#!/usr/bin/env python3
"""Scan the CM550 ROM for the priority-gated output write idiom
    tst.b (d16,An) ; bne.s ; clr.b (d16,An)
and the absolute form
    tst.b (xxx).l ; bne.s ; clr.b (xxx).l
and report the displacement / address and the An register, so every gated
write of an override slot can be listed with its function.
usage: find_gated_writes.py <rom> <function_renames.csv>"""
import bisect
import csv
import sys

rom = open(sys.argv[1], 'rb').read()
functions = []
with open(sys.argv[2]) as f:
    for row in csv.reader(f):
        if not row or not row[0].startswith('0x'):
            continue
        functions.append((int(row[0], 16), row[1]))
functions.sort()
starts = [a for a, _ in functions]


def owner(address):
    k = bisect.bisect_right(starts, address) - 1
    return functions[k][1] if k >= 0 else '?'


def word(i):
    return int.from_bytes(rom[i:i + 2], 'big')


for i in range(0, len(rom) - 12, 2):
    w = word(i)
    # tst.b (d16,An) = 0100 1010 00 101 rrr = 0x4a28 | r
    if (w & 0xfff8) == 0x4a28:
        reg = w & 7
        disp = word(i + 2)
        b = word(i + 4)
        if (b & 0xff00) == 0x6600:
            j = i + 6
            c = word(j)
            # clr.b (d16,An) = 0100 0010 00 101 rrr = 0x4228 | r
            if (c & 0xfff8) == 0x4228 and word(j + 2) == disp:
                print(f"0x{i:06x} {owner(i)}: tst.b/clr.b ({disp:#x},a{reg}) [same reg: {(c & 7) == reg}]")
    # tst.b (xxx).l = 0x4a39
    if w == 0x4a39:
        addr = int.from_bytes(rom[i + 2:i + 6], 'big')
        b = word(i + 6)
        if (b & 0xff00) == 0x6600 and word(i + 8) == 0x4239 and int.from_bytes(rom[i + 10:i + 14], 'big') == addr:
            print(f"0x{i:06x} {owner(i)}: tst.b/clr.b 0x{addr:08x}.l")
