import re
import os
import sys
import json
import glob

sys.path.insert(0, '/tmp/w14_globals1')
import names

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output'
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg", "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq", "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req", "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}


def words(name):
    out = []
    for p in name.split('_'):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


used = set()
for f, col in (('function_renames.csv', 1), ('global_variables.csv', 1), ('arrays.csv', 1)):
    for l in open(os.path.join(OUT, f), errors='replace'):
        p = l.split(',')
        if p[0].startswith('0x') and len(p) > col:
            used.add(p[col])
alltext = {}
for f in glob.glob(OUT + '/*.csv') + [OUT + '/cm848_rom.ghidra.cpp', OUT + '/firmware_globals.hpp', OUT + '/firmware_types.hpp', OUT + '/firmware_functions.hpp']:
    alltext[f] = open(f, errors='replace').read()
allnames = []
for k, v in names.NEW.items():
    allnames.append((k, v))
for k, lst in names.SPLIT_NAMES.items():
    for a, n in lst:
        allnames.append((str(k) + ':' + a, n))
seen = {}
EEPROM = (0x3fd482, 0x3feec1)
d = json.load(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals1.json'))
for k, n in allnames:
    prob = []
    if n in seen:
        prob.append('duplicate of %s' % seen[n])
    seen[n] = k
    if n in used:
        prob.append('in CSV names')
    for f, t in alltext.items():
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(n) + r'(?![A-Za-z0-9_])', t):
            prob.append('text hit in ' + os.path.basename(f))
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
        prob.append('format')
    bad = sorted(set(words(n)) & BANNED)
    if bad:
        prob.append('banned %s' % bad)
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", n):
        prob.append('hex-looking')
    if 'protection' in words(n) and n.split('_')[-1] == 'protection':
        prob.append('bare protection')
    if isinstance(k, int):
        a = int(d[k]['address'], 16)
        ee = EEPROM[0] <= a <= EEPROM[1]
        if n.endswith('_cal') and not ee:
            prob.append('_cal outside eeprom')
        if ee and not n.endswith('_cal'):
            prob.append('eeprom row without _cal')
    else:
        a = int(k.split(':')[1], 16)
        if n.endswith('_cal'):
            prob.append('_cal outside eeprom')
    if prob:
        print(k, n, prob)
print('checked', len(allnames))
