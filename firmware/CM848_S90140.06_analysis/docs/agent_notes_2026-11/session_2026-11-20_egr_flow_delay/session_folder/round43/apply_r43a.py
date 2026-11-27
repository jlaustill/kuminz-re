"""Round 43 stage A: cm848_computeFuelRpmCompensatedOffset computes the main injection's end of injection timing.
main_injection_timing_copy - (main_injection_pulse_width + addend) x average_engine_speed x 6 / 1e6 x 256 / 600:
on-times are 0.4 us per count and the speed is 1/8 rpm, so the subtrahend is the pulse's crank angle in main timing
counts (0.1171875 deg). Renames the function, its output and its four calibrations (round 39's fuel_rpm_compensated_*
names); the three signed calibrations (lha loads) become i16. The output keeps word: its other reader,
cm848_updateOilChangeMonitor, loads it with lhz (the lookup reads it through a signed axis). Idempotent.
usage: apply_r43a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 43"
FUNC = "cm848_calculateMainInjectionEndTiming"
ROWS = [  # address, name now, new name, new type or None, comment head
    ("0x0040b28a", "fuel_rpm_compensated_offset", "main_injection_end_timing", None,
     f"The main injection's end of injection timing in main timing counts (0.1171875 deg): {FUNC} subtracts the "
     "pulse's crank angle from main_injection_timing_copy. cm848_updateOilChangeMonitor reads it (lhz) as the input of "
     "engine_power_accumulator_increment (signed axis)"),
    ("0x00408800", "fuel_rpm_compensated_offset_default", "main_injection_end_timing_default", "i16",
     f"{FUNC}: main_injection_end_timing while main_injection_pulse_width or average_engine_speed is 0 (lha)"),
    ("0x00408802", "fuel_rpm_compensated_offset_pulse_width_addend", "main_injection_end_timing_pulse_width_addend", None,
     f"{FUNC} adds it to main_injection_pulse_width (0.4 us counts) before the crank angle conversion (lhz)"),
    ("0x00408804", "fuel_rpm_compensated_offset_upper_limit", "main_injection_end_timing_upper_limit", "i16",
     f"{FUNC}: the signed upper clamp of main_injection_end_timing (lha)"),
    ("0x00408806", "fuel_rpm_compensated_offset_lower_limit", "main_injection_end_timing_lower_limit", "i16",
     f"{FUNC}: the signed lower clamp of main_injection_end_timing (lha)"),
]
PLATE = (f"Calculates main_injection_end_timing, the end of the main injection in main timing counts (0.1171875 deg): "
         "main_injection_timing_copy (the start) minus the pulse's crank angle (main_injection_pulse_width + "
         "main_injection_end_timing_pulse_width_addend) x average_engine_speed x 6 / 1e6 x 256 / 600. With the on-time at "
         "0.4 us per count and the speed at 1/8 rpm that product is the pulse duration in the same counts. Clamped to "
         "main_injection_end_timing_lower_limit .. _upper_limit (signed); main_injection_end_timing_default while the "
         "pulse width or the engine speed is 0. The engine speed x 6 product is truncated to 16 bits (clrlwi), so it "
         "wraps above raw 10922 (about 1365 rpm). cm848_updateOilChangeMonitor reads the result as its "
         "engine_power_accumulator_increment input. (was cm848_computeFuelRpmCompensatedOffset, and before that "
         "cm848_computeCruiseSpeedSetpoint: its limits are -171..512 in the RAM dump, not a speed)")
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "main_injection_end_timing" in names:
    print("already applied")
    sys.exit(0)
rows = ["address,name,old_label,kind,dims"]
for a, cur, new, typ, head in ROWS:
    assert new not in names, new
    i = next(k for k, l in enumerate(g) if l.startswith(a + "," + cur + ","))
    p = g[i].split(",", 3)
    g[i] = f"{a},{new},{typ or p[2]},{head} (was {cur}; {R}) | earlier note: {p[3] if len(p) > 3 else ''}"
    rows.append(f"{a},{new},{cur},global,1")
open(gp, "w").write("\n".join(g))
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read().split("\n")
i = next(k for k, l in enumerate(f) if l.startswith("0x0003866c,cm848_computeFuelRpmCompensatedOffset"))
f[i] = f"0x0003866c,{FUNC},{PLATE} ({R})"
open(fp, "w").write("\n".join(f))
rows.append(f"0x0003866c,{FUNC},cm848_computeFuelRpmCompensatedOffset,function,1")
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(ROWS)} rows and the function renamed")
