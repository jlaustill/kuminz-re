"""Round 44 stage C closing: correct stage B's block count and placement wording (14 blocks: 11 tile five gaps, 8B50 /
8BAE match field by field, 8B59 by meaning), qualify the 8BAC match, reword the untested 8B13 lead, record stage C.
Task 046, PR body, README, todo, memory. Idempotent (guard: the new text already present).
usage: apply_r44c_closing.py <repo> <pr_body.md> <hash C> <count> <proof line>"""
import os
import re
import sys

repo, pr, hc, count, proof = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "the uncapped search finds the blocks that hold stage A's rows. They lie past the\n"
        "  dumped parameter ID table. Each block's CHR_CC layout fills a gap between dumped-table blocks exactly, and every\n"
        "  record's description matches the code that reads the row (`align_blocks.py`):\n",
     "the uncapped search finds 14 blocks past the dumped parameter ID table that hold\n"
     "  stage A's rows and their neighbours (`align_blocks.py`). Every record's description matches the code that reads\n"
     "  the row. How each block is placed:\n"
     "  - 11 blocks fill five gaps between dumped-table blocks exactly: 8C30; 8B12; 8B4E + 8BAC; 8B4F + 8BAD; and 8B51-8B55,\n"
     "    between 8D3A's 30-byte table and 106D.\n"
     "  - 8B50 / 8BAE match the EEPROM rows field by field. 8C36 ends at EEPROM 0x19a1, 16 bytes before 8B50.\n"
     "  - 8B59 is placed by meaning only.\n"
     "  The blocks:\n")
edit(T, "    - 8BAC's 15 records match the 15 pedal calibration rows in order.\n",
     "    - 8BAC's 15 records line up with the 15 pedal calibration rows in order. 14 descriptions match the code-derived\n"
     "      names; the 15th, +0x18 PPS_AZ_Time_Limit, shows the \"total step\" limit is a time limit (stage C).\n")
edit(T, "  - 8B13 ASG_Throttle_Reset_Allow is not placed: no gap matches it.\n",
     "  - 8B13 ASG_Throttle_Reset_Allow was not searched for.\n"
     f"- **Stage C ({hc}, labels):** the advisor's review of stage B.\n"
     "  - `accelerator_pedal_idle_learning_total_step_limit` / `_counter` are `accelerator_pedal_idle_learning_time_limit`\n"
     "    / `accelerator_pedal_idle_learning_timer`.\n"
     "    - The counter increments on every 100 ms pass in which either channel's learning conditions hold, whether or\n"
     "      not a step is taken.\n"
     "    - Its limit is 8BAC +0x18 PPS_AZ_Time_Limit: 'Time allowed from key on for pps auto zero when auto zero\n"
     "      conditions exist', 29.9 s here.\n"
     "  - The PPS block is inactive in this calibration. 0x408a84 (8BAC +0x12 Accelerator_Position_Sensor_Type) is 0,\n"
     "    which the e2m defines as TPS operation for the commanded throttle, so the five PPS block functions do nothing.\n"
     "    The test cell comment on 0x408a76 now says so.\n"
     "  - No history was lost: every `(was` note of stage B's renamed rows survives (`check_r44b_review.py`).\n"
     f"  - **Proof:** {proof}\n")
edit(pr, "nine e2m blocks past the dumped parameter ID table placed by tiling. Stage A's\n",
     "14 e2m blocks past the dumped parameter ID table (11 fill five gaps between dumped-table\n"
     "  blocks exactly, 8B50 / 8BAE match field by field, 8B59 by meaning). Stage A's\n")
edit(pr, "  OCM_Soot_Percentage_*). 33 rows gain citations.\n",
     "  OCM_Soot_Percentage_*). 33 rows gain citations.\n"
     f"- **Stage C ({hc}, labels):** the pedal learning's \"total step\" limit and counter are a time limit and its timer (e2m\n"
     "  PPS_AZ_Time_Limit); the PPS block is inactive in this calibration (Accelerator_Position_Sensor_Type = 0, TPS).\n")
edit(pr, "- [x] Round 44 stage B:", f"- [x] Round 44 stage C: {proof}\n- [x] Round 44 stage B:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "`check_history_r44b.py`, `apply_r44b_closing.py`.",
     "`check_history_r44b.py`, `apply_r44b_closing.py`. **Stage C:** `apply_r44c.py`, `map_r44c.csv`, "
     "`check_r44b_review.py` (run with `git show f338e54:firmware/CM848_S90140.06_analysis/output/global_variables.csv` "
     "as its before file), `apply_r44c_closing.py`.")
edit("work/todo.md", "the oil soot model and the PPS block placed by tiling - open: the task 046 leads",
     "the oil soot model and the PPS block placed by tiling, the PPS learning time limit - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = ("stage B: 9 e2m blocks past the dumped table placed by TILING the gaps between table blocks - the oil soot model "
       "e2m 8B4E/8B50/8B54/8B55, the PPS block 8BAC/8BAD); task 046 leads")
new = ("stage B: 14 e2m blocks past the dumped table, 11 placed by TILING the gaps between table blocks - the oil soot "
       "model e2m 8B4E/8B50/8B54/8B55, the PPS block 8BAC/8BAD, inactive here (TPS); stage C: the PPS learning time "
       "limit); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 44 stage C (2026-11-22): {hc}. A counter that increments when an action is allowed, not when it is "
        "taken, is a timer (the e2m's MSEC record named it). Check a block's gate before describing its behaviour in the "
        "dump: Accelerator_Position_Sensor_Type = 0 switches the whole PPS block off on this truck. Count what you "
        "claim: stage B said 'nine blocks' for 14.\n")
if "Round 44 stage C (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 44 stage C closing applied")
