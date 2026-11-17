"""Replace old identifiers with their new names in comment columns (and given text files), keeping history
('(was old)', 'were old', 'formerly old'). Usage: refresh_references.py <repo> <mapping.csv>"""
import csv
import os
import re
import sys

repo, mapping = sys.argv[1:3]
KEEP = {"fuel_demand_offset_correction", "sensor_channel7_fault_status"}      # still names of other addresses
pairs = sorted(((r["old_label"], r["name"]) for r in csv.DictReader(open(mapping))
                if r["old_label"] and not r["old_label"].startswith("DAT_") and r["old_label"] not in KEEP),
               key=lambda p: -len(p[0]))
table = dict(pairs)
pattern = re.compile(r"\b(" + "|".join(re.escape(o) for o, _ in pairs) + r")\b")
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")


def refresh(text):
    count = 0

    def sub(m):
        nonlocal count
        before = text[max(0, m.start() - 120):m.start()]
        if HISTORY.search(before[-14:]):
            return m.group(0)
        hist = max(before.rfind("was "), before.rfind("were "), before.rfind("(was"))
        if hist >= 0 and not re.search(r"[);]|->|\.\s", before[hist:]):     # inside a 'were a / b / c' list
            return m.group(0)
        count += 1
        return table[m.group(1)]
    return pattern.sub(sub, text), count


out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
column_files = [("global_variables.csv", 3), ("function_renames.csv", 2), ("deleted_functions.csv", 1),
                ("arrays.csv", 4), ("labels.csv", 2), ("constants.csv", 3)]
for name, col in column_files:
    path = os.path.join(out, name)
    if not os.path.exists(path):
        continue
    lines = open(path).read().split("\n")
    total = 0
    for i, l in enumerate(lines):
        p = l.split(",", col)
        if p[0].startswith("0x") and len(p) > col:
            p[col], n = refresh(p[col])
            if n:
                total += n
                lines[i] = ",".join(p)
    open(path, "w").write("\n".join(lines))
    print(f"{name}: {total} references refreshed")
for rel in ("firmware/CLAUDE.md", "firmware/scripts/test_disasm_tools.py"):
    path = os.path.join(repo, rel)
    t, n = refresh(open(path).read())
    open(path, "w").write(t)
    print(f"{rel}: {n} references refreshed")
