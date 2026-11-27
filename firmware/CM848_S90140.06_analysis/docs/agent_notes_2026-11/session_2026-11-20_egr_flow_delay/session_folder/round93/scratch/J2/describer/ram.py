"""Describer J2 (read-only): hex dump of CM550 RAM cells from the RAM dump (address - 0x800000) or the extended RAM
dump (address - 0x809242), and the EEPROM image comparison.
usage: ram.py <0xADDR> <length> [...]   |   ram.py --eeprom-compare"""
import os
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware"
ram = open(os.path.join(FW, "J90350.00.ram.bin"), "rb").read()
ext = open(os.path.join(FW, "J90350.00.extended_ram.bin"), "rb").read()


def read(addr, n):
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    return None


if sys.argv[1] == "--eeprom-compare":
    ee = open(os.path.join(FW, "J90350.00.eeprom.bin"), "rb").read()
    print("eeprom length", len(ee), "ram length", len(ram), "extended ram length", len(ext))
    base = 0x803b0a
    mirror = read(base, len(ee))
    if mirror is None:
        print("RAM range not in dump")
    else:
        diffs = [i for i in range(len(ee)) if ee[i] != mirror[i]]
        print("differing bytes:", len(diffs), "first", [hex(d) for d in diffs[:20]])
        # longest equal run from 0
        run = 0
        for i in range(len(ee)):
            if ee[i] != mirror[i]:
                break
            run += 1
        print("equal from offset 0 for", hex(run), "bytes")
else:
    args = sys.argv[1:]
    for i in range(0, len(args), 2):
        a = int(args[i], 16)
        n = int(args[i + 1], 0)
        b = read(a, n)
        print(f"0x{a:x}:", b.hex(" ") if b is not None else "(not in a dump)")
