"""Sensor-channel typing, step 1: struct templates and one prototype for the four channel functions."""
import sys

OUT = sys.argv[1]
STRUCTS, FUNCDEFS = f"{OUT}/structure_definitions.csv", f"{OUT}/function_definitions.csv"

# ── structure_definitions.csv ─────────────────────────────────────────────────────
STATE = [
    "# sensor_channel_state_t: the 12-byte RAM state of one sensor channel (sensorChannelConfigInit / updateSensorChannelWithConfig / sensorChannelTypeB_*)",
    "sensor_channel_state_t,,raw_adc_counts,word,2,QADC result read this pass (sensor_channel_diag_override while diagnostics override the channel),,verified",
    "sensor_channel_state_t,,value,word,2,Engineering value: the table lookup of lookup_input (config default_value while the channel is disabled or faulted) - filtered into sensor_channel_filtered_output[channel],,verified",
    "sensor_channel_state_t,,debounce_count,word,2,Fault debounce: + debounce_step toward debounce_limit while out of range / - recovery_decrement back in range,,verified",
    "sensor_channel_state_t,,held_value,word,2,Output while the channel is held (its fuel_demand_feature_flags bit set) - config default_value from the boot pass,,verified",
    "sensor_channel_state_t,,spare,word,2,Not accessed by the four sensor-channel functions,,verified",
    "sensor_channel_state_t,,lookup_input,word,2,Table input: raw x sensor_channel_ratio_scale / the supply channel's filtered output (capped at 0x3ff) or the raw reading for type-0 channels,,verified",
    "# ema_filter_state_t: exponentialMovingAverage's state - each pass the accumulator moves (65536 - coefficient) / 65536 of the way to the new value",
    "ema_filter_state_t,,coefficient,word*,4,Points at the filter coefficient (a sensor channel's config filter_coefficient): the weight of the previous value in 1/65536 - 0 = no filtering,,verified",
    "ema_filter_state_t,,accumulator,dword,4,Q16.16 filtered value - its integer part is the output,,verified",
]
lines = open(STRUCTS).read().split("\n")
out, replaced = [], False
for line in lines:
    if line.startswith("sensor_channel_config_t,,config_word0,"):
        line = ("sensor_channel_config_t,,filter_coefficient,word,2,EMA coefficient: the weight of the previous filtered value "
                "in 1/65536 (0 = no filtering) - the channel's ema_filter_state_t.coefficient points here "
                "(was config_word0),,verified")
        replaced = True
    out.append(line)
    if line.startswith("sensor_channel_config_t,,debounce_clear_threshold,"):
        out.extend(STATE)
assert replaced
open(STRUCTS, "w").write("\n".join(out))

# ── function_definitions.csv ──────────────────────────────────────────────────────
CHANNEL_FUNCTIONS = {
    "0x00500234": ("sensorChannelConfigInit", "Type A periodic pass"),
    "0x00500a4c": ("updateSensorChannelWithConfig", "Type A boot pass"),
    "0x005012dc": ("sensorChannelTypeB_configInit", "Type B periodic pass"),
    "0x00501b4c": ("sensorChannelTypeB_update", "Type B boot pass"),
}
PARAMS = [
    ("return", "", "void", "No return value"),
    ("0", "config_ptr", "sensor_channel_config_t *", "ROM / EEPROM calibration block: filter coefficient / default / thresholds / debounce"),
    ("1", "state_ptr", "sensor_channel_state_t *", "The channel's RAM state"),
    ("2", "cached_axis_offset", "word *", "Cache word of the lookup (r5) - passed to lookupTableInterpolation as its cached_axis_offset"),
    ("3", "x_axis", "word *", "X axis (r6): byte-length word then the breakpoints - looked up with state_ptr->lookup_input"),
    ("4", "y_data", "word *", "Y data (r7): one value per breakpoint after a byte-length word"),
    ("5", "flags", "int", "lookupTableInterpolation flags (r8): bit 0 = signed axis / bit 1 = signed data / bit 3 = step lookup"),
    ("6", "filter_state_ptr", "ema_filter_state_t *", "EMA filter state (r9) - the boot pass points its coefficient at config_ptr->filter_coefficient and seeds the accumulator"),
    ("7", "channel_index", "uint", "Sensor channel (r10): indexes sensor_channel_filtered_output / qadc_channel_index_table and the enable bitmaps"),
    ("8", "high_fault_bit", "uint", "Fault bit set when the input stays above high_threshold (fault n = word n/16 bit n%16)"),
    ("9", "low_fault_bit", "uint", "Fault bit set when the input stays below low_threshold"),
    ("10", "value_output_ptr", "word *", "Receives sensor_channel_filtered_output[channel] - the filtered engineering value - at the end of each pass (was raw_output_ptr)"),
    ("11", "default_value_output_ptr", "word *", "Receives config_ptr->default_value (was filtered_output_ptr)"),
    ("12", "fault_status_output_ptr", "word *", "Receives the status: 0 in range / 1 debouncing (value held) / 2 fault confirmed (default used) / 0x100 channel not enabled"),
]
EMA = [
    "0x00056594,exponentialMovingAverage,return,,uint,Filtered value: the integer part of the updated accumulator",
    "0x00056594,exponentialMovingAverage,0,value,uint,New sample (r3)",
    "0x00056594,exponentialMovingAverage,1,filter_state,ema_filter_state_t *,Filter state (r4) - coefficient pointer and Q16.16 accumulator - updated in place",
]
lines = open(FUNCDEFS).read().split("\n")
out, inserted = [], set()
for line in lines:
    p = line.split(",", 2)
    if p[0] in CHANNEL_FUNCTIONS and len(p) > 1 and p[1] == CHANNEL_FUNCTIONS[p[0]][0]:
        if p[0] not in inserted:
            name, role = CHANNEL_FUNCTIONS[p[0]]
            for index, pname, typ, comment in PARAMS:
                text = comment if index != "return" else f"No return value ({role})"
                out.append(f"{p[0]},{name},{index},{pname},{typ},{text}")
            inserted.add(p[0])
        continue
    if p[0] == "0x00056594":
        continue
    out.append(line)
assert inserted == set(CHANNEL_FUNCTIONS), inserted
out.extend(EMA)
open(FUNCDEFS, "w").write("\n".join(out))
print("ok")
