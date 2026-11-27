"""Read CM550 dump values at a declared width (read-only helper, round 93 batch D1 investigator, session 2).
RAM dump 0x800000-0x8091C1 (J90350.00.ram.bin) and extended RAM dump from 0x809242 (J90350.00.extended_ram.bin);
EEPROM dump (4 KB) for the mirror 0x803b0a + offset.
usage: ramval.py b|w|d|s:<len> 0xADDR [more pairs ...]      e.g. ramval.py w 0x80d674 b 0x80bad6 s:20 0x800010"""
import struct
import sys

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()


def get(addr, n):
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n], "ram"
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n], "extended"
    return None, "not dumped"


def main(args):
    i = 0
    while i + 1 < len(args):
        kind, addr = args[i], int(args[i + 1], 16)
        i += 2
        if kind == "b":
            data, src = get(addr, 1)
            print(f"0x{addr:06x} byte  = " + (f"{data[0]} (0x{data[0]:02x})" if data else "?") + f"  [{src}]")
        elif kind == "w":
            data, src = get(addr, 2)
            if data:
                v = struct.unpack(">H", data)[0]
                print(f"0x{addr:06x} word  = {v} (0x{v:04x})  [{src}]")
            else:
                print(f"0x{addr:06x} word  = ?  [{src}]")
        elif kind == "d":
            data, src = get(addr, 4)
            if data:
                v = struct.unpack(">I", data)[0]
                print(f"0x{addr:06x} dword = {v} (0x{v:08x})  [{src}]")
            else:
                print(f"0x{addr:06x} dword = ?  [{src}]")
        elif kind.startswith("s:"):
            n = int(kind[2:])
            data, src = get(addr, n)
            print(f"0x{addr:06x} bytes = " + (data.hex(" ") if data else "?") + f"  [{src}]")


if __name__ == "__main__":
    main(sys.argv[1:])
