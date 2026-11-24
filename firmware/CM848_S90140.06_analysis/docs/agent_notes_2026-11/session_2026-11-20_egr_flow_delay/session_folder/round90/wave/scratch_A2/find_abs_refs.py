#!/usr/bin/env python3
"""Find absolute-long references to given addresses in the CM550 ROM and show
the opcode words around them (MC68336 big-endian), to read the access width."""
import sys

rom = open(sys.argv[1], 'rb').read()
for a in sys.argv[2:]:
    addr = int(a, 16)
    pat = addr.to_bytes(4, 'big')
    pos = 0
    hits = []
    while True:
        i = rom.find(pat, pos)
        if i < 0:
            break
        hits.append(i)
        pos = i + 1
    print(f"== 0x{addr:08x}: {len(hits)} absolute-long hits")
    for i in hits:
        if i % 2:
            continue  # instructions are word aligned
        ctx = rom[max(0, i - 6):i + 8]
        words = ' '.join(f"{int.from_bytes(ctx[k:k+2], 'big'):04x}" for k in range(0, len(ctx), 2))
        print(f"  at 0x{i:06x}: ... {words}")
