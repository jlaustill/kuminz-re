import csv
import json
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
RN = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/"

glob = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        glob[r[1]] = r
func = {}
for r in csv.reader(open(OUT + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        func[r[1]] = r
fields = set()
for r in csv.reader(open(OUT + "structure_definitions.csv")):
    if r and len(r) > 2 and not r[0].startswith("#") and r[0] != "struct_name":
        fields.add(r[2])

text = []
for fn in ["aligned_W5_combustion_rom.jsonl", "aligned_W5_combustion_flash2.jsonl"]:
    for line in open(RN + fn):
        line = line.strip()
        if not line:
            continue
        o = json.loads(line)
        if o.get("kind") == "note" or o.get("verdict") == "uncertain":
            text.append(json.dumps(o))
blob = "\n".join(text)
ids = sorted(set(re.findall(r"[A-Za-z_][A-Za-z0-9_]{5,}", blob)))
print("identifiers in the leads that STILL exist as a current name:")
for i in ids:
    if i in glob:
        r = glob[i]
        print("  G", r[0], i, r[2])
    elif i in func:
        r = func[i]
        print("  F", r[0], i)
print("identifiers that are struct field names:")
for i in ids:
    if i in fields and i not in glob and i not in func:
        print("  S", i)
