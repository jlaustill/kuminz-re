"""Round 41 fix (advisor review), text only: the mask row's 'cutout class bit 8' (the code tests mask 8), the cylinder
records' 'records 6 / 7 are unused' (they are injectors 7 / 8, past cylinder_event_count_max), the proof claim narrowed
to what prove_records.py checks, and the round's checks recorded (the parameter ID table, the widths, the low voltage
threshold vs the low fault). Idempotent.  usage: apply_r41_fix.py <repo> <pr_body.md> <commit count>"""
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
edit(gv, "compares it with 1 / 2 / 0 (cutout class bit 8)",
     "compares it with 1 / 2 / 0 (while cylinder_cutout_diagnostic_class_enable_mask & 8 is set)")
edit(gv, "records 6 / 7 are unused on 6 cylinders (the table ends at supervisor_watchdog_answer_3_table)",
     "records 6 / 7 hold injectors 7 / 8 and lie past cylinder_event_count_max (6) (the table ends at "
     "supervisor_watchdog_answer_3_table)")
T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "- **Proof:** `prove_records.py` maps the old raw addresses and the new struct accesses to field tokens by offset.\n"
          "  - The monitor has 112 statements on each side, identical apart from its name.",
     "- **Proof:** `prove_records.py` maps the old raw addresses and the new struct accesses to field tokens by offset.\n"
     "  - The monitor has 112 statements on each side, identical apart from its name. That proves field identity and\n"
     "    statement structure: the canonical form drops the bracket indexes, the index set-up and the temp names, so it\n"
     "    does not check which record or cylinder an access indexes (the index derivation reads the same in both).")
edit(T46, "- **Leads:**\n  - The monitor still carries decompiler temps and one goto (Readability Medium).",
     "- **Checks (fix commit):**\n"
     "  - The parameter ID table resolves none of the new rows (absence of data). Its records for the channel config /\n"
     "    state (81CB-81CF) confirm every pointer target: High_Limit / Low_Limit / Fault_Set, Raw / Unfiltered /\n"
     "    User_Value.\n"
     "  - Every access is word-width (`lhz` / `sth`, indexed included).\n"
     "  - The low voltage check is on in this calibration and distinct from the low fault: count limit 3 at threshold 699\n"
     "    raw counts, against the low fault's 705.\n"
     "  - All 8 cylinder records follow the field order; records 6 / 7 are injectors 7 / 8.\n"
     "  - This resolves round 39's booster capacitor monitor lead.\n"
     "- **Leads:**\n  - The monitor still carries decompiler temps and one goto (Readability Medium).")
edit(pr, "- [x] Round 41: the monitor's 112 statements match field by field (prove_records.py); the other functions match "
         "the canonical form or differ in local declaration order only.",
     "- [x] Round 41: the monitor's 112 statements match field by field (prove_records.py: field identity and statement "
     "structure; the indexes are dropped); the other functions match the canonical form or differ in local declaration "
     "order only; widths asm-verified.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
open(M + "MEMORY.md", "w").write(m)
print("fix applied")
