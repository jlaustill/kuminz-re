# R6 investigator notes (round 97)

Batch: CM550's J1939 set-ups, senders and the PGN 61184 request chain.

## Findings (one entry each, with evidence)

### 0x32244 (cm550_diagnosticDM11PGN_65234_Builder) -> initializePgn65234Dm10Handler, TWIN of CM848 0x24b64
- CM550 asm 0x32244-0x32298: can_id 0xfed200 @0x3224a, prio word 0x803f60 (JCDG10PZ) &7 <<2 into byte 0 (andi.b #0xe3/or.b), len 2 @0x32268, data 0x801f4c @0x3226e, status 0x801f54 @0x32276, SA byte 0x80da01 -> +3 @0x3227e, registerJ1939PgnRequestHandler(0xfed2, 0x32222 buildPgn65234Dm10TestIdentifiersSupportMessage) @0x32290.
- CM848 0x24b64-0x24be4: same 7 steps same order (stw 0xfed200, rlwimi prio 0x3fd84c, sth 2 +4, stw +6, stw +10, stb SA +3, bl 0x23188 with 0xfed2 / 0x24b28 = the same shared builder).
- Both are the LAST call of the PGN request registrar (cm550_registerJ1939PgnRequestHandlers 0x2f5fc / cm848_registerJ1939PgnRequestHandlers), after the DM5 set-up.
- Global 0x803f60 j1939_pgn65234_priority_cal (word, e2m 1254 +12 JCDG10PZ, RAM 6, read once @0x32254).

### 0x323be (cm550_engineCoolantPGN_65226_Builder) -> cm550_initializePgn65226Dm1Handler, COUNTERPART of CM848 0x24dd8 cm848_initPgn65226Dm1Handler
- CM550 asm: can_id 0xfeca00 @0x323ca, prio 0x803f56 (JCDG01PZ), data 0x801f64 (+6), status 0x80265a (+10), SA +3, payload[1]=0xff @0x323fc (flash lamp byte), bset #7 payload[5] @0x32402, register(0xfeca, 0x322ae).
- CM848 does the same plus clears j1939_dm1_broadcast_pending_flag (stb 0 -> 0x3fabcb @0x24e50) before registering; its handler 0x24be8 is a counterpart (round 96). So counterpart.
- Callers: mc68k_initializeJ1939Datalink 0x28c4e (after the PGN 65279 set-up) and cm550_registerJ1939PgnRequestHandlers 0x2f5de (CM848 also calls its set-up twice: cm848_j1939_system_init and cm848_registerJ1939PgnRequestHandlers).
- No data length: the DM1 sender sets it.
- Global 0x803f56 j1939_pgn65226_priority_cal.

### 0x33064 (vp44_cumminsProprietaryDM_983_Builder) -> initializePgn61443ElectronicEngineController2Handler, TWIN of CM848 0x25d60 cm848_initPgn61443Eec2Handler
- CM550 asm 0x33064-0x330be: can_id 0xf00300, prio 0x803f64 (JCEG02PZ), SA +3, len 5, data 0x8034aa, status 0x8034c0, jsr 0xf99a (emptyPgn61443ElectronicEngineController2InitializationStep), register(0xf003, 0x32e4c).
- CM848 0x25d60-0x25de4: stw 0xf00300, rlwimi prio 0x3fd850, stb SA +3, sth 5, stw +6, stw +10, bl 0x20aec (the same shared empty step), bl 0x23188(0xf003, 0x25b10).
- Same order (SA before length in BOTH, unlike the other set-ups), same constants, the fifth descriptor set-up of both initializers (mc68k_initializeJ1939Datalink 0x28bf4 / cm848_j1939_system_init after the EEC1 set-up).
- Handlers registered are each firmware's EEC2 builder (counterparts) - like registerJ1939DiagnosticHandlers (a twin that registers counterpart handlers).
- Global 0x803f64 j1939_pgn61443_priority_cal (RAM 3).

### 0x33aea (cm550_retarderConfigPGN_65249_Builder) -> cm550_initializePgn65257FuelConsumptionHandler, standalone
- asm: can_id 0xfee900, prio 0x803f72 (JCFCPZ 'fuel consumption'), len 8, data 0x8035a8 (j1939_pgn65257_trip_fuel), status 0x8035b0, SA, register(0xfee9, 0x33a62 cm550_buildPgn65257FuelConsumptionMessage). Called from cm550_registerJ1939PgnRequestHandlers 0x2f568.
- CM848 has no PGN 65257 message (no 0xfee9 in the cpp). Name says 65249 - wrong.

### 0x33ce2 (vp44_ioControlPGN_65244_Builder) -> cm550_initializePgn65244IdleOperationHandler, standalone
- asm: can_id 0xfedc00, prio 0x803f76 (JCISPZ idle operation), len 8, data 0x8035de (j1939_pgn65244_total_idle_fuel_used), status 0x8035e6, register(0xfedc, 0x33c6c cm550_buildPgn65244IdleOperationMessage). Nothing VP44: cm550_. No CM848 65244.

### 0x343d2 (vp44_vehicleHoursPGN_65255_Builder) -> cm550_initializePgn65255VehicleHoursHandler, standalone
- asm: can_id 0xfee700, prio 0x803f86 (JCVHHRPZ), len 8, data 0x803692 (j1939_pgn65255_total_vehicle_hours), status 0x80369a, SA, total vehicle hours = 0xffffffff @0x34414-0x34416, register(0xfee7, 0x34394 cm550_buildPgn65255VehicleHoursMessage). Nothing VP44. No CM848 65255.

### Priority globals (all words, each read once as move.w by its set-up; RAM dump values)
0x803f4e JCAKPZ 6 (ACK sender 0x31b44); 0x803f56 JCDG01PZ 6; 0x803f5e JCDG08PZ 6 (DM8 set-up 0x32b7a); 0x803f60 JCDG10PZ 6; 0x803f64 JCEG02PZ 3; 0x803f72 JCFCPZ 6; 0x803f76 JCISPZ 6; 0x803f86 JCVHHRPZ 6. 0x803f7c JCNTAKPZ (NACK) has no reference.

### 0x31b22 (cm550_diagnosticCanResponseSender) -> cm550_sendPgn59392AcknowledgementMessage, COUNTERPART of CM848 0x23dbc (and 0x23d3c)
- asm 0x31b22-0x31b94: request = long +4 (movea.l (0xc,a7) after 8-byte movem), control = word +8 (move.w (0x10,a7),d1), header 0xe8ff00 @0x31b3a + prio 0x803f4e (JCAKPZ, read @0x31b44), header byte 3 (SA) = request id byte 2 @0x31b58, header byte 2 (DA) = request id byte 3 (requester SA) @0x31b5e, payload byte 0 0x801eb2 = control @0x31b64, payload 5/6/7 = data_ptr[0..2] @0x31b6e-0x31b80, cm550_sendCanMessage(0x801ea4) @0x31b88.
- Callers: DM3 handler 0x2ef2c clr.w (0 = ACK); DM7 handler 0x2efae #1 (NACK, unsupported test id); cm550_dispatchJ1939PgnRequest 0x2f52a #1 (NACK when no handler matched and the request was not global).
- CM848 0x23dbc (cm848_sendJ1939NegativeAcknowledgement): same steps except header byte 2 = 0xff (li r12,255 @0x23df8) - global, not the requester. CM848 0x23d3c echoes 0 / pgn_pf / dest_address (the received frame's own PGN). CM550 has one sender: counterpart.
- CM848 0x23dbc is called with J1939_ACK too (cm848_j1939HandlePgn65228Dm3ClearInactiveFaults when j1939_dm1_active_flag != 0) -> its name 'NegativeAcknowledgement' is wrong (cm848_functions lead).
- Only writer of 0x801ea4 header / 0x801eb2 payload besides the set-up 0x31b96.

### 0x31b96 (cm550_canBufferSetup1, EXTRA) -> cm550_initializePgn59392AcknowledgementBuffer, COUNTERPART of cm848_initJ1939AckBuffer 0x23e40
- asm 0x31b96-0x31bcc: len 8, data 0x801eb2, status 0x801eba, payload bytes 1-4 = 0xff. First descriptor set-up of mc68k_initializeJ1939Datalink (0x28bdc).
- CM848 0x23e40 does the same plus clears j1939_dm1_active_flag (stb 0 -> 0x40ad53 @0x23e84): counterpart.

### 0x32b38 (vp44_diagnosticByteResponseSender) -> sendPgn65232NonContinuousMonitorTestResultMessage, TWIN of CM848 0x255c0
- CM550 asm 0x32b38-0x32b62: link a6; byte (9,a6) -> 0x803470 (payload +0 test identifier); pea (0xa,a6) jsr byteSwap16 0x218fe; move.w d0 -> 0x803472 (payload +2 test value); cm550_sendCanMessage(0x803462).
- CM848 0x255c0-0x25608: stb r3 -> 0x3fad6e (+0); sth r4 to stack, bl 0x50b58c cm848_reverseByteOrder16(&r4) -> sth 2(r31); bl 0x539fc cm848_sendJ1939Message(0x3fad60). Same steps, same offsets.
- Callers: CM550 DM7 handler 0x2ef76 (test 0, value 0x100) / 0x2ef9a (test 1, value 0x200); CM848 cm848_j1939HandlePgn58112Dm7 (0, intake_air_heater_monitor_result) / (1, misfire_monitor_result). Same position (the DM7 handler's two sends).

### 0x32b64 (vp44_diagnosticDM8PGN_65232_Builder, EXTRA) -> initializePgn65232Dm8Buffer, TWIN of CM848 0x2560c cm848_initializePgn65232Dm8Buffer
- CM550 asm 0x32b64-0x32bba: header 0xfed000, prio 0x803f5e (JCDG08PZ), len 8, data 0x803470, status 0x803478, SA, payload +1 = 0xff, +4 = 0xffff, +6 = 0xffff.
- CM848 0x2560c-0x25678: the same 8 steps, same order, same constants. Both called right after the DM1 set-up in the datalink initializer (CM550 0x28c54; CM848 cm848_j1939_system_init).

### 0x322ae cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage: keep (counterpart of CM848 0x24be8)
- CM848 loop stops at 20 slots (uVar3 < 0x15) and re-orders the DTC bytes; CM550 does neither. Round 96 decision confirmed.
- Stack argument never read (no (n,a7) read in 0x322ae-0x323bc); d0 is left over; callers ignore d0 (0x322a4 addq.l #4; dispatcher 0x2f50c addq.l #4 then bra) -> prototype void(void).

### 0x2ed6a (cm550_insiteParameterParser) -> cm550_getReceivedJ1587ParameterLength, standalone (CM848 has no J1587)
- asm 0x2ed6a-0x2edb0: insite_parameter_id (0x80dde5) < 0x80 -> 2, < 0xc0 -> 3, < 0xfe -> the count byte at insite_request_read_pointer (0x80ddf2) + 2, 20 when the count is above 18 (cmpi.b #0x12; moveq #20), else (PID 254 / 255) 0.
- One caller: the J1708 request parser 0x1e956 (named buildPgn65228Dm3ClearInitMessage) @0x1e9ca right after it reads the PID byte and advances the read pointer: move.b d0,d2; beq -> stop parsing (0x1eb7c); add.b d2,d4 (bytes consumed). Return used as a byte. No arguments.
- = the size of the received parameter (PID byte + data) in the request by the J1587 PID ranges.

### 0x2edb2 (cm550_parameterLookupForInsite) -> cm550_getJ1587ReplyParameterLength, standalone
- asm 0x2edb2-0x2ee60: PID < 0x80 -> 2, < 0xc0 -> 3; 0xc1 (PID 193) -> word 0x80599c (insite_active_fault_count) low byte + 2; 0xc2 (PID 194) -> mode 0x80dde7 == 0: (word 0x805998 + byte 0x80bca8) * 2 + 2, else (0x805998 + 0x80599a) * 3 + 2; 0xc4 (PID 196) -> 4 when 0x80de26 & 0xc0, 2 when 0x80de76 == 0, else 7; 0xea (PID 234) -> 24; 0xed (PID 237) -> 22; 0xf3 (PID 243) -> 31; others -> 6.
- Callers 0xec80 (cm550_activeParamReadFunction: move.b d0,(a2) = insite_parameter_data_size, beq), 0x1e9e2 / 0x1ea4a / 0x1eb48 (the parser: move.b d0 -> 0x80ddf8 insite_parameter_data_size) - all for the REQUESTED PID before the reply is appended. Return used as a byte.
- Discriminator vs 0x2ed6a: this one sizes the ECM's REPLY for the requested PID (fault counts / fixed sizes); 0x2ed6a sizes the received request field (reads its count byte).

### 0x2eea2 (cm550_diagnosticServiceDispatcher) -> cm550_dispatchJ1939DiagnosticServiceRequest, COUNTERPART of CM848 0x22128 cm848_j1939DiagnosticServiceHandler
- asm 0x2eea2-0x2ef06: request = long +4 (movea.l (0x18,a7),a3 after 20-byte movem); result d4 = 24 (unknown service); scan j1939_diagnostic_service_table 0x801c7a for count 0x801d3a entries (6 bytes each) comparing entry byte 0 with data_ptr[0] (movea.l (6,a3)); on a match: cm550_diagnosticServiceSecurityValidator 0x21982(request) and, when it returns 0xff, the entry handler (movea.l (2,a2); jsr (a0)) with the request (move.l a3,-(a7)); result low byte; unless 0xff: cm550_diagnosticMultiPacketResponseBuilder(request, word result) 0x3216a.
- CM848 0x22128 first drops services 0x0c / 0x0d (responses: result 0xff, no reply; cmpwi r3,12 / 13 @0x22150) - CM550 has no such filter: counterpart.
- Registered for 0xef00 by registerJ1939DiagnosticServiceDispatcher (0x2ef08) and called by the TP.DT handler 0x22c26 (vp44MultiFrameResponseHandler) with pea (8,a4) = 0x8012cc, the reassembled message record (+6 data_ptr set to 0x8012de @0x22d02) - a can_std_rx_desc_t too.
- Return: d0 left over; void.

### Global 0x803613 -> j1939_pgn65270_exhaust_gas_temperature_low_byte (byte), no row yet
- IC1 set-up 0x33eee (cm550_intakeManifoldPGN_65526_Builder - misnamed, it is the PGN 65270 set-up): a1 = 0x80360e (data_pointer), move.b #0xff,(0x5,a1) @0x33f46 = byte 6. No absolute reference anywhere (abs_refs empty), no other writer; the IC1 builder 0x33e58 writes only bytes 2 / 3.
- J1939 DB PGN 65270 (doc mislabelled 'AMB' but the parameters are IC1): bytes 6-7 = SPN 173 Engine Exhaust Gas Temperature (0.03125 deg C/bit, -273). Sibling 0x803614 is j1939_pgn65270_exhaust_gas_temperature_high_byte (round 96).
- Other IC1 bytes without rows (all 0xff from the set-up, never written again): 0x80360e byte 1 SPN 81 (move.b #0xff abs @0x33f32), 0x803611 byte 4 SPN 106 ((3,a1) @0x33f3a), 0x803612 byte 5 SPN 107 ((4,a1) @0x33f40), 0x803615 byte 8 SPN 112 ((7,a1) - check).

### Global 0x80a9cc -> engine_retarder_command_source (ENGINE_RETARDER_COMMAND_SOURCE, word), no row yet
- e2m 117D +8 EBCOAG 'EB CMD SRC. 0=NOT_COMM,1=J_COMM,2=CRUISE,3=SWITCH,4=JC_LIM,5=NOT_S' (len 2, unsigned, 0-4). CM848's row for 117D +8 is 0x40a270 engine_retarder_command_source typed ENGINE_RETARDER_COMMAND_SOURCE (size 2). RAM (outside the EEPROM image): no _cal.
- Only access in the dump: move.w (0x80a9cc),d0 @0x33920 in cm550_buildPgn61440ElectronicRetarderController1Message, ext.l, cmp #4 / bhi, jump table at 0x33936: 0 -> 0x33974 (no mode bits), 1 -> 0x3394c, 2 -> 0x33946 (or 2), 3 -> 0x33940 (or 1), 4 -> 0x3394c; 1 / 4 map engine_retarder_j1939_control_device 1 / 3 / 2 / other to 6 / 5 / 7 / 14.
- CM848's ERC1 builder 0x26238 uses the same mapping with the enum (J1939_OVERRIDE / J1939_LIMIT -> 6 / 5 / 7 / 14, CRUISE -> 2, SWITCH -> 1). No writer in the dumped CM550 ROM (likely in the undumped region above 0x40000).
- CM550 enum members to add: ENGINE_RETARDER_COMMAND_SOURCE 0 NONE / 1 J1939_OVERRIDE / 2 CRUISE / 3 SWITCH / 4 J1939_LIMIT (size 2). 5 NOT_SET only in the label (range 0-4): left out.
- Lead (not done): 0x80a9ca (117D +6 EBSWSS, 0-3 in CM550, tst.w @0x33914 -> SPN 571 0x10) = CM848's engine_retarder_selection_percent_fault_masked record; the CM848 name rests on CM848's writer.

### 0x3407a cm550_buildPgn65249RetarderConfigurationMessage: keep the name; prototype void(void); plate amended
- asm 0x3407a-0x341e4: link a6,#-4; reads no stack argument (only the local -2(a6)); the early exit (status 0x803652 & 0xf0) leaves d0 = status & 0xf0 -> Ghidra's uint / in_D0. Only caller: the retarder periodic queue (scheduleJ1939PeriodicMessage(RETARDER, 0xfee1, 5000, 0x12d)); cm550_runJ1939PeriodicTransmitQueues calls the builder as a statement. No PGN request registration for 0xfee1.
- '=' bug confirmed: 0x340a2 cmpi.w #1,(0x8081fe); bls 0x340b6 -> 0x340ac byte 1 = 3 (count >= 2); 0x340b6 move.w #1,(0x8081fe).l; beq.s 0x340ca (never: move of 1 clears Z) -> 0x340c0 byte 1 = 0x14; 0x340ca (0xff) unreachable. CM848 0x26xxx: count < 2 -> (== 1 -> 0x14 else 0xff), else 3.
- Side effect: the retarder queue runs while datalink_broadcast_enable_flags bit 3 (JCRDBCEA) is set (dump 0x80aa12 = 0x000d: set). With a calibrated EBNUOUDR of 0 the first RC broadcast makes it 1; then the ERC1 builder sends the computed SPN 520 instead of 0xff (tst.w @0x33974), cm550_processEngineRetarderTsc1Request stops skipping retarder TSC1 requests (tst.w @0x2f800; beq.w 0x2fa9e); cm550_diagnosticMessage54Builder (cmpi.w #1 @0x1fcee, bls) is unaffected. Dump: count 1, RC byte 1 = 0x14, RC status 5 (sent).
- Globals (EXTRA, same e2m records as CM848, RAM -> no _cal): 0x8081fe (13D8 +0 EBNUOUDR) -> engine_retarder_output_driver_count; 0x808200..0x80820a (13D8 +2..+C JCDR1NCY..JCDR6NCY) -> engine_retarder_driver_1..6_cylinder_count. All word accesses.

## REQUEST CHAIN (PGN 61184) - registrations found in the ROM (movea.l #0x2ee62,a2 + jsr (a2), and one jsr.l)
- 0x11b36 registerJ1939DiagnosticHandlers: 1 0x1183e / 7 0x1188c / 10 0x118b2 / 22 0x118cc / 6 0x118fc / 11 0x11908 / 24 0x11a68 / 21 0x11a74
- 0x200c6 (cm550_systemFunction6xParameterized): 15 0x1ffd2 / 16 0x1ffd2 / 4 0x200a4 / 5 0x200b4
- 0x21872 registerJ1939MemoryWriteServices: 0x44 0x2167e / 0x45 0x216c6 / 0x4b 0x217de / 0x4d 0x21826 / 0x47 0x21714 / 0x49 0x21778
- 0x226da registerJ1939MemoryReadServices: 0x43 0x22530 / 0x4a 0x22646 / 0x4c 0x2268e / 0x46 0x2257c / 0x48 0x225e0
- 0x22370 (cm550_systemFunction1xCaller): 0x41 0x222b4 (jsr.l 0x2ee62 @0x2237a)
- The receive dispatcher 0x212b2 pushes the 18-byte ring record pointer (move.l (a3),-(a7) @0x21388; records at 0x80d72e, +18 each) and ignores d0; the TP.DT handler 0x22c26 pushes 0x8012cc (pea (8,a4) @0x22d0a), whose +6 it set to 0x8012de. Both are can_std_rx_desc_t (+0 id, +4 length, +6 data_ptr).

### Stack offsets (entry sp+4 = first argument; 2-byte slots)
- dispatcher 0x2eea2: movem 5 regs (20) -> (0x18,a7) = +4 request. void.
- validator 0x21982 (cm550_diagnosticServiceSecurityValidator): movem 5 regs -> (0x18,a7) = +4; reads (6,a2) data_ptr, (4,a2) length; returns 0xff / 3 / 2 (byte).
  COUNTERPART of CM848 0x50b634 cm848_validateJ1939DiagnosticRequest: CM848 returns 0x1a for a secured service whose length is 8 (li r3,26 @0x50b6f4); CM550 returns 2 for any length other than header + 10 (0x21a20). -> cm550_validateJ1939DiagnosticRequest.
- write worker 0x2148a: movem 8 regs (32): (0x24,a7) +4 request, (0x28,a7) +8 address long, (0x2c,a7) +12 length long. char.
- write by ID 0x21642: link a6: (8,a6) +4 request, (0xc,a6) +8 ID word, (0xe,a6) +10 offset long, (0x12,a6) +14 length long. char.
- read worker 0x2238e: movem 8 regs: +4 request / +8 address / +12 length. Returns 2 / 9 / 10 (region) / 4 (no buffer) / 0xff (sent) - the read services tail-return it (bsr then unlk / rts, d0 untouched) so the existing 'return void' row is WRONG.
  TWIN of CM848 0x50c42c cm848_readJ1939DiagnosticMemoryAndRespond (same cap 0x6e4, header length check 8 / h / h + 10, region REFUSED / UNMAPPED, 0x43 under 256 -> 0x44 with data[3] = data[6], reply table 0x22384 = 45 00 00 47 00 49 00 4b 00 4d (CM848 the same), header 0xef0000 + priority bits, swapped addresses, EEPROM remap 0x1000000 -> 0x803b0a (CM848 -> 0x3fd482), memcpy, send, 0xff).
- read by ID 0x224f4 (FUN_000224f4, no row): link a6: +4 request, +8 ID word, +10 offset, +14 length; lookup 0x10e16 -> 8; else read worker. TWIN of CM848 0x50c5d0 cm848_readJ1939DiagnosticMemoryByParameterId (same steps; the write-side pair is already shared).
- restartThroughBootRom 0x1192a: (8,a6) +4 request (only passed to 0x3216a @0x119fa), (0xc,a6) +8 word acknowledge_datalink. byte. J1708 path passes clr.l (NULL).
- handlers with link a6 read (8,a6) = +4; handlers without a frame read (4,a7) = +4 (0x11908, 0x200a4, 0x200b4).
- handlers that read no argument: 0x1183e, 0x1188c, 0x118b2, 0x118cc, 0x118fc, 0x11a68, 0x11a74, 0x1ffd2 (CM848 declares its twins (void) too).

### Extra twins in the chain (same steps, same constants, same position: CM550 mc68k_initializeJ1939Datalink and cm848_j1939_system_init both call ... registerJ1939MemoryReadServices, <0x41 registrar>, registerJ1939MemoryWriteServices, registerJ1939DiagnosticHandlers, <15/16/4/5 registrar>)
- 0x22370 cm550_systemFunction1xCaller = CM848 0x50c400 cm848_registerJ1939GetAddressByParameterIdService -> registerJ1939GetAddressByParameterIdService
- 0x222b4 cm550_canDiagnosticResponseSender = CM848 0x50c318 -> handleJ1939GetAddressByParameterIdService (ID data 1-2, lookup 0x10e16 -> 8, header 0xef0000 + (byte0 & 0x1c), addresses swapped, len 7, [0x42, ID, 4-byte address], cm550_sendCanSingleFrame, 0xff)
- 0x200c6 cm550_systemFunction6xParameterized = CM848 0x509d34 -> registerJ1939BroadcastAndNoOperationServices (15, 16, 4, 5 in that order)
- 0x1ffd2 (label, no function) = CM848 0x509be0 (li r3,0; blr) -> handleJ1939NoOperationService
- 0x200a4 cm550_j1939TorqueControlModeClear = CM848 0x509ce4 -> handleJ1939DisableBroadcastService
- 0x200b4 cm550_j1939TorqueControlModeSet = CM848 0x509d0c -> handleJ1939EnableBroadcastService
- 0x1ffd6 cm550_j1939TorqueControlModeParser = CM848 0x509be8 -> updateJ1939BroadcastEnableMask (FE/FE -> 0xffff; target 1: item 1 12 / 2 0x80 / 6 1 / 7 2 / else 4; target 0xfd: 0xfe 0x8c / 1 12 / 2 0x80 / else 4; other 4; enable byte +9 == 1 -> or, else and-not into datalink_broadcast_enable_flags; 0)

### Prototypes to give (CM550; request = can_std_rx_desc_t* at +4 unless said)
- 0x2eea2 dispatcher: void (request).  0x21982 validator: byte (request) [locals 0x21982 keyed by auto-names bVar2 / uVar1 / iVar4 / cVar3 must be re-checked after the build].
- handlers reading the request: 0x11908 byte; 0x200a4 byte; 0x200b4 byte; 0x222b4 byte; write services 0x2167e / 0x216c6 / 0x21714 / 0x21778 / 0x217de / 0x21826 char; read services 0x22530 / 0x2257c / 0x225e0 / 0x22646 / 0x2268e char (each tail-returns its worker's d0).
- handlers with no argument: 0x1183e, 0x118fc, 0x11a68, 0x1ffd2 -> byte (void) (0x1188c / 0x118b2 / 0x118cc / 0x11a74 already have byte return rows).
- workers: 0x2148a char (request +4, address dword +8, length dword +12); 0x21642 char (request +4, parameter_id ushort +8, offset dword +10, length dword +14); 0x2238e char (request +4, address dword +8, length dword +12) - replaces the wrong 'return void' row; 0x224f4 char (request +4, parameter_id ushort +8, offset dword +10, length dword +14); 0x1192a byte (request +4, acknowledge_datalink ushort +8).
- 0x31b22 void (request +4, acknowledgement_type ushort +8) [existing rows already right; only the return row is missing - d0 is left over].
- 0x32b38 void (test_identifier byte at +5 = low byte of the +4 slot, test_value ushort +6) - CM848 twin's names.
- void(void): 0x322ae, 0x3407a. byte(void): 0x2ed6a, 0x2edb2.
- Round 97's abbreviation pass renames 0x2238e request_ptr / 0x21982 msg_ptr / 0x2eea2 msg_ptr: these prototypes replace those rows.

### Leads not done (other set-ups with wrong old names; the CM848 order of cm848_j1939_system_init matches)
0x31c1a cm550_j1939MessageSetup_PGN_65265 = PGN 65269 AMB set-up (0xfef500, prio 0x803f50); 0x32e08 vp44Command0x100Builder = PGN 61444 EEC1 set-up (0xf00400, 0x803f62); 0x33120 vp44_secondaryParamPGN_65247_Builder = PGN 65247 EEC3 (0xfedf00, 0x803f66); 0x331ae vp44_engineFluidLevelPGN_65263_Builder = PGN 65263 (0xfeef00, 0x803f6a); 0x339b0 cm550_cumminsProprietaryTSC_PGN_15728640_Builder = PGN 61440 ERC1 set-up (0xf00000 = 15728640, 0x803f6e); 0x33c28 cm550_fuelEconomyPGN_65266_Builder = PGN 65266 (0xfef200, 0x803f74); 0x3401a cm550_cruiseControlPGN_65264_Builder = PGN 65264 PTO (0xfef000, 0x803f7e); 0x34334 cm550_electronicBrakePGN_65527_Builder = PGN 65271 VEP1 (0xfef700, 0x803f84); 0x331ae etc. Also cm550_engineSerialNumberPGN_65259_Builder, cm550_engineTemperaturePGN_65262_Builder, cm550_vehicleDistancePGN_65248_Builder, cm550_diagnosticDM2PGN_65227_Builder, cm550_diagnosticDM5PGN_65230_Builder from the registrar.
- Plates that still name old set-up names: 0x33a62 (cm550_retarderConfigPGN_65249_Builder), 0x32e4c (vp44_cumminsProprietaryDM_983_Builder), 0x34394 (vp44_vehicleHoursPGN_65255_Builder), 0x33e58 (cm550_intakeManifoldPGN_65526_Builder), 0x2ef4a (DM8 sender 0x32b38 by address).
- 0x8012cc: the TP reassembly record (can_std_rx_desc_t at +8 of the session record 0x8012c4; data buffer 0x8012de) - no rows; a struct for the session is a later job.
- CM550 J1939_DIAGNOSTIC_RESULT members are CM550's own unreviewed names; CM848's set fits the codes the CM550 handlers return (0 / 2 / 3 / 4 / 7 / 8 / 9 / 0x0a / 0x0b / 0x18 / 0x1a).
- J1939_ACK_TYPE for CM550 (0 ACK / 1 NACK) would need size 2 (the 0x31b22 slot is a word): not proposed.

### More chain facts
- TP layer: 0x23186 (vp44DiagnosticBufferPointersInit) registers 0x22e5e for 0xec00 (TP.CM, PGN 60416) and 0x22c26 (vp44MultiFrameResponseHandler) for 0xeb00 (TP.DT, PGN 60160) with registerJ1939ReceiveHandler (0x231b8-0x231cc) - the CM848 counterparts are cm848_initializeJ1939Transport / cm848_dispatchJ1939TransportConnectionManagement / cm848_handleJ1939TransportDataPacket. Names are a transport-family lead. 0x22c26 reads its frame at +4 (movea.l (0x24,a7),a2 after the 32-byte movem): prototype void (can_std_rx_desc_t *message).
- IC1 set-up 0x33eee (EXTRA): TWIN (medium) of CM848 0x265d8 cm848_initJ1939InletExhaustConditionsBuffer: same header 0xfef600 / prio / len 8 / data / status / SA, then 0xff into payload bytes 1, 4, 5, 6, 7, 8; CM848 writes bytes 6-7 with one sth 0xffff at payload+5 (0x3fae4b) where CM550 writes two bytes ((5,a1) and (6,a1)): the CPU32 cannot store a word at the odd address 0x803613. Between the fluid level and PTO set-ups in both initializers (CM550 has the SHUTDN set-up in between).
- CM848 renames (cm848_functions): 0x23dbc cm848_sendJ1939NegativeAcknowledgement -> cm848_sendJ1939AcknowledgementOfRequestedPgn (called with J1939_ACK by the DM3 handler); 0x24dd8 cm848_initPgn65226Dm1Handler -> cm848_initializePgn65226Dm1Handler; 0x23e40 cm848_initJ1939AckBuffer -> cm848_initializePgn59392AcknowledgementBuffer; 0x22128 cm848_j1939DiagnosticServiceHandler -> cm848_dispatchJ1939DiagnosticServiceRequest.
- 0x801eb2 (ACK payload, no row): j1939_pgn59392_payload byte[8] (CM848 j1939_ack_payload is a j1939_acknowledgement_payload_t; a struct port is a later step).
