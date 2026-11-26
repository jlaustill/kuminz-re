"""Round 97 stage E: the two R1 prototypes that have no rows yet (R1's judge CONFIRMED both). Inserted before the first
row of a higher address in function_definitions.csv order... appended to the round 96 block's end. usage: prototypes_r97e.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
assert not any(l.startswith(("0x000265e6,", "0x0002609c,")) for l in lines), "rows exist"
R = "(PR #53 round 97)"
rows = ["# PR #53 round 97 (batch R1): two low speed governor functions that take no arguments",
        f"0x0002609c,cm550_updateLowSpeedGovernorAggressiveGainLogic,return,,void,Returns nothing: its one caller cm550_loadLowSpeedGovernorGainSet ignores d0 (jsr 0x2609c at 0x262ae is followed at once by jsr 0x265e6); no stack arguments are read {R}",
        f"0x000265e6,selectLowSpeedGovernorTsc1GainSet,return,,ushort,1 = a TSC1 gain set is selected (moveq #1;d0 at 0x2660e) / 0 = none (clr.w d0 at 0x26612): the one caller keeps the word (move.w d0;d2 at 0x262ba) and passes it to selectLowSpeedGovernorOverrideGainSet; no stack arguments are read {R}"]
k = max(i for i, l in enumerate(lines) if l.startswith("0x")) + 1
lines[k:k] = rows
open(p, "w", newline="").write(E.join(lines))
print("ok")
