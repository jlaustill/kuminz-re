"""Round 94 (task #39): the docs that state CM550's EEPROM as 4 KB at 0x1000000-0x1000FFF. The EEPROM image is
0x148A bytes: mc68k_initializeSerialEepromDriverAndLoadMirror (0x26854) loads EEPROM 0x0-0x1489 into RAM
0x803B0A-0x804F93 at start-up; the 4 KB dump file holds its first 4 KB and the RAM dump the rest. CLAUDE.md lines are
changed only where they state the old size as fact (each reported in full). Each old text must occur exactly once;
idempotent; keeps line endings. usage: patch_eeprom_docs_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


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


patch("CLAUDE.md", [
    ("| EEPROM | 0x01000000 | 4KB |", "| EEPROM | 0x01000000 | 0x148A bytes (CM550's EEPROM image) |"),
    ("./kuminz-cli can0 --dump-eeprom [file]        # Dump 4KB EEPROM",
     "./kuminz-cli can0 --dump-eeprom [file]        # Dump the 0x148A-byte EEPROM image"),
])
patch("firmware/CLAUDE.md", [
    ("- **EEPROM:** 4KB at 0x01000000",
     "- **EEPROM:** a 0x148A-byte image at 0x01000000 (PR #53 round 94): `mc68k_initializeSerialEepromDriverAndLoadMirror` loads "
     "EEPROM 0x0-0x1489 into RAM 0x803B0A-0x804F93 at start-up, then keeps refreshing 0x0-0x64B. Every value in that RAM is "
     "EEPROM-backed (`_cal`). `J90350.00.eeprom.bin` holds the first 4 KB; the RAM dump has the rest"),
])
patch("firmware/CM550_J90350.00_analysis/README.md", [
    ("| `firmware/J90350.00.eeprom.bin` | 4KB | EEPROM calibration data |",
     "| `firmware/J90350.00.eeprom.bin` | 4KB | EEPROM calibration data: the first 4 KB of the 0x148A-byte EEPROM image (the RAM dump holds the rest at 0x804B0A-0x804F93) |"),
    ("| EEPROM | 0x1000000-0x1000FFF | 4KB | rw- | Extracted |",
     "| EEPROM | 0x1000000-0x1001489 | 0x148A (5 KB) | rw- | 0x1000000-0x1000FFF extracted |"),
])
patch("firmware/CM550_J90350.00_analysis/docs/memory_map.md", [
    ("| **EEPROM** | 0x1000000-0x1000FFF | 4KB | Extracted | Module ID, calibration config |",
     "| **EEPROM** | 0x1000000-0x1001489 | 0x148A (5 KB) | 0x1000000-0x1000FFF extracted | Module ID, calibration config; loaded into RAM 0x803B0A-0x804F93 at start-up |"),
    ("           |     EEPROM      | 4KB (Configuration)\n0x01000FFF +-----------------+",
     "           |     EEPROM      | 0x148A bytes (Configuration)\n0x01001489 +-----------------+"),
])
