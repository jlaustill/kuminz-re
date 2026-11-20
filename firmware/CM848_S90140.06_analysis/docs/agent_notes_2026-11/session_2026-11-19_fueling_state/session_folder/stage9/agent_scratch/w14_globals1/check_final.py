import re
import os
import sys
import json
import glob

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output'
STAGE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg", "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq", "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req", "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


bin_items = json.load(open(STAGE + 'bins/globals1.json'))
rows = [json.loads(l) for l in open(STAGE + 'result_W14_globals1.jsonl') if l.strip()]
print('lines', len(rows), 'bin items', len(bin_items))
problems = []
if len(rows) != len(bin_items):
    problems.append('line count')
for i, (b, r) in enumerate(zip(bin_items, rows)):
    if r['address'] != b['address'] or r['old'] != b['current_name'] or r['kind'] != 'global':
        problems.append('order/old mismatch at %d: %s %s' % (i, r['address'], r['old']))

used = set()
for f, col in (('function_renames.csv', 1), ('global_variables.csv', 1), ('arrays.csv', 1)):
    for l in open(os.path.join(OUT, f), errors='replace'):
        p = l.split(',')
        if p[0].startswith('0x') and len(p) > col:
            used.add(p[col])
alltext = {}
for f in glob.glob(OUT + '/*.csv') + [OUT + '/cm848_rom.ghidra.cpp', OUT + '/firmware_globals.hpp', OUT + '/firmware_types.hpp', OUT + '/firmware_functions.hpp']:
    alltext[f] = open(f, errors='replace').read()

others = {}
for f in sorted(glob.glob(STAGE + 'result_W14_*.jsonl')):
    if f.endswith('globals1.jsonl'):
        continue
    for l in open(f):
        l = l.strip()
        if not l:
            continue
        r = json.loads(l)
        if r.get('new'):
            others.setdefault(r['new'], []).append(os.path.basename(f) + ':' + str(r.get('address')))
        for s in r.get('split', []) or []:
            others.setdefault(s['name'], []).append(os.path.basename(f) + ':split:' + s['address'])

seen = {}
count = {'confirmed': 0, 'keep': 0, 'drift': 0, 'uncertain': 0}
for i, r in enumerate(rows):
    count[r['verdict']] = count.get(r['verdict'], 0) + 1
    if r['verdict'] != 'confirmed':
        continue
    nm = [(r['new'], r['address'])] + [(s['name'], s['address']) for s in r.get('split', [])]
    for k, (n, a) in enumerate(nm):
        prob = []
        key = n
        if k == 0 and r.get('split') and r['split'][0]['name'] == n:
            pass
        if n in seen and not (k == 1 and False):
            if seen[n] != (i, 'main') or k != 0:
                if not (k == 1 and seen[n][0] == i):
                    prob.append('duplicate of %s' % (seen[n],))
        if (n in seen and seen[n][0] == i):
            pass
        seen.setdefault(n, (i, 'main' if k == 0 else 'split'))
        if n in used:
            prob.append('in CSV names')
        for f, t in alltext.items():
            if re.search(r'(?<![A-Za-z0-9_])' + re.escape(n) + r'(?![A-Za-z0-9_])', t):
                prob.append('text hit in ' + os.path.basename(f))
        if n in others:
            prob.append('also proposed by other agents %s' % others[n])
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
            prob.append('format')
        bad = sorted(set(words(n)) & BANNED)
        if bad:
            prob.append('banned %s' % bad)
        if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", n):
            prob.append('hex-looking')
        if 'protection' in words(n) and n.split('_')[-1] == 'protection':
            prob.append('bare protection')
        addr = int(a, 16)
        ee = EEPROM[0] <= addr <= EEPROM[1]
        if n.endswith('_cal') and not ee:
            prob.append('_cal outside eeprom')
        if ee and not n.endswith('_cal'):
            prob.append('eeprom row without _cal')
        if prob:
            problems.append('%d %s: %s' % (i, n, prob))
    # old name must equal the current CSV row name
for p in problems:
    print('PROBLEM', p)
print('counts', count, 'problems', len(problems))
# check the old names against global_variables.csv rows
gv = {}
for l in open(os.path.join(OUT, 'global_variables.csv'), errors='replace'):
    p = l.split(',', 3)
    if p[0].startswith('0x'):
        gv.setdefault(int(p[0], 16), []).append(p[1])
for r in rows:
    a = int(r['address'], 16)
    if gv.get(a) != [r['old']]:
        print('PROBLEM old name vs csv', r['address'], r['old'], gv.get(a))
# distinct new names in my own file
newnames = []
for r in rows:
    if r['verdict'] == 'confirmed':
        newnames.append(r['new'])
        for s in r.get('split', []) or []:
            if s['name'] != r['new']:
                newnames.append(s['name'])
dups = {n for n in newnames if newnames.count(n) > 1}
print('duplicate new names inside my file:', dups)
