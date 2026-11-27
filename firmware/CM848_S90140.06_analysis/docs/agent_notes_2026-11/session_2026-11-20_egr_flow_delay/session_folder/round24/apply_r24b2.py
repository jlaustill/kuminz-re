"""Round 24 stage B (label-only), part 2: the type-only rows named from e2m 1966 (the channel 26 / 68 outputs, which
rendered as WORD_ labels) and five words with no row, each named from its e2m record (the ECU's parameter ID table)
and its code use (asm width: lhz in each reader). Appends the map rows (address,name,Ghidra label,global).
usage: apply_r24b2.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
NAME = [  # (address, type, Ghidra label, name, comment)
    (0x40bdb8, "word", "WORD_0040bdb8", "fuel_level_sensor_value",
     "e2m 1966 +38 Fuel_Lvl_Sensor 'Fuel_Level_Sensor value linearized and filtered' (%): the value output (argument "
     "11) of sensor channel 68, the fuel level (sensorChannelTypeB_configInit_axis4 and its boot twin)"),
    (0x40bdba, "word", "WORD_0040bdba", "fuel_level_sensor_default_value",
     "e2m 1966 +3A Fuel_Lvl_Default 'Fuel_Lvl_Default value' (%): the default value output (argument 12) of sensor "
     "channel 68"),
    (0x40bdbc, "word", "WORD_0040bdbc", "ecm_internal_temperature_sensor_value",
     "e2m 1966 +3C ECM_Internal_Tmptr_Sensor 'ECM Internal Temperature' (DEG_F): the value output (argument 11) of "
     "sensor channel 26 (sensorChannelTypeB_configInit_axis1 and its boot twin), so channel 26 is the ECM internal "
     "temperature; its fault bits 306 / 307 map to P0606 / no DTC"),
    (0x40bdbe, "word", "WORD_0040bdbe", "ecm_internal_temperature_sensor_default_value",
     "e2m 1966 +3E ECM_Internal_Tmptr_Default 'ECM Internal Temperature Default value' (DEG_F): the default value "
     "output (argument 12) of sensor channel 26"),
]
NEW = [  # (address, type, Ghidra label, name, comment)
    (0x5c28e, "word", "DAT_0005c28e", "accelerator_pedal_off_idle_deadband",
     "e2m 1048 +0 Throttle_Deadband (%THROTTLE) 'above the sum of this and Throttle_Min switches must indicate off "
     "idle': cm848_evaluateIdleValidationSwitches adds it to the Throttle_Min (accelerator_pedal_autozero_cal - "
     "accelerator_pedal_autozero_offset) for idle_validation_off_idle_threshold (lhz @ 0x1716c)"),
    (0x5c290, "word", "DAT_0005c290", "accelerator_pedal_idle_hysteresis",
     "e2m 1048 +2 Throttle_Hysteresis (%THROTTLE) 'below the sum of this and Throttle_Min switches must indicate "
     "IDLE': cm848_evaluateIdleValidationSwitches adds it to the Throttle_Min for idle_validation_idle_threshold "
     "(lhz @ 0x1718c)"),
    (0x5c292, "word", "DAT_0005c292", "accelerator_pedal_throttle_range",
     "e2m 1048 +4 Throttle_Range (%THROTTLE) 'sum of this and Auto_Zero = 100% Commanded_Throttle': "
     "cm848_calculateCommandedThrottleFromPedal divides (pedal - autozero) x 400 by it (lhz @ 0x17124)"),
    (0x5c2a6, "word", "DAT_0005c2a6", "accelerator_pedal_autozero_time_limit",
     "e2m 1048 +18 TPS_AZ_Time_Limit (MSEC) 'Time limit to allow for setting a new Throttle_Min & Auto_Zero': "
     "cm848_learnAcceleratorPedalAutozero stops learning once accelerator_pedal_autozero_elapsed_time exceeds it "
     "(lhz @ 0x173f8)"),
    (0x64428, "word", "DAT_00064428", "intake_air_heater_performance_test_recovery_sample_delay_ticks",
     "e2m 162A +4 IAH_Grid_Off_Voltage_Check_Delay 'Delay between grid-off and taking voltage sample': loaded into "
     "intake_air_heater_performance_test_delay_ticks when state 2 ends (the preheat is over) and the test moves to "
     "state 3, the recovery after the heater turns off (lhz @ 0x532880); 2 in ROM"),
]
map_rows = []
for address, typ, label, name, comment in NAME:
    k = [i for i, l in enumerate(g) if l.startswith(f"0x{address:08x},,{typ},")]
    assert len(k) == 1, hex(address)
    old_comment = g[k[0]].split(",", 3)[3]
    g[k[0]] = f"0x{address:08x},{name},{typ},{comment} (PR #53 round 24) | earlier note: {old_comment}"
    map_rows.append(f"0x{address:08x},{name},{label},global")
for address, typ, label, name, comment in NEW:
    assert not any(l.startswith(f"0x{address:08x},") for l in g), hex(address)
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"0x{address:08x},{name},{typ},{comment} (PR #53 round 24)")
    map_rows.append(f"0x{address:08x},{name},{label},global")
open(gp, "w").write("\n".join(g))
with open(map_path, "a") as fh:
    fh.write("\n".join(map_rows) + "\n")
print(len(NAME), "rows named,", len(NEW), "rows added,", len(map_rows), "map rows")
