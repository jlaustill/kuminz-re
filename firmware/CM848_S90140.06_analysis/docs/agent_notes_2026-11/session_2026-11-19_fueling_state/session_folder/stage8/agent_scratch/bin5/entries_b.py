# records 23-45 of bin5

rename("0x004094b2", "injection_timing_scale_cyl4_a_cal", "fuel_pressure_governor_integral_gain_small_signal",
       "e2m 8015 +0 HPCR_Integral_Gain_Small_Signal (%/MPa/SEC, 0.00011641, 4 bytes): "
       "cm848_calculateFuelMeteringCommand builds the integral gain record (&local_54: this dword, +4 and +8 the next "
       "two rows, +12 / +14 the window shorts at 0x4094be / 0x4094c0 = e2m +C / +E) and cm848_integrateWithZoneGain "
       "uses gain +0 while the error is between the windows; with cam_timing_alt_mode_enable_cal 0 (as here) the word "
       "is first scaled by an rpm table value (>> 12); the old name (injection timing scale, cylinder 4) is an older "
       "guess; census blind (struct copy); dump 8590 x 0.00011641 = 1.0",
       "e2m 8015 +0 HPCR_Integral_Gain_Small_Signal (%/MPa/SEC, 0.00011641 per count, 4 bytes): 'Fuel pressure "
       "governor I-Component small signal gain'. Integral gain of the fuel (rail) pressure governor while the "
       "pressure error is inside the zone window: cm848_calculateFuelMeteringCommand builds the gain record "
       "(&local_54: this dword, +4 fuel_pressure_governor_integral_gain_positive_large_signal, +8 "
       "fuel_pressure_governor_integral_gain_negative_large_signal, +12 / +14 the two window shorts at 0x4094be / "
       "0x4094c0 = e2m +C Positive_Window_Width / +E Negative_Window_Width, +205 / -204 counts of 0.0488 MPa = about "
       "+-10 MPa) and cm848_integrateWithZoneGain adds gain x error x step >> 16 to the integrator "
       "fuel_pressure_governor_integrator, with this gain while the error (fuel_pressure_setpoint minus "
       "fuel_pressure_feedback_filtered) is between the windows. With cam_timing_alt_mode_enable_cal 0 (as here) the "
       "word is first multiplied by an rpm table value (>> 12). 8590 = 1.0 here")

rename("0x004094b6", "injection_timing_scale_cyl5_a_cal", "fuel_pressure_governor_integral_gain_positive_large_signal",
       "e2m 8015 +4 HPCR_Integral_Gain_Positive_Large_Signal (%/MPa/SEC, 0.00011641, 4 bytes): the +4 gain of the "
       "record passed to cm848_integrateWithZoneGain, picked when the error is above the +12 window short (e2m +C "
       "Positive_Window_Width); same scaling by an rpm table (>> 12) while cam_timing_alt_mode_enable_cal is 0; the old "
       "name (injection timing scale, cylinder 5) is an older guess; census blind; dump 5154 x 0.00011641 = 0.6",
       "e2m 8015 +4 HPCR_Integral_Gain_Positive_Large_Signal (%/MPa/SEC, 0.00011641 per count, 4 bytes): 'Fuel "
       "pressure governor I-Component positive large signal gain'. Integral gain of the fuel pressure governor used "
       "by cm848_integrateWithZoneGain when the error (fuel_pressure_setpoint minus fuel_pressure_feedback_filtered) "
       "is above the positive window (+205 counts = about 10 MPa below the setpoint; e2m +C Positive_Window_Width at "
       "0x4094be); see fuel_pressure_governor_integral_gain_small_signal. 5154 = 0.6 here")

rename("0x004094ba", "injection_timing_scale_cyl6_a_cal", "fuel_pressure_governor_integral_gain_negative_large_signal",
       "e2m 8015 +8 HPCR_Integral_Gain_Negative_Large_Signal (%/MPa/SEC, 0.00011641, 4 bytes): the +8 gain of the "
       "record passed to cm848_integrateWithZoneGain, picked when the error is below the +14 window short (e2m +E "
       "Negative_Window_Width); same scaling by an rpm table (>> 12) while cam_timing_alt_mode_enable_cal is 0; the old "
       "name (injection timing scale, cylinder 6) is an older guess; census blind; dump 8590 x 0.00011641 = 1.0",
       "e2m 8015 +8 HPCR_Integral_Gain_Negative_Large_Signal (%/MPa/SEC, 0.00011641 per count, 4 bytes): 'Fuel "
       "pressure governor I-Component negative large signal gain'. Integral gain of the fuel pressure governor used "
       "by cm848_integrateWithZoneGain when the error (fuel_pressure_setpoint minus fuel_pressure_feedback_filtered) "
       "is below the negative window (-204 counts = about 10 MPa above the setpoint; e2m +E Negative_Window_Width at "
       "0x4094c0); see fuel_pressure_governor_integral_gain_small_signal. 8590 = 1.0 here")

keep("0x0040b886", "fuel_pressure_governor_proportional_term",
     "e2m 8019 +7 HPCR_Fuelpr_Prop_Dutycycle (%, 0.0244, signed) 'Proportional component of dutycycle for fuel "
     "pressure monitoring' (the proportional term of the fuel pressure governor)")

keep("0x0040b88c", "fuel_pressure_governor_accelerator_feed_forward",
     "e2m 8019 +D HPCR_Fuelpr_Throttle_FF_Dutycycle (%, 0.0244, signed) 'Throttle feed-forward contribution to the "
     "dutycycle' (throttle = the accelerator pedal demand change)")

keep("0x0040b891", "fuel_pressure_feedback_previous",
     "e2m 8019 +12 HPCR_Filtered_Fuelpr_Control (MPa, 0.0488) 'Filtered fuel pressure used in the control algorithm' "
     "(the governor's copy of fuel_pressure_feedback_filtered taken each pass)")

rename("0x0040b893", "cam_speed_rate", "fuel_metering_command_filtered",
       "e2m 8019 +14 HPCR_Filtered_Dutycycle_Output (%, 0.0244, signed) 'Filtered final output used for coil "
       "resistance calculation': cm848_calculateFuelMeteringCommand stores cm848_signedFirstOrderFilter("
       "engine_sync_state_t_0040b87f.fuel_metering_command, &fuel_metering_command_filter) in it while "
       "fuel_metering_feedback_fault_code is 0 and uses it with the battery voltage and the filtered feedback for the "
       "coil resistance; the old name (cam speed rate) is an older cam-sync guess; sth 2 (store only; signed by the "
       "e2m and the (short) casts); dump 0 (engine off)",
       "e2m 8019 +14 HPCR_Filtered_Dutycycle_Output (%, 0.0244 per count, signed): 'Filtered final output used for "
       "coil resistance calculation'. The fuel metering command (engine_sync_state_t_0040b87f.fuel_metering_command, "
       "0-4095 = 0-100 percent, the fuel pressure governor output to the fuel metering solenoid, e2m MPROP) after the "
       "first-order filter fuel_metering_command_filter, written every pass by cm848_calculateFuelMeteringCommand while "
       "fuel_metering_feedback_fault_code is 0; with the battery voltage and the filtered feedback it gives "
       "fuel_metering_coil_resistance_filtered, and it is compared with cam_speed_rate_threshold_cal to gate that "
       "estimate. 0 in the RAM dump (engine off)")

rename("0x0040b895", "engine_sync_rpm_filtered", "fuel_metering_coil_resistance_filtered",
       "e2m 8019 +16 HPCR_MPROP_Coil_Resistance (OHM, 0.005) 'Filtered estimated resistance based on voltage and "
       "current': cm848_calculateFuelMeteringCommand computes (fuel_metering_command_filtered x battery_voltage x 5) / "
       "(2 x the filtered fuel_metering_feedback_input) while the filtered feedback is above "
       "cam_sync_error_rate_threshold_cal and the filtered command above cam_speed_rate_threshold_cal, EMA-filters "
       "it (cam_sync_rpm_filter_state) into this word, and turns it into a temperature with "
       "engine_sync_rpm_scale_cal x this / 0x138 + engine_sync_rpm_offset_cal; cm848_resetEngineSyncState reloads it "
       "from engine_sync_rpm_filter_initial_cal; sth 2 / lhz 1; dump 722 x 0.005 = 3.61 ohm; the old name (engine "
       "sync rpm) is an older cam-sync guess",
       "e2m 8019 +16 HPCR_MPROP_Coil_Resistance (OHM, 0.005 per count): 'Filtered estimated resistance based on "
       "voltage and current'. Estimated resistance of the fuel metering solenoid coil (e2m MPROP): once the filtered "
       "command fuel_metering_command_filtered and the filtered feedback current (fuel_metering_feedback_input) are "
       "above their thresholds (cam_speed_rate_threshold_cal, cam_sync_error_rate_threshold_cal), "
       "cm848_calculateFuelMeteringCommand computes command x battery_voltage x 5 / (2 x filtered feedback) into "
       "engine_sync_rpm_raw_working and EMA-filters it (cam_sync_rpm_filter_state) into this word; "
       "engine_sync_rpm_scale_cal x this / 0x138 + engine_sync_rpm_offset_cal is the coil temperature "
       "(fuel_metering_coil_temperature). cm848_resetEngineSyncState reloads it from "
       "engine_sync_rpm_filter_initial_cal. 722 = 3.61 ohm in the RAM dump")

rename("0x0040b897", "engine_sync_speed_raw", "fuel_metering_coil_temperature",
       "e2m 8019 +18 MPROP_Coil_Temperature (DEG_F, 1/64, signed, -50..255) 'Calculated using estimated coil "
       "resistance': cm848_calculateFuelMeteringCommand stores engine_sync_rpm_scale_cal x "
       "fuel_metering_coil_resistance_filtered / 0x138 + engine_sync_rpm_offset_cal once the estimate has settled "
       "(engine_sync_phase_counter at its maximum), and engine_sync_state_a / _b select it as temperature source 5 "
       "(the other sources are fuel, coolant, intake manifold, battery and ambient air temperature) for the start "
       "command lookups and the feedback trim integrator preset; lha 3 / lhz 1 / sth 2 (signed: i16 would fit); dump "
       "1943 = 30.4 F; the old name (engine sync speed) is an older cam-sync guess",
       "e2m 8019 +18 MPROP_Coil_Temperature (DEG_F, 1/64 deg F per count, signed): 'Calculated using estimated coil "
       "resistance'. Temperature of the fuel metering solenoid coil (e2m MPROP) estimated from its resistance: "
       "cm848_calculateFuelMeteringCommand sets it to engine_sync_rpm_scale_cal x "
       "fuel_metering_coil_resistance_filtered / 0x138 + engine_sync_rpm_offset_cal once the resistance estimate has "
       "settled (engine_sync_phase_counter at its maximum) and then raises engine_sync_rpm_phase_acquired_flag / "
       "engine_sync_confirmed_flag. It is temperature source 5 of the start temperature selectors "
       "engine_sync_state_a / engine_sync_state_b (0 fuel, 1 coolant, 2 intake manifold, 3 battery, 4 ambient air "
       "temperature, any other value the lowest of coolant / intake manifold / battery), which choose the temperature "
       "for the open loop start command and the feedback trim integrator preset. Signed (lha). 1943 = 30.4 deg F in "
       "the RAM dump")

keep("0x0040b766", "total_injection_quantity",
     "e2m 8192 +0 Cylinder_Fueling (MM3S, 0.0679) 'Cylinder Fueling - after cyl. balance and cutout' (the cylinder's "
     "whole quantity: pilot + main + auxiliary, after the per-cylinder trim)")

rename("0x0040b778", "crank_sync_inhibit_flag", "cylinder_cutout_test_mask",
       "e2m 8192 +12 Cylinder_Cutoff (HEX, 0-255, 'bit-mapped to each cylinder, bit0=cyl1'): "
       "cm848_sciCommand37Callback sets / clears bit (sub-id - 5) per cylinder for the SCI actuator test (value 2 cuts "
       "the cylinder out with a 1000 count refresh timer in DAT_003fcf64, value 1 or sub-id / value 0 releases it); "
       "the injection dispatch tests bit (cylinder_event_index & 0x3f) of (this OR cylinder_cutout_mask); "
       "hpcr_cbdCalculateCylinderTrims holds off the cylinder balance learning and cm848_runCylinderContributionTest "
       "reports status 2 while it is non-zero; nothing in these uses is a crank sync inhibit; lhz 5 / sth 2; dump 0",
       "e2m 8192 +12 Cylinder_Cutoff (HEX, 0-255): 'Cylinder Cutoff - bit-mapped to each cylinder, bit0=cyl1 ...'. "
       "Cylinder cutout test mask, bit n = cylinder n + 1 cut out. Set and cleared per cylinder by the SCI actuator "
       "test command 37 (cm848_sciCommand37Callback: sub-ids 5-10 = cylinders 1-6, value 2 cuts the cylinder out "
       "for a 1000 count timer that the tool refreshes, value 1 releases it, sub-id or value 0 releases all). The "
       "injection dispatch skips a cylinder event when bit (cylinder_event_index & 0x3f) of (this OR "
       "cylinder_cutout_mask) is set; while it is non-zero hpcr_cbdCalculateCylinderTrims reloads crank_state_debounce_timer (no "
       "cylinder balance learning) and cm848_runCylinderContributionTest reports status 2. The ECU's own injector "
       "fault cutout is the other mask, cylinder_cutout_mask (e2m Bank_Cutoff). 0 in the RAM dump")

keep("0x0040b780", "cylinder_cutout_mask",
     "e2m 8192 +1A Bank_Cutoff (UNITLESS, 0-63) 'Bank Cutoff - bit-mapped to each cylinder' (the ECU's own injector "
     "fault cutout: engine_injectionAngle_updateCutoutAndTimingDemand ORs in 0x55 / 0xaa, one injector bank)")

keep("0x0040b784", "auxiliary_injection_quantity",
     "e2m 8192 +1E Injected_Aux_Fuel (MM3S, 0.0679) 'Amount of fuel actually implemented at auxillary injection'")

keep("0x0040b78c", "injection_quantity_scale_factor",
     "e2m 8192 +26 Speed_Limp_Derate (%, 1/512, 0-127) 'Fueling derate percentage for fuel injection when running on "
     "backup EPS' (the speed limp home fuel derate scale, 51200 = 100 percent; see speed_limp_home_derate_slew_rate)")

rename("0x00408f56", "crank_sync_event_count_min_cal", "crank_sync_event_count_limit",
       "e2m 8194 +0 [ESTDCU02] Backup_Consec_Error_Thresh (UNITLESS, 1 byte, 255 here): "
       "cm848_updateEngineSpeedFromCrankSignal compares crank_sync_event_count (+1 per pass while "
       "engine_sync_startup_countdown is 0 and the speed is non-zero, else 0) with the HIGH byte "
       "(crank_sync_event_count_min_cal._0_1_) and at the limit sets fault_detected_bits_80_to_95 bit 0x2000 (fault 93) "
       "and holds the count; the old name says minimum and has a _cal outside the EEPROM mirror; TYPE: the row is "
       "typed word but 0x408f56 is a byte - the low byte 0x408f57 (dump 1) is e2m +1 Bank_With_Added_Tooth, read as "
       "(byte)crank_sync_event_count_min_cal in hpcr_processEngineSyncPulses and mpc555_updateEngineCrankState, so "
       "the row should be split into two byte rows (those two readers would then name the second one)",
       "e2m 8194 +0 [ESTDCU02] Backup_Consec_Error_Thresh (UNITLESS, 1 byte): 'threshold count at which eps is "
       "lost'. The limit of the consecutive error count crank_sync_event_count: "
       "cm848_updateEngineSpeedFromCrankSignal adds 1 per pass while the tooth period countdown "
       "engine_sync_startup_countdown (reloaded from crank_tooth_period_timeout by mpc555_updateEngineCrankState) is "
       "0 and the engine speed is non-zero, else clears the count; at this limit it sets "
       "fault_detected_bits_80_to_95 bit 0x2000 (fault 93) and holds the count here. The main signal counterpart is "
       "e2m Main_Consec_Error_Thres, crank_sync_period_confirm_count_cal at 0x408f80 (fault 92). 255 in the RAM "
       "dump. TYPE: this row is typed word but the record is the HIGH byte (read as ._0_1_); the low byte 0x408f57 "
       "(1 in the dump) is e2m +1 Bank_With_Added_Tooth ('which crank signal window has the cam +1 pulse'), which "
       "hpcr_processEngineSyncPulses and mpc555_updateEngineCrankState compare with the TPU channel 0 bank bit as "
       "(byte) of this word - it needs its own byte row")

rename("0x00408f68", "crank_period_scale_cal", "crank_period_rpm_conversion_factor",
       "e2m 8194 +12 [ESCUCF01] Engine_Speed_Constant_1 (UNITLESS, x 0.125, 4 bytes): 'Conversion factor from tcnts "
       "to rpm - primary': cm848_updateEngineSpeedFromCrankSignal sets crank_derived_rpm = this / "
       "crank_period_accumulator and hpcr_processEngineSyncPulses builds the period variation metric from this / "
       "crank_period_accumulator and this / crank_period_prev_snapshot; lwz 2; dump 400000000; the old name has a _cal "
       "outside the EEPROM mirror",
       "e2m 8194 +12 [ESCUCF01] Engine_Speed_Constant_1 (UNITLESS, x 0.125, 4 bytes): 'Engine_Speed_Constant_1: "
       "Conversion factor from tcnts to rpm - primary'. The primary engine speed constant: "
       "cm848_updateEngineSpeedFromCrankSignal computes crank_derived_rpm (1/8 rpm per count, the engine_rpm_measured "
       "scale) = this / crank_period_accumulator (the accumulated crank period in timer counts), and "
       "hpcr_processEngineSyncPulses forms the period variation metric from this / crank_period_accumulator and this / "
       "crank_period_prev_snapshot. The backup (tooth period) counterpart is e2m Engine_Speed_Constant_1_Backup, "
       "crank_tooth_rpm_divisor_cal at 0x408f6c. 400,000,000 here")

rename("0x00408f78", "crank_teeth_per_rev", "crank_period_buffer_initial_engine_speed",
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

rename("0x00408f84", "crank_sync_timing_scale_cal", "crank_tooth_period_timeout",
       "e2m 8194 +2E [ESMXTM02] Maximum_Pulse_Period_Timeout_Backup (MSEC, 20 per count, 0-10000): 'max reset value "
       "for backup': cm848_updateEngineSpeedFromCrankSignal divides it by 1 / 2 / 4 / 8 as the filtered engine "
       "speed rises (below 256 rpm / below 511 / below 768 / above) into crank_sync_timing_scale_working, and "
       "mpc555_updateEngineCrankState reloads engine_sync_startup_countdown from that - the countdown whose expiry "
       "zeroes crank_tooth_rpm and drives crank_sync_event_count; lhz 3; dump 50 = 1000 ms; the old name has a _cal "
       "outside the EEPROM mirror",
       "e2m 8194 +2E [ESMXTM02] Maximum_Pulse_Period_Timeout_Backup (MSEC, 20 per count, 0-10000): "
       "'Maximum_Pulse_Period_Timeout_Backup:max reset value for backup'. Reload value of the backup (tooth period) "
       "pulse lost countdown: cm848_updateEngineSpeedFromCrankSignal divides it by 1 / 2 / 4 / 8 as the filtered "
       "engine speed rises (below 256 rpm / below 511 / below 768 / above) into crank_sync_timing_scale_working, and "
       "mpc555_updateEngineCrankState reloads engine_sync_startup_countdown from that on every tooth event; "
       "cm848_updateEngineSpeedFromCrankSignal counts the countdown down and, while it is 0, zeroes crank_tooth_rpm "
       "and counts crank_sync_event_count. The primary counterpart (crank_period_countdown reloaded from "
       "crank_period_raw, e2m Maximum_Pulse_Period_Timeout at 0x408f82) works the same way. 50 = 1000 ms here")

rename("0x00408f8a", "crank_sync_tooth_count_cal", "cam_wheel_pulse_count",
       "e2m 8194 +34 Number_Of_Cam_Pulses (UNITLESS, 0-255): 'Number of targets on the cam wheel': "
       "mpc555_updateEngineCrankState uses it as the offset of the second half of crank_tooth_pattern_table (26 "
       "entries = 2 x 13 = e2m Plausible_Cam_Positions) and compares crank_sync_period_counter with it, and "
       "engine_injectionAngle_tpuUpdate / _writeTpuEvent / _computeLoadCh6 / "
       "cm848_scheduleInjectionAnglesInSpeedLimpHome divide by this - 1 (12) and wrap the tooth index at it; lhz 13; "
       "dump 13; the old name has a _cal outside the EEPROM mirror",
       "e2m 8194 +34 Number_Of_Cam_Pulses (UNITLESS, 0-255): 'Number of targets on the cam wheel'. 13 here. "
       "mpc555_updateEngineCrankState uses it as the offset of the second half of crank_tooth_pattern_table (26 "
       "entries = 2 x 13, e2m Plausible_Cam_Positions) and compares crank_sync_period_counter with it; the injection "
       "angle to tooth conversions (engine_injectionAngle_tpuUpdate, engine_injectionAngle_writeTpuEvent, "
       "engine_injectionAngle_computeLoadCh6, cm848_scheduleInjectionAnglesInSpeedLimpHome) divide the tooth count by "
       "this - 1 (12) and wrap the tooth index at it")

rename("0x00408f9c", "engine_event_countdown_cal", "crank_preliminary_sync_evaluation_count",
       "e2m 8194 +46 Prelim_Sync_Evaluation_Count (UNITLESS, 0-255): 'Number of crank revs in Prelim_Sync before "
       "checking accel detection': it is the reload value of engine_event_countdown, loaded by "
       "mpc555_resetEngineTimingAccumulators, cm848_setEngineRunState3, cm848_engineRunState3Handler, "
       "cm848_engineRunState3HandlerWithTimebaseCapture and mpc555_updateEngineCrankState; in run state 3 "
       "(preliminary sync) mpc555_updateEngineCrankState counts the countdown down per event and at 0 compares "
       "crank_tooth_count_b with crank_tooth_count_b_min_cal (e2m +44 Prelim_Sync_Detection_Threshold) to enter run "
       "state 4; lhz 6; dump 6; the old name has a _cal outside the EEPROM mirror",
       "e2m 8194 +46 Prelim_Sync_Evaluation_Count (UNITLESS, 0-255): 'Number of crank revs in Prelim_Sync before "
       "checking accel detection'. Reload value of engine_event_countdown, the event countdown of run state 3 "
       "(preliminary sync) of the crank state machine: mpc555_updateEngineCrankState counts it down per event and, at "
       "0, compares crank_tooth_count_b (firing detections) with crank_tooth_count_b_min_cal (e2m "
       "Prelim_Sync_Detection_Threshold) to move to run state 4, and reloads the countdown from here; "
       "mpc555_resetEngineTimingAccumulators, cm848_setEngineRunState3, cm848_engineRunState3Handler and "
       "cm848_engineRunState3HandlerWithTimebaseCapture load it too. 6 here")

rename("0x00408fa0", "crank_rpm_divisor_cal", "crank_speed_interrupts_per_cylinder",
       "e2m 8194 +4A Sums_Per_Cylinder (UNITLESS, 0-255): 'Number of speed interrupts per cylinder': "
       "mpc555_resetEngineTimingAccumulators multiplies it by crank_period_capture_index_max_cal into "
       "crank_period_scale_divisor and programs TPU-A channel 12 PARAM7 with this x 0x100 - 0x100, and "
       "mpc555_updateEngineCrankState divides the captured tooth period by it before adding it to "
       "crank_tooth_period_sum; lhz 1; dump 4; the old name has a _cal outside the EEPROM mirror and calls it an rpm "
       "divisor",
       "e2m 8194 +4A Sums_Per_Cylinder (UNITLESS, 0-255): 'Number of speed interrupts per cylinder.' Number of speed "
       "(tooth period) interrupt sums per cylinder event: mpc555_resetEngineTimingAccumulators multiplies it by "
       "crank_period_capture_index_max_cal into crank_period_scale_divisor (the divisor of the period variation "
       "metric in hpcr_processEngineSyncPulses) and programs TPU-A channel 12 PARAM7 with this x 256 - 256; "
       "mpc555_updateEngineCrankState divides the captured tooth period by it before it adds the period to "
       "crank_tooth_period_sum. 4 here")

keep("0x00408fa2", "cylinder_event_count_max",
     "e2m 8194 +4C [EST2CY] Engine_Cylinders (UNITLESS, 0-12) 'Number of engine cylinders' (cylinder_event_count_max "
     "= the cylinder events per engine cycle, 6 here)")

rename("0x00409082", "fuel_demand_threshold_cal", "equivalent_throttle_vacuum_all_speed_governor_offset",
       "e2m 81A9 +12 Equiv_Throt_Vac_ASG_Offset (%THROTTLE, 0.25, 0-100) 'Equivalent throttle offfset.': "
       "cm848_calculateFuelDemandWithConditions, with bit 0x10 of fuel_feature_control_flags set, uses "
       "fuel_demand_control_t.calculated - this (0 when not above it) as the equivalent throttle while the governor "
       "is not in control and as the floor of the governor output (output >= demand - this) at the end; it is an "
       "offset that is subtracted, not a threshold; lhz 2 (three uses); dump 24 = 6 percent; the old name (fuel demand "
       "threshold) has a _cal outside the EEPROM mirror",
       "e2m 81A9 +12 Equiv_Throt_Vac_ASG_Offset (%THROTTLE, 0.25 percent per count, 0-100): 'Equivalent throttle "
       "offfset.' Offset of the all speed governor (ASG) equivalent throttle in the vacuum configuration: "
       "cm848_calculateFuelDemandWithConditions, when bit 0x10 of fuel_feature_control_flags (the EEPROM fuel "
       "feature word) is set, takes fuel_demand_control_t.calculated (the accelerator pedal demand, 0.25 percent per "
       "count) minus this (0 when the demand is not above it) as the equivalent throttle while the governor is not in "
       "control, and at the end keeps fuel_demand_governor_output at least demand minus this. 24 = 6 percent in the "
       "RAM dump")
