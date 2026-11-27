"""Round 57 closing: task 046, PR body, README, todo, memory; and round 56's wording fix (its "the last protection_*
names" was true of function names only: 17 protection_* globals were left). No CLAUDE.md edit. Idempotent.
usage: apply_r57_closing.py <repo> <pr_body.md> <hash A> <hash B> <count> <proof> <unprefixed left>"""
import os
import re
import sys

repo, pr, ha, hb, count, proof, left = os.path.abspath(sys.argv[1]), *sys.argv[2:8]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 57 (2026-11-23, same PR): the cruise cluster, the cruise N/V ratio, two warning chime sources

A peer relay started the round; the scripts are in `session_folder/round57/`.
- **Stage A ({ha}): the cruise cluster at 0x511ea8-0x513980, read function by function.**
  - 10 unprefixed legacy names, plus `cm848_integrateCruiseRpmRatioChange` for the vocabulary.
  - Three were wrong-domain:
    - `governor_cruise_dualCalc_dispatch` runs the coolant overheat derate monitors
      (`cm848_runCoolantOverheatDerateMonitors`).
    - `engine_coolantTemp_delta_calc` is e2m 8A72 +0 CT_Derate_Temp_Error
      (`cm848_calculateCoolantOverheatTemperatureError`).
    - `fuel_demand_timing_initialize` initializes the TSC1 lost management and the rock cycle cache
      (`cm848_initializeRockCycleAndTsc1LostManagement`).
  - **The five state getters** return `CRUISE_CONTROL_STATE` (no parameters, r3 returns):
    `cm848_selectBaseCruiseState`, `cm848_selectDeniedCruiseState` and `cm848_selectCruiseStateFor{{Set,Resume,Coast}}Switch`.
    - They render the states by name and drop 6 casts.
    - The caller re-renders with renumbered locals and no cast added.
  - **The e2m 8A0E / 8A0F "N_V" ratio family** (table-resolved) is now `cruise_engine_to_vehicle_speed_ratio_*`
    (was `cruise_rpm_ratio_*`): 12 rows, including the filter state and its coefficient (two type-only rows).
- **Stage B ({hb}): two of the five warning chime sources in `cm848_updateEngineWarningFlags`.**
  - `fuel_pressure_fault_active_flag` (was `protection_fault_latch_flag`): any of the P1221 / P1222 / P1223 rail
    pressure and fuel metering faults; PCI 0x35 bit 6.
  - `air_conditioning_coolant_off_flag` (was `protection_coolant_classb_active_flag`): the A/C coolant-off condition
    of the DR truck A/C clutch control, chimed by e2m 8B2D +6 AC_Coolant_Off_Chime_Count.
  - Their copy / previous words and chime counts: 7 rows.
  - The 11.45 e2m's 8A0F +C / +E / +10 records (cruise switch history, a transmission cutout) do not match the code
    at those addresses, so 8A0F's 11.46 layout drifts from +C on.
- **Proof:** {proof}
- **Round 56's wording, corrected:** "the last `protection_*` names" was true of function names only; 17
  `protection_*` globals were left, and stage B renamed 5 of them.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - {left} unprefixed CM848-only functions remain.
  - 12 `protection_*` globals remain: `protection_diag_state_a` / `_b` / `_c`,
    `protection_event_output_polarity_bits_cal` / `_line_cal`, `protection_status_flags_b`, `protection_crank_event_counter`,
    the `protection_group29_*` pair, `protection_rpm_correction_cached_axis_offsets`, and two pad fields.
  - 8A0F +A Filtered_Cruise_N_V_Ratio (0x40b20e) has no code use under its address.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "the discrete output overrides replace the last protection_* names",
     "the discrete output overrides replace the last protection_* function names")
edit(pr, "the last `protection_*` names are the discrete output overrides",
     "the last `protection_*` function names are the discrete output overrides")
edit(pr, "\n## Test plan\n",
     "**Round 57.**\n"
     f"- **Stage A ({ha}):** the cruise cluster, 11 functions named from their code. Three names were wrong-domain:\n"
     "  two coolant overheat derate steps and the TSC1 lost / rock cycle initializer. `CRUISE_CONTROL_STATE` returns\n"
     "  on the five state getters, and the e2m 8A0E / 8A0F N/V ratio family is now\n"
     "  `cruise_engine_to_vehicle_speed_ratio_*` (12 rows).\n"
     f"- **Stage B ({hb}):** two warning chime sources: `fuel_pressure_fault_active_flag` (P1221-P1223) and\n"
     "  `air_conditioning_coolant_off_flag` (e2m 8B2D +6), 7 rows.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 56:", f"- [x] Round 57: {proof}\n- [x] Round 56:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 57: the cruise cluster, the N/V ratio, two warning chime sources (`session_folder/round57/`)\n\n"
       "- **Stage A:** `apply_r57a.py`, `map_r57a.csv`, `refresh_other_csvs_r57.py`. Proof: `prove_r57.sh`, "
       "`prove_return_types_r57.py`, `diff_function_r57.py`, `count_casts.py`. **Stage B:** `apply_r57b.py`, "
       "`map_r57b.csv`. **Closing:** `apply_r57_closing.py`, `update_large_tar_r57.sh`.\n")
if "## Round 57:" not in t:
    i = t.index("## Round 56:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 56: the discrete output overrides (e2m 8B5B / 8C29) - open: the task 046 leads",
     "round 56: the discrete output overrides (e2m 8B5B / 8C29); round 57: the cruise cluster, the cruise N/V ratio, "
     "two warning chime sources - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
m = m.replace("replace the last protection_* names: discrete_output_override_t x 11)",
              "replace the last protection_* function names: discrete_output_override_t x 11)")
old = "discrete_output_override_t x 11); task 046 leads"
new = ("discrete_output_override_t x 11) + round 57 (the cruise cluster: 11 functions + CRUISE_CONTROL_STATE returns, "
       "the 8A0E / 8A0F N/V ratio, 2 warning chime sources); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 57 (2026-11-23): {ha} / {hb}. The cruise cluster; a return-only prototype on a no-parameter getter "
        "is free (no call-site casts, unlike committed parameters); refresh_references.py skips enums.csv too "
        "(refresh_other_csvs_r57.py covers the other CSVs).\n")
if "Round 57 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 57 closing applied")
