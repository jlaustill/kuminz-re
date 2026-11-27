"""Round 27 stage A (label-only), part 2: names the type-only rows of labels_r27a.tsv (generate_r27a.py), keeping each
row's type; comment = the note + ' (was <Ghidra label>, PR #53 round 27)' + ' | earlier note: <old comment>'. Checks:
the row exists and is type-only, the name is not a .cpp identifier / global / function / struct field name.
Appends address,name,Ghidra label,global rows to the map.
usage: apply_r27a_labels.py <repo> <labels.tsv> <map.csv>"""
import csv
import os
import re
import sys

repo, tsv, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
taken = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
for f, k in (("global_variables.csv", 1), ("function_renames.csv", 1), ("structure_definitions.csv", 2),
             ("structure_definitions.csv", 0), ("local_variables.csv", 3), ("function_definitions.csv", 3)):
    taken |= {row[k] for row in csv.reader(open(os.path.join(out, f), errors="replace")) if len(row) > k}
problems, rows = [], []
for line in open(tsv):
    address, typ, label, name, note = line.rstrip("\n").split("\t")
    a = f"0x{int(address, 16):08x}"
    k = [i for i, l in enumerate(g) if l.startswith(f"{a},,")]
    if len(k) != 1:
        problems.append(f"{a}: {len(k)} type-only rows")
        continue
    if name in taken:
        problems.append(f"{a}: {name} exists")
    if not re.match(r"^[a-z][a-z0-9_]*[a-z0-9]$", name) or "__" in name:
        problems.append(f"{a}: name format {name}")
    if 0x3fd482 <= int(a, 16) <= 0x3feec1:
        problems.append(f"{a}: inside the EEPROM mirror, check _cal")
    rows.append((k[0], a, label, name, note))
if problems:
    sys.exit("\n".join("PROBLEM " + p for p in problems))
with open(map_path, "a") as fh:
    for i, a, label, name, note in rows:
        _, _, typ, old_comment = (g[i].split(",", 3) + [""])[:4]
        text = f"{note} (was {label}, PR #53 round 27)"
        if old_comment:
            text += f" | earlier note: {old_comment}"
        g[i] = ",".join([a, name, typ, text])
        fh.write(f"{a},{name},{label},global\n")
open(gp, "w").write("\n".join(g))
print(f"named {len(rows)} type-only rows")
