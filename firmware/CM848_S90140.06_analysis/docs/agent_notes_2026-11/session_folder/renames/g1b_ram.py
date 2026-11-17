import struct
import sys

RAM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin"
BASE = 0x3FA000
with open(RAM, "rb") as handle:
    data = handle.read()

# usage: ram.py <hexaddr>:<w|b|d|s>[:<count>] ...   (w = u16 big-endian, s = s16, b = u8, d = u32)
for spec in sys.argv[1:]:
    parts = spec.split(":")
    address = int(parts[0], 16)
    kind = parts[1] if len(parts) > 1 else "w"
    count = int(parts[2]) if len(parts) > 2 else 1
    size = {"w": 2, "s": 2, "b": 1, "d": 4}[kind]
    fmt = {"w": "H", "s": "h", "b": "B", "d": "I"}[kind]
    offset = address - BASE
    values = struct.unpack(">" + fmt * count, data[offset:offset + size * count])
    print("0x%08x %s:" % (address, kind), " ".join(str(value) for value in values))
