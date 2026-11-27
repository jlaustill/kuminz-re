"""Read CM550 RAM dump values at their declared width.
usage: peek.py <address hex>:<width 1|2|4> [...]
RAM dump J90350.00.ram.bin covers 0x800000-0x8091c1 (offset = address - 0x800000);
extended_ram.bin covers 0x809242+ (offset = address - 0x809242). ROM file offset = address."""
import sys

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(base + "J90350.00.ram.bin", "rb").read()
ext = open(base + "J90350.00.extended_ram.bin", "rb").read()
rom = open(base + "J90350.00.rom.bin", "rb").read()
for arg in sys.argv[1:]:
    a, w = arg.split(":")
    a = int(a, 16)
    w = int(w)
    if a < 0x40000:
        data, off, where = rom, a, "rom"
    elif 0x800000 <= a < 0x800000 + len(ram):
        data, off, where = ram, a - 0x800000, "ram"
    elif 0x809242 <= a < 0x809242 + len(ext):
        data, off, where = ext, a - 0x809242, "ext"
    else:
        print(f"0x{a:x}: not dumped")
        continue
    v = int.from_bytes(data[off:off + w], "big")
    s = v - (1 << (8 * w)) if v >= (1 << (8 * w - 1)) else v
    print(f"0x{a:x} [{where}] w{w}: 0x{v:0{2*w}x} = {v} (signed {s})")
