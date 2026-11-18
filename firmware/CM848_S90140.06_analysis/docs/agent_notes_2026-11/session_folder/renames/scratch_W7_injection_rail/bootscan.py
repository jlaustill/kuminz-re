import struct
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/'
rom = open(BASE + 'cm848_rom.bin', 'rb').read()
LIM = 0x7F60
targets = [int(t, 16) for t in sys.argv[1:]]
# 16-bit immediate forms of each address: low half as unsigned and as signed with high half adjusted
want = {}
for t in targets:
    lo = t & 0xFFFF
    hi = t >> 16
    want[lo] = (t, 'ori/addi lo, lis hi=%#x or %#x' % (hi, hi + 1 if lo >= 0x8000 else hi))
hits = []
for a in range(0, LIM, 4):
    ins = struct.unpack_from('>I', rom, a)[0]
    imm = ins & 0xFFFF
    if imm in want:
        op = ins >> 26
        hits.append((a, ins, op, imm, want[imm][0]))
print('targets', [hex(t) for t in targets])
for a, ins, op, imm, t in hits:
    print('  %05x: %08x op=%d imm=%04x  (for %#x)' % (a, ins, op, imm, t))
print('hits', len(hits))
