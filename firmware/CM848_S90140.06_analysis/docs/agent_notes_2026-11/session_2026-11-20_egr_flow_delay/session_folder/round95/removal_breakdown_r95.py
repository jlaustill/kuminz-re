"""Round 95 (read-only): which judged element covers each row in overrides_r95.json's remove_globals, with counts per
element and the named rows each one removes. usage: removal_breakdown_r95.py <repo> <overrides.json> <batch.json>..."""
import collections
import json
import os
import re
import sys

repo, overrides = os.path.abspath(sys.argv[1]), json.load(open(sys.argv[2]))
names = {}
for line in open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 3)
    if len(p) > 2 and p[0].startswith("0x"):
        names[int(p[0], 16)] = (p[1], p[2])
elements = []
for path in sys.argv[3:]:
    d = json.load(open(path))
    vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
    for g in d["proposal"].get("globals") or []:
        if (g.get("firmware") or "CM550") != "CM550":
            continue
        v = vd.get(("global", str(g["address"]).lower())) or {}
        elements.append((int(g["address"], 16), v.get("final_name") or g["proposed_name"],
                         (v.get("final_type") or g.get("proposed_type") or "").strip(), d["batch"]))
elements.sort()
by = collections.defaultdict(list)
for a in sorted(int(x, 16) for x in overrides["remove_globals"]["CM550"]):
    holder = max((e for e in elements if e[0] < a), default=None, key=lambda e: e[0])
    by[holder[1:] if holder else ("(none)",)].append((a, names.get(a, ("?", ""))))
for k, v in sorted(by.items(), key=lambda kv: -len(kv[1])):
    named = [f"0x{a:x} {n}" for a, (n, t) in v if n]
    print(f"{len(v):4d} {k}: {len(named)} named: {', '.join(named[:6])}{' ...' if len(named) > 6 else ''}")
