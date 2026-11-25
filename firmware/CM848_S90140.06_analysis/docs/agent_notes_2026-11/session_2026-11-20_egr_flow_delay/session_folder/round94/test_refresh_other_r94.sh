#!/bin/bash
# Round 94: test the fixed refresh_other_csvs.py on a scratch copy of both firmwares' CSVs:
# 1. the throttle map: the struct field alternate_throttle_priority must keep its name (only a comment may change);
# 2. the round 93 freeze frame maps (functions in both firmwares): the function-name columns must follow the renames;
# 3. line endings of CRLF files stay CRLF. usage: test_refresh_other_r94.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
T=$W/refresh_test
rm -rf "$T"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    mkdir -p "$T/firmware/$fw/output"
    cp "$REPO/firmware/$fw/output/"*.csv "$T/firmware/$fw/output/"
done
echo "-- 1. throttle map"
python3 "$W/../r88/refresh_other_csvs.py" "$T" --own-only --cm550 "$W/map_r94b_cm550.csv" | grep -v ": 0 ref" || true
diff "$REPO/firmware/CM550_J90350.00_analysis/output/structure_definitions.csv" "$T/firmware/CM550_J90350.00_analysis/output/structure_definitions.csv" | grep "^[<>]" | cut -c1-150 || true
grep -c "^cm550_commanded_throttle_state_t,,alternate_throttle_priority," "$T/firmware/CM550_J90350.00_analysis/output/structure_definitions.csv"
file "$T/firmware/CM550_J90350.00_analysis/output/structure_definitions.csv" | grep -o "CRLF.*"
echo "-- 2. a function map on a fresh copy: names in the function-name column follow"
cp "$REPO/firmware/CM550_J90350.00_analysis/output/"*.csv "$T/firmware/CM550_J90350.00_analysis/output/"
printf 'address,name,old_label,kind,dims\n0x0002fe38,cm550_testRenamedFunction,cm550_captureFaultFreezeFrame,symbol,1\n' > "$T/map_fn.csv"
sed -i 's/^0x0002fe38,cm550_captureFaultFreezeFrame,/0x0002fe38,cm550_testRenamedFunction,/' "$T/firmware/CM550_J90350.00_analysis/output/function_renames.csv"
python3 "$W/../r88/refresh_other_csvs.py" "$T" --own-only --cm550 "$T/map_fn.csv" | grep -v ": 0 ref" || true
grep -c "^0x0002fe38,cm550_testRenamedFunction," "$T/firmware/CM550_J90350.00_analysis/output/function_definitions.csv"
grep -c "cm550_captureFaultFreezeFrame" "$T/firmware/CM550_J90350.00_analysis/output/function_definitions.csv" || echo "0 (old name gone)"
