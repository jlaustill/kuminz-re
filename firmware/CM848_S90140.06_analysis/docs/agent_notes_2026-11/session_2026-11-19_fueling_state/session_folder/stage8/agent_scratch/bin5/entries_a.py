# records 0-22 of bin5

keep("0x003fd4b2", "key_on_hour_meter_cal",
     "e2m 0027 +0 [CMECBUTR] ECM_Run_Time_Backup (SEC, 0.2 s per count) 'Non-volatile copy of ECM_Run_Time' "
     "(ECM_Run_Time = 'Time key switch is on and ECM is running boot or application code' = key_on_hour_meter)")

rename("0x003fd510", "checksum_validation_step_counter", "calibration_download_security_key_cal",
       "e2m 1000 +0 Security_Key (HEX, 2 bytes): the word is compared with 0xFF in six loads to bypass the security "
       "checks - cm848_validatePciSecurityKey and cm848_sciValidateSecurityKey (key accepted), "
       "cm848_processSecurityCodeConversion, j1939_writeDiagMemory (twice) and j1939_diagServiceDispatch; no use is a "
       "checksum or a step counter; lhz 6; dump 0 (EEPROM 0x8e is 0 in all four EEPROM dumps)",
       "e2m 1000 +0 Security_Key (HEX, 2 bytes): 'Key which provides access to calibration dl.' (EEPROM 0x8e, mirror). "
       "The security switch of the calibration download / diagnostic access: the value 0xFF bypasses the seed / key "
       "checks - cm848_validatePciSecurityKey (PCI 0x27 security access) and cm848_sciValidateSecurityKey (SCI key "
       "check) accept any key, cm848_processSecurityCodeConversion returns 0 at once, j1939_writeDiagMemory skips its "
       "security gate (twice) and j1939_diagServiceDispatch lets the services marked in the ROM bitmap 0x5a486 "
       "through without a key. Any other value leaves the checks active. 0 in the RAM dump and in all four EEPROM "
       "dumps")

rename("0x0040aeb0", "governor_speed_filter_output", "low_speed_governor_alternator_load_fuel",
       "e2m 1065 +1C Alternator_Load (MM3S, 0.0679, signed): cm848_runLowSpeedGovernor stores "
       "cm848_signedFirstOrderFilter((governor_speed_filter_input_scale_cal x (alternator_field_duty_target - "
       "governor_speed_filter_fuel_offset_cal)) >> 14, &governor_speed_filter) in it and adds it to the low speed "
       "governor fueling sum; e2m 1064 +2A / +2C LSG_EVR_Gain / LSG_EVR_Offset ('EVR duty cycle to fuel conversion') "
       "sit at those two cals; the old name says speed filter; sth 1 / lha 1 (signed: i16 would fit); dump -18",
       "e2m 1065 +1C Alternator_Load (MM3S, 0.0679 mm3 per count, signed): 'Calculated fuel value to add to LSG'. The "
       "alternator load term of the low speed governor (LSG): cm848_runLowSpeedGovernor converts the alternator field "
       "duty (alternator_field_duty_target, the EVR duty) to fuel with (governor_speed_filter_input_scale_cal x (duty "
       "- governor_speed_filter_fuel_offset_cal)) >> 14 (e2m LSG_EVR_Gain / LSG_EVR_Offset), filters it with "
       "governor_speed_filter (e2m Alternator_Load_Filter_Coefficient) into this word and adds it to the other LSG "
       "terms that make low_speed_governor_fueling_working. cm848_applyProtectionRpmCorrectionFilter also adds it to "
       "governor_integral_component_a / _b (floored at 0), looks the sum up in the combustion torque by fuel quantity "
       "grid and subtracts the result from the net combustion torque (net_machine_torque). Signed (lha). -18 "
       "(-1.2 mm3) in the RAM dump")

keep("0x0040ae6c", "pedal_fault_mode_fuel_demand_ramp",
     "e2m 10CF +0 [LHFL] Limp_Home_Fueling (MM3S) 'Fueling value from Limp Home Algorithm' (limp home = the "
     "accelerator pedal fault mode, engine operating mode 6)")

keep("0x0040ae6e", "pedal_fault_mode_fuel_demand_limit",
     "e2m 10CF +2 [LHMXFL] Limp_Home_Max_Fueling (MM3S) 'Calculated fueling value dependent upon engine speed' (the "
     "limit is pedal_fault_mode_fuel_demand_limit_offset minus a term of the filtered engine speed)")

rename("0x003fde48", "fuel_demand_histogram_sample_count", "load_histogram_total_sample_count_cal",
       "e2m 1122 +4 DC_Mon_Long_Map_Total (HR, 0.0000277777 per count = 0.1 s, max 100000 HR): "
       "cm848_outputs2_periodic (every 0.1 s: scheduler phases 0x13 and 0x27) adds 1 per load histogram sample and "
       "stops at 3600000000 = 100000 h, the record's max, zeroes it with the bin counters on the SCI cmd 20 clear and "
       "divides the bin sums by it for percent_time_at_load_cal; stw 1; dump 3203448 = 89.0 h (EEPROM 0x9c6); the "
       "old name sits in the EEPROM mirror without _cal",
       "e2m 1122 +4 [DCLGMPTL] DC_Mon_Long_Map_Total (HR, 1 count = 0.1 s, max 100000 h): 'Duty Cycle Monitor Long "
       "Term Map Total Time'. EEPROM 0x9c6 (mirror). Total number of load histogram (duty cycle monitor) samples = the "
       "monitored time in 0.1 s counts: cm848_outputs2_periodic runs every 0.1 s and adds 1 per engine-running sample "
       "while it is below 3,600,000,000 (= 100,000 h, the record's maximum); it is the divisor of "
       "percent_time_at_load_cal (25600 = 100 percent) and is zeroed with the 82 fine bin counters (the dwords from "
       "0x3fde4e) and percent_time_at_load_cal by the SCI command 20 clear; while it is 0 the next sample stores "
       "load_histogram_start_engine_hours_cal. 3,203,448 = 89.0 h in the RAM dump (HP Tuners zeroes it)")

rename("0x003feb8e", "etc1_state_timer_b", "j1939_link_fault_timeout_count_cal",
       "e2m 11C1 +2 [JC39TMCU] J1939_Link_Fault_Timeout_Count (CNTS, 0-1000): cm848_processGovernorModeTransition adds "
       "1 per expiry of the TSC1 / retarder request timers handled while j1939_tsc1_override_state.etc1_active_state "
       "is 1 (written only by the J1939 TSC1 receive handler torqueControlModeHandler) up to "
       "j1939_link_fault_timeout_count_limit (e2m Jcomm_Link_Fault_Timeout_Limit), then sets "
       "fault_detected_bits_112_to_127 bit 0x1 (fault 112) and clears it; its +0 twin 0x3feb8c counts the other "
       "path (fault 110) = e2m J1708_Link_Fault_Timeout_Count; census blind; dump 0 (EEPROM 0x170c is 0 in all "
       "dumps); the old name is no timer and sits in the EEPROM mirror without _cal",
       "e2m 11C1 +2 [JC39TMCU] J1939_Link_Fault_Timeout_Count (CNTS, 0-1000): 'Current number of J1939 time-outs since "
       "powerdown or fault set'. EEPROM 0x170c (mirror). cm848_processGovernorModeTransition adds 1 per expired TSC1 "
       "(or retarder control) request timer while j1939_tsc1_override_state.etc1_active_state is 1 (torqueControlModeHandler, "
       "the J1939 TSC1 receive handler, is the only writer of that state) and the count is below "
       "j1939_link_fault_timeout_count_limit (e2m Jcomm_Link_Fault_Timeout_Limit, 100 here); at the limit it sets "
       "fault_detected_bits_112_to_127 bit 0x1 (fault 112) and returns to 0. The twin at +0 (0x3feb8c) counts the "
       "path with another state and sets fault 110 (bit 0x4000 of fault_detected_bits_96_to_111): e2m "
       "J1708_Link_Fault_Timeout_Count. 0 in the RAM dump")

keep("0x0040af06", "fault_aging_triggered_flag",
     "e2m 1226 +8 [DGDRCY] Drive_Cycle (UNITLESS) 'Indicates whether a drive cycle has occurred' (the flag is set once "
     "the engine has run drive_cycle_minimum_engine_run_time passes; it then allows fault aging and removal)")

rename("0x0040af07", "coolant_overheat_condition_flags", "warm_up_cycle_condition_flags",
       "e2m 1226 +9 [DGWUCYFL] Warm_Up_Cycle_Flag (UNITLESS, 1 byte): engine_coolantTemp_overheat_monitor sets bit 0 "
       "when coolant_temp exceeds warm_up_cycle_start_coolant_temperature by more than 0x9ff (40 F) and bit 1 above "
       "warm_up_cycle_minimum_coolant_temperature (140 F); at 3 it adds 1 to fault_auto_clear_warm_up_cycle_count_cal "
       "and calls fault_ring_buffer_auto_clear_emission = the OBD warm-up cycle, no overheat monitor; no census "
       "width (byte per code); dump 0. The function name is wrong too",
       "e2m 1226 +9 [DGWUCYFL] Warm_Up_Cycle_Flag (UNITLESS, 1 byte): 'Indicates whether warm up cycle has "
       "occurred'. The OBD warm-up cycle bits, set by engine_coolantTemp_overheat_monitor (its name is a misnomer): "
       "bit 0 = coolant_temp has risen more than 0x9ff / 64 = 40 deg F above warm_up_cycle_start_coolant_temperature "
       "(the sample taken after the startup delay), bit 1 = coolant_temp is above "
       "warm_up_cycle_minimum_coolant_temperature (8960 = 140 deg F). Both set (3) = a warm-up cycle has occurred: the "
       "monitor then stops evaluating, adds 1 to fault_auto_clear_warm_up_cycle_count_cal (modulo 40) and calls "
       "fault_ring_buffer_auto_clear_emission, which clears the fault ring. 0 in the RAM dump (engine off)")

rename("0x0040af0a", "diagnostic_suppress_flag", "end_of_line_mil_override_state",
       "e2m 1226 +C EOL_Mil_State (UNITLESS, 0 none / 1 on / 2 flash on / 3 flash off): written only by "
       "diag_suppress_stateMachine, which cm848_runEndOfLineTestSequence and the end-of-line test steps (for example "
       "cm848_runEndOfLineMisfireTestStep) drive; cm848_updateMilOnRequest forces the MIL request on at 1 and "
       "cm848_processPciRemoteFaultStatus ignores the PCM's MIL request while it is non-zero; only 0 and 1 are ever "
       "stored; lbz 3 / stb 2; dump 0",
       "e2m 1226 +C EOL_Mil_State (UNITLESS): 'EOL Mil override state (0 none, 1 on, 2 flash on, 3 flash off)'. The "
       "malfunction indicator lamp override of the Chrysler end-of-line (in-plant) test. diag_suppress_stateMachine "
       "(called by cm848_runEndOfLineTestSequence and its test steps) sets it: state 3 saves 1 and sets 1 (lamp on), "
       "state 1 saves the current value and sets 0 (and requests the flash, end_of_line_mil_flash_request_flag), "
       "state 2 restores the saved value, state 0 clears both. cm848_updateMilOnRequest: 0 = the MIL request follows "
       "the fault slots (fault_status_array bit 0x10), 1 = the request is forced on, any other value leaves it "
       "unchanged; cm848_processPciRemoteFaultStatus ignores the PCM's MIL request (RX[8] bit 7) while it is "
       "non-zero. Only 0 and 1 are written in this firmware (the e2m flash states 2 / 3 are never set). 0 in the "
       "RAM dump")

rename("0x0040af0b", "diag_suppress_active_flag", "end_of_line_mil_flash_request_flag",
       "e2m 1226 +D EOL_Mil_Flash (UNITLESS, 0 no flash / 1 flash): diag_suppress_stateMachine sets it to 1 at state 1 "
       "and clears it at states 2 and 3; cm848_buildPciTransmitMessage3MilAndDtcDisplay sends it as bit 5 of PCI "
       "TX[3] (0xB0) byte 1 only while end_of_line_test_settings_cal.field_mode_register is 5100 (0x13ec), the "
       "end-of-line mode; stb 3 / lbz 1; dump 0",
       "e2m 1226 +D EOL_Mil_Flash (UNITLESS, 0-1): 'EOL Mil Flash request (0 no flash, 1 flash)'. The flash request of "
       "the end-of-line (in-plant) test MIL override: diag_suppress_stateMachine sets it to 1 at state 1 (which also "
       "saves and clears end_of_line_mil_override_state) and clears it at states 2 and 3; "
       "cm848_buildPciTransmitMessage3MilAndDtcDisplay puts it into bit 5 of PCI TX[3] (0xB0) byte 1 while "
       "end_of_line_test_settings_cal.field_mode_register is 5100 (0x13ec). 0 in the RAM dump")

keep("0x0040afaa", "accelerator_pedal_press_count",
     "e2m 142D +2 [THDGCYCU] Throttle_Cycle_Counter (CNTS, 0-10) 'Counter of throttle cycles' (accelerator pedal "
     "presses counted by cm848_countAcceleratorPedalPresses)")

keep("0x0040b99e", "boost_pressure_pre_start_check_fault_flag",
     "e2m 1632 +0 BIR_Startup_Error (UNITLESS, 2 bytes) 'Boost sensor fault detected at power up' (BIR = boost in "
     "range; this is the pre-start MAP limit / barometric correlation check result)")

drift("0x0040b9a2", "cssc_coolant_monitoring_cycle_count",
      "e2m 1632 +4 BIR_Ratio (BIR_Numerator / BIR_Denominator, 0-7.99527) resolves here but the code holds something "
      "else: cm848_checkCoolantTemperatureSensorPerformance (P0116 coolant temperature rationality) clears this word "
      "at the start of a run, adds 1 per pass and compares it with ROM DAT_000642d8 (sth only), and its neighbours "
      "0x40b9a4 cssc_coolant_temp_span and 0x40b9a6 engine_cssc_coolant_state belong to the same monitor, so block "
      "1632 of 11.46.06 ends after +2 (0x40b9a0 boost_pressure_monitor_state_code) and the 11.45 ratio record has no "
      "word here; keep the role, but 'cssc' is an invented abbreviation: the whole cssc_coolant_* family "
      "(0x40b9a2, 0x40b9a4, 0x3fd18a-0x3fd190, engine_cssc_coolant_state) should become "
      "coolant_temperature_sensor_performance_* in one family rename; dump 0")

rename("0x00407186", "governor_speed_margin_cal_a", "barometric_pressure_sensor_tolerance",
       "e2m 165C +0 Ambient_Air_Sensor_Tolerence (IN_HG, 0.0159): cm848_checkSensorDeviationFlags adds the three "
       "tolerances in pairs to abs(reading - reading) tests of three pressure readings (barometric_pressure, channel 77 "
       "governor_integrator_bound_a, channel 38 governor_integrator_bound_b), this one belonging to the barometric "
       "reading; e2m +6 Pressure_Check_Delay_Time = cold_start_sensor_deviation_delay_cal (400 passes) gates the "
       "same check in cm848_processSensorDeviationOnKeyoff; nothing to do with a governor speed margin; the check "
       "is off here (algorithm_enable_flags_6_cal bit 0x20 clear, 0x801f); census blind; dump 0",
       "e2m 165C +0 Ambient_Air_Sensor_Tolerence (IN_HG, 0.0159 per count = 1/18.56 kPa, 0-20): 'Error Tolerence of "
       "Ambient Air Pressure Sensor'. Tolerance of the barometric pressure sensor (sensor_readings_t.barometric_pressure) "
       "in the pressure sensor agreement check cm848_checkSensorDeviationFlags: a sensor's bit of "
       "iat_sensor_deviation_flags is set when it differs from BOTH other pressure readings by more than the sum of "
       "the two tolerances, e.g. abs(barometric_pressure - governor_integrator_bound_a) > this + "
       "boost_pressure_sensor_tolerance and abs(barometric_pressure - governor_integrator_bound_b) > this + "
       "oil_pressure_sensor_tolerance. cm848_processSensorDeviationOnKeyoff runs the check once per power cycle "
       "(re-armed by cm848_resetSensorDeviationTracking) after the engine has been stopped for "
       "cold_start_sensor_deviation_delay_cal passes (e2m Pressure_Check_Delay_Time), only when bit 0x20 of "
       "algorithm_enable_flags_6_cal is set (0x801f here: off). 0 in the RAM dump")

rename("0x00407188", "governor_speed_margin_cal_b", "boost_pressure_sensor_tolerance",
       "e2m 165C +2 Boost_Sensor_Tolerence (IN_HG, 0.0159): second tolerance of cm848_checkSensorDeviationFlags, paired "
       "with sensor channel 77 (governor_integrator_bound_a = sensor_channel_filtered_output[77], set by "
       "cm848_sensorChannel4, 1703 in the dump against 1700 intake manifold and 1647 barometric counts, and the "
       "numerator of turbocharger_speed_sensor_pressure_ratio); the old name says governor speed margin; the check is "
       "off here (algorithm_enable_flags_6_cal bit 0x20 clear); census blind; dump 0",
       "e2m 165C +2 Boost_Sensor_Tolerence (IN_HG, 0.0159 per count = 1/18.56 kPa, 0-20): 'Error Tolerence of Boost "
       "Pressure Sensor'. Tolerance of the second pressure reading of cm848_checkSensorDeviationFlags, sensor channel "
       "77 (governor_integrator_bound_a = sensor_channel_filtered_output[77], configured by cm848_sensorChannel4: "
       "1703 counts in the RAM dump against 1700 intake manifold and 1647 barometric, and the numerator of "
       "turbocharger_speed_sensor_pressure_ratio). Used in the sums with barometric_pressure_sensor_tolerance and "
       "oil_pressure_sensor_tolerance, see the first. The check only runs when bit 0x20 of "
       "algorithm_enable_flags_6_cal is set (off here). 0 in the RAM dump")

rename("0x0040718a", "governor_speed_margin_cal_c", "oil_pressure_sensor_tolerance",
       "e2m 165C +4 Oil_Sensor_Tolerence (PSI_G, 0.0078 = 1/18.56 kPa per count): third tolerance of "
       "cm848_checkSensorDeviationFlags, paired with channel 38 (governor_integrator_bound_b = "
       "sensor_channel_filtered_output[38], 0 in the dump and no sensor channel wrapper passes channel 38, so the "
       "oil identity comes from the e2m order ambient / boost / oil that the code's pairing follows, not from the "
       "channel); the old name says governor speed margin; the check is off here (algorithm_enable_flags_6_cal bit "
       "0x20 clear); lhz 3; dump 0",
       "e2m 165C +4 Oil_Sensor_Tolerence (PSI_G, 0.0078 per count = 1/18.56 kPa, 0-10): 'Error_Tolerence of Oil "
       "Pressure Sensor'. Tolerance of the third pressure reading of cm848_checkSensorDeviationFlags "
       "(governor_integrator_bound_b = sensor_channel_filtered_output[38]; the code's pairing order barometric / "
       "channel 77 / channel 38 follows the e2m order ambient / boost / oil, but no sensor channel wrapper is "
       "configured for channel 38 and it reads 0 in the RAM dump, so the oil identity is the e2m's). Used in the "
       "sums with barometric_pressure_sensor_tolerance and boost_pressure_sensor_tolerance. The check only runs when "
       "bit 0x20 of algorithm_enable_flags_6_cal is set (off here). 0 in the RAM dump")

keep("0x0040a532", "nitrogen_oxide_target_off_nominal_adjusted",
     "e2m 1711 +1A CBO_bsNOx (G/HP*HR, 0.000244) 'CBR_NOx_Target_Ref adjusted for off-nominal conditions'")

rename("0x0040a404", "boost_pressure_rpm_scale_factor", "engine_volumetric_efficiency",
       "e2m 177D +0 CHP_Volumetric_Efficiency (UNITLESS, 1/8192, 0.5-1.2): cm848_boostBasedFuelModifier writes it "
       "(four stores) as boost_pressure_upper_limit_cal minus a model term of the rpm modifier, the load lookup, the "
       "flow area constant and the pressure ratio, clamped to fuel_demand_rpm_factor_base_cal (6554 = 0.8) .. "
       "fuel_demand_rpm_factor_upper_cal (8192 = 1.0); cm848_throttleBasedFuelCalculation multiplies it by the "
       "engine speed (>> 13, at least 0x640) as the divisor of throttle_conversion; the +2..+A records of block 177D "
       "(intake temperature, Veff Mach / Sqrt, flow area constant, pressure ratio) fit boost_pressure_state_t_0040a406; "
       "lhz 2 / sth 1; dump 7303 = 0.8915",
       "e2m 177D +0 CHP_Volumetric_Efficiency (UNITLESS, 1/8192, 0.5-1.2): 'Volumetric efficiency of engine'. The "
       "engine's volumetric efficiency (8192 = 1.0), computed every pass by cm848_boostBasedFuelModifier from the "
       "boost_pressure_state_t terms (boost_pressure_upper_limit_cal minus a term built from the rpm modifier, the "
       "load lookup, the flow area constant and the pressure ratio) and clamped between "
       "fuel_demand_rpm_factor_base_cal (6554 = 0.8) and fuel_demand_rpm_factor_upper_cal (8192 = 1.0); "
       "cm848_throttleBasedFuelCalculation multiplies it by the engine speed (>> 13, at least 0x640), the speed "
       "density term that divides throttle_conversion_scale_cal into throttle_conversion. 0x0040a426 keeps the name "
       "fuel_demand_rpm_factor: that is a different word (an rpm table value from "
       "cm848_calculateBoostTorqueOffset). 7303 = 0.8915 in the RAM dump")

keep("0x0040ba62", "fuel_pressure_setpoint_not_reached_accumulator",
     "e2m 18F0 +0 HPCR_Cusum_Leak_Pos (MPa, 0.0488) 'Accumulated positive HPCR rail pressure deviation for leak "
     "detection' (a CUSUM of setpoint minus feedback, clamped at 0)")

rename("0x004051e4", "fuel_demand_step_increment_cal", "boost_pressure_in_range_fault_count_increment",
       "e2m 1A2C +4 C_Charge_Press_Fault_Cnt_Incrt (UNITLESS, 0-100): cm848_processBoostControlState adds it to "
       "fuel_demand_step_accumulator (e2m 1A2D +A Charge_Press_IR_Fault_Cnt) on each pass in which the in range "
       "condition is suspect (boost_fuel_below_threshold_flag, enabled by boost_condition_active_flag), capped at the "
       "set threshold; lhz 1; dump 1; the old name (fuel demand step) matches nothing in the function; the word is "
       "outside the EEPROM mirror so no _cal",
       "e2m 1A2C +4 C_Charge_Press_Fault_Cnt_Incrt (UNITLESS, 0-100): 'Charge pressure in range fault count increment "
       "amount'. Calibration of the boost (charge) pressure in range monitor: cm848_processBoostControlState adds it "
       "to boost_pressure_in_range_fault_count on each pass in which the in range condition is suspect "
       "(boost_fuel_below_threshold_flag: abs(boost_pressure_target - boost_pressure_sensor_value - "
       "boost_fuel_threshold_offset) above boost_fuel_threshold_limit, with the monitor enabled by "
       "boost_condition_active_flag), never above boost_pressure_in_range_fault_set_threshold. The count goes down by "
       "the word at 0x4051e2 (e2m C_Charge_Press_Fault_Cnt_Decrt) on a good pass. 1 here")

rename("0x004051e6", "fuel_demand_step_limit_cal", "boost_pressure_in_range_fault_set_threshold",
       "e2m 1A2C +6 C_Charge_Press_Fault_Set (CNTS, 1-65535): cm848_processBoostControlState caps "
       "fuel_demand_step_accumulator (the fault count) here and a count at or above it sets fault 527 (bit 0x8000 of "
       "fault_detected_bits_512_to_527); e2m +0 C_Charge_Press_Fault_Clear (0x4051e0, dump 2) is the clear threshold; "
       "lhz 1; dump 4; the old name (fuel demand step limit) matches nothing in the function; the word is outside the "
       "EEPROM mirror so no _cal",
       "e2m 1A2C +6 C_Charge_Press_Fault_Set (CNTS, 1-65535): 'Calibration for pass to fail threshold'. The count at "
       "which the boost (charge) pressure in range fault is set: cm848_processBoostControlState caps "
       "boost_pressure_in_range_fault_count at it, and a count at or above it sets fault 527 (bit 0x8000 of "
       "fault_detected_bits_512_to_527); the fault clears again when the count is at or below e2m "
       "C_Charge_Press_Fault_Clear (0x4051e0, 2 here). 4 here")

rename("0x0040a438", "fuel_demand_step_accumulator", "boost_pressure_in_range_fault_count",
       "e2m 1A2D +A Charge_Press_IR_Fault_Cnt (CNTS, 0-255): the up / down count of cm848_processBoostControlState "
       "(+ the increment word 0x4051e4 while the condition is suspect, - the decrement word 0x4051e2 while it is "
       "good, 0 while the monitor is bypassed), which sets fault 527 at the set threshold and clears it at the clear "
       "threshold; the same record block's +6 / +8 flags are boost_fuel_below_threshold_flag / "
       "boost_condition_active_flag; the census sees no width (compiled as word compares); dump 0",
       "e2m 1A2D +A Charge_Press_IR_Fault_Cnt (CNTS, 0-255): 'Charge pressure in range fault count'. Up / down "
       "debounce count of the boost (charge) pressure in range monitor, updated each pass by "
       "cm848_processBoostControlState: plus boost_pressure_in_range_fault_count_increment while the in range "
       "condition is suspect (boost_fuel_below_threshold_flag, e2m Charge_Press_IR_Cond) and the monitor is enabled "
       "(boost_condition_active_flag, e2m Charge_Press_IR_Enable), capped at boost_pressure_in_range_fault_set_threshold; "
       "minus the decrement (e2m C_Charge_Press_Fault_Cnt_Decrt, 0x4051e2) while it is good, down to 0; held when the "
       "monitor is not enabled and 0 while it is bypassed (governor_feature_config_flags bit 0x10 clear or "
       "air_handling_compensation_and_diagnostic_bypass_cal non-zero). At the set threshold it sets fault 527 (bit "
       "0x8000 of fault_detected_bits_512_to_527); at or below the clear threshold (e2m C_Charge_Press_Fault_Clear, "
       "0x4051e0) it clears it. 0 in the RAM dump")
