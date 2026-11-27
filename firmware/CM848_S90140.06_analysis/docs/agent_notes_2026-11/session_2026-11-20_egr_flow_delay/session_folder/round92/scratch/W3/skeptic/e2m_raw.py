"""Print raw CM550 e2m records (untruncated) for a block, optionally one offset or a name regex.
usage: e2m_raw.py <block hex> [--off HEX] [--name REGEX] [--e2m FILE]
Columns: name,units,block,offset,c4,type,c6,size,c8,sign,scale(mask for S),c11,c12,group,date;description"""
import argparse
import re

E2M = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m'
ap = argparse.ArgumentParser()
ap.add_argument('block')
ap.add_argument('--off')
ap.add_argument('--name')
ap.add_argument('--e2m', default=E2M)
a = ap.parse_args()
seen = set()
rows = []
for raw in open(a.e2m, encoding='latin-1'):
    line = raw.rstrip('\r\n')
    data, _, comment = line.partition(';')
    c = data.split(',')
    if len(c) < 12 or c[2].upper() != a.block.upper():
        continue
    if a.off is not None and int(c[3], 16) != int(a.off, 16):
        continue
    if a.name and not re.search(a.name, c[0]):
        continue
    key = (c[0], c[3], c[5], c[7], c[10], comment)
    dup = key in seen
    seen.add(key)
    rows.append((int(c[3], 16), c[5], c[10], c[0], c[7], c[13] if len(c) > 13 else '', c[14] if len(c) > 14 else '', comment, dup, c[1]))
for off, typ, mask, name, size, group, date, comment, dup, units in sorted(rows, key=lambda r: (r[0], r[1], int(r[2], 16) if re.fullmatch(r'[0-9A-Fa-f]+', r[2]) else 0, r[3])):
    if dup:
        continue
    print('+%03X %s mask=%-6s size=%s %-10s units=%-8s grp=%-4s date=%s ; %s' % (off, typ, mask, size, name, units, group, date, comment))
