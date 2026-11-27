"""Round 89 stage C3 (CM550): no local rows for cm550_initializeAnalogSensorChannels (0xbcf0). With the 25
sensor_state_t / sensor_config_t instances its three start-up loops share one sensor_state_t * and one
sensor_config_t * that the decompiler types by itself (build C1: psVar3 / psVar2 in every loop). Committing either
splits it: build C2 named it in the first loop only and kept psVar3 / psVar2 in the others (round 88's channel_record
row had split it the same way: channel_record in loop 1, peVar3 in loops 2 and 3). Both rows go: round 88's
walker row and stage C2's config row. Idempotent. usage: drop_bcf0_rows_r89.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
lines = open(L5, newline="").read().split("\n")
keep = [l for l in lines if not l.startswith("0x0000bcf0,cm550_initializeAnalogSensorChannels,")]
open(L5, "w", newline="").write("\n".join(keep))
print(len(lines) - len(keep), "rows removed")
