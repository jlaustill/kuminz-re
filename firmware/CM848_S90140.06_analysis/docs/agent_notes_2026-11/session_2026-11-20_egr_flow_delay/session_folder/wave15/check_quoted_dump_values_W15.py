"""Re-read the dump values the wave-15 comments quote (from check_quoted_dump_values_W14.py). For each renamed global (the map, kind global): the
RAM dump (ROM image below 0x3f0000) at the row's width, and every number the comment quotes as a raw dump value: "<n> in
the dump", "<n> here", "dump <n>" (but not "dump = <scaled>"). Prints the rows where no quoted number equals the value.
The RAM dump misses 0x80 bytes at 0x40c200-0x40c27f (stage 9 finding): rows from 0x40c280 up are read at address - 0x80,
rows inside the gap are skipped. --negative reads 2 bytes off (every row should fail).
usage: check_quoted_dump_values_W15.py <map csv> <CM848 analysis dir> [--negative]"""
import csv
import os
import re
import sys

here, analysis = sys.argv[1:3]
negative = "--negative" in sys.argv
ram = open(os.path.join(analysis, "originals", "cm848_ram.bin"), "rb").read()
rom = open(os.path.join(analysis, "originals", "cm848_rom.bin"), "rb").read()
rows = {}
for line in open(os.path.join(analysis, "output", "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + ["", ""])[:4]
        rows[name] = (int(address, 16), typ, comment)
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4, "pointer": 4}
enum_sizes = {}
for line in open(os.path.join(analysis, "output", "enums.csv"), errors="replace"):
    size = line.rstrip("\r\n").rsplit(",", 1)[-1]
    if size.isdigit():
        enum_sizes[line.split(",", 1)[0]] = int(size)
QUOTES = [re.compile(r"(-?0x[0-9a-fA-F]+|-?\d+) in the (?:RAM )?dump\b"),
          re.compile(r"(-?0x[0-9a-fA-F]+|-?\d+)(?: = [^;()]{0,40})? here\b"),
          re.compile(r"\bdump (?:value )?(?:is )?(-?0x[0-9a-fA-F]+|-?\d+)\b(?! *=)")]
checked = mismatches = skipped = 0
for r in csv.DictReader(open(here)):
    if r["kind"] != "global" or r["name"] not in rows:
        continue
    address, typ, comment = rows[r["name"]]
    comment = re.sub(r"\| earlier note:.*", "", comment)
    m = re.match(r"(\w+)\[(\d+)\]$", typ)
    size = WIDTH.get(m.group(1), 2) * int(m.group(2)) if m else WIDTH.get(typ, enum_sizes.get(typ, 2))
    if address < 0x3f0000:
        data, at = rom, address
    else:
        if 0x40c200 <= address < 0x40c280:
            skipped += 1
            continue
        data, at = ram, address - 0x3FA000 - (0x80 if address >= 0x40c280 else 0)
    at += 2 if negative else 0
    raw = data[at:at + min(size, 4)] if not m else data[at:at + size]
    if not raw:
        continue
    candidates = set(raw) if m else {int.from_bytes(raw, "big"), int.from_bytes(raw, "big", signed=True)}
    quoted = [q for pattern in QUOTES for q in pattern.findall(comment)]
    if not quoted:
        continue
    checked += 1
    values = {int(q, 16) if "0x" in q.lower() else int(q) for q in quoted}
    if not values & candidates:
        mismatches += 1
        print(f"{address:#x} {r['name']} [{typ}] dump {sorted(candidates)[:4]} quoted {sorted(values)[:4]} | {comment[:110]}")
print(f"{checked} rows quote a dump value; {mismatches} without a match; {skipped} inside the dump gap skipped")
