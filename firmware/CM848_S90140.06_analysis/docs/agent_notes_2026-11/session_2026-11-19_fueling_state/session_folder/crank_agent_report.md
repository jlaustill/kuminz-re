Conventions: c#=cm848_rom.ghidra.cpp line (cm848_ functions): c17824 calculateColdStartFuelAdjust, c17893 calculateColdStartRpmAdjust, c17938 calculateColdStartTempTable, c17994 calculateIntakeAirAdjustment, c18032 checkColdStartConditions, c18053 processColdStartAdjustment, c18074 initColdStartTablePointers (jump-start ramp), c18106 processColdStartStateMachine (exit-fuel ramp), c18131 coldStartRpmTableLookup (timers), c18158 coldStartFuelFactorLookup, c18218 updateEngineState, c19316 selectFinalFueling. e2m = CHR_CC_11.45.01.07; +off = same offset in CM848; proposed names are e2m names spelled out. Blank conf = high. All words 16-bit (xref plus whole-ROM/flash2 scan); e2m-signed ones use lha: type i16 (0x40a79a/9c/a2/a6/b6/b8, 0x406858/5a/64/66/68).

Alignment (once; confirms the earlier 105E / 105F reading for all 42 words): 105E base 0x40a798 ends at 1068 (0x40a7c0). 105F base 0x406852: dump bytes equal ROM 0x6c46c (ROM copy, never written, outside the EEPROM mirror, so strip `_cal`); 1032 follows at 0x40687e. Units agree: helpers run every 4th phase = 20 ms = e2m SEC x0.02; two ramps run once per 40 phases = 200 ms = e2m "/SEC" x5; init and clamp +-1024 = e2m +-120 deg; dump: exit 800 rpm, exit time 3 s, re-entry 500 rpm (= RAM 4000).

|addr|old|new|evidence|conf|
|--|--|--|--|--|
|0x40a798|cold_start_advance_counter|crank_exit_timer|105E+00 c18135, c18035||
|0x40a79a|cold_start_rpm_adjust_b|crank_advance|+02 c17920||
|0x40a79c|cold_start_rpm_adjust_c|crank_4d_timing|+04 written -1024 c17880, never read; "4D" unknown|medium|
|0x40a79e|injection_timing_base_limit_working|crank_adjusted_initial_fuel|+06 c17851||
|0x40a7a0|fuel_timing_rpm_upper_limit|crank_adjusted_initial_rpm|+08 c17846||
|0x40a7a2|unnamed|crank_wet_stack_timing|+0A no access found|low|
|0x40a7a4|fuel_timing_correction_c|crank_coolant_exit_fuel|+0C c17836||
|0x40a7a6|fuel_timing_correction_a|crank_initial_advance|+0E c18009||
|0x40a7a8|fuel_timing_correction_b|crank_exit_fuel_adjustment|+10 c18111||
|0x40a7aa|governor_rpm_setpoint_output|crank_exit_speed|+12 c17981, ends CRANKING c18290||
|0x40a7ac|governor_cold_start_rpm_output|crank_fuel|+14 FUEL quantity c19345||
|0x40a7ae|fuel_timing_base_limit|crank_initial_fuel|+16 c17946||
|0x40a7b0|governor_fuel_timing_offset|crank_initial_fuel_adjustment|+18 c18087||
|0x40a7b2|fuel_timing_advance_cal|crank_initial_advance_break_speed|+1A c18014, RAM so no _cal||
|0x40a7b4|fuel_timing_table_output|crank_initial_fuel_break_speed|+1C c17952||
|0x40a7b6|cold_start_rpm_adjust_a|crank_exit_advance|+1E c17881||
|0x40a7b8|unnamed|injection_timing_before_startup|+20 only unreferenced code writes it|medium|
|0x40a7ba|torque_fuel_offset_trim|crank_initial_rpm_adjustment|+22 c18093||
|0x40a7bc|crank_event_sample_counter|crank_jump_start_timer|+24 c18142, c18299||
|0x40a7be|cold_start_rpm_threshold|crank_reentry_speed|+26 c18037, c18309||
|0x406852|fuel_timing_correction_c_cal|crank_exit_fuel_override|105F+00 c17843||
|0x406854|fuel_timing_correction_b_max_cal|crank_exit_fuel_ramp_maximum|+02 c18113||
|0x406856|cold_start_fuel_timing_correction_addend_cal|crank_exit_fuel_ramp_rate|+04 c18112||
|0x406858|fuel_timing_correction_load_max_cal|crank_high_manifold_temperature|+06 c18003||
|0x40685a|fuel_timing_correction_offset_cal|crank_low_manifold_temperature|+08 c18002||
|0x40685c|torque_fuel_timing_offset_cal|crank_jump_start_rpm_ramp_rate|+0A c18093||
|0x40685e|cold_start_fuel_timing_rpm_threshold_cal|crank_exit_fuel_ramp_rpm|+0C c18110||
|0x406860|cold_start_rpm_setpoint_cal|crank_exit_rpm|+0E c17983||
|0x406862|cold_start_advance_count_cal|crank_exit_time|+10 c18035||
|0x406864|cold_start_coolant_temp_threshold_cal|crank_jump_start_temperature_threshold|+12 c18082||
|0x406866|fuel_timing_correction_a_high_cal|crank_high_manifold_temperature_timing|+14 c18004||
|0x406868|fuel_timing_correction_a_low_cal|crank_low_manifold_temperature_timing|+16 c18009||
|0x40686a|fuel_timing_advance_high_cal|crank_high_manifold_temperature_rpm|+18 c18005||
|0x40686c|fuel_timing_advance_low_cal|crank_low_manifold_temperature_rpm|+1A c18014||
|0x40686e|cold_start_rpm_base_cal|crank_initial_reentry_speed|+1C c18041||
|0x406870|cold_start_rpm_threshold_addend_cal|crank_exited_reentry_speed_offset|+1E c18037||
|0x406872|cold_start_torque_fuel_offset_cal|crank_exited_initial_rpm_offset|+20 c18164||
|0x406874|governor_fuel_timing_offset_addend_cal|crank_jump_start_fueling_ramp_rate|+22 c18087||
|0x406876|fuel_timing_base_limit_cal|crank_initial_fuel_override|+24 c17956||
|0x406878|fuel_timing_table_override_cal|crank_initial_speed_override|+26 c17959||
|0x40687a|cold_start_governor_fuel_timing_offset_cal|crank_exited_initial_fueling_offset|+28 c18163||
|0x40687c|cold_start_crank_event_threshold_cal|crank_jump_start_time|+2A c18299||
|0x406884|engine_rpm_trigger_cal|engine_stopped_speed|1032+06 c18268; 1032 base 0x40687e, 6/6 with overspeed words||
|0x406886|governor_speed_engage_count_target_cal|ecm_power_down_timer_threshold|1032+08 c18356, 60 s||
|0x406888|governor_speed_engage_fault_count_threshold_cal|ecm_power_down_delay|1032+0A c18358, 2 s||
|0x3fd872|cold_start_rpm_active_flag|crank_exit_speed_switch_cal|1254+38, EEPROM+0x3f0; base 0x3fd83a, 15+ J1939 priority words by PGN; c17982; dump 0 = idle reference||
|0x3fd53e|cold_start_fuel_mode_ready_flag|engine_brake_driveline_brake_type_cal|1180+16, EEPROM+0xbc; base 0x3fd528: +02 85 mph, +04 106 mph, +0E two_speed_axle_enable_cal; 1 = retarder; c18305; dump 1||
|0x3fd5c4|cold_start_feature_enable_flags|algorithm_enable_flags_20_cal|106B+2A, EEPROM+0x142; 7 tested masks 0x100-0x8000 = its e2m enable bits; dump 0x0100||
|0x3fdfdc|engine_rpm_trigger_ready_flag|engine_startup_inhibit_cal|candidate: 1096+00 calibration record, single-record block; never written; c18268 needs 0|low|
|0x3fa840|cold_start_rpm_threshold_updated_flag|crank_reentry_speed_offset_applied_flag|c18035, c18139; no e2m|medium|
|0x5b1be-0x5b1e4|cold_start_fuel_demand_base_*|crank_initial_fuel_{x_axis,y_axis,grid}|8A49/48/47||
|0x5b25c-0x5b282|cold_start_fuel_demand_at_governor_setpoint_*|crank_exit_fuel_*|8A4C/4B/4A||
|0x5b2fa,0x5b30c|cold_start_fuel_ramp_start_rpm_*|crank_initial_speed_{axis,values}|8A46/45||
|0x5b1b6-0x5b1bc|DAT_0005b1b6/b8/ba/bc|crank_initial_default_fuel, _default_rpm, _fuel_maximum, _speed_maximum|8A44+0/2/4/6; 70 mm3, 450, 200 mm3, 950 rpm||
|0x40a5f4/f6|cold_start_phase26_fuel_mode_flag, fuel_coldStart_phase26_demand_floor|engine_start_warmup_protection_active_flag, _emission_level_cap|19B3+0/+2 c61560||
|0x40a5f8/fa|cold_start_phase3_fuel_mode_count_met_flag, _fuel_demand_floor|extended_idle_protection_active_flag, _emission_level_cap|19B1+0/+2||
|0x3fbc9c, 0x406570|cold_start_phase3_fuel_mode_count, _count_max|extended_idle_timer, extended_idle_time_threshold|19B0+02; +2 per 0.2 s c61610|medium|
|0x40a5fc/fe|cold_start_boost_override_*|extreme_ambient_overheat_protection_active_flag, _emission_level_cap|19A4; coolant 217/222 degF (19A1): hot, not cold||

Flags. engine_starting (0x40a784) is a shutdown request: e2m 10B1+12 Shutdown ("turn off all solenoids"); block base 0x40a772, 10 anchors (fault_derate_* words +0A/0C/0E/10/14/16/18, governor_fuel_derate_state +1E). Setters: fault-derate monitor c63996, c64025, c64041, held c64059 by governor_faultDerate_latch (cleared in STOPPED c63929); J1939 service 6. Cleared by cm848_completeEngineStartSequence and SHUTDOWN at rpm 0 (c18346). Gates: STOPPED/RUNNING to SHUTDOWN (c18278, c18315, c18368); injection quantity 0 (c84787); rail pressure setpoint 0 (c85696); final fueling (c19329). Name engine_shutdown_command_flag, high.
engine_shutdown_active_flag (0x40aa98) is inverted: 1 suppresses key-off shutdown. Only setter J1939 service 24; cleared at the key-on edge (c18374). Key off and flag 0: SHUTDOWN (c18278, c18314, c18368), power-down timer counts (c18350), injection 0 (c84787), rail pressure governor KEY_OFF (c46631). Name key_off_shutdown_inhibit_flag, medium (120C+04 FSS_Key_Off_Shutdown is a one-anchor candidate; 120C does not line up).
0x40a334 engine_start_inhibit_flag: keep; working RAM, only written 0 (c18403).

Contradictions: governor_cold_start_rpm_output is fuel; the fuel_timing/injection_timing/torque_fuel/governor names at 0x40a79e-0x40a7ba are crank names. `_cal` is wrong on 0x406852-0x40687c, 0x406884-0x406888 and 0x40a7b2, missing on 0x3fd53e/5c4/872 and 0x3fdfdc. crank_advance and injection_timing_before_startup are used only by code at 0x1bee8-0x1bf40 (states 2/6/7; overwrites timing 0x40a2f0): no caller found (b/bl/bc, lis+addi/ori, 16/32-bit literals, ROM+flash2). ENGINE_BRAKE is not entered with this calibration. Stale: enums.csv:897 (CSP_*) and two global comments use old state names; engine_injectionAngle_writeTpuEvent plate reads engine_starting backwards; cm848_setEngineStarting and cm848_setColdStartMode2Flag are misnames. Untraced cold_start_* (protection, battery, timer_a/b, active_flag_c, engine_sync, intake_temperature_filter): other domains, unknown.