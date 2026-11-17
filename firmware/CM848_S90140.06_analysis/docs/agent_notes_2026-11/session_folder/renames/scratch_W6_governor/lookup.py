import csv, sys, re
base='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
def load(fn):
    rows=[]
    with open(base+fn, newline='') as f:
        lines=[l for l in f if not l.startswith('#')]
    r=csv.reader(lines)
    hdr=next(r)
    for row in r:
        if row: rows.append(row)
    return rows
g=load('global_variables.csv')
fr=load('function_renames.csv')
def norm(a):
    return int(a,16)
gd={}
for r in g:
    try: gd.setdefault(norm(r[0]),[]).append(r)
    except: pass
fd={}
for r in fr:
    try: fd.setdefault(norm(r[0]),[]).append(r)
    except: pass
for a in sys.argv[1:]:
    n=norm(a)
    print('==',a)
    for r in gd.get(n,[]): print('  G', r[1], r[2], '|', r[3] if len(r)>3 else '')
    for r in fd.get(n,[]): print('  F', r[1], '|', r[2] if len(r)>2 else '')
