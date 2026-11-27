"""Round 93 closing: one sentence of the task 046 entry described the proof of all 52 removed rows as 'code runs
into it'; the switch case row is different (it follows an rts and is reached only through its jump table).
Idempotent. usage: fix_closing_wording_r93.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "work/tasks/046-cm848-egr-flow-estimate.md")
t = open(p).read()
old = ("    reaches it; a linear disassembly lands on it; the instruction before it does not leave; control flow from the\n"
       "    holding function's entry reaches it.")
new = ("    reaches it; a linear disassembly lands on it; the instruction before it does not leave; control flow from the\n"
       "    holding function's entry reaches it. (The switch case row follows an rts: only its jump table reaches it.)")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(p, "w").write(t.replace(old, new))
print("wording fixed")
