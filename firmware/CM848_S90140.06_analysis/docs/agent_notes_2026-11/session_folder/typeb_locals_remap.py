"""Put the Type B sensor-channel local rows back with the auto-names of the current decompilation (read from a build
without them): the kernel-table cut renumbered the temporaries, which made the old rows land on the wrong variables.
usage: typeb_locals_remap.py <saved rows.csv> <local_variables.csv>"""
import sys

saved, path = sys.argv[1:3]
NEW_OLD_NAME = {
    "0x00501b4c": {"channel_word_index": "iVar7", "high_fault_word_index": "iVar8", "low_fault_word_index": "iVar6",
                   "validation_state": "sVar3", "sensor_value": "uVar9", "dispatch_index": "uVar5", "sensor_scratch": "wVar4",
                   "ema_result": "dVar2", "scratch16": "uVar1"},
    "0x005012dc": {"channel_word_index": "iVar9", "high_fault_word_index": "iVar8", "low_fault_word_index": "iVar7",
                   "validation_state": "sVar5", "sensor_value": "uVar10", "dispatch_index": "uVar3", "sensor_scratch": "wVar6",
                   "ema_result": "dVar4", "scratch16": "uVar1", "recovery_decrement": "uVar2",
                   "debounce_transition_state": "unaff_r29"},
}
rows = []
for line in open(saved).read().split("\n"):
    if not line:
        continue
    p = line.split(",", 5)
    p[2] = NEW_OLD_NAME[p[0]][p[3]]
    rows.append(",".join(p))
assert len(rows) == 20
lines = open(path).read().split("\n")
tail = lines.pop() if lines and lines[-1] == "" else None
lines += rows
if tail is not None:
    lines.append(tail)
open(path, "w").write("\n".join(lines))
print(f"{len(rows)} rows restored with the current auto-names")
