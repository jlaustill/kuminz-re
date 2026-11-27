"""List every big-endian 4-byte occurrence of each builder address in a ROM image (pea / move.l #imm / tables).
usage: find_refs.py <rom.bin> <base hex> name=0xADDR [name=0xADDR ...]"""
import sys

data = open(sys.argv[1], "rb").read()
base = int(sys.argv[2], 16)
for arg in sys.argv[3:]:
    name, value = arg.split("=")
    target = int(value, 16)
    needle = target.to_bytes(4, "big")
    hits = []
    i = data.find(needle)
    while i != -1:
        hits.append(f"{base + i:#x}(prev {data[max(0, i - 2):i].hex()})")
        i = data.find(needle, i + 1)
    print(name, hex(target), " ".join(hits) if hits else "NONE")
