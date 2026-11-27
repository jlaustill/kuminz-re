# N1 describer notes (round 95)

Helper: e2mrec.py <block hex> <offset hex> [mask hex] | --name <MNEMONIC>  (raw CM550 e2m records with S-record masks)

## 0x30498 cm550_FUN_00030498
- asm 0x30498-0x304f2: a0 = 0x80bcf6 (output image array, e2m 000E +28..); tests (1,a0) bit 0 = 0x80bcf7 bit 0
  (e2m 000E +29 mask 01: EBDR1 'output control of the engine brake solenoid driver 1' / DREBDR) then (3,a0) bit 6
  = 0x80bcf9 bit 6 FIVE times. In cm550_ioControlBasedFuelCalculator 0xff6c the same 6 tests add the per-driver
  cylinder counts 0x808200 (13D8 +2 JCDR1NCY 'cyl brakes driven by EB driver 1') .. 0x80820a (JCDR6NCY) into
  0x80da9c (13D9 +0 EBONSM engine brake cylinders on) -> the five 0x80bcf9 bit 6 tests are engine brake drivers 2-6
  (all built onto one output bit in this ROM).
- any set -> addq.l #1 to 0x80615e (1216 +38 TIT3EBTM 'engine operating time with the engine brakes on since last
  trip reset', 2.77777E-5 h = 0.1 s/count) and 0x806176 (1216 +50 TIT2EBTM 'total non-resetable time ... engine brake').
- only caller: trip information update 0x306ca (every 100 ms, phase 19 task set), in every operating mode except 0.
- CM848: cm848_updateTripAndLifetimeCounters 0x523148 has no engine brake time (CM848 e2m has no *EBTM record) -> none.
- name idea: cm550_accumulateEngineBrakeOnTime (trip + lifetime).

## 0x306ca cm550_FUN_000306ca  (trip information update)
- caller cm550_runEvery20FramesTaskSetPhase19 (every 20 frames = 100 ms). Gate algorithm_enable_flags_3_cal.trip_information_enable.
- TIRF (0x80de66, 1215 +14 'flag used by tools to clear trip parameters') == 1: clear it, 0x80de50 = 1, zero 25 longs
  at 0x8060c2, every trip remainder / counter, overflow flags, TIT3ISTM/PTTM/EBTM/TM, TIT3EZTM, TIAVLD, ..., TIMXES, TIGAT3.
- operating mode TIEGST (fuel_statistics_operating_mode): 0 rpm 0; 2 PTO governor active; 1 idle (road speed 0 with
  VSSVF, or final fueling state LOW_SPEED_GOVERNOR without); 3 drive.
- mode != 0: sample counters TIT3TM (0x806162), TITMT2 (0x804fc0 = TIT2TMOF offset + count); instantaneous fuel
  rate TIFU by fuel_statistics_mode_selector; J1939 / J1587 formatted rates; lifetime + trip fuel (TIDCFU->TIT2FU,
  TID2FU->TIT3FU) then per-mode fuel/time (3 drive fuel, 1 cm550_runTimeCountersUpdate idle, 2 ..Alt PTO), then
  0x30498 engine brake time, then TIT3EZTM/TIT2EZTM while can_transmit_buffer_ptr != 0; always then
  cm550_rpmHistogramAndAveragingStatistics.
- CM848 counterpart (different code): cm848_updateTripAndLifetimeCounters 0x523148.
- name idea: cm550_updateTripInformation.

## 0x30a5e cm550_FUN_00030a5e (first step of mc68k_runPowerDownSequence, jsr @0x27fb2; only reference)
- gate algorithm_enable_flags_3_cal bit 0x200 (trip_information_enable).
- eeprom_write_failure_flag_cal (0x803fdc, 1069 +8 SDEEWRFU) != 0 -> TIFUSS (0x80614e, 1216 +28 'bit mapped fault
  status log for trip info'; current name fuel_statistics_overflow_flags) |= 2 then |= 0x80.
- system error status word 0 (0x806000) bit 0x800 AND fault_processing_enable_flags[0] bit 0x800 -> |= 8 then |= 0x200.
  Bit 0x800 is set by cm550_loadParameterBlockAndUpdatePowerDownCounts when consecutive_incomplete_power_down_count_cal
  > consecutive_incomplete_power_down_limit (too many incomplete power-downs).
- bit 0x1000 (set there when parameter_block_uploaded == 0: no power-down parameter block loaded) AND enable -> |= 0x1000, |= 0x2000.
- CM848 counterpart: cm848_flagTripInformationPowerDownDataLoss 0x523760 (one check: fault_detected_cal.power_down_data_lost_error ->
  trip_information_fault_status_cal |= 8 then |= 0x200 - the same two TIFUSS bits as CM550's bit-11 step), no trip enable gate,
  no EEPROM / no-parameter-block steps, called from cm848_restartApplicationWithoutReset -> counterpart (not twin).
- name idea: cm550_flagTripInformationPowerDownDataLoss. Global: 0x80614e -> trip_information_fault_status (working RAM, no _cal; CM848 trip_information_fault_status_cal is the same record 8B6D +E TIFUSS).

## 0x30b0e cm550_FUN_00030b0e
- single rts (4e75); only reference jsr @0x28774 in mc68k_applicationMain start-up, between mc68k_scheduler_init (0x1bf54)
  and the undumped 0x42ad4. CM848's start-up (cm848_applicationMain) has no matching call -> none.
- name idea: cm550_emptyStartupStub (family: cm550_emptyStubFunction4/7/10, cm550_emptyInitPlaceholder 0x303d2).

## 0x31496 cm550_FUN_00031496 (trending trigger evaluation) - caller cm550_runEvery20FramesTaskSetPhase5 (100 ms)
- gate algorithm_enable_flags_18_cal.trending_enable (bit 4, TRAGEN), engine_state != STOPPED, TRITWNAE (0x804a04 = 126D +1A,
  current name trending_data_capture_active_cal) == 1.
- four window triggers, each min < x <= max (strict upper: x > max -> 0, x <= min -> 0):
  0x801e98 engine speed (current_engine_rpm_filtered in TRESMN 0x808a82 .. TRESMX 0x808a80)
  0x801e9a load (engine_load_at_current_speed_percent in TRPCLDMN .. TRPCLDMX)
  0x801e9c IMT (intake_manifold_temperature_sensor_state.filtered_value in TRIMTPMN 0x808a8a .. TRIMTPMX 0x808a88)
  0x801e9e coolant (coolant_temperature_sensor_state.filtered_value in TRCQMN 0x808a8e .. TRCQMX 0x808a8c)
- all four -> TRTRCD (0x804a08, 126D +1E 'all triggers satisfied') = 1 and (while TRTRCDTR 0x804a02 is 0) TRTRCDTM 0x804a00 += 1;
  at TRTRSATM (0x808a7e, seconds) x 10 it sets TRTRCDTR = 1. Any one false -> TRTRCD = TRTRCDTM = TRTRCDTR = 0.
- CM848: no trending records / code -> none. name idea: cm550_evaluateTrendingTriggers.
- globals: 0x801e98 trending_engine_speed_trigger_satisfied_flag, 0x801e9a trending_engine_load_trigger_satisfied_flag,
  0x801e9c trending_intake_manifold_temperature_trigger_satisfied_flag, 0x801e9e trending_coolant_temperature_trigger_satisfied_flag
  (RAM below the EEPROM image, no e2m record; readers 0x31496 + the window-end step of 0x315be);
  0x804a08 trending_all_triggers_satisfied_flag_cal (126D +1E TRTRCD, EEPROM image); 0x808a80 trending_engine_speed_trigger_maximum (TRESMX),
  0x808a82 rpm_divisor_value -> trending_engine_speed_trigger_minimum (TRESMN), 0x808a88/8a/8c/8e IMT / coolant max / min.

## 0x315be cm550_FUN_000315be (trending interval timing + data set store) - executiveFrameInterruptHandler case 3 (every 40 frames = 200 ms)
- counter 0x801ea0 += 1; at 300 (= 60 s) clear and run, if trending_enable and engine not STOPPED.
- interval in minutes: 2000 while TRNOSATN (0x8049fa) < 3, else TRITTR (0x808a7c, 126C +2, hours) x 60. TRITTM 0x8049f4 counts
  minutes; at the interval -> TRITWNLM 0x8049f6 = interval / 10 and the window starts (TRITWNTM 0x8049f8 counts); TRITWNAE 0x804a04 = 1
  while TRITWNTM < TRITWNLM. TRFLUSSR 0x804a16 = lifetime_fuel_used when TRITTM is 0.
- TRAVNOCU 0x804a0a += 1, TRLDRNT2 0x804a0c += 0x80bad4 (duty_cycle_monitor_load_factor) every minute.
- any fault_count_table[0..124].status 1 or 3 -> at window end (TRITWNAE 0, TRITWNAL 0x804a06 = 1) writes a ZERO data set
  (time stamp only) and advances; else: while TRITWNAE and TRTRCDTR, stores oil pressure / boost / coolant (a3 = 0x80a2aa +0x60/+0x76/+0x8c)
  into the 14-byte record TRSATB[TRSAIN] (0x804a1a + 14 x index); at window end the oil pressure is kept only if speed / IMT / coolant
  triggers are set and the LOAD trigger is CLEAR (tst.w 0x801e9a / bne -> zero), boost / coolant zeroed; then writes TRAVFLCN
  (0x804a14 = (lifetime_fuel_used - TRFLUSSR) / minutes / 60... ), TRLDINAV (0x804a10 = TRLDRNT2 / TRAVNOCU), the time stamp TRTMST 0x8049f0
  = engine_hour_meter & 0xffffff00 | TRTQCDID (0x804a12 = throttle_100_fueling & 0xff00) >> 8 into record +10; advances TRSAIN (wraps at
  TRNOSARQ), TRNOSATN (at TRNOSARQ: = 3, index += 3), clears the interval / trigger state. TRITWNAL = TRITWNAE at the end.
- CM848: none. name idea: cm550_recordTrendingDataSets (or cm550_runTrendingIntervalAndStoreDataSet).
- e2m-proven global renames (126D block base 0x8049ea): 0x8049f4 TRITTM trending_interval_elapsed_minutes_cal (now trending_presample_interval_counter_cal),
  0x8049f6 TRITWNLM trending_interval_window_limit_cal, 0x8049f8 TRITWNTM trending_interval_window_elapsed_cal (now trending_sample_phase_counter_cal),
  0x8049fa TRNOSATN trending_data_set_written_count_cal, 0x8049fc TRSAIN trending_storage_table_index_cal, 0x804a04 TRITWNAE trending_interval_window_active_flag_cal,
  0x804a06 TRITWNAL trending_interval_window_active_previous_flag_cal, 0x804a0a TRAVNOCU trending_average_load_sample_count_cal (now output_control_countdown_timer_cal),
  0x804a0c TRLDRNT2 trending_load_accumulator_cal (now engine_run_counter_snapshot_1_cal), 0x804a10 TRLDINAV trending_interval_average_load_cal
  (now engine_run_counter_snapshot_2_cal), 0x804a12 TRTQCDID trending_torque_curve_maximum_cal, 0x804a14 TRAVFLCN trending_average_fuel_consumption_cal
  (now engine_run_counter_snapshot_0_cal), 0x804a16 TRFLUSSR trending_lifetime_fuel_used_snapshot_cal, 0x8049f0 TRTMST trending_data_set_time_stamp_cal,
  0x804a1a TRSATB trending_storage_table_cal (now histogram_stored_ticks_cal; 1400 bytes = 100 x 14-byte records), 0x808a7c TRITTR trending_interval_hours.

## 0x31a68 cm550_FUN_00031a68 (start-up: jsr @0x287f8 in mc68k_applicationMain right after cm550_initializeTripInformation; only ref)
- asm 0x31a68-0x31acc: if trending enable bit (0x803cb8 & 0x10) and TRRBOC (0x8049ea, 126D +0 'trending feature flag that indicates
  when (if) an engine rebuild occurred') != 0: clr TRITTM / TRITWNTM / TRTRCDTM / TRTRCDTR / TRITWNAE / TRITWNAL / TRAVNOCU, clr TRRBOC,
  TRNOSARB (0x8049fe, 'number of samples taken by trending feature before rebuild flag') = TRNOSATN, TRNOSATN = 0,
  TRRBTMST (0x8049ec, 'trending feature time stamp written to NVM when engine rebuild') = engine_hour_meter (0x80ccee), clr.l TRLDRNT2.
- TRRBOC has no writer in the ROM (only this read + clear) -> a service tool sets it.
- CM848: none. name idea: cm550_resetTrendingAfterEngineRebuild.
- globals: 0x8049ea trending_engine_rebuild_flag_cal; 0x8049ec (now calibration_validator_ptr_cal - wrong) trending_engine_rebuild_time_stamp_cal;
  0x8049fe trending_data_sets_before_rebuild_count_cal.

## 0x31bce cm550_FUN_00031bce = PGN 65269 AMB build + send
- registered by mc68k_initializeJ1939Datalink: scheduleJ1939PeriodicMessage(queue 0, PGN 0xfef5 = 65269, 1000 ms, offset 170 ms, 0x31bce)
  (pea @0x28d74) and by the request-handler registrations 0x2f538 (FUN_0002f47e(0xfef5, 0x31bce) @0x2f5b6).
- byte 1 (0x801eca) = (ambient_air_pressure_sensor_state.filtered_value (0x80a3ba) x 2 x 6906 / 1000) >> 7 = count x 0.1079;
  ADAAPRFT is 0.015906 inHg/count -> x 3.38639 kPa/inHg / 0.5 kPa/bit = 0.1077: SPN 108 barometric pressure. No fault check.
  Then cm550_sendCanMessage(&j1939_pgn65269_tx_message).
- The descriptor is built by 0x31c1a (named cm550_j1939MessageSetup_PGN_65265 but it is PGN 65269: header 0xfef500, JCAAPZ 0x803f50
  'default network priority for ambient conditions message').
- CM848 counterpart: cm848_buildPgn65269AmbientConditionsMessage 0x23e8c (adds 0xFE on fault + ambient air temperature bytes 4-5).
- name idea: cm550_buildPgn65269AmbientConditionsMessage.

## 0x31ed2 cm550_FUN_00031ed2 = CCVS1 (PGN 65265) descriptor init + request handler registration
- called once from mc68k_initializeJ1939Datalink (jsr @0x28be2). header 0xfef100 | (JCCRVSPZ 0x803f52 'default network priority for
  CC / VSS message' & 7) << 2, source address 0x80da01, length 8, data 0x801ee2, status 0x801eea; byte 1 (0x801ee2) = 0xf3;
  FUN_0002f47e(0xfef1, 0x31c84 j1939HandlePgn65265CruiseVehicleSpeed) = the PGN 59904 request responder.
- CM848 cm848_initPgn65265CruiseSpeedHandler 0x24664: same stores in the same order (header 0xfef100 with its priority, SA, 8, data,
  status, 0xf3) plus one more store ccvs1_cruise_control_state = 7 before cm848_j1939RegisterPgnHandler(0xfef1, builder) -> counterpart
  (close; one extra store).
- name idea: cm550_initializePgn65265CruiseControlVehicleSpeedHandler. Global: 0x801ee2 (ccvs_message_byte_0) = CM848's j1939_ccvs1_two_speed_axle_byte.

## 0x32052 cm550_FUN_00032052 = PGN 65259 component identification request handler
- reached only via FUN_0002f47e(0xfeeb, 0x32052) in 0x320f6 (pea @0x32138; the other 'abs' hits are opcode coincidences).
- payload 0x801f12 (40 bytes = descriptor length 0x28): 5 bytes make 0x803dcc ('CMMNS'), '*', 17 bytes model 0x803dd1 ('ISB 195'),
  '*', 4 raw bytes 0x803de2 (serial number, binary 0x035e4b37 in the dump), '*', 10 bytes 0x803ebb (unit number, spaces), '*';
  then cm550_sendCanMessage(&j1939_pgn65259_tx_message).
- CM848 counterpart: cm848_j1939HandlePgn65259ComponentId 0x24870 (same fields/delimiters, but the serial number is formatted as 8
  decimal digits with cm848_formatNumberAsDecimalText; 44-byte payload) -> counterpart.
- name idea: cm550_j1939HandlePgn65259ComponentId. (0x320f6 cm550_engineSerialNumberPGN_65259_Builder is really the descriptor
  initializer = counterpart of cm848_initPgn65259ComponentIdHandler.)

## 0x32c22 vp44_FUN_00032c22 = EBC1 (PGN 61441) transmit descriptor init - NOT VP44
- called once from mc68k_initializeJ1939Datalink (jsr @0x28be8). asm: header 0xf00100 | (JCEBDFPZ 0x803f90 'default network priority
  for electronic brake controller #1 message' & 7) << 2, SA 0x80da01, length 5, payload 0x80347a bytes +0 and +2 = 0xff,
  data pointer 0x80347a, status 0x803490.
- the EBC1 builder is 0x32bbc (NO function row in the CM550 project!): bytes 4 (0x80347d) = 0x40 when 0x80bcd0 bit 3, | 1 when
  0x80bccf bit 1; byte 5 = 0x80a9f1; then cm550_sendCanMessage(0x803482). Registered scheduleJ1939PeriodicMessage(0, 61441, 100 ms, 20 ms) @0x28de6.
- CM848 cm848_initializePgn61441ElectronicBrakeController1Buffer 0x25824: same header/priority/SA/length 5 stores, but THREE 0xff seeds
  (bytes 0, 2, 1) vs CM550's two (0, 2) -> counterpart (one extra store).
- name idea: cm550_initializePgn61441ElectronicBrakeController1Buffer. Globals: 0x80347a vp44_lift_pump_table_2_size and
  0x80347c vp44_lift_pump_table_2_ptr are EBC1 payload bytes 1 and 3 (offsets 0 / 2; seeded 0xff = not available; byte 2 =
  SPN 521 brake pedal position is NOT seeded in CM550); the builder writes byte 4 (0x80347d: 0x01 = accelerator interlock switch
  bits 1-2, 0x40 = remote accelerator enable switch bits 7-8) and byte 5 (0x80347e = 0x80a9f1, SPN 973 engine retarder selection);
  0x803f90 -> j1939_pgn61441_priority_cal (CM848 name).

## 0x33164 vp44_FUN_00033164 = PGN 65263 EFL/P1 build + send - NOT VP44
- registered scheduleJ1939PeriodicMessage(0, 0xfeef = 65263, 500 ms, 130 ms) @0x28d44 and FUN_0002f47e(0xfeef, 0x33164) @0x2f59e (request).
- byte 4 (0x8034eb = payload 0x8034e8 + 3) = ((oil_pressure_sensor_state.filtered_value (0x80a30a) >> 7) x 6906 / 1000) >> 2
  = count x 0.01349; ADOLPRFT 0.0078125 psi/count x 6.895 kPa/psi / 4 kPa/bit = 0.01347 -> SPN 100 engine oil pressure. No fault check.
  then cm550_sendCanMessage(0x8034da = j1939_pgn65263_tx_message). Bytes 1, 2, 5-6, 8 = 0xff (set by 0x331ae).
- CM848 counterpart: cm848_buildPgn65263EngineFluidLevelPressure1Message 0x25eb4 (fuel delivery + oil + coolant pressure with enables).
- name idea: cm550_buildPgn65263EngineFluidLevelPressure1Message.

## EC1 (PGN 65251) send-on-change family: 0x333d6 / 0x33460 / 0x334ec / 0x3366a (CM848 0x1b624 / 0x1b69c / 0x1b778 / 0x1b730)
- 0x333d6 (word) / 0x33460 (byte): args (previous, current) (caller pushes current first, then previous: (0xc,a7) = previous).
  previous 0 -> return current != 0. Else diff = previous - current, but when negative it computes -previous - current (an ABS macro
  over an unparenthesized difference), q = |diff| / previous (divs.l, integer), return 1 when q x 10 >= 1 (unsigned).
  Simulated (sim_change_test.py): 1000->1001 gives 1, 1000->900 gives 0, 1000->0 gives 1: it fires on ANY increase, a drop to 0, or 0->non-zero.
  CM848 cm848_hasWordChangedByTenPercent / cm848_hasByteChangedByTenPercent: correct |new-old|, early 'old <= diff -> 1', then
  diff x 10 / old > 0 -> a real 10 % test. Different arithmetic -> counterparts. Names: cm550_hasWordChangedByTenPercent /
  cm550_hasByteChangedByTenPercent (intent; plate must state the integer-division behavior).
- 0x334ec: copies the 28-byte payload 0x8034f2 to 0x80350e (7 x move.l), rebuilds it (buildPgn65251EngineConfiguration1Payload),
  tests offsets 0w 2b 3w 5b 6w 8b 9w 11b 12w 14b 15w 27b (word = bytes n, n+1), any 1 -> 0x3366a. No reference in the dumped ROM.
  CM848 0x1b778: lswi/stswi 16+12 bytes copy, rebuild, the SAME 12 tests at the SAME offsets in the SAME order, then 0x1b730; also no
  reference in CM848 -> TWIN: shared name sendPgn65251EngineConfiguration1OnChange (CM848 row cm848_sendPgn65251EngineConfiguration1OnChange changes).
- 0x3366a: status byte 0x803538 & 0xf0 == 0 -> build payload 0x8034f2 + cm550_sendCanMessage(0x80352a). Registered
  scheduleJ1939PeriodicMessage(queue 0, 65251, 5000 ms, 110 ms) @0x28cb4 and called by 0x334ec. CM848 0x1b730: lbz status, mask 0xf0
  (rlwinm 24,27), build 0x3fa7f8, cm848_sendJ1939Message(0x3fa830); registered (0, 65251, 5000, 110) in cm848_j1939_system_init @0x539324
  -> TWIN: shared name sendPgn65251EngineConfiguration1Message.

## 0x33716 cm550_FUN_00033716 = PGN 65253 HOURS request handler (engine hours)
- reached only via FUN_0002f47e(0xfee5, 0x33716) in 0x33754 (pea @0x337b0). bytes 1-4 (0x803548) = byteSwap32(cm550_scaleByRatio(TITMT2
  (0x804fc0, 117F +20 'accumulated time of engine operation', 0.1 s/count), 20, 36000)) = count / 1800 -> 0.05 h/bit = SPN 247 total
  engine hours; then cm550_sendCanMessage(0x80353a = j1939_pgn65253_tx_message). Bytes 5-8 (revolutions) 0xff from 0x33754.
- CM848: no PGN 65253 code -> none. name idea: cm550_j1939HandlePgn65253EngineHours.

## 0x33754 cm550_FUN_00033754 = PGN 65253 descriptor init + request registration
- called once from the request handler registration list 0x2f538 (jsr @0x2f55c). header 0xfee500 | (JCEGTMPZ 0x803f8c 'default
  network priority for the engine hours message (PGN FEE5)' & 7) << 2, SA, length 8, data 0x803548, status 0x803550, bytes 8,7,6,5 = 0xff,
  FUN_0002f47e(0xfee5, 0x33716). CM848: none. name idea: cm550_initializePgn65253EngineHoursHandler.
- global 0x803f8c -> j1939_pgn65253_priority_cal (EEPROM image).

## 0x337c4 cm550_FUN_000337c4 = PGN 65262 ET1 build + send
- registered scheduleJ1939PeriodicMessage(0, 0xfeee = 65262, 1000 ms, 430 ms) @0x28d14 (same constants as CM848's ET1 registration
  0, 0xfeee, 1000, 0x1ae) and FUN_0002f47e(0xfeee, 0x337c4) in 0x33880 (pea @0x338d6).
- byte 1 (0x803560) = SPN 110 coolant temperature: ((coolant filtered 0x80a336 - 6400) >> 7 = deg F) x 5 - 160) / 9 = deg C; < -40 -> 0,
  >= 210 -> 0xfa, else + 40. byte 2 = SPN 174 fuel temperature, same conversion from vp44_fuel_temperature (0x80a188, e2m 801A +16 FLFLTP
  'RAM image of fuel temp measured by pump controller', /16 = deg F). bytes 3-4 = 0xffff (oil temperature n/a). send 0x803552.
- reads one value the VP44 reports, but its job is the J1939 ET1 broadcast -> cm550_ not vp44_.
- CM848 counterpart: cm848_buildPgn65262EngineTemperature1Message 0x26024 (fault bytes 0xFE, oil temperature) -> counterpart.
- name idea: cm550_buildPgn65262EngineTemperature1Message. (0x33880 cm550_engineTemperaturePGN_65262_Builder is its descriptor init.)

## 0x33a1e cm550_FUN_00033a1e = FD1 (PGN 65213) descriptor init
- called once from mc68k_initializeJ1939Datalink (jsr @0x28c0c), after ERC1's 0x339b0 (CM848 order: ERC1 init then FD1 init too).
  header 0xfebd00 | (JCFMDFPZ 0x803f92 'default network priority for fan drive message' & 7) << 2, SA, length 2, data 0x803582,
  status 0x803598. The FD1 builder is 0x339fe (NO function row): byte 2 (0x803583) = 0x80a9f3 | 0xf0, send 0x80358a; registered
  scheduleJ1939PeriodicMessage(0, 65213, 1000 ms, 50 ms) @0x28dd0.
- CM848 cm848_initializePgn65213FanDrive1Buffer 0x26480: the same stores in the same order (header 0xfebd00, priority word & 7 << 2
  into byte 0, SA byte 3, length 2, data, status), same init-list position -> TWIN: shared name initializePgn65213FanDrive1Buffer.
- global 0x803f92 -> j1939_pgn65213_priority_cal.

## 0x33a62 cm550_FUN_00033a62 = PGN 65257 LFC (fuel consumption) request handler
- reached only via FUN_0002f47e(0xfee9, 0x33a62) in 0x33aea (pea @0x33b2c; 0x33aea is misnamed cm550_retarderConfigPGN_65249_Builder,
  it is the PGN 65257 descriptor init: header 0xfee900, JCFCPZ 0x803f72 'default network priority for fuel consumption message').
- bytes 1-4 (0x8035a8) = byteSwap32(scaleByRatio(scaleByRatio(TIGAT3 0x804fa4 (trip fuel, 0.125 gal), 2, 8), 3785411, 1000000))
  = 0.5 L/bit -> SPN 182 trip fuel; bytes 5-8 (0x8035ac) = byteSwap32(scaleByRatio(TIGAT2 0x804fa0 (lifetime fuel, 0.125 gal) >> 2,
  3785411, 1000000)) -> SPN 250 total fuel used. send 0x80359a.
- CM848: no PGN 65257 code -> none. name idea: cm550_j1939HandlePgn65257FuelConsumption.

## 0x33e58 cm550_FUN_00033e58 = PGN 65270 IC1 build + send
- registered scheduleJ1939PeriodicMessage(0, 0xfef6 = 65270, 500 ms, 190 ms) @0x28d8a and FUN_0002f47e(0xfef6, 0x33e58) @0x2f5c2.
- byte 2 (0x80360f) = scaleByRatio(boost_pressure_sensor_state.filtered_value (0.0159 inHg/count), 6906, 128000) >> 1 = count x 0.02698;
  0.0159 x 3.38639 / 2 kPa/bit = 0.02693 -> SPN 102 boost pressure. byte 3 (0x803610) = SPN 105 intake manifold temperature (deg F -> deg C,
  < -40 -> 0, >= 210 -> 0xfa, else + 40). No fault check. send 0x803600 (j1939_pgn65270_tx_message; descriptor by 0x33eee).
- CM848 counterpart: cm848_buildPgn65270InletExhaustConditions1Message 0x264d8 (same 6906/128000 >> 1 constant on intake manifold
  pressure, 0xFE on fault bits). name idea: cm550_buildPgn65270InletExhaustConditions1Message.

## 0x33f5a cm550_FUN_00033f5a = PGN 65264 PTO build + send
- registered scheduleJ1939PeriodicMessage(0, 0xfef0 = 65264, 100 ms, 150 ms) @0x28d5a and FUN_0002f47e(0xfef0, 0x33f5a) @0x2f5aa.
- bytes 4-5 (0x803629 / 0x80362a) = byteSwap16(power_take_off_requested_engine_speed) (SPN 187 PTO set speed);
  byte 6 (0x80362b) = 0xcc, 0xdc when 0x80bcd0 bit 4 (e2m 000E +2 mask 10 DSRXSWSS 'debounced value of remote PTO switch input' -
  the byte's current name debounced_value_for_rear_axle_ratio_switch_on_off does not fit this bit), | 1 when PTO on (0x80bcd5 bit 4 DSPTONSW);
  byte 7 (0x80362c) = 0xcc, 0xdc when PTO resume (bit 0 DSPTRUSW), | 1 when PTO set (bit 2 DSPTSESW). send 0x803618.
- CM848 counterpart: cm848_buildPgn65264PowerTakeOffInformationMessage 0x2bd58 (gated by power_take_off_enable, datalink-sourced switches
  give 0xfc / | 3) -> counterpart. name idea: cm550_buildPgn65264PowerTakeOffInformationMessage.

## 0x341e6 cm550_FUN_000341e6 = RC (PGN 65249) descriptor init
- called once from mc68k_initializeJ1939Datalink (jsr @0x28c18). header 0xfee100 | (JCRDCGPZ 0x803f80 'default network priority for
  retarder configuration message' & 7) << 2, SA = 0x80da0b (j1939_retarder_node_source_address, not the engine SA), length 19,
  data 0x803630, status 0x803652; payload byte 19 (+0x12) = 0xff. The RC builder is 0x3407a (named vp44CanMessage100ResponseBuilder),
  registered (queue 1, 65249, 5000 ms, 301 ms) like CM848's (1, 0xfee1, 5000, 0x12d).
- CM848 cm848_initializePgn65249RetarderConfigurationBuffer 0x2682c: same stores (retarder SA, 19) but no 0xff seed -> counterpart (one store).
- name idea: cm550_initializePgn65249RetarderConfigurationBuffer. global 0x803f80 -> j1939_pgn65249_priority_cal.

## 0x34232 cm550_FUN_00034232 = PGN 65248 VD request handler
- only via FUN_0002f47e(0xfee0, 0x34232) in 0x3429a (pea @0x342dc). bytes 1-4 (0x803662) = byteSwap32(scaleByRatio(TIMIT3 0x804fac
  (117F +C 'distance travelled since last reset of trip information', 0.015625 mi), 12904, 64000)) -> 0.125 km/bit SPN 244 trip distance;
  bytes 5-8 (0x803666) = the same on TIMIT2 0x804fa8 (117F +8 'accumulated distance travelled by vehicle') -> SPN 245 total distance.
  send 0x803654.
- CM848 counterpart: cm848_j1939HandlePgn65248VehicleDistance 0x26bb0 (trip_distance_cal / lifetime pulses x 0xc47400 / ...) -> counterpart.
- name idea: cm550_j1939HandlePgn65248VehicleDistance.

## 0x34394 cm550_FUN_00034394 = PGN 65255 VH request handler
- only via FUN_0002f47e(0xfee7, 0x34394) in 0x343d2 (pea @0x3441c). bytes 5-8 (0x803696) = byteSwap32(scaleByRatio(TITMP2 0x804fbc
  (117F +1C 'accumulated time of operation of power takeoff device', 0.1 s), 20, 36000)) -> 0.05 h/bit SPN 248 total PTO hours;
  bytes 1-4 (0x803692, total vehicle hours SPN 246) stay 0xffffffff from 0x343d2. send 0x803684.
- CM848: no PGN 65255 code -> none. name idea: cm550_j1939HandlePgn65255VehicleHours.
- (0x343d2 vp44_vehicleHoursPGN_65255_Builder is the descriptor init, not VP44; 0x803692 protection_flag_source_2 = the VH payload.)

## 0x34440 cm550_FUN_00034440 = PGN 65260 VI descriptor init + request registration
- called once from 0x2f538 (jsr @0x2f580). header 0xfeec00 | (JCVHIDPZ 0x803f8e 'default network priority for vehicle identification
  message' & 7) << 2, SA, length 20, data pointer 0x803e7f directly (20 bytes in the EEPROM image; dump = 20 spaces), status 0x8036aa;
  FUN_0002f47e(0xfeec, 0x34430). 0x34430 (NO function row) = cm550_sendCanMessage(0x80369c) only.
- CM848 cm848_initPgn65260VehicleIdHandler 0x26ddc: length 21, copies vehicle_vin_string_cal into a RAM buffer and appends '*'
  -> counterpart. name idea: cm550_initializePgn65260VehicleIdentificationHandler. global 0x803e7f -> vehicle_identification_number_cal.

## 0x344ce vp44_FUN_000344ce = PGN 65279 water in fuel indicator descriptor init - NOT VP44
- called once from mc68k_initializeJ1939Datalink (jsr @0x28c48). header 0xfeff00 | (JCWFDFPZ 0x803f94 'default network priority for water
  in fuel indicator message' & 7) << 2, SA, length 1, data 0x8036ac, status 0x8036c2. The builder 0x34496 (NO function row): byte 1 = 1
  when 0x80bcf6 bit 2 (LCWFLP water in fuel lamp commanded) else 0; registered (0, 65279, 10000 ms, 40 ms) @0x28e00.
- CM848 cm848_initializePgn65279WaterInFuelIndicatorBuffer 0x26efc: the same 6 stores plus seven 0xff seeds -> counterpart.
- name idea: cm550_initializePgn65279WaterInFuelIndicatorBuffer. global 0x803f94 -> j1939_pgn65279_priority_cal.

## 0x34d52 vp44_FUN_00034d52 = wet stack timing advance (WSTA) with the high-fueling ramp-down - NOT VP44
- caller cm550_runEvery4FramesTaskSetPhase3 (20 ms). WSTA (0x80dee4, 1077 +0 'timing advance as commanded by wet stack') =
  WSADTA (0x80dee8, 1077 +4 'timing advance from coolant or intake manifold temperature') - WSTARM (0x8071de, 1074 +4 'wet stack timing
  ramp rate when final fueling exceeds the threshold'; current name vp44_fault_counter_threshold_2) x (final_fueling - WSMXLMFL 0x8071dc) / 100
  while final_fueling > WSMXLMFL, else WSADTA; then WSTA = max(WSTA (signed), WSTAMN 0x808ac4 140A +0 'low limitation of wet stack timing').
- WSADTA comes from 0x34cc4 (named vp44_liftPumpFuelDeliveryController - it is the wet stack table selection, frame 7 every 200 ms);
  cm550_applyWetStackTimingAdvance (step 4 of the timing chain) uses WSTA.
- CM848: only a cranking wet stack timing record (CKWSTA) - no running wet stack code -> none.
- name idea: cm550_calculateWetStackTimingAdvance. globals: 0x8071de -> wet_stack_timing_ramp_rate (WSTARM, ROM->RAM image, no _cal),
  0x808ac4 -> wet_stack_timing_minimum (WSTAMN), 0x80dee4 wet_stack_adjusted_timing_floor_0_120 -> wet_stack_timing_advance (WSTA),
  0x80dee8 wet_stack_timing_base_value_0_120 -> wet_stack_temperature_timing_advance (WSADTA).

## Final name picks (describer), all checked unused in both function_renames.csv
0x30498 cm550_accumulateEngineBrakeOnTime | 0x306ca cm550_updateTripInformation | 0x30a5e cm550_flagTripInformationPowerDownDataLoss
0x30b0e cm550_emptyStartupStub (note: 0x1ffd0 cm550_emptyPlaceholderInit is a 2nd empty start-up call @0x28864; only the call position differs)
0x31496 cm550_evaluateTrendingTriggers | 0x315be cm550_updateTrendingIntervalAndStoreDataSets | 0x31a68 cm550_restartTrendingAfterEngineRebuild
0x31bce cm550_buildPgn65269AmbientConditionsMessage | 0x31ed2 cm550_initializePgn65265CruiseControlVehicleSpeedHandler
0x32052 cm550_j1939HandlePgn65259ComponentIdentification | 0x32c22 cm550_initializePgn61441ElectronicBrakeController1Buffer
0x33164 cm550_buildPgn65263EngineFluidLevelPressure1Message | 0x333d6 cm550_hasWordChangedByTenPercent | 0x33460 cm550_hasByteChangedByTenPercent
0x334ec sendPgn65251EngineConfiguration1OnChange (TWIN 0x1b778) | 0x3366a sendPgn65251EngineConfiguration1Message (TWIN 0x1b730)
0x33716 cm550_j1939HandlePgn65253EngineHours | 0x33754 cm550_initializePgn65253EngineHoursHandler | 0x337c4 cm550_buildPgn65262EngineTemperature1Message
0x33a1e initializePgn65213FanDrive1Buffer (TWIN 0x26480) | 0x33a62 cm550_j1939HandlePgn65257FuelConsumption
0x33e58 cm550_buildPgn65270InletExhaustConditions1Message | 0x33f5a cm550_buildPgn65264PowerTakeOffInformationMessage
0x341e6 cm550_initializePgn65249RetarderConfigurationBuffer | 0x34232 cm550_j1939HandlePgn65248VehicleDistance | 0x34394 cm550_j1939HandlePgn65255VehicleHours
0x34440 cm550_initializePgn65260VehicleIdentificationHandler | 0x344ce cm550_initializePgn65279WaterInFuelIndicatorBuffer | 0x34d52 cm550_calculateWetStackTimingAdvance

## Leads (not in the batch)
- no function row: 0x32bbc EBC1 builder (61441, 100/20), 0x339fe FD1 builder (65213, 1000/50), 0x34430 PGN 65260 request handler (one send;
  same as CM848 cm848_j1939HandlePgn65260VehicleId), 0x34496 WIF builder (65279, 10000/40).
- misnamed neighbours: 0x31c1a cm550_j1939MessageSetup_PGN_65265 is PGN 65269's descriptor init; 0x320f6 = 65259 descriptor init + registration;
  0x33880 = ET1 descriptor init; 0x33aea cm550_retarderConfigPGN_65249_Builder = PGN 65257 descriptor init; 0x343d2 vp44_vehicleHoursPGN_65255_Builder =
  65255 init; 0x3407a vp44CanMessage100ResponseBuilder = RC builder; 0x34cc4 vp44_liftPumpFuelDeliveryController = wet stack table selection.
- globals: 0x80d2b4 can_transmit_buffer_ptr = SPTU (11DC +4 'value which determines alternate HP ratings'); 0x80615e / 0x806176 TIT3EBTM / TIT2EBTM;
  0x80617e / 0x806182 TIT3EZTM / TIT2EZTM (ESP high HP time); 0x80de64 fuel_statistics_operating_mode = TIEGST (ENG_OFF / IDLE / PTO / drive).

## Enum lead: TIEGST (0x80de64, now fuel_statistics_operating_mode)
- e2m 1215 +12 TIEGST 'THE ENGINE STATE AS DETERMINED BY TRIP INFORMATION, ENG_OFF, IDLE, PTO' (one e2m copy has the longer text), range 0-3.
- 0x306ca: 0 rpm 0 / 2 PTO governor active / 1 idle / 3 otherwise (state 3 carries trip drive fuel TIT3VSFU 'engine not at idle and PTO not active').
- proposal TRIP_INFORMATION_ENGINE_STATE: 0 _ENGINE_OFF, 1 _IDLE, 2 _POWER_TAKE_OFF, 3 _DRIVE.
## Priority words (block 1254, EEPROM image -> _cal; CM550 precedent j1939_pgn65252_priority_cal 0x803f78)
0x803f50 JCAAPZ 65269 | 0x803f52 JCCRVSPZ CC/VSS (65265 and 65261) | 0x803f68 JCEGCGPZ 65251 | 0x803f6a JCEGFDPZ 65263 | 0x803f70 JCEGTPPZ 65262
0x803f72 JCFCPZ 65257 | 0x803f7a JCEPPZ 65270 | 0x803f7e JCPTPZ 65264 | 0x803f80 JCRDCGPZ 65249 | 0x803f82 JCVHDSPZ 65248 | 0x803f86 JCVHHRPZ 65255
0x803f8c JCEGTMPZ 65253 | 0x803f8e JCVHIDPZ 65260 | 0x803f90 JCEBDFPZ 61441 | 0x803f92 JCFMDFPZ 65213 | 0x803f94 JCWFDFPZ 65279
