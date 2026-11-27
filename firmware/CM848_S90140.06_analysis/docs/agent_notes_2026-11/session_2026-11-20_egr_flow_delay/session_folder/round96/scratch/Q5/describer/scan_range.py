"""Q5 describer: find every D-form / X-form access that reaches RAM 0x3fdb80-0x3fdc80 in CM848 ROM + flash2.
Extends round 58's scan_accesses_v2.py: tracks lis / addi / addis / ori / mr, reports D-form accesses resolved
to base + displacement, addi pointer formation into the range, and X-form indexed accesses whose rA or rB holds a
known value in (or just below) the range. Linear scan: registers are forgotten at blr, at bl (volatile r0 / r3-r12)
and at any write the scanner does not model. Attributes each hit to the containing function (cm848_rom.ghidra.cpp).
usage: scan_range.py [lo hi]"""
import bisect
import re
import struct
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/cm848_rom.ghidra.cpp"
LO = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x3fdb80
HI = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x3fdc80

funcs = []
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
for line in open(CPP, errors="replace"):
    m = pat.match(line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))
fstarts = [a for a, _ in funcs]


def owner(pc):
    i = bisect.bisect_right(fstarts, pc) - 1
    return funcs[i][1] if i >= 0 else "?"


banks = [(0, open(BASE + "cm848_rom.bin", "rb").read()),
         (0x500000, open(BASE + "cm848_flash2_live.bin", "rb").read())]
DOPS = {32: ("lwz", 4), 33: ("lwzu", 4), 34: ("lbz", 1), 35: ("lbzu", 1), 36: ("stw", 4), 37: ("stwu", 4),
        38: ("stb", 1), 39: ("stbu", 1), 40: ("lhz", 2), 41: ("lhzu", 2), 42: ("lha", 2), 43: ("lhau", 2),
        44: ("sth", 2), 45: ("sthu", 2), 46: ("lmw", 4), 47: ("stmw", 4), 48: ("lfs", 4), 50: ("lfd", 8),
        52: ("stfs", 4), 54: ("stfd", 8)}
XOPS = {23: ("lwzx", 4), 55: ("lwzux", 4), 87: ("lbzx", 1), 119: ("lbzux", 1), 151: ("stwx", 4),
        183: ("stwux", 4), 215: ("stbx", 1), 247: ("stbux", 1), 279: ("lhzx", 2), 311: ("lhzux", 2),
        343: ("lhax", 2), 375: ("lhaux", 2), 407: ("sthx", 2), 439: ("sthux", 2)}
LOADS = {32, 33, 34, 35, 40, 41, 42, 43, 46}
hits = []


def inrange(v, slack=0):
    return LO - slack <= v < HI


for org, data in banks:
    regs = {}
    for off in range(0, len(data) - 3, 4):
        pc = org + off
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        rt, ra, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xffff
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if w == 0x4e800020:          # blr
            regs = {}
            continue
        if op == 18 and w & 1:       # bl: volatile registers clobbered
            regs = {r: v for r, v in regs.items() if r in (1, 2) or r >= 13}
            continue
        if op in DOPS:
            name, width = DOPS[op]
            if ra in regs and ra != 0:
                a = (regs[ra] + simm) & 0xffffffff
                if op in (46, 47):
                    width = 4 * (32 - rt)
                if a < HI and a + width > LO:
                    hits.append((pc, owner(pc), f"{name} r{rt},{simm}(r{ra})", a, width, "D"))
            if op in LOADS:
                regs.pop(rt, None)
            if op in (33, 35, 37, 39, 41, 43, 45) and ra in regs:
                regs[ra] = (regs[ra] + simm) & 0xffffffff
            if op == 46:
                for r in range(rt, 32):
                    regs.pop(r, None)
            continue
        if op == 15:                 # lis / addis
            if ra == 0:
                regs[rt] = (imm << 16) & 0xffffffff
            elif ra in regs:
                regs[rt] = (regs[ra] + (simm << 16)) & 0xffffffff
            else:
                regs.pop(rt, None)
            continue
        if op == 14:                 # addi / li
            if ra == 0:
                regs[rt] = simm & 0xffffffff
            elif ra in regs:
                v = (regs[ra] + simm) & 0xffffffff
                if inrange(v):
                    hits.append((pc, owner(pc), f"addi r{rt},r{ra},{simm}", v, 0, "P"))
                regs[rt] = v
            else:
                regs.pop(rt, None)
            continue
        if op == 24:                 # ori rA,rS,U
            if rt in regs:
                v = regs[rt] | imm
                if inrange(v) and imm:
                    hits.append((pc, owner(pc), f"ori r{ra},r{rt},0x{imm:x}", v, 0, "P"))
                regs[ra] = v
            else:
                regs.pop(ra, None)
            continue
        if op == 31:
            rb, xo = (w >> 11) & 31, (w >> 1) & 0x3ff
            if xo in XOPS:
                name, width = XOPS[xo]
                known = [(r, regs[r]) for r in (ra, rb) if r in regs and r != 0 and inrange(regs[r], 0x100)]
                if known:
                    hits.append((pc, owner(pc), f"{name} r{rt},r{ra},r{rb}",
                                 known[0][1], width, "X" + "".join(f" r{r}=0x{v:x}" for r, v in known)))
                if xo in (23, 55, 87, 119, 279, 311, 343, 375):
                    regs.pop(rt, None)
                if xo in (55, 119, 183, 247, 311, 375, 439):
                    regs.pop(ra, None)
                continue
            if xo == 444 and rb == rt:   # mr rA,rS
                if rt in regs:
                    regs[ra] = regs[rt]
                else:
                    regs.pop(ra, None)
                continue
            if xo == 266:                # add rD,rA,rB
                known = [(r, regs[r]) for r in (ra, rb) if r in regs and inrange(regs[r], 0x100)]
                if known:
                    hits.append((pc, owner(pc), f"add r{rt},r{ra},r{rb}", known[0][1], 0,
                                 "A" + "".join(f" r{r}=0x{v:x}" for r, v in known)))
                if ra in regs and rb in regs:
                    regs[rt] = (regs[ra] + regs[rb]) & 0xffffffff
                else:
                    regs.pop(rt, None)
                continue
            # anything else: forget rD and rA (store-like X-forms do not write registers, but be safe)
            regs.pop(rt, None)
            regs.pop(ra, None)
            continue
        if op in (7, 8, 12, 13):     # mulli / subfic / addic / addic.
            regs.pop(rt, None)
            continue
        if op in (20, 21, 23, 25, 26, 27, 28, 29):   # rlwimi / rlwinm / rlwnm / oris / xori / xoris / andi. / andis.
            if op == 25 and rt in regs:
                regs[ra] = regs[rt] | (imm << 16)
            else:
                regs.pop(ra, None)
            continue
        if op in (16, 18, 19):       # branches: keep (linear scan)
            continue
        # other opcodes (floating point etc.): forget rt
        if op not in (10, 11, 3, 2, 17):
            regs.pop(rt, None)

hits.sort()
for pc, fn, ins, a, wdt, kind in hits:
    tag = "BOOT" if pc < 0x7f60 else "APP"
    print(f"{tag} 0x{pc:06x} {fn:55s} {ins:28s} -> 0x{a:06x} w{wdt} {kind}")
