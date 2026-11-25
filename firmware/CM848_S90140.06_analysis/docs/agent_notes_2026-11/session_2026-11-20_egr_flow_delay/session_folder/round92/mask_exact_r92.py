"""Round 92 stage A proof (read-only): every token-diff census entry that turns a mask test into a bitfield name,
"( <old> & <mask> ) => <row> . <field>" (with or without the parentheses), is checked against the firmware's
structure_definitions.csv: the field's bit must be the mask's single bit, and the row must be the word the old label
was (by the rename map, or DAT_<address>). usage: mask_exact_r92.py <token_diff.txt> <structure_definitions.csv>
<global_variables.csv> <map.csv>"""
import csv
import re
import sys

census, structs_path, globals_path, map_path = sys.argv[1:5]
bits = {}
for row in csv.reader(open(structs_path, newline="")):
    if len(row) > 3:
        m = re.match(r"^bitfield:1@(\d+)$", row[3])
        if m:
            bits.setdefault(row[0], {})[row[2]] = int(m.group(1))
rows = {r[1]: (int(r[0], 16), r[2]) for r in csv.reader(open(globals_path, newline="")) if r and r[0].startswith("0x")}
old_to_new = {r[2]: r[1] for r in csv.reader(open(map_path, newline="")) if r and r[0].startswith("0x")}
pat = re.compile(r"^\s*(\d+)\s+\(?\s*_?(\w+) & (0x[0-9a-f]+|\d+)\s*\)?\s*=>\s*(\w+) \. (\w+)\s*$")
ok = bad = 0
inside = False
for line in open(census):
    if line.startswith("---- census"):
        inside = True
        continue
    if not inside:
        continue
    m = pat.match(line.rstrip("\n"))
    if not m:
        continue
    count, old, mask, row, field = int(m.group(1)), m.group(2), int(m.group(3), 0), m.group(4), m.group(5)
    address, typ = rows[row]
    expected_row = old_to_new.get(old) or (row if old.lower() == f"dat_{address:08x}" else None)
    bit = bits.get(typ, {}).get(field)
    good = (mask & (mask - 1)) == 0 and bit is not None and (1 << bit) == mask and expected_row == row
    ok += count if good else 0
    bad += 0 if good else count
    if not good:
        print("MISMATCH:", line.strip(), "| field bit", bit, "| expected row", expected_row)
print(f"{ok} mask tests became the field of that exact bit on the same word; {bad} mismatches")
