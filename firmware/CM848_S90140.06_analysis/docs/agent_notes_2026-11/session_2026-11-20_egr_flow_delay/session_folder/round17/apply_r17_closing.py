"""Round 17 closing: the leads round 17 resolved, and the round 17 sections of task 046, the PR body, the session
README and the todo line. Idempotent. usage: apply_r17_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(t46, "    1-6, and `EB_Brake_Type` 0-3 (a bitmask in this code).\n",
     "    1-6, and `EB_Brake_Type` 0-3 (a bitmask in this code). (Done in round 17.)\n")
edit(t46, "  - **The engine retarder family** (e2m 1070 / 1071 / 1192), still open from round 15. 1192 +4 / +6 / +8 have no\n"
          "    rows.\n",
     "  - **The engine retarder family** (e2m 1070 / 1071 / 1192), still open from round 15. 1192 +4 / +6 / +8 have no\n"
     "    rows. (Done in round 17; 1192 +4 / +6 / +8 have no reader.)\n")
TASK = """## Done, round 17 (2026-11-21, same PR; the relayed "keep going" again): the engine retarder request chain

Scripts are in `session_folder/round17/`.
- **The records:** the parameter ID table places e2m 1070 (RAM 0x40a352), 1071 (ROM 0x408e9a), 1192 (EEPROM) and the
  117D retarder words. Each was checked against the seven steps of `cm848_processEngineRetarderRequest`. The 20
  renamed rows with records match their e2m sizes, apart from the 0x40a35c dword, which stage C splits.
- **The vocabulary is the e2m's, and it fits the code exactly:**
  - The **override command** is the TSC1 request: source 1 (J1939 override) or 6 (no override).
  - The **non-override command** is the lowest of the cruise permission (2), the operator switch selection (3) and
    the TSC1 limit (4). It restarts at 101 (none) each pass the allowed state is 2.
  - The **allowed state** picks between them: 0 none, 1 override only (the driver conditions hold the rest off), 2
    override or non-override. The **command level** and **command source** are the result, and the ERC1 builder maps
    the source to SPN 900 by compares.
  - The rule for the three words: `engine_retarder_*` names the brake request chain (e2m EB = engine brake) and the
    J1939 retarder words. `exhaust_brake_*` names the 48RE lockup aid and the exhaust brake switch (switch 12), and
    `variable_geometry_turbocharger_brake_*` names the VG brake. They describe one system at different layers, so they
    are not mass-renamed.
  - 'Driver' in these names is the human: the pedal / clutch / brake conditions. The e2m's hardware-driver words take
    'output' names (`EB_Driver_Level` is `engine_retarder_output_level_percent`).
  - e2m 1070 +10 / +20 (a 0-255 switch sum, a 1/8192 fraction) do not explain the code's 0 / 100 values, so
    `engine_retarder_switch_percent` / `_2` keep their code-derived names.
- **Stage A (9d4ddaf, label-only):** 28 globals, 2 functions and 1 field (EQUIVALENT, 30 names).
  - The seven other plates of the chain are rewritten in these words. They called the extended idle condition 'the
    road speed limit'.
  - **`algorithm_enable_flags_18_t` bit 14 is proven:** `engine_retarder_service_brake_activate_enable` (e2m
    EB_Service_Brake_Activate_Enable, was `reserved_bit_14`). While it is set, the driver conditions pass only after a
    service brake tap or with a cruise non-override command.
  - The 0x40a27c comment called the TSC1 devices primary / secondary / tertiary. They are e2m 10E6 +2's
    `J1939_CONTROL_DEVICE` codes.
- **Stage B (bd059da, types):** `ENGINE_RETARDER_COMMAND_SOURCE` (117D +8 value labels) on the three source words,
  `ENGINE_RETARDER_ALLOWED_STATE` (1070 +14), and `J1939_CONTROL_DEVICE` on `engine_retarder_j1939_control_device`.
  `check_enum_proof3.py`: 0 functions differ beyond the substitutions.
- **Stage C (833d573, types):** `engine_retarder_brake_type_t` (bit 0 exhaust brake, bit 1 VG brake; a ROM word read only with
  masks), and the 0x40a35c dword is now the word `engine_retarder_immediate_brake_flag` (one `sth` per store).
- **Round 17 leads:**
  - **The service tool test points** (1070 +1A / +1C) are never written in this build, so their 1 / 2 / 3 codes are
    read from the code alone. They do not use the SPN 695 numbering: there 1 is speed control.
  - **`fuel_demand_offset_correction`** is added to the idle / PTO fueling limits, and its role is unread.
  - **The engage delay** by engine speed (1071 +C / +12 / +14) is written but has no effect: the shift block clears the
    inhibit flag first. It may be a 11.46 change.
  - **`algorithm_enable_flags_41_t.engine_retarder_speed_limit_enable`** forces the retarder selection to 100 during
    extended idle, a warm-up use. The bit's name and the e2m record for it are still open.

## Leads (not in this PR)
"""
t = open(path(t46)).read()
if "## Done, round 17" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 17 (the relayed "keep going" again): the engine retarder request chain.**
- **Stage A (9d4ddaf, label-only):** the chain in the e2m's words: the override command (TSC1), the non-override
  command (the lowest of cruise / switch / TSC1 limit), the allowed state, the command level and source. It also
  proves the `algorithm_enable_flags_18_t` bit 14 guess: `engine_retarder_service_brake_activate_enable`. The chain's
  plates are rewritten.
- **Stage B (bd059da, types):** `ENGINE_RETARDER_COMMAND_SOURCE` and `ENGINE_RETARDER_ALLOWED_STATE` from their e2m
  value lists, and `J1939_CONTROL_DEVICE` on the retarder's device word.
- **Stage C (833d573, types):** the `EB_Brake_Type` bitfield (exhaust / VG brake), and the 0x40a35c dword split.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 16: stage A is EQUIVALENT (109 names)",
     "- [x] Round 17: stage A is EQUIVALENT (30 names); stage B's enum proof shows 0 functions differing beyond the "
     "substitutions; stage C's type diff is reviewed with a mask normalizer.\n"
     "- [x] Round 16: stage A is EQUIVALENT (109 names)")
edit(pr, "- **Open after round 16:**\n  - the engine retarder family, the cruise PID's Q16 integrator type,",
     "- **Open after round 17:**\n  - the cruise PID's Q16 integrator type,")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 17" not in t:
    t += """

## Round 17: the engine retarder request chain (`session_folder/round17/`)

- **The records:** `blocks.txt` (e2m_block_addresses.py on 1070 / 1071 / 1192), `check*_out.txt`, `width_r17a.txt`.
- **Stage A:** `worklist_r17a.py` (through apply_hand_worklist.py), `apply_r17a_plates.py` (the chain's plates),
  `retired_prose_r17.py` / `fix_retired_prose_r17.py` (the old words in current comments).
- **Stage B:** `apply_r17b_enums.py`. **Stage C:** `apply_r17c.py` and the proof helper `normalize_r17c.py`.
  **Closing:** `apply_r17_closing.py`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 17" not in lines[i]:
    assert lines[i].endswith("user's decisions) - open: the engine retarder family"), lines[i][-60:]
    lines[i] += ("; round 17: the engine retarder request chain from e2m 1070 / 1071 / 1192 (the override / "
                 "non-override commands, ENGINE_RETARDER_COMMAND_SOURCE / _ALLOWED_STATE, the brake type bitfield, "
                 "the proven service brake activate enable bit) - open: the Q16 integrator type, the task 046 leads")
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
