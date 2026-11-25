"""Round 93 (read-only): how many global renders in a CM550 .cpp still carry the leading underscore (a read wider than
the row's type) and how many unnamed DAT_ / _DAT_ renders there are; for the underscore rows, their current type.
usage: underscore_census_r93.py <repo> [<cpp>]"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp_path = sys.argv[2] if len(sys.argv) > 2 else os.path.join(O, "J90350.00.ghidra.cpp")
rows = {}
for line in open(os.path.join(O, "global_variables.csv"), newline="").read().split("\n"):
    parts = line.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x") and parts[1]:
        rows[parts[1]] = parts[2]
cpp = open(cpp_path, errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", cpp, flags=re.S)
code = "\n".join(l for l in code.split("\n") if not l.lstrip().startswith("//"))
under = collections.Counter()
for m in re.finditer(r"(?<![A-Za-z0-9_])_([a-z][A-Za-z0-9_]*)\b", code):
    if m.group(1) in rows:
        under[m.group(1)] += 1
dat = len(re.findall(r"\b_?DAT_[0-9a-f]{8}\b", code))
by_type = collections.Counter()
for name, n in under.items():
    by_type[rows[name]] += n
print(f"{sum(under.values())} underscore renders of {len(under)} rows; by row type: {dict(by_type.most_common(8))}")
print(f"{dat} DAT_ / _DAT_ renders")
print("most frequent:", [(n, c, rows[n]) for n, c in under.most_common(8)])
