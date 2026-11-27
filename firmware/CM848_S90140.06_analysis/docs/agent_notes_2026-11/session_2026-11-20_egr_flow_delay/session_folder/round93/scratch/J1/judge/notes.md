# J1 judge notes (round 93) - CM550 0x201d6-0x211f4 J1939 multiplexed input layer

Scratch: cm550_201a0_21290.asm (fresh m68k.py), cm848_helpers.asm, cm848_processors.asm (disasm_func.py).

## Settled so far

### Nine bitmap helpers = TWINS (own disassembly of both)
CM550 0x201d6/0x20210/0x2024a clear and.l on 0x800aa0/0x800aa8/0x800aa4 (order +0,+8,+4);
0x20284/0x202a0/0x202bc any (tst.l (a0)+, one-element loop) on 0x800aa0/a8/a4; 0x202d8/0x20310/0x20348 or.l on 0x800aa0/a8/a4.
CM848 0x509d98/dd8/e18 clear (srawi 5 / slw / not / lwz-and-stw) on 0x3fbd5a/62/5e (+0,+8,+4);
0x509e58/e98/ed8 any (lwzx, loop while idx<=0) on +0,+8,+4; 0x509f18/f54/f90 or on +0,+8,+4.
Same index (N>>5), same mask (1 << N&31), same 32-bit and/or, same order of the nine, same one-element loop quirk.
-> CONFIRMED twins; CM848 rows already have these names with cm848_ prefix (rows 1798-1806).

### Twin vs counterpart precedent in THIS layer (frozen CM550 function_renames.csv)
- 0x21edc cm550_tickJ1939InputSupervision = counterpart because CM848 adds gates (multiplex enable, start delay, inhibit flag, DM13).
- 0x21ef6 cm550_registerJ1939InputMessageHandlers = counterpart because CM848 adds ONE store (start delay = 1000).
- 0x1183e cm550_requestClearInactiveFaults = counterpart: "The acceptance gate differs".
=> every processor / task / initializer here has CM848-only gates (0x40adda DM13, 0x40aaca inhibit, 0x40aaa4 start delay, 0x3fd5d4 bit 10 enable, 0x3fbd69 armed flag) -> counterpart + prefix. Describer's TWIN for these is too loose by the layer's own precedent.

## Run 2 (resumed 2026-11-25) - per function

### 0x20380 retarder -> cm550_processJ1939EngineRetarderSelection: CONFIRM (counterpart)
CM550 asm 0x20380-0x2041a: clear data err 5 / timeout 5; 0x803cd6 & 0x10 (flags_33 bit 4 engine_retarder_switch_level_override); word 0x808158 vs byte 0x80d726 blt exit;
tst.w 0x80423e (slot 5) zero -> set timeout 5 + default 0x80815a->0x80d728; <=0xfa x4/10; ==0xfe default; else default + set data err 5.
CM848 0x509fcc: same core + lhz 0x40adda (DM13) bne -> default, lhz 0x40aaca (inhibit) before each set; enable 0x3fd5b6 bit 0. Extra steps -> counterpart (layer precedent 0x21edc/0x21ef6).

### 0x2041c fan -> cm550_processJ1939EngineFanRequestedSpeed: CONFIRM (counterpart)
CM550: input 0, 0x803cc6 & 0x8000 (flags_25 bit 15), byte 0x80d727, slot 0x804234, x16/10, 0x80815c -> 0x80d72a; set data err BEFORE default (order differs from retarder, trivially).
CM848 0x50a0cc: same + DM13 0x40adda + inhibit 0x40aaca. Counterpart.

### 0x204b0 cm550_outputControlState1Handler -> cm550_processJ1939AcceleratorLowIdleSwitch: CONFIRM (counterpart)
CM550: clears 0x201d6/0x2024a/0x20210 with 6 (same order as CM848 d98/e18/dd8); 0x803cae&0x80 (flags_13 bit 7); word 0x808158 vs byte 0x80bd51 blt; claim if byte<=word; tst.w 0x804240 (slot 6) zero -> set timeout+pedal timeout, no switch write;
==3 set data err + default bit7 of dword 0x807d6a -> 0x80bcd8 bit7 (only if prio byte 0); ==2 default; else tst.b -> bit 7. No output, no state -> old name wrong.
CM848 0x50a1b4: same + inhibit 0x40aaca (x2), writes via helpers 0x4ea40/0x4ea84 (7,0), enable byte 0x3fdbce bit 7. Counterpart.

### 0x205c4 -> mc68k_updateIdleSwitchesFromLocalInputs: CONFIRM (counterpart, mc68k_)
CM550: flags_25 bit 3 -> move.w (0xfff2b0 + 2*word 0x806be2) -> 0x80d72c (QADC RJURR direct read; 0xfff2b0 abs refs only 0xb856 + 0x205fc), >360 -> 0x80bcd9 bit0 on / 0x80bcd8 bit7 off / 0x80aa86=1; else opposite.
Else d2 = (0x80bced XOR 0x800aaf) & 1; vs 0x800aae: changed -> store + timer 0x800aac=100; same: timer 0 -> exit; -50; >0 exit; clear + apply. No priority test.
CM848 0x50a2cc: + armed flag 0x3fbd69 (test/set + timer 100; cleared in analog branch), forced A/D option 0x3fdb78 bit 13 (0x40bc9a), switch via 0x4eac8(8), writes via helpers. Extra steps -> counterpart. mc68k_ justified by the direct QADC register read.

### 0x206a8 -> cm550_copyOutputBitToSwitchOverrideValue: CONFIRM (counterpart)
CM550: d2=arg1 (0x14,a7) input, d3=arg2 output; enable bit (d2+0xd0) of words at 0x803c94; word 0x808158 vs byte 0x80bd4a[d3] (output index quirk) blt exit; claim 0x80bd4a[d2]; prio byte 0 -> bit d3 of 0x80bcf6[d3>>3] -> bit d2 of 0x80bcd8[d2>>3].
CM848 0x50a4a0: enable is a separate byte array 0x3fdbce[r3>>3], same quirk, write through helpers 0x4ea40/0x4ea84 (priority test after the bit read). Counterpart (enable layout + helper calls differ). CM848 keeps its name.

### 0x20784 -> cm550_processJ1939RemoteAcceleratorPedalPosition: CONFIRM (standalone)
CM550 asm matches (flags_18 bit 12 + flags_14 bit 3; word 0x808158 vs word 0x80a6e0 bcs exit, no claim; slot 1 0x804236; 0xfe -> default + fault bit0 0x806000/0x806040; fb-fd/ff -> data err 1 + default; <=fa clear fault bit0 + x16/10 -> 0x80a744).
CM848: only stb to 0x40aabc (0x50b944) / 0x40aaba (0x50b978), no load (lis/d-form scan + .cpp one hit each). Standalone ok.

### 0x20890 -> cm550_processJ1939SwitchInput: CONFIRM (counterpart)
Table 0x20108: 17 entries {ptr, slot, 0, switch long} verified from ROM. Timeout -> default bit (unlike 0x204b0). CM848 0x50a57c adds DM13 0x40adda branch + inhibit x2 + helpers. Counterpart. CM848 keeps cm848_evaluateJ1939InputSignalFault (no CM848 rename for counterparts).

### 0x20c98 -> cm550_processJ1939AcceleratorPedalPosition: CONFIRM name (counterpart), plate needs fix
CM550: 0xfe sets fallback flag 0x80d70c=1 only while low idle switch <=1 (else above-idle flag 0, 0x80d70c stays 0); valid value also clears 0x80d70c + fault bit0 when fault bit0 set and low idle switch != 2. Plate overstates 0xfe path. CM848 0x50a700: DM13 path, inhibit, armed flag clears -> counterpart.

### 0x20e14 -> cm550_processJ1939AcceleratorIdleSwitchPair: CONFIRM (counterpart)
CM550 matches; still clears its bits and claims both priorities while 0x80d70e is set, only the writes are skipped. CM848 0x50a9d4 differs by inhibit x2 + helpers + own fault bit -> counterpart.

### 0x20fac -> cm550_processJ1939WetTankPressure: CONFIRM (standalone)
x 9282/100 verified (((9v)*16+v)*32+v)*2; enable 0x803cbc&0x200; prio word 0x80a6fc bhi exit, claim; slot 9 0x804246; default 0x806d3c -> 0x80a760.
RAM 0x806d3a = 50, 0, 30, ... 1023 (header 50 + 25 breakpoints) = e2m 101B +0 ADIMTPXA IMT linearization X axis -> 0x806d3c is its first breakpoint (investigator right).

### RAM (main + extended) peeks agree: bitmaps 0, 0x808158 0, 0x807d5e 765df1ae 0000ffff 00000000, 0x807d6a 0 0000ffff 0, 0x80bced 0xff, 0x80bd4a.. all 0.
### Task periods: live CSV round 93 names 0x1b4d8 cm550_runEvery2FramesTaskSetPhase0 (10 ms) and 0x1b714 cm550_runEvery10FramesTaskSetPhase6 (50 ms) -> "10 ms / 50 ms" ok.

### Tasks / initializer (all CONFIRM, counterpart)
0x21070: loop 0..16 -> 0x20890, fan, retarder, five 0x206a8 (54,1)(54,4)(33,6)(32,0 via clr.l (a7))(54,2); both summaries on bit 0 of 0x806000 (+latch 0x806040). CM848 0x50aba8 gates on 0x3fd5d4 bit 10, start delay 0x40aaa4, bits 2/0, registered copy 0x3fe9d8.
0x21146: 0x204b0, 0x20fac, 0x20e14, 0x20c98, 0x20784, summaries, 0x202a0 -> 0x80d70e. CM848 0x50ad1c: 3 processors + gate + delay.
0x211f4: copies byte 2 (bits 8-15) of 0x807d5e (jump table case 1 = 0x2123a) to 0x800aaf, 0xff -> 0x800aae, clear bit0 0x806000, clr 0x80d70d. No reference of any form (abs32 any alignment, 3-byte, b.s/b.w/b.l, (d16,pc)) - own scan. CM848 0x50ae5c: 0xff prev, 100 timer, bit 2 clear, 0x40aaa7=0, 0x40aaca=1 -> counterpart.

### Names: all 25 proposed function names free in frozen+live CSVs of both firmwares and in J2/D1/F1 proposals.
### any... helpers: only predicates without is/has/are/check in either CSV -> AMEND to isAny... (verb-phrase rule; both rows change anyway). Global comments 0x800aa0/a4/a8 name them -> fix comment text.

### Globals (abs_refs + e2m + parameter ID table, all verified)
Param table: 12FE 0x808158 (next 0x80815e), 1234 0x807d5e (next 12FC 0x807d6a), 12FC 0x807d6a (next 0x807d76), 12A8 0x80bd4a (next 128E 0x80bd9a), 12D0/1/2/3 0x80a6ca/6fc/72e/760, 12F7 0x80d70c, 000E 0x80bcce.
- 0x80bd4a byte[80]: 56 rows inside 0x80bd4b-0x80bd99 == investigator's list exactly; no element has an absolute reference (only base at 0x204b6/0x206b6/0x208a0/0x20e1a + param table). CM848 arrays.csv 0x40c058 switch_input_source_priority byte[32] = 12A8. CONFIRM.
- 0x807d5e dword[3]: dwords read at 0x15070/0x1508e/0x150ac (XOR, mc68k_sampleAndDebounceDiscreteInputs) + 0x15bfe.. (mc68k_ioDriverStrobeHandler) + 0x21206; 0x807d60/64 no ref. CONFIRM.
- 0x807d6a dword[3]: 7 sites, all in J1939 layer; 0x807d6e/72 no direct ref. CONFIRM.
- 0x808158 word: word reads + byte low half 0x808159 only at 0x20958. CONFIRM (0x808159 row removal).
- 0x80bced: raw byte from port 0xffd001 stored at 0x1502c before the polarity XOR at 0x15076. CONFIRM.
- 0x800aac: type 'short' not a CSV spelling (ImportAnalysis.java knows i16, not short; 0 'short' rows) -> AMEND type i16.
- RAM: word 20 = 0 (0x803cbc), word 18 = 0x303a (bit 12 set), 0x806000 = 0x2800.

### 0x80d70c flag latch (new finding)
Clears: 0x20d6a (valid value AND fault bit0 0x806000 set AND low idle switch != 2), 0x20d86 (unavailable flag set), 0x20d9a (>250). Set 0x20ddc. Read 0x2583a.
The 0xfe path sets no bitmap bit, so the summaries of 0x21146 / 0x21070 clear bit 0 the same pass -> a later valid value leaves the flag at 1. Investigator's "clears it otherwise" is wrong -> AMEND comment.
0x25806: (flags_5 bit 10) and (0x80d70c | 0x80d70e) -> user_fueling_state (0x80ded4) = 6 FUELING_STATE_ACCELERATOR_PEDAL_FAULT. ok.

### 0x80a6de: 0x107d0 compares 0x808158 vs 0x80a6de, both branches take 0x80a38e (sampled_throttle_sensor_state +8) into (a2) or (a3). Comment wording ok.
### cm848_applicationMain calls cm848_initJ1939InputProcessing (cpp 59060). ok.
### function_definitions.csv: 0x201d6/210/24a/2d8/310/348/890 rows carry old names; 0x206a8 row = ptpSwitchedInputDebouncer(input_state, debounce_mask) -> code is (logical_input, output_number). Lead for apply.
### 0x80a72e analog_sensor_override_values comment says "no writer in the dumped ROM" - wrong: 0x20c98 writes [10] (0x80a742), 0x20784 writes [11] (0x80a744). Lead.

## FINAL
Functions: 6 twins CONFIRMED (clear x3, set x3), 3 twins AMENDED isAny..., 10 counterparts CONFIRMED (0x20c98 + 0x20e14 plate fixed -> AMENDED), 2 standalone CONFIRMED.
Globals: 0x800aa0/a4/a8 AMENDED (comment fn names), 0x800aac AMENDED type i16, 0x80d70c AMENDED comment, rest CONFIRMED. No enum members. skipped[] empty.
Investigator's CM848 renames (0x50a57c, 0x50a4a0, 0x50ae5c) not accepted: counterparts keep CM848 names.
