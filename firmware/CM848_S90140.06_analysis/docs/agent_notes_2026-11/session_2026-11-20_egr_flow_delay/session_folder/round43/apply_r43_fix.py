"""Round 43 fix (advisor review): stage C and the review's checks recorded; the task 046 text the round 39 / 41 fix
scripts duplicated is removed (dedupe_task046.py ran first). Idempotent.
usage: apply_r43_fix.py <repo> <pr_body.md> <hash C> <commit count>"""
import os
import re
import sys

repo, pr, hc, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "  - The old plate said the output had no reader; `cm848_updateOilChangeMonitor` reads it.\n",
     "  - The old plate said the output had no reader; `cm848_updateOilChangeMonitor` reads it.\n"
     "  - This resolves round 39's `i16` clamp lead.\n"
     f"- **Stage C ({hc}, labels):** the full e2m search names this block. The dumped parameter ID table does not reach it,\n"
     "  but name, order, sign, scale and description all match the code.\n"
     "  - 8B47: EOI_Default / EOI_Hydraulic_Delay / EOI_Max_Limit / EOI_Min_Limit. 8B48: EOI.\n"
     "  - The pulse width addend is `main_injection_end_timing_hydraulic_delay` (uSEC, 0.4 per count).\n"
     "  - The dump: default -171 = -20.04 deg, maximum 512 = 60.00 deg, minimum -171, hydraulic delay 1975 = 790 us; the\n"
     "    output equals the default with the engine stopped.\n"
     "  - `main_injection_timing_copy` is 103B +2 SOI.\n"
     "  - So the `i16` types (default / maximum / minimum) meet both conditions of the signedness rule: a signed e2m record\n"
     "    and `lha` loads. Stage A had only the loads.\n")
edit(T46, "- **firmware/CLAUDE.md (factual refresh):** the MISSING sentence gives 221 (123 documentation, 77 boot-named, 10 dual-use,\n"
          "  7 unreferenced, 4 deferred).\n",
     "- **firmware/CLAUDE.md (factual refresh):** the MISSING sentence gives 221 (123 documentation, 77 boot-named, 10 dual-use,\n"
     "  7 unreferenced, 4 deferred).\n"
     "- **Checks (fix commit):** thunks 18 / 14 after the dotted junk rows; all four test scripts pass; CM550 uses none of\n"
     "  the stage A names.\n"
     "  - The round 39 / 41 fix scripts had duplicated text in this file: their edit guard let a second run re-apply an\n"
     "    edit whose new text contains the old. `dedupe_task046.py` removed the copies.\n")
edit(pr, f"- **Stage B (ef9781b, rows):** 30 junk `<name>+<N>` rows removed (the build changes only local declaration order).\n",
     f"- **Stage B (ef9781b, rows):** 30 junk `<name>+<N>` rows removed (the build changes only local declaration order).\n"
     f"- **Stage C ({hc}, labels):** the block named by e2m 8B47 / 8B48 (EOI_Default / _Hydraulic_Delay / _Max_Limit /\n"
     "  _Min_Limit, EOI); the addend is the hydraulic delay.\n")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "- **Stage A:** `apply_r43a.py`, `rules_r43a*.json`. **Stage B:** `apply_r43b.py`, `removed_junk_rows.txt`. ",
     "- **Stage A:** `apply_r43a.py`, `rules_r43a*.json`. **Stage B:** `apply_r43b.py`, `removed_junk_rows.txt`. "
     "**Stage C:** `apply_r43c.py`. **Fix:** `dedupe_task046.py`, `apply_r43_fix.py`. ")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
t = open(f).read()
add = (" Never cap an e2m search with head: the round's block (8B47 EOI_*) sat past the cut. A fix script's edit guard "
       "must be `if new in t: return` (an insertion keeps the old text inside the new).")
if "Never cap an e2m search with head" not in t:
    t = t.replace("removing them only reorders local declarations.\n", "removing them only reorders local declarations." + add + "\n")
    open(f, "w").write(t)
print("fix applied")
