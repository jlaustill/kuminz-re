"""Offline refresh audit for a committed stage: for each row kept under the same key (address + name) in both
versions whose text changed, print the changed span. Rows the stage renamed or added (the map's addresses) are
skipped. usage: refresh_diff_offline.py <map.csv> <before.csv> <after.csv>"""
import csv
import difflib
import sys

map_path, before_path, after_path = sys.argv[1:4]
renamed = {r["address"].lower() for r in csv.DictReader(open(map_path)) if r.get("address")}


def keyed(path):
    rows = {}
    for line in open(path).read().split("\n"):
        parts = line.split(",", 2)
        if len(parts) >= 2 and parts[0].lower().startswith("0x"):
            rows[(parts[0].lower(), parts[1])] = line
    return rows


b, a = keyed(before_path), keyed(after_path)
n = 0
for key in sorted(set(b) & set(a)):
    if key[0] in renamed or b[key] == a[key]:
        continue
    for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, b[key], a[key], autojunk=False).get_opcodes():
        if op != "equal":
            n += 1
            print(f"{key[0]} {key[1]}: ...{b[key][max(i1 - 40, 0):i1]}[{b[key][i1:i2]} -> {a[key][j1:j2]}]")
print(f"{n} changed spans in kept rows")
