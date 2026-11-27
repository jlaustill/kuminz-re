# N3 describer notes (round 95)

## CM550 0x1fe84 scheduleJ1939PeriodicMessage - PROTOTYPE CONFIRMED
- Frozen .cpp has NO body at 0x1fe84 (no function header there); read from the disassembly.
- movem.l a3/a2/d2 (12 bytes) then: move.l (0x10,a7) = entry +4 long = queue (0 -> queue 0 at 0x80096e / count
  0x800a9a max 20 / tick 0x800a9c; 1 -> queue 1 at 0x800a36 / count 0x800a9b max 10 / tick 0x800a9e; any other value
  falls to 0x1ff04 with a2 / d2 as the caller left them - no caller passes another value).
- move.w (0x14,a7),(a2) = +8 word = PGN -> entry +0.
- moveq #0,d0 / move.w (0x18,a7),d0 / divs.l #10 / add.w d2 (current tick) -> entry +4 next_tick: +12 = first send offset ms.
- moveq #0,d0 / move.w (0x16,a7),d0 / divs.l #10 -> entry +2 interval_ticks: +10 = interval ms.
- move.l (0x1a,a7),(0x6,a2) = +14 long = builder -> entry +6.
- Return: moveq #1,d0 when count = 20 / 10 (full); clr.b d0 on success (only the low byte is 0; the upper bytes keep the
  quotient) -> return type byte.
- Only caller: mc68k_initializeJ1939Datalink 0x28b80 (movea.l #0x1fe84,a4 at 0x28b8a, then 19 x jsr (a4); pushes pea builder,
  move.w offset, move.w interval, move.w PGN, clr.l / pea (1).w queue; lea 0x2a = 3 calls x 14 bytes). Never reads d0.
  PGNs are the real numbers (0xfef1 65265 / 100 ms / 70; 0xf004 61444 / 20 / 0; 0xf000 61440 on queue 1 / 100 / 50 ...).
- Prototype: byte scheduleJ1939PeriodicMessage(dword queue_index, ushort pgn, ushort interval_milliseconds,
  ushort first_send_offset_milliseconds, void* builder).

## CM848 0x538c8c scheduleJ1939PeriodicMessage - twin, prototype
- r3 cmpwi 0 (0 -> queue 0 0x3fd2e2 / count 0x3fd40e max 20 / tick 0x3fd410; else queue 1 0x3fd3aa / 0x3fd40f max 10 /
  tick 0x3fd412); sth r4 -> +0; divw r6/10 + tick -> sth +4; divw r5/10 -> sth +2; stw r7 -> +6; li r3,1 full / li r3,0.
- Same store order as CM550 (+0, +4, +2, +6), same limits, same caller list (cm848_j1939_system_init, same PGNs / periods /
  offsets; CM848 adds PGN 65241 and 65504). Neither caller uses the result.
- Prototype: uint scheduleJ1939PeriodicMessage(uint queue_index r3, word pgn r4, int interval_milliseconds r5,
  int first_send_offset_milliseconds r6, void* builder r7). (divw reads the whole r5 / r6.)

## CM550 0x35088 cm550_tableLookup2D - PROTOTYPE CONFIRMED
- link a6,#0 / movem saves d1-d6 a0-a5 (everything but d0) / movea.l (0x8,a6),a2 = the long at +4 = the record.
- Reads the record as table_lookup_2d_arguments_t (+0 x offset cache, +2 x axis ptr, +6 x input, +8 y offset cache,
  +10 y axis ptr, +14 y input, +16 z ptr, +20 no-interpolation word); writes back +0 and +8 (move.w a1,(a2) /
  move.w a5,(0x8,a2)).
- Every exit sets only d0.w: 0x35180 move.w (a1),d0 (flag set: the grid point at the low x / y corner), 0x35202 add.w d6,d0,
  0x35208 move.w d6,d0 (y exact), 0x3521a sub.w d3,d0. The upper word of d0 is a divu remainder or the caller's bits.
  Unsigned math (mulu.w / divu.w, bcs / bcc), clamps at both axis ends.
- Callers: 25 jsr (0x35088).l + 10 jsr (a5) after movea.l #0x35088,a5 (0x1c674, 0x1de6a): all do move.w d0,<ea>
  or andi.l #0xffff,d0 (0x1292a, 0x12c7e). Nobody reads d1 (it is restored) -> Ghidra's undefined8 / CONCAT44(...,in_D1)
  is the default d0:d1 pair for an undeclared return.
- Prototype: ushort cm550_tableLookup2D(table_lookup_2d_arguments_t* lookup) (row 'return' ushort + row 0).
- CM848: cm848_dualAxisTableInterpolation 0x566cc = COUNTERPART (r3 two-word cache, r4-r8 inputs / axes / grid, r9
  signedness + step flags) - different interface, not a twin.

## CM550 J1708 ring pointers 0x80dc98 / 0x80dca2 - CONFIRMED
- Init cm550_diagnosticBufferPointerInit 0x1dd2c (a1 = 0x80dc94 base): transmit ring 0x808b00-0x808bff (0x80dc9c =
  0x80dc94 = 0x808b00 [0x808bdc & ~0xff], 0x80dc98 = 0x808b01, *0x808b00 = 0); receive ring 0x808c00-0x808cff (0x80dcaa =
  0x80dca2 = 0x808c00, 0x80dca6 = 0x808c01, *0x808c00 = 0). Pointers advance in their low byte only (addq.b to +3) = 256-byte
  rings. Records = [length][bytes...].
- 0x80dc98: the byte being transmitted. mc68k_startJ1708Transmission 0x16d4e sends *ptr to QSM_SCDR (first byte = the
  MID, checksum = it, count 1; movea.l #0x80dc98,a2 at 0x16d7c = its only absolute reference). mc68k_j1708SciInterruptHandler
  (a4 = 0x80dc94, +4): state 0 echo == *ptr -> ptr+1, send *ptr; state 1 ptr+1 send; count == *0x80dc9c (the length byte)
  -> state 2: send ~sum+1, ptr+1; state 3: 0x80dc9c = ptr (next record's length byte), ptr+1 (its first byte).
  mc68k_j1708BusTimerInterruptHandler: no echo (receive mode 0) -> ptr = 0x80dc9c + 1 (restart the message).
  -> name j1708_transmit_byte_pointer (alternative j1708_transmit_read_pointer).
- 0x80dca2: the length byte of the record being received. SCI handler per received byte: *0x80dca6 = byte, 0x80dca6+1,
  *(0x80dca2) += 1; overflow when 0x80dca6 = 0x80dcaa. Bus timer (message end): length < 3 -> discard (0x80dca6 =
  ptr+1, *ptr = 0); checksum 0 -> *ptr -= 1 (drops the checksum byte), ptr = 0x80dca6 - 1, *ptr = 0 (record closed,
  next one starts there); bad checksum -> discard (+ the [2][6][0x74] record when the MID < 7 and there is room).
  mc68k_dispatchJ1708ReceivedMessages loop 0x16440: move.l (0x80dca2),d0 / cmp.l (a3 = 0x80dcaa) -> drains records
  while the read pointer differs from it (or the full flag 0x80dcae is 1); advances 0x80dcad (low byte) by length+1.
  -> name j1708_receive_message_length_pointer (the start of the message being received).
- CM848: none (no J1708 driver; its SCI is the Chrysler SCI link).
- Neighbour facts (not asked): 0x80dc94 = transmit write pointer (dc94 != dc9c -> a message waits), 0x80dc9c = the length
  byte of the message being sent (not an 'end pointer'), 0x80dca6 = receive write pointer, 0x80dcaa = receive read pointer.

## CM550 0x80d03e io_control_bit0_state - CONFIRMED (main speed period sum between vehicle speed pulses)
- e2m 100C +34C ESACGR [TCNT] 4 bytes 'ACCUMULATED MAIN EPS PERIOD BETWEEN VSS INTERRUPTS' resolves to 0x80d03e;
  100C +354 ESCTGR [CNT] 'NUMBER OF MAIN EPS INTERRUPTS BETWEEN VSS INTERRUPTS' -> 0x80d046 (io_control_bit4_state);
  100C +358 ESIPPE 'EPS_PERIOD: TIME BETWEEN THE TWO MOST RECENT EPS INTERRUPTS' -> 0x80d04a (io_control_handshake_state).
- Code: the four TPU channel 10 primary speed interrupt handlers (modes 0 0x19acc / 1 0x19e90 / 2 0x1a52c / 3 0x1a8a4):
  move.l (0xffffa8),(0x80d04a) [TPU CH10 PARAM4-5 = the new period]; moveq #-1,d0 / sub.l (0x80d03e),d0 / cmp.l (a2),d0 /
  bcs skip / add.l period,(0x80d03e) / cmpi.w #0xffff,(0x80d046) / bcc / addq.w #1 (0x19b1e-0x19b3c): sum with an overflow
  guard + a saturating count.
- No other reference in the dumped ROM (no constant 0x80cfc0-0x80d049 outside these 16 instruction words; 0x80d042 /
  0x80d048 backup sums never referenced): the reader (CM848: cm848_vehicleSpeedSensorInterruptHandler divides sum / count
  into drivetrain_ratio_engine_period_average and clears both) is not in the dump (undumped ROM above 0x40000).
- CM848 equivalent: engine_speed_state.main_speed_period_sum_between_vss_pulses (0x40b7ae, e2m 819B +20 [ESACGR]), adder
  hpcr_processEngineSyncPulses. The 0x80d046 count = CM848 main_speed_pulse_count_between_vss_pulses.
- Name: main_speed_period_sum_between_vehicle_speed_pulses (spelled-out form of CM848's field; RAM, no _cal).

## CM550 0x801d44-0x801d59 = one 22-byte struct (CM848 j1939_powertrain_messages_received_t without ETC2 / previous words)
- Every ROM constant 0x801d3b-0x801d63: 0x2ef54 movea #0x801d3c (DM7 test id byte, separate), 0x2efe0 movea #0x801d44,a1 /
  0x2f01c movea #0x801d48,a0 (ETC1 handler 0x2efd0: data[0] -> 0x801d44, data[4] -> 0x801d48, nothing else), processEngineTsc1Request
  0x2f128: a3 = 0x801d4c; data[0] -> 0x801d4c (0x2f150); (2,a3) = data[1], (1,a3) = data[2], (3,a3) = data[3] (0x2f16e-0x2f182);
  read (1,a3) << 8 | (2,a3) (0x2f232 / 0x2f316 / 0x2f412), (3,a3) (0x2f384 / 0x2f428); 0x801d54 cmp.b 0x2f1f2 / 0x2f1fc, move.b d4
  0x2f29e; 0x801d56 move.w read 0x2f22c, write 0x2f320 / 0x2f41c; 0x801d58 move.b read 0x2f212 / 0x2f220, write 0x2f388 / 0x2f42c.
  0x801d5a = the J1939 receive handler table (6-byte entries: PGN word + handler; count 0x801e1a = 0x801d5a + 32 x 6; dump fe f1
  00031c84 / f0 03 00032e4c ...) - a separate object, so the cluster ends at 0x801d59. RAM dump: all 0 in 0x801d3c-0x801d59.
- Layout = CM848's order (ETC1 8-byte image, TSC1 8-byte image, accepted priority / speed / torque) with no
  etc1_output_shaft_speed_previous word, no ETC2 block, 68k alignment (pad at +17 before the word):
  +0 etc1_status_byte_1 byte | +1 reserved_1 byte[3] (ETC1 bytes 2-4 never stored) | +4 etc1_status_byte_5 byte |
  +5 reserved_5 byte[3] (ETC1 bytes 6-8) | +8 tsc1_control_byte byte | +9 tsc1_requested_speed byte[2] (big-endian copy,
  [0] = data[2], [1] = data[1]; odd address so byte accesses) | +11 tsc1_requested_torque byte | +12 reserved_12 byte[4]
  (TSC1 bytes 5-8) | +16 tsc1_accepted_priority byte | +17 reserved_17 byte (alignment) | +18 tsc1_accepted_requested_speed word |
  +20 tsc1_accepted_requested_torque byte | +21 reserved_21 byte. Total 22.
- Type cm550_j1939_powertrain_messages_received_t (layout differs -> cm550_ prefix per the algorithm_enable_flags
  convention); global 0x801d44 j1939_powertrain_messages_received (CM848's global name). Replaces the 7 rows 0x801d44 ..
  0x801d58 (they become field coordinates).
- Aside: 0x801d3c = DM7 test identifier (cm550_FUN_0002ef4a: data[0], 0 -> bit 0x100 / 1 -> bit 0x200 of
  supported_non_continuous_monitors_bits) = CM848 j1939_dm7_test_identifier 0x3fa97a.

## CM848 0x29c98 cm848_calculateFuelDemandFilter / 0x29de0 cm848_initFuelDemandFilterDimensions - L4 lead CONFIRMED
- 0x29c98: 3 x cm848_dualAxisTableInterpolation of maximum_torque_map_grid (e2m MT_Max_Torque_Map) over
  engine_speed_state.filtered_engine_speed: y 0 (cache 0x3faf98), chi lower map number << 14 clamped 0xffff (0x3faf9c),
  chi upper << 14 (0x3fafa0); cm848_interpolateAlphaChiValue(lower, upper, alpha0, chi numbers, chi_hundredths,
  alpha_percent) -> maximum_torque_at_current_engine_speed (0x40aee6, sth at 0x29db4); 0 -> 1 (sth 0x29dc8). Only stores.
  Called first in cm848_periodicTaskSet_sensorProcessing 0xb98c (then cm848_calculateJ1939ReferenceEngineFueling, a user).
  Nothing about fuel demand or a filter. -> cm848_calculateMaximumTorqueAtCurrentEngineSpeed.
- 0x29de0: maximum_torque_at_current_engine_speed = 1, the 3 two-word caches = 2; once from cm848_applicationMain.
  -> cm848_initializeMaximumTorqueAtCurrentEngineSpeed.
- Sibling cm848_lookupMaximumTorqueAtEngineSpeed 0x21ac0: same 3 lookups + blend but speed param (r3), fresh local
  caches, returns the value, no 0 -> 1, no global store.
- CM550 counterparts (already named): cm550_calculateMaximumTorqueAtCurrentEngineSpeed 0x269f2 (one cm550_tableLookup2D
  with engine_rpm_primary x alpha_blend_factor, 0 -> 1) / cm550_initializeMaximumTorqueAtCurrentEngineSpeed 0x26a2e
  (1 + the lookup record's pointers / offsets 2). Different lookup steps -> counterpart, keep cm848_ prefix.

## CM848 0x29ecc (unnamed leaf after cm848_calculateInjectionTimingMainMisfireLimit's blr 0x29ec8) - DEAD, twin by code
- Body 0x29ecc-0x29f38 (blr; 0x29f3c = cm848_absoluteValue16): no frame (calls nothing). lhz 0x3fd5ec & 0x100
  (algorithm_enable_flags_40_cal.misfire_timing_limit_enable) = 0 -> return; lha 0x40a2f2 (injection_timing_intermediate_source_code)
  != 0 -> return; lha 0x40a2f0 (main_injection_timing_copy) -> sth 0x40aeea (main_injection_timing_before_misfire_limit, e2m 8A3D +2
  SOI_Before_MST); lha 0x40aee8 (injection_timing_main_misfire_limit); cmpw limit,timing / ble return; sth limit -> 0x40a2f0;
  0x40a2f4 (injection_timing_increment_flags) &= 0xfffe; li 11 -> 0x40a2f2.
- Unreferenced: ppc_reach.py (I-form / B-form branch targets, aligned 4-byte values, lis+addi / lis+ori pairs over
  cm848_rom.bin and cm848_flash2_live.bin) finds nothing for 0x29ecc (the same scan finds bl 0xbab0 -> 0x29e50 and bl 0x54a64
  -> 0x29e24). Dead under any calibration. The live misfire raise is in cm848_calculateMainInjectionTiming 0x4ae20
  (injection_timing_demand < limit -> limit, MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT, adjustment flags 0).
- CM550 cm550_applyMisfireTimingLimit 0x26af0 = the same steps in the same order: 0x803cd4 bit 0 (misfire_timing_limit_enable),
  tst.w 0x80d348 (TSTPTAST intermediate state) = 0, 0x80d346 -> 0x80a270 (BSTABELM before limit), cmp 0x80a26e limit / bls,
  limit -> 0x80d346, andi.w #0xfffe 0x80d34a, move.w #11 0x80d348. Only difference: unsigned compare (bls) vs signed (ble).
  Same module order: CM550 0x26a7e init / 0x26ab8 calculate / 0x26af0 apply = CM848 0x29e24 / 0x29e50 / 0x29ecc.
  Call graph differs: CM550's is step 1 of cm550_runInjectionTimingModificationChain; CM848's has no caller.
- Name: cm848_applyInjectionTimingMainMisfireLimit (trio stem of its CM848 siblings); shared applyMisfireTimingLimit only if the
  judge accepts an unreferenced copy as a twin.
- Enum aside: the 11 it writes into injection_timing_intermediate_source_code (INJECTION_TIMING_INTERMEDIATE_SOURCE has 0 / 2 /
  25 / 27 / 28) is the e2m 103B label 0B MISFIRE (= MAIN_INJECTION_TIMING_SOURCE 11); only store = this dead code.

## CM848 safety_* blend globals 0x40b31e-0x40b326 - users: cm848_applyFuelPressureGovernorFaultBlend 0x3889c + its initializer 0x38a98 only
- Function: gate safety_fuel_blend_enable (0x4088e4 byte). Fault = any of fault_detected_cal +6 bits 0x200 / 0x400 / 0x800 / 0x1000
  (faults 57-60: governed speed check / demand above limit / decay below model / metering feedback low).
  Fault: 0x40b326 = 1; 0x40b324 = lookupTableInterpolation(0x3fb3c2, filtered engine speed, 0x4088e8 axis, 0x40891a values, 0)
  (sth 0x38950); rising edge (0x3fb3c0 prev = 0, 0x40b326 != 0) and final_fueling 0x40a2ce > lookup -> 0x40b320 =
  injection_quantity_combustion_chi_maximum 0x40a4ea (sth 0x38988); if 0x40b320 > lookup: 0x40b322 += 0x4088e2, clamp 25600.
  No fault: 0x40b326 = 0; 0x40b322 = 0 -> result = chi maximum; else 0x40b322 -= 0x4088e0 (the 0 clamp at 0x38a04 is unreachable:
  clrlwi then cmpwi >= 0 - a value below the decrement wraps to 16-bit).
  Result = 0x40b320 x (25600 - 0x40b322) / 25600 + 0x40b324 x 0x40b322 / 25600 -> sth 0x40b31e (0x38a50); below
  torque_derate_fuel_quantity 0x40afac -> it + source 62 FUELING_STATE_FUEL_PRESSURE_GOVERNOR_FAULT_BLEND (0x40afae).
  0x3fb3c0 = 0x40b326 at the end. Init 0x38a98: cache 2, 0x40b31e = 0x40b320 = 5888 (0x1700), 0x40b322 = 0.
- No e2m record at any of the five; no other reader of 0x40b31e (write-only result copy).
- Names (prefix = the function's concept): 0x40b31e fuel_pressure_governor_fault_blend_fuel_limit; 0x40b320
  fuel_pressure_governor_fault_blend_start_fuel; 0x40b322 fuel_pressure_governor_fault_blend_fraction; 0x40b324
  fuel_pressure_governor_fault_fuel_limit_by_engine_speed; 0x40b326 fuel_pressure_governor_fault_active_flag (and 0x3fb3c0
  safety_condition_prev_flag -> fuel_pressure_governor_fault_active_previous_flag). CM550: none.

## CM848 0x40af7c governor_tuning_set_blend_weight - all_speed_governor_ prefix SUPPORTED
- Machine-code accesses (ppc_data_refs.py, lis + D-form): 0xfd34 cm848_calculateAllSpeedGovernorNoLoadFuel (blends
  all_speed_governor_friction_fuel_blend_0 / _128 -> all_speed_governor_no_load_fuel), 0xff18
  cm848_calculateGovernorCompensatorCoefficients (blends all_speed_governor_droop_blend_0 / _128 -> all_speed_governor_droop and the
  ASG droop gains), 0x2c048 sth / 0x2c050 lhz cm848_blendAllSpeedGovernorReferenceSpeeds (writes it from drivetrain_ratio tables or the
  default; blends -> all_speed_governor_minimum / maximum_reference_speed), 0x2c10c sth cm848_initializeAllSpeedGovernorTuningSetBlendWeight
  (= governor_tuning_set_default_blend_weight_cal, e2m 1387 +8 ASG_Droop_Flag_Trim), 0x45fa0 cm848_calculateAllSpeedGovernorEquivalentThrottle
  (> 128 test; blends the droop / friction fuel tables). Every user reads or writes all_speed_governor_* data.
- e2m: CHR 158D +0 ASG_Droop_Flag [ASDPFG] 'ASG droop selection flag; used to select droop source' (2 bytes, 1/128) - block
  not in the dumped ID table, but 158D +2 ASG_Max_RPM / +4 ASG_Min_RPM = 0x40af7e all_speed_governor_maximum_reference_speed /
  0x40af80 all_speed_governor_minimum_reference_speed by relative offset -> 0x40af7c = 158D +0.
- Name: all_speed_governor_tuning_set_blend_weight (unique). Family (not asked): the default cal / the two ROM tables could follow.
- CM550 counterpart: 0x80a9a2 asg_throttle_source_selector (e2m 107A +16 ASDPFG, TRUE / FALSE): a 0 / 1 switch (== 0 / == 1 picks a
  set) instead of a 0-128 blend weight.

## Final name choices (status: all leads done)
- 0x80dc98 j1708_transmit_read_pointer (ring symmetry: 0x80dc94 write / 0x80dc9c message length; receive 0x80dca2 message
  length / 0x80dca6 write / 0x80dcaa read). 0x80dca2 j1708_receive_message_length_pointer.
- 0x80d03e main_speed_period_sum_between_vehicle_speed_pulses; 0x80d046 main_speed_pulse_count_between_vehicle_speed_pulses.
- safety blend: 0x40b31e fuel_pressure_governor_fault_blend_fuel_limit / 0x40b320 fuel_pressure_governor_fault_blend_start_fuel /
  0x40b322 fuel_pressure_governor_fault_blend_fraction / 0x40b324 fuel_pressure_governor_fault_blend_target_fuel /
  0x40b326 fuel_pressure_governor_fault_active_flag.
- Enum: INJECTION_TIMING_INTERMEDIATE_SOURCE 11 = INJECTION_TIMING_INTERMEDIATE_SOURCE_MISFIRE_LIMIT (103B +4 SOI_State
  [TSTPTAST] label 0B=MISFIRE; CM848 store only in the dead leaf 0x29f30; CM550's twin writes 11 into its TSTPTAST 0x80d348).
- cm550_tableLookup2D keeps its name (counterpart of cm848_dualAxisTableInterpolation; CM550's 1-D lookup 0x34de0 already
  shares lookupTableInterpolation with CM848 0x55ef4).
