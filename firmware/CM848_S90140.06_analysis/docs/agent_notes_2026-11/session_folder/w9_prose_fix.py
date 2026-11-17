"""Re-apply the governor agent's exact prose rows (notes 70 and 73) with a proper split: the first row after the label and
the last row's trailing sentence were mishandled by w9_stage_b.py.
usage: w9_prose_fix.py <CM848 output dir> <renames dir>"""
import json
import os
import sys

out, rdir = sys.argv[1:3]
notes = {n: json.loads(l) for n, l in enumerate(open(os.path.join(rdir, "aligned_W9_governor.jsonl")), 1) if l.strip()}
t70 = " ".join(notes[70]["text"].split())
body70 = t70.split("EXACT REPLACEMENT ROWS (global_variables.csv): ")[1].split(" If the function renames of this file are applied")[0]
t73 = " ".join(notes[73]["text"].split())
body73 = t73.split("EXACT ROWS: ")[1].split(". PLATE 0x0000ff04")[0]
rows = [r.strip() for r in body70.split(" | ")] + [r.strip() for r in body73.split(" | ")]
assert len(rows) == 8 and all(r.startswith("0x0040") for r in rows), [r[:20] for r in rows]
p = f"{out}/global_variables.csv"
gv = open(p).read().split("\n")
for row in rows:
    a, name = row.split(",")[:2]
    hits = [k for k, l in enumerate(gv) if l.startswith(f"{a},{name},")]
    assert len(hits) == 1, (a, name)
    gv[hits[0]] = row
open(p, "w").write("\n".join(gv))
print("rows applied:", [r.split(",")[0] for r in rows])
print("0x406fe2 ends:", rows[5][-90:])
