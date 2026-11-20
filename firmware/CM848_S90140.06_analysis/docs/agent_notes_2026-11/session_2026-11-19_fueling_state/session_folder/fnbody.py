"""Print decompiled function bodies from a .ghidra.cpp, blank lines dropped.
usage: fnbody.py <cpp> <function>[:<max lines>] ...   (max lines defaults to 80)"""
import re
import sys

text = open(sys.argv[1]).read().split("\n")
starts = [(i, m.group(1)) for i, line in enumerate(text) if (m := re.match(r"^// Function: (\S+) @", line))]
index = {name: (i, starts[k + 1][0] if k + 1 < len(starts) else len(text)) for k, (i, name) in enumerate(starts)}
for arg in sys.argv[2:]:
    name, _, limit = arg.partition(":")
    if name not in index:
        print(f"=== {name}: not found")
        continue
    s, e = index[name]
    body = [(n + 1, line) for n, line in enumerate(text[s:e], s) if line.strip()]
    cap = int(limit or 80)
    print(f"=== {name} (lines {s + 1}-{e}, {len(body)} non-blank)")
    for n, line in body[:cap]:
        print(f"{n}: {line}")
    if len(body) > cap:
        print(f"... {len(body) - cap} more lines")
