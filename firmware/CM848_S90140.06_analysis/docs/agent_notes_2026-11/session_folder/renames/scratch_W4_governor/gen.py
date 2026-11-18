import csv
import json
import re
import sys

OUT_FILE = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_governor.jsonl'
CSV_DIR = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
rows = []


def F(address, old, new, plate, evidence, verdict='confirmed'):
    row = {'kind': 'function', 'address': address, 'old': old, 'verdict': verdict}
    if new:
        row['new'] = new
    if plate:
        row['plate_comment'] = plate
    row['evidence'] = evidence
    rows.append(row)


def G(address, old, new, evidence, verdict='confirmed'):
    row = {'kind': 'global', 'address': address, 'old': old, 'verdict': verdict}
    if new:
        row['new'] = new
    row['evidence'] = evidence
    rows.append(row)


def NG(address, new, type_, evidence):
    rows.append({'kind': 'new_global', 'address': address, 'new': new, 'type': type_, 'evidence': evidence})


def SF(struct, old, new, evidence):
    rows.append({'kind': 'struct_field', 'struct': struct, 'old': old, 'new': new, 'evidence': evidence})


def N(text):
    rows.append({'kind': 'note', 'text': text})


BOOT = ' Time-shared window: xref_addr.py lists no access below 0x7F60 and a raw scan of the 8152 instructions in ROM 0x0-0x7F60 for the displacement finds none (no boot users; the same scan finds the known boot users of 0x3fdba4 / 0x3fdbb2 / 0x3fee34, so it works).'

# ---------------------------------------------------------------------------------------------
# FAMILY 1: engine retarder (exhaust brake) request arbitration cluster
# ---------------------------------------------------------------------------------------------
N('Convention: plate comments use the PROPOSED new names of globals and functions (engine_retarder_*, service_brake_*, ...) so apply the global renames and the function plates together; evidence lines use the current CSV names. Plates with the was clause replace the old plate.')
N('Retarder cluster domain proof: the dispatcher chain cm848_processTimingDispatcher (0x4218c) ends in the ERC1 request source code / percent (cm848_buildPgn61440ElectronicRetarderController1Message reads engine_retarder_request_source_code and engine_retarder_request_percent) and logical output 11 (cm848_setLogicalOutputRequest(11), the only set of outputs 11-15; 12-15 are only cleared at init). Fault bits 41 / 42, which zero engine_retarder_selection_percent_fault_masked, decode (ROM 0x5985a slot -> obd_dtc_code_table 0x5b57c) to P0478 / P0477 = exhaust pressure control valve high / low, so the retarder here is most likely an exhaust brake. Switch decode (switch n = byte n/8 bit n%8): [1] mask 8 = switch 11 = brake switch, [1] mask 0x80 = switch 15 = clutch switch (firmware/CLAUDE.md), [1] mask 0x10 = switch 12 = the wired retarder selector.')

F('0x00041368', 'cm848_processProtectionSystemBit3', 'cm848_updateEngineRetarderEnableState',
  'Evaluates the engine retarder (exhaust brake) enable conditions once per pass and sets engine_retarder_enable_state: 0 = not wanted or exit condition, 1 = wanted but held off by the pedal, clutch or service brake conditions, 2 = enabled (then engine_retarder_limit_percent restarts at 101 = no limit). It uses the service brake switch with a release delay (service_brake_delayed_active_flag), the torque converter lockup state (tc_lockup_disengage_state), oil temperature, engine speed, boost, fuel demand and governor mode thresholds; it also keeps the arbitrated request of the two previous passes (was cm848_processProtectionSystemBit3).',
  'Read in full (140 lines). Enter / exit flags are built from oil temperature vs engine speed thresholds, boost below a limit, fuel demand at its minimum, lockup state; the state 0 / 1 / 2 assignment follows (S = arbitrated request nonzero, E / X = enter / exit flag, V = driver conditions): 0 for (not S, not E) or (S, X); 1 for (not S, E, not V) or (S, not X, driver inhibit); otherwise 2 with governor_load_percent_min = 101. Called as step 1 of cm848_processTimingDispatcher.')

F('0x00041938', 'cm848_processProtectionSystemBit4', 'cm848_calculateEngineRetarderSelectionPercent',
  'Calculates the operator engine retarder selection percent engine_retarder_selection_percent: 100 or 0 from the wired retarder switch (switch_input_state_bits[1] mask 16), or the J1939 EBC1 retarder selection j1939_engine_retarder_selection_percent when fault_feature_config_flags bit 0 is set, and 100 while the road speed limit is active with operating_mode_flags_cal bit 0 set. engine_retarder_selection_percent_fault_masked is the same value forced to 0 while fault bit 41 or 42 (P0478 / P0477) is detected and engine_feature_enable_flags_cal bit 0x4000 is set; the ERC1 builder uses it for the brake assist bits, and cm848_j1939BuildEngineControlByte sends the percent as EBC1 SPN 973 (was cm848_processProtectionSystemBit4).',
  'Read in full (24 lines). Output words engine_retarder_selection_percent (read by cm848_applyMinimumProtectionLimit and cm848_j1939BuildEngineControlByte, byte 5 = percent x 5 / 2 = 0.4 percent per bit = SPN 973 Engine Retarder Selection, j1939 DB) and _fault_masked (read by the ERC1 builder). Called from cm848_periodicTaskGroup27_calibration9 (the previous wave named both words; lead confirmed).')

F('0x00041a10', 'cm848_applyMinimumProtectionLimit', 'cm848_limitEngineRetarderPercentToOperatorSelection',
  'Lowers the engine retarder percent limit engine_retarder_limit_percent to the operator selection engine_retarder_selection_percent when that is smaller and records limit source code 3 (operator selection, ERC1 retarder torque mode 1) in engine_retarder_limit_source_code. Step 3 of cm848_processEngineRetarderRequest (was cm848_applyMinimumProtectionLimit).',
  'Body is 4 lines: if (selection < limit) { limit = selection; code = 3 }. The source code is mapped to ERC1 SPN 900 = 1 (operator selection) in the ERC1 builder (code 3 -> 1).')

F('0x00041a40', 'cm848_processGovernorErrorState', 'cm848_applyEngineRetarderTsc1Request',
  'Applies the TSC1 retarder request recorded by cm848_processEngineRetarderTsc1Request: override control mode 2 (torque control) sets engine_retarder_tsc1_request_percent and engine_retarder_tsc1_request_source_code 1, mode 3 (torque limit) lowers engine_retarder_limit_percent to engine_retarder_torque_limit_percent with limit source code 4, and mode 0 (or no request) clears it; the requesting device index goes to engine_retarder_request_source_index. engine_retarder_internal_override_control_mode, never set in this build, can force the same three cases (was cm848_processGovernorErrorState).',
  'Read in full (22 lines): reads engine_retarder_override_control_mode / _torque_request_percent / _torque_limit_percent / _controlling_source_index, all written by cm848_processEngineRetarderTsc1Request (the TSC1 handler for the retarder source address). Step 4 of the dispatcher.')

F('0x00041b24', 'cm848_processTemperatureCompensationMode', 'cm848_selectEngineRetarderRequest',
  'Selects the final engine retarder request percent engine_retarder_arbitrated_request_percent and its source code engine_retarder_request_source_code (ERC1 SPN 900 mapping): 0 when the enable state is 0, or 1 with no TSC1 request; with enable state 2 and no TSC1 request the smallest limit engine_retarder_limit_percent and its limit source code; with a TSC1 torque request that request and its code. Skipped while engine_retarder_request_arbitration_inhibit_flag (constant 0 in this build) is set (was cm848_processTemperatureCompensationMode).',
  'Read in full (27 lines); the three assignments of governor_speed_setpoint / engine_retarder_request_source_code follow fuel_correction_active_flag (0 / 1 / 2) and fuel_correction_state (6 = no TSC1 request, 1 = TSC1 torque request). temp_compensation_active_flag has 1 read here and 1 write (0) in the init: the arbitration always runs.')

F('0x00041be4', 'cm848_processTemperatureTrim', 'cm848_updateEngineRetarderActiveState',
  'Sets engine_retarder_active_flag (1 while an arbitrated request exists unless the road speed limit is active, 0 when none), which the transmission lockup / overdrive logic, the wastegate duty request and the cold start loop read. While the transmission reports shift in process (ETC1 SPN 574), engine_retarder_request_shift_hold_flag freezes the request percent and the active flag for up to engine_retarder_shift_hold_passes passes; after the retarder output is released, engine_retarder_release_pending_flag clears the active flag after engine_retarder_release_passes passes. The engine speed dependent engage delay chain at the top writes the hold flag, but it is cleared unconditionally before the shift block, so that chain has no effect (was cm848_processTemperatureTrim).',
  'Read in full (105 lines) and disassembled: fuel_correction_trigger_flag (0x40a364) stores at 0x41e40 / 0x41e74 (chain), a load at 0x41ea0 and a store at 0x41eb0 (the unconditional clear), then stores at 0x41eec / 0x41ef8 (shift block) and a load at 0x41f5c. fuel_mode_switch_state readers: cm848_selectTemperatureTrimValue, cm848_calculateWastegateDutyRequest, cm848_determineCurrentGearAndLockupInhibit, cm848_processOverdriveSwitchAndShift, mpc555_processColdStartMainLoop. The boost sensor fault test (faults 8 / 9 / 64 = P0238 / P0237 / P0236) belongs to the dead chain.')

F('0x00041fd4', 'cm848_processFuelEfficiencyTrim', 'cm848_driveEngineRetarderOutput',
  'Turns the arbitrated retarder request into the retarder output: engine_retarder_request_percent takes engine_retarder_arbitrated_request_percent unless the shift hold flag freezes it. Below 50 percent it clears the engaged flag and logical output 11 (per engine_retarder_output_mode_flags bits 1 and 0); at 50 percent or more for engine_retarder_request_on_delay_passes passes it sets engine_retarder_engaged_flag and logical output 11, which is cleared again above engine_retarder_output_maximum_engine_speed when both mode bits are set, and while fault bit 101 is detected. Also saves the previous request percent and the wired switch percent copy (was cm848_processFuelEfficiencyTrim).',
  'Read in full (58 lines) and disassembled the on-delay counter (0x3fb54c: lhz at 0x42074, sth at 0x4207c / 0x4212c, so word width). Step 7 (last) of the dispatcher; logical output 11 is the only output set by the cluster.')

F('0x0004218c', 'cm848_processTimingDispatcher', 'cm848_processEngineRetarderRequest',
  'Runs the engine retarder request chain once per pass in order: cm848_updateEngineRetarderEnableState, cm848_limitEngineRetarderPercentToCruisePermission, cm848_limitEngineRetarderPercentToOperatorSelection, cm848_applyEngineRetarderTsc1Request, cm848_selectEngineRetarderRequest, cm848_updateEngineRetarderActiveState and cm848_driveEngineRetarderOutput (was cm848_processTimingDispatcher).',
  'Seven calls, read in full; called from cm848_periodicTaskSet_sensorProcessing between cm848_processSpeedGovernorControl and cm848_calculateSpeedRateLimiting. Nothing in it is about timing.')

F('0x000421c8', 'cm848_initProtectionEventStates', 'cm848_initializeEngineRetarderRequestState',
  'Start-up initialisation of the engine retarder request chain: clears logical outputs 11 to 15, the request, shift hold, release, enable and delay words, and sets the request source codes to 5 (was cm848_initProtectionEventStates).',
  'Read in full (28 lines): five cm848_clearLogicalOutputRequest calls (11-15) and resets of every word the chain owns; called from the application init list next to initHpcr_ExceptionHandler.')

F('0x00524594', 'governorOverrideSpeedControl', 'cm848_calculateEngineRetarderCruisePermissionPercent',
  'Sets engine_retarder_cruise_permission_percent: 0 (no retarder braking) while cruise control is engaged (cruise_control_engaged_flag, with protection_config_flags_b bit 0x8000) and the filtered cruise_speed_setpoint_adjusted has not passed cruise_speed_command plus an offset (with hysteresis), or is at or below cruise_speed_min_threshold; otherwise 100. It is the cruise control limit, source code 2, of the retarder request (was governorOverrideSpeedControl).',
  'Read in full (28 lines). Its only reader is governorLoadMinimumUpdate (engine_retarder_cruise_permission_percent), which records code 2 = ERC1 retarder torque mode 2 (cruise control). Which of cruise_speed_command / cruise_speed_setpoint_adjusted is the measured speed was not settled (many writers), so the plate does not say.')

F('0x005246b0', 'governorLoadMinimumUpdate', 'cm848_limitEngineRetarderPercentToCruisePermission',
  'Lowers the engine retarder percent limit engine_retarder_limit_percent to engine_retarder_cruise_permission_percent when that is smaller and records limit source code 2 (cruise control) in engine_retarder_limit_source_code. Step 2 of cm848_processEngineRetarderRequest (was governorLoadMinimumUpdate).',
  'Body is 4 lines; the source code 2 is mapped to ERC1 SPN 900 = 2 (cruise control) by the ERC1 builder.')

F('0x005246e0', 'initHpcr_ExceptionHandler', 'cm848_initializeEngineRetarderCruisePermissionFilter',
  'Clears the accumulator of the filter on cruise_speed_setpoint_adjusted used by cm848_calculateEngineRetarderCruisePermissionPercent, points it at its coefficient word and clears engine_retarder_cruise_permission_hysteresis_state (was initHpcr_ExceptionHandler).',
  'Read in full (5 lines): writes governor_override_speed_filter_state.accumulator / .coefficient and governor_override_speed_active_flag, all owned by governorOverrideSpeedControl.')

# --- state words of the chain (all working RAM 0x40a3xx unless noted) ---
G('0x0040a352', 'governor_speed_setpoint', 'engine_retarder_arbitrated_request_percent',
  'xref_addr.py: 4 writes in the selection step, 3 reads in the enable-state, active-state and output steps; values are percents (0, the operator selection, the TSC1 request or the minimum limit), and the output step passes it to engine_retarder_request_percent which drives logical output 11 at 50 percent or more. Not a speed.')
G('0x003fb53c', 'governor_speed_setpoint_prev', 'engine_retarder_arbitrated_request_percent_previous',
  'Written once per pass from governor_speed_setpoint at the end of the enable-state step (before the selection step recomputes it), read three times by the active-state step as the previous pass value.' + BOOT)
G('0x003fb53e', 'governor_speed_setpoint_prev_prev', 'engine_retarder_arbitrated_request_percent_previous_2',
  'Copy of the previous-pass word made in the same step; write-only (2 writes, 0 reads).' + BOOT)
G('0x0040a354', 'fuel_correction_state', 'engine_retarder_tsc1_request_source_code',
  'cm848_applyEngineRetarderTsc1Request sets it to 6 at the start of each pass and to 1 for a TSC1 torque request; the selection step copies it into engine_retarder_request_source_code when it is not 6, and the ERC1 builder maps code 1 by requester index. Initial value 5.')
G('0x0040a356', 'governor_speed_setpoint_error_state', 'engine_retarder_tsc1_request_percent',
  'Written only with engine_retarder_torque_request_percent (or 0) in cm848_processGovernorErrorState and read once by the selection step as the percent of a TSC1 torque request.')
G('0x0040a362', 'governor_load_percent_protection_output', 'engine_retarder_switch_percent',
  'cm848_processProtectionSystemBit4 sets it to 100 when switch_input_state_bits[1] mask 0x10 is set (the wired retarder selector, switch 12) else 0 and uses it only through the register; xref_addr.py: no reader (0 reads, 1 write).')
G('0x0040a364', 'fuel_correction_trigger_flag', 'engine_retarder_request_shift_hold_flag',
  'After the unconditional clear (disassembly 0x41ea0 / 0x41eb0) the flag is set only in the ETC1 shift in process block of cm848_processTemperatureTrim, for at most fuel_correction_trigger_threshold_cal passes; while set, cm848_processFuelEfficiencyTrim keeps engine_retarder_request_percent unchanged.')
G('0x0040a366', 'fuel_correction_active_flag', 'engine_retarder_enable_state',
  'Values 0 / 1 / 2 written only by cm848_processProtectionSystemBit3 (and 0 by the init), read by the selection step as the enable state (0 none, 1 held off by pedal / clutch / brake conditions, 2 enabled).')
G('0x0040a368', 'governor_mode_request_code', 'engine_retarder_limit_source_code',
  'Written 2 (cruise), 3 (operator selection) or 4 (TSC1 torque limit) by the three limit steps whenever they lower governor_load_percent_min, read by the selection step as the source code; the ERC1 builder maps 2 -> SPN 900 2, 3 -> 1, 4 -> by requester index.')
G('0x0040a36a', 'governor_load_percent_min', 'engine_retarder_limit_percent',
  'Reset to 101 (no limit) in the enable-state step when enabled and lowered by the cruise, operator selection and TSC1 torque limit steps; the selection step uses it as the request in enable state 2 with no TSC1 request.')
G('0x0040a36c', 'governor_override_mode_state', 'engine_retarder_internal_override_control_mode',
  'Constant 0 in this build: only the init writes it (1 write, 0), and cm848_processGovernorErrorState compares it with 1 / 2 / 3 exactly like engine_retarder_override_control_mode (TSC1 SPN 695 values).')
G('0x0040a36e', 'temp_compensation_active_flag', 'engine_retarder_request_arbitration_inhibit_flag',
  'Constant 0: 1 read in cm848_processTemperatureCompensationMode (skips the whole arbitration when nonzero) and 1 write (0) in the init. Nothing to do with temperature compensation.')
G('0x0040a372', 'fuel_efficiency_trim_pct', 'engine_retarder_switch_percent_2',
  'Written by cm848_processFuelEfficiencyTrim with the same value as 0x40a362 (100 when switch_input_state_bits[1] mask 0x10 is set, else 0); no reader (write-only, 0 reads).')
G('0x0040a374', 'j1939_governor_engage_flag', 'engine_retarder_engaged_flag',
  'Set to 1 / 0 by cm848_processFuelEfficiencyTrim at the same points as logical output 11 (engage after the request stayed at 50 percent or more for the on-delay, release below 50 percent), 3 writes, no reader (0 reads); enabled by engine_retarder_output_mode_flags bit 1.')
G('0x0040a26c', 'fuel_mode_switch_state', 'engine_retarder_active_flag',
  'Set 1 / 0 by cm848_processTemperatureTrim from the arbitrated request (held during a shift); read by cm848_selectTemperatureTrimValue, cm848_calculateWastegateDutyRequest, cm848_determineCurrentGearAndLockupInhibit, cm848_processOverdriveSwitchAndShift and mpc555_processColdStartMainLoop.')
G('0x003fb548', 'fuel_mode_delay_timer', 'service_brake_release_delay_counter',
  'cm848_processProtectionSystemBit3 reloads it from fuel_mode_delay_timer_cal while switch_input_state_bits[1] mask 8 (switch 11, brake) is set and counts it down after release; 1 read / 3 writes, all in the chain.' + BOOT)
G('0x00408eaa', 'fuel_mode_delay_timer_cal', 'service_brake_release_delay_passes',
  'Single read in cm848_processProtectionSystemBit3 (reload value of the brake release delay). ROM address, not in the EEPROM mirror, so no _cal.')
G('0x0040a360', 'engine_idle_validation_flag', 'service_brake_delayed_active_flag',
  '1 while the brake switch (switch 11) is set and until the release delay ends, 0 after; read once in cm848_processProtectionSystemBit3 where a feature bit (system_feature_config_flags 0x4000) makes the retarder conditions require it; not an idle validation.')
G('0x003fb54c', 'governor_j1939_fuel_input_counter', 'engine_retarder_request_on_delay_counter',
  'Disassembly of cm848_processFuelEfficiencyTrim: lhz at 0x42074, sth at 0x4207c (0) / 0x4212c (clamp to the threshold), counting passes with engine_retarder_request_percent at 50 percent or more; word width. The decompiled C shows the plain name for the lockup state accesses of cm848_processProtectionSystemBit3, which really use 0x3fb54e (tc_lockup_disengage_state), so the labels look swapped in the .cpp. BOOT USER (time-shared window): mpc555_diagService25_executeFunction (ROM 0x1840, boot ROM, .cpp line 1132) calls the kernel image function cm848_validateDiagnosticRequestLengthAndAuthorization at RAM 0x3fb54c (ROM 0x597c) and the .cpp renders that call with this name; the application uses the same address as a data word. xref_addr.py lists only that call (0r/0w) and a raw scan of ROM 0x0-0x7F60 finds no load or store of the address.')
G('0x00408ec0', 'governor_j1939_fuel_input_threshold_cal', 'engine_retarder_request_on_delay_passes',
  'Read twice in cm848_processFuelEfficiencyTrim as the on-delay limit of the counter at 0x3fb54c. ROM address (0x408ec0), so no _cal.')
G('0x00408ec2', 'governor_engage_mode_flags', 'engine_retarder_output_mode_flags',
  'Three reads in cm848_processFuelEfficiencyTrim: bit 0 enables logical output 11, bit 1 enables the engaged flag; with both set the output is cleared above the speed threshold.')
G('0x00408ec4', 'j1939_governor_engage_rpm_threshold_cal', 'engine_retarder_output_maximum_engine_speed',
  'Single read in cm848_processFuelEfficiencyTrim: engine_rpm_state_t.current_rpm above it clears logical output 11 when both mode bits are set. ROM address, no _cal.')
G('0x003fb542', 'j1939_governor_fuel_input_snapshot', 'engine_retarder_request_percent_previous',
  'Written with engine_retarder_request_percent at the start of cm848_processFuelEfficiencyTrim, read by cm848_processTemperatureTrim to detect that the request just fell to 0.' + BOOT)
G('0x003fb544', 'governor_cruise_engage_pending_flag', 'engine_retarder_release_pending_flag',
  'Set in cm848_processTemperatureTrim when the request percent has just fallen to 0 or logical output 11 has just been cleared (and no shift hold); while set it counts and then clears engine_retarder_active_flag. Not a cruise word.' + BOOT)
G('0x003fb546', 'governor_cruise_engage_count', 'engine_retarder_release_counter',
  'Counter of the release pending state above (cleared when it starts, incremented to 0xffff).' + BOOT)
G('0x00408e9c', 'governor_cruise_engage_threshold_cal', 'engine_retarder_release_passes',
  'Single read in cm848_processTemperatureTrim as the limit of the release counter. ROM address, no _cal.')
G('0x003fb558', 'fuel_demand_config_flags_snapshot', 'engine_retarder_output_request_bit_previous',
  'Holds logical_output_request_bits_8_to_15 & 8 (the request bit of logical output 11) from the previous pass; 1 read, 1 write, both in cm848_processTemperatureTrim.' + BOOT)
G('0x003fb554', 'fuel_correction_shift_counter', 'engine_retarder_shift_hold_counter',
  'Counts the passes of the ETC1 shift in process hold in cm848_processTemperatureTrim (1 read, 2 writes), dword access.' + BOOT)
G('0x00408eb6', 'fuel_correction_trigger_threshold_cal', 'engine_retarder_shift_hold_passes',
  'Single read in cm848_processTemperatureTrim as the pass limit of the shift hold. ROM address, no _cal.')
G('0x003fb550', 'fuel_correction_enter_condition_flag', 'engine_retarder_enter_condition_flag',
  'Byte written once per pass by cm848_processProtectionSystemBit3 (enter condition: oil temperature / engine speed, boost below limit, fuel demand at minimum, lockup state); read through the register by the enable-state logic.' + BOOT)
G('0x003fb551', 'fuel_correction_exit_condition_flag', 'engine_retarder_exit_condition_flag',
  'Byte written once per pass by cm848_processProtectionSystemBit3 (exit condition: engine speed below the exit threshold, fuel demand above its minimum, lockup disengaged).' + BOOT)
G('0x003fb552', 'fuel_demand_idle_validated_flag', 'engine_retarder_driver_conditions_met_flag',
  'Byte: accelerator pedal demand 0, clutch switch (switch 15) not set, and the service brake condition when required; enable state 2 needs it for a new request.' + BOOT)
G('0x003fb553', 'fuel_demand_idle_active_flag', 'engine_retarder_driver_inhibit_flag',
  'Byte: true when the accelerator pedal demand is not 0 or the clutch switch is set; enable state 1 (held off) is chosen while it is true.' + BOOT)
G('0x00408eb4', 'intercooler_temp_threshold', 'engine_retarder_oil_temperature_threshold',
  'Compared with oil_temperature_sensor_filtered in the enter and exit conditions of cm848_processProtectionSystemBit3 (2 reads, no other user); selects which of the cold / warm engine speed thresholds applies. The old name came from the oil temperature slot 11 name intercooler_temp_raw.')
G('0x00408eb0', 'intercooler_rpm_threshold_low_cal', 'engine_retarder_enter_minimum_engine_speed_cold_oil',
  'Engine speed must exceed it when oil temperature is below the threshold (cm848_processProtectionSystemBit3, 1 read). ROM address, no _cal.')
G('0x00408e9a', 'intercooler_rpm_threshold_high_cal', 'engine_retarder_enter_minimum_engine_speed_warm_oil',
  'Engine speed must exceed it when oil temperature is at or above the threshold (cm848_processProtectionSystemBit3, 1 read). ROM address, no _cal.')
G('0x00408eb2', 'intercooler_rpm_exit_threshold_cal', 'engine_retarder_exit_engine_speed_cold_oil',
  'Exit when oil temperature is below the threshold and engine speed is below this (cm848_processProtectionSystemBit3, 1 read). ROM address, no _cal.')
G('0x003fd924', 'intercooler_rpm_threshold_cal', 'engine_retarder_exit_engine_speed_warm_oil_cal',
  'Exit when oil temperature is at or above the threshold and engine speed is at or below this (cm848_processProtectionSystemBit3, 1 read). 0x3fd924 is in the EEPROM mirror (EEPROM 0x4a2), so _cal stays.' + BOOT)
G('0x00408ebe', 'coolant_temp_threshold', 'engine_retarder_coolant_temperature_threshold',
  'Four reads, all in cm848_processProtectionSystemBit3 (governor mode 11 / 4 enter and exit tests, with a minus 320 count offset = 5 degrees F); no other user.')
G('0x00408ea0', 'fuel_correction_enter_boost_pressure_limit', 'engine_retarder_enter_maximum_boost_pressure',
  'Boost from cm848_calculateBoostPressure must be below it for the enter condition (1 read, cm848_processProtectionSystemBit3).')
G('0x003fd92c', 'fuel_correction_exit_maximum_vehicle_speed_cal', 'engine_retarder_exit_maximum_vehicle_speed_cal',
  'Two reads in cm848_processProtectionSystemBit3: with fuel demand above its minimum and vehicle_speed at or below this value the exit condition is true. In the EEPROM mirror (EEPROM 0x4aa), _cal stays.' + BOOT)
G('0x00408eb8', 'fuel_demand_threshold_a_cal', 'engine_retarder_fuel_demand_threshold_governor_mode_11',
  'Two reads in cm848_processProtectionSystemBit3, both inside governor_fuel_demand_mode == 11 (0xb) tests, added to fuel_demand_offset_correction. ROM address, no _cal.')
G('0x00408eba', 'fuel_demand_threshold_b_cal', 'engine_retarder_fuel_demand_threshold_governor_mode_4',
  'Two reads in cm848_processProtectionSystemBit3, both inside governor_fuel_demand_mode == 4 tests. ROM address, no _cal.')
G('0x0040b68a', 'governor_override_load_percent', 'engine_retarder_cruise_permission_percent',
  'Written 0 or 100 only by governorOverrideSpeedControl and read only by governorLoadMinimumUpdate (limit source code 2 = cruise control).')
G('0x003fcfee', 'governor_override_speed_active_flag', 'engine_retarder_cruise_permission_hysteresis_state',
  'Holds the same 0 / 100 as the permission percent and selects the plain or the hysteresis threshold in governorOverrideSpeedControl (1 read, 2 writes, plus 0 from the init).' + BOOT)
G('0x0040b682', 'governor_override_speed_filter_state', 'engine_retarder_cruise_permission_speed_filter_state',
  'ema_filter_state_t used only by governorOverrideSpeedControl on cruise_speed_setpoint_adjusted (init in initHpcr_ExceptionHandler).')
G('0x00408dfa', 'governor_override_speed_filter_coefficient', 'engine_retarder_cruise_permission_speed_filter_coefficient',
  'Coefficient word of the filter above (set as its coefficient pointer by initHpcr_ExceptionHandler).')
NG('0x003fd90c', 'engine_retarder_cruise_permission_speed_threshold_cal', 'word',
   'DAT_003fd90c: threshold on the filtered speed minus (cruise_speed_command + 0x3fd910) in governorOverrideSpeedControl (2 reads, 0 writes, no other user): permission 100 when the difference exceeds it. In the EEPROM mirror (EEPROM 0x48a) so _cal. xref_addr.py says word (2 reads / 0 writes); no row in any CSV.' + BOOT)
NG('0x00408dee', 'engine_retarder_cruise_permission_hysteresis', 'word',
   'DAT_00408dee: subtracted from the threshold above once the permission is active (1 read in governorOverrideSpeedControl, 0 writes); ROM address. xref_addr.py says word (1 read / 0 writes); no row in any CSV.')
N('DAT_003fd910 (word, EEPROM 0x48e, time-shared window, xref: governorOverrideSpeedControl 1r + governorCruiseStateMachine 1r, no boot users) is the speed offset added to cruise_speed_command in both functions: shared with the cruise state machine, so it is not named here.')
G('0x003faa66', 'tsc1_override_mode_bits_prev', 'engine_retarder_controlling_override_priority_bits',
  'cm848_processEngineRetarderTsc1Request stores tsc1_rx_byte_0 & 0x30 into it (bVar5), i.e. TSC1 byte 1 bits 5-6 = SPN 897 Override Control Mode Priority (j1939 DB), not SPN 695 (that is mask 0x03, engine_retarder_override_control_mode); a new sender whose value is numerically larger (lower priority) is rejected. xref_addr.py: 1 read, 1 write, only that function.' + BOOT)
G('0x0040ad60', 'tsc1_rx_byte0_cached', 'engine_retarder_controlling_tsc1_control_byte',
  'Word copy of TSC1 byte 1 of the accepted sender, 1 write, 0 reads (write-only), only cm848_processEngineRetarderTsc1Request.')
NG('0x003faa67', 'engine_retarder_controlling_tsc1_torque_byte', 'byte',
   'DAT_003faa67: byte copy of TSC1 byte 4 (tsc1_rx_byte_3, SPN 518 torque / limit) of the accepted sender, compared with a new sender at equal priority in mode 3; xref_addr.py says byte (1 read / 1 write, only cm848_processEngineRetarderTsc1Request); no row in any CSV.' + BOOT)
G('0x003fae50', 'j1939_pgn_dest_address', 'j1939_pgn65249_payload_byte_1',
  'cm848_buildPgn65249RetarderConfigurationMessage writes 0xFF / 0x14 / 3 from engine_retarder_configuration_mode into the first RC payload byte (0x3fae50 is the start of the 19 byte buffer); it is payload, not a destination address (the descriptor holds the address). The j1939 DB has no SPN list for PGN 65249, so the field (probably retarder type / location) is not named by SPN.' + BOOT)
G('0x003fae51', 'j1939_pgn65249_byte0', 'j1939_pgn65249_payload_byte_2',
  'Second RC payload byte: 0xFF / 6 / 3 / 2 / 1 from engine_retarder_stage_1_weight (0 / 1 / 2 / 3 / 6); the old name byte0 contradicts its place (second byte). Field meaning is not in the j1939 DB.' + BOOT)
G('0x00408e9e', 'governor_cruise_enable_count_cal', None,
  'Part of the engine speed dependent engage delay chain of cm848_processTemperatureTrim (with governor_cruise_mode_count, governor_enable_delay_counter and cruise_rpm_range_low / mid / high_cal) whose writes to the hold flag are overwritten by the unconditional clear: the chain is a retarder engage delay, not cruise, but its effect is nil here, so no name is proposed.', verdict='uncertain')

# ---------------------------------------------------------------------------------------------
# FAMILY 2: load protection confirm counters (instance = function A / B, stage = delay / hysteresis)
# ---------------------------------------------------------------------------------------------
N('Confirm counter naming: instance letter = the function (cm848_updateLoadProtectionConfirmCounterA / B), stage = delay (stage 1, on-delay against the first limit) / hysteresis (stage 2, up-down counter against the second limit). The old a / b / c suffixes crossed the function letters: function A used the old _b words (0x3fb0c4 / 0x3fb0c6 / 0x3fb0ca / 0x3fb0cc / 0x3fb0ce), function B the old _c and _a words (0x3fb0a6 / 0x3fb0a8 / 0x3fb0ac / 0x3fb0ae / 0x3fb0b0). All ten words sit in the time-shared window and have no boot user. Function B was read in full and has the identical structure (stage 1 input protection_confirm_active_b 0x40b09e, stage 2 up / down input protection_condition_active_flag, the same two limits, match flag, snapshot and latched flag). The inputs of the two instances (protection_confirm_active_a 0x40b060 for A, protection_confirm_active_b 0x40b09e for B) were not renamed.')
CONFIRM = ' Function A (steady stage, read by cm848_evaluateLoadProtectionSteadyStage) uses this word.'
CONFIRM_B = ' Function B (live stage, read by cm848_evaluateLoadProtectionLiveStage) uses this word.'
G('0x003fb0c4', 'protection_confirm_delay_counter_b', 'load_protection_confirm_a_delay_counter',
  'Stage 1 of cm848_updateLoadProtectionConfirmCounterA: on-delay counter, 0 while protection_confirm_active_a is 0, else counts up to protection_confirm_limit_a_cal (2 reads / 1 write, word).' + BOOT)
G('0x003fb0c6', 'protection_confirm_counter_b', 'load_protection_confirm_a_hysteresis_counter',
  'Stage 2 of cm848_updateLoadProtectionConfirmCounterA: up / down counter limited by protection_confirm_limit_b_cal, counting up while fuel_control_setpoint_exceeded_flag is set after the delay elapsed and down otherwise (3 reads / 1 write, word).' + BOOT)
G('0x003fb0cc', 'protection_confirm_counter_b_match_flag', 'load_protection_confirm_a_delay_elapsed_flag',
  'Written by function A as (delay counter == limit_a), read by cm848_evaluateLoadProtectionSteadyStage (1 read / 1 write).' + BOOT)
G('0x003fb0ce', 'protection_confirm_counter_b_snapshot', 'load_protection_confirm_a_hysteresis_counter_snapshot',
  'Copy of the stage 2 counter written by function A; write-only (0 reads / 1 write).' + BOOT)
G('0x003fb0ca', 'protection_confirm_condition_b_flag', 'load_protection_confirm_a_latched_flag',
  'Set by function A when the stage 2 counter reaches its limit and cleared when it returns to 0; read by cm848_evaluateLoadProtectionSteadyStage (1 read / 1 write).' + BOOT)
G('0x003fb0a6', 'protection_confirm_counter_c', 'load_protection_confirm_b_delay_counter',
  'Stage 1 (on-delay) of cm848_updateLoadProtectionConfirmCounterB, same pattern as 0x3fb0c4 with protection_confirm_limit_a_cal (2 reads / 1 write, only function B).' + BOOT)
G('0x003fb0a8', 'protection_confirm_counter_a', 'load_protection_confirm_b_hysteresis_counter',
  'Stage 2 (up / down counter) of cm848_updateLoadProtectionConfirmCounterB against protection_confirm_limit_b_cal (3 reads / 1 write, only function B).' + BOOT)
G('0x003fb0ae', 'protection_confirm_counter_c_match_flag', 'load_protection_confirm_b_delay_elapsed_flag',
  'Written by function B (0 reads / 1 write there), read by cm848_evaluateLoadProtectionLiveStage.' + BOOT)
G('0x003fb0b0', 'protection_confirm_counter_a_snapshot', 'load_protection_confirm_b_hysteresis_counter_snapshot',
  'Copy of the stage 2 counter written by function B; write-only (0 reads / 1 write).' + BOOT)
G('0x003fb0ac', 'protection_confirm_active_b_flag', 'load_protection_confirm_b_latched_flag',
  'Written once by function B (analog of 0x3fb0ca) and read by cm848_evaluateLoadProtectionLiveStage; function B read in full: set when the stage 2 counter reaches limit_b and cleared when it returns to 0, exactly as in function A.' + BOOT)
G('0x004077ea', 'protection_confirm_limit_a_cal', 'load_protection_confirm_delay_limit',
  'Stage 1 limit used by both instances (1 read each in cm848_updateLoadProtectionConfirmCounterA and B): the two limits are stages, not instances. ROM address 0x4077ea, so no _cal.')
G('0x004077ec', 'protection_confirm_limit_b_cal', 'load_protection_confirm_hysteresis_limit',
  'Stage 2 limit used by both instances (1 read each in function A and B). ROM address 0x4077ec, so no _cal.')

# ---------------------------------------------------------------------------------------------
# FAMILY 3: TSC1 ignored request lists (the coolant_cal_entry family)
# ---------------------------------------------------------------------------------------------
N('TSC1 list semantics (coolant_cal_entry family): two countdown lists of senders whose TSC1 requests the ECM ignores. A = engine TSC1 (torqueControlModeHandler: cm848_removeCoolantCalEntryByParams(1, source) on override mode 0, cm848_findJ1939MessageEntry(1, source, mode) returns nonzero -> the request is dropped), B = retarder TSC1 (cm848_processEngineRetarderTsc1Request: cm848_removeCoolantCalEntry(source) on mode 0, cm848_refreshTsc1RequestEntry(source, mode) nonzero -> dropped, countdown reloaded from etc1_torque_mode_timeout_cal). Entries are added by cm848_processGovernorModeTransition when the engine / retarder override times out and by cm848_updateParkNeutralFlagAndTsc1Activity (three authorized sources x modes 1-3 on a TSC1 activity timing fault); cm848_processCoolantCalEntries expires them. Follow-ups outside this file: cm848_refreshTsc1RequestEntry (0x53cd8, wave 3) and cm848_findJ1939MessageEntry (0x53c68) are the list B / list A lookups and could become cm848_refreshRetarderTsc1IgnoredRequestEntry / cm848_findEngineTsc1IgnoredRequestEntry; the wave 3 plate of 0x53cd8 cites fault_entry_data_array and needs the new array name. DAT_003fb918 / 0x3fb91a / 0x3fb91c (list A: source address byte, mode word, countdown word at offsets +2 / +4 / +6 of the 8-byte entries) and DAT_003fb968 / 0x3fb96a (list B: mode word and countdown word at +2 / +4 of the 6-byte entries) are element fields, not separate globals. Type note only: both arrays are typed word / byte but are 10 entries of 8 / 6 bytes (0x3fb916-0x3fb965 and 0x3fb966-0x3fb9a1).')
F('0x00053d3c', 'cm848_addCoolantCalEntry', 'cm848_addEngineTsc1IgnoredRequestEntry',
  'Appends an entry (type word param_1, source address param_2, override control mode param_3, countdown etc1_torque_mode_timeout_cal) to the engine TSC1 ignored request list engine_tsc1_ignored_request_entries (8-byte entries, at most 10, counted by engine_tsc1_ignored_request_count); torqueControlModeHandler then ignores TSC1 requests from that source address and mode until the entry expires. Called when the engine override times out (cm848_processGovernorModeTransition) and for the three authorized TSC1 sources on a TSC1 activity timing fault (cm848_updateParkNeutralFlagAndTsc1Activity) (was cm848_addCoolantCalEntry).',
  'Read in full; nothing to do with coolant. Callers at .cpp lines 24632 (cm848_processGovernorModeTransition) and 67378-67380 (cm848_updateParkNeutralFlagAndTsc1Activity, key 1, three source addresses, modes 1-3).')
F('0x00053d84', 'cm848_addCoolantCalEntryAlt', 'cm848_addRetarderTsc1IgnoredRequestEntry',
  'Appends an entry (source address param_1, override control mode param_2, countdown etc1_torque_mode_timeout_cal) to the retarder TSC1 ignored request list retarder_tsc1_ignored_request_entries (6-byte entries, at most 10, counted by retarder_tsc1_ignored_request_count); cm848_processEngineRetarderTsc1Request then ignores requests from that source address and mode until the entry expires. Called by cm848_processGovernorModeTransition when the retarder torque control request times out (was cm848_addCoolantCalEntryAlt).',
  'Read in full; sole caller cm848_processGovernorModeTransition (.cpp line 24719, with engine_retarder_controlling_source_address and mode 2).')
F('0x00053dc8', 'cm848_processCoolantCalEntries', 'cm848_processTsc1IgnoredRequestTimeouts',
  'Counts down every entry of the two TSC1 ignored request lists once per pass and removes the entries that reach 0 (the last entry moves into the gap); an expiring engine list entry of type 1, mode 1 and the primary authorized source address clears j1939_tsc1_override_state.torque_limit_mode_select and bit 0 of speed_control_target, an expiring retarder list entry of mode 2 from that source clears bit 1 (was cm848_processCoolantCalEntries).',
  'Read in full (80 lines); called once per pass from the periodic task list (.cpp line 6641).')
F('0x00053fa8', 'cm848_removeCoolantCalEntryByParams', 'cm848_removeEngineTsc1IgnoredRequestEntry',
  'Removes the engine TSC1 ignored request list entries with type word param_1 and source address param_2 (the last entry moves into the gap). Called by torqueControlModeHandler when that sender sends override control mode 0, and by cm848_updateParkNeutralFlagAndTsc1Activity for the three authorized sources when TSC1 activity returns (was cm848_removeCoolantCalEntryByParams).',
  'Read in full; callers at .cpp lines 21463 (torqueControlModeHandler) and 67350-67352.')
F('0x00054064', 'cm848_removeCoolantCalEntry', 'cm848_removeRetarderTsc1IgnoredRequestEntry',
  'Removes the retarder TSC1 ignored request list entries of source address param_1 (the last entry moves into the gap); called by cm848_processEngineRetarderTsc1Request when that sender sends override control mode 0 (was cm848_removeCoolantCalEntry).',
  'Read in full; caller at .cpp line 21894 (cm848_processEngineRetarderTsc1Request).')
G('0x003fb916', 'fault_severity_data_array', 'engine_tsc1_ignored_request_entries',
  'Base of the 10 x 8-byte list A (engine TSC1) used by cm848_findJ1939MessageEntry, cm848_addCoolantCalEntry, cm848_processCoolantCalEntries and cm848_removeCoolantCalEntryByParams; not a fault severity array.' + BOOT)
G('0x003fb966', 'fault_entry_data_array', 'retarder_tsc1_ignored_request_entries',
  'Base of the 10 x 6-byte list B (retarder TSC1) used by cm848_refreshTsc1RequestEntry, cm848_addCoolantCalEntryAlt, cm848_processCoolantCalEntries and cm848_removeCoolantCalEntry; not a fault entry array.' + BOOT)
G('0x003fb9a2', 'coolant_cal_entry_count_a', 'engine_tsc1_ignored_request_count',
  'Entry count of list A (6 reads / 5 writes in the four list A functions and cm848_findJ1939MessageEntry); maximum 10.' + BOOT)
G('0x003fb9a3', 'coolant_cal_entry_count_b', 'retarder_tsc1_ignored_request_count',
  'Entry count of list B (6 reads / 5 writes in the four list B functions); maximum 10.' + BOOT)

# ---------------------------------------------------------------------------------------------
# FAMILY 4: J1939 / CAN receive and transmit queues (the engine_data_log family)
# ---------------------------------------------------------------------------------------------
N('CAN queue facts: receive = 20 records of 18 bytes (0x40aacc-0x40ac33, record = 29-bit identifier word + bytes copied from the TouCAN mailbox by mpc555_queueCanReceiveMessage, dequeued by cm848_dispatchJ1939ReceivedMessages); transmit = 12-byte records in can_transmit_queue_buffer (0x40ac34), enqueue pointer can_transmit_queue_enqueue_ptr (0x40ad24, spelled ptr, could become ..._pointer for consistency), dequeue pointer 0x40ad28 advanced by 12 in mpc555_processJ1939TxBufferSend; fault bit 111 (0x8000 of fault_detected_bits_96_to_111, no DTC slot) is set when mpc555_sendJ1939SingleFrame finds the transmit queue full after at least one transmit completion, and the init clears it. Type notes (no change proposed): engine_data_log_buffer is typed byte but is a 360 byte array; 0x40ad28 is typed dword but holds an address.')
G('0x0040aacc', 'engine_data_log_buffer', 'can_receive_queue_buffer',
  'Base of the receive ring (18-byte records) written by mpc555_queueCanReceiveMessage and read by cm848_dispatchJ1939ReceivedMessages; xref_addr.py finds no direct access (pointer use only).')
G('0x0040ac22', 'engine_data_log_buffer_limit', 'can_receive_queue_last_entry',
  'Start address of the last record (0x40aacc + 19 x 18): the wrap test is (&limit < pointer) in both the enqueue and dequeue functions.')
G('0x0040ad2c', 'engine_data_log_write_ptr', 'can_receive_queue_write_pointer',
  'Advanced by 18 per received message in mpc555_queueCanReceiveMessage (3 reads / 2 writes) and compared with the read pointer in cm848_dispatchJ1939ReceivedMessages; initialised to the buffer in cm848_j1939_system_init.')
G('0x0040ad30', 'engine_data_log_read_ptr', 'can_receive_queue_read_pointer',
  'Advanced by 18 per dispatched message in cm848_dispatchJ1939ReceivedMessages (3 reads / 2 writes), compared in mpc555_queueCanReceiveMessage.')
G('0x0040ad35', 'engine_data_log_full_flag', 'can_receive_queue_full_flag',
  'Set by mpc555_queueCanReceiveMessage when the write pointer catches the read pointer (and the mailbox interrupt is masked), cleared by cm848_dispatchJ1939ReceivedMessages after it dequeues.')
G('0x0040ad28', 'engine_data_log_write_sentinel', 'can_transmit_queue_dequeue_pointer',
  'mpc555_processJ1939TxBufferSend compares can_transmit_queue_enqueue_ptr with it to detect an empty queue, writes the next record to the TouCAN mailbox and advances it by 12 with wrap at 0x40ad18 + 12 (2 reads / 3 writes incl. init); a dequeue pointer, not a sentinel.')
G('0x0040ad34', 'engine_data_log_active_flag', 'can_transmit_queue_full_flag',
  'mpc555_sendJ1939SingleFrame sets it to 1 (inside a condition expression, so xref_addr.py shows no store there) when the enqueue pointer reaches the dequeue pointer; mpc555_processJ1939TxBufferSend clears it after dequeuing and tests it for the empty case.')
G('0x0040ad38', 'engine_data_log_ptr', 'can_transmit_mailbox_pointer',
  'Set by cm848_j1939_system_init to the TouCAN message buffer used for transmitting (&UNK_003070f0 + 16 x index); its byte 1 (mailbox code) is tested for 0xC0 (busy) in mpc555_sendJ1939SingleFrame and cleared in mpc555_processJ1939TxBufferSend. Not a queue pointer (the earlier wave did not check it).')
G('0x0040ad80', 'engine_data_log_read_ready_flag', 'can_transmit_completed_flag',
  'Set to 1 by mpc555_processJ1939TxBufferSend (transmit completion), cleared by the init, and required by mpc555_sendJ1939SingleFrame before it raises fault bit 111 for a full transmit queue.')
G('0x0040ad56', 'j1939_data_log_sa_whitelist', 'j1939_receive_source_address_whitelist',
  'cm848_dispatchJ1939ReceivedMessages walks it (4 bytes) to accept source addresses of received records; the data log domain of the old name belongs to the same mislabelled queue.')

# ---------------------------------------------------------------------------------------------
# FAMILY 5: dual analog accelerator pedal block (the cruise_speed_* words)
# ---------------------------------------------------------------------------------------------
N('Dual accelerator pedal block identity: 0x40bbb2 / 0x40bbb4 are sensor_channel_filtered_output[97] / [98] ((0x40bbb2 - 0x40baf0) / 2 = 97), and the linearization tables of those channels are already named accelerator_pedal_channel97_ / channel98_linearization_*. The circuit fault bits tested for channel 97 are faults 347 / 348 = P2122 / P2123 and 196 / 197 = P0699 / P0698, for channel 98 faults 349 / 350 = P2127 / P2128 and 377 / 378 = P0653 / P0652; the channel disagreement raises fault 334 = P2121 (ROM 0x5985a slot table + obd_dtc_code_table). Not the cruise controller (cm848_cruiseSpeedCommandStateMachine). Wave-3 comments that cite the old names (0x3fee46, 0x40b556, 0x40b558 rows) need a reference refresh.')
F('0x0003cf68', 'cm848_processFaultPendingFlags', 'cm848_updateAcceleratorPedalSensorFaultFlags',
  'When the dual accelerator pedal block is enabled (accelerator_pedal_dual_channel_enable_flag), sets accelerator_pedal_channel97_circuit_fault_flag and accelerator_pedal_channel98_circuit_fault_flag from the circuit fault bits of the two pedal channels and latches accelerator_pedal_sensor_fault_latched_flag while either is set, releasing it once fuel_demand_control_t.accelerator_off_idle is 0 (was cm848_processFaultPendingFlags).',
  'Read in full (27 lines): faults 347 / 348 / 196 / 197 and 349 / 350 / 377 / 378 (P2122 / P2123 / P0699 / P0698 and P2127 / P2128 / P0653 / P0652).')
F('0x0003d070', 'cm848_processOperatingModeFlags', 'cm848_checkAcceleratorPedalChannelAgreement',
  'Compares the two accelerator pedal channels (each minus its idle threshold when accelerator_pedal_compare_relative_to_idle_flag is set); a difference above accelerator_pedal_channel_disagreement_threshold for accelerator_pedal_channel_disagreement_debounce_limit passes sets accelerator_pedal_channel_disagreement_flag, which clears when both channels are at or below their idle thresholds; with the flag set and no latched circuit fault it sets fault bit 334 (P2121) (was cm848_processOperatingModeFlags).',
  'Read in full (60 lines); fault 334 decodes to P2121 through the 0x5985a slot table.')
F('0x0003d204', 'cm848_processFuelDemandEnableFlag', 'cm848_calculateAcceleratorPedalDemandFromChannels',
  'Calculates governor_speed_demand_limit, the pedal demand 0 to 400 (0.25 percent per count), as the idle-corrected reading of channel 97 (channel 98 when channel 97 has a circuit fault, 0 when both have one; during a disagreement without a latched fault the lower of the two, or 0 when accelerator_pedal_disagreement_zero_demand_enable is set) times 400 divided by accelerator_pedal_travel_span, sets fuel_demand_control_t.accelerator_off_idle when it exceeds accelerator_pedal_off_idle_threshold, and sets accelerator_pedal_input_fault_flag and governor_speed_demand_limit_prev (was cm848_processFuelDemandEnableFlag).',
  'Read in full (55 lines); the enable flag word it was named for is not set here.')
F('0x0003d3b8', 'cm848_processCalibration12FuelDemand', 'cm848_learnAcceleratorPedalIdlePositions',
  'Learns the closed pedal position of each channel while neither a disagreement nor a latched circuit fault exists: after accelerator_pedal_idle_learning_debounce_limit passes below position plus accelerator_pedal_idle_learning_deadband it moves the idle position down by gain / 256 of the difference (accelerator_pedal_idle_learning_gain) for at most accelerator_pedal_idle_learning_channel_step_limit steps, and stores position plus accelerator_pedal_idle_threshold_offset as the idle threshold (the EEPROM-backed 0x3fee46 / 0x3fee48 words) (was cm848_processCalibration12FuelDemand).',
  'Read in full (75 lines); writes accelerator_pedal_idle_threshold_a_cal and cruise_speed_target_b (0x3fee48), both in the EEPROM mirror.')
F('0x0003d5fc', 'cm848_initFuelDemandLimits', 'cm848_initializeAcceleratorPedalIdlePositions',
  'Sets both accelerator pedal idle positions (channel 97 and channel 98) to accelerator_pedal_idle_position_initial (was cm848_initFuelDemandLimits).',
  'Two stores, read in full.')
G('0x0040bbb2', 'cruise_speed_current_a', 'accelerator_pedal_channel97_sensor_filtered',
  'sensor_channel_filtered_output[97] (arithmetic from 0x40baf0); read in the three pedal functions; its linearization tables are accelerator_pedal_channel97_linearization_*; 0 writes in the pedal block (written by the sensor channel wrapper).')
G('0x0040bbb4', 'cruise_speed_current_b', 'accelerator_pedal_channel98_sensor_filtered',
  'sensor_channel_filtered_output[98]; channel B of the same block (tables accelerator_pedal_channel98_linearization_*).')
G('0x0040b554', 'cruise_speed_setpoint_a', 'accelerator_pedal_idle_position_a',
  'Channel A learned closed pedal position (initialised by cm848_initFuelDemandLimits, lowered by the learning step); the sibling 0x40b556 is already accelerator_pedal_idle_position_b.')
G('0x003fee48', 'cruise_speed_target_b', 'accelerator_pedal_idle_threshold_b_cal',
  'Channel B idle threshold = idle position B + offset, written by the learning function and compared in cm848_checkAcceleratorPedalChannelAgreement (sibling of accelerator_pedal_idle_threshold_a_cal at 0x3fee46); EEPROM mirror (EEPROM 0x9c6) so _cal. Not in the 0x3fee08-0x3fee3d boot-shared range: xref_addr.py lists no access below 0x7F60 either.')
G('0x0040b550', 'cruise_active_flag_a', 'accelerator_pedal_channel_disagreement_flag',
  'Set after the channel difference exceeded the threshold for the debounce time, cleared when both channels are at or below their idle thresholds; with no latched circuit fault it raises P2121.')
G('0x0040b551', 'cruise_active_flag_b', 'accelerator_pedal_sensor_fault_latched_flag',
  'Set while either channel has a circuit fault, cleared when accelerator_off_idle is 0 (cm848_updateAcceleratorPedalSensorFaultFlags).')
G('0x0040b552', 'cruise_setpoint_a_valid_flag', 'accelerator_pedal_channel97_circuit_fault_flag',
  'Byte: false when none of faults 347 / 348 / 196 / 197 is detected and true when one is, so the old _valid_ name is inverted.')
G('0x0040b553', 'cruise_setpoint_b_valid_flag', 'accelerator_pedal_channel98_circuit_fault_flag',
  'Byte: true when one of faults 349 / 350 / 377 / 378 is detected, inverted like the channel 97 flag.')
G('0x00408a78', 'cruise_speed_setpoint_init', 'accelerator_pedal_idle_position_initial',
  'ROM initial value of both learned idle positions (1 read in cm848_initFuelDemandLimits). ROM address, no _cal.')
G('0x00408a7a', 'cruise_speed_setpoint_offset_cal', 'accelerator_pedal_idle_threshold_offset',
  'Added to the idle position to give the idle threshold (2 reads in the learning function). ROM address, so the _cal goes.')
G('0x00408a7e', 'cruise_speed_deadband_cal', 'accelerator_pedal_idle_learning_deadband',
  'The reading must be below idle position + this for a learning step (1 read). ROM address, no _cal.')
G('0x00408a80', 'cruise_speed_diff_threshold_cal', 'accelerator_pedal_channel_disagreement_threshold',
  'Absolute channel difference above which the disagreement debounce counts (1 read in cm848_checkAcceleratorPedalChannelAgreement). ROM address, no _cal.')
G('0x003fb428', 'cruise_set_debounce_timer', 'accelerator_pedal_channel_disagreement_debounce_counter',
  'Counts passes of channel disagreement up to the limit and resets to 0 (1 read / 3 writes, only cm848_processOperatingModeFlags).' + BOOT)
G('0x00408a74', 'cruise_set_debounce_timer_max_cal', 'accelerator_pedal_channel_disagreement_debounce_limit',
  'Limit of the disagreement debounce counter (1 read). ROM address, no _cal.')
G('0x00408a84', 'fuel_demand_enable_flag', 'accelerator_pedal_dual_channel_enable_flag',
  'ROM byte tested first by all five pedal block functions (each does nothing when it is 0) and read by cm848_fuelDemandFinalCalculation, cm848_fuelDemandCoordinator, cm848_selectSensorValuesInUse, cm848_transitionEngineOperatingMode and the SCI table read functions (19 reads, 0 writes). cm848_fuelDemandFinalCalculation uses the single pedal path (cm848_fuelDemandBaseCalculation) when it is 0 and governor_speed_demand_limit_prev, the dual channel demand, when it is nonzero; cm848_selectSensorValuesInUse tests fault bit 348 (P2123, channel 97) for the pedal position substitute when it is 1 and the single pedal fault bit otherwise.')
G('0x00408a7c', 'cruise_speed_demand_divisor_cal', 'accelerator_pedal_travel_span',
  'Divisor in (reading - idle threshold) x 400 / this: the counts of full pedal travel (1 read). ROM address, no _cal.')
G('0x00408a82', 'cruise_governor_demand_enable_threshold_cal', 'accelerator_pedal_off_idle_threshold',
  'fuel_demand_control_t.accelerator_off_idle = (this < governor_speed_demand_limit) (1 read). ROM address, no _cal.')
G('0x00408a88', 'cruise_active_limit_enable_cal', 'accelerator_pedal_disagreement_zero_demand_enable',
  'Read once in cm848_calculateAcceleratorPedalDemandFromChannels: with a disagreement and no latched circuit fault, 0 selects the lower of the two readings and a nonzero value selects demand 0. ROM address, so the _cal goes.')
G('0x00408a85', 'cruise_speed_offset_enable_cal', 'accelerator_pedal_compare_relative_to_idle_flag',
  'Byte read once in the agreement check: when nonzero each channel is compared after subtracting its idle threshold. ROM address, no _cal.')
G('0x00408a86', 'cruise_speed_error_gain_cal', 'accelerator_pedal_idle_learning_gain',
  'Multiplier / 256 on the difference of reading and idle position in the learning step (2 reads). ROM address, no _cal.')
G('0x003fb42a', 'cruise_resume_debounce_a', 'accelerator_pedal_channel97_idle_learning_debounce_counter',
  'Debounce counter of the channel A idle learning (1 read / 3 writes, only the learning function).' + BOOT)
G('0x003fb42c', 'cruise_resume_debounce_b', 'accelerator_pedal_channel98_idle_learning_debounce_counter',
  'Debounce counter of the channel B idle learning (1 read / 3 writes, only the learning function).' + BOOT)
G('0x003fb42e', 'cruise_resume_debounce_counter', 'accelerator_pedal_idle_learning_total_step_counter',
  'Incremented when either channel took a learning step; learning stops above accelerator_pedal_idle_learning_total_step_limit (1 read / 1 write).' + BOOT)
G('0x003fb430', 'cruise_speed_settle_counter_a', 'accelerator_pedal_channel97_idle_learning_step_counter',
  'Learning steps taken on channel A, compared with the per-channel step limit (2 reads / 1 write).' + BOOT)
G('0x003fb432', 'cruise_speed_settle_counter_b', 'accelerator_pedal_channel98_idle_learning_step_counter',
  'Learning steps taken on channel B (2 reads / 1 write).' + BOOT)
G('0x00408a72', 'cruise_resume_debounce_limit', 'accelerator_pedal_idle_learning_debounce_limit',
  'Debounce limit for both channels in the learning function (2 reads). ROM address, no _cal.')
G('0x00408a8a', 'cruise_resume_timer_threshold_cal', 'accelerator_pedal_idle_learning_total_step_limit',
  'Learning only runs while the total step counter is at or below it (1 read). ROM address, so the _cal goes.')
G('0x00408a8c', 'cruise_speed_settle_count_cal', 'accelerator_pedal_idle_learning_channel_step_limit',
  'Per-channel limit of learning steps (2 reads). ROM address, so the _cal goes.')

# ---------------------------------------------------------------------------------------------
# FAMILY 6: fuel_trim_* reference speed reduction in operating mode 7
# ---------------------------------------------------------------------------------------------
N('Mode 7 owner: cm848_initEngineOperatingMode (0x10110) holds the one literal assignment engine_operating_mode = 7 (other writers take the mode as a parameter), made only when engine_operating_mode == 0 and variable_speed_governor_selected_flag == 1 (that flag comes from variable_speed_governor_default_cal / cm848_updateVariableSpeedGovernorSelection), after cm848_blendGovernorTuningSets, so mode 7 is the variable speed governor selected by its flag. The block in cm848_runOperatingModeSpeedGovernor (.cpp lines 9128-9170) reduces governor_reference_speed_filtered: with the active flag set, above the upper threshold by the decay per call (or by upper minus lower when the decay is 0), otherwise by the lower step, then caps it at current rpm + governor_reference_speed_lead_offset + a manifold pressure gain and floors it at governor_reference_speed_floor; with the flag clear it sets the reference to the floor. The reason for the reduction (what the variable speed governor does with it) was not settled, so the rows below name only the verified mechanism. The fuel_trim_pid_* / fuel_trim_saved_* words (saved and restored PID state of the same loop, 0x40a20a-0x40a24a) and fuel_trim_speed_override_flag / fuel_trim_override_* were not renamed; 0x3ff6a2-0x3ff6a8 stay a [W3 rail] lead.')
G('0x0040a1f2', 'fuel_trim_speed_active_flag', 'governor_reference_speed_reduction_active_flag',
  'Set in cm848_runOperatingModeSpeedGovernor (engine_operating_mode 7) when no cancel switch is set (or the cancel feature is off), vehicle_speed_copy is at or above the minimum, the override flag allows it and the park / neutral condition passes; while set, governor_reference_speed_filtered is reduced, while clear it is set to the floor.')
G('0x003ff692', 'fuel_trim_speed_decay_cal', 'governor_reference_speed_reduction_decay',
  'Subtracted from governor_reference_speed_filtered per call while it is above the upper threshold (0 = use upper minus lower instead). 0x3ff692 is above the EEPROM mirror, so no _cal.' + ' Not in the time-shared window.')
G('0x003ff694', 'fuel_trim_speed_lower_threshold', 'governor_reference_speed_reduction_low_range_step',
  'Not a threshold: subtracted from the reference per call when it is at or below the upper threshold (0 gives 0), and used as upper minus this when the decay is 0.')
G('0x003ff696', 'fuel_trim_speed_upper_threshold', 'governor_reference_speed_reduction_upper_threshold',
  'Breakpoint between the decay branch and the low range step branch of the reduction.')
G('0x003ff698', 'fuel_trim_speed_minimum_vehicle_speed', 'governor_reference_speed_reduction_minimum_vehicle_speed',
  'vehicle_speed_copy must be at or above it for the reduction to be active.')
G('0x003ff69a', 'fuel_trim_speed_switch_cancel_enable_flag', 'governor_reference_speed_reduction_switch_cancel_enable_flag',
  'When nonzero, the brake switch (switch 11) or switch 2 makes the reduction inactive, which sets the reference to its floor.')

# ---------------------------------------------------------------------------------------------
# FAMILY 7: fuel_ema_* / fuel_demand_ema_* and the injection timing compensation limits
# ---------------------------------------------------------------------------------------------
N('fuel_ema block: selectSensorRawChannels (0x1fa20, chooses one of the base / alternate / working coefficient sets into the selected set and records the set code in fuel_demand_state_code), cm848_processSystemStatusLimits (loads the working sets, set codes 0x14 / 0x15), cm848_initSensorRawChannels (selects the base set, code 0x10) and cm848_processTorqueLimitTiming (the consumer): a first-order filter (cm848_signedFirstOrderFilter on an error x fuel_demand_ema_gain_cal / 512, coefficient pointer = fuel_demand_ema_coeff_ptr -> coefficient 4, output fuel_demand_filtered_ema, accumulator injection_timing_compensation_int) whose output scales injection timing compensation terms: coefficient 1 -> injection_timing_scale_factor, 2 -> injection_timing_ema_coeff_computed, 3 -> injection_timing_compensation_scale, each optionally scheduled by |filtered output| through the coefficient N scale tables. The confirmed rows are the filter itself (coefficient 4, the coefficient pointer, input gain, output limits, output, snapshot) and the five injection_timing_compensation_* rows; the coefficient 1 to 3 rows are left uncertain with the planned scheme fuel_demand_filter_coefficient_<n>_<base|working|alternate|scaling_enable|scale_axis|scale_values|scale_cached_axis_offset>, which spells out coeff -> coefficient and ema -> filter and keeps the fuel demand vocabulary the wave-3 name fuel_demand_filter_coefficient_working_set_code already uses; whether fuel demand is the right domain is medium confidence. The accumulator word injection_timing_compensation_int (0x40a8d7) is reset together with fuel_demand_filtered_ema when the output leaves its limits, so it is the filter accumulator (misnamed), not renamed here.')
SETS = [
  ('0x00406fb4', 'fuel_ema_coeff_1_cal', 'fuel_demand_filter_coefficient_1_base', 'Base set coefficient 1 (ROM, copied to the selected set when set code 0x10).'),
  ('0x00406fb6', 'fuel_ema_coeff_3_cal', 'fuel_demand_filter_coefficient_3_base', 'Base set coefficient 3 (ROM).'),
  ('0x00406fb8', 'fuel_ema_coeff_2_cal', 'fuel_demand_filter_coefficient_2_base', 'Base set coefficient 2 (ROM).'),
  ('0x00406fba', 'fuel_ema_coeff_4_cal', 'fuel_demand_filter_coefficient_4_base', 'Base set coefficient 4 (ROM, the filter coefficient).'),
  ('0x0040a8cb', 'fuel_ema_coeff_1', 'fuel_demand_filter_coefficient_1', 'Selected set coefficient 1: written by selectSensorRawChannels and cm848_initSensorRawChannels, read by cm848_processTorqueLimitTiming.'),
  ('0x0040a8cd', 'fuel_ema_coeff_2', 'fuel_demand_filter_coefficient_2', 'Selected set coefficient 2 (same writers / reader).'),
  ('0x0040a8cf', 'fuel_ema_coeff_3', 'fuel_demand_filter_coefficient_3', 'Selected set coefficient 3 (same writers / reader).'),
  ('0x0040a8d1', 'fuel_ema_coeff_4', 'fuel_demand_filter_coefficient_4', 'Selected set coefficient 4: the filter coefficient the pointer word points at (7 writes, read through the pointer).'),
  ('0x0040a8ad', 'fuel_ema_coeff_3_working', 'fuel_demand_filter_coefficient_3_working', 'Working set coefficient 3 written by cm848_processSystemStatusLimits, read by selectSensorRawChannels. Packed halfword block 0x40a8ad-0x40a8b7: the odd-address accesses are real.'),
  ('0x0040a8af', 'fuel_ema_coeff_4_working', 'fuel_demand_filter_coefficient_4_working', 'Working set coefficient 4 (same writer / reader).'),
  ('0x0040a8b3', 'fuel_ema_coeff_2_working', 'fuel_demand_filter_coefficient_2_working', 'Working set coefficient 2 (same writer / reader).'),
  ('0x0040a8b5', 'fuel_ema_coeff_1_working', 'fuel_demand_filter_coefficient_1_working', 'Working set coefficient 1 (same writer / reader).'),
  ('0x0040a8b9', 'fuel_ema_coeff_1_alternate', 'fuel_demand_filter_coefficient_1_alternate', 'Alternate set coefficient 1, write-only here (3 writes in selectSensorRawChannels).'),
  ('0x0040a8bb', 'fuel_ema_coeff_2_alternate', 'fuel_demand_filter_coefficient_2_alternate', 'Alternate set coefficient 2, write-only.'),
  ('0x0040a8bd', 'fuel_ema_coeff_3_alternate', 'fuel_demand_filter_coefficient_3_alternate', 'Alternate set coefficient 3, write-only.'),
  ('0x0040a8bf', 'fuel_ema_coeff_4_alternate', 'fuel_demand_filter_coefficient_4_alternate', 'Alternate set coefficient 4, write-only.'),
  ('0x0040a8d3', 'fuel_demand_ema_coeff_ptr', 'fuel_demand_filter_coefficient_pointer', 'Pointer to coefficient 4, first word of the filter state passed to cm848_signedFirstOrderFilter (0 reads by address, 3 writes).'),
  ('0x00406fbc', 'fuel_demand_ema_gain_cal', 'fuel_demand_filter_input_gain', 'Multiplier / 512 on the input error of the filter in cm848_processTorqueLimitTiming (1 read). ROM address, no _cal.'),
  ('0x00406fbe', 'fuel_demand_ema_upper_limit_cal', 'fuel_demand_filter_output_upper_limit', 'Upper limit of fuel_demand_filtered_ema: above it the output and accumulator are set to the limit (1 read). ROM address, no _cal.'),
  ('0x00406fc0', 'fuel_demand_ema_lower_limit_cal', 'fuel_demand_filter_output_lower_limit', 'Lower limit of fuel_demand_filtered_ema (1 read). ROM address, no _cal.'),
  ('0x0040a8c3', 'fuel_demand_filtered_ema', 'fuel_demand_filter_output', 'Output of the first-order filter in cm848_processTorqueLimitTiming; also scheduled the coefficient scale lookups.'),
  ('0x00406fd4', 'fuel_ema_coeff3_scaling_enable_cal', 'fuel_demand_filter_coefficient_3_scaling_enable', 'Enables the |filter output| scheduling of coefficient 3 (1 read). ROM address, no _cal.'),
  ('0x00406fd6', 'fuel_ema_coeff1_scaling_enable_cal', 'fuel_demand_filter_coefficient_1_scaling_enable', 'Enables the scheduling of coefficient 1 (1 read). ROM address, no _cal.'),
  ('0x00406fd8', 'fuel_ema_coeff2_input_select_cal', 'fuel_demand_filter_coefficient_2_scaling_enable', 'Selects the scheduled path for coefficient 2 (0 = plain coefficient) (1 read). ROM address, no _cal.'),
  ('0x00406ff0', 'fuel_ema_coeff3_scale_axis_cal', 'fuel_demand_filter_coefficient_3_scale_axis', 'word[14] lookup axis (absolute filter output) of the coefficient 3 scale lookup. ROM address, no _cal.'),
  ('0x0040700c', 'fuel_ema_coeff3_scale_output_cal', 'fuel_demand_filter_coefficient_3_scale_values', 'word[14] lookup values (multiplier / 256) for coefficient 3. ROM address, no _cal.'),
  ('0x00407028', 'fuel_ema_coeff1_scale_axis_cal', 'fuel_demand_filter_coefficient_1_scale_axis', 'word[14] lookup axis for coefficient 1. ROM address, no _cal.'),
  ('0x00407044', 'fuel_ema_coeff1_scale_output_cal', 'fuel_demand_filter_coefficient_1_scale_values', 'word[14] lookup values for coefficient 1. ROM address, no _cal.'),
  ('0x00407060', 'fuel_ema_coeff2_scale_axis_cal', 'fuel_demand_filter_coefficient_2_scale_axis', 'word[14] lookup axis for coefficient 2. ROM address, no _cal.'),
  ('0x0040707c', 'fuel_ema_coeff2_scale_output_cal', 'fuel_demand_filter_coefficient_2_scale_values', 'word[14] lookup values for coefficient 2. ROM address, no _cal.'),
]
def keep_filter_row(new):
    return (new.startswith('fuel_demand_filter_coefficient_4') or new in ('fuel_demand_filter_coefficient_pointer', 'fuel_demand_filter_input_gain', 'fuel_demand_filter_output_upper_limit', 'fuel_demand_filter_output_lower_limit', 'fuel_demand_filter_output'))


for address, old, new, text in SETS:
    if keep_filter_row(new):
        G(address, old, new, 'xref_addr.py and the .cpp (cm848_processTorqueLimitTiming / selectSensorRawChannels): ' + text)
    else:
        G(address, old, None, 'Left uncertain: ' + text + ' Coefficients 1 to 3 scale injection timing compensation terms, not the filter, so the fuel demand filter wording is unproven; scheme if the domain is confirmed: ' + new + '.', verdict='uncertain')
CACHES = [
  ('0x003fa896', 'fuel_ema_coeff_slot_state_1', 'fuel_demand_filter_coefficient_3_scale_cached_axis_offset', 'cache word passed with the coefficient 3 scale axis / values'),
  ('0x003fa898', 'fuel_ema_coeff_slot_state_2', 'fuel_demand_filter_coefficient_1_scale_cached_axis_offset', 'cache word passed with the coefficient 1 scale axis / values'),
  ('0x003fa89a', 'fuel_ema_coeff_slot_state_3', 'fuel_demand_filter_coefficient_2_scale_cached_axis_offset', 'cache word passed with the coefficient 2 scale axis / values'),
  ('0x003fa894', 'fuel_demand_ema_snapshot', 'fuel_demand_filter_output_snapshot', 'copy of fuel_demand_filtered_ema made by cm848_calculateTimingCompensation / cm848_processTorqueLimitTiming (0 reads by address, 2 writes)'),
]
for address, old, new, text in CACHES:
    if new.endswith('_snapshot'):
        G(address, old, new, 'cm848_processTorqueLimitTiming / cm848_calculateTimingCompensation: ' + text + '.' + BOOT)
    else:
        G(address, old, None, 'Left uncertain: lookupTableInterpolation first argument in cm848_processTorqueLimitTiming, ' + text + '; it belongs to a coefficient 1 to 3 scale lookup, scheme if the domain is confirmed: ' + new + '.' + BOOT, verdict='uncertain')
G('0x00406fc2', 'injection_timing_compensation_limit_cal', 'injection_timing_compensation_limit_upper',
  'Upper clamp of the compensation accumulator in cm848_processTorqueLimitTiming, paired with injection_timing_compensation_limit_lower (0x406fc4, lower clamp), second read in cm848_initSensorRawChannels. ROM address, so the _cal goes.')
G('0x00406fcc', 'injection_timing_compensation_lower_cal', 'injection_timing_compensation_calculation_lower_limit',
  'Lower clamp of the accumulator in cm848_calculateTimingCompensation (1 read, 0 writes), a different pair from the limit_lower / limit_upper clamp of cm848_processTorqueLimitTiming. ROM address, so the _cal goes.')
G('0x00406fce', 'injection_timing_compensation_upper_cal', 'injection_timing_compensation_calculation_upper_limit',
  'Upper clamp of the same accumulator calculation (1 read, 0 writes). ROM address, so the _cal goes.')
G('0x00406fe2', 'injection_timing_compensation_addend_cal', 'injection_timing_compensation_addend',
  'Addend limited by injection_timing_max_cal_load in cm848_calculateTimingCompensation (1 read, 0 writes). ROM address, so the _cal goes.')
G('0x00406fc6', 'injection_timing_compensation_init_cal', 'injection_timing_compensation_initial_value',
  'Preset of the accumulator and injection_timing_compensation_b in cm848_processTorqueLimitTiming for governor mode 0xc (1 read, 0 writes). ROM address, so the _cal goes.')

# ---------------------------------------------------------------------------------------------
# FAMILY 8: sensor channel 75 functions and the lookup cache words
# ---------------------------------------------------------------------------------------------
F('0x00506840', 'governor_speedFault_filterProcess_update', 'cm848_updateSensorChannel75ReferencedValue',
  'Copies sensor_channel75_value and its calibration thresholds into the fault state filter block at 0x3fbcc6, runs cm848_processFaultStateWithFilter on it, sets or clears bit 0x4000 of diagnostic_status_bits_b from the result, and computes sensor_channel75_value_minus_reference (the value minus the filter block reference word, or the constant DAT_00406756 when DAT_003fd7f6 is nonzero) (was governor_speedFault_filterProcess_update).',
  'Read in full (20 lines); the governor speed vocabulary has no basis: the only signal it handles is sensor channel 75. The sensor identity is still open (wave 3 note), so the name stays generic.')
F('0x00506964', 'boost_pressureSource_faultSelect_update', 'cm848_selectBoostPressureFromSensorChannel75',
  'Selects boost_pressure_filtered: sensor_channel75_value_minus_reference when the combined fault status (sensor_channel75_fault_status plus bit 8 from diagnostic_status_bits_b bit 0x4000 and bit 0x20 from diagnostic_status_bits bit 0x20) is 0, otherwise sensor_channel75_default_value; sets boost_correction_block_flag (0 or 2) and boost_fuel_mode_active from the result (was boost_pressureSource_faultSelect_update).',
  'Read in full (30 lines); the old name already said boost pressure, the new one names the actual source channel.')
F('0x00507214', 'governor_speedRamp_stabilityFlag_calc', None, None,
  'Compares governor_speed_ramp_output with sensor_channel75_value_minus_reference and sets governor_speed_ramp_pid_stable_gate; the governor speed vocabulary may be wrong (the compared channel is a pressure-like referenced value) but the purpose was not settled in the part read, so no name is proposed.', verdict='uncertain')
G('0x003fa10a', 'diag_state_group3_c_state', 'all_speed_governor_coolant_fuel_adjustment_cached_axis_offset',
  'First argument of the coolant temperature lookup (all_speed_governor_coolant_fuel_adjustment_axis / _values) in cm848_calculateAllSpeedGovernorNoLoadFuel, initialised to 2 by cm848_initFuelTimingTableSizes; same naming as the wave-3 droop blend cache words.' + BOOT)
G('0x003fa10e', 'diag_state_group3_b_state', 'all_speed_governor_friction_fuel_blend_0_cached_axis_offset',
  'First argument of the friction fuel blend 0 lookup in cm848_calculateAllSpeedGovernorNoLoadFuel (two call sites).' + BOOT)
G('0x003fa10c', 'diag_state_group3_a_state', 'all_speed_governor_friction_fuel_blend_128_cached_axis_offset',
  'First argument of the friction fuel blend 128 lookup in cm848_calculateAllSpeedGovernorNoLoadFuel (two call sites).' + BOOT)
G('0x003fa8a8', 'fuel_ema_mode_slot_state_2', 'engine_retarder_torque_cached_axis_offset_2',
  'Initialised to 2 together with 0x3fa8a6 by cm848_initializeEngineRetarderTorqueLookupCache, whose plate already calls the pair engine_retarder_torque_cached_axis_offset / _2; no reader (the single lookup in cm848_calculateEngineRetarderTorque uses only 0x3fa8a6).' + BOOT)
G('0x003fa114', 'diag_state_group4_a_state', None,
  'Only written (2) by cm848_initLookupTableParams (xref_addr.py: 0 reads / 1 write, .cpp line 9885); no lookup in the file passes it and no other access exists, so it stays unnamed.' + BOOT, verdict='uncertain')
G('0x003fa116', 'diag_state_group4_d_state', None,
  'Only written (2) by cm848_initLookupTableParams next to 0x3fa114; no reader found.' + BOOT, verdict='uncertain')


N('LABEL CHECK before applying 0x3fb54c: cm848_processProtectionSystemBit3 stores the torque converter lockup state at 0x3fb54e (disassembly: lis 0x40, addi -19122, sth at 0x41428; loads at 0x4157c / 0x41798) and cm848_processFuelEfficiencyTrim counts at 0x3fb54c (addi -19124; lhz 0x42074, sth 0x4207c / 0x4212c), but the .cpp prints the plain name governor_j1939_fuel_input_counter for the 0x3fb54e accesses and the underscore name for the 0x3fb54c ones, and never prints the CSV name tc_lockup_disengage_state of 0x3fb54e (which is the right name for it). The CSV rows are 0x3fb54c governor_j1939_fuel_input_counter and 0x3fb54e tc_lockup_disengage_state, so the .cpp labels look swapped (the boot kernel image has the function cm848_validateDiagnosticRequestLengthAndAuthorization at RAM 0x3fb54c = ROM 0x597c, called from mpc555_diagService25_executeFunction at .cpp line 1132, so the function-image symbol owns the address and the data word renders with the underscore). After the rename expect the boot call at .cpp line 1132 and the 0x3fb54e lockup accesses of cm848_updateEngineRetarderEnableState to print the new name (they print the old name now); if that is not acceptable keep the old name for this row or fix the label mapping first. No row is proposed for 0x3fb54e. Whole-window check: of the 51 window rows only 0x3fb54c has a call by name or func_ / FUN_ label in the .cpp; the raw boot ROM scan found no load or store of any of the 51 addresses.')
N('Skipped on purpose: the type notes of the [W3 governor] leads (j1939_diag_code / 0x3fee34 dword to word, 0x3fee3a word to dword, the 0x3fee3e row) because 0x3fee34-0x3fee3d is time-shared with boot users and no type change is proposed for time-shared words; the oil change monitor offsets note and the engine_power_accumulator_increment_axis / _values axis (no new evidence); the J1939 DB has no SPN list for PGN 65249, so the RC payload bytes got positional names only.')
N('Not renamed in the retarder cluster (listed so they are not lost): governor_cruise_mode_count (0x3fb540), governor_enable_delay_counter (0x3fb54a), governor_cruise_enable_count_cal (0x408e9e) and cruise_rpm_range_low / mid / high_cal (0x408ea6 / 0x408eac / 0x408eae) form the engine speed dependent engage delay chain of cm848_updateEngineRetarderActiveState whose writes to the hold flag are overwritten by the unconditional clear; fuel_demand_rate_minimum_fuel_mode_1_value (0x40a370, only the init writes 0) and engine_idle_cal_valid_flag (0x40a35c, write-only) belong to the same logic; protection_monitored_rpm_threshold_cal (0x408ebc) is the governor mode 4 speed threshold of the enter / exit conditions but what protection_monitored_rpm is was not checked.')

# ---------------------------------------------------------------------------------------------
# WRITE + VALIDATE (keep at the bottom)
# ---------------------------------------------------------------------------------------------


def load_existing():
    existing = {}
    by_address = {}
    for name in ['global_variables.csv', 'function_renames.csv', 'arrays.csv', 'constants.csv', 'enums.csv']:
        with open(CSV_DIR + name, newline='') as handle:
            for line in handle:
                if line.startswith('#') or not line.strip():
                    continue
                parts = line.rstrip('\n').split(',', 3)
                if len(parts) < 2 or not parts[0].startswith('0x'):
                    continue
                existing.setdefault(parts[1].strip(), []).append(name + ':' + parts[0])
                if name in ('global_variables.csv', 'function_renames.csv'):
                    by_address[(name[:3], int(parts[0], 16))] = parts[1].strip()
    return existing, by_address


BANNED = re.compile(r'(^|_)(ptr|pct|coeff|coef|calc|init|temp|tmp|cnt|val|cfg|ctrl|msg|req|resp|cmd|idx|prev|cur|src|dst|addr|num|mgr|buf|reg|ema|hex|diag)(_|$)')


def validate():
    existing, by_address = load_existing()
    problems = []
    seen_new = {}
    for index, row in enumerate(rows):
        kind = row['kind']
        if kind in ('function', 'global', 'new_global'):
            address = int(row['address'], 16)
        if kind in ('function', 'global'):
            table = 'fun' if kind == 'function' else 'glo'
            current = by_address.get((table, address))
            if current != row['old']:
                problems.append('row %d: old %s at %s is %s in the CSV' % (index, row['old'], row['address'], current))
        if kind == 'new_global':
            if ('glo', address) in by_address:
                problems.append('row %d: new_global %s already has a row (%s)' % (index, row['address'], by_address[('glo', address)]))
        new = row.get('new')
        if new and kind in ('function', 'global', 'new_global'):
            if new in existing:
                problems.append('row %d: new name %s exists: %s' % (index, new, existing[new]))
            if new in seen_new:
                problems.append('row %d: new name %s repeated (row %d)' % (index, new, seen_new[new]))
            seen_new[new] = index
            if BANNED.search(new) or re.search(r'0x|[0-9a-f]{4,}$', new) and re.search(r'(^|_)(0x)', new):
                problems.append('row %d: banned token in %s' % (index, new))
            if re.search(r'(^|_)protection(_|$)', new) and 'load_protection' not in new:
                problems.append('row %d: bare protection in %s' % (index, new))
            if kind != 'function':
                in_mirror = 0x3fd482 <= address <= 0x3feec1
                if in_mirror and not new.endswith('_cal'):
                    problems.append('row %d: %s at %s is in the EEPROM mirror but has no _cal' % (index, new, row['address']))
                if not in_mirror and new.endswith('_cal'):
                    problems.append('row %d: %s at %s is outside the EEPROM mirror but has _cal' % (index, new, row['address']))
            if kind == 'function' and not re.fullmatch(r'cm848_[a-z][A-Za-z0-9]*', new):
                problems.append('row %d: function name %s is not cm848_camelCase' % (index, new))
            if kind != 'function' and not re.fullmatch(r'[a-z][a-z0-9_]*', new):
                problems.append('row %d: global name %s is not snake_case' % (index, new))
        if kind in ('global', 'new_global') and ((0x3f9800 <= address <= 0x3fdb30) or (0x3fee08 <= address <= 0x3fee3d)):
            if 'boot user' not in row.get('evidence', '').lower():
                problems.append('row %d: window address %s lacks the boot-user evidence' % (index, row['address']))
        if kind in ('function', 'global') and row['verdict'] == 'confirmed' and not row.get('new'):
            problems.append('row %d: confirmed without new' % index)
        if kind == 'function' and row.get('new') and not row.get('plate_comment', '').rstrip().endswith('(was ' + row['old'] + ').'):
            problems.append('row %d: plate does not end with (was %s).' % (index, row['old']))
    return problems


if __name__ == '__main__':
    problems = validate()
    with open(OUT_FILE, 'w') as handle:
        for row in rows:
            handle.write(json.dumps(row) + '\n')
    counts = {}
    for row in rows:
        key = row['kind'] + ('/' + row['verdict'] if 'verdict' in row else '')
        counts[key] = counts.get(key, 0) + 1
    print('rows', len(rows), counts)
    print('PROBLEMS', len(problems))
    for problem in problems:
        print(' ', problem)
