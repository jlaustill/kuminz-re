"""Round 19 closing: the round 18 leads round 19 resolved, and the round 19 sections of task 046, the PR body, the
session README and the todo line. Idempotent. usage: apply_r19_closing.py <repo> <pr_body.md>"""
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
edit(t46, "    `injection_timing_main_cold_start_*`.\n",
     "    `injection_timing_main_cold_start_*`. (Done in round 19: the map is e2m 8091-8093 `Main_SOI_Cranking_*`; 105E +4\n"
     "    is the crank routine's own 4D timing output, which only its initializer writes.)\n")
edit(t46, "    `boost_fuel_rpm_blend_table_row_count` (0x3fb9f2) look like lookup caches named as table dimensions.\n",
     "    `boost_fuel_rpm_blend_table_row_count` (0x3fb9f2) look like lookup caches named as table dimensions. (Done in\n"
     "    round 19.)\n")
edit(t46, "    ANC stage (e2m 10A4) has no names yet, and the function name is wrong.\n",
     "    ANC stage (e2m 10A4) has no names yet, and the function name is wrong. (Done in round 19.)\n")
TASK = """## Done, round 19 (2026-11-21, same PR; the relayed "keep going" again): tables, sources and the ANC pass-through

Scripts are in `session_folder/round19/`.
- **Stage A (2327679, label-only):** tables named by the parameter ID table.
  - The main timing cranking map is e2m 8091-8093 `Main_SOI_Cranking_*` (was `injection_timing_main_cold_start_*`).
  - The ambient humidity table is e2m 1A98-1A9A `C_AMB_Humidity_*` (was `boost_fuel_rpm_blend_scale_*`), the table
    behind `ambient_relative_humidity`.
  - The altitude lookup's cache was named as a table dimension.
- **Stage B (e3bc815, types):**
  - `SENSOR_VALUE_SOURCE` (PRIMARY / BACKUP / DEFAULT) goes on eleven source words. Eleven e2m `*_Source` records
    share the value list '0=PRIMARY, 1=BACKUP, 2=DEFAULT', and the code stores and compares only those values.
    `barometric_altitude_source` (1921 +12) gets a row.
  - The humidity table's cache is `word[2]`.
- **Stage C (label-only): the ANC pass-through.**
  - The ANC timing stage (e2m 10A4, enables in 106B +8) is compiled out: its RAM words have no access.
  - `cm848_passCompensatedTimingToCombustionLimits` (was `cm848_storeFuelDemandPreviousValues`) copies the
    off-nominal compensated reference into `injection_timing_combustion_limits_input`. That word was
    `injection_timing_compensated_reference_previous`; it is 10A4 +14 `ANC_SOI`, 'input to CBL'.
  - The function also sets source 25 (COMBUSTION_REFERENCE). The combustion limits step reads the word.
  - 'ANC' is not spelled out in the e2m, so the names use the role.
- **Round 19 leads:**
  - **The source enum's reach:** other `*_Source` words may use the same 0 / 1 / 2 coding without the e2m list (for
    example `egr_flow_source`). Check each one's stores before typing it.

## Leads (not in this PR)
"""
t = open(path(t46)).read()
if "## Done, round 19" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 19 (the relayed "keep going" again): tables, sources and the ANC pass-through.**
- **Stage A (2327679, label-only):** the main timing cranking map (e2m 8091-8093), the ambient humidity table (1A98-1A9A)
  and the altitude cache, from the parameter ID table.
- **Stage B (e3bc815, types):** `SENSOR_VALUE_SOURCE` on the eleven words whose e2m records share the PRIMARY / BACKUP /
  DEFAULT list, and the humidity cache as `word[2]`.
- **Stage C (label-only):** the compiled-out ANC stage's pass-through into the combustion limits input.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 18: stages B and D are EQUIVALENT;",
     "- [x] Round 19: stages A and C are EQUIVALENT; stage B's enum proof shows only the substitutions (plus the cache's "
     "two users).\n"
     "- [x] Round 18: stages B and D are EQUIVALENT;")
edit(pr, "- **Open after round 18:**\n  - the ANC timing stage (e2m 10A4), the droop word at 0x40aedc (task 046);",
     "- **Open after round 19:**\n  - the droop word at 0x40aedc and the task 046 leads;")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 19" not in t:
    t += """

## Round 19: tables, sources and the ANC pass-through (`session_folder/round19/`)

- **Stage A:** `worklist_r19a.py`. **Stage B:** `apply_r19b.py`, with `source_values.py` (the values each source word
  stores and compares). **Stage C:** `worklist_r19c.py`. **Closing:** `apply_r19_closing.py`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 19" not in lines[i]:
    assert lines[i].endswith("open: the ANC timing stage, the task 046 leads"), lines[i][-60:]
    lines[i] += ("; round 19: the main timing cranking map and the ambient humidity table from the parameter ID table, "
                 "SENSOR_VALUE_SOURCE on eleven source words, the ANC pass-through - open: the task 046 leads")
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
