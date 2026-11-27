"""Round 18 closing: the leads round 18 resolved, and the round 18 sections of task 046, the PR body, the session
README and the todo line. Idempotent. usage: apply_r18_closing.py <repo> <pr_body.md>"""
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
edit(t46, "      renders with an underscore.\n", "      renders with an underscore. (Done in round 18: dwords.)\n")
edit(t46, "    - The 4D fueling caches are 4 bytes but typed `word`.\n",
     "    - The 4D fueling caches are 4 bytes but typed `word`. (Done in round 18: word[2].)\n")
edit(t46, "    the 125C enable first.\n",
     "    the 125C enable first. (Done in round 18: main_injection_timing_selection 2 / 3, and the enable is "
     "algorithm_enable_flags_4_cal bit 8.)\n")
edit(t46, "  - **`Main_Cold_Advance_Select`** (8085 +2: 0 add / 1 max wins / 2 min wins) is an enum candidate.\n",
     "  - **`Main_Cold_Advance_Select`** (8085 +2: 0 add / 1 max wins / 2 min wins) is an enum candidate. (Done in round "
     "18: INJECTION_TIMING_COMBINATION_MODE.)\n")
edit(t46, "    stores; decide by a pilot.\n",
     "    stores; decide by a pilot. (Done in round 18: the pilot printed casts, not pieces, so it is a "
     "q16_fixed_point_t.)\n")
TASK = """## Done, round 18 (2026-11-21, same PR; the relayed "keep going" again): types and the main injection timing selection

Scripts are in `session_folder/round18/`.
- **Stage A (cc6189f, types): three type leads.**
  - `cruise_pid_integrator_q16` as `q16_fixed_point_t`. A pilot build showed the dword integration lines as casts, not
    pieces, so the 12 integer-half lines read `.integer_part` and the preset's fraction clear `.fractional_part`.
  - The AFC slew rates (e2m 11D5 +C / +10 / +14) as the dwords `air_fuel_control_fueling_slew_rate_1` / `_2` / `_3`.
  - The 4D fueling caches as `word[2]`. Their second words had rows of their own, which failed inside the arrays and
    are removed.
  - Underscore warnings 24 -> 22.
- **Stage B (3d714fe, label-only): the round 15 'user commanded timing' lead.**
  - **`main_injection_timing_selection`** (was `injection_delivery_mode`; e2m 8085 +0): 0 no change, 1 calculated, 2
    the user commanded timing (e2m 125C +2, was `injection_timing_offset_cal`), 3 calculated plus the user timing.
  - **The 4D timing** (103B +0 `Four_D_Timing`, was `injection_timing_offset_map_output`) and its maps a / b. The user
    timing replaces it while `algorithm_enable_flags_4_cal` bit 8 is set. That word was `engine_mode_control_flags`;
    it is EEPROM 0x122, AENBLFLG word 4.
  - **The timing source members** follow the e2m value labels of 103B +8 `Final_Timing_State` (hex keys, shared with
    +4 `SOI_State`), each checked at its store: CRANK, USER_OVERRIDE, ENGINE_STOPPED, MISFIRE_LIMIT,
    COMBUSTION_MANAGER, EXTENDED_IDLE, COOLANT_OVERHEAT_DERATE, plus the intermediate FOUR_DIMENSIONAL_TIMING /
    USER_COMMANDED_TIMING / COMBUSTION_REFERENCE. They also name the limit words: the misfire timing limit (8A3D),
    the extended idle minimum (8085 +4) and the coolant overheat derate's minimum timing family.
- **Stage C (99dd717, types):** `MAIN_INJECTION_TIMING_SELECTION` and `INJECTION_TIMING_COMBINATION_MODE`, the
  `algorithm_enable_flags_4_t` bitfield (the user commanded fueling / timing enables), and five 2-D lookup caches as
  `word[2]`. Two of the caches were the `dual_axis_table_dims_t` instances, whose 'row / column counts' were the
  cached offsets, so that struct is gone.
- **Round 18 leads:**
  - **`cm848_storeFuelDemandPreviousValues`** copies the off-nominal compensated reference (1711 +8 `CBO_SOI_Ref`)
    into `ANC_SOI` (10A4 +14) and two kernel-window words (0x3fa700 / 0x3fa702), with source 25 (e2m `CBR_SOI`). The
    ANC stage (e2m 10A4) has no names yet, and the function name is wrong.
  - **`fuel_demand_offset_correction`** is added to the altitude derate limit (`protection_feature_flags` bit 0x80)
    and to the retarder's idle / PTO fueling limits; its source is unread.

## Leads (not in this PR)
"""
t = open(path(t46)).read()
if "## Done, round 18" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 18 (the relayed "keep going" again): types and the main injection timing selection.**
- **Stage A (cc6189f, types):** the cruise Q16 integrator as `q16_fixed_point_t`, the AFC slew rates as dwords, and
  the 4D fueling caches as `word[2]` (underscore warnings 24 -> 22).
- **Stage B (3d714fe, label-only):** `main_injection_timing_selection`, the user commanded and 4D timing, the AENBLFLG
  word 4, and the timing source members from the 103B value labels with their limit words.
- **Stage C (99dd717, types):** the two timing enums, the `algorithm_enable_flags_4_t` bitfield, and five lookup
  caches (the misread `dual_axis_table_dims_t` struct is gone).

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 17: stage A is EQUIVALENT (30 name",
     "- [x] Round 18: stage B is EQUIVALENT (30 names); stages A and C are type diffs reviewed line by line (only the "
     "intended effects).\n"
     "- [x] Round 17: stage A is EQUIVALENT (30 name")
edit(pr, "- **Open after round 17:**\n  - the cruise PID's Q16 integrator type, the droop word at 0x40aedc (task 046);",
     "- **Open after round 18:**\n  - the ANC timing stage (e2m 10A4), the droop word at 0x40aedc (task 046);")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 18" not in t:
    t += """

## Round 18: types and the main injection timing selection (`session_folder/round18/`)

- **Stage A:** `apply_r18a.py` (after the q16 pilot build). **Stage B:** `worklist_r18b.py` / `worklist_r18b2.py`
  (through apply_hand_worklist.py) and `apply_r18b_enums.py`. **Stage C:** `apply_r18c.py`. **Closing:**
  `fix_retired_prose_r18.py`, `apply_r18_closing.py`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 18" not in lines[i]:
    assert lines[i].endswith("open: the Q16 integrator type, the task 046 leads"), lines[i][-60:]
    lines[i] += ("; round 18: the cruise Q16 integrator / AFC slew rate / lookup cache types, the main injection timing "
                 "selection with the user commanded and 4D timing, the timing source members from the e2m value labels - "
                 "open: the ANC timing stage, the task 046 leads")
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
