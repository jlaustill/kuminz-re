import re,sys
cpp=open(sys.argv[1]).read().split('\n')
funcs=[]
for i,l in enumerate(cpp):
    m=re.match(r'\s*//\s*Function:\s*(\S+)\s*@\s*(0x[0-9a-fA-F]+)',l)
    if m: funcs.append((i,m.group(1),m.group(2)))
def enclosing(i):
    best=None
    for f in funcs:
        if f[0]<=i: best=f
        else: break
    return best
for lab in sys.argv[2:]:
    pat=re.compile(r'\b_?'+re.escape(lab.lstrip('_'))+r'\b')
    print('=====',lab)
    for i,l in enumerate(cpp):
        if pat.search(l):
            f=enclosing(i)
            print('%6d [%s @ %s] %s'%(i+1,f[1] if f else None,f[2] if f else None,l.strip()[:220]))
