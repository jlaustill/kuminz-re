#!/bin/bash
# Round 94: run apply_r94.py with the judges' real verdicts on a scratch copy of both firmwares' CSVs (and the twin
# types copied first) to read its report before the real apply. usage: real_dry_run_r94.sh <repo> <batch ids...>
set -euo pipefail
REPO=$(cd "$1" && pwd)
shift
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
S=$W/real_dry_run
rm -rf "$S"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    mkdir -p "$S/repo/firmware/$fw/output"
    cp "$REPO/firmware/$fw/output/"*.csv "$S/repo/firmware/$fw/output/"
done
mkdir -p "$S/out"
cp "$W/apply_r94.py" "$W/overrides_r94.json" "$S/"
python3 "$W/copy_twin_types_r94.py" "$S/repo" > /dev/null
FILES=""
for b in "$@"; do FILES="$FILES $W/batch_$b.json"; done
python3 "$S/apply_r94.py" "$S/repo" "$S/out" $FILES 2>&1 | tail -40
echo "-- report lines of interest:"
grep "TYPE\|SKIP\|DROPPED\|NOTE\|proposed names\|struct\|removed" "$S/out/apply_report_r94.txt" 2>/dev/null | cut -c1-220 | head -40 || true
