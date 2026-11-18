"""Changed functions whose bodies name nothing the sensor-channel pass typed."""
import difflib
import re
import sys

HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)

def split(path):
    parts = HEADER.split(open(path).read())
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}

old, new = split(sys.argv[1]), split(sys.argv[2])
tokens = {"sensor_channel_state_t", "sensor_channel_config_t", "ema_filter_state_t", "exponentialMovingAverage",
          "sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit",
          "sensorChannelTypeB_update", "sensor_channel_cal_block_start", "raw_adc_counts", "debounce_count",
          "held_value", "lookup_input", "accumulator", "filter_coefficient", "filter_state", "coefficient"}
for line in open(sys.argv[3]):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 2 and p[1] and p[2] in ("sensor_channel_state_t", "sensor_channel_config_t", "ema_filter_state_t", "word"):
        tokens.add(p[1])
pat = re.compile("|".join(re.escape(t) for t in sorted(tokens, key=len, reverse=True)) + r"|ema_filter_state_t_|sensor_channel_config_t_|sensor_channel_state_t_|WORD_00")
changed = [a for a in new if a in old and old[a][1] != new[a][1]]
left = [a for a in changed if not pat.search(new[a][1])]
print(f"changed {len(changed)}, unexplained {len(left)}")
for a in left:
    d = [l for l in difflib.unified_diff(old[a][1].split("\n"), new[a][1].split("\n"), lineterm="", n=0)
         if l[:1] in "+-" and not l.startswith(("+++", "---"))]
    print(f"== {a} {new[a][0]} ({len(d)} lines)")
    for l in d[:6]:
        print("   ", l[:140])
