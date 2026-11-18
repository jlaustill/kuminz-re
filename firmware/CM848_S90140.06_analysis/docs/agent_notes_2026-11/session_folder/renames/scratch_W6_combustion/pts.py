import csv
import sys
sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
g = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        g[r[1]] = r
for n in ["governor_integrator_rpm_output", "protection_recovery_threshold_cal", "protection_threshold_lookup_rpm",
          "protection_threshold_scale_working", "protection_base_threshold_working"]:
    r = g.get(n)
    print(n, r[0:3] if r else None, "|", (r[3][:300] if r and len(r) > 3 else ""))
    if r:
        a = int(r[0], 16)
        print("   dump word:", w(a), "rpm =", w(a) * 0.125)

print("torque grid unique:", uniq(0x405d9c, 304, True))
print("torque x axis rpm:", [v * 0.125 for v in axis(0x405d52)])
print("torque y axis fuel mm3:", [round(v * 0.0679, 1) for v in axis(0x405d7a)])
print("chi max fuel points dump:", [w(0x40a502 + 2 * i) for i in range(5)], [w(0x40a50c + 2 * i) for i in range(5)])
