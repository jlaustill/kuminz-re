import re, sys, csv
R='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
cpp=open(R+'cm848_rom.ghidra.cpp').read().split('\n')
heads=[(i,l) for i,l in enumerate(cpp) if l.startswith('// Function: ')]
funcs={}
for k,(i,l) in enumerate(heads):
    m=re.match(r'// Function: (\S+) @ (0x[0-9a-fA-F]+)',l)
    end=heads[k+1][0] if k+1<len(heads) else len(cpp)
    funcs[m.group(1)]=(m.group(2).lower(),i,end)
    funcs[m.group(2).lower()]=(m.group(1),i,end)
rows={}
byaddr={}
for r in csv.reader(open(R+'global_variables.csv')):
    if len(r)<2 or r[0]=='address': continue
    rows[r[1]]=r
    byaddr[r[0].lower()]=r
frows={}
for r in csv.reader(open(R+'function_renames.csv')):
    if len(r)<2 or r[0]=='address': continue
    frows[r[1]]=r
def ident_set(text):
    return set(re.findall(r'[A-Za-z_][A-Za-z0-9_]*',text))
def show(names, maxc=300):
    seen=set()
    for n in names:
        fn=funcs.get(n)
        if not fn:
            print('NO FUNC',n); continue
        text='\n'.join(cpp[fn[1]:fn[2]])
        ids=ident_set(text)
        for t in sorted(ids):
            if t in seen: continue
            if t in rows:
                r=rows[t]; seen.add(t)
                print(f"{r[0]} {r[1]} [{r[2] if len(r)>2 else ''}] {(r[3] if len(r)>3 else '')[:maxc]}")
            elif re.match(r'DAT_[0-9a-f]{8}$',t):
                seen.add(t)
                a='0x'+t[4:]
                rr=byaddr.get(a)
                print(f"{a} {t} -- {'ROW:'+rr[1] if rr else 'no row'}")
if __name__=='__main__':
    maxc=int(sys.argv[1])
    show(sys.argv[2:], maxc)
