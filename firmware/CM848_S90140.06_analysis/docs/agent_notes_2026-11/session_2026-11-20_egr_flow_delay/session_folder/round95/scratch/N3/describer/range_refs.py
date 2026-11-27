"""Every even-aligned 4-byte big-endian value in [low, high) in the CM550 ROM, with the opcode word before it.
usage: range_refs.py <rom> <0xLOW> <0xHIGH>"""
import sys

rom = open(sys.argv[1], "rb").read()
low, high = int(sys.argv[2], 16), int(sys.argv[3], 16)
for i in range(2, len(rom) - 4, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if low <= v < high:
        pre = int.from_bytes(rom[i - 2:i], "big")
        print(f"0x{i:05x}: value 0x{v:06x} previous word {pre:04x}")
