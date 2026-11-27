#!/bin/bash
# Round 94: dry-run the leads apply (r94/leads/apply_r94.py + overrides) on a scratch copy of both firmwares' CSVs,
# with the placeholder function rows added first. usage: leads_dry_run_r94.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
S=$W/leads_dry_run
rm -rf "$S"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    mkdir -p "$S/repo/firmware/$fw/output"
    cp "$REPO/firmware/$fw/output/"*.csv "$S/repo/firmware/$fw/output/"
done
mkdir -p "$S/out"
cp "$W/leads/apply_r94.py" "$W/leads/overrides_r94.json" "$S/"
python3 "$W/add_function_placeholders_r94.py" "$S/repo" > /dev/null
python3 "$S/apply_r94.py" "$S/repo" "$S/out" "$W/batch_L1.json" "$W/batch_L2.json" "$W/batch_L3.json" "$W/batch_L4.json" 2>&1 | tail -30
echo "-- report lines of interest:"
grep "TYPE\|SKIP\|DROPPED\|NOTE\|proposed names\|created" "$S/out/apply_report_r94.txt" 2>/dev/null | cut -c1-230 | head -40 || true
