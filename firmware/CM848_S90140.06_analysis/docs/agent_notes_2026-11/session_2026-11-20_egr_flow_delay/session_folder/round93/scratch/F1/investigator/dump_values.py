"""Round 93 F1 (read-only): CM550 RAM dump values at the declared width.
RAM J90350.00.ram.bin = 0x800000..0x8091C1 ; extended RAM J90350.00.extended_ram.bin file offset = address - 0x809242.
usage: dump_values.py <hex address>:<width 1|2|4> [...]"""
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(BASE + "J90350.00.ram.bin", "rb").read()
ext = open(BASE + "J90350.00.extended_ram.bin", "rb").read()
for arg in sys.argv[1:]:
    a, w = arg.split(":")
    a = int(a, 16)
    w = int(w)
    if 0x800000 <= a and a + w <= 0x800000 + len(ram):
        data = ram[a - 0x800000:a - 0x800000 + w]
        src = "ram"
    elif 0x809242 <= a and a + w <= 0x809242 + len(ext):
        data = ext[a - 0x809242:a - 0x809242 + w]
        src = "ext"
    else:
        print(f"0x{a:x}: outside both dumps")
        continue
    v = int.from_bytes(data, "big")
    print(f"0x{a:x} [{src}] width {w}: {v} (0x{v:x})")
