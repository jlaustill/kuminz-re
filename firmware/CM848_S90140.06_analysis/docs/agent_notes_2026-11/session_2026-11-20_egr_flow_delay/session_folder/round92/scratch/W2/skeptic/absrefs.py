"""Skeptic: every occurrence of a 32-bit big-endian address in [lo, hi] in the CM550 ROM, at any byte offset
(even offsets are the instruction-aligned ones), with raw context bytes for hand decoding.
usage: absrefs.py <rom> <lo hex> <hi hex>"""
import sys

rom = open(sys.argv[1], "rb").read()
lo = int(sys.argv[2], 16)
hi = int(sys.argv[3], 16)
hits = []
for off in range(0, len(rom) - 3):
    v = int.from_bytes(rom[off:off + 4], "big")
    if lo <= v <= hi:
        hits.append((off, v))
print(f"{len(hits)} occurrences of 0x{lo:x}..0x{hi:x}")
for off, v in hits:
    before = rom[max(0, off - 8):off].hex()
    after = rom[off + 4:off + 16].hex()
    align = "even" if off % 2 == 0 else "ODD "
    print(f"0x{off:05x} {align} addr=0x{v:x}  before={before}  after={after}")
