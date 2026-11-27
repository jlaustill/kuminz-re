"""Round 92 pilot (CM550, thrown away after the build): does Ghidra 12.2 render bitfield names on 68000 code? Types
algorithm enable word 2 (0x803c98, e2m 106B +6) with the nine bits whose position its e2m records give; the other bits
are reserved_bit_N. usage: pilot_bitfield_r92.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
BITS = {0: "engine_protection_shutdown_enable", 1: "j1922_monitor_clear_enable",
        3: "power_take_off_does_not_override_shutdown_enable", 4: "engine_protection_enable",
        5: "engine_protection_restart_enable", 6: "engine_brake_enable", 13: "power_take_off_throttle_override_enable",
        14: "user_timing_enable", 15: "zero_vehicle_speed_power_take_off_engine_speed_limit_enable"}
S = os.path.join(O, "structure_definitions.csv")
s = open(S, newline="").read()
E = "\r\n" if "\r\n" in s else "\n"
if "algorithm_enable_flags_2_t,," not in s:
    rows = ["# pilot (round 92)"]
    for bit in range(16):
        name = BITS.get(bit, f"reserved_bit_{bit}")
        rows.append(f"algorithm_enable_flags_2_t,,{name},bitfield:1@{bit},{2 if bit == 0 else 0},bit {bit},,verified")
    s = s.rstrip("\r\n") + E + E + E.join(rows) + E
    open(S, "w", newline="").write(s)
G = os.path.join(O, "global_variables.csv")
g = open(G, newline="").read()
old = "0x00803c98,calibration_feature_enable_flags_word_2,undefined,"
new = "0x00803c98,calibration_feature_enable_flags_word_2,algorithm_enable_flags_2_t,"
if new not in g:
    assert g.count(old) == 1
    open(G, "w", newline="").write(g.replace(old, new))
print("pilot applied")
