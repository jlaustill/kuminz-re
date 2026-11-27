"""Round 73 stage A0: audit_cal_suffixes.py learns CM550's EEPROM RAM mirror (0x803b0a-0x804155 = EEPROM 0x0-0x64b).
The _cal rule is unchanged (EEPROM-backed = _cal); the auditor's CM550 memory map lacked the mirror. Evidence:
- the memory services translate an EEPROM address into it by - 0x7fc4f6 (EEPROM 0x1000000 -> RAM 0x803b0a):
  writeJ1939DiagnosticMemory and three more functions;
- cm550_FUN_00011a74 stores 0x803b0a-0x804155 back to EEPROM in 16-byte chunks - the twin of CM848's
  cm848_commitEepromMirrorToEeprom over CM848's mirror (7 when not safe / 16-byte chunks through the EEPROM byte write
  queue / up to 16000 waits for the queue);
- CM848's EEPROM offsets land on the same CM550 roles: 0x02 the security key password, 0x8e the calibration download
  security key (a word in both - cmpi.w in CM550).
Idempotent.  usage: apply_r73a0.py <repo>"""
import os
import sys

P = os.path.join(os.path.abspath(sys.argv[1]), "firmware/scripts/audit_cal_suffixes.py")
s = open(P).read()
OLD = ('CM550_REGIONS = [\n'
       '    ("EEPROM",        0x01000000,   0x01001000,   True,    "eeprom"),\n')
NEW = ('CM550_REGIONS = [\n'
       '    ("EEPROM",        0x01000000,   0x01001000,   True,    "eeprom"),\n'
       '    # RAM mirror of EEPROM 0x0-0x64b (RAM = 0x803B0A + EEPROM offset): the memory services translate by - 0x7FC4F6\n'
       '    # and 0x11a74 stores it back in 16-byte chunks (the twin of cm848_commitEepromMirrorToEeprom); PR #53 round 73.\n'
       '    # Listed before RAM: the first matching region wins.\n'
       '    ("EEPROM_SHADOW", 0x00803B0A,   0x00804156,   True,    "eeprom"),\n')
DOC_OLD = "    On CM848 the application loads a RAM mirror of the serial EEPROM at 0x3FD482-0x3FEEC1"
DOC_NEW = ("    On CM550 the EEPROM RAM mirror is 0x803B0A-0x804155 (RAM = 0x803B0A + EEPROM offset; PR #53 round 73).\n"
           "    On CM848 the application loads a RAM mirror of the serial EEPROM at 0x3FD482-0x3FEEC1")
if NEW not in s:
    assert s.count(OLD) == 1 and s.count(DOC_OLD) == 1
    s = s.replace(OLD, NEW).replace(DOC_OLD, DOC_NEW)
    open(P, "w").write(s)
print("round 73 stage A0 applied")
