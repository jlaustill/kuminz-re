import sys, re, bisect
CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
fn = []
for i, l in enumerate(open(CPP, errors='replace'), 1):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', l)
    if m:
        fn.append((int(m.group(2), 16), m.group(1), i))
fn.sort()
addrs = [f[0] for f in fn]
for a in sys.argv[1:]:
    n = int(a, 16)
    k = bisect.bisect_right(addrs, n) - 1
    f = fn[k]
    print(hex(n), '->', f[1], '@0x%x' % f[0], '(cpp line %d)' % f[2])
