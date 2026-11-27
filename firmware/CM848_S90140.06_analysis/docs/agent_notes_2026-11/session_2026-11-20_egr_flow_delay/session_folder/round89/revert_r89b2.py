"""Round 89: take the two config-pointer local rows of stage B2 out again. Build B2 showed both failing: the
mc68k_processAnalogSensorChannels row never applied (committing channel_record renumbers the auto-names, so psVar7
was not there at apply time) and the cm550_initializeAnalogSensorChannels row split the pointer (channel_config in
one loop, psVar2 in the other). Without them both pointers stay one sensor_config_t * auto-named variable (build 1).
Idempotent. usage: revert_r89b2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
lines = open(L5, newline="").read().split("\n")
keep = [l for l in lines if not (l.startswith(("0x0000b7bc,", "0x0000bcf0,")) and ",channel_config,sensor_config_t*," in l)]
open(L5, "w", newline="").write("\n".join(keep))
print(len(lines) - len(keep), "rows removed")
