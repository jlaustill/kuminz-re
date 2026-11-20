"""Wave 14: complete the global worklist so no family ends half-renamed.
- Ranges: every "0xAAAAAA-0xBBBBBB" / "0xAAAAAA..BB" a wave-13 report quotes adds all named rows inside it.
- Stems: a worklist row whose name ends in a family index (`cylinder1_...`, `..._channel_a`, `..._b_cal`, a trailing
  number) adds the rows within 0x40 bytes whose name has the same stem.
Rows that wave 13 / 8b / 8c reviewed or renamed, or that are excluded, are skipped; added rows must be used in the .cpp.
usage: expand_worklist.py <worklist.json> <global_variables.csv> <.cpp> <audit.csv> <stage8 dir> <out.json> [exclude...]"""
import csv
import glob
import json
import os
import re
import sys

work_path, gv_path, cpp_path, audit_path, stage8, out_path = sys.argv[1:7]
exclude = {int(a, 16) for a in sys.argv[7:]}
work = json.load(open(work_path))
rows = {}
for line in open(gv_path, errors="replace"):
    if line.startswith("0x"):
        address, name, typ = (line.rstrip("\n").split(",", 3) + ["", ""])[:3]
        if name and "+" not in name:
            rows[int(address, 16)] = (name, typ)
reviewed = {int(i["address"], 16) for p in glob.glob(os.path.join(stage8, "bins", "bin*.json")) for i in json.load(open(p))}
renamed = {int(r["address"], 16) for n in ("map_stage8.csv", "map_stage8b.csv", "map_stage8c.csv")
           for r in csv.DictReader(open(os.path.join(stage8, n)))}
audit = {}
for r in csv.DictReader(open(audit_path)):
    audit.setdefault(int(r["address"], 16), r)
cpp = open(cpp_path, errors="replace").read()
have = {int(w["address"], 16) for w in work}


def used(name):
    return re.search(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", cpp) is not None


def add(a, why):
    if a in rows and a not in have and a not in reviewed and a not in renamed and a not in exclude and used(rows[a][0]):
        have.add(a)
        r = dict(audit.get(a, {}))
        r.update({"address": f"0x{a:08x}", "row_name": rows[a][0], "row_type": rows[a][1], "added_by": why})
        work.append(r)
        return 1
    return 0


ranges = 0
for report in sorted(glob.glob(os.path.join(stage8, "reports", "*.md"))):
    for m in re.finditer(r"0x([0-9a-fA-F]{5,8})\s*(?:-|\.\.|–)\s*(?:0x)?([0-9a-fA-F]{2,8})\b", open(report).read()):
        start, end_text = m.group(1), m.group(2)
        end = start[:len(start) - len(end_text)] + end_text if len(end_text) < len(start) else end_text
        s, e = int(start, 16), int(end, 16)
        if 0 < e - s <= 0x80:
            for a in range(s, e + 1):
                ranges += add(a, f"range {m.group(0)} in {os.path.basename(report)}")
STEM = [(re.compile(r"^(.*?)\d+(_.*)?$"), lambda m: re.escape(m.group(1)) + r"\d+" + re.escape(m.group(2) or "") + "$"),
        (re.compile(r"^(.*_)[a-e](_cal)?$"), lambda m: re.escape(m.group(1)) + r"[a-h]" + re.escape(m.group(2) or "") + "$"),
        (re.compile(r"^(.*_)[a-e](_[a-z_]+)$"), lambda m: re.escape(m.group(1)) + r"[a-h]" + re.escape(m.group(2)) + "$")]
stems = 0
for w in list(work):
    name, a = w["row_name"], int(w["address"], 16)
    for pattern, build in STEM:
        m = pattern.match(name)
        if m:
            family = re.compile(build(m))
            for b in range(a - 0x40, a + 0x41):
                if b in rows and family.match(rows[b][0]):
                    stems += add(b, f"family stem of {name}")
            break
json.dump(work, open(out_path, "w"), indent=1)
print(f"added {ranges} from report ranges and {stems} from family stems; {len(work)} rows in all")
