"""The unreviewed pool by word overlap: named scalar / array / enum rows, used in the code, dump in range, no '| e2m:'
keep note and no word-cite of the record in the comment. Prints the count per overlap band (unique addresses).
usage: overlap_pool_W15.py <audit.csv> <global_variables.csv>"""
import collections
import csv
import re
import sys

audit, gv = sys.argv[1:3]
rows = list(csv.DictReader(open(audit)))
comments = {}
for line in open(gv, errors="replace"):
    if line.startswith("0x"):
        parts = (line.rstrip("\n").split(",", 3) + [""])[:4]
        comments[int(parts[0], 16)] = parts[3]
SCALAR = {"byte", "word", "dword", "i16", "i32", "i8", "pointer"}


def reviewed(r):
    c = comments.get(int(r["address"], 16), "")
    return "| e2m:" in c or re.search(rf"\b{re.escape(r['record'])}\b", c) is not None


pool = [r for r in rows if r["status"] == "named"
        and (r["row_type"] in SCALAR or r["row_type"].endswith("]") or r["row_type"].isupper())
        and r["token_overlap"] and int(r["references"] or 0) >= 1 and r["dump_in_range"] == "yes"]
print("named, used, in range (all overlaps):", len({r["address"] for r in pool}))
bands = collections.Counter()
unreviewed_bands = collections.Counter()
seen = set()
for r in sorted(pool, key=lambda x: float(x["token_overlap"])):
    if r["address"] in seen:
        continue
    seen.add(r["address"])
    o = float(r["token_overlap"])
    band = "0" if o == 0 else f"<={min(b for b in (0.2, 0.25, 0.34, 0.5, 0.67, 1.0) if o <= b)}"
    bands[band] += 1
    if not reviewed(r):
        unreviewed_bands[band] += 1
order = ["0", "<=0.2", "<=0.25", "<=0.34", "<=0.5", "<=0.67", "<=1.0"]
print("band: all / unreviewed")
for b in order:
    print(f"  {b}: {bands[b]} / {unreviewed_bands[b]}")
