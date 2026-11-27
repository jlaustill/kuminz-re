#!/bin/bash
# Round 93: apply the judged batches, then refresh the old names in comments (both firmwares, both directions; CM848's
# own refresh includes firmware/CLAUDE.md and test_disasm_tools.py; Calterm record names are kept), then sweep.
# SKIP_APPLY=1 skips the apply (the maps must exist). usage: run_r93.sh <repo> <batch ids...>
set -e
cd "$1"
shift
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r93
FILES=""
for b in "$@"; do FILES="$FILES $W/batch_$b.json"; done
[ -n "${SKIP_APPLY:-}" ] || python3 $W/apply_r93.py . $W $FILES
python3 $W/keep_lists_r93.py . $W
RR=firmware/scripts/rename_waves/refresh_references.py
K5=$(cat $W/keep_r93_cm550.txt)
K8=$(cat $W/keep_r93_cm848.txt)
echo "-- cm550 own"; python3 $RR . $W/map_r93_cm550.csv --firmware CM550_J90350.00_analysis ${K5:+--keep "$K5"} --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm550 map into cm848"; python3 $RR . $W/map_r93_cm550.csv --firmware CM848_S90140.06_analysis ${K5:+--keep "$K5"} --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm848 own (+ firmware/CLAUDE.md, test_disasm_tools.py)"; python3 $RR . $W/map_r93_cm848.csv --firmware CM848_S90140.06_analysis ${K8:+--keep "$K8"} | grep -v ": 0 references" || true
echo "-- cm848 map into cm550"; python3 $RR . $W/map_r93_cm848.csv --firmware CM550_J90350.00_analysis ${K8:+--keep "$K8"} --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- other csvs"; python3 $W/../r88/refresh_other_csvs.py . --cm550 $W/map_r93_cm550_nokeep.csv --cm848 $W/map_r93_cm848_nokeep.csv | grep -v ": 0 references" || true
echo "-- sweeps"
python3 $W/../r87/old_name_sweep.py . $W/map_r93_cm550_nokeep.csv $W/map_r93_cm848_nokeep.csv | grep -v "^work/tasks/\|^docs/plans/\|/agent_notes_\|/session_folder/" | cut -c1-240 | head -30 || true
python3 $W/../r88/script_name_sweep.py . $W/map_r93_cm550.csv $W/map_r93_cm848.csv 2>&1 | tail -2
