"""Round 40 fix (advisor review), text only.
- The 24 stage A comments said "only application code uses it"; that was measured as a name search of the .cpp, and
  some of those addresses lie in the kernel image window or the time-shared header range. They now say "only
  application code references this name".
- The counts: the parameter ID table resolved 7 of the candidates (not 8); 10 names changed their base (9 EEPROM rows
  plus engine_idling_flag) and 15 only gained _cal (not 7 / 17). Task 046 and the PR body.
- firmware/CLAUDE.md's round 39 sentence still said 258 MISSING; it gives the 234 and their categories now. Memory too.
Idempotent.  usage: apply_r40_fix.py <repo> <pr_body.md> <commit count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and old not in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


gv = "firmware/CM848_S90140.06_analysis/output/global_variables.csv"
t = open(path(gv)).read()
n = t.count("only application code uses it)")
t = t.replace("only application code uses it)", "only application code references this name)")
open(path(gv), "w").write(t)
print("comments reworded:", n)
T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "that describe the application's EEPROM value change. Every candidate went through the ECU's parameter ID table\n"
          "    first, which resolves 8.",
     "that describe the application's EEPROM value change. Every candidate went through the ECU's parameter ID table\n"
     "    first, which resolves 7.")
edit(T46, "  - **Seven names change with the evidence:**",
     "  - **Ten names change with the evidence (nine EEPROM rows and `engine_idling_flag`; 7f54db1's message said seven):**")
edit(T46, "  - The other 17 rows only gain `_cal`, among them",
     "  - The other 15 rows only gain `_cal` (7f54db1's message said 17), among them")
edit(pr, "24 application-side names in the EEPROM mirror gain `_cal`; 7 renamed from their e2m\n"
         "  records and code (the idle counters, the feature bitmap, the exhaust brake switch learned flag, ...).",
     "24 application-side names in the EEPROM mirror gain `_cal`; 9 of them (plus\n"
     "  `engine_idling_flag`) renamed from their e2m records and code (the idle counters, the feature bitmap, the exhaust\n"
     "  brake switch learned flag, ...).")
edit("firmware/CLAUDE.md",
     "The 258 MISSING rows (EEPROM-backed names without `_cal`) are still open.",
     "MISSING (EEPROM-backed names without `_cal`) is 234 since PR #53 round 40: 123 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "18 with no reference by name, and 6 deferred.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
open(M + "MEMORY.md", "w").write(m)
cf = M + "feedback_cal_suffix_memory_map.md"
c = open(cf).read()
old = "258 MISSING remain."
new = ("MISSING is 234 since round 40 (123 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
       "addresses, 18 unreferenced, 6 deferred); sort MISSING rows by who references them before adding _cal.")
if new not in c:
    assert c.count(old) == 1
    open(cf, "w").write(c.replace(old, new))
print("fix applied")
