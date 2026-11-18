import csv
import json
import re
from collections import Counter

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
rows = [json.loads(line) for line in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_charge_turbo.jsonl')]
print('rows', len(rows), Counter((r['kind'], r.get('verdict')) for r in rows))

gv = {}
gv_names = set()
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if r and r[0].startswith('0x'):
        gv.setdefault(int(r[0], 16), []).append((r[1], r[2] if len(r) > 2 else ''))
        if r[1]:
            gv_names.add(r[1])
fn_rows = {}
fn_names = set()
for r in csv.reader(open(OUT + 'function_renames.csv')):
    if r and r[0].startswith('0x'):
        fn_rows[int(r[0], 16)] = r[1]
        fn_names.add(r[1])
arr_names = set()
for line in open(OUT + 'arrays.csv'):
    p = line.split(',')
    if p[0].startswith('0x') and len(p) > 1:
        arr_names.add(p[1])
enum_members = set()
for r in csv.reader(open(OUT + 'enums.csv')):
    if len(r) > 2:
        enum_members.add(r[2])

problems = []
news = Counter()
for r in rows:
    k = r['kind']
    if k == 'note':
        continue
    a = int(r['address'], 16)
    if k == 'function':
        cur = fn_rows.get(a)
        if cur != r['old']:
            problems.append(('function old mismatch', r['address'], r['old'], cur))
        new = r.get('new')
        if new and new != r['old'] and (new in fn_names or new in gv_names or new in arr_names):
            problems.append(('function new collides', r['address'], new))
        news[new] += 1
        if not r.get('plate_comment'):
            problems.append(('no plate', r['address']))
        continue
    if r.get('verdict') == 'uncertain':
        cur = [n for n, t in gv.get(a, [])]
        if r['old'] not in cur:
            problems.append(('uncertain old mismatch', r['address'], r['old'], cur))
        continue
    if k == 'global':
        cur = [n for n, t in gv.get(a, [])]
        if r['old'] not in cur:
            problems.append(('global old mismatch', r['address'], r['old'], cur))
        else:
            ot = [t for n, t in gv[a] if n == r['old']][0]
            if r.get('old_type') and r['old_type'] != ot:
                problems.append(('old_type mismatch', r['address'], r['old_type'], ot))
            if r.get('type') and not r.get('old_type') and r['type'] != ot and r['type'] not in ('word[17]', 'word[20]', 'word[7]', 'word[36]', 'word[256]'):
                problems.append(('type given without old_type', r['address'], r['type'], ot))
        new = r['new']
        if new != r['old'] and (new in gv_names or new in fn_names or new in arr_names or new in enum_members):
            problems.append(('global new collides', r['address'], new))
        news[new] += 1
    elif k == 'new_global':
        cur = gv.get(a, [])
        if any(n for n, t in cur):
            problems.append(('new_global address already named', r['address'], cur))
        new = r['new']
        if new in gv_names or new in fn_names or new in arr_names or new in enum_members:
            problems.append(('new_global name collides', r['address'], new))
        news[new] += 1
        if not r.get('type'):
            problems.append(('new_global no type', r['address']))
    # name rules
    new = r.get('new')
    if new:
        if re.search(r'0x|[0-9a-f]{6,}', new):
            problems.append(('hex in name', r['address'], new))
        if new.endswith('_cal') and not (0x3fd482 <= a <= 0x3feec1):
            problems.append(('_cal outside EEPROM mirror', r['address'], new))
        if (0x3fd482 <= a <= 0x3feec1) and not new.endswith('_cal') and not new.startswith(('fault_', 'j1939_')) and r['kind'] != 'function':
            problems.append(('EEPROM-range name without _cal (check)', r['address'], new))
        if re.search(r'(^|_)init(_|$)|initialisation|(^|_)tmp(_|$)|(^|_)temp(_|$)|(^|_)qty(_|$)|(^|_)cfg(_|$)|(^|_)ctrl(_|$)|(^|_)cnt(_|$)|(^|_)val(_|$)', new):
            problems.append(('possible abbreviation', r['address'], new))
for n, c in news.items():
    if c > 1:
        problems.append(('duplicate new name in file', n, c))
print('problems:', len(problems))
for p in problems:
    print(p)
