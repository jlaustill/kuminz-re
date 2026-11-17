"""Split wave-8 new rows into stage A (free bytes) and stage B (inside a row that a stage-B retype or split changes).
usage: w8_new_row_overlaps.py <output dir> <aligned...>"""
import json
import re
import sys

out, files = sys.argv[1], sys.argv[2:]
WIDTH = {"byte": 1, "i8": 1, "bool": 1, "char": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4, "pointer": 4, "float": 4}
struct_size = {}
for line in open(f"{out}/structure_definitions.csv"):
    p = line.rstrip("\n").split(",")
    if len(p) > 4 and not line.startswith("#") and p[4].isdigit():
        struct_size[p[0]] = struct_size.get(p[0], 0) + int(p[4])


def width(t):
    m = re.fullmatch(r"(\w+)\[(\d+)\]", t)
    if m:
        return width(m.group(1)) * int(m.group(2))
    return WIDTH.get(t) or struct_size.get(t) or 1


extent = []
for line in open(f"{out}/global_variables.csv"):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 2 and p[2]:
        a = int(p[0], 16)
        extent.append((a, a + width(p[2]), p[1], p[2]))
for f in files:
    for line in open(f):
        r = json.loads(line) if line.strip() else {}
        if r.get("kind") != "new_global":
            continue
        a = int(r["address"], 16)
        hits = [e for e in extent if e[0] < a < e[1] or (e[0] == a)]
        tag = "B (inside " + ", ".join(f"0x{e[0]:08x} {e[2]} {e[3]}" for e in hits) + ")" if hits else "A"
        print(f"{tag[:1]}  0x{a:08x} {r['new']} {r['type']}  {tag[1:] if hits else ''}")
