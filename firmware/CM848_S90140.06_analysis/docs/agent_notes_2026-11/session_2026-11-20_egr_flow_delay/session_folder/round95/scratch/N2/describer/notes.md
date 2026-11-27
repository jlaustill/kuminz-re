# N2 describer notes (round 95) - CM550 lookupTableInterpolation 0x34de0 records

## 0x34de0 lookupTableInterpolation - record layout (from the disassembly 0x34de0-0x34e98)
- arg (0xc,a7) -> a2 = record. Reads +0 w (movea.w (a2),a3: sign-extended byte offset), +2 l (x axis pointer),
  +6 w (input), +8 l (y pointer, adda.l (0x8,a2)), +12 w (move.w (0xc,a2),d0; beq -> interpolate).
- Writes back ONLY +0 (move.w a1,(a2) at 0x34e30 / 0x34e3e): the byte offset of the x point found.
- x table: word 0 = byte count of the points (= offset of the last point; a1 = x + x[0]); points at x+2 ..
  x+count, unsigned, ascending. Search starts at the cached offset, scans down (subq #2) or up (addq #2).
- input < first point: offset 2, input replaced by x[1] -> returns y[+2]. input >= last point: offset = count,
  returns y[+count]. exact hit -> y[+offset]. else +12 nonzero -> y[+offset] (step, no interpolation);
  +12 zero -> linear: y0 +/- ((|y1-y0|) * (in - x0)) / (x1 - x0) (mulu.w / divu.w, unsigned, both slopes).
- y table: read at y + offset (offset >= 2), so y+0 is never read: same layout as x (count word then values)
  in every dumped table (e.g. 0x8071a8 EPFLTB count 48 = 24 points like its axis 0x807176).
- 14 bytes, not 12: the decompiler's args[1].current_index is +12. Records are 14 bytes apart (0x80058e /
  0x80059c, 0x801a3e / 0x801a4c via pea (0xe,a2), 0x801c0e/1c/2a/38, 0x801e30/3e/4c/5a/68).
- Proposed table_lookup_1d_arguments_t: x_axis_offset word +0 (2), x_axis_pointer word* +2 (4), x_input word +6
  (2), y_values_pointer word* +8 (4), no_interpolation_flag word +12 (2) = 14 bytes.

## Call sites (44 abs refs = 42 jsr (0x34de0).l + 2 movea.l #0x34de0,a4 with 5 jsr (a4) each = 52 calls; no pc-relative)
- record -> caller(s) -> input -> output  [tables: e2m x / y]  (rows inside the 14 bytes)
- 0x80004a cm550_rpm_system_state_controller 0xb388: in current_engine_rpm_filtered (0x80ccf4) -> acceleration_noise_control_fuel_limit [10A6 NZFLLMXA 0x6009e / 10A7 NZFLLMYA 0x600b2 'ANC FUELING LIMIT TABLE (1 X 9 VALUES)'] init cm550_rpmParameterPointerSetup 0xb614. rows: 0x800052 timing_table_1_ptr
- 0x800058 cm550_FUN_0000b3d0 0xb4a2: in 0x80ccf4 -> acceleration_noise_control_timing_limit [10A8 NZTALMXA 0x600c6 / 10A9 NZTALMYA 0x600da 1x9] init cm550_dmaDescriptorSetup2 0xb63e. rows 0x800058 timing_table_2_base, 0x80005a timing_table_2_ptr, 0x800060 timing_table_3_ptr
- 0x80a792 table_lookup_1d_arguments_t[25] (ends 0x80a8ef, next row 0x80a8f0): mc68k_processAnalogSensorChannels 0xbbb6 (local pointer, stride 14: &local_8[1].x_axis_ptr), input adc_raw_value -> unfiltered_value; init cm550_initializeAnalogSensorChannels (offset 2, x, y for all 25). No rows inside.
- 0x800102 cm550_dzgTimingAndPressureControlStateMachine 0xc92e: in |(a2)-(a3)| -> (a5) [1326 ASTHPFXA 0x807acc / 1327 ASTHPFYA 0x807ad8, RAM, 5 points; CM848 speed_request_blend_weight_by_speed_difference_axis/_values] init cm550_FUN_0000c880. rows 0x800102 fuel_blend_table_3_ptr, 0x800106 fuel_blend_lookup_input_2, 0x800108 fuel_blend_table_4_base, 0x80010a fuel_blend_table_4_ptr, 0x80010e fuel_blend_table_3_limit
- 0x800118 cm550_dualTableLookupSum 0xd26a: in asg_reference_speed_working 0x80a990 [1321 ASNLFLXA 0x807230 / 1323 ASNLFLYA 0x807242, 8 points; CM848 all_speed_governor_friction_fuel_blend_128_axis/_values]; sum -> 0x8091de (ASNLFL). rows 0x80011a io_control_fuel_rpm_input, 0x80011c retarder_lookup_table_ptr, 0x800120 io_control_fuel_table_2_lookup_arg, 0x800122 retarder_lookup_table_pointer
- 0x800126 cm550_dualTableLookupSum 0xd260: in coolant_temperature_sensor_state.filtered_value (0x80a336) [1324 ASCLNLXA 0x807254 / 1325 ASCLNLYA 0x807268, 9 points; CM848 all_speed_governor_coolant_fuel_adjustment_axis/_values]. init cm550_interpolationTableSetup (both). rows 0x800126 io_control_fuel_table_param, 0x800128 io_control_fuel_calculator_ptr, 0x80012c throttle_validation_state, 0x800130 throttle_position_raw_value
- 0x800136 cm550_diagnosticMode10FuelController 0xd446 (asg_throttle_source_selector 0x80a9a2 == 0): in asg_reference_speed_working -> asg_selected_droop_slope_0_30 0x80a99a [116C ASALDPXA 0x60462 / 116D ASALDPYA 0x60472 ASG_Alt_Droop; gap 16 -> word[8]; CM848 all_speed_governor_droop_blend_0_*]. rows 0x800138 throttle_buffer_validation_value, 0x80013c throttle_buffer_decreasing_value, 0x800140 throttle_position_validation_buffer
- 0x800144 same function 0xd422 (selector == 1) [116E ASDPTBXA 0x60482 / 116F ASDPTBYA 0x60492 ASG_Droop; word[8]; CM848 droop_blend_128_*]. init cm550_fuelBlendTablePointerSetup (both). rows 0x800144 derate_fault_counter_1, 0x800146 derate_fault_counter_2, 0x800148 derate_fault_counter_3, 0x80014a derate_target_snapshot, 0x80014c derate_lower_limit, 0x80014e derate_upper_limit, 0x800150 current_derate_target
- 0x800184 cm550_ioControlBasedFuelCalculator 0x10074 (= CM848 cm848_calculateEngineRetarderTorque role): x JCBCRPXA 0x6052a, y = JC<n>CTQYA chosen by engine_brake_active_cylinder_count 1..6 (jump table 0x1002e -> 0x60534..0x60566), in engine_rpm_primary -> d3. rows 0x800184 anc_altitude_table_1_size, 0x800186 anc_duty_cycle_ptr, 0x80018a cold_start_rpm_snapshot_2, 0x80018c anc_min_active_time_ptr, 0x800190 anc_disable_duration_table_size
- 0x800192 same 0x1009c: y JC6CTQYA 0x60566, input = word at x_axis_pointer+8 (axis point 4) -> d2 = full scale torque; result 25600*d3/d2 capped 32000 -> 0x80aa14 (JCINRDTQ). init cm550_throttleTablePointerSetup 0x100da (both). rows 0x800192 anc_disable_duration_ptr, 0x800196 cold_start_rpm_snapshot_3, 0x800198 anc_altitude_table_1_base, 0x80019a anc_altitude_table_1_ptr, 0x80019e cold_start_sensor_sum_saved
- 0x8001ea cm550_coldStartFuelControlSlowCycle40Coordinator (= cylinder pressure maintenance) 0x11fe2: in engine_rpm_primary (0x11ed6) -> uVar4 multiplies the SOI offset [108B CPCS01XA 0x60596 / 108C CPCS01YA 0x605b2 'RATIO OF CYL. PRESS. TO COMPRESSION PRESS. PER DEGREE TA', word[14] by gap]. init cm550_initLoadTrendingSystem 0x124d2. rows 0x8001ea hour_meter_table_3_size, 0x8001ec hour_meter_table_3_ptr, 0x8001f0 engine_rpm_histogram_threshold_select, 0x8001f2 hour_meter_table_4_base, 0x8001f4 hour_meter_table_4_ptr
- 0x80020e same function 0x122c8: in engine_rpm_primary (0x11eca) -> ratio x (IMT measured - expected) = timing increment (clamp +-0xaa) [108D CPCS03XA 0x60640 / 108E CPCS03YA 0x6065c 'RATIO OF DEG. F TO DEG. TVC', word[14]]. rows 0x80020e manifold_temp_table_1_z_ptr, 0x800212 manifold_temp_table_2_type, 0x800214 manifold_temp_table_2_x_ptr, 0x800218 speed_based_parameter_lookup_result, 0x80021a manifold_temp_table_2_z_ptr
- 0x80024e / 0x80025c / 0x80026a vp44_FUN_000127c2 (cylinder balancing), in current_engine_rpm_filtered: CBDTT1 0x8072f4 (row rpm_breakpoint_table) + CBDTT2 0x807316 -> 0x809230; + CBDDCT 0x809e9e -> d3; + CBDI2DCT 0x809ebe -> d4. init vp44_FUN_000133fe. rows: 0x80025c: 0x800268 vp44_third_array_1; 0x80026a: 0x80026c vp44_third_array_2, 0x800270 vp44_third_array_3
  CBDDCT / CBDI2DCT are e2m T records, 16 words each, NO count word (reset loop 0x13422 writes 16 x 10000 at each); the writer 0x12b2e updates T[i], T[i+1] with i = segment index 0..13, the lookup reads y+2..y+32 = T[1..16] (one word shift; T[16] of CBDI2DCT = 0x809ede executive timing enable). Flag only.
- 0x80db20 friction fuel by engine speed (NLFCFLXA 0x611fa / NLFCFLYA 0x6120e, word[10] by gap; CM848 friction_fuel_by_engine_speed_axis/_values word[10] same Calterm records): cm550_FUN_00014348 (5x at lsg_breakpoint_speed / 0x807d50 / 0x807d52 / 0x807d54 / 0x807d4e -> 0x80bc82/86/88/8a/84 frictional load at the J1939 breakpoints), cm550_fuelDemandPercentageCalculator (0x807d52 -> 0x80bc88), selectEngineSpeedLimit (0x80d650), cm550_FUN_00026b3a (engine_rpm_primary; sum -> no_load_fuel_quantity 0x80db1c). init cm550_FUN_0001ddb4. rows 0x80db20 no_load_fueling_curve_descriptor, 0x80db26 no_load_fueling_curve_rpm_input
- 0x80db2e friction fuel correction by coolant temperature (ADCLFLBP 0x61222 / NLCLFLYA 0x61236, word[10]; CM848 friction_fuel_correction_by_coolant_temperature_axis/_values): cm550_multiSpeedParameterInterpolation (-> 0x80052c), selectEngineSpeedLimit, cm550_FUN_00026b3a; input coolant filtered. no rows inside.
- 0x80058e WPCQXA 0x60846 / WPDYTMYA 0x6085a (word[10]): coolant -> engine_warmup_protection_rifle_to_turbocharger_delay_time. 0x80059c WPESXA 0x607f2 / WPFLDQYA 0x6081c (word[21]): engine_rpm_primary -> engine_warmup_protection_fuel_limit. init cm550_initializeEngineWarmupProtection. no rows.
- 0x8005fe EPFLVSAI 0x807176 / EPFLTB 0x8071a8 (24 points, word[25]; CM848 fault_derate_fuel_limit_by_engine_speed_axis/_values): cm550_FUN_000183cc 5x at torque_curve_speed_at_breakpoint_1..5 -> torque_curve_fueling_at_* (min or copy) = CM848 cm848_applyFaultDerateToJ1939TorqueCurveFuelings (cache _2). init cm550_FUN_000185f0. row 0x800604 epf_fuel_limit_table_x_input
- 0x800632 same tables: cm550_FUN_00019702 at engine_rpm_primary -> fault_derate_fuel_limit (blend with throttle_100_fueling by severity) = CM848 cm848_calculateFaultDerateFuelLimit. init cm550_initShutdownLimitVariables. rows 0x800638 arbitrated_fuel_previous, 0x80063a governor_rpm_error_previous
- 0x8006aa DPFPTB 0x607d6 (x, MM3S) / DPTVOTB 0x607e4 (y, %FU), word[7] (double pulsing 'TVO/FPW mapping'; Calterm types the TVO table X - the code looks it up inversely): cm550_fuelDemandTableBlendCalculator, final_fueling -> fueling input of the 4D timing tables while 0x80d706 = 1. init cm550_FUN_0001c7a8 (with the 4D timing lookups). no rows.
- 0x80071e/2c/3a runHighSpeedGovernorPid |error| -> multiplier; HSDVCFXA 0x808068 / HSPPCFXA 0x8080a0 / HSITCFXA 0x8080d8 axes (word[14], no rows; CM848 high_speed_governor_*_gain_adjustment_error_axis). init initializeHighSpeedGovernorGainSet.
- 0x801a3e / 0x801a4c cm550_epsTimingCalculationSlowCycle40Coordinator engine_rpm_primary -> 0x80dabe low / 0x80dac0 very low oil pressure limit; EPO2VSAI 0x611d0 shared axis, EPO2LOTB 0x611de / EPO2VLTB 0x611ec (word[7]). init cm550_initLookupTablePointers1 0x25926. rows 0x801a3e: 0x801a42 retarder_mode1_threshold_table, 0x801a44 retarder_mode1_data_ptr, 0x801a48 retarder_mode1_rpm_input, 0x801a4a retarder_mode1_output_ptr; 0x801a4c: 0x801a4e retarder_mode2_threshold_table, 0x801a50 retarder_mode2_data_ptr, 0x801a54 retarder_mode2_rpm_input, 0x801a56 retarder_mode2_output_ptr
- 0x801c0e PTSPAX 0x808958 / PTGNTB 0x80896e (count 20, word[11]) closed_loop_rpm_snapshot -> <<9 -> _closed_loop_rpm_based_gain (0x20c..0x7ccc) = CM848 power_take_off_gain_adjustment_*; cm550_runPowerTakeOffGovernor + cm550_presetPowerTakeOffGovernorOnEngagement. 0x801c1c/2a/38 error+16000 -> 0x80dc1e/20/22 (derivative / integral / proportional; enables 0x804012/14/16). init initializePowerTakeOffGovernorFiltersAndGains. no rows in records.
- 0x801e30..0x801e68 j1939FormatMultiFrameResponse (= CM848 cm848_selectEngineRetarderStagePercent) stage 1..5 tables at engine_rpm_primary vs the scaled request -> 0x11/0x21/0x32/0x43/0x53/100. init cm550_FUN_0002faa4. no rows inside (0x801e2e retarder_torque_threshold_interpolated sits just before).
- 0x8036c6 WSIMAI 0x8071e0 / WSTATB 0x8071f6 (count 20, word[11]) IMT; 0x8036d4 WSCLAI 0x80720c (count 16, word[9]) / WSCLTATB 0x80721e coolant: vp44_liftPumpFuelDeliveryController (= the wet stack timing base: max of the two, state 1 / 13) sets offset 2 + pointers every pass. no rows inside.
- UNUSED records (initialized, never passed to 0x34de0; no other reference in ROM / RAM): 0x8005b4 (WSIMAI/WSTATB, by vp44_fuelLimitParameterPointerSetup with the crank 4D timing records 0x8005c2/0x8005d8), 0x800278 (CBDESBV 0x807360 / CBDESBT 0x807370), 0x800286 (CBDDFBV 0x807380 / CBDDFBT 0x80738e), 0x800294 (CBDFFBV 0x80739c / CBDFFBT 0x8073aa), all by vp44_FUN_000133fe.

## Function verdict
- 0x34de0 -> cm550_lookupTableInterpolation (COUNTERPART of CM848 lookupTableInterpolation 0x55ef4, not a twin): same table
  format (byte count word + points; values read at the same byte offset), cached offset written back, end clamps,
  step option. Different code: CM848 takes 5 register args (cached offset ptr, input, x, y, flags: bit0 signed x /
  bit1 signed y / bit3 step), tests x[1] then x[last] before the cache, skips duplicate first points, one signed
  formula; CM550 takes one 14-byte record, unsigned only, compares with the cached point first, two unsigned
  mulu/divu branches (rising / falling), step word at +12. Return word (callers mask andi.l #0xffff).
- 52 calls = 42 jsr (0x34de0).l + movea.l #0x34de0,a4 at 0x14352 (cm550_FUN_00014348) and 0x183da
  (cm550_FUN_000183cc) with 5 jsr (a4) each; no pc-relative caller. Decompiler 53 lines = 52 calls + definition.
- +12 never written for any record (no abs ref; all 0 in the dumps): every lookup in this ROM interpolates.

## Names chosen (all checked unique vs frozen CM550 globals / functions: scratch proposed_names.txt)
- records: see proposed_names.txt lines 1-42; tables lines 43-131.
- CM848 shared Calterm table names reused: friction_fuel_by_engine_speed_*, friction_fuel_correction_by_coolant_temperature_*,
  fault_derate_fuel_limit_by_engine_speed_*, all_speed_governor_coolant_fuel_adjustment_*, high_speed_governor_*_gain_adjustment_error_axis,
  power_take_off_gain_adjustment_*, engine_retarder_torque_engine_speed_axis / _stage_<n>_values, *_linearization_axis.
- Not reused (CM848 blends, CM550 selects / no blend): CM848 all_speed_governor_droop_blend_0/128 (CM550 ASDPFG flag selects
  ASG_Alt_Droop vs ASG_Droop) and all_speed_governor_friction_fuel_blend_128 (CM550 has one table); CM848
  speed_request_blend_weight_by_speed_difference (CM550 uses the Calterm ASG throttle prefilter coefficient name).

## Leads (outside this batch; caller roles seen while reading)
- 0xff6c cm550_ioControlBasedFuelCalculator = engine retarder torque (CM848 cm848_calculateEngineRetarderTorque role).
- 0x2f632 j1939FormatMultiFrameResponse = engine retarder stage percent selection (CM848 cm848_selectEngineRetarderStagePercent role).
- 0x34cc4 vp44_liftPumpFuelDeliveryController = wet stack timing base (max of IMT / coolant tables; state 1 / 13).
- 0x11e5e cm550_coldStartFuelControlSlowCycle40Coordinator = cylinder pressure maintenance timing.
- 0xb2aa cm550_rpm_system_state_controller / 0xb3d0 cm550_FUN_0000b3d0 = acceleration noise control fuel / timing limit.
- 0xd23c cm550_dualTableLookupSum = ASG no load fuel ASNLFL 0x8091de (row rpm_control_override_flag is that record).
- 0xd3e6 cm550_diagnosticMode10FuelController = ASG droop selection by ASDPFG (0x80a9a2) -> ASSLDP 0x80a99a.
- 0x183cc = J1939 torque curve fault derate fuelings; 0x19702 = fault derate fuel limit (CM848 cm848_calculateFaultDerateFuelLimit role).
- 0x178b0 cm550_governorFuelModeBlendCalculator = crank exit timing (uses wet_stack_timing_base_value + crank 4D lookups).
