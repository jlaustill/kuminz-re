#!/usr/bin/env python3
"""Scan the CM550 ROM for any 32-bit big-endian value inside the given address ranges (at even offsets).
Usage: scanrange.py LO-HI [LO-HI ...]  (hex, inclusive)"""
import sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
ranges = []
for r in sys.argv[1:]:
    lo, hi = r.split('-')
    ranges.append((int(lo, 16), int(hi, 16)))
for i in range(0, len(d) - 3, 2):
    v = int.from_bytes(d[i:i + 4], 'big')
    for lo, hi in ranges:
        if lo <= v <= hi:
            print('%06x: %06x  context %s | %s' % (i, v, d[i - 6:i].hex(' '), d[i + 4:i + 8].hex(' ')))
