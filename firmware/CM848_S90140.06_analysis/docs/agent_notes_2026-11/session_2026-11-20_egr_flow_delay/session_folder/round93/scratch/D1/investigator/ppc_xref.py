"""Whole-image CM848 data xref (read-only helper, round 93 batch D1 investigator).
Linear sweep of cm848_rom.bin (base 0) and cm848_flash2_live.bin (base 0x500000): tracks lis / addi / addis / ori / li
register constants (reset at blr) and reports every load / store / address-materialisation whose effective address
falls in [lo, hi].
usage: ppc_xref.py 0xADDR[-0xADDR] ..."""
import bisect
import re
import struct
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/cm848/cm848_rom.ghidra.cpp"
IMAGES = [(FW + "cm848_rom.bin", 0), (FW + "cm848_flash2_live.bin", 0x500000)]
LOADSTORE = {32: ("lwz", 4), 33: ("lwzu", 4), 34: ("lbz", 1), 35: ("lbzu", 1), 36: ("stw", 4), 37: ("stwu", 4),
             38: ("stb", 1), 39: ("stbu", 1), 40: ("lhz", 2), 41: ("lhzu", 2), 42: ("lha", 2), 43: ("lhau", 2),
             44: ("sth", 2), 45: ("sthu", 2), 46: ("lmw", 4), 47: ("stmw", 4)}

funcs = []
for line in open(CPP, errors="replace"):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", line)
    if m:
        funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [a for a, _ in funcs]


def owner(addr):
    i = bisect.bisect_right(starts, addr) - 1
    return funcs[i][1] if i >= 0 else "?"


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def scan(ranges):
    out = []
    for path, base in IMAGES:
        data = open(path, "rb").read()
        reg = {}
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack_from(">I", data, off)[0]
            pc = base + off
            op = w >> 26
            rd = (w >> 21) & 31
            ra = (w >> 16) & 31
            imm = w & 0xffff
            if w == 0x4e800020:  # blr
                reg = {}
                continue
            if op == 15:  # addis / lis
                if ra == 0:
                    reg[rd] = (imm << 16) & 0xffffffff
                elif ra in reg:
                    reg[rd] = (reg[ra] + (imm << 16)) & 0xffffffff
                else:
                    reg.pop(rd, None)
                continue
            if op == 14:  # addi / li
                if ra == 0:
                    reg[rd] = s16(imm) & 0xffffffff
                elif ra in reg:
                    v = (reg[ra] + s16(imm)) & 0xffffffff
                    reg[rd] = v
                    for lo, hi in ranges:
                        if lo <= v <= hi:
                            out.append((pc, "addi(address)", 0, v))
                else:
                    reg.pop(rd, None)
                continue
            if op == 24:  # ori rA,rS,imm  (rS = rd field)
                rs = rd
                if rs in reg:
                    v = reg[rs] | imm
                    reg[ra] = v
                    for lo, hi in ranges:
                        if lo <= v <= hi and imm:
                            out.append((pc, "ori(address)", 0, v))
                else:
                    reg.pop(ra, None)
                continue
            if op in LOADSTORE:
                name, width = LOADSTORE[op]
                if ra in reg:
                    v = (reg[ra] + s16(imm)) & 0xffffffff
                    for lo, hi in ranges:
                        if lo <= v <= hi:
                            out.append((pc, name, width, v))
                if name.startswith("l") and op != 46:
                    reg.pop(rd, None)
                if name.endswith("u") and ra in reg:
                    reg[ra] = (reg[ra] + s16(imm)) & 0xffffffff
                continue
            if op == 31:
                xo = (w >> 1) & 0x3ff
                if xo == 444 and rd == ((w >> 11) & 31):  # mr rA,rS
                    if rd in reg:
                        reg[ra] = reg[rd]
                    else:
                        reg.pop(ra, None)
                    continue
                # other X-form: destination is rd for loads/arith, ra for logical; drop both conservatively
                reg.pop(rd, None)
                if xo in (28, 60, 124, 284, 316, 412, 444, 476, 24, 536, 792, 824, 922, 954, 26):
                    reg.pop(ra, None)
                continue
            if op in (18, 16):  # b / bc: calls clobber volatile regs
                if w & 1:
                    for r in (0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12):
                        reg.pop(r, None)
                continue
            if op in (7, 8, 12, 13, 20, 21, 23, 25, 26, 27, 28, 29):
                # mulli subfic addic addic. rlwimi rlwinm rlwnm oris xori xoris andi. andis.
                tgt = rd if op in (7, 8, 12, 13) else ra
                reg.pop(tgt, None)
                continue
    return out


if __name__ == "__main__":
    ranges = []
    for a in sys.argv[1:]:
        if "-" in a:
            lo, hi = a.split("-")
            ranges.append((int(lo, 16), int(hi, 16)))
        else:
            ranges.append((int(a, 16), int(a, 16)))
    for pc, name, width, v in scan(ranges):
        print(f"0x{pc:06x} {name:<14} width {width} -> 0x{v:06x}   in {owner(pc)}")
