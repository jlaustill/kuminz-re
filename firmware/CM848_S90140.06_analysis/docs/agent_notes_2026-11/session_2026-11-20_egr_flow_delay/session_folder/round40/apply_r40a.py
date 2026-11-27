"""Round 40 stage A: application-side names in the EEPROM mirror (0x3fd482-0x3feec1) without _cal, from
audit_cal_suffixes.py's MISSING list. Only rows used by application code alone (missing_users.py) whose name describes
the application's EEPROM value; boot-named and dual-use rows (time-shared with the boot kernel), the region labels
(eeprom_mirror, eeprom_checksummed_block_start) and rows without evidence stay. Every candidate was run through the
ECU's parameter ID table first; 7 names change with the evidence (e2m record or code use), the rest only gain _cal.
Documentation rows follow their instance. Writes the proof map. Idempotent.  usage: apply_r40a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
MIRROR = "EEPROM-backed (mirror RAM = 0x3fd482 + EEPROM offset; only application code uses it), so _cal"
IDLE = ("engine_idling_flag (the low speed governor fueling state 11 within +-400 counts = 50 rpm of its reference: "
        "idle; e2m 117F +A names the lifetime fuel twin Total_Idle_Fuel_Used)")
# (address, name now, new name, comment head or None to keep the comment)
ROWS = [
    ("0x003fd707", "vehicle_vin_string", "vehicle_vin_string_cal", "The VIN, EEPROM 0x285. " + MIRROR),
    ("0x003fd882", "governor_speed_target_trim", "low_speed_governor_no_load_fuel_trim_cal",
     "EEPROM 0x400: its only use adds it into low_speed_governor_reference.no_load_fuel with "
     "friction_fuel_by_engine_speed, the commanded-throttle addend and friction_fuel_adjustment_for_coolant_temperature "
     "(cm848_calculateLowSpeedGovernorNoLoadFuel), so it is a fuel trim, not a speed target. " + MIRROR),
    ("0x003fd902", "j1939_governor_feature_byte", "feature_selection_bits_cal",
     "EEPROM 0x480 feature bits: bit 0 = cab power take-off governor, bit 1 = remote power take-off governor "
     "(cm848_runPowerTakeOffGovernorStateMachine), bit 4 = the water in fuel sensor's second configuration "
     "(cm848_processWaterInFuelChannel / cm848_initializeWaterInFuelChannel use the *_feature_bit_4_off_* tables while "
     "it is clear). Not J1939; 0 on this truck. " + MIRROR),
    ("0x003fdb88", "sensor_validation_startup_accumulator", "eeprom_verify_retry_lifetime_total_cal",
     "EEPROM 0x706: cm848_saveEepromForPowerDown adds cm848_getEepromVerifyRetryTotal() to it at each power-down "
     "with retries and writes it back (verified by reading it again). " + MIRROR),
    ("0x003fdd6c", "lifetime_distance_pulses", "lifetime_distance_pulses_cal", "e2m 117F +0 Total_Distance. " + MIRROR),
    ("0x003fdd74", "trip_average_fuel_economy", "trip_average_fuel_economy_cal",
     "e2m 117F +8 Trip_Average_Fuel_Economy. " + MIRROR),
    ("0x003fdd76", "lifetime_fuel_used_at_governed_speed", "lifetime_idle_fuel_used_cal",
     "e2m 117F +A Total_Idle_Fuel_Used: lifetime injected fuel while " + IDLE + ". " + MIRROR),
    ("0x003fdda8", "ignition_key_off_count", "ignition_key_off_count_cal", "e2m 1329 +0 Key_Off_Count. " + MIRROR),
    ("0x003feaa0", "governor_mode_code_diag_snapshot", "final_fueling_state_before_shutdown_or_excess_injection_fault_cal",
     "EEPROM 0x161e: cm848_selectFinalFueling stores final_fueling_state_prev here once (governor_diag_entry_latch_flag) "
     "when final_fueling_state becomes FUELING_STATE_SHUTDOWN or fault_detected_cal.watchdog_fueling_error sets, next "
     "to total_fueling_before_shutdown_or_excess_injection_fault_cal. " + MIRROR),
    ("0x003fee00", "cruise_control_switches_learned_flag", "cruise_control_switches_learned_flag_cal", MIRROR),
    ("0x003fee02", "supervisor_watchdog_serious_error_events", "supervisor_watchdog_serious_error_events_cal", MIRROR),
    ("0x003fee2f", "immobilizer_secret_key_byte_3", "immobilizer_secret_key_byte_3_cal",
     "EEPROM 0x19ad; the key's other bytes share their addresses with boot-time names (time-shared "
     "eeprom_shadow_header area). " + MIRROR),
    ("0x003fee50", "lifetime_distance_8_mile_record", "lifetime_distance_8_mile_record_cal", MIRROR),
    ("0x003fee58", "lifetime_fuel_used", "lifetime_fuel_used_cal", MIRROR),
    ("0x003fee5c", "lifetime_time_at_governed_speed", "lifetime_idle_time_cal",
     "Lifetime passes (EEPROM 0x19da) with " + IDLE + ". " + MIRROR),
    ("0x003fee60", "lifetime_engine_run_time", "lifetime_engine_run_time_cal", MIRROR),
    ("0x003fee64", "trip_counter_status_flags", "trip_counter_status_flags_cal", MIRROR),
    ("0x003fee66", "trip_and_lifetime_overflow_flags", "trip_and_lifetime_overflow_flags_cal", MIRROR),
    ("0x003fee68", "trip_fuel_used", "trip_fuel_used_cal", MIRROR),
    ("0x003fee6c", "trip_fuel_used_at_governed_speed", "trip_idle_fuel_used_cal",
     "Trip injected fuel (EEPROM 0x19ea) while " + IDLE + ". " + MIRROR),
    ("0x003fee70", "trip_time_at_governed_speed", "trip_idle_time_cal",
     "Trip passes (EEPROM 0x19ee) with " + IDLE + ". " + MIRROR),
    ("0x003fee74", "trip_engine_run_time", "trip_engine_run_time_cal", MIRROR),
    ("0x003feeb6", "temperature_rationality_coolant_soak_reference", "temperature_rationality_coolant_soak_reference_cal",
     "The EEPROM copy (0x1a34) of temperature_rationality_coolant_soak_reference_working. " + MIRROR),
    ("0x003feebc", "protection_b_fault_active_flag", "exhaust_brake_switch_learned_flag_cal",
     "EEPROM 0x1a3a: cm848_monitorDiscreteOutputReadBack sets it once switch_input_state_bits.exhaust_brake_switch is "
     "seen on, and only then checks the engine brake 1 output read-back; cm848_sciBuildStatusFlagsByte reports it as "
     "bit 0x10 next to four_wheel_drive_switch_learned_flag_cal (0x20); cm848_clearDiagnosticState clears it with the "
     "other learned flags inside the in-plant miles. (The parameter ID table gives 1930 +16 BTR_Numerator here, but "
     "block 1930's offsets drift in 11.46.) " + MIRROR),
    ("0x0040b644", "engine_at_governed_speed_flag", "engine_idling_flag", None),
]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "lifetime_distance_pulses_cal" in names:
    print("already applied")
    sys.exit(0)
for r in ROWS:
    assert not any(t in BANNED for t in r[2].split("_")), r[2]
    assert r[2] not in names, f"name taken: {r[2]}"


def find(addr, name):
    hits = [k for k, l in enumerate(g) if l.startswith(addr + "," + name + ",")]
    assert len(hits) == 1, (addr, name, len(hits))
    return hits[0]


rows = ["address,name,old_label,kind,dims"]
for a, cur, new, head in ROWS:
    i = find(a, cur)
    p = g[i].split(",", 3)
    old = p[3].strip() if len(p) > 3 else ""
    if head is None:
        comment = old.replace("1 while adjusted_user_fueling_state is 11", "1 while adjusted_user_fueling_state is 11 "
                              "(the low speed governor: idle)") + " (was engine_at_governed_speed_flag; PR #53 round 40)"
    else:
        comment = f"{head} (was {cur}; PR #53 round 40)" + (f" | earlier note: {old}" if old else "")
    g[i] = f"{a},{new},{p[2]},{comment}"
    rows.append(f"{a},{new},{cur},global,1")
    # documentation rows of the instance follow it
    for k, l in enumerate(g):
        q = l.split(",", 3)
        if len(q) > 2 and l.startswith("0x") and re.fullmatch(re.escape(cur) + r"(\[\d+\]|\.\w+)", q[1]):
            g[k] = f"{q[0]},{new}{q[1][len(cur):]}," + ",".join(q[2:])
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(ROWS)} rows renamed")
