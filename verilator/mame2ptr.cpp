// M3: MAME capture (.raw, CPU-cycle timestamps) -> lockstep trace (.ptr), and the
// oracle check against unmodified MAME (no rebuild): every value MAME returned for
// a POKEY read is compared with pokey_ref at the modelled POKEY position.
//
// Scheduler model (MAME 0.289 emu/schedule.cpp timeslice(), diexec.cpp; plan M-1/M-2):
//  * CPU access at cycle c (tap time = c*aspc): read() / write() call synchronize()
//    -> zero-delay timer at c, CPU stops after cycle c, every POKEY catches up to c+SR
//    (SR = 1: the CPU finished cycle c).  A write is applied there (k = c+SW, SW = SR).
//  * Periodic scheduler timer every TPER clocks (centiped.cpp:1794 32V timer:
//    25200 clocks/frame / 256 lines * 16 = 1575): POKEYs catch up to floor(c/TPER)*TPER.
//  * POKEY-internal sync (--internal-sync): if a POKEY step j <= c queues a zero-delay
//    timer (sync_pot / sync_set_irqst, pokey.cpp:613, pokey.h:228) during that catch-up,
//    MAME aborts the POKEY slice; that chip and every chip after it in device order end
//    at c, not c+1 (timer at j-1 < c lowers the slice target; next slice runs to the
//    access timer at c only).  Chips before it keep c+1.
// usage: mame2ptr <in.raw> [--out f.ptr] [--sw N] [--sr N] [--tper N] [--internal-sync]
//                 [--maxgap N] [-v]
#include "pokey_ref.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct Ev { char t; int64_t c; int chip; int a; int d; };

int main(int argc, char **argv)
{
	const char *in = nullptr, *outfn = nullptr;
	int sw = 1, sr = 1;
	int64_t tper = 0, maxgap = INT64_MAX;
	bool isync = false, verbose = false;
	for (int i = 1; i < argc; i++)
	{
		std::string a = argv[i];
		if (a == "--out") outfn = argv[++i];
		else if (a == "--sw") sw = atoi(argv[++i]);
		else if (a == "--sr") sr = atoi(argv[++i]);
		else if (a == "--tper") tper = atoll(argv[++i]);
		else if (a == "--maxgap") maxgap = atoll(argv[++i]);
		else if (a == "--internal-sync") isync = true;
		else if (a == "-v") verbose = true;
		else in = argv[i];
	}
	if (!in) { fprintf(stderr, "usage: mame2ptr in.raw [--out f.ptr] [--sw N] [--sr N] [--tper N] [--internal-sync] [--maxgap N] [-v]\n"); return 2; }
	FILE *f = fopen(in, "r");
	if (!f) { perror(in); return 2; }
	std::map<std::string, int> chipidx;
	std::vector<std::string> chipname, chipline;
	std::vector<std::unique_ptr<PokeyRef>> ref;
	uint32_t clk = 0;
	std::string set;
	std::vector<Ev> ev;
	char line[512];
	int64_t endc = -1;
	while (fgets(line, sizeof line, f))
	{
		char name[64]; long long c; int a, d; unsigned base, potm; int acb;
		if (!strncmp(line, "# raw", 5))
		{
			const char *p = strstr(line, "clk="); clk = p ? atoi(p + 4) : 0;
			p = strstr(line, "set="); if (p) { char b[64]; sscanf(p + 4, "%63s", b); set = b; }
		}
		else if (sscanf(line, "C %63s %x %x %d", name, &base, &potm, &acb) == 4)
		{
			chipidx[name] = int(ref.size());
			chipname.push_back(name);
			char b[128]; snprintf(b, sizeof b, "C %d %s %02x %d", int(ref.size()), name, potm, acb);
			chipline.push_back(b);
			ref.emplace_back(new PokeyRef(clk, uint8_t(potm), acb != 0));
		}
		else if ((line[0] == 'W' || line[0] == 'R' || line[0] == 'P') && sscanf(line + 2, "%lld %63s %d %d", &c, name, &a, &d) == 4)
			ev.push_back({ line[0], c, chipidx.at(name), a, d });
		else if (line[0] == 'E') endc = atoll(line + 2);
	}
	fclose(f);
	// pot values logged with a POTGO write go before it (MAME reads pot_r inside the write)
	for (size_t i = 1; i < ev.size(); i++)
		if (ev[i].t == 'P' && ev[i - 1].t == 'W' && ev[i - 1].a == 0x0b && ev[i].c == ev[i - 1].c)
		{
			size_t j = i;
			while (j > 0 && ev[j - 1].t == 'W' && ev[j - 1].c == ev[i].c && ev[j - 1].a == 0x0b) { std::swap(ev[j - 1], ev[j]); j--; }
		}
	for (auto &e : ev) if (e.t == 'P' && e.c == 0) ref[e.chip]->set_pot(e.a, e.d);
	for (auto &r : ref) r->power_on();

	FILE *out = nullptr;
	if (outfn)
	{
		out = fopen(outfn, "w");
		if (!out) { perror(outfn); return 2; }
		fprintf(out, "# ptr v2 set=%s clk=%u src=%s sw=%d sr=%d tper=%lld internal_sync=%d\n", set.c_str(), clk, in, sw, sr,
			(long long)tper, isync ? 1 : 0);
		for (auto &l : chipline) fprintf(out, "%s\n", l.c_str());
		for (auto &e : ev) if (e.t == 'P' && e.c == 0) fprintf(out, "P 0 %d %d %d\n", e.chip, e.a, e.d);
	}

	const size_t N = ref.size();
	std::vector<int64_t> pos(N, 0);
	auto step_chip = [&](size_t i) { ref[i]->step(); pos[i]++; return ref[i]->last_step_queued; };
	// timer sync: all chips to t (internal syncs there do not change the end point)
	auto run_to = [&](int64_t t) { for (size_t i = 0; i < N; i++) while (pos[i] < t) step_chip(i); };
	// CPU access at cycle c: every chip to c+SR; internal sync at step <= c ends this chip and all later chips at c
	auto access_sync = [&](int64_t c) {
		int64_t target = c + sr;
		bool cut = false;
		for (size_t i = 0; i < N; i++)
		{
			int64_t t = cut ? c : target;
			while (pos[i] < t)
			{
				bool q = step_chip(i);
				if (isync && q && pos[i] <= c && !cut) { cut = true; t = c; }
			}
		}
	};

	int64_t prev_c = -1;
	char prev_t = 0;
	long nr[2] = {0, 0}, nex[2] = {0, 0}, nlong = 0;
	long no[2] = {0, 0}, noex[2] = {0, 0};
	for (const Ev &e : ev)
	{
		if (e.t == 'P')
		{
			if (e.c == 0) continue;
			ref[e.chip]->set_pot(e.a, e.d);
			if (out) fprintf(out, "P %lld %d %d %d\n", (long long)pos[e.chip], e.chip, e.a, e.d);
			continue;
		}
		if (tper > 0) run_to((e.c / tper) * tper);
		if (e.t == 'W')
		{
			// SW != SR only for the fit control: apply the write at c+SW instead
			if (sw != sr) { run_to(std::max<int64_t>(e.c + sw, 0)); }
			else access_sync(e.c);
			if (out) fprintf(out, "W %lld %d %d %d\n", (long long)pos[e.chip], e.chip, e.a, e.d);
			ref[e.chip]->write(e.a, uint8_t(e.d));
			if (sw != sr) access_sync(e.c);
			prev_c = e.c; prev_t = 'W';
			continue;
		}
		// read: value is the POKEY state at its current position (before this access' own catch-up)
		int cls = prev_t == 'W' ? 0 : 1;
		bool scored = prev_c >= 0 && e.c - prev_c <= maxgap;
		if (!scored) nlong++;
		bool allpot_cb = e.a == 0x08 && ref[e.chip]->dev.m_allpot_r_cb.fn && (ref[e.chip]->dev.m_SKCTL & 3);
		uint8_t v = ref[e.chip]->read_peek(e.a);
		if (out) fprintf(out, "r %lld %d %d %d\n", (long long)pos[e.chip], e.chip, e.a, e.d);
		if (allpot_cb)
			ref[e.chip]->read(e.a, uint8_t(e.d));   // pokey.cpp:944 store; value is the callback's
		else if (scored)
		{
			bool rnd = e.a == 0x0a;
			if (rnd) { nr[cls]++; if (v == e.d) nex[cls]++; } else { no[cls]++; if (v == e.d) noex[cls]++; }
			if (v != e.d && verbose)
				printf("MISS c=%lld chip=%d reg=%X mame=%02X ref=%02X pos=%lld prev=%c@%lld\n", (long long)e.c, e.chip, e.a, e.d, v,
					(long long)pos[e.chip], prev_t, (long long)prev_c);
		}
		access_sync(e.c);
		prev_c = e.c; prev_t = 'R';
	}
	if (endc < 0) endc = prev_c + 2;
	if (out) { fprintf(out, "E %lld\n", (long long)endc); fclose(out); }
	printf("%s sw=%d sr=%d tper=%lld isync=%d maxgap=%lld: RANDOM after write %ld/%ld, after read %ld/%ld; other regs after write %ld/%ld, after read %ld/%ld (exact/scored; %ld reads unscored)\n",
		in, sw, sr, (long long)tper, isync ? 1 : 0, (long long)(maxgap == INT64_MAX ? -1 : maxgap), nex[0], nr[0], nex[1], nr[1], noex[0], no[0], noex[1], no[1], nlong);
	return 0;
}
