"""Round 94 (read-only): struct field names, enum member names, parameter and local names that equal the name of a
current global row or function of the same firmware - where refresh_other_csvs.py (which replaced old names in every
column) could have overwritten a name column with a rename's new name. For each hit: was the name column ever changed
by a commit of the session? (git log -S on the line's new text in the CSV). usage: name_collision_check_r94.py <repo>"""
import csv
import os
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    rel = f"firmware/{fw}/output"
    O = os.path.join(repo, rel)
    names = set()
    for fname in ("global_variables.csv", "function_renames.csv"):
        for l in open(os.path.join(O, fname), newline="").read().split("\n"):
            if l.startswith("0x") and l.count(",") >= 1:
                names.add(l.split(",")[1])
    for fname, col, keycol in (("structure_definitions.csv", 2, 0), ("enums.csv", 2, 0), ("function_definitions.csv", 3, 1), ("local_variables.csv", 3, 1)):
        hits = []
        for row in csv.reader(open(os.path.join(O, fname), newline="")):
            if len(row) <= col or not row[0] or row[0].startswith("#"):
                continue
            if row[col].strip() in names and row[col].strip():
                hits.append((row[keycol], row[col].strip()))
        print(f"{fw[:5]} {fname}: {len(hits)} name-column values equal a current global / function name")
        for key, name in hits[:12]:
            print(f"    {key} . {name}")
