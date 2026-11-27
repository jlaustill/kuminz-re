"""Print an e2m block's records against the CSV rows at an assumed base (relative-offset alignment), with each row's
RAM-dump value and the functions that use it (from the .cpp).
usage: align_block.py <repo> <block> <base> [start_offset end_offset]"""
import csv
import os
import re
import struct
import sys

repo, block, base = os.path.abspath(sys.argv[1]), sys.argv[2].upper(), int(sys.argv[3], 16)
lo = int(sys.argv[4], 16) if len(sys.argv) > 4 else 0
hi = int(sys.argv[5], 16) if len(sys.argv) > 5 else 0x10000
fw = os.path.join(repo, "firmware", "CM848_S90140.06_analysis")
e2m = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
recs = []
for line in open(e2m, errors="replace"):
    f = line.split(",")
    if len(f) > 10 and f[2].upper() == block and re.match(r"^[0-9A-Fa-f]{4}$", f[3]):
        off = int(f[3], 16)
        desc = line.split(";", 1)[1].strip() if ";" in line else ""
        recs.append((off, f[0], f[1], f[9], f[10], desc))
recs.sort()
rows = {}
for line in open(os.path.join(fw, "output", "global_variables.csv")):
    if line.startswith("0x"):
        r = next(csv.reader([line]))
        if len(r) > 2:
            rows.setdefault(int(r[0], 16), (r[1], r[2]))
ram = open(os.path.join(fw, "originals", "cm848_ram.bin"), "rb").read()
RB = 0x3FA000
cpp = open(os.path.join(fw, "output", "cm848_rom.ghidra.cpp")).read()
funcs = {}
cur = None
for line in cpp.split("\n"):
    m = re.match(r"// Function: (\S+)", line)
    if m:
        cur = m.group(1)
        continue
    if cur and not line.lstrip().startswith(("/*", "//")):
        for tok in set(re.findall(r"\b[a-z][a-z0-9_]{3,}\b", line)):
            funcs.setdefault(tok, set()).add(cur)
for off, name, unit, sign, scale, desc in recs:
    if not (lo <= off <= hi):
        continue
    a = base + off
    row = rows.get(a)
    val = ""
    if RB <= a < RB + len(ram) - 1:
        val = struct.unpack(">H", ram[a - RB:a - RB + 2])[0]
    users = ""
    if row:
        users = ",".join(sorted(funcs.get(row[0], set()))[:3])
    print(f"+{off:04X} 0x{a:06x} {name} [{unit} {sign} {scale}] = {val} | row: {row[0] if row else '-'} "
          f"{row[1] if row else ''} | {users[:90]} | {desc[:70]}")
