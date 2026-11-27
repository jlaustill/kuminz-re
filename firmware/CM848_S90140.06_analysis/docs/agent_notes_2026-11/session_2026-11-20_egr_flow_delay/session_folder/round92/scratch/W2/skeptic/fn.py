"""Skeptic: print the decompiled function that contains a .cpp line number, or the one with a given name / address.
usage: fn.py <cpp> line <n> [max lines]   |   fn.py <cpp> name <function name> [max lines]   |   fn.py <cpp> addr <hex>"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
mode = sys.argv[2]
arg = sys.argv[3]
limit = int(sys.argv[4]) if len(sys.argv) > 4 else 400
heads = [(i, m.group(1), int(m.group(2), 16)) for i, line in enumerate(cpp)
         for m in [re.match(r"// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)] if m]


def body(idx):
    start = heads[idx][0]
    end = heads[idx + 1][0] - 1 if idx + 1 < len(heads) else len(cpp)
    lines = cpp[start - 1:end]
    for n, line in enumerate(lines[:limit]):
        print(f"{start + n:6d}  {line}")
    if len(lines) > limit:
        print(f"... ({len(lines) - limit} more lines)")


if mode == "line":
    n = int(arg) - 1
    idx = max(i for i, h in enumerate(heads) if h[0] <= n)
    body(idx)
elif mode == "name":
    for i, h in enumerate(heads):
        if h[1] == arg:
            body(i)
elif mode == "addr":
    a = int(arg, 16)
    cands = [i for i, h in enumerate(heads) if h[2] <= a]
    idx = max(cands, key=lambda i: heads[i][2])
    print(f"# containing-by-entry: {heads[idx][1]} @ 0x{heads[idx][2]:x}")
    body(idx)
