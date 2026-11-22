"""Round 34: every function that names a label in an address range (DAT_ / PTR_ / named rows), with the labels it
uses. usage: area_users.py <cpp> <global_variables.csv> <start hex> <end hex>"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
start, end = int(sys.argv[3], 16), int(sys.argv[4], 16)
names = {}
for l in open(sys.argv[2], errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 2 and p[0].startswith("0x") and p[1] and start <= int(p[0], 16) <= end:
        names[p[1]] = int(p[0], 16)
pat = re.compile(r"\b(?:DAT|PTR_DAT|PTR_[A-Za-z0-9_]+?|BYTE|WORD|DWORD|PTR)_(003f[0-9a-f]{4})\b|\b(" +
                 "|".join(re.escape(n) for n in sorted(names, key=len, reverse=True)) + r")\b")
func, users = None, {}
for l in cpp:
    m = re.match(r"^// Function: (\S+) @", l)
    if m:
        func = m.group(1)
        continue
    for m in pat.finditer(l):
        if m.group(1):
            a = int(m.group(1), 16)
            if not (start <= a <= end):
                continue
            label = m.group(0)
        else:
            label = m.group(2)
        users.setdefault(func, set()).add(label)
for f, labels in sorted(users.items()):
    print(f"{f}: {' '.join(sorted(labels))}")
