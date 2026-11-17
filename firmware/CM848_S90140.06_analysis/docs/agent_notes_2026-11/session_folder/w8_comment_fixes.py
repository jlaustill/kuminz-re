"""Wave 8: the split-word rows' comments describe the old dwords in the present tense; say what they are now.
usage: w8_comment_fixes.py <output dir>"""
import sys

p = f"{sys.argv[1]}/global_variables.csv"
t = open(p).read()
FIX = [
    ("today the row is the label sensor_channel105_fault_combined+2 of a mis-sized dword",
     "it was the label row sensor_channel105_fault_combined+2 inside the mis-sized dword at 0x40a662 (now the word egr_delta_pressure_state)"),
    ("second word of the mis-sized dword throttle_fuel_rate_b (the row now is the label throttle_fuel_rate_b+2)",
     "second word of the old mis-sized dword at 0x3fa172 (throttle_fuel_rate_b, now the word egr_assist_controller_unstaged_output; this was its label row throttle_fuel_rate_b+2)"),
    ("second word of the mis-sized dword cold_start_enable_flag_b (the row is the label cold_start_enable_flag_b+2)",
     "second word of the old mis-sized dword at 0x3fa7ca (cold_start_enable_flag_b, now the word egr_valve_h_bridge_fault_retry_active_flag; this was its label row cold_start_enable_flag_b+2)"),
    ("second word of the mis-sized dword cold_start_valid_flag (row = label cold_start_valid_flag+2)",
     "second word of the old mis-sized dword at 0x3fa7bc (cold_start_valid_flag, now the word egr_valve_h_bridge_fault_reset_flag; this was its label row cold_start_valid_flag+2)"),
    ("second word of the mis-sized dword cold_start_timing_active_flag (row = label cold_start_timing_active_flag+2)",
     "second word of the old mis-sized dword at 0x3fa7d0 (cold_start_timing_active_flag, now the word egr_valve_h_bridge_fault_counter_decrement_enabled_flag; this was its label row cold_start_timing_active_flag+2)"),
    ("ema_filter_state_t_003fbd10.coefficient points here", "egr_valve_position_command_diagnostic_filter_state.coefficient points here"),
]
for old, new in FIX:
    assert t.count(old) == 1, old[:60]
    t = t.replace(old, new)
open(p, "w").write(t)
print(f"fixed {len(FIX)} comments")
