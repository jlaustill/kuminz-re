"""Round 93 (read-only): among the 4-byte rows of the second typing pass, the ones the code uses as pointers:
- the ROM loads the row's content into an address register (movea.l (abs).l,An) anywhere, or
- the new .cpp dereferences or indexes the row (*(type *)name, name[...], *name, (type *)name).
Such rows go back to 'undefined' (a pointer's type should name its pointee). Writes their addresses.
usage: pointer_rows_r93.py <repo> <candidates.csv> <drop.csv>"""
import csv
import os
import re
import sys

repo, candidates, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
cpp = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"), errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", cpp, flags=re.S)
drop = []
for r in csv.DictReader(open(candidates)):
    if r["type"] not in ("dword", "i32"):
        continue
    a, name = int(r["address"], 16), r["name"]
    load = False
    i = rom.find(a.to_bytes(4, "big"))
    while i != -1:
        if i % 2 == 0 and i >= 2 and (int.from_bytes(rom[i - 2:i], "big") & 0xf1ff) == 0x2079:
            load = True
            break
        i = rom.find(a.to_bytes(4, "big"), i + 1)
    deref = len(re.findall(rf"\*\s*\)\s*{re.escape(name)}\b|\*\s*{re.escape(name)}\b|\b{re.escape(name)}\s*\[", code))
    if load or deref:
        drop.append((r["address"], name, "movea.l load" if load else "", deref))
with open(out, "w") as fh:
    for a, name, load, deref in drop:
        fh.write(f"{a}\n")
for a, name, load, deref in drop:
    print(f"{a} {name}: {load} {'pointer renders ' + str(deref) if deref else ''}")
print(len(drop), "pointer rows")
