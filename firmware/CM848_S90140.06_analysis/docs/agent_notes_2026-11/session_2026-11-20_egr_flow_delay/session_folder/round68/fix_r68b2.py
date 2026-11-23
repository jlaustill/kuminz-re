"""Round 68 follow-up, second pass: two history notes the reference refresh rewrote. Idempotent.
refresh_references.py skips old labels after 'was' / 'were' / 'formerly' / 'old name', but not after 'named it':
- this round's '3be13ab6 named it boot_eeprom_status_block' became '... named it boot_ecm_part_number';
- round 66's follow-up (c48cc435) had turned '382fa677 named it net_combustion_torque_coolant_friction_scale' into
  '... named it coolant_torque_adjustment_factor'.
Both are rewritten in the protected form '(was <old> in <hash>)'.
usage: fix_r68b2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
G = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r68"
PAIRS = [
    (G, "(3be13ab6 named it boot_ecm_part_number; was eeprom_shadow_header.serial_number",
     "(was boot_eeprom_status_block in 3be13ab6; was eeprom_shadow_header.serial_number"),
    (G, "PR #53 round 66 - 382fa677 named it coolant_torque_adjustment_factor)",
     "PR #53 round 66 - was net_combustion_torque_coolant_friction_scale in 382fa677)"),
    (os.path.join(W, "fix_r68b.py"), "(3be13ab6 named it \"\n         \"boot_eeprom_status_block; was eeprom_shadow_header.serial_number",
     "(was \"\n         \"boot_eeprom_status_block in 3be13ab6; was eeprom_shadow_header.serial_number"),
]
for path, old, new in PAIRS:
    s = open(path).read()
    if new in s:
        continue
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(path, "w").write(s.replace(old, new))
print("history notes restored")
