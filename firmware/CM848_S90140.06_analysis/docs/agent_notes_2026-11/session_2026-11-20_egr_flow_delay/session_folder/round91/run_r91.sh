#!/bin/bash
# Round 91: apply the five verified items, then refresh the old names (both firmwares, both directions; CM848's own
# refresh includes firmware/CLAUDE.md and test_disasm_tools.py; Calterm record names are kept). usage: run_r91.sh <repo>
set -e
cd "$1"
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r91
[ -n "${SKIP_APPLY:-}" ] || python3 $W/apply_r91.py . $W $W/item_S1.json $W/item_S2.json $W/item_S3.json $W/item_T1.json $W/item_T2.json
python3 $W/keep_lists_r91.py . $W
RR=firmware/scripts/rename_waves/refresh_references.py
K5=$(cat $W/keep_r91_cm550.txt)
echo "-- cm550 own"; python3 $RR . $W/map_r91_cm550.csv --firmware CM550_J90350.00_analysis --keep "$K5" --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm550 map into cm848"; python3 $RR . $W/map_r91_cm550.csv --firmware CM848_S90140.06_analysis --keep "$K5" --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- cm848 own (+ firmware/CLAUDE.md, test_disasm_tools.py)"; python3 $RR . $W/map_r91_cm848.csv --firmware CM848_S90140.06_analysis | grep -v ": 0 references" || true
echo "-- cm848 map into cm550"; python3 $RR . $W/map_r91_cm848.csv --firmware CM550_J90350.00_analysis --text does_not_exist.md | grep -v ": 0 references" || true
echo "-- other csvs"; python3 $W/../r88/refresh_other_csvs.py . --cm550 $W/map_r91_cm550_nokeep.csv --cm848 $W/map_r91_cm848_nokeep.csv | grep -v ": 0 references" || true
