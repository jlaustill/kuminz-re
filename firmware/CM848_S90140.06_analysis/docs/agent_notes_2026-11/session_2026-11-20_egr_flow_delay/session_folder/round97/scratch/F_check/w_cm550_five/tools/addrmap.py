import csv, re, sys, bisect
gv = sys.argv[1]; dis = sys.argv[2]
rows = []
with open(gv, newline='') as f:
    for r in csv.reader(f):
        if not r or r[0].startswith('#') or r[0] == 'address':
            continue
        try:
            a = int(r[0], 16)
        except ValueError:
            continue
        rows.append((a, r[1], r[2] if len(r) > 2 else ''))
rows.sort()
addrs = [r[0] for r in rows]
seen = {}
for line in open(dis):
    for m in re.finditer(r'0x([0-9a-f]{5,8})', line.split(None, 2)[2] if len(line.split(None, 2)) > 2 else ''):
        v = int(m.group(1), 16)
        if v < 0x800000 and not (0x10000 <= v < 0x40000):
            continue
        seen.setdefault(v, line.split(':')[0])
for v in sorted(seen):
    i = bisect.bisect_right(addrs, v) - 1
    if i >= 0:
        a, n, t = rows[i]
        print(f"{v:#08x} first@{seen[v]}  -> {n} ({t}) +{v - a}  [row {a:#08x}]")
    else:
        print(f"{v:#08x} -> none")
