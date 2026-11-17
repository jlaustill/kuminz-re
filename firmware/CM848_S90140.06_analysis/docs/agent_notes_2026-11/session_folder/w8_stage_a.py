"""Wave 8 stage A inputs: the manual rows (aligned_W8_manual.jsonl) and copies of the agents' aligned files without
the six new rows that sit inside dwords the stage-B retypes split (aligned_W8_<group>_A.jsonl)."""
import json
import os
import sys

d = sys.argv[1]
STAGE_B_NEW = {0x3fa174, 0x3fa7be, 0x3fa7cc, 0x3fa7d2, 0x40a664, 0x40a8a9}
for g in ("torque_limit", "egr_charge", "governor_combustion"):
    rows = [json.loads(l) for l in open(os.path.join(d, f"aligned_W8_{g}.jsonl")) if l.strip()]
    keep = [r for r in rows if not (r.get("kind") == "new_global" and int(r["address"], 16) in STAGE_B_NEW)]
    open(os.path.join(d, f"aligned_W8_{g}_A.jsonl"), "w").write("".join(json.dumps(r) + "\n" for r in keep))
    print(g, len(rows), "->", len(keep))
check = ("hpcr_checkRailPressureSensorBeforeStart (its only user, xref_addr.py) during the pre-start P0191 check "
         "(fault 414, fault_detected_bits_400_to_415 0x4000)")
manual = [
    {"kind": "function", "verdict": "confirmed", "address": "0x0001fa20", "old": "cm848_selectHighSpeedGovernorGainSet",
     "new": "selectHighSpeedGovernorGainSet",
     "plate_comment": ("Selects the high speed governor gain set - error filter coefficient plus proportional, integral and "
                       "derivative gains - and records its code in high_speed_governor_gain_set_code: the base set (code 16) "
                       "when system_feature_config_flags bit 0 is clear; otherwise a transient set (code 17, "
                       "high_speed_governor_transient_*) while engine acceleration is above "
                       "high_speed_governor_transient_acceleration_threshold and governor_mode_code_prev is not 12, and once "
                       "high_speed_governor_transient_gain_set_time_limit has elapsed the working set (when loaded) or the low / "
                       "high reference speed set (codes 18 / 19, chosen against high_speed_governor_low_reference_speed_threshold "
                       "/ high_speed_governor_high_reference_speed_threshold; base set 16 between them); it also records the "
                       "alternate set. Shared with CM550 0x1d392 (same function: same pass timer, set codes and the 16 constant "
                       "words at the same relative offsets; CM848 also loads the base set every pass while feature bit 0 is "
                       "clear) (was selectSensorRawChannels then cm848_selectHighSpeedGovernorGainSet)")},
    {"kind": "global", "verdict": "confirmed", "address": "0x003fd1d8", "old": "sensor_scan_cycle_counter",
     "new": "fuel_pressure_sensor_pre_start_high_sample_count",
     "evidence": ("Counts fuel_pressure_sensor_volts samples above fuel_pressure_sensor_pre_start_high_volts_threshold (573 = "
                  "0.69 V) in " + check + "; a sample in range after a count aborts the check (abort reason 4); saturates at "
                  "0xfffe; compared with fuel_pressure_sensor_pre_start_high_sample_limit (20). Time-shared RAM: the boot "
                  "kernel image of mpc555_tickTransferTimeoutAndRuntimeCounter starts here (the thunk stage keeps this row)")},
    {"kind": "new_global", "verdict": "confirmed", "address": "0x003fd1da", "new": "fuel_pressure_sensor_pre_start_low_sample_count",
     "type": "word",
     "evidence": ("Counts fuel_pressure_sensor_volts samples below fuel_pressure_sensor_pre_start_low_volts_threshold (246 = "
                  "0.30 V) in " + check + "; a sample in range after a count aborts the check (abort reason 3); saturates at "
                  "0xfffe; compared with fuel_pressure_sensor_pre_start_low_sample_limit (20). Word accesses only (xref_addr.py "
                  "4 reads / 2 writes); time-shared RAM, no boot-ROM data user")},
    {"kind": "new_global", "verdict": "confirmed", "address": "0x00409eec", "new": "fuel_pressure_sensor_pre_start_high_sample_limit",
     "type": "word", "evidence": "20 in the RAM dump; the high sample count must stay below it to clear fault 414; read once by " + check},
    {"kind": "new_global", "verdict": "confirmed", "address": "0x00409eee", "new": "fuel_pressure_sensor_pre_start_high_volts_threshold",
     "type": "word", "evidence": "573 (x 0.0012 V = 0.69 V) in the RAM dump; samples above it are counted; read once by " + check},
    {"kind": "new_global", "verdict": "confirmed", "address": "0x00409ef0", "new": "fuel_pressure_sensor_pre_start_low_sample_limit",
     "type": "word", "evidence": "20 in the RAM dump; the low sample count must stay below it to clear fault 414; read once by " + check},
    {"kind": "new_global", "verdict": "confirmed", "address": "0x00409ef2", "new": "fuel_pressure_sensor_pre_start_low_volts_threshold",
     "type": "word", "evidence": "246 (x 0.0012 V = 0.30 V) in the RAM dump; samples below it are counted; read once by " + check},
]
open(os.path.join(d, "aligned_W8_manual.jsonl"), "w").write("".join(json.dumps(r) + "\n" for r in manual))
print("manual rows", len(manual))
