"""Round 58 (v2): find D-form loads / stores / addi that reach the given addresses, tracking base registers.
A register set by lis (addis rD,0,H) / addi rD,rA,L / ori rD,rS,U from a known value keeps that value until an X-form
or another D-form instruction writes it, a call (bl) clobbers the volatile registers r0 / r3-r12, or blr ends the
function. Any D-form access through a known register is resolved to base + displacement. This sees the
"lbz r11,19(r31)" form a lis-only scan misses; it can still miss accesses through computed or loaded pointers.
usage: scan_accesses_v2.py <repo> <address>..."""
import os
import struct
import sys

repo = os.path.abspath(sys.argv[1])
base = os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals")
banks = [(0, open(os.path.join(base, "cm848_rom.bin"), "rb").read()),
         (0x500000, open(os.path.join(base, "cm848_flash2_live.bin"), "rb").read())]
OPS = {14: "addi", 32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu",
       40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu", 46: "lmw", 47: "stmw"}
LOADS = {32, 33, 34, 35, 40, 41, 42, 43}
targets = {int(x, 16): [] for x in sys.argv[2:]}
for org, data in banks:
    regs = {}
    for off in range(0, len(data) - 3, 4):
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        rt, ra, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xffff
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if w == 0x4e800020:          # blr
            regs = {}
            continue
        if op == 18 and w & 1:       # bl: volatile registers clobbered
            regs = {r: v for r, v in regs.items() if r == 1 or r == 2 or r >= 13}
            continue
        if op in OPS and op != 14 and ra in regs and ra != 0:
            a = (regs[ra] + simm) & 0xffffffff
            width = {34: 1, 35: 1, 38: 1, 39: 1, 40: 2, 41: 2, 42: 2, 43: 2, 44: 2, 45: 2}.get(op, 4)
            for t in targets:
                if a <= t < a + width:
                    targets[t].append(f"0x{org + off:06x} {OPS[op]} r{rt},{simm}(r{ra}) = 0x{a:06x}")
        if op == 15 and ra == 0:     # lis
            regs[rt] = (imm << 16) & 0xffffffff
        elif op == 14:               # addi / li
            if ra == 0:
                regs[rt] = simm & 0xffffffff
            elif ra in regs:
                v = (regs[ra] + simm) & 0xffffffff
                for t in targets:
                    if v == t:
                        targets[t].append(f"0x{org + off:06x} addi r{rt},r{ra},{simm} = &0x{v:06x}")
                regs[rt] = v
            else:
                regs.pop(rt, None)
        elif op == 24:               # ori rA,rS,U (rS in the rt field, rA in the ra field)
            if rt in regs:
                regs[ra] = regs[rt] | imm
            else:
                regs.pop(ra, None)
        elif op in LOADS or op in (33, 35, 41, 43):
            regs.pop(rt, None)
            if op in (33, 35, 41, 43):
                regs.pop(ra, None)
        elif op == 31:               # X-form: mr rA,rS (or rA,rS,rS) copies; anything else forgets rt and rA
            rb, xo = (w >> 11) & 31, (w >> 1) & 0x3ff
            if xo == 444 and rb == rt:
                if rt in regs:
                    regs[ra] = regs[rt]
                else:
                    regs.pop(ra, None)
            else:
                regs.pop(rt, None)
                regs.pop(ra, None)
        elif op in (7, 8, 10, 11, 12, 13, 20, 21, 23, 28, 29):  # mulli / subfic / cmpli... / rlwinm / andi. / andis.
            if op in (20, 21, 23, 28, 29):
                regs.pop(ra, None)
            elif op in (7, 8, 12, 13):
                regs.pop(rt, None)
for t, hits in targets.items():
    print(f"0x{t:06x}: {len(hits)} hits" + "".join(f"\n   {h}" for h in hits[:14]))
