# Q2 describer notes (round 96)

## CM550 registration facts (disassembly, m68k.py)
- 0x2f47e (FUN_0002f47e, no row): count byte 0x801e1a (cmpi.b #0x20 / move.b / addq.b: BYTE, not word).
  count == 32 -> return 1; else idx = count, count += 1, entry = 0x801d5a + idx*6, entry.w = PGN key (arg word
  at sp+8 after the push of a2), entry+2 .l = handler; return 0. Same shape as registerJ1939ReceiveHandler
  (0x21272, 16 entries) and registerJ1939DiagnosticService (0x2ee62, 32 entries, byte key).
- 0x2f4be (cm550_FUN_0002f4be): rx+2 (destination) == j1939_engine_node_source_address (0x80da01) or 0xff ->
  scan count entries: entry byte 1 == data[0] and entry byte 0 == data[1] (the requested PGN's low and middle
  bytes; data[2] = data page is not compared) -> call handler(rx) and stop. No match and not global ->
  0x31b22(rx, 1) (cm550_diagnosticCanResponseSender, 1 = negative acknowledgement). No store before the call.
- 0x2f538 (cm550_diagnosticDataDump): registerJ1939ReceiveHandler(0xea00 = PGN 59904, 0x2f4be), then the responder
  registrations (list below).
- RAM dump: 0x801e1a = 24 (0x18). Table entries [0]..[23] listed in dump_tables.py output.

## Registered responders (RAM dump order; [n] = table index)
- [0] 65265 -> 0x31c84 (registered by 0x31ed2, not by 0x2f538)
- [1] 61443 -> 0x32e4c (registered by 0x33064, not by 0x2f538)
- [2] 65226 -> 0x322ae (registered by 0x323be, called earlier from elsewhere; 0x2f538 calls it again -> [18])
- [3] 65259 -> 0x32052 (by 0x320f6)   [4] 65253 -> 0x33716 (0x33754)   [5] 65262 -> 0x337c4 (0x33880)
- [6] 65257 -> 0x33a62 (0x33aea)      [7] 65244 -> 0x33c6c (0x33ce2)   [8] 65248 -> 0x34232 (0x3429a)
- [9] 65255 -> 0x34394 (0x343d2)      [10] 65260 -> 0x34430 NO ROW (0x34440)
- [11]-[17] direct from 0x2f538: 65252 0x33d38 / 65261 0x31f30 / 65263 0x33164 / 65264 0x33f5a / 65269 0x31bce /
  65270 0x33e58 / 65271 0x342f0
- [18] 65226 0x322ae (0x323be) [19] 65227 0x3241c (0x3252c) [20] 65228 0x2ef1c (0x2ef36) [21] 65229 0x3258a (0x329d2)
  [22] 65230 0x32a42 (0x32ae2) [23] 65234 0x32222 NO ROW (0x32244)

## Other functions in range
- 0x2ef08: registerJ1939ReceiveHandler(0xef00 = PGN 61184, 0x2eea2 cm550_diagnosticServiceDispatcher)
- 0x2efbc: registerJ1939ReceiveHandler(0xe300 = PGN 58112 DM7, 0x2ef4a)
- 0x2f114: registerJ1939ReceiveHandler(0xf002 = PGN 61442 ETC1, 0x2efd0)
- 0x2ef36: 0x2f47e(0xfecc = PGN 65228 DM3, 0x2ef1c)
- 0x2ef1c: 0x80de7a (diagnostic_clear_request_state) = 1; 0x31b22(rx, 0) (acknowledge)
- 0x2ef4a: DM7 receive handler: 0x801d3c = data[0] (test identifier); 0 with 0x60fa8 & 0x100 -> 0x32b38(0, 0x100);
  1 with & 0x200 -> 0x32b38(1, 0x200); else 0x31b22(rx, 1).

## CM848 side (cm848_rom.ghidra.cpp + disasm_func.py)
- 0x23188 cm848_j1939RegisterPgnHandler: count byte 0x3faa62 == 32 -> 1; else entry 0x3fa9a2 + count*6, count+1
  (stored first), sth key at +0, stw handler at +2, return 0. SAME steps / constants / order as CM550 0x2f47e -> TWIN.
- 0x231cc cm848_j1939DispatchPgnHandler: same as CM550 0x2f4be PLUS `stb 1 -> 0x40ad53` (j1939_dm1_active_flag)
  before the handler call; CM848's DM3 handler reads that flag to choose its NACK path -> COUNTERPART.
- 0x232b4 cm848_initJ1939ProtocolHandlers: registerJ1939ReceiveHandler(0xea00, dispatcher), initPgn65261CruiseControlSetupStruct,
  5 init handlers (65259 65262 65242 65248 65260), 7 direct (65261 65263 65264 65269 65270 65271 65504), 6 DM inits
  (DM1 DM2 DM3 DM4 DM5 DM10). CM550 0x2f538: same frame, 8 inits (65259 65253 65262 65257 65244 65248 65255 65260),
  7 direct (65252 65261 65263 65264 65269 65270 65271), same 6 DM inits -> COUNTERPART (different lists).
- 0x221f0 cm848_initJ1939DiagnosticServiceHandler = registerJ1939ReceiveHandler(0xef00, cm848_j1939DiagnosticServiceHandler)
  <-> CM550 0x2ef08 (0xef00, cm550_diagnosticServiceDispatcher).
- 0x22840 cm848_registerJ1939Dm7Handler = (0xe300, cm848_j1939HandlePgn58112Dm7) <-> CM550 0x2efbc (0xe300, 0x2ef4a).
- 0x23bb4 cm848_initJ1939AddressDispatcher = (0, cm848_dispatchTsc1ByDestinationAddress) <-> CM550 0x2fbb2 (0, 0x2fb70).
- 0x227a0 cm848_j1939HandlePgn58112Dm7 vs CM550 0x2ef4a: CM848 passes a monitor result to the DM8 sender and NACKs
  only test IDs 0/1 (id < 2); CM550 passes the mask word (0x100 / 0x200) and NACKs every other ID -> COUNTERPART.
- 0x2346c cm848_decodeRetarderTorqueRequestPercent == CM550 0x2f606 (<25 -> 100, <125 -> 125 - raw, else 0) -> TWIN.
- 0x234a4 cm848_selectEngineRetarderStagePercent ~ CM550 0x2f632 (j1939FormatMultiFrameResponse): same steps and
  constants (0 / mode 3 & >99 -> 100 / full scale stage 6 [4] or stage 4 [4] when 4 stages / req*full/100 / stage 1-5
  lookups at engine speed / 17 33 50 67 83 100, mode 2 rounds up). Lookup call convention differs per platform.
- 0x23b38 cm848_dispatchTsc1ByDestinationAddress == CM550 0x2fb70 (engine SA or 0xff -> processEngineTsc1Request;
  retarder SA or 0xff -> retarder handler) -> TWIN candidate.
- 0x236f0 cm848_processEngineRetarderTsc1Request ~ CM550 0x2f7e6 (cm550_retarderControlModeHandler): COUNTERPART
  (CM848 masks j1939_blocked_message_bits on mode 0, goto for the same controlling sender, ...).
- 0x23a9c cm848_initializeEngineRetarderTsc1RequestState vs CM550 0x2faa4: CM848 torque limit = 100, CM550 = 125
  (0x7d); CM550 fills five 1-D lookup records (axis / values pointers + offset 2), CM848 sets five cache words -> COUNTERPART.

## Responder twins proven at the instruction level
- [17] CM550 0x342f0 (cm550_retarderDataBuilder) <-> CM848 0x26cf0 cm848_j1939HandlePgn65271VehicleElectrical: both
  copy the battery voltage word into a local, local = local*20 >> 3 (CM550: lsl2 / add / lsl2 / lsr3; the decompiler
  shows *5>>1), byte-swap the local, store the word at payload+4 (CM550 0x80367e = data 0x80367a + 4: bytes 5-6 =
  SPN 168 battery potential), send the 65271 descriptor. TWIN. Also scheduled every 1000 ms from 210 ms (CM550).
- [23] CM550 0x32222 (no row) <-> CM848 0x24b28 cm848_j1939HandlePgn65234Dm10: byte swap of
  supported_non_continuous_monitors_bits -> DM10 payload word (CM550 0x801f4c) -> send j1939_dm10_tx_message. TWIN.
- [10] CM550 0x34430 (no row) <-> CM848 0x26db4 cm848_j1939HandlePgn65260VehicleId: one send of
  j1939_pgn65260_tx_message (CM550 0x80369c). TWIN (the set-ups differ: CM848 copies the VIN + '*' into RAM, 21 bytes;
  CM550 points at vehicle_vin_string_cal, 20 bytes).
- precedent: sendPgn61444ElectronicEngineController1Message is a twin although CM550 sends with cm550_sendCanMessage.

## 65244 (IO) responder 0x33c6c (cm550_ioControlDataBuilder)
- bytes 1-4 (0x8035de) = byteSwap32(scale(idle fuel 0x804fb8 >> 2, 3785411, 1000000)): e2m 117F +18 TIGAIST2 'ACCUMULATED
  AMOUNT OF FUEL USED DURING VEHICLE OPERATION WHILE UNDER I(DLE)' (0.125 gal) -> SPN 236 total idle fuel (0.5 L).
- bytes 5-8 (0x8035e2, misnamed protection_state_enable_flags) = byteSwap32(scale(0x804fb4, 20, 36000)): 117F +14 TITMIS
  'ACCUMULATED TIME OF OPERATION OF THE ENGINE WHILE UNDER IDLE CONDITION' (0.1 s) -> SPN 235 total idle hours (0.05 h).
- sends j1939_pgn65244_tx_message. Not scheduled (request only). CM848: no 65244 registration.

## More responder comparisons
- [0] 0x31c84 (j1939HandlePgn65265CruiseVehicleSpeed, unprefixed, no CM848 namesake) vs CM848 0x24178
  cm848_buildPgn65265CruiseControlVehicleSpeedMessage: CM848 gates on datalink source bits / enables, speed x412>>16;
  CM550 x103>>6 (mph -> km/h), switch status word bits -> COUNTERPART. Also scheduled every 100 ms from 70 ms.
- [1] 0x32e4c (j1939HandlePgn61443Eec2) vs CM848 0x25b10 cm848_buildPgn61443ElectronicEngineController2Message:
  CM848 tests fault_detected_cal bits, CM550 (status & bit) && (processing enable & bit) pairs and
  idle_switch_override_enable -> COUNTERPART. Scheduled every 50 ms from 10 ms.
- [2]/[18] DM1 0x322ae vs CM848 0x24be8 (shared name j1939HandlePgn65226Dm1ActiveDtc): CM848's loop has a 2nd bound
  `cmpwi r6,20; ble` (<= 20 entries); CM550's loop only the list count (cmp.b 0x8058d4). Near-twin.
- [19] DM2 0x3241c vs CM848 0x24e78: same relation as DM1 (CM848 `cmpwi r7,20`; CM550 only cmp.b 0x8058f4).
- [12] 65261 0x31f30 vs CM848 0x246fc (shared j1939HandlePgn65261CruiseControlSetup): CM848 gates byte 1 on
  road_speed_governor_enable and bytes 2-3 on cruise_control_enable; CM550 checks only < 0x9e01 -> COUNTERPART.
- [22] DM5 0x32a42 (vp44_diagnosticDM5DataBuilder) vs CM848 0x25458 cm848_j1939HandlePgn65230Dm5Readiness: same steps
  (counts, 0x60fa5, 0x60fa7, swapped 0x60fa8, local 0x1000 / & 0xfeff from 0x80da0e and bit 0x100) -> TWIN. Nothing VP44.
- [20] DM3 0x2ef1c vs CM848 0x22674: CM848 gates (not_safe_to_program, key switch, obd enable), runs a clear state
  machine and picks ACK vs NACK sender by j1939_dm1_active_flag; CM550 sets state 1 and sends ACK type 0 -> COUNTERPART.
- DM8 sender CM550 0x32b38 (vp44_diagnosticByteResponseSender) = test id + byteSwap16(value) -> PGN 65232, the counterpart
  of cm848_sendPgn65232NonContinuousMonitorTestResultMessage (CM848 copies the value to a local first).

## Remote throttle (0x2ec50 / 0x2ed62)
- 0x2ec50 (from cm550_runEvery4FramesTaskSetPhase0): flags_18 bit 0x1000 off -> release (priority 0x80aa90 == remote
  priority 0x8089a4 -> priority 0, alternate 0x80aa8e = 0). Bit 0x2000 off -> switch 20 (0x80bcd0 bit 3, e2m DS20SWSS)
  on: claim (priority < remote -> priority = remote, alternate = remote throttle 0x80a3a4 ADROTHFT); off: release.
  Bit 0x2000 on: latch 0x801c78 (remote_throttle_active_flag) set when remote <= calculated (0x80aa92) and switch on,
  cleared when calculated <= remote and switch off; with status word 3 bit 0x800 set and 0x806046 bit 0x800 clear,
  cleared when calculated <= remote. Latch 1 -> claim, else release.
  CM848: cm848_claimRemoteThrottleOverride (0x50e610) + cm848_verifyRemoteThrottleTransition (0x50e534) -> COUNTERPART
  (CM848 also mirrors fault bits; CM848 does not release - cm848_selectCommandedThrottle resets the claim).
- 0x2ed62: clr.w 0x801c78; called from mc68k_applicationMain (0x28830). Counterpart: cm848_initializeRemoteThrottle
  (which also clears fault bits 171/172 when the feature is off).
- 0x801c78 plays CM848's remote_throttle_transition_verified_flag role.

## TSC1 / retarder chain (asm-checked)
- 0x2fb70 == CM848 0x23b38 (dest byte rx+2; engine SA 0x80da01 / CM848 0x40ad74 low byte, or 0xff -> processEngineTsc1Request;
  retarder SA 0x80da0b / 0x40ad7e, or 0xff -> retarder processor) TWIN.
- 0x2fbb2 == CM848 0x23bb4: registerJ1939ReceiveHandler(0, the dispatcher) TWIN.
- 0x2f606 == CM848 0x2346c (<25 -> 100, >=125 -> 0, else 125 - x) TWIN; called by bsr.w from 0x2f7e6 (modes 2 and 3).
- 0x2f632 ~ CM848 0x234a4: req 0x80d9f2 == 0 -> 0; mode 0x80d9e4 == 3 && req >= 100 -> 100; count 0x801e28 == 4 ?
  0x6055a (stage 4 [4]) : 0x6056e (stage 6 [4]) -> 0x801e2c (CM848 the same if/else on 0x3faa72 with 0x5a456 / 0x5a46a);
  0x801e26 = req * full / 100; stage 1..5 lookups (record x_input = engine_rpm_primary 0x80ccf6); 17/33/50/67/83/100.
  TWIN (the lookup call follows each platform's API). Only caller 0x2f7e6 (bsr.w).
- 0x2faa4: 0x80d9ee = 125, 0x80d9e4 = 0, 0x80d9e6 = 0, 0x801e28 = sum of words 0x808200..0x80820a, five lookup records.
  CM848 0x23a9c writes 100 (li r11,100) -> COUNTERPART. Caller mc68k_initializeJ1939Datalink (0x28c1e).
- 0x2f7e6 vs CM848 0x236f0: COUNTERPART (CM848 masks j1939_blocked_message_bits on mode 0, other state words).
- CM550 retarder TSC1 bytes (no rows): 0x801e1c controlling priority bits (CM848 engine_retarder_controlling_override_priority_bits),
  0x801e1d controlling torque byte (..._controlling_tsc1_torque_byte), 0x801e1e received control byte
  (engine_retarder_received_tsc1_control_byte), 0x801e21 received torque byte (engine_retarder_received_tsc1_torque_byte).

## PGN 61184 / DM7 / ETC1 wrappers
- CM848 0x22128 cm848_j1939DiagnosticServiceHandler returns early with no answer for the response service bytes;
  CM550 0x2eea2 has no such check -> COUNTERPART; so 0x2ef08 vs 0x221f0 COUNTERPART.
- CM848 0x22bc4 cm848_initJ1939Pgn61442Etc1Handler also starts ETC1 timers and clears fault bits -> 0x2f114 COUNTERPART.
- 0x2efbc vs CM848 0x22840 cm848_registerJ1939Dm7Handler: the DM7 handlers are counterparts -> COUNTERPART.

## Descriptor initializers the registration list calls (outside the range; header / length / responder)
- 0x320f6 65259 len 40 -> 0x32052 | 0x33880 65262 len 8 -> 0x337c4 | 0x33aea 65257 len 8 -> 0x33a62 (name says 65249!)
- 0x33ce2 65244 len 8 -> 0x33c6c | 0x3429a 65248 len 8 -> 0x34232 | 0x343d2 65255 len 8 (bytes 1-4 0xffffffff) -> 0x34394
- 0x323be DM1 -> 0x322ae (name says engine coolant!) | 0x3252c DM2 -> 0x3241c | 0x32ae2 DM5 len 8 -> 0x32a42
- 0x32244 DM10 len 2 -> 0x32222 (name says DM11!) | 0x33064 61443 -> 0x32e4c (name says proprietary DM 983!)
- 0x31fee initPgn65261CruiseControlSetupStruct: 65261 descriptor only, no registration (0x2f538 registers 0x31f30 itself).
- 0x323be is called twice (mc68k_initializeJ1939Datalink 0x28c4e and 0x2f538) -> DM1 at entries 2 and 18.

## Count / table facts
- 0x801e1a: all accesses byte (cmpi.b / move.b / addq.b / cmp.b), 0x801e1b no reference -> byte count + pad.
- 0x801d3c: byte, written only by 0x2ef4a (DM7 test identifier) -> CM848's j1939_dm7_test_identifier role.
- CM550 has no J1939_ACK_TYPE enum: cm550_diagnosticCanResponseSender type 0 from 0x2ef1c (ACK), 1 from 0x2ef4a / 0x2f4be (NACK).

## Final proposals (all names checked FREE in both firmwares with check_names.py)
- twins (both rows): 0x2f47e/0x23188 registerJ1939RequestResponder; 0x2f606/0x2346c decodeRetarderTorqueRequestPercent;
  0x2f632/0x234a4 selectEngineRetarderStagePercent; 0x2fb70/0x23b38 dispatchTsc1ByDestinationAddress;
  0x2fbb2/0x23bb4 registerJ1939Tsc1ReceiveHandler; 0x342f0/0x26cf0 buildPgn65271VehicleElectricalPower1Message;
  0x32222/0x24b28 j1939HandlePgn65234Dm10TestIdentifiersSupport; 0x34430/0x26db4 j1939HandlePgn65260VehicleIdentification;
  0x32a42/0x25458 j1939HandlePgn65230Dm5DiagnosticReadiness.
- counterparts (cm550_): 0x2f4be cm550_dispatchJ1939Request; 0x2f538 cm550_registerJ1939RequestResponders;
  0x2ec50 cm550_updateRemoteThrottleOverrideClaim; 0x2ed62 cm550_initializeRemoteThrottle; 0x2eea2 cm550_dispatchJ1939DiagnosticService;
  0x2ef08 cm550_registerJ1939DiagnosticServiceDispatcher; 0x2ef1c cm550_j1939HandlePgn65228Dm3ClearInactiveFaults;
  0x2ef36 cm550_registerPgn65228Dm3RequestResponder; 0x2ef4a cm550_receivePgn58112Dm7TestCommandMessage;
  0x2efbc cm550_registerJ1939Dm7Handler; 0x2f114 cm550_registerPgn61442ElectronicTransmissionController1Handler;
  0x2f7e6 cm550_processEngineRetarderTsc1Request; 0x2faa4 cm550_initializeEngineRetarderTsc1RequestState;
  0x31c84 cm550_buildPgn65265CruiseControlVehicleSpeedMessage; 0x32e4c cm550_buildPgn61443ElectronicEngineController2Message;
  0x31f30 cm550_buildPgn65261CruiseControlVehicleSpeedSetupMessage (flag); 0x3241c cm550_j1939HandlePgn65227Dm2PreviouslyActiveDtc.
- none: 0x2ed6a cm550_getJ1587RequestParameterLength; 0x2edb2 cm550_getJ1587ResponseParameterLength;
  0x33c6c cm550_buildPgn65244IdleOperationMessage.
- globals: 0x801d5a j1939_request_responder_table (entry_t[32]); 0x801e1a j1939_request_responder_count (byte);
  0x801d3c j1939_dm7_test_identifier (byte).

## J1587 helpers in range (no CM848 counterpart: CM848 has no J1708)
- 0x2ed6a cm550_insiteParameterParser: length of the J1587 parameter at the request read pointer: PID < 128 -> 2,
  < 192 -> 3, < 254 -> count byte + 2 (20 when count >= 19), 254/255 -> 0. Caller: J1708 request parser 0x1e956.
- 0x2edb2 cm550_parameterLookupForInsite: response length of the requested PID: <128 -> 2, <192 -> 3, 193 -> active
  count + 2, 194 -> 2 x (count + queue) + 2 or 3 x (inactive + active) + 2, 196 -> 4 / 2 / 7, 234 -> 24, 237 -> 22,
  243 -> 31, else 6. Callers 0x1e956 (x3) and 0xec1e.
