"""Round 12 stage A (types): scalar rows whose comment already says they start an N-element block, typed as the
arrays they are (array_candidates.py: no other row inside each range; the DAT_ words inside are their elements).
switch_input_hardware_line_cal ('base of 32 words') is left alone: its range holds the boot kernel's time-shared
words. String edits only (global_variables.csv takes commas unquoted). usage: apply_r12a_arrays.py <repo>
(writes arrays_r12a.json for the proof)"""
import json
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
ARRAYS = [  # address, name, old type, element type, count, why
    ("0x003fb900", "switch_input_debounce_history", "byte", "byte", 16, "4 samples x 4 bytes"),
    ("0x003fd0ca", "fuel_pressure_setpoint_map_cached_axis_offsets", "word", "word", 16, "16 cache words"),
    ("0x003fba38", "fuel_demand_timing_demand_ring_buf", "word", "word", 150, "the 150-element ring"),
    ("0x0040877e", "cold_start_coolant_bucket_thresholds", "word", "word", 5, "5 per-bucket thresholds"),
    ("0x0040ad56", "j1939_receive_source_address_whitelist", "byte", "byte", 4, "the 4 accepted source addresses"),
    ("0x003fce55", "intake_air_heater_level_duration_table", "word", "word", 4, "4 per-level durations"),
    ("0x00409ee2", "fuel_pressure_sensor_plausibility_expected_fuel_demand_table", "word", "word", 5,
     "the byte-length word and 4 values"),
    ("0x0040b9ee", "misfire_monitor_cylinder_attempt_counts", "word", "word", 6, "one per firing-order slot"),
    ("0x003fd1ff", "misfire_monitor_cylinder_misfire_flags", "byte", "byte", 6, "one per firing-order slot"),
]
lines = open(p).read().split("\n")
done = 0
spec = []
for addr, name, old, elem, count, why in ARRAYS:
    i = next(k for k, l in enumerate(lines) if l.startswith(addr + ","))
    a, n, t, c = (lines[i].split(",", 3) + [""])[:4]
    assert n == name and t == old, (addr, n, t)
    lines[i] = ",".join([a, n, f"{elem}[{count}]", c + f" Typed {elem}[{count}] (round 12): {why}."])
    spec.append([name, int(addr, 16), {"byte": 1, "word": 2}[elem], count])
    done += 1
open(p, "w").write("\n".join(lines))
json.dump(spec, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "arrays_r12a.json"), "w"), indent=1)
print(done, "rows typed as arrays")
