"""usage: whichfn.py 0x51f870 ... -> function name containing each address (from the cpp // Function: lines)"""
import re
import sys

CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
funcs = []
for i, line in enumerate(open(CPP, errors='replace'), 1):
    m = pat.match(line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1), i))
funcs.sort()
for a in sys.argv[1:]:
    addr = int(a, 16)
    cand = [f for f in funcs if f[0] <= addr]
    print(hex(addr), cand[-1][1], hex(cand[-1][0]), 'cpp line', cand[-1][2])
