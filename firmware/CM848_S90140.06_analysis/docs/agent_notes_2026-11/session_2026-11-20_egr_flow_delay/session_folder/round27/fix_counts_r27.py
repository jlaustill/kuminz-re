"""Round 27 review fixes: the named-bit and named-access counts (316 -> 301 in words 1-49, word 0's 15 names,
674 / 109 -> 780 references = 656 tests / 108 writes / 16 other), the dotted-rows lead, the commit-message note.
Idempotent.  usage: fix_counts_r27.py <repo> <pr_body.md>"""
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


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "  - 316 bits have e2m 1036 names (the uncertain expansions checked against the bits' setters); the others are\n"
        "    `fault_<n>`.",
     "  - 301 bits of words 1-49 have e2m 1036 names (the uncertain expansions checked against the bits' setters); the\n"
     "    others are `fault_<n>`. Word 0's 15 named bits stay in its comment.")
edit(T, "  - The measured trade: 674 tests and 109 writes now name their fault, against 943 piece tokens. 856 of those are the\n"
        "    set / clear writes, which Ghidra 12.1 does not fold.",
     "  - The measured trade: 780 bit-name references (656 in tests, 108 in writes, 16 elsewhere) against 943 piece\n"
     "    tokens. 856 of those are the set / clear writes, which Ghidra 12.1 does not fold; the other 87 are tests and\n"
     "    whole-word uses.\n"
     "  - The stage B commit message (2eb75f6) says 316 named bits and 674 tests / 109 writes. The right figures are 301\n"
     "    (words 1-49) and 780 references: the proof's 674 counts both sides of a bit-to-bit compare.")
edit(T, "  - Word 0's seven named bits (RAM image word, fuel shutoff, turbocharger wastegate driver 1, fuel pressure idle,\n"
        "    HPCR OBD deviation) stay in its comment. The indexed accesses keep it a plain word.",
     "  - Word 0's 15 named bits (faults 0-4 and 6-15: the RAM image word, fuel shutoff, turbocharger wastegate driver 1,\n"
     "    air fuel control low boost, fuel pressure idle, boost / sampled throttle / oil pressure high and low, HPCR OBD\n"
     "    deviation) stay in its comment. The indexed accesses keep it a plain word.\n"
     "  - The 72 dotted documentation rows `fault_*_cal.faults_A_to_B` in global_variables.csv name the word addresses;\n"
     "    only word 0 is still a field. The importer skips them; rename or drop them with the next fault-word change.")
edit(pr, "(316 e2m names, the rest\n  `fault_<n>`). 674 tests and 109 writes are named; 943 piece tokens, 856 of them on set / clear writes.",
     "(301 e2m names, the rest\n  `fault_<n>`). 780 bit-name references (656 tests, 108 writes, 16 other); 943 piece tokens, 856 of them on\n"
     "  set / clear writes.")
edit("firmware/CLAUDE.md",
     "        - **What it gained:** 674 tests and 109 writes now name their fault (`fault_detected_cal.coolant_temperature_high_error == 0`).",
     "        - **What it gained:** 780 bit-name references (656 in tests, 108 in writes, 16 elsewhere), such as\n"
     "          `fault_detected_cal.coolant_temperature_high_error == 0`.")
m = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/typing_focus_2026_11.md"
edit(m, "Trade: 674 tests + 109 writes named vs 943 pieces (856 on set / clear writes).",
     "Trade: 780 bit-name references (656 tests / 108 writes / 16 other; 301 e2m-named bits in words 1-49) vs 943 "
     "pieces (856 on set / clear writes).")
print("counts fixed")
