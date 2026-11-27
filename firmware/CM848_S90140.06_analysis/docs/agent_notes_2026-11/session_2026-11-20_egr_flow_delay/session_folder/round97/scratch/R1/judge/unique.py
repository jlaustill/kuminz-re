import csv, sys
fz = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/'


def load(path):
    rows = {}
    with open(path, newline='') as f:
        for r in csv.reader(f):
            if not r or r[0].startswith('#'):
                continue
            rows.setdefault(r[1], []).append(r[0].lower())
    return rows


g550 = load(fz + 'cm550/global_variables.csv')
f550 = load(fz + 'cm550/function_renames.csv')
g848 = load(fz + 'cm848/global_variables.csv')
f848 = load(fz + 'cm848/function_renames.csv')
seen = {}
for line in open(sys.argv[1]):
    k, name, addr = line.split()
    addr = addr.lower()
    hits = []
    for label, tab in (('g550', g550), ('f550', f550)):
        for a in tab.get(name, []):
            if a != addr:
                hits.append('%s@%s' % (label, a))
    for label, tab in (('g848', g848), ('f848', f848)):
        for a in tab.get(name, []):
            hits.append('%s@%s' % (label, a))
    if name in seen:
        hits.append('DUPLICATE PROPOSAL %s' % seen[name])
    seen[name] = addr
    print('%s %-60s %s' % (k, name, ' '.join(hits) if hits else 'free'))
