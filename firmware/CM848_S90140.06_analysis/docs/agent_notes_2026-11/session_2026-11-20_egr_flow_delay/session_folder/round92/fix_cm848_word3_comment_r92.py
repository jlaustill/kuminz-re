"""Round 92 stage A (CM848): the algorithm_enable_flags_3_cal row comment said 'bit 8 has no record (the road speed
governor without droops below top gear)'. The field is gear_down_protection_enable now (Cummins' label for that table
position in CM550's e2m and the later CHR_B2 files); the behaviour text stays. Idempotent.
usage: fix_cm848_word3_comment_r92.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
G = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
t = open(G, newline="").read()
old = "bit 8 has no record (the road speed governor without droops below top gear)"
new = ("bit 8 has no record in this e2m: gear_down_protection_enable (GRGDPNEN 'GEAR DOWN PROTECTION ENABLE' in CM550's "
       "e2m and Gear_Down_Protection_Enable in the later CHR_B2 files; here the road speed governor without droops below "
       "top gear) (PR #53 round 92)")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(G, "w", newline="").write(t.replace(old, new))
print("row comment updated")
