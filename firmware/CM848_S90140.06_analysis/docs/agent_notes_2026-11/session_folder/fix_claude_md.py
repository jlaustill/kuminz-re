"""Correct the J1939 pedal 'dead end' bullet and the sensor-channel notes in firmware/CLAUDE.md."""
import sys

path = sys.argv[1]
t = open(path).read()
OLD_DBW = t[t.index("- **Drive-by-wire dead end (task 022):**"):]
OLD_DBW = OLD_DBW[:OLD_DBW.index("\n")]
NEW_DBW = (
    "- **J1939 pedal path (task 022 - CORRECTED 2026-11-16, was \"drive-by-wire dead end\"):**\n"
    "  - `cm848_processJ1939AcceleratorPedalPosition` writes EEC2 SPN 91 (x 16 / 10 = 0.25 % per count, 400 = 100 %) into the accelerator pedal channel's state, `sensor_channel13_ram.held_value`, with its source priority in `.held_value_source_priority`.\n"
    "  - It runs only when bit 13 (0x2000) of `fuel_demand_feature_flags` is set and switch 7 is datalink-sourced (`switch_input_datalink_source_bits_cal` bit 7). That flag word is 0x3fda68 = EEPROM 0x5e6. It is really a per-channel bitmap: bit n makes channel n output its held value.\n"
    "  - With that same bit set, the sensor-channel functions output `held_value` in place of the pedal sensor. So the J1939 pedal DOES reach `sensor_channel_filtered_output[13]` (`accelerator_pedal_sensor_filtered`).\n"
    "  - The 2026-11-12 \"has no reader\" conclusion came from a name search. The channel reads the value through `state_ptr` + 6, which never names the address.\n"
    "  - Bit 0x2000 also switches `cm848_fuelDemandFinalCalculation` / `cm848_fuelDemandCoordinator` to their J1939-pedal branches.\n"
    "  - In this calibration the bitmap is 0 and the J1939 input layer is off (`j1939_input_processing_enable_cal` bit 0x400 = 0), so using it means EEPROM changes: the bitmap bit, the switch-7 datalink bit and the input-layer enables. Bench-test them before driving. TSC1 remains the other J1939 fueling path.\n"
    "  - The CM1 fan request output is write-only.")
assert t.count(OLD_DBW) == 1
t = t.replace(OLD_DBW, NEW_DBW)

OLD_OUT = t[t.index("- **Outputs:** `value_output_ptr` receives"):]
OLD_OUT = OLD_OUT[:OLD_OUT.index("\n- **Still untyped:**")]
NEW_OUT = ("- **Outputs (renamed 2026-11-16):** `value_output_ptr` receives `sensor_channel_filtered_output[channel]`, the filtered engineering value, into the `<channel>_value` globals (were `*_raw`: `sensor_channelN_value`, `boost_pressure_sensor_value` 0x40bd8e = channel 1 intake manifold pressure, `fuel_timing_sensor_value`). "
           "`default_value_output_ptr` receives the config default into the `<channel>_default_value` globals (were `*_filtered`; e.g. `map_fuel_correction_factor` falls back to `boost_pressure_sensor_default_value`). "
           "Verified in the disassembly: the last stores are `lhzx` of the filtered output and `lhz 2(config)`. The status is 0 in range / 1 debouncing (value held) / 2 fault confirmed (default used) / 0x100 channel not enabled.")
t = t.replace(OLD_OUT, NEW_OUT)
OLD_UNTYPED = t[t.index("- **Still untyped:** 26 config"):]
OLD_UNTYPED = OLD_UNTYPED[:OLD_UNTYPED.index("\n")]
NEW_UNTYPED = ("- **Blocks with named fields (typed 2026-11-16):** 24 blocks used to keep a named row inside, and those rows are now struct fields:\n"
               "  - the barometric channel's default `barometric_pressure_sensor_config.default_value` (was `boost_pressure_fixed_reference`), which `cm848_calculateBoostPressure` subtracts when it uses no barometer;\n"
               "  - the cruise switch validity window `cruise_switch_sensor_config.high_threshold` / `.low_threshold` (were `cruise_engage_adc_valid_upper` / `_lower`);\n"
               "  - `fuel_level_sensor_channel_state.value` (was `fuel_level_unfiltered`);\n"
               "  - the J1939 pedal pair on `sensor_channel13_ram`, and filter accumulators.\n"
               "  - Filter states are named `<x>_filter_state` (were `*_ptr` / `*_pointer`), and the words their coefficient points at are `<x>_filter_coefficient` (36, typed `word`).")
t = t.replace(OLD_UNTYPED, NEW_UNTYPED)
open(path, "w").write(t)
print("firmware/CLAUDE.md corrected")
