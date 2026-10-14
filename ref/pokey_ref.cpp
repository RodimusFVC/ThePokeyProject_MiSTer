// pokey_ref: see pokey_ref.h.  Every MAME-semantics choice is tagged SHIM.
#include "pokey_ref.h"

machine_config PokeyRef::s_cfg;
const attotime attotime::zero{};

PokeyRef::PokeyRef(uint32_t clock, uint8_t pot_mask, bool allpot_cb)
	: dev(s_cfg, "pokey", nullptr, clock)
{
	// SHIM: pot_r<n>() / allpot_r() bindings (centiped.cpp:1907,1911,1953-1956; ccastles.cpp:888).
	// Values come from the trace (P events / r events).
	for (int i = 0; i < 8; i++)
		if (pot_mask & (1 << i))
			dev.m_pot_r_cb[i].fn = [this, i](offs_t) { return m_pot_val[i]; };
	if (allpot_cb)
		dev.m_allpot_r_cb.fn = [this](offs_t) { return m_allpot_val; };
	// SHIM: m_SERIN, m_SEROUT, m_kbd_latch are never initialised by MAME
	// (device_start 228-368); use 0 (plan 2.3).
	dev.m_SERIN = 0;
	dev.m_SEROUT = 0;
	dev.m_kbd_latch = 0;
	// SHIM: pin levels before MAME's first callback: irq=0 (clear), sod=1 (mark), oclk=0.
	dev.m_sod_w_cb.level = 1;
}

void PokeyRef::power_on()
{
	dev.device_start();
	dev.device_reset();
	drain();
}

// SHIM: zero-delay timers / synchronize() callbacks queued during a step or a
// write apply right after it (plan M-3), in FIFO order (schedule.cpp:847).
void PokeyRef::drain()
{
	auto &q = dev.machine().scheduler().queue;
	while (!q.empty())
	{
		shim_deferred e = q.front();
		q.pop_front();
		e.fn(e.param);
	}
}

// SHIM: execute_run() (pokey.cpp:495-503) = one step_one_clock() per POKEY clock.
void PokeyRef::step()
{
	dev.step_one_clock();
	steps++;
	last_step_queued = !dev.machine().scheduler().queue.empty();
	drain();
}

// SHIM: write() -> synchronize(sync_write) (pokey.cpp:1004): the rig applies
// write_internal() at the event clock.
void PokeyRef::write(unsigned reg, uint8_t data)
{
	dev.write_internal(reg & 0x0f, data);
	drain();
}

uint8_t PokeyRef::read(unsigned reg, uint8_t allpot_cb_value)
{
	m_allpot_val = allpot_cb_value;
	return dev.read(reg & 0x0f);
}

uint8_t PokeyRef::read_peek(unsigned reg)
{
	uint8_t save = dev.m_ALLPOT;
	uint8_t d = dev.read(reg & 0x0f);
	dev.m_ALLPOT = save;
	return d;
}

void PokeyRef::get_state(pokey_state &s)
{
	for (auto &v : s.v)
		v = 0xdeadbeef;
	const auto &c = dev.m_channel;
#define CH(n)                                                       \
	s.v[F_ch##n##_audf] = c[n - 1].m_AUDF;                          \
	s.v[F_ch##n##_audc] = c[n - 1].m_AUDC;                          \
	s.v[F_ch##n##_counter] = uint32_t(c[n - 1].m_counter);          \
	s.v[F_ch##n##_borrow_cnt] = uint32_t(c[n - 1].m_borrow_cnt);    \
	s.v[F_ch##n##_output] = c[n - 1].m_output;                      \
	s.v[F_ch##n##_filter_sample] = c[n - 1].m_filter_sample;
	CH(1) CH(2) CH(3) CH(4)
#undef CH
	s.v[F_audctl] = dev.m_AUDCTL;
	s.v[F_skctl] = dev.m_SKCTL;
	s.v[F_irqen] = dev.m_IRQEN;
	s.v[F_irqst] = dev.m_IRQST;
	s.v[F_skstat] = dev.m_SKSTAT;
	s.v[F_allpot] = dev.m_ALLPOT;
	s.v[F_clk28] = uint32_t(dev.m_clock_cnt[1]);
	s.v[F_clk114] = uint32_t(dev.m_clock_cnt[2]);
	// polys compared as LFSR state = table[index] (plan section 1)
	s.v[F_p4] = dev.m_poly4[dev.m_p4];
	s.v[F_p5] = dev.m_poly5[dev.m_p5];
	s.v[F_p9] = dev.m_poly9[dev.m_p9];
	s.v[F_p17] = dev.m_poly17[dev.m_p17];
	s.v[F_pot_counter] = dev.m_pot_counter;
	s.v[F_pot0] = dev.m_POTx[0];
	s.v[F_pot1] = dev.m_POTx[1];
	s.v[F_pot2] = dev.m_POTx[2];
	s.v[F_pot3] = dev.m_POTx[3];
	s.v[F_pot4] = dev.m_POTx[4];
	s.v[F_pot5] = dev.m_POTx[5];
	s.v[F_pot6] = dev.m_POTx[6];
	s.v[F_pot7] = dev.m_POTx[7];
	s.v[F_serin] = dev.m_SERIN;
	s.v[F_serout] = dev.m_SEROUT;
	s.v[F_serin_shift] = dev.m_serin_shift;
	s.v[F_serout_shift] = dev.m_serout_shift;
	s.v[F_serout_full] = dev.m_serout_full;
	s.v[F_ser_iclk] = dev.m_ser_iclk;
	s.v[F_ser_oclk] = dev.m_ser_oclk;
	s.v[F_sod_twotone] = dev.m_sod_twotone;
	s.v[F_out_raw] = dev.m_out_raw;
	s.v[F_irq] = uint32_t(dev.m_irq_w_cb.level);
	s.v[F_sod] = uint32_t(dev.m_sod_w_cb.level);
	s.v[F_oclk] = uint32_t(dev.m_oclk_w_cb.level);
	for (unsigned i = 0; i < POKEY_NFIELDS; i++)
		if (s.v[i] == 0xdeadbeef || (POKEY_FIELD_INFO[i].width < 32 && (s.v[i] >> POKEY_FIELD_INFO[i].width)))
		{
			fprintf(stderr, "pokey_ref: field %s unmapped or out of range (%x)\n", POKEY_FIELD_INFO[i].name, s.v[i]);
			abort();
		}
}
