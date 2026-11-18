import csv
import json
import re
import sys

OUTDIR = sys.argv[1]
RES = sys.argv[2]

glob = {}
with open(OUTDIR + '/global_variables.csv', newline='') as f:
    for r in csv.reader(f):
        if r and r[0].startswith('0x') and len(r) > 2:
            glob[r[1]] = int(r[0], 16)
by_addr = {v: k for k, v in glob.items()}
fns = {}
with open(OUTDIR + '/function_renames.csv', newline='') as f:
    for r in csv.reader(f):
        if r and r[0].startswith('0x') and len(r) > 1:
            fns[r[1]] = int(r[0], 16)
fn_by_addr = {v: k for k, v in fns.items()}
arrays = set()
with open(OUTDIR + '/arrays.csv', newline='') as f:
    for r in csv.reader(f):
        if r and len(r) > 1:
            arrays.add(r[1])
            arrays.add(r[0])

rows = [json.loads(l) for l in open(RES) if l.strip()]
problems = []
new_names = []
for i, r in enumerate(rows, 1):
    k = r['kind']
    if k == 'note':
        continue
    addr = int(r['address'], 16)
    old = r['old']
    new = r.get('new')
    if k == 'global':
        if glob.get(old) != addr:
            problems.append((i, 'old global not at address', old, hex(addr), glob.get(old)))
        if not re.fullmatch(r'[a-z][a-z0-9_]*', new):
            problems.append((i, 'bad global name', new))
        in_eeprom = 0x3fd482 <= addr <= 0x3feec1
        if in_eeprom != new.endswith('_cal'):
            problems.append((i, '_cal rule', new, hex(addr)))
    elif k == 'function':
        if old:
            if fns.get(old) != addr:
                problems.append((i, 'old function not at address', old, hex(addr), fns.get(old)))
        else:
            if addr in fn_by_addr:
                problems.append((i, 'function already exists at', hex(addr), fn_by_addr[addr]))
        if not re.fullmatch(r'cm848_[a-z][A-Za-z0-9]*', new):
            problems.append((i, 'bad function name', new))
        pc = r.get('plate_comment', '')
        sentences = [s for s in re.split(r'(?<=[.;])\s+(?=[A-Z(])', pc) if s.strip()]
        if len(sentences) > 4:
            problems.append((i, 'plate sentences', len(sentences), new))
    if new:
        new_names.append(new)
        if new in glob or new in fns or new in arrays:
            problems.append((i, 'NAME COLLISION with existing', new))
        if '0x' in new or re.search(r'\d{4,}', new):
            problems.append((i, 'hex or long number in name', new))
dups = {n for n in new_names if new_names.count(n) > 1}
if dups:
    problems.append(('duplicate new names', sorted(dups)))
print('rows:', len(rows), 'new names:', len(new_names))
print('problems:', len(problems))
for p in problems:
    print(p)
tokens = set()
for n in new_names:
    for t in re.split(r'_', re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', n)):
        tokens.add(t.lower())
print(sorted(tokens))
