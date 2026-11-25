# J2 investigator run 2: functions outside the batch list that belong to the same family and carry wrong names,
# two more globals, the three source address words and the new enum members. build_result.py appends them.
functions = []
globals_ = []
enum_members = []


def fn(**k):
    functions.append(k)


def g(address, current, proposed, typ, comment, evidence, confidence="high", firmware="CM550"):
    globals_.append(dict(firmware=firmware, address=address, current_name=current, proposed_name=proposed,
                         proposed_type=typ, comment=comment, evidence=evidence, confidence=confidence))


OUTSIDE = " (Outside the batch list: added because it belongs to this family and its current name is wrong.)"

fn(address="0x1fd6c", current_name="cm550_j1939TimeoutDataClearHandler",
   proposed_name="cm550_clearExpiredJ1922ControlOccurrences", relation="standalone",
   cm848_address="", cm848_current_name="",
   role="With the J1922 monitor clear enabled it zeroes the eight J1922 control occurrence records once the last control time plus the clear occurrence time lies before key_on_hour_meter.",
   discriminator="The only code that clears the JC22* records 0x804164-0x80417b and the only reader of the clear occurrence time 0x808190; it reads the clear enable bit 0x100, not the monitor enable bit 0x80 of its sibling 0x1fdc0, and it has no argument." + OUTSIDE,
   plate_comment="Clears the J1922 monitor's records when they are old: with algorithm_enable_flags_2_cal.j1922_monitor_clear_enable set (e2m JC22CCSW) and the last control time 0x804166 (e2m 1101 +2 JC22TM) + the clear occurrence time 0x808190 (10E7 +12 JC22CCTM) before key_on_hour_meter, it zeroes the total count and time and the speed / torque / limit counts and times (the eight records that cm550_recordJ1922ControlOccurrence writes). Called by the task set 0x1b6d6. Nothing in it concerns J1939 or a timeout. CM848 has no counterpart: its j1922_monitor_clear_enable has no reader (was cm550_j1939TimeoutDataClearHandler; PR #53 round 93)",
   evidence="0x1fd6c move.w (0x803c98),d0 / andi.l #0x100 / beq to the rts; 0x1fd7a move.l (0x804166),d0; 0x1fd80 add.l (0x808190),d0; 0x1fd86 cmp.l (0x80bda4),d0 / bcc to the rts (so it acts only when the sum is below key_on_hour_meter); 0x1fd8e clr.w (0x804164), 0x1fd94 clr.l (0x804166), 0x1fd9a clr.w (0x804170), 0x1fda0 clr.l (0x804172), 0x1fda6 clr.w (0x804176), 0x1fdac clr.l (0x804178), 0x1fdb2 clr.w (0x80416a), 0x1fdb8 clr.l (0x80416c). These are the addresses 0x1fdc0 counts and stamps. One caller: jsr at 0x1b6d6. CM848: algorithm_enable_flags_2_t.j1922_monitor_clear_enable 'no reader in this build' (frozen structure_definitions.csv:2175); the record J1922_Clear_Occurrence_Time (0x5c394) has no row.",
   confidence="high")

fn(address="0x142a8", current_name="cm550_canBusConfigTypeSelector",
   proposed_name="lookupJ1939ControlDevice", relation="twin",
   cm848_address="0x53a4c", cm848_current_name="cm848_lookupJ1939ControlDevice",
   role="Returns the control device code of a source address: 1 when it equals the configured transmission source address, 2 for the anti-lock brake address, 3 for the anti-slip regulation address, else 4.",
   discriminator="A pure lookup: one byte argument compared with the low bytes of three calibration words, four constant results and no store; it configures no CAN bus and selects no type." + OUTSIDE,
   plate_comment="Returns the J1939 control device of a source address, the code of e2m JCEGCOID / JCRDCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': 1 when it equals the low byte of the transmission source address word 0x60f82 (e2m 10E3 +4 JCTRSA), 2 for the anti-lock brake address 0x60f84 (JCABSA), 3 for the anti-slip regulation address 0x60f86 (JCARSA), else 4. processEngineTsc1Request stores the result in the engine control device word 0x80da4e and cm550_retarderControlModeHandler in the retarder's 0x80d9e6. Twin of CM848 0x53a4c (one shared name; was cm550_canBusConfigTypeSelector; PR #53 round 93)",
   evidence="CM550 | CM848: 0x142a8 move.w (4,a7),d1 | the argument in r3. 0x142ac cmp.b (0x60f83),d1 / bne / moveq #1 | 0x53a50 lhz 0x5a470 / clrlwi 24 / cmpw / bne / li 1. 0x142b8 cmp.b (0x60f85) / moveq #2 | 0x53a6c lhz 0x5a472 / li 2. 0x142c4 cmp.b (0x60f87) / moveq #3 | 0x53a88 lhz 0x5a474 / li 3. 0x142d0 moveq #4 | 0x53aa0 li 4. The same steps in the same order with the same constants; both read the low byte of a word record. The records are the same: CM550 e2m 10E3 +4 JCTRSA -> 0x60f82, +6 JCABSA -> 0x60f84, +8 JCARSA -> 0x60f86; CM848 10E3 +4 / +6 / +8 -> 0x5a470 / 0x5a472 / 0x5a474 (j1939_transmission_source_address / j1939_anti_lock_brake_source_address / j1939_anti_slip_regulation_source_address). Call graph: CM550 jsr at 0x2f300 / 0x2f370 / 0x2f3fe (processEngineTsc1Request; the result goes to 0x80da4e at 0x2f308 / 0x2f378 / 0x2f406) and 0x2fa04 / 0x2fa46 (cm550_retarderControlModeHandler; to 0x80d9e6 at 0x2fa0c / 0x2fa4c) | CM848 processEngineTsc1Request three times and cm848_processEngineRetarderTsc1Request twice.",
   confidence="high")

fn(address="0x23820", current_name="cm550_diagnosticMessageValidator",
   proposed_name="refreshEngineTsc1IgnoredRequestEntry", relation="twin",
   cm848_address="0x53c68", cm848_current_name="cm848_refreshEngineTsc1IgnoredRequestEntry",
   role="Searches the engine ignored request list for the entry with the given network type, source address and control mode; when found it reloads the entry's countdown with the recovery time and returns 1, else 0.",
   discriminator="Of the list's functions it is the one that compares all three key fields (word 0, byte 2, word 4) and writes only the countdown; it validates no diagnostic message - its callers ignore the request when it returns 1." + OUTSIDE,
   plate_comment="Searches the engine ignored request list (8-byte entries at 0x801994, count byte 0x8019d0) for the entry with network type param 1, source address param 2 and control mode param 3: when found it reloads the entry's countdown with the recovery time 0x808188 (e2m JCTMRCTM) and returns 1, else 0. processEngineTsc1Request and the two J1922 command handlers (0x1f4e8 / 0x1f8bc) call it first and ignore the request on 1. Twin of CM848 0x53c68 (one shared name; was cm550_diagnosticMessageValidator; PR #53 round 93)",
   evidence="CM550 | CM848: 0x23824-0x2382c d4 = (0x18,a7), d5 = (0x16,a7), d1 = (0x14,a7) | r5, r4, r3. 0x23830 a0 = 0x801994, d3 = the count byte 0x8019d0 | 0x53c68 r8 = 0x3fb916, 0x53c78 lbz 0x3fb9a2. 0x23840 cmp.w (a0),d1 | 0x53c84 lha 0(r8) / cmpw r3. 0x23844 cmp.b (2,a0),d5 | 0x53c90 lbz 2(r8) / cmpw r4. 0x2384a cmp.w (4,a0),d4 | 0x53c9c lha 4(r8) / cmpw r5. 0x23850 move.w (0x808188),(6,a0) / moveq #1 | 0x53ca8 lhz 0x5c38c / sth 6(r8) / li 1. 0x23860 a0 + 8, next | 0x53cbc addi 8. 0x23868 clr.w d0 | 0x53cd0 li 0. The same steps in the same order with the same offsets (0 / 2 / 4 / 6, step 8); no capacity appears in this body. Call graph: both are called by the shared processEngineTsc1Request before it accepts a sender (jsr at 0x2f1ac | one call); CM550 also calls it from its J1922 handlers (jsr at 0x1f522 with (0, 0x4a, mode) and 0x1f904), code CM848 does not have.",
   confidence="high")

fn(address="0x23870", current_name="cm550_ioControlTimeoutTableLookup",
   proposed_name="cm550_refreshRetarderTsc1IgnoredRequestEntry", relation="counterpart",
   cm848_address="0x53cd8", cm848_current_name="cm848_refreshRetarderTsc1IgnoredRequestEntry",
   role="Searches the retarder ignored request list for the entry with the given source address; when found it reloads the entry's countdown with the recovery time and returns 1, else 0.",
   discriminator="It walks the 4-byte retarder list 0x8019bc by the count byte 0x8019d1 and compares one byte; the engine list's function 0x23820 compares three fields of 8-byte entries." + OUTSIDE,
   plate_comment="Searches the retarder ignored request list (4-byte entries at 0x8019bc, count byte 0x8019d1) for the entry with source address param 1: when found it reloads the countdown with the recovery time 0x808188 (e2m JCTMRCTM) and returns 1, else 0. cm550_retarderControlModeHandler calls it and ignores the request on 1. The counterpart of cm848_refreshRetarderTsc1IgnoredRequestEntry (0x53cd8), whose 6-byte entries are also matched by the control mode (was cm550_ioControlTimeoutTableLookup; PR #53 round 93)",
   evidence="0x23874 d1 = (0xc,a7); 0x23878 a0 = 0x8019bc; 0x23880 d3 = the count byte 0x8019d1; 0x23888 cmp.b (a0),d1; equal -> 0x2388c move.w (0x808188),(2,a0) / moveq #1; 0x2389c a0 + 4; 0x238a4 clr.w d0. One caller: jsr at 0x2f886 (cm550_retarderControlModeHandler). CM848 0x53cd8: lbz 0(r7) / cmpw r3, then lha 2(r7) / cmpw r4 (the mode), sth the recovery time to 4(r7), step 6: one more compare and another entry size, so a counterpart.",
   confidence="high")

fn(address="0x23920", current_name="cm550_phase3_countdown_timer_manager",
   proposed_name="cm550_processTsc1IgnoredRequestTimeouts", relation="counterpart",
   cm848_address="0x53dc8", cm848_current_name="cm848_processTsc1IgnoredRequestTimeouts",
   role="Counts the countdown of every entry of the engine and the retarder ignored request lists down by 1 and removes each entry that reaches 0 (the last entry moves into its place and the count drops).",
   discriminator="The only code that decrements the entry countdowns ((6,entry) of the 8-byte list, (2,entry) of the 4-byte list); it walks both lists from the last entry down and takes no argument." + OUTSIDE,
   plate_comment="Counts down the two ignored request lists once per pass, the third call of the odd frame task set 0x1b504: every entry's countdown (word +6 of the 8-byte engine entries at 0x801994, word +2 of the 4-byte retarder entries at 0x8019bc) drops by 1; an entry that reaches 0 is removed - the count byte (0x8019d0 / 0x8019d1) drops and, unless it was the last entry, the last entry is copied into its place. The sender is then no longer ignored. The counterpart of cm848_processTsc1IgnoredRequestTimeouts (0x53dc8), which also clears its blocked message bits (was cm550_phase3_countdown_timer_manager; PR #53 round 93)",
   evidence="Engine list 0x2392a-0x23982: a1 = 0x8019d0; a2 = 0x80198c + 8 x count (the entry before the list end: 0x80198c is the base 0x801994 - 8); d1 = count; 0x23948 subq.w #1,(6,a2) / bne next; 0x2394e d1 == count -> 0x23952 subq.b #1,(a1); else 0x23958 count - 1 and 0x23968-0x23976 copy word 0 / byte 2 / word 4 / word 6 from 0x801994 + 8 x count; 0x2397c a2 - 8, d1 - 1. Retarder list 0x23984-0x239ca the same with a4 = 0x8019d1, 0x8019b8 + 4 x count, subq.w #1,(2,a2), copy byte 0 and word 2 from 0x8019bc + 4 x count. One caller: jsr at 0x1b510 in the task set 0x1b504. CM848 0x53dc8 has the same two loops over 8-byte and 6-byte entries and, when an entry expires, clears high_idle_override_active_flag and bits of j1939_blocked_message_bits (a word CM550 does not have): more code, so a counterpart.",
   confidence="high")

fn(address="0x239d2", current_name="cm550_diagnosticStateInitializer",
   proposed_name="removeEngineTsc1IgnoredRequestEntry", relation="twin",
   cm848_address="0x53fa8", cm848_current_name="cm848_removeEngineTsc1IgnoredRequestEntry",
   role="Removes every entry of the engine ignored request list whose network type and source address equal the two arguments (the last entry moves into the gap and the count drops).",
   discriminator="Of the list's functions it is the one that matches on two fields (word 0 and byte 2, not the mode) and removes; it initializes nothing and touches no diagnostic state." + OUTSIDE,
   plate_comment="Removes the engine ignored request list entries (8-byte entries at 0x801994, count byte 0x8019d0) with network type param 1 and source address param 2, whatever their control mode: the count drops and, unless the entry was the last, the last entry is copied into its place. processEngineTsc1Request calls it when that sender sends control mode 0 (tst.w d3 at 0x2f18c), the J1922 command handlers when they accept a mode 1 / 2 / 3 command. Twin of CM848 0x53fa8 (one shared name; was cm550_diagnosticStateInitializer; PR #53 round 93)",
   evidence="CM550 | CM848: 0x239d6-0x239da d3 = (0x1a,a7), d1 = (0x18,a7) | r4, r3. 0x239de a4 = 0x8019d0, a1 = 0x801994; 0x239ea tst.b (a4) / beq out | 0x53fb0-0x53fc0 lbz the count 0x3fb9a2 / ble out. 0x239f2 a2 = base - 8 + 8 x count, d2 = count | 0x53fcc-0x53fd8 slwi 3 / add / addi -8, r7 = count. 0x239fc cmp.w (a2),d1 / bne | 0x53fe4 lha 0(r8) / cmpw r3. 0x23a00 cmp.b (2,a2),d3 / bne | 0x53ff0 lbz 2(r8) / cmpw r4. 0x23a06 d2 == count -> 0x23a0a subq.b #1,(a4) | 0x53ffc-0x5400c. Else 0x23a10 count - 1 and 0x23a1a-0x23a28 copy word 0 / byte 2 / word 4 / word 6 from base + 8 x count | 0x54014-0x54040 the same four copies. 0x23a2e a2 - 8, d2 - 1, loop while nonzero | 0x54044-0x54054. The same steps in the same order with the same constants; no capacity appears. Call graph: both are called by the shared processEngineTsc1Request (jsr at 0x2f198 | one call); each firmware has callers the other lacks (CM550's J1922 handlers: jsr at 0x1f62e / 0x1f686 / 0x1f71c / 0x1f9fc / 0x1fa50 / 0x1fae6; CM848's cm848_updateParkNeutralFlagAndTsc1Activity).",
   confidence="high")

fn(address="0x23a3c", current_name="cm550_ioControlEntryRemove",
   proposed_name="cm550_removeRetarderTsc1IgnoredRequestEntry", relation="counterpart",
   cm848_address="0x54064", cm848_current_name="cm848_removeRetarderTsc1IgnoredRequestEntry",
   role="Removes every entry of the retarder ignored request list whose source address equals the argument (the last entry moves into the gap and the count drops).",
   discriminator="It walks the 4-byte retarder list 0x8019bc by the count byte 0x8019d1 and matches one byte; the engine list's remover 0x239d2 matches two fields of 8-byte entries. Nothing here is I/O control." + OUTSIDE,
   plate_comment="Removes the retarder ignored request list entries (4-byte entries at 0x8019bc, count byte 0x8019d1) with source address param 1: the count drops and, unless the entry was the last, the last entry (byte 0 and word 2) is copied into its place. cm550_retarderControlModeHandler calls it when that sender sends control mode 0 (tst.w d4 at 0x2f870). The counterpart of cm848_removeRetarderTsc1IgnoredRequestEntry (0x54064), whose entries are 6 bytes (was cm550_ioControlEntryRemove; PR #53 round 93)",
   evidence="0x23a40 d1 = (0x14,a7); 0x23a44 a4 = 0x8019d1, a1 = 0x8019bc; 0x23a50 tst.b (a4) / beq out; 0x23a58 a2 = base - 4 + 4 x count, d2 = count; 0x23a62 cmp.b (a2),d1 / bne next; 0x23a66 d2 == count -> subq.b #1,(a4); else 0x23a70 count - 1 and 0x23a7a move.b (a3),(a2) / move.w (2,a3),(2,a2) from base + 4 x count; 0x23a82 a2 - 4, d2 - 1. One caller: jsr at 0x2f878 (cm550_retarderControlModeHandler). CM848 0x54064 does the same over 6-byte entries (mulli 6; it copies byte 0, word 2 and word 4): another entry layout, so a counterpart.",
   confidence="high")

# ---- two rows whose current names say something else than the code
g("0x80da50", "datalink_speed_control_mode", "tsc1_override_control_mode", "word",
  "CM848's j1939_powertrain_control_state.tsc1_override_control_mode. e2m 10E8 +4 JCEGMD 'JCOMM CONTROL MODE 0 = DISABLE 1 = SPEED 2 = TORQUE 3 = LIMIT' (0-3): the control mode of the accepted engine control request - processEngineTsc1Request and the J1922 command handlers set it, cm550_resetEngineTsc1Request clears it. It is the mode of the whole request and not a speed control mode (the old name): cm550_recordJ1922ControlOccurrence counts 1 as speed, 2 as torque and 3 as limit control, and the timeout runner takes the speed control time limit for 1 and the torque control time limit for 2.",
  "The twins pair it with CM848 0x40adf8: cmpi.w #1,(0x80da50) at 0x21450 | lha 0x40adf8 == 1 at 0x50aefc (endRetarderShiftAssistAboveFuelDemandLimit); move.w (0x80da50),(6,a2) at 0x21ff4 | lha 0x40adf8 -> 6() at 0x50bf40 (startJ1939ControlSession). Mode values: the jump tables of the runner at 0x2347e / 0x234fa index it 0-3 (mode 1 -> (6,configuration) + 1, mode 2 -> (0xa,configuration) + 1); 0x231da pushes it to 0x1fdc0, whose 1 / 2 / 3 branches write the JC22RP* / JC22TQ* / JC22LM* records. Word accesses only (cmpi.w / tst.w / move.w / clr.w: 0x21450, 0x220ba, 0x231ec through a2, 0x23442, 0x2f03a ...).",
  "medium")
g("0x80da82", "retarder_command_inactivity_timer", "retarder_tsc1_request_time_limit_timer", "word",
  "CM848's j1939_powertrain_control_state.retarder_tsc1_request_time_limit_timer: the time limit of a retarder torque control request (mode 2) - the sender's tsc1_source_configuration_t retarder_torque_control_time_limit + 1 when the retarder request starts or changes, 0 for the other modes; counted down each pass, and at 1 the sender goes into the retarder ignored request list and the request ends. It limits an active request; it does not time inactivity (the old name).",
  "move.w d0,(0x80da82) at 0x23622 with d0 = (0x10 of retarder_tsc1_source_configuration_pointer) + 1 (0x23616-0x23620, mode 2 only); clr.w at 0x23630 (other modes) and 0x23230 (resetEngineRetarderTsc1Request, the fifth of its seven stores = CM848's store to 0x40ae24); tst.w / subq.w #1 at 0x23650-0x23658; cmpi.w #1 at 0x23678 -> jsr 0x238ec and jsr 0x23216. No other reference.",
  "high")

# ---- the three source address words that lookupJ1939ControlDevice reads (ROM above the 256 KB dump)
g("0x60f82", "", "j1939_transmission_source_address", "word",
  "CM848's j1939_transmission_source_address (0x5a470). e2m 10E3 +4 JCTRSA 'JCOMM TRANSMISSION SOURCE ADDRESS 1939 SOURCE ADDRESS FOR TRAN(SMISSION)' (0-255): the address in the low byte 0x60f83. lookupJ1939ControlDevice returns 1 (TRANS) for it, and the ETC1 (PGN 61442) receive handler 0x2efd0 takes ETC1 only from this address (0xff = from any). ROM beyond the 256 KB dump, so no value.",
  "cmp.b (0x60f83),d1 at 0x142ac -> moveq #1; move.w (0x60f82),d1 at 0x2efec compared with the frame's source address byte, and cmpi.w #0xff,(0x60f82) at 0x2eff6. e2m_block_addresses.py --firmware cm550 10E3: +4 JCTRSA -> 0x060f82.")
g("0x60f84", "", "j1939_anti_lock_brake_source_address", "word",
  "CM848's j1939_anti_lock_brake_source_address (0x5a472). e2m 10E3 +6 JCABSA 'JCOMM ABS SOURCE ADDRESS SOURCE ADDRESS FOR ANTI-LOCK BRAKE DE(VICE)' (0-255): the address in the low byte 0x60f85; lookupJ1939ControlDevice returns 2 (ABS) for it. ROM beyond the 256 KB dump, so no value.",
  "cmp.b (0x60f85),d1 at 0x142b8 -> moveq #2. e2m 10E3 +6 JCABSA -> 0x060f84.")
g("0x60f86", "", "j1939_anti_slip_regulation_source_address", "word",
  "CM848's j1939_anti_slip_regulation_source_address (0x5a474). e2m 10E3 +8 JCARSA 'JCOMM ASR SOURCE ADDRESS SOURCE ADDRESS FOR ANTI-SLIP REGULATI(ON DEVICE)' (0-255): the address in the low byte 0x60f87; lookupJ1939ControlDevice returns 3 (ASR) for it. ROM beyond the 256 KB dump, so no value.",
  "cmp.b (0x60f87),d1 at 0x142c4 -> moveq #3. e2m 10E3 +8 JCARSA -> 0x060f86.")


# ---- new enums for CM550: CM848's three enums of the same records (size 2)
def em(enum, value, member, comment, evidence, confidence="high"):
    enum_members.append(dict(firmware="CM550", enum_name=enum, value=value, current_member="", proposed_member=member,
                             comment=comment, evidence=evidence, confidence=confidence))


MODE_EVIDENCE = "e2m 10E8 +4 JCEGMD 'JCOMM CONTROL MODE 0 = DISABLE 1 = SPEED 2 = TORQUE 3 = LIMIT' (0x80da50) and 10E6 +0 JCRDMD 'JCOMM RETARDER CONTROL MODE 0 = DISABLE 2 = TORQUE 3 = LIMIT' (0x80d9e4). "
em("TSC1_OVERRIDE_MODE", 0, "TSC1_OVERRIDE_OFF",
   "New enum in CM550 (size 2), CM848's enum of the same records: 0 = no control request (e2m 0 = DISABLE). The reset functions store it",
   MODE_EVIDENCE + "clr.w on the engine mode at 0x231ec (a2 = 0x80da50) and clr.w (0x80d9e4) at 0x23216; the runner's jump tables give mode 0 no time limit (0x23486) and no timeout test (0x234fa entry 0 -> 0x2358c).")
em("TSC1_OVERRIDE_MODE", 1, "TSC1_SPEED_CONTROL",
   "1 = speed control (e2m 1 = SPEED): counted in the J1922 speed control records, timed with the speed control time limit",
   MODE_EVIDENCE + "0x1fdc0 mode 1 -> JC22RPCU 'J1922 SPEED CONTROL MODE COUNT' (0x1fdec); runner mode 1 -> time limit = (6,configuration) + 1 = speed_control_time_limit (0x2348a); cmpi.w #1,(0x80da50) at 0x21450 and 0x2f03a.")
em("TSC1_OVERRIDE_MODE", 2, "TSC1_TORQUE_CONTROL",
   "2 = torque control (e2m 2 = TORQUE): counted in the J1922 torque control records, timed with the torque control time limit",
   MODE_EVIDENCE + "0x1fdc0 mode 2 -> JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT' (0x1fe08); runner mode 2 -> (0xa,configuration) + 1 = torque_control_time_limit (0x2349c); cmpi.w #2 on the retarder mode 0x80d9e4 at 0x21440 (through a0) and 0x23610 (through a3).")
em("TSC1_OVERRIDE_MODE", 3, "TSC1_SPEED_TORQUE_LIMIT",
   "3 = speed / torque limit control (e2m 3 = LIMIT): counted in the J1922 limit records; it has no time limit",
   MODE_EVIDENCE + "0x1fdc0 mode 3 -> JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT' (0x1fe24); runner mode 3 -> time limit 0 (0x234ae); cmpi.w #3 on the retarder mode (a3 = 0x80d9e4) at 0x23636 / 0x2369a.")
DEVICE_EVIDENCE = "e2m 10E8 +2 JCEGCOID and 10E6 +2 JCRDCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN' (0x80da4e / 0x80d9e6). "
em("J1939_CONTROL_DEVICE", 0, "J1939_CONTROL_DEVICE_NONE",
   "New enum in CM550 (size 2), CM848's enum of the same records: 0 = NONE, the value the reset functions store",
   DEVICE_EVIDENCE + "clr.w (0x80da4e) at 0x231ee; clr.w (0x80d9e6) at 0x2321c.")
em("J1939_CONTROL_DEVICE", 1, "J1939_CONTROL_DEVICE_TRANSMISSION",
   "1 = TRANS: the sender is the transmission source address 0x60f82 (e2m JCTRSA)",
   DEVICE_EVIDENCE + "lookupJ1939ControlDevice (0x142a8) returns 1 for the byte 0x60f83; cmpi.w #1,(0x80da4e) at 0x2145a / 0x2f044 and cmpi.w #1,(0x80d9e6) at 0x21446.")
em("J1939_CONTROL_DEVICE", 2, "J1939_CONTROL_DEVICE_ANTI_LOCK_BRAKES",
   "2 = ABS: the sender is the anti-lock brake source address 0x60f84 (e2m JCABSA)",
   DEVICE_EVIDENCE + "0x142a8 returns 2 for the byte 0x60f85 (0x142b8-0x142c0).")
em("J1939_CONTROL_DEVICE", 3, "J1939_CONTROL_DEVICE_ANTI_SLIP_REGULATION",
   "3 = ASR: the sender is the anti-slip regulation source address 0x60f86 (e2m JCARSA)",
   DEVICE_EVIDENCE + "0x142a8 returns 3 for the byte 0x60f87 (0x142c4-0x142cc).")
em("J1939_CONTROL_DEVICE", 4, "J1939_CONTROL_DEVICE_UNKNOWN",
   "4 = UNKNOWN: any other source address",
   DEVICE_EVIDENCE + "0x142a8 returns 4 when no address matches (0x142d0).")
NETWORK_EVIDENCE = "e2m 10E8 +1C JCEGNETY 'NETWORK TYPE IN CONTROL OF ENGINE 0 = J1922, 1 = J1939' (engine_control_network_type 0x80da68). "
em("CONTROL_NETWORK", 0, "CONTROL_NETWORK_J1922",
   "New enum in CM550 (size 2), CM848's enum of the same record: 0 = J1922 (on the J1708 link)",
   NETWORK_EVIDENCE + "tst.w (0x801984) at 0x234b2: previous network 0 -> jsr 0x1fdc0, the J1922 record; a timeout with the network not 1 counts in the J1708 (J1922) count 0x804266 (0x2359c -> 0x236c2); the J1922 handler 0x1f4e8 stores 0 (clr.w (0x80da68) at 0x1f5de).")
em("CONTROL_NETWORK", 1, "CONTROL_NETWORK_J1939",
   "1 = J1939",
   NETWORK_EVIDENCE + "cmpi.w #1,(a5) at 0x23592 (a5 = 0x80da68): a timeout counts in the J1939 count 0x804268; cmpi.w #1,(0x80da68) at 0x220f8: only network 1 opens a J1939 control session.")
