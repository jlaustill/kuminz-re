"""Stage 5 fix: the monitor bit was named like the new global charge_pressure_estimate (the proof's global reversal
then rewrote the field, and a reader would face the same ambiguity) -> charge_pressure_estimate_enable; and the name
column of 0x13294's prototype rows (the build warned 'Function name mismatch').
Usage: fix_stage5_collision.py <firmware output dir> <scratch dir>"""
import os
import sys

out, scratch = sys.argv[1:3]


def edit(path, pairs):
    text = open(path).read()
    for old, new, count in pairs:
        assert text.count(old) == count, (path, old, text.count(old))
        text = text.replace(old, new)
    open(path, "w").write(text)


edit(os.path.join(out, "structure_definitions.csv"),
     [("monitor_condition_bits_t,,charge_pressure_estimate,", "monitor_condition_bits_t,,charge_pressure_estimate_enable,", 1)])
edit(os.path.join(out, "function_definitions.csv"),
     [("0x00013294,cm848_calculateBoostTorqueOffset,", "0x00013294,cm848_estimateChargePressure,", 2)])
edit(os.path.join(out, "function_renames.csv"),
     [("the monitor condition bit charge_pressure_estimate is clear or latched",
       "the monitor condition bit charge_pressure_estimate_enable is clear or latched", 1)])
edit(os.path.join(scratch, "map_stage5.csv"),
     [(",charge_pressure_estimate,boost_fuel_weight_factor,field", ",charge_pressure_estimate_enable,boost_fuel_weight_factor,field", 1)])
print("ok")
