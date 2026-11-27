"""Round 29 stage A (label-only): fault_<n> bitfields of fault_bit_words_t named from the code that sets them (or the
sensor channel that owns them). Rewrites the field name and prefixes the evidence to its comment. Appends field rows
to the map. Idempotent.  usage: fault_bits_r29a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
BITS = {
    57: ("fuel_pressure_governed_speed_check_error",
         "cm848_checkFuelPressureGovernorDemandAtGovernedSpeed sets it when fuel_pressure_governed_speed_check_debounce_count "
         "reaches its limit"),
    58: ("fuel_pressure_governor_demand_above_limit_error",
         "cm848_checkFuelPressureWithoutInjection sets it when fuel_pressure_governor_demand_above_limit_debounce_count "
         "reaches its limit"),
    59: ("fuel_pressure_decay_below_model_error",
         "cm848_checkFuelPressureWithoutInjection sets it when fuel_pressure_allowed_decay_below_model_debounce_count "
         "reaches its limit"),
    60: ("fuel_metering_feedback_low_error",
         "cm848_monitorFuelMeteringFeedbackAgainstGovernorDemand sets it when fuel_metering_feedback_low_debounce_count "
         "reaches its limit"),
    308: ("engine_off_time_stuck_error",
          "cm848_latchAndCheckEngineOffTime sets it when the engine-off time in PCI frame 0x42 stays within "
          "engine_off_time_unchanged_delta of the last value for engine_off_time_unchanged_count_limit key cycles "
          "(e2m Chry_Dat42 = Chrysler data frame 0x42); the temperature rationality checks skip while it is set"),
    342: ("overspeed_protection_error",
          "cm848_checkRpmOverspeedProtection sets it above overspeed_protection_threshold (and clears logical outputs "
          "0x2f / 0x30 until overspeed_protection_recovery_threshold)"),
    343: ("overspeed_warning_error",
          "cm848_checkRpmOverspeedProtection sets it above overspeed_warning_threshold (until "
          "overspeed_warning_recovery_threshold)"),
    682: ("variable_geometry_turbocharger_position_sensor_high_error",
          "sensor channel 101's high fault bit (cm848_processVariableGeometryTurbochargerPositionChannel passes 0x2aa)"),
    683: ("variable_geometry_turbocharger_position_sensor_low_error",
          "sensor channel 101's low fault bit (0x2ab)"),
}
lines = open(p).read().split("\n")
done, rows = 0, []
for i, line in enumerate(lines):
    m = re.match(r"^(fault_bit_words_t,0x003fe974,)fault_(\d+)(,bitfield:1@\d+,[02],)(.*)$", line)
    if not m or int(m.group(2)) not in BITS:
        continue
    f = int(m.group(2))
    name, why = BITS[f]
    rest = m.group(4)
    comment, tail = rest.rsplit(",,verified", 1)[0], ",,verified"
    assert "," not in why
    lines[i] = f"{m.group(1)}{name}{m.group(3)}{why} (was fault_{f}; PR #53 round 29) | {comment}{tail}"
    rows.append(f"0x003fe974,{name},fault_{f},field")
    done += 1
assert done == len(BITS) or done == 0, done
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as fh:
    for r in rows:
        fh.write(r + "\n")
print(f"{done} fault bits named")
