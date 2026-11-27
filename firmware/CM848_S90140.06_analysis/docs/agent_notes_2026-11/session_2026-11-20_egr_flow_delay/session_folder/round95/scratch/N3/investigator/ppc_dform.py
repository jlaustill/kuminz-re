"""Round 95 N3 (read-only): every lis-based D-form load / store / addi of the given CM848 addresses in the ROM and
the flash2 image. usage: ppc_dform.py <hex address> [...]"""
import struct
import sys

IMAGES = [
    ("rom", "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin", 0),
    ("flash2", "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_flash2_live.bin", 0x500000),
]
OPS = {32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu", 40: "lhz",
       41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu", 14: "addi"}
STORES = {36, 37, 38, 39, 44, 45}
targets = [int(x, 16) for x in sys.argv[1:]]
for name, path, base in IMAGES:
    img = open(path, "rb").read()
    for i in range(0, len(img) - 4, 4):
        w = struct.unpack(">I", img[i:i + 4])[0]
        if (w >> 26) != 15 or ((w >> 16) & 31) != 0:
            continue
        rd = (w >> 21) & 31
        hi = w & 0xffff
        for j in range(1, 40):
            if i + 4 * j + 4 > len(img):
                break
            w2 = struct.unpack(">I", img[i + 4 * j:i + 4 * j + 4])[0]
            op = w2 >> 26
            ra = (w2 >> 16) & 31
            rt = (w2 >> 21) & 31
            if op in OPS and ra == rd:
                d = w2 & 0xffff
                if d & 0x8000:
                    d -= 0x10000
                v = ((hi << 16) + d) & 0xffffffff
                if v in targets:
                    print(name, hex(base + i + 4 * j), OPS[op], hex(v))
            # stop when the base register is overwritten
            if op in OPS and op not in STORES and rt == rd:
                break
            if op == 15 and rt == rd:
                break
            if op == 18 or op == 19:
                break
