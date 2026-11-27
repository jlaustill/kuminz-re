"""Round 15 closing: a structure_definitions.csv comment (the refresh skips that file), the odometer doc table, the task
notes that described round 15's rows, and the round 15 sections of task 046, the PR body, the session README and the
todo line. usage: apply_r15_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
R15 = "PR #53 round 15"


def edit(rel, old, new):
    p = rel if os.path.isabs(rel) else os.path.join(repo, rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return  # already applied (a re-run)
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


edit("firmware/CM848_S90140.06_analysis/output/structure_definitions.csv",
     "(j1939_reference_engine_fueling - fuel_demand_norm_zero_cal) x percent",
     "(j1939_reference_engine_fueling - zero_torque_fueling) x percent")
edit("firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md",
     "| `0x0040BDF6` | `sensor_channel102_value` |", "| `0x0040BDF6` | `governor_pressure_sensor_value` |")
edit("work/tasks/025-cm848-naming-wave-followups.md",
     "a derate latch that also blocks the phase 1 -> 2 move; name misleads.",
     "a derate latch that also blocks the phase 1 -> 2 move; name misleads. (Resolved by " + R15 + ": the ECU's "
     "parameter ID table places e2m 1096 +0 Engine_Startup_Inhibit, its own block, at 0x3fdfdc - "
     "engine_startup_inhibit_cal.)")
edit("work/tasks/025-cm848-naming-wave-followups.md", "- Outside the list: fuel_demand_base_offset 0x40aeec",
     "- Outside the list: fuel_demand_base_offset 0x40aeec (no_load_fuel_quantity since " + R15 + ", e2m 109C)")
edit("work/tasks/042-table-campaign-rename-leads.md", "- `sensor_channel7_fault_status` at 0x0040be18 and 0x0040be3a",
     "- `sensor_channel7_fault_status` at 0x0040be18 and 0x0040be3a (" + R15 + ": the channel 7 one at 0x40be3a is "
     "fuel_temperature_sensor_fault_status)")
edit("work/tasks/042-table-campaign-rename-leads.md", "- `protection_iat_scaled`, `governor_cold_start_iat_correction`",
     "- `protection_iat_scaled` (`initial_ambient_air_pressure` since " + R15 + "), `governor_cold_start_iat_correction`")
t46 = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(t46, "    `governor_speed_error_prev_snapshot`, `governor_speed_low_clamp`; e2m 1064 / 1065).\n",
     "    `governor_speed_error_prev_snapshot`, `governor_speed_low_clamp`; e2m 1064 / 1065). (Resolved in round 15.)\n")
edit(t46, "  - `sensor_channel9_ram` (0x40a0e6) is the state of the `cm848_sensorChannel9_*` wrappers.",
     "  - `sensor_channel9_ram` (0x40a0e6) is the state of the `cm848_sensorChannel9_*` wrappers (round 15: it is "
     "slot 7's state, `fuel_temperature_sensor_channel_state`).")
TASK = """## Done, round 15 (2026-11-21, same PR; the relayed "keep going" again): the e2m pool above 0.2 overlap, part 1

Scripts are in `session_folder/round15/`.
- **The pool:** `pool_r15.py` lists the rows whose name shares 20-50 % of the words of their table-resolved e2m record.
  It uses wave 15's filter: used in the code, dump value in range, and not reviewed before. The three bands (0.2-0.25 /
  0.25-0.34 / 0.34-0.5) hold 108 / 103 / 169 rows. Each candidate is checked against its code use and its width before
  it is named.
- **Stage A (123d6ae, label-only): sixteen sensor channels, named as families.**
  - e2m 1966 is the sensor channels' value / default outputs.
  - Each channel number is proved by its sensor channel calls (channel_index = argument 8). The fault bits decode to
    the sensors' DTCs: 21 / 28 / 42 are sensor reference voltages C / B / A (P0699 / P0653 / P0643), 97 / 98 are pedal
    position sensors 1 / 2 (P2123 / P2128), 76 is the 4WD switch (P0839), and 102 is the governor pressure (P0868).
  - Each channel's config, state, filter, cache, value, default and fault status rows are named (124 rows).
  - The state records carried the wrapper ordinals: channel 7's was `sensor_channel9_ram`.
- **Stage B (359ecb7, label-only):**
  - **The tachometer outputs:** e2m 1565 / 151C / 1527 name the output channel map and its duty / period caches entry
    by entry, and they agree with every entry proved before.
    - Entries 25 / 26 (todo 035's actuators c / d) are the tachometer high / low side drivers.
    - `cm848_driveTachometerOutputs` (was `cm848_processEngineRpmDiagnostic`) sets the period to
      `tachometer_base_period` x 1e6 / engine speed at 50 % duty.
  - **Also:** the 4D fueling maps (e2m 1054-1059), the LSG leftovers, and the 100 % throttle fueling at the LSG
    reference.
  - **Checked singles:** initial ambient air pressure, the AFC thresholds, the OCM reset flag, no-load fuel, zero torque
    fueling, the VSS noise counter, the axle ratio learn delay, the flash failure flag and the engine startup inhibit.
- **Round 15 leads:**
  - **The cruise / road speed governor family** (e2m 117D / 1180 / 1184-118F / 1190): about 40 rows, and the
    `governor_cruise_*` / `cm848_protectionFuelRate*` functions. The firmware calls the road speed governor "vehicle
    speed limit".
  - **The engine retarder family** (e2m 1070 / 1071). Its records carry two value lists: `EB_Non_Override_Command_Source`
    1-6, and `EB_Brake_Type` 0-3 (a bitmask in this code).
  - **Types:**
    - The AFC slew rates (e2m 11D5 +C / +10 / +14) are 4-byte records on word rows: `_fuel_demand_load_threshold_d`
      renders with an underscore.
    - The 4D fueling caches are 4 bytes but typed `word`.
    - The 0x40a35c dword holds `EB_Immediate_Brake` and the next record.
  - **User commanded timing** (125C +2) and the 4D timing word (103B +0): one use adds the timing like an offset, so read
    the 125C enable first.
  - **`Main_Cold_Advance_Select`** (8085 +2: 0 add / 1 max wins / 2 min wins) is an enum candidate.
  - **The rest of the pool:** the 0.34-0.5 band, and the 27 records with code references and no name.

## Leads (not in this PR)
"""
t = open(t46).read()
assert t.count("## Leads (not in this PR)\n") == 1
open(t46, "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 15 (the relayed "keep going" again): the e2m pool above 0.2 overlap, part 1.**
- **Stage A (123d6ae, label-only):** sixteen sensor channels named as families from e2m 1966 (124 rows). Each channel
  is proved at its calls and by its DTCs.
- **Stage B (359ecb7, label-only):**
  - the tachometer outputs: e2m 1565 names the output channel map, and entries 25 / 26 are todo 035's "actuators c / d";
  - the 4D fueling maps, the LSG leftovers and checked singles.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 14: stages A and C are EQUIVALENT",
     "- [x] Round 15: stages A and B are EQUIVALENT; every renamed row's width matches its e2m size.\n"
     "- [x] Round 14: stages A and C are EQUIVALENT")
edit(pr, "- **Open after round 14:**\n  - the LSG PID internals and the droop word at 0x40aedc (task 046);\n",
     "- **Open after round 15:**\n  - the cruise / road speed governor family and the engine retarder family, the droop word at 0x40aedc "
     "(task 046);\n")
README = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
t += """

## Round 15: the e2m pool above 0.2 overlap, part 1 (`session_folder/round15/`)

- **The pool:** `pool_r15.py` (wave 15's filter, by overlap band) and `evidence_r15.py` (code lines per candidate).
- **Stage A:**
  - `channel_calls_r15.py` proves each channel at its calls.
  - `gen_channels_r15.py` and `make_worklist_r15a.py` build `worklist_r15a.py` (named rows) and `fill_r15a.json`
    (type-only rows, via `apply_r15a_fill.py`).
- **Stage B:** `worklist_r15b.py`. `width_check_r15.py` compares each row's width with its e2m size.
- **Closing:** `apply_r15_closing.py`.
"""
open(README, "w").write(t + "\n")
TODO = os.path.join(repo, "work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
assert lines[i].endswith("open: the LSG PID internals"), lines[i][-40:]
lines[i] += ("; round 15: sixteen sensor channels as families from e2m 1966, the tachometer outputs (e2m 1565 names the "
             "output channel map), the 4D fueling maps, checked singles - open: the cruise / road speed governor and "
             "engine retarder families")
open(TODO, "w").write("\n".join(lines))
print("comments, docs, task notes, task 046, PR body, README, todo")
