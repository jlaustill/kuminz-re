#!/usr/bin/env python3
"""Scan CM848 ROM + flash2 for D-form accesses / address formations hitting a data range.

Tracks lis/addis rX values per register (linear sweep, crude invalidation), reports:
 - D-form load/store whose effective address (tracked base + simm16) lies in [lo, hi]
 - addi rY,rX,simm whose result lies in [lo - 0x40, hi] (a base pointer near the range)
Usage: ppc_scan.py LO HI
"""
import struct
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
IMAGES = [(FW + 'cm848_rom.bin', 0x0), (FW + 'cm848_flash2_live.bin', 0x500000)]
OPS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
       40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 46: 'lmw', 47: 'stmw'}
LOADS = (32, 33, 34, 35, 40, 41, 42, 43, 46)


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def main():
    lo = int(sys.argv[1], 16)
    hi = int(sys.argv[2], 16)
    for path, vma in IMAGES:
        d = open(path, 'rb').read()
        regs = {}
        for off in range(0, len(d) - 3, 4):
            w = struct.unpack('>I', d[off:off + 4])[0]
            op = w >> 26
            rt = (w >> 21) & 31
            ra = (w >> 16) & 31
            imm = w & 0xffff
            pc = vma + off
            if op == 15:  # addis / lis
                if ra == 0:
                    regs[rt] = (imm << 16) & 0xffffffff
                elif ra in regs:
                    regs[rt] = (regs[ra] + (s16(imm) << 16)) & 0xffffffff
                else:
                    regs.pop(rt, None)
                continue
            if op == 14:  # addi / li
                if ra != 0 and ra in regs:
                    v = (regs[ra] + s16(imm)) & 0xffffffff
                    if lo - 0x40 <= v <= hi:
                        print(f'{pc:08x} addi r{rt},r{ra},{s16(imm)} -> {v:#x}')
                    regs[rt] = v
                else:
                    regs.pop(rt, None)
                continue
            if op in OPS:
                if ra != 0 and ra in regs:
                    ea = (regs[ra] + s16(imm)) & 0xffffffff
                    if lo <= ea <= hi:
                        print(f'{pc:08x} {OPS[op]} r{rt},{s16(imm)}(r{ra}) -> {ea:#x}')
                if op in LOADS:
                    regs.pop(rt, None)
                if op in (33, 35, 37, 39, 41, 43, 45):  # update forms change ra
                    regs.pop(ra, None)
                continue
            if op == 18 and (w & 1):  # bl: volatile registers die
                for r in (0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12):
                    regs.pop(r, None)
                continue
            if op == 31:
                xo = (w >> 1) & 0x3ff
                # X-form logical ops (and, or, xor, nor, andc, orc, slw, srw, sraw, srawi, extsb, extsh, cntlzw)
                # write ra; most others write rt; stores write nothing.
                if xo in (28, 60, 124, 284, 316, 412, 444, 476, 24, 536, 792, 824, 954, 922, 26):
                    regs.pop(ra, None)
                elif xo in (151, 183, 215, 247, 407, 439, 662, 918, 150, 214, 663, 695, 727, 759, 983):
                    pass
                else:
                    regs.pop(rt, None)
                continue
            if op in (20, 21, 23, 24, 25, 26, 27, 28, 29):  # rlwimi/rlwinm/rlwnm/ori/oris/xori/xoris/andi./andis.
                regs.pop(ra, None)
                continue
            if op in (7, 8, 12, 13):  # mulli, subfic, addic, addic.
                regs.pop(rt, None)
                continue


if __name__ == '__main__':
    main()
