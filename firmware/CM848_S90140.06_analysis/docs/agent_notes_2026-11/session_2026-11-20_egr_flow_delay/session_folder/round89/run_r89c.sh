#!/bin/bash
# Round 89 stage C: apply, then refresh the old names. The keep list holds the old labels that are Calterm names
# themselves (the old global was named after the mnemonic, e.g. ADHBSVFT): the new comments cite those Calterm names,
# so they must not be refreshed. usage: run_r89c.sh <repo>
set -e
cd "$1"
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r89
D=firmware/CM550_J90350.00_analysis/docs/analog_sensor_channels.md
python3 $W/apply_r89c.py . $W/calterm_stems_r89.tsv $W/map_r89c_cm550.csv $D
KEEP=$(python3 - "$W/map_r89c_cm550.csv" "$W/calterm_stems_r89.tsv" <<'EOF'
import csv, sys
calterm = {r["name"] for r in csv.DictReader(open(sys.argv[2]), delimiter="\t")}
print(",".join(sorted({r["old_label"] for r in csv.DictReader(open(sys.argv[1])) if r["old_label"] in calterm})))
EOF
)
echo "keep: $KEEP"
RR=firmware/scripts/rename_waves/refresh_references.py
python3 $RR . $W/map_r89c_cm550.csv --firmware CM550_J90350.00_analysis --keep "$KEEP" --text does_not_exist.md | grep -v ": 0 references" || true
python3 $RR . $W/map_r89c_cm550.csv --firmware CM848_S90140.06_analysis --keep "$KEEP" --text does_not_exist.md | grep -v ": 0 references" || true
python3 $W/../r88/refresh_other_csvs.py . --own-only --cm550 $W/map_r89c_cm550.csv | grep -v ": 0 references" || true
G5=firmware/CM550_J90350.00_analysis/output/global_variables.csv
echo "state rows citing a field path: $(grep ',sensor_state_t,' $G5 | grep -c '_sensor_state\.[a-z]' || true)"
echo "config rows with the refreshed filter path: $(grep ',sensor_config_t,' $G5 | grep -c '_sensor_state\.filter\.coefficient points' || true)"
