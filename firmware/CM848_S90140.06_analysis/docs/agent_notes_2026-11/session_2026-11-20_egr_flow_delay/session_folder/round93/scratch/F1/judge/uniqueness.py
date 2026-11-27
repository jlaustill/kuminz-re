"""Judge F1: every proposed name against the FROZEN and the LIVE CSVs of both firmwares (functions, globals, enum
members, struct fields) - a holder other than the element's own row is printed."""
import csv
import json
import re
import sys

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware"
SETS = {
    "frozen": {"CM550": f"{R}/frozen/cm550", "CM848": f"{R}/frozen/cm848"},
    "live": {"CM550": f"{REPO}/CM550_J90350.00_analysis/output", "CM848": f"{REPO}/CM848_S90140.06_analysis/output"},
}
d = json.load(open(f"{R}/scratch/F1/investigator/result_f1.json"))
extra = sys.argv[1:]          # more names to test (judge amendments): name=kind@address


def holders(folder):
    h = {}
    for line in open(f"{folder}/function_renames.csv", newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if p[0].startswith("0x") and len(p) > 1:
            h.setdefault(p[1], []).append(("function", int(p[0], 16)))
    for line in open(f"{folder}/global_variables.csv", newline=""):
        p = line.rstrip("\r\n").split(",", 3)
        if p[0].startswith("0x") and len(p) > 1 and p[1]:
            h.setdefault(p[1], []).append(("global", int(p[0], 16)))
    for row in csv.reader(open(f"{folder}/enums.csv", newline="")):
        if row and not row[0].startswith("#") and len(row) > 2:
            h.setdefault(row[2], []).append(("enum " + row[0], int(row[1], 0) if re.match(r"^(0x)?[0-9a-fA-F]+$", row[1]) else -1))
    for row in csv.reader(open(f"{folder}/structure_definitions.csv", newline="")):
        if row and not row[0].startswith("#") and len(row) > 2 and row[2]:
            h.setdefault(row[2], []).append(("field of " + row[0], -1))
    return h


H = {s: {fw: holders(p) for fw, p in v.items()} for s, v in SETS.items()}
tests = []
for f in d["functions"]:
    tests.append((f["proposed_name"], "function", int(f["address"], 16), "CM550"))
    if f["relation"] == "twin":
        tests.append((f["proposed_name"], "function", int(f["cm848_address"], 16), "CM848"))
for g in d["globals"]:
    tests.append((g["proposed_name"], "global", int(g["address"], 16), "CM550"))
for e in d["enum_members"]:
    for fw in (("CM550", "CM848") if e["firmware"] == "both" else (e["firmware"],)):
        tests.append((e["proposed_member"], "enum FUELING_STATE", int(e["value"]), fw))
for x in extra:
    name, rest = x.split("=")
    kind, at = rest.split("@")
    fw, a = at.split(":")
    tests.append((name, kind, int(a, 0), fw))
seen = {}
for name, kind, a, fw in tests:
    seen.setdefault((fw, name), []).append((kind, a))
for (fw, name), uses in seen.items():
    if len(uses) > 1:
        print(f"!! proposed more than once in {fw}: {name} {uses}")
for name, kind, a, fw in tests:
    for s in SETS:
        others = [h for h in H[s][fw].get(name, []) if h != (kind, a)]
        if others:
            print(f"!! {s} {fw}: {name} ({kind} 0x{a:x}) is also held by {others}")
        own = (kind, a) in H[s][fw].get(name, [])
        if own:
            print(f"   {s} {fw}: {name} already on its own row ({kind} 0x{a:x})")
print(f"{len(tests)} names tested")
