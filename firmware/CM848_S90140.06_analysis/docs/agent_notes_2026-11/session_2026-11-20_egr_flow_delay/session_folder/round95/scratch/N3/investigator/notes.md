# N3 investigator notes (round 95)

## CM550 0x1fe84 scheduleJ1939PeriodicMessage - prototype (SURE)
- entry: movem.l a3/a2/d2,-(a7) = 12 bytes, so (0x10,a7)=entry+4, (0x14)=+8, (0x16)=+10, (0x18)=+12, (0x1a)=+14
- +4 move.l -> queue selector dword (beq -> queue 0 @0x80096e count 0x800a9a tick 0x800a9c; cmp.l #1 -> queue 1 @0x800a36 count 0x800a9b tick 0x800a9e; any other value branches to 0x1ff04 with a2 never set)
- +8 move.w -> stored at entry+0 (pgn_key)
- +10 move.w zero-extended (moveq #0 / move.w) / divs.l #10 -> entry+2 interval_ticks  => interval_milliseconds ushort
- +12 move.w zero-extended / divs.l #10 + current tick -> entry+4 next_tick => first_send_offset_milliseconds ushort
- +14 move.l -> entry+6 builder (4 bytes)
- returns: moveq #1,d0 when count = 20 (q0) / 10 (q1); else clr.b d0 (only the low byte defined) => byte
- only caller: mc68k_initializeJ1939Datalink 0x28b80 loads movea.l #0x1fe84,a4 (0x28b8a) and calls jsr (a4) 19 times: pea builder / move.w offset / move.w interval / move.w PGN / clr.l (or pea (1).w) queue; lea (0x2a,a7) per 3 calls = 14 bytes per call; no caller reads d0
- first call: pea 0x31c84 / 0x46 (70) / 0x64 (100) / 0xfef1 (65265) / queue 0 -> PGN 65265 every 100 ms from 70 ms
- LEAD: 0x1fe84 has NO body in the frozen or current .cpp (ExportAnalysis drops a function whose decompile fails, silently). Also missing: 0x103ba cm550_sendCanSingleFrame, 0x16cd8, 0x18dae, 0x1e0bc, 0x21272 registerJ1939ReceiveHandler, 0x21642, 0x2ee62 registerJ1939DiagnosticService. They were missing in HEAD~20 too. The callers render the names (the function records exist).

## CM848 0x538c8c scheduleJ1939PeriodicMessage - prototype (SURE)
- r3 cmpwi 0 (any nonzero = queue 1 @0x3fd3aa count 0x3fd40f tick 0x3fd412; 0 = queue 0 @0x3fd2e2 count 0x3fd40e tick 0x3fd410)
- r4 sth +0 (pgn key), r5 divw /10 -> sth +2 (interval ticks), r6 divw /10 + tick -> sth +4 (next tick), r7 stw +6 (builder); li r3,1 full / li r3,0 done
- same steps and store order as CM550 (+0, +4, +2, +6), same limits 20 / 10, same first call (cm848_j1939_system_init 0x5392a4: r7=0x24178 r3=0 r4=65265 r5=100 r6=70 bl) -> twin confirmed
- no caller reads r3 after the bl (next insn is lis r7)
- precedent: CM848 registerJ1939ReceiveHandler 0x538eb0 rows: pgn_key ushort / handler void*

## CM550 0x35088 cm550_tableLookup2D - prototype (SURE)
- link a6,#0 / movem.l d1-d6/a0-a5 saved: every register but d0 preserved -> result = d0 only
- (0x8,a6) = entry+4 movea.l -> the 22-byte table_lookup_2d_arguments_t record; it writes back +0 x_axis_offset and +8 y_axis_offset (cached segments) -> non-const pointer
- every exit writes only d0.w (move.w (a1),d0 / divu.w quotient / add.w / sub.w); upper word = divu remainder or caller's d0 -> Ghidra's CONCAT22 / CONCAT44 / undefined8 because no return type is declared (68000 cspec guesses d0:d1)
- unsigned: cmp.w + bcs/bcc, mulu.w / divu.w
- result: bilinear z at (x_input, y_input): z[i,j] -> along x to z[i+1,j], row j+1 likewise, then along y; no_interpolation_flag (+20) nonzero -> z[i,j] alone; inputs outside an axis clamp to its end point
- 25 callers (jsr.l), each pushes one long (pea record / move.l aN,-(a7)), d0 used as word: move.w d0,<dest> (most) / andi.l #0xffff,d0 (0x1292a, 0x12c7e: zero-extend -> unsigned)
- counterpart (not twin) of CM848 cm848_dualAxisTableInterpolation 0x566cc (7 register args, signed options, step flag); keep cm550_ name

## CM550 J1708 buffer pointers 0x80dc94-0x80dcaa (e2m block 1126) (SURE)
- format: 256-byte aligned circular buffers (tx 0x808b00, rx 0x808c00); records [length][bytes]; pointers step by addq.b on their LOW byte (wrap inside the 256 bytes)
- init cm550_diagnosticBufferPointerInit 0x1dd2c: TXIP=TXOP=0x808b00, TXMP=TXIP low+1, *TXIP=0, TXFF=0; RXIP=RXOP=0x808c00, RXMP=+1, *RXIP=0, RXFF=0; 0x80ddc6=0x808b00, 0x80ddca=0x808c00, 0x80ddce=0x808cff
- 0x80dc94 JC17TXIP: writer (cm550_diagnosticMessageQueueWrite 0xb6e8 etc): free = TXOP - TXIP (-2 / +0xfe), writes [len][bytes] at TXIP, TXIP = after it, *TXIP = 0 (end marker) -> j1708_transmit_buffer_write_pointer
- 0x80dc98 JC17TXMP: mc68k_startJ1708Transmission 0x16d7c sends *TXMP; ISR 0x1e35e compares the echo of byte 1 with *TXMP (arbitration), states 0/1 addq.b #1,(0x7,a4) then send *TXMP; state 2 sends checksum; bus timer ISR 0x301d4 rewinds TXMP = TXOP +1 -> j1708_transmit_byte_pointer
- 0x80dc9c JC17TXOP: length byte of the message being sent; ISR state 3 (0x1e480) TXOP = TXMP (next record); ISR compares count with *TXOP -> j1708_transmit_buffer_read_pointer
- 0x80dca2 JC17RXIP: length byte of the message being received: ISR (*RXIP)++ per byte (0x1e2ce / 0x1e38c); bus timer ISR 0x300d4 closes it (good checksum: *RXIP--, RXIP = RXMP - 1, *RXIP = 0; <3 bytes or bad: RXMP = RXIP+1); reader loops while RXIP != RXOP (0x16440) -> j1708_receive_buffer_write_pointer
- 0x80dca6 JC17RXMP: ISR stores each byte at *RXMP and steps it (0x1e2c4); full when RXMP == RXOP -> j1708_receive_byte_pointer
- 0x80dcaa JC17RXOP: mc68k_dispatchJ1708ReceivedMessages 0x15fbe reads the record at RXOP, adds len+1 to its low byte 0x80dcad (0x1641a) -> j1708_receive_buffer_read_pointer
- RAM dump: TXIP=TXOP=0x808b7d, TXMP=0x808b7e; RXIP=RXOP=0x808c00, RXMP=0x808c01; 0x80ddc6=0x808b00 0x80ddca=0x808c00 0x80ddce=0x808cff
- 0x80ddc6 (e2m 1127 JC17TXBF), 0x80ddca (1128 JC17RXBF), 0x80ddce: written only by the init; only other reference = the parameter ID table at 0x35cd4.. -> buffer start / end addresses for Calterm

## CM550 0x80d03e io_control_bit0_state -> accumulated_main_engine_position_sensor_period (SURE)
- Calterm 100C +034C ESACGR [TCNT] 'ACCUMULATED MAIN EPS PERIOD BETWEEN VSS INTERRUPTS' (0 - 65535)
- 8 abs refs, all in the TPU channel 10 primary speed handlers (vector 65 0x808f04): Mode0 0x19b20/0x19b2c, Mode1 0x19ee4/0x19ef0, Mode2 0x1a580/0x1a58c, cm550_processPrimarySpeedPulsePeriodWithSyncPulse 0x1aa00/0x1aa0c: moveq #-1,d0; sub.l (sum),d0; cmp.l (period),d0; bcs skip; add.l period,(sum); then 0x80d046 +1 unless 0xffff
- the period = 0x80d04a (copied from TPU channel 10 parameter RAM 0xffffa8 (move.l, then clr.w)); Calterm 100C +0358 ESIPPE 'EPS_PERIOD: TIME BETWEEN THE TWO MOST RECENT EPS INTERRUPTS' (200 - 16777216) -> main_engine_position_sensor_period (was io_control_handshake_state, untyped; move.l at 0x1028a, 0x126be, 0x1a97a, ISRs)
- 0x80d046 Calterm 100C +0354 ESCTGR 'NUMBER OF MAIN EPS INTERRUPTS BETWEEN VSS INTERRUPTS' -> main_engine_position_sensor_interrupt_count (was io_control_bit4_state, word)
- same handlers also add 0x807ec4 into 0x80cd00 (ESCKSM01 'CRANK DEGREES BETWEEN VSS INTERRUPTS') with the same guard
- no reader / reset of 0x80d03e / 0x80d046 / 0x80cd00 anywhere in the dumped ROM (abs refs, immediates, bases 0x80cf00+); no VSS handler in the RAM vector table writes (0x808e4c-0x809008) -> the vehicle speed side is outside the dump (0x40000+)

## CM550 0x801d44-0x801d59 -> one struct (proposal, medium-high)
- accesses (abs refs of every byte 0x801d40-0x801d5b + base registers): 0x801d44 ETC1 data[0] (cm550_receivePgn61442ElectronicTransmissionController1Message 0x2efde movea a1; move.b (a0),(a1)); 0x801d48 ETC1 data[4] (0x2f01a); 0x801d4c TSC1 data[0] (processEngineTsc1Request 0x2f130 a3 base, 0x2f150); (2,a3)=0x801d4e <- data[1], (1,a3)=0x801d4d <- data[2], (3,a3)=0x801d4f <- data[3]; 0x801d54 byte (cmp.b/move.b); 0x801d56 word (move.w); 0x801d58 byte. Nothing at 0x801d45-47, 49-4b, 50-53, 55, 57, 59. 0x801d3c = PGN 58112 handler byte (separate), 0x801d5a = cm550_FUN_0002f4be record (next object)
- layout: ETC1 frame image +0..+7 (data index = offset), TSC1 image +8..+15 (speed bytes swapped big-endian), accepted priority +0x10, pad +0x11, accepted speed word +0x12 (aligned), torque +0x14, pad +0x15 -> 22 bytes; 0x801d44 + 22 = 0x801d5a
- CM848 j1939_powertrain_messages_received_t (0x3fa982, 32 bytes, packed): prev shaft speed, ETC1 image, prev gear ratio, ETC2 image, TSC1 image, accepted priority / speed (odd) / torque -> same members in the same order; CM550 has no ETC2 / previous-speed parts and aligns the accepted speed word
- RAM dump: all 0 (no frames)
- proposal: type cm550_j1939_powertrain_messages_received_t (cm550_ because the layout differs, as cm550_algorithm_enable_flags_<n>_t), global j1939_powertrain_messages_received at 0x801d44; remove the 8 rows inside

## CM848 0x29c98 cm848_calculateFuelDemandFilter -> cm848_calculateMaximumTorqueAtCurrentEngineSpeed (SURE)
- 3 x bl cm848_dualAxisTableInterpolation (0x29ce8 / 0x29d30 / 0x29d78) over maximum_torque_map_x_axis (0x5c556) / _y_axis (0x5c582) / _grid (0x5c58e) at engine_speed_state.filtered_engine_speed (0x40b7ba) and y = 0 / combustion_chi_lower_map_number<<14 (max 0xffff) / chi_upper<<14, caches 0x3faf98 / 0x3faf9c / 0x3fafa0
- bl 0x14528 cm848_interpolateAlphaChiValue (lower, upper, alpha 0 value, chi map numbers, chi_hundredths, alpha_percent); sth r29,0(r31) r31=0x40aee6; 0 -> 1 (sth at 0x29dc8)
- caller: cm848_periodicTaskSet_sensorProcessing 0xb98c
- CM550 counterpart 0x269f2 cm550_calculateMaximumTorqueAtCurrentEngineSpeed: ONE cm550_tableLookup2D (engine_rpm_primary x alpha_blend_factor), min 1 -> counterpart, not twin
## CM848 0x29de0 cm848_initFuelDemandFilterDimensions -> cm848_initializeMaximumTorqueAtCurrentEngineSpeed (SURE)
- sth 1 -> 0x40aee6; sth 2 -> 0x3faf98/9a, 0x3faf9c/9e, 0x3fafa0/a2; blr. Caller cm848_applicationMain 0x544c4 (start-up). CM550 counterpart 0x26a2e cm550_initializeMaximumTorqueAtCurrentEngineSpeed (sets 1 + the record's pointers / offsets 2)

## CM848 0x29ecc uncalled leaf (SURE: dead; name proposed)
- body 0x29ecc-0x29f38 (blr), between cm848_calculateInjectionTimingMainMisfireLimit (blr 0x29ec8) and cm848_absoluteValue16 0x29f3c; no Ghidra function there
- if algorithm_enable_flags_40_cal & 0x100 (Misfire_Timing_Limit_Enable) and injection_timing_intermediate_source_code (0x40a2f2, lha) == 0 (FOUR_DIMENSIONAL_TIMING): main_injection_timing_before_misfire_limit (0x40aeea) = main_injection_timing_copy (0x40a2f0, lha); if injection_timing_main_misfire_limit (0x40aee8, lha) > it (cmpw/ble signed): main_injection_timing_copy = limit, injection_timing_increment_flags (0x40a2f4) bit 0 cleared (rlwinm 16,30), intermediate source = 11 (li r10,11 / sth 0(r4))
- references: none (ppc_refs.py: b/bl/bc in rom + flash2, 32-bit word, lis+addi / lis+ori pairs) - control 0x29e50 found (bl at 0xbab0)
- live misfire limit: cm848_calculateMainInjectionTiming 0x4ae20 raises injection_timing_demand to the limit, source MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT (11)
- value 11 = e2m 103B label 0B MISFIRE; INJECTION_TIMING_INTERMEDIATE_SOURCE has no member 11 (only this dead store writes it - not proposed)

## CM848 safety_* family -> fuel_pressure_governor_fault_* (SURE on roles)
- only user cm848_applyFuelPressureGovernorFaultBlend 0x3889c (+ cm848_initializeFuelPressureGovernorFaultBlend 0x38a98: 0x40b31e=0x40b320=0x1700, 0x40b322=0, cache 0x3fb3c2=2)
- gate lbz 0x4088e4 (safety_fuel_blend_enable) ; faults = fault_detected_cal (0x3fe974) +6 masks 0x200/0x400/0x800/0x1000 (faults 57/58/59/60)
- fault set: sth 1 -> 0x40b326; lookupTableInterpolation(0x3fb3c2, filtered speed 0x40b7ba, axis 0x4088e8, values 0x40891a) -> sth 0x40b324; rising edge (prev 0x3fb3c0 == 0, active != 0) and final_fueling 0x40a2ce > table value -> 0x40b320 = injection_quantity_combustion_chi_maximum 0x40a4ea; if 0x40b320 > table value: 0x40b322 += 0x4088e2, cap 25600
- no fault: sth 0 -> 0x40b326; fraction 0 -> output = chi maximum; else 0x40b322 -= 0x4088e0 (the floor 0 at 0x38a04 is unreachable: clrlwi + cmpwi bge on the zero-extended value)
- output = start x (25600 - fraction) / 25600 + table x fraction / 25600 -> sth 0x40b31e; if < torque_derate_fuel_quantity 0x40afac -> it, source 0x40afae = 62 (FUELING_STATE_FUEL_PRESSURE_GOVERNOR_FAULT_BLEND); prev 0x3fb3c0 = active
- no e2m record for 0x40b31e-0x40b326

## CM848 governor_tuning_set_blend_weight 0x40af7c -> all_speed_governor_tuning_set_blend_weight (SURE)
- every access (ppc_dform.py lis-based loads/stores + decompile): 0xfd34 cm848_calculateAllSpeedGovernorNoLoadFuel, 0xff18 cm848_calculateGovernorCompensatorCoefficients (all-speed governor droop / gains only), 0x2c048 / 0x2c050 cm848_blendAllSpeedGovernorReferenceSpeeds, 0x2c10c cm848_initializeAllSpeedGovernorTuningSetBlendWeight, 0x45fa0 cm848_calculateAllSpeedGovernorEquivalentThrottle -> all five are all-speed governor functions
- CHR e2m block 158D: +0 ASG_Droop_Flag [ASDPFG] 'ASG droop selection flag; used to select droop source' (1/128, 0-2), +2 ASG_Max_RPM, +4 ASG_Min_RPM: +2 / +4 = all_speed_governor_maximum_reference_speed 0x40af7e / all_speed_governor_minimum_reference_speed 0x40af80 -> block base 0x40af7c (not in the dumped parameter ID table)
- RAM dump: 0x40af7c = 128, 0x40af7e = 37200, 0x40af80 = 5920
- family: 0x3fd526 governor_tuning_set_default_blend_weight_cal (e2m 1387 +8 ASG_Droop_Flag_Trim [ASDPFGTN], EEPROM 0xa4; lhz 0x2bfa4 / 0x2c040 / 0x2c108), 0x5a9c4 / 0x5a9d2 by_drivetrain_ratio axis / values (addi 0x2bff8 / 0x2c018) - same two functions only
## misc
- CM848 dump: 0x40a4ea chi maximum = 1030 = 0x40b31e = torque_derate_fuel_quantity 0x40afac, source 0x40afae = 62 -> the fault blend output is the active derate limit even with no fault (fraction 0 -> chi maximum)
- 0x538c8c: 19 bl, all in cm848_j1939_system_init 0x5392c0-0x539500 (CM550: 19 jsr (a4) in mc68k_initializeJ1939Datalink)
- missing CM550 bodies: no ROM data row overlaps them; cause unknown without a Ghidra run

## FINAL struct proposal: cm550_j1939_powertrain_messages_received_t (22 bytes) at 0x801d44
| off | field | type | size | source |
| +0x00 | etc1_status_byte_1 | byte | 1 | ETC1 data[0] (0x2f010 move.b (a0),(a1)) |
| +0x01 | etc1_bytes_2_to_4 | byte | 3 | never written (ETC1 output shaft speed / clutch slip not kept) |
| +0x04 | etc1_status_byte_5 | byte | 1 | ETC1 data[4] (0x2f016 / 0x2f022) |
| +0x05 | etc1_bytes_6_to_8 | byte | 3 | never written |
| +0x08 | tsc1_control_byte | byte | 1 | TSC1 data[0] (0x2f150) |
| +0x09 | tsc1_requested_speed | byte | 2 (byte[2]) | [0] = data[2] (0x2f178 -> (1,a3)), [1] = data[1] (0x2f16e -> (2,a3)); big-endian |
| +0x0b | tsc1_requested_torque | byte | 1 | data[3] (0x2f182 -> (3,a3)) |
| +0x0c | tsc1_bytes_5_to_8 | byte | 4 | never written |
| +0x10 | tsc1_accepted_priority | byte | 1 | 0x2f29e move.b d4 / cmp.b 0x2f1f2 0x2f1fc |
| +0x11 | padding_1 | byte | 1 | alignment of the next word |
| +0x12 | tsc1_accepted_requested_speed | word | 2 | move.w 0x2f22c / 0x2f320 / 0x2f41c |
| +0x14 | tsc1_accepted_requested_torque | byte | 1 | move.b 0x2f212 / 0x2f220 / 0x2f388 / 0x2f42c |
| +0x15 | padding_2 | byte | 1 | even size; 0x801d5a = cm550_FUN_0002f4be's record |
- rows inside to remove: 0x801d48, 0x801d4c, 0x801d4d, 0x801d4f, 0x801d54, 0x801d56, 0x801d58 (0x801d44 becomes the struct row)

## stale text after the renames (for the applier)
- CM550 0x26a2e plate quotes cm848_initFuelDemandFilterDimensions; CM848 rows 0x40aee6, 0x5c556, 0x5c582, 0x5c58e, 0x3faf98, 0x3faf9c, 0x3fafa0 quote cm848_calculateFuelDemandFilter / cm848_initFuelDemandFilterDimensions
- CM848 plates of cm848_applyFuelPressureGovernorFaultBlend / cm848_initializeFuelPressureGovernorFaultBlend and the 0x4088e0.. rows quote safety_* names
- CM848 rows 0x5976e, 0x40af80, 0x3fd526 and the plates of 0x2bf6c / 0x2c100 quote governor_tuning_set_blend_weight
- CM550 0x80d03e comment 'three functions add the 32-bit _io_control_handshake_state' (four handlers)

## leads (not in the brief)
- CM550 0x80d042 (ESACBKGR accumulated backup EPS period) / 0x80d048 (ESCTBKGR backup EPS count): no absolute access in the dump; 0x80d04e (ESIPBKPE) read at 0x102cc and loaded as a base at 0x1b30e (the backup channel handler mc68k_FUN_0001b30a, vector 56)
- optional enum J1939_PERIODIC_TRANSMIT_QUEUE (size 4): 0 ENGINE / 1 RETARDER - queue 1 carries PGN 61440 ERC1 + 65249 retarder configuration (CM550) / 65249 (CM848); gates JCEGBCEA / JCRDBCEA
- STATUS: all batch items done; output assembled from these notes
