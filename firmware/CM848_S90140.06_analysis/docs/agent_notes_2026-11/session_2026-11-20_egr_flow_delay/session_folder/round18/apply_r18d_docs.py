"""Round 18 stage D docs: task 046's round 18 section and the PR body after the review. Idempotent.
usage: apply_r18d_docs.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(p, old, new):
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (p[-30:], old[:60], t.count(old))
    open(p, "w").write(t.replace(old, new))


t46 = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(t46, "    +4 `SOI_State`), each checked at its store: CRANK, USER_OVERRIDE, ENGINE_STOPPED, MISFIRE_LIMIT,\n"
          "    COMBUSTION_MANAGER, EXTENDED_IDLE, COOLANT_OVERHEAT_DERATE, plus the intermediate FOUR_DIMENSIONAL_TIMING /\n"
          "    USER_COMMANDED_TIMING / COMBUSTION_REFERENCE.",
     "    +4 `SOI_State`), checked at the stores: CRANK, USER_OVERRIDE, MISFIRE_LIMIT, COMBUSTION_MANAGER,\n"
     "    EXTENDED_IDLE, COOLANT_OVERHEAT_DERATE, plus the intermediate FOUR_DIMENSIONAL_TIMING / USER_COMMANDED_TIMING.\n"
     "    Two rest on more than a store: 8 is only the power-up value (stage D: `POWER_UP`, as the dump with the engine\n"
     "    stopped reads 20), and 25 `COMBUSTION_REFERENCE` is the dump's value, but its storing function is a lead.")
edit(t46, "- **Round 18 leads:**\n",
     "- **Stage D (label-only, after the review):** one prefix rule for the main timing. `main_injection_timing*` names\n"
     "  the final value and what describes it (its copies, selection and source; 9 rows), and `injection_timing_main_*`\n"
     "  (60 rows) names its inputs, components and limits. So the misfire limit and the extended idle minimum are\n"
     "  `injection_timing_main_*`, with the misfire limit's table and cache (were `injection_timing_demand_floor_*`).\n"
     "  The plates of `cm848_calculateMainInjectionTiming` / `cm848_calculatePilotInjectionTimingOffset` lost the retired\n"
     "  'floor / governor-limit minimum / working minimum / cold-start map' words.\n"
     "- **Round 18 leads:**\n"
     "  - **The cranking timing map** is e2m 105E +4 `Crank_4D_Timing`, but its tables keep\n"
     "    `injection_timing_main_cold_start_*`.\n"
     "  - **Two more 'row count' caches:** `governor_adjustment_input_table_row_count` (0x3fb9da) and\n"
     "    `boost_fuel_rpm_blend_table_row_count` (0x3fb9f2) look like lookup caches named as table dimensions.\n")
edit(pr, "- **Stage C (99dd717, types):** the two timing enums, the `algorithm_enable_flags_4_t` bitfield, and five lookup\n"
         "  caches (the misread `dual_axis_table_dims_t` struct is gone).",
     "- **Stage C (99dd717, types):** the two timing enums, the `algorithm_enable_flags_4_t` bitfield, and five lookup\n"
     "  caches (the misread `dual_axis_table_dims_t` struct is gone).\n"
     "- **Stage D (label-only, after the review):** one prefix rule for the main timing (`injection_timing_main_*` for\n"
     "  its inputs and limits), the misfire limit's table, the power-up timing source, and the plates' retired words.")
edit(pr, "- [x] Round 18: stage B is EQUIVALENT (30 names); stages A and C are type diffs reviewed line by line (only the "
         "intended effects).",
     "- [x] Round 18: stages B and D are EQUIVALENT; stage A's cast-normalized diff and stage C's diff show only the "
     "intended effects.")
print("docs updated")
