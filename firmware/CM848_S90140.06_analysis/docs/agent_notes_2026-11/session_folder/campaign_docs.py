"""Todo 041 item (1) done, todo 042 added, the 'Every table' bullet updated."""
import sys

root = sys.argv[1]
p = f"{root}/work/todo.md"
t = open(p).read()
old = ("(1) name the 564 unnamed lookup tables (they render WORD_ARRAY_<address>; each row's comment gives role / size / "
       "readers - a naming campaign, and the protection_fuel_limit_* tables read by the converter lockup and governor "
       "pressure code still carry wrong-domain names)")
new = ("(1) DONE (PR #50, 2026-11-16): 519 of the 564 unnamed lookup tables named by a 20-agent campaign (pilot of 4 with a "
       "two-agent agreement check, then 16; every name traced from its input, output and breakpoints; 45 left unnamed "
       "for lack of evidence) - rename leads for the code around them in task 042; still open: the protection_fuel_limit_* "
       "tables read by the converter lockup and governor pressure code carry wrong-domain names")
assert t.count(old) == 1, "todo 041 anchor"
t = t.replace(old, new)
line041 = next(l for l in t.split("\n") if l.startswith("041 "))
entry = ("042 [ ] [firmware] CM848D rename leads from the table-naming campaign: ~20 misnamed functions (e.g. "
         "cm848_auxiliary_boundary_condition_eval = auxiliary injection timing, cm848_torque_limit_state_update = pilot "
         "injection quantity, cm848_sensor_channel_state_load = rail pressure setpoint, cm848_boostCompensatedRpmGovernor = "
         "wastegate duty) and their variables, two duplicate global names - leads to verify, see tasks/042-table-campaign-rename-leads.md")
assert "\n042 " not in t
t = t.replace(line041, line041 + "\n" + entry)
open(p, "w").write(t)

p = f"{root}/firmware/CLAUDE.md"
t = open(p).read()
old = "920 tables (918 in `global_variables.csv`, 2 in `arrays.csv`; 564 unnamed)"
new = "920 tables (918 in `global_variables.csv`, 2 in `arrays.csv`; 564 were unnamed before the 2026-11-16 campaign, 45 now)"
assert t.count(old) == 1, "CLAUDE.md anchor"
open(p, "w").write(t.replace(old, new))
print("ok")
