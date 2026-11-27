"""Round 90 (read-only): how many CM848 audit records read their dump value from 0x40c280 or above (the RAM dump gap),
and for how many the old contiguous read (0x80 bytes too far on) gives another value / another in-range verdict.
usage: gap_effect_r90.py <repo> <audit_cm848.csv>"""
import csv
import os
import sys

repo, audit = sys.argv[1], sys.argv[2]
ram = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin"), "rb").read()
rows = list(csv.DictReader(open(audit, newline="")))
hit = changed = verdict = 0
for r in rows:
    a = int(r["address"], 16)
    size = int(r["size"])
    if not (0x40C280 <= a < 0x440000) or size not in (1, 2, 4):
        continue
    hit += 1
    old_at = a - 0x3FA000
    old = int.from_bytes(ram[old_at:old_at + size], "big", signed=r["signed"] == "S") if old_at + size <= len(ram) else None
    new = int(r["dump_raw"]) if r["dump_raw"] != "" else None
    if old != new:
        changed += 1
        try:
            scale, low, high = float(r["scale"]), float(r["min"]), float(r["max"])
            o = "" if old is None else ("yes" if low - 1e-9 <= old * scale <= high + 1e-9 else "no")
            if o != r["dump_in_range"]:
                verdict += 1
        except ValueError:
            pass
print(f"{hit} records at 0x40c280+; {changed} read another value now; {verdict} change their in-range verdict")
