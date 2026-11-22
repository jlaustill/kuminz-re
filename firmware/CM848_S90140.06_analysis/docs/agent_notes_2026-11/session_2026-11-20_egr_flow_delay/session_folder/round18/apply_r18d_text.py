"""Round 18 stage D: the enum member 8 (power-up, not 'engine stopped': the dump with the engine stopped reads 20) and
the plates / comments that still used the retired main timing words. Appends the member rename to the map.
usage: apply_r18d_text.py <repo> <map.csv>"""
import csv
import io
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
ep = os.path.join(out, "enums.csv")
lines = open(ep).read().split("\n")
done = 0
for i, line in enumerate(lines):
    if line.startswith("MAIN_INJECTION_TIMING_SOURCE,8,MAIN_INJECTION_TIMING_SOURCE_ENGINE_STOPPED,"):
        row = next(csv.reader([line]))
        row[2] = "MAIN_INJECTION_TIMING_SOURCE_POWER_UP"
        row[3] = ("The power-up value (cm848_initTimingFilterStates), the only store of 8; the e2m 103B value label is 08 "
                  "STOP, but the dump with the engine stopped reads 20 (coolant) (was MAIN_INJECTION_TIMING_SOURCE_INITIAL, "
                  "then _ENGINE_STOPPED)")
        b = io.StringIO()
        csv.writer(b, lineterminator="").writerow(row)
        lines[i] = b.getvalue()
        done += 1
assert done == 1
open(ep, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write(",MAIN_INJECTION_TIMING_SOURCE_POWER_UP,MAIN_INJECTION_TIMING_SOURCE_ENGINE_STOPPED,global\n")
FIX = {
    "function_renames.csv": [
        ("into main_injection_timing: the cold-start rpm x coolant map while engine_state is",
         "into main_injection_timing: the cranking map (engine speed x coolant; e2m label 05 CRANK) while engine_state is"),
        ("injection_timing_main_base_command and a constant, then the floor, governor-limit minimum and working minimum;",
         "injection_timing_main_base_command (the combustion manager's CBL_SOI_Cmd) and a constant, then the limits "
         "injection_timing_main_misfire_limit, injection_timing_main_extended_idle_minimum (extended idle) and "
         "coolant_overheat_derate_minimum_injection_timing (coolant overheat derate);"),
        ("in counts of 0.1171875 degree: the cold-start rpm x coolant map while engine_state is",
         "in counts of 0.1171875 degree: the cranking map (engine speed x coolant) while engine_state is"),
    ],
    "global_variables.csv": [
        ("the governor-limit floor variant while the main timing sits at its governor limit minimum)",
         "the extended idle variant while the main timing sits at injection_timing_main_extended_idle_minimum)"),
    ],
}
for name, pairs in FIX.items():
    p = os.path.join(out, name)
    t = open(p).read()
    for old, new in pairs:
        if old not in t and new in t:
            continue
        assert t.count(old) == 1, (name, old[:50], t.count(old))
        t = t.replace(old, new)
    open(p, "w").write(t)
print("member renamed, 4 texts refreshed")
