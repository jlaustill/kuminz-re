"""Round 59 stage B: round 58's follow-up said scan_accesses_v2.py "found 2 of the 6 stores" to the P0116 countdown
(0x3fd188) and the booster counter (0x3fd0b8). That set a decompile line count against a machine store count. The
machine code has exactly 2 stores to each word in those functions (0x52deac / 0x52df64 and 0x5290dc / 0x529140); the
decompile prints 6 lines because it repeats a shared store in each branch's return path. The scan's real limit stays:
it forgets volatile bases at each call in address order and does not see computed pointers, so it cannot prove
absence. Comments, docs and memory only. Idempotent.  usage: fix_r59b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(path, old, new, count=1):
    s = open(path).read()
    if new in s and old not in s:
        return
    assert s.count(old) == count, (path, old[:70], s.count(old))
    open(path, "w").write(s.replace(old, new))


G = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
edit(G, "; neither sees a computed pointer and the scan tracks bases in address order only - it found 2 of the 6 stores "
        "to the P0116 countdown - so it cannot prove absence",
     "; neither sees a computed pointer and the scan forgets the volatile bases at each call in address order - so "
     "neither proves absence", count=7)
T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(T, "so it under-reports: it found 2 of the 6 stores to the P0116 countdown and 2 of\n"
        "  the 6 to the booster counter. The follow-up commit corrected the rows' wording.",
     "so it cannot prove absence. Round 58's follow-up called it an under-report (2 of 6\n"
     "  stores found); round 59 counted the machine code: those words have exactly 2 stores each, which the decompile\n"
     "  prints as 6 lines by repeating the store in each branch's return path.")
edit(T, "  - `scan_accesses_v2.py` could become a repo tool once it follows control flow; it now tracks bases in address\n"
        "    order and under-reports.",
     "  - `scan_accesses_v2.py` could become a repo tool once it follows control flow; it now tracks bases in address\n"
     "    order, so it cannot prove absence.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/typing_focus_2026_11.md"
edit(M, "but it tracks bases in address order and under-reports (2 of 6 known stores found), so a no-reader claim rests on "
        "the decompile's use list plus the dump, worded 'no other access found'.",
     "but it tracks bases in address order and cannot prove absence, so a no-reader claim rests on the decompile's use "
     "list plus the dump, worded 'no other access found'. Round 59: a decompile line count is not a machine store "
     "count - the decompiler repeats a shared store in each branch's return path.")
print("round 58's scan claim corrected")
