"""Rows bordering each proposed table / log range in the frozen CM550 global_variables.csv: do any overlap the range?"""
import re

rows = []
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/global_variables.csv'):
    if line.startswith('#') or line.startswith('address'):
        continue
    p = line.split(',', 3)
    try:
        a = int(p[0], 16)
    except ValueError:
        continue
    rows.append((a, p[1], p[2]))
rows.sort()
BASE = {'byte': 1, 'word': 2, 'dword': 4, 'i16': 2, 'short': 2, 'undefined': 1}


def size(t):
    m = re.match(r'(\w+)\[(\d+)\]', t)
    if m:
        return BASE.get(m.group(1), 0) * int(m.group(2))
    return BASE.get(t, 0)


for lo, hi in ((0x807032, 0x807176), (0x80d0dc, 0x80d27a), (0x8057c0, 0x8058ce), (0x805562, 0x8057be)):
    print(hex(lo), hex(hi))
    for r in [r for r in rows if r[0] < lo][-2:]:
        s = size(r[2])
        print('  before', hex(r[0]), r[1], r[2], 'ends', hex(r[0] + s - 1) if s else '?', 'OVERLAP' if s and r[0] + s > lo else '')
    for r in [r for r in rows if lo <= r[0] < hi][-1:]:
        s = size(r[2])
        print('  last in', hex(r[0]), r[1], r[2], 'ends', hex(r[0] + s - 1) if s else '?', 'CROSSES' if s and r[0] + s > hi else '')
    for r in [r for r in rows if r[0] >= hi][:1]:
        print('  after', hex(r[0]), r[1], r[2])
