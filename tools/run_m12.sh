#!/bin/bash
# M12: lockstep regression.  Logs: verilator/out/m12_*.log, summary on stdout.
#  1. every game trace, native pokey_cx (normal + --merge)
#  2. every game trace through pokey_glue with the old port protocol (--glue)
#  3. fuzz seeds 1-32 x CLK clocks, 2 chips: std + war builds (normal + --merge), glue_std + glue_war builds
#  4. control: old Mark Watson RTL, out_raw only, every game trace -> must DIVERGE
# usage: run_m12.sh [clocks per fuzz seed] [parallel jobs]
set -u
P=$(cd "$(dirname "$0")/.." && pwd)
V=$P/verilator
CLK=${1:-100000000}
J=${2:-20}
mkdir -p "$V/out"
rm -f "$V"/out/m12_*.log
jobs_list=()
for t in "$P"/traces/*.ptr; do
    b=$(basename "$t" .ptr)
    case $b in warlords*) tb=tb_war; gtb=tb_glue_war; otb=tb_old_war;; milliped*|mazeinv*|multiped*) tb=tb_mil; gtb=tb_glue_std; otb=tb_old_std;; *) tb=tb_std; gtb=tb_glue_std; otb=tb_old_std;; esac
    jobs_list+=("$V/$tb --trace $t > $V/out/m12_trace_$b.log")
    jobs_list+=("$V/$tb --trace $t --merge > $V/out/m12_trace_${b}_merge.log")
    jobs_list+=("$V/$gtb --glue --trace $t > $V/out/m12_gluetrace_$b.log")
    jobs_list+=("$V/$otb --glue --outonly --trace $t > $V/out/m12_ctrl_old_$b.log")
done
for s in $(seq 1 32); do
    for tb in tb_std tb_war; do
        jobs_list+=("$V/$tb --fuzz $s --clocks $CLK --fuzz-chips 2 > $V/out/m12_fuzz_${tb}_$s.log")
        jobs_list+=("$V/$tb --fuzz $s --clocks $CLK --fuzz-chips 2 --merge > $V/out/m12_fuzz_${tb}_${s}_merge.log")
    done
    for tb in tb_glue_std tb_glue_war; do
        jobs_list+=("$V/$tb --glue --fuzz $s --clocks $CLK --fuzz-chips 2 > $V/out/m12_glue_fuzz_${tb}_$s.log")
    done
done
printf '%s\n' "${jobs_list[@]}" | xargs -P "$J" -I{} bash -c '{}'
for kind in trace gluetrace fuzz glue_fuzz; do
    n=$(ls "$V"/out/m12_${kind}_*.log 2>/dev/null | wc -l)
    p=$(grep -l '^PASS' "$V"/out/m12_${kind}_*.log 2>/dev/null | wc -l)
    echo "M12 $kind: $p / $n PASS"
done
n=$(ls "$V"/out/m12_ctrl_old_*.log | wc -l)
d=$(grep -l '^DIVERGE' "$V"/out/m12_ctrl_old_*.log | wc -l)
echo "M12 control (old RTL, out_raw only): $d / $n traces DIVERGE (required: every trace with non-zero volume writes)"
for f in "$V"/out/m12_ctrl_old_*.log; do echo "  $(basename "$f" .log): $(head -2 "$f" | tr '\n' ' ' | cut -c1-110)"; done
grep -L '^PASS' "$V"/out/m12_trace_*.log "$V"/out/m12_gluetrace_*.log "$V"/out/m12_glue_fuzz_*.log "$V"/out/m12_fuzz_*.log 2>/dev/null | while read -r f; do echo "FAIL: $f"; head -3 "$f"; done
