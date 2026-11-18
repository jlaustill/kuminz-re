import csv
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
g = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        g[r[1]] = r
print("calibration words (hex address, unsigned, signed):")
for a in [0x405d4a, 0x405d4c, 0x405d4e, 0x405d50, 0x405ffc, 0x405ffe, 0x40676e, 0x406768, 0x40676a, 0x406000, 0x406002, 0x406006]:
    print(hex(a), w(a), s(a))
for n in ["boost_target_load_gain", "map_fuel_correction_factor", "boost_target_load_rpm_output", "boost_target_fuel_normalized_ratio",
          "boost_fuel_input_value", "charge_fuel_ratio", "fuel_demand_boost_offset", "fuel_demand_boost_input", "engine_load_input_value",
          "fuel_demand_rpm_limit_output", "fuel_demand_limit_input", "fuel_demand_limit_input_lower_limit", "fuel_demand_limit_input_upper_limit",
          "fuel_quantity_ema_filtered", "fuel_quantity_ema", "fuel_demand_load_axis_cap", "main_injection_timing_for_air_handling"]:
    r = g.get(n)
    if r:
        a = int(r[0], 16)
        print(n, r[0], r[2], "dump:", w(a), s(a))
    else:
        print(n, "NO ROW")
print("boost_correction_block_mode_flag dword 0x40a688:", w(0x40a688), w(0x40a68a))
print("0x40a55c:", w(0x40a55c), "0x40a680:", w(0x40a680))
# the byte words
print("0x40a893 word:", w(0x40a892), w(0x40a894), w(0x40a896), "bytes 893/895:", b(0x40a893), b(0x40a895))
for n in ["fuel_rate_rpm_factor", "fuel_rate_rpm_factor_raw"]:
    r = g.get(n)
    print(n, r[:3], r[3][:300] if len(r) > 3 else "")
