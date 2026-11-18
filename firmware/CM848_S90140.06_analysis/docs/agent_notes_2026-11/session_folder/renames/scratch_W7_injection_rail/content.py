# ---------------------------------------------------------------- functions
F('0x0001e870', 'cm848_processTorqueLimitState', 'cm848_calculateInjectionTimingOffset',
  ('Calculates the injection timing offset (timing counts of 0.1171875 degree) into injection_timing_offset_map_output: '
   'two engine speed x fuel_demand_computed maps (injection_timing_offset_map_a and injection_timing_offset_map_b) blended by the '
   'combustion alpha (Q14, 16384 = map a only, 0 = map b only), or the fixed injection_timing_offset_cal while '
   'engine_mode_control_flags bit 8 is set (fuel_demand_mode_code is 0 for the maps and 2 for the fixed value). Adds '
   'injection_timing_offset_increment_cal and sets fuel_demand_mode_flags to 1 when governor_feature_config_word bit 0x4000 is set, '
   'and copies the result to governor_rpm_offset_cached, which cm848_copyProtectionAccumulator overwrites with main_injection_timing '
   'before its only reader cm848_computeFuelRpmCompensatedOffset runs. Both maps are flat 171 counts (20 degrees) in the dump. '
   'Task of cm848_periodicTaskSet_auxiliaryControl (was cm848_processTorqueLimitState).'),
  ('Unit proven, consumer not: both maps are flat 171 and the output is 171 = injection_timing_offset_cal (EEPROM) = minus '
   'injection_timing_top_dead_center_offset (the top dead center position in timing counts); the fallback is injection_timing_offset_cal, '
   'the increment case assigns fuel_demand_mode_flags = 1 (cm848_setTimingIncrementFlags sets bits 0x10 / 0x20 / 0x40 of the same word) and '
   'fuel_demand_mode_code 0 / 2 is read by cm848_calculateMainInjectionTiming. No torque quantity anywhere. governor_rpm_offset is '
   'referenced by this function only and its cache is overwritten by cm848_copyProtectionAccumulator (= main_injection_timing) before the '
   'only reader, so the result has no live consumer: a leftover legacy path. Confidence medium-high on the domain, not on the use.'))

F('0x00020860', 'cm848_selectTorqueLimitStateMachine', 'cm848_calculateDriverDemandPercentTorque',
  ('Selects the driver demand fuel quantity driver_demand_fuel_quantity by governor_fuel_demand_mode (governor_fuel_demand_value for '
   'modes 4 / 5 / 6 / 9 / 10; for modes 7 / 8 the effective fuel limit of cm848_calculateEffectiveFuelLimit when '
   'variable_speed_governor_default_cal is 1, otherwise governor_proportional_gain_calc; the cruise modes 11 / 12 and the state codes in '
   'governor_pid_t.integral_term pick other values or hold the previous one) and scales it between fuel_demand_norm_zero_cal and '
   'fuel_demand_norm_fullscale to percent x 256 (clamped to +-32000) in driver_demand_percent_torque_times_256, which '
   'j1939GetEngineStateCode sends as the driver demand percent torque byte (offset -125) of PGN 61444, SPN 512. '
   '(was cm848_selectTorqueLimitStateMachine)'),
  ('Its only caller j1939GetEngineStateCode stores (j1939_dm1_spn_b_word >> 8) + 125 into j1939_eec1_driver_demand_torque_byte right after '
   'calling it (cpp 23808-23809) and sends PGN 61444. 100 percent = 25600 = 100 x 256 and the clamped division bounds are +-32000 = +-125 percent. '
   'The old name has neither a torque limit nor a state machine in it. The governor_pid_t fields it compares (integral_term against 1, 2, 4, 6, 37, 38) '
   'are state codes: see the note on governor_pid_t.'))

F('0x0002c114', 'cm848_updateTorqueLimitFromProtection', 'cm848_applySwitchSelectedEngineSpeedLimit',
  ('Lowers the engine speed limit droop cap engine_speed_limit_droop_cap (engine speed x 8; the droop branch of cm848_selectEngineSpeedLimit '
   'applies it) to engine_speed_limit_droop_cap_cal (30000 = 3750 rpm in the dump), or to engine_speed_limit_droop_cap_alternate_cal while '
   'a switch input (switch_input_state_bits[3] bit 0x80) is on, torque_source_count is above 1 and torque_limit_multi_source_enable_cal is 0, '
   'and records source code 1 in engine_speed_limit_droop_cap_source_code. First task of cm848_periodicTaskSet_auxiliaryControl; '
   'torque_source_count is 1 in the dump, so only the first limit is ever used. (was cm848_updateTorqueLimitFromProtection)'),
  ('Code: the chosen EEPROM word is compared with torque_limit_fuel_demand, which cm848_selectEngineSpeedLimit initializes to '
   'engine_speed_limit_default_cal (30000) and uses as a cap on applied_speed_limit, so both candidates are engine speed x 8 - not a torque or a '
   'protection value. xref_addr.py (name-based): torque_source_count and torque_limit_multi_source_enable_cal are read only here (1 read / 0 writes each).'))

F('0x00040de8', 'cm848_processTorqueLimitBounded', 'cm848_calculateGovernorFuelDemandUpperLimit',
  ('Sets governor_fuel_demand_upper, the upper bound of the governor fuel demand (fuel quantity counts), to governor_fuel_demand_upper_working, '
   'or to governor_fuel_demand_value + governor_fuel_demand_mode_b_offset_cal while governor_fuel_demand_mode is 11, and caps it at 5888 '
   '(the 400 mm3 fuel maximum). Called from cm848_processProtectionRampControl, whose mode logic compares governor_fuel_demand_working and '
   'the TSC1 mode 3 limit with it. (was cm848_processTorqueLimitBounded)'),
  ('Code: three assignments to one global in fuel quantity units (5888 = 0x1700, the fuel clamp used all over the injection code); the reader '
   'cm848_processProtectionRampControl compares it with governor_fuel_demand_working (cpp 40943+). The caller is the governor demand mode '
   'machine, not a torque limit.'))

F('0x0004279c', 'cm848_applyProtectionTorqueLimit', 'cm848_applyFuelPressureFaultFuelLimit',
  ('Folds the rail pressure fault fuel limit fuel_pressure_fault_fuel_limit_working (set by cm848_applyFuelLimitsForFuelPressureFaults; '
   '5888 = none) into the running minimum fuel limit protection_fuel_limit_active and records source code 28 in governor_fuel_mode_command when '
   'it is the lower one. One of the fuel limit steps run by cm848_processProtectionLimits; its sibling cm848_enforceFuelLimitProtection does the '
   'same for the fault derate fuel limit with code 29. (was cm848_applyProtectionTorqueLimit)'),
  ('governor_fuel_limit_source has cm848_applyFuelLimitsForFuelPressureFaults as its writer (4r / 5w there; the P0193 / P0192 / fault 264 / P0251 / '
   'reaction / P0088 limits, 0x1700 = none) plus the startup init (xref_addr.py, name-based), and cm848_calculateEffectiveFuelLimit also reads it. '
   'governor_fuel_mode_command has 13 writes in 12 functions (xref_addr.py), two of them outside cm848_processProtectionLimits (cm848_processProtectionSelection, cm848_calculateProtectionRateLimited); this function writes 0x1c = 28 and cm848_enforceFuelLimitProtection 0x1d = 29.'))

F('0x0004285c', 'cm848_initProtectionTorqueLimit', 'cm848_initializeFuelDemandAndLimitInterpolationStates',
  ('Startup initialization of the fuel demand and fuel limit lookups: calls cm848_initializeBarometricFuelLimitInterpolationStates (barometric fuel limit), '
   'cm848_initFuelTableSizes (diag_state_group1_a..d, the first is the state argument of the lookup in cm848_fuelDemandBlendCalculator) and '
   'cm848_initFuelDemandTableDimensions (fuel_ema_slot_state_1 / 2, the first is the state argument of the lookup in cm848_calculateFuelDemandWithTrim), '
   'each a store of the start value 2 into cached axis offset words, and sets fuel_pressure_fault_fuel_limit_working to its no-limit value timing_limit_lower (5888). '
   'Called once from cm848_applicationMain. (was cm848_initProtectionTorqueLimit)'),
  ('Code: its body is three initializer calls and one store of timing_limit_lower (5888); callers by the cpp: cm848_applicationMain only. Checked this pass: '
   'diag_state_group1_a_state is passed as the first (cached axis offsets) argument of a lookup in cm848_fuelDemandBlendCalculator (cpp 8500) and fuel_ema_slot_state_1 in '
   'cm848_calculateFuelDemandWithTrim (cpp 19339); the other state words (b-d, slot 2) have no other named user, so they are inferred to be states of the same kind. '
   'No torque limit or protection logic.'))

F('0x00502b34', 'cm848_protection_torqueLimit', 'cm848_initializeBarometricFuelLimitInterpolationStates',
  ('Sets the three two-word interpolation states (cached axis offsets, start value 2 = first segment) of the barometric fuel limit lookups in '
   'cm848_calibrationGroup5_periodic - fuel_correction_table_dims_a (0x3fb9ca), fuel_correction_temp_band_dims_b (0x3fb9ce) and the state at '
   '0x3fb9d2, each with its second word - to 2. Called from cm848_initializeFuelDemandAndLimitInterpolationStates. (was cm848_protection_torqueLimit)'),
  ('Six stores of 2 into 0x3fb9ca / cc / ce / d0 / d2 / d4. cm848_calibrationGroup5_periodic passes the first word of each state as the '
   'cached-axis-offsets argument of cm848_dualAxisTableInterpolation with the fuel_limit_barometric_* tables and writes fuel_correction_upper_limit '
   '(a fuel limit, 5888 = none); the interpolator reads cached_axis_offsets[0] / [1] and treats 2 as segment 1.'))

F('0x005087e4', 'engine_torqueLimit_workingState_init', 'cm848_initializeFaultDerateEngineSpeedLimit',
  ('Initializes the fault derate engine speed limit: engine_speed_limit_fault_derate (source 5 of cm848_selectEngineSpeedLimit) and the '
   'accumulator of its filter state (ema_filter_state_t_003fbd2e, coefficient WORD_0005c2f2) to engine_speed_limit_default_cal, and '
   'engine_speed_limit_fault_derate_span to the default minus DAT_0005c2f0 (19200 = 2400 rpm). Called with cm848_resetFaultDerateFuelLimit by '
   'hpcr_initFuelTemperatureSensorChannel; cm848_calculateFaultDerateEngineSpeedLimit updates the same filter state. (was engine_torqueLimit_workingState_init)'),
  ('Code: the two engine speed x 8 values and the EMA accumulator (value << 16) are all set from engine_speed_limit_default_cal; the EMA state is '
   'also used by cm848_calculateFaultDerateEngineSpeedLimit (cpp 62519, renamed in wave 6), and the caller list is hpcr_initFuelTemperatureSensorChannel (cpp 62132-62133).'))

F('0x00509540', 'engine_torqueLimit_upperCap_calc', 'cm848_calculateFaultDerateFuelLimit',
  ('Calculates the fault derate fuel limit fault_derate_fuel_limit (fuel quantity counts, 5888 = no derate). For each channel of the derate '
   'table at 0x597b2 (one entry: the fuel temperature channel fuel_temperature_derate_input_pointer with its 200 to 210 degrees F ramp) it takes '
   'a derate level while the channel fault bits allow it, keeps the highest level of the unlatched channels and moves '
   'fault_derate_ramp_times_256 (0 to 256) toward it by DAT_0005c2ec (13) per call. With the ramp above 0 the limit lies between the '
   'fault_derate_fuel_limit_by_engine_speed curve (ramp 256) and protection_fuel_limit_cal_active (ramp near 0), otherwise it is timing_limit_lower; '
   'fault_derate_active_flag is the ramp above 0. Task 2 of the fault derate scheduler cm848_resetGovernorStartupReadyFlag. '
   '(was engine_torqueLimit_upperCap_calc)'),
  ('The output torque_limit_fuel_upper_cap is a fuel quantity limit (5888 = no derate in the dump) read by cm848_calculateEffectiveFuelLimit and '
   'cm848_enforceFuelLimitProtection (source code 29), not a torque limit. The CSV comment of fuel_temperature_derate_input_pointer says the only channel is the fuel '
   'temperature (ramp words 12800 / 13440 = 200 / 210 degrees F at ROM 0x597bc / 0x597be, which I read in the ROM). The loop itself is channel-generic (table stride 0x24, one '
   'entry before the fault_derate_fuel_limit_by_engine_speed_axis table at 0x597d6), so the name stays in the fault_derate family and does not say fuel temperature.'))

F('0x00509814', 'engine_protection_torqueLimit_reset', 'cm848_resetFaultDerateFuelLimit',
  ('Resets the fault derate fuel limit: fault_derate_ramp_times_256 to 0, its lookup state DAT_003fbd4e to 2, fault_derate_fuel_limit to '
   'the no-limit value timing_limit_lower (5888) and fault_derate_active_flag to 0. Called with cm848_initializeFaultDerateEngineSpeedLimit by '
   'hpcr_initFuelTemperatureSensorChannel. (was engine_protection_torqueLimit_reset)'),
  ('Code: four stores that are the exact reverse of the end of cm848_calculateFaultDerateFuelLimit (same four words); callers by the cpp: hpcr_initFuelTemperatureSensorChannel (62133).'))

F('0x005250c0', 'governor_cruise_torqueLimit_calc', 'cm848_calculateCruisePidRateGainScale',
  ('Calculates cruise_pid_rate_gain_scale = ((protection_timing_period_cal x protection_temp_scale_factor / 60) x 100 >> 7) x DAT_00408e60 >> 10, '
   'capped at DAT_00408e6a (4900). governor_cruise_speedError_torqueAdj multiplies the cruise speed error x cruise_pid_rate_gain_working / 1000 by it '
   '(>> 7, clamped to +-10000) and protectionOutputActuatorControl does the same to its rate term. Called from protectionRampRateControl and '
   'protectionOutputActuatorControl. (was governor_cruise_torqueLimit_calc)'),
  ('Medium confidence: the use is exact (cpp 81097-81100 and 81376: the product of the speed error or rate term with cruise_pid_rate_gain_working and then the scale, clamped), '
   'so it is a PID term scale and no torque limit; the physical meaning of the inputs is NOT identified (protection_timing_period_cal = 251 EEPROM with 7 reads in 5 functions '
   'incl. cm848_calculateDrivetrainRatioFromVehicleSpeed, protection_temp_scale_factor = 453 in the dump), so the name states only the verified role.'))

F('0x0050d864', 'cm848_calculateAuxiliaryTorqueLimitFromEngineRPM', 'cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit',
  ('Runs while engine_operating_mode is 6, the accelerator pedal fault mode (cm848_transitionEngineOperatingMode enters it from mode 0 on '
   'accelerator_pedal_input_fault_flag when the dual channel pedal is enabled, or on P2123 / P2122 (fault bits 10 / 11 of fault_detected_bits_0_to_15) when it is not, '
   'or when the J1939 pedal input times out or falls back). Ramps the fuel demand governor_proportional_gain: pedal_fault_mode_fuel_demand_ramp is 0 while accelerator_off_idle is not 1, '
   'starts at DAT_0005c498 (250) when it becomes 1 and then rises DAT_0005c494 (9) per call up to pedal_fault_mode_fuel_demand_limit (DAT_0005c492 = 854 minus a '
   'target speed term whose coefficient DAT_0005c490 is 0, or DAT_0005c4a4 while a switch input (switch_input_state_bits[1] bit 8 or [0] bit 4) or fault P0572 '
   '(fault bit 395) is active), slewed down at most DAT_0005c49c (9) per call. Also sets engine_speed_limit_pedal_fault_mode (source 14 of '
   'cm848_selectEngineSpeedLimit): the default, DAT_0005c4a0 under the same switch / fault condition, and at most DAT_0005c49e above vehicle speed DAT_0005c4a2; '
   'outside mode 6 it is the default. (was cm848_calculateAuxiliaryTorqueLimitFromEngineRPM)'),
  ('Mode 6 = accelerator pedal fault mode, read from cm848_transitionEngineOperatingMode (cpp 66473-66490): mode 6 is set only when engine_operating_mode is 0, DAT_0005c49a (cal) is nonzero and '
   'accelerator_pedal_input_fault_flag / fault_detected_bits_0_to_15 bits 0x400 / 0x800 (or the J1939 pedal fallback / timeout flags when fuel_demand_feature_flags bit 0x2000 selects the J1939 pedal) are set. '
   'Fault decode: the 0x5985a fault -> slot table is read with word width (it reproduces the documented b11 P2122 / b12 P2123 of fault_detected_bits_336_to_351 for faults 347 / 348); '
   'with it fault 10 = P2123, fault 11 = P2122, fault 395 = P0572. The ramp / limit constants are ROM 0x5c490-0x5c4a4 = 0 / 854 / 9 / 854 / 250 / 1 / 9. W6 left the subject of mode 6 open; the entry '
   'condition settles it.'))

# ---------------------------------------------------------------- globals (arbiter)
bw = ('cm848_selectEngineSpeedLimit (cpp 19764+): ')
G('0x0040a322', 'torque_limit_fuel_upper', 'engine_speed_limit_reference_lower_bound',
  bw + 'the code is "if (stored < torque_limit_fuel_upper) reference = torque_limit_fuel_upper (code 2) else if (torque_limit_fuel_floor < stored) reference = '
  'torque_limit_fuel_floor (code 3)", then torque_limit_fuel_upper = 0 and torque_limit_fuel_floor = engine_speed_limit_default_cal, so "upper" acts as the MINIMUM '
  'bound and "floor" as the MAXIMUM (the inversion from wave 6). Engine speed x 8. xref_addr.py (name-based): 1 read / 1 write, this function only; the dump holds 0, '
  'so the reset value is the permissive one and the bound is inert. Working RAM above 0x40000, outside the time-shared window.')
G('0x0040a320', 'torque_limit_fuel_floor', 'engine_speed_limit_reference_upper_bound',
  bw + 'maximum bound of the stored reference (see engine_speed_limit_reference_lower_bound); dump 30000 = engine_speed_limit_default_cal. xref_addr.py: 1 read / 1 write, this function only.')
G('0x0040a326', 'torque_limit_fuel_upper_working', 'engine_speed_limit_reference_lower_bound_snapshot',
  bw + 'copy of the lower bound taken at the start of every pass and never read (xref_addr.py: 0 reads / 1 write).')
G('0x0040a324', 'torque_limit_fuel_floor_working', 'engine_speed_limit_reference_upper_bound_snapshot',
  bw + 'copy of the upper bound taken at the start of every pass and never read (xref_addr.py: 0 reads / 1 write).')
G('0x0040a302', 'torque_limit_fuel_reference', 'engine_speed_limit_reference',
  bw + 'source 6 of the arbitration: the stored reference clamped to the two bounds, engine speed x 8 (dump 25600 = 3200 rpm), not a fuel value; the droop slope numerator is (torque_limit_offset_calc - this) x 4369.')
G('0x0040a31e', 'torque_limit_fuel_reference_stored', 'engine_speed_limit_reference_stored',
  bw + 'read once as the input of the clamp; cm848_initializeEngineSpeedLimitDefaults writes it with engine_speed_limit_reference_default_cal and xref_addr.py (name-based) finds no other writer (1 read / 1 write); dump 25600.')
G('0x0040a30e', 'torque_limit_fuel_demand', 'engine_speed_limit_droop_cap',
  bw + 'engine speed x 8 (reset to engine_speed_limit_default_cal = 30000 at the end of every pass) that caps applied_speed_limit in the droop branch; lowered by cm848_applySwitchSelectedEngineSpeedLimit (state code 1) and by source 2 in torque_limit_arb_mode 2 / 3 (state code 2). Not a fuel demand. xref_addr.py: 4 reads / 3 writes in these two functions.')
G('0x0040a312', 'torque_limit_state_machine', 'engine_speed_limit_droop_cap_source_code',
  bw + 'set to 1 by cm848_applySwitchSelectedEngineSpeedLimit and 2 by the source 2 branch, copied to torque_limit_state_machine_snapshot and reset to 0 at the end of the pass: the source code of the cap, not a state machine (xref_addr.py: 1 read / 3 writes).')
G('0x0040a30a', 'torque_limit_override_active_flag', 'engine_speed_limit_droop_active_flag',
  bw + 'written 0 on the direct-limit branch (sources 9 with ETC1 active, 11, 13 / 15 while torque_limit_source_d_f_disable_cal is 0, 16 and the two early returns) and 1 on the branch where the applied limit is the ramp plus the droop slope term; cm848_calculateEffectiveFuelLimit applies the droop slope only while it is 1.')
G('0x0040a31a', 'fuel_limit_state_code', 'engine_speed_limit_reference_clamp_state_code',
  bw + 'written 1 (stored reference within the bounds), 2 (raised to the lower bound) or 3 (cut to the upper bound) in the same statement block as the reference clamp; xref_addr.py: 0 reads / 2 writes, so it is a diagnostic word.')

# ---------------------------------------------------------------- globals (sources, cals)
G('0x0040a278', 'torque_limit_fuel_abs_min', 'engine_speed_limit_source_2',
  bw + 'source 2 of the arbitration: with torque_limit_arb_mode 0 / 1 it competes in the lowest-wins minimum (number 2), with 2 / 3 it lowers the droop cap (code 2). xref_addr.py (name-based) finds one reader (this function) and one writer, '
  'cm848_protection_init, which stores engine_speed_limit_default_cal (dump 30000 = 3750 rpm), so no real limit is ever written by a function the tool sees; the name states only the verified unit and the source number.')
G('0x0040a27a', 'torque_limit_fuel_minimum_snapshot', 'engine_speed_limit_source_4',
  bw + 'source 4 (compared with <=, number 4); xref_addr.py (name-based): 1 read here and 1 write in cm848_initializeEngineSpeedLimitDefaults (default 30000).')
G('0x0040a310', 'torque_fuel_limit_active', 'engine_speed_limit_source_10',
  bw + 'source 10; when it wins the droop slope word at 0x40a306 is zeroed first (the limit then cuts the fuel at once). xref_addr.py (name-based): 1 read here, 1 write in cm848_initializeEngineSpeedLimitDefaults (default 30000).')
G('0x003fd816', 'torque_limit_arb_mode', 'engine_speed_limit_source_2_mode_cal',
  'EEPROM-backed (inside 0x3fd482-0x3feec1, 4 reads / 0 writes, all in cm848_selectEngineSpeedLimit): 0 / 1 sends source 2 into the lowest-wins minimum, 2 / 3 into the droop cap; the dump holds 0. '
  'Time-shared window checks: xref_addr.py lists no boot-ROM user and my immediate scan of 0..0x7F5F for 0xd816 found 0 hits (misses split base + offset forms).')
G('0x003fd80c', 'torque_limit_offset_init', None,
  'EEPROM-backed word (dump 28000 = 3500 rpm = engine_speed_limit_maximum) read once, by cm848_initializeEngineSpeedLimitDefaults, as the initial torque_limit_offset_calc; that word is the speed argument of the fuel curve lookup and of the droop slope numerator in the arbiter, so my reading is the end speed of the droop line - not settled. '
  'Candidate if confirmed: engine_speed_limit_droop_end_speed_default_cal. torque_limit_offset_stored / _enable_flag / torque_limit_lookup_disable_flag have no writer (xref_addr.py). Time-shared window: immediate scan 0 hits.', 'uncertain')
G('0x003fd80e', 'torque_limit_source_b_working', 'engine_speed_limit_droop_cap_cal',
  'EEPROM-backed (inside the range, 1 read / 0 writes, cm848_applySwitchSelectedEngineSpeedLimit only), dump 30000 = 3750 rpm: the calibrated engine speed x 8 cap. xref_addr.py lists no boot-ROM user; immediate scan of 0..0x7F5F for 0xd80e: 0 hits.')
G('0x003fd810', 'protection_fuel_limit_param', 'engine_speed_limit_droop_cap_alternate_cal',
  'EEPROM-backed (inside the range, dump 30000), the alternative cap of cm848_applySwitchSelectedEngineSpeedLimit chosen by the switch input; xref_addr.py: 1 read / 0 writes, that function only. Time-shared window: immediate scan of 0..0x7F5F for 0xd810: 0 hits.')
G('0x003fdb84', 'torque_limit_control_flags', None,
  'EEPROM-backed word (inside the range, dump 0) with 0 direct reads / 0 writes by xref_addr.py: reached only indirectly, so its role cannot be settled from the code. Immediate scan of the boot ROM: 0 hits. No name given.', 'uncertain')
G('0x00406fe6', 'torque_limit_fuel_upper_cal', None,
  'Clamp bounds of the word injection_timing_compensation_b in the droop slope term of cm848_selectEngineSpeedLimit (applied = ramp + slope x (torque_limit_table_output - clamp(injection_timing_compensation_b, lower, upper)) / 4369); the role of the clamped word is open, so no new name.', 'uncertain')
G('0x00406fe8', 'torque_limit_fuel_lower_cal', None,
  'Lower clamp bound of the same term as torque_limit_fuel_upper_cal; see that row. Outside the EEPROM range (0x406fe8), so any new name drops _cal.', 'uncertain')

# ---------------------------------------------------------------- converter slip
cs = 'cm848_monitorConverterSlipAndEngineSpeedLimit (cpp 39927+): '
G('0x00408baa', 'torque_limit_enable_cal', 'converter_slip_output_speed_sensor_enable',
  cs + 'while transmission_output_speed_in_use is 0 or this word is not 1 the output shaft speed equivalent comes from vehicle_speed x vehicle_speed_to_output_speed_scale, otherwise from transmission_output_speed_in_use; dump 1. 0x408baa is outside the EEPROM range, so no _cal.')
G('0x00408bac', 'torque_fuel_accumulator_limit', 'converter_slip_counter_limit',
  cs + 'torque_converter_slip_warning_flag is set once the slip counter (0x40b612) reaches it; dump 1000 (the CLAUDE.md figure).')
G('0x00408bb0', 'torque_limit_cycle_divisor', 'converter_slip_counter_decrement_divisor',
  cs + 'with no slip the counter drops by 1 on every divisor-th call (dump 2); 0 stops the decrement.')
G('0x00408bb2', 'torque_limit_rpm_spread_threshold', 'converter_slip_speed_difference_threshold',
  cs + 'slip counting needs engine speed minus the output equivalent above it; dump 6400 = 800 rpm.')
G('0x00408bb6', 'torque_limit_rpm_offset', 'converter_slip_engine_speed_threshold_offset',
  cs + 'second threshold = equivalent x scale / 64 + this; dump 10400 = 1300 rpm.')
G('0x00408bb8', 'torque_limit_rpm_scale', 'converter_slip_engine_speed_threshold_scale',
  cs + 'second threshold = equivalent x this / 64 + offset; dump 125 = 1.95 (CLAUDE.md: above 1.95 x output + 1300 rpm).')
G('0x00408bba', 'torque_limit_load_axis_cal', 'engine_speed_limit_converter_slip_x_axis',
  cs + 'x axis (10 breakpoints after the byte-length word, 40..400 = fuel_demand_control_t.calculated, the x argument of the call) of the engine speed limit table; type word[11] unchanged.')
G('0x00408bd0', 'torque_limit_table_fuel_cal', 'engine_speed_limit_converter_slip_y_axis',
  cs + 'y axis (15 breakpoints 0..40000 = the output speed equivalent, the y argument of the call; 0..5000 rpm in 0.125 rpm counts) - the "fuel" in the old name is wrong, it is a speed axis; type word[16] unchanged.')
G('0x00408bf0', 'torque_limit_table_ext_cal', 'engine_speed_limit_converter_slip_grid',
  cs + '15 rows (output speed) x 10 columns (fuel demand) = 150 words of engine speed x 8 (13920..17664 = 1740..2208 rpm; the dump output 13927 matches row 1 at the key-on speed); type word[150] unchanged.')
G('0x0040b610', 'torque_limit_base_input', 'transmission_output_speed_engine_equivalent',
  cs + 'the engine speed equivalent of the output shaft speed (plate of the function): transmission_output_speed_in_use x engine_load_scale_factor >> 8, or the vehicle speed form; the y input of the table and the base of both slip thresholds.')
G('0x0040b612', 'torque_fuel_accumulator', 'converter_slip_counter',
  cs + 'counts up by 1 per call while engine speed is above the second threshold and below converter_slip_counter_limit, down by 1 per divisor-th call otherwise; at the limit torque_converter_slip_warning_flag is set, at 0 it is cleared.')
G('0x0040b616', 'torque_limit_rpm_delta', 'converter_slip_speed_difference',
  cs + 'engine speed minus the output equivalent (0 when below it), stored at the end of every pass; the value tested against the difference threshold.')
G('0x003fb4e6', 'torque_limit_cycle_counter', 'converter_slip_counter_decrement_cycle_count',
  cs + 'counts the calls between two decrements of the slip counter. Time-shared window: xref_addr.py (name-based) 1 read / 2 writes, this function only; immediate scan of 0..0x7F5F for 0xb4e6 found 0 hits.')
G('0x003fb4e8', 'torque_limit_fuel_table_dims', 'engine_speed_limit_converter_slip_interpolation_state',
  cs + 'passed as the cached axis offsets state of the converter slip table lookup (cm848_dualAxisTableInterpolation first argument); xref_addr.py: 0 reads / 1 write (mpc555_initThermalProtectionFilters, the init). Time-shared window: immediate scan for 0xb4e8 / 0xb4ea: 0 hits. Label only.')

# ---------------------------------------------------------------- fault derate
G('0x0040a77c', 'torque_limit_fuel_upper_cap', 'fault_derate_fuel_limit',
  'Written by cm848_calculateFaultDerateFuelLimit (limit between the speed curve and protection_fuel_limit_cal_active) and reset to timing_limit_lower (5888 = none) by cm848_resetFaultDerateFuelLimit and cm848_resetGovernorStartupReadyFlag; read by cm848_calculateEffectiveFuelLimit and cm848_enforceFuelLimitProtection as a fuel quantity limit (xref_addr.py: 2 reads / 3 writes). Dump 5888.')
G('0x0040a792', 'protection_torque_derate_ramp', 'fault_derate_ramp_times_256',
  'Rate limited (DAT_0005c2ec = 13 per call) toward the highest channel derate level and capped at 256 (the existing CSV comment: rate-limited 0..256 ramp); it blends the fault derate curve with protection_fuel_limit_cal_active. xref_addr.py: 4 reads / 3 writes in cm848_calculateFaultDerateFuelLimit and cm848_resetFaultDerateFuelLimit. Dump 0.')
G('0x0040a77e', 'governor_startup_ready_flag', 'fault_derate_active_flag',
  'Writers: cm848_resetGovernorStartupReadyFlag (0 when the derate feature bit 0x10 of governor_feature_config_word is off), cm848_calculateFaultDerateFuelLimit (ramp above 0) and cm848_resetFaultDerateFuelLimit (0) - so it is the derate-active flag. Readers (xref_addr.py: 2): hpcr_calculateFuelTrimOutput (cpp 8867, part of the condition that sets governor_startup_state 3 and combustion_alpha_input; its own meaning is not read here) '
  'and governor_calculateIntegratorRpmOutput (cpp 61930: ORs governor_faultDerate_channel_bit into protection_mode_request_flags, i.e. requests the derate protection mode). The old "startup ready" name does not match the writers.')

# ---------------------------------------------------------------- pedal fault mode
pf = 'cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit (cpp 66389+): '
G('0x0040ae72', 'torque_limit_fuel_min_working', 'engine_speed_limit_pedal_fault_mode',
  pf + 'source 14 of cm848_selectEngineSpeedLimit (limiting_source_number 14); xref_addr.py: 1 read (the arbiter) / 4 writes (3 here, 1 in cm848_initializeEngineSpeedLimitDefaults). Engine speed x 8, not fuel.')
G('0x0040ae6e', 'aux_torque_fuel_demand_limit', 'pedal_fault_mode_fuel_demand_limit',
  pf + 'the upper limit of the pedal fault mode fuel demand ramp (DAT_0005c492 = 854 or DAT_0005c4a4 or DAT_0005c496 = 9); xref_addr.py: 1 read / 2 writes, this function only.')
G('0x0040ae6c', 'aux_torque_fuel_demand_ramp', 'pedal_fault_mode_fuel_demand_ramp',
  pf + 'the ramp that becomes governor_proportional_gain in mode 6; also set to fuel_demand_computed on mode entry by fuel_demand_periodSnapshot_save (xref_addr.py: 2 reads / 3 writes).')
G('0x003fcbe6', 'governor_fuel_demand_limit_prev', 'pedal_fault_mode_fuel_demand_limit_previous',
  pf + 'the slewed limit (falls by at most DAT_0005c49c per call); xref_addr.py (name-based): this function and fuel_demand_periodSnapshot_save only; time-shared window: no boot-ROM user listed, immediate scan of 0..0x7F5F for 0xcbe6: 0 hits.')
NG('0x0040ae70', 'pedal_fault_mode_target_speed_filtered', 'word',
   pf + 'xref_addr.py: 0 reads / 1 write, width word (sth of the low half of the exponentialMovingAverage of engine_rpm_state_t.target_rpm, filter state ema_filter_state_t_003fcbdc); working RAM outside the time-shared window; the stored value feeds nothing that was found (the term DAT_0005c490 x filtered speed is 0 in the dump).')
NG('0x003fcbe4', 'pedal_fault_mode_accelerator_off_idle_previous', 'word',
   pf + 'xref_addr.py: 1 read / 1 write, width word, this function only (stores fuel_demand_control_t.accelerator_off_idle at the end of every call and compares it with 1 on the next one). Time-shared window: no other user listed, immediate scan of 0..0x7F5F for 0xcbe4: 0 hits.')

# ---------------------------------------------------------------- driver demand
dd = 'cm848_calculateDriverDemandPercentTorque (cpp 20168+): '
G('0x0040ad8c', 'j1939_dm1_spn_b_word', 'driver_demand_percent_torque_times_256',
  dd + 'written here only and read by j1939GetEngineStateCode as (word >> 8) + 125 into j1939_eec1_driver_demand_torque_byte (PGN 61444, SPN 512); 100 percent = 25600. The old name says DM1 (the diagnostic message), which this is not; the neighbouring j1939_dm1_spn_a_word / j1939_dm1_spn_fmi_byte are the actual percent torque word and byte of the same message (note).')
G('0x003fa8a0', 'governor_pid_integral_prev', 'driver_demand_fuel_quantity',
  dd + 'the selected demand in fuel quantity counts (governor_fuel_demand_value, the effective fuel limit or the held previous value); xref_addr.py (name-based): 1 read / 1 write, this function only. Time-shared window: no boot-ROM user listed and immediate scan of 0..0x7F5F for 0xa8a0: 0 hits. Rename only.')
G('0x0040adaa', 'governor_pid_integral_cached', 'driver_demand_fuel_quantity_copy',
  dd + 'copy of driver_demand_fuel_quantity written every call and never read (xref_addr.py: 0 reads / 1 write).')

# ---------------------------------------------------------------- injection timing offset (0x1e870)
io = 'cm848_calculateInjectionTimingOffset (cpp 18940+): '
G('0x0040a2ee', 'governor_rpm_offset', 'injection_timing_offset_map_output',
  io + 'names what is computed: the blend of the two offset maps (or injection_timing_offset_cal) plus the increment, in timing counts (dump 171). Referenced by this function only; no live consumer found (see the function row).')
G('0x0040a2f0', 'governor_rpm_offset_cached', None,
  io + 'two writers: this function (the map output) and cm848_copyProtectionAccumulator (main_injection_timing, later in cm848_periodicTaskSet_auxiliaryControl); the only reader cm848_computeFuelRpmCompensatedOffset runs after the second writer, so what it reads is a copy of main_injection_timing (dump 162 = main_injection_timing). '
  'Candidate main_injection_timing_copy describes the live content but not the first writer, so left uncertain.', 'uncertain')
G('0x003fd806', 'governor_rpm_offset_increment', 'injection_timing_offset_increment_cal',
  io + 'EEPROM-backed (inside 0x3fd482-0x3feec1, 1 read / 0 writes, dump 0): added to the map output when governor_feature_config_word bit 0x4000 is set. Time-shared window: xref_addr.py lists no boot-ROM user; immediate scan of 0..0x7F5F for 0xd806: 0 hits.')
tb = io + 'map table copied ROM -> RAM (0x406xxx, not EEPROM so no _cal); read only by this function in the cpp (cm848_dualAxisTableInterpolation arguments); '
G('0x00406a5e', 'rpm_governor_offset_rpm_axis_a_cal', 'injection_timing_offset_map_a_x_axis',
  tb + 'x axis 5200..28000 = 650..3500 rpm (19 breakpoints after the length word); type word[20] unchanged. Medium confidence on the domain (maps flat 171, same as injection_timing_offset_cal).')
G('0x00406a86', 'rpm_governor_offset_fuel_axis_a_cal', 'injection_timing_offset_map_a_y_axis',
  tb + 'y axis 0..2061 = fuel_demand_computed counts (16 breakpoints); type word[17] unchanged.')
G('0x00406aa8', 'rpm_governor_offset_values_a_cal', 'injection_timing_offset_map_a_grid',
  tb + '16 x 19 grid, all 171 in the RAM dump; type word[304] unchanged.')
G('0x00406d08', 'rpm_governor_offset_rpm_axis_b_cal', 'injection_timing_offset_map_b_x_axis',
  tb + 'same axis as map a; type word[20] unchanged.')
G('0x00406d30', 'rpm_governor_offset_fuel_axis_b_cal', 'injection_timing_offset_map_b_y_axis',
  tb + 'same axis as map a; type word[17] unchanged.')
G('0x00406d52', 'rpm_governor_offset_values_b_cal', 'injection_timing_offset_map_b_grid',
  tb + '16 x 19 grid, all 171 in the RAM dump; type word[304] unchanged.')

# ---------------------------------------------------------------- fuel limit chain, cruise
G('0x0040afb0', 'governor_fuel_limit_source', 'fuel_pressure_fault_fuel_limit_working',
  'Written by cm848_applyFuelLimitsForFuelPressureFaults (4 reads / 5 writes: the P0193 / P0192 / fault 264 / P0251 / reaction / P0088 fuel limits, 0x1700 = none; its W6 plate calls the same value "the fuel limit"), by the startup init and read by cm848_calculateEffectiveFuelLimit and cm848_applyFuelPressureFaultFuelLimit (xref_addr.py: 6 reads / 6 writes). '
  'Parallel to fuel_pressure_fault_engine_speed_limit_working (0x40a300), which the same function sets for source 7.')
G('0x0040b6d6', 'cruise_torque_limit_scale', 'cruise_pid_rate_gain_scale',
  'Written by cm848_calculateCruisePidRateGainScale, read by governor_cruise_speedError_torqueAdj and protectionOutputActuatorControl as the factor after cruise_pid_rate_gain_working in the cruise PID speed error / rate terms (xref_addr.py: 2 reads / 1 write); dump 0.')

# ---------------------------------------------------------------- auxiliary interaction tables (kept uncertain)
au = ('Auxiliary pulse interaction table of cm848_calculateAuxiliaryInjectionPulseWidth (code role exact: quantity = ((scale lookup x correction lookup) >> 4) + auxiliary_injection_quantity while the main pulse is on). '
      'The lost campaign objection was found (see the note): axis placeholder, all-zero grids, unsigned read, not an exact mirror of the main twin. Kept uncertain. ')
G('0x0005f8ac', '', None, au + 'Correction x axis (x = main_to_auxiliary_injection_interval, 3.2 us counts, at least 187 when the pulse is kept): ROM 25 breakpoints 0,0,1,1,1,2,...,8,8,8,9 = a linear 0..9 ramp rounded, so every real input saturates the last breakpoint (fit test failed). Candidate: auxiliary_quantity_main_correction_x_axis (twin of main_quantity_pilot_correction_x_axis).', 'uncertain')
G('0x0005f8e0', '', None, au + 'Correction y axis (y = main_injection_pulse_width_before_minimum_check, ticks of 0.4 us): ROM 0, 1250, 3750, 6250, 8750, 10238 (fits). Candidate: auxiliary_quantity_main_correction_y_axis.', 'uncertain')
G('0x0005f8ee', '', None, au + 'Correction grid, 6 rows x 25 columns, read with flags 0 (z unsigned) where the main twin main_quantity_pilot_correction_grid is read with flags 4 (z signed); all 150 ROM words are 0 (the twin has 115 nonzero). Candidate: auxiliary_quantity_main_correction_grid.', 'uncertain')
G('0x0005fa1a', '', None, au + 'Scale x axis (x = auxiliary_injection_quantity): ROM 0, 736, 1472, 2208, 2944, 3680, 4048, 4416 = 0..300 mm3 in round steps (fits a quantity axis, but runs far past the 56 mm3 where the auxiliary on-time table stops). Candidate: auxiliary_quantity_main_correction_scale_x_axis.', 'uncertain')
G('0x0005fa2c', '', None, au + 'Scale y axis (y = fuel_pressure_sensor): ROM 0, 614, 1023, 1433, 1842, 2252, 2866, 3276 = 0..160 MPa (fits). Candidate: auxiliary_quantity_main_correction_scale_y_axis.', 'uncertain')
G('0x0005fa3e', '', None, au + 'Scale grid 8 x 8: all 64 ROM words are 0 (the main twin holds 16 / 12 / 8 / 4 / 3); read with flags 6 like the main scale. Candidate: auxiliary_quantity_main_correction_scale_grid.', 'uncertain')

# ---------------------------------------------------------------- injector debounce counters
dc = ('Injector diagnostic debounce counter of cm848_evaluateInjectorDiagnostics (cpp 47113+), passed as &DAT_003fb6xx to cm848_evaluateInjectorDiagnosticFault, which counts up while any bit of its class is set (stops above the limit) and down while none is. '
      'WIDTH FROM THE CALLEE DISASSEMBLY, NOT xref_addr.py: xref_addr.py reports 0 accesses (pointer-passed), so this departs from the wave-3 rule; cm848_evaluateInjectorDiagnosticFault 0x4aaac-0x4ac3c loads and stores the counter with lhz r12,0(r26) / sth r12,0(r26) (0x4aad0 / 0x4aae4 / 0x4ab00-0x4ab08 / 0x4ab3c): word. '
      'Time-shared window: immediate scan of the boot ROM 0..0x7F5F for the low address halves found 0 hits (misses split base + offset forms). ')
NG('0x003fb6fc', 'injector_diagnostic_bits_a_debounce_count', 'word', dc + 'Class a, limit injector_diagnostic_bits_a_debounce_limit (0x409a8c), fault table offset 2.')
NG('0x003fb6fe', 'injector_diagnostic_bits_c_debounce_count', 'word', dc + 'Class c, limit injector_diagnostic_bits_c_debounce_limit (0x409a90), fault table offset 4, heal blocked by cylinder_cutout_mask.')
NG('0x003fb700', 'injector_diagnostic_bits_b_debounce_count', 'word', dc + 'Class b, limit injector_diagnostic_bits_b_debounce_limit (0x409a8e), fault table offset 6, heal blocked by cylinder_cutout_mask.')
NG('0x003fb702', 'injector_diagnostic_bits_d_debounce_count', 'word', dc + 'Class d, limit injector_diagnostic_bits_d_debounce_limit (0x409a8a), fault table offset 8, heal blocked by cylinder_cutout_mask.')

# ---------------------------------------------------------------- struct field
SF('torque_limit_arb_t', 'source_priority', 'main_injection_timing_source_code',
   'Label only (the struct split stays a type-change note): xref_addr.py shows the first word 0x40a2f6 touched only by cm848_calculateMainInjectionTiming (2 reads / 18 writes: codes 5, 8, 18-22, 29, 30 ...), cm848_updateMainInjectionTimingByDeliveryMode (1r / 1w), '
   'cm848_initTimingFilterStates (0r / 1w) and cm848_calculatePilotInjectionTimingOffset (1r / 0w) - the winning source code of the main injection timing, nothing of the engine speed limit arbitration.')

# ---------------------------------------------------------------- notes
N('[W7 lead 1: struct type rename, exact names] torque_limit_arb_t -> engine_speed_limit_arbitration_t. CURRENT names: structure_definitions.csv header comment lines 238-240 ("# Torque Limit Arbitration - multi-source torque limit selection" / "# Used by fuel limit arbitration and protection systems" / "# Total size: 8 bytes (0x0040a2f6-0x0040a2fd)") and data rows 241-244 (struct_name torque_limit_arb_t, address 0x0040a2f6, fields source_priority / limiting_source_number / applied_speed_limit / lowest_source_speed_limit). '
  'global_variables.csv keeps the instance and its sub-rows as LITERAL names that do NOT follow a type rename: row 4417 "0x0040a2f6,torque_limit_arb_t_0040a2f6,torque_limit_arb_t,", row 4418 "0x0040a2f8,torque_limit_arb_t_0040a2f6.limiting_source_number,,", row 4419 "0x0040a2fa,torque_limit_arb_t_0040a2f6.applied_speed_limit,,", row 4420 "0x0040a2fc,torque_limit_arb_t_0040a2f6.lowest_source_speed_limit,,". '
  'VERIFIED (xref_addr.py): the first word 0x40a2f6 is the main injection timing source code (see the struct_field row), the arbiter proper is the 6 bytes 0x40a2f8-0x40a2fd (xref_addr.py: limiting_source_number 6 reads / 13 writes in 7 functions, applied_speed_limit 3 / 8, lowest_source_speed_limit 22 / 16).'
  'RECOMMENDED (split + rename): header "# Engine Speed Limit Arbitration - lowest wins selection of the engine speed limit" / "# Used by cm848_selectEngineSpeedLimit and its readers" / "# Total size: 6 bytes (0x0040a2f8-0x0040a2fd)"; rows "engine_speed_limit_arbitration_t,0x0040a2f8,limiting_source_number,word,2,Number of the engine speed limit source that wins the arbitration,,verified", '
  '"engine_speed_limit_arbitration_t,0x0040a2f8,applied_speed_limit,word,2,Engine speed limit applied by the governor (ramped limit or the ramp plus the droop term capped by the droop cap) in 0.125 rpm counts,,verified", '
  '"engine_speed_limit_arbitration_t,0x0040a2f8,lowest_source_speed_limit,word,2,Lowest engine speed limit of the sources in the current pass (0.125 rpm counts) and reset to the default at the end of cm848_selectEngineSpeedLimit,,verified" (the cells contain no commas because structure_definitions.csv is comma-split). '
  'global_variables.csv rows 4417-4420 become "0x0040a2f6,main_injection_timing_source_code,word,<comment: winning source code of the main injection timing written by cm848_calculateMainInjectionTiming>", "0x0040a2f8,engine_speed_limit_arbitration_t_0040a2f8,engine_speed_limit_arbitration_t,", "0x0040a2fa,engine_speed_limit_arbitration_t_0040a2f8.applied_speed_limit,,", "0x0040a2fc,engine_speed_limit_arbitration_t_0040a2f8.lowest_source_speed_limit,,". '
  'Without the split the instance would be engine_speed_limit_arbitration_t_0040a2f6 (rows 4417-4420 with the same suffixes) and an injection timing word would sit inside an engine speed limit struct. '
  'Prose to update: global_variables.csv rows 3113 / 3114 / 3115 ("torque_limit_arb_t.applied_speed_limit" -> "engine_speed_limit_arbitration_t.applied_speed_limit"), row 4873 ("torque_limit_arb_t.source_priority == 0x12" -> "main_injection_timing_source_code == 18"), function_renames.csv row 1387 (cm848_calculateMainInjectionTiming plate: "torque_limit_arb_t.source_priority" -> "main_injection_timing_source_code"). '
  'Generated or historical text to regenerate or leave: firmware_types.hpp lines 969 and 1307, firmware_globals.hpp line 3948, bank2_functions.cpp (13 hits), docs/memory-mappings/ram.txt line 66301, work/tasks/042-*.md, worklist_* batches. ')
N('[W7 convention] Plate comments and evidence of this file use the PROPOSED new names of globals and functions, so apply the function rows, the global rows and the plates together (as in waves 4-6). _cal rule applied by address: 0x3fd806 / 80c / 80e / 810 / 816, 0x3fdb84, 0x3fdd38 are inside 0x3fd482-0x3feec1 (new names there end in _cal); 0x406fe6 / e8 / ee, 0x407266 and 0x408baa-0x408d76 are outside (new names drop _cal). '
  'Time-shared window (0x3F9800-0x3FDB30) checks actually run: xref_addr.py (name-based) on 0x3fd806 / 80c / 80e / 810 / 816 / 3fdb84 / 3fa8a0 / 3fb4e6 / 3fb4e8 / 3fcbe4 / 3fcbe6 / all four of 3fb6fc-3fb702; my own immediate scan of the boot ROM 0..0x7F5F (a 16-bit immediate equal to the low address half; it misses split base + offset forms) on 0x3fb4e6 / e8 / ea, 0x3fb6fc-702, 0x3fb708-726, 0x3fa8a0, 0x3fcbe4 / e6, 0x3fd806 / 80c / 80e / 810 / 816, 0x3fdb84: 0 hits everywhere. No type change is proposed for any time-shared word; the new_global rows add types only for words that have no row.')
N('[W7] 0x1f40c (was cm848_processTorqueLimitTiming) is already cm848_runHighSpeedGovernorPid (wave 6): nothing to do.')
N('[W7 lead: auxiliary interaction tables 0x5f8ac / 0x5f8e0 / 0x5f8ee / 0x5fa1a / 0x5fa2c / 0x5fa3e] The campaign objection that two waves could not recover IS in the job files: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_09.jsonl (first pass, lookups L022 / L023) and result_retry.jsonl (second pass). '
  'Its content: (a) the correction x axis 0x5f8ac is a rounded 0..9 ramp against intervals of at least 187 counts (fit test failed, every real input saturates the last breakpoint); (b) all 214 grid words are 0; (c) the correction grid is read with interpolator flags 0 (z unsigned) where the main twin L065 is read with flags 4 (z signed) - '
  'cm848_dualAxisTableInterpolation flags are bit 0 = x compared signed, bit 1 = y compared signed, bit 2 = z values signed (read in the interpolator, cpp 56334+) - so the pairing with the main twin is not exact; (d) the scale x axis runs to 4416 (300 mm3) while the auxiliary on-time table L024 stops at 662 (56 mm3), so that axis is not calibrated for this input. '
  'My checks: the code roles of all six are exact (cpp 45059+), the ROM words are as listed in the rows, the main twins have real data (corr x 188..1375, scale grid 16 / 12 / 8 / 4 / 3, 115 nonzero correction words). Nothing new settles the objection, so the six rows stay uncertain. '
  'If the caller wants names anyway: the campaign own second-pass candidates are auxiliary_quantity_main_correction (L022) and auxiliary_quantity_main_correction_scale (L023), i.e. the TWIN family of main_quantity_pilot_correction_*: auxiliary_quantity_main_correction_{x_axis,y_axis,grid} for 0x5f8ac / 0x5f8e0 / 0x5f8ee and auxiliary_quantity_main_correction_scale_{x_axis,y_axis,grid} for 0x5fa1a / 0x5fa2c / 0x5fa3e (types word[26] / word[7] / word[150] / word[9] / word[9] / word[64] unchanged); '
  'the wave-4 candidates injection_quantity_auxiliary_main_correction_* use the injection_quantity_auxiliary_* prefix of the auxiliary quantity limit maps instead (first-pass candidate was post_quantity_main_correction*, from before the third event was known as the auxiliary one). The campaign skipped all-zero tables on purpose.')
N('[W7 lead: 0x5a48a sign] injection_timing_top_dead_center_offset (i16 -171) is already a row. Reading that settles the sign of use (3): timing counts are measured so that top dead center sits at 171 counts (20.04 degrees): the TDC-relative angle in counts is timing - 171. Use (1) cm848_j1939HandlePgn65504ProprietaryB: (main_injection_timing + const) x 120 >> 10 + 125 = the top-dead-center-relative angle (dump 162 - 171 = -9 counts = 1 degree after TDC); '
  'use (2) cm848_calculateAuxiliaryInjectionTiming: -(const + retard) = 171 - retard counts converts retard after TDC back to timing counts; use (3) cm848_calculateMainInjectionTiming delivery mode 3: demand + injection_timing_offset_cal + const = demand + (offset_cal - 171): offset_cal (EEPROM, 171 in the dump) is an absolute value whose default equals the TDC position, so the net trim is 0 - consistent with (1) and (2), no opposite sign. '
  'So the constant is minus the TDC position and the name can stay; a row comment saying "minus the top dead center position in timing counts (171)" would help. Plates that still cite DAT_0005a48a: function_renames.csv row 1387 (cm848_calculateMainInjectionTiming) and row 2133 (cm848_calculateAuxiliaryInjectionTiming, 0x5279d8). Reading, not proof; consistency check only.')
N('[W7 lead: torque_limit_error_integrator 0x40a306, by address] The dword is two words: 0x40a306 = the droop slope (cm848_selectEngineSpeedLimit zeroes it for source 10 and recomputes it with cm848_clampedDivisionWithBounds; the code reads it as _0_2_; dump 0), 0x40a308 = the ramped applied limit (init: engine_speed_limit_reference_default_cal, step engine_speed_limit_ramp_up_step; the code reads it as _2_2_; dump 25600). '
  'The wave-6 wording "high word = ramped, low word = slope" is inverted for big-endian (the lower address is the high half). The row 0x40a308 torque_limit_fuel_cal_input (no type, 0 accesses) sits on the second word and must go when the dword is split. Proposal (type change, no row): 0x40a306 word engine_speed_limit_droop_slope, 0x40a308 word engine_speed_limit_ramped (readers by xref_addr.py of the dword: cm848_selectEngineSpeedLimit 1r / 2w, faultTimerHandler, cm848_calculateEffectiveFuelLimit, cm848_processJ1939RxMessage, governor_calculateIntegratorRpmOutput, cm848_calculateEngineLoadPercentages).')
N('[W7 lead: debounce counters 0x3fb6fc-0x3fb702] a = 0x3fb6fc, c = 0x3fb6fe, b = 0x3fb700, d = 0x3fb702 (the call order a, c, b, d of cm848_evaluateInjectorDiagnostics). Four new_global rows are given with the width taken from the callee disassembly, not from xref_addr.py: this departs from the wave-3 rule (new_global width = xref width), flagged for the caller. No boot-ROM user found (immediate scan).')
N('[W7] Family leftovers found while reading, not renamed: torque_limit_init_state_0 .. _15 (0x3fb708-0x3fb726, word each) are the interpolation state words of the main injection timing lookups (cm848_initTimingFilterStates sets all 16 to 2; &torque_limit_init_state_0 and &torque_limit_init_state_8 are the state arguments in cm848_calculateMainInjectionTiming, cpp 47216 / 47236): rename the family to injection_timing_main_interpolation_state_<n> after a check of the other 14 users (boot scan of all 16 addresses found 0 hits). '
  'protection_fuel_limit_active (0x40afac, 13 users) is the running minimum fuel quantity limit and governor_fuel_mode_command (0x40afae) the source code of the limit that last lowered it (28 = rail pressure fault limit, 29 = fault derate limit, further codes in the other writers: 13 writes in 12 functions, two of them outside cm848_processProtectionLimits): the "protection" / "governor ... mode command" names mislead and want one wave of their own with the 12 writer functions (cm848_applyThermalFuelLimit, cm848_applySpeedControlProtectionLimit, cm848_applyProtectionLimit, cm848_protection_limits, protection_fuel_limit_check, cm848_limitFuelQuantityOnRailPressureShortfall, cm848_processSafetyConditionProtection ...). '
  'timing_limit_lower (0x5c306) holds 5888 = 0x1700, the fuel quantity maximum used as "no limit", and timing_limit_upper (0x5c30c) holds 0: both names are wrong, but only some of the 8 + 5 users were read (cm848_selectFuelDemandSource, cm848_updateProtectionStateMachine, cm848_calibrationGroup5_periodic, cm848_calculateFuelDemandWithTrim, cm848_processActiveFaultList, ...), so a rename needs that reading. '
  'cm848_resetGovernorStartupReadyFlag (0x507c44) is really the fault derate scheduler (feature bit 0x10 of governor_feature_config_word; 5 tasks round robin: eventCounter update, latch clear + channelIter, cm848_calculateFaultDerateFuelLimit, cm848_calculateFaultDerateEngineSpeedLimit + channelProcess, mainLoop update); a later wave could name it cm848_runFaultDerateScheduler. '
  'governor_cruise_speedError_torqueAdj (0x525134) returns the cruise speed error x rate gain term (/ 1000, x cruise_pid_rate_gain_scale >> 7, +-10000): candidate cm848_calculateCruiseWeightedSpeedError. '
  'governor_pid_t fields proportional_gain / integral_term (0x40af5a / 0x40af5c) are used as a fuel quantity and as a state code (compared with 1, 2, 4, 6, 7, 8, 37, 38) in cm848_processProtectionRampControl and cm848_calculateDriverDemandPercentTorque: wrong names, needs its own reading. '
  'j1939_dm1_spn_a_word / j1939_dm1_spn_fmi_byte (cm848_calculateLoadRateOfChange, then (word >> 8) + 125 into the byte) belong to the same PGN 61444 message as the actual engine percent torque (SPN 513): the "dm1" / "fmi" names are wrong (not verified further). '
  'cm848_protection_init (0x5031b4) initializes cruise_control_engaged_flag, cruise_speed_command, vehicle_speed, drivetrain_ratio, the source 2 speed limit and j1939_prop_status_tx_state: the name says nothing; not renamed.')
N('[W7] Not renamed in the torque_limit_* family (no reading yet): torque_limit_offset_calc 0x40a304 / _stored 0x40a328 / _enable_flag 0x40a31c / torque_limit_lookup_disable_flag 0x40a32a, torque_limit_override_source_cal 0x408d76, torque_limit_source_d_f_disable_cal 0x406fee (0 = sources 13 and 15 take the direct limit), torque_limit_source_working 0x40a2fe (write-only, the applied limit in the droop branch before the maximum with the ramp), torque_limit_load_snapshot 0x40a32e, torque_limit_source_code 0x40a318 (write-only copy of limiting_source_number), '
  'torque_limit_fuel_demand_snapshot 0x40a314, torque_limit_state_machine_snapshot 0x40a316, torque_limit_table_output 0x40a89b, torque_limit_working_reference 0x3fa8a4, torque_limit_enable_flag 0x3fb4f0, torque_limit_active_flag_b 0x3fb4f6, torque_limit_stable_flag 0x3fb4f8, torque_limit_entry_timer 0x3fb4fa and its _cal 0x408d26, torque_limit_active_flag 0x40b61e, torque_limit_setpoint_active 0x40b620, torque_limit_setpoint_working 0x40bd4e, torque_source_count 0x3fdd38 and torque_limit_multi_source_enable_cal 0x407266 (both read only by cm848_applySwitchSelectedEngineSpeedLimit).')
N('[W7] Stale-name check (script over the comment column of global_variables.csv and function_renames.csv, with a left word boundary): no comment cites a retired torque_* or cm848_*Torque* name any more; the single hit is the fragment "torque_limit_table_" in the comment of engine_speed_limit_converter_slip_table_output, which names the torque_limit_table_* family renamed in this file. The W6 housekeeping note (row 81) holds.')
N('[W7 skipped, informational] injection note 35 / 37 / 40 / 42 and rail notes 47 / 50-57 of the W6 file stay as W6 left them (no new reading); 0x3fd108 (time-shared window, type note only) and fuel_demand_integrator_b (type note: the dword is two words) are not touched here.')
N('[W7 stale text this file creates] Existing plates and comments cite names that these rows retire, so the apply step must refresh them: function_renames.csv rows 844 (cm848_selectEngineSpeedLimit: torque_limit_fuel_reference, torque_limit_fuel_min_working), 845 (cm848_initializeEngineSpeedLimitDefaults: torque_limit_fuel_min_working, torque_fuel_limit_active, torque_limit_fuel_minimum_snapshot) and 848 (cm848_calculateEffectiveFuelLimit: torque_limit_fuel_reference, and its wording "droop slope in the low word of torque_limit_error_integrator" is inverted by address - the slope is the word at 0x40a306, read as _0_2_), '
  'plus the plate of cm848_applyFuelLimitsForFuelPressureFaults (governor_fuel_limit_source) and the plates of the other functions whose words are renamed here. If the struct_field row for source_priority is applied without the struct split, global_variables.csv row 4873 and function_renames.csv row 1387 should read "torque_limit_arb_t.main_injection_timing_source_code".')
