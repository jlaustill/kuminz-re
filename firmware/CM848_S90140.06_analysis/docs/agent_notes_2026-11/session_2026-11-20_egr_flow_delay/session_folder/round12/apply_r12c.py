"""Round 12 stage C (label-only), after the review: the rest of cm848_calculateFuelMeteringCommand (stage B's scan
printed only the first 420 of its 757 lines), the plate, and stale text.
- Renames: the three derivative gain scaling caches and the current integrator preset cache (empty-name word rows
  rendered WORD_003fb652 / 654 / 656 / 660), the current integrator preset table (e2m 8B49 / 8B4A
  HPCR_Current_Integrator_Preset_Temp_Axis / _Axis, ROM: no _cal) and the raw coil resistance sample.
- The plate: the second early return is the service tool's fuel control test (fuel_control_actuator_test_active_flag,
  DRB 13-5E), not 'a cranking value'.
- Stale text: enums.csv 870 (engine_sync_state_a), function_definitions.csv row 14 (the cache name patterns),
  work/todo.md (the 045 line's open start-mode tables, the 046 line's output 54), task 046's resolved leads.
String edits only (global_variables / function_renames are split(",", 4 / 3); enums / function_definitions
quote-aware, the edited comments have no commas). usage: apply_r12c.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")


def edit(path, old, new, count=1):
    text = open(path).read()
    assert text.count(old) == count, (path, old[:60], text.count(old))
    open(path, "w").write(text.replace(old, new))


gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
maps = []
EMPTY = {  # address: (name, comment)
    "0x003fb652": ("fuel_pressure_governor_derivative_small_signal_gain_scaling_cached_axis_offset",
                   "Lookup cache of the fuel_pressure_governor_derivative_small_signal_gain_scaling table "
                   "(cm848_calculateFuelMeteringCommand)"),
    "0x003fb654": ("fuel_pressure_governor_derivative_positive_large_signal_gain_scaling_cached_axis_offset",
                   "Lookup cache of the fuel_pressure_governor_derivative_positive_large_signal_gain_scaling table"),
    "0x003fb656": ("fuel_pressure_governor_derivative_negative_large_signal_gain_scaling_cached_axis_offset",
                   "Lookup cache of the fuel_pressure_governor_derivative_negative_large_signal_gain_scaling table"),
    "0x003fb660": ("fuel_metering_current_integrator_preset_cached_axis_offset",
                   "Lookup cache of the fuel_metering_current_integrator_preset table (the current loop integrator "
                   "preset by the coil temperature)"),
}
RENAME = {  # address: (old, new, comment)
    "0x0040948a": ("engine_sync_speed_scale_axis_cal", "fuel_metering_current_integrator_preset_temperature_axis",
                   "e2m 8B49 HPCR_Current_Integrator_Preset_Temp_Axis 'Temperature Axis for scheduling MPROP current "
                   "integrator preset': looked up by fuel_metering_coil_temperature"),
    "0x00409496": ("engine_sync_speed_scale_values_cal", "fuel_metering_current_integrator_preset_values",
                   "e2m 8B4A HPCR_Current_Integrator_Preset_Axis: the preset of fuel_metering_feedback_trim_integrator "
                   "when fuel_metering_inner_loop_coil_temperature_ready_flag is set and "
                   "fuel_metering_inner_loop_preset_temperature_source is 5 (the coil temperature)"),
    "0x003fb6c7": ("engine_sync_rpm_raw_working", "fuel_metering_coil_resistance_raw",
                   "The unfiltered coil resistance sample: fuel_metering_command_filtered x battery voltage x 5 / "
                   "(current x 2), filtered by fuel_metering_coil_resistance_filter into "
                   "fuel_metering_coil_resistance_filtered"),
}
for i, l in enumerate(lines):
    a = l[:10]
    if a in EMPTY:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        assert name == "" and typ == "word", (a, name, typ)
        new, role = EMPTY[a]
        lines[i] = ",".join([addr, new, typ, f"{role} | earlier note: {comment}"])
        maps.append(f"{a},{new},WORD_{a[2:]},global")
    elif a in RENAME:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        old, new, role = RENAME[a]
        if name != old:
            continue
        lines[i] = ",".join([addr, new, typ, f"{role} (was {old})" + (f" | earlier note: {comment}" if comment else "")])
        maps.append(f"{a},{new},{old},global")
assert len(maps) == 7, maps
open(gv, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
edit(os.path.join(out, "function_renames.csv"),
     "(fuel_metering_command_override_enable) and a cranking value return early",
     "(fuel_metering_command_override_enable) and the service tool's fuel control test "
     "(fuel_control_actuator_test_active_flag: fuel_metering_tool_override_command) return early")
edit(os.path.join(out, "enums.csv"),
     "two tables blended by the input engine_sync_state_a picks",
     "two tables blended by the input fuel_metering_outer_loop_preset_temperature_source picks")
edit(os.path.join(out, "function_definitions.csv"),
     "the globals passed here are the *_interp_state / *_interp_index / engine_sync_init_state_* words",
     "the globals passed here are the *_cached_axis_offset words (named after their tables in PR #53 rounds 10-12)")
todo = os.path.join(repo, "work", "todo.md")
edit(todo, "the start-mode tables (engine_sync_init_state_k / _l and engine_sync_state_a's sensor choice)",
     "the start-mode tables (engine_sync_init_state_k / _l and engine_sync_state_a's sensor choice; re-domained in PR "
     "#53 round 12: fuel_metering_start_duty_cycle / _hot_start_duty_cycle, fuel_metering_outer_loop_preset_"
     "temperature_source)")
edit(todo, "output 54 = fuel_shutoff_request", "output 54 = driver_asic_shutoff_request")
t46 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(t46, "    `governor_interp_table_state_b` and `cruise_switch_interp_index`.\n",
     "    `governor_interp_table_state_b` and `cruise_switch_interp_index`. (Round 11 renamed the cruise switch cache;\n"
     "    round 12 re-domained the cam_sync tables and their caches from the e2m HPCR_* records.)\n")
edit(t46, "  - **`fuel_pressure_setpoint_map_cached_axis_offsets`** is a `word` row with a plural name: type it `word[16]`.\n",
     "  - **`fuel_pressure_setpoint_map_cached_axis_offsets`** is a `word` row with a plural name: type it `word[16]`.\n"
     "    (Resolved in round 12: the block is eight 2-word caches, so `word[2]` plus seven new rows.)\n")
edit(t46, "  - The cam_sync tables, the end-of-line test sequencer, 8C80 / 8C2D and the SCI high-speed words stay open from\n"
          "    round 10.\n",
     "  - The end-of-line test sequencer, 8C80 / 8C2D and the SCI high-speed words stay open from round 10 (round 12\n"
     "    resolved the cam_sync tables).\n")
print("7 renames, the plate, enums 870, function_definitions row 14, todo, task 046")
