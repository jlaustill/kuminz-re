#!/bin/bash
# Round 94 stage B proofs (the CM550 commanded throttle struct): function set, token diff with the map, statement
# counts, the caller census. usage: prove_r94b.sh <repo>
set -uo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15
PRE=${PRE:-$W/r94/head_r94b_cm550.cpp}
POST=$REPO/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp
MAP=${MAP:-$W/r94/map_r94b_cm550_full.csv}
OUT=$W/r94/proof_r94b
mkdir -p "$OUT"
ls -l "$PRE" "$POST" | awk '{print $5, $9}'
echo "== function set"
python3 $W/r84/function_set_check.py "$PRE" "$POST" "$MAP" > "$OUT/function_set.txt" 2>&1
tail -4 "$OUT/function_set.txt"
echo "== token diff"
python3 $W/r87/token_diff.py "$PRE" "$POST" "$MAP" > "$OUT/token_diff.txt" 2>&1
tail -25 "$OUT/token_diff.txt"
echo "== statement counts"
python3 $W/r93/line_count_diff_r93.py "$PRE" "$POST" > "$OUT/line_count.txt" 2>&1
head -6 "$OUT/line_count.txt"
echo "== caller census"
python3 $W/r86/caller_census.py "$PRE" "$POST" "$OUT/function_set.txt" > "$OUT/caller_census.txt" 2>&1
tail -4 "$OUT/caller_census.txt"
