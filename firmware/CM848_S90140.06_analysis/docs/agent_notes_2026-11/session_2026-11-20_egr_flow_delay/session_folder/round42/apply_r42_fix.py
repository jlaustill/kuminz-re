"""Round 42 fix (advisor review), text only.
- status_word bit 0 was called "active" from a legacy function name; the truck's dump has it clear in every slot,
  including the active P0483 (fault 407 -> slot 100: flags 0x82, status_word 0). The struct comment says what is known.
- The proof: stage A's run covered 12 of the 24 users (prove_caches.py prints at most 12 names). All 24 are proven now.
- The counts and wording in task 046 (24 users, not 22; the 0x0e count's neutral wording) and the PR test plan.
- firmware/CLAUDE.md's MISSING sentence (234 -> 233: one row gained _cal, one became a documentation row) and memory.
Idempotent.  usage: apply_r42_fix.py <repo> <pr_body.md> <commit count>"""
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


edit("firmware/CM848_S90140.06_analysis/output/structure_definitions.csv",
     "bit 0x0001: the fault is active (cm848_sciCommand51ReportActiveFaultDtcs reports it);",
     "bit 0x0001: cm848_sciCommand51ReportActiveFaultDtcs reports the slots that have it (clear in every slot of the "
     "truck's dump, the active P0483 too: slot 100 reads flags 0x82 / status_word 0, so not simply 'active');")
T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "  - **flags:** 0x10 the MIL request, 0x60 the heal cycle count, 0x0e a severity count, 0x80 a stored DTC. They are\n"
          "    updated with read-modify-write masks, so the field stays a byte.\n"
          "  - **status_word:** bit 0 active, bits 3-9 an age.",
     "  - **flags:** 0x10 the MIL request, 0x60 the heal cycle count, 0x0e a 3-bit count that\n"
     "    `diag_faultState_severity_increment` steps, 0x80 a stored DTC. They are updated with read-modify-write masks, so\n"
     "    the field stays a byte.\n"
     "  - **status_word:** bit 0 is what `cm848_sciCommand51ReportActiveFaultDtcs` reports. It is clear in every slot of\n"
     "    the truck's dump, the active P0483 too (slot 100: flags 0x82, status_word 0), so it is not simply \"active\".\n"
     "    Bits 3-9 hold an age.\n"
     "  - The dump agrees with the flags byte: P0483's 0x82 has the stored DTC bit.")
edit(T46, "  - **Render:** the 24 users read `(&fault_status_records_cal)[slot].flags` / `.status_word`.\n"
          "  - **Proof:** `prove_status_records.py` gives 0 differing statements in 23 users; `fault_clearByIndex` keeps one\n"
          "    index set-up the struct index absorbs. This proves field identity and statement structure, not the index.",
     "  - **Render:** the 24 users (34f1e78's message said 22) read `(&fault_status_records_cal)[slot].flags` /\n"
     "    `.status_word`.\n"
     "  - **Proof:** `prove_status_records.py` gives 0 differing statements in 23 of the 24 users. In the 24th,\n"
     "    `cm848_mainLoopServiceMonitor`, one pair is the same address (base + 1 + 3 x slot) written two ways.\n"
     "    - It proves field identity and statement structure, not the index.\n"
     "    - The first run covered only 12 users, because `prove_caches.py` prints at most 12 names; the fix commit\n"
     "      re-ran it on every user.\n"
     "  - This resolves round 40's deferred `fault_status_*` pair. The parameter ID table has no record at 0x3feb92\n"
     "    (round 40's `app_e2m.txt`).")
edit(pr, "- [x] Round 42: the 24 status record users match field by field (index set-up dropped);",
     "- [x] Round 42: all 24 status record users match field by field (index set-up dropped; one pair is the same "
     "address in two forms);")
edit("firmware/CLAUDE.md",
     "MISSING (EEPROM-backed names without `_cal`) is 234 since PR #53 round 40: 123 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "18 with no reference by name, and 6 deferred.",
     "MISSING (EEPROM-backed names without `_cal`) is 233 since PR #53 round 42: 124 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "18 with no reference by name, and 4 deferred.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
open(M + "MEMORY.md", "w").write(m)
cf = M + "feedback_cal_suffix_memory_map.md"
c = open(cf).read()
old = ("MISSING is 234 since round 40 (123 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
       "addresses, 18 unreferenced, 6 deferred)")
new = ("MISSING is 233 since round 42 (124 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
       "addresses, 18 unreferenced, 4 deferred)")
if new not in c:
    assert c.count(old) == 1
    open(cf, "w").write(c.replace(old, new))
print("fix applied")
