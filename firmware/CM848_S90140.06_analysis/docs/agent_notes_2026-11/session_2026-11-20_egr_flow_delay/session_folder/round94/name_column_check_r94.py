"""Round 94 (read-only): look for names in name columns that a comment-refresh could have written - a '.' (an
'instance.field' path) or a name that is a global row of the same firmware - in structure_definitions (field_name),
enums (member_name), function_definitions (name) and local_variables (new_name), both firmwares.
usage: name_column_check_r94.py <repo>"""
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    O = os.path.join(repo, "firmware", fw, "output")
    globals_ = {l.split(",")[1] for l in open(os.path.join(O, "global_variables.csv"), newline="").read().split("\n")
                if l.startswith("0x") and l.count(",") >= 2}
    for fname, col in (("structure_definitions.csv", 2), ("enums.csv", 2), ("function_definitions.csv", 3), ("local_variables.csv", 3)):
        bad = []
        for n, row in enumerate(csv.reader(open(os.path.join(O, fname), newline="")), 1):
            if len(row) <= col or not row[0] or row[0].startswith("#"):
                continue
            name = row[col].strip()
            if "." in name:
                bad.append((n, name, "has a dot"))
        print(f"{fw[:5]} {fname}: {len(bad)} suspicious" + "".join(f"\n   line {n}: {name} ({why})" for n, name, why in bad[:10]))
