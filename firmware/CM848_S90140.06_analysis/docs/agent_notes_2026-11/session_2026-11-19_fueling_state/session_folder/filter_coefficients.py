"""For every coefficient a cm848_signedFirstOrderFilter record is pointed at (`RECORD = &C` / `RECORD = (cast)&C` in the
.cpp): the coefficient's row, its other non-comment uses in the .cpp (beyond the record assignments), its direct access
widths (width_census.py), its region and its RAM-dump value (u16, and / 65536).
usage: filter_coefficients.py <CM848 output dir> <census.txt> <all.dis> <width_census.py> <ram.bin>"""
import os
import re
import struct
import subprocess
import sys

out, census, dis, width_census, ram_path = sys.argv[1:6]
rows = {}
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + [""])[:4]
        rows[name or f"DAT_{int(address, 16):08x}"] = (int(address, 16), typ)
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
ram = open(ram_path, "rb").read()
records = []
for line in open(census):
    m = re.search(r"\| &(\w+)$", line.strip())
    if m and m.group(1) not in records:
        records.append(m.group(1))
for record in records:
    for c in sorted(set(re.findall(r"\b" + re.escape(record) + r"\s*=\s*(?:\([^)]*\)\s*)?&(\w+)", code))):
        address, typ = rows.get(c, (None, "?"))
        assigns = len(re.findall(r"=\s*(?:\([^)]*\)\s*)?&" + re.escape(c) + r"\b", code))
        uses = len(re.findall(r"\b" + re.escape(c) + r"\b", code)) - assigns
        width, value = "-", "-"
        if address is not None:
            result = subprocess.run([sys.executable, width_census, dis, hex(address)], capture_output=True, text=True)
            width = result.stdout.strip().split(": ", 1)[-1]
            if 0x3FA000 <= address < 0x3FA000 + len(ram) - 1:
                v = struct.unpack(">H", ram[address - 0x3FA000:address - 0x3FA000 + 2])[0]
                value = f"{v} ({v / 65536:.3f})"
        region = "?" if address is None else ("EEPROM" if 0x3fd482 <= address <= 0x3feec1 else
                                               "flash" if address < 0x3f0000 else "RAM/ROM-copy")
        where = "none" if address is None else hex(address)
        print(f"{record} -> {c} @ {where} {typ} {region} other-uses={uses} widths={width} dump={value}")
