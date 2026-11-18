"""Check the W9 result file: JSON validity, new-name collisions (function_renames / global_variables / arrays / enums / struct
fields), old name at address, naming rules, _cal rule, hex in names, init token."""
import csv
import json
import re
import sys

OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_gear_down.jsonl'
D = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'


def rows(name):
    return [r for r in csv.reader(open(D + name, errors='replace')) if r and not r[0].startswith('#')]


fn = {r[0].lower(): r[1] for r in rows('function_renames.csv') if len(r) > 1}
gv = {}
for r in rows('global_variables.csv'):
    if len(r) > 1:
        gv.setdefault(r[0].lower(), r[1])
arr = {r[0].lower(): r[1] for r in rows('arrays.csv') if len(r) > 1}
all_names = set(fn.values()) | set(gv.values()) | set(arr.values())
all_names |= {n.split('.')[0] for n in gv.values()}
enum_members = {r[2] for r in rows('enums.csv') if len(r) > 2}
struct_fields = {r[2] for r in rows('structure_definitions.csv') if len(r) > 2}

problems = []
rs = []
for i, line in enumerate(open(OUT), 1):
    try:
        rs.append(json.loads(line))
    except Exception as e:
        problems.append('line %d invalid JSON: %s' % (i, e))
news = {}
for r in rs:
    k = r.get('kind')
    if k not in ('function', 'global', 'new_global', 'note'):
        problems.append('bad kind %r' % k)
    if k == 'note':
        continue
    a = r['address'].lower()
    a8 = '0x%08x' % int(a, 16)
    new = r.get('new')
    old = r.get('old')
    if k == 'function':
        cur = fn.get(a8)
        if cur != old:
            problems.append('%s old %r != csv %r' % (a8, old, cur))
    elif k == 'global':
        cur = gv.get(a8)
        if cur != old:
            problems.append('%s old %r != csv %r' % (a8, old, cur))
    elif k == 'new_global':
        if a8 in gv:
            problems.append('%s new_global but row exists: %s' % (a8, gv[a8]))
    if new:
        if new != old and new in all_names:
            problems.append('%s new name %r already exists' % (a8, new))
        if new in news and news[new] != a8:
            problems.append('duplicate new name %r at %s and %s' % (new, news[new], a8))
        news[new] = a8
        if new in enum_members or new in struct_fields:
            problems.append('%s new name %r collides with enum member / struct field' % (a8, new))
        if k == 'function':
            if not re.fullmatch(r'cm848_[a-z][A-Za-z0-9]*', new):
                problems.append('%s function name shape %r' % (a8, new))
        else:
            if not re.fullmatch(r'[a-z][a-z0-9_]*', new):
                problems.append('%s global name shape %r' % (a8, new))
            if re.search(r'(^|_)(0x|[0-9a-f]{6,})(_|$)', new):
                problems.append('%s hex-looking name %r' % (a8, new))
            if new.endswith('_cal'):
                if not (0x3fd482 <= int(a, 16) <= 0x3feec1):
                    problems.append('%s _cal outside the EEPROM window: %s' % (a8, new))
            else:
                if 0x3fd482 <= int(a, 16) <= 0x3feec1 and new != old:
                    problems.append('%s inside EEPROM window without _cal: %s' % (a8, new))
        if re.search(r'(^|_)init(_|$)|[a-z]Init[A-Z]|Init$', new):
            problems.append('%s uses init: %s' % (a8, new))
        if re.search(r'(^|_)protection(_|$)', new) and not re.search(r'protection_(of|against)', new):
            problems.append('%s bare protection in %s' % (a8, new))
        if len(new) > 90:
            problems.append('%s long name %d' % (a8, len(new)))
    if r.get('verdict') == 'confirmed' and k != 'new_global' and not r.get('evidence'):
        problems.append('%s no evidence' % a8)
    if k == 'function' and new and not r.get('plate_comment'):
        problems.append('%s function without plate_comment' % a8)
    # plates / evidence must not still mention a new name that is not in this file or the csv
for r in rs:
    if r.get('kind') == 'function' and r.get('plate_comment') and '(was ' not in r['plate_comment']:
        problems.append('%s plate lacks (was ...)' % r['address'])
# stale old names inside plates (outside the trailing "(was ...)")
olds = {r['old'] for r in rs if r.get('old') and r.get('new') and r['new'] != r['old']}
for r in rs:
    if r.get('kind') == 'function' and r.get('plate_comment'):
        p = re.sub(r'\(was [^)]*\)', '', r['plate_comment'])
        for o in olds:
            if re.search(r'(?<![A-Za-z0-9_])' + re.escape(o) + r'(?![A-Za-z0-9_])', p):
                problems.append('%s plate still mentions old name %s' % (r['address'], o))
print(len(rs), 'rows;', len(news), 'new names')
for p in problems:
    print('PROBLEM', p)
print('OK' if not problems else '%d problems' % len(problems))
