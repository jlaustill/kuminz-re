# bin6 draft verdicts (before advisor review)

idx addr old -> verdict / new
0  0x0040a895 fuel_mass_flow -> keep
1  0x0005c29a fuel_demand_rate_limit_debounce_low_cal -> rename accelerator_pedal_fault_delay   (_cal in ROM; throttle fault delay; sibling 0x5c2a4 -> accelerator_pedal_fault_delay_at_idle out of bin)
2  0x0005c2a0 idle_validation_fault_minimum_vehicle_speed -> keep
3  0x0040a16e pressure_fuel_delay_b_status -> rename alpha_air_fuel_control_result
4  0x0040a172 fuel_rate_condition_status -> rename alpha_on_governor_result
5  0x0040a174 pressure_fuel_delay_a_status -> rename alpha_low_speed_governor_result
6-12 1063 engine_speed_limit_* -> keep (12 keep: park_neutral_exit = rock cycle torque mgmt trigger; wave 12 decided)
13 0x003ff68e fuel_demand_speed_deadband_cal -> rename all_speed_governor_switch_droop_fueling_offset
14 0x003ff6a0 fuel_demand_integrator_offset_cal -> rename all_speed_governor_delta_offset
15,16 fuel_demand_decaying_peak_decrease_step_* -> keep
17 0x003ff6b8 engine_rpm_delta_high_offset_cal -> rename rpm_deceleration_limit_target_rate_high_zone
18 0x003ff6ba rpm_drop_fuel_minimum_manifold_pressure -> rename rpm_deceleration_limit_minimum_manifold_pressure (family consistency)  [borderline]
19,20 fuel_demand_ramp_rate / _step -> keep (borderline)
21 0x003ff6c4 engine_temp_protection_threshold -> rename fuel_demand_ramp_drivetrain_ratio_threshold
22 0x003ff6c8 fuel_demand_integrator_upper_limit -> rename all_speed_governor_delta_upper_limit
23 0x0040ae56 emission_fault_overflow_flag -> rename diagnostic_fault_to_erase [low-medium confidence; write-only]
24 0x0040ad96 protection_speed_ratio_c -> rename j1939_indicated_percent_torque_at_point_3_times_256
25 0x0040ad98 protection_speed_ratio_d -> rename j1939_indicated_percent_torque_at_point_4_times_256
26-35 1170 engine_operating_mode_restore_* -> keep
36 cruise_fuel_demand_floor keep
37 0x00408e6e fuel_demand_corrected_step_cal -> rename cruise_minimum_fuel_transition_ramp_rate  (sibling 0x3feff0 fuel_demand_correction_step_cal)
38 keep, 39 keep
40 0x003fd920 fuel_flow_rpm_mode_flag -> rename cruise_feedback_uses_road_speed_flag_cal
41 0x0040a885 governor_startup_fuel_blend_coeff -> rename master_slave_final_override_alpha
42 0x003fd51c j1939_pgn_priority_cal -> rename application_identifier_cal
43,44 keep
45 0x0005c94c cruise_speed_default_cal -> rename high_speed_governor_compensator_transition_coefficient (siblings cruise_speed_factor_a/b, offset, ... out of bin)
46-53 keep (162B IAH, 1631 BIR)
54 0x000642c4 underboost_minimum_target_speed -> rename underboost_minimum_engine_speed
55 keep
56-58 keep
59 0x003ff07a boost_pressure_timing_filter_coefficient -> rename ambient_air_flow_filter_coefficient (siblings boost_pressure_timing_filter_state, boost_pressure_timing_ema_filtered)
60-63 keep
64 0x003fee98 tpu_init_retry_count -> rename fuel_system_hardware_shutdown_error_count_cal

Function names wrong (not applied): protectionOutputActuatorControl @0x525504 / protectionRampRateControl @0x5251e4 (cruise governor),
cm848_fuelDemandSmoothingController @0x17560 (accelerator pedal idle validation fault), cm848_tpu_interrupt_flag_init @0x528b90 (TPU injection channel init; "init"), ...
