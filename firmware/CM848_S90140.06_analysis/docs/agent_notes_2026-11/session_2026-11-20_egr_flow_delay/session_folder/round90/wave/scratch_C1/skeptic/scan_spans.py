#!/usr/bin/env python3
"""List every literal / DAT_ label in the CM550 decompilation that falls strictly inside a proposed array span."""
import re
CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
SPANS = [
    (0x80539c, 104), (0x805404, 104), (0x805562, 40), (0x80558a, 40), (0x8055da, 40), (0x805602, 40),
    (0x8058d4, 32), (0x8058f4, 32), (0x805914, 64), (0x805954, 64), (0x805a1c, 4), (0x806ed0, 18),
    (0x806ee8, 6), (0x807114, 2), (0x807116, 2), (0x80721e, 18), (0x80794e, 32), (0x807abe, 2),
    (0x807ac0, 2), (0x807ac2, 2), (0x807ac6, 2), (0x807b8e, 2), (0x807b90, 2), (0x807b92, 72),
    (0x807bdc, 2), (0x807bde, 2), (0x807d18, 2), (0x807d1a, 2),
]
pat = re.compile(r'(?:0x00|0x|DAT_00|DAT_)(80[0-9a-fA-F]{4})\b')
func = None
hits = {}
for ln, line in enumerate(open(CPP, encoding='utf-8', errors='replace'), 1):
    m = re.match(r'// Function: (\S+) @', line)
    if m:
        func = m.group(1)
    for mm in pat.finditer(line):
        v = int(mm.group(1), 16)
        for base, size in SPANS:
            if base < v < base + size:
                hits.setdefault((base, v), []).append((ln, func, line.strip()[:150]))
for (base, v), lst in sorted(hits.items()):
    print('span 0x%x: inner 0x%x  (%d hits)' % (base, v, len(lst)))
    for ln, f, t in lst[:6]:
        print('   line %d [%s] %s' % (ln, f, t))
