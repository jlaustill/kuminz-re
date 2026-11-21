"""Round 6 closing 2: the live old names in memory and the TSC1 time limit gate. usage: memory_edits_r6d.py <dir>"""
import os
import sys

d = sys.argv[1]
edits = {
    "task022_phase3_findings.md": [
        ("SPN 898 bytes[1-2] → `etc1_capped_speed_target` = min(requested_speed, 24000).",
         "SPN 898 bytes[1-2] → `j1939_powertrain_control_state.tsc1_requested_speed_capped` = min(requested_speed, "
         "24000) (was etc1_capped_speed_target)."),
        ("| SA whitelist (`0x0005c3b4`) | TSC1 if sender not in table |",
         "| SA whitelist (`0x0005c3b4` = `tsc1_source_configuration_table`, ROM image: 0x03 / 0x0B / 0x21 / 0x4A / 0x4F, "
         "entries 5-9 = 0xFE unused) | TSC1 if sender not in table |\n"
         "| TSC1 time limit (same table, +6 / +0xa, 10 ms counts) | speed control from 0x0B / 0x21 / 0x4A / 0x4F ends "
         "after 6 s (the sender is ignored until it sends override disabled); from 0x03 unlimited (0xFFFF); torque "
         "control 6 s for all; request timeout 50 ms (found 2026-11-21, PR #53 round 6) |"),
    ],
    "cm848_cruise_drivetrain_type_fork.md": [
        ("`j1939_tsc1_override_state` sat dead/timed-out.",
         "`j1939_powertrain_control_state` (was j1939_tsc1_override_state) sat dead/timed-out."),
    ],
    "typing_focus_2026_11.md": [
        ("  - Open: the J1939 monitor session record (e2m 10FE / 10FF / 1100,",
         "  - The TSC1 source table read from the ROM image: whitelist 0x03 / 0x0B / 0x21 / 0x4A / 0x4F; speed control "
         "unlimited only from 0x03, 6 s from the others (task 022 note updated).\n"
         "  - Open: the J1939 monitor session record (e2m 10FE / 10FF / 1100,"),
    ],
}
for name, pairs in edits.items():
    p = os.path.join(d, name)
    s = open(p).read()
    for a, b in pairs:
        assert s.count(a) == 1, (name, a[:60], s.count(a))
        s = s.replace(a, b)
    open(p, "w").write(s)
    print(name, "ok")
