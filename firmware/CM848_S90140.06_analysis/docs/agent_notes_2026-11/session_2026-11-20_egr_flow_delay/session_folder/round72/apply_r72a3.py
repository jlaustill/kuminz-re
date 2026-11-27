"""Round 72 stage A3 (from stage A's CM550 build): a 'word' range_length moved the parameter to the stack slot's other
half - the body then read an in_stack_00000008 placeholder and the callers cast their argument to (word) - so it goes
back to uint (the callers push a word into the upper half of the 4-byte slot; the body shifts it down). Idempotent.
usage: apply_r72a3.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
P = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
R = "PR #53 round 72"
OLD = ("0x0003460e,lookupApplicationMemoryRegionType,1,range_length,word,Its length in bytes - a word: the body read the "
       f"upper half of a 4-byte stack slot (was operation_length uint; {R})\n")
NEW = ("0x0003460e,lookupApplicationMemoryRegionType,1,range_length,uint,Its length in bytes - in the upper half of the "
       "4-byte stack slot: the callers push a word and the body shifts it down (a word type moves the parameter to the "
       f"slot's other half; was operation_length; {R})\n")
s = open(P, newline="").read()
if NEW not in s:
    assert s.count(OLD) == 1
    open(P, "w", newline="").write(s.replace(OLD, NEW))
print("round 72 stage A3 applied")
