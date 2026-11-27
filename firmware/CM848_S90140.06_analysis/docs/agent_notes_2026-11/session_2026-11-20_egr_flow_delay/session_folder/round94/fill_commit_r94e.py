"""Round 94: put the stage E proof summary into commit_r94e.txt. usage: fill_commit_r94e.py <commit_r94e.txt>"""
import sys

p = sys.argv[1]
s = open(p).read()
proof = """- CM848: the function set is unchanged (1968). Every token change is in the map (19 function renames, 3 globals, the
  INSITE_PARAM_CODE member) except the new duty cycle axes in cm848_updateDutyCycleMonitorLoadHistogram
  (*(ushort *)(i * 2 + 0x5c2c0) -> duty_cycle_monitor_engine_speed_axis[i], likewise the load axis). Statement counts,
  the caller census and the 1379 pieces are unchanged.
- CM550: 704 -> 705 functions: the new row 0x33d38 (cm550_buildPgn65252ShutdownMessage) creates a function where no
  function was; nothing else is added or removed and no other function changes its statements apart from one. The token
  changes outside the map (38 functions) are typing effects, sorted by r94/classify_census_r94.py: 166 unnamed
  addresses now named or field paths, 97 cast / index rewrites, 8 temporaries renumbered and 84 reviewed by hand (the
  lookup records' field stores, scheduleJ1939PeriodicMessage where FUN_0001fe84 rendered before its row existed, typed
  table pointers, one local declaration reordered). cm550_updateDutyCycleMonitorLoadHistogram's speed axis loop is
  restructured (the pointer starts at the axis and steps in the loop condition instead of starting at element 1;
  the first compare is element 1 either way). The caller census shows no rise; the 494 pieces are unchanged.
- Both: no old name is left in the code; every new name renders; no row sits newly inside another row's span.
- Headers regenerated (g++ 0 errors); the _cal audit is 0 hard / 0 soft (CM550 12 missing, was 14: two removed rows);
  the five Python suites and the 109 JUnit tests pass."""
assert "PROOF_PLACEHOLDER" in s
open(p, "w").write(s.replace("PROOF_PLACEHOLDER", proof))
print("filled")
