"""Round 97 stage A (both firmwares; from round 96's stage H script, struct types left out): parameter, local, struct field and struct type names spell their words out (the
naming rule: no invented abbreviations; register mnemonics from the manuals and the allowed industry abbreviations
stay).
1. Struct types (11): a word-boundary rename over every CSV column of both firmwares' output folders and the
   current-state docs (firmware/CLAUDE.md, the CM848 / CM550 docs), as in stage C.
2. Parameters / locals / fields (abbreviation_renames_r96.csv): the name column of function_definitions.csv
   (param rows), local_variables.csv (new_name) and structure_definitions.csv (field_name), plus dotted documentation
   names in global_variables.csv ('instance.old_field' where the instance's type has the renamed field).
3. Comments and docs: only the distinctive old tokens (every old name except msg / hi / lo, which also occur as
   ordinary text) are rewritten, word-bounded.
A line that holds a history note for an old name ('was <old>') is left alone and reported. Refuses (writes nothing)
when a new type name already exists. Writes map_r96h_cm550.csv / map_r96h_cm848.csv for the proofs.
Idempotent; keeps line endings. usage: spell_names_stage_h_r96.py <repo> <abbreviation_renames_r96.csv>"""
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
TYPES = {"CM550": {}, "CM848": {}}          # round 97 stage A: the struct types wait until after the workflow apply
GENERIC = {"msg", "hi", "lo"}
# a token that is also a global / function name in either firmware must not be rewritten in free text
for fw in FW.values():
    for f in ("global_variables.csv", "function_renames.csv"):
        for line in open(os.path.join(repo, fw, "output", f), newline=""):
            p = line.rstrip("\r\n").split(",", 2)
            if len(p) > 1 and p[0].startswith("0x"):
                GENERIC.add(p[1])
plan = collections.defaultdict(list)
for r in csv.DictReader(open(plan_path)):
    plan[r["firmware"]].append(r)


def read(p):
    t = open(p, newline="").read()
    return t, ("\r\n" if "\r\n" in t else "\n")


# refuse on a type clash
for fw, m in TYPES.items():
    text = open(os.path.join(repo, FW[fw], "output", "structure_definitions.csv"), newline="").read()
    for new in m.values():
        if re.search(rf"(?m)^{re.escape(new)},", text):
            sys.exit(f"REFUSED: type {new} already exists in {fw}")

changes = collections.Counter()
held = []


def rewrite_text(p, mapping):
    """word-bounded token rewrite of a whole file, history-note lines held"""
    if not mapping:
        return
    pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(mapping, key=len, reverse=True))) + r")(?![A-Za-z0-9_])")
    t, E = read(p)
    if not pattern.search(t):
        return
    lines = t.split(E)
    n = 0
    for i, l in enumerate(lines):
        if not pattern.search(l):
            continue
        if any(re.search(rf"\bwas `?{re.escape(old)}\b", l) for old in mapping):
            held.append(f"{os.path.relpath(p, repo)}:{i + 1}")
            continue
        n += len(pattern.findall(l))
        lines[i] = pattern.sub(lambda m: mapping[m.group(1)], l)
    if n:
        open(p, "w", newline="").write(E.join(lines))
        changes[os.path.relpath(p, repo)] += n


# 2. the name columns
for fw, rows in plan.items():
    out = os.path.join(repo, FW[fw], "output")
    by_file = collections.defaultdict(dict)
    for r in rows:
        by_file[r["file"]][(r["owner"], r["old"])] = r["new"]
    for f, col in (("function_definitions.csv", 3), ("local_variables.csv", 3), ("structure_definitions.csv", 2)):
        m = by_file.get(f)
        if not m:
            continue
        p = os.path.join(out, f)
        t, E = read(p)
        lines = t.split(E)
        n = 0
        for i, line in enumerate(lines):
            if not line or line.startswith("#"):
                continue
            cells = next(csv.reader([line]))
            if len(cells) <= col or (cells[0], cells[col]) not in m:
                continue
            # rebuild the line by replacing exactly the cell at col (cells before it hold no quotes in these files)
            head = line.split(",", col)
            assert head[col].startswith(cells[col] + ",") or head[col] == cells[col], (p, i + 1, line[:80])
            head[col] = m[(cells[0], cells[col])] + head[col][len(cells[col]):]
            lines[i] = ",".join(head)
            n += 1
        open(p, "w", newline="").write(E.join(lines))
        changes[os.path.relpath(p, repo)] += n
    # dotted documentation names in global_variables.csv: instance.old_field -> instance.new_field
    field_map = {(r["owner"], r["old"]): r["new"] for r in rows if r["file"] == "structure_definitions.csv"}
    gp = os.path.join(out, "global_variables.csv")
    t, E = read(gp)
    lines = t.split(E)
    instance_type = {}
    for line in lines:
        p = line.split(",", 3)
        if len(p) > 2 and p[0].startswith("0x") and p[1] and "." not in p[1]:
            instance_type[p[1]] = re.sub(r"\[\d+\]$", "", p[2].strip())
    n = 0
    for i, line in enumerate(lines):
        p = line.split(",", 3)
        if len(p) > 2 and p[0].startswith("0x") and "." in p[1]:
            inst, _, field = p[1].partition(".")
            base = re.sub(r"\[\d+\]$", "", inst)
            key = (instance_type.get(base, ""), re.sub(r"\[\d+\]$", "", field.split(".")[0]))
            if key in field_map:
                p[1] = inst + "." + field.replace(key[1], field_map[key], 1)
                lines[i] = ",".join(p)
                n += 1
    open(gp, "w", newline="").write(E.join(lines))
    changes[os.path.relpath(gp, repo)] += n

# 1. + 3. types everywhere, distinctive old names in comments / docs (both firmwares' files: shared docs mention both)
docs = [os.path.join(repo, "firmware/CLAUDE.md")]
for fw in FW.values():
    docs += glob.glob(os.path.join(repo, fw, "docs", "*.md"))
for fw in FW:
    files = glob.glob(os.path.join(repo, FW[fw], "output", "*.csv"))
    rewrite_text_map = dict(TYPES[fw])
    for f in files:
        rewrite_text(f, rewrite_text_map)
    tokens = {r["old"]: r["new"] for r in plan[fw] if r["old"] not in GENERIC}
    # an old token that maps to two different new names in one firmware is ambiguous in free text: skip it
    seen = collections.defaultdict(set)
    for r in plan[fw]:
        seen[r["old"]].add(r["new"])
    tokens = {k: v for k, v in tokens.items() if len(seen[k]) == 1}
    for f in files:
        rewrite_text(f, tokens)
all_types = {**TYPES["CM550"], **TYPES["CM848"]}
for d in docs:
    rewrite_text(d, all_types)
cm848_tokens = {r["old"]: r["new"] for r in plan["CM848"] if r["old"] not in GENERIC}
for d in [x for x in docs if "CM848" in x or x.endswith("firmware/CLAUDE.md")]:
    rewrite_text(d, cm848_tokens)
cm550_tokens = {r["old"]: r["new"] for r in plan["CM550"] if r["old"] not in GENERIC}
for d in [x for x in docs if "CM550" in x]:
    rewrite_text(d, cm550_tokens)
for k, n in sorted(changes.items()):
    print(f"{k}: {n}")
for h in held:
    print("HELD (history note):", h)
for fw in FW:
    with open(os.path.join(HERE, f"map_r97a_{fw.lower()}.csv"), "w") as f:
        f.write("address,name,old_label,kind,dims\n")
        for old, new in TYPES[fw].items():
            f.write(f"0x00000000,{new},{old},type,1\n")
        done = set()
        for r in plan[fw]:
            if r["old"] not in done:
                f.write(f"0x00000000,{r['new']},{r['old']},local,1\n")
                done.add(r["old"])
