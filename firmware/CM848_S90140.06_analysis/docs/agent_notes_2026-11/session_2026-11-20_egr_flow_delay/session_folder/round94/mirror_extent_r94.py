"""Round 94 (read-only): how far CM550's EEPROM RAM mirror reaches. Compares the RAM dump (base 0x800000) from
0x803B0A with the EEPROM dump byte by byte and reports the runs where they agree, plus the copy lengths the ROM
uses with the mirror base (any long immediate next to 0x803b0a / 0x01000000 references).
usage: mirror_extent_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
F = os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware")
ram = open(os.path.join(F, "J90350.00.ram.bin"), "rb").read()
eep = open(os.path.join(F, "J90350.00.eeprom.bin"), "rb").read()
rom = open(os.path.join(F, "J90350.00.rom.bin"), "rb").read()
MIRROR = 0x803B0A
print(f"EEPROM dump {len(eep)} bytes; RAM dump {len(ram)} bytes (to 0x{0x800000 + len(ram):x})")
base = MIRROR - 0x800000
n = min(len(eep), len(ram) - base)
runs, start, agree = [], None, 0
for i in range(n):
    same = ram[base + i] == eep[i]
    agree += same
    if same and start is None:
        start = i
    if not same and start is not None:
        runs.append((start, i))
        start = None
if start is not None:
    runs.append((start, n))
long_runs = [(a, b) for a, b in runs if b - a >= 16]
print(f"bytes compared: {n}; equal: {agree} ({100 * agree / n:.1f} %)")
print("equal runs of 16+ bytes (EEPROM offset ranges):", ", ".join(f"0x{a:x}-0x{b - 1:x}" for a, b in long_runs[:40]))
last = max((b for a, b in long_runs), default=0)
print(f"last long equal run ends at EEPROM offset 0x{last - 1:x} = RAM 0x{MIRROR + last - 1:x}")
for off in (0x64C, 0x65A, 0x729):
    print(f"EEPROM 0x{off:x}: RAM 0x{MIRROR + off:x} = {ram[base + off]:02x} / EEPROM {eep[off]:02x}")
for pat in (MIRROR.to_bytes(4, "big"), (0x01000000).to_bytes(4, "big")):
    i = rom.find(pat)
    while i != -1:
        ctx = rom[max(0, i - 8):i + 12].hex(" ")
        print(f"ROM 0x{i:x}: {pat.hex()} | {ctx}")
        i = rom.find(pat, i + 1)
