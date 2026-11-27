#!/usr/bin/env python3
"""Find absolute-long references to DATA addresses inside a ROM window and decode the opcode word.
Usage: findabs.py START END ADDR [ADDR...]   (hex)"""
import sys
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
d = open(ROM, 'rb').read()
s = int(sys.argv[1], 16)
e = int(sys.argv[2], 16)
SZ = {0: 'b', 1: 'w', 2: 'l', 3: '?'}


def decode(op):
    """best-effort mnemonic of opcode word op (whose EA extension may hold the abs.L)"""
    hi = op >> 12
    if hi in (1, 2, 3):
        sz = {1: 'b', 3: 'w', 2: 'l'}[hi]
        src = op & 0x3f
        dst = (op >> 6) & 0x3f
        dmode = dst & 7
        dreg = dst >> 3
        if src == 0x3c:
            return 'move.%s #imm,<dst mode %d reg %d>%s' % (sz, dmode, dreg, ' [movea address constant]' if dmode == 1 else '')
        if src == 0x39 and (dmode, dreg) == (7, 1):
            return 'move.%s (abs).L,(abs).L' % sz
        if src == 0x39:
            return 'move.%s (abs).L,<dst mode %d reg %d>%s' % (sz, dmode, dreg, ' [movea]' if dmode == 1 else '')
        if (dmode, dreg) == (7, 1):
            return 'move.%s <src ea %02x>,(abs).L' % (sz, src)
        return 'move.%s src %02x dst mode %d reg %d' % (sz, src, dmode, dreg)
    if op & 0xff00 == 0x4a00 and (op >> 6) & 3 != 3:
        return 'tst.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x4200:
        return 'clr.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0c00:
        return 'cmpi.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0000:
        return 'ori.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0200:
        return 'andi.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0400:
        return 'subi.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0600:
        return 'addi.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0a00:
        return 'eori.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x0800:
        return 'bit op #imm (byte on memory)'
    if op & 0xf1c0 in (0x0100, 0x0140, 0x0180, 0x01c0):
        return 'bit op dynamic (byte on memory)'
    if op & 0xf1c0 == 0x41c0:
        return 'lea (abs).L,a%d [address]' % ((op >> 9) & 7)
    if op == 0x4879:
        return 'pea (abs).L [address]'
    if op & 0xf000 in (0xb000, 0xd000, 0x9000, 0xc000, 0x8000):
        name = {0xb000: 'cmp', 0xd000: 'add', 0x9000: 'sub', 0xc000: 'and', 0x8000: 'or'}[op & 0xf000]
        opm = (op >> 6) & 7
        if opm in (3, 7):
            return '%sa.%s a%d' % (name, 'w' if opm == 3 else 'l', (op >> 9) & 7)
        if name == 'cmp' and opm >= 4:
            return 'eor/cmpm.%s d%d' % (SZ[opm & 3], (op >> 9) & 7)
        return '%s.%s %s d%d' % (name, SZ[opm & 3], 'ea->' if opm < 4 else '<-', (op >> 9) & 7)
    if op & 0xf000 == 0x5000 and (op >> 6) & 3 != 3:
        return '%s.%s #%d' % ('subq' if op & 0x100 else 'addq', SZ[(op >> 6) & 3], ((op >> 9) & 7) or 8)
    if op & 0xffc0 == 0x4ec0:
        return 'jmp'
    if op & 0xffc0 == 0x4e80:
        return 'jsr'
    if op & 0xff00 == 0x4400:
        return 'neg.%s' % SZ[(op >> 6) & 3]
    if op & 0xff00 == 0x4600:
        return 'not.%s' % SZ[(op >> 6) & 3]
    if op & 0xf1c0 == 0xc1c0:
        return 'muls.w d%d' % ((op >> 9) & 7)
    if op & 0xf1c0 == 0xc0c0:
        return 'mulu.w d%d' % ((op >> 9) & 7)
    if op & 0xf1c0 == 0x81c0:
        return 'divs.w d%d' % ((op >> 9) & 7)
    if op & 0xf1c0 == 0x80c0:
        return 'divu.w d%d' % ((op >> 9) & 7)
    return '?'


for a in sys.argv[3:]:
    A = int(a, 16)
    pat = A.to_bytes(4, 'big')
    i = s
    found = False
    while True:
        i = d.find(pat, i, e)
        if i < 0:
            break
        found = True
        cands = []
        for back in (2, 4, 6):
            op = int.from_bytes(d[i - back:i - back + 2], 'big')
            cands.append('-%d:%04x=%s' % (back, op, decode(op)))
        print('%06x: abs %06x  before[%s] abs[%s] after[%s]  %s' % (
            i, A, d[i - 8:i].hex(' '), d[i:i + 4].hex(' '), d[i + 4:i + 8].hex(' '), ' | '.join(cands)))
        i += 2
    if not found:
        print('none for %06x in %06x-%06x' % (A, s, e))
