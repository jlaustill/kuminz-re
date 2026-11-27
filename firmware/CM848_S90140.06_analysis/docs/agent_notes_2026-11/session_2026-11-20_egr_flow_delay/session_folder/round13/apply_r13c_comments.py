"""Round 13 stage C, comments only (the advisor's open items 6 and 7):
- the injector cutout claim: nothing counts the 0x3fcf64 words down (a search of both banks finds no access outside
  cm848_sciCommand37Callback, whose cancel loop reads them as 8 words), so 1000 is only a marker;
- the bit maps of end_of_line_test_enable_flags, the in-plant flag bytes (end_of_line_test_settings_t) and
  transmission_shift_strategy_flags.service_test_request_flags, from the step functions and the SCI 0x25 code;
- the SCI command 0x25 plates (DAT_003fcf60 is named now).
global_variables / function_renames: string edits (commas unquoted); structure_definitions: csv module per row.
usage: apply_r13c_comments.py <repo>"""
import csv
import io
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware", "CM848_S90140.06_analysis", "output")


def edit(path, old, new):
    text = open(path).read()
    assert text.count(old) == 1, (os.path.basename(path), old[:70], text.count(old))
    open(path, "w").write(text.replace(old, new))


gv = os.path.join(out, "global_variables.csv")
edit(gv, "1 on / 2 off (an injector: 2 cuts it out for 1000 passes and 1 restores it); 0 ends every test",
     "1 on / 2 off (an injector: 2 cuts it out - its word in the cutout table at 0x3fcf64 becomes 1000, a marker no "
     "code counts down, and its cylinder_cutout_test_mask bit is set - and 1 restores it); 0 ends every test")
edit(gv, "the number of injectors cut out by SCI command 0x25 tests 5-10 (cylinder_cutout_test_mask holds which)",
     "the number of injectors cut out by SCI command 0x25 tests 5-10: +1 when an injector's cutout word goes from 0 "
     "to 1000, -1 when one is cleared (cylinder_cutout_test_mask holds which)")
edit(gv, "test its bits 0x01 / 0x02 / 0x04 / 0x08 / 0x10 / 0x20 / 0x40 / 0x80 (grid heater ... (new row 2026-11-19, "
         "wave 12)",
     "test its bits 0x01 / 0x02 / 0x04 / 0x08 / 0x10 / 0x20 / 0x40 / 0x80 (grid heater ... (new row 2026-11-19, "
     "wave 12) | bit map (PR #53 round 13, from the step functions): bit 0 the intake air heater test / 1 the misfire "
     "test / 2 the wait-to-start lamp output test (output 4) / 3 the lift pump test (output 53; with it clear the "
     "output test step never leaves its lift pump state) / 4 the A/C clutch relay output test (output 38) / 5 the "
     "alternator test and the alternator field actuator test / 6 the fuel control actuator test / 7 the cooling fan "
     "actuator test; 0xfd here = every test but the misfire test")
fr = os.path.join(out, "function_renames.csv")
edit(fr, "installed by cm848_sciCommand37Handler (0x520ad8) - works on DAT_003fcf60 - reached only via "
         "sci_next_byte_handler",
     "installed by cm848_sciCommand37Handler (0x520ad8): the SCI command 0x25 service tool tests (DRB 25-xx). It "
     "collects two request bytes (sci_command_37_test_number / sci_command_37_requested_state, counted in "
     "sci_command_37_received_byte_count) and starts or stops one test: 0x11 alternator field / 0x14-0x16 the 48RE "
     "governor pressure / converter clutch / overdrive solenoids / 0x17 a 48RE anti-hunt request / 0x24 lift pump / "
     "0x25 cylinder contribution (DRB 25-25) / 0x26 high pressure safety valve (DRB 25-26) / 5-10 injector 1-6 cutout; "
     "0 ends every test. Each test sets a timeout that cm848_expireSciCommand37Tests counts down - reached only via "
     "sci_next_byte_handler")
sd = os.path.join(out, "structure_definitions.csv")
APPEND = {
    ("end_of_line_test_settings_t", "test_results_1"):
        " - bits 2-3 read by cm848_runEndOfLineFinalResultStep: bit 3 set = the plant tester's verdict is pending / "
        "bit 2 set = fail (clear = pass)",
    ("end_of_line_test_settings_t", "final_test_results_1"):
        " - bit 3: cm848_runEndOfLineTestStartStep goes to the final result step when no test is pending",
    ("end_of_line_test_settings_t", "test_flags_1"):
        " ($CC) - cleared to 0 by cm848_runEndOfLineTestStartStep",
    ("end_of_line_test_settings_t", "test_flags_2"):
        " ($CD): bit 3 = the output tests pending (cleared at the end of the output test step) / bit 4 = the output "
        "tests not passed (cleared when no DTC is stored) / bits 5 and 7 = the lift pump test not passed (cleared "
        "without P0629 / P0628); the start step keeps only bits 3-5 and 7",
    ("end_of_line_test_settings_t", "test_flags_3"):
        " ($CE): bit 5 = the alternator test pending (cleared after the test); the start step keeps only bit 5",
    ("end_of_line_test_settings_t", "test_flags_4"):
        " ($CF): bit 0 = the alternator test not passed (cleared on a pass and when end_of_line_test_enable_flags bit "
        "5 is clear); the start step keeps only bit 0",
    ("end_of_line_test_settings_t", "test_flags_5"):
        " ($D0): bit 0 = the intake air heater test pending / bit 1 = it has not passed / bit 4 = the misfire test "
        "pending / bit 5 = it has not passed (bits 0-1 and 4-5 are cleared when enable bit 0 / 1 is clear); the start "
        "step clears bits 2-3",
    ("transmission_shift_strategy_flags_t", "service_test_request_flags"):
        " - bit 0 is set by all three tests (the governor pressure solenoid under test control: test 0x14 drives it and "
        "0x15 / 0x16 hold it at its minimum duty) / bit 1 = the converter clutch solenoid test (0x15 / output 18) / bit "
        "2 = the overdrive solenoid test (0x16 / output 17); cm848_expireSciCommand37Tests clears bit 0 / bits 0-1 / "
        "bits 0 and 2 at each test's timeout (round 13)",
}
lines = open(sd).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if not l or l.startswith("#"):
        continue
    row = next(csv.reader([l]))
    key = (row[0], row[2]) if len(row) > 5 else None
    if key in APPEND:
        row[5] = row[5] + APPEND[key]
        s = io.StringIO()
        csv.writer(s, lineterminator="").writerow(row)
        lines[i] = s.getvalue()
        done += 1
assert done == len(APPEND), done
open(sd, "w").write("\n".join(lines))
print(f"3 global comments, 1 plate, {done} field comments")
