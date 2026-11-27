"""Round 19 stage D docs: task 046's round 19 section and the PR body after the review. Idempotent.
usage: apply_r19d_docs.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(p, old, new):
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (p[-30:], old[:60], t.count(old))
    open(p, "w").write(t.replace(old, new))


t46 = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(t46, "- **Stage C (label-only): the ANC pass-through.**\n  - The ANC timing stage (e2m 10A4, enables in 106B +8) is compiled out: its RAM words have no access.",
     "- **Stage C (75d8c34, label-only): the ANC pass-through.**\n"
     "  - The ANC timing stage (e2m 10A4, enables in 106B +8) is compiled out. A raw scan of both banks finds no access to\n"
     "    0x40a04a-0x40a05d (its control, 0x40a05e, finds the three known ones), and no code tests the three ANC enable\n"
     "    bits (0x1000 / 0x2000 / 0x4000 of 0x3fd5a2).")
edit(t46, "- **Round 19 leads:**\n",
     "- **Stage D (label-only, after the review):** the siblings of stage A's map, each by its e2m record and the parameter\n"
     "  ID table: the pilot timing offset cranking map (8078-807A `Pilot_SOI_Cranking_*`), the pilot quantity crank map,\n"
     "  its correction and coolant factor (8D76-8D78, 806A +26, 8068 / 8069), the crank logic select (805F +22), and the\n"
     "  cranking fuel pressure setpoint table and value (803F +2). They were all `*_cold_start_*`.\n"
     "- **Round 19 leads:**\n"
     "  - **AENBLFLG word 3:** 0x3fd5a2 `j1939_governor_feature_cal` is algorithm enable flags word 3 (e2m 106B +8):\n"
     "    0x8 idle speed adjust, 0x10 PTO, 0x40 cruise control, 0x80 road speed governor, 0x400 cruise / RSG droop,\n"
     "    0x1000-0x4000 ANC, 0x8000 the cruise set speed save. The code tests 0x10 / 0x40 / 0x80 / 0x100 / 0x8000 (21\n"
     "    lines), so it is a bitfield struct and a rename (0x100 has no e2m name).\n"
     "  - **`cm848_initialization_step_3`** is the ambient conditions module's initializer. Its filter\n"
     "    (`ema_filter_state_t_003fb9f6`, coefficient `WORD_003ff07e`) is unnamed.\n")
edit(pr, "- **Stage C (label-only):** the compiled-out ANC stage's pass-through into the combustion limits input.",
     "- **Stage C (75d8c34, label-only):** the compiled-out ANC stage's pass-through into the combustion limits input.\n"
     "- **Stage D (label-only, after the review):** the pilot timing / pilot quantity / rail pressure cranking maps and words,\n"
     "  from their e2m records (were `*_cold_start_*`).")
edit(pr, "- [x] Round 19: stages A and C are EQUIVALENT;", "- [x] Round 19: stages A, C and D are EQUIVALENT;")
print("docs updated")
