"""Round 8 stage G docs: task 046, firmware/CLAUDE.md, work/todo.md, the PR body, the session README.
usage: docs_r8g.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:70], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


STAGE_G = """- **Stage G (label-only, after a second review):**
  - **Word order:** the exhaust brake inhibit words take the word order of their records. `RE_E_Brake_Inhibit_LU`
    means the exhaust brake is inhibited (so the converter can lock). Stage F's `exhaust_brake_lockup_inhibit_*` read
    as a lockup inhibited by the exhaust brake, and the same function also sets a real lockup inhibit (`condition_eval`
    bit 6). The new names:
    - `cm848_updateExhaustBrakeInhibitForLockup`;
    - `exhaust_brake_inhibit_timer` / `_timeout` / `_previous`;
    - `transmission_exhaust_brake_flags`, the byte's record `RE_Trans_EBrake` ('Contains engine brake flags').
  - **Bit 2** of that byte is `RE_Ebrake_Inhibit_Timeout_Flag` ('E-Brake inhibit timeout flag'): the code sets it
    exactly when the inhibit timer runs out.
  - **8C19 at 0x40b0e8** is checked by code use at +0..+3, +9 (the low range boosts), +A (`status_flags`: the WOT
    anti-hang and boost flags), +C (`flags[0]`: the anti-hunt boosts, the detent) and +16.
  - **Switch 12** is the exhaust brake switch, proved by code: `cm848_driveEngineRetarderOutput` sets
    `engine_retarder_switch_percent_2` to 100 while it is on.
  - **The polarity of `converter_clutch_closed_throttle_lockup_enable`:** 1 here skips the block that unlocks the
    converter on the brake (switch 11) or switch 2, so its name has the right sense. The comment now says so.
  - **The csv-module audit:** `csv_tail_check2.py` and the scripts that wrote these files found no other damage than
    the three quoted rows, the 0x40b0fe tail and the lost stage C edit.
"""
T046 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(T046, [
    ("    corrects it: the e2m names it the exhaust brake lockup aid (`cm848_updateExhaustBrakeLockupInhibit`).",
     "    corrects it: the e2m names it the exhaust brake lockup aid (now `cm848_updateExhaustBrakeInhibitForLockup`)."),
    ("    brake waits for converter lock: `cm848_updateExhaustBrakeLockupInhibit`, `exhaust_brake_lockup_flags`,\n"
     "    `exhaust_brake_lockup_inhibit_timer` / `_timeout`, `exhaust_brake_lockup_speed_ratio_*`. 8C17 drifts from +4C,\n",
     "    brake waits for converter lock: `cm848_updateExhaustBrakeLockupInhibit`, `exhaust_brake_lockup_flags`,\n"
     "    `exhaust_brake_lockup_inhibit_timer` / `_timeout`, `exhaust_brake_lockup_speed_ratio_*` (stage G reorders the\n"
     "    inhibit names). 8C17 drifts from +4C,\n"),
    ("    and 0x408372 `RE_Cruise_Unlock_Inhibit`.\n- **Thin evidence:**\n",
     "    and 0x408372 `RE_Cruise_Unlock_Inhibit`.\n" + STAGE_G + "- **Thin evidence:**\n"),
])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("    - 8C19 (the RE flag bytes) at 0x40b0e8, the `protection_condition_flags_t` struct (bits not named yet).\n",
     "    - 8C19 (the RE flag bytes) at 0x40b0e8, the `protection_condition_flags_t` struct, checked at +0..+3, +9, +A,\n"
     "      +C and +16 (bits not named yet).\n"),
    ("The ECM's CCVS1 broadcast reports **15 as the clutch switch and 11 as the brake switch**.",
     "The ECM's CCVS1 broadcast reports **15 as the clutch switch and 11 as the brake switch**. **12** = the exhaust brake "
     "switch (`cm848_driveEngineRetarderOutput` sets `engine_retarder_switch_percent_2` to 100 while it is on, and the "
     "48RE logic uses its exhaust brake shift lines; PR #53 round 8)."),
])
edit(os.path.join(repo, "work", "todo.md"), [
    ("round 8: the 48RE transmission controller from the e2m RE_ blocks (anti-hunt, post-shift acceleration and inertia, "
     "low range, lockup, WOT, cruise decel) - open: the rest of the 48RE controller (the pressure state enum, the 3-4 / "
     "4-3 shift lines, lockup), ",
     "round 8: the 48RE transmission controller from the e2m RE_ blocks 8BBC / 8C17 / 8C18 / 8C53 (anti-hunt, "
     "post-shift acceleration and inertia, low range, lockup boost, WOT, cruise decel, the exhaust brake lockup aid) - "
     "open: the rest of the 48RE controller (the pressure state enum, the 8C19 flag bits, the 3-4 / 4-3 shift lines, "
     "blocks 8BB5 / 8BBB / 8BBD), "),
])
edit(pr, [
    ("- **Stage F (label-only, after a review): e2m 8C18",
     "- **Stage F (0b685f3, label-only, after a review): e2m 8C18"),
    ("    the exhaust brake off until the converter locks: `cm848_updateExhaustBrakeLockupInhibit`,\n"
     "    `exhaust_brake_lockup_*`.\n",
     "    the exhaust brake off until the converter locks: now `cm848_updateExhaustBrakeInhibitForLockup`,\n"
     "    `exhaust_brake_inhibit_*` and `transmission_exhaust_brake_flags` (stage G).\n"),
    ("    comments that an earlier script had quoted (that file takes commas unquoted).\n",
     "    comments that an earlier script had quoted (that file takes commas unquoted).\n"
     "- **Stage G (label-only, after a second review):**\n"
     "  - The exhaust brake inhibit names follow their records' word order (`RE_E_Brake_Inhibit_LU`: the exhaust\n"
     "    brake is inhibited): `cm848_updateExhaustBrakeInhibitForLockup`, `exhaust_brake_inhibit_*` and\n"
     "    `transmission_exhaust_brake_flags` (`RE_Trans_EBrake`).\n"
     "  - The flag byte's bit 2 is `RE_Ebrake_Inhibit_Timeout_Flag`.\n"
     "  - Switch 12 is proved to be the exhaust brake switch (it drives `engine_retarder_switch_percent_2`).\n"
     "  - 8C19 is checked at +0..+3, +9, +A, +C and +16.\n"),
    ("  - stages A, B, E and F are EQUIVALENT: no function differs, except two in stage F, each of which declares one local\n"
     "    in another place;\n",
     "  - stages A, B, E, F and G are EQUIVALENT: no function differs, except two in stage F, each of which declares one\n"
     "    local in another place;\n"),
])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read()
a = "- **Stage F, label-only:** "
i = s.index(a)
j = s.index("\n", i) + 1
s = s[:j] + ("- **Stage G, label-only:** `worklist_r8g.py` and `apply_r8g_fix.py` (the exhaust brake inhibit word order, "
             "the 0x408388 polarity comment). `csv_tail_check.py` / `csv_tail_check2.py` look for the silent forms of the "
             "csv-module bug (left-over comment tails) between two revisions.\n") + s[j:]
open(p, "w").write(s)
print("README ok")
