"""Generate result_W8_egr_charge.jsonl (read-only research output; nothing in the repo is touched).

Every global / function row is checked against the CSV (current name at the address), the time-shared window rows get the
boot-ROM scan result written into the evidence, and the dump value is appended.
"""
import csv
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import scan  # noqa: E402

OUT = scan.REPO + "/firmware/CM848_S90140.06_analysis/output"
RESULT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_egr_charge.jsonl"
SIZE = {"byte": 1, "word": 2, "dword": 4, "i16": 2, "i8": 1, "i32": 4}

gv = {}
for r in csv.reader(open(OUT + "/global_variables.csv")):
    if r and r[0].startswith("0x"):
        gv[int(r[0], 16)] = r
fr = {}
for r in csv.reader(open(OUT + "/function_renames.csv")):
    if r and r[0].startswith("0x"):
        fr[int(r[0], 16)] = r
ram = open(scan.D.ROM.replace("cm848_rom.bin", "cm848_ram.bin"), "rb").read()

rows = []
problems = []


def window(a):
    return 0x3F9800 <= a <= 0x3FDB30 or 0x3FEE08 <= a <= 0x3FEE3D


def dumpval(a, n):
    if 0x3FA000 <= a and a - 0x3FA000 + n <= len(ram):
        return int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + n], "big")
    return None


def tail(a, typ, old_type, ev=""):
    t = ""
    n = SIZE.get(typ or old_type or "word", 2)
    v = dumpval(a, n)
    if v is not None and "Dump" not in ev:
        t += " Dump %d." % v
    if window(a):
        bs = scan.boot_scan(a)
        if bs:
            problems.append("boot-ROM hit for 0x%06x: %s" % (a, bs[:3]))
        t += " Time-shared window: no access below 0x7F60 (xref scan; boot-ROM low-halfword / 32-bit constant scan of 0x0-0x7F5F: none)."
    return t


def G(addr, old, new, ev, typ=None):
    a = int(addr, 16)
    if "turbocharger_speed" in new:
        ev += (" The 'turbocharger speed' label comes from the e2m names (CHL_Turbo_Speed_*, C_EGR_AZ_Turbo_Speed_Thd, KRPM 0.008) and from"
               " fuel_demand_quantity feeding the compressor map in cm848_estimateCompressorOutletTemperature; the variable's own rename is left as a lead.")
    row = gv.get(a)
    if row is None:
        problems.append("no CSV row at %s" % addr)
        return
    if row[1] != old:
        problems.append("%s: CSV name is %r, not %r" % (addr, row[1], old))
    rows.append({"kind": "global", "address": "0x%08x" % a, "old": old, "verdict": "confirmed", "new": new,
                 **({"type": typ} if typ else {}), "evidence": ev + tail(a, typ, row[2] if len(row) > 2 else None, ev)})


def NG(addr, new, typ, ev):
    a = int(addr, 16)
    if a in gv and "+" not in gv[a][1]:
        problems.append("new_global row exists already at %s: %s" % (addr, gv[a][1]))
    rows.append({"kind": "new_global", "address": "0x%08x" % a, "new": new, "type": typ,
                 "evidence": ev + tail(a, typ, None, ev)})


def F(addr, old, new, plate, ev):
    a = int(addr, 16)
    row = fr.get(a)
    if row is None or row[1] != old:
        problems.append("function %s: CSV name is %r, not %r" % (addr, row[1] if row else None, old))
    rows.append({"kind": "function", "address": "0x%08x" % a, "old": old, "verdict": "confirmed", "new": new,
                 "plate_comment": plate + " (was %s)" % old, "evidence": ev})


def U(addr, old, why):
    rows.append({"kind": "global", "address": addr, "old": old, "verdict": "uncertain", "evidence": why})


def NOTE(text):
    rows.append({"kind": "note", "text": text})


def DEL(addr, name, why):
    a = int(addr, 16)
    if a not in gv or gv[a][1] != name:
        problems.append("DELETE %s: CSV name is %r" % (addr, gv.get(a, [None, None])[1]))
    NOTE("DELETE 0x%08x %s: %s" % (a, name, why))


# =============================================================================================================
# A. EGR delta pressure sensor (sensor channel 105) autozero chain
# =============================================================================================================
F("0x00018384", "cm848_checkProtectionEnableConditions", "cm848_updateEgrDeltaPressureAutozeroConditions",
  "Autozero conditions of the EGR delta pressure sensor (sensor channel 105): egr_delta_pressure_autozero_bypass_flag is 1 unless the "
  "coolant temperature source, the sensor fault status and the EGR valve position source are all 0; the precondition flag "
  "(egr_delta_pressure_autozero_precondition_flag, also read by cm848_updateEgrValvePositionCommandAndControlState, which then drives the "
  "valve command to 12800 or 0) is set while the bypass flag is 0, engine speed is 0, bit 0 of switch_input_state_bits[0] is clear and the "
  "coolant temperature is above egr_delta_pressure_autozero_coolant_temperature_threshold; the enable flag (first word of "
  "egr_delta_pressure_autozero_enable_flag) is the precondition AND, with boost_correction_alt_mode_cal = 0, the valve not closed and "
  "fuel_demand_quantity at or below egr_delta_pressure_autozero_turbocharger_speed_threshold, or, with it non-zero, the filtered intake "
  "manifold temperature above its threshold, the valve closed and fuel_demand_phase_state 0.",
  "code: three writes (bypass 0x40a658, precondition 0x40a65a, enable 0x40a652) and every compared cell sits at the same relative offset as the e2m "
  "cal block 0x01176E00 (C_EGR_AZ_Coolant_Tmptr_Thd +0x0c, C_EGR_AZ_IMT_Thd +0x0e, C_EGR_AZ_Turbo_Speed_Thd +0x10) and the e2m state block "
  "0x01176F00 (EGR_Delta_P_AZ_Bypass +0x08, _Precondition +0x0a, _Autozero_Enable +0x02) = RAM 0x40a650 + offset. Dump: bypass 1 (sensor status 2).")
F("0x000184f0", "cm848_checkFaultConditionThreshold", "cm848_updateEgrDeltaPressureAutozeroCompleteFlag",
  "Completion timer of the EGR delta pressure autozero (the ECM may delay power-down for it): while engine speed is 0 and bit 0 of "
  "switch_input_state_bits[0] is clear egr_delta_pressure_autozero_wait_counter rises by 10 per pass up to "
  "egr_delta_pressure_autozero_allowed_time (0 otherwise); egr_delta_pressure_autozero_complete_flag is 0 only while bit 0 of "
  "egr_delta_pressure_user_override_flags_cal is clear, the bypass flag is not 1 and the counter is below the allowed time, 1 otherwise.",
  "e2m C_EGR_Autozero_Allowed_Time (0x01176E00, 'time the autozero is permitted to delay powerdown') is the cell compared (0x40673c) and "
  "EGR_Delta_P_Autozero_Complete (0x01176F00, 'autozero complete and ECM powerdown can begin') is the flag written (0x40a650). Code: the counter step 10 "
  "per pass is the same 10 ms-count convention as the filter block's pass increment.")
F("0x00018904", "cm848_updateFaultStatusRegisters", "cm848_updateEgrDeltaPressureAutozero",
  "Autozero of the EGR delta pressure sensor: fills the offset filter block at 0x3fa720 (12 words and a pointer: sensor channel 105 value, tolerance, enable "
  "flag, enable time, fault time, error count clear flag, pass increment 10, filter state pointer) and runs cm848_updateAutozeroOffset on "
  "it; the learned zero offset goes to egr_delta_pressure_autozero_offset_cal (replaced by egr_delta_pressure_autozero_override_value "
  "while bit 0 of egr_delta_pressure_user_override_flags_cal is set); fault 719 (mask 0x8000 of fault_detected_bits_704_to_719, e2m "
  "EGR_Delta_P_Autozero_Error) follows the filter error status; egr_delta_pressure_autozeroed = sensor value - offset and "
  "egr_delta_pressure_combined_status = sensor channel 105 fault status | the autozero error status (8).",
  "code: the filter block fields line up with the e2m cal cells C_EGR_Delta_P_AZ_Enable_Time / _Fault_Time / _Fil_Cnst / _Tolerance / "
  "_Override_Value (0x01176E02-0x01176E0a = 0x40673e-0x406746) and the stored offset is the EEPROM word T_EGR_Delta_P_Autozero_Offset "
  "(0x01177000 = 0x3fdfb0). Fault 719 = e2m EGR_Delta_P_Autozero_Error (0x01103658 mask 0x8000, fault_detected_bits_704_to_719).")
F("0x00018a50", "cm848_selectFaultProtectionValue", "cm848_selectEgrDeltaPressure",
  "Selects the EGR delta pressure sensor output: egr_delta_pressure_state takes egr_delta_pressure_combined_status; when neither bit 8 "
  "(autozero error, fault 719) nor bit 2 (sensor fault status 2) is set egr_delta_pressure_sensor_output is the autozeroed value and "
  "egr_delta_pressure_sensor_source is 0, otherwise sensor_channel105_default_value and 2; egr_delta_pressure_sensor_output_snapshot is a copy.",
  "code: three stores and the two tests; e2m EGR_Delta_Press_State / _Source / EGR_Delta_Press at +0x12 / +0x0e / +0x0c of block 0x01176F00 = 0x40a662 / 0x40a65e / 0x40a65c.")
F("0x00018ac0", "cm848_processFaultProtection", "cm848_runEgrDeltaPressureAutozero",
  "Per-pass runner of the EGR delta pressure autozero: cm848_updateEgrDeltaPressureAutozeroConditions, "
  "cm848_updateEgrDeltaPressureAutozeroCompleteFlag, cm848_updateEgrDeltaPressureAutozero and cm848_selectEgrDeltaPressure in that order, "
  "then refreshes egr_delta_pressure_sensor_output_snapshot.", "code: the four calls.")
F("0x00018afc", "mpc555_initFaultProtectionVariables", "cm848_initializeEgrDeltaPressureAutozero",
  "Boot initialization of the EGR delta pressure autozero: clears the wait counter, the enable timer, the sample window counter and the error status, "
  "restores the error counter (egr_delta_pressure_autozero_fault_time while fault 719 is set, else 0), seeds the offset filter with the "
  "stored egr_delta_pressure_autozero_offset_cal and points it at the filter constant at 0x406742 (e2m C_EGR_Delta_P_AZ_Fil_Cnst), and "
  "starts the sensor output at the sensor value with source 0 (sensor status 0 or 1) or 2.", "code: the stores of this function.")
F("0x00018780", "cm848_processFaultStateWithFilter", "cm848_updateAutozeroOffset",
  "Generic autozero offset learner (called for the EGR delta pressure at 0x3fa720 and, from cm848_updateEgrValvePositionAutozero, for the EGR valve "
  "position): on the block (12 words and a pointer) {0 offset output, 1 sample, 2 tolerance, 3 enable, 4 enable timer, 5 enable time, 6 fault time, 7 error "
  "counter, 8 sample window counter, 9 error count clear flag, 10 error status, 11 pass increment, 12-13 filter state pointer} it counts the "
  "enable timer up to the enable time while enabled, compares |sample| with the tolerance, runs cm848_updateAutozeroErrorCounter and "
  "filters the sample into the offset (cm848_conditionalFirstOrderFilter) only when the enable time has passed and the sample is inside "
  "the tolerance.", "code: field use read from the function and from the two callers' block fills.")
F("0x0001860c", "cm848_processFaultIncrement", "cm848_updateAutozeroErrorCounter",
  "Debounce and error counter of the autozero offset learner (argument = the 11-word working block of cm848_updateAutozeroOffset): the sample "
  "window counter counts up to the pass increment (10) while the enable time has passed and, at its limit, says whether the sample was "
  "outside or inside the tolerance; the error counter rises by the increment up to the fault time while outside, falls by the decrement "
  "while inside, is held at 0 while the clear flag is set; the error status becomes 8 at the fault time and 0 again at 0.",
  "code: both counters and the status stores. Dump: window counter 10, fault time 9000, error status 0.")

# --- globals of the delta pressure chain ---------------------------------------------------------------------
G("0x003fa714", "fuel_enable_fault_count_working", "egr_delta_pressure_autozero_wait_counter",
  "code: written only by cm848_updateEgrDeltaPressureAutozeroCompleteFlag (+10 per pass up to the allowed time while engine speed is 0 and the key bit is clear, else 0) and cleared at boot.")
G("0x003fa71e", "governor_speed_output_limit", "egr_delta_pressure_combined_status",
  "code: written by cm848_updateEgrDeltaPressureAutozero as sensor channel 105 fault status | autozero error status (8), read only by cm848_selectEgrDeltaPressure, which copies it to egr_delta_pressure_state. Same combination as egr_valve_position_status. Dump 2 (sensor fault status 2).")
G("0x003fa720", "boost_pressure_fault_filter_state", "egr_delta_pressure_autozero_offset_filter_output",
  "code: word 0 of the autozero filter block: the learned zero offset (output of cm848_conditionalFirstOrderFilter), copied to egr_delta_pressure_autozero_offset_cal each pass. The block's other words are named egr_delta_pressure_autozero_* below.")
G("0x003fa722", "boost_sensor_raw_input", "egr_delta_pressure_autozero_sample",
  "code: word 1 of the filter block, written each pass with sensor_channel105_value; the sample whose |value| is compared with the tolerance and filtered into the offset.")
G("0x003fa724", "boost_fault_filter_param_b_working", "egr_delta_pressure_autozero_tolerance_working",
  "code: word 2 of the filter block = the calibrated tolerance (C_EGR_Delta_P_AZ_Tolerance, 0x406744); the autozero error counter rises while |sample| is at or above it. Dump 1288 (0x508).")
G("0x003fa726", "boost_decel_active_working", "egr_delta_pressure_autozero_enable_working",
  "code: word 3 of the filter block = the enable flag copied from egr_delta_pressure_autozero_enable_flag; 0 resets the enable timer.")
G("0x003fa72a", "boost_fault_filter_threshold_working", "egr_delta_pressure_autozero_enable_time_working",
  "code: word 5 of the filter block = egr_delta_pressure_autozero_enable_time (e2m C_EGR_Delta_P_AZ_Enable_Time), the enable timer limit before samples are filtered.")
G("0x003fa72c", "boost_fault_filter_hysteresis_working", "egr_delta_pressure_autozero_fault_time_working",
  "code: word 6 of the filter block = egr_delta_pressure_autozero_fault_time (e2m C_EGR_Delta_P_AZ_Fault_Time, 'confirmation time for autozero error detection'), the error counter limit; the status turns 8 at it. Dump 9000.")
G("0x003fa732", "cold_start_inhibit_working", "egr_delta_pressure_autozero_error_count_clear_flag",
  "code: word 9 of the filter block = a copy of cold_start_inhibit_cal (0x3fd7f0); non-zero holds the error counter at 0 (same role as egr_valve_position_autozero_error_count_clear_cal for the position autozero). cold_start_inhibit_cal itself has five users (see the note).")
G("0x003fa734", "boost_pressure_fault_status_flag", "egr_delta_pressure_autozero_error_status",
  "code: word 10 of the filter block: 8 at the autozero fault time, 0 at error counter 0; mask 0x8000 of fault_detected_bits_704_to_719 (fault 719, e2m EGR_Delta_P_Autozero_Error) follows it; OR-ed into egr_delta_pressure_combined_status.")
G("0x003fa736", "boost_fault_filter_count_cal", "egr_delta_pressure_autozero_pass_increment",
  "code: word 11 of the filter block: written with the constant 10 every pass by cm848_updateEgrDeltaPressureAutozero (counter increment / decrement and window limit). Not EEPROM or calibration data, so it has no _cal. Dump 10.")
G("0x003fa738", "boost_fault_filter_state_pointer", "egr_delta_pressure_autozero_offset_filter_pointer",
  "code: words 12-13 of the filter block: written each pass with &0x3fa716, the ema_filter_state_t (coefficient pointer + accumulator) of the offset filter.")
NG("0x003fa728", "egr_delta_pressure_autozero_enable_timer", "word",
   "code: xref sees only the boot clear (sth 0); word 4 of the filter block by pointer use in cm848_updateAutozeroOffset: counts up to the enable time while the enable flag is set, 0 otherwise.")
NG("0x003fa72e", "egr_delta_pressure_autozero_error_counter", "word",
   "code: word 7 of the filter block (pointer use in cm848_updateAutozeroErrorCounter); the boot initialization restores it to the fault time when fault 719 is set, else 0 (so the error survives a power cycle through the fault bit).")
NG("0x003fa730", "egr_delta_pressure_autozero_sample_window_counter", "word",
   "code: word 8 of the filter block (pointer use): counts to the pass increment 10 while enabled and tells in or out of tolerance. Boot initialization writes 0. Dump 10.")
G("0x003fa716", "", "egr_delta_pressure_autozero_offset_filter_state",
  "code: the ema_filter_state_t of the offset filter: coefficient pointer (boot initialization stores &0x406742 here) at 0x3fa716 and the Q16 accumulator at 0x3fa71a (boot initialization seeds it with the stored offset << 16); both are written with stw. Row type to ema_filter_state_t (see the type note); there is no other row in 0x3fa71a-0x3fa71d.",
  typ="ema_filter_state_t")
G("0x0040a650", "map_sensor_fault_mode_flag", "egr_delta_pressure_autozero_complete_flag",
  "code: written by cm848_updateEgrDeltaPressureAutozeroCompleteFlag; read by mpc555_processColdStartMainLoop (0x1c28c). e2m: EGR_Delta_P_Autozero_Complete (+0x00 of 0x01176F00, 'autozero complete and ECM powerdown can begin'). Dump 1.")
G("0x0040a652", "boost_decel_active_flag", "egr_delta_pressure_autozero_enable_flag",
  "code: written by cm848_updateEgrDeltaPressureAutozeroConditions, read by cm848_updateEgrDeltaPressureAutozero (copied into the filter block); every access is a halfword (sth / lhz) so the dword row is mis-sized (word; 0x40a654 has no access). e2m: EGR_Delta_P_Autozero_Enable (+0x02 of 0x01176F00).",
  typ="word")
G("0x0040a656", "boost_pressure_correction_snapshot", "egr_delta_pressure_sensor_output_snapshot",
  "code: a copy of egr_delta_pressure_sensor_output written twice per pass (cm848_selectEgrDeltaPressure, cm848_runEgrDeltaPressureAutozero); its only reader is the Bank 2 EGR cooler check (cm848_calculateEgrCoolerEfficiency). e2m: EGR_Delta_Pressure ('selected EGR delta pressure') is the word at +0x06 of 0x01176F00 = this cell.")
G("0x0040a658", "engine_running_flag", "egr_delta_pressure_autozero_bypass_flag",
  "code: 1 unless coolant_temperature_source, sensor_channel105_fault_status and egr_valve_position_source are all 0; its two users are cm848_updateEgrDeltaPressureAutozeroConditions (writer) and the completion timer (read: bypass means complete). It is not an engine-running flag. e2m: EGR_Delta_P_AZ_Bypass (+0x08 of 0x01176F00, 'autozero will not be attempted'). Dump 1.")
G("0x0040a65a", "boost_decel_mode_flag", "egr_delta_pressure_autozero_precondition_flag",
  "code: set while the bypass flag is 0, engine speed 0, key bit clear and the coolant temperature above the threshold; the EGR valve position command stage reads it (command 12800, or 0 when boost_correction_alt_mode_cal is non-zero). e2m: EGR_Delta_P_AZ_Precondition (+0x0a of 0x01176F00, 'autozero is being attempted'). Dump 0.")
G("0x0040a65c", "boost_pressure_correction_raw", "egr_delta_pressure_sensor_output",
  "code: the sensor chain's output: the autozeroed value, or sensor_channel105_default_value while the sensor status is 2 or fault 719 is set; read by cm848_calculateFuelFlowWithMode (which builds egr_delta_pressure), the Bank 2 sensor-valid logic and cm848_calibration_group22_load. e2m: EGR_Delta_Press (+0x0c of 0x01176F00).")
G("0x0040a65e", "fuel_demand_enable_state", "egr_delta_pressure_sensor_source",
  "code: 0 when the sensor output is the autozeroed value, 2 when the default is used (boot initialization: 0 for sensor status 0 or 1, 2 for status 2); read by cm848_calculateFuelFlowWithMode, the Bank 2 cooler check and the sensor-valid logic. e2m: EGR_Delta_Press_Source (+0x0e of 0x01176F00, 'source quality indicator'). Dump 2.")
G("0x0040a660", "sensor_channel105_pressure_diff", "egr_delta_pressure_autozeroed",
  "code: sensor_channel105_value - the learned zero offset (egr_delta_pressure_autozero_offset_cal, or the override value), written by cm848_updateEgrDeltaPressureAutozero and read by cm848_selectEgrDeltaPressure. e2m: EGR_Delta_Press_AP ('delta pressure after auto-zero', +0x10 of 0x01176F00).")
G("0x0040a662", "sensor_channel105_fault_combined", "egr_delta_pressure_state",
  "code: written (sth) only by cm848_selectEgrDeltaPressure from egr_delta_pressure_combined_status; the dword row is mis-sized: the second word (0x40a664) is written by cm848_updateEgrValvePositionAutozero (EGR_Valve_Position_Offset). e2m: EGR_Delta_Press_State (+0x12 of 0x01176F00). Retype to word. Dump (word) 2 (sensor status 2).",
  typ="word")
NG("0x0040a664", "egr_valve_position_autozero_offset", "word",
   "code: stored (sth) by cm848_updateEgrValvePositionAutozero: the learned EGR valve position zero offset; today the row is the label sensor_channel105_fault_combined+2 of a mis-sized dword. e2m: EGR_Valve_Position_Offset (+0x00 of the position block 0x01179D00, anchored at 0x40a664).")
DEL("0x0040a664", "sensor_channel105_fault_combined+2", "label of the second word of a mis-sized dword; replaced by the new word row egr_valve_position_autozero_offset.")
G("0x003fdfb0", "boost_pressure_correction_working", "egr_delta_pressure_autozero_offset_cal",
  "code: inside the EEPROM mirror (0x3fd482-0x3feec1): the learned zero offset, written every pass from the filter output (or the override value) and read at boot to seed the filter. e2m: T_EGR_Delta_P_Autozero_Offset (0x01177000, trim) is +0x00 of the block that anchors 0x3fdfb0.")
G("0x003fdfb2", "fuel_enable_fault_status_flags", "egr_delta_pressure_user_override_flags_cal",
  "code: inside the EEPROM mirror: bit 0 = use egr_delta_pressure_autozero_override_value instead of the learned offset (cm848_updateEgrDeltaPressureAutozero) and treat the autozero as complete (cm848_updateEgrDeltaPressureAutozeroCompleteFlag). e2m: T_EGR_User_Override / T_EGR_Delta_P_AZ_User_Override (0x01177002) = +0x02 of the same block.")
G("0x0040673c", "engine_fuel_enable_count_cal", "egr_delta_pressure_autozero_allowed_time",
  "code: the limit of the completion timer in cm848_updateEgrDeltaPressureAutozeroCompleteFlag (2 reads); ROM-to-RAM value, no _cal. e2m: C_EGR_Autozero_Allowed_Time (0x01176E00, 0.001 s) is the first cell of the block that anchors 0x40673c.")
G("0x0040673e", "boost_fault_filter_threshold_cal", "egr_delta_pressure_autozero_enable_time",
  "code: copied into the filter block as the enable time. e2m: C_EGR_Delta_P_AZ_Enable_Time (0x01176E02) = +0x02 of the block that anchors 0x40673c.")
G("0x00406740", "boost_fault_filter_hysteresis_cal", "egr_delta_pressure_autozero_fault_time",
  "code: copied into the filter block as the fault time and used to restore the error counter at boot. e2m: C_EGR_Delta_P_AZ_Fault_Time (0x01176E04). Dump 9000.")
G("0x00406744", "boost_fault_filter_param_b_cal", "egr_delta_pressure_autozero_tolerance",
  "code: copied into the filter block as the tolerance. e2m: C_EGR_Delta_P_AZ_Tolerance (0x01176E08). Dump 1288.")
G("0x00406746", "boost_fault_correction_override_cal", "egr_delta_pressure_autozero_override_value",
  "code: replaces the learned offset while bit 0 of egr_delta_pressure_user_override_flags_cal is set. e2m: C_EGR_Delta_P_AZ_Override_Value (0x01176E0a).")
G("0x00406748", "boost_decel_input_threshold_cal", "egr_delta_pressure_autozero_coolant_temperature_threshold",
  "code: coolant_temperature_selected must be above it for the precondition. e2m: C_EGR_AZ_Coolant_Tmptr_Thd (0x01176E0c, 1/64 degree F).")
G("0x0040674a", "boost_decel_offset_threshold_cal", "egr_delta_pressure_autozero_intake_manifold_temperature_threshold",
  "code: the filtered intake manifold temperature must be above it for the enable flag in the alternate mode. e2m: C_EGR_AZ_IMT_Thd (0x01176E0e, 'min intake manifold temperature required for the enable').")
G("0x0040674c", "boost_mode_fuel_qty_threshold_cal", "egr_delta_pressure_autozero_turbocharger_speed_threshold",
  "code: fuel_demand_quantity must be at or below it (valve not closed) for the enable flag. e2m: C_EGR_AZ_Turbo_Speed_Thd (0x01176E10, 'max filtered turbo speed', KRPM 0.008) is the cell at this offset; fuel_demand_quantity is therefore the filtered turbocharger speed (strong lead, see the note). Dump 1500 x 0.008 = 12 KRPM.")
G("0x003ff734", "boost_fuel_correction_threshold", "egr_valve_maximum_opening_delta_pressure",
  "code: cm848_limitChargeManagerCommands passes the EGR fraction command only while the valve is not closed or egr_delta_pressure is below it. e2m: C_CHL_Max_Opening_Delta_P (0x01169A18, 'maximum EGR delta-P permitted when initially opening the EGR valve', IN_HG) = +0x18 of the block that anchors 0x3ff71c. Dump 3143.")
G("0x0040a628", "boost_fuel_correction", "egr_delta_pressure",
  "code: written only by cm848_calculateFuelFlowWithMode: the EGR delta pressure sensor output (alternate mode 0) or (boost_pressure_current_raw - boost_pressure_baseline_cal) - map_fuel_correction_factor (boost_correction_alt_mode_cal non-zero, dump 1); read by the charge flow delta pressure derate, the EGR valve maximum opening limit, the assist / EGR controller preset lift table (delta pressure axis) and the EGR valve over-temperature inhibit. e2m: those four consumers' calibrations are C_CHL_Delta_P_Drt_Limit, C_CHL_Max_Opening_Delta_P, C_EAC_Preset_Delta_P_Axis, C_EGA_Delta_Press_Threshold (all IN_HG / PSI at 0.0159 inHg per count).")
G("0x0040a62a", "boost_fuel_correction_state", "egr_delta_pressure_source",
  "code: written last by cm848_calculateFuelFlowWithMode from fuel_demand_enable_state_cached: the sensor source (alternate mode 0) or the combined state of the two other pressure inputs (0 / 1 / 2); read by the EGR valve over-temperature inhibit. Dump 0.")
G("0x0040a62c", "boost_fuel_correction_neg", "egr_delta_pressure_negated",
  "code: = -egr_delta_pressure, written by cm848_calculateFuelFlowWithMode, read by cm848_calculateBoostPressureOffset. Dump 65451 (-85).")
G("0x003fa776", "boost_correction_threshold_exceeded_flag", "egr_valve_delta_pressure_over_temperature_threshold_reached_flag",
  "code: written by cm848_updateEgrValveOverTemperatureFault: the filtered egr_delta_pressure is at or above egr_valve_over_temperature_delta_pressure_threshold; resets the inhibit counter. e2m: C_EGA_Delta_Press_Threshold ('valve over-temperature is not logged above this delta pressure').")
G("0x003fa778", "boost_fuel_correction_active_flag", "egr_valve_over_temperature_timer_inhibit_flag",
  "code: set when coolant_temperature_source is non-zero or egr_delta_pressure_source is non-zero; holds the over-temperature inhibit counter at 0 (written and read only by cm848_updateEgrValveOverTemperatureFault).")
G("0x003fa750", "", "egr_valve_delta_pressure_filter_state",
  "code: the ema_filter_state_t of the delta pressure filter in cm848_updateEgrValveOverTemperatureFault: cm848_initializeEgrValveMotorThermalModel stores (stw, instruction scan) the coefficient pointer at 0x3fa750 - it targets egr_valve_motor_winding_temperature_filter_coefficient, the cell the winding temperature filter uses too - and seeds the accumulator at 0x3fa754 (stw; no row there) with egr_delta_pressure << 16 (dump high word 85 = the delta pressure). Row type to ema_filter_state_t.",
  typ="ema_filter_state_t")
G("0x003fa790", "j1939_handler_param_table_pointer", "egr_valve_derivative_filter_state",
  "code: the ema_filter_state_t of the EGR valve derivative (error change) filter: boot initialization cm848_initializeEgrValvePositionControlLoop stores the coefficient pointer (&0x4067f2, C_EGA_Der_Dtime_Cnst) here and a dword (stw) at 0x3fa794; nothing to do with J1939. Row type to ema_filter_state_t and delete the 0x3fa794 row.",
  typ="ema_filter_state_t")
DEL("0x003fa794", "j1939_handler_param_table_index", "this word is the accumulator half of the ema_filter_state_t now at 0x3fa790 (egr_valve_derivative_filter_state); it is written with stw at boot.")

# =============================================================================================================
# A'. EGR cooler fouling monitor (Bank 2): the 'boost_correction_*' words of the lead
# =============================================================================================================
F("0x005033a0", "fuel_boostCorrection_enableCheck_trimCalc", "cm848_calculateEgrCoolerEfficiency",
  "EGR cooler effectiveness check (e2m EGR_Cooler_* / T_EGR_Cooler_Fouling_Enable): egr_cooler_fouling_precondition_flag is set when the "
  "alternate mode (boost_correction_alt_mode_cal) is non-zero, the coolant temperature source is 0, no block-mode or state flag is set and "
  "the EGR mass flow, the coolant temperature, the valve position and the EGR delta pressure are at or above their thresholds with "
  "egr_valve_position_source and egr_delta_pressure_sensor_source 0 and fault 725 clear; egr_cooler_efficiency (0-10000) = (hot-side "
  "temperature boost_fuel_input_value x 32 - throttle_trim_lookup_input) x 10000 / (hot-side temperature - coolant temperature) and "
  "egr_cooler_efficiency_threshold = egr_mass_flow_delayed_filtered x egr_cooler_efficiency_threshold_gain / 1280 + "
  "egr_cooler_efficiency_threshold_offset (0-10000); then cm848_updateEgrCoolerFoulingFaultCounter.",
  "code: the formula is a heat exchanger effectiveness, not a boost correction. e2m: RAM 0x40a442 + offset matches block 0x011A5700 (CHH_CBO_Off +0, "
  "CHH_EGR_Cooler_Fouled +2, CHH_EGR_System_Failure +4, EGR_Cooler_Eff +6, EGR_Cooler_Eff_Thd +8, EGR_Cooler_Fouling_Fault_Count +0x0a, "
  "EGR_Cooler_Fouling_Precondition +0x0c) and the cal cells 0x4051e8-0x4051f0 match C_EGR_Cooler_Eff_Thd_Gain / _Offset / _Fouling_Clt_Thd / "
  "_Fault_Thd / _Flow_Thd (0x011A5600-0x011A5608); the enable bit 0x2000 of 0x3fd5c2 is T_EGR_Cooler_Fouling_Enable (0x01106B28 mask 2000).")
F("0x005031fc", "governor_adjustment_counter_update", "cm848_updateEgrCoolerFoulingFaultCounter",
  "EGR cooler fouling fault counter: the precondition must hold for 10 passes (egr_cooler_fouling_precondition_dwell_counter); then "
  "egr_cooler_fouling_fault_counter rises by 1 per pass up to egr_cooler_fouling_fault_time_threshold while egr_cooler_efficiency is below "
  "egr_cooler_efficiency_threshold and falls by 1 while it is at or above it; the counter is held at 0 while bit 0x2000 of "
  "feature_enable_flags_cal is clear or cold_start_inhibit_cal is non-zero; egr_cooler_fouled_flag (second word of "
  "fuel_blend_correction_inhibit_flag) is set at the maximum and cleared at 0.",
  "code: the three counters and the two comparisons. e2m: EGR_Cooler_Fouling_Fault_Count (0x011A570a, 0.1 s) and CHH_EGR_Cooler_Fouled (0x011A5702); the dump has the feature bit clear (0x8488), so the monitor is off in this calibration.")
F("0x00503604", "cm848_auxiliary_periodic", "cm848_updateEgrSystemHealthFlags",
  "Runs cm848_calculateEgrCoolerEfficiency, then sets egr_system_failure_flag when any EGR input or actuator state is bad (fuel_demand_mode_index or "
  "fuel_demand_droop_state 2, fuel_demand_phase_state non-zero, egr_delta_pressure_sensor_source or egr_valve_position_source non-zero, "
  "faults 726 / 727 / 728 of the EGR valve, or the cooler fouled) and the first word of fuel_blend_correction_inhibit_flag when either of "
  "the two state words is 1.",
  "e2m: CHH_EGR_System_Failure ('EGR system failure indicator', +4) and CHH_CBO_Off (+0) of block 0x011A5700 are the words written (0x40a446, 0x40a442). Code: the listed conditions are all EGR inputs, the EGR valve faults 726-728 and the cooler flag.")
G("0x0040a448", "boost_correction_throttle_trim_ratio", "egr_cooler_efficiency",
  "code: 0-10000, written by cm848_calculateEgrCoolerEfficiency as a temperature ratio (hot side - outlet) / (hot side - coolant); compared with the threshold by the fouling counter. e2m: EGR_Cooler_Eff (+0x06 of 0x011A5700 = 0x40a448, 'current assessment of EGR cooler effectiveness'). Dump 0.")
G("0x0040a44a", "boost_correction_fuel_ema_ratio", "egr_cooler_efficiency_threshold",
  "code: 0-10000, egr_mass_flow_delayed_filtered x gain / 1280 + offset clamped 0-10000. e2m: EGR_Cooler_Eff_Thd (+0x08, 'effectiveness threshold below which EGR is considered fouled') with C_EGR_Cooler_Eff_Thd_Gain / _Offset. Dump 5000.")
G("0x0040a44c", "boost_correction_step_counter", "egr_cooler_fouling_fault_counter",
  "code: counted by cm848_updateEgrCoolerFoulingFaultCounter, limit egr_cooler_fouling_fault_time_threshold (dump 300). e2m: EGR_Cooler_Fouling_Fault_Count (+0x0a of 0x011A5700, 0.1 s).")
G("0x0040a44e", "boost_correction_eligible_flag", "egr_cooler_fouling_precondition_flag",
  "code: written by cm848_calculateEgrCoolerEfficiency, read by the fouling counter. e2m: EGR_Cooler_Fouling_Precondition (+0x0c of 0x011A5700, 'fouling algorithm activation conditions are satisfied').")
G("0x003fb9fe", "boost_corr_eligible_dwell_count", "egr_cooler_fouling_precondition_dwell_counter",
  "code: counts passes of the precondition up to 10 (cm848_updateEgrCoolerFoulingFaultCounter); the efficiency comparison is only used at 10.")
G("0x004051e8", "boost_correction_fuel_ema_scale", "egr_cooler_efficiency_threshold_gain",
  "code: multiplies the delayed filtered EGR mass flow (/ 1280); signed (dump 62936 = -2600). e2m: C_EGR_Cooler_Eff_Thd_Gain (0x011A5600, +0x00 of the block that anchors 0x4051e8).")
NG("0x004051ea", "egr_cooler_efficiency_threshold_offset", "word",
   "code: xref_addr.py says word (1 read / 0 writes): added to the flow term; dump 5000 (50 percent). e2m: C_EGR_Cooler_Eff_Thd_Offset (0x011A5602).")
NG("0x004051ec", "egr_cooler_fouling_coolant_temperature_threshold", "word",
   "code: xref_addr.py says word (1 read / 0 writes): the coolant temperature must be at or above it; dump 12160 = 190 degrees F at 1/64. e2m: C_EGR_Cooler_Fouling_Clt_Thd (0x011A5604, 'temperature below which the algorithm is disabled').")
G("0x004051ee", "boost_correction_step_count_max", "egr_cooler_fouling_fault_time_threshold",
  "code: upper limit of the fouling counter (fouled flag set at it). Dump 300. e2m: C_EGR_Cooler_Fouling_Fault_Thd (0x011A5606, 0.1 s).")
NG("0x004051f0", "egr_cooler_fouling_flow_threshold", "word",
   "code: xref_addr.py says word (1 read / 0 writes): minimum EGR mass flow (egr_mass_flow_delayed_filtered, 1/128 lb/min); dump 128 = 1 lb/min. e2m: C_EGR_Cooler_Fouling_Flow_Thd (0x011A5608).")
NG("0x004051f2", "egr_cooler_fouling_delta_pressure_threshold", "word",
   "code: xref_addr.py says word (1 read / 0 writes): the selected EGR delta pressure snapshot must be at or above it; dump 63 (1 inHg). e2m: not in the .12 parameter list (the cell after C_EGR_Cooler_Fouling_Flow_Thd).")
NG("0x004051f4", "egr_cooler_fouling_valve_position_threshold", "word",
   "code: xref_addr.py says word (1 read / 0 writes): egr_valve_position (12800 = 100 percent) must be at or above it; dump 1920 = 15 percent. e2m: not in the .12 parameter list.")
G("0x003fd5c2", "cold_start_feature_flags", "feature_enable_flags_cal",
  "code: inside the EEPROM mirror; six functions test the masks 0x08, 0x20, 0x80, 0x200 and 0x2000. e2m: the same masks of the engineering trim word 0x01106B28 are CWG_Monitor_Enable (0008), Alpha_Altitude_Derate_Override_Enable (0020), COT_Estimation_Enable (0080), ESP_Smart_Torque_Enable / T_EMO_Condensation_AECD_Enable (0200) and T_EGR_Cooler_Fouling_Enable (2000; the .12 file lists T_VGT_Pneumatic_Control_Enable at the same mask, a variant bit); nothing here is cold start. Dump 0x8488 (bits 0x8000 virtual sensors, 0x400 swingvane, 0x80 COT estimation, 0x08 wastegate monitor; 0x2000 clear).")
G("0x0040a446", "fuel_demand_active_state_flag", "egr_system_failure_flag",
  "code: written by cm848_updateEgrSystemHealthFlags: 1 when any of the EGR delta pressure / position sources, the valve faults 726-728, the cooler-fouled flag or the two state words says failure; read by cm848_updateSensorValidationFlags (0x509a7c). e2m: CHH_EGR_System_Failure (+0x04 of 0x011A5700 = 0x40a446). Dump 1 (delta pressure source 2).")

# =============================================================================================================
# A''. compressor outlet temperature (input of the charge flow derate)
# =============================================================================================================
F("0x00017d54", "cm848_selectFuelFlowMode", "cm848_selectCompressorOutletTemperature",
  "Selects compressor_outlet_temperature: the calibrated default (fuel_flow_rate_default_cal) when the compressor outlet temperature estimation is disabled (bit 0x80 of feature_enable_flags_cal clear) or both source states are 2, otherwise cm848_calculateFuelFlowRate (the estimate); sets the state code 0 / 1 / 2 (fuel_timing_state_code).",
  "code: the 0x80 test of the feature word; e2m COT_Estimation_Enable / T_TPE_COT_Estimation_Enable (0x01106B28 mask 0080); the dump has the bit set and the value 1662 / 64 = 26 degrees F, the CHL limit cell holds 14080 = 220 degrees F.")
F("0x00017b84", "cm848_calculateFuelFlowRate", "cm848_estimateCompressorOutletTemperature",
  "Estimates the compressor outlet temperature (1/64 degree F) from a compressor map: the corrected fresh air mass flow (boost_pressure_state fresh_air_mass_flow_filtered x a table factor of the ambient air temperature) and the corrected turbocharger speed (fuel_demand_quantity x 0x106 / 10000, divided by the same factor) index a dual-axis table, whose output scales the ambient air temperature in Rankine (ambient_air_temperature_selected + 0x7300), converted back, floored and filtered by an exponential moving average; returns the filtered value.",
  "code: the whole function was read: the two corrected inputs, the dual-axis lookup, the Rankine scaling and the EMA; the only caller is cm848_selectCompressorOutletTemperature. The corrected speed input is fuel_demand_quantity, which supports its turbocharger speed reading (lead).")
G("0x0040a616", "fuel_flow_rate", "compressor_outlet_temperature",
  "code: 1/64 degree F: written by cm848_selectCompressorOutletTemperature (estimate or default), read by the charge flow COT derate (ratio to the limit cell at 14080 = 220 degrees F), the wastegate duty request and the Bank 2 governor_adjustment_compare. e2m: COT = compressor outlet temperature (CHL_COT_Drt_* / COT_Estimation_Enable). Not a fuel flow. Dump 1662.")

# =============================================================================================================
# B. Charge manager: limiters (CHL), system errors (CSE), EGR / assist controller (EAC)
# =============================================================================================================
F("0x000108a4", "cm848_calculateTurboRatioA", "cm848_calculateChargeFlowCompressorOutletTemperatureDerate",
  "Charge flow derate for high compressor outlet temperature: ratio = compressor_outlet_temperature / the COT limit (Q15), looked up and scaled by the COT derate gain, capped at the maximum, filtered into charge_flow_compressor_outlet_temperature_derate_offset (-6400 = no derate below the ratio threshold) and flagged in charge_flow_compressor_outlet_temperature_derate_active_flag.",
  "code: the ratio, gain, clamp and filter chain. e2m: CHL_COT_Drt_Active / _Offset (0x01169B04 / 06) = 0x40a37c / 0x40a37e; the cells 0x3ff71c-0x3ff722 are C_CHL_COT_Drt_Fil_Cnst / _Gain / _Limit / _Ratio.")
F("0x000109c8", "cm848_calculateTurboRatioB", "cm848_calculateChargeFlowDeltaPressureDerate",
  "Charge flow derate for high EGR delta pressure: ratio = egr_delta_pressure / the delta pressure limit (Q15), looked up and scaled by the gain, capped at the maximum, filtered into charge_flow_delta_pressure_derate_offset and flagged in charge_flow_delta_pressure_derate_active_flag.",
  "code: the same chain as the COT derate on egr_delta_pressure. e2m: CHL_Delta_P_Drt_Active / _Offset (0x01169B0a / 0c) = 0x40a382 / 0x40a384; C_CHL_Delta_P_Drt_Limit (IN_HG) = 0x3ff728.")
F("0x00010b04", "cm848_calculateTurboRatios", "cm848_calculateChargeFlowDerates",
  "Runs the compressor outlet temperature derate and the delta pressure derate.", "code: the two calls.")
F("0x00010b28", "cm848_calculateTurboBlendOutput", "cm848_limitChargeManagerCommands",
  "Charge manager command limiters (e2m CHL): sets egr_fraction_command_above_on_threshold_flag with hysteresis (on at egr_fraction_on_threshold, off at egr_fraction_off_threshold); takes the larger of the turbocharger speed and the COT derate offsets (only the COT one while the throttle_rate_filter_active_flag_cal trim is non-zero), floors it at -6400 while the EGR fraction is off and otherwise also takes the larger of it and the delta pressure offset, and when a derate flag is active limits the mass charge flow command to charge_mass_flow_filtered - 2 x that offset into mass_charge_flow_limited_command (charge_flow_derate_active_flag when it limited); passes egr_fraction_combustion_command only while the EGR fraction is on and the valve is open or egr_delta_pressure is below egr_valve_maximum_opening_delta_pressure, slew-limited by egr_fraction_slew_up_rate / egr_fraction_slew_down_rate, into egr_fraction_limited_command.",
  "code: the function. e2m: CHL_MCF_Cmd, CHL_EGR_Frac_Cmd, CHL_Derate_Is_Active, CHL_EGR_Frac_Cmd_With_Shutoff are +0x00 / +0x02 / +0x0e / +0x14 of 0x01169B00 = 0x40a378 / 0x40a37a / 0x40a386 / 0x40a38c; the cells are C_CHL_EGR_Frac_Thd_On / _Off, C_CHL_EGR_Slew_Up_Rate / _Down_Rate, C_CHL_Max_Opening_Delta_P at 0x3ff734-0x3ff73c.")
F("0x00010d3c", "cm848_calculateTurboRatioWithMode", "cm848_calculateChargeFlowTurbochargerSpeedDerate",
  "Charge flow derate for high turbocharger speed: the limit is charge_flow_turbocharger_speed_derate_base_limit (the backup limit when boost_control_mode is 1) x a barometric pressure factor into charge_flow_turbocharger_speed_derate_limit; ratio = fuel_demand_quantity / limit (Q15), looked up, scaled, capped and filtered into charge_flow_turbocharger_speed_derate_offset; then runs cm848_limitChargeManagerCommands.",
  "code: the function. e2m: CHL_Turbo_Drt_Limit (+0x08 = 0x40a380), CHL_Turbo_Speed_Drt_Active / _Offset (+0x10 / +0x12) and C_CHL_Turbo_Drt_Backup_Limit (0x3ff73e), C_CHL_Turbo_Drt_AAP_Axis (the barometric table).")
F("0x00010ed0", "cm848_initTurboRatioVariables", "cm848_initializeChargeManagerLimiters",
  "Boot initialization of the charge manager limiters: clears the three derate offsets and the EGR fraction hysteresis flag, sets the interpolation states and points the three derate filters at their constants (0x3ff71c, 0x3ff724, 0x3ff72c).", "code: the stores.")
F("0x00011290", "cm848_processLoadAdjustment", "cm848_calculateChargeSystemErrors",
  "Charge system errors (e2m CSE): charge_system_mass_charge_flow_error = (mass_charge_flow_limited_command - charge_mass_flow_filtered) / 2, charge_system_egr_fraction_error = egr_fraction_limited_command - egr_fraction_actual (charge_system_egr_fraction_error_adjusted is that error, 0 while the commanded fraction is at or below egr_fraction_off_threshold), then the adjusted mass flow error, the transform angle and the transformed errors.",
  "code: the function. e2m: CSE_MCF_Error, CSE_EGR_Frac_Error, CSE_EGR_Frac_Adj_Error are +0x04 / +0x06 / +0x0e of 0x01169E00 = 0x40a392 / 0x40a394 / 0x40a39c.")
F("0x00010f68", "cm848_calculateLoadBasedAdjustment", "cm848_calculateChargeSystemAdjustedMassChargeFlowError",
  "Adjusted mass charge flow error: charge_system_aggressiveness_gain_adjusted is a gain (charge_system_aggressiveness_gain_scale x fuel_limit_ratio_compensated_reference >> 13, with a hysteresis flag between two thresholds, else 0), charge_system_transient_gain_adjusted a table gain on the mass charge flow error; charge_system_mass_charge_flow_error_adjusted = (both gains) x error >> 13 limited to +-12800.",
  "e2m: CSE_Aggressiveness_Gain_Adj, CSE_Transient_Gain_Adj, CSE_MCF_Adj_Error (+0x0c / +0x12 / +0x10 of 0x01169E00 = 0x40a39a / 0x40a3a0 / 0x40a39e). Code: the products and the clamp.")
F("0x000110bc", "cm848_lookupRpmLoadTable", "cm848_selectChargeSystemTransformAngle",
  "Selects the charge system transform angle: dual-axis lookup on engine speed and total_injection_quantity_for_air_handling (charge_system_transform_angle_scheduled), replaced by the override value when throttle_rate_override_flag is 1, then limited to the lower and upper angle limits; returns it.",
  "e2m: CSE_Scheduled_Xform_Angle (+0x08) and CSE_Xform_Angle (+0x0a) of 0x01169E00 = 0x40a396 / 0x40a398 ('after overrides and limits'). Code: the lookup, the override and the clamp.")
F("0x00011170", "cm848_calculateLoadAdjustmentFactors", "cm848_transformChargeSystemErrors",
  "Rotates the adjusted charge system errors by the transform angle: the half-angle cosine table is read at the angle and at 0xb400 minus the angle, charge_system_error_for_egr_valve = cos x mass flow error - sin x EGR fraction error / 1.28 and charge_system_error_for_turbocharger = sin x mass flow error + cos x EGR fraction error / 1.28.",
  "code: the two lookups and the products. e2m: CSE_Xform_Error_1 ('transformed for EGR valve control') and _2 ('for turbocharger control') are +0x00 / +0x02 of 0x01169E00 = 0x40a38e / 0x40a390.")
F("0x00011324", "mpc555_initLoadAdjustmentTableSizes", "cm848_initializeChargeSystemErrorTables",
  "Boot initialization of the charge system error table interpolation states (size 2).", "code: the stores.")
F("0x0001134c", "cm848_calculateLoadGainValues", "cm848_calculateEgrAssistControllerGains",
  "Gain scheduling of the EGR / assist controller: egr_assist_controller_adjusted_proportional_gain = a table on charge_system_mass_charge_flow_error x egr_assist_controller_proportional_gain >> 12 (capped 0x7fff), egr_assist_controller_adjusted_integral_gain = a table on charge_system_error_for_egr_valve x egr_assist_controller_integral_gain >> 12.",
  "code: the two lookups and scales. e2m: EAC_Adjusted_P_Gain (+0x12) and EAC_Adjusted_I_Gain (+0x1a) of 0x01169F00 = 0x40a3b4 / 0x40a3bc; C_EAC_Trans_MCF_Axis / C_EAC_I_Gain_Error_Axis are the table axes.")
F("0x00011410", "cm848_selectLoadAdjustmentLimits", "cm848_selectEgrAssistControllerLimits",
  "Selects the position limits of the EGR / assist controller: egr_fraction_limited_command_above_on_threshold_flag (hysteresis on the EGR fraction command), the assist throttle low limit, the EGR valve low limit (the calibrated pair of the on or off state), copies of the high limits, and egr_assist_controller_preset_active_flag (EGR off and the preset enabled).",
  "e2m: EAC_Asst_Throt_High / _Low, EAC_EGR_Valve_High / _Low (+0x02 / +0x04 / +0x08 / +0x0a of 0x01169F00 = 0x40a3a4 / 0x40a3a6 / 0x40a3aa / 0x40a3ac). Code: the selections.")
F("0x000114dc", "cm848_calculateLoadCompensation", "cm848_calculateEgrAssistControllerPreset",
  "Preset of the EGR / assist controller integrator: while the preset is active egr_assist_controller_preset_lift is a dual-axis table on the EGR mass flow (egr_fraction_limited_command x charge_mass_flow_filtered >> 13) and egr_delta_pressure; the preset is the EGR valve upper limit minus lift x the preset gain >> 12, kept between the lower and upper limits.",
  "e2m: EAC_Preset (+0x14) and EAC_Preset_Lift (+0x16) of 0x01169F00 = 0x40a3b6 / 0x40a3b8; C_EAC_Preset_EGR_Flow_Axis (LB/MIN), C_EAC_Preset_Delta_P_Axis (IN_HG), C_EAC_Preset_Gain. Code: the table axes and the formula.")
F("0x000115cc", "cm848_calculateLoadIntegral", "cm848_calculateEgrAssistControllerOutput",
  "PI controller of the staged EGR / assist output: proportional term = charge_system_error_for_egr_valve x the adjusted proportional gain >> 10 (+-12800), integral accumulator (Q16) += (error x the adjusted integral gain >> 10) x 655 between the integral limits, preset while the preset is active or the controller is overridden; the unstaged output = feedforward (the override value) + proportional + integral; the assist throttle command takes it within its limits, the excess x the staging gain plus the EGR valve lower limit gives the staged EGR position, and egr_assist_controller_egr_valve_command = EGR valve upper limit - that position (limited), the EGR valve position command (12800 = 100 percent).",
  "code: the function. e2m: EAC_Asst_Throt_Cmd, EAC_EGR_Valve_Cmd, EAC_Feedforward_Term, EAC_Integral_Term, EAC_Proportional_Term (+0x00 / +0x06 / +0x0c / +0x0e / +0x10 of 0x01169F00 = 0x40a3a2 ... 0x40a3b2); the cal cells 0x3ffc82-0x3ffc96 are C_EAC_* in order. The code's 'd gain' multiplies the error (proportional) and its 'p gain' feeds the integrator.")
F("0x000118f8", "cm848_processLoadGainCalculations", "cm848_runEgrAssistController",
  "Runs the EGR / assist controller: gains, limits, preset, output.", "code: the four calls.")
F("0x00011924", "mpc555_initLoadGainVariables", "cm848_initializeEgrAssistController",
  "Boot initialization of the EGR / assist controller: clears the assist command, the EGR valve command, the preset lift, the unstaged output, the staged position, the integral accumulator and the limit hysteresis flag; sets the table interpolation states.", "code: the stores.")

# --- CHL state / calibration ------------------------------------------------------------------------------
G("0x0040a37a", "fuel_demand_rate_limiter", "egr_fraction_limited_command",
  "code: the slew-limited EGR fraction command written by cm848_limitChargeManagerCommands; read by the charge system errors, the EGR / assist limit selection and the preset (EGR mass flow). e2m: CHL_EGR_Frac_Cmd ('charge manager demanded EGR fraction after limiters', +0x02 of 0x01169B00). Dump 0.")
G("0x0040a37c", "throttle_rate_threshold_a_flag", "charge_flow_compressor_outlet_temperature_derate_active_flag",
  "code: set by the COT derate when the ratio is at or above the ratio threshold. e2m: CHL_COT_Drt_Active (+0x04 of 0x01169B00).")
G("0x0040a37e", "throttle_rate_filter_output_c", "charge_flow_compressor_outlet_temperature_derate_offset",
  "code: the filtered COT derate offset (-6400 when below the ratio threshold, then no derate). e2m: CHL_COT_Drt_Offset (+0x06 of 0x01169B00, lb/min).")
G("0x0040a380", "fuel_pressure_demand_reference", "charge_flow_turbocharger_speed_derate_limit",
  "code: written by cm848_calculateChargeFlowTurbochargerSpeedDerate: the base (or backup) limit x the barometric factor >> 15. Not a fuel pressure. e2m: CHL_Turbo_Drt_Limit (+0x08 of 0x01169B00, KRPM, 'turbo speed limit for calculating the charge flow derate').")
G("0x0040a382", "throttle_rate_threshold_b_flag", "charge_flow_delta_pressure_derate_active_flag",
  "code: set by the delta pressure derate at or above its ratio threshold. e2m: CHL_Delta_P_Drt_Active (+0x0a of 0x01169B00).")
G("0x0040a384", "throttle_rate_filter_output_b", "charge_flow_delta_pressure_derate_offset",
  "code: the filtered delta pressure derate offset. e2m: CHL_Delta_P_Drt_Offset (+0x0c of 0x01169B00).")
G("0x0040a386", "fuel_demand_rate_below_min_flag", "charge_flow_derate_active_flag",
  "code: 1 when a derate lowered the mass charge flow command below the selected command. e2m: CHL_Derate_Is_Active (+0x0e of 0x01169B00).")
G("0x0040a388", "throttle_rate_threshold_c_flag", "charge_flow_turbocharger_speed_derate_active_flag",
  "code: set by the turbocharger speed derate at or above its ratio threshold. e2m: CHL_Turbo_Speed_Drt_Active (+0x10 of 0x01169B00).")
G("0x0040a38a", "throttle_rate_filter_output_a", "charge_flow_turbocharger_speed_derate_offset",
  "code: the filtered turbocharger speed derate offset (0 while throttle_rate_filter_reset_flag is set). e2m: CHL_Turbo_Speed_Drt_Offset (+0x12 of 0x01169B00).")
G("0x0040a38c", "fuel_demand_rate_input", "egr_fraction_limited_command_with_shutoff",
  "code: egr_fraction_combustion_command while the EGR fraction is on and the valve may open, else 0; the input of the slew limiter. e2m: CHL_EGR_Frac_Cmd_With_Shutoff (+0x14 of 0x01169B00, 'CBL_EGR_Frac_Cmd with CHL EGR off command imposed').")
G("0x003fa12e", "fuel_demand_high_limit_exceeded_flag", "egr_fraction_command_above_on_threshold_flag",
  "code: hysteresis flag of cm848_limitChargeManagerCommands on egr_fraction_combustion_command: set at or above egr_fraction_on_threshold, cleared at or below egr_fraction_off_threshold. e2m: C_CHL_EGR_Frac_Thd_On / _Off.")
G("0x003ff71e", "lookup_table_scale_factor_a_cal", "charge_flow_compressor_outlet_temperature_derate_gain",
  "code: multiplies the table output (>> 14) in the COT derate; ROM-to-RAM value, no _cal. e2m: C_CHL_COT_Drt_Gain (0x01169A02) is +0x02 of the block that anchors 0x3ff71c.")
G("0x003ff720", "fuel_flow_rate_reference", "charge_flow_compressor_outlet_temperature_derate_limit",
  "code: the divisor of compressor_outlet_temperature; dump 14080 = 220 degrees F at 1/64. e2m: C_CHL_COT_Drt_Limit (0x01169A04, DEG_F).")
G("0x003ff722", "throttle_rate_threshold_c_cal", "charge_flow_compressor_outlet_temperature_derate_ratio",
  "code: the ratio (Q15) below which the COT derate does nothing. e2m: C_CHL_COT_Drt_Ratio (0x01169A06).")
G("0x003ff726", "lookup_table_scale_factor_b_cal", "charge_flow_delta_pressure_derate_gain",
  "code: gain of the delta pressure derate (>> 14). e2m: C_CHL_Delta_P_Drt_Gain (0x01169A0a).")
G("0x003ff728", "throttle_rate_divisor_cal", "charge_flow_delta_pressure_derate_limit",
  "code: the divisor of egr_delta_pressure in the delta pressure derate; dump 1886. e2m: C_CHL_Delta_P_Drt_Limit (0x01169A0c, IN_HG).")
G("0x003ff72a", "throttle_rate_threshold_b_cal", "charge_flow_delta_pressure_derate_ratio",
  "code: ratio below which the delta pressure derate does nothing. e2m: C_CHL_Delta_P_Drt_Ratio (0x01169A0e).")
G("0x003ff72e", "lookup_table_scale_factor_c_cal", "charge_flow_turbocharger_speed_derate_gain",
  "code: gain of the turbocharger speed derate. e2m: C_CHL_Turbo_Drt_Gain (0x01169A12).")
G("0x003ff730", "boost_control_default_cal", "charge_flow_turbocharger_speed_derate_base_limit",
  "code: the speed limit used when boost_control_mode is not 1; dump 16250 x 0.008 = 130 KRPM. e2m: C_CHL_Turbo_Drt_Limit (0x01169A14, KRPM).")
G("0x003ff732", "throttle_rate_threshold_a_cal", "charge_flow_turbocharger_speed_derate_ratio",
  "code: ratio below which the speed derate does nothing. e2m: C_CHL_Turbo_Drt_Ratio (0x01169A16).")
G("0x003ff736", "fuel_demand_band_low_threshold", "egr_fraction_on_threshold",
  "code: the EGR fraction command at or above it turns the limiter hysteresis on (two functions). e2m: C_CHL_EGR_Frac_Thd_On (0x01169A1a, 'open EGR when the commanded fraction rises above').")
G("0x003ff738", "fuel_demand_band_high_threshold", "egr_fraction_off_threshold",
  "code: at or below it the hysteresis turns off and the integral input is 0. e2m: C_CHL_EGR_Frac_Thd_Off (0x01169A1c).")
G("0x003ff73a", "fuel_demand_rate_increase_limit_cal", "egr_fraction_slew_up_rate",
  "code: the maximum increase per pass of the EGR fraction command. e2m: C_CHL_EGR_Slew_Up_Rate (0x01169A1e).")
G("0x003ff73c", "fuel_demand_rate_working", "egr_fraction_slew_down_rate",
  "code: the (negative) decrease limit per pass while the EGR fraction is on; dump 65528 = -8. e2m: C_CHL_EGR_Slew_Down_Rate (0x01169A20).")
G("0x003ff73e", "boost_control_mode1_cal", "charge_flow_turbocharger_speed_derate_backup_limit",
  "code: the speed limit used when boost_control_mode is 1. e2m: C_CHL_Turbo_Drt_Backup_Limit (0x01169A22).")
G("0x003ff740", "fuel_demand_clamp_upper_cal", "charge_flow_turbocharger_speed_derate_maximum",
  "code: cap of the speed derate offset. e2m: C_CHL_Turbo_Drt_Max (0x01169A24).")
G("0x003ff742", "fuel_demand_clamp_upper2_cal", "charge_flow_delta_pressure_derate_maximum",
  "code: cap of the delta pressure derate offset. e2m: C_CHL_Delta_P_Drt_Max (0x01169A26).")
G("0x003ff744", "fuel_demand_clamp_upper3_cal", "charge_flow_compressor_outlet_temperature_derate_maximum",
  "code: cap of the COT derate offset. e2m: C_CHL_COT_Drt_Max (0x01169A28).")

# --- CSE (charge system errors) ----------------------------------------------------------------------------
G("0x0040a38e", "throttle_rate_control_input", "charge_system_error_for_egr_valve",
  "code: output of cm848_transformChargeSystemErrors; the input of the EGR / assist PI controller and of the integral gain table. e2m: CSE_Xform_Error_1 (+0x00 of 0x01169E00, 'transformed for EGR valve control').")
G("0x0040a390", "throttle_rate_filtered_sum", "charge_system_error_for_turbocharger",
  "code: the second output of the rotation (sin x mass flow error + cos x EGR fraction error / 1.28); its only reader is cm848_calculateWastegateDutyRequest (three reads), the turbocharger-side controller, as the e2m name says. e2m: CSE_Xform_Error_2 (+0x02, 'transformed for turbocharger control'). Dump 220.")
G("0x0040a392", "throttle_position_scaled", "charge_system_mass_charge_flow_error",
  "code: (mass_charge_flow_limited_command - charge_mass_flow_filtered) / 2; the proportional gain table input. e2m: CSE_MCF_Error (+0x04 of 0x01169E00).")
G("0x0040a394", "throttle_rate_error", "charge_system_egr_fraction_error",
  "code: egr_fraction_limited_command - egr_fraction_actual (throttle_fuel_trim_t.egr_fraction_actual). e2m: CSE_EGR_Frac_Error (+0x06).")
G("0x0040a396", "throttle_rate_lookup_raw", "charge_system_transform_angle_scheduled",
  "code: dual-axis table output (engine speed x total injection quantity) before the override and the limits. e2m: CSE_Scheduled_Xform_Angle (+0x08).")
G("0x0040a398", "rpm_load_table_result", "charge_system_transform_angle",
  "code: the angle after override and limits; read by the transform. e2m: CSE_Xform_Angle (+0x0a).")
G("0x0040a39a", "throttle_position_increment", "charge_system_aggressiveness_gain_adjusted",
  "code: charge_system_aggressiveness_gain_scale x fuel_limit_ratio_compensated_reference >> 13 (capped 0xffae) while the hysteresis flag is on, else 0. e2m: CSE_Aggressiveness_Gain_Adj (+0x0c).")
G("0x0040a39c", "throttle_rate_integral_input", "charge_system_egr_fraction_error_adjusted",
  "code: charge_system_egr_fraction_error, or 0 while egr_fraction_limited_command is at or below egr_fraction_off_threshold. e2m: CSE_EGR_Frac_Adj_Error (+0x0e).")
G("0x0040a39e", "throttle_fuel_demand_scaled", "charge_system_mass_charge_flow_error_adjusted",
  "code: (aggressiveness gain + transient gain) x mass flow error >> 13, limited +-12800. e2m: CSE_MCF_Adj_Error (+0x10).")
G("0x0040a3a0", "throttle_position_accumulator", "charge_system_transient_gain_adjusted",
  "code: table lookup on the mass flow error (axis / values throttle_fuel_demand_deviation_gain_*). e2m: CSE_Transient_Gain_Adj (+0x12).")
G("0x003fa15a", "throttle_load_gain_positive", "charge_system_transform_half_angle_cosine",
  "code: lookup of the half-angle cosine table at charge_system_transform_angle (Q14); the rotation's cosine.")
G("0x003fa15c", "throttle_load_gain_negative", "charge_system_transform_half_angle_sine",
  "code: the same table read at 0xb400 - angle: the rotation's sine.")
G("0x003fa15e", "throttle_load_offset_working", "charge_system_transform_supplementary_angle",
  "code: 0xb400 - charge_system_transform_angle (the table argument for the sine).")
G("0x003fa160", "throttle_load_gain_neg_scaled", "charge_system_sine_scaled_mass_charge_flow_error",
  "code: sine x charge_system_mass_charge_flow_error_adjusted >> 14.")
G("0x003fa162", "throttle_load_gain_pos_scaled", "charge_system_cosine_scaled_egr_fraction_error",
  "code: cosine x charge_system_egr_fraction_error_adjusted / 0x51ec (20972 = 1.28 x 16384).")
G("0x003fa158", "speed_threshold_exceeded_flag", "charge_system_aggressiveness_threshold_exceeded_flag",
  "code: hysteresis flag of cm848_calculateChargeSystemAdjustedMassChargeFlowError on fuel_limit_ratio_compensated_reference (on at the upper threshold, off at the lower).")
G("0x003ff856", "throttle_output_clamp_lower_cal", "charge_system_transform_angle_lower_limit",
  "code: lower clamp of the selected angle in cm848_selectChargeSystemTransformAngle; ROM-to-RAM, no _cal.")
G("0x003ff858", "fuel_demand_mode_select_cal", "charge_system_transform_angle_override_value",
  "code: replaces the scheduled angle while charge_system_transform_angle_override_enable_cal is 1 (read in cm848_selectChargeSystemTransformAngle in the C output; the instruction scanner finds no tracked access). Dump 35840 (0x8c00).")
G("0x003ff85a", "throttle_output_clamp_upper_cal", "charge_system_transform_angle_upper_limit",
  "code: upper clamp of the selected angle.")

# --- EAC (EGR / assist controller) -------------------------------------------------------------------------
G("0x0040a3a2", "throttle_fuel_rate_reference", "egr_assist_throttle_command",
  "code: the unstaged output clamped to the assist limits (cm848_calculateEgrAssistControllerOutput); written, and NOT read by any function in the binary (the assist throttle drives nothing). e2m: EAC_Asst_Throt_Cmd (+0x00 of 0x01169F00).")
G("0x0040a3a4", "throttle_fuel_rate_limit_snapshot", "egr_assist_throttle_high_limit",
  "code: copy of the assist throttle upper limit. e2m: EAC_Asst_Throt_High (+0x02).")
G("0x0040a3a6", "throttle_fuel_demand_high", "egr_assist_throttle_low_limit",
  "code: the lower assist limit of the current EGR state (lower limit while the EGR fraction is on, else the upper limit). e2m: EAC_Asst_Throt_Low (+0x04).")
G("0x0040a3a8", "throttle_fuel_demand_limit", "egr_assist_controller_egr_valve_command",
  "code: upper limit - staged position (12800 = 100 percent), written by cm848_calculateEgrAssistControllerOutput; its one reader is cm848_updateEgrValvePositionCommandAndControlState (the valve position command). e2m: EAC_EGR_Valve_Cmd (+0x06 of 0x01169F00). Dump 0.")
G("0x0040a3aa", "throttle_fuel_rate_cal_snapshot", "egr_assist_controller_egr_valve_high_limit",
  "code: copy of the EGR valve upper limit (12800). e2m: EAC_EGR_Valve_High (+0x08).")
G("0x0040a3ac", "throttle_fuel_rate_selected", "egr_assist_controller_egr_valve_low_limit",
  "code: the lower EGR limit of the current EGR state. e2m: EAC_EGR_Valve_Low (+0x0a).")
G("0x0040a3ae", "throttle_rate_coeff_snapshot", "egr_assist_controller_feedforward_term",
  "code: copy of the override value used as the feedforward (dump 1280). e2m: EAC_Feedforward_Term (+0x0c).")
G("0x0040a3b0", "throttle_rate_integral_accumulator", "egr_assist_controller_integral_term",
  "code: the integer part (>> 16) of the Q16 accumulator. e2m: EAC_Integral_Term (+0x0e).")
G("0x0040a3b2", "throttle_rate_derivative_term", "egr_assist_controller_proportional_term",
  "code: error x the adjusted 'd gain' >> 10 limited +-12800: this is the PROPORTIONAL term (the original name swaps p and d). e2m: EAC_Proportional_Term (+0x10).")
G("0x0040a3b4", "throttle_rate_d_gain", "egr_assist_controller_adjusted_proportional_gain",
  "code: table on the mass flow error x egr_assist_controller_proportional_gain >> 12; it multiplies the error in the proportional term. e2m: EAC_Adjusted_P_Gain (+0x12).")
G("0x0040a3b6", "throttle_fuel_rate_working", "egr_assist_controller_preset",
  "code: the integrator preset from cm848_calculateEgrAssistControllerPreset. e2m: EAC_Preset (+0x14).")
G("0x0040a3b8", "throttle_fuel_rate_factor", "egr_assist_controller_preset_lift",
  "code: dual-axis table output (EGR mass flow x delta pressure). e2m: EAC_Preset_Lift (+0x16).")
G("0x0040a3ba", "throttle_fuel_rate_limit_active", "egr_assist_controller_preset_active_flag",
  "code: EGR fraction off (hysteresis flag 0) and egr_assist_controller_preset_enable_cal non-zero.")
G("0x0040a3bc", "throttle_rate_p_gain", "egr_assist_controller_adjusted_integral_gain",
  "code: table on charge_system_error_for_egr_valve x egr_assist_controller_integral_gain >> 12; scales the integrator input (the original name swaps p and d). e2m: EAC_Adjusted_I_Gain (+0x1a).")
G("0x003fa16c", "throttle_position_integral", "egr_assist_controller_integral_accumulator",
  "code: Q16 integrator (stw / lwz): += error x gain x 655, limited by the integral limits, preset when the controller is inhibited or the preset is active.")
G("0x003fa170", "throttle_fuel_rate_limit_exceeded_flag", "egr_fraction_limited_command_above_on_threshold_flag",
  "code: hysteresis flag of cm848_selectEgrAssistControllerLimits on egr_fraction_limited_command (on at egr_fraction_on_threshold, off at egr_fraction_off_threshold); same thresholds as egr_fraction_command_above_on_threshold_flag, other input.")
G("0x003fa172", "throttle_fuel_rate_b", "egr_assist_controller_unstaged_output",
  "code: first word of a mis-sized dword (every access is a halfword): feedforward + proportional + integral limited +-32767. Retype to word; the second word is egr_assist_controller_egr_valve_staged_position.",
  typ="word")
NG("0x003fa174", "egr_assist_controller_egr_valve_staged_position", "word",
   "code: second word of the mis-sized dword throttle_fuel_rate_b (the row now is the label throttle_fuel_rate_b+2): (unstaged output - assist throttle command) x the staging gain >> 12 + the EGR valve lower limit, limited +-32767; the EGR valve command is the upper limit minus its limited value.")
DEL("0x003fa174", "throttle_fuel_rate_b+2", "label of the second word of a mis-sized dword; replaced by the new word row egr_assist_controller_egr_valve_staged_position.")
G("0x003ffc82", "throttle_fuel_demand_high_b_cal", "egr_assist_throttle_lower_limit",
  "code: assist lower limit selected while the EGR fraction is on. e2m: C_EAC_Asst_Throt_LLim (0x01167E00, +0x00 of the block that anchors 0x3ffc82). Dump 0.")
G("0x003ffc84", "throttle_fuel_rate_error_gain_cal", "egr_assist_staging_proportional_gain",
  "code: multiplies the unstaged output minus the assist command (>> 12). e2m: C_EAC_Asst_Throt_P_Gain (0x01167E02, 'proportional gain for the assist portion of the staging algorithm').")
G("0x003ffc86", "throttle_fuel_demand_high_cal", "egr_assist_throttle_upper_limit",
  "code: assist upper limit (the one used while the EGR fraction is off, and the high-limit copy). e2m: C_EAC_Asst_Throt_ULim (0x01167E04).")
G("0x003ffc88", "throttle_fuel_rate_factor_gain_cal", "egr_assist_controller_preset_gain",
  "code: multiplies the preset lift (>> 12). e2m: C_EAC_Preset_Gain (0x01167E06, 'applied to EAC_Preset_Lift prior to saturation limits').")
G("0x003ffc8a", "throttle_fuel_rate_base", "egr_assist_controller_egr_valve_lower_limit",
  "code: lower EGR limit while the EGR fraction is on and the lower bound of the preset. e2m: C_EAC_EGR_LLim (0x01167E08).")
G("0x003ffc8c", "throttle_fuel_rate_cal", "egr_assist_controller_egr_valve_upper_limit",
  "code: 12800 (100 percent): upper EGR limit, the minuend of the EGR valve command and the preset. e2m: C_EAC_EGR_ULim (0x01167E0a).")
G("0x003ffc8e", "throttle_rate_control_scale_cal", "egr_assist_controller_integral_gain",
  "code: scales the integral gain table (>> 12). e2m: C_EAC_I_Gain (0x01167E0c).")
G("0x003ffc90", "throttle_position_integral_limit_b_cal", "egr_assist_controller_integral_lower_limit",
  "code: lower limit of the integral accumulator (<< 16). e2m: C_EAC_Int_LLim (0x01167E0e).")
G("0x003ffc92", "throttle_position_integral_limit_cal", "egr_assist_controller_integral_upper_limit",
  "code: upper limit of the integral accumulator. e2m: C_EAC_Int_ULim (0x01167E10).")
G("0x003ffc94", "throttle_rate_coeff_cal", "egr_assist_controller_override_value",
  "code: used as the feedforward term at the start of the unstaged output; dump 1280 (10 percent). e2m: C_EAC_Override_Value (0x01167E12, 'override value of unstaged controller output').")
G("0x003ffc96", "throttle_position_scale_cal", "egr_assist_controller_proportional_gain",
  "code: scales the proportional gain table (>> 12); dump 8192. e2m: C_EAC_P_Gain (0x01167E14).")
G("0x003fd7d8", "throttle_rate_control_inhibit_flag", "egr_assist_controller_user_override_cal",
  "code: EEPROM mirror: non-zero makes the unstaged output the override value alone (integrator fed with the negated proportional term). e2m: T_EAC_User_Override (0x0116A000, 'user override enable for EGR/Assist').")
G("0x003fd7da", "throttle_fuel_rate_limit_enable_flag", "egr_assist_controller_preset_enable_cal",
  "code: EEPROM mirror: enables the integrator preset (egr_assist_controller_preset_active_flag). e2m: T_EAC_Preset_Enable (0x0116A002) is the word after T_EAC_User_Override, as 0x3fd7da is after 0x3fd7d8.")

# =============================================================================================================
# D. H-bridge state words and leftover EGR valve words
# =============================================================================================================
G("0x003fa73e", "governor_speed_rate_d", "egr_valve_driver_over_current_clear_timer",
  "code: first word of a mis-sized dword (all accesses lhz / sth): the clear timer counted by cm848_updateEgrValveDriverOverCurrentFault (+1 per pass up to the clear time; the retry trigger flag is set at the limit); its second word 0x3fa740 is the fault counter. Retype to word. Dump 1200.",
  typ="word")
G("0x003fa740", "governor_speed_rate_a", "egr_valve_driver_over_current_fault_counter",
  "code: the over-current fault counter of cm848_updateEgrValveDriverOverCurrentRetryCounter (+increment up to the maximum count, -decrement, reset by the give-up word); the plates still call it 'second word of governor_speed_rate_d'. e2m: C_EGA_Driver_OC_Fail_Incrt / _Max_Count / _Pass_Decrt = 'fault counter'. Retype to word (the row has no type). The VGT twin is variable_geometry_turbocharger_driver_over_current_fault_counter.",
  typ="word")
U("0x003fa7ae", "governor_target_speed_c_working", "zeroed once by cm848_clearEgrValveHBridgeFaultState and never accessed by any other function (xref and whole-binary load / store scan; time-shared window, no boot-ROM user); sits between the inrush input flag and the fault retry timer flags; its role is unknown, so no name is proposed, but the old 'governor target speed' name is wrong.")
U("0x003fa7b0", "governor_target_speed_d_working", "same as 0x003fa7ae: zeroed once by cm848_clearEgrValveHBridgeFaultState, no other access; role unknown, old governor name wrong.")
G("0x003fa7b8", "cold_start_enable_flag_b_prev_snapshot", "egr_valve_h_bridge_fault_retry_active_previous_2_flag",
  "code: two passes ago of the retry-active flag of the H-bridge fault path: written by cm848_updateEgrValveHBridgeFaultCounter, zeroed at boot. VGT twin: variable_geometry_turbocharger_h_bridge_fault_retry_active_previous_2_flag. Dump 1.")
G("0x003fa7ba", "cold_start_enable_flag_b_snapshot", "egr_valve_h_bridge_fault_retry_active_previous_flag",
  "code: previous pass of the retry-active flag (same function). VGT twin ..._retry_active_previous_flag. Dump 1.")
G("0x003fa7ca", "cold_start_enable_flag_b", "egr_valve_h_bridge_fault_retry_active_flag",
  "code: first word of a mis-sized dword (lhz / sth only): 1 when the fault retry trigger is set and the counter is below the maximum or give-up is off; read by cm848_processEgrValveHBridgeFaults (pending flag). The second word 0x3fa7cc is egr_valve_h_bridge_inrush_retry_timer_at_limit_flag. Retype to word. Dump 1.",
  typ="word")
NG("0x003fa7cc", "egr_valve_h_bridge_inrush_retry_timer_at_limit_flag", "word",
   "code: second word of the mis-sized dword cold_start_enable_flag_b (the row is the label cold_start_enable_flag_b+2): written by cm848_updateEgrValveHBridgeInrushRetryTimer as (timer at or above the retry time); the twin of egr_valve_h_bridge_fault_retry_timer_at_limit_flag; never read.")
DEL("0x003fa7cc", "cold_start_enable_flag_b+2", "label of the second word of a mis-sized dword; replaced by the new word row egr_valve_h_bridge_inrush_retry_timer_at_limit_flag.")
G("0x003fa7bc", "cold_start_valid_flag", "egr_valve_h_bridge_fault_reset_flag",
  "code: first word of a mis-sized dword (lhz / sth): non-zero would hold all four retry timers and fault counters at 0 (read at the top of each); no function ever writes it non-zero (only the boot clear). Retype to word; the second word 0x3fa7be is egr_valve_h_bridge_inrush_retry_latch_flag. Not in the VGT module.",
  typ="word")
NG("0x003fa7be", "egr_valve_h_bridge_inrush_retry_latch_flag", "word",
   "code: second word of the mis-sized dword cold_start_valid_flag (row = label cold_start_valid_flag+2): set at the inrush retry limit, cleared at 0 by cm848_updateEgrValveHBridgeInrushRetryTimer; the twin of egr_valve_h_bridge_fault_retry_latch_flag.")
DEL("0x003fa7be", "cold_start_valid_flag+2", "label of the second word of a mis-sized dword; replaced by the new word row egr_valve_h_bridge_inrush_retry_latch_flag.")
G("0x003fa7c0", "cold_start_enable_flag_a_snapshot", "egr_valve_h_bridge_inrush_retry_active_previous_flag",
  "code: previous pass of the inrush retry-active flag (cm848_updateEgrValveHBridgeInrushFaultCounter). Dump 1.")
G("0x003fa7c2", "cold_start_enable_flag_a_prev_snapshot", "egr_valve_h_bridge_inrush_retry_active_previous_2_flag",
  "code: two passes ago of the inrush retry-active flag. Dump 1.")
G("0x003fa7c8", "cold_start_enable_flag_a", "egr_valve_h_bridge_inrush_retry_active_flag",
  "code: inrush retry trigger set and the counter below the maximum or give-up off; read by cm848_processEgrValveHBridgeFaults (driver fault pending when it or the fault one is 0). Dump 1.")
G("0x003fa7c4", "cold_start_enable_condition_snapshot", "egr_valve_h_bridge_fault_latched_flag",
  "code: set when the fault counter reaches its set threshold, cleared at 0 (cm848_processEgrValveHBridgeFaults); with fault 724 it drives the electrical fault 726 (mask 0x40). VGT twin variable_geometry_turbocharger_h_bridge_fault_latched_flag.")
G("0x003fa7c6", "cold_start_speed_a_ready_flag", "egr_valve_h_bridge_inrush_fault_latched_flag",
  "code: set when the inrush fault counter reaches its set threshold, cleared at 0; drives fault 724 (mask 0x10).")
G("0x003fa7ce", "cold_start_speed_zero_flag", "egr_valve_h_bridge_inrush_retry_timer_zero_flag",
  "code: (inrush retry timer = 0), written by cm848_updateEgrValveHBridgeInrushRetryTimer; the twin of egr_valve_h_bridge_fault_retry_timer_zero_flag; never read. Dump 1.")
G("0x003fa7d0", "cold_start_timing_active_flag", "egr_valve_h_bridge_fault_counter_decrement_enabled_flag",
  "code: first word of a mis-sized dword (sth only): 1 when the fault retry-active flag has been 1 for three passes and the input is absent; it lets the fault counter fall (the counter rises with the input present and holds otherwise). Retype to word; the second word 0x3fa7d2 is egr_valve_h_bridge_status_a_input_flag.",
  typ="word")
NG("0x003fa7d2", "egr_valve_h_bridge_status_a_input_flag", "word",
   "code: second word of the mis-sized dword cold_start_timing_active_flag (row = label cold_start_timing_active_flag+2): bit 0x10 of supervisor_register_162_status, the input of fault 720 (mask 1); written by cm848_processEgrValveHBridgeFaults. e2m: EGA_Fault_HB1A (0x0110365a mask 1, 'latched value of the ASIC detected hardware fault in the EGR H-bridge').")
DEL("0x003fa7d2", "cold_start_timing_active_flag+2", "label of the second word of a mis-sized dword; replaced by the new word row egr_valve_h_bridge_status_a_input_flag.")
G("0x003fa7d4", "engine_idle_bit6_flag", "egr_valve_h_bridge_status_b_input_flag",
  "code: bit 0x40 of supervisor_register_162_status (cm848_processEgrValveHBridgeFaults), the input of fault 721 (mask 2); not an idle flag. e2m: EGA_Fault_HB1B (0x0110365a mask 2).")
G("0x003fa7d6", "cold_start_timing_advance_timer", "egr_valve_h_bridge_over_current_high_input_flag",
  "code: bit 0x100 of supervisor_register_162_status, or bit 0 of switch_input_state_bits[2] when bit 0 of fuel_feature_control_flags is set: the input of fault 722 (mask 4); not a timer. e2m: EGA_Fault_HB1_OC_HI (0x0110365a mask 4).")
G("0x003fa7d8", "engine_idle_bit8_flag", "egr_valve_h_bridge_over_current_low_input_flag",
  "code: the same source as the over-current high input: the input of fault 723 (mask 8). e2m: EGA_Fault_HB1_OC_LO (0x0110365a mask 8).")
G("0x003fa7da", "cold_start_diag_condition_0_flag", "egr_valve_h_bridge_status_a_fault_latch_flag",
  "code: latch of fault 720 (mask 1): set when the input is present and the fault counter is at its set threshold, cleared at counter 0. e2m: EGA_Fault_HB1A ('latched value').")
G("0x003fa7dc", "cold_start_diag_condition_1_flag", "egr_valve_h_bridge_status_b_fault_latch_flag",
  "code: latch of fault 721 (mask 2), same rule. e2m: EGA_Fault_HB1B.")
G("0x003fa7de", "cold_start_diag_bit2_flag", "egr_valve_h_bridge_over_current_high_fault_latch_flag",
  "code: latch of fault 722 (mask 4), same rule. e2m: EGA_Fault_HB1_OC_HI.")
G("0x003fa7e0", "cold_start_diag_bit3_flag", "egr_valve_h_bridge_over_current_low_fault_latch_flag",
  "code: latch of fault 723 (mask 8), same rule. e2m: EGA_Fault_HB1_OC_LO.")
G("0x003fa7e2", "cold_start_fuel_timer", "egr_valve_h_bridge_inrush_fault_counter_decrement_enabled_flag",
  "code: the inrush twin of egr_valve_h_bridge_fault_counter_decrement_enabled_flag (three passes of inrush retry-active and the input absent), written by cm848_updateEgrValveHBridgeInrushFaultCounter, never read outside it. Dump 1.")
G("0x003fa7e4", "governor_speed_above_target_flag", "egr_valve_h_bridge_inrush_fault_set_flag",
  "code: (inrush fault counter at or above its set threshold), written by cm848_updateEgrValveHBridgeInrushFaultCounter; the twin of egr_valve_h_bridge_fault_set_flag; never read.")
G("0x003fa77c", "governor_speed_ramp_at_target_flag", "egr_valve_closed_stage_ramp_at_target_flag",
  "code: 1 when the position command is at or above egr_valve_closed_stage_command_threshold (staged command reset to it), 0 while the staged command ramps; written by cm848_calculateEgrValveStagedPositionCommand only.")
G("0x003fa77e", "governor_speed_ramp_state", "egr_valve_closed_stage_command",
  "code: the staged closing command (ramped by the stage rate, never below 0, reset to the threshold); the larger of it and the command is egr_valve_position_command_final. The wave-7 plate calls it governor_speed_ramp_state.")
G("0x003fa79c", "boost_governor_speed_below_threshold_flag", "egr_valve_closed_hold_position_at_or_below_threshold_flag",
  "code: 1 when egr_valve_position and egr_valve_position_command_final are both at or below egr_valve_closed_hold_position_threshold (cm848_checkEgrValveClosedHoldCondition); one of the two ways to the closed hold.")
G("0x003fa79e", "boost_pressure_governor_ramp_working", "egr_valve_closed_hold_counter",
  "code: counts passes of a 0 position command up to egr_valve_closed_hold_maximum_time, reset when the command is non-zero. The wave-7 plate calls it boost_pressure_governor_ramp_working.")
G("0x003fa7a0", "governor_speed_at_limit_flag", "egr_valve_closed_hold_time_reached_flag",
  "code: (closed hold counter at or above the maximum time), written by cm848_checkEgrValveClosedHoldCondition; the other way to the closed hold. Dump 1.")
G("0x003fa7a2", "governor_speed_target_active_flag", "egr_valve_position_command_nonzero_flag",
  "code: (egr_valve_position_command != 0), written by cm848_checkEgrValveClosedHoldCondition; never read elsewhere.")
G("0x003fbd1a", "governor_speed_at_target_prev_flag", "egr_valve_closed_hold_previous_flag",
  "code: the previous egr_valve_closed_hold_flag for the closing edge: read and written by cm848_countEgrValveClosings, initialised by cm848_initializeEgrValveClosedHoldPreviousFlag; nothing to do with a governor. Dump 1.")
G("0x003fbd10", "", "egr_valve_position_command_diagnostic_filter_state",
  "code: the ema_filter_state_t of the filtered final position command (egr_valve_position_command_diagnostic_filtered): coefficient pointer stored by cm848_initializeEgrValvePositionControlDiagnostic (stw), accumulator at 0x3fbd14. The row already has the type; only the name is missing.")

# =============================================================================================================
# C. enum, E. type notes, notes
# =============================================================================================================
NOTE("ENUM (new type, enums.csv - enum_name,value,member_name,comment,size; every value is read from cm848_selectEgrValveControlState 0x197b4 and its consumers, all stores of the word at 0x40a6ca are in that function): "
     "EGR_VALVE_CONTROL_STATE,0,EGR_VALVE_CLOSED_LOOP,PID position control: cm848_selectEgrValveDutyByControlState takes egr_valve_pid_duty (the default state; the staged command and the loop reference use the final command here and in state 1),2 | "
     "EGR_VALVE_CONTROL_STATE,1,EGR_VALVE_CLOSED_HOLD,Open-loop closed-hold duty: egr_valve_closed_hold_flag is set (command 0 held for the closed hold time or position at or below the hold threshold),2 | "
     "EGR_VALVE_CONTROL_STATE,2,EGR_VALVE_USER_DUTY_OVERRIDE,Fixed duty override: bit 1 of egr_valve_user_override_flags_cal is set,2 | "
     "EGR_VALVE_CONTROL_STATE,3,EGR_VALVE_AUTOZERO_DRIVE,Position autozero drive: egr_valve_drive_diagnostic_override_flag is set and the autozero holding duty is output (the dump is permanently here: fault 718 keeps the hold counter at 0),2 | "
     "EGR_VALVE_CONTROL_STATE,4,EGR_VALVE_DISABLED,Output disabled: logical output request 67 (the PWM enable) is clear; the duty is 0,2. "
     "Evidence per value: the stores at cpp 16019 (4), 16022 (3), 16026 (1), 16029 (0), 16033 (2); the readers compare with 0, 1, 2, 3, 4 (cm848_selectEgrValveDutyByControlState 16337-16350, the staged command 16119 'state is neither 0 nor 1', the position control diagnostic 61967 'state != 0'). "
     "Globals that take the type (global_variables.csv rows, type column): 0x0040a6ca,egr_valve_control_state,EGR_VALVE_CONTROL_STATE and 0x003fa78e,egr_valve_control_state_previous,EGR_VALVE_CONTROL_STATE (previous: boot initialization stores 3, cm848_calculateEgrValvePidDuty copies the state at the end and tests '!= 0'). "
     "Both words are accessed only as halfwords (0x40a6ca: sth by the selector, lha by four readers; 0x3fa78e: lha / sth), so the enum's size 2 fits; 0x3fa78e is in the time-shared window and has no boot-ROM user (scan: none). Every reader uses lha, so an i16-style signedness may add a (short) cast to the rendering: an accepted difference. Compared locals: none. "
     "Keep egr_valve_control_state / _previous otherwise unchanged. The VGT sibling has six states (no autozero drive, two stop-seek states and a driver-disabled state 5) and stays a separate enum.")
NOTE("TYPE ROWS (global_variables.csv: address,name,type,comment; each retype is proven by the load / store instructions listed): "
     "(1) 0x004067f2,egr_valve_derivative_filter_coefficient,word,...: byte -> word. The cell holds 0x8000 (32768 = 0.5 in 1/65536) and the byte row shows only its high byte 0x80; the first-order filter reads it through the pointer stored at 0x3fa790 (so xref_addr.py shows no access); e2m C_EGA_Der_Dtime_Cnst has scale 1.52588E-05 = 1/65536, a 16-bit filter constant exactly like sensor_channel_config_t.filter_coefficient (word); the VGT twin 0x407720 has the same fault (byte row, word value 0x8000). "
     "(2) 0x0040a666,egr_valve_position_autozeroed,i16,...: ALL FOUR users agree on signed: the store is sth (cm848_updateEgrValvePositionAutozero) and the three loads are lha (cm848_selectEgrValvePositionSource, cm848_evaluateEgrValvePositionControlDiagnosticConditions, cm848_runEgrValvePositionControlDiagnostic). "
     "(3) 0x0040a662,egr_delta_pressure_state,word,... and 0x0040a664,egr_valve_position_autozero_offset,word,... replace the dword sensor_channel105_fault_combined (+ its '+2' label row 0x0040a664): the first word is stored (sth) only by cm848_selectEgrDeltaPressure at 0x18a50 and the second word (sth) only by cm848_updateEgrValvePositionAutozero at 0x506840; no access is a dword. "
     "(4) 0x0040a70a,egr_valve_autozero_enable_flag,word and 0x0040a716,egr_valve_ready_for_autozero_flag,word: dword rows, every access sth / lhz (writers cm848_updateEgrValveEnableAndDiagnosticConditions, cm848_updateEgrValveAutozeroConditions, cm848_initializeEgrValveAutozeroConditions; readers cm848_updateEgrValveAutozeroActiveFlag, cm848_updateEgrValveEnableAndDiagnosticConditions); 0x40a70c and 0x40a718 have no access (dump 0). "
     "(5) 0x0040a652 (egr_delta_pressure_autozero_enable_flag) dword -> word, same reason; 0x40a654 has no access. "
     "(6) 0x004067e8 egr_valve_control_strong_drive_duty_threshold stays word: its only load is lhz (the VGT's 0x407780 is lha / i16, the EGR copy is not). "
     "(7) Pointer-struct rows -> ema_filter_state_t (8 bytes: coefficient word* + accumulator dword): 0x003fa716 (egr_delta_pressure_autozero_offset_filter_state), 0x003fa750 (egr_valve_delta_pressure_filter_state: pointer stw at 0x3fa750 to egr_valve_motor_winding_temperature_filter_coefficient, accumulator stw at 0x3fa754 seeded with egr_delta_pressure << 16), 0x003fa790 (egr_valve_derivative_filter_state, delete the 0x003fa794 row) - boot inits store pointer and accumulator with stw (instruction scan); the first two have no other row inside the 8 bytes.")
NOTE("STALE CITATIONS (the 19 rows of the wave-7 list): CHECKED AT HEAD - all 19 comments were already refreshed (a scan of every CSV comment outside '(was ...)' / 'earlier note' history for fuel_demand_boost_input, boost_fuel_scale_cal, fuel_timing_error_scale, boost_correction_inhibit_flag, boost_fuel_mode_active, cm848_processFuelDemandFaultConditions, governor_speed_at_target_flag, sensor_generic_fault_status, cm848_calculateSensorChannel75DeviationDiagnosticConditions finds 0 hits, and none of those names is a row name any more). "
     "Two of the 19 rows had a stale NAME, not citation, and are renamed in this file: 0x003fbd1a governor_speed_at_target_prev_flag -> egr_valve_closed_hold_previous_flag and the blank 0x003fbd10 -> egr_valve_position_command_diagnostic_filter_state. After this file is applied the refresh step has to rewrite the plates / comments that cite the old names renamed here (boost_fuel_correction, boost_pressure_governor_ramp_working, governor_speed_ramp_state, throttle_fuel_demand_limit, fuel_demand_rate_limiter ...).")
NOTE("IDENTITY, DELTA PRESSURE CHAIN: the 0x18384-0x18afc functions (and the 'boost_correction_*' / 'boost_decel_*' words) are the autozero of the EGR delta pressure sensor on sensor channel 105, not boost or protection logic: (code) a learned zero offset of channel 105 is filtered while the engine is stopped and the key is off, saved in EEPROM (0x3fdfb0), subtracted from the sensor value, with an error status that sets fault 719; (e2m) the RAM cells line up at equal relative offsets with the cal block 0x01176E00 (0x40673c-0x40674c) and the state block 0x01176F00 (0x40a650-0x40a662) of C_EGR_Delta_P_AZ_* / EGR_Delta_P_* / EGR_Delta_Press*, and fault 719 is the e2m EGR_Delta_P_Autozero_Error bit. The EGR valve command forced to 12800 / 0 by boost_decel_mode_flag is the autozero precondition. "
     "The DELTA PRESSURE USED by the rest of the firmware is a different word, 0x40a628 (was boost_fuel_correction): it is the sensor output only when boost_correction_alt_mode_cal (0x4002ea, dump 1) is 0; with the alternate mode it is (boost_pressure_current_raw 0x40a7d0 - boost_pressure_baseline_cal 0x40675a) - map_fuel_correction_factor 0x40a42e, so on this truck the channel-105 chain is bypassed for the consumers (the dump: sensor status 2, fault 691 set, output 0 but delta pressure 85). Left unrenamed (no e2m anchor, roles not proven): boost_correction_alt_mode_cal (a ROM-to-RAM cell that carries a wrong _cal and a boost name; it selects the computed delta pressure and is required non-zero by the cooler monitor), boost_pressure_current_raw, map_fuel_correction_factor, boost_pressure_baseline_cal, 0x40a624 boost_fuel_correction_prev (the sensor value in alternate mode, else 0; read by cm848_calculateLoadBasedFuelTrim), 0x40a626 boost_fuel_mode_state, 0x40a62e fuel_demand_enable_state_cached, and the three consumers' own names.")
NOTE("IDENTITY, 0x5033a0 / 0x5031fc / 0x503604: NOT part of the delta pressure chain. They are the EGR cooler fouling monitor: precondition (EGR flow, coolant temperature, valve position and delta pressure above thresholds), a measured cooler effectiveness (T_hot - T_out) / (T_hot - T_coolant) in 0-10000 against a flow-dependent threshold, a 10-pass dwell, a fault counter in 0.1 s with a fouled flag, and the CHH flags. Proof is both code and e2m: the RAM block 0x40a442-0x40a44e matches 0x011A5700 (CHH_CBO_Off, CHH_EGR_Cooler_Fouled, CHH_EGR_System_Failure, EGR_Cooler_Eff, EGR_Cooler_Eff_Thd, EGR_Cooler_Fouling_Fault_Count, EGR_Cooler_Fouling_Precondition), the cal cells 0x4051e8-0x4051f0 match C_EGR_Cooler_* (0x011A5600), and the enable bit 0x2000 of the word 0x3fd5c2 is T_EGR_Cooler_Fouling_Enable (0x01106B28 mask 2000). The dump has that bit clear (0x8488), so the monitor is off in this calibration (counter 0, precondition 0). "
     "Not renamed: 0x40a686 boost_fuel_input_value (dump 81, x32 = hot-side temperature in 1/64 degree F; filtered by cm848_auxiliaryControl_exponentialAverage 0x506e28) and 0x40a68c throttle_trim_lookup_input (outlet side, 1/64 degree F, written by sensor_throttleTrim_inputSelect 0x50716c): they are the two EGR cooler temperatures (e2m names 'EGR orifice temperature' = sensor channel 108 / T_INM_EGRT_Lead), which one is which needs the channel-108 chain (0x506f88 / 0x507028). 0x40a442 first word fuel_blend_correction_inhibit_flag (CHH_CBO_Off) is read by cm848_applyOffNominalTimingAdjustment: rename after the two state words fuel_demand_mode_index (0x40a430) and fuel_demand_droop_state (0x40a7d2) are identified (they feed CHH_EGR_System_Failure and CHH_CBO_Off).")
NOTE("IDENTITY, CHARGE MANAGER (all three blocks are the e2m Charge Manager, e2m names kept in the evidence): CHL = limiters (cm848_limitChargeManagerCommands 0x10b28: three charge flow derates - compressor outlet temperature, EGR delta pressure, turbocharger speed - and the EGR fraction on / off hysteresis with a slew limiter); CSE = charge system errors (cm848_calculateChargeSystemErrors 0x11290: mass charge flow error and EGR fraction error rotated by a speed / quantity scheduled transform angle into one error for the EGR valve and one for the turbocharger); EAC = EGR / assist controller (cm848_runEgrAssistController 0x118f8: PI controller with preset and staging between an assist throttle and the EGR valve). "
     "Blocks and offsets: CHL state 0x40a378-0x40a38c = e2m 0x01169B00 +0x00..+0x14 (word by word), CHL cal 0x3ff71c-0x3ff744 = 0x01169A00 +0x00..+0x28 (all 21 cells; 0x3ff71c / 0x3ff724 / 0x3ff72c are the three derate filter constants, reached only through the pointers stored by cm848_initializeChargeManagerLimiters, so they get no new_global rows), CSE state 0x40a38e-0x40a3a0 = 0x01169E00 +0x00..+0x12, EAC state 0x40a3a2-0x40a3bc = 0x01169F00 +0x00..+0x1a, EAC cal 0x3ffc82-0x3ffc96 = 0x01167E00 +0x00..+0x14, EAC trims 0x3fd7d8 / 0x3fd7da = T_EAC_User_Override / T_EAC_Preset_Enable. The assist throttle (egr_assist_throttle_command 0x40a3a2) is computed and has no reader anywhere. "
     "Inputs found on the way: compressor_outlet_temperature (was fuel_flow_rate, an estimate gated by the feature bit 0x80) and fuel_demand_quantity (0x40afe6, 10 users) = the filtered TURBOCHARGER SPEED (strong lead, NOT renamed: e2m C_EGR_AZ_Turbo_Speed_Thd and the CHL turbo derate ratio both divide / compare it with a KRPM 0.008 cell, boost_control_mode 0x40afd6 selects the base or backup limit, but fuel_demandSource_modeSelect 0x50ecc4 picks it from three sources (governor_speed_reference_raw, governor_temperature_correction, egr_smoke_speed_demand_working, mode 0 / 1 / 2) whose own names are unverified; propose the rename with that module). "
     "The CSE / EAC / CHL table arrays (throttle_load_gain_angle_x_axis / _y_axis / _grid, throttle_load_gain_half_angle_cosine_axis / _values, throttle_fuel_demand_deviation_gain_axis / _values and the EAC gain tables WORD_ARRAY_003ffaf6 / 003ffb1e / 003ffbfa / 003ffc1c / 003ffb46-003ffb62, C_CHL derate tables 003ff78a-003ff834) were not renamed here because array rows are also in arrays.csv; rename them with their arrays.csv entries (charge_system_transform_angle_*, charge_system_transform_half_angle_cosine_*, charge_system_transient_gain_*, egr_assist_controller_*_gain_*). "
     "THE EGR VALVE COMMAND CHAIN IS NOW CLOSED: egr_fraction_combustion_command -> egr_fraction_limited_command -> charge system errors -> egr_assist_controller_egr_valve_command -> egr_valve_position_command -> the EGR valve H-bridge loop.")
NOTE("OTHER LEFT-OVERS: cold_start_inhibit_cal (0x3fd7f0, EEPROM mirror, name wrong) has five users - cm848_updateEgrDeltaPressureAutozero (copied into the filter block as the error count clear), the cooler fouling counter, cm848_processBoostControlState (0x1359c), cm848_calculatePressureSensorFiltered (0x13dc8, two reads) and sensor_throttleTrim_ema_faultProcess (0x507028, two reads) - each tests '(feature bit == 0) || cold_start_inhibit_cal != 0' and holds an error counter at 0: it is a shared 'clear the air handling diagnostic error counters' trim (the twins are T_EGR_Clr_Autozero_Error_Count at 0x3fd7f2 and T_VGT_Clr_Adjustment_Error_Cnt); a rename such as air_handling_diagnostic_error_count_clear_cal needs the other two users' sensors identified first. "
     "0x3fa79a governor_speed_range_prev_snapshot (written by cm848_outputEgrValveDirectionAndDuty, boot initialization 1): previous direction state for the direction-change duty zeroing, not renamed (the function was not re-read for it; it duplicates egr_valve_direction_request_previous_flag in role). 0x4067e8 control_strong_drive_duty_threshold read as lhz: unsigned, no change. cm848_bothConditionsTrue (0x1a980) keeps its name. "
     "The H-bridge names follow the VGT twins (variable_geometry_turbocharger_h_bridge_* / _driver_over_current_*) and the e2m state block 0x0117C200 (the already-named egr_valve_h_bridge_*_flag words at 0x40a6fc-0x40a708 are its +0x00..+0x0c); the words renamed here are the compiler's file-static state of the same functions and have no e2m names. Every row inside 0x3F9800-0x3FDB30 quotes the xref and boot-ROM scan result; none has a user below 0x7F60.")


G("0x003fd7d6", "throttle_rate_override_flag", "charge_system_transform_angle_override_enable_cal",
  "code: EEPROM mirror: read only by cm848_selectChargeSystemTransformAngle; 1 selects charge_system_transform_angle_override_value instead of the scheduled angle. No e2m trim name found for it (it sits right before T_EAC_User_Override / T_EAC_Preset_Enable).")
G("0x004067e2", "", "egr_valve_position_command_diagnostic_filter_constant",
  "code: the coefficient cell the filter state egr_valve_position_command_diagnostic_filter_state points at (stored by cm848_initializeEgrValvePositionControlDiagnostic): weight of the previous value of the filtered final position command in 1/65536 (dump 33647 = 0.513). The row has the type word; only the name is missing.")


NOTE("EXACT ROW CHANGES FOR THE APPLIER (global_variables.csv address,name,type; the comment of each row is the evidence of its row above, '(was <old>)' appended): "
     "RETYPE + RENAME (the old row exists, its type changes): "
     "0x003fa73e,egr_valve_driver_over_current_clear_timer,word | 0x003fa740,egr_valve_driver_over_current_fault_counter,word | "
     "0x003fa7bc,egr_valve_h_bridge_fault_reset_flag,word | 0x003fa7ca,egr_valve_h_bridge_fault_retry_active_flag,word | "
     "0x003fa7d0,egr_valve_h_bridge_fault_counter_decrement_enabled_flag,word | 0x003fa172,egr_assist_controller_unstaged_output,word | "
     "0x0040a652,egr_delta_pressure_autozero_enable_flag,word | 0x0040a662,egr_delta_pressure_state,word | "
     "0x0040a70a,egr_valve_autozero_enable_flag,word | 0x0040a716,egr_valve_ready_for_autozero_flag,word | "
     "0x004067f2,egr_valve_derivative_filter_coefficient,word | 0x0040a666,egr_valve_position_autozeroed,i16 | "
     "0x0040a6ca,egr_valve_control_state,EGR_VALVE_CONTROL_STATE | 0x003fa78e,egr_valve_control_state_previous,EGR_VALVE_CONTROL_STATE | "
     "0x003fa716,egr_delta_pressure_autozero_offset_filter_state,ema_filter_state_t | 0x003fa750,egr_valve_delta_pressure_filter_state,ema_filter_state_t | 0x003fa790,egr_valve_derivative_filter_state,ema_filter_state_t. "
     "NEW WORD ROWS (new_global rows above; each replaces the '+N' label row named in its DELETE note, which stage 1 of apply_extras.py removes first): "
     "0x003fa7be,egr_valve_h_bridge_inrush_retry_latch_flag,word | 0x003fa7cc,egr_valve_h_bridge_inrush_retry_timer_at_limit_flag,word | 0x003fa7d2,egr_valve_h_bridge_status_a_input_flag,word | "
     "0x003fa174,egr_assist_controller_egr_valve_staged_position,word | 0x0040a664,egr_valve_position_autozero_offset,word. "
     "DELETE rows without a replacement: 0x003fa794 j1939_handler_param_table_index (accumulator half of the ema_filter_state_t at 0x003fa790). "
     "WIDTH PROOF for every retype: all accesses of the first word are halfword (sth / lhz / lha) in xref_addr.py and in the whole-binary load / store scan, none is a dword, and the second word has its own halfword accesses (or none); "
     "inside 0x3F9800-0x3FDB30 the boot-ROM scan 0x0-0x7F5F (low halfword of the address in any load / store / addi / ori, and aligned 32-bit constants equal to the address) found nothing for any of these addresses or for the other 0x3fa7xx words; "
     "0x3fa790 / 0x3fa794 / 0x3fa716 / 0x3fa750 are stored with stw (pointer and accumulator) by the boot inits and used through cm848_signedFirstOrderFilter's struct pointer. "
     "RENDER NOTE: the names of the rows typed ema_filter_state_t / EGR_VALVE_CONTROL_STATE appear in the C output only after the build, and a retyped dword row changes '._0_2_' / '._2_2_' accesses to plain names (a label-only difference).")


NOTE("LEAD ITEMS CHECKED AND NOT RENAMED (one line each): "
     "(1) cm848_calibration_group22_load 0x52e29c: reads the delta pressure sensor output (egr_delta_pressure_sensor_output, three reads) in a crank-phase plausibility check (key on, cold_start_phase CSP_CRANKING, egr_valve_position below DAT_00409e90, no fault 725, dwell counters boost_corr_crank_phase_dwell_a / _b): |output| above DAT_00409ea8 sets bits 0x240 of diagnostic_status_flags_working; a second, running-engine half uses DAT_00409e86 / 8a / 8c / 92 (speed, load and valve position limits). It is a delta pressure sensor plausibility check, but its bits and DTC slot were not decoded, so the function and the boost_corr_* words stay as they are (the unnamed cells 0x409e86-0x409ea8 are its thresholds). "
     "(2) cm848_calibration_group21_load_cont 0x52eae8: a cam / sync start-up evaluation (coolant minus battery temperature, fault bits, cold_start_phase CSP_CRANKING, engine_sync_validation_flags) whose only link to the valve is the position test against DAT_00409eb8 at cpp 86910; NOT part of the delta pressure chain. "
     "(3) cm848_completeBoostPressureMonitorReport 0x52d524: completion of the Boost / MAP monitor group (P0236 / P0299 / P0069 by the DTC table), gated on the group 21 / 22 triggers above; unresolved conflict: the DTC names say boost while the compared word is the EGR delta pressure; decode diagnostic_status_flags_working bits 0x40 / 0x80 / 0x100 / 0x200 against the slot table before renaming any of the three. "
     "(4) The 0x18070-0x182e8 'throttle' functions (cm848_throttlePositionProcessing, cm848_faultSeverityEvaluation, cm848_processThrottlePositionLookups, cm848_calculateThrottleProtectionLimit) and their throttle_position_* / throttle_cal_* / throttle_demand_* / throttle_protection_load_ratio words are a different 'throttle': a torque / fuel demand percentage from the governor integrator and ROM tables (DAT_0005c2b2-0x5c2ba, friction fuel by coolant temperature); not the EAC and not touched. "
     "(5) The other fuel_demand_rate_* words (0x3fa6de fuel_demand_rate_complement, 0x3fb420-0x3fb426 fuel_demand_rate_limiter_state and _lookup_a / b / c, 0x408998 / 0x40899a fuel_demand_rate_step_down / _up, 0x408db6 / 0x408dba) belong to the Bank 1 fuel demand limit module (cm848_calculateFuelDemandLimit 0x3ccb4, mpc555_initFuelDemandTrackingState 0x3cf40) and are unrelated to the charge manager; only fuel_demand_rate_limiter (0x40a37a), fuel_demand_rate_input, fuel_demand_rate_below_min_flag, fuel_demand_rate_increase_limit_cal and fuel_demand_rate_working (0x3ff73c) were CHL words and are renamed above. "
     "(6) 0x3fa7ae / 0x3fa7b0 (governor_target_speed_c / d_working): zeroed at boot by cm848_clearEgrValveHBridgeFaultState and never accessed again, role unknown - left as uncertain rows with no name.")

# --- uncertain rows ---------------------------------------------------------------------------------------
U("0x004002ea", "boost_correction_alt_mode_cal", "role proven only as a selector: 0 = the sensor chain output is the delta pressure, non-zero (dump 1) = the delta pressure is computed from two other pressures; also required non-zero by the cooler monitor and by the valve command stage; no e2m cell found. Name and its _cal (the cell is a ROM-to-RAM value, not EEPROM) both need a fix but the replacement name is not settled.")
U("0x003fd7f0", "cold_start_inhibit_cal", "shared error-counter clear trim with five users; the other two sensors are not identified, see the note.")
U("0x0040afe6", "fuel_demand_quantity", "strong lead = filtered turbocharger speed (KRPM 0.008, ten users incl. two Bank 2 selectors); not renamed because its three-way source selection uses unverified names.")
U("0x0040a686", "boost_fuel_input_value", "one of the two EGR cooler temperatures (x32 in the effectiveness formula); which side needs the channel-108 chain.")

with open(RESULT, "w") as f:
    for r in rows:
        f.write(json.dumps(r) + "\n")
print("rows", len(rows), "problems", len(problems))
for p in problems:
    print("PROBLEM", p)
