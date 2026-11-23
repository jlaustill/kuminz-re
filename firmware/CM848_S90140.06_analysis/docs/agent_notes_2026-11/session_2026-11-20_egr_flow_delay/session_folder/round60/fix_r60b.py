"""Round 60 follow-up: the firmware/CLAUDE.md stuck-warning row said "Resolved in PR #53 round 60", but the pre-round
decompile of cm848_lookupTableEntryByKey already rendered &param_id_lookup_table without the '_'. Round 60 only typed
it. Reword the row and the matching task 046 line to what was seen. Idempotent.  usage: fix_r60b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (rel, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


edit("firmware/CLAUDE.md",
     "| `_param_id_lookup_table` | Resolved in PR #53 round 60: it is the boot kernel's parameter ID table, now "
     "`boot_parameter_id_table` (a `parameter_id_entry_t[20]` array, which applies over the ROM-to-RAM window) |",
     "| `_param_id_lookup_table` | No longer stuck: it already rendered without the `_` (as `param_id_lookup_table`) "
     "before PR #53 round 60. It is the boot kernel's parameter ID table, typed since round 60 as "
     "`boot_parameter_id_table` (a `parameter_id_entry_t[20]` array, which applies over the ROM-to-RAM window) |")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "  - the stuck-warning row for `_param_id_lookup_table` now records that the typed array applies over the window.",
     "  - the stuck-warning row for `_param_id_lookup_table`: it already rendered without the `_` before this round; the\n"
     "    row now says so, and that the typed array applies over the window (a follow-up fixed the row's first wording,\n"
     "    \"resolved in round 60\").")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
m = open(M).read()
open(M, "w").write(m.replace("(cm848/egr-flow-delay-model, 261 commits)", "(cm848/egr-flow-delay-model, 262 commits)"))
print("round 60 follow-up applied")
