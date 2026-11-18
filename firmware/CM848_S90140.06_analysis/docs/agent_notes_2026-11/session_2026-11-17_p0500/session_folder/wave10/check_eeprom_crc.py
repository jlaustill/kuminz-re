"""Check the wave-10 claim that EEPROM 0x118-0x171 is guarded by a CRC16 stored at EEPROM 0x482.
For each EEPROM dump: the bytes of 0x118-0x171 that differ from the first dump, the stored word at 0x482, and the
CRC16 of the block recomputed with the 256-word table at ROM 0x5842e (seed 0), both bit orders.
Usage: check_eeprom_crc.py <cm848_rom.bin> <eeprom.bin>..."""
import struct
import sys

rom = open(sys.argv[1], "rb").read()
table = [struct.unpack(">H", rom[0x5842e + 2 * i:0x5842e + 2 * i + 2])[0] for i in range(256)]


def crc_msb_first(data):
    crc = 0
    for b in data:
        crc = ((crc << 8) & 0xffff) ^ table[((crc >> 8) ^ b) & 0xff]
    return crc


def crc_lsb_first(data):
    crc = 0
    for b in data:
        crc = (crc >> 8) ^ table[(crc ^ b) & 0xff]
    return crc


dumps = [(path, open(path, "rb").read()) for path in sys.argv[2:]]
first = dumps[0][1]
for path, d in dumps:
    block = d[0x118:0x172]
    diffs = [(hex(0x118 + i), first[0x118 + i], b) for i, b in enumerate(block) if first[0x118 + i] != b]
    stored = struct.unpack(">H", d[0x482:0x484])[0]
    print(f"{path.split('/')[-1]}: stored 0x482 = 0x{stored:04x}  msb-first 0x{crc_msb_first(block):04x}"
          f"  lsb-first 0x{crc_lsb_first(block):04x}  block diffs vs first: {diffs}")
