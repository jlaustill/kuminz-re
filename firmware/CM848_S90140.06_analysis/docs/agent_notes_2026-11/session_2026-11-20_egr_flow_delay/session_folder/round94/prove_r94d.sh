#!/bin/bash
# Round 94 stage D proofs (the EEPROM image window: 71 CM550 _cal renames, one CM848 array rename): per firmware the
# function set, the token diff with the map (a label-only change must leave no unmapped token), statement counts,
# the caller census, old names left in code; then the overlap check. Base = HEAD 9b467c63 (stage C).
# usage: FIRMWARES="cm550 cm848" prove_r94d.sh <repo>
set -uo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15
OUT=$W/r94/proof_r94d
mkdir -p "$OUT"
for fw in ${FIRMWARES:-cm550 cm848}; do
    if [ $fw = cm550 ]; then POST=$REPO/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp; PRE=$W/r94/post_r94c2_cm550.cpp
    else POST=$REPO/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp; PRE=$W/r94/head_r94d_cm848.cpp; fi
    MAP=$W/r94/map_r94d_$fw.csv
    echo "######## $fw ($(grep -c '^// Function: ' "$POST") functions; base $(grep -c '^// Function: ' "$PRE"))"
    python3 $W/r84/function_set_check.py "$PRE" "$POST" "$MAP" > "$OUT/function_set_$fw.txt" 2>&1
    head -3 "$OUT/function_set_$fw.txt"
    python3 $W/r87/token_diff.py "$PRE" "$POST" "$MAP" > "$OUT/token_diff_$fw.txt" 2>&1
    echo "-- token diff: $(grep -c ': [0-9]* token changes' "$OUT/token_diff_$fw.txt") functions with unmapped changes"
    sed -n '/---- census/,$p' "$OUT/token_diff_$fw.txt" | head -20
    python3 $W/r93/line_count_diff_r93.py "$PRE" "$POST" > "$OUT/line_count_$fw.txt" 2>&1
    echo "-- statements: $(grep 'functions with a different statement count' "$OUT/line_count_$fw.txt")"
    python3 $W/r86/caller_census.py "$PRE" "$POST" "$OUT/function_set_$fw.txt" > "$OUT/caller_census_$fw.txt" 2>&1
    tail -2 "$OUT/caller_census_$fw.txt"
    python3 $W/r94/old_names_in_code_r94.py "$POST" "$MAP"
    python3 $W/r94/render_check_r94.py "$POST" "$MAP" | head -1
done
python3 $W/r94/overlap_check_r94.py "$REPO" --since HEAD | cut -c1-200
