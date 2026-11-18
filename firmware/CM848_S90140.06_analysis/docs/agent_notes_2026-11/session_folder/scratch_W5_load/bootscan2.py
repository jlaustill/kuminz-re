import csv
import struct

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/'
rom = open(FW + 'originals/cm848_rom.bin', 'rb').read()
LIMIT = 0x7F60
ranges = [(0x3FB050, 0x3FB0E0), (0x3FD8CC, 0x3FD8E0), (0x3FEDD8, 0x3FEDE4)]


def inside(a):
    return any(lo <= a < hi for lo, hi in ranges)


LS = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
      40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 14: 'addi', 24: 'ori'}
lows = {}
for lo, hi in ranges:
    for a in range(lo, hi):
        lows.setdefault(a & 0xFFFF, []).append(a)

low_hits = []
branch_hits = []
ptr_hits = []
for off in range(0, LIMIT, 4):
    w = struct.unpack('>I', rom[off:off + 4])[0]
    op = w >> 26
    # (1) low halfword of a load / store / addi / ori that matches a watched address
    if op in LS:
        lo16 = w & 0xFFFF
        if lo16 in lows:
            low_hits.append((hex(off), LS[op], hex(lo16), [hex(x) for x in lows[lo16]][:2]))
    # (2) direct branch (b / bl / ba / bla) whose target lies in a watched range
    if op == 18:
        li = w & 0x03FFFFFC
        if li & 0x02000000:
            li -= 0x04000000
        aa = (w >> 1) & 1
        target = li if aa else off + li
        if inside(target):
            branch_hits.append((hex(off), hex(target), 'bla/ba' if aa else 'bl/b'))
    # (3) a 32-bit data word that equals a watched address (pointer table / literal)
    if inside(w):
        ptr_hits.append((hex(off), hex(w)))

print('low-halfword load/store/addi/ori hits:', len(low_hits))
for h in low_hits:
    print('  ', h)
print('branch hits into the watched ranges:', len(branch_hits))
for h in branch_hits:
    print('  ', h)
print('32-bit pointer words equal to a watched address:', len(ptr_hits))
for h in ptr_hits:
    print('  ', h)

# e2m check: boost value / default under the same offset mapping as the position pair
rows = list(csv.reader(open(FW + 'output/e2m_parameters.csv')))
want = {0x0119660E: 'boost value', 0x01196626: 'boost default', 0x01196634: 'position default', 0x01196636: 'position sensor'}
for r in rows[1:]:
    try:
        a = int(r[2], 16)
    except Exception:
        continue
    if a in want:
        print('e2m', hex(a), want[a], '->', r[0], '|', r[6][:80])
