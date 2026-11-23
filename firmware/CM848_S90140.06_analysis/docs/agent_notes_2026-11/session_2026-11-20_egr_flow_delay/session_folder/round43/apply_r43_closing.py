"""Round 43 closing: task 046, PR body, README, todo, firmware/CLAUDE.md's MISSING sentence (factual refresh), memory.
Idempotent.  usage: apply_r43_closing.py <repo> <pr_body.md> <hash A> <hash B> <commit count>"""
import os
import re
import sys

repo, pr, ha, hb, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 43 (2026-11-22, same PR): the main injection end timing, the junk rows

A peer relay started the round; the scripts are in `session_folder/round43/`.
- **Stage A ({ha}, labels, types):** `cm848_computeFuelRpmCompensatedOffset` is `cm848_calculateMainInjectionEndTiming`.
  - It computes the main injection's end of injection timing: the start minus the pulse's crank angle.
  - Units: on-time at 0.4 us per count x engine speed at 1/8 rpm x 6 / 1e6 x 256 / 600 lands in main timing counts.
  - Its output is `main_injection_end_timing`, and its four calibrations follow (round 39's fuel_rpm_compensated_*
    names). The three signed ones (lha) are `i16`.
  - The old plate said the output had no reader; `cm848_updateOilChangeMonitor` reads it.
- **Stage B ({hb}, rows):** 30 junk `<name>+<N>` rows removed. They were an old export's labels for interior bytes,
  rendered nowhere. The `.cpp` differs only in local declaration order. MISSING 233 -> 221.
- **firmware/CLAUDE.md (factual refresh):** the MISSING sentence gives 221 (123 documentation, 77 boot-named, 10 dual-use,
  7 unreferenced, 4 deferred).
- **Leads:**
  - The typed junk row `fuel_demand_enable_sync_flag_shadow+2` (`undefined2`).
  - The oil change monitor's "engine power" accumulator and increment table: keyed by the end of injection, so likely
    soot, but unproven.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 43.**\n"
     f"- **Stage A ({ha}, labels, types):** the main injection end of injection timing (was\n"
     "  cm848_computeFuelRpmCompensatedOffset): the function, its output and its calibrations.\n"
     f"- **Stage B ({hb}, rows):** 30 junk `<name>+<N>` rows removed (the build changes only local declaration order).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 42: all 24 status record users match field by field",
     "- [x] Round 43: the end timing function has 0 differing statements; removing the junk rows changes only the "
     "order of local declarations.\n"
     "- [x] Round 42: all 24 status record users match field by field")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 43: the main injection end timing, the junk rows (`session_folder/round43/`)\n\n"
       "- **Stage A:** `apply_r43a.py`, `rules_r43a*.json`. **Stage B:** `apply_r43b.py`, `removed_junk_rows.txt`. "
       "**Closing:** `apply_r43_closing.py`, `update_large_tar_r43.sh`, the MISSING survey (`missing*.tsv`).\n")
if "## Round 43:" not in t:
    i = t.index("## Round 42:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 42: the fault status records, the retarder cylinder counts - open: the task 046 leads",
     "round 42: the fault status records, the retarder cylinder counts; round 43: the main injection end timing, 30 junk "
     "rows - open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "MISSING (EEPROM-backed names without `_cal`) is 233 since PR #53 round 42: 124 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "18 with no reference by name, and 4 deferred.",
     "MISSING (EEPROM-backed names without `_cal`) is 221 since PR #53 round 43: 123 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "7 with no reference by name, and 4 deferred.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the retarder driver cylinder counts e2m 13D8 / 13D9); task 046 leads"
new = ("the retarder driver cylinder counts e2m 13D8 / 13D9) + round 43 (main_injection_end_timing; 30 junk '+N' rows "
       "removed); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
cf = M + "feedback_cal_suffix_memory_map.md"
c = open(cf).read()
old = ("MISSING is 233 since round 42 (124 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
       "addresses, 18 unreferenced, 4 deferred)")
new = ("MISSING is 221 since round 43 (123 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
       "addresses, 7 unreferenced, 4 deferred)")
if new not in c:
    assert c.count(old) == 1
    open(cf, "w").write(c.replace(old, new))
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 43 (2026-11-22): {ha} / {hb}. Work a formula's units from the documented scales before naming it "
        "(0.4 us on-time x 1/8 rpm x 6 / 1e6 x 256 / 600 = main timing counts: an end of injection angle). Junk "
        "'<name>+<N>' rows render nowhere; removing them only reorders local declarations.\n")
if "Round 43 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 43 closing applied")
