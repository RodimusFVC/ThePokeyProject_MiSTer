// pokey_ref: rig-side wrapper around the PRISTINE MAME 0.289 pokey_device
// (ref/mame_0289/pokey.{cpp,h}, compiled unmodified against ref/shim/emu.h).
// The only MAME-semantics decisions live here and in the shim; each is tagged SHIM.
#pragma once
#include "emu.h"
#include "pokey.h"
#include "pokey_state.h"

class PokeyRef
{
public:
	// pot_mask: pots with a MAME pot_r callback (warlords 0x0F)
	// allpot_cb: chip has an allpot_r callback (milliped, ccastles pokey2)
	PokeyRef(uint32_t clock, uint8_t pot_mask, bool allpot_cb);

	void power_on();                    // device_start + device_reset (+ drain)
	void step();                        // one execute_run() iteration + end-of-step drain
	void write(unsigned reg, uint8_t data);   // write_internal + drain (SHIM for write()->sync_write)
	uint8_t read(unsigned reg, uint8_t allpot_cb_value);
	void set_pot(unsigned idx, uint8_t val) { m_pot_val[idx & 7] = val; }
	void get_state(pokey_state &s);
	uint8_t random() { return read_peek(0x0a); }
	uint8_t read_peek(unsigned reg);    // read without the ALLPOT-callback store side effect

	pokey_device dev;
	uint8_t m_pot_val[8] = {};
	uint8_t m_allpot_val = 0;
	uint64_t steps = 0;
	bool last_step_queued = false;   // a zero-delay timer was queued by the last step (MAME: POKEY slice abort)

private:
	void drain();
	static machine_config s_cfg;
};
