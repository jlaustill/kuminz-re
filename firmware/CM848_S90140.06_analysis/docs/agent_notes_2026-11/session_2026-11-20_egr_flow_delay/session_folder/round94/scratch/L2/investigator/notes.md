# L2 investigator notes (round 94)

## 0x1fe84 (no row, FUN_0001fe84) -> scheduleJ1939PeriodicMessage (twin of CM848 0x538c8c)
- asm 0x1fe84-0x1ff36: a3=0x800a9a (queue0 count) a1=0x800a9b (queue1 count); arg (0x10,a7) long queue:
  0 -> cmpi.b #0x14,(a3) full -> return 1; entry = count0++ *10 + 0x80096e; d2 = tick0 0x800a9c
  1 -> cmpi.b #0xa,(a1) full -> return 1; entry = count1++ *10 + 0x800a36; d2 = tick1 0x800a9e
  (other queue numbers fall to the stores with a2 unset - CM848 uses plain else for queue != 0)
  stores: (a2)=pgn word (0x14,a7); (4,a2)= offset(0x18,a7)/10 + tick; (2,a2)= interval(0x16,a7)/10; (6,a2)= builder long (0x1a,a7); clr.b d0 -> 0
- CM848 0x538c8c: cmpwi r3,0; same 20/10 caps, *10 entries at 0x3fd2e2/0x3fd3aa, sth pgn 0, divw offset/10 + tick -> +4, divw interval/10 -> +2, stw builder +6, li r3,0. Same order.
- Caller: mc68k_initializeJ1939Datalink 0x28b8a movea.l #0x1fe84,a4 + 19 x jsr (a4); CM848 cm848_j1939_system_init 19 calls.
  First 2 identical: (0,65265,100,70,0x31c84) / (0,61444,20,0,0x32c76=sendPgn61444...)
- Stack args: +4 queue long, +8 pgn word, +0xa interval_ms word, +0xc offset_ms word, +0xe builder long (5 params).
- CM550 schedule list (19 calls 0x28c5a-0x28e14), (queue, PGN, interval ms, first-send offset ms, builder):
  (0,65265,100,70,0x31c84) (0,61444,20,0,0x32c76) (0,61443,50,10,0x32e4c) (0,65247,250,30,0x330c4) (0,65251,5000,110,0x3366a)
  (1,61440,100,50,0x338ea) (0,65266,100,90,0x33b40) (1,65249,5000,301,0x3407a) (0,65262,1000,430,0x337c4) (0,65252,1000,110,0x33d38)
  (0,65263,500,130,0x33164) (0,65264,100,150,0x33f5a) (0,65269,1000,170,0x31bce) (0,65270,500,190,0x33e58) (0,65271,1000,210,0x342f0)
  (0,65226,1000,500,0x3229a) (0,65213,1000,50,0x339fe) (0,61441,100,20,0x32bbc) (0,65279,10000,40,0x34496)
  CM848 cm848_j1939_system_init: 15 of these with identical (queue,PGN,interval,offset); CM848 differs on 61443 (20 ms) / 65247 (50 ms), has 65241 + 65504, lacks 65266 + 65252.
  VERDICT: twin -> shared name scheduleJ1939PeriodicMessage (both rows). Prototype for function_definitions: queue uint (move.l 0x10), pgn ushort, interval_ms ushort, offset_ms ushort, builder pointer; return byte.

## 0x33d38 (no row) -> cm550_buildPgn65252ShutdownMessage
- Reached only via the scheduler: pea 0x33d38 at 0x28d2e (PGN 65252 every 1000 ms from 110 ms, queue 0). No other ROM reference.
- a0=a1=0x8035f6 (payload set as data_pointer by 0x33dfa). byte 1 by idle_shutdown_state 0x80d674 (jump table 0x33d5a): 0->0x00 1->0x40 2->0x44 3->unchanged 4->0x10 5->0x01 (>5 unchanged)
  = SPN 590 timer state (bits 7-8) / 594 driver alert (3-4) / 592 override (5-6) / 593 has shut down (1-2).
- byte 2: algorithm_enable_flags_3_cal idle_shutdown_enable (0x803c9a & 2) -> 0x7f else 0x3f (SPN 591 timer function enabled / disabled, bits 1-6 = 1s)
- byte 3: 0x80bcd7 bit 0 (e2m 000E +9 DSAKPRSW, software value of the air conditioner pressure switch) -> 0xfd else 0xfc (SPN 985 A/C high pressure fan switch, bits 1-2)
- byte 4: 0x80bcf6 bit 0 (e2m 000E +28 DSLP1 / LCLP01EA lamp 1 driver command) -> 0xfd else 0xfc (SPN 1081 wait to start lamp, bits 1-2)
- then pea 0x8035e8 (j1939_pgn65252_tx_message); jsr 0x104e8 (send). CM848 has no PGN 65252 transmitter (only receivePgn65252ShutdownMessage) -> standalone, cm550_ prefix.

## 0x33dfa vp44_engineHoursPGN_65252_Builder -> cm550_initializePgn65252ShutdownBuffer
- Called once from mc68k_initializeJ1939Datalink (0x28c30, the 15th of the 21 transmit buffer initializers).
- Writes j1939_pgn65252_tx_message 0x8035e8: can_id 0xfee400 with the priority (word 0x803f78 & 7) << 2, data_length 8, data_pointer 0x8035f6, status_pointer 0x8035fe, source address 0x80da01; payload bytes 5-8 (0x8035fa-0x8035fd) = 0xff.
- Nothing about engine hours and nothing about the VP44. Same shape as CM848 cm848_initializePgn65279WaterInFuelIndicatorBuffer etc. -> standalone cm550_.

## DGFUIDEN (e2m block F +0x570, length 38 bytes = 19 words) -> 0x806abc..0x806ae1
- e2m: DGFUIDEN,HEX,F,570,4D,B,37,38 'BIT MAPPED PARAMETER USED TO DISABLE/ENABLE THE PROCESSING OF A (fault)'. Length decimal (DGFUCATB +0x20 len 600 ends at +0x278 = DG0000FU).
- dgfuiden_pairs.py: every direct read of word k (0x806abc+2k) follows a read of the SAME bit of system error status word k (0x806000+2k, SSERSS k): words 0/1/2/4/5/6/7. Indexed reads (movea.l #0x806abc + (fault>>4)*2, bit fault&15) pair with 0x806000 indexed the same way (0xb8b8 A/D channel faults, 0x10726, fault scan 0x14900).
- Rows: 0x806abc fault_confirm_status_word_0 / 0x806abe _word_1 / 0x806ac0 fault_latch_status_word_2 / 0x806ac2 fault_latch_status_word_3 / 0x806ac4 fault_confirm_status_word_4 / 0x806aca fault_first_occurrence_word_7; words 5 (0x806ac6) and 6 (0x806ac8) render _DAT_.
- Not in the EEPROM image (0x803b0a-0x804f93) -> no _cal. Not in the dumped ROM either (block F is not found in rom.bin).
- RAM dump: fc00 2600 d007 006b 2b3f f800 b7ee 0200 ea00 0299 0040 0000 0000 0000 0000 0000 f800 f7bf 0efb

## ETC1 bytes 0x801d44 / 0x801d48 (rows tsc1_message_byte_0 / tsc1_message_control_byte)
- 0x2efd0 is registered at 0x2f114: registerJ1939ReceiveHandler(0xf002 = PGN 61442 ETC1, 0x2efd0). (0x2efd0's row is cm550_diagnosticServiceDispatcherByPgn - wrong, not in this batch)
- 0x2efd0: accept source == word ROM 0x60f82 (_j1939_transmission_source_address) or 0xff; length 8; move.b (data),(0x801d44) = ETC1 byte 1; move.b 4(data) -> 0x801d48 = ETC1 byte 5.
  byte 5 & 3 == 1 -> high idle override (SPN 606 momentary overspeed enable), & 0xc == 4 -> progressive shift disable (SPN 607); byte 1 & 0x30 == 0 and & 3 == 0 -> driveline disengaged (out of gear).
- Only reference of each: the movea.l in 0x2efd0 (abs_refs). Byte accesses only.
- CM848 twin fields: j1939_powertrain_messages_received.etc1_status_byte_1 (+2) / etc1_status_byte_5 (+6) in cm848_j1939ProcessPgn61442Etc1 (4 bytes apart in both).
- Proposed: j1939_received_etc1_status_byte_1 / j1939_received_etc1_status_byte_5 (byte).
- Bonus (same layout family, processEngineTsc1Request 0x2f128): 0x801d4c TSC1 byte 1 (row torque_control_message_byte_0), 0x801d4d/0x801d4e requested speed (data[2] high / data[1] low; read CONCAT11(4d,4e)), 0x801d4f TSC1 byte 4 requested torque (row torque_control_percent_byte), 0x801d54 accepted priority (byte1 & 0x30), 0x801d56 accepted requested speed (word), 0x801d58 accepted requested torque (byte). = CM848 tsc1_control_byte / tsc1_requested_speed / tsc1_requested_torque / tsc1_accepted_priority / tsc1_accepted_requested_speed / tsc1_accepted_requested_torque.

## 2D lookups (records named in round 94 stage C)
- 0x269f2 (called last in cm550_runEvery4FramesTaskSetPhase0, 20 ms): maximum_torque_map_lookup x_input (+6) = engine_rpm_primary 0x80ccf6, y_input (+0xe) = alpha_blend_factor 0x80a8f8; jsr 0x35088 cm550_tableLookup2D; result -> 0x80db1a (e2m 1461 +0 MTMPRPFL 'MAX TORQUE AT CURRENT RPM IN FOOT-POUNDS'); if < 1 -> 1.
  CM848 counterpart 0x29c98 cm848_calculateFuelDemandFilter (3 lookups alpha 0 / chi lower / chi upper + cm848_interpolateAlphaChiValue, result fuel_demand_filter_dimension 0x40aee6, 0 -> 1). Counterpart, not twin.
  -> cm550_calculateMaximumTorqueAtCurrentEngineSpeed
- 0x26a2e (start-up init chain, step 0x8970): 0x80db1a = 1; record +2 x_axis_pointer 0x808346, +0 x offset 2, +0xa y pointer 0x808372, +8 y offset 2, +0x10 z pointer 0x80837c.
  CM848 counterpart 0x29de0 cm848_initFuelDemandFilterDimensions (dimension = 1, three caches = 2).
  -> cm550_initializeMaximumTorqueAtCurrentEngineSpeed
- 0x26a7e cm550_fuelDemandTablePointersInit (start-up init chain step 0x8918): injection_timing_misfire_limit_lookup +8 y offset 2, +0xa y pointer 0x807944, +0 x offset 2, +2 x pointer 0x80793a, +0x10 grid 0x80794e; clr.w 0x80a270 (818E +2 BSTABELM) then clr.w 0x80a26e (818E +0 BSTAMNLM).
  CM848 counterpart 0x29e24 cm848_initProtectionFilterAccumulators: cache[1]=2, cache[0]=2, clear 0x40aeea (8A3D +2 SOI_Before_MST, row injection_timing_pid_init_flag) then 0x40aee8 (8A3D +0 Misfire_Timing_Limit). Same order but CM550 also stores 3 pointers -> counterpart.
  -> cm550_initializeInjectionTimingMisfireLimit
- 0x26ab8 cm550_rpmLoadParameterLookup (cm550_runEvery4FramesTaskSetPhase2, 6th call): while 0x803cd4 & 1 (algorithm_enable_flags_32_cal.misfire_timing_limit_enable): x = 0x80a320 (1004 +76 BSTPRS boost pressure), y = engine_rpm_primary; cm550_tableLookup2D -> 0x80a26e BSTAMNLM. Read by cm550_applyMisfireTimingLimit.
  CM848 counterpart 0x29e50 cm848_calculateInjectionTimingMainMisfireLimit (same enable bit role, boost x filtered speed, direct interpolation call with args).
  -> cm550_calculateInjectionTimingMisfireLimit
- globals: 0x80db1a max_torque_at_current_rpm_in_foot_pounds_0_10000 -> maximum_torque_at_current_engine_speed (MTMPRPFL); 0x80a26e output_of_the_misfire_timing_limit_table_60_to_60 -> injection_timing_misfire_limit (BSTAMNLM; CM848 injection_timing_main_misfire_limit)
- CM848 leads (not this batch): 0x29c98 / 0x29de0 / 0x29e24 names, 0x40aee6 fuel_demand_filter_dimension (= max torque at current speed), 0x40aeea injection_timing_pid_init_flag (= SOI_Before_MST).

## Extra checks
- 0x33d38 has a second reference: pea 0x33d38 / move.w #0xfee4 / jsr (a2=0x2f47e) at 0x2f586 in 0x2f538 (cm550_diagnosticDataDump): the PGN 59904 request responder for PGN 65252. 0x2f538 = CM848 cm848_initJ1939ProtocolHandlers counterpart (CM550 list 65252/65261/65263/65264/65269/65270/65271; CM848 65261/65263/65264/65269/65270/65271/65504). 0x2f47e (no row) = cm848_j1939RegisterPgnHandler counterpart (32 entries x 6 bytes at 0x801d5a, count 0x801e1a).
- pc_relative_calls.py: no bsr / (d16,pc) reference to 0x1fe84 / 0x33d38 / 0x33dfa / 0x269f2 / 0x26a2e / 0x26a7e / 0x26ab8.
- 0x80bcd7 bit 0 (e2m 000E +9 DSAKPRSW): written by mc68k_sampleAndDebounceDiscreteInputs from debounced byte 0x80bcd0 bit 1, read only by 0x33d38 (PGN 65252 byte 3, SPN 985).
- 0x80bcf6 bit 0 = LCWTSRLP / LCLP01EA / DSLP1 (wait to start lamp driver command) -> PGN 65252 byte 4 SPN 1081.
- 0x803f78 = e2m 1254 +2A JCISSHPZ 'DEFAULT NETWORK PRIORITY FOR IDLE SHUTDOWN MESSAGE' (EEPROM image) -> j1939_pgn65252_priority_cal; one reader 0x33e10 (& 7 << 2 into the can_id top byte). CM848 has the record at 1254 +28 (0x3fd862, no row, no reader).
- 0x803f76 = JCISPZ (idle operation message priority) read by 0x33ce2 vp44_ioControlPGN_65244_Builder (PGN 65244 Idle Operation descriptor) - lead.
- DGFUIDEN base-register readers (0xc682 a5 (2,a5) / 0x16dd8 / 0x30a5e / 0x32e56 a4 = +8 / 0x1f0ee / 0x2580e / 0xc184): all reads paired with 0x806000 + same offset; no write anywhere in the dumped ROM.

## Leads for later rounds (not this batch)
- misnamed scheduled builders (from the schedule list): 0x31c84 j1939HandlePgn65265CruiseVehicleSpeed (65265 CCVS1 builder), 0x32e4c j1939HandlePgn61443Eec2 (61443 builder), 0x330c4 vp44_configParamCanBuilder (65247), 0x33164 vp44_FUN_00033164 (65263), 0x3366a cm550_FUN_0003366a (65251), 0x337c4 cm550_FUN_000337c4 (65262), 0x338ea cm550_dutyCycleMonitorAltIsrHandler (61440 ERC1 on queue 1), 0x33b40 cm550_fuelEconomyDataBuilder (65266), 0x33e58 cm550_FUN_00033e58 (65270), 0x33f5a cm550_FUN_00033f5a (65264), 0x3407a vp44CanMessage100ResponseBuilder (65249 queue 1), 0x342f0 cm550_retarderDataBuilder (65271), 0x31bce cm550_FUN_00031bce (65269); no rows: 0x3229a (65226 DM1), 0x339fe (65213), 0x32bbc (61441), 0x34496 (65279).
- 0x2efd0 cm550_diagnosticServiceDispatcherByPgn = the ETC1 (PGN 61442) receive handler (counterpart of cm848_j1939ProcessPgn61442Etc1); 0x2f114 cm550_systemControlFunction3 registers it (0xf002).
- 0x2ef08 cm550_systemControlFunction1 registers PGN 61184 (0xef00 -> 0x2eea2); 0x2efbc cm550_systemControlFunction2 registers PGN 58112 DM7 (0xe300 -> 0x2ef4a).
- system error status words 0x806000.. (SSERSS00-31) are indexed by fault >> 4 exactly like DGFUIDEN: a word[32] array candidate; fault_first_occurrence_flags_word_N at 0x806040.. likewise.
- CM848: 0x29c98 cm848_calculateFuelDemandFilter (computes the maximum torque at the current engine speed into fuel_demand_filter_dimension 0x40aee6), 0x29de0 cm848_initFuelDemandFilterDimensions, 0x29e24 cm848_initProtectionFilterAccumulators (initializes the misfire limit; clears 0x40aeea = e2m 8A3D +2 SOI_Before_MST, row injection_timing_pid_init_flag).

## Final decisions (written before StructuredOutput)
- functions: 0x1fe84 scheduleJ1939PeriodicMessage (twin, CM848 0x538c8c renamed too) / 0x33d38 cm550_buildPgn65252ShutdownMessage / 0x33dfa cm550_initializePgn65252ShutdownBuffer / 0x269f2 cm550_calculateMaximumTorqueAtCurrentEngineSpeed / 0x26a2e cm550_initializeMaximumTorqueAtCurrentEngineSpeed / 0x26a7e cm550_initializeInjectionTimingMisfireLimit / 0x26ab8 cm550_calculateInjectionTimingMisfireLimit
- globals: 0x801d44 j1939_received_etc1_status_byte_1 / 0x801d48 j1939_received_etc1_status_byte_5 / 0x801d4c j1939_received_tsc1_control_byte / 0x801d4d j1939_received_tsc1_requested_speed byte[2] / 0x801d4f j1939_received_tsc1_requested_torque / 0x801d54 tsc1_accepted_priority / 0x801d56 tsc1_accepted_requested_speed word / 0x801d58 tsc1_accepted_requested_torque / 0x806abc fault_processing_enable_flags word[19] (remove the 5 rows inside) / 0x80db1a maximum_torque_at_current_engine_speed / 0x80a26e injection_timing_misfire_limit / 0x803f78 j1939_pgn65252_priority_cal / 0x80bcd7 air_conditioner_pressure_switch_state (medium)
- DGFUIDEN direct reads: 27 (word 0: 8, 1: 4, 2: 5, 4: 4, 5: 2, 6: 1, 7: 3), all paired with the same bit of 0x806000 + 2k.
