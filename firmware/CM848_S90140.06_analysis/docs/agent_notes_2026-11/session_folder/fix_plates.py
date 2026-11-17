"""Point the plate comments at the new struct fields; correct the J1939 pedal 'no reader' claim."""
import sys

path = sys.argv[1]
t = open(path).read()
EDITS = [
    ("(or minus boost_pressure_fixed_reference when boost_uses_barometric_pressure_flag is 0)",
     "(or minus barometric_pressure_sensor_config.default_value - the barometric channel's default - when boost_uses_barometric_pressure_flag is 0)"),
    ("config struct 0x5ab84 holds cruise_engage_adc_valid_lower/upper",
     "its config cruise_switch_sensor_config (0x5ab84) high_threshold / low_threshold are the validity window governor_cruise_engage_check reads (were cruise_engage_adc_valid_upper / _lower)"),
    ("-> j1939_accelerator_pedal_position (raw x 16 / 10 = 0.25 %/bit - the local pedal scale)",
     "-> sensor_channel13_ram.held_value (raw x 16 / 10 = 0.25 %/bit - the local pedal scale; was j1939_accelerator_pedal_position) with its priority in .held_value_source_priority"),
    ("j1939_accelerator_pedal_position has NO reader in S90140.06 so a J1939 pedal never reaches fueling",
     "with the same bit 13 set the accelerator pedal channel (13) outputs held_value in place of its sensor (the sensor-channel functions read it through state_ptr) - so the J1939 pedal DOES reach sensor_channel_filtered_output[13]; it was read as having no reader because nothing names the address"),
    ("and fuel_level_unfiltered within 20 of the last sample", "and fuel_level_sensor_channel_state.value within 20 of the last sample"),
    ("if fuel_level_unfiltered differs from the stored slow level", "if fuel_level_sensor_channel_state.value differs from the stored slow level"),
    ("moves 3341/65536 of the way to fuel_level_unfiltered each run", "moves 3341/65536 of the way to fuel_level_sensor_channel_state.value each run"),
]
for old, new in EDITS:
    assert t.count(old) == 1, old
    t = t.replace(old, new)
open(path, "w").write(t)
print("plates updated:", len(EDITS))
