"""Round 20 stage F (the advisor's review), text fixes before typing word 11:
- F1: algorithm_enable_flags_11_cal's comment said 'clear on this truck (0x0000 in the dump)', written without reading
  the dump: the word is 0x000b (bits 0, 1, 3: proprietary, J1587 and J1939 communication), so J1939 communication is
  enabled, as the truck's J1939 traffic says;
- F3: word 19 bit 7's two e2m records (COT_Estimation_Enable, T_TPE_COT_Estimation_Enable) are one enable under two
  names; the generated comment said the reader rules one out.
usage: apply_r20f.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
FIXES = [
    ("global_variables.csv",
     "; clear on this truck (0x0000 in the dump), the other bits have no reader",
     "; set on this truck (0x000b in the dump: bits 0, 1 and 3 - proprietary, J1587 and J1939 communication), the other "
     "bits have no reader (stage C's comment said 0x0000 without reading the dump; corrected in stage F)"),
    ("structure_definitions.csv",
     "(the reader rules out the other record on this bit, T_TPE_COT_Estimation_Enable)",
     "(the e2m also names this enable T_TPE_COT_Estimation_Enable)"),
]
for name, old, new in FIXES:
    p = os.path.join(out, name)
    t = open(p).read()
    assert t.count(old) == 1, (name, t.count(old))
    open(p, "w").write(t.replace(old, new))
print("F1 + F3 applied")
