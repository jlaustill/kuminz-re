"""Round 93 F1 (read-only): every 'li rX,N' and 'cmpwi / cmplwi rX,N' in both CM848 images for the fueling state
numbers under test, with the store target of each li (the next sth of that register, its base resolved from the
nearest earlier lis / addi of the base register) and the owning function row.
usage: scan_cm848_state_constants.py <N> [...]"""
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
CARRIERS = {0x3fa0ec, 0x3fa6d0, 0x3fa874, 0x3fb524, 0x3fb526, 0x40a154, 0x40a2d0, 0x40a2d4, 0x40a2da, 0x40a2de,
            0x40a2e2, 0x40a4f0, 0x40afae, 0x40afb4, 0x40b000, 0x40b67c, 0x3fd048, 0x3fcdc4, 0x40af5a, 0x40af5c,
            0x3feaa0}


def owner(a):
    best = None
    for addr, name in ROWS:
        if addr <= a:
            best = (addr, name)
        else:
            break
    return f"{best[1]}@0x{best[0]:x}" if best else "?"


def word(img, off):
    return struct.unpack(">I", img[off:off + 4])[0]


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def resolve_store(base, img, off, reg):
    """the next 'sth reg,d(rb)' within 8 instructions, and rb's value from the nearest earlier lis (+ addi)"""
    for k in range(1, 9):
        if off + 4 * k + 4 > len(img):
            break
        w = word(img, off + 4 * k)
        if (w >> 26) == 44 and ((w >> 21) & 0x1F) == reg:  # sth
            rb = (w >> 16) & 0x1F
            d = s16(w & 0xFFFF)
            value = None
            for j in range(1, 40):
                p = off + 4 * k - 4 * j
                if p < 0:
                    break
                v = word(img, p)
                if (v >> 26) == 14 and ((v >> 21) & 0x1F) == rb and ((v >> 16) & 0x1F) == rb and value is None:
                    d += s16(v & 0xFFFF)  # addi rb,rb,lo
                    continue
                if (v >> 26) == 15 and ((v >> 21) & 0x1F) == rb and ((v >> 16) & 0x1F) == 0:  # lis
                    value = ((v & 0xFFFF) << 16) + d
                    break
            return base + off + 4 * k, value
        if (w >> 26) == 14 and ((w >> 21) & 0x1F) == reg:  # the register is reloaded
            break
    return None, None


for arg in sys.argv[1:]:
    n = int(arg, 0)
    print(f"===== N = {n}")
    for base, img in IMAGES:
        for off in range(0, len(img) - 4, 4):
            w = word(img, off)
            op = w >> 26
            imm = w & 0xFFFF
            if imm != n:
                continue
            a = base + off
            if op == 14 and ((w >> 16) & 0x1F) == 0:  # li
                reg = (w >> 21) & 0x1F
                at, target = resolve_store(base, img, off, reg)
                if target is None:
                    tag = "no sth found"
                else:
                    tag = f"sth @0x{at:x} -> 0x{target & 0xffffffff:x}" + ("  <== FUELING_STATE CARRIER" if (target & 0xffffffff) in CARRIERS else "")
                print(f"  li r{reg},{n} @0x{a:x} [{owner(a)}] {tag}")
            elif op in (10, 11) and ((w >> 21) & 0x1F) in (0,):  # cmplwi / cmpwi cr0
                reg = (w >> 16) & 0x1F
                print(f"  {'cmpwi' if op == 11 else 'cmplwi'} r{reg},{n} @0x{a:x} [{owner(a)}]")
