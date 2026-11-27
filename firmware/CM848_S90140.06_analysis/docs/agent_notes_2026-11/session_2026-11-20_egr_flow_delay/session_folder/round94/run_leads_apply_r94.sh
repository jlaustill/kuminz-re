#!/bin/bash
# Round 94 stage E: apply the leads batches L1-L4 to the repo (placeholder function rows first, then
# r94/leads/apply_r94.py with its overrides; maps + report to r94/leads_out), then refresh the references.
# usage: run_leads_apply_r94.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
OUT=$W/leads_out
rm -rf "$OUT"
mkdir -p "$OUT"
python3 "$W/add_function_placeholders_r94.py" "$REPO"
python3 "$W/leads/apply_r94.py" "$REPO" "$OUT" "$W/batch_L1.json" "$W/batch_L2.json" "$W/batch_L3.json" "$W/batch_L4.json" 2>&1 | grep -v "NOTE verdict" | tail -5
ls "$OUT"
bash /home/linux/.claude/jobs/374b0424/tmp/w15/r93/refresh_r93.sh "$REPO" "$OUT/map_r94_cm550.csv" "$OUT/map_r94_cm848.csv" 2>&1 | cut -c1-220 | head -40
