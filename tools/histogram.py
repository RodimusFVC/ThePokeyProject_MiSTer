#!/usr/bin/env python3
"""M2: register-usage histogram per game/chip from capture .raw files.
usage: histogram.py file.raw [...]"""
import sys
from collections import Counter, defaultdict

WN = ["AUDF1", "AUDC1", "AUDF2", "AUDC2", "AUDF3", "AUDC3", "AUDF4", "AUDC4",
      "AUDCTL", "STIMER", "SKREST", "POTGO", "w0C", "SEROUT", "IRQEN", "SKCTL"]
RN = ["POT0", "POT1", "POT2", "POT3", "POT4", "POT5", "POT6", "POT7",
      "ALLPOT", "KBCODE", "RANDOM", "r0B", "r0C", "SERIN", "IRQST", "SKSTAT"]


def main():
    for fn in sys.argv[1:]:
        w = defaultdict(Counter)      # chip -> reg -> count
        vals = defaultdict(lambda: defaultdict(Counter))
        r = defaultdict(Counter)
        inputs = []
        end = 0
        for line in open(fn):
            t = line.split()
            if not t:
                continue
            if t[0] == "W":
                chip, reg, d = t[2], int(t[3]), int(t[4])
                w[chip][reg] += 1
                vals[chip][reg][d] += 1
            elif t[0] == "R":
                r[t[2]][int(t[3])] += 1
            elif t[0] == "E":
                end = int(t[1])
            elif line.startswith("# input"):
                inputs.append(line.strip()[2:])
        print(f"== {fn.split('/')[-1]}  end clock {end}  scripted inputs: {len(inputs)}")
        for chip in sorted(set(w) | set(r)):
            print(f"  [{chip}] writes:", ", ".join(f"{WN[k]}={w[chip][k]}" for k in sorted(w[chip])))
            for k, name in ((15, "SKCTL"), (8, "AUDCTL"), (14, "IRQEN"), (13, "SEROUT"), (9, "STIMER"), (11, "POTGO"), (10, "SKREST")):
                if vals[chip][k]:
                    print(f"     {name} values: " + " ".join(f"{v:02X}x{c}" for v, c in sorted(vals[chip][k].items())))
            dist = Counter()
            for k in (1, 3, 5, 7):
                for v, c in vals[chip][k].items():
                    dist[v >> 4] += c
            if dist:
                print("     AUDC high nibble (dist|volonly): " + " ".join(f"{v:X}x{c}" for v, c in sorted(dist.items())))
            print(f"  [{chip}] reads :", ", ".join(f"{RN[k]}={r[chip][k]}" for k in sorted(r[chip])))


if __name__ == "__main__":
    main()
