"""Round 39 closing checks.
1. _cal names outside the EEPROM mirror (0x3fd482-0x3feec1) in arrays.csv and structure_definitions.csv instance rows.
2. Where the RAM dump bytes around 0x3ff6ce / 0x3ff6d8 / 0x3ffca2 also occur in ROM or flash2.
3. The extent of the RAM = ROM + 0x39a3e6 copy around 0x40713a-0x409576 (word-by-word walk; stops at the first run of
   16 mismatching words).  usage: closing_checks.py <analysis dir>"""
import csv
import os
import sys

d = sys.argv[1]
out = os.path.join(d, "output")
print("== 1. _cal outside the mirror")
for fn in ("arrays.csv", "structure_definitions.csv"):
    for row in csv.reader(open(os.path.join(out, fn), errors="replace")):
        if not row or row[0].startswith("#"):
            continue
        cells = [c for c in row if "_cal" in c]
        addr = next((c for c in row if c.startswith("0x")), None)
        if cells and addr:
            a = int(addr, 16)
            names = [c for c in row[:3] if "_cal" in c]
            if names and not (0x3fd482 <= a <= 0x3feec1) and a < 0x1000000:
                print(fn, addr, names)
ram = open(os.path.join(d, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(d, "originals/cm848_rom.bin"), "rb").read()
fl2 = open(os.path.join(d, "originals/cm848_flash2_live.bin"), "rb").read()
print("== 2. sources of the 0x3ffxxx rows")
for a in (0x3ff6ce, 0x3ff6d8, 0x3ffca2):
    for lo, hi in ((-16, 16), (-8, 8), (-4, 4)):
        b = ram[a + lo - 0x3FA000:a + hi - 0x3FA000]
        hr = [hex(i - lo) for i in range(len(rom)) if rom.startswith(b, i)][:3]
        hf = [hex(0x500000 + i - lo) for i in range(len(fl2)) if fl2.startswith(b, i)][:3]
        print(f"{a:#x} window {hi - lo} bytes ({b.hex()}): rom {hr} flash2 {hf}")
        if hr or hf:
            break
print("== 3. the extent of RAM = ROM + 0x39a3e6")
OFF = 0x39a3e6


def match(a):
    r = a - 0x3FA000
    o = a - OFF
    return 0 <= o < len(rom) - 1 and ram[r:r + 2] == rom[o:o + 2]


for start, step in ((0x40713a, -2), (0x409576, 2)):
    a, last, miss = start, start, 0
    while 0x3fa000 < a < 0x40c1fe and miss < 16:
        if match(a):
            last, miss = a, 0
        else:
            miss += 1
        a += step
    print(f"from {start:#x} going {'down' if step < 0 else 'up'}: last matching word {last:#x}")
lo, hi = 0x406000, 0x40a400
words = (hi - lo) // 2
same = sum(match(a) for a in range(lo, hi, 2))
print(f"{lo:#x}-{hi:#x}: {same} of {words} words match ROM at RAM - 0x39a3e6")
