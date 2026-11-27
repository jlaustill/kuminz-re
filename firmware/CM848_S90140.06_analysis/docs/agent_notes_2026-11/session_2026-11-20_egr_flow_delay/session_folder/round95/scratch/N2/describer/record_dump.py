"""Decode CM550 lookupTableInterpolation (0x34de0) argument records from the RAM dumps.
usage: record_dump.py <record hex> ...
Prints the 14-byte record (x_axis_offset w+0, x_axis_pointer l+2, x_input w+6, y_values_pointer l+8,
no_interpolation_flag w+12), the two tables (count word + N = count/2 words), the e2m record of each table
address, and every frozen global row that starts inside the record or at the tables."""
import csv
import os
import struct
import subprocess
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ROM = open(FW + "J90350.00.rom.bin", "rb").read()
RAM = open(FW + "J90350.00.ram.bin", "rb").read()
XRAM = open(FW + "J90350.00.extended_ram.bin", "rb").read()
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
TOOL = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/e2m_block_addresses.py"

rows = []
for line in open(FROZEN + "global_variables.csv"):
    if line.startswith("0x"):
        parts = next(csv.reader([line]))
        rows.append((int(parts[0], 16), parts[1], parts[2] if len(parts) > 2 else "", parts[3] if len(parts) > 3 else ""))


def read(addr, n):
    if addr + n <= len(ROM):
        return ROM[addr:addr + n], "ROM"
    if 0x800000 <= addr and addr + n <= 0x800000 + len(RAM):
        return RAM[addr - 0x800000: addr - 0x800000 + n], "RAM"
    if 0x809242 <= addr and addr + n <= 0x809242 + len(XRAM):
        return XRAM[addr - 0x809242: addr - 0x809242 + n], "XRAM"
    return None, "?"


def w(addr):
    b, _ = read(addr, 2)
    return None if b is None else struct.unpack(">H", b)[0]


def l(addr):
    b, _ = read(addr, 4)
    return None if b is None else struct.unpack(">I", b)[0]


def rows_in(lo, hi):
    return [r for r in rows if lo <= r[0] < hi]


def e2m(addr):
    out = subprocess.run(["python3", TOOL, "--firmware", "cm550", "--globals", FROZEN + "global_variables.csv",
                          "--address", "0x%x" % addr], capture_output=True, text=True, cwd=os.path.dirname(TOOL))
    return out.stdout.strip() or out.stderr.strip()


def table(ptr, label):
    count = w(ptr)
    if count is None:
        print("    %s 0x%x: not readable" % (label, ptr))
        return
    n = count // 2
    vals = [w(ptr + 2 + 2 * i) for i in range(min(n, 40))]
    _, region = read(ptr, 2)
    print("    %s 0x%x (%s): count word %d -> %d points: %s" % (label, ptr, region, count, n, vals))
    for r in rows_in(ptr, ptr + 2 + min(count, 80)):
        print("      row 0x%x %s [%s] %s" % (r[0], r[1], r[2], r[3][:160]))
    print("      e2m: " + e2m(ptr).replace("\n", "\n           "))


for a in sys.argv[1:]:
    rec = int(a, 16)
    b, region = read(rec, 14)
    print("===== record 0x%x (%s)" % (rec, region))
    if b is None:
        print("   not readable")
        continue
    off, xp, xin, yp, flag = struct.unpack(">HIHIH", b)
    print("   x_axis_offset %d  x_axis_pointer 0x%x  x_input %d (0x%x)  y_values_pointer 0x%x  no_interpolation_flag %d"
          % (off, xp, xin, xin, yp, flag))
    for r in rows_in(rec - 4, rec + 14):
        print("   row 0x%x (+%d) %s [%s] %s" % (r[0], r[0] - rec, r[1], r[2], r[3][:200]))
    table(xp, "x axis")
    table(yp, "y values")
