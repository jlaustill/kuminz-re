"""Round 6: the PR #53 memory entry. usage: memory_round6.py <memory dir>"""
import os
import sys

d = sys.argv[1]
p = os.path.join(d, "typing_focus_2026_11.md")
s = open(p).read()
anchor = "  - Open: the TSC1 / ETC1 vocabulary ("
i = s.index(anchor)
j = s.index("\n", i)
add = ("\n- Round 6 (2026-11-21, same 'keep going'): 47d462a / 247bebf / 2f5eec4 / 4ae5f79 + closing (hand work). The TSC1 / "
       "ETC1 lead resolved:\n"
       "  - e2m 10E8 ('Jcomm', 0x40adf4-0x40ae1f) + 10E6 (0x40ad5a) are Cummins' layout of `j1939_powertrain_control_state` (was "
       "j1939_tsc1_override_state / etc1_governor_state_t); 10E7 = the Jcomm timeouts. Check TSC1 / ETC1 names there FIRST.\n"
       "  - `processEngineTsc1Request` (was torqueControlModeHandler, shared CM550 0x2f128), `cm848_dispatchTsc1ByDestinationAddress`, "
       "`cm848_findTsc1SourceConfiguration` (SA whitelist `tsc1_source_configuration_table` 0x5c3b4, 10 entries), "
       "`cm848_runJ1939PowertrainControlTimeouts`, `cm848_lookupJ1939ControlDevice`.\n"
       "  - Enums TSC1_OVERRIDE_MODE (word now), J1939_CONTROL_DEVICE, CONTROL_NETWORK. Orphan structs etc1_state_t / governor_control_t "
       "deleted (the latter caused the _j1939_governor_source_index underscores).\n"
       "  - Lessons: Ghidra piece names count in DECIMAL (_10_2_ = +0xa); a multi-bit mask on a bitfield renders as a raw piece "
       "(_32_2_ & 3) -> keep masked flag words as words; apply_hand_worklist's gate rejects shared (unprefixed) function names and "
       "apply_renames.py fails on CM550 (no arrays.csv) -> edit CM550's row directly; global_variables.csv has dotted per-field alias "
       "rows (214) that a field rename must follow.\n"
       "  - Open: the J1939 monitor session record (e2m 10FE / 10FF / 1100, etc1_governor_* words at 0x3fbd6c.. and 0x3feb4e..), "
       "the retarder handler's two timers, the *Governor* reset functions of the TSC1 path.")
s = s[:j] + add + s[j:]
b = "21 commits after round 4, 28 after round 5 (title now names the cm550 twin)."
assert b in s
s = s.replace(b, "21 commits after round 4, 28 after round 5 (title now names the cm550 twin), 34 after round 6.")
open(p, "w").write(s)
p = os.path.join(d, "MEMORY.md")
s = open(p).read()
a = "PR #53 OPEN 2026-11-20 (cm848/egr-flow-delay-model, 28 commits)"
assert a in s
s = s.replace(a, "PR #53 OPEN 2026-11-20 (cm848/egr-flow-delay-model, 34 commits)")
a2 = "+ round 5 (J1939 builders vs PGNs, ASG gain set struct, vehicle_speed_sensor_type_cal); task 046 leads"
assert a2 in s
s = s.replace(a2, "+ round 5 (J1939 builders vs PGNs, ASG gain set struct, vehicle_speed_sensor_type_cal) + round 6 (TSC1 / ETC1 = "
                  "e2m 10E8 Jcomm state: j1939_powertrain_control_state, processEngineTsc1Request, 3 enums); task 046 leads")
open(p, "w").write(s)
print("ok")
