"""Skeptic: read CM550 dump values at the declared width.
RAM 0x800000-0x8091c1 -> ram.bin[addr - 0x800000]; extended RAM (addr >= 0x8092c2) -> extended_ram.bin[addr - 0x809242];
EEPROM 0x1000000 + o -> eeprom.bin[o]; the EEPROM RAM mirror is 0x803b0a + o.
usage: dumps.py <firmware dir> <addr hex>[:<count>[:<width 1|2|4>]] ..."""
import sys

d = sys.argv[1]
ram = open(d + "/J90350.00.ram.bin", "rb").read()
ext = open(d + "/J90350.00.extended_ram.bin", "rb").read()
eep = open(d + "/J90350.00.eeprom.bin", "rb").read()
rom = open(d + "/J90350.00.rom.bin", "rb").read()


def read(addr, width):
    if addr < 0x40000:
        return int.from_bytes(rom[addr:addr + width], "big"), "rom"
    if 0x800000 <= addr < 0x8091c2:
        o = addr - 0x800000
        return int.from_bytes(ram[o:o + width], "big"), "ram"
    if 0x8092c2 <= addr <= 0x80ffff:
        o = addr - 0x809242
        return int.from_bytes(ext[o:o + width], "big"), "ext"
    if 0x8091c2 <= addr < 0x8092c2:
        return None, "ext-gap"
    if 0x1000000 <= addr < 0x1001000:
        o = addr - 0x1000000
        return int.from_bytes(eep[o:o + width], "big"), "eeprom"
    return None, "?"


for spec in sys.argv[2:]:
    parts = spec.split(":")
    addr = int(parts[0], 16)
    count = int(parts[1]) if len(parts) > 1 else 1
    width = int(parts[2]) if len(parts) > 2 else 2
    for i in range(count):
        a = addr + i * width
        v, src = read(a, width)
        extra = ""
        if 0x803b0a <= a <= 0x804155 + 1 and src == "ram":
            e = a - 0x803b0a
            ev = int.from_bytes(eep[e:e + width], "big")
            extra = f"  eeprom[0x{e:x}]=0x{ev:0{width * 2}x}{'' if ev == v else '  (DIFFERS)'}"
        if v is None:
            print(f"0x{a:06x} {src}")
        else:
            print(f"0x{a:06x} {src} 0x{v:0{width * 2}x} ({v}){extra}")
