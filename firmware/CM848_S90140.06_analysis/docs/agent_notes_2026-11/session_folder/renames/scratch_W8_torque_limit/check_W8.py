"""Read-only validation of result_W8_torque_limit.jsonl against the CSVs (same checks as the wave gate, own code)."""
import csv
import json
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_torque_limit.jsonl'
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


def load(path, n):
    lines = open(path, errors='replace').read().split('\n')
    rows = {}
    for i, l in enumerate(lines):
        p = l.split(',', n)
        if p[0].startswith('0x'):
            rows.setdefault(int(p[0], 16), []).append((i, p))
    return lines, rows


fr_lines, fr_rows = load(OUT + 'function_renames.csv', 2)
gv_lines, gv_rows = load(OUT + 'global_variables.csv', 3)
used = set()
for path in ('function_renames.csv', 'global_variables.csv', 'arrays.csv'):
    for l in open(OUT + path, errors='replace'):
        p = l.rstrip('\n').split(',')
        if p[0].startswith('0x') and len(p) > 1:
            used.add(p[1])
known = set(used)
for l in open(OUT + 'structure_definitions.csv', errors='replace'):
    p = l.rstrip('\n').split(',')
    if len(p) > 3 and p[1].startswith('0x'):
        known.add(p[2]); known.add(p[0])
for l in open(OUT + 'enums.csv', errors='replace'):
    p = l.split(',')
    if len(p) > 2:
        known.add(p[0]); known.add(p[2])
for l in open(OUT + 'e2m_parameters.csv', errors='replace'):
    known.add(l.split(',')[0])

rows = [json.loads(l) for l in open(RESULT) if l.strip()]
problems = []
seen = {}
newnames = set()
for r in rows:
    k = r.get('kind')
    if k not in ('function', 'global'):
        continue
    a = int(r['address'], 16)
    old, new, v = r.get('old'), r.get('new'), r.get('verdict')
    tag = '%s %s %s -> %s' % (k, r['address'], old, new)
    if k == 'function':
        rr = fr_rows.get(a, [])
        if len(rr) != 1 or rr[0][1][1] != old:
            problems.append(tag + ': function_renames row mismatch (%s)' % [x[1][1] for x in rr])
        if v == 'confirmed' and new == old:
            if not r.get('plate_comment'):
                problems.append(tag + ': plate-only row without plate')
            continue
        if not re.fullmatch(r"(cm848|mpc555)_[a-z][A-Za-z0-9]*", new or ''):
            problems.append(tag + ': function name format')
    else:
        rr = gv_rows.get(a, [])
        if len(rr) != 1 or rr[0][1][1] != old:
            problems.append(tag + ': global_variables row mismatch (%s)' % [x[1][1] for x in rr])
        if v != 'confirmed' or not new:
            continue
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(tag + ': global name format')
        in_e = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith('_cal') and not in_e:
            problems.append(tag + ': _cal outside the EEPROM mirror')
        if old.endswith('_cal') and in_e and not new.endswith('_cal'):
            problems.append(tag + ': EEPROM-backed value lost its _cal')
        if in_e and old and not old.endswith('_cal') and not new.endswith('_cal'):
            problems.append(tag + ': (info) inside the EEPROM mirror without _cal - check it is not EEPROM-backed')
    if new in seen:
        problems.append(tag + ': new name also used by ' + seen[new])
    seen[new] = tag
    newnames.add(new)
    if new in used:
        problems.append(tag + ': new name already in a CSV')
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(tag + ': banned word(s) %s' % bad)
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(tag + ': hex-looking part')

print('rows:', len(rows), 'confirmed renames:', len(newnames))
for p in problems:
    print('PROBLEM', p)

# identifiers inside notes / plates / evidence that exist nowhere (typo check, names of this file count as known)
ident = re.compile(r"(?<![A-Za-z0-9_.])([a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555)_[A-Za-z0-9]+)(?![A-Za-z0-9_])")
missing = {}
for r in rows:
    text = ' '.join(str(r.get(x, '')) for x in ('text', 'plate_comment', 'evidence'))
    for m in ident.finditer(text):
        t = m.group(1)
        if t in known or t in newnames or t.startswith('0x'):
            continue
        missing.setdefault(t, 0)
        missing[t] += 1
print('identifiers not defined in any CSV / e2m / this file:')
for t, c in sorted(missing.items()):
    print('  ', t, c)
