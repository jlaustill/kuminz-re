"""Round 40 stage A follow-ups. arrays.csv also names the VIN (its arrays stage runs after the import, so its name wins
in the build). The other files only mention old names in comments: the global_variables.csv '#' line, enums.csv,
structure_definitions.csv, docs/engine_hours_and_odometer.md and tools/update_odometer.sh. The feature byte's comment
also gains bits 2 / 3 and its SCI access. Idempotent.  usage: apply_r40a_followups.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
EDITS = [
    ("output/arrays.csv", r"\bvehicle_vin_string\b", "vehicle_vin_string_cal"),
    ("output/global_variables.csv", r"(?m)^(# 0x003fd707-0x003fd717: )vehicle_vin_string\b", r"\1vehicle_vin_string_cal"),
    ("output/enums.csv", r"\bj1939_governor_feature_byte\b", "feature_selection_bits_cal"),
    ("output/structure_definitions.csv", r"\bj1939_governor_feature_byte\b", "feature_selection_bits_cal"),
    ("docs/engine_hours_and_odometer.md", r"\blifetime_distance_pulses\b", "lifetime_distance_pulses_cal"),
    ("tools/update_odometer.sh", r"\blifetime_distance_pulses\b", "lifetime_distance_pulses_cal"),
    ("tools/update_odometer.sh", r"\blifetime_distance_8_mile_record\b", "lifetime_distance_8_mile_record_cal"),
]
for rel, pat, rep in EDITS:
    p = os.path.join(out, rel)
    t = open(p).read()
    n = len(re.findall(pat, t))
    t = re.sub(pat, rep, t)
    open(p, "w").write(t)
    print(rel, n)
gp = os.path.join(out, "output/global_variables.csv")
t = open(gp).read()
old = ("bit 4 = the water in fuel sensor's second configuration (cm848_processWaterInFuelChannel / "
       "cm848_initializeWaterInFuelChannel use the *_feature_bit_4_off_* tables while it is clear). Not J1939; 0 on this "
       "truck.")
new = ("bit 2 = the oil change monitor (cm848_updateOilChangeMonitor, with algorithm_enable_flags_12_cal "
       "oil_change_monitor_enable), bit 3 = the initial overdrive flags (cm848_initializeTransmissionControl), bit 4 = "
       "the water in fuel sensor's second configuration (cm848_processWaterInFuelChannel / "
       "cm848_initializeWaterInFuelChannel use the *_feature_bit_4_off_* tables while it is clear). SCI EEPROM setting "
       "type 2 (cm848_sciLookupEepromSettingAddress), so a scan tool programs it. Not J1939.")
if new not in t:
    assert t.count(old) == 1
    t = t.replace(old, new)
open(gp, "w").write(t)
print("feature byte comment updated")
