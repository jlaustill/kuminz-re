"""Find '&name + N' / '(name + N)' style references in the CM550 .cpp whose resolved address lands in a range.
usage: offset_refs.py <globals.csv> <cpp> <lo> <hi>"""
import csv, re, sys
rows = {}
for r in csv.reader(open(sys.argv[1], newline='')):
    if r and r[0].startswith('0x'):
        rows[r[1]] = int(r[0], 16)
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
pat = re.compile(r'&?_?([A-Za-z_]\w*)\s*\+\s*(0x[0-9a-fA-F]+|\d+)\b')
fn = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
cur = '?'
for i, line in enumerate(open(sys.argv[2], errors='replace'), 1):
    m = fn.match(line)
    if m:
        cur = m.group(1); continue
    for m in pat.finditer(line):
        name = m.group(1)
        base = rows.get(name)
        if base is None and name.startswith('DAT_'):
            try: base = int(name[4:], 16)
            except ValueError: pass
        if base is None: continue
        a = base + int(m.group(2), 0)
        if lo <= a < hi and not (lo <= base < hi):
            print(f'{i:6} {cur}: {name}+{m.group(2)} -> 0x{a:x}: {line.strip()[:150]}')
