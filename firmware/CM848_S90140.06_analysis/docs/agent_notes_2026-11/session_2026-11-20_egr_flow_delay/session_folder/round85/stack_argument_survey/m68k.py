#!/usr/bin/env python3
"""Minimal CPU32 (68000 family) instruction decoder for stack-argument analysis.

decode(rom, pc) -> Insn with: length, mnemonic text, operand EAs, operation
size, flow kind (seq / call / jump / cbranch / ret / stop / bad) and target.
Only what the stack survey needs is modelled precisely: lengths, flow,
-(sp) pushes, (sp)+ pops, sp adjustments, (d16,sp)/(d16,An) accesses.
"""

SIZE_BITS = {0: 1, 1: 2, 2: 4}
MOVE_SIZE = {1: 1, 3: 2, 2: 4}
SZ = {1: 'b', 2: 'w', 4: 'l'}
CC = ['t', 'f', 'hi', 'ls', 'cc', 'cs', 'ne', 'eq', 'vc', 'vs', 'pl', 'mi',
      'ge', 'lt', 'gt', 'le']


def u16(b, p):
    return (b[p] << 8) | b[p + 1]


def s16(b, p):
    v = u16(b, p)
    return v - 0x10000 if v & 0x8000 else v


def u32(b, p):
    return (u16(b, p) << 16) | u16(b, p + 2)


def s32(b, p):
    v = u32(b, p)
    return v - 0x100000000 if v & 0x80000000 else v


def s8(v):
    return v - 0x100 if v & 0x80 else v


class BadInsn(Exception):
    pass


class EA:
    __slots__ = ('mode', 'reg', 'disp', 'addr', 'imm', 'index', 'text')

    def __init__(self, mode, reg=None, disp=None, addr=None, imm=None,
                 index=None, text=''):
        self.mode = mode      # 'Dn','An','(An)','(An)+','-(An)','(d16,An)',
        # '(idx,An)','abs.w','abs.l','(d16,PC)','(idx,PC)','#'
        self.reg = reg
        self.disp = disp
        self.addr = addr
        self.imm = imm
        self.index = index
        self.text = text

    def __repr__(self):
        return self.text


def reg_name(an, r):
    if an:
        return 'sp' if r == 7 else 'a%d' % r
    return 'd%d' % r


def decode_index(b, pos, base_an, base_reg):
    """Brief or full extension word at pos. Returns (EA, ext_len)."""
    w = u16(b, pos)
    xr = reg_name(w & 0x8000, (w >> 12) & 7) + ('.l' if w & 0x800 else '.w')
    scale = 1 << ((w >> 9) & 3)
    if scale != 1:
        xr += '*%d' % scale
    if not (w & 0x100):
        d8 = s8(w & 0xff)
        if base_an:
            return EA('(idx,An)', reg=base_reg, disp=d8, index=xr,
                      text='(%d,%s,%s)' % (d8, reg_name(1, base_reg), xr)), 2
        return EA('(idx,PC)', addr=(pos + d8) & 0xffffffff, index=xr,
                  text='(0x%x,pc,%s)' % ((pos + d8) & 0xffffffff, xr)), 2
    bs = w & 0x80
    is_ = w & 0x40
    bdsize = (w >> 4) & 3
    iis = w & 7
    if bdsize == 0:
        raise BadInsn('reserved bd size')
    ln = 2
    bd = 0
    if bdsize == 2:
        bd = s16(b, pos + 2)
        ln += 2
    elif bdsize == 3:
        bd = s32(b, pos + 2)
        ln += 4
    if (iis & 3) == 2:
        ln += 2
    elif (iis & 3) == 3:
        ln += 4
    if iis & 4 and is_:
        raise BadInsn('reserved I/IS')
    memind = iis != 0
    idx = None if is_ else xr
    if base_an:
        if bs:
            text = '(%d%s)' % (bd, (',' + idx) if idx else '')
            return EA('abs.l' if not idx and not memind else '(full)',
                      addr=bd & 0xffffffff, index=idx, text=text), ln
        text = '(%d,%s%s)' % (bd, reg_name(1, base_reg), (',' + idx) if idx else '')
        mode = '(d16,An)' if not idx and not memind else '(full,An)'
        return EA(mode, reg=base_reg, disp=bd, index=idx, text=text), ln
    # PC relative: base is the address of the extension word
    if bs:
        tgt = bd & 0xffffffff
    else:
        tgt = (pos + bd) & 0xffffffff
    text = '(0x%x%s%s)' % (tgt, '' if bs else ',pc', (',' + idx) if idx else '')
    mode = '(d16,PC)' if not idx and not memind else '(full,PC)'
    return EA(mode, addr=tgt, index=idx, text=text), ln


def decode_ea(b, pos, mode, reg, size):
    if mode == 0:
        return EA('Dn', reg=reg, text='d%d' % reg), 0
    if mode == 1:
        return EA('An', reg=reg, text=reg_name(1, reg)), 0
    if mode == 2:
        return EA('(An)', reg=reg, text='(%s)' % reg_name(1, reg)), 0
    if mode == 3:
        return EA('(An)+', reg=reg, text='(%s)+' % reg_name(1, reg)), 0
    if mode == 4:
        return EA('-(An)', reg=reg, text='-(%s)' % reg_name(1, reg)), 0
    if mode == 5:
        d = s16(b, pos)
        return EA('(d16,An)', reg=reg, disp=d,
                  text='(%d,%s)' % (d, reg_name(1, reg))), 2
    if mode == 6:
        return decode_index(b, pos, True, reg)
    if reg == 0:
        a = s16(b, pos) & 0xffffffff
        return EA('abs.w', addr=a, text='(0x%x).w' % a), 2
    if reg == 1:
        a = u32(b, pos)
        return EA('abs.l', addr=a, text='(0x%x).l' % a), 4
    if reg == 2:
        d = s16(b, pos)
        a = (pos + d) & 0xffffffff
        return EA('(d16,PC)', addr=a, text='(0x%x,pc)' % a), 2
    if reg == 3:
        return decode_index(b, pos, False, None)
    if reg == 4:
        if size == 4:
            v = u32(b, pos)
            return EA('#', imm=v, text='#0x%x' % v), 4
        v = u16(b, pos)
        if size == 1:
            v &= 0xff
        return EA('#', imm=v, text='#0x%x' % v), 2
    raise BadInsn('bad ea mode 7 reg %d' % reg)


class Insn:
    __slots__ = ('addr', 'len', 'op', 'mn', 'size', 'src', 'dst', 'flow',
                 'target', 'extra', 'raw')

    def __init__(self, addr):
        self.addr = addr
        self.len = 2
        self.op = None
        self.mn = '?'
        self.size = None
        self.src = None
        self.dst = None
        self.flow = 'seq'
        self.target = None
        self.extra = {}
        self.raw = b''

    def text(self):
        ops = []
        if self.src is not None:
            ops.append(self.src if isinstance(self.src, str) else self.src.text)
        if self.dst is not None:
            ops.append(self.dst if isinstance(self.dst, str) else self.dst.text)
        s = self.mn
        if ops:
            s += ' ' + ','.join(ops)
        return s

    def hexbytes(self):
        return ' '.join('%02x' % x for x in self.raw)


def regmask_count(mask):
    return bin(mask & 0xffff).count('1')


def decode(b, pc):
    """Decode the instruction at pc. Raises BadInsn on invalid encodings."""
    if pc + 2 > len(b):
        raise BadInsn('eof')
    op = u16(b, pc)
    i = Insn(pc)
    i.op = op
    line = op >> 12
    mode = (op >> 3) & 7
    reg = op & 7
    if line == 0:
        _line0(b, pc, op, i, mode, reg)
    elif line in (1, 2, 3):
        size = MOVE_SIZE[line]
        src, l1 = decode_ea(b, pc + 2, mode, reg, size)
        dmode = (op >> 6) & 7
        dreg = (op >> 9) & 7
        if dmode == 7 and dreg > 1:
            raise BadInsn('move dst')
        dst, l2 = decode_ea(b, pc + 2 + l1, dmode, dreg, size)
        if dmode == 1 and size == 1:
            raise BadInsn('movea.b')
        i.mn = ('movea.' if dmode == 1 else 'move.') + SZ[size]
        i.size = size
        i.src, i.dst = src, dst
        i.len = 2 + l1 + l2
    elif line == 4:
        _line4(b, pc, op, i, mode, reg)
    elif line == 5:
        sz = (op >> 6) & 3
        if sz == 3:
            cc = (op >> 8) & 0xf
            if mode == 1:
                d = s16(b, pc + 2)
                i.mn = 'db' + CC[cc]
                i.src = EA('Dn', reg=reg, text='d%d' % reg)
                i.target = (pc + 2 + d) & 0xffffffff
                i.dst = '0x%x' % i.target
                i.flow = 'cbranch'
                i.len = 4
            elif mode == 7 and reg in (2, 3, 4):
                i.mn = 'trap' + CC[cc]
                i.len = {2: 4, 3: 6, 4: 2}[reg]
            else:
                ea, l = decode_ea(b, pc + 2, mode, reg, 1)
                i.mn = 's' + CC[cc]
                i.size = 1
                i.dst = ea
                i.len = 2 + l
        else:
            size = SIZE_BITS[sz]
            data = (op >> 9) & 7 or 8
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            i.mn = ('subq.' if op & 0x100 else 'addq.') + SZ[size]
            i.size = size
            i.src = EA('#', imm=data, text='#%d' % data)
            i.dst = ea
            i.len = 2 + l
    elif line == 6:
        cc = (op >> 8) & 0xf
        d8 = op & 0xff
        if d8 == 0:
            d = s16(b, pc + 2)
            i.len = 4
            suf = '.w'
        elif d8 == 0xff:
            d = s32(b, pc + 2)
            i.len = 6
            suf = '.l'
        else:
            d = s8(d8)
            suf = '.b'
        i.target = (pc + 2 + d) & 0xffffffff
        if cc == 0:
            i.mn = 'bra' + suf
            i.flow = 'jump'
        elif cc == 1:
            i.mn = 'bsr' + suf
            i.flow = 'call'
        else:
            i.mn = 'b' + CC[cc] + suf
            i.flow = 'cbranch'
        i.dst = '0x%x' % i.target
    elif line == 7:
        if op & 0x100:
            raise BadInsn('moveq')
        v = s8(op & 0xff)
        i.mn = 'moveq'
        i.size = 4
        i.src = EA('#', imm=v & 0xffffffff, text='#%d' % v)
        i.dst = EA('Dn', reg=(op >> 9) & 7, text='d%d' % ((op >> 9) & 7))
    elif line in (8, 9, 0xb, 0xc, 0xd):
        _arith(b, pc, op, i, line, mode, reg)
    elif line == 0xe:
        sz = (op >> 6) & 3
        if sz == 3:
            if op & 0x800:
                raise BadInsn('bitfield (not CPU32)')
            ea, l = decode_ea(b, pc + 2, mode, reg, 2)
            i.mn = ['as', 'ls', 'rox', 'ro'][(op >> 9) & 3] + \
                ('l' if op & 0x100 else 'r') + '.w'
            i.size = 2
            i.dst = ea
            i.len = 2 + l
        else:
            i.mn = ['as', 'ls', 'rox', 'ro'][(op >> 3) & 3] + \
                ('l' if op & 0x100 else 'r') + '.' + SZ[SIZE_BITS[sz]]
            i.size = SIZE_BITS[sz]
            i.dst = EA('Dn', reg=reg, text='d%d' % reg)
    elif line == 0xf:
        if (op & 0xffc0) == 0xf800:
            ext = u16(b, pc + 2)
            if op == 0xf800 and ext == 0x01c0:
                i.mn = 'lpstop'
                i.len = 6
            else:
                i.mn = 'tbl'
                if mode == 0:
                    i.len = 4
                else:
                    ea, l = decode_ea(b, pc + 4, mode, reg, 2)
                    i.src = ea
                    i.len = 4 + l
        else:
            raise BadInsn('line f')
    else:
        raise BadInsn('line a')
    if pc + i.len > len(b):
        raise BadInsn('eof')
    i.raw = bytes(b[pc:pc + i.len])
    return i


def _line0(b, pc, op, i, mode, reg):
    if op in (0x003c, 0x023c, 0x0a3c, 0x007c, 0x027c, 0x0a7c):
        i.mn = {0x003c: 'ori', 0x023c: 'andi', 0x0a3c: 'eori', 0x007c: 'ori',
                0x027c: 'andi', 0x0a7c: 'eori'}[op]
        i.src = EA('#', imm=u16(b, pc + 2), text='#0x%x' % u16(b, pc + 2))
        i.dst = 'ccr' if op & 0x40 == 0 else 'sr'
        i.len = 4
        return
    if op & 0x100:
        if mode == 1:
            i.mn = 'movep'
            i.len = 4
            return
        ea, l = decode_ea(b, pc + 2, mode, reg, 1)
        i.mn = ['btst', 'bchg', 'bclr', 'bset'][(op >> 6) & 3]
        i.src = EA('Dn', reg=(op >> 9) & 7, text='d%d' % ((op >> 9) & 7))
        i.dst = ea
        i.size = 1 if mode != 0 else 4
        i.len = 2 + l
        return
    sub = (op >> 9) & 7
    sz = (op >> 6) & 3
    if sub == 4:
        bit = u16(b, pc + 2)
        ea, l = decode_ea(b, pc + 4, mode, reg, 1)
        i.mn = ['btst', 'bchg', 'bclr', 'bset'][sz]
        i.src = EA('#', imm=bit, text='#%d' % (bit & 0xff))
        i.dst = ea
        i.size = 1 if mode != 0 else 4
        i.len = 4 + l
        return
    if sub == 7:
        if sz == 3:
            raise BadInsn('moves size')
        ea, l = decode_ea(b, pc + 4, mode, reg, SIZE_BITS[sz])
        i.mn = 'moves.' + SZ[SIZE_BITS[sz]]
        i.dst = ea
        i.size = SIZE_BITS[sz]
        i.len = 4 + l
        return
    if sz == 3:
        if sub in (0, 1, 2):
            size = {0: 1, 1: 2, 2: 4}[sub]
            ea, l = decode_ea(b, pc + 4, mode, reg, size)
            i.mn = ('chk2.' if u16(b, pc + 2) & 0x800 else 'cmp2.') + SZ[size]
            i.src = ea
            i.size = size
            i.len = 4 + l
            return
        raise BadInsn('line0 sz3')
    if sub == 3 and False:
        pass
    names = {0: 'ori', 1: 'andi', 2: 'subi', 3: 'addi', 5: 'eori', 6: 'cmpi'}
    if sub not in names:
        raise BadInsn('line0 sub')
    size = SIZE_BITS[sz]
    if size == 4:
        imm = u32(b, pc + 2)
        il = 4
    else:
        imm = u16(b, pc + 2) & (0xff if size == 1 else 0xffff)
        il = 2
    if mode == 1:
        raise BadInsn('imm to An')
    ea, l = decode_ea(b, pc + 2 + il, mode, reg, size)
    i.mn = names[sub] + '.' + SZ[size]
    i.size = size
    i.src = EA('#', imm=imm, text='#0x%x' % imm)
    i.dst = ea
    i.len = 2 + il + l


def _line4(b, pc, op, i, mode, reg):
    if op & 0x100:
        if (op & 0xfff8) == 0x49c0:
            i.mn = 'extb.l'
            i.size = 4
            i.dst = EA('Dn', reg=reg, text='d%d' % reg)
            return
        t = (op >> 6) & 7
        an = (op >> 9) & 7
        if t == 7:
            ea, l = decode_ea(b, pc + 2, mode, reg, 4)
            i.mn = 'lea'
            i.size = 4
            i.src = ea
            i.dst = EA('An', reg=an, text=reg_name(1, an))
            i.len = 2 + l
            return
        if t in (6, 4):
            size = 2 if t == 6 else 4
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            i.mn = 'chk.' + SZ[size]
            i.size = size
            i.src = ea
            i.len = 2 + l
            return
        raise BadInsn('line4 bit8')
    sub = (op >> 8) & 0xf
    sz = (op >> 6) & 3
    if sub in (0, 2, 4, 6):
        if sz == 3:
            size = 2
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            nm = {0: 'move sr,', 2: 'move ccr,', 4: 'move to ccr', 6: 'move to sr'}[sub]
            i.mn = nm
            i.size = 2
            if sub in (0, 2):
                i.dst = ea
            else:
                i.src = ea
            i.len = 2 + l
            return
        size = SIZE_BITS[sz]
        ea, l = decode_ea(b, pc + 2, mode, reg, size)
        i.mn = {0: 'negx.', 2: 'clr.', 4: 'neg.', 6: 'not.'}[sub] + SZ[size]
        i.size = size
        i.dst = ea
        i.len = 2 + l
        return
    if sub == 8:
        if sz == 0:
            if mode == 1:
                i.mn = 'link.l'
                i.src = EA('An', reg=reg, text=reg_name(1, reg))
                d = s32(b, pc + 2)
                i.dst = EA('#', imm=d, text='#%d' % d)
                i.extra['link'] = (reg, d)
                i.len = 6
                return
            ea, l = decode_ea(b, pc + 2, mode, reg, 1)
            i.mn = 'nbcd'
            i.size = 1
            i.dst = ea
            i.len = 2 + l
            return
        if sz == 1:
            if mode == 0:
                i.mn = 'swap'
                i.dst = EA('Dn', reg=reg, text='d%d' % reg)
                return
            if mode == 1:
                i.mn = 'bkpt'
                return
            ea, l = decode_ea(b, pc + 2, mode, reg, 4)
            i.mn = 'pea'
            i.size = 4
            i.src = ea
            i.len = 2 + l
            return
        if mode == 0:
            i.mn = 'ext.w' if sz == 2 else 'ext.l'
            i.size = 2 if sz == 2 else 4
            i.dst = EA('Dn', reg=reg, text='d%d' % reg)
            return
        size = 2 if sz == 2 else 4
        mask = u16(b, pc + 2)
        ea, l = decode_ea(b, pc + 4, mode, reg, size)
        i.mn = 'movem.' + SZ[size]
        i.size = size
        i.src = '#0x%04x' % mask
        i.dst = ea
        i.extra['movem'] = (mask, 'to_mem')
        i.len = 4 + l
        return
    if sub == 0xa:
        if op == 0x4afc:
            i.mn = 'illegal'
            i.flow = 'stop'
            return
        if op in (0x4afa, 0x4afb):
            i.mn = 'bgnd'
            return
        if sz == 3:
            ea, l = decode_ea(b, pc + 2, mode, reg, 1)
            i.mn = 'tas'
            i.size = 1
            i.dst = ea
            i.len = 2 + l
            return
        size = SIZE_BITS[sz]
        ea, l = decode_ea(b, pc + 2, mode, reg, size)
        i.mn = 'tst.' + SZ[size]
        i.size = size
        i.src = ea
        i.len = 2 + l
        return
    if sub == 0xc:
        if sz in (0, 1):
            ext = u16(b, pc + 2)
            ea, l = decode_ea(b, pc + 4, mode, reg, 4)
            signed = ext & 0x800
            if sz == 0:
                i.mn = ('muls.l' if signed else 'mulu.l')
            else:
                i.mn = ('divs.l' if signed else 'divu.l')
            i.size = 4
            i.src = ea
            i.len = 4 + l
            return
        size = 2 if sz == 2 else 4
        mask = u16(b, pc + 2)
        ea, l = decode_ea(b, pc + 4, mode, reg, size)
        i.mn = 'movem.' + SZ[size]
        i.size = size
        i.src = ea
        i.dst = '#0x%04x' % mask
        i.extra['movem'] = (mask, 'to_reg')
        i.len = 4 + l
        return
    if sub == 0xe:
        if sz == 1:
            if (op & 0xfff0) == 0x4e40:
                i.mn = 'trap #%d' % (op & 0xf)
                return
            if (op & 0xfff8) == 0x4e50:
                d = s16(b, pc + 2)
                i.mn = 'link.w'
                i.src = EA('An', reg=reg, text=reg_name(1, reg))
                i.dst = EA('#', imm=d, text='#%d' % d)
                i.extra['link'] = (reg, d)
                i.len = 4
                return
            if (op & 0xfff8) == 0x4e58:
                i.mn = 'unlk'
                i.dst = EA('An', reg=reg, text=reg_name(1, reg))
                i.extra['unlk'] = reg
                return
            if (op & 0xfff0) == 0x4e60:
                i.mn = 'move usp'
                return
            simple = {0x4e70: 'reset', 0x4e71: 'nop', 0x4e73: 'rte',
                      0x4e75: 'rts', 0x4e76: 'trapv', 0x4e77: 'rtr'}
            if op in simple:
                i.mn = simple[op]
                if op in (0x4e73, 0x4e75, 0x4e77):
                    i.flow = 'ret'
                return
            if op == 0x4e72:
                i.mn = 'stop'
                i.len = 4
                return
            if op == 0x4e74:
                d = s16(b, pc + 2)
                i.mn = 'rtd'
                i.src = EA('#', imm=d, text='#%d' % d)
                i.flow = 'ret'
                i.extra['rtd'] = d
                i.len = 4
                return
            if op in (0x4e7a, 0x4e7b):
                i.mn = 'movec'
                i.len = 4
                return
            raise BadInsn('line4 4e')
        if sz in (2, 3):
            if mode in (0, 1, 3, 4) or (mode == 7 and reg == 4):
                raise BadInsn('jsr/jmp ea')
            ea, l = decode_ea(b, pc + 2, mode, reg, 4)
            i.mn = 'jsr' if sz == 2 else 'jmp'
            i.src = ea
            i.len = 2 + l
            i.flow = 'call' if sz == 2 else 'jump'
            if ea.mode in ('abs.w', 'abs.l', '(d16,PC)'):
                i.target = ea.addr
            return
        raise BadInsn('line4 4e sz0')
    raise BadInsn('line4 sub %x' % sub)


def _arith(b, pc, op, i, line, mode, reg):
    opmode = (op >> 6) & 7
    dreg = (op >> 9) & 7
    dn = EA('Dn', reg=dreg, text='d%d' % dreg)
    if line == 8:
        if opmode in (3, 7):
            ea, l = decode_ea(b, pc + 2, mode, reg, 2)
            i.mn = 'divu.w' if opmode == 3 else 'divs.w'
            i.size = 2
            i.src, i.dst = ea, dn
            i.len = 2 + l
            return
        if opmode in (4, 5, 6) and mode in (0, 1):
            i.mn = {4: 'sbcd', 5: 'pack', 6: 'unpk'}[opmode]
            i.len = 2 if opmode == 4 else 4
            return
        base = 'or'
    elif line == 0xc:
        if opmode in (3, 7):
            ea, l = decode_ea(b, pc + 2, mode, reg, 2)
            i.mn = 'mulu.w' if opmode == 3 else 'muls.w'
            i.size = 2
            i.src, i.dst = ea, dn
            i.len = 2 + l
            return
        if opmode == 4 and mode in (0, 1):
            i.mn = 'abcd'
            return
        if (opmode == 5 and mode in (0, 1)) or (opmode == 6 and mode == 1):
            i.mn = 'exg'
            i.extra['exg'] = (opmode, mode, dreg, reg)
            return
        base = 'and'
    elif line in (9, 0xd):
        base = 'sub' if line == 9 else 'add'
        if opmode in (3, 7):
            size = 2 if opmode == 3 else 4
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            i.mn = base + 'a.' + SZ[size]
            i.size = size
            i.src = ea
            i.dst = EA('An', reg=dreg, text=reg_name(1, dreg))
            i.len = 2 + l
            return
        if opmode in (4, 5, 6) and mode in (0, 1):
            i.mn = base + 'x.' + SZ[SIZE_BITS[opmode & 3]]
            i.size = SIZE_BITS[opmode & 3]
            if mode == 1:
                i.extra['predec_both'] = (reg, dreg)
            return
    else:  # 0xb
        if opmode in (3, 7):
            size = 2 if opmode == 3 else 4
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            i.mn = 'cmpa.' + SZ[size]
            i.size = size
            i.src = ea
            i.dst = EA('An', reg=dreg, text=reg_name(1, dreg))
            i.len = 2 + l
            return
        if opmode in (0, 1, 2):
            size = SIZE_BITS[opmode]
            ea, l = decode_ea(b, pc + 2, mode, reg, size)
            i.mn = 'cmp.' + SZ[size]
            i.size = size
            i.src, i.dst = ea, dn
            i.len = 2 + l
            return
        if mode == 1:
            i.mn = 'cmpm.' + SZ[SIZE_BITS[opmode & 3]]
            i.size = SIZE_BITS[opmode & 3]
            i.extra['cmpm'] = (reg, dreg)
            return
        size = SIZE_BITS[opmode & 3]
        ea, l = decode_ea(b, pc + 2, mode, reg, size)
        i.mn = 'eor.' + SZ[size]
        i.size = size
        i.src, i.dst = dn, ea
        i.len = 2 + l
        return
    size = SIZE_BITS[opmode & 3]
    ea, l = decode_ea(b, pc + 2, mode, reg, size)
    i.mn = base + '.' + SZ[size]
    i.size = size
    if opmode & 4:
        i.src, i.dst = dn, ea
    else:
        i.src, i.dst = ea, dn
    i.len = 2 + l
