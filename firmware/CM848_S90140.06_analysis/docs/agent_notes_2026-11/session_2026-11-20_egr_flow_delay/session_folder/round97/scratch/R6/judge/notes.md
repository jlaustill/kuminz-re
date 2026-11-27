# R6 judge notes (round 97)

Started fresh (no earlier judge notes). Investigator + describer notes read.

## Pipeline facts
- ImportAnalysis.java creates a function (disassemble + createFunction) for a rename row at an address with no function -> 0x1ffd2 row works.
- function_definitions.csv and enums.csv use ScriptUtils.parseCSVLine (split on EVERY unquoted comma): comments there must not hold commas (existing rows use ';'). Enum: a comma in the comment pushes junk into the size column -> size defaults to 4 -> enum 4 bytes. function_renames (split ,3) and global_variables (split ,4) accept commas.

## Call lists (verified)
- CM550 mc68k_initializeJ1939Datalink set-ups 0x28bdc..: 31b96 ACK, 31ed2 CCVS, 32c22 EBC1, 32e08 EEC1, 33064 EEC2 (5th), 33120 EEC3, 33692, 339b0 ERC1, 33a1e FD1, 33c28, 341e6 RC, 2faa4, 31c1a AMB, 331ae fluid, 33dfa SHUTDN, 33eee IC1, 3401a PTO, 34334 VEP1, 344ce WIF, 323be DM1, 32b64 DM8 (last). Later: 226da read svc, 22370, 21872 write svc, 11b36 diag handlers, 200c6 (last).
- CM848 cm848_j1939_system_init: AckBuffer, 65265, EBC1, EEC1, EEC2 (5th), EEC3, 65251, ERC1, FD1, 65241, RC, TSC1 state, 56320, AMB, fluid, IC1, PTO, VEP1, WIF, 65504, DM1, DM8 (last). Later: read svc, GetAddress registrar, write svc, diag handlers, BroadcastAndNoOperation (last). Same order as CM550.
- CM550 registrar 0x2f538 tail: 323be DM1, 3252c DM2, 2ef36 DM3, 329d2 DM4, 32ae2 DM5, 32244 DM10 (last); CM848 same DM1..DM5, DM10 last.

## 0x32244 -> initializePgn65234Dm10Handler TWIN 0x24b64: CONFIRMED
- CM550: 0xfed200 / prio 0x803f60 &7<<2 (andi.b e3/or.b) / len 2 / +6 0x801f4c / +10 0x801f54 / SA byte 0x80da01 -> +3 / reg(0xfed2, 0x32222). CM848: stw 0xfed200 / lhz 0x3fd84c rlwimi 2,27,29 / li 2 sth +4 / +6 0x3fab60 / +10 0x3fab68 / lhz 0x40ad74 stb +3 / bl 0x23188(0xfed2, 0x24b28). Same order; last call of both registrars.

## 0x323be -> cm550_initializePgn65226Dm1Handler COUNTERPART: CONFIRMED
- CM550 no length store; +1 = 0xff; bset 7 of +5; reg(0xfeca, 0x322ae). CM848 same + stb 0 -> 0x3fabcb (j1939_dm1_broadcast_pending_flag) @0x24e50. Callers 0x28c4e + 0x2f5de.
## 0x33aea -> cm550_initializePgn65257FuelConsumptionHandler standalone: CONFIRMED (0xfee900, 0x803f72 JCFCPZ, len 8, 0x8035a8, 0x8035b0, SA, reg(0xfee9, 0x33a62)); only caller 0x2f568.
## 0x33064 -> initializePgn61443ElectronicEngineController2Handler TWIN 0x25d60: CONFIRMED
- CM550: 0xf00300 / 0x803f64 / SA +3 BEFORE len 5 / +6 0x8034aa / +10 0x8034c0 / jsr 0xf99a / reg(0xf003, 0x32e4c). CM848: same order incl. SA before len, bl 0x20aec (same shared empty step name), reg(0xf003, 0x25b10). 5th set-up of both initializers.
## 0x33ce2 -> cm550_initializePgn65244IdleOperationHandler standalone: CONFIRMED (0xfedc00, 0x803f76 JCISPZ, len 8, 0x8035de, 0x8035e6, reg 0xfedc -> 0x33c6c).
## 0x343d2 -> cm550_initializePgn65255VehicleHoursHandler standalone: CONFIRMED (0xfee700, 0x803f86 JCVHHRPZ, len 8, 0x803692, 0x80369a, moveq -1 -> 0x803692, reg 0xfee7 -> 0x34394).
## Priority words: e2m tool confirms 1254 +0/+8/+10/+12/+16/+24/+28/+38 (hex) = 0x803f4e/56/5e/60/64/72/76/86; dump 6 except +16 (EEC2) = 3. CM848 names j1939_pgn59392/65226/65232/65234/61443_priority_cal for the same records. Precedent CM550 0x803f78 j1939_pgn65252_priority_cal.
## 0x3407a RC builder: '=' bug confirmed (0x340b6 move.w #1 then beq never taken); no stack read; queue 1 runs only with datalink_broadcast_enable_flags & 8. CM848 0x26650 count<2 -> (==1 ? 0x14 : 0xff) else 3. Byte 19 0xff from 0x341e6.
## 0x322ae DM1 builder: no stack read (movem 7 regs, no (0x20,a7)); CM848 cap 0x15 + byte swap -> counterpart. Both write DTC k at payload+2+4(k-1) (slot-indexed: a skipped 0x4000 slot leaves a gap; length counts only written DTCs).
## 0x2eea2 dispatcher: request (0x18,a7) after 5 regs = +4; d4=0x18; validator then handler(request); reply 0x3216a(request, word) unless 0xff. CM848 0x22128 adds the 0x0c/0x0d filter -> counterpart.
## 0x21982 validator: +4 request; >0x19 -> 0xff; secured: len==hdr+10 -> key -> 0xff/3, else 2 (CM848: 0x1a when len 8) -> counterpart.
## 0x31b22 -> cm550_sendPgn59392AcknowledgementMessage COUNTERPART 0x23dbc: CONFIRMED
- movem 2 regs: (0xc,a7)=+4 request, (0x10,a7)=+8 control word; hdr byte3 = req id byte2, byte2 = req id byte3 (requester); payload+0 = control; +5..+7 = data_ptr[0..2]. CM848 0x23dbc: byte2 = 0xff (global) -> counterpart. Callers: DM3 0x2ef2c clr.w (always ACK), DM7 0x2efae #1 (any unsupported test id), 0x2f52a #1 (no match, not global).
## CM848 0x23dbc -> cm848_sendJ1939AcknowledgementOfRequestedPgn: CM848 DM3 handler passes J1939_ACK to it when j1939_dm1_active_flag != 0 (decompile) -> 'Negative' is wrong. PGN from data bytes 0-2; 0x23d3c takes 0 / pgn_pf / dest_address from the frame id. Dispatcher passes J1939_NACK.
## 0x31b96 -> cm550_initializePgn59392AcknowledgementBuffer COUNTERPART 0x23e40: CONFIRMED (CM848 extra stb 0 -> 0x40ad53).
## 0x32b38 -> sendPgn65232NonContinuousMonitorTestResultMessage TWIN 0x255c0: CONFIRMED (stb id +0, swap(&value) -> +2, send; DM7 handler only caller in both).
## 0x32b64 -> initializePgn65232Dm8Buffer TWIN 0x2560c: CONFIRMED (8 stores same order/constants; last set-up of both initializers).
## 0x33eee -> initializePgn65270InletExhaustConditions1Buffer TWIN 0x265d8: CONFIRMED (same stores; CM848 one sth at odd 0x3fae4b = bytes 6-7 vs CM550 two move.b: CPU32 alignment, same C step).
## IC1 bytes (J1939 DB PGN 65270): b1 SPN81 DPF intake pressure, b4 SPN106 air intake pressure, b5 SPN107 air filter 1 diff, b6-7 SPN173 EGT, b8 SPN112 coolant filter diff. 0x803611/12/13/15 no abs refs; 0x80360e refs only as base (builder writes +1/+2 only) + set-up 0xff. Dump: ff 00 56 ff ff ff ff ff.
## 0x801eb2 payload byte[8]: no row inside 0x801eb2-0x801eb9 (0x801ea4 descriptor ends at 0x801eb1, 0x801eba status). Dump 00 ff ff ff ff 00 00 00. CM550 lacks j1939_acknowledgement_payload_t.
## 0x2ed6a / 0x2edb2 J1587 helpers: CONFIRMED roles. 0x2ed6a reads *insite_request_read_pointer (the count byte right after the PID) + 2 (NOT pointer+2: plate wording "at insite_request_read_pointer + 2" is ambiguous -> amend). Parallel names: cm550_getJ1587ReceivedParameterLength / cm550_getJ1587ReplyParameterLength (describer's order) -> amend 0x2ed6a for the pair.
## Request chain offsets all verified (asm): dispatcher/validator +4 after 5-reg movem; workers 0x2148a/0x2238e +4/+8/+12 after 8-reg movem; by-ID 0x21642/0x224f4 link a6: +4 req, +8 ID word, +10 offset, +14 length; services link a6 (8,a6); 0x11908/0x200a4/0x200b4 (4,a7); 0x1192a (8,a6) req + (0xc,a6) word. Service handlers tail-return d0 (movea/unlk/rts).
## Service field layouts (0-based data_ptr): 0x44 ID 1-2 len 3; 0x45 ID 1-2 len 3-6; 0x47 ID 1-2 off 3-4 len 5; 0x49 ID 1-2 off 3-6 len 7-10; 0x4b addr 1-4 len 5; 0x4d addr 1-4 len 5-8; 0x43 ID 1-2 len 3-6; 0x46 ID 1-2 off 3-4 len 5; 0x48 ID 1-2 off 3-6 len 7-10; 0x4a addr 1-4 len 5; 0x4c addr 1-4 len 5-8. All match the proposals.
## 0x2238e TWIN 0x50c42c: cap 0x6e4 (CM848 < 0x6e5), hdr len 8/h/h+10, REFUSED/UNMAPPED, 0x43<256 -> 0x44 with [3]=[6], table 0x22384, alloc null -> 4, 0xef0000 + prio + swapped addrs, EEPROM remap, send, 0xff. Existing 'return void' row wrong (callers tail-return d0).
## 0x224f4 TWIN 0x50c5d0 (no body exported today: FUN_ functions are not exported).
## 0x222b4 TWIN 0x50c318; 0x22370 TWIN 0x50c400; 0x1ffd6 TWIN 0x509be8 (jump table decoded: items 1->12, 2->0x80, 3/4/5->4, 6->1, 7->2); 0x200a4/0x200b4 TWINS; 0x200c6 TWIN 0x509d34 (15,16,4,5); 0x1ffd2 (4200 4e75) TWIN 0x509be0.
## 0x22c26 TP.DT: +4 message after 8-reg movem; length==8, id byte 3; at 0x22d02 sets 0x8012d2 (= 0x8012cc+6) = 0x8012de and passes 0x8012cc to 0x2eea2.
## Build order: enums -> import(renames create funcs) -> ... -> export (funcdefs) -> fine for 0x1ffd2 / 0x224f4.
## Stale CM848 names in CM550 plates if the CM848 renames apply: 0x323be (cm848_initPgn65226Dm1Handler), 0x31b96 (cm848_initJ1939AckBuffer), 0x2eea2 (cm848_j1939DiagnosticServiceHandler) -> amend plates to the new CM848 names.
## 0x1ffd6 plate: '(the gate of the J1939 periodic queues)' incomplete: bits 0 J1587 / 1 J1922 / 2-3 J1939 queues (items 6/7 -> masks 1/2 = J1587/J1922) -> amend.
## DECISIONS (final)
- CONFIRMED functions: 32244, 33aea, 33064, 33ce2, 343d2, 31b22, 32b38, 2edb2, 2148a, 32b64, 33eee, 2238e, 224f4, 21982, 222b4, 22370, 200a4, 200b4, 200c6, 1ffd2.
- AMENDED functions: 323be / 31b96 / 2eea2 (plates cite CM848 names this batch renames), 322ae (slot-indexed gap), 2ed6a (name cm550_getJ1587ReceivedParameterLength for the pair + pointer wording), 3407a (restore SPN 547 / 556 meanings + 'other counts leave it'), 1ffd6 (flags parenthetical: bits 0 J1587 / 1 J1922 / 2-3 J1939 queues).
- CM848 functions: all 4 CONFIRMED (0x23dbc gets J1939_ACK from the DM3 handler).
- Globals: all 22 CONFIRMED. Enum: member 0 comment made comma-free (enum size column), 1-4 CONFIRMED.
- Prototypes: 1192a and 31b22 AMENDED (explicit rows; keep the good existing ones; drop the wrong 0x23d3c twin claim), 2ed6a AMENDED (name), others CONFIRMED.
- CM848 RC 0x26650 / J1939 DB: RC bytes 15-16 SPN 547 peak torque speed, 17-18 SPN 556 reference torque (CM550 j1939_pgn65249_payload_t fields).
## Old-name references (applier): CM550 CSVs cite old names e.g. cm550_diagMemoryReadResponseBuilder (10 lines), cm550_diagnosticServiceDispatcher (9), cm550_diagnosticCanResponseSender (9), cm550_diagnosticServiceSecurityValidator (8 incl. local_variables), parameter_id_lookup_table.csv cites total_number_of_engine_brake_output_drivers...; CM848 39 lines cite cm848_j1939DiagnosticServiceHandler.
## Writing StructuredOutput now (92 verdicts).
