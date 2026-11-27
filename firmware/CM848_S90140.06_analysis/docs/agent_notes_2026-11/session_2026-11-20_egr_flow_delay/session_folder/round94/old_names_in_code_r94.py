"""Round 94 (read-only): for each old label of a map, count its whole-word uses in the .cpp's CODE (comments - the
plate comment blocks /* ... */ and // lines - removed first). A rename is complete when no old label is left in the
code. usage: old_names_in_code_r94.py <cpp> <map.csv>"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
code = re.sub(r"//[^\n]*", " ", code)
rows = [r.split(",") for r in open(sys.argv[2]).read().splitlines()[1:] if r.strip()]
left = []
for r in rows:
    if len(r) < 3 or not r[2]:
        continue
    old = r[2]
    n = len(re.findall(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", code))
    if n:
        left.append((old, r[1], n))
print(f"{len(rows)} map rows; {len(left)} old labels still in code")
for old, new, n in left:
    print(f"   {old} -> {new}: {n}")
