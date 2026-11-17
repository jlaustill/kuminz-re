"""Collect naming_concern / skip reasons from result files into one compact list."""
import glob
import json
import os
import sys

d = sys.argv[1]
for path in sorted(glob.glob(os.path.join(d, "result_*.jsonl"))):
    tag = os.path.basename(path)[7:-6]
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        r = json.loads(line)
        c = (r.get("naming_concern") or "").strip()
        if c:
            print(f"[{tag}] {r.get('lookup') or r.get('table')}: {c[:260]}")
        if r.get("skip"):
            print(f"[{tag}] SKIP {r.get('lookup')}: {(r.get('reason') or '')[:200]}")
