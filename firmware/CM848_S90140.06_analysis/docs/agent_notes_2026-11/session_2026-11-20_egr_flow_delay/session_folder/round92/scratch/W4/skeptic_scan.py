"""Skeptic (read-only): find every 4-byte big-endian occurrence of each address in [lo, hi] in the CM550 ROM, plus
occurrences of block base addresses, and print the 12 bytes before / 8 after so the instruction can be hand-decoded.
usage: skeptic_scan.py <rom> <lo hex> <hi hex> [<extra addr hex> ...]"""
import sys

rom = open(sys.argv[1], "rb").read()
lo, hi = int(sys.argv[2], 16), int(sys.argv[3], 16)
targets = list(range(lo, hi + 1)) + [int(x, 16) for x in sys.argv[4:]]
for t in targets:
    pat = t.to_bytes(4, "big")
    start = 0
    while True:
        i = rom.find(pat, start)
        if i < 0:
            break
        before = rom[max(0, i - 8):i].hex(" ")
        after = rom[i + 4:i + 12].hex(" ")
        print(f"0x{t:06x} at 0x{i:05x} (even={i % 2 == 0}): [{before}] {pat.hex(' ')} [{after}]")
        start = i + 1
