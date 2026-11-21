"""The wave 15 candidate funnel: how many audit rows each filter removes, and the dump_in_range values.
usage: funnel_W15.py <audit.csv> <global_variables.csv>"""
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
stage = rows
print("audit rows:", len(stage))
stage = [r for r in stage if r["status"] == "named"]
print("named:", len(stage))
stage = [r for r in stage if r["row_type"] in SCALAR or r["row_type"].endswith("]") or r["row_type"].isupper()]
print("scalar / array / enum rows:", len(stage))
stage = [r for r in stage if r["token_overlap"] and float(r["token_overlap"]) == 0]
print("no shared word:", len(stage))
print("  dump_in_range values here:", collections.Counter(r["dump_in_range"] or "(blank)" for r in stage))
print("  references here (5 = 5+):", sorted(collections.Counter(min(int(r["references"] or 0), 5) for r in stage).items()))
used = [r for r in stage if int(r["references"] or 0) >= 1]
print("used in code (1+ references):", len(used))
for v in ("yes", "no", ""):
    print(f"  of those, dump_in_range={v or '(blank)'}:", sum(1 for r in used if r["dump_in_range"] == v))


def reviewed_marker(r):
    return "| e2m:" in comments.get(int(r["address"], 16), "")


def cites_record(r):
    return re.search(rf"\b{re.escape(r['record'])}\b", comments.get(int(r["address"], 16), "")) is not None


ok = [r for r in used if r["dump_in_range"] in ("yes", "")]
print("dump in range or not in the dump:", len(ok))
print("  with a '| e2m:' keep note:", sum(1 for r in ok if reviewed_marker(r)))
print("  citing the record by word:", sum(1 for r in ok if not reviewed_marker(r) and cites_record(r)))
left = [r for r in ok if not reviewed_marker(r) and not cites_record(r)]
print("left:", len(left), "unique addresses:", len({r["address"] for r in left}))
