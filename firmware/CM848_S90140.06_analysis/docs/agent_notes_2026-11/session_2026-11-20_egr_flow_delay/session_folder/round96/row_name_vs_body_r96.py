"""Round 96: function_renames.csv rows whose body in the decompilation carries a different name, plus rows that repeat
an address or cannot be parsed. usage: row_name_vs_body_r96.py <function_renames.csv> <decompilation.cpp>"""
import collections
import re
import sys

bodies = {int(m.group(2), 16): m.group(1) for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-f]+)$", open(sys.argv[2], errors="replace").read(), re.M)}
seen = collections.Counter()
for n, line in enumerate(open(sys.argv[1], newline=""), 1):
    s = line.strip()
    if not s or s.startswith("#") or n == 1:
        continue
    p = s.split(",", 2)
    try:
        a = int(p[0], 16)
    except ValueError:
        print(f"line {n}: unparsable address {p[0]!r}")
        continue
    seen[a] += 1
    if seen[a] > 1:
        print(f"line {n}: repeats 0x{a:x}")
    if a in bodies and bodies[a] != p[1]:
        print(f"line {n}: 0x{a:x} row {p[1]} but the body is {bodies[a]}")
