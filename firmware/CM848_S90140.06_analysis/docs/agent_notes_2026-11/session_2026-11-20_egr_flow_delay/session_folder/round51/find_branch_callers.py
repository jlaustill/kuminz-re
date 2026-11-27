"""Find every bl (opcode 18, LK=1, relative) in the CM848 ROM / live flash2 whose target is the given address, and
print the three instruction words before each.  usage: find_branch_callers.py <originals dir> <target hex>"""
import os
import sys

d, target = sys.argv[1], int(sys.argv[2], 16)
for name, base in (("cm848_rom.bin", 0), ("cm848_flash2_live.bin", 0x500000)):
    data = open(os.path.join(d, name), "rb").read()
    for i in range(0, len(data) - 3, 4):
        w = int.from_bytes(data[i:i + 4], "big")
        if w >> 26 != 18 or w & 3 != 1:
            continue
        off = w & 0x03FFFFFC
        if off & 0x02000000:
            off -= 0x04000000
        if base + i + off == target:
            before = " | ".join(f"{int.from_bytes(data[k:k + 4], 'big'):08x}" for k in range(i - 12, i, 4))
            print(f"{name} {base + i:#08x}: bl {target:#x}   previous words: {before}")
