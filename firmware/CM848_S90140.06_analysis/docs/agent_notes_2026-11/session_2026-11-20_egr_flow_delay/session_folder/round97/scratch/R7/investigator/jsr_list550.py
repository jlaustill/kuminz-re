"""List the jsr / bsr targets (with names) of a CM550 code range, with the ordinal of each call.
usage: jsr_list550.py 0xSTART 0xEND"""
import csv
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
names = {}
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/function_renames.csv")):
    if row and row[0].startswith("0x"):
        names[int(row[0], 16)] = row[1]
start, end = int(sys.argv[1], 16), int(sys.argv[2], 16)
n = 0
for pc in range(start, end, 2):
    w = int.from_bytes(rom[pc:pc + 2], "big")
    tgt = None
    if w == 0x4eb9:
        tgt = int.from_bytes(rom[pc + 2:pc + 6], "big")
        kind = "jsr"
    elif (w >> 8) == 0x61:
        d8 = w & 0xff
        if d8 == 0:
            tgt = pc + 2 + int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
            kind = "bsr.w"
        elif d8 != 0xff:
            tgt = pc + 2 + (d8 - 256 if d8 & 0x80 else d8)
            kind = "bsr.s"
    if tgt is not None:
        n += 1
        print(f"{n:3d} 0x{pc:x}: {kind} 0x{tgt:x} {names.get(tgt, '')}")
