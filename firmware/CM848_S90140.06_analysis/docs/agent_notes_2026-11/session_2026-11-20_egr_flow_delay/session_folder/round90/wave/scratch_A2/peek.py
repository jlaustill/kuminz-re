#!/usr/bin/env python3
"""Peek big-endian values in a CM550 dump.
usage: peek.py <file> <base> <address> <width> [<address> <width> ...]
The file offset is address - base."""
import sys

data = open(sys.argv[1], 'rb').read()
base = int(sys.argv[2], 16)
args = sys.argv[3:]
for k in range(0, len(args), 2):
    addr = int(args[k], 16)
    width = int(args[k + 1])
    off = addr - base
    raw = data[off:off + width]
    print(f"0x{addr:08x} w{width}: {raw.hex()} = {int.from_bytes(raw, 'big')}")
