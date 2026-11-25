# L3 describer notes (round 94)

## Every call of cm550_tableLookup2D (0x35088)
ROM scan (find_calls.py): 25 `jsr (0x35088).l` + 2 `movea.l #0x35088,a5` (0x1c674, 0x1de6a; then `jsr (a5)`);
no pc-relative jsr/bsr/lea/pea. Call sites -> record:
- 0xad22/0xad58 0x800010, 0xad42/0xad6a 0x800026 (cm550_updateDutyCycleMonitorLoadHistogram) - typed, skip
- 0xc1ca pea 0x8000aa; 0xc230 a3=0x8000c0 (cm550_fuelTimingTransitionStateMachine @0xc180)
- 0xc6f8 a3=0x8000da (cm550_rpmHistogramAndProtectionStatisticsAccumulator @0xc66a)
- 0x11fee pea 0x8001f8; 0x11ffc pea 0x8001d4 (cm550_coldStartFuelControlSlowCycle40Coordinator @0x11e5e)
- 0x12924 pea 0x800222; 0x12c74 pea 0x800238 (vp44_FUN_000127c2)
- 0x142f0 a2=0x80d372 (cm550_FUN_000142d4)
- 0x178ec/0x1795a a3=0x8005c2; 0x17918/0x17978 a2=0x8005d8 (cm550_governorFuelModeBlendCalculator @0x178b0)
- 0x1c6dc/0x1c720 a4=0x8006b8; 0x1c6fc/0x1c732 a3=0x8006ce (cm550_fuelDemandTableBlendCalculator @0x1c65e, jsr (a5))
- 0x1cbac a4=0x80d372; 0x1cbd2 a3=0x80d388 (cm550_calculateBlendedTableValue @0x1cb76)
- 0x1cd0a pea 0x800700; 0x1cd5e/0x1cdbc pea 0x8006ea (cm550_FUN_0001cc72)
- 0x1ded6/0x1deea/0x1df00 pea 0x80d372; 0x1df5c/0x1df6e/0x1df84 pea 0x80d388 (cm550_FUN_0001de58, jsr (a5))
- 0x25994 pea 0x80d372; 0x259c0 a5=0x80d388 (cm550_governorFuelPidController @0x2595a)
- 0x26a14 0x801a94, 0x26ade 0x801aaa - typed, skip
Records to name (15): 0x8000aa 0x8000c0 0x8000da 0x8001d4 0x8001f8 0x800222 0x800238 0x8005c2 0x8005d8 0x8006b8
0x8006ce 0x8006ea 0x800700 0x80d372 0x80d388

## Dump pointer values (dump_records.py) + e2m (e2m_block_addresses.py --address)
- 0x8000aa: 0x6010c AFFLLMXA (rpm) / 0x600ee AFFLLMYA (boost inHg) / 0x60138 AFFLLMZA (AFC fueling limit)
- 0x8000c0 and 0x800700: 0x6124a FLCDTPXA (coolant degF) / 0x6125e FLCDESYA (rpm) / 0x6126a FLCDICZA (cold temp incremental fuel)
- 0x8000da: 0x60384 ATESXA / 0x603b0 ATAAPRYA / 0x603ba ATFLLMZA (altitude derate fuel limit)
- 0x8001f8: 0x605ce CPCS02XA (rpm) / 0x605ea CPCS02BS (abs boost psia) / 0x605f2 CPCS02YA (compression ratio ^ polytropic)
- 0x8001d4: 0x60678 CPDSXA (rpm) / 0x60694 CPDSYA (fueling) / 0x606a4 CPDSZA (desired cylinder pressure psia)
- 0x800222: 0x80734c CBDSCSV / 0x807352 CBDSCFV / 0x807358 CBDSCT (cyl balancing stop compensation table) RAM
- 0x800238: 0x807338 CBDCSV / 0x80733e CBDC3FV / 0x807344 CBDCAT (cyl balancing compensation_3 adjustment) RAM
- 0x8005c2 and 0x8006b8: 0x60a2a 4DTA01XA / 0x60a52 4DTA01YA / 0x60a74 4DTA01ZA (steady state timing advance)
- 0x8005d8 and 0x8006ce: 0x60cd4 4DTA00XA / 0x60cfc 4DTA00YA / 0x60d1e 4DTA00ZA (transient timing advance)
- 0x80d372 and 0x8006ea (and 0x800010): 5DFL01 steady state 4D fueling 0x6086e/0x6089a/0x608a4
- 0x80d388 (and 0x800026): 5DFL00 transient 4D fueling 0x6094c/0x60978/0x60982
(pointer values are the dump's; checked: constant initializers write them, below)

## Initializers (all pointers are constants; the dump agrees)
- 0xc246 cm550_fuelTimingModeInit: 0x8000aa (AFFLLM x/y/z) + 0x8000c0 (FLCD x/y/z); offsets +0/+8 = 2
- 0xc714 cm550_fuelParameterPointerSetup: 0x8000da (ATESXA/ATAAPRYA/ATFLLMZA)
- 0x124d2 cm550_initLoadTrendingSystem: 1D 0x8001ea (CPCS01), 2D 0x8001f8 (CPCS02, x=rpm y=0x80021e), 1D 0x80020e (CPCS03), 2D 0x8001d4 (CPDS, x=rpm, y=final_fueling)
- 0x133fe vp44_FUN_000133fe: 2D 0x800222 (CBDSC*), 2D 0x800238 (CBDC*), 1D 0x80024e/25c/26a/278/286/294
- 0x17ef8 vp44_fuelLimitParameterPointerSetup: 1D 0x8005b4, 2D 0x8005c2 (4DTA01), 2D 0x8005d8 (4DTA00)
- 0x1c7a8 cm550_FUN_0001c7a8: 1D 0x8006aa, 2D 0x8006b8 (4DTA01), 2D 0x8006ce (4DTA00)
- 0xaf70 cm550_initializeDutyCycleMonitor: 0x800010 / 0x800026 (typed)
- 0x1cdf8 cm550_FUN_0001cdf8: 2D 0x8006ea (5DFL01, y_input fixed 400 at init), 2D 0x800700 (FLCD)
- 0x1ddb4 cm550_FUN_0001ddb4: 2D 0x80d372 (5DFL01), 2D 0x80d388 (5DFL00), 1D 0x80db20 / 0x80db2e

## Users / outputs (from disassembly)
- 0x8000aa: x=engine_rpm_primary y=boost filtered (0x80a320) -> air_fuel_control_fuel_limit (0x80a8f6, AFFL) when AFENMAN override bit clear
- 0x8000c0: x=coolant filtered (0x80a336) y=engine_rpm_primary -> ADDED to air_fuel_control_fuel_limit when AFCLAJEN (flags_32 bit 14) set and no coolant faults
- 0x8000da: x=engine_rpm_primary y=ambient air pressure filtered (0x80a3ba) -> altitude_derate_fuel_limit (0x80a922 ATFLLM) when ATAGEN set, running, no ambient faults
- 0x8001f8: x=engine_rpm_primary y=0x80021e (boost + ambient if gauge sensor) -> d3 = CR^n -> cm550_scaleByRatio(0x80021e, d3, 0x400) = calculated_cylinder_pressure_1500_3000
- 0x8001d4: x=engine_rpm_primary y=final_fueling -> d2 = desired cylinder pressure, compared with calculated
- 0x800222: x=current_engine_rpm_filtered (ESCMES) y=CBDFFL 0x8091e8 -> clamp 0..100 -> 0x8092e2 CBDATG active trim gain; <100 -> CBDSCF flag 0x80922e = 1
- 0x800238: same inputs -> result - 10000 -> 0x8092e0 CBDC3ADJ
- 0x8005c2 / 0x8005d8: x=crank_exit_speed (CKEXES) y=CKEXFL 0x807ef4 + CKEXFLAJ -> blended by ALPHA (0x80a8f8) -> four_d_timing_output_by_crank (CK4DTA 0x80d09c)
- 0x8006b8 / 0x8006ce: x=engine_rpm_primary y=final_fueling (or 1D 0x8006aa of it when 0x80d706=1) -> ALPHA blend -> timing_4DTBTA (0x80d344)
- 0x8006ea: x=engine_rpm_primary, y fixed 400 -> throttle_100_fueling_low_horsepower_curve (FST0MXFL) / with ESP: 0x80d370 (FSMTFLNP?)
- 0x800700: x=coolant, y=rpm -> added to the 100% throttle fuelings when 5DCLAJEN (flags_32 bit 15)
- 0x80d372 / 0x80d388: 5DFL01 / 5DFL00 blended by FLINML (0x80d340) in cm550_calculateBlendedTableValue, cm550_FUN_0001de58 (throttle, 0, 400), cm550_governorFuelPidController (LSG ref speed, 400); 0x80d372 alone in cm550_FUN_000142d4 (x=arg, y=400)

## CM848 counterparts (lookup caches; CM848 passes the tables separately)
- 0x8000aa <-> air_fuel_control_fuel_limit_cached_axis_offsets 0x3fa0c4 (cm848_calculateAirFuelControlFuelLimit)
- 0x8000da <-> fuel_limit_barometric_ambient_air_cached_axis_offsets 0x3fb9ca (altitude derate, different grids)
- 0x800222 <-> cylinder_balance_stop_compensation_cached_axis_offsets 0x3fb592 (hpcr_cbdCalculateCylinderTrims)
- 0x8006b8 / 0x8006ce <-> four_dimensional_injection_timing_map_a / _b_cached_axis_offsets 0x3fa878 / 0x3fa87c
- 0x80d372 / 0x80d388 <-> four_dimensional_fueling_steady_state / _transient_cached_axis_offsets 0x40a8a1 / 0x40a8a5
- 0x8006ea <-> four_dimensional_fueling_steady_state_cached_axis_offsets_2 0x3fa88c (cm848_calculateThrottle100Fuelings)
- 0x8005c2/0x8005d8: none (CM848 crank_four_dimensional_timing only seeded)
- 0x800238: none (CM848 cylinder_balance_component_3_adjustment is a calibration, no table)
- 0x8000c0 / 0x800700 <-> cold_delta_fuel_cached_axis_offsets 0x3fb35c (one lookup of CM848's own 8AA2 table)
- 0x8001f8 / 0x8001d4: none (no cylinder pressure rows in CM848)

## Checks
- record_refs.py: every absolute ref into each record is from its initializer or its lookup users (0x8000da
  +0x11/+0x12 hits in sendJ1939MultiFrame are `ori.l #0x00ec0000/#0x00eb0000` immediates, false positives)
- row_uses.py: every row name inside a record appears only in the initializer / users -> pure struct instances
- no 0x00035088 in the RAM / EEPROM dumps (no stored function pointer); 35 call sites total (25 jsr abs + 4 + 6 jsr (a5))
- proposed names: none exists in either firmware's global_variables.csv

## Duty cycle monitor axes (PROVEN)
- 0x807d1e DCMNESTB (e2m 111D T): byte count 18 -> 9 values 0,8000,10400,12800,15200,16800,18400,20000,22400
  (0.125 rpm: 0..2800 rpm) -> word[10] = 0x807d1e..0x807d31; 0x807d32 = next e2m record (111E)
- 0x807d32 DCMNLDTB (e2m 111E T): byte count 14 -> 7 values 0,1000,3000,5000,7000,9000,10000 (0.01 %) -> word[8]
  = 0x807d32..0x807d41; 0x807d42 = next record JCFCLD06 (10DF)
- readers: cm550_updateDutyCycleMonitorLoadHistogram only: movea.l #0x807d20,a2 at 0xae5c (values 1-8 by (a2)+),
  movea.l #0x807d34,a2 at 0xae90 (values 1-6), move.w (0x807d40).l at 0xadd2 (value 7 = load ratio when the full
  throttle fueling = no_load_fuel_quantity). Count words and rpm value 9 (0x807d30): no code reader (param ID table only)
- rows inside: 0x807d20 rpm_timer_interrupt_threshold_7d20, 0x807d2c rpm_source_selector_init,
  0x807d2e throttle_frictional_load_upper_threshold, 0x807d30 throttle_frictional_load_lower_threshold |
  0x807d32 DCMNLDTB (row AT the base, replaced), 0x807d34 intake_temp_frictional_load_threshold,
  0x807d36 rpm_fuel_limit_blend_offset, 0x807d38 frictional_load_fuel_init, 0x807d3a rpm_fuel_limit_threshold_max,
  0x807d3c frictional_load_state_init, 0x807d3e rpm_fuel_limit_state_max, 0x807d40 frictional_load_torque_init
- CM848 counterpart: ROM 0x5c2c0 (111D, byte count 18, 9 values -> word[10]) and 0x5c2d4 (111E, byte count 22,
  11 values -> word[12]); no rows; cm848_updateDutyCycleMonitorLoadHistogram reads 8 rpm / 10 load values and
  DAT_0005c2ea (11th load value 10000) the same way

## Side observations (functions, NOT proven twins; outside the batch)
- cm550_calculateBlendedTableValue ~ cm848_calculateMaximumFuelCurve (0x1f03c; CM550 also adds 5DFLAJ 0x803f3a)
- cm550_fuelDemandTableBlendCalculator ~ cm848_calculateFourDimensionalInjectionTiming (0x1e870; CM550 adds 1-D map 0x8006aa)
- cm550_FUN_0001cc72 ~ cm848_calculateThrottle100Fuelings (0x1f17c)
- cm550_FUN_0001ddb4 ~ cm848_initFaultSeverityTables (0x1ea94); cm550_FUN_0001c7a8 ~ cm848_initProtectionTableSizes
  (0x1ea6c); cm550_FUN_0001cdf8 ~ cm848_initFuelDemandTableDimensions (0x1f300)

## Names chosen
0x8000aa air_fuel_control_fuel_limit_lookup | 0x8000c0 air_fuel_control_cold_temperature_fuel_increment_lookup |
0x8000da altitude_derate_fuel_limit_lookup | 0x8001d4 desired_cylinder_pressure_lookup |
0x8001f8 compression_ratio_polytropic_power_lookup | 0x800222 cylinder_balance_stop_compensation_lookup |
0x800238 cylinder_balance_component_3_adjustment_lookup | 0x8005c2 crank_four_dimensional_timing_steady_state_lookup |
0x8005d8 crank_four_dimensional_timing_transient_lookup | 0x8006b8 four_dimensional_injection_timing_steady_state_lookup |
0x8006ce four_dimensional_injection_timing_transient_lookup | 0x8006ea four_dimensional_fueling_steady_state_throttle_100_lookup |
0x800700 throttle_100_cold_temperature_fuel_increment_lookup | 0x80d372 four_dimensional_fueling_steady_state_lookup |
0x80d388 four_dimensional_fueling_transient_lookup | 0x807d1e duty_cycle_monitor_engine_speed_axis word[10] |
0x807d32 duty_cycle_monitor_load_axis word[8]
