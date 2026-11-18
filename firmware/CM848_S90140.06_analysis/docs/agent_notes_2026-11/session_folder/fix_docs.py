"""Replace renamed globals in the active docs (word-bounded); dropped interior names -> struct fields."""
import re
import sys

root = sys.argv[1]
old_new = dict(l.strip().split(",", 1) for l in open(sys.argv[2]) if l.strip())
FIELDS = {"boost_pressure_fixed_reference": "barometric_pressure_sensor_config.default_value",
          "fuel_level_unfiltered": "fuel_level_sensor_channel_state.value",
          "j1939_accelerator_pedal_position": "sensor_channel13_ram.held_value",
          "j1939_accelerator_pedal_source_priority": "sensor_channel13_ram.held_value_source_priority",
          "j1939_accelerator_pedal_default_position": "accelerator_pedal_sensor_config.default_value",
          "cruise_engage_adc_valid_upper": "cruise_switch_sensor_config.high_threshold",
          "cruise_engage_adc_valid_lower": "cruise_switch_sensor_config.low_threshold"}
mapping = {o: (FIELDS.get(o) if n == "(field)" else n) for o, n in old_new.items()}
mapping = {o: n for o, n in mapping.items() if n}
FILES = ["firmware/CLAUDE.md", "firmware/CM848_S90140.06_analysis/docs/service_0x4a_protocol.md",
         "firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md",
         "firmware/CM848_S90140.06_analysis/docs/wastegate_control_path.md",
         "firmware/CM848_S90140.06_analysis/output/10bar_map_conversion.md"]
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(re.escape(o) for o in sorted(mapping, key=len, reverse=True)) + r")(?![A-Za-z0-9_])")
for f in FILES:
    path = f"{root}/{f}"
    text = open(path).read()
    new, n = pattern.subn(lambda m: mapping[m.group(1)], text)
    open(path, "w").write(new)
    print(f"{f}: {n} replacements")
