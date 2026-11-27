"""Round 13 closing: the round 13 sections of task 046, the PR body, the session README and the todo line.
usage: apply_r13_docs.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(path, old, new):
    text = open(path).read()
    assert text.count(old) == 1, (os.path.basename(path), old[:70], text.count(old))
    open(path, "w").write(text.replace(old, new))


TASK = """## Done, round 13 (2026-11-21, same PR; the relayed "keep going" again): the end-of-line tests and the SCI service tests

Scripts are in `session_folder/round13/`.
- **Stage A (99a8d67, label-only): the end-of-line test steps and the SCI command 0x25 service tests.**
  - **The sequencer:** `cm848_runEndOfLineTestSequence` runs seven step functions, each returning the next step.
    Their names were cold start / protection / cam sync / fault queue guesses.
    - 0 start, then 1 the output tests (engine stopped): lift pump, then the wait-to-start lamp and A/C clutch relay,
      then intake air heaters 1 and 2 one at a time.
    - 2 the intake air heater verdict: the battery voltage drop each heater causes.
    - 3 the alternator test, which cuts the field.
    - 4 the fan speed noise, 5 the misfire test, 6 the plant tester's final result.
  - **The settings:** e2m 164A `EOL_*` and 1649 `CHRY_In_Plant_*`. 0x642ee is 164A +C `EOL_EVR_Test_Time`.
  - **The SCI command 0x25 tests** (DRB 25-xx; the e2m calls them `Cmd25`). `cm848_expireSciCommand37Tests` (was
    `protectionVoltageTimeoutControl`) ends each one at its timeout.
    - 0x11 alternator field, 0x14-0x16 the 48RE solenoids, 0x24 lift pump.
    - 0x25 cylinder contribution (DRB 25-25 CylinderPerformanceTest, e2m 8C74).
    - 0x26 high pressure safety valve (DRB 25-26, e2m 8C76 / 8C77 / 8022 +1E).
    - 5-10 cut out injectors 1-6.
  - **`BYTE_003fd1ac`** is `end_of_line_test_seconds_since_engine_start`. It is time-shared with the boot kernel, and its
    boot calls keep their call override.
  - **The alternator verdict** takes the present voltage minus the snapshot in 16 bits (`subf` / `clrlwi`), so any fall
    in voltage passes.
- **Stage B (a44169f, types): three enums.**
  - `SERVICE_TOOL_TEST_STATE` (e2m '0=NOT_RUN,1=RUN,2=ABORT') on the cylinder contribution and HPSV test states.
  - `END_OF_LINE_TEST_STEP` and `END_OF_LINE_OUTPUT_TEST_STATE`.
  - The proof is `check_enum_proof3.py`, which handles byte-sized enum types: 0 functions differ beyond the
    substitutions.
- **Stage C (f951258, label-only): the record-anchored governor reference speeds.**
  - **DRB SCI 0x19 'SET RPM'** (19-7D 'SET ECM RPM 1000' = 125 x 8): `sci_set_engine_speed_request`, with its 0xe5c1
    key and a 72-pass timeout. The LSG target selection takes it as `low_speed_governor_service_speed_floor`.
  - **e2m block 0008** (checked in both dumps):
    - `LSG_Breakpoint_Speed` is `low_speed_governor_base_reference_speed_cal` (750 rpm).
    - `ASG_Minimum` / `_Maximum` for sets 1 and 2 (740 / 4650 rpm) and their blend
      (`cm848_blendAllSpeedGovernorReferenceSpeeds`). The old names called the minimum 'high' and the maximum
      'low'.
  - **Bit maps in the comments:** `end_of_line_test_enable_flags`, the in-plant flag bytes and
    `service_test_request_flags`.
- **Round 13 leads:**
  - **The low speed governor reference speed chain** (about 75 rows) has almost no e2m records, so it needs its own
    round:
    - `cm848_updateSpeedLimitFromCoolant` is the coolant idle speed (e2m 8A51 / 8A52 `LSG_Coolant_*`). Its engage /
      disengage timers are not traced yet.
    - `cm848_calculateProtectionSpeedLimits` is the LSG target selection. It takes the largest of: the base
      reference speed (source 5), the coolant idle (0), the park / neutral idle (1), the cold idle-up (2: battery and
      coolant cold), switch 13 (3), the PCI idle request (4), the barometric idle (9), the service floor (11) and the
      moving-vehicle table (12, e2m 8C51 / 8C52). Source 10 means a shift is in process, and 6 is the TSC1 override.
    - `cm848_applySpeedLimitConstraints` ramps `idle_reference_speed` toward the target. The `thermal_governor_*`
      words are its up / down rates, and the minimum (source 7) and maximum (source 8) clamps follow.
    - The source code `governor_output_t.governor_output` needs an enum with every value 0-12 proved; 7 and 8 are
      stored in the ramp function.
  - **The injector cutout markers** at 0x3fcf64 are a `word[8]` array candidate (the cancel loop reads them with
    `lhz`).
  - **The 47 '+N' offcut-label rows** in `global_variables.csv` are legacy export rows; some carry stale base names.
  - **e2m 1981 +0 `EOL_Alternator_Test_State`** (0x3fee9a) has no access in either bank.
  - **`cm848_validateWriteAuth`'s local declaration order** flips between builds of different CSVs. The DECL pattern
    of `reverse_names.py` probably does not match its array locals.

## Leads (not in this PR)
"""
edit(os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md"), "## Leads (not in this PR)\n", TASK)
PR_ROUND = """**Round 13 (the relayed "keep going" again): the end-of-line tests and the SCI command 0x25 service tests.**
- **Stage A (99a8d67, label-only): the steps of the Chrysler end-of-line (in-plant) test sequencer.**
  - The steps are the output tests (lift pump / wait-to-start lamp and A/C clutch relay / intake air heaters), the
    heater voltage-drop verdict, the alternator test, the fan speed noise, the misfire test and the final result.
  - They were cold start / protection / cam sync guesses. e2m 164A / 1649 name their settings.
  - **The SCI command 0x25 tests** (DRB 25-xx, e2m `Cmd25`) and their timeouts: the alternator field, the 48RE
    solenoids, the lift pump, the cylinder contribution test and the high pressure safety valve test.
- **Stage B (a44169f, types):** `SERVICE_TOOL_TEST_STATE` (e2m 0 not run / 1 running / 2 aborted),
  `END_OF_LINE_TEST_STEP` and `END_OF_LINE_OUTPUT_TEST_STATE`.
- **Stage C (f951258, label-only):**
  - the DRB SCI 0x19 'SET RPM' request;
  - the LSG base reference speed and the ASG minimum / maximum reference speeds from e2m block 0008. The old names
    called the minimum 'high'.
  - the bit maps in the comments.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] `./analyze.sh verify`: the two builds are byte-identical.\n",
     "- [x] Round 13:\n"
     "  - stages A and C are label-only (stage A: one function's local declarations reorder, sorted lines identical;\n"
     "    stage C EQUIVALENT);\n"
     "  - stage B passes `check_enum_proof3.py` (0 functions differ beyond the enum substitutions);\n"
     "  - the thunk stage still makes 19 thunks and 13 call overrides.\n"
     "- [x] `./analyze.sh verify`: the two builds are byte-identical.\n")
edit(pr, "- **Open after round 12:**\n  - the fault status records (a packed record array, but the range is time-shared RAM);\n"
         "  - the end-of-line test sequencer;\n",
     "- **Open after round 13:**\n  - the low speed governor reference speed chain (about 75 rows; task 046 lists the three functions' roles);\n"
     "  - the fault status records (a packed record array, but the range is time-shared RAM);\n")
edit(pr, "  Round 11 resolved the output bitfields and the lift pump control; round 12 the cam_sync fuel metering tables and the setpoint caches.\n",
     "  Round 11 resolved the output bitfields and the lift pump control; round 12 the cam_sync fuel metering tables and the setpoint caches; round 13 the end-of-line test sequencer.\n")
README = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
text = open(README).read()
text = text.rstrip("\n") + """

## Round 13: the end-of-line tests and the SCI command 0x25 service tests (`session_folder/round13/`)

- **Stage A:** `worklist_r13a.py` (35 renames, 13 functions), `new_r13a.json` (10 new rows) and `apply_r13a_plates.py`.
- **Stage B:** `apply_r13b_enums.py`. The proof is `check_enum_proof3.py`, a copy of the fueling state session's
  `check_enum_proof2.py` that normalizes byte-sized enum types to `byte`.
- **Stage C:** `worklist_r13c.py`, `apply_r13c_comments.py` (the bit maps, the cutout correction) and
  `apply_r13c_docs.py`.
- **Audits:** `refresh_diff_offline.py` checks a committed stage's reference refresh between two commits.
  `keyed_refresh_audit_refs.py` is the same audit pinned to two commits.
- **Logs:** the round 13 build logs and the final verify log are in the large-files tarball.
- **Commit messages:** `commit_r13*.txt`.
"""
open(README, "w").write(text)
TODO = os.path.join(repo, "work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
assert lines[i].endswith("open: the fault status records (time-shared RAM)"), lines[i][-80:]
lines[i] += ("; round 13: the end-of-line test steps and the SCI command 0x25 service tests (DRB 25-xx, e2m Cmd25), "
             "three enums, the SCI SET RPM request and the LSG / ASG reference speeds from e2m 0008 - open: the low "
             "speed governor reference speed chain")
open(TODO, "w").write("\n".join(lines))
print("task 046, PR body, README, todo")
