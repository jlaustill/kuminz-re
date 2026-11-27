"""Print a decompiled function from a .ghidra.cpp by name, by entry address, or by a contained .cpp line number.
usage: showfn.py <cpp> <name | 0xADDR | L<line>> [max lines]"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
key = sys.argv[2]
limit = int(sys.argv[3]) if len(sys.argv) > 3 else 400
starts = []
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
for i, line in enumerate(cpp):
    m = pat.match(line)
    if m:
        starts.append((i, m.group(1), int(m.group(2), 16)))
sel = None
if key.startswith("L"):
    n = int(key[1:]) - 1
    for j, (i, name, addr) in enumerate(starts):
        if i <= n:
            sel = j
elif key.lower().startswith("0x"):
    a = int(key, 16)
    for j, (i, name, addr) in enumerate(starts):
        if addr == a:
            sel = j
    if sel is None:
        best = None
        for j, (i, name, addr) in enumerate(starts):
            if addr <= a and (best is None or addr > starts[best][2]):
                best = j
        sel = best
else:
    for j, (i, name, addr) in enumerate(starts):
        if name == key:
            sel = j
if sel is None:
    sys.exit("not found")
i, name, addr = starts[sel]
end = starts[sel + 1][0] if sel + 1 < len(starts) else len(cpp)
print(f"### {name} @ 0x{addr:x} : cpp lines {i + 1}-{end} ({end - i} lines)")
for n in range(i, min(end, i + limit)):
    print(f"{n + 1}: {cpp[n]}")
