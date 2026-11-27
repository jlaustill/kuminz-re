"""Round 22 closing, after the review: stage B, the scanner note (two modes) and a leads list in task 046, the PR
body, the README and the todo line. Idempotent. usage: apply_r22_closing2.py <repo> <pr_body.md> <stage B hash>"""
import os
import sys

repo, pr, b_hash = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


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
edit(t46, "- **Closed leads:**\n  - `function_definitions.csv`'s `int`",
     f"- **Stage B ({b_hash}, label-only + comments, after the review):**\n"
     "  - `cm848_isEngineProtectionInputMoreExtreme` (was `protection_condition_eval`) and\n"
     "    `cm848_interpolateEngineProtectionSeverity` (was `threshold_value_interpolate`), now read rather than inferred.\n"
     "  - The second derate cache is `fault_derate_fuel_limit_by_engine_speed_cached_axis_offset_2`, by the cache rule\n"
     "    (the table base + `_2`, as with the retarder torque caches).\n"
     "  - Two of stage A's comments went beyond the code read, and are corrected:\n"
     "    - the torque curve plate: only the clamp-mask path keeps the minimum; the priority path sets the five fuelings;\n"
     "    - the configuration flags' 0x4 / 0x8 / 0xc / 0x40: 0x4 also tracks the maximum, 0x8 the minimum, and 0x40\n"
     "      also picks the fueling severity in the fault derate fuel limit.\n"
     "  - `hpcr_initializeEngineProtection` is called only from `cm848_applicationMain`, so the \"boot / restart\" plates\n"
     "    hold.\n"
     "- **Closed leads:**\n  - `function_definitions.csv`'s `int`")
edit(t46, "- **Methods:** the scratch raw scanner (`raw_addr_scan.py`) accepted any `lis` of the base register in its 8-word\n"
     "  window, not the nearest one, so it reported false hits (0x51f884 reads 0x40bd4e, not 0x3fbd4e). It never hid one.\n"
     "  Fixed in `session_folder/round22/`; the round 19 control and the ANC range give the same counts.\n",
     "- **Methods:** the scratch raw scanner (`raw_addr_scan.py`) accepted any `lis` of the base register in its 8-word\n"
     "  window, not the nearest one, so it reported false hits (0x51f884 reads 0x40bd4e, not 0x3fbd4e). The round 22\n"
     "  copy has two modes:\n"
     "  - the default: the nearest `lis` decides, for counting real accesses;\n"
     "  - `--permissive`: the old rule. It over-reports, but it cannot miss an access whose base comes from two paths\n"
     "    with different `lis` values, so it is the one for \"no access\" claims.\n"
     "  Both give the round 19 control's 3 and the ANC range's 0.\n"
     "- **Round 22 leads:**\n"
     "  - `DAT_0040a78c` only ever gets 0; a name needs a reader.\n"
     "  - The words next to the module that belong to other code: `DAT_003fbd20`-`26` (the emission level cap, the timer\n"
     "    registers, the not-to-exceed zone) and `DAT_003fbd50`-`58` (`cm848_updateGeneralEngineProtection`).\n")
edit(pr, "  fault derate's J1939 torque curve adjustment (PGN 65251), two new rows, and the configuration flags documented.\n",
     "  fault derate's J1939 torque curve adjustment (PGN 65251), two new rows, and the configuration flags documented.\n"
     f"- **Stage B ({b_hash}, label-only, review):** the two helpers it had only seen as calls, the second derate cache "
     "by the cache rule, and two comments corrected.\n")
edit(pr, "- [x] Round 22: stage A is EQUIVALENT (12 names).",
     "- [x] Round 22: stages A and B are EQUIVALENT (12 and 3 names).")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
edit(README, "  **Closing:** `apply_r22_closing.py`. `raw_addr_scan.py` is the fixed scanner (the nearest `lis` decides).",
     "  **Stage B:** `worklist_r22b.py`, `apply_r22b2.py` (the two comments). **Closing:** `apply_r22_closing.py`,\n"
     "  `apply_r22_closing2.py`. `raw_addr_scan.py` is the fixed scanner: the nearest `lis` decides, and `--permissive`\n"
     "  keeps the old rule for \"no access\" claims.")
print("closing 2 edits applied")
