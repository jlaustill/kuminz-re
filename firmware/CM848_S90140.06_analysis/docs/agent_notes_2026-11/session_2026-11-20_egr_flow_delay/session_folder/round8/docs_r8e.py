"""Round 8 stage E docs: task 046, firmware/CLAUDE.md, the PR body, the session README.
usage: docs_r8e.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:60], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


STAGE_E = """- **Stage E (label-only, after the closing commit f349dd2):** what the timer tick still counted under
  `protection_*` names.
  - `cm848_monitorConverterClutchEngagement` (was `cm848_processProtectionRateLimitFlags`). After each converter clutch
    command the speed ratio (engine / output speed x 32) must enter the gear's locked window within 3 s
    (`converter_clutch_engagement_time_limit`, 300). The windows are 2nd 43-50, 3rd 28-35 and 4th 19-25, around the
    gear ratios 46 / 32 / 20. If it does not, the lockup inhibit (`condition_eval` bit 6) is set. This proves
    `converter_clutch_transition_state` bits 0 (engagement pending) and 2 (engagement timed out).
  - `cm848_selectGovernorPressureHighGear` (was `cm848_calculateProtectionThresholdLimit`): pressure state 0x10 in
    3rd / 4th below a throttle curve, plus the manual 1 / 2 lever's 4-3 request.
  - The WOT anti-hang timer and the WOT upshift target / command engine speeds (3075 rpm, the target minus engine
    acceleration x the predicted shift delay).
  - The cruise decel downshift / upshift delay timers.
  - The 8C17 record at +4A (`RE_E_Brake_Inhibit_Timer`) does not fit the code there (the engagement timer), so 8C17
    drifts from +4A.
"""
edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"), [
    ("  - **8C17 (RAM) at 0x40b102**, aligned +0..+48 (it drifts from +4C). The anti-hunt timers start it.",
     "  - **8C17 (RAM) at 0x40b102**, aligned +0..+48 (it drifts from +4A, see stage E). The anti-hunt timers start it."),
    ("- **Stage C (types):** the gear ratio table as `word[6]`, `transmission_vehicle_inertia_default`, and\n"
     "  `cm848_initializeTransmissionShiftLogic`.\n",
     "- **Stage C (types):** the gear ratio table as `word[6]`, `transmission_vehicle_inertia_default`, and\n"
     "  `cm848_initializeTransmissionShiftLogic`.\n" + STAGE_E),
    ("    anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 high gear, 0x11 2nd gear locked,\n"
     "    0x16 manual low, 0x17 override.\n",
     "    anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 high gear, 0x11 2nd gear locked,\n"
     "    0x16 manual low, 0x17 override, 7 / 9 WOT 1-2 / 2-3 hold, 8 / 10 WOT 1-2 / 2-3 boost.\n"),
    ("    - `cm848_protectionStateTransitionCheck`: the 3-4 / 4-3 shift lines and manual low (e2m `RE_Normal_3_4` /\n"
     "      `4_3`, `RE_Cruise_*`);\n"
     "    - `cm848_calculateProtectionThresholdLimit`;\n",
     "    - `cm848_protectionStateTransitionCheck` (0x31d98): the 3-4 / 4-3 shift lines, manual low and the cruise decel\n"
     "      requests (e2m `RE_Normal_3_4` / `4_3`, `RE_Cruise_*`). Its gate (`condition_flags_1` bit 4), pressure state\n"
     "      3 and switch 12 are not identified yet. Switch 12 picks the alternate `_c` shift lines, perhaps the exhaust\n"
     "      brake schedule;\n"),
])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("    boost curves gated by a predicted post-shift acceleration from a learned vehicle inertia) and `LowRange`.\n",
     "    boost curves gated by a predicted post-shift acceleration from a learned vehicle inertia), `LowRange` and\n"
     "    `HighGear`.\n"
     "  - **Converter clutch engagement:** `cm848_monitorConverterClutchEngagement` gives each clutch command 3 s to show\n"
     "    lock. The speed ratio (engine / output speed x 32) must enter the gear's window around the gear ratio\n"
     "    (`transmission_<gear>_gear_locked_speed_ratio_minimum` / `_maximum`), or the lockup inhibit is set.\n"),
])
edit(pr, [
    ("- **Stage C:** the gear ratio table is typed `word[6]`, and the inertia default and the shift logic initializer are\n"
     "  named.\n",
     "- **Stage C:** the gear ratio table is typed `word[6]`, and the inertia default and the shift logic initializer are\n"
     "  named.\n"
     "- **Stage E (label-only):**\n"
     "  - the converter clutch engagement monitor (`cm848_monitorConverterClutchEngagement`). After each clutch command\n"
     "    the speed ratio must enter the gear's locked window (2nd 43-50 / 3rd 28-35 / 4th 19-25 around the gear ratios)\n"
     "    within 3 s, or lockup is inhibited;\n"
     "  - the high gear mode (`cm848_selectGovernorPressureHighGear`, pressure state 0x10);\n"
     "  - the WOT anti-hang timer and upshift engine speeds, and the cruise decel delay timers.\n"),
    ("  - stages A and B are EQUIVALENT (0 functions differ);\n",
     "  - stages A, B and E are EQUIVALENT (0 functions differ);\n"),
])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read()
a = "- **Stage C, the types:** `worklist_r8c.py` and `apply_r8c_types.py`.\n"
assert s.count(a) == 1
s = s.replace(a, a + "- **Stage E, label-only:** `worklist_r8e.py` and `apply_r8e_comment.py` (the converter clutch transition "
                     "state comment); `worktree_refresh_audit.py` is `refresh_audit.py` for an uncommitted tree.\n")
open(p, "w").write(s)
print("README ok")
