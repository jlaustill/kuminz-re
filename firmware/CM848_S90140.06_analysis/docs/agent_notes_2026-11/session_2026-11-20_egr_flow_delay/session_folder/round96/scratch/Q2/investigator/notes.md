# Q2 investigator notes (round 96)

## Registration machinery (sure)
- 0x2f47e (no row): PGN 59904 request responder registrar. a1=0x801e1a; cmpi.b #0x20,(a1) -> full returns 1;
  else d0=count, addq.b #1 (count), entry = 0x801d5a + count*6, move.w pgn (sp+8) -> entry+0, move.l handler (sp+0xa) -> entry+2,
  clr.b d0 (returns 0). Count is a BYTE (cmpi.b / move.b / addq.b at 0x2f486/0x2f492/0x2f494; move.b (a4) at 0x2f4e8, cmp.b (a4) 0x2f518).
  CM848 0x23188 cm848_j1939RegisterPgnHandler: lbz count 0x3faa62; cmpwi 32 -> li r3,1; entry = 0x3fa9a2 + count*6; stb count+1;
  sth pgn ->+0; stw handler ->+2; li r3,0. SAME steps/order/constants -> TWIN.
- 0x2f4be: PGN 59904 request dispatcher (registered by 0x2f538 for 0xea00 with registerJ1939ReceiveHandler 0x21272).
  DA (msg+2) == j1939_engine_node_source_address (0x80da01) or 0xff -> scan entries: entry[1]==data[0] && entry[0]==data[1] -> jsr handler(msg), break.
  If index==count and DA != 0xff -> 0x31b22 (msg, 1) NACK.
  CM848 0x231cc cm848_j1939DispatchPgnHandler: same, BUT stores 1 to 0x40ad53 (j1939_dm1_active_flag) before blrl (0x2324c-0x23250).
  -> COUNTERPART (one extra step in CM848).
- 0x2f538 (cm550_diagnosticDataDump): registers 0x2f4be for 0xea00, calls initPgn65261CruiseControlSetupStruct, 9 initializers, 7 direct
  registrations (fee4 feed feef fef0 fef5 fef6 fef7), then the DM initializers DM1/DM2/DM3/DM4/DM5/DM10.
  CM848 0x232b4 cm848_initJ1939ProtocolHandlers: the same shape but other sets (5 initializers 65259 65262 65242 65248 65260;
  direct feed feef fef0 fef5 fef6 fef7 ffe0; DM1 DM2 DM3 DM4 DM5 DM10). -> COUNTERPART.
- Table 0x801d5a: 32 x 6 bytes (0x801d5a + 0xc0 = 0x801e1a = the count byte). CM848 j1939_pgn_dispatch_table 0x3fa9a2 + 0xc0 = 0x3faa62.

## Registrations (registrations.py output)
see registrations.py; 23 request responders.

## Scope decisions
- Batch Q1 (make_workflow_r96.py) names the PERIODIC builders: 65265 0x31c84, 61443 0x32e4c, 65262 0x337c4, 65252 0x33d38,
  65263/65264/65269/65270, 65271 0x342f0 (cm550_retarderDataBuilder). They are also request responders -> list them, names
  consistent with Q1's scheme (<prefix>_buildPgn<N><J1939 name>Message; twins unprefixed), flag the overlap.
- 23 request registrations (registrations.py). Extra in-range wrappers: 0x2ef08 (61184), 0x2ef36 (DM3 request), 0x2efbc (DM7),
  0x2f114 (61442), 0x2fbb2 (PGN 0), 0x2fb70 (TSC1 destination dispatcher).

## Per-function facts (sure)
- 0x2ef1c DM3 responder: diagnostic_clear_request_state (0x80de7a, word) = 1 (CLEAR_INACTIVE), 0x31b22(msg, 0) = positive ACK.
  CM848 0x22674 has a gate + state transitions + ACK/NACK by j1939_dm1_active_flag -> COUNTERPART.
- 0x2ef36 registers 0x2ef1c for 0xfecc via 0x2f47e; CM848 0x22770 cm848_initPgn65228Dm3Handler: bl 0x23188 (65228, 0x22674). TWIN wrapper.
- 0x2fbb2: pea 0x2fb70; clr.w -(a7); jsr 0x21272 (PGN 0). CM848 0x23bb4: li r3,0; r4=0x23b38; bl 0x538eb0. TWIN wrapper.
- 0x2fb70: DA=msg+2; ==0x80da01 (engine SA) or 0xff -> processEngineTsc1Request 0x2f128; ==0x80da0b (retarder SA) or 0xff -> 0x2f7e6.
  CM848 0x23b38: same order/constants (-> 0x22d60 processEngineTsc1Request, 0x236f0 retarder). TWIN.
- 0x2ef4a DM7 (PGN 58112) receive handler (registered by 0x2efbc for 0xe300 with 0x21272): 0x801d3c = data[0] (test id);
  id 0 & JCNTCTMR bit 0x100 -> DM8 sender 0x32b38(0, 0x100); id 1 & bit 0x200 -> 0x32b38(1, 0x200); ELSE NACK 0x31b22(msg,1).
  CM848 0x227a0: sends monitor RESULTS (intake air heater / misfire), NACK only when id < 2 -> COUNTERPART.
  0x801d3c = CM848 j1939_dm7_test_identifier (0x3fa97a) role.
- 0x32222 DM10 responder (no row): 0x801f4c = byteSwap16(&supported_non_continuous_monitors_bits 0x60fa8); cm550_sendCanMessage(0x801f3e).
  CM848 0x24b28: payload = reverseByteOrder16(&supported bits); send(&j1939_dm10_tx_message). TWIN.
  Initializer 0x32244 (cm550_diagnosticDM11PGN_65234_Builder) = twin of CM848 0x24b64 cm848_initializePgn65234Dm10Handler (lead).
- 0x31f30 (shared j1939HandlePgn65261CruiseControlSetup) vs CM848 0x246fc: CM550 encodes RSMXRZ 0x80a9dc / CRMXRZ 0x804fc6 / CRMNRUVS 0x807bf6
  (each <0x9e01 -> x*0xa1/100>>8 else 0xff) unconditionally; CM848 gates bytes by road_speed_governor_enable / cruise_control_enable.
  -> COUNTERPART: both rows need a prefix (CM848 row via cm848_functions).
- 0x322ae (shared j1939HandlePgn65226Dm1ActiveDtc) vs CM848 0x24be8: CM848 has the 20-slot cap (cmpwi r6,20 at 0x24d54) and a byte shuffle
  of the DTC word (0x24ce4-0x24d04); CM550 neither (0x3230c-0x323aa) -> COUNTERPART: prefix both.
- 0x3241c (cm550_previousDtcListBuilder) DM2 vs CM848 0x24e78: same differences as DM1 -> COUNTERPART.
- 0x32a42 (vp44_diagnosticDM5DataBuilder) DM5 vs CM848 0x25458 cm848_j1939HandlePgn65230Dm5Readiness: step-for-step the same
  (counts 0x8058d4/0x8058f4, JCOBDG low byte 0x60fa5, JCCTMR low byte 0x60fa7, swap JCNTCTMR, heater result 0x80da0e ==1 / bit 0x100
  -> 0x1000 / &0xfeff, swap, send 0x80344a) -> TWIN.
- CM550 globals: 0x80da0e = e2m 1227 +0 JCGPSS (CM848 intake_air_heater_monitor_result 0x40ad82), word (cmpi.w/tst.w 0x32a94/0x32aae);
  0x60fa4 = 1228 +4 JCOBDG (CM848 obd_compliance_code 0x5a490) word; 0x60fa6 = 1228 +6 JCCTMR (CM848 supported_continuous_monitors_bits) word.
- 0x2f606 retarder torque decode (bsr from 0x2f980 mode 2 and 0x2fa5a mode 3 in 0x2f7e6): <25 ->100; >=125 -> 0; else 125-x.
  CM848 0x2346c cm848_decodeRetarderTorqueRequestPercent: cmpwi 25/bge, li 100; cmpwi 125/blt, li 0; subfic 125. Same order, called twice
  by cm848_processEngineRetarderTsc1Request -> TWIN (shared decodeRetarderTorqueRequestPercent).
- 0x2faa4 (from mc68k_initializeJ1939Datalink 0x28c1e right after cm550_initializePgn65249RetarderConfigurationBuffer 0x341e6):
  retarder_torque_percent=125, mode=0, device=0, 0x801e28 = sum of the 6 cylinder-brake counts 0x808200-0x80820a, five lookup records
  (axis 0x6052a, values 0x60534/3e/48/52/5c, offset 2). CM848 0x23a9c: limit=100 (not 125), offsets only -> COUNTERPART
  (cm550_initializeEngineRetarderTsc1RequestState).
- 0x801e28: written 0x2faf8 (sum), read cmpi.w #4 at 0x2f678 in 0x2f632 -> CM848 engine_retarder_stage_count (0x3faa72) role. word.
- 0x2f632 (j1939FormatMultiFrameResponse - wrong) = counterpart of CM848 0x234a4 cm848_selectEngineRetarderStagePercent.
- 0x2f7e6 (cm550_retarderControlModeHandler) = counterpart of CM848 0x236f0 cm848_processEngineRetarderTsc1Request
  (CM848 extra j1939_blocked_message_bits / speed control flag steps).
- 0x2ec50 remote throttle claim/release (20 ms task set): reads algorithm_enable_flags_18_cal 0x803cb8 bits 0x1000/0x2000, RMTHSW
  (0x80bcd0 bit 3, e2m 000E +2), CTRMTHPZ priority 0x8089a4, remote_throttle_sensor_state.filtered_value 0x80a3a4,
  calculated_commanded_throttle 0x80aa92, fault word 3 bit 0x800 (0x806006 / 0x806046); writes alternate_throttle_priority 0x80aa90,
  alternate_throttle 0x80aa8e, remote_throttle_active_flag 0x801c78. CM848 splits it: cm848_verifyRemoteThrottleTransition +
  cm848_claimRemoteThrottleOverride (mirrors fault bits, never releases) -> COUNTERPART (cm550_claimRemoteThrottleOverride).
- 0x2ed62: clr.w 0x801c78; from mc68k_applicationMain 0x2882e. CM848 0x50e768 cm848_initializeRemoteThrottle also clears fault bits
  171/172 -> COUNTERPART (cm550_initializeRemoteThrottle).
- Wrappers: 0x2ef08 (61184 -> 0x2eea2) twin of CM848 0x221f0; 0x2efbc (58112 -> 0x2ef4a) twin of CM848 0x22840;
  0x2f114 (61442 only) counterpart of CM848 0x22bc4 (also initializes ETC1 state).
- 0x34430 VI responder: pea 0x80369c; jsr 0x104e8; rts (ends 0x3443e; only reference = the pea at 0x34484). CM848 0x26db4: one call
  cm848_sendJ1939Message(0x3faef8). TWIN.
- 0x33c6c PGN 65244 IO: bytes 1-4 0x8035de = swap32(scale(TIGAIST2 0x804fb8 >> 2, 3785411, 1000000)) SPN 236 0.5 L;
  bytes 5-8 0x8035e2 (protection_state_enable_flags - wrong) = swap32(scale(TITMIS 0x804fb4, 20, 36000)) SPN 235 0.05 h. CM848: none.

## RAM dump check (J90350.00.ram.bin)
- 0x801e1a = 24 (byte; 0x801e1b = 0). Entries 0-23: 65265 0x31c84, 61443 0x32e4c, 65226 0x322ae, 65259, 65253, 65262, 65257, 65244, 65248,
  65255, 65260 0x34430, 65252, 65261, 65263, 65264, 65269, 65270, 65271, 65226 0x322ae (again), 65227, 65228 0x2ef1c, 65229, 65230, 65234 0x32222.
  DM1 is registered twice (datalink init + 0x2f538), like CM848 ("entries 2 and 15"). Entries 24-31 zero.
- 0x801e28 = 6 (six words of 1 at 0x808200). 0x80d9ee = 0x7d. retarder SA 0x80da0b = 0x29 (41). algorithm_enable_flags_18_cal = 0x303a.
- TITMIS 0x804fb4 = 167363181 (4649 h) vs TITMT2 12566.8 h; TIGAIST2 0x804fb8 = 11708 (1463.5 gal) -> idle hours / idle fuel.

## Decided names (functions)
twins (shared, both rows): 0x2f47e/0x23188 registerJ1939PgnRequestHandler; 0x2f606/0x2346c decodeRetarderTorqueRequestPercent;
 0x2fb70/0x23b38 dispatchTsc1ByDestinationAddress; 0x2fbb2/0x23bb4 registerTsc1DestinationAddressDispatcher;
 0x2ef08/0x221f0 registerJ1939DiagnosticServiceDispatcher; 0x2efbc/0x22840 registerJ1939Dm7Handler; 0x2ef36/0x22770 registerJ1939Dm3RequestHandler;
 0x32222/0x24b28 buildPgn65234Dm10TestIdentifiersSupportMessage; 0x32a42/0x25458 buildPgn65230Dm5DiagnosticReadiness1Message;
 0x34430/0x26db4 sendPgn65260VehicleIdentificationMessage.
counterparts: 0x2f4be cm550_dispatchJ1939PgnRequest; 0x2f538 cm550_registerJ1939PgnRequestHandlers; 0x2ec50 cm550_claimRemoteThrottleOverride;
 0x2ed62 cm550_initializeRemoteThrottle; 0x2ef4a cm550_receivePgn58112Dm7CommandNonContinuouslyMonitoredTestMessage;
 0x2faa4 cm550_initializeEngineRetarderTsc1RequestState; 0x2f114 cm550_registerJ1939ElectronicTransmissionController1Handler;
 0x2f632 cm550_selectEngineRetarderStagePercent; 0x2f7e6 cm550_processEngineRetarderTsc1Request; 0x2ef1c cm550_j1939HandlePgn65228Dm3ClearInactiveFaults;
 0x31f30 cm550_buildPgn65261CruiseControlVehicleSpeedSetupMessage; 0x322ae cm550_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage;
 0x3241c cm550_buildPgn65227Dm2PreviouslyActiveDiagnosticTroubleCodesMessage; 0x342f0 cm550_buildPgn65271VehicleElectricalPower1Message;
 0x31c84 cm550_buildPgn65265CruiseControlVehicleSpeedMessage; 0x32e4c cm550_buildPgn61443ElectronicEngineController2Message.
standalone: 0x33c6c cm550_buildPgn65244IdleOperationMessage. Round 95 names kept for the rest.
CM848-only: 0x246fc -> cm848_buildPgn65261CruiseControlVehicleSpeedSetupMessage; 0x24be8 -> cm848_buildPgn65226Dm1ActiveDiagnosticTroubleCodesMessage;
 0x231cc -> cm848_dispatchJ1939PgnRequest; 0x232b4 -> cm848_registerJ1939PgnRequestHandlers.
All names grep-unique (checked).

## Structs (for notes)
- j1939_pgn_handler_entry_t (copy CM848's to CM550, portable): +0 pgn_byte_1 byte 1 (PGN bits 8-15, compared with request data byte 1),
  +1 pgn_byte_0 byte 1 (PGN bits 0-7, compared with data byte 0), +2 handler_func dword 4. Size 6. CM550 global 0x801d5a [32].
- j1939_pgn65230_payload_t (new, both): +0 active_trouble_code_count byte, +1 previously_active_trouble_code_count byte,
  +2 obd_compliance byte, +3 continuously_monitored_systems_support byte, +4 non_continuously_monitored_systems_support word,
  +6 non_continuously_monitored_systems_status word. CM550 0x803458 (absorbs 0x80345a / 0x80345c rows), CM848 0x3fad56 (absorbs 0x3fad5a / 0x3fad5c).
- j1939_ccss_tx_payload_t (CM848's, copy to CM550): 8 byte fields. CM550 0x801efa, CM848 0x3fab0a (no row yet).
## Globals decided
CM550: 0x801d5a j1939_pgn_dispatch_table; 0x801e1a j1939_pgn_handler_count byte; 0x801d3c j1939_dm7_test_identifier byte;
 0x801f4c j1939_dm10_payload word; 0x803458 j1939_pgn65230_payload; 0x801efa j1939_pgn65261_payload; 0x80da0e intake_air_heater_monitor_result word;
 0x60fa4 obd_compliance_code word; 0x60fa6 supported_continuous_monitors_bits word; 0x8035de j1939_pgn65244_total_idle_fuel_used dword;
 0x8035e2 j1939_pgn65244_total_idle_hours dword; 0x804fb8 total_idle_fuel_consumed dword; 0x804fb4 total_idle_operating_time dword;
 0x801e28 engine_retarder_stage_count word; 0x80a9dc maximum_road_speed word (RSMXRZ = CM848 Max_Road_Speed);
 0x804fc6 cruise_maximum_road_speed word (CRMXRZ; outside EEPROM image -> no _cal); 0x807bf6 cruise_speed_low_limit word (CRMNRUVS = CM848's).
CM848: 0x3fad56 j1939_pgn65230_payload; 0x3fab0a j1939_pgn65261_payload.

## Status
All functions decided (39 rows in functions[], 4 CM848-only renames, 19 globals, 3 CM848 enum member fixes, 4 CM550 prototypes).
Funcdef rows to retarget on rename: CM550 0x2f4be, 0x2f606, 0x2ef4a (replace); CM848 0x23188, 0x231cc, 0x23b38 (two duplicate rows, lines 87/244), 0x221f0.
Leads: wrong-named set-ups 0x320f6 0x32244(twin of 0x24b64) 0x323be 0x3252c 0x32ae2(twin of 0x2553c) 0x33064 0x33880 0x33aea(65257!) 0x33ce2 0x3429a 0x343d2;
 0x31b22 = PGN 59392 acknowledgement sender; 0x32b38 = DM8 sender (twin candidate of CM848 0x255c0); 0x21272 has no CM550 prototype.
