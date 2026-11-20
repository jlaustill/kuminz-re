"""Read-only scratch helper: find big-endian 32-bit pointer values (and the 16-bit low halves in `addi` forms are NOT searched)
in the CM848 ROM / flash2 / eeprom images.  usage: find_pointer.py <originals dir> <0xaddress>..."""
import sys

root = sys.argv[1]
for name, base in (("cm848_rom.bin", 0), ("cm848_flash2_live.bin", 0x500000), ("cm848_eeprom.bin", 0x1000000)):
    data = open(f"{root}/{name}", "rb").read()
    for a in sys.argv[2:]:
        value = int(a, 16)
        needle = value.to_bytes(4, "big")
        pos = data.find(needle)
        found = []
        while pos != -1:
            found.append(hex(base + pos))
            pos = data.find(needle, pos + 1)
        print(name, a, found)
