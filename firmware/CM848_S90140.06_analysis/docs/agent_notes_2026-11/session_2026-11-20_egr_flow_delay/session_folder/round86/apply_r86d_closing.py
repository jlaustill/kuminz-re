"""Round 86 stage D closing: task 046, PR body, README, the memory counts. Idempotent.
usage: apply_r86d_closing.py <repo> <pr_body.md> <hash D> <count>"""
import os
import re
import sys

repo, pr, hd, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def edit(p, old, new):
    p = p if os.path.isabs(p) else os.path.join(repo, p)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "  the 58 functions that still showed stack-argument pieces: 50 accepted, 8 amended (comments only), 88 parameter rows.\n",
     "  the 58 functions that still showed stack-argument pieces: 50 accepted, 8 amended (comments only), 88 parameter rows.\n"
     "  C2 added the two chip select 5 message object wrappers, so stage C placed 60 functions (58 + 2).\n")
edit(T46, "- **firmware/CLAUDE.md:** the two corrections in stage B (old and new lines in its commit).",
     f"- **Stage D ({hd}), from an advisor review of stage C:** the local rows of the changed functions were checked\n"
     "  (`local_rows_check.py`). One had moved: stage C's word return for `cm550_crc16Calculate` merged three values of\n"
     "  one register in `mc68k_dispatchJ1708ReceivedMessages` (the elapsed timer read, the CRC, a `QSM_SCCR1` temp), so\n"
     "  `elapsedTimerCount` had landed on the CRC result. That row is removed. Every new artifact token in the 13 census\n"
     "  functions was read (`new_token_lines.py`): nearly all are the stale high byte of a pushed word. The exception is\n"
     "  `cm550_diagMemoryReadResponseBuilder`'s unused return, now a `void` row.\n"
     "- **firmware/CLAUDE.md:** the two corrections in stage B (old and new lines in its commit).")
edit(pr, "- **Stage C (4b6911cb):** wave 2 - rows for 58 more functions, proposed and verified by a workflow.\n",
     "- **Stage C (4b6911cb):** wave 2 - rows for 60 more functions (58 proposed and verified by a workflow, plus 2\n"
     "  wrappers).\n"
     f"- **Stage D ({hd}):** a local row that stage C's renumbering had moved is removed; one unused return becomes\n"
     "  `void`.\n")
edit(pr, "- [x] Round 86: C: ",
     f"- [x] Round 86: D: CM550 verify DETERMINISTIC; only the two target functions change; the local rows of every changed function checked\n- [x] Round 86: C: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "- **Closing:** `apply_r86_closing.py`, `update_large_tar_r86.sh`.\n",
     "- **Stage D:** `local_rows_check.py` (each named local of a changed function, before / after),\n"
     "  `new_token_lines.py` (the new artifact lines, for classification), `apply_r86d.py`.\n"
     "- **Closing:** `apply_r86_closing.py`, `apply_r86d_closing.py`, `update_large_tar_r86.sh`; `wave2_result.json` is the\n"
     "  workflow's proposals and verdicts.\n")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    s = open(M + name).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2
    open(M + name, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
old = "wave 2 workflow: 58 more functions)"
new = ("wave 2 workflow: 58 more functions + 2 wrappers; stage D: a changed callee prototype can renumber a caller's "
       "temporaries and move its local rows - check them)")
if new not in s:
    assert s.count(old) == 1
    open(log, "w").write(s.replace(old, new))
print("round 86 stage D closing applied")
