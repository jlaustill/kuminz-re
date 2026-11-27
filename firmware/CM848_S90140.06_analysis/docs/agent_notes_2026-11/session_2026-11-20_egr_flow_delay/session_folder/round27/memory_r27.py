"""Round 27: MEMORY.md (the PR #53 line, the sensor channel line), the sensor channel note, the typing focus note."""
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
p = M + "MEMORY.md"
t = open(p).read()
t = t.replace("(cm848/egr-flow-delay-model, 153 commits)", "(cm848/egr-flow-delay-model, 157 commits)")
old = "mode-4 vehicle speed never reaches the filtered vehicle_speed); task 046 leads"
new = ("mode-4 vehicle speed never reaches the filtered vehicle_speed) + round 27 (the user approved: one bitfield per fault in "
       "fault_bit_words_t words 1-49 + the CLAUDE.md J1939 switch-input fix; the sensor channel layer's inverted names "
       "fixed); task 046 leads")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    t = t.replace(old, new)
old_line = [l for l in t.split("\n") if "(cm848_sensor_channel_init_process_inverted.md)" in l]
assert len(old_line) == 1
new_line = ("- [Sensor-channel _init/_process inversion - FIXED](cm848_sensor_channel_init_process_inverted.md) — round 27 "
            "(PR #53): wrappers are cm848_process<Channel>Channel (periodic) / cm848_initialize<Channel>Channel (boot); "
            "bases cm848_process/initialize{Signed,Unsigned}SensorChannel; the 8th arg is the channel (no ordinals left)")
t = t.replace(old_line[0], new_line)
open(p, "w").write(t)
open(M + "cm848_sensor_channel_init_process_inverted.md", "w").write("""---
name: cm848-sensor-channel-init-process-inverted
description: CM848 sensor channel wrapper / base names - the old _init / _process inversion is fixed (PR #53 round 27)
metadata:
  type: project
---

FIXED 2026-11-22 (PR #53 round 27, commit 084a1cc). The old `cm848_sensorChannelN_init` / `_process` wrappers had the
suffixes inverted (the `_init` ones ran every pass from periodic tasks, the `_process` ones once at boot from
`cm848_applicationMain`), and so did the Bank 2 bases (`sensorChannelConfigInit` was the periodic pass).

Names now:
- bases: `cm848_processSignedSensorChannel` (0x500234) / `cm848_initializeSignedSensorChannel` (0x500a4c) and
  `cm848_processUnsignedSensorChannel` (0x5012dc) / `cm848_initializeUnsignedSensorChannel` (0x501b4c). Signed =
  lookup flags 2, lha, cm848_signedFirstOrderFilter; unsigned = flags 0, lhz, exponentialMovingAverage, plus
  threshold-fault exceptions for channels 47 / 71 / 10 (machine code diff).
- wrappers: `cm848_process<Channel>Channel` (periodic) / `cm848_initialize<Channel>Channel` (boot), 34 pairs.
- blocks: `<x>_sensor_config` / `_sensor_channel_state` / `<table base>_cached_axis_offset` / `_sensor_filter_state`
  / `_sensor_value` / `_sensor_default_value` / `_sensor_fault_status`; for an x that already contains "sensor"
  (sensor_reference_voltage_*, engine_speed_sensor_supply_voltage) drop the `_sensor` infix.

The channel number is the 8th argument (the `sensor_channel_filtered_output` slot). Identify a channel by its fault
bits (e2m 1036 names in fault_bit_words_t) and its e2m 1966 / 1963 outputs; e2m "SV" = supply voltage.
Finding kept for the user: disabled channel 88 (exhaust throttle position) writes the fuel temperature outputs.
""")
f = M + "typing_focus_2026_11.md"
note = ("  - Round 27 (2026-11-22, the user said \"approved\" to both round 26 questions): 084a1cc the sensor channel layer "
        "(inverted base / wrapper names fixed, 91 blocks named by channel from e2m; channel 88 = exhaust throttle "
        "position writes the fuel temperature outputs); 04b419e the J1939 descriptor's third field = logical_switch "
        "(brake 11 / clutch 15 / PTO 3 / remote PTO 19 / interlock 26 / rest 31) + the CLAUDE.md mechanism fix; "
        "2eb75f6 one bitfield per fault in fault_bit_words_t words 1-49 (word 0 stays plain: the indexed base; a "
        "nested type per word renders ZPULL, rejected). Trade: 674 tests + 109 writes named vs 943 pieces (856 on "
        "set / clear writes). Proof = rewrite each bit name back to its word + mask (prove_fault_bitfields.py). "
        "Harness: heredocs and shell functions in Bash are refused - write scripts to files.\n")
if "Round 27 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("memory updated")
