"""Raw scan: every D-form load / store / addi in both CM848 banks whose signed 16-bit immediate, added to 0x400000
(the lis r,64 base), lands in [lo, hi). No register tracking: it lists candidates the tracked scan may have missed
(code outside the function table, bases set in another block). Also the lis 0x3f / ori form (0x3fxxxx | imm).
usage: raw_imm_scan.py <lo hex> <hi hex>"""
import os
import struct
import sys

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"
banks = [(0, open(os.path.join(base, "cm848_rom.bin"), "rb").read()),
         (0x500000, open(os.path.join(base, "cm848_flash2_live.bin"), "rb").read())]
OPS = {14: "addi", 32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu",
       40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu", 46: "lmw", 47: "stmw"}
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
for org, data in banks:
    for off in range(0, len(data) - 3, 4):
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        rt, ra, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xffff
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op in OPS and ra != 0:
            ea = 0x400000 + simm
            if lo <= ea < hi:
                # look back up to 12 instructions for lis r<ra>,64
                lis = None
                for back in range(1, 13):
                    p = off - 4 * back
                    if p < 0:
                        break
                    w2 = struct.unpack(">I", data[p:p + 4])[0]
                    if w2 >> 26 == 15 and ((w2 >> 16) & 31) == 0 and ((w2 >> 21) & 31) == ra:
                        lis = (org + p, w2 & 0xffff)
                        break
                tag = f"lis r{ra},{lis[1]:#x}@{lis[0]:#x}" if lis else "no-lis-nearby"
                print(f"0x{ea:06x} @0x{org + off:06x} {OPS[op]} r{rt},{simm}(r{ra})  {tag}")
        if op == 24:  # ori
            pass
