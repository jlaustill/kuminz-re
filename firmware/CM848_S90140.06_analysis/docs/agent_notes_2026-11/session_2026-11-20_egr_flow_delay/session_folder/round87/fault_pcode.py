"""The OBD P-code of CM848 fault numbers: fault n -> slot = ROM word at 0x5985a + 2n -> obd_dtc_code_table
(0x5b57c) word at slot (a slot of 170 or more has no DTC). Same mapping as the 2026-11-17 fault_setters.py.
usage: fault_pcode.py <cm848_rom.bin> <fault>..."""
import struct
import sys

rom = open(sys.argv[1], "rb").read()


def u16(address):
    return struct.unpack(">H", rom[address:address + 2])[0]


for fault in map(int, sys.argv[2:]):
    slot = u16(0x5985a + 2 * fault)
    code = f"P{u16(0x5b57c + 2 * slot):04x}" if slot < 170 else "no DTC slot"
    print(f"fault {fault}: word {fault // 16} bit {fault % 16} (mask 0x{1 << fault % 16:04x}), slot {slot}, {code}")
