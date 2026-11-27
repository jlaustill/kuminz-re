"""Round 94 (tooling + one comment): CM550's EEPROM address space is imaged in RAM for its whole 4 KB, not only for the
0x64C bytes the bulk commit writes back.
- e2m_block_addresses.py: cm550_ram_address translates every EEPROM address 0x01000000-0x01000FFF to 0x803B0A + offset.
  Evidence: the memory services translate any address >= 0x01000000 with no upper bound (0x224b6: cmpa.l #0x1000000 /
  suba.l #0x1000000 / adda.l #0x803b0a; the tool write path 0x2d30a does the same before the EEPROM write queue);
  12 parameter ID table entries point at EEPROM 0x64E-0xF10 and the code uses their RAM images, e.g. e2m 107F +0
  DGFUSITB ('SNAPSHOT_TABLE', 1920 bytes) at EEPROM 0x760 = RAM 0x80426a = the 40 x 48-byte fault freeze frames.
  CM550_MIRROR_LENGTH (0x64C) stays: the part the bulk commit (service 21, cm550_commitEepromMirrorToEeprom) writes.
- test_e2m_block_addresses.py: the test that pinned 0x01000720 as untranslated now expects its RAM image.
- CM550 global_variables.csv: the fault_freeze_frame_entries comment said 'No e2m record' and 'outside CM550's mirror,
  so no _cal'; it now names DGFUSITB and leaves _cal to the open question (is RAM above 0x804155 reloaded from EEPROM?).
Idempotent. usage: patch_eeprom_image_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:60], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T = "firmware/scripts/e2m_block_addresses.py"
edit(T, "CM550_EEPROM_MIRROR, CM550_MIRROR_LENGTH = 0x803B0A, 0x64C\n",
     "CM550_EEPROM_MIRROR, CM550_MIRROR_LENGTH = 0x803B0A, 0x64C   # 0x64C: the part the bulk commit (service 21) writes back\n"
     "CM550_EEPROM_LENGTH = 0x1000                                 # the EEPROM address space the memory services image in RAM\n")
edit(T, '''    """CM550's application reads EEPROM from its RAM mirror 0x803B0A-0x804155 (RAM = 0x803B0A + EEPROM offset;
    audit_cal_suffixes.py, PR #53 round 73)."""
    if EEPROM_BASE <= address < EEPROM_BASE + CM550_MIRROR_LENGTH:''',
     '''    """CM550 images its whole EEPROM address space in RAM: RAM = 0x803B0A + EEPROM offset for offsets 0x0-0xFFF. The
    memory services translate any EEPROM address with no upper bound (0x224b6; the tool write path 0x2d30a), and the
    code uses the RAM images of the parameter ID table's entries above 0x64C (e2m 107F DGFUSITB at EEPROM 0x760 =
    RAM 0x80426a, the fault freeze frames). Only 0x0-0x64B is written back by the bulk commit
    (cm550_commitEepromMirrorToEeprom); the _cal window of audit_cal_suffixes.py is a separate question (PR #53
    rounds 73 / 94)."""
    if EEPROM_BASE <= address < EEPROM_BASE + CM550_EEPROM_LENGTH:''')
edit(T, "offset) map to CM550's EEPROM RAM mirror at 0x803B0A + offset.",
     "offset, 0x0-0xFFF) map to CM550's RAM image of the EEPROM at 0x803B0A + offset.")
X = "firmware/scripts/test_e2m_block_addresses.py"
edit(X, 'check("cm550 EEPROM past the mirror", m.cm550_ram_address(0x01000720), 0x01000720)',
     'check("cm550 EEPROM past the committed part", m.cm550_ram_address(0x01000720), 0x80422A)\n'
     'check("cm550 freeze frame block (e2m 107F DGFUSITB)", m.cm550_ram_address(0x01000760), 0x80426A)\n'
     'check("cm550 past the 4 KB EEPROM", m.cm550_ram_address(0x01001000), 0x01001000)')
G = "firmware/CM550_J90350.00_analysis/output/global_variables.csv"
edit(G, "sent by cm550_j1939HandlePgn65229Dm4FreezeFrame (73 bytes per used entry, both halves). No e2m record. The counterpart of",
     "sent by cm550_j1939HandlePgn65229Dm4FreezeFrame (73 bytes per used entry, both halves). e2m 107F +0 DGFUSITB "
     "'SNAPSHOT_TABLE.H NON OBD_MODULE' (1920 bytes = 40 x 48) at EEPROM 0x760, imaged here (PR #53 round 94: the round 93 "
     "comment said there was no record). The counterpart of")
t = open(os.path.join(repo, G), newline="").read()
old = "in its EEPROM mirror); this one is outside CM550's mirror, so no _cal"
new = ("in its EEPROM mirror). No _cal for now: the bulk commit writes back only 0x803b0a-0x804155, and whether RAM above it "
       "is reloaded from the EEPROM at start-up is not proved (PR #53 round 94)")
if old in t:
    edit(G, old, new)
else:
    assert new in t or "outside CM550" not in t, "freeze frame comment not found"
print("patched")
