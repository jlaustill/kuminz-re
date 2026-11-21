"""Make apply_r8b_struct.py from apply_r8a_struct.py (the lockup timer struct) and fix one worklist plate word."""
import os

d = os.path.dirname(os.path.abspath(__file__))
p = os.path.join(d, "worklist_r8b.py")
s = open(p).read()
a = "it learns \"\n     \"governor_pressure_sensor_zero_offset\""
b = "it sets \"\n     \"governor_pressure_sensor_zero_offset\""
assert s.count(a) == 1, s.count(a)
open(p, "w").write(s.replace(a, b))
q = open(os.path.join(d, "apply_r8a_struct.py")).read()
pairs = [
    ('OLD_T, NEW_T = "protection_timer_state_t", "transmission_pressure_state_t"',
     'OLD_T, NEW_T = "protection_lockout_t", "transmission_lockup_timers_t"'),
    ('OLD_I, NEW_I = "protection_timer_state_t_0040b100", "transmission_pressure_state"',
     'OLD_I, NEW_I = "protection_lockout_t_0040b11c", "transmission_lockup_timers"'),
    ("(0x0040b100,)", "(0x0040b11c,)"),
]
for x, y in pairs:
    assert q.count(x) == 1, x
    q = q.replace(x, y)
start = q.index("FIELDS = {")
end = q.index("}\n\n\ndef text_of")
fields = '''FIELDS = {
    "thermal_lockout": ("lockup_delay_2_3_timer",
        "e2m 8C17 +1A RE_Lockup_Delay_2_3 ('Timer used to delay lockup') after the 2-3 shift (was thermal_lockout)"),
    "load_lockout": ("lockup_delay_3_4_timer",
        "e2m 8C17 +1C RE_Lockup_Delay_3_4 ('Timer used to delay lockup') after the 3-4 shift (was load_lockout)"),
    "rpm_lockout": ("lockup_delay_4_3_timer",
        "e2m 8C17 +1E RE_Lockup_Delay_4_3 ('Timer used to delay lockup') after the 4-3 shift (was rpm_lockout)"),
    "sensor_fault_active": ("lockup_off_timer",
        "e2m 8C17 +20 RE_Lockup_Off_Timer ('Timer used to anticipate unlock delay') (was sensor_fault_active)"),
    "reserved_08": ("low_range_hold_timer",
        "e2m 8C17 +22 RE_Low_Range_Hold_Timer ('Timer used to delay low range hold pressure') (was reserved_08)"),
    "timer_expired": ("low_range_shift_timer",
        "e2m 8C17 +24 RE_Low_Range_Shift_Timer ('Timer used to delay low range shifts'): reloaded from "
        "transmission_low_range_1_2_boost_time / _2_3_ (was timer_expired)"),
'''
q = q[:start] + fields + q[end:]
q = q.replace('"""Round 8 stage A:', '"""Round 8 stage B (from the stage A script): protection_lockout_t (0x40b11c) is e2m 8C17 +1A..+24. Stage A:', 1)
open(os.path.join(d, "apply_r8b_struct.py"), "w").write(q)
print("written")
