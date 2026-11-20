"""Stage 6a comment fixes (comment_name_sweep.py findings):
- the history note of a record that kept its name said "(the accumulator rows +4 NAME dword)", which the sweep does
  not treat as history. All record notes now read "(was ...)": "(was OLD + the accumulator row at +4 NAME, dword)", or
  "(was a pointer row + the accumulator row at +4 NAME, dword)" when the name did not change;
- two shorthand struct references written out: engine_sync_state_t_0040b87f.fuel_metering_command and
  fuel_demand_control_t_0040a57a.delta_filtered / .delta.
usage: fix_stage6a_comments.py <CM848 output dir>"""
import os
import re
import sys

path = os.path.join(sys.argv[1], "global_variables.csv")
lines = open(path, newline="").read().split("\n")
changed = 0
for i, line in enumerate(lines):
    if ",ema_filter_state_t,cm848_signedFirstOrderFilter record" not in line:
        continue
    new = line
    new = re.sub(r"\(was ([^;()]+); the accumulator rows \+4 (\w+) (\w+)\)", r"(was \1 + the accumulator row at +4 \2, \3)",
                 new)
    new = re.sub(r"\(the accumulator rows \+4 (\w+) (\w+)\)", r"(was a pointer row + the accumulator row at +4 \1, \2)",
                 new)
    new = new.replace("(was cam_sync_fuel_filter_state_pointer; the accumulator rows +4 cam_sync_fuel_filter_accum word / "
                      "+5 cam_sync_fuel_filter_accum+1 )",
                      "(was cam_sync_fuel_filter_state_pointer + the accumulator row at +4 cam_sync_fuel_filter_accum, word, "
                      "and a label-only row cam_sync_fuel_filter_accum+1 at +5)")
    if "accumulator rows" in new:
        raise SystemExit(f"unhandled note: {new[:160]}")
    if new != line:
        lines[i] = new
        changed += 1
text = "\n".join(lines)
for old, new in [("smooths engine_sync_state fuel_metering_command (into cam_speed_rate)",
                  "smooths engine_sync_state_t_0040b87f.fuel_metering_command (into cam_speed_rate)"),
                 ("produces fuel_demand_control delta_filtered from its delta",
                  "produces fuel_demand_control_t_0040a57a.delta_filtered from fuel_demand_control_t_0040a57a.delta")]:
    assert text.count(old) == 1, old
    text = text.replace(old, new)
open(path, "w", newline="").write(text)
print(f"{changed} record notes rewritten, 2 struct references written out")
