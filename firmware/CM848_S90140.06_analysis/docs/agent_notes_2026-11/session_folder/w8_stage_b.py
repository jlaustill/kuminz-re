"""Wave 8 stage B: the typing changes (struct split / rename, dword splits, retypes, enums, prototypes, locals).
Every edit asserts the row it changes; the six new rows inside split dwords go in afterwards with apply_extras stage 2.
usage: w8_stage_b.py <output dir> <renames dir>"""
import json
import os
import re
import sys

out, rdir = sys.argv[1:3]


def load(name):
    return open(os.path.join(out, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(out, name), "w").write("\n".join(lines))


# ---------- structure_definitions.csv ----------
sd = load("structure_definitions.csv")
start = sd.index("# Torque Limit Arbitration - multi-source torque limit selection")
assert sd[start + 3].startswith("torque_limit_arb_t,0x0040a2f6,main_injection_timing_source_code,")
assert all(sd[start + 3 + i].startswith("torque_limit_arb_t,0x0040a2f6,") for i in range(4))
sd[start:start + 7] = [
    "# Engine Speed Limit Arbitration - lowest-wins selection of the engine speed limit (the e2m HSG reference speed state block)",
    "# Written by cm848_selectEngineSpeedLimit and the source functions - read by the fuel limit and governor code",
    "# Total size: 6 bytes (0x0040a2f8-0x0040a2fd)",
    "engine_speed_limit_arbitration_t,0x0040a2f8,limiting_source_number,word,2,Number of the engine speed limit source that "
    "wins the arbitration (e2m HSG_Ref_Speed_State),,verified",
    "engine_speed_limit_arbitration_t,0x0040a2f8,applied_speed_limit,word,2,Engine speed limit applied by the governor in "
    "0.125 rpm counts - the ramped limit or the ramped limit plus the droop term capped by the droop cap (e2m "
    "HSG_Reference_Speed),,verified",
    "engine_speed_limit_arbitration_t,0x0040a2f8,lowest_source_speed_limit,word,2,Lowest engine speed limit of the sources "
    "in the current pass in 0.125 rpm counts - reset to engine_speed_limit_default_cal at the end of "
    "cm848_selectEngineSpeedLimit (e2m HSG_Ref_Speed_Before_Droop),,verified",
]
g = sd.index("# Governor PID State - PID controller variables for speed control")
assert sd[g + 3].startswith("governor_pid_t,0x0040af5a,proportional_gain,") and sd[g + 4].startswith("governor_pid_t,0x0040af5a,integral_term,")
sd[g:g + 5] = [
    "# Operating Mode Governor Output - the fuel demand of the engine operating mode governor as the output stages see it",
    "# Written by cm848_runOperatingModeSpeedGovernor and cm848_updateGovernorFromProtection (was governor_pid_t: nothing in it is a PID term)",
    "# Total size: 4 bytes (0x0040af5a-0x0040af5d)",
    "operating_mode_governor_output_t,0x0040af5a,fuel_demand,word,2,Fuel demand of the engine operating mode governor as the "
    "output stages see it (engine_operating_mode_fuel_demand or the protection limit) (was proportional_gain),,verified",
    "operating_mode_governor_output_t,0x0040af5a,mode_code,word,2,Copy of engine_operating_mode (1 2 5 6 7 8 30 37 38) or 4 "
    "when the output is replaced by the limit in cm848_updateGovernorFromProtection (was integral_term),,verified",
]
old83 = "engine_crank_state_t,0x0040b80a,run_state,word,2,Engine run state (ENGINE_OPERATING_MODE enum),,verified"
sd[sd.index(old83)] = ("engine_crank_state_t,0x0040b80a,run_state,word,2,Engine run state written by "
                       "mpc555_updateEngineRunState - a different variable from engine_operating_mode,,verified")
save("structure_definitions.csv", sd)

# ---------- enums.csv ----------
en = load("enums.csv")
i = en.index("# Engine Operating Mode State Machine (engine_operating_mode values)")
assert all(en[i + k].startswith("ENGINE_OPERATING_MODE,") for k in range(1, 6)) and not en[i + 6].startswith("ENGINE_OPERATING_MODE,")
eom = [
    (0, "NOT_SELECTED", "Cleared at the start of every pass by cm848_resetEngineOperatingMode; the selectors then run in call "
     "order 30 then 1 then 2 then 5 then 6 then 7 then 8 and each acts only while the mode is still 0 (first wins)"),
    (1, "TSC1_TORQUE_CONTROL", "cm848_setEngineOperatingMode1: J1939 TSC1 override control mode 2 (torque); the governor output "
     "is etc1_torque_limit_calc"),
    (2, "TSC1_SPEED_CONTROL", "cm848_engineMode_reset: J1939 TSC1 override control mode 1 (speed); the all-speed governor PID "
     "runs on etc1_capped_speed_target with the ROM coefficient record"),
    (5, "CALIBRATED_FIXED_FUEL_DEMAND", "cm848_setEngineOperatingMode5: bit 0 of engine_mode_control_flags (0 in every dump) "
     "makes the governor output a calibrated fuel demand; the feature behind it is not identified"),
    (6, "ACCELERATOR_PEDAL_FAULT", "cm848_transitionEngineOperatingMode: accelerator pedal input fault conditions; "
     "cm848_calculatePedalFaultModeFuelDemandAndSpeedLimit ramps the fuel only while the mode is 6"),
    (7, "VARIABLE_SPEED_GOVERNOR", "cm848_initEngineOperatingMode: variable_speed_governor_selected_flag = 1; the pedal sets a "
     "speed request and the all-speed governor PID runs (dump: 7)"),
    (8, "DUAL_AXIS_FUEL_DEMAND_TABLE", "cm848_initEngineOperatingState: left when no other selector claimed the pass; the "
     "governor output comes from cm848_calculateDualAxisFuelLimit (engine speed x tracked fuel demand tables)"),
    (30, "ALL_SPEED_GOVERNOR_RESTORE", "cm848_restoreEngineOperatingMode: engine_operating_mode_restore_valid_flag nonzero; "
     "loads the restore record 0x40a216-0x40a246 (never set in this build and RAM is zeroed at every start)"),
]
en[i:i + 6] = (["# Engine Operating Mode (engine_operating_mode 0x40b000): which governor drives the fuel this pass "
                "(corrected 2026-11-17 from every store of 0x40b000; 37 and 38 are only compared - never stored - so they "
                "have no member)"]
               + [f"ENGINE_OPERATING_MODE,{v},ENGINE_OPERATING_MODE_{n},{c},2" for v, n, c in eom])
en += ["# EGR valve control state (egr_valve_control_state 0x40a6ca / _previous 0x3fa78e; every store is in "
       "cm848_selectEgrValveControlState)"]
en += [f"EGR_VALVE_CONTROL_STATE,{v},EGR_VALVE_{n},{c},2" for v, n, c in (
    (0, "CLOSED_LOOP", "PID position control: cm848_selectEgrValveDutyByControlState takes egr_valve_pid_duty"),
    (1, "CLOSED_HOLD", "Open-loop closed-hold duty: egr_valve_closed_hold_flag is set"),
    (2, "USER_DUTY_OVERRIDE", "Fixed duty override: bit 1 of egr_valve_user_override_flags_cal is set"),
    (3, "AUTOZERO_DRIVE", "Position autozero drive: the autozero holding duty is output (the dump is permanently here)"),
    (4, "DISABLED", "Output disabled: logical output request 67 (the PWM enable) is clear; the duty is 0"))]
en += ["# Combustion chi source (combustion_chi_source_code 0x40a4a4 / combustion_base_chi_source_code 0x40a4e4; the "
       "values assigned in cm848_selectChiAndAlpha and cm848_determineBaseChi)"]
en += [f"COMBUSTION_CHI_SOURCE,{v},COMBUSTION_CHI_SOURCE_{n},{c},2" for v, n, c in (
    (1, "AMBIENT_AIR_DENSITY", "Base chi from the ambient air density protective chi table (the density chi is not smaller)"),
    (3, "COOLANT_TEMPERATURE", "Base chi from the coolant temperature protective chi table (the density chi is smaller)"),
    (10, "EGR_OFF", "Fixed EGR-off chi and level while EGR is requested off and no combustion status flag 0x08 / 0x10 / "
     "0x200 is set; the normal state on this truck (dump: 10)"),
    (12, "FULL_USER_OVERRIDE", "Calibrated override of chi and both map numbers (override mask 0x80 and 0x40 set)"),
    (13, "SINGLE_USER_OVERRIDE", "Calibrated override with one whole chi that sets both map numbers (mask 0x80 set and 0x40 clear)"),
    (14, "STATUS_FLAG_FIXED_VALUE", "Fixed chi and level selected when a combustion status flag 0x08 / 0x10 / 0x200 is set"))]
save("enums.csv", en)

# ---------- global_variables.csv ----------
gv = load("global_variables.csv")
idx = {}
for n, line in enumerate(gv):
    p = line.split(",", 3)
    if p[0].startswith("0x"):
        idx.setdefault((int(p[0], 16), p[1]), n)


def row(addr, name):
    assert (addr, name) in idx, (hex(addr), name)
    return idx[(addr, name)]


def retype(addr, name, new_type, allowed):
    n = row(addr, name)
    p = gv[n].split(",", 3)
    while len(p) < 4:
        p.append("")
    assert p[2] in allowed, (hex(addr), name, p[2])
    p[2] = new_type
    gv[n] = ",".join(p)


# the arbitration struct: the flat source-code word + the 6-byte struct
for a, old, new in ((0x40a2f6, "torque_limit_arb_t_0040a2f6",
                     "0x0040a2f6,main_injection_timing_source_code,word,Winning source code of the main injection timing "
                     "(5 / 7 / 8 / 11 / 18-24 / 29-31) written by cm848_calculateMainInjectionTiming and "
                     "cm848_updateMainInjectionTimingByDeliveryMode - not part of the engine speed limit arbitration (was "
                     "torque_limit_arb_t.source_priority)"),
                    (0x40a2f8, "torque_limit_arb_t_0040a2f6.limiting_source_number",
                     "0x0040a2f8,engine_speed_limit_arbitration,engine_speed_limit_arbitration_t,"),
                    (0x40a2fa, "torque_limit_arb_t_0040a2f6.applied_speed_limit",
                     "0x0040a2fa,engine_speed_limit_arbitration.applied_speed_limit,,"),
                    (0x40a2fc, "torque_limit_arb_t_0040a2f6.lowest_source_speed_limit",
                     "0x0040a2fc,engine_speed_limit_arbitration.lowest_source_speed_limit,,")):
    gv[row(a, old)] = new
n = row(0x40af5a, "governor_pid_t_0040af5a")
gv[n] = "0x0040af5a,operating_mode_governor_output,operating_mode_governor_output_t," + gv[n].split(",", 3)[3]
n = row(0x40af5c, "governor_pid_t_0040af5a.integral_term")
gv[n] = "0x0040af5c,operating_mode_governor_output.mode_code,," + gv[n].split(",", 3)[3]
# dword splits and retypes (each proven by the load / store instructions in the agents' notes)
retype(0x40a306, "engine_speed_limit_droop_slope", "i16", ("dword",))
retype(0x40a308, "engine_speed_limit_ramped", "word", ("",))
EGR = [(0x3fa73e, "egr_valve_driver_over_current_clear_timer", "word"), (0x3fa740, "egr_valve_driver_over_current_fault_counter", "word"),
       (0x3fa7bc, "egr_valve_h_bridge_fault_reset_flag", "word"), (0x3fa7ca, "egr_valve_h_bridge_fault_retry_active_flag", "word"),
       (0x3fa7d0, "egr_valve_h_bridge_fault_counter_decrement_enabled_flag", "word"),
       (0x3fa172, "egr_assist_controller_unstaged_output", "word"), (0x40a652, "egr_delta_pressure_autozero_enable_flag", "word"),
       (0x40a662, "egr_delta_pressure_state", "word"), (0x40a70a, "egr_valve_autozero_enable_flag", "word"),
       (0x40a716, "egr_valve_ready_for_autozero_flag", "word"), (0x4067f2, "egr_valve_derivative_filter_coefficient", "word"),
       (0x40a666, "egr_valve_position_autozeroed", "i16"),
       (0x40a6ca, "egr_valve_control_state", "EGR_VALVE_CONTROL_STATE"),
       (0x3fa78e, "egr_valve_control_state_previous", "EGR_VALVE_CONTROL_STATE"),
       (0x3fa716, "egr_delta_pressure_autozero_offset_filter_state", "ema_filter_state_t"),
       (0x3fa750, "egr_valve_delta_pressure_filter_state", "ema_filter_state_t"),
       (0x3fa790, "egr_valve_derivative_filter_state", "ema_filter_state_t")]
for a, name, t in EGR:
    retype(a, name, t, ("word", "dword", "byte", "pointer", ""))
# the governor's signed words (every load lha) and the three condensation words (signed in the computation)
signed = [0x40a226, 0x40a20a, 0x40a20c, 0x40a210, 0x40a212, 0x40a214, 0x40a228, 0x40a22c, 0x40a22e, 0x40a230,
          *range(0x40a232, 0x40a244, 2), 0x40a25a, 0x40a25c, 0x40a5c2, 0x40a5d8, 0x40a5e8]
by_addr = {}
for (a, name), n in idx.items():
    by_addr.setdefault(a, []).append(name)
for a in signed:
    names = [x for x in by_addr.get(a, []) if x and "+" not in x and "." not in x]
    assert len(names) == 1, (hex(a), names)
    retype(a, names[0], "i16", ("word", ""))
retype(0x40b000, "engine_operating_mode", "ENGINE_OPERATING_MODE", ("word",))
retype(0x40a4a4, "combustion_chi_source_code", "COMBUSTION_CHI_SOURCE", ("word",))
retype(0x40a4e4, "combustion_base_chi_source_code", "COMBUSTION_CHI_SOURCE", ("word",))
# new_type fields of the results (type-only retypes)
for gname in ("torque_limit", "egr_charge", "governor_combustion"):
    for line in open(os.path.join(rdir, f"aligned_W8_{gname}.jsonl")):
        r = json.loads(line) if line.strip() else {}
        if r.get("new_type"):
            name = r.get("new") or r.get("old")
            if (int(r["address"], 16), name) in idx:
                retype(int(r["address"], 16), name, r["new_type"], ("word", "dword", "byte", "pointer", "", r["new_type"]))
                print("new_type", r["address"], name, r["new_type"])
# '+N' label rows inside the split dwords, and the accumulator half of the 0x3fa790 filter state
drop = {(0x40a664, "sensor_channel105_fault_combined+2"), (0x3fa794, "j1939_handler_param_table_index"),
        (0x3fa174, "throttle_fuel_rate_b+2"), (0x3fa7cc, "cold_start_enable_flag_b+2"), (0x3fa7be, "cold_start_valid_flag+2"),
        (0x3fa7d2, "cold_start_timing_active_flag+2"), (0x40a8a9, "governor_fuel_demand_interp_state_y+2")}
for key in drop:
    row(*key)
gv = [l for n, l in enumerate(gv) if not (l.startswith("0x") and (int(l.split(",")[0], 16), l.split(",")[1]) in drop)]
save("global_variables.csv", gv)

# ---------- prototypes and locals ----------
fd = load("function_definitions.csv")
tail = fd.pop() if fd and fd[-1] == "" else None
for a, fn, note in ((0x10110, "cm848_initEngineOperatingMode", "the tuning set is reloaded when it is not 7"),
                    (0x503074, "cm848_engineMode_reset", "the tuning set is reloaded when it is not 2"),
                    (0x50daac, "cm848_transitionEngineOperatingMode", "the pedal fault snapshot is saved when it is not 6")):
    assert not any(l.startswith(f"0x{a:08x},") for l in fd), fn
    fd += [f"0x{a:08x},{fn},return,,void,", f"0x{a:08x},{fn},0,previous_engine_operating_mode,ENGINE_OPERATING_MODE,"
           f"Mode of the previous pass; {note}"]
assert not any(l.startswith("0x00014508,") for l in fd)
fd += ["0x00014508,cm848_selectChiSourceCode,return,,COMBUSTION_CHI_SOURCE,1 when the air density chi is not smaller than "
       "the coolant temperature chi - else 3",
       "0x00014508,cm848_selectChiSourceCode,0,air_density_chi_hundredths,int32_t,",
       "0x00014508,cm848_selectChiSourceCode,1,coolant_temperature_chi_hundredths,int32_t,"]
if tail is not None:
    fd.append(tail)
save("function_definitions.csv", fd)
lv = load("local_variables.csv")
tail = lv.pop() if lv and lv[-1] == "" else None
lv += ["0x00042918,cm848_resetEngineOperatingMode,iVar1,previous_engine_operating_mode,ENGINE_OPERATING_MODE,Mode read "
       "before it is cleared; passed to the three selectors that compare the previous mode",
       "0x000160ac,cm848_selectChiAndAlpha,local_1a,chi_source_code,COMBUSTION_CHI_SOURCE,Chi source code of this pass",
       "0x00015f34,cm848_determineBaseChi,local_1a,chi_source_code,COMBUSTION_CHI_SOURCE,Base chi source code (1 or 3)",
       "0x00015f34,cm848_determineBaseChi,sVar1,selected_chi_source_code,COMBUSTION_CHI_SOURCE,Return value of "
       "cm848_selectChiSourceCode (compared with 1 and 3)"]
if tail is not None:
    lv.append(tail)
save("local_variables.csv", lv)

# the six new rows inside the split dwords, for apply_extras stage 2
STAGE_B_NEW = {0x3fa174, 0x3fa7be, 0x3fa7cc, 0x3fa7d2, 0x40a664, 0x40a8a9}
rows = []
for gname in ("torque_limit", "egr_charge", "governor_combustion"):
    for line in open(os.path.join(rdir, f"aligned_W8_{gname}.jsonl")):
        r = json.loads(line) if line.strip() else {}
        if r.get("kind") == "new_global" and int(r["address"], 16) in STAGE_B_NEW:
            rows.append(r)
assert len(rows) == 6, len(rows)
open(os.path.join(rdir, "aligned_W8_stage_b_new.jsonl"), "w").write("".join(json.dumps(r) + "\n" for r in rows))
print(f"stage B: structs 2, enums 3, retypes {len(EGR) + len(signed) + 5}, deleted rows {len(drop)}, prototypes 4, locals 4, "
      f"new rows queued {len(rows)}")
