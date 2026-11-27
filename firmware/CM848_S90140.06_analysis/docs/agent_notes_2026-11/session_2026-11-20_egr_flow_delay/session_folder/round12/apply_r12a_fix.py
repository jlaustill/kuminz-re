"""Round 12 stage A, fix after the first build: the 16 words at 0x3fd0ca are eight 2-word (2-D grid) lookup caches,
one per fuel pressure setpoint table, not one 16-word cache (word[16] rendered `x + 8` where the code had the distinct
&DAT_003fd0da). So 0x3fd0ca becomes word[2] (the four setpoint maps share it) and the other seven caches get their
own word[2] rows, named after their tables (cm848_calculateFuelPressureSetpoint's cm848_dualAxisTableInterpolation
calls). Also corrects stage 11A's comment ('passes its first word to each map lookup'). String edits only.
usage: apply_r12a_fix.py <repo>  (updates arrays_r12a.json: [name, base, size, count, old base label])"""
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
here = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(p).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("0x003fd0ca,"))
a, n, t, c = lines[i].split(",", 3)
assert n == "fuel_pressure_setpoint_map_cached_axis_offsets" and t == "word[16]", (n, t)
c = ("The 2-D lookup cache (x and y segment offsets) the four fuel pressure setpoint maps share "
     "(fuel_pressure_setpoint_map_1..4: cm848_calculateFuelPressureSetpoint calls cm848_dualAxisTableInterpolation with "
     "it 8 times). It is the first of eight 2-word caches at 0x3fd0ca-0x3fd0e9, one per setpoint table, all set to 2 by "
     "the initializer. Typed word[2] (round 12; stage 11A's 'first word to each map lookup' was wrong: the other "
     "tables have their own caches)")
lines[i] = ",".join([a, n, "word[2]", c])
NEW = [  # address, table base
    ("0x003fd0ce", "fuel_pressure_setpoint_cold_start"),
    ("0x003fd0d2", "fuel_pressure_setpoint_ambient_factor"),
    ("0x003fd0d6", "fuel_pressure_setpoint_ambient_limit"),
    ("0x003fd0da", "fuel_pressure_setpoint_base_map"),
    ("0x003fd0de", "fuel_pressure_setpoint_coolant_limit"),
    ("0x003fd0e2", "fuel_pressure_setpoint_coolant_factor"),
    ("0x003fd0e6", "fuel_pressure_setpoint_offset"),
]
for addr, base in NEW:
    assert not any(l.startswith(addr + ",") for l in lines), addr
    name = base + "_cached_axis_offsets"
    comment = (f"The 2-D lookup cache (x and y segment offsets) of the {base} table: cm848_calculateFuelPressureSetpoint "
               "passes it to cm848_dualAxisTableInterpolation; set to 2 by the initializer (one of the eight 2-word "
               "caches at 0x3fd0ca-0x3fd0e9)")
    k = next(j for j, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > int(addr, 16))
    lines.insert(k, ",".join([addr, name, "word[2]", comment]))
open(p, "w").write("\n".join(lines))
spec_path = os.path.join(here, "arrays_r12a.json")
spec = json.load(open(spec_path))
spec = [s + [s[0]] if len(s) == 4 else s for s in spec]
for s in spec:
    if s[0] == "fuel_pressure_setpoint_map_cached_axis_offsets":
        s[3] = 2
for addr, base in NEW:
    spec.append([base + "_cached_axis_offsets", int(addr, 16), 2, 2, f"DAT_{int(addr, 16):08x}"])
json.dump(spec, open(spec_path, "w"), indent=1)
print("0x3fd0ca -> word[2]; 7 cache rows added")
