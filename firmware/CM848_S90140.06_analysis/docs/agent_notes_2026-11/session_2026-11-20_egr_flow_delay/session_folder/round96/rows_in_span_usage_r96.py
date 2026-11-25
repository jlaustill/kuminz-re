"""Round 96: for every CM550 global row inside [start, end), how many times its name (or _name) appears in a decompilation,
and in which functions. usage: rows_in_span_usage_r96.py <repo> <cpp> <hex start> <hex end>"""
import collections
import os
import re
import sys

repo, cpp_path, start, end = os.path.abspath(sys.argv[1]), sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
cpp = open(cpp_path, errors="replace").read()
func_of = []
for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-f]+)$", cpp, re.M):
    func_of.append((m.start(), m.group(1)))
used = collections.Counter()
for line in open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 3)
    if len(p) > 2 and p[0].startswith("0x") and p[1] and start <= int(p[0], 16) < end:
        hits = [m.start() for m in re.finditer(r"(?<![A-Za-z0-9_])_?%s(?![A-Za-z0-9_])" % re.escape(p[1]), cpp)]
        funcs = set()
        for h in hits:
            name = ""
            for s, n in func_of:
                if s > h:
                    break
                name = n
            funcs.add(name)
        if hits:
            print(f"{p[0]} {p[1]:45s} {len(hits):3d} uses in {sorted(funcs)[:4]}")
        used[bool(hits)] += 1
print("rows used by name:", used[True], "unused:", used[False])
