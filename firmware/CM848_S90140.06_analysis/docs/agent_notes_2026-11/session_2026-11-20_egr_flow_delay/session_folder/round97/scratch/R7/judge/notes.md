# R7 judge notes (round 97)

No earlier judge run found (directory was empty at start).

cbd-named CM848 symbols (names / types / prototypes): functions 0x42bd0 / 0x42d78 / 0x43a5c, global 0x408ef6 cbd_enable_flag.
(other cbd hits are comments mentioning old function names, and 0x3fcbd* address strings)

## Stub bodies (checked bytes)
- CM550 0x15f8c / 0x19aca / 0x26852 / 0x30b0e / 0x26b82 = 4e75 (rts). 0x19ac2 / 0x1a89a = jsr 0x34674; rts.
- CM848 0x54220 / 0x1806c / 0x26f7c / 0x2c0fc / 0x55e9c = 4e800020 (blr).
- callers: CM550 0x15f8c jsr 0x1598a (sampler); 0x19aca jsr 0x1718e (case 0 of 0x17150, table 0x17166 = 1c/08/30/44); 0x26852 bsr.s 0x2685e; 0x30b0e jsr 0x28774; 0x26b82 jsr 0x287da.
  CM848 0x54220 bl 0x549c8; 0x1806c bl 0x54c84; 0x26f7c bl 0x53b14; 0x2c0fc bl 0x1015c; 0x55e9c none, 23 ptrs 0x583ae-0x5842a.
- 0x55e9c tables: TPU-B base 0x583ae (dispatcher 0x55d2c lis/addi at 0x55dbc; CISR 0x304420 CIER 0x30440a), TPU-A base 0x583ee (dispatcher 0x55de4, lis/addi at 0x55e74, CISR 0x304020 CIER 0x30400a).
  Stub entries TPU-B ch 0,3-8,10-13,15 (12); TPU-A ch 2-5,7-9,12-15 (11) = 23. Investigator's counts right; describer's 13/10 miscounted.
  Dispatcher clears the CISR bit (sth andc) then blrl the entry: plate right.
- 0x34674: config 0 -> TPU ch0 fn 0xc set-up + handler 0x19c88; config 1 -> 0x80a23a table + jsr 0x3494a; 2/3 -> rts. (so round 96 plate of 0x1a89a 'acts for 0 and 1' is right; investigator's 'only config that programs ch0 fn 0xc' is right.)
- RAM dump: 0x807e9d = 1, 0x808edc = 0x19f82, 0x808ee0 = 0x1b30a, 0x807f26 = 0, 0x803f8a = 1, 0x807eea = 0x1900, 0x80a982 = 1, 0x80db04 = 0, 0x80d2c2 = 0, 0x8002ac..c3 all 0.

## 0x143b6 / CM848 0x1820c twin
- CM550: lookup rec 0x80db2e (input 0x80a336) jsr 0x34de0 -> 0x80052c; bsr 0x14348; 5x jsr 0x142d4: (0x80db02,0x80bc82)->bc7e, (0x807d4e,bc84)->bc80, (7d50,bc86)->bc78, (7d52,bc88)->bc7a, (7d54,bc8a)->bc7c.
- CM848: bl 0x55ef4 (coolant 0x40baf4) -> sth 0x3fa712; bl 0x1811c; 5x bl 0x18070: (0x40aec2, 0x40a63e)->a63a, (0x5c2b4,a640)->a63c, (5c2b6,a642)->a634, (5c2b8,a644)->a636, (5c2ba,a646)->a638.
- helpers already shared names in both (calculateJ1939PercentPeakTorqueAtSpeed, calculateJ1939FrictionLoadFuelingAtBreakpoints). Same steps / order. CM848 has no reference (no bl, no ptr). CM550 caller jsr 0x1f352 in cm550_diagnosticMessage46Builder.
- 10E2 records match: CM550 +4/+6/+8/+A/+C -> 0x80bc78/7a/7c/7e/80; CM848 -> 0x40a634/36/38/3a/3c (j1939_percent_peak_torque_*_times_256, type word). CM550 accesses all move.w (writes in 0x143b6, reads in 0x1f2d0). Not EEPROM -> no _cal.
- CM848 0x3fa712: sth 0x18244 (0x1820c), lha 0x180c8 (0x18070). Only users. CM550 0x80052c already friction_fuel_coolant_temperature_correction (word). Name free in CM848.
- VERDICT 0x143b6: CONFIRMED twin -> calculateJ1939PercentPeakTorquePoints (CM848 0x1820c). CM848 no caller = J1708 builder excluded; body / callees / order identical.

## 0x1c640 / CM848 0x1e830 twin
- CM550: cmpi.w #8,(0x80ded4); bne; jsr 0x1de58; move.w d0 -> 0x80d33e, 0x80ded2; rts. 4th call in 0x1b572 (after 0xc962 runAllSpeedGovernor, before 0x2dbde smoothPowerTakeOffReferenceEngineSpeed).
- CM848: lha 0x40b000; cmpwi 8; bl 0x1ec70; sth 0x40a887, 0x40affe. bl 0xb9b4 (after 0xea00, 0xe78c; before 0x2ac44 smoothPowerTakeOffReferenceEngineSpeed).
- e2m 1050 +0/+2, 1053 +0 same in both. VERDICT CONFIRMED twin updateFourDimensionalFueling.

## crank entry trio (CM550 0x17d2a / CM848 0x1bf44)
- Both handlers: (prev==1 && state==2) || (prev==3 && state==7) -> step1, step2, step3; then 0x17ca6 / 0x1be64; prev = state. Identical skeleton.
  CM550 bsr 0x17a8e, 0x17baa, 0x17b8a; CM848 bl 0x1bc30, 0x1bd74, 0x1bd44.
- 0x17b8a vs 0x1bd44: identical (switch==1 -> calibrated exit rpm, else LSG ref -> crank_exit_speed). e2m CKEXESSW 1254 (+3C / +38), CKCNEXES 105F (+0 / +E), CKEXES 105E (+14 / +12). VERDICT CONFIRMED twin selectCrankExitSpeed.
- 0x17a8e: fault word2 bit0/bit1 (enabled in 0x806ac0 = fault_processing_enable_flags[2]) or coolant < CKCDCLTP -> cold (0x807ef8 / 0x807efc); > CKHTCLTP -> hot (0x807ef6 / 0x807efa); else linear interp -> 0x80d0a6 (CKIIFL) / 0x80d0b2 (CKIIFLES).
  CM848 0x1bc30: coolant faults -> defaults; else 2D coolant x baro table + 1D break speed table + overrides. Same role, different code -> counterpart. VERDICT CONFIRMED cm550_calculateCrankInitialFuelByCoolantTemperature.
- globals: 0x803f8a (no row, nothing covers it; EEPROM image -> _cal; only ref cmpi.w at 0x17b90) crank_exit_speed_switch_cal OK.
  0x80d0a6 (no row; refs move.w 0x1781c read + a3 write in 0x17a8e) crank_initial_fuel OK. 0x807eea crank_exit_rpm OK (outside EEPROM; refs 0x17b9a + data list 0x35694/98).

## 0x8002ac projection array
- pass 1 0x12ca2-0x12d84, pass 2 0x12d8a-0x12e54: [0]=ref c1, [4]=ref c5, [2]=ref c3 (/10000, divs), [5]=-[0], [1]=-[4], [3]=-[2] (neg.l). Search: d4=[0], a2=0x8002b0, i=1..5 cmp.l bge -> index of max -> 0x809260 (CBDTI1) / 0x809262 (CBDTI2).
- All long accesses; no access to b2/b6/ba/be/c2/ae; no base-relative pointer into it (0x8002a4 / 0x8002a2 used as words only). Rows inside: b0, b2, b6, b8, bc, be, c0 (all misnamed). Dump all 0.
- Index = cylinder - 1 (pairs 0/5, 1/4, 2/3 = cylinders 1/6, 2/5, 3/4 opposite in 1-5-3-6-2-4). VERDICT CONFIRMED i32[6] cylinder_balance_reference_projections.

## torque curve pair
- 0xfa06 vs CM848 0x20b84: same bit 0x40 (LSDPEN, bit 6 of flags 12 in both structs), slope nonzero, x fueling / 167, clamp 0 (signed 16), point1 speed + fueling stores; callers 0xfa68 (shared setJ1939TorqueCurvePoints1And3AtDeratedFueling) + builder cases 2/3 in both. VERDICT CONFIRMED twin setJ1939TorqueCurvePoint1AtDeratedIdleFueling.
- 0xfb26: index +4 LSBPRFES outside LSRF +- LSRFESDC; +2 FSLMFLST 15 or 16 w/ word1 bit 9/10 enabled (0x806abe); d3 = FLINML==0x4000 ? 0 : 1; +1 HSRFST in {2,4,5,1} (0x800182 = HSRFBEDP else HSBKRFAE). Table 0xfc2e cases: 0->tail, 1 0xfc3e, 2 0xfc52 (bsr fa06), 3 0xfcac (bsr fa06 + faa6), 4 0xfd06, 5 0xfd26, 6 0xfd54 (fa68), 7 0xfd9c (fa68 + faa6). Tail (fuel - CLNTFL) x 25600 / (JCRFEGFL - CLNTFL), max 0x7d00 min 0.
  CM848 0x20d10: faults w/o enable mask, + limiting source 12, per-point reference fueling divisors, min -32000, calculated fuelings cached -> counterpart. VERDICT CONFIRMED cm550_updateJ1939EngineConfigurationTorqueCurve.

## lamp check / fault handler
- 0x23be8 (body 0x23be8-0x24802): btst #0,(0x80bcce) DSKYSWSS key switch; compares 0x80bd02 bits with 0x80bd08; debounces 0x8019fa..; limits ROM 0x611c8 / 0x611ca; status words 7 (0x80600e) and 8 (0x806010) + first-occurrence 0x80604e / 0x806050. No 0xffxxxx access -> cm550_. Only caller jsr 0x2480a (0x24804, after 0x23a90). VERDICT CONFIRMED cm550_checkLampDriverOutputFaults.
- CM848 0x1d9b8: fault scan over 50 words + buildFaultConditionMask + processFaultScanGroup, clear request, OBD monitors, system_switch_status / _2, countdown > 0x18. CM550 0x14dc6: 32 words, no mask, no OBD, switch status from bit tables (3 words) -> counterpart. VERDICT CONFIRMED cm848_runFaultHandler (describer cm848_runPeriodicFaultProcessing also OK).

## TPU channel functions
- 0x1839a dispatcher (EPCMSYTY 0x807f26): 1 -> 0x1ae22, 2 -> 0x1b39a, 0 -> 0x1b1ea.
- 0x1b39a: table fill (0x80ceae, ESIITB02 0x807ebc), end ptr 0x80d07c, next ptr 0x80d084, 0x80cd0c, sums 0x80d074 / 0x80ccfc; then ch1 disable, CFSR3 bits 7-4 = 0xd, p1 0x100, p3 0, p4/5 long 0, p0 0xb, HSQR/HSRR 3, CPR 2, handler 0x808ee0 = 0x1b4b2, CIER bit1; clr.b 0x80d2cc, clr.l 0x80d2d2. Type 0 0x1b1ea same TPU set-up but gated by 0x807ed4 & 8 and handler 0x1b30a.
  VERDICT CONFIRMED mc68k_initializeTpuChannel1SpeedMeasurementResetInput (both roles agree).
- 0x1af32 (installed only at 0x1aec6 by 0x1ae22): param5 low byte 0xffff1b -> CMSNTTCU 0x80d2be; clr.w 0xffff18; 0x807f9d -> 0x80d2c2; wide (0x807f98) / narrow (0x807f9a) -> CMSNCUER down / word0 bit0 clear; EGPITTCU 0x80ccea vs EGPSCU01 / EGPICU02: match -> CMSYSS/CRSYSS = 1, clear w2 0x800, CKTTCUER down; mismatch -> 2, resync, CKTTCUER up to CKTTERMX -> w0 bit0 + w2 0x800. Neither -> CMSNCUER up to CMSNERMX -> w0 bit 0. Then jsr 0x3478c, 0xc87e, CISR bit1 clear, rte.
  VERDICT CONFIRMED mc68k_tpuChannel1CylinderIdentificationPulseInterruptHandler.
  NOTE: 0xc87e plate still names 0x1af32 'mc68k_dutyCycleMonitorIsrHandler' (stale after rename).
- 0x80d2c2: move.b 0x1af5e (reload from CMSNTMCU low byte); tst.b 0x19bc4 / 0x1a624, subq.b 0x19c1a / 0x1a67a in mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode0 / Mode2 after cmpi.w #1,(0x807f26); at 0 -> CMSNFXER 0x80d2c1 up to CMSNFXMX 0x807fa0 -> w0 bit0, cam_sync_state = 2, w2 0x800. Byte only. No e2m record. Dump 0.
  VERDICT CONFIRMED cylinder_identification_pulse_timeout_counter byte.

## more
- 0x1a6e8 (installed only at 0x1a510 by 0x1a47c): TPU_CH15_PARAM6 0xfffffc hi -> CKSYERTY 0x80d293, lo 0xfffffd -> CKSYERTT 0x80d292; 0xc0 -> CMSYSS/CRSYSS 0 else 2; jsr 0x34a82; CISR bit0 clear; rte. Set-up seeds 0xc000 (0x1a4d8). Config 1 handler 0x19f82 (no row) reads the same bytes then branches on 0 / 0xff. Config 0 handler 0x19c88 only jsr 0x34a82.
  VERDICT CONFIRMED mc68k_tpuChannel0MissingToothSyncErrorInterruptHandlerMode2 ('Mode2' = configuration 2 like its set-up and the ch10 handler Mode2).
- CM550 start-up: 28 jsr 0x1bf54 scheduler_init (0x2876e), 29 jsr 0x30b0e (0x28774), 30 0x42ad4; 45 0x2658c LSG idle adj (0x287d4), 46 0x26b82 (0x287da), 47 0x4cf42. 0x26852: bsr.s 0x2685e first step of 0x26854, before move.l #0x26834,(0x808f20) and QSM regs.
- CM848 start-up: 0x549c4 bl 0x505d94 resetDataCollector, 0x549c8 bl 0x54220, 0x549cc bl 0x5246e0 initializeEngineRetarderCruisePermissionFilter. 0x54c80 bl 0x505bd8 initializeCoolantTemperatureSource, 0x54c84 bl 0x1806c, 0x54c88 bl 0x5071dc initialization_step_14.
- CM848 0x26f7c: 0x53ae0 queues when j1939_transmit_message_object_number < n <= j1939_last_receive_message_object_number, else bl 0x26f7c. Dispatcher 0x53b68 (IFLAG 0x3070a4): n == transmit obj -> 0x53aa8 else 0x53ae0. CM550 0x1e086 just returns out of range (no hook). VERDICT CONFIRMED cm848_emptyNonJ1939MessageObjectInterruptHook.
- CM848 0x2c0fc: 0x10110 state==0 && flag==1 -> bl 0x2bf6c, state 7, bl 0xfe5c, bl 0x2c0fc, bl 0xff04. CM550 0xd4ae only bsr 0xd3e6 after state 7. VERDICT CONFIRMED cm848_emptyVariableSpeedGovernorSelectionStep.
- 0x80a982: STUOTHGV 107C +16 both firmwares; CM848 0x40a1c0 variable_speed_governor_selected_flag. refs 0xd4b8 (a2 in 0xd4ae), 0xd5da move.w 0x803bf0 -> it, tst.w 0x1ac1e / 0x1ac34. VERDICT CONFIRMED.
- 0x80db04: LSCIRF 1067 +2; only user 0x26616 (a2): stopped -> cold ? LSCIRFSR : 0; running after LSCITMLM or warm -> ramp down by LSCIRMRT to 0; floor into 0x80db06 unless override (flags12 0x4000 + 0x80db08). CM848 has no 1067 block. VERDICT CONFIRMED low_speed_governor_cold_idle_reference_speed.
- enum: CM550 handlers 0x22530 (ID 2 @+1, length 4 @+3, offset clr.l) / 0x2257c (ID, offset 2 bytes @+3/+4, length 1 @+5) / 0x225e0 (ID, offset 4 @+3, length 4 @+7) / 0x22646 (addr 4 @+1, len 1 @+5 -> 0x2238e) / 0x2268e (addr 4 @+1, len 4 @+5 -> 0x2238e). Registered 0x43/0x4a/0x4c/0x46/0x48 in 0x226da. Handler names already shared twins with CM848 0x50c640.. so CM848 member names apply.
  0x41: 0x22370 registers 0x41 -> 0x222b4: ID bytes 1-2 -> lookup 0x10e16; fail -> 8; else 7-byte frame PGN 0xef00: 0x42, ID, address 4 bytes, jsr 0x103ba; return 0xff. CM848 0x50c318 identical behaviour. All 6 CONFIRMED.

## CM848 cylinder balancing + globals
- 0x42bd0 (bl 0x451a8 in hpcr_processEngineSyncPulses): enable || misfire flag; crank sync 4; start tooth (ch0 PARAM4 low byte) && counter 0xff -> latch ch12 PARAM7 byte (0x3fb57c) + ch14 capture (0x3fb578), counter 0; else counter < max && PARAM7 byte == latched -> buffer[counter] = (capture - prev) >> 2. Out of sync -> 0xff. CONFIRMED hpcr_fillCylinderBalanceAccelerationBuffers.
- 0x42d78 (bl 0xc2cc executiveFrameInterruptHandler): stop compensation table, Fourier comps 4/6/8, minus dynamic compensation, projections local_48[6] (= CM550's 0x8002ac array concept), trims learn, limit mode 1 restores 0x3fb580 on limit exceeded. CONFIRMED hpcr_calculateCylinderBalanceTrims.
- 0x43a5c (bl 0x54a40 applicationMain): counter 0xff, cache offsets 2/2, copy trim_cal[i] -> 0x3fb580[i] for count_max. CONFIRMED hpcr_initializeCylinderBalancing.
- 0x408ef6: e2m 81AE +14 CBD_Enable, byte (lbz), ROM image 0x6eb10 = 1, ROM-copied window -> no _cal. CONFIRMED cylinder_balance_enable_flag.
- 0x3fb580: only addi bases 0x438b0 / 0x43a9c (lhax/sthx); no rows in 0x3fb580-0x3fb58f (next 0x3fb590); source trim_cal 0x3fee82 also spans 16 bytes to 0x3fee92. CONFIRMED i16[8] cylinder_balance_power_up_fueling_trims.
- 0x3fa712: CONFIRMED friction_fuel_coolant_temperature_correction (word).
- 0x55e9c: name OK but plate 'an interrupt of a channel without a function does nothing' is WRONG: mpc555_driveOutputLineHigh sets TPU-B CFSR1 ch4 function 0xF (0x5009c-0x500b0), and ch4's entry is the stub. AMEND comment ('a channel without an interrupt handler of its own'). Describer's 'Unused' name also wrong for the same reason.
- name check (judge/check_names.py): every final name free, no duplicates; enum members after change unique and equal to CM848's.
- 0x42d78 plate: 'Limit mode 1 restores them' omits the condition: the restore runs only when a trim leaves min..max (trim_limits_exceeded_flag); mode 0 subtracts the step, 2 zeroes; the add runs only while cylinder_balance_compensation_enable_cal == 1 and misfire_monitor_cylinder_balance_suspend_flag == 0. AMEND comment.
- Stale comment references after the renames (applier should text-replace per firmware): CM550 cm550_multiSpeedParameterInterpolation (5 rows), vp44_fuelLimitExceedanceStatisticsAccumulator (7), vp44State2TransitionHandler (3), mc68k_dutyCycleMonitorIsrHandler (3, incl. 0xc87e plate), cm550_diagnostic_parameter_handler (2); CM848 hpcr_cbdCalculateCylinderTrims (61), hpcr_cbdFillAccelerationBuffers (9), diagnosticMainStateProcessor (10), cm848_calculateJ1939PercentPeakTorquePoints (10), cm848_setJ1939TorqueCurvePoint1AtDeratedIdleFueling (7), throttle_demand_offset_cal_working (3), cm848_emptyStubFunction5 (2), cbd_enable_flag (2).
## FINAL: all functions CONFIRMED except CM848 0x55e9c and 0x42d78 AMENDED (comment only). All globals and enum members CONFIRMED. Skipped 0x8002b0 / 0x8002b4 stay skipped (array).
