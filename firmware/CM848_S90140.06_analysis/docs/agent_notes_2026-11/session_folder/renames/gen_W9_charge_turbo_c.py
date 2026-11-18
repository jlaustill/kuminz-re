# Part C: the other uncertain rows, the monitor-completion decode, 0x3fae3c, final notes, and the writer.
import json
import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames')
from gen_W9_charge_turbo_b import *   # noqa: F401,F403  (ROWS, helpers, BOOT)


# ---------------------------------------------------------------- C_CSE_Aggressiveness cells (neighbours of the angle limits)
g("0x003ff85c", "speed_threshold_scale_cal", "charge_system_aggressiveness_gain_scale",
  "code: multiplies fuel_limit_ratio_compensated_reference >> 13 into charge_system_aggressiveness_gain_adjusted while the hysteresis flag is 1 (cm848_calculateChargeSystemAdjustedMassChargeFlowError; the plate of that function already cites this name). e2m (same block as the three angle cells 0x3ff856 / 58 / 5a = C_CSE_Xform_LLim / _Override_Value / _ULim, equal offsets): C_CSE_Aggressiveness_Gain (0x01169D06, 1/8192). ROM-to-RAM cell, no _cal. Dump 0. (was speed_threshold_scale_cal)")
g("0x003ff85e", "fuel_blend_load_lower_threshold", "charge_system_aggressiveness_off_threshold",
  "code: the hysteresis flag clears when fuel_limit_ratio_compensated_reference is at or below it (cm848_calculateChargeSystemAdjustedMassChargeFlowError). e2m: C_CSE_Aggressiveness_Off (0x01169D08, 1/8192, 'hysteresis off threshold, off - no gain to charge aggressiveness'). Dump 8192 = 1.0. (was fuel_blend_load_lower_threshold)")
g("0x003ff860", "fuel_blend_load_upper_threshold", "charge_system_aggressiveness_on_threshold",
  "code: the hysteresis flag sets when fuel_limit_ratio_compensated_reference reaches it. e2m: C_CSE_Aggressiveness_On (0x01169D0A, 1/8192). Dump 10240 = 1.25. (was fuel_blend_load_upper_threshold)")

# ---------------------------------------------------------------- (3a) 0x3fa7ae / 0x3fa7b0
unc("0x003fa7ae", "governor_target_speed_c_working",
    "Checked again, still no name: the only access is the boot store in cm848_clearEgrValveHBridgeFaultState (between egr_valve_h_bridge_inrush_fault_counter 0x3fa7aa and egr_valve_h_bridge_fault_reset_flag 0x3fa7bc, after the two timers and two counters); no read anywhere (xref_addr.py 0 reads / 1 write; boot-ROM scan of 0x0-0x7F5F: none). They are not the upper halves of the timers: in the EGR module the retry timers are single word rows (egr_valve_h_bridge_fault_retry_timer 0x3fa7a4 / egr_valve_h_bridge_inrush_retry_timer 0x3fa7a8, updated as words by cm848_updateEgrValveHBridge*RetryTimer), unlike the VGT twin whose retry timers are dwords (cleared as ._0_2_ / ._2_2_). Role unknown (boot-cleared state that no code reads); the 'governor target speed' name is wrong, keep the row unrenamed or give it a neutral placeholder only if the applier needs one.")
unc("0x003fa7b0", "governor_target_speed_d_working",
    "Same as 0x3fa7ae: one boot store (cm848_clearEgrValveHBridgeFaultState), no read, no boot-ROM user; not a timer half (see 0x3fa7ae); role unknown; the old governor name is wrong.")

# ---------------------------------------------------------------- (3b) 0x4002ea
g("0x004002ea", "boost_correction_alt_mode_cal", "egr_flow_cold_side_algorithm_select",
  "code: selector read by six functions (xref_addr.py 6 reads / 0 writes, all lhz): 0 = the EGR delta pressure is the delta pressure sensor output, non-zero (dump 1) = it is computed from two other pressures ((boost_pressure_current_raw - boost_pressure_baseline_cal) - map_fuel_correction_factor); the EGR valve autozero command is 12800 for 0 and 0 for non-zero; the cooler fouling monitor needs non-zero; the orifice temperature state counts only while non-zero. e2m (block anchor, equal relative offsets): C_CHP_Downstream_Delta_P_Active (0x01177E08, 'Select hot side (0) or cold side (1) EGR flow algorithm'): the block 0x4002e2-0x4002f0 is C_CHP_EGR_Flow_Fil_Cnst (0x4002e2, an EMA coefficient), _EGR_Flow_Max (2560), _EGR_Flow_Min (0), _Volume_Fraction (9552), Downstream_Delta_P_Active (this cell, 1), Venturi_Vrt_Sensor_Active (0x4002ec = 1), EGR_Flow_Delay_Fraction (0x4002ee), EGR_Pos_Delay_Fil_Cnst (0x4002f0 = 32768, 0.5). ROM-to-RAM cell outside the EEPROM mirror, so no _cal. (was boost_correction_alt_mode_cal)")

# ---------------------------------------------------------------- (3c) 0x3fd7f0
g("0x003fd7f0", "cold_start_inhibit_cal", "air_handling_compensation_and_diagnostic_bypass_cal",
  "code: EEPROM-mirror trim with five readers, every one of the form '(feature bit clear) or this trim non-zero' (all five read in the C output): cm848_processBoostControlState (0x1359c) takes a bypass branch (with governor_feature_config_flags bit 0x10 clear); cm848_calculatePressureSensorFiltered (0x13dc8, the intake manifold temperature lag compensation of sensor channel 9) sets pressure_correction_scale to 0 and skips the two lag filters; cm848_updateEgrDeltaPressureAutozero copies it as egr_delta_pressure_autozero_error_count_clear_flag; cm848_updateEgrCoolerFoulingFaultCounter holds the fouling counter at 0; sensor_throttleTrim_ema_faultProcess (the EGR orifice temperature lead compensation) sets the lead gain to 0 and skips the two filters. So non-zero switches the air handling lead compensations off and clears / holds their diagnostic counters. e2m candidate (not anchored by a block offset, hence the code-based name): T_Bench_Test (0x01177100, 'resets fault set in estimating Delta-P zero offset'), twin of egr_valve_position_autozero_error_count_clear_cal 0x3fd7f2 (T_EGR_Clr_Autozero_Error_Count). Dump 0. " + BOOT + " (was cold_start_inhibit_cal)")

# ---------------------------------------------------------------- (3d) exhaust and EGR orifice temperature
g("0x0040a686", "boost_fuel_input_value", "exhaust_temperature",
  "code: estimated exhaust temperature in 0.5 degree F per count = intake_manifold_temperature_filtered x 2 / 64 + the combustion temperature rise (boost_target_fuel_normalized_ratio from cm848_calculateCombustionTemperatureRise), the rise is 0 while engine speed < 1 rpm or charge_fuel_ratio < 128 (boost_target_calc_inhibit_flag); the cooler efficiency uses it x 32 (1/64 degree F) as the hot side temperature. e2m (block 0x40a67e = 0x0117A100, equal offsets): Exhaust_Tmptr (0x0117A108, DEG_F 0.5, 'Exhaust Temperature virtual sensor value'); the rise is DAT_0040a680 = TPE_Delta_Exhaust_Tmptr (0x0117A102). Dump 81 = 40.5 degrees F (engine off, intake temperature only). (was boost_fuel_input_value)")
g("0x0040a68c", "throttle_trim_lookup_input", "egr_orifice_temperature",
  "code: the selected EGR orifice temperature (1/64 degree F), the cooler outlet side of the efficiency formula: sensor_throttleTrim_inputSelect copies the lead-compensated and doubly filtered sensor channel 108 value, or sensor_channel108_default_value when bit 1 of the state is set; it equals sensor_channel108_value (4608 = 72 degrees F, the channel default) in the dump. e2m (block 0x40a68c = 0x0119CA00, equal offsets): EGR_Orifice_Tmptr (DEG_F 0.015625), with Source / State / INM_EGRT_After_Lead / INM_EGRT_Lead_Term / INM_EGRT_Lead_Time_Constant at 0x40a68e / 90 / 92 / 94 / 96; e2m sensor EGR_Orifice_Tmptr_Sensor (0x01196614) is sensor_channel108_value (0x40bd94, generic sensor block base 0x40bd80). (was throttle_trim_lookup_input)")
g("0x0040a688", "boost_correction_block_mode_flag", "exhaust_temperature_source",
  "type dword -> i16: the accesses are sth (cm848_auxiliaryControl_exponentialAverage 0x506f40) and lha (cm848_calculateEgrCoolerEfficiency 0x5033e8), xref_addr.py / disasm_func.py width verdict word, no dword access. code: 0 when the exhaust temperature estimate is valid (state words 0, calculation not inhibited), otherwise 1; the cooler monitor requires 0. e2m: Exhaust_Tmptr_Source (0x0117A10A, 'estimated exhaust temp source quality indicator'). Dump 1. (was boost_correction_block_mode_flag)",
  type="i16", old_type="dword")
ng("0x0040a68a", "exhaust_metal_temperature", "word",
   "replaces the label row boost_correction_block_mode_flag+2 (DELETE it). width: sth (cm848_auxiliaryControl_exponentialAverage 0x506ef0) and lhz (governor_adjustment_compare 0x5044b8), no other access. code: first-order filter of exhaust_temperature (coefficient 0x406770), 0.5 degree F per count; compared with an altitude dependent exhaust temperature threshold. e2m: Exhaust_Metal_Tmptr (0x0117A10C, 'Exhaust Metal Temperature virtual sensor value'). Dump 81.")
g("0x0040a68e", "fuel_demand_mode_index_init_flag", "egr_orifice_temperature_source",
  "type dword -> i16: sth (sensor_throttleTrim_inputSelect 0x5071b0) and lha (cm848_calculateEgrCoolerEfficiency 0x5033f8, cm848_updateEgrSystemHealthFlags 0x503668), no dword access. code: 0 = the filtered sensor value is selected, 2 = the channel default (bit 1 of the state set); the cooler monitor and the EGR health flags need 0. e2m: EGR_Orifice_Tmptr_Source (0x0119CA02, '0=PRIMARY, 1=BACKUP, 2=DEFAULT'). Dump 2. (was fuel_demand_mode_index_init_flag)",
  type="i16", old_type="dword")
ng("0x0040a690", "egr_orifice_temperature_state", "i16",
   "replaces the label row fuel_demand_mode_index_init_flag+2 (DELETE it). width: sth (sensor_throttleTrim_ema_faultProcess 0x507060) and lha (sensor_throttleTrim_inputSelect 0x507170), no other access. code: sensor_channel108_fault_status while egr_flow_cold_side_algorithm_select is non-zero, otherwise 0 (written by sensor_throttleTrim_ema_faultProcess). e2m: EGR_Orifice_Tmptr_State (0x0119CA04). Dump 2.")
note("DELETE 0x0040a68a boost_correction_block_mode_flag+2: label of the second word of a mis-sized dword; replaced by the new word row exhaust_metal_temperature (the first word 0x40a688 is retyped dword -> i16 as exhaust_temperature_source).")
note("DELETE 0x0040a690 fuel_demand_mode_index_init_flag+2: label of the second word of a mis-sized dword; replaced by the new i16 row egr_orifice_temperature_state (the first word 0x40a68e is retyped dword -> i16 as egr_orifice_temperature_source).")
note("EXHAUST TEMPERATURE / EGR ORIFICE TEMPERATURE CHAIN (settles the cooler monitor): the EGR cooler effectiveness (cm848_calculateEgrCoolerEfficiency) = (exhaust_temperature x 32 - egr_orifice_temperature) x 10000 / (exhaust_temperature x 32 - coolant temperature): the hot side is the ESTIMATED exhaust temperature (intake manifold temperature + combustion temperature rise, e2m Exhaust_Tmptr) and the outlet side the measured, lead-compensated EGR orifice temperature (sensor channel 108). Neighbours of the same e2m blocks that are still unrenamed: 0x40a67e boost_target_fuel_normalized_ratio (the combustion temperature rise, 0.5 degree F), 0x40a680 DAT (TPE_Delta_Exhaust_Tmptr copy), 0x40a682 boost_target_load_rpm_output, 0x40a684 boost_target_calc_inhibit_flag; 0x40a692 throttle_trim_predictor_output (INM_EGRT_After_Lead), 0x40a694 DAT (INM_EGRT_Lead_Term), 0x40a696 throttle_trim_predictor_gain (INM_EGRT_Lead_Time_Constant); EGR orifice lead enable = bit 0x8000 of cold_start_feature_enable_flags (e2m T_INM_EGRT_Lead_Enable 0x01106B2A mask 0x8000); the two tables at 0x406778 / 0x40678c (lookup on egr_mass_flow_delayed_filtered whose output is the coefficient of the lead filter ema_filter_state_t_003fbd00) are e2m C_INM_EGRT_Lead_EGR_Flow_Axis / C_INM_EGRT_Lead_Time_Cnst_Table (0x011A2F00 / 0x011A3000); 0x406774 and throttle_trim_predictor_output_min are probably C_INM_EGRT_Max / _Min (0x011A2E02 / 04, not proven); 0x406770 is the separate coefficient of the exhaust metal temperature filter. In the dump the orifice sensor is at its default (source 2, 72 degrees F): no EGR orifice sensor on this truck.")

# ---------------------------------------------------------------- (4) monitor completion decode: fault words
g("0x003fe9d4", "diagnostic_status_flags_working", "fault_detected_bits_768_to_783",
  "Word 48 of fault-detected array 0x3fe974 ((0x3fe9d4 - 0x3fe974) / 2 = 48; fault bit = word x 16 + bit via ROM 0x5985a -> obd_dtc_code_table): only mask 0x400 (fault 778) has a DTC, P0069 (MAP / barometric pressure correlation); masks 0x40 / 0x80 / 0x100 / 0x200 (faults 774-777) have no DTC slot (slot 170): internal bits, 0x240 are set by the EGR delta pressure plausibility check cm848_calibration_group22_load. (was diagnostic_status_flags_working)")
g("0x003fea38", "diagnostic_status_flags_snapshot", "fault_registered_bits_768_to_783",
  "Word 48 of fault-registered array 0x3fe9d8 ((0x3fea38 - 0x3fe9d8) / 2): registered copy of fault_detected_bits_768_to_783. (was diagnostic_status_flags_snapshot)")
g("0x003fea96", "diagnostic_status_snapshot", "fault_previous_pass_bits_720_to_735",
  "Word 45 of the previous-pass array 0x3fea3c ((0x3fea96 - 0x3fea3c) / 2 = 45): previous-pass copy of fault_detected_bits_720_to_735 (mask 0x200 = fault 729, P0299), compared by cm848_completeBoostPressureMonitorReport. (was diagnostic_status_snapshot)")
g("0x003fea9c", "diagnostic_status_flags_ring_snapshot", "fault_previous_pass_bits_768_to_783",
  "Word 48 of the previous-pass array 0x3fea3c ((0x3fea9c - 0x3fea3c) / 2): previous-pass copy of fault_detected_bits_768_to_783 (mask 0x400 = fault 778, P0069). (was diagnostic_status_flags_ring_snapshot)")
note("MONITOR COMPLETION DECODE (lead 4), all from the ROM slot table 0x5985a and obd_dtc_code_table 0x5b57c: fault 64 (bit 0 of fault_detected_bits_64_to_79) = slot 48 = P0236; fault 729 (mask 0x200 of fault_detected_bits_720_to_735) = slot 160 = P0299; fault 778 (mask 0x400 of fault_detected_bits_768_to_783) = slot 149 = P0069; faults 774-777 (0x40 / 0x80 / 0x100 / 0x200 of the same word) = slot 170 (no DTC). cm848_completeBoostPressureMonitorReport compares each of these three bits with its previous-pass copy (DAT_003fea44 = previous-pass word 4 = fault_previous_pass_bits_64_to_79 at 0x3fea44, no row yet), and the detectors were read: cm848_calibration_group21_load (0x52d6a8) sets fault 64 when the intake manifold pressure at cranking is above DAT_000642be (P0236), fault 778 when |barometric pressure - intake manifold pressure| at cranking is above DAT_000642cc (P0069, a MAP / barometric correlation check), and, while running at the governor setpoint with engine speed and load gates, fault 729 when the boost above barometric stays below DAT_000642ca for more votes than DAT_000642c6 (P0299 underboost, mask 0x200 of fault_detected_bits_720_to_735). So the DTC names say boost / MAP and so do the detectors: there is no EGR delta pressure in this monitor. The EGR link of the earlier note came from cm848_calibration_group22_load (0x52e29c): an EGR delta pressure sensor plausibility check at crank phase (key on, cranking, valve below its threshold, no fault 725) that sets faults 774 and 777 (0x240, no DTC) when |delta pressure| exceeds DAT_00409ea8, plus a running-engine half; a better name for it would be cm848_checkEgrDeltaPressureSensorPlausibility (not read in full here, so not proposed as a row). cm848_calibration_group21_load_cont (0x52eae8) is the cam / start-up evaluation and stays as is.")

# ---------------------------------------------------------------- (5) 0x3fae3c
g("0x003fae3c", "", "j1939_pgn65270_tx_length",
  "type byte -> word. The IC1 (PGN 65270, 0xfef6) transmit descriptor at 0x3fae38 has the j1939_tx_msg_t layout: +0 header dword (j1939_pgn65270_tx_header), +4 data_length word (j1939_msg_hdr_t.data_length is a word), +6 data pointer (0x3fae3e), +10 end pointer (0x3fae42); cm848_initJ1939InletExhaustConditionsBuffer stores the length 8 with ONE sth r9,4(r4) (disasm_func.py: word; the stw at 6(r4) / 10(r4) store the two pointers, 0x3fae46 + 8 = 0x3fae4e), no other access anywhere (xref_addr.py 0 references by name). Same pattern as j1939_pgn65213_tx_length (0x3fae2c) and j1939_pgn61440_tx_length (0x3fae14). " + BOOT + " The cpp renders it _BYTE_003fae3c = 8 today. Boot check widened: the boot ROM 0x0-0x7F5F has no access to 0x3fae38 (descriptor base, reached as 4(r4) by the application), 0x3fae3a-0x3fae46 (every halfword). What the kernel image holds there: the RAM copy of ROM 0x526c (0x3fae3c = 0x3f9800 + 0x163c, ROM 0x3c30 + 0x163c), a function prologue (stwu r1,-48(r1) / mflr r0 / stmw), i.e. code at boot and the IC1 length word in the running application.",
  type="word", old_type="byte")
g("0x003fae3e", "j1939_tx_buf_data_ptr", "j1939_pgn65270_data_ptr",
  "code: dword store of &DAT_003fae46 at +6 of the IC1 (PGN 65270) descriptor 0x3fae38 (data_pointer of j1939_tx_msg_t), the only access (stw r3,6(r4)); the generic name hid that it belongs to this one message, like j1939_pgn65251_data_ptr etc. Type stays pointer. The boot ROM has no access to 0x3fae38-0x3fae46 (see 0x3fae3c); the kernel image holds code here at boot (RAM copy of ROM 0x526c-0x5270). " + BOOT + " (was j1939_tx_buf_data_ptr)")
g("0x003fae42", "", "j1939_pgn65270_end_ptr",
  "code: dword store of 0x3fae4e (first byte after the 8 data bytes at 0x3fae46) at +10 of the IC1 descriptor 0x3fae38 (data_end_pointer of j1939_tx_msg_t), the only access (stw r11,10(r4)). Type stays pointer (row exists, name was blank; renders PTR_DAT_003fae42 today). The boot ROM has no access to 0x3fae42 (scanned, together with 0x3fae38-0x3fae46); the kernel image holds code at 0x3fae3c-0x3fae44 at boot (RAM copy of ROM 0x526c-0x5274). " + BOOT,
  type="pointer", old_type="pointer")

# ---------------------------------------------------------------- remaining notes
note("OTHER LEFT-OVERS (not renamed, with the reason): (a) boost_pressure_current_raw 0x40a7d0 / boost_pressure_baseline_cal 0x40675a / map_fuel_correction_factor 0x40a42e: map_fuel_correction_factor is the boost (charge) pressure (its change is the boost lead term of the turbocharger speed estimate and its ratio to boost_fuel_scale_divisor 0x40a19e, the ambient pressure, indexes the 3-D table); the alternate delta pressure is (boost_pressure_current_raw - boost_pressure_baseline_cal) - map_fuel_correction_factor, and e2m C_TPE_Exhaust_Pressure_Offset ('offset subtracted from Exhaust_Pressure_Sensor to calculate Exhaust_Pressure') matches the baseline cell by role only, so the exhaust pressure reading of boost_pressure_current_raw is a lead, not a proven name. (b) fuel_demand_mode_index 0x40a430 / fuel_demand_mode_state 0x40a1a0 / fuel_demand_state_b 0x40a60a / fuel_demand_phase_state 0x40a462 are the 0 / 1 / 2 state words of the four estimator inputs (charge pressure, ambient pressure, a third input, intake manifold temperature with the temperature stored at the neighbour 0x40a460): they are tested by the turbocharger speed estimation status, the charge pressure estimate and the cooler / EGR health flags; naming them needs the sensor identities of 0x40a60a. (c) cm848_calibration_group22_load / group21_load_cont: see the monitor completion note. (d) the EGR flow estimation constants 0x4002e2-0x4002f0 (C_CHP_* block) are listed in the egr_flow_cold_side_algorithm_select evidence.")
note("RENDER / APPLY NOTES: every global above in 0x3F9800-0x3FDB30 (0x3fcbfe-0x3fcc1e, 0x3fd7f0, 0x3fd8ac-0x3fd8b2, 0x3fa150-0x3fa15e, 0x3fae3c-0x3fae42) was scanned in the boot ROM 0x0-0x7F5F: no user. The only type changes are 0x3fae3c byte -> word (one sth, no other access), 0x40a688 / 0x40a68e dword -> i16 and the new row 0x40a690 i16 (sth stores, lha loads, no dword access), the new row 0x40a68a word (sth / lhz) and the new row 0x3ff702 i16 (lha); every one has its instruction proof in its row. Time-shared 0x3fcc08 keeps ema_filter_state_t (name only). Rows with a retype that remove a label row: 0x40a68a and 0x40a690 (see the DELETE note).")




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

def write(path):
    with open(path, 'w') as f:
        for r in ROWS:
            f.write(json.dumps(r, ensure_ascii=True) + "\n")
    return len(ROWS)


if __name__ == '__main__':
    _exact_notes()
    n = write('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_charge_turbo.jsonl')
    print('rows written:', n)
