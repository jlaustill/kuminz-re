"""For each cm848_signedFirstOrderFilter record: the CSV rows at +0 / +4 (and +8 when it is a gap), and every .cpp
line that names the +0 or +4 symbol outside comments, with its function.
usage: filter_records.py <CM848 output dir> <record symbol>..."""
import os
import re
import sys

out, symbols = sys.argv[1], sys.argv[2:]
rows = {}
for line in open(os.path.join(out, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        address, name, typ, comment = (line.rstrip("\n").split(",", 3) + [""])[:4]
        rows[int(address, 16)] = (name, typ, comment)
by_name = {v[0]: k for k, v in rows.items() if v[0]}
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read().split("\n")
function_at = []
current = ""
for line in cpp:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append(current)


def label(address):
    name, typ, comment = rows.get(address, ("", "", ""))
    return name or f"DAT_{address:08x}", typ


for symbol in symbols:
    m = re.match(r"PTR_DAT_([0-9a-f]{8})$", symbol)
    address = int(m.group(1), 16) if m else by_name.get(symbol)
    if address is None:
        print(f"== {symbol}: no row")
        continue
    print(f"== {symbol} @ 0x{address:06x}")
    names = []
    for offset in (0, 4):
        name, typ = label(address + offset)
        in_csv = address + offset in rows
        print(f"   +{offset}: {name} ({typ or 'no row'}) {rows.get(address + offset, ('', '', ''))[2][:110]}")
        names.append(name if in_csv else None)
    gap = [a for a in range(address + 1, address + 8) if a in rows and a != address + 4]
    if gap:
        print(f"   rows inside the 8 bytes: {[hex(a) + ' ' + rows[a][0] for a in gap]}")
    pattern = re.compile(r"\b(" + "|".join(re.escape(n) for n in names + [symbol] if n) + r")\b")
    for i, line in enumerate(cpp):
        s = line.strip()
        if s.startswith(("//", "/*", "*")) or not pattern.search(line):
            continue
        print(f"   {i + 1} [{function_at[i]}] {s[:120]}")
