"""Which P-code each 80B9 injector diagnostic class sets. cm848_evaluateInjectorDiagnosticFault reads, for injector row i,
the 10-byte row at <table> + 10 x i: +0 the injector's bit mask, +param_4 the fault number of the class (the calls pass 2 /
4 / 6 / 8 with the bits bytes named open circuit / short to battery / short to ground / fast decay). A fault number maps
to a P-code through the slot table at ROM 0x5985a and obd_dtc_code_table at ROM 0x5b57c.
usage: injector_fault_codes.py <cm848_rom.bin> <table address> <rows>"""
import sys

rom = open(sys.argv[1], "rb").read()
table, rows = int(sys.argv[2], 16), int(sys.argv[3])


def u16(address):
    return int.from_bytes(rom[address:address + 2], "big")


def pcode(fault):
    slot = u16(0x5985A + 2 * fault)
    return f"P{u16(0x5B57C + 2 * slot):04x}" if slot < 170 else f"slot{slot}"


CLASS = {2: "open circuit (old a)", 4: "named short to battery (old c)", 6: "named short to ground (old b)",
         8: "fast decay (old d)"}
for i in range(1, rows + 1):
    row = table + 10 * i
    parts = [f"mask 0x{u16(row):04x}"]
    for offset, what in CLASS.items():
        fault = u16(row + offset)
        parts.append(f"+{offset} {what}: fault {fault} = {pcode(fault)}")
    print(f"row {i}: " + "; ".join(parts))
