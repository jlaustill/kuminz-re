#!/usr/bin/env python3
"""Read CM550 RAM / extended RAM / ROM values at given addresses.

usage: peek.py <b|w|l> <addr> [<addr> ...]
"""
import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(BASE + 'J90350.00.ram.bin', 'rb').read()
ext = open(BASE + 'J90350.00.extended_ram.bin', 'rb').read()
rom = open(BASE + 'J90350.00.rom.bin', 'rb').read()


def chunk(a, n):
    if a < 0x40000:
        return rom[a:a + n]
    if 0x800000 <= a and a + n <= 0x800000 + len(ram):
        return ram[a - 0x800000:a - 0x800000 + n]
    if 0x809242 <= a and a + n <= 0x809242 + len(ext):
        return ext[a - 0x809242:a - 0x809242 + n]
    return None


size = sys.argv[1]
n = {'b': 1, 'w': 2, 'l': 4}[size]
fmt = {'b': '>B', 'w': '>H', 'l': '>I'}[size]
for s in sys.argv[2:]:
    a = int(s, 16)
    c = chunk(a, n)
    if c is None or len(c) < n:
        print(hex(a), 'not dumped')
        continue
    v = struct.unpack(fmt, c)[0]
    sv = v - (1 << (8 * n)) if v >= (1 << (8 * n - 1)) else v
    print(hex(a), hex(v), v, 'signed', sv)
