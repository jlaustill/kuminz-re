"""peek.py ADDR [count] [width] [s]: dump values at the declared width from the images
(ROM below 0x3f0000, flash2 from 0x500000, the RAM dump otherwise)."""
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"
rom = open(FW + "cm848_rom.bin", "rb").read()
ram = open(FW + "cm848_ram.bin", "rb").read()
f2 = open(FW + "cm848_flash2_live.bin", "rb").read()


def get(addr):
    if addr < 0x3f0000:
        return rom, addr
    if addr >= 0x500000:
        return f2, addr - 0x500000
    return ram, addr - 0x3FA000


a = int(sys.argv[1], 16)
n = int(sys.argv[2]) if len(sys.argv) > 2 else 1
w = int(sys.argv[3]) if len(sys.argv) > 3 else 2
sg = len(sys.argv) > 4 and sys.argv[4] == "s"
for i in range(n):
    d, at = get(a + i * w)
    v = int.from_bytes(d[at:at + w], "big", signed=sg)
    print(f"0x{a + i * w:08x}: {v} (0x{v & ((1 << (8 * w)) - 1):0{2 * w}x})")
