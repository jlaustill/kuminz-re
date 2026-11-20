# Verdict spec for wave 13 bin 4. R = rename, K = keep. Keys are addresses; `old` comes from the bin.
RENAMES = {}
KEEPS = {}


def R(address, new, evidence, comment):
    RENAMES[address] = (new, evidence, comment)


def K(address, note):
    KEEPS[address] = note


# ---------------------------------------------------------------------------------------------- renames

R("0x003fddb8", "data_collector_trigger_active_cal",
  "e2m 0039 +2 Collector_Trigger (UNITLESS 0-1): cm848_phase_groupB_calculation (the data collector pass) sets it when "
  "the trigger input line is active, diag_dm1Buffer_circularFill sets it when the ring fills in stop mode 3 and "
  "hpcr_exception_process clears it, and it picks the post-trigger fill; the diag_dm1_* names are the collector's, not DM1; "
  "EEPROM 0x936 (0x3fddb8 - 0x3fd482) so _cal; type: row is word but e2m is signed and 3 reads are lha (i16 would fit)",
  "e2m 0039 +2 Collector_Trigger 'activates/deactivates collection of data' (address from the ECU's parameter ID table; "
  "EEPROM 0x936) (UNITLESS 0 or 1; 0 here): the data collector's trigger flag, not a DM1 or protection warning. "
  "cm848_phase_groupB_calculation (the collector pass) sets it to 1 when the trigger input line "
  "(data_collector_trigger_input_line_cal) is active, diag_dm1Buffer_circularFill sets it to 1 when the ring buffer fills "
  "in stop mode 3 (diag_dm1_fill_mode_config, e2m Collector_Stop_Mode) and hpcr_exception_process (the collector reset, run "
  "by cm848_applicationMain at start-up and by j1939_dm1_diagnosticMessage_send when its transport session does not end in state 5) clears it. "
  "While it is 0 the collector keeps filling the ring buffer (fill phase 1); once it is 1, diag_dm1_fill_mode_config "
  "(1 / 2 / 3) selects how the fill continues. EEPROM mirror, so _cal.")

R("0x0040a813", "system_switch_status",
  "e2m 1092 +0 System_Switch_Status (HEX): diagnosticMainStateProcessor rebuilds it every pass from switch_input_state_bits "
  "(switches 8 / 7 / 0 / 12 / 11 / 2) and hpcr_setFaultActiveStatus copies it into each fault freeze frame; dump 0x60 = "
  "switch 7 (accelerator at idle) + switch 0 (key on); the old name says fault flags",
  "e2m 1092 +0 System_Switch_Status '[SSSWSS01] bit mapped system switch status' (address from the ECU's parameter ID "
  "table) (HEX; 96 = 0x60 here): a bit-mapped snapshot of the debounced switch states, not a fault flag word. "
  "diagnosticMainStateProcessor rebuilds it every pass from switch_input_state_bits: bit 2 = switch 8 (accelerator off "
  "idle), bit 5 = switch 7 (accelerator at idle), bit 6 = switch 0 (ignition key), bit 10 = switch 12, bit 14 = switch 11 "
  "(brake), bit 15 = switch 2. hpcr_setFaultActiveStatus copies it into every fault freeze frame "
  "(fault_entry_t.diagnostic_fault_flags_a). The dump's 0x60 is key on with the pedal at idle.")

R("0x0040a815", "system_switch_status_2",
  "e2m 1092 +2 System_Switch_Status_2 (HEX): second word of the same rebuild in diagnosticMainStateProcessor, from "
  "logical_output_request_bits (requests 4 / 11 / 43 / 44 / 53) and switch 19; copied into each fault freeze frame by "
  "hpcr_setFaultActiveStatus; the old name says fault flags",
  "e2m 1092 +2 System_Switch_Status_2 '[SSSWSS02] bit mapped system switch status' (address from the ECU's parameter ID "
  "table) (HEX; 0 here): the second bit-mapped status word, not a fault flag word. diagnosticMainStateProcessor rebuilds "
  "it every pass: bit 0 = logical output request 4, bit 1 = request 53, bits 2 / 3 = requests 43 / 44 (byte 5 of "
  "logical_output_request_bits, the row named protection_enable_byte_35), bit 4 = request 11, bit 12 = switch 19 "
  "(switch_input_state_bits[2] bit 3). hpcr_setFaultActiveStatus copies it with system_switch_status into every fault "
  "freeze frame (fault_entry_t.diagnostic_fault_flags_b).")

R("0x0005a470", "j1939_transmission_source_address",
  "e2m 10E3 +4 Jcomm_Trans_Source_Address (UNITLESS): sender filter of the ETC1 / ETC2 handlers "
  "(cm848_j1939ProcessPgn61442Etc1, cm848_j1939ProcessPgn61445Etc2; any when 0xff), index 1 of "
  "cm848_lookupJ1939SourceAddressIndex = TRANS per e2m 117D +14 Engine_Brake_Jcomm_Device_Indicator (1 TRANS / 2 ABS / "
  "3 ASR / 4 UNKNOWN, a block that does not drift), dump 3 (transmission #1); the drifting 10E3 tail starts at +20 (= block 1228 +0 at 0x5a48c), "
  "after this record; the old name's 'sa' is an abbreviation and 'tsc1 auth primary' misses the ETC1 / ETC2 role",
  "e2m 10E3 +4 Jcomm_Trans_Source_Address '[JCTRSA] Jcomm Transmission Source Address 1939 source address for "
  "transmission ECM' (address from the ECU's parameter ID table) (UNITLESS; 3 here): the J1939 source address of the "
  "transmission controller (0xff = accept any); flash constant, no _cal. It is the sender filter of the ETC1 "
  "(cm848_j1939ProcessPgn61442Etc1) and ETC2 (cm848_j1939ProcessPgn61445Etc2) receive handlers; index 1 of "
  "cm848_lookupJ1939SourceAddressIndex (e2m 117D +14 Engine_Brake_Jcomm_Device_Indicator: 1 = TRANS, 2 = ABS, 3 = ASR, "
  "4 = UNKNOWN); the transmission whose retarder TSC1 requests cm848_processEngineRetarderTsc1Request ignores while "
  "governor_feature_config_word bit 0x1000 is clear (it also tests it in its shift-assist branch); and the first source "
  "cm848_updateParkNeutralFlagAndTsc1Activity adds to / removes from the TSC1 ignored-request lists "
  "(cm848_processTsc1IgnoredRequestTimeouts ages them).")

R("0x0005a472", "j1939_anti_lock_brake_source_address",
  "e2m 10E3 +6 Jcomm_ABS_Source_Address (UNITLESS): index 2 of cm848_lookupJ1939SourceAddressIndex = ABS per e2m 117D +14 "
  "(1 TRANS / 2 ABS / 3 ASR / 4 UNKNOWN), added to / removed from the TSC1 ignored-request lists by "
  "cm848_updateParkNeutralFlagAndTsc1Activity; dump 11; the old name's 'sa' is an abbreviation",
  "e2m 10E3 +6 Jcomm_ABS_Source_Address '[JCABSA] Jcomm ABS Source Address source address for anti-lock brake device' "
  "(address from the ECU's parameter ID table) (UNITLESS; 11 here): the J1939 source address of the anti-lock brake "
  "controller; flash constant, no _cal. Index 2 of cm848_lookupJ1939SourceAddressIndex (e2m 117D +14 "
  "Engine_Brake_Jcomm_Device_Indicator: 1 = TRANS, 2 = ABS, 3 = ASR, 4 = UNKNOWN). "
  "cm848_updateParkNeutralFlagAndTsc1Activity adds it to / removes it from the TSC1 ignored-request lists "
  "(cm848_addEngineTsc1IgnoredRequestEntry / cm848_removeEngineTsc1IgnoredRequestEntry) with the other two source "
  "addresses.")

R("0x0005a474", "j1939_anti_slip_regulation_source_address",
  "e2m 10E3 +8 Jcomm_ASR_Source_Address (UNITLESS): index 3 of cm848_lookupJ1939SourceAddressIndex = ASR per e2m 117D +14 "
  "(1 TRANS / 2 ABS / 3 ASR / 4 UNKNOWN), added to / removed from the TSC1 ignored-request lists by "
  "cm848_updateParkNeutralFlagAndTsc1Activity; dump 33; the old name's 'sa' is an abbreviation",
  "e2m 10E3 +8 Jcomm_ASR_Source_Address '[JCARSA] Jcomm ASR Source Address source address for anti-slip regulation "
  "device' (address from the ECU's parameter ID table) (UNITLESS; 33 here): the J1939 source address of the anti-slip "
  "regulation device; flash constant, no _cal. Index 3 of cm848_lookupJ1939SourceAddressIndex (e2m 117D +14 "
  "Engine_Brake_Jcomm_Device_Indicator: 1 = TRANS, 2 = ABS, 3 = ASR, 4 = UNKNOWN). "
  "cm848_updateParkNeutralFlagAndTsc1Activity adds it to / removes it from the TSC1 ignored-request lists "
  "(cm848_addEngineTsc1IgnoredRequestEntry / cm848_removeEngineTsc1IgnoredRequestEntry) with the other two source "
  "addresses.")

R("0x0005a494", "supported_non_continuous_monitors_bits",
  "DRIFT of the labelled record (10E3 +28 DDT_TSC_ASG_Filter_Slew_Rate is the 11.45 e2m's shifted tail; wave 12: the 10E3 "
  "tail is block 1228) but the record that resolves here too, e2m 1228 +8 Supported_Non_Continuous_Monitors, matches the "
  "code: cm848_j1939HandlePgn65230Dm5Readiness sends this word byte-reversed as DM5 bytes 5-6 after OBD compliance "
  "(0x5a490, 1228 +4) and the continuous monitors byte (0x5a492, 1228 +6), cm848_j1939HandlePgn65234Dm10 returns it and "
  "cm848_j1939HandlePgn58112Dm7 tests its bits 0x100 / 0x200; dump 0",
  "e2m 1228 +8 Supported_Non_Continuous_Monitors '[JCNTCTMR] Indicator of software's support of non-continuously run "
  "monitors' (address from the ECU's parameter ID table; the 10E3 +28 DDT_TSC_ASG_Filter_Slew_Rate record that also "
  "resolves here is the 11.45 e2m's shifted 10E3 tail) (UNITLESS bits; 0 here = no non-continuous monitor supported): "
  "flash constant, no _cal. cm848_j1939HandlePgn65230Dm5Readiness sends it byte-reversed (j1939_feature_config_tx_word) "
  "as bytes 5-6 of the J1939 DM5 readiness message (non-continuously monitored systems support), after "
  "obd_compliance_code (byte 3) and supported_continuous_monitors_bits (byte 4); cm848_j1939HandlePgn65234Dm10 (DM10) "
  "returns the same word and cm848_j1939HandlePgn58112Dm7 (DM7) answers a test mode 0 / 1 command only when its bit "
  "0x100 / 0x200 is set.")

R("0x0040a64b", "duty_cycle_monitor_map_reset_pending_flag",
  "e2m 111F +3 DC_Mon_Map_Reset (UNITLESS 0-1): SCI command 35 sub-command 0x14 (20) sets it in cm848_sciCommand35Callback "
  "(engine stopped) and cm848_outputs2_periodic (the duty cycle monitor / load histogram pass, e2m DC_Mon_*) clears the "
  "histogram and the flag; block 111F +0 is duty_cycle_monitor_load_factor; the old name says fuel demand",
  "e2m 111F +3 DC_Mon_Map_Reset 'Set to TRUE to reset the duty cycle monitor map' (address from the ECU's parameter ID "
  "table) (UNITLESS 0 or 1; 0 here): byte, a reset request. SCI command 35 sub-command 0x14 (20) sets it "
  "(cm848_sciCommand35Callback, engine stopped only; sub-command 0x15 sets trip_counters_reset_pending_flag). "
  "cm848_outputs2_periodic (the duty cycle monitor, whose load factor is duty_cycle_monitor_load_factor) acts on it when "
  "the monitor is off (algorithm_enable_flags_18_cal bit 3 clear) or the engine is stopped: it zeroes "
  "fuel_demand_histogram_sample_count, the load map at 0x3fde4e and percent_time_at_load_cal, then clears the flag.")

R("0x0040a298", "rear_axle_ratio",
  "e2m 117D +30 Rear_Axle_Ratio (UNITLESS 1/128): the axle ratio in use, loaded by cm848_setProtectionControlValue / "
  "cm848_applyProtectionControlLimit from the two EEPROM words that are e2m 1180 +C Rear_Axle_Ratio_High (0x3fd534) and "
  "+6 Rear_Axle_Ratio_Low (0x3fd52e); dump 453 = 3.54 in all three; read as drivetrain_ratio x this >> 11 and as "
  "protection_timing_period_cal x this / 60; the old name says protection temperature scale",
  "e2m 117D +30 Rear_Axle_Ratio '[VSRRAXRA] RATIO OF TRANS TO AXLE REVS - (can vary for 2 spd apps)' (address from the "
  "ECU's parameter ID table) (UNITLESS, 1/128 per count; 453 = 3.54 here): the rear axle ratio in use, working RAM, no "
  "_cal. cm848_setProtectionControlValue loads it from protection_temp_scale_cal (EEPROM, e2m 1180 +C "
  "Rear_Axle_Ratio_High); with two_speed_axle_enable_cal set, cm848_applyProtectionControlLimit takes that word while "
  "switch 31 is set (switch_input_state_bits[3] bit 0x80) and protection_temp_scale_factor_working (EEPROM, e2m 1180 +6 "
  "Rear_Axle_Ratio_Low) otherwise. Read as drivetrain_ratio x this >> 11 (cm848_processGovernorSpeedSetpoint, against "
  "the governor speed mode rpm limits) and as protection_timing_period_cal x this / 60 (cm848_calculateRiseLimitedVehicleSpeed, "
  "cm848_calculateCruisePidRateGainScale).")

R("0x0040a2b4", "ecm_power_down_delay_request_flag",
  "e2m 117D +4C Powerdown_Delay_Request (HEX): the delayed power-down branch of cm848_updateEngineState (SHUTDOWN) needs it "
  "0 and the state clears it each pass; cm848_setFuelDemandActiveFlag (every pass of cm848_periodicTaskSet_sensorProcessing) "
  "sets it while vehicle_speed_unfiltered is nonzero; type: row is dword but every access is a halfword "
  "(lhz / sth, the decompiler prints _0_2_) and the e2m record is 2 bytes - should be word",
  "e2m 117D +4C Powerdown_Delay_Request '[SDDYFG] The ECM will not powerdown until this is inactive' (address from the "
  "ECU's parameter ID table) (HEX; 0 here): a power-down hold request. In the SHUTDOWN state cm848_updateEngineState "
  "starts the delayed power-down (power_down_start_flag once ecm_power_down_timer reaches ecm_power_down_delay and "
  "egr_delta_pressure_autozero_complete_flag is set) only while this is 0, and clears it at the end of every SHUTDOWN "
  "pass (the immediate path at ecm_power_down_timer_threshold ignores it). cm848_setFuelDemandActiveFlag, run every pass of "
  "cm848_periodicTaskSet_sensorProcessing, sets it to 1 while vehicle_speed_unfiltered is nonzero. Accessed as a halfword.")

R("0x0040a2c8", "cruise_resume_active_flag",
  "e2m 117D +60 Cruise_Resume_Status (UNITLESS 0-1): cm848_cruiseSpeedCommandStateMachine sets it in CRUISE_RESUME and "
  "clears it in CRUISE_OFF / STANDBY and at the end of a pass unless cruise is engaged in RESUME / ACTIVE_HOLD with "
  "cruise_speed_command above vehicle_speed_rise_limited; cm848_cruiseControlPeriodicUpdate sends ACTIVE_HOLD with the flag "
  "set as CCVS1 state 4 (resume); the old name says fuel demand",
  "e2m 117D +60 Cruise_Resume_Status 'Status of the Cruise Control Resume' (address from the ECU's parameter ID table) "
  "(UNITLESS 0 or 1; 0 here): set while a cruise resume is under way. cm848_cruiseSpeedCommandStateMachine sets it to 1 in "
  "CRUISE_RESUME (2) and to 0 in CRUISE_OFF (0) and CRUISE_STANDBY (8); at the end of every pass it is cleared again "
  "unless cruise is engaged in RESUME or ACTIVE_HOLD with cruise_speed_command above vehicle_speed_rise_limited (still "
  "accelerating to the target). Readers: cm848_cruiseControlPeriodicUpdate (the CCVS1 state: ACTIVE_HOLD with the flag set "
  "is sent as 4 = resume, else 1 = hold), cm848_processOverdriveSwitchAndShift (the 4th gear downshift check against "
  "cruise_speed_command) and cm848_arbitrateGovernedFueling, which copies it to fuel_demand_enable_sync_flag_shadow (0 on "
  "the first pass of a cruise / vehicle speed limit state runs protectionRampRateControl).")

R("0x0040093a", "engine_displacement_cubic_inches",
  "e2m 177C +8 C_CHP_Engine_Displacement (IN3, 1/32): dump 11493 = 359.2 cu in = 5.89 L; the multiplier of the speed-density "
  "charge flow in cm848_loadBasedFuelAdjustment (engine speed x boost_pressure_rpm_scale_factor x "
  "map_fuel_correction_factor x this / (boost_pressure_state_t.load_input x 0xa200)) and the pressure-difference scale of "
  "cm848_calculateBoostPressureOffset; 0x40093a is outside the EEPROM mirror so the _cal was wrong",
  "e2m 177C +8 C_CHP_Engine_Displacement 'Engine displacement in cu. in. (61.02 times displacement in liters)' (address "
  "from the ECU's parameter ID table) (IN3, 1/32 per count; 11493 = 359.2 cu in = 5.89 L here): the engine displacement in "
  "the charge flow estimate. cm848_loadBasedFuelAdjustment (the speed-density flow into charge_mass_flow_filtered) "
  "multiplies engine speed x boost_pressure_rpm_scale_factor x map_fuel_correction_factor by it and divides by "
  "boost_pressure_state_t.load_input x 0xa200 (the intake temperature term, per charge_mass_flow_filtered); "
  "cm848_calculateBoostPressureOffset scales its pressure-difference term by it x 1326 / 100000. ROM constant copied to RAM (0x40093a, outside the EEPROM mirror), so no _cal.")

R("0x0040a692", "egr_orifice_temperature_after_lead",
  "e2m 19CA +6 INM_EGRT_After_Lead (DEG_F 1/64): sensor_channel108_filter writes sensor channel 108 (the EGR orifice "
  "temperature sensor) + egr_orifice_temperature_lead_term clamped to the min / egr_orifice_temperature_estimate_maximum_limit "
  "limits, sensor_throttleTrim_ema_faultProcess filters it into egr_orifice_temperature; dump 4608 = 72 degF = the sensor "
  "value; the sibling 19CA rows already say egr_orifice_temperature_*, the old name says throttle trim",
  "e2m 19CA +6 INM_EGRT_After_Lead 'Estimated EGR orifice temp after sensor compensation but' (address from the ECU's "
  "parameter ID table) (DEG_F, 1/64 per count; 4608 = 72 degF here): the lead-compensated EGR orifice temperature. "
  "sensor_channel108_filter (sensor channel 108 = the EGR orifice temperature sensor) writes sensor_channel108_value + "
  "egr_orifice_temperature_lead_term, limited between throttle_trim_predictor_output_min and "
  "egr_orifice_temperature_estimate_maximum_limit; sensor_throttleTrim_ema_faultProcess then filters it twice "
  "(ema_filter_state_t at 0x3fbd00 / 0x3fbd08) and sensor_throttleTrim_inputSelect selects the result as "
  "egr_orifice_temperature. Not a throttle trim.")

R("0x0040a696", "egr_orifice_temperature_lead_time_constant",
  "e2m 19CA +A INM_EGRT_Lead_Time_Constant (SEC 0.01): sensor_channel108_filter multiplies the channel 108 change since the "
  "last pass by it into egr_orifice_temperature_lead_term (clamped +-32000); sensor_throttleTrim_ema_faultProcess loads it "
  "from a table over egr_mass_flow_delayed_filtered (throttle_trim_predictor_gain_lookup) and forces 0 on a sensor fault; "
  "dump 0; the old name says throttle trim",
  "e2m 19CA +A INM_EGRT_Lead_Time_Constant 'Current active EGR orifice temperature lead time constant' (address from the "
  "ECU's parameter ID table) (SEC, 0.01 per count; 0 here): the gain of the EGR orifice temperature lead compensation. "
  "sensor_channel108_filter computes egr_orifice_temperature_lead_term = (sensor_channel108_value - its previous value) x "
  "this, clamped to +-32000. sensor_throttleTrim_ema_faultProcess loads it from throttle_trim_predictor_gain_lookup (a "
  "table over egr_mass_flow_delayed_filtered) and forces 0 while sensor channel 108 has a fault, "
  "air_handling_compensation_and_diagnostic_bypass_cal is nonzero or bit 0x8000 of algorithm_enable_flags_20_cal is clear. "
  "Not a throttle trim gain.")

R("0x0040a624", "egr_orifice_delta_pressure",
  "e2m 1A19 +0 EGR_Orifice_Delta_Press (IN_HG signed): cm848_calculateFuelFlowWithMode writes 0 while "
  "egr_flow_cold_side_algorithm_select is 0 and egr_delta_pressure_sensor_output otherwise; cm848_calculateLoadBasedFuelTrim "
  "divides it by map_fuel_correction_factor as the orifice pressure ratio of an EGR flow lookup with egr_valve_position and "
  "egr_orifice_temperature; sibling rows +4 / +8 are already egr_delta_pressure*; type: word read with lha (signed) - i16 "
  "would match the e2m; the old name says boost fuel correction",
  "e2m 1A19 +0 EGR_Orifice_Delta_Press 'Pressure drop across EGR Delta Press Disturbance' (address from the ECU's "
  "parameter ID table) (IN_HG signed, 0.0159 inHg per count; 0 here): the pressure drop across the EGR orifice. "
  "cm848_calculateFuelFlowWithMode writes it: 0 while egr_flow_cold_side_algorithm_select is 0, else the EGR delta "
  "pressure sensor output (egr_delta_pressure_sensor_output); the next word (e2m EGR_Orifice_Delta_Press_Source) holds the "
  "source. cm848_calculateLoadBasedFuelTrim divides it by map_fuel_correction_factor (x 0x7fff, saturated) as the "
  "pressure ratio input of a lookup against egr_valve_position, next to the egr_orifice_temperature lookup: an EGR flow "
  "calculation, not a boost fuel correction.")

R("0x004094a2", "fuel_pressure_governor_proportional_gain_small_signal",
  "e2m 8014 +0 HPCR_Propgain_Small_Signal (%/MPa): first dword of the gain block cm848_calculateFuelMeteringCommand hands to "
  "cm848_applyPiecewiseLinearGain(setpoint - feedback) = fuel_pressure_governor_proportional_term; gain 0 between the window "
  "breakpoints (e2m 8014 +C / +E windows read +205 / -204 = +-10 MPa at 0.0488), scaled by the e2m 8005 / 8008 "
  "HPCR_SF_Propcomp_Small_Signal rpm curve (cam_sync_cyl1_timing_*_a_cal) while cam_timing_alt_mode_enable_cal is 0; dump "
  "65537 = 0.5 %/MPa; 0x4094a2 is outside the EEPROM mirror so the _cal was wrong; the old name says injection timing",
  "e2m 8014 +0 HPCR_Propgain_Small_Signal 'Fuel pressure governor P-Component small signal gain' (address from the ECU's "
  "parameter ID table) (%/MPa, 1/131072 per count; 65537 = 0.5 here): dword, gain 0 of the fuel pressure governor's "
  "proportional term. cm848_calculateFuelMeteringCommand builds the gain block of cm848_applyPiecewiseLinearGain from it "
  "(multiplied by the engine speed curve cam_sync_cyl1_timing_axis_a_cal / _values_a_cal, e2m 8005 / 8008 "
  "HPCR_SF_Propcomp_Small_Signal_*, >> 12 while cam_timing_alt_mode_enable_cal, e2m HPCR_Governor_Mode, is 0 as in the "
  "dump; used directly otherwise); the helper applies it to fuel_pressure_setpoint - fuel_pressure_feedback_filtered "
  "between the window breakpoints (+-10 MPa here, e2m 8014 +C / +E at 0x4094ae). ROM constant copied to RAM, no _cal.")

R("0x004094a6", "fuel_pressure_governor_proportional_gain_positive_large_signal",
  "e2m 8014 +4 HPCR_Propgain_Positive_Large_Signal (%/MPa): second dword of the gain block of "
  "cm848_calculateFuelMeteringCommand, gain 1 of cm848_applyPiecewiseLinearGain = applied above the upper window breakpoint, "
  "scaled by the e2m 8006 / 8009 HPCR_SF_Propcomp_Positive_Large_Signal curve (cam_sync_cyl2_timing_*_a_cal); dump 13107 = "
  "0.1 %/MPa; outside the EEPROM mirror so the _cal was wrong; the old name says injection timing",
  "e2m 8014 +4 HPCR_Propgain_Positive_Large_Signal 'Fuel pressure governor P-Component positive large signal gain' (address "
  "from the ECU's parameter ID table) (%/MPa, 1/131072 per count; 13107 = 0.1 here): dword, gain 1 of the fuel pressure "
  "governor's proportional term. cm848_calculateFuelMeteringCommand builds it into the gain block of "
  "cm848_applyPiecewiseLinearGain (multiplied by the engine speed curve cam_sync_cyl2_timing_axis_a_cal / _values_a_cal, "
  "e2m 8006 / 8009 HPCR_SF_Propcomp_Positive_Large_Signal_*, >> 12 while cam_timing_alt_mode_enable_cal is 0); the helper "
  "applies it to the part of fuel_pressure_setpoint - fuel_pressure_feedback_filtered above the positive window width. "
  "ROM constant copied to RAM, no _cal.")

R("0x004094aa", "fuel_pressure_governor_proportional_gain_negative_large_signal",
  "e2m 8014 +8 HPCR_Propgain_Negative_Large_Signal (%/MPa): third dword of the gain block of "
  "cm848_calculateFuelMeteringCommand, gain 2 of cm848_applyPiecewiseLinearGain = applied below the lower window breakpoint, "
  "scaled by the e2m 8007 / 800A HPCR_SF_Propcomp_Negative_Large_Signal curve (cam_sync_cyl3_timing_*_a_cal); dump 78644 = "
  "0.6 %/MPa; outside the EEPROM mirror so the _cal was wrong; the old name says injection timing",
  "e2m 8014 +8 HPCR_Propgain_Negative_Large_Signal 'Fuel pressure governor P-Component negative large signal gain' (address "
  "from the ECU's parameter ID table) (%/MPa, 1/131072 per count; 78644 = 0.6 here): dword, gain 2 of the fuel pressure "
  "governor's proportional term. cm848_calculateFuelMeteringCommand builds it into the gain block of "
  "cm848_applyPiecewiseLinearGain (multiplied by the engine speed curve cam_sync_cyl3_timing_axis_a_cal / _values_a_cal, "
  "e2m 8007 / 800A HPCR_SF_Propcomp_Negative_Large_Signal_*, >> 12 while cam_timing_alt_mode_enable_cal is 0); the helper "
  "applies it to the part of fuel_pressure_setpoint - fuel_pressure_feedback_filtered below the negative window width. "
  "ROM constant copied to RAM, no _cal.")

R("0x004090f0", "injection_timing_tooth_base_offset_cylinder_0",
  "e2m 805C +8 HPCR_1st_Wakeup_Increment_Cyl0 (UNITLESS, dump 35 of 120): cm848_scheduleInjectionAnglesOnPrimarySpeedInput "
  "(period address 2) and cm848_scheduleInjectionAnglesInSpeedLimpHome (period address 0x12) both start the tooth of "
  "cylinder event N from it + injection_timing_tooth_separation_per_cylinder x N, so 'mode2' in the old name is wrong",
  "e2m 805C +8 HPCR_1st_Wakeup_Increment_Cyl0 'Increment number for wakeup on Cyl0' (address from the ECU's parameter ID "
  "table) (UNITLESS; 35 of 120 increments here): byte, the tooth (increment) of the first static wakeup of cylinder event "
  "0. The scheduler places the wakeup of cylinder event N at this + injection_timing_tooth_separation_per_cylinder x N, "
  "wrapping at injection_timing_tooth_count, in both cm848_scheduleInjectionAnglesOnPrimarySpeedInput (TPU period address 2) "
  "and cm848_scheduleInjectionAnglesInSpeedLimpHome (0x12), so it is not specific to one timing mode; "
  "cm848_calculatePilotInjectionTiming also converts it to an angle (x 1536 / 30) for injection_timing_static_wakeup_location. "
  "ROM constant copied to RAM, no _cal.")

R("0x0040b877", "injection_tpu_period_parameter_address",
  "e2m 805E +B HPCR_Period_Address (UNITLESS): 2 and 0x12 are the low bytes of TPU-A parameter RAM addresses 0x304102 / "
  "0x304112 = parameter 1 of channel 0 / channel 1 (channel n starts at 0x304100 + 0x10 x n), the two engine position "
  "inputs: set to 2 by cm848_scheduleInjectionAnglesOnPrimarySpeedInput (channel 0) and 0x12 by "
  "cm848_scheduleInjectionAnglesInSpeedLimpHome (channel 1); ORed into TPUA_CH6 / CH10 PARAM0 and CH2 / CH7 PARAM4; dump 2",
  "e2m 805E +B HPCR_Period_Address 'Address of the period parameter in TPU' (address from the ECU's parameter ID table) "
  "(UNITLESS; 2 here): byte, the low byte of the TPU-A parameter RAM address of the engine position period: 0x02 = "
  "channel 0 parameter 1 (0x304102, the primary speed input; set by cm848_scheduleInjectionAnglesOnPrimarySpeedInput and "
  "the scheduler initializer cm848_sensor_diagnostic_flag_update) or 0x12 = channel 1 parameter 1 (0x304112, the speed "
  "limp home input; set by cm848_scheduleInjectionAnglesInSpeedLimpHome). ORed into the low byte of TPUA_CH6 / CH10 PARAM0 "
  "(with 0x6000 / 0xa000 in the high nibble) and of TPUA_CH2 / CH7 PARAM4; the tooth conversions take their != 2 branch "
  "(injection_timing_angle_threshold / injection_timing_tooth_base_index, the first cam pulse after the crank gap) when it "
  "is 0x12.")

R("0x0040b878", "injection_timing_tooth_separation_per_cylinder",
  "e2m 805E +C HPCR_Wakeup_Seperation_In_Increments (UNITLESS, dump 20): cm848_sensor_diagnostic_flag_update (the TPU injection "
  "angle scheduler initializer) stores injection_timing_tooth_count / cylinder_event_count_max (120 / 6) in it and both "
  "scheduling paths add it x the cylinder event index to the cylinder 0 tooth; the old name says cam sync position",
  "e2m 805E +C HPCR_Wakeup_Seperation_In_Increments 'Seperation in increments between static wakeups' (address from the "
  "ECU's parameter ID table) (UNITLESS; 20 here): byte, the tooth (increment) spacing between the static wakeups of "
  "consecutive cylinder events = injection_timing_tooth_count / cylinder_event_count_max (120 / 6), stored once by the "
  "scheduler initializer cm848_sensor_diagnostic_flag_update. Both scheduling paths use "
  "injection_timing_tooth_base_offset_cylinder_0 + this x cylinder event index as the tooth. It is also the span of the "
  "angle / time conversions against crank_period_accumulator: angle x period / (this x 256) in "
  "cm848_calculate{Pilot,Auxiliary}InjectionPulseWidth, duration x this x 256 / period in "
  "engine_injectionAngle_computeLoadCh6 and engine_injectionAngle_tpuChannel6EventHandler. Not a cam sync position.")

# ---------------------------------------------------------------------------------------------- keeps

K("0x0040bb0a", "e2m 001B +0 Percent_Throttle 'VALIDATED PERCENT THROTTLE COMMANDED BY DRIVER' (0.25 percent per count, "
                "the scale of this pedal channel's output)")
K("0x0040afb2", "e2m 105D +6 Torque_Derate_Fueling_2 '[FLLMAHFL] Smallest derate fueling value among group 2 (AH) derate "
                "algorithms' (the running minimum of the air handling limiters: air fuel control derate 16, net torque limit 59)")
K("0x0040a26c", "e2m 117D +4 E_Brake_Status '[EBSS] Status of whether operating conditions indicate desire for brake "
                "activation'")
K("0x0040a276", "e2m 117D +E Out_Of_Gear '[GROGSS] Indicator set when an out of gear condition is detected'")
K("0x0040a2c6", "e2m 117D +5E ESP_Tau_State '[SPTUST] Indicates the source of the current ESP_Tau value' (one reader: "
                "governor_cruise_speedReference_update picks the cruise top droop offset of Tau 0 / another Tau / Tau 1 by it; "
                "no writer found in the .cpp)")
K("0x003fd930", "e2m 1195 +2 GR_Constant 'GEAR RATIO CONSTANT'")
K("0x0040b99c", "e2m 13F7 +0 Hybrid_Governor_Fueling 'Partial Throttle ASG Fueling Limit'")
K("0x0040b9d8", "e2m 1627 +0 HPCR_Cusum_Pos 'accumulated positive HPCR rail pressure deviation' (positive = setpoint above "
                "feedback)")
K("0x0040b9dc", "e2m 1627 +4 HPCR_Cusum_Neg 'accumulated negative HPCR rail pressure deviation'")
K("0x0040b9e0", "e2m 1627 +8 HPCR_Cusum_Delta 'HPCR rail pressure deviation from setpoint'")
K("0x0040ba6a", "e2m 162F +0 Turbo_Pass_Counter 'Gives how many times the wastegate monitor passes during the monitoring "
                "trip.'")
K("0x0040ba6c", "e2m 162F +2 Turbo_Total_Pass_Time 'Total time when the wastegate monitor passes during the monitoring "
                "trip.' (0.1 s per count)")
K("0x0040a482", "e2m 16A5 +2 CBR_FCLR_Ref 'CBR_Gross_Torque_Fuel divided by OFC_Fuel_Limit'")
K("0x0040b05c", "e2m 1839 +C VGA_Electrical_Error 'Any of a combination of ASIC detected Hw faults without persistance'")
K("0x004090e8", "e2m 805C +0 HPCR_Total_Increments 'Total number of increments'")
K("0x004090ef", "e2m 805C +7 HPCR_TPU_Minimum_Ratio 'Minimum value of ratio for TPU'")
K("0x004090f3", "e2m 805C +B HPCR_Location_Of_1st_Cam_Pulse_After_Gap 'Location of 1st cam pulse after crank gap in crank "
                "degrees'")
K("0x004090f5", "e2m 805C +D HPCR_Count_Of_1st_Cam_Pulse_After_Gap 'Count of 1st cam pulse after crank gap'")
K("0x0040b86c", "e2m 805E +0 HPCR_Wakeup_Processing_Status_N 'Status of wakeup processing'")
K("0x0040b86d", "e2m 805E +1 HPCR_Previous_Wakeup_N 'Status of previous wakeup'")
K("0x0040b86e", "e2m 805E +2 HPCR_1st_Wakeup_Increment 'Wakeup increment number for 1st static wakeup'")
K("0x0040b86f", "e2m 805E +3 HPCR_1st_Wakeup_Ratio 'Ratio value for 1st static wakeup'")
K("0x0040b875", "e2m 805E +9 HPCR_Dynamic_Wakeup_Angle 'Wakeup increment number for dynamic wakeup' (engine_injectionAngle_"
                "computeLoadCh6 places it one wakeup duration before the injection start)")
K("0x0040b876", "e2m 805E +A HPCR_Dynamic_Wakeup_Ratio 'Wakeup ratio for dynamic wakeup'")
K("0x0040b8aa", "e2m 812F +0 CP3_Driver_Inhibit_Timer 'Timer value of CP3 Off cycle time when short or open circuit' (0.01 s "
                "per count)")
K("0x00408f46", "e2m 81C9 +0 HPCR_Bank_Retest_Count 'Number of cam revs injector bank is disabled after fault' (the cutout "
                "takes one injector bank: mask 0x55 or 0xaa of the cylinder events)")
K("0x00408f48", "e2m 81C9 +2 HPCR_Bank_Shutdown_Threshold 'Number of bank shutdowns before permanent disable'")
K("0x00408f49", "e2m 81C9 +3 HPCR_Bank_Diagnostic_Count 'Number of cam rev. counts for delay of bank shutdown so faults can "
                "be detected.'")
K("0x00408f4c", "e2m 81C9 +6 HPCR_Bank_Shutdown_Enables 'Bank shutdown enable (1=shutdown);bit0=STG,1=STB,2=fast dec,3=low "
                "boost'")
K("0x0040b3de", "e2m 8A12 +9 J50_Act68 'J1850 Message $68 ECM Rx activity for J1979 OBD support of tool request' (PCI RX[0], "
                "header 68 6A)")
K("0x0040b3e7", "e2m 8A12 +12 Chry_Err24 'Chrysler Specific ECM Rx error for J2190 diagnosic support of tool request' (PCI "
                "RX[1], header 24)")
K("0x0040b3e8", "e2m 8A12 +13 Chry_Act24 'Chrysler Specific ECM Rx activity for J2190 diagnosic support of tool request' "
                "(PCI RX[1], header 24)")
K("0x0040b402", "e2m 8A12 +2D Chry_Act4FC0 'Chrysler DR Message $4FC0 activity for VTA SKIM request seed/key, ECM Rx mess' "
                "(PCI RX[6], header 4F C0)")
K("0x0040b40d", "e2m 8A12 +38 Chry_Act98 'Chrysler DR Message $98 activity for General Trans. Status, ECM Rx' (the e2m says "
                "Rx; the PCI tables list header 98 as TX[12])")
K("0x0040b436", "e2m 8A12 +61 Chry_ActB1 'Chrysler DR Message $B1 activity for SKIM Status, ECM Rx message' (PCI RX[12], "
                "header B1)")
K("0x0040b43a", "e2m 8A12 +65 Chry_Err42 'Chrysler DR Message $42 error for Last Ign Off Duration, ECM Rx message' (PCI "
                "RX[14], header 42)")
K("0x0040b43e", "e2m 8A12 +69 Chry_Dat42_Acknowledge 'Chrysler DR Message $42 data for Last Ign Off Duration, ECM Rx "
                "message' (the value latched from the first valid frame; the raw payload is pci_receive_message_14_engine_off_"
                "time)")
K("0x0040b33c", "e2m 8A35 +2 IAH_Phase 'IAH Control Phase (0=key_on/1=setup/2=preheat/3=crank/4=postheat/5=off)'")
K("0x0040b342", "e2m 8A35 +8 IAH_Override 'Value:IAH Relay1/ Relay2(0:ignore override,1:ON/OFF,2:OFF/ON,3:ON/ON,4:OFF/OFF)' "
                "(an override input, 0 = ignore it - which fits no writer in the binary)")
K("0x0040b344", "e2m 8A35 +A IAH_Error_Status '0=Inprocess/1=complete/2=VS/3=BT/4=longcrank/5=2hot/6=posthigh/7=Inhbit/"
                "8=Fuel'")
K("0x0040b542", "e2m 8C60 +2 Tcase_NV_Instantaneous 'Instantaneous value (ENGRPM/Vehicle_Speed), N/V Low Range Indication' "
                "(1/8 rpm per mph per count)")
K("0x0040b544", "e2m 8C60 +4 Tcase_NV_Average 'Filtered Instantaneous value (ENGRPM/Vehicle_Speed), N/V Low Range "
                "Indication'")
