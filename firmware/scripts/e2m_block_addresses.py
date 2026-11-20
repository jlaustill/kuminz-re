#!/usr/bin/env python3
"""Resolve e2m parameter records to CM848 addresses with the ECU's own parameter ID table.

The CM848 flash2 image carries the table that cm848_lookupParameterIdAddress (0x539768) searches: 6-byte records
[block id u16][address u32], big-endian, from 0x53be38 to 0x53ea6c. The block id is column 3 of an e2m record
(e.g. `Crank_Exit_Speed,RPM,105E,0012,...`), so a record's address is table[block] + column 4. The table returns
EEPROM addresses as 0x01000000 + EEPROM offset; the application reads those from the EEPROM RAM mirror at
0x3fd482 + EEPROM offset (the `_cal` region).

The live flash2 dump ends before the table does (1441 of its 1886 records are in the dump). A block that is not in
the dumped part prints as "not in the dumped table".

Found 2026-11-19 (PR #52): it reproduces every block base proved by offsets before it (105E 0x40a798, 1068 0x40a7c0,
10AA 0x40718e, 19B0-19B3, 1254 EEPROM 0x3b8, ...).

usage: e2m_block_addresses.py [--flash2 FILE] [--e2m FILE] [--globals FILE] BLOCK [BLOCK...]
       e2m_block_addresses.py --address 0xADDR     (which block / record covers an address)
"""
import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
CM848 = os.path.join(REPO, "firmware", "CM848_S90140.06_analysis")
DEFAULTS = {
    "flash2": os.path.join(CM848, "originals", "cm848_flash2_live.bin"),
    "e2m": os.path.join(REPO, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m"),
    "globals": os.path.join(CM848, "output", "global_variables.csv"),
}
TABLE_START, TABLE_END, FLASH2_BASE = 0x53be38, 0x53ea6c, 0x500000
EEPROM_BASE, EEPROM_MIRROR = 0x01000000, 0x3fd482


def parse_table(data):
    """Return {block id: address} from the flash2 image bytes (first record wins)."""
    table = {}
    start, end = TABLE_START - FLASH2_BASE, min(TABLE_END - FLASH2_BASE, len(data) - 5)
    for offset in range(start, end, 6):
        block, address = struct.unpack(">HI", data[offset:offset + 6])
        if block or address:
            table.setdefault(block, address)
    return table


def ram_address(address):
    """The address the application uses: EEPROM addresses map to the EEPROM RAM mirror."""
    if EEPROM_BASE <= address < EEPROM_BASE + 0x10000:
        return EEPROM_MIRROR + (address - EEPROM_BASE)
    return address


def parse_e2m(path):
    """Yield (name, unit, block, offset, description) for every e2m parameter record."""
    for line in open(path, errors="replace"):
        fields = line.rstrip("\r\n").split(",")
        if len(fields) < 4:
            continue
        try:
            block, offset = int(fields[2], 16), int(fields[3], 16)
        except ValueError:
            continue
        description = line.split(";", 1)[1].strip() if ";" in line else ""
        yield fields[0], fields[1], block, offset, description


def load_globals(path):
    rows = {}
    for line in open(path, errors="replace"):
        if line.startswith("0x"):
            address, name, typ = (line.split(",", 3) + ["", ""])[:3]
            rows[int(address, 16)] = (name, typ)
    return rows


def main(argv):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    for key, value in DEFAULTS.items():
        parser.add_argument("--" + key, default=value)
    parser.add_argument("--address", help="report the e2m record(s) whose resolved address is this one")
    parser.add_argument("blocks", nargs="*")
    args = parser.parse_args(argv)
    table = parse_table(open(args.flash2, "rb").read())
    rows = load_globals(args.globals)
    records = list(parse_e2m(args.e2m))
    wanted = {int(b, 16) for b in args.blocks}
    target = int(args.address, 16) if args.address else None
    for name, unit, block, offset, description in records:
        if target is None and block not in wanted:
            continue
        base = table.get(block)
        if base is None:
            if target is None:
                print(f"{block:04X} +{offset:04X} {name} [{unit}]: not in the dumped table")
            continue
        address = ram_address(base) + offset
        if target is not None and address != target:
            continue
        current, typ = rows.get(address, ("", ""))
        where = f"EEPROM 0x{base - EEPROM_BASE + offset:x} = " if EEPROM_BASE <= base < EEPROM_BASE + 0x10000 else ""
        print(f"{block:04X} +{offset:04X} {name} [{unit}] -> {where}0x{address:06x} "
              f"{current or '(no name)'} {typ or '(no row)'}; {description[:90]}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
