"""List every absolute-long reference to CM550 addresses with the containing function (from the frozen .cpp function starts).
usage: refs.py 0xADDR ..."""
import re, sys, bisect
ROM='/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
CPP='/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/J90350.00.ghidra.cpp'
rom=open(ROM,'rb').read()
starts=[]
for m in re.finditer(r'^// Function: (\S+) @ 0x([0-9a-f]+)', open(CPP,errors='replace').read(), flags=re.M):
    starts.append((int(m.group(2),16), m.group(1)))
starts.sort()
keys=[s[0] for s in starts]
def owner(a):
    i=bisect.bisect_right(keys,a)-1
    return starts[i][1] if i>=0 else '?'
for arg in sys.argv[1:]:
    a=int(arg,16)
    pat=a.to_bytes(4,'big')
    i=rom.find(pat)
    out=[]
    while i!=-1:
        if i%2==0:
            out.append(f'0x{i:x}({owner(i)})')
        i=rom.find(pat,i+1)
    print(f'0x{a:x}: {len(out)} refs: '+', '.join(out))
