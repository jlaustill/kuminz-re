# J2 investigator scratch notes (round 93)

## The "ROM table at 0x1b4da-0x1b4e9"
Not a table: the bytes are the absolute operands of three `jsr (xxx).l` (opcode 4eb9) inside the function
at 0x1b4d8 (CSV name vp44_evenPhaseSchedulerTaskSet, a name used twice: 0x1b4d8 and 0x1b62a).
0x1b4d8: jsr 0x212b2 / jsr 0x23244 / jsr 0x22070 / (0x1b4ea:) jsr 0x230ee / jsr 0x21edc / (0x1b4f6:) jsr 0x21070 /
jsr 0x420bc / rts.  The executive (executiveFrameInterruptHandler 0x1b876) calls 0x1b4d8 on every even phase
(0, 2, ... 38) and 0x1b504 (jsr 0x2142c / jsr 0x1ff38 / jsr 0x23920 / rts) on every odd phase.
CM848 cm848_phase_group_a_processing (0xb7b4) has the same list in one function:
dispatch / runTimeouts / trackSessions / serviceTransport / tickInputSupervision / processSwitchInputs /
endRetarderShiftAssist / runPeriodicTransmitQueues.

## Pairs (CM550 -> CM848)
- 0x1fdc0  -> none (CM848: j1922_monitor_enable has no reader; e2m block 1101 absent in CHR e2m)
- 0x1ff38  -> 0x538d3c cm848_runJ1939PeriodicTransmitQueues (CM848 adds the DM13 flags test) = counterpart
- 0x212b2  -> 0x538ef4 cm848_dispatchJ1939ReceivedMessages (DM13, TouCAN vs 82527) = counterpart
- 0x2142c  -> 0x50aec0 cm848_endRetarderShiftAssistAboveFuelDemandLimit = twin (asm compared)
- 0x21642  -> 0x50b1b8 cm848_writeJ1939DiagnosticMemoryByParameterId = twin
- 0x2167e  -> 0x50b228 (0x44) twin; 0x216c6 -> 0x50b298 (0x45) twin; 0x21714 -> 0x50b300 (0x47) twin;
  0x21778 -> 0x50b38c (0x49) twin
- 0x21872  -> 0x50b4d8 cm848_registerJ1939MemoryWriteServices = twin (ids 44 45 4b 4d 47 49 in that order)
- 0x21920  -> 0x50b5b4 cm848_buildJ1939LampStatusByte = counterpart (bits of one byte vs four flags)
- 0x21f4e  -> 0x50be6c twin; 0x21fac -> 0x50beec twin; 0x22070 -> 0x50bff4 twin
- 0x231da  -> 0x26f80 cm848_runTsc1LostManagement (CM848 added the TSC lost ramps) = counterpart, other role
- 0x23216  -> 0x27118 cm848_resetEngineRetarderTsc1Request = twin (7 stores, same order)
- 0x23244  -> 0x2715c cm848_runJ1939PowertrainControlTimeouts = counterpart
- 0x238ac  -> 0x53d3c cm848_addEngineTsc1IgnoredRequestEntry (5 vs 10 entries, extra CM848 caller) = counterpart
- 0x238ec  -> 0x53d84 cm848_addRetarderTsc1IgnoredRequestEntry (4-byte entry, no mode) = counterpart

## EEPROM mirror finding
mc68k_FUN_00026854 (0x26854, batch D1) loads EEPROM 0x0-0x1489 into RAM 0x803B0A-0x804F93 (end offset word
0x801a88 = 0x148a, then 0x64c for the refresh). vp44_FUN_00027c20 (called by mc68k_runPowerDownSequence) writes RAM
0x804156-0x804f91 back in 16-byte chunks. So 0x804156-0x804F93 is EEPROM-backed power-down data
(EEPROM 0x64C-0x1489). parameter_id_table: 0x1101 JC22CU = EEPROM 0x65A -> 0x804164, 0x10FD = 0x672 -> 0x80417C,
0x10FE = 0x6EC -> 0x8041F6, 0x10FF = 0x706 -> 0x804210, 0x1100 = 0x720 -> 0x80422A, 0x11C1 = 0x75C -> 0x804266.

## Leads outside the batch
- FUN_0001fe84 (no CSV row) = cm848_scheduleJ1939PeriodicMessage (0x538c8c) counterpart/twin
- 0x1fd6c cm550_j1939TimeoutDataClearHandler = clears the J1922 occurrence records (flags2 bit 8, JC22CCTM)
- 0x23820 / 0x23870 / 0x23920 / 0x239d2 / 0x23a3c = refresh engine / refresh retarder / process timeouts /
  remove engine / remove retarder ignored request entries
- 0x142a8 cm550_canBusConfigTypeSelector = lookupJ1939ControlDevice twin (1 / 2 / 3 / 4)
- 0x2322a cm550_statisticsTrackingFlagsReset = mid-body row inside 0x23216 (no jsr / bsr / pointer reaches it)
- 0x2efd0 = ETC1 (PGN 61442) receive handler, registered with key 0xf002 at 0x2f114

## Run 2 (resumed 2026-11-24 after an interruption) - every reused claim re-checked
- build_result.py assembles result.json from build_result_part1.py / part2.py (+ summary_notes.py); validate_result.py and
  validate_extents_mentions.py check it against the frozen CSVs; callers.py / ram.py / e2m_bits.py are helpers.
- RE-CHECKED against fresh disassembly (run2_asm_*.txt) and CM848 disasm: 0x1fdc0, 0x1fd6c, 0x1fe84, 0x1ff38, 0x212b2, 0x2142c,
  0x21642, 0x2167e, 0x216c6, 0x21714, 0x21778, 0x21872, 0x21920, 0x21f4e, 0x21fac, 0x22070, 0x231da, 0x23216, 0x23244,
  0x23820, 0x23870, 0x238ac, 0x238ec, 0x23920, 0x239d2, 0x23a3c, 0x142a8, 0x2efd0 - all claims of run 1 hold EXCEPT:
  * queue 1 entry 1 handler is 0x3407a (run 1 wrote 0x4007a)
  * J1708 (J1922) link timeout fault = word 7 MASK 0x8 (bit 3), ori.w #8,(0x80600e) at 0x236f0; J1939 = word 5 mask 0x400
    (run 1 wrote "bit 8" in two places). e2m JC39TMER says word 7 mask 1 (CM848's layout) - CM550's code differs: quote
    the masks from the code, not the e2m record.
- 0x231da -> 0x1fdc0 has NO network type test: a timed-out J1939 request is counted in the JC22* records too.
- The live CSVs moved on from the frozen copies: 0x1b4d8 = cm550_runEvery2FramesTaskSetPhase0, 0x1b504 =
  cm550_runEvery2FramesTaskSetPhase1 (commit 7cf52470), the mid-function row 0x2322a is already removed, and many
  'undefined' globals are typed now. Plate comments refer to the task sets by address.
- Flags in the dump: flags 2 (0x803c98) = 0x1870 -> J1922 monitor (0x80) and its clear (0x100) OFF, J1939 monitor (0x800)
  and shift assist (0x1000) ON; flags 11 = 0xb; broadcast enable 0xd; all session / J1922 records empty.
- CM848 0x40ad56 really is a BLOCK list (0x539060 cmpwi r30,0 / bne skips the handler scan); RAM dump 0x40ad54 = 0004 fe fe fe fe.
- Extras found wrong-named in the same family (not in the batch list): 0x142a8 = lookupJ1939ControlDevice twin (0x53a4c),
  0x23820 = refreshEngineTsc1IgnoredRequestEntry twin (0x53c68), 0x239d2 = removeEngineTsc1IgnoredRequestEntry twin (0x53fa8),
  0x23870 / 0x23a3c / 0x23920 counterparts of 0x53cd8 / 0x54064 / 0x53dc8, 0x1fd6c = clears the J1922 records.
  FUN_0001fe84 (no CSV row) = cm848_scheduleJ1939PeriodicMessage's counterpart (CM550 tests queue 0 / 1 / other, CM848 0 / else).
- Call order: CM550 even set 0x1b4d8 = dispatch / timeouts / track / 0x230ee / tick input supervision / 0x21070 / 0x420bc;
  odd set 0x1b504 = shift assist / periodic queues / 0x23920. CM848 group A has the same order in one function
  (cpp lines 6799-6806), 0x53dc8 sits in group B.

## Run 2 - final state (2026-11-24)
- result_full.json = the complete answer (26 functions, 67 globals, 17 enum members, long notes); built by build_result.py
  from build_result_part1.py (+ patch_part1_run2.py), part2 (+ patch_part2_run2.py), part3 (extras, enums) and summary_notes.py.
- result_compact.json / result_compact.min.json = the answer for the StructuredOutput call (about 63 KB): short texts from
  compact_functions.py / compact_comments.py / summary_notes_compact.py, evidence cut with ' ...', new-enum members left out.
  Built by compact2.py. Both pass validate_result.py.
- Late corrections: removeEngine / removeRetarder ignored request entry are called for control mode 0 in the TSC1 handlers
  (tst.w d3 at 0x2f18c, tst.w d4 at 0x2f870), for modes 1-3 in the J1922 handlers; 0x8019b8 has one absolute reference
  (0x2398e, the retarder list base - 4); 0x80da60 has nine more clr.w sites.
