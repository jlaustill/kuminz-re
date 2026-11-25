"""Round 94 (task #41): the function_name column of function_definitions.csv / local_variables.csv takes the current
name of the function at its address (function_renames.csv). The build applies those rows by address and only warns
('Function name mismatch at 0x10520 - expected arrayRangeSum, found cm550_arrayRangeSum'), so the .cpp must not
change. Keeps line endings; reports each change. usage: sync_definition_names_r94.py <repo> [--dry-run]"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
FIRMWARES = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
for fw, out in FIRMWARES.items():
    names = {}
    for r in csv.reader(open(os.path.join(repo, out, "function_renames.csv"), newline="")):
        if r and r[0].startswith("0x"):
            names[int(r[0], 16)] = r[1]
    for csv_name in ("function_definitions.csv", "local_variables.csv"):
        path = os.path.join(repo, out, csv_name)
        text = open(path, newline="").read()
        lines = text.split("\n")
        changed = []
        for i, line in enumerate(lines):
            if not line.startswith("0x"):
                continue
            body = line.rstrip("\r")
            end = line[len(body):]
            row = next(csv.reader([body]))
            current = names.get(int(row[0], 16))
            if current and len(row) > 1 and row[1] != current:
                changed.append((row[0], row[1], current))
                first, rest = body.split(",", 2)[0], body.split(",", 2)[2]
                lines[i] = f"{first},{current},{rest}{end}"
        if changed and not dry:
            open(path, "w", newline="").write("\n".join(lines))
        print(f"{fw} {csv_name}: {len(changed)} rows")
        for a, old, new in sorted(set(changed)):
            print(f"   {a} {old} -> {new}")
