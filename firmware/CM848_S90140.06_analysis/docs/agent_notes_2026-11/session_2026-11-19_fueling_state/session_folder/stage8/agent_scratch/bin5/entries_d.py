# overrides after the advisor review (same helpers as entries_a-c)

# --- 0x40af0a / 0x40af0b: spell out the lamp ---
rename("0x0040af0a", "diagnostic_suppress_flag", "end_of_line_test_malfunction_indicator_lamp_override_state",
       "e2m 1226 +C EOL_Mil_State (UNITLESS, 0 none / 1 on / 2 flash on / 3 flash off): written only by "
       "diag_suppress_stateMachine, which cm848_runEndOfLineTestSequence and the end-of-line test steps (for example "
       "cm848_runEndOfLineMisfireTestStep) drive; cm848_updateMilOnRequest forces the MIL request on at 1 and "
       "cm848_processPciRemoteFaultStatus ignores the PCM's MIL request while it is non-zero; only 0 and 1 are ever "
       "stored; lbz 3 / stb 2; dump 0",
       "e2m 1226 +C EOL_Mil_State (UNITLESS): 'EOL Mil override state (0 none, 1 on, 2 flash on, 3 flash off)'. The "
       "malfunction indicator lamp (MIL) override of the Chrysler end-of-line (in-plant) test. "
       "diag_suppress_stateMachine (called by cm848_runEndOfLineTestSequence and its test steps) sets it: state 3 "
       "saves 1 and sets 1 (lamp on), state 1 saves the current value and sets 0 (and requests the flash, "
       "end_of_line_test_malfunction_indicator_lamp_flash_request_flag), state 2 restores the saved value, state 0 clears "
       "both. cm848_updateMilOnRequest: 0 = the MIL request follows the fault slots (fault_status_array bit 0x10), 1 = "
       "the request is forced on, any other value leaves it unchanged; cm848_processPciRemoteFaultStatus ignores the "
       "PCM's MIL request (RX[8] bit 7) while it is non-zero. Only 0 and 1 are written in this firmware (the e2m flash "
       "states 2 / 3 are never set). 0 in the RAM dump")

rename("0x0040af0b", "diag_suppress_active_flag", "end_of_line_test_malfunction_indicator_lamp_flash_request_flag",
       "e2m 1226 +D EOL_Mil_Flash (UNITLESS, 0 no flash / 1 flash): diag_suppress_stateMachine sets it to 1 at state 1 "
       "and clears it at states 2 and 3; cm848_buildPciTransmitMessage3MilAndDtcDisplay sends it as bit 5 of PCI "
       "TX[3] (0xB0) byte 1 only while end_of_line_test_settings_cal.field_mode_register is 5100 (0x13ec), the "
       "end-of-line mode; stb 3 / lbz 1; dump 0",
       "e2m 1226 +D EOL_Mil_Flash (UNITLESS, 0-1): 'EOL Mil Flash request (0 no flash, 1 flash)'. The flash request of "
       "the end-of-line (in-plant) test malfunction indicator lamp (MIL) override: diag_suppress_stateMachine sets it "
       "to 1 at state 1 (which also saves and clears end_of_line_test_malfunction_indicator_lamp_override_state) and "
       "clears it at states 2 and 3; cm848_buildPciTransmitMessage3MilAndDtcDisplay puts it into bit 5 of PCI TX[3] "
       "(0xB0) byte 1 while end_of_line_test_settings_cal.field_mode_register is 5100 (0x13ec). 0 in the RAM dump")

# --- block 1A2C / 1A2D: charge pressure, not boost in range (block 1632 BIR is the other monitor) ---
rename("0x004051e4", "fuel_demand_step_increment_cal", "charge_pressure_in_range_fault_count_increment",
       "e2m 1A2C +4 C_Charge_Press_Fault_Cnt_Incrt (UNITLESS, 0-100): cm848_processBoostControlState adds it to "
       "fuel_demand_step_accumulator (e2m 1A2D +A Charge_Press_IR_Fault_Cnt) on each pass in which the in range "
       "condition is suspect (boost_fuel_below_threshold_flag = e2m 1A2D +6 Charge_Press_IR_Cond, enabled by "
       "boost_condition_active_flag = +8 Charge_Press_IR_Enable), capped at the set threshold; lhz 1; dump 1; the old "
       "name (fuel demand step) matches nothing in the function; the word is outside the EEPROM mirror so no _cal",
       "e2m 1A2C +4 C_Charge_Press_Fault_Cnt_Incrt (UNITLESS, 0-100): 'Charge pressure in range fault count increment "
       "amount'. Calibration of the charge pressure in range monitor (charge pressure = the selected intake manifold "
       "pressure of e2m 1A2D +0 Charge_Press, map_fuel_correction_factor; not the OBD boost in range monitor of "
       "block 1632): cm848_processBoostControlState adds it to charge_pressure_in_range_fault_count on each pass in "
       "which the in range condition is suspect (boost_fuel_below_threshold_flag: abs(boost_pressure_target - "
       "boost_pressure_sensor_value - boost_fuel_threshold_offset) above boost_fuel_threshold_limit, with the monitor "
       "enabled by boost_condition_active_flag), never above charge_pressure_in_range_fault_set_threshold. The count "
       "goes down by the word at 0x4051e2 (e2m C_Charge_Press_Fault_Cnt_Decrt) on a good pass. 1 here")

rename("0x004051e6", "fuel_demand_step_limit_cal", "charge_pressure_in_range_fault_set_threshold",
       "e2m 1A2C +6 C_Charge_Press_Fault_Set (CNTS, 1-65535): cm848_processBoostControlState caps "
       "fuel_demand_step_accumulator (the fault count) here and a count at or above it sets fault 527 (bit 0x8000 of "
       "fault_detected_bits_512_to_527); e2m +0 C_Charge_Press_Fault_Clear (0x4051e0, dump 2) is the clear threshold; "
       "lhz 1; dump 4; the old name (fuel demand step limit) matches nothing in the function; the word is outside the "
       "EEPROM mirror so no _cal",
       "e2m 1A2C +6 C_Charge_Press_Fault_Set (CNTS, 1-65535): 'Calibration for pass to fail threshold'. The count at "
       "which the charge pressure in range fault is set: cm848_processBoostControlState caps "
       "charge_pressure_in_range_fault_count at it, and a count at or above it sets fault 527 (bit 0x8000 of "
       "fault_detected_bits_512_to_527); the fault clears again when the count is at or below e2m "
       "C_Charge_Press_Fault_Clear (0x4051e0, 2 here). 4 here")

rename("0x0040a438", "fuel_demand_step_accumulator", "charge_pressure_in_range_fault_count",
       "e2m 1A2D +A Charge_Press_IR_Fault_Cnt (CNTS, 0-255): the up / down count of cm848_processBoostControlState "
       "(+ the increment word 0x4051e4 while the condition is suspect, - the decrement word 0x4051e2 while it is "
       "good, 0 while the monitor is bypassed), which sets fault 527 at the set threshold and clears it at the clear "
       "threshold; the same block's +6 / +8 flags are boost_fuel_below_threshold_flag / boost_condition_active_flag; "
       "the census sees no width (compiled as word compares); dump 0",
       "e2m 1A2D +A Charge_Press_IR_Fault_Cnt (CNTS, 0-255): 'Charge pressure in range fault count'. Up / down "
       "debounce count of the charge pressure in range monitor (charge pressure = the selected intake manifold "
       "pressure, e2m Charge_Press), updated each pass by cm848_processBoostControlState: plus "
       "charge_pressure_in_range_fault_count_increment while the in range condition is suspect "
       "(boost_fuel_below_threshold_flag, e2m Charge_Press_IR_Cond) and the monitor is enabled "
       "(boost_condition_active_flag, e2m Charge_Press_IR_Enable), capped at "
       "charge_pressure_in_range_fault_set_threshold; minus the decrement (e2m C_Charge_Press_Fault_Cnt_Decrt, "
       "0x4051e2) while it is good, down to 0; held when the monitor is not enabled and 0 while it is bypassed "
       "(governor_feature_config_flags bit 0x10 clear or air_handling_compensation_and_diagnostic_bypass_cal "
       "non-zero). At the set threshold it sets fault 527 (bit 0x8000 of fault_detected_bits_512_to_527); at or below "
       "the clear threshold (e2m C_Charge_Press_Fault_Clear, 0x4051e0) it clears it. 0 in the RAM dump")

# --- block 8194: the backup path is the TPU-A channel 1 (cam signal) path; the primary one is channel 11 ---
rename("0x00408f56", "crank_sync_event_count_min_cal", "backup_consecutive_error_threshold",
       "e2m 8194 +0 [ESTDCU02] Backup_Consec_Error_Thresh (UNITLESS, 1 byte, 255 here): "
       "cm848_updateEngineSpeedFromCrankSignal compares crank_sync_event_count (+1 per pass while "
       "engine_sync_startup_countdown - reloaded by mpc555_updateEngineCrankState, the TPU-A channel 1 handler of the "
       "cam signal (e2m PMA_Edge_Type 'cam signal' = crank_mios_channel1_config_cal on tpu_a_ch1_param2) - is 0 and the "
       "speed is non-zero, else 0) with the HIGH byte (crank_sync_event_count_min_cal._0_1_) and at the limit sets "
       "fault_detected_bits_80_to_95 bit 0x2000 (fault 93) and holds the count; the old name says minimum and has a "
       "_cal outside the EEPROM mirror; TYPE: the word row swallows the byte at 0x408f57 (dump 1) = e2m +1 "
       "Bank_With_Added_Tooth (typeless label crank_sync_reference_flag_cal), read as "
       "(byte)crank_sync_event_count_min_cal in hpcr_processEngineSyncPulses and mpc555_updateEngineCrankState, so "
       "this row should be typed byte and 0x408f57 given a byte row",
       "e2m 8194 +0 [ESTDCU02] Backup_Consec_Error_Thresh (UNITLESS, 1 byte): 'threshold count at which eps is "
       "lost'. Threshold of the consecutive error count of the backup engine position signal, the TPU-A channel 1 path "
       "(the cam signal: mpc555_updateEngineCrankState is its interrupt handler and reloads "
       "engine_sync_startup_countdown from backup_pulse_period_timeout on every tooth event): "
       "cm848_updateEngineSpeedFromCrankSignal adds 1 to crank_sync_event_count per pass while that countdown is 0 and "
       "the engine speed is non-zero, else clears it; at this threshold it sets fault_detected_bits_80_to_95 bit "
       "0x2000 (fault 93) and holds the count here. The main signal counterpart is e2m Main_Consec_Error_Thres, "
       "crank_sync_period_confirm_count_cal at 0x408f80 (fault 92). 255 in the RAM dump. TYPE: this row is typed word "
       "but the record is the HIGH byte (read as ._0_1_); the word type swallows the byte at 0x408f57 (1 in the dump) "
       "= e2m +1 Bank_With_Added_Tooth, 'which crank signal window has the cam +1 pulse' (typeless label "
       "crank_sync_reference_flag_cal), which hpcr_processEngineSyncPulses and mpc555_updateEngineCrankState read as "
       "(byte) of this word; this row should be typed byte and 0x408f57 given a byte row of its own")

rename("0x00408f68", "crank_period_scale_cal", "primary_period_rpm_conversion_factor",
       "e2m 8194 +12 [ESCUCF01] Engine_Speed_Constant_1 (UNITLESS, x 0.125, 4 bytes): 'Conversion factor from tcnts "
       "to rpm - primary': cm848_updateEngineSpeedFromCrankSignal sets crank_derived_rpm = this / "
       "crank_period_accumulator and hpcr_processEngineSyncPulses (TPU-A channel 11 handler) builds the period "
       "variation metric from this / crank_period_accumulator and this / crank_period_prev_snapshot; lwz 2; dump "
       "400000000; the old name has a _cal outside the EEPROM mirror",
       "e2m 8194 +12 [ESCUCF01] Engine_Speed_Constant_1 (UNITLESS, x 0.125, 4 bytes): 'Engine_Speed_Constant_1: "
       "Conversion factor from tcnts to rpm - primary'. The primary engine speed constant: "
       "cm848_updateEngineSpeedFromCrankSignal computes crank_derived_rpm (1/8 rpm per count, the engine_rpm_measured "
       "scale) = this / crank_period_accumulator (the accumulated period of the primary signal in timer counts), and "
       "hpcr_processEngineSyncPulses (the TPU-A channel 11 handler) forms the period variation metric from this / "
       "crank_period_accumulator and this / crank_period_prev_snapshot. The backup counterpart (the tooth period sum of "
       "the channel 1 handler) is e2m Engine_Speed_Constant_1_Backup, crank_tooth_rpm_divisor_cal at 0x408f6c. "
       "400,000,000 here")

rename("0x00408f78", "crank_teeth_per_rev", "tooth_period_buffer_initial_engine_speed",
       "e2m 8194 +22 Initial_Engine_Speed (UNITLESS, x 0.125 rpm, 0-5000): 'Speed for which tooth period buffers are "
       "initialized': all 27 uses are in mpc555_resetEngineTimingAccumulators, which divides 2500000 (then x 8, for "
       "crank_period_capture_array) and 20000000 or N x 20000000 (the TPU-A channel 11 / 12 / 13 / 14 period "
       "buffers) by it, i.e. an initial tooth period K / speed with the x 8 of the 1/8 rpm scale; no code treats it "
       "as a tooth count (a count would not carry the e2m's 0.125 scale and would not be used only to preload period "
       "buffers); census blind; dump 120 = 15 rpm",
       "e2m 8194 +22 Initial_Engine_Speed (UNITLESS, x 0.125, 0-5000): 'Speed for which tooth period buffers are "
       "initialized'. The speed (1/8 rpm per count) at which the engine speed measurement is preloaded: "
       "mpc555_resetEngineTimingAccumulators, its only user (27 reads), fills crank_period_capture_array with the "
       "crank_timer_offset byte (e2m Crank_Sync_Tooth) x (2500000 / this) x 8 and the TPU-A channel 11 / 12 / 13 / 14 "
       "period buffers with (N x) 20000000 / this, i.e. the tooth period of that speed in TPU-A timer counts "
       "(0.4 us): 2500000 x 8 / 120 = 166,666 counts = 66.7 ms. 120 = 15 rpm here")

rename("0x00408f84", "crank_sync_timing_scale_cal", "backup_pulse_period_timeout",
       "e2m 8194 +2E [ESMXTM02] Maximum_Pulse_Period_Timeout_Backup (MSEC, 20 per count, 0-10000): 'max reset value "
       "for backup': cm848_updateEngineSpeedFromCrankSignal divides it by 1 / 2 / 4 / 8 as the filtered engine "
       "speed rises (below 256 rpm / below 511 / below 768 / above) into crank_sync_timing_scale_working, and "
       "mpc555_updateEngineCrankState (the TPU-A channel 1 handler, cam signal) reloads engine_sync_startup_countdown "
       "from that on every tooth event - the countdown whose expiry zeroes crank_tooth_rpm and drives "
       "crank_sync_event_count; lhz 3; dump 50 = 1000 ms; the old name has a _cal outside the EEPROM mirror",
       "e2m 8194 +2E [ESMXTM02] Maximum_Pulse_Period_Timeout_Backup (MSEC, 20 per count, 0-10000): "
       "'Maximum_Pulse_Period_Timeout_Backup:max reset value for backup'. Reload value of the backup pulse lost "
       "countdown, the TPU-A channel 1 (cam signal) path: cm848_updateEngineSpeedFromCrankSignal divides it by 1 / 2 / "
       "4 / 8 as the filtered engine speed rises (below 256 rpm / below 511 / below 768 / above) into "
       "crank_sync_timing_scale_working, and mpc555_updateEngineCrankState reloads engine_sync_startup_countdown from "
       "that on every tooth event; cm848_updateEngineSpeedFromCrankSignal counts the countdown down and, while it is "
       "0, zeroes crank_tooth_rpm and counts crank_sync_event_count. The primary counterpart (crank_period_countdown "
       "reloaded from crank_period_raw, e2m Maximum_Pulse_Period_Timeout at 0x408f82) works the same way. 50 = 1000 ms "
       "here")

rename("0x00408fa0", "crank_rpm_divisor_cal", "engine_speed_interrupts_per_cylinder",
       "e2m 8194 +4A Sums_Per_Cylinder (UNITLESS, 0-255): 'Number of speed interrupts per cylinder': "
       "mpc555_resetEngineTimingAccumulators multiplies it by crank_period_capture_index_max_cal into "
       "crank_period_scale_divisor and programs TPU-A channel 12 PARAM7 with this x 0x100 - 0x100, and "
       "mpc555_updateEngineCrankState divides the captured tooth period by it before adding it to "
       "crank_tooth_period_sum; lhz 1; dump 4; the old name has a _cal outside the EEPROM mirror and calls it an rpm "
       "divisor",
       "e2m 8194 +4A Sums_Per_Cylinder (UNITLESS, 0-255): 'Number of speed interrupts per cylinder.' Number of speed "
       "interrupt sums per cylinder event: mpc555_resetEngineTimingAccumulators multiplies it by "
       "crank_period_capture_index_max_cal into crank_period_scale_divisor (the divisor of the period variation "
       "metric in hpcr_processEngineSyncPulses) and programs TPU-A channel 12 PARAM7 with this x 256 - 256; "
       "mpc555_updateEngineCrankState divides the captured tooth period by it before it adds the period to "
       "crank_tooth_period_sum. 4 here")

# --- 0x409082: the e2m defines Vac ---
rename("0x00409082", "fuel_demand_threshold_cal", "equivalent_throttle_vacuum_all_speed_governor_offset",
       "e2m 81A9 +12 Equiv_Throt_Vac_ASG_Offset (%THROTTLE, 0.25, 0-100) 'Equivalent throttle offfset.' ('Vac' is the "
       "e2m's own word for the vacuum throttle actuator: the Vac_Throttle_* records, e.g. Vac_Throttle_ASG_Delta 'ASG "
       "fuel is decreased by this amount when in cruise with vac throttle', Vac_Throttle_Actuator_Disabled 'TRUE "
       "indicates throttle cannot be positioned with vac actuator'): cm848_calculateFuelDemandWithConditions, with bit "
       "0x10 of fuel_feature_control_flags set, uses fuel_demand_control_t.calculated - this (0 when not above it) as "
       "the equivalent throttle while the governor is not in control and as the floor of the governor output (output "
       ">= demand - this) at the end; it is an offset that is subtracted, not a threshold; lhz 2 (three uses); dump 24 "
       "= 6 percent; the old name (fuel demand threshold) has a _cal outside the EEPROM mirror",
       "e2m 81A9 +12 Equiv_Throt_Vac_ASG_Offset (%THROTTLE, 0.25 percent per count, 0-100): 'Equivalent throttle "
       "offfset.' Offset of the all speed governor (ASG) equivalent throttle for the vacuum throttle (vac = the "
       "vacuum throttle actuator of the e2m's Vac_Throttle_* records, e.g. Vac_Throttle_ASG_Delta 'ASG fuel is "
       "decreased by this amount when in cruise with vac throttle'): cm848_calculateFuelDemandWithConditions, when bit "
       "0x10 of fuel_feature_control_flags (the EEPROM fuel feature word) is set, takes "
       "fuel_demand_control_t.calculated (the accelerator pedal demand, 0.25 percent per count) minus this (0 when "
       "the demand is not above it) as the equivalent throttle while the governor is not in control, and at the end "
       "keeps fuel_demand_governor_output at least demand minus this. 24 = 6 percent in the RAM dump")

# --- 0x40b55e: lead with the record used ---
rename("0x0040b55e", "protection_coldStart_channelA_trip_count", "governor_pressure_zero_check_fail_count",
       "e2m 8C58 +0 RE_Governor_Pr_Zero_Rat_Fails_This_DC (CNTS 'Number of times monitor has detected failures this "
       "DC') is the record the code holds here: cm848_monitorGovernorPressureTracking adds 1 per failed zero check "
       "(vehicle stopped, governor pressure target at or below protection_coldStart_channelA_rpm_min_threshold, "
       "governor_pressure above governor_pressure_zero_check_high_limit for more than "
       "governor_pressure_zero_check_debounce_count_limit passes) while below "
       "governor_pressure_zero_check_fail_count_limit (e2m 8C59 +0), at the limit the next failure sets fault 391 (bit "
       "0x80 of fault_detected_bits_384_to_399); census blind; dump 0. The bin's record e2m 8C56 +4 Gov_Press_Rat_Ratio "
       "(in-use performance ratio of the transmission oil pressure rationality) resolves to the same address but is "
       "drift: block 8C56 ends after +2 in this build and this word is the next block's first record. The old name "
       "(cold start protection channel A) is an older guess; the prefix of the family is governor_pressure_zero_check_",
       "e2m 8C58 +0 RE_Governor_Pr_Zero_Rat_Fails_This_DC (CNTS): 'Number of times monitor has detected failures this "
       "DC'. Failure count of the 48RE governor pressure zero check of cm848_monitorGovernorPressureTracking (vehicle "
       "stopped with the governor pressure target at or below protection_coldStart_channelA_rpm_min_threshold, e2m "
       "RE_Governor_Pr_Zero_Set_High_Limit: governor_pressure above governor_pressure_zero_check_high_limit for more "
       "than governor_pressure_zero_check_debounce_count_limit passes): +1 per failed evaluation while below "
       "governor_pressure_zero_check_fail_count_limit (e2m RE_Governor_Pr_Zero_Rat_Fail_Count_Limit), and at the limit "
       "the next failure sets fault 391 (bit 0x80 of fault_detected_bits_384_to_399). The ECU's table also resolves "
       "e2m 8C56 +4 Gov_Press_Rat_Ratio (the in-use performance ratio of the transmission oil pressure rationality) to "
       "this address, but block 8C56 ends before +4 in this build and the code holds the zero check failure count "
       "here. 0 in the RAM dump")

# --- 0x3fedfa / 0x3fedfb: information spelled out ---
rename("0x003fedfa", "diag_response_pending_flag", "transmission_learned_information_stored_flags_byte_1_cal",
       "e2m 8CE5 +0 RE_Non_Vol_Mem_Flags1 (HEX, 1 byte) 'Flags indicating transmission learned info is stored, byte 1 "
       "of 2': the table maps block 8CE5 to 0x3fedfa (EEPROM 0x1978) and its +1 record is proved by the application "
       "(cm848_learnOutputSpeedToVehicleSpeedRatio sets bit 0 of 0x3fedfb, cm848_calculateTransmissionOutputSpeed "
       "tests it); this byte has no application access in the decompile - its only code users are the boot reflash "
       "kernel's SCI routines (mpc555_sciReceiveDataByte sets it to 2 / 0, mpc555_sciValidateChecksum counts it down), "
       "which time-share the EEPROM mirror RAM; EEPROM 0x1978 is 0 in all four EEPROM dumps (the next byte is 1 "
       "before the HP Tuners flash and 0 after); stb 2; the old name is the kernel's use and has no _cal in the "
       "EEPROM mirror",
       "e2m 8CE5 +0 RE_Non_Vol_Mem_Flags1 (HEX, 1 byte): 'Flags indicating transmission learned info is stored, byte "
       "1 of 2'. EEPROM 0x1978 (mirror), the first of two flag bytes beside the learned output speed ratio "
       "(diag_clear_flags_t at 0x3fedfc); the second byte, output_speed_to_vehicle_speed_ratio_learned_flag_cal at "
       "0x3fedfb, is the one the application uses (bit 0 = learned ratio stored); no application code reads or "
       "writes this byte in the decompile. TIME-SHARED with the boot reflash kernel: mpc555_sciReceiveDataByte sets "
       "it to 2 (and 0) and mpc555_sciValidateChecksum counts it down as an SCI response pending countdown. 0 in the "
       "RAM dump and in all four EEPROM dumps")

rename("0x003fedfb", "output_speed_to_vehicle_speed_ratio_learned_flag",
       "output_speed_to_vehicle_speed_ratio_learned_flag_cal",
       "e2m 8CE5 +1 RE_Non_Vol_Mem_Flags2 (HEX, 1 byte) 'Flags indicating transmission learned info is stored, byte 2 "
       "of 2': cm848_learnOutputSpeedToVehicleSpeedRatio sets bit 0 once a ratio is stored and "
       "cm848_calculateTransmissionOutputSpeed tests it to pick the learned or the default ratio; the old name is "
       "right but sits in the EEPROM mirror (EEPROM 0x1979, 1 before the HP Tuners flash and 0 after) without the "
       "_cal suffix; the boot reflash kernel reuses the byte as an SCI checksum; stb 1 / lbz 1; dump 1",
       "e2m 8CE5 +1 RE_Non_Vol_Mem_Flags2 (HEX, 1 byte): 'Flags indicating transmission learned info is stored, byte "
       "2 of 2'. EEPROM 0x1979 (mirror). Bit 0 is set by cm848_learnOutputSpeedToVehicleSpeedRatio once a ratio is "
       "stored (diag_clear_flags_t.learned_output_speed_to_vehicle_speed_ratio at 0x3fedfe) - "
       "cm848_calculateTransmissionOutputSpeed checks it to pick the learned vs the default ratio; the other bits are "
       "not used by the application. The first flag byte is transmission_learned_information_stored_flags_byte_1_cal "
       "at 0x3fedfa. TIME-SHARED: the boot reflash kernel reuses this byte as an SCI checksum "
       "(mpc555_sciTransmitChecksummedByte; medium confidence). 1 in the RAM dump (HP Tuners zeroes it)")
