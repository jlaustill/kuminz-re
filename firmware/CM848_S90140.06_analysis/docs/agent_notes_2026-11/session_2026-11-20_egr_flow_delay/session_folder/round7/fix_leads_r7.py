"""Round 7 closing: mark task 046's round 6 leads resolved, point the memory note at the new name.
usage: fix_leads_r7.py <repo> <memory dir>"""
import os
import sys

repo, mem = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:60], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"), [
    ("- **Round 6 leads:**\n"
     "  - The J1939 monitor's session record: e2m 10FE J1939_Active_Engine (0x3feb4e), 10FF J1939_Active_Retarder and 1100\n",
     "- **Round 6 leads** (the first three are resolved in round 7, below):\n"
     "  - The J1939 monitor's session record: e2m 10FE J1939_Active_Engine (0x3feb4e), 10FF J1939_Active_Retarder and 1100\n"),
    ("  - `retarder_tsc1_mode_transition_timer` and `retarder_tsc1_speed_mode_flag` kept their old roles under a retarder\n"
     "    prefix; the retarder handler was only skimmed.\n",
     "  - `retarder_tsc1_mode_transition_timer` and `retarder_tsc1_speed_mode_flag` kept their old roles under a retarder\n"
     "    prefix; the retarder handler was only skimmed. (Round 7 read it in full: they became\n"
     "    `retarder_tsc1_zero_torque_request_timer` and `retarder_tsc1_speed_control_flag`.)\n"),
])
edit(os.path.join(mem, "cm848_cruise_drivetrain_type_fork.md"), [
    ("fuelTempTrimUpperLimitCheck, etcTransmissionModeControl,",
     "fuelTempTrimUpperLimitCheck, cm848_applyJ1939OutOfGearToDrivetrainRatio (was etcTransmissionModeControl),"),
])
