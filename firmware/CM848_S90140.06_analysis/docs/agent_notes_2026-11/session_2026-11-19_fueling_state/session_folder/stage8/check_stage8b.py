"""Stage 8b check: the functions whose text changed must be exactly the predicted ones (the three gain consumers, whose
first parameter is now a struct pointer, and cm848_calculateFuelMeteringCommand, the only function that touches the
seven records). Also: no function appears or disappears, every instance name renders, no `_<instance>` variant, and no
retired name is left in the code.
usage: check_stage8b.py <pre .cpp> <new .cpp>"""
import re
import sys

old_path, new_path = sys.argv[1:3]
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
PREDICTED = {"cm848_applyPiecewiseLinearGain", "cm848_integrateWithZoneGain", "cm848_calculateFilteredDerivative",
             "cm848_calculateFuelMeteringCommand"}
INSTANCES = ["fuel_pressure_governor_proportional_gains", "fuel_pressure_governor_integral_gains",
             "fuel_pressure_governor_derivative_gains", "fuel_metering_current_compensation_proportional_gains",
             "fuel_metering_current_compensation_integral_gains",
             "fuel_metering_uncompensated_duty_cycle_proportional_gains",
             "fuel_metering_current_compensation_derivative_gains"]
RETIRED = ["fuel_pressure_governor_proportional_gain_small_signal", "engine_sync_prot_scale_a_cal",
           "fuel_pressure_governor_integral_gain_small_signal", "engine_sync_prot_scale_b_cal", "engine_sync_prot_gain_cal",
           "fuel_pressure_governor_derivative_gain_small_signal", "injection_timing_scale_cyl4_lo_cal",
           "injection_timing_scale_cyl5_lo_cal", "injection_timing_scale_cyl6_lo_cal", "engine_sync_prot_limit_cal",
           "engine_sync_prot_gain_b_cal", "cam_sync_speed_error_prot_state_cal", "cam_sync_speed_error_prot_mode_cal",
           "cam_sync_ref_prot_state_cal", "cam_sync_ref_prot_handler_state_cal"]


def split(path):
    parts = HEADER.split(open(path, errors="replace").read())
    return {parts[i]: parts[i + 2] for i in range(1, len(parts), 3)}


old, new = split(old_path), split(new_path)
changed = {name for name in old if name in new and old[name] != new[name]}
print(f"functions: {len(old)} before, {len(new)} after; added {sorted(set(new) - set(old))}, removed"
      f" {sorted(set(old) - set(new))}")
print(f"changed: {sorted(changed)}")
print("changed == predicted:", changed == PREDICTED, "| unexpected:", sorted(changed - PREDICTED), "| missing:",
      sorted(PREDICTED - changed))
text = open(new_path, errors="replace").read()
for name in INSTANCES:
    print(f"  {name}: {len(re.findall(r'(?<![A-Za-z0-9_])' + name + r'(?![A-Za-z0-9_])', text))} uses,"
          f" {len(re.findall(r'(?<![A-Za-z0-9_])_' + name + r'(?![A-Za-z0-9_])', text))} underscore variants")
left = {n: len(re.findall(r"(?<![A-Za-z0-9])_?" + n + r"(?![A-Za-z0-9_])", text)) for n in RETIRED}
print("retired names left in the code:", {n: c for n, c in left.items() if c})
