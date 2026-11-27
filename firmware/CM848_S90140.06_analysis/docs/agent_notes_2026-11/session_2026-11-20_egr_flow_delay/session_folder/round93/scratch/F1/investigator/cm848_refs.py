"""Round 93 F1 (read-only): load / store / addi references to a CM848 RAM address in both images: any instruction
whose 16-bit displacement equals the low half of the address when the high half is the adjusted lis value
(lis rX,hi ; op rY,lo(rX)). Prints the owning function row. A coarse scan: a hit only shows a candidate.
usage: cm848_refs.py <hex address> [...]"""
import csv
import struct
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
IMAGES = [(0x0, open(REPO + "cm848_rom.bin", "rb").read()), (0x500000, open(REPO + "cm848_flash2_live.bin", "rb").read())]
ROWS = []
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/cm848/function_renames.csv", errors="replace")):
    if row and row[0].startswith("0x"):
        try:
            ROWS.append((int(row[0], 16), row[1]))
        except ValueError:
            pass
ROWS.sort()
OPS = {32: "lwz", 34: "lbz", 36: "stw", 38: "stb", 40: "lhz", 42: "lha", 44: "sth", 14: "addi"}


def owner(a):
    best = None
    for addr, name in ROWS:
        if addr <= a:
            best = (addr, name)
        else:
            break
    return f"{best[1]}@0x{best[0]:x}" if best else "?"


for arg in sys.argv[1:]:
    target = int(arg, 16)
    lo = target & 0xFFFF
    hi = (target >> 16) + (1 if lo & 0x8000 else 0)
    print(f"== 0x{target:x} (lis {hi}, lo 0x{lo:x})")
    for base, img in IMAGES:
        for off in range(0, len(img) - 4, 4):
            w = struct.unpack(">I", img[off:off + 4])[0]
            op = w >> 26
            if op in OPS and (w & 0xFFFF) == lo:
                ra = (w >> 16) & 0x1F
                # confirm the base register was loaded with the high half within the previous 12 instructions
                ok = False
                for j in range(1, 13):
                    p = off - 4 * j
                    if p < 0:
                        break
                    v = struct.unpack(">I", img[p:p + 4])[0]
                    if (v >> 26) == 15 and ((v >> 21) & 0x1F) == ra and (v & 0xFFFF) == hi:
                        ok = True
                        break
                if ok:
                    print(f"  {OPS[op]} @0x{base + off:x} [{owner(base + off)}]")
