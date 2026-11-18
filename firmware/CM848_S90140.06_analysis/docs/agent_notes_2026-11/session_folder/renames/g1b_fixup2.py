import json
import runpy

RESULT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1b.jsonl"
items = [json.loads(line) for line in open(RESULT)]

replacements = {
    "0x00046f7c": [
        ("(main_injection_quantity_even_event for even cylinder_event_index, _low for odd)",
         "(main_injection_quantity_even_event for even cylinder_event_index, main_injection_quantity_odd_event for odd)"),
        ("capped at main_injection_pulse_width_maximum (main_injection_pulse_width_before_minimum_check)",
         "capped at main_injection_pulse_width_maximum (giving main_injection_pulse_width_before_minimum_check)"),
    ],
    "0x00047140": [
        ("(main_injection_quantity_even_event / _low)",
         "(main_injection_quantity_even_event / main_injection_quantity_odd_event)"),
    ],
    "0x0004769c": [
        ("into main_injection_quantity_even_event for even cylinder_event_index, _low for odd)",
         "into main_injection_quantity_even_event for even cylinder_event_index, main_injection_quantity_odd_event for odd)"),
        ("main main_injection_pulse_width_maximum = 2 / 3 / 4", "main_injection_pulse_width_maximum = 2 / 3 / 4"),
        ("pilot pilot_injection_pulse_width_maximum and auxiliary auxiliary_injection_pulse_width_maximum = period / 16",
         "pilot_injection_pulse_width_maximum and auxiliary_injection_pulse_width_maximum = period / 16"),
    ],
}
for item in items:
    if item["kind"] == "function" and item["address"] in replacements:
        for old, new in replacements[item["address"]]:
            assert item["plate_comment"].count(old) == 1, (item["address"], old)
            item["plate_comment"] = item["plate_comment"].replace(old, new)

with open(RESULT, "w") as handle:
    for item in items:
        handle.write(json.dumps(item, ensure_ascii=False) + "\n")

runpy.run_path("/home/linux/.claude/jobs/d55ae3c6/tmp/renames/g1b_validate.py")
for item in items:
    if item["kind"] == "function" and item["address"] in ("0x00046f7c", "0x00047140", "0x0004769c", "0x00047394"):
        print(item["address"], item["plate_comment"])
