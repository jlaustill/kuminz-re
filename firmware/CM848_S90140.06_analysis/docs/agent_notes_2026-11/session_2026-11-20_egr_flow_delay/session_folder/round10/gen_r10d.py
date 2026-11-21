"""Round 10 stage D renames (with the enum build): the lettered lookup caches whose tables carry descriptive names
(<table base>_cached_axis_offset; the 2-D lookup's second word _y), and the ten <x>_interp(olation)_state_y y-axis
words of 2-D lookups (-> <x>_cached_axis_offset_y, next to their x word renamed in stage C). The caches of the
cam_sync_*_cal fuel metering tables wait for those tables' own e2m pass. usage: gen_r10d.py <gv csv> <out worklist>"""
import re
import sys

gv_path, out_path = sys.argv[1:3]
rows = {}
for line in open(gv_path):
    m = re.match(r"^(0x[0-9a-f]{8}),([^,]*),", line)
    if m and m.group(2):
        rows[m.group(2)] = m.group(1)
LETTERED = [  # cache, table base, function
    ("engine_sync_init_state_c", "fuel_pressure_governor_proportional_small_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_d", "fuel_pressure_governor_proportional_positive_large_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_e", "fuel_pressure_governor_proportional_negative_large_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_f", "fuel_pressure_governor_integral_small_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_g", "fuel_pressure_governor_integral_positive_large_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_h", "fuel_pressure_governor_integral_negative_large_signal_gain_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_i", "fuel_pressure_governor_derivative_filter_coefficient_scaling", "cm848_calculateFuelMeteringCommand"),
    ("engine_sync_init_state_m", "fuel_pressure_sensor_filter_coefficient_scaling", "cm848_calculateFuelMeteringCommand"),
    ("governor_interp_table_state_a", "governor_speed_limit_by_coolant_temperature", "cm848_updateSpeedLimitFromCoolant"),
    ("governor_interp_table_state_c", "governor_idle_speed_by_barometric_pressure", "cm848_calculateProtectionSpeedLimits"),
    ("governor_interp_table_state_d", "governor_minimum_speed_by_vehicle_speed", "cm848_calculateProtectionSpeedLimits"),
    ("injection_timing_interp_state_b", "injection_timing_demand_floor", "cm848_processEngineConfigSpeedControl"),
]
out = []
for cache, base, func in LETTERED:
    new = base + "_cached_axis_offset"
    assert new not in rows, new
    role = (f"Lookup cache (the last axis segment offset) of the {base} table: {func} passes it to the table lookup")
    out.append((rows[cache], new, role))
# injection_timing_interp_state_a is the second word of the injection_timing_demand_floor 2-D lookup
assert int(rows["injection_timing_interp_state_a"], 16) == int(rows["injection_timing_interp_state_b"], 16) + 2
out.append((rows["injection_timing_interp_state_a"], "injection_timing_demand_floor_cached_axis_offset_y",
            "The y-axis word of the injection_timing_demand_floor 2-D lookup cache (the word after "
            "injection_timing_demand_floor_cached_axis_offset; cm848_dualAxisTableInterpolation keeps the y segment "
            "offset there)"))
for name, addr in sorted(rows.items(), key=lambda r: r[1]):
    m = re.match(r"^(?P<x>[a-z0-9_]+?)_(?:interp_state|interpolation_state)_y$", name)
    if not m:
        continue
    x_name = m.group("x") + "_cached_axis_offset"
    assert rows.get(x_name) == f"0x{int(addr, 16) - 2:08x}", (name, x_name)
    out.append((addr, x_name + "_y",
                f"The y-axis word of the {m.group('x')} 2-D lookup cache (the word after {x_name}; "
                "cm848_dualAxisTableInterpolation keeps the y segment offset there)"))
with open(out_path, "w") as f:
    f.write('"""Round 10 stage D renames (gen_r10d.py)."""\nGLOBALS = [\n')
    for a, n, r in sorted(out):
        f.write(f"    ({a!r}, {n!r},\n     {r!r}),\n")
    f.write("]\nFUNCTIONS = []\n")
print(len(out), "renames")
