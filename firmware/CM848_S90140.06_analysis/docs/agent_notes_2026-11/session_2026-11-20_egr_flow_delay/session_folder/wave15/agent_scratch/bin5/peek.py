"""Read values from the CM848 dumps at their declared width (big-endian).
usage: peek.py <0xADDR> [<width 1|2|4> [<count>]]
Address map (as lookup_tables.py / e2m_name_audit.py): < 0x70000 ROM image; 0x3f9800.. ROM->RAM low mirror;
0x3fa000.. RAM dump (cm848_ram.bin, which misses 0x40c200-0x40c27f); 0x500000.. flash2 live dump."""
import os
import sys

ORIG = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"


def load(name):
    with open(os.path.join(ORIG, name), "rb") as f:
        return f.read()


rom, ram, flash2, eeprom = load("cm848_rom.bin"), load("cm848_ram.bin"), load("cm848_flash2_live.bin"), load("cm848_eeprom.bin")


def fetch(address, n):
    if address < 0x70000:
        return rom[address:address + n], "rom"
    if 0x3F9800 <= address < 0x3FA000:
        base = 0x3C30 + address - 0x3F9800
        return rom[base:base + n], "rom-mirror"
    if 0x3FA000 <= address < 0x440000:
        if 0x40C200 <= address < 0x40C280:
            return b"", "dump gap"
        base = address - 0x3FA000
        return ram[base:base + n], "ram"
    if 0x500000 <= address < 0x540000:
        return flash2[address - 0x500000:address - 0x500000 + n], "flash2"
    return b"", "unmapped"


address = int(sys.argv[1], 16)
width = int(sys.argv[2]) if len(sys.argv) > 2 else 2
count = int(sys.argv[3]) if len(sys.argv) > 3 else 1
for k in range(count):
    a = address + k * width
    data, where = fetch(a, width)
    if len(data) < width:
        print(f"0x{a:08x} {where}: no data")
        continue
    u = int.from_bytes(data, "big")
    s = int.from_bytes(data, "big", signed=True)
    print(f"0x{a:08x} ({where}) {data.hex()}  unsigned {u}  signed {s}  /8 = {u / 8:g}")
