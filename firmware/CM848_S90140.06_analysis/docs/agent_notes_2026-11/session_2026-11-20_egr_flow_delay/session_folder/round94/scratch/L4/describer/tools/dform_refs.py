"""List D-form accesses (lis rX,hi ; op d(rX)) and 4-byte words equal to the given CM848 addresses.
Takes the MOST RECENT write of the base register within 16 instructions; only a lis (addis rX,0,hi) counts as the base.
usage: dform_refs.py 0xADDR [0xADDR ...]"""
import struct
import sys

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
imgs = [(open(FW + 'cm848_rom.bin', 'rb').read(), 0), (open(FW + 'cm848_flash2_live.bin', 'rb').read(), 0x500000)]
targets = {int(a, 16) for a in sys.argv[1:]}
NAMES = {14: 'addi', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
         40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 46: 'lmw', 47: 'stmw'}
# opcodes whose rt field is a destination register (so they overwrite rt)
WRITES_RT = {14, 15, 32, 33, 34, 35, 40, 41, 42, 43, 46, 7, 8, 12, 13}
for img, base in imgs:
    words = [struct.unpack('>I', img[o:o + 4])[0] for o in range(0, len(img) - 3, 4)]
    for i, w in enumerate(words):
        op = w >> 26
        if op in NAMES:
            ra = (w >> 16) & 31
            d = w & 0xffff
            if d & 0x8000:
                d -= 0x10000
            if ra == 0:
                continue
            for j in range(i - 1, max(-1, i - 17), -1):
                v = words[j]
                vop = v >> 26
                rt = (v >> 21) & 31
                if vop == 15 and rt == ra:
                    if ((v >> 16) & 31) == 0:
                        ea = (((v & 0xffff) << 16) + d) & 0xffffffff
                        if ea in targets:
                            print(hex(base + i * 4), NAMES[op], hex(ea))
                    break
                if vop in WRITES_RT and rt == ra:
                    break
                if vop in (24, 25, 26, 27, 28, 29) and ((v >> 16) & 31) == ra:  # ori/oris/xori/andi write ra
                    break
        if w in targets:
            print(hex(base + i * 4), 'word', hex(w))
