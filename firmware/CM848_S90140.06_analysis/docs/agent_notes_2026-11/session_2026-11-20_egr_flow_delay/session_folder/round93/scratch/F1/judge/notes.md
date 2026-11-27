# Judge F1 - notes (run 2, 2026-11-25)

Continuing from run 1 (files in this folder: notes_judge_f1.txt, verdicts_f1.json, disasm_*.txt, abs_refs_*.txt, ...).
The r94 batch_F1.json proposal is identical to the investigator's result_f1.json that run 1 judged.
Run 1 had 73 verdicts but no StructuredOutput was collected (batch verdict null). Re-checking below.

## Re-checked in run 2 (disassembly in run2/)
- run2/disasm_small.txt: every CM550 limiter / timing step / runner / hour meter body matches the investigator's evidence byte
  for byte (0xb3b2 17, 0xb4ce 3, 0xc2a0 16, 0xc2ee add + mask 4, 0xc742 15, 0x12484 add 0..0x400 + mask 8, 0x17120 33 behind
  engine_state 3 + WPLMFG, 0x196e4 29, 0x1ce58 19 / 40, 0x2d9a8 34 behind PTSS 1, 0x30ade four stores, 0x30b0e = rts,
  0x30b10 4, 0x30b34 eight calls, 0x30bf6 28, 0x30c14 20 behind JCEGMD 3, 0x30c3c eleven calls, 0x34512 hour meters,
  0x34dba copies 0x8036e2).
- run2/disasm_cm848_twins.txt: CM848 0x4280c bl order 0x1f318 0x2a918 0xe0c4 0x502af4 0x509510 0x427cc 0x4279c + 6 more.
  Twins: same compare / copy / constant: 0x1f318 (19/40), 0x2a918 (PTSS==1, 34), 0xe0c4 (16 into 0x40afb4), 0x502af4 (15),
  0x509510 (29), 0x427cc (lha 0x40adf8 ==3, 20), 0x4279c (28), 0x506780 (engine_state!=1 +1 0x40a794, +1 0x40a64c).
- run2/disasm_1c152.txt: 0x1c152 final fueling selection as described (26/27/25/23/24/22/11, clamp, fold, latch, prev).
- run2/disasm_mid.txt: 0x1ca54 fuel shutoff driver (bit 0x20 of 0x80bcfb, priority byte 0x80bd47), 0x2658c idle initializer,
  0x26af0 misfire raise (state 11, needs state 0 and flags_32 bit 0).
- Enum scan (run 1 scan_imm.py re-read + 37/38 run now): other move.w #17/#33 go to 0x80d61a (HSG gain set, a2 in
  0x1d392), 0x801e2a (a2 in 0x2f632 - percent levels 100/17/33/50) and 0x80068c (executive phase, a4). cmpi #18,(a2) at
  0x2535e/0x2536c is the lamp blink counter 0x801a18. CM550 37/38: only move.w #37/#38,(a4) = executive phase.
- run2/callers.py: every batch function has exactly one caller (jsr / bsr) - 0xb3b2 0x30c48, 0xb4ce 0x30b4c, 0xc2a0 0x30c4e,
  0xc2ee 0x30b3a, 0xc742 0x30c54, 0x12484 0x30b40, 0x17120 0x30c64, 0x196e4 0x30c5a, 0x1c152 0x1b5fe, 0x1ca54 0x1b63c,
  0x1ce58 0x30c3c, 0x2658c 0x287d4, 0x26af0 0x30b34, 0x2d9a8 0x30c42, 0x30ade 0x287f2, 0x30b0e 0x28774, 0x30b10 bsr 0x30b52,
  0x30b34 bsr 0x30b7e, 0x30bf6 bsr 0x30c62, 0x30c14 bsr 0x30c60, 0x30c3c 0x1c18a, 0x34512 0x1b974, 0x34dba 0x30b46;
  0x1ca5c / 0x2659a / 0x26b00: none (and the LIVE deleted_functions.csv lists all three, PR #53 round 93).
- Executive phase 0: CM550 0x1b95e jsr (a5) + 5 bsr + jsr 0x34512 + 0x800690 = 0x809ef2 + phase 1; CM848 case 0 the same
  shape with cm848_advanceHourMeters last. Twin confirmed.
- 0x30b62 (caller of the timing runner) picks final timing by final_fueling_state 27 / 25 / 26 / override bit / else TSOI.
- 0x2d994 = 33f9 0080dc26 00801c0c = move.w (PTSS),(0x801c0c): PTSS is the SOURCE -> the 0x80dc26 comment is wrong.
- 0x8000d7 main_loop_iteration_counter row (undefined) exists in frozen AND live CSVs, no reference -> keep 0x8000d6 untyped.
- e2m signed column: only TSAJ4DTA (0x80aaa4) is S among the 43 records -> i16; 0x801a82 is ext.l'd at 0x264e6 / 0x26524
  (LSICBKRF 0x805f0a, its saved copy, is S and i16 in the live CSV) -> i16. Live CSV (round 94, in progress) already moved
  0x80800a / 0x80da62 back to word (Calterm unsigned) - agrees with the proposal.
- TIT3DQTM text is cut ('...ENGINE PROTECTIO' / '...ENGINE PROTECTION SINCE LAS' in 4 files): the proposal's quote adds words.
- reg_targets.py: no move.w #3/#17/#18/#33/#36-#39 through an address register lands on a fueling state word except the
  known compares (0xf7f6 / 0x2dcde for 3); 17 / 33 each have one store (0xb3c6 / 0x17146).
- EEC1 table 0x32d04 (index = state - 1): 0x32d5c = states 1 2 3 7 8 30 37; 0x32d88 (0xF8) = 13-21 28 29 31 33-36 38-41.
- CM848 37 / 38: cm848_runOperatingModeSpeedGovernor runs only in 7 / 2 / 30 / 37; cm848_selectPowerTakeOffOrUserFueling,
  the cruise selection and the governed fueling arbitration treat 37 / 38 like TSC1 1 / 2. 49 / 50 only compared.
- Wet stack 0x34cc4: table on ADIMTPFT (intake manifold temperature) -> state 1, on ADCLTPFT (coolant) -> 13. Confirmed.
- Warmup protection 0x16dd4: oil pressure threshold WPO2TDCN / time WPO2TMCN / max time / fault time / drain-back re-arm
  (WPLMFG = 1 again at 0x16e76 after the drain-back time with the engine stopped - the 0x80ccb2 comment omits it, not wrong).
VERDICTS: same as run 1 (all re-derived): 3 function comment amendments (stale mid-body remarks), 0x80dc26 comment,
0x8000d6 type undefined, 0x80aaa4 / 0x801a82 i16, enum 18 comment quote; everything else CONFIRMED. Skipped 0x30b0e stays.
FINAL (run 2): 73 verdicts - functions 19 CONFIRMED / 3 AMENDED (0x1ca54 0x2658c 0x26af0 comments), globals 39 / 4
(0x80dc26 comment, 0x8000d6 undefined, 0x80aaa4 i16, 0x801a82 i16), enum 7 / 1 (18 comment). Built in run2/final_verdicts.json
(final_verdicts.py); submitted through StructuredOutput with shortened reasons.
