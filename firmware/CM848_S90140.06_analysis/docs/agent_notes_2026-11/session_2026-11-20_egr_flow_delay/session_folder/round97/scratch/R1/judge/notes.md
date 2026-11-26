# R1 judge notes (CM550 low speed governor)

My own disassembly: disasm.txt (m68k.py 0x2595a-0x266e0).

## Functions (verified from my disassembly)
- 0x265e6 TSC1 selector: tst.w 0x80da50 / beq ret0; 0x803c96 & 0x8000 / beq ret0; final state 0x80dacc = 4; ptr 0x80dada = 0x808334; ret 1.
  CM848 0x28b38: lha 0x40adf8 / beq; lhz 0x3fd59e bit 0x8000 / beq; sth 4 -> 0x40ae7e; stw 0x5c4a6 -> 0x40ae90; ret 1/0. SAME STEPS = TWIN.
- 0x26272 override selector: arg != 0 -> ret 1; 0x80dace == 0 -> ret 0; final = it; ptr = 0x80dad0; ret 1.
  CM848 0x289d0: r3 != 0 -> 1; lha 0x40ae80 == 0 -> 0; sth -> 0x40ae7e; stw 0x40ae82 -> 0x40ae90; ret 1. TWIN.
- 0x2629e gain set load: jsr 0x2609c, jsr 0x265e6, bsr 0x26272(d2); if 0: final = user (0x80daca); user 0 -> ptr = 0x808314 else ptr = (0x80dad6); load (a2)/(2,a2)/(4,a2) -> 0x80dac4/c6/c8.
- 0x2609c aggressive logic: counts 0x801a7a (|LSER|<=0x808222, to 0x80821e), 0x801a7c (also road speed 0x80a9d0 < 0x808226, else clr). Inhibit 0x80dac2 set: road > 0x808224, or latch 0x801a76==1 and ((LSER+0x80822c<0 and 0x80bccf&4==0) or (road>=0x808226 and 0x801a7a==0x80821e)). Release when 0x801a7c == 0x80821e (clr inhibit, clr latch). Not inhibited: state 0 -> 1 with 0x803c96&0x1000 and (LSER > 0x80822a or (LSER > 0x808228 and rpm+0x808220 < prev 0x801a78)); state 1 -> 0 if LSER < 0x808228-0x80822e, or (LSER < 0x80822a and rpm > prev+0x808220). Inhibited + state 1 -> 0. State 1 -> latch=1, req ptr 0x80dad6 = 0x808230. prev rpm 0x801a78 = rpm.
- 0x26252: 0x801a78 = rpm; clr 0x801a7a; clr 0x801a7c.
- 0x2626a: clr 0x801a76 only.
- 0x262fa: jsr 0x26252; jsr 0x26462.
- 0x26308: jsr 0x2626a; clr 0x80daca; copy 0x808314/16/18 -> 0x80dad0/d2/d4.
- 0x26340 gear: only state 11 (0x80a8f2) and 0x80dac2==1; LSER > 0x80831e or < 0x808320 or 0x80a9d4 != 0 -> clr state, clr timer 0x801a7e. Timer ++ to 0x808322. ratio = 0x80a9d2*0x80a9f8 >>11; ratio > 0x80831a -> clr state. state 0, timer==time, 0x803c96&0x4000, ratio < bp1-hyst: (0x2000 clear or ratio > bp2) -> state 2 / ptr 0x80832c; else ratio < bp2-hyst -> state 3 / ptr 0x808326.
- 0x26462: clr 0x801a7e; 0x80a9f8 = 0x803d40.
- 0x26474 idle adjust: 0x803c9a&8 clear -> adj=0; or (0x80600e&2 and 0x806aca&2) -> adj = 0. Else rising edge 0x80bccf&0x20 (prev 0x801a80) -> +step 0x808332, limit 0x803fcc-0x803b9e; rising edge &0x40 (prev 0x801a81) -> -step, limit 0x803fca-0x803b9e. desired 0x80db06 = base + adj; 0x803cac&1 -> 0x805f0a = adj else 0; prev bytes stored.
- 0x2658c: 0x803cac&1 -> adj 0x801a82 = 0x805f0a, else clr both; clr 0x80db08; 0x803fca raised to 0x808342 (bcc); 0x803fcc lowered to 0x808344 (bls).
- 0x26616 cold idle: cold = coolant 0x80a336 < 0x80833a; d1 = 0x803cac&0x4000 && 0x80db08; state 1: clr timer 0x801a84, LSCIRF 0x80db04 = 0x80833c or 0; state 2: skip; else cold&timer<time -> ++; state 3 and (timer>=time or warm): ramp by 0x808340 to 0. raise desired 0x80db06 to LSCIRF unless d1.
- 0x266d2: jsr 0x26474; rts.
- 0x2595a: steady (0x80d340 != 0) lookup 0x80d372 at x=0x80daee,y=400 -> 0x1e02a; transient (factor < 0x4000) 0x80d388; select / blend mulu.l >>14, clamp 0..0x1700 -> 0x801a6e.
- 0x25a34 preset: bsr 0x2595a; 0x80daec = clamp(0x80823a + 0x801a6e, 0..0x1700); integ = final_fueling 0x80d32e - LSER*LSPPGN/960 + rpm*LSPP02GN/2226 (- 0x80db1c if 0x803cd4&0x200); limit 0x80823c..0x80daec; 0x801a6a = <<16; 0x80dade = final_fueling; clr 0x80dae4; prev rpm/gains.
- 0x25b1c run: see disasm (verified sequence of investigator / describer). Integrator also subtracts 0x80d350 << 16 each pass (not mentioned by either).
- 0x25ff2 speed error preset: LSER = clamp(LSFTGN*(LSAJRFES - rpm - LSDPOFES)>>9, LSFTMN..LSFTMX) -> filter acc preset; jsr 0x262fa; prev rpm 0x801a70.
- 0x26078: 0x801a62 = 0x808258; 0x801a5a = 0x80823e; jsr 0x26308; 0x80dae8 = 0x1700.

## Verified facts (round 2)
- Callers (callers.py): 2595a <- bsr 25a50, 25e32; 25a34 <- 25cb8; 25b1c <- jsr 1b5d4 (phase 2); 25ff2 NO caller; 26078 <- jsr 2880a; 2609c <- 262ae; 26252 <- 262fa; 2626a <- 26318; 26272 <- bsr.s 262be; 2629e <- 25c9e; 262fa <- 26066; 26308 <- 2608c; 26340 <- jsr 1b5da (phase 2); 26462 <- 26300; 26474 <- 266d2; 2658c <- 287d4; 265e6 <- 262b4; 26616 <- jsr 1b7a8 (phase 4; stray hit 23846 is cmp.b code); 266d2 <- jsr 1b7a2.
- CM848 twins: 0x28b38 / 0x289d0 same steps/constants/position as CM550 0x265e6 / 0x26272 (disasm_func). TWIN confirmed.
- CM848 0x27d38 blends with mullw/srawi/addze, no 0..0x1700 clamp, ble (signed) factor test, separate-args 2D lookup -> counterpart.
- 0x80bccf = debounced switch byte 1 (e2m 000E +1): bit2 0x4 = DSCHSWSS CLUTCH switch, bit5 0x20 = DSICSWSS idle increment, bit6 0x40 = DSDTSWSS idle decrement. CM848 aggressive logic uses switch_input_state_bits.clutch_switch at the same test.
- 0x806aca = fault_processing_enable_flags[7]; 0x80600e word 7 bit 1 has no e2m bit record (JC39TMER is bit 0).
- RAM: ptr 0x80dada = req 0x80dad6 = 0x808230; working gains 530/283/55 = 0x808230/32/34; default 132/215/66 = override copy = high/middle sets; J1939 set 124/57/55; user=final=1; latch 0x801a76=1; inhibit 0; engine STOPPED; adj state 11. rear_axle_ratio 499 = low = high cal (499) -> cannot tell which.
- 0x1e02a also called through a4 by cm550_calculateFourDimensionalFueling (0x1de64) - plate list misses it.
- 0x807a54 at 0x1d708: selectEngineSpeedLimit floors the speed limit at LSRF + LSRFOF in its state 9 (not 'adds to LSRF').
- run LSG: P2 and D2 are SUBTRACTED from the sum (sub.l at 0x25f52 / 0x25f66); integrator also subtracts FSAPITAJ 0x80d350 << 16 each pass.
- Enum: override gain state (0x80dace / CM848 0x40ae80) 0 = no override; typing it LOW_SPEED_GOVERNOR_GAIN_STATE renders '== 0' as DEFAULT -> misleading -> keep word.

## Decisions (round 3)
- All proposed names free in CM550 (unique.py); CM848 hits are the intended same-record reuses (mnemonics checked in CHR e2m: LSFTMX/LSFTMN/LSFTGN/LSER/LSAJRFES/LSDSRFRP/LSRF/LSMNRF/LSMXRF/LSCICLTP/LSCITMLM).
- No overlaps for new rows / struct instances (overlap.py). CM550 round 91 precedent DELETES rows inside struct instances (900ff89c ASG gain sets).
- Types all match access widths and e2m signedness (LSDEGN word for mulu.w, LSRFESUL word for bls, LSDPOFES i16 for ext.l).
- AMEND 0x808256 -> low_speed_governor_adjusted_reference_speed_maximum (it caps LSAJRFES only; 'reference_speed' is LSRF's name here).
- AMEND 0x2626a -> cm550_clearLowSpeedGovernorAggressiveGainsUsedFlag (body = clr.w 0x801a76 only; 'reset ... logic' over-claims).
- AMEND 0x80dace type word (not enum); REFUTE CM848 0x40ae80 enum type (0 = no override, would render as DEFAULT).
- Plates: restore '(was ...; PR #53 round N)' history dropped for 0x25a34/0x25b1c/0x25ff2/0x26078/0x2658c/0x26616; fix 'switch 16 bit 2' -> clutch switch DSCHSWSS; idle switches DSICSWSS / DSDTSWSS; run LSG subtracts the gain 2 terms; 0x1e02a also called by cm550_calculateFourDimensionalFueling via a4; alpha reload in STOPPED/CRANKING/JUMP_START; 0x805f0a drop unproven 'non-volatile history area'; 0x25ff2 rear axle ratio is not proof (high cal also 499).
- CM848 0x40ae7c/0x40ae7e: keep the existing rich comments, append the typed note, rename twin references.
- Stale text to update elsewhere: CM550 0x80d340/0x80d372/0x80d388 comments and deleted_functions 0x25a30/0x26484 cite old names; CM848 0x5c4a6, 0x40ae80 comments + structure bit 15 comment cite cm848_select* twin names.

## Final verdict summary (written before StructuredOutput)
- Functions: CONFIRMED 0x2595a 0x2629e 0x265e6(twin 0x28b38) 0x26272(twin 0x289d0) 0x26340 0x262fa 0x26252 0x26462 0x266d2 0x34f8a 0x34e9a 0x35088; AMENDED name 0x2626a; AMENDED plate 0x25b1c 0x25a34 0x26078 0x26616 0x2609c 0x26308 0x25ff2 0x26474 0x2658c 0x1e02a.
- CM848 twin rows 0x28b38 / 0x289d0: shared names confirmed, plates get the history note (AMENDED for the comment only).
- Prototypes: all 3 CONFIRMED.
- Globals: 110 (107 CM550 + 3 CM848); AMENDED 0x805f0a 0x807aae 0x808256(name) 0x80a90e 0x80daee 0x80dace(type) 0x807a54 0x80dac2 0x80822c 0x801a76 0x801a80 0x801a81 CM848 0x40ae7c 0x40ae7e; REFUTED CM848 0x40ae80; rest CONFIRMED.
- Enum members 0-4 CONFIRMED.
