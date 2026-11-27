"""Round 90 stage C: add the rows apply_r90c.py removed (inside the new arrays, no reference in the .cpp) to the
refresh map, each mapped to its element of the covering array (<array>[i], or <array>[i]+n for an odd offset), so a
comment that cites the old row names the element. usage: extend_map_r90c.py <repo> <report.txt> <map.csv>"""
import csv
import os
import re
import sys

repo, report, map_path = sys.argv[1], sys.argv[2], sys.argv[3]
rows = [r for r in csv.reader(open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"),
                                    newline="")) if r and r[0].startswith("0x")]
SIZES = {"byte": 1, "char": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4}
arrays = []
for r in rows:
    m = re.match(r"^(\w+)\[(\d+)\]$", r[2])
    if m and m.group(1) in SIZES:
        arrays.append((int(r[0], 16), r[1], SIZES[m.group(1)], int(m.group(2))))
existing = open(map_path).read()
added = 0
with open(map_path, "a") as fh:
    for line in open(report):
        m = re.match(r"^removed (0x[0-9a-f]+) (\S+) ", line)
        if not m:
            continue
        a, old = int(m.group(1), 16), m.group(2)
        for base, name, size, count in arrays:
            if base < a < base + size * count:
                index, rest = divmod(a - base, size)
                new = f"{name}[{index}]" + (f"+{rest}" if rest else "")
                if f",{old}," not in existing:
                    fh.write(f"0x{a:08x},{new},{old},symbol,1\n")
                    added += 1
                break
print(added, "removed rows added to the map")
