import json, re, csv, collections, glob, os, struct

OUT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_air.jsonl"
ROOT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/"
FW = ROOT + "firmware/CM848_S90140.06_analysis/output/"
cpp = open(FW + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
ram = open(ROOT + "firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin", "rb").read()


def ramword(a):
    return struct.unpack(">H", ram[a - 0x3FA000:a - 0x3FA000 + 2])[0]


def container(line_no):
    for i in range(line_no - 1, -1, -1):
        m = re.match(r"// Function: (\S+) @", cpp[i])
        if m:
            return m.group(1)


cw = [i + 1 for i, l in enumerate(cpp) if l.strip() == "cm848_turboCompensationWrapper();"]
ci = [i + 1 for i, l in enumerate(cpp) if l.strip() == "mpc555_initTurboCompensationVariables();"]
wrapper_caller = container(cw[0])
init_caller = container(ci[0])
print("wrapper caller:", wrapper_caller, " init caller:", init_caller)
R = []


def fn(addr, old, verdict, new, plate, ev):
    d = {"kind": "function", "address": addr, "old": old, "verdict": verdict}
    if new:
        d["new"] = new
    if plate:
        d["plate_comment"] = plate
    d["evidence"] = ev
    R.append(d)


def gl(addr, old, new, ev, verdict="confirmed"):
    R.append({"kind": "global", "address": addr, "old": old, "verdict": verdict, "new": new, "evidence": ev})


def ng(addr, new, typ, ev):
    R.append({"kind": "new_global", "address": addr, "new": new, "type": typ, "evidence": ev})


def sf(old, new, ev):
    R.append({"kind": "struct_field", "struct": "rpm_governor_state_t", "old": old, "new": new, "evidence": ev})


def note(t):
    R.append({"kind": "note", "text": t})


# ---------------- heater performance test ----------------
fn("0x0053227c", "hpcr_throttlePositionDiagnostic", "confirmed", "cm848_armIntakeAirHeaterPerformanceTest",
   "Boot-time arming of the intake air heater performance test (called once from cm848_applicationMain): reloads the dwell from DAT_0006442c, zeroes the sample count, ring index and the baseline and loaded battery-voltage averages, and sets intake_air_heater_performance_test_state to 0 (armed) only when no battery temperature sensor fault (P0517 / P0516, fault_detected_bits_368_to_383 masks 0x800 / 0x1000) is set and the battery temperature and the intake manifold temperature differ by at most DAT_0006443a (640 = 10 F, a cold-soaked engine); otherwise it sets state 6 (aborted). (was hpcr_throttlePositionDiagnostic)",
   "Not a throttle diagnostic: it writes only the heater-test counters and intake_air_heater_performance_test_state (0 or 6), its one caller is the boot list of cm848_applicationMain, and cm848_monitorIntakeAirHeaterPerformance can only start from state 0. Masks 0x800 / 0x1000 of word 23 are P0517 / P0516 (battery temperature sensor) in the fault decode.")
fn("0x0053232c", "engine_protection_batteryLoad_check", "confirmed", "cm848_abortIntakeAirHeaterPerformanceTestIfConditionsInvalid",
   "Called by states 1, 2 and 3 of cm848_monitorIntakeAirHeaterPerformance: returns 1 and sets intake_air_heater_performance_test_state to 6 (aborted) when the intake manifold temperature is below DAT_00064432 (0 F), an intake air temperature sensor fault (P0113 / P0112) or a grid heater circuit fault (P0541 / P0542 / P2607 / P2608) is set, the battery voltage (1/16 V per count) is outside the range DAT_00064436 to DAT_00064434 (160 to 208 = 10 to 13 V), or intake_air_heater_status_flags shows neither preheat on (bit 1) nor preheat done (bit 3); otherwise returns 0. It does not measure a battery load. (was engine_protection_batteryLoad_check)",
   "Verified from the code: every branch either aborts the test or returns 0, and the fault masks decode as intake-temperature (bits_16_to_31 0x8 / 0x10 = P0113 / P0112) and grid-heater (bits_288_to_303 0x40 / 0x80 / 0x100 / 0x200 = P0541 / P0542 / P2607 / P2608) circuit faults. ROM thresholds read from cm848_rom.bin: 0, 208, 160.")

# ---------------- wastegate duty controller ----------------
fn("0x0001231c", "cm848_turboCompensationWrapper", "confirmed", "cm848_runWastegateDutyController",
   "Phase group A call slot of the wastegate duty controller (called from @WRAPPER@): calls cm848_calculateWastegateDutyRequest and does nothing else. (was cm848_turboCompensationWrapper)".replace("@WRAPPER@", wrapper_caller),
   "The body is the single call cm848_calculateWastegateDutyRequest(), which writes rpm_governor_state_t_0040a3ca.commanded_rpm (21792 = 2 x 10896 in the dump reaches wastegate_solenoid_duty_command through cm848_applyWastegateSolenoidDuty). No CM550 function carries the turbo-compensation names, so no cross-firmware link breaks. The wave-1 G3 agent suggested cm848_runWastegateDutyControl; either spelling is fine.")
fn("0x0001233c", "mpc555_initTurboCompensationVariables", "confirmed", "cm848_initializeWastegateDutyController",
   "Boot init of the wastegate duty controller (called from @INIT@): zeroes throttle_rate_integrator, governor_rpm_band_rate_working, the duty request of the controller state struct and the battery-voltage averaging accumulator ema_filter_state_t_003fa19c (coefficient pointer set to WORD_003ffcb4), and sets the twelve lookup hint words DAT_003fa17e to DAT_003fa19a to 2. (was mpc555_initTurboCompensationVariables)".replace("@INIT@", init_caller),
   "Every variable it zeroes is used by cm848_calculateWastegateDutyRequest (integrator, rate-limiter state, commanded_rpm, the EMA state fed with sensor_readings_t.battery_voltage) and the 12 words set to 2 are exactly the interpolation hint arguments of that function. The wave-1 G3 agent suggested cm848_initWastegateDutyControl.")
fn("0x00011a4c", "cm848_checkSpeedBandCondition", "confirmed", "cm848_updateWastegateDutyIntegratorEnable",
   "Anti-windup of the wastegate duty controller integrator: sets throttle_acceleration_active_flag (integrator enabled) to 0 while the duty request is pinned at the duty ceiling with a non-negative integrator input (governor_speed_error_working), or pinned at the duty floor with a non-positive input; otherwise to 1. Called once per pass by cm848_calculateWastegateDutyRequest. (was cm848_checkSpeedBandCondition)",
   "Truth table of the nested tests: flag = 0 iff (commanded_rpm >= desired_rpm and input >= 0) or (commanded_rpm <= lower_rpm_limit and input <= 0); the flag gates the integrator update in cm848_calculateWastegateDutyRequest (conditional-integration anti-windup). Its only other user is that function.")
fn("0x0002ca14", "cm848_calculateSpeedControlLimit", "uncertain", None, None,
   "Second reader of commanded_rpm: applies the override governor_commanded_rpm_override_cal (flag bit 0 of governor_rpm_override_flags), caps it at speed_control_rpm_upper_limit_cal (12800) and, with governor_status_flags mask 0x4000 (set in the dump), clamps it into [fuel_control_setpoint_cal, 12800 - fuel_control_setpoint_cal] = [1856, 10944]; fuel_control_setpoint_working = 10896 in the dump = commanded_rpm. The consumers (cm848_calculateSpeedControlRampUp / RampDown, cm848_updateSpeedControlOutputs, cm848_selectSpeedControlGains, cm848_checkSpeedZeroCondition) work in the same 12800 = 100 percent scale, but cm848_applyWastegateSolenoidDuty reads commanded_rpm directly and not their output, so whether this speed-control chain is wastegate duty conditioning or a separate governor path needs its own pass (the wave-1 G3 agent reached the same conclusion); no rename.")

# ---------------- charging chain ----------------
fn("0x00037658", "cm848_processProtectionVoltageOffset", "confirmed", "cm848_calculateChargingVoltageError",
   "Charging regulator error: when engine_feature_enable_flags_cal bit 0 is set, saves the previous error in battery_voltage_delta_snapshot, sets charging_voltage_error = charging_voltage_target - battery voltage (1/16 V per count; 48 = 3.0 V in the dump), updates charging_voltage_error_slow_average (new-sample weight battery_voltage_filter_coeff_cal / 65536) and sets charging_voltage_error_fast_component = error - slow average. (was cm848_processProtectionVoltageOffset)",
   "Direct reading of the code; the outputs are the inputs of the state 2 / 3 duty tables, the state machine and the PID. Dump: target 240, error 48. The wave-1 G3 agent suggested the same name.")
fn("0x000376dc", "cm848_dispatchProtectionOutputMode", "confirmed", "cm848_updateAlternatorFieldRegulatorState",
   "Steps the 4-state charging (alternator field) regulator when engine_feature_enable_flags_cal bit 0 is set: saves the state in alternator_field_regulator_previous_state, then takes the next state from the 4-entry handler table at ROM 0x57730 (0 idle or fault, 1 start ramp, 2 regulation, 3 load response; the handlers at ROM 0x38338 / 0x38384 / 0x383f0 / 0x3844c are not decompiled as functions). (was cm848_dispatchProtectionOutputMode)",
   "The body is exactly one indirect call through the handler table into alternator_field_regulator_state; I disassembled the four handlers (see the transition note). The wave-1 G3 agent suggested the same name.")
fn("0x00037a40", "cm848_calculateProtectionOutputDemand", "confirmed", "cm848_calculateAlternatorFieldDutyByPid",
   "Charging-voltage PID loop, run only when operating_mode_flags mask 0x20 is set and the regulator is in state 2 or 3, where it replaces the duty of cm848_calculateAlternatorFieldDutyByRegulatorState: gain, integral rate and derivative rate come from the a set while charging_voltage_error is below battery_voltage_delta_threshold_cal and from the b set otherwise; the p term (error x gain), the integral term (integrator preset from the duty on the 1 -> 2 transition, clamped 0..25600) and the d term ((error - previous error) x rate) are summed, clamped to 0..25600 and written to alternator_field_duty_target. (was cm848_calculateProtectionOutputDemand)",
   "Direct reading; all working variables (cruise_speed_roc_integrator, battery_voltage_p_term / d_term ...) are used only here and in the init, and the result feeds cm848_applyAlternatorFieldDuty. Dump calibration: threshold 4, gains 35 / 80, integral rates 65 / 5, derivative rates 0 / 0. The wave-1 G3 agent suggested cm848_calculateAlternatorFieldDutyPid; the ByPid spelling pairs with cm848_calculateAlternatorFieldDutyByRegulatorState.")
fn("0x00037f28", "cm848_checkProtectionOutputConditions", "confirmed", "cm848_monitorChargingSystemVoltageHighAndLow",
   "Charging system voltage monitor: sets fault_detected_bits_368_to_383 mask 2 (P2504, voltage high) when the regulator is not in state 0, no protection voltage is active and charging_voltage_error_slow_average stays below battery_voltage_cruise_check_threshold_cal (-16 = measured voltage more than 1 V above the target) for cruise_check_sample_count_max_cal passes (150) and a timer then counts cruise_monitor_timer_max_cal passes (6); sets mask 4 (P2503, voltage low) after cruise_enable_sample_count_max_cal passes (80) in regulator state 2 with the grid heater control in state 5 (shutdown) and battery voltage below battery_voltage_low_threshold_cal (184 = 11.5 V); clears mask 4 after cruise_sensor_sample_count_max_cal passes (50) above battery_voltage_sensor_threshold_cal (192 = 12.0 V). (was cm848_checkProtectionOutputConditions)",
   "Not in the lead list; found while tracing the chain. Bits 1 / 2 of word 23 are P2504 / P2503 in the fault decode (high / low), matching the direction of each test; thresholds read from the RAM dump. Skip this row if the chain is reviewed elsewhere.")
fn("0x00038120", "cm848_processProtectionMode2", "confirmed", "cm848_testAlternatorOutputByCuttingField",
   "Alternator output test: in regulator state 2 with the grid heater in state 5 (shutdown), engine speed above battery_voltage_sample_rpm_threshold_cal, no charging fault set and charging_voltage_error_slow_average above battery_voltage_sample_threshold_cal it counts passes; once the count reaches battery_voltage_sample_count_max_cal a second counter starts and, when it equals battery_fault_sample_count_threshold_cal, the battery voltage is snapshotted and battery_voltage_fault_flag is set, which makes cm848_applyAlternatorFieldDuty cut the field duty to 0. The test clears if the voltage then falls by more than battery_fault_clear_delta_cal; otherwise after cruise_enable_count_threshold_cal passes it counts a failed test and releases the field, and fault 368 (P2502) is set when the failed tests reach cruise_confirm_threshold_cal. The thresholds in the RAM dump (8000 rpm, 640, 65535) keep it from ever tripping. (was cm848_processProtectionMode2)",
   "Not in the lead list; behaviour read from the code. battery_voltage_fault_flag (0x40b264) is read in cm848_applyAlternatorFieldDuty, where it forces alternator_field_duty_target to 0 (xref_addr.py: 1 read there, 4 writes plus 1 read in this function, 1 write in the init), so the function really cuts the field and watches the voltage fall; thresholds read from the RAM dump. Skip this row if the chain is reviewed elsewhere.")

# ---------------- charging globals ----------------
gl("0x004087fa", "protection_fuel_output_idle_cal", "alternator_field_duty_while_charging_system_fault_368_set",
   "Read only in regulator state 0 of cm848_calculateAlternatorFieldDutyByRegulatorState, where alternator_field_duty_target = this value, then forced to 0 unless fault_detected_bits_368_to_383 mask 1 (fault 368, P2502) is set; all four state handlers return to state 0 whenever that fault is set, and masks 2 / 4 (faults 369 / 370) do not select this value. 0 in the dump; 0x4087fa is outside the EEPROM mirror, so no _cal. The only direct setter of fault 368 found by a name grep is cm848_testAlternatorOutputByCuttingField, so the name says the fault number instead of a meaning.")
gl("0x003fd5ee", "operating_mode_flags", "operating_mode_flags_cal",
   "0x3fd5ee is inside the EEPROM mirror 0x3fd482-0x3feec1 (EEPROM 0x16c holds the same word, 0x7ca6, as the RAM dump), so the name needs _cal. Bit uses in the decompile: 0x20 charging PID (cm848_calculateAlternatorFieldDutyByPid), 0x200 heater performance test, 0x400 overboost monitor, plus 0x1 / 0x2 / 0x4 / 0x10 / 0x40 / 0x100 / 0x800 / 0x1000 / 0x2000 / 0x8000 elsewhere; each bit enables one function, so a feature-enable reading may fit better than operating mode but the bits are not all traced.")
gl("0x003fb39e", "cruise_speed_roc_integrator", "alternator_field_duty_pid_integrator",
   "Used only in cm848_calculateAlternatorFieldDutyByPid (integral rate x error added each pass, preset from the duty x 0x640 / 0x100 on the 1 -> 2 transition, 160000 = full 25600 duty); dword. Nothing to do with cruise.")
gl("0x0040b27a", "cruise_integral_clamp_value", "alternator_field_duty_pid_integral_term",
   "integrator x 0x100 / 0x640 clamped to 0..25600 in cm848_calculateAlternatorFieldDutyByPid, added into the duty sum; cleared in cm848_initProtectionFilterValues; no other user.")
gl("0x0040b280", "battery_voltage_p_term", "alternator_field_duty_pid_proportional_term",
   "(charging_voltage_error x gain x 0x100) >> 4 in cm848_calculateAlternatorFieldDutyByPid, summed into alternator_field_duty_target; write-only otherwise.")
gl("0x0040b276", "battery_voltage_d_term", "alternator_field_duty_pid_derivative_term",
   "(error - previous error) x derivative rate x 0x100 / 0x640 in cm848_calculateAlternatorFieldDutyByPid, summed into the duty; no other reader.")
gl("0x003fb3a2", "battery_voltage_gain_working", "alternator_field_duty_pid_proportional_gain_working",
   "Loaded from battery_voltage_gain_a_cal or _b_cal by the error threshold test and multiplied into the p term; used only in cm848_calculateAlternatorFieldDutyByPid.")
gl("0x003fb3a4", "battery_voltage_integral_rate_working", "alternator_field_duty_pid_integral_rate_working",
   "Loaded from the a / b integral rate calibration and multiplied by the error into the integrator; dword; used only in cm848_calculateAlternatorFieldDutyByPid.")
gl("0x003fb3a8", "battery_voltage_ema_rate_working", "alternator_field_duty_pid_derivative_rate_working",
   "Loaded from the a / b rate calibration and multiplied by (error - previous error) for the d term; not an EMA rate; used only in cm848_calculateAlternatorFieldDutyByPid.")
gl("0x003fb3aa", "battery_voltage_delta_snapshot", "charging_voltage_error_previous",
   "Written in cm848_calculateChargingVoltageError as the copy of charging_voltage_error before it is updated and read as the previous error in the PID derivative; no other user.")
gl("0x004087e6", "battery_voltage_delta_threshold_cal", "alternator_field_duty_pid_gain_set_error_threshold",
   "Read once in cm848_calculateAlternatorFieldDutyByPid: error below it selects the a gain set, otherwise the b set; 4 (0.25 V) in the dump. Address 0x4087e6 is outside the EEPROM mirror, so no _cal.")
gl("0x004087a0", "battery_voltage_filter_coeff_cal", "charging_voltage_error_slow_average_coefficient",
   "Weight of the new error sample (coefficient / 65536) in the charging_voltage_error_slow_average update, used only in cm848_calculateChargingVoltageError; 64881 = 0.99 in the dump, so this slow average hardly lags. Outside the EEPROM mirror, so no _cal; same pattern as alternator_field_duty_slow_average_coefficient.")
gl("0x004087c4", "battery_voltage_cruise_check_threshold_cal", "charging_system_voltage_high_error_threshold",
   "Signed 1/16 V threshold (-16 in the dump) that charging_voltage_error_slow_average must stay below for the voltage-high fault (P2504); used only in cm848_monitorChargingSystemVoltageHighAndLow.")
gl("0x004087c8", "cruise_check_sample_count_max_cal", "charging_system_voltage_high_confirm_passes",
   "Passes the voltage-high condition must hold (150 in the dump) before the fault timer starts counting; used only in the high / low monitor.")
gl("0x004087c6", "cruise_monitor_timer_max_cal", "charging_system_voltage_high_fault_count_limit",
   "Timer count (6 in the dump) at which the monitor sets the voltage-high fault (P2504); used only in the high / low monitor.")
gl("0x004087cc", "battery_voltage_low_threshold_cal", "charging_system_voltage_low_threshold",
   "Battery voltage (1/16 V, 184 = 11.5 V in the dump) below which the voltage-low condition counts in regulator state 2; used only in the high / low monitor.")
gl("0x004087d0", "cruise_enable_sample_count_max_cal", "charging_system_voltage_low_confirm_passes",
   "Passes of the voltage-low condition (80 in the dump) that set fault mask 4 (P2503); used only in the high / low monitor.")
gl("0x004087ca", "battery_voltage_sensor_threshold_cal", "charging_system_voltage_low_clear_threshold",
   "Battery voltage (1/16 V, 192 = 12.0 V in the dump) that must be exceeded to clear the voltage-low fault; used only in the high / low monitor.")
gl("0x004087ce", "cruise_sensor_sample_count_max_cal", "charging_system_voltage_low_clear_passes",
   "Passes above the clear threshold (50 in the dump) that clear fault mask 4 (P2503); used only in the high / low monitor.")

# ---------------- wastegate duty globals ----------------
gl("0x003fa17a", "throttle_rate_integrator", "wastegate_duty_integrator_q16",
   "The PI integrator of cm848_calculateWastegateDutyRequest: error x gain / 100 added in 16.16 fixed point while the enable flag is set, clamped to the upper / lower limit words << 16, preset to -(rate-limited term) << 16 by the reset flag; zeroed in the controller init; dword in both users.")
gl("0x0040a3c0", "throttle_rate_integrator_hi", "wastegate_duty_integrator_whole_counts",
   "integrator >> 16 in cm848_calculateWastegateDutyRequest, the integrator contribution (half-duty counts) added to the base and rate-limited terms before the floor / ceiling clamp; no other user.")
gl("0x003fa1aa", "throttle_acceleration_active_flag", "wastegate_duty_integrator_enable_flag",
   "Written only by cm848_checkSpeedBandCondition (anti-windup) and read once in cm848_calculateWastegateDutyRequest, where it gates the integrator update; nothing to do with acceleration.")
gl("0x003fa1a4", "governor_speed_error_working", "wastegate_duty_integrator_input",
   "selected control term x integral gain >> 10, clamped to +-32767, written in cm848_calculateWastegateDutyRequest and the amount added to the integrator; its sign is the direction tested by the anti-windup in cm848_checkSpeedBandCondition. Used in those two functions only.")
gl("0x0040a3c4", "governor_adjustment_gain", "wastegate_duty_integral_gain",
   "wastegate_integrator_gain_by_error_* lookup x throttle_rate_scale_factor_cal >> 12 in cm848_calculateWastegateDutyRequest, then multiplied into the control term for the integrator input; no other user.")
gl("0x003ffc9c", "throttle_rate_integrator_upper_cal", "wastegate_duty_integrator_upper_limit",
   "Upper clamp of the wastegate duty integrator (value << 16 against the Q16 integrator); 10240 = 80 percent in half-duty counts in the dump; read only in cm848_calculateWastegateDutyRequest. 0x3ffc9c is above the EEPROM mirror, so no _cal.")
gl("0x003ffc9a", "throttle_rate_integrator_lower_cal", "wastegate_duty_integrator_lower_limit",
   "Lower clamp of the wastegate duty integrator; -12800 (word 52736) = -100 percent in half-duty counts in the dump; read only in cm848_calculateWastegateDutyRequest. Above the EEPROM mirror, so no _cal.")
gl("0x0040a162", "boost_pressure_fuel_working", "barometric_pressure_selected",
   "Written from sensor_channel3_value, or sensor_channel3_default_value when the sensor channel 3 gate trips; the gate tests fault_detected_bits_16_to_31 masks 0x200 / 0x400 = P0108 / P0107 (the barometric pressure circuit faults in the fault decode) and a second fault gate on fault_detected_bits_336_to_351 mask 0x10. It feeds barometric_pressure_reference (plus boost_fuel_pressure_offset_lookup) in hpcr_fuelFinal_exponentialAverage; dump: 1648 against sensor_readings_t.barometric_pressure 1647 and intake_manifold_pressure 1700, so it is not a boost pressure. xref_addr.py: 3 reads / 3 writes. Lead from the wave-1 G3 agent, candidate name theirs.")

# ---------------- new globals ----------------
ng("0x004087a8", "alternator_field_regulator_start_engine_speed_threshold", "word",
   "State 0 handler (ROM 0x38338) moves to state 1 when engine speed (0x40b7ba) >= this (lhz) or cold_start_phase = 3, and fault 368 is clear; 3200 = 400 rpm (0.125 rpm per count) in the dump. xref_addr.py shows nothing (handler code is not decompiled); disasm_func.py 0x38338 shows one lhz read.")
ng("0x004087a2", "alternator_field_regulator_stop_engine_speed_threshold", "word",
   "States 1, 2 and 3 (ROM 0x38384 / 0x383f0 / 0x3844c) fall back to state 0 when engine speed < this; 2880 = 360 rpm in the dump. Width: three lhz reads in disasm_func.py (xref_addr.py has no hits, the handlers are LAB_ code).")
ng("0x004087ac", "alternator_field_load_response_fast_error_threshold", "i16",
   "State 2 handler (ROM 0x383f0) enters state 3 (load response) when charging_voltage_error_fast_component exceeds this; 192 (12 V) in the dump, i.e. state 3 cannot be entered in this calibration. Signed: lha read in disasm_func.py.")
ng("0x004087ae", "alternator_field_regulation_error_threshold", "i16",
   "State 1 and state 3 handlers go to / stay in regulation (state 2) when charging_voltage_error <= this and stay in state 3 while the error is above it; 1 (1/16 V) in the dump. Signed: two lha reads in disasm_func.py.")
ng("0x004087b0", "alternator_field_load_response_full_duty_passes_limit", "word",
   "State 3 handler (ROM 0x3844c) returns to state 2 when the duty is 25600 and alternator_field_load_response_elapsed_passes exceeds this; 11 in the dump. One lhz read in disasm_func.py.")
ng("0x00409fe0", "wastegate_monitor_driver_duty_threshold", "word",
   "cm848_monitorWastegateBoostPressure counts the high-boost fault only while wastegate_solenoid_duty_command <= this; 11520 = 45 percent of 25600 in the dump. e2m CWG_Driver_Duty_Cycle_Threshold (0x011B2E00, Duty cycle threshold for wastegate error check); the e2m CWG block at 0x011B2E00 lines up by relative offset with 0x409fe0 (+2 high boost time = wastegate_monitor_debounce_count_limit, +4 high load, +6 minimum engine speed = wastegate_monitor_minimum_engine_speed_threshold, +8 minimum start battery temperature). xref_addr.py says word (1 read / 0 writes), lhz.")
ng("0x00409fe4", "wastegate_monitor_pass_high_load_threshold", "word",
   "The pass-window check of cm848_monitorWastegateBoostPressure requires engine_load_percent >= this; 19200 = 75 percent in 1/256 percent units in the dump. e2m CWG_High_Load_Threshold (0x011B2E04, %LOAD, 0.00390625, Percent load threshold for wastegate pass check). xref_addr.py says word (1 read / 0 writes), lhz.")
ng("0x00409fe8", "wastegate_monitor_minimum_start_battery_temperature_threshold", "i16",
   "cm848_initAdaptiveControl sets the monitor armed flag to (this <= battery_temperature_sensor_filtered); 1280 = 20 F (1/64 F) in the dump. e2m CWG_Min_Start_Battery_Temp_Threshold (0x011B2E08, DEG_F 0.015625, Min battery temp at start-up to run electronic wastegate rationality). xref_addr.py says word (1 read / 0 writes), signed lha in the code, so i16.")
ng("0x003fd270", "wastegate_monitor_armed_flag", "byte",
   "Byte set once in cm848_initAdaptiveControl (battery temperature at start >= the minimum start temperature) and read at the top of cm848_monitorWastegateBoostPressure, which returns while it is 0; 1 in the dump. xref_addr.py says byte (1 read / 1 write). Working RAM below the EEPROM mirror, so no _cal.")
ng("0x00064424", "intake_air_heater_performance_test_ring_sample_delay_ticks", "word",
   "Loaded into the dwell counter at the end of state 1 and gates the ring sampling of state 2; 30 in ROM (cm848_rom.bin). xref_addr.py: word (1 read / 0 writes).")
ng("0x00064426", "intake_air_heater_performance_test_preheat_end_remaining_ticks", "word",
   "State 2 keeps sampling while intake_air_heater_preheat_remaining_ticks > this and goes to state 3 (heater off) when the remaining ticks fall below it; 1 in ROM. xref_addr.py: word (1 read).")
ng("0x0006442a", "intake_air_heater_performance_test_loaded_sample_delay_ticks", "word",
   "Loaded into the dwell counter after the baseline average (state 0 -> 1) and gates the loaded-voltage sampling of state 1; 25 in ROM. xref_addr.py: word (1 read).")
ng("0x0006442c", "intake_air_heater_performance_test_baseline_sample_delay_ticks", "word",
   "Initial dwell loaded by cm848_armIntakeAirHeaterPerformanceTest; state 0 counts it down while preheat is on before taking the baseline battery voltage samples; 2 in ROM. xref_addr.py: word (1 read; also stored into the dwell counter).")
ng("0x0006442e", "intake_air_heater_performance_test_loaded_voltage_lower_window_adc", "word",
   "State 2 aborts (state 6) when the ring average falls below the loaded average minus this; 15 ADC counts in ROM. xref_addr.py: word (1 read).")
ng("0x00064430", "intake_air_heater_performance_test_drop_recovery_agreement_window_adc", "word",
   "State 3: the turn-on voltage drop and the turn-off recovery must differ by less than this (10 ADC counts in ROM) or the test ends in state 6. xref_addr.py: word (2 reads in the function, 1 listed).")
ng("0x00064432", "intake_air_heater_performance_test_minimum_intake_manifold_temperature", "i16",
   "The abort check ends the test when intake_manifold_temperature_sensor_filtered (1/64 F) is below this; 0 = 0 F in ROM. xref_addr.py: word (1 read), signed lha in the code, so i16.")
ng("0x00064434", "intake_air_heater_performance_test_maximum_battery_voltage", "word",
   "Abort check: battery voltage (1/16 V per count) above this ends the test; 208 = 13 V in ROM. xref_addr.py: word (1 read), lhz.")
ng("0x00064436", "intake_air_heater_performance_test_minimum_battery_voltage", "word",
   "Abort check: battery voltage (1/16 V per count) below this ends the test; 160 = 10 V in ROM. xref_addr.py: word (1 read), lhz.")
ng("0x00064438", "intake_air_heater_performance_test_loaded_voltage_upper_window_adc", "word",
   "State 2 aborts when the ring average rises above the loaded average plus this; 10 ADC counts in ROM. xref_addr.py: word (1 read).")
ng("0x0006443a", "intake_air_heater_performance_test_arming_temperature_difference_limit", "word",
   "cm848_armIntakeAirHeaterPerformanceTest arms only when |battery temperature - intake manifold temperature| <= this; 640 = 10 F (1/64 F) in ROM. xref_addr.py: word (1 read), lhz.")
ng("0x0040b9e6", "intake_air_heater_performance_test_recovery_voltage_rise_adc", "word",
   "Written in state 3 of cm848_monitorIntakeAirHeaterPerformance as (recovered average - loaded average), the recovery after the heater turns off, and compared with the turn-on drop; store only (xref_addr.py: word, 0 reads / 1 write), typed word like its siblings.")
ng("0x003fd1ee", "intake_air_heater_performance_test_ring_average_battery_voltage_adc", "word",
   "Average of the three ring samples (state 2), compared with the loaded average and copied into intake_air_heater_performance_test_loaded_battery_voltage_adc at the end of state 2; xref_addr.py: word (1 read / 3 writes), only cm848_monitorIntakeAirHeaterPerformance.")
ng("0x0040bd0a", "battery_temperature_adc_forced_reading", "word",
   "Slot 69 of the forced-reading array that starts at 0x40bc80 (2 bytes per slot: 0x40bd0a - 0x40bc80 = 138 = 2 x 69; slot 4 = 0x40bc88 = battery_voltage_adc_forced_reading); the SCI case 1 code reads DAT_0040bd0a unless word +80 of diagnostic_service_dispatch_table has mask 0x20 clear, with qadc_channel_index_table[0x45] (= 69) as the live channel; slot 69 is battery_temperature_sensor_filtered (sensor_channel_filtered_output[69]). xref_addr.py: word (1 read / 0 writes), cm848_sciCommand20Callback only.")

# ---------------- struct fields ----------------
sf("commanded_rpm", "request_half_duty_counts",
   "Final output of cm848_calculateWastegateDutyRequest = clamp(base + rate-limited term + integrator, floor, ceiling); 2 x it is the solenoid duty (cm848_applyWastegateSolenoidDuty), 12800 = 100 percent; 10896 in the dump (21792 = 2 x 10896 = wastegate_solenoid_duty_command). Readers: output stage, anti-windup, cm848_calculateSpeedControlLimit; also zeroed by the init.")
sf("reserved_02", "selected_control_term",
   "Min-select of the candidate terms throttle_rate_filtered_sum, reserved_04 (when throttle_rate_filter_active_flag) and governor_rpm_state_output (when governor_rpm_output_enable_flag); it is the rate-limiter input and, times the integral gain, the integrator input (3 reads / 2 writes, all in the controller). The wave-1 G3 agent called it the feedback limit. Medium confidence on the word term versus error.")
sf("reserved_04", "first_error_proportional_derivative_term",
   "clamp(error x reserved_06 x throttle_rate_pid_gain_cal word 0 (._0_2_) / 64000 - governor_pid_adjustment_output, +-25600) with error = fuel_pressure_demand_reference - fuel_demand_quantity (the first of two error pairs; the second is fuel_flow_rate_reference - fuel_flow_rate); one write, the value is then used from a register. The e2m has no block that lines up with 0x40a3ca-0x40a3de (grep of CWG / wastegate), and the two input pairs were not traced to a physical quantity, so the name stays domain-neutral.")
sf("reserved_06", "first_error_gain",
   "lookupTableInterpolation of that same first error through WORD_ARRAY_003ffcb6 / WORD_ARRAY_003ffcca (an error-dependent gain, multiplied into reserved_04); written once, no other reader. Domain-neutral for the reason given for reserved_04.")
sf("lower_rpm_limit", "floor_half_duty_counts",
   "Duty floor: wastegate_duty_floor_fixed or the floor grid lookup (reserved_0e) plus the altitude trim in the normal mode, or throttle_rate_pid_gain_cal word 1 (._2_2_) when fuel_mode_switch_state is non-zero; 128 (1 percent) in the dump; the lower clamp of commanded_rpm and the anti-windup floor test.")
sf("limit_adjustment", "floor_altitude_adjustment_half_duty_counts",
   "lookupTableInterpolation(barometric_altitude_feet, wastegate_duty_floor_adjustment_by_altitude_*): added to the floor when wastegate_duty_altitude_adjustment_enable_cal is non-zero; one write, one read in the controller.")
sf("reserved_0c", "ceiling_grid_lookup_half_duty_counts",
   "cm848_dualAxisTableInterpolation of engine speed x engine_load_input_b through wastegate_duty_ceiling_grid; becomes the ceiling when wastegate_duty_ceiling_grid_enable_cal is non-zero (the grid is unused in the dump).")
sf("reserved_0e", "floor_grid_lookup_half_duty_counts",
   "cm848_dualAxisTableInterpolation of engine speed x engine_load_input_b through wastegate_duty_floor_grid; becomes the floor when wastegate_duty_floor_grid_enable_cal is non-zero (unused in the dump).")
sf("desired_rpm", "ceiling_half_duty_counts",
   "Duty ceiling: wastegate_duty_ceiling_fixed x the battery-voltage gain / 4096 (or the ceiling grid lookup) plus the altitude trim, clamped 0..12800, or base_rpm_lookup when fuel_mode_switch_state is non-zero; 10896 = 9600 x 4649 / 4096 in the dump, so commanded_rpm is pinned at it; the upper clamp of commanded_rpm and the anti-windup ceiling test.")
sf("adjustment_delta", "ceiling_altitude_adjustment_half_duty_counts",
   "lookupTableInterpolation(barometric_altitude_feet, wastegate_duty_ceiling_adjustment_by_altitude_*): added to the ceiling when wastegate_duty_altitude_adjustment_enable_cal is non-zero; one write, one read in the controller.")
sf("base_rpm_lookup", "engine_speed_ceiling_half_duty_counts",
   "lookupTableInterpolation(engine speed, wastegate_duty_ceiling_engine_speed_axis, governor_base_rpm_output_cal): copied into desired_rpm only when fuel_mode_switch_state is non-zero (0 in the dump); one write, the read is through a register.")

# ---------------- notes ----------------
note("Struct name: rpm_governor_state_t should become wastegate_duty_controller_state_t (the wave-1 G3 agent suggested wastegate_duty_state_t). All 11 words of the struct at 0x40a3ca are written only by cm848_calculateWastegateDutyRequest (plus commanded_rpm = 0 in the init) and read only by that function, cm848_checkSpeedBandCondition, cm848_applyWastegateSolenoidDuty (2 x commanded_rpm) and cm848_calculateSpeedControlLimit; the dump (commanded 10896 = desired 10896, lower 128) matches the wastegate duty path. The instance row rpm_governor_state_t_0040a3ca and its 10 sub-rows (global_variables.csv lines 4526-4536) and the Gap comments (reserved_*) in structure_definitions.csv need the same rename; the field comments should say that every field is in half-duty counts (12800 = 100 percent) except reserved_02 / reserved_04 / reserved_06. Caveat: cm848_calculateSpeedControlLimit (left uncertain) passes commanded_rpm into a governor speed and fuel chain in the same duty units (fuel_control_setpoint_working, 10896 in the dump, ending in governor_fuel_demand_raw and cm848_selectFuelControlModeOutput); the wastegate reading does not depend on it (the only writer of the word is the wastegate controller, the only actuator reader is the wastegate output stage) but that chain needs its own review before the struct name is final.")
note("Convention used in this file: plate_comment texts use the proposed new names (the old name only in the trailing was clause) so they read correctly once all rows of this file are applied together; evidence and note lines use the current CSV names unless they say new. Plates avoid struct field names, so they stay valid whether or not the struct rename is taken.")
note("Lead tails: the task file cuts every G3 note at 427 characters; the full notes were read from result_G3.jsonl (wave 1). All tails are covered above: the field list of the struct note, the second reader (uncertain, same conclusion), the wrapper / init names (the G3 agent suggested cm848_runWastegateDutyControl / cm848_initWastegateDutyControl, I propose ...Controller / cm848_initializeWastegateDutyController), the charging chain (G3 suggested cm848_calculateAlternatorFieldDutyPid, I propose ...ByPid), the DAT_ list, the heater names (G3 suggested cm848_checkIntakeAirHeaterPerformanceTestConditions for the abort check; mine says what it does) and boost_pressure_fuel_working. Not named: DAT_003fd271 / 003fd273 / 003fd275 (lookup hint words of the three wastegate monitor tables, set to 2 in cm848_initAdaptiveControl) and DAT_00064428.")
note("Overlap with the G4 group: the [G4] note (line 170 of the task file) also mentions cm848_processProtectionVoltageOffset and cm848_dispatchProtectionOutputMode as the same charging regulator; result_G4.jsonl has no rename row for them, and the names proposed here (cm848_calculateChargingVoltageError / cm848_updateAlternatorFieldRegulatorState) are the ones the G3 agent suggested. battery_voltage_correction_enable_cal belongs to the G4 lead and is not touched here. No overlap with the other wave-3 result files (duplicates, governor, injection, rail).")
note("Type issues (note only, no type change proposed in the rows): battery_voltage_cruise_check_threshold_cal (0x4087c4, -16 in the dump) is compared as a signed short in the decompile and wants i16; throttle_rate_integrator_lower_cal (0x3ffc9a, -12800) and throttle_rate_integrator_upper_cal (0x3ffc9c, 10240) are used as signed shorts and want i16; throttle_rate_pid_gain_cal (0x3ffcaa, dword) holds two words, word 0 (._0_2_) = 128 (multiplier of the first error term, divided by 64000) and word 1 (._2_2_) = 1280 (the floor used when fuel_mode_switch_state is non-zero), shown in the decompile as throttle_rate_pid_gain_cal._0_2_ / ._2_2_. governor_base_rpm_output_cal (word[20], 0x40027a, no EEPROM so no _cal) is the data table behind base_rpm_lookup and governor_trim_rpm_axis_cal / governor_trim_output_cal (0x4002a2 / 0x4002b6) are the error-to-gain table of the second error term; their names are still governor names.")
note("Not renamed in the wastegate controller (insufficient evidence): throttle_rate_integrator_prev (0x40a3c2: the second half of the cm848_calculateRateLimitedValue result, added into the output sum and used to preset the integrator) and governor_rpm_band_rate_working / _target (rate limiter state and target), throttle_rate_integrator_cal (0x3ffca6, 0 in the dump) and its snapshot (the base term of the output sum), and the inputs fuel_pressure_demand_reference (written by cm848_calculateTurboRatioWithMode) / fuel_demand_quantity (written by fuel_demandSource_modeSelect) and fuel_flow_rate_reference / fuel_flow_rate, which were not traced to a physical quantity. Three flags in the EEPROM mirror lack _cal: throttle_rate_integrator_reset_flag (0x3fd7dc, 0 in the dump; nonzero presets the integrator to minus the rate-limited term and when equal to 1 the output is just the base term), throttle_rate_filter_active_flag (0x3fd7de, 1; also read by cm848_calculateTurboBlendOutput) and governor_rpm_output_enable_flag (0x3fd7e6, 1); they belong in the _cal sweep with domain names.")
note("Charging regulator transitions, from the disassembly of the handlers (ROM 0x38338 / 0x38384 / 0x383f0 / 0x3844c, lead confirmed): 0 -> 1 when engine speed >= word 0x4087a8 (3200 = 400 rpm) or cold_start_phase = 3, and fault 368 clear; every state returns to 0 when speed < word 0x4087a2 (2880 = 360 rpm) or fault 368 is set; 1 -> 2 when the duty is 25600 or charging_voltage_error <= word 0x4087ae (1); 2 -> 3 when charging_voltage_error_fast_component > word 0x4087ac (192, never in this calibration); 3 -> 2 when the duty is 25600 and alternator_field_load_response_elapsed_passes > word 0x4087b0 (11) or when the error is <= word 0x4087ae. The handlers are LAB_ code with no function definition, so they cannot be renamed.")
note("Charging chain facts: the only direct setter of fault 368 (P2502) found by a name grep of fault_detected_bits_368_to_383 is cm848_testAlternatorOutputByCuttingField (an indexed write would not show), whose thresholds in the dump (8000 rpm at 0x4087ba, 65535 passes at 0x4087b6 / 0x4087b8 / 0x4087be, 640 at 0x4087c2) keep it from ever tripping, so alternator_field_duty_while_charging_system_fault_368_set is moot here. charging_voltage_error_slow_average_coefficient is 64881 / 65536 = 0.99, so the slow average follows the error almost one to one and the fast component stays near 0 (state 3 is effectively off). Still-misnamed a / b gain sets read only by cm848_calculateAlternatorFieldDutyByPid (no _cal outside the EEPROM mirror): battery_voltage_gain_a_cal / _b_cal (0x4087e8 / 0x4087ea = 35 / 80) = proportional gains for error below / at or above the threshold, battery_voltage_integral_rate_a_cal / _b_cal (0x4087de / 0x4087e2, dword = 65 / 5) = integral rates, battery_voltage_ema_rate_a_cal / _b_cal (0x4087d6 / 0x4087d8 = 0 / 0) = derivative rates; the other cruise_* / battery_voltage_* words in 0x4087b6-0x4087c2 belong to cm848_testAlternatorOutputByCuttingField; the RAM counters cruise_check_sample_count, cruise_monitor_timer, cruise_enable_sample_count(_b) and cruise_sensor_sample_count are charging monitor counters too. protection_fuel_output_target_prev (0x40b27e) is written (PID and init) and never read.")
note("Existing CSV comment to fix: alternator_field_duty_target (0x40b266) says it is filtered by cm848_calculateAlternatorFieldDutyByRegulatorState, which does not filter it. Suggested text (new names): Alternator field duty target (25600 = 100 percent): set per regulator state by cm848_calculateAlternatorFieldDutyByRegulatorState (clamped to 25600) and, in states 2 and 3 when operating_mode_flags_cal mask 0x20 is set, replaced by cm848_calculateAlternatorFieldDutyByPid; cm848_applyAlternatorFieldDuty overrides, inverts and snaps it and sends it to the field.")
note("Feature enable words (G3 lead tail): the dump value of operating_mode_flags_cal is 0x7ca6 (0x20 charging PID and 0x400 overboost monitor set, 0x200 heater performance test clear), so cm848_monitorIntakeAirHeaterPerformance never leaves state 0 on this truck and the charging PID is active. cold_start_feature_flags (0x3fd5c2, EEPROM mirror, so it also lacks _cal; @CSFF@ in the dump) mask 0x8 and protection_feature_status_flags (0x40b9d0, runtime RAM, dword; @PFSF@ in the dump) mask 0x1000000 are the first two gates of cm848_monitorWastegateBoostPressure (seen in the code); the wave-1 reading that 0x1000000 means wastegate monitor armed and 0x4 overboost monitor armed was not traced to its setters, so no rename is proposed.")
note("Heater test: DAT_00064428 (2) is loaded into the dwell counter when state 2 hands over to state 3, but state 3 only counts it down and no test reads it as a gate, so it is not named. The three-element sample ring starts at DAT_003fd1f6 and is indexed 1..3 (words 0x3fd1f8-0x3fd1fc), a word[4] array typing note only. The fault decode behind the abort conditions: bits_16_to_31 b3 / b4 = P0113 / P0112 (intake air temperature circuit), bits_288_to_303 b6 / b7 / b8 / b9 = P0541 / P0542 / P2607 / P2608 (grid heater circuits), bits_368_to_383 b11 / b12 = P0517 / P0516 (battery temperature).")
note("barometric_pressure_selected follow-up: sensor_channel3_value (0x40bd82), sensor_channel3_default_value (0x40bd9a) and sensor_channel3_fault_status are the live value, default value and fault state of the same barometric channel (the gate that selects between them tests the P0107 / P0108 faults), so their boost-pressure style names should follow in one change; not traced further here.")
note("Array typing (a type change, so a note only): the forced-reading words start at 0x40bc80, one word per sensor slot (slot 4 = 0x40bc88 battery_voltage_adc_forced_reading, slot 69 = 0x40bd0a battery_temperature_adc_forced_reading; checked: 0x40bc88 - 0x40bc80 = 8 = 2 x 4 and 0x40bd0a - 0x40bc80 = 138 = 2 x 69); the override enable of slot n is bit (n mod 16) of word (n / 16) of diagnostic_service_dispatch_table starting at +72 (slot 4 = +72 mask 0x10 seen in the heater test, slot 69 = +80 mask 0x20 seen in SCI case 1). Candidate type word[70] or longer; the array length was not established.")

# ---------------- plate comments use the new names ----------------
mapping = {}
for d in R:
    if d["kind"] in ("function", "global") and d.get("new"):
        mapping[d["old"]] = d["new"]
    if d["kind"] == "new_global":
        mapping["DAT_%08x" % int(d["address"], 16)] = d["new"]
pat = re.compile(r"(?<![\w.])(" + "|".join(re.escape(k) for k in sorted(mapping, key=len, reverse=True)) + r")(?![\w])")


def newify(text):
    head, sep, tail = text.rpartition(" (was ")
    if not sep:
        head, tail = text, ""
    head = pat.sub(lambda mo: mapping[mo.group(1)], head)
    return head + sep + tail


for d in R:
    if d["kind"] == "function" and d.get("plate_comment"):
        d["plate_comment"] = newify(d["plate_comment"])

# ---------------- placeholders in notes from the RAM dump ----------------
for d in R:
    if d["kind"] == "note":
        d["text"] = d["text"].replace("@CSFF@", "0x%04x" % ramword(0x3FD5C2))
        hi, lo = ramword(0x40B9D0), ramword(0x40B9D2)
        d["text"] = d["text"].replace("@PFSF@", "0x%04x%04x" % (hi, lo))


# ---------------- collision / consistency checks ----------------
def rows(path):
    return [r for r in csv.reader(l for l in open(FW + path, errors="replace") if not l.startswith("#")) if r]


gv = rows("global_variables.csv")
fr = rows("function_renames.csv")
ar = rows("arrays.csv")
names = collections.Counter()
for r in gv + fr + ar:
    if len(r) > 1:
        names[r[1].strip()] += 1
gv_by_addr = {int(r[0], 16): r[1].strip() for r in gv if re.match(r"0x[0-9a-fA-F]+$", r[0].strip())}
fr_by_addr = {int(r[0], 16): r[1].strip() for r in fr if re.match(r"0x[0-9a-fA-F]+$", r[0].strip())}
bad = []
seen_new = collections.Counter()
for d in R:
    if d["kind"] in ("function", "global", "new_global") and d.get("new"):
        seen_new[d["new"]] += 1
        if names.get(d["new"]):
            bad.append(("EXISTS", d["new"]))
        if len(d["new"]) > 100:
            bad.append(("LONG", d["new"], len(d["new"])))
        if d["kind"] != "function" and re.search(r"0x|[A-Z]", d["new"]):
            bad.append(("CASE/HEX", d["new"]))
    if d["kind"] == "global":
        a = int(d["address"], 16)
        if gv_by_addr.get(a) != d["old"]:
            bad.append(("OLD MISMATCH", d["address"], d["old"], gv_by_addr.get(a)))
        if d["new"].endswith("_cal") and not (0x3fd482 <= a <= 0x3feec1):
            bad.append(("CAL OUTSIDE EEPROM", d["address"], d["new"]))
        if (not d["new"].endswith("_cal")) and 0x3fd482 <= a <= 0x3feec1:
            bad.append(("MISSING _cal IN EEPROM RANGE", d["address"], d["new"]))
    if d["kind"] == "function":
        a = int(d["address"], 16)
        if fr_by_addr.get(a) != d["old"]:
            bad.append(("FN OLD MISMATCH", d["address"], d["old"], fr_by_addr.get(a)))
    if d["kind"] == "new_global":
        a = int(d["address"], 16)
        if a in gv_by_addr:
            bad.append(("ROW EXISTS", d["address"], gv_by_addr[a]))
for n, c in seen_new.items():
    if c > 1:
        bad.append(("DUP NEW", n))
print("problems:", bad)

# ---------------- CM550 shared names ----------------
cm550_files = [ROOT + "firmware/CM550_J90350.00_analysis/output/function_renames.csv",
               ROOT + "firmware/CM550_J90350.00_analysis/output/global_variables.csv",
               ROOT + "docs/cross_firmware_variable_map.csv",
               ROOT + "firmware/cross_firmware_matches.csv"]
olds = sorted({d["old"] for d in R if d["kind"] in ("function", "global") and d.get("new")})
cm550_hits = collections.defaultdict(list)
for f in cm550_files:
    if not os.path.exists(f):
        print("missing", f)
        continue
    text = open(f, errors="replace").read()
    for o in olds:
        if re.search(r"(?<![\w])" + re.escape(o) + r"(?![\w])", text):
            cm550_hits[o].append(os.path.basename(f))
print("CM550 hits:", dict(cm550_hits))
if cm550_hits:
    note("CM550 / cross-firmware references to names retired here (check the CM550 counterpart before renaming): " + "; ".join("%s in %s" % (o, ", ".join(sorted(set(fs)))) for o, fs in sorted(cm550_hits.items())) + ".")
else:
    note("Checked every old function and global name of this file against the CM550 function_renames.csv and global_variables.csv, docs/cross_firmware_variable_map.csv and firmware/cross_firmware_matches.csv: no hits, so no cross-firmware link breaks.")

# ---------------- wave-1 rows that cite names retired here ----------------
ref_names = set(olds) | {"DAT_%08x" % int(d["address"], 16) for d in R if d["kind"] == "new_global"}
rpat = re.compile(r"(?<![\w.])(" + "|".join(re.escape(k) for k in sorted(ref_names, key=len, reverse=True)) + r")(?![\w])")
cited = collections.defaultdict(set)
for line in open(FW + "function_renames.csv", errors="replace"):
    if line.startswith("#"):
        continue
    parts = line.rstrip("\n").split(",", 2)
    if len(parts) == 3:
        head, sep, tail = parts[2].rpartition(" (was ")
        for m in rpat.findall(head if sep else parts[2]):
            if m != parts[1]:
                cited["fn " + parts[1]].add(m)
for line in open(FW + "global_variables.csv", errors="replace"):
    if line.startswith("#"):
        continue
    parts = line.rstrip("\n").split(",", 3)
    if len(parts) == 4:
        head, sep, tail = parts[3].rpartition(" (was ")
        for m in rpat.findall(head if sep else parts[3]):
            if m != parts[1]:
                cited["global " + parts[1]].add(m)
# the rows being renamed here carry their old names in their own first column: skip self references
print("rows citing retired names:", len(cited))
listing = "; ".join("%s cites %s" % (k, ", ".join(sorted(v))) for k, v in sorted(cited.items()))
note("Existing CSV rows (wave-1 plate comments and global comments) that cite names retired by this file and need a reference refresh when the renames are applied (%d rows): %s." % (len(cited), listing[:6000]))

with open(OUT, "w") as f:
    for d in R:
        f.write(json.dumps(d, ensure_ascii=True) + "\n")
cnt = collections.Counter((d["kind"], d.get("verdict")) for d in R)
print(len(R), "lines;", dict(cnt))
