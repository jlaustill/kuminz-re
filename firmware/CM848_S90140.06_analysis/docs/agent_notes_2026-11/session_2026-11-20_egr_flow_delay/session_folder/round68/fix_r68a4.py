"""Round 68 stage A, fourth pass: undo fix_r68a3.py. Idempotent.
Typed byte *, cm848_lookupEepromParameterAddress's local split in two (value_address for the 0x3fee38 path and a
struct-typed piVar2 for the rest, with a cast on every path): Ghidra types any pointer it builds from 0x3fee1c - now
intake_air_heater_saved_values_cal's address - as that struct's pointer. Without the local row there is one variable:
the prototype keeps the byte * return (its caller lost its cast), and the plate explains the local's type.
usage: fix_r68a4.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
p = os.path.join(O, "local_variables.csv")
lines = open(p).read().split("\n")
keep = [l for l in lines if not l.startswith("0x00002d08,cm848_lookupEepromParameterAddress,piVar2,")]
if len(keep) != len(lines):
    open(p, "w").write("\n".join(keep))
p = os.path.join(O, "function_renames.csv")
s = open(p).read()
old = "oil_change_monitor_fuel_hundredth_gallons_cal) / others return 0 (PR #53 round 68)"
new = ("oil_change_monitor_fuel_hundredth_gallons_cal) / others return 0. Its local shows as "
       "intake_air_heater_saved_values_t * because one path returns that struct's address; typing it byte * split it "
       "in two (PR #53 round 68)")
if new not in s:
    assert s.count(old) == 1
    open(p, "w").write(s.replace(old, new))
print("fourth pass applied")
