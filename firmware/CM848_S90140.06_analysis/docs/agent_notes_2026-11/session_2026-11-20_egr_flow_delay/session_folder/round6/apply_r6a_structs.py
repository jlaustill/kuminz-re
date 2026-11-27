"""Round 6 stage A: the struct type and field renames of the TSC1 / ETC1 vocabulary (label-only), with new field
comments; the label accept_etc1_command; the 0x5c3b6 artifact row. Run AFTER apply_hand_worklist.py (the globals).
- structure_definitions.csv: the three types and their renamed fields (new comment each), field types that name an
  old type; every comment column: old type tokens, qualified field references (<instance>.<old> / -><old>), unique
  bare old field tokens, and the globals / functions of the given extra map (refresh_references.py skips this file
  and enums.csv).
- global_variables.csv: the type column, the 0x5c3b6 row deleted, the qualified field references in comments.
- labels.csv: the label.
- Checks: every new field name is free (no field of another struct, no .cpp identifier), every new type / label
  name is free; a renamed old field name that another struct also uses, or that the .cpp uses outside a field
  access, counts as generic: only its qualified references are refreshed.
Appends type / field / label rows to <map.csv>; writes <refresh_map.csv> = the map without the generic field rows.
usage: apply_r6a_structs.py <repo> <map.csv> <refresh_map.csv> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo, map_path, refresh_path = sys.argv[1:4]
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
CPP = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
CODE = re.sub(r"/\*.*?\*/", " ", CPP, flags=re.S)
CODE = re.sub(r"//[^\n]*", " ", CODE)
S, R = "j1939_powertrain_control_state", "j1939_powertrain_messages_received"
INSTANCES = {"etc1_governor_state_t": ("j1939_tsc1_override_state", S),
             "etc1_message_t": ("j1939_tsc1_received", R),
             "etc1_config_entry_t": ("etc1_config_entry_t_0005c3b4", "tsc1_source_configuration_table")}
TYPES = {"etc1_governor_state_t": "j1939_powertrain_control_state_t",
         "etc1_message_t": "j1939_powertrain_messages_received_t",
         "etc1_config_entry_t": "tsc1_source_configuration_t"}
FIELDS = {
    "etc1_governor_state_t": {
        "governor_mode": ("tsc1_override_control_mode",
            "the accepted engine TSC1 request's override control mode (J1939 SPN 695: 0 override disabled / 1 speed "
            "control / 2 torque control / 3 speed and torque limit control); processEngineTsc1Request sets it from "
            "byte 1 bits 1-2 and cm848_runTsc1LostManagement sets 3 / 0 (was governor_mode)"),
        "torque_limit_mode_select": ("high_idle_override_active_flag",
            "1 = the high idle override is granted: ETC1 byte 5 bits 1-2 (SPN 606 engine momentary overspeed enable) "
            "= 01 while the engine TSC1 speed control (mode 1) comes from source index 1; selectEngineSpeedLimit then "
            "applies the e2m Jcomm_High_Idle_Override_Speed (0x5c39a) (was torque_limit_mode_select)"),
        "etc1_disable_control": ("etc1_out_of_gear_flag",
            "e2m Jcomm_Out_of_Gear: 1 when ETC1 byte 1 reports the driveline disengaged (SPN 560 = 00) and no shift in "
            "process (SPN 574 = 00); cleared when etc1_out_of_gear_timer runs out (was etc1_disable_control)"),
        "etc1_torque_limit_value": ("tsc1_speed_limit",
            "the TSC1 speed limit of mode 3 (the requested speed); cm848_runTsc1LostManagement ramps it up by "
            "tsc1_lost_speed_ramp_rate or resets it to the engine speed; read by selectEngineSpeedLimit (was "
            "etc1_torque_limit_value)"),
        "etc1_speed_setpoint": ("tsc1_requested_percent_torque_times_256",
            "mode 2 (torque control): the requested torque in percent x 256 (byte 4 x 256 - 32000 = (raw - 125) x "
            "256) (was etc1_speed_setpoint)"),
        "etc1_capped_speed_target": ("tsc1_requested_speed_capped",
            "mode 1 (speed control): the requested speed capped at 24000 (3000 rpm); read by "
            "cm848_selectTsc1SpeedControlMode (was etc1_capped_speed_target)"),
        "etc1_control_flags": ("tsc1_speed_control_flag",
            "1 while the accepted request is speed control (mode 1), else 0; no reader in the decompile (was "
            "etc1_control_flags)"),
        "etc1_mode3_torque_limit": ("tsc1_torque_limit_fueling",
            "mode 3: the requested torque limit as fueling ((j1939_reference_engine_fueling - fuel_demand_norm_zero_cal) "
            "x percent / 100 + the zero fueling, at least 0); cm848_runTsc1LostManagement ramps it through "
            "tsc1_torque_limit_ramp_integrator; read by cm848_applyTsc1TorqueLimit and cm848_arbitrateGovernedFueling "
            "(was etc1_mode3_torque_limit)"),
        "etc1_torque_limit_calc": ("tsc1_torque_control_fueling",
            "mode 2 (torque control): the requested torque as fueling (the conversion of tsc1_torque_limit_fueling); "
            "read by cm848_setEngineOperatingMode1 (was etc1_torque_limit_calc)"),
        "etc1_speed_control_mode": ("tsc1_requested_speed_control_condition",
            "TSC1 byte 1 bits 3-4 (J1939 SPN 696 Engine Requested Speed Control Conditions) of a speed control "
            "request: the index into j1939_tsc1_speed_control_condition_gain_sets (was etc1_speed_control_mode)"),
        "etc1_active_state": ("tsc1_controlling_data_link",
            "the data link of the accepted control request: 1 = J1939 (processEngineTsc1Request); a timeout counts as "
            "a J1939 link fault when it is 1, else as a J1708 (J1922) one. The first argument of the ignored request "
            "and source configuration lookups (was etc1_active_state)"),
        "etc1_speed_disable_latch": ("etc1_out_of_gear_latch",
            "set to 1 with etc1_out_of_gear_flag; nothing clears or reads it in the decompile (was "
            "etc1_speed_disable_latch)"),
        "etc1_control_active": ("etc1_out_of_gear_data_valid_flag",
            "1 while ETC1 gives a valid driveline / shift status with a J1939 vehicle speed source "
            "(vehicle_speed_sensor_type_cal 4 / 5); cleared when etc1_out_of_gear_data_timer or the ETC1 message "
            "timeout runs out; read by cm848_updateDrivetrainRatio and etcTransmissionModeControl (was "
            "etc1_control_active)"),
        "etc1_spn573_tc_lockup_disengage": ("etc1_spn573_torque_converter_lockup_disengaged_flag",
            "ETC1 byte 1 bits 3-4 (SPN 573): 1 when the torque converter lockup is disengaged (00), 0 when engaged "
            "(01); set to 0 when etc1_torque_converter_lockup_timer runs out; read by "
            "cm848_updateEngineRetarderEnableState (was etc1_spn573_tc_lockup_disengage)"),
        "etc1_handler_initialized": ("etc1_output_shaft_speed_fault_hold_off_flag",
            "1 holds off the J1939 output shaft speed fault: while switch input bit 0 is 0, or while the engine has "
            "run for fewer passes than j1939_pgn61442_output_shaft_speed_fault_run_state_delay (e2m "
            "J1939_Powerup_Runtime_Fault_Delay) (was etc1_handler_initialized)"),
        "speed_control_target": ("time_limited_node_status_bits",
            "bit 0 = an engine TSC1 sender hit its time limit and went into the ignored request list; bit 1 = the same "
            "for an engine retarder TSC1 sender; bit 2 = the high idle override hit its time limit (e2m "
            "Jcomm_Recovery_Time: a time limited node must be silent before its messages count again). "
            "processEngineTsc1Request clears bit 0 on override disabled; ETC1 SPN 606 = 00 and the high idle timeout "
            "clear bit 2 (was speed_control_target)"),
        "etc1_speed_error_timeout_flag": ("tsc1_request_timed_out_flag",
            "1 when tsc1_request_timeout_count is below 2 (the accepted engine TSC1 request timed out); "
            "cm848_runTsc1LostManagement then ramps the limits (was etc1_speed_error_timeout_flag)"),
        "etc1_activation_confirm_timer": ("tsc1_request_time_limit_timer",
            "the time limit of a speed / torque control request: the sender's tsc1_source_configuration_t "
            "speed_control_time_limit / torque_control_time_limit + 1 when the request starts or changes; at 1 the "
            "sender goes into the ignored request list (bit 0 of time_limited_node_status_bits) and "
            "cm848_runTsc1LostManagement runs (was etc1_activation_confirm_timer)"),
        "etc1_speed_error_timeout": ("tsc1_request_timeout_count",
            "the accepted engine TSC1 request's message timeout: the sender's request timeout for the mode (+4 / +8 / "
            "+0xc of its configuration entry) + 1 on each accepted message, counted down each pass (was "
            "etc1_speed_error_timeout)"),
        "etc1_error_fault_timer": ("retarder_tsc1_request_time_limit_timer",
            "the engine retarder TSC1 torque control (mode 2) time limit: retarder_torque_control_time_limit + 1 "
            "of the retarder sender's entry when its request starts or changes; at 1 the sender goes into the "
            "retarder ignored request list (bit 1 of time_limited_node_status_bits) (was etc1_error_fault_timer)"),
        "etc1_multiframe_timeout": ("retarder_tsc1_request_timeout_count",
            "the engine retarder TSC1 request's message timeout: the entry's retarder request timeout (+0xe mode 2 / "
            "+0x12 mode 3) + 1, loaded by cm848_processEngineRetarderTsc1Request; at 1 the retarder request ends "
            "(cm848_resetGovernorState) (was etc1_multiframe_timeout)"),
        "etc1_torque_mode_timer": ("high_idle_override_timeout_timer",
            "the high idle override's message timeout: j1939_pgn61442_engine_overspeed_enable_timeout + 1 (e2m "
            "Jcomm_Eng_Overspeed_TO) on each ETC1 with SPN 606 = 01, or j1939_time_limited_node_recovery_time + 1 "
            "(Jcomm_Recovery_Time) while high_idle_override_recovery_flag is set; at 1 the override and the recovery "
            "end (was etc1_torque_mode_timer)"),
        "etc1_torque_active_timer": ("high_idle_override_time_limit_timer",
            "the high idle override's time limit: j1939_pgn61442_engine_overspeed_enable_time_limit + 1 (e2m "
            "Jcomm_Eng_Overspeed_TL), loaded once per request; at 1 the override ends and "
            "high_idle_override_recovery_flag is set (was etc1_torque_active_timer)"),
        "etc1_speed_override_timer": ("etc1_out_of_gear_timer",
            "j1939_pgn61442_driveline_disengaged_timeout + 1 (e2m Jcomm_Driveline_Disengaged_TO: the time out for "
            "Jcomm_Out_of_Gear) while ETC1 reports out of gear; at 1 etc1_out_of_gear_flag is cleared (was "
            "etc1_speed_override_timer)"),
        "etc1_torque_limit_timer": ("etc1_progressive_shift_disable_timer",
            "j1939_pgn61442_progressive_shift_disable_timeout + 1 (e2m Jcomm_Prog_Shift_TO) while ETC1 byte 5 bits "
            "3-4 (SPN 607) = 01; at 1 etc1_spn607_progressive_shift_disable is cleared (was etc1_torque_limit_timer)"),
        "etc1_mode_transition_timer": ("retarder_tsc1_mode_transition_timer",
            "an engine retarder TSC1 timer: cm848_processEngineRetarderTsc1Request loads it with the request timeout "
            "(mode 2 with a zero torque request, mode 3 without a torque limit); at 1 it counts as a link timeout. "
            "Its role is not settled (was etc1_mode_transition_timer)"),
        "etc1_speed_mode_flag": ("retarder_tsc1_speed_mode_flag",
            "written 0 by the engine retarder TSC1 functions and the resets; no reader in the decompile (was "
            "etc1_speed_mode_flag)"),
        "etc1_mode_timeout": ("etc1_out_of_gear_data_timer",
            "j1939_pgn61442_out_of_gear_timeout + 1 (e2m Jcomm_OOG_Timeout: the time of no data link out of gear "
            "before it is calculated) on each valid ETC1 status; at 1 etc1_out_of_gear_data_valid_flag is cleared "
            "(was etc1_mode_timeout)"),
        "etc1_speed_cmd_timeout": ("etc1_output_shaft_speed_timer",
            "j1939_pgn61442_output_shaft_speed_timeout + 1 (e2m J1939_TSS_Timeout) on each valid ETC1 output shaft "
            "speed; at 0 (outside the hold-off) the speed is zeroed and the vehicle speed fault (bit 0x2000 of "
            "fault word 16-31) is set (was etc1_speed_cmd_timeout)"),
        "etc1_override_timeout": ("etc1_torque_converter_lockup_timer",
            "j1939_pgn61442_torque_converter_lockup_timeout (e2m J1939_TQ_Cnv_Lockup_TO) on each valid SPN 573; at 1 "
            "etc1_spn573_torque_converter_lockup_disengaged_flag is set to 0 (was etc1_override_timeout)"),
        "governor_mode_transition_counter": ("etc1_output_shaft_speed_run_state_count",
            "counts the passes the engine runs (RUNNING / ENGINE_BRAKE / OVERSPEED) with the J1939 speed source with "
            "gear ratio, for etc1_output_shaft_speed_fault_hold_off_flag (was governor_mode_transition_counter)"),
        "etc1_spn1482_source_address": ("tsc1_controlling_source_address",
            "the source address of the accepted engine TSC1 request (the sender in control). Not SPN 1482, which is "
            "ETC1's source address of the device controlling the transmission (was etc1_spn1482_source_address)"),
        "etc1_config_entry_ptr": ("tsc1_matched_source_configuration_ptr",
            "the tsc1_source_configuration_table entry cm848_findTsc1SourceConfiguration matched for the last sender "
            "(was etc1_config_entry_ptr)"),
        "etc1_active_config_ptr": ("tsc1_source_configuration_ptr",
            "the configuration entry of the accepted engine TSC1 sender (its request timeouts and time limits); a new "
            "sender takes over only with an entry at the same or an earlier position (was etc1_active_config_ptr)"),
        "etc1_secondary_config_ptr": ("retarder_tsc1_source_configuration_ptr",
            "the configuration entry of the accepted engine retarder TSC1 sender (+0xe / +0x10 / +0x12 read) (was "
            "etc1_secondary_config_ptr)"),
        "etc1_torque_limit_active": ("high_idle_override_recovery_flag",
            "1 after the high idle override hit its time limit: the transmission must stop asking for it for "
            "j1939_time_limited_node_recovery_time (e2m Jcomm_Recovery_Time) before it is granted again; cleared by "
            "ETC1 SPN 606 = 00 or when high_idle_override_timeout_timer runs out (was etc1_torque_limit_active)"),
    },
    "etc1_message_t": {
        "speed_previous": ("etc1_output_shaft_speed_previous",
            "output_shaft_speed_current before the latest valid ETC1 output shaft speed (was speed_previous)"),
        "byte1_status": ("etc1_status_byte_1",
            "ETC1 byte 1: bits 1-2 driveline engaged (SPN 560), 3-4 torque converter lockup engaged (SPN 573), 5-6 "
            "shift in process (SPN 574) (was byte1_status)"),
        "spn191_output_shaft_speed": ("etc1_spn191_output_shaft_speed",
            "ETC1 bytes 2-3: the transmission output shaft speed (SPN 191, 0.125 rpm) (was spn191_output_shaft_speed)"),
        "spn522_clutch_slip": ("etc1_spn522_percent_clutch_slip",
            "ETC1 byte 4: the percent clutch slip (SPN 522); no access found in the decompile (was spn522_clutch_slip)"),
        "byte5_control": ("etc1_status_byte_5",
            "ETC1 byte 5: bits 1-2 engine momentary overspeed enable (SPN 606), 3-4 progressive shift disable (SPN "
            "607) (was byte5_control)"),
        "control_word": ("tsc1_control_byte",
            "TSC1 byte 1: bits 1-2 override control mode (SPN 695), 3-4 requested speed control conditions (SPN 696), "
            "5-6 override control mode priority (SPN 897) (was control_word)"),
        "requested_speed": ("tsc1_requested_speed",
            "TSC1 bytes 2-3: the requested speed / speed limit (SPN 898, 0.125 rpm) (was requested_speed)"),
        "requested_torque": ("tsc1_requested_torque",
            "TSC1 byte 4: the requested torque / torque limit (SPN 518, percent + 125) (was requested_torque)"),
        "priority_byte": ("tsc1_accepted_priority",
            "the priority bits (byte 1 & 0x30) of the accepted request; a new sender needs an equal or higher "
            "priority (a value not above this) (was priority_byte)"),
        "speed_stored": ("tsc1_accepted_requested_speed",
            "the requested speed of the accepted speed control / limit request (modes 1 and 3); a mode 3 takeover at "
            "the same priority needs a lower torque or speed (was speed_stored, described as an SPN 191 copy)"),
        "torque_stored": ("tsc1_accepted_requested_torque",
            "the requested torque of the accepted torque control / limit request (modes 2 and 3) (was torque_stored, "
            "described as an SPN 522 copy)"),
    },
    "etc1_config_entry_t": {
        "match_key": ("data_link",
            "the data link the entry is for (1 = J1939; the 0xff source address wildcard counts only on 1) (was "
            "match_key)"),
        "speed_error_timeout_mode1": ("speed_control_request_timeout",
            "the request timeout of a speed control request (mode 1): tsc1_request_timeout_count reload (was "
            "speed_error_timeout_mode1)"),
        "activation_confirm_timeout_mode1": ("speed_control_time_limit",
            "the time limit of a speed control request: tsc1_request_time_limit_timer reload (was "
            "activation_confirm_timeout_mode1)"),
        "speed_error_timeout_mode2": ("torque_control_request_timeout",
            "the request timeout of a torque control request (mode 2) (was speed_error_timeout_mode2)"),
        "activation_confirm_timeout_mode2": ("torque_control_time_limit",
            "the time limit of a torque control request (was activation_confirm_timeout_mode2)"),
        "speed_error_timeout_mode3": ("speed_torque_limit_control_request_timeout",
            "the request timeout of a speed / torque limit control request (mode 3) (was speed_error_timeout_mode3)"),
        "multiframe_timeout_mode2": ("retarder_torque_control_request_timeout",
            "the engine retarder TSC1 torque control (mode 2) request timeout: retarder_tsc1_request_timeout_count "
            "reload (was multiframe_timeout_mode2)"),
        "error_fault_timeout": ("retarder_torque_control_time_limit",
            "the engine retarder TSC1 torque control time limit: retarder_tsc1_request_time_limit_timer reload (was "
            "error_fault_timeout)"),
        "multiframe_timeout_mode3": ("retarder_speed_torque_limit_control_request_timeout",
            "the engine retarder TSC1 speed / torque limit control (mode 3) request timeout (was "
            "multiframe_timeout_mode3)"),
    },
}
LABEL = ("0x00022f1c", "accept_etc1_command", "accept_tsc1_command",
         "Accept and apply the engine TSC1 (PGN 0) request after the source arbitration (was accept_etc1_command, "
         "described as an ETC1 (PGN 61442) driveline command)")
DELETE_GLOBAL = "0x0005c3b6"   # etc1_config_entry_t.conflict_0005c3b4.source_address_filter (no type, no render)
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
problems = []


def word(n):
    return re.compile(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])")


# --- checks --------------------------------------------------------------------------------------------------
sd_path = os.path.join(out, "structure_definitions.csv")
sd_lines = open(sd_path).read().split("\n")
other_fields = set()
for line in sd_lines:
    if line and not line.startswith("#"):
        row = next(csv.reader([line]))
        if len(row) > 2 and row[0] not in TYPES and row[2]:
            other_fields.add(row[2])
for t, nt in TYPES.items():
    if word(nt).search(CPP) or any(line.startswith(nt + ",") for line in sd_lines):
        problems.append(f"type name {nt} is taken")
if word(LABEL[2]).search(CPP):
    problems.append(f"label {LABEL[2]} is taken")
generic = set()
for t, fmap in FIELDS.items():
    news = [v[0] for v in fmap.values()]
    if len(set(news)) != len(news):
        problems.append(f"{t}: duplicate new field names")
    for old, (new, _) in fmap.items():
        if new in other_fields or word(new).search(CODE):
            problems.append(f"{t}.{new}: the name is taken")
        bare = [m for m in word(old).finditer(CODE) if not re.search(r"(\.|->)\s*$", CODE[max(0, m.start() - 3):m.start()])]
        if old in other_fields or bare:
            generic.add(old)
print("generic (qualified refresh only):", ", ".join(sorted(generic)))
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)

# --- the text replacements for comment columns ---------------------------------------------------------------
old_instances = {old_i: new_i for old_i, new_i in INSTANCES.values()}
qualified = []          # (pattern, replacement) for <instance>.<field> and ->field
for t, fmap in FIELDS.items():
    old_i, new_i = INSTANCES[t]
    for old, (new, _) in fmap.items():
        qualified.append((re.compile(r"(?<![A-Za-z0-9_])(?:" + re.escape(old_i) + "|" + re.escape(new_i) + r")\." +
                                     re.escape(old) + r"(?![A-Za-z0-9_])"), f"{new_i}.{new}"))
        qualified.append((re.compile(r"->" + re.escape(old) + r"(?![A-Za-z0-9_])"), f"->{new}"))
bare_tokens = {}        # unique old field tokens, old types, the label
for t, fmap in FIELDS.items():
    for old, (new, _) in fmap.items():
        if old not in generic:
            bare_tokens[old] = new
bare_tokens.update(TYPES)
bare_tokens[LABEL[1]] = LABEL[2]
gf_tokens = {}          # the globals / functions apply_hand_worklist.py already wrote to the map
if os.path.exists(map_path):
    for r in csv.DictReader(open(map_path)):
        if r["kind"] in ("global", "function") and r["old_label"]:
            gf_tokens[r["old_label"]] = r["name"]
print(f"{len(gf_tokens)} global / function renames from the map")


def refresh(text, with_globals=False):
    for pat, rep in qualified:
        text = pat.sub(rep, text)
    tokens = dict(bare_tokens, **gf_tokens) if with_globals else bare_tokens
    for old, new in sorted(tokens.items(), key=lambda kv: -len(kv[0])):
        def sub(m, new=new):
            return m.group(0) if HISTORY.search(text[max(0, m.start() - 12):m.start()]) else new
        text = word(old).sub(sub, text)
    return text


def write_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


# --- structure_definitions.csv -------------------------------------------------------------------------------
changed_fields = 0
new_sd = []
for line in sd_lines:
    if not line or line.startswith("#"):
        new_sd.append(line)
        continue
    row = next(csv.reader([line]))
    if row[0] in TYPES:
        fmap = FIELDS[row[0]]
        if len(row) > 2 and row[2] in fmap:
            row[2], row[5] = fmap[row[2]]
            changed_fields += 1
        elif len(row) > 5:
            row[5] = refresh(row[5], True)
        row[0] = TYPES[row[0]]
    elif len(row) > 5:
        row[5] = refresh(row[5], True)
    if len(row) > 3:
        for t, nt in TYPES.items():
            row[3] = word(t).sub(nt, row[3])
    new_sd.append(write_row(row) if row != next(csv.reader([line])) else line)
print(f"structure_definitions.csv: {changed_fields} fields renamed")

# --- global_variables.csv ------------------------------------------------------------------------------------
gv_path = os.path.join(out, "global_variables.csv")
gv_lines = open(gv_path).read().split("\n")
new_gv, deleted = [], 0
for line in gv_lines:
    if line.startswith(DELETE_GLOBAL + ","):
        deleted += 1
        continue
    if not line or line.startswith("#") or line.startswith("address,"):
        new_gv.append(line)
        continue
    row = next(csv.reader([line]))
    before = list(row)
    if len(row) > 2 and row[2] in TYPES:
        row[2] = TYPES[row[2]]
    if len(row) > 3:
        row[3] = refresh(row[3])
    new_gv.append(write_row(row) if row != before else line)
print(f"global_variables.csv: deleted {deleted} row")

# --- the other comment columns (qualified references only; refresh_references.py does the tokens) -------------
others = {}
for name, col in [("function_renames.csv", 2), ("labels.csv", 2), ("enums.csv", 3), ("constants.csv", 3),
                  ("arrays.csv", 4), ("deleted_functions.csv", 1)]:
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    lines, new_lines = open(p).read().split("\n"), []
    for line in lines:
        if not line or line.startswith("#"):
            new_lines.append(line)
            continue
        row = next(csv.reader([line]))
        before = list(row)
        if name == "labels.csv" and row[0] == LABEL[0] and row[1] == LABEL[1]:
            row[1], row[2] = LABEL[2], LABEL[3]
        elif len(row) > col:
            row[col] = refresh(row[col], True) if name == "enums.csv" else row[col]
            for pat, rep in qualified:
                row[col] = pat.sub(rep, row[col])
        new_lines.append(write_row(row) if row != before else line)
    others[p] = new_lines

if dry:
    sys.exit(0)
open(sd_path, "w").write("\n".join(new_sd))
open(gv_path, "w").write("\n".join(new_gv))
for p, lines in others.items():
    open(p, "w").write("\n".join(lines))
rows = [("", nt, t, "type") for t, nt in TYPES.items()]
rows += [("", new, old, "field") for fmap in FIELDS.values() for old, (new, _) in fmap.items()]
rows.append((LABEL[0], LABEL[2], LABEL[1], "label"))
new_file = not os.path.exists(map_path)
with open(map_path, "a") as f:
    if new_file:
        f.write("address,name,old_label,kind\n")
    for r in rows:
        f.write(",".join(r) + "\n")
with open(refresh_path, "w") as f:
    f.write("address,name,old_label,kind\n")
    for line in open(map_path).read().split("\n")[1:]:
        if not line:
            continue
        a, n, o, k = line.split(",")
        if k == "field" and o in generic:
            continue
        f.write(line + "\n")
print(f"map: {len(rows)} type / field / label rows; refresh map written")
