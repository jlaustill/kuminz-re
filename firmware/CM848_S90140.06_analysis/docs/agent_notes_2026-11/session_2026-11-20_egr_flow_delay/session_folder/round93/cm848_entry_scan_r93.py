"""Round 93 (read-only): the CM848 version of the mid-function row scan. For every function row, how the two images
(ROM at 0, flash2 at 0x500000) reach its address: a relative or absolute branch (b / bl / ba / bla / bc / bcl), an
aligned 4-byte pointer in either image, or an address built in a register (lis + addi / ori within 6 instructions).
A row nothing reaches is printed with the instruction before it: 'blr' / 'b' / 'bctr' before it = an entry that only a
computed call can reach (a table of 16-bit offsets, or the boot ROM's RAM copy); anything else = code runs into it.
usage: cm848_entry_scan_r93.py <repo>"""
import csv
import os
import struct
import sys

repo = os.path.abspath(sys.argv[1])
A = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
images = [(0x0, open(os.path.join(A, "originals/cm848_rom.bin"), "rb").read()),
          (0x500000, open(os.path.join(A, "originals/cm848_flash2_live.bin"), "rb").read())]
rows = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(A, "output/function_renames.csv"), newline="")) if r and r[0].startswith("0x")}
targets, pointers, built = set(), set(), set()


def word_at(a):
    for base, data in images:
        if base <= a < base + len(data) - 3:
            return struct.unpack_from(">I", data, a - base)[0]
    return None


for base, data in images:
    reg_hi = {}
    for off in range(0, len(data) - 3, 4):
        w = struct.unpack_from(">I", data, off)[0]
        pc = base + off
        op = w >> 26
        if op == 18:                                   # b / bl / ba / bla
            li = w & 0x03fffffc
            if li & 0x02000000:
                li -= 0x04000000
            targets.add(li if w & 2 else pc + li)
        elif op == 16:                                 # bc
            bd = w & 0xfffc
            if bd & 0x8000:
                bd -= 0x10000
            targets.add(bd if w & 2 else pc + bd)
        elif op == 15 and ((w >> 16) & 0x1f) == 0:     # lis rD,imm
            reg_hi[(w >> 21) & 0x1f] = ((w & 0xffff) << 16, pc)
        elif op in (14, 24):                           # addi rD,rA,imm / ori rA,rS,imm
            src = (w >> 16) & 0x1f if op == 14 else (w >> 21) & 0x1f
            if src in reg_hi and pc - reg_hi[src][1] <= 24:
                imm = w & 0xffff
                if op == 14 and imm & 0x8000:
                    imm -= 0x10000
                built.add((reg_hi[src][0] + imm) & 0xffffffff)
        if w in rows or (w & 0xfffffffc) in rows:
            pointers.add(w & 0xfffffffc)
LEAVES = {0x4e800020: "blr", 0x4e800420: "bctr", 0x4c000064: "rfi"}
no_entry = []
for a in sorted(rows):
    if a in targets or a in pointers or a in built:
        continue
    before = word_at(a - 4)
    if before is None:
        kind = "first in its image"
    elif before in LEAVES:
        kind = "after " + LEAVES[before]
    elif (before >> 26) == 18 and not (before & 1):
        kind = "after b"
    else:
        kind = f"RUNS INTO IT (before: {before:08x})"
    no_entry.append((a, rows[a], kind))
print(f"{len(rows)} function rows; {len(no_entry)} with no reference found")
for a, n, k in no_entry:
    if k.startswith("RUNS"):
        print(f"  0x{a:08x} {n}: {k}")
import collections
print(collections.Counter(k.split(" (")[0] for _, _, k in no_entry))
