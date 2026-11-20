"""Items 0-13 of the functions2 bin (addresses 0x18070 .. 0x2588c). Plain data, no logic."""

ITEMS_A = []

# ---------------------------------------------------------------- 0x00018070
ITEMS_A.append({
    "address": "0x00018070",
    "old": "cm848_throttlePositionProcessing",
    "new": "cm848_calculateJ1939PercentPeakTorqueAtSpeed",
    "code_quote": "(int)(short)(param_2 + throttle_demand_offset_cal_working)) * 0x6400,",
    "evidence": (
        "param_1 is an engine speed and param_2 the friction fuel at it: cm848_dualAxisTableInterpolation("
        "&fuel_demand_threshold_interp_state, param_1, fuel_demand_rpm_threshold_cal, 400, fuel_demand_rpm_limit_low_cal, "
        "fuel_demand_rpm_limit_high_cal, 4) reads the maximum fuel grid at throttle 400 = 100 percent (the y axis reads 0 100 "
        "200 400 in the RAM dump), cm848_clampFuelDemandToValidRange clamps it, then (fuel - (param_2 + "
        "throttle_demand_offset_cal_working)) x 0x6400 / (j1939_peak_fueling_tau_0 - j1939_friction_load_fueling_at_breakpoint_4) "
        "through cm848_signedDivisionWithSaturation = percent x 256 (0x6400 = 100 x 256). Peak follows e2m 10DF +6 "
        "Jcomm_Pk_Fueling_Tau_0 'max fueling on 100% throttle curve' (the denominator) and 10E2 Jcomm_Prc_Pk_Trq_*; its only "
        "caller cm848_processThrottlePositionLookups (0x1820c) passes the idle, rated and breakpoint 3 / 4 / 5 speeds with "
        "their friction fuels. That caller has no bl and no 32-bit pointer in ROM or flash2, and the Jcomm_Prc_Pk_Trq_* words "
        "(0x40a632-0x40a63c) read 0 in the RAM dump. Wave 13 proposal taken, with J1939 added to match the 10E2 siblings "
        "(j1939_friction_load_fueling_at_breakpoint_4)."),
    "plate_comment": (
        "Percent peak torque x 256 (0x6400 = 100 percent) available at one engine speed, for the J1939 (Jcomm) engine "
        "configuration data of e2m block 10E2. param_1 is the engine speed (1/8 rpm), param_2 the friction fuel at that speed. "
        "It reads the fuel at 100 percent throttle (y = 400) at that speed from the maximum fuel grid "
        "(fuel_demand_threshold_interp_state, x axis fuel_demand_rpm_threshold_cal, y axis fuel_demand_rpm_limit_low_cal, grid "
        "fuel_demand_rpm_limit_high_cal), clamps it with cm848_clampFuelDemandToValidRange (0x1ec48), subtracts param_2 plus the "
        "coolant temperature friction correction throttle_demand_offset_cal_working, and divides by the peak fueling span "
        "j1939_peak_fueling_tau_0 (e2m 10DF +6 Jcomm_Pk_Fueling_Tau_0) minus j1939_friction_load_fueling_at_breakpoint_4 "
        "(10E2 +14) with cm848_signedDivisionWithSaturation. Returns the value that cm848_processThrottlePositionLookups "
        "(0x1820c) stores in the Jcomm_Prc_Pk_Trq_* words (10E2 +4 .. +C). No bl and no 32-bit pointer to that caller was "
        "found in either bank, and those words read 0 in the RAM dump."),
})

# ---------------------------------------------------------------- 0x0001811c
ITEMS_A.append({
    "address": "0x0001811c",
    "old": "cm848_faultSeverityEvaluation",
    "new": "cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints",
    "code_quote": "j1939_friction_load_fueling_at_breakpoint_4 =",
    "evidence": (
        "Five lookupTableInterpolation(&friction_fuel_by_engine_speed_interpolation_state, speed, "
        "friction_fuel_by_engine_speed_axis, friction_fuel_by_engine_speed_values, 0) calls at "
        "governor_output_t_0040aec2.idle_reference_speed, j1939_speed_breakpoint_3_tau_0 / _4_ / _5_ and j1939_rated_speed_tau_0 "
        "store e2m 10E2 +E / +12 / +14 / +16 / +10 (Jcomm_Frict_Load_at_Low_Idle / _at_Brkpt_3 / 4 / 5 / _at_Rated_RPM). Called "
        "by cm848_initFaultSeverityTables (0x1ea94) at start-up and by cm848_processThrottlePositionLookups (0x1820c). The ROM "
        "table at 0x5a77c / 0x5a790 reproduces the RAM dump: breakpoint 3 (11200) 97, breakpoint 4 (20800) 263, breakpoint 5 "
        "(22400) 311, rated speed (23200) 340; the idle word reads 397, the first table value, so its input was at or below "
        "3600 when it ran. Nothing here evaluates a fault severity."),
    "plate_comment": (
        "Looks up the friction (no load) fueling friction_fuel_by_engine_speed_values at five engine speeds for the J1939 "
        "(Jcomm) engine configuration data, e2m block 10E2 (MM3S, 0.0679 mm3 per count): the low speed governor idle reference "
        "speed (governor_output_t_0040aec2.idle_reference_speed) into throttle_torque_integrator_lookup (+E "
        "Jcomm_Frict_Load_at_Low_Idle), the rated speed j1939_rated_speed_tau_0 into throttle_cal_b4_lookup (+10 "
        "Jcomm_Frict_Load_at_Rated_RPM) and the speed breakpoints 3 / 4 / 5 (j1939_speed_breakpoint_3_tau_0 / _4_ / _5_, e2m "
        "10DF +A / +C / +E) into throttle_cal_b6_lookup (+12), j1939_friction_load_fueling_at_breakpoint_4 (+14) and "
        "throttle_cal_ba_lookup (+16). Called by cm848_initFaultSeverityTables (0x1ea94) at start-up and by "
        "cm848_processThrottlePositionLookups (0x1820c). RAM dump (key on, engine stopped): 340 at the rated speed and 97 / 263 "
        "/ 311 at breakpoints 3 / 4 / 5, which the ROM table gives at those speeds; 397 at idle, the first table value."),
})

# ---------------------------------------------------------------- 0x0001820c
ITEMS_A.append({
    "address": "0x0001820c",
    "old": "cm848_processThrottlePositionLookups",
    "new": "cm848_calculateJ1939PercentPeakTorquePoints",
    "code_quote": "cm848_throttlePositionProcessing(j1939_rated_speed_tau_0,(int)(short)throttle_cal_b4_lookup);",
    "evidence": (
        "Stores friction_fuel_correction_by_coolant_temperature_values at the coolant temperature in "
        "throttle_demand_offset_cal_working, calls cm848_faultSeverityEvaluation (0x1811c) for the five friction lookups, then "
        "cm848_throttlePositionProcessing (0x18070) per speed: idle reference speed -> throttle_position_from_integrator, "
        "j1939_rated_speed_tau_0 -> throttle_position_b4, breakpoints 3 / 4 / 5 -> throttle_position_b6 / b8 / ba = e2m 10E2 +A / "
        "+C / +4 / +6 / +8 (Jcomm_Prc_Pk_Trq_at_Idle / _at_Rated_RPM / _at_Brkpt_3 / 4 / 5). No caller found (no bl, no 32-bit "
        "pointer in either bank) and the six percent words read 0 in the RAM dump; not a throttle position lookup. Peak follows "
        "the e2m Jcomm_Prc_Pk_Trq_* names and the 100 percent throttle (maximum fuel) curve that cm848_throttlePositionProcessing "
        "reads."),
    "plate_comment": (
        "Calculates the J1939 (Jcomm) percent peak torque at five engine speeds, x 256, e2m block 10E2. It first stores the "
        "coolant temperature friction correction (friction_fuel_correction_by_coolant_temperature_values at "
        "sensor_readings_t_0040baf2.coolant_temp) in throttle_demand_offset_cal_working, refreshes the five friction fuels with "
        "cm848_faultSeverityEvaluation (0x1811c) and then runs cm848_throttlePositionProcessing (0x18070) for each speed with its "
        "friction fuel: the idle reference speed into throttle_position_from_integrator (+A Jcomm_Prc_Pk_Trq_at_Idle), the rated "
        "speed j1939_rated_speed_tau_0 into throttle_position_b4 (+C Jcomm_Prc_Pk_Trq_at_Rated_RPM) and the speed breakpoints 3 "
        "/ 4 / 5 into throttle_position_b6 / throttle_position_b8 / throttle_position_ba (+4 / +6 / +8). No caller was found (no "
        "bl and no 32-bit pointer to it in either bank) and the six percent words read 0 in the RAM dump."),
})

# ---------------------------------------------------------------- 0x000182e8
ITEMS_A.append({
    "address": "0x000182e8",
    "old": "cm848_calculateThrottleProtectionLimit",
    "new": "cm848_calculateJ1939PercentPeakTorque",
    "code_quote": "(((int)(short)final_fueling - (int)(short)fuel_demand_base_offset_snapshot) *",
    "evidence": (
        "fuel_demand_base_offset_snapshot = fuel_demand_base_offset (e2m 10E2 +0 Jcomm_No_Load_Torque), "
        "j1939_friction_load_fueling_at_breakpoint_4 is looked up again at j1939_speed_breakpoint_4_tau_0, and "
        "throttle_protection_load_ratio = (final_fueling - snapshot) x 0x6400 / (j1939_peak_fueling_tau_0 - "
        "j1939_friction_load_fueling_at_breakpoint_4) via cm848_signedDivisionWithSaturation = e2m 10E2 +2 "
        "Jcomm_Percent_Peak_Torque 'based on current engine speed and temperature' (percent x 256). No caller found (no bl, no "
        "32-bit pointer in either bank); the snapshot and the ratio read 0 in the RAM dump; it limits no throttle. Peak follows "
        "e2m Jcomm_Percent_Peak_Torque and Jcomm_Pk_Fueling_Tau_0 ('max fueling on 100% throttle curve'), the top of the span "
        "in the denominator."),
    "plate_comment": (
        "Calculates the J1939 (Jcomm) percent peak torque of the current operating point, e2m 10E2 +2 "
        "Jcomm_Percent_Peak_Torque (percent x 256, 'based on current engine speed and temperature'), into "
        "throttle_protection_load_ratio, and records the no load fuel fuel_demand_base_offset in "
        "fuel_demand_base_offset_snapshot (+0 Jcomm_No_Load_Torque). It looks up the friction fuel at the speed breakpoint 4 "
        "(friction_fuel_by_engine_speed_values at j1939_speed_breakpoint_4_tau_0) into j1939_friction_load_fueling_at_breakpoint_4 "
        "(+14) and divides (final_fueling - fuel_demand_base_offset_snapshot) x 0x6400 by j1939_peak_fueling_tau_0 (e2m 10DF +6) "
        "minus that friction fuel with cm848_signedDivisionWithSaturation. No caller was found (no bl and no 32-bit pointer to it "
        "in either bank) and its two result words read 0 in the RAM dump."),
})

# ---------------------------------------------------------------- 0x0001b3a0 (shared with CM550 0x3320e)
ITEMS_A.append({
    "address": "0x0001b3a0",
    "old": "faultTimerHandler",
    "new": "cm848_buildPgn65251EngineConfiguration1Payload",
    "code_quote": "(char)(j1939_pgn61442_engine_overspeed_enable_time_limit / 10));",
    "evidence": (
        "PGN proof in initFaultTimerMessage (0x1b900): j1939_pgn65251_tx_message.header.can_id is built from the constant "
        "0xfee300 (PGN 65251), data_length = 0x1c = 28 and data_pointer = fault_timer_state_base; cm848_sendFaultTimerMessage "
        "(0x1b730) calls this function on that buffer and then sendJ1939Message(&j1939_pgn65251_tx_message). The 7 dwords it "
        "stores decode as the 28 bytes of Engine Configuration 1: SPN 188 / 539 (idle, point 1), 528 / 540, 529 / 541, 530 / "
        "542, 531 / 543, 532 (high idle, point 6), 545 (0xffff), 544 (reference_engine_torque_working), 533 / 534 (ROM 0x5c39a "
        "and the time limit / 10 = 0.1 s per bit), 535 / 536 (/ 0x50 = 10 rpm per bit), 537 / 538; the local automotive DB table "
        "j1939_spns lists exactly these SPNs and resolutions for PGN 65251. It fills a buffer and sends nothing, so Payload, not "
        "Message. SHARED: faultTimerHandler is also CM550 0x3320e (function_renames.csv), so the main session holds this rename."),
    "plate_comment": (
        "Fills the 28-byte payload of the J1939 engine configuration message, PGN 65251 (Engine Configuration 1), into the "
        "buffer param_1 (fault_timer_state_base; the transmit descriptor j1939_pgn65251_tx_message has its can_id built from "
        "0xfee300 and length 28, set by initFaultTimerMessage at 0x1b900). First it refreshes the torque curve with "
        "governor_calculateIntegratorRpmOutput (0x507a20, the fault derate speed points) and cm848_updateProtectionStateMachine "
        "(0x20d10). Then, byte swapped to J1939 little endian, it stores: the speeds and percent torques of curve points 1-5 "
        "(e2m 1102 Jcomm_Determined_RPM_Point_1-5 at +16 / +12 / +18 / +1A / +14, SPN 188 / 528 / 529 / 530 / 531; the high byte "
        "of j1939_indicated_percent_torque_at_* plus 125, SPN 539 .. 543), the high idle speed of point 6 "
        "(engine_speed_limit_arbitration.lowest_source_speed_limit, or the droop corrected limit capped at 0xfaff, SPN 532), "
        "0xffff for the endspeed governor gain (SPN 545), reference_engine_torque_working (1102 +1E, SPN 544), the maximum "
        "momentary override speed ROM 0x5c39a (e2m 10E7 +18 Jcomm_High_Idle_Override_Speed, SPN 533) and its time limit "
        "j1939_pgn61442_engine_overspeed_enable_time_limit / 10 (SPN 534), the speed control range limits governor_rpm_limit_cal "
        "/ 80 and engine_speed_limit_maximum / 80 (10 rpm per bit, SPN 535 / 536) and the torque control range, 0 percent and the "
        "largest point torque (SPN 537 / 538). It sends nothing: cm848_sendFaultTimerMessage (0x1b730, registered for PGN 65251 "
        "in the periodic transmit queue) and cm848_processFaultMessageTiming (0x1b778, which resends when a value changed) call it "
        "and send the descriptor."),
})

# ---------------------------------------------------------------- 0x00020500
ITEMS_A.append({
    "address": "0x00020500",
    "old": "cm848_calculateProtectionActivationDelay",
    "new": "cm848_calculateJ1939ReferenceEngineFueling",
    "code_quote": "(word)((((uint)injection_quantity_combustion_chi_maximum - (uint)friction_fueling) * 10000)",
    "evidence": (
        "When algorithm_enable_flags_41_cal.reserved_bit_11 (guessed e2m Torque_Normalization_Enable; 31910 = 0x7ca6 in the dump, "
        "bit set) is set: j1939_reference_engine_fueling = (injection_quantity_combustion_chi_maximum - friction_fueling) x "
        "10000 / ((fuel_demand_filter_dimension x 0x34f6) / reference_engine_torque_working). Reproduced from the RAM dump: (1030 "
        "- 397) x 10000 / ((290 x 13558) / 850) = 1368 = j1939_reference_engine_fueling (0x40ada6), while the ROM "
        "j1939_peak_fueling (0x5c348) reads 1501, so the computed branch is live. fuel_demand_filter_dimension is the lb-ft "
        "value of the e2m MT_Max_Torque_Map at the current engine speed (see 0x21ac0); 13558 / 10000 is 1.3558 N*m per lb-ft. "
        "Called by cm848_periodicTaskSet_sensorProcessing. No activation delay of any protection."),
    "plate_comment": (
        "Recomputes the J1939 (Jcomm) reference engine fueling j1939_reference_engine_fueling (e2m 1102 +1C "
        "Jcomm_Reference_Engine_Fueling, 'Determined Peak Engine Fueling', MM3S) when bit 11 of algorithm_enable_flags_41_cal is "
        "set (guessed e2m Torque_Normalization_Enable; set in this calibration): (injection_quantity_combustion_chi_maximum - "
        "friction_fueling) x 10000 / ((fuel_demand_filter_dimension x 13558) / reference_engine_torque_working). "
        "fuel_demand_filter_dimension is the maximum torque in lb-ft at the current engine speed (e2m MT_Max_Torque_Map, "
        "cm848_calculateFuelDemandFilter at 0x29c98); x 13558 / 10000 turns it into N*m, so the net full load fuel is scaled by "
        "the reference engine torque (e2m 1102 +1E, 850 N*m) over that torque. RAM dump (key on, engine stopped): (1030 - 397) x "
        "10000 / ((290 x 13558) / 850) = 1368 = j1939_reference_engine_fueling, against 1501 = j1939_peak_fueling (ROM, e2m 1104 "
        "+0) that cm848_initProtectionDelayDefaults (0x212dc) loads. Called from cm848_periodicTaskSet_sensorProcessing."),
})

# ---------------------------------------------------------------- 0x000209e8
ITEMS_A.append({
    "address": "0x000209e8",
    "old": "cm848_calculateLoadRateOfChange",
    "new": "cm848_calculateActualEnginePercentTorque",
    "code_quote": "((short)(final_fueling - fuel_demand_norm_zero_cal) * 0x6400,",
    "evidence": (
        "Sets actual_engine_percent_torque_times_256 (e2m 1102 +0 Jcomm_Actual_Engine_Ind_Torque): 0 when final_fueling equals "
        "fuel_demand_norm_zero_cal (e2m 10E7 +16 FSS_Zero_Torque_Fueling, 0 in ROM 0x5c398), else "
        "cm848_clampedDivisionWithBounds((final_fueling - zero) x 0x6400, j1939_reference_engine_fueling - zero, 32000, -32000) = "
        "percent x 256 clamped to plus or minus 125 percent. Its high byte + 125 is the EEC1 actual percent torque byte (SPN 513) "
        "in j1939GetEngineStateCode (0x2588c); cm848_runEmissionManager also calls it. It is a ratio of fuelings, not a load rate "
        "of change."),
    "plate_comment": (
        "Calculates the actual engine percent torque x 256, actual_engine_percent_torque_times_256 (e2m 1102 +0 "
        "Jcomm_Actual_Engine_Ind_Torque, 'calculated output torque of the engine'): 0 when final_fueling equals the zero torque "
        "fueling fuel_demand_norm_zero_cal (ROM 0x5c398, e2m 10E7 +16 FSS_Zero_Torque_Fueling), otherwise (final_fueling - zero) "
        "x 0x6400 / (j1939_reference_engine_fueling - zero), clamped to 32000 and -32000 (plus or minus 125 percent x 256) by "
        "cm848_clampedDivisionWithBounds. Its high byte plus 125 is the EEC1 actual engine percent torque (SPN 513) in "
        "j1939GetEngineStateCode (0x2588c); cm848_runEmissionManager calls it too."),
})

# ---------------------------------------------------------------- 0x00020a58
ITEMS_A.append({
    "address": "0x00020a58",
    "old": "cm848_calculateLoadToFuelRatio",
    "new": "cm848_calculateEnginePercentLoadAtCurrentSpeed",
    "code_quote": "else if ((short)(throttle_100_fueling - fuel_demand_norm_zero_cal) < -31999) {",
    "evidence": (
        "j1939_engine_percent_load_at_current_speed_times_256 (e2m 1102 +4 Jcomm_Ind_Percent_Load 'ratio of actual engine torque "
        "to max torque at current speed') = (final_fueling - fuel_demand_norm_zero_cal) x 0x6400 / (throttle_100_fueling - "
        "fuel_demand_norm_zero_cal) via cm848_saturatingDivision16, 0x8300 (-32000) when a difference is below -31999, capped at "
        "32000. Its only caller cm848_buildPgn61443ElectronicEngineController2Message (0x25b10) sends the high byte as EEC2 byte "
        "3 (j1939_eec2_percent_load_byte, SPN 92 percent load at current speed). The denominator is the 100 percent throttle "
        "(maximum) fuel curve at the current speed."),
    "plate_comment": (
        "Calculates the engine percent load at current speed x 256, j1939_engine_percent_load_at_current_speed_times_256 (e2m "
        "1102 +4 Jcomm_Ind_Percent_Load, 'ratio of actual engine torque to max torque at current speed'; SPN 92 of EEC2): "
        "(final_fueling - fuel_demand_norm_zero_cal) x 0x6400 / (throttle_100_fueling - fuel_demand_norm_zero_cal), i.e. the "
        "actual torque as a share of the torque of the 100 percent throttle fuel curve at the current speed (throttle_100_fueling, "
        "e2m 105A +0). The result is 0x8300 (-32000, minus 125 percent) when either fuel difference is below -31999 and is capped "
        "at 32000 (125 percent). Called by cm848_buildPgn61443ElectronicEngineController2Message (0x25b10), whose byte 3 is the "
        "high byte."),
})

# ---------------------------------------------------------------- 0x00020c64
ITEMS_A.append({
    "address": "0x00020c64",
    "old": "cm848_processJ1939RxMessage",
    "new": "cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling",
    "code_quote": "engine_speed_limit_ramped_maximum_fuel_quantity - (int)rx_msg) * 8 & 0xfff8))",
    "evidence": (
        "r3 is a fueling (decompiled as the pointer rx_msg) and r4 a flag (in_r4): speed = engine_speed_limit_arbitrated + "
        "engine_speed_limit_droop_slope x (((engine_speed_limit_ramped_maximum_fuel_quantity - fueling) x 8) & 0xfff8) / 0x8888, "
        "capped at 40000, or torque_limit_working_reference when the slope is 0; stored in j1939_torque_curve_speed_at_point_2 and "
        "_5 (e2m 1102 +24 / +2A; _5 becomes the ROM protection_threshold_base_cal = 1104 +8 Jcomm_Engine_Speed_at_Point_5 when r4 "
        "is 0), the fueling in j1939_torque_curve_fueling_at_point_2 and _5 (+2E / +34). The asm at 0x20f00-0x20f24 shows the "
        "caller passing j1939_derated_fueling_at_point_4 with li r4,1 when ROM 0x5c35e (1104 +16 "
        "Jcomm_Tau_0_Point_5_Intersection_Speed, 16000) is above the speed limit, else j1939_derated_fueling_at_point_5 with li "
        "r4,0. It receives no J1939 message. Wave 13 proposals taken as the literal form (bin 1) rather than the breakpoint form "
        "(bin 2), which omits point 5."),
    "plate_comment": (
        "Sets points 2 and 5 of the J1939 (Jcomm) torque curve of the engine configuration message from one fueling on the "
        "engine speed limit droop line. The fueling arrives in r3 (decompiled as the pointer parameter rx_msg) and a flag in r4. "
        "The speed is the droop line speed at that fueling: engine_speed_limit_arbitrated + engine_speed_limit_droop_slope x "
        "(((engine_speed_limit_ramped_maximum_fuel_quantity - fueling) x 8) & 0xfff8) / 0x8888, capped at 40000 (5000 rpm), or "
        "torque_limit_working_reference when engine_speed_limit_droop_slope is 0. It stores that speed in "
        "j1939_torque_curve_speed_at_point_2 (e2m 1102 +24 Jcomm_RPM_At_Point_2, the high speed governor breakpoint) and in "
        "j1939_torque_curve_speed_at_point_5 (+2A; with r4 = 0 point 5 gets the ROM speed protection_threshold_base_cal instead, "
        "e2m 1104 +8 Jcomm_Engine_Speed_at_Point_5) and the fueling in j1939_torque_curve_fueling_at_point_2 (+2E) and "
        "j1939_torque_curve_fueling_at_point_5 (+34). Its only caller cm848_updateProtectionStateMachine (0x20d10) passes "
        "j1939_derated_fueling_at_point_4 with r4 = 1 when ROM 0x5c35e (e2m 1104 +16 Jcomm_Tau_0_Point_5_Intersection_Speed) is "
        "above the speed limit, otherwise j1939_derated_fueling_at_point_5 with r4 = 0. It receives no J1939 message."),
})

# ---------------------------------------------------------------- 0x00020d10
ITEMS_A.append({
    "address": "0x00020d10",
    "old": "cm848_updateProtectionStateMachine",
    "new": "cm848_updateJ1939EngineConfigurationTorqueCurve",
    "code_quote": "j1939_indicated_percent_torque_at_idle_times_256 =",
    "evidence": (
        "Builds the e2m 1102 torque curve of PGN 65251: a mode index (+4 governor_speed_limit_output outside the "
        "governor_output_t_0040aec2.idle_reference_speed +- low_speed_governor_reference_speed_delta band, +2 altitude or air "
        "fuel control derate in torque_derate_fuel_source_code, +1 engine_speed_limit_arbitration.limiting_source_number 1 / 2 / "
        "4 / 5 / 12) picks the point speeds and fuelings from cm848_updateProtectionParameters (0x20b84), "
        "cm848_updateProtectionInputs (0x20bfc), cm848_processJ1939RxMessage (0x20c64) and the derated ROM values (e2m 1104 "
        "Jcomm_Derated_Fueling_*, Jcomm_Tau_0 / Tau_1_Derated_*); then j1939_indicated_percent_torque_at_idle_times_256 / "
        "_point_2_ / protection_speed_ratio_c / protection_speed_ratio_d / _point_5_ (1102 +8 .. +10) = "
        "cm848_clampedDivisionWithBounds((fueling - fuel_demand_norm_zero_cal) x 0x6400, governor_speed_ref_channel_a..e - zero, "
        "32000, -32000), caches the determined speeds (+12 .. +1A) and Calc fuelings (+36 .. +3E), and resets the working fuelings "
        "to fuel_demand_maximum. No protection state machine. Called by faultTimerHandler (0x1b3a0) before the PGN 65251 payload "
        "is filled."),
    "plate_comment": (
        "Builds the J1939 (Jcomm) engine configuration torque curve of PGN 65251, e2m block 1102: the speeds, fuelings and "
        "indicated percent torques at points 1-5. A mode index is formed from the situation: +4 when governor_speed_limit_output "
        "is outside the low speed governor idle band (governor_output_t_0040aec2.idle_reference_speed plus or minus "
        "low_speed_governor_reference_speed_delta), +2 for an altitude derate or an air fuel control derate with a fault in bits 8 "
        "/ 9 of fault_detected_bits_0_to_15 (torque_derate_fuel_source_code), +1 when the engine speed limit source "
        "(engine_speed_limit_arbitration.limiting_source_number) is 1 / 2 / 4 / 5 / 12. Its cases load the point speeds and "
        "fuelings from the derated ROM values (e2m 1104 Jcomm_Engine_Speed_at_Point_3-5, Jcomm_Derated_Fueling_at_Idle-Point_5 "
        "and the tau 0 / tau 1 derated point 2, chosen by thermal_fuel_limit_factor) with cm848_updateProtectionParameters "
        "(0x20b84), cm848_updateProtectionInputs (0x20bfc) and cm848_processJ1939RxMessage (0x20c64). Each percent torque is "
        "(fueling at the point - fuel_demand_norm_zero_cal) x 0x6400 / (reference fueling at the point - zero) clamped to plus or "
        "minus 32000, with the reference fuelings governor_speed_ref_channel_a..e (+40 .. +48), into "
        "j1939_indicated_percent_torque_at_idle_times_256, _point_2_, protection_speed_ratio_c, protection_speed_ratio_d and "
        "_point_5_ (+8 .. +10). It caches the determined speeds (+12 .. +1A) and the calculated fuelings (Jcomm_Calc_Fueling_At_"
        "Point_1-5, +36 .. +3E) and then resets the working fuelings to fuel_demand_maximum, which "
        "cm848_updateProtectionDiagnostics (0x21cd4) lowers again. Called by faultTimerHandler (0x1b3a0) before each PGN 65251 "
        "payload is filled."),
})

# ---------------------------------------------------------------- 0x000212dc
ITEMS_A.append({
    "address": "0x000212dc",
    "old": "cm848_initProtectionDelayDefaults",
    "new": "cm848_initializeJ1939ReferenceEngineFuelingAndTorque",
    "code_quote": "reference_engine_torque_working = j1939_reference_engine_torque;",
    "evidence": (
        "While algorithm_enable_flags_18_cal.programmable_power_enable is 0: j1939_reference_engine_fueling = j1939_peak_fueling "
        "(ROM, e2m 1104 +0 Jcomm_Peak_Fueling, 1501 in the ROM = 102.0 mm3) and reference_engine_torque_working = "
        "j1939_reference_engine_torque (1104 +2, 850 N*m). Called by initFaultTimerMessage (0x1b900), the PGN 65251 "
        "initialization; no protection delay is set."),
    "plate_comment": (
        "Initializes the J1939 (Jcomm) reference values of the engine configuration message from the ROM: while the algorithm "
        "flag programmable_power_enable (algorithm_enable_flags_18_cal) is 0 it copies the peak fueling j1939_peak_fueling (e2m "
        "1104 +0 Jcomm_Peak_Fueling, 1501 in the ROM = 102.0 mm3) into j1939_reference_engine_fueling (e2m 1102 +1C) and the "
        "reference engine torque j1939_reference_engine_torque (1104 +2 Jcomm_Reference_Engine_Torque, 850 N*m) into "
        "reference_engine_torque_working (1102 +1E). Called by initFaultTimerMessage (0x1b900), the PGN 65251 initialization; "
        "cm848_calculateProtectionActivationDelay (0x20500) recomputes the fueling afterwards when torque normalization is on."),
})

# ---------------------------------------------------------------- 0x00021ac0
ITEMS_A.append({
    "address": "0x00021ac0",
    "old": "cm848_initUdsServiceHandlers",
    "new": "cm848_lookupMaximumTorqueAtEngineSpeed",
    "code_quote": "(local_30,param_1,j1939_fuel_table_xaxis_cal,0,j1939_fuel_table_ystart_cal,",
    "evidence": (
        "Three cm848_dualAxisTableInterpolation calls over j1939_fuel_table_xaxis_cal (ROM 0x5c556 = e2m 140E MT_RPM_Axis), "
        "j1939_fuel_table_ystart_cal (0x5c582 = e2m 1447 MT_Alpha_Axis) and the grid j1939_fuel_table_yend_cal that follows it at "
        "0x5c58e (the Z record e2m MT_Max_Torque_Map [FT*LB] names axes 140E:1447; its own block 1460 is not in the dumped ID "
        "table), at y = 0 and at y = chi map number x 0x4000 for the lower and upper chi maps, blended by "
        "cm848_interpolateAlphaChiValue like the maximum fuel curve. The ROM grid reads 385 .. 600 .. 589 .. 295 .. 0 over "
        "800 .. 3500 rpm, a lb-ft curve peaking at 600, not fuel. With 0x34f6 = 13558 (1.3558 N*m per lb-ft) and 850 N*m the "
        "RAM dump reproduces 1368 in cm848_calculateProtectionActivationDelay (0x20500), where 290 is the twin "
        "cm848_calculateFuelDemandFilter (0x29c98) at speed 0. Maximum, by use: it is the full load torque paired with "
        "injection_quantity_combustion_chi_maximum in the engine_torque_estimate formula. Wave 13 read it as a fuel table "
        "because of the borrowed j1939_fuel_table_* names; no UDS service is involved."),
    "plate_comment": (
        "Returns the maximum engine torque in lb-ft at the engine speed param_1 (1/8 rpm): the e2m MT_Max_Torque_Map (Table with "
        "max torque corresp. to MTTQMPXA values; engine speed axis 140E MT_RPM_Axis x alpha axis 1447 MT_Alpha_Axis, 600 lb-ft at "
        "its peak in the ROM grid). The ROM rows named j1939_fuel_table_xaxis_cal / j1939_fuel_table_ystart_cal / "
        "j1939_fuel_table_yend_cal (0x5c556 / 0x5c582 / 0x5c58e) are this torque map, not a fuel table. It looks the grid up with "
        "fresh cache words at the alpha 0 row and at the two chi map rows combustion_chi_lower_map_number / "
        "combustion_chi_upper_map_number (x 0x4000) and blends them with cm848_interpolateAlphaChiValue (0x14528) by the chi and "
        "alpha of combustion_reference_state, as cm848_lookupChiMaximumFuelAtSpeed (0x164e4) does for the maximum fuel. "
        "cm848_calculateFuelDemandFilter (0x29c98) does the same at the current engine speed into fuel_demand_filter_dimension. "
        "Called by cm848_updateProtectionDiagnostics (0x21cd4) with the five torque curve speeds."),
})

# ---------------------------------------------------------------- 0x00021cd4
ITEMS_A.append({
    "address": "0x00021cd4",
    "old": "cm848_updateProtectionDiagnostics",
    "new": "cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings",
    "code_quote": "wVar2 = cm848_lookupChiMaximumFuelAtSpeed(governor_integrator_rpm_output);",
    "evidence": (
        "protection_mode_request_bit = 1 << throttle_100_priority_bit_index (e2m 12BD +A). While programmable_power_enable is 0 it "
        "sets that bit in j1939_pgn65251_speed_points_request_flags, cm848_updateProtectionThresholdsIfLow (0x21c3c) writes the "
        "point speeds, and cm848_lookupChiMaximumFuelAtSpeed at the five point speeds gives the maximum fuels. Reference fuelings "
        "governor_speed_ref_channel_a..e (e2m 1102 +40 .. +48): j1939_reference_engine_fueling at every point when "
        "algorithm_enable_flags_41_cal bit 11 is clear, else maximum fuel / ((cm848_initUdsServiceHandlers(speed) x 0x34f6) / "
        "reference_engine_torque_working) - asm 0x21dd8-0x21dfc is bl 0x21ac0, mulli 13558, divw, divwu with no x 10000 and no "
        "friction term, unlike 0x20500. The divisor (torque x 13558) / 850 is 3939 for 247 lb-ft up to 9570 for 600 lb-ft over "
        "the grid below its last column (that column is 0, where the divisor would be 0), so fuels of 1030 .. 2082 counts "
        "(the chi maximum fuel range) give a quotient of 0; the dump (31910 = 0x7ca6 in algorithm_enable_flags_41_cal, bit 11 "
        "set) reads 0 in all five words. Fuelings (1102 +2C .. +34): when "
        "throttle_100_fueling_point_clamp_bitmap & cm848_getHighestPriorityBit() is non-zero the existing values are only lowered "
        "to the maximum fuel, else they are replaced by it unless a higher priority request bit is set (early return). Called by "
        "cm848_periodicTaskSet_diagnostics2."),
    "plate_comment": (
        "Sets the fueling points of the J1939 (Jcomm) torque curve and the reference fuelings that scale them into percent "
        "torque, e2m block 1102, for the throttle 100 request of PGN 65251. On first use protection_mode_request_bit = 1 << "
        "throttle_100_priority_bit_index (e2m 12BD +A Throttle_100_Priority). While programmable_power_enable is 0 it sets that "
        "bit in j1939_pgn65251_speed_points_request_flags, lets cm848_updateProtectionThresholdsIfLow (0x21c3c) write the point "
        "speeds from the broadcast overrides when no higher priority bit is set, and takes the maximum fuel of the chi curve at "
        "each of the five point speeds (cm848_lookupChiMaximumFuelAtSpeed, 0x164e4). The reference fuelings "
        "governor_speed_ref_channel_a..e (1102 +40 .. +48 Jcomm_Reference_Fueling_At_Point_1-5) are j1939_reference_engine_fueling "
        "at every point when torque normalization (algorithm_enable_flags_41_cal bit 11) is off, otherwise that maximum fuel "
        "divided by ((maximum torque at the point speed x 13558) / reference_engine_torque_working), the torque coming from "
        "cm848_initUdsServiceHandlers (0x21ac0). There is no x 10000 as in cm848_calculateProtectionActivationDelay (0x20500): "
        "the divisor is 3939 (247 lb-ft) to 9570 (600 lb-ft), so a fuel of about 1000 .. 2000 counts gives a quotient of 0, and "
        "all five words read 0 in the RAM dump. When "
        "the highest set request bit (cm848_getHighestPriorityBit, 0x21bf8) is in throttle_100_fueling_point_clamp_bitmap (e2m "
        "12BD +8 Throttle_100_Min_Config), protection_cal_level1_working (point 1) and j1939_torque_curve_fueling_at_point_2 .. 5 "
        "(e2m 1102 +2C .. +34) are only lowered to the maximum fuel; otherwise they are replaced by it, unless a higher priority "
        "request bit is set. Called by cm848_periodicTaskSet_diagnostics2."),
})

# ---------------------------------------------------------------- 0x0002588c (shared with CM550 0x32c76)
ITEMS_A.append({
    "address": "0x0002588c",
    "old": "j1939GetEngineStateCode",
    "new": "cm848_buildPgn61444ElectronicEngineController1Message",
    "code_quote": "sendJ1939Message(&j1939_pgn61444_tx_message);",
    "evidence": (
        "PGN proof in cm848_initEec1TxDescriptor (0x25ab8): j1939_pgn61444_tx_message.header.can_id is built from the constant "
        "0xf00400 (PGN 61444), data_length 5, data pointer j1939_engine_status_byte; this function fills those bytes and ends "
        "with sendJ1939Message(&j1939_pgn61444_tx_message); the periodic queue registers it for header 0xf004 (diag_record_queue_"
        "add_entry(0,0xf004,0x14,0,...)). Byte 1 = engine torque mode (SPN 899) from final_fueling_state: 0xf0 low speed "
        "governor (11), 0xf2 cruise control (9), 0xf3 power take-off (4), 0xf4 vehicle speed limit (10), 0xf9 high speed "
        "governor (12), 0xfa engine brake (24), 0xf1 for states 7 / 8 / 30 / 37, 0xf8 when torque_derate_fuel_source_code equals "
        "final_fueling_state, 0xf6 / 0xf7 / 0xf5 for the TSC1 source index 1 / 2 / 3 = transmission / ABS / ASR (the same order "
        "as e2m 117D +14); byte 2 = cm848_calculateDriverDemandPercentTorque + 125 (SPN 512), byte 3 = actual percent torque + "
        "125 (SPN 513), bytes 4-5 = engine_rpm_state_t_0040b7ac.current_rpm (SPN 190). SHARED: j1939GetEngineStateCode is also "
        "CM550 0x32c76 (function_renames.csv), so the main session holds this rename."),
    "plate_comment": (
        "Builds and sends the ECM's own EEC1 broadcast, PGN 61444: the transmit descriptor j1939_pgn61444_tx_message (can_id "
        "built from 0xf00400, 5 bytes, set by cm848_initEec1TxDescriptor at 0x25ab8) is registered in the periodic transmit "
        "queue with diag_record_queue_add_entry. Byte 1 is the engine torque mode (SPN 899): while a TSC1 override is active "
        "(j1939_tsc1_override_state.governor_mode non-zero in the TSC1 fueling states) 0xf6 / 0xf7 / 0xf5 for the sender index 1 "
        "/ 2 / 3 (transmission / ABS / ASR), otherwise from final_fueling_state: 0xf8 (torque limiting) when "
        "torque_derate_fuel_source_code equals it, 0xf0 low speed governor, 0xf2 cruise control, 0xf3 power take-off governor, "
        "0xf4 vehicle speed limit, 0xf9 high speed governor, 0xfa engine brake, 0xf1 accelerator pedal for the other user fueling "
        "states, else 0xfe. Byte 2 is the driver demand percent torque plus 125 (cm848_calculateDriverDemandPercentTorque, SPN "
        "512), byte 3 the actual engine percent torque plus 125 (cm848_calculateLoadRateOfChange at 0x209e8, SPN 513; 0xfe when "
        "j1939_broadcast_enable_flag is 1) and bytes 4-5 the engine speed (engine_rpm_state_t_0040b7ac.current_rpm, SPN 190)."),
})
