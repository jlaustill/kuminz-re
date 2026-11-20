"""Read-only scratch helper: join e2m records of the given block ids with the ECU's flash2 {ID, address} table and the
current global_variables.csv names.  usage: join_e2m.py <originals dir> <e2m file> <global_variables.csv> <block id hex>..."""
import csv
import sys

originals, e2m_path, globals_path = sys.argv[1:4]
wanted = {int(b, 16) for b in sys.argv[4:]}
flash2 = open(f"{originals}/cm848_flash2_live.bin", "rb").read()
base = 0x500000
table = {}
for off in range(0x53BE38 - base, 0x53EA6C - base, 6):
    block_id = int.from_bytes(flash2[off:off + 2], "big")
    address = int.from_bytes(flash2[off + 2:off + 6], "big")
    if block_id or address:
        table[block_id] = address
names = {}
with open(globals_path) as handle:
    for line in handle:
        parts = line.rstrip("\n").split(",", 3)
        if len(parts) >= 3 and parts[0].startswith("0x"):
            names.setdefault(int(parts[0], 16), (parts[1], parts[2]))
rows = []
with open(e2m_path, errors="replace") as handle:
    for line in handle:
        fields = line.split(";")[0].split(",")
        if len(fields) < 10:
            continue
        try:
            block = int(fields[2], 16)
            offset = int(fields[3], 16)
        except ValueError:
            continue
        if block not in wanted or block not in table:
            continue
        address = table[block] + offset
        if 0x1000000 <= address < 0x1002000:
            mirrored = address - 0xC02B7E
        else:
            mirrored = address
        current = names.get(mirrored)
        rows.append((block, offset, address, mirrored, fields[0], fields[1], fields[7], current))
rows.sort(key=lambda r: (r[0], r[1]))
for block, offset, address, mirrored, name, unit, size, current in rows:
    print(f"{block:04X}+{offset:02X} {hex(mirrored):10} {name:34} {unit:9} {size}B  now: {current[0] if current else '-'} ({current[1] if current else ''})")
