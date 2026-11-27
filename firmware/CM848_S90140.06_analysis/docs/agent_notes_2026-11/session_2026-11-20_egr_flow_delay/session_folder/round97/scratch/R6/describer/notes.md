# R6 describer notes (round 97)

## 0x32244 (now cm550_diagnosticDM11PGN_65234_Builder) - DM10 descriptor set-up, TWIN of CM848 0x24b64
- asm 0x32244-0x32298: move.l #0xfed200,(0x801f3e); priority word 0x803f60 (e2m 1254 +12 JCDG10PZ 'DEFAULT PRIORITY FOR DIAGNOSTIC MESSAGE 10') &7 <<2 into byte0 bits 2-4 (andi.b #0xe3 / or.b); len 2 at +4; data ptr 0x801f4c (j1939_dm10_payload) +6; status ptr 0x801f54 +10; SA byte 0x80da01 -> +3; registerJ1939PgnRequestHandler(0xfed2, 0x32222). rts.
- CM848 0x24b64 cm848_initializePgn65234Dm10Handler: same 7 steps in the same order (0xfed200, priority 0x3fd84c rlwimi 27-29, len 2 +4, +6 payload, +10 status, SA +3, register 65234 -> 0x24b28).
- Both are the LAST call of the registrar (cm550_registerJ1939PgnRequestHandlers / cm848_registerJ1939PgnRequestHandlers), after the DM5 set-up. The handler 0x32222 / 0x24b28 already share the name buildPgn65234Dm10TestIdentifiersSupportMessage.
- => twin, shared unprefixed name: initializePgn65234Dm10TestIdentifiersSupportHandler (or initializePgn65234Dm10Handler). Current name 'DM11' is wrong (65234 = DM10).

## 0x323be (now cm550_engineCoolantPGN_65226_Builder) - DM1 descriptor set-up, COUNTERPART of CM848 0x24dd8
- asm 0x323be-0x3241a: 0xfeca00 -> 0x801f56; priority word 0x803f56 (e2m 1254 +8 JCDG01PZ) &7<<2; data ptr 0x801f64 (+6); status ptr 0x80265a (+10); SA +3; payload byte 2 (0x801f65 flash lamp) = 0xff; bset #7 payload byte 6 (0x801f69, first DTC's conversion method bit); registerJ1939PgnRequestHandler(0xfeca, 0x322ae). No data length store (the builder sets it).
- CM848 0x24dd8 cm848_initPgn65226Dm1Handler: same steps + one more: clears j1939_dm1_broadcast_pending_flag (0x3fabcb) before the registration (CM550 has no such flag: its periodic task 0x3229a sends only while faults are active).
- Position: first DM set-up in both registrars (after the direct registrations).
- => counterpart, prefix cm550_: cm550_initializePgn65226Dm1Handler. Nothing about coolant.

## 0x33aea (now cm550_retarderConfigPGN_65249_Builder) - LFC (PGN 65257) descriptor set-up + request registration
- asm 0x33aea-0x33b3e: 0xfee900 -> 0x80359a (j1939_pgn65257_tx_message); priority word 0x803f72 (e2m 1254 +24 JCFCPZ 'DEFAULT NETWORK PRIORITY FOR FUEL CONSUMPTION MESSAGE') &7<<2; len 8; data 0x8035a8 (j1939_pgn65257_trip_fuel); status 0x8035b0; SA; registerJ1939PgnRequestHandler(0xfee9=65257, 0x33a62 cm550_buildPgn65257FuelConsumptionMessage).
- Called from cm550_registerJ1939PgnRequestHandlers (5th call). CM848 has no PGN 65257 (no 0xfee9 anywhere in its cpp / renames) -> none; prefix cm550_.
- => cm550_initializePgn65257FuelConsumptionHandler. Nothing retarder about it.

## 0x33064 (now vp44_cumminsProprietaryDM_983_Builder) - EEC2 (PGN 61443) descriptor set-up, TWIN of CM848 0x25d60
- asm 0x33064-0x330c2: 0xf00300 -> 0x8034b2; priority 0x803f64 (e2m 1254 +16 JCEG02PZ 'DEFAULT NETWORK PRIORITY FOR EEC2 MESSAGE') &7<<2; SA -> +3 BEFORE len (unusual order); len 5 (+4); data 0x8034aa (+6); status 0x8034c0 (+10); jsr 0xf99a emptyPgn61443ElectronicEngineController2InitializationStep (shared empty twin of CM848 0x20aec); registerJ1939PgnRequestHandler(0xf003, 0x32e4c EEC2 builder).
- CM848 0x25d60 cm848_initPgn61443Eec2Handler: identical order (0xf00300, priority 0x3fd850 rlwimi, SA +3, len 5, +6, +10, bl 0x20aec, register 61443 -> 0x25b10).
- Position: 5th call of both J1939 initializers (mc68k_initializeJ1939Datalink / cm848_j1939_system_init), right after the EEC1 set-up.
- => twin, shared unprefixed: initializePgn61443ElectronicEngineController2Handler. No VP44, no DM, no '983'.

## 0x31b22 (now cm550_diagnosticCanResponseSender) - PGN 59392 Acknowledgment sender, COUNTERPART of CM848 0x23dbc
- asm 0x31b22-0x31b94: header 0xe8ff00 -> 0x801ea4 (j1939_pgn59392_tx_message); priority word 0x803f4e (e2m 1254 +0 JCAKPZ 'DEFAULT PRIORITY FOR ACK MESSAGE') &7<<2; tx id byte 3 (SA) = request id byte 2 (the address the request was sent to); tx id byte 2 (DA) = request id byte 3 (the requester's SA); data byte 1 (0x801eb2) = control byte arg (word slot +8 after movem of 2 = sp+8 at entry... prototype +4 request ptr long, +8 control word); data bytes 6-8 (0x801eb7-9) = request->data_ptr[0..2]; send (0x104e8 cm550_sendCanMessage). Bytes 2-5 = 0xff and len 8 set once by 0x31b96 (cm550_canBufferSetup1, the PGN 59392 buffer set-up, 1st descriptor set-up of mc68k_initializeJ1939Datalink like CM848 cm848_initJ1939AckBuffer).
- Callers (3): DM3 handler 0x2ef1c passes 0 (clr.w) = ACK; DM7 handler 0x2efae passes 1 = NACK; PGN request dispatcher 0x2f52a passes 1 = NACK (not for global requests).
- CM848: two senders, both DA=0xff global and SA = request DA: 0x23d3c cm848_sendJ1939AcknowledgeMessage (PGN field = 0 / id byte1 / id byte2 = the received frame's own PGN; called by DM3 / DM7 / 56832 reset) and 0x23dbc cm848_sendJ1939NegativeAcknowledgement (PGN field = data bytes 0-2; called by the PGN request dispatcher NACK and DM3). CM550 0x31b22 = 0x23dbc's steps except the DA (requester, not global) -> counterpart (the existing param comment calling 0x23d3c its twin is wrong).
- => cm550_sendPgn59392AcknowledgementMessage (control byte 0 ACK / 1 NACK = CM848 J1939_ACK_TYPE values).

## 0x32b38 (now vp44_diagnosticByteResponseSender) - DM8 (PGN 65232) test result sender, TWIN of CM848 0x255c0
- asm: link a6; move.b (9,a6) -> 0x803470 (payload byte 1 = test identifier, SPN 1224); byteSwap16(&arg2) -> word 0x803472 (bytes 3-4 test value SPN 1226, low byte first); cm550_sendCanMessage(0x803462 = j1939_pgn65232_tx_message). Args: +4 word slot, byte at +5 = test id; +6 word = value.
- Only caller: DM7 handler 0x2ef4a (twice: (0,0x100) and (1,0x200)).
- CM848 0x255c0 cm848_sendPgn65232NonContinuousMonitorTestResultMessage: stb test_id -> payload+0; reverseByteOrder16(&value) -> payload+2; send. Same steps / order; only caller the DM7 handler 0x227a0. -> twin: one shared name, drop the prefix: sendPgn65232NonContinuousMonitorTestResultMessage.
- Nothing VP44. Parameter names: test_identifier (byte), test_value (word).

## 0x322ae cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage (round 96 name in the frozen csv) - DM1 builder/sender, COUNTERPART (not twin) of CM848 0x24be8
- Same frame as CM848 (status ptr store, 0xf0 busy test, len 2, empty list -> lamp 0 + 0xffffffff len 6, else lamp byte + per slot skip flag 0x4000, count min 127, |0x80), BUT CM848 caps the loop at 20 slots (uVar3 < 0x15) and swaps the first two SPN bytes of its table word; CM550 has neither. Both index the output by slot so a 0x4000-flag slot leaves a 4-byte gap (CM550: addq.l #4,a2 at 0x323a0 runs for skipped slots too) while the length grows only for written DTCs.
- Name already in build form; keep cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage. Return: callers ignore d0 (0x3229a pushes 0 and drops it; the request dispatcher ignores it) -> void prototype would drop in_D0.

## 0x33ce2 (now vp44_ioControlPGN_65244_Builder) - IO Idle Operation (PGN 65244) descriptor set-up + request registration
- asm 0x33ce2-0x33d36: 0xfedc00 -> 0x8035d0 (j1939_pgn65244_tx_message); priority 0x803f76 (e2m 1254 +28 JCISPZ 'DEFAULT NETWORK PRIORITY FOR IDLE OPERATION MESSAGE') &7<<2; len 8; data 0x8035de (j1939_pgn65244_total_idle_fuel_used); status 0x8035e6; SA; registerJ1939PgnRequestHandler(0xfedc=65244, 0x33c6c cm550_buildPgn65244IdleOperationMessage). No payload seeding.
- Only caller: cm550_registerJ1939PgnRequestHandlers (6th call, 0x2f56e). CM848: no PGN 65244 anywhere -> none. Not 'IO control', nothing VP44.
- => cm550_initializePgn65244IdleOperationHandler.

## 0x343d2 (now vp44_vehicleHoursPGN_65255_Builder) - VH Vehicle Hours (PGN 65255) descriptor set-up + request registration
- asm 0x343d2-0x3442e: 0xfee700 -> 0x803684 (j1939_pgn65255_tx_message); priority 0x803f86 (e2m 1254 +38 JCVHHRPZ 'DEFAULT NETWORK PRIORITY FOR VEHICLE HOURS MESSAGE'); len 8; data 0x803692; status 0x80369a; SA; payload bytes 1-4 (SPN 246 total vehicle hours) = 0xffffffff (moveq #-1 / move.l); registerJ1939PgnRequestHandler(0xfee7=65255, 0x34394 cm550_buildPgn65255VehicleHoursMessage, which fills bytes 5-8 power take-off hours).
- Only caller: cm550_registerJ1939PgnRequestHandlers (8th call, 0x2f57a). CM848: no PGN 65255 -> none. Nothing VP44.
- => cm550_initializePgn65255VehicleHoursHandler.

## 0x2ed6a (now cm550_insiteParameterParser) - byte count of the RECEIVED J1587 parameter at the cursor
- asm: PID = insite_parameter_id (0x80dde5): <128 -> 2; <192 -> 3; <254 -> the byte at insite_request_read_pointer (0x80ddf2, the length byte after the PID) + 2, or 20 when that byte > 18; 254/255 -> 0. Returns byte (moveq / clr.b d0).
- Only caller 0x1e9ca in the J1708/J1587 request processor 0x1e956 (now buildPgn65228Dm3ClearInitMessage - a wrong name, not in this batch): it adds the result to the message cursor (bVar7) and skips an unhandled PID by result-1; 0 ends the walk.
- J1587 PID length classes (0-127 one data byte, 128-191 two, 192-253 counted). CM848 has no J1587 code -> none.
- => cm550_getReceivedJ1587ParameterLength. Prototype byte(void).

## 0x2edb2 (now cm550_parameterLookupForInsite) - byte count of the ECM's REPLY parameter for the requested PID
- asm: PID <128 -> 2; <192 -> 3; 193 (0xc1) -> insite_active_fault_count (0x80599c) + 2; 194 (0xc2) -> (active_j1922_reportable_fault_count 0x805998 + insite_fault_change_queue_count 0x80bca8) * 2 + 2 when insite_full_detail_response_mode (0x80dde7) is 0, else (0x805998 + inactive_fault_j1587_reportable_count 0x80599a) * 3 + 2; 196 (0xc4) -> 4 when insite_dtc_command_action_byte (0x80de26) & 0xc0, else 2 with insite_matched_dtc_fault_code (0x80de76) 0, else 7; 234 -> 24; 237 -> 22; 243 -> 31; any other -> 6. Byte result (addq.b / moveq).
- Callers: 0x1e956 (for PIDs requested with PID 0 / PID 128 and for the 196 reply), and cm550_activeParamReadFunction 0xec1e (0xec80), which compares it with the J1708 transmit space (insite_response_space_available) before insiteCommandByteDispatcher writes the parameter. 4 call sites.
- Sibling of 0x2ed6a: the same first two classes, but its variable sizes come from the ECM's own data (fault counts, fixed text lengths), not from a received length byte. CM848: none.
- => cm550_getJ1587ReplyParameterLength. Prototype byte(void).

## 0x2eea2 (now cm550_diagnosticServiceDispatcher) - PGN 61184 receive handler / service dispatcher, COUNTERPART of CM848 0x22128
- asm: request = long at +4 (movea.l (0x18,a7) after movem of 5); result d4 = 0x18 (UNKNOWN_SERVICE); scans j1939_diagnostic_service_table (0x801c7a, 6-byte entries) up to j1939_diagnostic_handler_count (0x801d3a) for service_id == request->data_ptr[0]; on a match d4 = cm550_diagnosticServiceSecurityValidator(request) and, when that is 0xff, d4 = handler(request) (move.l a3,-(a7); jsr (a0); low byte). If d4 != 0xff -> cm550_diagnosticMultiPacketResponseBuilder(request, d4).
- Reached: registerJ1939DiagnosticServiceDispatcher (0x2ef08: registerJ1939ReceiveHandler(0xef00, 0x2eea2)) and directly by the transport protocol receive handler 0x22c26 (0x22d0e: pea (8,a4) = the reassembled message view: +6 = data pointer 0x8012de set just before).
- CM848 0x22128 cm848_j1939DiagnosticServiceHandler: same loop / validator / reply, but first drops received 0x0c / 0x0d (positive / negative response) service bytes with result 0xff. CM550 has no such test -> counterpart, cm550_ prefix.
- => cm550_dispatchJ1939DiagnosticServiceRequest (matches cm550_dispatchJ1939PgnRequest). Prototype void(can_std_rx_desc_t *request @ +4).

## global 0x803613 (no row) - IC1 (PGN 65270) payload byte 6 = SPN 173 exhaust gas temperature LOW byte
- Payload base 0x80360e (byte 1). The IC1 set-up 0x33eee (cm550_intakeManifoldPGN_65526_Builder) writes move.b #0xff,(0x5,a1) with a1 = 0x80360e -> 0x803613 = 0xff (not available). No absolute reference anywhere (abs_refs: none); the IC1 builder 0x33e58 writes only bytes 2 and 3. Dump: 0xff. No e2m record.
- Neighbour 0x803614 = j1939_pgn65270_exhaust_gas_temperature_high_byte (byte 7). CM848 stores bytes 6-7 as one halfword 0xffff at DAT_003fae4b (no row). CPU32 cannot do a word at the odd 0x803613, CM550 writes two bytes -> byte row.
- => j1939_pgn65270_exhaust_gas_temperature_low_byte, byte.

## global 0x80a9cc (no row) - e2m 117D +8 EBCOAG engine retarder command source
- e2m (CM550): 117D +8 EBCOAG, 2 bytes U, 'EB CMD SRC. 0=NOT_COMM,1=J_COMM,2=CRUISE,3=SWITCH,4=JC_LIM,5=NOT_S~0-4'. CM848 e2m: 117D +8 E_Brake_Command_Source [EBCOAG] labels 0 NONE ... 6 NOOVERDE -> CM848 row 0x40a270 engine_retarder_command_source, type ENGINE_RETARDER_COMMAND_SOURCE.
- CM550 users: one word read at 0x33920 (move.w (0x80a9cc),d0) in cm550_buildPgn61440ElectronicRetarderController1Message: 1 / 4 -> SPN 900 mode by engine_retarder_j1939_control_device (6 / 5 / 7 / 14), 2 -> 2 (cruise), 3 -> 1 (switch). Same mapping as CM848's ERC1 builder on engine_retarder_command_source. No writer in the dumped ROM (no other 4-byte reference; the writer is outside the 256 KB dump or indirect). Dump (extended RAM) 0x0000. Working RAM (not EEPROM image) -> no _cal.
- => engine_retarder_command_source, type ENGINE_RETARDER_COMMAND_SOURCE (port the enum: CM550 has none).

## 0x3407a cm550_buildPgn65249RetarderConfigurationMessage + the '=' bug at 0x340b6
- asm 0x340a2: cmpi.w #1,(0x8081fe); bls 0x340b6; else byte 1 = 3. 0x340b6: move.w #1,(0x8081fe) (an ASSIGNMENT); beq 0x340ca never taken (Z clear after moving 1) -> byte 1 = 0x14; 0x340ca (byte 1 = 0xff) unreachable. Source bug 'if (count = 1)'.
- 0x8081fe = total_number_of_engine_brake_output_drivers_at_the_ecm_0_255 (e2m 13D8 +0 EBNUOUDR, word, working RAM). Other readers: 0x1fcee (cm550_diagnosticMessage54Builder: count <= 1 -> 4 else 2), 0x2f800 (cm550_processEngineRetarderTsc1Request, tst.w), 0x33974 (ERC1 builder: 0 -> actual retarder percent torque 0xff). After the first RC broadcast (retarder queue 1, 301 ms then every 5000 ms) a count of 0 reads as 1 in all of them. RAM dump: 0x0001.
- Prototype: void(void). Only reference = the builder pointer pea at 0x28cfc (scheduleJ1939PeriodicMessage, queue 1, 0xfee1, 5000, 301); the runner cm550_runJ1939PeriodicTransmitQueues does jsr (a0) then moveq #10,d0: d0 is dropped. No stack parameter read (link a6,#-4 only uses -2(a6)).
- Same for 0x322ae (DM1 builder): callers 0x3229a (pushes 0, drops d0) and cm550_dispatchJ1939PgnRequest (jsr (a0); addq; bra; d0 unused) -> void(void) too.

## EXTRA (not in the lead list, siblings with clean evidence)
- 0x31b96 cm550_canBufferSetup1: PGN 59392 ACK buffer set-up (len 8 @ 0x801ea4+4, data 0x801eb2, status 0x801eba, payload bytes 2-5 = 0xff). 1st descriptor set-up of mc68k_initializeJ1939Datalink. CM848 0x23e40 cm848_initJ1939AckBuffer does the same and then clears j1939_dm1_active_flag (0x40ad53) -> counterpart => cm550_initializePgn59392AcknowledgementBuffer.
- 0x32b64 vp44_diagnosticDM8PGN_65232_Builder: DM8 descriptor set-up (0xfed000, priority 0x803f5e e2m 1254 +10 JCDG08PZ, len 8, data 0x803470, status 0x803478, SA, +1 = 0xff, +4 = 0xffff, +6 = 0xffff). CM848 0x2560c cm848_initializePgn65232Dm8Buffer: identical order and constants; both the last descriptor set-up of the J1939 initializers (after DM1) -> twin => initializePgn65232Dm8Buffer (shared, both rows).

## PGN 61184 request chain prototypes (every request read = (0x6,aN) data_ptr / (0x4,aN) length word / (0..3,aN) ID bytes -> can_std_rx_desc_t*)
Registrations found (registerJ1939DiagnosticService 0x2ee62, via movea.l #0x2ee62,a2 / jsr (a2) at 0x11b38, 0x200ca, 0x21874, 0x226dc and one jsr at 0x2237a):
 svc 1 0x1183e, 7 0x1188c, 0x0a 0x118b2, 0x16 0x118cc, 6 0x118fc, 0x0b 0x11908, 0x18 0x11a68, 0x15 0x11a74, 0x0f/0x10 0x1ffd2 (clr.b d0; rts, no row), 4 0x200a4, 5 0x200b4, 0x44 0x2167e, 0x45 0x216c6, 0x4b 0x217de, 0x4d 0x21826, 0x47 0x21714, 0x49 0x21778, 0x41 0x222b4, 0x43 0x22530, 0x4a 0x22646, 0x4c 0x2268e, 0x46 0x2257c, 0x48 0x225e0.
- Handlers that never read the request (0x1183e, 0x1188c, 0x118b2, 0x118cc, 0x118fc, 0x11a68, 0x11a74, 0x1ffd2): keep (void), byte return.
- Every service handler returns its result byte to the dispatcher (move.b d0,d4 after jsr (a0)); the wrappers pass d0 through (bsr/jsr then unlk/rts) -> return byte (J1939_DIAGNOSTIC_RESULT low byte; 0xff = replied itself / no reply).
Prototypes (offsets from sp at entry; slot rule of stack_parameter_layout.csv):
 0x2eea2 cm550_diagnosticServiceDispatcher: void (can_std_rx_desc_t *request +4)   [movea.l (0x18,a7) after movem of 5]
 0x21982 cm550_diagnosticServiceSecurityValidator: byte (can_std_rx_desc_t *request +4)  [movea.l (0x18,a7) after movem 5; returns 0xff / 2 / 3]
 0x11908 handleJ1939RestartService: byte (can_std_rx_desc_t *request +4)   [movea.l (0x4,a7)]
 0x1192a restartThroughBootRom: byte (can_std_rx_desc_t *request +4, word acknowledge_datalink +8)  [(8,a6) long / (0xc,a6) word; 0x1191a passes NULL + 1]
 0x200a4 / 0x200b4: byte (can_std_rx_desc_t *request +4)  [movea.l (0x4,a7); already typed, name param_1 -> request]
 0x2167e / 0x216c6 / 0x21714 / 0x21778 / 0x217de / 0x21826: byte (can_std_rx_desc_t *request +4)  [link a6; movea.l (0x8,a6),a2; (0x6,a2) data_ptr]
 0x222b4 (svc 0x41) cm550_canDiagnosticResponseSender: byte (can_std_rx_desc_t *request +4)  [link a6,#-28; movea.l (0x8,a6); returns 0xff / 8]
 0x22530 / 0x2257c / 0x225e0 / 0x22646 / 0x2268e: byte (can_std_rx_desc_t *request +4)  [link a6; movea.l (0x8,a6),a2]
 0x21642 writeJ1939DiagnosticMemoryByParameterId: byte (can_std_rx_desc_t *request +4, word parameter_id +8, dword offset +10, dword length +14)  [(8,a6) / (0xc,a6) word / (0xe,a6) / (0x12,a6)]
 0x2148a writeJ1939DiagnosticMemory: char (can_std_rx_desc_t *request +4, dword address +8, dword length +12)  [movem 8 regs: (0x24,a7) / (0x28,a7) / (0x2c,a7); (0x6,a2) / (0x4,a2)]
 0x224f4 (FUN_000224f4, NO ROW): byte (can_std_rx_desc_t *request +4, word parameter_id +8, dword offset +10, dword length +14) - read twin of 0x21642: cm550_lookupParameterIdAddress (0x10e16) -> 8, else bsr 0x2238e(request, address + offset, length). CM848 0x50c5d0 cm848_readJ1939DiagnosticMemoryByParameterId has the same steps -> shared name readJ1939DiagnosticMemoryByParameterId.
 0x2238e cm550_diagMemoryReadResponseBuilder: byte (can_std_rx_desc_t *request +4, dword address +8, dword length +12)  [movem 8: (0x24,a7) / (0x28,a7) / (0x2c,a7); returns 2 for length > 1764 ...; its 'return void' row is wrong: 0x224f4 / 0x22646 / 0x2268e return its d0 to the dispatcher]
 Already typed: 0x3216a cm550_diagnosticMultiPacketResponseBuilder (can_std_rx_desc_t*, word), 0x1ffd6 (can_std_rx_desc_t*, byte), 0x31b22.
- The transport receive path also feeds the dispatcher a can_std_rx_desc_t view: 0x22d0e pea (8,a4) after storing the reassembly buffer 0x8012de at (0xe,a4) = view+6.

## 0x224f4 (FUN_000224f4, no row) - read memory by parameter ID, TWIN of CM848 0x50c5d0
- Steps: lookup ID (0x10e16 cm550_lookupParameterIdAddress) -> 8; else bsr 0x2238e (request, address + offset, length). Callers: the three read-by-ID services 0x22530 / 0x2257c / 0x225e0 (twins of CM848 0x50c640 / 0x50c6a8 / 0x50c734, the only callers of CM848 0x50c5d0). Same as the write side (writeJ1939DiagnosticMemoryByParameterId shared).
- => readJ1939DiagnosticMemoryByParameterId (shared; CM848 row cm848_readJ1939DiagnosticMemoryByParameterId changes).

## CM848 DM1 builder asm check (0x24be8): byte swap of the table word (12/13 -> 8/9), slot-indexed store r29 + 4*slot - 2 (gaps), cap cmpwi r6,20 -> counterpart confirmed.

## FINAL NAME LIST
0x32244 initializePgn65234Dm10Handler (twin 0x24b64) | 0x323be cm550_initializePgn65226Dm1Handler | 0x33aea cm550_initializePgn65257FuelConsumptionHandler | 0x33064 initializePgn61443ElectronicEngineController2Handler (twin 0x25d60) | 0x33ce2 cm550_initializePgn65244IdleOperationHandler | 0x343d2 cm550_initializePgn65255VehicleHoursHandler | 0x31b22 cm550_sendPgn59392AcknowledgementMessage | 0x32b38 sendPgn65232NonContinuousMonitorTestResultMessage (twin 0x255c0) | 0x322ae keep cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage | 0x2ed6a cm550_getJ1587ReceivedParameterLength | 0x2edb2 cm550_getJ1587ReplyParameterLength | 0x2eea2 cm550_dispatchJ1939DiagnosticServiceRequest | 0x803613 j1939_pgn65270_exhaust_gas_temperature_low_byte (byte) | 0x80a9cc engine_retarder_command_source (ENGINE_RETARDER_COMMAND_SOURCE) | 0x3407a keep name, void(void) | extras 0x31b96 cm550_initializePgn59392AcknowledgementBuffer, 0x32b64 initializePgn65232Dm8Buffer (twin 0x2560c), 0x224f4 readJ1939DiagnosticMemoryByParameterId (twin 0x50c5d0).
All names checked unique in both firmwares (engine_retarder_command_source = the CM848 row of the same record).
