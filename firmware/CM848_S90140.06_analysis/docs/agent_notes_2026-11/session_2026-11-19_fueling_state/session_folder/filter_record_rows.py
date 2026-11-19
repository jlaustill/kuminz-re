"""For every global record passed as `&NAME` to cm848_signedFirstOrderFilter: its address, the CSV rows at +0..+7,
the coefficient the code stores in it, the non-comment .cpp uses of the +4 row and of any other row inside the 8
bytes, and whether +0 / +4 is in the EEPROM mirror or the ROM-to-RAM window.
usage: filter_record_rows.py <CM848 output dir> <census.txt from filter_call_census.py>"""
import os
import re
import sys

out, census = sys.argv[1:3]
rows = {}
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + [""])[:4]
        rows[int(address, 16)] = (name, typ, comment)
by_name = {v[0]: k for k, v in rows.items() if v[0]}
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
seen = []
for line in open(census):
    m = re.search(r"\| &(\w+)$", line.strip())
    if m and m.group(1) not in seen:
        seen.append(m.group(1))
for symbol in seen:
    m = re.match(r"PTR_DAT_([0-9a-f]{8})$", symbol)
    address = int(m.group(1), 16) if m else by_name.get(symbol)
    if address is None:
        print(f"{symbol}: NO ROW")
        continue
    inside = [(a - address, rows[a][0] or f"DAT_{a:08x}", rows[a][1]) for a in range(address, address + 8) if a in rows]
    init = re.findall(r"\b" + re.escape(symbol) + r"\s*=\s*(?:\([^)]*\)\s*)?&(\w+)", code)
    uses = {}
    for offset, name, _ in inside:
        if offset == 0:
            continue
        uses[name] = len(re.findall(r"\b" + re.escape(name) + r"\b", code))
    flags = []
    if 0x3fd482 <= address <= 0x3feec1:
        flags.append("EEPROM")
    if 0x3f9800 <= address <= 0x3fdb30:
        flags.append("copy-window")
    if address % 2:
        flags.append("ODD")
    print(f"0x{address:06x} {symbol} rows={inside} coefficient={init} other-row-uses={uses} {' '.join(flags)}")
