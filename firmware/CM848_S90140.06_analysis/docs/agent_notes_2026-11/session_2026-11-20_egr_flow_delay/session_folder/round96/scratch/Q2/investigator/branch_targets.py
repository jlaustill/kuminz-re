"""Scan the CM550 ROM for 68k PC-relative branches (Bcc / BRA / BSR, 8- and 16-bit displacement) and jsr/jmp abs.l
whose target falls inside the given ranges, to show nothing else enters a new function row.
usage: branch_targets.py <start> <end> [<start> <end> ...] (hex)"""
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
ranges = [(int(sys.argv[i], 16), int(sys.argv[i + 1], 16)) for i in range(1, len(sys.argv), 2)]
for pc in range(0, len(rom) - 6, 2):
    w = int.from_bytes(rom[pc:pc + 2], "big")
    hits = []
    if (w & 0xf000) == 0x6000:
        d8 = w & 0xff
        if d8 == 0:
            d = int.from_bytes(rom[pc + 2:pc + 4], "big", signed=True)
            hits.append(pc + 2 + d)
        elif d8 != 0xff:
            d = d8 - 256 if d8 > 127 else d8
            hits.append(pc + 2 + d)
    if w in (0x4eb9, 0x4ef9):
        hits.append(int.from_bytes(rom[pc + 2:pc + 6], "big"))
    for t in hits:
        for a, b in ranges:
            if a <= t < b:
                print(f"0x{pc:x}: word 0x{w:04x} -> 0x{t:x}")
