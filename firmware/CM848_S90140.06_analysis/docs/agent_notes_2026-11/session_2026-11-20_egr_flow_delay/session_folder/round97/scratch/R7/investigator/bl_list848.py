"""List the bl / b targets (with names) of a CM848 code range: bl_list848.py 0xSTART 0xEND"""
import csv
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
rom = open(BASE + "cm848_rom.bin", "rb").read()
fl2 = open(BASE + "cm848_flash2_live.bin", "rb").read()
names = {}
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm848/function_renames.csv")):
    if row and row[0].startswith("0x"):
        names[int(row[0], 16)] = row[1]
start, end = int(sys.argv[1], 16), int(sys.argv[2], 16)
img, base = (fl2, 0x500000) if start >= 0x500000 else (rom, 0)
for pc in range(start, end, 4):
    w = int.from_bytes(img[pc - base:pc - base + 4], "big")
    if (w >> 26) == 18:
        li = w & 0x03fffffc
        if li & 0x02000000:
            li -= 0x04000000
        tgt = li if (w >> 1) & 1 else pc + li
        print(f"0x{pc:x}: {'bl' if w & 1 else 'b '} 0x{tgt:x} {names.get(tgt, '')}")
