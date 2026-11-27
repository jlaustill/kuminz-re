"""Round 7 docs: task 046, firmware/CLAUDE.md, todo 046, the PR body. usage: docs_r7.py <repo> <pr_body.md>"""
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


R7_TASK = """## Done, round 7 (2026-11-21, same PR; the user's next "keep going")

Hand work on the round 6 leads (scripts in `session_folder/round7/`).
- **Stage A (9d2ebdf, label-only):**
  - **The J1939 monitor's working words** take their e2m 1100 names: `j1939_engine_control_source_cal` /
    `j1939_retarder_control_source_cal` and `j1939_control_session_history_next_entry_cal`.
  - **The tracker's retarder-half copies** are named like the engine half.
  - **The session functions' parameter** is `session_kind`, typed `int32_t` (the importer maps `int` to `dword`).
  - **The engine retarder TSC1 handler,** read in full:
    - `engine_retarder_received_tsc1_control_byte` / `_torque_byte`;
    - `retarder_tsc1_zero_torque_request_timer`: armed while the requested torque or limit is 0; why that is timed
      is open;
    - `retarder_tsc1_speed_control_flag`: always 0, because speed control is rejected;
    - `cm848_resetEngineRetarderTsc1Request` and `cm848_endRetarderShiftAssistAboveFuelDemandLimit`.
- **Stage C (9fd5621, label-only): the drivetrain ratio module.**
  - **Misnamed words:** `drivetrain_ratio_filter_state` (was `engine_temperature_protection_filter_state`) and
    `drivetrain_ratio_engine_period_valid_flag` (was `protection_timeout_enable_flag`, set by the VSS interrupt's
    period average).
  - **Gear down:** `drivetrain_gear_range` (was `governor_j1939_bypass_flag`) is the gear-down protection range,
    with `top_gear_ratio_threshold` / `gear_down_ratio_threshold`.
  - **Functions:** `cm848_initializeDrivetrainRatio`, `cm848_applyJ1939OutOfGearToDrivetrainRatio` and
    `cm848_saveOutputShaftSpeed`.
- **Stage B (types):**
  - **`j1939_control_session_t`,** the 24-byte j1939mon session record. Its layout comes from the three monitor
    functions and the EEPROM image's length words (0x78 / 0x18 / 0x18).
    - **Instances:** the history `[5]`, the active engine and the active retarder records.
    - **Replaced rows:** the four member rows. The control source words are `J1939_CONTROL_DEVICE`.
  - **The drivetrain cals** from e2m 106D, and `gear_down_gear_ratio_cal` (0x3fd900, e2m 8B8B).
  - **`DRIVETRAIN_GEAR_RANGE`.**
  - **The history store's locals** are named. The record local keeps the struct pointer type: its copy start reads
    `&session_record[-1].duration + 2` (the word before the record). A `word *` or `byte *` local made Ghidra spell
    it out longer.
- **Found:** the history table's length word (0x3fead4) is also `j1939_input_signal_timeouts[24]`.
  - The supervision tick's loop covers 25 words (`addi r3 = r4 + 48` / `bge` @ 0x50bd9c-0x50bdc4), so it would count
    the length word down.
  - The tick is off in this calibration (`j1939_input_processing_enable_cal` = 0). Documented on the array.
- **Thin evidence:**
  - `gear_down_gear_ratio_cal`'s address comes from the code. Block 8B8B is not in the parameter ID table.
  - Range codes 2 and 3 are never tested apart; the readers only test 1 against everything else.
  - The tolerance percent at 0x408b78 has no writer and no e2m record, so it is unnamed.
- **Round 7 leads:**
  - The transmission gear functions `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and
    `cm848_processProtectionStateFlags` (0x3257c): `transmission_current_gear` / output speed logic under inherited
    `protection_*` names (e2m 8D14 drifts).
  - The engine run-state machine (819B).
  - `cm848_initGovernorStateVariables`, a mixed governor initialization.

"""
p46 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(p46, [("## Leads (not in this PR)\n", R7_TASK + "## Leads (not in this PR)\n")])
pcl = os.path.join(repo, "firmware", "CLAUDE.md")
edit(pcl, [("  - **Ghidra:** a piece name such as `_10_2_` counts in decimal (offset 10 = +0xa). A multi-bit mask on a\n"
            "    bitfield renders as a raw piece (`_32_2_ & 3`), so masked flag words stay words.\n",
            "  - **Ghidra:** a piece name such as `_10_2_` counts in decimal (offset 10 = +0xa). A multi-bit mask on a\n"
            "    bitfield renders as a raw piece (`_32_2_ & 3`), so masked flag words stay words.\n"
            "- **Round 7 (2026-11-21, PR #53):** the J1939 monitor (j1939mon) and the drivetrain ratio module.\n"
            "  - **`j1939_control_session_t`** is the 24-byte session record (e2m 10FD history table `[5]` at 0x3fead6,\n"
            "    10FE / 10FF active engine / retarder records at 0x3feb50 / 0x3feb6a, each behind a length word).\n"
            "  - **The drivetrain module:** `drivetrain_gear_range` / `DRIVETRAIN_GEAR_RANGE` is the gear-down protection\n"
            "    range (top gear / one gear down / lower; `top_gear_ratio_cal` 0.8, `gear_down_gear_ratio_cal` 1.0). The\n"
            "    cals come from e2m 106D.\n"
            "  - **The importer:** a `function_definitions` / `local_variables` type `int` becomes `dword`; use\n"
            "    `int32_t` for a signed int.\n")])
ptodo = os.path.join(repo, "work", "todo.md")
edit(ptodo, [("table and its time limits) - open: the J1939 monitor session record (e2m 10FE / 10FF / 1100), the engine "
              "speed module's functions,",
              "table and its time limits); round 7: the J1939 monitor session record (j1939_control_session_t), the "
              "engine retarder TSC1 words, the drivetrain ratio module and gear-down range - open: the transmission gear "
              "functions 0x3241c / 0x3257c, the engine speed module's functions,")])
R7_PR = """**Round 7 (another "keep going"): the J1939 monitor's session record, the retarder TSC1 words, the drivetrain
ratio module.**
- **Stage A (9d2ebdf, label-only):**
  - the J1939 monitor's e2m 1100 words and the tracker's retarder-half copies;
  - the engine retarder TSC1 handler read in full: the received bytes, a zero torque request timer, and a speed
    control flag that is always 0 because the handler rejects speed control;
  - `cm848_resetEngineRetarderTsc1Request` and `cm848_endRetarderShiftAssistAboveFuelDemandLimit`.
- **Stage C (9fd5621, label-only):** the drivetrain ratio module.
  - **Two misnamed words:** `drivetrain_ratio_filter_state` was `engine_temperature_protection_filter_state`, and
    `drivetrain_ratio_engine_period_valid_flag` was `protection_timeout_enable_flag`.
  - **Gear down:** `governor_j1939_bypass_flag` is the gear-down protection range (`drivetrain_gear_range`: top gear
    / one gear down / lower). With the feature on, only top gear keeps the road speed governor's droops.
- **Stage B (types):**
  - **`j1939_control_session_t`,** the j1939mon record (e2m 10FD / 10FE / 10FF), on the history `[5]` and the two
    active records. Its layout comes from the code and the EEPROM image's length words, and it replaces four member
    rows.
  - **The drivetrain cals** from e2m 106D, plus `gear_down_gear_ratio_cal`.
  - **`DRIVETRAIN_GEAR_RANGE`.**
- **Found:** the history table's length word is also `j1939_input_signal_timeouts[24]`. The supervision tick would
  count it down, but the tick is off in this calibration.

"""
edit(pr, [("## Test plan\n", R7_PR + "## Test plan\n"),
          ("- [x] `./analyze.sh verify`: the two builds are byte-identical.",
           "- [x] Round 7:\n"
           "  - stages A and C are EQUIVALENT;\n"
           "  - stage B was read diff by diff: the struct field renders, the enum renders and declaration order;\n"
           "  - the session functions' `int32_t` parameter was found because the first 7a build rendered `int` as\n"
           "    `dword`.\n"
           "- [x] `./analyze.sh verify`: the two builds are byte-identical."),
          ("  - the J1939 monitor's session record (e2m 10FE / 10FF / 1100: still etc1_governor-named words);\n",
           "  - the transmission gear functions 0x3241c / 0x3257c (inherited `protection_*` names);\n")])
