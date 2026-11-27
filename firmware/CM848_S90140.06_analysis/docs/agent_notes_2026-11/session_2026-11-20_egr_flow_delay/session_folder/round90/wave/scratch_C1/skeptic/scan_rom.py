#!/usr/bin/env python3
"""Scan the CM550 ROM for 32-bit big-endian absolute addresses inside the proposed array spans (heuristic)."""
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
SPANS = [(0x80539c, 104), (0x805404, 104), (0x805562, 40), (0x80558a, 40), (0x8055da, 40), (0x805602, 40),
         (0x8058d4, 32), (0x8058f4, 32), (0x805914, 64), (0x805954, 64), (0x805a1c, 4), (0x806ed0, 18),
         (0x806ee8, 6), (0x80721e, 18), (0x80794e, 32), (0x807b92, 72)]
for i in range(0, len(d) - 3, 2):
    v = int.from_bytes(d[i:i + 4], 'big')
    for base, size in SPANS:
        if base <= v < base + size:
            print('rom 0x%05x: 0x%06x  (span 0x%x +%d)' % (i, v, base, v - base))
