import json
draft = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S2/draft.json'))
V = []


def add(element, verdict, reason, amendment=None):
    v = {'element': element, 'verdict': verdict, 'reason': reason}
    if amendment:
        v['amendment'] = amendment
    V.append(v)


SWITCH = ("the debounced user datalogger switch (bit 6 = mask 0x40 of the byte at 0x80bcd0; e2m 000E +2 DSILSSSW "
          "'STATUS OF THE DEBOUNCED SWITCH USER_DATALOGGER_SWITCH'; the row there is still named "
          "debounced_value_for_rear_axle_ratio_switch_on_off)")

# ---------------- structs
add('struct datalogger_trigger_t', 'CONFIRMED',
    'Re-derived from the ROM bytes (proposer listing checked byte-for-byte against J90350.00.rom.bin: 1217 lines, 0 mismatches; key '
    'extension words hand-decoded). Stride 16: lsl.l #4 at 0x13ef6, moveq #16 / add.l at 0x13986 / 0x13d10 / 0x13dfe / 0x13ec4. Count 4: '
    'cmpi.b #4 at 0x13e06 / 0x13ecc, cmpi.w #4 at 0x13d1a, the 0-2 loop (cmpi.b #2 / bls at 0x1398e) plus trigger 4 (tst.b $803d95, '
    'move.w #3,-(sp)). Fields: +0 byte (move.b (0,a0,d0.w*8) at 0x13f30 with d0 = 2 x index, then cmp 1 / 2 / 4, anything else = dword); '
    '+1 byte (tst.b (0,a0,d3.w) a0 = 0x803d65); +2 word (tst.w 0x13dd2 / 0x13f00, cmpi.w #1 0x13cf4 / 0x13e78); +4 word (tst.w 0x13f0e / '
    '0x1419c: nonzero = value > threshold strict, or fault status 0/2 -> 1/3); +6 word (move.w 0x13de0 / cmp.w (a2) 0x13ea0); +8 word '
    'zero-extended (andi.l #0xffff 0x13df6); +0xA dword (move.l, low byte / low word / dword compares; andi.l #0xff also in signed mode); '
    '+0xE word (tst.w 0x13f1c / 0x1405c). e2m 1282 has exactly 32 records at +0x10 x (n-1) + 0/1/2/4/6/8/A/E with lengths 1/1/2/2/2/2/4/2; '
    'ROM region 0x1F5 = {0x0100025a, 64}; RAM 0x803d64-0x803dc9 equals EEPROM 0x25a-0x2bf byte for byte; dump = len 2, disabled, mode 1 '
    'on 0x100c+2 / 0x1004+0x76 / 0x1051 / 0x1047. No other reader: all 40 absolute operands in 0x803d60-0x803dcb sit in 0x13922-0x14186. '
    'Optional naming note (not required): CM848 monitor_calibrated_condition_t calls the same concept parameter_byte_offset.')
add('struct datalogger_data_parameter_t', 'CONFIRMED',
    'Stride 6: addq.l #6,d4 at 0x13ad0, addq.l #6,d2 at 0x13e48, d4 = 6 x i at 0x13b5c-0x13b64. +0 word (move.w (0,a0,d4.w) at 0x13abe / '
    '0x13bb2 / 0x13b9e, andi.l #0xffff; the set-up adds only its low byte: add.b d0,d2 / cmpi.b #10 / bhi), +2 word (move.w ...,-(sp) at '
    '0x13e2a before jsr 0x10e16), +4 word zero-extended (0x13e3c / andi.l #0xffff / add.l d0,(a2)). Count 5 is not a code bound (loops '
    'run to UDPRCU 0x803dc8) but is pinned by: e2m 1283 = UD01-UD05 (15 records, +6 x (n-1) + 0/2/4, all 2 bytes); region 0x1F6 = '
    '{0x0100029a, 30}; UDADSZ dump 94 = 64 + 30; the address dwords 0x800508 + 5 x 4 = 0x80051c, the next variable. The task text said '
    'block 1282; the e2m file puts every UD0nDX record in 1283, so the proposal is right. Dump: len 2 x 5, ids 0x100c / 0x1004 / 0x1051 / '
    '0x1047 / 0x1004, offsets 2 / 0x76 / 0 / 0 / 0x8c.')
add('struct datalogger_trigger_information_t', 'CONFIRMED',
    '8 bytes, built at 0x13b06-0x13b2c: move.w d0w,$800522 (write pointer - 0x800374), move.l $80bda4 (key_on_hour_meter),$800524, '
    'move.b $80bac7,$800528, move.b $80bac9,$800529; copied field by field to 0x8052ea / 0x8052ec / 0x8052f0 / 0x8052f1 (event 1, '
    '0x13c16-0x13c34) and 0x8052f2 / 0x8052f4 / 0x8052f8 / 0x8052f9 (event 2, 0x13c52-0x13c70) = stride 8. e2m 1287 UDTRMK is 16 '
    'bytes and region 0x1F9 = {0x4354, 16}. ApplyStructures builds non-packed structs (offset += size), so the dword at +2 lands at +2. '
    'Dump: {0x0050, 0x000003d3, 1, 0} / {0x00aa, 0x0d8d364a, 1, 0}.')

# ---------------- globals
G = {
    '0x00803d64': ('CONFIRMED',
                   'No row at 0x803d64 now; 0x803d64 + 64 = 0x803da4 (the data array), no other row in 0x803d64-0x803da3 besides the four '
                   'removed scalars. EEPROM mirror (0x803b0a-0x804155), so _cal is right. Every claim in the comment checked: the 40-operand '
                   'scan (all in 0x13922-0x14186; 0x14292 has none), parameter ID table entry for 1282 at ROM 0x367ac / 0x367b0 = 0x0100025a, '
                   'region 0x1F5 = {0x0100025a, 64}, dump values. Only generic users remain (mirror base / parameter ID services).'),
    '0x00803da4': ('CONFIRMED',
                   'Existing row datalogger_data_1_length_cal (word) at the array base: rename + retype in place is right (keep it, do not '
                   'delete). 0x803da4 + 30 = 0x803dc2 (UDADSZ); only 0x803da6 sits inside and it is removed. Users 0x13a5c (0x13aba / '
                   '0x13b9a / 0x13bae) and 0x13e12 (0x803da6 / 0x803da8 at 0x13e26 / 0x13e38). EEPROM mirror -> _cal. Block 1283 confirmed.'),
    '0x00803dc4': ('CONFIRMED',
                   'Word: cmpi.w #3 / move.w #2 / move.w $803dc4,d0w at 0x13d52 / 0x13d5c / 0x13d64; only users are the 3 operands in 0x13d42. '
                   'Jump table at 0x13d7a decoded: 0..5 -> 5/10/20/40/80/160, else 5 (cmp.l #5 / bhi after ext.l). e2m 1284 +2 UDSART 2 bytes, '
                   'dump 1, EEPROM 0x2ba. Nit: the rewrite uses signed blt, so only codes 3..0x7fff become 2.'),
    '0x00803dc6': ('AMENDED',
                   'Word, users 0x1391e / 0x1394a (0x138b6) and 0x13d48 (0x13d42), all cmpi.w #1; e2m 1284 +4 UDTRMD, dump 1. Layout and name '
                   'confirmed; the comment should name the manual trigger input: e2m 000E +2 DSILSSSW (mask 0x40) resolves to 0x80bcd0 and is '
                   "'STATUS OF THE DEBOUNCED SWITCH USER_DATALOGGER_SWITCH'.",
                   'Keep name/type; in the comment replace "any other value = manual, a rising edge of bit 6 of the byte at 0x80bcd0 triggers" '
                   'with "any other value = manual: a rising edge of ' + SWITCH + ' triggers".'),
    '0x00803dc8': ('CONFIRMED',
                   'Word: move.w $803dc8,d1w at 0x13ada (set-up count loop) and 0x13e54 (resolver bound), cmp.l / blt; only these 2 operands. '
                   'e2m 1284 +6 UDPRCU 0-5, dump 5, EEPROM 0x2be. Note no code caps it at 5 (6+ would overrun 0x800508 into 0x80051c).'),
    '0x0080bac4': ('CONFIRMED',
                   'a4 = 0x80bac4 in 0x13a5c (cmpi.w #1,(a4) / tst.w (a4) / move.w #1,(a4) at 0x13b02 / clr.w (a4) at 0x13c8c) and tst.w '
                   '$80bac4 at 0x1390a / 0x13940; plus the parameter ID table (0x367c4 / 0x367c8). e2m 1285 +0 UDSS. Word. Old name '
                   'snapshot_capture_active_flag has users only in these two functions.'),
    '0x0080bac6': ('CONFIRMED',
                   'move.w #1,$80bac6 at 0x139ca (triggers 1-3 all satisfied), clr.w at 0x13a28 / 0x13a38 / 0x13a48, byte read of 0x80bac7 at '
                   '0x13b22. e2m 1285 +2 UDADTR 2 bytes. Word. No row now.'),
    '0x0080bac8': ('CONFIRMED',
                   'a5 = 0x80bac8 (0x138c6): move.w #1,(a5) at 0x139d8 / 0x139ec, clr.w (a5) at 0x13a2e / 0x13a3e / 0x13a4e; byte read 0x80bac9 '
                   'at 0x13b2c. e2m 1285 +4 UDORTR. Word.'),
    '0x0080baca': ('CONFIRMED',
                   'a4 = 0x80baca in 0x138b6: move.w #1,(a4) at 0x139c6 / 0x139e8 / 0x13a08, clr.w (a4) at 0x13a26 / 0x13a36 / 0x13a46; '
                   'cmpi.w #1,$80baca at 0x13a7e and tst.w $80baca at 0x13afa in 0x13a5c. e2m 1285 +6 UDTRSE. Word. (The comment could also '
                   'mention the 0x13a7e test that keeps the sample task running while the datalogger is disabled.)'),
    '0x00800352': ('CONFIRMED',
                   'Byte: tst.b at 0x13902 / 0x13a90, move.b #1 at 0x13a9c, clr.b at 0x13a50; 4 operands, all in 0x138b6 / 0x13a5c. Dump 1. '
                   'Not overlapping 0x800350 (a data collector word, move.w only).'),
    '0x00800353': ('CONFIRMED',
                   'Byte: move.b $800353,d1b at 0x138dc, move.b d0b,$800353 at 0x13918, movea.l #0x800353,a0 / move.b #imm,(a0) / move.b (a0),d0b '
                   'in 0x13d42. Dump 10 (UDSART 1 -> 10). Users only 0x138b6 / 0x13d42.'),
    '0x00800354': ('CONFIRMED',
                   'Byte: move.b #1 at 0x138e6; tst.b at 0x13956 / 0x13aea; clr.b at 0x13af4 / 0x13cd8 / 0x13dae. Users 0x138b6 / 0x13a5c / '
                   '0x13cc8 / 0x13d42 only. Old name scheduler_phase_execution_time is wrong (CM550 phase index is scheduler_phase_index 0x80068c).'),
    '0x00800356': ('CONFIRMED',
                   '4 dwords: a2 = 0x800356 / addq.l #4,a2 / 4 iterations in 0x13dbe (the lookup writes the address, add.l d0,(a2) adds the '
                   'offset); movea.l (0,a2,d0.l*4),a0 in 0x13ed8. Dump 0x80ccf4 / 0x80a320 / 0x80d32e / 0x80aa82 = table(0x100c)+2 / '
                   'table(0x1004)+0x76 / table(0x1051) / table(0x1047). Ends at 0x800365; 0x800366 is the next array. The 5 junk rows inside '
                   'have no user.'),
    '0x00800366': ('CONFIRMED',
                   'Byte[4]: a2 = 0x800366 (+1 per trigger) in 0x13cc8, a3 = 0x800366 + n / move.b d2b,(a3) at 0x13ea4 in 0x13e64, '
                   'a1 = 0x800366 / move.b (0,a1,d0.l) in 0x13ed8. Values index the 125 x 6 definitions at 0x8067c4 and the 10-byte fault count '
                   'records (status at 0x805a24 + 10 x i). Dump 0.'),
    '0x0080036a': ('CONFIRMED',
                   'a3 = 0x80036a (0x138ba), a2 = a3 +1 per trigger: move.b #1,(a2) / move.b d0b,(a2), clr.b (3,a3) / move.b d0b,(3,a3), tst.b '
                   '$80036a / (1,a3) / (2,a3) / (3,a3). Byte[4]; replaces the rendered DAT_0080036b/c/d too. Users 0x138b6 only.'),
    '0x0080036e': ('CONFIRMED',
                   'Byte[4]: a3 = 0x80036e in 0x13cc8 and 0x13ed8 (cmpi.b / tst.b (0,a3,d0.l), move.b d0b,(0,a3,d1.l) at 0x14286), a1 = 0x80036e '
                   '+1 per trigger in 0x13e64. Status semantics checked in cm550_FUN_00014872 (3 active / 2 inactive), '
                   'cm550_diagnosticCodeRegistrar (3 -> 1, 2 -> 0 when a snapshot slot is reused), cm550_diagnosticTableEntryClear (0).'),
    '0x00800372': ('CONFIRMED',
                   'Byte: move.b #1 at 0x13cb6 / 0x13d34, tst.b at 0x13c96, clr.b at 0x13be6 (after every sample). No row now. Users '
                   '0x13a5c / 0x13cc8 only.'),
    '0x00800374': ('CONFIRMED',
                   'Byte[400] = 0x800374-0x800503: clr.b (a2)+ / cmpi.w #0x190 loops at 0x13ca6 and 0x13d24, write pointer reset to 0x800374 '
                   'when it reaches 0x800504 (cmpa.l (a5),a3 at 0x13b78), 0x14292 copies 0x190 bytes from it. Dump: 40 identical 10-byte '
                   'samples (00 00 00 00 00 00 00 00 7f 80), write pointer 0x80041e. All 51 rows inside are undefined, uncommented, with no '
                   '.cpp user and no ROM operand.'),
    '0x00800504': ('CONFIRMED',
                   'Long pointer: a5 = 0x800504 in 0x13a5c (move.l #0x800374,(a5) / movea.l (a5),a0 / move.b d0b,(a0) / addq.l #1,(a5) / cmpa.l '
                   '(a5),a3), move.l $800504,d0 at 0x13b06, move.l a1,$800504 at 0x13d2e. byte * is an existing CSV type. Dump 0x80041e.'),
    '0x00800508': ('CONFIRMED',
                   'Dword[5]: a2 = 0x800508 / addq.l #4,a2 in 0x13e12; movea.l #0x800508,a0 / adda.w (4 x i) / add.l (a2),d0 in 0x13a5c. Dump '
                   '0x80ccf4 / 0x80a320 / 0x80d32e / 0x80aa82 / 0x80a336. Ends at 0x80051b, before 0x80051c. No row now.'),
    '0x0080051c': ('CONFIRMED',
                   'Byte: clr.b at 0x13b36, addq.b #1 at 0x13b88, cmpi.b #0xc8 (200) at 0x13b8e / 0x13bca. Users 0x13a5c only. Dump 0.'),
    '0x0080051e': ('CONFIRMED',
                   'Word: addq.w #1 at 0x138cc, move.w at 0x138d4 (cmp.l with the period, blt), clr.w at 0x138ee / 0x13cd2 / 0x13db4. Dump 3.'),
    '0x00800520': ('AMENDED',
                   'Byte: tst.b at 0x13a00, move.b #1 at 0x13a0c (with move.w #1,(a4) = trigger detected), clr.b at 0x13a1a; users 0x138b6 '
                   'only. Name confirmed; the comment should say which switch: btst #6,$80bcd0 tests DSILSSSW (e2m 000E +2, mask 0x40, '
                   "'STATUS OF THE DEBOUNCED SWITCH USER_DATALOGGER_SWITCH').",
                   'Keep name/type; in the comment replace "when bit 6 of 0x80bcd0 is set" / "when the bit is clear" with "when ' + SWITCH +
                   ' is on" / "when it is off".'),
    '0x00800521': ('CONFIRMED',
                   'Byte: clr.b at 0x13aac, addq.b #1 at 0x13aca (after add.b d0,d2 / cmpi.b #10 / bhi), move.b at 0x13bd4, cmp.b at 0x13bdc '
                   '(sample loop bound). Dump 5. Users 0x13a5c only.'),
    '0x00800522': ('CONFIRMED',
                   '0x800522-0x800529 accessed only as the word / dword / byte / byte of datalogger_trigger_information_t (0x13b12-0x13b2c and '
                   'the copies at 0x13c16-0x13c70); no rows in that span; 0x80052a is the next variable. Users 0x13a5c only.'),
    '0x0080052a': ('CONFIRMED',
                   'Byte: move.b #1 at 0x13ba2, tst.b at 0x13bf4, clr.b at 0x13c8e. Users 0x13a5c only; 0x80052c (next operand) belongs to '
                   'other code (0x1430a / 0x143d8).'),
    '0x00804fca': ('CONFIRMED',
                   'Byte[800] = 0x804fca-0x8052e9: movea.l #0x804fca / #0x80515a (= +400) at 0x13c0c / 0x13c48 as the 0x14292 destination; '
                   'e2m 1286 UDDXTB 800 bytes; region 0x1F8 = {0x4034, 800}. The other ROM 4-byte matches inside (0x80522b / 0x80522d / '
                   '0x80528a at 0x1e902 / 0xec4c / 0xecce / 0x27824 / 0x37de / 0x2c9d2) are instruction-pair artefacts (10bc 0080 + 522d 0003 '
                   'etc.), not operands. Optional comment addition, like the round-88 engine_overspeed_log row: no _cal because it lies in the '
                   'flash parameter block RAM 0x804f9a-0x806547 that cm550_flashProgramFromRam(0x4004 / 0x6004, 0x804f9a, 0x15ae) saves '
                   '(0x4034 - 0x4004 = 0x804fca - 0x804f9a = 0x30).'),
    '0x008052ea': ('CONFIRMED',
                   'Two 8-byte records 0x8052ea-0x8052f9 (event 1 / event 2 copies at 0x13c16-0x13c34 / 0x13c52-0x13c70); e2m 1287 UDTRMK 16 '
                   'bytes, region 0x1F9 = {0x4354, 16} (flash parameter block +0x350). No rows in the span. Dump {0x50, 0x3d3, 1, 0} / '
                   '{0xaa, 0x0d8d364a, 1, 0}.'),
    '0x008052fa': ('CONFIRMED',
                   'Word: tst.w $8052fa at 0x13c04, move.w #1 at 0x13c3e; e2m 1288 +0 UDEV01; dump 1. Flash parameter block, so no _cal.'),
    '0x008052fc': ('CONFIRMED',
                   'Word: move.w #1,$8052fc at 0x13c7a only; e2m 1288 +2 UDEV02; dump 1. 0x8052fe (DCSDEN) is a different variable.'),
}
for g in draft['globals']:
    entry = G[g['address']]
    add('global ' + g['address'], entry[0], entry[1], entry[2] if len(entry) > 2 else None)

# ---------------- functions
F = {
    '0x000138b6': ('AMENDED',
                   'Only caller jsr at 0x1b6dc in cm550_FUN_0001b6d6 (jsr 0x1fd6c cm550_j1939TimeoutDataClearHandler; jsr 0x138b6; rts), which '
                   'the executive calls as a statement in phases 2 / 12 / 22 / 32. Every step of the plate checked against 0x138b6-0x13a5a '
                   '(counter / due flag, enable bit 0x20 of 0x803cb8 = e2m 106B +0x26 UDEN bit 5, set-up calls, cmpi.w #1,$80d0c8 = '
                   'ENGINE_STATE_STOPPED, the 0-2 loop + trigger 4, AND / OR flags). CM848 has no datalogger (0 UD / DATALOGGER records in '
                   'CHR_CC_11.45.01.07.e2m; its 6 cm848_lookupParameterIdAddress calls are in cm848_processPciDiagnosticRequest x2, '
                   'cm848_evaluateCalibratedMonitorDisableConditions and the 3 J1939 parameter-ID services), so standalone cm550_ is right. '
                   'Only the manual-trigger sentence should name the switch.',
                   'Keep name/relation; in the plate replace "a rising edge of bit 6 of the byte at 0x80bcd0 (latch 0x800520)" with "a rising '
                   'edge of ' + SWITCH + ' (latch 0x800520)".'),
    '0x00013a5c': ('AMENDED',
                   'Only caller jsr at 0x1b6ea in cm550_FUN_0001b6e4 (after vp44_hourMeterEventLogger 0x27998). Plate checked against '
                   '0x13a5c-0x13cc6: disabled path zeroes the ring once, set-up, sample-due pass, event start, ring copy with wrap, 200-byte '
                   'end, event save to 0x8052ea / 0x804fca or 0x8052f2 / 0x80515a, copy (source pushed last = (4,sp)). One wording fix: only '
                   'the flag of the event written is set, not both.',
                   'Keep name; in the plate replace "UDEV01 / UDEV02 (0x8052fc) are set and logging stops" with "the flag of the event written '
                   'is set (UDEV01 0x8052fa for event 1, UDEV02 0x8052fc for event 2) and logging stops".'),
    '0x00013cc8': ('CONFIRMED',
                   'Only caller jsr at 0x28792 in mc68k_applicationMain, right after cm550_initLoadTrendingSystem (which is unrelated: hour '
                   'meter / histogram table pointers). Body 0x13cc8-0x13d40 matches the plate (clr.w $80051e / clr.b $800354; cmpi.w #1 on '
                   '0x803d66 + 16 n, 4 records; move.b (0,a0,d0.w*2),(a3) with a0 = 0x805a24; 400-byte clear; move.l a1,$800504; move.b #1,$800372).'),
    '0x00013d42': ('CONFIRMED',
                   'Only caller jsr at 0x13912. Jump table 0x13d7a = 000c 0012 0018 001e 0024 002a -> case bodies move.b #5 / #10 / #20 / #40 / '
                   '#80 / #160,(a0) with a0 = 0x800353; default 5; the automatic-mode rewrite and the two clears confirmed; returns '
                   'move.b (a0),d0b.'),
    '0x00013dbe': ('CONFIRMED',
                   'Only caller jsr at 0x13928. tst.w (0,a0,d2.w) a0 = 0x803d66; push a2 / move.w (0x803d6a + d2),-(sp); jsr 0x10e16 '
                   '(cm550_lookupParameterIdAddress); add zero-extended word at 0x803d6c + d2; d2 += 16, a2 += 4, 4 records.'),
    '0x00013e12': ('CONFIRMED',
                   'Only caller jsr at 0x13aa4. Records 0..UDPRCU-1 of 0x803da4 (0x803da6 id / 0x803da8 offset, d2 += 6), results into '
                   '0x800508 + 4 n. Dump results match table(id) + offset.'),
    '0x00013e64': ('CONFIRMED',
                   'Only caller jsr at 0x1392e. For fault_code_flag == 1: scans 125 6-byte definitions from 0x8067c4 (addq.l #6,a2 / cmpi.b '
                   '#0x7d), no early exit, stores index and current status (0x805a24 + 10 x i). The definitions +0 word is the Cummins fault '
                   'code (cm550_FUN_00014872 copies it into previously_active_dtc_cummins_fault_codes).'),
    '0x00013ed8': ('CONFIRMED',
                   'Callers jsr 0x1397c (0-2) / 0x139a6 (move.w #3). All 12 compare paths decoded (unsigned bls / bcc / bge on 0-255, signed '
                   'extb.l / ble / bge; all strict) and the fault-edge path 0x1419c-0x14286 (MD 0: now 0/2 and previous 1/3; MD nonzero: now 1/3 '
                   'and previous 0/2; previous := now). function_definitions.csv: the two rows (return / param 0 condition_record_index ushort) '
                   'are keyed by the old name; ApplyFunctionDefinitions only warns on a name mismatch, but rename function_name to '
                   'cm550_evaluateDataloggerTrigger and param 0 to trigger_index as proposed.'),
    '0x00014292': ('CONFIRMED',
                   'Only caller jsr at 0x13c86 after move.l a2 (destination),-(sp) / move.l a3 (0x800374),-(sp); body movea.l (8,sp),a1 / '
                   'movea.l (4,sp),a0 / move.b (a0)+,(a1)+ x 0x190. So param 0 = source, param 1 = destination; the optional prototype '
                   '(void; byte *source; byte *destination) is right.'),
}
for f in draft['functions']:
    e = F[f['address']]
    add('function ' + f['address'], e[0], e[1], e[2] if len(e) > 2 else None)

# ---------------- removals
core = {
    '0x00803d65': 'datalogger_triggers_cal[0].disable_flag (+1); users tst.b (0,a0,d3.w) a0 = 0x803d65 at 0x1396c (only operand 0x13968).',
    '0x00803d66': 'datalogger_triggers_cal[0].fault_code_flag (+2); its 4 operands (0x13cf0 / 0x13dce / 0x13e74 / 0x13efc) are record-base loads.',
    '0x00803d6a': 'datalogger_triggers_cal[0].parameter_id_or_fault_code (+6); operands 0x13ddc / 0x13e98 are record-base loads.',
    '0x00803d95': 'datalogger_triggers_cal[3].disable_flag (+0x31); tst.b $803d95 at 0x13994 is trigger 4 of the array.',
    '0x00803da6': 'datalogger_data_parameters_cal[0].parameter_id (+2); operand 0x13e26 is a record-base load.',
}
ring_lo, ring_hi = 0x800374, 0x800504
for r in draft['rows_to_remove']:
    a = int(r['address'], 16)
    nm = r['name']
    if r['address'] in core:
        add('remove ' + r['address'], 'CONFIRMED', nm + ' becomes ' + core[r['address']] + ' Struct field replaces the scalar; no other user.')
        continue
    base = 'Row ' + nm + ' is undefined, uncommented, has 0 .cpp references and no ROM operand (word-aligned 4-byte scan of the dumped ROM). '
    if 0x800356 <= a < 0x800366:
        if a == 0x800358:
            add('remove ' + r['address'], 'AMENDED',
                base + 'Inside datalogger_trigger_parameter_addresses (4 dwords, dump 0x80ccf4 / 0x80a320 / 0x80d32e / 0x80aa82, so 0x800358 '
                'holds 0xccf4, never a 0-0x27 phase). The name is a stale scheduler claim: CM550 switches on scheduler_phase_index '
                '0x0080068c in executiveFrameInterruptHandler; CM848 0x003fa008 is executive_frame_phase. The removed name survives in '
                'docs, which the proposal stale-reference sweep (renamed names only) would miss; no script reads the map.',
                'Remove as proposed, and also fix the stale references: docs/cross_firmware_variable_map.csv line 17 (0x00800358,0x003fa008,'
                'main_loop_phase_index,confirmed - CM550 is 0x0080068c scheduler_phase_index, CM848 is executive_frame_phase; correct or '
                'drop the row), docs/cross-firmware-analysis.md line 204 (both columns), the CM550 enums.csv line 75 comment '
                '"main_loop_phase_index in scheduler switch" (-> scheduler_phase_index), and optionally the historical spec '
                'docs/superpowers/specs/2026-03-17-cross-firmware-convergence-pipeline-design.md line 86.')
            continue
        add('remove ' + r['address'], 'CONFIRMED', base + 'Inside datalogger_trigger_parameter_addresses 0x800356-0x800365 (addq.l #4,a2 x 4 in 0x13dbe, '
            '(0,a2,d0.l*4) in 0x13ed8); the dumped dwords are the four resolved trigger addresses.')
    elif a == 0x800370:
        add('remove ' + r['address'], 'CONFIRMED', base + 'Inside datalogger_trigger_previous_fault_status 0x80036e-0x800371 (index 0-3: (0,a3,d0.l) in '
            '0x13ed8, a1 = 0x80036e + n in 0x13e64, a3 + n in 0x13cc8).')
    elif ring_lo < a < ring_hi:
        add('remove ' + r['address'], 'CONFIRMED', base + 'Inside datalogger_sample_ring_buffer 0x800374-0x800503 (0x190-byte clears, wrap at 0x800504); '
            'the dumped bytes are 10-byte datalogger samples.')
    elif 0x804fca < a < 0x8052ea:
        add('remove ' + r['address'], 'CONFIRMED', base + 'Inside datalogger_event_sample_buffers (event 1 = 0x804fca + 400, written whole by the 0x14292 '
            'copy); its dumped byte 0x00 is part of event 1 first sample.')
    else:
        raise SystemExit('unclassified ' + r['address'])

out = {
    'item': 'S2',
    'overall': 'PLACEHOLDER',
    'verdicts': V,
}
json.dump(out, open('/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S2-skeptic/verdicts.json', 'w'), indent=1)
from collections import Counter
print(len(V), Counter(v['verdict'] for v in V))
