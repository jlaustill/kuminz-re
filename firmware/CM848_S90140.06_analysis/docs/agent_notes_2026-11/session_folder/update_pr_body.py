"""PR #50 body: the follow-up commit and the J1939 pedal finding."""
import sys

p = sys.argv[1]
t = open(p).read()
EDITS = [
    ("| `(word *)&` cast lines | 966 | 48 (EEPROM buffers, and the 26 sensor blocks left untyped on purpose) |",
     "| `(word *)&` cast lines | 966 | 20 (mostly EEPROM buffers) |"),
    ("| `(sensor_channel_config_t *)&` / `(dword *)&` casts at sensor-channel calls | 48 / 50 | 6 / 2 |",
     "| `(sensor_channel_config_t *)&` / `(dword *)&` casts at sensor-channel calls | 48 / 50 | 0 / 2 |"),
    ("## Finding for the bench",
     "10. **Sensor / filter blocks with named fields, and honest output names.**\n"
     "    - **Blocks typed:** the 24 blocks the previous step skipped are typed, and their interior names became fields:\n"
     "      - `barometric_pressure_sensor_config.default_value` (was `boost_pressure_fixed_reference`).\n"
     "      - `cruise_switch_sensor_config.high_threshold` / `.low_threshold` (were `cruise_engage_adc_valid_*`).\n"
     "      - `fuel_level_sensor_channel_state.value`.\n"
     "      - The J1939 pedal pair: `sensor_channel13_ram.held_value` / `.held_value_source_priority`. +8 is a byte, so the state struct splits its spare word.\n"
     "    - **Filter names:** filter states are `<x>_filter_state` (25 renamed from `*_ptr` / `*_pointer`), and their 36 coefficient words are `word` / `<x>_filter_coefficient`.\n"
     "    - **Output names:** `<x>_value` / `<x>_default_value` (52 renamed from `*_raw` / `*_filtered`). The disassembly shows argument 10 gets the filtered output and argument 11 the config default. `boost_pressure_sensor_value` (0x40bd8e) is channel 1's filtered intake manifold pressure; the docs that called it \"raw\" are fixed.\n"
     "    - **Checks:** 155 functions change, all traced to the renamed / typed symbols. One of my apply scripts briefly blanked every auto-label row; those names are restored and every remaining row change was checked against the plan.\n\n"
     "## Finding for task 022: the J1939 pedal reaches fueling\n\n"
     "The 2026-11-12 \"EEC2 pedal = dead end\" conclusion was wrong. That value is the accelerator channel's `held_value` (state + 6), and the sensor-channel functions read it through `state_ptr`, which a name search can't see.\n\n"
     "- `cm848_processJ1939AcceleratorPedalPosition` writes SPN 91 x 16 / 10 into `sensor_channel13_ram.held_value`. It runs when EEPROM 0x5e6 (`fuel_demand_feature_flags`, really a per-channel hold bitmap) has bit 13 set and switch 7 is datalink-sourced.\n"
     "- With that bit set, channel 13 outputs `held_value`, and `cm848_fuelDemandFinalCalculation` takes fuel demand from `accelerator_pedal_sensor_filtered`.\n"
     "- The pedal channel's own table maps ADC 39..839 to 0..400. That is the same 0.25 % per count as the J1939 writer, so this is a designed drop-in J1939 pedal mode.\n"
     "- Enabling it means EEPROM changes, a bench job: bit 13 of 0x5e6, the switch-7 datalink bit at 0x74c, `j1939_input_processing_enable_cal` 0x400, and the input-7 enable.\n\n"
     "## Finding for the bench"),
]
for old, new in EDITS:
    assert t.count(old) == 1, old[:50]
    t = t.replace(old, new)
open(p, "w").write(t)
print("pr body updated")
