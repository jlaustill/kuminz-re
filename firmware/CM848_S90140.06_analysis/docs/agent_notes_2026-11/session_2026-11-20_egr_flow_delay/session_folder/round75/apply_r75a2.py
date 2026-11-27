"""Round 75 stage A2 (CM550): ROM 0x612ee has no memory block (the map ends with the 256 KB dump), so the
insite_parameter_schedule_entry_t[30] type cannot apply there (the importer counted it as '1 failed'); the row becomes
label-only and keeps the layout in its comment. Idempotent. usage: apply_r75a2.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
old = "0x000612ee,insite_parameter_schedule_table,insite_parameter_schedule_entry_t[30],The InSite parameter schedule: up to 30 3-byte records"
new = ("0x000612ee,insite_parameter_schedule_table,,The InSite parameter schedule: up to 30 3-byte "
       "insite_parameter_schedule_entry_t records")
if new not in s:
    assert s.count(old) == 1
    s = s.replace(old, new)
    s = s.replace("so the contents are unknown (PR #53 round 75)",
                  "so the contents are unknown and the row is label-only: the address has no memory block, so the "
                  "importer cannot apply insite_parameter_schedule_entry_t[30] there (PR #53 round 75)")
    open(p, "w", newline="").write(s)
print("round 75 stage A2 applied")
