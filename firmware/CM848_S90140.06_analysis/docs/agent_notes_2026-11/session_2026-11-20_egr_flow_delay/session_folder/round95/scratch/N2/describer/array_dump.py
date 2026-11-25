"""Dump an array of 14-byte lookupTableInterpolation records from the CM550 RAM dump, with the row names at
each x / y pointer.  usage: array_dump.py <start hex> <count>"""
import csv
import struct
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
RAM = open(FW + "J90350.00.ram.bin", "rb").read()
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
names = {}
for line in open(FROZEN + "global_variables.csv"):
    if line.startswith("0x"):
        p = next(csv.reader([line]))
        names[int(p[0], 16)] = (p[1], p[2])
start = int(sys.argv[1], 16)
count = int(sys.argv[2])
for i in range(count):
    a = start + 14 * i
    off, xp, xin, yp, flag = struct.unpack(">HIHIH", RAM[a - 0x800000: a - 0x800000 + 14])
    xc = struct.unpack(">H", RAM[xp - 0x800000: xp - 0x800000 + 2])[0] if 0x800000 <= xp < 0x809000 else None
    yc = struct.unpack(">H", RAM[yp - 0x800000: yp - 0x800000 + 2])[0] if 0x800000 <= yp < 0x809000 else None
    print("[%2d] 0x%x off %3d x 0x%x (count %s) %s  in %5d  y 0x%x (count %s) %s  flag %d" % (
        i, a, off, xp, xc, names.get(xp, ("-", ""))[0], xin, yp, yc, names.get(yp, ("-", ""))[0], flag))
