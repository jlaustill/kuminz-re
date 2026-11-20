# W13 bin5 working notes (scratch, outside repo)
#0 0x3fd4b2 key_on_hour_meter_cal: KEEP (e2m 0027 +0 ECM_Run_Time_Backup)
#1 0x3fd510 checksum_validation_step_counter: RENAME -> calibration_download_security_key_cal ; code: ==0xff bypasses seed/key checks (cm848_validatePciSecurityKey, sciValidateSecurityKey, processSecurityCodeConversion, j1939_writeDiagMemory, ...)
#2 0x40aeb0 governor_speed_filter_output: RENAME -> low_speed_governor_alternator_load_fuel ; runLowSpeedGovernor: filter((scale*(alternator_field_duty_target - offset))>>14) added to LSG sum; also used cm848_applyProtectionRpmCorrectionFilter
#3 0x40ae6c pedal_fault_mode_fuel_demand_ramp: KEEP (limp home = pedal fault mode)
#4 0x40ae6e pedal_fault_mode_fuel_demand_limit: KEEP
#5 0x3fde48 fuel_demand_histogram_sample_count: RENAME (missing _cal; EEPROM mirror) -> load_histogram_total_sample_count_cal (neighbor +0 is load_histogram_start_engine_hours_cal); cap 3.6e9 = 100000 HR e2m max
#6 0x3feb8e etc1_state_timer_b: RENAME -> j1939_link_fault_timeout_count_cal (EEPROM mirror range); torqueControlModeHandler sets etc1_active_state=1 for J1939 TSC1; counter B (+2) counts for state==1; sibling A 0x3feb8c etc1_state_timeout_counter = J1708 count (not in bin; lead)
#7 0x40af06 fault_aging_triggered_flag: KEEP (drive cycle flag; wave12 drive_cycle_minimum_engine_run_time comment says so)
#8 0x40af07 coolant_overheat_condition_flags: RENAME -> warm_up_cycle_condition_flags ; engine_coolantTemp_overheat_monitor (0x5341a8) is really the warm-up cycle monitor (rise>40F vs start temp = bit0, > 140F = bit1, ==3 -> warm_up count++ & fault_ring_buffer_auto_clear_emission). function rename lead: cm848_monitorWarmUpCycle
#9 0x40af0a diagnostic_suppress_flag: RENAME -> end_of_line_mil_override_state ; diag_suppress_stateMachine = EOL test MIL override (cm848_runEndOfLineMisfireTestStep etc.); cm848_updateMilOnRequest, processPciRemoteFaultStatus; only 0/1 written
#10 0x40af0b diag_suppress_active_flag: RENAME -> end_of_line_mil_flash_request_flag ; cluster msg3 bit5 when field_mode_register==0x13ec; siblings diag_suppress_saved_flag/request_flag + func diag_suppress_stateMachine (0x50ddb4) not in bin = lead
#11 0x40afaa accelerator_pedal_press_count: KEEP (throttle cycles; comment already cites e2m)
#12 0x40b99e boost_pressure_pre_start_check_fault_flag: KEEP (BIR_Startup_Error)
#13 0x40b9a2 cssc_coolant_monitoring_cycle_count: DRIFT (1632 +4 BIR_Ratio; RAM 0x40b9a2.. belongs to coolant sensor performance monitor (cssc_coolant_temp_span 0x40b9a4, engine_cssc_coolant_state 0x40b9a6); block 1632 only +0,+2 in 11.46.06). lead: cssc = invented abbreviation family.
#14-16 0x407186/88/8a governor_speed_margin_cal_a/b/c: RENAME -> barometric_pressure_sensor_tolerance / boost_pressure_sensor_tolerance / oil_pressure_sensor_tolerance ; cm848_checkSensorDeviationFlags run once after key-off delay (cold_start_sensor_deviation_delay_cal 0x40718c = Pressure_Check_Delay_Time, 400); compares baro vs sensor ch77 (governor_integrator_bound_a 0x40bb8a=1703 ~ intake manifold 1700) vs ch38 (bound_b 0x40bb3c=0, no wrapper found); all 3 tolerances 0 in dump. iat_sensor_deviation_flags misnamed lead. sensor channel 38 identity unproven.
#17 0x40a532 nitrogen_oxide_target_off_nominal_adjusted: KEEP
#18 0x40a404 boost_pressure_rpm_scale_factor: RENAME -> engine_volumetric_efficiency ; clamp base 0.8 (0x400942=6554) upper 1.0 (0x400940=8192) val 7303=0.8915; throttleBasedFuelCalculation uses it*rpm>>13 as charge flow denominator; block 177D matches CHP struct. leads: fuel_demand_rpm_factor_base/upper_cal = Veff min/max; func names cm848_boostBasedFuelModifier / cm848_throttleBasedFuelCalculation
#19 0x40ba62 fuel_pressure_setpoint_not_reached_accumulator: KEEP (cusum leak pos)
#20 0x4051e4 fuel_demand_step_increment_cal -> boost_pressure_in_range_fault_count_increment (RAM no _cal)
#21 0x4051e6 fuel_demand_step_limit_cal -> boost_pressure_in_range_fault_set_threshold
#22 0x40a438 fuel_demand_step_accumulator -> boost_pressure_in_range_fault_count ; siblings (not in bin): 0x4051e0 fuel_demand_step_min_threshold_cal -> ..._clear_threshold ; 0x4051e2 fuel_demand_step_decrement_cal -> ..._count_decrement ; fault bit 0x8000 of bits_512_to_527 (fault 527)
#23-25 0x4094b2/b6/ba injection_timing_scale_cyl4/5/6_a_cal -> fuel_pressure_governor_integral_gain_small_signal / positive_large_signal / negative_large_signal ; cm848_integrateWithZoneGain gains +0/+4/+8, windows +12/+14 (= 0x4094be/c0 engine_sync_prot_scale_b_cal dword, lead split into 2 words); dump 8590/5154/8590 *0.00011641 = 1.0/0.6/1.0
#26 0x40b886 fuel_pressure_governor_proportional_term KEEP ; #27 0x40b88c fuel_pressure_governor_accelerator_feed_forward KEEP
#28 0x40b891 fuel_pressure_feedback_previous: KEEP? (HPCR_Filtered_Fuelpr_Control = filtered fuel pressure used in control; code copies fuel_pressure_feedback_filtered at governor pass) -> keep
#29 0x40b893 cam_speed_rate -> fuel_metering_command_filtered (EMA of fuel_metering_command through fuel_metering_command_filter; used for coil resistance)
#30 0x40b895 engine_sync_rpm_filtered -> fuel_metering_coil_resistance_filtered (R = filtered cmd*battV*5/(2*filtered feedback current), EMA cam_sync_rpm_filter_state), dump 722*0.005=3.61 ohm
#31 0x40b897 engine_sync_speed_raw -> fuel_metering_coil_temperature (= scale*resistance/0x138 + offset; used as start temperature when engine_sync_state_a/b ==5), dump 1943/64=30.4 F
#32 0x40b766 total_injection_quantity KEEP
#33 0x40b778 crank_sync_inhibit_flag -> cylinder_cutout_test_mask (SCI cmd 37 callback sets/clears bit per cylinder, 1000 timeout; injection dispatch tests (mask|cylinder_cutout_mask)>>idx &1; suspends cyl trim learn & contribution test)
#34 0x40b780 cylinder_cutout_mask KEEP (Bank_Cutoff; 0x55/0xaa)
#35 0x40b784 auxiliary_injection_quantity KEEP
#36 0x40b78c injection_quantity_scale_factor KEEP (speed limp derate; generic but accurate)  [maybe rename speed_limp_home_fuel_derate_scale]
#37 0x408f56 crank_sync_event_count_min_cal -> crank_sync_event_count_limit (RAM no _cal); byte at 0x408f56=255 Backup_Consec_Error_Thresh (high byte used `._0_1_`), word row overlays 0x408f57 (Bank_With_Added_Tooth=1, `(byte)` uses in hpcr_processEngineSyncPulses / mpc555_updateEngineCrankState) -> type should split
