// M1: LFSR equivalence. The RTL keeps poly STATE (table value), not MAME's
// table index.  Step an RTL-style shift register from table[0] and require
// state == table[i mod period] for two full periods (covers the wrap
// table[period-1] -> table[0]).  Tables come from the pristine MAME code.
#include "pokey_ref.h"
#include <cstdio>

// RTL-style next-state functions (same equations go into rtl/pokey_cx.sv)
static uint32_t nx45(uint32_t s, int n)
{
	uint32_t m = (1u << n) - 1;
	uint32_t fb = (~((s >> 2) ^ (s >> (n - 1)))) & 1u;
	return ((s << 1) | fb) & m;
}
static uint32_t nx9(uint32_t s) { return (s >> 1) | ((((s >> 0) ^ (s >> 5)) & 1u) << 8); }
static uint32_t nx17(uint32_t s)
{
	uint32_t in8 = ((s >> 8) ^ (s >> 13)) & 1u;
	uint32_t t = s >> 1;
	t = (t & 0xff7fu) | (in8 << 7);
	return ((s & 1u) << 16) | t;
}

static int check(const char *name, const uint32_t *tab, uint32_t period, uint32_t (*nx)(uint32_t, int), int n)
{
	uint32_t s = tab[0];
	for (uint64_t i = 1; i <= 2ull * period; i++)
	{
		s = nx(s, n);
		if (s != tab[i % period])
		{
			printf("%s: FAIL at step %llu: rtl=%05x table[%llu]=%05x\n", name, (unsigned long long)i, s,
				(unsigned long long)(i % period), tab[i % period]);
			return 1;
		}
	}
	printf("%s: OK  period %u, init(table[0]) = 0x%05x, %u steps checked\n", name, period, tab[0], 2 * period);
	return 0;
}

int main()
{
	PokeyRef r(1512000, 0, false);
	r.power_on();
	int fails = 0;
	fails += check("poly4 ", r.dev.m_poly4, 0x0f, nx45, 4);
	fails += check("poly5 ", r.dev.m_poly5, 0x1f, nx45, 5);
	fails += check("poly9 ", r.dev.m_poly9, 0x1ff, [](uint32_t s, int) { return nx9(s); }, 9);
	fails += check("poly17", r.dev.m_poly17, 0x1ffff, [](uint32_t s, int) { return nx17(s); }, 17);
	// RANDOM in init mode (Warlords rule): poly17 table[0] >> 8 and poly9 table[0] low byte
	printf("init RANDOM poly17 = %02x, poly9 = %02x\n", (r.dev.m_poly17[0] >> 8) & 0xff, r.dev.m_poly9[0] & 0xff);
	// control: a wrong tap must fail
	int ctl = check("ctrl(poly9 tap4)", r.dev.m_poly9, 0x1ff,
		[](uint32_t s, int) { return (s >> 1) | ((((s >> 0) ^ (s >> 4)) & 1u) << 8); }, 9);
	printf("control %s\n", ctl ? "failed as required" : "DID NOT FAIL");
	printf("%s\n", (fails == 0 && ctl) ? "LFSR TEST PASS" : "LFSR TEST FAIL");
	return (fails == 0 && ctl) ? 0 : 1;
}
