"""Raw scan of the CM848 ROM and flash2 for instructions that form a data address as lis rA,HI + D-form (load / store /
addi) with rA and a displacement: the accesses a name grep of the .cpp cannot see. The lis must be within 24
instructions before, with no write to rA in between (a heuristic, enough to find candidates to read).
usage: raw_address_scan.py <originals dir> 0xADDR [0xADDR ...]"""
import os
import sys

D_FORM = {14: "addi", 32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu",
          40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu"}
originals, targets = sys.argv[1], [int(a, 16) for a in sys.argv[2:]]
images = [("rom", os.path.join(originals, "cm848_rom.bin"), 0x0), ("flash2", os.path.join(originals, "cm848_flash2_live.bin"), 0x500000)]
for label, path, base in images:
    data = open(path, "rb").read()
    words = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 4)]
    for k, w in enumerate(words):
        op, rd, ra, d = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op not in D_FORM or ra == 0:
            continue
        sd = d - 0x10000 if d & 0x8000 else d
        for j in range(k - 1, max(-1, k - 25), -1):
            p = words[j]
            pop, prd, pra = p >> 26, (p >> 21) & 31, (p >> 16) & 31
            if pop == 15 and prd == ra and pra == 0:  # lis ra,HI
                hi = p & 0xFFFF
                address = ((hi << 16) + sd) & 0xFFFFFFFF
                if address in targets:
                    print(f"{label} 0x{base + 4 * k:06x}: {D_FORM[op]} r{rd},{sd}(r{ra})  lis @ 0x{base + 4 * j:06x} -> 0x{address:x}")
                break
            if (p >> 21) & 31 == ra and pop in (14, 15, 32, 33, 34, 35, 40, 41, 42, 43, 31):
                break  # ra rewritten by something else
