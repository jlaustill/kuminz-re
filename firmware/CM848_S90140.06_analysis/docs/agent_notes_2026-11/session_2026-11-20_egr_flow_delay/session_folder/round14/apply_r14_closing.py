"""Round 14 closing: the comments the refresh tool skips (enums.csv, structure_definitions.csv, a test comment), the task
notes that described the chain, and the round 14 sections of task 046, the PR body, the session README and the todo
line. usage: apply_r14_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")


def edit(path, old, new, count=1):
    text = open(path).read()
    assert text.count(old) == count, (os.path.basename(path), old[:70], text.count(old))
    open(path, "w").write(text.replace(old, new))


R14 = "PR #53 round 14"
edit(os.path.join(out, "enums.csv"), "while governor_speed_limit_active_flag is set",
     "while low_speed_governor_extended_idle_active_flag is set")
edit(os.path.join(out, "structure_definitions.csv"), "while governor_speed_limit_active_flag is set",
     "while low_speed_governor_extended_idle_active_flag is set")
edit(os.path.join(repo, "firmware/scripts/test_lookup_tables.py"),
     "governor_minimum_speed_by_vehicle_speed_axis word[10]", "low_speed_governor_moving_speed_axis word[10]")
t25 = os.path.join(repo, "work/tasks/025-cm848-naming-wave-followups.md")
edit(t25, "rnor_speed_limit_* and 'protection' names there need their own review.",
     f"rnor_speed_limit_* and 'protection' names there need their own review. Resolved by {R14}: e2m 14EE / 1496 "
     "aligned by offset; cm848_selectLowSpeedGovernorDesiredReferenceSpeed / cm848_slewLowSpeedGovernorReferenceSpeed "
     "and LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE (task 046).")
edit(t25, "ionSpeedLimits and that family are misleading - a follow-up re-domain.",
     f"ionSpeedLimits and that family are misleading - a follow-up re-domain. (Resolved by {R14}.)")
edit(t25, " the separate Cold_Idle_Coolant_Temperature / Cold_Idle_Time (0 here).",
     " the separate Cold_Idle_Coolant_Temperature / Cold_Idle_Time (0 here). Resolved by "
     f"{R14}: the whole e2m 14EE block is at 0x4070ee (low_speed_governor_*).")
edit(os.path.join(repo, "work/tasks/042-table-campaign-rename-leads.md"),
     "- `protection_iat_scaled`, `governor_cold_start_iat_correction`, `iat_fuel_trim_*`",
     "- `protection_iat_scaled`, `governor_cold_start_iat_correction` (`low_speed_governor_altitude_speed_target` since "
     f"{R14}), `iat_fuel_trim_*`")
edit(os.path.join(repo, "work/tasks/045-cm848-fueling-state-enum.md"),
     "  - `governor_speed_error_delta_filter` (was `governor_bank2_cal_ptr`);",
     f"  - `governor_speed_error_delta_filter` (was `governor_bank2_cal_ptr`; `low_speed_governor_error_filter` since {R14});")
t46 = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
text = open(t46).read()
n = text.count("`cm848_initGovernorStateVariables`")
assert n == 2, n
text = text.replace("`cm848_initGovernorStateVariables`",
                    "`cm848_initGovernorStateVariables` (now `cm848_initializeLowSpeedGovernorReferenceSpeed`)")
old = "key and a 72-pass timeout. The LSG target selection takes it as `low_speed_governor_service_speed_floor`.\n"
assert text.count(old) == 1
text = text.replace(old, "key and a 72-pass timeout. The LSG target selection takes it as `low_speed_governor_service_speed_floor`\n"
                    "    (`low_speed_governor_tool_speed_request` since round 14: e2m 1496 +1C LSG_Tool_Speed).\n")
start = text.index("  - **The low speed governor reference speed chain** (about 75 rows) has almost no e2m records")
end = text.index("  - **The injector cutout markers**", start)
text = text[:start] + "  - **The low speed governor reference speed chain:** resolved in round 14 (below).\n" + text[end:]
TASK = """## Done, round 14 (2026-11-21, same PR; the relayed "keep going" again): the low speed governor reference speed chain

Scripts are in `session_folder/round14/`.
- **The records:** the Cummins e2m blocks lie past the end of the dumped parameter ID table, so they are aligned by
  relative offset. Every record is checked against its code use and the dump values:
  - 14EE (ROM settings) at 0x4070ee: all 32 records +0..+3E. 8C76 follows at 0x40712e, so 11.46 has no +40 / +42.
  - 1496 (RAM) at 0x40aeb2: all 16 records. +14 `LSG_Reference_Speed_State` is the source code, and +1A
    `SCI_Cmd19_Status` is round 13's 0xE5C1 key.
  - 14EF (ROM) at 0x5c4ae (it ends where 8A51 starts) and 14F0 (RAM) at 0x40aede: the LSG error terms.
  - The widths match the e2m sizes (14EE +28 and 1496 +16 are the 4-byte records).
- **Stage A (29de6d0, label-only):** 68 globals, 7 functions, the struct and 3 new rows.
  - The task `cm848_updateLowSpeedGovernorReferenceSpeed` runs the coolant temperature speed
    (`cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed`), the desired speed selection
    (`cm848_selectLowSpeedGovernorDesiredReferenceSpeed`, was `cm848_calculateProtectionSpeedLimits`) and the slew
    (`cm848_slewLowSpeedGovernorReferenceSpeed`; the `thermal_governor_*` words were its rates).
  - The struct at 0x40aec2 is `low_speed_governor_reference_t` (reference speed / no-load fuel / state / altitude
    speed).
  - The three `*_PN_Enable` flags read backwards (0 = park / neutral at rest only), so they are named
    `*_outside_park_neutral_enable`.
  - Switch 13 is e2m 1612 `AC_On_Off_Switch`.
- **Stage B (d65de3e, types):** `LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE`, from the record's own value labels (0
  COOLANT ... 12 MOVING), exactly the thirteen sources the code stores. `check_enum_proof3.py`: 0 functions differ.
- **Stage C (3307773, types):** the 0x3faf7a dword is two words: the extended idle conditions flag, and the base
  reference speed's boot copy (only the initializer writes it). EQUIVALENT with the old pieces mapped back.
- **Round 14 leads:**
  - **0x40aedc** is subtracted from the reference before droop, but its only store is 0 (`governor_speed_error_reference`;
    the droop or a throttle adjustment).
  - **The LSG PID internals** in `cm848_runLowSpeedGovernor` (`governor_speed_debounce_active_flag`,
    `governor_speed_error_prev_snapshot`, `governor_speed_low_clamp`; e2m 1064 / 1065).
  - **The fuel by throttle table** of `cm848_calculateLowSpeedGovernorNoLoadFuel` (`governor_fuel_demand_axis_cal` /
    `_output_cal` at 0x40713a) has no record yet.

## Leads (not in this PR)
"""
text = text.replace("## Leads (not in this PR)\n", TASK, 1)
open(t46, "w").write(text)
PR_ROUND = """**Round 14 (the relayed "keep going" again): the low speed governor reference speed chain.**
- **The records:** e2m 14EE / 1496 / 14EF / 14F0, aligned by relative offset (they lie past the dumped parameter ID
  table). Every record matches its code use and the dump values.
- **Stage A (29de6d0, label-only):**
  - the coolant temperature speed, the desired speed selection and the slew (were `cm848_updateSpeedLimitFromCoolant`
    / `cm848_calculateProtectionSpeedLimits` / `cm848_applySpeedLimitConstraints`);
  - 68 words, among them the A/C / drive / park / extended idle / tool / moving speeds and the rates;
  - the struct `low_speed_governor_reference_t`.
- **Stage B (d65de3e, types):** `LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE` from the record's own value labels.
- **Stage C (3307773, types):** a dword split into its two halves.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "  - stage D (comments) is EQUIVALENT;\n",
     "  - stage D (comments) is EQUIVALENT;\n"
     "- [x] Round 14: stages A and C are EQUIVALENT (C with the split words mapped back to the old pieces); stage B\n"
     "  passes `check_enum_proof3.py`.\n")
edit(pr, "- **Open after round 13:**\n  - the low speed governor reference speed chain (about 75 rows; task 046 lists the three functions' roles);\n",
     "- **Open after round 14:**\n  - the LSG PID internals and the droop word at 0x40aedc (task 046);\n")
edit(pr, "; round 13 the end-of-line test sequencer.\n",
     "; round 13 the end-of-line test sequencer; round 14 the low speed governor reference speed chain.\n")
README = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
t += """

## Round 14: the low speed governor reference speed chain (`session_folder/round14/`)

- **Stage A:** `worklist_r14a.py` (68 globals, 7 functions), `apply_r14a_struct.py` (the struct at 0x40aec2) and
  `new_r14a.json` (the 14EF gain and clamps).
- **Stage B:** `apply_r14b_enum.py`, proved with round 13's `check_enum_proof3.py`.
- **Stage C:** `apply_r14c_split.py`; its proof map sends the two words back to the old `._0_2_` / `._2_2_` pieces.
- **Closing:** `apply_r14_closing.py`.
- **Logs and commit messages:** the round 14 build logs are in the large-files tarball; the messages are
  `commit_r14*.txt`.
"""
open(README, "w").write(t + "\n")
TODO = os.path.join(repo, "work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
assert lines[i].endswith("open: the low speed governor reference speed chain"), lines[i][-60:]
lines[i] += ("; round 14: the low speed governor reference speed chain from e2m 14EE / 1496 / 14EF / 14F0 (aligned by "
             "offset), LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE from its value labels, a dword split - open: the LSG PID "
             "internals")
open(TODO, "w").write("\n".join(lines))
print("comments, task notes, task 046, PR body, README, todo")
