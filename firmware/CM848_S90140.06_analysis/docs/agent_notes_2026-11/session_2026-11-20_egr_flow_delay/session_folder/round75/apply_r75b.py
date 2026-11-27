"""Round 75 stage B: the boot kernel's EEPROM header shadow (eeprom_header_t at 0x3fee08) and the EEPROM words it is loaded
from, named from cm848_loadVersionConfigFromEeprom / mpc555_systemInitialization and the e2m. Idempotent.
- cm848_loadVersionConfigFromEeprom fills it: EEPROM 0x34 -> +0, EEPROM 0x0 -> +2 (ecm_status), EEPROM 0x2 (6 bytes) ->
  +4, EEPROM 0x30 (4) -> +10, EEPROM 0x8e (2) -> +14.
- mpc555_systemInitialization reads EEPROM 0x8e into +14 and writes it to EEPROM 0x34 each time the boot service loop starts (it runs only when the boot mode strap pins are
  high or the ECM status is not CALIBRATION_VALID): EEPROM 0x34 is a
  copy of the security key, and that copy is the boot kernel's key gate (cm848_validateBootSecurityKey passes every key
  while it is 0xff; the application gates on EEPROM 0x8e itself).
- EEPROM 0x2 = e2m 0005 ECM_PSWD / Master_Password (the application's security_master_password_cal); EEPROM 0x30 = the
  key-on hour meter (the application's key_on_hour_meter_cal - mpc555_loadRuntimeCounterFromEepromShadow loads
  ecu_power_state_flags.runtime_counter from +10, mpc555_keyOnStateMachine writes it back); EEPROM 0x8e = e2m 1000
  Security_Key (the application's calibration_download_security_key_cal) - its EEPROM row was named a serial number.
usage: apply_r75b.py <repo> <map.csv>"""
import os
import sys

repo, map8 = os.path.abspath(sys.argv[1]), sys.argv[2]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 75"


def edit(p, old, new):
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


S8, G8, F8 = (os.path.join(O8, n) for n in ("structure_definitions.csv", "global_variables.csv", "function_renames.csv"))
edit(S8, "eeprom_header_t,0x003fee08,version_marker,word,2,EEPROM data version marker,,verified",
     "eeprom_header_t,0x003fee08,security_key_copy,word,2,EEPROM 0x34: the copy of the security key (EEPROM 0x8e) that "
     "the boot service loop mpc555_systemInitialization writes each time it starts - the boot kernel's key gate: cm848_validateBootSecurityKey passes "
     f"every key while it is 0xff (was version_marker 'EEPROM data version marker'; {R}),,verified")
edit(S8, "eeprom_header_t,0x003fee08,header_block,byte,6,EEPROM header data block,,verified",
     "eeprom_header_t,0x003fee08,security_master_password,byte,6,EEPROM 0x2-0x7: e2m 0005 ECM_PSWD / Master_Password (the "
     "application's security_master_password_cal) - cm848_validateBootSecurityKey compares the unscrambled key's 6 "
     f"characters with it (was header_block 'EEPROM header data block'; {R}),,verified")
edit(S8, "eeprom_header_t,0x003fee08,config_dword,dword,4,EEPROM configuration dword,,verified",
     "eeprom_header_t,0x003fee08,key_on_hour_meter,dword,4,EEPROM 0x30: the key-on hour meter (the application's "
     "key_on_hour_meter_cal) - mpc555_loadRuntimeCounterFromEepromShadow loads ecu_power_state_flags.runtime_counter from "
     f"it (was config_dword 'EEPROM configuration dword'; {R}),,verified")
edit(S8, "eeprom_header_t,0x003fee08,config_word,word,2,EEPROM configuration word,,verified",
     "eeprom_header_t,0x003fee08,calibration_download_security_key,word,2,EEPROM 0x8e: e2m 1000 Security_Key (the "
     "application's calibration_download_security_key_cal) - mpc555_systemInitialization copies it to EEPROM 0x34 (was "
     f"config_word 'EEPROM configuration word'; {R}),,verified")
for old, new in (("0x003fee0c,eeprom_shadow_header.header_block[0],,",
                  f"0x003fee0c,eeprom_shadow_header.security_master_password[0],,(was header_block[0]; {R})"),
                 ("0x003fee12,eeprom_shadow_header.config_dword,,",
                  f"0x003fee12,eeprom_shadow_header.key_on_hour_meter,,(was config_dword; {R})"),
                 ("0x003fee16,eeprom_shadow_header.config_word,,",
                  f"0x003fee16,eeprom_shadow_header.calibration_download_security_key,,(was config_word; {R})"),
                 ("0x01000002,eeprom_security_key,byte,",
                  "0x01000002,eeprom_security_master_password_cal,byte[6],EEPROM 0x2-0x7: e2m 0005 ECM_PSWD / "
                  "Master_Password - the source the boot kernel reads into eeprom_shadow_header.security_master_password "
                  f"(was eeprom_security_key byte; {R})"),
                 ("0x01000030,eeprom_config_block,byte,",
                  "0x01000030,eeprom_key_on_hour_meter_cal,dword,EEPROM 0x30: the key-on hour meter (the mirror's "
                  "key_on_hour_meter_cal) - read into eeprom_shadow_header.key_on_hour_meter / written back by "
                  f"mpc555_keyOnStateMachine and mpc555_verifyDownloadedCalibration (was eeprom_config_block byte; {R})"),
                 ("0x01000034,eeprom_version_marker,byte,",
                  "0x01000034,eeprom_security_key_copy_cal,word,EEPROM 0x34 (no e2m record): the copy of the security key "
                  "that the boot service loop mpc555_systemInitialization writes from EEPROM 0x8e each time it starts - the boot kernel's key gate "
                  f"(was eeprom_version_marker byte; {R})"),
                 ("0x0100008e,eeprom_serial_number,byte,",
                  "0x0100008e,eeprom_calibration_download_security_key_cal,word,EEPROM 0x8e: e2m 1000 Security_Key 'Key "
                  "which provides access to calibration dl.' (the mirror's calibration_download_security_key_cal) - not a "
                  f"serial number (was eeprom_serial_number byte; {R})")):
    edit(G8, old, new)
edit(F8, "0 (pass) when eeprom_shadow_header.version_marker is 0xff / 1 once",
     "0 (pass) when eeprom_shadow_header.security_key_copy (EEPROM 0x34 - a copy of the security key) is 0xff / 1 once")
with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x01000002,eeprom_security_master_password_cal,eeprom_security_key,global,1\n"
             "0x01000030,eeprom_key_on_hour_meter_cal,eeprom_config_block,global,1\n"
             "0x01000034,eeprom_security_key_copy_cal,eeprom_version_marker,global,1\n"
             "0x0100008e,eeprom_calibration_download_security_key_cal,eeprom_serial_number,global,1\n")
print("round 75 stage B applied")
