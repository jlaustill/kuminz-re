#!/usr/bin/env python3
"""CM550 small stack argument survey.

Inputs: ROM, affected.json (parse_cpp.py), affected_all_functions.json,
results.json (analyze.py). Writes survey.json and prints a report.
"""
import json
import sys
from collections import Counter, defaultdict

HERE = __file__.rsplit('/', 1)[0]
sys.path.insert(0, HERE)
from m68k import decode, BadInsn, u16, s16, u32, s32, s8  # noqa: E402
from analyze import State, step, make_rec_push, pop_after, base_mn  # noqa: E402

ROM_PATH = sys.argv[1]
rom = open(ROM_PATH, 'rb').read()
affected = json.load(open(HERE + '/affected.json'))
allf = json.load(open(HERE + '/affected_all_functions.json'))
results = {int(k, 16): v for k, v in json.load(open(HERE + '/results.json')).items()}
entries = {a: v['name'] for a, v in results.items()}
IMAGE_LO, IMAGE_HI = 0x291F4, 0x2CE64

covered = set()
for v in results.values():
    covered.update(v['covered'])


def push_kind(rec):
    if rec is None:
        return '?'
    t = rec['text']
    mn = t.split(' ')[0]
    if rec['how'] == 'pea':
        return 'pea'
    if rec['how'] == 'movem':
        return 'movem'
    if rec['how'] == 'link':
        return 'link'
    if rec['how'] == 'store':
        return 'store.' + mn.split('.')[-1]
    if mn == 'clr.w':
        return 'clr.w'
    if mn == 'clr.l':
        return 'clr.l'
    if mn == 'clr.b':
        return 'clr.b'
    return mn


# ---------------------------------------------------------------- raw scan
def raw_scan():
    hits = []
    for pc in range(0, len(rom) - 6, 2):
        if IMAGE_LO <= pc < IMAGE_HI:
            continue
        op = u16(rom, pc)
        tgt = None
        kind = None
        if op == 0x4eb9 or op == 0x4ef9:
            tgt = u32(rom, pc + 2)
            kind = 'jsr.l' if op == 0x4eb9 else 'jmp.l'
        elif op == 0x4eb8 or op == 0x4ef8:
            tgt = s16(rom, pc + 2) & 0xffffffff
            kind = 'jsr.w' if op == 0x4eb8 else 'jmp.w'
        elif op == 0x4eba or op == 0x4efa:
            tgt = (pc + 2 + s16(rom, pc + 2)) & 0xffffffff
            kind = 'jsr(d16,pc)' if op == 0x4eba else 'jmp(d16,pc)'
        elif op == 0x4ebb or op == 0x4efb:
            ext = u16(rom, pc + 2)
            if ext & 0x100 and (ext & 0x40) and (ext & 7) == 0:
                bds = (ext >> 4) & 3
                if bds == 2:
                    bd = s16(rom, pc + 4)
                elif bds == 3:
                    bd = s32(rom, pc + 4)
                else:
                    continue
                tgt = (bd if ext & 0x80 else pc + 2 + bd) & 0xffffffff
                kind = 'jsr(bd,pc)' if op == 0x4ebb else 'jmp(bd,pc)'
        elif (op & 0xff00) == 0x6100 or (op & 0xff00) == 0x6000:
            d8 = op & 0xff
            if d8 == 0:
                tgt = (pc + 2 + s16(rom, pc + 2)) & 0xffffffff
                w = '.w'
            elif d8 == 0xff:
                tgt = (pc + 2 + s32(rom, pc + 2)) & 0xffffffff
                w = '.l'
            else:
                tgt = (pc + 2 + s8(d8)) & 0xffffffff
                w = '.b'
            kind = ('bsr' if op & 0x100 else 'bra') + w
        if tgt is not None and tgt in entries:
            hits.append((pc, tgt, kind))
    return hits


def local_walk(call_pc):
    """Linear decode into call_pc from a nearby start; returns (shadow, sp, insns)."""
    for back in range(96, 0, -2):
        s = call_pc - back
        if s < 0:
            continue
        pc = s
        seq = []
        ok = True
        while pc < call_pc:
            try:
                ins = decode(rom, pc)
            except Exception:
                ok = False
                break
            seq.append(ins)
            pc += ins.len
        if not ok or pc != call_pc:
            continue
        # restart after the last unconditional flow change
        cut = 0
        for k, ins in enumerate(seq):
            if ins.flow in ('ret', 'jump', 'stop'):
                cut = k + 1
        seq = seq[cut:]
        st = State()
        rp = make_rec_push()
        for ins in seq:
            step(ins, st, rp)
        return st, seq
    return None, None


def layout_from_shadow(shadow_list, extent):
    """shadow_list: list of groups (callee_offset, len, rec, first_byte_in_rec).
    Return every group that overlaps [4, 4+extent), whole (a push that
    starts inside the range is kept in full)."""
    out = []
    for g in shadow_list:
        lo = g['callee_offset']
        hi = lo + g['len']
        if hi <= 4 or lo >= 4 + extent:
            continue
        if g['rec'] is None:
            lo2 = max(lo, 4)
            hi2 = min(hi, 4 + extent)
        else:
            lo2, hi2 = max(lo, 4), hi
        out.append({'off': lo2, 'len': hi2 - lo2, 'rec': g['rec'],
                    'first': (g['first_byte_in_rec'] or 0) + (lo2 - lo),
                    'truncated': (lo2 != lo) or (hi2 != hi)})
    return out


def groups_from_state(st, spc, span=48):
    raw = []
    for off in range(spc, spc + span):
        ent = st.shadow.get(off)
        rec, k = (ent if ent else (None, None))
        if raw and raw[-1]['orig'] is rec:
            raw[-1]['len'] += 1
        else:
            raw.append({'off': off, 'orig': rec, 'k': k, 'len': 1})
    groups = []
    for g in raw:
        rec = g['orig']
        groups.append({'callee_offset': g['off'] - spc + 4, 'len': g['len'], 'rec':
                       None if rec is None else {kk: rec[kk] for kk in
                                                 ('addr', 'text', 'bytes', 'how', 'slot', 'width', 'src')},
                       'first_byte_in_rec': g['k']})
    return groups


def describe(layout):
    parts = []
    for g in layout:
        rec = g['rec']
        pk = push_kind(rec)
        if rec is None:
            parts.append('+%d:unwritten%d' % (g['off'], g['len']))
            continue
        d = '+%d:%s' % (g['off'], pk)
        if rec['slot'] != g['len'] or g['first'] != 0:
            d += '[bytes %d-%d of %d]' % (g['first'], g['first'] + g['len'] - 1, rec['slot'])
        parts.append(d)
    return ' '.join(parts)


def callee_reads(addr):
    r = results.get(addr)
    if not r:
        return []
    return [a for a in r['arg_access'] if not a.get('retaddr')]


def read_summary(reads):
    c = Counter()
    for a in reads:
        w = a['width']
        key = '%s+%d/%s' % ({'r': 'r', 'w': 'w', 'rw': 'rw', 'addr': '&'}[a['kind']],
                            a['offset'], '-' if w is None else str(w))
        c[key] += 1
    return dict(sorted(c.items(), key=lambda kv: (int(kv[0].split('+')[1].split('/')[0]), kv[0])))


def extent_of(reads):
    """Bytes past +4 the callee touches: reads/writes, and the first byte of any
    slot whose address it takes (lea/pea)."""
    e = 0
    for a in reads:
        if a['width'] is None:
            e = max(e, a['offset'] + 1 - 4)
            continue
        e = max(e, a['offset'] + a['width'] - 4)
    return e


fragments = set()
for v in results.values():
    fragments.update(v.get('flows_into', []))
_direct = {c['target'] for v in results.values() for c in v['calls'] if c['target'] is not None}
fragments -= _direct
json.dump(sorted(fragments), open(HERE + '/fragments.json', 'w'))

# walker call index
walker_calls = defaultdict(list)
for faddr, v in results.items():
    for c in v['calls']:
        if c['target'] is not None:
            walker_calls[c['target']].append(c)

scan = raw_scan()
scan_by_target = defaultdict(list)
for pc, tgt, kind in scan:
    scan_by_target[tgt].append((pc, kind))

# data longs equal to a function address (dispatch tables): skip bytes that are
# part of a flow-reached instruction or of a raw-scan call/jump hit
covered_bytes = set()
for v in results.values():
    pass
for faddr in results:
    pass
_cov_ranges = []
for pc in covered:
    try:
        _cov_ranges.append((pc, decode(rom, pc).len))
    except Exception:
        pass
for pc, ln in _cov_ranges:
    covered_bytes.update(range(pc, pc + ln))
for pc, tgt, kind in scan:
    covered_bytes.update(range(pc, pc + 6))
data_refs = defaultdict(list)
for pc in range(0, len(rom) - 4, 2):
    v = u32(rom, pc)
    if v in entries and pc not in covered_bytes and not (IMAGE_LO <= pc < IMAGE_HI):
        data_refs[v].append(pc)


def call_sites(addr, extent):
    sites = []
    wset = set()
    best = {}
    for c in walker_calls.get(addr, []):
        prev = best.get(c['addr'])
        if prev is None or (prev['func'] in fragments and c['func'] not in fragments):
            best[c['addr']] = c
    for c in sorted(best.values(), key=lambda c: c['addr']):
        if IMAGE_LO <= c['addr'] < IMAGE_HI:
            continue
        wset.add(c['addr'])
        lay = layout_from_shadow(c['args'], extent) if extent else []
        pushed = sum(g['len'] for g in layout_from_shadow(c['args'], 48) if g['rec'] is not None
                     and g['rec']['how'] in ('push', 'pea'))
        sites.append({'addr': c['addr'], 'caller': entries.get(c['func'], hex(c['func'])),
                      'caller_addr': c['func'], 'via': 'walker', 'call': c['bytes'],
                      'call_text': c['text'], 'pop': c['pop'], 'pop_bytes': c['pop_bytes'],
                      'pop_text': c['pop_text'], 'layout': lay, 'desc': describe(lay),
                      'shadow': c['args'], 'unknown_sp': c['unknown_sp']})
    for pc, kind in scan_by_target.get(addr, []):
        if pc in wset:
            continue
        if kind.startswith('bra') or kind.startswith('jmp'):
            sites.append({'addr': pc, 'via': 'scan-jump', 'call_text': kind, 'caller': '?',
                          'in_covered_code': pc in covered})
            continue
        st, seq = local_walk(pc)
        if st is None:
            sites.append({'addr': pc, 'via': 'scan-undecodable', 'call_text': kind, 'caller': '?'})
            continue
        try:
            ins = decode(rom, pc)
        except BadInsn:
            continue
        n, popins = pop_after(rom, pc + ins.len)
        groups = groups_from_state(st, st.sp)
        lay = layout_from_shadow(groups, extent) if extent else []
        owner = max([a for a in entries if a <= pc], default=None)
        sites.append({'addr': pc, 'via': 'scan', 'call': ins.hexbytes(), 'call_text': ins.text(),
                      'caller': entries.get(owner, '?') + '(+0x%x, not flow-reached)' % (pc - owner) if owner is not None else '?',
                      'caller_addr': owner,
                      'pop': n, 'pop_bytes': popins.hexbytes() if popins else None,
                      'pop_text': popins.text() if popins else None, 'layout': lay,
                      'desc': describe(lay), 'shadow': groups,
                      'window': ['%06x %s' % (i.addr, i.text()) for i in seq[-6:]]})
    sites.sort(key=lambda s: s['addr'])
    return sites


def main():
    report = []
    aff_addrs = [f['address'] for f in affected]
    for f in affected:
        addr = f['address']
        reads = callee_reads(addr)
        ext = extent_of(reads)
        sites = call_sites(addr, ext)
        issues = results.get(addr, {}).get('issues', [])
        retaddr_reads = [a for a in results.get(addr, {}).get('arg_access', []) if a.get('retaddr')]
        report.append({'address': addr, 'name': f['name'], 'signature': f['signature'],
                       'cpp_refs': [{k: r[k] for k in ('token', 'offset', 'width', 'count', 'decl_type')
                                     if k in r} for r in f['refs']],
                       'rom_reads': read_summary(reads), 'rom_read_list': reads,
                       'retaddr_reads': retaddr_reads,
                       'extent': ext, 'issues': issues, 'sites': sites,
                       'data_refs': data_refs.get(addr, []),
                       'is_flowed_into': any(i[0] == 'flows-into-function' and i[1] == addr
                                             for v in results.values() for i in v['issues'])})
    json.dump(report, open(HERE + '/survey.json', 'w'), indent=1)
    # global: every walker call to a function with arg reads
    allsites = []
    for addr in sorted(results):
        reads = callee_reads(addr)
        ext = extent_of(reads)
        if not ext:
            continue
        for s in call_sites(addr, ext):
            s['callee'] = addr
            allsites.append(s)
    json.dump({'scan_hits': len(scan), 'sites': allsites}, open(HERE + '/all_sites.json', 'w'))
    print('affected functions:', len(report))
    print('raw scan call/jump hits to function entries:', len(scan))


if __name__ == '__main__':
    main()
