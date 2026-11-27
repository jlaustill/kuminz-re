"""Round 23 stage A (label-only), part 2: the ambient conditions module's unnamed rows (they rendered under Ghidra's
labels) and three words with no row, each named from its e2m record (the ECU's parameter ID table) or its code use.
Appends the map rows (address,name,Ghidra label,global). usage: apply_r23a2.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
NAME = [  # (address, type, Ghidra label, name, comment)
    (0x3fb9e2, "ema_filter_state_t", "ema_filter_state_t_003fb9e2", "ambient_air_temperature_filter",
     "The ambient air temperature filter (cm848_signedFirstOrderFilter): compressor_inlet_temperature minus "
     "compressor_inlet_temperature_rise, with ambient_air_temperature_filter_coefficient"),
    (0x3ff076, "word", "WORD_003ff076", "ambient_air_temperature_filter_coefficient",
     "e2m 1977 +2 C_AMB_Amb_Tmptr_Fil_Cnst 'First order filter constant used for Ambient Air Temperature' (1/65536): "
     "ambient_air_temperature_filter's coefficient"),
    (0x3fb9f6, "ema_filter_state_t", "ema_filter_state_t_003fb9f6", "compressor_inlet_pressure_drop_air_flow_filter",
     "First order filter of the fresh air mass flow for the compressor inlet pressure drop lookup, with "
     "compressor_inlet_pressure_drop_air_flow_filter_coefficient"),
    (0x3ff07e, "word", "WORD_003ff07e", "compressor_inlet_pressure_drop_air_flow_filter_coefficient",
     "e2m 1977 +A C_AMB_Air_Flow_CIPD_Fil_Cnst 'First order filter constant for Compressor_Inlet_Pressure_Drop calc.' "
     "(1/65536)"),
    (0x3ff0c4, "word[17]", "WORD_ARRAY_003ff0c4", "compressor_inlet_pressure_drop_by_air_flow_axis",
     "e2m 197A C_AMB_Pressure_Drop_Flow_Axis (LB/MIN) 'Pressure drop function of fresh-air flow': the axis of the "
     "compressor inlet pressure drop table"),
    (0x3ff0e6, "word[17]", "WORD_ARRAY_003ff0e6", "compressor_inlet_pressure_drop_by_air_flow_values",
     "e2m 197B C_AMB_Pressure_Drop_Table (IN_HG) 'Pressure drop function of fresh air flow': compressor_inlet_pressure_drop "
     "by the filtered fresh air flow"),
    (0x3ff108, "word[19]", "WORD_ARRAY_003ff108", "compressor_inlet_temperature_rise_x_axis",
     "e2m 197C C_AMB_Tmptr_Rise_Flow_Axis (LB/MIN) 'Temperature rise function of fresh-air flow'"),
    (0x3ff3b6, "word[19]", "WORD_ARRAY_003ff3b6", "compressor_inlet_temperature_rise_y_axis",
     "e2m 1A0E C_AMB_Tmptr_Rise_Speed_Axis (MPH) 'Temperature rise function of vehicle speed'"),
    (0x3ff12e, "word[324]", "WORD_ARRAY_003ff12e", "compressor_inlet_temperature_rise_grid",
     "e2m 197D C_AMB_Tmptr_Rise_Table (DEG_F): compressor_inlet_temperature_rise by ambient_air_flow_filtered x "
     "vehicle_speed_copy"),
    (0x3fb9de, "word[2]", "WORD_ARRAY_003fb9de", "compressor_inlet_temperature_rise_cached_axis_offsets",
     "2-D lookup cache of compressor_inlet_temperature_rise_grid: the X / Y axis offsets of the last lookup"),
]
NEW = [  # (address, type, Ghidra label, name, comment)
    (0x3fb9dc, "word", "DAT_003fb9dc", "compressor_inlet_pressure_drop_by_air_flow_cached_axis_offset",
     "Lookup cache of compressor_inlet_pressure_drop_by_air_flow (cm848_calculateAmbientAndCompressorInletConditions); "
     "preset to 2 by cm848_initializeAmbientConditions"),
    (0x3faac5, "word", "DAT_003faac5", "j1939_pgn65269_ambient_air_temperature",
     "PGN 65269 bytes 4-5: ambient air temperature (SPN 171): the ambient air temperature sensor "
     "(ambient_air_temperature_sensor_filtered, 1/64 deg F) converted to J1939's 0.03125 K per bit (deg F to deg C, + "
     "273, x 32) and byte-swapped; 0xFFFF while algorithm_enable_flags_29_cal bits 0 and 1 are not both set, 0xFFFE "
     "while fault 150 or 151 is detected"),
    (0x3faac7, "byte", "DAT_003faac7", "j1939_pgn65269_engine_air_intake_temperature",
     "PGN 65269 byte 6: engine air intake temperature (SPN 172); 0xFF (not available) from "
     "cm848_initJ1939AmbientConditionsBuffer, never built"),
]
map_rows = []
for address, typ, label, name, comment in NAME:
    k = [i for i, l in enumerate(g) if l.startswith(f"0x{address:08x},,{typ},")]
    assert len(k) == 1, hex(address)
    old_comment = g[k[0]].split(",", 3)[3]
    g[k[0]] = f"0x{address:08x},{name},{typ},{comment} (PR #53 round 23) | earlier note: {old_comment}"
    map_rows.append(f"0x{address:08x},{name},{label},global")
for address, typ, label, name, comment in NEW:
    assert not any(l.startswith(f"0x{address:08x},") for l in g), hex(address)
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"0x{address:08x},{name},{typ},{comment} (PR #53 round 23)")
    map_rows.append(f"0x{address:08x},{name},{label},global")
open(gp, "w").write("\n".join(g))
with open(map_path, "a") as fh:
    fh.write("\n".join(map_rows) + "\n")
print(len(NAME), "rows named,", len(NEW), "rows added,", len(map_rows), "map rows")
