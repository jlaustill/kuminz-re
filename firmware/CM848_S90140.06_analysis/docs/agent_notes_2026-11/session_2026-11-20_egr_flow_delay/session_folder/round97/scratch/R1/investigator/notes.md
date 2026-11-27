# R1 investigator notes (CM550 low speed governor globals, lsg names)

Fresh run started 2026-11-25 (scratch dir was empty).

## Functions in the family (from function_renames.csv)
- 0x25b1c cm550_runLowSpeedGovernor (called by cm550_runEvery4FramesTaskSetPhase2)
- 0x25a34 cm550_presetLowSpeedGovernorIntegrator
- 0x26078 cm550_initializeLowSpeedGovernor
- 0x26616 cm550_calculateLowSpeedGovernorColdIdleSpeed
- callees: 0x2595a cm550_governorFuelPidController, 0x2629e cm550_epsControlModeSelector,
  0x2609c cm550_epsAccelerationMonitor, 0x265e6 cm550_epsRpmTargetModeChecker, 0x26272 cm550_epsOverrideChecker,
  0x26308 cm550_epsControlModeInit, 0x2626a cm550_epsControlModeReset
- related: 0x25ff2 cm550_presetLowSpeedGovernorSpeedError -> 0x262fa cm550_epsInitializationWrapper -> 0x26252 cm550_epsRpmTrackingInit, 0x26462 cm550_initOilPressureMonitoring;
  0x26340 cm550_epsDiagnosticModeHandler (task set phase 2, gear gain sets)

## Callers (callers.py, jsr/bsr/ptr scan of the ROM)
- 0x25b1c <- jsr 0x1b5d4 cm550_runEvery4FramesTaskSetPhase2; 0x25a34 <- bsr.w 0x25cb8 (runLSG); 0x26078 <- jsr 0x2880a applicationMain
- 0x26616 <- jsr 0x1b7a8 cm550_runEvery20FramesTaskSetPhase4 (ptr hit at 0x23846 = data coincidence?)
- 0x2595a <- bsr.w 0x25a50 (preset) and 0x25e32 (runLSG)
- 0x2629e <- jsr 0x25c9e (runLSG); 0x2609c <- jsr 0x262ae (0x2629e); 0x265e6 <- jsr 0x262b4 (0x2629e); 0x26272 <- bsr.s 0x262be (0x2629e)
- 0x26308 <- jsr 0x2608c (0x26078); 0x2626a <- jsr 0x26318 (0x26308)
- 0x25ff2 cm550_presetLowSpeedGovernorSpeedError: NO caller in the dump (no jsr/bsr/ptr)
- 0x262fa <- jsr 0x26066 (0x25ff2 only); 0x26252 <- 0x262fa; 0x26462 <- 0x26300 (0x262fa)
- 0x26340 <- jsr 0x1b5da task set phase 2 (right after runLSG)
- 0x26474 <- jsr 0x266d2 (cm550_timingOffsetCalculatorWrapper = jsr 0x26474; rts) <- task set phase 4

## TWINS (verified from both disassemblies)
- 0x265e6 cm550_epsRpmTargetModeChecker == CM848 0x28b38 cm848_selectLowSpeedGovernorTsc1GainSet:
  tst tsc1_override_control_mode -> 0; algorithm_enable_flags_1_cal & 0x8000 -> 0; final gain state (CM550 0x80dacc / CM848 0x40ae7e) = 4;
  gain set pointer (0x80dada / 0x40ae90) = J1939 gain set 10EB +0 (0x808334 / 0x5c4a6); return 1. First call of the gain set load in both.
  -> shared name selectLowSpeedGovernorTsc1GainSet (CM848 row renamed too)
- 0x26272 cm550_epsOverrideChecker == CM848 0x289d0 cm848_selectLowSpeedGovernorOverrideGainSet:
  arg != 0 -> 1; override gain state (10ED +A LSOVGNST: 0x80dace / 0x40ae80) == 0 -> 0; final state = it; pointer = override gain set
  (10ED +C: 0x80dad0 / 0x40ae82); return 1. Second call of the gain set load in both. -> shared name selectLowSpeedGovernorOverrideGainSet
  (function_definitions.csv has CM550 rows keyed cm550_epsOverrideChecker: rename them too)

## COUNTERPARTS
- 0x2595a cm550_governorFuelPidController ~ CM848 0x27d38 cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity: same lookups
  (steady state if factor != 0, transient if < 0x4000, x = LSAJRFES, y = 400), same select/blend, but CM550 clamps the blend to 0..0x1700
  (0x25a10-0x25a26) and multiplies unsigned (mulu.l); CM848 has no clamp (0x27e0c-0x27e2c). -> cm550_calculateLowSpeedGovernorReferenceMaximumFuelQuantity
- 0x2629e cm550_epsControlModeSelector ~ CM848 0x28a14 cm848_loadLowSpeedGovernorGainSet: same TSC1 -> override -> user/default select
  and load through the pointer, but CM550 first runs the aggressive gain logic (jsr 0x2609c at 0x262ae) and loads 3 words (P/I/D at
  0x80dac4/c6/c8) not 4. -> cm550_loadLowSpeedGovernorGainSet
- 0x2609c cm550_epsAccelerationMonitor ~ CM848 0x28670 cm848_updateLowSpeedGovernorAggressiveGainLogic: same settled counts
  (0x801a7a idle error / 0x801a7c stopped vehicle, LSMXERES / LSLGTZTM / LSLOVS), same inhibit set condition (latch 0x801a76 == 1 and
  (LSER + LSOF03ES < 0 with switch 16 bit 2 clear, or road speed >= LSLOVS with the idle count done), or road speed > LSHIVS), same
  on/off by LSOF01ES / LSOF02ES / LSDCTDES / LSHYES; but CM550 uses the previous engine speed 0x801a78 (not engine acceleration), has
  no run timer / coolant / tool-state conditions, the enable bit only gates activation, and it writes the user gain state directly.
  -> cm550_updateLowSpeedGovernorAggressiveGainLogic
- 0x26340 cm550_epsDiagnosticModeHandler ~ CM848 0x4256c cm848_selectLowSpeedGovernorGearGainSet: same window LSERGRMX/MN, timer
  0x801a7e to LSGRTZTM, gear ratio 0x80a9d2 x axle ratio 0x80a9f8 >> 11 vs LS01BPGR / LS02BPGR with LSHYGR, states 2 / 3 and the
  requested pointer 0x80dad6 = middle 0x80832c / high 0x808326; CM550 also leaves on GROGSS 0x80a9d4 (out of gear), has no
  else branch (not-LSG reset) and no gain adjustment inhibit flag. -> cm550_selectLowSpeedGovernorGearGainSet
- 0x26308 cm550_epsControlModeInit ~ CM848 0x28adc cm848_initializeLowSpeedGovernorGainSelection: reset call first (0x2626a), user
  gain state 0, copy the default set 0x808314 into the override set 0x80dad0 (3 words, CM848 4). -> cm550_initializeLowSpeedGovernorGainSelection
- 0x2626a cm550_epsControlModeReset: clr.w 0x801a76 only; first call of the gain selection initializer like CM848 0x289ac
  cm848_resetLowSpeedGovernorAggressiveGainLogic (which clears its active flag, sets the inhibit and the run timer). -> cm550_resetLowSpeedGovernorAggressiveGainLogic
- 0x26252 cm550_epsRpmTrackingInit: 0x801a78 = engine_rpm_primary, clr 0x801a7a / 0x801a7c -> cm550_resetLowSpeedGovernorSettledCounts
- 0x26462 cm550_initOilPressureMonitoring: clr 0x801a7e (gear gain timer), 0x80a9f8 (117D +34 VSRRAXRA, axle ratio in use) = 0x803d40
  (1180 +6 VSRRAXRL). No oil pressure. -> cm550_resetLowSpeedGovernorGearGainLogic (only writer of 0x80a9f8 in the dump)
- 0x262fa cm550_epsInitializationWrapper: jsr 0x26252; jsr 0x26462 -> cm550_resetLowSpeedGovernorGainLogic
  (chain 0x25ff2 -> 0x262fa -> 0x26252 / 0x26462 has no caller in the dump: no jsr / bsr / pointer / pc-relative reference to 0x25ff2)
- 0x26474 cm550_engineModeTimingAdjuster: operator idle adjust by switch 16 bits 0x20 (increment) / 0x40 (decrement) rising edges
  (previous states 0x801a80 / 0x801a81 bytes), step LSICDTIS 0x808332, limits LSMXRFTN / LSMNRFTN minus LSBPRFES, gated by
  algorithm_enable_flags_3 bit 3 LSISAJEN and a fault (0x80600e & 2 with 0x806aca & 2); LSDSRFRP 0x80db06 = LSBPRFES + adjustment;
  LSICBKRF 0x805f0a = adjustment with LSISSVEN else 0. CM848 has no reader of idle_speed_adjust_enable. -> cm550_updateLowSpeedGovernorIdleAdjustment
- 0x266d2 cm550_timingOffsetCalculatorWrapper: jsr 0x26474; rts (first call of task set phase 4) -> cm550_updateLowSpeedGovernorIdleAdjustmentWrapper

## GLOBALS (the 56 rows): e2m record (CM550 v64t6_s) -> CM848 row of the same mnemonic -> proposal
(e2m layouts of 1064 / 1065 differ between the firmwares after +6: matched by mnemonic + description, not offset)
- 0x803b9e 0008 +2 LSBPRFES -> CM848 low_speed_governor_base_reference_speed_cal (0008 +2) -> same, word (EEPROM image)
- 0x803fca 131E +2 LSMNRFTN (no CM848 record) -> low_speed_governor_minimum_idle_speed_trim_cal word (EEPROM)
- 0x803fcc 131E +4 LSMXRFTN -> low_speed_governor_maximum_idle_speed_trim_cal word
- 0x805f0a 1073 +0 LSICBKRF S -> low_speed_governor_saved_operator_idle_adjustment i16 (0x805f0a outside the mirror: no _cal)
- 0x807aae 104B +E APLSTMTR -> CM848 low_speed_governor_alpha_timeout (104B +14) word
- 0x807bf2 11A3 +0 LSRFOF02 (CM848 11A3 +0 no row; no reader in either decompile) -> low_speed_governor_exit_reference_offset word
- 0x80817c 1104 +1E LSRFESDC -> CM848 low_speed_governor_reference_speed_delta (1104 +1E) word
- 0x808236 1064 +0 LSMXFLOF -> low_speed_governor_fueling_clamp_maximum_offset i16
- 0x808238 1064 +2 LSMNLMFL -> low_speed_governor_fueling_clamp_minimum word
- 0x80823a 1064 +4 LSMXPZOF -> low_speed_governor_integrator_preset_maximum_offset i16
- 0x808242 1064 +C LSFTMX -> CM848 14EF +4 low_speed_governor_filtered_error_maximum i16
- 0x808244 1064 +E LSFTMN -> low_speed_governor_filtered_error_minimum i16
- 0x808246 1064 +10 LSMXITOF -> CM848 1064 +8 low_speed_governor_integrator_clamp_maximum_offset i16
- 0x80824c 1064 +16 LSITRSES -> CM848 1064 +E low_speed_governor_reset_speed_offset i16
- 0x80824e 1064 +18 LSITRSFL -> CM848 1064 +10 low_speed_governor_reset_fueling word
- 0x808250 / 0x808252 1064 +1A / +1C LSDEITGN / LSDEPPGN 'BLANK SPOT AFTER REMOVAL OF LSG_DB_INT/PROP_GAIN' (no reader)
  -> low_speed_governor_removed_deadband_integral_gain / _proportional_gain word
- 0x808256 1064 +20 LSRFESUL -> low_speed_governor_reference_speed_upper_limit word (cmp.w + bls at 0x25b84)
- 0x80825c 1064 +26 LSDVFTCF -> CM848 1064 +12 low_speed_governor_derivative_filter_coefficient i16 (muls.w at 0x25d5c; was undefined)
- 0x80825e/60/62 LSDVAJEN / LSPPAJEN / LSITAJEN (no reader) -> low_speed_governor_{derivative,proportional,integral}_gain_adjustment_enable word
- 0x808266 1064 +30 LSMXDVFL -> CM848 1064 +1E LSG_Derivative_Max low_speed_governor_derivative_term_maximum i16
- 0x808268 / 0x80826a LSPP02GN / LSDV02GN -> low_speed_governor_proportional_gain_2 / low_speed_governor_derivative_gain_2 i16
- 0x808334 10EB +0 LSJCPPGN -> CM848 j1939_low_speed_governor_gain_set (struct) -> cm550_low_speed_governor_gain_set_t (3 shorts)
  0x808336 / 0x808338 inside it (delete rows)
- 0x808340 1066 +6 LSCIRMRT -> low_speed_governor_cold_idle_ramp_rate word
- 0x808342 1066 +8 LSMNRF (NOT datalink commanded) -> CM848 14EE +1E low_speed_governor_minimum_idle_speed word; also read
  by buildPgn65251EngineConfiguration1Payload (0x33344: / 80 into payload byte 24) like CM848's
- 0x80a90e (no record) -> CM848 alpha_low_speed_governor_timer_active_flag (twin calculateAlphaLowSpeedGovernorResult) word
- 0x80a910 104A +18 APLSTR -> CM848 alpha_low_speed_governor_timer (104A +16) word
- 0x80dac4 10ED +0 LSPPGN -> low_speed_governor_proportional_gain i16
- 0x80daca 10ED +6 LSUSGNST -> low_speed_governor_user_gain_state; 0x80dacc 10ED +8 LSFNGNST -> low_speed_governor_final_gain_state
  (enum LOW_SPEED_GOVERNOR_GAIN_STATE 0 DEFAULT / 1 AGGRESSIVE / 2 MIDDLE_GEAR / 3 HIGH_GEAR / 4 J1939, proven in both firmwares)
- 0x80dad0 10ED +C LSAPPPGN -> low_speed_governor_override_gain_set (struct); 0x80dad2 / 0x80dad4 inside (delete rows)
- 0x80dada (no record) -> low_speed_governor_gain_set_pointer, cm550_low_speed_governor_gain_set_t * (move.l writes)
- 0x80dade 1065 +0 LSFL -> CM848 low_speed_governor_fueling_working word
- 0x80dae0 1065 +2 LSER -> CM848 14F0 +0 low_speed_governor_filtered_speed_error i16
- 0x80dae4 1065 +6 LSDVFL -> low_speed_governor_derivative_term i16
- 0x80dae8 1065 +A LSMXLMFL -> low_speed_governor_fueling_clamp_maximum word
- 0x80daea 1065 +C LSMXITFL -> low_speed_governor_integrator_clamp_maximum i16 (ext.l at 0x25f1c)
- 0x80daec 1065 +E LSMXITPZ -> low_speed_governor_integrator_preset_maximum i16 (ext.l at 0x25ad6)
- 0x80daee 1065 +10 LSAJRFES -> CM848 14F0 +2 low_speed_governor_adjusted_reference_speed word
- 0x80daf0 / 0x80daf2 LSDPGN01 / LSDPGN02 (no reader) -> low_speed_governor_integrator_feedback_droop_gain / _fueling_output_droop_gain i16
- 0x80daf6 1065 +18 LSEXFL 'LSG ALG. IS RUNNING' -> low_speed_governor_running_flag word (NOT _active_flag: CM848's
  low_speed_governor_active_flag is LSLOFG 1045 +4, which CM550 has at 0x80a8f4 low_speed_governor_lock_flag)
- 0x80daf8/fa/fc LSPPAJGN / LSDVAJGN / LSITAJGN (no reader) -> low_speed_governor_adjusted_{proportional,derivative,integral}_gain i16
- 0x80dafe 1065 +20 LSDV02FL -> low_speed_governor_derivative_2_term i16; 0x80db00 LSPP02FL -> low_speed_governor_proportional_2_term i16
- 0x80db02 1067 +0 LSRF -> low_speed_governor_reference_speed word (CM848: low_speed_governor_reference.reference_speed)
- 0x80db06 1049 +4 LSDSRFRP -> CM848 1496 +2 low_speed_governor_desired_reference_speed word
- R7 owns 0x80db04 LSCIRF (do not propose here)

## RAM dump evidence (ram_words.py: 0x809242+ comes from extended_ram.bin; earlier zero reads past 0x8091c1 were bogus)
- engine_state 0x80d0c8 = 1 (STOPPED), adjusted_user_fueling_state 0x80a8f2 = 11 (LSG), LSLOFG 0x80a8f4 = 1
- user gain state 0x80daca = 1, final 0x80dacc = 1, requested pointer 0x80dad6 = 0x808230, gain set pointer 0x80dada = 0x808230,
  working gains 0x80dac4/c6/c8 = 530 / 283 / 55 = the words at 0x808230 / 32 / 34 (aggressive set) -> proves the 3-word set + pointer
- override set 0x80dad0/d2/d4 = 132 / 215 / 66 = default set 0x808314/16/18 (copied by 0x26308); high / middle gear sets also 132/215/66
- J1939 set 0x808334 = 124 / 57 / 55; 0x801a76 = 1 (aggressive gains used), inhibit 0x80dac2 = 0
- LSER 0x80dae0 = 7000 = LSFTGN 512 x (LSAJRFES 7000 - 0 rpm) >> 9; LSPPFL 0x80dae2 = 3864 = 7000 x 530 / 960; LSITFL 0x80dae6 = 127 =
  high word of 0x801a6a (0x007fe920); LSMXLMFL = LSMXITFL = LSMXITPZ = 2061 = 0x801a6e (1619) + 442; LSFL 0x80dade = 2061
- LSRF = LSAJRFES = LSDSRFRP = 7000 = LSBPRFES 6400 + adjustment 0x801a82 600 (= LSICBKRF 0x805f0a 600); LSEXFL 0x80daf6 = 1
- rear axle ratio in use 0x80a9f8 = 499 = 0x803d40 (VSRRAXRL 499): set even though 0x26462's chain has no caller in the dumped ROM
  -> its caller is likely in the undumped region (or another writer exists)
- alpha: 0x80a90e = 1, 0x80a910 = 15000 = APLSTMTR 0x807aae

## STRUCT (new, CM550 structure_definitions.csv, type only, empty address; precedent all_speed_governor_gain_set_t / cm550_fault_entry_t)
cm550_low_speed_governor_gain_set_t,,proportional_gain,short,2,"+0: e2m *PPGN (M/R 0.000566 per count, signed); cm550_loadLowSpeedGovernorGainSet copies it into low_speed_governor_proportional_gain (move.w (a2) at 0x262de)",,verified
cm550_low_speed_governor_gain_set_t,,integral_gain,short,2,"+2: e2m *ITGN (M/RS 0.0017691 per count, signed); copied into low_speed_governor_integral_gain (move.w (2,a2) at 0x262e4)",,verified
cm550_low_speed_governor_gain_set_t,,derivative_gain,short,2,"+4: e2m *DVGN (MS/R 4.529E-5 per count, signed); copied into low_speed_governor_derivative_gain (move.w (4,a2) at 0x262ec)",,verified
(CM848's low_speed_governor_gain_set_t has a 4th jerk_gain word, so the CM550 layout needs its own name)
Instances: 0x808314 default (10EC), 0x808230 aggressive (10EE +12), 0x808326 high gear (10EA +C), 0x80832c middle gear (10EA +12),
0x808334 J1939 (10EB), 0x80dad0 override (10ED +C). Pointers 0x80dada / 0x80dad6 typed cm550_low_speed_governor_gain_set_t *.
Rows inside instances to delete: 0x808328 0x80832a 0x80832e 0x808330 0x808336 0x808338 0x80dad2 0x80dad4.

## ENUM (new, both firmwares) LOW_SPEED_GOVERNOR_GAIN_STATE size 2: 0 DEFAULT / 1 AGGRESSIVE / 2 MIDDLE_GEAR / 3 HIGH_GEAR / 4 J1939
CM550 rows 0x80daca / 0x80dacc / 0x80dace; CM848 rows 0x40ae7c / 0x40ae7e / 0x40ae80 (5-9 = override states of the fuel system
specific algorithm, no members)

## CSV text that cites renamed names (parent should update)
- CM550 function_renames plates of 0x1b5ce (phase 2: cm550_epsDiagnosticModeHandler) and 0x1b7a2 (phase 4: cm550_timingOffsetCalculatorWrapper)
- CM550 structure_definitions bit comments: algorithm_enable_flags_1_t bits 12-15 (cm550_epsAccelerationMonitor / cm550_epsDiagnosticModeHandler /
  cm550_epsRpmTargetModeChecker), cm550_algorithm_enable_flags_12_t idle_speed_save_enable (cm550_engineModeTimingAdjuster, rpm_added_to_lsg_reference)
- CM550 function_definitions rows 0x26272 (function_name cm550_epsOverrideChecker -> selectLowSpeedGovernorOverrideGainSet)
- CM550 global comment of 0x808314 (cm550_epsControlModeSelector / cm550_epsControlModeInit / lsg_gain_set_pointer)
- CM550 deleted_functions.csv rows 0x25a30 / 0x26484 mention the old names (history only)

## Misc
- 0xfb26 (R7's vp44_fuelLimitExceedanceStatisticsAccumulator) tests LSRF - LSRFESDC <= LSBPRFES <= LSRF + LSRFESDC (0xfb44-0xfb7c): d2 = 0 inside, 4 outside
- 0x258e8 / 0x25926 (before the LSG block) are oil pressure protection lookups (R5 territory), not LSG
- generic callees kept: cm550_exponentialMovingAverage 0x34f8a, cm550_signedFirstOrderFilter 0x34e9a, cm550_tableLookup2D 0x35088,
  cm550_subtractAndClampValue 0x1e02a (= clamp(value - 0x2e00, 0, 0x1700); 0x2e00 = 800 MM3S, the 4D table bias)
- FINAL: output assembled 2026-11-25 (functions 23, globals 56 + extras, enum LOW_SPEED_GOVERNOR_GAIN_STATE, 3 prototypes)
