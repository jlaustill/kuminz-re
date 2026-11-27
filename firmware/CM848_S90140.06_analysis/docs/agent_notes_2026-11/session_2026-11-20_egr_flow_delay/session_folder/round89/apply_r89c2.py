"""Round 89 stage C2 (CM550): the A/D loops' local rows after the runtime records are typed. With the 25
sensor_state_t instances the start-up routine's three loops share one sensor_state_t * (auto-named psVar3: the round 88
row's old name peVar3 no longer exists), so the row moves to psVar3. The config pointers get their rows again (stage B2
failed while the state pointer was split): each sits right after its function's channel_record row, so the walker is
committed first. Idempotent. usage: apply_r89c2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
R = "PR #53 round 89"
lines = open(L5, newline="").read().split("\n")
CONFIG = {
    "0x0000b7bc": "0x0000b7bc,mc68k_processAnalogSensorChannels,psVar7,channel_config,sensor_config_t*,The A/D channel "
                  f"config record this pass reads (0x806ae2 + 24 x channel; stepped with channel_record) ({R})",
    "0x0000bcf0": "0x0000bcf0,cm550_initializeAnalogSensorChannels,psVar2,channel_config,sensor_config_t*,The A/D "
                  f"channel config record the first and third start-up loops read (0x806ae2 + 24 x channel) ({R})",
}
out = []
for line in lines:
    if line.startswith("0x0000bcf0,cm550_initializeAnalogSensorChannels,peVar3,channel_record,"):
        line = line.replace(",peVar3,channel_record,", ",psVar3,channel_record,", 1)
    out.append(line)
    address = line.split(",", 1)[0]
    if address in CONFIG and ",channel_record,sensor_state_t*," in line and CONFIG[address] not in lines:
        out.append(CONFIG[address])
open(L5, "w", newline="").write("\n".join(out))
print("rows:", sum(1 for l in out if l.startswith(("0x0000b7bc,", "0x0000bcf0,"))))
