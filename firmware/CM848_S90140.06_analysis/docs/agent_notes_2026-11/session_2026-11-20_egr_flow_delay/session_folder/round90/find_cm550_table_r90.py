"""Round 90 (read-only): find CM550's parameter ID table in the ROM around the record for id 0x1003 (0x353b2) and
compare it with output/parameter_id_lookup_table.csv. A record is [id u16][address u32], big-endian (CM848's format).
usage: find_cm550_table_r90.py <repo>"""
import csv
import os
import struct
import sys

repo = sys.argv[1]
D = os.path.join(repo, "firmware/CM550_J90350.00_analysis")
rom = open(os.path.join(D, "firmware/J90350.00.rom.bin"), "rb").read()
anchor = 0x353b2
assert struct.unpack(">HI", rom[anchor:anchor + 6]) == (0x1003, 0x806ae2), rom[anchor:anchor + 6].hex()


def plausible(off):
    if off < 0 or off + 6 > len(rom):
        return False
    pid, address = struct.unpack(">HI", rom[off:off + 6])
    return (0x800000 <= address < 0x810000 or 0x1000000 <= address < 0x1001000 or address < 0x40000) and pid != 0xffff


start = anchor
while plausible(start - 6):
    start -= 6
end = anchor
while plausible(end):
    end += 6
records = [struct.unpack(">HI", rom[o:o + 6]) for o in range(start, end, 6)]
print(f"run 0x{start:x}-0x{end:x}: {len(records)} records; first {records[0][0]:04x}->{records[0][1]:x}, "
      f"last {records[-1][0]:04x}->{records[-1][1]:x}")
print("bytes before:", rom[start - 8:start].hex(), " after:", rom[end:end + 8].hex())
rows = [(int(r["param_id_hex"], 16), int(r["address_hex"], 16))
        for r in csv.DictReader(open(os.path.join(D, "output/parameter_id_lookup_table.csv"), newline=""))]
rom_map = {}
for pid, address in records:
    rom_map.setdefault(pid, address)
csv_map = dict(rows)
print(f"CSV {len(rows)} rows / {len(csv_map)} ids; ROM {len(rom_map)} ids; same address {sum(1 for k, v in csv_map.items() if rom_map.get(k) == v)}; "
      f"CSV-only {len(set(csv_map) - set(rom_map))}; ROM-only {len(set(rom_map) - set(csv_map))}; "
      f"differ {sum(1 for k, v in csv_map.items() if k in rom_map and rom_map[k] != v)}")
order = [pid for pid, _ in records]
print("sorted by id:", order == sorted(order), " duplicates:", len(order) - len(set(order)))
