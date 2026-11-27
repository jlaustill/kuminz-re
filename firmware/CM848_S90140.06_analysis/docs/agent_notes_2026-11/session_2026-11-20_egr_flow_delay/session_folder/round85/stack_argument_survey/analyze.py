#!/usr/bin/env python3
"""Flow-following stack analysis of CM550 functions.

For every function entry (from the .cpp export) the code is walked from the
entry (branches followed, calls stepped over), tracking the sp offset from the
entry sp (return address at +0..+3, first argument byte at +4), link frames,
and address registers that hold sp + k. Produces:
  - per function: the reads / writes of its own argument area (entry offset >= 4)
  - per call instruction: the bytes the caller placed at the callee's +4.. (from a
    shadow of the caller's stack: which instruction wrote each byte), and the
    instruction that releases them after the call.
"""
import json
import sys

sys.path.insert(0, __file__.rsplit('/', 1)[0])
from m68k import decode, BadInsn, EA  # noqa: E402

RMW = ('add', 'sub', 'and', 'or', 'eor', 'neg', 'not', 'addq', 'subq', 'as',
       'ls', 'rox', 'ro', 'bset', 'bclr', 'bchg', 'tas', 'nbcd', 'negx',
       'addx', 'subx')
READ_ONLY_DST = ('tst', 'cmp', 'btst', 'chk', 'cmp2', 'chk2', 'cmpi', 'cmpa')


def base_mn(mn):
    return mn.split('.')[0].split(' ')[0]


class State:
    __slots__ = ('sp', 'frames', 'alias', 'shadow', 'unknown_sp', 'aconst')

    def __init__(self):
        self.aconst = {}     # An -> constant address (movea.l #imm / lea abs)
        self.sp = 0
        self.frames = {}     # An -> entry offset the frame register points at
        self.alias = {}      # An -> entry offset (An = entry_sp + k)
        self.shadow = {}     # entry offset -> (record dict, byte index)
        self.unknown_sp = False

    def copy(self):
        s = State()
        s.sp = self.sp
        s.frames = dict(self.frames)
        s.alias = dict(self.alias)
        s.shadow = dict(self.shadow)
        s.unknown_sp = self.unknown_sp
        s.aconst = dict(self.aconst)
        return s

    def purge(self):
        for k in [k for k in self.shadow if k < self.sp]:
            del self.shadow[k]


SCC = {'s' + c for c in ('t', 'f', 'hi', 'ls', 'cc', 'cs', 'ne', 'eq', 'vc', 'vs',
                         'pl', 'mi', 'ge', 'lt', 'gt', 'le')}


def access_kind(ins, which):
    b = base_mn(ins.mn)
    if which == 'src':
        return 'addr' if b in ('lea', 'pea', 'jsr', 'jmp') else 'r'
    if b in ('move', 'movea', 'clr', 'moveq', 'movem', 'moves') or b in SCC:
        return 'w'
    if b in ('tst', 'cmp', 'cmpi', 'btst', 'cmpa', 'cmpm', 'chk', 'chk2', 'cmp2'):
        return 'r'
    return 'rw'


def shift_alias_on_write(ins, st):
    """Forget alias / frame tracking for an An the instruction overwrites."""
    dst = ins.dst
    if isinstance(dst, EA) and dst.mode == 'An':
        b = base_mn(ins.mn)
        r = dst.reg
        if r == 7:
            return
        if b == 'lea' and isinstance(ins.src, EA):
            off = stack_offset_of_ea_addr(ins.src, st)
            st.alias.pop(r, None)
            if off is not None:
                st.alias[r] = off
            return
        if b == 'movea' and isinstance(ins.src, EA) and ins.src.mode == 'An':
            sr = ins.src.reg
            st.alias.pop(r, None)
            if sr == 7:
                st.alias[r] = st.sp
            elif sr in st.alias:
                st.alias[r] = st.alias[sr]
            elif sr in st.frames:
                st.alias[r] = st.frames[sr]
            return
        if b in ('adda', 'suba', 'addq', 'subq') and r in st.alias and \
                isinstance(ins.src, EA) and ins.src.mode == '#':
            v = ins.src.imm
            if ins.size == 2 and v & 0x8000:
                v -= 0x10000
            if ins.size == 4 and v & 0x80000000:
                v -= 0x100000000
            st.alias[r] += v if b in ('adda', 'addq') else -v
            return
        st.alias.pop(r, None)


def stack_offset_of_ea_addr(ea, st):
    """Entry offset that an EA's address denotes (for lea/pea), or None."""
    if ea.mode == '(An)':
        r = ea.reg
        if r == 7:
            return st.sp
        if r in st.alias:
            return st.alias[r]
        if r in st.frames:
            return st.frames[r]
    if ea.mode == '(d16,An)':
        r = ea.reg
        if r == 7:
            return st.sp + ea.disp
        if r in st.alias:
            return st.alias[r] + ea.disp
        if r in st.frames:
            return st.frames[r] + ea.disp
    return None


def ea_access(ins, ea, which, st, size, out):
    """Record a stack access for ea and apply (An)+ / -(An) side effects."""
    if not isinstance(ea, EA):
        return None
    kind = access_kind(ins, which)
    m = ea.mode
    r = ea.reg
    eff = (2 if size == 1 else size) if size else 0
    if m == '-(An)':
        if r == 7:
            st.sp -= eff
            off = st.sp
            out.append(('push', off, size, eff, kind))
            return off
        if r in st.alias:
            st.alias[r] -= eff if r == 7 else (size or 0)
            off = st.alias[r]
            out.append(('alias', off, size, size, kind))
            return off
        return None
    if m == '(An)+':
        if r == 7:
            off = st.sp
            st.sp += eff
            out.append(('pop', off, size, eff, kind))
            return off
        if r in st.alias:
            off = st.alias[r]
            st.alias[r] += size or 0
            out.append(('alias', off, size, size, kind))
            return off
        return None
    if m in ('(An)', '(d16,An)'):
        d = ea.disp if m == '(d16,An)' else 0
        if r == 7:
            off = st.sp + d
            src = 'sp'
        elif r in st.frames:
            off = st.frames[r] + d
            src = 'frame'
        elif r in st.alias:
            off = st.alias[r] + d
            src = 'alias'
        else:
            return None
        out.append((src, off, size, size, kind))
        return off
    if m == '(idx,An)' or m == '(full,An)':
        if r == 7 or r in st.frames or r in st.alias:
            base = st.sp if r == 7 else st.frames.get(r, st.alias.get(r))
            out.append(('indexed', base + (ea.disp or 0), size, size, kind))
        return None
    return None


def _step(ins, st, rec_push):
    """Apply ins to st. Returns list of stack accesses
    (how, entry_offset, width, bytes_on_stack, kind)."""
    out = []
    b = base_mn(ins.mn)
    size = ins.size
    if b == 'movem':
        mask, direction = ins.extra['movem']
        n = bin(mask).count('1')
        if direction == 'to_mem':
            ea = ins.dst
            if ea.mode == '-(An)' and ea.reg == 7:
                st.sp -= n * size
                out.append(('push', st.sp, n * size, n * size, 'w'))
                rec_push(st, ins, st.sp, n * size, n * size, 'movem')
            else:
                ea_access(ins, ea, 'dst', st, n * size, out)
        else:
            ea = ins.src
            if ea.mode == '(An)+' and ea.reg == 7:
                out.append(('pop', st.sp, n * size, n * size, 'r'))
                st.sp += n * size
                if mask & 0x8000:
                    pass
            else:
                ea_access(ins, ea, 'src', st, n * size, out)
            # movem to registers may load An
            for r in range(8):
                if mask & (1 << (8 + r)):
                    st.alias.pop(r, None)
        st.purge()
        return out
    if 'link' in ins.extra:
        r, d = ins.extra['link']
        st.sp -= 4
        rec_push(st, ins, st.sp, 4, 4, 'link')
        st.frames[r] = st.sp
        st.alias.pop(r, None)
        st.sp += d
        return out
    if 'unlk' in ins.extra:
        r = ins.extra['unlk']
        if r in st.frames:
            st.sp = st.frames.pop(r) + 4
        else:
            st.unknown_sp = True
        st.purge()
        return out
    if b == 'pea':
        off = None
        if isinstance(ins.src, EA):
            off = stack_offset_of_ea_addr(ins.src, st)
            if off is not None:
                out.append(('addr', off, None, None, 'addr'))
        st.sp -= 4
        rec_push(st, ins, st.sp, 4, 4, 'pea')
        return out
    # sp arithmetic
    if isinstance(ins.dst, EA) and ins.dst.mode == 'An' and ins.dst.reg == 7:
        src = ins.src
        if b in ('addq', 'subq', 'adda', 'suba') and isinstance(src, EA) and src.mode == '#':
            v = src.imm
            if b in ('adda', 'suba'):
                if size == 2 and v & 0x8000:
                    v -= 0x10000
                if size == 4 and v & 0x80000000:
                    v -= 0x100000000
            st.sp += v if b in ('addq', 'adda') else -v
            st.purge()
            return out
        if b == 'lea' and isinstance(src, EA):
            off = stack_offset_of_ea_addr(src, st)
            if off is not None:
                st.sp = off
                st.purge()
                return out
        if b == 'movea' and isinstance(src, EA) and src.mode == 'An':
            if src.reg in st.frames:
                st.sp = st.frames[src.reg]
                st.purge()
                return out
            if src.reg in st.alias:
                st.sp = st.alias[src.reg]
                st.purge()
                return out
        st.unknown_sp = True
        return out
    # generic: src then dst
    if ins.src is not None and isinstance(ins.src, EA):
        if b in ('lea',):
            off = stack_offset_of_ea_addr(ins.src, st)
            if off is not None:
                out.append(('addr', off, None, None, 'addr'))
        elif b in ('jsr', 'jmp'):
            pass
        else:
            ea_access(ins, ins.src, 'src', st, size, out)
    if ins.dst is not None and isinstance(ins.dst, EA):
        before = len(out)
        off = ea_access(ins, ins.dst, 'dst', st, size, out)
        for a in out[before:]:
            how, aoff, w, eff, kind = a
            if how == 'push':
                rec_push(st, ins, aoff, eff, w, 'push')
            elif kind in ('w', 'rw') and how in ('sp', 'frame', 'alias'):
                rec_push(st, ins, aoff, w, w, 'store')
    if 'predec_both' in ins.extra:
        pass
    shift_alias_on_write(ins, st)
    st.purge()
    return out


def track_aconst(ins, st):
    b = base_mn(ins.mn)
    written = set()
    dst = ins.dst
    src = ins.src
    if isinstance(dst, EA) and dst.mode == 'An':
        r = dst.reg
        if b == 'movea' and ins.size == 4 and isinstance(src, EA) and src.mode == '#':
            st.aconst[r] = src.imm
            return
        if b == 'lea' and isinstance(src, EA) and src.mode in ('abs.l', 'abs.w', '(d16,PC)'):
            st.aconst[r] = src.addr
            return
        if b == 'movea' and ins.size == 4 and isinstance(src, EA) and src.mode == 'An' \
                and src.reg in st.aconst:
            st.aconst[r] = st.aconst[src.reg]
            return
        written.add(r)
    for ea in (src, dst):
        if isinstance(ea, EA) and ea.mode in ('(An)+', '-(An)'):
            written.add(ea.reg)
    if b == 'movem' and ins.extra.get('movem', (0, ''))[1] == 'to_reg':
        mask = ins.extra['movem'][0]
        for r in range(8):
            if mask & (1 << (8 + r)):
                written.add(r)
    if b == 'exg':
        written.update(range(8))
    if ins.flow == 'call':
        written.update((0, 1))
    for r in written:
        st.aconst.pop(r, None)
        if ins.flow == 'call' and r in (0, 1):
            st.alias.pop(r, None)


def step(ins, st, rec_push):
    out = _step(ins, st, rec_push)
    track_aconst(ins, st)
    return out


def make_rec_push():
    def rec_push(st, ins, off, nbytes, width, how):
        rec = {'addr': ins.addr, 'text': ins.text(), 'bytes': ins.hexbytes(),
               'how': how, 'slot': nbytes, 'width': width,
               'src': ins.src.text if isinstance(ins.src, EA) else (ins.src or '')}
        for k in range(nbytes):
            st.shadow[off + k] = (rec, k)
    return rec_push


def pop_after(rom, pc):
    """Instruction right after a call: how many bytes it releases."""
    try:
        ins = decode(rom, pc)
    except BadInsn:
        return None, None
    b = base_mn(ins.mn)
    if isinstance(ins.dst, EA) and ins.dst.mode == 'An' and ins.dst.reg == 7:
        if b in ('addq', 'adda') and isinstance(ins.src, EA) and ins.src.mode == '#':
            v = ins.src.imm
            if b == 'adda' and ins.size == 2 and v & 0x8000:
                v -= 0x10000
            return v, ins
        if b == 'lea' and isinstance(ins.src, EA) and ins.src.mode == '(d16,An)' and ins.src.reg == 7:
            return ins.src.disp, ins
    return None, ins


def analyze_function(rom, entry, entries, max_insns=20000):
    rec_push = make_rec_push()
    insns = {}
    sp_at = {}
    arg_access = []
    calls = []
    issues = []
    work = [(entry, State())]
    while work:
        pc, st = work.pop()
        while True:
            if pc in insns:
                if sp_at[pc] != st.sp and not st.unknown_sp:
                    issues.append(('sp-merge', pc, sp_at[pc], st.sp))
                break
            if pc != entry and pc in entries and ('flows-into-function', pc) not in issues:
                issues.append(('flows-into-function', pc))
                # keep walking: the next entry is (usually) this function's own body
            if len(insns) > max_insns:
                issues.append(('too-long', pc))
                break
            try:
                ins = decode(rom, pc)
            except (BadInsn, IndexError) as e:
                issues.append(('bad-insn', pc, str(e)))
                break
            insns[pc] = ins
            sp_at[pc] = st.sp
            if ins.flow in ('call', 'jump') and ins.target is None and \
                    isinstance(ins.src, EA) and ins.src.mode == '(An)' and ins.src.reg in st.aconst:
                ins.target = st.aconst[ins.src.reg]
                ins.extra['via_register'] = 'a%d' % ins.src.reg
            accesses = step(ins, st, rec_push)
            for how, off, w, eff, kind in accesses:
                if off is not None and off >= 4 and how != 'push':
                    arg_access.append({'addr': ins.addr, 'how': how, 'offset': off,
                                       'width': w, 'kind': kind, 'text': ins.text(),
                                       'bytes': ins.hexbytes()})
                if off is not None and 0 <= off < 4 and how not in ('push',) and not st.unknown_sp:
                    if how == 'pop' and base_mn(ins.mn) == 'movem':
                        continue
                    arg_access.append({'addr': ins.addr, 'how': how, 'offset': off,
                                       'width': w, 'kind': kind, 'text': ins.text(),
                                       'bytes': ins.hexbytes(), 'retaddr': True})
            if ins.flow == 'call':
                n, popins = pop_after(rom, pc + ins.len)
                args = []
                spc = sp_at[pc]  # sp at the call (calls do not move sp)
                # shadow: bytes from spc upward
                hi = spc + 48
                seen = []
                for off in range(spc, hi):
                    ent = st.shadow.get(off)
                    if ent is None:
                        seen.append((off, None, None))
                    else:
                        seen.append((off, ent[0], ent[1]))
                # group
                groups = []
                for off, rec, k in seen:
                    if groups and groups[-1]['rec'] is rec and rec is not None:
                        groups[-1]['len'] += 1
                    elif groups and rec is None and groups[-1]['rec'] is None:
                        groups[-1]['len'] += 1
                    else:
                        groups.append({'off': off, 'rec': rec, 'k': k, 'len': 1})
                for g in groups:
                    rec = g['rec']
                    args.append({'callee_offset': g['off'] - spc + 4, 'len': g['len'],
                                 'rec': None if rec is None else
                                 {kk: rec[kk] for kk in ('addr', 'text', 'bytes', 'how', 'slot', 'width', 'src')},
                                 'first_byte_in_rec': g['k']})
                calls.append({'addr': pc, 'target': ins.target, 'text': ins.text(),
                              'via_register': ins.extra.get('via_register'),
                              'bytes': ins.hexbytes(), 'pop': n,
                              'pop_text': popins.text() if popins else None,
                              'pop_bytes': popins.hexbytes() if popins else None,
                              'sp': spc, 'args': args, 'unknown_sp': st.unknown_sp,
                              'func': entry})
                pc += ins.len
                continue
            if ins.flow == 'seq':
                pc += ins.len
                continue
            if ins.flow == 'cbranch':
                work.append((ins.target, st.copy()))
                pc += ins.len
                continue
            if ins.flow == 'jump':
                if ins.target is None and isinstance(ins.src, EA) and ins.src.mode == '(idx,PC)' \
                        and ins.src.index and ins.src.index.endswith('.w'):
                    # switch idiom: move.w (d8,pc,dN.l*2),dN ; jmp (d8,pc,dN.w) - word table at base
                    base = ins.src.addr
                    targets = []
                    lim = base + 2 * 512
                    k = 0
                    while base + 2 * k < lim and base + 2 * k + 2 <= len(rom):
                        e = ((rom[base + 2 * k] << 8) | rom[base + 2 * k + 1])
                        if e & 0x8000:
                            e -= 0x10000
                        t = base + e
                        if t & 1 or t < 0 or t >= len(rom):
                            break
                        targets.append(t)
                        if t > base:
                            lim = min(lim, t)
                        k += 1
                    issues.append(('switch-table', pc, base, len(targets)))
                    for t in targets:
                        work.append((t, st.copy()))
                    break
                if ins.target is None:
                    issues.append(('indirect-jump', pc, ins.text()))
                    break
                if ins.target in entries and ins.target != entry:
                    issues.append(('tail-jump', pc, ins.target))
                pc = ins.target
                continue
            # ret / stop
            if ins.flow == 'ret' and not st.unknown_sp and st.sp != 0 and base_mn(ins.mn) == 'rts':
                issues.append(('rts-sp', pc, st.sp))
            break
    return {'entry': entry, 'insns': insns, 'sp_at': sp_at, 'arg_access': arg_access,
            'calls': calls, 'issues': issues}


def main():
    rom = open(sys.argv[1], 'rb').read()
    allf = json.load(open(sys.argv[2]))
    out = sys.argv[3]
    extend = '--extend' in sys.argv
    entries = {f['address']: f['name'] for f in allf}
    cpp_entries = set(entries)
    results = {}
    out_of_rom = {}
    todo = sorted(entries)
    rounds = 0
    while todo:
        rounds += 1
        new_targets = set()
        for addr in todo:
            r = analyze_function(rom, addr, entries)
            results[addr] = {
                'name': entries[addr],
                'cpp_entry': addr in cpp_entries,
                'n_insns': len(r['insns']),
                'extent': [min(r['insns']), max(r['insns']) + r['insns'][max(r['insns'])].len] if r['insns'] else None,
                'arg_access': r['arg_access'],
                'calls': r['calls'],
                'issues': r['issues'],
                'flows_into': [i[1] for i in r['issues'] if i[0] == 'flows-into-function'] +
                              [i[2] for i in r['issues'] if i[0] == 'tail-jump'],
                'covered': sorted(r['insns'].keys()),
            }
            if extend:
                for c in r['calls']:
                    t = c['target']
                    if t is None:
                        continue
                    if t >= len(rom):
                        out_of_rom.setdefault(t, []).append(c['addr'])
                    elif t not in entries and not (t & 1) and not (0x291F4 <= c['addr'] < 0x2CE64):
                        new_targets.add(t)
        for t in new_targets:
            entries[t] = 'call_target_%x' % t
        todo = sorted(new_targets)
    json.dump({hex(k): v for k, v in results.items()}, open(out, 'w'))
    if extend:
        json.dump({'rounds': rounds, 'added': sorted(a for a in entries if a not in cpp_entries),
                   'out_of_rom': {hex(k): v for k, v in out_of_rom.items()}},
                  open(out.replace('.json', '_extend.json'), 'w'))


if __name__ == '__main__':
    main()
