"""usage: peek.py <address> [b|w|d|s] [count]
Reads the RAM dump (addresses >= 0x3f0000, base 0x3FA000) or the ROM image (below), at the given width.
b = byte, w = word (2), d = dword (4), s = signed word. Prints raw unsigned (and signed for w / d)."""
import sys

A = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"
ram = open(A + "cm848_ram.bin", "rb").read()
rom = open(A + "cm848_rom.bin", "rb").read()
flash2 = open(A + "cm848_flash2_live.bin", "rb").read()
address = int(sys.argv[1], 16)
kind = sys.argv[2] if len(sys.argv) > 2 else "w"
count = int(sys.argv[3]) if len(sys.argv) > 3 else 1
width = {"b": 1, "w": 2, "s": 2, "d": 4}[kind]
for i in range(count):
    a = address + i * width
    if a >= 0x500000:
        data, at = flash2, a - 0x500000
    elif a >= 0x3F0000:
        data, at = ram, a - 0x3FA000
    else:
        data, at = rom, a
    raw = data[at:at + width]
    u = int.from_bytes(raw, "big")
    sgn = int.from_bytes(raw, "big", signed=True)
    print(f"0x{a:x}: {u} (0x{u:x}) signed {sgn}")
