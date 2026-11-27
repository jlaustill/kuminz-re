"""Round 97 stage F hand edits (R7's follow-ups): the plate of CM848 0x1bd44 (it had none; the judge checked the
investigator's text against 0x1bd44 / 0x1bf44) and CM550's J1939_DIAGNOSTIC_SERVICE header (every member has CM848's
name now). usage: hand_edits_r97f.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    assert t.count(old) == 1, (rel, old[:60])
    open(p, "w", newline="").write(t.replace(old, new))
    print("edited", rel)


edit("firmware/CM848_S90140.06_analysis/output/function_renames.csv",
     "0x0001bd44,selectCrankExitSpeed,the twin of CM550 0x00017b8a: one shared name (was cm848_selectColdStartRpmLimit; PR #53 round 97)",
     "0x0001bd44,selectCrankExitSpeed,Crank exit speed on entry to CRANKING or REENTRY (third call of "
     "cm848_processColdStartAdjustment): crank_exit_speed (e2m 105E +12 CKEXES) = crank_exit_rpm (105F +E CKCNEXES) when "
     "crank_exit_speed_switch_cal (1254 +38 CKEXESSW) is 1, else low_speed_governor_reference.reference_speed. The twin "
     "of CM550 0x00017b8a: one shared name (was cm848_selectColdStartRpmLimit; PR #53 round 97)")
edit("firmware/CM550_J90350.00_analysis/output/enums.csv",
     "# J1939_DIAGNOSTIC_SERVICE (was EF00_SERVICE_ID - EF00 is the PGN in hex): renamed with CM848's in PR #53 round 63. "
     "The members below are CM550's own and unreviewed against its handlers",
     "# J1939_DIAGNOSTIC_SERVICE (was EF00_SERVICE_ID - EF00 is the PGN in hex): renamed with CM848's in PR #53 round 63. "
     "Every member below has CM848's member name, and its comment names the CM550 handler (the last six since PR #53 "
     "round 97)")
