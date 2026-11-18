"""Batch A hygiene: rename the member-label rows that name fields the redefined structs no longer have, and reword
comment tokens that cite names no CSV defines. Usage: fix_batchA_labels.py <output dir>"""
import os
import sys

out = sys.argv[1]
LABELS = {
    "0x0040aec4,governor_output_t_0040aec2.integrator+2,": "0x0040aec4,governor_output_t_0040aec2.fuel_feed_forward_quantity,",
    "0x0040aec8,governor_output_t_0040aec2.governor_output_high,": "0x0040aec8,governor_output_t_0040aec2.idle_speed_barometric_ramped,",
    "0x0040b102,protection_timer_state_t_0040b100.status_code+2,": "0x0040b102,protection_timer_state_t_0040b100.status_code_hold_timer,",
    "0x0040b7ae,engine_rpm_state_t_0040b7ac.reserved_02,": "0x0040b7ae,engine_rpm_state_t_0040b7ac.crank_capture_period_sum,",
    "0x0040b7b2,engine_rpm_state_t_0040b7ac.reserved_06,": "0x0040b7b2,engine_rpm_state_t_0040b7ac.crank_tooth_period_sum,",
    "0x0040b7b6,engine_rpm_state_t_0040b7ac.reserved_0a,": "0x0040b7b6,engine_rpm_state_t_0040b7ac.crank_capture_period_sample_count,",
    "0x0040b7b8,engine_rpm_state_t_0040b7ac.reserved_0c,": "0x0040b7b8,engine_rpm_state_t_0040b7ac.crank_tooth_period_sample_count,",
}
TEXT = {
    "global_variables.csv": [("minus boost_pressure_fixed_reference", "minus barometric_pressure_sensor_config.default_value")],
    "structure_definitions.csv": [
        ("guess (not proven, so reserved): elevation_delay_timer_armed_flag", "guess (not proven, so reserved): an elevation delay timer armed flag"),
        ("guess (not proven, so reserved): pressure_elevation_by_timer_flag", "guess (not proven, so reserved): a pressure elevation by timer flag"),
        ("guess (not proven, so reserved): transmission_solenoid_enable_request", "guess (not proven, so reserved): a transmission solenoid enable request"),
        ("the old word field governor_output_high covered only its high half", "the old word field at +6 covered only its high half"),
        ("Read by cm848_calibration_group21_load_cont", "Read by cm848_monitorEgrOrificeTemperatureSensorRationality"),
    ],
}
path = os.path.join(out, "global_variables.csv")
text = open(path).read()
for old, new in LABELS.items():
    assert text.count("\n" + old) == 1, old
    text = text.replace("\n" + old, "\n" + new)
for old, new in TEXT["global_variables.csv"]:
    text = text.replace(old, new)
open(path, "w").write(text)
path = os.path.join(out, "structure_definitions.csv")
text = open(path).read()
for old, new in TEXT["structure_definitions.csv"]:
    assert old in text, old
    text = text.replace(old, new)
open(path, "w").write(text)
print("fixed")
