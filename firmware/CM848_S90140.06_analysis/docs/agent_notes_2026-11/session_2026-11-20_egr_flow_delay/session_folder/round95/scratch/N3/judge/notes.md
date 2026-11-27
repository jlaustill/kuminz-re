# N3 judge notes (round 95)

Started 2026-11-25. No earlier judge notes existed.

## CM550 0x1fe84 scheduleJ1939PeriodicMessage prototype - CONFIRMED (checked)
- m68k.py 0x1fe84-0x1ff38: movem a3/a2/d2 (12 B); (0x10)=+4 move.l queue (beq q0 / cmp.l #1 q1 / else bra 0x1ff04 with a2 unset);
  (0x14)=+8 move.w -> entry+0; (0x18)=+12 moveq0/move.w/divs.l #10/add.w tick -> +4; (0x16)=+10 same -> +2; (0x1a)=+14 move.l -> +6; clr.b d0 / moveq #1 full.
- stack layout file: first_stack_offset 4, slot 2 -> +4 (4B) +8 +10 +12 (2B) +14 (4B): matches.
- only ref 0x28b8c (movea.l #0x1fe84,a4 in mc68k_initializeJ1939Datalink), 19 jsr (a4); pushes pea builder / w offset / w interval / w PGN / clr.l or pea (1).w; d0 never read.
- frozen .cpp: no body at 0x1fe84 (callers render scheduleJ1939PeriodicMessage(0,100)).
- struct j1939_periodic_transmit_entry_t field = pgn_key -> param name pgn_key OK.
## CM848 0x538c8c prototype - CONFIRMED (checked)
- cmpwi r3,0 (nonzero -> q1), sth r4 +0, divw r6/10 + tick -> +4, divw r5/10 -> +2, stw r7 +6, li r3,0 / li r3,1.
- 19 bl, all in cm848_j1939_system_init 0x5392c0-0x539500 (scan of rom + flash2); next insn after each = lis r7 (r3 unread).
- CM848 queue 1 calls: TWO (61440 ERC1 at 0x53934c li r3,1 and 65249 at 0x53936c) -> investigator's "one queue 1 call" / "18 of 19" is WRONG (17 of 19 in both).
- CM550 vs CM848 call lists differ: CM550 has 65266 / 65252, CM848 65241 / 65504; 61443 50 vs 20 ms, 65247 250 vs 50 ms. Plate's "the same 19 start-up calls" overclaims.
- getDataType: ushort/word/short -> WordDataType; uint/int/dword -> DWordDataType; int32_t signed; void* -> pointer to void.
## CM550 0x35088 cm550_tableLookup2D - name/prototype CONFIRMED, plate AMEND (caller count)
- link a6,#0 / movem d1-d6/a0-a5 / movea.l (8,a6),a2 = entry+4; record offsets +0/+2/+6/+8/+10/+14/+16/+20 = table_lookup_2d_arguments_t (structure_definitions rows 924-932, 22 B).
- exits write d0.w only (0x35180 / 0x35202 / 0x35208 / 0x3521a); unsigned (bcs/bcc, mulu/divu); end points clamp (exact flag d3/d5 = 1).
- call sites: 25 jsr (0x35088).l + 10 jsr (a5) (4 in cm550_fuelDemandTableBlendCalculator 0x1c65e, 6 in cm550_FUN_0001de58) = 35; all move.w d0 / andi.l #0xffff (0x1292a, 0x12c7e in vp44_FUN_000127c2). Plate's "The 25 callers" undercounts.
- counterpart of cm848_dualAxisTableInterpolation (7 register args + flags) - keep cm550_.
## CM550 J1708 pointers (block 1126) - all 6 CONFIRMED names/types; 3 buffer cells CONFIRMED
- init 0x1dd2c: TXIP=TXOP=0x808b00, TXMP=+1, *TXIP=0; RXIP=RXOP=0x808c00, RXMP=+1, *RXIP=0; 0x80ddc6=0x808b00, 0x80ddca=0x808c00, 0x80ddce=0x808cff.
- writer 0xb6e8: free = TXOP - TXIP (-2 / +0xfe); record at TXIP; TXIP past it; *TXIP=0 -> write pointer.
- SCI ISR 0x1e288: rx byte -> *RXMP, RXMP.b+1, (*RXIP)++; tx state 0 echo vs *TXMP; states 0/1 TXMP.b+1 send *TXMP; count == *TXOP -> state 2 checksum; state 3 TXOP = TXMP, TXMP.b+1.
- bus timer 0x300d4: *RXIP < 3 discard; bad sum discard (+[2][6][0x74] record); good: (*RXIP)--, RXIP.b = RXMP.b - 1, *RXIP = 0; no echo: TXMP = TXOP + 1.
- e2m 1126 +0 TXIP / +4 TXMP / +8 TXOP / +E RXIP / +12 RXMP / +16 RXOP; 1127 JC17TXBF 0x80ddc6; 1128 JC17RXBF 0x80ddca; no record at 0x80ddce.
- 0x80ddc6 / 0x80ddca / 0x80ddce: only code refs = the init (+ the 0x80ddca read for +0xff); parameter ID table words at 0x35cd4/8, 0x35cdc/e0.
- RAM: TXIP=TXOP=0x808b7d, TXMP=0x808b7e, RXIP=RXOP=0x808c00, RXMP=0x808c01, cells 0x808b00 / 0x808c00 / 0x808cff.
- names all unique in CM550 (grep).
## CM550 0x80d03e / 0x80d046 / 0x80d04a (block 100C) - names OK; 0x80d04a AMEND
- e2m ESACGR 4 B / ESCTGR 2 B / ESIPPE 4 B (+358) at these addresses.
- handlers 0x19acc / 0x19e90 / 0x1a52c / cm550_processPrimarySpeedPulsePeriodWithSyncPulse 0x1a95a: period from 0xffffa8 (move.l, clr.w); ring 0x80cd1e via 0x80cd08 with pulse_period_sum_primary 0x80d070; guarded add to 0x80d03e + saturating count 0x80d046 INSIDE the guard; crank degrees per period measurement (0x807ec4) into 0x80cd00.
- other readers of 0x80d04a: 0x1028a cm550_detectEngineSpeedSensorSyncPulse (-> 0x8001a8), 0x126be mc68k_FUN_0001266e (sum 0x8002a6 + count 0x8002aa). Investigator's "pulse period ring buffer (0x1028a)" is wrong: the ring is fed in the handlers.
- base-register scan (judge/base_scan.py over the full linear disassembly): only (a2)=0x80d04a long accesses; nothing reaches 0x80d03e-0x80d049 or 0x80d04c otherwise.
- 0x80d04c io_control_active_mask (untyped row) lies inside the 4-byte ESIPPE dword -> typing 0x80d04a dword swallows it: the row must go (no access).
## CM550 0x801d44 struct cm550_j1939_powertrain_messages_received_t - CONFIRMED (medium)
- abs refs: 0x801d44 (movea a1, ETC1 handler 0x2efd0 data[0]), 0x801d48 (data[4]), 0x801d4c (TSC1 0x2f128 a3 base: +0 data[0], +1 data[2], +2 data[1], +3 data[3]), 0x801d54 byte, 0x801d56 word, 0x801d58 byte. Nothing at 45-47 / 49-4b / 50-53 / 55 / 57 / 59.
- 0x801d3c = separate byte (cm550_FUN_0002ef4a, movea a3, (a3) only) 8 bytes before - as CM848 0x3fa97a before 0x3fa982.
- 0x801d5a = 32 x 6-byte table (0x2f47e registers: pgn word + pointer; count 0x801e1a = 0x801d5a + 0xc0; dump fe f1 00031c84) -> next object; record = 22 bytes.
- CM848 j1939_powertrain_messages_received_t (32 B): prev word, ETC1 image, ETC2 part, TSC1 image, accepted priority / speed / torque - same members same order.
- struct packing in ApplyStructures is sequential (offset += size; byte size>1 -> array) -> explicit padding fields needed: investigator's 13 fields sum to 22. Field names match CM848's.
- replaced rows (0x801d48 / 4c / 4d / 4f / 54 / 56 / 58) are quoted by no other CSV row except 0x801d58's comment (tsc1_accepted_requested_speed).
## CM848 0x29c98 / 0x29de0 maximum torque pair - CONFIRMED
- 0x29c98: 3 x bl 0x566cc (caches 0x3faf98 / 9c / a0; x = 0x40b7ba; y = 0 / chi lower<<14 cap 0xffff / chi upper<<14); bl 0x14528 (lower, upper, alpha0, 0x40a4a6, 0x40a4a8, chi_hundredths 0x40a49e, alpha_percent 0x40a494); sth 0x40aee6; 0 -> 1. Only call: bl at 0xb998 (cm848_periodicTaskSet_sensorProcessing).
- 0x29de0: sth 1 -> 0x40aee6, 2 -> the six cache words; only call bl at 0x549bc (cm848_applicationMain).
- note: cm848_convertTorqueDerateTorqueLimitToFuelLimit 0x1e4e8 ALSO writes 1 when 0 (investigator's "init is the only other writer" is wrong; not in the plate).
- CM550 counterparts cm550_calculate/initializeMaximumTorqueAtCurrentEngineSpeed (one lookup) -> cm848_ prefix right; names unique.
## CM848 0x29ecc dead leaf - name AMEND (module stem), plate amend (+CM550 counterpart)
- judge/ppc_reach.py: 0 refs (b/bl/bc/word/lis+addi/lis+ori in rom + flash2); controls 0x29e50 (bl 0xbab0) and 0x29e24 (bl 0x54a64) found.
- body 0x29ecc-0x29f38 verified (enable 0x3fd5ec & 0x100; lha 0x40a2f2 == 0; 0x40a2f0 -> 0x40aeea; lha 0x40aee8 > (signed) -> store, 0x40a2f4 &= ~1, 11 -> 0x40a2f2).
- CM550 cm550_applyMisfireTimingLimit 0x26af0: same steps / order / 0xfffe / 11; unsigned bls; live (timing chain step 1) -> not a twin (call graph) -> counterpart.
- live raise: cm848_calculateMainInjectionTiming line 51736 (injection_timing_demand, MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT).
- ImportAnalysis creates a function for a row whose address has none (disassemble + createFunction; plate applied on the second import pass).
## CM848 safety_* fault blend family - names CONFIRMED (12 rows)
- judge/ppc_dform.py: every access of 0x40b31e-0x40b326, 0x3fb3c0/c2, 0x4088e0/e2/e4/e8, 0x40891a is in cm848_applyFuelPressureGovernorFaultBlend 0x3889c or cm848_initializeFuelPressureGovernorFaultBlend 0x38a98.
- disassembly checked: gate lbz 0x4088e4; faults = fault_detected_cal +6 masks 0x200/0x400/0x800/0x1000 (fault_bit_words_t bits 9-12 = faults 57-60); table lookup -> 0x40b324; rising edge + final_fueling > table -> 0x40b320 = chi max 0x40a4ea; fraction +inc cap 25600 (only while start > table); no fault: 0 -> output = chi max; fraction - dec (clrlwi/cmpwi bge always -> 0x38a04 unreachable); output = start*(25600-f)/25600 + table*f/25600 -> 0x40b31e; < 0x40afac -> derate + source 62; prev = active.
- init: cache 2, 0x40b31e = 0x40b320 = 5888, fraction 0.
- RAM: 0x40b31e = 1030 = 0x40a4ea = 0x40afac, 0x40afae = 62; steps 1280; enable byte 1; axis/value tables start with the length word 48 (24 points) -> word[25] OK.
- names unique; note 0x40b214 fuel_pressure_fault_active_flag = same 4-fault condition (cm848_updateEngineWarningFlags) - similar but distinct name.
## CM848 0x40af7c governor_tuning_set_blend_weight -> all_speed_governor_ prefix CONFIRMED; comment AMEND
- users (D-form scan): 0xfd34 NoLoadFuel, 0xff18 cm848_calculateGovernorCompensatorCoefficients (writes all_speed_governor_droop + gains), 0x2c048/0x2c050 blendAllSpeedGovernorReferenceSpeeds, 0x2c10c init, 0x45fa0 EquivalentThrottle - all all-speed governor.
- e2m CHR 158D +0 ASG_Droop_Flag (2 B, 1/128) / +2 ASG_Max_RPM / +4 ASG_Min_RPM (0x40af7e / 0x40af80; block not in the dumped table); 1387 +8 ASG_Droop_Flag_Trim -> 0x3fd526 (EEPROM 0xa4).
- STALE in the proposed comment: "governor_speed_error_*_working set ... the _b set" - the sets are all_speed_governor_minimum/maximum_reference_speed_1_cal (weight 0) / _2_cal (weight 128) in the current decompile.
- ROM 0x5a9c4 [12, 1843, 2458, 3482, 6144, 10240, 40960]; 0x5a9d2 [12, 128 x 6].
## Enum J1939_PERIODIC_TRANSMIT_QUEUE - CONFIRM (0 comment amended), prototypes AMEND to use it
- runner gates: both firmwares datalink_broadcast_enable_flags bit 2 (JCEGBCEA engine) -> queue 0, bit 3 (JCRDBCEA retarder) -> queue 1; CM848 also needs j1939_dm13_broadcast_enable_flags bits 2 / 3.
- queue 1 calls: CM550 61440 + 65249, CM848 61440 + 65249 (17 of 19 calls use queue 0 in both).
- enums applied before function definitions in both builds (cmd_enums before cmd_import / export) -> a size-4 enum can type queue_index.
## Verdict summary (final)
- functions: 0x1fe84 AMENDED plate (19-call overclaim); 0x35088 AMENDED plate (35 call sites).
- cm848: 0x29c98 / 0x29de0 CONFIRMED; 0x29ecc AMENDED -> cm848_applyInjectionTimingMainMisfireLimit.
- prototypes: scheduler x2 AMENDED (queue_index enum type); 0x35088 CONFIRMED.
- globals: 0x80d03e / 0x80d04a / 0x40af7c AMENDED comments; rest CONFIRMED.
- leads: INJECTION_TIMING_INTERMEDIATE_SOURCE 11 (dead store), J1708 block struct-shaped (a4 base offsets), stale texts (cm550 function_definitions row for 0x1a95a quotes io_control_handshake_state; CM848 FUELING_STATE 62 comment quotes safety_fuel_blend_enable).
- 0x40aeea: only the init clear (0x29e40) and the dead leaf (0x29f04) store it (D-form scan). EEPROM 0xa4 = 0x0000.
- COUNT: 39 verdicts, 9 AMENDED (0x1fe84 plate, 0x35088 plate, 0x29ecc, 2 scheduler prototypes, 0x80d03e, 0x80d04a, 0x40af7c, enum member 0), 30 CONFIRMED, 0 REFUTED. STATUS: done, output submitted.
