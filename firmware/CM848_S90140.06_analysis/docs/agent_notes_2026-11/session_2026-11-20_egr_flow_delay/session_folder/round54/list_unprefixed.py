"""Round 54: list CM848 function names without a cm848_ / hpcr_ / mpc555_ prefix, marking the ones CM550 also uses
(those keep their name or are renamed in both firmwares).  usage: list_unprefixed.py <firmware dir>"""
import os
import re
import sys

d = sys.argv[1]
cm848 = open(os.path.join(d, "CM848_S90140.06_analysis/output/function_renames.csv")).read().split("\n")
cm550 = open(os.path.join(d, "CM550_J90350.00_analysis/output/function_renames.csv")).read()
cm550_names = set(re.findall(r"^0x[0-9a-fA-F]+,([A-Za-z_][A-Za-z0-9_]*)", cm550, re.M))
out = []
for line in cm848:
    m = re.match(r"^(0x[0-9a-fA-F]+),([A-Za-z_][A-Za-z0-9_]*)(,.*)?$", line)
    if not m:
        continue
    name = m.group(2)
    if re.match(r"(cm848|hpcr|mpc555|vp44|cm550)_", name) or name.startswith(("FUN_", "LAB_")):
        continue
    out.append((name in cm550_names, m.group(1), name, (m.group(3) or "")[1:][:150]))
print(f"{len(out)} unprefixed; {sum(1 for o in out if not o[0])} not in CM550")
for shared, a, name, plate in sorted(out):
    if not shared:
        print(a, name, "|", plate)
