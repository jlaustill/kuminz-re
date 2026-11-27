"""For the rows check_quoted_dump_values_W15.py flags, print each quoted-dump snippet with context and the dump value
at the row's width (big-endian, unsigned and signed), so a misread can be told from a regex false hit.
usage: dump_mismatch_context_W15.py <check output file> <CM848 analysis dir>"""
import os
import re
import sys

check_out, analysis = sys.argv[1:3]
ram = open(os.path.join(analysis, "originals", "cm848_ram.bin"), "rb").read()
rom = open(os.path.join(analysis, "originals", "cm848_rom.bin"), "rb").read()
rows = {}
for line in open(os.path.join(analysis, "output", "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + ["", ""])[:4]
        rows[name] = (int(address, 16), typ, re.sub(r"\| earlier note:.*", "", comment))
QUOTES = re.compile(r"(-?0x[0-9a-fA-F]+|-?\d+) in the (?:RAM )?dump\b|(-?0x[0-9a-fA-F]+|-?\d+)(?: = [^;()]{0,40})? here\b"
                    r"|\bdump (?:value )?(?:is )?(-?0x[0-9a-fA-F]+|-?\d+)\b(?! *=)")
for line in open(check_out):
    m = re.match(r"(0x[0-9a-f]+) (\S+) \[", line)
    if not m:
        continue
    address, typ, comment = rows[m.group(2)]
    at = address if address < 0x3f0000 else address - 0x3FA000 - (0x80 if address >= 0x40c280 else 0)
    data = rom if address < 0x3f0000 else ram
    b1, b2, b4 = data[at], int.from_bytes(data[at:at + 2], "big"), int.from_bytes(data[at:at + 4], "big")
    print(f"{m.group(1)} {m.group(2)} [{typ}] byte {b1} word {b2} ({b2 - 65536 if b2 > 32767 else b2}) dword {b4:#x}")
    for q in QUOTES.finditer(comment):
        print(f"    ...{comment[max(0, q.start() - 70):q.end() + 15]}...")
