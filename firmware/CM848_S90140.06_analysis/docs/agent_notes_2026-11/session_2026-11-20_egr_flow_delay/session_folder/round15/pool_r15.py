"""Round 15: the e2m pool above wave 15's 0.2 overlap, with wave 15's filter (build_context_W15.py): named scalar /
array / enum rows used in the code, dump value in range, not reviewed before (no '| e2m:' keep note and the comment
does not cite the record), and no other record at the address matching the name better. Prints one line per row for a
hand review: overlap, address, current name, type, record, unit, description.
usage: pool_r15.py <audit.csv> <global_variables.csv> <low> <high> [--block-prefix P]"""
import collections
import csv
import re
import sys

audit, gv, low, high = sys.argv[1], sys.argv[2], float(sys.argv[3]), float(sys.argv[4])
comments = {}
for line in open(gv, errors="replace"):
    if line.startswith("0x"):
        parts = (line.rstrip("\n").split(",", 3) + [""])[:4]
        comments[int(parts[0], 16)] = parts[3]
SCALAR = {"byte", "word", "dword", "i16", "i32", "i8", "pointer"}
rows = list(csv.DictReader(open(audit)))


def reviewed(r):
    c = comments.get(int(r["address"], 16), "")
    return "| e2m:" in c or re.search(rf"\b{re.escape(r['record'])}\b", c) is not None


best = collections.defaultdict(float)
for r in rows:
    if r["token_overlap"]:
        best[r["address"]] = max(best[r["address"]], float(r["token_overlap"]))
seen = set()
out = []
for r in rows:
    if r["status"] != "named" or not r["token_overlap"]:
        continue
    if not (r["row_type"] in SCALAR or r["row_type"].endswith("]") or r["row_type"].isupper()):
        continue
    v = best[r["address"]]
    if not (low < v <= high) or int(r["references"] or 0) < 1 or r["dump_in_range"] != "yes" or reviewed(r):
        continue
    if r["address"] in seen:
        continue
    seen.add(r["address"])
    out.append((r["block"], r["offset"], v, r))
for block, off, v, r in sorted(out):
    print(f"{v:.2f} {r['block']}+{r['offset']} {r['address']} {r['row_name']} [{r['row_type']}] <- {r['record']} "
          f"({r['unit']}) {r['description'][:90]}")
print(f"{len(out)} rows in ({low}, {high}]", file=sys.stderr)
