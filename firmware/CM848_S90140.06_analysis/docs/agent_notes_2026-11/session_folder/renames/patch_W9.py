import re

D = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/'


def rep(s, old, new, count=1):
    assert old in s, ('missing', old[:70])
    return s.replace(old, new) if count == 0 else s.replace(old, new, count)


# ------------------------------------------------------------------ part A
a = open(D + 'gen_W9_charge_turbo_a.py').read()
a = rep(a, "(the half-angle fit is the same numbers only if the angle unit were 1/256 degree, but e2m declares 1/512 and describes the axis as 0-PI/2; the angle limits 512 / 46080 and the 90 degree grid fit the 1/512 unit).",
        "(the same numbers also fit cos(angle / 2) if the angle unit were 1/256 degree, so the CODE cannot discriminate the two; the plain cosine rests on the e2m only: it declares 1/512 degree per count and describes the axis as 'input defined from 0-PI/2'; the angle limits 512 / 46080 then read 1 / 90 degrees and the all-90-degree grid decouples the two controllers).")
open(D + 'gen_W9_charge_turbo_a.py', 'w').write(a)

# ------------------------------------------------------------------ part B
b = open(D + 'gen_W9_charge_turbo_b.py').read()
b = rep(b, "With the sensor not installed (turbocharger_speed_sensor_installed = 0, as in the dump) it clears the in-range fault bits, sets the frequency to 0,",
        "With the sensor not installed (turbocharger_speed_sensor_installed = 0, as in the dump) it clears the three sensor fault bits (611 / 613 / 618), sets the frequency to 0,")
b = rep(b, "sets output line 49 from turbocharger_speed_sensor_configuration (1 = variable reluctance, 0 = eddy current sensor)",
        "sets bit 1 of output_line_state.lines_48_to_55 (line 49 if bit 0 is line 48) from turbocharger_speed_sensor_configuration (1 = variable reluctance, 0 = eddy current sensor)")
b = rep(b, "scaled by the intake air temperature factor;", "scaled by a temperature factor looked up on the ambient air temperature;")
b = rep(b, "output_line_state.lines_48_to_55 bit 1 follows 0x3ff70e", "output_line_state.lines_48_to_55 bit 1 follows 0x3ff70e (not verified which line number that bit is)")
b = rep(b, "b11 / b12 (faults 619 / 620, P9934) are never set by the turbocharger speed code. Written only by the turbocharger speed sensor diagnostics (Bank 2 0x50eeb0-0x50f6c4).",
        "b11 / b12 (faults 619 / 620) map to slot 78 = B1934 (raw 0x9934: the letter comes from the top two bits, checked against word 32 = B1971-B1976) and have no named setter in the turbocharger speed code. No named access outside the turbocharger speed sensor diagnostics (Bank 2 0x50eeb0-0x50f6c4); the generic fault scan reaches the word by index.")
b = rep(b, "faults 619 / 620 = P9934 but nothing in the turbo speed code sets them.",
        "faults 619 / 620 = B1934 (raw 0x9934; the DTC letter is the top two bits of the table word, verified: it reproduces word 32 = B1971-B1976 of task 027) with no named setter in the turbo speed code.")
b = rep(b, "while set cm848_calculateChargeFlowTurbochargerSpeedDerate sets charge_flow_turbocharger_speed_derate_offset to 0 (the charge flow command is limited to the present flow). (was throttle_rate_filter_reset_flag)",
        "while set cm848_calculateChargeFlowTurbochargerSpeedDerate sets charge_flow_turbocharger_speed_derate_offset to 0 (the charge flow command is limited to the present flow) and cm848_calibrationGroup5_periodic skips its altitude fuel correction upper limit lookup (the immediate engine derate of e2m TU_WG_Immediate_Speed_Derate_Thr); written by cm848_updateTurbochargerOverspeedImmediateDerate, cleared at boot by cm848_initialization_step_2. (was throttle_rate_filter_reset_flag)")
open(D + 'gen_W9_charge_turbo_b.py', 'w').write(b)

# ------------------------------------------------------------------ part C
c = open(D + 'gen_W9_charge_turbo_c.py').read()

# 0x3fd7f0: code-true name, all five users read
i0 = c.index('g("0x003fd7f0"')
i1 = c.index('# ---------------------------------------------------------------- (3d)')
new_fd7f0 = '''g("0x003fd7f0", "cold_start_inhibit_cal", "air_handling_compensation_and_diagnostic_bypass_cal",
  "code: EEPROM-mirror trim with five readers, every one of the form '(feature bit clear) or this trim non-zero' (all five read in the C output): cm848_processBoostControlState (0x1359c) takes a bypass branch (with governor_feature_config_flags bit 0x10 clear); cm848_calculatePressureSensorFiltered (0x13dc8, the intake manifold temperature lag compensation of sensor channel 9) sets pressure_correction_scale to 0 and skips the two lag filters; cm848_updateEgrDeltaPressureAutozero copies it as egr_delta_pressure_autozero_error_count_clear_flag; cm848_updateEgrCoolerFoulingFaultCounter holds the fouling counter at 0; sensor_throttleTrim_ema_faultProcess (the EGR orifice temperature lead compensation) sets the lead gain to 0 and skips the two filters. So non-zero switches the air handling lead compensations off and clears / holds their diagnostic counters. e2m candidate (not anchored by a block offset, hence the code-based name): T_Bench_Test (0x01177100, 'resets fault set in estimating Delta-P zero offset'), twin of egr_valve_position_autozero_error_count_clear_cal 0x3fd7f2 (T_EGR_Clr_Autozero_Error_Count). Dump 0. " + BOOT + " (was cold_start_inhibit_cal)")

'''
c = c[:i0] + new_fd7f0 + c[i1:]

# word / i16 retypes with instruction proof
c = rep(c, '"type dword -> word (the old dword was two words; every access is a halfword: cpp renders ._0_2_ / ._2_2_). code: 0 when the exhaust temperature estimate is valid',
        '"type dword -> i16: the accesses are sth (cm848_auxiliaryControl_exponentialAverage 0x506f40) and lha (cm848_calculateEgrCoolerEfficiency 0x5033e8), xref_addr.py / disasm_func.py width verdict word, no dword access. code: 0 when the exhaust temperature estimate is valid')
c = rep(c, '  type="word", old_type="dword")\nng("0x0040a68a"', '  type="i16", old_type="dword")\nng("0x0040a68a"')
c = rep(c, '"replaces the label row boost_correction_block_mode_flag+2 (DELETE it). width: the only accesses are halfword (cm848_auxiliaryControl_exponentialAverage writes it, governor_adjustment_compare reads it twice).',
        '"replaces the label row boost_correction_block_mode_flag+2 (DELETE it). width: sth (cm848_auxiliaryControl_exponentialAverage 0x506ef0) and lhz (governor_adjustment_compare 0x5044b8), no other access.')
c = rep(c, '"type dword -> word (every access is a halfword: cpp renders ._0_2_ / ._2_2_). code: 0 = the filtered sensor value is selected',
        '"type dword -> i16: sth (sensor_throttleTrim_inputSelect 0x5071b0) and lha (cm848_calculateEgrCoolerEfficiency 0x5033f8, cm848_updateEgrSystemHealthFlags 0x503668), no dword access. code: 0 = the filtered sensor value is selected')
c = rep(c, '  type="word", old_type="dword")\nng("0x0040a690"', '  type="i16", old_type="dword")\nng("0x0040a690"')
c = rep(c, 'ng("0x0040a690", "egr_orifice_temperature_state", "word",\n   "replaces the label row fuel_demand_mode_index_init_flag+2 (DELETE it). width: halfword accesses only.',
        'ng("0x0040a690", "egr_orifice_temperature_state", "i16",\n   "replaces the label row fuel_demand_mode_index_init_flag+2 (DELETE it). width: sth (sensor_throttleTrim_ema_faultProcess 0x507060) and lha (sensor_throttleTrim_inputSelect 0x507170), no other access.')
# one DELETE note per address (wave 8 form)
j0 = c.index('note("DELETE 0x0040a68a boost_correction_block_mode_flag+2 and')
j1 = c.index('note("EXHAUST TEMPERATURE / EGR ORIFICE TEMPERATURE CHAIN')
c = c[:j0] + '''note("DELETE 0x0040a68a boost_correction_block_mode_flag+2: label of the second word of a mis-sized dword; replaced by the new word row exhaust_metal_temperature (the first word 0x40a688 is retyped dword -> i16 as exhaust_temperature_source).")
note("DELETE 0x0040a690 fuel_demand_mode_index_init_flag+2: label of the second word of a mis-sized dword; replaced by the new i16 row egr_orifice_temperature_state (the first word 0x40a68e is retyped dword -> i16 as egr_orifice_temperature_source).")
''' + c[j1:]

# lead 4: detectors found
c = rep(c, "Conflict resolved (decoded against the ROM slot table 0x5985a / obd_dtc_code_table 0x5b57c): the compared words are fault bits, not the EGR delta pressure.",
        "Conflict resolved by decoding both sides (ROM slot table 0x5985a / obd_dtc_code_table 0x5b57c, and the detectors): the compared words are fault bits, and the detectors that set them are boost / MAP checks in cm848_calibration_group21_load (0x52d6a8): at cranking intake manifold pressure above DAT_000642be sets fault 64 (P0236), and a barometric - intake manifold pressure difference above DAT_000642cc sets fault 778 (P0069); at the governor setpoint with speed and load gates, boost above barometric below DAT_000642ca for more votes than DAT_000642c6 sets fault 729 (P0299 underboost). No EGR delta pressure is involved.")
c = rep(c, "The delta pressure plausibility function cm848_calibration_group22_load sets 0x240 there (faults 774 and 777, no DTC), which is why the group 21 / 22 context looked EGR related. The name stays right: P0236 / P0299 / P0069 are all boost / MAP DTCs.",
        "The EGR delta pressure plausibility function cm848_calibration_group22_load sets 0x240 there (faults 774 and 777, no DTC), which is why the group 21 / 22 context looked EGR related. The name stays right: P0236 / P0299 / P0069 are all boost / MAP DTCs. cm848_calibration_group21_load (not renamed here, read only in part) is the detector of this monitor.")
c = rep(c, "i.e. the DTC names say boost / MAP and so do the compared words: there is no EGR delta pressure in the comparison.",
        "and the detectors were read: cm848_calibration_group21_load (0x52d6a8) sets fault 64 when the intake manifold pressure at cranking is above DAT_000642be (P0236), fault 778 when |barometric pressure - intake manifold pressure| at cranking is above DAT_000642cc (P0069, a MAP / barometric correlation check), and, while running at the governor setpoint with engine speed and load gates, fault 729 when the boost above barometric stays below DAT_000642ca for more votes than DAT_000642c6 (P0299 underboost, mask 0x200 of fault_detected_bits_720_to_735). So the DTC names say boost / MAP and so do the detectors: there is no EGR delta pressure in this monitor.")

# 0x3fae3c rows: wider boot scan + kernel content
c = rep(c, 'Dump value not needed (written at boot). The cpp renders it _BYTE_003fae3c = 8 today.",',
        'The cpp renders it _BYTE_003fae3c = 8 today. Boot check widened: the boot ROM 0x0-0x7F5F has no access to 0x3fae38 (descriptor base, reached as 4(r4) by the application), 0x3fae3a-0x3fae46 (every halfword). What the kernel image holds there: the RAM copy of ROM 0x526c (0x3fae3c = 0x3f9800 + 0x163c, ROM 0x3c30 + 0x163c), a function prologue (stwu r1,-48(r1) / mflr r0 / stmw), i.e. code at boot and the IC1 length word in the running application.",')
c = rep(c, 'Type stays pointer. " + BOOT + " (was j1939_tx_buf_data_ptr)")',
        'Type stays pointer. The boot ROM has no access to 0x3fae38-0x3fae46 (see 0x3fae3c); the kernel image holds code here at boot (RAM copy of ROM 0x526c-0x5270). " + BOOT + " (was j1939_tx_buf_data_ptr)")')
c = rep(c, 'renders PTR_DAT_003fae42 today). " + BOOT,',
        'renders PTR_DAT_003fae42 today). The boot ROM has no access to 0x3fae42 (scanned, together with 0x3fae38-0x3fae46); the kernel image holds code at 0x3fae3c-0x3fae44 at boot (RAM copy of ROM 0x526c-0x5274). " + BOOT,')

# charge system aggressiveness cells (neighbours of the transform angle limits)
agg = '''
# ---------------------------------------------------------------- C_CSE_Aggressiveness cells (neighbours of the angle limits)
g("0x003ff85c", "speed_threshold_scale_cal", "charge_system_aggressiveness_gain_scale",
  "code: multiplies fuel_limit_ratio_compensated_reference >> 13 into charge_system_aggressiveness_gain_adjusted while the hysteresis flag is 1 (cm848_calculateChargeSystemAdjustedMassChargeFlowError; the plate of that function already cites this name). e2m (same block as the three angle cells 0x3ff856 / 58 / 5a = C_CSE_Xform_LLim / _Override_Value / _ULim, equal offsets): C_CSE_Aggressiveness_Gain (0x01169D06, 1/8192). ROM-to-RAM cell, no _cal. Dump 0. (was speed_threshold_scale_cal)")
g("0x003ff85e", "fuel_blend_load_lower_threshold", "charge_system_aggressiveness_off_threshold",
  "code: the hysteresis flag clears when fuel_limit_ratio_compensated_reference is at or below it (cm848_calculateChargeSystemAdjustedMassChargeFlowError). e2m: C_CSE_Aggressiveness_Off (0x01169D08, 1/8192, 'hysteresis off threshold, off - no gain to charge aggressiveness'). Dump 8192 = 1.0. (was fuel_blend_load_lower_threshold)")
g("0x003ff860", "fuel_blend_load_upper_threshold", "charge_system_aggressiveness_on_threshold",
  "code: the hysteresis flag sets when fuel_limit_ratio_compensated_reference reaches it. e2m: C_CSE_Aggressiveness_On (0x01169D0A, 1/8192). Dump 10240 = 1.25. (was fuel_blend_load_upper_threshold)")
'''
k0 = c.index('# ---------------------------------------------------------------- (3a)')
c = c[:k0] + agg + '\n' + c[k0:]

# exact row notes, generated from ROWS before writing
exact = '''

def _exact_notes():
    import csv
    OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/global_variables.csv'
    cur = {}
    for r in csv.reader(open(OUT)):
        if r and r[0].startswith('0x'):
            cur.setdefault(int(r[0], 16), []).append((r[1], r[2] if len(r) > 2 else ''))
    lines = []
    for r in ROWS:
        if r['kind'] == 'global' and r.get('verdict') == 'confirmed':
            a = int(r['address'], 16)
            ot = [t for n, t in cur.get(a, []) if n == r['old']]
            typ = r.get('type') or (ot[0] if ot else '')
            lines.append('%s,%s,%s' % (r['address'], r['new'], typ))
        elif r['kind'] == 'new_global':
            lines.append('%s,%s,%s' % (r['address'], r['new'], r['type']))
    fl = []
    for r in ROWS:
        if r['kind'] == 'function':
            fl.append('%s,%s' % (r['address'], r['new']))
    note('EXACT ROW CHANGES FOR THE APPLIER, global_variables.csv (address,name,type); the comment of every row is the evidence / comment text of its row above with (was <old>) appended where the row had a name; rows of kind new_global are unnamed addresses with no row today, except 0x40a68a and 0x40a690 which replace the label rows deleted first (see the DELETE notes); arrays.csv has NO row for any address in this file (checked: its 79 data rows are buffers, PCI / J1939 tables, watchdog tables, DTC and QADC tables; this contradicts the wave 8 remark that the charge manager arrays are in arrays.csv): ' + ' | '.join(lines))
    note('EXACT ROW CHANGES FOR THE APPLIER, function_renames.csv (address,name; the plate comment is plate_comment of the function row above): ' + ' | '.join(fl))

'''
c = rep(c, "def write(path):", exact + "def write(path):")
c = rep(c, "    n = write('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_charge_turbo.jsonl')", "    _exact_notes()\n    n = write('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_charge_turbo.jsonl')")
open(D + 'gen_W9_charge_turbo_c.py', 'w').write(c)
print('patched all three parts')
