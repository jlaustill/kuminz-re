# L2 describer notes (round 94)

## 0x1fe84 (no row; renders FUN_0001fe84) - SURE
- Separate function: cm550_canMessageFilterInit ends with rts at 0x1fe82; 0x1fe84 starts movem.l a3/a2/d2.
- Args (stack, after movem 12 + ret 4): 0x10 long queue (0 / 1), 0x14 word PGN key, 0x16 word interval ms,
  0x18 word first-send offset ms, 0x1a long builder address.
- queue 0: count byte 0x800a9a (full at 20 -> return 1), entries 0x80096e + count*10, tick 0x800a9c.
  queue 1: count byte 0x800a9b (full at 10 -> return 1), entries 0x800a36 + count*10, tick 0x800a9e.
  (any other queue value falls to the stores with a2 unset - switch on 0/1 only)
- Stores in order: +0 = PGN key, +4 = offset/10 + current tick, +2 = interval/10, +6 = builder; returns 0.
- mc68k_initializeJ1939Datalink: movea.l #0x1fe84,a4 (0x28b8a, operand 0x28b8c) then 19 jsr (a4).
- CM848 cm848_scheduleJ1939PeriodicMessage 0x538c8c: identical steps / order (+0,+4,+2,+6) / constants (20,10,/10)
  / return 1 full 0 ok; called from cm848_j1939_system_init with the same list (65265 100/70, 61444 20/0, ...).
  -> TWIN. Shared unprefixed name scheduleJ1939PeriodicMessage (no such name in either CSV).
- The 19 CM550 registrations (queue, PGN, interval ms, offset ms, builder):
  0 65265 100 70 0x31c84 | 0 61444 20 0 0x32c76 | 0 61443 50 10 0x32e4c | 0 65247 250 30 0x330c4 |
  0 65251 5000 110 0x3366a | 1 61440 100 50 0x338ea | 0 65266 100 90 0x33b40 | 1 65249 5000 301 0x3407a |
  0 65262 1000 430 0x337c4 | 0 65252 1000 110 0x33d38 | 0 65263 500 130 0x33164 | 0 65264 100 150 0x33f5a |
  0 65269 1000 170 0x31bce | 0 65270 500 190 0x33e58 | 0 65271 1000 210 0x342f0 | 0 65226 1000 500 0x3229a |
  0 65213 1000 50 0x339fe | 0 61441 100 20 0x32bbc | 0 65279 10000 40 0x34496

## 0x33d38 (no row; inside the 0x33ce2 row's span) - SURE
- Separate function: 0x33ce2 ends rts at 0x33d36. Reached twice: (1) schedule entry queue 0 PGN 65252 (0xfee4)
  every 1000 ms from 110 ms (pea 0x33d38 at 0x28d2e in mc68k_initializeJ1939Datalink), (2) the PGN request responder
  table: 0x2f538 (cm550_diagnosticDataDump) calls 0x2f47e(0xfee4, 0x33d38) (0x2f47e adds a 6-byte {PGN word, handler}
  entry to 0x801d5a, max 32, count 0x801e1a; 0x2f4be = PGN 59904 request handler registered at 0x2f540 walks it).
- Fills the payload 0x8035f6 (data of j1939_pgn65252_tx_message) then cm550_sendCanMessage(0x8035e8):
  byte 1 = idle_shutdown_state (0x80d674) via jump table 0x33d5a: 0->0x00 1->0x40 2->0x44 3->unchanged 4->0x10 5->0x01
       (>5 unchanged) = SPN 593 / 594 / 592 / 590 two-bit fields.
  byte 2 = 0x7f if algorithm_enable_flags_3_cal.idle_shutdown_enable (0x803c9a & 2) else 0x3f (SPN 591 bits 7-8 01/00).
  byte 3 = 0xfd if 0x80bcd7 bit 0 (e2m 000E +9 DSAKPRSW 'software value of air conditioner pressure switch') else 0xfc
       (SPN 985 A/C high pressure fan switch).
  byte 4 = 0xfd if 0x80bcf6 bit 0 (e2m 000E +28 LCLP01EA 'command to enable the lamp 1 driver (bit 0)') else 0xfc
       (SPN 1081 engine wait to start lamp position).
  bytes 5-8 are not written here (0x33dfa sets them to 0xff).
- CM848 does not transmit PGN 65252 (only registerJ1939ReceiveHandler(0xfee4, receivePgn65252ShutdownMessage)) -> none.
- name: cm550_buildPgn65252ShutdownMessage (CM848 pattern cm848_buildPgn<N><Name>Message = fill payload + send).

## 0x33dfa vp44_engineHoursPGN_65252_Builder - SURE (name wrong)
- Called once, from mc68k_initializeJ1939Datalink (jsr at 0x28c30) among the transmit buffer initializers.
- Writes j1939_pgn65252_tx_message (0x8035e8): can_id 0x00fee400, priority bits = (word 0x803f78 & 7) << 2 in byte 0
  (0x803f78 = e2m 1254 +2A JCISSHPZ 'default network priority for idle shutdown message'), data_length 8,
  data_pointer 0x8035f6, status_pointer 0x8035fe, byte 3 = j1939_engine_node_source_address (0x80da01);
  payload bytes 5-8 (0x8035fa-0x8035fd) = 0xff. No engine hours, no VP44. PGN 65252 is SHUTDN (engine hours is 65253).
- CM848 none (CM848 does not send PGN 65252).
- name: cm550_initializePgn65252ShutdownBuffer (pattern initializePgn65251EngineConfiguration1Buffer / cm848_initializePgn<N>...Buffer).

## 0x2efd0 cm550_diagnosticServiceDispatcherByPgn (extra; stores 0x801d44 / 0x801d48) - SURE
- Registered by 0x2f114 (cm550_systemControlFunction3): registerJ1939ReceiveHandler(0xf002 = PGN 61442 ETC1, 0x2efd0).
- Accepts only frames from _j1939_transmission_source_address (ROM 0x60f82; 0xff = any) with data_length 8.
- 0x801d44 <- data[0] (ETC1 byte 1); 0x801d48 <- data[4] (ETC1 byte 5).
- byte 5 bits 1-2 = 1 (SPN 606 engine momentary overspeed enable) with tsc1_override_control_mode 1 and
  engine_control_device_indicator 1 -> high_idle_override_active_flag (JCHII1OD) + timer JCEGOSTM+1; not 1/3 -> clear;
  recovery flag set -> timer = JCTMRCTM+1. byte 5 bits 3-4 = 1 (SPN 607) -> progressive_shift_disable_flag (JCPSDB) +
  timer JCPSTM+1; not 3 -> clear. byte 1 bits 5-6 = 0 and bits 1-2 = 0 (not shifting, driveline disengaged) ->
  driveline_disengaged_flag (JCOG) + timer JCDRDITM+1 + out_of_gear_network_type (JCOGNETY) = 1 (J1939); else clear.
- CM848 counterpart cm848_j1939ProcessPgn61442Etc1 (0x22870): same three ETC1 decodes plus torque converter lockup,
  shift in process, output shaft speed, message timeout and the time limit timer -> counterpart, not twin.
- name: cm550_receivePgn61442ElectronicTransmissionController1Message (pattern receivePgn<N><Name>Message).

## 0x801d44 / 0x801d48 (tsc1_message_byte_0 / tsc1_message_control_byte) - SURE
- Only access: 0x2efd0 (movea.l #0x801d44,a1 at 0x2efde; movea.l #0x801d48,a0 at 0x2f01a). Not TSC1 (TSC1 is 0x801d4c+,
  processEngineTsc1Request 0x2f128).
- 0x801d44 = ETC1 byte 1 (SPN 560 driveline engaged bits 1-2, SPN 573 lockup bits 3-4, SPN 574 shift in process bits 5-6);
  CM848 j1939_powertrain_messages_received.etc1_status_byte_1.
- 0x801d48 = ETC1 byte 5 (SPN 606 bits 1-2, SPN 607 bits 3-4); CM848 ...etc1_status_byte_5.
- Spacing +4 = the frame offsets (byte 1 at +0, byte 5 at +4): an 8-byte ETC1 image 0x801d44-0x801d4b (only 2 stored).
- names: j1939_pgn61442_received_byte_1 / j1939_pgn61442_received_byte_5 (byte types).

## DGFUIDEN record (0x806abc-0x806ae1; rows 0x806abc / abe / ac0 / ac2 / ac4 / aca) - SURE
- e2m v64t6_s: DGFUIDEN,HEX,F,570,4D,B,37,38 'BIT MAPPED PARAMETER USED TO DISABLE/ENABLE THE PROCESSING OF A (particular fault)'.
  Block F = RAM 0x80654c (parameter ID table: 'DG00ELTM / FLT_DATA'), +0x570 = 0x806abc. Length 38 decimal bytes =
  19 words: it ends at 0x806ae2 = block 1003 (intake_manifold_temperature_sensor_config) - proves decimal. Last record
  of block F. Same record in all 40+ family e2m (length 38); CM848 e2m: Log_Fault_Indicator [DGFUIDEN] 100 bytes at a
  virtual address (e2m_variables 0x01002600) -> no CM848 RAM row found; CM848 sensor channels do not use such a mask.
- Every access in the dumped ROM is a READ (script dgfuiden_uses.py): absolute move.w of words 0/1/2/4/5/6/7,
  base loads (a0/a2/a3/a4/a5) with (0x2/0x4/0x6/0x8/0xc,aN) = words 1/2/3/4/6, and the indexed form
  movea.l #0x806abc,a0; move.w (0,a0,d0.w*2) with d0 = fault number >> 4 (cm550_processFaultScanGroup,
  analog channel code, vp44 derate code). No writer in the dump (contents not in the ROM or the EEPROM dump).
- Pattern everywhere: (status word n of 0x806000 SSERSSnn & bit) AND (DGFUIDEN word n & the same bit) -> the fault counts
  as active; cm550_processFaultScanGroup (0x14900) logs a fault only when its DGFUIDEN bit is set; 0x115b2 sets status
  word 0 bit 12 only while DGFUIDEN word 0 bit 12 is set. Same word / bit indexing as the 32 status words -> a per-fault
  enable bitmap (304 bits), not confirm / latch / first occurrence bits.
- Dump words: fc00 2600 d007 006b 2b3f f800 b7ee 0200 ea00 0299 0040 0 0 0 0 0 f800 f7bf 0efb.
- Rows now: 0x806abc fault_confirm_status_word_0 / 0x806abe fault_confirm_status_word_1 / 0x806ac0 fault_latch_status_word_2 /
  0x806ac2 fault_latch_status_word_3 / 0x806ac4 fault_confirm_status_word_4 (all undefined) / 0x806aca
  fault_first_occurrence_word_7 (word). Words 5 (0x806ac6) and 6 (0x806ac8) have readers but no rows.
- proposal: one row 0x806abc fault_processing_enable_flags word[19] (not _cal: outside the EEPROM mirror); drop the
  other five rows (they are elements 1 / 2 / 3 / 4 / 7).

## 2D lookup functions (0x269f2 / 0x26a2e / 0x26a7e / 0x26ab8) - SURE
- 0x269f2 cm550_FUN_000269f2: x_input = engine_rpm_primary (0x80ccf6, ENGRPM), y_input = alpha_blend_factor (0x80a8f8,
  ALPHA 0 urban - 1 open road) into maximum_torque_map_lookup (0x801a94), cm550_tableLookup2D -> 0x80db1a
  max_torque_at_current_rpm_in_foot_pounds_0_10000 (e2m 1461 MTMPRPFL 'max torque at current rpm in foot-pounds'),
  then floors it at 1 (cmpi #1 / bcc). No gate. Last call of cm550_runEvery4FramesTaskSetPhase0 (jsr 0x1b56a, 20 ms).
  Reader of the result: cm550_FUN_0001c0d4 (torque derate limit -> fuel quantity, divides by it; also floors at 1).
  CM848 counterpart cm848_calculateFuelDemandFilter 0x29c98 (misnamed): the same MT_Max_Torque_Map at
  filtered_engine_speed into fuel_demand_filter_dimension (= MTMPRPFL), floored at 1, but three lookups (alpha 0 row,
  chi lower / upper rows) blended by cm848_interpolateAlphaChiValue -> counterpart.
  name: cm550_calculateMaximumTorqueAtCurrentEngineSpeed.
- 0x26a2e cm550_FUN_00026a2e: max_torque_at_current_rpm = 1; maximum_torque_map_lookup x_axis_pointer 0x808346
  (MTTQMPXA) offset 2, y_axis_pointer 0x808372 (MTTQMPYA) offset 2, z_values_pointer 0x80837c (MTTQMPZA). Called once
  by mc68k_applicationMain (jsr 0x2896a). CM848 counterpart cm848_initFuelDemandFilterDimensions 0x29de0 (result = 1,
  three cache pairs = 2). name: cm550_initializeMaximumTorqueAtCurrentEngineSpeed.
- 0x26a7e cm550_fuelDemandTablePointersInit: injection_timing_misfire_limit_lookup (0x801aaa) y offset 2 / y axis
  0x807944 (BSTAESYA) / x offset 2 / x axis 0x80793a (BSTABSXA) / z 0x80794e (BSTATBZA); clears 0x80a270
  injection_timing_before_misfire_limit (BSTABELM) and 0x80a26e the misfire timing limit (BSTAMNLM). Called once by
  mc68k_applicationMain (jsr 0x28912). No fuel demand. CM848 counterpart cm848_initProtectionFilterAccumulators 0x29e24
  (misnamed: misfire cache = 2, injection_timing_pid_init_flag = 0, injection_timing_main_misfire_limit = 0).
  name: cm550_initializeInjectionTimingMisfireLimit.
- 0x26ab8 cm550_rpmLoadParameterLookup: only while algorithm_enable_flags_32_cal.misfire_timing_limit_enable (0x803cd4
  bit 0, BSTALMEN): x_input = boost_pressure_sensor_state.filtered_value (0x80a320, BSTPRS), y_input =
  engine_rpm_primary, cm550_tableLookup2D(injection_timing_misfire_limit_lookup) -> 0x80a26e BSTAMNLM; returns it (0 when
  disabled, the stored limit is then left as is). Called by cm550_runEvery4FramesTaskSetPhase2 (jsr 0x1b5ec, 6th call).
  Consumer: cm550_applyMisfireTimingLimit (raises fuel_timing_advance_value to it). CM848 counterpart
  cm848_calculateInjectionTimingMainMisfireLimit 0x29e50: same gate (algorithm_enable_flags_40_cal.misfire_timing_limit_enable),
  same table record (Misfire_Timing_Table, boost x engine speed), but boost from cm848_calculateBoostPressure (MAP minus
  baro) and the argument / cache lookup library; void. Close to a twin, but the boost input computation differs.
  name: cm550_calculateInjectionTimingMisfireLimit.
- 0x26a64 cm550_memcpy sits between 0x26a2e and 0x26a7e (byte copy loop) - not in the batch.

## Cross-checks done
- RAM dump queues: queue 0 count 17, queue 1 count 2 (= the 19 calls); entry 7 of queue 0 = PGN 65252, 100 ticks,
  builder 0x33d38. Queue 1 = 61440 ERC1 + 65249 retarder configuration (the retarder node).
- 0x1fe84 difference vs CM848: CM550 tests queue == 0 / == 1 (any other value stores through an unset a2 / d2);
  CM848 sends every non-zero queue to queue 1. Only difference. Callers: the CM848 list in cm848_j1939_system_init
  (0x539190) has the same PGN / interval / offset values for 15 shared entries.
- Prototype for the new row (stack_parameter_layout 2-byte slots): queue dword @4, pgn word @8, interval ms word @0xa,
  first send offset ms word @0xc, builder pointer @0xe; returns 1 (queue full) / 0.
- 0x80bcf6 bit 0 = the wait to start lamp output: cm550_iahDisableWaitToStartLamp (0x24812) clears it (andi.b #0xfe).
- 0x80bcd7 (DSAKPRSW) is read only by 0x33d38 (rendered inside vp44_ioControlPGN_65244_Builder in the .cpp).
- TSC1 image: processEngineTsc1Request (0x2f128) stores TSC1 byte 1 at 0x801d4c, bytes 2-3 at 0x801d4e / 0x801d4d
  (swapped -> word 0x801d4d = requested speed), byte 4 at 0x801d4f. So 0x801d44-0x801d4b = ETC1, 0x801d4c+ = TSC1.
- Aside (not this batch): 0x33ce2 vp44_ioControlPGN_65244_Builder initializes the PGN 65244 Idle Operation descriptor
  (priority JCISPZ 0x803f76) and registers 0x33c6c as the PGN 65244 request responder (0x2f47e); 0x33c6c sends idle fuel
  (bytes 1-4) and idle hours (bytes 5-8: the row 0x8035e2 protection_state_enable_flags is that payload dword). 0x2f47e =
  add a PGN request responder (table 0x801d5a, 32 entries, count 0x801e1a); 0x2f4be = the PGN 59904 request handler.
- 0x2f538 cm550_diagnosticDataDump registers 0x2f4be for PGN 59904 and the responders 65252 / 65261 / 65263 / 65264 /
  65269 / 65270 / 65271 (name wrong; not this batch).

## DGFUIDEN word pairing re-checked (status word n of 0x806000 AND enable word n, same mask)
- word 1: 0x806002 & 0x400 / 0x200 with 0x806abe (0xe9ce); 0x806002 & 0x4 / 0x8 with (0x2,a5) (0xc6a2).
- word 2: 0x806004 & 0x2 with (a2) = 0x806ac0 (0xc1e2). word 3: 0x806006 & 0x4/0x8/0x20/0x40 with (0x6,a2) (0x16ef6).
- word 5: 0x80600a & 0x200 / 0x400 with 0x806ac6 (0x1e5a2, 0x237c8). word 6: 0x806ac8 & 0x400 (0x10b4e);
  0x80600c & 0x2000 with (0xc,a2) (0x16f7c). word 7: 0x80600e & 0x4 / 0x2 with 0x806aca (0x1e490, 0x264a0).
- The fault scanner (cm550_faultFlagScannerAndProcessor 0x14dc6) walks status words 0-31; cm550_processFaultScanGroup
  maps word*16+bit through 0x80656c (< 125) before it reads the enable word, so only words 0-18 matter.

## Final proposals (describer)
- 0x1fe84 scheduleJ1939PeriodicMessage (twin; CM848 0x538c8c cm848_scheduleJ1939PeriodicMessage -> same shared name)
- 0x33d38 cm550_buildPgn65252ShutdownMessage (none)
- 0x33dfa cm550_initializePgn65252ShutdownBuffer (none)
- 0x2efd0 cm550_receivePgn61442ElectronicTransmissionController1Message (counterpart cm848_j1939ProcessPgn61442Etc1 0x22870)
- 0x269f2 cm550_calculateMaximumTorqueAtCurrentEngineSpeed (counterpart cm848_calculateFuelDemandFilter 0x29c98)
- 0x26a2e cm550_initializeMaximumTorqueAtCurrentEngineSpeed (counterpart cm848_initFuelDemandFilterDimensions 0x29de0)
- 0x26a7e cm550_initializeInjectionTimingMisfireLimit (counterpart cm848_initProtectionFilterAccumulators 0x29e24)
- 0x26ab8 cm550_calculateInjectionTimingMisfireLimit (counterpart cm848_calculateInjectionTimingMainMisfireLimit 0x29e50)
- 0x801d44 j1939_received_pgn61442_byte_1 / 0x801d48 j1939_received_pgn61442_byte_5 (byte)
- 0x806abc fault_processing_enable_flags word[19] (absorbs 0x806abe / ac0 / ac2 / ac4 / aca)
