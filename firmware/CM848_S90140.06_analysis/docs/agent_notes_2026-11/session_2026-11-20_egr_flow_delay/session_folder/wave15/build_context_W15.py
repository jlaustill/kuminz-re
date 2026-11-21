"""Wave 15 pre-pass (from wave 13's build_context_W13.py): named rows whose name shares no word with their table-resolved
e2m record, used in the code (1+ references), dump value in range, and not reviewed before (no '| e2m:' keep note,
and the comment does not cite the record). Each item carries the record, the current row and comment, the region
(it decides _cal), the access widths (width_census.py), up to 4 code lines and the block's other named rows.
usage: build_context_W15.py <audit.csv> <cpp> <global_variables.csv> <all.dis> <out dir> <bins> [--count] [--max-overlap X]"""
import collections
import csv
import json
import os
import re
import subprocess
import sys

audit, cpp, gv, alldis, out_dir, bins = sys.argv[1:7]
bins = int(bins)
HERE = os.path.dirname(os.path.abspath(__file__))
rows = list(csv.DictReader(open(audit)))
comments = {}
for line in open(gv, errors="replace"):
    if line.startswith("0x"):
        parts = (line.rstrip("\n").split(",", 3) + [""])[:4]
        comments[int(parts[0], 16)] = parts[3]
by_block = collections.defaultdict(list)
for r in rows:
    by_block[r["block"]].append(r)
SCALAR = {"byte", "word", "dword", "i16", "i32", "i8", "pointer"}


MAX_OVERLAP = float(sys.argv[sys.argv.index("--max-overlap") + 1]) if "--max-overlap" in sys.argv else 0.0


def reviewed(r):
    c = comments.get(int(r["address"], 16), "")
    return "| e2m:" in c or re.search(rf"\b{re.escape(r['record'])}\b", c) is not None


wanted = [r for r in rows if r["status"] == "named"
          and (r["row_type"] in SCALAR or r["row_type"].endswith("]") or r["row_type"].isupper())
          and r["token_overlap"] and float(r["token_overlap"]) <= MAX_OVERLAP and int(r["references"] or 0) >= 1
          and r["dump_in_range"] == "yes" and not reviewed(r)]
best_overlap = collections.defaultdict(float)
for r in rows:
    if r["token_overlap"]:
        best_overlap[r["address"]] = max(best_overlap[r["address"]], float(r["token_overlap"]))
before = len({r["address"] for r in wanted})
wanted = [r for r in wanted if best_overlap[r["address"]] <= MAX_OVERLAP]
seen = set()
wanted = [r for r in wanted if not (r["address"] in seen or seen.add(r["address"]))]
print(f"skipped {before - len(wanted)} addresses whose name matches another record there better")
if "--count" in sys.argv:
    refs = collections.Counter(min(int(r["references"]), 5) for r in wanted)
    print(f"candidates: {len(wanted)}; by references (5 = 5+): {sorted(refs.items())}; blocks: {len({r['block'] for r in wanted})}")
    sys.exit(0)
lines = open(cpp, errors="replace").read().split("\n")
function_at, current = [], ""
for line in lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append(current)
index = collections.defaultdict(list)
labels = {r["label"] for r in wanted if r["label"]}
pattern = re.compile(r"\b(" + "|".join(map(re.escape, sorted(labels, key=len, reverse=True))) + r")\b")
for i, line in enumerate(lines):
    s = line.strip()
    if s.startswith(("//", "/*", "*")):
        continue
    for m in pattern.finditer(line):
        if len(index[m.group(1)]) < 4:
            index[m.group(1)].append(f"{function_at[i]}: {s[:150]}")
addresses = sorted({r["address"] for r in wanted})
census = {}
for k in range(0, len(addresses), 60):
    chunk = addresses[k:k + 60]
    out = subprocess.run([sys.executable, os.path.join(HERE, "width_census.py"), alldis, *chunk], capture_output=True,
                         text=True)
    for line in out.stdout.splitlines():
        m = re.match(r"(0x[0-9a-f]+): (.*)", line)
        if m:
            census[int(m.group(1), 16)] = m.group(2)


def region(address):
    a = int(address, 16)
    if 0x3fd482 <= a <= 0x3feec1:
        return "EEPROM mirror (name ends _cal)"
    if a < 0x3f0000:
        return "flash / ROM constant (no _cal)"
    if 0x3f9800 <= a < 0x3fdb30:
        return "RAM in the ROM-to-RAM copy window (ROM-copied constant or reused working RAM; no _cal)"
    return "RAM (working value or ROM-copied constant; no _cal)"


records = []
for r in wanted:
    block_named = [(x["offset"], x["record"], x["row_name"], x["token_overlap"]) for x in by_block[r["block"]]
                   if x["status"] == "named"][:14]
    records.append({
        "address": r["address"], "block": r["block"], "offset": r["offset"], "record": r["record"], "unit": r["unit"],
        "size_bytes": r["size"], "signed": r["signed"], "scale": r["scale"], "min": r["min"], "max": r["max"],
        "description": r["description"], "region": region(r["address"]), "current_row": r["status"],
        "current_row_type": r["row_type"], "label_in_cpp": r["label"], "references": int(r["references"]),
        "dump_raw": r["dump_raw"], "token_overlap": float(r["token_overlap"]), "access_widths": census.get(int(r["address"], 16), "?"),
        "code": index.get(r["label"], []), "block_named_rows": block_named,
        "other_records_at_this_address": [x["record"] for x in rows if x["address"] == r["address"] and x is not r],
        "current_comment": comments.get(int(r["address"], 16), "")[:700],
    })
groups = collections.defaultdict(list)
for rec in records:
    groups[rec["block"]].append(rec)
order = sorted(groups.values(), key=len, reverse=True)
bins_list = [[] for _ in range(bins)]
for group in order:
    min(bins_list, key=len).extend(group)
os.makedirs(out_dir, exist_ok=True)
for k, b in enumerate(bins_list, 1):
    json.dump(sorted(b, key=lambda x: (x["block"], x["offset"])), open(os.path.join(out_dir, f"bin{k}.json"), "w"),
              indent=1)
print(f"{len(records)} records in {bins} bins: {[len(b) for b in bins_list]}")
