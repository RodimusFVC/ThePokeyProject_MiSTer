#!/usr/bin/env python3
"""Directed lockstep tests (plan 4.3) as .ptr v2 files -> verilator/tests/.
Serial/two-tone tests (T12/T13) are not generated: SERIAL not implemented (M2 histogram).
Chip configs: std build slot0 = (pot_cb 00, allpot_cb 0), slot1 = (00, 1); war build slot0 = (0F, 0).
usage: gen_tests.py [outdir]"""
import os
import random
import sys

P = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(P, "verilator", "tests")

AUDF = [0, 2, 4, 6]
AUDC = [1, 3, 5, 7]
AUDCTL, STIMER, SKREST, POTGO, SEROUT, IRQEN, SKCTL = 8, 9, 10, 11, 13, 14, 15


class T:
    def __init__(self, name, chips=(("t", 0x00, 0),), seed=1):
        self.name, self.chips, self.k, self.ev = name, chips, 0, []
        self.rng = random.Random(seed)

    def w(self, reg, d, chip=0):
        self.ev.append(f"W {self.k} {chip} {reg} {d & 0xff}")

    def r(self, reg, d=0, chip=0):
        self.ev.append(f"r {self.k} {chip} {reg} {d & 0xff}")

    def p(self, idx, v, chip=0):
        self.ev.append(f"P {self.k} {chip} {idx} {v & 0xff}")

    def run(self, n):
        self.k += n

    def readall(self, chip=0):
        for a in range(16):
            if a == 8 and self.chips[chip][2]:
                continue
            self.r(a, 0, chip)

    def save(self):
        os.makedirs(OUT, exist_ok=True)
        fn = os.path.join(OUT, self.name + ".ptr")
        with open(fn, "w") as f:
            f.write(f"# ptr v2 set=directed clk=1512000 test={self.name}\n")
            for i, (n, pm, acb) in enumerate(self.chips):
                f.write(f"C {i} {n} {pm:02x} {acb}\n")
            f.write("\n".join(self.ev) + "\n")
            f.write(f"E {self.k + 10}\n")
        print(f"{fn}: {len(self.ev)} events, {self.k + 10} clocks")


def t01():
    t = T("T01_regs")
    t.readall(); t.run(3)
    t.w(SKCTL, 3); t.run(5)
    for reg in list(range(16)):
        for d in (0x00, 0xFF, 0x55, 0xAA, 0x01, 0x80):
            if reg == SKCTL:
                d &= 0x97
            t.w(reg, d); t.readall(); t.run(t.rng.randrange(1, 40))
            t.readall(); t.run(1)
    for i in range(400):
        reg = t.rng.randrange(16)
        d = t.rng.randrange(256)
        if reg == SKCTL:
            d &= 0x97
        t.w(reg, d); t.run(t.rng.randrange(0, 300)); t.readall()
    t.save()


def t02():
    t = T("T02_init", seed=2)
    for i in range(60):
        t.w(SKCTL, 0); t.run(t.rng.randrange(0, 50))
        t.w(AUDCTL, 0x80 if (i & 1) else 0x00)
        t.run(t.rng.randrange(0, 30))
        t.w(SKCTL, t.rng.choice([1, 2, 3, 3, 7]))
        for j in range(20):
            t.run(t.rng.randrange(1, 120))
            t.r(10)
            if t.rng.randrange(4) == 0:
                t.w(AUDCTL, t.rng.choice([0x00, 0x80]))
    t.w(SKCTL, 0); t.run(4); t.r(10); t.run(9); t.r(10)   # Warlords rule: FF, held
    t.w(SKCTL, 3); t.run(2000)
    t.save()


def tone(t, base_ctl, audfs, vols=None, hold=3000):
    t.w(AUDCTL, base_ctl)
    for ch in range(4):
        t.w(AUDF[ch], audfs[ch % len(audfs)])
        t.w(AUDC[ch], 0xA0 | (vols[ch] if vols else (ch * 4 + 3)))
    t.run(hold)


def t03(name="T03_64k", ctl=0x00, seed=3):
    t = T(name, seed=seed)
    t.w(SKCTL, 3); t.run(7)
    for f in (0, 1, 2, 0x7F, 0xFF):
        tone(t, ctl, [f, f + 1, f ^ 3, f], hold=40 * (f + 2) * (114 if ctl & 1 else 28) // 8 + 500)
    for v in range(16):
        t.w(AUDC[v & 3], 0x10 | v); t.run(300)           # volume only
        t.w(AUDC[v & 3], 0xA0 | v); t.run(300)
    for i in range(200):
        ch = t.rng.randrange(4)
        t.w(AUDF[ch], t.rng.choice([0, 1, 2, 3, 0x7F, 0xFF, t.rng.randrange(256)]))
        t.w(AUDC[ch], t.rng.choice([0xA0, 0x10, 0xA8, 0xAF, 0x1F]) | t.rng.randrange(16))
        t.run(t.rng.randrange(1, 3000))
    t.save()


def t05():
    t = T("T05_179", seed=5)
    t.w(SKCTL, 3); t.run(3)
    for f in list(range(6)) + [0xFF, 0x80]:
        t.w(AUDCTL, 0x60); t.w(AUDF[0], f); t.w(AUDF[2], f + 1)
        t.w(AUDC[0], 0xA7); t.w(AUDC[2], 0xA9); t.w(AUDC[1], 0xA2); t.w(AUDF[1], 3)
        t.run(2000 + 4 * f)
        t.w(AUDCTL, 0x40); t.run(700); t.w(AUDCTL, 0x20); t.run(700)
    t.save()


def t06():
    t = T("T06_noise", seed=6)
    t.w(SKCTL, 3); t.run(3)
    for ctl in (0x00, 0x01, 0x60, 0x80, 0x81, 0xE0):
        for dist in range(8):
            t.w(AUDCTL, ctl)
            for ch in range(4):
                t.w(AUDF[ch], t.rng.choice([0, 1, 5, 17, 100, 255]))
                t.w(AUDC[ch], (dist << 5) | (ch * 3 + 5) & 15)
            t.run(4000)
    t.save()


def t07():
    t = T("T07_linked", seed=7)
    t.w(SKCTL, 3); t.run(3)
    for ctl in (0x50, 0x28, 0x78, 0x10, 0x08, 0x18, 0x19, 0x11):
        t.w(AUDCTL, ctl)
        for ch in range(4):
            t.w(AUDF[ch], t.rng.choice([0, 1, 2, 3, 4, 0x10, 0xFF]))
            t.w(AUDC[ch], 0xA0 | (ch + 8))
        t.run(6000)
        for j in range(20):            # AUDF changes mid-count
            t.w(AUDF[t.rng.randrange(4)], t.rng.randrange(8)); t.run(t.rng.randrange(1, 400))
    t.save()


def t08():
    t = T("T08_filters", seed=8)
    t.w(SKCTL, 3); t.run(3)
    for ctl in (0x00, 0x04, 0x02, 0x06, 0x66, 0x26, 0x46, 0x7E, 0x01, 0x07):
        t.w(AUDCTL, ctl)
        for ch in range(4):
            t.w(AUDF[ch], t.rng.choice([1, 3, 7, 20, 60]))
            t.w(AUDC[ch], 0xA0 | (ch * 4 + 3))
        t.run(5000)
        t.w(AUDCTL, ctl ^ 0x06); t.run(t.rng.randrange(1, 300)); t.w(AUDCTL, ctl); t.run(2000)
    t.save()


def t09():
    t = T("T09_stimer", seed=9)
    t.w(SKCTL, 3); t.run(3)
    for i in range(400):
        if i % 50 == 0:
            t.w(AUDCTL, t.rng.choice([0x00, 0x06, 0x60, 0x66, 0x78, 0x7E, 0x01]))
            for ch in range(4):
                t.w(AUDF[ch], t.rng.choice([0, 1, 2, 3, 5]))
                t.w(AUDC[ch], 0xA0 | t.rng.randrange(16))
        t.run(t.rng.randrange(0, 60))
        t.w(STIMER, t.rng.randrange(256))
    t.run(1000)
    t.save()


def t10():
    t = T("T10_irq", seed=10)
    t.r(14); t.w(IRQEN, 0x08); t.r(14); t.run(5); t.w(IRQEN, 0x00); t.r(14)
    t.w(SKCTL, 3); t.run(3)
    t.w(AUDCTL, 0x00)
    for ch in range(4):
        t.w(AUDF[ch], ch + 1); t.w(AUDC[ch], 0xA4)
    for i in range(300):
        t.w(IRQEN, t.rng.choice([0x00, 0x01, 0x02, 0x04, 0x07, 0x08, 0x0F, 0xFF, t.rng.randrange(256)]))
        t.run(t.rng.randrange(1, 800)); t.r(14)
        if t.rng.randrange(3) == 0:
            t.w(IRQEN, 0x00); t.r(14)
        if t.rng.randrange(10) == 0:
            t.w(SKCTL, 0); t.run(t.rng.randrange(0, 20)); t.r(14); t.w(SKCTL, 3)
        if t.rng.randrange(8) == 0:
            t.w(AUDCTL, t.rng.choice([0x00, 0x01, 0x60, 0x78, 0x50]))
        if t.rng.randrange(8) == 0:
            t.w(STIMER, 0)
    t.save()


def t11(name, chips, seed):
    t = T(name, chips=chips, seed=seed)
    nch = len(chips)
    for c in range(nch):
        t.w(POTGO, 0, c)                   # in init: ignored
        t.readall(c)
        if chips[c][2]:
            t.r(8, 0x5A, c)
    vals = [0, 1, 100, 227, 228, 255, 2, 29, 203]
    for i in range(80):
        c = t.rng.randrange(nch)
        for idx in range(8):
            t.p(idx, t.rng.choice(vals), c)
        t.w(SKCTL, t.rng.choice([3, 3, 7, 0x13, 0x17]), c)
        t.w(POTGO, t.rng.randrange(256), c)
        for j in range(t.rng.randrange(5, 40)):
            t.run(t.rng.choice([1, 3, 50, 114, 500, 2000]))
            for idx in range(8):
                t.r(idx, 0, c)
            t.r(8, t.rng.randrange(256), c)
        if t.rng.randrange(4) == 0:
            t.w(SKCTL, 0, c); t.r(8, t.rng.randrange(256), c); t.readall(c)
    t.run(30000)
    t.save()


def t14():
    t = T("T14_audctl", seed=14)
    t.w(SKCTL, 3); t.run(3)
    for ch in range(4):
        t.w(AUDF[ch], 2 + ch); t.w(AUDC[ch], 0xA5 + ch)
    for i in range(500):
        t.w(AUDCTL, t.rng.randrange(256)); t.run(t.rng.randrange(0, 500))
        if t.rng.randrange(4) == 0:
            t.w(AUDCTL, t.rng.randrange(256)); t.w(AUDCTL, t.rng.randrange(256))   # back-to-back
        if t.rng.randrange(5) == 0:
            sk = t.rng.choice([3, 3, 7, 0x13, 0x10 | 3, 0x83])
            t.w(SKCTL, sk); t.run(t.rng.randrange(0, 3)); t.w(SKCTL, sk)            # same value: early return
        if t.rng.randrange(6) == 0:
            t.w(AUDF[t.rng.randrange(4)], t.rng.randrange(256))
    # poly9/17 select switched on the clock of a noise borrow (write-then-step on one edge)
    t.w(SKCTL, 3)
    for ch in range(4):
        t.w(AUDF[ch], ch & 1); t.w(AUDC[ch], 0x8F)
    for i in range(3000):
        t.w(AUDCTL, t.rng.choice([0x60, 0xE0, 0x00, 0x80])); t.run(t.rng.randrange(1, 4))
    t.save()


def main():
    t01(); t02()
    t03()
    t03("T04_15k", 0x01, seed=4)
    t05(); t06(); t07(); t08(); t09(); t10()
    t11("T11_pots_std", (("p0", 0x00, 0), ("p1", 0x00, 1)), seed=11)
    t11("T11_pots_war", (("w0", 0x0F, 0), ("w1", 0x00, 0)), seed=111)
    t14()


if __name__ == "__main__":
    main()
