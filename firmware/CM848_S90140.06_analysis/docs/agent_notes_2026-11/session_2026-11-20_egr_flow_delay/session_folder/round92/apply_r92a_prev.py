"""Round 92 stage A side rows (CM550): the two previous-pass copies of fueling states, found through stage B's enum
(they rendered _DAT_008000fe / _DAT_0080d33c next to typed carriers). Both are word accesses in every reference
(abs_refs_r92.py). Names follow CM848's rows for the same roles. Idempotent. usage: apply_r92a_prev.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 92"
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
ROWS = [
    (0x008000fe, "0x008000fe,user_fueling_state_previous_pass,FUELING_STATE,user_fueling_state of the last "
     "cm550_runAllSpeedGovernor pass: its last store (move.w (0x80ded4).l at 0xd0ce). The governor compares it with the "
     "current state (cmp.w at 0xc9a8 / 0xcbac) and cm550_dzgTimingAndPressureControlStateMachine with 7 (cmpi.w at "
     f"0xc8bc). CM848's engine_operating_mode_previous_pass (0x3fa0ec) has the same role ({R})"),
    (0x0080d33c, "0x0080d33c,final_fueling_state_prev,FUELING_STATE,final_fueling_state of the last pass: "
     "fuelTimingOilPressureModeController tests it for the entry into the low speed governor (cmpi.w #11 at 0x1c2e4) and "
     "then stores the current state (move.w at 0x1c2fc); selectHighSpeedGovernorGainSet reads it (cmpi.w #12 at "
     f"0x1d3d0). The twin of CM848's final_fueling_state_prev (0x40a2de) ({R})"),
]
lines = open(G, newline="").read().split("\n")
names = {l.split(",")[1] for l in lines if l.startswith("0x")}
added = 0
for a, row in ROWS:
    if any(l.startswith(row.split(",")[0] + ",") for l in lines):
        continue
    assert row.split(",")[1] not in names, row.split(",")[1]
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < a]
    lines.insert(after[-1] + 1, row)
    added += 1
open(G, "w", newline="").write("\n".join(lines))
print(added, "rows added")
