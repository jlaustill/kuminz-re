"""Describer F1 helper (read-only): print the function that contains each given line of a decompilation, with context.
usage: ctx.py <cpp> <before> <after> <line> [<line> ...]"""
import re
import sys

path, before, after = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
lines = open(path, errors="replace").read().split("\n")
for arg in sys.argv[4:]:
    n = int(arg)
    name = "?"
    for i in range(n - 1, -1, -1):
        m = re.match(r"// Function: (.*)", lines[i])
        if m:
            name = m.group(1)
            break
    print(f"##### line {n}: {name}")
    for i in range(max(0, n - 1 - before), min(len(lines), n + after)):
        print(f"{i + 1:6d}  {lines[i][:170]}")
