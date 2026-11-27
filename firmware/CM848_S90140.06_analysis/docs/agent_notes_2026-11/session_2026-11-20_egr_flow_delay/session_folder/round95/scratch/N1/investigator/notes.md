# N1 investigator notes (round 95) - CM550 placeholder functions 0x30000-0x34fff

(started 2026-11-25; no earlier run found)

## Tools
- callers.py (mine): jsr/bsr/bra/pc-relative + raw 4-byte refs to code addresses.
- J1939 transmit builders are registered in mc68k_initializeJ1939Datalink 0x28c5a-0x28e14 via scheduleJ1939PeriodicMessage(queue, PGN, interval ms, offset, builder) (jsr (a4), a4=0x1fe84),
  and as PGN 59904 request responders in cm550_diagnosticDataDump 0x2f586-0x2f5d8 via 0x2f47e(PGN, handler) (table 0x801d5a, 6-byte entries; dispatcher 0x2f4be = PGN 59904 (0xea00) receive handler).
  Periodic: 65265 0x31c84 (70/100) | 61444 0x32c76 | 61443 0x32e4c | 65247 0x330c4 | 65251 0x3366a (110/5000) | 61440 0x338ea (q1) | 65266 0x33b40 | 65249 0x3407a (q1) | 65262 0x337c4 (430/1000) | 65252 0x33d38 | 65263 0x33164 (130/500) | 65264 0x33f5a (150/100) | 65269 0x31bce (170/1000) | 65270 0x33e58 (190/500) | 65271 0x342f0 | 65226 0x3229a | 65213 0x339fe | 61441 0x32bbc | 65279 0x34496
  On request (0x2f47e in diagnosticDataDump): 65252 0x33d38, 65261 0x31f30, 65263 0x33164, 65264 0x33f5a, 65269 0x31bce, 65270 0x33e58, 65271 0x342f0

## 0x30498 cm550_FUN_00030498 -> cm550_countEngineBrakeOnTime (standalone)
- bsr.w from 0x30a3c in 0x306ca (trip information update, 100 ms task, only when operating mode != 0 = engine turning).
- tests 0x80bcf7 bit0 (engine brake driver 1) then 5x 0x80bcf9 bit6 (output 30 = engine brake drivers 2-6 in this build; the same six tests in
  cm550_ioControlBasedFuelCalculator 0xff6c add indicates_of_cyl_brakes_driven_by_eb_driver_1..6 per test). If any: addq.l #1 0x80615e (e2m 1216 +38 TIT3EBTM trip engine brake time) and 0x806176 (1216 +50 TIT2EBTM lifetime). 0.1 s counts (HR scale 2.77777E-5).
- siblings: 0x30414 idle time (TIT2ISTM 0x806152 / TIT3ISTM 0x806156), 0x30454 PTO time (TIT3PTTM 0x80615a / TIT2PTTM 0x806172).
- CM848 cm848_updateTripAndLifetimeCounters has no engine brake time -> no counterpart.
- globals: 0x80615e trip_engine_brake_time (dword, no row), 0x806176 lifetime_engine_brake_time (dword, no row).

## 0x306ca cm550_FUN_000306ca -> cm550_updateTripInformation (counterpart of cm848_updateTripAndLifetimeCounters 0x523148)
- jsr from cm550_runEvery20FramesTaskSetPhase19 (0x1b868; 100 ms). Gate algorithm_enable_flags_3_cal.trip_information_enable (0x803c9a & 0x200).
- TIRF 0x80de66 ==1 -> trip reset (zero 25 histogram bins 0x8060c2, trip fuel / time / counters); classify TIEGST 0x80de64 (0 stopped/1 idle/2 PTO/3 drive);
  counts TIT3TM 0x806162; fuel increment TIFU 0x80de54; J1939/J1587 fuel rate words; lifetime / trip / drive fuel; idle / PTO / engine brake time; ESP time 0x80617e/0x806182; then 0x304f4.
- CM848's counterpart is structured differently (no PTO / engine brake / ESP, fuel from PCI timer) -> counterpart, cm550_ prefix. Neighbour cm550_initializeTripInformation (0x30ade).
- globals: 0x80de66 (row with empty name) trip_information_reset_request_flag (e2m 1215 +14 TIRF); 0x80614e fuel_statistics_overflow_flags -> trip_information_fault_status (1216 +28 TIFUSS; CM848 trip_information_fault_status_cal);
  0x806162 trip_engine_operating_time (1216 +3C TIT3TM, no row); 0x80617e trip_electronic_smart_power_high_horsepower_time? (1216 +58 TIT3EZTM 'ESP HIGH HP MODE') / 0x806182 lifetime (1216 +5C TIT2EZTM) - incremented when can_transmit_buffer_ptr != 0 (0x30a44?) check.

## 0x30a5e cm550_FUN_00030a5e -> cm550_flagTripInformationPowerDownDataLoss (counterpart of cm848_flagTripInformationPowerDownDataLoss)
- first call of mc68k_runPowerDownSequence (0x27fb0). Gate trip_information_enable. eeprom_write_failure_flag_cal (0x803fdc) -> TIFUSS |= 0x2,0x80;
  system error 11 (0x806000 bit 0x800, set by cm550_loadParameterBlockAndUpdatePowerDownCounts when consecutive_incomplete_power_down_count_cal > limit) with its fault_processing_enable_flags[0] bit -> |= 0x8,0x200 (CM848 sets 0x208 on power_down_data_lost_error);
  system error 12 (bit 0x1000: no parameter block loaded at start-up) -> |= 0x1000,0x2000.

## 0x30b0e cm550_FUN_00030b0e -> cm550_emptyStubFunction11 (standalone)
- one rts (0x4e75). One call: jsr at 0x28774 in mc68k_applicationMain's start-up list (progress marker 0x877a), after mc68k_scheduler_init (0x8774) and before func_0x00042ad4 (0x8780).
- existing CM550 empty stubs: 1, 4, 7, 10 (9 deleted). CM848's main has no step at that position (different order).

## Trending feature (e2m group TRENDING B5; CM848 has no TR* records / no trending code -> all standalone, cm550_)
- 126C (ROM->RAM cal, base 0x808a7a, no _cal): +0 TRNOSARQ sample count (0x808a7a) / +2 TRITTR interval hours (0x808a7c, no row) / +4 TRTRSATM trigger hold s (0x808a7e) /
  +6 TRESMX rpm upper (0x808a80 no row) / +8 TRESMN rpm lower (0x808a82 = rpm_divisor_value: WRONG) / +A TRPCLDMX load upper / +C TRPCLDMN load lower / +E TRIMTPMX / +10 TRIMTPMN / +12 TRCQMX / +14 TRCQMN (0x808a88-0x808a8e, no rows)
- 126D (EEPROM image, base 0x8049ea, _cal): +0 TRRBOC rebuild flag 0x8049ea / +2 TRRBTMST rebuild time stamp dword 0x8049ec (= calibration_validator_ptr_cal: WRONG) / +6 TRTMST time stamp dword 0x8049f0 /
  +A TRITTM interval timer (min) 0x8049f4 (trending_presample_interval_counter_cal) / +C TRITWNLM window limit 0x8049f6 / +E TRITWNTM window timer 0x8049f8 (trending_sample_phase_counter_cal) / +10 TRNOSATN 0x8049fa / +12 TRSAIN 0x8049fc /
  +14 TRNOSARB 0x8049fe / +16 TRTRCDTM 0x804a00 / +18 TRTRCDTR 0x804a02 / +1A TRITWNAE 0x804a04 / +1C TRITWNAL 0x804a06 / +1E TRTRCD 0x804a08 / +20 TRAVNOCU 0x804a0a (output_control_countdown_timer_cal: WRONG) /
  +22 TRLDRNT2 dword 0x804a0c (engine_run_counter_snapshot_1_cal: WRONG) / +26 TRLDINAV 0x804a10 (..._2_cal WRONG) / +28 TRTQCDID 0x804a12 / +2A TRAVFLCN 0x804a14 (..._0_cal WRONG) / +2C TRFLUSSR dword 0x804a16
- 126E +0 TRSATB 0x804a1a, 1400 bytes = 100 records x 14: oil pressure / boost pressure / coolant temperature (sensor records 4/5/6 filtered_value) / average fuel consumption / average load / dword time stamp. Only 0x315be touches it.
  Rows inside it: 0x804a1a histogram_stored_ticks_cal, 0x804a1c engine_runtime_total_counter_cal, 0x804a20 runtime_histogram_array_1_cal (all wrong); 0x804a18 hour_meter_stored_ticks_cal sits inside the dword 0x804a16 (no reference).

## 0x31496 cm550_FUN_00031496 -> cm550_evaluateTrendingTriggers (standalone)
- jsr from cm550_runEvery20FramesTaskSetPhase5 (0x1b7b0, 100 ms). Gate trending_enable (0x803cb8 & 0x10), engine_state != STOPPED, TRITWNAE (0x804a04) == 1.
- window flags 0x801e98 rpm (TRESMN < rpm <= TRESMX), 0x801e9a load at current speed, 0x801e9c IMT (sensor 0 filtered), 0x801e9e coolant (sensor 6).
- all four -> TRTRCD 0x804a08 = 1, TRTRCDTM 0x804a00 +1 per 0.1 s until TRTRSATM*10 -> TRTRCDTR 0x804a02 = 1; any out -> all three cleared.

## 0x315be cm550_FUN_000315be -> cm550_runTrendingIntervalAndStoreSamples (standalone)
- jsr at 0x1b9ea, the frame-3 slot of executiveFrameInterruptHandler (once per 40-frame cycle = 200 ms); 0x801ea0 counts 300 -> once a minute.
- interval: TRFLUSSR snapshot at interval start; length 2000 min while TRNOSATN < 3 else TRITTR*60; TRITTM counts to it, then TRITWNLM = length/10 and TRITWNTM runs; TRITWNAE = window active.
- each minute: TRAVNOCU +1, TRLDRNT2 += duty_cycle_monitor_load_factor; scans fault_count_table (125 x 10 bytes status at 0x805a24) for status 1/3.
- writes record [TRSAIN] at 0x804a1a + 14 x index (oil / boost / coolant while window active and TRTRCDTR; at window end computes TRAVFLCN = fuel since snapshot / hours, TRLDINAV = TRLDRNT2 / TRAVNOCU, TRTMST = engine_hour_meter & ~0xff | throttle_100_fueling >> 8), advances the index (wraps at TRNOSARQ; when full count = 3 and index + 3), restarts the interval.

## 0x31a68 cm550_FUN_00031a68 -> cm550_restartTrendingAfterEngineRebuild (standalone)
- jsr at 0x287f8 in mc68k_applicationMain (start-up, right after cm550_initializeTripInformation).
- trending_enable and TRRBOC (0x8049ea) != 0: clears TRITTM, TRITWNTM, TRTRCDTM, TRTRCDTR, TRITWNAE, TRITWNAL, TRAVNOCU, TRRBOC; TRNOSARB = TRNOSATN; TRNOSATN = 0; TRRBTMST = engine_hour_meter (0x80ccee); TRLDRNT2 = 0.

## J1939 init parallel (CM550 mc68k_initializeJ1939Datalink 0x28bdc.. vs CM848 init at cpp line ~100180)
 CM550: 0x31b96 ACK | 0x31ed2 CCVS 65265 | 0x32c22 EBC1 61441 | 0x32e08 EEC1 | 0x33064 EEC2 | 0x33120 EEC3 | 0x33692 EC1 (twin) | 0x339b0 ERC1 | 0x33a1e FD1 65213 | 0x33c28 LFE | 0x341e6 RC 65249 | 0x2faa4 | 0x31c1a AMB 65269 | 0x331ae EFL/P1 | 0x33dfa SHUTDN | 0x33eee IC1 | 0x3401a PTO | 0x34334 VEP1 | 0x344ce 65279 | 0x323be DM1 | 0x32b64 DM8
 CM848: AckBuffer | initPgn65265CruiseSpeedHandler | initializePgn61441...Buffer | initEec1TxDescriptor | initPgn61443Eec2Handler | initPgn65247... | initializePgn65251 (twin) | initializePgn61440... | initializePgn65213FanDrive1Buffer | initializePgn65241 AUXIO1 | initializePgn65249... | initializeEngineRetarderTsc1RequestState | 56320 | initJ1939AmbientConditionsBuffer | FluidLevelPressure | InletExhaust | 65264 | VehicleElectrical | 65279 | Dm1 | Dm8
 Same schedule constants (e.g. 65251 (0,5000,110), 65213 (0,1000,50), 65269 (0,1000,170)).

## 0x31bce -> cm550_buildPgn65269AmbientConditionsMessage (counterpart of cm848_buildPgn65269AmbientConditionsMessage 0x23e8c)
- scheduled PGN 65269 every 1000 ms from 170 (queue 0) + PGN 59904 request responder (0x2f5b6). byte 1 (0x801eca) = SPN 108 barometric pressure: ((ambient_air_pressure_sensor_state.filtered_value x 2) & 0xffff) x 6906 / 1000 >> 7 (0.5 kPa/bit). sends j1939_pgn65269_tx_message (0x801ebc).
- CM848 same formula but 0xFE on the fault bits and bytes 4-5 ambient air temperature -> different code.
- global: 0x801eca (no row) j1939_pgn65269_barometric_pressure (CM848 name). Lead: cm550_j1939MessageSetup_PGN_65265 (0x31c1a) actually initializes the PGN 65269 descriptor (counterpart of cm848_initJ1939AmbientConditionsBuffer).

## 0x31ed2 -> cm550_initializePgn65265CruiseControlVehicleSpeedBuffer (counterpart of cm848_initPgn65265CruiseSpeedHandler 0x24664)
- descriptor 0x801ed4: 0xfef100 | priority (0x803f52 e2m 1254 +4 JCCRVSPZ) & 7 << 2, SA 0x80da01, DLC 8, data 0x801ee2, status 0x801eea, byte 1 = 0xf3; registers 0x31c84 (j1939HandlePgn65265CruiseVehicleSpeed = the CCVS1 builder) for PGN 65265 with 0x2f47e.
- CM848 does the same plus ccvs1_cruise_control_state = 7 -> counterpart.

## 0x32052 -> cm550_buildPgn65259ComponentIdentificationMessage (counterpart of cm848_j1939HandlePgn65259ComponentId 0x24870)
- registered by 0x320f6 (pea 0x32052 / 0xfeeb / jsr 0x2f47e at 0x32138). payload 0x801f12 (40 bytes = DLC 0x28): make 5 bytes from 0x803dcc ('CMMNS') '*' model 17 from 0x803dd1 ('ISB 195') '*' serial number 4 raw bytes from 0x803de2 (0x035e4b37 = 56511287) '*' unit number 10 from 0x803ebb (spaces) '*'; sends j1939_pgn65259_tx_message (0x801f04).
- CM848 formats the serial number as 8 decimal digits (cm848_formatNumberAsDecimalText), 44 bytes -> counterpart.
- dataplate block e2m 0006 DAT_PLAT (0x803dca, 332 bytes, EEPROM image -> _cal). 0x803dcc/0x803dd1/0x803de2 also read by cm550_FUN_000277e6 (J1587 PID 243-style make*model*serial reply, MID 0x80).
- globals: 0x801f12 j1939_pgn65259_payload byte[40]; 0x803dcc component_identification_make_cal byte[5]; 0x803dd1 component_identification_model_cal byte[17]; 0x803de2 component_identification_serial_number_cal byte[4]; 0x803ebb component_identification_unit_number_cal byte[10].
- Lead: 0x320f6 cm550_engineSerialNumberPGN_65259_Builder is the CI descriptor initializer (counterpart of cm848_initPgn65259ComponentIdHandler).

## 0x32c22 -> cm550_initializePgn61441ElectronicBrakeController1Buffer (counterpart of cm848_initializePgn61441ElectronicBrakeController1Buffer 0x25824)
- descriptor 0x803482: 0xf00100 | priority 0x803f90 & 7 << 2, SA, DLC 5, payload[0]=payload[2]=0xff (0x80347a / 0x80347c), data 0x80347a, status 0x803490. Nothing VP44.
- CM848 also sets payload byte 1 (0x3fad79) = 0xff -> one more store -> counterpart (strict rule).
- builder 0x32bbc (scheduled 61441 every 100 ms from 20) has no Ghidra function (lead).
- rows 0x80347a vp44_lift_pump_table_2_size / 0x80347c vp44_lift_pump_table_2_ptr are EBC1 bytes 1 / 3 (only the init writes them).

## 0x33164 -> cm550_buildPgn65263EngineFluidLevelPressure1Message (counterpart of cm848_buildPgn65263EngineFluidLevelPressure1Message 0x25eb4)
- scheduled 65263 every 500 ms from 130 + request responder. byte 4 (0x8034eb) = SPN 100 oil pressure = (sensor 4 filtered >> 7) x 6906 / 1000 >> 2 (4 kPa/bit). sends 0x8034da. Not VP44.
- CM848 also sends fuel delivery pressure etc. -> counterpart. global 0x8034eb j1939_pgn65263_engine_oil_pressure (no row).

## EC1 send-on-change family (shared EC1 code; CM848 names cm848_*)
- 0x3366a -> TWIN of CM848 0x1b730 cm848_sendPgn65251EngineConfiguration1Message: (status 0x803538 & 0xf0)==0 -> buildPgn65251EngineConfiguration1Payload(0x8034f2) -> send 0x80352a. CM848: lbz status / rlwinm 24,27 (0xf0) / bne / bl 0x1b3a0 / bl send. Both scheduled (0, 65251, 5000, 110). Both called at the end of the on-change test. Shared name sendPgn65251EngineConfiguration1Message.
- 0x334ec -> TWIN of CM848 0x1b778 cm848_sendPgn65251EngineConfiguration1OnChange: copy 28-byte payload to the previous copy (CM550 7x move.l 0x8034f2->0x80350e; CM848 lswi/stswi 16+12 0x3fa7f8->0x3fa814), rebuild, 12 compares in the same order W+0 B+2 W+3 B+5 W+6 B+8 W+9 B+0xb W+0xc B+0xe W+0xf B+0x1b (helper(previous, new)), first change -> send. No caller in either firmware (0 refs in CM550; no bl / pointer in CM848). Shared name sendPgn65251EngineConfiguration1OnChange.
- 0x333d6 -> cm550_hasWordIncreasedOrDroppedToZero (counterpart of cm848_hasWordChangedByTenPercent 0x1b624): previous==0 -> new!=0; else d = previous-new, when negative d = -previous-new (an ABS macro without parentheses), q = |d / previous| (divs.l), return q*10 >= 1. So 1 for any increase, a drop to 0, or a rise from 0; 0 for no change or a decrease to a non-zero value. CM848 computes |new-old| correctly and tests diff >= old or diff*10/old > 0 (the 10 percent rule) -> different code.
- 0x33460 -> cm550_hasByteIncreasedOrDroppedToZero (counterpart of cm848_hasByteChangedByTenPercent 0x1b69c): the same on bytes.
- CM848 rows to change: 0x1b730 -> sendPgn65251EngineConfiguration1Message, 0x1b778 -> sendPgn65251EngineConfiguration1OnChange.

## Remaining J1939 functions
- 0x33716 -> cm550_buildPgn65253EngineHoursRevolutionsMessage (standalone; CM848 has no 0xfee5): bytes 1-4 (0x803548) = byteSwap32(scaleByRatio(0x804fc0 TITMT2, 20, 36000)) (SPN 247, 0.05 h/bit from 0.1 s counts); sends 0x80353a. Registered by 0x33754 (pea 0x33716 / 0xfee5 / 0x2f47e at 0x337b0).
- 0x33754 -> cm550_initializePgn65253EngineHoursRevolutionsBuffer (standalone): descriptor 0x80353a 0xfee500 | priority 0x803f8c (e2m 1254 +3E JCEGTMPZ 'engine hours message (PGN FEE5)'), DLC 8, data 0x803548, status 0x803550, bytes 5-8 = 0xff; registers 0x33716. Called from cm550_diagnosticDataDump (0x2f55c).
- 0x337c4 -> cm550_buildPgn65262EngineTemperature1Message (counterpart of cm848_buildPgn65262EngineTemperature1Message 0x26024): byte 1 coolant (sensor 6 at 0x80a336: (v - 0x1900) >> 7 = deg F, (F x 5 - 160) / 9 = deg C, < -40 -> 0, >= 210 -> 250, else +40), byte 2 fuel temperature from vp44_fuel_temperature (0x80a188, e2m 801A +16 FLFLTP 'fuel temp measured by pump controller') >> 4 then the same, bytes 3-4 0xffff; sends 0x803552. Periodic (0, 65262, 1000, 430) + request (registered by 0x33880). CM848 has fault checks and oil temperature.
- 0x33a1e -> TWIN of CM848 0x26480 cm848_initializePgn65213FanDrive1Buffer: stw 0xfebd00 / priority & 7 << 2 / SA / DLC 2 / data / status - same 6 steps, same constants; 9th call of both J1939 inits; both builders scheduled (0, 65213, 1000, 50). Shared name initializePgn65213FanDrive1Buffer.
- 0x33a62 -> cm550_buildPgn65257FuelConsumptionMessage (standalone; CM848 has no 0xfee9): bytes 1-4 (0x8035a8) trip fuel SPN 182 = 0x804fa4 x 2/8 x 3785411/1000000 (0.125 gal -> 0.5 L), bytes 5-8 (0x8035ac) total fuel SPN 250 = (0x804fa0 >> 2) x 3785411/1000000; sends 0x80359a. Registered by 0x33aea (misnamed cm550_retarderConfigPGN_65249_Builder: it is the PGN 65257 init) at 0x33b2c.
- 0x33e58 -> cm550_buildPgn65270InletExhaustConditions1Message (counterpart of cm848 0x264d8): byte 2 (0x80360f) boost SPN 102 = scaleByRatio(sensor 5 0x80a320, 6906, 128000) >> 1, byte 3 (0x803610) intake manifold temperature SPN 105 from sensor 0 0x80a2b2 (same deg C + 40 clamp); sends 0x803600. Periodic (0, 65270, 500, 190) + request. CM848 adds fault checks.
- 0x33f5a -> cm550_buildPgn65264PowerTakeOffInformationMessage (counterpart of cm848 0x2bd58): bytes 4-5 (0x803629/0x80362a) byteSwap16(power_take_off_requested_engine_speed 0x80dc24) (SPN 187); byte 6 (0x80362b) 0xcc / 0xdc from 0x80bcd0 bit 4 (bits 5-6, SPN 978 remote variable speed) | 1 from 0x80bcd5 bit 4 DSPTONSW 'PTO on switch' (SPN 980); byte 7 (0x80362c) 0xcc/0xdc from DSPTRUSW bit 0 'PTO resume switch' (SPN 982) | 1 from DSPTSESW bit 2 'PTO set switch' (SPN 984); sends 0x803618. Periodic (0, 65264, 100, 150) + request. CM848 gates on power_take_off_enable and datalink switch sources.
- 0x341e6 -> cm550_initializePgn65249RetarderConfigurationBuffer (counterpart of cm848 0x2682c): 0xfee100 | priority 0x803f80, retarder SA 0x80da0b, DLC 19, data 0x803630, status 0x803652, then payload byte 19 (0x803642) = 0xff - CM848 has no payload store.
- 0x34232 -> cm550_buildPgn65248VehicleDistanceMessage (counterpart of cm848_j1939HandlePgn65248VehicleDistance 0x26bb0): bytes 1-4 (0x803662) trip distance SPN 244 = scaleByRatio(0x804fac TIMIT3, 12904, 64000) (0.015625 mi -> 0.125 km), bytes 5-8 (0x803666) total SPN 245 from 0x804fa8 TIMIT2; sends 0x803654. Registered by 0x3429a at 0x342dc. CM848 scales from speed sensor pulses.
- 0x34394 -> cm550_buildPgn65255VehicleHoursMessage (standalone; CM848 has no 0xfee7): bytes 5-8 (0x803696) total power take-off hours SPN 248 = scaleByRatio(0x804fbc TITMP2, 20, 36000); bytes 1-4 0xffffffff from the init 0x343d2; sends 0x803684. Registered by 0x343d2 at 0x3441c.
- 0x34440 -> cm550_initializePgn65260VehicleIdentificationBuffer (counterpart of cm848_initPgn65260VehicleIdHandler 0x26ddc): 0xfeec00 | priority 0x803f8e, DLC 20, data pointer 0x803e7f (the VIN text in the EEPROM image - spaces in the dump), status 0x8036aa; registers 0x34430 (pea 0x80369c / jsr send - no Ghidra function) for 65260. CM848 copies the VIN to a payload and adds '*', DLC 21.
- 0x344ce -> cm550_initializePgn65279WaterInFuelIndicatorBuffer (counterpart of cm848 0x26efc): 0xfeff00 | priority 0x803f94, SA, DLC 1, data 0x8036ac, status 0x8036c2. CM848 also writes payload bytes 2-8 = 0xff. Builder 0x34496 (not a Ghidra function): byte = 1 when 0x80bcf6 bit 2 (LCWFLP water in fuel lamp) else 0. Nothing VP44.
- 0x34d52 -> cm550_calculateWetStackTimingAdvance (standalone; CM848 has no wet stack algorithm): WSTA (0x80dee4, 1077 +0) = WSADTA (0x80dee8) when final_fueling <= WSMXLMFL (0x8071dc), else WSADTA - WSTARM (0x8071de) x (final_fueling - WSMXLMFL) / 100; floor WSTAMN (0x808ac4, 140A +0; 0x1bc = -8 deg). cm550_runEvery4FramesTaskSetPhase3 call 3 (20 ms). Base from 0x34cc4 (vp44_liftPumpFuelDeliveryController - wrong name), applied by cm550_applyWetStackTimingAdvance.

## Dump checks
- Trending table decodes: 100 records (TRNOSARQ 0x0064), TRNOSATN = TRSAIN = 24; records 0-2 at 35.5 / 70.4 / 107.6 h (2000-minute interval while < 3 samples), then every ~100 h (TRITTR = 100) from 10427 h to 12460 h; oil / boost / coolant 185-199 F / 2.25-3.75 GPH / load 23-36 %.
  Rows inside 0x804a1a-0x804f91 other than the 3 table bases: 35 rows, all 'undefined', none referenced (absolute) - bogus (old pass).
- 0x803ec2 part_number_list: the dump has the part numbers from 0x803ec5 (3945360100 ... 3945389800, 8 x 10 digits); the 10-byte unit number field 0x803ebb-0x803ec4 is spaces. Row is 3 bytes early.

## Leads (not in this batch)
- 0x30414 cm550_runTimeCountersUpdate = idle time (TIT2ISTM/TIT3ISTM + TITMIS copy) and idle fuel; 0x30454 ...Alt = PTO time (TIT3PTTM/TIT2PTTM + TITMP2) and PTO fuel.
- 0x30b04 cm550_protectionLimitValueInit = an empty interrupt handler (movem push / pop / rte).
- 0x31c1a cm550_j1939MessageSetup_PGN_65265 initializes PGN 65269 (AMB); 0x320f6 cm550_engineSerialNumberPGN_65259_Builder = CI init; 0x33aea cm550_retarderConfigPGN_65249_Builder = PGN 65257 init;
  0x3429a = PGN 65248 init; 0x343d2 vp44_vehicleHoursPGN_65255_Builder = PGN 65255 init (no VP44); 0x33880 = ET1 init; 0x33eee cm550_intakeManifoldPGN_65526_Builder = PGN 65270 init; 0x3401a cm550_cruiseControlPGN_65264_Builder = PGN 65264 init;
  0x34334 cm550_electronicBrakePGN_65527_Builder = PGN 65271 init; 0x342f0 cm550_retarderDataBuilder = PGN 65271 builder (battery voltage); 0x331ae vp44_engineFluidLevelPGN_65263_Builder = PGN 65263 init.
- Pointer-reached builders with no Ghidra function: 0x32bbc (EBC1, 61441), 0x339fe (FD1, 65213), 0x34496 (65279), 0x34430 (VI sender), 0x3229a (DM1 65226, inside DM11's range).
- 0x34cc4 vp44_liftPumpFuelDeliveryController = wet stack timing base (max of the IMT and coolant table lookups, state 1 / 13); 0x34c36 vp44FaultRegisterBit2Monitor = water in fuel lamp / fault.
- 0x80d2b4 can_transmit_buffer_ptr = e2m 11DC +4 SPTU 'value which determines alternate HP ratings' (written by cm550_updateElectronicSmartPowerTau: 0x4000 / cal / 0) - the ESP tau.
- 0x804a18 hour_meter_stored_ticks_cal lies inside the dword 0x804a16; 0x803698 governor_rpm_error_init_value inside the dword 0x803696.
- NAMING-RULE NOTE: the task text gives the CM550 EEPROM window both as 0x803b0a-0x804f93 (round 94) and 0x803B0A-0x804155; I used 0x803b0a-0x804f93 (round 94 renamed the trending rows to _cal on it).

## Struct proposal (for the applier)
trending_sample_record_t (14 bytes, 100 at 0x804a1a = trending_storage_table_cal, e2m 126E +0 TRSATB 1400 bytes):
 +0 word oil_pressure (sensor 4 filtered) / +2 word boost_pressure (sensor 5) / +4 word coolant_temperature (sensor 6) / +6 word average_fuel_consumption (TRAVFLCN) / +8 word average_load (TRLDINAV) / +10 dword time_stamp (engine_hour_meter & ~0xff | throttle_100_fueling >> 8)

## FINAL DECISIONS (all 29 named, none skipped)
0x30498 cm550_countEngineBrakeTime (standalone) | 0x306ca cm550_updateTripInformation (counterpart 0x523148) | 0x30a5e cm550_flagTripInformationPowerDownDataLoss (counterpart 0x523760) | 0x30b0e cm550_emptyStubFunction11
0x31496 cm550_evaluateTrendingTriggers | 0x315be cm550_runTrendingIntervalAndStoreSamples | 0x31a68 cm550_restartTrendingAfterEngineRebuild (all standalone)
0x31bce cm550_buildPgn65269AmbientConditionsMessage (cp 0x23e8c) | 0x31ed2 cm550_initializePgn65265CruiseControlVehicleSpeedBuffer (cp 0x24664) | 0x32052 cm550_buildPgn65259ComponentIdentificationMessage (cp 0x24870)
0x32c22 cm550_initializePgn61441ElectronicBrakeController1Buffer (cp 0x25824) | 0x33164 cm550_buildPgn65263EngineFluidLevelPressure1Message (cp 0x25eb4)
0x333d6 cm550_hasWordIncreasedOrDroppedToZero (cp 0x1b624) | 0x33460 cm550_hasByteIncreasedOrDroppedToZero (cp 0x1b69c) | 0x334ec sendPgn65251EngineConfiguration1OnChange (TWIN 0x1b778) | 0x3366a sendPgn65251EngineConfiguration1Message (TWIN 0x1b730)
0x33716 cm550_buildPgn65253EngineHoursRevolutionsMessage | 0x33754 cm550_initializePgn65253EngineHoursRevolutionsBuffer (standalone) | 0x337c4 cm550_buildPgn65262EngineTemperature1Message (cp 0x26024)
0x33a1e initializePgn65213FanDrive1Buffer (TWIN 0x26480) | 0x33a62 cm550_buildPgn65257FuelConsumptionMessage (standalone) | 0x33e58 cm550_buildPgn65270InletExhaustConditions1Message (cp 0x264d8)
0x33f5a cm550_buildPgn65264PowerTakeOffInformationMessage (cp 0x2bd58) | 0x341e6 cm550_initializePgn65249RetarderConfigurationBuffer (cp 0x2682c) | 0x34232 cm550_buildPgn65248VehicleDistanceMessage (cp 0x26bb0)
0x34394 cm550_buildPgn65255VehicleHoursMessage (standalone) | 0x34440 cm550_initializePgn65260VehicleIdentificationBuffer (cp 0x26ddc) | 0x344ce cm550_initializePgn65279WaterInFuelIndicatorBuffer (cp 0x26efc) | 0x34d52 cm550_calculateWetStackTimingAdvance (standalone)
Globals: see proposed_globals.txt (checked with check_globals.py; names unique). Enum TRIP_INFORMATION_ENGINE_STATE 0..3 for 0x80de64.
