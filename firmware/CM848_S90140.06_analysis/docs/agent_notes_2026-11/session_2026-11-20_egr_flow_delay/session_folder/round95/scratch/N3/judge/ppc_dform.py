"""List every lis-based D-form load/store (and addi/ori pair) reaching CM848 data addresses.
Tracks lis rX,hi through the following 12 instructions; reports lbz/lhz/lha/lwz/stb/sth/stw (+u forms) with base rX
whose EA is one of the targets, plus lis+addi / lis+ori pairs. Owner function from the frozen function_renames.csv.
Usage: ppc_dform.py <addr hex> [...]"""
import bisect
import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
IMAGES = [(BASE + 'cm848_rom.bin', 0), (BASE + 'cm848_flash2_live.bin', 0x500000)]
RENAMES = '/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm848/function_renames.csv'
OPS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
       40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 24: 'ori'}

funcs = []
for line in open(RENAMES):
    if line.startswith('0x'):
        a, n = line.split(',')[:2]
        funcs.append((int(a, 16), n))
funcs.sort()
starts = [a for a, _ in funcs]


def owner(pc):
    i = bisect.bisect_right(starts, pc) - 1
    return funcs[i][1] if i >= 0 else '?'


targets = {int(a, 16) for a in sys.argv[1:]}
hits = {t: [] for t in targets}
for path, base in IMAGES:
    img = open(path, 'rb').read()
    words = [struct.unpack('>I', img[o:o + 4])[0] for o in range(0, len(img) - 3, 4)]
    for i, w in enumerate(words):
        if w >> 26 != 15 or (w >> 16) & 0x1f != 0:
            continue
        rd = (w >> 21) & 0x1f
        hi = (w & 0xffff) << 16
        for j in range(i + 1, min(i + 13, len(words))):
            w2 = words[j]
            op = w2 >> 26
            rt = (w2 >> 21) & 0x1f
            ra = (w2 >> 16) & 0x1f
            imm = w2 & 0xffff
            if op in OPS:
                if op == 24:
                    if rt == rd:
                        ea = hi | imm
                    else:
                        ea = None
                elif ra == rd:
                    ea = (hi + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xffffffff
                else:
                    ea = None
                if ea in hits:
                    pc = base + 4 * j
                    hits[ea].append('%s %s (%s)' % (hex(pc), OPS[op], owner(pc)))
            # stop when rd is overwritten by something other than a store/compare
            if op in (14, 15, 24, 32, 33, 34, 35, 40, 41, 42, 43) and rt == rd and op != 24:
                if not (op == 14 and ra == rd):
                    break
for t in sorted(hits):
    print(hex(t), len(hits[t]))
    for h in hits[t]:
        print('   ', h)
