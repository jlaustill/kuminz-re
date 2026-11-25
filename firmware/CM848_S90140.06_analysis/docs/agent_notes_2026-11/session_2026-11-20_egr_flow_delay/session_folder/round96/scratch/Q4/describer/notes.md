# Q4 describer notes (round 96)

Batch: 30 CM550 placeholders in 0x0-0xffff and 0x20000-0x2dfff.
Status: started 2026-11-25. Entries below are findings I am sure of. ALL 30 DONE (final output = StructuredOutput).
Registrar position also checked: CM550 mc68k_initializeJ1939Datalink ... registerJ1939InputMessageHandlers, 0x226da, 0x22370 (svc 0x41), registerJ1939MemoryWriteServices,
 registerJ1939DiagnosticHandlers = CM848 cm848_j1939_system_init ... registerJ1939InputMessageHandlers, (callback), cm848_registerJ1939MemoryReadServices,
 cm848_registerJ1939GetAddressByParameterIdService, registerJ1939MemoryWriteServices, registerJ1939DiagnosticHandlers.
 Same list also puts 0x33064 (EEC2 init, caller of 0xf99a) where CM848 has cm848_initPgn61443Eec2Handler.

## PGN 61184 memory READ services (0x22530 .. 0x226da) - SURE
Registrar 0x226da (called by mc68k_initializeJ1939Datalink) does registerJ1939DiagnosticService (0x2ee62) x5:
0x43->0x22530, 0x4a->0x22646, 0x4c->0x2268e, 0x46->0x2257c, 0x48->0x225e0 (asm 0x226dc-0x2271c).
CM848 cm848_registerJ1939MemoryReadServices 0x50c880: 0x43->0x50c640, 0x4a->0x50c7b0, 0x4c->0x50c81c,
0x46->0x50c6a8, 0x48->0x50c734, via registerJ1939DiagnosticService 0x220e4 (twin of 0x2ee62). Same order.
Helper 0x224f4 (NOT a Ghidra function, no row; decompiler shows FUN_000224f4 with params lost):
 cm550_lookupParameterIdAddress(id, &addr) -> 8 when nonzero; else cm550_diagMemoryReadResponseBuilder(request, addr+offset, length).
 = twin of CM848 cm848_readJ1939DiagnosticMemoryByParameterId 0x50c5d0 (same steps, returns 8).
Handlers (asm; the decompilation of 0x2257c drops the byte copies, of 0x22530/0x225e0 drops the args):
- 0x22530 svc 0x43: id = data[1..2] (memcpy 2), length = data[3..6] (memcpy 4); 0x224f4(req, id, offset 0, length).
  CM848 0x50c640 identical (li r5,0). Twin.
- 0x2257c svc 0x46: id = data[1..2]; offset = 0:0:data[3]:data[4]; length = 0:0:0:data[5]; 0x224f4(req,id,offset,len). CM848 0x50c6a8 identical.
- 0x225e0 svc 0x48: id = data[1..2]; offset = data[3..6]; length = data[7..10]; 0x224f4. CM848 0x50c734 identical.
- 0x22646 svc 0x4a: address = data[1..4]; length = 0:0:0:data[5]; 0x2238e(req, addr, len). CM848 0x50c7b0 identical (0x50c42c).
- 0x2268e svc 0x4c: address = data[1..4]; length = data[5..8]; 0x2238e. CM848 0x50c81c identical.
Reply table at 0x22384 (index service-0x43): 45 00 00 47 00 49 00 4b 00 4d -> 0x43->0x45 (0x44 when <256 in 0x2238e), 0x46->0x47, 0x48->0x49, 0x4a->0x4b, 0x4c->0x4d - matches CM848 rows.
Write side was made shared in round 94 (handleJ1939WriteByParameterId*Service, registerJ1939MemoryWriteServices).
=> shared names = CM848 names without cm848_ (both rows change):
 0x22530 handleJ1939ReadByParameterIdLongLengthService; 0x2257c handleJ1939ReadByParameterIdShortOffsetService;
 0x225e0 handleJ1939ReadByParameterIdLongOffsetService; 0x22646 handleJ1939ReadMemoryService;
 0x2268e handleJ1939ReadMemoryLongLengthService; 0x226da registerJ1939MemoryReadServices.
 No collision in either CSV (grep).

## 0xb3d0 cm550_FUN_0000b3d0 - SURE: ANC (acceleration noise control) TIMING limit computation
Caller: cm550_runEvery10FramesTaskSetPhase1 (0x1b6c8, call 2, every 10 frames). asm 0xb3d0-0xb4cc.
Gate: algorithm_enable_flags_3_cal bit 0x2000 (acceleration_noise_control_timing_limit_enable).
Steps: bare-engine latch: ESFT01AC (0x80a294) > NZTAACTR (0x807a50) -> NZTALMIH (0x80a2a4)=1 and timer 0x800040 = NZTAIHTM (0x807a4e);
 else timer 0x800040 counts down, at 0 NZTALMIH=0.
 Conditions = ASANENF(0x80a2a8)!=0 && !NZTALMIH && coolant filtered (0x80a336) > NZTACLTR (0x807a38, unsigned) && ESFT01AC <= NZTAACTR && ESFT02AC (0x80a296) >= NZTAFTTR (0x807a3e):
 NZTALMSS (0x80a29a)=1, timer 0x800044 = NZTADYTM (0x807a3a). Else override ASANODFG (0x80a2a6) does the same; else 0x800044 counts down, at 0 NZTALMSS=0.
 NZTALMSS==1: lookup x = 0x80ccf4 (current_engine_rpm_filtered) -> NZTALM (0x80a28e) = cm550_lookupTableInterpolation(0x800058 NZTALMXA/YA table).
 else NZTALM < 1024: += NZTARMRT (0x807a3c), capped at 1024.
Return value: d0 left over; callers ignore it -> void.
Siblings (same skeleton, other enable bits): 0xb2aa fuel limit (bit fuel_limit_enable, speed >= NZFLTRES, output NZFLLM 0x80a28c, ramp to fuel_demand_maximum);
 0xb4f2 speed limit (bit engine_speed_limit_enable, speed <= NZESTRES, output NZESLM 0x80a290 = NZCNESLM constant, ramp to maximum rated speed).
 Discriminator of 0xb3d0: timing enable bit, COOLANT temperature gate, the timing table lookup, the 1024 ramp ceiling.
CM848: none. CHR e2m has 10A4 ANC_Timing (NZTALM) -> 0x40a04a, status 0x40a04c, inhibit 0x40a04e but NO code accesses them;
 cm848_passCompensatedTimingToCombustionLimits (0x17b54) plate: "The ANC timing stage's place (e2m 10A4; compiled out)".
Global 0x800040 (no row, no e2m record): written only here - the NZTALMIH inhibit countdown (load NZTAIHTM, subq.w, clears NZTALMIH at 0).
 -> acceleration_noise_control_timing_limit_inhibit_timer (word). Siblings 0x80003c (speed, 0xb4f2) / 0x80003e (fuel, 0xb2aa) same role.
Note 0x800044 anc_timing_limit_active_timer is typed undefined (renders _anc_...): word accesses only (tst.w/subq.w/move.w).
Name: cm550_calculateAccelerationNoiseControlTimingLimit.

## 0xc87c / 0xc87e - SURE: single rts each (asm 0xc87c: 4e75, 0xc87e: 4e75)
0xc87c: called in all 4 modes of mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0-3 (0x19acc/0x19e90/0x1a52c/0x1a8a4), ISR tail,
 between cm550_rpmTimingDeltaComparatorWithReturn and mc68k_FUN_0001266e, before vp44_communication_state_machine(1) and TPU_CISR &= ~0x400 (ch 10).
0xc87e: called at the tail of the TPU channel 1 (backup speed) ISRs mc68k_dutyCycleMonitorIsrHandler 0x1af32 / mc68k_FUN_0001b30a / mc68k_FUN_0001b4b2,
 after mc68k_resetSpeedMeasurementMode0, before TPU_CISR &= ~2 (ch 1).
Precedent for empty bodies: cm550_emptyStubFunction10 / 11 (rounds 94/95) - CM550 uses 4, 7, 10, 11 now.

## 0xc880 cm550_FUN_0000c880 - SURE: start-up initializer of speed_request_blend_weight_by_speed_difference_lookup (0x800102)
asm: move.w #2,(0x800102); (0x800104).l = 0x807acc (ASTHPFXA axis, e2m 1326); (0x80010a).l = 0x807ad8 (ASTHPFYA values, 1327); rts.
Caller: mc68k_applicationMain start-up (step id 0x8876). Only other user of the record: 0xc8a0 (writes x_input 0x800108, calls the lookup).
CM848: the same tables (0x5c272/0x5c27e) are passed directly to lookupTableInterpolation in cm848_calculateGovernorReferenceSpeedBlend -> no init step, no counterpart.
Name: cm550_initializeSpeedRequestBlendWeightLookup.

## 0xd3b2 cm550_FUN_0000d3b2 - SURE: ASG reference-speed set pointers + preset of the droop/set selection flag
asm 0xd3b2-0xd3e4: (0x80a9ac).l=0x803bbc ASMNRF (0008+20); (0x80a9b0).l=0x803bbe ASMXRF (+22); (0x80a9b4).l=0x803bca ASMNRF02 (+2E); (0x80a9b8).l=0x803bcc ASMXRF02 (+30);
 move.w 0x803d5a (ASDPFGTN 1387+8 'trim for ASG droop selection flag') -> 0x80a9a2 (ASDPFG 107A+16 'ASG droop selection flag').
Caller: mc68k_applicationMain start-up (0x8726). Readers of the 4 pointers: only 0xd2be (cm550_acceleratorThrottleFaultDetector, misnamed):
 ASDPFG==0 -> ASMNRP/ASMXRP (0x80a9a4/6) = *ptr1/*ptr2, ==1 -> *ptr3/*ptr4; then ASG reference = min + throttle*(max-min)/400.
RAM dump: pointers = 0x803bbc/0x803bbe/0x803bca/0x803bcc; ASDPFGTN=1, ASDPFG=1, ASMNRP=5200 (=ASMNRF02), ASMXRP=34304 (=ASMXRF02).
CM848 counterpart (not twin): cm848_initializeAllSpeedGovernorTuningSetBlendWeight 0x2c100 = only the copy ASDPFGTN -> ASDPFG (CM848 blends 0..128, no pointers).
Globals: 0x80a9ac all_speed_governor_minimum_reference_speed_1_pointer, 0x80a9b0 ..maximum.._1_pointer, 0x80a9b4 ..minimum.._2_pointer, 0x80a9b8 ..maximum.._2_pointer (word *).
 Targets (no rows, in EEPROM mirror -> _cal): 0x803bbc all_speed_governor_minimum_reference_speed_1_cal, 0x803bbe ..maximum.._1_cal, 0x803bca ..minimum.._2_cal, 0x803bcc ..maximum.._2_cal
 (the CM848 names of the same records ASMNRF/ASMXRF/ASMNRF02/ASMXRF02 at 0x3fdd14/16/22/24).
Name: cm550_initializeAllSpeedGovernorReferenceSpeedSelection (counterpart of CM848 0x2c100 - prefixed).

## User fueling selector chain (caller of 0x25806 and 0xd4ae) - SURE
cm550_engine_protection_coordinator 0x3458c: prev = user_fueling_state (0x80ded4); state = 0; then selectors 30 / 1 / 2(prev) / 5 / 0x25806(prev) / 0xd4ae(prev) / default.
CM848 cm848_resetEngineOperatingMode 0x42918: prev = mode; mode = 0; selectAllSpeedGovernorApplicationMode / setEngineOperatingMode1 /
 selectTsc1SpeedControlMode(prev) / selectUserCommandedFueling / cm848_transitionEngineOperatingMode(prev) 0x50daac / cm848_selectVariableSpeedGovernorMode(prev) 0x10110 / initEngineOperatingState.
=> position 5 = 0x25806 with CM848 0x50daac; position 6 = 0xd4ae with CM848 0x10110.

## 0x25806 cm550_FUN_00025806 - SURE: accelerator pedal fault (limp home, state 6) mode selector
asm 0x25806-0x258ac: tst.w 0x80821a (LHFLEN 10CE+C 'enable bit for the limphome fueling algorithm', no row) else return; user_fueling_state != 0: return;
 algorithm_enable_flags_5_cal (0x803c9e) bit 0x400 sampled_throttle_override_enable set: (0x80d70c OR 0x80d70e) j1939 position-error fallback / pedal timeout: state 6;
 clear: error status word 4 (0x806008) bit 1 AND enable[4] (0x806ac4) bit 1, or bit 2 pair, or bit 5 pair: state 6.
 state 6 and prev != 6: presetPedalFaultModeFuelDemand (0x258b0, shared twin).
Faults: sampled_throttle_sensor_config (A/D ch 10) high_error_fault_number = 65 (word 4 bit 1), low = 66 (bit 2) (dump bytes 0x806be6/7);
 bit 5 (fault 69) = the throttle mismatch / idle validation fault set by vp44_derateThresholdMonitorAndFaultController (0x10822).
CM848 counterpart (NOT twin): cm848_transitionEngineOperatingMode 0x50daac (no plate): pedal_fault_mode_enable_flag (0x5c49a = SAME record 10CE+C LHFLEN),
 mode 0, held-value bit 0x2000 selects j1939 fallbacks, else accelerator_pedal_input_fault_flag (dual channel) or P2123/P2122 bits 10/11; mode 6 + preset.
 Analog fault tests differ (constants), so counterpart.
Global: 0x80821a = pedal_fault_mode_enable_flag (CM848 name of the same LHFLEN record; outside the mirror, no _cal; word: tst.w).
Name: cm550_selectAcceleratorPedalFaultMode.

## 0xd4ae cm550_FUN_0000d4ae - SURE: variable speed governor (state 7) mode selector + the throttle-governor selection flag update
asm 0xd4ae-0xd582. Part 1 (= CM848 cm848_updateVariableSpeedGovernorSelection 0x2c6c4, inlined): when no_load_fuel_quantity (0x80db1c) + ASSDFUOF (0x807ac8, 107D+A, no row)
 above final_fueling (0x80d32e) and commanded throttle (0x80aa82) == 0: STUOTHGV (0x80a982) = FSTHGVOP (0x803bf0, 0008+54 'user indicator for enabling automotive governing through throttle', no row),
 inverted (1 to 0, 0 to 1) when algorithm_enable_flags_27_cal bit 3 (switched_throttle_control_governor_select) and throttle interlock switch byte 0x80bcd1 bit 1.
 Part 2 (= CM848 cm848_selectVariableSpeedGovernorMode 0x10110): user_fueling_state == 0 and STUOTHGV == 1: state 7, bsr 0xd3e6 (droop gains),
 and when prev != 7 and prev != 3: gain set pointer 0x80a9a8 = &0x807be0 (throttle mode set), clr 0x80a9a0 external reset, 0x80a99e = ASCNLOLM (0x807bde), 0x80a99c = ASCNHILM (0x807bdc), 0x80a984 coefficient ptr = 0x807bda (ASFTCF).
CM848 0x10110 differs: blends reference speeds, computes the throttle reference + compensator coefficients, copies 10 gains, only prev != 7: counterpart, not twin.
Globals (same e2m records as CM848): 0x80a982 STUOTHGV 107C+16 = variable_speed_governor_selected_flag (CM848 0x40a1c0);
 0x803bf0 FSTHGVOP 0008+54 (in mirror) = variable_speed_governor_default_cal (CM848 0x3fdd42, 0008+4E);
 0x807ac8 ASSDFUOF 107D+A (outside mirror) = all_speed_governor_switch_droop_fueling_offset (CM848 0x3ff68e, 107D+8).
Name: cm550_selectVariableSpeedGovernorMode.

## 0xf716 cm550_FUN_0000f716 - SURE: ASG droop-line fueling at the throttle reference speed (driver demand fuel in VSG mode)
asm 0xf716-0xf794: d2 = ASTHRFES (0x80a98c, 107A+0) - ENGRPM (0x80ccf6); if ASRFST (0x80a98e) == 7: (0x800180) = ASSLDP (0x80a99a, selected droop slope);
 droop (0x800180) == 0: return d2 > 0 ? 0x1700 : 0; else d2 = d2*0x2655 (mulu.l after ext.l) / (droop << 3) (divs.l) + ASNLFL (0x8091de, 1322+0); clamp: <=0 gives 0, >=0x1700 gives 0x1700.
Only caller: 0xf796 (cm550_paramSystemModeController, misnamed = the J1939 driver demand torque fueling selector) when FSTHGVOP (0x803bf0) == 1, into JCDRIDFL (0x80da36, 1102+20); else 5DFL (0x80d33e).
CM848 counterpart (not twin): cm848_calculateEffectiveFuelLimit 0x20554 (called by cm848_calculateDriverDemandPercentTorque 0x20860 when variable_speed_governor_default_cal == 1):
 its tail has the same droop line (reference - speed) x 0x2655 / (droop_snapshot << 3) + all_speed_governor_no_load_fuel with the snapshot refreshed only in mode 7,
 but CM848 adds the speed limiter fuel limit, the min of six fuel limits, a minimum droop branch and deadband compensation.
 0x1700 = 5888 counts = 400 mm3 (0.0679 per count); 9813 x 0.0679 x 0.0015 = 1 (CM848 row of all_speed_governor_droop).
Globals: 0x800180 (named anc_speed_limit_table_3_ptr, type undefined - WRONG: only access is here, word) = all_speed_governor_droop_snapshot (CM848 0x3fa8a2 same role);
 0x8091de (named rpm_control_override_flag - WRONG) = e2m 1322+0 ASNLFL = CM848 all_speed_governor_no_load_fuel (0x40a24a, same record).
Name: cm550_calculateAllSpeedGovernorDroopLineFueling.

## 0xf99a cm550_FUN_0000f99a - SURE: single rts, the empty step of the PGN 61443 (EEC2) transmit setup
Only caller 0x33064 (vp44_cumminsProprietaryDM_983_Builder - misnamed: it is the EEC2 transmit descriptor initializer):
 can_id 0xf00300 | (0x803f64 & 7) << 2, SA 0x80da01, length 5, data 0x8034aa, status 0x8034c0, jsr 0xf99a, then 0x2f47e(0xf003, 0x32e4c) (handler registration).
CM848 cm848_initPgn61443Eec2Handler (0x25d60) has the identical sequence and calls cm848_emptyStubFunction7 (0x20aec, one blr) in the same place,
 then cm848_j1939RegisterPgnHandler(0xf003, cm848_buildPgn61443ElectronicEngineController2Message). The next function in both ROMs is the nominal friction calc
 (CM550 0xf99c right after 0xf99a; CM848 0x20af0 right after 0x20aec) - same source order.
=> twin by position of CM848 0x20aec; shared name needs a role word (cannot come from an empty body).

## 0xf99c cm550_FUN_0000f99c - SURE: J1939 nominal friction percent torque (SPN 514, EEC3 byte 1)
asm 0xf99c-0xfa04: d2 = no_load_fuel_quantity (0x80db1c) - CLNTFL (0x808194, 10E7+16 zero torque fueling); <= 0: 0x80da1c = 0;
 d3 = JCRFEGFL (0x80da32, 1102+1C) - CLNTFL; <= 0: 0; else 0x80da1c = 0x165f2(d2 x 25600, d3) (saturating division), capped 32000.
Only caller: 0x330c4 (vp44_configParamCanBuilder - misnamed: the PGN 65247 EEC3 builder) - byte 1 = (0x80da1c >> 8) + 125, bytes 2-3 desired operating speed, byte 4.
CM848 cm848_calculateNominalFrictionPercentTorque 0x20af0 (called first by cm848_buildPgn65247ElectronicEngineController3Message):
 same steps, same 25600 / 32000, but its floors are -32000 with result 0x8300 (CM550: 0 with result 0) - method versioning; constants differ, so counterpart by the strict rule
 (precedent writeJ1939DiagnosticMemory shares a name despite small differences).
Global: 0x80da1c JCINFCTQ 1102+6 (sole writer 0xf99c; reader 0x330e2) = CM848 j1939_nominal_friction_percent_torque_times_256 (0x40ad90, same record).
 0x808194 CLNTFL = CM848 zero_torque_fueling (same record 10E7+16); 0x80da32 JCRFEGFL = CM848 j1939_reference_engine_fueling (same record).
Name: cm550_calculateNominalFrictionPercentTorque (or shared calculateNominalFrictionPercentTorque if version changes are accepted).

## 0xfa68 vp44_FUN_0000fa68 - SURE: TWIN of CM848 cm848_setJ1939TorqueCurvePoints1And3AtDeratedFueling 0x20bfc
asm 0xfa68-0xfaa4: bsr 0xfa06 (point 1 at derated idle fueling; 0xfa06 = vp44State2TransitionHandler, misnamed, = CM848 0x20b84 incl. the /167);
 if point 1 speed (0x80da38, 1102+22) > point 3 speed (0x80da3c, +26) (bhi, unsigned): point 3 speed = point 1 speed, point 3 fueling (0x80da46, +30) = point 1 fueling (0x80da42, +2C);
 else point 3 speed = 0x808162 (j1939_engine_speed_at_point_3), point 3 fueling = 0x80816a (fueling at point 3 when derated).
CM848 0x20bfc: bl 0x20b84; lhz point3 vs lhz point1 cmpw/blt (zero-extended, same as unsigned); same two stores each branch.
Position: both called only in cases 6 and 7 of the torque curve update (CM550 0xfb26 vp44_fuelLimitExceedanceStatisticsAccumulator - misnamed;
 CM848 cm848_updateJ1939EngineConfigurationTorqueCurve 0x20d10); adjacency 0xfa06/0xfa68 = 0x20b84/0x20bfc.
No VP44 content: the vp44_ prefix is wrong.
Name: shared setJ1939TorqueCurvePoints1And3AtDeratedFueling (CM848 row drops cm848_).

## 0xff48 cm550_FUN_0000ff48 - SURE: TWIN of CM848 cm848_initializeJ1939ReferenceEngineFuelingAndTorque 0x212dc
asm 0xff48-0xff6a: algorithm_enable_flags_18_cal (0x803cb8) & 0x200 (programmable_power_enable, bit 9) != 0: return;
 else 0x80da32 (JCRFEGFL 1102+1C) = 0x80815e (JCINPKFL 1104+0); 0x80da34 (JCRFTQ 1102+1E, no row) = 0x808160 (JCRFEGTQ 1104+2). rts (decompiled return = leftover d0; void).
CM848 0x212dc: lhz flags 18 (0x3fd5c0) rlwinm mask 0x200, bne out; 0x40ada6 = ROM 0x5c348 (1104+0); 0x40ada8 = ROM 0x5c34a (1104+2). Same steps/constants/records.
Position: last call of initializePgn65251EngineConfiguration1Buffer (already a shared twin, CM550 0x33692 = CM848 0x1b900), after the fault derate priority init (CM550 0x185f0 / CM848 cm848_initializeFaultDerateJ1939TorqueCurvePriority).
Globals (0xff48 is the sole writer of both): 0x80da32 = j1939_reference_engine_fueling (CM848 0x40ada6, same record; now determined_peak_engine_fueling_0_100);
 0x80da34 = reference_engine_torque_working (CM848 0x40ada8, same record; no row). Sources 0x80815e = j1939_peak_fueling, 0x808160 = j1939_reference_engine_torque (CM848 names).
Name: shared initializeJ1939ReferenceEngineFuelingAndTorque.

## 0x24804 cm550_FUN_00024804 - SURE: two-call task: lamp requests to the output image, then the port 1 output driver feedback check
asm: jsr 0x23a90 (cm550_applyLampRequestsToOutputs); jsr 0x23be8 (diagnosticMainStateProcessor - misnamed: 432 decompiled lines that compare
 io_driver_port_1_feedback bits 0-6 with the output image, each gated by a bit of value_used_for_monitoring_switch_data, and set/clear open and short circuit
 faults in error words 7 (0x400/0x800/0x1000/0x4000/0x8000) and 8 (0x1..0x100)); rts.
Caller: cm550_runEvery10FramesTaskSetPhase6 (0x1b714) call 1, then cm550_processJ1939AcceleratorInputs.
CM848: cm848_runEvery10FramesTaskSetPhase6 (0xbd28) calls only cm848_processJ1939AcceleratorInputs - nothing at this slot. CM848's output read-back check is
 cm848_updateOutputReadBackFaultBits (0x53a110, slot 2) and CM848 has no lamp request mapping here -> none.
Name: cm550_applyLampRequestsAndCheckOutputDriverFeedback (wrapper: the name comes from its two calls).

## 0x25a34 vp44_FUN_00025a34 - SURE: low speed governor integrator preset (bumpless entry into LSG)
Caller: cm550_runLowSpeedGovernor (0x25b1c) only when adjusted_user_fueling_state == LSG (11) and final_fueling_state != LSG.
asm 0x25a34-0x25b1a: bsr 0x2595a (cm550_governorFuelPidController - misnamed: 4D steady/transient fueling at LSAJRFES and throttle 400, alpha blend, into 0x801a6e
 = CM848 cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity 0x27d38); preset max LSMXITPZ (0x80daec) = clamp(LSMXPZOF (0x80823a) + 0x801a6e, 0, 0x1700);
 d2 = final_fueling - LSER (0x80dae0) x LSPPGN (0x80dac4) / 960 + ENGRPM x LSPP02GN (0x808268) / 2226, minus no_load_fuel_quantity when algorithm_enable_flags_32_cal bit 0x200
 (low_speed_governor_no_load_fuel_enable); clamp to [LSMNITPZ (0x80823c), preset max]; 0x801a6a (long) = d2 << 16 (integrator accumulator);
 LSFL (0x80dade) = final_fueling; LSDVFL (0x80dae4) = 0; 0x801a70 = ENGRPM; 0x801a72 = LSPPGN; 0x801a74 = LSPP02GN (previous values).
CM848 counterpart (not twin): cm848_presetLowSpeedGovernorIntegrator 0x27e4c (called by cm848_runLowSpeedGovernor): same skeleton (reference max fuel call,
 preset max = offset + it, accumulator = final_fueling - P term - arg, clamp, << 16, terms cleared, fueling working = final_fueling, previous P gain) but its P term has
 the gain adjustment (/0x22c86), no speed x gain 2 term, a use-previous branch, and park/drive minimums.
No VP44 content: the vp44_ prefix is wrong.
Globals: 0x80823c LSMNITPZ 1064+6 (no row; read only here; outside the mirror) = low_speed_governor_integrator_preset_minimum (CM848 0x4070bc same record);
 also (shared with cm550_runLowSpeedGovernor): 0x801a6a = low_speed_governor_integral_accumulator (dword, now fuel_economy_sample_1/2 overlap),
 0x801a6e = low_speed_governor_reference_maximum_fuel_quantity (now fuel_economy_sample_3; written by 0x2595a).
Name: cm550_presetLowSpeedGovernorIntegrator.

## 0x26616 cm550_FUN_00026616 - SURE: low speed governor cold idle speed (sets LSCIRF, raises the breakpoint speed to it)
Caller: cm550_runEvery20FramesTaskSetPhase4 (0x1b7a2) call 2 (100 ms).
asm 0x26616-0x266d0: cold = coolant filtered (0x80a336) < LSCICLTP (0x80833a, unsigned); override = algorithm_enable_flags_12_cal (0x803cac) bit 0x4000 AND LSCIOD (0x80db08) != 0.
 engine_state (0x80d0c8) STOPPED: timer 0x801a84 = 0; LSCIRF (0x80db04) = cold ? LSCIRFSR (0x80833c cold idle speed) : 0.
 CRANKING: nothing. Other states: cold and timer < LSCITMLM (0x80833e): timer + 1; RUNNING and (timer >= LSCITMLM or not cold): LSCIRF -= LSCIRMRT (0x808340), floor 0.
 Always: LSDSRFRP (0x80db06 operator adjusted breakpoint) < LSCIRF and no override: LSDSRFRP = LSCIRF.
CM848 counterpart (not twin): cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed 0x28d44 - a coolant temperature speed table with hysteresis, park/neutral gate,
 cold idle timer (low_speed_governor_cold_idle_timer) that zeroes the request after the cold idle time, hot idle inhibit/timers; no ramp-out, no breakpoint floor.
Globals owned (only 0x26616 accesses them): 0x80db04 LSCIRF 1067+2 'cold idle LSG reference speed' (now cold_idle_speed_adder_0_1000 - it is a speed floor, not an adder)
 = low_speed_governor_cold_idle_reference_speed; 0x801a84 (no e2m; now rpm_histogram_sample_divider, undefined) word cold idle timer = low_speed_governor_cold_idle_timer
 (CM848 name of the same role); 0x80db08 LSCIOD 1049+6 (no row; also cleared at start-up 0x265bc) = low_speed_governor_cold_idle_override_flag.
 Row 0x801a85 fuel_economy_sample_toggle has no absolute reference (overlaps the timer's low byte).
Name: cm550_applyLowSpeedGovernorColdIdleSpeed.

## 0x26b3a cm550_FUN_00026b3a - SURE: no load fuel = friction fuel by engine speed + coolant temperature correction (NLFL)
asm 0x26b3a-0x26b7c: 0x80db26 (x_input of friction_fuel_by_engine_speed_lookup 0x80db20) = ENGRPM; 0x80db34 (x_input of the coolant lookup 0x80db2e) = coolant filtered;
 NLFL (0x80db1c) = lookup(coolant record) + lookup(speed record).
Caller: cm550_runEvery20FramesTaskSetPhase6 (0x1b7ca), its only call.
CM848 counterpart (not twin): cm848_calculateNoLoadFuel 0x50dba8 - the sole call of cm848_runEvery20FramesTaskSetPhase6 too (same slot) - but four terms
 (+ A/C clutch adjustment + radiator fan adjustment) and each term stored (friction_fueling, friction_fuel_adjustment_for_coolant_temperature ...).
Name: cm550_calculateNoLoadFuel.

## 0x26b82 cm550_FUN_00026b82 - SURE: single rts, an empty start-up step
Only reference: jsr at 0x287dc in mc68k_applicationMain (step id 0x87e0) between cm550_initializeLowSpeedGovernorIdleAdjustment and undumped 0x4cf42.
 0x26b7e / 0x26b80 are two more unreferenced rts words before it.
Position hint: it follows the no load fuel calc 0x26b3a; CM848 puts its no load fuel lookup cache initializer cm848_initInterpolationStateCounters (0x50dd10,
 a start-up step) right after cm848_calculateNoLoadFuel (0x50dba8) - plausibly the same source file's initializer compiled empty in CM550
 (CM550 sets the friction fuel lookup records in 0x1ddb4). Not proof: the body is empty.

## 0x26e8e cm550_FUN_00026e8e - SURE: engine speed phase lag lines (ESPG and ESPS00PG)
asm 0x26e8e-0x26eea: ESPS00PG (0x80db66, 11AA+2) = (ESAVES (0x80ccf2, average engine speed) x ESPSPGSL (0x80847c) >> 4 + ESPSPGIN (0x80847a) + ESCWAJ (0x80847e)) / 16
 (asr with +15 for negative); ESPG (0x80db64, 11AA+0, no row) = (ESAVES x ESPGSL (0x808478) >> 4 + ESPGIN (0x808476) + ESCWAJ) / 16.
 e2m: ESPG 'phase lag calculation based on the normal phase lag slope and intercept'; ESPS00PG '... pulse 0 phase lag slope and ...';
 ESPGIN/ESPGSL 'intercept / slope of RPM vs phase lag line defining time offset for sync / normal ...'; ESCWAJ 'one time TDC adjustment for misaligned cam wheels'.
Callers: cm550_runEvery4FramesTaskSetPhase0 (0x1b518, periodic) and 0x26e86 (start-up wrapper).
CM848: none - CHR e2m has no 11A9/11AA records (ESPG/ESCWAJ absent).
Wrong existing names (all read only here, outside the mirror, no _cal): 0x808476 final_fuel_command_min = ESPGIN; 0x808478 final_fuel_command_max = ESPGSL;
 0x80847e fuel_rpm_deviation_calc_param = ESCWAJ; 0x80ccf2 fuel_demand_blend_mode_select = ESAVES 100C+0 'average engine speed' (also read at 0x10278/0x171d0/0x1aad8).
Owned outputs: 0x80db64 (no row) = engine_speed_phase_lag; 0x80db66 = engine_speed_pulse_0_phase_lag (0x80db64 also listed in a data table at 0x360ec).
Name: cm550_calculateEngineSpeedPhaseLags.

## 0x26e86 cm550_FUN_00026e86 - SURE: start-up wrapper: jsr 0x26e8e; rts
Only reference: mc68k_applicationMain start-up (step 0x875c) after cm550_canBusTimingInit, before cm550_initializeEnginePositionSignalInputs.
Name: cm550_initializeEngineSpeedPhaseLags.

## 0x277e6 cm550_FUN_000277e6 - SURE: J1587 PID 243 (component identification) reply
Caller: insiteCommandByteDispatcher (0xed64) for insite_parameter_id == 0xf3 (243); siblings in the same chain: 0xea (234) cm550_insiteVersionInfoBuilder,
 0xeb (235) idle hours inline, 0xec (236) inline, 0xed (237) cm550_insiteCapacityResponseBuilder (J1587 PIDs 234 software id / 235 / 236 / 237 VIN).
asm 0x277e6-: data size (0x80ddf8) <= 19: writes at the response pointer (0x80ddea, low byte incremented) [PID (0x80dde5)][size - 2][0x80 = MID 128 engine]
 [make 5 bytes 0x803dcc]['*'][model 17 bytes 0x803dd1]['*'][serial number 4 raw bytes 0x803de2]; response length += size, space -= size.
 Larger: cm550_insiteMultiFrameResponseBuilder(0xe, 0xf) == 0 builds the same bytes at 0x801ade.. and sends them frame by frame (cm550_responseBufferFinalize /
 cm550_insiteMultiFrameContinuation).
The J1939 counterpart in CM550 is cm550_buildPgn65259ComponentIdentificationMessage (0x32052) - same three records plus unit number.
CM848: none (no J1587/J1708 datalink; CM848's PGN 65259 builder is the counterpart of CM550 0x32052, not of this).
Global rows already call it 'the J1587 reply 0x277e6' (component_identification_*_cal).
Name: cm550_buildJ1587Pid243ComponentIdentificationReply.

## 0x27c20 vp44_FUN_00027c20 - SURE: power-down save of the EEPROM image area above the refresh window (0x804156-0x804f91)
Caller: mc68k_runPowerDownSequence (0x27f9c), right after development mode off / RAM refresh on / run location normal / the 1000 x 500-tick queue wait.
asm 0x27c20-0x27cce: a2 = 0x804156; loop while a2 < 0x804f92 and retries (d4, NOT initialised in the function) < 2:
 count = 16, or for the last piece 0x27c9 - (a2 >> 1) (the remaining WORDS, passed as the count); cm550_parameterCircularBufferWrite(a2, a2, count) (0x16c3c, the EEPROM write queue,
 same address as source and target); 0 = queued: a2 += 16, d4 = 0; else d4 + 1. Then up to 16000 waits while cm550_circularBufferEmptyCheck (0x16c2c) is 0:
 cm550_emptyPlaceholderFunction, mc68k_delayTimeBaseTicksWithWatchdogService(500), and the key input 0xffd000 bit 0 (CS2 device port): set for more than 80 (0x50) consecutive waits
 calls restartOnKeyOnDuringPowerDown (0x27af0).
CM848 counterpart (not twin): cm848_saveEepromForPowerDown 0x539a78 - same place in its power-down sequence (right after the 1000-wait for the queue), same 80-sample key-on rule,
 but it starts the whole mirror save (cm848_startEepromMirrorSave / cm848_isEepromMirrorSaveIdle), restarts only after the save, then stores the verify retry total,
 the mirror checksum and the completed power-down count.
Range: CM550 EEPROM image 0x803b0a-0x804f93; refresh window 0x803b0a-0x804155; this function writes only the rest.
Prefix: it reads the CS2 device port 0xffd000 directly (move.b at 0x27c8a) -> mc68k_ by the rule (mc68k_runPowerDownSequence got mc68k_ for CTM4_BIUTBR reads). No VP44 content.
Name: mc68k_saveEepromForPowerDown.
 Quirk: cm550_parameterCircularBufferWrite counts BYTES (byte loop), so the last piece at 0x804f86 queues 6 bytes, not 12: 0x804f8c-0x804f91 are never queued.

## 0x2cf52 cm550_FUN_0002cf52 - SURE of the code, NO role: copies byte_count bytes from source to the fixed buffer 0x801afc
asm 0x2cf52-0x2cf7c: a2 = 0x801afc; loop d1 < count: move.b (source),(a2)+; addq.b #1 on the source's LOW BYTE only (8-bit wrap, like insite_response_write_pointer).
No reference in the dumped ROM: no jsr/bsr/jmp, no 4-byte pointer, no pc-relative lea/pea; 0x801afc has no other absolute reference; the RAM dump is 0 there.
 Callers are presumably in the undumped region above 0x40000. Neighbouring rows 0x801afa-0x801b0d carry old automatic names (j1939_message_buffer_pgn65226 ...) - not evidence.
 Not the J1708 transmit buffer (that is 0x808b00). => no name: the buffer's role and the callers are missing.

## 0x2cf7e cm550_FUN_0002cf7e - SURE: applies the J1708 memory write records (RAM direct, secured RAM / EEPROM staged in the secure write scratch pad)
Caller: cm550_diagnosticMemoryWriteHandler (0x1ec3c; parses a message from j1708_receive_buffer_read_pointer into 10-byte records at 0x80db68:
 +0 address (parameter ID resolved with cm550_lookupParameterIdAddress for 2-byte records), +4 data pointer, +8 length, +9 MEMORY_REGION_TYPE from lookupApplicationMemoryRegionType;
 refused / main flash -> 10, unmapped -> 9), then 0x2cf7e(count) and cm550_diagnosticMessageQueueWrite(result) unless 0xff.
asm 0x2cf7e-0x2d09c: pass 1 counts records of type 5 (EEPROM) or 3 (AUTHORIZATION_REQUIRED) and sums their lengths;
 if any: entries (0x80de2c) + that count > 10, or room (0x80dd86 directory start - write pointer 0x80ddc2) < total length -> return 14 (nothing copied).
 pass 2: type 3/5: directory entry n (0x80dd86 + 6n: address long, length word at 0x80dd8a + 6n), entries + 1, bytes appended at the write pointer;
 other types (0 = RAM 0x8091dc+): bytes copied straight to the address. Source pointer bumps only its low byte. Return 0.
Scratch pad: data 0x80dcbe-0x80dd85 (200 bytes, scratch_pad_data_buffer), directory 0x80dd86 (10 x 6 bytes), write pointer 0x80ddc2 (rows exist, typed undefined).
CM848: none - no J1708 datalink and no scratch pad (grep 'scratch' in CM848 CSVs: nothing related).
Global: 0x80db68 (no row) = the record array, e.g. j1708_memory_write_records (10-byte records: address / data pointer / length / region type).
Name: cm550_applyJ1708MemoryWriteRecords.

## 0x2ddbc cm550_FUN_0002ddbc - SURE: TWIN of CM848 cm848_initializePowerTakeOffThrottleOverride 0x2bd38
asm 0x2ddbc-0x2ddcc: clr.w 0x80dc2e (PTTHOV 1265+2); move.w 0x803f40 (EPNTDQRP 1262+0) -> 0x80dc2c (PTTHDQRP 1265+0); rts.
CM848 0x2bd38: sth 0 -> 0x40af58 (PTTHOV 1265+2); lhz 0x3fd814 (engine_speed_limit_default_cal = EPNTDQRP 1262+0, same record) -> sth 0x40af56 (PTTHDQRP 1265+0). Same order.
Position: one call each from the application main's start-up list (CM550 jsr at 0x287ec; CM848 cm848_applicationMain).
Runtime user in CM550: 0x2dcb0 (cm550_oil_pressure_shutdown_controller - misnamed) reads/writes PTTHOV / PTTHDQRP (CM848: cm848_selectPowerTakeOffOrUserFueling).
Globals (shared records): 0x80dc2e = power_take_off_throttle_override_flag, 0x80dc2c = power_take_off_throttle_override_engine_speed_limit (CM848 names;
 the CM550 names contain 'pto'); 0x803f40 maximum_rated_engine_speed_0_5000 = CM848 engine_speed_limit_default_cal (25 accesses; not owned here).
Name: shared initializePowerTakeOffThrottleOverride.

## Source-order alignment of the J1939 torque module (supports the twins 0xfa68 / 0xff48 / 0xf99a)
CM550: 0xf796 driver demand torque fueling selector / 0xf8c6 actual percent torque (EEC1) / 0xf930 percent load at current speed (EEC2) / 0xf99a empty (EEC2 init) /
 0xf99c nominal friction (EEC3) / 0xfa06 point 1 / 0xfa68 points 1 and 3 / 0xfaa6 points 2 and 5 / 0xfb26 torque curve update ... 0xff48 reference fueling init.
CM848: 0x20860 / 0x209e8 / 0x20a58 / 0x20aec / 0x20af0 / 0x20b84 / 0x20bfc / 0x20c64 / 0x20d10 ... 0x212dc. Same order.
The CM848 percent calcs floor at -32000 (0x8300), the CM550 ones at 0 - a version change across the module.

## Empty stubs - decision
0xc87c / 0xc87e / 0x26b82: CM550-only empty bodies -> precedent names cm550_emptyStubFunction12 / 13 / 14 (round 94/95 used 10 / 11), plate = call sites.
0xf99a: twin by position of CM848 cm848_emptyStubFunction7 (0x20aec) -> one shared name; 'emptyStubFunction7' would sit beside the unrelated cm550_emptyStubFunction7 (0x19aca),
 so a call-site name: emptyPgn61443InitializationStep (low confidence on the wording).

## Enum J1939_DIAGNOSTIC_SERVICE (CM550 still has the old members)
0x43 MEM_READ_2B_PARAM_4B_OFFSET is wrong (the 4 bytes are the LENGTH, offset 0) -> J1939_DIAGNOSTIC_SERVICE_READ_BY_PARAMETER_ID_LONG_LENGTH;
0x46 MEM_READ_2B_PARAM_ONLY is wrong ([46][ID 2][offset 2][length 1]) -> ..._READ_BY_PARAMETER_ID_SHORT_OFFSET; 0x48 SERVICE_48 -> ..._READ_BY_PARAMETER_ID_LONG_OFFSET;
0x4A MEM_READ_4B_ADDR_1B_LEN -> ..._READ_MEMORY; 0x4C MEM_READ_4B_ADDR_4B_LEN -> ..._READ_MEMORY_LONG_LENGTH (CM848 members, same values).

## Missing row (not in the batch): 0x224f4 has no row and no body in the export (FUN_000224f4, shown with one argument);
 it is the twin of CM848 cm848_readJ1939DiagnosticMemoryByParameterId 0x50c5d0 (request, ID word, offset dword, length dword; 8 on unknown ID).
 Likewise 0x2238e cm550_diagMemoryReadResponseBuilder = CM848 cm848_readJ1939DiagnosticMemoryAndRespond 0x50c42c (1764 cap, 0x43 under 256 -> 0x44, reply table).

