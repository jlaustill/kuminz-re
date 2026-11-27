"""Round 13 stage A: the plates that still told the old story - cm848_runEndOfLineTestSequence's step list and its
seconds counter, and the misfire step's BYTE_003fd1ac. String edits only (function_renames.csv is split(",", 3)).
usage: apply_r13a_plates.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware", "CM848_S90140.06_analysis", "output", "function_renames.csv")
text = open(p).read()
EDITS = [
    ("it keeps the elapsed-seconds counter BYTE_003fd1ac (cleared in ENGINE_STATE_STOPPED, +1 per 10 passes) and runs "
     "end_of_line_test_step through its steps: 0 initialize, 1 cold start, 2 deviation check, 3 battery voltage, 4 "
     "radiator fan speed noise, 5 misfire test, 6 bit check. With any other field mode value it resets its state and "
     "the diag suppress request",
     "it keeps end_of_line_test_seconds_since_engine_start (+1 per 10 passes) and "
     "end_of_line_test_time_since_engine_start (0.1 s), both 0 while ENGINE_STATE_STOPPED, and runs "
     "end_of_line_test_step through its steps, each returning the next: 0 start (cm848_runEndOfLineTestStartStep), 1 "
     "output tests (cm848_runEndOfLineOutputTestStep), 2 intake air heater verdict, 3 alternator test, 4 radiator fan "
     "speed noise (cm848_checkRadiatorFanSpeedSignalNoise), 5 misfire test, 6 final result, 7 done. With any other "
     "field mode value it resets the step, the output test state and timers, the MIL override and its power-down "
     "flag"),
    ("waits for the elapsed seconds (BYTE_003fd1ac) to pass",
     "waits for the elapsed seconds (end_of_line_test_seconds_since_engine_start) to pass"),
]
for old, new in EDITS:
    assert text.count(old) == 1, old[:60]
    text = text.replace(old, new)
open(p, "w").write(text)
print(f"{len(EDITS)} plate edits")
