"""Check every identifier the draft output mentions (prefixed function names, snake_case globals) against the names
that exist (frozen / live CSVs of both firmwares) or that the draft proposes - catches a plate comment that names a
function under a name nobody has. Read-only helper, round 93 batch D1 investigator, session 2.
usage: check_refs.py"""
import csv
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/"
R = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/"
d = json.load(open(os.path.join(HERE, "draft_output.json")))

known = set()
for path in (F + "cm550/function_renames.csv", F + "cm848/function_renames.csv",
             F + "cm550/global_variables.csv", F + "cm848/global_variables.csv",
             R + "CM550_J90350.00_analysis/output/function_renames.csv",
             R + "CM848_S90140.06_analysis/output/function_renames.csv",
             R + "CM550_J90350.00_analysis/output/global_variables.csv",
             R + "CM848_S90140.06_analysis/output/global_variables.csv"):
    for row in csv.reader(open(path, errors="replace")):
        if len(row) >= 2 and not row[0].startswith("#"):
            known.add(row[1].strip())
for path in (F + "cm550/structure_definitions.csv", F + "cm848/structure_definitions.csv"):
    for row in csv.reader(open(path, errors="replace")):
        if row and not row[0].startswith("#"):
            known.add(row[0].strip())
            if len(row) > 2:
                known.add(row[2].strip())
for path in (F + "cm550/enums.csv", F + "cm848/enums.csv"):
    for row in csv.reader(open(path, errors="replace")):
        if len(row) >= 3 and not row[0].startswith("#"):
            known.add(row[0].strip())
            known.add(row[2].strip())
proposed = {f["proposed_name"] for f in d["functions"]} | {g["proposed_name"] for g in d["globals"]}
proposed |= {m["proposed_member"] for m in d["enum_members"]} | {m["enum_name"] for m in d["enum_members"]}
proposed |= {"table_lookup_2d_arguments_t"}

texts = []
for f in d["functions"]:
    for k in ("role", "discriminator", "plate_comment", "evidence"):
        texts.append((f["address"] + " " + k, f[k]))
for s in d["skipped"]:
    texts.append((s["address"] + " reason", s["reason"]))
for g in d["globals"]:
    for k in ("comment", "evidence"):
        texts.append((g["address"] + " " + k, g[k]))
for m in d["enum_members"]:
    for k in ("comment", "evidence"):
        texts.append((m["proposed_member"] + " " + k, m[k]))
texts.append(("summary", d["summary"]))
texts.append(("notes", d["notes"]))

pat_fn = re.compile(r"\b(?:cm550|mc68k|vp44|cm848|hpcr|mpc555)_[A-Za-z0-9_]+\b")
pat_camel = re.compile(r"\b[a-z]+(?:[A-Z][a-z0-9]+){2,}\b")
pat_snake = re.compile(r"\b[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}\b")
unknown = {}
for where, text in texts:
    for pat in (pat_fn, pat_camel, pat_snake):
        for name in pat.findall(text):
            if name in known or name in proposed:
                continue
            unknown.setdefault(name, []).append(where)
for name, wheres in sorted(unknown.items()):
    print(f"{name}: {sorted(set(wheres))[:4]}")
print("unknown identifiers:", len(unknown))
# old names that should no longer appear in plate comments (the proposals replace them)
renamed = {f["current_name"]: f["proposed_name"] for f in d["functions"] if f["current_name"] != f["proposed_name"]}
for f in d["functions"]:
    for old in renamed:
        if re.search(r"\b" + re.escape(old) + r"\b", f["plate_comment"]):
            print("OLD NAME in plate comment of", f["address"], ":", old)
