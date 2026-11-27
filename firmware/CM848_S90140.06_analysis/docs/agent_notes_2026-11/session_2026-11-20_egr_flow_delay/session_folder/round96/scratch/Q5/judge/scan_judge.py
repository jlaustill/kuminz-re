#!/usr/bin/env python3
"""Q5 judge: independent scan of every access into RAM LO..HI in CM848 ROM + flash2.

Per function window (from the frozen cm848_rom.ghidra.cpp '// Function:' lines), two analyses:
  linear : state flows in address order through every instruction (branches do not reset it),
           volatile registers r0/r3-r12 are KEPT across bl (superset mode) or CLOBBERED (strict mode)
  flow   : forward dataflow over the basic blocks with merging (only equal constants survive)
Register values: ('c', value) constant, ('i', base) = base + unknown index (from add/addi of an index).
Reports: D-form accesses (EA = const + disp), X-form accesses with a constant or indexed operand,
pointer formation into the range (addi / ori result), range pointers live in r3-r10 at a bl, and
stores of a range pointer to memory.
usage: scan_judge.py [lo hi] [--keep|--clobber]
"""
import bisect
import re
import struct
import sys

ORIG = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/cm848_rom.ghidra.cpp"
args = [a for a in sys.argv[1:] if not a.startswith("--")]
LO = int(args[0], 16) if args else 0x3fdb80
HI = int(args[1], 16) if len(args) > 1 else 0x3fdc90
KEEP = "--clobber" not in sys.argv
SLACK = 0x200   # an indexed base may sit below the range (e.g. 0x3fdb8e)

funcs = []
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
for line in open(CPP, errors="replace"):
    m = pat.match(line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))
starts = [a for a, _ in funcs]
rom = open(ORIG + "cm848_rom.bin", "rb").read()
fl2 = open(ORIG + "cm848_flash2_live.bin", "rb").read()


def word_at(pc):
    if pc < 0x500000:
        return struct.unpack(">I", rom[pc:pc + 4])[0] if pc + 4 <= len(rom) else None
    o = pc - 0x500000
    return struct.unpack(">I", fl2[o:o + 4])[0] if o + 4 <= len(fl2) else None


DOPS = {32: ("lwz", 4, 0), 33: ("lwzu", 4, 1), 34: ("lbz", 1, 0), 35: ("lbzu", 1, 1), 36: ("stw", 4, 0),
        37: ("stwu", 4, 1), 38: ("stb", 1, 0), 39: ("stbu", 1, 1), 40: ("lhz", 2, 0), 41: ("lhzu", 2, 1),
        42: ("lha", 2, 0), 43: ("lhau", 2, 1), 44: ("sth", 2, 0), 45: ("sthu", 2, 1), 46: ("lmw", 4, 0),
        47: ("stmw", 4, 0)}
XOPS = {23: ("lwzx", 4, 0), 55: ("lwzux", 4, 1), 87: ("lbzx", 1, 0), 119: ("lbzux", 1, 1), 151: ("stwx", 4, 0),
        183: ("stwux", 4, 1), 215: ("stbx", 1, 0), 247: ("stbux", 1, 1), 279: ("lhzx", 2, 0), 311: ("lhzux", 2, 1),
        343: ("lhax", 2, 0), 375: ("lhaux", 2, 1), 407: ("sthx", 2, 0), 439: ("sthux", 2, 1)}
STORE_D = {36, 37, 38, 39, 44, 45, 47}


def interesting(v):
    return v is not None and LO - SLACK <= v < HI


def step(pc, w, regs, report):
    """apply instruction w at pc to regs (dict reg -> ('c', v) | ('i', base)); report(kind, ...) on hits."""
    op = w >> 26
    rt, ra, rb = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    imm = w & 0xffff
    simm = imm - 0x10000 if imm & 0x8000 else imm

    def get(r):
        return regs.get(r)

    def setr(r, val):
        if val is None:
            regs.pop(r, None)
        else:
            regs[r] = val

    if op == 14:      # addi
        if ra == 0:
            setr(rt, ('c', simm & 0xffffffff))
        else:
            v = get(ra)
            if v and v[0] == 'c':
                nv = (v[1] + simm) & 0xffffffff
                setr(rt, ('c', nv))
                if LO <= nv < HI:
                    report('ptr', pc, 'addi', nv, None)
            elif v and v[0] == 'i':
                setr(rt, ('i', (v[1] + simm) & 0xffffffff))
            else:
                setr(rt, None)
        return
    if op == 15:      # addis
        if ra == 0:
            setr(rt, ('c', (simm << 16) & 0xffffffff))
        else:
            v = get(ra)
            setr(rt, ('c', (v[1] + (simm << 16)) & 0xffffffff) if v and v[0] == 'c' else None)
        return
    if op == 24:      # ori rA,rS,UIMM
        v = get(rt)
        if v and v[0] == 'c':
            nv = v[1] | imm
            setr(ra, ('c', nv))
            if LO <= nv < HI:
                report('ptr', pc, 'ori', nv, None)
        else:
            setr(ra, None)
        return
    if op == 25:      # oris
        v = get(rt)
        setr(ra, ('c', v[1] | (imm << 16)) if v and v[0] == 'c' else None)
        return
    if op in DOPS:
        name, width, upd = DOPS[op]
        if op in (46, 47):   # lmw/stmw: stack save/restore - lmw clobbers rt..r31
            if op == 46:
                for r in range(rt, 32):
                    setr(r, None)
            return
        v = get(ra) if ra != 0 else ('c', 0)
        if v and v[0] == 'c':
            ea = (v[1] + simm) & 0xffffffff
            if LO <= ea < HI:
                report('D', pc, name, ea, width)
            if upd:
                setr(ra, ('c', ea))
        elif v and v[0] == 'i':
            ea = (v[1] + simm) & 0xffffffff
            if interesting(ea):
                report('Di', pc, name, ea, width)
            if upd:
                setr(ra, ('i', ea))
        else:
            if upd:
                setr(ra, None)
        if op in STORE_D:
            sv = get(rt)
            if sv and sv[0] == 'c' and LO <= sv[1] < HI:
                report('ptrstore', pc, name, sv[1], None)
        else:
            setr(rt, None)
        return
    if op == 31:
        xo = (w >> 1) & 0x3ff
        if xo in XOPS:
            name, width, upd = XOPS[xo]
            va = get(ra) if ra != 0 else None
            vb = get(rb)
            for v in (va, vb):
                if v and interesting(v[1]):
                    report('X', pc, name, v[1], width)
            if upd:
                setr(ra, None)
            if not (xo in (151, 183, 215, 247, 407, 439)):
                setr(rt, None)
            return
        if xo == 444:   # or rA,rS,rB  (mr when rS == rB)
            if rt == rb:
                setr(ra, get(rt))
            else:
                setr(ra, None)
            return
        if xo == 266:   # add rD,rA,rB
            va, vb = get(ra), get(rb)
            if va and va[0] in 'ci' and interesting(va[1]) and not (vb and vb[0] == 'c'):
                setr(rt, ('i', va[1]))
            elif vb and vb[0] in 'ci' and interesting(vb[1]) and not (va and va[0] == 'c'):
                setr(rt, ('i', vb[1]))
            elif va and vb and va[0] == 'c' and vb[0] == 'c':
                setr(rt, ('c', (va[1] + vb[1]) & 0xffffffff))
            else:
                setr(rt, None)
            return
        # stores with rS operand: stwx etc handled; other X-form ops write rD or rA
        # (cmp* (xo 0/32) write a CR field only; mtspr/mtcrf write no GPR)
        if xo in (0, 32, 467, 144, 854, 86, 470, 54, 278, 246, 1014, 982):
            return
        # logical ops write rA, arithmetic write rD: clobber both conservatively
        if xo in (28, 60, 124, 284, 316, 412, 476, 24, 536, 792, 824, 954, 922, 26, 58):
            setr(ra, None)
        else:
            setr(rt, None)
        return
    if op in (21, 20, 23, 28, 29, 26, 27, 30):   # rlwinm/rlwimi/rlwnm/andi./andis./xori/xoris/rld*: write rA
        setr(ra, None)
        return
    if op in (7, 8, 12, 13, 2, 3):   # mulli/subfic/addic/addic./tdi/twi
        if op in (7, 8, 12, 13):
            setr(rt, None)
        return
    if op in (10, 11):   # cmpli/cmpi
        return
    if op == 18 or op == 16 or op == 19:
        return
    # float / other: assume no GPR change except loads of floats (no GPR) - nothing to do
    return


def call_clobber(regs):
    for r in [0] + list(range(3, 13)):
        regs.pop(r, None)


def analyse(fstart, fend, name, out):
    pcs = list(range(fstart, fend, 4))
    words = {pc: word_at(pc) for pc in pcs}

    def report_factory(mode):
        def report(kind, pc, mn, ea, width):
            out.add((name, pc, kind, mn, ea, width, mode))
        return report

    # ---------- linear ----------
    regs = {}
    rep = report_factory('linear')
    for pc in pcs:
        w = words[pc]
        if w is None:
            break
        op = w >> 26
        if op == 18 and (w & 1) or (op == 16 and (w & 1)) or (op == 19 and ((w >> 1) & 0x3ff) == 528 and (w & 1)):
            for r in range(3, 11):
                v = regs.get(r)
                if v and v[0] == 'c' and LO <= v[1] < HI:
                    out.add((name, pc, 'argptr', 'r%d' % r, v[1], None, 'linear'))
            if not KEEP:
                call_clobber(regs)
            continue
        step(pc, w, regs, rep)
    # ---------- flow ----------
    succ = {}
    leaders = {fstart}
    for pc in pcs:
        w = words[pc]
        if w is None:
            continue
        op = w >> 26
        if op == 18:
            li = w & 0x03fffffc
            if li & 0x02000000:
                li -= 0x04000000
            tgt = li if (w & 2) else pc + li
            if w & 1:
                succ[pc] = [pc + 4]
            else:
                succ[pc] = [tgt] if fstart <= tgt < fend else []
                leaders.add(pc + 4)
                if fstart <= tgt < fend:
                    leaders.add(tgt)
        elif op == 16:
            bd = w & 0xfffc
            if bd & 0x8000:
                bd -= 0x10000
            tgt = bd if (w & 2) else pc + bd
            bo = (w >> 21) & 31
            s = []
            if fstart <= tgt < fend:
                s.append(tgt)
                leaders.add(tgt)
            if not (bo & 0x14 == 0x14):
                s.append(pc + 4)
            if w & 1:
                s = [pc + 4]
            succ[pc] = s
            leaders.add(pc + 4)
        elif op == 19 and ((w >> 1) & 0x3ff) in (16, 528):
            bo = (w >> 21) & 31
            if w & 1:
                succ[pc] = [pc + 4]
            else:
                succ[pc] = [] if (bo & 0x14 == 0x14) else [pc + 4]
                leaders.add(pc + 4)
        else:
            succ[pc] = [pc + 4]
    instate = {fstart: {}}
    work = [fstart]
    seen_count = {}
    rep = report_factory('flow')
    while work:
        pc0 = work.pop()
        regs = dict(instate[pc0])
        pc = pc0
        while True:
            if pc not in words or words[pc] is None or pc >= fend:
                break
            w = words[pc]
            op = w >> 26
            is_call = (op == 18 and (w & 1)) or (op == 16 and (w & 1)) or \
                      (op == 19 and ((w >> 1) & 0x3ff) == 528 and (w & 1))
            if is_call:
                for r in range(3, 11):
                    v = regs.get(r)
                    if v and v[0] == 'c' and LO <= v[1] < HI:
                        out.add((name, pc, 'argptr', 'r%d' % r, v[1], None, 'flow'))
                if not KEEP:
                    call_clobber(regs)
            else:
                step(pc, w, regs, rep)
            nxt = succ.get(pc, [pc + 4])
            if len(nxt) == 1 and nxt[0] == pc + 4 and (pc + 4) not in leaders:
                pc += 4
                continue
            for t in nxt:
                if t >= fend or t < fstart:
                    continue
                if t not in instate:
                    instate[t] = dict(regs)
                    work.append(t)
                else:
                    old = instate[t]
                    merged = {r: v for r, v in old.items() if regs.get(r) == v}
                    if merged != old:
                        seen_count[t] = seen_count.get(t, 0) + 1
                        if seen_count[t] < 50:
                            instate[t] = merged
                            work.append(t)
            break
    # unreachable leaders (jump-table targets): analyse with empty state
    for ld in sorted(leaders):
        if fstart <= ld < fend and ld not in instate:
            regs = {}
            pc = ld
            while pc < fend and words.get(pc) is not None:
                w = words[pc]
                op = w >> 26
                is_call = (op == 18 and (w & 1))
                if is_call:
                    if not KEEP:
                        call_clobber(regs)
                else:
                    step(pc, w, regs, rep)
                nxt = succ.get(pc, [pc + 4])
                if nxt != [pc + 4] or (pc + 4) in leaders:
                    break
                pc += 4


def main():
    out = set()
    bounds = []
    for i, (a, n) in enumerate(funcs):
        if i + 1 < len(funcs):
            e = funcs[i + 1][0]
        else:
            e = a + 0x800
        if a < 0x500000 and e > 0x500000:
            e = min(e, len(rom))
        if a < 0x500000 and e > len(rom):
            e = len(rom)
        if e - a > 0x20000:
            e = a + 0x20000
        bounds.append((a, e, n))
    for a, e, n in bounds:
        analyse(a, e, n, out)
    for rec in sorted(out, key=lambda r: (r[4], r[1], r[6])):
        name, pc, kind, mn, ea, width, mode = rec
        side = 'BOOT' if pc < 0x7f60 else 'APP'
        print("%-5s %-6s %-8s 0x%06x %-7s %-5s %-6s %s" % (side, mode, kind, ea, mn, width, hex(pc), name))


main()
