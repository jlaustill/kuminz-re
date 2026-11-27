"""Round 24: struct type / field renames and the instance's dotted alias rows (label-only), driven by a spec file.
The instance rows themselves are renamed by apply_hand_worklist.py (as globals) BEFORE this runs.
spec.py defines:
  TYPES = {old_type: new_type}
  INSTANCES = {old_instance_label: (address, new_instance, old_type)}
  FIELDS = {old_type: {old_field: (new_field, comment)}}      comment -> '<comment> (was <old>) | earlier note: <old>'
  FIELD_NOTES = {old_type: {field: text}}                        appended to a kept field's comment as ' | <text>'
What it changes:
- structure_definitions.csv: struct_name, field names and comments, the field type / dependency columns (type tokens),
  every comment (qualified references, type and instance tokens, unique bare old field tokens).
- global_variables.csv: the type column (type tokens); dotted alias rows '<old or new instance>.<x>' -> '<new
  instance>.<field at that offset>'; comments (qualified references, type tokens).
- function_definitions.csv / local_variables.csv / arrays.csv: type columns (type tokens).
- comments of function_renames / enums / labels / constants / arrays / deleted_functions and firmware/CLAUDE.md:
  qualified references and type tokens (refresh_references.py does the bare global / function / field tokens with
  the refresh map).
Checks: new type names free; new field names not a field of any struct and no .cpp identifier; an old field name that
another struct also has, or that the .cpp uses outside a field access, is generic (qualified refreshes only).
Appends type / field rows to <map.csv>; writes <refresh_map.csv> = the whole map without the generic field rows.
usage: apply_struct_renames.py <repo> <spec.py> <map.csv> <refresh_map.csv> [--dry-run]"""
import csv
import io
import os
import re
import runpy
import sys

repo, spec_path, map_path, refresh_path = sys.argv[1:5]
repo = os.path.abspath(repo)
dry = "--dry-run" in sys.argv
spec = runpy.run_path(spec_path)
TYPES, INSTANCES, FIELDS = spec["TYPES"], spec["INSTANCES"], spec["FIELDS"]
FIELD_NOTES = spec.get("FIELD_NOTES", {})
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
CPP = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
CODE = re.sub(r"//[^\n]*", " ", re.sub(r"/\*.*?\*/", " ", CPP, flags=re.S))
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
problems = []


def word(n):
    return re.compile(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])")


def read_csv_row(line):
    return next(csv.reader([line]))


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


# --- the struct layouts (offsets as ApplyStructures places them: running offset, size 0 = bitfield continuation) ---
sd_path = os.path.join(out, "structure_definitions.csv")
sd_lines = open(sd_path).read().split("\n")
layout, all_fields = {}, {}
for line in sd_lines:
    if not line or line.startswith("#") or line.startswith("struct_name,"):
        continue
    row = read_csv_row(line)
    if len(row) < 5 or not row[2]:
        continue
    t = row[0]
    off = layout.setdefault(t, {"next": 0, "fields": []})
    size = int(row[4] or 0)
    start = off["next"] if size else (off["fields"][-1][0] if off["fields"] else 0)
    off["fields"].append((start, row[2]))
    off["next"] += size
    all_fields.setdefault(row[2], set()).add(t)

# --- checks -------------------------------------------------------------------------------------------------------
for t, nt in TYPES.items():
    if t not in layout:
        problems.append(f"type {t} has no rows")
    if word(nt).search(CPP) or nt in layout:
        problems.append(f"type name {nt} is taken")
generic = set()
for t, fmap in FIELDS.items():
    news = [v[0] for v in fmap.values()]
    if len(set(news)) != len(news):
        problems.append(f"{t}: duplicate new field names")
    kept = {f for _, f in layout[t]["fields"]} - set(fmap)
    for old, (new, _) in fmap.items():
        if old not in {f for _, f in layout[t]["fields"]}:
            problems.append(f"{t}.{old}: no such field")
        if new in all_fields or word(new).search(CODE) or new in kept:
            problems.append(f"{t}.{new}: the name is taken ({sorted(all_fields.get(new, []))})")
        bare = [m for m in word(old).finditer(CODE)
                if not re.search(r"(\.|->)\s*$", CODE[max(0, m.start() - 3):m.start()])]
        if all_fields[old] - {t} or bare or "_" not in old:   # a plain word ('calculated') also reads as prose
            generic.add(old)
print("generic (qualified refresh only):", ", ".join(sorted(generic)) or "none")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)

# --- the comment refresh ---------------------------------------------------------------------------------------------
qualified = []      # (pattern, replacement)
for t, fmap in FIELDS.items():
    nt = TYPES.get(t, t)
    owners = [t, nt] + [x for oi, (a, ni, ot) in INSTANCES.items() if ot == t for x in (oi, ni)]
    news_of = {oi: ni for oi, (a, ni, ot) in INSTANCES.items() if ot == t}
    for old, (new, _) in fmap.items():
        for owner in owners:
            target = nt if owner in (t, nt) else news_of.get(owner, owner)
            qualified.append((re.compile(r"(?<![A-Za-z0-9_])" + re.escape(owner) + r"\." + re.escape(old) +
                                         r"(?![A-Za-z0-9_])"), f"{target}.{new}"))
        if old not in generic:
            qualified.append((re.compile(r"->" + re.escape(old) + r"(?![A-Za-z0-9_])"), f"->{new}"))
tokens = dict(TYPES)
tokens.update({oi: ni for oi, (a, ni, ot) in INSTANCES.items()})
for t, fmap in FIELDS.items():
    for old, (new, _) in fmap.items():
        if old not in generic:
            tokens[old] = new


def refresh(text, bare=True):
    for pat, rep in qualified:
        text = pat.sub(rep, text)
    for old, new in sorted(tokens.items(), key=lambda kv: -len(kv[0])):
        if not bare and old not in TYPES and old not in INSTANCES:
            continue

        def sub(m, new=new, text=text):
            return m.group(0) if HISTORY.search(text[max(0, m.start() - 12):m.start()]) else new
        text = word(old).sub(sub, text)
    return text


def retype(text):
    for t, nt in TYPES.items():
        text = word(t).sub(nt, text)
    return text


changes = {}

# --- structure_definitions.csv ------------------------------------------------------------------------------------
new_sd, renamed_fields = [], 0
for line in sd_lines:
    if not line or line.startswith("#") or line.startswith("struct_name,"):
        new_sd.append(refresh(line) if line.startswith("#") else line)
        continue
    row, before = read_csv_row(line), read_csv_row(line)
    if row[0] in TYPES:
        t = row[0]
        if len(row) > 2 and row[2] in FIELDS.get(t, {}):
            new, comment = FIELDS[t][row[2]]
            old_comment = row[5] if len(row) > 5 else ""
            row[5] = f"{comment} (was {row[2]})" + (f" | earlier note: {old_comment}" if old_comment else "")
            row[2] = new
            renamed_fields += 1
        elif len(row) > 5:
            row[5] = refresh(row[5])
            if row[2] in FIELD_NOTES.get(t, {}):
                row[5] = f"{row[5]} | {FIELD_NOTES[t][row[2]]}"
        row[0] = TYPES[t]
    elif len(row) > 5:
        row[5] = refresh(row[5])
    if len(row) > 3:
        row[3] = retype(row[3])
    if len(row) > 6:
        row[6] = retype(row[6])
    new_sd.append(write_csv_row(row) if row != before else line)
changes[sd_path] = new_sd
print(f"structure_definitions.csv: {renamed_fields} fields renamed")

# --- global_variables.csv -------------------------------------------------------------------------------------------
gv_path = os.path.join(out, "global_variables.csv")
gv_lines, new_gv, dotted = open(gv_path).read().split("\n"), [], 0
by_instance = {}
for oi, (a, ni, ot) in INSTANCES.items():
    fmap = FIELDS.get(ot, {})
    offs = {}
    for start, f in layout[ot]["fields"]:
        offs.setdefault(start, fmap.get(f, (f, None))[0])
    by_instance[oi] = by_instance[ni] = (int(a, 16), ni, offs)
for line in gv_lines:
    if not line.startswith("0x"):
        new_gv.append(line)
        continue
    parts = line.split(",", 3)
    while len(parts) < 4:
        parts.append("")
    before = list(parts)
    name = parts[1]
    if "." in name and name.split(".", 1)[0] in by_instance:
        base, new_instance, offs = by_instance[name.split(".", 1)[0]]
        off = int(parts[0], 16) - base
        assert off in offs, (line, off)
        parts[1] = f"{new_instance}.{offs[off]}"
        dotted += 1
    parts[2] = retype(parts[2])
    parts[3] = refresh(parts[3], bare=False)
    new_gv.append(",".join(parts) if parts != before else line)
changes[gv_path] = new_gv
print(f"global_variables.csv: {dotted} dotted alias rows")

# --- type columns and other comment columns -------------------------------------------------------------------------
for name, type_col, comment_col, ncols in [("function_definitions.csv", 4, 5, 6), ("local_variables.csv", 4, 5, 6),
                                           ("arrays.csv", 2, 4, 5), ("function_renames.csv", None, 2, 3),
                                           ("labels.csv", None, 2, 3), ("constants.csv", None, 3, 4),
                                           ("deleted_functions.csv", None, 1, 2)]:
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    new_lines = []
    for line in open(p).read().split("\n"):
        if not line or line.startswith("#"):
            new_lines.append(line)
            continue
        parts = line.split(",", ncols - 1)
        before = list(parts)
        if type_col is not None and len(parts) > type_col:
            parts[type_col] = retype(parts[type_col])
        if len(parts) > comment_col:
            parts[comment_col] = refresh(parts[comment_col], bare=False)
        new_lines.append(",".join(parts) if parts != before else line)
    changes[p] = new_lines
ep = os.path.join(out, "enums.csv")
new_lines = []
for line in open(ep).read().split("\n"):
    if not line or line.startswith("#") or line.startswith("enum_name,"):
        new_lines.append(refresh(line) if line.startswith("#") else line)
        continue
    row, before = read_csv_row(line), read_csv_row(line)
    if len(row) > 3:
        row[3] = refresh(row[3])
    new_lines.append(write_csv_row(row) if row != before else line)
changes[ep] = new_lines
cl = os.path.join(repo, "firmware", "CLAUDE.md")
changes[cl] = [refresh(l, bare=False) for l in open(cl).read().split("\n")]

total = 0
for p, lines in changes.items():
    old = open(p).read().split("\n")
    n = sum(1 for a, b in zip(old, lines) if a != b) + abs(len(old) - len(lines))
    total += n
    if n:
        print(f"  {os.path.relpath(p, repo)}: {n} lines")
        if "--show" in sys.argv:
            for a, b in zip(old, lines):
                if a != b:
                    i = next(k for k in range(min(len(a), len(b))) if a[k] != b[k]) if a[:len(b)] != b[:len(a)] else 0
                    print(f"      - {a[max(0, i - 60):i + 100]}\n      + {b[max(0, i - 60):i + 100]}")
if dry:
    sys.exit(0)
for p, lines in changes.items():
    if lines != open(p).read().split("\n"):
        open(p, "w").write("\n".join(lines))
rows = [("", nt, t, "type") for t, nt in TYPES.items()]
rows += [("", new, old, "field") for fmap in FIELDS.values() for old, (new, _) in fmap.items()]
new_file = not os.path.exists(map_path)
with open(map_path, "a") as f:
    if new_file:
        f.write("address,name,old_label,kind\n")
    for r in rows:
        f.write(",".join(r) + "\n")
with open(refresh_path, "w") as f:
    f.write("address,name,old_label,kind\n")
    for line in open(map_path).read().split("\n")[1:]:
        if not line:
            continue
        a, n, o, k = line.split(",")
        if k == "field" and o in generic:
            continue
        f.write(line + "\n")
print(f"map: {len(rows)} type / field rows; refresh map written")
