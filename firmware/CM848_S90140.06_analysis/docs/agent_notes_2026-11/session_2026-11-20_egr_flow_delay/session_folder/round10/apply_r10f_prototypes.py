"""Round 10 stage F, part 2: full prototypes for the three SCI actuator test helpers. The struct's word fields are
passed as `short *` (Ghidra's guess), and with that type mismatch the decompiler printed the field addresses as raw
constants (cm848_stopSciOutputTest(0x3fcf42,0x2b)). Every load of a timer is lhz (unsigned), so the parameter is a
word *. function_definitions.csv is quote-aware: comments with commas are quoted.
usage: apply_r10f_prototypes.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "function_definitions.csv")
text = open(p).read()
ROWS = [
    ("0x0051e624", "cm848_stepSciOutputTest", [
        ("return", "", "void", "No result"),
        ("0", "timer", "word *", "The test's timer in sci_output_test_timers (phases left; lhz: unsigned)"),
        ("1", "logical_output", "int", "The logical output the test drives (priority 5)"),
    ]),
    ("0x0051e490", "cm848_stopSciOutputTest", [
        ("return", "", "void", "No result"),
        ("0", "timer", "word *", "The test's timer in sci_output_test_timers; zeroed"),
        ("1", "logical_output", "int", "The logical output the test drove; its priority 5 request is cleared"),
    ]),
    ("0x0051e894", "cm848_sciStartTimedOutputTest", [
        ("return", "", "void", "No result"),
        ("0", "timer", "word *", "The test's timer in sci_output_test_timers"),
        ("1", "logical_output", "int", "The logical output to drive at priority 5"),
        ("2", "duration", "word", "Phases of 141 passes to run (300 or 11)"),
    ]),
]
for addr, name, params in ROWS:
    assert f"\n{addr}," not in text, addr
lines = []
for addr, name, params in ROWS:
    for index, pname, ptype, comment in params:
        c = f'"{comment}"' if "," in comment else comment
        lines.append(f"{addr},{name},{index},{pname},{ptype},{c}")
text = text.rstrip("\n") + "\n" + "\n".join(lines) + "\n"
open(p, "w").write(text)
print(len(lines), "prototype rows")
