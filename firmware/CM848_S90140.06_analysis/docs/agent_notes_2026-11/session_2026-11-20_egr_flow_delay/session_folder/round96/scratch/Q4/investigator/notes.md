# Q4 investigator notes (round 96)

## CLIP memory read services (TWINS, sure)
- 0x226da = twin of CM848 0x50c880 cm848_registerJ1939MemoryReadServices -> shared registerJ1939MemoryReadServices.
  ROM 0x226dc movea.l #0x2ee62 (registerJ1939DiagnosticService) then pea handler / move.w #svc / jsr (a2): 0x43->0x22530, 0x4a->0x22646, 0x4c->0x2268e, 0x46->0x2257c, 0x48->0x225e0.
  CM848 0x50c88c..: li r3 67/74/76/70/72 with 0x50c640/0x50c7b0/0x50c81c/0x50c6a8/0x50c734, bl 0x220e4. Same order.
  Call graph: CM550 mc68k_initializeJ1939Datalink: cm550_registerJ1939InputMessageHandlers; 0x226da; cm550_systemFunction1xCaller; registerJ1939MemoryWriteServices; registerJ1939DiagnosticHandlers.
  CM848 cm848_j1939_system_init: cm848_registerJ1939InputMessageHandlers; cm848_initJ1939DiagnosticCallback; 0x50c880; cm848_registerJ1939GetAddressByParameterIdService; registerJ1939MemoryWriteServices; registerJ1939DiagnosticHandlers.
- 0x22530 (svc 0x43) twin CM848 0x50c640: memcpy id(data+1,2), memcpy length(data+3,4), 0x224f4(req,id,0,length). CM848 li r5,0 = offset 0.
- 0x2257c (svc 0x46) twin CM848 0x50c6a8: id(data+1,2); offset = 0x0000:data[3]:data[4] (clr.w -6, move.b +3/+4); length = 0x000000:data[5]; 0x224f4(req,id,offset,length).
- 0x225e0 (svc 0x48) twin CM848 0x50c734: id(data+1,2), offset(data+3,4), length(data+7,4); 0x224f4.
- 0x22646 (svc 0x4a) twin CM848 0x50c7b0: address(data+1,4), length = 0x000000:data[5]; 0x2238e(req,address,length) (CM848 0x50c42c).
- 0x2268e (svc 0x4c) twin CM848 0x50c81c: address(data+1,4), length(data+5,4); 0x2238e.
- LEAD (not in batch): CM550 0x224f4 (FUN_000224f4, no row) = twin of CM848 0x50c5d0 cm848_readJ1939DiagnosticMemoryByParameterId: jsr 0x10e16 cm550_lookupParameterIdAddress(id,&local) -> nonzero: moveq #8; else 0x2238e(req, local+offset(0xe), length(0x12)). Same as write side 0x21642 writeJ1939DiagnosticMemoryByParameterId (twin of 0x50b1b8).

## 0xb3d0 -> cm550_calculateAccelerationNoiseControlTimingLimit (standalone, sure)
- Enable 0x803c9a & 0x2000 = algorithm_enable_flags_3_cal.acceleration_noise_control_timing_limit_enable (b3ec-b3f6).
- Bare-engine-acceleration inhibit: ESFT01AC 0x80a294 > 0x807a50 -> NZTALMIH 0x80a2a4 = 1, 0x800040 = NZTAIHTM 0x807a4e (b408-b40c); else 0x800040 counts down, at 0 clears 0x80a2a4.
- Conditions: ASANENF 0x80a2a8 != 0, inhibit 0, coolant 0x80a336 > 0x807a38, ESFT01AC <= 0x807a50, ESFT02AC 0x80a296 >= 0x807a3e -> NZTALMSS 0x80a29a = 1, 0x800044 = 0x807a3a (minimum active time). Else override ASANODFG 0x80a2a6 does the same; else 0x800044 counts down, at 0 clears 0x80a29a.
- NZTALMSS == 1: lookup x_input 0x80005e = 0x80ccf4 (current_engine_rpm_filtered), NZTALM 0x80a28e = cm550_lookupTableInterpolation(0x800058) (NZTALMXA/NZTALMYA). Else ramp NZTALM up by 0x807a3c up to 0x400 (b4b0-b4c4).
- Discriminator vs siblings: 0xb2aa (fuel limit: enable bit NZFLAGEN, engine speed threshold, ramps to fuel_demand_maximum) and 0xb4f2 (speed limit: enable NZESAGEN, sets anc_speed_limit_ramp_value). 0xb3d0 uses the timing enable bit, a COOLANT threshold, the timing table and ramps to 1024.
- Caller: cm550_runEvery10FramesTaskSetPhase1 (50 ms). Consumer: cm550_applyAccelerationNoiseControlTimingLimit 0xb4ce.
- CM848: 10A4 is the ANC block (CHR e2m ANC_Timing etc.) but the stage is compiled out: cm848_passCompensatedTimingToCombustionLimits 0x17b54 only copies the timing. => standalone.
- Globals: 0x800040 (no row, no e2m) word countdown = timing limit bare engine acceleration disable timer. 0x800044 row anc_timing_limit_active_timer type undefined -> word (word subq/move at b464/b478/b480/b484).
- Sibling leads: 0x80003c (speed limit disable timer, 0xb4f2), 0x80003e (fuel limit disable timer, 0xb2aa), 0x800042 anc_fuel_limit_active_timer, 0x800046 anc_speed_limit_hold_timer (both undefined type).

## Module layout match (J1939 engine data module): CM550 0xf8c6.. vs CM848 0x209e8..
- CM848: 0x209e8 calculateActualEnginePercentTorque / 0x20a58 calculateEnginePercentLoadAtCurrentSpeed / 0x20aec emptyStub7 / 0x20af0 calculateNominalFrictionPercentTorque / 0x20b84 setJ1939TorqueCurvePoint1AtDeratedIdleFueling / 0x20bfc setJ1939TorqueCurvePoints1And3AtDeratedFueling / 0x20c64 ..Points2And5AtDroopLineFueling / 0x20d10 updateJ1939EngineConfigurationTorqueCurve
- CM550: 0xf8c6 param_lookup_1 / 0xf930 param_lookup_3 / 0xf99a empty / 0xf99c friction / 0xfa06 vp44State2TransitionHandler / 0xfa68 / 0xfaa6 cm550_calculateGovernorDroopSpeed / 0xfb26 vp44_fuelLimitExceedanceStatisticsAccumulator

## 0xf99a -> twin of CM848 0x20aec cm848_emptyStubFunction7 (empty; both rts / blr)
- Sole caller CM550 0x33064 (vp44_cumminsProprietaryDM_983_Builder = really the PGN 61443 EEC2 transmit record initializer): 0x8034b2 = 0xf00300, priority (0x803f64 & 7) << 2 into byte 0 (andi.b #0xe3 / or.b), SA byte 3 from 0x80da01, length 5, data 0x8034aa, status 0x8034c0, jsr 0xf99a, then 0x2f47e(0xf003, 0x32e4c).
- CM848 0x25d60 cm848_initPgn61443Eec2Handler: 0xf00300, (0x3fd850 & 7) << 2 rlwimi into byte 0, SA byte 3, length 5 (+4), data (+6), status (+10), bl 0x20aec, then 0x23188(61443, 0x25b10). Same steps -> callers are twins (LEAD: rename 0x33064), and the stub is the same step.
- Proposed shared name: emptyPgn61443ElectronicEngineController2InitializationStep (judgment).

## 0xf99c -> cm550_calculateNominalFrictionPercentTorque (COUNTERPART of CM848 0x20af0)
- CM550: d2 = NLFL 0x80db1c - 0x808194 (max fueling that does not inject); <=0 -> 0x80da1c = 0. d3 = 0x80da32 (determined peak fueling) - 0x808194; <=0 -> 0. Else d2*25600 (shift/add f9da-f9e6) / d3 via jsr 0x165f2, store 0x80da1c, cap 0x7d00 (32000, bls unsigned).
- CM848 0x20af0: same formula but floor test is cmpwi -32000 and stores 0x8300 (-32000) - different constants -> counterpart.
- Caller: vp44_configParamCanBuilder 0x330c4 = PGN 65247 EEC3 builder (byte 1 = high byte + 125). CM848 0x40ad90 j1939_nominal_friction_percent_torque_times_256 = JCINFCTQ = CM550 0x80da1c.

## 0xfa68 -> setJ1939TorqueCurvePoints1And3AtDeratedFueling (TWIN of CM848 0x20bfc)
- CM550: bsr 0xfa06 (point 1); if point1 speed 0x80da38 (1102 +22) > point3 speed 0x80da3c (1102 +26) (bhi) -> point3 speed = point1 speed, point3 fueling 0x80da46 (1102 +30) = point1 fueling 0x80da42 (1102 +2C); else point3 = 0x808162 (1104 +4 JC39P3RP), fueling = 0x80816a (1104 +C JCDQFLP3).
- CM848 0x20bfc: bl 0x20b84; point3 0x40adb0 < point1 0x40adac (cmpw on zero-extended halfwords = same as unsigned) -> copy point 1 speed / fueling 0x40adb6 -> 0x40adba; else ROM 0x5c34c / 0x5c354 (1104 +4 / +C).
- Call graph: CM550 0xfb26 cases 6 and 7 (cVar2 = +4 LSG band / +2 derate / +1 source) = CM848 0x20d10 cases 6 and 7.
- Not VP44 code: vp44_ prefix wrong.
- LEAD: 0xfa06 vp44State2TransitionHandler = twin of CM848 0x20b84 setJ1939TorqueCurvePoint1AtDeratedIdleFueling (enable 0x803cac & 0x40, x / 167 = divs.l #0xa7).

## 0xff48 -> initializeJ1939ReferenceEngineFuelingAndTorque (TWIN of CM848 0x212dc cm848_initializeJ1939ReferenceEngineFuelingAndTorque)
- CM550 ff48: 0x803cb8 & 0x200 (algorithm_enable_flags_18_cal.programmable_power_enable) set -> rts; else 0x80da32 (1102 +1C JCRFEGFL) = 0x80815e (1104 +0 JCINPKFL); 0x80da34 (1102 +1E JCRFTQ) = 0x808160 (1104 +2 JCRFEGTQ).
- CM848 212dc: 0x3fd5c0 rlwinm bit 0x200 -> blr; else 0x40ada6 = ROM 0x5c348 (1104 +0); 0x40ada8 = ROM 0x5c34a (1104 +2). Same order.
- Caller: both from initializePgn65251EngineConfiguration1Buffer (shared twin, CM550 0x33692 / CM848 0x1b900), last call. CM550's other call cm550_FUN_000185f0 sits where CM848 has cm848_initializeFaultDerateJ1939TorqueCurvePriority (LEAD).
- Global 0x80da34 (no row): word, e2m 1102 +1E JCRFTQ 'THE MAXIMUM AVAILABLE TORQUE (CORRESPONDS TO JCOMM_PEAK_FUEL'; writer ff60 only, reader 0x33310 buildPgn65251EngineConfiguration1Payload (bytes of SPN 544). CM848 name reference_engine_torque_working -> propose same.

## 0xc880 -> cm550_initializeSpeedRequestBlendWeightLookup (COUNTERPART of CM848 0xe8cc cm848_initTemperatureTrimCoeff)
- c880: 0x800102 (speed_request_blend_weight_by_speed_difference_lookup) x_axis_offset = 2, +2 = 0x807acc (1326 ASTHPFXA axis), +8 = 0x807ad8 (1327 ASTHPFYA values). Caller mc68k_applicationMain start-up (between cm550_FUN_0001ddb4 and cm550_interpolationTableSetup).
- CM848 0xe8cc (from cm848_applicationMain): only speed_request_blend_weight_by_speed_difference_cached_axis_offset = 2 (CM848 lookups have no pointer record) -> counterpart. User of the lookup: CM550 0xc92c in cm550_dzgTimingAndPressureControlStateMachine; CM848 cm848_calculateGovernorReferenceSpeedBlend.
- LEAD: CM848 0xe8cc name is wrong (temperature trim) -> cm848_initializeSpeedRequestBlendWeightLookupCache.

## 0xd3b2 -> cm550_initializeAllSpeedGovernorReferenceSpeedSets (counterpart: CM848 0x2c100 cm848_initializeAllSpeedGovernorTuningSetBlendWeight does only the last step)
- d3b2: 0x80a9ac = 0x803bbc (0008 +20 ASMNRF), 0x80a9b0 = 0x803bbe (0008 +22 ASMXRF), 0x80a9b4 = 0x803bca (0008 +2E ASMNRF02), 0x80a9b8 = 0x803bcc (0008 +30 ASMXRF02); 0x80a9a2 (107A +16 ASDPFG) = 0x803d5a (1387 +8 ASDPFGTN).
- Reader 0xd2be (cm550_acceleratorThrottleFaultDetector, old name): selector 0 -> ASMNRP 0x80a9a4 = *0x80a9ac, ASMXRP 0x80a9a6 = *0x80a9b0; selector 1 -> *0x80a9b4 / *0x80a9b8; then 0x80a98c = min + (max - min) x 0x80aa82 / 400.
- Dump: pointers 0x803bbc/0x803bbe/0x803bca/0x803bcc; set 1 5440/27600, set 2 5200/34304; selector 1; ASMNRP/ASMXRP 5200/34304 (= set 2).
- CM848 names: all_speed_governor_minimum/maximum_reference_speed_1_cal (0x3fdd14/16), _2_cal (0x3fdd22/24) -> propose same for 0x803bbc/be/ca/cc (EEPROM image -> _cal). Pointers: all_speed_governor_minimum/maximum_reference_speed_1/2_pointer (word *).
- Note: 0x803d5a default_throttle_source_selector is in the EEPROM image without _cal (LEAD for the cal audit; its CM848 twin record is all_speed_governor_tuning_set_default_blend_weight_cal).

## User fueling state chain: CM550 0x3458c cm550_engine_protection_coordinator (old name) -> previous = FSDSFLST; FSDSFLST = 0; ... 0x25806(previous); 0xd4ae(previous); default setter. From cm550_runEvery4FramesTaskSetPhase1.

## 0xd4ae -> cm550_selectVariableSpeedGovernorMode (COUNTERPART of CM848 0x2c6c4 cm848_updateVariableSpeedGovernorSelection + 0x10110 cm848_selectVariableSpeedGovernorMode)
- d4c2-d4de: only while NLFL 0x80db1c + ASSDFUOF 0x807ac8 > FSFNFL 0x80d32e (strict; CM848 uses <=) and THROTTLE 0x80aa82 == 0: flags_27 0x803cca & 8 (switched_throttle_control_governor_select) == 0 or interlock switch 0x80bcd1 bit 1 clear -> STUOTHGV 0x80a982 = FSTHGVOP 0x803bf0; else STUOTHGV = inverse (1->0, 0->1).
- d532-d57e: FSDSFLST 0x80ded4 == 0 and STUOTHGV == 1 -> FSDSFLST = 7; bsr 0xd3e6 (cm550_diagnosticMode10FuelController = ASG throttle reference? not checked); previous not 7 and not 3 -> 0x80a9a8 = &0x807be0 (107B throttle mode gain set), 0x80a9a0 = 0, 0x80a99e = 0x807bde, 0x80a99c = 0x807bdc, 0x80a984 (filter state .coefficient) = 0x807bda.
- CM848 does the flag in 0x2c6c4 and the state in 0x10110 (blend + throttle reference + empty stub 6 + compensator coefficients, previous != 7 only; loads 10 selected gains). Different code -> counterpart.
- Globals: 0x803bf0 (no row) = 0008 +54 FSTHGVOP 'USER INDICATOR FOR ENABLING AUTOMOTIVE GOVERNING THROUGH THROTTLE' -> variable_speed_governor_default_cal (CM848 0x3fdd42 0008 +4E same record; CM550 EEPROM image -> _cal). 0x807ac8 (no row) = 107D +0A ASSDFUOF -> all_speed_governor_switch_droop_fueling_offset (CM848 0x3ff68e 107D +8); also read by 0xd2be (d2ee).

## 0x25806 -> cm550_selectPedalFaultMode (COUNTERPART of CM848 0x50daac cm848_transitionEngineOperatingMode)
- 25820: LHFLEN 0x80821a (10CE +C, word tst) == 0 -> rts; FSDSFLST != 0 -> rts.
- flags_5 0x803c9e & 0x400 (sampled_throttle_override_enable = J1939 pedal) set: MXACDXER 0x80d70c | MXACTMER 0x80d70e != 0 -> state 6.
- else: status word 4 0x806008 bits 0x2 / 0x4 / 0x20 each with fault_processing_enable_flags[4] 0x806ac4 -> state 6.
- state 6 and previous != 6 -> jsr 0x258b0 presetPedalFaultModeFuelDemand (shared).
- CM848 0x50daac: pedal_fault_mode_enable_flag, NOT_SELECTED, sensor_channel_held_value_enable_bits_cal[0] & 0x2000 selects J1939 branch; local branch = accelerator_pedal_input_fault_flag (dual channel) or faults_0_to_15 bits 0x400 / 0x800 -> different tests -> counterpart.
- Module order: CM550 0x2571e calculate / 0x25806 select / 0x258b0 preset / 0x258d6 initialize filter; CM848 0x50d864 / 0x50da7c preset / 0x50daac select / 0x50db88.
- Global 0x80821a (no row): word (only access tst.w 0x25820), 10CE +C LHFLEN 'ENABLE BIT FOR THE LIMPHOME FUELING ALGORITHM' = CM848 pedal_fault_mode_enable_flag (0x5c49a, 10CE +C) -> same name. Not in EEPROM image.
- LEAD: CM848 0x50daac name generic -> cm848_selectPedalFaultMode.

## 0xf716 -> cm550_calculateAllSpeedGovernorDroopFueling (COUNTERPART: the droop part of CM848 0x20554 cm848_calculateEffectiveFuelLimit)
- f71e: d2 = ASTHRFES 0x80a98c (107A +0 ASG reference speed from throttle) - ENGRPM 0x80ccf6. ASRFST 0x80a98e == 7 -> 0x800180 = ASSLDP 0x80a99a (107A +E selected droop slope).
- 0x800180 == 0: d2 > 0 -> 0x1700 else 0. Else fuel = d2 (ext.l) x 0x2655 (9813) / (0x800180 << 3) (divs.l) + ASNLFL 0x8091de; <= 0 -> 0; >= 0x1700 -> 0x1700.
- Caller 0xf796 cm550_paramSystemModeController (old name; = CM848 cm848_calculateDriverDemandPercentTorque counterpart): when 0x803bf0 (FSTHGVOP) == 1 its driver-demand fueling = 0xf716(), else 5DFL 0x80d33e; then JCDRIDTQ 0x80da18 = (fuel - zero) x 25600 / (peak - zero) cap 32000. Called by sendPgn61444ElectronicEngineController1Message.
- CM848 0x20554 does the speed limiter + 6 fuel limits + droop (with the deadband / minimum droop branches) in one function -> counterpart only.
- Globals: 0x800180 row anc_speed_limit_table_3_ptr (undefined) -> all_speed_governor_droop_snapshot word (only refs 0xf71a; CM848 0x3fa8a2 same pattern 'refreshes only while mode 7'). 0x80a99a asg_selected_droop_slope_0_30 undefined -> word (move.w f734). 0x8091de rpm_control_override_flag -> all_speed_governor_no_load_fuel (1322 +0 ASNLFL 'FUEL REQUIRED TO OVERCOME FRICTION CALCULATED USING ASG REFERE'; CM848 0x40a24a).
- LEADS: 0x80d33e (1053 +0 5DFL, no row) = CM848 four_dimensional_fueling; 0x80da18 (1102 +2 JCDRIDTQ, no row) = CM848 driver_demand_percent_torque_times_256; 0xf796 -> cm550_calculateDriverDemandPercentTorque.

## 0x24804 -> cm550_updateLampOutputsAndCheckLampDriverFaults (standalone wrapper)
- Body: jsr cm550_applyLampRequestsToOutputs (0x23a90: lamp_driver_output_bitmask bits -> output image bits while each override priority byte is 0), then diagnosticMainStateProcessor (0x23be8). Only caller: cm550_runEvery10FramesTaskSetPhase6 (50 ms, first call; then cm550_processJ1939AcceleratorInputs).
- CM550 0x23be8 body (NOT CM848's): while switch 1 (0x80bcce bit 0, 000E +0 DS01SWSS) is on, for 7 outputs (bits 0,1,2,6,4,5,3) compares the lamp driver status bits LCLP01FB.. (0x80bd02, 000E +34 'STATUS OF THE LAMP n DRIVER OUTPUT') with io_driver_port_1_feedback (0x80bd08) and debounces two fault bits per output in status word 8 (0x40/0x80, 0x10/0x20, 0x100 ...), limits 0x611c8 / 0x611ca.
- CM848 diagnosticMainStateProcessor 0x1d9b8 is the fault scanner (fault_scan_index, cm848_processFaultScanGroup, clear request, OBD completed monitors) -> different function; CM848 calls it straight from cm848_runEvery4FramesTaskSetPhase1, no lamp wrapper -> 0x24804 standalone.
- LEAD: CM550 0x23be8 shares the name diagnosticMainStateProcessor with CM848 0x1d9b8 but is not its twin -> rename CM550 0x23be8 (cm550_checkLampDriverOutputFaults) and prefix CM848's (cm848_). 

## 0x25a34 -> cm550_presetLowSpeedGovernorIntegrator (COUNTERPART of CM848 0x27e4c cm848_presetLowSpeedGovernorIntegrator)
- Called by cm550_runLowSpeedGovernor (0x25b1c) only when adjusted_user_fueling_state == LSG (11) and final_fueling_state != LSG (the LSG takes over).
- 25a50 bsr 0x2595a (cm550_governorFuelPidController, old name: computes 0x801a6e = alpha blend (0x80d340) of two 2D lookups (0x80d372 / 0x80d388) at x 0x80daee (LSG adjusted reference speed) and y 0x190 = 400 = 100% throttle, clamp 0..0x1700) = CM848 cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity (LEAD).
- 25a54: LSMXITPZ 0x80daec (1065 +E) = LSMXPZOF 0x80823a (1064 +4) + 0x801a6e, clamp 0..0x1700.
- 25a78: value = FSFNFL - (LSER 0x80dae0 x LSPPGN 0x80dac4 (muls.w)) / 0x3c0 + (ENGRPM 0x80ccf6 x LSPP02GN 0x808268) / 0x8b2; minus NLFL 0x80db1c when flags_32 0x803cd4 & 0x200 (low_speed_governor_no_load_fuel_enable); clamp to [LSMNITPZ 0x80823c (1064 +6), LSMXITPZ].
- 25ae6: 0x801a6a (move.l) = value << 16; LSFL 0x80dade = FSFNFL; LSDVFL 0x80dae4 = 0; 0x801a70 = ENGRPM; 0x801a72 = LSPPGN; 0x801a74 = LSPP02GN.
- CM848 0x27e4c: same role; no engine speed term (/0x22c86 with P gain adjustment), optional previous-integral reuse, park/neutral vs drive minimum, clears P/D/jerk terms -> different code -> counterpart. Not VP44 -> cm550_.
- Globals (users in 0x25b1c): 0x801a6a fuel_economy_sample_1 (undefined) -> low_speed_governor_integral_accumulator dword (add.l to (a5) 0x25ef6, high word copied to 0x80dae6 at 0x25f38 = CM848 Q16.16 accumulator). 0x801a6e fuel_economy_sample_3 (undefined) -> low_speed_governor_reference_maximum_fuel_quantity word (written 0x259d8/0x259e2/0x25a28; add.w readers 0x25a5a/0x25e3c/0x25e64 for LSMXITPZ / clamp max LSMXFLOF / LSMXITOF). 0x801a70 vp44_fuel_demand_previous -> low_speed_governor_previous_engine_speed word (speed - it x LSDV02GN 0x80826a / 0x8b2 = LSDV02FL 0x80dafe at 0x25dea; stored each pass 0x25fe6 and in 0x25ff2 init). 0x801a72 (no row) -> low_speed_governor_proportional_gain_previous i16 (ext.l at 0x25e98; LSPPGN - it times error). 0x801a74 non_idle_time_counter -> low_speed_governor_proportional_gain_2_previous i16 (ext.l at 0x25ebc; LSPP02GN - it times speed). 0x80823c (no row) -> low_speed_governor_integrator_preset_minimum i16 (1064 +6 LSMNITPZ; ext.l at 0x25ac8; CM848 0x4070bc same record).

## 0x26616 -> cm550_calculateLowSpeedGovernorColdIdleSpeed (COUNTERPART of CM848 0x28d44 cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed)
- cold = coolant 0x80a336 < LSCICLTP 0x80833a (1066 +0) (bcc unsigned). override = flags_12 0x803cac & 0x4000 (low_speed_governor_cold_idle_override_enable) and LSCIOD 0x80db08 (1049 +6) != 0.
- engine_state 0x80d0c8 == 1 STOPPED: timer 0x801a84 = 0; LSCIRF 0x80db04 (1067 +2 'COLD IDLE LSG REFERENCE SPEED') = cold ? LSCIRFSR 0x80833c (1066 +2) : 0. == 2 CRANKING: nothing. Else: cold and timer < LSCITMLM 0x80833e (1066 +4) -> timer + 1; RUNNING (3) and (timer >= LSCITMLM or not cold) -> LSCIRF ramps down by LSCIRMRT 0x808340 (1066 +6) to 0.
- Then LSDSRFRP 0x80db06 (1049 +4 operator adjusted LSG breakpoint speed) < LSCIRF and no override -> LSDSRFRP = LSCIRF.
- Caller: cm550_runEvery20FramesTaskSetPhase4 (100 ms), 2nd call.
- CM848: blocks 1049/1066/1067 absent; cold idle records moved to 14EE (Cold_Idle_Coolant_Temperature / Cold_Idle_Time) and 0x28d44 is a coolant table / hot idle / park-neutral design -> counterpart.
- Globals: 0x801a84 rpm_histogram_sample_divider (undefined; only ref 0x26622) -> low_speed_governor_cold_idle_timer word. 0x80db08 (no row) -> low_speed_governor_cold_idle_override_flag word (1049 +6 LSCIOD 'COLD IDLE OVERRIDE FLAG - TRUE INHIBITS COLD IDLE ADJUSTMEN'; tst.w 0x26652, clr.w 0x265bc in cm550_initializeLowSpeedGovernorIdleAdjustment).

## 0x26b3a -> cm550_calculateNoLoadFuel (COUNTERPART of CM848 0x50dba8 cm848_calculateNoLoadFuel)
- 26b4a: friction_fuel_by_engine_speed_lookup (0x80db20) x_input = ENGRPM 0x80ccf6; friction_fuel_correction_by_coolant_temperature_lookup (0x80db2e) x_input = coolant 0x80a336; NLFL 0x80db1c (109C +0) = coolant lookup + speed lookup (two jsr 0x34de0).
- CM848 0x50dba8: four terms (coolant / A/C clutch / radiator fan grid / friction by speed), stores each term -> counterpart. Both run from runEvery20FramesTaskSetPhase6 (CM550 its only call; CM848 'Caller cm848_runEvery20FramesTaskSetPhase6').

## Empty stubs (all a single rts 0x4e75)
- 0xc87c: called in all 4 modes of mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0..3, after cm550_rpmTimingDeltaComparatorWithReturn, before mc68k_FUN_0001266e / vp44_communication_state_machine(1). -> cm550_emptyPrimarySpeedInterruptStep.
- 0xc87e: called by the three TPU channel 1 (backup engine speed input) interrupt handlers 0x1af32 (mc68k_dutyCycleMonitorIsrHandler, old name) / 0x1b30a / 0x1b4b2: each mc68k_resetSpeedMeasurementMode0(); 0xc87e(); TPU_CISR &= 0xfffd (channel 1). -> cm550_emptyBackupSpeedInterruptStep.
- 0x26b82: one call, mc68k_applicationMain start-up (jsr at 0x287d8, after cm550_initializeLowSpeedGovernorIdleAdjustment 0x2658c, before 0x4cf42). In the no load fuel module (0x26b3a then rts stubs 0x26b7e/80/82/84/86, only 0x26b82 referenced). CM848's cm848_initInterpolationStateCounters 0x50dd10 sits after cm848_calculateNoLoadFuel but CM550 sets those lookup records in 0x1ddb4 and the start-up order differs -> no twin proof. -> cm550_emptyStubFunction12 (convention of 10 / 11).
- 0xf99a: twin of CM848 0x20aec (see above).

## 0x26e8e -> cm550_calculateEnginePositionPhaseLag (standalone)
- 26e9a: ESPS00PG 0x80db66 (11AA +2) = (ESAVES 0x80ccf2 x ESPSPGSL 0x80847c (11A9 +6) >> 4 + ESPSPGIN 0x80847a (11A9 +4) + ESCWAJ 0x80847e (11A9 +8)) >> 4 (asr with +15 for a negative sum = signed divide by 16).
- 26ec2: ESPG 0x80db64 (11AA +0) = (ESAVES x ESPGSL 0x808478 (11A9 +2) >> 4 + ESPGIN 0x808476 (11A9 +0) + ESCWAJ) >> 4.
- Callers: cm550_runEvery4FramesTaskSetPhase0 (20 ms) and 0x26e86 (start-up wrapper from mc68k_applicationMain).
- Outputs written only here; no dumped reader (ESPG also appears at 0x360ec / 0x360f0 inside parameter_id_table data) -> consumers in undumped 0x4xxxx code.
- CM848: no 11A9 / 11AA records in CHR e2m, no phase lag names -> standalone. Engine position (ES group, next to 11A8 cam/crank sync), not VP44 -> cm550_.
- Globals: 0x80db64 (no row) -> engine_position_normal_phase_lag word; 0x80db66 phase_lag_calculation_based_on_the_pulse_0_phase_lag_slope_and_0_40 -> engine_position_pulse_0_phase_lag (consistency, optional); 0x808476 final_fuel_command_min -> engine_position_normal_phase_lag_intercept; 0x808478 final_fuel_command_max -> engine_position_normal_phase_lag_slope (only refs in 0x26e8e); 0x80847e fuel_rpm_deviation_calc_param -> cam_wheel_top_dead_center_adjustment (ESCWAJ 'ONE TIME TDC ADJUSTMENT FOR MISALIGNED CAM WHEELS'; only ref 0x26e90); 0x80ccf2 fuel_demand_blend_mode_select -> average_engine_speed (100C +0 ESAVES 'AVERAGE_ENGINE_SPEED: ENGINE SPEED BASED ON THE 2^N PULSE AVE'; written by cm550_calculateEngineSpeed, compared with crank_sync_running_speed_threshold).

## 0x26e86 -> cm550_initializeEnginePositionPhaseLag (standalone): jsr 0x26e8e; rts. One call, mc68k_applicationMain start-up (after cm550_canBusTimingInit, before cm550_initializeEnginePositionSignalInputs).

## 0x277e6 -> cm550_buildJ1587Pid243ComponentIdentificationReply (standalone)
- Called by insiteCommandByteDispatcher (0xed64) when insite_parameter_id == 0xf3 (243). The dispatcher's other cases are J1587 PIDs too (0x54 road speed 84, 0x55 cruise status 85 from cruise switch bits, 0x56 86, 0x59 PTO status 89 from power_take_off_switch_state_bits, 0xed 237).
- Short path (insite_parameter_data_size < 20): writes [PID][data size - 2][0x80 = MID 128 engine][make 5 component_identification_make_cal]['*'][model 17]['*'][serial number 4 raw bytes] at insite_response_write_pointer; adds data size to insite_response_length, subtracts from insite_response_space_available.
- Long path: cm550_insiteMultiFrameResponseBuilder(0xe, 0xf) == 0 -> builds 0x80 make * model * serial at 0x801ade.. then copies insite_multiframe_frame_bytes_remaining bytes per frame, cm550_insiteMultiFrameContinuation between frames, cm550_responseBufferFinalize at the last.
- CM848 has no J1708 / J1587 (its CI is J1939 PGN 65259 cm848_j1939HandlePgn65259ComponentId; CM550's J1939 one is cm550_buildPgn65259ComponentIdentificationMessage 0x32052, which also adds the unit number) -> standalone, cm550_.
- Round 95 rows (component_identification_*_cal) already call it 'the J1587 reply 0x277e6'.

## 0x27c20 -> mc68k_saveEepromForPowerDown (COUNTERPART of CM848 0x539a78 cm848_saveEepromForPowerDown)
- 27c26: pointer a2 = 0x804156; loop while a2 < 0x804f92 and fewer than 2 consecutive refusals (d4): count 16, or (0x804f92 >> 1) - (a2 >> 1) for the last partial chunk; jsr 0x16c3c cm550_parameterCircularBufferWrite(a2, a2, count) -> 0 = queued: a2 += 16, d4 = 0; else d4 + 1.
- 27c72: then up to 16000 (0x3e80) waits while 0x16c2c cm550_circularBufferEmptyCheck is 0: 0x16d4c (empty), 0x34bba mc68k_delayTimeBaseTicksWithWatchdogService(500); bit 0 of 0xffd000 (chip select 2 device input register 0, same input as mc68k_waitForChipSelect2InputBit0High) set -> d3 + 1, clear -> d3 = 0; d3 > 80 (0x50) -> jsr 0x27af0 restartOnKeyOnDuringPowerDown (shared twin).
- Caller mc68k_runPowerDownSequence 0x27f9c, right after the 1000-pass queue drain (0x27fd2.. ) - CM848 cm848_runPowerDownSequence calls cm848_saveEepromForPowerDown at the same step (same 1000-pass drain before).
- CM848 0x539a78: cm848_startEepromMirrorSave + wait idle; key line mios_mdasm30.SCR bit 15 > 80 samples -> key_on_during_power_down_save_flag, restart after the save; then verify retry total, mirror checksum, completed power down sequence number -> different code -> counterpart.
- Range: 0x804156-0x804f91 = the EEPROM image above the part cm550_commitEepromMirrorToEeprom writes (0x803b0a-0x804155). Prefix mc68k_ (reads the CS2 device register; like mc68k_waitForChipSelect2InputBit0High). Not VP44.

## 0x2cf7e -> cm550_applyJ1708MemoryWriteRecords (standalone; CM848 has no J1708 and no scratch pad)
- Caller cm550_diagnosticMemoryWriteHandler 0x1ec3c (from mc68k_dispatchJ1708ReceivedMessages): parses the J1708 write request from j1708_receive_buffer_read_pointer into 10-byte records at 0x80db68 (+0 address (from cm550_lookupParameterIdAddress when the size byte is 2), +4 data pointer into the 256-byte J1708 receive ring 0x808c00, +8 length, +9 MEMORY_REGION_TYPE from lookupApplicationMemoryRegionType; 10 refused / main flash, 9 unmapped answered at once), then 0x2cf7e(record count) and queues its result unless 0xff (jsr at 0x1ed86).
- 2cf9e: pass 1 counts records of type 5 (EEPROM) / 3 (AUTHORIZATION_REQUIRED) and sums their lengths (bytes). If any: entries 0x80de2c + count > 10 -> return 14; 0x80dd86 (scratch_pad_directory_table) - scratch_pad_write_pointer 0x80ddc2 < bytes -> return 14 (nothing written).
- 2cffc: pass 2: type 5 / 3 -> directory entry n at 0x80dd86 + 6n: long address, word length at +4 (0x80dd8a + 6n), entries + 1, data bytes to *scratch_pad_write_pointer++; other types -> bytes copied straight to the address. Source pointer steps its low byte (addq.b #1,(-1,a6)) -> wraps in the receive ring. Returns 0.
- Dump: scratch pad empty (write pointer 0x80dcbe = data start, entries 0); data buffer 0x80dcbe-0x80dd85 (200), directory 0x80dd86-0x80ddc1 (10 x 6).
- Global 0x80db68 (no row): j1708_memory_write_records, 15 x 10 bytes up to 0x80dbfe (DAT_0080dbfe = address size 2 / 4, set by the parser). Struct candidate j1708_memory_write_record_t {dword address; byte *data; byte length; MEMORY_REGION_TYPE region_type} (needs a structure_definitions row set; else byte[150]).

## 0x2cf52 -> SKIP
- Body: copies byte_count bytes from source to 0x801afc (move.b (a0),(a2)+; addq.b #1,(0xb,a6) steps only the source's low byte = the J1708 receive ring idiom).
- No reference in the dumped ROM: no absolute 0x2cf52 (abs_refs), no bsr.w/bsr.s/jsr pc-relative, no pea/lea pc-relative, no stored long 0x0002cf52. 0x801afc has no row and no other reference (abs_refs: only 0x2cf5e). Purpose unprovable -> caller probably in the undumped 0x40000+ region.

## 0x2ddbc -> initializePowerTakeOffThrottleOverride (TWIN of CM848 0x2bd38 cm848_initializePowerTakeOffThrottleOverride)
- CM550 2ddbc: clr.w 0x80dc2e (1265 +2 PTTHOV); 0x80dc2c (1265 +0 PTTHDQRP) = 0x803f40 (1262 +0 EPNTDQRP 'MAX ENGINE SPEED WHEN NO DERATE IS IN EFFECT'); rts.
- CM848 2bd38: sth 0 -> 0x40af58 (1265 +2 PTTHOV); 0x40af56 (1265 +0 PTTHDQRP) = 0x3fd814 (1262 +0 EPNTDQRP engine_speed_limit_default_cal). Same records, same order.
- Both called once from the application main at start-up (CM550 between 0x4d9dc and cm550_initializeTripInformation).
- Globals: 0x80dc2e throttle_fueling_override_active_flag -> power_take_off_throttle_override_flag (CM848 name, same record); 0x80dc2c max_engine_speed_while_throttle_fueling_overrides_pto_fueling_0_4500 -> power_take_off_throttle_override_engine_speed_limit (CM848 name; removes 'pto'). Readers: selectEngineSpeedLimit 0x1d6c2/0x1d6cc, the PTO/user fueling selector at 0x2dcbc.
- LEAD: 0x803f40 maximum_rated_engine_speed_0_5000 is in the EEPROM image without _cal (CM848: engine_speed_limit_default_cal).

## Chain match (strengthens 0x25806 / 0xd4ae counterparts)
- CM848 cm848_resetEngineOperatingMode 0x42918: previous = mode; NOT_SELECTED; selectAllSpeedGovernorApplicationMode; setEngineOperatingMode1; selectTsc1SpeedControlMode(prev); selectUserCommandedFueling; transitionEngineOperatingMode(prev) [pedal fault 6]; selectVariableSpeedGovernorMode(prev) [7]; initEngineOperatingState.
- CM550 0x3458c: same skeleton: diagnosticStatus30Setter; setDiagnosticSourceFromFuelArbitrator; diagnosticStatus2Initializer(prev); setDiagnosticSourceFromEngineFlags; 0x25806(prev); 0xd4ae(prev); diagnosticStatusDefaultSetter. LEAD: rename the CM550 chain and its callees after their CM848 matches.

## Checks done
- no_load_fuel_quantity 0x80db1c: only writer 0x26b72 (0x1445e is a read to 0x80bc74).
- 0x26b82 call: jsr at 0x287da (after jsr 0x2658c, before jsr 0x4cf42).
- All proposed names free in both firmwares (check_names.py).
- CM848 renames: 0xe8cc cm848_initTemperatureTrimCoeff -> cm848_initializeSpeedRequestBlendWeightLookupCache (li 2 / sth 0x3fa0f0 / blr; one caller cm848_applicationMain); 0x50daac cm848_transitionEngineOperatingMode -> cm848_selectPedalFaultMode (only state store = 6; position in the chain above).

## Other leads (not in batch)
- CM550 0x224f4 FUN_000224f4 (no row) = twin of CM848 0x50c5d0 cm848_readJ1939DiagnosticMemoryByParameterId.
- CM550 0x2238e cm550_diagMemoryReadResponseBuilder vs CM848 0x50c42c cm848_readJ1939DiagnosticMemoryAndRespond: compare (the write side is the shared writeJ1939DiagnosticMemory).
- CM550 0x33064 vp44_cumminsProprietaryDM_983_Builder = twin of CM848 0x25d60 cm848_initPgn61443Eec2Handler (PGN 61443 EEC2 record set-up).
- CM550 0xfa06 vp44State2TransitionHandler = twin of CM848 0x20b84 setJ1939TorqueCurvePoint1AtDeratedIdleFueling.
- CM550 0xfb26 vp44_fuelLimitExceedanceStatisticsAccumulator = the torque curve builder (CM848 0x20d10 cm848_updateJ1939EngineConfigurationTorqueCurve).
- CM550 0x2595a cm550_governorFuelPidController = CM848 cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity (100 percent throttle 4D fueling at the LSG adjusted reference speed).
- CM550 0xf796 cm550_paramSystemModeController = J1939 driver's demand percent torque (CM848 cm848_calculateDriverDemandPercentTorque); 0x80d33e (1053 +0 5DFL) / 0x80da18 (1102 +2 JCDRIDTQ) unnamed.
- CM550 0x23be8 diagnosticMainStateProcessor shares a name with CM848 0x1d9b8 but is the lamp driver check (not a twin).
- CM550 0xd2be cm550_acceleratorThrottleFaultDetector = ASG throttle reference speed (set selection + interpolation).
- CM550 0xd3e6 cm550_diagnosticMode10FuelController writes ASSLDP 0x80a99a (selected droop slope).
- 0x80dac4 lsg_proportional_gain_active: undefined type, every access word and signed (muls.w 0x25a86 / 0x25d02, ext.l 0x25e90) -> i16.
- Cal audit: 0x803d5a default_throttle_source_selector and 0x803f40 maximum_rated_engine_speed_0_5000 lie in the EEPROM image without _cal.
- ANC siblings: 0x80003c / 0x80003e (no rows) inhibit timers of 0xb4f2 / 0xb2aa; 0x800042 anc_fuel_limit_active_timer / 0x800046 anc_speed_limit_hold_timer undefined type (word).

STATUS: investigation complete for all 30 (29 named, 0x2cf52 skipped). Output assembled from these notes.
