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

CM550 (`--firmware cm550`, PR #53 round 90): J90350.00's ROM holds `parameter_id_table` (0x35224), which
cm550_lookupParameterIdAddress (0x10e16) indexes by id range: index = id for 0x0000-0x002E, id - 0xFD1 for
0x1000-0x1478, id - 0x7B58 for 0x8000-0x8265 (1806 entries of 8 bytes: the address while RAM refresh is disabled,
then the address otherwise - equal in every entry). An address of 0 is no entry. EEPROM entries (0x01000000 +
offset, 0x0-0xFFF) map to CM550's RAM image of the EEPROM at 0x803B0A + offset. `e2m-analysis/originals/v64t6_s.e2m` carries
J90350.00's block layout (round 89: it agrees with blocks 1003 / 1004). `--write-table CSV` writes the table with the
current global at each address (EEPROM entries: at the mirror) and the e2m records with storage there (types N / S /
B / T / X / Y / Z; not block 0, whose system records all say offset 0) - CM550's `output/parameter_id_lookup_table.csv`.

usage: e2m_block_addresses.py [--firmware cm848|cm550] [--flash2 FILE | --rom FILE] [--e2m FILE] [--globals FILE]
                              BLOCK [BLOCK...]
       e2m_block_addresses.py [--firmware ...] --address 0xADDR     (which block / record covers an address)
       e2m_block_addresses.py --firmware cm550 --write-table CSV   (the decoded table, with names)
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
CM550 = os.path.join(REPO, "firmware", "CM550_J90350.00_analysis")
CM550_DEFAULTS = {
    "rom": os.path.join(CM550, "firmware", "J90350.00.rom.bin"),
    "e2m": os.path.join(REPO, "e2m-analysis", "originals", "v64t6_s.e2m"),
    "globals": os.path.join(CM550, "output", "global_variables.csv"),
    "structures": os.path.join(CM550, "output", "structure_definitions.csv"),
}
CM550_TABLE = 0x35224
# (first id, last id, index of the first id) - cm550_lookupParameterIdAddress's three ranges
CM550_RANGES = ((0x0000, 0x002E, 0), (0x1000, 0x1478, 47), (0x8000, 0x8265, 47 + 1145))


def cm550_table_index(pid):
    """The parameter_id_table index cm550_lookupParameterIdAddress reads for an id, or None outside its ranges."""
    for first, last, index in CM550_RANGES:
        if first <= pid <= last:
            return index + pid - first
    return None


def parse_cm550_table(rom):
    """Return {id: address} from the J90350.00 ROM image (the address used with RAM refresh enabled; 0 = no entry).
    Raises ValueError when an entry's two addresses differ - the table would then need both."""
    table = {}
    for first, last, index in CM550_RANGES:
        for pid in range(first, last + 1):
            offset = CM550_TABLE + 8 * (index + pid - first)
            if offset + 8 > len(rom):
                raise ValueError(f"the image ends before entry 0x{pid:04x}")
            disabled, enabled = struct.unpack(">II", rom[offset:offset + 8])
            if disabled != enabled:
                raise ValueError(f"entry 0x{pid:04x} has two addresses: 0x{disabled:x} / 0x{enabled:x}")
            if enabled:
                table[pid] = enabled
    return table


CM550_EEPROM_MIRROR, CM550_MIRROR_LENGTH = 0x803B0A, 0x64C   # 0x64C: the part the bulk commit (service 21) writes back
CM550_EEPROM_LENGTH = 0x148A                                 # the EEPROM image: the start-up load (0x26854)


def cm550_ram_address(address):
    """CM550 images its EEPROM in RAM: RAM = 0x803B0A + EEPROM offset for offsets 0x0-0x1489, the start-up load of
    mc68k_initializeSerialEepromDriverAndLoadMirror (0x26854: 0x148a bytes, then a refresh of 0x0-0x64B). The
    memory services translate any EEPROM address with no upper bound (0x224b6; the tool write path 0x2d30a), and the
    code uses the RAM images of the parameter ID table's entries above 0x64C (e2m 107F DGFUSITB at EEPROM 0x760 =
    RAM 0x80426a, the fault freeze frames). Only 0x0-0x64B is written back by the bulk commit
    (cm550_commitEepromMirrorToEeprom); the _cal window of audit_cal_suffixes.py is the whole image (PR #53
    rounds 73 / 94)."""
    if EEPROM_BASE <= address < EEPROM_BASE + CM550_EEPROM_LENGTH:
        return CM550_EEPROM_MIRROR + (address - EEPROM_BASE)
    return address


def cm550_region(address):
    """ROM below the RAM base (the chip's flash runs past the dumped 256 KB: entries point at 0x611a0 ...)."""
    if address < 0x800000:
        return "ROM"
    if EEPROM_BASE <= address < EEPROM_BASE + CM550_EEPROM_LENGTH:
        return "EEPROM"
    return "RAM"


def load_structures(path):
    """{struct name: [(field, offset, size)]} from a structure_definitions.csv (fields in order; markers skipped)."""
    import csv
    structs = {}
    for row in csv.reader(open(path, newline="", errors="replace")):
        if len(row) < 5 or row[0].startswith("#") or row[0] == "struct_name" or not row[2]:
            continue
        try:
            size = int(row[4])
        except ValueError:
            continue
        fields = structs.setdefault(row[0], [])
        fields.append((row[2], sum(f[2] for f in fields), size))
    return structs


SCALAR_SIZES = {"byte": 1, "char": 1, "bool": 1, "word": 2, "i16": 2, "short": 2, "ushort": 2, "dword": 4, "i32": 4,
                "uint": 4, "int": 4, "float": 4, "pointer": 4}


def type_size(typ, structs):
    import re
    typ = typ.strip()
    m = re.match(r"^(.+?)\s*\[(\d+)\]$", typ)
    if m:
        return type_size(m.group(1), structs) * int(m.group(2))
    if typ.endswith("*"):
        return 4
    if typ in structs:
        return sum(f[2] for f in structs[typ])
    return SCALAR_SIZES.get(typ, 0)


def symbol_at(address, rows, structs):
    """The current name at an address: a row's name, or `<row>.<field>` / `<row>[i]` / `<row>+n` inside a typed row."""
    import re
    if address in rows and rows[address][0]:
        return rows[address][0]
    for base in sorted((a for a in rows if address - 4096 < a < address), reverse=True):
        name, typ = rows[base][0], rows[base][1].strip()
        size = type_size(typ, structs)
        if not (name and base + size > address):
            continue
        offset = address - base
        m = re.match(r"^(.+?)\s*\[(\d+)\]$", typ)
        element = m.group(1) if m else typ
        element_size = type_size(element, structs) if m else size
        prefix, rest = name, offset
        if m and element_size:
            prefix, rest = f"{name}[{offset // element_size}]", offset % element_size
        for field, field_offset, field_size in structs.get(element, []):
            if field_offset == rest:
                return f"{prefix}.{field}"
            if field_offset < rest < field_offset + field_size:
                return f"{prefix}.{field}+{rest - field_offset}"
        return prefix if rest == 0 else f"{prefix}+{rest}"
    return ""


def write_cm550_table(path, table, rows, structs, records):
    """The decoded table as CSV: id, address, region, the current name there and the e2m records at that address."""
    at = {}
    for name, unit, block, offset, description in records:
        if block and block in table:
            at.setdefault(table[block] + offset, []).append(name)
    eol = "\r\n" if os.path.exists(path) and b"\r\n" in open(path, "rb").read(4096) else "\n"
    with open(path, "w", newline="") as fh:
        fh.write("param_id,param_id_hex,address,address_hex,region,firmware_variable,e2m_parameter" + eol)
        for pid in sorted(table):
            address = table[pid]
            names = " / ".join(dict.fromkeys(at.get(address, [])))
            fh.write(f"{pid},0x{pid:04X},{address},0x{address:08X},{cm550_region(address)},"
                     f"{symbol_at(cm550_ram_address(address), rows, structs)},{names}" + eol)


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


STORAGE_TYPES = {"N", "S", "B", "T", "X", "Y", "Z"}  # not G (group header), A (area) or C (command): no storage


def parse_e2m_storage(path):
    """parse_e2m for the records that have storage (column 6 type N / S / B / T / X / Y / Z)."""
    for line in open(path, errors="replace"):
        fields = line.rstrip("\r\n").split(",")
        if len(fields) < 6 or fields[5].strip() not in STORAGE_TYPES:
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
    parser.add_argument("--firmware", choices=("cm848", "cm550"), default="cm848")
    parser.add_argument("--flash2", default=None, help="CM848: the flash2 image")
    parser.add_argument("--rom", default=None, help="CM550: the ROM image")
    parser.add_argument("--e2m", default=None)
    parser.add_argument("--globals", default=None)
    parser.add_argument("--address", help="report the e2m record(s) whose resolved address is this one")
    parser.add_argument("--write-table", help="CM550: write the decoded table with the current names to this CSV")
    parser.add_argument("blocks", nargs="*")
    args = parser.parse_args(argv)
    if args.firmware == "cm550":
        table = parse_cm550_table(open(args.rom or CM550_DEFAULTS["rom"], "rb").read())
        e2m_path, globals_path = args.e2m or CM550_DEFAULTS["e2m"], args.globals or CM550_DEFAULTS["globals"]
        to_address = cm550_ram_address
    else:
        table = parse_table(open(args.flash2 or DEFAULTS["flash2"], "rb").read())
        e2m_path, globals_path = args.e2m or DEFAULTS["e2m"], args.globals or DEFAULTS["globals"]
        to_address = ram_address
    rows = load_globals(globals_path)
    records = list(parse_e2m(e2m_path))
    if args.write_table:
        if args.firmware != "cm550":
            parser.error("--write-table is for --firmware cm550")
        write_cm550_table(args.write_table, table, rows, load_structures(CM550_DEFAULTS["structures"]),
                          list(parse_e2m_storage(e2m_path)))
        return 0
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
        address = to_address(base) + offset
        if target is not None and address != target:
            continue
        current, typ = rows.get(address, ("", ""))
        where = (f"EEPROM 0x{base - EEPROM_BASE + offset:x} = "
                 if EEPROM_BASE <= base < EEPROM_BASE + 0x10000 and args.firmware == "cm848" else "")
        print(f"{block:04X} +{offset:04X} {name} [{unit}] -> {where}0x{address:06x} "
              f"{current or '(no name)'} {typ or '(no row)'}; {description[:90]}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
