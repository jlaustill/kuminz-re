import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W5_combustion')
from peek import *
items = [
 ('engine_feature_enable_flags', 0x3fd5a6), ('engine_feature_enable_flags_cal', 0x3fd5ec), ('fuel_feature_control_flags', 0x3fd5f2),
 ('fuel_mode_status_flags', 0x40a5ee), ('fuel_blend_coefficient', 0x40a168), ('fuel_demand_min_threshold', 0x40a5b4),
 ('fuel_demand_offset_correction', 0x40b22a), ('engine_load_input_value', 0x40a604), ('fuel_demand_boost_input', 0x40a61c),
 ('fuel_demand_boost_offset', 0x40a460), ('fuel_demand_timing_input', 0x40a608), ('boost_fuel_mode_active', 0x40a668),
 ('fuel_demand_arbitrated_snapshot', 0x40a2e0), ('fuel_demand_mode_code', 0x40a2f2), ('fuel_demand_mode_flags', 0x40a2f4),
 ('engine_rpm current_rpm 0x40b7ac', 0x40b7ac), ('sensor_channel9_pressure_value', 0x40bd86), ('fuel_demand_offset_load_delta_correction', 0x40a550),
 ('0x40a502..0x40a516 (max chi fuel at points / torque at points):', 0),
]
for n, a in items:
    if a == 0:
        print(n)
        for x in range(0x40a502, 0x40a518, 2):
            print('  ', hex(x), w(x), w(x, True))
        continue
    print(f"{n:45s} {hex(a)} hex={hex(w(a))} u={w(a)} s={w(a,True)}")
print('CBO block 0x40a518-0x40a54e')
for x in range(0x40a518, 0x40a550, 2):
    print('  ', hex(x), w(x), w(x, True), end=' |')
print()
