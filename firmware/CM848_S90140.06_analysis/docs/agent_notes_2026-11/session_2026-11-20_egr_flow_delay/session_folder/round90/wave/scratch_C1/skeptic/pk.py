#!/usr/bin/env python3
"""pk.py ADDR COUNT SIZE(b|w|l) [s]  - read CM550 dumps big-endian.
RAM 0x800000-0x8091c1 (ram.bin at addr-0x800000), ext RAM 0x8092c2+ (extended_ram.bin at addr-0x809242), ROM below."""
import sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(FW + 'J90350.00.ram.bin', 'rb').read()
ext = open(FW + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(FW + 'J90350.00.rom.bin', 'rb').read()
a = int(sys.argv[1], 0)
n = int(sys.argv[2])
k = sys.argv[3]
sg = len(sys.argv) > 4
sz = {'b': 1, 'w': 2, 'l': 4}[k]


def rd(x):
    if 0x800000 <= x < 0x8091c2:
        b = ram
        o = x - 0x800000
    elif x >= 0x8092c2:
        b = ext
        o = x - 0x809242
    elif x < len(rom):
        b = rom
        o = x
    else:
        return None
    if o + sz > len(b):
        return None
    return int.from_bytes(b[o:o + sz], 'big', signed=sg)


v = [rd(a + i * sz) for i in range(n)]
print(hex(a), k, v)
if n <= 24:
    print('   hex', [hex(x) if x is not None else None for x in v])
