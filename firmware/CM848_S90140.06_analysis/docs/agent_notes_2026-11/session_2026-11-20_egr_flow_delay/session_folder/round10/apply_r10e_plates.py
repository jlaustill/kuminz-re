"""Round 10 stage E: correct the plates of the two SCI 0x13 functions that keep their names (they run with the engine
stopped, not while cranking; the 'protection event' wording was the old cold-start guess). function_renames.csv is
split(",", 3), so the plate takes unquoted commas. usage: apply_r10e_plates.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "function_renames.csv")
lines = open(p).read().split("\n")
NEW = {
    "0x0051e894": ("cm848_sciStartTimedOutputTest",
                   "Starts one SCI 0x13 actuator test (timer pointer, logical output, duration in phases: 300 or 11): if "
                   "the test was not running it adds one to sci_output_test_active_count and drives the output request "
                   "at priority 5 on or off by sci_output_test_drive_phase_flag; then sets the timer. "
                   "cm848_updateSciOutputTests steps the timers"),
    "0x0051e914": ("cm848_sciCommand19OutputTestCallback",
                   "SCI diagnostic link next-byte callback: command 19 (0x13) actuator tests, only while the engine is "
                   "stopped (a running engine or code 0 stops all tests). Codes (DRB names): 0x09 A/C clutch relay "
                   "(output 38), 0x0c cruise vacuum + vent (19 + 20), 0x0f torque converter clutch (18), 0x16 overdrive "
                   "solenoid (17), 0x1a / 0x1b cruise vent / vacuum (19 / 20), 0x28 / 0x29 intake heater 1 / 2 (43 / "
                   "44), 0x2c cruise 12 volt feed (21), 0x33 fuel transfer pump (53), 0x43 transmission relay (16), "
                   "0x49 wait to start lamp (4), 0x5d exhaust brake (11), 0x5e fuel control and 0x5f PWM radiator fan "
                   "(flags with 11-phase countdowns); while a test runs it sets actuator_test_flags bit 0"),
}
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in NEW:
        addr, name, plate = (l.split(",", 2) + [""])[:3]
        assert name == NEW[a][0], (a, name)
        lines[i] = ",".join([addr, name, NEW[a][1] + f" | earlier note: {plate}"])
        done += 1
assert done == 2
open(p, "w").write("\n".join(lines))
print("2 plates corrected")
