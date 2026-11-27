#!/usr/bin/env python3
"""Q5 judge: every D-form load/store/addi whose 16-bit immediate, added to 0x400000 (lis 0x40), lands in LO..HI,
anywhere in ROM / flash2 (no function windows). Groups the hits by the containing function of the frozen cpp."""
import bisect
import re
import struct
from collections import Counter

ORIG = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/cm848_rom.ghidra.cpp"
LO, HI = 0x3fdba4, 0x3fdc3a
funcs = []
for line in open(CPP, errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))
starts = [a for a, _ in funcs]


def owner(pc):
    i = bisect.bisect_right(starts, pc) - 1
    return funcs[i][1] + "@" + hex(funcs[i][0]) if i >= 0 else "?"


OPS = {14: 'addi', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
       40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu'}
hits = []
for org, fn in ((0, "cm848_rom.bin"), (0x500000, "cm848_flash2_live.bin")):
    data = open(ORIG + fn, "rb").read()
    for off in range(0, len(data) - 3, 4):
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        if op not in OPS:
            continue
        ra = (w >> 16) & 31
        if ra == 0:
            continue
        simm = w & 0xffff
        simm = simm - 0x10000 if simm & 0x8000 else simm
        ea = (0x400000 + simm) & 0xffffffff
        if LO <= ea < HI:
            hits.append((org + off, OPS[op], ea, ra, (w >> 21) & 31))
print(len(hits), "raw immediate hits (any base register)")
c = Counter(owner(h[0]) for h in hits)
for k, v in sorted(c.items()):
    print(v, k)
print("--- hits per address (pc mnemonic) for app functions >= 0x7f60:")
for pc, mn, ea, ra, rt in hits:
    if pc >= 0x7f60:
        print(hex(ea), hex(pc), mn, "r%d" % ra, owner(pc))
