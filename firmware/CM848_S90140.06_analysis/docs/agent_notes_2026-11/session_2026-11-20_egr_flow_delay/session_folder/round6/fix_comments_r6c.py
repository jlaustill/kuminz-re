"""Round 6 closing: the comment references the scripted refreshes could not reach.
usage: fix_comments_r6c.py <CM848 output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "function_renames.csv": [
        ("j1939_powertrain_messages_received.auxiliary_state at 0",
         "j1939_powertrain_messages_received.etc2_actual_gear_ratio_previous at 0"),
        ("values kept in the *_transition_snapshot words (j1939_monitor_engine_override_control_mode_previous and so",
         "values kept in the j1939_monitor_engine_*_previous words (j1939_monitor_engine_override_control_mode_previous "
         "and so"),
    ],
    "local_variables.csv": [
        ("# cm848_lookupJ1939SourceAddressIndex @ 0x00053a4c", "# cm848_lookupJ1939ControlDevice @ 0x00053a4c"),
    ],
}
for name, pairs in EDITS.items():
    p = os.path.join(out, name)
    s = open(p).read()
    for a, b in pairs:
        assert s.count(a) == 1, (name, a[:60], s.count(a))
        s = s.replace(a, b)
    open(p, "w").write(s)
    print(name, len(pairs), "edits")
