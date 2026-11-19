import json
import sys

d = json.load(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin1.json'))
names = {x['record']: x for x in d}
full = {}
for line in open(sys.argv[1], errors='replace'):
    f = line.rstrip('\r\n').split(';', 1)
    cols = f[0].split(',')
    if cols[0] in names and len(cols) > 13 and cols[2] == names[cols[0]]['block'] and cols[3] == names[cols[0]]['offset']:
        full[cols[0]] = (f[1].strip() if len(f) > 1 else '', cols)
for n, x in names.items():
    t = full.get(n)
    if t is None:
        print('MISSING', n)
        continue
    desc, cols = t
    print(x['block'], '+' + x['offset'], n, '|', desc, '| size=' + cols[7], 'sign=' + cols[9], 'scale=' + cols[10], 'min=' + cols[12], 'max=' + cols[13])
