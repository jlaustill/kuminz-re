import re
import sys

CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
lines = open(CPP, errors='replace').read().split('\n')
hdr = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
cur = None
idx = {}
for i, l in enumerate(lines):
    m = hdr.match(l)
    if m:
        cur = m.group(1)
        continue
    for t in set(re.findall(r'[A-Za-z_][A-Za-z0-9_]*', l)):
        idx.setdefault(t, {}).setdefault(cur, []).append(i + 1)
for w in sys.argv[1:]:
    d = idx.get(w, {})
    print('## %s: %d functions' % (w, len(d)))
    for f, ls in sorted(d.items(), key=lambda kv: str(kv[0])):
        print('   %s lines %s' % (f, ls[:6]))
