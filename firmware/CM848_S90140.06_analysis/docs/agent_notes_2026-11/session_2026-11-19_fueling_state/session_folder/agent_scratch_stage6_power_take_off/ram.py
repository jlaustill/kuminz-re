"""Read the CM848 RAM dump (big-endian) at a declared width.
usage: ram.py <addr>:<b|w|d|sw>[:<count>] ...   (addr hex; sw = signed word)"""
import struct
import sys

PATH = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin"
data = open(PATH, "rb").read()
BASE = 0x3FA000
FMT = {"b": (1, ">B"), "w": (2, ">H"), "d": (4, ">I"), "sw": (2, ">h"), "sd": (4, ">i")}
for arg in sys.argv[1:]:
    parts = arg.split(":")
    addr = int(parts[0], 16)
    width, fmt = FMT[parts[1]]
    count = int(parts[2]) if len(parts) > 2 else 1
    vals = []
    for k in range(count):
        off = addr + k * width - BASE
        if off < 0 or off + width > len(data):
            vals.append("OUT_OF_DUMP")
            continue
        v = struct.unpack(fmt, data[off:off + width])[0]
        vals.append(f"{v}(0x{v & ((1 << (8 * width)) - 1):x})")
    print(f"0x{addr:x} [{parts[1]}] -> {' '.join(vals)}")
