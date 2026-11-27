"""Judge F1: every 'li rX,N' (addi rX,0,N) and 'cmpwi / cmplwi rX,N' in both CM848 images, with the next
instructions decoded enough to see a store (sth / stw / stb with its displacement and base).
usage: scan_cm848_li.py N [N ...]"""
import struct
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
IMAGES = [(0x0, open(REPO + "cm848_rom.bin", "rb").read()), (0x500000, open(REPO + "cm848_flash2_live.bin", "rb").read())]
ST = {44: "sth", 36: "stw", 38: "stb", 45: "sthu", 37: "stwu"}


def dec(w):
    op = w >> 26
    rs, ra, d = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
    sd = d - 0x10000 if d & 0x8000 else d
    if op in ST:
        return f"{ST[op]} r{rs},{sd}(r{ra})"
    if op == 15:
        return f"lis r{rs},0x{d:x}"
    if op == 14:
        return f"addi r{rs},r{ra},{sd}"
    return f"op{op}"


for arg in sys.argv[1:]:
    n = int(arg)
    print(f"===== {n}")
    for base, img in IMAGES:
        for off in range(0, len(img) - 16, 4):
            w = struct.unpack(">I", img[off:off + 4])[0]
            op, rs, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if imm != n:
                continue
            if op == 14 and ra == 0:
                nxt = [dec(struct.unpack(">I", img[off + 4 * k:off + 4 * k + 4])[0]) for k in range(1, 4)]
                prev = [dec(struct.unpack(">I", img[off - 4 * k:off - 4 * k + 4])[0]) for k in range(2, 0, -1)]
                print(f"  0x{base + off:06x}: li r{rs},{n}   prev: {prev}  next: {nxt}")
            elif op == 11 and (rs & 1) == 0:
                print(f"  0x{base + off:06x}: cmpwi r{ra},{n}")
            elif op == 10 and (rs & 1) == 0:
                print(f"  0x{base + off:06x}: cmplwi r{ra},{n}")
