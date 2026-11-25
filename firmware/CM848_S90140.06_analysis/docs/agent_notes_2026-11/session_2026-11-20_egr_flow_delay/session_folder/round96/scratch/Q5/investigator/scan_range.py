"""Q5: find every load / store / address computation that reaches a CM848 RAM range, per function.

Walks each function window from cm848_rom.ghidra.cpp (// Function: <name> @ 0x<addr>) in both banks
(ROM base 0, flash2 base 0x500000) and tracks register contents:
  known value    (lis / addis / addi / li / ori / oris / mr from a known value)
  derived value  (add rD,rA,rB with one side known -> 'base X + index'), kept through addi
A call (bl) clobbers r0 / r3-r12; blr forgets everything. Each D-form access through a known register
is resolved to base + displacement; an access through a derived register or an X-form indexed access
with a known / derived base is reported as an INDEXED access of that base. An addi / ori that forms an
address inside the range is reported as ADDR (a pointer is taken).

usage: scan_range.py <lo hex> <hi hex>     (hi exclusive)
prints one line per hit: <bank> <function> @<insn> <kind> <mnemonic> <effective address> <width>
"""
import os
import re
import struct
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848"
ORIG = os.path.join(REPO, "firmware/CM848_S90140.06_analysis/originals")
ROM = open(os.path.join(ORIG, "cm848_rom.bin"), "rb").read()
FLASH2 = open(os.path.join(ORIG, "cm848_flash2_live.bin"), "rb").read()

LO, HI = int(sys.argv[1], 16), int(sys.argv[2], 16)

funcs = []
pat = re.compile(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)")
for line in open(os.path.join(FROZEN, "cm848_rom.ghidra.cpp"), errors="replace"):
    m = pat.match(line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs = sorted(set(funcs))

DFORM = {32: ("lwz", 4, "L"), 33: ("lwzu", 4, "L"), 34: ("lbz", 1, "L"), 35: ("lbzu", 1, "L"),
         36: ("stw", 4, "S"), 37: ("stwu", 4, "S"), 38: ("stb", 1, "S"), 39: ("stbu", 1, "S"),
         40: ("lhz", 2, "L"), 41: ("lhzu", 2, "L"), 42: ("lha", 2, "L"), 43: ("lhau", 2, "L"),
         44: ("sth", 2, "S"), 45: ("sthu", 2, "S"), 46: ("lmw", 4, "L"), 47: ("stmw", 4, "S")}
XFORM_MEM = {23: ("lwzx", 4, "L"), 55: ("lwzux", 4, "L"), 87: ("lbzx", 1, "L"), 119: ("lbzux", 1, "L"),
             279: ("lhzx", 2, "L"), 311: ("lhzux", 2, "L"), 343: ("lhax", 2, "L"), 375: ("lhaux", 2, "L"),
             151: ("stwx", 4, "S"), 183: ("stwux", 4, "S"), 215: ("stbx", 1, "S"), 247: ("stbux", 1, "S"),
             407: ("sthx", 2, "S"), 439: ("sthux", 2, "S")}
X_WRITES_RA = {28, 60, 124, 284, 316, 412, 444, 476, 24, 536, 792, 824, 26, 922, 954}
X_NO_WRITE = {0, 32, 4, 86, 470, 54, 278, 246, 1014, 982, 598, 854, 306, 370, 566, 467, 146, 210, 242, 144}


def in_range(a, width):
    return a < HI and a + width > LO


def scan(start, stop, data, org, name):
    hits = []
    known = {}     # reg -> value
    derived = {}   # reg -> (base, offset)
    for pc in range(start, stop, 4):
        off = pc - org
        if off < 0 or off + 4 > len(data):
            break
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        rt, ra, rb = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = w & 0xffff
        simm = imm - 0x10000 if imm & 0x8000 else imm

        def forget(r):
            known.pop(r, None)
            derived.pop(r, None)

        if w == 0x4e800020:
            known.clear()
            derived.clear()
            continue
        if op == 18:
            if w & 1:
                for r in [0] + list(range(3, 13)):
                    forget(r)
            continue
        if op in DFORM:
            mn, width, kind = DFORM[op]
            if op in (46, 47):
                width = 4 * (32 - rt)
            if ra != 0 and ra in known:
                ea = (known[ra] + simm) & 0xffffffff
                if in_range(ea, width):
                    hits.append((pc, kind, f"{mn} r{rt},{simm}(r{ra})", ea, width, ""))
                if op in (33, 35, 37, 39, 41, 43, 45):
                    known[ra] = ea
            elif ra != 0 and ra in derived:
                b, o = derived[ra]
                ea = (b + o + simm) & 0xffffffff
                if in_range(b, 1) or in_range(ea, width):
                    hits.append((pc, kind, f"{mn} r{rt},{simm}(r{ra})", ea, width,
                                 f"INDEXED base 0x{b:06x}+{o}+index"))
                if op in (33, 35, 37, 39, 41, 43, 45):
                    derived[ra] = (b, o + simm)
            elif op in (33, 35, 37, 39, 41, 43, 45):
                forget(ra)
            if kind == "L":
                if op == 46:
                    for r in range(rt, 32):
                        forget(r)
                else:
                    forget(rt)
            continue
        if op == 15:  # addis / lis
            if ra == 0:
                known[rt] = (imm << 16) & 0xffffffff
                derived.pop(rt, None)
            elif ra in known:
                known[rt] = (known[ra] + (simm << 16)) & 0xffffffff
                derived.pop(rt, None)
            else:
                forget(rt)
            continue
        if op == 14:  # addi / li
            if ra == 0:
                known[rt] = simm & 0xffffffff
                derived.pop(rt, None)
            elif ra in known:
                v = (known[ra] + simm) & 0xffffffff
                if in_range(v, 1):
                    hits.append((pc, "A", f"addi r{rt},r{ra},{simm}", v, 0, "ADDR"))
                known[rt] = v
                derived.pop(rt, None)
            elif ra in derived:
                b, o = derived[ra]
                derived[rt] = (b, o + simm)
                known.pop(rt, None)
            else:
                forget(rt)
            continue
        if op in (24, 25):  # ori / oris: rS in rt field, rA in ra field
            if rt in known:
                v = known[rt] | (imm if op == 24 else imm << 16)
                if op == 24 and in_range(v, 1) and imm:
                    hits.append((pc, "A", f"ori r{ra},r{rt},{imm}", v, 0, "ADDR"))
                known[ra] = v & 0xffffffff
                derived.pop(ra, None)
            else:
                forget(ra)
            continue
        if op in (20, 21, 23, 26, 27, 28, 29):
            forget(ra)
            continue
        if op in (10, 11, 16, 19, 17):
            continue
        if op == 31:
            xo = (w >> 1) & 0x3ff
            if xo in XFORM_MEM:
                mn, width, kind = XFORM_MEM[xo]
                base = None
                if ra != 0 and ra in known:
                    base = (known[ra], 0, f"r{ra}")
                elif rb in known:
                    base = (known[rb], 0, f"r{rb}")
                elif ra != 0 and ra in derived:
                    base = (derived[ra][0], derived[ra][1], f"r{ra}")
                elif rb in derived:
                    base = (derived[rb][0], derived[rb][1], f"r{rb}")
                if base is not None:
                    b, o, rn = base
                    if in_range(b + o, 1) or in_range(b, 1):
                        hits.append((pc, kind, f"{mn} r{rt},r{ra},r{rb}", b + o, width,
                                     f"INDEXED base 0x{b:06x}+{o} via {rn}"))
                if xo in (55, 119, 311, 375, 183, 247, 439):
                    forget(ra)
                if kind == "L":
                    forget(rt)
                continue
            if xo == 444 and rt == rb:  # mr rA,rS
                if rt in known:
                    known[ra] = known[rt]
                    derived.pop(ra, None)
                elif rt in derived:
                    derived[ra] = derived[rt]
                    known.pop(ra, None)
                else:
                    forget(ra)
                continue
            if xo == 266:  # add rD,rA,rB
                if ra in known and rb not in known:
                    derived[rt] = (known[ra], 0)
                    known.pop(rt, None)
                elif rb in known and ra not in known:
                    derived[rt] = (known[rb], 0)
                    known.pop(rt, None)
                elif ra in known and rb in known:
                    known[rt] = (known[ra] + known[rb]) & 0xffffffff
                    derived.pop(rt, None)
                elif ra in derived:
                    derived[rt] = derived[ra]
                    known.pop(rt, None)
                elif rb in derived:
                    derived[rt] = derived[rb]
                    known.pop(rt, None)
                else:
                    forget(rt)
                continue
            if xo in X_WRITES_RA:
                forget(ra)
                continue
            if xo in X_NO_WRITE:
                continue
            forget(rt)
            continue
        # anything else: assume it writes rt
        forget(rt)
    return hits


all_hits = []
for i, (a, n) in enumerate(funcs):
    stop = funcs[i + 1][0] if i + 1 < len(funcs) else a + 0x800
    if a >= 0x500000:
        data, org = FLASH2, 0x500000
    else:
        data, org = ROM, 0
        stop = min(stop, 0x70000)
    if stop - a > 0x4000:
        stop = a + 0x4000
    for h in scan(a, stop, data, org, n):
        all_hits.append((h[3], n, a, h))

for ea, n, fa, h in sorted(all_hits, key=lambda x: (x[0], x[3][0])):
    pc, kind, txt, ea, width, note = h
    side = "BOOT" if pc < 0x7f60 else "APP "
    print(f"0x{ea:06x} {side} {kind} w{width} @0x{pc:06x} {n} (0x{fa:x}) {txt} {note}")
