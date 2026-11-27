#!/usr/bin/env python3
"""usage: peek.py ADDR [count] [w|b|l]  - read CM550 RAM/extended RAM/ROM dump at the address (big-endian)."""
import sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(FW + 'J90350.00.ram.bin', 'rb').read()
ext = open(FW + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(FW + 'J90350.00.rom.bin', 'rb').read()
a = int(sys.argv[1], 0)
n = int(sys.argv[2]) if len(sys.argv) > 2 else 1
k = sys.argv[3] if len(sys.argv) > 3 else 'w'
sz = {'b': 1, 'w': 2, 'l': 4}[k]


def rd(addr):
    if 0x800000 <= addr < 0x8091c2:
        o = addr - 0x800000
        buf = ram
    elif addr >= 0x8092c2:
        o = addr - 0x809242
        buf = ext
    elif addr < 0x40000:
        o = addr
        buf = rom
    else:
        return None
    return int.from_bytes(buf[o:o + sz], 'big')


vals = [rd(a + i * sz) for i in range(n)]
print(hex(a), k, vals, [hex(v) if v is not None else None for v in vals] if n <= 16 else '')
