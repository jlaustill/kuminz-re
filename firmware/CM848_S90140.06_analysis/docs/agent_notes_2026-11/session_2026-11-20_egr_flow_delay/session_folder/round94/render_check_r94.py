"""Round 94 (read-only): for every address row of a map (address,name,old_label,...), check the new name renders in
the .cpp and the old label no longer does (a whole-word match; field paths check their base name). Enum member rows
(no address) are checked the same way. usage: render_check_r94.py <cpp> <map.csv>"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read()
rows = [r.split(",") for r in open(sys.argv[2]).read().splitlines()[1:] if r.strip()]
bad, n = [], 0
for r in rows:
    if len(r) < 3:
        continue
    new, old = r[1], r[2]
    n += 1
    base = re.split(r"[.\[]", new)[0]
    has_new = re.search(rf"(?<![A-Za-z0-9_]){re.escape(base)}(?![A-Za-z0-9_])", cpp) is not None
    has_old = re.search(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", cpp) is not None if old else False
    if not has_new or has_old:
        bad.append(f"{r[0] or '(enum)'} {old} -> {new}: new renders {has_new}, old renders {has_old}")
print(f"{n} rows checked, {len(bad)} not clean")
for b in bad:
    print("  ", b)
