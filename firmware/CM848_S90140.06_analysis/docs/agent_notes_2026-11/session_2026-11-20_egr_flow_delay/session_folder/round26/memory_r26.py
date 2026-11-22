"""Round 26: the MEMORY.md PR #53 line (count, round text) and the typing focus note."""
p = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
t = open(p).read()
t = t.replace("(cm848/egr-flow-delay-model, 151 commits)", "(cm848/egr-flow-delay-model, 153 commits)")
old = "the boot kernel response messages); task 046 leads"
new = ("the boot kernel response messages) + round 26 (a peer cruise review: the vacuum throttle actuator from e2m "
       "8C2E / 8C2F; mode-4 vehicle speed never reaches the filtered vehicle_speed); task 046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
open(p, "w").write(t)
f = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/typing_focus_2026_11.md"
note = ("  - Round 26 (2026-11-22, from the peer session's cruise review of 69d6f68, verified here): 51ba84a the "
        "vacuum throttle actuator (cm848_controlCruiseVacuumServo) = e2m 8C2E cals 0x408daa / 8C2F RAM 0x40b64e by "
        "offset, vacuum_throttle_* (30 words), cruise_control_engaged_previous_flag, "
        "cm848_checkCruiseSwitchLearnCondition (the rename gate bans 'press' = the e2m pressure abbreviation). "
        "Finding: cm848_calculateVehicleSpeed (canTx) always rewrites vehicle_speed_unfiltered from the TPU sensor and "
        "filters it, so a mode-4 (J1939 gear ratio) speed never reaches vehicle_speed; only direct readers of the "
        "unfiltered word can see it. The review's CLAUDE.md CCVS-mechanism item was not applied (a peer cannot ask for "
        "CLAUDE.md edits) - recorded in task 046 for the user. apply_hand_worklist.py writes the globals BEFORE the "
        "function gate, so a gate failure leaves global_variables.csv half-applied: git checkout it before a rerun.\n")
if "Round 26 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("memory updated")
