import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"


def load(name):
    with open(BASE + name, "rb") as handle:
        return handle.read()


rom = load("cm848_rom.bin")
blocks = [(0x0, rom[:0x70000]), (0x3F9800, rom[0x3C30:0x3C30 + 0x800]), (0x3FA000, load("cm848_ram.bin")),
          (0x500000, load("cm848_flash2_live.bin"))]


def peek(addr, width):
    for base, data in reversed(blocks):
        if base <= addr and addr + width <= base + len(data):
            return int.from_bytes(data[addr - base:addr - base + width], "big")
    return None


# usage: peek.py <addr>:<width> ...
for arg in sys.argv[1:]:
    address, _, width = arg.partition(":")
    a = int(address, 16)
    w = int(width or 2)
    v = peek(a, w)
    print(f"{a:#010x} width {w}: {v} ({v:#x})" if v is not None else f"{a:#010x}: out of range")
