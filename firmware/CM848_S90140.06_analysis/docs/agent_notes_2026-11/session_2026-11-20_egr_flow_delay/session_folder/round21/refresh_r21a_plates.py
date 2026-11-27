"""Round 21 stage A: refresh the three function plates that named the removed flat rows (the struct fields replace
them). usage: refresh_r21a_plates.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
t = open(p).read()
FIXES = [
    ("it sets fuel_temperature_derate_precrank_error_flag for the channel",
     "it sets the channel's state precrank_error (fuel_temperature_engine_protection_state.precrank_error)"),
    ("the two shutdown time counts (fuel_temperature_derate_fuel_shutdown_time_count / _rpm_)",
     "the two shutdown time counts (fuel_temperature_engine_protection_state.fueling_shutdown_time_count / "
     "engine_speed_shutdown_time_count)"),
    ("the fuel temperature channel fuel_temperature_derate_input_pointer",
     "the fuel temperature channel, fuel_temperature_engine_protection_state"),
]
for old, new in FIXES:
    assert t.count(old) == 1, old
    t = t.replace(old, new)
open(p, "w").write(t)
print(len(FIXES), "plates refreshed")
