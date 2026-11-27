"""Round 24 stage F (types), part 1:
- sensor_readings_t (0x40baf2, 4 words) is channels 1-4 of sensor_channel_filtered_output, whose other slots are flat
  '<channel>_sensor_filtered' words: the struct goes, the four words become flat rows with the field comments.
- throttle_fuel_enable_flag (dword 0x3fa6f0) is two words (sth / lhz at each half): the throttle sensor fault flag
  and the previous pass's commanded throttle.
Writes the proof's token map (old render -> address token, new render -> address token).
usage: apply_r24f.py <repo> <tokens.json>"""
import csv
import json
import os
import sys

repo, tokens_out = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
sd_path, gv_path = os.path.join(out, "structure_definitions.csv"), os.path.join(out, "global_variables.csv")
sd, gv = open(sd_path).read().split("\n"), open(gv_path).read().split("\n")
FIELDS = [("intake_manifold_pressure", 0x40baf2, "intake_manifold_pressure_sensor_filtered", 1),
          ("coolant_temp", 0x40baf4, "coolant_temperature_sensor_filtered", 2),
          ("barometric_pressure", 0x40baf6, "barometric_pressure_sensor_filtered", 3),
          ("battery_voltage", 0x40baf8, "battery_voltage_sensor_filtered", 4)]
comments = {}
new_sd = []
for line in sd:
    if line.startswith("sensor_readings_t,"):
        row = next(csv.reader([line]))
        comments[row[2]] = row[5]
        continue
    new_sd.append(line)
assert len(comments) == 4, comments
old_tok, new_tok = {}, {}
for field, a, name, slot in FIELDS:
    old_tok[f"sensor_readings_t_0040baf2.{field}"] = f"SENSOR{slot}"
    new_tok[name] = f"SENSOR{slot}"
old_tok["sensor_readings_t_0040baf2"] = "SENSOR1"
done = set()
new_gv = []
for line in gv:
    for field, a, name, slot in FIELDS:
        if line.startswith(f"0x{a:08x},"):
            old = line.split(",", 3)
            old_name, old_comment = old[1], (old[3] if len(old) > 3 else "")
            text = (f"sensor_channel_filtered_output[{slot}]: {comments[field]} (was sensor_readings_t_0040baf2."
                    f"{field}; the 4-word struct sensor_readings_t over slots 1-4 is gone, every other slot is a flat "
                    f"word too) (PR #53 round 24)")
            if old_comment:
                text += f" | earlier note: {old_comment}"
            line = f"0x{a:08x},{name},word,{text}"
            done.add(a)
            break
    if line.startswith("0x003fa6f0,throttle_fuel_enable_flag,dword,"):
        old_comment = line.split(",", 3)[3] if line.count(",") >= 3 else ""
        line = ("0x003fa6f0,throttle_sensor_fault_flag,word,1 while the throttle (accelerator pedal) sensor has a fault: "
                "cm848_calculateCommandedThrottleFromPedal sets it from the registered Sampled_Throttle_High_Error / "
                "_Low_Error (fault bits 10 / 11) and cm848_runThrottleValidation also from fault 197 "
                "(Throttle_Sensor_Supply_Voltage_Low_Error); while it is set the calculated commanded throttle is 0, the "
                "Throttle_Min learning is skipped and Throttle_Min = accelerator_pedal_highest_valid_minimum + 4. The "
                "low word of the old dword throttle_fuel_enable_flag (sth / lhz) (PR #53 round 24)"
                + (f" | earlier note: {old_comment}" if old_comment else ""))
        new_gv.append(line)
        new_gv.append("0x003fa6f2,commanded_throttle_previous,word,The previous pass's commanded throttle: "
                      "cm848_selectCommandedThrottle subtracts it for commanded_throttle_delta and then stores the new "
                      "one; cm848_initializeCommandedThrottleState zeroes it. The high word of the old dword "
                      "throttle_fuel_enable_flag (sth / lhz) (PR #53 round 24)")
        done.add(0x3fa6f0)
        continue
    if line.startswith("0x003fa6f2,throttle_fuel_enable_flag+2,"):   # the old offset alias row (no type): replaced
        done.add(0x3fa6f2)
        continue
    new_gv.append(line)
assert done == {a for _, a, _, _ in FIELDS} | {0x3fa6f0, 0x3fa6f2}, done
assert sum(1 for l in new_gv if l.startswith("0x003fa6f2,")) == 1
old_tok["throttle_fuel_enable_flag._0_2_"] = "THROTTLE0"
old_tok["throttle_fuel_enable_flag._2_2_"] = "THROTTLE2"
new_tok["throttle_sensor_fault_flag"] = "THROTTLE0"
new_tok["commanded_throttle_previous"] = "THROTTLE2"
open(sd_path, "w").write("\n".join(new_sd))
open(gv_path, "w").write("\n".join(new_gv))
json.dump({"old": old_tok, "new": new_tok,
           "old_regex": [[r"\(\(sensor_readings_t \*\)(\w+)\)->intake_manifold_pressure", r"*\1"]]},
          open(tokens_out, "w"), indent=1)
print("sensor_readings_t dissolved into 4 flat rows; throttle_fuel_enable_flag split into 2 words")
