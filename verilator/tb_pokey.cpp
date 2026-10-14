// POKEY lockstep rig: pokey_cx (Verilator) vs pokey_ref (pristine MAME 0.289 code),
// full state compared after every event and every POKEY clock (plan 4.2).
//
// usage: tb_pokey --trace f.ptr | --fuzz SEED --clocks N [--fuzz-chips 1|2] [--fuzz-mask HEX]
//        [--merge] [--readall] [--groups g1,g2] [--plant field@clk[@chip]] [--to K] [-q]
//        [--watch f1,f2 --from K] (print ref/dut fields from clock K)
//        [--outonly] (compare out_raw only, no read checks: old-RTL control)
//        [--glue]  (GLUE build: old port protocol, one write per chip per clock on the step edge;
//                   ALLPOT callbacks off on both sides, POTx fields of comparator pots not compared)
// exit 0 = no divergence, 1 = divergence, 2 = usage/config error.
#include "Vtb_top.h"
#include "verilated.h"
#include "pokey_ref.h"
#include "pokey_state.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <memory>
#include <random>
#include <string>
#include <vector>

struct Ev { char t; int64_t k; int chip; int a; int d; };

static Vtb_top *top;
static uint64_t evals = 0;

// ---------------------------------------------------------------- DUT bus helpers
static void set_slot(int s, unsigned addr, unsigned din)
{
	if (s == 0) { top->addr0 = addr; top->din0 = din; } else { top->addr1 = addr; top->din1 = din; }
}
static void tick()
{
	top->clk = 0; top->eval();
	top->clk = 1; top->eval();
	evals += 2;
	top->ce = 0; top->wr = 0; top->rd = 0;
}
static uint8_t dut_dout(int s) { top->eval(); return s == 0 ? top->dout0 : top->dout1; }
static const uint32_t *dut_dbg(int s) { return s == 0 ? top->dbg0 : top->dbg1; }
static void set_pots(int s, const uint8_t *v)
{
	uint64_t q = 0;
	for (int i = 0; i < 8; i++) q |= uint64_t(v[i]) << (8 * i);
	if (s == 0) top->pot_val0 = q; else top->pot_val1 = q;
}
static void set_allpot(int s, uint8_t v) { if (s == 0) top->allpot_ext0 = v; else top->allpot_ext1 = v; }

// ---------------------------------------------------------------- state packing / compare
struct FieldPos { unsigned w, sh, width; uint32_t mask; };
static FieldPos FP[POKEY_NFIELDS];
static uint32_t cmp_mask[POKEY_STATE_WORDS];
static uint32_t cmp_mask_chip[2][POKEY_STATE_WORDS];
static unsigned group_mask = ~0u & ~unsigned(G_serial);

static void init_fields()
{
	memset(cmp_mask, 0, sizeof cmp_mask);
	for (unsigned i = 0; i < POKEY_NFIELDS; i++)
	{
		const auto &f = POKEY_FIELD_INFO[i];
		FP[i] = { f.lsb >> 5, f.lsb & 31, f.width, f.width >= 32 ? ~0u : ((1u << f.width) - 1) };
		if (f.group & group_mask)
			for (unsigned b = 0; b < f.width; b++) cmp_mask[(f.lsb + b) >> 5] |= 1u << ((f.lsb + b) & 31);
	}
}
static void pack(const pokey_state &s, uint32_t *w)
{
	memset(w, 0, 4 * POKEY_STATE_WORDS);
	for (unsigned i = 0; i < POKEY_NFIELDS; i++)
	{
		uint64_t v = uint64_t(s.v[i] & FP[i].mask) << FP[i].sh;
		w[FP[i].w] |= uint32_t(v);
		if (FP[i].sh + FP[i].width > 32) w[FP[i].w + 1] |= uint32_t(v >> 32);
	}
}
static uint32_t field_of(const uint32_t *w, unsigned i)
{
	uint64_t v = w[FP[i].w];
	if (FP[i].w + 1 < POKEY_STATE_WORDS) v |= uint64_t(w[FP[i].w + 1]) << 32;
	return uint32_t(v >> FP[i].sh) & FP[i].mask;
}

// ---------------------------------------------------------------- rig
struct Chip
{
	std::unique_ptr<PokeyRef> ref;
	uint8_t pot_mask = 0;
	bool allpot_cb = false;
	uint8_t pots[8] = {};
	std::deque<std::vector<uint32_t>> hist_ref, hist_dut; // last steps
	std::deque<int64_t> hist_k;
};
static std::vector<Chip> chips;
static std::deque<std::string> last_events;
static int64_t plant_k = -1; static int plant_field = -1; static int plant_chip = 0;
static bool quiet = false;
static bool no_readcheck = false;
static std::vector<unsigned> watch;   // --watch f1,f2 --from K: print fields every step from K
static int64_t watch_from = INT64_MAX;   // --outonly: old-RTL control compares out_raw only
static uint64_t n_outraw_changes = 0, n_irq_changes = 0, n_potcnt_changes = 0, n_borrow_steps = 0;
static uint64_t n_compares = 0, n_read_checks = 0, n_read_vs_mame_diff = 0, n_read_vs_mame = 0;

static void log_event(const char *s)
{
	last_events.push_back(s);
	if (last_events.size() > 16) last_events.pop_front();
}

static int compare(int c, int64_t k, const char *phase)
{
	pokey_state rs;
	chips[c].ref->get_state(rs);
	uint32_t rw[POKEY_STATE_WORDS], dw[POKEY_STATE_WORDS];
	pack(rs, rw);
	memcpy(dw, dut_dbg(c), sizeof dw);
	if (plant_field >= 0 && k == plant_k && c == plant_chip && !strcmp(phase, "after-step"))
	{
		const auto &f = FP[plant_field];
		dw[f.w] ^= 1u << f.sh;   // flip bit 0 of the field as read back from the DUT
	}
	n_compares++;
	if (!watch.empty() && k >= watch_from)
	{
		printf("watch k=%lld %s c%d:", (long long)k, phase, c);
		for (unsigned i : watch) printf(" %s=%X/%X", POKEY_FIELD_INFO[i].name, field_of(rw, i), field_of(dw, i));
		printf("\n");
	}
	bool bad = false;
	for (unsigned i = 0; i < POKEY_STATE_WORDS; i++)
		if ((rw[i] ^ dw[i]) & cmp_mask_chip[c][i]) { bad = true; break; }
	if (!strcmp(phase, "after-step"))
	{
		auto &ch = chips[c];
		ch.hist_ref.emplace_back(rw, rw + POKEY_STATE_WORDS);
		ch.hist_dut.emplace_back(dw, dw + POKEY_STATE_WORDS);
		ch.hist_k.push_back(k);
		if (ch.hist_k.size() > 9) { ch.hist_ref.pop_front(); ch.hist_dut.pop_front(); ch.hist_k.pop_front(); }
	}
	if (!bad) return 0;
	double ms = chips[c].ref->dev.clock() ? 1000.0 * double(k) / chips[c].ref->dev.clock() : 0;
	printf("DIVERGE clk %lld (%.3f ms) %s chip %d\n", (long long)k, ms, phase, c);
	std::vector<unsigned> diff;
	for (unsigned i = 0; i < POKEY_NFIELDS; i++)
		if ((POKEY_FIELD_INFO[i].group & group_mask) && field_of(rw, i) != field_of(dw, i) && (field_of(cmp_mask_chip[c], i) != 0))
		{
			diff.push_back(i);
			printf("  field %-16s ref=%X dut=%X\n", POKEY_FIELD_INFO[i].name, field_of(rw, i), field_of(dw, i));
		}
	printf("  last %zu events:", last_events.size());
	for (auto &e : last_events) printf(" %s", e.c_str());
	printf("\n  window (after-step rows; * = differs):\n");
	auto &ch = chips[c];
	for (size_t r = 0; r < ch.hist_k.size(); r++)
	{
		printf("   k=%-10lld", (long long)ch.hist_k[r]);
		for (unsigned i : diff)
		{
			uint32_t a = field_of(ch.hist_ref[r].data(), i), b = field_of(ch.hist_dut[r].data(), i);
			printf(" %s ref=%X dut=%X%s", POKEY_FIELD_INFO[i].name, a, b, a != b ? "*" : "");
		}
		printf("\n");
	}
	return 1;
}

static void dut_reset()
{
	top->reset_n = 0;
	for (size_t c = 0; c < chips.size(); c++) set_pots(int(c), chips[c].pots);
	tick();
	top->reset_n = 3;
}

// write; with step=true the write is presented on the step edge (merge mode)
static void dut_write(int c, unsigned a, unsigned d, bool step)
{
	set_slot(c, a, d);
	top->wr = 1u << c;
	if (step) top->ce = 3;
	tick();
}
static void dut_step() { top->ce = 3; tick(); }

static int do_read(int c, int64_t k, unsigned a, int data, bool has_mame)
{
	Chip &ch = chips[c];
	bool cbstore = a == 8 && ch.allpot_cb && (ch.ref->dev.m_SKCTL & 3);
	uint8_t cbval = uint8_t(data);   // allpot_r callback value (MAME's returned value)
	set_allpot(c, cbval);
	set_slot(c, a, 0);
	uint8_t d = dut_dout(c);
	uint8_t e;
	if (cbstore) e = ch.ref->read(a, cbval); else { ch.ref->m_allpot_val = cbval; e = ch.ref->read_peek(a); }
	n_read_checks++;
	if (has_mame) { n_read_vs_mame++; if (e != data) n_read_vs_mame_diff++; }
	if (d != e && !no_readcheck)
	{
		printf("DIVERGE clk %lld read chip %d reg %X ref=%02X dut=%02X\n", (long long)k, c, a, e, d);
		return 1;
	}
	if (cbstore) { top->rd = 1u << c; tick(); }   // ALLPOT store side effect in the DUT
	return 0;
}

static int read_all(int c, int64_t k)
{
	for (unsigned a = 0; a < 16; a++)
	{
		if (a == 8 && chips[c].allpot_cb) continue;   // has a side effect; checked via r events
		set_slot(c, a, 0);
		uint8_t d = dut_dout(c), e = chips[c].ref->read_peek(a);
		n_read_checks++;
		if (d != e) { printf("DIVERGE clk %lld readall chip %d reg %X ref=%02X dut=%02X\n", (long long)k, c, a, e, d); return 1; }
	}
	return 0;
}

// ---------------------------------------------------------------- fuzz stimulus
struct Fuzz
{
	std::mt19937_64 rng;
	int nchips;
	bool single = false;          // glue: at most one event per clock
	uint32_t regmask = 0xffff;   // allowed write registers (bit n = reg n); P/r events only if all allowed
	explicit Fuzz(uint64_t seed, int n) : rng(seed), nchips(n) {}
	uint32_t r(uint32_t n) { return uint32_t(rng() % n); }
	// generate events for clock k (may be none); returns events in file order
	int64_t next_k = 0;
	void gen(int64_t k, std::vector<Ev> &out)
	{
		out.clear();
		if (k < next_k) return;
		int nev = single ? 1 : 1 + (r(4) == 0 ? r(4) : 0);
		for (int i = 0; i < nev; i++)
		{
			int c = r(nchips);
			uint32_t x = r(100);
			Ev e{ 'W', k, c, 0, 0 };
			if (x < 30) { e.a = 2 * r(4); e.d = r(3) ? r(8) : r(256); }               // AUDF, mostly small
			else if (x < 50) { e.a = 2 * r(4) + 1; e.d = r(256); }                    // AUDC
			else if (x < 60) { e.a = 8; e.d = r(256); }                               // AUDCTL
			else if (x < 64) { e.a = 9; e.d = r(256); }                               // STIMER
			else if (x < 70) { e.a = 15; e.d = (r(256) & 0x97); }                     // SKCTL, bits 3/5/6 = 0
			else if (x < 73)                                                          // POTGO
			{
				e.a = 11; e.d = r(256);
				if (single)   // glue: board paddles change only together with POTGO, never 0
					for (int pt = 0; pt < 8; pt++) out.push_back({ 'P', k, c, pt, int(1 + r(255)) });
			}
			else if (x < 78) { e.a = 14; e.d = r(256); }                              // IRQEN
			else if (x < 80) { e.a = 10 + 2 * r(2) + (r(2) ? 1 : 0); e.d = r(256); } // SKREST, 0C, SEROUT
			else if (x < 85 && !single) { e.t = 'P'; e.a = r(8); e.d = r(4) ? r(256) : (r(2) ? 0 : 228 + r(28)); }
			else if (x < 85) { i--; continue; }
			else { e.t = 'r'; e.a = r(16); e.d = r(256); }
			if (e.t == 'W' && !((regmask >> e.a) & 1)) { i--; continue; }
			if (e.t != 'W' && regmask != 0xffff) { i--; continue; }
			out.push_back(e);
		}
		uint32_t g = r(10);
		next_k = k + (g < 3 ? r(4) : g < 7 ? r(200) : r(2001));
		if (single && next_k == k) next_k = k + 1;
	}
};

// ---------------------------------------------------------------- main
int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);
	const char *trace = nullptr;
	int64_t fuzz_seed = -1, fuzz_clocks = 0, to_k = -1;
	int fuzz_chips = 1;
	uint32_t fuzz_mask = 0xffff;
	bool merge = false, readall = false, glue = false;
	for (int i = 1; i < argc; i++)
	{
		std::string a = argv[i];
		if (a == "--trace") trace = argv[++i];
		else if (a == "--fuzz") fuzz_seed = atoll(argv[++i]);
		else if (a == "--clocks") fuzz_clocks = atoll(argv[++i]);
		else if (a == "--fuzz-chips") fuzz_chips = atoi(argv[++i]);
		else if (a == "--fuzz-mask") fuzz_mask = uint32_t(strtoul(argv[++i], nullptr, 16));
		else if (a == "--merge") merge = true;
		else if (a == "--readall") readall = true;
		else if (a == "--glue") glue = true;
		else if (a == "--from") watch_from = atoll(argv[++i]);
		else if (a == "--watch")
		{
			std::string w = std::string(argv[++i]) + ",";
			for (size_t p0 = 0, p1; (p1 = w.find(',', p0)) != std::string::npos; p0 = p1 + 1)
				for (unsigned f = 0; f < POKEY_NFIELDS; f++)
					if (w.substr(p0, p1 - p0) == POKEY_FIELD_INFO[f].name) watch.push_back(f);
		}
		else if (a == "--outonly") { no_readcheck = true; group_mask = G_out; }
		else if (a == "--to") to_k = atoll(argv[++i]);
		else if (a == "-q") quiet = true;
		else if (a == "--groups")
		{
			group_mask = 0;
			std::string g = argv[++i];
			const char *names[] = { "reg", "chan", "irq", "serial", "pot", "prescale", "poly", "out" };
			for (int b = 0; b < 8; b++) if (g.find(names[b]) != std::string::npos) group_mask |= 1u << b;
		}
		else if (a == "--plant")
		{
			char fn[64]; long long k; int c = 0;
			if (sscanf(argv[++i], "%63[^@]@%lld@%d", fn, &k, &c) < 2) { fprintf(stderr, "bad --plant\n"); return 2; }
			for (unsigned f = 0; f < POKEY_NFIELDS; f++) if (!strcmp(POKEY_FIELD_INFO[f].name, fn)) plant_field = int(f);
			if (plant_field < 0) { fprintf(stderr, "no field %s\n", fn); return 2; }
			plant_k = k; plant_chip = c;
		}
		else if (a[0] != '+') { fprintf(stderr, "unknown arg %s\n", a.c_str()); return 2; }
	}
	init_fields();
	top = new Vtb_top;
	top->clk = 0; top->ce = 0; top->wr = 0; top->rd = 0; top->reset_n = 0;
	top->eval();
	unsigned cfg = top->cfg;
	uint8_t slot_pot[2] = { uint8_t(cfg & 0xff), uint8_t((cfg >> 9) & 0xff) };
	bool slot_acb[2] = { bool((cfg >> 8) & 1), bool((cfg >> 17) & 1) };

	std::vector<Ev> ev;
	uint32_t clk = 1512000;
	bool from_mame = false;   // trace generated from a MAME capture: r data = MAME's value
	int64_t endk = 0;
	if (trace)
	{
		FILE *f = fopen(trace, "r");
		if (!f) { perror(trace); return 2; }
		char line[512];
		while (fgets(line, sizeof line, f))
		{
			int idx; char name[64]; unsigned pm; int acb; long long k; int c, a, d;
			const char *p = strstr(line, "clk=");
			if (line[0] == '#') { if (p) clk = atoi(p + 4); if (strstr(line, "src=")) from_mame = true; continue; }
			if (sscanf(line, "C %d %63s %x %d", &idx, name, &pm, &acb) == 4)
			{
				if (idx != int(chips.size()) || idx > 1) { fprintf(stderr, "bad chip line\n"); return 2; }
				if (glue) acb = 0;   // board muxes DIP switches over ALLPOT reads
				if (pm != slot_pot[idx] || bool(acb) != slot_acb[idx])
				{
					fprintf(stderr, "config mismatch: trace chip %d pot_cb=%02x allpot_cb=%d, build slot pot_cb=%02x allpot_cb=%d\n",
						idx, pm, acb, slot_pot[idx], slot_acb[idx]);
					return 2;
				}
				chips.emplace_back();
				chips.back().pot_mask = uint8_t(pm); chips.back().allpot_cb = acb != 0;
			}
			else if ((line[0] == 'W' || line[0] == 'r' || line[0] == 'P') && sscanf(line + 2, "%lld %d %d %d", &k, &c, &a, &d) == 4)
				ev.push_back({ line[0], k, c, a, d });
			else if (line[0] == 'E') endk = atoll(line + 2);
		}
		fclose(f);
	}
	else if (fuzz_seed >= 0)
	{
		for (int c = 0; c < fuzz_chips; c++)
		{
			chips.emplace_back();
			chips.back().pot_mask = slot_pot[c]; chips.back().allpot_cb = slot_acb[c];
		}
		endk = fuzz_clocks;
		if (glue) for (auto &ch : chips) for (auto &pv : ch.pots) pv = 0x80;   // paddle mid position, not 0
	}
	else { fprintf(stderr, "need --trace or --fuzz\n"); return 2; }
	if (to_k >= 0 && to_k < endk) endk = to_k;

	for (int c = 0; c < 2; c++)
	{
		memcpy(cmp_mask_chip[c], cmp_mask, sizeof cmp_mask);
		if (glue)
			for (int pt = 0; pt < 8; pt++)
				if ((slot_pot[c] >> pt) & 1)
				{
					unsigned f = F_pot0 + pt;
					for (unsigned b = 0; b < FP[f].width; b++)
					{
						unsigned l = POKEY_FIELD_INFO[f].lsb + b;
						cmp_mask_chip[c][l >> 5] &= ~(1u << (l & 31));
					}
				}
	}
	if (glue && (slot_acb[0] || slot_acb[1])) { fprintf(stderr, "glue build must have ALLPOT_CB=0\n"); return 2; }
	// power on: pot values for device_reset's POTGO come from P events at k=0
	size_t ei = 0;
	while (ei < ev.size() && ev[ei].t == 'P' && ev[ei].k == 0) { chips[ev[ei].chip].pots[ev[ei].a & 7] = ev[ei].d; ei++; }
	for (auto &ch : chips)
	{
		ch.ref.reset(new PokeyRef(clk, ch.pot_mask, ch.allpot_cb));
		for (int i = 0; i < 8; i++) ch.ref->set_pot(i, ch.pots[i]);
		ch.ref->power_on();
	}
	dut_reset();
	for (size_t c = 0; c < chips.size(); c++) if (compare(int(c), 0, "after-reset")) return 1;

	Fuzz fz(uint64_t(fuzz_seed < 0 ? 0 : fuzz_seed), fuzz_chips);
	fz.regmask = fuzz_mask;
	fz.single = glue;
	std::vector<Ev> fev;
	char buf[96];
	for (int64_t k = 0; k < endk; k++)
	{
		const std::vector<Ev> *cur;
		std::vector<Ev> tev;
		if (trace)
		{
			tev.clear();
			while (ei < ev.size() && ev[ei].k == k) tev.push_back(ev[ei++]);
			if (ei < ev.size() && ev[ei].k < k) { fprintf(stderr, "trace not sorted at k=%lld\n", (long long)ev[ei].k); return 2; }
			cur = &tev;
		}
		else { fz.gen(k, fev); cur = &fev; }
		int merged = -1;   // index of the write presented on the step edge
		if (merge && !cur->empty() && cur->back().t == 'W') merged = int(cur->size()) - 1;
		int gw[2] = { -1, -1 };   // glue: write per chip presented on the step edge
		std::vector<Ev> glue_late_reads;   // reads after that write: checked after the step (no side effects)
		if (glue)
			for (size_t i = 0; i < cur->size(); i++)
			{
				const Ev &e = (*cur)[i];
				if (gw[e.chip] >= 0)
				{
					if (e.t != 'r') { fprintf(stderr, "glue: chip %d %c after its write at k=%lld (old protocol: one write per clock)\n", e.chip, e.t, (long long)k); return 2; }
					glue_late_reads.push_back(e);
					continue;
				}
				if (e.t == 'W') gw[e.chip] = int(i);
			}
		for (size_t i = 0; i < cur->size(); i++)
		{
			const Ev &e = (*cur)[i];
			Chip &ch = chips[e.chip];
			if (glue && gw[e.chip] >= 0 && int(i) > gw[e.chip]) continue;   // late read
			// glue fuzz: the board paddle changes only when the POTGO with it samples it (MAME M-11);
			// a POTGO in init mode is ignored, so its paddle change would be a mid-scan change
			if (glue && !trace && e.t == 'P' && !(ch.ref->dev.m_SKCTL & 3)) continue;
			snprintf(buf, sizeof buf, "%c@%lld:%d:%X=%02X", e.t, (long long)k, e.chip, e.a, e.d);
			log_event(buf);
			if (e.t == 'W')
			{
				if (glue) continue;            // applied with the step below
				if (int(i) == merged) break;   // applied with the step below
				dut_write(e.chip, e.a, e.d, false);
				ch.ref->write(e.a, uint8_t(e.d));
			}
			else if (e.t == 'P')
			{
				ch.pots[e.a & 7] = uint8_t(e.d);
				ch.ref->set_pot(e.a & 7, uint8_t(e.d));
				set_pots(e.chip, ch.pots);
			}
			else if (e.t == 'r')
			{
				if (do_read(e.chip, k, e.a & 15, e.d, from_mame)) return 1;
			}
			if (compare(e.chip, k, "after-event")) return 1;
		}
		if (glue)
		{
			top->wr = 0;
			for (int c = 0; c < 2; c++)
				if (gw[c] >= 0)
				{
					const Ev &e = (*cur)[gw[c]];
					chips[c].ref->write(e.a, uint8_t(e.d));
					set_slot(c, e.a, e.d);
					top->wr |= 1u << c;
				}
			top->ce = 3;
			tick();
		}
		else if (merged >= 0)
		{
			const Ev &e = (*cur)[merged];
			chips[e.chip].ref->write(e.a, uint8_t(e.d));
			dut_write(e.chip, e.a, e.d, true);
		}
		else dut_step();
		for (auto &ch : chips) ch.ref->step();
		for (size_t c = 0; c < chips.size(); c++)
		{
			// coverage (from the reference side)
			auto &d = chips[c].ref->dev;
			static uint32_t last_or[2], last_irq[2], last_pc[2];
			if (d.m_out_raw != last_or[c]) { n_outraw_changes++; last_or[c] = d.m_out_raw; }
			if (uint32_t(d.m_irq_w_cb.level) != last_irq[c]) { n_irq_changes++; last_irq[c] = d.m_irq_w_cb.level; }
			if (d.m_pot_counter != last_pc[c]) { n_potcnt_changes++; last_pc[c] = d.m_pot_counter; }
			for (auto &chn : d.m_channel) if (chn.m_borrow_cnt) { n_borrow_steps++; break; }
			if (compare(int(c), k + 1, "after-step")) return 1;
			if (readall && read_all(int(c), k + 1)) return 1;
		}
		for (const Ev &e : glue_late_reads)
			if (do_read(e.chip, k + 1, e.a & 15, e.d, false)) return 1;
	}
	printf("PASS %s: %lld clocks, %zu chip(s), %llu state compares, %llu read checks%s, 0 divergences",
		trace ? trace : "fuzz", (long long)endk, chips.size(), (unsigned long long)n_compares, (unsigned long long)n_read_checks,
		merge ? " (merge)" : glue ? " (glue, old port protocol)" : "");
	if (fuzz_seed >= 0) printf(", seed %lld", (long long)fuzz_seed);
	printf("; coverage: out_raw changes %llu, irq pin changes %llu, pot counter changes %llu, steps with a borrow pending %llu",
		(unsigned long long)n_outraw_changes, (unsigned long long)n_irq_changes, (unsigned long long)n_potcnt_changes, (unsigned long long)n_borrow_steps);
	if (n_read_vs_mame) printf("; ref vs MAME read values: %llu/%llu differ (info, plan M-1)",
		(unsigned long long)n_read_vs_mame_diff, (unsigned long long)n_read_vs_mame);
	printf("\n");
	delete top;
	return 0;
}
