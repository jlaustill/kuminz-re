# Q3 describer notes (round 96)

Helper scripts here: callers.py (callers by name + ROM 4-byte hits), names.py (function_renames lookup).

## 0x10e06 cm550_FUN_00010e06
- Body: move.w (0x807ce4),d0; addq #4; move.w d0,(0x80aa8c) = commanded_throttle_state.throttle_minimum (+0xa); rts.
- 0x807ce4 = e2m 1048 +6 CTHISATH 'MAXIMUM THROTTLE_MIN THAT ANY VALID PEDAL CAN HAVE' (8-20) = CM848 accelerator_pedal_highest_valid_minimum (0x5c294, same record). No row in CM550. Not in EEPROM window -> no _cal.
- One caller: mc68k_applicationMain jsr at 0x28780 (boot step, between cm550_emptyStubFunction11 0x30b0e/0x42ad4 and cm550_initBoostProtectionSystem).
- CM848 counterpart: cm848_initializeCommandedThrottleState @0x17af4 sets throttle_minimum = highest_valid_minimum + 4 AND clears confidence counter / idle validation / transition / off idle / previous / delta filter. CM550 only does the one store -> counterpart, not twin.
- Same expression also used in the CM550 throttle validation at 0x10a50 on a pedal fault (as CM848 cm848_runThrottleValidation's fault branch).
- Proposed: cm550_initializeThrottleMinimum; global 0x807ce4 accelerator_pedal_highest_valid_minimum (word, shared name with CM848 0x5c294).

## Cylinder balance cluster (e2m 823C cals 0x80728c-0x8072f2, 823D state 0x8091e8-, 823E/823F tables, 8241 EEPROM trims)
### 0x1266e mc68k_FUN_0001266e = fill the cylinder balance speed buffers (EPS interrupt)
- Called (jsr abs) by the 4 TPU channel 10 primary speed interrupt handlers (modes 0-3) at 0x19c62/0x19f5c/0x1a6c2/0x1a912.
- Gate: CBDEN 0x8072c0 (823C+34) == 1; engine_speed_source_select 0x80cd18 == 0 else clears CBDSBRF 0x8092e4.
- tooth = TPU_CH15_PARAM6 (0xfffffc) & 0xff, +36 when flag_indicating_crank_rev_1_or_2_of_cam_rev (0x80d0cf) == 1; == CBDST 0x8072dc (823C+50 START TOOTH) restarts: sum 0x8002a6 (long) = 0, tooth count 0x8002aa = 0, segment index 0x8002a4 = 1.
- every call: sum += main_engine_position_sensor_period (0x80d04a); count++; at count 4: index<6 -> slot[index] (7 longs at 0x800322) = sum, index++ (index clamped 1..5); index==6 -> slot[6] = sum, copies the 7 slots clamped 0..150000 into CBDSB1..7 (0x8091ea.., 823D+2..+1A), slot[0] = slot[6], CBDSBRF = 1, index = 1. Then count = 0, sum = 0.
- Reads an MC68336 TPU parameter word -> mc68k_ is defensible by the rule.
- CM848 counterpart: hpcr_cbdFillAccelerationBuffers @0x42bd0 (called in the crank tooth ISR; same start-tooth gate, but takes TPU-A ch14 timestamp differences / 4 per event into the acceleration buffer directly). Not twin.
- Proposed: mc68k_fillCylinderBalanceSpeedBuffers.

### 0x127c2 vp44_FUN_000127c2 = cylinder balance trim calculation (once per 40 frames, frame 38, jsr at 0x1be60)
- CBDEN gate. When CBDSBRF: new-data flag 0x80033e = 1; accelerations CBDAXB1..6 (0x809284.., longs) = SB[i]-SB[i+1] with interrupts masked (ori #0x700,sr); Fourier: FRC1 0x809206 = (A1+A5-A2-A4)/2 - A3 + A6; FIC1 0x80920a = (A1+A2-A4-A5)*866/1000; FRC2 0x80920e = -(A1+A2+A4+A5)/2 + A3 + A6; FIC2 0x809212 = (A1+A4-A2-A5)*866/1000; FRC3 0x809216 = A2+A4+A6-A1-A3-A5 (same formulas as CM848 hpcr_cbdCalculateCylinderTrims, which filters them).
- active trim gain CBDATG 0x8092e2 = 2D stop compensation table(rpm, CBDFFL 0x8091e8) capped 100; |rpm change| 0x8002c8, previous rpm 0x8002c6; stop compensation flag CBDSCF 0x80922e = 1 if gain<100 or change>CBDDST or no new data or not RUNNING.
- adjusted comp 2 CBDARC2/CBDAIC2 (0x809276/8) = 10000 + FFT comp2 - dynamics compensation table(rpm), clamped +-10000; speed bin 0x800320; while motoring (CBDFFL<=CBDMFT, final_fueling 0, CBDLSL<rpm<CBDUSL, RUNNING) learns tables 0x809e9e / 0x809ebe at bin and bin+1 (from copies 0x8002e0 / 0x800300, x (1 - CBDEFCN/10000)); CBDDCR reset sets all 4 x 16 to 10000.
- comp 3 adjustment CBDC3ADJ 0x8092e0 = 2D table - 10000; CBDARC3 0x80927a = FRC3 low word - adjustment.
- trim indexes CBDTI1/2/3 (0x809260/2/4) = argmax of 6 projections on the reference vectors (CBDR1Cn / CBDR2Cn; scratch longs 0x8002ac-0x8002c3) / sign of CBDARC3 vs CBDR3.
- magnitudes CBDFM1..3 (0x809232/4/6, capped 15000, x CBDMG2/3/10); FFT threshold CBDFT 0x809230 = 1-D table(rpm); trim increments CBDTINC1..3 (0x80926e/70/72) = trim gain n (CBDTGn low word) or the small gain (CBDTGnS).
- cutout delay 0x800220 counts down, reloaded with CBDDSTM 0x8072ee while any FLCnENFG (0x80a21a..) is 0.
- trim adjustments CBDTA1..6 (0x809252..) = pattern rows (ROM 0x12596 / 0x125de / 0x12626) x increments when CBDCEN, no stop, cam sync, delay 0, road speed <= CBDVSTD, coolant > CBDCLTP, IMT > CBDIMTP; else 0.
- trims CBDDFO1..6 (0x809246..) = adjustments + saved trims cyl_balance_trim_array_cal (0x804158, 8241 'CBD ONTIME TRIM, SAVED AT POWER-DOWN'); outside CBDFTMX/CBDFTMN -> CBDTLE 0x80925e; limit mode CBDLMMD 1 = restore power-up snapshot 0x8002d4, 2 = zero; CBDCEN 0 -> 0; mean removed; written back to 0x804158.
- outputs 0x80a1ac..0x80a1b6 (6 words, cylinder-number order, in the 801A pump block gap) = FLFLAJCn (0x80782c..) + trim[firing slot 1,5,3,6,2,4] x CBDATG / 100 (0 during the cutout delay). No absolute reader in the dumped ROM.
- clears CBDSBRF at the end.
- CM848 counterpart: hpcr_cbdCalculateCylinderTrims @0x42d78 (frame 3 once-per-40 call): same FFT formulas, but filters components, 4/6/8 cylinders, no speed-binned tables. Not twin.
- Does not touch the VP44 link itself -> cm550_. Proposed: cm550_calculateCylinderBalanceTrims.

### 0x133fc cm550_FUN_000133fc = empty (rts)
- Only real call: jsr at 0x1ba2c, frame 5 of executiveFrameInterruptHandler, the once-per-40-frames slot after cm550_runEvery20FramesTaskSetPhase5 (other ROM 4-byte hits 0x139c8/0x16d92/0x1f648/0x1fa16 are inside move.w #1,(abs) instructions, not pointers).
- Sits between the cylinder balance calculation (0x127c2) and its initializer (0x133fe). Many CBD e2m records (FFT trending tables CBDFTTB1-5, trend reset CBDTR, iteration/cycle counts) have no code reference -> could be a compiled-out step, but an empty body proves nothing.
- Proposed: positional empty-stub name only (cm550_emptyStubFunction12), low.

### 0x133fe vp44_FUN_000133fe = cylinder balance start-up initializer
- One caller: mc68k_applicationMain jsr at 0x28964.
- clr.w 0x8002a2 (no other reference); sets the two dynamics compensation tables (0x809e9e, 0x809ebe) and their copies (0x8002e0, 0x800300) to 10000 (16 words each); fills the eight lookup argument records (threshold, real 2 / imaginary 2 dynamics, stop compensation 2D, component 3 2D, three breakpoint lookups) with offset 2 + axis/value pointers; snapshots the 6 saved trims (0x804158) into 0x8002d4 (used by limit mode 1 'reset to last').
- CM848 counterpart: hpcr_cbdInitFilterState @0x43a5c (event counter 0xff, axis cache offsets 2, trims -> 0x3fb580 snapshot). Same role, different steps.
- No VP44 access -> cm550_. Proposed: cm550_initializeCylinderBalance.

## J1939 engine configuration (PGN 65251) percent peak torque (e2m 10DF cals 0x807d4c-, 10E2 state 0x80bc74-)
### 0x142d4 cm550_FUN_000142d4 = percent peak torque x 256 at one engine speed -> TWIN of CM848 cm848_calculateJ1939PercentPeakTorqueAtSpeed @0x18070
- (speed, friction fuel): 2D lookup four_dimensional_fueling_steady_state_lookup at (speed, y=400 = 100% throttle) -> cm550_subtractAndClampValue (CM550's helper also removes a 0x2e00 offset before the 0..0x1700 clamp; CM848 helper clamps only) -> (fuel - (friction fuel + 0x80052c coolant friction correction)) x 0x6400 -> cm550_safeDivideWithClamp by (JCMXT0FL 0x807d4c - JCFCBK04 0x80bc88).
- Called 5x by cm550_multiSpeedParameterInterpolation @0x143b6 (idle LSRF, rated, bp3, bp4, bp5 - same order as CM848 cm848_calculateJ1939PercentPeakTorquePoints) which is itself the twin of CM848 0x1820c (not in this batch).
- Same steps, constants (400, 0x6400), order, position -> twin. Shared unprefixed name: calculateJ1939PercentPeakTorqueAtSpeed (CM848 row changes too).
### 0x14348 cm550_FUN_00014348 = friction fueling at the five torque speeds -> TWIN of CM848 cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints @0x1811c
- friction_fuel_by_engine_speed_lookup at lsg_breakpoint_speed (LSRF) -> JCFCLDIS 0x80bc82, bp3 JCT0RP03 0x807d50 -> JCFCBK03 0x80bc86, bp4 JCT0RP04 0x807d52 -> JCFCBK04 0x80bc88, bp5 JCT0RP05 0x807d54 -> JCFCBK05 0x80bc8a, rated JCRTT0RP 0x807d4e -> JCFCBKRR 0x80bc84. Same order as CM848.
- Callers: cm550_multiSpeedParameterInterpolation and cm550_FUN_0001ddb4 (start-up); CM848: cm848_calculateJ1939PercentPeakTorquePoints and the start-up cm848_initFaultSeverityTables.
- Shared unprefixed name: calculateJ1939FrictionLoadFuelingAtBreakpoints.
- Globals with CM848 shared names (same records): 0x807d4c j1939_peak_fueling_tau_0 (JCMXT0FL), 0x807d4e j1939_rated_speed_tau_0 (was shutdown_protection_step_2), 0x807d50 j1939_speed_breakpoint_3_tau_0 (was shutdown_protection_step_1), 0x807d52 j1939_speed_breakpoint_4_tau_0 (was engine_running_timer_threshold), 0x807d54 j1939_speed_breakpoint_5_tau_0 (was frictional_load_torque_table_value), 0x80bc82 j1939_friction_load_fueling_at_low_idle, 0x80bc84 _at_rated_speed, 0x80bc86/88/8a _at_breakpoint_3/4/5. Percent words 0x80bc78/7a/7c/7e/80 = j1939_percent_peak_torque_at_breakpoint_3/4/5_times_256, _at_idle_times_256, _at_rated_speed_times_256. 0x80052c = coolant friction correction (CM848 throttle_demand_offset_cal_working, a poor name) - no e2m record.

## 0x14812 cm550_FUN_00014812 = act on the CLEAR_INACTIVE request -> counterpart of CM848 cm848_clearDiagnosticState @0x1d01c
- Called by cm550_faultFlagScannerAndProcessor when diagnostic_clear_request_state & 1 (as CM848's scanner calls cm848_clearDiagnosticState).
- If not_safe_to_program_flag == 2: cm550_resetFaultStatus for every code of previously_active_dtc_list (count byte 0x8058f4); count = 0; previously_active_dtc_cummins_fault_codes[0] = 0; inactive_fault_list_count = 0; inactive_fault_j1587_reportable_count = 0; fault_to_erase_none (FLT2ERAS) = 0. Always diagnostic_clear_request_state = 0.
- CM848 version has gating on (request & 7 / key switch / OBD), an active-fault clear branch, cm848_clearPreviouslyActiveFaults, learned-switch resets -> counterpart.
- Proposed: cm550_clearInactiveFaults (or cm550_processClearInactiveFaultsRequest).

## 0x17baa cm550_FUN_00017baa = crank initial advance + break speed by IMT -> counterpart of CM848 cm848_calculateIntakeAirAdjustment @0x1bd74
- Position: 2nd call of cm550_engineModeTransitionHandler @0x17d2a in the STOPPED->CRANKING / RUNNING->REENTRY branch = CM848 cm848_processColdStartAdjustment @0x1bf44 (same 3 calls + 1).
- IMT high/low error = fault bits 13/14 (A/D channel 0 config 0x806ae2: high_error_fault_number 13, low 14) with fault_processing_enable_flags[0] bits, or IMT < CKCDIMTP -> CKIITA = CKCDIMTA, CKIITAES = CKCDIMES; IMT > CKHTIMTP -> high values; else weighted interpolation ((hi-T)*lo + (T-lo)*hi)/(hi-lo) for both.
- CM848 tests no enable mask, uses <= / >= and lo + slope*(T-lo): counterpart.
- Proposed: cm550_calculateCrankInitialAdvance.

## PGN 65251 fault derate (EPF) torque curve (e2m 12BA cals 0x807f3e-0x807f4c, 12BB 0x80d0da, 1102 0x80da38-)
### 0x183cc = min/replace the five torque curve fuelings by the fault derate fuel limit -> counterpart of cm848_applyFaultDerateToJ1939TorqueCurveFuelings @0x507858
- 5 lookups of fault_derate_fuel_limit_at_torque_curve_points_lookup (EPFLVSAI/EPFLTB) at JCTQRPP1..5; if (EPTQCG 0x807f4c & EPAERPST 0x80d0da) != 0 -> each JCTQFLPn lowered to the derate value; else if (flags & ~bit) <= bit -> all five replaced.
- CM848 tests the clamp mask against cm848_getHighestPriorityBit(); CM550 against the whole flag word -> counterpart. Only caller 0x184c6 (bsr at 0x185d6).
- Proposed: cm550_applyFaultDerateToJ1939TorqueCurveFuelings.
### 0x184c6 = fault derate torque curve speed points -> counterpart of cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints @0x507a20
- First call of buildPgn65251EngineConfiguration1Payload (twin) in both.
- EPFLLMSS 0x80d286 != 1 -> clear the bit (epf_source_bitmask 0x80060c) in EPAERPST, return. Else set it; if no higher bit: point 1 = LSRF - LSDPSE(0x80daf4) x EPLSINFL / 167 (droop enable bit 0x40 of algorithm_enable_flags_12_cal and slope != 0; floored 0), point 2 = HSRFBEDP + (FSMXBFDP - EPHSINFL) x 8 x HSDPSLAE / 0x8888 (capped 40000) when HSRFST in {1,2,4,5}, else EPRPP2; points 3-5 = EPRPP3-5. Then 0x183cc.
- CM848 includes source 12 and clamps point 1 to 40000 -> counterpart.
- Proposed: cm550_calculateFaultDerateJ1939TorqueCurveSpeedPoints.
### 0x185f0 = TWIN of cm848_initializeFaultDerateJ1939TorqueCurvePriority @0x507c1c
- epf_source_bitmask = 1 << EPTQPZ; lookup record offset 2 + axis/value pointers (CM550's record form of CM848's cached offset preset, as initializeHighSpeedGovernorGainSet was judged). Same parent: initializePgn65251EngineConfiguration1Buffer, first of its two closing calls (then 0xff48 / cm848_initializeJ1939ReferenceEngineFuelingAndTorque).
- Shared name: initializeFaultDerateJ1939TorqueCurvePriority.
- Globals (CM848 shared names, same records): 0x807f3e fault_derate_curve_low_speed_governor_intercept_fueling, 0x807f40 fault_derate_curve_high_speed_governor_intercept_fueling, 0x807f42..48 fault_derate_curve_engine_speed_point_2..5, 0x807f4a fault_derate_curve_priority_bit_position, 0x807f4c fault_derate_curve_clamp_priority_mask, 0x80060c fault_derate_torque_curve_priority_bit, 0x80d0da j1939_pgn65251_speed_points_request_flags, 0x80d286 fault_derate_active_flag, 0x80da38..40 j1939_torque_curve_speed_at_point_1..5, 0x80da42..4a j1939_torque_curve_fueling_at_point_1..5.

## Engine protection (EPF)
### 0x192e0 = record the power-up shutdown channel + clear the shutdown latch -> counterpart (subset) of cm848_resetEngineProtectionShutdownState @0x508de8
- move.w EPSOAE (0x8058ce, e2m 10B3 +0, the shutdown channel 255 = none) -> 0x80061e; clr.w 0x80061c. Third-last step of vp44_engineProtectionSystemInit (after initializeFaultDerateEngineSpeedLimit, cm550_initShutdownLimitVariables).
- 0x80061e: only other reader processDiagnosticLimitStatus 0x1927e: at a new shutdown, EPSOCU 0x8058d0 counts up when EPSOAE equals it, else 1; EPSOTF 0x8058d2 (total) counts. = CM848 engine_protection_power_up_shutdown_channel.
- 0x80061c: cleared while engine_state STOPPED (0x18fe0), set from the shutdown command at the end, while set the channels are skipped (0x1900e) = CM848 engine_protection_shutdown_latch (current CM550 name engine_shutdown_command_flag_previous).
- CM848 does these two stores inside a bigger reset (flags, previous speed, time counts, override) -> counterpart.
- Proposed: cm550_resetEngineProtectionShutdownState (or cm550_recordPowerUpEngineProtectionShutdownChannel). Globals: 0x80061e engine_protection_power_up_shutdown_channel, 0x80061c engine_protection_shutdown_latch, 0x8058d2 engine_protection_shutdown_total (EPSOTF; not EEPROM window -> no _cal).
### 0x19702 = fault derate fuel limit (task 2 of the EPF phase switch cm550_engineProtectionMultiStateSlowCycle40Coordinator) -> counterpart of cm848_calculateFaultDerateFuelLimit @0x509540 (task 2 of cm848_runFaultDerateScheduler)
- Loop over the 9 channel configs 0x807032 + 36n (state 46 bytes from 0x80d0dc, history 30 bytes from 0x8057c0): fueling-limiting enable bit 0x70+4n or history-only bit 416+n (word 26) -> severity (flag 0x40: cm550_protectionThresholdCalculationHelper; else duration > start: cm550_protectionPercentageCalculator(input, min, max)); floor at the restart severity unless history-only; store the channel fueling severity; max of the non-history-only ones.
- EXTRA vs CM848: with oil pressure fueling limiting enabled (word 7 bit 0x1000), a running counter 0x80062e (0 while engine_rpm_primary 0) counts to EPO2 power-up time 0x807f34; until then EPO2FLIX 0x80581a and the maximum are forced to 0x100.
- Ramp engine_protection_fueling_severity_filtered (0x800630) toward the max by EPFLIXRT 0x807f32, cap 0x100; 0 -> fault_derate_fuel_limit = fuel_demand_maximum, else derate table(engine_rpm_primary) + (256 - ramp) x (throttle_100_fueling - table) / 256; EPFLLMSS = ramp > 0.
- CM848: constants 0x80/0x1a4 (one channel), no oil step -> counterpart. Proposed: cm550_calculateFaultDerateFuelLimit. (0x800630 = CM848 fault_derate_ramp_times_256 role, e2m 10B1+20 in CM848.)

## Engine position signal set-ups (switch in cm550_initializeEnginePositionSignalInputs @0x17150 on EPCMTY 0x807e9d: 3 calls per configuration)
- config 0: 0x1999c (mc68k_initializeTpuChannel10PrimarySpeedInputDivided), 0x19ac2 (jsr 0x34674; rts - misnamed cm550_delayWithWatchdogServiceWrapper2), 0x19aca (empty, cm550_emptyStubFunction7)
- config 1: 0x19caa, 0x19dd0 (mc68k_initializeTpuChannel0MissingToothInput), 0x19e8e (empty)
- config 2: 0x1a350, 0x1a47c, 0x1a52a (empty)
- config 3: 0x1a746 (mc68k_initializeTpuChannel10PrimarySpeedInputIfEnabled), 0x1a89a (jsr 0x34674; rts), 0x1a8a2 (empty)
### 0x19caa = byte-for-byte 0x1999c except the handler: rpm_timer_isr_function_pointer 0x808f04 = 0x19e90 (Mode1). TPU ch10 function 0xd (CFSR1), PARAM1 = ESTTIP << 8, PARAM0 = 0xb, HSQR0 0x30, HSRR0 0x30, CIER bit 10, priority 2; fills the pulse period ring with ESIITB01. Proposed mc68k_initializeTpuChannel10PrimarySpeedInputMode1.
### 0x1a350 = same, handler 0x1a52c (Mode2) and PARAM1 = (ESCMTT 0x807ec8 / ESPECM01) << 8. Proposed mc68k_initializeTpuChannel10PrimarySpeedInputMode2.
### 0x1a47c = TPU ch0 function 9 set-up like 0x19dd0 but PARAM0 = 4 (not 7), no PARAM2/4-6 clears, TPU_CH15_PARAM6 = 0xc000, priority 2 (not 1), hook 0x808edc = 0x1a6e8 (mc68k_crankFuelAndTimingBufferStore; 0x19dd0 uses 0x19f82); then 0x34674. Proposed mc68k_initializeTpuChannel0MissingToothInputMode2.
### 0x19e8e / 0x1a52a / 0x1a8a2 = rts only; third set-up step of configs 1 / 2 / 3 (config 0's is cm550_emptyStubFunction7 0x19aca).
### 0x1a89a = jsr mc68k_initializeSpeedMeasurementMode0 (0x34674); rts. Identical to 0x19ac2. 0x34674 acts only for configs 0 and 1, so in config 3 it does nothing.
### 0x1a298 = NO reference in the dumped ROM (no jsr/bsr/pointer). Mirror of cm550_rpmTimingDeltaComparatorWithReturn @0x1a1e0 (called by the 4 ch10 primary handlers): gate 0x80aa18 (backup sensor's sync-pulse result from cm550_detectEngineSpeedSensorSyncPulse) instead of 0x80aa16; with the MAIN lost counter ESTMCU01 0x80cd10 = 0 it sets backup in phase ESBUIPER = 1 (primary version: backup lost counter 0x80cd12 -> main in phase). Tooth counters equal -> ESPHDF = backup edge - main edge, positive/negative out-of-phase counts vs ESPLPHTD/ESNGPHTD/ESMXPHCU (same outputs as the primary version). No CM848 records (12A1/12A2 absent in CM848 e2m) -> cm550_, no counterpart.

## Backup speed / cam sync input on TPU channel 1 (dispatcher cm550_canRpmModeConfigInit @0x1839a on EPCMSYTY 0x807f26 'DETERMINES HOW ENGINE POSITION IS SYNC'D TO CAM': 1 -> 0x1ae22 mc68k_initializeTpuChannel1BackupSpeedInput, 2 -> 0x1b39a mc68k_dutyCycleMonitorBufferInit, 0 -> 0x1b1ea)
- RAM 0x808edc + 4n = TPU channel n's interrupt vector (0x808edc ch0 hook, 0x808ee0 ch1, 0x808f04 ch10 = rpm_timer_isr_function_pointer); handlers end in RTE.
### 0x1b1ea = type 0 set-up: fills the backup pulse period ring ESPSTB02 (0x80ceae) with ESIITB02, ring end/next pointers, sums (0x80d074, ESPLAVBU 0x80ccfc); only with ESSXSNEN (0x807ed4) bit 3: vector 0x808ee0 = 0x1b30a, CFSR3 ch1 function 0xd, PARAM1 0x100, PARAM3/4 0, PARAM0 0xb, HSQR1 0xc, HSRR1 0xc, CIER bit 1, CPR1 priority 2, clear CISR bit 1. Differs from 0x1ae22 (type 1: unconditional, PARAM0 0x4f, clears 0x80d0cc/0x80d0cd, handler 0x1af32). Proposed mc68k_initializeTpuChannel1BackupSpeedInputIfEnabled (mirrors ..Channel10PrimarySpeedInputIfEnabled).
### 0x1b30a = TPU ch1 ISR for type 0 (RTE): with ESSXSNEN bit 3: ESTMCU02 0x80cd12 = timeout 0x80d06e; ESIPBKPE 0x80d04e = TPU_CH1 PARAM4/5 (long 0xffff18); clear PARAM4; CMSYRSFG 0x80d0ce = 1; clears fault bit 43 (word 2 bit 0x800, the missing cam/CI pulse error that the ch10 handlers set with cam_sync_state 2) when its first-occurrence bit is clear (interrupts masked); period -> ring start 0x80ceae and ESPLAVBU 0x80ccfc. Else clear PARAM4. Then mc68k_resetSpeedMeasurementMode0 (0x3478c), cm550_FUN_0000c87e (empty), clear CISR bit 1. Proposed mc68k_tpuChannel1BackupSpeedInterruptHandlerCamSyncType0.
### 0x1b4b2 = TPU ch1 ISR for type 2 (installed by 0x1b39a): only mc68k_resetSpeedMeasurementMode0, cm550_FUN_0000c87e, clear CISR bit 1, RTE. Proposed mc68k_tpuChannel1BackupSpeedInterruptHandlerCamSyncType2.
- CM848: no 100B / 11A8 / 11AD records; its crank/cam handling is MPC555 TPU code -> none.

## Throttle 100 torque curve request (PGN 65251) and 4D timing lookups
### 0x1c7a8 = start-up set-up of three lookup records (double_pulsing_fueling_mapping_lookup 1-D; four_dimensional_injection_timing_steady_state_lookup / _transient_lookup 2-D: axis/value pointers + offsets 2) used by cm550_fuelDemandTableBlendCalculator. mc68k_applicationMain jsr 0x287b0.
- CM848 counterpart: cm848_initializeFourDimensionalInjectionTimingLookupCaches @0x1ea6c (presets map a / map b caches to 2; no double pulsing mapping) -> counterpart (extra record). Proposed cm550_initializeFourDimensionalInjectionTimingLookups.
### 0x1c824 = throttle 100 torque curve speed points -> counterpart of cm848_setThrottle100J1939TorqueCurveSpeedPoints @0x21c3c
- if (flags 0x80d0da & ~bit 0x8006e6) <= bit: point 1 = LSRF + JCLSRFOF (0x808010, signed) clamped 0..0xffff; point 2 = engine_speed_limit_ramped (HSRFBFDP 0x80d654); points 3-5 = PPTHES03/04/05 (0x808014/16/18). Only caller 0x1c8a0 (bsr at 0x1c8ec).
- CM848 recomputes the bit from the cal each call and only floors point 1 at 0 (no 0xffff cap) -> counterpart. Proposed cm550_setThrottle100J1939TorqueCurveSpeedPoints.
### 0x1c8a0 = throttle 100 torque curve fuelings -> counterpart of cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings @0x21cd4
- Called twice? (callers.py: cm550_runEvery20FramesTaskSetPhase14 (2) - the decompiled task set; jsr at 0x1b82a). Once: bit 0x8006e6 = 1 << FSMXMNCG (0x80801c), init flag 0x8006e8 = 1. programmable_power_enable clear: set the bit in EPAERPST, 0x1c824, five cm550_calculateBlendedTableValue(point speed, 400); (flags & FSMXTHCG 0x80801a) != 0 -> lower each JCTQFLPn; else if no higher bit -> replace all five. Programmable power set: clear the bit.
- CM848 also computes the 5 reference fuelings (torque normalization), tests the clamp bitmap against the highest set bit, and never clears the bit -> counterpart. Proposed cm550_calculateThrottle100J1939TorqueCurveFuelings.
- Globals (CM848 names, same 12BD records; CM550's 12BD has PPMXTHPR at +2 so offsets shift by 2): 0x808010 j1939_pgn65251_speed_at_point_1_low_speed_governor_offset, 0x808014/16/18 j1939_pgn65251_speed_at_point_3/4/5, 0x80801a throttle_100_fueling_point_clamp_bitmap, 0x80801c throttle_100_priority_bit_index, 0x8006e6 throttle_100_speed_points_request_bit (now torque_curve_feature_bitmask), 0x8006e8 throttle_100_speed_points_request_bit_initialized_flag.

## Engine protection fuel temperature source (e2m 81F9 EPFLTPDF/EPFTFG, 81FA EPFLTP; no CM848 records)
### 0x1cad6 = select the fuel temperature used by the EPF (EPFLTP 0x80a254, now named vp44_fuel_temperature_value): frame 15 once-per-40 call (jsr 0x1bb94). With word 2 bit 4 (engine protection) and word 8 bit 12 or 13 (fuel temperature fueling / rpm limiting): EPFTFG 0x80784a == 0 (VP44 source): fault word 18 bit 7 (fault 295, no writer in the dumped ROM) set -> EPFLTPDF 0x807848 default, else the converted pump temperature from 0x1cb48; EPFTFG != 0 -> ADFLTPFT 0x80a2c8 (ECM fuel temperature sensor filtered). Handles the VP44 pump temperature path -> vp44_ OK. CM848 none. Proposed vp44_selectEngineProtectionFuelTemperature.
### 0x1cb3c = start-up: EPFLTP = ADDFFLTP (fuel_temperature_sensor_config.default_value, 0x806afc). mc68k_applicationMain jsr 0x28900. No VP44 access -> cm550_. Proposed cm550_initializeEngineProtectionFuelTemperature.
### 0x1cb48 = NOT empty (the decompiler lost it): d1 = FLFLTP (vp44_fuel_temperature 0x80a188, 'RAM IMAGE OF FUEL TEMP MEASURED BY PUMP CONTROLLER') sign-extended + 800, clamped 0..5600, returned << 3 in d0. Only caller 0x1cad6. Proposed vp44_convertPumpFuelTemperature (function_definitions needs a word return).
- Global: 0x80a254 engine_protection_fuel_temperature (EPFLTP), 0x80784a engine_protection_fuel_temperature_source (EPFTFG), 0x807848 engine_protection_vp44_fuel_temperature_default (current name ok).

## 0x1cdf8 = start-up set-up (cm550_masterSubsystemInit jsr 0x30c8a) of the two lookups of cm550_calculateThrottle100Fuelings: throttle_100_fueling_low_horsepower_curve_lookup (5DFL01 tables, y input fixed 400) and full_fueling_cold_temperature_fuel_increment_lookup (FLCDIC tables).
- CM848 counterpart: cm848_initFuelDemandTableDimensions @0x1f300 (presets four_dimensional_fueling_steady_state_cached_axis_offsets_2, the throttle 100 low HP lookup cache; sits right after cm848_calculateThrottle100Fuelings as 0x1cdf8 sits after 0x1cc72). CM550 has the extra cold increment record -> counterpart. Proposed cm550_initializeThrottle100FuelingLookups.

## 0x1dbd8 = start-up: ZILMES (0x80d686, e2m 10C4 +0 'OUTPUT ENGINE SPEED LIMIT GOING TO HSG REFERENCE SPEED ALG'; the ZI block 10C3 = injector fault speed derate: ZICNMXES / ZIFUDYTM / ZIFURMRT) and 0x80def0 (no e2m record, no other reference) = maximum_rated_engine_speed (EPNTDQRP 0x803f40). mc68k_applicationMain jsr 0x287b6. No reader of either in the dumped ROM (0x80d686 is in the parameter ID table at 0x359bc).
- CM848: no 10C3/10C4 records -> none. Proposed cm550_initializeInjectorFaultEngineSpeedLimit. Global 0x80d686 injector_fault_engine_speed_limit.

## 0x1ddb4 = TWIN of CM848 cm848_initFaultSeverityTables @0x1ea94 (misnamed there)
- Same steps / order: 4D fueling steady state record (5DFL01 0x6086e/0x6089a/0x608a4), transient (5DFL00 0x6094c/0x60978/0x60982), friction fuel by engine speed (1-D), friction fuel correction by coolant temperature (1-D), then 0x14348 (calculateJ1939FrictionLoadFuelingAtBreakpoints) - CM848: the same four cache presets (steady, transient, friction by speed, coolant) then cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints. Both once from applicationMain (CM550 jsr 0x2886a).
- CM550 record pointers + offsets = CM848 cached offsets (initializeHighSpeedGovernorGainSet precedent). Shared name proposal: initializeFourDimensionalFuelingAndFrictionFuelLookups (CM848 row changes; its name says init and fault severity, both wrong).

## 0x1de58 = 4D fueling (FOUR_D user fueling state) -> counterpart of cm848_calculateDualAxisFuelLimit @0x1ec70
- Called by cm550_diagnostic_parameter_handler (0x1c640, misnamed: it is CM848's cm848_updateFourDimensionalFueling) when user_fueling_state == FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE; result -> 5DFL 0x80d33e and fuel_demand_selected.
- throttle = commanded_throttle_state.commanded_throttle (capped at ROM 0x608a0 = the 5DFL01 throttle axis word [3] with programmable power); 0 -> fuel_demand_minimum. Else steady (alpha FLINML 0x80d340 != 0) and transient (alpha < 0x4000) 2D lookups at (engine_rpm_primary, throttle), each clamped with cm550_subtractAndClampValue and, without programmable power, bounded by the throttle 0 / 400 values; blended by alpha / 0x4000; + 5DFLAJ (0x803f3a, e2m 125A +C 'INCREMENTAL FUELING VALUE ADDED TO 4-D FUELING VALUE', EEPROM window) floored at fuel_demand_minimum; capped by the one-shot 5DIRMXFL 0x80d342 which is reset to 0x1700.
- CM848: same structure but filtered throttle (commanded_throttle_filtered) and no incremental fueling (no 125A records) -> counterpart. Proposed cm550_calculateFourDimensionalFueling.
- Globals (CM848 names, same 1053 records): 0x80d33e four_dimensional_fueling, 0x80d340 four_dimensional_fueling_interpolation_factor (now timing_alpha_blend_factor), 0x80d342 four_dimensional_fueling_user_maximum; 0x803f3a four_dimensional_fueling_adjustment_cal (CM550 only).

## 0x1e04c = start-up: FLINML 0x80d340 = 0x4000. mc68k_applicationMain jsr 0x2881c.
- CM848 counterpart: cm848_initFuelDemandTracking @0x1ef30 (same store first, then the commanded throttle filter set-up that CM550 lacks) -> counterpart. Proposed cm550_initializeFourDimensionalFuelingInterpolationFactor.

## 0x1f4e8 = J1922 engine control request from the transmission (J1708 record MID 0x4a = 74; J1922 range 0x45-0x56 with algorithm_enable_flags_11_cal.j1922_communication_enable) - dispatched by mc68k_dispatchJ1708ReceivedMessages (jsr at 0x163f8 case 0x4a).
- Command byte (record +2) bits 0-1 = override control mode; record length must be 3 / 5 / 4 / 5 for modes 0-3. refreshEngineTsc1IgnoredRequestEntry(0, 0x4a, mode) -> ignored; findTsc1SourceConfiguration(0, 0x4a) and table-position priority against the current controller; stores JCEGCOBY, network type 0, source 0x4a; mode 0 clears the control (timeout 0x808186 + 1); 1 speed: speed reference = (bytes 3-4 LE) >> 1, device 1 (TRANS); 2 torque: percent = byte 3 << 8, torque fueling = JCFCLDTQ + (JCMXT0FL - JCFCBK04) x percent / 0x6400; 3 limit: speed limit = byte 3 << 7, torque limit fueling from signed byte 4 x 8; then command bits 2 (retarder), 3 (high idle override), 4 (driveline disengaged).
- Sibling: cm550_engineFluidLevelDataBuilder @0x1f8bc (misnamed) = the same for source 0x4f (MID 79, device 2 = ABS, other byte layout). CM848 has no J1708/J1922 -> none. Proposed cm550_processJ1922TransmissionEngineControlRequest.

## Naming check (2026-11-25): all proposed function names absent from both function_renames.csv and deleted_functions.csv (grep -c 0).

## Global name proposals (evidence: e2m record resolved by e2m_block_addresses table + the access in these functions)
- 0x807ce4 accelerator_pedal_highest_valid_minimum (1048+6 CTHISATH; CM848 0x5c294 same record)
- cylinder balance: 0x8072c0 cylinder_balance_enable (CBDEN), 0x8072dc cylinder_balance_start_tooth (CBDST, CM848 name), 0x8091e8 cylinder_balance_filtered_fueling (CBDFFL, CM848 name), 0x8091ea cylinder_balance_speed_buffer_1 (CBDSB1; now intake_manifold_temp_raw - wrong), 0x8092e4 cylinder_balance_speed_buffer_ready_flag (CBDSBRF), 0x809206/0a/0e/12/16 cylinder_balance_fourier_real_component_1 / _imaginary_component_1 / _real_component_2 / _imaginary_component_2 / _real_component_3 (CBDFRC1.. longs), 0x809276/78/7a cylinder_balance_adjusted_real_component_2 / _adjusted_imaginary_component_2 / _adjusted_real_component_3 (CM848 names), 0x80922e cylinder_balance_stop_compensation_flag, 0x80925e cylinder_balance_trim_limits_exceeded_flag, 0x809260/62/64 cylinder_balance_trim_index_1/2/3, 0x80926e/70/72 cylinder_balance_trim_increment_1/2/3 (0x80926e now throttle_position_raw - wrong), 0x809230 cylinder_balance_fourier_threshold (CBDFT), 0x809232/34/36 cylinder_balance_filtered_magnitude_1/2/3 (CBDFM1-3), 0x809246 cylinder_balance_fueling_trims (CBDDFO1-6, now cyl_balance_correction_array), 0x809252 cylinder_balance_trim_adjustment_1 (exists), 0x8092e0 cylinder_balance_component_3_adjustment (CBDC3ADJ), 0x8092e2 cylinder_balance_active_trim_gain (CBDATG, now cyl_balance_gain_percent), 0x804158 cylinder_balance_fueling_trim_cal (8241 CBDDFTO1-6 saved at power-down; CM848 name), 0x8002d4 cylinder_balance_fueling_trim_power_up_copy, 0x800220 cylinder_balance_cutout_delay_counter (now manifold_temp_table_3_x_ptr), 0x800320 cylinder_balance_engine_speed_bin_index, 0x8002c6 cylinder_balance_engine_speed_previous (CM848 name), 0x8002c8 cylinder_balance_engine_speed_change, 0x8002e0 / 0x800300 cylinder_balance_real_2 / imaginary_2 _dynamics_compensation_previous_values (word[16]; now system_timer_array / protection_state2_table_ptr_1), 0x8002a4 cylinder_balance_segment_index, 0x8002a6 cylinder_balance_segment_period_sum (dword), 0x8002aa cylinder_balance_segment_period_count, 0x800322 cylinder_balance_segment_periods (dword[7]; 0x80033a = slot 6, now oil_pressure_crank_exit_ptr), 0x80033e cylinder_balance_new_speed_data_flag (now oil_pressure_mode_init_flag), 0x80a1ac cylinder_fueling_offset (word[6] cylinder order, CM848 name of the same role), cals 0x80728c-0x8072f2 per 823C (CM848 81AE names where they exist).
- PGN 65251: listed in the J1939 sections above (CM848 shared names).
- EPF: 0x80061e engine_protection_power_up_shutdown_channel, 0x80061c engine_protection_shutdown_latch, 0x8058d2 engine_protection_shutdown_total (EPSOTF).
- 0x80a254 engine_protection_fuel_temperature (EPFLTP), 0x80784a engine_protection_fuel_temperature_source (EPFTFG).
- 0x80d686 injector_fault_engine_speed_limit (ZILMES).
- 4D fueling: 0x80d33e four_dimensional_fueling, 0x80d340 four_dimensional_fueling_interpolation_factor, 0x80d342 four_dimensional_fueling_user_maximum, 0x803f3a four_dimensional_fueling_adjustment_cal.

## Leads outside the batch (seen while reading)
- cm550_multiSpeedParameterInterpolation 0x143b6 = twin of cm848_calculateJ1939PercentPeakTorquePoints 0x1820c (coolant correction -> 0x80052c, 0x14348, 5 x 0x142d4 in the same order).
- cm550_engineModeTransitionHandler 0x17d2a = same structure as cm848_processColdStartAdjustment 0x1bf44.
- cm550_diagnostic_parameter_handler 0x1c640 = cm848_updateFourDimensionalFueling 0x1e830 role (FOUR_D state -> 5DFL + fuel demand).
- cm550_delayWithWatchdogServiceWrapper2 0x19ac2 = jsr 0x34674; rts (identical to 0x1a89a), not a delay.
- cm550_rpmTimingDeltaComparatorWithReturn 0x1a1e0 = main/backup EPS phase comparator on the primary edge (mirror of 0x1a298).
- cm550_canRpmModeConfigInit 0x1839a = TPU channel 1 (backup / cam sync input) set-up switch on EPCMSYTY; mc68k_dutyCycleMonitorBufferInit 0x1b39a = its type 2 set-up; mc68k_dutyCycleMonitorIsrHandler 0x1af32 = the type 1 channel 1 ISR.
- cm550_engineFluidLevelDataBuilder 0x1f8bc = J1922 engine control request from MID 0x4f (device 2 = ABS); sibling of 0x1f4e8.
- processDiagnosticLimitStatus 0x18fcc = the EPF shutdown loop (CM848 cm848_updateEngineProtectionShutdown role).
- CM848 cm848_initFaultSeverityTables 0x1ea94 is misnamed (it is the twin of 0x1ddb4).
