#!/bin/bash
# Round 93: refresh the old names of a pair of maps (CM550, CM848) in comments - both firmwares, both directions;
# CM848's own refresh includes firmware/CLAUDE.md and test_disasm_tools.py - then sweep for leftovers.
# usage: refresh_r93.sh <repo> <cm550 map.csv> <cm848 map.csv>
set -e
cd "$1"
M5=$2
M8=$3
W=/home/linux/.claude/jobs/374b0424/tmp/w15
RR=firmware/scripts/rename_waves/refresh_references.py
echo "-- cm550 own"; python3 $RR . $M5 --firmware CM550_J90350.00_analysis --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm550 map into cm848"; python3 $RR . $M5 --firmware CM848_S90140.06_analysis --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm848 own (+ firmware/CLAUDE.md, test_disasm_tools.py)"; python3 $RR . $M8 --firmware CM848_S90140.06_analysis | grep -v ": 0 references" || true
echo "-- cm848 map into cm550"; python3 $RR . $M8 --firmware CM550_J90350.00_analysis --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- other csvs"; python3 $W/r88/refresh_other_csvs.py . --cm550 $M5 --cm848 $M8 | grep -v ": 0 references" || true
echo "-- sweeps"
python3 $W/r87/old_name_sweep.py . $M5 $M8 | grep -v "^work/tasks/\|^docs/plans/\|/agent_notes_\|/session_folder/" | cut -c1-240 | head -30 || true
python3 $W/r88/script_name_sweep.py . $M5 $M8 2>&1 | tail -2
