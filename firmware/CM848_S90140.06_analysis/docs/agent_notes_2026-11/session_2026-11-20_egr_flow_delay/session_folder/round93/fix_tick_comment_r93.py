"""Round 93 (CM550): the plate comment of cm550_tickJ1939InputSupervision said it runs from two functions; the second
was a mid-body row of the first's task set (removed this round), so the refresh left the same name twice.
Idempotent. usage: fix_tick_comment_r93.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
t = open(p, newline="").read()
old = "Runs from vp44_evenPhaseSchedulerTaskSet and vp44_evenPhaseSchedulerTaskSet with no gate."
new = ("Runs from the task set vp44_evenPhaseSchedulerTaskSet (0x1b4d8; every second executive frame) with no gate.")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(p, "w", newline="").write(t.replace(old, new))
print("comment fixed")
