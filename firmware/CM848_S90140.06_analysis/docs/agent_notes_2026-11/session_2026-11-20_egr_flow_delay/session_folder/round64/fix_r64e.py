"""Round 64 follow-up (the advisor's closing review): correct the pushed closing's numbers and record the corrections
to this round's commit messages. Idempotent.  usage: fix_r64e.py <repo> <pr_body.md> <hash D> <count>"""
import os
import re
import sys

repo, pr, hd, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r64"


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


OLD_PROOF = "with no cast added and 4 placeholder names removed"
NEW_PROOF = ("with no cast or placeholder added or removed (the dispatcher's split temp is J1939_DIAGNOSTIC_RESULT JVar1 "
             "now - was uint uVar1)")
T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "  - 12 codes, named from what produces them in this firmware: the validator, the dispatcher, the memory workers,\n"
        "    the region lookup and the handlers.\n",
     "  - 11 codes, named from what produces them in this firmware: the validator, the dispatcher, the memory workers,\n"
     "    the region lookup and the handlers. 0xff (nothing to send) is deliberately not a member: the dispatcher masks\n"
     "    each result with 0xff, and a member of that value would name the mask.\n")
edit(T, "    `history_corruption.py` finds a rewritten note. Round 63's renames show none.\n- **Proof:**",
     "    `history_corruption.py` finds a rewritten note. Round 63's renames show none, and neither do rounds 57-62's\n"
     "    archived maps.\n"
     f"- **Corrections ({hd}), from the closing review:**\n"
     "  - The pushed closing said 12 codes and that the dispatcher lost 4 placeholder names. The enum has 11 codes, and\n"
     "    the dispatcher lost none. `review_typed.py` matched only lowercase prefixes; `review_typed_r64.py` matches\n"
     "    `JVar` too.\n"
     "  - Commit 3ce87e58 says the thunk snapshot has 10 targets at 0x3fc580 - 0x3fcb24. That range holds 9; the\n"
     "    snapshot's tenth, 0x3fc484, lies below the record.\n"
     "  - The `j1939_transport_tx_data` comment said a 0x4c read reply needs up to 1775 bytes. That is the 0x49 reply\n"
     "    to a 0x48 read (header 11 + 1764); a 0x4c reply needs 1773. The comment is fixed, and the `.cpp` is\n"
     "    unchanged.\n"
     "  - Commit 36c29ebe repeats the 4-placeholder claim.\n"
     "- **Proof:**")
edit(T, OLD_PROOF, NEW_PROOF)
edit(pr, "one result-code enum, `J1939_DIAGNOSTIC_RESULT` (12 codes, each named from its producer),",
     "one result-code enum, `J1939_DIAGNOSTIC_RESULT` (11 codes, each named from its producer),")
edit(pr, OLD_PROOF, NEW_PROOF)
edit(os.path.join(W, "proof_r64.txt"), OLD_PROOF, NEW_PROOF)
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
open(M + "MEMORY.md", "w").write(re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)",
                                        f"(cm848/egr-flow-delay-model, {count} commits)", m))
f = M + "typing_focus_2026_11.md"
note = ("    - An enum member equal to a mask value names the mask: the dispatcher's & 0xff read & ..._NONE. Leave such a\n"
        "      value out of the enum.\n"
        "    - The local-variable stage sees positional names, with the prefix taken from each variable's type. Two\n"
        "      J... enums made both locals JVar<n> (the service local was JVar1, the result JVar4), so key the rows by\n"
        "      position.\n"
        "    - Count placeholders with [a-zA-Z]{1,2}Var (r64/review_typed_r64.py); the old regex missed JVar.\n")
s = open(f).read()
if "names the mask" not in s:
    open(f, "w").write(s.rstrip("\n") + "\n" + note)
print("round 64 corrections applied")
