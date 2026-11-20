"""For every row whose name is in a stage map and whose comment quotes a dump value ("... here"), print the RAM-dump
value at the declared width (word / i16; ROM below 0x3f0000 from the ROM image) next to the comment's text, plus the
named enable words. For checking by eye.
usage: check_here_values.py <CM848 output dir> <originals dir> <map.csv> [name...]"""
import csv
import os
import re
import struct
import sys

out, originals, map_path = sys.argv[1:4]
extra = sys.argv[4:]
ram = open(os.path.join(originals, "cm848_ram.bin"), "rb").read()
rom = open(os.path.join(originals, "cm848_rom.bin"), "rb").read()
names = {r["name"] for r in csv.DictReader(open(map_path))} | set(extra)
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if not line.startswith("0x"):
        continue
    address, name, typ, comment = (line.rstrip("\n").split(",", 3) + [""])[:4]
    if name not in names or not (" here" in comment or name in extra):
        continue
    a = int(address, 16)
    size = 1 if typ == "byte" else 2
    if a < 0x3f0000:
        raw = rom[a:a + size]
    else:
        raw = ram[a - 0x3FA000:a - 0x3FA000 + size]
    value = raw[0] if size == 1 else struct.unpack(">H", raw)[0]
    signed = value - 65536 if typ == "i16" and value > 32767 else value
    quotes = re.findall(r"[^;()]{0,40}\bhere\b", comment)
    print(f"{address} {name[:58]:58s} {typ:6s} dump={signed} (0x{value:x}) | {' / '.join(q.strip() for q in quotes)[:110]}")
