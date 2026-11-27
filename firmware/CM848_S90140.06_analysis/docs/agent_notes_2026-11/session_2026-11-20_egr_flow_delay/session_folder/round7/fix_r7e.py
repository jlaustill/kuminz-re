"""Round 7 closing 2 (the final review): comment fixes, one comment-only build.
- The session plates: param_1 is session_kind; the history table's length word is j1939_input_signal_timeouts[24].
- The zero torque timer: in limit control the test reads the previous torque limit.
- The retarder speed control flag: an inference (no e2m record covers 0x40ae20-0x40ae4c).
- The length rows: no direct load or store in the disassembly (e2m type T records).
- The top gear threshold: e2m 1185 +A's wording disagrees with the code's direction.
usage: fix_r7e.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
EDITS = {
    "function_renames.csv": [
        ("param_1 selects the session record: 0 is", "session_kind selects the session record: 0 is"),
        ("j1939_input_signal_timeouts + index x 12 + 24 words, which is the table at 0x3fead4 behind that 25 word array.",
         "j1939_input_signal_timeouts + index x 12 + 24 words: word 24 of that 25-word array is the history table's "
         "length word at 0x3fead4, and the first store lands one word later at the entry."),
        ("param_1 = 0 starts an engine control (TSC1) session:", "session_kind = 0 starts an engine control (TSC1) session:"),
        ("Any other param_1 does the same for the retarder control session", "Any other session_kind does the same for the retarder control session"),
    ],
    "structure_definitions.csv": [
        ("armed with the retarder request timeout while the requested torque (torque control) or the torque limit "
         "(limit control) is 0, cleared otherwise",
         "armed with the retarder request timeout when the stage-quantized torque request is 0 (torque control) or, in "
         "limit control, when the previous torque limit (read before this message updates it) is 0; cleared otherwise"),
        ("the retarder twin of tsc1_speed_control_flag: always written 0, since cm848_processEngineRetarderTsc1Request "
         "rejects speed control (SPN 695 = 1)",
         "inferred: the retarder twin of tsc1_speed_control_flag (no e2m record covers 0x40ae20-0x40ae4c). Always "
         "written 0, since cm848_processEngineRetarderTsc1Request rejects speed control (SPN 695 = 1)"),
    ],
    "global_variables.csv": [
        ("the record length 0x18 (24) in the EEPROM image; no code access found\n",
         "the record length 0x18 (24) in the EEPROM image; no direct load or store in the disassembly (an e2m type T "
         "record: tools read it through the parameter ID table)\n"),
        ("the record length 0x18 (24) in the EEPROM image; no code access found\n",
         "the record length 0x18 (24) in the EEPROM image; no direct load or store in the disassembly (an e2m type T "
         "record: tools read it through the parameter ID table)\n"),
        ("0x408b78), at most the e2m 106D +4 Gear_Ratio_Max_Limit; drivetrain_ratio below it = top gear",
         "0x408b78), at most the e2m 106D +4 Gear_Ratio_Max_Limit; drivetrain_ratio below it = top gear. e2m 1185 +A "
         "calls Top_Gear_Ratio the ratio ABOVE which the transmission is in top gear, but the code sets top gear BELOW "
         "the threshold; the period formula (VSS period / engine period) makes drivetrain_ratio engine speed / vehicle "
         "speed, lowest in top gear, so the code's direction holds. 0.8 / 1.0 are not checked against the truck's "
         "gearing"),
    ],
}
for name, pairs in EDITS.items():
    p = os.path.join(out, name)
    s = open(p).read()
    for a, b in pairs:
        n = s.count(a)
        assert n >= 1, (name, a[:60], n)
        s = s.replace(a, b, 1)
    open(p, "w").write(s)
    print(name, len(pairs), "edits")
