"""Round 94: put the stage C proof summary into commit_r94c.txt. usage: fill_commit_r94c.py <commit_r94c.txt>"""
import sys

p = sys.argv[1]
s = open(p).read()
proof = """- CM848: the function set is unchanged (1968); every token change is in the apply's map (31 twin renames, the
  0x40ad56 rename, FUELING_STATE 37 / 38); statement counts, the caller census and the 1379 pieces are unchanged;
  no old name is left in the code (only in the plate comments' 'was' notes).
- CM550: the function set is unchanged (704). The token changes outside the map (81 functions) are typing effects,
  sorted by r94/classify_census_r94.py: 162 decompiler temporaries renumbered, 212 unnamed addresses now named or
  field paths, 47 numbers now enum members, 133 cast / index rewrites (pointer arithmetic to array elements and
  fields), and 334 more reviewed by hand (typed struct pointers, the control session copies, the lookup record
  initializers). Five functions changed their statement count, all from typing: the duty cycle histogram, the
  control session history copy, the TSC1 ignored request scan, the maximum torque map initializer (the removed
  can_buffer_setup_t's byte stores became the record's fields) and mc68k_initializeJ1939Datalink (a typed table
  pointer). The caller census shows no rise (unaff_ 13, extraout_ 27, CONCAT 132). Pieces 496 -> 494: the two new
  ones are the low-word reads of duty_cycle_monitor_load_ratio (move.w (0x800002) at 0xae4a). No old name is left in
  the code, and no row sits newly inside another row's span.
- Headers regenerated (g++ 0 errors); the _cal audit is 0 hard / 0 soft in both; the five Python suites and the 109
  JUnit tests pass."""
assert "PROOF_PLACEHOLDER" in s
open(p, "w").write(s.replace("PROOF_PLACEHOLDER", proof))
print("filled")
