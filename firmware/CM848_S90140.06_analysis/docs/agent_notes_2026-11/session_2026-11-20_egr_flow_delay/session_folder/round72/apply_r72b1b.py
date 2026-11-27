"""Round 72 stage B1b (from B1's CM550 build): the handlers' address rows named the decompiler's 'auStack_8' - the stack
variable is 'local_8' when the rows apply (the base build found local_8 and only failed its byte[2] type). The writer's
dword address already merged the two halves into one dword local_8; this names it. Idempotent; keeps line endings.
usage: apply_r72b1b.py <repo>"""
import os
import sys

P = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
s = open(P, newline="").read()
n = 0
for fn in ("0x000217de,handleJ1939WriteMemoryService", "0x00021826,handleJ1939WriteMemoryLongLengthService"):
    old, new = f"{fn},auStack_8,address,dword,", f"{fn},local_8,address,dword,"
    if new not in s:
        assert s.count(old) == 1, fn
        s = s.replace(old, new)
        n += 1
open(P, "w", newline="").write(s)
print(f"round 72 stage B1b applied ({n} rows)")
