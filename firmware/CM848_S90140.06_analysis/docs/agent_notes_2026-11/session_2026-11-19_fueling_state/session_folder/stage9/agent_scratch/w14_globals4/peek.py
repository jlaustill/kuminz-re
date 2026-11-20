"""usage: peek.py <addr>:<width>[:s] ...  -> RAM-dump / ROM / flash2 values (big endian). Append :s for signed."""
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


for arg in sys.argv[1:]:
    parts = arg.split(":")
    a = int(parts[0], 16)
    w = int(parts[1]) if len(parts) > 1 and parts[1] else 2
    signed = len(parts) > 2 and parts[2] == "s"
    v = peek(a, w)
    if v is None:
        print(f"{a:#010x}: out of range")
        continue
    sv = v - (1 << (8 * w)) if signed and v >= 1 << (8 * w - 1) else v
    print(f"{a:#010x} width {w}: {sv} ({v:#x})")
