#!/bin/bash
# Capture POKEY bus events from unmodified MAME 0.289 (plan 3.1).
# usage: run_capture.sh <set> <seconds> <out.raw> [POKEY_INPUTS spec]
# Headless, scratch cfg/nvram/snap dirs, plugins off, never -str.
set -euo pipefail
SET=$1; SECS=$2; OUT=$3; INPUTS=${4:-}
HERE=$(cd "$(dirname "$0")" && pwd)
MAME=/CybertronMD/Mame/mame
ROMS=/Work/Projects/Arcade-Centipede_MiSTer/games/mame
S=${POKEY_SCRATCH:-/tmp/claude-1000/-Work-Projects-ZZZ-Obsidian-FPGA-FPGA-Brain/d8dabd36-421a-4c87-b611-a080a6d81967/scratchpad/pokey/mame}
RUN=$(mktemp -d "$S.XXXXXX")
mkdir -p "$RUN/cfg" "$RUN/nv" "$RUN/snap"
POKEY_OUT=$(realpath -m "$OUT") POKEY_INPUTS="$INPUTS" \
"$MAME" "$SET" -rompath "$ROMS" -video none -sound none -nothrottle \
  -seconds_to_run "$SECS" -noplugins -skip_gameinfo -keyboardprovider none -mouseprovider none -joystickprovider none -lightgunprovider none \
  -cfg_directory "$RUN/cfg" -nvram_directory "$RUN/nv" -snapshot_directory "$RUN/snap" \
  -autoboot_delay 0 -autoboot_script "$HERE/capture_pokey.lua" > "$RUN/mame.log" 2>&1 || { cat "$RUN/mame.log"; exit 1; }
rm -rf "$RUN"
echo "captured $SET ${SECS}s -> $OUT ($(wc -l < "$OUT") lines)"
