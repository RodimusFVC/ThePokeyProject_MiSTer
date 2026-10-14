#!/usr/bin/env python3
"""Rig control: the lockstep rig must FAIL on behaviourally wrong RTL.
Each mutant = rtl/pokey_cx.sv with one planted bug (exact-string edit, asserted to
apply once), built as a std-config rig, run against the directed tests + a fuzz run
until the first divergence.  A mutant that survives everything = rig hole.
usage: mutate.py <scratch_dir> [mutant_name ...]"""
import os
import subprocess
import sys

P = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
V = os.path.join(P, "verilator")

MUTANTS = [
    ("borrow4to3",   "t = f_inc(n_cnt[0], n_bcnt[0], j12 ? 3'd7 : 3'd4);", "t = f_inc(n_cnt[0], n_bcnt[0], j12 ? 3'd7 : 3'd3);"),
    ("link7to6",     "t = f_inc(n_cnt[2], n_bcnt[2], j34 ? 3'd7 : 3'd4);", "t = f_inc(n_cnt[2], n_bcnt[2], j34 ? 3'd6 : 3'd4);"),
    ("div28",        "if (n_clk28 == 5'd27)", "if (n_clk28 == 5'd26)"),
    ("div114",       "if (n_clk114 == 7'd113)", "if (n_clk114 == 7'd112)"),
    ("p17tap",       "n_p17[8] ^ n_p17[13]", "n_p17[8] ^ n_p17[12]"),
    ("p5xnor",       "~(n_p5[2] ^ n_p5[4])", "(n_p5[2] ^ n_p5[4])"),
    ("p4tap",        "~(n_p4[2] ^ n_p4[3])", "~(n_p4[1] ^ n_p4[3])"),
    ("p9tap",        "{n_p9[0] ^ n_p9[5], n_p9[8:1]}", "{n_p9[0] ^ n_p9[4], n_p9[8:1]}"),
    ("filt1off",     "n_fsmp[0] = n_audctl[2] ? n_outp[0] : 1'b1;", "n_fsmp[0] = n_audctl[2] ? n_outp[0] : 1'b0;"),
    ("stimer_fs",    "n_outp = 4'b0000; n_fsmp = 4'b0011;", "n_outp = 4'b0000; n_fsmp = 4'b0001;"),
    ("init_seroc",   "n_irqen = 8'h00; n_irqst = 8'h08;", "n_irqen = 8'h00; n_irqst = 8'h00;"),
    ("pot228",       "n_pot_cnt < POT_MAX", "n_pot_cnt <= POT_MAX"),
    ("irqen_seroc",  "n_irqst = n_irqst & (din | 8'h08);", "n_irqst = n_irqst & din;"),
    ("skctl_same",   "4'hF: if (din != skctl) begin", "4'hF: if (1'b1) begin"),
    ("link_irq",     "arm[2] = arm[2] | t[11];", "arm[2] = arm[2];"),
    ("random_bits",  "p17[15:8];", "p17[16:9];"),
    ("allpot_pol",   "(ALLPOT_CB ? allpot_ext : ~allpot)", "(ALLPOT_CB ? allpot_ext : allpot)"),
    ("async_off",    "async_rst = n_skctl[4];", "async_rst = 1'b0;"),
    ("volonly",      "|| n_audc[i][4])", "|| 1'b0)"),
    ("poly4sel",     "else if (c[1]) f_proc = p4b;", "else if (c[1]) f_proc = p5b;"),
    ("init_borrow",  "        // 9. CH3 borrow (runs in init mode too)\n        fire = (n_bcnt[2] == 3'd1);",
                     "        // 9. CH3 borrow (runs in init mode too)\n        fire = run && (n_bcnt[2] == 3'd1);"),
    ("potgo_init",   "4'hB: if (skctl[1:0] != 2'b00) begin", "4'hB: begin"),
    ("audctl_poly9", "poly9 = n_audctl[7];", "poly9 = audctl[7];"),
]

TESTS = ["T01_regs", "T02_init", "T03_64k", "T04_15k", "T05_179", "T06_noise", "T07_linked", "T08_filters",
         "T09_stimer", "T10_irq", "T11_pots_std", "T14_audctl"]


def build(scratch, name, src):
    d = os.path.join(scratch, name)
    os.makedirs(d, exist_ok=True)
    rtl = os.path.join(d, "pokey_cx.sv")
    with open(rtl, "w") as f:
        f.write(src)
    refinc = f"-I{P}/ref/shim -I{P}/ref/mame_0289 -I{P}/ref -I{V}"
    cmd = ["verilator", "-cc", "-O3", "--x-assign", "fast", "--x-initial", "fast", "-Wno-fatal", "-Wno-lint",
           "-DPOKEY_DBG", f"-I{P}/rtl", f"-I{V}", "--top-module", "tb_top", "-CFLAGS", f"-std=c++17 -O2 {refinc}",
           "-GS0_POT_CB=0", "-GS0_ALLPOT_CB=0", "-GS1_POT_CB=0", "-GS1_ALLPOT_CB=1",
           "--Mdir", os.path.join(d, "obj"), "--exe", os.path.join(V, "tb_top.sv"), rtl,
           os.path.join(V, "tb_pokey.cpp"), os.path.join(P, "ref/mame_0289/pokey.cpp"), os.path.join(P, "ref/pokey_ref.cpp"),
           "-o", os.path.join(d, "tb")]
    subprocess.run(cmd, check=True, capture_output=True)
    subprocess.run(["make", "-s", "-C", os.path.join(d, "obj"), "-f", "Vtb_top.mk", "-j8"], check=True, capture_output=True)
    return os.path.join(d, "tb")


def main():
    scratch = sys.argv[1]
    only = set(sys.argv[2:])
    base = open(os.path.join(P, "rtl", "pokey_cx.sv")).read()
    survivors = []
    for name, a, b in MUTANTS:
        if only and name not in only:
            continue
        n = base.count(a)
        assert n == 1, f"mutant {name}: pattern found {n} times"
        tb = build(scratch, name, base.replace(a, b))
        caught = None
        for t in TESTS + [x + " --merge" for x in TESTS]:
            tn, *extra = t.split()
            r = subprocess.run([tb, "--trace", os.path.join(V, "tests", tn + ".ptr"), "--readall"] + extra, capture_output=True, text=True)
            if r.returncode == 1:
                caught = (t, r.stdout.splitlines()[0] if r.stdout else "")
                break
        if caught is None:
            for extra in ([], ["--merge"]):
                r = subprocess.run([tb, "--fuzz", "7", "--clocks", "5000000", "--fuzz-chips", "2"] + extra, capture_output=True, text=True)
                if r.returncode == 1:
                    caught = ("fuzz seed 7 5M " + " ".join(extra), r.stdout.splitlines()[0])
                    break
        if caught:
            print(f"{name:13s} CAUGHT by {caught[0]}: {caught[1]}")
        else:
            print(f"{name:13s} SURVIVED")
            survivors.append(name)
    print(f"{len(survivors)} survivor(s): {' '.join(survivors)}")
    return 1 if survivors else 0


if __name__ == "__main__":
    sys.exit(main())
