import re,sys,bisect
F='/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
fs=[]
for i,l in enumerate(open(F,errors='replace')):
    m=re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)',l)
    if m: fs.append((int(m.group(2),16),m.group(1),i+1))
fs.sort()
keys=[a for a,_,_ in fs]
for t in sys.argv[1:]:
    a=int(t,16)
    j=bisect.bisect_right(keys,a)-1
    print(f'0x{a:x} in {fs[j][1]} @ 0x{fs[j][0]:x} (cpp line {fs[j][2]})')
