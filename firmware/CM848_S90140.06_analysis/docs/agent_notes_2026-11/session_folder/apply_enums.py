"""Gate and apply enum_member / enum_type renames. Usage: apply_enums.py <output_dir> <mapping_out.csv> [--apply] <results...>
enums.csv columns: enum_name,value,member_name,comment,size. A type rename also rewrites type columns that name it."""
import csv
import json
import re
import sys

OUT, MAP = sys.argv[1], sys.argv[2]
APPLY = "--apply" in sys.argv
FILES = [a for a in sys.argv[3:] if not a.startswith("--")]
recs = [json.loads(l) for f in FILES for l in open(f) if l.strip()]
members = [r for r in recs if r.get("kind") == "enum_member" and r.get("new") and r.get("new") != r.get("old")]
types = [r for r in recs if r.get("kind") == "enum_type" and r.get("new") and r.get("new") != r.get("old")]
path = f"{OUT}/enums.csv"
lines = open(path).read().split("\n")
rows = [(i, l.split(",", 4)) for i, l in enumerate(lines) if l and not l.startswith("#") and "," in l]
existing_members = {p[2] for _, p in rows if len(p) > 2}
existing_types = {p[0] for _, p in rows}
problems, mapping = [], []
seen = set()
for r in members:
    hits = [i for i, p in rows if p[0] == r["enum"] and len(p) > 2 and p[2] == r["old"]]
    if len(hits) != 1:
        problems.append(f"member {r['enum']}.{r['old']}: {len(hits)} rows")
    if not re.fullmatch(r"[A-Z][A-Z0-9]*(_[A-Z0-9]+)*", r["new"]):
        problems.append(f"member {r['new']}: not UPPER_SNAKE")
    if r["new"] in existing_members or r["new"] in seen:
        problems.append(f"member {r['new']}: already used")
    seen.add(r["new"])
for r in types:
    if r["old"] not in existing_types:
        problems.append(f"type {r['old']}: not in enums.csv")
    if r["new"] in existing_types:
        problems.append(f"type {r['new']}: already used")
print(f"enum members {len(members)}, enum types {len(types)}")
for p in problems:
    print("PROBLEM", p)
if APPLY and not problems:
    for r in members:
        for i, p in rows:
            if p[0] == r["enum"] and p[2] == r["old"]:
                p[2] = r["new"]
                lines[i] = ",".join(p)
        mapping.append(("", r["new"], r["old"], "token"))
    for r in types:
        for i, p in rows:
            if p[0] == r["old"]:
                p[0] = r["new"]
                lines[i] = ",".join(p)
        mapping.append(("", r["new"], r["old"], "token"))
        for name, col, split in (("global_variables.csv", 2, 3), ("structure_definitions.csv", 3, None),
                                 ("function_definitions.csv", 4, None), ("local_variables.csv", 4, None)):
            fp = f"{OUT}/{name}"
            fl = open(fp).read().split("\n")
            n = 0
            for i, l in enumerate(fl):
                if not l or l.startswith("#"):
                    continue
                if split is not None:
                    p = l.split(",", split)
                    if len(p) > col and re.fullmatch(rf"{re.escape(r['old'])}(\[\d+\])?", p[col]):
                        p[col] = r["new"] + p[col][len(r["old"]):]
                        fl[i] = ",".join(p)
                        n += 1
                else:
                    new_l = re.sub(rf"(?<=,){re.escape(r['old'])}(?=(\[\d+\])?,)", r["new"], l)
                    if new_l != l:
                        fl[i] = new_l
                        n += 1
            open(fp, "w").write("\n".join(fl))
            print(f"{name}: {n} type references")
    open(path, "w").write("\n".join(lines))
    with open(MAP, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "old_label", "kind"])
        w.writerows(mapping)
    print("applied")
