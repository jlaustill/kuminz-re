"""Read-only replica of the rename gate checks (firmware/scripts/rename_waves/apply_renames.py) for the W9 governor result file."""
import json
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output'
RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_governor.jsonl'
EEPROM = (0x3fd482, 0x3feec1)
BANNED = {'init', 'tmp', 'temp', 'val', 'cnt', 'calc', 'ctrl', 'mgr', 'cfg', 'param', 'idx', 'ptr', 'sel', 'cmd', 'flg', 'reg', 'num', 'msg',
          'aecd', 'emm', 'emo', 'chp', 'asg', 'hsg', 'cbr', 'imt', 'el'}


def load(name, col):
    d = {}
    for l in open(f'{OUT}/{name}'):
        p = l.rstrip('\n').split(',', 3)
        if p[0].startswith('0x') and len(p) > col:
            d.setdefault(int(p[0], 16), []).append(p[col])
    return d


gv = load('global_variables.csv', 1)
fr = load('function_renames.csv', 1)
arr = load('arrays.csv', 1)
used = set()
for d in (gv, fr, arr):
    for v in d.values():
        used.update(v)

rows = []
for n, line in enumerate(open(RES), 1):
    rows.append((n, json.loads(line)))
problems = []
seen = {}
byaddr = {}
for n, r in rows:
    k = r.get('kind')
    if k not in ('function', 'global', 'new_global'):
        continue
    a = int(r['address'], 16)
    new = r.get('new')
    if k == 'new_global':
        if a in gv:
            problems.append(f"line {n}: new_global {r['address']} already has a row {gv[a]}")
        if new in used:
            problems.append(f"line {n}: new name {new} already in a CSV")
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(f"line {n}: bad new_global name {new}")
        continue
    old = r['old']
    cur = (gv if k == 'global' else fr).get(a, [])
    if len(cur) != 1 or cur[0] != old:
        problems.append(f"line {n}: {k} {r['address']} old {old} != current {cur}")
    if not new or new == old:
        continue
    if new in used:
        problems.append(f"line {n}: new name {new} already in a CSV")
    if new in seen:
        problems.append(f"line {n}: new name {new} also proposed at line {seen[new]}")
    seen[new] = n
    if (k, a) in byaddr:
        problems.append(f"line {n}: second proposal for {r['address']}")
    byaddr[(k, a)] = n
    words = re.split(r"[_]|(?<=[a-z0-9])(?=[A-Z])", new)
    bad = {w.lower() for w in words} & BANNED
    if bad:
        problems.append(f"line {n}: banned word(s) {bad} in {new}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"line {n}: hex-looking part in {new}")
    if k == 'function':
        if not re.fullmatch(r"((cm848|cm550|mpc555|mc68k|hpcr|vp44)_)?[a-z][A-Za-z0-9]*", new):
            problems.append(f"line {n}: function name format {new}")
    else:
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(f"line {n}: global name format {new}")
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith('_cal') and not in_eeprom:
            problems.append(f"line {n}: _cal outside the EEPROM mirror {new}")
        if old.endswith('_cal') and in_eeprom and not new.endswith('_cal'):
            problems.append(f"line {n}: EEPROM value lost _cal {old}")
        if new.split('_')[-1] == 'protection':
            problems.append(f"line {n}: bare protection {new}")
print(len(rows), 'rows;', len(problems), 'problems')
for p in problems:
    print('PROBLEM', p)
from collections import Counter
print(Counter((r.get('kind'), r.get('verdict')) for _, r in rows))
