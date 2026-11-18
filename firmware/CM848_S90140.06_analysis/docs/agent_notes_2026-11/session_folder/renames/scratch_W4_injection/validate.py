import csv
import json
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_injection.jsonl'

glob = {}
names = set()
for row in csv.reader(open(OUT + 'global_variables.csv')):
    if len(row) < 2 or not row[0].startswith('0x'):
        continue
    glob[int(row[0], 16)] = row[1]
    names.add(row[1])
funcs = {}
for row in csv.reader(open(OUT + 'function_renames.csv')):
    if len(row) < 2 or not row[0].startswith('0x'):
        continue
    funcs[int(row[0], 16)] = row[1]
    names.add(row[1])
arrays = {}
try:
    for row in csv.reader(open(OUT + 'arrays.csv')):
        if len(row) < 2:
            continue
        names.add(row[0])
        for c in row:
            names.add(c)
except Exception as exc:
    print('arrays.csv:', exc)

rows = []
for i, line in enumerate(open(RES), 1):
    line = line.strip()
    if not line:
        continue
    try:
        rows.append(json.loads(line))
    except Exception as exc:
        print('LINE', i, 'JSON ERROR', exc)
        sys.exit(1)
print('rows', len(rows))
from collections import Counter
print(Counter((r['kind'], r.get('verdict')) for r in rows))

bad = 0
seen_new = Counter()
banned = re.compile(r'(?<![a-z])(soi|cbl|cbr|cbo|fss|mcf|ctrl|temp|qty|cmd|calc|cfg|reg|val|idx|cnt|prev)(?![a-z])')
for r in rows:
    k = r['kind']
    new = r.get('new')
    if new and new != r.get('old'):
        seen_new[new] += 1
        if new in names:
            print('COLLISION with existing name:', new)
            bad += 1
        if re.search(r'0x|[0-9]', new) and k != 'function':
            print('DIGIT in name:', new)
        if 'protection' in new and not re.search(r'protection_[a-z]+', new):
            print('bare protection:', new)
        if banned.search(new.replace('_', ' ')):
            print('ABBREVIATION?', new)
        if k in ('global', 'new_global') and new.endswith('_cal'):
            print('_cal suffix:', new)
    if k == 'function':
        a = int(r['address'], 16)
        cur = funcs.get(a)
        if cur != r['old']:
            print('FUNC old mismatch', r['address'], r['old'], 'csv has', cur)
            bad += 1
    if k == 'global':
        a = int(r['address'], 16)
        cur = glob.get(a)
        if cur != r['old']:
            print('GLOBAL old mismatch', r['address'], repr(r['old']), 'csv has', repr(cur))
            bad += 1
    if k == 'new_global':
        a = int(r['address'], 16)
        if a in glob:
            print('NEW_GLOBAL already has a row', r['address'], glob[a])
            bad += 1
for n, c in seen_new.items():
    if c > 1:
        print('DUPLICATE NEW NAME in file', n)
        bad += 1
print('problems', bad)
