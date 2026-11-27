# R7 describer notes (round 97)

## CM550 0x143b6 cm550_multiSpeedParameterInterpolation
- Steps: coolant filtered (0x80a336) -> friction_fuel_correction_by_coolant_temperature lookup (0x80db2e, jsr 0x34de0) -> 0x80052c; bsr calculateJ1939FrictionLoadFuelingAtBreakpoints (0x14348); then 0x142d4 (calculateJ1939PercentPeakTorqueAtSpeed) x5: idle (0x80db02 LSRF, fuel 0x80bc82) -> 0x80bc7e (10E2 +A JCLSPCTQ), rated -> 0x80bc80, bp3 -> 0x80bc78, bp4 -> 0x80bc7a, bp5 -> 0x80bc7c.
- CM848 0x1820c cm848_calculateJ1939PercentPeakTorquePoints: same steps, same order (coolant correction lookup -> 0x1811c -> 0x18070 x5 idle/rated/bp3/bp4/bp5), same e2m 10E2 records. CM848 has no caller; CM550's one caller is the J1708 message builder 0x1f2d0 (jsr at 0x1f352).
- Verdict: twin (callee side identical; caller missing in CM848 = no J1708 there).

## CM550 0x1c640 cm550_diagnostic_parameter_handler
- asm: cmpi.w #8,(0x80ded4 user_fueling_state, e2m 1050 +2 FSDSFLST) / bne rts / jsr 0x1de58 cm550_calculateFourDimensionalFueling / move.w d0 -> 0x80d33e (1053 +0 5DFL four_dimensional_fueling) and 0x80ded2 (1050 +0 FSDSFL fuel_demand_selected).
- One call: jsr at 0x1b584 in cm550_runEvery4FramesTaskSetPhase1, between cm550_runAllSpeedGovernor and smoothPowerTakeOffReferenceEngineSpeed.
- CM848 0x1e830 cm848_updateFourDimensionalFueling: lha 0x40b000 (1050 +2) cmpwi 8 / bl 0x1ec70 / sth 0x40a887 (1053 +0) / sth 0x40affe (1050 +0); called by cm848_runEvery4FramesTaskSetPhase1 between cm848_runOperatingModeSpeedGovernor (+ temperatureBasedFuelTrim) and smoothPowerTakeOffReferenceEngineSpeed.
- Verdict: TWIN (same steps/order/constant 8/same e2m records/same task-set slot). Shared name updateFourDimensionalFueling (callees differ: CM550's 4D calc adds an increment per CM848 plate, so callees stay prefixed).

## CM550 0x19ac2 cm550_delayWithWatchdogServiceWrapper2 (WRONG name)
- asm: jsr 0x34674 (mc68k_initializeSpeedMeasurementMode0); rts. No delay, no watchdog.
- One call: jsr at 0x17188 = step 2 of engine_position_signal_configuration 0 in cm550_initializeEnginePositionSignalInputs (switch on byte 0x807e9d, jump table 0x17166: 0 -> 0x17182: 0x1999c, 0x19ac2, 0x19aca).
- 0x34674 in configuration 0: TPU ch0 function 0xc, param2 = 0x807ec8/6, param1 = 0xe, param0 = 0xb, HSQR1/HSRR1 = 1, CPR1 = 2, CIER bit 0, handler 0x808edc = 0x19c88 (RTE handler that calls mc68k_configureTpuChannelsForSpeedMeasurementMode 0x34a82). Other callers of 0x34674: 0x19e86 (end of config 1 step 2 0x19dd0), 0x1a522 (end of config 2 step 2 0x1a47c), 0x1a89a (config 3 step 2, same 2 instructions, named cm550_initializeSpeedMeasurementMode3).
- No CM848 counterpart (no engine position signal configuration switch there).

## CM550 0x19aca cm550_emptyStubFunction7
- single rts; one call jsr at 0x1718e = step 3 of configuration 0 (after 0x1999c, 0x19ac2). Siblings named round 96: cm550_emptyEnginePositionSignalConfiguration1/2/3ThirdStep (0x19e8e/0x1a52a/0x1a8a2).
- Name: cm550_emptyEnginePositionSignalConfiguration0ThirdStep. No CM848 counterpart.

## CM550 0x1b39a mc68k_dutyCycleMonitorBufferInit (WRONG name)
- One call: jsr at 0x183bc = cam sync type 2 branch of 0x1839a (cm550_canRpmModeConfigInit, switch on word 0x807f26 EPCMSYTY 11AD +2: 0 -> 0x1b1ea, 1 -> 0x1ae22, 2 -> 0x1b39a).
- Body: fills backup pulse period table 0x80ceae.. with initial value, sets next pointer / per-cam sum 0x80d074 / per-cylinder average (same as 0x1b1ea), THEN disables ch1 (CPR1 bits 3-2, CIER bit 1, CISR bit 1), CFSR3 bits 7-4 = 0xd, param1 = 0x100, param3 = 0, param4-5 (0xffff18) = 0, param0 = 0xb, HSQR1/HSRR1 bits 3-2 = 3, CPR1 = 2 (0x8), handler 0x808ee0 = 0x1b4b2 (mc68k_tpuChannel1SpeedMeasurementResetInterruptHandler), CIER bit 1; clears 0x80d2cc (CSCMPSCU-area byte eps_pulse_count_since_addtnl_eps_pulse) and long 0x80d2d2.
- vs 0x1b1ea (type 0): unconditional (no engine_speed_sensor_enable_flags bit 3 test), different handler (0x1b4b2 vs 0x1b30a), table filled before the channel disable, clears the two counters. vs 0x1ae22 (type 1): param0 0xb not 0x4f, HSQR 3 not 0, handler 0x1b4b2 not 0x1af32, no cam_sync_state reset.
- Suggested: mc68k_initializeTpuChannel1SpeedMeasurementResetInput. CM848: none (CM848 cam input set-up is TPU-A ch1 PMA, different code).

## CM550 0x1af32 mc68k_dutyCycleMonitorIsrHandler (WRONG name)
- Installed as TPU ch1 handler (0x808ee0) by 0x1ae22 mc68k_initializeTpuChannel1BackupSpeedInput (cam sync type 1) - move.l #0x1af32 at 0x1aec6. Ends RTE.
- Reads ch1 param5 low byte (0xffff1b) = CI tooth count (CMSNTTCU 0x80d2be), clears param4, reloads 0x80d2c2 (misnamed can_tx_message_type) from 0x807f9d (CI_LOST_COUNT_MAX low byte). Tooth count = wide CI expected (0x807f98) or narrow (0x807f9a): CI tooth count error 0x80d2c0 decremented (0 -> clears fault word 0 bit 0); then EPS tooth counter vs expected at wide/narrow CI falling edge (0x807f94/0x807f96): match -> cam_sync_state/cam_sync_status (0x80d0cc/0x80d0cd) = 1, clear word 2 bit 11, crank tooth count error 0x80d2bf decremented; mismatch -> 2 (lost), counter resynchronised, crank tooth count error counted to 0x807f9e then fault word 0 bit 0 + word 2 bit 11. Neither width -> CI error counted to 0x807f9f then word 0 bit 0. Then mc68k_resetSpeedMeasurementMode0, empty hook, clear CISR bit 1.
- Suggested: mc68k_tpuChannel1CylinderIdentificationPulseInterruptHandler. CM848 counterpart: mpc555_handleCamSignalInterrupt 0x457d0 (TPU-A ch1 cam signal handler running cam sync state; different algorithm).

## CM550 0x1a6e8 mc68k_crankFuelAndTimingBufferStore (WRONG name)
- Installed as TPU ch0 handler (0x808edc) by 0x1a47c mc68k_initializeTpuChannel0MissingToothInputMode2 (move.l at 0x1a510) = engine_position_signal_configuration 2. RTE.
- Reads 0xfffffc (TPU ch15 param6): high byte -> 0x80d293 (PMM error type CKSYERTY), low byte (0xfffffd) -> 0x80d292 (CKSYERTT); type 0xc0 -> cam_sync_state & cam_sync_status = 0, else = 2; jsr 0x34a82 mc68k_configureTpuChannelsForSpeedMeasurementMode; clear CISR bit 0.
- No fuel, no timing buffer. Siblings: 0x19c88 (config 0 ch0 handler: only 0x34a82 + CISR), 0x19f82 (config 1 ch0 handler, error type 0/0xff tests, longer).
- Suggested: mc68k_tpuChannel0MissingToothInterruptHandlerMode2. CM848 counterpart: mpc555_updateCrankSyncState 0x45478 (TPU-A ch0 crank sync state machine).

## CM550 0x17a8e cm550_frictionalLoadTorqueInterpolator (WRONG name)
- Step 1 of crank entry set-up in 0x17d2a cm550_engineModeTransitionHandler (bsr.w 0x17d52; runs on STOPPED->CRANKING or RUNNING->REENTRY, then 0x17baa, 0x17b8a; 0x17ca6 always; previous state 0x8005f0).
- Coolant filtered 0x80a336; fault word 2 (0x806004) bit 0 or 1 set and enabled (0x806ac0) OR coolant < CKCDCLTP 0x807eee -> crank initial fuel 0x80d0a6 (105E +E CKIIFL, no row) = cold fueling 0x807ef8, crank_initial_fuel_break_speed 0x80d0b2 (105E +1A CKIIFLES) = cold RPM 0x807efc; coolant > CKHTCLTP 0x807eec -> hot values (0x807ef6 CKHTCLFL, 0x807efa CKHTCLES); between: linear interpolation of both.
- CM848 counterpart: 0x1bc30 cm848_calculateColdStartTempTable (step 1 of cm848_processColdStartAdjustment): crank_initial_fuel (105E +16 CKIIFL) by coolant x barometric 2D table, break speed by 1D coolant table, coolant sensor faults -> defaults, overrides. Different code => counterpart.
- Suggested: cm550_calculateCrankInitialFuelByCoolantTemperature (matches step 2 name cm550_calculateCrankInitialAdvanceByIntakeManifoldTemperature).

## CM550 0x17b8a cm550_rpmSourceSelectorForFrictionalLoad (WRONG name)
- asm: cmpi.w #1,(0x803f8a CKEXESSW 1254 +3C) / bne / move.w 0x807eea (CKCNEXES 105F +0) -> 0x80d0ac crank_exit_speed (105E +14 CKEXES) / else move.w 0x80db02 (LSRF lsg_breakpoint_speed) -> crank_exit_speed.
- Step 3 of crank entry set-up (bsr.w at 0x17d5a).
- CM848 0x1bd44 cm848_selectColdStartRpmLimit: lha 0x3fd872 crank_exit_speed_switch_cal (1254 +38 CKEXESSW) cmpwi 1 / bne -> LSG reference 0x40aec2 else crank_exit_rpm 0x406860 (105F +E CKCNEXES) / sth crank_exit_speed 0x40a7aa (105E +12 CKEXES); step 3 of cm848_processColdStartAdjustment (same state-entry condition).
- TWIN. Shared name: selectCrankExitSpeed.

## CM550 0xfa06 vp44State2TransitionHandler (WRONG name, no VP44)
- asm: andi.l #0x40 of 0x803cac (algorithm_enable_flags_12_cal LSG droop enable) && tst (0x80daf4 LSDPSE 1065 +16 droop slope) -> point 1 speed 0x80da38 (1102 +22 JCTQRPP1) = LSRF 0x80db02 - slope*fueling 0x808168 (1104 +A JCDQFLIS)/0xa7, clamped >= 0; else = LSRF. point 1 fueling 0x80da42 (1102 +2C JCTQFLP1) = 0x808168.
- Callers: bsr.s 0xfa7e (in setJ1939TorqueCurvePoints1And3AtDeratedFueling 0xfa68, shared twin with CM848 0x20bfc), bsr.w 0xfc52 / 0xfcac (cases 2 and 3 of the torque curve builder 0xfb26).
- CM848 0x20b84 cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling: same bit 0x40 (rlwinm 25,25) of algorithm_enable_flags_12_cal, nonzero 0x40aeda (CM848 calls it governor_integrator_correction_term; no e2m row), LSG reference - term*j1939_derated_fueling_at_idle(1104 +A)/167, clamp 0, -> 1102 +22; fueling 1104 +A -> 1102 +2C. Called by 0x20bfc and cases 2/3 of 0x20d10.
- TWIN. Shared name setJ1939TorqueCurvePoint1AtDeratedIdleFueling.

## CM550 0xfb26 vp44_fuelLimitExceedanceStatisticsAccumulator (WRONG name)
- J1939 engine configuration torque curve builder (PGN 65251, e2m 1102): mode index +4 LSG base reference (0x803b9e) outside LSRF +/- delta (0x80817c), +2 altitude derate (FUELING_STATE 15) or AFC derate (16) with fault word 1 bit 9/10 (enabled), +1 speed limit source (0x80d644) 1/2/4/5 (hsg reference for droop 0x800182 = 0x80d648 else 0x80d64e); jump table 0..7: cases call 0xfa06, 0xfa68, cm550_calculateGovernorDroopSpeed; percent torques (fueling - zero-torque fueling 0x...) x 0x6400 / (peak fueling - zero fueling) clamp 32000; copies speeds; resets fuelings to fuel_demand_maximum.
- One call: jsr at 0x33228 in buildPgn65251EngineConfiguration1Payload (0x3320e).
- CM848 0x20d10 cm848_updateJ1939EngineConfigurationTorqueCurve (called by buildPgn65251EngineConfiguration1Payload 0x1b3a0): same frame, but +1 also for source 12, percent torque divides by per-point reference fueling, caches calculated fuelings (+36..+3E). => counterpart.
- Suggested: cm550_updateJ1939EngineConfigurationTorqueCurve.

## CM550 0x23be8 diagnosticMainStateProcessor (unprefixed, not a twin)
- One call: jsr at 0x2480a in cm550_updateLampOutputsAndCheckLampDriverFaults (0x24804, 50 ms task) after cm550_applyLampRequestsToOutputs.
- While bit 0 of 0x80bcce (DSKYSWSS key switch, e2m 000E +0) is set, for the 7 lamp driver bits of 0x80bd02 (e2m 000E +34 LCLP01FB..LCLP07FB driver output status; misnamed status_of_the_water_in_fuel_lamp_output_on_off) vs feedback 0x80bd08 (io_driver_port_1_feedback), in bit order 0,1,2,6,4,5,3: match -> both fault debounce counters 0 and a latched fault (not first-occurrence) clears after the clear debounce _DAT_000611ca; mismatch commanded-off -> counts the ch open-circuit counter to _DAT_000611c8 then sets one bit; commanded-on -> short-circuit counter then the other bit, in system error words 7/8 (+ first-occurrence flags).
- CM848: no lamp driver feedback check found. CM848 0x1d9b8 'diagnosticMainStateProcessor' is a different function (fault scan) -> CM550 needs own prefixed name: cm550_checkLampDriverOutputFaults.

## CM848 0x1d9b8 diagnosticMainStateProcessor (check)
- Called by cm848_runEvery4FramesTaskSetPhase1 (20 ms). Skips fault words whose detected and previous-pass words are 0 (50 words), then cm848_buildFaultConditionMask + cm848_processFaultScanGroup, advances fault_scan_index (wrap at 50); diagnostic_clear_request_state bit 0 -> cm848_clearDiagnosticState; OBD fault handler enable + new monitor-complete bits -> cm848_registerFaultsOfCompletedMonitors + cm848_markFaultsOfCompletedMonitorsHandled; builds system_switch_status / _2 from switch and output request bits; key_on_hour_meter moved > 24 -> cm848_countDownPreviouslyActiveFaults.
- CM550 counterpart: cm550_faultFlagScannerAndProcessor 0x14dc6 (same frame: skip empty words of 32, cm550_processFaultScanGroup, clear request cm550_clearInactiveFaultsOnRequest, switch status words 1-3 from a bit table 0x807980.., countdown > 24). Counterpart (CM848 adds the condition mask and the OBD monitor step; switch words by fixed bits) -> CM848 name must be prefixed: cm848_runPeriodicFaultProcessing (suggestion).

## CM550 numbered stubs (all single rts, verified bytes 4e75)
- 0x15f8c stub 4: one jsr at 0x1598a in mc68k_sampleAndDebounceDiscreteInputs (its only call), after the idle increment/decrement switch-pair fault (word 7 bit 1, 50 passes) and before the air conditioner pressure switch decode (bit 1 -> air_conditioner_pressure_switch_state bit 0). -> cm550_emptyDiscreteInputSamplingStep. CM848: none.
- 0x19aca stub 7: config 0 third step -> cm550_emptyEnginePositionSignalConfiguration0ThirdStep.
- 0x26852 stub 10: bsr.s at 0x2685e, first instruction step of mc68k_initializeSerialEepromDriverAndLoadMirror before the QSPI vector store 0x808f20 = 0x26834. -> cm550_emptySerialEepromDriverInitializationStep. CM848 cm848_initEepromDriverAndLoadMirror: no call there.
- 0x30b0e stub 11: jsr at 0x28774 in mc68k_applicationMain start-up list (breadcrumb 0x810ffc = 0x877a), after mc68k_scheduler_init, before undumped 0x42ad4; address between cm550_initializeTripInformation (0x30ade) and cm550_applyMaximumTimingAdvanceLimit (0x30b10). CM848 has cm848_initSensorDefaults / cm848_initFuelFilterCoefficients at that place (after initializeEngineState, before cm848_initializeCommandedThrottleState) - not empty. -> cm550_emptyStartUpStepAfterSchedulerInitialization.
- 0x26b82 stub 12: jsr at 0x287da (breadcrumb 0x87e0), after cm550_initializeLowSpeedGovernorIdleAdjustment, before undumped 0x4cf42. -> cm550_emptyStartUpStepAfterLowSpeedGovernorIdleAdjustment.

## CM848 numbered stubs (all single blr 4e800020)
- 0x54220 cm848_emptyStubFunction: one bl at 0x549c8 in cm848_applicationMain start-up list, between cm848_resetDataCollector and cm848_initializeEngineRetarderCruisePermissionFilter; address between mpc555_enableSchedulerMiosOutput (0x541f4) and cm848_checkRpmOverspeedProtection (0x54224). -> cm848_emptyStartUpStepAfterDataCollectorReset.
- 0x1806c stub 3: one bl at 0x54c84 in cm848_applicationMain between cm848_initializeCoolantTemperatureSource and cm848_initialization_step_14; address right before calculateJ1939PercentPeakTorqueAtSpeed (0x18070), after cm848_calculateEgrDeltaPressures. CM550 has no rts before 0x142d4. -> cm848_emptyStartUpStepAfterCoolantTemperatureSource.
- 0x26f7c stub 5: one bl at 0x53b14 = the else branch of cm848_handleJ1939CanReceiveInterrupt (mailbox n not in transmit-object < n <= last receive object). CM550 cm550_handleJ1939CanReceiveInterrupt (0x1e086) just returns there (no hook). Next to ignoreCanTransmitInterrupt 0x26f78. -> cm848_ignoreNonJ1939CanReceiveInterrupt.
- 0x2c0fc stub 6: one bl at 0x1015c in cm848_selectVariableSpeedGovernorMode on entry to FUELING_STATE_VARIABLE_SPEED_GOVERNOR, between cm848_calculateAllSpeedGovernorThrottleReference and cm848_calculateGovernorCompensatorCoefficients; address right after cm848_blendAllSpeedGovernorReferenceSpeeds. CM550 cm550_selectVariableSpeedGovernorMode calls 0xd3e6 there (not empty). -> cm848_emptyVariableSpeedGovernorEntryStep.
- 0x55e9c stub 8: no bl; 23 unaligned 4-byte pointers in the TPU channel interrupt handler tables: TPU-B table 0x583ae (13 of 16 entries: all but ch1 0x50f680, ch2 0x526ce4, ch9 0x516274, ch14 0x3fa5c) used by mpc555_tpuBInterruptDispatcher (lis/addi 0x583ae at 0x55dbc) and TPU-A table 0x583ee (10 of 16: all but ch0 0x45478, ch1 0x457d0, ch6 0x529640, ch10 0x5283d0, ch11 0x44fa8) used by mpc555_tpuAInterruptDispatcher (blrl at 0x55e88). = the handler of unused TPU channels. -> cm848_ignoreUnusedTpuChannelInterrupt.

## CM848 cbd names
- hpcr_cbdFillAccelerationBuffers 0x42bd0 (called from hpcr_processEngineSyncPulses 0x44fa8 = TPU-A ch11 handler): with cbd_enable_flag or misfire speed buffer flag, crank sync 4: at start tooth (cylinder_balance_start_tooth or misfire start tooth) arms capture (cylinder_event_seq_counter 0), then per cylinder event stores (TPU-A ch14 32-bit capture delta)>>2 into cylinder_balance_acceleration_buffer_1.. -> hpcr_fillCylinderBalanceAccelerationBuffers. Counterpart of mc68k_fillCylinderBalanceSpeedBuffers (segment period sums, 7 speed buffers).
- hpcr_cbdCalculateCylinderTrims 0x42d78 (executive frame 3 of executiveFrameInterruptHandler): Fourier components, dynamic compensation, trim pattern projections (stack local_48), trim learning -> hpcr_calculateCylinderBalanceTrims. Counterpart of cm550_calculateCylinderBalanceTrims (frame 38).
- hpcr_cbdInitFilterState 0x43a5c (start-up list): cylinder_event_seq_counter = 0xff, stop compensation cache offsets = 2, copies cylinder_balance_fueling_trim_cal into 0x3fb580 (power-up trims) -> hpcr_initializeCylinderBalancing. Counterpart of cm550_initializeCylinderBalancing.
- global cbd_enable_flag 0x408ef6 byte: e2m 81AE +14 CBD_Enable; ROM-copied window (no _cal) -> cylinder_balance_enable_flag (CM550 0x8072c0 same concept, record 823C +34 CBDEN).

## Enum J1939_DIAGNOSTIC_SERVICE (CM550 stale members), verified by asm
- registration: CM550 0x226da and CM848 0x50c880 both register 0x43, 0x4a, 0x4c, 0x46, 0x48 in this order.
- 0x43 (0x22530): ID bytes 1-2, length bytes 3-6, offset 0 -> 0x224f4 -> READ_BY_PARAMETER_ID_LONG_LENGTH (old MEM_READ_2B_PARAM_4B_OFFSET is wrong: 4 bytes are the length).
- 0x46 (0x2257c): ID 1-2, offset 3-4, length 5 -> READ_BY_PARAMETER_ID_SHORT_OFFSET (old MEM_READ_2B_PARAM_ONLY wrong).
- 0x48 (0x225e0): ID 1-2, offset 3-6, length 7-10 -> READ_BY_PARAMETER_ID_LONG_OFFSET.
- 0x4a (0x22646): address 1-4, length 5 -> 0x2238e -> READ_MEMORY.
- 0x4c (0x2268e): address 1-4, length 5-8 -> READ_MEMORY_LONG_LENGTH.
- bonus 0x41 DIAG_ADDR_RESOLVER: handler 0x222b4 (cm550_canDiagnosticResponseSender) reads ID 1-2, cm550_lookupParameterIdAddress, sends 7-byte 0x42 frame with ID + 4-byte address on 0xEF00 to requester, else 8 -> J1939_DIAGNOSTIC_SERVICE_GET_ADDRESS_BY_PARAMETER_ID (CM848's member).

## CM550 globals
- 0x8002ac..0x8002c3: ONE i32[6] array (max search loop a2 = 0x8002b0 step 4, 5 compares vs [0]) of trim pattern projections, written twice in cm550_calculateCylinderBalanceTrims: pass 1 with component 1 (CBDFRC1 0x809206 / CBDFIC1 0x80920a) and reference 1 vectors (0x8072c2..cc) -> argmax -> CBDTI1 0x809260; pass 2 with adjusted component 2 (CBDARC2 0x809276 / CBDAIC2 0x809278) and reference 2 (0x8072ce..d8) -> CBDTI2 0x809262. [0] 0x8002ac = (ref cyl1 imag x imag + ref cyl1 real x real)/10000; [4] 0x8002bc = same with cyl5; [2] 0x8002b4 = cyl3; [5] 0x8002c0 = -[0]; [1] 0x8002b0 = -[4]; [3] 0x8002b8 = -[2]. No e2m record. Overlapping rows 0x8002b0/b2/b6/b8/bc/be/c0 are all inside it. CM848 keeps the same 6 values in a stack array (local_48) of hpcr_cbdCalculateCylinderTrims (no global).
- 0x80a982 STUOTHGV (107C +16): = CM848 0x40a1c0 variable_speed_governor_selected_flag (same record). Writers cm550_selectVariableSpeedGovernorMode (FSTHGVOP 0x803bf0 or its inverse when STCG enable bit + switch) and cm550_fuelBlendTablePointerSetup (start-up copy); readers cm550_selectVariableSpeedGovernorMode (==1 -> state 7), cm550_updateElectronicSmartPowerTau.
- 0x80db04 LSCIRF (1067 +2 'COLD IDLE LSG REFERENCE SPEED', RPM): only cm550_calculateLowSpeedGovernorColdIdleSpeed (a2 = 0x80db04 at 0x2661c): set to LSCIRFSR (0x80833c) when stopped and cold else 0; ramps down by LSCIRMRT while running when time up or warm; raises LSDSRFRP (0x80db06) to it. Not an adder. -> low_speed_governor_cold_idle_reference_speed. CM848: no row of 1067 (block 1496 not in its table); concept counterpart low_speed_governor_coolant_temperature_speed_request.

## Extra checks (late)
- CM848 0x1820c: no bl / b / pointer / lis+addi reference anywhere (ppc_callers + unaligned byte search) -> orphan; twin verdict for 0x143b6 rests on identical body + callees + e2m outputs; caller side differs (CM550 J1708 0x46 builder 0x1f2d0, CM848 none).
- CM848 0x20b84 callers 0x20c08 (in 0x20bfc), 0x20e64 / 0x20ef0 (cases 2 / 3 of 0x20d10) = CM550 0xfa06 callers 0xfa7e (in 0xfa68), 0xfc52 / 0xfcac (cases 2 / 3 of 0xfb26).
- CM848 0x1bd44 caller 0x1bfa0, 0x1bc30 caller 0x1bf98, both in cm848_processColdStartAdjustment (0x1bf44) = CM550 0x17d2a structure (STOPPED->CRANKING or RUNNING->REENTRY: step1 initial fuel, step2 initial advance, step3 exit speed; then check step; previous state).
- 0x80bd08 = byte read from CS2 device 0xffd004 by mc68k_ioDriverStrobeHandler (0x15b88) = lamp driver feedback; 0x80bd02 written at 0x15d06 = (override value & override mask) | (computed & ~mask) = commanded lamp driver outputs (e2m LCLP01FB..07FB).
- 0x23be8 role counterpart in CM848: cm848_monitorDiscreteOutputReadBack 0x538278 / cm848_checkDiscreteOutputReadBack 0x537c64 (11 discrete outputs, retries, cruise special case) - not the fault scanner 0x1d9b8.
- CM848 0x40aeda (governor_integrator_correction_term, no e2m row) sits where CM550 has LSDPSE droop slope (1065 +16); CM848's LSDPSE record is 1497 +4 (block not in its table) - lead only.
