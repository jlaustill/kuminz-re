"""Find even offsets holding a 16-bit value in a set, where the preceding word looks like an opcode with a
(d16,An) or abs.W operand (mode 101 or mode 111/000 in either EA field). usage: scan16.py v1 v2 ..."""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
d = open(ROM, "rb").read()
vals = {int(v, 16) for v in sys.argv[1:]}


def w(a):
    return struct.unpack(">H", d[a:a + 2])[0]


for i in range(2, len(d) - 1, 2):
    v = w(i)
    if v not in vals:
        continue
    op = w(i - 2)
    src_mode, src_reg = (op >> 3) & 7, op & 7
    dst_reg, dst_mode = (op >> 9) & 7, (op >> 6) & 7
    tags = []
    if src_mode == 5:
        tags.append("src(d16,A%d)" % src_reg)
    if src_mode == 7 and src_reg == 0:
        tags.append("src abs.W")
    if (op >> 12) in (1, 2, 3) and dst_mode == 5:
        tags.append("dst(d16,A%d)" % dst_reg)
    if (op >> 12) in (1, 2, 3) and dst_mode == 7 and dst_reg == 0:
        tags.append("dst abs.W")
    print("0x%05x value 0x%04x prev opcode %04x %s  ctx %s" % (i, v, op, " ".join(tags), d[i - 6:i + 6].hex()))
