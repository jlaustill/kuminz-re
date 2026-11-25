# L3 investigator notes (round 94)

## Calls of cm550_tableLookup2D (0x35088): 27 absolute references in the ROM (abs_refs.py 0x35088)
25 are jsr (0x35088).l, 2 are movea.l #0x35088,a5 (0x1c674 in cm550_fuelDemandTableBlendCalculator, 0x1de6a in cm550_FUN_0001de58) then jsr (a5).
Skip (typed): 0xad24/0xad5a 0x800010, 0xad44/0xad6c 0x800026, 0x26a16 0x801a94, 0x26ae0 0x801aaa.

## Records (found so far)
- 0x8000aa: cm550_fuelTimingTransitionStateMachine 0xc1c4 pea 0x8000aa; x input 0x8000b0 <- engine_rpm_primary 0x80ccf6 (0xc1b0), y input 0x8000b8 <- 0x80a320 boost filtered (0xc1ba); result -> 0x80a8f6 air_fuel_control_fuel_limit. Pointers set by cm550_fuelTimingModeInit 0xc246: x 0x6010c (104E AFFLLMXA engine speed axis used by AFC), y 0x600ee (104D AFFLLMYA boost pressure axis), z 0x60138 (104F AFFLLMZA AFC look-up table defining fueling limit as a function of boost..). Gate: algorithm_enable_flags_12_cal bit 8 (0x803cac & 8) override -> 0x807a5a.
- 0x8000c0: same function, a3 = 0x8000c0 (0xc18a); x input 0x8000c6 <- 0x80a336 coolant filtered (0xc21e), y input 0x8000ce <- 0x80ccf6 engine rpm (0xc226); result added to air_fuel_control_fuel_limit (0xc23e add.w d2,(a5)). Pointers (init 0xc278..): x 0x6124a (81EE FLCDTPXA coolant temp axis for cold temp fuel increment), y 0x6125e (81EF FLCDESYA speed axis), z 0x6126a (81F0 FLCDICZA COLD TEMP INCREMENTAL FUEL TABLE). Gate 0x803cd4 & 0x4000 = algorithm_enable_flags_32_cal.air_fuel_control_coolant_temperature_adjustment_enable.
- 0x8000da: cm550_rpmHistogramAndProtectionStatisticsAccumulator 0xc674 a3 = 0x8000da; x input <- (a4)=0x80ccf6 engine rpm (0xc6ea), y input <- 0x80a3ba ambient air pressure filtered (0xc6ee); result -> (a2)=0x80a922 altitude_derate_fuel_limit. Init cm550_fuelParameterPointerSetup 0xc714: x 0x60384 (10A1 ATESXA engine rpm axis for altitude derate), y 0x603b0 (10A2 ATAAPRYA ambient air pressure axis), z 0x603ba (10A3 ATFLLMZA table of fuel limit values used by altitude derate).
- 0x8001d4: cm550_coldStartFuelControlSlowCycle40Coordinator 0x11ff6 pea; x input 0x8001da <- engine_rpm_primary, y input 0x8001e2 <- final_fueling (0x80d32e; also preset by init 0x12572); result d2 = desired cylinder pressure (compared with calculated_cylinder_pressure). Init cm550_initLoadTrendingSystem 0x124d2: x 0x60678 (1088 CPDSXA engine speed axis for desired cylinder pressure table), y 0x60694 (1089 CPDSYA fueling axis), z 0x606a4 (108A CPDSZA desired cylinder pressure table PSIA). Gate algorithm_enable_flags_3_cal.cylinder_pressure_maintenance_enable.
- 0x8001f8: same function 0x11fe8 pea; x input 0x8001fe <- engine rpm (0x11ed0 / init 0x12510), y input 0x800206 <- 0x80021e absolute intake manifold pressure (boost + ambient, 0x11fd0); result d3 -> scaleByRatio(manifold pressure, d3, 0x400) = calculated cylinder pressure. Init: x 0x605ce (11D0 CPCS02XA), y 0x605ea (11D1 CPCS02BS abs boost axis), z 0x605f2 (11D2 CPCS02YA compression ratio raised to power of a polytropic exponent).
- 0x800222: vp44_FUN_000127c2 0x1291e pea; x 0x800228 <- current_engine_rpm_filtered 0x80ccf4, y 0x800230 <- 0x8091e8; result clamped to 100 -> cyl_balance_gain_percent. Dump: x 0x80734c (822B CBDSCSV cylinder balancing stop compensation speed vector), y 0x807352 (822C CBDSCFV fueling vector), z 0x807358 (822D CBDSCT cylinder balancing stop compensation table).
- 0x800238: same function 0x12c6e pea; x 0x80023e <- 0x80ccf4, y 0x800246 <- 0x8091e8; result + 0xd8f0 (-10000) -> 0x8092e0. Dump: x 0x807338 (8228 CBDCSV comp_3 speed vector), y 0x80733e (8229 CBDC3FV fueling vector), z 0x807344 (822A CBDCAT cylinder balancing component_3 adjustment table -10000..10000).
- 0x80d372 / 0x80d388: 4D fueling steady state (1055/1054/1056 5DFL01) / transient (1058/1057/1059 5DFL00). Init cm550_FUN_0001ddb4 0x1ddb4. Users: cm550_FUN_000142d4 (y=400), cm550_calculateBlendedTableValue (y=throttle arg), cm550_FUN_0001de58 (y = throttle, 0, 400), cm550_governorFuelPidController 0x2597c (x 0x80daee, y=400). Blend by timing_alpha_blend_factor 0x80d340 (0x4000 = steady only, 0 = transient only). CM848 names the tables four_dimensional_fueling_steady_state_* / _transient_*.
- 0x8005c2 / 0x8005d8: 4D timing advance steady state (103D/103C/103E 4DTA01) / transient (1040/103F/1041 4DTA00); init vp44_fuelLimitParameterPointerSetup 0x17ef8; user cm550_governorFuelModeBlendCalculator 0x178b0: x = crank_exit_speed 0x80d0ac, y = 0x807ef4 + crank_exit_fuel_adjustment 0x80d0b6, blended by alpha_blend_factor 0x80a8f8 -> four_d_timing_output_by_crank_0_120 0x80d09c (CK4DTA). No rows inside.
- 0x8006b8 / 0x8006ce: the same two 4D timing tables, init cm550_FUN_0001c7a8 0x1c7a8; user cm550_fuelDemandTableBlendCalculator: x = engine_rpm_primary, y = final_fueling (or 1D-adjusted 0x8006aa lookup), blended by alpha_blend_factor -> timing_4DTBTA 0x80d344. No rows inside.
- 0x8006ea: steady state 4D fueling table (5DFL01) with y input fixed 400 (init cm550_FUN_0001cdf8 0x1ce14; no other write of 0x8006f8); x 0x8006f0 <- engine_rpm_primary; result -> throttle_100_fueling_low_horsepower_curve (FST0MXFL) / max_fueling_without_programmable_power_for_esp (ESP on). No rows inside.
- 0x800700: cold temperature incremental fuel table (81EE/81EF/81F0 FLCD), init 0x1ce30; user cm550_FUN_0001cc72: x 0x800706 <- coolant filtered (0x80a336), y 0x80070e <- engine rpm; gate algorithm_enable_flags_32_cal.full_fueling_coolant_temperature_adjustment_enable; result sVar1 added to throttle_100_fueling, low hp curve and full_fueling_value_at_hsg. No rows inside.

## Reference check (record_refs.py): every absolute reference into each record is the lookup call (pea / movea.l), its x / y input stores (+6 / +0xe) and the initializer's stores - nothing else touches those bytes (sendJ1939MultiFrame hits at 0x227b8.. are ori.l immediates 0x8000ec0000 / 0x8000eb0000, not addresses).
- 0x8000aa refs: 0xc1b0 (+6), 0xc1ba (+0xe), 0xc1c4 pea, init 0xc24c / 0xc25a
- 0x8000c0 refs: 0xc18a movea a3 (then (0x6,a3) 0xc21e, (0xe,a3) 0xc226), init 0xc246 / 0xc280
- 0x8000da refs: 0xc674 a3 ((0x6,a3) 0xc6ea, (0xe,a3) 0xc6ee), init 0xc714 / 0xc71a
- 0x8001d4: 0x11edc (+6), 0x11ee2 (+0xe), 0x11ff6 pea, init 0x124d6 a2 / 0x1256a
- 0x8001f8: 0x11ed0 (+6), 0x11fd0 (+0xe), 0x11fe8 pea, init 0x124dc a3 / 0x1251c
- 0x800222: 0x1290a (+6), 0x12914 (+0xe), 0x1291e pea, init vp44_FUN_000133fe 0x1348e/0x13496/0x134a0/0x134a8/0x134b2
- 0x800238: 0x12c5a (+6), 0x12c64 (+0xe), 0x12c6e pea, init 0x134bc/0x134c4/0x134ce/0x134d6/0x134e0
- 0x80d372: 0x142dc a2, 0x1cb92 a4, 0x1debe (+6), 0x1dec8 movea #0x80d380 (+0xe), 3 pea 0x1ded0/0x1dee4/0x1defa, 0x2597c (+6 <- lsg ref speed 0x80daee), 0x25986 (+0xe <- 400), 0x2598e pea; init 0x1ddbe/0x1ddd8
- 0x80d388: 0x1cb8c a3, 0x1df44 (+6), 0x1df4e movea #0x80d396, 3 pea 0x1df56.., 0x25972 a5; init 0x1ddb8/0x1ddfe
- 0x8005c2: 0x178ba a3; init 0x17f00 / 0x17f2c. 0x8005d8: 0x178b4 a2; init 0x17efa / 0x17f52
- 0x8006b8: 0x1c66e a4; init 0x1c7b0 / 0x1c7dc. 0x8006ce: 0x1c668 a3; init 0x1c7aa / 0x1c802
- 0x8006ea: 0x1cd52 / 0x1cdb0 (+6), pea 0x1cd58 / 0x1cdb6; init 0x1cdf8 / 0x1ce0c (y input 400 at 0x1ce14 is the only write of +0xe)
- 0x800700: 0x1ccf4 (+6), 0x1ccfe (+0xe), pea 0x1cd04; init 0x1cdfe / 0x1ce38

## No-visible-caller records (leads only): RAM blocks with the exact record shape, no reference anywhere in the dumped ROM (users / initializers are in the undumped 0x40000+ code):
- 0x8036e4: FLFLTBZA 8014 'table for converting fuel units to mg/stroke' over FLFLESXA 8012 speed / FLFLFLYA 8013 fuel (RAM tables 0x8074d6 / 0x8074f6 / 0x807516); row inside 0x8036ea diagnostic_mode_7_enable_flag
- 0x8036fe: FLTATBZA 8017 'line delay timing offset table' over FLTAESXA 8015 / FLTAFUYA 8016 (0x8076d8 / 0x8076f2 / 0x80770c); rows inside 0x803706 oil_pressure_rpm_target_low, 0x80370a oil_pressure_rpm_target_high
- 0x803896: 5DFL01 steady state 4D fueling (y input 400); 0x8038ac: x axis 5DFL01XA with 5DFL00YA / 5DFL00ZA transient (mixed axes! x pointer 0x6086e = steady-state speed axis); 0x8039ae: IHPHTMZA 81B2 IAH postheat time over IHPHTMXA / IHPHTMYA (0x80789a / 0x8078aa / 0x8078b4)

## Duty cycle monitor axes (PROVEN, the lead's sizes hold)
- 0x807d1e e2m 111D +0 DCMNESTB (T record, RPM 0.125): dump byte count 18 then 9 speeds 0 / 8000 / 10400 / 12800 / 15200 / 16800 / 18400 / 20000 / 22400 -> word[10] (0x807d1e-0x807d31; 0x807d32 = 111E +0 next). Reader: cm550_updateDutyCycleMonitorLoadHistogram movea.l #0x807d20,a2 at 0xae5c, loop d2 1..8 (cmpi.b #9 at 0xae82): compares the first 8 values. No row at 0x807d1e; rows inside: 0x807d20 rpm_timer_interrupt_threshold_7d20, 0x807d2c rpm_source_selector_init, 0x807d2e throttle_frictional_load_upper_threshold, 0x807d30 throttle_frictional_load_lower_threshold.
- 0x807d32 e2m 111E +0 DCMNLDTB (T record, PERC 0.01): byte count 14 then 7 loads 0 / 1000 / 3000 / 5000 / 7000 / 9000 / 10000 -> word[8] (0x807d32-0x807d41; 0x807d42 = 10DF +0 JCFCLD06). Readers: movea.l #0x807d34,a2 at 0xae90, loop 1..6 (cmpi.b #7 at 0xaeb6); move.w (0x807d40).l at 0xadd2 (the 7th value 10000 = 100 percent: the load ratio when the 100 percent throttle fueling equals no_load_fuel_quantity). Row at 0x807d32 DCMNLDTB (rename); rows inside: 0x807d34 intake_temp_frictional_load_threshold, 0x807d36 rpm_fuel_limit_blend_offset, 0x807d38 frictional_load_fuel_init, 0x807d3a rpm_fuel_limit_threshold_max, 0x807d3c frictional_load_state_init, 0x807d3e rpm_fuel_limit_state_max, 0x807d40 frictional_load_torque_init.
- No other ROM reference (record_refs: 0x35c84 / 0x35c8c are parameter_id_table entries).
- CM848 same records: DC_Mon_RPM_Axis 111D -> ROM 0x5c2c0 (count 18, 9 speeds 0..28800) word[10]; DC_Mon_Load_Axis 111E -> ROM 0x5c2d4 (count 22, 11 loads 0..10000) word[12]; no rows; read by cm848_updateDutyCycleMonitorLoadHistogram (*(ushort *)(i*2 + 0x5c2c0) i 1..8, *(ushort *)(i*2 + 0x5c2d4) i 1..10, DAT_0005c2ea = the 11th load point).

## Cylinder balancing RAM tables (extra, proven: e2m 8228-822D, dump counts 4 -> 2 points, 2x2 grids; only refs = the record init 0x134c4-0x134e0 / 0x13496-0x134b2)
- 0x807338 CBDCSV word[3] (4, 3200, 15200); 0x80733e CBDC3FV word[3] (4, 0, 7009); 0x807344 CBDCAT word[4] (10000 x4); 0x80734c CBDSCSV word[3] (4, 7600, 16000; row vp44_state_debounce_threshold + inside 0x80734e vp44_state_processing_timeout_reload / 0x807350 vp44_state2_transition_param); 0x807352 CBDSCFV word[3] (4, 421, 1122); 0x807358 CBDSCT word[4] (100, 0, 0, 0). Row 0x80734a sensor_fault_rpm_selector_param lies inside CBDCAT.

## Leads
- 44 jsr/refs of lookupTableInterpolation (0x34de0, 1D, table_interp_args_t 12 bytes) - none typed (e.g. 0x8001ea CPCS01, 0x80020e CPCS03, 0x8006aa DPFPTB/DPTVOTB, 0x8005b4 WSIMAI/WSTATB, 0x80db20 / 0x80db2e no load fuel).
- function_definitions.csv 0x142d4 param comment names fuel_table_primary_descriptor (text update after the rename).
- cm550_governorFuelModeBlendCalculator (0x178b0) computes the crank routine's 4D timing (CK4DTA) and crank_exit_advance - its name is wrong (lead for a function batch).

## Proposed names (all unique in the frozen CSVs; type table_lookup_2d_arguments_t)
0x8000aa air_fuel_control_fuel_limit_lookup (was target_rpm_rate_limiter_reserved_aa)
0x8000c0 air_fuel_control_cold_temperature_fuel_increment_lookup (was diagnostic_table_pointer_1)
0x8000da altitude_derate_fuel_limit_lookup (was diagnostic_data_table_1_ptr)
0x8001d4 desired_cylinder_pressure_lookup (was engine_runtime_histogram_interpolation_b)
0x8001f8 compression_ratio_raised_to_polytropic_exponent_lookup (was hour_meter_table_3_limit)
0x800222 cylinder_balance_stop_compensation_lookup (no row)
0x800238 cylinder_balance_component_3_adjustment_lookup (was vp44_comm_bit1_debounce_timer)
0x80d372 four_dimensional_fueling_steady_state_lookup (was fuel_table_primary_descriptor)
0x80d388 four_dimensional_fueling_transient_lookup (was fuel_table_secondary_descriptor)
0x8005c2 crank_four_dimensional_timing_steady_state_lookup (no row)
0x8005d8 crank_four_dimensional_timing_transient_lookup (no row)
0x8006b8 four_dimensional_injection_timing_steady_state_lookup (no row)
0x8006ce four_dimensional_injection_timing_transient_lookup (no row)
0x8006ea throttle_100_fueling_low_horsepower_curve_lookup (no row)
0x800700 full_fueling_cold_temperature_fuel_increment_lookup (no row)
Axes: CM550 0x807d1e duty_cycle_monitor_engine_speed_axis word[10]; 0x807d32 duty_cycle_monitor_load_axis word[8] (was DCMNLDTB); CM848 0x5c2c0 word[10] / 0x5c2d4 word[12] same names.
Cylinder balancing tables (CM550): 0x807338 / 0x80733e / 0x807344 cylinder_balance_component_3_adjustment_x_axis / _y_axis / _grid (word[3] / word[3] / word[4]); 0x80734c / 0x807352 / 0x807358 cylinder_balance_stop_compensation_x_axis / _y_axis / _grid (CM848 names, same sizes).
