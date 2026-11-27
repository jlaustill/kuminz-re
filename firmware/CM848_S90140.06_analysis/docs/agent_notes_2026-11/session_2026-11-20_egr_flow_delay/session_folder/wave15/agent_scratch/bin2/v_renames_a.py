"""Renames, part A: crank, low speed governor family, engine protection restart limitation, gain set, boot pointer."""

V = [
    # ---------------- 105E crank routine
    {'address': '0x0040a79c', 'verdict': 'rename',
     'new': 'crank_four_dimensional_timing',
     'evidence': "e2m 105E +4 Crank_4D_Timing (CRANK_DEG_BTDC, S, 0.1171875, -120..120): cm848_initColdStartLimits stores 0xfc00 = "
                 "-1024 x 0.1171875 = -120 deg, the record minimum, as it does for crank_exit_advance (e2m 105E +1E); that is the only "
                 "access (1 sth, no read); the old name said rpm adjust but the unit is degrees BTDC; row typed word, the record is "
                 "signed (i16 fits)",
     'code_quote': "cm848_initColdStartLimits: cold_start_rpm_adjust_c = 0xfc00;",
     'comment': "e2m 105E +4 Crank_4D_Timing '[CK4DTA] 4D TIMING OUTPUT BY CRANK' (CRANK_DEG_BTDC, 0.1171875 deg per count, signed "
                "-120..120; 0 in the dump): the crank routine's four dimensional (4D) timing output. "
                "The only code access is cm848_initColdStartLimits storing 0xfc00 = -1024 = -120 deg, the record minimum, as the start "
                "value (the same function stores -0x400 into the neighbour crank_exit_advance, e2m 105E +1E); xref: word (0 reads / 1 "
                "write, sth). The row is typed word while the record is signed: i16 would fit."},

    # ---------------- 1065 low speed governor (LSG) PID terms
    {'address': '0x0040ae9a', 'verdict': 'rename',
     'new': 'low_speed_governor_integral_term',
     'evidence': "e2m 1065 +6 LSG_Integral_Term (MM3S, S): cm848_runLowSpeedGovernor sets it to the high word of the integrator accumulator "
                 "(governor_fuel_demand_correction_accumulator) and adds it to the proportional, derivative and jerk terms into "
                 "low_speed_governor_fueling_working; cm848_updateSpeedProtectionLimits presets the accumulator from it (record +1A "
                 "'used previous integral'); dump 54 = 3.7 mm3; the old name said fuel demand correction",
     'code_quote': "cm848_runLowSpeedGovernor: (int)governor_fuel_demand_correction + (int)governor_speed_error_derivative + iVar6 +",
     'comment': "e2m 1065 +6 LSG_Integral_Term '[LSITFL] LSG PID integrator fueling contribution' (MM3S, 0.0679 mm3 per count, signed; 54 = "
                "3.7 mm3 in the dump): the integral term of the low speed governor. cm848_runLowSpeedGovernor sets it to the high word of "
                "the Q16.16 integrator accumulator (governor_fuel_demand_correction_accumulator, clamped between "
                "governor_fuel_correction_threshold_cal and governor_speed_pid_output_working) and sums it with the proportional "
                "(governor_speed_weight_a), derivative (governor_speed_weight_b) and jerk (governor_speed_error_derivative) terms, the "
                "feed forward and the alternator load into low_speed_governor_fueling_working. cm848_updateSpeedProtectionLimits presets "
                "the accumulator from it when the previous integral is kept (low_speed_governor_integrator_preset_used_previous_flag); "
                "cm848_runLowSpeedGovernor sets it to governor_fuel_correction_init_cal (and clears the other terms) while the engine speed is "
                "above the idle reference speed plus governor_integrator_offset_cal and adjusted_user_fueling is below "
                "governor_fuel_demand_reset_threshold_cal. xref: i16 (every load lha)."},

    {'address': '0x0040aea4', 'verdict': 'rename',
     'new': 'low_speed_governor_derivative_gain_adjustment',
     'evidence': "e2m 1065 +10 LSG_QD_Adjustment (UNITLESS, 1/128, 0..8): cm848_runLowSpeedGovernor multiplies the speed error rate x the "
                 "third word of the gain set (the derivative gain, e2m 10EC +4 LSG_Default_Derivative_Gain) x this and stores the result "
                 "as the derivative term (the e2m 1065 +4 row); written 0x80 = 1.0 by cm848_runLowSpeedGovernor and "
                 "cm848_initSpeedProtectionParameters, dump 128; the old name was gain factor a",
     'code_quote': "cm848_runLowSpeedGovernor: (int)governor_p_gain_from_table * (int)(short)governor_pid_gain_factor_a)",
     'comment': "e2m 1065 +10 LSG_QD_Adjustment '[LSQDAJ] LSG derivative gain adjustment coefficient' (UNITLESS, 1/128 per count, 0..8; "
                "128 = 1.0 in the dump): the multiplier of the low speed governor's derivative term. cm848_runLowSpeedGovernor multiplies "
                "governor_speed_error_rate x governor_p_gain_from_table (the third word of the 4-word gain set, the derivative gain: e2m "
                "10EC +4 LSG_Default_Derivative_Gain) x this and filters the result into governor_speed_weight_b (the derivative term, e2m "
                "1065 +4 LSG_Derivative_Term). It writes 0x80 (1.0) here before each use, and cm848_initSpeedProtectionParameters "
                "writes 0x80 too: xref 1 read (lha) / 2 writes, so it stays 1.0."},

    {'address': '0x0040aea6', 'verdict': 'rename',
     'new': 'low_speed_governor_integral_gain_adjustment',
     'evidence': "e2m 1065 +12 LSG_QI_Adjustment (UNITLESS, 1/128, 0..8): cm848_runLowSpeedGovernor multiplies the speed error x the second "
                 "word of the gain set (the integral gain, e2m 10EC +2 LSG_Default_Integral_Gain) x this / 0x23 and adds it to the integrator "
                 "accumulator whose high word is the integral term; written 0x80 = 1.0 by cm848_runLowSpeedGovernor and "
                 "cm848_initSpeedProtectionParameters, dump 128; the old name was gain factor b",
     'code_quote': "cm848_runLowSpeedGovernor: (int)(short)governor_pid_gain_factor_b) / 0x23);",
     'comment': "e2m 1065 +12 LSG_QI_Adjustment '[LSQIAJ] LSG integral gain adjustment coefficient' (UNITLESS, 1/128 per count, 0..8; 128 = "
                "1.0 in the dump): the multiplier of the low speed governor's integral gain. cm848_runLowSpeedGovernor adds governor_speed_error_delta "
                "x governor_d_gain_from_table (the second word of the 4-word gain set, the integral gain: e2m 10EC +2 LSG_Default_Integral_Gain) "
                "x this / 0x23 to governor_fuel_demand_correction_accumulator, whose high word is the integral term (e2m 1065 +6). It writes 0x80 "
                "(1.0) here before each use, and cm848_initSpeedProtectionParameters writes 0x80 too: xref 1 read (lha) / 2 writes, so it stays 1.0."},

    {'address': '0x0040aeae', 'verdict': 'rename',
     'new': 'low_speed_governor_integrator_preset_used_previous_flag',
     'evidence': "e2m 1065 +1A LSG_Integrator_Preset_Used_Previous (0/1, 'if 1 used previous integral on last reset; if 0 used reset value'): "
                 "cm848_updateSpeedProtectionLimits sets it to 1 in the branch that presets the integrator accumulator from the previous "
                 "integral term (governor_fuel_demand_correction) and to 0 in the branch that uses the computed reset value; write-only, "
                 "no reader; the old name said fuel demand correction active",
     'code_quote': "cm848_updateSpeedProtectionLimits: governor_fuel_demand_correction_active_flag = 1;",
     'comment': "e2m 1065 +1A LSG_Integrator_Preset_Used_Previous 'If=1, LSG used previous integral on last reset; if=0, used reset value.' "
                "(UNITLESS, 0..1; 0 in the dump). cm848_updateSpeedProtectionLimits (the integrator preset when the low speed governor takes "
                "over) sets it to 1 when engine_state is RUNNING, cold_start_fuel_demand_correction_enable_cal is set and either "
                "governor_speed_low_clamp is below cold_start_governor_speed_clamp_threshold_cal or vehicle_speed is at or below "
                "governor_fuel_demand_correction_maximum_vehicle_speed: the accumulator then starts from the previous integral term "
                "(low_speed_governor_integral_term); otherwise it sets 0 and the accumulator starts from the computed reset value "
                "(final_fueling minus the proportional term and the feed forward). Write-only: xref 0 reads / 1 write (sth)."},

    # ---------------- 10EC LSG default gain set
    {'address': '0x004070e6', 'verdict': 'rename',
     'new': 'low_speed_governor_default_proportional_gain',
     'evidence': "e2m 10EC +0 LSG_Default_Proportional_Gain (MM3S/RPM, S, 0.000488, dump 164 = 0.080): cm848_updateGovernorSetpointParameters "
                 "points governor_setpoint_table_ptr here by default and loads the 4-word gain set (P, I, D, jerk) from it, the first word "
                 "being the proportional gain of the proportional term; the old name said setpoint table a (the rows at +2 / +4 / +6 are "
                 "named d / p / i gain with a _cal in RAM and the roles shifted: integral / derivative / jerk)",
     'code_quote': "cm848_updateGovernorSetpointParameters: governor_setpoint_table_ptr = (undefined *)&governor_setpoint_table_a;",
     'comment': "e2m 10EC +0 LSG_Default_Proportional_Gain '[LSDFPPGN] Low speed governor default proportional gain.' (MM3S/RPM, 1/2048 per "
                "count, signed 0..1.74; 164 = 0.080 in the dump): the first word of the 4-word default gain set of the low speed governor "
                "(P, I, D, jerk = e2m 10EC +0 / +2 / +4 / +6, 0x4070e6-0x4070ec). cm848_updateGovernorSetpointParameters points "
                "governor_setpoint_table_ptr at it when no other source selects a gain set and the requested mode is 0, then loads the "
                "four words into governor_speed_setpoint_raw (the proportional gain: error x it x the proportional adjustment / 0x22c86 is the "
                "proportional term), governor_d_gain_from_table (the integral gain), governor_p_gain_from_table (the derivative gain) and "
                "governor_j1939_gain_extra_working (the jerk gain); cm848_initGovernorLoadStateWrapper loads all four default words directly "
                "into the stored J1939 gains. This row is also the table base the pointer is aimed at. The RAM dump shows the loaded gain words "
                "at 0x40ae76 / 0x40ae78 / 0x40ae7a as 164 / 164 / 77, the same as the defaults at 0x4070e6 / 0x4070e8 / 0x4070ea. Typed i16 "
                "(every load lha)."},

    # ---------------- 10B1 engine protection restart limitation
    {'address': '0x0040a772', 'verdict': 'rename',
     'new': 'engine_protection_restart_limitation_shutdown_command_flag',
     'evidence': "e2m 10B1 +0 Restart_Oil_Pressure_Shutdown (EPF shutdown engine command from the restart limitation algorithm): "
                 "cm848_updateEngineProtectionShutdown forces engine_shutdown_command_flag (e2m 10B1 +12) from it; its only writer "
                 "protection_state_transition sets it in the branch for channel index 4 once the consecutive shutdown count reaches the limit; "
                 "this calibration's channel loop has a single channel (index 0, enable bits 130 / 131 = e2m 106B +12 bits 2 / 3, the fuel "
                 "temperature word) so the index 4 branch never runs and the flag stays 0 (dump 0); the e2m label says oil pressure but the code "
                 "does not show which channel index 4 is (the oil pressure enables are e2m 106B +10 bits 12-15, outside this loop), so the name "
                 "follows the record description, not the oil pressure label; the old name said engine sync trigger",
     'code_quote': "cm848_updateEngineProtectionShutdown: if ((governor_faultDerate_engine_sync_trigger != 0) ||",
     'comment': "e2m 10B1 +0 Restart_Oil_Pressure_Shutdown '[EPRYO2SO] EPF SHUTDOWN ENGINE COMMAND FROM RESTART LIMITATION ALGORITHM.' "
                "(UNITLESS; 0 in the dump): the shutdown command of the engine protection restart limitation algorithm. "
                "protection_state_transition (called for the active channel by governor_fault_derateCalc_channelIter) "
                "writes it in the branch for channel index 4: when the channel's consecutive shutdown count has reached DAT_0005c2f4 (e2m 10B9 "
                "+0 Shutdown_Max_Limit) and the channel's shutdown delay (configuration word +0x1e) is below the record word at +6. "
                "cm848_updateEngineProtectionShutdown then sets engine_shutdown_command_flag (e2m 10B1 +12 Shutdown) when it is non-zero. "
                "This calibration's channel table has a single channel (index 0, fuel temperature), so the flag is never set. The e2m "
                "labels the algorithm the oil pressure one (EPRYO2): the code only shows channel index 4. This ROM's channel loop starts at "
                "enable bit 128 (e2m 106B +12, where index 0 is the fuel temperature channel, bits 130 / 131 = shutdown / restart enable) and the "
                "oil pressure enables sit in the word before it (e2m 106B +10 bits 12-15), so the oil pressure label is not confirmed."},

    {'address': '0x0040a774', 'verdict': 'rename',
     'new': 'engine_protection_restart_limitation_shutdown_approaching_flag',
     'evidence': "e2m 10B1 +2 Restart_Oil_Press_Shutdown_Approaching (EPF shutdown approaching command from the restart limitation algorithm): "
                 "cm848_updateEngineProtectionShutdown sets engine_protection_shutdown_approaching_flag (e2m 10B1 +14) from it; its only "
                 "writer protection_state_transition sets it in the channel index 4 branch; never set here (single channel, index 0, dump 0); "
                 "the e2m label says oil pressure but the code does not show which channel index 4 is (see the e2m 10B1 +0 row), so the name "
                 "follows the record description; the old name said channel active latch",
     'code_quote': "cm848_updateEngineProtectionShutdown: if ((governor_faultDerate_channel_active_latch != 0) ||",
     'comment': "e2m 10B1 +2 Restart_Oil_Press_Shutdown_Approaching '[EPRYO2SQ] EPF SHUTDOWN APPROACHING COMMAND FROM RESTART LIMITATION "
                "ALGORITHM.' (UNITLESS; 0 in the dump): the approaching-shutdown command of the engine protection restart limitation algorithm. "
                "protection_state_transition writes it as (channel record word at +6 != 0) in the same "
                "channel index 4 branch as engine_protection_restart_limitation_shutdown_command_flag, and clears that word when the shutdown "
                "override request latch is 1; cm848_updateEngineProtectionShutdown then sets engine_protection_shutdown_approaching_flag "
                "(e2m 10B1 +14 Shutdown_Approaching). This calibration's channel table has a single channel (index 0), so it is never set. "
                "The e2m labels the algorithm the oil pressure one (EPRYO2), which the channel index does not confirm (see the shutdown "
                "command flag's comment)."},

    # ---------------- 1198 application entry pointer (ROM)
    {'address': '0x0000810e', 'verdict': 'rename',
     'new': 'flash_operational_code_entry_pointer',
     'evidence': "e2m 1198 +0 Flash_Start_Address (HEX, 4 bytes, 'pointer to the Flash operational code entry location, from boot loader'): "
                 "mpc555_hardwareInitialization calls through it with argument 0; the ROM value 0x54380 (dump_raw 344960) is "
                 "mpc555_systemStartupInitialization, which calls cm848_applicationMain; the old name has Init (banned) and is not snake_case",
     'code_quote': "mpc555_hardwareInitialization: (*(code *)systemStartupInit_ptr)(0);",
     'comment': "e2m 1198 +0 Flash_Start_Address '[SSFHSRAD] Pointer to the Flash operational code entry location, from boot loader.' (HEX, 4 "
                "bytes; 0x00054380 here). ROM constant, so no _cal. mpc555_hardwareInitialization calls through it with argument 0 as the "
                "hand-off from the boot code to the application; the target is mpc555_systemStartupInitialization (0x54380), which calls "
                "cm848_applicationMain."},

    # ---------------- 11AE supervisor chip (the e2m ASIC) overspeed configuration
    {'address': '0x0040a042', 'verdict': 'rename',
     'new': 'supervisor_chip_engine_speed_targets_per_revolution',
     'evidence': "e2m 11AE +A ASIC_Engine_Speed_Targets_Per_Rev (CNTS, 1 byte, 1..255, dump 60): cm848_configureSupervisorChip divides 30000000 "
                 "by (the overspeed limit word 0x40a040 x this byte, read as ._0_1_) for the period it writes to the supervisor chip start-up "
                 "words; the row is typed word but holds two 1-byte records: the high byte is +A, the low byte is +B ASIC_Engine_Overspeed_"
                 "Persistance (0x40a043, dump 10, used as (byte) & 7 << 4); the old name j1939_timer_period_factor_b is not J1939",
     'code_quote': "cm848_configureSupervisorChip: uVar2 = 30000000 / ((uint)j1939_timer_period_factor_a * (uint)j1939_timer_period_factor_b._0_1_);",
     'comment': "e2m 11AE +A ASIC_Engine_Speed_Targets_Per_Rev '[ESASRVTT] Number of engine speed targets per crankshaft revolution.' (CNTS, 1 "
                "byte, 1..255; 60 in the dump): part of the overspeed configuration of the supervisor chip (the e2m ASIC) that "
                "cm848_configureSupervisorChip sends at start-up: the period it writes (0xD0xx low byte and the low 4 bits of the 0xD6xx word) is "
                "30000000 / (the overspeed limit 0x40a040, e2m 11AE +8 ASIC_Engine_Overspeed_Limit, x this byte, read as ._0_1_). The row is typed "
                "word: its low byte (0x40a043) is the next record, e2m 11AE +B ASIC_Engine_Overspeed_Persistance 'Consecutive occurances of "
                "engine overspeed to cause a shutdown' (10 in the dump), used as (byte) & 7 << 4 in the 0xD6xx word. xref: lbz."},

    {'address': '0x0040a044', 'verdict': 'rename',
     'new': 'supervisor_chip_overspeed_non_latching_flag',
     'evidence': "e2m 11AE +C ASIC_Engine_Overspeed_Type (0 latching / 1 non-latching, dump 1): cm848_configureSupervisorChip puts bit 0 of it "
                 "into bit 7 of the 0xD6xx word next to the occurrence count (bits 4-6) and the period (bits 0-3) of the supervisor chip "
                 "overspeed configuration; the old name j1939_timer_mode_flag is not J1939",
     'code_quote': "cm848_configureSupervisorChip: (j1939_timer_mode_flag & 1) << 7 | 0xd600;",
     'comment': "e2m 11AE +C ASIC_Engine_Overspeed_Type '[ESASOSTY] Action after an overspeed shutdown, 0=latching & 1=non-latching' (UNITLESS, "
                "0..1; 1 in the dump = non-latching): the last field of the overspeed configuration of the supervisor chip (the e2m ASIC) "
                "that cm848_configureSupervisorChip sends at start-up: bit 0 goes to bit 7 of the 0xD6xx word, next to the occurrence count "
                "(bits 4-6) and the high bits of the period (bits 0-3). xref: lbz, 1 read."},

    # ---------------- 1210 / 1299 override priorities
    {'address': '0x00408de2', 'verdict': 'rename',
     'new': 'accelerator_interlock_throttle_priority',
     'evidence': "e2m 1210 +0 Accelerator_Throttle_Priority (UNITLESS, 0..9, dump 9 'priority of Accelerator Interlock Feature w/r to other "
                 "Throttle Features'): cm848_checkDiagnosticFuelOverride (accelerator_interlock_enable set and switch 26 on) stores it into "
                 "fuel_demand_control_t.override_active when that is lower and zeroes override_value: a compare-and-take priority claim; the "
                 "remote throttle client uses its own priority (e2m 1171 +0 Remote_Throttle_Calibrated_Priority = fuel_demand_override_active_min); "
                 "the old name carried a _cal in RAM and said minimum",
     'code_quote': "cm848_checkDiagnosticFuelOverride: fuel_demand_control_t_0040a57a.override_active = fuel_demand_override_min_cal;",
     'comment': "e2m 1210 +0 Accelerator_Throttle_Priority 'Priority of Accelerator Interlock Feature w/r to other Throttle Features' (UNITLESS, "
                "0..9; 9 in the dump). RAM-resident constant, so no _cal. cm848_checkDiagnosticFuelOverride, with "
                "algorithm_enable_flags_12_cal.accelerator_interlock_enable set and switch 26 on, claims the throttle override when the active "
                "override priority fuel_demand_control_t.override_active is below this value: it stores this value there and sets "
                "override_value to 0 (a zero fuel demand override). The same compare-and-take pattern with the remote throttle's own "
                "priority (e2m 1171 +0 Remote_Throttle_Calibrated_Priority, fuel_demand_override_active_min) is the remote throttle claim in "
                "cm848_periodicControlLoopFaultHandling."},

    {'address': '0x0040b70c', 'verdict': 'rename',
     'new': 'high_speed_governor_working_gain_set_source_priority',
     'evidence': "e2m 1299 +0 HSG_Application_Gain_Set_Priority (HEX, 0..597, dump 0 'location containing the priority of the present source of "
                 "HSG gain set'): cm848_loadHighSpeedGovernorWorkingGainSet loads gain set 20 / 21 only when this word is at or below the gear "
                 "ratio source's priority (e2m 1298 +0 HSG_GR_Application_Priority = system_speed_limit_working_minimum) and then stores that "
                 "priority here: a compare-and-take priority location, not a system speed limit; no other code writes it",
     'code_quote': "cm848_loadHighSpeedGovernorWorkingGainSet: system_speed_limit_working = system_speed_limit_working_minimum;",
     'comment': "e2m 1299 +0 HSG_Application_Gain_Set_Priority 'Location containing the priority of the present source of HSG gain set' (HEX, "
                "0..597; 0 in the dump): the priority of the source that last set the high speed governor (HSG) gain set. "
                "cm848_loadHighSpeedGovernorWorkingGainSet, with algorithm_enable_flags_18_cal.high_speed_governor_gear_ratio_gain_enable set and "
                "this word at or below the gear ratio source's priority (e2m 1298 +0 HSG_GR_Application_Priority 'HSG gain schedule selection "
                "priority', system_speed_limit_working_minimum, 0 here), stores that priority here and copies gain set 20 or 21 into the "
                "high_speed_governor_*_working words. xref: no other writer. The bit 0x100 enable is clear in this calibration (EEPROM 0x13e = "
                "0x0008), so the gain set is never loaded."},
]
