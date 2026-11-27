"""Read big-endian words (or :b bytes, :l dwords) from the CM550 RAM dumps.
RAM 0x800000-0x8091c1 from J90350.00.ram.bin (offset = address - 0x800000);
0x809242 and up from J90350.00.extended_ram.bin (offset = address - 0x809242). usage: ram_words.py <hex addr>[:b|:l] ..."""
import sys

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()
for arg in sys.argv[1:]:
    a, _, w = arg.partition(":")
    addr = int(a, 16)
    n = {"b": 1, "l": 4}.get(w, 2)
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        data, src = ram[addr - 0x800000:addr - 0x800000 + n], "ram"
    elif 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        data, src = ext[addr - 0x809242:addr - 0x809242 + n], "ext"
    else:
        print(f"0x{addr:x}: not in a dump")
        continue
    v = int.from_bytes(data, "big")
    s = v - (1 << (8 * n)) if v >> (8 * n - 1) else v
    print(f"0x{addr:x} ({src}): {v} (0x{v:0{2 * n}x}) signed {s}")
