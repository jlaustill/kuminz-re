"""Round 58 (lis-checked): find every D-form load / store / addi in ROM bank 1 and flash2 whose 16-bit displacement could reach the
given RAM addresses (base 0x400000 via lis 0x40: displacement = address - 0x400000), and print the instruction with its
address. A name grep cannot see an access through a register; this sees every D-form encoding of the low half.
usage: scan_accesses.py <repo> <address>..."""
import os
import struct
import sys

repo = os.path.abspath(sys.argv[1])
base = os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals")
banks = [(0, open(os.path.join(base, "cm848_rom.bin"), "rb").read()),
         (0x500000, open(os.path.join(base, "cm848_flash2_live.bin"), "rb").read())]
OPS = {14: "addi", 32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu",
       40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu"}
for a in (int(x, 16) for x in sys.argv[2:]):
    d = (a - 0x400000) & 0xffff
    hits = []
    for org, data in banks:
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack(">I", data[off:off + 4])[0]
            op = w >> 26
            if op in OPS and (w & 0xffff) == d:
                rt, ra = (w >> 21) & 31, (w >> 16) & 31
                high = None  # the nearest earlier lis ra,X (addis ra,0,X) within 12 instructions
                for back in range(1, 13):
                    if off - 4 * back < 0:
                        break
                    v = struct.unpack(">I", data[off - 4 * back:off - 4 * back + 4])[0]
                    if v >> 26 == 15 and (v >> 21) & 31 == ra and (v >> 16) & 31 == 0:
                        high = (v & 0xffff) << 16
                        break
                full = None if high is None else (high + (d - 0x10000 if d & 0x8000 else d)) & 0xffffffff
                if full is not None and full != a:
                    continue
                where = "lis not found" if full is None else f"= 0x{full:06x}"
                hits.append(f"0x{org + off:06x} {OPS[op]} r{rt},{d - 0x10000 if d & 0x8000 else d}(r{ra}) {where}")
    print(f"0x{a:06x}: {len(hits)} D-form hits" + ("".join(f"\n   {h}" for h in hits[:12])))
