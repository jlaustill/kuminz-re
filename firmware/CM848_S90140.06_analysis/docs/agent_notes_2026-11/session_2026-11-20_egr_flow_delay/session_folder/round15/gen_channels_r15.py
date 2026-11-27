"""Round 15 stage A: the sixteen sensor channels the e2m 1966 block names, as families. From each channel's calls
(channel_index = argument 8) it takes the config (1), state (2), cache (3), x / y tables (4 / 5), filter (7) and the value
/ default / fault status outputs (11 / 12 / 13), resolves each label to its global_variables.csv row, and proposes the
name from the channel's sensor (proved by its DTCs, e2m 1966 and its tables' existing names). Writes a JSON plan
[[address, old_label, new_name, row_name_empty, role, channel]] and prints it.
usage: gen_channels_r15.py <cpp> <global_variables.csv> <out.json>"""
import json
import re
import sys

cpp, gv, out = sys.argv[1:4]
P = {  # channel: (row prefix, table base for the cache name)
    7: ("fuel_temperature_sensor", "fuel_temperature_linearization"),
    8: ("remote_accelerator_pedal_sensor", "remote_accelerator_pedal_linearization"),
    10: ("oil_pressure_sensor", "oil_pressure_linearization"),
    13: ("accelerator_pedal_sensor", "accelerator_pedal_linearization"),
    15: ("water_in_fuel_sensor", None),
    21: ("sensor_reference_voltage_c", "sensor_reference_voltage_c_linearization"),
    28: ("sensor_reference_voltage_b", "sensor_reference_voltage_b_linearization"),
    42: ("sensor_reference_voltage_a", "sensor_reference_voltage_a_linearization"),
    69: ("battery_temperature_sensor", "battery_temperature_linearization"),
    71: ("air_conditioning_pressure_sensor", "air_conditioning_pressure_linearization"),
    76: ("four_wheel_drive_switch_sensor", "four_wheel_drive_switch_position_code"),
    97: ("accelerator_pedal_position_sensor_1", "accelerator_pedal_position_sensor_1_linearization"),
    98: ("accelerator_pedal_position_sensor_2", "accelerator_pedal_position_sensor_2_linearization"),
    102: ("governor_pressure_sensor", "governor_pressure_linearization"),
    105: ("egr_delta_pressure_sensor", "egr_delta_pressure_linearization"),
    108: ("egr_orifice_temperature_sensor", "egr_orifice_temperature_linearization"),
}
TABLES = {  # old table names -> new (the tables that still carry a channel number)
    "sensor_channel105_linearization_axis": "egr_delta_pressure_linearization_axis",
    "sensor_channel105_linearization_values": "egr_delta_pressure_linearization_values",
    "sensor_channel108_linearization_axis": "egr_orifice_temperature_linearization_axis",
    "sensor_channel108_linearization_values": "egr_orifice_temperature_linearization_values",
    "accelerator_pedal_channel97_linearization_axis": "accelerator_pedal_position_sensor_1_linearization_axis",
    "accelerator_pedal_channel97_linearization_values": "accelerator_pedal_position_sensor_1_linearization_values",
    "accelerator_pedal_channel98_linearization_axis": "accelerator_pedal_position_sensor_2_linearization_axis",
    "accelerator_pedal_channel98_linearization_values": "accelerator_pedal_position_sensor_2_linearization_values",
}
for s in ("off", "on"):
    for k in ("axis", "values"):
        TABLES[f"sensor_channel15_linearization_feature_bit_4_{s}_{k}"] = f"water_in_fuel_linearization_feature_bit_4_{s}_{k}"
rows = {}
by_name = {}
for line in open(gv):
    if line.startswith("0x"):
        a, n, t = (line.split(",", 3) + ["", ""])[:3]
        rows[a] = (n, t)
        if n:
            by_name[n] = a
text = open(cpp).read()
FUNCS = ("sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit",
         "sensorChannelTypeB_update")
seen = {}
for m in re.finditer(rf"\b({'|'.join(FUNCS)})\s*\(", text):
    i, depth = m.end(), 1
    while depth:
        depth += {"(": 1, ")": -1}.get(text[i], 0)
        i += 1
    args, depth, cur = [], 0, ""
    for ch in text[m.end():i - 1]:
        if ch == "," and depth == 0:
            args.append(cur.strip())
            cur = ""
            continue
        depth += {"(": 1, ")": -1}.get(ch, 0)
        cur += ch
    args.append(cur.strip())
    try:
        chan = int(args[7], 0)
    except (ValueError, IndexError):
        continue
    if chan not in P:
        continue
    prefix, table = P[chan]
    roles = {0: f"{prefix}_config", 1: f"{prefix}_channel_state", 6: f"{prefix}_filter_state",
             10: f"{prefix}_value", 11: f"{prefix}_default_value", 12: f"{prefix}_fault_status"}
    if table:
        roles[2] = f"{table}_cached_axis_offset"
    for idx, new in roles.items():
        label = re.sub(r"\s+", "", args[idx].replace("&", ""))
        m2 = re.match(r"^(?:[a-z_0-9]+_t|WORD|DAT|BYTE)_([0-9a-f]{8})$", label)
        if m2:
            addr = "0x" + m2.group(1)
            empty = True
        else:
            addr = by_name.get(label)
            empty = False
        if addr is None:
            print("UNRESOLVED", chan, idx, label, file=sys.stderr)
            continue
        seen[(addr, new)] = (addr, label, new, empty, idx, chan)
for old, new in TABLES.items():
    a = by_name.get(old)
    if a:
        seen[(a, new)] = (a, old, new, False, "table", None)
plan = sorted(seen.values(), key=lambda r: (r[5] if r[5] is not None else 999, str(r[4])))
for a, old, new, empty, idx, chan in plan:
    if old == new:
        continue
    print(f"{chan} {idx} {a} {old} -> {new}{' (fill)' if empty else ''}")
json.dump([p for p in plan if p[1] != p[2]], open(out, "w"), indent=0)
