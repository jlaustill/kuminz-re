"""Round 24 stage B: the live todo line's rename refresh and task 042's resolved lead. usage: apply_r24b_docs.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, t.count(old))
    open(p, "w").write(t.replace(old, new))


edit("work/todo.md", "and cm848_fuelDemandFinalCalculation takes fuel demand from it;",
     "and cm848_selectCommandedThrottle (was cm848_fuelDemandFinalCalculation) takes the commanded throttle from it;")
edit("work/tasks/042-table-campaign-rename-leads.md",
     "- `governor_torque_output` (0x40bb00) = the remote accelerator pedal position (bin 16).",
     "- `governor_torque_output` (0x40bb00) = the remote accelerator pedal position (bin 16). Done in PR #53 round 24: "
     "`remote_accelerator_pedal_sensor_filtered` (EEC2 byte 4, SPN 974).")
print("docs refreshed")
