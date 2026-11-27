# Q3 investigator notes (round 96)

## 0x10e06 cm550_FUN_00010e06
- body: move.w (0x807ce4),d0; addq #4; move.w d0,(0x80aa8c = commanded_throttle_state.throttle_minimum); rts
- only caller: mc68k_applicationMain boot init (call @0x28782, between func_0x00042ad4 and cm550_initBoostProtectionSystem)
- 0x807ce4 = e2m 1048 +6 CTHISATH 'MAXIMUM THROTTLE_MIN THAT ANY VALID PEDAL CAN HAVE' (8-20 %); word (4 move.w reads: 0x10a50, 0x10c76, 0x10c94, 0x10e06); no row
- CM848 counterpart cm848_initializeCommandedThrottleState @0x17af4 does more (clears confidence counter, idle validation state, transition state, off idle, previous, delta filter) -> counterpart not twin
- CM848 global 0x5c294 accelerator_pedal_highest_valid_minimum is the same e2m record (1048 +6 Highest_Throttle_Min) -> use the same name for CM550 0x807ce4 (not EEPROM -> no _cal)
- proposal: cm550_initializeThrottleMinimum

## Cylinder balancing module (e2m 823C cal / 823D state; CM848 hpcr_cbd*)
- 0x1266e mc68k_FUN_0001266e: called from the 4 TPU ch10 primary speed ISRs (mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0..3, jsr at 0x19c64/0x19f5e/0x1a6c4/0x1a914).
  if CBDEN(0x8072c0)==1: if engine_speed_source_select(0x80cd18)!=0 -> CBDSBRF(0x8092e4)=0; else tooth=TPU_CH15_PARAM6(0xfffffc)&0xff (+36 when 0x80d0cf==1); tooth==CBDST(0x8072dc) -> clear sum 0x8002a6 (long), count 0x8002aa, index 0x8002a4=1;
  sum += main_engine_position_sensor_period(0x80d04a); count++; at count 4: index 6 -> store sum to slot 6 (0x80033a), copy 7 longs 0x800322.. clamped 0..150000 into CBDSB1..7 (0x8091ea..), slot0=slot6, CBDSBRF=1; else slot[index]=sum (index clamped 1..5), index++; clear count+sum.
  reads TPU register directly -> mc68k_ ok. CM848 counterpart hpcr_cbdFillAccelerationBuffers (TPU-A ch14 capture deltas, different code).
- 0x127c2 vp44_FUN_000127c2: executiveFrameInterruptHandler phase 38 (jsr 0x1be62) only. CM848 counterpart hpcr_cbdCalculateCylinderTrims (phase 3).
  outputs 0x80a1ac..0x80a1b6 = FLFLAJCn + trim*CBDATG/100 (6 words, no e2m, no abs reader - VP44 code likely in undumped 0x40000+). Not VP44 handling -> cm550_.
- 0x133fc: bare rts; one jsr from executiveFrameInterruptHandler phase 5 (0x1ba2e). other 4-byte hits are coincidental (move.w #1 / 33fc opcodes).
- 0x133fe vp44_FUN_000133fe: mc68k_applicationMain boot (jsr 0x28966). clears 0x8002a2, sets 4x16 dynamics compensation words to 10000, sets the 8 CBD lookup records' pointers, copies cyl_balance_trim_array_cal (0x804158, 6 words) into 0x8002d4. CM848 counterpart hpcr_cbdInitFilterState.
- 0x1277c cm550_fuelSourceMode11CountdownHandler (NOT my batch) is the CBD fueling filter: CBDFFL = fuel + (prev - fuel)*CBDFFCN/1000 -> lead.

## J1939 engine configuration percent torque (e2m 10DF / 10E2)
- 0x142d4 cm550_FUN_000142d4(speed, friction): TWIN of CM848 0x18070 cm848_calculateJ1939PercentPeakTorqueAtSpeed -> shared calculateJ1939PercentPeakTorqueAtSpeed.
  asm: rec 0x80d372 (4D SS fueling) x=arg1 (+6) y=400 (+0xe); jsr 0x35088 tableLookup2D; jsr 0x1e02a subtractAndClamp (-11776 offset, clamp 0..5888); d2=arg2+(0x80052c); (local-d2)*0x6400 (shift sequence 0x14316-0x14322 = x*25600); / (0x807d4c JCMXT0FL - 0x80bc88 JCFCBK04) via 0x1645e safeDivideWithClamp (= cm848_signedDivisionWithSaturation); returns d0 word.
  caller cm550_multiSpeedParameterInterpolation 0x143b6 (5 calls) = CM848 cm848_calculateJ1939PercentPeakTorquePoints 0x1820c (lead: twin, not my batch).
- 0x14348 cm550_FUN_00014348: TWIN of CM848 0x1811c cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints -> shared calculateJ1939FrictionLoadFuelingAtBreakpoints.
  asm 0x14348-0x143b4: record 0x80db20 (friction fuel by speed) x = LSRF 0x80db02 -> 0x80bc82 (10E2 +E); 0x807d50 (bp3) -> 0x80bc86 (+12); 0x807d52 (bp4) -> 0x80bc88 (+14); 0x807d54 (bp5) -> 0x80bc8a (+16); 0x807d4e (rated) -> 0x80bc84 (+10). CM848 same order (bl 0x55ef4 x5: 0x40a63e,42,44,46,40).
  callers: 0x1ddb4 (jsr 0x1de4e) + 0x143b6. CM848: 0x1ea94 + 0x1820c.
- 0x1ddb4 cm550_FUN_0001ddb4: TWIN of CM848 0x1ea94 cm848_initFaultSeverityTables (misnamed): SS 4D fueling (x/y offsets 2), transient 4D fueling (2/2), friction fuel by speed (2), friction coolant correction (2), then the friction-at-breakpoints call. CM550 also sets the record pointers (lookup convention, precedent initializeHighSpeedGovernorGainSet). boot: applicationMain jsr 0x2886c; CM848 boot line 59502.
- globals: 0x807d4e/50/52/54 only used by 0x14348, 0x143b6, cm550_diagnosticMessage46Builder -> CM848 names j1939_rated_speed_tau_0 / j1939_speed_breakpoint_3/4/5_tau_0 (current shutdown_protection_step_2 / _1 / engine_running_timer_threshold / frictional_load_torque_table_value are wrong).
  0x80bc82..8a -> CM848 j1939_friction_load_fueling_at_* names. 0x80052c (no row): coolant friction correction (only w 0x143d8 / r 0x1430a).

## 0x14812 cm550_FUN_00014812
- called by cm550_faultFlagScannerAndProcessor when diagnostic_clear_request_state bit 0 (CLEAR_INACTIVE) set. asm 0x14812-0x14870: if not_safe_to_program_flag (0x80dc92)==2: jsr 0x2fddc cm550_resetFaultStatus for each previously_active_dtc_list[1..count]; clr.b list count 0x8058f4; clr.w codes[0] 0x805954, 0x805996 inactive_fault_list_count, 0x80599a inactive_fault_j1587_reportable_count, 0x80de78 (FLT2ERAS); always clr.w 0x80de7a diagnostic_clear_request_state.
- CM848 counterpart cm848_clearDiagnosticState (more: OBD branch, clear active branch, freeze frames, switch learned flags; different gate).
- 0x80de78 = e2m 1080 +0 FLT2ERAS 'FAULT TO ERASE' -> CM848 name diagnostic_fault_to_erase (current fault_to_erase_none).

## 0x17baa cm550_FUN_00017baa
- called by cm550_engineModeTransitionHandler (0x17d2a) on entry to CRANKING / REENTRY, between cm550_frictionalLoadTorqueInterpolator and cm550_rpmSourceSelectorForFrictionalLoad.
- writes CKIITA 0x80d0a8 (105E +10 crank initial advance) and CKIITAES 0x80d0b4 (105E +1C) from IMT 0x80a2b2 (intake_manifold_temperature_sensor_state.filtered_value) between CKCDIMTP 0x807ef2 / CKHTIMTP 0x807ef0 (105F +8/+6) with CKCDIMTA/CKHTIMTA 0x807f00/0x807efe and CKCDIMES/CKHTIMES 0x807f04/0x807f02. Fault bits 13/14 (0x806000 & 0x806abc bit 0x2000/0x4000) = IMT high/low error (RAM dump: intake_manifold_temperature_sensor_config bytes 20/21 = 13/14) -> low values.
- CM848 counterpart cm848_calculateIntakeAirAdjustment 0x1bd74 (different boundaries T<=low / T>=high, slope formula; fault_detected_cal only).

## J1939 torque curve requesters (PGN 65251; e2m 12BA EPF / 12BB request flags / 12BD throttle 100)
- 0x185f0: TWIN of CM848 0x507c1c cm848_initializeFaultDerateJ1939TorqueCurvePriority -> shared initializeFaultDerateJ1939TorqueCurvePriority. asm: moveq #1; lsl.w (0x807f4a EPTQPZ),d0 -> 0x80060c; 0x8005fe.x_axis_offset=2; +2 ptr 0x807176; +8 ptr 0x8071a8. Both called by shared initializePgn65251EngineConfiguration1Buffer (CM550 line 35988 / CM848 19352).
- 0x184c6: counterpart of CM848 0x507a20 cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints (CM848 adds source 12 to the HSG source list and a 40000 cap on point 1; CM550: {2,1,4,5}, point1 only >=0; point 2 (max fuel - EPHSINFL)*8*slope/0x8888 + HSRFBEDP cap 40000). Both called by shared buildPgn65251EngineConfiguration1Payload. Gate 0x80d286 EPFLLMSS ==1 -> set bit; else clear bit.
- 0x183cc: counterpart of CM848 0x507858 cm848_applyFaultDerateToJ1939TorqueCurveFuelings (CM848 tests clamp mask & cm848_getHighestPriorityBit(); CM550 tests clamp mask 0x807f4c & request flags 0x80d0da). Lookup 0x8005fe (fault derate fuel limit by speed) at 0x80da38..40 -> clamp/set 0x80da42..4a.
- 0x1c824: counterpart of CM848 0x21c3c cm848_setThrottle100J1939TorqueCurveSpeedPoints (CM550 uses stored bit 0x8006e6 + clamps point 1 to 0xffff; CM848 recomputes bit, no upper clamp). point1 = 0x80db02 + JCLSRFOF 0x808010 (ext.l signed); point2 = 0x80d654 engine_speed_limit_ramped; 3..5 = PPTHES03..05 0x808014/16/18.
- 0x1c8a0: counterpart of CM848 0x21cd4 cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings (CM848: chi max fuel, reference fuelings, highest-priority-bit test, no bit clear when PP on). CM550: once bit 0x8006e6 = 1<<FSMXMNCG(0x80801c), flag 0x8006e8; PP off (0x803cb8&0x200==0): set bit, bsr 0x1c824, jsr 0x1cb76 cm550_calculateBlendedTableValue(point speed, 400) x5, clamp (0x80801a & flags) or set (highest); PP on: clear bit. Called from task set (line 16287).
- globals (CM848 names, same records): 0x807f42..48 EPRPP2..5 (no row) -> fault_derate_curve_engine_speed_point_2..5; 0x807f4a EPTQPZ -> fault_derate_curve_priority_bit_position; 0x807f4c EPTQCG -> fault_derate_curve_clamp_priority_mask; 0x80060c epf_source_bitmask -> fault_derate_torque_curve_priority_bit; 0x808010 JCLSRFOF -> j1939_pgn65251_speed_at_point_1_low_speed_governor_offset (i16); 0x808014/16/18 -> j1939_pgn65251_speed_at_point_3/4/5; 0x8006e6 -> throttle_100_speed_points_request_bit; 0x8006e8 -> throttle_100_speed_points_request_bit_initialized_flag; 0x80801a -> throttle_100_fueling_point_clamp_bitmap; 0x80801c -> throttle_100_priority_bit_index; 0x80d0da -> j1939_pgn65251_speed_points_request_flags; 0x80daf4 LSDPSE (no row) -> low_speed_governor_droop_selected_slope (i16, e2m S).

## 0x1c7a8 cm550_FUN_0001c7a8
- boot (applicationMain line 29558, after cm550_initializeElectronicSmartPower): sets double_pulsing_fueling_mapping_lookup (1D, x ptr 0x607d6, y 0x607e4, off 2), four_dimensional_injection_timing_steady_state_lookup (0x60a2a/0x60a52/0x60a74, 2/2), transient (0x60cd4/0x60cfc/0x60d1e, 2/2) = the three lookups of cm550_fuelDemandTableBlendCalculator (the 4D timing 4DTBTA).
- CM848 counterpart cm848_initializeFourDimensionalInjectionTimingLookupCaches 0x1ea6c (no double pulsing lookup) -> counterpart.

## Engine protection fault derate (e2m 10B1 / 10B3)
- 0x19702: task 2 of cm550_engineProtectionMultiStateSlowCycle40Coordinator (= CM848 cm848_runFaultDerateScheduler task 2 cm848_calculateFaultDerateFuelLimit 0x509540). CM550 loops the 9 channels (bits 0x70+4n / 0x1a0+n; configs 0x807032+36n, states 0x80d0dc+46n, severity 0x8057c0+30n), plus oil pressure power-up inhibit (oil_pressure_fueling_limiting_enable / oil_pressure_fault_inhibit_timer -> severity 0x100) which CM848 lacks; CM848 bits 0x80/0x1a4 (fuel temperature channel only). -> counterpart cm550_calculateFaultDerateFuelLimit (unique; sibling cm550_calculateFaultDerateEngineSpeedLimit 0x18e0c).
- 0x192e0: called once by vp44_engineProtectionSystemInit (after cm550_initShutdownLimitVariables). asm: move.w (0x8058ce EPSOAE engine_protection_active_fault_index) -> 0x80061e; clr.w 0x80061c engine_shutdown_command_flag_previous. processDiagnosticLimitStatus 0x19278: new shutdown on 0->1 edge: same channel as 0x80061e -> consecutive count+1 else 1. CM848 counterpart cm848_resetEngineProtectionShutdownState 0x508de8 (more steps) -> 0x80061e = CM848 engine_protection_power_up_shutdown_channel (i16).

## Engine position signal set-up dispatcher cm550_initializeEnginePositionSignalInputs (0x17150; jump table 0x17166 on engine_position_signal_configuration 0x807e9d)
- mode 0: 0x1999c (ch10, handler Mode0 0x19acc), 0x19ac2 (jsr 0x34674 wrapper, misnamed cm550_delayWithWatchdogServiceWrapper2), 0x19aca (empty, cm550_emptyStubFunction7)
- mode 1: 0x19caa (ch10, handler Mode1 0x19e90 - the dumped ECU's handler RAM 0x808f04), 0x19dd0 (ch0 PMM function 9, handler 0x19f82, ends jsr 0x34674), 0x19e8e (empty)
- mode 2: 0x1a350 (ch10, handler Mode2 0x1a52c; param1 = (0x807ec8 / 0x807ec0) << 8), 0x1a47c (ch0 function 9 param0 4, TPU_CH15_PARAM6 = 0xc000, priority 2, handler 0x1a6e8 which reads the PMM error type / tooth (CKSYERTY / CKSYERTT) from ch15 param 6; ends jsr 0x34674), 0x1a52a (empty)
- mode 3: 0x1a746 (ch10 if ESSXSNEN bit 0, handler Mode3), 0x1a89a (jsr 0x34674; rts - ROM-identical to 0x19ac2; 0x34674 returns at once for mode 3), 0x1a8a2 (empty)
- 0x19caa byte-identical to 0x1999c except the handler constant (0x19d42: move.l #0x19e90 vs 0x19a34 #0x19acc).
- empty stub names used in CM550: emptyStubFunction1,4,7,10,11 (+ deleted 2,3,9) -> new 12..15 free.

## EPS phase comparator 0x1a298
- byte-for-byte the same logic as 0x1a1e0 cm550_rpmTimingDeltaComparatorWithReturn (called by the 4 ch10 ISRs) except: gate 0x80aa18 (cm550_detectEngineSpeedSensorSyncPulse result for the backup sensor, 0x10386) vs 0x80aa16 (primary, 0x1037e); lost test ESTMCU01 0x80cd10 (main lost) -> ESBUIPER 0x80d297 = 1, vs ESTMCU02 0x80cd12 (backup lost) -> ESMNIPER 0x80d296 = 1. Edge difference ESPHDF 0x80d298 = ESBUEGTM 0x80d054 - ESMNEGTM 0x80d052 vs ESPLPHTD 0x807f58 / ESNGPHTD 0x807f5a, persistence ESMXPHCU 0x807f5c, counts ESPLPHCU 0x80d29a / ESNGPHCU 0x80d29c.
- NO caller in the dumped ROM (no jsr / bsr / bra / 4-byte pointer) and no pointer in the RAM / extended RAM / EEPROM dumps -> reached from the undumped 0x40000+ code or unused.

## TPU channel 1 (backup speed / cam) set-up, dispatcher cm550_canRpmModeConfigInit 0x1839a (misnamed) on EPCMSYTY 0x807f26 (11AD +2; dump 0)
- 0 -> 0x1b1ea (fills backup pulse table 0x80ceae like 0x1ae22; when ESSXSNEN 0x807ed4 bit 3: handler 0x808ee0 = 0x1b30a, CFSR3 ch1 function 0xd, param1 0x100, param0 0xb, HSQR1 3, HSRR1 3, CIER bit 1, priority 2). Dump: 0x808ee0 = 0x1b30a (active).
- 1 -> 0x1ae22 mc68k_initializeTpuChannel1BackupSpeedInput (clears cam sync state/status first; param0 0x4f; handler 0x1af32 = CI pulse width cam sync, misnamed mc68k_dutyCycleMonitorIsrHandler)
- 2 -> 0x1b39a (misnamed mc68k_dutyCycleMonitorBufferInit; handler 0x1b4b2, clears 0x80d2cc / 0x80d2d2)
- 0x1b30a (ISR, rte): if ESSXSNEN bit 3: ESTMCU02 0x80cd12 = reload 0x80d06e; period 0x80d04e = TPU ch1 param 4-5 (0xffff18); clear it; cam_cycle_reset_flag 0x80d0ce = 1; clear fault bit 0x800 of word 2 (0x806004) when first-occurrence 0x806044 bit clear (sr masked); copy period to 0x80ceae (backup ring first) and 0x80ccfc (EPS backup period); else clr param4. Then jsr 0x3478c mc68k_resetSpeedMeasurementMode0, jsr 0xc87e (empty), clear CISR bit 1.
- 0x1b4b2 (ISR, rte): only jsr 0x3478c, jsr 0xc87e, clear CISR bit 1.

## Engine protection fuel temperature input (e2m 81F9 / 81FA)
- 0x1cad6 (executive frame 15, between cm550_epsTimingCalculationSlowCycle40Coordinator and cm550_engineProtectionMultiStateSlowCycle40Coordinator; jsr 0x1bb96): if engine_protection_enable (0x803c98 bit 0x10) and (fuel temperature fueling 0x803ca4 bit 0x1000 or rpm limiting bit 0x2000): EPFTFG 0x80784a == 0 -> (fault bit 0x806024 bit 7 = fault 295 clear ? jsr 0x1cb48 : EPFLTPDF 0x807848) else ECM sensor ADFLTPFT 0x80a2c8 -> EPFLTP 0x80a254. No setter of 0x806024 bit 7 in the dumped ROM.
- 0x1cb3c: boot (applicationMain jsr 0x28902): EPFLTP 0x80a254 = ADDFFLTP 0x806afc (fuel temperature sensor config default).
- 0x1cb48: NOT empty (decompiler shows return;): d1 = ext FLFLTP 0x80a188 (VP44 fuel temp, signed 1/16 F) + 0x320 (50 F x 16), clamp 0..0x15e0, d0 = <<3 -> (T+50) x 128 = the ECM 0.0078125 / -50 scale (EPFLTP). Only caller 0x1cb26.
- globals: 0x80a254 EPFLTP (vp44_fuel_temperature_value undefined) -> engine_protection_fuel_temperature word; 0x80784a EPFTFG (dzg_pressure_max_limit - wrong) -> engine_protection_fuel_temperature_source word.

## 0x1cdf8 / 0x1dbd8
- 0x1cdf8: called by cm550_masterSubsystemInit 0x30c78 (boot). Sets throttle_100_fueling_low_horsepower_curve_lookup (SS 4D fueling table 0x6086e/0x6089a/0x608a4, offsets 2, y_input 400) and full_fueling_cold_temperature_fuel_increment_lookup (0x6124a/0x6125e/0x6126a, 2/2) = the two lookups only cm550_calculateThrottle100Fuelings uses. CM848 counterpart cm848_initFuelDemandTableDimensions 0x1f300 (only the 4D SS cache; called from cm848_initializeFuelDemandAndLimitInterpolationStates = counterpart of cm550_masterSubsystemInit).
- 0x1dbd8: boot (applicationMain line 29561, after the 4D timing lookups init, before cm550_initializeIdleShutdown): ZILMES 0x80d686 (10C4 +0 'OUTPUT ENGINE SPEED LIMIT GOING TO HSG REFERENCE SPEED ALG', e2m group 0x21 INJLIMIT 'INJECTOR FAULT SPEED DERATE GROUP') and 0x80def0 (no e2m) = maximum_rated_engine_speed (0x803f40). No other dumped code reads either or the 10C3 cal (0x808152/54/56) -> the algorithm is in the undumped 0x40000+ region. No CM848 counterpart (no injector fault speed derate records in CHR e2m).

## 0x1f4e8 J1922 handler
- mc68k_dispatchJ1708ReceivedMessages J1922 branch (MID 69..86 with algorithm_enable_flags_11 j1922 bit 0x4 of 0x803caa): jump table 0x163e8 on MID-74: 74 -> jsr 0x1f4e8 (0x163f8), 76 -> 0x1f84e, 79 -> 0x1f8bc (misnamed cm550_engineFluidLevelDataBuilder: same engine control pattern, source 0x4f), 81 -> 0x1fbb0.
- record = [length][MID][control]...: mode = control & 3; length must be 3/5/4/5 for modes 0..3; refreshEngineTsc1IgnoredRequestEntry(0,74,mode); findTsc1SourceConfiguration(0 = J1922 data link, 74); sets tsc1_override_control_mode etc; mode 1 speed = bytes 3-4 >> 1; mode 2 torque byte 3 << 8 -> fueling via JCMXT0FL/JCFCBK04 /0x6400; mode 3 speed limit byte 3 << 7 + signed torque limit byte 4 x 8; bits 2/3/4 retarder / high idle / driveline. TSC1 source table in the dump: all 5 entries data link 1 (J1939) -> J1922 control unconfigured here.
- CM848 has no J1922 -> standalone (J1939 analogue processEngineTsc1Request).

## DECISIONS (function names unique in both CSVs and the deleted lists; see proposed_functions.txt)
Twins: 0x142d4 = CM848 0x18070, 0x14348 = 0x1811c, 0x185f0 = 0x507c1c, 0x1ddb4 = 0x1ea94 (cm848_initFaultSeverityTables).
Counterparts: 0x10e06 0x17af4, 0x1266e 0x42bd0, 0x127c2 0x42d78, 0x133fe 0x43a5c, 0x14812 0x1d01c, 0x17baa 0x1bd74, 0x183cc 0x507858, 0x184c6 0x507a20, 0x192e0 0x508de8, 0x19702 0x509540, 0x1c7a8 0x1ea6c, 0x1c824 0x21c3c, 0x1c8a0 0x21cd4, 0x1cdf8 0x1f300, 0x1de58 0x1ec70, 0x1e04c 0x1ef30.
CM848-only renames: 0x1bd74 to cm848_calculateCrankInitialAdvanceByIntakeManifoldTemperature; 0x1ec70 to cm848_calculateFourDimensionalFueling.
Leads (not my batch): 0x1c640 cm550_diagnostic_parameter_handler twin of CM848 0x1e830 cm848_updateFourDimensionalFueling; 0x143b6 cm550_multiSpeedParameterInterpolation twin of CM848 0x1820c; 0x1277c cm550_fuelSourceMode11CountdownHandler is the CBD fueling filter; 0x17d2a cm550_engineModeTransitionHandler counterpart of cm848_processColdStartAdjustment 0x1bf44; 0x1839a cm550_canRpmModeConfigInit is the channel 1 set-up dispatcher on EPCMSYTY; 0x1ae22 0x1b39a 0x1af32 channel 1 names wrong; 0x19ac2 is a jsr 0x34674 wrapper; 0x1a1e0 is the main-pulse sibling of 0x1a298; 0x8002ac to 0x8002c3 CBD trim projections need asm reading.
GLOBALS: the CBD block 0x8002a2 to 0x80033f is private to 0x1266e, 0x1277c, 0x127c2, 0x133fe (every row 0 refs elsewhere). DFO1-6 are in firing order (cylinders 1 5 3 6 2 4) feeding outputs 0x80a1ac..0x80a1b6 for cylinders 1..6.
- added 0x8002ca/cc/ce/d0/d2 absolute values (asm 0x12e86-0x12fb6): |FRC1 low word|, |FIC1 low word|, |ARC2|, |AIC2|, |ARC3|; FM1 = min(15000, max(|FRC1|,|FIC1|)), FM2 = CBDMG2 x max(|ARC2|,|AIC2|) / 10, FM3 = CBDMG3 x |ARC3| / 10

## STATUS: analysis complete for all 37 functions; final output being composed (functions 37, globals 140, cm848_functions 2, skipped 0).
