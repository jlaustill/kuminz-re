"""Map CM550's engine protection channels (severity records 0x8057c0 + 30n, states 0x80d0dc + 46n, configs
0x807032 + 36n) to the global names that sit in each record. usage: channels.py <globals.csv>"""
import csv
import sys
rows = {int(r[0], 16): r for r in csv.reader(open(sys.argv[1], newline='')) if r and r[0].startswith('0x')}
for name, base, stride in (('severity', 0x8057c0, 30), ('state', 0x80d0dc, 46), ('config', 0x807032, 36)):
    print('==', name)
    for n in range(10):
        lo = base + stride * n
        hi = lo + stride
        hits = [(a, rows[a][1]) for a in sorted(rows) if lo <= a < hi]
        print(n, hex(lo), ' | '.join(f'{hex(a)} {nm}' for a, nm in hits[:4]))
