"""CM848: every PowerPC I-form branch (b / bl / ba / bla), B-form conditional branch, 32-bit big-endian pointer and
lis + addi / ori pair that reaches a target, in the ROM (base 0) and flash2 (base 0x500000).
usage: ppc_callers.py <addr hex> [...]"""
import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
images = [(0, open(BASE + 'cm848_rom.bin', 'rb').read()), (0x500000, open(BASE + 'cm848_flash2_live.bin', 'rb').read())]


def scan(target):
    out = []
    for base, img in images:
        n = len(img) // 4
        words = struct.unpack('>%dI' % n, img[:n * 4])
        for k, w in enumerate(words):
            pc = base + 4 * k
            op = w >> 26
            if op == 18:
                li = w & 0x03fffffc
                if li & 0x02000000:
                    li -= 0x04000000
                aa = (w >> 1) & 1
                lk = w & 1
                dest = li if aa else pc + li
                if dest == target:
                    out.append(('bl' if lk else 'b', hex(pc)))
            elif op == 16:
                bd = w & 0xfffc
                if bd & 0x8000:
                    bd -= 0x10000
                aa = (w >> 1) & 1
                dest = bd if aa else pc + bd
                if dest == target:
                    out.append(('bc', hex(pc), hex(w)))
            if w == target:
                out.append(('ptr', hex(pc)))
            if op == 15 and ((w >> 16) & 0x1f) == 0:  # lis rD,imm
                rd = (w >> 21) & 0x1f
                hi = (w & 0xffff) << 16
                for j in range(1, 6):
                    if k + j >= n:
                        break
                    w2 = words[k + j]
                    op2 = w2 >> 26
                    ra = (w2 >> 16) & 0x1f
                    rd2 = (w2 >> 21) & 0x1f
                    imm = w2 & 0xffff
                    if op2 == 14 and ra == rd:  # addi
                        val = (hi + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xffffffff
                        if val == target:
                            out.append(('lis+addi', hex(pc), hex(base + 4 * (k + j))))
                    if op2 == 24 and rd2 == rd:  # ori rA,rS,imm  (rS field = bits 21-25)
                        val = hi | imm
                        if val == target:
                            out.append(('lis+ori', hex(pc), hex(base + 4 * (k + j))))
    return out


for a in sys.argv[1:]:
    t = int(a, 16)
    print(hex(t), scan(t))
