"""List new_global rows (wave-11 results) whose address lies inside an existing row's width or inside an existing
array / struct instance, so they must wait for the type change that frees the bytes.
Usage: new_row_overlaps.py <global_variables.csv> <result files...>"""
import json
import re
import sys

WIDTH = {"byte": 1, "bool": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4, "pointer": 4, "i8": 1}
spans = []
for line in open(sys.argv[1]):
    p = line.rstrip("\n").split(",", 3)
    if not p[0].startswith("0x") or len(p) < 3:
        continue
    a, t = int(p[0], 16), p[2].strip()
    m = re.fullmatch(r"(\w+)\[(\d+)\]", t)
    w = WIDTH.get(t) or (WIDTH.get(m.group(1), 0) * int(m.group(2)) if m else 0)
    if w > 1:
        spans.append((a, a + w, p[1], t))
for path in sys.argv[2:]:
    for line in open(path):
        if not line.strip():
            continue
        r = json.loads(line)
        if r.get("kind") != "new_global":
            continue
        a = int(r["address"], 16)
        hit = [s for s in spans if s[0] < a < s[1]]
        if hit:
            print(path.rsplit("_", 1)[-1][:-6], r["address"], r["new"], r.get("type"), "inside", hit)
