# Q3 judge notes (round 96)
Started 2026-11-25. One entry per element as verified.

## 0x10e06 -> cm550_initializeThrottleMinimum CONFIRMED
asm: move.w (0x807ce4),d0; addq #4; move.w d0,(0x80aa8c) [=commanded_throttle_state+0xa throttle_minimum]; rts. Only caller mc68k_applicationMain jsr 0x28782.
CM848 0x17af4 sets throttle_minimum = accelerator_pedal_highest_valid_minimum+4 plus 6 more stores -> counterpart. Name unique.
Global 0x807ce4: e2m 1048 +6 CTHISATH (no row); refs word reads 0x10a50/0x10c76/0x10c94/0x10e06 -> accelerator_pedal_highest_valid_minimum word OK (CM848 0x5c294 same name).
## 0x1266e -> mc68k_fillCylinderBalanceSpeedBuffers CONFIRMED (plate: callers call it on every interrupt, it checks CBDEN itself)
asm 0x1266e-0x1277a read fully: CBDEN gate, ESSNSE!=0 -> clr CBDSBRF; tooth = TPU_CH15_PARAM6&0xff (+36 if CMSYFG==1) == CBDST -> restart; sum += ESIPPE 0x80d04a; every 4: slot[idx] (idx clamp 1..5) / idx 6 -> slot6 0x80033a, copy 7 longs clamp 0..0x249f0 to 0x8091ea.., slot0=slot6, CBDSBRF=1.
Callers: 4 ch10 handlers Mode0-3 (jsr 0x19c62/0x19f5c/0x1a6c2/0x1a912) unconditionally. Dump: ESTTIP=3, ESNOTTCU=34 (36-2 wheel) -> 4 periods x 3 teeth = 12 teeth = 120 deg OK. CM848 0x42bd0 different code -> counterpart. mc68k_ precedent (reads TPU param RAM: mc68k_alignCylinderIndexToCrankRevolution etc).
## 0x127c2 -> cm550_calculateCylinderBalanceTrims CONFIRMED
Decompiled body read in full (b127c2.txt). Frame 38 (case 0x26) once-per-40-frame slot. Outputs 0x80a1ac+2n = FLFLAJCn + trim[slot]*CBDATG/100: cyl1<-0x809246, cyl2<-0x80924e, cyl3<-0x80924a, cyl4<-0x809250, cyl5<-0x809248, cyl6<-0x80924c = firing order 1-5-3-6-2-4. No VP44 access -> cm550_. CM848 hpcr_cbdCalculateCylinderTrims different (4/6/8 cyl) -> counterpart.
## 0x133fc -> cm550_emptyStubFunction12 CONFIRMED (precedent emptyStubFunction10/11 with same plate style; 12-15 free)
4e75; only ref jsr 0x1ba2e frame-5 once-per-40 slot (case 5 extra call). Other 4-byte hits inside move.w #1 (33fc opcode).
## 0x133fe -> cm550_initializeCylinderBalancing CONFIRMED
body: clr 0x8002a2, 16x 10000 into 4 arrays, 8 lookup records set, copy 6 words 0x804158 -> 0x8002d4. Only caller mc68k_applicationMain. CM848 hpcr_cbdInitFilterState: seq counter 0xff, cached offsets, trims copy -> counterpart.
## Globals sweep (check_globals.py -> globals_check.txt)
- all 140 proposed names unique in CM550 globals + structs.
- CBD 823C/823D records: addresses/len/sign match e2m; refs all in 0x1266e/0x127c2/0x133fe.
- ISSUE 0x8002a6 dword swallows row 0x8002a8 fuel_timing_blend_rpm_input_1 (0 abs refs, 0 cpp uses, no RAM pointer) -> comment must say drop it (AMEND comment).
- inner rows of 0x800322/0x8002d4/0x8002e0/0x800300/0x8002d0: abs refs none except 0x80033a (slot 6 movea 0x12712), 0x8002e2/0x800302 (bin+1 bases in learning code) -> arrays OK, comments list them.
- 0x800320 found as a RAM value at 0x808118 = calibration HSACRFBP word pair (coincidence).
## 0x142d4 -> calculateJ1939PercentPeakTorqueAtSpeed TWIN of CM848 0x18070 CONFIRMED
asm: rec 0x80d372 (4D SS) x=arg1 y=400; tableLookup2D; cm550_subtractAndClampValue (+0xd200 i.e. -0x2e00 storage offset, clamp 0..0x1700 = CM848 clamp 0..0x1700); (v - (arg2 + 0x80052c)) * 25600 (shift sequence) ; cm550_safeDivideWithClamp(/ (0x807d4c - 0x80bc88)). CM848 same steps/constants. Callers 5x in 0x143b6 order idle, rated, bp3, bp4, bp5 = CM848 0x1820c order. Offset removal = table storage encoding.
## 0x14348 -> calculateJ1939FrictionLoadFuelingAtBreakpoints TWIN of CM848 0x1811c CONFIRMED
asm: rec 0x80db20 friction_fuel_by_engine_speed; LSRF 0x80db02->bc82, 7d50->bc86, 7d52->bc88, 7d54->bc8a, 7d4e->bc84 = CM848 order (LSG ref, bp3, bp4, bp5, rated). Callers bsr 0x143dc (twin parent) + jsr 0x1de4e (0x1ddb4).
## 0x14812 -> cm550_clearInactiveFaultsOnRequest CONFIRMED
asm 0x14812-0x14870: if not_safe_to_program_flag(0x80dc92)==2: cm550_resetFaultStatus each of previously_active_dtc_list, clr list count/0x805954/0x805996/0x80599a/0x80de78; always clr 0x80de7a (request word). Caller cm550_faultFlagScannerAndProcessor if (state & 1). CM848 cm848_clearDiagnosticState = superset -> counterpart.
## 0x17baa -> cm550_calculateCrankInitialAdvanceByIntakeManifoldTemperature AMENDED (comment only: exact global names _0_120/_50_to_293/_0_1000)
asm 0x17baa-0x17ca4: d2=ADIMTPFT 0x80a2b2 (filtered_value); status word0 bit 0x2000/0x4000 & enable mask 0x806abc -> low values; T<low -> low (0x807f00/0x807f04); T>high -> high (0x807efe/0x807f02); else ((hi-T)*low + (T-lo)*high)/(hi-lo). Only writer of 0x80d0a8/0x80d0b4. Caller bsr 0x17d56 in cm550_engineModeTransitionHandler (STOPPED->CRANKING / RUNNING->REENTRY), same slot as CM848 0x1bd74 in cm848_processColdStartAdjustment. CM848 code differs (no enable mask, <=/>=, slope) -> counterpart.
## CM848 0x1bd74 cm848_calculateIntakeAirAdjustment -> cm848_calculateCrankInitialAdvanceByIntakeManifoldTemperature CONFIRMED (only writer of crank_initial_advance / _break_speed; plate OK)
## 0x183cc -> cm550_applyFaultDerateToJ1939TorqueCurveFuelings CONFIRMED (counterpart CM848 0x507858)
asm: rec 0x8005fe lookups at 0x80da38..40 -> d6..d2; (EPTQCG 0x807f4c & flags 0x80d0da) != 0 -> min(current, derated) for 0x80da42..4a; else (flags & ~bit) <= bit -> write all five. CM848 tests mask vs cm848_getHighestPriorityBit -> different code. Only caller bsr 0x185d6.
## 0x184c6 -> cm550_calculateFaultDerateJ1939TorqueCurveSpeedPoints CONFIRMED (counterpart CM848 0x507a20)
asm 0x184c6-0x185ee: EPFLLMSS!=1 -> flags &= ~bit; else flags |= bit; if no higher: p1 = LSRF - LSDPSE*EPLSINFL/167 (LSDPEN bit6 of flags_12 & LSDPSE!=0; floor 0), p2 = ((FSMXBFDP - EPHSINFL)<<3)*HSDPSLAE/0x8888 + HSRFBEDP cap 40000 for HSRFST 1/2/4/5 else EPRPP2; p3-5 = EPRPP3-5; bsr 0x183cc (also when a higher request owns the points). First call of buildPgn65251EngineConfiguration1Payload in both firmwares. CM848 accepts source 12 and caps p1 -> counterpart.
## 0x185f0 -> initializeFaultDerateJ1939TorqueCurvePriority TWIN of CM848 0x507c1c CONFIRMED
asm: bit = 1 lsl.w EPTQPZ (68k register count mod 64 = CM848 &0x3f) -> 0x80060c; rec 0x8005fe offset 2 + axis/value pointers (record convention). Both are the first of the two closing calls of the shared initializePgn65251EngineConfiguration1Buffer.
## 0x192e0 -> cm550_initializeEngineProtectionShutdownCounting CONFIRMED (name narrow but accurate; 0x80061c = previous command AND latch: while set processDiagnosticLimitStatus holds engine_shutdown_command_flag=1 and skips channels; cleared while STOPPED)
asm: move.w EPSOAE 0x8058ce -> 0x80061e; clr.w 0x80061c; rts. Only caller vp44_engineProtectionSystemInit after cm550_initShutdownLimitVariables. 0x80061e read only by cmp at 0x1927e (consecutive count). CM848 0x508de8 superset -> counterpart.
Global 0x80061e engine_protection_power_up_shutdown_channel i16 OK (CM848 0x3fbd3a same name i16).
CM848 shared names claimed by the investigator all exist (script check).
## 0x19702 -> cm550_calculateFaultDerateFuelLimit AMENDED (comment: bit 0x1a0+n is algorithm_enable_flags_26_cal bit n = history-only (no derate), NOT restart; history-only channels are not floored and not in the maximum)
decompile read in full; helper semantics checked (ramp by config[3]); severity rec[2] = fueling restart severity index (EPCVFLRI 10B2 +4). Task 2 of coordinator (case 2). Only run-time writer of 0x800630 / 0x80d284 (init 0x19960 cm550_initShutdownLimitVariables, disabled path 0x18694).
## 0x19caa -> mc68k_initializeTpuChannel10PrimarySpeedInputMode1 CONFIRMED (diff vs 0x1999c: only handler 0x19e90; jsr at 0x1716e case 1)
## 0x1a350 -> mc68k_initializeTpuChannel10PrimarySpeedInputMode2 CONFIRMED (handler 0x1a52c; PARAM1 = (0x807ec8 / ESPECM01) << 8; case 2 jsr 0x17196)
## 0x1a47c -> mc68k_initializeTpuChannel0MissingToothInputMode2 CONFIRMED (vs 0x19dd0: PARAM0 4 vs 7, no PARAM2/4-6, CH15_PARAM6 = 0xc000, priority 2 vs 1, handler 0x1a6e8 vs 0x19f82; handler treats type 0xc0 as clear-sync-state (0) vs 2)
## 0x1b1ea -> mc68k_initializeTpuChannel1BackupSpeedPeriodInput CONFIRMED (EPCMSYTY 0 via 0x1839a; vs type 1 0x1ae22 (CI pulse width handler 0x1af32, PARAM0 0x4f, unconditional): ESSXSNEN bit 3 gate, PARAM0 0xb, HSQR 3, handler 0x1b30a; dump 0x808ee0 = 0x1b30a)
## 0x1b30a -> mc68k_tpuChannel1BackupSpeedPeriodInterruptHandler AMENDED comment: clears only PARAM4 (clr.w 0xffff18), copies the period into ESPSTB02[0] 0x80ceae and AVERAGE_PULSE_PERIOD_BACKUP 0x80ccfc (not 'the EPS backup period', which is 0x80d04e itself)
## 0x1b4b2 -> mc68k_tpuChannel1SpeedMeasurementResetInterruptHandler CONFIRMED (jsr 0x3478c, jsr 0xc87e (empty rts), clr CISR bit1, rte; installed by 0x1b39a at 0x1b48e, only pointer 0x1b490)
## 0x1a298 -> cm550_checkEnginePositionSensorPhaseOnBackupPeriod CONFIRMED (medium; no reference in ROM / RAM / ext RAM, no relative branch)
asm vs 0x1a1e0: identical logic with a0/a2 swapped; gate 0x80aa18 (backup sync pulse result, 0x10386 in cm550_detectEngineSpeedSensorSyncPulse) vs 0x80aa16; lost shortcut ESTMCU01==0 -> ESBUIPER=1 vs ESTMCU02==0 -> ESMNIPER=1. Outputs/thresholds e2m 12A1/12A2 checked.
## 0x1a89a: jsr 0x34674; rts (same bytes as 0x19ac2). 0x34674 acts only for configuration 0/1 -> no-op in configuration 3. Decide naming at end.
## 0x1cad6 -> cm550_selectEngineProtectionFuelTemperature CONFIRMED (cm550_ ok: engine protection input selector; pump value only via the converter). Frame 15 before the coordinator ✓. Plate uses EPFLTPDF short name (actual ..._40_to_300) -> amend comment names.
## 0x1cb3c -> cm550_initializeEngineProtectionFuelTemperature CONFIRMED (move.w 0x806afc -> 0x80a254; mc68k_applicationMain)
## 0x1cb48 -> vp44_convertPumpFuelTemperatureToSensorScale CONFIRMED: (FLFLTP + 800) clamp 0..5600, <<3 in d0 = (T+50)*128; only caller jsr 0x1cb26.
## 0x1c7a8 -> cm550_initializeFourDimensionalInjectionTimingLookups CONFIRMED (3 records used only by cm550_fuelDemandTableBlendCalculator; CM848 0x1ea6c caches a/b only -> counterpart)
## 0x1cdf8 -> cm550_initializeThrottle100FuelingLookups CONFIRMED (2 records used only by cm550_calculateThrottle100Fuelings; y_input 400; caller cm550_masterSubsystemInit; CM848 0x1f300 one cache -> counterpart)
## 0x1ddb4 -> initializeFourDimensionalFuelingAndFrictionFuelLookups TWIN of CM848 0x1ea94 CONFIRMED (asm 0x1ea94: sth 2 x2 SS, x2 transient, friction 0x40aef8, coolant 0x40aefa, bl 0x1811c; CM550 same order + record pointers, jsr 0x14348; both applicationMain)
## 0x1dbd8 -> cm550_initializeInjectorFaultEngineSpeedLimit CONFIRMED (ZILMES 0x80d686 + 0x80def0 = 0x803f40; no reader in dump; plate name maximum_rated_engine_speed -> actual _0_5000)
## 0x1e04c -> cm550_initializeFourDimensionalFuelingInterpolationFactor CONFIRMED (CM848 0x1ef30 superset -> counterpart)
## 0x1c824 -> cm550_setThrottle100J1939TorqueCurveSpeedPoints CONFIRMED (asm 0x1c824-0x1c89e; bsr from 0x1c8ec only; CM848 0x21c3c builds bit itself, floor only)
## 0x1c8a0 -> cm550_calculateThrottle100J1939TorqueCurveFuelings CONFIRMED (asm 0x1c8a0-0x1c9d0; caller cm550_runEvery20FramesTaskSetPhase14 jsr 0x1b828; CM848 0x21cd4 adds reference fuelings + highest-bit test -> counterpart)
## 0x1de58 -> cm550_calculateFourDimensionalFueling CONFIRMED; CM848 0x1ec70 same structure but filtered throttle / filtered speed and NO 5DFLAJ increment -> counterpart.
## CM848 0x1ec70 cm848_calculateDualAxisFuelLimit -> cm848_calculateFourDimensionalFueling CONFIRMED (returns the 4D fueling stored in four_dimensional_fueling by cm848_updateFourDimensionalFueling; not a limit). Old name cited in 3 function_renames + 4 global comments (follow-up).
## 0x1f4e8 -> cm550_processJ1922EngineControlRequestFromSource74 CONFIRMED (jump table 0x163e8: MID 74 -> 0x1f4e8 only; modes 1-3 set engine_control_device_indicator = 1 = TRANS (JCEGCOID); MID 79 handler sets 2 = ABS; plate accurate)
## Remaining function decisions
- 0x1a89a cm550_initializeSpeedMeasurementMode3 CONFIRMED (slot name, plate says no-op in configuration 3)
- plates with truncated global names -> AMENDED comments: 0x17baa, 0x1a350, 0x1a47c (+0xc0 meaning), 0x1b30a (+PARAM4 / ESPLAVBU), 0x1cad6, 0x1dbd8 (+no code reference)
- 0x1266e AMENDED comment (gate inside); 0x19702 AMENDED comment (history-only bit 0x1a0+n)
## Global decisions
- 0x8002aa AMENDED name cylinder_balance_segment_period_count (counts periods = interrupts, not teeth; investigator's own comment says periods)
- 0x8002a6 AMENDED comment (drop row 0x8002a8)
- 0x80d340 AMENDED comment (writer cm550_updateElectronicSmartPowerTau at 0x1addc: alpha = 0x4000 - tau)
- 0x80da38 AMENDED comment ('VP44 derate code' is wrong: 0xfa06/0xfa68/0xfaa6 are helpers of vp44_fuelLimitExceedanceStatisticsAccumulator 0xfb26 = 2nd call of buildPgn65251EngineConfiguration1Payload = torque curve update; names not evidence)
- all others CONFIRMED
## CM848 0x1ea94 caller cm848_applicationMain line 59502 ✓; CM550 0x1ddb4 caller mc68k_applicationMain line 29651 ✓
## FINAL (2026-11-25): verdict JSON built by make_function_verdicts.py (function_verdicts.json) + make_global_verdicts.py (global_verdicts.json)
- CM550 functions: 28 CONFIRMED, 9 AMENDED (comments: 0x1266e, 0x133fc, 0x17baa, 0x19702, 0x1a350, 0x1a47c, 0x1b30a, 0x1cad6, 0x1dbd8)
- CM848 functions: 2 CONFIRMED; globals: 136 CONFIRMED, 4 AMENDED (0x8002aa name, 0x8002a6 / 0x80d340 / 0x80da38 comments)
- skipped[] empty; no prototypes / enum members proposed.
