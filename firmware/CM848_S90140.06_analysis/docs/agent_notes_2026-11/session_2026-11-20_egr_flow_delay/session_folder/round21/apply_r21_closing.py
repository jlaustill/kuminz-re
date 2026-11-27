"""Round 21 closing: the round 21 sections of task 046, the PR body, the session README and the todo line.
Idempotent. usage: apply_r21_closing.py <repo> <pr_body.md> <stage D hash>"""
import os
import sys

repo, pr, d_hash = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


TASK = f"""## Done, round 21 (2026-11-22, same PR; the relayed "keep going" again): the engine protection module

Scripts are in `session_folder/round21/`.
- **The module:** the engine protection feature (the e2m's 'EPF') runs as five round-robin tasks of
  `cm848_runFaultDerateScheduler`. Its per-channel data sits in three e2m blocks, and the channel loops step through
  each with the block's size as the stride: the configuration (112E, ROM), the state (1152, RAM) and the history (1143,
  EEPROM). This build has one channel, fuel temperature.
- **Stage A (75178dc, types):** `engine_protection_channel_configuration_t` / `_state_t` / `_history_t` (36 / 62 / 30
  bytes), the instances `fuel_temperature_engine_protection_configuration` / `_state` / `_history_cal`, and full
  prototypes for the five helpers that take them as parameters. The 62-byte state has 4-byte fields at 2-mod-4
  offsets. A pilot build of it alone showed the importer places fields at running offsets, and the loops step `+ 1`.
- **Stage B (756f2e0, types):**
  - the fault log: `engine_protection_fault_log_entry_t` (occurrence time = `key_on_hour_meter`, extreme value,
    duration) and the two EEPROM logs (e2m 10DA, 5 entries each);
  - the state's current-entry copies and log pointers;
  - the fault-log loop's three current-channel pointers;
  - the fix for stage A's five `i16` fields (see Methods).
- **Stage C (093c501, label-only):** 11 functions and 9 words:
  - the helpers, by what they do: the severity ramp, the threshold test, the restart indexes and limitation, the
    shutdown time count;
  - the loops: the over-limit durations, the restart severity, the fault logs;
  - the log helpers, which open and close an entry;
  - `hpcr_initializeEngineProtection` (was `hpcr_initFuelTemperatureSensorChannel`). Task 025 kept the old name
    because the channel it sets up is fuel temperature, and noted 'SensorChannel overclaims'. All its calls
    initialize engine protection: the derate limits, the start sequence, the protection mode, the precrank error and
    the task index;
  - the working words that were `governor_faultDerate_*` / `fault_channel_*`;
  - the override lamp flag (e2m 10B1 +19).
- **Stage D ({d_hash}, tooling):** `ApplyStructures.java` maps `i16` / `sword` to short and warns when a field type is
  unknown; such a field used to become byte without a word. CM550 and CM848 build identical before and after.
- **Methods:**
  - `structure_definitions.csv` field types: the importer knows byte / word / dword / short / ushort / int / uint /
    pointer, `T*`, and the struct and enum names. Until stage D an unknown name became a byte array without a word:
    `i16`, which `global_variables.csv` uses, did. The decompiler then rendered array decays and odd computed-offset
    bases. `struct_type_fallbacks.py` lists such fields.
  - A struct stage's gate has three parts:
    - known access sites per struct, so a shifted layout fails them;
    - the changed functions stay inside the predicted set once the instance fields are rewritten back to the flat
      names;
    - the artifact counts (pieces, `extraout_`, `unaff_`, `in_r`) do not grow.
    Stage A's sites had no `i16` field, which is how its defect got through. Include one field of every type.
  - Pilot a struct with misaligned 4-byte fields alone before writing the rest.
- **Round 21 leads:**
  - The configuration flags word (+0) is tested at 0x1 / 0x2 / 0x4 / 0x8 / 0x10 / 0x20 / 0x40 / 0x100-0x800 / 0x1000.
    It has no e2m bit records, so a bitfield needs each bit named from the code.
  - `DAT_0040a78c` is cleared with the lamp flag. The module also has other unnamed working words (`DAT_003fbd20`-`26`,
    `3a`, `4e`-`58`). `governor_faultDerate_channel_bit` / `_lookup_interp_state` and their users
    (`engine_protection_derateParam_priorityApply`, `fault_initBitwiseTimerMask`,
    `governor_calculateIntegratorRpmOutput`) are still guesses.
  - e2m 10DA's engine overspeed error log (+0 / +78 / +7A).

## Leads (not in this PR)
"""
t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
t = open(path(t46)).read()
if "## Done, round 21" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = f"""**Round 21 (the relayed "keep going" again): the engine protection module.**
- **Stage A (75178dc, types):** the three per-channel records (e2m 112E / 1152 / 1143) as structs, and full prototypes
  for the helpers that take them.
- **Stage B (756f2e0, types):** the fault log entry and the two EEPROM logs, the fault-log loop's current-channel
  pointers, and stage A's five `i16` fields corrected to `short`.
- **Stage C (093c501, label-only):** the module's 11 functions and 9 working words, from the typed bodies.
- **Stage D ({d_hash}, tooling):** `ApplyStructures.java` maps `i16` / `sword` and warns on an unknown field type.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 20: stages A, C and E are EQUIVALENT;",
     "- [x] Round 21: stages A and B pass a layout / containment / artifact gate (A was piloted first); stage C is "
     "EQUIVALENT; stage D builds CM550 and CM848 identical before and after.\n"
     "- [x] Round 20: stages A, C and E are EQUIVALENT;")
edit(pr, "- **Open after round 20:**\n", "- **Open after round 21:**\n")
edit(pr, "round 20 the algorithm enable flags block.",
     "round 20 the algorithm enable flags block; round 21 the engine protection records and fault logs.")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 21" not in t:
    t += """

## Round 21: the engine protection module (`session_folder/round21/`)

- **Stage A:** `apply_r21a.py` (the three structs and the helper prototypes; `--only state` was the packing pilot),
  `refresh_r21a_plates.py`, the gate `prove_r21a.py`. **Stage B:** `apply_r21b.py` + `prove_r21b.py`, and
  `struct_type_fallbacks.py` (the field types the importer does not know). **Stage C:** `worklist_r21c.py`,
  `apply_r21c2.py`. **Stage D:** `patch_apply_structures.py` (mind the file's CRLF line endings). **Closing:**
  `apply_r21_closing.py`.
- **Evidence:** `blocks.txt` (e2m 112E / 1152 / 1143), the per-function bodies `body_*.txt`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 21" not in lines[i]:
    tail = " - open: the task 046 leads"
    assert lines[i].endswith(tail), lines[i][-60:]
    lines[i] = lines[i][:-len(tail)] + ("; round 21: the engine protection module (3 channel record structs, the fault "
                                        "log, 11 functions + 9 words named, the struct importer's i16 gap)" + tail)
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
