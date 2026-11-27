#!/usr/bin/env python3
"""Disassemble CM550 ROM bytes with llvm-mc (m68k, 68020), one instruction at a time, so
an undecodable instruction (llvm's m68k decoder misses some cmp forms) does not desync the
rest. Usage: dis68k.py ROM START END   (hex addresses)"""
import subprocess
import sys
import re

rom = open(sys.argv[1], 'rb').read()
start = int(sys.argv[2], 16)
end = int(sys.argv[3], 16)


def ea_ext_len(mode, reg, size):
    if mode in (0, 1, 2, 3, 4):
        return 0
    if mode == 5:
        return 2
    if mode == 6:
        return 2  # brief extension word (CPU32 has no memory indirect)
    if mode == 7:
        if reg == 0:
            return 2
        if reg == 1:
            return 4
        if reg in (2, 3):
            return 2
        if reg == 4:
            return 4 if size == 4 else 2
    return None


def fallback(addr):
    w = (rom[addr] << 8) | rom[addr + 1]
    top = w >> 12
    if top == 7 and not (w & 0x100):
        imm = w & 0xff
        if imm >= 0x80:
            imm -= 0x100
        return 2, 'moveq #%d, %%d%d   [manual decode]' % (imm, (w >> 9) & 7)
    def eatext(mode, r, ext):
        if mode == 7 and r == 1:
            return '$%x' % int.from_bytes(ext, 'big')
        if mode == 5:
            return '(%d,%%a%d)' % (int.from_bytes(ext, 'big', signed=True), r)
        if mode == 0:
            return '%%d%d' % r
        if mode == 1:
            return '%%a%d' % r
        if mode == 2:
            return '(%%a%d)' % r
        if mode == 7 and r == 4:
            return '#%d' % int.from_bytes(ext, 'big', signed=True)
        return 'mode%d/reg%d' % (mode, r)
    if (w & 0xffc0) == 0x4840:
        mode = (w >> 3) & 7
        r = w & 7
        n = ea_ext_len(mode, r, 4)
        return 2 + n, 'pea %s   [manual decode]' % eatext(mode, r, rom[addr + 2:addr + 2 + n])
    if top == 5 and ((w >> 6) & 3) != 3:
        size = {0: 1, 1: 2, 2: 4}[(w >> 6) & 3]
        mode = (w >> 3) & 7
        r = w & 7
        n = ea_ext_len(mode, r, size)
        q = (w >> 9) & 7 or 8
        nm = 'subq' if w & 0x100 else 'addq'
        return 2 + n, '%s.%s #%d, %s   [manual decode]' % (nm, {1: 'b', 2: 'w', 4: 'l'}[size], q,
                                                          eatext(mode, r, rom[addr + 2:addr + 2 + n]))
    if (w >> 8) in (0x00, 0x02, 0x04, 0x06, 0x0a, 0x0c) and ((w >> 6) & 3) != 3:
        size = {0: 1, 1: 2, 2: 4}[(w >> 6) & 3]
        il = 4 if size == 4 else 2
        imm = int.from_bytes(rom[addr + 2:addr + 2 + il], 'big', signed=True)
        mode = (w >> 3) & 7
        r = w & 7
        n = ea_ext_len(mode, r, size)
        nm = {0x00: 'ori', 0x02: 'andi', 0x04: 'subi', 0x06: 'addi', 0x0a: 'eori', 0x0c: 'cmpi'}[w >> 8]
        return 2 + il + n, '%s.%s #%d, %s   [manual decode]' % (
            nm, {1: 'b', 2: 'w', 4: 'l'}[size], imm, eatext(mode, r, rom[addr + 2 + il:addr + 2 + il + n]))
    if (w & 0xffc0) == 0x4c00:
        mode = (w >> 3) & 7
        r = w & 7
        e = int.from_bytes(rom[addr + 2:addr + 4], 'big')
        n = ea_ext_len(mode, r, 4)
        signed = 's' if e & 0x800 else 'u'
        return 4 + n, 'mul%s.l %s, %%d%d (ext %04x)   [manual decode]' % (
            signed, eatext(mode, r, rom[addr + 4:addr + 4 + n]), (e >> 12) & 7, e)
    if (w >> 8) in (0x40, 0x42, 0x44, 0x46, 0x4a) and ((w >> 6) & 3) != 3:
        size = {0: 1, 1: 2, 2: 4}[(w >> 6) & 3]
        mode = (w >> 3) & 7
        r = w & 7
        n = ea_ext_len(mode, r, size)
        if n is None:
            return None
        ext = rom[addr + 2:addr + 2 + n]
        nm = {0x40: 'negx', 0x42: 'clr', 0x44: 'neg', 0x46: 'not', 0x4a: 'tst'}[w >> 8]
        sz = {1: 'b', 2: 'w', 4: 'l'}[size]
        if mode == 7 and r == 1:
            eas = '$%x' % int.from_bytes(ext, 'big')
        elif mode == 5:
            eas = '(%d,%%a%d)' % (int.from_bytes(ext, 'big', signed=True), r)
        elif mode == 0:
            eas = '%%d%d' % r
        elif mode == 2:
            eas = '(%%a%d)' % r
        else:
            eas = 'mode%d/reg%d' % (mode, r)
        return 2 + n, '%s.%s %s   [manual decode]' % (nm, sz, eas)
    if top in (0xb, 0x8, 0x9, 0xc, 0xd):
        reg = (w >> 9) & 7
        opmode = (w >> 6) & 7
        mode = (w >> 3) & 7
        r = w & 7
        size = {0: 1, 1: 2, 2: 4, 4: 1, 5: 2, 6: 4, 3: 2, 7: 4}[opmode]
        n = ea_ext_len(mode, r, size)
        if n is None:
            return None
        names = {0xb: 'cmp/eor', 0x8: 'or', 0x9: 'sub', 0xc: 'and', 0xd: 'add'}
        sz = {1: 'b', 2: 'w', 4: 'l'}[size]
        ext = rom[addr + 2:addr + 2 + n]
        if mode == 7 and r == 1:
            eas = '$%x' % int.from_bytes(ext, 'big')
        elif mode == 7 and r == 0:
            eas = '$%x.w' % int.from_bytes(ext, 'big')
        elif mode == 5:
            eas = '(%d,%%a%d)' % (int.from_bytes(ext, 'big', signed=True), r)
        elif mode == 2:
            eas = '(%%a%d)' % r
        elif mode == 0:
            eas = '%%d%d' % r
        elif mode == 1:
            eas = '%%a%d' % r
        elif mode == 7 and r == 4:
            eas = '#%d' % int.from_bytes(ext, 'big', signed=True)
        else:
            eas = 'mode%d/reg%d' % (mode, r)
        if top == 0xb and opmode in (3, 7):
            txt = 'cmpa.%s %s, %%a%d' % (sz, eas, reg)
        elif top == 0xb and opmode < 3:
            txt = 'cmp.%s %s, %%d%d' % (sz, eas, reg)
        else:
            txt = '%s(opmode %d).%s %s, d%d' % (names[top], opmode, sz, eas, reg)
        return 2 + n, txt + '   [manual decode]'
    return None


addr = start
while addr < end:
    chunk = rom[addr:addr + 10]
    inp = ' '.join('0x%02x' % b for b in chunk)
    p = subprocess.run(['llvm-mc-18', '--disassemble', '--triple=m68k', '-mcpu=M68020',
                        '-show-encoding'], input=inp, capture_output=True, text=True)
    lines = [ln for ln in p.stdout.splitlines()
             if ln.strip() and not ln.strip().startswith('.text')]
    first_failed = p.stderr.startswith('<stdin>:1:1:')
    ok = False
    if lines and not first_failed:
        m = re.search(r'encoding: \[([^\]]*)\]', lines[0])
        if m:
            n = len(m.group(1).split(','))
            txt = lines[0].split('; encoding')[0].strip()
            print('%06x: %-30s %s' % (addr, ' '.join('%02x' % b for b in rom[addr:addr + n]), txt))
            addr += n
            ok = True
    if not ok:
        fb = fallback(addr)
        if fb:
            n, txt = fb
            print('%06x: %-30s %s' % (addr, ' '.join('%02x' % b for b in rom[addr:addr + n]), txt))
            addr += n
        else:
            print('%06x: %-30s ??? (undecoded word)' % (addr, '%02x %02x' % (rom[addr], rom[addr + 1])))
            addr += 2
