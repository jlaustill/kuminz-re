#!/usr/bin/env python3
"""Count absolute-long references (big-endian 32-bit operand) to each address
in a range, in the CM550 ROM. Usage: absrefs.py START END"""
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
data = open(ROM, 'rb').read()
start = int(sys.argv[1], 0)
end = int(sys.argv[2], 0)
for a in range(start, end + 1):
    pat = a.to_bytes(4, 'big')
    hits = []
    i = data.find(pat)
    while i != -1:
        hits.append(i)
        i = data.find(pat, i + 1)
    print('0x%06x %2d %s' % (a, len(hits), ' '.join('0x%05x' % h for h in hits)))
