"""Scan a ROM byte range for m68k ops through an address register (cmpi / clr / addq on (aN)) and print each with its
size: shows the width of a variable the code reaches through movea.l #address,aN.
usage: m68k_register_ops.py <rom.bin> <start hex> <end hex> <register 0-7>"""
import sys

rom = open(sys.argv[1], "rb").read()
start, end, reg = int(sys.argv[2], 16), int(sys.argv[3], 16), int(sys.argv[4])
span = rom[start:end]
ops = {}
for size, bits in (("b", 0), ("w", 1), ("l", 2)):
    ea = 0x10 | reg  # (aN)
    ops[f"cmpi.{size} #imm,(a{reg})"] = (0x0C00 | (bits << 6) | ea).to_bytes(2, "big")
    ops[f"clr.{size} (a{reg})"] = (0x4200 | (bits << 6) | ea).to_bytes(2, "big")
    ops[f"addq.{size} #1,(a{reg})"] = (0x5200 | (bits << 6) | ea).to_bytes(2, "big")
for name, code in ops.items():
    hits, i = [], span.find(code)
    while i != -1:
        hits.append(f"{start + i:#x}" + (f" imm {span[i + 2:i + 4].hex()}" if name.startswith("cmpi") else ""))
        i = span.find(code, i + 1)
    if hits:
        print(name, hits)
