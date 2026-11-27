"""Round 47 stage B: refresh_references.py rewrote the old dword's name inside three texts that described its two
words; restore readable text (the old name kept inside a protected '(was' note). Idempotent.
usage: fix_r47b_texts.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
fixes = [
    ("function_renames.csv", "egr_cooler_fouled_flag (second word of egr_off_allowed_flag) is set at the maximum",
     "egr_cooler_fouled_flag is set at the maximum"),
    ("function_renames.csv", "and the first word of egr_off_allowed_flag when either of the two state words is 1.",
     "and egr_off_allowed_flag when either of the two state words is 1."),
    ("global_variables.csv", "The second word of the old dword egr_off_allowed_flag (PR #53 round 47)",
     "(was the second word of the dword fuel_blend_correction_inhibit_flag; PR #53 round 47)"),
]
for name, old, new in fixes:
    p = os.path.join(out, name)
    t = open(p).read()
    if new in t and old not in t:
        continue
    assert t.count(old) == 1, (name, old[:50], t.count(old))
    open(p, "w").write(t.replace(old, new))
print("texts fixed")
