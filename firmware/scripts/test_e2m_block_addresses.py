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

print("\n".join(failures) if failures else "ALL PASS")
sys.exit(1 if failures else 0)
