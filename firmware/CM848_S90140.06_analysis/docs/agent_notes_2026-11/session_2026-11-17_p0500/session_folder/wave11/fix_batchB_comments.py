"""Batch B comment hygiene for the comment-name sweep: guessed / collapsed bit names become prose, stale function names
in agent evidence get their current names, and shorthand gets the real names. Usage: fix_batchB_comments.py <repo>"""
import os
import re
import sys

repo = sys.argv[1]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")


def edit(path, fn):
    text = open(path).read()
    new = fn(text)
    assert new != text, path
    open(path, "w").write(new)


def structures(text):
    # demoted guesses: "guess (not proven, so reserved): some_bit_name -" -> words
    text = re.sub(r"(guess \(not proven, so reserved\): )([a-z][a-z0-9_]+)( -)",
                  lambda m: m.group(1) + m.group(2).replace("_", " ") + m.group(3), text)
    # the two collapsed flag bytes: "0x20 some_bit_name:" -> words
    for prefix in ("protection_condition_flags_t,0x0040b0e8,fault_state_flags,", "protection_status_flags_t,0x0040b0f2,status_flags,"):
        start = text.index("\n" + prefix) + 1
        end = text.index("\n", start)
        row = re.sub(r"(0x[0-9a-f]{2} )([a-z][a-z0-9_]+):", lambda m: m.group(1) + m.group(2).replace("_", " ") + ":",
                     text[start:end])
        text = text[:start] + row + text[end:]
    for old, new in [
        ("and sensor_fault_safety_check (lhz at 0x5103b8", "and cm848_monitorWaterInFuel (lhz at 0x5103b8"),
        ("cm848_completeBoostPressureMonitorReport, cm848_calibration_group21_load_cont)",
         "cm848_completeBoostPressureMonitorReport, cm848_monitorEgrOrificeTemperatureSensorRationality)"),
        ("it computes the air_fuel_control_fuel_limit grid limit", "it computes the limit from air_fuel_control_fuel_limit_grid"),
    ]:
        assert old in text, old
        text = text.replace(old, new)
    return text


def renames(text):
    old = "moves faults between active_dtc / previously_active_dtc"
    assert text.count(old) == 1
    return text.replace(old, "moves faults between active_dtc_list_cal / previously_active_dtc_list_cal")


def claude_md(text):
    old = ("of its bytes (`engine_sync_type_code`, `cold_start_protection_state_flags`, ...) were guesses.")
    assert old in text
    text = text.replace(old, "of its bytes were `engine_sync_type_code`, `cold_start_protection_state_flags` and so on, all guesses.")
    old = "    - `algorithm_enable_flags_12/18/41_t`, with the e2m AENBLFLG bit names."
    assert old in text
    return text.replace(old, "    - `algorithm_enable_flags_12_t`, `algorithm_enable_flags_18_t` and `algorithm_enable_flags_41_t`, with the\n"
                             "      e2m AENBLFLG bit names.")


edit(os.path.join(out, "structure_definitions.csv"), structures)
edit(os.path.join(out, "function_renames.csv"), renames)
edit(os.path.join(repo, "firmware/CLAUDE.md"), claude_md)
print("fixed")
