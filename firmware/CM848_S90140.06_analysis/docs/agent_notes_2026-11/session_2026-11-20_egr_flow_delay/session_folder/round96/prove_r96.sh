#!/bin/bash
# Round 96: the proof suite for one firmware build in the copy. usage: prove_r96.sh <stage> <cm848|cm550> <map.csv>
W=/home/linux/.claude/jobs/374b0424/tmp/w15
S=$1
F=$2
M=$3
if [ "$F" = cm848 ]; then
  B=/tmp/kuminz-fwbuild-374b0424/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
else
  B=/tmp/kuminz-fwbuild-374b0424/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp
fi
BASE=$W/r96/base_r96${S}_$F.cpp
PC=/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/wave11/piece_census.py
echo "== $F function set"
python3 $W/r84/function_set_check.py $BASE $B $M 2>&1 | grep "removed\|added\|changed"
python3 $W/r87/token_diff.py $BASE $B $M > $W/r96/token_diff_r96${S}_$F.txt 2>&1
echo "== $F unmapped: $(grep -c ': [0-9]* token changes' $W/r96/token_diff_r96${S}_$F.txt)"
python3 $W/r94/classify_census_r94.py $W/r96/token_diff_r96${S}_$F.txt $M | grep "^=="
python3 $W/r93/line_count_diff_r93.py $BASE $B | grep "functions with a different\|^0x"
python3 $PC $BASE $B 2>&1 | tail -4
python3 $W/r94/old_names_in_code_r94.py $B $M | head -5
echo "== $F renders False: $(python3 $W/r94/render_check_r94.py $B $M | grep -c 'new renders False')"
for t in unaff_ extraout_ in_ CONCAT; do echo "$t $(grep -c "$t" $BASE) -> $(grep -c "$t" $B)"; done
