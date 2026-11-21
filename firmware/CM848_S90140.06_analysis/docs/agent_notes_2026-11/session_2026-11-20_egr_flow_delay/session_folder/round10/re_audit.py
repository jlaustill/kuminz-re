"""Build the audit CSV classify_signed_loads.py reads, for the offset-aligned RE blocks (rounds 8-10): one row per e2m
record at block base + offset, with the CSV row's name / type there. usage: re_audit.py <repo> <out.csv>"""
import csv
import os
import re
import sys

repo, out_path = os.path.abspath(sys.argv[1]), sys.argv[2]
E2M = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
GV = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
# block: (base, last offset that aligns)
BLOCKS = {"8BBC": (0x40780c, 0x5c), "8C17": (0x40b102, 0x4a), "8C18": (0x4082f4, 0x98), "8C53": (0x40b100, 0),
          "8BB5": (0x408ae0, 0x4e), "8BBB": (0x4077f6, 0x14), "8BBD": (0x40b0ae, 0x38), "8BB6": (0x40b58c, 0x1a),
          "8BB2": (0x408d60, 0x12)}
rows = {}
for line in open(GV):
    m = re.match(r"^(0x[0-9a-f]{8}),([^,]*),([^,]*),", line)
    if m:
        rows.setdefault(int(m.group(1), 16), (m.group(2), m.group(3)))
out = []
for line in open(E2M, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) < 10 or f[2] not in BLOCKS:
        continue
    base, last = BLOCKS[f[2]]
    off = int(f[3], 16)
    if off > last:
        continue
    addr = base + off
    name, typ = rows.get(addr, ("", ""))
    out.append({"address": f"0x{addr:08x}", "row_name": name, "row_type": typ, "signed": f[9], "size": f[7],
                "inside": "", "status": "named" if name and "." not in name else "unnamed", "block": f[2],
                "offset": f[3], "record": f[0]})
with open(out_path, "w", newline="") as fh:
    w = csv.DictWriter(fh, fieldnames=list(out[0]), lineterminator="\n")
    w.writeheader()
    w.writerows(out)
print(len(out), "records;", sum(1 for r in out if r["signed"] == "S" and r["size"] == "2" and r["row_type"] == "word"),
      "signed 2-byte records on word rows")
