"""Round 68 stage A, second pass (from the first build's render). Idempotent.
- cm848_lookupEepromParameterAddress (0x2d08) returns 0x3fee1c for parameter 0x17, so once the struct starts there
  Ghidra typed its return intake_air_heater_saved_values_t * and cast every other path. It gets its prototype (byte *
  / the parameter) and a plate: its only caller, cm848_processDiagnosticResponseCallback, casts the result to byte *.
- fuel_level_saved_values_t's comment: the boot kernel does read 0x3fee18-0x3fee1d - by address, through that lookup.
usage: fix_r68a2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 68"


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


edit("structure_definitions.csv",
     "The boot kernel time-shares 0x3fee18-0x3fee1d for its copy of EEPROM 0x4a (eeprom_calibration_block - "
     "cm848_loadCalibrationFromEeprom) and reads none of it back by name",
     "The boot kernel time-shares 0x3fee18-0x3fee1d for its copy of EEPROM 0x4a-0x4f (eeprom_calibration_block - "
     "cm848_loadCalibrationFromEeprom) and reads it back only by address: cm848_lookupEepromParameterAddress returns "
     "its bytes for parameters 1-4 / 0x17 / 0x18")
edit("function_renames.csv", "0x00002d08,cm848_lookupEepromParameterAddress\n",
     "0x00002d08,cm848_lookupEepromParameterAddress,Boot kernel: the address of a diagnostic EEPROM parameter's value for "
     "cm848_processDiagnosticResponseCallback - parameters 1-4 / 0x17 / 0x18 return 0x3fee18-0x3fee1b / 0x3fee1c / "
     "0x3fee1d (the boot kernel's copy of EEPROM 0x4a-0x4f - time-shared with the application's fuel level and intake "
     "air heater words) / 10-12 and 15-16 read an EEPROM word from 0x20-0x24 into 0x3fee38 (inside the application's "
     f"oil_change_monitor_fuel_hundredth_gallons_cal) / others return 0 ({R})\n")
D = os.path.join(O, "function_definitions.csv")
d = open(D).read()
if "0x00002d08,cm848_lookupEepromParameterAddress," not in d:
    d = d.rstrip("\n") + "\n" + "\n".join([
        f"0x00002d08,cm848_lookupEepromParameterAddress,return,,byte*,The parameter's value (see the plate) - 0 for an "
        f"unknown parameter ({R})",
        f"0x00002d08,cm848_lookupEepromParameterAddress,0,parameter,byte,The diagnostic EEPROM parameter number ({R})"]) + "\n"
    open(D, "w").write(d)
print("second pass applied")
