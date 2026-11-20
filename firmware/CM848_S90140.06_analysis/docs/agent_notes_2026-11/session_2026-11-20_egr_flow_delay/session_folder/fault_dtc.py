"""Fault bit -> OBD DTC: ROM 0x5985a[bit] (byte slot) -> obd_dtc_code_table (ROM 0x5b57c, BCD words).
Usage: fault_dtc.py <cm848_rom.bin> <fault bit>..."""
import struct
import sys

rom = open(sys.argv[1], "rb").read()
for arg in sys.argv[2:]:
    bit = int(arg, 0)
    slot = rom[0x5985a + bit]
    code = struct.unpack(">H", rom[0x5b57c + 2 * slot:0x5b57c + 2 * slot + 2])[0] if slot < 170 else None
    print(f"fault {bit}: slot {slot} -> " + (f"P{code:04X}" if code is not None else "no DTC slot"))
