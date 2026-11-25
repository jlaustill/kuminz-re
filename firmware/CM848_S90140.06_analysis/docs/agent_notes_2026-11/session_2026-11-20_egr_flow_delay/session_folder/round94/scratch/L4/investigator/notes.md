# L4 investigator notes (CM848 bare 'protection' names + 0x50e000)

## Executive frame slots (from executiveFrameInterruptHandler @ 0xc0a0, decompiled switch)
Per frame: call 1 cm848_phase_common_processing (every frame), call 2 group_a (even) / group_b (odd),
call 3 = 4-frame slot (fuelFinal 0 / sensorProcessing 1 / controlLoop 2 / auxiliaryControl 3),
call 4 = 8-frame slot (canTx 0, sensors2 1, protection 2, timing 3, outputs 4, sensors 5, monitoring 6, communication 7),
call 5 = 10-frame slot (Group12 0, Group13 1, Group14 2, Group15 3, protection2 4, Group17 5, Group18 6; 7/8/9 empty),
call 6 = 20-frame slot (Group25 0 .. Group32 7, protection3 8, auxiliary 9, fuelDemand 10, Group36 11, Group37 12,
  Group38 13, diagnostics2 14, Group20 15, Group21 16, Group22 17, protection4 18, outputs2 19)
- cm848_periodicTaskSet_protection 0xbb68: frames 2, 10, 18, 26, 34 (every 8, phase 2). calls runTorqueManagement,
  cruiseControlPeriodicUpdate, filterEngineSensorValue
- cm848_periodicTaskSet_protection2 0xbce8: frames 4, 14, 24, 34 (every 10, phase 4). calls startEepromBlockRead
- cm848_periodicTaskSet_protection3 0xbeb4: frames 8, 28 (every 20, phase 8). calls calculateChargingVoltageTarget,
  monitorChargingSystemVoltageHighAndLow, updateFuelPressureFaultReactionRequests, applyFuelLimitsForFuelPressureFaults
- hpcr_periodicTaskSet_protection4 0xc050: frames 18, 38 (every 20, phase 18). calls updateSwitch31FromAcceleratorPedal,
  calculateEngineRetarderCruisePermissionPercent, monitorFuelSystemHardwareShutdown
CM550 round 93 slot style: cm550_runEvery<N>FramesTaskSetPhase<M> (plate: "Executive frame task set: runs every N frames ...")
TODO: verify by disassembly; check frame period.

## Verified by disassembly (slots.py on 0xc0a0 jump table, 40 cases)
- 0xbb68 call 4 of frames 2,10,18,26,34 ; 0xbce8 call 5 of frames 4,14,24,34 ; 0xbeb4 call 5 of frames 8,28 ;
  0xc050 call 5 of frames 18,38. Only callers (findptr.py: bl only, no pointers). Frame = 5 ms (PITC 4999,
  advanceHourMeters plate '40 PIT ticks of 5 ms'). => every 8 frames 40 ms / 10 frames 50 ms / 20 frames 100 ms.
- PLAN: slot names cm848_runEvery8FramesTaskSetPhase2 / cm848_runEvery10FramesTaskSetPhase4 /
  cm848_runEvery20FramesTaskSetPhase8 / cm848_runEvery20FramesTaskSetPhase18 (CM550 round 93 style; no CM848 'runEvery' names exist)

## Callers (findptr.py; all reached by bl)
1e4e8 <- arbitrateRequestedFueling 0x1e610 (right after processProtectionLimits 0x1e60c)
1ea6c <- applicationMain 0x54994 ; 29e24 <- applicationMain 0x54a64 ; 2c100 <- applicationMain 0x54a1c ;
38a98 <- applicationMain 0x54d28 ; 4eeb8 <- applicationMain 0x54930 ; 23a9c <- cm848_j1939_system_init 0x539278
20b84 <- updateProtectionInputs 0x20c08 + updateJ1939EngineConfigurationTorqueCurve 0x20e64/0x20ef0
20bfc <- updateJ1939EngineConfigurationTorqueCurve 0x20ff4/0x21080 ; 21c3c <- calculateJ1939TorqueCurveFuelingsAndReferenceFuelings 0x21d4c
3eccc <- evaluateTorqueManagementRequired 0x3ee94 ; 50e000 <- periodicTaskGroup28_calibration10 0xbde8

## 0x1e4e8 cm848_calculateProtectionRateLimited
fuel = no_load_fuel_quantity + torque_derate_torque_limit (1051 +A TQDQTQ ft-lb) x (throttle_100_fueling_without_programmable_power
(105A +8) - no_load) / 0x40aee6 (max torque lb-ft at current speed, MT_Max_Torque_Map lookup by cm848_calculateFuelDemandFilter;
clamped >= 1); clamp >= 0; if below torque_derate_fuel_quantity (105D +0 FSLMFL) store it + torque_derate_fuel_source_code =
torque_derate_torque_limit_state (1051 +C). Caller resets the torque limit to 0xffff / NO_DERATE BEFORE processProtectionLimits.
CM550 0x1c0d4: same formula via cm550_scaleByRatioSigned (jsr 0x35076) BUT resets 0x80d338=0xffff / 0x80d33a=0x28 at its END
(0x1c140/0x1c148) -> counterpart, not twin (CM848 resets in the caller at 0x1e5d0..).
  CM848 caller reset verified: 0x1e5fc sth 0xffff -> 0x40a2d8, 0x1e608 sth 40 -> 0x40a2da, then bl 0x4280c, bl 0x1e4e8.
  NAME PLAN: cm848_convertTorqueDerateTorqueLimitToFuelLimit (or ...apply...). 0x40aee6 'fuel_demand_filter_dimension' = max torque
  lb-ft at speed (e2m 1461 +0 MT_Max_Torque_At_RPM_Ftlb [MTMPRPFL] 'max torque at current rpm in foot-pounds' - block 1461 NOT in the
  dumped parameter ID table, so no address proof) -> lead only (not a protection_* global; written by cm848_calculateFuelDemandFilter 0x29c98).

## 0x4280c cm848_processProtectionLimits -> cm848_runFuelLimitChains (counterpart of cm550_runFuelLimitChains 0x30c3c)
disasm 0x42818..0x42848: bl 1f318 initializeFuelLimitChains, 2a918 applyPowerTakeOffTorqueLimit, e0c4 applyAirFuelControlFuelLimit,
502af4 applyAltitudeDerateFuelLimit, 509510 applyFaultDerateFuelLimit, 427cc applyTsc1TorqueLimit, 4279c applyFuelSystemDerateFuelLimit,
513ddc applyCoolantOverheatFuelDerate, 3f35c applyTorqueManagementFuelLimit, 4b9ac applyFuelLimitByRpmAndDemand, 3cefc applyNetTorqueFuelLimit,
519e2c limitFuelQuantityOnRailPressureShortfall, 3889c applyFuelPressureGovernorFaultBlend. CM550: same 7 shared steps in order +
cm550_applyAccelerationNoiseControlFuelLimit (17) + cm550_applyEngineWarmupProtectionFuelLimit (33) + 2 undumped -> counterpart.
Only caller arbitrateRequestedFueling 0x1e60c. Name unique (no runFuelLimitChains row in CM848).

## 0x50e000 cm848_validateFuelDemandRelativeToTiming -> cm848_calculateEngineLoadLowHorsepowerCurvePercent (counterpart of CM550 0x26e2c)
disasm: lhz 0x40a2ce final_fueling, lhz 0x40aeec no_load, lha 0x40a899 throttle_100_fueling_low_horsepower_curve (105A +2 FST0MXFL),
signed compares (ble), (final-no_load) x 25600 / (lowhp-no_load) via bl 0x571b0, clamp cmplwi 65280 -> 0xff00, sth 0x40af26
(e2m 10BF +4 Tau_0_Percent_Load [SPT0PCLD]). CM550 0x26e2c: unsigned bls compares, x25600 by shifts, divu.l, NO clamp -> counterpart.
Only caller cm848_periodicTaskGroup28_calibration10 (0xbde8; 20-frame slot phase 3), right after cm848_calculateEngineLoadPercentages.

## J1939 PGN 65251 torque curve point helpers (e2m 1102 / 1104 / 12BD / 12BB)
- 0x20b84 updateProtectionParameters -> cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling. disasm: r3 = lhz 0x5c352
  (1104 +A Jcomm_Derated_Fueling_at_Idle JCDQFLIS); speed = lhz 0x40aec2 (LSG reference speed, 1496 +10) unless bit 0x40 of
  algorithm_enable_flags_12_cal (low_speed_governor_droop_enable, lhz 0x3fd5b4) and lha 0x40aeda != 0: then lha 0x40aec2 -
  0x40aeda x 0x5c352 / 167, negative -> 0; sth 0x40adac (1102 +22 Jcomm_RPM_At_Point_1 JCTQRPP1), sth r3 0x40adb6 (1102 +2C
  Jcomm_Fueling_At_Point_1 JCTQFLP1). Callers: 0x20bfc, updateJ1939EngineConfigurationTorqueCurve cases 2/3 (derate cases).
- 0x20bfc updateProtectionInputs -> cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling. disasm: bl 0x20b84; if point 3 speed
  0x40adb0 < point 1 speed 0x40adac -> point 3 speed = point 1 speed, point 3 fueling = 0x40adb6; else point 3 speed = 0x5c34c
  (1104 +4 Jcomm_Engine_Speed_at_Point_3), fueling = 0x5c354 (1104 +C Jcomm_Derated_Fueling_at_Point_3); sth 0x40adba (1102 +30).
  Callers: updateJ1939EngineConfigurationTorqueCurve cases 6/7 (0x20ff4/0x21080).
- 0x21c3c updateProtectionThresholdsIfLow -> cm848_setThrottle100J1939TorqueCurveSpeedPoints. disasm: bit = 1 << lhz 0x5c33e
  (12BD +A Throttle_100_Priority); return when (0x40a732 (12BB +0 Active_Speed_Points_State) & ~bit) > bit (a higher priority
  request); else point 1 speed = 0x40aec2 + lha 0x5c334 (12BD +0 Jcomm_LSG_Ref_Speed_Offset) clamped >= 0, point 2 = 0x40a308
  (engine_speed_limit_ramped, HSG before droop speed), points 3/4/5 = 0x5c336/0x5c338/0x5c33a (12BD +2/+4/+6 Throttle_Speed_At_Point_3-5).
  Caller: calculateJ1939TorqueCurveFuelingsAndReferenceFuelings 0x21d4c (after it sets the throttle 100 request bit).
  Parallel of cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints (fault derate request).
Names checked unique in both frozen function_renames.csv.

## Boot initializers (applicationMain)
- 0x2c100 initProtectionLimitVariables -> cm848_initializeGovernorTuningSetBlendWeight. disasm: lhz 0x3fd526 (EEPROM 0xa4,
  e2m 1387 +8 ASG_Droop_Flag_Trim [ASDPFGTN] 'select droop source' = governor_tuning_set_default_blend_weight_cal) -> sth 0x40af7c
  (governor_tuning_set_blend_weight; the all-speed governor tuning set weight 0..128 written only here and in
  cm848_blendAllSpeedGovernorReferenceSpeeds). Caller applicationMain 0x54a1c (between initRpmSetpointFilters and initTimingFilterStates).
- 0x29e24 initProtectionFilterAccumulators -> cm848_initializeInjectionTimingMainMisfireLimit. disasm: 0x3fafa4/0x3fafa6 = 2
  (injection_timing_main_misfire_limit_cached_axis_offsets, the cache of cm848_calculateInjectionTimingMainMisfireLimit 0x29e50),
  0x40aeea = 0, 0x40aee8 = 0 (injection_timing_main_misfire_limit, e2m 8A3D +0 Misfire_Timing_Limit). Caller applicationMain 0x54a64.
  GLOBAL: 0x40aeea 'injection_timing_pid_init_flag' = e2m 8A3D +2 SOI_Before_MST [DEG, signed, 0.1171875] 'Desired SOI before being
  limited by misfire algorithm' (tool --address, parameter ID table). Writers: 0x29e40 (init 0) and 0x29f04 in UNREGISTERED code
  0x29ecc-0x29f38 (no bl / no pointer to it): if misfire_timing_limit_enable (0x3fd5ec bit 0x100) and 0x40a2f2 (103B +4 SOI_State) == 0:
  0x40aeea = lha 0x40a2f0 (103B +2 SOI); if limit 0x40aee8 > it: 0x40a2f0 = limit, 0x40a2f4 bit 0 cleared, 0x40a2f2 = 11.
  -> propose injection_timing_before_misfire_limit (i16). Lead: 0x29ecc uncalled code (dead in this build? no caller found).
- 0x38a98 initProtectionFilterLimits -> cm848_initializeFuelPressureGovernorFaultBlend. disasm: 0x3fb3c2 = 2 (safety_fuel_limit_cached_axis_offset),
  0x40b31e = 0x40b320 = 5888 (safety_fuel_blend_output / safety_blend_fuel_demand_prev; 5888 = 400 mm3 no limit), 0x40b322 = 0
  (safety_fuel_blend_fraction): all four are the state of cm848_applyFuelPressureGovernorFaultBlend 0x3889c (fuel limit chain step 13,
  code 62). Caller applicationMain 0x54d28. No e2m records for 0x40b31e/20/22. RAM dump: 0x0406 / 0x1700 / 0 / cache 2.
- 0x23a9c initGovernorProtectionState -> cm848_initializeEngineRetarderTsc1RequestState. disasm: 0x40ad62 = 100
  (engine_retarder_torque_limit_percent), 0x40ad5a = 0 (engine_retarder_override_control_mode, TSC1_OVERRIDE_OFF), 0x40ad5c = 0
  (engine_retarder_control_device_indicator, e2m 10E6 +2), 0x3faa72 = sum of ROM 0x5c47e..0x5c488 (the six engine brake driver
  cylinder counts, e2m 13D8..) = engine_retarder_stage_count, 0x3faa7a..0x3faa82 = 2 (stage 1..5 lookup caches of
  cm848_selectEngineRetarderStagePercent 0x234a4). Caller cm848_j1939_system_init 0x539278, right after the ERC1 (61440) and
  retarder configuration (65249) buffer inits. vs resetEngineRetarderTsc1Request 0x27118 (limit 125, timers cleared; no stage setup).
  RAM dump: limit 100 / stage count 1.
- 0x4eeb8 hpcr_initProtectionAndOutputCycle -> cm848_initializeSwitchInputStates. disasm: 4 bytes ROM 0x6456e
  (j1939_switch_input_default_state_bits, all 0) -> 0x40c050 switch_input_state_bits; bl 0x533e0 refreshInputLineImage once;
  bl 0x4eb48 scanAndDebounceSwitchInputs 4 times (its debounce needs 4 equal samples). Caller applicationMain 0x54930
  (first init after the power-down fault bits). Nothing about protection or outputs; no HPCR hardware -> cm848_.
- 0x1ea6c initProtectionTableSizes -> cm848_initializeFourDimensionalInjectionTimingLookupCaches. disasm: 0x3fa878/7a and 0x3fa87c/7e = 2
  (four_dimensional_injection_timing_map_a/_b_cached_axis_offsets, used only by cm848_calculateFourDimensionalInjectionTiming 0x1e870).
  Caller applicationMain 0x54994. Convention: cm848_initialize<X>LookupCache(s) (0x2156c, 0x3744c, 0x144d0).

## 0x3eccc setThermalProtectionMode5 (DEAD: unreachable under any calibration)
disasm: stw 5 -> 0x3fb500 (32-bit store). ppcrefs/baserefs: the only access to 0x3fb500..3 in ROM + flash2. RAM dump 0x3fb500 = 0.
No e2m record. Only caller: cm848_evaluateTorqueManagementRequired 0x3ee94, in its transmission_type_cal (lha 0x3fd934) == 3 branch
(0x3ed08 cmpwi 3); evaluate's only caller cm848_runTorqueManagement 0x3f304 is skipped when lha 0x3fd934 == 3 (0x3f2ec cmpwi 3 ->
limit 5888). transmission_type_cal is EEPROM, never written by the app -> body never runs. Nothing thermal.

## Task set call order (disasm): 0xbb68 bl 3f2b0 runTorqueManagement, 512ff4 cruiseControlPeriodicUpdate, 4922c filterEngineSensorValue
0xbce8 bl 4bd5c startEepromBlockRead ; 0xbeb4 bl 375c8 calculateChargingVoltageTarget, 37f28 monitorChargingSystemVoltageHighAndLow,
49df0 updateFuelPressureFaultReactionRequests, 49edc applyFuelLimitsForFuelPressureFaults ; 0xc050 bl 2c3c8 updateSwitch31FromAcceleratorPedal,
524594 calculateEngineRetarderCruisePermissionPercent, 529068 monitorFuelSystemHardwareShutdown. DECISION: slot names for all 4
(CM550 round 93 named single-callee sets by slot too: cm550_runEvery10FramesTaskSetPhase5 = runLampControl only). hpcr_ -> cm848_.

## GLOBALS (proposals)
- 0x40aeea injection_timing_pid_init_flag -> main_injection_timing_before_misfire_limit i16 (e2m 8A3D +2 SOI_Before_MST, S). HIGH
- 0x40aee6 fuel_demand_filter_dimension -> maximum_torque_at_current_engine_speed word. writers 0x29d84.. (calculateFuelDemandFilter,
  MT_Max_Torque_Map blend at filtered speed, >= 1), 0x29de8 (= 1); readers 0x17ee8, 0x1e500, 0x20518. RAM 290. CM550 same role
  0x80db1a = e2m 1461 +0 MTMPRPFL (cm550 tool). CM848 table lacks 1461. MEDIUM
- 0x3fb500 subsystem_init_code -> torque_management_transmission_type_3_code dword (stw 0x3ecd4 only access; RAM 0). LOW
RAM dump: 0x40aeda (governor_integrator_correction_term) 0 and only cleared (0x28b94) / read (0x20ba4, 0x507a84): the LSG droop
branch of 0x20b84 never applies in this build. Point 1 speed 6000 = LSG ref 6000; request flags 0x80 (bit 7 = throttle 100).

## LEADS
- 0x29ecc-0x29f38 uncalled unregistered code (misfire timing limit applied to 103B +2 SOI, source 11 = e2m label 0B MISFIRE;
  INJECTION_TIMING_INTERMEDIATE_SOURCE has no member 11).
- cm848_calculateFuelDemandFilter 0x29c98 / cm848_initFuelDemandFilterDimensions 0x29de0: misnamed (maximum torque at current speed).
- safety_* globals 0x40b31e/20/22/24/26 of the fault blend ('prev' abbreviation; 'safety' vague).
- other CM848 task sets could take slot names (table at top).
- stale old names in comments: global_variables rows 1457/1461/2260/4506/4507/5039/5044/5216/6090/335/338/8225/8226,
  structure_definitions 1853/2070, function_renames header line 19 + plates of 0x20d10/0x21cd4/0x3f2b0/0x49df0/0x533e0/0x538a84.

## FINAL NAMES (all 17; none skipped; no CM550 twin proven)
0xbb68 cm848_runEvery8FramesTaskSetPhase2 | 0xbce8 cm848_runEvery10FramesTaskSetPhase4 | 0xbeb4 cm848_runEvery20FramesTaskSetPhase8 |
0xc050 cm848_runEvery20FramesTaskSetPhase18 | 0x1e4e8 cm848_convertTorqueDerateTorqueLimitToFuelLimit |
0x1ea6c cm848_initializeFourDimensionalInjectionTimingLookupCaches | 0x20b84 cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling |
0x20bfc cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling | 0x21c3c cm848_setThrottle100J1939TorqueCurveSpeedPoints |
0x23a9c cm848_initializeEngineRetarderTsc1RequestState | 0x29e24 cm848_initializeInjectionTimingMainMisfireLimit |
0x2c100 cm848_initializeGovernorTuningSetBlendWeight | 0x38a98 cm848_initializeFuelPressureGovernorFaultBlend |
0x3eccc cm848_setTorqueManagementTransmissionType3Code (medium) | 0x4280c cm848_runFuelLimitChains |
0x4eeb8 cm848_initializeSwitchInputStates | 0x50e000 cm848_calculateEngineLoadLowHorsepowerCurvePercent
All checked unique in both frozen function_renames.csv. Globals: 0x40aeea / 0x40aee6 / 0x3fb500 as above.
