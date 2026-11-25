"""Round 94 (read-only): for every twin in the batch proposals, the CM848 row it would rename (its live name) and
where that name is cited in CLAUDE.md files and the CM848 CSV comments (the refresh would rewrite those).
usage: twin_targets_r94.py <repo> <batch_X.json>..."""
import csv
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
cm848 = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_renames.csv"), newline=""))
         if r and r[0].startswith("0x")}
docs = {}
for rel in ("CLAUDE.md", "firmware/CLAUDE.md"):
    p = os.path.join(repo, rel)
    if os.path.exists(p):
        docs[rel] = open(p).read().split("\n")
for path in sys.argv[2:]:
    p = json.load(open(path))["proposal"]
    for f in p.get("functions") or []:
        if f["relation"] != "twin":
            continue
        a = int(re.search(r"0x[0-9a-fA-F]+", f["cm848_address"]).group(0), 16)
        live = cm848.get(a, "(NO CM848 ROW)")
        hits = [f"{rel}:{i + 1}" for rel, lines in docs.items() for i, l in enumerate(lines) if re.search(rf"\b{re.escape(live)}\b", l)]
        print(f"{p['batch']} CM550 {f['address']} -> {f['proposed_name']} | CM848 0x{a:x} {live}{' | CLAUDE.md: ' + ' '.join(hits) if hits else ''}")
