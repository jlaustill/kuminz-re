"""Round 90 (read-only): test a layout for CM550's parameter ID table against output/parameter_id_lookup_table.csv.
The ROM holds a run of 8-byte entries (one address, stored twice) at 0x35224-0x38a94. Hypothesis: ids 0x0000-0x002E
are entries 0-46 and ids 0x1000 and up follow from 0x3539c (the 0x1003 entry is at 0x353b4). Also searches the ROM for
a 32-bit pointer to either base. usage: check_cm550_table_layout_r90.py <repo>"""
import csv
import os
import re
import struct
import sys

repo = sys.argv[1]
D = os.path.join(repo, "firmware/CM550_J90350.00_analysis")
rom = open(os.path.join(D, "firmware/J90350.00.rom.bin"), "rb").read()
LOW_BASE, HIGH_BASE, END = 0x35224, 0x3539c, 0x38a94


def entry(pid):
    off = LOW_BASE + 8 * pid if pid < 0x1000 else HIGH_BASE + 8 * (pid - 0x1000)
    if not (LOW_BASE <= off < END) or (pid < 0x1000 and off >= HIGH_BASE):
        return None
    a, b = struct.unpack(">II", rom[off:off + 8])
    return a if a == b else ("pair differs", a, b)


rows = list(csv.DictReader(open(os.path.join(D, "output/parameter_id_lookup_table.csv"), newline="")))
same = differ = outside = 0
bad = []
for r in rows:
    pid, address = int(r["param_id_hex"], 16), int(r["address_hex"], 16)
    got = entry(pid)
    if got is None:
        outside += 1
        bad.append((pid, address, "outside"))
    elif got == address:
        same += 1
    else:
        differ += 1
        bad.append((pid, address, got))
print(f"{len(rows)} CSV rows: {same} match the ROM layout, {differ} differ, {outside} outside it")
for b in bad[:10]:
    print("  ", f"0x{b[0]:04x}", f"0x{b[1]:x}", b[2] if isinstance(b[2], str) else (hex(b[2]) if isinstance(b[2], int) else b[2]))
nonzero_low = sum(1 for p in range(47) if entry(p))
nonzero_high = sum(1 for p in range(0x1000, 0x1000 + (END - HIGH_BASE) // 8) if entry(p))
print(f"ROM non-zero entries: {nonzero_low} low ids, {nonzero_high} high ids (ids 0x1000-0x{0x1000 + (END - HIGH_BASE) // 8 - 1:x})")
for base in (LOW_BASE, HIGH_BASE, HIGH_BASE - 0x8000, LOW_BASE - 8):
    hits = [hex(m.start()) for m in re.finditer(re.escape(base.to_bytes(4, "big")), rom)]
    print(f"pointer 0x{base:x}: {hits[:5]}")
