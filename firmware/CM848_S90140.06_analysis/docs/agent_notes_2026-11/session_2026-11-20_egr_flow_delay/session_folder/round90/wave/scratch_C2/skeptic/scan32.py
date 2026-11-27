#!/usr/bin/env python3
"""Find every occurrence of the given 32-bit big-endian values (or ranges LO-HI) in the CM550 ROM at any byte offset.
Usage: scan32.py VALUE|LO-HI ..."""
import sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
ranges = []
for r in sys.argv[1:]:
    if '-' in r:
        lo, hi = r.split('-')
        ranges.append((int(lo, 16), int(hi, 16)))
    else:
        v = int(r, 16)
        ranges.append((v, v))
for i in range(0, len(d) - 3):
    v = int.from_bytes(d[i:i + 4], 'big')
    for lo, hi in ranges:
        if lo <= v <= hi:
            print('%06x%s: %08x  before %s | after %s' % (i, '' if i % 2 == 0 else ' (odd)', v, d[max(0, i - 4):i].hex(' '), d[i + 4:i + 8].hex(' ')))
