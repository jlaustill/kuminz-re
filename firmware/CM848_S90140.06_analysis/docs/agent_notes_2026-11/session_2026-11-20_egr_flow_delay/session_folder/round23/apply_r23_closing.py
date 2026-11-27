"""Round 23 closing: the round 23 sections of task 046, the PR body, the session README and the todo line.
Idempotent. usage: apply_r23_closing.py <repo> <pr_body.md>"""
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


TASK = """## Done, round 23 (2026-11-22, same PR; the relayed "keep going" again): the ambient module and the source enum

Scripts are in `session_folder/round23/`.
- **Stage A (0787531, label-only):**
  - The ambient conditions module (e2m 1921 / 1977, `cm848_calculateAmbientAndCompressorInletConditions`):
    - three `boost_*` words are the ambient air flow filter, its output, and the ambient air temperature estimate;
    - the unnamed filters, coefficients, tables and caches are named from the parameter ID table (1977 +2 / +A, 197A /
      197B the compressor inlet pressure drop, 197C / 1A0E / 197D the compressor inlet temperature rise);
    - the initializer is `cm848_initializeAmbientConditions`.
    This resolves round 19's lead on `cm848_initialization_step_3`'s filter.
  - The PGN 65269 payload: all five fields, from the local J1939 database (SPN 108 / 170 / 171 / 172 / 79). Only
    barometric pressure and ambient air temperature are built; the other three stay 'not available'. The ambient air
    temperature byte comes from the ambient temperature sensor, not the ambient module's estimate.
- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more `*_source` words. `source_scan.py` matches each
  word's e2m value list (via the parameter ID table) against every literal the code uses, which resolves round 19's
  reach lead. `egr_flow_source` (PRIMARY / BACKUP only) is included; the fan and fuel metering "sources" use other
  value sets.
- **Dead end:** the general engine protection's other reason bits. `DAT_0040a43c` / `_43e` are read but never written
  (two `lhz`, even in permissive mode), `DAT_003fbd50` / `_54` are only zeroed, and the e2m names only the state and
  its cap.
- **Round 23 leads:**
  - `algorithm_enable_flags_29_cal` bits 0 / 1 (the e2m's 'SS Ambient Advance / Derate') gate the ambient air
    temperature broadcast, a hint at what 'SS' is.
  - e2m 1977 +0 `C_AMB_Amb_Pressure_Fil_Cnst` (0x3ff074) has no row; check its users.

## Leads (not in this PR)
"""
t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
t = open(path(t46)).read()
if "## Done, round 23" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 23 (the relayed "keep going" again): the ambient module and the source enum.**
- **Stage A (0787531, label-only):** the ambient conditions module's filters, coefficients, tables, caches and
  initializer (e2m 1977 / 197A-197D / 1A0E), and the PGN 65269 payload's five fields.
- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more source words (each e2m value list against the code's
  literals).

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 22: stages A and B are EQUIVALENT",
     "- [x] Round 23: stage A is EQUIVALENT (20 names); stage B's enum proof shows only the substitutions.\n"
     "- [x] Round 22: stages A and B are EQUIVALENT")
edit(pr, "- **Open after round 22:**\n", "- **Open after round 23:**\n")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 23" not in t:
    t += """

## Round 23: the ambient module and the source enum (`session_folder/round23/`)

- **Stage A:** `worklist_r23a.py`, `apply_r23a2.py` (the unnamed and new rows). **Stage B:** `source_scan.py` (each
  `*_source` word's e2m value list against the code's literals), `apply_r23b.py`. **Closing:** `apply_r23_closing.py`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 23" not in lines[i]:
    tail = " - open: the task 046 leads"
    assert lines[i].endswith(tail), lines[i][-60:]
    lines[i] = lines[i][:-len(tail)] + ("; round 23: the ambient module and the PGN 65269 payload named, "
                                        "SENSOR_VALUE_SOURCE on ten more source words" + tail)
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
