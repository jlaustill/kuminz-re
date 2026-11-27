"""Describer J2 (read-only): does a proposed name already exist in a firmware's function_renames.csv /
global_variables.csv / structure_definitions.csv (exact name match on the name column)?
usage: check_names.py <frozen dir> <name> [...]"""
import csv
import os
import sys

frozen = sys.argv[1]
for fw in ("cm550", "cm848"):
    names = {}
    for fn, col in (("function_renames.csv", 1), ("global_variables.csv", 1), ("structure_definitions.csv", 0)):
        for r in csv.reader(open(os.path.join(frozen, fw, fn), newline="", errors="replace")):
            if len(r) > col and r and not r[0].startswith("#"):
                names.setdefault(r[col], []).append((fn, r[0]))
            if fn == "structure_definitions.csv" and len(r) > 2:
                names.setdefault(r[2], []).append((fn + ":field", r[0]))
    for n in sys.argv[2:]:
        hits = names.get(n, [])
        print(f"{fw:6s} {n}: " + (", ".join(f"{a}@{b}" for a, b in hits[:4]) if hits else "free"))
