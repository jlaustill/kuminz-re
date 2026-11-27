"""Round 94 (task #39): the CM550 EEPROM image is 0x148a bytes. mc68k_initializeSerialEepromDriverAndLoadMirror
(0x26854) loads EEPROM 0x0-0x1489 into RAM 0x803b0a-0x804f93 at start-up (move.l #0x804f94,d0 / subi.l #0x803b08,d0 /
addi.w #-2,d0), then keeps refreshing 0x0-0x64b. This patches the tools that assumed 4 KB or the 0x64c refresh:
- audit_cal_suffixes.py: the CM550 EEPROM and RAM image regions end at the image's end;
- e2m_block_addresses.py (+ test): CM550 EEPROM addresses map to RAM for the whole image;
- clip-core TClipPacket.h / kuminz-cli: --dump-eeprom and --dump-all read the whole image (the memory services read the
  RAM image, so a read past it would return RAM, not EEPROM).
Each old text must occur exactly once; idempotent. usage: patch_eeprom_window_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"


def patch(rel, pairs):
    path = os.path.join(repo, rel)
    text = open(path, newline="").read()
    E = "\r\n" if "\r\n" in text else "\n"
    for old, new in pairs:
        old, new = old.replace("\n", E), new.replace("\n", E)
        if new in text and old not in text:
            continue
        assert text.count(old) == 1, (rel, old[:70], text.count(old))
        text = text.replace(old, new)
    open(path, "w", newline="").write(text)
    print("patched", rel)


patch("firmware/scripts/audit_cal_suffixes.py", [
    ("    On CM550 the EEPROM RAM mirror is 0x803B0A-0x804155 (RAM = 0x803B0A + EEPROM offset; PR #53 round 73).",
     "    On CM550 the EEPROM RAM image is 0x803B0A-0x804F93 (RAM = 0x803B0A + EEPROM offset; the start-up load is 0x148a\n"
     "    bytes; PR #53 rounds 73 / 94)."),
    ('    ("EEPROM",        0x01000000,   0x01001000,   True,    "eeprom"),',
     '    ("EEPROM",        0x01000000,   0x0100148A,   True,    "eeprom"),'),
    ("    # RAM mirror of EEPROM 0x0-0x64b (RAM = 0x803B0A + EEPROM offset): the memory services translate by - 0x7FC4F6\n"
     "    # and 0x11a74 stores it back in 16-byte chunks (the counterpart of cm848_commitEepromMirrorToEeprom in CM848); PR #53 round 73.\n",
     "    # RAM image of EEPROM 0x0-0x1489 (RAM = 0x803B0A + EEPROM offset): mc68k_initializeSerialEepromDriverAndLoadMirror\n"
     "    # (0x26854) loads 0x148a bytes at start-up, then refreshes 0x0-0x64b; the memory services translate by - 0x7FC4F6\n"
     "    # and 0x11a74 stores 0x0-0x64b back in 16-byte chunks (the counterpart of cm848_commitEepromMirrorToEeprom in\n"
     f"    # CM848); PR #53 rounds 73 / 94 (the window was 0x803B0A-0x804155, the refresh, until {R}).\n"),
    ('    ("EEPROM_SHADOW", 0x00803B0A,   0x00804156,   True,    "eeprom"),',
     '    ("EEPROM_SHADOW", 0x00803B0A,   0x00804F94,   True,    "eeprom"),'),
])
patch("firmware/scripts/e2m_block_addresses.py", [
    ("CM550_EEPROM_LENGTH = 0x1000                                 # the EEPROM address space the memory services image in RAM",
     "CM550_EEPROM_LENGTH = 0x148A                                 # the EEPROM image: the start-up load (0x26854)"),
    ('    """CM550 images its whole EEPROM address space in RAM: RAM = 0x803B0A + EEPROM offset for offsets 0x0-0xFFF. The\n'
     "    memory services translate any EEPROM address with no upper bound (0x224b6; the tool write path 0x2d30a), and the\n",
     '    """CM550 images its EEPROM in RAM: RAM = 0x803B0A + EEPROM offset for offsets 0x0-0x1489, the start-up load of\n'
     "    mc68k_initializeSerialEepromDriverAndLoadMirror (0x26854: 0x148a bytes, then a refresh of 0x0-0x64B). The\n"
     "    memory services translate any EEPROM address with no upper bound (0x224b6; the tool write path 0x2d30a), and the\n"),
    ("    (cm550_commitEepromMirrorToEeprom); the _cal window of audit_cal_suffixes.py is a separate question (PR #53\n"
     '    rounds 73 / 94)."""',
     "    (cm550_commitEepromMirrorToEeprom); the _cal window of audit_cal_suffixes.py is the whole image (PR #53\n"
     '    rounds 73 / 94)."""'),
    ("    if EEPROM_BASE <= address < EEPROM_BASE + 0x1000:\n        return \"EEPROM\"",
     "    if EEPROM_BASE <= address < EEPROM_BASE + CM550_EEPROM_LENGTH:\n        return \"EEPROM\""),
])
patch("firmware/scripts/test_e2m_block_addresses.py", [
    ('check("cm550 past the 4 KB EEPROM", m.cm550_ram_address(0x01001000), 0x01001000)',
     'check("cm550 EEPROM above 4 KB (the image is 0x148a bytes)", m.cm550_ram_address(0x01001000), 0x804B0A)\n'
     'check("cm550 last byte of the EEPROM image", m.cm550_ram_address(0x01001489), 0x804F93)\n'
     'check("cm550 past the EEPROM image", m.cm550_ram_address(0x0100148A), 0x0100148A)'),
])
patch("clip-core/include/clip/types/TClipPacket.h", [
    (" * @brief CM550 EEPROM region (calibration data).\n * Contains calibration parameters. 4KB total.\n",
     " * @brief CM550 EEPROM region (calibration data).\n"
     " * The EEPROM image J90350.00 loads into RAM at start-up: 0x148A bytes\n"
     " * (mc68k_initializeSerialEepromDriverAndLoadMirror, 0x26854). The memory services read that RAM image\n"
     " * (RAM = 0x803B0A + offset), so a read past it would return RAM, not EEPROM.\n"),
    ("constexpr uint32_t CM550_EEPROM_END = 0x01000FFF;", "constexpr uint32_t CM550_EEPROM_END = 0x01001489;"),
    ("constexpr uint32_t CM550_EEPROM_SIZE = 0x00001000;  // 4KB", "constexpr uint32_t CM550_EEPROM_SIZE = 0x0000148A;  // 5,258 bytes"),
])
patch("kuminz-cli/src/main.cpp", [
    ('    std::cerr << "  --dump-eeprom [file]        Dump EEPROM (4KB) to file\\n";',
     '    std::cerr << "  --dump-eeprom [file]        Dump the EEPROM image (0x148A bytes) to file\\n";'),
])
