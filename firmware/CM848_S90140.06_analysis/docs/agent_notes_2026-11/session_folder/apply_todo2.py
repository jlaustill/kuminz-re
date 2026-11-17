"""todo.md: 022 J1939 pedal correction; 041 sensor follow-ups done."""
import sys

p = sys.argv[1]
t = open(p).read()
old22 = "022 [>] [firmware/oct] CM848D J1939 drive-by-wire — trace j1939_governor_config_flags gate, enable TSC1 speed control"
new22 = (old22 + " | 2026-11-16 (PR #50): the EEC2 pedal path is NOT a dead end - EEPROM 0x5e6 bit 13 makes the accelerator "
         "pedal channel output its held value, which cm848_processJ1939AcceleratorPedalPosition fills with SPN 91 at the "
         "channel's own 0.25 %/count scale, and cm848_fuelDemandFinalCalculation takes fuel demand from it; needs "
         "that bit + EEPROM 0x74c bit 7 (switch 7 datalink) + j1939_input_processing_enable_cal 0x400 + the input-7 "
         "enable - bench before driving (see firmware/CLAUDE.md J1939 pedal path)")
assert t.count(old22) == 1
t = t.replace(old22, new22)
start = t.index("STILL OPEN there: 26 blocks")
end = t.index("sensor state blocks among the 26);", start) + len("sensor state blocks among the 26);")
t = t[:start] + ("DONE too: the 24 blocks with named rows inside are typed (their names became struct fields - e.g. "
                 "barometric_pressure_sensor_config.default_value / cruise_switch_sensor_config.high_threshold / "
                 "fuel_level_sensor_channel_state.value), filter states are <x>_filter_state, their 36 coefficient "
                 "words <x>_filter_coefficient, and the value / default outputs are <x>_value / <x>_default_value "
                 "(were *_raw / *_filtered); 20 (word *)& casts left (EEPROM buffers and a few others);") + t[end:]
open(p, "w").write(t)
print("todo updated")
