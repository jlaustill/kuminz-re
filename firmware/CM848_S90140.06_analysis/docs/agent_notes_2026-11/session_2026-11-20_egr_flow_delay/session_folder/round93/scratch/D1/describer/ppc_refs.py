"""Describer D1 scratch: brute scan of the CM848 images for PowerPC accesses to a data address.
For every D-form load / store / addi whose 16-bit displacement equals the low half of the address, walk back up to
64 instructions for the 'lis rBase,HA' that sets the base register (HA = high-adjusted half). Also reports
r13 / r2 small-data hits when the bases are given.
usage: ppc_refs.py 0xADDR [...]"""
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"
IMAGES = [("rom", 0x0, open(f"{FW}/cm848_rom.bin", "rb").read()),
          ("flash2", 0x500000, open(f"{FW}/cm848_flash2_live.bin", "rb").read())]
OPS = {32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu", 40: "lhz",
       41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu", 14: "addi", 46: "lmw", 47: "stmw"}


def scan(target):
    lo = target & 0xffff
    ha = ((target + 0x8000) >> 16) & 0xffff
    hits = []
    for label, base, img in IMAGES:
        for i in range(0, len(img) - 4, 4):
            w = int.from_bytes(img[i:i + 4], "big")
            op = w >> 26
            if op not in OPS or (w & 0xffff) != lo:
                continue
            ra = (w >> 16) & 31
            rd = (w >> 21) & 31
            if ra == 0:
                continue
            # walk back for lis ra,ha
            found = None
            for k in range(1, 65):
                j = i - 4 * k
                if j < 0:
                    break
                p = int.from_bytes(img[j:j + 4], "big")
                if (p >> 26) == 15 and ((p >> 21) & 31) == ra and ((p >> 16) & 31) == 0:
                    found = (j, p & 0xffff)
                    break
            if found and found[1] == ha:
                hits.append((base + i, OPS[op], rd, ra, base + found[0]))
    return hits


for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x}")
    for at, op, rd, ra, lis in scan(t):
        print(f"  0x{at:06x}: {op} r{rd},0x{t & 0xffff:x}(r{ra})   (lis r{ra} at 0x{lis:06x})")
