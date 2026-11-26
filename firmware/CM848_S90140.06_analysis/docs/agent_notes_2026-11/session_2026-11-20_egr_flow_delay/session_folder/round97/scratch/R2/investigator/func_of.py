"""Map each reference address in refs.txt to the CM550 function containing it (by the .cpp markers).
usage: func_of.py refs.txt"""
import re
import sys
import bisect
from collections import Counter

cpp = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
funcs = []
for line in open(cpp, errors="replace"):
    m = re.match(r"// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [f[0] for f in funcs]


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return funcs[i] if i >= 0 else (0, "?")


cur = None
out = {}
for line in open(sys.argv[1]):
    m = re.match(r"== 0x([0-9a-f]+)", line)
    if m:
        cur = m.group(1)
        out[cur] = []
        continue
    m = re.match(r"\s+0x([0-9a-f]+):", line)
    if m and cur:
        a = int(m.group(1), 16)
        s, n = owner(a)
        out[cur].append(f"{n}@{s:x}" + (f"(+{a - s:x})" if a - s > 0x800 else ""))
for k, v in out.items():
    c = Counter(v)
    print(f"0x{k}: " + ", ".join(f"{n} x{c[n]}" for n in c))
