# J2 investigator: the globals[] and enum_members[] parts of the result (round 93).
globals_ = []
enum_members = []

POWER_DOWN = "Power-down data in the EEPROM image (EEPROM offset 0x%X): loaded at start and written back at power-down."


def g(address, current, proposed, typ, comment, evidence, confidence="high", firmware="CM550"):
    globals_.append(dict(firmware=firmware, address=address, current_name=current, proposed_name=proposed,
                         proposed_type=typ, comment=comment, evidence=evidence, confidence=confidence))


# ---- the J1922 monitor's records (e2m 1101) ----
g("0x804164", "j1939_message_total_timeout_count", "j1922_control_count", "word",
  "e2m 1101 +0 JC22CU 'CONTROL COUNT 0 = J1922 HASN'T CONTROLLED' (CNTS): the J1922 monitor's total count of control occurrences; cm550_recordJ1922ControlOccurrence adds 1 for every recorded mode 1 / 2 / 3 occurrence and the clear routine 0x1fd6c zeroes it. " + POWER_DOWN % 0x65A + " It counts no timeouts and nothing J1939 (the old name).",
  "addq.w #1,(0x804164) at 0x1fdec / 0x1fe08 / 0x1fe24; clr.w at 0x1fd8e; no other reference in the ROM. parameter_id_table 0x1101 = EEPROM 0x65A -> 0x803B0A + 0x65A.")
g("0x804166", "j1939_last_message_hour_meter", "j1922_control_last_time", "dword",
  "e2m 1101 +2 JC22TM 'J1922 MONITOR OCCURRENCE TIME ECM TIME OF LAST J1922 CONTROL' (4 bytes): key_on_hour_meter (0.2 s counts) at the last recorded occurrence of any mode; the clear routine 0x1fd6c clears the J1922 records once this time + the clear occurrence time 0x808190 is before key_on_hour_meter. " + POWER_DOWN % 0x65C,
  "move.l d0,(0x804166) at 0x1fe00 / 0x1fe1c / 0x1fe38 (d0 = key_on_hour_meter); move.l (0x804166),d0 at 0x1fd7a; clr.l at 0x1fd94.")
g("0x80416a", "", "j1922_limit_control_count", "word",
  "e2m 1101 +6 JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT 0 = J1922 HASN'T LIMITED ENGI(NE)' (CNTS): occurrences of control mode 3 (speed / torque limit). " + POWER_DOWN % 0x660,
  "addq.w #1,(0x80416a) at 0x1fe2a (the mode 3 branch); clr.w at 0x1fdb2.")
g("0x80416c", "", "j1922_limit_control_last_time", "dword",
  "e2m 1101 +8 JC22LMTM 'J1922 LIMIT ENGINE OCC. TIME ECM TIME OF LAST J1922 LIMIT COM(MAND)': key_on_hour_meter at the last mode 3 occurrence. " + POWER_DOWN % 0x662,
  "move.l d0,(0x80416c) at 0x1fe32; clr.l at 0x1fdb8.")
g("0x804170", "", "j1922_speed_control_count", "word",
  "e2m 1101 +C JC22RPCU 'J1922 SPEED CONTROL MODE COUNT' (CNTS): occurrences of control mode 1 (speed control). " + POWER_DOWN % 0x666,
  "addq.w #1,(0x804170) at 0x1fdf2 (the mode 1 branch); clr.w at 0x1fd9a.")
g("0x804172", "", "j1922_speed_control_last_time", "dword",
  "e2m 1101 +E JC22RPTM 'J1922 SPEED CONTROL OCC. TIME': key_on_hour_meter at the last mode 1 occurrence. " + POWER_DOWN % 0x668,
  "move.l d0,(0x804172) at 0x1fdfa; clr.l at 0x1fda0.")
g("0x804176", "", "j1922_torque_control_count", "word",
  "e2m 1101 +12 JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT' (CNTS): occurrences of control mode 2 (torque control). " + POWER_DOWN % 0x66C,
  "addq.w #1,(0x804176) at 0x1fe0e (the mode 2 branch); clr.w at 0x1fda6.")
g("0x804178", "", "j1922_torque_control_last_time", "dword",
  "e2m 1101 +14 JC22TQTM: key_on_hour_meter at the last mode 2 occurrence. " + POWER_DOWN % 0x66E,
  "move.l d0,(0x804178) at 0x1fe16; clr.l at 0x1fdac.")
g("0x808190", "j1922_clear_occurrence_time_time_from_last_j1922_control_befo_0_2_29", "j1922_clear_occurrence_time", "dword",
  "e2m 10E7 +12 JC22CCTM 'J1922 CLEAR OCCURRENCE TIME TIME FROM LAST J1922 CONTROL BEFO(RE the counts are cleared)' (SEC, 4 bytes; 0 in the dump): with flags 2 bit 0x100 set (JC22CCSW, the J1922 monitor clear enable) the routine 0x1fd6c clears the eight J1922 records once j1922_control_last_time + this is before key_on_hour_meter. CM848 has the record (ROM 0x5c394, no row) and no reader.",
  "add.l (0x808190),d0 at 0x1fd80 (the only reference), after move.l (0x804166),d0 and before cmp.l (0x80bda4),d0 / bcc.", "medium")

# ---- the J1939 monitor's records (e2m 10FD / 10FE / 10FF / 1100) ----
g("0x80417e", "", "j1939_control_session_history", "j1939_control_session_t[5]",
  "CM848's j1939_control_session_history_cal (0x3fead6). e2m 10FD JCHSTB 'J1939 HISTORY TABLE SEE J1939MON SPECIFICATION': the last five finished J1939 control sessions; storeJ1939ControlSessionInHistoryTable copies the closing record into entry 0x804232. The word before it (0x80417c = 0x0078) is the table's byte length. Dumps: five empty records (fe fe then zeros). " + POWER_DOWN % 0x674 + "",
  "0x21f6c movea.l #0x80417e,a0 + 24 x the index (0x21f64-0x21f72), then twelve move.w (a2)+,(a1)+ at 0x21f9c; no other reference. parameter_id_table 0x10FD = EEPROM 0x672 -> 0x80417c.")
g("0x8041f8", "", "j1939_active_engine_control_session", "j1939_control_session_t",
  "CM848's j1939_active_engine_control_session_cal (0x3feb50). e2m 10FE JCAEEG 'J1939 ACTIVE ENGINE STRUCTURE': the open engine control session - startJ1939ControlSession fills it, trackJ1939ControlSessions appends the mode changes and stores the duration. Layout from every access: +0 byte kind (0), +1 byte source address, +2 word control device, +4 word mode count, +6 five mode words, +0x10 dword start time, +0x14 dword duration. The word before it (0x8041f6 = 0x0018) is its byte length. Replaces the row 0x8041fc datalink_speed_snapshot_mode_count (the +4 count field). " + POWER_DOWN % 0x6EE,
  "0x21fdc clr.b (0x8041f8); 0x21fe2 move.b -> (1,a2); 0x21fea move.w -> (2,a2); 0x21fee move.w #1,(4,a2); 0x21ff4 (6,a2); 0x21ffc-0x22008 clr.w (8)..(0xe); 0x2200c move.l -> (0x10,a2); 0x22010 clr.l (0x14,a2). In 0x22070 through a5: (4,a5) cmpi.w #5 / addq.w, (6,a5,d0*2) move.w, (0xe,a5), (0x10,a5) / (0x14,a5) long. 0x21f8c copies its 12 words. No other reference.")
g("0x804212", "", "j1939_active_retarder_control_session", "j1939_control_session_t",
  "CM848's j1939_active_retarder_control_session_cal (0x3feb6a). e2m 10FF JCAERD 'J1939 ACTIVE RETARDER': the open retarder control session, kind 1; same layout and users as the engine record. The word before it (0x804210 = 0x0018) is its byte length. Replaces the row 0x804216 retarder_snapshot_mode_count (the +4 count field). " + POWER_DOWN % 0x708,
  "0x2202c move.b #1,(0x804212); 0x22034 move.b (0x80d9e9),(1,a3); 0x2203c (2,a3); 0x22044 move.w #1,(4,a3); 0x2204a (6,a3); 0x22052-0x2205e clr.w; 0x22062 move.l -> (0x10,a3); 0x22066 clr.l (0x14,a3). In 0x22070 through a4 with the same offsets (0x22230-0x22264, 0x221fa-0x221fe, 0x22274-0x22278). 0x21f94 copies its 12 words.")
g("0x80422a", "", "j1939_engine_control_active_flag", "word",
  "CM848's j1939_engine_control_active_flag_cal. e2m 1100 +0 JCEGCOSS 'J1939 ENGINE CONTROL STATUS 0 = INACTIVE' (0 / 1): 1 while a J1939 engine control session is open - startJ1939ControlSession(0) sets it, trackJ1939ControlSessions tests it and clears it when the control ends. " + POWER_DOWN % 0x720,
  "move.w #1,(0x80422a) at 0x21fce; cmpi.w #1 at 0x22104; clr.w at 0x220d8 / 0x2218c.")
g("0x80422c", "", "j1939_retarder_control_active_flag", "word",
  "CM848's j1939_retarder_control_active_flag_cal. e2m 1100 +2 JCRDCOSS 'J1939 RETARDER CONTROL STATUS 0 = INACTIVE': 1 while a J1939 retarder control session is open. " + POWER_DOWN % 0x722,
  "move.w #1,(0x80422c) at 0x2201a; cmpi.w #1 at 0x22210; clr.w at 0x221ee.")
g("0x80422e", "", "j1939_engine_control_source", "word",
  "CM848's j1939_engine_control_source_cal. e2m 1100 +4 JCEGCOSA '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the control device of the open engine control session, copied from the engine control device indicator 0x80da4e. " + POWER_DOWN % 0x724,
  "move.w (a1),(0x80422e) at 0x21fd6 with a1 = 0x80da4e; the only reference.")
g("0x804230", "", "j1939_retarder_control_source", "word",
  "CM848's j1939_retarder_control_source_cal. e2m 1100 +6 JCRDCOSA '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the control device of the open retarder control session, copied from 0x80d9e6. " + POWER_DOWN % 0x726,
  "move.w (0x80d9e6),(0x804230) at 0x22022; the only reference.")
g("0x804232", "", "j1939_control_session_history_next_entry", "word",
  "CM848's j1939_control_session_history_next_entry_cal. e2m 1100 +8 JCHSTBPO 'POINTER INTO J1939_HISTORY_TABLE': the history entry storeJ1939ControlSessionInHistoryTable writes next (0-4, wraps). " + POWER_DOWN % 0x728,
  "move.w (0x804232),d0 at 0x21f52; addq.w #1 at 0x21f58; cmpi.w #5 at 0x21f76; clr.w at 0x21f80.")
g("0x800b12", "", "j1939_monitor_engine_override_control_mode_previous", "word",
  "CM848's global of the same name (0x3fbd6c): trackJ1939ControlSessions' copy of the engine control mode 0x80da50 from its last pass; a change starts or ends an engine control session record. Working RAM.",
  "cmp.w (0x800b12),d0 at 0x22094; tst.w at 0x220c2; move.w (0x80da50),(0x800b12) at 0x2219a. The five monitor words sit in CM848's order (0x800b12 / b14 / b16 / b18 / b19 against 0x3fbd6c / 6e / 70 / 72 / 73).")
g("0x800b14", "", "j1939_monitor_retarder_override_control_mode_previous", "word",
  "CM848's global of the same name (0x3fbd6e): the monitor's copy of retarder_control_mode from its last pass.",
  "cmp.w (0x800b14),d0 at 0x221be; tst.w at 0x221e4; move.w (0x80d9e4),(0x800b14) at 0x2229a.")
g("0x800b16", "", "j1939_monitor_engine_control_data_link_previous", "word",
  "CM848's global of the same name (0x3fbd70): the monitor's copy of engine_control_network_type from its last pass (1 = J1939: a session to close).",
  "cmp.w (0x800b16),d0 at 0x220a2; cmpi.w #1 at 0x220cc / 0x22182; move.w (0x80da68),(0x800b16) at 0x221a4.")
g("0x800b18", "", "j1939_monitor_engine_controlling_source_address_previous", "byte",
  "CM848's global of the same name (0x3fbd72): the monitor's copy of datalink_command_source_id from its last pass; a new sender closes the session and opens another.",
  "cmp.b (0x800b18),d0 at 0x220b0 / 0x22114; move.b (0x80da70),(0x800b18) at 0x221ae.")
g("0x800b19", "", "j1939_monitor_retarder_controlling_source_address_previous", "byte",
  "CM848's global of the same name (0x3fbd73): the monitor's copy of the low byte of the retarder source address word 0x80d9e8.",
  "move.b (0x800b19),d1 at 0x221d0 / 0x22226 (compared zero-extended with the word 0x80d9e8); move.b (0x80d9e9),(0x800b19) at 0x222a4.")

# ---- the timeout runner's state ----
g("0x801982", "", "tsc1_override_control_mode_previous", "word",
  "CM848's global of the same name (0x3faf34): the engine control mode 0x80da50 at the end of the last cm550_runJ1939PowertrainControlTimeouts pass; cm550_resetEngineTsc1Request also keeps the ended mode here. In this firmware the mode may come from a J1922 command as well. The ten runner words 0x801982-0x801993 sit in CM848's order (0x3faf34-0x3faf43).",
  "move.w (a2),(a3) at 0x231ea (a3 = 0x801982); cmp.w (0x801982),d0 at 0x23448; move.w (0x801982),-(a7) at 0x234bc; move.w (0x80da50),(0x801982) at 0x235ba.")
g("0x801984", "", "tsc1_controlling_data_link_previous", "word",
  "CM848's global of the same name (0x3faf36): engine_control_network_type at the end of the last runner pass; 0 (J1922) makes a change of the request record a J1922 occurrence.",
  "cmp.w (0x801984),d0 at 0x23452; tst.w at 0x234b2; move.w (a5),(0x801984) at 0x235c4 (a5 = 0x80da68).")
g("0x801986", "", "tsc1_controlling_source_address_previous", "byte",
  "CM848's global of the same name (0x3faf38): datalink_command_source_id at the end of the last runner pass.",
  "cmp.b (0x801986),d0 at 0x23460; move.b (0x80da70),(0x801986) at 0x235ca.")
g("0x801988", "", "high_idle_override_active_flag_previous", "word",
  "CM848's global of the same name: high_idle_override_active_flag at the end of the last runner pass; its rise to 1 loads the override's time limit timer and counts as a new request.",
  "move.w (0x801988),d0 at 0x23268, compared with (0x80da54); move.w (0x80da54),(0x801988) at 0x235d4.")
g("0x80198a", "", "engine_retarder_override_control_mode_previous", "word",
  "CM848's global of the same name: retarder_control_mode at the end of the last runner pass; a change restarts the retarder request's time limit.",
  "move.w (0x80198a),d0 at 0x23386; cmp.w (0x80198a),d0 at 0x235f4; move.w (a3),(0x80198a) at 0x236b2 (a3 = 0x80d9e4).")
g("0x80198c", "", "engine_retarder_controlling_source_address_previous", "byte",
  "CM848's global of the same name (0x3faf3d): the low byte of the retarder source address word 0x80d9e8 at the end of the last runner pass.",
  "move.b (0x80198c),d1 at 0x23606; move.b (0x80d9e9),(0x80198c) at 0x236b8. (0x2393c loads the same address as the list base 0x801994 - 8; it is not an access.)")
g("0x80198e", "", "etc1_progressive_shift_disable_previous", "word",
  "CM848's global of the same name (0x3faf3e): the progressive shift disable flag 0x80da58 at the end of the last runner pass.",
  "move.w (0x80198e),d0 at 0x23306, compared with (0x80da58); move.w (0x80da58),(0x80198e) at 0x235de.")
g("0x801990", "", "etc1_out_of_gear_flag_previous", "word",
  "CM848's global of the same name (0x3faf40): the out of gear flag 0x80da56 (driveline_disengaged_flag, e2m JCOG) at the end of the last runner pass.",
  "move.w (0x801990),d0 at 0x23346, compared with (0x80da56); move.w (0x80da56),(0x801990) at 0x235e8.")
g("0x801992", "datalink_j1939_timeout_flag", "j1939_link_fault_clear_request_flag", "byte",
  "CM848's global of the same name (0x3faf42). It is not a timeout flag: the runner sets it when a J1939 control request starts or changes (the engine request with network type 1, or the retarder request) in a pass without a timeout; in a later pass without a J1939 timeout it clears the J1939 link timeout fault (error status word 5 mask 0x400) once that fault is in 0x806ac6 and gone from 0x80604a, then the flag.",
  "Through a4 = 0x801992 (movea.l at 0x23254): move.b #1,(a4) at 0x235ac / 0x23628 / 0x2363c; cmpi.b #1,(a4) at 0x237c0; clr.b (a4) at 0x237b8 / 0x23810 / 0x23818.", "medium")
g("0x801993", "datalink_j1708_timeout_flag", "j1708_link_fault_clear_request_flag", "byte",
  "CM848's global of the same name (0x3faf43): the J1708 (J1922) twin of j1939_link_fault_clear_request_flag - set when a control request on network type 0 starts or changes; it clears the J1708 link timeout fault (error status word 7 mask 0x8) and the count 0x804266.",
  "move.b #1,(0x801993) at 0x235b2; cmpi.b #1 at 0x23712; clr.b at 0x23708 / 0x23766 / 0x23774.", "medium")
g("0x80da7e", "", "tsc1_request_time_limit_timer", "word",
  "CM848's j1939_powertrain_control_state.tsc1_request_time_limit_timer: the time limit of a speed / torque control request - the sender's tsc1_source_configuration_t speed_control_time_limit (mode 1) or torque_control_time_limit (mode 2) + 1 when the request starts or changes, 0 for modes 0 / 3; at 1 the sender goes into the ignored request list and the request ends. J1922 requests use it too.",
  "Through a2 = 0x80da7e (movea.l at 0x23248): clr.w (a2) at 0x23486 / 0x234ae; move.w d0,(a2) at 0x23496 / 0x234a8 (d0 = (6,a0) + 1 or (0xa,a0) + 1 with a0 = (0x80da76)); tst.w / subq.w #1 at 0x234dc-0x234e0; cmpi.w #1,(a2) at 0x23516 / 0x2354e; clr.w (0x80da7e) at 0x2320a.")
g("0x80da86", "high_idle_override_duration_timer", "high_idle_override_timeout_timer", "word",
  "CM848's j1939_powertrain_control_state.high_idle_override_timeout_timer: the high idle override's message timeout - (0x808182, e2m JCEGOSTM 'TIME OUT FOR JCOMM_HIGH_IDLE_OVERRIDE') + 1 on each ETC1 with SPN 606 = 01, or the recovery time 0x808188 + 1 while the recovery flag 0x80da98 is set; at 1 the override and the recovery end. It does not time the override's duration: that is 0x80da88.",
  "ETC1 handler 0x2efd0 through a4 = 0x80da86: move.w d0,(a4) at 0x2f05e (d0 = (0x808182) + 1) and 0x2f088 (d0 = (0x808188) + 1), clr.w (a4) at 0x2f076; J1922 handler move.w d3,(0x80da86) at 0x1f802 / clr.w at 0x1f810; runner tst.w 0x23290, subq.w 0x23298, cmpi.w #1 0x232a0, clr.w 0x232b6, move.w d0 at 0x232f2 (d0 = (0x808188) + 1).")
g("0x80da88", "high_idle_overspeed_timeout_timer", "high_idle_override_time_limit_timer", "word",
  "CM848's j1939_powertrain_control_state.high_idle_override_time_limit_timer: the high idle override's time limit - (0x808184, e2m JCEGOSTL 'TIME LIMIT FOR JCOMM_HIGH_IDLE_OVERRIDE') + 1 when the override flag rises; at 1 the override ends and the recovery flag 0x80da98 is set. The old name called the time limit a timeout.",
  "move.w d0,(0x80da88) at 0x23288 (d0 = (0x808184) + 1, on the flag's rise 0x23268-0x2327e); tst.w 0x232c4, subq.w 0x232cc, cmpi.w #1 0x232d2; clr.w at 0x232bc and at 0x2f078 (ETC1 handler).")
g("0x80da8c", "", "etc1_progressive_shift_disable_timer", "word",
  "CM848's j1939_powertrain_control_state.etc1_progressive_shift_disable_timer: (0x80818c, e2m JCPSTM 'TIME OUT FOR JCOMM_PROGRESSIVE_SHIFT_DISABLE') + 1 while ETC1 byte 5 bits 3-4 (SPN 607) = 01; at 1 the flag 0x80da58 is cleared. The message handler 0x1f84e loads it too (without the + 1).",
  "move.w d0,(0x80da8c) at 0x2f0a8 (d0 = (0x80818c) + 1) and clr.w at 0x2f0c4 (ETC1 handler 0x2efd0); move.w (0x80818c),(a3) / clr.w (a3) at 0x1f8a6 / 0x1f8b0 (a3 = 0x80da8c); runner tst.w 0x232f8, subq.w 0x23300, cmpi.w #1 0x23320, clr.w 0x23330.")
g("0x80da58", "engine_brake_override_flag", "etc1_spn607_progressive_shift_disable", "word",
  "CM848's j1939_powertrain_control_state.etc1_spn607_progressive_shift_disable. e2m 10E8 +C JCPSDB 'JCOMM PROGRESSIVE SHIFT DISABLE 1=TRUE, DISABLE PROG SHIFT': 1 while ETC1 byte 5 bits 3-4 (SPN 607) = 01; cleared by another value except 11 or when its timer 0x80da8c runs out. The message handler 0x1f84e sets it too (bit 7 of its first byte). Nothing in it concerns the engine brake (the old name).",
  "ETC1 handler 0x2efd0: data byte 4 & 0xc == 4 -> move.w #1,(0x80da58) at 0x2f098, else unless == 0xc clr.w at 0x2f0be; handler 0x1f84e through a4: move.w #1,(a4) at 0x1f8a2 / clr.w (a4) at 0x1f8ae; runner cmp.w at 0x2330c, cmpi.w #1 at 0x23314, clr.w at 0x2332a, move.w (0x80da58),(0x80198e) at 0x235de.")
g("0x80da98", "", "high_idle_override_recovery_flag", "word",
  "CM848's j1939_powertrain_control_state.high_idle_override_recovery_flag: 1 after the high idle override hit its time limit - while it is set every ETC1 reloads the timeout timer 0x80da86 with the recovery time (0x808188, e2m JCTMRCTM) + 1 and the override is not granted; cleared when that timer runs out.",
  "move.w #1,(0x80da98) at 0x232e2 (time limit timer 0x80da88 at 1); clr.w at 0x232b0 (timeout timer at 1); tst.w at 0x2f024 in the ETC1 handler (nonzero -> 0x2f080 reload with the recovery time).")
g("0x80da90", "", "retarder_tsc1_speed_control_flag", "word",
  "CM848's j1939_powertrain_control_state.retarder_tsc1_speed_control_flag, the same word by position and by the twins that clear it (endRetarderShiftAssistAboveFuelDemandLimit, resetEngineRetarderTsc1Request). As in CM848 the name is inferred (the retarder twin of the speed control status 0x80da60): every access writes 0 and nothing reads it.",
  "clr.w (0x80da90) at 0x21482, 0x2323c, 0x2fa30 and 0x2fa8a (the last two in cm550_retarderControlModeHandler); no read and no other write in the dumped ROM. The pairing with CM848 0x40ae32 is proven (the last store of both twins), the meaning of the word is not.", "low")
g("0x80da4e", "source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_da4e", "engine_control_device_indicator", "word",
  "CM848's engine_control_device_indicator. e2m 10E8 +2 JCEGCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the control device of the sender in control of the engine - processEngineTsc1Request stores the result of the lookup 0x142a8 (1 / 2 / 3 by three configured source addresses, else 4), the J1922 handlers store 1 or 2, a reset stores 0; the high idle override and the shift assist need 1.",
  "cmpi.w #1,(0x80da4e) at 0x2145a and 0x2f044; clr.w at 0x231ee; move.w d0,(0x80da4e) at 0x2f308 after jsr 0x142a8; move.w #1 / #2 at 0x1f64a.. / 0x1fa18..; read through a1 at 0x21fd6 / 0x21fea.")
g("0x80d9e6", "source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_d9e6", "engine_retarder_control_device_indicator", "word",
  "CM848's engine_retarder_control_device_indicator. e2m 10E6 +2 JCRDCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the control device of the sender in control of the retarder; resetEngineRetarderTsc1Request stores 0.",
  "cmpi.w #1,(0x80d9e6) at 0x21446; clr.w at 0x2321c / 0x2f964 / 0x2f9da / 0x2face; move.w d0,(0x80d9e6) at 0x2fa0c / 0x2fa4c; move.w (0x80d9e6) at 0x22022 / 0x2203c.")
g("0x80da60", "jcomm_speed_control_status_1_speed_control_mode_0_n_true_false", "tsc1_speed_control_flag", "word",
  "CM848's j1939_powertrain_control_state.tsc1_speed_control_flag. e2m 10E8 +14 JCRPGVSS 'JCOMM SPEED CONTROL STATUS 1 = SPEED CONTROL MODE 0 = N(OT)': 1 while the accepted engine request is speed control (mode 1), else 0; cm550_resetEngineTsc1Request clears it.",
  "clr.w (0x80da60) at 0x231f4 and at nine more sites in the request handlers; move.w #1,(0x80da60) at 0x2f30e (processEngineTsc1Request, mode 1) and 0x1f652 / 0x1fa20 (J1922 handlers).")
g("0x80d9e8", "retarder_command_source_address", "retarder_command_source_address", "word",
  "Type only (the row is typed undefined): the retarder request's source address as a word, the address in the low byte 0x80d9e9. The byte reads of 0x80d9e9 in the session functions and the runner render as DAT_0080d9e9 until the row is a word. CM848's engine_retarder_controlling_source_address (0x40ad5e, word) is the same record.",
  "move.w d0,(0x80d9e8) at 0x2f92c (d0 = a zero-extended byte); move.w (0x80d9e8),d0 at 0x221c8 / 0x2221e / 0x235fe / 0x2f89e; move.b (0x80d9e9) at 0x22034 / 0x222a4 / 0x23682 / 0x236b8.")
g("0x803d4a", "", "vehicle_speed_sensor_type_cal", "word",
  "CM848's vehicle_speed_sensor_type_cal. e2m 1180 +10 VSRSSNTY '0=NONE, 1=INDUCTIVE, 2=MINIGEN, 3=TACH, 4=DLW/GR&OOG, 5=DLW/O GR' (0-5): the vehicle speed sensor type; 4 / 5 (the vehicle speed from the data link, with / without gear ratio and out of gear) make cm550_runJ1939PowertrainControlTimeouts run the J1939 vehicle speed timers, and 4 alone the VSS lost fault. EEPROM 0x240, inside the mirror, so _cal. 0 in the dump.",
  "cmpi.w #4,(0x803d4a) at 0x233a8 and 0x233fe; cmpi.w #5 at 0x233b2; the same tests guard the same timers in CM848's runner (vehicle_speed_sensor_type_cal == 4 / == 5). parameter_id_table: 0x1180 + 0x10 = 0x803d4a.")

# ---- the periodic transmit queues ----
g("0x80096e", "", "j1939_periodic_queue0_entries", "j1939_periodic_transmit_entry_t[20]",
  "The engine node's periodic transmit queue (CM848's unnamed table 0x3fd2e2): 20 entries of 10 bytes - +0 word the PGN key, +2 word the interval in 10 ms ticks, +4 word the next tick, +6 the builder's address. The registrar 0x1fe84 appends them, cm550_runJ1939PeriodicTransmitQueues calls the due ones while bit 2 of the broadcast enable word is set. Dump: 17 entries (PGN 65265 every 10 ticks by 0x31c84, 61444 every 2 by 0x32c76, 61443, 65247, 65251, 65266, 65262, 65252, 65263, 65264, 65269, 65270, 65271, 65226, 65213, 61441, 65279).",
  "0x1ff62 movea.l #0x80096e,a2; (4,a2) word compare and add at 0x1ff6c / 0x1ff78, (2,a2) word at 0x1ff74, (6,a2) long at 0x1ff7c, step 10 at 0x1ff82. Registrar: 0x1fec2 base + 10 x count; 0x1ff04 move.w -> (a2); 0x1ff16 move.w -> (4,a2); 0x1ff26 move.w -> (2,a2); 0x1ff2a move.l -> (6,a2). No other reference; the 200 bytes end at 0x800a36.")
g("0x800a36", "", "j1939_periodic_queue1_entries", "j1939_periodic_transmit_entry_t[10]",
  "The retarder node's periodic transmit queue (CM848's unnamed table 0x3fd3aa): 10 entries of the same 10-byte layout, run while bit 3 of the broadcast enable word is set. Dump: 2 entries (PGN 61440 every 10 ticks by 0x338ea, PGN 65249 every 500 by 0x3407a).",
  "0x1ff9a movea.l #0x800a36,a2 with the same accesses (0x1ffa4-0x1ffbc); registrar 0x1fef4 base + 10 x count. The 100 bytes end at the count byte 0x800a9a.")
g("0x800a9a", "", "j1939_periodic_queue0_count", "byte",
  "CM848's j1939_periodic_queue0_count (0x3fd40e): the number of entries in queue 0 (at most 20). 0x11 in the dump.",
  "cmp.b (0x800a9a),d2 at 0x1ff88; registrar through a3 = 0x800a9a: cmpi.b #0x14,(a3) at 0x1fea2, move.b (a3),d0 / addq.b #1,(a3) at 0x1feb0.")
g("0x800a9b", "", "j1939_periodic_queue1_count", "byte",
  "CM848's j1939_periodic_queue1_count (0x3fd40f): the number of entries in queue 1 (at most 10). 2 in the dump.",
  "cmp.b (0x800a9b),d2 at 0x1ffc0; registrar through a1 = 0x800a9b: cmpi.b #0xa,(a1) at 0x1fed4, addq.b #1,(a1) at 0x1fee4.")
g("0x800a9c", "", "j1939_periodic_queue0_current_tick", "word",
  "CM848's j1939_periodic_queue0_current_tick (0x3fd410): queue 0's tick, + 1 per pass while the queue runs (10 ms); an entry is due when its next tick equals it.",
  "Through a4 = 0x800a9c: cmp.w (a4),d0 at 0x1ff70, addq.w #1,(a4) at 0x1ff90; move.w (0x800a9c),d2 at 0x1fecc (the registrar adds it to the first offset).")
g("0x800a9e", "", "j1939_periodic_queue1_current_tick", "word",
  "CM848's j1939_periodic_queue1_current_tick (0x3fd412): queue 1's tick.",
  "Through a3 = 0x800a9e: cmp.w (a3),d0 at 0x1ffa8, addq.w #1,(a3) at 0x1ffc8; move.w (0x800a9e),d2 at 0x1fefe.")
g("0x80aa12", "bit_2_0_15_enables_j1939_71_engine_broadcast_1_on_0_off", "datalink_broadcast_enable_flags", "word",
  "CM848's datalink_broadcast_enable_flags. e2m 102E +0 JCBCFGLC 'BIT-MAPPED PARAMETER INDICATES PROTOCOLS/PORTS BROADCAST ENAB(LED)': bit 0 J1587 (JC87EN) / 1 J1922 (JC22EN) / 2 J1939-71 engine broadcast (JCEGBCEA, periodic queue 0) / 3 J1939-71 retarder broadcast (JCRDBCEA, queue 1). Loaded from 0x803f88 at start; the broadcast enable / disable services change it. 0x000d in the dump.",
  "Through a5 = 0x80aa12 in 0x1ff38: andi.w #4 at 0x1ff5c, andi.w #8 at 0x1ff94; move.w (0x803f88),(0x80aa12) at 0x2919c; clr.w at 0x161ca; ori.w #1 / #2 at 0x16208 / 0x1621e; base load at 0x1ffde (service 4 / 5 worker).")

# ---- the receive dispatcher's blocking table ----
g("0x80d9e0", "", "j1939_source_address_blocking_table", "byte[4]",
  "e2m 10E4 JCSABLTB 'JCOMM SOURCE ADDRESS BLOCKING TABLE TABLE THAT HAS SOURCE ADDR(ESSES TO BE BLOCKED)': four source addresses, 0xFE = unused and the end of the list; mc68k_dispatchJ1939ReceivedMessages drops a received frame whose source address is listed. mc68k_initializeJ1939Datalink fills it with 0xFE. Dump: fe fe fe fe. CM848's twin is 0x40ad56 (see its row).",
  "0x21344 movea.l #0x80d9e0,a2; cmp.b (a2)+,d3 at 0x2135a; cmpi.b #0xfe,(a2) at 0x21362; bound a5 = 0x80d9e4 (cmpa.l a5,a2 at 0x21368). Initializer: movea.l #0x80d9e0 at 0x28bca, four move.b #0xfe. e2m 10E4 resolves to 0x80d9de, the table's length word.")
g("0x80d9de", "", "j1939_source_address_blocking_table_byte_length", "word",
  "The byte length (4) in front of the blocking table: e2m 10E4 JCSABLTB resolves here (a table record starts with its length word). mc68k_initializeJ1939Datalink writes 4; no code reads it. Dump 0x0004.",
  "move.w #4,(0x80d9de) at 0x28bc0 (operand at 0x28bc4); the only code reference. parameter_id_table 0x10E4 = 0x80d9de.", "medium")
g("0x40ad56", "j1939_receive_source_address_whitelist", "j1939_source_address_blocking_table", "byte[4]",
  "It is a blocking table, not a whitelist: cm848_dispatchJ1939ReceivedMessages skips the handler when the received source address is listed (0xFE ends the list). e2m 10E4 Jcomm_Source_Address_Blocking_Table '[JCSABLTB] ... table that has source addresses to be block(ed)' resolves to 0x40ad54, the length word in front of these four bytes. The twin of CM550's table 0x80d9e0.",
  "CM848 0x539024-0x53905c: r4 walks 0x40ad56 (lbz, 254 ends, 4 bytes); a match sets r30 = 1; 0x539060 cmpwi r30,0 / bne 0x5390bc jumps over the handler table scan 0x539068-0x5390b8. e2m_block_addresses.py 10E4 -> 0x40ad54.", "high", "CM848")

# ---- the ignored request lists ----
g("0x801994", "", "engine_tsc1_ignored_request_entries", "engine_tsc1_ignored_request_t[5]",
  "CM848's engine_tsc1_ignored_request_entries (0x3fb916; 10 entries there): the engine ignored request list - 5 entries of 8 bytes: +0 word the network type (0 J1922 / 1 J1939), +2 byte the source address, +4 word the control mode, +6 word the countdown (the recovery time 0x808188). Added by cm550_addEngineTsc1IgnoredRequestEntry; searched / refreshed by 0x23820, counted down by 0x23920, pruned by 0x239d2. Replaces the rows inside it, which only name base + index accesses: 0x801998 diagnostic_service_state_counter, 0x80199a diagnostic_security_access_mode, 0x8019a2, 0x8019a6, 0x8019aa-0x8019ad, 0x8019b2, 0x8019b4, 0x8019b6 and 0x8019b8 diag_service_pgn_dispatch_ptr (no absolute reference to any of them but 0x8019b8, which 0x2398e loads as the retarder list base - 4).",
  "0x23830 movea.l #0x801994: cmp.w (a0), cmp.b (2,a0), cmp.w (4,a0), move.w -> (6,a0), step 8; 0x238c6 base + 8 x count: move.w -> (a2), move.b -> (2,a2), move.w -> (4,a2), move.w -> (6,a2); 0x23920: subq.w #1,(6,a2) and the copy (a3) -> (a2) of word 0, byte 2, word 4, word 6 (0x23968-0x23976); 0x239e4: cmp.w (a2), cmp.b (2,a2) and the same copy. Byte 3 is never accessed.")
g("0x8019bc", "", "retarder_tsc1_ignored_request_entries", "retarder_tsc1_ignored_request_t[5]",
  "CM848's retarder_tsc1_ignored_request_entries (0x3fb966; 6-byte entries with a mode word there): the retarder ignored request list - 5 entries of 4 bytes: +0 byte the source address, +2 word the countdown. Added by cm550_addRetarderTsc1IgnoredRequestEntry; refreshed by 0x23870, counted down by 0x23920, pruned by 0x23a3c.",
  "0x23878 movea.l #0x8019bc: cmp.b (a0), move.w -> (2,a0), step 4; 0x23906 base + 4 x count: move.b -> (a2), move.w -> (2,a2); 0x23920: subq.w #1,(2,a2), move.b (a3),(a2), move.w (2,a3),(2,a2) (0x2399c-0x239be; 0x8019b8 at 0x2398e is the base - 4); 0x23a4a: cmp.b (a2). Byte 1 is never accessed; the 20 bytes end at the count byte 0x8019d0.")
g("0x8019d0", "io_control_entry_count", "engine_tsc1_ignored_request_count", "byte",
  "CM848's engine_tsc1_ignored_request_count: the number of entries in the engine ignored request list (at most 5). Nothing here is I/O control.",
  "cmpi.b #5,(a1) / move.b (a1),d0 / addq.b #1,(a1) at 0x238b4-0x238bc (a1 = 0x8019d0); move.b (0x8019d0),d3 at 0x23838; tst.b / subq.b #1 through a1 in 0x23920 and through a4 in 0x239d2.")
g("0x8019d1", "io_control_timeout_entry_count", "retarder_tsc1_ignored_request_count", "byte",
  "CM848's retarder_tsc1_ignored_request_count: the number of entries in the retarder ignored request list (at most 5).",
  "cmpi.b #5,(a1) / addq.b #1,(a1) at 0x238f4-0x238fc (a1 = 0x8019d1); move.b (0x8019d1),d3 at 0x23880; through a4 in 0x23920 (0x23984-0x239ac) and 0x23a3c.")

# ---- the settings the family reads ----
g("0x8089a8", "limit_to_which_user_fueling_is_compared_to_determine_if_engine_0_100", "engine_retarder_shift_assist_fuel_demand_limit", "word",
  "CM848's engine_retarder_shift_assist_fuel_demand_limit (ROM 0x5c36c). e2m 10FC +2 JCEBSILM 'LIMIT TO WHICH USER FUELING IS COMPARED TO DETERMINE IF ENGINE (brakes should be ...)' (MM3S): endRetarderShiftAssistAboveFuelDemandLimit and the retarder request handler end the retarder request when fuel_demand_selected is at or above it. 0x000f in the dump.",
  "cmp.w (0x8089a8),d0 at 0x2146a and 0x2f9c6, each after move.w (0x80ded2),d0.")
g("0x808188", "jcomm_recovery_time_time_that_time_limited_node_must_be_silen_0_1000", "j1939_time_limited_node_recovery_time", "word",
  "CM848's j1939_time_limited_node_recovery_time (ROM 0x5c38c). e2m 10E7 +A JCTMRCTM 'JCOMM RECOVERY TIME TIME THAT TIME LIMITED NODE MUST BE SILEN(T)' (MSEC, 10 ms counts): the countdown of every ignored request list entry and (+ 1) the high idle override's recovery timeout. 5 = 50 ms in the dump.",
  "move.w (0x808188) -> (6,a2) at 0x238e0 and (6,a0) at 0x23850; -> (2,a2) at 0x23914 and (2,a0) at 0x2388c; -> d0 then + 1 at 0x232ea and 0x2f080.")
g("0x808184", "jcomm_engine_overspeed_tl_time_limit_for_jcomm_high_idle_ove_0_25000", "j1939_pgn61442_engine_overspeed_enable_time_limit", "word",
  "CM848's j1939_pgn61442_engine_overspeed_enable_time_limit (ROM 0x5c388). e2m 10E7 +6 JCEGOSTL 'JCOMM ENGINE OVERSPEED TL TIME LIMIT FOR JCOMM_HIGH_IDLE_OVE(RRIDE)' (MSEC, 10 ms counts): the runner loads it + 1 into the override's time limit timer 0x80da88 when the override starts. 0 in the dump.",
  "move.w (0x808184),d0 / addq.w #1 / move.w d0,(0x80da88) at 0x23280-0x23288; one more word read at 0x33332.")
g("0x8081fc", "number_of_timeouts_allowed_before_setting_j1xxx_link_not_fast_0_1000", "j1939_link_fault_timeout_count_limit", "word",
  "CM848's j1939_link_fault_timeout_count_limit (ROM 0x5c39c). e2m 10E7 +7E JCTMERLM 'NUMBER OF TIMEOUTS ALLOWED BEFORE SETTING J1XXX_LINK_NOT_FAST(_ENOUGH_ERROR)': the runner sets the J1708 link timeout fault when the count 0x804266 reaches it - 1 and the J1939 fault when the count 0x804268 reaches it. 100 in the dump.",
  "move.w (0x8081fc),d1 / subq.l #1 at 0x236d4-0x236da; cmp.w (0x8081fc),d0 at 0x23788.")

# ---- enum members: the six write services that 0x21872 registers ----
def em(value, current, proposed, comment, evidence):
    enum_members.append(dict(firmware="CM550", enum_name="J1939_DIAGNOSTIC_SERVICE", value=value, current_member=current,
                             proposed_member=proposed, comment=comment, evidence=evidence, confidence="high"))


em(0x44, "SERVICE_44", "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID",
   "Service 0x44 (CM848's member name): handleJ1939WriteByParameterIdService (0x2167e) - the ID (2 bytes) and a length (1) then the data (was SERVICE_44; PR #53 round 93)",
   "0x2187a pea (0x2167e) / 0x21880 move.w #0x44 / jsr registerJ1939DiagnosticService; 0x2167e is the twin of CM848 0x50b228.")
em(0x45, "SERVICE_45", "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_LENGTH",
   "Service 0x45 (CM848's member name): handleJ1939WriteByParameterIdLongLengthService (0x216c6) - the ID (2 bytes) and a length (4) then the data (was SERVICE_45; PR #53 round 93)",
   "0x21886 pea (0x216c6) / 0x2188c move.w #0x45; 0x216c6 is the twin of CM848 0x50b298.")
em(0x47, "SERVICE_47", "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_SHORT_OFFSET",
   "Service 0x47 (CM848's member name): handleJ1939WriteByParameterIdShortOffsetService (0x21714) - the ID (2 bytes) / an offset (2) / a length (1) then the data (was SERVICE_47; PR #53 round 93)",
   "0x218aa pea (0x21714) / 0x218b0 move.w #0x47; 0x21714 is the twin of CM848 0x50b300.")
em(0x49, "SERVICE_49", "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID_LONG_OFFSET",
   "Service 0x49 (CM848's member name): handleJ1939WriteByParameterIdLongOffsetService (0x21778) - the ID (2 bytes) / an offset (4) / a length (4) then the data (was SERVICE_49; PR #53 round 93)",
   "0x218b6 pea (0x21778) / 0x218bc move.w #0x49; 0x21778 is the twin of CM848 0x50b38c.")
em(0x4B, "SERVICE_4B", "J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY",
   "Service 0x4b (CM848's member name): handleJ1939WriteMemoryService (0x217de) - an address (4 bytes) and a length (1) then the data (was SERVICE_4B; PR #53 round 93)",
   "0x21892 pea (0x217de) / 0x21898 move.w #0x4b; 0x217de shares its name with CM848 0x50b408 since round 72.")
em(0x4D, "SERVICE_4D", "J1939_DIAGNOSTIC_SERVICE_WRITE_MEMORY_LONG_LENGTH",
   "Service 0x4d (CM848's member name): handleJ1939WriteMemoryLongLengthService (0x21826) - an address (4 bytes) and a length (4) then the data (was SERVICE_4D; PR #53 round 93)",
   "0x2189e pea (0x21826) / 0x218a4 move.w #0x4d; 0x21826 shares its name with CM848 0x50b474 since round 72.")
