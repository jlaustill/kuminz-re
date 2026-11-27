"""Round 89 stage C3 (CM550): sensor_state_t.reserved_18 as one dword instead of byte[4]. Build C1 showed the
decompiler using the byte array as the base of byte arithmetic once the 25 records were typed: the array-end bound
0x80a4cf rendered as (operational_amplifier_and_comparator_supply_voltage_sensor_state.reserved_18 + 3) in both A/D
loops, and insiteCommandByteDispatcher's indexed read of channel n's filtered value (0x80a2b2 + 22 x n) as
intake_manifold_temperature_sensor_state.reserved_18 + 22 x n - 10. The 4 bytes have no access either way.
Idempotent; keeps CRLF. usage: apply_r89c3.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
S5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/structure_definitions.csv")
s = open(S5, newline="").read()
old = ("sensor_state_t,,reserved_18,byte,4,+18-+21: no access; 0 in all 25 dumped records (was reserved_12 - the hex "
       "offset; PR #53 round 88),,verified")
new = ("sensor_state_t,,reserved_18,dword,4,+18-+21: no access; 0 in all 25 dumped records. One dword: as byte[4] the "
       "decompiler made it the base of byte arithmetic (the array end and indexed channel reads) (was reserved_12 - the "
       "hex offset; PR #53 round 88; byte[4] until round 89),,verified")
if new not in s:
    assert s.count(old) == 1
    s = s.replace(old, new)
    open(S5, "w", newline="").write(s)
print("reserved_18 is a dword")
