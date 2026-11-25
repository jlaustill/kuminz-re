# L4 describer notes (CM848 bare 'protection' names + 0x50e000)

## Task sets (executiveFrameInterruptHandler 0xc0a0, 40-case jump table on executive_frame_phase)
Slot layout seen in the disassembly (bl order per case; matches the decompile):
 call 1 cm848_phase_common_processing (every frame); call 2 group_a / group_b (every 2);
 call 3 fuelFinal / sensorProcessing / controlLoop / auxiliaryControl (every 4);
 call 4 canTx / sensors2 / protection / timing / outputs / sensors / monitoring / communication (every 8, phase 0..7);
 call 5 Group12..Group18 + protection2 (every 10, phase 0..6 + 4) and every-20 sets at phases 8/9 mod 10.
- 0xbb68 cm848_periodicTaskSet_protection: frames 2,10,18,26,34 (call 4) -> every 8 frames phase 2.
  Calls runTorqueManagement (0x3f2b0), cruiseControlPeriodicUpdate (0x512ff4), filterEngineSensorValue (0x4922c): no shared role.
  -> cm848_runEvery8FramesTaskSetPhase2
- 0xbce8 cm848_periodicTaskSet_protection2: frames 4,14,24,34 (call 5) -> every 10 frames phase 4. Calls only cm848_startEepromBlockRead (0x4bd5c).
  -> cm848_runEvery10FramesTaskSetPhase4
- 0xbeb4 cm848_periodicTaskSet_protection3: frames 8,28 (call 5) -> every 20 frames phase 8. Calls calculateChargingVoltageTarget 0x375c8,
  monitorChargingSystemVoltageHighAndLow 0x37f28, updateFuelPressureFaultReactionRequests 0x49df0, applyFuelLimitsForFuelPressureFaults 0x49edc.
  -> cm848_runEvery20FramesTaskSetPhase8
- 0xc050 hpcr_periodicTaskSet_protection4: frames 18,38 (call 5) -> every 20 frames phase 18. Calls updateSwitch31FromAcceleratorPedal 0x2c3c8,
  calculateEngineRetarderCruisePermissionPercent 0x524594, monitorFuelSystemHardwareShutdown 0x529068.
  -> cm848_runEvery20FramesTaskSetPhase18
Convention = CM550 round 93 cm550_runEvery<N>FramesTaskSetPhase<k>. Frame = 5 ms PIT tick (advanceHourMeters row). No twin: CM550 slots call other functions (counterpart by slot only).

## 0x1e4e8 cm848_calculateProtectionRateLimited
- Body: guard 0x40aee6 (fuel_demand_filter_dimension = max torque lb-ft at current speed, written by cm848_calculateFuelDemandFilter 0x29c98 from MT_Max_Torque_Map) 0 -> 1;
  fuel = no_load_fuel_quantity + torque_derate_torque_limit (e2m 1051 +A TQDQTQ ft-lb) x (throttle_100_fueling_without_programmable_power (105A +8) - no_load_fuel) / max torque; clamp >= 0;
  if fuel < torque_derate_fuel_quantity (105D +0 FSLMFL) -> lower it, source = torque_derate_torque_limit_state (1051 +C).
- Only caller cm848_arbitrateRequestedFueling 0x1e5a4 (when torque_derate_override_enable == 0): it sets torque limit 0xffff / NO_DERATE, calls 0x4280c (chain), then 0x1e4e8.
- CM550 0x1c0d4 (cm550_FUN_0001c0d4): same formula via cm550_scaleByRatioSigned with 0x80db1a = e2m 1461 +0 MTMPRPFL max torque at current rpm,
  same min-fold, PLUS resets torque_derate_torque_limit 0xffff / NO_DERATE at its end (CM848 resets in the caller): counterpart, not twin.
- Name: cm848_applyTorqueDerateTorqueLimitAsFuelLimit (siblings applyTsc1TorqueLimit / applyFuelSystemDerateFuelLimit / applyPowerTakeOffTorqueLimit).
- Global side note: 0x40aee6 fuel_demand_filter_dimension is the max torque at current speed (CM550 twin quantity 0x80db1a MTMPRPFL; CM848 block 1461 not in the dumped table).

## 0x1ea6c cm848_initProtectionTableSizes
- Body (asm 0x1ea6c-0x1ea90): stores 2 into both words of four_dimensional_injection_timing_map_a_cached_axis_offsets (0x3fa878) and _map_b_ (0x3fa87c).
- Those caches are read only by cm848_calculateFourDimensionalInjectionTiming 0x1e870 (the 4D timing maps a/b). Called once from cm848_applicationMain (boot list).
- Convention cm848_initialize<Thing>LookupCache(s) -> cm848_initializeFourDimensionalInjectionTimingLookupCaches. No protection content.

## 0x20b84 cm848_updateProtectionParameters (J1939 PGN 65251 torque curve point 1)
- point 1 speed (0x40adac, e2m 1102 +22 Jcomm_RPM_At_Point_1 'LSG Reference') = low_speed_governor_reference.reference_speed, less
  (0x40aeda droop term x j1939_derated_fueling_at_idle (1104 +A)) / 167 when algorithm_enable_flags_12_cal.low_speed_governor_droop_enable and term != 0; clamp >= 0.
- point 1 fueling (0x40adb6, 1102 +2C) = j1939_derated_fueling_at_idle (1104 +A JCDQFLIS 'fueling at idle ... when torque derate').
- Callers: cm848_updateJ1939EngineConfigurationTorqueCurve 0x20d10 cases 2 / 3 (altitude / air fuel control derate) and via 0x20bfc in cases 6 / 7.
- Name: cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling (sibling cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling 0x20c64).

## 0x20bfc cm848_updateProtectionInputs
- Calls 0x20b84 (point 1), then point 3: if point-3 speed < point-1 speed -> point 3 = point 1 (speed + fueling), else point 3 =
  j1939_engine_speed_at_point_3 (1104 +4) / j1939_derated_fueling_at_point_3 (1104 +C).
- Callers: 0x20d10 cases 6 / 7 (low speed governor outside idle band + derate).
- Name: cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling.

## 0x21c3c cm848_updateProtectionThresholdsIfLow
- bit = 1 << throttle_100_priority_bit_index (e2m 12BD +A Throttle_100_Priority); if (j1939_pgn65251_speed_points_request_flags (12BB +0) & ~bit) <= bit
  (no higher request bit set): point 1 speed = LSG reference + j1939_pgn65251_speed_at_point_1_low_speed_governor_offset (12BD +0, clamp >= 0);
  point 2 = engine_speed_limit_ramped; points 3/4/5 = Throttle_Speed_At_Point_3..5 (12BD +2/+4/+6). Speeds only, no fuelings.
- Only caller cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings 0x21cd4 (while programmable_power_enable == 0, after it sets the throttle 100 bit).
- Sibling with the same priority gate: cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints 0x507a20 (fault derate source).
- Name: cm848_setThrottle100J1939TorqueCurveSpeedPoints.

## 0x23a9c cm848_initGovernorProtectionState (engine retarder start-up)
- engine_retarder_torque_limit_percent = 100, engine_retarder_override_control_mode = TSC1_OVERRIDE_OFF, control device = NONE,
  engine_retarder_stage_count = sum of engine_retarder_driver_1..6_cylinder_count (e2m 13D8 Jcomm_EB_Driver_n_Num_Cyl),
  engine_retarder_torque_stage_1..5_cached_axis_offset = 2.
- Stage count + the 5 caches are read only by cm848_selectEngineRetarderStagePercent 0x234a4. Called once from cm848_j1939_system_init 0x539190.
- Siblings: resetEngineRetarderTsc1Request 0x27118 (run-time end of request: limit 125 + clears timers, no stage count / caches);
  cm848_initializeEngineRetarderRequestState 0x421c8 (output chain); cm848_initializeEngineRetarderTorqueLookupCache 0x2156c (ERC1 lookups).
- No governor, no protection. CM550: no counterpart found (its reset twin sets 0x7d; nothing sets 100 / a stage count in the dump).
- Name: cm848_initializeEngineRetarderStageSelectionState.

## 0x29e24 cm848_initProtectionFilterAccumulators (misfire timing limit start-up)
- asm 0x29e24-0x29e4c: injection_timing_main_misfire_limit_cached_axis_offsets (0x3fafa4) [0],[1] = 2; 0x40aeea = 0; injection_timing_main_misfire_limit (0x40aee8, e2m 8A3D +0 Misfire_Timing_Limit) = 0.
- Only caller: bl at 0x54a64 in cm848_applicationMain (boot). The cache is read only by cm848_calculateInjectionTimingMainMisfireLimit 0x29e50.
- No filter, no accumulator, no protection. Name: cm848_initializeInjectionTimingMainMisfireLimit (pairs with cm848_calculateInjectionTimingMainMisfireLimit).
- GLOBAL: 0x40aeea injection_timing_pid_init_flag = e2m 8A3D +2 SOI_Before_MST 'Desired SOI before being limited by misfire algorithm'.
  Writers: this init (0) and an unsplit leaf routine at 0x29ecc (inside Ghidra's 0x29e50 span; no bl / pointer / lis-addi reaches it):
  when misfire_timing_limit_enable and injection_timing_intermediate_source_code == 0 it stores main_injection_timing_copy (0x40a2f0) into 0x40aeea,
  then raises 0x40a2f0 to the misfire limit (clears bit 0 of 0x40a2f4, source 11). Loaded with lha (signed).
  -> proposed injection_timing_main_before_misfire_limit (i16). Not a pid, not a flag.

## 0x2c100 cm848_initProtectionLimitVariables
- One store: governor_tuning_set_blend_weight (0x40af7c; 0 = tuning set 1 .. 128 = set 2 of the all-speed governor) = governor_tuning_set_default_blend_weight_cal
  (0x3fd526, EEPROM mirror +0xa4, e2m 1387 +8 ASG_Droop_Flag_Trim 'select droop source').
- Boot only (cm848_applicationMain list). The weight is rewritten only by cm848_blendAllSpeedGovernorReferenceSpeeds 0x2bf6c and read by the ASG no-load fuel /
  compensator / equivalent throttle functions.
- Name: cm848_initializeAllSpeedGovernorTuningSetBlendWeight. No protection, no limit.

## 0x38a98 cm848_initProtectionFilterLimits
- safety_fuel_limit_cached_axis_offset (0x3fb3c2) = 2, safety_fuel_blend_output (0x40b31e) = 0x1700 (5888 = no limit), safety_blend_fuel_demand_prev (0x40b320) = 0x1700,
  safety_fuel_blend_fraction (0x40b322) = 0. Every one of these is used only by cm848_applyFuelPressureGovernorFaultBlend 0x3889c (code 62 fuel pressure governor fault blend).
- Boot only (cm848_applicationMain). No e2m records for these words.
- Name: cm848_initializeFuelPressureGovernorFaultBlend (pairs with cm848_applyFuelPressureGovernorFaultBlend).

## 0x3eccc cm848_setThermalProtectionMode5
- asm: li r11,5 ; stw r11,0x3fb500 (32-bit store; row subsystem_init_code is a word, hence _subsystem_init_code). Leaf, 4 instructions.
- Only call: cm848_evaluateTorqueManagementRequired 0x3ecdc, branch transmission_type_cal == 3 (calls it and returns without touching torque_management_required_flag).
- That branch cannot run: the only caller cm848_runTorqueManagement 0x3f2b0 skips the evaluator when transmission_type_cal == 3 (limit 0x1700 instead).
  transmission_type_cal (0x3fd934, EEPROM +0x4b2) = 3 in cm848_eeprom.bin (48RE), never written by the app.
- 0x3fb500: no other access (lis/D-form scan of ROM + flash2, decompile, e2m: none). RAM dump 0x3fb500 = 0 (dump base 0x3fa000 checked with 0x40aee6 = 290).
- No thermal, no protection. Output has no reader -> purpose not shown. Factual name at most: cm848_setTorqueManagementTransmissionType3Code (low).

## 0x4280c cm848_processProtectionLimits
- asm: 13 bl in order: initializeFuelLimitChains 0x1f318, applyPowerTakeOffTorqueLimit 0x2a918, applyAirFuelControlFuelLimit 0xe0c4, applyAltitudeDerateFuelLimit 0x502af4,
  applyFaultDerateFuelLimit 0x509510, applyTsc1TorqueLimit 0x427cc, applyFuelSystemDerateFuelLimit 0x4279c, then CM848-only cm848_applyCoolantOverheatFuelDerate 0x513ddc,
  cm848_applyTorqueManagementFuelLimit 0x3f35c, cm848_applyFuelLimitByRpmAndDemand 0x4b9ac, cm848_applyNetTorqueFuelLimit 0x3cefc, cm848_limitFuelQuantityOnRailPressureShortfall 0x519e2c,
  cm848_applyFuelPressureGovernorFaultBlend 0x3889c. Each step lowers torque_derate_fuel_quantity / source (or the torque limit for PTO).
- Only caller cm848_arbitrateRequestedFueling 0x1e5a4 (after it presets torque limit 0xffff / NO_DERATE), followed by 0x1e4e8.
- CM550 cm550_runFuelLimitChains 0x30c3c: same first 7 shared steps in the same order but adds 17 (acceleration noise) / 33 (warm-up) and two undumped calls,
  lacks CM848's six -> counterpart, not twin. Name: cm848_runFuelLimitChains (free in CM848).

## 0x4eeb8 hpcr_initProtectionAndOutputCycle
- Copies the 4 bytes j1939_switch_input_default_state_bits (ROM 0x6456e, all 0) into switch_input_state_bits (0x40c050, the 32 debounced logical switches),
  calls cm848_refreshInputLineImage 0x533e0 once, then cm848_scanAndDebounceSwitchInputs 0x4eb48 four times (its debounce needs 4 equal samples).
- Called once early in cm848_applicationMain (boot). No protection, no output cycle, nothing HPCR-specific.
- Name: cm848_initializeSwitchInputs (alt cm848_initializeDebouncedSwitchInputs).

## 0x50e000 cm848_validateFuelDemandRelativeToTiming
- engine_load_low_horsepower_curve_percent (0x40af26, e2m 10BF +4 Tau_0_Percent_Load SPT0PCLD 'Percent Load based on Low HP Torque curve', 1/256 %) =
  (final_fueling (1051 +0) - no_load_fuel_quantity (109C +0)) x 25600 / (throttle_100_fueling_low_horsepower_curve (105A +2 FST0MXFL) - no_load_fuel), clamped at 0xff00 (asm 0x50e068);
  0 when final fueling or the low hp curve fueling is not above the no-load fuel. No timing input at all.
- Caller: cm848_periodicTaskGroup28_calibration10 (frames 3, 23 = every 20 frames phase 3) right after cm848_calculateEngineLoadPercentages.
- CM550 cm550_calculateEngineLoadLowHorsepowerCurvePercent 0x26e2c: same records, same formula, same slot (cm550_runEvery20FramesTaskSetPhase3 right after
  cm550_calculateEngineLoadPercentages) but no 0xff00 clamp -> counterpart, not twin. Name: cm848_calculateEngineLoadLowHorsepowerCurvePercent.

## Extra checks (done)
- 0x23a9c is boot only: cm848_applicationMain -> cm848_initCanHardware 0x539868 -> cm848_j1939_system_init 0x539190 -> 0x23a9c.
- 0x20b84 / 0x20bfc / 0x1e4e8 / 0x50e000 asm re-read: decompile matches (0x20bfc compares the CURRENT point 3 speed 0x40adb0 with the new point 1 speed 0x40adac).
- No 'protection_*' global is touched by any of the 17 functions -> no protection_* global proposals. Two other misnamed globals found (0x40aeea, 0x40aee6), see above.
- CM550 has a misfire timing limit (grid 0x80794e, output 0x80a26e BSTAMNLM) but no 4D timing caches; its initializers were not identified.
## FINAL names
bb68 cm848_runEvery8FramesTaskSetPhase2 | bce8 cm848_runEvery10FramesTaskSetPhase4 | beb4 cm848_runEvery20FramesTaskSetPhase8 | c050 cm848_runEvery20FramesTaskSetPhase18
1e4e8 cm848_applyTorqueDerateTorqueLimitAsFuelLimit | 1ea6c cm848_initializeFourDimensionalInjectionTimingLookupCaches | 20b84 cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling
20bfc cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling | 21c3c cm848_setThrottle100J1939TorqueCurveSpeedPoints | 23a9c cm848_initializeEngineRetarderStageSelectionState
29e24 cm848_initializeInjectionTimingMainMisfireLimit | 2c100 cm848_initializeAllSpeedGovernorTuningSetBlendWeight | 38a98 cm848_initializeFuelPressureGovernorFaultBlend
3eccc (low) cm848_setTorqueManagementTransmissionType3Code | 4280c cm848_runFuelLimitChains | 4eeb8 cm848_initializeSwitchInputs | 50e000 cm848_calculateEngineLoadLowHorsepowerCurvePercent
