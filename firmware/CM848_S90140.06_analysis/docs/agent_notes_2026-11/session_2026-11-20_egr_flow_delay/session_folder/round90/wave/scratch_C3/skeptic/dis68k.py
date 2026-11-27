"""Independent 68000/CPU32 linear-sweep decoder (skeptic, batch C3).
usage: python3 dis68k.py START END [TARGET ...]   (hex)
  With targets: print only instructions whose absolute operand or tracked-base EA hits a target
  (base tracking: movea.l #imm,An / lea abs,An inside the sweep, linear, not flow-sensitive)."""
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
D = open(ROM, 'rb').read()


def w(p):
    return (D[p] << 8) | D[p + 1]


def lw(p):
    return (w(p) << 16) | w(p + 2)


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def s8(v):
    return v - 0x100 if v & 0x80 else v


CC = ['t', 'f', 'hi', 'ls', 'cc', 'cs', 'ne', 'eq', 'vc', 'vs', 'pl', 'mi', 'ge', 'lt', 'gt', 'le']
SZ = {0: 'b', 1: 'w', 2: 'l'}


class Bad(Exception):
    pass


class Ctx:
    def __init__(self):
        self.base = {}  # An -> value


def ea(p, mode, reg, size, ctx):
    """returns (text, extra_bytes, abs_or_effective_address_or_None)"""
    if mode == 0:
        return 'd%d' % reg, 0, None
    if mode == 1:
        return 'a%d' % reg, 0, None
    if mode == 2:
        b = ctx.base.get(reg)
        return '(a%d)' % reg, 0, b
    if mode == 3:
        b = ctx.base.get(reg)
        return '(a%d)+' % reg, 0, b
    if mode == 4:
        return '-(a%d)' % reg, 0, None
    if mode == 5:
        d = s16(w(p))
        b = ctx.base.get(reg)
        return '(%d,a%d)' % (d, reg), 2, (None if b is None else (b + d) & 0xffffffff)
    if mode == 6:
        ext = w(p)
        xr = ('a' if ext & 0x8000 else 'd') + str((ext >> 12) & 7)
        xs = '.l' if ext & 0x800 else '.w'
        sc = 1 << ((ext >> 9) & 3)
        if ext & 0x100:
            # full format
            bdsize = (ext >> 4) & 3
            iis = ext & 7
            n = 2
            bd = 0
            if bdsize == 2:
                bd = s16(w(p + n)); n += 2
            elif bdsize == 3:
                bd = lw(p + n); n += 4
            if iis in (2, 6):
                n += 2
            elif iis in (3, 7):
                n += 4
            return '(full bd=%x,a%d,%s%s*%d)' % (bd, reg, xr, xs, sc), n, None
        d = s8(ext & 0xff)
        b = ctx.base.get(reg)
        return '(%d,a%d,%s%s*%d)' % (d, reg, xr, xs, sc), 2, (None if b is None else ('idx', (b + d) & 0xffffffff))
    if mode == 7:
        if reg == 0:
            v = s16(w(p)) & 0xffffffff
            return '$%x.w' % v, 2, v
        if reg == 1:
            v = lw(p)
            return '$%x' % v, 4, v
        if reg == 2:
            d = s16(w(p))
            return '(%d,pc)' % d, 2, None
        if reg == 3:
            return '(d8,pc,xn)', 2, None
        if reg == 4:
            if size == 'b':
                return '#$%x' % (w(p) & 0xff), 2, None
            if size == 'w':
                return '#$%x' % w(p), 2, None
            if size == 'l':
                return '#$%x' % lw(p), 4, None
            raise Bad('imm size')
    raise Bad('ea %d %d' % (mode, reg))


def decode(p, ctx):
    """returns (text, length, list_of_(ea_value,size,role))"""
    op = w(p)
    hi = op >> 12
    hits = []
    n = 2

    def E(mode, reg, size, role):
        nonlocal n
        t, x, v = ea(p + n, mode, reg, size, ctx)
        n += x
        if v is not None:
            hits.append((v, size, role))
        return t

    m = (op >> 3) & 7
    r = op & 7
    if hi == 0:
        if op & 0x0100 and ((op >> 3) & 7) != 1:  # dynamic bit op
            kind = ['btst', 'bchg', 'bclr', 'bset'][(op >> 6) & 3]
            t = E(m, r, 'b', kind)
            return '%s d%d,%s' % (kind, (op >> 9) & 7, t), n, hits
        if op & 0x0100:
            raise Bad('movep')
        top = (op >> 9) & 7
        if top == 4:  # static bit op
            kind = ['btst', 'bchg', 'bclr', 'bset'][(op >> 6) & 3]
            bit = w(p + 2) & 0xff
            n = 4
            t = E(m, r, 'b', kind)
            return '%s #%d,%s' % (kind, bit, t), n, hits
        names = {0: 'ori', 1: 'andi', 2: 'subi', 3: 'addi', 5: 'eori', 6: 'cmpi'}
        if top not in names:
            raise Bad('grp0')
        sz = (op >> 6) & 3
        if sz == 3:
            raise Bad('grp0 sz3')
        s = SZ[sz]
        if m == 7 and r == 4:
            return '%s.%s #...,ccr/sr' % (names[top], s), 4, hits
        it, x, _ = ea(p + 2, 7, 4, s, ctx)
        n = 2 + x
        t = E(m, r, s, names[top])
        return '%s.%s %s,%s' % (names[top], s, it, t), n, hits
    if hi in (1, 2, 3):
        s = {1: 'b', 3: 'w', 2: 'l'}[hi]
        src = E(m, r, s, 'read')
        dr = (op >> 9) & 7
        dm = (op >> 6) & 7
        if dm == 1:
            if s == 'b':
                raise Bad('movea.b')
            # movea
            if m == 7 and r == 4 and s == 'l':
                ctx.base[dr] = lw(p + 2)
            elif m == 7 and r == 1 and s == 'l':
                ctx.base.pop(dr, None)  # pointer load from memory: unknown
            else:
                ctx.base.pop(dr, None)
            return 'movea.%s %s,a%d' % (s, src, dr), n, hits
        dst = E(dm, dr, s, 'write')
        return 'move.%s %s,%s' % (s, src, dst), n, hits
    if hi == 4:
        if op == 0x4e75:
            return 'rts', 2, hits
        if op == 0x4e71:
            return 'nop', 2, hits
        if op == 0x4e73:
            return 'rte', 2, hits
        if op == 0x4e77:
            return 'rtr', 2, hits
        if op == 0x4afc:
            return 'illegal', 2, hits
        if op == 0x4afa:
            return 'bgnd', 2, hits
        if op & 0xfff8 == 0x4e50:
            return 'link a%d,#%d' % (r, s16(w(p + 2))), 4, hits
        if op & 0xfff8 == 0x4e58:
            return 'unlk a%d' % r, 2, hits
        if op & 0xfff0 == 0x4e40:
            return 'trap #%d' % (op & 15), 2, hits
        if op & 0xfff8 == 0x4840:
            return 'swap d%d' % r, 2, hits
        if op & 0xfff8 == 0x4880:
            return 'ext.w d%d' % r, 2, hits
        if op & 0xfff8 == 0x48c0:
            return 'ext.l d%d' % r, 2, hits
        if op & 0xfff8 == 0x49c0:
            return 'extb.l d%d' % r, 2, hits
        if op & 0xfff0 == 0x4e60:
            return 'move usp', 2, hits
        if op & 0xffc0 == 0x4e80:
            t = E(m, r, 'l', 'jsr')
            return 'jsr %s' % t, n, hits
        if op & 0xffc0 == 0x4ec0:
            t = E(m, r, 'l', 'jmp')
            return 'jmp %s' % t, n, hits
        if op & 0xf1c0 == 0x41c0:  # lea
            an = (op >> 9) & 7
            t, x, v = ea(p + 2, m, r, 'l', ctx)
            n = 2 + x
            if m == 7 and r in (0, 1):
                ctx.base[an] = v
            elif m == 5 and ctx.base.get(r) is not None:
                ctx.base[an] = (ctx.base[r] + s16(w(p + 2))) & 0xffffffff
            else:
                ctx.base.pop(an, None)
            if v is not None and not isinstance(v, tuple):
                hits.append((v, 'l', 'lea'))
            return 'lea %s,a%d' % (t, an), n, hits
        if op & 0xffc0 == 0x4840:
            t = E(m, r, 'l', 'pea')
            return 'pea %s' % t, n, hits
        if op & 0xfb80 == 0x4880:  # movem
            s = 'l' if op & 0x40 else 'w'
            mask = w(p + 2)
            n = 4
            t = E(m, r, s, 'movem')
            # memory to registers is nearly always the epilogue (then rts); later code is another
            # branch of the same function, where the prologue bases still hold: keep them.
            return 'movem.%s %04x,%s%s' % (s, mask, t, ' (->regs)' if op & 0x400 else ''), n, hits
        if op & 0xffc0 == 0x4c00:
            ext = w(p + 2)
            n = 4
            t = E(m, r, 'l', 'mul.l')
            return 'mul%s.l %s' % ('s' if ext & 0x800 else 'u', t), n, hits
        if op & 0xffc0 == 0x4c40:
            ext = w(p + 2)
            n = 4
            t = E(m, r, 'l', 'div.l')
            return 'div%s.l %s' % ('s' if ext & 0x800 else 'u', t), n, hits
        if op & 0xff00 == 0x4a00:
            sz = (op >> 6) & 3
            if sz == 3:
                t = E(m, r, 'b', 'tas')
                return 'tas %s' % t, n, hits
            s = SZ[sz]
            t = E(m, r, s, 'tst')
            return 'tst.%s %s' % (s, t), n, hits
        for base, nm in ((0x4000, 'negx'), (0x4200, 'clr'), (0x4400, 'neg'), (0x4600, 'not')):
            if op & 0xff00 == base:
                sz = (op >> 6) & 3
                if sz == 3:
                    t = E(m, r, 'w', 'srccr')
                    return 'move sr/ccr %s' % t, n, hits
                s = SZ[sz]
                t = E(m, r, s, nm)
                return '%s.%s %s' % (nm, s, t), n, hits
        if op & 0xffc0 == 0x4800:
            t = E(m, r, 'b', 'nbcd')
            return 'nbcd %s' % t, n, hits
        if op & 0xf1c0 == 0x4180:
            t = E(m, r, 'w', 'chk')
            return 'chk %s,d%d' % (t, (op >> 9) & 7), n, hits
        if op & 0xf1c0 == 0x4100:
            t = E(m, r, 'l', 'chk')
            return 'chk.l %s,d%d' % (t, (op >> 9) & 7), n, hits
        raise Bad('grp4 %04x' % op)
    if hi == 5:
        sz = (op >> 6) & 3
        cond = (op >> 8) & 15
        if sz == 3:
            if m == 1:
                return 'db%s d%d,%x' % (CC[cond], r, (p + 2 + s16(w(p + 2))) & 0xffffff), 4, hits
            t = E(m, r, 'b', 'scc')
            return 's%s %s' % (CC[cond], t), n, hits
        s = SZ[sz]
        q = (op >> 9) & 7 or 8
        nm = 'subq' if op & 0x100 else 'addq'
        t = E(m, r, s, nm)
        if m == 1:
            b = ctx.base.get(r)
            if b is not None:
                ctx.base[r] = (b - q if op & 0x100 else b + q) & 0xffffffff
        return '%s.%s #%d,%s' % (nm, s, q, t), n, hits
    if hi == 6:
        cond = (op >> 8) & 15
        d = op & 0xff
        if d == 0:
            tgt = p + 2 + s16(w(p + 2)); n = 4
        elif d == 0xff:
            tgt = p + 2 + lw(p + 2); n = 6
        else:
            tgt = p + 2 + s8(d)
        nm = 'bra' if cond == 0 else ('bsr' if cond == 1 else 'b' + CC[cond])
        return '%s %x' % (nm, tgt & 0xffffff), n, hits
    if hi == 7:
        if op & 0x100:
            raise Bad('moveq bit8')
        return 'moveq #%d,d%d' % (s8(op & 0xff), (op >> 9) & 7), 2, hits
    if hi in (8, 9, 11, 12, 13):
        dr = (op >> 9) & 7
        opm = (op >> 6) & 7
        nm = {8: 'or', 9: 'sub', 11: 'cmp', 12: 'and', 13: 'add'}[hi]
        if hi in (8, 12) and opm in (3, 7):
            nm2 = {8: ('divu', 'divs'), 12: ('mulu', 'muls')}[hi][opm == 7]
            t = E(m, r, 'w', nm2)
            return '%s.w %s,d%d' % (nm2, t, dr), n, hits
        if hi in (9, 11, 13) and opm in (3, 7):
            s = 'w' if opm == 3 else 'l'
            nm2 = {9: 'suba', 11: 'cmpa', 13: 'adda'}[hi]
            t = E(m, r, s, nm2)
            ctx.base.pop(dr, None) if hi != 11 else None
            return '%s.%s %s,a%d' % (nm2, s, t, dr), n, hits
        s = SZ[opm & 3]
        if opm & 4:
            if hi == 11:
                if m == 1:
                    return 'cmpm', 2, hits
                t = E(m, r, s, 'eor')
                return 'eor.%s d%d,%s' % (s, dr, t), n, hits
            if m in (0, 1) and hi in (8, 9, 12, 13):
                nm2 = {8: 'sbcd', 9: 'subx', 12: ('abcd' if opm == 4 else 'exg'), 13: 'addx'}[hi]
                return '%s' % nm2, 2, hits
            t = E(m, r, s, nm + '_to_mem')
            return '%s.%s d%d,%s' % (nm, s, dr, t), n, hits
        t = E(m, r, s, nm)
        return '%s.%s %s,d%d' % (nm, s, t, dr), n, hits
    if hi == 14:
        sz = (op >> 6) & 3
        if sz == 3:
            kind = ['as', 'ls', 'rox', 'ro'][(op >> 9) & 3]
            t = E(m, r, 'w', 'shiftmem')
            return '%s%s.w %s' % (kind, 'l' if op & 0x100 else 'r', t), n, hits
        kind = ['as', 'ls', 'rox', 'ro'][(op >> 3) & 3]
        cnt = (op >> 9) & 7
        if op & 0x20:
            c = 'd%d' % cnt
        else:
            c = '#%d' % (cnt or 8)
        return '%s%s.%s %s,d%d' % (kind, 'l' if op & 0x100 else 'r', SZ[sz], c, r), 2, hits
    if hi == 15:
        if op & 0xffc0 == 0xf800:  # tbl
            ext = w(p + 2)
            n = 4
            t = E(m, r, 'w', 'tbl')
            return 'tbl %s ext=%04x' % (t, ext), n, hits
        raise Bad('f-line %04x' % op)
    raise Bad('a-line %04x' % op)


def sweep(start, end, targets=None, show_all=True):
    ctx = Ctx()
    p = start
    out = []
    while p < end:
        try:
            t, n, hits = decode(p, ctx)
        except Bad as e:
            out.append((p, '.word %04x   ; %s' % (w(p), e), []))
            p += 2
            continue
        except IndexError:
            break
        out.append((p, t, hits))
        p += n
    for p, t, hits in out:
        raw = ' '.join('%04x' % w(q) for q in range(p, p + 2))
        if targets:
            hh = []
            for v, s, role in hits:
                vv = v[1] if isinstance(v, tuple) else v
                if vv in targets or (isinstance(v, tuple) and any(vv <= tg < vv + 64 for tg in targets)):
                    hh.append((v, s, role))
            if hh:
                print('%06x: %-50s ; %s' % (p, t, ', '.join('%s %s %s' % (('idx+%x' % v[1]) if isinstance(v, tuple) else '%x' % v, s, role) for v, s, role in hh)))
        else:
            print('%06x: %s' % (p, t))
    return out


if __name__ == '__main__':
    a = sys.argv[1:]
    st = int(a[0], 16)
    en = int(a[1], 16)
    tg = set(int(x, 16) for x in a[2:])
    sweep(st, en, tg or None)
