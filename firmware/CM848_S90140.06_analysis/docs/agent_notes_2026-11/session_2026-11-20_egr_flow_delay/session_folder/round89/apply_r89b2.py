"""Round 89 stage B2 (CM550): name the A/D loops' config pointers. With the 25 sensor_config_t instances typed, the
pointer each loop walks the configs with infers sensor_config_t * (auto-names psVar7 / psVar2 in build 1, as the
investigator expected); the rows name it channel_config. Idempotent. usage: apply_r89b2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
R = "PR #53 round 89"
ROWS = [
    "0x0000b7bc,mc68k_processAnalogSensorChannels,psVar7,channel_config,sensor_config_t*,The A/D channel config record "
    f"this pass reads (0x806ae2 + 24 x channel; stepped with channel_record) ({R})",
    "0x0000bcf0,cm550_initializeAnalogSensorChannels,psVar2,channel_config,sensor_config_t*,The A/D channel config record "
    f"the first and third start-up loops read (0x806ae2 + 24 x channel) ({R})",
]
lines = open(L5, newline="").read().split("\n")
for row in ROWS:
    if row in lines:
        continue
    address = int(row.split(",")[0], 16)
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) <= address]
    lines.insert((after[-1] + 1) if after else len(lines), row)
open(L5, "w", newline="").write("\n".join(lines))
print("config pointer rows applied")
