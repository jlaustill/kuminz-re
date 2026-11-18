import csv, json, re
from collections import Counter

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"


def load(name):
    out = {}
    for r in csv.reader(open(D + name)):
        if len(r) >= 2 and r[0].startswith("0x"):
            out.setdefault(r[0].lower(), []).append(r[1])
    return out


gv, fr, ar = load("global_variables.csv"), load("function_renames.csv"), load("arrays.csv")
existing = {n for d in (gv, fr, ar) for v in d.values() for n in v}

E = []


def fn(addr, old, new, plate, ev, verdict="confirmed"):
    E.append(dict(kind="function", address=addr, old=old, verdict=verdict, new=new,
                  plate_comment=plate, evidence=ev))


def gl(addr, old, new, ev, verdict="confirmed"):
    d = dict(kind="global", address=addr, old=old, verdict=verdict)
    if new:
        d["new"] = new
    d["evidence"] = ev
    E.append(d)


def note(text):
    E.append(dict(kind="note", text=text))


# ---------------- functions ----------------
fn("0x000234a4", "j1939FormatMultiFrameResponse", "cm848_selectEngineRetarderStagePercent",
   "Quantizes a TSC1 engine retarder torque request (0 to 100 percent, decoded from TSC1 byte 4) into a retarder stage percentage 0 / 17 / 33 / 50 / 67 / 83 / 100: the request is scaled by the full-scale torque (engine_retarder_torque_stage_6_values[4], or stage 4 when the retarder has 4 stages), then the first of engine_retarder_torque_stage_1 to 5_values whose maximum at the current rpm covers it sets the stage. Torque control (governor_mode_state 2) rounds up to the next stage, torque limit control (3) down one stage; called by cm848_j1939ProcessGovernorRequest for TSC1 addressed to the retarder source address (was j1939FormatMultiFrameResponse).",
   "Lead holds. Output is n/6 of 100 percent for the first stage n whose table maximum at current_rpm covers request x full_scale / 100 (mode 3 gives one stage lower than mode 2). Only callers are the two mode branches of cm848_j1939ProcessGovernorRequest (TSC1 PGN 0 routed by destination = j1939_source_address_b, which is also the ERC1 source address); the request is decoded as 125 - byte (SPN 518, -125 percent offset) by cm848_j1939SetupMultiFrameTransfer. The multi-frame name is wrong: nothing here touches a transport protocol.")
fn("0x00021314", "cm848_calculateSpeedControlError", "cm848_calculateEngineRetarderTorque",
   "Calculates the engine retarder torque reported in ERC1 (PGN 61440) byte 2, SPN 520: the engine_retarder_torque_stage table selected by the number of engaged retarder stages (0 to 6) at the current rpm, divided by the full-scale torque (stage 6 value [4]) and multiplied by a ramp that starts after a 2 call delay and rises 50 percent per call. The result is percent x 256 (32000 = 125 percent, 0x8300 = invalid) and 0 when no stage is engaged; called by the ERC1 builder cm848_j1939BuildVehicleOperatingStatus, which transmits 125 minus the percent (was cm848_calculateSpeedControlError).",
   "Lead holds with a scope correction: this function computes the retarder torque magnitude; the ERC1 builder (PGN 61440 header 0xF000, source address b) does the byte-2 encoding 0x7d - (value >> 8). Its only output j1939_engine_torque_encoded has that single reader. Table index = sum of per-stage weights (ROM 0x5c47e.. = 1,0,0,0,0) over bits 3-7 of fuel_demand_config_flags (logical output requests 11-15); ramp step 12800 = 50 percent x 256 and delay 2 are ROM words 0x5c48a / 0x5c48c.")
fn("0x0000ff04", "cm848_calculateFuelTrimValues", "cm848_calculateGovernorPidGains",
   "Calculates the all-speed governor's integral and proportional gains (Q10, 1024 = 1.0) from the coefficient calibrations fuel_pid_coeff2/3/6/7/8_cal and a speed scale factor, which is the blend (weighted by the gear-ratio blend weight 0..128) of the governor_speed_scale_factor_blend_0 and _128 tables at the requested speed. Integral gain = 1024 x (K - u) / (K + u) with K = 40196217 and u = scale x (coeff2 + coeff3) x (coeff6 - coeff7) / (256 - coeff8), proportional gain = (integral gain + 1024) / 2, and 1024 when the coefficients disable the adjustment. Called by cm848_initEngineOperatingMode when the speed governor starts; the results feed cm848_runOperatingModeSpeedGovernor (was cm848_calculateFuelTrimValues).",
   "Lead holds: the only outputs are governor_pid_integral_gain / governor_pid_proportional_gain (and their *_calc copies), consumed by the PID loop in cm848_runOperatingModeSpeedGovernor; there is no fuel trim here. Caveat (medium confidence on the word gains): the pair behaves like a one-pole coefficient a and (1 + a) / 2 rather than plain P and I gains. The scale-factor tables match the e2m ASG droop tables (rpm per mm3/stroke vs reference speed).")
fn("0x0000fcd0", "cm848_calculateFuelTimingBlend", "cm848_calculateAllSpeedGovernorNoLoadFuel",
   "Calculates the all-speed governor's no-load (friction) fuel reference: the friction fuel at the reference speed (speed_request_filtered, or fuel_trim_speed_request_working in operating mode 30) blended between the all_speed_governor_friction_fuel_blend_0 and _128 tables by the gear-ratio blend weight (0..128), plus the coolant temperature adjustment all_speed_governor_coolant_fuel_adjustment; the sum is governor_fuel_demand_reference. Called from cm848_runOperatingModeSpeedGovernor (was cm848_calculateFuelTimingBlend).",
   "Lead holds for the blend weight (fuel_timing_blend_factor is set from drivetrain_ratio thresholds) but the function itself computes the governor no-load fuel: output = coolant term + (w x t128 + (128 - w) x t0) >> 7. e2m ASG_No_Load_Fuel (ASNLFL: fuel required to overcome friction at the ASG reference), ASG_Friction_Fuel_* and Coolant_Fuel_Adjustment match, and cm848_calculateEffectiveFuelLimit uses it as fuel = no_load_fuel + (reference - speed) x 9813 / (8 x scale).")
fn("0x0000e8dc", "cm848_fuelTimingRateLimitedBlend", "cm848_calculateGovernorReferenceSpeedBlend",
   "Smooths the governor's reference speed: it rate-limits the requested speed (limit speed_request_rate_limit_cal per call), looks up a Q14 weight (16384 = 1.0) from the absolute difference between that and the filtered reference speed, and blends the requested and filtered reference speeds with it to give the lowest value the filtered reference may take. Runs only in engine operating mode 7, called from cm848_runOperatingModeSpeedGovernor (was cm848_fuelTimingRateLimitedBlend).",
   "Lead holds. Every input and output is an engine speed (0.125 rpm) or the Q14 weight (table speed_request_blend_weight_by_speed_difference: 0.92 at 0 rpm difference down to 0.78 at 600 rpm); no injection timing. The weight is also the smoothing weight of governor_fuel_demand_prev_ref in cm848_runOperatingModeSpeedGovernor, and in other modes it is set from the reference EMA coefficient >> 2.")
fn("0x0051a878", "governorCruiseTimerManagement", "cm848_updateOilChangeMonitor",
   "Updates the oil change monitor while it is enabled (config word mask 0x2000 and j1939_governor_feature_byte mask 0x04): it accumulates the distance since the last reset in speed-sensor pulses, the injected fuel weighted by coolant temperature and target rpm (one count per 0.01 US gallon at 100 percent weight) and a third table-driven accumulator (probably the oil soot estimate), and sets the flag at 0x40ae5e when any exceeds its threshold and the distance has reached its minimum. A J1939 proprietary command (j1939_feature_enable_cmd_flag) zeroes the accumulators (was governorCruiseTimerManagement).",
   "Proved by the code: three accumulators (distance in pulses; weighted injected fuel, one count per 557210 weighted units; a table-increment timer) compared with three consecutive dwords at DAT_00408a66 / 6a / 6e, a minimum distance DAT_003fd8ec, a warning flag and a command reset. Why it is the oil change monitor (vocabulary and layout, not proof): the enable mask 0x2000 is bit 13 like e2m OCM_Enable (OCEA, 'bit 13 of 0-15 of Word C'); the e2m has three consecutive u32 OCM_Gallons / OCM_Miles / OCM_Soot_Percentage thresholds (0x018B4E00 / 04 / 08) in the same order as the code's fuel / distance / third; the RAM dump (base 0x3fa000) holds 250000 / 120000000 / 89301300 and a minimum of 16000000, i.e. 2500 gallons (557210 counts x 0.0679 mm3 = 0.01 US gallon), 15000 miles (8000 pulses per mile) and 2000 miles; and OCM_Interval_Warning_Flag ('set when leading threshold has expired') matches the flag. Caveats: the flag at 0x40ae5e has no direct reader found by xref_addr.py (0 reads, 2 writes) and no 32-bit pointer to it in cm848_rom.bin or cm848_flash2_live.bin, so what it drives is untraced; in this truck j1939_governor_feature_byte (0x3fd902) is 0 in the RAM dump, so the body is skipped and every accumulator is 0 (RAM dump and EEPROM image).")
fn("0x000375c8", "cm848_processProtectionCoolantLookup", "cm848_calculateChargingVoltageTarget",
   "Calculates the alternator charging voltage target when engine_feature_enable_flags_cal bit 0 is set: battery_voltage_correction_default_cal if battery_voltage_correction_enable_cal is non-zero, otherwise charging_voltage_target_by_battery_temperature interpolated at battery_temperature_sensor_filtered plus charging_voltage_target_offset. The result (charging_voltage_target, was battery_voltage_prev) is the target cm848_processProtectionVoltageOffset subtracts the measured battery voltage from (was cm848_processProtectionCoolantLookup).",
   "Lead holds: the lookup input is battery_temperature_sensor_filtered (not coolant) and the tables are charging_voltage_target_by_battery_temperature_*; the output feeds the battery_voltage_delta regulator error and the SCI command 20 callback. Neither 'protection' nor 'coolant' belongs in the name.")

# ---------------- globals: retarder chain ----------------
gl("0x0040ae5a", "fuel_operation_mode_index", "engine_retarder_engaged_stage_count",
   "Only cm848_calculateSpeedControlError touches it: sum of the per-stage weights (ROM 0x5c47e / 0x5c480 / 0x5c482 / 0x5c484 / 0x5c486 = 1,0,0,0,0) over set bits 3-7 of fuel_demand_config_flags (logical output requests 11-15, byte 1 of logical_output_request_bits); it selects engine_retarder_torque_stage_<n>_values. Reading those bits as retarder stage requests is inferred from the table family.")
gl("0x003faa72", "fuel_operation_mode_count", "engine_retarder_stage_count",
   "Set once by cm848_initGovernorProtectionState to the sum of the six stage weights (1 in this ROM); j1939FormatMultiFrameResponse tests == 4 to use stage 4 value [4] instead of stage 6 value [4] as the full-scale torque.")
gl("0x0040aaa2", "j1939_engine_torque_encoded", "engine_retarder_torque_percent_times_256",
   "Written only by cm848_calculateSpeedControlError, read only by the ERC1 builder (byte 2 = 0x7d - (value >> 8), SPN 520). The value is percent x 256 (table / full-scale ratio times the ramp; 25600 = 100 percent, clamp 32000 = 125 percent, 0x8300 = invalid), 0 with no stage engaged; the scale is in the name because plain 'percent' would be 256 times off.")
gl("0x003faa78", "governor_speed_request_maximum", "engine_retarder_stage_maximum_torque",
   "Used only in j1939FormatMultiFrameResponse: the interpolated engine_retarder_torque_stage_<n>_values maximum at current_rpm for the stage being tested, compared against the scaled request (the campaign already called it a misnomer).")
gl("0x003faa76", "governor_speed_percentage_cal", "engine_retarder_full_scale_torque",
   "0x3faa76 is working RAM, so _cal is wrong. Reloaded on every call of j1939FormatMultiFrameResponse from engine_retarder_torque_stage_6_values[4] (stage_4_values[4] when fuel_operation_mode_count = 4) and used as request x value / 100; read nowhere else.")
gl("0x0040ad66", "j1939_transfer_frame_count", "engine_retarder_requested_torque_percent",
   "Written only by cm848_j1939ProcessGovernorRequest from cm848_j1939SetupMultiFrameTransfer(TSC1 byte 4): 100 below raw 25, 125 - raw up to 124, else 0 (SPN 518 requested torque, -125 percent offset, as a retarding magnitude); read by j1939FormatMultiFrameResponse and as a non-zero check in the torque control branch.")
gl("0x003faa74", "governor_output_percentage", "engine_retarder_stage_percent",
   "Output of j1939FormatMultiFrameResponse (0 / 17 / 33 / 50 / 67 / 83 / 100 = engaged stages out of 6); copied to j1939_governor_output_percent_cached / _tx by cm848_j1939ProcessGovernorRequest, where the lowest request wins in cm848_processGovernorErrorState.")
gl("0x003faa70", "j1939_governor_speed_demand", "engine_retarder_requested_torque",
   "Extra (not in the lead list): request percent x full-scale torque / 100, written and read only in j1939FormatMultiFrameResponse and compared with the stage maxima; it is a retarder torque in table units, not a speed demand.")
gl("0x003fa8aa", "throttle_demand_integrator", "engine_retarder_torque_ramp_percent_times_256",
   "Extra: used only in cm848_calculateSpeedControlError. Reset to 0 with no stage engaged, else grows by ROM 0x5c48a (12800) per call up to 0x6400 (25600 = 100 percent x 256) and multiplies the table torque; not a throttle demand.")
gl("0x003fa8ac", "injection_timing_advance_enable_count", "engine_retarder_torque_ramp_delay_count",
   "Extra: used only in cm848_calculateSpeedControlError. Counts calls up to ROM 0x5c48c (2) before the torque ramp starts, reset with no stage engaged; unrelated to injection timing.")
gl("0x0005c47e", "cal_fuel_operation_mode_1_en", "engine_retarder_stage_1_weight",
   "Extra: ROM constant (1), the first of six consecutive stage weights at 0x5c47e / 0x5c480 / 0x5c482 / 0x5c484 / 0x5c486 / 0x5c488 (values 1,0,0,0,0,0; the last five are unnamed DAT_ words). cm848_calculateSpeedControlError adds weight n to the engaged stage count when flag bit (3 + n - 1) of fuel_demand_config_flags is set; cm848_initGovernorProtectionState sums all six into fuel_operation_mode_count. ROM, so no _cal; 'en' is an invented abbreviation.")

# ---------------- globals: governor blend ----------------
gl("0x0040af7c", "fuel_timing_blend_factor", "governor_tuning_set_blend_weight",
   "Written only in cm848_calculateRpmLimitsFromProtection (first drivetrain_ratio threshold at ROM 0x5a9c6.. = 1843 / 2458 / 3482 / 6144 / 10240 / 40960, ratio x 2048, picks the weight at 0x5a9d4.., all 128 in this ROM) and at init. Weight 0..128 of the second tuning set: 0 = governor_speed_error_*_working and the *_blend_0 tables, 128 = governor_speed_error_*_b and the *_blend_128 tables.")
gl("0x003fd526", "fuel_timing_blend_counter", "governor_tuning_set_default_blend_weight_cal",
   "EEPROM-backed (mirror offset 0xa4, reads 0 in originals/cm848_eeprom.bin) and never written. cm848_initProtectionLimitVariables copies it into fuel_timing_blend_factor, cm848_calculateRpmLimitsFromProtection uses it as the blend weight when governor_system_config_flags mask 0x08 is set (drivetrain ratio selection off), and one entry condition of that function is value < 256. So it is the default tuning-set blend weight, not a counter.")
gl("0x003fa0f8", "speed_timing_blend_weight", "governor_reference_filter_weight",
   "Q14 weight (16384 = 1.0) of the previous value for the governor reference smoothing: set from the speed-difference table in cm848_fuelTimingRateLimitedBlend (mode 7) or from the reference EMA coefficient >> 2 otherwise; used for fuel_trim_speed_floor and for governor_fuel_demand_prev_ref. No timing involved. Working RAM, no _cal.")
gl("0x0040a1b0", "fuel_trim_speed_filtered", "governor_reference_speed_filtered",
   "EMA of speed_request_filtered (the reference speed) in cm848_runOperatingModeSpeedGovernor; the PID error is this minus governor_rpm_actual and cm848_calculateEffectiveFuelLimit uses (this - speed) in the droop equation. It is the filtered ASG reference speed (e2m ASG_Filtered_Reference), not a fuel trim.")
gl("0x0040a1f0", "fuel_trim_speed_floor", "governor_reference_speed_floor",
   "Written only in cm848_fuelTimingRateLimitedBlend = request x (1 - w) + filtered x w; in the mode 7 branch of cm848_runOperatingModeSpeedGovernor the filtered reference is not allowed below it.")

# ---------------- globals: oil change monitor ----------------
gl("0x003fee3e", "sensor_init_retry_timer", "oil_change_monitor_soot_accumulator_cal",
   "Third accumulator of the oil change monitor, soot by elimination: it is compared with DAT_00408a6e, the third of three consecutive threshold dwords whose first two are verified in the RAM dump as gallons (250000 = 2500 gal) and miles (120000000 = 15000 mi), and the e2m order is OCM_Gallons / OCM_Miles / OCM_Soot_Percentage (u32 at 0x018B4E00 / 04 / 08). Per call while fuel is injected it adds engine_power_accumulator_increment_values(fuel_rpm_compensated_offset) x 85048 / 900000; its units are not decoded (threshold 89301300). If the soot reading is not accepted, the neutral reading is a table-weighted engine operating accumulator (the campaign's 'engine power accumulator'). It is a dword in the EEPROM mirror (0x3fee3e - 0x3fd482 = EEPROM 0x19bc, hence _cal), zeroed by the reset command. xref_addr.py also reports byte accesses at this address from the boot-ROM functions cm848_restoreDiagnosticHandler / cm848_enableDiagnosticTimer (not inspected): if it is time-shared, give the row a TIME-SHARED comment like immobilizer_present_flag.")
gl("0x003fcee2", "governor_cruise_period_accum", "oil_change_monitor_weighted_fuel_accumulator",
   "Adds (injected_fuel_running_total delta x weight) / 100 each call and wraps into the fuel counter at 0x3fee36 above 0x8809a (557210 = 0.01 US gallon at 100 percent weight); the old comment 'scaled engine operating time' is wrong, it is weighted fuel.")
gl("0x003fcede", "governor_cruise_crank_period_snapshot", "oil_change_monitor_injected_fuel_snapshot",
   "Copy of injected_fuel_running_total taken at the end of every call of the monitor to form the delta.")
gl("0x0040b54a", "governor_cruise_period_scale_factor", "oil_change_monitor_fuel_weight_percent",
   "Output of the coolant x target rpm grid fuel_accumulation_weight_by_coolant_and_rpm_grid; divided by 100 when scaling the injected-fuel delta, so it is a percent weight.")
gl("0x0040b28a", "governor_cruise_speed_adjusted", "fuel_rpm_compensated_offset",
   "Written only by cm848_computeFuelRpmCompensatedOffset (base - (fuel_quantity_active + addend) x rpm x 6 term, clamped to cal limits, default when fuel or rpm is 0; the base falls back to injection_timing_offset_cal per that function's comment) and read only by the oil change monitor as the x input of engine_power_accumulator_increment_*. Not a speed and not cruise.")

# ---------------- globals: charging voltage ----------------
gl("0x0040b26e", "battery_voltage_prev", "charging_voltage_target",
   "Written only by cm848_processProtectionCoolantLookup (temperature-compensated target); read by cm848_processProtectionVoltageOffset as battery_voltage_delta = this - measured battery voltage and by cm848_sciCommand20Callback. It is the charging voltage setpoint, not a previous battery voltage.")

# ---------------- duplicates ----------------
gl("0x0040a550", "fuel_demand_offset_correction", "fuel_demand_offset_load_delta_correction",
   "DUPLICATE NAME. This one is written only by cm848_auxiliaryControl_tableInterpolation @ 0x5039b4: gain(rpm, engine_load_input_b) x (engine_load_normalized_prev - fuel_demand_calc_c) x 10 / 371 clamped to [DAT_00405a9c, fuel_demand_offset_correction_upper_limit] (tables fuel_demand_offset_load_delta_gain_*), and it feeds DAT_0040a556. It is read as a signed value and subtracted from fuel_demand_arbitrated when the demand reaches fuel_demand_blend_threshold_cal (cm848_processProtectionSelection, cm848_calculateFuelLimitSource).")
gl("0x0040b22a", "fuel_demand_offset_correction", None,
   "DUPLICATE NAME, KEEP this name here. Written only by cm848_calculateFuelDemandOffsetTrim from the coolant x rpm table fuel_demand_offset_correction_by_coolant_and_rpm_grid (so the table name matches); read unsigned and added to fuel demand limits by cm848_fuelDemandBlendCalculator, cm848_calculateFuelDemandLimit, cm848_calculateThermalLimitValue, cm848_processProtectionSystemBit3, cm848_calculateFuelLimitSource and cm848_calculateFuelDemandWithTrim.")
gl("0x00405a9e", "fuel_demand_offset_correction_upper_limit", "fuel_demand_offset_load_delta_correction_upper_limit",
   "Follows the 0x40a550 rename: its only use is the upper clamp of the value written to 0x40a550 in cm848_auxiliaryControl_tableInterpolation, not of the coolant x rpm offset at 0x40b22a (update its comment too).")
gl("0x0040be18", "sensor_channel7_fault_status", "sensor_channel75_fault_status",
   "DUPLICATE NAME. Disassembly: cm848_sensorChannel7_init / _process (0xd064 / 0xd0f0) load 0x40be18 (addi r10,r10,-16872) as the fault-status output with channel_index 0x4b = 75 and the sensor_channel75_linearization_* tables. The .cpp prints both addresses with the same name, so the readers (boost_pressureSource_faultSelect_update, governor_speedRamp_stabilityFlag_calc, cm848_updateFaultConditionState, cm848_protection_init_2) are only separable by xref_addr.py 0x0040be18.")
gl("0x0040be3a", "sensor_channel7_fault_status", None,
   "DUPLICATE NAME, KEEP this name here. cm848_sensorChannel9_init / _process (0xd294 / 0xd320) pass 0x40be3a (addi -16838) with channel_index 7 and sensor_channel7_value / _default_value (0x40bdd0 / 0x40bdd2), so it is the real slot 7 (fuel_temperature_linearization_* tables).")

# ---------------- notes ----------------
note("OUTSIDE THE LEADS, same chain: cm848_j1939BuildVehicleOperatingStatus @ 0x26238 builds ERC1 (PGN 61440: header 0xF000 from cm848_initJ1939SpeedControlMessage, source address j1939_source_address_b), not a vehicle operating status. Byte 1 = j1939_vehicle_op_status_byte (0x3fae08, retarder torque mode + enable bits), byte 2 = j1939_pgn61440_engine_load_byte (0x3fae09, its comment 'EEC2 engine percent load byte' is wrong: SPN 520 actual retarder percent torque, 125 - percent). Suggested: cm848_buildErc1Message, erc1_retarder_status_byte, erc1_actual_retarder_percent_torque_byte.")
note("OUTSIDE THE LEADS: cm848_j1939SetupMultiFrameTransfer @ 0x2346c decodes TSC1 byte 4 (requested torque, -125 percent offset) to a retarding magnitude 0..100 (suggest cm848_decodeRetarderTorqueRequestPercent); cm848_j1939ProcessGovernorRequest @ 0x236f0 is the TSC1 handler for the retarder source address (suggest cm848_processRetarderTorqueRequest). The governor_* / j1939_governor_output_percent_* variables around cm848_processGovernorErrorState @ 0x41a40 are the same retarder arbitration (lowest requested percent wins, initial limit 101).")
note("OUTSIDE THE LEADS: cm848_initJ1939BrakeRetarderBuffer @ 0x26480 and cm848_j1939SendDiagnosticStatusMessage @ 0x2641c serve PGN 65213 (fan drive FD1: duty 25600 * 5 >> 9 = 250 = 0.4 percent per bit), not a brake retarder.")
note("fuel_demand_config_flags (0x40c081, byte) is not a config word: it is byte 1 of logical_output_request_bits (0x40c080, outputs 8-15), an alias into that array (other readers: diagnosticMainStateProcessor, cm848_processTemperatureTrim, engine_protection_fuelCorrection_stateMachine). cm848_calculateSpeedControlError reads bits 3-7 (outputs 11-15) as retarder stage requests (inferred). Needs an alias / struct-field fix, so not renamed here. The five unnamed stage weights after engine_retarder_stage_1_weight (ROM 0x5c480 / 0x5c482 / 0x5c484 / 0x5c486 / 0x5c488) should become engine_retarder_stage_2_weight .. engine_retarder_stage_6_weight together (stage 6 has no flag in the engaged-stage sum, only in the total).")
note("lookupTableInterpolation's first argument is a per-lookup state word initialised to 2 (diag_service_slot_state_1..5, fuel_ema_mode_slot_state_1/2, diag_state_group3_a/b/c_state, diag_state_group4_*_state): the domain words in those names are wrong but they are just interpolation hints; not renamed here.")
note("governor_speed_scale_factor (0x40a258) behaves like the ASG droop (rpm per mm3/stroke at the reference speed; e2m ASG_Droop_Axis / ASG_Alt_Droop_Axis): cm848_calculateEffectiveFuelLimit uses fuel = governor_fuel_demand_reference + (filtered reference - speed) x 9813 / (8 x scale). governor_fuel_demand_reference is the ASG no-load fuel (e2m ASNLFL). speed_request_filtered is the UNfiltered reference (= speed_request_base); the filtered one is fuel_trim_speed_filtered.")
note("Unnamed drivetrain-ratio blend tables used by cm848_calculateRpmLimitsFromProtection: ROM 0x5a9c4 (axis, 6 breakpoints after the length word: 1843 / 2458 / 3482 / 6144 / 10240 / 40960 = ratio x 2048) and ROM 0x5a9d2 (6 weights, all 128 in this ROM); candidates governor_tuning_set_blend_by_drivetrain_ratio_axis / _values.")
note("If the soot reading of 0x3fee3e is accepted, the table rows engine_power_accumulator_increment_axis / _values (ROM 0x5c902 / 0x5c918, the campaign's names) should follow, e.g. oil_change_monitor_soot_increment_by_fuel_rpm_offset_axis / _values; leave them alone if the neutral reading is chosen.")
note("Oil change monitor words that need dword splits or unnamed rows (type changes, so notes only): 0x3fee34 'sensor_initialization_sequence_count' dword = high word fault-event bits (|= 4 / 0x100) + low word 0x3fee36 weighted fuel counter (suggest oil_change_monitor_fault_event_bits_cal / oil_change_monitor_fuel_count_cal); 0x3fee3a 'sensor_validation_delta' is used as a dword = distance in pulses since the reset (oil_change_monitor_distance_since_reset_cal); DAT_003fee42 = lifetime_distance_pulses at the reset (oil_change_monitor_distance_at_reset_cal); DAT_0040ae5e = the warning flag (oil_change_monitor_interval_warning_flag). Thresholds DAT_00408a66 / 6a / 6e (RAM, ROM-initialised, no _cal) = fuel / distance / third = 250000 / 120000000 / 89301300 in the RAM dump (RAM dump base is 0x3fa000: word at 0x408a60 = 2400 matches the documented constant), DAT_003fd8ec = 16000000 minimum distance (EEPROM mirror). j1939_feature_enable_cmd_flag (0x40ae60) is set by cm848_j1939HandleProprietaryCommand and cleared here after the reset (candidate oil_change_monitor_reset_request_flag, after reading that handler). fault_management_status_flags (0x3fd5b4, EEPROM mirror, 0x2e06 in the dump) is a feature config word (mask 0x2000 = oil change monitor enable), not a fault status. engine_timing_reference (0x40b766, tested != 0 here) holds a fuel quantity per the campaign leads.")
note("battery_voltage_correction_enable_cal is used inverted in cm848_processProtectionCoolantLookup (0 selects the temperature table, non-zero selects battery_voltage_correction_default_cal), so 'enable' reads backwards; the neighbours cm848_processProtectionVoltageOffset / cm848_dispatchProtectionOutputMode / cm848_filterProtectionOutput are the same charging-voltage regulator.")
note("Slot 75 (0x40be18 via cm848_sensorChannel7_*): its fault status is read by boost_pressureSource_faultSelect_update and governor_speedRamp_stabilityFlag_calc, which suggests a boost-pressure related sensor, so the governor_speed_input_value / _default_value names (0x40bd96 / 0x40bda0) on the same channel look wrong; unverified.")
note("Not renamed (insufficient evidence): fuel_timing_blend_accumulator (read in the PID loop of cm848_runOperatingModeSpeedGovernor, not a blend) and the fuel_trim_* family (fuel_trim_speed_active_flag / _upper_threshold / _lower_threshold / _decay_cal ...) around the same loop: they belong to the governor reference speed handling in mode 7, not to a fuel trim; needs its own pass.")

# ---------------- checks ----------------
bad = []
for e in E:
    if e["kind"] == "note":
        continue
    a = e["address"].lower()
    table = fr if e["kind"] == "function" else gv
    if e["old"] not in table.get(a, []):
        bad.append(("old name/address not in CSV", e["address"], e["old"], table.get(a)))
    n = e.get("new")
    if n:
        if n in existing:
            bad.append(("new name already exists", n))
        if e["kind"] == "function" and not re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", n):
            bad.append(("function name style", n))
        if e["kind"] == "global" and not re.fullmatch(r"[a-z][a-z0-9_]*", n):
            bad.append(("global name style", n))
        if re.search(r"0x|[0-9a-f]{6,}|_q\d+", n):
            bad.append(("hex or q-suffix in name", n))
        if e["kind"] == "global" and n.endswith("_cal"):
            ad = int(e["address"], 16)
            if not (0x3fd482 <= ad <= 0x3feec1):
                bad.append(("_cal outside EEPROM range", n))
        if e["kind"] == "global" and (not n.endswith("_cal")) and 0x3fd482 <= int(e["address"], 16) <= 0x3feec1:
            bad.append(("EEPROM-range name without _cal", n))
news = [e["new"] for e in E if e.get("new")]
dups = {n for n in news if news.count(n) > 1}
if dups:
    bad.append(("duplicate new names", dups))
print("PROBLEMS:", bad)
out = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G4.jsonl"
with open(out, "w") as f:
    for e in E:
        f.write(json.dumps(e) + "\n")
print(len(E), "lines;", Counter((e["kind"], e.get("verdict")) for e in E))
