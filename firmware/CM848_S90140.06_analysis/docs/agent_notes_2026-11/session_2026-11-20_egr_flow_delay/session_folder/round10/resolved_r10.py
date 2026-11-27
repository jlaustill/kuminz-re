"""Append a 'Resolved by PR #53 round 10' section to the task files that cite round 10's old names (the text above
each section keeps its wording). usage: resolved_r10.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
SECTIONS = {
    "work/tasks/025-cm848-naming-wave-followups.md": [
        ("j1939_fault_state", "governor_pressure_rationality_monitor_state (e2m 8C56 +2, typed DIAGNOSTIC_MONITOR_STATE)"),
        ("j1939_fault_state_cycle_divider", "governor_pressure_rationality_cycle_divider"),
        ("j1939_load_protection_fault_reported_flag", "governor_pressure_rationality_tested_in_park_neutral_flag"),
        ("cm848_evaluateProtectionFaultCondition", "cm848_updateTransmissionRelayRequest (output 16 is the transmission "
                                                    "relay: P0883 / P0882 'TCM power input', DRB test 13-43)"),
        ("cm848_processCalibrationTablesMain", "cm848_updateTransmissionControlState"),
        ("cm848_processProtectionStateMachine", "cm848_runTransmissionControlWhenEnabled"),
    ],
    "work/tasks/027-cm848-naming-wave-2-followups.md": [
        ("protection_rpm_limit_table_ramp_state", "governor_pressure_manual_2nd_curve_cached_axis_offset (the lookup "
                                                   "cache of the manual 2nd curve)"),
    ],
    "work/tasks/042-table-campaign-rename-leads.md": [
        ("cm848_initProtectionFilterValues", "cm848_initializeAlternatorFieldControl"),
    ],
}
for rel, pairs in SECTIONS.items():
    p = os.path.join(repo, rel)
    text = open(p).read()
    assert "## Resolved by PR #53 round 10" not in text, rel
    lines = ["", "## Resolved by PR #53 round 10 (2026-11-21)", "",
             "The old names this file cites were renamed in PR #53 round 10 (the text above keeps its wording):"]
    lines += [f"- `{old}` → `{new.split(' ')[0]}`" + (f" {new[len(new.split(' ')[0]):].strip()}" if " " in new else "")
              for old, new in pairs]
    open(p, "w").write(text.rstrip("\n") + "\n" + "\n".join(lines) + "\n")
    print(rel, len(pairs))
