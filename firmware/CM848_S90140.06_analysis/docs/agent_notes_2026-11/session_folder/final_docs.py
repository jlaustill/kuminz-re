"""Final doc fixes for wave 3: CLAUDE.md stats / time-shared note / stuck-underscore table, todo 042, task 042,
and the 0x40b9e6 type."""
import sys

repo = sys.argv[1]
p = f"{repo}/firmware/CLAUDE.md"
t = open(p).read()
for old, new in [
    ("519 of the 564 unnamed tables are named; 45 stay `WORD_ARRAY_`",
     "524 of the 564 unnamed tables are named (5 more on a retry after the rename waves); 40 stay `WORD_ARRAY_`"),
    ("confidence (39 % medium)", "confidence (40 % medium)"),
    ("| `_governor_mode_state` (12×),", "| `_engine_retarder_override_control_mode` (12×, was `_governor_mode_state`),"),
    ("| `_sensor_validation_delta`,", "| `_oil_change_monitor_distance_pulses_cal` (was `_sensor_validation_delta`; 0x3fee3a is also time-shared with the boot ROM),"),
]:
    assert t.count(old) == 1, old
    t = t.replace(old, new)
anchor = "the trip distance dword still renders as `ram0x003fee28`."
assert t.count(anchor) == 1, "time-shared anchor"
t = t.replace(anchor, anchor + " The boot-time use goes on past 0x3fee2f: `mpc555_eepromValidationCycle` counts in the dword at "
              "0x3fee34, `cm848_lookupEepromParameterAddress` returns 0x3fee38 and `cm848_bootSciCheckSecurityKey` reads the "
              "bytes 0x3fee3a-0x3fee3d, while the application keeps its oil change monitor there (EEPROM 0x19b2-0x19bb) - "
              "retyping those words for the application made the boot code worse (2026-11-16), so they keep their types.")
open(p, "w").write(t)

p = f"{repo}/work/todo.md"
t = open(p).read()
old = "still open: the agents' further leads and type notes in tasks/042-table-campaign-rename-leads.md"
new = ("wave 3 DONE too (53 functions, 183 globals, 16 struct fields, 21 duplicate names, 31 junk rows, 113 new rows); "
       "still open: wave 3's 9 uncertain items and 49 notes in tasks/042-table-campaign-rename-leads.md")
assert t.count(old) == 1, "todo anchor"
open(p, "w").write(t.replace(old, new))

p = f"{repo}/work/tasks/042-table-campaign-rename-leads.md"
open(p, "a").write("""
### Wave 3 review checks
- `engine_speed_limp_home_active_flag` (was `crank_position_valid_flag`) confirmed apart from e2m: `cm848_enterSpeedLimpHome`
  switches the TPU-A speed input from channel 0 to channel 1 and, after its debounce above a speed, sets fault 335 =
  P0336 (crankshaft position sensor signal); the RAM dump (engine off) holds 0.
- Five new rows do not render: the alternator regulator thresholds 0x4087a2-0x4087b0 - their only readers are the
  four regulator state handlers at ROM 0x38338-0x3844c, which Ghidra has not made functions.
- No new row overlaps another row or array; no renamed ROM-to-RAM-window global is used by boot-ROM code; no
  duplicate names remain; the importer's type stats are unchanged.
- CM550 also uses the old `governor_mode_state` (now `engine_retarder_override_control_mode` in CM848) - one more
  cross-firmware link to check on the CM550 side.
- Naming convention left for the user: about nine wave-3 functions say `initialize` (spelled out by the renaming
  gate), while the repo's older functions say `init`.
""")
p = f"{repo}/firmware/CM848_S90140.06_analysis/output/global_variables.csv"
t = open(p).read()
old = "0x0040b9e6,intake_air_heater_performance_test_recovery_voltage_rise_adc,word,"
assert t.count(old) == 1
open(p, "w").write(t.replace(old, "0x0040b9e6,intake_air_heater_performance_test_recovery_voltage_rise_adc,i16,"))
print("ok")
