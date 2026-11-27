"""Round 88 stage A2 (CM550): type the A/D channel record walkers. Stage A typed cm550_exponentialMovingAverage's
record parameter ema_filter_state_t *, so the two functions that walk the 22-byte A/D channel records (0x80a2aa +
22 x channel) with one pointer and pass it to the filter inferred that 8-byte type, and the stride and the record's
later fields rendered as &record[2].accumulator + 2 / &record[1].accumulator + 3. These rows type each walker as
sensor_debounce_state_t * (the 22-byte record: the filter at +0, then the filtered value, the lookup result, the
debounce count, the flags and the raw counts; offsets verified by the round 87 skeptic). The auto-names are this
build's. Idempotent. usage: apply_r88a2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
L5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/local_variables.csv")
R = "PR #53 round 88"
ROWS = [
    "0x0000b7bc,validateServiceDataLength,filter_state,channel_record,sensor_debounce_state_t*,The A/D channel record "
    "this pass works on (0x80a2aa + 22 x channel; one per channel up to 0x80a4d0): its filter at +0 goes to "
    f"cm550_exponentialMovingAverage ({R})",
    "0x0000bcf0,cm550_initADCChannelConfiguration,peVar3,channel_record,sensor_debounce_state_t*,The A/D channel record "
    f"each of the three start-up loops walks (0x80a2aa + 22 x channel; up to 0x80a4d0) ({R})",
]
lines = open(L5, newline="").read().split("\n")
for row in ROWS:
    if row in lines:
        continue
    address = int(row.split(",")[0], 16)
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > address:
            lines.insert(i, row)
            break
    else:
        lines.insert(len(lines) - 1 if lines[-1] == "" else len(lines), row)
open(L5, "w", newline="").write("\n".join(lines))
print("walker rows applied")
