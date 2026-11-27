"""Round 13 stage C: the docs that cite round 13 old names. Historical lead notes get the new name in parentheses or
a 'Resolved by PR #53 round 13' line; firmware/CLAUDE.md only gets the rename of 0x3fd1ac (no new rule).
usage: apply_r13c_docs.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    text = open(p).read()
    assert text.count(old) == 1, (rel, old[:70], text.count(old))
    open(p, "w").write(text.replace(old, new))


edit("firmware/CLAUDE.md",
     "Three addresses keep a `BYTE_` data label on purpose because the application uses them as data: 0x3fd1ac / "
     "0x3fd284 / 0x3fd298 (time-shared with the kernel image). Give them application names before dropping the "
     "labels.",
     "Two addresses keep a `BYTE_` data label on purpose because the application uses them as data: 0x3fd284 / "
     "0x3fd298 (time-shared with the kernel image). Give them application names before dropping the labels. The "
     "third, 0x3fd1ac, is `end_of_line_test_seconds_since_engine_start` since PR #53 round 13 (the boot calls there "
     "keep their call override).")
edit("work/tasks/025-cm848-naming-wave-followups.md",
     "used by diag_iat_protection_stateMachine_update and engine_protection_timerStateMachine_init. Suggest",
     "used by diag_iat_protection_stateMachine_update and engine_protection_timerStateMachine_init "
     "(cm848_runEndOfLineTestStartStep since PR #53 round 13: it writes 0 / 0x19 to bytes 4-5 at the start of the "
     "end-of-line tests). Suggest")
edit("work/tasks/025-cm848-naming-wave-followups.md",
     "written by diag_iat_protection_stateMachine_update and engine_protection_timerStateMachine_init (byte 3",
     "written by diag_iat_protection_stateMachine_update and engine_protection_timerStateMachine_init (now "
     "cm848_runEndOfLineTestStartStep, PR #53 round 13) (byte 3")
edit("work/tasks/042-table-campaign-rename-leads.md",
     "with engine speed within governor_speed_limit_output +/- 160 counts",
     "with engine speed within governor_speed_limit_output (low_speed_governor_base_reference_speed_cal since PR #53 "
     "round 13) +/- 160 counts")
edit("work/tasks/044-cm848-dtc-code-name-clashes.md",
     "  `end_of_line_test_settings_cal.test_flags_2`. They are probably end-of-line test steps, not protection.\n",
     "  `end_of_line_test_settings_cal.test_flags_2`. They are probably end-of-line test steps, not protection.\n"
     "  Resolved by PR #53 round 13: they are steps 0 and 1 of the end-of-line test sequence\n"
     "  (`cm848_runEndOfLineTestStartStep` / `cm848_runEndOfLineOutputTestStep`).\n")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "    `cold_start_protection_*` words, `fault_event_queue_clear_active` and `protection_voltage_active_flag`.\n",
     "    `cold_start_protection_*` words, `fault_event_queue_clear_active` and `protection_voltage_active_flag`.\n"
     "    (Resolved in round 13: the end-of-line test steps and the SCI command 0x25 service tests.)\n")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "  - The end-of-line test sequencer, 8C80 / 8C2D and the SCI high-speed words stay open from round 10 (round 12\n"
     "    resolved the cam_sync tables).\n",
     "  - 8C80 / 8C2D and the SCI high-speed words stay open from round 10 (round 12 resolved the cam_sync tables,\n"
     "    round 13 the end-of-line test sequencer).\n")
print("7 doc edits")
