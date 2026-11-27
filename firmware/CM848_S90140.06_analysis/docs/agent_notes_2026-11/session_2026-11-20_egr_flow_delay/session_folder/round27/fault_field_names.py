"""Round 27 stage B: a bitfield name for each of the 800 fault bits of fault_bit_words_t.
- e2m 1036 name -> snake_case with the abbreviations spelled out (TOKEN; each expansion's evidence in EVIDENCE);
- an 'A/B' name (one bit, two applications) -> the alternative its DTC slot names (PICK);
- a name with an unresolved abbreviation (UNKNOWN), a DTC-only bit and an unnamed bit -> fault_<n>;
- checks: unique, name format, no banned word (the rename gate's list), no token outside the word list or ALLOWED.
Writes <out.tsv>: fault, word, bit, field, comment.
usage: fault_field_names.py <fault_bits.tsv> <out.tsv>"""
import re
import sys

src, out = sys.argv[1], sys.argv[2]
TOKEN = {
    "fso": "fuel_shutoff", "tu": "turbocharger", "wg": "wastegate", "driver1": "driver_1", "driver2": "driver_2",
    "fp": "fuel_pressure", "hpcr": "high_pressure_common_rail", "neg": "negative", "pos": "positive",
    "dev": "deviation", "mux": "multiplexed", "aps": "accelerator_pedal_sensor", "vfs": "variable_force_solenoid",
    "tcc": "torque_converter_clutch", "vbatt": "battery", "cusum": "cumulative_sum", "pps": "pedal_position_sensor",
    "wif": "water_in_fuel", "e2": "eeprom", "vta": "vehicle_theft_alarm", "ckt": "circuit", "keyon": "key_on",
    "ration": "rationality", "ac": "air_conditioning", "ct": "coolant_temperature", "agg": "aggressive",
    "min": "minimum", "max": "maximum", "pr": "pressure", "fs": "fuel_system", "hw": "hardware",
    "tstat": "thermostat", "tcase": "transfer_case", "oor": "out_of_range", "rx": "receive", "tx": "transmit",
    "ign": "ignition", "az": "autozero", "ir": "in_range", "ega": "egr_valve_actuator",
    "vga": "variable_geometry_turbocharger_actuator", "afc": "air_fuel_control",
    "oc": "over_current", "hi": "high", "lo": "low", "dp": "delta_pressure", "eps": "engine_position_sensor",
    "oss": "output_speed_sensor", "tipm": "totally_integrated_power_module", "conn": "connector", "sv": "supply_voltage",
    "powerdown": "power_down", "poweroff": "power_off", "vgt": "variable_geometry_turbocharger",
    "tva": "variable_geometry_turbocharger", "press": "pressure", "tmptr": "temperature", "temp": "temperature",
    "volt": "voltage", "lvl": "level", "cap": "capacitor", "hb0": "h_bridge_0", "hb1": "h_bridge_1",
    "hb0a": "h_bridge_0_a", "hb0b": "h_bridge_0_b", "hb1a": "h_bridge_1_a", "hb1b": "h_bridge_1_b",
    "re": "transmission", "jcomm": "j1939", "tsc": "tsc1", "diag": "diagnostic", "turbo": "turbocharger",
    "rt": "remote_throttle", "cwg": "wastegate", "evr": "alternator_field", "eeprom": "eeprom", "gen": "",
    "postprocessed": "postprocessed", "autozero": "autozero", "overcurrent": "over_current", "inrush": "inrush",
    "derate": "derate", "keyoff": "key_off", "cyl": "cylinder", "apps": "accelerator_pedal_position_sensor",
    "imt": "intake_manifold_temperature", "ecm": "ecm", "egr": "egr", "obd": "obd", "j1939": "j1939",
    "j1850": "j1850", "pgn": "pgn", "vin": "vin", "vss": "vss", "qspi": "qspi", "pwm": "pwm", "abs": "abs", "cp3": "cp3",
    "ram": "ram", "rom": "rom", "crc": "crc", "can": "can", "adc": "adc", "pid": "pid", "dtc": "dtc", "mil": "mil",
}
EVIDENCE = {
    "rt": "fault 171 / 172 are set by cm848_claimRemoteThrottleOverride",
    "ct": "faults 389 / 390 are set by the coolant overheat monitors (P0217)",
    "tsc": "fault 356 is set by cm848_updateParkNeutralFlagAndTsc1Activity",
    "ir": "fault 527 is set by cm848_updateChargePressureInRangeFaultCount",
    "ega": "faults 720-728 are set by cm848_processEgrValveHBridgeFaults and its egr_valve family",
    "vga": "faults 738-746 are set by cm848_processVariableGeometryTurbochargerHBridgeFaults and its family",
    "cwg": "fault 332 is set by cm848_monitorWastegateBoostPressure (P0234)",
    "evr": "fault 396 = output 27, the alternator field, P0622 (the output read-back debounce)",
    "tva": "e2m names channel 101's VGT position block TVA_Sampled_Position",
    "sv": "e2m spells the throttle one both ways (Throttle_Sensor_Supply_Voltage / Throttle_Position_Sensor_SV)",
    "eps": "faults 92 / 93 (P0335 / P0340) are set by cm848_updateEngineSpeedFromCrankSignal (main / backup sensor)",
}
UNKNOWN = {"cors", "t2", "tas", "pp", "chry", "dat42", "sc"}
PICK = {  # fault: alternative index, from the DTC slot's SAE title
    138: 1, 139: 1,    # P0974 / P0973 shift solenoid A control circuit: the 48RE overdrive solenoid
    140: 1, 141: 1,    # P2770 / P2769 torque converter clutch circuit
    142: 0, 143: 0,    # P0588 / P0587 cruise control vent control circuit
    144: 0, 145: 0,    # P0584 / P0583 cruise control vacuum control circuit
    218: 0, 219: 0,    # P0381 the wait to start (glow plug / heater indicator) lamp
}
OVERRIDE = {  # fault: (field, why)
    171: ("remote_throttle_enabled_low_error", "cm848_claimRemoteThrottleOverride copies fault 78 "
          "(Remote_Throttle_Low_Error) into it while algorithm_enable_flags_18_cal.remote_throttle_enable is set; RT = "
          "remote throttle"),
    172: ("remote_throttle_enabled_high_error", "cm848_claimRemoteThrottleOverride copies fault 77 "
          "(Remote_Throttle_High_Error) into it while the remote throttle is enabled"),
}
EVIDENCE["afc"] = "the air fuel control derate (cm848_calculateAirFuelControlFuelLimit, fueling state 16)"
BANNED = {"press", "amb", "temp", "est", "volt", "info", "init", "tmptr", "lvl", "cap", "cfg", "calc", "ctrl"}
ALLOWED = set(TOKEN.values()) | {"ecm", "egr", "obd", "j1939", "j1850", "pgn", "vin", "vss", "qspi", "pwm", "abs",
                                 "cp3", "ram", "rom", "crc", "can", "adc", "pid", "dtc", "mil", "tsc1", "eeprom",
                                 "autozero", "postprocessed", "inrush", "derate", "wastegate", "overspeed", "shutoff",
                                 "checksum", "overdrive", "underspeed", "powertrain", "rationality"}
words = {w.strip().lower() for w in open("/usr/share/dict/words")}
rows = {}
for line in open(src):
    fault, word, bit, name, dtc = line.rstrip("\n").split("\t")
    rows[int(fault)] = (name, dtc)
result, notes = [], []
seen = {}
for fault in range(800):
    name, dtc = rows.get(fault, ("", ""))
    e2m = name
    why = ""
    if name and "/" in name:
        alternatives = name.split("/")
        if fault in PICK and len(alternatives) == 2 and all(alternatives):
            name = alternatives[PICK[fault]]
            why = f"the {dtc} alternative of {e2m}"
        else:
            name = ""
            why = f"e2m {e2m!r} names two applications and no DTC decides"
    field = ""
    if name:
        tokens = [t.lower() for t in name.split("_") if t]
        if any(t in UNKNOWN for t in tokens):
            why = f"e2m {e2m} has an abbreviation the code does not resolve ({', '.join(t for t in tokens if t in UNKNOWN)})"
        else:
            out_tokens = []
            for i, t in enumerate(tokens):
                if t == "p" and i > 0 and tokens[i - 1] == "delta":
                    out_tokens.append("pressure")
                elif t in TOKEN:
                    if TOKEN[t]:
                        out_tokens.append(TOKEN[t])
                else:
                    out_tokens.append(t)
            field = "_".join(out_tokens)
            field = re.sub(r"_+", "_", field).strip("_")
    if fault in OVERRIDE:
        field, why = OVERRIDE[fault]
    if not field:
        field = f"fault_{fault}"
    if field in seen:
        field = f"{field}_{fault}"
    seen[field] = fault
    parts = field.split("_")
    bad = [t for t in parts if t in BANNED]
    odd = [t for t in parts if not (t in words or t in ALLOWED or t.isdigit() or re.fullmatch(r"fault", t))]
    assert re.fullmatch(r"[a-z][a-z0-9_]*[a-z0-9]", field) and "__" not in field, field
    assert not bad, (fault, field, bad)
    expansions = sorted({t for t in (e2m or "").lower().replace("/", "_").split("_") if t in EVIDENCE})
    comment = f"fault {fault}"
    if e2m:
        comment += f": e2m 1036 {e2m}"
    if dtc:
        comment += f" ({dtc})"
    if why:
        comment += f"; {why}"
    for t in expansions:
        comment += f"; {t.upper()}: {EVIDENCE[t]}"
    result.append((fault, fault // 16, fault % 16, field, comment.replace(",", ";")))
    if odd:
        notes.append(f"{fault} {field}: tokens not in the word list {odd}")
with open(out, "w") as fh:
    for r in result:
        fh.write("\t".join(map(str, r)) + "\n")
named = sum(1 for r in result if not r[3].startswith("fault_"))
print(f"800 bits: {named} named, {800 - named} fault_<n>")
print("\n".join(notes))
