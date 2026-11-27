"""Check the CM848 names cited in the N2 comments: each must exist in the frozen CM848 CSVs (at the cited address
when one is given). usage: python3 cm848_cited.py"""
import csv
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm848/"
g = {}
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        g.setdefault(r[1], []).append((int(r[0], 16), r[2], (r[3] if len(r) > 3 else "")[:160]))
fn = {}
for r in csv.reader(open(F + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        fn[r[1]] = int(r[0], 16)
props = json.load(open(J + "proposals_globals.json"))
seen = {}
for e in props:
    c = e["comment"]
    for m in re.finditer(r"CM848[^.;]*?\b([a-z][a-z0-9_]+[a-z0-9])\b(?: \((0x[0-9a-f]+)\))?", c):
        seen.setdefault((m.group(1), m.group(2)), set()).add(e["address"])
    for m in re.finditer(r"\b([a-z][a-z0-9_]*(?:_axis|_values|_cached_axis_offset(?:_2)?))\b(?: \((0x[0-9a-f]+)\))?", c):
        if m.group(2) and int(m.group(2), 16) < 0x800000 and int(m.group(2), 16) > 0x40000 and int(m.group(2), 16) < 0x60000 or (m.group(2) and int(m.group(2), 16) >= 0x400000 and int(m.group(2), 16) < 0x410000):
            seen.setdefault((m.group(1), m.group(2)), set()).add(e["address"])
    for m in re.finditer(r"\b(cm848_[A-Za-z0-9]+)\b", c):
        seen.setdefault((m.group(1), None), set()).add(e["address"])
for (nm, ad), where in sorted(seen.items()):
    if nm.startswith("cm848_"):
        print(f"FUNC {nm}: {'0x%x' % fn[nm] if nm in fn else 'MISSING'}")
        continue
    rows = g.get(nm)
    if not rows:
        if nm.endswith(("_axis", "_values", "_offset", "_offset_2")):
            print(f"GLOBAL {nm} ({ad}): MISSING in CM848   <- cited by {sorted(where)[:2]}")
        continue
    ok = (ad is None) or any(a == int(ad, 16) for a, t, c in rows)
    print(f"GLOBAL {nm} ({ad}): {[(hex(a), t) for a, t, c in rows]} {'OK' if ok else 'ADDRESS MISMATCH'}")
