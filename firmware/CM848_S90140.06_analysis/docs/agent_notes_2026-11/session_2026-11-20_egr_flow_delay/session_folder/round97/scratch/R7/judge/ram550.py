"""read CM550 RAM dump values: ram550.py <b|w|l> 0xADDR [...]"""
import sys
D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()


def get(a, n):
    if 0x800000 <= a and a + n <= 0x800000 + len(ram):
        return ram[a - 0x800000:a - 0x800000 + n]
    if 0x809242 <= a and a + n <= 0x809242 + len(ext):
        return ext[a - 0x809242:a - 0x809242 + n]
    return None


w = sys.argv[1]
n = {'b': 1, 'w': 2, 'l': 4}[w]
for s in sys.argv[2:]:
    a = int(s, 16)
    v = get(a, n)
    print(hex(a), 'not dumped' if v is None else f"0x{int.from_bytes(v, 'big'):x} ({int.from_bytes(v, 'big', signed=True)})")
