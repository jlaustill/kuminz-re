"""Round 39 stage A: the 24 ROM-side lookup tables named _cal (the EEPROM-only rule: tables are never EEPROM data)
renamed after their own lookups with the table grammar (<base>_axis / _values, <base>_x_axis / _y_axis / _grid),
and their caches. Several were wrong-domain (the "injection timing temperature correction" map is the turbocharger
corrected speed map; the "J1939 fuel table" is e2m MT_Max_Torque_Map). Checks names (banned words, collisions) and
the cache second words. Writes the proof map (address,name,old_label,kind,dims). Idempotent.
usage: apply_r39a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))  # the gate's set literal
WHY = {
    "low_speed_governor_no_load_fuel": "cm848_calculateLowSpeedGovernorNoLoadFuel: the no-load fuel by "
                                       "commanded_throttle_state.commanded_throttle",
    "turbocharger_corrected_speed": "cm848_estimateTurbochargerSpeed: turbocharger_speed_estimate_corrected_speed by the "
                                    "compressor pressure ratio (charge_pressure x 4096 / compressor_inlet_pressure; x) "
                                    "and the filtered engine speed (y); the speed estimate scales it by the square root "
                                    "of the compressor inlet temperature",
    "safety_fuel_limit": "cm848_applyFuelPressureGovernorFaultBlend: safety_fuel_limit_lookup by the filtered engine speed",
    "cylinder_balance_enable": "hpcr_cbdCalculateCylinderTrims: by engine speed (x) and cylinder_balance_filtered_fueling "
                               "(y); 0 resets cylinder_event_seq_counter and below 0x80 sets "
                               "cylinder_balance_stop_compensation_flag",
    "crank_tooth_good_window_fraction": "cm848_updateEngineSpeedFromCrankSignal: crank_tooth_good_window_fraction by "
                                        "average_engine_speed",
    "cylinder_event_index_a": "engine_injectionTiming_crankSyncDispatch: cylinder_event_index by the low byte of TPU-A "
                              "channel 0 PARAM4 (table a)",
    "cylinder_event_index_b": "engine_injectionTiming_crankSyncDispatch: cylinder_event_index by the low byte of TPU-A "
                              "channel 0 PARAM4 (table b)",
    "crank_preliminary_sync_count": "hpcr_processEngineSyncPulses: crank_preliminary_sync_count (a step lookup at the "
                                    "constant 2)",
    "fuel_metering_pwm_frequency": "cm848_setFuelMeteringPwm / mpc555_initTpuTimingInterrupts by average_engine_speed: "
                                   "TPU-B channel 11's period is 5000000 / value ticks (16 x the frequency in Hz at the "
                                   "3.2 us TPU-B tick)",
    "engine_retarder_torque_engine_speed": "the filtered engine speed axis the engine retarder torque stage tables share "
                                           "(cm848_calculateEngineRetarderTorque / cm848_selectEngineRetarderStagePercent)",
    "maximum_torque_map": "e2m MT_Max_Torque_Map (engine speed x MT_RPM_Axis / alpha y MT_Alpha_Axis; "
                          "cm848_lookupMaximumTorqueAtEngineSpeed / cm848_calculateFuelDemandFilter)",
}
TABLES = [  # (address, old, new)
    ("0x0040713a", "governor_fuel_demand_axis_cal", "low_speed_governor_no_load_fuel_axis"),
    ("0x0040714c", "governor_fuel_demand_output_cal", "low_speed_governor_no_load_fuel_values"),
    ("0x004072a2", "injection_timing_temp_corr_axis1_cal", "turbocharger_corrected_speed_x_axis"),
    ("0x004072e8", "injection_timing_temp_corr_ystart_cal", "turbocharger_corrected_speed_y_axis"),
    ("0x00407308", "injection_timing_temp_corr_yend_cal", "turbocharger_corrected_speed_grid"),
    ("0x004088e8", "safety_fuel_limit_rpm_axis_cal", "safety_fuel_limit_axis"),
    ("0x0040891a", "safety_fuel_limit_rpm_output_cal", "safety_fuel_limit_values"),
    ("0x00408f32", "cylinder_seq_axis1_cal", "cylinder_balance_enable_x_axis"),
    ("0x00408f38", "cylinder_seq_ystart_cal", "cylinder_balance_enable_y_axis"),
    ("0x00408f3e", "cylinder_seq_yend_cal", "cylinder_balance_enable_grid"),
    ("0x00408fae", "crank_mios_timing_axis_cal", "crank_tooth_good_window_fraction_axis"),
    ("0x00408fba", "crank_mios_timing_values_cal", "crank_tooth_good_window_fraction_values"),
    ("0x00408fe0", "cylinder_event_axis_b_cal", "cylinder_event_index_b_axis"),
    ("0x00408ff6", "cylinder_event_values_b_cal", "cylinder_event_index_b_values"),
    ("0x0040900c", "cylinder_event_axis_a_cal", "cylinder_event_index_a_axis"),
    ("0x00409030", "cylinder_event_values_a_cal", "cylinder_event_index_a_values"),
    ("0x00409054", "engine_event_countdown_axis_cal", "crank_preliminary_sync_count_axis"),
    ("0x00409062", "engine_event_countdown_values_cal", "crank_preliminary_sync_count_values"),
    ("0x00409554", "engine_sync_speed_correction_axis_cal", "fuel_metering_pwm_frequency_axis"),
    ("0x00409576", "engine_sync_speed_correction_values_cal", "fuel_metering_pwm_frequency_values"),
    ("0x0005a426", "governor_load_xaxis_cal", "engine_retarder_torque_engine_speed_axis"),
    ("0x0005c556", "j1939_fuel_table_xaxis_cal", "maximum_torque_map_x_axis"),
    ("0x0005c582", "j1939_fuel_table_ystart_cal", "maximum_torque_map_y_axis"),
    ("0x0005c58e", "j1939_fuel_table_yend_cal", "maximum_torque_map_grid"),
]
CACHES = [  # (address, old label (row name or DAT_), new, type, y-half old name or None)
    ("0x003faf7e", "governor_interp_table_state_b", "low_speed_governor_no_load_fuel_cached_axis_offset", "word", None),
    ("0x003fb01a", "DAT_003fb01a", "turbocharger_corrected_speed_cached_axis_offsets", "word[2]", None),
    ("0x003fb3c2", "DAT_003fb3c2", "safety_fuel_limit_cached_axis_offset", "word", None),
    ("0x003fb592", "cylinder_event_init_state_a", "cylinder_balance_enable_cached_axis_offsets", "word[2]",
     "cylinder_event_init_state_b"),
    ("0x003fb5bf", "crank_timing_init_state_a", "cylinder_event_index_a_cached_axis_offset", "word", None),
    ("0x003fb5c1", "crank_timing_init_state_b", "cylinder_event_index_b_cached_axis_offset", "word", None),
    ("0x003fb5c3", "crank_timing_init_state_c", "crank_preliminary_sync_count_cached_axis_offset", "word", None),
    ("0x003fb6ea", "cam_timing_filter_init_state", "fuel_metering_pwm_frequency_cached_axis_offset", "word", None),
    ("0x003faf98", "fuel_demand_interp_state_a", "maximum_torque_map_alpha_0_cached_axis_offsets", "word[2]",
     "fuel_demand_interp_state_b"),
    ("0x003faf9c", "fuel_demand_interp_state_c", "maximum_torque_map_chi_lower_cached_axis_offsets", "word[2]",
     "fuel_demand_interp_state_d"),
    ("0x003fafa0", "fuel_demand_interp_state_e", "maximum_torque_map_chi_upper_cached_axis_offsets", "word[2]",
     "fuel_demand_interp_state_f"),
]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
new_names = [t[2] for t in TABLES] + [c[2] for c in CACHES]
if all(n in names for n in new_names):
    print("already applied")
    sys.exit(0)
for n in new_names:
    assert not any(t in BANNED for t in n.split("_")), n
    assert n not in names, f"name taken: {n}"


def base_of(n):
    return re.sub(r"_(x_axis|y_axis|axis|values|grid|cached_axis_offsets?|alpha_0_cached_axis_offsets|"
                  r"chi_lower_cached_axis_offsets|chi_upper_cached_axis_offsets)$", "", n)


def why(n):
    b = base_of(n)
    for k, v in WHY.items():
        if b.startswith(k):
            return v
    return ""


rows = ["address,name,old_label,kind,dims"]
for a, old, new in TABLES:
    i = next(k for k, l in enumerate(g) if l.startswith(a + "," + old + ","))
    p = g[i].split(",", 3)
    g[i] = f"{a},{new},{p[2]},{why(new)} (was {old}: no _cal - ROM-side; PR #53 round 39) | earlier note: {p[3] if len(p) > 3 else ''}"
    rows.append(f"{a},{new},{old},global,1")
for a, old, new, typ, yhalf in CACHES:
    ai = int(a, 16)
    line_y = None
    if yhalf:
        line_y = next(k for k, l in enumerate(g) if l.startswith(f"0x{ai + 2:08x},{yhalf},"))
    if old.startswith("DAT_"):
        assert not any(l.startswith(a + ",") for l in g), a
        if typ == "word[2]":
            assert not any(l.startswith(f"0x{ai + 2:08x},") or l.startswith(f"0x{ai + 1:08x},") or
                           l.startswith(f"0x{ai + 3:08x},") for l in g), a
        j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < ai)
        g.insert(j + 1, f"{a},{new},{typ},the lookup cache of {why(new)} (PR #53 round 39)")
    else:
        i = next(k for k, l in enumerate(g) if l.startswith(a + "," + old + ","))
        p = g[i].split(",", 3)
        g[i] = (f"{a},{new},{typ},the lookup cache of {why(new)} (was {old}; PR #53 round 39) | earlier note: "
                f"{p[3] if len(p) > 3 else ''}")
    widened = typ == "word[2]" and not old.startswith("DAT_")
    rows.append(f"{a},{new},{old},global,{2 if (typ == 'word[2]') else 1}")
    if yhalf:
        line_y = next(k for k, l in enumerate(g) if l.startswith(f"0x{ai + 2:08x},{yhalf},"))
        q = g[line_y].split(",", 3)
        g[line_y] = f"{q[0]},{new}[1],,the y segment offset of {new} (was {yhalf}; PR #53 round 39) | earlier note: {q[3] if len(q) > 3 else ''}"
        rows.append(f"0x{ai + 2:08x},{new}[1],{yhalf},global,1")
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(TABLES)} tables and {len(CACHES)} caches renamed; {len(rows) - 1} map rows")
