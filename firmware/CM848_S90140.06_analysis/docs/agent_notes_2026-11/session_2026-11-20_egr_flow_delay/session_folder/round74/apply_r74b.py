"""Round 74 stage B: the boot kernel's copies of the security key check, and CM550's 'calibration bank' subcommand names.
Idempotent; keeps line endings.
- CM848 0x7370 cm848_validateWriteAuth is the boot kernel's copy of validateSecurityKey (the same steps over the boot's
  variables: 0 when the key byte is 0xff / 1 once eeprom_block_tracking.failed_write_authorization_count is 0x11 /
  unscramble / the runtime stamp ((runtime & ~0xff) - stamp < 0x1a) / the 6-character compare) -> cm848_validateBootSecurityKey.
- CM848 0x71f8 cm848_descrambleAuthToken is the boot kernel's copy of unscrambleSecurityKey -> cm848_unscrambleBootSecurityKey.
  Its tables sit in the boot image (RAM copy 0x3f981c / 0x3f9826 = ROM 0x3c4c / 0x3c56): the byte order is the
  application's (06 08 01 02 00 07 03 09 05 04) but the scramble mask is not (23 24 c0 11 30 0e 46 22 0b c8 against
  46 58 9a 32 70 87 23 99 85 64) - the reflash kernel scrambles its key differently.
- CM550: J1708 command 3 subcommands 0x40 / 0x41 call enterDevelopmentMode / forceExitDevelopmentMode and command 4
  subcommand 0x69 calls exitDevelopmentMode (diagnosticCommandDispatcher); J90280.05's analysis had named them
  calibration bank switches. The enum members render nowhere.
usage: apply_r74b.py <repo> <map_cm848.csv>"""
import os
import sys

repo, map8 = os.path.abspath(sys.argv[1]), sys.argv[2]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 74"


def edit(p, old, new):
    s = open(p, newline="").read()
    eol = "\r\n" if "\r\n" in s else "\n"
    s = s.replace("\r\n", "\n")
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w", newline="").write(s.replace(old, new).replace("\n", eol))


F8, G8, L8 = (os.path.join(O8, n) for n in ("function_renames.csv", "global_variables.csv", "local_variables.csv"))
edit(F8, "\n0x00007370,cm848_validateWriteAuth\n",
     "\n0x00007370,cm848_validateBootSecurityKey,The boot kernel's copy of validateSecurityKey - the same steps over the "
     "boot's variables: 0 (pass) when eeprom_shadow_header.version_marker is 0xff / 1 once "
     "eeprom_block_tracking.failed_write_authorization_count is 0x11 (17 misses) / else cm848_unscrambleBootSecurityKey "
     "gives 6 characters and a runtime stamp ((runtime & ~0xff) - stamp < 0x1a) and the characters are compared (was "
     f"cm848_validateWriteAuth; {R})\n")
edit(F8, "\n0x000071f8,cm848_descrambleAuthToken\n",
     "\n0x000071f8,cm848_unscrambleBootSecurityKey,The boot kernel's copy of unscrambleSecurityKey - the same bit routing / "
     "XOR / reorder with its own tables: boot_security_key_byte_order is the application's but "
     "boot_security_key_scramble_mask is not (the reflash kernel scrambles its key differently) (was "
     f"cm848_descrambleAuthToken; {R})\n")
s = open(L8).read()
if ",cm848_validateWriteAuth," in s:
    open(L8, "w").write(s.replace(",cm848_validateWriteAuth,", ",cm848_validateBootSecurityKey,"))
lines = open(G8).read().split("\n")
ROWS = [
    "0x003f981c,boot_security_key_scramble_mask,byte[10],The mask cm848_unscrambleBootSecurityKey routes the boot key's bits "
    "by - in the boot image (ROM 0x3c4c): 23 24 c0 11 30 0e 46 22 0b c8; NOT the application's security_key_scramble_mask "
    f"(46 58 9a 32 70 87 23 99 85 64) ({R})",
    "0x003f9826,boot_security_key_byte_order,byte[10],The byte order cm848_unscrambleBootSecurityKey XORs and writes the "
    "boot key by - in the boot image (ROM 0x3c56): 06 08 01 02 00 07 03 09 05 04, the same bytes as the application's "
    f"security_key_byte_order ({R})",
]
for row in ROWS:
    if row in lines:
        continue
    a = int(row.split(",")[0], 16)
    assert not any(l.startswith(row.split(",")[0] + ",") for l in lines)
    i = next(i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) > a)
    lines.insert(i, row)
open(G8, "w").write("\n".join(lines))

E5 = os.path.join(O5, "enums.csv")
for old, new in (
        ("DIAG_SECURED_SUBFUNC,0x40,SWITCH_TO_FACTORY_BANK,Switch to factory calibration bank - sets "
         "calibration_bank_selector=0 (switchToFactoryCalibrationBank)",
         "DIAG_SECURED_SUBFUNC,0x40,ENTER_DEVELOPMENT_MODE,enterDevelopmentMode after the security key (was "
         f"SWITCH_TO_FACTORY_BANK - J90280.05 read it as a calibration bank switch; {R})"),
        ("DIAG_SECURED_SUBFUNC,0x41,FORCE_ACTIVE_BANK,Force switch to active calibration bank (forceActiveCalibrationBank)",
         f"DIAG_SECURED_SUBFUNC,0x41,FORCE_EXIT_DEVELOPMENT_MODE,forceExitDevelopmentMode after the security key (was "
         f"FORCE_ACTIVE_BANK; {R})"),
        ("DIAG_CONTROL_SUBFUNC,0x69,SWITCH_TO_ACTIVE_BANK,Switch to active calibration bank - sets "
         "calibration_bank_selector=1 (switchToActiveCalibrationBank)",
         f"DIAG_CONTROL_SUBFUNC,0x69,EXIT_DEVELOPMENT_MODE,exitDevelopmentMode (was SWITCH_TO_ACTIVE_BANK; {R})"),
        ("DIAG_SERVICE_3_CMD,0x40,SERVICE_3_SWITCH_TO_FACTORY_BANK,switchToFactoryCalibrationBank - select factory "
         "calibration bank (calibration_bank_selector=0),1",
         "DIAG_SERVICE_3_CMD,0x40,SERVICE_3_ENTER_DEVELOPMENT_MODE,enterDevelopmentMode after the security key (was "
         f"SERVICE_3_SWITCH_TO_FACTORY_BANK; {R}),1"),
        ("DIAG_SERVICE_3_CMD,0x41,SERVICE_3_FORCE_ACTIVE_BANK,forceActiveCalibrationBank - force active calibration bank "
         "if write protect allows,1",
         "DIAG_SERVICE_3_CMD,0x41,SERVICE_3_FORCE_EXIT_DEVELOPMENT_MODE,forceExitDevelopmentMode - when "
         f"not_safe_to_program_flag allows (was SERVICE_3_FORCE_ACTIVE_BANK; {R}),1"),
        ("DIAG_SERVICE_4_CMD,0x69,SERVICE_4_SWITCH_TO_ACTIVE_BANK,switchToActiveCalibrationBank - select active "
         "calibration bank (calibration_bank_selector=1),1",
         "DIAG_SERVICE_4_CMD,0x69,SERVICE_4_EXIT_DEVELOPMENT_MODE,exitDevelopmentMode (was "
         f"SERVICE_4_SWITCH_TO_ACTIVE_BANK; {R}),1")):
    edit(E5, old, new)
with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00007370,cm848_validateBootSecurityKey,cm848_validateWriteAuth,function,1\n"
             "0x000071f8,cm848_unscrambleBootSecurityKey,cm848_descrambleAuthToken,function,1\n")
print("round 74 stage B applied")
