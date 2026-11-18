import re,sys
F='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
pat=re.compile(sys.argv[1])
ctx=int(sys.argv[2]) if len(sys.argv)>2 else 0
lines=open(F,errors='replace').read().split('\n')
cur=None
for i,l in enumerate(lines):
    m=re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)',l)
    if m: cur=m.group(1)+'@'+m.group(2)
    if pat.search(l):
        print(f'[{cur}] {i+1}: {l.strip()}')
        for k in range(1,ctx+1):
            if i+k<len(lines): print(f'      +{k}: {lines[i+k].strip()}')
