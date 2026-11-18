import subprocess, sys, re
for a in sys.argv[1:]:
    out = subprocess.run(['python3','firmware/scripts/xref_addr.py',a],capture_output=True,text=True).stdout.split('\n')
    head = [l for l in out[:3] if l.startswith('#')]
    fn = None; funcs=[]; boot=[]
    for l in out:
        m = re.match(r'^(\S+): (\d+)r/(\d+)w', l)
        if m: fn=m.group(1); funcs.append('%s %sr/%sw'%(m.group(1),m.group(2),m.group(3))); continue
        m = re.match(r'^\s+\[(\w+)\s*\]\s+(\w+)\s+([0-9a-f]+):', l)
        if m and int(m.group(3),16) < 0x7f60: boot.append('%s@%s(%s %s)'%(fn,m.group(3),m.group(1).strip(),m.group(2)))
    print(a, '|', head[0][2:80] if head else '', '|', head[1][2:70] if len(head)>1 else '')
    print('    funcs:', '; '.join(funcs[:8]))
    print('    BOOT(<0x7f60):', boot if boot else 'none')
