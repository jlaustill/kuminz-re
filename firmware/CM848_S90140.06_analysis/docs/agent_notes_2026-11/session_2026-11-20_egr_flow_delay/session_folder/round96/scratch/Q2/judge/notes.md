# Q2 judge notes (round 96)

## Core (verified by own disassembly)
- 0x2f47e (no Ghidra function now; export prints FUN_0002f47e()): count BYTE 0x801e1a (cmpi.b #0x20 / move.b / addq.b),
  ==32 -> moveq #1; else idx=count, count+1, entry=0x801d5a+6*idx, move.w (8,a7)->+0, move.l (0xa,a7)->+2, clr.b d0.
  CM848 0x23188: lbz 0x3faa62, cmpwi 32 -> li 1; mulli 6 + 0x3fa9a2; stb count+1; sth +0; stw +2; li 0. TWIN confirmed.
  Callers: 16 jsr abs + movea.l #0x2f47e,a2 at 0x2f53a (7 jsr (a2)) = 23 sites; 0x323be runs twice -> 24 entries.
- 0x2f4be: dest (0x2,a3) == 0x80da01 or 0xff; loop entry+1 vs data[0], entry+0 vs data[1]; jsr handler(rx); no match & dest!=0xff -> 0x31b22(rx,1).
  CM848 0x231cc same + stb 1 -> 0x40ad53 (j1939_dm1_active_flag) before blrl -> COUNTERPART confirmed.
- 0x2f538: registerJ1939ReceiveHandler(0xea00,0x2f4be); 0x31fee; 8 set-ups 320f6 33754 33880 33aea 33ce2 3429a 343d2 34440;
  7 direct fee4 feed feef fef0 fef5 fef6 fef7; lea 0x30; DM 323be 3252c 2ef36 329d2 32ae2 32244. Only caller 0x28e2c.
  CM848 0x232b4: same frame; set-ups 24940 2619c 268ac 26c6c 26ddc; direct feed feef fef0 fef5 fef6 fef7 ffe0; DM 24dd8 25000 22770 25094 2553c 24b64. COUNTERPART.
- RAM dump: count 0x18, entries 0-23 as listed by investigator (DM1 at 2 and 18). Entries 24-31 zero.
- Export: ExportAnalysis exports every Ghidra function; ImportAnalysis creates a function for a row with no function (disassemble + createFunction).

## STALE TYPES (frozen copies predate round 96 stage C, commit 7b3c9fd3; HEAD = 0d4cafee stage D)
- Stage C map: j1939_rx_msg_t->j1939_received_message_t, j1939_tx_msg_t->j1939_transmit_message_t, j1939_msg_hdr_t->j1939_message_header_t,
  can_rx_channel_t->can_receive_channel_t, j1939_ccss_tx_payload_t->j1939_pgn65261_payload_t (CM848). CM550 can_std_rx_desc_t unchanged.
- HEAD CM848 already has 0x003fab0a j1939_pgn65261_payload (j1939_pgn65261_payload_t). -> CM848 global proposal already applied; type name stale.
- CM550 has neither j1939_pgn65261_payload_t nor j1939_pgn_handler_entry_t at HEAD (both must be added as portable struct rows).
- Function names: frozen == HEAD in both firmwares.

## Remote throttle
- 0x2ec50: asm agrees with both agents. 0x80bcd0 bit 3 = RMTHSW (mask 08) = DS20SWSS (mask 08): switch 20 IS the remote throttle switch.
  CM550 selection (0x10580 area) also resets alternate_throttle_priority to 0 after it takes the claim, so the "claim" stem is the role -> keep investigator name.
- 0x2ed62: clr.w 0x801c78 only; caller mc68k_applicationMain 0x2882e. CM848 0x50e768 clears flag + fault bits when disabled -> counterpart OK.

## Wrappers (asm checked)
- 0x2ef08 (0xef00,0x2eea2) / CM848 0x221f0 (61184,0x22128): first registration in both start-ups. Twin by registerJ1939DiagnosticHandlers precedent
  (registered handler a counterpart is OK; twin rests on the registrar's own code).
- 0x2fbb2 (0,0x2fb70) / 0x23bb4 (0,0x23b38): second. Twin.
- 0x2f114 (0xf002,0x2efd0) / 0x22bc4 (extra ETC1 init steps): counterpart.
- 0x2efbc (0xe300,0x2ef4a) / 0x22840: after the request list in both (CM848 has 0x2343c + 0x22318 between). Twin.
- 0x2ef36 (0xfecc,0x2ef1c via 0x2f47e) / 0x22770 (65228,0x22674 via 0x23188): between DM2 and DM4 set-ups in both lists. Twin.
- Start-up order: CM550 28e1a 2ef08, 28e20 2fbb2, 28e26 2f114, 28e2c 2f538, 28e32 2efbc. CM848 539504 221f0, 539508 23bb4, 53950c 22bc4, 539510 22d18(ETC2, CM848-only), 539514 232b4, 539518 2343c, 53951c 22318, 539520 22840.

## Globals checks
- 0x8035de dword (IO bytes 1-4) SWALLOWS row 0x8035e0 fuel_temp_control_flags (undefined, 0 refs) -> must be removed with it.
- 0x803458 payload swallows 0x80345a / 0x80345c (0 refs) - investigator says so.
- 0x804fb8 TIGAIST2 / 0x804fb4 TITMIS: other e2m files say "...WHILE UNDER IDLE CONDITION" -> idle fuel / idle time confirmed.
- 0x80da0e = 1227 +0 JCGPSS; 0x80da10 = 1227 +2 JCMIFISS (row exists, long Calterm name) = CM848 misfire_monitor_result role.
- 0x60fa4 JCOBDG len 2, 0x60fa6 JCCTMR len 2 (only low-byte reads at 0x60fa5 / 0x60fa7).

## Retarder chain
- 0x2f606 / 0x2346c: <25 ->100, >=125 ->0, else 125-x; same order/constants -> TWIN decodeRetarderTorqueRequestPercent (both agents agree). bsr only (0 abs refs).
- 0x2f632 / 0x234a4: asm identical step list: req==0 ->0; mode==3 && req>=100 ->100; count==4 ? stage4[4] (0x6055a / 0x5a456) : stage6[4] (0x6056e / 0x5a46a)
  as IF/ELSE in BOTH asm (CM848 bne 0x23504; the decompiler's "load stage6 then override" is a rendering artifact -> investigator's difference is false);
  scaled = req*full/100; stage 1-5 lookups at engine speed; 0/17/33/50/67/83 or (mode 2) 17/33/50/67/83/100. Only the lookup call follows the
  platform API (record vs register args) - precedent: runHighSpeedGovernorPid / selectEngineSpeedLimit are twins with the same API split.
  Called twice at the same two points by the retarder TSC1 processors (mode 2 after decode, mode 3 at the end). CM848 row says "(was j1939FormatMultiFrameResponse)".
  -> TWIN: AMEND to selectEngineRetarderStagePercent (CM848 0x234a4 too).
- 0x2f7e6 / 0x236f0: counterpart OK (CM848 masks j1939_blocked_message_bits & 5 in mode 0, zero torque timer / speed control flag tails).

## Responders (asm checked)
- 0x342f0 / 0x26cf0 VEP1: CM550 move.w batt -> local; lsl2+add+lsl2 = x20; lsr3; swap -> 0x80367e; send 0x80366c. CM848: lhz batt; sth local; mulli 20; srwi 3; sth; swap -> payload+4; send.
  Same steps/constants; both scheduled (ENGINE,0xfef7,1000,0xd2) and directly registered 0xfef7 in the request lists. -> TWIN (investigator's "x 5 / 2 other constants" = decompiler rendering).
  Q1 judge notes also confirm the twin buildPgn65271VehicleElectricalPower1Message. -> AMEND.
- 0x32e4c EEC2: CM550 commanded_throttle vs CM848 all_speed_governor_equivalent_throttle + other fault tests -> counterpart (Q1 judge agrees). CONFIRM.
- DM1 0x322ae / 0x24be8: CM848 cmpwi r6,20 (0x24d54) + byte reorder via stack (0x24ce4-0x24d04); CM550 neither -> counterpart CONFIRM.
- DM2 0x3241c / 0x24e78: CM848 cmpwi r7,20 (0x24fd8) + same reorder (0x24f6c-0x24f88) -> counterpart CONFIRM.
- DM5 0x32a42 / 0x25458: identical steps -> TWIN CONFIRM.
- DM10 0x32222 / 0x24b28: identical -> TWIN. 0x32222 starts after rts 0x32220, ends rts 0x32242; only ref pea 0x32286.
- VI 0x34430 / 0x26db4: single send -> TWIN. ends rts 0x3443e; only ref pea 0x34482.
- IO 0x33c6c: SPN 236 = swap32(scale(TIGAIST2>>2, 3785411, 1000000)), SPN 235 = swap32(scale(TITMIS, 20, 36000)); CM848 no 0xfedc -> standalone CONFIRM.
- CM848 registers no 65252/65253/65257/65244/65255 responder -> standalone OK for those.
- J1939 DB: 65244 Idle Operation (236 b1-4, 235 b5-8); 65230 DM5 (1218-1223); 65234 DM10 (1229); 65261 CCSS (74/87/88); 58112 DM7; 65504 Proprietary B.
- 0x801d44 powertrain struct = 22 bytes -> ends at 0x801d5a: table overlaps nothing.

## Plate / comment corrections found
- 0x31c84 CCVS1: CM550 speed = ((((x*8-x)*2-x)*8-x)*4)>>8 = x*412>>8 = CM848 x*0x19c>>8: the "x 412 / 256" difference in the plate is FALSE.
  Real differences: CM848 0xffff speed when vehicle_speed_sensor_type_cal < 1, datalink-source bits (0xc0/0x30 not available), cruise enable. -> AMEND comment.
- 0x2f4be / 0x2f538 / 0x2f7e6 / 0x801e28 comments cite names this batch renames (cm848_j1939DispatchPgnHandler, cm848_initJ1939ProtocolHandlers,
  cm550_selectEngineRetarderStagePercent) -> AMEND comments.
- 0x231cc CM848: HEAD comment is "jlaustill reviewed 2026-5-25 - mostly readable, hopefully accurate" -> keep as "earlier note:" (repo practice).
- 0x24be8 CM848: no-fault path stores lamp byte 0 (j1939_dm1_lamp_status = 0), not the built lamp byte; 0x24d78 is renamed by Q1
  (cm848_broadcastPgn65226Dm1UntilFaultsClear, Q1 judge CONFIRMED) -> AMEND comment.
- 0x801efa / 0x3fab0a: type j1939_ccss_tx_payload_t no longer exists (stage C) -> j1939_pgn65261_payload_t; CM848 row already at HEAD.
- 0x8035de: swallows 0x8035e0 fuel_temp_control_flags (undefined, 0 refs, no .cpp use) -> row removal in comment.
- Registrar callers: all 16 jsr followed by addq.l #6,a7 -> no caller reads d0 (plate OK).
- CM848 J1939_PGN_LOWER is applied nowhere (only enums.csv + firmware_types.hpp); 65235 = DM11 in Mongo. Member renames are doc fixes; names unique.
- Struct-array precedent: j1939_receive_handler_table j1939_receive_handler_entry_t[16], j1939_diagnostic_service_table [32] -> [32] fits.
- Reference counts (csv / docs) of renamed names: cm848_selectEngineRetarderStagePercent 24 / 32, cm848_j1939DispatchPgnHandler 20 / 12, j1939FormatMultiFrameResponse 8 / 55 ...

## VERDICT PLAN
AMENDED: 0x2f632 (twin selectEngineRetarderStagePercent / 0x234a4), 0x342f0 (twin buildPgn65271VehicleElectricalPower1Message / 0x26cf0),
 comments: 0x2f4be, 0x2f538, 0x2f7e6, 0x31c84, CM848 0x231cc, 0x24be8; globals 0x801efa (type), 0x3fab0a (type; already done), 0x8035de (comment), 0x801e28 (comment).
CONFIRMED: everything else.

## FINAL (written before StructuredOutput)
- 0x2f7e6 bsr.w 0x2f606 at 0x2f980 / 0x2fa5a and bsr.w 0x2f632 at 0x2f98e / 0x2fa90 (verified).
- Bit names: flags_18 bit 12 remote_throttle_enable, bit 13 remote_throttle_transition_verification_enable (CM550 struct rows 757/758).
- 0x34430 VI plate verified (0x803e7f = vehicle_vin_string_cal byte[20]; CM848 copies 20 bytes + '*', length 0x15).
- CM550 rows without exported bodies: 0x103ba 0x16cd8 0x18dae 0x1e0bc 0x21272 0x21642 0x2ee62 -> new row 0x2f47e may also export no body.
- Verdicts: AMENDED 0x2f632 (twin selectEngineRetarderStagePercent/0x234a4), 0x342f0 (twin buildPgn65271VehicleElectricalPower1Message/0x26cf0),
  comment-only 0x2f4be 0x2f538 0x2f7e6 0x31c84, CM848 0x231cc 0x24be8; globals 0x801efa + 0x3fab0a (type), 0x8035de + 0x801e28 (comment). Rest CONFIRMED.
