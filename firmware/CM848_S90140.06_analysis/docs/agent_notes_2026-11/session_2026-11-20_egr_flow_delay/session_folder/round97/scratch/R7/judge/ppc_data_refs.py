"""CM848: find D-form loads / stores (and addi) whose effective address (lis rA,hi + d) is one of the targets.
Scans the ROM (base 0) and flash2 (base 0x500000). Looks up to 12 instructions after each lis for a use of rA
(stops when rA is overwritten by another lis). usage: ppc_data_refs.py 0xADDR [...]"""
import bisect
import csv
import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
images = [(0, open(BASE + 'cm848_rom.bin', 'rb').read()), (0x500000, open(BASE + 'cm848_flash2_live.bin', 'rb').read())]
names = {}
for row in csv.reader(open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm848/function_renames.csv')):
    if row and row[0].startswith('0x'):
        names[int(row[0], 16)] = row[1]
starts = sorted(names)


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return f"{names[starts[i]]}@0x{starts[i]:x}" if i >= 0 else '?'


OPS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu', 40: 'lhz',
       41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 46: 'lmw', 47: 'stmw', 48: 'lfs', 50: 'lfd',
       52: 'stfs', 54: 'stfd', 14: 'addi'}
targets = {int(a, 16) for a in sys.argv[1:]}
for base, img in images:
    n = len(img) // 4
    words = struct.unpack('>%dI' % n, img[:n * 4])
    for k, w in enumerate(words):
        if (w >> 26) != 15 or ((w >> 16) & 0x1f) != 0:
            continue
        rd = (w >> 21) & 0x1f
        hi = (w & 0xffff) << 16
        for j in range(1, 13):
            if k + j >= n:
                break
            w2 = words[k + j]
            op = w2 >> 26
            ra = (w2 >> 16) & 0x1f
            rt = (w2 >> 21) & 0x1f
            if op in OPS and ra == rd:
                d = w2 & 0xffff
                if d & 0x8000:
                    d -= 0x10000
                ea = (hi + d) & 0xffffffff
                if ea in targets:
                    pc = base + 4 * (k + j)
                    print(f"0x{ea:x}: {OPS[op]} r{rt} at 0x{pc:x} in {owner(pc)}")
            # stop when rd is overwritten (lis/addis/li to rd)
            if op in (15, 14) and rt == rd and ra != rd:
                break
