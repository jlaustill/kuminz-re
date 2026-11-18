"""Consistency pass: patch name_tables.py for mixed shared x axes, write tables/rewrite.json."""
import json
import os
import sys

d = sys.argv[1]
p = os.path.join(d, "name_tables.py")
t = open(p).read()
old = ('    if len(roles) != 1:\n        problems.append(f"{a}: inconsistent roles {roles}")\n        continue\n'
       '    role = roles.pop()')
new = ('    if len(roles) > 1 and {r for _, r in roles} == {"x_axis"}:\n'
       '        roles = {("1-D", "x_axis")}            # an x axis shared by 1-D and 2-D lookups: plain _axis\n'
       '    if len(roles) != 1:\n        problems.append(f"{a}: inconsistent roles {roles}")\n        continue\n'
       '    role = roles.pop()')
if new not in t:
    assert t.count(old) == 1, "anchor"
    t = t.replace(old, new)
    open(p, "w").write(t)
rewrite = {"lookups": {
    # bin 01: the same structure as the main injection timing family (bin 05) - the same words
    "L179": "injection_timing_offset_coolant_factor",
    "L184": "injection_timing_offset_coolant_angle",
    "L180": "injection_timing_offset_intake_temperature_factor",
    "L181": "injection_timing_offset_barometric_pressure_factor",
    "L186": "injection_timing_offset_barometric_pressure_angle",
    "L187": "injection_timing_offset_boost_angle",
    "L188": "injection_timing_offset_boost_factor",
    "L182": "injection_timing_offset_start_run_up",
    # bin 04: the same coolant / ambient pairs as the auxiliary families (bins 02 / 03)
    "L131": "fuel_pressure_setpoint_coolant_factor",
    "L133": "fuel_pressure_setpoint_coolant_limit",
    "L134": "fuel_pressure_setpoint_ambient_factor",
    "L135": "fuel_pressure_setpoint_ambient_limit",
    "L136": "fuel_pressure_setpoint_start_run_up",
    # bin 00: base_map like every other blended family
    "L144": "pilot_quantity_base_map",
    # bin 12: sensor channels are numbered by channel_index (the output slot), like bins 15 - 18
    "L118": "sensor_channel15_linearization_feature_bit_4_off",
    "L119": "sensor_channel15_linearization_feature_bit_4_on",
    # bin 13: aux spelled out
    "L197": "fuel_demand_auxiliary_blend_deviation_maximum_by_rpm",
    "L198": "fuel_demand_auxiliary_blend_deviation_minimum_by_rpm"}}
json.dump(rewrite, open(os.path.join(d, "tables", "rewrite.json"), "w"), indent=1)
print("rewrites", len(rewrite["lookups"]))
