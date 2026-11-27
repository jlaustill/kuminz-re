"""Round 58 follow-up (the advisor's closing checks; comments, docs and memory only - nothing that renders). Idempotent.
usage: fix_r58b.py <repo>
- scan_accesses_v2.py under-reports: it tracks bases in address order and drops the volatile registers at every bl,
  so a base kept across a call on another path is lost. It found 2 of the 6 stores to the P0116 countdown (0x3fd188)
  and 2 of the 6 to the booster counter (0x3fd0b8) that the decompile shows. The "no other access" claims rest on the
  decompile's use list (every function, by name) plus the dump values; the rows now say so.
- "No global keeps a protection_ prefix" was counted in global_variables.csv only: four struct fields still start with
  protection_ (engine_control_flags_t.protection_system, timing_mode_control_t.protection_blend_ramp /
  protection_counter_1 / protection_counter_2)."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
OLD = "no other access found by scan_accesses_v2.py (a base-tracking scan of both banks; computed pointers can escape it)"
NEW = ("no other access in the decompile (every function - by name) nor in scan_accesses_v2.py's base-tracking scan "
       "of both banks; neither sees a computed pointer and the scan tracks bases in address order only - it found 2 of "
       "the 6 stores to the P0116 countdown - so it cannot prove absence")
G = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
t = open(G).read()
n = t.count(OLD)
assert n in (0, 7), n
open(G, "w").write(t.replace(OLD, NEW))


def edit(path, old, new):
    s = open(path).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(path, "w").write(s.replace(old, new))


T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(T, "- **Stage A (d0ce823).** Accesses were checked with `scan_accesses_v2.py`, a base-tracking D-form scan of both banks\n"
        "  (lis / addi / ori / mr bases). Computed pointers can escape it, so the rows say \"no other access found\".",
     "- **Stage A (d0ce823).** Each \"no other access found\" rests on the decompile's use list (every function, by name)\n"
     "  plus the dump values. `scan_accesses_v2.py`, a base-tracking D-form scan of both banks (lis / addi / ori / mr\n"
     "  bases), adds the raw-offset forms such as `lbz r11,19(r31)`. It tracks bases in address order and drops the\n"
     "  volatile registers at every `bl`, so it under-reports: it found 2 of the 6 stores to the P0116 countdown and 2 of\n"
     "  the 6 to the booster counter. The follow-up commit corrected the rows' wording.")
edit(T, "  - No global keeps a `protection_` prefix now. ",
     "  - No `global_variables.csv` row keeps a `protection_` prefix now; four struct fields still do\n"
     "    (`engine_control_flags_t.protection_system`, `timing_mode_control_t.protection_blend_ramp` /\n"
     "    `protection_counter_1` / `protection_counter_2`). ")
edit(T, "  - `scan_accesses_v2.py` could become a repo tool (an access finder that sees base-register forms).",
     "  - `scan_accesses_v2.py` could become a repo tool once it follows control flow; it now tracks bases in address\n"
     "    order and under-reports.\n"
     "  - firmware/CLAUDE.md's time-shared bullet still says 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe are read \"by protection + J1939\n"
     "    builders\"; they are the logical output line map.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
edit(M + "typing_focus_2026_11.md",
     "use r58's scan_accesses_v2.py (lis / addi / ori / mr tracking) before claiming a word has no reader.",
     "r58's scan_accesses_v2.py adds those base-register forms, but it tracks bases in address order and under-reports "
     "(2 of 6 known stores found), so a no-reader claim rests on the decompile's use list plus the dump, worded 'no "
     "other access found'.")
mm = open(M + "MEMORY.md").read()
open(M + "MEMORY.md", "w").write(mm.replace("(cm848/egr-flow-delay-model, 254 commits)",
                                            "(cm848/egr-flow-delay-model, 255 commits)"))
print(f"round 58 follow-up applied ({n} row comments)")
