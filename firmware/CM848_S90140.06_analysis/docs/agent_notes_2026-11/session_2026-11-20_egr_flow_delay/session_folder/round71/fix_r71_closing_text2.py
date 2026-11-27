"""Round 71 closing text fixes, second pass (the final read of task 046's section). Idempotent; applied to the closed
files, proof_r71.txt and apply_r71_closing.py (so the archived closing reproduces them).
- The proof said the new casts 'convert pointer arguments'; of the 8 only 5 do: one more converts a word length, one is
  the 0x19 handler's (BOOT_DIAGNOSTIC_RESULT) mix and one is the 0x6ffff bound that lost its DAT_0006ffff label.
- The CM550 lead said cm550_memoryOperationDispatcher 'switches on its own region codes'; read, it is the application
  writer's twin path for path, on the same codes.  usage: fix_r71_closing_text2.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
W = os.path.dirname(os.path.abspath(__file__))
TASK = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
README = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/"
                            "session_2026-11-20_egr_flow_delay/README.md")
CLOSING = os.path.join(W, "apply_r71_closing.py")
COMMIT = os.path.join(W, "commit_r71_closing.txt")
PROOF = os.path.join(W, "proof_r71.txt")

NEW_PROOF = (
    "17 of 1968 functions differ after the renames, with net 26 placeholders fewer (28 out, 2 in) and net 3 casts more "
    "(8 in, 5 out). The region compares now name MEMORY_REGION_TYPE members (the download handlers, the 0x19 execute "
    "handler, both writers, both read handlers, the PCI diagnostic handler), and both lookups read their tables' fields "
    "(the application one lost its 5 casts). Of the 8 new casts, 6 convert lookup arguments to the parameters' integer "
    "types (a code * / a byte * / the PCI pointer x3 / a word length), 1 makes the 0x19 handler's region / result mix "
    "explicit (BVar6 = (BOOT_DIAGNOSTIC_RESULT)MVar7), and 1 is the 0x6ffff bound in mpc555_cmfEraseBlocks, which lost "
    "its DAT_0006ffff label. verify is byte-identical with round 70's WARNING lines; thunks 18 / 14; prototype and local "
    "rows 0 failed, locals Skipped 8 (the same warnings as round 66); no enum compositions. Headers regenerated (0 g++ "
    "errors), tests pass, lookup tables 0 sizing problems, audit_cal_suffixes.py HARD 0 / MISSING 211.")
LEAD_OLD = "  - CM550's `cm550_memoryOperationDispatcher` (0x2148a) switches on its own region codes - a cross-firmware lead."
LEAD_NEW = (
    "  - CM550's `cm550_memoryOperationDispatcher` (0x2148a) is the application J1939 writer's twin, path for path: it\n"
    "    switches on the same codes from `cm550_addressRangeValidator` (0 copy / 3 and 5 after the security check / 4 ->\n"
    "    10 / the others back as the result), and its security check calls `sensorRangeValidation`, the twin of\n"
    "    `cm848_processSecurityCodeConversion` - so MEMORY_REGION_TYPE and the twins' names can carry over to CM550.")
COMMIT_OLD = "    - CM550's cm550_memoryOperationDispatcher.\n"
COMMIT_NEW = ("    - CM550's cm550_memoryOperationDispatcher: the application writer's twin, on the same region codes.\n"
              "- The proof's cast breakdown: 6 of the 8 new casts convert lookup arguments (one a word length, not a\n"
              "  pointer); the other 2 are the 0x19 handler's result cast and the 0x6ffff bound.\n")
SCRIPTS_OLD = "`fix_r71_closing_text.py`, `update_large_tar_r71.sh`"
SCRIPTS_NEW = "`fix_r71_closing_text.py`, `fix_r71_closing_text2.py`, `update_large_tar_r71.sh`"


def edit(p, old, new):
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


old_proof = open(PROOF).read().strip()
if old_proof != NEW_PROOF:
    assert old_proof.startswith("17 of 1968 functions differ after the renames, with net 26"), old_proof[:60]
    for p in (TASK, pr):
        edit(p, old_proof, NEW_PROOF)
    open(PROOF, "w").write(NEW_PROOF + "\n")
for p in (TASK, CLOSING):
    edit(p, LEAD_OLD, LEAD_NEW)
for p in (README, CLOSING):
    edit(p, SCRIPTS_OLD, SCRIPTS_NEW)
edit(COMMIT, COMMIT_OLD, COMMIT_NEW)
print("closing text fixed (second pass)")
