"""Round 8 docs: task 046, firmware/CLAUDE.md, todo 046, the PR body, the session README.
usage: docs_r8.py <repo> <pr_body.md>"""
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


R8_TASK = """## Done, round 8 (2026-11-21, same PR; the user's next "keep going"): the 48RE transmission controller

The round 7 lead (0x3241c / 0x3257c) opened the whole 48RE controller, which was named `protection_*`. Scripts are in
`session_folder/round8/`.
- **Method:** the Chrysler e2m `RE_*` records, aligned by relative offset. None of the RE blocks are in the parameter
  ID table, but their bases are proved word by word:
  - **8C53 +0** `RE_Trans_Pressure_State` resolves to 0x40b100 in the table.
  - **8C17 (RAM) at 0x40b102**, aligned +0..+48 (it drifts from +4C). The anti-hunt timers start it.
    `RE_OSS_Accel` (+28) lands on the existing output shaft acceleration, and seven names that were already right
    match (`RE_Governor_Set` = `governor_pressure_target`, `Transmission_OD_Lamp` = `overdrive_off_flag`, ...).
  - **8BBC (ROM cals) at 0x40780c**, aligned +0..+5C (it drifts from +5E). The anti-hunt timer limits and the
    inertia limits start it, and +10 `RE_Inertia_Default` = 53 is the learned inertia in the RAM dump.
    `align_block.py` prints a block against the rows with each row's users.
- **Stage A (e848623, label-only): the anti-hunt mode and its post-shift acceleration model.**
  - `cm848_selectGovernorPressureAntiHunt` uses the hold curve (prevent the upshift) and the boost curve (force it),
    once the predicted post-shift acceleration clears `RE_PSA_Max_*`.
  - `cm848_predictPostShiftAcceleration`, `cm848_calculateTransmissionOutputTorqueInGear` (the turbine torque
    estimate x the gear ratio) and `cm848_learnVehicleInertia`.
  - `transmission_pressure_state_t` (the pressure state, then the anti-hunt timers), the gear ratio table and 25
    tables.
- **Stage B (1766051, label-only): the rest of both aligned ranges.**
  - The low range, lockup / unlock service, WOT boost / hold / anti-hang and cruise decel cals.
  - The 8C17 working words, including the predicted shift delays (were `governor_pressure_learned_gain_gear1` / `2`)
    and `transmission_overheat_protection_active_flag` (was `hot_mode_flag`).
  - `transmission_lockup_timers_t` (was `protection_lockout_t`).
  - `cm848_selectGovernorPressureLowRange` (was `cm848_protectionOverloadHandler`), the timer tick, the
    initialization, the output shaft acceleration and the governor pressure sensor offset calibration.
- **Stage C (types):** the gear ratio table as `word[6]`, `transmission_vehicle_inertia_default`, and
  `cm848_initializeTransmissionShiftLogic`.
- **Thin evidence:**
  - `transmission_output_speed_fault_debounce_timer` (8C17 +8): only the timer tick and the initialization use it.
  - The turbine torque tables have other sizes than in the 11.45 e2m (17 / 9 / 17 x 9 here, 8 / 8 / 5 x 5 there).
  - The gear ratio table's indexes 0 / 1 (10 / 512) are unexplained.
- **Round 8 leads:**
  - The pressure state codes 1-0x18: an enum needs every mode handler's curves. Named so far: 1 base, 0x12 / 0x13
    anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 high gear, 0x11 2nd gear locked,
    0x16 manual low, 0x17 override.
  - The still `protection_*`-named 48RE functions and tables:
    - `cm848_protectionStateTransitionCheck`: the 3-4 / 4-3 shift lines and manual low (e2m `RE_Normal_3_4` /
      `4_3`, `RE_Cruise_*`);
    - `cm848_calculateProtectionThresholdLimit`;
    - `cm848_protectionCleanupHandler` (the 3rd gear lockup);
    - the `protection_condition_flags_t` / `protection_status_flags_t` bits;
    - the remaining tables (`RE_Cold_Curve`, `RE_Cruise_Curve`, `RE_Fuel_Economy_Curve`, `RE_WOT_*_Curve`,
      `RE_Lockup_*`, `RE_Unlock_*`).
  - Blocks 8BB5 / 8BBB / 8BBD / 8C18 / 8C19 (more RE cals and flags), to align the same way.

"""
edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"),
     [("## Leads (not in this PR)\n", R8_TASK + "## Leads (not in this PR)\n")])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("  - **The importer:** the two session functions' `session_kind` needed `int32_t` (see the \"Prototype / local type\n"
     "    keywords\" rule above).\n",
     "  - **The importer:** the two session functions' `session_kind` needed `int32_t` (see the \"Prototype / local type\n"
     "    keywords\" rule above).\n"
     "- **Round 8 (2026-11-21, PR #53): the 48RE transmission controller was named `protection_*`.**\n"
     "  - **The vocabulary:** the Chrysler e2m `RE_*` records. None of the RE blocks are in the parameter ID table, so\n"
     "    align them by relative offset and prove the base by the code use of several words (`round8/align_block.py`).\n"
     "  - **The alignments:**\n"
     "    - 8C53 +0 `RE_Trans_Pressure_State` = 0x40b100 (`transmission_pressure_state`);\n"
     "    - 8C17 (RAM) at 0x40b102, +0..+48;\n"
     "    - 8BBC (ROM cals) at 0x40780c, +0..+5C.\n"
     "  - **The modes:** the governor pressure modes are `cm848_selectGovernorPressure*`, now with `AntiHunt` (hold /\n"
     "    boost curves gated by a predicted post-shift acceleration from a learned vehicle inertia) and `LowRange`.\n")])
edit(os.path.join(repo, "work", "todo.md"), [
    ("the engine retarder TSC1 words, the drivetrain ratio module and gear-down range - open: the transmission gear "
     "functions 0x3241c / 0x3257c, the engine speed module's functions,",
     "the engine retarder TSC1 words, the drivetrain ratio module and gear-down range; round 8: the 48RE "
     "transmission controller from the e2m RE_ blocks (anti-hunt, post-shift acceleration and inertia, low range, "
     "lockup, WOT, cruise decel) - open: the rest of the 48RE controller (the pressure state enum, the 3-4 / 4-3 shift "
     "lines, lockup), the engine speed module's functions,")])
R8_PR = """**Round 8 (another "keep going"): the 48RE transmission controller, named `protection_*` until now.**
- **The method:** the Chrysler e2m `RE_*` records, aligned by relative offset and proved word by word by code use.
  - 8C53 resolves through the parameter ID table to `transmission_pressure_state`.
  - 8C17 (RAM, 0x40b102) aligns +0..+48. Its `RE_OSS_Accel` and seven names that were already right confirm it.
  - 8BBC (ROM cals, 0x40780c) aligns +0..+5C. Its `RE_Inertia_Default` = 53 equals the learned inertia in the RAM
    dump.
- **Stage A (e848623, label-only): the anti-hunt mode.**
  - `cm848_selectGovernorPressureAntiHunt` holds the governor pressure on a hold curve, which prevents the upshift,
    then forces it with a boost curve once the predicted post-shift acceleration clears the minimum for the throttle.
  - The prediction: the road load from a turbine torque estimate x the gear ratio, the next gear's torque, ÷ a
    vehicle inertia learned across each forced 1-2 shift.
- **Stage B (1766051, label-only):** the rest of both blocks.
  - the low range strategy (`cm848_selectGovernorPressureLowRange`, was `cm848_protectionOverloadHandler`);
  - the lockup / unlock, WOT and cruise decel cals;
  - the predicted shift delays (were `governor_pressure_learned_gain_gear1` / `2`);
  - `hot_mode_flag` = `transmission_overheat_protection_active_flag`;
  - `transmission_lockup_timers_t`;
  - the timer tick, the initialization and the governor pressure sensor offset calibration.
- **Stage C:** the gear ratio table is typed `word[6]`, and the inertia default and the shift logic initializer are
  named.

"""
edit(pr, [("## Test plan\n", R8_PR + "## Test plan\n"),
          ("- [x] `./analyze.sh verify`: the two builds are byte-identical.",
           "- [x] Round 8:\n"
           "  - stages A and B are EQUIVALENT (0 functions differ);\n"
           "  - stage C was read diff by diff;\n"
           "  - each aligned e2m record was checked against its row's users (`align_block.py`), and each block stops\n"
           "    where it drifts.\n"
           "- [x] `./analyze.sh verify`: the two builds are byte-identical."),
          ("  - the transmission gear functions 0x3241c / 0x3257c (inherited `protection_*` names);\n",
           "  - the rest of the 48RE controller (the pressure state enum, the 3-4 / 4-3 shift lines, lockup, more RE blocks);\n")])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read().rstrip("\n") + "\n\n" + """## Round 8: the 48RE transmission controller (`session_folder/round8/`)

Hand work on the round 7 lead.
- **Finding the vocabulary:**
  - `e2m_of_names.py` looks up the e2m record of each named row by address.
  - `align_block.py` prints an e2m block against the CSV rows at an assumed base, with each row's RAM value and users.
    It is the tool that proved the 8C17 and 8BBC bases.
- **Stage A, label-only:** `worklist_r8a.py` and `apply_r8a_struct.py` (`transmission_pressure_state_t`).
- **Stage B, label-only:** `worklist_r8b.py` and `apply_r8b_struct.py` (`transmission_lockup_timers_t`; generated by
  `make_r8b_struct.py`).
- **Stage C, the types:** `worklist_r8c.py` and `apply_r8c_types.py`.
- **References:** `refresh_struct_comments.py` refreshes the comment columns of `structure_definitions.csv` /
  `enums.csv`, which `refresh_references.py` skips.
- **Commit messages:** `commit_r8*.txt`.
"""
open(p, "w").write(s)
print("README ok")
