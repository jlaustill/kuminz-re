"""Round 42 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r42_closing.py <repo> <pr_body.md> <hash A> <hash B> <commit count>"""
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


T46 = f"""## Done, round 42 (2026-11-22, same PR): the fault status records, the retarder cylinder counts

A peer relay started the round; the scripts are in `session_folder/round42/`.
- **Stage A ({ha}, a type):** `fault_status_array` (byte) and `fault_status_word_array` (word at +1) are one
  per-fault-slot status record (EEPROM 0x1710 + 3 x slot), now `fault_status_records_cal` (`fault_status_record_t`:
  `flags` byte + `status_word`).
  - **flags:** 0x10 the MIL request, 0x60 the heal cycle count, 0x0e a severity count, 0x80 a stored DTC. They are
    updated with read-modify-write masks, so the field stays a byte.
  - **status_word:** bit 0 active, bits 3-9 an age.
  - **Typed at the base only:** 170 records would run across the boot kernel's time-shared structures at
    0x3fec7a-0x3fecf6.
  - **Render:** the 24 users read `(&fault_status_records_cal)[slot].flags` / `.status_word`.
  - **Proof:** `prove_status_records.py` gives 0 differing statements in 23 users; `fault_clearByIndex` keeps one
    index set-up the struct index absorbs. This proves field identity and statement structure, not the index.
- **Stage B ({hb}, labels and a local):** the retarder's six "stage weights" are e2m 13D8 Jcomm_EB_Driver_N_Num_Cyl
  (`engine_retarder_driver_N_cylinder_count`, 1 / 0 / 0 / 0 / 0 / 0). The engaged count is 13D9 Engine_Brake_On_Sum
  (`engine_retarder_cylinders_on_count`).
  - `cm848_calculateEngineRetarderTorque`'s live-in `in_r6` is the selected table (`selected_stage_torque_values`).
  - A count above 6 would read a stale r6; that is unreachable with these counts.
- **Leads:**
  - The other `fault_status_records_cal` bits: flags 0x01, status_word 0x02 / 0x04.
  - The "stage N" torque tables have no e2m record in the dump.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 42.**\n"
     f"- **Stage A ({ha}, a type):** the per-fault-slot status records (`fault_status_records_cal`, a 3-byte struct; was\n"
     "  two overlapping rows).\n"
     f"- **Stage B ({hb}, labels):** the engine retarder driver cylinder counts and the cylinders-on count from e2m 13D8 /\n"
     "  13D9; the retarder torque lookup's live-in table pointer named.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 41: the monitor's 112 statements match field by field",
     "- [x] Round 42: the 24 status record users match field by field (index set-up dropped); the retarder function has "
     "0 differing statements; the other functions match the canonical form.\n"
     "- [x] Round 41: the monitor's 112 statements match field by field")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 42: the fault status records, the retarder cylinder counts (`session_folder/round42/`)\n\n"
       "- **Stage A:** `apply_r42a.py`, `prove_status_records.py`. **Stage B:** `apply_r42b.py`, `rules_r42b.json`. "
       "**Closing:** `apply_r42_closing.py`, `update_large_tar_r42.sh`.\n")
if "## Round 42:" not in t:
    i = t.index("## Round 41:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 41: the booster capacitor monitor - open: the task 046 leads",
     "round 41: the booster capacitor monitor; round 42: the fault status records, the retarder cylinder counts - open: "
     "the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "two ROM record tables as struct arrays); task 046 leads"
new = ("two ROM record tables as struct arrays) + round 42 (fault_status_records_cal 3-byte struct; the retarder "
       "driver cylinder counts e2m 13D8 / 13D9); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 42 (2026-11-22): {ha} / {hb}. A per-slot record table that overlaps time-shared boot structures "
        "can still be typed as ONE record at its base: Ghidra renders the slot x size indexing through it as "
        "(&base)[slot].field.\n")
if "Round 42 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 42 closing applied")
