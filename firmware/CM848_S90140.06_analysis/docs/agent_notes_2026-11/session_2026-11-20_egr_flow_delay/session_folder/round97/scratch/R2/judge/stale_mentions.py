"""List CM550 / CM848 rows (globals, functions, structure fields, locals) whose text mentions an old name of the
batch (CM550 family_R2 rows + the CM848 row torque_limit_working_reference). Read-only.
usage: stale_mentions.py"""
import csv
import re

BASE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97"
family = {}
for line in open(f"{BASE}/family_R2.txt"):
    parts = line.split()
    if parts:
        family[int(parts[0], 16)] = parts[1]
old_cm550 = set(family.values())
old_cm848 = {"torque_limit_working_reference"}


def scan(path, old, skip_addresses, label):
    pattern = re.compile(r"\b(" + "|".join(sorted(map(re.escape, old), key=len, reverse=True)) + r")\b")
    with open(path, newline="", errors="replace") as handle:
        for row in csv.reader(handle):
            if not row or not row[0].startswith("0x"):
                continue
            try:
                address = int(row[0], 16)
            except ValueError:
                continue
            if address in skip_addresses:
                continue
            text = ",".join(row[1:])
            hits = sorted(set(pattern.findall(text)))
            if hits:
                print(f"{label} {row[0]} {row[1]}: {' '.join(hits)}")


scan(f"{BASE}/frozen/cm550/global_variables.csv", old_cm550, set(family), "cm550 global")
scan(f"{BASE}/frozen/cm550/function_renames.csv", old_cm550, set(), "cm550 function")
scan(f"{BASE}/frozen/cm848/global_variables.csv", old_cm848, {0x3fa8a4}, "cm848 global")
scan(f"{BASE}/frozen/cm848/function_renames.csv", old_cm848, set(), "cm848 function")
