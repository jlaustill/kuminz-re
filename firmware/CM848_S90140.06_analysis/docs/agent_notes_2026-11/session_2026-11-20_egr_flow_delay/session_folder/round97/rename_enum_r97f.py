"""Round 97 stage F pre-step: CM550's unused enum PROTECTION_STATE becomes ENGINE_PROTECTION_TASK (R5's judge), with
its header line; the apply then renames the members. usage: rename_enum_r97f.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/enums.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
OLD_HEAD = "# Protection State Machine - _protection_state_machine_index in engineProtectionMultiStateSlowCycle40Coordinator"
NEW_HEAD = ("# ENGINE_PROTECTION_TASK: the task index engine_protection_task_index (0x80060e) of "
            "cm550_runEngineProtectionScheduler, one task per call (was PROTECTION_STATE; PR #53 round 97)")
i = lines.index(OLD_HEAD)
lines[i] = NEW_HEAD
n = 0
for k, l in enumerate(lines):
    if l.startswith("PROTECTION_STATE,"):
        lines[k] = "ENGINE_PROTECTION_TASK," + l[len("PROTECTION_STATE,"):]
        n += 1
assert n == 5, n
open(p, "w", newline="").write(E.join(lines))
print("renamed", n, "rows")
