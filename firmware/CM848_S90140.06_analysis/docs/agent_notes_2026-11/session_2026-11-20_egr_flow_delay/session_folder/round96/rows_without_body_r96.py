"""Round 96: function_renames.csv rows whose address has no '// Function: ... @ 0x<addr>' body in a decompilation.
usage: rows_without_body_r96.py <function_renames.csv> <decompilation.cpp>"""
import re
import sys

bodies = {int(m.group(1), 16) for m in re.finditer(r"^// Function: \S+ @ 0x([0-9a-f]+)$", open(sys.argv[2], errors="replace").read(), re.M)}
n = 0
for line in open(sys.argv[1], newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if len(p) > 1 and p[0].startswith("0x"):
        a = int(p[0], 16)
        if a not in bodies:
            n += 1
            print(f"0x{a:08x} {p[1]}")
print(n, "rows without a body")
