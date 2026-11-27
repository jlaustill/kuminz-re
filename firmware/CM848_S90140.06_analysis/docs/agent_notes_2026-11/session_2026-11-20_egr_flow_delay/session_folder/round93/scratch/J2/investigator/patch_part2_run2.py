"""J2 investigator run 2: corrections to build_result_part2.py after the re-check (each replacement must hit once
unless a count is given). Keeps the run 1 file as build_result_part2.run1.py."""
import os
import shutil

here = os.path.dirname(os.path.abspath(__file__))
path = os.path.join(here, "build_result_part2.py")
backup = os.path.join(here, "build_result_part2.run1.py")
if not os.path.exists(backup):
    shutil.copy(path, backup)
text = open(backup).read()

REPLACEMENTS = [
    # comments are applied to the CSV: no process words in them
    ('POWER_DOWN = ("Power-down part of the EEPROM image (EEPROM 0x%X): loaded at boot and saved at power-down, but outside the "\n'
     '              "0x803B0A-0x804155 window this round allows for _cal, so the name carries none (see notes).")',
     'POWER_DOWN = "Power-down data in the EEPROM image (EEPROM offset 0x%X): loaded at start and written back at power-down."', 1),
    (" Needs the struct j1939_control_session_t (24 bytes, CM848's layout; see notes).\",", "\",", 1),
    (" New struct, see notes.\",", "\",", 3),
    ("PGN 65249 every 500 by 0x4007a).", "PGN 65249 every 500 by 0x3407a).", 1),
    ("it clears the J1708 link timeout fault (error status word 7 bit 8) and the count 0x804266.",
     "it clears the J1708 link timeout fault (error status word 7 mask 0x8) and the count 0x804266.", 1),
    ("it clears the J1939 link timeout fault (error status word 5 bit 0x400) once",
     "it clears the J1939 link timeout fault (error status word 5 mask 0x400) once", 1),
    ("copy of the engine control mode datalink_speed_control_mode from its last pass",
     "copy of the engine control mode 0x80da50 from its last pass", 1),
    ("the engine control mode datalink_speed_control_mode at the end of the last cm550_runJ1939PowertrainControlTimeouts pass",
     "the engine control mode 0x80da50 at the end of the last cm550_runJ1939PowertrainControlTimeouts pass", 1),
    # 0x80da90: nothing reads it, so the role is CM848's inference
    ('"clr.w (0x80da90) at 0x21482, 0x2323c, 0x2fa30 and 0x2fa8a (the last two in cm550_retarderControlModeHandler); no read and no other write in the dumped ROM.", "medium")',
     '"clr.w (0x80da90) at 0x21482, 0x2323c, 0x2fa30 and 0x2fa8a (the last two in cm550_retarderControlModeHandler); no read and no other write in the dumped ROM. The pairing with CM848 0x40ae32 is proven (the last store of both twins), the meaning of the word is not.", "low")', 1),
    ("clr.w (0x80da60) at 0x231f4 and at ten more sites in the request handlers",
     "clr.w (0x80da60) at 0x231f4 and at nine more sites in the request handlers", 1),
    ("base load at 0x1ffe0 (service 4 / 5 worker)", "base load at 0x1ffde (service 4 / 5 worker)", 1),
    ("bound cmpa.l #0x80d9e4 at 0x21368", "bound a5 = 0x80d9e4 (cmpa.l a5,a2 at 0x21368)", 1),
    ("'J1922 LIMIT ENGINE OCC. TIME ECM TIME OF LAST J1922 LIMIT COMMAND'",
     "'J1922 LIMIT ENGINE OCC. TIME ECM TIME OF LAST J1922 LIMIT COM(MAND)'", 1),
    ("'J1922 LIMIT ENGINE MODE COUNT 0 = J1922 HASN'T LIMITED ENGINE'",
     "'J1922 LIMIT ENGINE MODE COUNT 0 = J1922 HASN'T LIMITED ENGI(NE)'", 1),
    ("(no absolute reference to any of them)",
     "(no absolute reference to any of them but 0x8019b8, which 0x2398e loads as the retarder list base - 4)", 1),
]
for old, new, count in REPLACEMENTS:
    n = text.count(old)
    assert n == count, (n, count, old[:90])
    text = text.replace(old, new)
open(path, "w").write(text)
print("patched", len(REPLACEMENTS), "patterns")
