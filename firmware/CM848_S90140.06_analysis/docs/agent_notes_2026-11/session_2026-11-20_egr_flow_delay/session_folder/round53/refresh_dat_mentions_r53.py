"""Round 53: refresh_references.py never rewrites DAT_ labels, so comments and plates still named three rows this round
created by their DAT_ label. Replace each with the row's name. Idempotent.  usage: refresh_dat_mentions_r53.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
pairs = [("DAT_00408756", "coolant_overheat_recovery_temperature"),
         ("DAT_00408768", "coolant_overheat_level_timer_reset_time"),
         ("DAT_00408b78", "drivetrain_gear_ratio_detection_margin")]
total = 0
for name in ("function_renames.csv", "global_variables.csv"):
    p = os.path.join(out, name)
    t = open(p).read()
    for old, new in pairs:
        lines = t.split("\n")
        for k, line in enumerate(lines):
            # the row of the address itself keeps its own DAT_ reference out of its comment; only other rows change
            if old in line and not line.startswith(f"0x00{old[4:]},"):
                lines[k] = line.replace(old, new)
                total += 1
        t = "\n".join(lines)
    open(p, "w").write(t)
print(f"{total} lines refreshed")
