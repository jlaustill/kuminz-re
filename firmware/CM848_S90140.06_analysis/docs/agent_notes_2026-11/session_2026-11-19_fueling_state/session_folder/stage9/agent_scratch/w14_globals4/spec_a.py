"""Wave 14 globals4: items 0-26 of the bin (spec part A). Each entry is a dict; build.py assembles the JSONL."""

A = []


def rename(address, old, new, quote, evidence, comment, **extra):
    d = {"kind": "global", "verdict": "confirmed", "address": address, "old": old, "new": new,
         "evidence": evidence, "code_quote": quote, "comment": comment}
    d.update(extra)
    A.append(d)


# 0 --------------------------------------------------------------------------------------------------------------
rename(
    "0x003fcd92", "governor_cruiseOverride_holdoff_countdown", "cruise_coast_accelerate_hold_countdown",
    "governor_cruiseOverride_holdoff_countdown = cruise_coast_accelerate_hold_time;",
    "governor_cruise_coastButton_handler / _setButton_handler / _resumeButton_handler reload it from "
    "cruise_coast_accelerate_hold_time (e2m 8A0E +2 Coast_Accel_Timer) on a press, decrement it while the button stays "
    "held and return CRUISE_DECELERATE / CRUISE_ACCELERATE when it is 0; no e2m record here; legacy camelCase name.",
    "Countdown of the cruise coast / accelerate hold time (no e2m record here; the reload is e2m 8A0E +2 Coast_Accel_Timer "
    "'Amount of time bump must be held before transitioning to coast/accel', 0.04 s per count): the coast, set and resume "
    "button handlers (governor_cruise_*Button_handler) load it from the hold time on a press and count it down while the "
    "button stays held; at 0 the held button becomes CRUISE_DECELERATE / CRUISE_ACCELERATE. ROM-to-RAM window word.")

# 1 --------------------------------------------------------------------------------------------------------------
rename(
    "0x003fcff0", "cruise_ramp_rate_b_computed", "cruise_top_droop_gain_for_rear_axle_ratio_low",
    "cruise_ramp_rate_b_working = cruise_ramp_rate_b_computed;",
    "governorCruiseStateMachine: governor_cruise_rampRate_calc(cruise_fuel_demand_ramp_ceiling - "
    "cruise_ramp_zone_b_fuel_demand_threshold (e2m 1185 +4 Cruise_Top_Droop_Width), rear_axle_ratio_low_cal) feeds "
    "governor_cruise_tableLimit_calc, whose result is stored here; the same call with rear_axle_ratio_high_cal gives the "
    "twin DAT_003fcff2; governor_cruise_speedReference_update loads this word into the working top droop gain "
    "(0x40b6b0, e2m 1187 +1A Cruise_Top_Droop_Gain) on the normal path.",
    "Cruise control top droop gain computed for the low rear axle ratio, the normal single-speed path (no e2m record "
    "here): governorCruiseStateMachine turns the cruise top droop width (e2m 1185 +4 Cruise_Top_Droop_Width, 0x3fd912) with "
    "rear_axle_ratio_low_cal into it, and governor_cruise_speedReference_update loads it into the working gain at 0x40b6b0 "
    "(e2m 1187 +1A Cruise_Top_Droop_Gain). DAT_003fcff2 is the high-ratio twin, used while switch 31 is on with "
    "DRIVETRAIN_MANUAL_VSS and two_speed_axle_enable_cal 1. A droop slope, not a ramp rate.")

# 2 --------------------------------------------------------------------------------------------------------------
rename(
    "0x003fcff4", "cruise_ramp_rate_d_computed", "road_speed_governor_top_droop_gain_for_rear_axle_ratio_low",
    "road_speed_governor_top_droop_gain = cruise_ramp_rate_d_computed;",
    "governorCruiseStateMachine: the same call with road_speed_governor_top_droop_width_cal (e2m 1185 +8 "
    "RSG_Top_Droop_Width) and rear_axle_ratio_low_cal; DAT_003fcff6 is the rear_axle_ratio_high_cal twin; "
    "governor_cruise_speedReference_update and governorCruiseStateMachine load it into road_speed_governor_top_droop_gain "
    "(0x40b6bc, e2m 1187 +26 RSG_Top_Droop_Gain); top = the width input is the top droop width.",
    "Road speed governor (RSG) top droop gain computed for the low rear axle ratio, the normal path (no e2m record here): "
    "governorCruiseStateMachine turns road_speed_governor_top_droop_width_cal (e2m 1185 +8 RSG_Top_Droop_Width) with "
    "rear_axle_ratio_low_cal into it; governor_cruise_speedReference_update and governorCruiseStateMachine load it into "
    "road_speed_governor_top_droop_gain (e2m 1187 +26 RSG_Top_Droop_Gain, 0x40b6bc). DAT_003fcff6 is the high-ratio twin "
    "(switch 31 with DRIVETRAIN_MANUAL_VSS and two_speed_axle_enable_cal 1). A droop slope, not a ramp rate.")

# 3 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a198", "boost_pressure_fuel_mode_state", "barometric_pressure_reference_source",
    "boost_pressure_fuel_mode_state = fuel_boost_mode_state;",
    "hpcr_fuelFinal_exponentialAverage: with barometric_pressure_sensor_senses_ambient_air_flag_cal set it copies "
    "fuel_boost_mode_state (the barometric pressure selection state, 0 sensor / 2 default), else it combines that with the "
    "fresh air flow state (boost_pressure_state_t_0040a406.reserved_0e) into 0 / 1 / 2; DAT_0040a1a6 (e2m 1921 +12 "
    "Altitude_Source) copies it; e2m 1921 +4 Ambient_Air_Press_Source 0=PRIMARY / 1=BACKUP / 2=DEFAULT, 2 B = row.",
    "e2m 1921 +4 Ambient_Air_Press_Source 'Ambient Air Press Source: 0=PRIMARY, 1=BACKUP, 2=DEFAULT' (UNITLESS): source "
    "quality of barometric_pressure_reference. hpcr_fuelFinal_exponentialAverage stores the barometric pressure selection "
    "state when the barometric sensor senses ambient air (barometric_pressure_sensor_senses_ambient_air_flag_cal set), "
    "else that state combined with the fresh air flow state; DAT_0040a1a6 (e2m Altitude_Source) copies it. Not a boost or "
    "fuel mode.",
    old_comment_wrong=True)

# 4 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a19c", "fuel_demand_timing_mode_state", "ambient_air_temperature_reference_source",
    "fuel_demand_timing_mode_state = fuel_demand_state_b;",
    "hpcr_fuelFinal_exponentialAverage: = 2 when fuel_demand_state_b (the ambient air temperature input state of "
    "cm848_selectAmbientAirTemperatureInput, 0 sensor / 2 default) or the fresh air flow state is 2, 1 when either is 1, "
    "else 0, and (fuel_demand_timing_mode_state != 2) guards the filtered path of ambient_air_temperature_reference (2 "
    "takes the default value); cm848_initialization_step_3 seeds it from fuel_demand_state_b; e2m 1921 +8 "
    "Ambient_Air_Tmptr_Source, 2 B (its e2m description is copied from the pressure source).",
    "e2m 1921 +8 Ambient_Air_Tmptr_Source (UNITLESS; the e2m description is copied from the pressure source): source "
    "quality of ambient_air_temperature_reference, 0 PRIMARY / 1 BACKUP / 2 DEFAULT. hpcr_fuelFinal_exponentialAverage "
    "sets 2 when the ambient air temperature input state (cm848_selectAmbientAirTemperatureInput: 0 sensor / 2 default) "
    "or the fresh air flow state is 2, 1 when either is 1, else 0; at 2 the temperature filter is bypassed and the "
    "default value is used; cm848_initialization_step_3 seeds it.",
    old_comment_wrong=True)

# 5 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1a0", "fuel_demand_mode_state", "compressor_inlet_pressure_source",
    "fuel_demand_mode_state = fuel_boost_mode_state;",
    "hpcr_fuelFinal_exponentialAverage: fuel_demand_mode_state = fuel_boost_mode_state when "
    "barometric_pressure_sensor_senses_ambient_air_flag_cal is clear (the sensor then reads the compressor inlet), else "
    "0 / 1 / 2 from that state and the fresh air flow state; cm848_selectCompressorOutletTemperature tests "
    "(fuel_demand_mode_state == 2) && (fuel_demand_state_b == 2) for the default outlet temperature; e2m 1921 +C "
    "Compressor_Inlet_Press_Source, 2 B.",
    "e2m 1921 +C Compressor_Inlet_Press_Source 'Source, DEFAULT or PRIMARY, indicator for Compressor Inlet Pressure' "
    "(UNITLESS): source quality of compressor_inlet_pressure, 0 PRIMARY / 1 BACKUP / 2 DEFAULT. "
    "hpcr_fuelFinal_exponentialAverage takes the barometric pressure selection state when the barometric sensor reads the "
    "compressor inlet (barometric_pressure_sensor_senses_ambient_air_flag_cal clear), else that state combined with the "
    "fresh air flow state; cm848_selectCompressorOutletTemperature and cm848_estimateTurbochargerSpeed read it.")

# 6 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a430", "fuel_demand_mode_index", "charge_pressure_source",
    "if ((fuel_demand_droop_state == 2) && (fuel_demand_mode_index == 2)) {",
    "cm848_selectLoadNormalizer stores 0 (the MAP sensor value into the charge pressure at 0x40a42e), 1 (the lower of "
    "the sensor and boost_pressure_target) or 2 (boost_pressure_sensor_default_value); cm848_calculateFuelFlowWithMode "
    "combines it with fuel_demand_droop_state (both 2 gives egr_delta_pressure_source 2, both 0 gives 0); "
    "cm848_checkFuelSystemFaultFlags and cm848_fuelDemandWithLoadCompensation test it == 0; e2m 1A2D +2 "
    "Charge_Press_Source 0=PRIMARY / 1=BACKUP / 2=DEFAULT, 2 B.",
    "e2m 1A2D +2 Charge_Press_Source 'Charge Press Source: 0=PRIMARY, 1=BACKUP, 2=DEFAULT' (UNITLESS): source of the "
    "selected charge (intake manifold) pressure at 0x40a42e, set by cm848_selectLoadNormalizer: 0 the MAP sensor value, "
    "1 a backup taken from the sensor and boost_pressure_target, 2 boost_pressure_sensor_default_value. "
    "cm848_calculateFuelFlowWithMode, cm848_checkFuelSystemFaultFlags and cm848_fuelDemandWithLoadCompensation read it as "
    "the quality of that pressure. Not a fuel demand mode index.")

# 7 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a432", "fuel_mode_combined_flags", "charge_pressure_state",
    "fuel_mode_combined_flags = fuel_mode_flags_combined | boost_fuel_weight_snapshot;",
    "cm848_selectLoadNormalizer ORs fuel_mode_flags_combined (cm848_processBoostProtectionConditions: the MAP fault "
    "status, plus 0x20 while fault 527 or the gated faults 64 / 729 are active) with boost_fuel_weight_snapshot (0x80 / "
    "0x40 / 0 = the charge pressure target is default / backup / good) and tests the bits 0x80 0x40 0x20 0x10 0x02 to "
    "choose source 0 / 1 / 2; sth only, tests are inline masks; e2m 1A2D +4 Charge_Press_State, 2 B.",
    "e2m 1A2D +4 Charge_Press_State 'Charge Pressure State' (UNITLESS): bit mask of the charge pressure quality, built each "
    "pass by cm848_selectLoadNormalizer as the MAP fault status word (cm848_processBoostProtectionConditions, plus 0x20 "
    "while the in-range fault or a gated pre-start / underboost fault is active) OR the charge pressure target quality "
    "(0x40 backup, 0x80 default); its bits choose the charge pressure source. Not a fuel mode.")

# 8 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a434", "boost_fuel_below_threshold_flag", "charge_pressure_in_range_condition",
    "boost_fuel_below_threshold_flag = (word)(boost_fuel_threshold_limit < uVar3);",
    "cm848_processBoostProtectionConditions: uVar3 = |boost_pressure_target - boost_pressure_sensor_value - "
    "boost_fuel_threshold_offset| and the flag = (boost_fuel_threshold_limit < uVar3), so 1 means the deviation EXCEEDS "
    "the limit (the old 'below threshold' is backwards); cm848_processBoostControlState counts "
    "charge_pressure_in_range_fault_count up for 1 and down for 0; e2m 1A2D +6 Charge_Press_IR_Cond '0 for good, 1 for "
    "suspect', 2 B.",
    "e2m 1A2D +6 Charge_Press_IR_Cond 'Charge pressure in range condition (0 for good, 1 for suspect)' (UNITLESS): 1 when "
    "the charge pressure deviates from its target by more than the limit, |boost_pressure_target - "
    "boost_pressure_sensor_value - boost_fuel_threshold_offset| above boost_fuel_threshold_limit "
    "(cm848_processBoostProtectionConditions). While the monitor is enabled, cm848_processBoostControlState counts the "
    "in-range fault count up for 1 and down for 0.")

# 9 --------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a436", "boost_condition_active_flag", "charge_pressure_in_range_enable_flag",
    "if (boost_condition_active_flag == 0) {",
    "cm848_checkBoostControlCondition: = 1 when map_sensor_fault_status == 0 and boost_fuel_weight_snapshot == 0, else 0; "
    "cm848_processBoostControlState: 0 gives fuel_demand_cal_percent 0 and the in-range fault count is held, 1 gives 100; "
    "e2m 1A2D +8 Charge_Press_IR_Enable 'Enable bit for the charge pressure in range', 2 B.",
    "e2m 1A2D +8 Charge_Press_IR_Enable 'Enable bit for the charge pressure in range.' (UNITLESS): 1 while the charge "
    "pressure in range monitor may judge the pressure: cm848_checkBoostControlCondition sets it when the MAP channel has no "
    "fault status and the charge pressure target quality is good (both 0). cm848_processBoostControlState turns it into a "
    "0 / 100 percent enable and holds the in-range fault count while it is 0.")

# 10 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a462", "fuel_demand_phase_state", "intake_manifold_temperature_filtered_source",
    "fuel_demand_phase_state = 2;",
    "cm848_calculatePressureSensorFiltered: 0 with intake_manifold_temperature_filtered = the filtered value, 1 with "
    "fuel_demand_boost_offset_filtered, 2 with sensor_channel9_pressure_default_value, chosen from the sensor channel 9 "
    "fault status flags; e2m 18D9 +A Charge_Tmptr_Source 0=PRIMARY / 1=BACKUP / 2=DEFAULT, 2 B; the value row 0x40a460 "
    "is e2m 18D9 +8 Charge_Tmptr.",
    "e2m 18D9 +A Charge_Tmptr_Source 'Charge Tmptr Source: 0=PRIMARY, 1=BACKUP, 2=DEFAULT.' (UNITLESS): source of the "
    "charge (intake manifold) temperature at 0x40a460, set by cm848_calculatePressureSensorFiltered from the sensor channel "
    "9 fault status flags: 0 the filtered sensor value, 1 a backup (fuel_demand_boost_offset_filtered), 2 the channel "
    "default (sensor_channel9_pressure_default_value). Not a fuel demand phase.")

# 11 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a618", "fuel_timing_state_code", "compressor_outlet_temperature_source",
    "fuel_timing_state_code = 2;",
    "cm848_selectCompressorOutletTemperature: 2 with compressor_outlet_temperature = fuel_flow_rate_default_cal when the "
    "estimate is off (feature_enable_flags_cal bit 0x80 clear) or both input sources are 2, else 0 for primary inputs / 1 "
    "for backup inputs; mpc555_initFuelFlowRateVariables clears it; e2m 175F +A Compressor_Outlet_Tmptr_Source "
    "'source quality indicator', 2 B.",
    "e2m 175F +A Compressor_Outlet_Tmptr_Source 'Compressor outlet temperature source quality indicator' (UNITLESS): set by "
    "cm848_selectCompressorOutletTemperature: 2 when the estimation is off (feature_enable_flags_cal bit 0x80 clear) or the "
    "compressor inlet pressure and ambient temperature sources are both 2 (compressor_outlet_temperature = "
    "fuel_flow_rate_default_cal), else 0 for an estimate from primary inputs and 1 for backup inputs. Not a fuel timing "
    "state.")

# 12 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a626", "boost_fuel_mode_state", "egr_orifice_delta_pressure_source",
    "boost_fuel_mode_state = egr_delta_pressure_sensor_source;",
    "cm848_calculateFuelFlowWithMode: boost_fuel_mode_state = 2 together with egr_orifice_delta_pressure = 0 when "
    "egr_flow_cold_side_algorithm_select is 0, else boost_fuel_mode_state = egr_delta_pressure_sensor_source while "
    "egr_orifice_delta_pressure = the sensor output; e2m 1A19 +2 EGR_Orifice_Delta_Press_Source 'measurement quality', "
    "2 B, next to +0 egr_orifice_delta_pressure (0x40a624).",
    "e2m 1A19 +2 EGR_Orifice_Delta_Press_Source 'EGR orifice delta pressure measurement quality' (UNITLESS, quality code "
    "with 2 = default): source of the EGR orifice delta pressure at 0x40a624, written by cm848_calculateFuelFlowWithMode: "
    "2 (the pressure is the 0 default) when egr_flow_cold_side_algorithm_select is 0, else the EGR delta pressure sensor's "
    "own source (egr_delta_pressure_sensor_source). Not a boost fuel mode.")

# 13 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a62e", "fuel_demand_enable_state_cached", "egr_delta_pressure_negated_source",
    "egr_delta_pressure_source = fuel_demand_enable_state_cached;",
    "cm848_calculateFuelFlowWithMode ends with egr_delta_pressure_negated = -egr_delta_pressure and "
    "egr_delta_pressure_source = fuel_demand_enable_state_cached, the latter holding egr_delta_pressure_sensor_source "
    "(select 0) or the combination of fuel_demand_droop_state and fuel_demand_mode_index (0 / 1 / 2): one quality for the "
    "EGR valve delta pressure (e2m 1A19 +6) and for its negative, the engine delta pressure (+8, 0x40a62c); e2m 1A19 +A "
    "Engine_Delta_Press_Source, 2 B.",
    "e2m 1A19 +A Engine_Delta_Press_Source 'Pressure drop across the engine - measurement quality' (UNITLESS): source of "
    "the engine delta pressure at 0x40a62c (= -egr_delta_pressure). cm848_calculateFuelFlowWithMode holds here the EGR "
    "delta pressure sensor source (egr_flow_cold_side_algorithm_select 0) or the combined state of the two pressure inputs "
    "(0 / 1 / 2) and then copies it to egr_delta_pressure_source (e2m 1A19 +6), so both read the same. Not a fuel demand "
    "enable state.")

# 14 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a78a", "governor_fuel_derate_j1939_latch", "engine_protection_shutdown_override_request_flag",
    "governor_fuel_derate_j1939_latch = 1;",
    "governor_derateTrigger_latch_clear sets it from governor_derate_j1939_trigger_pending, which "
    "cm848_updateJ1939ReceptionControlFlag raises on a rising edge of switch 31 (switch_input_state_bits[3] & 0x80) while "
    "engine_protection_shutdown_approaching_flag is set and j1939_feature_enable_flags_cal bit 0x200 is on; "
    "governor_faultDerate_mainLoop_update then sets a running channel timer back to its start-warning time and raises "
    "DAT_0040a78b, and clears the latch every pass; e2m 10B1 +18 EPF_Shutdown_Override_Flag, 1 B.",
    "e2m 10B1 +18 EPF_Shutdown_Override_Flag '[EPSOOVFG] True indicates EPS shutdown override request detected.' (UNITLESS, "
    "byte): the engine protection shutdown override request. governor_derateTrigger_latch_clear sets it from "
    "governor_derate_j1939_trigger_pending (a rising edge of switch 31 while a shutdown is approaching, "
    "j1939_feature_enable_flags_cal bit 0x200); governor_faultDerate_mainLoop_update then sets the running channel timer "
    "back to its start-warning time and raises DAT_0040a78b (e2m +19 override lamp flag), and clears this flag every "
    "pass. Not a fuel derate latch.",
    old_comment_wrong=True)

# 15 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a790", "governor_fuel_derate_state", "engine_protection_timer_state",
    "governor_fuel_derate_state = 1;",
    "governor_faultDerate_mainLoop_update: 3 when governor_feature_config_word bit 0 is clear, else 0 when "
    "engine_protection_shutdown_approaching_flag and the peak timer value are both 0, else 1; "
    "cm848_runFaultDerateScheduler stores 3 with the derate feature bit 0x10 clear; cm848_completeEngineStartSequence "
    "stores 0; three sth writes and no load of 0x40a790 in the disassembly (the e2m's 'for broadcast' is not seen in "
    "code); e2m 10B1 +1E J1939_EP_Timer_State, 2 B.",
    "e2m 10B1 +1E J1939_EP_Timer_State 'calculated value of timer status for broadcast' (UNITLESS): engine protection timer "
    "state. governor_faultDerate_mainLoop_update stores 3 while the shutdown feature (governor_feature_config_word bit 0) "
    "is off, 0 when no channel timer is running and no shutdown is approaching, else 1; cm848_runFaultDerateScheduler also "
    "stores 3 with the derate feature (bit 0x10) off, cm848_completeEngineStartSequence stores 0. Only written: no "
    "decompiled reader. Not a fuel derate state.",
    old_comment_wrong=True)

# 16 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a891", "fuel_limit_mode_flags", "commanded_throttle_transient_flags",
    "fuel_limit_mode_flags = fuel_limit_mode_flags | 3;",
    "cm848_calculateFuelDemandChangeRate tests (flags & 2) and (flags & 1): | 3 when the looked-up filter constant falls "
    "and the commanded throttle is below its filtered value (decrease), | 2 with the 0xfffe mask when it is not, and "
    "& 0xfffd when the difference settles within DAT_0005c30e; lhz / sth through a pointer at the odd address 0x40a891; "
    "e2m 1053 +A Throttle_Decrease_Flag (mask 0001) and Throttle_Transient_Flag (mask 0002), 2 B = row.",
    "e2m 1053 +A Throttle_Decrease_Flag (mask 0x0001 '1-throttle value decreasing, 0-throttle value increasing') and "
    "Throttle_Transient_Flag (mask 0x0002 'Flag set-throttle in transient situation') (UNITLESS, 2 bytes at the odd "
    "address 0x40a891): flag word of the commanded throttle filter. cm848_calculateFuelDemandChangeRate sets 0x2 when the "
    "looked-up filter constant falls (0x1 as well when the commanded throttle is below its filtered value, else 0x1 "
    "cleared) and clears 0x2 when the throttle settles. Not a fuel limit mode.")

# 17 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b57f", "protection_output_controller_phase", "converter_clutch_rationality_monitor_state",
    "protection_output_controller_phase = 3;",
    "cm848_monitorConverterClutchAndOverdrivePerformance: = 1 when an engagement test starts, = 2 when "
    "converter_clutch_rationality_pass_count reaches its limit (clears fault bit 15 of fault_detected_bits_304_to_319), "
    "= 3 when the fail count reaches the maximum (sets it; fault 319 -> ROM slot table 0x5985a -> obd_dtc_code_table = "
    "P1740), = 4 when an inhibiting fault is active; e2m 8C34 +5 TCC_Rationality_Monitor_State 0004=ABORT / 0003=CMPFL / "
    "0002=CMPPS / 0001=RUN / 0000=NORUN, 2 B.",
    "e2m 8C34 +5 TCC_Rationality_Monitor_State 'State of TCC rationality Monitor' (0000=NORUN, 0001=RUN, 0002=CMPPS, "
    "0003=CMPFL, 0004=ABORT): state of the converter clutch / overdrive rationality monitor (P1740, "
    "cm848_monitorConverterClutchAndOverdrivePerformance): 1 the engagement test runs, 2 completed pass (pass count at its "
    "limit), 3 completed fail (fail count at its limit, sets fault 319), 4 aborted by an inhibiting fault. Not a "
    "protection output phase.",
    old_comment_wrong=True)

# 18 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b58b", "protection_fuel_derate_active_flag", "converter_clutch_first_lockup_in_third_gear_flag",
    "protection_fuel_derate_active_flag = 1;",
    "cm848_monitorConverterClutchAndOverdrivePerformance: set to 1 (with converter_clutch_rationality_timer = 0) when the "
    "overdrive solenoid request is off, the lockup gear ratio is inside the third gear window (or the gear is 2 or "
    "lower, which skips the window test) and overdrive_control_flags bit 0x20 is clear; cleared with "
    "converter_clutch_engaged_since_low_speed_flag when the clutch request is off below the engagement low speed; e2m "
    "8C34 +11 TCC_Third_Lockup 'first TCC lockup was in third gear', 1 B.",
    "e2m 8C34 +11 TCC_Third_Lockup 'Flag indicating first TCC lockup was in third gear' (0000=FALSE, 0001=TRUE, byte): set "
    "by cm848_monitorConverterClutchAndOverdrivePerformance after a lockup with the overdrive solenoid request off (lockup "
    "gear ratio inside the third gear window, or the gear is 2 or lower) while overdrive control flag 0x20 is clear, so the "
    "overdrive part of the test follows; cleared when the converter clutch request is off below the engagement low speed. "
    "Not a fuel derate flag.",
    old_comment_wrong=True)

# 19 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b746", "cylinder_sync_valid_flag", "cylinder_balance_stop_compensation_flag",
    "(cylinder_balance_compensation_enable_cal != 1)) || ((bool)cylinder_sync_valid_flag)) ||",
    "hpcr_cbdCalculateCylinderTrims: = true when the balance table lookup (filtered rpm x filtered fueling) is below 0x80, "
    "the engine speed moved by more than cylinder_sync_rpm_delta_threshold_cal or engine_state is not RUNNING, else "
    "false; ((bool)cylinder_sync_valid_flag) is one of the OR-ed conditions that zero the trim increments, so TRUE means "
    "stop compensating (the old 'valid' reads it inverted); e2m 81B0 +C CBD_Stop_Compensation_Flag, 1 B.",
    "e2m 81B0 +C CBD_Stop_Compensation_Flag 'Cylinder Balancing Stop Compensation Flag' (UNITLESS, byte): 1 stops the "
    "cylinder balance trim learning this pass. hpcr_cbdCalculateCylinderTrims sets it while the balance table lookup "
    "(filtered rpm x filtered fueling) is below 0x80, the engine speed moved by more than "
    "cylinder_sync_rpm_delta_threshold_cal or the engine is not RUNNING, and zeroes the trim increments while it is 1; "
    "cm848_runCylinderContributionTest tests it too. Not a sync valid flag: the polarity is reversed.")

# 20 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b747", "crank_pattern_sync_flag", "cylinder_balance_trim_limits_exceeded_flag",
    "if (crank_pattern_sync_flag == 1) {",
    "hpcr_cbdCalculateCylinderTrims: = 1 when a cylinder trim is above cylinder_balance_fueling_trim_maximum or below "
    "cylinder_balance_fueling_trim_minimum (cleared first in limit mode 0); the following (crank_pattern_sync_flag == 1) "
    "block takes the pass's increments back (limit mode 0), restores the power-down trims (1) or zeroes them (2); "
    "cm848_runCylinderContributionTest clears it; e2m 81B0 +D CBD_Trim_Limits_Exceeded, 1 B.",
    "e2m 81B0 +D CBD_Trim_Limits_Exceeded 'Cylinder Balancing Trim Limits Exceeded' (UNITLESS, byte): 1 when a learned "
    "cylinder trim goes above cylinder_balance_fueling_trim_maximum or below cylinder_balance_fueling_trim_minimum "
    "(hpcr_cbdCalculateCylinderTrims); cylinder_balance_fueling_trim_limit_mode then takes the pass's increments back (0), "
    "restores the power-down trims (1) or zeroes the trims (2). cm848_runCylinderContributionTest clears it. Not a crank "
    "pattern sync flag.")

# 21 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b9a4", "cssc_coolant_temp_span", "coolant_temperature_sensor_performance_temperature_span",
    "cssc_coolant_temp_span = cssc_coolant_temp_max - cssc_coolant_temp_min;",
    "cm848_checkCoolantTemperatureSensorPerformance (P0116: fault 401 -> ROM slot table 0x5985a -> obd_dtc_code_table; "
    "the plate also says coolant rationality) tracks the minimum and maximum coolant temperature while its state is 1 "
    "and stores the span; a span >= ROM word 0x642d6 (384) passes (state 2, clears fault bit 401), else it fails after "
    "ROM 0x642d8 (6000) cycles (state 3); no thermostat logic; compared as (short), signed i16 would fit; family prefix "
    "coolant_temperature_sensor_performance_ as in the wave-13 lead (0x3fd18a-0x3fd190 siblings are in another bin).",
    "Span (maximum minus minimum, 1/64 deg F) of the coolant temperature readings seen while the coolant temperature "
    "sensor performance monitor (P0116, cm848_checkCoolantTemperatureSensorPerformance) runs. A span of at least ROM "
    "word 0x642d6 (384 = 6 deg F) passes the sensor (state 2, clears fault 401); a smaller span after ROM 0x642d8 (6000) "
    "monitoring cycles fails it (state 3). Not a thermostat monitor (that is the P0128 thermostat_monitor_* family). No "
    "e2m record here.",
    old_comment_wrong=True)

# 22 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b9a6", "engine_cssc_coolant_state", "coolant_temperature_sensor_performance_state",
    "engine_cssc_coolant_state = 3;",
    "cm848_checkCoolantTemperatureSensorPerformance: 0 waiting for the start conditions, 1 monitoring (set once the soak "
    "and temperature checks pass), 2 span reached = pass, 3 failed (sets fault bit 401 = P0116), 6 aborted; "
    "cm848_completeCoolantTemperatureSensorMonitorReport turns 2 into 4 and 3 into 5 once the fault bit matches its "
    "snapshot; same family prefix as the 0x40b9a4 span row.",
    "State of the coolant temperature sensor performance monitor (P0116, cm848_checkCoolantTemperatureSensorPerformance): "
    "0 waiting for the start checks, 1 watching the coolant rise while the engine runs, 2 passed, 3 failed (sets fault 401, "
    "also at once in the hot-start shortcut), 4 / 5 pass / fail reported (cm848_completeCoolantTemperatureSensorMonitorReport), 6 not run or aborted. No e2m record here. Not a "
    "thermostat diagnostic.",
    old_comment_wrong=True)

# 23 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b9c6", "cam_sync_validation_state", "fuel_pressure_sensor_pre_start_check_state",
    "cam_sync_validation_state = 2;",
    "hpcr_checkRailPressureSensorBeforeStart (P0191: fault 414 -> ROM slot table 0x5985a -> obd_dtc_code_table) runs "
    "only while it is 1; it stores 4 on every abort (codes 1-5), 2 (clears fault bit 0x4000 of "
    "fault_detected_bits_400_to_415) when both sample counts stay below their limits, else 3 (sets it); "
    "cm848_initialization_group26_state arms it with 1; e2m 1B2D +2 Fuel_Pressure_Keyon_Rationality_State "
    "0000=NOTRUN:0001=RUN:0002=PASS:0003=FAIL:0004=ABORT, 2 B; family stem fuel_pressure_sensor_pre_start_*.",
    "e2m 1B2D +2 Fuel_Pressure_Keyon_Rationality_State 'Monitor state (Notrun Run Pass Fail Abort)' (0000=NOTRUN, "
    "0001=RUN, 0002=PASS, 0003=FAIL, 0004=ABORT): state of the rail pressure sensor key-on check before the engine starts "
    "(hpcr_checkRailPressureSensorBeforeStart, P0191 / fault 414). The initializer arms it with 1; it ends in 2 (clears the "
    "fault), 3 (sets it) or 4 (aborted, see the abort code). Not a cam sync validation.",
    old_comment_wrong=True)

# 24 (keep, built in build.py) ------------------------------------------------------------------------------------
A.append({"kind": "global", "verdict": "keep", "address": "0x0040b9cb",
          "old": "general_diagnostic_battery_voltage_in_range_flag",
          "new": "general_diagnostic_battery_voltage_in_range_flag", "e2m_note": "",
          "evidence": "no table-resolved record here (1B2D +6 resolves to 0x40b9ca, the 1B2D block drifts from +4 on); "
                      "the name is spelled out and its comment already carries the proved basis (e2m "
                      "Gen_Diag_Battery_Voltage_In_Range from block 160A, the 10.5-16.5 V window, readers "
                      "cm848_buildFaultConditionMask / cm848_updateMonitorEnablingConditionInputs)."})

# 25 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040bb3c", "governor_integrator_bound_b", "sensor_channel38_filtered_output",
    "uVar2 = cm848_absoluteValue16(uVar2 - governor_integrator_bound_b);",
    "0x40bb3c = 0x40baf0 + 2 x 38, element 38 of sensor_channel_filtered_output; cm848_checkSensorDeviationFlags compares "
    "it with the barometric pressure and channel 77 under oil_pressure_sensor_tolerance (e2m 165C +4 Oil_Sensor_Tolerence), "
    "the tolerances being paired in e2m order; no sensor channel wrapper passes channel index 38, so nothing writes it; "
    "named by slot like the unidentified sensor_channel<N>_* rows, not as an oil sensor.",
    "sensor_channel_filtered_output[38] (0x40baf0 + 2 x 38; no e2m record here): no sensor channel function writes it, so "
    "it stays 0. cm848_checkSensorDeviationFlags compares it with the barometric pressure and channel 77 using "
    "oil_pressure_sensor_tolerance (e2m 165C +4 Oil_Sensor_Tolerence), which is why the e2m order calls it the oil "
    "pressure sensor; the real oil pressure is slot 10 (oil_pressure_sensor_filtered). Not a governor integrator bound.")

# 26 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040bb8a", "governor_integrator_bound_a", "boost_pressure_channel77_sensor_filtered",
    "(uVar1 = (uint)(((ulonglong)governor_integrator_bound_a << 8) /",
    "0x40bb8a = 0x40baf0 + 2 x 77; sensor channel 77 (cm848_sensorChannel4_init / _process: channel index 0x4d, fault bits "
    "648 / 649 with no DTC slot, own table sensor_channel77_linearization_*) has qadc_channel_index_table[77] = "
    "qadc_channel_index_table[1] (the RAM dump holds 3 in both), the MAP channel's input; cm848_checkSensorDeviationFlags pairs it with "
    "boost_pressure_sensor_tolerance (e2m 165C +2) and cm848_diagnoseTurbochargerSpeedSensorFrequency divides it by "
    "barometric_pressure_reference for the compressor pressure ratio; named like accelerator_pedal_channel97_sensor_filtered.",
    "sensor_channel_filtered_output[77] (0x40baf0 + 2 x 77; no e2m record here): the second conversion of the boost "
    "(intake manifold) pressure input, 1/18.56 kPa per count. Sensor channel 77 (cm848_sensorChannel4_init / _process, own "
    "table sensor_channel77_linearization_*, fault bits 648 / 649 with no DTC) uses the same QADC index as the MAP channel "
    "(qadc_channel_index_table entries 1 and 77 hold the same index, value 3 in the RAM dump). cm848_checkSensorDeviationFlags compares it as the "
    "boost pressure sensor; cm848_diagnoseTurbochargerSpeedSensorFrequency divides it by the ambient pressure for the "
    "pressure ratio.")
