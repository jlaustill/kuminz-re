# records 46-62 of bin5

keep("0x0040b38e", "pci_message_error_flags",
     "e2m 8A11 +0 Sticky_Err (HEX) 'J1850 ECM Network Specific Error Trap, Only msg. TAGGED Sticky_Error Applic.' "
     "(the OR of the error status bits of the known TX / RX messages)")

keep("0x0040b3a5", "pci_unmatched_frame_error_flags",
     "e2m 8A11 +17 Nonspec_Err (HEX) 'J1850 Generic Network Error Trap, All other messages on bus are Applic.' (the "
     "OR of the error bits of frames whose header matched no table entry)")

keep("0x0040b3bc", "pci_normal_transmit_disabled",
     "e2m 8A11 +2E J1850_Tx_Freeze (UNITLESS, 0-1) 'J1850 Transmit Network activity, Enable=1=Frozen Disable=0=Active' "
     "(frozen = normal PCI message transmission disabled)")

keep("0x0040b3bd", "pci_receive_processing_disabled",
     "e2m 8A11 +2F J1850_Rx_Freeze (UNITLESS, 0-1) 'J1850 Receive Network activity, Enable=1=Frozen Disable=0=Active' "
     "(frozen = PCI receive processing disabled)")

rename("0x0040b57a", "protection_output_hold_flag", "converter_clutch_engaged_since_low_speed_flag",
       "e2m 8C34 +0 TCC_Engagement_Since_Low_Speed (UNITLESS, 0-1): "
       "cm848_monitorConverterClutchAndOverdrivePerformance clears it when the converter clutch solenoid request is "
       "off and vehicle_speed is below converter_clutch_engagement_low_speed (e2m 8C33 +0 TCC_Engagement_Low_Speed "
       "'Speed when TCC_Engagement_Since_Low_Speed clears'), sets it when an engagement cannot be judged or has been "
       "judged, and returns early while it is set; the old name (protection output hold) is an older guess; sth 1; "
       "dump 0. The ECU's table also resolves e2m 8C5B +A PN_Ratio (the park neutral in-use performance ratio) to this "
       "address - the same kind of spill as 8C56 +4 - and this code does not hold that ratio here",
       "e2m 8C34 +0 TCC_Engagement_Since_Low_Speed (UNITLESS, 0-1): 'Indicates if TCC has been engaged since last low "
       "speed'. Torque converter clutch engagement flag of the P1740 converter clutch / overdrive performance monitor "
       "(cm848_monitorConverterClutchAndOverdrivePerformance): cleared when the converter clutch solenoid request is "
       "off and vehicle_speed is below converter_clutch_engagement_low_speed (e2m TCC_Engagement_Low_Speed); set to 1 "
       "when an engagement cannot be judged (throttle not steady) or has been judged, and the monitor returns early "
       "while it is set, so each engagement after a low speed is checked once. The ECU's parameter ID table also maps "
       "e2m 8C5B +A PN_Ratio (an in-use performance ratio of the park neutral monitor) to this address; that ratio is "
       "not held here (block 8C5B ends before +A in this build), so only the TCC record is documented. 0 in the RAM "
       "dump")

rename("0x0040b57c", "protection_fuel_derate_increment_counter", "converter_clutch_rationality_fail_count",
       "e2m 8C34 +2 TCC_Rationality_Fail_Count_This_Trip (CNTS, 0-255, 1 byte): "
       "cm848_monitorConverterClutchAndOverdrivePerformance adds 1 per missed ratio test and clears it on a pass; at "
       "protection_fuel_derate_increment_counter_max (e2m 8C33 +6 TCC_Rationality_Fail_Count_Limit) it holds there, "
       "sets fault_detected_bits_304_to_319 bit 0x8000 (fault 319) and monitor phase 3; stb 1; dump 0; the old name "
       "(fuel derate increment) is an older guess",
       "e2m 8C34 +2 TCC_Rationality_Fail_Count_This_Trip (CNTS, 0-255): 'Number of consecutive failures this trip'. "
       "Consecutive failure count of the P1740 converter clutch / overdrive rationality test "
       "(cm848_monitorConverterClutchAndOverdrivePerformance): +1 on each missed test (the ratio delta sum below its "
       "minimum, or the lockup gear ratio outside its limits), cleared by a pass; at "
       "protection_fuel_derate_increment_counter_max (e2m TCC_Rationality_Fail_Count_Limit) it holds at the limit, "
       "fault_detected_bits_304_to_319 bit 0x8000 (fault 319) is set and the monitor phase becomes 3. 0 in the RAM "
       "dump")

rename("0x0040b581", "protection_pid_rpm_setpoint", "converter_clutch_rationality_ratio",
       "e2m 8C34 +7 TCC_Rationality_Ratio (UNITLESS, 1/256, 0-255) 'Engine RPM/Transmission OSS Ratio': "
       "cm848_monitorConverterClutchAndOverdrivePerformance stores cm848_calculateEngineToOutputSpeedRatio() "
       "(filtered engine speed x 256 / transmission_output_speed_in_use) into it and cm848_pidError_calc takes the "
       "previous ratio minus it; lhz 1 / sth 2; dump 0; the old name (protection pid rpm setpoint) is an older guess",
       "e2m 8C34 +7 TCC_Rationality_Ratio (UNITLESS, 1/256 per count, 0-255): 'Engine RPM/Transmission OSS Ratio'. The "
       "engine speed to transmission output speed ratio (cm848_calculateEngineToOutputSpeedRatio: filtered engine "
       "speed x 256 / transmission_output_speed_in_use, 0xffff when the output speed is 0) that "
       "cm848_monitorConverterClutchAndOverdrivePerformance samples when a converter clutch engagement starts and on "
       "each timed step; cm848_pidError_calc subtracts it from the previous sample (the ratio delta that "
       "cm848_pidIntegrator_accumulate sums). 0 in the RAM dump")

rename("0x0040b583", "protection_pid_integrator", "converter_clutch_rationality_ratio_delta_sum",
       "e2m 8C34 +9 TCC_Rationality_Sum_Ratio_Delta (UNITLESS, 1/256, signed -128..127) 'Sum of ratio deltas while "
       "monitor is running': cm848_pidIntegrator_accumulate adds protection_pid_error_term (previous ratio minus "
       "ratio, clamped +-0x8000) to it, clamped to a signed word, and the monitor compares it with the signed "
       "protection_pid_integrator_threshold (e2m 8C33 +7 TCC_Rationality_Min_Ratio_Delta 'Min RPM/OSS ratio sum to "
       "pass'); sth 1 / lha 2 (signed: i16 would fit); dump 0; the old name (protection pid integrator) is an older "
       "guess",
       "e2m 8C34 +9 TCC_Rationality_Sum_Ratio_Delta (UNITLESS, 1/256, signed, -128 to 127): 'Sum of ratio deltas while "
       "monitor is running'. Running sum of the engine / output speed ratio deltas of the converter clutch "
       "rationality test: cm848_pidIntegrator_accumulate adds protection_pid_error_term (previous ratio minus the new "
       "converter_clutch_rationality_ratio, from cm848_pidError_calc) and clamps the sum to a signed word; it is "
       "cleared while the converter clutch is off, and once the rationality timer reaches its limit a sum below the "
       "signed minimum protection_pid_integrator_threshold (e2m 8C33 +7 TCC_Rationality_Min_Ratio_Delta, 'Min RPM/OSS "
       "ratio sum to pass') counts as a missed test. Signed (lha). 0 in the RAM dump")

rename("0x0040b585", "protection_pid_step_counter", "converter_clutch_rationality_timer",
       "e2m 8C34 +B TCC_Rationality_Timer (SEC, 0.5 per count, 0-127.5, 1 byte) 'Timer for TCC engagement before error "
       "is set': cm848_monitorConverterClutchAndOverdrivePerformance (one pass per 0.5 s = every 5th call of the "
       "0.1 s task) restarts it at 0 when an engagement starts and adds 1 per pass up to "
       "protection_pid_step_count_threshold (e2m 8C33 +9 TCC_Rationality_Max_Time) or "
       "protection_pid_step_count_threshold_b (e2m 8C33 +12 TCC_OD_Rationality_Time); stb 1; dump 0; the old name "
       "(protection pid step counter) is an older guess",
       "e2m 8C34 +B TCC_Rationality_Timer (SEC, 0.5 s per count, 1 byte): 'Timer for TCC engagement before error is "
       "set'. Engagement timer of the converter clutch rationality test: "
       "cm848_monitorConverterClutchAndOverdrivePerformance (one pass every 0.5 s: every 5th call of the 0.1 s task) "
       "restarts it at 0 when an engagement starts and adds 1 per pass up to protection_pid_step_count_threshold "
       "(e2m 8C33 +9 TCC_Rationality_Max_Time) or protection_pid_step_count_threshold_b (e2m 8C33 +12 "
       "TCC_OD_Rationality_Time, the time after lockup for the overdrive check); at the limit the ratio delta sum is "
       "judged. 0 in the RAM dump")

rename("0x0040b586", "protection_output_stability_counter", "converter_clutch_steady_throttle_count",
       "e2m 8C34 +C TCC_Steady_Throttle_Counts (CNTS, 0-255) 'Number of counts with steady throttle': "
       "cm848_monitorConverterClutchAndOverdrivePerformance adds 1 per pass in which fuel_demand_control_t.calculated "
       "moved less than converter_clutch_maximum_throttle_delta (e2m TCC_Max_Delta_Throttle) up to "
       "protection_output_stability_threshold (e2m 8C33 +A TCC_Steady_Throttle_Count_Limit) and clears it on a larger "
       "change; the test only proceeds with the count at the limit; lhz 4 / sth 1; dump 9; the old name (protection "
       "output stability) is an older guess",
       "e2m 8C34 +C TCC_Steady_Throttle_Counts (CNTS, 0-255): 'Number of counts with steady throttle'. Steady "
       "throttle pass count of the converter clutch rationality test: "
       "cm848_monitorConverterClutchAndOverdrivePerformance adds 1 per pass in which fuel_demand_control_t.calculated "
       "changed by less than converter_clutch_maximum_throttle_delta (e2m TCC_Max_Delta_Throttle) since the previous "
       "pass, up to protection_output_stability_threshold (e2m 8C33 +A TCC_Steady_Throttle_Count_Limit, 'Minimum "
       "interations with steady throttle'), and clears it on a larger change; an engagement is only judged while the "
       "count is at that limit. 9 in the RAM dump")

rename("0x0040b588", "protection_rpm_sample", "converter_clutch_lockup_gear_ratio",
       "e2m 8C34 +E TCC_OD_Gear_Ratio (UNITLESS, 1/256, 0-255) 'Calculated gear ratio after TCC lockup for TCC/OD "
       "diagnostics': cm848_monitorConverterClutchAndOverdrivePerformance stores "
       "cm848_calculateEngineToOutputSpeedRatio() into it once after lockup and compares it with "
       "converter_clutch_lockup_third_gear_minimum_ratio / _maximum_ratio (overdrive solenoid request clear) or "
       "converter_clutch_lockup_fourth_gear_ratio_limit (set); sth 1; dump 0; the old name (protection rpm sample) is "
       "an older guess",
       "e2m 8C34 +E TCC_OD_Gear_Ratio (UNITLESS, 1/256, 0-255): 'Calculated gear ratio after TCC lockup for TCC/OD "
       "diagnostics'. The engine / output speed ratio sampled once after converter clutch lockup by "
       "cm848_monitorConverterClutchAndOverdrivePerformance and judged against the overdrive limits: with the "
       "overdrive solenoid request clear (third gear) a ratio outside "
       "converter_clutch_lockup_third_gear_minimum_ratio .. converter_clutch_lockup_third_gear_maximum_ratio is a miss, "
       "with it set (fourth gear) a ratio above converter_clutch_lockup_fourth_gear_ratio_limit is a miss (at or below "
       "is a pass). 0 in the RAM dump")

rename("0x0040b58a", "protection_derate_recovery_counter", "converter_clutch_rationality_pass_count",
       "e2m 8C34 +10 TCC_Rationality_Pass_Count_This_Trip (CNTS, 0-255, 1 byte): "
       "cm848_monitorConverterClutchAndOverdrivePerformance adds 1 per passed test and clears it on a miss; at "
       "converter_clutch_rationality_pass_count_limit (e2m 8C33 +13 TCC_Rationality_Pass_Count_Limit 'Number of "
       "consecutive passes required to clear error') it clears fault 319 (bit 0x8000 of "
       "fault_detected_bits_304_to_319) and sets monitor phase 2; stb 2 / lbz 1; dump 0; the old name (derate "
       "recovery) is an older guess",
       "e2m 8C34 +10 TCC_Rationality_Pass_Count_This_Trip (CNTS, 0-255): 'Number of consective passes this trip'. "
       "Consecutive pass count of the P1740 converter clutch / overdrive rationality test "
       "(cm848_monitorConverterClutchAndOverdrivePerformance): +1 on each passed test, cleared by a miss; at "
       "converter_clutch_rationality_pass_count_limit (e2m TCC_Rationality_Pass_Count_Limit, 'Number of consecutive "
       "passes required to clear error') the monitor clears fault 319 (bit 0x8000 of fault_detected_bits_304_to_319) "
       "and its phase becomes 2. 0 in the RAM dump")

rename("0x0040b55a", "j1939_fault_load_protection_trip_count", "governor_pressure_rationality_fail_count",
       "e2m 8C56 +0 RE_Governor_Pr_Rationality_Fails_This_DC (CNTS, 0-100, 1 byte): "
       "cm848_monitorGovernorPressureSensorOffset (P1762, 48RE governor pressure in park / neutral at light throttle) "
       "adds 1 when the in range window check stays failed past governor_pressure_rationality_maximum_time, clears it "
       "on an in range reading, and sets fault 149 (bit 0x20 of fault_detected_bits_144_to_159) above "
       "governor_pressure_rationality_fail_count_limit (e2m 8C55 +6); stb 1; dump 0; the old name (J1939 fault load "
       "protection) names neither the monitor nor its domain",
       "e2m 8C56 +0 RE_Governor_Pr_Rationality_Fails_This_DC (CNTS, 0-100, 1 byte): 'Number of times rationality "
       "monitor detected error'. Failure count of the 48RE governor pressure sensor offset check "
       "(cm848_monitorGovernorPressureSensorOffset, P1762: park / neutral switch 20, light throttle, transmission "
       "temperature window): +1 each time governor_pressure stays outside "
       "governor_pressure_rationality_minimum_pressure .. governor_pressure_rationality_maximum_pressure for longer "
       "than governor_pressure_rationality_maximum_time, cleared by an in range reading; above "
       "governor_pressure_rationality_fail_count_limit it sets fault 149 (bit 0x20 of "
       "fault_detected_bits_144_to_159). 0 in the RAM dump")

rename("0x0040b55b", "j1939_fault_load_protection_debounce_count", "governor_pressure_rationality_timer",
       "e2m 8C56 +1 RE_Governor_Pressure_Rationality_Timer (SEC, 0.5 per count, 0-100, 1 byte): "
       "cm848_monitorGovernorPressureSensorOffset adds 1 per pass while its enabling conditions hold and compares it "
       "with governor_pressure_rationality_maximum_time (e2m 8C55 +7 RE_Governor_Pressure_Rationality_Max_Time 'Max "
       "time for governor pressure monitor to pass'), and clears it when the conditions drop; stb 1; dump 0; the old "
       "name (J1939 fault load protection) names neither the monitor nor its domain",
       "e2m 8C56 +1 RE_Governor_Pressure_Rationality_Timer (SEC, 0.5 s per count, 1 byte): 'Timer for governor "
       "pressure rationality'. Timer of the 48RE governor pressure sensor offset check "
       "(cm848_monitorGovernorPressureSensorOffset, P1762): +1 per pass while the enabling conditions hold (park / "
       "neutral switch 20, light throttle, transmission temperature window, no related fault); when it exceeds "
       "governor_pressure_rationality_maximum_time (e2m RE_Governor_Pressure_Rationality_Max_Time, 'Max time for "
       "governor pressure monitor to pass') and governor_pressure is still outside the in range window the "
       "failure count governor_pressure_rationality_fail_count is incremented; cleared when the conditions drop. "
       "0 in the RAM dump")

rename("0x0040b55e", "protection_coldStart_channelA_trip_count", "governor_pressure_zero_check_fail_count",
       "the bin's record e2m 8C56 +4 Gov_Press_Rat_Ratio (in-use performance ratio of the transmission oil pressure "
       "rationality) does NOT match the code (block 8C56 ends after +2 here), but the ECU's table resolves e2m 8C58 +0 "
       "RE_Governor_Pr_Zero_Rat_Fails_This_DC (CNTS 'Number of times monitor has detected failures this DC') to the "
       "same address and that one fits: cm848_monitorGovernorPressureTracking adds 1 per failed zero check "
       "(vehicle stopped, governor pressure target at or below protection_coldStart_channelA_rpm_min_threshold, "
       "governor_pressure above governor_pressure_zero_check_high_limit for more than "
       "governor_pressure_zero_check_debounce_count_limit passes) "
       "while below governor_pressure_zero_check_fail_count_limit (e2m 8C59 +0), at the limit the next failure sets "
       "fault 391 (bit 0x80 of fault_detected_bits_384_to_399); census blind; dump 0; the old name (cold start "
       "protection channel A) is an older guess - if you treat the bin record as drift, keep the old name and use "
       "this as the lead",
       "e2m 8C58 +0 RE_Governor_Pr_Zero_Rat_Fails_This_DC (CNTS): 'Number of times monitor has detected failures this "
       "DC'. Failure count of the 48RE governor pressure zero check of cm848_monitorGovernorPressureTracking (vehicle "
       "stopped with the governor pressure target at or below protection_coldStart_channelA_rpm_min_threshold, e2m "
       "RE_Governor_Pr_Zero_Set_High_Limit: governor_pressure above "
       "governor_pressure_zero_check_high_limit for more than governor_pressure_zero_check_debounce_count_limit "
       "passes): +1 per failed evaluation while below governor_pressure_zero_check_fail_count_limit (e2m "
       "RE_Governor_Pr_Zero_Rat_Fail_Count_Limit), and at the limit the next failure sets fault 391 (bit 0x80 of "
       "fault_detected_bits_384_to_399). The ECU's table also resolves e2m 8C56 +4 Gov_Press_Rat_Ratio (the in-use "
       "performance ratio of the transmission oil pressure rationality) to this address, but block 8C56 ends before "
       "+4 in this build and the code holds the zero check failure count here. 0 in the RAM dump")

rename("0x003fedfa", "diag_response_pending_flag", "transmission_learned_info_stored_flags_byte_1_cal",
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
       "not used by the application. The first flag byte is transmission_learned_info_stored_flags_byte_1_cal at "
       "0x3fedfa. TIME-SHARED: the boot reflash kernel reuses this byte as an SCI checksum "
       "(mpc555_sciTransmitChecksummedByte). 1 in the RAM dump (HP Tuners zeroes it) (Medium confidence)")
