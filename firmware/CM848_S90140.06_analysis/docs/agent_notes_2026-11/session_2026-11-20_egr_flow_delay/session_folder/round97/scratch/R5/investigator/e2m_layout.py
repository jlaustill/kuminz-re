import collections
e2m = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m'
recs = collections.defaultdict(list)
for line in open(e2m, 'rb'):
    s = line.decode('latin-1').rstrip('\r\n')
    parts = s.split(';')[0].split(',')
    if len(parts) < 12:
        continue
    m, unit, blk, off = parts[0], parts[1], parts[2], parts[3]
    try:
        o = int(off, 16)
    except ValueError:
        continue
    desc = s.split(';', 1)[1] if ';' in s else ''
    recs[blk.upper()].append((o, m, unit.strip(), parts[7], parts[9], parts[10], parts[12], desc[:70]))
groups = {
    'config': ['10B7', '112B', '112C', '112D', '112E', '112F', '1130', '1131', '1132'],
    'state': ['10B0', '114F', '1150', '1151', '1152', '1153', '1154', '1155', '1156'],
    'history': ['10B2', '1140', '1141', '1142', '1143', '1144', '1145', '1146', '1147'],
}
for g, blks in groups.items():
    print('=====', g)
    offs = sorted(set(o for b in blks for (o, *_) in recs[b]))
    for o in offs:
        row = []
        for b in blks:
            ms = [r[1] for r in recs[b] if r[0] == o]
            row.append('/'.join(ms) if ms else '-')
        lens = set(r[3] for b in blks for r in recs[b] if r[0] == o)
        sg = set(r[4] for b in blks for r in recs[b] if r[0] == o)
        sub = set(r[6] for b in blks for r in recs[b] if r[0] == o)
        print('+%02X len%s %s sub%s: %s' % (o, ','.join(sorted(lens)), ','.join(sorted(sg)), ','.join(sorted(sub)), ' '.join(row)))
