"""Round 27 stage B: a '#' note before fault_bit_words_t's rows (idempotent).
usage: add_struct_note_r27b.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
t = open(p).read()
old = "fault_bit_words_t,0x003fe974,faults_0_to_15,"
note = ("# fault_bit_words_t (PR #53 round 27, the user's decision): word 0 stays the plain word faults_0_to_15 (the base "
        "of the indexed accesses); words 1-49 are one bitfield per fault (fault n = bit n % 16 of word n / 16; e2m 1036 "
        "names, fault_<n> where the code does not resolve the name)\n")
if note not in t:
    assert t.count(old) == 1
    open(p, "w").write(t.replace(old, note + old))
print("note in place")
