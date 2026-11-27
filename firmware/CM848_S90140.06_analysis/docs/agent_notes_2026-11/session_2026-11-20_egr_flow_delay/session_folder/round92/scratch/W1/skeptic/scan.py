"""Independent scan: every byte offset in the CM550 ROM holding a 32-bit big-endian value in a range
(any alignment), with the two words before it. usage: scan.py LO HI"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
d = open(ROM, "rb").read()
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
n = 0
for i in range(0, len(d) - 3):
    v = struct.unpack(">I", d[i:i + 4])[0]
    if lo <= v < hi:
        pre = d[max(0, i - 6):i].hex()
        post = d[i + 4:i + 10].hex()
        print("0x%05x %s value 0x%08x  pre %s post %s" % (i, "odd" if i & 1 else "even", v, pre, post))
        n += 1
print("total", n)
