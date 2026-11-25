"""Find every reference to CM848 code/data addresses in the ROM and flash2 images.
Reports I-form b/bl, B-form bc, aligned 32-bit words, and lis+addi / lis+ori pairs (any register, within 8 insns).
Usage: ppc_reach.py <addr hex> [...]"""
import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
IMAGES = [(BASE + 'cm848_rom.bin', 0), (BASE + 'cm848_flash2_live.bin', 0x500000)]


def scan(targets):
    out = {t: [] for t in targets}
    for path, base in IMAGES:
        img = open(path, 'rb').read()
        words = [struct.unpack('>I', img[o:o + 4])[0] for o in range(0, len(img) - 3, 4)]
        for i, w in enumerate(words):
            pc = base + 4 * i
            op = w >> 26
            if op == 18:
                li = w & 0x03fffffc
                if li & 0x02000000:
                    li -= 0x04000000
                tgt = li if (w >> 1) & 1 else pc + li
                if tgt in out:
                    out[tgt].append((hex(pc), 'bl' if w & 1 else 'b'))
            elif op == 16:
                bd = w & 0xfffc
                if bd & 0x8000:
                    bd -= 0x10000
                tgt = bd if (w >> 1) & 1 else pc + bd
                if tgt in out:
                    out[tgt].append((hex(pc), 'bc'))
            if w in out:
                out[w].append((hex(pc), 'word'))
            if op == 15 and ((w >> 16) & 0x1f) == 0:  # lis rD,imm
                rd = (w >> 21) & 0x1f
                hi = (w & 0xffff) << 16
                for j in range(i + 1, min(i + 9, len(words))):
                    w2 = words[j]
                    op2 = w2 >> 26
                    ra = (w2 >> 16) & 0x1f
                    rs = (w2 >> 21) & 0x1f
                    imm = w2 & 0xffff
                    if op2 == 14 and ra == rd:  # addi
                        val = (hi + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xffffffff
                        if val in out:
                            out[val].append((hex(pc), 'lis+addi @' + hex(base + 4 * j)))
                    if op2 == 24 and rs == rd:  # ori
                        val = hi | imm
                        if val in out:
                            out[val].append((hex(pc), 'lis+ori @' + hex(base + 4 * j)))
    return out


if __name__ == '__main__':
    ts = [int(a, 16) for a in sys.argv[1:]]
    for t, refs in scan(ts).items():
        print(hex(t), len(refs), refs[:30])
