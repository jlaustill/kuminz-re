# L4 judge notes (CM848 bare 'protection' names + 0x50e000)
Started 2026-11-25. No earlier judge run found (directory was empty).

Investigator vs describer: agree on 12/17 names. Differ on 0x1e4e8 (convert... vs apply...AsFuelLimit),
0x23a9c (...Tsc1RequestState vs ...StageSelectionState), 0x2c100 (GovernorTuningSet vs AllSpeedGovernorTuningSet),
0x4eeb8 (SwitchInputStates vs SwitchInputs); global 0x40aeea (main_injection_timing_before_misfire_limit vs
injection_timing_main_before_misfire_limit).

## Task sets (judge slots_judge.py decodes the 40-entry jump table at 0xc198 from ROM bytes)
- 0xbb68: call 4 of frames 2/10/18/26/34 (8-frame slot phase 2). Body bl 0x3f2b0 / 0x512ff4 / 0x4922c only.
- 0xbce8: call 5 of frames 4/14/24/34 (10-frame slot phase 4). Body bl 0x4bd5c only.
- 0xbeb4: call 5 of frames 8/28 (20-frame slot phase 8; 10-frame slot empty at phases 7-9). Body 0x375c8/0x37f28/0x49df0/0x49edc.
- 0xc050: call 5 of frames 18/38 (20-frame slot phase 18). Body 0x2c3c8/0x524594/0x529068.
- findptr: only bl from 0xc0a0, no pointers. PITC 4999; advanceHourMeters plate = 40 ticks of 5 ms.
- CM848 has no runEvery names (unique). CM550 round 93 slot style cm550_runEvery<N>FramesTaskSetPhase<M>. CONFIRM all 4.
## 0x1e4e8 -> CONFIRM cm848_convertTorqueDerateTorqueLimitToFuelLimit (pairs with L1's cm550_convertTorqueDerateTorqueLimitToFuelLimit,
   both L1 roles propose it). asm verified; xref_all: 0x40a2da read only here; 0x40a2d8 writers = caller 0x1e5fc + PTO 0x2a94c.
   Caller 0x1e5a4: override bit 0x10 of 0x3fd59e -> fuel = 0x3fd802, source 13, skip; else limit 0xffff, state 40, bl 0x4280c, bl 0x1e4e8.
## 0x1ea6c -> CONFIRM cm848_initializeFourDimensionalInjectionTimingLookupCaches. asm: li 2, sth 0x3fa878/7a/7c/7e; caller applicationMain 0x54994;
   caches passed only in cm848_calculateFourDimensionalInjectionTiming (cpp 20891-20915). Name free; pattern initialize<X>LookupCaches.
## 0x20b84 -> CONFIRM cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling. asm verified (0x5c352 1104 +A -> 0x40adb6; speed 0x40aec2 LSG ref
   -> 0x40adac; droop branch only if flags_12 bit 0x40 (clear in cal 0x2e06) and 0x40aeda != 0; 0x40aeda only store = 0 at 0x28b94 -> dead).
   Callers: jump table at 0x20e40 of 0x20d10: case 2 -> 0x20e64, case 3 -> 0x20ef0 (bl 0x20b84); plus 0x20bfc.
## 0x20bfc -> CONFIRM cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling. asm verified; cases 6 -> 0x20ff4, 7 -> 0x21080.
## 0x21c3c -> CONFIRM cm848_setThrottle100J1939TorqueCurveSpeedPoints. asm verified; caller 0x21cd4 ORs 0x3fa8ae (throttle 100 bit) into
   0x40a732 at 0x21d3c-0x21d48 then bl 0x21c3c; gated by bit 0x200 of 0x3fd5c0 clear. Points 1-5 speeds only.
## 0x23a9c -> CONFIRM cm848_initializeEngineRetarderTsc1RequestState (investigator), not the describer's StageSelectionState:
   all 9 stores belong to the J1939 retarder TSC1 path (e2m 10E5 +2 limit, 10E6 +0 mode, 10E6 +2 device, 13D8 cylinder counts "for J1939
   ret. map"); the stage quantizer cm848_selectEngineRetarderStagePercent is called by cm848_processEngineRetarderTsc1Request and reads the
   override mode. Only writer of stage count 0x3faa72 + caches 0x3faa7a-82. Distinct from cm848_initializeEngineRetarderRequestState (0x421c8,
   output chain) and resetEngineRetarderTsc1Request (125). CM550: 0x80d9ee never gets 100 (abs_refs: 125 / clr / copy) -> no twin.
   RAM: limit 100, mode 0, device 0, count 1 (ROM 0x5c47e = 1, rest 0), caches 2.
## 0x29e24 -> CONFIRM cm848_initializeInjectionTimingMainMisfireLimit. asm: 0x3fafa4/6 = 2, 0x40aeea = 0, 0x40aee8 = 0; caller applicationMain.
## global 0x40aeea -> CONFIRM main_injection_timing_before_misfire_limit i16 (e2m 8A3D +2 SOI_Before_MST, S, 0.1171875 DEG; line 7925).
   Stores: 0x29e40 (init) + 0x29f04 in the leaf 0x29ecc (after blr 0x29ec8; no bl/b/pointer, addrbuild finds no lis/addi of 0x29ecc). No reads.
   RAM 0. Describer's injection_timing_main_before_misfire_limit is equally valid; no reason to amend.
## 0x2c100 -> AMEND to cm848_initializeAllSpeedGovernorTuningSetBlendWeight (describer). Copies 0x3fd526 (1387 +8 ASG_Droop_Flag_Trim) to
   0x40af7c. All users of 0x40af7c are all-speed governor functions (calculateAllSpeedGovernorNoLoadFuel, calculateGovernorCompensatorCoefficients
   = 'the all-speed governor's two droop gains', blendAllSpeedGovernorReferenceSpeeds, calculateAllSpeedGovernorEquivalentThrottle). CM848 has
   low speed / high speed / PTO / road speed / fuel pressure governors, so the bare 'Governor' lacks the discriminator. RAM: 0x40af7c 128, 0x3fd526 0.
## 0x38a98 -> CONFIRM cm848_initializeFuelPressureGovernorFaultBlend. asm: 0x3fb3c2=2, 0x40b31e=0x40b320=5888, 0x40b322=0; all users = 0x3889c.
## 0x3eccc -> CONFIRM cm848_setTorqueManagementTransmissionType3Code (low/medium). stw 5 -> 0x3fb500 only; caller = type 3 branch of 0x3ecdc
   (cmpwi 3 at 0x3ed08 -> bl at 0x3ee94); 0x3f2b0 skips the evaluator for type 3 (0x3f2e8-0x3f2f0). transmission_type_cal only loaded (lha).
## global 0x3fb500 -> CONFIRM torque_management_transmission_type_3_code dword. Only access stw 0x3ecd4; no register-built base (addrbuild);
   no boot call (findptr) although inside the kernel image window (ROM source 0x5930); no e2m; next row 0x3fb504 -> no overlap. RAM 0.
## 0x4280c -> CONFIRM cm848_runFuelLimitChains (counterpart of cm550_runFuelLimitChains 0x30c3c: 7 shared steps in order; CM550 adds 17 / 33 +
   two undumped; CM848 adds 6). 13 bl verified; state codes match enums.csv; 105D +6/+8 = fuel_demand_minimum_tracked(_state).
## 0x4eeb8 -> CONFIRM cm848_initializeSwitchInputStates. lbzx 0x6456e[i] (j1939_switch_input_default_state_bits, arrays.csv, all 0) -> 0x40c050;
   bl 0x533e0 once; bl 0x4eb48 x4. Called at 0x54930, before the sensor channel initializers (0x54938..).
## 0x50e000 -> CONFIRM cm848_calculateEngineLoadLowHorsepowerCurvePercent. Only store 0x40af26 (10BF +4). Counterpart of CM550 0x26e2c
   (bls compares, x25600 shifts, divu.l, no clamp). Caller 0xbdd8 runs cm848_calculateEngineLoadPercentages first.
## global 0x40aee6 -> CONFIRM maximum_torque_at_current_engine_speed word. Writers 0x29db4/0x29dc8 (alpha/chi blend of maximum_torque_map lookups,
   0 -> 1), 0x29de8 (= 1), 0x1e514 (0 -> 1); readers 0x17ee8, 0x1e504/0x1e540, 0x20518. CHR e2m 1461 +0 MT_Max_Torque_At_RPM_Ftlb (U, min 1,
   'max torque at current rpm in foot-pounds'), not in CM848's table; CM550 0x80db1a = 1461 +0 (L1/L2 give it the same name). RAM 290.
## Plate checks: 0xbce8 '30-word block' OK (32-word job = command + address + 30 data words); 0x23a9c order OK (after 61440 / 65249 buffers);
   0x38a98 5888 x 0.067934784 = 400 mm3 OK; CM550 0x1c0d4 resets 0xffff / 0x28 at its end (0x1c140 / 0x1c148) OK.
   ERROR in the 0x3eccc plate: 'the one branch ... that sets neither the required flag nor the stage' - any transmission_type_cal value outside
   0-3 also returns without either (decompile: if != 3 return). Corrected comment in the verdict.
## No protection_* global in the 17 bodies (only hit: 0x20bfc's call to 0x20b84). skipped[] empty; nothing should be skipped.
