"""Round 23 closing, after the review: stage C and the review's corrections in task 046, the PR body and the README.
Idempotent. usage: apply_r23_closing2.py <repo> <pr_body.md>"""
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
edit(t46, "- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more `*_source` words. `source_scan.py` matches each\n"
     "  word's e2m value list (via the parameter ID table) against every literal the code uses, which resolves round 19's\n"
     "  reach lead. `egr_flow_source` (PRIMARY / BACKUP only) is included; the fan and fuel metering \"sources\" use other\n"
     "  value sets.\n",
     "- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more `*_source` words. `source_scan.py` matches each\n"
     "  word's e2m value list (via the parameter ID table) against every literal the code uses. `egr_flow_source`\n"
     "  (PRIMARY / BACKUP only) is included; the fan and fuel metering \"sources\" use other value sets.\n"
     "- **Stage C (bc99794, types, after the review):**\n"
     "  - Stage B's scan only took `word` globals, and the ambient function still compared\n"
     "    `charge_flow_estimate_terms.fresh_air_flow_source` with a bare 2 / 1. Now `exhaust_temperature_source` (`i16`)\n"
     "    and the struct fields `charge_flow_estimate_terms_t.charge_flow_source` / `.fresh_air_flow_source` are\n"
     "    `SENSOR_VALUE_SOURCE` too.\n"
     "  - `source_scan.py` now covers every type and the struct fields, matches the value list in any order or its\n"
     "    PRIMARY / BACKUP subset, and skips the dotted alias rows. Rerun, it finds 24 words typed, 8 with other value\n"
     "    sets, and none left. This resolves round 19's reach lead.\n"
     "  - Two comments named 0x40a1a6 by its Ghidra label (`DAT_0040a1a6`, `barometric_altitude_source` since round 19)\n"
     "    and are refreshed.\n")
edit(t46, "- **Dead end:** the general engine protection's other reason bits. `DAT_0040a43c` / `_43e` are read but never written\n"
     "  (two `lhz`, even in permissive mode),",
     "- **Dead end:** the general engine protection's other reason bits. For `DAT_0040a43c` / `_43e`, no write was found\n"
     "  in the `.cpp` or by the `lis` scan (two `lhz`, even in permissive mode; a base-register store would escape the\n"
     "  scan),")
edit(t46, "  - e2m 1977 +0 `C_AMB_Amb_Pressure_Fil_Cnst` (0x3ff074) has no row; check its users.\n",
     "  - e2m 1977 +0 `C_AMB_Amb_Pressure_Fil_Cnst` (0x3ff074) has no row; check its users.\n"
     "  - The CSV comments hold 276 Ghidra labels (`DAT_` / `WORD_` / `PTR_` / `<type>_` + address) whose address now\n"
     "    has a name (`stale_ghidra_labels.py`). Some are deliberate history ('it rendered as ...'), so each hit needs a\n"
     "    review; the stale-name sweeps skip these labels by design.\n")
edit(pr, "- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more source words (each e2m value list against the code's\n"
     "  literals).\n",
     "- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more source words (each e2m value list against the code's\n"
     "  literals).\n"
     "- **Stage C (bc99794, types, review):** three more (an `i16` global and two struct fields), the scan widened to every\n"
     "  type and struct field (none left), and a stale `DAT_` label refreshed.\n")
edit(pr, "- [x] Round 23: stage A is EQUIVALENT (20 names); stage B's enum proof shows only the substitutions.",
     "- [x] Round 23: stage A is EQUIVALENT (20 names); stages B and C pass the enum proof (C differs only in a refreshed "
     "plate).")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
edit(README, "`*_source` word's e2m value list against the code's literals), `apply_r23b.py`. **Closing:** `apply_r23_closing.py`.",
     "`*_source` word's e2m value list against the code's literals; rerun it as `source_scan.py <firmware> "
     "<round19/source_values.py>`), `apply_r23b.py`. **Stage C:** `apply_r23c.py`, `stale_ghidra_labels.py` (dry run "
     "only), `source_scan_after.txt`. **Closing:** `apply_r23_closing.py`, `apply_r23_closing2.py`.")
print("closing 2 edits applied")
