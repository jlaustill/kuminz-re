# bin3 notes (scratch, not a deliverable)

## Function-name leads (address, current -> proposed, reason)
- 0x00013aec cm848_processBoostProtectionMode -> cm848_estimateChargeTemperature : the TPE charge temperature estimate (e2m 1A1A/1A1B), not boost protection
- 0x00013ca4 cm848_initBoostProtectionState -> cm848_initializeChargeTemperatureEstimate : seeds the estimate's filter with sensor channel 9 and sets the quality byte
- 0x00510fa0 engine_protection_fuelMass_rpmCheck -> cm848_controlAirConditioningClutchForBrTruck : e2m 8A14 AC_Control_Configuration 0 algorithm, sets/clears logical output 0x26 (A/C clutch request)
- 0x00511078 engine_protection_conditionCode_evaluate -> cm848_controlAirConditioningClutchForDrTruck : the AC_Control_Configuration 1 algorithm (condition codes 1-15), logical output 0x26
- 0x005118f8 hpcr_fuel_mode_state_transition -> cm848_controlAirConditioningClutch : dispatcher on AC_Control_Configuration
- 0x005127d8 governor_cruise_speedError_integrate -> governor_cruise_rpmRatio_integrate : integrates the change of cruise_rpm_ratio_ema (engine speed / vehicle speed), not a speed error
- 0x00046d90 cm848_updateEngineStatusTimers -> cm848_monitorInjectionLimitViolationCounters : persistence counters of the TPU-A ch 2/7 end-of-injection-limit and injection-command-overlap flags, faults 325 / 326
- 0x0050e610 cm848_periodicControlLoopFaultHandling -> cm848_applyRemoteThrottleOverride : remote throttle priority override (e2m 1171) + copies remote throttle fault bits 64-79 0x4000/0x2000 to 160-175 0x800/0x1000
- 0x0002560c cm848_initJ1939EngineControlBuffer -> cm848_initializePgn65232NonContinuousMonitorTestResultBuffer : builds the PGN 65232 (DM8) tx descriptor (its sender is cm848_sendPgn65232...)
- 0x0001b900 initFaultTimerMessage -> cm848_initializePgn65251EngineConfigurationMessage : builds the PGN 65251 (EC1) tx descriptor (header 0xfee300) + J1939 reference fueling init
- 0x0001b730 cm848_sendFaultTimerMessage -> cm848_sendPgn65251EngineConfigurationMessage : buildPgn65251EngineConfiguration1Payload + sendJ1939Message(&j1939_pgn65251_tx_message)
- 0x00524df4 governorCruiseStateMachine -> cm848_initializeCruiseDroopGains (likely) : only sets the power-up top/bottom droop gains and offsets (no state machine)

## Out-of-bin siblings
- 106C: 0x3fd05c fuel_flow_rpm_divisor_prev (previous-pass drivetrain_ratio_user_filtered) -> drivetrain_ratio_user_filtered_previous
- 10EA: 0x4070aa governor_setpoint_table_cal (e2m 10EE +12 LSG_Aggressive_Proportional_Gain, byte, _cal in RAM) -> low_speed_governor_aggressive_proportional_gain ; 0x4070e6 governor_setpoint_table_a (e2m 10EC +0 LSG_Default_Proportional_Gain) -> low_speed_governor_default_proportional_gain
- 1171: 0x408de2 fuel_demand_override_min_cal (e2m 1210 +0 Accelerator_Throttle_Priority, 9; _cal in RAM) -> accelerator_interlock_throttle_priority
- 1186/1187: 0x40b6a2 cruise_speed_setpoint_active (e2m 1187 +C Cruise_RSG_Error_Delta) -> cruise_droop_speed_error_delta ; 0x408e20 cruise_zone_speed_error_abs_limit (Gain_Thres, abbreviation abs) -> cruise_zone_2_speed_error_threshold
- 11D5: 0x3feff8/0x3feffa/0x3feffc fuel_demand_load_threshold_c/b/a -> air_fuel_control_fueling_threshold_1/2/3 ; 0x3feffe fuel_demand_load_threshold_d, 0x3ff002 fuel_demand_load_result_working, 0x3ff006 fuel_demand_load_select_working -> air_fuel_control_fueling_slew_rate_1/2/3 (dwords typed word)
- 1254: 0x3fd83a j1939_ackm_priority, 0x3fd83e j1939_cruise_ctrl_priority, 0x3fd842 j1939_dm1_priority, 0x3fd844 j1939_dm2_priority, 0x3fd84c j1939_dm11_priority (e2m says DM10, the code builds PGN 65234 = DM11): EEPROM mirror, missing _cal ; descriptors 0x3faeb8 j1939_pgn57344_tx_message -> j1939_pgn65504_tx_message, 0x3faa8c j1939_pgn56360_tx_message -> j1939_pgn56320_tx_message
- 16A1 (same function): 0x3ffcaa throttle_rate_pid_gain_cal (C_TGC_Turbo_Drt_Scale_Gain), 0x3ffcae fuel_demand_delta_scale_cal (C_TGC_Turbo_Drt_Deriv_Gain), 0x3ffcb0 fuel_flow_rate_divisor_cal (C_TGC_COT_Drt_Deriv_Gain), 0x3ffcb2 fuel_flow_rate_gain_cal (C_TGC_COT_Drt_Scale_Gain); working: 0x3fa176 fuel_demand_delta_working, 0x3fa184 fuel_demand_quantity_snapshot (turbo speed previous), 0x3fa182 fuel_flow_rate_prev_snapshot (COT previous), 0x3fa1ac governor_first_iteration_flag
- 1A1A/1A1B: 0x3fa60e fuel_demand_boost_offset_filter (EMA record) -> charge_temperature_estimate_filter ; 0x40a456 injection_enable_mode_byte (e2m 1A1B +4 Charge_Tmptr_EStat) -> charge_temperature_estimate_status
- 804A/804B: 0x4090ce injection_timing_count_b_max_cal (Injection_Command_Overlap_Threshold, _cal in RAM) -> injection_command_overlap_count_threshold ; 0x40b858 injection_timing_count_a (EOI_Limit_Count) -> injection_end_limit_exceeded_count ; 0x40b85a injection_timing_count_b -> injection_command_overlap_count
- 8A0F: 0x40b204 cruise_speed_error_integral (e2m 8A0F +0 Cruise_N_V_Ratio_Int) -> cruise_rpm_ratio_integral
- 8A14: 0x4086b4 protection_event26_rpm_high_gate_lower (AC_Low_RPM_Off), 0x4086b8 protection_event26_rpm_high_debounce_limit (AC_Low_RPM_On_Time) + the working protection_event26_* words 0x3fcd5e-0x3fcd78 and bytes 0x40b1e6/7 -> air_conditioning_*
- 8C33: working words in cm848_monitorConverterClutchAndOverdrivePerformance with the wrong protection_ prefix: 0x3fcefc protection_output_phase_entry_flag, 0x3fcefe protection_pid_rpm_setpoint_prev, 0x3fcf00 protection_fuel_demand_prev, 0x3fcf02 protection_output_rate_counter, 0x3fcf04 protection_fuel_demand_tick_snapshot, 0x3fcf06 protection_action_mode_b2_snapshot
- 81AE: 0x408f14 crank_sync_coolant_threshold_cal (e2m 81AE +32 CBD_Coolant_Temp_Threshold, i16, RAM) -> cylinder_balance_coolant_temperature_threshold
