"""Session 2 overrides for build_output.py (after the advisor's review): evidence re-derived from the disassembly
instead of the decompiler, relations, unproven statements dropped, swallowed rows named, the PGN 65252 note.
Imported by build_output.py and applied by address (functions / globals_ / enum_members are the builder's lists).
Round 93 batch D1 investigator; read-only on the repository."""


def apply(functions, globals_, enum_members):
    def fnset(address, **fields):
        hit = [f for f in functions if f["address"] == address]
        assert len(hit) == 1, address
        hit[0].update(fields)

    def glset(address, **fields):
        hit = [g for g in globals_ if g["address"] == address]
        assert len(hit) == 1, address
        hit[0].update(fields)

    # wrappers whose CM848 slot mate shares no task: standalone (slot mate kept in the evidence)
    for a in ("0x0001b754", "0x0001b7f2", "0x0001b70c"):
        fnset(a, relation="standalone", cm848_address="", cm848_current_name="")
    fnset("0x0001b754", discriminator=(
        "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 1 and 21 only (bsr.w at "
        "0x1b99e and 0x1bc5c). Two of its three callees (0x4115a, 0x41256) are above the dumped ROM, so no role name "
        "can be proven; the slot is what the code shows. CM848's slot mate (cm848_periodicTaskGroup26_calibration8) "
        "shares no task with it, so standalone."))
    fnset("0x0001b7f2", discriminator=(
        "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 11 and 31 only (bsr.w "
        "at 0x1bafa and 0x1bd88). Three of its four callees (0x46aac, 0x40b30, 0x422b4) are above the dumped ROM. "
        "Nothing in it touches the VP44 pump, so the vp44_ prefix does not hold. CM848's slot mate "
        "(hpcr_periodicTaskGroup36_calibration15) shares no task with it, so standalone."),
          plate_comment=(
        "Executive frame task set: runs every 20 frames (100 ms), in frames 11 and 31 of the 40-frame cycle, as "
        "call 6 of those frames in executiveFrameInterruptHandler. Calls, in order: 0x46aac (not dumped), "
        "cm550_runIdleShutdownStateMachine, 0x40b30 (not dumped), 0x422b4 (not dumped). CM848's slot mate is "
        "hpcr_periodicTaskGroup36_calibration15, with a different task list."))
    fnset("0x0001b70c", discriminator=(
        "Its position in the dispatch: the fifth call (the 10-frame set) of executive frames 5 / 15 / 25 / 35 "
        "(bsr.w at 0x1ba24, 0x1bb86, 0x1bcd0, 0x1be02), and a single jsr to 0x254b6. Nothing in it concerns timing "
        "or pressure. CM848's slot mate (cm848_periodicTaskGroup17_calibration5) shares no task with it, so "
        "standalone."))
    fnset("0x0001b788", discriminator=(
        "Its position in the dispatch: the sixth call (the 20-frame set) of executive frames 3 and 23 only (bsr.w at "
        "0x1b9e6 and 0x1bc98). Its first callee 0x491b4 is above the dumped ROM and the three dumped ones belong to "
        "two subsystems, so the slot is the name. Counterpart as the slot mate: CM848's set starts with the same "
        "two percent load calculations and shares nothing else."))

    # 0x254b6: say only what was shown about CM848
    fnset("0x000254b6", evidence=(
        "0x254c6 tst.b 0x8019d2 -> jsr 0x24858 and return; 0x254da jsr 0x24d40, tst.b d0; 0x254e4 jsr 0x249ee, tst.b "
        "d0; 0x254ee move.b #0x7d to 0x8019e7 and jsr 0x24f30; 0x254fc-0x25502 count (a2 = 0x801a22) up to 0x191; "
        "0x25504-0x25514 0x64 <= count < 0x190 and tst.w (a3 = 0x80daae) -> jsr 0x25316; 0x2551a tst.w 0x80dab0 or "
        "0x25522 tst.b 0x801a1c -> jsr 0x253b0; 0x25530 tst.w 0x803c42, tst.w (a3), cmpi.w #3 on engine_state -> jsr "
        "0x25448; 0x2554c-0x25588 the three sne of 0x80bccf masks 0x20 / 0x40 / 0x80 into 0x8019eb / 0x8019ec / "
        "0x8019ed. Single caller: jsr at 0x1b70c (frames 5 / 15 / 25 / 35). e2m: 1094 +10 OCITWNFG, +12 OCRSFG, 0008 "
        "+A6 OCRNSTEA, DSICSWSS / DSDTSWSS / DSTESWSS masks 0x20 / 0x40 / 0x80 at 000E +1. CM848: the three J1939 "
        "lamp flags 0x40ae62 / 64 / 66 are only read (cm848_buildJ1939LampStatusByte) and "
        "oil_change_monitor_change_due_flag 0x40ae5e is only written; no CM848 function was found in this role."))

    fnset("0x00024858", evidence=(
        "0x24868 tst.b 0x8019d3 (first pass): loop 0x2487c-0x248ba over the 16 words 0x611a8..0x611c6: cmpi.b #0x80 "
        "on 0x80bd1a + n / bhi skip, move.b #0x80 to it, or.b of 1 << (n & 7) into 0x80bcf6 + (n >> 3); 0x248bc "
        "clr.b 0x8019d3, 0x248c2 move.w #0x28 to 0x8019f8, pointer (a4 = 0x8019f4) = 0x611a8. Later passes: 0x248d2 "
        "addq.w #1 on 0x8019f0, cmp.w 0x8019f8 at 0x248de; 0x248e8-0x2492a the pointed output: priority 0x80 and "
        "and.b of the inverted bit; 0x2492e addi.w #0xa to 0x8019f8; 0x24936 addq.l #2,(a4); 0x2493a tst.w (next "
        "entry) / 0x24944 table end -> 0x24948 cmpi.b #1 on 0x8019d4: first time move.b #1 and addi.w #0x14 to "
        "0x8019f8 (0x2495a), second time loop 0x24974-0x24994 clr.b of each table output's priority, "
        "0x24998-0x249aa clr.b 0x8019d2 / 0x8019eb / 0x8019ec / 0x8019ed. Single caller: jsr at 0x254ce. LCLPONTM's "
        "scale (50 ms per count) and the 10-frame slot give the 50 ms tick."))
    fnset("0x000249ee", evidence=(
        "0x24a0a moveq #1,d2 (the result). 0x24a0c tst.w 0x80d67a: clr.b d2; phase (a2 = 0x8019dc) 0 -> ori.w #0x2 "
        "on (a3 = 0x80daac); == 0x611a0 -> andi.w #0xfffd; == 0x611a0 + 0x611a2 - 1 -> 0; flag 0x8019e0 = 1 "
        "(0x24a56); 0x24a60-0x24a70 request gone: flag and phase cleared, lamp bit off. 0x24a74 tst.w 0x80d28e: the "
        "same with phase (a1 = 0x8019da), ori.w #0x1 / andi.w #0xfffe and flag 0x8019e1. 0x24adc cmpi.w #1 on "
        "0x80d684 -> latch (a0 = 0x8019e2) = 1; 0x24aee-0x24b20 while latched: on at phase 0, off at cmpi.w #0xa, at "
        "cmpi.w #0x13 phase 0 and addq.b #1 on 0x8019e3; 0x24b22 cmpi.b #0x78 on 0x8019e3 -> lamp off, latch and "
        "count cleared, clr.w 0x80d684 (0x24b40). 0x24b46 move.b d2,d0. Single caller: jsr at 0x254e4 (result "
        "tested at 0x254ea). Request bits 0x1 / 0x2 -> outputs 1 / 6 (stop engine lamp / warning lamp) in 0x23a90."))
    fnset("0x00024d40", evidence=(
        "0x24d5c-0x24d74 gate: andi.l #0x80 on 0x80bccf and cmpi.w #1 on engine_state, else 0x24f12: tst.b 0x8019e8 "
        "-> clr.b, andi.w #0xfffe / #0xfffd on 0x80daac, moveq #1,d0. 0x24d78 move.b #1 to 0x8019e8. "
        "0x24d80-0x24dd8 diagnostic switch edge (tst.b 0x8019ed): current (a3 = 0x8019e7) = 0x7d, jsr "
        "0x24c5a(0x7d). 0x24ddc-0x24e2c andi.l #0x20 with tst.b 0x8019eb -> jsr 0x24c5a(current). 0x24e30-0x24e80 "
        "andi.l #0x40 with tst.b 0x8019ec -> jsr 0x24cd2(current). 0x24e82-0x24edc automatic mode: tst.b 0x80820c, "
        "repetition count (a4 = 0x8019ea) against 0x80820d once the cycle-complete byte (a5 = 0x8019e9) is set, jsr "
        "0x24c5a when the count is 0, addq.b #1,(a4). A new fault clears the lamp bits, the phase 0x8019d6, the "
        "cycle counter 0x8019d8 and the digit count 0x8019ee. 0x24ede cmpi.b #0x7d,(a3): ori.w #1 and #2, else jsr "
        "0x24b4e with the word at 0x8067c4 + 6 x index; 0x24f0a clr.b d0. Single caller: jsr at 0x254da (result "
        "tested at 0x254e0). e2m: switch masks DSTESWSS 0x80, DSICSWSS 0x20, DSDTSWSS 0x40 at 000E +1; 13EF +0 "
        "LCFUFHMD, +1 LCFUFHCU."))
    fnset("0x00024f30", evidence=(
        "0x24f5e-0x24f6a clr.w 0x80dab2 / 0x80dab4 / 0x80dab6; loop d2 = 1..active_dtc_list[0] (0x8058d4): flag word "
        "(2,a3,d0.l*2) with a3 = 0x8067c4 and d0 = 3 x fault index (= 0x8067c6 + 6 x index): andi.w #0x1 (0x24f94), "
        "#0x40 (0x24fba), bitmap byte 0x803fb6 + (index >> 3) bit index & 7 (0x24ffc-0x2500e), move.w #1 to "
        "0x80dab2 (0x25010); the same tests with #0x2 -> 0x80dab4 (0x250e6) and #0x4 -> 0x80dab6 (0x251b8), each "
        "followed by the #0x8 test that picks flashing or steady. Lamp blocks: stop (phase 0x8019da, ori.w #1 / "
        "andi.w #0xfffe, up to 0x25262), warning 0x25266-0x252b4 (phase a1 = 0x8019dc, bit 0x2), fluids "
        "0x252b8-0x25308 (phase a4 = 0x8019de, bit 0x4), each against 0x611a0 / 0x611a2. Single caller: jsr at "
        "0x254f6. CM848 reads the three flags (0x40ae62 / 64 / 66) in cm848_buildJ1939LampStatusByte and has no "
        "writer for them."))
    fnset("0x00025316", evidence=(
        "0x2532a cmpi.w #5 on (a0 = 0x801a16) / bcc exit; 0x25330 addq.w #1 on (a2 = 0x801a18); 0x25336-0x2533c "
        "count 1..5 ori.w #0x4 on (a1 = 0x80daac); 0x25344-0x25350 6..11 andi.w #0xfffb; 0x25358-0x25364 12..17 on; "
        "0x2536c-0x25378 18..23 off; 0x25380-0x2538c 24..29 on; 0x25394-0x253a0 30..47 off; 0x253a8 clr.w (a2), "
        "addq.w #1,(a0). Single caller: jsr at 0x25514 after cmpi.w #0x64 / #0x190 on 0x801a22 and tst.w 0x80daae "
        "(0x25504-0x25512). Bit 0x4 -> output 4 (e2m EPLPPZ 'engine protection lamp', LCEGPNLP mask 0x10) in "
        "0x23a90 (0x23ad4-0x23afc)."))
    fnset("0x00025448", evidence=(
        "0x25464 tst.b (a1 = 0x801a1d): 0 -> 0x25468 addq.w #1 on (a2 = 0x801a1e), cmpi.w #0x8ca0 (36000) / bls "
        "exit, else move.b #1,(a1) and clr.w (a2). Nonzero -> 0x2547c addq.w #1,(a2): 1..0x13 ori.w #0x4 on (a0 = "
        "0x80daac) (0x25488); 0x14..0x4f andi.w #0xfffb (0x2549a); else addq.w #1 on (a3 = 0x801a20) and clr.w (a2) "
        "(0x254a0); 0x254a4 cmpi.w #3,(a3) / bls, else clr.b (a1), clr.w (a2), clr.w (a3). Single caller: jsr at "
        "0x25546 after tst.w 0x803c42 (0x25530), tst.w 0x80daae (0x25538) and cmpi.w #3 on engine_state "
        "(0x2553c)."))
    fnset("0x0002482e", evidence=(
        "0x2482e move.b #1 to 0x8019d2; 0x24836 move.b #1 to 0x8019d3; 0x2483e clr.b 0x8019d4; 0x24844 clr.b "
        "0x8019e9; 0x2484a clr.b 0x8019ea; 0x24850 clr.w 0x8019f0; 0x24856 rts. Callers: jsr at 0x287c2 (start-up "
        "list) and 0x2898a (restart entry 0x28978)."))
    fnset("0x000249b6", evidence=(
        "0x249c2 tst.w (a1 = 0x8019d8): 0 -> ori.w #0x1 on (a0 = 0x80daac), addq.w #1; 0x249ce cmpi.w #0xa -> andi.w "
        "#0xfffe, addq.w #1; 0x249dc cmpi.w #0x14 -> clr.w (a1), moveq #1,d0, rts; else addq.w #1 and clr.b d0. "
        "Callers: jsr at 0x24bda, 0x24bfe and 0x24c22 (the three digit branches of 0x24b4e)."))
    fnset("0x00024b4e", evidence=(
        "Argument: the word at (0x18,a7) -> d2. 0x24b6e tst.w (a2 = 0x8019d6): 0 -> ori.w #0x2 and andi.w #0xfffe on "
        "(a5 = 0x80daac), phase + 1, digits: divs.l #100 -> (a4 = 0x8019e4), / 10 minus 10 x hundreds -> 0x8019e5, "
        "remainder -> 0x8019e6. 0x24bca cmpi.w #0x28: andi.w #0xfffd; digit count (a3 = 0x8019ee) against (a4): jsr "
        "0x249b6 and addq.b #1 on its 1, at the digit clr.b (a3) and phase + 1. 0x24bee cmpi.w #0x50 with "
        "0x8019e5; 0x24c12 cmpi.w #0x78 with 0x8019e6; 0x24c36 cmpi.w #0xa0: clr.w (a2), move.b #1 to 0x8019e9; "
        "else phase + 1 (returns 1; every other path returns 0). Single caller: jsr at 0x24ef8."))
    fnset("0x00024c5a", evidence=(
        "0x24c64 tst.b 0x8058d4 (list count) / beq -> moveq #125; argument byte at (0xd,a7) -> d2; loop d3 = "
        "1..count: 0x24c74 cmpi.b #0x7d,d2 -> index (a1 = 0x8019f2) = 1, else addq.b #1,(a1) and back to 1 when "
        "above the word 0x805994; fault = 0x8058d4[index]; 0x24ca8-0x24cb6 flag word 0x8067c6 + 6 x fault andi.w "
        "#0x40 / bne next; else return the fault; 0x24cca moveq #125. Callers: jsr at 0x24da0 (diagnostic switch "
        "edge), 0x24df8 (idle increment edge), 0x24eaa (automatic mode)."))
    fnset("0x00024cd2", evidence=(
        "As 0x24c5a with 0x24cf2 subq.b #1,(a1) and, at 0 or for the argument 0x7d, index = the word 0x805994 "
        "(0x24cf6); the same 0x40 test at 0x24d16-0x24d24; 0x24d38 moveq #125. Caller: jsr at 0x24e4c (idle "
        "decrement edge)."))

    # 0x266da keeps its name (incomplete, not wrong): the extended plate comment stays, the rename goes to the notes
    fnset("0x000266da", proposed_name="mc68k_runSerialEepromWriteQueue", confidence="high",
          discriminator=(
              "The only code that touches the QSPI transmit / receive RAM for the EEPROM after start-up and the "
              "only user of the state dword 0x801a8a. The name stays: it is incomplete rather than wrong - it "
              "covers states 1 and 2, while state 0, the normal one, is the read stream that loads and refreshes "
              "the EEPROM mirror; the plate comment now says so."))

    fnset("0x000266da", plate_comment=(
        "Serial EEPROM driver step, run after each QSPI queue pass (by mc68k_serialEepromQspiInterruptHandler, and "
        "by polling during the start-up load). State 0 (eeprom_byte_write_state): it copies the 12 received words "
        "to the mirror at eeprom_mirror_base_pointer + eeprom_mirror_load_offset (the store is skipped while "
        "ram_refresh_enable is 0), advances the offset, wraps it at eeprom_mirror_load_length (setting "
        "eeprom_mirror_loaded_flag) and queues the next READ; when the write queue is not empty it goes to state "
        "1. State 1 sends command 6 (write enable) and command 2 (write) with the next queue entry (address word "
        "0x80BDA8 + 2 x read index, data byte 0x80C7A8 + index). State 2 sends command 5 (read status) until the "
        "write-in-progress bit is clear, then continues with the next write or returns to reading at the saved "
        "offset."))

    # wording fixes after the proofread
    fnset("0x00026834", discriminator=(
        "It is the interrupt entry (saves d0-d1 / a0-a1 and ends in RTE) and has no caller: 0x26854 stores its "
        "address in the RAM vector 0x808f20 (vector 0x51, the QSPI vector for QIVR 0x50). The driver step itself "
        "is 0x266da, which the start-up load loop of 0x26854 calls directly."))
    fnset("0x000253b0", role=(
        "Flashes the warning lamp three times (5 or 6 ticks on, 18 off; 50 ms per tick) to acknowledge a manual "
        "reset of the oil change monitor."))
    fnset("0x000254b6", role=(
        "The lamp control task (every 50 ms): runs the power-up lamp sequence, then by priority the fault code "
        "flash out, the shutdown warning flashes and the active fault lamps, plus the three oil change monitor "
        "flash patterns, and saves the idle increment / idle decrement / diagnostic switch states for edge "
        "detection."))
    fnset("0x00024c5a", discriminator=(
        "The forward one of the two selectors: it adds 1 to fault_list_navigation_index (back to 1 past the "
        "count), where its sibling 0x24cd2 subtracts 1 (back to the count at 0). Both skip faults whose "
        "definition flag 0x40 is set."))
    fnset("0x00024cd2", discriminator=(
        "The backward one of the two selectors: it subtracts 1 from fault_list_navigation_index and goes to the "
        "list count at 0, where its sibling 0x24c5a adds 1. Called only for the idle decrement switch edge."))
    fnset("0x0001db8a", discriminator=(
        "The start-up writer of the idle shutdown records: the only place that writes ISRSFG (= 1) in the dumped "
        "ROM and, apart from the state machine, the only writer of ISST, ISTM, ISOD and ISODFG. It is called once "
        "from the start-up list of mc68k_applicationMain, not from the executive."))
    glset("0x00800000", comment=(
        "Working value of cm550_updateDutyCycleMonitorLoadHistogram: (final fueling - no load fueling) x 10000 / "
        "(100 percent throttle fueling - no load fueling), signed, 0.01 percent. Its low word (0x800002) is copied "
        "to DCMNLDFA when it is not negative. The row 0x800002 rpm_control_timer_1 (typed word in the live CSV) is "
        "that low word and should go."))
    glset("0x00800006", comment=(
        "The duty cycle monitor's short term log period in 0.1 s ticks = DCMNSHTI (hours) x 36000 (18000000 in the "
        "dump): a short term map fills until its total reaches it. The row 0x800008 rpm_control_timer_previous "
        "(no ROM reference) is its low word and should go."))

    glset("0x008019d2", evidence=(
        "move.b #1 at 0x2482e (cm550_startPowerUpLampSequence); tst.b (0x8019d2).l at 0x254c6; clr.b at 0x24998 (the "
        "end of the sequence). Byte accesses only. Dump 0."))
    glset("0x0080d28e", evidence=(
        "tst.w at 0x24a74 (the lamp reader); move.w #1 at 0x19134 / 0x191e4 / 0x19242 and clr.w at 0x19018 / "
        "0x192ae in processDiagnosticLimitStatus (0x18fcc, the engine protection shutdown algorithm: it sets the "
        "flag when a channel's time over its threshold passes the warning time, before the shutdown command); clr.w "
        "at 0x186a4."))

    # swallowed rows named in the comments
    glset("0x0080546e", comment=(
        "The long term map counters of the duty cycle monitor (e2m 1125 DCMNLGMP, 0.1 s per count), indexed by the "
        "operating region 1 - 50 (entry 0 unused); they follow the table's byte count word at 0x80546c (204) and "
        "end at 0x80553a engine_overspeed_log. Eight live rows lie inside and should go (undefined type, no ROM "
        "reference): 0x8054a6 j1939_message_type_total_counter, 0x8054a8 vp44_sensor_diag_counter, 0x8054ac "
        "rpm_histogram_bin_1_counter, 0x8054ae loop_counter_snapshot_0, 0x8054b2 rpm_histogram_bin_2_counter, "
        "0x8054b4 loop_counter_snapshot_1, 0x8054b8 rpm_histogram_overflow_counter, 0x8054ba "
        "loop_counter_snapshot_2."))
    glset("0x0080bada", comment=(
        "The counters of short term processing map 1 (e2m 1120 DCSHPR01, 0.1 s per count), indexed by the operating "
        "region; they follow duty_cycle_monitor_short_term_processing_map_1_byte_count (0x80bad8, 204). No live "
        "row lies inside 0x80bada-0x80bba5."))
    glset("0x0080bba8", comment=(
        "The counters of short term processing map 2 (e2m 1121 DCSHPR02, 0.1 s per count), indexed by the operating "
        "region; they follow duty_cycle_monitor_short_term_processing_map_2_byte_count (0x80bba6, 204). No live "
        "row lies inside 0x80bba8-0x80bc73."))
    glset("0x00800010", comment=(
        "The 22-byte argument record of cm550_tableLookup2D for the steady state 4D fueling table (e2m 1055 / 1054 "
        "/ 1056 5DFL01XA / YA / ZA at 0x6086e / 0x6089a / 0x608a4): x input (+6, 0x800016) = the cutoff-limited "
        "engine speed, y input (+0xe) = 400 (100 percent throttle). table_lookup_2d_arguments_t is a NEW struct "
        "(layout in the notes). The live rows 0x800012 (unnamed dword), 0x800014 rpm_state_lookup_input, 0x800016 "
        "dma_desc1_dest_ptr, 0x80001a dma_descriptor_base2, 0x80001c dma_desc2_source_ptr, 0x800020 "
        "high_rpm_lookup_input and 0x800022 dma_desc2_dest_ptr lie inside it. No DMA is involved."))
    glset("0x00800026", comment=(
        "The 22-byte argument record of cm550_tableLookup2D for the transient 4D fueling table (e2m 1058 / 1057 / "
        "1059 5DFL00XA / YA / ZA at 0x6094c / 0x60978 / 0x60982): x input (+6, 0x80002c) = the cutoff-limited "
        "engine speed, y input = 400. The live rows 0x80002a dma_control_flags1, 0x80002e dma_descriptor_ptr2, "
        "0x800032 dma_control_flags2 and 0x800036 sensor_fault_debounce_counter_base lie inside it."))
    glset("0x00801a8a", comment=(
        "State dword of the serial EEPROM driver step: 0 = no write in progress (the read stream runs), 1 = send "
        "the next queued byte write, 2 = wait for the write to finish (status polling). It is not a CAN buffer: "
        "the can_buffer_setup_t instance at 0x801a8a should go, with its member rows 0x801a8c "
        "can_buffer_setup1_data_ptr, 0x801a90 can_buffer_setup1_unused_ptr and 0x801a94-0x801a9c "
        "(can_buffer_setup1_data, can_buffer_1_reserved_0-3, diag_can_response_data_0-2, .data[6]); 0x801a94 "
        "starts a 2D lookup record of cm550_FUN_000269f2."))

    # PGN 65252: the bit positions are the standard layout, not read from the local database
    first = True
    for m in enum_members:
        if m["enum_name"] == "IDLE_SHUTDOWN_STATE" and first:
            m["evidence"] += (" SPN positions for all six members: the SAE J1939-71 layout of PGN 65252 byte 1 "
                              "(bits 1-2 SPN 593, 3-4 SPN 594, 5-6 SPN 592, 7-8 SPN 590); the local database lists "
                              "the parameters in that order but stores no bit positions, and the builder's other "
                              "bytes follow the same order (byte 2 bits 7-8 by the enable bit = SPN 591, byte 3 "
                              "bits 1-2 the A/C switch = SPN 985, byte 4 bits 1-2 the wait to start lamp output = "
                              "SPN 1081).")
            first = False
