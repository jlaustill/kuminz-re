"""Round 97 stage B: apply enum_spelling_plan_r97.csv.
1. enums.csv of each firmware: the enum name (column 1) and the member name (column 3) of each planned row; comment
   lines ('# ...') and member comments are rewritten only through step 3.
2. Every other CSV of the firmware: an enum type in a type column is renamed (word-bounded; types are distinctive).
3. Comments, plates and the current-state docs (firmware/CLAUDE.md, each firmware's docs/*.md): the type names and the
   distinctive member names (two or more words, not a global / function name in either firmware) are rewritten,
   word-bounded; a line with a history note for the old name ('was <old>' / 'were <old>' / 'removed <old>' / 'old <old>')
   is held and reported.
Writes map_r97b_<fw>.csv for the proofs. Keeps line endings. usage: apply_enum_spelling_r97.py <repo> <plan.csv>"""
import collections
import csv
import glob
import io
import os
import re
import sys

repo, plan_path = os.path.abspath(sys.argv[1]), sys.argv[2]
HERE = os.path.dirname(os.path.abspath(__file__))
FW = {"CM550": "firmware/CM550_J90350.00_analysis", "CM848": "firmware/CM848_S90140.06_analysis"}
plan = collections.defaultdict(list)
for r in csv.DictReader(open(plan_path)):
    plan[r["firmware"]].append(r)
symbols = set()
for d in FW.values():
    for f in ("global_variables.csv", "function_renames.csv"):
        for line in open(os.path.join(repo, d, "output", f), newline=""):
            p = line.rstrip("\r\n").split(",", 2)
            if len(p) > 1 and p[0].startswith("0x"):
                symbols.add(p[1])
changes = collections.Counter()
held = []


def read(p):
    t = open(p, newline="").read()
    return t, ("\r\n" if "\r\n" in t else "\n")


def rewrite(p, mapping):
    if not mapping:
        return
    pat = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(mapping, key=len, reverse=True))) + r")(?![A-Za-z0-9_])")
    t, E = read(p)
    if not pat.search(t):
        return
    lines = t.split(E)
    n = 0
    for i, l in enumerate(lines):
        if not pat.search(l):
            continue
        if any(re.search(r"\b(was|were|removed|old)\b[^;)|]{0,80}(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(o), l) for o in mapping):
            held.append(f"{os.path.relpath(p, repo)}:{i + 1}")
            continue
        n += len(pat.findall(l))
        lines[i] = pat.sub(lambda m: mapping[m.group(1)], l)
    if n:
        open(p, "w", newline="").write(E.join(lines))
        changes[os.path.relpath(p, repo)] += n


for fw, rows in plan.items():
    out = os.path.join(repo, FW[fw], "output")
    types = {r["old"]: r["new"] for r in rows if r["kind"] == "type"}
    members = {(r["enum"], r["old"]): r["new"] for r in rows if r["kind"] == "member"}
    # 1. enums.csv name columns
    p = os.path.join(out, "enums.csv")
    t, E = read(p)
    lines = t.split(E)
    n = 0
    for i, line in enumerate(lines):
        if not line or line.startswith("#"):
            continue
        cells = line.split(",", 3)
        if len(cells) < 3:
            continue
        enum, member = cells[0], cells[2]
        new_member = members.get((enum, member), member)
        new_enum = types.get(enum, enum)
        if (new_enum, new_member) != (enum, member):
            cells[0], cells[2] = new_enum, new_member
            lines[i] = ",".join(cells)
            n += 1
    open(p, "w", newline="").write(E.join(lines))
    changes[os.path.relpath(p, repo)] += n
    # 2. + 3. types everywhere; distinctive members in free text
    distinctive = {r["old"]: r["new"] for r in rows if r["kind"] == "member" and "_" in r["old"] and r["old"] not in symbols}
    for f in glob.glob(os.path.join(out, "*.csv")):
        rewrite(f, types)
        rewrite(f, distinctive)
    docs = glob.glob(os.path.join(repo, FW[fw], "docs", "*.md")) + [os.path.join(repo, "firmware/CLAUDE.md")]
    for d in docs:
        rewrite(d, types)
        rewrite(d, distinctive)
    with open(os.path.join(HERE, f"map_r97b_{fw.lower()}.csv"), "w") as f:
        f.write("address,name,old_label,kind,dims\n")
        for o, nw in types.items():
            f.write(f"0x00000000,{nw},{o},type,1\n")
        seen = set()
        for r in rows:
            if r["kind"] == "member" and r["old"] not in seen:
                f.write(f"0x00000000,{r['new']},{r['old']},enum,1\n")
                seen.add(r["old"])
for k, n in sorted(changes.items()):
    print(f"{k}: {n}")
for h in held:
    print("HELD (history note):", h)
