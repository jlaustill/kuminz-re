"""Stage 5 (label-only): the TPE charge pressure estimate (e2m 1A22-1A29), the charge pressure in range monitor (1A2D),
the exhaust pressure estimate (198C / 1772) and sensor (channel 109, 1966 / 1963), the EGR delta pressures (1A19),
two source words (1A0C / 1A11), the predicted IMT initializer and the monitor bit of the charge pressure estimate.
Usage: apply_stage5.py <firmware output dir> <scratch dir>"""
import csv
import os
import sys

out, scratch = sys.argv[1:3]
NO_CAL = "ROM-copied RAM outside the EEPROM mirror, so no _cal."

FUNCTIONS = {
    0x00506b34: ("cm848_phase_groupA_exponentialAverage", "cm848_estimateExhaustPressure",
        "Exhaust pressure estimate (e2m 1772 +A Exhaust_Press_Est: the TPE model with the e2m 198C constants), every "
        "10 ms from cm848_phase_group_a_processing: engine speed x exhaust_pressure_estimate_engine_speed_constant / "
        "1024 + egr_valve_position x exhaust_pressure_estimate_egr_valve_position_constant / 4096 + charge_pressure x "
        "exhaust_pressure_estimate_charge_pressure_constant / 4096 + exhaust_pressure_estimate_constant, limited to "
        "0 .. 0xffff and filtered (exhaust_pressure_estimate_filter_state) into exhaust_pressure_estimate. "
        "exhaust_pressure_estimate_state (1772 +8 Exhaust_Press_EStat): 0x80 while "
        "combustion_override_and_estimation_enable_flags_cal bit 0x2000 is clear or the valve position / charge "
        "pressure source is DEFAULT, 0x40 while one is BACKUP, else 0. (was cm848_phase_groupA_exponentialAverage)"),
    0x00506c94: ("cm848_initialization_step_12", "cm848_initializeExhaustPressureEstimate",
        "Boot initialization of the exhaust pressure estimate: seeds exhaust_pressure_estimate_filter_state with the "
        "exhaust pressure sensor's filtered value (exhaust_pressure_sensor_filtered, sensor_channel_filtered_output "
        "slot 109) and points its coefficient at exhaust_pressure_estimate_filter_coefficient (e2m 198C +C "
        "C_TPE_EMP_Est_Fil_Cnst). (was cm848_initialization_step_12)"),
    0x000130ac: ("mpc555_initManifoldPressureFilter", "cm848_initializePredictedIntakeManifoldTemperature",
        "Boot initialization of the CHP predicted intake manifold temperature (e2m 1945 +0 CHP_Predicted_IMT), called "
        "by cm848_applicationMain: predicted_intake_manifold_temperature and its filter "
        "predicted_intake_manifold_temperature_filter start at intake_manifold_temperature_filtered, on the coefficient "
        "predicted_intake_manifold_temperature_filter_coefficient (e2m 1944 +2 C_CHP_Predicted_IMT_Fil_Cnst). "
        "(was mpc555_initManifoldPressureFilter)"),
    0x00013294: ("cm848_calculateBoostTorqueOffset", "cm848_estimateChargePressure",
        "Charge pressure estimate (e2m 1A23; constants 1A22, tables 1A24-1A29), from cm848_periodicTaskSet_controlLoop. "
        "It looks up charge_pressure_estimate_offset / charge_pressure_estimate_tolerance / "
        "compressor_pressure_ratio_estimate against compressor_map_corrected_turbocharger_speed and "
        "compressor_pressure_ratio_scale against engine speed. charge_pressure_estimate_unclamped = "
        "compressor_inlet_pressure x pressure ratio x scale / 0xfa000 - charge_pressure_estimate_calibration_offset, "
        "limited to 0 .. 0x3200 and filtered (charge_pressure_estimate_filter_state) into both "
        "charge_pressure_estimate_with_turbocharger_speed and charge_pressure_estimate. The state "
        "(charge_pressure_estimate_with_turbocharger_speed_state, copied to charge_pressure_estimate_state) is 0x80 "
        "while combustion_override_and_estimation_enable_flags_cal bit 0x8000 is clear, the turbocharger speed is "
        "DEFAULT or outside charge_pressure_estimate_turbocharger_speed_low_threshold .. _high_threshold, an input "
        "source (intake manifold temperature, compressor inlet temperature, barometric pressure) is DEFAULT, or the "
        "monitor condition bit charge_pressure_estimate is clear or latched; 0x40 while one of those sources or the "
        "turbocharger speed is BACKUP; else 0. (was cm848_calculateBoostTorqueOffset)"),
    0x0001350c: ("cm848_initFuelDemandFilterState", "cm848_initializeChargePressureEstimate",
        "Boot initialization of the charge pressure estimate, called by cm848_applicationMain: presets its four lookup "
        "caches to 2, seeds charge_pressure_estimate_filter_state with compressor_inlet_pressure (no boost at key on) "
        "on the coefficient charge_pressure_estimate_filter_coefficient (e2m 1A22 +6 C_TPE_ICP_Est_Filter_Constant), and "
        "clears charge_pressure_estimate_state. (was cm848_initFuelDemandFilterState)"),
    0x00013564: ("cm848_checkBoostControlCondition", "cm848_calculateChargePressureInRangeEnable",
        "e2m 1A2D +8 Charge_Press_IR_Enable: charge_pressure_in_range_enable_flag = 1 while the charge pressure sensor "
        "has no fault (map_sensor_fault_status 0) and the estimate is good (charge_pressure_estimate_state 0), else 0. "
        "Called by cm848_monitorChargePressureInRange. (was cm848_checkBoostControlCondition)"),
    0x00013774: ("cm848_processBoostProtectionConditions", "cm848_monitorChargePressureInRange",
        "Charge pressure in range monitor (e2m 1A2D): runs cm848_calculateChargePressureInRangeEnable, sets "
        "charge_pressure_in_range_condition (+6 Charge_Press_IR_Cond, 1 = suspect) when |charge_pressure_estimate - "
        "boost_pressure_sensor_value - charge_pressure_estimate_offset| exceeds charge_pressure_estimate_tolerance, runs "
        "cm848_updateChargePressureInRangeFaultCount, and writes charge_pressure_sensor_state_flags: the sensor fault "
        "status while fault bit 8 or 9 is set and enabled in charge_pressure_sensor_fault_gate_bits (bits 0 / 1), | "
        "0x20 while fault 64 or 729 is active with its fault_status_array bit 0x10 and gate bit 2 / 3, or fault 527 "
        "is set. No direct caller in the decompile. (was cm848_processBoostProtectionConditions)"),
    0x0000d17c: ("cm848_sensorChannel8_init", "cm848_sensorChannel8_exhaustPressureInit",
        "Exhaust pressure sensor channel (sensor channel 109; e2m 1966 +A Exhaust_Press_Sensor): the periodic pass "
        "(sensorChannelTypeB_configInit; the _init / _process suffixes are inverted in this firmware) on "
        "exhaust_pressure_sensor_config / exhaust_pressure_sensor_channel_state and the linearization table, fault "
        "bits 672 / 673, outputs exhaust_pressure_sensor_value / _default_value / _fault_status. "
        "(was cm848_sensorChannel8_init)"),
    0x0000d208: ("cm848_sensorChannel8_process", "cm848_sensorChannel8_exhaustPressureProcess",
        "Boot pass of the exhaust pressure sensor channel (sensorChannelTypeB_update, the same arguments as "
        "cm848_sensorChannel8_exhaustPressureInit). (was cm848_sensorChannel8_process)"),
}


def e2m(rec, desc, role, region=NO_CAL, old=None):
    return f"e2m {rec} '{desc}': {role}. {region}" + (f" (was {old})" if old else "")


G = {}  # address: (old label, new, type or None for a new row, comment)


def add(a, old, new, typ, comment):
    G[a] = (old, new, typ, comment + (f" (was {old})" if not old.startswith(("DAT_", "WORD_", "ema_", "sensor_channel_config_t_")) else ""))


add(0x0040675a, "boost_pressure_baseline_cal", "exhaust_pressure_offset", "word",
    e2m("198C +0 C_TPE_Exhaust_Pressure_Offset [IN_HG]", "Offset subtracted from Exhaust_Pressure_Sensor to calculate "
        "Exhaust_Pressure", "on the hot side EGR algorithm cm848_calculateEgrDeltaPressures takes egr_valve_delta_pressure "
        "= exhaust_pressure - this - charge_pressure"))
add(0x0040675e, "boost_synthetic_ema_boost_pressure_coef", "exhaust_pressure_estimate_egr_valve_position_constant", "word",
    e2m("198C +4 C_TPE_EMP_EGRPOS_Cnst [PSI/%OPEN]", "Exhaust pressure EGR position constant",
        "multiplies egr_valve_position (/ 4096) in cm848_estimateExhaustPressure"))
add(0x00406760, "boost_synthetic_ema_rpm_coef", "exhaust_pressure_estimate_engine_speed_constant", "word",
    e2m("198C +6 C_TPE_EMP_ESP_Cnst [PSI/RPM]", "Exhaust pressure engine speed constant",
        "multiplies engine speed (/ 1024) in cm848_estimateExhaustPressure"))
add(0x00406762, "boost_synthetic_ema_map_coef", "exhaust_pressure_estimate_charge_pressure_constant", "word",
    e2m("198C +8 C_TPE_EMP_ICP_Cnst", "Exhaust pressure charge pressure constant",
        "multiplies charge_pressure (/ 4096) in cm848_estimateExhaustPressure"))
add(0x00406766, "WORD_00406766", "exhaust_pressure_estimate_filter_coefficient", "word",
    e2m("198C +C C_TPE_EMP_Est_Fil_Cnst", "Exhaust pressure estimation filter constant",
        "the coefficient of exhaust_pressure_estimate_filter_state (cm848_initializeExhaustPressureEstimate)"))
add(0x003fbce2, "ema_filter_state_t_003fbce2", "exhaust_pressure_estimate_filter_state", "ema_filter_state_t",
    "exponentialMovingAverage record of the exhaust pressure estimate (cm848_estimateExhaustPressure -> "
    "exhaust_pressure_estimate); cm848_initializeExhaustPressureEstimate seeds it with exhaust_pressure_sensor_filtered "
    "on exhaust_pressure_estimate_filter_coefficient.")
add(0x0040bd8a, "sensor_channel109_value", "exhaust_pressure_sensor_value", "word",
    e2m("1966 +A Exhaust_Press_Sensor [IN_HG]", "Exhaust_Pressure raw value linearized and filtered",
        "the value output of the exhaust pressure sensor channel (sensor channel 109, "
        "cm848_sensorChannel8_exhaustPressureInit); the cold side measurement of cm848_calculateExhaustPressure",
        "Computed RAM."))
add(0x0040bdb0, "sensor_channel109_default_value", "exhaust_pressure_sensor_default_value", "word",
    e2m("1966 +30 Exhaust_Press_Default [IN_HG]", "Exhaust_Press_Sensor global default value",
        "the channel's config default; cm848_calculateExhaustPressure falls back to it (source 2 DEFAULT)", "Computed RAM."))
add(0x0040be2c, "sensor_channel109_fault_status", "exhaust_pressure_sensor_fault_status", "word",
    e2m("1963 +18 Exhaust_Press_Status", "Air Press Status",
        "0 in range / 1 debouncing / 2 fault confirmed / 0x100 channel not enabled; feeds exhaust_pressure_state and "
        "exhaust_pressure_source", "Computed RAM."))
add(0x0040bbca, "DAT_0040bbca", "exhaust_pressure_sensor_filtered", None,
    "sensor_channel_filtered_output slot 109: the exhaust pressure sensor's filtered engineering value (channel index "
    "0x6d of cm848_sensorChannel8_exhaustPressureInit); cm848_initializeExhaustPressureEstimate seeds the estimate "
    "filter with it. New row (it rendered DAT_0040bbca).")
add(0x003fef8a, "sensor_channel109_linearization_axis", "exhaust_pressure_sensor_linearization_axis", "word[12]",
    "Lookup table - x axis of the exhaust pressure sensor linearization (sensor channel 109, the raw ADC reading).")
add(0x003fefa2, "sensor_channel109_linearization_values", "exhaust_pressure_sensor_linearization_values", "word[12]",
    "Lookup table - the exhaust pressure (0.0159 inHg per count) at each axis point of "
    "exhaust_pressure_sensor_linearization_axis.")
add(0x0040a0ce, "sensor_channel8_ram", "exhaust_pressure_sensor_channel_state", "sensor_channel_state_t",
    "Sensor channel RAM state of the exhaust pressure sensor (channel 109) - cm848_sensorChannel8_exhaustPressureInit / "
    "_Process.")
add(0x003fef7a, "sensor_channel_config_t_003fef7a", "exhaust_pressure_sensor_config", "sensor_channel_config_t",
    "Sensor channel calibration block of the exhaust pressure sensor (channel 109): filter coefficient, default "
    "(exhaust_pressure_sensor_default_value), thresholds and debounce.")
add(0x003fa06a, "WORD_003fa06a", "exhaust_pressure_sensor_cached_axis_offset", "word",
    "Lookup cache: the last axis segment offset (2 x index) kept for exhaust_pressure_sensor_linearization_axis by the "
    "exhaust pressure sensor channel.")
add(0x003fa06c, "ema_filter_state_t_003fa06c", "exhaust_pressure_sensor_filter_state", "ema_filter_state_t",
    "EMA filter state of the exhaust pressure sensor channel (cm848_sensorChannel8_exhaustPressureInit / _Process).")
CP = [
    (0x0040510c, "boost_control_fuel_upper_threshold_cal", "charge_pressure_estimate_turbocharger_speed_high_threshold",
     "word", "1A22 +0 C_Charge_Press_Turbo_High_Thd [KRPM]", "High threshold for charge pressure turbo speed",
     "above it the estimate state is 0x80"),
    (0x0040510e, "boost_control_fuel_lower_threshold_cal", "charge_pressure_estimate_turbocharger_speed_low_threshold",
     "word", "1A22 +2 C_Charge_Press_Turbo_Low_Thd [KRPM]", "Low threshold for charge pressure turbo speed",
     "below it the estimate state is 0x80"),
    (0x00405110, "fuel_demand_correction_offset_cal", "charge_pressure_estimate_calibration_offset", "word",
     "1A22 +4 C_TPE_Charge_Press_Est_Offset [IN_HG]", "charge pressure estimate calibratible offset",
     "subtracted from the pressure ratio x inlet pressure product"),
    (0x00405112, "WORD_00405112", "charge_pressure_estimate_filter_coefficient", "word",
     "1A22 +6 C_TPE_ICP_Est_Filter_Constant", "Estimated charge pressure filter constant",
     "the coefficient of charge_pressure_estimate_filter_state"),
    (0x00405114, "fuel_timing_load_axis_cal", "charge_pressure_estimate_corrected_turbocharger_speed_axis", "word[17]",
     "1A24 +0 C_TPE_Correct_Turbo_Speed_Axis [REV/SEC/SQRT(K)]",
     "X axis for charge pressure estimate offset and tolerance lookups",
     "the compressor_map_corrected_turbocharger_speed axis shared by the offset, tolerance and pressure ratio lookups"),
    (0x00405136, "boost_fuel_threshold_offset_values_cal", "charge_pressure_estimate_offset_values", "word[17]",
     "1A25 +0 C_TPE_ICP_Est_Offset_Table [IN_HG]", "Y value for charge pressure offset lookup",
     "the values behind charge_pressure_estimate_offset (signed, flags 2)"),
    (0x00405158, "fuel_demand_rpm_axis_b_cal", "compressor_pressure_ratio_scale_axis", "word[17]",
     "1A27 +0 C_TPE_ICP_Speed_Axis [RPM]", "X axis for Pressure Ratio Scale table",
     "the engine speed axis of compressor_pressure_ratio_scale"),
    (0x0040517a, "boost_fuel_threshold_limit_values_cal", "charge_pressure_estimate_tolerance_values", "word[17]",
     "1A26 +0 C_TPE_ICP_Tolerance_Table [IN_HG]", "Y value for charge pressure tolerance lookup",
     "the values behind charge_pressure_estimate_tolerance"),
    (0x0040519c, "fuel_demand_rpm_factor_values_cal", "compressor_pressure_ratio_scale_values", "word[17]",
     "1A28 +0 C_TPE_Press_Ratio_Scale_Table", "Y axis for Pressure Ratio Scale table",
     "the values behind compressor_pressure_ratio_scale"),
    (0x004051be, "fuel_demand_base_quantity_values_cal", "compressor_pressure_ratio_estimate_values", "word[17]",
     "1A29 +0 C_TPE_Pressure_Ratio_Table", "look up table y-axis as estimated compressor pressure ratio",
     "the values behind compressor_pressure_ratio_estimate"),
]
for a, old, new, typ, rec, desc, role in CP:
    add(a, old, new, typ, e2m(rec, desc, role + " (cm848_estimateChargePressure)"))
CPR = [
    (0x0040a41e, "boost_fuel_weight_snapshot", "charge_pressure_estimate_state", "1A23 +0 Charge_Press_EStat",
     "Indicator of Charge Pressure Estimate quality", "a copy of charge_pressure_estimate_with_turbocharger_speed_state; "
     "0 lets cm848_calculateChargePressureInRangeEnable enable the in range monitor"),
    (0x0040a420, "boost_pressure_target", "charge_pressure_estimate", "1A23 +2 Charge_Press_Est [IN_HG]",
     "Estimated Charge Pressure", "the filtered estimate; the in range monitor compares it with the sensor"),
    (0x0040a422, "boost_fuel_threshold_offset", "charge_pressure_estimate_offset", "1A23 +4 Charge_Press_Est_Offset [IN_HG]",
     "Offset for Charge Pressure Estimate", "looked up from the corrected turbocharger speed; subtracted in the in "
     "range comparison"),
    (0x0040a424, "boost_fuel_threshold_limit", "charge_pressure_estimate_tolerance", "1A23 +6 Charge_Press_Tolerance [IN_HG]",
     "Tolerance used for charge pressure estimate", "the in range limit of |estimate - sensor - offset|"),
    (0x0040a426, "fuel_demand_rpm_factor", "compressor_pressure_ratio_scale", "1A23 +8 TPE_Pressure_Ratio_Scale",
     "Test point for pressure ratio scale from engine speed", "the engine speed scale of the pressure ratio"),
    (0x0040a428, "fuel_demand_base_quantity", "compressor_pressure_ratio_estimate", "1A23 +A TPE_Pressure_Ratio_Estimate",
     "Estimated compressor pressure ratio", "looked up from the corrected turbocharger speed"),
    (0x0040a42a, "boost_pressure_target_filtered", "charge_pressure_estimate_with_turbocharger_speed",
     "1A23 +C Charge_Press_Est_With_TSS [IN_HG]", "Estimated charge pressure with turbo speed sensor",
     "the filtered estimate (the same value as charge_pressure_estimate)"),
    (0x0040a42c, "boost_fuel_weight_factor", "charge_pressure_estimate_with_turbocharger_speed_state",
     "1A23 +E Charge_Press_EStat_With_TSS", "Status of estimated charge pressure with turbo speed sensor",
     "0x80 unusable / 0x40 from a BACKUP input / 0"),
]
for a, old, new, rec, desc, role in CPR:
    add(a, old, new, "word", e2m(rec, desc, role + " (cm848_estimateChargePressure)", "Computed RAM."))
add(0x003fa606, "boost_pressure_target_unclamped", "charge_pressure_estimate_unclamped", "dword",
    "compressor_inlet_pressure x compressor_pressure_ratio_estimate x compressor_pressure_ratio_scale / 0xfa000 - "
    "charge_pressure_estimate_calibration_offset before the 0 .. 0x3200 limit (cm848_estimateChargePressure).")
add(0x003fa5fe, "ema_filter_state_t_003fa5fe", "charge_pressure_estimate_filter_state", "ema_filter_state_t",
    "exponentialMovingAverage record of the charge pressure estimate (cm848_estimateChargePressure); "
    "cm848_initializeChargePressureEstimate seeds it with compressor_inlet_pressure on "
    "charge_pressure_estimate_filter_coefficient.")
for a, new, table in [(0x003fa5f6, "charge_pressure_estimate_offset_cached_axis_offset", "charge_pressure_estimate_offset_values"),
                      (0x003fa5f8, "charge_pressure_estimate_tolerance_cached_axis_offset", "charge_pressure_estimate_tolerance_values"),
                      (0x003fa5fa, "compressor_pressure_ratio_estimate_cached_axis_offset", "compressor_pressure_ratio_estimate_values"),
                      (0x003fa5fc, "compressor_pressure_ratio_scale_cached_axis_offset", "compressor_pressure_ratio_scale_values")]:
    add(a, f"DAT_{a:08x}", new, None,
        f"Lookup cache: the last axis segment offset (2 x index) that lookupTableInterpolation keeps for {table} "
        f"(cm848_estimateChargePressure); cm848_initializeChargePressureEstimate presets it to 2. New row (it rendered "
        f"DAT_{a:08x}).")
add(0x003fa60c, "fuel_mode_flags_combined", "charge_pressure_sensor_state_flags", "word",
    "Written by cm848_monitorChargePressureInRange: the charge pressure sensor fault status (map_sensor_fault_status) "
    "while fault bit 8 or 9 is set and enabled in charge_pressure_sensor_fault_gate_bits, | 0x20 while one of the gated "
    "faults (64, 729) or fault 527 is active. No reader found in the decompile.")
add(0x003ff06f, "fuel_boost_protect_fault_gate_enable", "charge_pressure_sensor_fault_gate_bits", "byte",
    "Gate bits of cm848_monitorChargePressureInRange: bits 0 / 1 let fault bits 8 / 9 pass the sensor fault status into "
    "charge_pressure_sensor_state_flags, bits 2 / 3 let faults 64 / 729 set its 0x20.")
add(0x0040a60a, "fuel_demand_state_b", "compressor_inlet_temperature_source", "word",
    e2m("1A0C +2 Compressor_Inlet_Tmptr_Source", "Source, BACKUP, DEFAULT or PRIMARY, indicator for Compressor Inlet "
        "Temperature", "0 PRIMARY / 1 BACKUP / 2 DEFAULT; an input source of the charge pressure estimate state",
        "Computed RAM."))
add(0x0040a164, "fuel_boost_mode_state", "barometric_pressure_selected_source", "i16",
    e2m("1A11 +2 Air_Press_Source", "Air Press Source: 0=PRIMARY, 1=BACKUP, 2=DEFAULT",
        "the source of barometric_pressure_selected (1A11 +0 Air_Press); an input source of the charge pressure "
        "estimate state", "Computed RAM."))
DP = [
    (0x0040a628, "egr_delta_pressure", "egr_valve_delta_pressure", "1A19 +4 EGR_Valve_Delta_Press [IN_HG]",
     "EGR_Valve_Delta_Pressure after all post-processing",
     "cold side: the EGR delta pressure sensor output; hot side: exhaust_pressure - exhaust_pressure_offset - "
     "charge_pressure (cm848_calculateEgrDeltaPressures)"),
    (0x0040a62a, "egr_delta_pressure_source", "egr_valve_delta_pressure_source", "1A19 +6 EGR_Valve_Delta_Press_Source",
     "EGR valve delta pressure measurement quality", "0 PRIMARY / 1 BACKUP / 2 DEFAULT"),
    (0x0040a62c, "egr_delta_pressure_negated", "engine_delta_pressure", "1A19 +8 Engine_Delta_Press [IN_HG]",
     "Pressure drop across the engine", "the negated EGR valve delta pressure; the pumping torque takes it from "
     "nominal_engine_delta_pressure"),
    (0x0040a62e, "egr_delta_pressure_negated_source", "engine_delta_pressure_source", "1A19 +A Engine_Delta_Press_Source",
     "Pressure drop across the engine - measurement quality", "0 PRIMARY / 1 BACKUP / 2 DEFAULT"),
]
for a, old, new, rec, desc, role in DP:
    add(a, old, new, "word", e2m(rec, desc, role, "Computed RAM."))

FIELD = ("monitor_condition_bits_t", "boost_fuel_weight_factor", "charge_pressure_estimate")

# --- apply
names_in_csvs = set()
for name in ("global_variables.csv", "function_renames.csv", "arrays.csv", "labels.csv"):
    for row in csv.reader(open(os.path.join(out, name))):
        if len(row) > 1 and row[0].startswith("0x"):
            names_in_csvs.add(row[1])
fields = {r[2] for r in csv.reader(open(os.path.join(out, "structure_definitions.csv"))) if len(r) > 2}
for new in [v[1] for v in G.values()] + [v[1] for v in FUNCTIONS.values()] + [FIELD[2]]:
    assert new not in names_in_csvs, new
assert FIELD[2] not in fields, FIELD


def rewrite(path, fn):
    lines = open(path).read().split("\n")
    out_lines = [fn(l) for l in lines]
    open(path, "w").write("\n".join(out_lines))
    return out_lines


seen = set()
UNNAMED = ("DAT_", "WORD_", "ema_filter_state_t_", "sensor_channel_config_t_")


def global_row(line):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        return line
    a = int(p[0], 16)
    if a not in G:
        return line
    old, new, typ, comment = G[a]
    seen.add(a)
    assert p[1] == ("" if old.startswith(UNNAMED) else old), (hex(a), p[1], old)
    assert typ is None or p[2] == typ, (hex(a), p[2], typ)
    return f"{p[0]},{new},{p[2]},{comment}"


path = os.path.join(out, "global_variables.csv")
lines = rewrite(path, global_row)
new_rows = sorted(a for a in G if a not in seen)
assert all(G[a][2] is None for a in new_rows), [hex(a) for a in new_rows]
for a in new_rows:
    old, new, _, comment = G[a]
    row = f"0x{a:08x},{new},word,{comment}"
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",", 1)[0], 16) > a:
            lines.insert(i, row)
            break
open(path, "w").write("\n".join(lines))


def function_row(line):
    p = line.split(",", 2)
    if not p[0].startswith("0x") or int(p[0], 16) not in FUNCTIONS:
        return line
    old, new, plate = FUNCTIONS[int(p[0], 16)]
    assert p[1] == old, p
    return f"{p[0]},{new},{plate}"


rewrite(os.path.join(out, "function_renames.csv"), function_row)


def struct_row(line):
    if line.startswith(f"{FIELD[0]},,{FIELD[1]},"):
        line = line.replace(f"{FIELD[0]},,{FIELD[1]},", f"{FIELD[0]},,{FIELD[2]},", 1)
        line = line.replace("Read by cm848_calculateBoostTorqueOffset (lwz at 0x13488, mask 0x8000; "
                            "boost_fuel_weight_factor is forced to 0x80 while the bit is clear)",
                            "The enabling condition of the charge pressure estimate: cm848_estimateChargePressure (lwz "
                            "at 0x13488, mask 0x8000) forces charge_pressure_estimate_with_turbocharger_speed_state to "
                            "0x80 while the bit is clear (was boost_fuel_weight_factor)")
    return line


lines = rewrite(os.path.join(out, "structure_definitions.csv"), struct_row)
assert sum(1 for l in lines if l.startswith(f"{FIELD[0]},,{FIELD[2]},")) == 1

with open(os.path.join(scratch, "map_stage5.csv"), "w", newline="") as f:
    w = csv.writer(f, lineterminator="\n")
    w.writerow(["address", "name", "old_label", "kind"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (old, new, _, _) in G.items():
        w.writerow([f"0x{a:08x}", new, old, "global"])
    w.writerow(["", FIELD[2], FIELD[1], "field"])
with open(os.path.join(scratch, "map_refresh_stage5.csv"), "w", newline="") as f:
    w = csv.writer(f, lineterminator="\n")
    w.writerow(["address", "name", "old_label", "kind"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (old, new, _, _) in G.items():
        if not old.startswith(UNNAMED):
            w.writerow([f"0x{a:08x}", new, old, "global"])
    for inst in ("monitor_condition_bits_t", "monitor_enabling_conditions_met", "monitor_battery_voltage_error_latch"):
        w.writerow(["", f"{inst}.{FIELD[2]}", f"{inst}.{FIELD[1]}", "token"])
print(f"functions {len(FUNCTIONS)}, globals {len(G)} ({len(new_rows)} new rows), 1 struct field")
