"""Round 93 J1 describer (read-only): read CM550 RAM dump values at the DECLARED width.
usage: ram_peek.py <0xADDR>:<b|w|l>[:count] ..."""
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ram = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin", "rb").read()
ext = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.extended_ram.bin", "rb").read()
rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
W = {"b": 1, "w": 2, "l": 4}


def read(a, n):
    if a < 0x40000:
        return rom[a:a + n], "rom"
    if 0x800000 <= a and a + n <= 0x800000 + len(ram):
        return ram[a - 0x800000:a - 0x800000 + n], "ram"
    if 0x809242 <= a and a + n <= 0x809242 + len(ext):
        return ext[a - 0x809242:a - 0x809242 + n], "extended_ram"
    return None, "not dumped"


for arg in sys.argv[1:]:
    parts = arg.split(":")
    a = int(parts[0], 16)
    w = W[parts[1]] if len(parts) > 1 else 1
    count = int(parts[2]) if len(parts) > 2 else 1
    vals = []
    src = ""
    for i in range(count):
        data, src = read(a + i * w, w)
        vals.append("??" if data is None else f"0x{int.from_bytes(data, 'big'):0{2 * w}x}")
    print(f"0x{a:06x} [{src}] width {w} x{count}: {' '.join(vals)}")
