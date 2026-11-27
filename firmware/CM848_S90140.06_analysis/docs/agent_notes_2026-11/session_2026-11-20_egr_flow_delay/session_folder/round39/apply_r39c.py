"""Round 39 stage C: the 42 scalar rows audit_cal_suffixes.py still lists as HARD (_cal outside the EEPROM mirror
0x3fd482-0x3feec1; the 39 at 0x40xxxx are ROM-copied, RAM = ROM + 0x39a3e6, and the code never writes them), plus the
RAM words of the same functions.
- 39 renamed from their code use (11 also from the e2m record the parameter ID table resolves at the address);
  3 only lose the _cal and are marked unverified.
- The supervisor chip block (cm848_writeSupervisorConfiguration / cm848_runSupervisorChipSchedule /
  cm848_runSupervisorWatchdogCycle) was J1939-named: its settings, its four configuration transmit words (now one
  word[4]) and its schedule counters (the word j1939_tx_periodic_counter is two byte counters).
Writes the proof map (address,name,old_label,kind,dims) of the label renames. Idempotent.
usage: apply_r39c.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
ROM = " ROM-copied (RAM = ROM + 0x39a3e6), never written, so no _cal"
UNVERIFIED = (" Name unverified: round 39 only removed the _cal (outside the EEPROM mirror, never written by the code)")
SUP = "cm848_writeSupervisorConfiguration (supervisor chip, QSPI PCS1)"
# (address, name now, new name, new type or None, comment)
ROWS = [
    ("0x003ff6ce", "governor_override_fuel_decay_cal", "governor_override_fuel_decay", None,
     "cm848_runOperatingModeSpeedGovernor: all_speed_governor_fueling steps down by it while the step is smaller than "
     "the remaining difference." + UNVERIFIED),
    ("0x003ff6d8", "governor_speed_lower_limit_offset_cal", "all_speed_governor_minimum_speed_offset", None,
     "e2m 107B +8 ASG_Min_RPM_Offset 'Offset used to calculate ASG minimum RPM from LSG reference speed': "
     "cm848_calculateAllSpeedGovernorThrottleReference sets governor_speed_lower_limit = "
     "low_speed_governor_desired_reference_speed - it"),
    ("0x003ffca2", "governor_rpm_error_gain_cal", "wastegate_duty_proportional_gain_rate_limit", None,
     "e2m 16A1 +A C_TGC_P_Gain_Rate_Lim 'Turbo control P_Gain rate limit imposed during P_Gain changes': "
     "cm848_calculateWastegateDutyRequest multiplies the duty band (ceiling - floor half duty counts) by it (>> 3) into "
     "the target that cm848_calculateRateLimitedValue moves wastegate_duty_proportional_term toward"),
    ("0x00407264", "high_idle_override_reset_enable_cal", "high_idle_override_reset_enable", None,
     "cm848_blendAllSpeedGovernorReferenceSpeeds: when it is set, a set high_idle_override_flag is cleared and the "
     "default blend weight is reloaded." + ROM),
    ("0x0040729c", "boost_fuel_correction_gain_cal", "turbocharger_speed_estimate_boost_lead_gain", None,
     "e2m 18CC +0 C_TSE_Boost_Lead_Gain 'Scales boost press derivative to turbo spd estimate correction offset': "
     "cm848_estimateTurbochargerSpeed multiplies it (x 0x7d) by the charge pressure change into "
     "turbocharger_speed_estimate_boost_lead_term." + ROM),
    ("0x0040868e", "protection_fuel_demand_snapshot_init_cal", "accelerator_pedal_position_high_substitute", None,
     "Value used for accelerator_pedal_position_in_use while the pedal sensor's high error is set "
     "(fault_detected_cal.pedal_position_sensor_1_high_error with two channels, fault word 0 bit 10 with one) - "
     "cm848_selectSensorValuesInUse; part of the substitute block with intake_manifold_pressure_*_substitute and "
     "coolant_temperature_*_substitute." + ROM),
    ("0x00408690", "protection_fuel_demand_snapshot_default_cal", "accelerator_pedal_position_low_substitute", None,
     "Value used for accelerator_pedal_position_in_use while bit 11 of the pedal fault word is set "
     "(pedal_position_sensor_1_low_error, fault 347, with two channels; fault word 0 bit 11 with one) - "
     "cm848_selectSensorValuesInUse." + ROM),
    ("0x00408710", "per_cylinder_timing_max_cal", "injector_driver_booster_capacitor_low_voltage_count_limit", None,
     "cm848_processFaultScanLookup (the injector driver booster capacitor monitor): while the cylinder's booster "
     "capacitor reading is at or below injector_driver_booster_capacitor_low_voltage_threshold, its "
     "per_cylinder_timing_counter counts up to this and then sets injection_check_flags; 0 turns the check off." + ROM),
    ("0x00408712", "per_cylinder_timing_max_alt_cal", "injector_driver_booster_capacitor_low_voltage_threshold", None,
     "cm848_processFaultScanLookup: at or below this raw booster capacitor reading (the record's raw value pointer) "
     "the cylinder's per_cylinder_timing_counter counts up; above it the counter counts down (final_fueling below 0x3b) "
     "or resets to 0." + ROM),
    ("0x00408740", "can_fuel_qty_scale_cal", "supervisor_watchdog_window_setting", None,
     "cm848_runSupervisorWatchdogCycle's first call sends it to the supervisor chip as register 0x18 (24): "
     "supervisor_watchdog_transmit_words[1] = (it x 1000 / 31250) & 0xff | 0x1800, the watchdog window setting." + ROM),
    ("0x00408742", "j1939_tx_periodic_rate_cal", "supervisor_watchdog_cycle_interval", None,
     "cm848_runSupervisorChipSchedule / cm848_paceSupervisorWatchdogCycle run cm848_runSupervisorWatchdogCycle "
     "every this many calls (supervisor_watchdog_cycle_counter)." + ROM),
    ("0x00408746", "j1939_status_flag_a_cal", "supervisor_register_152_bit_3_setting", None,
     SUP + " sets bit 3 of configuration register 0x98 (152) when this is not 0." + ROM),
    ("0x00408747", "j1939_status_flag_b_cal", "supervisor_register_152_bit_2_setting", None,
     SUP + " sets bit 2 of configuration register 0x98 (152) when this is not 0." + ROM),
    ("0x00408748", "j1939_status_nibble_a_cal", "supervisor_register_152_high_nibble_setting", None,
     SUP + ": bits 7-4 of configuration register 0x98 (152)." + ROM),
    ("0x00408749", "j1939_status_byte_a_cal", "supervisor_register_164_setting", None,
     SUP + ": configuration register 0xA4 (164)." + ROM),
    ("0x0040874a", "j1939_status_byte_b_cal", "supervisor_register_158_setting", None,
     SUP + ": configuration register 0x9E (158) = (this + 0xe0) & 0xff." + ROM),
    ("0x0040874c", "j1939_status_nibble_b_cal", "supervisor_register_148_low_nibble_setting", None,
     SUP + ": bits 3-0 of configuration register 0x94 (148)." + ROM),
    ("0x0040874d", "j1939_status_nibble_c_cal", "supervisor_register_148_high_nibble_setting", None,
     SUP + ": bits 7-4 of configuration register 0x94 (148) = (this x 16 + 0x80) & 0xff." + ROM),
    ("0x00408800", "cruise_speed_setpoint_default_cal", "fuel_rpm_compensated_offset_default", None,
     "cm848_computeFuelRpmCompensatedOffset: fuel_rpm_compensated_offset while main_injection_pulse_width or "
     "average_engine_speed is 0 (not a cruise speed)." + ROM),
    ("0x00408802", "fuel_quantity_active_addend_cal", "fuel_rpm_compensated_offset_pulse_width_addend", None,
     "cm848_computeFuelRpmCompensatedOffset adds it to main_injection_pulse_width before the pulse width x engine "
     "speed product." + ROM),
    ("0x00408804", "cruise_speed_upper_limit_cal", "fuel_rpm_compensated_offset_upper_limit", None,
     "cm848_computeFuelRpmCompensatedOffset: upper clamp of fuel_rpm_compensated_offset (signed; not a cruise "
     "speed)." + ROM),
    ("0x00408806", "cruise_speed_lower_limit_cal", "fuel_rpm_compensated_offset_lower_limit", None,
     "cm848_computeFuelRpmCompensatedOffset: lower clamp of fuel_rpm_compensated_offset (signed; not a cruise "
     "speed)." + ROM),
    ("0x00408810", "engine_speed_sim_mode_cal", "simulated_engine_speed_mode", None,
     "cm848_setEngineRpmFromCalibration: 1 replaces average_engine_speed and both engine_speed_state speeds with "
     "simulated_engine_speed." + ROM),
    ("0x00408812", "engine_speed_default_cal", "simulated_engine_speed", None,
     "cm848_setEngineRpmFromCalibration: the engine speed written into average_engine_speed / "
     "engine_speed_state.engine_speed / .filtered_engine_speed while simulated_engine_speed_mode is 1." + ROM),
    ("0x004088e0", "safety_fuel_blend_decrement_cal", "safety_fuel_blend_decrement", None,
     "cm848_applyFuelPressureGovernorFaultBlend: the step safety_fuel_blend_fraction falls by." + ROM),
    ("0x004088e2", "safety_fuel_blend_increment_cal", "safety_fuel_blend_increment", None,
     "cm848_applyFuelPressureGovernorFaultBlend: the step safety_fuel_blend_fraction rises by." + ROM),
    ("0x004088e4", "safety_system_enable_cal", "safety_fuel_blend_enable", None,
     "cm848_applyFuelPressureGovernorFaultBlend: 0 skips the safety fuel limit blend." + ROM),
    ("0x00408962", "battery_voltage_default_cal", "cluster_battery_voltage_during_intake_air_heating", None,
     "cm848_buildPciTransmitMessage14VoltageOilPressureTemperatures: PCI TX[14] (header 0xC0) byte 1 sends it in "
     "place of battery_voltage_sensor_filtered while intake_air_heater_status_flags bit 1 or 5 is set." + ROM),
    ("0x00408a76", "cruise_speed_target_min_cal", "cruise_speed_target_min", None,
     "cm848_calculateAcceleratorPedalDemandFromChannels: with the pedal fault latched and "
     "pedal_position_sensor_2_low_error set, the dual-channel demand is accepted while this is at most "
     "accelerator_pedal_idle_threshold_a_cal (not a cruise speed)." + UNVERIFIED),
    ("0x00408b6e", "temperature_protection_fuel_lower_cal", "park_neutral_exit_minimum_commanded_throttle", None,
     "cm848_calculateParkNeutralExitEngineSpeedLimit holds park_neutral_exit_engine_speed_limit only while "
     "commanded_throttle_state.commanded_throttle is at least this (no temperature involved)." + ROM),
    ("0x00408b70", "temperature_protection_fuel_upper_cal", "park_neutral_exit_maximum_commanded_throttle", None,
     "cm848_calculateParkNeutralExitEngineSpeedLimit: ... and at most this." + ROM),
    ("0x00408b72", "temperature_protection_trim_threshold_cal", "park_neutral_exit_maximum_vehicle_speed", None,
     "cm848_calculateParkNeutralExitEngineSpeedLimit: ... and while vehicle_speed is below this." + ROM),
    ("0x00408b76", "temperature_protection_timer_threshold_cal", "park_neutral_exit_window_duration", None,
     "cm848_calculateParkNeutralExitEngineSpeedLimit: the park / neutral exit window stays open while "
     "park_neutral_exit_window_timer (calls since park_neutral_exit_engine_speed_limit_active_flag was set) is below "
     "this." + ROM),
    ("0x00408de6", "governor_fuel_demand_mode_b_offset_cal", "low_speed_governor_exit_fuel_hysteresis", None,
     "e2m 11A3 +2 Fuel_Hysteresis 'Amt. by which Sel. User Fuel must be > Adj. User Fueling to leave LSG': "
     "cm848_limitLowSpeedGovernorFueling sets low_speed_governor_fueling = adjusted_user_fueling + it." + ROM),
    ("0x00408e96", "governor_override_fuel_threshold_cal", "governor_override_fuel_threshold", None,
     "cm848_selectCruiseOrUserFueling compares it in the cruise / user fueling selection." + UNVERIFIED),
    ("0x00408ee4", "cylinder_sync_rpm_delta_threshold_cal", "cylinder_balance_delta_speed_threshold", None,
     "e2m 81AE +2 CBD_Delta_Speed_Threshold: hpcr_cbdCalculateCylinderTrims stops the compensation when the speed "
     "change is above it (or the engine is not RUNNING)." + ROM),
    ("0x00408ee6", "fuel_demand_zero_rpm_upper_cal", "cylinder_balance_upper_speed_limit", None,
     "e2m 81AE +4 CBD_Upper_Speed_Limit: hpcr_cbdCalculateCylinderTrims' speed window upper limit." + ROM),
    ("0x00408ee8", "fuel_demand_zero_rpm_lower_cal", "cylinder_balance_lower_speed_limit", None,
     "e2m 81AE +6 CBD_Lower_Speed_Limit: hpcr_cbdCalculateCylinderTrims' speed window lower limit." + ROM),
    ("0x00408ef4", "fuel_demand_setpoint_zero_threshold_cal", "cylinder_balance_motoring_fuel_threshold", None,
     "e2m 81AE +12 CBD_Motoring_Fuel_Threshold: hpcr_cbdCalculateCylinderTrims treats cylinder_balance_filtered_fueling "
     "at or below it with final_fueling 0 as motoring." + ROM),
    ("0x00408f58", "crank_pattern_tooth_count_cal", "cam_pulse_count_with_added_tooth", None,
     "e2m 8194 +2 Cam_Count_With_Added_Tooth 'Number of cam pulses including +1 in start_sync window' (3 here): "
     "hpcr_processEngineSyncPulses compares the cam pulse count with it before the preliminary sync." + ROM),
    ("0x00408f7e", "crank_speed_setpoint_threshold_cal", "low_speed_filtering_threshold", None,
     "e2m 8194 +28 Low_Speed_Filtering_Threshold 'Speed below which special filtering is applied to speed signals': "
     "below it cm848_updateEngineSpeedFromCrankSignal loads the low speed crank windows into TPU-A channel 0 PARAM7, "
     "above it the normal ones." + ROM),
    ("0x00409072", "governor_speed_proportional_gain_cal", "equivalent_throttle_tracking_proportional_gain", None,
     "e2m 81A9 +2 Equiv_Throt_Proportional_Gain 'Equiv throttle tracking loop proportional gain': "
     "cm848_calculateAllSpeedGovernorEquivalentThrottle (next to equivalent_throttle_tracking_integral_gain)." + ROM),
    # the RAM words of the same functions
    ("0x003fb29d", "j1939_proprietary_status_byte_0", "supervisor_configuration_transmit_words", "word[4]",
     "supervisor_configuration_write_job.transmit_words: " + SUP + " fills (register << 8) | value for configuration "
     "registers 0x94 / 0x98 / 0x9E / 0xA4 (148 / 152 / 158 / 164). Was four J1939-named words "
     "j1939_proprietary_status_byte_0-3"),
    ("0x003fb29f", "j1939_proprietary_status_byte_1", "supervisor_configuration_transmit_words[1]", "",
     "register 0x98 (152) (was j1939_proprietary_status_byte_1)"),
    ("0x003fb2a1", "j1939_proprietary_status_byte_2", "supervisor_configuration_transmit_words[2]", "",
     "register 0x9E (158) (was j1939_proprietary_status_byte_2)"),
    ("0x003fb2a3", "j1939_proprietary_status_byte_3", "supervisor_configuration_transmit_words[3]", "",
     "register 0xA4 (164) (was j1939_proprietary_status_byte_3)"),
    ("0x003fb269", "j1939_tx_periodic_counter", "supervisor_watchdog_cycle_counter", "byte",
     "cm848_runSupervisorChipSchedule / cm848_paceSupervisorWatchdogCycle count calls here up to "
     "supervisor_watchdog_cycle_interval, then run cm848_runSupervisorWatchdogCycle (lbz / stb). Was byte 0 of the "
     "word j1939_tx_periodic_counter"),
    ("0x003fb26a", "j1939_tx_periodic_counter+1", "supervisor_register_46_read_counter", "byte",
     "cm848_runSupervisorChipSchedule counts calls here and queues cm848_queueSupervisorRegister46Read every 100 "
     "(lbz / stb; cm848_initSupervisorChip starts it at 1). Was byte 1 of the word j1939_tx_periodic_counter and a "
     "junk row 'j1939_tx_periodic_counter+1'"),
    ("0x003fb26b", "j1939_tx_pending_flag", "supervisor_watchdog_window_sent_flag", None,
     "cm848_runSupervisorWatchdogCycle: 0 makes the next cycle send supervisor_watchdog_window_setting (register "
     "0x18) and two register 0x2E reads, then sets it to 1; the watchdog start clears it (was j1939_tx_pending_flag)"),
    ("0x003fb26d", "diag_sequence_counter_a", "supervisor_register_162_read_counter", None,
     "cm848_runSupervisorChipSchedule queues cm848_queueSupervisorRegister162Read every 20 calls "
     "(cm848_initSupervisorChip starts it at 3; was diag_sequence_counter_a)"),
    ("0x003fb26e", "diag_sequence_counter_b", "supervisor_configuration_rewrite_counter", None,
     "cm848_runSupervisorChipSchedule calls cm848_writeSupervisorConfiguration every 100 calls while ram_refresh_enable "
     "is RAM_REFRESH_DISABLED (cm848_initSupervisorChip starts it at 2; was diag_sequence_counter_b)"),
    ("0x003fb4e0", "temperature_protection_timer", "park_neutral_exit_window_timer", None,
     "cm848_calculateParkNeutralExitEngineSpeedLimit: counts calls while park_neutral_exit_engine_speed_limit_active_flag "
     "is 1 (up to park_neutral_exit_window_duration) and is 0 otherwise; no temperature involved (was "
     "temperature_protection_timer)"),
]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "supervisor_watchdog_cycle_interval" in names:
    print("already applied")
    sys.exit(0)
for r in ROWS:
    assert not any(t in BANNED for t in re.split(r"[_\[\]]", r[2]) if t), r[2]
    assert r[2] not in names, f"name taken: {r[2]}"


def find(addr, name):
    hits = [k for k, l in enumerate(g) if l.startswith(addr + "," + name + ",")]
    assert len(hits) == 1, (addr, name, len(hits))
    return hits[0]


rows = ["address,name,old_label,kind,dims"]
for a, cur, new, typ, comment in ROWS:
    i = find(a, cur)
    p = g[i].split(",", 3)
    old_note = p[3].strip() if len(p) > 3 else ""
    if old_note and "Was " not in comment and "(was " not in comment:
        comment = f"{comment} (was {cur}; PR #53 round 39) | earlier note: {old_note}"
    elif "Was " not in comment and "(was " not in comment:
        comment = f"{comment} (was {cur}; PR #53 round 39)"
    else:
        comment = f"{comment} (PR #53 round 39)" + (f" | earlier note: {old_note}" if old_note else "")
    g[i] = f"{a},{new},{p[2] if typ is None else typ},{comment}"
    if "[" not in new and "+" not in cur:
        rows.append(f"{a},{new},{cur},global,1")
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(ROWS)} rows rewritten; {len(rows) - 1} label renames in the map")
