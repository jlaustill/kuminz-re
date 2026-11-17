import re, sys
CPP='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
want=sys.argv[1:]
lines=open(CPP,errors='replace').read().split('\n')
hdr=re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
starts=[(i,m.group(1),int(m.group(2),16)) for i,l in enumerate(lines) for m in [hdr.match(l)] if m]
for w in want:
    wa=None
    if w.startswith('0x'): wa=int(w,16)
    for k,(i,n,a) in enumerate(starts):
        if n==w or a==wa:
            j=starts[k+1][0] if k+1<len(starts) else len(lines)
            print('=== %s @ 0x%08x  (cpp lines %d-%d)'%(n,a,i+1,j))
            print('\n'.join(lines[i:j]).rstrip())
            print()
            break
    else:
        print('NOT FOUND',w)
