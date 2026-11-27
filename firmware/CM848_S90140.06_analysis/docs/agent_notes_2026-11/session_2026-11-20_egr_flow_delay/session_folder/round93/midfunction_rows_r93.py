"""Round 93 (read-only; a lead for the next round): CM550 function rows that the dumped ROM never enters (no jsr /
jmp operand, no bsr / bra / Bcc displacement, no aligned 4-byte pointer) classified by the code around them:
- MID-BODY: a linear disassembly from the function row before it reaches the row exactly on an instruction boundary
  and the instruction before the row does not leave (not rts / rte / rtd / jmp / bra): the row cuts a function in two;
- AFTER-LEAVE: the instruction before it leaves: an entry nothing in the dump calls (called from the undumped ROM
  above 0x40000, or dead code);
- OFF-BOUNDARY: the linear disassembly does not land on the row (data in between, or the row is inside an instruction).
usage: midfunction_rows_r93.py <repo> <m68k.py>"""
import csv
import importlib.util
import io
import os
import contextlib
import subprocess
import sys

repo, tool = os.path.abspath(sys.argv[1]), sys.argv[2]
rom_path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin")
rom = open(rom_path, "rb").read()
rows = sorted((int(r[0], 16), r[1]) for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline=""))
              if r and r[0].startswith("0x") and int(r[0], 16) < len(rom))
relative = set()
for i in range(0, len(rom) - 4, 2):
    w = int.from_bytes(rom[i:i + 2], "big")
    if (w & 0xf000) == 0x6000:
        d8 = w & 0xff
        if d8 == 0:
            relative.add(i + 2 + int.from_bytes(rom[i + 2:i + 4], "big", signed=True))
        elif d8 != 0xff:
            relative.add(i + 2 + (d8 - 256 if d8 & 0x80 else d8))


def referenced(a):
    if a in relative:
        return True
    i = rom.find(a.to_bytes(4, "big"))
    while i != -1:
        if i % 2 == 0:
            return True
        i = rom.find(a.to_bytes(4, "big"), i + 1)
    return False


counts = {}
for k, (a, name) in enumerate(rows):
    if referenced(a) or k == 0:
        continue
    prev = rows[k - 1][0]
    out = subprocess.run([sys.executable, tool, rom_path, f"{prev:x}", f"{a + 2:x}"], capture_output=True, text=True).stdout
    lines = [l for l in out.splitlines() if l[:6].strip(":").strip()]
    addresses = [int(l.split(":")[0], 16) for l in lines]
    if a not in addresses:
        kind, detail = "OFF-BOUNDARY", ""
    else:
        before = lines[addresses.index(a) - 1] if addresses.index(a) > 0 else ""
        text = " ".join(before.split()[2:])
        leaves = text.startswith(("rts", "rte", "rtd", "jmp", "bra"))
        kind, detail = ("AFTER-LEAVE" if leaves else "MID-BODY"), text
    counts[kind] = counts.get(kind, 0) + 1
    print(f"{kind:12} 0x{a:05x} {name:52} after 0x{prev:05x} {rows[k - 1][1][:40]:40} | before it: {detail[:40]}")
print(counts)
