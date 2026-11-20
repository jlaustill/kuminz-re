"""Read the seven fuel pressure governor / fuel metering gain blocks from the RAM dump at their field widths, and check
them against the e2m: window widths positive >= 0 and negative <= 0, gains inside the record's min..max (scaled).
usage: read_gain_blocks.py <CM848 analysis dir> <audit csv>"""
import csv
import os
import sys

analysis, audit = sys.argv[1:3]
ram = open(os.path.join(analysis, "originals", "cm848_ram.bin"), "rb").read()
records = {}
for r in csv.DictReader(open(audit)):
    records[int(r["address"], 16)] = r
BLOCKS = [("8014", 0x4094a2, False), ("8015", 0x4094b2, False), ("80EF", 0x4094c2, True), ("8016", 0x4094d4, False),
          ("8017", 0x4094e4, False), ("8018", 0x4094f4, False), ("80F2", 0x409504, True)]
FIELDS = [("small_signal_gain", 4, False), ("positive_large_signal_gain", 4, False),
          ("negative_large_signal_gain", 4, False), ("positive_window_width", 2, True), ("negative_window_width", 2, True)]
problems = 0
for block, base, derivative in BLOCKS:
    fields = ([("filter_coefficient", 2, False)] if derivative else []) + FIELDS
    at, parts = base, []
    for name, size, signed in fields:
        raw = int.from_bytes(ram[at - 0x3FA000:at - 0x3FA000 + size], "big", signed=signed)
        r = records.get(at)
        assert r is not None and r["block"] == block and int(r["size"]) == size, (block, hex(at), name, r and r["record"])
        value = raw * float(r["scale"])
        ok = float(r["min"]) - 1e-9 <= value <= float(r["max"]) + 1e-9
        if name == "positive_window_width":
            ok = ok and raw >= 0
        if name == "negative_window_width":
            ok = ok and raw <= 0
        problems += not ok
        parts.append(f"{name}={raw} ({value:.6g} {r['unit']}){'' if ok else ' OUT OF RANGE'}")
        at += size
    print(f"{block} @ {base:#x}: " + "; ".join(parts))
print(f"problems: {problems}")
