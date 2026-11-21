"""Round 8: the PR #53 memory entry. usage: memory_round8.py <memory dir> <commit count>"""
import os
import sys

d, count = sys.argv[1], sys.argv[2]
p = os.path.join(d, "typing_focus_2026_11.md")
s = open(p).read()
old_open = "  - Open: the transmission gear functions 0x3241c / 0x3257c (protection_* names), the engine run-state machine."
assert s.count(old_open) == 1
add = (old_open + " (Round 8 resolved the first.)\n"
       "- Round 8 (2026-11-21, next 'keep going'): the 48RE transmission controller, named protection_* until now. "
       "e848623 (label: anti-hunt mode cm848_selectGovernorPressureAntiHunt = 0x3257c, cm848_predictPostShiftAcceleration, "
       "cm848_calculateTransmissionOutputTorqueInGear, cm848_learnVehicleInertia = 0x3241c, transmission_pressure_state_t "
       "@ 0x40b100, 25 tables) / 1766051 (label: the rest of e2m 8BBC + 8C17: low range "
       "cm848_selectGovernorPressureLowRange = 0x2f920, lockup / WOT / cruise decel cals, transmission_lockup_timers_t, "
       "hot_mode_flag = transmission_overheat_protection_active_flag) / d542b7d (gear ratio table word[6], "
       "transmission_vehicle_inertia_default, cm848_initializeTransmissionShiftLogic).\n"
       "  - Method: Chrysler e2m RE_* blocks are NOT in the parameter ID table; align by relative offset and prove the base "
       "word by word by code use (round8/align_block.py). 8C53 +0 = 0x40b100 (table); 8C17 (RAM) = 0x40b102, good "
       "+0..+48; 8BBC (ROM cals) = 0x40780c, good +0..+5C; both drift after (11.45 vs this cal).\n"
       "  - Open: the pressure state enum (codes 1-0x18), cm848_protectionStateTransitionCheck (3-4 / 4-3 lines), "
       "cm848_calculateProtectionThresholdLimit, cm848_protectionCleanupHandler (3rd gear lockup), the "
       "protection_condition_flags_t / protection_status_flags_t bits, the RE_Cold / Cruise / Fuel_Economy / WOT / Lockup "
       "curves, blocks 8BB5 / 8BBB / 8BBD / 8C18 / 8C19.")
s = s.replace(old_open, add)
a = ", 35 after round 6, 40 after round 7."
assert s.count(a) == 1
s = s.replace(a, f", 35 after round 6, 40 after round 7, {count} after round 8.")
open(p, "w").write(s)
p = os.path.join(d, "MEMORY.md")
s = open(p).read()
a = "(cm848/egr-flow-delay-model, 40 commits)"
assert s.count(a) == 1
s = s.replace(a, f"(cm848/egr-flow-delay-model, {count} commits)")
a2 = "+ round 7 (j1939mon session record struct, drivetrain gear-down range); task 046 leads"
assert s.count(a2) == 1
s = s.replace(a2, "+ round 7 (j1939mon session record struct, drivetrain gear-down range) + round 8 (the 48RE transmission "
                  "controller from the e2m RE_ blocks 8BBC / 8C17 / 8C53: anti-hunt, low range, lockup, WOT); task 046 leads")
open(p, "w").write(s)
print("ok")
