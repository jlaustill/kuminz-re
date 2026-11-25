#!/bin/bash
# Round 94: apply the four judged batches to the repo: CM848's twin J1939 session types to CM550 first, then
# apply_r94.py (overrides_r94.json beside it); the maps and the report go to r94/apply_out.
# usage: run_apply_r94.sh <repo>
set -euo pipefail
REPO=$(cd "$1" && pwd)
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
OUT=$W/apply_out
rm -rf "$OUT"
mkdir -p "$OUT"
python3 "$W/copy_twin_types_r94.py" "$REPO"
python3 "$W/apply_r94.py" "$REPO" "$OUT" "$W/batch_F1.json" "$W/batch_J1.json" "$W/batch_J2.json" "$W/batch_D1.json" 2>&1 | tail -8
ls "$OUT"
