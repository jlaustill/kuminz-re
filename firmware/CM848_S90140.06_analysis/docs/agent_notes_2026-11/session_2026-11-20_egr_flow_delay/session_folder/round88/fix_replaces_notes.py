"""Round 88 stage A fix: refresh_references.py rewrote the old names in the instance rows' "(replaces X at +n, ...)"
notes ("replaces" is not one of its history markers). Restore the old names, in its protected "(were a / b; ...)"
form, and switch apply_r88a.py's note to that form. Idempotent. usage: fix_replaces_notes.py <repo> <apply_r88a.py>"""
import os
import re
import sys

repo, script = os.path.abspath(sys.argv[1]), sys.argv[2]
G5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
R = "PR #53 round 88"
OLD = {
    "0x00800066": ["timing_table_4_ptr at +0", "timing_table_5_ptr at +6"],
    "0x0080006e": ["diagnostic_timing_increment_state at +2", "diagnostic_timing_increment_reserved at +4",
                   "fuel_parameter_pointer_3 at +6"],
    "0x00801a32": ["can_transmission_active_count at +4", "retarder_mode_priority_level at +6",
                   "retarder_control_priority_prev at +7"],
    "0x00801a5a": ["retarder_mode3_threshold_table at +0", "retarder_mode3_data_ptr at +2",
                   "lsg_speed_error_ema_accumulator at +4", "retarder_mode3_rpm_input at +6"],
    "0x00801a62": ["retarder_mode3_output_ptr at +0", "retarder_mode_timeout_value at +4",
                   "fuel_statistics_fault_counter at +6"],
    "0x0080a984": ["asg_droop_compensated_error_2000_2000 at +0", "asg_quadratic_derivative_adjustment_100_100 at +2",
                   "qpid_adjusted_asg_droop_compensated_error_derivative_2000_2000 at +6"],
}
s = open(G5, newline="").read()
for address, parts in OLD.items():
    m = re.search(rf"^({address},[^\n]*?)\((?:replaces|were) [^)]*\)$", s, re.M)
    assert m, address
    new = f"{m.group(1)}(were {' / '.join(parts)}; {R})"
    s = s[:m.start()] + new + s[m.end():]
open(G5, "w", newline="").write(s)
t = open(script).read()
old = 'note = f"(replaces {\', \'.join(replaced)}; {R})" if replaced else f"({R})"'
new = 'note = f"(were {\' / \'.join(replaced)}; {R})" if replaced else f"({R})"'
if new not in t:
    assert t.count(old) == 1
    open(script, "w").write(t.replace(old, new))
print("notes restored")
