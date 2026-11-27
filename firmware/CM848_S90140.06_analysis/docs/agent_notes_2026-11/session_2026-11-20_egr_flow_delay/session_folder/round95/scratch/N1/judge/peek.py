"""Peek CM550 RAM dump values at the declared width: peek.py <hexaddr>:<b|w|l> ..."""
import sys

RAM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin"
ram = open(RAM, "rb").read()
SIZE = {"b": 1, "w": 2, "l": 4}
for arg in sys.argv[1:]:
    a, k = arg.split(":")
    a = int(a, 16)
    n = SIZE[k]
    off = a - 0x800000
    if off < 0 or off + n > len(ram):
        print(f"0x{a:x}: outside the RAM dump")
        continue
    v = int.from_bytes(ram[off:off + n], "big")
    print(f"0x{a:x}.{k} = 0x{v:0{2 * n}x} ({v})")
