"""Round 8 closing: mark task 046's round 7 lead resolved, write append_resolved_r8.py from the round 7 script, point
two memory notes at the new names.
usage: close_r8.py <repo> <memory dir>"""
import os
import sys

repo, mem = os.path.abspath(sys.argv[1]), sys.argv[2]
here = os.path.dirname(os.path.abspath(__file__))


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:60], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"), [
    ("- **Round 7 leads:**\n"
     "  - The transmission gear functions `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and\n"
     "    `cm848_processProtectionStateFlags` (0x3257c): `transmission_current_gear` / output speed logic under inherited\n"
     "    `protection_*` names (e2m 8D14 drifts).\n",
     "- **Round 7 leads** (the first is resolved in round 8, below):\n"
     "  - The transmission gear functions `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and\n"
     "    `cm848_processProtectionStateFlags` (0x3257c): `transmission_current_gear` / output speed logic under inherited\n"
     "    `protection_*` names (e2m 8D14 drifts). (Round 8: they are `cm848_learnVehicleInertia` and\n"
     "    `cm848_selectGovernorPressureAntiHunt` of the 48RE controller; the e2m vocabulary is the `RE_*` blocks.)\n"),
])
src = open(os.path.join(here, "..", "r7", "append_resolved_r7.py")).read()
a = '"## Resolved by PR #53 round 7 (2026-11-21)"'
assert src.count(a) == 1 and src.count('"## Resolved by PR #53 round 7" in text') == 1
src = src.replace(a, '"## Resolved by PR #53 round 8 (2026-11-21)"')
src = src.replace('"## Resolved by PR #53 round 7" in text', '"## Resolved by PR #53 round 8" in text')
src = src.replace("what PR #53 round 7 renamed it to", "what PR #53 round 8 renamed it to")
src = src.replace("still cites round 4's old names", "still cites round 8's old names")
open(os.path.join(here, "append_resolved_r8.py"), "w").write(src)
print("append_resolved_r8.py written")
edit(os.path.join(mem, "cm848_trans_temp_light.md"), [
    ("`hot_mode_flag` 235 / 220 °F",
     "`transmission_overheat_protection_active_flag` (was `hot_mode_flag`; e2m RE_Ovr_Heat_Prot_On) 235 / 220 °F"),
])
edit(os.path.join(mem, "cm848_0040_naming_campaign.md"), [
    ("reset to 2 by mpc555_initProtectionFilterVariables/clearTimingDataAndFilters",
     "reset to 2 by cm848_initializeTransmissionShiftLogic (was mpc555_initProtectionFilterVariables)/clearTimingDataAndFilters"),
])
