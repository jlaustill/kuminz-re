"""Stage 7 pre-pass: per-record context for the e2m naming agents, binned by block.
Reads the audit (e2m_name_audit.py output), keeps the scalar records whose address has no name yet but is used in the
.cpp and whose dump value is in the record's range, and adds: the region (and so `_cal`), the access widths
(width_census.py), up to 4 code lines that use the label, and the block's already-named rows (offset, record, name,
overlap) so an agent sees the naming conventions and any layout drift.
usage: build_context.py <audit.csv> <out dir> <bins>"""
import collections
import csv
import json
import os
import re
import subprocess
import sys

audit, out_dir, bins = sys.argv[1], sys.argv[2], int(sys.argv[3])
T = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state"
CPP = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
       "cm848_rom.ghidra.cpp")
rows = list(csv.DictReader(open(audit)))
by_block = collections.defaultdict(list)
for r in rows:
    by_block[r["block"]].append(r)
wanted = [r for r in rows if r["status"] in ("none", "unnamed") and int(r["references"]) > 0 and r["dump_in_range"] == "yes"]
lines = open(CPP, errors="replace").read().split("\n")
function_at, current = [], ""
for line in lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append(current)
index = collections.defaultdict(list)
labels = {r["label"] for r in wanted}
pattern = re.compile(r"\b(" + "|".join(map(re.escape, labels)) + r")\b")
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
    out = subprocess.run([sys.executable, f"{T}/width_census.py", f"{T}/all.dis", *chunk], capture_output=True, text=True)
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
        "dump_raw": r["dump_raw"], "access_widths": census.get(int(r["address"], 16), "?"),
        "code": index.get(r["label"], []), "block_named_rows": block_named,
        "other_records_at_this_address": [x["record"] for x in rows if x["address"] == r["address"] and x is not r],
    })
# bin by block, largest blocks first, greedy balance
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
print(f"{len(records)} records in {bins} bins: {[len(b) for b in bins_list]}; "
      f"skipped out of range: {sum(1 for r in rows if r['status'] in ('none', 'unnamed') and int(r['references']) > 0 and r['dump_in_range'] != 'yes')}")
