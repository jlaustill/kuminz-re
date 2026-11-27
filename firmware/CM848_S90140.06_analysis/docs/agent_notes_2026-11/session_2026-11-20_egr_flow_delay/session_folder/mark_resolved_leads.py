"""Mark the leads that round 2 resolved: a follow-up under task 042's W9 charge_turbo left-over line, and the stage 1
filter name in task 046 (renamed again in stage 3).
Usage: mark_resolved_leads.py <repo>"""
import os
import sys

repo = sys.argv[1]
path = os.path.join(repo, "work/tasks/042-table-campaign-rename-leads.md")
lines = open(path).read().split("\n")
idx = [i for i, l in enumerate(lines)
       if l.startswith("- [W9 charge_turbo] OTHER LEFT-OVERS") and "boost_pressure_current_raw 0x40a7d0" in l]
assert len(idx) == 1, idx
note = ("  - 2026-11-20 (task 046): `boost_pressure_current_raw` (0x40a7d0) is e2m 1A5D +0 Exhaust_Press, now "
        "`exhaust_pressure` (written by `cm848_calculateExhaustPressure`, was `phase_group_a_validateEngineSync`).")
assert lines[idx[0] + 1] != note
lines.insert(idx[0] + 1, note)
open(path, "w").write("\n".join(lines))

path = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
text = open(path).read()
old = "`egr_oxygen_fraction_filter` (was `throttle_filter_state`;"
new = "`egr_oxygen_fraction_filter` (was `throttle_filter_state`; `egr_oxygen_fraction_filter_state` since stage 3;"
assert text.count(old) == 1
open(path, "w").write(text.replace(old, new))
print("ok")
