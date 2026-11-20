"""Re-read the dump values the wave-13 comments quote. For each new row: the RAM dump (ROM image below 0x3f0000) at the
row's width (byte 1, word / i16 2, dword 4; byte[N] reads N bytes), and every number the comment quotes as a dump
value ("<n> here", "<n> = ... here", "dump <n>", "dump 0x<h>"). Prints only rows where no quoted number equals the
value (raw unsigned, raw signed, or one byte of an array).
usage: check_quoted_dump_values_W13.py <stage8 dir> <CM848 analysis dir> [--negative: read 2 bytes off, every row should fail]"""
import json
import os
import re
import sys

here, analysis = sys.argv[1:3]
ram = open(os.path.join(analysis, "originals", "cm848_ram.bin"), "rb").read()
rom = open(os.path.join(analysis, "originals", "cm848_rom.bin"), "rb").read()
rows = {}
for line in open(os.path.join(analysis, "output", "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + ["", ""])[:4]
        rows[name] = (int(address, 16), typ, comment)
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}
checked = mismatches = 0
import csv as _csv
NEGATIVE = "--negative" in sys.argv
for row in _csv.DictReader(open(os.path.join(here, "map_stage8.csv"))):
    name = row["name"]
    address, typ, comment = rows[name]
    m = re.match(r"byte\[(\d+)\]$", typ)
    size = int(m.group(1)) if m else WIDTH.get(typ, 2)
    data, at = (rom, address) if address < 0x3f0000 else (ram, address - 0x3FA000)
    at += 2 if NEGATIVE else 0
    raw = data[at:at + size]
    if len(raw) < size:
        continue
    candidates = set()
    if m:
        candidates |= set(raw)
    else:
        u = int.from_bytes(raw, "big")
        candidates |= {u, int.from_bytes(raw, "big", signed=True)}
    quoted = []
    for q in re.findall(r"(-?0x[0-9a-fA-F]+|-?\d+)(?: = [^;()]{0,40})? here\b", comment):
        quoted.append(q)
    for q in re.findall(r"\bdump (?:value )?(?:is |=\s*)?(-?0x[0-9a-fA-F]+|-?\d+)\b", comment):
        quoted.append(q)
    if not quoted:
        continue
    checked += 1
    values = {int(q, 16) if "0x" in q.lower() else int(q) for q in quoted}
    if not values & candidates:
        mismatches += 1
        print(f"{address:#x} {name} [{typ}] dump {sorted(candidates)[:4]} quoted {sorted(values)[:4]} | {comment[:120]}")
print(f"{checked} rows quote a dump value; {mismatches} without a match")
