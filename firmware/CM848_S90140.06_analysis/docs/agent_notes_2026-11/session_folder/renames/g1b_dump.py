import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"
with open(ROM, "rb") as handle:
    data = handle.read()

# usage: dump.py <hexaddr> <count words> [<hexaddr> <count words> ...]
args = sys.argv[1:]
index = 0
while index + 1 < len(args):
    address = int(args[index], 16)
    count = int(args[index + 1])
    words = struct.unpack(">" + "H" * count, data[address:address + 2 * count])
    print("0x%08x:" % address, " ".join("%d" % word for word in words))
    index += 2
