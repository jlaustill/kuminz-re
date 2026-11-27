"""Round 54 stage B: five boot-time functions named from their bodies (all were legacy names with no plate, none is in
CM550), and the calibration ID characters 4-9.
  - The EEPROM mirror 0x3fd4c8-0x3fd4d1 holds the calibration ID '1504 2RSAO' (EEPROM 0x46). The ECU only uses
    characters 4-9 (0x3fd4cc-0x3fd4d1 = EEPROM 0x4a-0x4f): cm848_updateEepromCalibrationIdentifier compares them with
    the ROM calibration's own characters (calibration_id_byte0-5 = ' 2RS' / 'AO') and rewrites them when they differ,
    and cm848_sciLookupEepromSettingAddress maps SCI EEPROM settings 1-6 onto them. A byte[6] row names them.
  - The calibration_id_byte0-5 comments said EEPROM-loaded; they are ROM-copied (0x408b81-0x408b84 / 0x408b97-0x408b98).
Idempotent.  usage: apply_r54b.py <repo> <map.csv>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 54"
fp = os.path.join(out, "function_renames.csv")
t = open(fp).read()
if "cm848_updateEepromCalibrationIdentifier" in t:
    print("already applied")
    sys.exit(0)
FUNCS = [
    ("0x00519ffc", "protection_speed_limit_initialize", "cm848_initializeRailPressureShortfallFuelLimit",
     "Boot (cm848_applicationMain): presets the rail pressure shortfall fuel limit - its lookup cache "
     "fuel_quantity_limit_rail_pressure_shortfall_cached_axis_offset = 2 and its ramp "
     "fuel_quantity_limit_rail_pressure_shortfall_ramp = 0x1700 (no limit)"),
    ("0x0051a018", "initDiagnosticShadowFlags", "cm848_initializeEngineOilPressureProcessing",
     "Boot (cm848_applicationMain) - the twin of cm848_processEngineOilPressure: clears the low oil pressure flags / "
     "debounce count and fault_detected_cal / fault_registered_cal.low_oil_pressure_error and presets the oil "
     "pressure model's lookup caches and engine_oil_pressure_filter_state"),
    ("0x0051ab50", "initFuelCorrectionTableParams", "cm848_initializeOilChangeMonitorLookups",
     "Boot (cm848_applicationMain): presets the oil change monitor's lookup caches (the severity factor by coolant "
     "and rpm grid and the soot percentage by end of injection table)"),
    ("0x0051db0c", "configurationValidationCheck", "cm848_updateEepromCalibrationIdentifier",
     "Boot (cm848_applicationMain): when the EEPROM copy of the calibration ID characters 4-9 "
     "(calibration_identifier_characters_4_to_9_cal) differs from the running calibration's own "
     "(calibration_id_byte0-5) it writes them to EEPROM 0x4a (4 bytes) and 0x4e (2 bytes) with cm848_writeEepromBytes"),
    ("0x005196f0", "j1939_fault_processor_initialize", "cm848_initializeObdServiceState",
     "Called by cm848_initJ1939CommunicationSystem: zeroes the OBD-II service state - obd_stored_dtc_count / "
     "obd_dtc_scan_index / obd_dtc_scan_more_flag / obd_dtc_copy_index and the VIN / calibration ID frame indexes"),
]
mapping = ["address,name,old_label,kind,dims"]
for a, cur, new, plate in FUNCS:
    m = re.search(rf"^{a},{cur}(,[^\n]*)?$", t, re.M)
    assert m and not (m.group(1) or "").strip(", "), (a, cur)
    assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", new) and new not in t and "," not in plate
    t = t[:m.start()] + f"{a},{new},{plate} (was {cur}; {R})" + t[m.end():]
    mapping.append(f"{a},{new},{cur},function,1")
open(fp, "w").write(t)
# ---- the calibration ID characters --------------------------------------------------------------------------------
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
assert "0x003fd4cc" not in idx
later = sorted(x for x in idx if int(x, 16) > 0x3fd4cc)
g.insert(idx[later[0]], "0x003fd4cc,calibration_identifier_characters_4_to_9_cal,byte[6],EEPROM 0x4a-0x4f (mirror): "
         "characters 4-9 of the calibration ID '1504 2RSAO' at EEPROM 0x46 (' 2RSAO' in the dump). "
         "cm848_updateEepromCalibrationIdentifier rewrites them from calibration_id_byte0-5 when they differ, and "
         "cm848_sciLookupEepromSettingAddress maps SCI EEPROM settings 1-6 onto them (setting n = character n + 3). "
         f"Characters 0-3 (EEPROM 0x46-0x49) have no user ({R})")
mapping.append("0x003fd4cc,calibration_identifier_characters_4_to_9_cal,DAT_003fd4cc,global,6")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
CHARS = {"0x00408b81": (0, "' '"), "0x00408b82": (1, "'2'"), "0x00408b83": (2, "'R'"), "0x00408b84": (3, "'S'"),
         "0x00408b97": (4, "'A'"), "0x00408b98": (5, "'O'")}
for a, (n, ch) in CHARS.items():
    p = g[idx[a]].split(",", 3)
    assert p[1] == f"calibration_id_byte{n}" and p[3].startswith("EEPROM-loaded calibration ID byte"), (a, p[3][:60])
    g[idx[a]] = (f"{a},{p[1]},{p[2]},ROM-copied character {n + 4} of the running calibration's ID ({ch}; the old note "
                 f"said EEPROM-loaded): cm848_updateEepromCalibrationIdentifier compares it with "
                 f"calibration_identifier_characters_4_to_9_cal[{n}] ({R}) | earlier note: {p[3]}")
open(gp, "w").write("\n".join(g))
with open(sys.argv[2], "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"{len(mapping) - 1} map entries")
