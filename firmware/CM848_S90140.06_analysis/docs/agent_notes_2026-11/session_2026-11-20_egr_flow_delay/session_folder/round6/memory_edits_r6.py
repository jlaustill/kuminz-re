"""Round 6: point the memory notes at the renamed TSC1 / ETC1 names. usage: memory_edits_r6.py <memory dir>"""
import os
import sys

d = sys.argv[1]
edits = {
    "MEMORY.md": [("hardcoded in torqueControlModeHandler)",
                   "hardcoded in processEngineTsc1Request, was torqueControlModeHandler)")],
    "task022_phase3_findings.md": [
        ("`j1939_handlerInitializer(0, cm848_j1939DispatchAddressHandler)` → `torqueControlModeHandler` (primary SA dest).",
         "`j1939_handlerInitializer(0, cm848_dispatchTsc1ByDestinationAddress)` → `processEngineTsc1Request` (DA = the "
         "engine's own SA; the retarder SA goes to `cm848_processEngineRetarderTsc1Request`). Renamed 2026-11-21 (PR #53 "
         "round 6; were cm848_j1939DispatchAddressHandler / torqueControlModeHandler). The TSC1 state is "
         "`j1939_powertrain_control_state` = e2m 10E8 \"Jcomm\" block; the SA whitelist is "
         "`tsc1_source_configuration_table` (0x5c3b4, 10 entries).")],
    "cm848_cruise_drivetrain_type_fork.md": [
        ("`j1939_tsc1_override_state.etc2_transmission_selected_gear`",
         "`j1939_powertrain_control_state.etc2_transmission_selected_gear` (was j1939_tsc1_override_state.)"),
        ("cm848_processGovernorModeTransition,",
         "cm848_runJ1939PowertrainControlTimeouts (was cm848_processGovernorModeTransition),")],
}
for name, pairs in edits.items():
    p = os.path.join(d, name)
    s = open(p).read()
    for a, b in pairs:
        assert s.count(a) == 1, (name, a[:50], s.count(a))
        s = s.replace(a, b)
    open(p, "w").write(s)
    print(name, "ok")
