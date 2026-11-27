"""Describer F1 helper (read-only): read CM550 RAM dump values at the declared width.
usage: ramread.py <firmware dir> <hex address>[:b|w|l] ...   (default width: w)"""
import os
import struct
import sys

folder = sys.argv[1]
ram = open(os.path.join(folder, "J90350.00.ram.bin"), "rb").read()
ext = open(os.path.join(folder, "J90350.00.extended_ram.bin"), "rb").read()


def read(address, size):
    if 0x800000 <= address and address + size <= 0x800000 + len(ram):
        return ram[address - 0x800000:address - 0x800000 + size], "ram"
    if 0x809242 <= address and address + size <= 0x809242 + len(ext):
        return ext[address - 0x809242:address - 0x809242 + size], "extended"
    return None, "not dumped"


for arg in sys.argv[2:]:
    text, _, width = arg.partition(":")
    width = width or "w"
    size = {"b": 1, "w": 2, "l": 4}[width]
    address = int(text, 16)
    data, where = read(address, size)
    if data is None:
        print(f"0x{address:06x}:{width} {where}")
        continue
    value = int.from_bytes(data, "big")
    print(f"0x{address:06x}:{width} = 0x{value:0{size * 2}x} ({value}) [{where}]")
