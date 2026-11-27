"""Judge F1 run 2: read CM550 RAM dump values at a declared width (w = word, l = dword, b = byte).
RAM dump: address - 0x800000 up to 0x8091c1; extended RAM dump: address - 0x809242.
usage: ramread.py w:0x80dc26 l:0x806192 ..."""
import struct
import sys

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()
SIZES = {"b": (1, ">B"), "w": (2, ">H"), "l": (4, ">I")}
for arg in sys.argv[1:]:
    kind, a = arg.split(":")
    a = int(a, 16)
    n, fmt = SIZES[kind]
    if a + n - 1 <= 0x8091c1:
        buf, off, src = ram, a - 0x800000, "ram"
    else:
        buf, off, src = ext, a - 0x809242, "extended"
    if off < 0 or off + n > len(buf):
        print(f"{a:#x}: outside the dumps")
        continue
    v = struct.unpack(fmt, buf[off:off + n])[0]
    print(f"{a:#x} ({src}, {kind}): {v} ({v:#x})")
