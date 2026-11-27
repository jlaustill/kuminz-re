"""Round 7: the PR #53 memory entry. usage: memory_round7.py <memory dir> <commit count>"""
import os
import sys

d, count = sys.argv[1], sys.argv[2]
p = os.path.join(d, "typing_focus_2026_11.md")
s = open(p).read()
anchor = "  - Open: the J1939 monitor session record (e2m 10FE / 10FF / 1100,"
i = s.index(anchor)
j = s.index("\n", i)
add = ("\n- Round 7 (2026-11-21, next 'keep going'): 9d2ebdf (label: j1939mon 1100 words, retarder TSC1 handler words, "
       "cm848_resetEngineRetarderTsc1Request / cm848_endRetarderShiftAssistAboveFuelDemandLimit) / 9fd5621 (label: the "
       "drivetrain ratio module: drivetrain_ratio_filter_state, drivetrain_ratio_engine_period_valid_flag, "
       "drivetrain_gear_range = the gear-down range) / the type stage (j1939_control_session_t = the 24-byte j1939mon "
       "record behind length words; DRIVETRAIN_GEAR_RANGE; e2m 106D drivetrain cals; gear_down_gear_ratio_cal 0x3fd900).\n"
       "  - Lessons: function_definitions / local_variables type `int` = dword (use int32_t for signed); a struct-typed "
       "global makes Ghidra express base - 2 bytes as &p[-1].last_field + 2 -> type the local `byte *`; "
       "j1939_input_signal_timeouts[24] overlaps the history table's length word (tick off in this cal).\n"
       "  - Open: the transmission gear functions 0x3241c / 0x3257c (protection_* names), the engine run-state machine.")
s = s[:j] + add + s[j:]
s = s.replace(", 35 after round 6.", f", 35 after round 6, {count} after round 7.")
open(p, "w").write(s)
p = os.path.join(d, "MEMORY.md")
s = open(p).read()
a = "(cm848/egr-flow-delay-model, 35 commits)"
assert a in s
s = s.replace(a, f"(cm848/egr-flow-delay-model, {count} commits)")
a2 = "+ round 6 (TSC1 / ETC1 = e2m 10E8 Jcomm state: j1939_powertrain_control_state, processEngineTsc1Request, 3 enums); task 046 leads"
assert a2 in s
s = s.replace(a2, "+ round 6 (TSC1 / ETC1 = e2m 10E8 Jcomm state: j1939_powertrain_control_state, processEngineTsc1Request, 3 "
                  "enums) + round 7 (j1939mon session record struct, drivetrain gear-down range); task 046 leads")
open(p, "w").write(s)
print("ok")
