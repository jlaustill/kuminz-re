#!/bin/bash
# Round 94 stage C proofs (the four judged batches): per firmware the function set, the token diff with the apply's
# map, statement counts, the caller census and the piece census; then the row overlap check against HEAD.
# usage: prove_r94c.sh <repo>
set -uo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15
PC=$REPO/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave11/piece_census.py
OUT=$W/r94/proof_r94c
mkdir -p "$OUT"
for fw in ${FIRMWARES:-cm550 cm848}; do
    if [ $fw = cm550 ]; then POST=$REPO/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp
    else POST=$REPO/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp; fi
    PRE=$W/r94/head_r94c_$fw.cpp
    MAP=$W/r94/apply_out/map_r94_${fw}_underscore.csv; [ -f "$MAP" ] || MAP=$W/r94/apply_out/map_r94_$fw.csv
    echo "######## $fw"
    python3 $W/r84/function_set_check.py "$PRE" "$POST" "$MAP" > "$OUT/function_set_$fw.txt" 2>&1
    head -3 "$OUT/function_set_$fw.txt"
    python3 $W/r87/token_diff.py "$PRE" "$POST" "$MAP" > "$OUT/token_diff_$fw.txt" 2>&1
    echo "-- token diff: $(grep -c ': [0-9]* token changes' "$OUT/token_diff_$fw.txt") functions with unmapped changes"
    sed -n '/---- census/,$p' "$OUT/token_diff_$fw.txt" | head -45
    python3 $W/r93/line_count_diff_r93.py "$PRE" "$POST" > "$OUT/line_count_$fw.txt" 2>&1
    echo "-- statements: $(head -1 "$OUT/line_count_$fw.txt")"
    python3 $W/r86/caller_census.py "$PRE" "$POST" "$OUT/function_set_$fw.txt" > "$OUT/caller_census_$fw.txt" 2>&1
    tail -3 "$OUT/caller_census_$fw.txt"
    python3 "$PC" "$PRE" "$POST" > "$OUT/piece_census_$fw.txt" 2>&1
    echo "-- pieces:"; tail -6 "$OUT/piece_census_$fw.txt"
done
echo "######## overlaps"
python3 $W/r94/overlap_check_r94.py "$REPO" --since HEAD | cut -c1-200
