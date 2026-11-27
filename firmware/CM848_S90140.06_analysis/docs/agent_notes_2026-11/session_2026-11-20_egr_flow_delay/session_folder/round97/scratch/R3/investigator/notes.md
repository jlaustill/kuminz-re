# R3 investigator notes (round 97)

Tools in this folder: refs_by_func.py (abs refs + containing function), find_range_refs.py (ROM 4-byte values in a
range), ram_find.py (RAM dump search / words).

## ANC (acceleration noise control) - CM848 compiles the stage out (algorithm_enable_flags_3_t bits 12-14 "no reader")
Functions (CM550 only, no CM848 twin):
- 0xb2aa cm550_rpm_system_state_controller = the ANC FUEL limit calculation (andi.w #0x1000 of 0x803c9a = enable bit
  acceleration_noise_control_fuel_limit_enable). LEAD: rename (not in this batch).
- 0xb3d0 cm550_calculateAccelerationNoiseControlTimingLimit (bit 0x2000).
- 0xb4f2 cm550_engineStateFuelLimitInterpolator = the ANC ENGINE SPEED limit calculation (bit 0x4000). LEAD: rename.
- 0xb666 cm550_initFuelSystemOutputDriver = ANC start-up: ASANENF (0x80a2a8) = 1, NZESLM (0x80a290) = rated speed
  0x803f40. LEAD: rename.
- 0xb5e4 initializeEngineAccelerationFilters; 0xb614 fuel limit lookup set-up (+ NZFLLM = fuel_demand_maximum 0x808004);
  0xb63e timing limit lookup set-up (+ NZTALM = 0x400).
- selectEngineSpeedLimit 0x1d5a0 reads NZESLM as source 3 (0x1d640-0x1d650).

Condition directions (disassembly 0xb2aa-0xb5e2):
- fuel: rpm 0x80ccf4 cmp NZFLTRES 0x807a2a bcs -> not met when rpm < it (MINIMUM rpm); ESFT01AC 0x80a294 cmp NZFLACTR
  0x807a26 bgt -> not met above (MAXIMUM first-stage accel; above it also sets the inhibit); ESFT02AC 0x80a296 cmp
  NZFLFTTR 0x807a28 blt -> not met below (MINIMUM second-stage accel).
- speed: rpm cmp NZESTRES 0x807a34 BHI -> not met when rpm > it: a MAXIMUM rpm (e2m text says "above which" - the code
  disagrees); NZESACTR 0x807a36 bgt (maximum first stage), NZESFTTR 0x807a32 blt (minimum second stage).
- timing: coolant 0x80a336 cmp NZTACLTR 0x807a38 bls (minimum coolant), NZTAACTR 0x807a50 bgt, NZTAFTTR 0x807a3e blt.
All accesses word (move.w / tst.w / subq.w / cmp.w). Signed compares (ble/bgt/blt) on the accel thresholds -> i16.

Rows:
- 0x80003c NEW acceleration_noise_control_engine_speed_limit_inhibit_timer word: 0xb52e move.w NZESIHTM(0x807a4a)->it
  when ESFT01AC > NZESACTR; 0xb53a tst.w / 0xb542 subq.w; at 0 clr.w NZESLMIH (a0=0x80a2a0).
- 0x80003e NEW acceleration_noise_control_fuel_limit_inhibit_timer word: 0xb2ea move.w NZFLIHTM(0x807a4c)->it;
  0xb2f6 tst.w, 0xb2fe subq.w, at 0 clr.w NZFLLMIH 0x80a2a2.
- 0x800042 anc_fuel_limit_active_timer -> acceleration_noise_control_fuel_limit_hold_timer word (a4: move.w NZFLDYTM
  0x807a22 ->(a4) at 0xb34a/0xb35e, tst.w (a4) 0xb366, subq.w 0xb36a; 0 clears NZFLLMSS (a3=0x80a298)).
- 0x800046 anc_speed_limit_hold_timer -> acceleration_noise_control_engine_speed_limit_hold_timer word (a1 at
  0xb586/0xb59a/0xb5a2/0xb5a6; 0 clears NZESLMSS 0x80a29c).
- 0x807a22..0x807a50 the 10A5 cal block (RAM, outside the EEPROM image -> no _cal). Values from the RAM dump:
  NZFLDYTM 40 (2.0 s), NZFLRMRT 273, NZFLACTR 160 (1000 r/s), NZFLFTTR 64 (400 r/s), NZFLTRES 20800 (2600 rpm),
  NZCNESLM 14560 (1820 rpm), NZESDYTM 40, NZESRMRT 80, NZESFTTR 40, NZESTRES 20800, NZESACTR 136, NZTADYTM 40,
  NZTARMRT 26, NZTAFTTR 64, NZTAACLM 400 (no reader), ESFT01MX 94, ESFT01MN -94, NZESIHTM/NZFLIHTM/NZTAIHTM 40,
  NZTAACTR 160.
- 0x807a40 NZTAACLM: NO reader in the dumped ROM (find_range_refs 0x8079f0-0x807a60: none) and no RAM pointer.
  Full text in 4 other e2m files: "UNFILTERED ACCELERATION LIMIT USED TO DETERMINE ANC TIMING LIMITING AC..."
- 0x807a46 ESFT01MX / 0x807a48 ESFT01MN: calculateFilteredEngineAcceleration (twin) loads them as a3/a4 (0xb21a /
  0xb220). CM848 names engine_acceleration_first_stage_clamp_maximum (0x40880c) / _minimum (0x40880e) (CM848 e2m 8A42
  +4/+6, same mnemonics) -> reuse.
- 0x807a4c NZFLIHTM: the 3 refs in cm550_ramClearWithWatchdog / mc68k_initializeJ1708Datalink are cmpa.l #0x807a4c
  (a RAM clear loop bound), not accesses. Real access: move.w at 0xb2ea. Record signed -> i16 like its siblings.
- 0x80a290 NZESLM -> acceleration_noise_control_engine_speed_limit (siblings acceleration_noise_control_fuel_limit /
  _timing_limit). Dump 21200 (2650 rpm).
- 0x80a29e TSBENZTA: written only by cm550_applyAccelerationNoiseControlTimingLimit 0xb4da (copy of
  fuel_timing_advance_value 0x80d346 before the cap).
- 0x80a2a0 / a2 / a4: NZESLMIH / NZFLLMIH / NZTALMIH inhibit flags (1 on bare engine accel, 0 when the timer ends).
- 0x80a2a6 ASANODFG: 3 tst.w reads (0xb352/0xb46c/0xb58e), no writer in the ROM: forces the status on.
- 0x80a2a8 ASANENF: tst.w reads in the three ANC functions + move.w #1 in 0xb666: 0 blocks the limits.

## A/C + vehicle acceleration (no code in the dumped ROM)
- 0x807a00 ACVSACCO, 0x807a02 ACACDBCU, 0x80a280 ACHIAC: no ROM reference except the parameter_id_table (block bases);
  the whole A/C block (ACCHHY 0x8079fe, ACCHEA 0x80a27e ...) has no code reader in the dump.
- 0x807a1c VAACFTTC: RAM 0x803af2 holds the pointer 0x00807a1c with accumulator 0x80000000 at 0x803af6 = a
  filter record (ema_filter_state_t layout: coefficient pointer then accumulator) set up by code above the dump (no
  ROM ref to 0x803af2). Dump 0xf5c3. VAACMXLM 0x807a1e = 0x7800 (1200 mph/s), VAACMNLM 0x807a20 = 0x8800 (-1200).

## Auxiliary driver diagnostic recovery counters (updateEngineSyncStatus 0xd610 = the driver read-back diagnostics)
Per output: compare auxiliary_driver_feedback_bits 0x80bd03 (read-back; e2m 000E +35 DRR1FB..DRS1FB) with the commanded
latch io_driver_port_2_feedback 0x80bd09. Agree + command bit 0 -> the "low" recovery count; agree + command bit 1 ->
the "high" recovery count (verified 0xdbae btst #1,(0x1,a5) then 0x800168 at 0xdbd6-0xdbfe); each recovers the fault
bit that the same command state raised; limit = enhanced_diag_number_good_samples_before_recovery (word via a4).
All byte (clr.b / move.b / addq.b); cm550_clearKickdownControlState 0xe780 clears them (it is the driver diagnostic
reset - LEAD rename).
- 0x800168 bit 0x02 = DRR2FB = DSCD01FB cold start aid relay 1: high recovery of status word 8 bit 0x2000.
- 0x800170 bit 0x40 = DRR4FB relay 4 (no function record): high recovery of status word 9 bit 0x20.
- 0x800172 bit 0x08 = DRR7FB relay 7 = DSACFB A/C clutch: high recovery of status word 9 bit 0x80.
Sibling names (not this batch) use aux_driver / numbering by code order (aux_driver6 = relay 4 bit 0x40!).

## Sync pulse detection (cm550_detectEngineSpeedSensorSyncPulse 0x1025c; called from
## cm550_processPrimarySpeedPulsePeriodWithSyncPulse 0x1a988 BEFORE the new period goes into the ring)
- 0x8001a4 dword (move.l 0x102c4 src, 0x1035e dst, 0x103a8 dst): main sensor threshold; new = CSXT_1PC (0x807c1e)
  x period >> 8; the period is a sync pulse candidate when below it (cmp.l (a2),d2 / bls).
- 0x8001a0 dword: same for the backup sensor (0x10306 / 0x10370 / 0x103b2).
- 0x8001ac dword pointer (movea.l #0x8001ac,a3 at 0x1026a; move.l ...,(a3)): the ring entry before the next write
  position = the previous period (the new one is not yet in the ring); read by the two check helpers 0x1011c /
  0x101b8 (movea.l (0x8001ac).l,a3 / movea.l #0x8001ac,a2).
- 0x8001a6: NO reference; it is the low word of the dword 0x8001a4 -> delete the row (skipped).
- cm550_canBusTimingInit 0x10394 = initializer of both thresholds (LEAD rename).

## PTO
- 0x803d42 = e2m 1180 +8 CRSEACSW (dump 1) = CM848 cruise_set_accelerate_switch_select_cal (EEPROM 0xae 0x3fd530,
  same block/offset). In the EEPROM image -> _cal. 13 tst.w in mc68k_sampleAndDebounceDiscreteInputs: 0 -> set held
  25 passes gives coast (ori #8 at 0x15518) and resume gives accelerate (ori #2 at 0x1559c); nonzero swaps. Same for
  the cruise byte 0x80bcd4.
- 0x803d44 (no row) = 1180 +A CRUSDSSW (dump 1) = CM848 cruise_discrete_switch_inputs_used_cal; tst.w at 0x1538a
  gates the whole PTO / cruise switch decode (beq 0x15870). EXTRA new row.
- 0x800544 / 0x800546: addq.w per pass while the PTO set / resume bit (0x04 / 0x01 of 0x80bcd5) is on, capped 25
  (cmpi.w #0x19), cleared when off; at 25 the bit becomes accelerate / coast -> hold counters, not debounce.
- 0x80053e: 0/1 latch: clr.w 0x1543c when the PTO on bit 0x10 is off, move.w #1 0x1544c while word 0x80aa02 == 3
  (0x80aa02: no writer in the dump, no CM550 record at 117D +3E); while 0: set+resume -> PTSERUSW 0x20 and set /
  resume clear cruise byte bit 6 (no record for bit 6). SKIP (trigger meaning missing).
- 0x80bcdf = e2m 000E +11 (DSPTRUUC 0x01, DSPTSEUC 0x04, DSPTONUC 0x10, DSAUSHUC 0x40): the override values the
  sampler ORs in when algorithm_enable_flags_16_cal bits 8 / 10 / 12 are set (move.b at 0x153a0 / 0x153d4 / 0x15408).
- 0x808984 / 0x808986 / 0x80898c = 109D +0 / +2 / +8 PTMXEGES / PTMNEGES / PTROSWTM (CM848 109D +0 / +2 / +4 same
  mnemonics): power_take_off_maximum_engage_engine_speed / _minimum_ / power_take_off_remote_switch_timeout. No
  reader in the dumped ROM (the engagement logic is above the dump: power_take_off_governor_active_flag has no
  writer in the dump). Dump 24000 (3000 rpm) / 2400 (300 rpm) / 10 (1.0 s). CM550 e2m: PTMXEGES signed -> keep i16.
- 0x80dc30 = 1265 +4 PTSLFL; CM848 keeps it as operating_mode_governor_output.fuel_demand (struct with mode_code =
  PTSLFLST); CM550's 0x80dc32 PTSLFLST is flat power_take_off_or_user_fueling_state -> name the pair
  power_take_off_or_user_fuel_demand. Writers: cm550_oil_pressure_shutdown_controller 0x2dcb0 (= the PTO / user
  fueling selector, counterpart of cm848_selectPowerTakeOffOrUserFueling; LEAD rename); reader
  cm550_paramSystemModeController 0xf84c (driver demand fuel in PTO / pedal fault states).

## AFC / alpha (twin calculateAlphaAirFuelControlResult; CM848 names for the same 104A / 104B / 11D5 records)
- 0x807a5a 11D5 +0 AFFLMAN -> air_fuel_control_fueling_override_value (CM848 0x3feff2); read 0xc1a8 move.w into
  air_fuel_control_fuel_limit (a5 = 0x80a8f6) while algorithm_enable_flags_12_cal bit 0x8 (override) is set.
- 0x807aa6 104B +6 APAFTRTM -> air_fuel_control_alpha_timeout (CM848 0x5be60, same block/offset). Dump 19500.
- 0x80a906 104A +E FLAFSTFG -> alpha_air_fuel_control_state_detected_flag (CM848 0x40a176). Set 1 at 0xc2e0 when
  final_fueling_state == 0x10 (AFC derate), cleared by 0xc658, read 0xc51c.
- 0x80a912 (no record) -> alpha_air_fuel_control_timer_active_flag (CM848 0x3fa0dc, same role in the twin).
- 0x80a914 104A +1C APAFTR (CM848 104A +18) -> alpha_air_fuel_control_timer (CM848 0x40a180).
- 0x80de68 105B +0 AFCNICTA (CM848 0x40a2e4 has no row; label AFC_Timing_Increment) -> air_fuel_control_timing_increment
  i16 (ext.l at 0xc304; e2m signed). Written by 0xc2be (LEAD: AFC timing increment function), read by 0xc2ee.

## Cruise / RSG (no code in the dumped ROM; CM848 names for the same block/offset records, descriptions match)
1186 +16 / +18 / +1A, 1187 +6 / +1A / +20 / +26 / +28, 106C +6 / +8, 106D +C -> CM848 names (see output).
1197 +0 CRMXVSRF 'MAXIMUM ALLOWABLE VEHICLE SPEED SELECTED AS THE RSG REFERENCE' = CM848 8B89 +0 RSG_Reference_Speed
(same text; 8B89 not in CM848's dumped table, but 8B89 +8 RSG_HPCR_Leak_Reference_Speed lines up with 0x40b5c4
fault_vehicle_speed_limit if the base is 0x40b5bc road_speed_governor_reference_speed).

## ESP
- 0x807f6a 11DD +6 SPDIRTTD: 0x1acae: rate (ext.l) cmp.l threshold (zero-extended); ble -> clr timer 0x80d2b0, else
  +1 up to SPDIPE 0x807f68 -> engine_deceleration_rate_timer_threshold word (dump 500 = 50 rpm/s).

## "eps_accel" rows 0x8087f0 / f2 / fa / fc
Inside e2m 12DF +0 PPCVTB 'TABLE OF FUELING CURVES' (Z, MM3S): X PPHPCTI 0x8086b0 (10 points), Y PPSSFLXA 0x8086c6
(21 points) -> Z = 210 words 0x8086f2-0x808895 (next entry 12D4 at 0x808896). RAM lookup record at 0x8038c4 /
0x8038cc / 0x8038d2 points at the three (set up by code above the dump). No ROM reference into the table. SKIP: delete
the rows; LEAD: type 0x8086f2 (now j1939_timeout_clear_value) as word[210] and drop the rows inside it.

## FINAL decisions (see proposals.txt; check_unique.py: all unique in CM550 rows / functions)
- ANC accel threshold names use first_stage / second_stage (ESFT01AC / ESFT02AC), e.g.
  acceleration_noise_control_fuel_limit_maximum_first_stage_acceleration (0x807a26).
- NZ*IHTM cals -> *_inhibit_duration (not _time, to keep apart from the *_inhibit_timer counters).
- Skipped: 0x8001a6 (low word of dword 0x8001a4), 0x80053e (trigger 0x80aa02 == 3 unknown), 0x8087f0 / f2 / fa / fc
  (inside PPCVTB).
- Extras: 0x80003c / 0x80003e (asked), 0x803d44 cruise_discrete_switch_inputs_used_cal, 0x80053c
  power_take_off_on_switch_previous_state (byte: tst.b 0x15460 / move.b 0x15494), 0x803af2
  vehicle_acceleration_filter_state (ema_filter_state_t, from the RAM dump: pointer 0x807a1c + accumulator 0x80000000).
- Relay 4 / relay 7 verified by disassembly: 0xe33a btst #6,(0x1,a5) -> 0x800170 recovers word 9 bit 0x20 (0x806012);
  0xe500 btst #3,(0x1,a5) -> 0x800172 recovers word 9 bit 0x80.

## Status 2026-11-25: all 75 rows decided (69 named + 6 skipped) + extras 0x80003c / 0x80003e / 0x803d44 / 0x80053c /
## 0x803af2. Returned through StructuredOutput (functions[] empty: the batch lists no functions; function leads in notes).
