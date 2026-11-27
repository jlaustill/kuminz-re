"""Round 53 stage A (labels / rows / comments only): eleven absent blocks whose layouts match existing rows record
for record, from semantic_record_matches.py (round 52's matcher ranked by a token-overlap meaning score), each read
by meaning. The coolant temperature derate module (8A71 / 8A72 / 8A73 / 8A79 / 8A7A) is stage B.
Renames:
  8B03: the eight sensor-fault substitutes named by the fault that selects them (the e2m's High_Default /
        Low_Default), not by their value. The coolant / intake temperature pair used the opposite convention from
        the pressure / pedal pair (coolant_temperature_low_substitute was the HIGH fault's value).
  8A7D +29: pci_receive_message_13_state_2_flag -> pci_four_wheel_drive_status_flag (J1850_4WD_Status).
New row: 8B8A +0 Fractional_GR_Difference (0x408b78, one lhz in cm848_updateDrivetrainRatio).
Idempotent.  usage: apply_r53a.py <repo> <map.csv>"""
import os
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows, place  # noqa: E402

repo = os.path.abspath(sys.argv[1])
records = Records(repo)
rows = Rows(repo, "PR #53 round 53")
if "pci_four_wheel_drive_status_flag" in rows.names:
    print("already applied")
    sys.exit(0)
RENAMES = {
    "0x0040868a": ("intake_manifold_pressure_high_substitute", "intake_manifold_pressure_high_fault_substitute",
                   "cm848_selectSensorValuesInUse: intake_manifold_pressure_in_use while fault_detected_cal.faults_0_to_15 mask "
                   "0x100 is set (the e2m: failed out of range high)"),
    "0x0040868c": ("intake_manifold_pressure_low_substitute", "intake_manifold_pressure_low_fault_substitute",
                   "cm848_selectSensorValuesInUse: intake_manifold_pressure_in_use while faults_0_to_15 mask 0x200 is set (out "
                   "of range low)"),
    "0x0040868e": ("accelerator_pedal_position_high_substitute", "accelerator_pedal_position_high_fault_substitute",
                   "cm848_selectSensorValuesInUse: accelerator_pedal_position_in_use while "
                   "fault_detected_cal.pedal_position_sensor_1_high_error (dual channel) or faults_0_to_15 mask 0x400 "
                   "is set (out of range high)"),
    "0x00408690": ("accelerator_pedal_position_low_substitute", "accelerator_pedal_position_low_fault_substitute",
                   "cm848_selectSensorValuesInUse: accelerator_pedal_position_in_use on the out of range low fault"),
    "0x00408692": ("coolant_temperature_low_substitute", "coolant_temperature_high_fault_substitute",
                   "cm848_selectSensorValuesInUse: coolant_temperature_in_use while "
                   "fault_detected_cal.coolant_temperature_high_error is set "
                   "(-50 deg F; the old name went by the value)"),
    "0x00408694": ("coolant_temperature_high_substitute", "coolant_temperature_low_fault_substitute",
                   "cm848_selectSensorValuesInUse: coolant_temperature_in_use while "
                   "fault_detected_cal.coolant_temperature_low_error is set (256 deg "
                   "F; the e2m description repeats 'failed OOR high' but the record is Low_Default)"),
    "0x00408696": ("intake_manifold_temperature_low_substitute", "intake_manifold_temperature_high_fault_substitute",
                   "cm848_selectSensorValuesInUse: intake_manifold_temperature_in_use while "
                   "fault_detected_cal.intake_manifold_temperature_high_error is set (-50 "
                   "deg F; the old name went by the value)"),
    "0x00408698": ("intake_manifold_temperature_high_substitute", "intake_manifold_temperature_low_fault_substitute",
                   "cm848_selectSensorValuesInUse: intake_manifold_temperature_in_use while "
                   "fault_detected_cal.intake_manifold_temperature_low_error "
                   "is set (256 deg F)"),
    "0x0040b528": ("pci_receive_message_13_state_2_flag", "pci_four_wheel_drive_status_flag",
                   "1 when PCI 0x92 payload byte 1 bits 0-2 = 2 (the e2m: 'j1850 msg $92 = $2, set J1850_4WD_Status "
                   "TRUE'); set every 4th PCI application tick and read by nothing in this build"),
}
NEW_ROWS = {
    "0x00408b78": ("drivetrain_gear_ratio_detection_margin", "word",
                   "cm848_updateDrivetrainRatio: top_gear_ratio_threshold / gear_down_ratio_threshold = (this + "
                   "0x6400) x top_gear_ratio_cal / gear_down_gear_ratio_cal / 0x6400 (clamped to "
                   "drivetrain_ratio_maximum_limit) - the margin over the expected ratio (2501 / 25600 = 9.8 %; one "
                   "lhz)", "DAT_00408b78"),
}
NOTE = (" The {} layout ({} records) matches the rows at {:#x} record for record (semantic_record_matches.py, read by "
        "meaning)")
PLACEMENTS = [(0x8B20, 0x40b2f4), (0x160A, 0x40b9c8), (0x1609, 0x64302), (0x8B03, 0x40868a), (0x8B04, 0x40b14e),
              (0x8BB1, 0x408706), (0x8B8A, 0x408b78), (0x8A7D, 0x40b4ff), (0x8A86, 0x3fcd88), (0x8ADA, 0x40b5a8),
              (0x8ADB, 0x3fd8f0), (0x8B0B, 0x408d1c)]
EXTRA = {0x8A7D: "; the middle 0x40b506-0x40b51c holds the immobilizer words this build adds (no e2m records there)",
         0x8ADA: "; it opens the 0x40b5a8 span round 51 could not place by width alone"}
for block, base in PLACEMENTS:
    note = NOTE.format(f"{block:04X}", len(records.block(block)), base) + EXTRA.get(block, "")
    missing = place(records, rows, block, base, RENAMES, NEW_ROWS, note)
    if missing:
        print(f"{block:04X}: no row for {missing}")
assert len([m for m in rows.mapping[1:]]) == len(RENAMES) + 1, rows.mapping
rows.save(sys.argv[2])
print(f"{len(rows.mapping) - 1} map entries")
