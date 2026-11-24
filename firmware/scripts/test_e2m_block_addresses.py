#!/usr/bin/env python3
"""Tests for e2m_block_addresses.py: the parameter ID table parse, the EEPROM mirror translation, and block bases
that were proved independently (by e2m offsets agreeing with the code) before the table was found."""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import e2m_block_addresses as m  # noqa: E402

failures = []


def check(label, got, expected):
    if got != expected:
        failures.append(f"{label}: got {got!r}, expected {expected!r}")


# a synthetic image: two records, then an all-zero slot, then a duplicate block id (the first one wins)
image = bytearray(m.TABLE_START - m.FLASH2_BASE)
image += struct.pack(">HI", 0x105E, 0x40A798) + struct.pack(">HI", 0x1254, 0x010003B8)
image += bytes(6) + struct.pack(">HI", 0x105E, 0x123456)
table = m.parse_table(bytes(image))
check("synthetic table", table, {0x105E: 0x40A798, 0x1254: 0x010003B8})
check("EEPROM mirror", m.ram_address(0x010003B8), 0x3FD83A)
check("RAM passes through", m.ram_address(0x40A798), 0x40A798)
check("a truncated record is not read", m.parse_table(bytes(image[:-3])), {0x105E: 0x40A798, 0x1254: 0x010003B8})

# the real dump, when it is present
if os.path.exists(m.DEFAULTS["flash2"]):
    real = m.parse_table(open(m.DEFAULTS["flash2"], "rb").read())
    for block, expected in [(0x105E, 0x40A798), (0x1068, 0x40A7C0), (0x10AA, 0x40718E), (0x19B0, 0x40656E),
                            (0x19B3, 0x40A5F4), (0x1254, 0x010003B8), (0x1180, 0x010000A6)]:
        check(f"real block {block:04X}", real.get(block), expected)
    check("real Crank_Exit_Speed_Switch", m.ram_address(real[0x1254]) + 0x38, 0x3FD872)

# CM550 (PR #53 round 90): cm550_lookupParameterIdAddress's three id ranges over 1806 entries
for pid, expected in [(0x0000, 0), (0x002E, 46), (0x002F, None), (0x0FFF, None), (0x1000, 47), (0x1478, 1191),
                      (0x1479, None), (0x7FFF, None), (0x8000, 1192), (0x8265, 1805), (0x8266, None)]:
    check(f"cm550 index 0x{pid:04X}", m.cm550_table_index(pid), expected)
rom = bytearray(m.CM550_TABLE + 8 * 1806)
for pid, address in [(0x0001, 0x0100000C), (0x1003, 0x806AE2), (0x8008, 0x806DA2)]:
    off = m.CM550_TABLE + 8 * m.cm550_table_index(pid)
    rom[off:off + 8] = struct.pack(">II", address, address)
check("cm550 synthetic table", m.parse_cm550_table(bytes(rom)), {0x0001: 0x0100000C, 0x1003: 0x806AE2, 0x8008: 0x806DA2})
off = m.CM550_TABLE + 8 * m.cm550_table_index(0x1004)
rom[off:off + 8] = struct.pack(">II", 0x80A2AA, 0x80A2AC)
try:
    m.parse_cm550_table(bytes(rom))
    failures.append("cm550: an entry with two different addresses was accepted")
except ValueError:
    pass
check("cm550 EEPROM mirror", m.cm550_ram_address(0x0100003A), 0x803B44)
check("cm550 EEPROM past the mirror", m.cm550_ram_address(0x01000720), 0x01000720)
check("cm550 RAM passes through", m.cm550_ram_address(0x806AE2), 0x806AE2)
check("cm550 ROM past the dump", m.cm550_region(0x611A0), "ROM")
if os.path.exists(m.CM550_DEFAULTS["rom"]):
    real = m.parse_cm550_table(open(m.CM550_DEFAULTS["rom"], "rb").read())
    check("cm550 real entries", len(real), 723)
    for pid, expected in [(0x000E, 0x80BCCE), (0x000F, 0x80654C), (0x001B, 0x80A38E), (0x1000, 0x0100008E),
                          (0x1003, 0x806AE2), (0x1004, 0x80A2AA), (0x8008, 0x806DA2)]:
        check(f"cm550 real 0x{pid:04X}", real.get(pid), expected)
    # the committed table CSV must be what --write-table writes now (a rename at a table address needs a rewrite)
    committed = os.path.join(m.CM550, "output", "parameter_id_lookup_table.csv")
    if os.path.exists(m.CM550_DEFAULTS["e2m"]) and os.path.exists(committed):
        import tempfile
        with tempfile.TemporaryDirectory() as tmp:
            fresh = os.path.join(tmp, "table.csv")
            m.write_cm550_table(fresh, real, m.load_globals(m.CM550_DEFAULTS["globals"]),
                                m.load_structures(m.CM550_DEFAULTS["structures"]),
                                list(m.parse_e2m_storage(m.CM550_DEFAULTS["e2m"])))
            ours = open(fresh, newline="").read().replace("\r\n", "\n")
            theirs = open(committed, newline="").read().replace("\r\n", "\n")
            if ours != theirs:
                failures.append("cm550: output/parameter_id_lookup_table.csv is stale - run "
                                "e2m_block_addresses.py --firmware cm550 --write-table <it>")

print("\n".join(failures) if failures else "ALL PASS")
sys.exit(1 if failures else 0)
