import csv
import json
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_combustion_flash2.jsonl'


def load_names(fname, col_name=1, col_addr=0):
    names = {}
    addrs = {}
    with open(OUT + fname, newline='') as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            parts = line.rstrip('\n').split(',', 3)
            if len(parts) < 2:
                continue
            names.setdefault(parts[col_name], []).append(parts[col_addr])
            addrs.setdefault(parts[col_addr].lower(), []).append(parts[col_name])
    return names, addrs


fn_names, fn_addrs = load_names('function_renames.csv')
gv_names, gv_addrs = load_names('global_variables.csv')
try:
    ar_names, ar_addrs = load_names('arrays.csv')
except Exception as e:
    ar_names, ar_addrs = {}, {}

# struct field names (to flag, informational)
sf = set()
with open(OUT + 'structure_definitions.csv', newline='') as f:
    for row in csv.reader(f):
        if len(row) > 2 and not row[0].startswith('#'):
            sf.add(row[2])

rows = []
with open(RES) as f:
    for i, line in enumerate(f, 1):
        try:
            rows.append((i, json.loads(line)))
        except Exception as e:
            print('BAD JSON line', i, e)
            sys.exit(1)

problems = 0
seen_new = {}
banned = re.compile(r'(^|_)(soi|nox|mcf|fsnox|cbo|cbp|cbr|cbl|fss|ofc|o2|afr|egt)(_|$)|0x|\d{3,}', re.I)
for i, r in rows:
    k = r['kind']
    if k in ('function', 'global', 'new_global'):
        new = r.get('new')
        old = r.get('old')
        addr = r['address']
        if new:
            if banned.search(new):
                print(f'line {i}: banned token in {new}')
                problems += 1
            if new in seen_new:
                print(f'line {i}: duplicate new name {new} (also line {seen_new[new]})')
                problems += 1
            seen_new[new] = i
            if k == 'function':
                if new != old and (new in fn_names or new in gv_names or new in ar_names):
                    print(f'line {i}: new function name already exists: {new}')
                    problems += 1
            else:
                if new in fn_names or new in gv_names or new in ar_names:
                    print(f'line {i}: new global name already exists: {new} -> {fn_names.get(new) or gv_names.get(new) or ar_names.get(new)}')
                    problems += 1
                if new in sf:
                    print(f'line {i}: note, {new} equals a struct field name')
        if k == 'function':
            cur = fn_addrs.get(addr.lower()) or fn_addrs.get('0x' + addr[2:].lstrip('0').rjust(8, '0'))
            if not cur or old not in cur:
                print(f'line {i}: function {old} not found at {addr}: {cur}')
                problems += 1
        elif k == 'global':
            a2 = '0x' + addr[2:].lstrip('0').rjust(8, '0')
            cur = gv_addrs.get(a2.lower())
            if not cur or old not in cur:
                print(f'line {i}: global {old} not found at {addr}: {cur}')
                problems += 1
        elif k == 'new_global':
            a2 = '0x' + addr[2:].lstrip('0').rjust(8, '0')
            cur = gv_addrs.get(a2.lower())
            if cur and any(c for c in cur):
                print(f'line {i}: new_global address {addr} already has rows: {cur}')
                problems += 1
        if k == 'function' and r['verdict'] == 'confirmed':
            pc = r.get('plate_comment', '')
            if '(was ' not in pc and new != old:
                print(f'line {i}: plate comment lacks (was ...)')
                problems += 1
    elif k == 'note':
        pass

print('rows', len(rows), 'problems', problems)
from collections import Counter
print(Counter(r['kind'] for _, r in rows))
print(Counter(r.get('verdict') for _, r in rows if r['kind'] in ('function', 'global')))
