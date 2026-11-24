"""Minimal 68000 / CPU32 decoder for the CM550 ROM (lengths + sizes + operands), linear sweep.
usage: python3 m68k.py [-q] <start_hex> <end_hex> [target_hex ...]
  -q : print only lines that mention a target (abs.L operand or #imm equal to a target), plus
       every access through an address register that was last loaded with a target value
       (movea.l #target / lea target) inside the sweep, with 1 line of context."""
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
data = open(ROM, 'rb').read()


def w(p):
    return (data[p] << 8) | data[p + 1]


def l(p):
    return (w(p) << 16) | w(p + 2)


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def s8(v):
    return v - 0x100 if v & 0x80 else v


SZ = {0: 'b', 1: 'w', 2: 'l'}
CC = ['t', 'f', 'hi', 'ls', 'cc', 'cs', 'ne', 'eq', 'vc', 'vs', 'pl', 'mi', 'ge', 'lt', 'gt', 'le']


class Bad(Exception):
    pass


def index_ext(p, base):
    ext = w(p)
    reg = ('a' if ext & 0x8000 else 'd') + str((ext >> 12) & 7)
    rs = '.l' if ext & 0x800 else '.w'
    scale = 1 << ((ext >> 9) & 3)
    if not (ext & 0x100):
        d = s8(ext & 0xff)
        return '(%d,%s,%s%s*%d)' % (d, base, reg, rs, scale), 2
    # full format
    bs = (ext >> 7) & 1
    is_ = (ext >> 6) & 1
    bdsize = (ext >> 4) & 3
    iis = ext & 7
    n = 2
    bd = 0
    if bdsize == 2:
        bd = s16(w(p + n)); n += 2
    elif bdsize == 3:
        bd = l(p + n); n += 4
    if iis in (2, 6):
        n += 2
    elif iis in (3, 7):
        n += 4
    return '(full bd=%x,%s%s,%s%s*%d)' % (bd, '' if bs else base, '', '' if is_ else reg, rs, scale), n


def ea(mode, reg, size, p):
    """returns (text, extension_length, abs_address_or_None)"""
    if mode == 0:
        return 'd%d' % reg, 0, None
    if mode == 1:
        return 'a%d' % reg, 0, None
    if mode == 2:
        return '(a%d)' % reg, 0, None
    if mode == 3:
        return '(a%d)+' % reg, 0, None
    if mode == 4:
        return '-(a%d)' % reg, 0, None
    if mode == 5:
        return '(%d,a%d)' % (s16(w(p)), reg), 2, None
    if mode == 6:
        t, n = index_ext(p, 'a%d' % reg)
        return t, n, None
    if mode == 7:
        if reg == 0:
            v = s16(w(p)) & 0xffffffff
            return '$%x.w' % v, 2, v
        if reg == 1:
            v = l(p)
            return '$%x' % v, 4, v
        if reg == 2:
            return '(%d,pc)' % s16(w(p)), 2, None
        if reg == 3:
            t, n = index_ext(p, 'pc')
            return t, n, None
        if reg == 4:
            if size == 'l':
                return '#$%x' % l(p), 4, ('imm', l(p))
            if size == 'b':
                return '#$%x' % (w(p) & 0xff), 2, ('imm', w(p) & 0xff)
            return '#$%x' % w(p), 2, ('imm', w(p))
    raise Bad('ea %d %d' % (mode, reg))


def decode(p):
    """returns (length, text, [abs addresses], [immediates])"""
    op = w(p)
    line = op >> 12
    n = 2
    abss = []
    imms = []

    def E(mode, reg, size):
        nonlocal n
        t, k, v = ea(mode, reg, size, p + n)
        n += k
        if isinstance(v, tuple):
            imms.append(v[1])
        elif v is not None:
            abss.append(v)
        return t

    m = (op >> 3) & 7
    r = op & 7
    if line == 0:
        if op in (0x003C, 0x023C, 0x0A3C):
            t = '%s #$%x,ccr' % ({0x003C: 'ori', 0x023C: 'andi', 0x0A3C: 'eori'}[op], w(p + 2) & 0xff)
            return 4, t, abss, imms
        if op in (0x007C, 0x027C, 0x0A7C):
            t = '%s #$%x,sr' % ({0x007C: 'ori', 0x027C: 'andi', 0x0A7C: 'eori'}[op], w(p + 2))
            return 4, t, abss, imms
        if op & 0x0100:
            if m == 1:
                return 4, 'movep', abss, imms
            typ = ['btst', 'bchg', 'bclr', 'bset'][(op >> 6) & 3]
            dn = (op >> 9) & 7
            sz = 'l' if m == 0 else 'b'
            t = E(m, r, 'b')
            return n, '%s.%s d%d,%s' % (typ, sz, dn, t), abss, imms
        kind = (op >> 9) & 7
        size = (op >> 6) & 3
        if kind == 4:
            typ = ['btst', 'bchg', 'bclr', 'bset'][size]
            bit = w(p + 2) & 0xff
            n = 4
            sz = 'l' if m == 0 else 'b'
            t = E(m, r, 'b')
            return n, '%s.%s #%d,%s' % (typ, sz, bit, t), abss, imms
        if size == 3:
            if kind in (0, 1, 2):  # cmp2 / chk2
                n = 4
                szc = {0: 'b', 1: 'w', 2: 'l'}[kind]
                t = E(m, r, szc)
                return n, 'cmp2/chk2.%s %s' % (szc, t), abss, imms
            raise Bad('line0 size3')
        if kind == 7:
            n = 4
            t = E(m, r, SZ[size])
            return n, 'moves.%s %s' % (SZ[size], t), abss, imms
        name = {0: 'ori', 1: 'andi', 2: 'subi', 3: 'addi', 5: 'eori', 6: 'cmpi'}[kind]
        szs = SZ[size]
        src = E(7, 4, szs)
        dst = E(m, r, szs)
        return n, '%s.%s %s,%s' % (name, szs, src, dst), abss, imms
    if line in (1, 2, 3):
        szs = {1: 'b', 3: 'w', 2: 'l'}[line]
        src = E(m, r, szs)
        dreg = (op >> 9) & 7
        dmode = (op >> 6) & 7
        dst = E(dmode, dreg, szs)
        name = 'movea' if dmode == 1 else 'move'
        return n, '%s.%s %s,%s' % (name, szs, src, dst), abss, imms
    if line == 4:
        fixed = {0x4AFC: 'illegal', 0x4E70: 'reset', 0x4E71: 'nop', 0x4E73: 'rte', 0x4E75: 'rts',
                 0x4E76: 'trapv', 0x4E77: 'rtr'}
        if op in fixed:
            return 2, fixed[op], abss, imms
        if op == 0x4E72:
            return 4, 'stop #$%x' % w(p + 2), abss, imms
        if op == 0x4E74:
            return 4, 'rtd #%d' % s16(w(p + 2)), abss, imms
        if op in (0x4E7A, 0x4E7B):
            return 4, 'movec', abss, imms
        if (op & 0xFFF0) == 0x4E40:
            return 2, 'trap #%d' % (op & 15), abss, imms
        if (op & 0xFFF8) == 0x4E50:
            return 4, 'link.w a%d,#%d' % (r, s16(w(p + 2))), abss, imms
        if (op & 0xFFF8) == 0x4808:
            return 6, 'link.l a%d,#%d' % (r, l(p + 2)), abss, imms
        if (op & 0xFFF8) == 0x4E58:
            return 2, 'unlk a%d' % r, abss, imms
        if (op & 0xFFF0) == 0x4E60:
            return 2, 'move usp', abss, imms
        if (op & 0xFFC0) == 0x4E80:
            t = E(m, r, 'l')
            return n, 'jsr %s' % t, abss, imms
        if (op & 0xFFC0) == 0x4EC0:
            t = E(m, r, 'l')
            return n, 'jmp %s' % t, abss, imms
        if (op & 0xFFF8) == 0x4840:
            return 2, 'swap d%d' % r, abss, imms
        if (op & 0xFFF8) == 0x4848:
            return 2, 'bkpt #%d' % r, abss, imms
        if (op & 0xFFC0) == 0x4840:
            t = E(m, r, 'l')
            return n, 'pea %s' % t, abss, imms
        if (op & 0xFFF8) == 0x4880:
            return 2, 'ext.w d%d' % r, abss, imms
        if (op & 0xFFF8) == 0x48C0:
            return 2, 'ext.l d%d' % r, abss, imms
        if (op & 0xFFF8) == 0x49C0:
            return 2, 'extb.l d%d' % r, abss, imms
        if (op & 0xFB80) == 0x4880:
            szs = 'l' if op & 0x40 else 'w'
            mask = w(p + 2)
            n = 4
            t = E(m, r, szs)
            if op & 0x0400:
                return n, 'movem.%s %s,#%04x' % (szs, t, mask), abss, imms
            return n, 'movem.%s #%04x,%s' % (szs, mask, t), abss, imms
        if (op & 0xFFC0) == 0x4C00:
            ext = w(p + 2)
            n = 4
            t = E(m, r, 'l')
            return n, '%s.l %s,ext=%04x' % ('muls' if ext & 0x800 else 'mulu', t, ext), abss, imms
        if (op & 0xFFC0) == 0x4C40:
            ext = w(p + 2)
            n = 4
            t = E(m, r, 'l')
            return n, '%s.l %s,ext=%04x' % ('divs' if ext & 0x800 else 'divu', t, ext), abss, imms
        if (op & 0xF1C0) == 0x41C0:
            t = E(m, r, 'l')
            return n, 'lea %s,a%d' % (t, (op >> 9) & 7), abss, imms
        if (op & 0xF1C0) == 0x4180:
            t = E(m, r, 'w')
            return n, 'chk.w %s,d%d' % (t, (op >> 9) & 7), abss, imms
        if (op & 0xF1C0) == 0x4100:
            t = E(m, r, 'l')
            return n, 'chk.l %s,d%d' % (t, (op >> 9) & 7), abss, imms
        if (op & 0xFFC0) in (0x40C0, 0x42C0, 0x44C0, 0x46C0):
            t = E(m, r, 'w')
            return n, 'move sr/ccr %s' % t, abss, imms
        if (op & 0xFF00) in (0x4000, 0x4200, 0x4400, 0x4600):
            size = (op >> 6) & 3
            name = {0x4000: 'negx', 0x4200: 'clr', 0x4400: 'neg', 0x4600: 'not'}[op & 0xFF00]
            t = E(m, r, SZ[size])
            return n, '%s.%s %s' % (name, SZ[size], t), abss, imms
        if (op & 0xFFC0) == 0x4800:
            t = E(m, r, 'b')
            return n, 'nbcd %s' % t, abss, imms
        if (op & 0xFFC0) == 0x4AC0:
            t = E(m, r, 'b')
            return n, 'tas %s' % t, abss, imms
        if (op & 0xFF00) == 0x4A00:
            size = (op >> 6) & 3
            t = E(m, r, SZ[size])
            return n, 'tst.%s %s' % (SZ[size], t), abss, imms
        raise Bad('line4 %04x' % op)
    if line == 5:
        cond = CC[(op >> 8) & 15]
        if (op & 0xF0F8) == 0x50C8:
            d = s16(w(p + 2))
            return 4, 'db%s d%d,$%x' % (cond, r, p + 2 + d), abss, imms
        if (op & 0xF0F8) == 0x50F8 and r in (2, 3, 4):
            return {2: 4, 3: 6, 4: 2}[r], 'trap%s' % cond, abss, imms
        if (op & 0xF0C0) == 0x50C0:
            t = E(m, r, 'b')
            return n, 's%s %s' % (cond, t), abss, imms
        size = (op >> 6) & 3
        q = (op >> 9) & 7 or 8
        t = E(m, r, SZ[size])
        return n, '%s.%s #%d,%s' % ('subq' if op & 0x100 else 'addq', SZ[size], q, t), abss, imms
    if line == 6:
        cond = (op >> 8) & 15
        name = {0: 'bra', 1: 'bsr'}.get(cond, 'b' + CC[cond])
        d8 = op & 0xff
        if d8 == 0:
            d = s16(w(p + 2)); n = 4
        elif d8 == 0xff:
            d = l(p + 2)
            if d & 0x80000000:
                d -= 1 << 32
            n = 6
        else:
            d = s8(d8)
        return n, '%s $%x' % (name, p + 2 + d), abss, imms
    if line == 7:
        return 2, 'moveq #%d,d%d' % (s8(op & 0xff), (op >> 9) & 7), abss, imms
    if line in (8, 9, 0xB, 0xC, 0xD):
        dn = (op >> 9) & 7
        opm = (op >> 6) & 7
        if line == 8:
            if opm == 3:
                t = E(m, r, 'w'); return n, 'divu.w %s,d%d' % (t, dn), abss, imms
            if opm == 7:
                t = E(m, r, 'w'); return n, 'divs.w %s,d%d' % (t, dn), abss, imms
            if (op & 0x1F0) == 0x100:
                return 2, 'sbcd', abss, imms
            name = 'or'
        elif line == 0xC:
            if opm == 3:
                t = E(m, r, 'w'); return n, 'mulu.w %s,d%d' % (t, dn), abss, imms
            if opm == 7:
                t = E(m, r, 'w'); return n, 'muls.w %s,d%d' % (t, dn), abss, imms
            if (op & 0x1F0) == 0x100:
                return 2, 'abcd', abss, imms
            if (op & 0x1F8) in (0x140, 0x148, 0x188):
                return 2, 'exg', abss, imms
            name = 'and'
        elif line in (9, 0xD):
            name = 'sub' if line == 9 else 'add'
            if opm in (3, 7):
                szs = 'w' if opm == 3 else 'l'
                t = E(m, r, szs)
                return n, '%sa.%s %s,a%d' % (name, szs, t, dn), abss, imms
            if opm in (4, 5, 6) and m in (0, 1):
                return 2, '%sx.%s' % (name, SZ[opm - 4]), abss, imms
        else:  # 0xB
            if opm in (3, 7):
                szs = 'w' if opm == 3 else 'l'
                t = E(m, r, szs)
                return n, 'cmpa.%s %s,a%d' % (szs, t, dn), abss, imms
            if opm in (4, 5, 6):
                if m == 1:
                    return 2, 'cmpm.%s' % SZ[opm - 4], abss, imms
                t = E(m, r, SZ[opm - 4])
                return n, 'eor.%s d%d,%s' % (SZ[opm - 4], dn, t), abss, imms
            name = 'cmp'
        if opm <= 2:
            t = E(m, r, SZ[opm])
            return n, '%s.%s %s,d%d' % (name, SZ[opm], t, dn), abss, imms
        t = E(m, r, SZ[opm - 4])
        return n, '%s.%s d%d,%s' % (name, SZ[opm - 4], dn, t), abss, imms
    if line == 0xE:
        if (op & 0xC0) == 0xC0:
            if op & 0x0800:
                raise Bad('bitfield')
            typ = ['as', 'ls', 'rox', 'ro'][(op >> 9) & 3]
            t = E(m, r, 'w')
            return n, '%s%s.w %s' % (typ, 'l' if op & 0x100 else 'r', t), abss, imms
        size = (op >> 6) & 3
        typ = ['as', 'ls', 'rox', 'ro'][(op >> 3) & 3]
        cnt = (op >> 9) & 7
        src = ('d%d' % cnt) if op & 0x20 else ('#%d' % (cnt or 8))
        return 2, '%s%s.%s %s,d%d' % (typ, 'l' if op & 0x100 else 'r', SZ[size], src, r), abss, imms
    if line == 0xF:
        if (op & 0xFFC0) == 0xF800:  # TBL / LPSTOP (CPU32)
            ext = w(p + 2)
            n = 4
            if op == 0xF800 and ext == 0x01C0:
                return 6, 'lpstop', abss, imms
            if ext & 0x0100 == 0 or True:
                # table form: <ea>,Dx when bit 8 of ext is 1? register form uses Dym:Dyn
                if (ext >> 8) & 1:
                    t = E(m, r, SZ.get((ext >> 6) & 3, 'w'))
                    return n, 'tbl.%s %s ext=%04x' % (SZ.get((ext >> 6) & 3, '?'), t, ext), abss, imms
                return n, 'tbl(reg) ext=%04x' % ext, abss, imms
        raise Bad('lineF %04x' % op)
    raise Bad('lineA %04x' % op)


def sweep(start, end):
    out = []
    p = start
    while p < end:
        try:
            n, t, a, im = decode(p)
        except Bad as e:
            n, t, a, im = 2, '<bad %04x: %s>' % (w(p), e), [], []
        out.append((p, n, t, a, im))
        p += n
    return out


if __name__ == '__main__':
    args = sys.argv[1:]
    quiet = False
    if args and args[0] == '-q':
        quiet = True
        args = args[1:]
    start = int(args[0], 16)
    end = int(args[1], 16)
    targets = set(int(t, 16) for t in args[2:])
    out = sweep(start, end)
    areg = {}
    marks = []
    for i, (p, n, t, a, im) in enumerate(out):
        mk = ''
        if any(x in targets for x in a) or any(x in targets for x in im):
            mk = '>>'
        # track movea.l #imm,An / lea abs,An
        import re
        mm = re.match(r'(movea\.l #\$([0-9a-f]+)|lea \$([0-9a-f]+)),a(\d)', t)
        if mm:
            val = int(mm.group(2) or mm.group(3), 16)
            areg[int(mm.group(4))] = val
        else:
            mm2 = re.search(r',a(\d)$', t)
            if mm2 and (t.startswith('movea') or t.startswith('lea') or t.startswith('adda') or t.startswith('suba')):
                areg.pop(int(mm2.group(1)), None)
        for reg, val in areg.items():
            if val in targets and re.search(r'[(,]a%d[)]' % reg, t) and not t.startswith('movea.l #') and not t.startswith('lea $'):
                mk = '>>'
                t = t + '   ; a%d=$%x' % (reg, val)
        if t.startswith('jsr') or t.startswith('bsr') or t.startswith('rts'):
            pass
        marks.append(mk)
        out[i] = (p, n, t, a, im)
    keep = set(range(len(out))) if not quiet else set()
    if quiet:
        for i, mk in enumerate(marks):
            if mk:
                keep.update(range(max(0, i - 1), min(len(out), i + 2)))
    for i in sorted(keep):
        p, n, t, a, im = out[i]
        print('%2s %05x: %-60s %s' % (marks[i], p, t, data[p:p + n].hex()))
