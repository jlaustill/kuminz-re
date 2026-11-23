"""Round 45 follow-up, the user's two decisions (2026-11-22): the round 27 fault bitfield section stays as it is; the
auditing-cal-suffixes skill says HARD 0 (was ~1352) and its region table matches the auditor. Records them in task 046,
the PR body and memory. Idempotent.  usage: apply_r45_user_decisions.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(p, old, new):
    p = p if os.path.isabs(p) else os.path.join(repo, p)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:60], t.count(old))
    open(p, "w").write(t.replace(old, new))


edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "  - The `fuel_level_low_distance_*` family (11 rows) could take the e2m's \"rationality\" vocabulary.\n",
     "  - The `fuel_level_low_distance_*` family (11 rows) could take the e2m's \"rationality\" vocabulary.\n"
     "- **The user's decisions (2026-11-22):**\n"
     "  - The round 27 fault bitfield exception section in `firmware/CLAUDE.md` stays as it is. The user left the call\n"
     "    to me. One line cannot carry its two gotchas: word 0 stays a plain word (the base of 200 indexed accesses), and\n"
     "    a nested type per word prints `ZPULL(...)`.\n"
     "  - The `auditing-cal-suffixes` skill now says HARD 0 since round 39 (was \"~1352\"), checked by a fresh\n"
     "    `audit_cal_suffixes.py` run (0 hard, 0 soft, 221 missing). Its region table now matches the auditor: the\n"
     "    mirror is 0x3FD482-0x3FEEC1, and the copy window's overlapping top counts as mirror.\n")
edit(pr, "  state. One rename.\n",
     "  state. One rename.\n"
     "- **Skill (the user's request):** `auditing-cal-suffixes` says HARD 0 since round 39 (was \"~1352\"), and its region\n"
     "  table matches `audit_cal_suffixes.py`. The round 27 section in `firmware/CLAUDE.md` stays as it is.\n")
f = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/typing_focus_2026_11.md"
note = ("  - The user's decisions (2026-11-22): the round 27 fault bitfield exception section in firmware/CLAUDE.md stays "
        "(the user left it to me: its two gotchas need more than one line); the auditing-cal-suffixes skill says HARD 0 "
        "(was ~1352). Neither is a pending item any more.\n")
if "The user's decisions (2026-11-22)" not in open(f).read():
    open(f, "a").write(note)
print("decisions recorded")
