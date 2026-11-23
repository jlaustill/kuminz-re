"""Round 46 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r46_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof A> <proof B>"""
import os
import re
import sys

repo, pr, ha, hb, count, pa, pb = os.path.abspath(sys.argv[1]), *sys.argv[2:8]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 46 (2026-11-22, same PR): the gap sweep's remainder - the warning chime, rock cycle torque management

A peer relay started the round; the scripts are in `session_folder/round46/`.
- **Method:** `gap_leads.py` ranks the undecided perfect-width gaps by meaning, and lists unnamed data the `.cpp`
  reads inside gaps. Every record was read in full; a 70-character cut had hidden two descriptions.
- **Stage A ({ha}, labels):**
  - 8A7F (tiled) is the oil pressure gauge state.
    - OPG_Check_Gauges, OPG_Error_Count, OPG_Pressure ("Oil_Pressure - Ambient_Air_Pressure", the code) and
      OPG_Threshold_Value are cited.
    - `oil_pressure_model_unfiltered` keeps its name: the table (8A82 OPG_Threshold_Table) feeds only the
      switch-only pressure model here.
    - +2 OPG_Chime: `low_oil_pressure_derate_flag` (and `_previous`) -> `low_oil_pressure_chime_flag`. Its only
      consumer starts the warning chime; nothing derates on it.
  - 8B2D (field match, 5 / 5 records) holds the warning chime counts and the chime duration.
    - The countdown is a count x Cluster_Warning_Chime_Duration x 5 / 10 passes. The request goes out as PCI header
      0x53, byte 1, bit 5.
    - `engine_warning_alert_*` -> `warning_chime_count_*` / `warning_chime_duration` / `warning_chime_countdown` /
      `warning_chime_request_flag` (+ `_previous`).
  - 8A7C (tiled) is the transmission state; +2 / +4 / +6 are cited.
    - +0 Jcomm_Torque_Mgmt_Request: `fuel_demand_timing_enable_flag` -> `tsc1_lost_management_active_flag`.
    - It is set on a TSC1 timing fault, with fault 356 Jcomm_TSC_Lost_Fault. Its two consumers ramp the TSC1
      torque limit and require torque management.
    - **The dump has it at 1 with fault 356 detected:** the truck had flagged TSC1 as lost.
  - **Proof:** {pa}
- **Stage B ({hb}, labels, a row, functions):** the `park_neutral_exit_*` family is rock cycle torque management.
  - Its enable bit was already `rock_cycle_torque_management_enable`.
  - 8C49 (in the dumped table) RE_RCTM_* holds the window's enabling calibrations, 8C4A / 8C4B its transmission
    temperature dwell table, and 8A7C +8 / +A the flag and dwell timer.
  - 8C2A (a field match, 6 / 6) TC_Rock_Cycle_* holds the speed limit's calibrations: 850 rpm to the high speed
    governor, the throttle window, the maximum road speed, the ramp rate and the active-too-long time.
  - `park_neutral_exit_` -> `rock_cycle_` with every other word kept: 20 globals and 3 functions.
  - A new row: `rock_cycle_engine_speed_limit_maximum_output_shaft_speed` (8C49 +6).
  - The five state rows without a record are named by code membership, and say so. The plates keep the park / neutral
    exit trigger.
  - **Proof:** {pb}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - `engine_speed_limit_*` arbitration: source 15 is now `engine_speed_limit_rock_cycle`. The other sources may sit in
    e2m blocks too.
  - Unread gaps with unnamed reads: the thermostat monitor gap (0x409fb8, 8 addresses), ROM 0x642ce (9 addresses),
    and 0x4086c8 (`DAT_004086ca` / `DAT_004086ce`, read by the TSC1 function).
  - The remaining small perfect-width gaps (2-4 bytes, 1-2 rows) have no meaning match.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 46.**\n"
     f"- **Stage A ({ha}, labels):** the warning chime (e2m 8B2D: `warning_chime_*`, was `engine_warning_alert_*`), the oil\n"
     "  pressure gauge state (8A7F; `low_oil_pressure_chime_flag`, was `…_derate_flag`) and the TSC1-lost backup\n"
     "  powertrain protection flag (8A7C; `tsc1_lost_management_active_flag`, was `fuel_demand_timing_enable_flag`).\n"
     f"- **Stage B ({hb}, labels, a row, functions):** the `park_neutral_exit_*` family is rock cycle torque management\n"
     "  (e2m 8C2A TC_Rock_Cycle_* / 8C49-8C4B RE_RCTM_*). It becomes `rock_cycle_*`: 20 globals, 3 functions, 1 new row.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 45:", f"- [x] Round 46: stage A {pa} Stage B {pb}\n- [x] Round 45:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 46: the warning chime, rock cycle torque management (`session_folder/round46/`)\n\n"
       "- `gap_leads.py` (+ `gap_leads.txt`), `placements_*.txt`. **Stage A:** `apply_r46a.py`, `map_r46a.csv`. "
       "**Stage B:** `apply_r46b.py`, `map_r46b*.csv`, `apply_r46b_struct_comment.py`. **Closing:** "
       "`apply_r46_closing.py`, `update_large_tar_r46.sh`.\n")
if "## Round 46:" not in t:
    i = t.index("## Round 45:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 45: the table gap sweep, six more e2m blocks - open: the task 046 leads",
     "round 45: the table gap sweep, six more e2m blocks; round 46: the warning chime, rock cycle torque management - "
     "open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "width match alone misleads - check meaning); task 046 leads"
new = ("width match alone misleads - check meaning) + round 46 (warning chime e2m 8B2D, TSC1-lost flag set in the dump, "
       "park_neutral_exit_* = rock cycle torque management -> rock_cycle_*); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 46 (2026-11-22): {ha} / {hb}. Read e2m descriptions in full (show_placement.py cuts at 70 chars). "
        "A dumped-table block can still be uncited (8C49 RE_RCTM_*): resolve a family's rows with "
        "e2m_block_addresses.py --address before trusting their code-only names. On the user's truck the dump has "
        "tsc1_lost_management_active_flag = 1 with fault 356 Jcomm_TSC_Lost_Fault detected.\n")
if "Round 46 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 46 closing applied")
