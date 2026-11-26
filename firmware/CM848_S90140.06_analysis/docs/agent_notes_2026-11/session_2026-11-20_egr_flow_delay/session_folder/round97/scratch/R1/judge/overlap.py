import csv, re, sys
fz = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/'
sizes = {'byte': 1, 'char': 1, 'word': 2, 'i16': 2, 'short': 2, 'ushort': 2, 'dword': 4, 'i32': 4, 'pointer': 4, 'undefined': 1, '': 1}
# struct sizes
ssz = {}
with open(fz + 'structure_definitions.csv', newline='') as f:
    for r in csv.reader(f):
        if not r or r[0].startswith('#') or len(r) < 5:
            continue
        try:
            ssz[r[0]] = ssz.get(r[0], 0) + int(r[4])
        except ValueError:
            pass
# bitfields share storage: crude fix, ignore
rows = []
with open(fz + 'global_variables.csv', newline='') as f:
    for r in csv.reader(f):
        if not r or r[0].startswith('#') or not r[0].startswith('0x'):
            continue
        rows.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else ''))
rows.sort()


def size_of(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    m = re.match(r'^(.*)\[(\d+)\]$', t)
    if m:
        return size_of(m.group(1)) * int(m.group(2))
    if t in sizes:
        return sizes[t]
    if t in ssz:
        return ssz[t]
    return 2


for x in sys.argv[1:]:
    t = int(x, 16)
    prev = [r for r in rows if r[0] < t]
    p = prev[-1] if prev else None
    same = [r for r in rows if r[0] == t]
    msg = ''
    if p:
        end = p[0] + size_of(p[2])
        msg = 'prev 0x%x %s %s ends 0x%x%s' % (p[0], p[1], p[2], end, '  OVERLAP!' if end > t else '')
    print('0x%x existing=%s | %s' % (t, same[0][1] if same else '-', msg))
