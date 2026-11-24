"""Round 78 stage A3 (CM550): io_control_bit0_state (0x80D03E) is a dword. All 15 accesses the removed oversize type
had rendered were fuel_arbitrator_throttle_override._8_4_ (4 bytes at 0x80D036 + 8). vp44_rpmTimerInterruptHandler2,
vp44_FUN_00019e90 and vp44_FUN_0001a52c add the 32-bit _io_control_handshake_state into it with an overflow check.
0x80D040 (io_control_bit1_state, a label-only row) lies inside it; no access of its own was found.
Idempotent. usage: apply_r78a3.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
R = "PR #53 round 78"
for old, new in (("0x0080d03e,io_control_bit0_state,,",
                  "0x0080d03e,io_control_bit0_state,dword,(typed dword: its 15 accesses were 4 bytes - the removed "
                  "fuel_arbitrator_diag_t rendered them as fuel_arbitrator_throttle_override._8_4_; three functions add "
                  "the 32-bit _io_control_handshake_state into it with an overflow check - the name is older and not "
                  f"checked against that; {R})"),
                 ("0x0080d040,io_control_bit1_state,,",
                  "0x0080d040,io_control_bit1_state,,(inside the io_control_bit0_state dword - no access of its own "
                  f"found; {R})")):
    if new not in s:
        assert s.count(old) == 1, (old, s.count(old))
        s = s.replace(old, new)
open(p, "w", newline="").write(s)
print("round 78 stage A3 applied")
