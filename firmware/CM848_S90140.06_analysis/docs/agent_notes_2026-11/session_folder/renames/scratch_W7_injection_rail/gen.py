import csv
import json
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_injection_rail.jsonl'
rows = []


def F(addr, old, new, plate, evidence, verdict='confirmed'):
    r = {'kind': 'function', 'address': addr, 'old': old, 'verdict': verdict}
    if new:
        r['new'] = new
    if plate:
        r['plate_comment'] = plate
    r['evidence'] = evidence
    rows.append(r)


def G(addr, old, new, evidence, verdict='confirmed'):
    r = {'kind': 'global', 'address': addr, 'old': old, 'verdict': verdict}
    if new:
        r['new'] = new
    r['evidence'] = evidence
    rows.append(r)


def NG(addr, new, typ, evidence):
    rows.append({'kind': 'new_global', 'address': addr, 'new': new, 'type': typ, 'evidence': evidence})


def SF(struct, old, new, evidence):
    rows.append({'kind': 'struct_field', 'struct': struct, 'old': old, 'new': new, 'evidence': evidence})


def N(text):
    rows.append({'kind': 'note', 'text': text})


exec(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W7_injection_rail/content.py').read())

with open(RES, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')
print('wrote', len(rows), 'rows')

# ---------------- validation ----------------
fn_rows, gv_rows, names_all = {}, {}, set()
for line in open(OUT + 'function_renames.csv'):
    if line.startswith('0x'):
        p = line.rstrip('\n').split(',', 2)
        fn_rows[int(p[0], 16)] = p[1]
        names_all.add(p[1])
for line in open(OUT + 'global_variables.csv'):
    if line.startswith('0x'):
        p = line.rstrip('\n').split(',', 3)
        gv_rows[int(p[0], 16)] = (p[1], p[2] if len(p) > 2 else '')
        names_all.add(p[1])
for fn in ('arrays.csv', 'enums.csv', 'constants.csv', 'structure_definitions.csv'):
    try:
        for r in csv.reader(open(OUT + fn)):
            for c in r[:4]:
                names_all.add(c)
    except FileNotFoundError:
        pass
vocab = set()
for n in names_all:
    for t in re.split(r'[_]|(?<=[a-z0-9])(?=[A-Z])', n):
        vocab.add(t.lower())
seen_new = {}
bad = 0
newtok = set()
EE_LO, EE_HI = 0x3fd482, 0x3feec1
for r in rows:
    k = r['kind']
    if k in ('function', 'global', 'new_global'):
        a = int(r['address'], 16)
        if k == 'function':
            cur = fn_rows.get(a)
        elif k == 'global':
            cur = gv_rows.get(a, (None,))[0]
        else:
            cur = None
            if a in gv_rows:
                print('PROBLEM new_global address already has a row', r['address'], gv_rows[a][0])
                bad += 1
        if k != 'new_global' and cur != r['old']:
            print('PROBLEM old name mismatch', r['address'], 'csv:', cur, 'row:', r['old'])
            bad += 1
        new = r.get('new')
        if new:
            if new in names_all:
                print('PROBLEM new name exists', new)
                bad += 1
            if new in seen_new:
                print('PROBLEM duplicate new name', new, r['address'], seen_new[new])
                bad += 1
            seen_new[new] = r['address']
            if re.search(r'0x|[0-9a-f]{8}', new):
                print('PROBLEM hex in name', new)
                bad += 1
            if k != 'function' and EE_LO <= a <= EE_HI and not new.endswith('_cal') and r.get('type') != 'word_not_eeprom':
                print('NOTE eeprom-range address without _cal', r['address'], new)
            if (new.endswith('_cal') or '_cal_' in new) and not (EE_LO <= a <= EE_HI):
                print('PROBLEM _cal outside the EEPROM range', r['address'], new)
                bad += 1
            toks = re.split(r'[_]|(?<=[a-z0-9])(?=[A-Z])', new)
            for t in toks:
                if t.lower() not in vocab:
                    newtok.add(t.lower())
    if k == 'struct_field':
        pass
print('new vocabulary tokens:', sorted(newtok))
print('problems:', bad)
from collections import Counter
print(Counter((r['kind'], r.get('verdict')) for r in rows))
