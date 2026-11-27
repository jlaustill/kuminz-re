"""Append the round 10 entry to typing_focus_2026_11.md and update the MEMORY.md index line (commit count, round 10).
usage: memory_round10.py <memory dir>"""
import os
import sys

d = sys.argv[1]
p = os.path.join(d, "typing_focus_2026_11.md")
text = open(p).read()
assert "- Round 10 (2026-11-21" not in text
entry = """- Round 10 (2026-11-21, next 'keep going'): 3be5a5e (A: the 78 RE lookup caches named after their tables) / b9df152 (B: 26 RE cals i16 by the lha rule via round10/re_audit.py, 98 label-only rows typed, transmission_1_2_shift_lag_cal word[6] at 0x3fede2) / c9e793d (C: every cache suffix = <table>_cached_axis_offset, 127 rows; _interp_state is an invented short form; output 16 = transmission_relay_request; the transmission controller's phase functions; the P1762 / P1756 / P1757 j1939_ / protection_coldStart_ words) / 4ff8174 (E: P1740 monitor words; the SCI 0x13 actuator tests named from the DRB db) / ee328b7 (D: DIAGNOSTIC_MONITOR_STATE on 6 monitor states, the e2m 8C19 limp-home bit map in the byte comments, 23 more caches) / 84033f0 (F: sci_output_test_timers_t + word *timer prototypes, 0x3fceee dword) / 4c55b56 + 950298e (docs, the advisor's checks, verify byte-identical). 66 commits after round 10.
  - Method: the DRB database (mydb v_transaction, protocol 'SAE J2610 SCI', request '13-xx') names the SCI actuator tests, so their logical outputs. The DRB lists several names per code (it spans vehicles), so confirm each with the output's firmware requesters (cm848_setLogicalOutputRequest callers; round10/output_requesters.py). 4 = wait to start lamp, 38 = A/C clutch relay, 43 / 44 = intake heaters, 53 = lift pump, 16 = transmission relay.
  - Method: output check fault pairs name outputs: cm848_mainLoopMonitor calls diag_faultMatch_outputCheck_update(output, ?, high fault, low fault, ...); the two DTCs name the part (16 = P0883 / P0882 TCM power input).
  - Lesson: a struct over words passed by pointer needs the callee's pointer type to match the field type, or Ghidra prints raw constants (cm848_stopSciOutputTest(0x3fcf42,..)); fix with prototypes; prove with round10/relabel_struct.py + cast_normalized_diff.py.
  - Lesson: apply_hand_worklist.py aborts on any PROBLEM ('no code line uses it' for a _-prefixed row): rename such rows in a separate script with map rows for both spellings. Read firmware/CLAUDE.md before piloting a shape (the limp bitfield was already reverted in wave 11).
  - Open: the cam_sync_*_cal fuel metering tables and their caches (engine_sync_init_state_a/b/j/k/l/n, fuel_demand_interp_state_*), the end-of-line test sequencer (engine_coldStart_protection_stateMachine), the lift pump control names (protection_ambient_qualification 0x519cc4), bitfields for logical outputs 4 / 38 / 43 / 44 / 53, e2m 8C80 / 8C2D, the SCI high-speed table words.
"""
text = text.rstrip("\n") + "\n" + entry
open(p, "w").write(text)
m = os.path.join(d, "MEMORY.md")
mt = open(m).read()
old = "57 commits): 0x128a0"
assert mt.count(old) == 1, "index anchor"
mt = mt.replace(old, "66 commits): 0x128a0")
old2 = "the 8C19 flag structs); task 046 leads"
assert mt.count(old2) == 1, "round 9 anchor"
mt = mt.replace(old2, "the 8C19 flag structs) + round 10 (lookup caches = <table>_cached_axis_offset, i16 RE cals, "
                      "output 16 = the transmission relay, DIAGNOSTIC_MONITOR_STATE, the SCI 0x13 actuator tests named "
                      "from the DRB db, sci_output_test_timers_t); task 046 leads")
open(m, "w").write(mt)
print("memory updated")
