import json, re, csv, sys, os
R = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_rail.jsonl'

fn_rows = {}
gl_rows = {}
for r in csv.reader(open(R + 'function_renames.csv')):
    if len(r) >= 2 and r[0].startswith('0x'):
        fn_rows[int(r[0], 16)] = r
for r in csv.reader(open(R + 'global_variables.csv')):
    if len(r) >= 2 and r[0].startswith('0x'):
        gl_rows[int(r[0], 16)] = r
all_names = set(r[1] for r in fn_rows.values()) | set(r[1] for r in gl_rows.values())
arr_cells = set()
if os.path.exists(R + 'arrays.csv'):
    for r in csv.reader(open(R + 'arrays.csv')):
        for c in r:
            arr_cells.add(c)

rows = []
problems = []
new_seen = set()
old_names = []
BANNED = ('temp', 'pres', 'press', 'cfg', 'ctrl', 'msg', 'diag', 'init', 'calc', 'cnt', 'val', 'ptr', 'tmp', 'num', 'idx', 'param')


def chk_new(n, kind):
    if n in all_names or n in arr_cells:
        problems.append('COLLISION ' + n)
    if n in new_seen:
        problems.append('DUP NEW ' + n)
    new_seen.add(n)
    if re.search(r'0x|[0-9a-f]{6,}', n):
        problems.append('HEX? ' + n)
    if kind == 'function' and not re.match(r'^cm848_[a-z][A-Za-z0-9]*$', n):
        problems.append('FNAME ' + n)
    if kind != 'function' and not re.match(r'^[a-z][a-z0-9_]*$', n):
        problems.append('GNAME ' + n)
    for tok in re.split(r'_|(?<=[a-z])(?=[A-Z])', n):
        if tok.lower() in BANNED:
            problems.append('ABBREV %s in %s' % (tok, n))


def func(addr, old, new, plate, evidence):
    a = int(addr, 16)
    if a not in fn_rows or fn_rows[a][1] != old:
        problems.append('FUNC OLD MISMATCH %s %s -> %s' % (addr, old, fn_rows.get(a, ['', '?'])[1]))
    if new != old:
        chk_new(new, 'function')
        old_names.append(old)
    rows.append({"kind": "function", "address": addr, "old": old, "verdict": "confirmed", "new": new, "plate_comment": plate, "evidence": evidence})


def glob(addr, old, new, evidence):
    a = int(addr, 16)
    if a not in gl_rows or gl_rows[a][1] != old:
        problems.append('GLOBAL OLD MISMATCH %s %s -> %s' % (addr, old, gl_rows.get(a, ['', '?'])[1]))
    chk_new(new, 'global')
    old_names.append(old)
    rows.append({"kind": "global", "address": addr, "old": old, "verdict": "confirmed", "new": new, "evidence": evidence})


def newglob(addr, new, typ, evidence):
    a = int(addr, 16)
    if a in gl_rows and gl_rows[a][1]:
        problems.append('NEW_GLOBAL HAS ROW %s %s' % (addr, gl_rows[a][1]))
    chk_new(new, 'global')
    rows.append({"kind": "new_global", "address": addr, "new": new, "type": typ, "evidence": evidence})


def sfield(struct, old, new, evidence):
    rows.append({"kind": "struct_field", "struct": struct, "old": old, "new": new, "evidence": evidence})


def note(text):
    rows.append({"kind": "note", "text": text})


def uncertain(kind, addr, old, evidence):
    rows.append({"kind": kind, "address": addr, "old": old, "verdict": "uncertain", "evidence": evidence})


exec(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W4_rail/rows_W4_rail.py').read())

# reference refresh scan: other rows whose comments cite a retired name
retired = sorted(set(old_names))
hits = {}
for a, r in gl_rows.items():
    c = r[3] if len(r) > 3 else ''
    for o in retired:
        if o != r[1] and re.search(r'(?<![A-Za-z0-9_])' + re.escape(o) + r'(?![A-Za-z0-9_])', c):
            hits.setdefault(o, []).append('0x%08x %s' % (a, r[1]))
for a, r in fn_rows.items():
    c = r[2] if len(r) > 2 else ''
    for o in retired:
        if o != r[1] and re.search(r'(?<![A-Za-z0-9_])' + re.escape(o) + r'(?![A-Za-z0-9_])', c):
            hits.setdefault(o, []).append('fn 0x%08x %s' % (a, r[1]))
if hits:
    txt = ('Existing CSV rows whose comments cite a name retired by this file (refresh the reference when the renames are applied): '
           + '; '.join('%s in %s' % (o, ', '.join(v)) for o, v in sorted(hits.items())) + '.')
    note(txt)

if problems:
    print('PROBLEMS:')
    for p in problems:
        print('  ', p)
else:
    print('no problems')
with open(OUT, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')
back = [json.loads(l) for l in open(OUT)]
from collections import Counter
print(len(back), Counter((r['kind'], r.get('verdict')) for r in back))
