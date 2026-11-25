#!/bin/bash
# Round 94: dry-run apply_r94.py on a scratch copy of both firmwares' CSVs, with every element of the given batches'
# proposals marked CONFIRMED (synthetic verdicts), to see the reconciliation report before the judges answer.
# usage: dry_run_apply_r94.sh <repo> <batch ids...>
set -euo pipefail
REPO=$(cd "$1" && pwd)
shift
W=/home/linux/.claude/jobs/374b0424/tmp/w15/r94
S=$W/dry_run
rm -rf "$S"
for fw in CM550_J90350.00_analysis CM848_S90140.06_analysis; do
    mkdir -p "$S/repo/firmware/$fw/output"
    cp "$REPO/firmware/$fw/output/"*.csv "$S/repo/firmware/$fw/output/"
done
mkdir -p "$S/out"
cp "$W/apply_r94.py" "$S/apply_r94.py"; cp "$W/overrides_r94.json" "$S/overrides_r94.json"
FILES=""
for b in "$@"; do
    python3 - "$W/batch_$b.json" "$S/batch_$b.json" <<'EOF'
import json, sys
d = json.load(open(sys.argv[1]))
p = d["proposal"]
v = []
for f in p.get("functions") or []:
    v.append({"kind": "function", "firmware": "CM550", "address": f["address"], "verdict": "CONFIRMED", "final_name": f["proposed_name"],
              "final_relation": f["relation"], "final_cm848_address": f.get("cm848_address") or "", "reason": "dry run"})
for g in p.get("globals") or []:
    v.append({"kind": "global", "firmware": g["firmware"], "address": g["address"], "verdict": "CONFIRMED", "final_name": g["proposed_name"],
              "final_type": g["proposed_type"], "reason": "dry run"})
for e in p.get("enum_members") or []:
    v.append({"kind": "enum_member", "firmware": e["firmware"], "address": f"{e['enum_name']}:{int(e['value'])}", "verdict": "CONFIRMED",
              "final_name": e["proposed_member"], "reason": "dry run"})
d["verdict"] = {"batch": d["batch"], "verdicts": v}
json.dump(d, open(sys.argv[2], "w"))
EOF
    FILES="$FILES $S/batch_$b.json"
done
python3 "$S/apply_r94.py" "$S/repo" "$S/out" $FILES > "$S/report.txt" 2>&1 || true
cat "$S/report.txt"
