"""Round 21 closing, after the review: stage E, stage D's positive control and the review's leads in task 046, the PR
body, the README and the todo line. Idempotent. usage: apply_r21_closing2.py <repo> <pr_body.md>"""
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
edit(t46, "  unknown; such a field used to become byte without a word. CM550 and CM848 build identical before and after.\n",
     "  unknown; such a field used to become byte without a word. CM550 and CM848 build identical before and after. A\n"
     "  scratch positive control (reverted) confirmed both paths: `i16` on a field rendered unchanged, and a made-up type\n"
     "  printed the warning (twice: the importer looks types up in two passes).\n"
     "- **Stage E (f6cecc2, types, after the review):** configuration +0x0A / +0x0C / +0x10 / +0x12 are short and the three\n"
     "  threshold pointers short*. Every load is `lha`: directly in the shutdown function and the threshold test, and\n"
     "  through the pointers. The e2m's NU loses to the loads. The input pointer stays `word*`, because it is read\n"
     "  unsigned for the switch masks and signed for the compares. The (short) casts on those fields are gone.\n")
edit(t46, "  - e2m 10DA's engine overspeed error log (+0 / +78 / +7A).\n",
     "  - e2m 10DA's engine overspeed error log (+0 / +78 / +7A).\n"
     "  - The module's init chain still has guessed names. `cm848_completeEngineStartSequence` only clears the engine\n"
     "    protection shutdown state; `cm848_initSensorChannelDataStructures` and `exception_resetProtectionModeState` are\n"
     "    part of the module too.\n"
     "  - `function_definitions.csv` `int` parameters render as `dword`. Check the prototype importer for the same kind\n"
     "    of silent type mapping as the struct importer had.\n")
edit(pr, "- **Stage D (cc49e74, tooling):** `ApplyStructures.java` maps `i16` / `sword` and warns on an unknown field type.\n",
     "- **Stage D (cc49e74, tooling):** `ApplyStructures.java` maps `i16` / `sword` and warns on an unknown field type\n"
     "  (a scratch positive control confirmed both).\n"
     "- **Stage E (f6cecc2, types, review):** the engine protection thresholds are `short` / `short*`: every load is `lha`.\n")
edit(pr, "stage C is EQUIVALENT; stage D builds CM550 and CM848 identical before and after.",
     "stage C is EQUIVALENT; stage D builds CM550 and CM848 identical before and after, and its positive control shows "
     "both new paths; stage E's gate passes (the five readers, no casts left).")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
edit(README, "`patch_apply_structures.py` (mind the file's CRLF line endings). **Closing:**\n  `apply_r21_closing.py`.",
     "`patch_apply_structures.py` (mind the file's CRLF line endings); its positive control's log is\n"
     "  `build_r21_control.log` in the large-files tarball. **Stage E:** `apply_r21e.py` + `prove_r21e.py`. **Closing:**\n"
     "  `apply_r21_closing.py`, `apply_r21_closing2.py`.")
edit("work/todo.md", "11 functions + 9 words named, the struct importer's i16 gap)",
     "11 functions + 9 words named, the signed thresholds, the struct importer's i16 gap)")
print("closing 2 edits applied")
