COMMENTS = {
    0: "e2m 0033 +8 Collector_Start_Address 'Logical beginning address of the data collector buffer' (HEX): read / tail "
       "pointer of the data collector ring buffer (storage &DAT_0040c28a, start 0x40c270, end 0x40c274, write pointer "
       "0x40c280): diag_dm1Buffer_circularFill advances / wraps it when the write pointer catches it, "
       "j1939_dm1_diagnosticMessage_send moves it past the bytes it sends. The diag_dm1_buffer_* words are the data "
       "collector (data_collector_*_cal), not DM1.",
    2: "e2m 104A +2 Alpha_Base '[APAPBA] Result of AFC, LSG, On Governor, and Fuel Rate alpha comparison' (UNITLESS, "
       "1/16384 per count): the base alpha ramp: timingProtectionFlagsOrchestrator zeroes it while no alpha condition is "
       "set, else adds alpha_ramp_rate_below_threshold / _at_or_above_threshold per pass up to 0x4000 (1.0); "
       "hpcr_calculateFuelTrimOutput outputs it as combustion_alpha_input in governor_startup_state 0. Not a fuel demand.",
    3: "e2m 104A +8 Alpha_Fuel_Rate '[APFLRTAP] result of Fuel Rate algorithm' (UNITLESS): the fuel rate alpha condition: "
       "cm848_calculateSensorEma returns 1 while alpha_filtered_fuel_delivery_rate is above alpha_threshold_fuel_rate, 0 at "
       "or below alpha_reset_fuel_rate, else the old value (hysteresis); timingProtectionFlagsOrchestrator stores it (enable "
       "bit 0x1000 of governor_fault_status_flags) and ORs it into the alpha ramp condition. Not a cold start value.",
    4: "e2m 104A +E Fueling_AFC_State_Detected '[FLAFSTFG] semaphore used to latch AFC events that occur between alpha "
       "executions' (UNITLESS): set to 1 by cm848_selectFinalFueling when final_fueling_state is AIR_FUEL_CONTROL_DERATE or "
       "COMBUSTION_OXYGEN_LIMIT; read by the air fuel control alpha check cm848_checkPressureFuelDelayB and cleared each "
       "alpha execution at the end of timingProtectionFlagsOrchestrator. Not a cold start flag.",
    5: "e2m 104A +10 Fueling_LSG_State_Detected '[FSLSSTFG] semaphore used to latch LSG events that occur between alpha "
       "executions' (UNITLESS): set to 1 by cm848_selectFinalFueling on the pass final_fueling_state enters "
       "LOW_SPEED_GOVERNOR; read by cm848_checkPressureFuelDelayA / B and the fuel rate filter restart in "
       "cm848_calculateSensorEma; cleared each alpha execution (timingProtectionFlagsOrchestrator) and by "
       "cm848_initFuelPressureVariables. Not a cold start flag.",
    6: "e2m 104A +14 Filtered_Fuel_Delivery_Rate '[APFLDLRT] fuel rate, after filtering, which alpha uses in comparison to "
       "trigger Fuel_Rate' (LB/HR, 0.1 per count): cm848_calculateSensorEma filters fuel_mass_flow_raw into it (state "
       "cold_start_intake_temperature_filter_state) and compares it with alpha_reset_fuel_rate / alpha_threshold_fuel_rate; "
       "hpcr_calculateFuelTrimOutput zeroes it with the engine stopped or cranking. Not an intake temperature.",
    7: "e2m 104A +1A Alpha_Altitude_Derate_Timer (SEC, 0.2 per count; the e2m description repeats the AFC latch text): the "
       "altitude derate alpha latch timer: cm848_checkPressureFuelState reloads it with altitude_derate_alpha_timeout every "
       "pass while final_fueling_state is ALTITUDE_DERATE and counts it down after that (0 when bit 0x20 of "
       "feature_enable_flags_cal is clear). Not a governor initialization count.",
    13: "e2m 107C +2 ASG_Error_Difference '[ASERDC] ASG error difference' (RPM, 0.125 per count, signed): the change of the "
        "speed error between two passes in cm848_runOperatingModeSpeedGovernor: the new error "
        "(all_speed_governor_state_speed_error) minus the previous pass error, clamped to +-32000; the error-difference term "
        "of both PID difference equations. Not a PID input word.",
    14: "e2m 107C +4 ASG_Feedback_Difference '[ASFBDC] ASG feedback difference term' (RPM, 0.125 per count, signed): the "
        "change of the measured engine speed between two passes: governor_rpm_actual minus the previous pass speed "
        "(fuel_trim_pid_ema_snapshot, which a reset seeds from all_speed_governor_reset_state_engine_speed_previous, e2m "
        "ASG_Reset_State_X3), clamped to +-8000; subtracted times a gain in both PID equations. Not a previous output.",
    15: "e2m 107C +A ASG_Fueling '[ASFL] ASG FUELING' (MM3S, 0.0679 per count; the alias ASG_100_Fueling [ASMXFL] 'Fueling "
        "from 4D tables ... 100% throttle' shares +A): the all-speed governor fueling: cm848_runOperatingModeSpeedGovernor "
        "clamps correction + no-load fuel + ASG delta between governor_fuel_demand_tracking_floor / _limit into it; "
        "cm848_calculateEffectiveFuelLimit uses it in the droop equation. Not a previous demand.",
    16: "e2m 107C +C ASG_State_X1 '[ASSTX1] ASG state X1' (RPM, 0.125 per count, signed): state 1 of the all-speed governor, "
        "the speed error governor_reference_speed_filtered minus governor_rpm_actual (clamped to +-32000), stored every pass "
        "by cm848_runOperatingModeSpeedGovernor; the old value is the previous error that a reset seeds from "
        "all_speed_governor_reset_state_speed_error_previous (e2m ASG_Reset_State_X1). Not a PID reference.",
    17: "e2m 107C +14 ASG_State_X6 '[ASSTX6] ASG state X6' (MM3S, 0.0679 per count, signed): state 6 of the all-speed "
        "governor, the PID's fuel correction: (x5 x gain - previous x5 x gain + x6 x gain) >> 8 clamped to +-0x1700 in "
        "cm848_runOperatingModeSpeedGovernor, added to the filtered no-load fuel for the governor fueling; a reset seeds it "
        "from all_speed_governor_reset_state_fuel_demand_correction (e2m ASG_Reset_State_X6).",
    18: "e2m 107C +56 ASG_Delta 'Calculated amount to add to ASG to eliminate LSG-ASG deadband' (MM3S, 0.0679 per count): in "
        "the low speed governor state cm848_runOperatingModeSpeedGovernor integrates final_fueling minus the governor "
        "fueling (minus fuel_demand_integrator_offset_cal, e2m ASG_Delta_Offset) into it, otherwise it decays above idle; "
        "limit fuel_demand_integrator_upper_limit (e2m ASG_Delta_Max_Limit); added to the governor fueling and the droop "
        "equation in cm848_calculateEffectiveFuelLimit.",
    19: "e2m 107C +5A Decel_Rate_I_Term 'Integral term of rpm decel limit control' (MM3S, 0.0679 per count, signed): first "
        "word of the dword (the proportional term is the second word, e2m +5C Decel_Rate_P_Term): "
        "cm848_runOperatingModeSpeedGovernor adds fuel_demand_integrator_gain_a_cal x (engine_rpm_delta minus an offset) >> 8 per "
        "pass, clamped 0..fuel_demand_integrator_b_limit, zero below rpm_drop_fuel_minimum_manifold_pressure; the sum with the "
        "proportional term (e2m Decel_Limit_Fuel) is a floor of the governor output.",
    20: "e2m 1100 +0 J1939_Engine_Control_Status '[JCEGCOSS] J1939 ENGINE CONTROL STATUS 0 = INACTIVE' (0..1; EEPROM "
        "mirror): 1 while a J1939 engine control session is open: governor_sourceData_init(0) sets it when "
        "j1939_tsc1_override_state.governor_mode becomes non-zero with etc1_active_state 1, phase_group_a_setupETC1Controller "
        "clears it when the control ends and files the session in the J1939 history table. Not a calibration snapshot gate.",
    21: "e2m 1100 +2 J1939_Retarder_Control_Status '[JCRDCOSS] J1939 RETARDER CONTROL STATUS 0 = INACTIVE' (0..1; EEPROM "
        "mirror): 1 while a J1939 retarder control session is open: governor_sourceData_init(1) sets it when "
        "engine_retarder_override_control_mode is non-zero, phase_group_a_setupETC1Controller clears it when the control "
        "ends and files the session in the J1939 history table. Not a governor-mode calibration snapshot gate.",
    22: "e2m 1100 +8 J1939_History_Table_Next_Entry '[JCHSTBPO] pointer into J1939_History_Table' (0..65535; EEPROM mirror): "
        "index 0-4 of the history slot written next: governor_calibSnapshot_rollingBuffer_update copies the finished engine "
        "(argument 0) or retarder (argument 1) control session record (12 words from 0x3feb50 / 0x3feb6a) into that slot "
        "(24 bytes each from 0x3fead6, e2m 10FD, length word 0x78 at 0x3fead4), then adds 1 and wraps 5 to 0.",
    23: "e2m 1143 +0 Fuel_Temperature_Fueling_Index '[EPFTFLIX] Fuel temperature fueling severity index.' (1/256 per count, "
        "0..1; EEPROM mirror): word 0 of the 30-byte state record of the single fault derate channel (fuel temperature, ROM "
        "0x597b2; the channel loops step it by 15 words): cm848_calculateFaultDerateFuelLimit stores the fueling derate level "
        "(0-256) here; governor_faultDerate_mainLoop_update clears the active channel when it and the engine speed index "
        "(word 1) are 0.",
    24: "e2m 1227 +0 Intake_Air_Heater_Status '[JCGPSS] Status from fault handler indicating OBDII def. of monitor status' "
        "(UNITLESS): the J1939 monitor status of the intake air heater test, twin of misfire_monitor_result (e2m 1227 +2): "
        "cm848_j1939HandlePgn58112Dm7 sends it as the test-0 value of its PGN 65232 (DM8) answer, "
        "cm848_j1939HandlePgn65230Dm5Readiness reads it; nothing stores it (2 loads in ROM / flash2), so 0. Not a DM1 "
        "response mode.",
    26: "e2m 1735 +2 C_CBP_Residual_Mass_Min 'Min limit on residual mass estimation' (MM3S, 0.1359 per count): the floor "
        "that cm848_calculateResidualGasMass applies to cylinder_residual_gas_mass (the ceiling is the row at 0x4062d2, e2m "
        "C_CBP_Residual_Mass_Max); ROM-copied constant. Not a boost pressure ratio.",
    27: "e2m 175F +2 TPE_Corrected_Turbo_Speed 'Turbo speed input to compressor map in corporate units' (REV/SEC/SQRT(K), "
        "1/256 per count): the corrected turbocharger speed: cm848_estimateCompressorOutletTemperature stores "
        "turbocharger_speed x 0x106 / 10000 x 0x28b0b / compressor_inlet_temperature_square_root (cap 65535) and uses it as "
        "the y input of the compressor map lookup; cm848_calculateBoostTorqueOffset uses it as the input of three lookups. "
        "dump 4241. Not a fuel timing input.",
    28: "e2m 175F +6 TPE_CIT_Sqrt 'Square root of CIT' (SQRT(DEG_K), 1/128 per count, 10..30): "
        "cm848_estimateCompressorOutletTemperature looks it up from ambient_air_temperature_selected (fuel_timing_correction_b_* "
        "tables), multiplies the fresh air mass flow by it and divides the turbocharger speed by it (corrected flow / speed); "
        "cm848_estimateTurbochargerSpeed multiplies the corrected speed by it. dump 2122 (16.58 = sqrt of 275 K). Not a fuel "
        "timing correction.",
    29: "e2m 175F +C TPE_COT_Est_Enable 'Indicates whether the compressor estimation is active.' (UNITLESS, 0..1): "
        "cm848_selectCompressorOutletTemperature sets it to 0 when bit 0x80 of feature_enable_flags_cal is clear or both "
        "source states are 2 (compressor_outlet_temperature = the default fuel_flow_rate_default_cal) and to 1 otherwise "
        "(the estimate of cm848_estimateCompressorOutletTemperature is used). dump 1. Not a fuel timing range flag.",
    30: "e2m 1781 +2 CHP_Pumping_Torque_Adj 'Used by CBR in determination of gross fuel from net torque cmd' (FT*LB, 0.5 per "
        "count, signed): the pumping torque adjustment between net and gross torque: cm848_calculateBoostPressureOffset turns "
        "the nominal delta-P minus egr_delta_pressure_negated into torque, adds fuel_demand_blend_offset_cal and clamps it; "
        "cm848_calculateNetCombustionTorque subtracts it from the combustion torque, "
        "cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque (no-load torque).",
    31: "e2m 17A1 +0 Temperature_Delta 'Difference between IMT and exhaust temperature' (DEG_F, 0.5 per count, 0..1500): the "
        "exhaust temperature model's rise over the intake manifold temperature: cm848_calculateCombustionTemperatureRise "
        "stores boost_target_load_rpm_output << 8 / charge_fuel_ratio (floor 128) capped at 3000 (1500 F); "
        "cm848_auxiliaryControl_exponentialAverage copies it to exhaust_temperature_rise_over_intake_manifold_temperature and "
        "adds it to twice the intake manifold temperature. Not a boost target.",
    32: "e2m 17A1 +6 TPE_Invalid_Model 'Set to TRUE to protect against divide by zero in model' (UNITLESS, 0..1): "
        "cm848_auxiliaryControl_exponentialAverage sets it to 1 when current_rpm is below 8 counts (1 rpm) or "
        "charge_fuel_ratio is below 128, else 0; while it is 1 cm848_calculateCombustionTemperatureRise is skipped (rise = 0) "
        "and exhaust_temperature_source is 1. dump 1. Not a boost target inhibit.",
    33: "e2m 191A +0 WIF_Miles 'Actual miles for WIF too long' (MI, 1/256 per count; EEPROM 0x1a36): persistent distance "
        "with P2269 water in fuel active (1/256 mile per count if the task runs every 100 ms): zeroed while P2269 is clear, "
        "at 128000 (0x40a026, 500 miles at that rate) it sets P0169 (fault_detected_bits_336_to_351 bit 0). EEPROM-backed, "
        "so _cal. e2m 1930 +12 AATR_Numerator resolves here too (drifted block tail).",
    34: "e2m 1921 +6 Ambient_Air_Tmptr 'Ambient Air Temperature' (DEG_F, 1/64 per count, signed): the ambient air temperature "
        "of the air handling models: hpcr_fuelFinal_exponentialAverage stores the user override, the default (source state "
        "2) or the filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; "
        "cm848_blendBoostAndThrottleFuelDemand looks up the water saturation vapor pressure with it (cap 90 F). Reference "
        "twin of ambient_air_temperature_selected. dump 1620.",
    35: "e2m 1921 +A Compressor_Inlet_Press 'Compressor_Inlet_Pressure' (IN_HG, 0.0159 per count): "
        "hpcr_fuelFinal_exponentialAverage stores barometric_pressure_selected (minus the inlet pressure drop "
        "boost_fuel_pressure_offset_lookup when barometric_pressure_sensor_senses_ambient_air_flag_cal is set), floored at 1; "
        "divisor of the charge pressure ratio in cm848_estimateTurbochargerSpeed and of the corrected air flow in "
        "cm848_estimateCompressorOutletTemperature. dump 1647. Not a fuel scale divisor.",
    36: "e2m 1921 +10 Compressor_Inlet_Tmptr_Rise 'Temperature rise from ambient to compressor inlet' (DEG_F, 1/64 per "
        "count): hpcr_fuelFinal_exponentialAverage looks it up in a dual-axis table of the filtered fresh air mass flow and "
        "vehicle_speed_copy; ambient_air_temperature_selected minus it (filtered) is ambient_air_temperature_reference "
        "(cm848_initialization_step_3 subtracts it once at start). dump 640 (10 F). Not a timing target.",
    37: "e2m 1921 +14 Ambient_Relative_Humidity 'Relative humidity of ambient air (0 = dry air, 1 = saturated air).' "
        "(UNITLESS, 1/1024 per count): hpcr_fuelFinal_exponentialAverage looks it up on engine speed and "
        "injection_quantity_combustion_reference; cm848_blendBoostAndThrottleFuelDemand multiplies "
        "ambient_saturation_vapor_pressure by it >> 10 for ambient_water_vapor_partial_pressure (condensation model). dump "
        "1024 (saturated). Not an rpm blend scale.",
    41: "e2m 8000 +20 HPCR_Max_Scaling_Current_Compensation 'Maximum scaling factor for current compensation' (UNITLESS, "
        "signed, 1/4096 per count): the upper clamp of the fuel metering feedback trim: cm848_calculateFuelMeteringCommand "
        "limits the PI sum on fuel_metering_feedback_error to it (integrator wound back to it minus the proportional term); "
        "command = base + trim x base / 4096. ROM-copied constant, no _cal. dump 2049 (0.5). Not an engine sync limit.",
    42: "e2m 8000 +22 HPCR_Min_Scaling_Current_Compensation 'Minimum scaling factor for current compensation' (UNITLESS, "
        "signed, 1/4096 per count): the lower clamp of the fuel metering feedback trim (twin of "
        "fuel_metering_feedback_trim_maximum_scaling_factor): cm848_calculateFuelMeteringCommand limits the PI sum on "
        "fuel_metering_feedback_error to it and winds the integrator back to it minus the proportional term. ROM-copied "
        "constant, no _cal. dump -2049 (-0.5). Not an engine sync limit.",
    43: "e2m 8000 +32 HPCR_Fuel_Pressure_Filter_Constant 'Fuel pressure filter constant for Derivative Component' "
        "(UNITLESS, 1/65536 per count): the base coefficient of fuel_pressure_sensor_filter, the filter "
        "cm848_calculateFuelMeteringCommand runs on fuel_pressure_sensor before the derivative term (setpoint minus filtered "
        "pressure): cm848_resetEngineSyncState points it at this word; in the closed loop modes it is used times a speed "
        "factor >> 16 while cam_timing_alt_mode_enable_cal is 0. ROM-copied constant, no _cal. dump 43693.",
    49: "e2m 819B +A Backup_Lost_Counter '[ESTMCU02] Backup_Lost_Counter: Timeout counter for secondary speed input' (CNTS, "
        "0..10000): the lost-signal timeout counter of the tooth (secondary) speed input: mpc555_updateEngineCrankState "
        "(TPU-A channel 1 interrupt) reloads it with crank_sync_timing_scale_working on every tooth capture; "
        "cm848_updateEngineSpeedFromCrankSignal counts it down and zeroes crank_tooth_rpm at 0. Primary twin "
        "crank_period_countdown. Not an engine sync start-up countdown.",
    50: "e2m 819B +30 Low_Speed_Filtering 'Flag indicating low speed operation' (UNITLESS): "
        "cm848_updateEngineSpeedFromCrankSignal sets it to 1 when engine_rpm_measured is below "
        "crank_speed_setpoint_threshold_cal (after loading the low speed TPU-A channel 0 / 1 parameters from the "
        "crank_mios_*_cal words) and to 0 above it; mpc555_resetEngineTimingAccumulators starts it at 1. Written only (3 "
        "stores). dump 1. Not a crank sync validity flag.",
    52: "e2m 819B +42 PMA_Good_Window 'Tooth fraction defining expected normal tooth location' (UNITLESS, 1/64 per count, "
        "0..3.98): cm848_updateEngineSpeedFromCrankSignal looks it up from engine_rpm_measured (crank_mios_timing_*_cal) and "
        "programs the TPU-A channel 1 (tooth capture) window bytes 0x40 +- (this >> 1): a symmetric window around a ratio of "
        "1.0 (0x40); reset to 0 by mpc555_resetEngineTimingAccumulators. dump 64 (1.0). Not a MIOS timing output.",
    54: "e2m 819B +60 First_Speed_ISR_Time 'Global ECM start time information of POR time to 1st Speed ISR Time' (MSEC, "
        "0.0004 per count, dword): the time base (TBLr) captured once, by hpcr_processEngineSyncPulses (TPU-A channel 11 "
        "speed interrupt) on the first speed interrupt after power-on reset; engine_state_crank_time / _run_time, "
        "crank_tooth_period_tbl, crank_event_timebase_a / b / c and crank_resync_time_ticks are TBLr minus it. Not a "
        "previous capture.",
    55: "e2m 819B +64 Crank_Resync_Time 'First speed isr time to Last Crank Re-Sync Time' (MSEC, 0.0004 per count, dword): "
        "the time base time from the first speed interrupt (first_speed_interrupt_time_ticks) to the latest crank re-sync, "
        "TBLr minus it, stored with the re-sync count crank_tbl_event_counter (e2m Crank_Resync_Count) at each re-sync in "
        "hpcr_processEngineSyncPulses, mpc555_updateEngineRunState and mpc555_updateEngineCrankState.",
    56: "e2m 819B +7A HPCR_Fuelpr_Start_Undershoot 'Global ECM start time information of HPCR_Fuel_Pressure Undershoot.' "
        "(MPa, 0.0488 per count, signed, 0..200): the lowest rail pressure sensor reading during the start: "
        "hpcr_processEngineSyncPulses lowers it to fuel_pressure_sensor on each speed interrupt in engine run state 3 while "
        "the sensor is below it; mpc555_resetEngineTimingAccumulators sets it to 0xfff (4095 = 199.8 MPa, the e2m maximum) "
        "when it is 0. dump 4095. Not a cam sync position.",
    57: "e2m 8A0E +2 Coast_Accel_Timer 'Amount of time bump must be held before transitioning to coast/accel' (SEC, 0.04 per "
        "count): the reload of the cruise switch hold-off countdown governor_cruiseOverride_holdoff_countdown: "
        "governor_cruise_coastButton_handler / _setButton_handler / _resumeButton_handler load it on a button press and the "
        "held button becomes CRUISE_DECELERATE / CRUISE_ACCELERATE when the countdown reaches 0. ROM-copied constant, no "
        "_cal. dump 13 (0.52 s). Not a cruise override.",
}
for i, text in COMMENTS.items():
    assert entries[i]["verdict"] == "confirmed", i
    entries[i]["comment"] = text

EVIDENCE[22] = ("e2m 1100 +8 J1939_History_Table_Next_Entry: governor_calibSnapshot_rollingBuffer_update copies the finished "
                "engine / retarder control session record (12 words from 0x3feb50 / 0x3feb6a) into slot this (base 0x3fead6 "
                "from the asm: e2m 10FD starts at 0x3fead4 with the length word 0x78), then adds 1 wrapping 5 to 0; EEPROM "
                "mirror, so _cal")
EVIDENCE[14] = ("e2m 107C +4 ASG_Feedback_Difference: cm848_runOperatingModeSpeedGovernor stores governor_rpm_actual minus the "
                "previous pass speed clamped to +-8000 (the 0xe0c0 / 8000 stores) and subtracts it times a gain in both PID "
                "equations; the old name says previous output; type note: e2m signed, cast to short (row is word)")
for i, text in EVIDENCE.items():
    assert entries[i]["verdict"] in ("confirmed", "drift"), i
    entries[i]["evidence"] = text

