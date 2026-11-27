"""Round 39 closing: for each global_variables.csv row the reference refresh changed in stage C (rows outside the round's
own rewrites), print the changed words.  usage: refreshed_changes.py <stage_c_globals.diff>"""
import difflib
import sys

d = open(sys.argv[1]).read().split("\n")
minus = {l[1:11]: l for l in d if l.startswith("-0x")}
for l in d:
    if l.startswith("+0x") and "PR #53 round 39" not in l:
        old = minus.get(l[1:11], "")
        a, b = old[1:].split(" "), l[1:].split(" ")
        sm = difflib.SequenceMatcher(None, a, b)
        ch = [" ".join(a[i1:i2]) + " -> " + " ".join(b[j1:j2]) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal"]
        print(l[1:11], l.split(",")[1][:38], "|", "; ".join(c[:90] for c in ch)[:170])
