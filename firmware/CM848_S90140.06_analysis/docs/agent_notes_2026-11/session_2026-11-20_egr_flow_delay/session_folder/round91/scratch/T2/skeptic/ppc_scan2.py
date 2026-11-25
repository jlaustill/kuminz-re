#!/usr/bin/env python3
"""Independent CM848 scan for accesses to a target byte (skeptic, T2).

Linear sweep of ROM + flash2. Tracks register values made by lis/addis, addi, ori/oris.
Reports:
  - D-form load/store whose EA == target (or within [target-window, target]) through a tracked base
  - addi / ori results that equal target or lie within window below it (base pointer formation)
  - X-form indexed loads/stores (lbzx etc.) where either register holds a tracked value within window
Also searches for the 32-bit literal and the halfword pairs used by lis/ori.
Usage: ppc_scan2.py TARGET_HEX [WINDOW_HEX]
"""
import struct
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
IMAGES = [(FW + 'cm848_rom.bin', 0x0), (FW + 'cm848_flash2_live.bin', 0x500000)]
DOPS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
        40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 46: 'lmw', 47: 'stmw'}
XOPS = {23: 'lwzx', 55: 'lwzux', 87: 'lbzx', 119: 'lbzux', 151: 'stwx', 183: 'stwux', 215: 'stbx',
        247: 'stbux', 279: 'lhzx', 311: 'lhzux', 343: 'lhax', 375: 'lhaux', 407: 'sthx', 439: 'sthux'}


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def main():
    target = int(sys.argv[1], 16)
    window = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x20
    lo = target - window
    for path, vma in IMAGES:
        d = open(path, 'rb').read()
        lit = struct.pack('>I', target)
        i = d.find(lit)
        while i >= 0:
            print(f'literal {target:#x} at {vma + i:#x}')
            i = d.find(lit, i + 1)
        regs = {}
        for off in range(0, len(d) - 3, 4):
            w = struct.unpack('>I', d[off:off + 4])[0]
            op = w >> 26
            rt = (w >> 21) & 31
            ra = (w >> 16) & 31
            rb = (w >> 11) & 31
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
                    if lo <= v <= target:
                        print(f'{pc:08x} addi r{rt},r{ra},{s16(imm)} -> {v:#x}')
                    regs[rt] = v
                elif ra == 0:
                    regs[rt] = s16(imm) & 0xffffffff
                else:
                    regs.pop(rt, None)
                continue
            if op == 24:  # ori rA,rS,uimm
                if rt in regs:
                    v = regs[rt] | imm
                    if lo <= v <= target:
                        print(f'{pc:08x} ori r{ra},r{rt},{imm:#x} -> {v:#x}')
                    regs[ra] = v
                else:
                    regs.pop(ra, None)
                continue
            if op in DOPS:
                if ra != 0 and ra in regs:
                    ea = (regs[ra] + s16(imm)) & 0xffffffff
                    if ea == target or (lo <= regs[ra] <= target and lo <= ea <= target + window):
                        print(f'{pc:08x} {DOPS[op]} r{rt},{s16(imm)}(r{ra}) base {regs[ra]:#x} -> {ea:#x}')
                if op in (32, 33, 34, 35, 40, 41, 42, 43, 46):
                    regs.pop(rt, None)
                if op in (33, 35, 37, 39, 41, 43, 45):
                    regs.pop(ra, None)
                continue
            if op == 18 and (w & 1):
                for r in (0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12):
                    regs.pop(r, None)
                continue
            if op == 31:
                xo = (w >> 1) & 0x3ff
                if xo in XOPS:
                    va = regs.get(ra) if ra != 0 else 0
                    vb = regs.get(rb)
                    for v, nm in ((va, f'r{ra}'), (vb, f'r{rb}')):
                        if v is not None and lo <= v <= target:
                            print(f'{pc:08x} {XOPS[xo]} r{rt},r{ra},r{rb}  {nm}={v:#x}')
                    if xo in (23, 55, 87, 119, 279, 311, 343, 375):
                        regs.pop(rt, None)
                    if xo in (55, 119, 183, 247, 311, 375, 439):
                        regs.pop(ra, None)
                    continue
                if xo == 266:  # add rT,rA,rB
                    va, vb = regs.get(ra), regs.get(rb)
                    for v in (va, vb):
                        if v is not None and lo <= v <= target:
                            print(f'{pc:08x} add r{rt},r{ra},r{rb}  base {v:#x}')
                    regs.pop(rt, None)
                    continue
                if xo == 444 and rt == rb:  # mr rA,rS (or rA,rS,rS)
                    if rt in regs:
                        regs[ra] = regs[rt]
                    else:
                        regs.pop(ra, None)
                    continue
                if xo in (28, 60, 124, 284, 316, 412, 444, 476, 24, 536, 792, 824, 954, 922, 26):
                    regs.pop(ra, None)
                elif xo in (151, 183, 215, 247, 407, 439, 662, 918, 150, 214, 663, 695, 727, 759, 983):
                    pass
                else:
                    regs.pop(rt, None)
                continue
            if op in (20, 21, 23, 25, 26, 27, 28, 29):
                regs.pop(ra, None)
                continue
            if op in (7, 8, 12, 13):
                regs.pop(rt, None)
                continue


if __name__ == '__main__':
    main()
