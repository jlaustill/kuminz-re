"""Round 8 stage F docs: task 046, firmware/CLAUDE.md, the PR body, the session README.
usage: docs_r8f.py <repo> <pr_body.md>"""
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


STAGE_F = """- **Stage F (label-only, after the review): e2m 8C18 and the exhaust brake lockup aid.**
  - **8C18 (ROM cals) aligns at 0x4082f4, +00..+98.** From +9A the rows are a table axis. Rows named before from
    their code use confirm it:
    - +0E `RE_ERPM_WOT_Target` = stage E's WOT upshift target;
    - +16 `RE_Lockup_Boost` = the pressure state 0x10 target;
    - +1E `RE_Low_Range_Max`;
    - +20..+24 the gear identification ratios;
    - +26..+54 the overdrive and over temperature light temperatures;
    - +70 `RE_OSS_Accel_Method` = the method switch of `cm848_calculateOutputShaftAcceleration`.
  - **The renames:** 71 globals in all. Among them: the engine acceleration defaults / limits, the WOT shift lag band,
    the lockup and overheat lockup delays, the detent / WOT throttle thresholds, the predicted shift delay limits
    (were `governor_pressure_learned_gain_gear1 / 2_maximum / _minimum`), the overheat protection temperatures (were
    `hot_mode_*`) and the governor pressure override.
  - **The exhaust brake lockup aid** (stage E's "converter clutch engagement monitor"). The e2m names:
    - 8C17 +4A `RE_E_Brake_Inhibit_Timer`: 'Used to time ebrake TCC inhibit timeout limit';
    - 8C18 +88..+92 `RE_EB_Lockup_Range_*` and +96 `RE_E_Brake_Inhibit_Timeout`;
    - 8C19 +16 `RE_E_Brake_Inhibit_LU`: 'Flag set to inhibit Exhaust Brake to allow TCC lockup'.

    In the code, `cm848_updateEngineRetarderEnableState` reads bit 0 of 0x40b0fe as its torque converter lockup
    disengaged input. The exhaust brake sets that bit entering 2nd gear and after a 4-3 downshift. So the exhaust
    brake waits for converter lock: `cm848_updateExhaustBrakeLockupInhibit`, `exhaust_brake_lockup_flags`,
    `exhaust_brake_lockup_inhibit_timer` / `_timeout`, `exhaust_brake_lockup_speed_ratio_*`. 8C17 drifts from +4C,
    not +4A.
  - **The lockup boost:** `cm848_selectGovernorPressureLockupBoost` (was stage E's `cm848_selectGovernorPressureHighGear`).
    Pressure state 0x10 is `RE_Lockup_Boost`, 'Gov pressure target during lockup, to prevent downshift'
    (`governor_pressure_lockup_boost`, was `governor_pressure_high_gear_target`).
  - **Switch 12 is the exhaust brake switch.** With `exhaust_brake_transmission_features_inhibit` (`RE_Ebrake_Inhibit`,
    0) clear and switch 12 on, `cm848_protectionStateTransitionCheck` uses the alternate `_c` 3-4 / 4-3 lines.
  - **Review fixes:**
    - the `cm848_calculateOutputShaftAcceleration` plate gives its two methods;
    - the ordinals are 1st / 2nd / 3rd everywhere;
    - three `global_variables.csv` comments that earlier scripts wrote with Python's `csv` module are unquoted (the
      importer splits that file with `split(",", 4)`, so commas need no quotes);
    - the stage C comment fix on the gear ratio table lands.
  - **Width check** (`width_check_r8.py`, the stage 8c rule): every 8BBC / 8C17 / 8C18 / 8C53 record in the aligned
    ranges has a row of its size. The exceptions are two words nothing reads: 0x407856 `RE_Lockup_Delay_2_3_Max_2nd`
    and 0x408372 `RE_Cruise_Unlock_Inhibit`.
"""
T046 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(T046, [
    ("  - **8C17 (RAM) at 0x40b102**, aligned +0..+48 (it drifts from +4A, see stage E). The anti-hunt timers start it.",
     "  - **8C17 (RAM) at 0x40b102**, aligned +0..+4A (it drifts from +4C, see stage F). The anti-hunt timers start it."),
    ("    inertia limits start it, and +10 `RE_Inertia_Default` = 53 is the learned inertia in the RAM dump.\n",
     "    inertia limits start it. +10 `RE_Inertia_Default` is the word `cm848_initializeTransmissionShiftLogic` copies\n"
     "    into the learned inertia (`lhz @ 0x331d4`). Both read 53 in the engine-off RAM dump, which is the unlearned\n"
     "    default, not independent evidence.\n"),
    ("  - `cm848_monitorConverterClutchEngagement` (was `cm848_processProtectionRateLimitFlags`). After each converter clutch\n"
     "    command the speed ratio (engine / output speed x 32) must enter the gear's locked window within 3 s\n"
     "    (`converter_clutch_engagement_time_limit`, 300). The windows are 2nd 43-50, 3rd 28-35 and 4th 19-25, around the\n"
     "    gear ratios 46 / 32 / 20. If it does not, the lockup inhibit (`condition_eval` bit 6) is set. This proves\n"
     "    `converter_clutch_transition_state` bits 0 (engagement pending) and 2 (engagement timed out).\n",
     "  - `cm848_monitorConverterClutchEngagement` (was `cm848_processProtectionRateLimitFlags`): read as a converter clutch\n"
     "    engagement monitor (3 s for the speed ratio to enter the gear's window, else the lockup inhibit). Stage F\n"
     "    corrects it: the e2m names it the exhaust brake lockup aid (`cm848_updateExhaustBrakeLockupInhibit`).\n"),
    ("  - `cm848_selectGovernorPressureHighGear` (was `cm848_calculateProtectionThresholdLimit`): pressure state 0x10 in\n"
     "    3rd / 4th below a throttle curve, plus the manual 1 / 2 lever's 4-3 request.\n",
     "  - `cm848_selectGovernorPressureHighGear` (was `cm848_calculateProtectionThresholdLimit`): pressure state 0x10 in\n"
     "    3rd / 4th below a throttle curve, plus the manual 1 / 2 lever's 4-3 request. Stage F renames it\n"
     "    `cm848_selectGovernorPressureLockupBoost` (e2m `RE_Lockup_Boost`).\n"),
    ("  - The 8C17 record at +4A (`RE_E_Brake_Inhibit_Timer`) does not fit the code there (the engagement timer), so 8C17\n"
     "    drifts from +4A.\n",
     "  - Stage E read the 8C17 record at +4A (`RE_E_Brake_Inhibit_Timer`) as not fitting the code. It does fit (stage F),\n"
     "    so 8C17 drifts from +4C.\n" + STAGE_F),
    ("anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 high gear, 0x11 2nd gear locked,",
     "anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 lockup boost, 0x11 2nd gear lockup boost,"),
    ("      requests (e2m `RE_Normal_3_4` / `4_3`, `RE_Cruise_*`). Its gate (`condition_flags_1` bit 4), pressure state\n"
     "      3 and switch 12 are not identified yet. Switch 12 picks the alternate `_c` shift lines, perhaps the exhaust\n"
     "      brake schedule;\n",
     "      requests (e2m `RE_Normal_3_4` / `4_3`, `RE_Cruise_*`). Its gate (`condition_flags_1` bit 4) and pressure\n"
     "      state 3 are not identified yet. Switch 12, the exhaust brake switch (stage F), picks the alternate `_c` shift\n"
     "      lines;\n"),
    ("    - the `protection_condition_flags_t` / `protection_status_flags_t` bits;\n",
     "    - the `protection_condition_flags_t` / `protection_status_flags_t` bits. e2m 8C19 aligns at 0x40b0e8:\n"
     "      - +0 `RE_Trans_Flag1` = `condition_eval`, with `RE_Request_3_4` / `RE_Request_4_3` at bits 2 / 1;\n"
     "      - +1 `RE_Trans_Flag2`, with `RE_Low_Range` at bit 2 and `RE_Decel_Mode_Active` at bit 0;\n"
     "      - +2 `RE_Trans_Flag3`, with `RE_Forced_2nd_Gear_ID` at bit 1 and `RE_High_Pressure` at bit 2;\n"
     "      - +3 `RE_OD_Flags`, +5..+8 the limp flags, +16 the exhaust brake flags.\n"
     "\n"
     "      The e2m gives no bit positions, so each bit still needs its code use;\n"),
    ("  - Blocks 8BB5 / 8BBB / 8BBD / 8C18 / 8C19 (more RE cals and flags), to align the same way.\n",
     "  - Blocks 8BB5 / 8BBB / 8BBD (more RE cals), to align the same way. 8BBB may sit at 0x4077cc: its +34\n"
     "    `RE_EB_Lockup_Delay_4_3_Max` would then be 0x407800, the 4-3 lockup delay `cm848_processOverdriveSwitchAndShift`\n"
     "    loads with `overdrive_control_flags` bit 5.\n"
     "  - Signedness: the anti-hunt compare casts `transmission_predicted_post_shift_acceleration` and\n"
     "    `transmission_post_shift_acceleration_minimum` to `short`. Run the round 3 `i16` rule over round 8's rows; the RE\n"
     "    records give the sign (column 10).\n"
     "  - Method 1's 27-word output speed ring at 0x3fb192 (between `transmission_output_shaft_acceleration_sample_counter`\n"
     "    and `transmission_output_speed_history_index`) as a `word[27]` `transmission_output_speed_history`.\n"),
])
edit(os.path.join(repo, "firmware", "CLAUDE.md"), [
    ("    - 8C17 (RAM) at 0x40b102, +0..+48;\n", "    - 8C17 (RAM) at 0x40b102, +0..+4A;\n"),
    ("    - 8BBC (ROM cals) at 0x40780c, +0..+5C.\n",
     "    - 8BBC (ROM cals) at 0x40780c, +0..+5C;\n"
     "    - 8C18 (ROM cals) at 0x4082f4, +00..+98;\n"
     "    - 8C19 (the RE flag bytes) at 0x40b0e8, the `protection_condition_flags_t` struct (bits not named yet).\n"),
    ("    boost curves gated by a predicted post-shift acceleration from a learned vehicle inertia), `LowRange` and\n"
     "    `HighGear`.\n",
     "    boost curves gated by a predicted post-shift acceleration from a learned vehicle inertia), `LowRange` and\n"
     "    `LockupBoost` (e2m `RE_Lockup_Boost`, pressure state 0x10).\n"),
    ("  - **Converter clutch engagement:** `cm848_updateExhaustBrakeLockupInhibit` gives each clutch command 3 s to show\n"
     "    lock. The speed ratio (engine / output speed x 32) must enter the gear's window around the gear ratio\n"
     "    (`transmission_<gear>_gear_locked_speed_ratio_minimum` / `_maximum`), or the lockup inhibit is set.\n",
     "  - **The exhaust brake lockup aid:** `cm848_updateExhaustBrakeLockupInhibit` holds the exhaust brake off after each\n"
     "    converter clutch command until the speed ratio (engine / output speed x 32) enters the gear's window around the\n"
     "    gear ratio (`exhaust_brake_lockup_speed_ratio_<gear>_minimum` / `_maximum`), for at most 3 s\n"
     "    (`exhaust_brake_lockup_inhibit_timeout`). `cm848_updateEngineRetarderEnableState` reads bit 0 of\n"
     "    `exhaust_brake_lockup_flags` as lockup disengaged. Switch 12 is the exhaust brake switch.\n"
     "  - **A CSV trap:** the importer splits `global_variables.csv` (and `function_renames.csv`) with `split(\",\", 4)` /\n"
     "    `split(\",\", 3)`, so the comment column takes commas unquoted. Python's `csv` module quotes such a comment when\n"
     "    it writes the row, and splits it when it reads one. Edit those rows with `line.split(\",\", 3)`. (Round 8\n"
     "    unquoted three comments that earlier scripts had written that way.)\n"),
    ("`governor_pressure_gear{1,2}_*_target` / `governor_pressure_learned_gain_*` tables (were `protection_derate_rpm_limit_*` / `protection_status_*`).",
     "the WOT boost / hold pressures and the predicted shift delays (were `protection_derate_rpm_limit_*` / `protection_status_*`, then `governor_pressure_gear{1,2}_*_target` / `governor_pressure_learned_gain_*` until PR #53 round 8)."),
])
edit(pr, [
    ("  - 8BBC (ROM cals, 0x40780c) aligns +0..+5C. Its `RE_Inertia_Default` = 53 equals the learned inertia in the RAM\n"
     "    dump.\n",
     "  - 8BBC (ROM cals, 0x40780c) aligns +0..+5C. Its `RE_Inertia_Default` is the word the shift logic initializer copies\n"
     "    into the learned inertia (`lhz @ 0x331d4`).\n"
     "  - 8C18 (ROM cals, 0x4082f4) aligns +00..+98, and 8C19 (the flag bytes) sits at 0x40b0e8 (stage F).\n"),
    ("  - 8C17 (RAM, 0x40b102) aligns +0..+48.", "  - 8C17 (RAM, 0x40b102) aligns +0..+4A."),
    ("  - the converter clutch engagement monitor (`cm848_monitorConverterClutchEngagement`). After each clutch command\n"
     "    the speed ratio must enter the gear's locked window (2nd 43-50 / 3rd 28-35 / 4th 19-25 around the gear ratios)\n"
     "    within 3 s, or lockup is inhibited;\n"
     "  - the high gear mode (`cm848_selectGovernorPressureHighGear`, pressure state 0x10);\n",
     "  - a \"converter clutch engagement monitor\" and a \"high gear mode\" (stage F corrects both, below);\n"),
    ("## Test plan\n",
     "- **Stage F (label-only, after a review): e2m 8C18 (0x4082f4, +00..+98) and the exhaust brake lockup aid.**\n"
     "  - 71 ROM cals named from 8C18, each checked against its row's users. Among them: the engine acceleration limits,\n"
     "    the WOT shift lag band, the lockup and overheat lockup delays, the throttle detent / WOT thresholds, the\n"
     "    predicted shift delay limits and the overheat protection temperatures (were `hot_mode_*`).\n"
     "  - The e2m corrects stage E. 8C17 +4A is `RE_E_Brake_Inhibit_Timer` ('Used to time ebrake TCC inhibit timeout\n"
     "    limit'), the per-gear windows are `RE_EB_Lockup_Range_*` and the flag is 8C19 +16 `RE_E_Brake_Inhibit_LU`. The\n"
     "    code agrees: `cm848_updateEngineRetarderEnableState` reads its bit 0 as lockup disengaged. So the function holds\n"
     "    the exhaust brake off until the converter locks: `cm848_updateExhaustBrakeLockupInhibit`,\n"
     "    `exhaust_brake_lockup_*`.\n"
     "  - Pressure state 0x10 is `RE_Lockup_Boost`, so its mode is `cm848_selectGovernorPressureLockupBoost`. Switch 12 is\n"
     "    the exhaust brake switch.\n"
     "  - Review fixes: the output shaft acceleration plate (two methods), ordinals, and three `global_variables.csv`\n"
     "    comments that an earlier script had quoted (that file takes commas unquoted).\n"
     "\n"
     "## Test plan\n"),
    ("  - stages A, B and E are EQUIVALENT (0 functions differ);\n",
     "  - stages A, B, E and F are EQUIVALENT (0 functions differ);\n"
     "  - the width check: every aligned 8BBC / 8C17 / 8C18 / 8C53 record has a row of its size (two unused words have\n"
     "    none);\n"),
    ("  - the rest of the 48RE controller (the pressure state enum, the 3-4 / 4-3 shift lines, lockup, more RE blocks);\n",
     "  - the rest of the 48RE controller (the pressure state enum, the 8C19 flag bits, the 3-4 / 4-3 shift lines, blocks\n"
     "    8BB5 / 8BBB / 8BBD);\n"),
])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "docs", "agent_notes_2026-11",
                 "session_2026-11-20_egr_flow_delay", "README.md")
s = open(p).read()
a = "- **Stage E, label-only:** "
i = s.index(a)
j = s.index("\n", i) + 1
s = s[:j] + ("- **Stage F, label-only:** `worklist_r8f.py` and `apply_r8f_fix.py`: the stage E rows' notes, the two-method "
             "plate, the new 0x408370 row, three unquoted comments. Also `width_check_r8.py` (e2m size against the "
             "declared width, block by block), `keyed_refresh_audit.py` (the comment-refresh audit keyed by address) and "
             "`quote_counts.py` (quoted CSV lines on two revisions).\n") + s[j:]
open(p, "w").write(s)
print("README ok")
