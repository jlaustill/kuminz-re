#!/usr/bin/env python3
"""Print a ROM range as 16-bit words with their addresses (for hand decoding).
usage: words.py <rom> <start hex> <end hex>"""
import sys

rom = open(sys.argv[1], 'rb').read()
start = int(sys.argv[2], 16)
end = int(sys.argv[3], 16)
line = []
for a in range(start, end, 2):
    if (a - start) % 16 == 0:
        if line:
            print(' '.join(line))
        line = [f"{a:06x}:"]
    line.append(f"{int.from_bytes(rom[a:a + 2], 'big'):04x}")
if line:
    print(' '.join(line))
