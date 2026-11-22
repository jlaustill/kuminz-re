"""Round 13 stage B (types): three enums from stage A's state words. Every value the code stores has a member (0 of the
output test state is only a case label).
- SERVICE_TOOL_TEST_STATE (size 1): e2m 8C74 +9 Cylinder_Performance_Test and 8C77 +1 HPSV_Test_Active, both
  '(0=NOT_RUN,1=RUN,2=ABORT)', on cylinder_contribution_test_status and high_pressure_safety_valve_test_state (bytes).
- END_OF_LINE_TEST_STEP (size 2) on end_of_line_test_step (word): the step functions of cm848_runEndOfLineTestSequence.
- END_OF_LINE_OUTPUT_TEST_STATE (size 1) on end_of_line_output_test_state (byte): cm848_runEndOfLineOutputTestStep.
String edits for global_variables.csv (commas unquoted); enums.csv rows are written with the csv module (quote-aware).
usage: apply_r13b_enums.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
ENUMS = {
    "SERVICE_TOOL_TEST_STATE": (1, "SERVICE_TOOL_TEST", [
        (0, "NOT_RUN", "e2m NOT_RUN: no service tool request (SCI command 0x25)"),
        (1, "RUNNING", "e2m RUN: requested and every condition holds"),
        (2, "ABORTED", "e2m ABORT: requested but a condition fails; cm848_expireSciCommand37Tests then ends the request"),
    ], "e2m 8C74 +9 Cylinder_Performance_Test / 8C77 +1 HPSV_Test_Active '(0=NOT_RUN,1=RUN,2=ABORT)': the state of a "
       "SCI command 0x25 service tool test (PR #53 round 13)"),
    "END_OF_LINE_TEST_STEP": (2, "END_OF_LINE_TEST_STEP", [
        (0, "START", "cm848_runEndOfLineTestStartStep: clears the flags of disabled tests and picks the first pending step"),
        (1, "OUTPUT_TESTS", "cm848_runEndOfLineOutputTestStep: lift pump / lamp and relay / intake air heaters"),
        (2, "INTAKE_AIR_HEATER_RESULT", "cm848_runEndOfLineIntakeAirHeaterResultStep: the two heater voltage drops"),
        (3, "ALTERNATOR_TEST", "cm848_runEndOfLineAlternatorTestStep: cuts the field and checks the voltage falls"),
        (4, "RADIATOR_FAN_SPEED_NOISE", "cm848_checkRadiatorFanSpeedSignalNoise"),
        (5, "MISFIRE_TEST", "cm848_runEndOfLineMisfireTestStep"),
        (6, "FINAL_RESULT", "cm848_runEndOfLineFinalResultStep: the plant tester's verdict on the MIL"),
        (7, "DONE", "no step runs"),
    ], "the step of cm848_runEndOfLineTestSequence; each step function returns the next (PR #53 round 13)"),
    "END_OF_LINE_OUTPUT_TEST_STATE": (1, "END_OF_LINE_OUTPUT_TEST", [
        (0, "IDLE", "a case that does nothing; no code stores 0"),
        (1, "START", "starts the fuel control / alternator field / cooling fan actuator tests and turns the MIL on"),
        (2, "LIFT_PUMP", "output 53 for end_of_line_test_lift_pump_on_time; passes without P0629 / P0628"),
        (3, "RELAYS", "the wait-to-start lamp (output 4) and the A/C clutch relay (output 38) for "
                      "end_of_line_test_relay_on_time"),
        (4, "BEFORE_INTAKE_AIR_HEATER_1", "end_of_line_test_relay_off_time, then heater 1 (output 43) on"),
        (5, "INTAKE_AIR_HEATER_1_ON", "heater 1 on for end_of_line_test_relay_on_time"),
        (6, "BEFORE_INTAKE_AIR_HEATER_2", "end_of_line_test_relay_off_time, then heater 2 (output 44) on"),
        (7, "INTAKE_AIR_HEATER_2_ON", "heater 2 on, then the output test verdict (no DTC stored)"),
        (8, "DONE", "done, or left early (engine not stopped / nothing pending)"),
    ], "the state of cm848_runEndOfLineOutputTestStep (PR #53 round 13)"),
}
ROWS = {
    "0x0040b765": ("cylinder_contribution_test_status", "byte", "SERVICE_TOOL_TEST_STATE"),
    "0x0040aed5": ("high_pressure_safety_valve_test_state", "byte", "SERVICE_TOOL_TEST_STATE"),
    "0x003fd1c4": ("end_of_line_test_step", "word", "END_OF_LINE_TEST_STEP"),
    "0x003fd1b2": ("end_of_line_output_test_state", "byte", "END_OF_LINE_OUTPUT_TEST_STATE"),
}


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


p = os.path.join(out, "enums.csv")
s = open(p).read()
members = {r[2] for r in csv.reader(l for l in s.split("\n") if l and not l.startswith("#")) if len(r) > 2}
block = []
for name, (size, prefix, items, about) in ENUMS.items():
    assert f"\n{name}," not in s, name
    block.append(f"# {name}: {about}")
    for value, member, comment in items:
        full = f"{prefix}_{member}"
        assert full not in members, full
        block.append(text_of([name, str(value), full, comment, str(size)]))
open(p, "w").write(s.rstrip("\n") + "\n" + "\n".join(block) + "\n")
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in ROWS:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        want_name, want_type, enum = ROWS[a]
        assert name == want_name and typ == want_type, (a, name, typ)
        lines[i] = ",".join([addr, name, enum, comment + f" | typed {enum} (was {typ}; round 13)"])
        done += 1
assert done == len(ROWS), done
open(gv, "w").write("\n".join(lines))
print(f"{len(ENUMS)} enums, {sum(len(v[2]) for v in ENUMS.values())} members, {done} rows typed")
