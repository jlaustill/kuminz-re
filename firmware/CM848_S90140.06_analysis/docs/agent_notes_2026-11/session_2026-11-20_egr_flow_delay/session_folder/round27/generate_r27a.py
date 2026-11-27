"""Round 27 stage A (label-only): the sensor channel families. Generates
  worklist_r27a.py  (GLOBALS for named rows, FUNCTIONS for the wrappers and the four base functions; for
                     apply_hand_worklist.py) and
  labels_r27a.tsv   (type-only rows: address, type, Ghidra label, name, comment; for apply_r27a_labels.py).
The family of each channel comes from its e2m records and fault bits (channel_identity.py; the evidence column).
Per-role names (the convention of the channels named before): <x>_sensor_config / <x>_sensor_channel_state /
<x>_linearization_axis / _values / <table base>_cached_axis_offset (round 10) / <x>_sensor_filter_state /
<x>_sensor_value / _default_value / <x>_sensor_fault_status. A named row is renamed only when its name is an ordinal
or wrong-family leftover (FIX below or a sensor_channel<N> / Generic name); every other named row stays.
Wrappers: cm848_process<Family>Channel when they call a periodic base, cm848_initialize<Family>Channel when they call
a boot base (the old _init / _process suffixes were inverted).
usage: generate_r27a.py <cpp> <global_variables.csv> <out dir>"""
import csv
import os
import re
import sys

cpp_path, gv_path, outdir = sys.argv[1:4]
text = open(cpp_path).read()
# channel: (family x, Family, evidence)
FAMILY = {
    1: ("boost_pressure", "BoostPressure", "e2m 1016 Boost_Pressure tables, 1966 +E Charge_Press_Sensor, P0238 / P0237"),
    2: ("coolant_temperature", "CoolantTemperature", "e2m 1014 tables, 1966 +8 Coolant_Tmptr_Sensor, P0118 / P0117"),
    3: ("barometric_pressure", "BarometricPressure", "e2m 101D Ambient_Air_Pressure tables, 1966 +2 Air_Press_Sensor, P0108 / P0107"),
    4: ("battery_voltage", "BatteryVoltage", "e2m 1027 tables, 1966 +22 Battery_Volt_Sensor, P0563 / P0562"),
    7: ("fuel_temperature", "FuelTemperature", "1966 +50 Fuel_Tmptr_Sensor, faults 47 / 48 Fuel_Temperature_High / Low_Error"),
    8: ("remote_accelerator_pedal", "RemoteAcceleratorPedal", "named before"),
    9: ("intake_manifold_temperature", "IntakeManifoldTemperature", "e2m 101B tables, 1966 +6 Charge_Tmptr_Sensor, P0113 / P0112"),
    10: ("oil_pressure", "OilPressure", "named before"),
    13: ("accelerator_pedal", "AcceleratorPedal", "named before"),
    15: ("water_in_fuel", "WaterInFuel", "named before"),
    20: ("ambient_air_temperature", "AmbientAirTemperature",
         "e2m 138E / 138D Ambient_Air_Temperature tables, P0073 / P0072; its outputs are e2m 1966 +10 "
         "Compressor_Inlet_Tmptr_Sensor (compressor_inlet_temperature_sensor_*)"),
    21: ("sensor_reference_voltage_c", "SensorReferenceVoltageC", "named before"),
    26: ("ecm_internal_temperature", "EcmInternalTemperature",
         "1966 +3C ECM_Internal_Tmptr_Sensor, 1963 +1E ECM_Internal_Tmptr_Status, faults 306 / 307 "
         "ECM_Internal_Temperature_Low / High_Error"),
    28: ("sensor_reference_voltage_b", "SensorReferenceVoltageB", "named before"),
    29: ("engine_speed_sensor_supply_voltage", "EngineSpeedSensorSupplyVoltage",
         "e2m 8A1E / 8A20 / 8A21 Engine_Speed_Sensor_SV (VOLT), 1966 +58 Engine_Speed_SV_Sensor, 1963 +2C "
         "Engine_Speed_SV_Status, faults 375 / 376 Engine_Speed_Sensor_SV_High / Low_Error = P0338 / P0337; SV = supply "
         "voltage (e2m spells the throttle one both ways, Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV, "
         "and 1966 +5A reads 'Engine_Speed_SVage Default value')"),
    42: ("sensor_reference_voltage_a", "SensorReferenceVoltageA", "named before"),
    47: ("cruise_switch", "CruiseSwitch", "named before"),
    54: ("injector_driver_booster_capacitor_1_voltage", "InjectorDriverBoosterCapacitor1Voltage",
         "e2m 81CA / 81CC / 81CD Booster_Cap_1_Voltage, 1966 +7C Booster_Cap_1_Volt_Sensor, fault 328 "
         "Booster_Cap_1_Voltage_High_Error / 329 P2146 (fuel injector group A supply voltage circuit)"),
    55: ("injector_driver_booster_capacitor_2_voltage", "InjectorDriverBoosterCapacitor2Voltage",
         "e2m 81CE / 81D0 / 81D1 Booster_Cap_2_Voltage, 1966 +80 Booster_Cap_2_Volt_Sensor, fault 331 P2149 (group B)"),
    68: ("fuel_level", "FuelLevel", "e2m 8A05 / 8A07 Fuel_Level, 1963 +1C Fuel_Lvl_Status, faults 381 / 382 P0463 / P0462"),
    69: ("battery_temperature", "BatteryTemperature", "named before"),
    71: ("air_conditioning_pressure", "AirConditioningPressure", "named before"),
    75: ("egr_valve_position", "EgrValvePosition",
         "e2m 17CF / 17D1 / 17D2 EGR_Position_Before_Autozero (%open), 1966 +16 EGR_Position_Sensor, faults 642 / 643 "
         "EGR_Position_Before_Autozero_High / Low_Error"),
    76: ("four_wheel_drive_switch", "FourWheelDriveSwitch", "named before"),
    77: ("boost_pressure_absolute", "BoostPressureAbsolute",
         "e2m 17DB / 17DD / 17DE Boost_Pressure_Absolute (IN_HG), faults 648 / 649 Boost_Pressure_Absolute_High / "
         "Low_Error; its outputs at 0x3fa046-0x3fa04b have no e2m record"),
    88: ("exhaust_throttle_position", "ExhaustThrottlePosition",
         "e2m 1813 / 1815 / 1816 Exhaust_Throttle_Position (%open), faults 658 / 659 Exhaust_Throttle_Position_High / "
         "Low_Error; disabled here (sensor_channel_enable_bits_cal word 5 = 0x047f), yet its wrapper passes the fuel "
         "temperature outputs 0x40bdd0 / 0x40bdd2 / 0x40be3a (the stack stores at 0x500128-0x500148), so channels 7 "
         "and 88 write the same three words"),
    97: ("accelerator_pedal_position_sensor_1", "AcceleratorPedalPositionSensor1", "named before"),
    98: ("accelerator_pedal_position_sensor_2", "AcceleratorPedalPositionSensor2", "named before"),
    101: ("variable_geometry_turbocharger_position", "VariableGeometryTurbochargerPosition",
          "e2m 182C / 182E TVA_Sampled_Position, 1966 +36 VGT_Position_Sensor"),
    102: ("governor_pressure", "GovernorPressure", "named before"),
    103: ("transmission_temperature", "TransmissionTemperature",
          "1966 +78 Trans_Oil_Tmptr_Sensor, 1963 +3C Trans_Oil_Tmptr_Status, P0713 / P0712"),
    105: ("egr_delta_pressure", "EgrDeltaPressure", "named before"),
    108: ("egr_orifice_temperature", "EgrOrificeTemperature", "named before"),
    109: ("exhaust_pressure", "ExhaustPressure", "named before"),
}
FIX = {  # named rows whose name is a leftover (old -> why)
    "map_sensor_fault_status": "the channel's other words are boost_pressure_* (e2m 1963 +C Charge_Press_Status)",
    "boost_pressure_sensor_state": "the _sensor_channel_state convention",
    "barometric_pressure_sensor_state": "the _sensor_channel_state convention",
    "variable_geometry_turbocharger_position_sensor_state": "the _sensor_channel_state convention",
    "boost_pressure_linearization_x_axis": "a 1-D table: <base>_axis / <base>_values (the table grammar)",
    "boost_pressure_linearization_y_axis": "a 1-D table: <base>_axis / <base>_values (the table grammar)",
    "injector_group_a_supply_voltage_linearization_axis": "e2m 81CC calls it Booster_Cap_1_Voltage_X_Axis",
    "injector_group_a_supply_voltage_linearization_values": "e2m 81CD calls it Booster_Cap_1_Voltage_Y_Axis",
    "injector_group_b_supply_voltage_linearization_axis": "e2m 81D0 calls it Booster_Cap_2_Voltage_X_Axis",
    "injector_group_b_supply_voltage_linearization_values": "e2m 81D1 calls it Booster_Cap_2_Voltage_Y_Axis",
    "exhaust_pressure_sensor_cached_axis_offset": "the cache takes its table's base (round 10)",
    "injector_driver_booster_capacitor_1_voltage_channel_state": "its outputs are ..._sensor_value / _fault_status",
    "injector_driver_booster_capacitor_2_voltage_channel_state": "its outputs are ..._sensor_value / _fault_status",
}
ORDINAL = re.compile(r"^sensor_channel(\d+|Generic)_")
LABEL = re.compile(r"^(sensor_channel_config_t|sensor_channel_state_t|ema_filter_state_t|WORD|WORD_ARRAY)_([0-9a-f]{8})$")
BASES = {"sensorChannelConfigInit": ("process", "signed"), "updateSensorChannelWithConfig": ("initialize", "signed"),
         "sensorChannelTypeB_configInit": ("process", "unsigned"), "sensorChannelTypeB_update": ("initialize", "unsigned")}
CALL = re.compile(r"\b(" + "|".join(BASES) + r")\s*\(([^;]*?)\);", re.S)
ROLE = ["config", "state", "cache", "x_axis", "y_data", "flags", "filter", "channel", "high_fault", "low_fault",
        "value", "default", "status"]
ARG = {"config": 1, "state": 2, "cache": 3, "x_axis": 4, "y_data": 5, "filter": 7, "value": 11, "default": 12,
       "status": 13}
gv = {}
for row in csv.reader(open(gv_path, errors="replace")):
    if row and row[0].startswith("0x") and len(row) >= 3:
        gv[row[1] or f"@{row[0]}"] = (row[0], row[2])
addr_of_label = {}
for name, (a, t) in gv.items():
    pass


def target(x, role, xaxis_new):
    if "sensor" in x.split("_"):     # sensor_reference_voltage_*, accelerator_pedal_position_sensor_N, ...
        suffix = {"config": "_config", "state": "_channel_state", "filter": "_filter_state", "value": "_value",
                  "default": "_default_value", "status": "_fault_status"}
    else:
        suffix = {"config": "_sensor_config", "state": "_sensor_channel_state", "filter": "_sensor_filter_state",
                  "value": "_sensor_value", "default": "_sensor_default_value", "status": "_sensor_fault_status"}
    if role == "x_axis":
        return f"{x}_linearization_axis"
    if role == "y_data":
        return f"{x}_linearization_values"
    if role == "cache":
        return re.sub(r"(_x_axis|_axis)$", "", xaxis_new) + "_cached_axis_offset"
    return x + suffix[role]


heads = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]
globals_named, labels, seen = {}, {}, {}
wrappers = {}
for m in CALL.finditer(text):
    base = m.group(1)
    args = [re.sub(r"\s+", "", a).lstrip("&") for a in m.group(2).split(",")]
    if len(args) != 13:
        continue
    ch = int(args[7], 0)
    caller = max((p, n) for p, n in heads if p < m.start())[1]
    x, fam, evidence = FAMILY[ch]
    wrappers.setdefault(caller, set()).add((BASES[base][0], BASES[base][1], fam, ch, x))
    xaxis_cur = args[3]
    xaxis_new = target(x, "x_axis", "") if (xaxis_cur in FIX or ORDINAL.match(xaxis_cur) or LABEL.match(xaxis_cur)) \
        else xaxis_cur
    for role, k in ARG.items():
        cur = args[k - 1]
        if role in ("value", "default", "status") and ch in (20, 88):
            continue          # the outputs keep their e2m 1966 names (compressor inlet / fuel temperature)
        lm = LABEL.match(cur)
        if not (lm or cur in FIX or ORDINAL.match(cur)):
            continue
        new = xaxis_new if role == "x_axis" else target(x, role, xaxis_new)
        if new == cur:
            continue
        why = FIX.get(cur, "an ordinal name" if ORDINAL.match(cur) else "unnamed")
        note = f"sensor channel {ch} {role.replace('_', ' ')} ({evidence}); {why}"
        key = (cur, new)
        if key in seen:
            continue
        seen[key] = 1
        if lm:
            labels[cur] = (f"0x{lm.group(2)}", lm.group(1) if lm.group(1) not in ("WORD", "WORD_ARRAY") else None,
                           cur, new, note)
        else:
            globals_named[cur] = (gv[cur][0], new, note)
# slot 77 of sensor_channel_filtered_output
globals_named["boost_pressure_channel77_sensor_filtered"] = (
    gv["boost_pressure_channel77_sensor_filtered"][0], "boost_pressure_absolute_sensor_filtered",
    "sensor_channel_filtered_output slot 77, the boost pressure absolute channel (e2m 17DB / 17DD / 17DE "
    "Boost_Pressure_Absolute); an ordinal name")
olds = [o for o, (a, n, w) in globals_named.items()]
news = [n for o, (a, n, w) in globals_named.items()] + [v[3] for v in labels.values()]
assert len(news) == len(set(news)), [n for n in news if news.count(n) > 1]
# functions
FUNCS = []
fr = {}
for row in csv.reader(open(os.path.join(os.path.dirname(gv_path), "function_renames.csv"), errors="replace")):
    if row and row[0].startswith("0x"):
        fr[row[1]] = row[0]
for caller, kinds in sorted(wrappers.items()):
    assert len({(k, f) for k, s, f, c, x in kinds}) == 1, (caller, kinds)
    kind, sign, fam, ch, x = sorted(kinds)[0]
    new = f"cm848_{kind}{fam}Channel"
    if new == caller:
        continue
    when = "every pass, from a periodic task" if kind == "process" else "once at boot, from cm848_applicationMain"
    base_new = f"cm848_{kind}{sign.capitalize()}SensorChannel"
    FUNCS.append((fr[caller], new, f"Sensor channel {ch} ({x.replace('_', ' ')}): calls {base_new} {when}; the old "
                  f"_init / _process suffixes were inverted"))
BASE_NEW = {
    "sensorChannelConfigInit": ("cm848_processSignedSensorChannel",
        "The periodic pass of the signed sensor channels (lookup flags 2, cm848_signedFirstOrderFilter; lha loads): "
        "read the QADC result, linearize, filter, debounce the high / low faults, write the outputs. Its callers run "
        "from periodic tasks; the old name said configInit"),
    "updateSensorChannelWithConfig": ("cm848_initializeSignedSensorChannel",
        "The boot pass of the signed sensor channels: seeds the filter accumulator, resets the lookup cache to 2 and "
        "points the filter at the config's coefficient. Its callers run once from cm848_applicationMain"),
    "sensorChannelTypeB_configInit": ("cm848_processUnsignedSensorChannel",
        "The periodic pass of the unsigned sensor channels (lookup flags 0, exponentialMovingAverage; lhz loads). "
        "Unlike the signed twin it skips the threshold faults of channel 47 (cruise switch) until "
        "cruise_control_switches_learned_flag, of channel 71 (A/C pressure) until its learned flag, and of channel 10 "
        "(oil pressure) while oil_pressure_switch_only_cal is set"),
    "sensorChannelTypeB_update": ("cm848_initializeUnsignedSensorChannel",
        "The boot pass of the unsigned sensor channels (the unsigned twin of cm848_initializeSignedSensorChannel)"),
}
for old, (new, plate) in BASE_NEW.items():
    FUNCS.append((fr[old], new, plate))
with open(os.path.join(outdir, "worklist_r27a.py"), "w") as fh:
    fh.write('"""Round 27 stage A (label-only), generated by generate_r27a.py: the sensor channel families (named rows '
             'and functions)."""\n')
    fh.write("GLOBALS = [\n")
    for old, (a, new, note) in sorted(globals_named.items(), key=lambda kv: kv[1][0]):
        fh.write(f"    ({a!r}, {new!r}, {note!r}),\n")
    fh.write("]\nFUNCTIONS = [\n")
    for a, new, plate in FUNCS:
        fh.write(f"    ({a!r}, {new!r}, {plate!r}),\n")
    fh.write("]\n")
with open(os.path.join(outdir, "labels_r27a.tsv"), "w") as fh:
    for label, (a, typ, cur, new, note) in sorted(labels.items(), key=lambda kv: kv[1][0]):
        fh.write("\t".join([a, typ or "word", cur, new, note]) + "\n")
print(f"{len(globals_named)} named rows, {len(labels)} type-only rows, {len(FUNCS)} functions")
