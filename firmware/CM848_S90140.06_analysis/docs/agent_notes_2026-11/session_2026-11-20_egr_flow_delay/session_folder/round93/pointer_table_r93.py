"""Round 93 (read-only): the 4-byte values around a ROM address that are function row addresses (a pointer table),
with the bytes before each. usage: pointer_table_r93.py <repo> <start hex> <end hex>"""
import csv
import os
import sys

repo, lo, hi = os.path.abspath(sys.argv[1]), int(sys.argv[2], 16), int(sys.argv[3], 16)
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
rows = {int(r[0], 16): r[1] for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline=""))
        if r and r[0].startswith("0x")}
for a in range(lo, hi, 2):
    v = int.from_bytes(rom[a:a + 4], "big")
    if v in rows:
        print(f"0x{a:x}: -> 0x{v:x} {rows[v]} | bytes before: {rom[a - 8:a].hex(' ')}")
