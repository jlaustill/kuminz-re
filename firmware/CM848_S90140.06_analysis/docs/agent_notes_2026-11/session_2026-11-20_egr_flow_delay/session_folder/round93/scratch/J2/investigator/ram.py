"""J2 investigator (round 93, read-only): read bytes of the CM550 RAM / extended RAM / ROM dumps at an address.
usage: ram.py <address hex> [<byte count>]   (ROM below 0x40000, RAM 0x800000-0x8091C1, extended 0x809242+)"""
import os
import sys

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware"


def read(a, n):
    if a < 0x40000:
        f, off = "J90350.00.rom.bin", a
    elif 0x800000 <= a <= 0x8091C1:
        f, off = "J90350.00.ram.bin", a - 0x800000
    elif a >= 0x809242:
        f, off = "J90350.00.extended_ram.bin", a - 0x809242
    else:
        return None, None
    data = open(os.path.join(base, f), "rb").read()
    return f, data[off:off + n]


if __name__ == "__main__":
    a = int(sys.argv[1], 16)
    n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 16
    f, b = read(a, n)
    if b is None:
        print("address not in a dump")
    else:
        for i in range(0, len(b), 16):
            print(f"{f} 0x{a + i:06x}: {b[i:i + 16].hex(' ')}")
