"""Round 16 closing: CSV comments the refresh missed, the firmware/CLAUDE.md wording refreshes for the retired
'vehicle speed limit' vocabulary, the leads that round 16 resolved, and the round 16 sections of task 046, the PR
body, the session README and the todo line. Idempotent. usage: apply_r16_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
R16 = "PR #53 round 16"


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return  # already applied
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


def append_line(rel, prefix, note):
    """Append note to the one line that starts with prefix (after its indentation)."""
    p = path(rel)
    lines = open(p).read().split("\n")
    hits = [i for i, l in enumerate(lines) if l.lstrip().startswith(prefix)]
    assert len(hits) == 1, (rel, prefix[:60], hits)
    if not lines[hits[0]].endswith(note):
        lines[hits[0]] += note
    open(p, "w").write("\n".join(lines))


GV = "firmware/CM848_S90140.06_analysis/output/global_variables.csv"
edit(GV, "this word is 0, it calls cm848_presetCruiseAndVehicleSpeedLimitGovernor.",
     "this word is 0, it calls cm848_presetCruiseAndRoadSpeedGovernor.")
edit(GV, "(was cruise_speed_upper_limit_ptr, a word row read as a pointer) (was cruise_speed_upper_limit_ptr word)",
     "(was cruise_speed_upper_limit_ptr, a word row read as a pointer)")
edit(GV, "cm848_presetCruiseAndRoadSpeedGovernor points cruise_speed_upper_limit_ptr (a fuel limit",
     "cm848_presetCruiseAndRoadSpeedGovernor points cruise_governor_fueling_maximum_pointer (a fuel limit")
CM = "firmware/CLAUDE.md"
edit(CM, "and a cruise vehicle speed limit (`cm848_calculateMaximumRoadSpeeds`)",
     "and the maximum road speeds (`cm848_calculateMaximumRoadSpeeds`)")
edit(CM, "adds 10 vehicle speed limit, 11 low speed governor", "adds 10 road speed governor, 11 low speed governor")
edit(CM, "the high speed governor fuel and the vehicle speed limit fuel.",
     "the high speed governor fuel and the road speed governor fuel.")
edit(CM, "the cruise / vehicle speed limit governor functions", "the cruise / road speed governor functions")
# the leads round 16 resolved
T = "work/tasks/"
edit(T + "025-cm848-naming-wave-followups.md",
     "computes the road speed limit (cruise_speed_limit_working / cruise_speed_high_limit).",
     "computes the road speed limit (cruise_speed_limit_working / cruise_speed_high_limit). (" + R16 + ": "
     "cm848_calculateMaximumRoadSpeeds, road_speed_governor_reference_speed / cruise_maximum_road_speed_trim_cal.)")
append_line(T + "027-cm848-naming-wave-2-followups.md", "- Servo-side cruise helpers still named protection*:",
            " (Resolved by " + R16 + ": cm848_decreaseCruiseSpeedCommand / cm848_increaseCruiseSpeedCommand / "
            "cm848_minimumSignedWord / cm848_presetCruiseAndRoadSpeedGovernor / cm848_runCruiseAndRoadSpeedGovernor and "
            "the e2m 118F ramps and steps.)")
append_line(T + "027-cm848-naming-wave-2-followups.md", "- cm848_validateFuelRateTarget (0x40d74) actually validates",
            " (" + R16 + ": cm848_restoreSavedCruiseSetSpeed, which restores cruise_saved_set_speed_cal at power-up.)")
append_line(T + "027-cm848-naming-wave-2-followups.md", "- protection_fuel_rate_step_a_param_cal / _step_b / _ramp_param_cal",
            " (" + R16 + ": cruise_coast_ramp / cruise_bump_down_step / cruise_accelerate_ramp, e2m 118F.)")
append_line(T + "027-cm848-naming-wave-2-followups.md", "- Cruise-only 'protection' fuel-rate symbols",
            " (Resolved by " + R16 + ".)")
edit(T + "042-table-campaign-rename-leads.md", "  `cruise_speed_target_working`, `engine_data_log_buffer`,",
     "  `cruise_speed_target_working` (`cruise_resume_speed` since " + R16 + "), `engine_data_log_buffer`,")
append_line(T + "042-table-campaign-rename-leads.md", "- [W6 governor] UNCERTAIN 0x003fd910",
            " (" + R16 + ": governor_cruise_rampScale_calc is cm848_calculateBottomDroopGain, and 0x3fd910 is "
            "cruise_bottom_droop_width_cal, e2m 1185 +2.)")
append_line(T + "042-table-campaign-rename-leads.md", "- [W9 gear_down] `governor_cruise_speedError_torqueAdj` (0x00525134)",
            " (" + R16 + ": cm848_calculateCruiseGovernorEngineSpeedError.)")
edit(T + "045-cm848-fueling-state-enum.md",
     "- `cruise_speed_limit_working`: both the cruise control and the vehicle speed limiter use it.",
     "- `cruise_speed_limit_working`: both the cruise control and the vehicle speed limiter use it. (" + R16 + ": "
     "`road_speed_governor_reference_speed`, the road speed governor's reference.)")
edit(T + "045-cm848-fueling-state-enum.md", "`cruise_speed_limit_working` = the vehicle speed limit.",
     "`cruise_speed_limit_working` = the vehicle speed limit (`road_speed_governor_reference_speed` since " + R16 + ").")
t46 = path(T + "046-cm848-egr-flow-estimate.md")
edit(t46, "  - **The switch bytes 0 / 1 / 3 as bitfields:** the user's call (the numbers above).",
     "  - **The switch bytes 0 / 1 / 3 as bitfields:** the user's call (the numbers above). (Done in round 16 stage C: "
     "the user approved it.)")
edit(t46, "    clamped to +-0x66), not a setpoint: name it with the cruise governor.",
     "    clamped to +-0x66), not a setpoint: name it with the cruise governor. (Round 16: "
     "`cruise_governor_filtered_road_speed`, the derivative filter output.)")
edit(t46, "    rename them to the `cruise_governor_*` words with the functions.",
     "    rename them to the `cruise_governor_*` words with the functions. (Done in round 16.)")
edit(t46, '    speed limit".\n',
     '    speed limit". (Done in round 16: `road_speed_governor_*` is the one vocabulary.)\n')
TASK = """## Done, round 16 (2026-11-21, same PR; the relayed "keep going" again): the cruise control / road speed governor

Scripts are in `session_folder/round16/`.
- **The records:** the parameter ID table places e2m 117D / 117F / 1180 / 1184-1191 and 11A4-11A6. Each record was
  checked against its code use, and the 59 renamed rows with records match their e2m sizes (`width_r16a.txt`).
- **Vocabulary decisions** (kept here; the user promoted only the round 11-15 methods into firmware/CLAUDE.md):
  - **The road speed governor is `road_speed_governor_*`.** The e2m calls it RSG (`Road_Speed_Governor_Enable`), and
    its siblings in `FUELING_STATE` are the low / high / variable / all speed governors. `vehicle_speed_limit_*` is
    retired, and state 10 is `FUELING_STATE_ROAD_SPEED_GOVERNOR`. `fault_vehicle_speed_limit*` keeps its name: it is
    the fault ramp, a different limit.
  - **The shared cruise / RSG PID** keeps `cruise_pid_*` for its terms and gains (PID is an allowed abbreviation). Its
    other words are `cruise_governor_*`: the 8 `governor_cruise_*` and 8 `cruise_zone_*` rows are gone.
  - **Gain sets, not zones:** the e2m says 'Switch to Cruise/RSG gain set 2 when tracking error is > this'.
  - **The sump** (e2m `Cruise_RSG_Sump_*`, explained from its uses): fuel held outside the integrator and added to
    the PID sum. It drains toward 0 by the decrement / increment rates. A preset fills it with final_fueling minus the
    preset fueling, a trigger fills it with `Sump_Fuel_Init_Gain` x the road speed change, and a gain set change fills
    it with the step that keeps the output. The old `rate_correction` / `fuel_demand_delta` words were one mechanism
    under two vocabularies.
  - **The maximum road speeds pair with their trims:** `maximum_road_speed` (117D +16; PGN 65261 SPN 74, was
    `j1939_cruise_speed_setpoint`) / `maximum_road_speed_trim_cal` (1180 +4), `cruise_maximum_road_speed_cal` (117F +10)
    / `cruise_maximum_road_speed_trim_cal` (1180 +2). `road_speed_governor_reference_speed` (was
    `cruise_speed_limit_working`) is the trim lowered by the fault ramp.
- **Stage A (9b3450f, label-only):** 77 globals, 6 type-only rows named by their default labels, 20 functions and 6
  enum members (EQUIVALENT, 109 names).
  - `CRUISE_CONTROL_STATE` from the value list of e2m 1184 +2 Cruise_Command_Mode, 'off / set / resume / coast / accel
    / bump down / bump up / hold / cancel': `CRUISE_COAST` / `CRUISE_BUMP_DOWN` / `CRUISE_BUMP_UP` / `CRUISE_HOLD` /
    `CRUISE_CANCEL` (were DECELERATE / DECELERATE_2 / ACCELERATE_2 / ACTIVE_HOLD / STANDBY). Every case of
    `cm848_cruiseSpeedCommandStateMachine` fits, and cancel keeps the resume speed where off clears it. The old
    comments assumed J1939 SPN 527 states.
  - e2m 118F: `cruise_accelerate_ramp` / `cruise_coast_ramp` / `cruise_bump_up_step` / `cruise_bump_down_step` /
    `cruise_minimum_coast_speed` / `cruise_minimum_set_speed` (were `protection_fuel_rate_*` / `cruise_speed_*_cal`;
    ROM, so no `_cal`). They drive `cm848_increaseCruiseSpeedCommand` / `cm848_decreaseCruiseSpeedCommand` (were
    `cm848_protectionFuelRateRamp` / `Step`).
  - The power-down save and power-up restore of the set speed: `cm848_saveCruiseSetSpeedForPowerDown` /
    `cm848_restoreSavedCruiseSetSpeed` (were `cm848_initFuelRateFromCapability` / `cm848_validateFuelRateTarget`),
    with `cruise_saved_set_speed_cal` (1191, EEPROM) and `cruise_resume_speed` (1190 +0).
  - `cm848_secondOrderFilterUnsigned` (was `cm848_interpolateTableLinearStep`) is a second order filter. It returns
    0 in this build: the asm shifts the output down 16 twice (0x56640 / 0x5664c). So
    `cruise_governor_filtered_road_speed` is 0 except right after a preset, and the sump and the preset fueling window
    see no road speed change.
- **Stage B (9a1bd93, types):**
  - `cruise_governor_gain_set_t` with the three e2m 1186 sets and the typed pointer.
  - `second_order_filter_state_t` (coefficient 1 / 3 pointers, output / previous output) with two instances. The
    filter prototypes take it, so their bodies read `filter->output`.
  - `cruise_governor_fueling_maximum_pointer` is typed `word *`, which removes one underscore warning (25 -> 24).
  - 11 new rows for the governor's `DAT_` words.
- **Stage C (5945df3, types; the user's decision):** `switch_input_state_t` bytes 0 / 1 / 3 as bitfields.
  - 180 named bit accesses replace 198 masked byte-field accesses.
  - The cost is the round 11 pilot's: 10 piece lines in three setters, and `field_0x0` in two indexed loops.
  - The proof: `switch_normalize_r16c.py` + `cast_normalized_diff.py`. The 8 functions that differ are all in those
    classes.
- **Stage D (098ecfe, docs; the user's decision):** firmware/CLAUDE.md now has the round 11-15 methods and the
  switch exception to the wave 11 bitfield rule.
- **Round 16 leads:**
  - **The Q16 integrator at 0x3fd032** is a `word` row read as a dword (`_cruise_pid_integrator_q16`). The preset
    writes its halves apart (`DAT_003fd034` is the fraction). `q16_fixed_point_t` would print pieces for the dword
    stores; decide by a pilot.
  - **The engine retarder family** (e2m 1070 / 1071 / 1192), still open from round 15. 1192 +4 / +6 / +8 have no
    rows.
  - **`DAT_0040b5c0`:** only the power-up initializer writes it (the maximum road speed trim).
  - **e2m 8A0F +C / +E / +10** do not fit the CM848 words there (the engine warning flags), so the block drifts after
    +A.
  - **`governor_override_fuel_threshold_cal` (0x408e96)** is ROM, so it has a legacy `_cal`.

## Leads (not in this PR)
"""
t = open(t46).read()
if "## Done, round 16" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(t46, "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 16 (the relayed "keep going" again): the cruise control / road speed governor.**
- **Stage A (9b3450f, label-only):** the family from e2m 117D-1191, with one vocabulary: `road_speed_governor_*`
  (state 10 is `FUELING_STATE_ROAD_SPEED_GOVERNOR`), the cruise / RSG PID's gain sets, the sump and the preset
  fueling. It also names the maximum road speeds and their trims, the cruise speed command ramps and steps (e2m 118F)
  and `CRUISE_CONTROL_STATE` from its e2m value list.
- **Stage B (9a1bd93, types):** `cruise_governor_gain_set_t` and `second_order_filter_state_t`, the typed pointers and
  11 new rows.
- **Stage C (5945df3, types) and D (098ecfe, docs), the user's two decisions:** the switch bytes 0 / 1 / 3 as
  bitfields (180 named bit accesses for 10 piece lines), and the round 11-15 methods in firmware/CLAUDE.md.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 15: stages A and B are EQUIVALENT",
     "- [x] Round 16: stage A is EQUIVALENT (109 names); B and C are type diffs reviewed function by function (C "
     "with a mask-normalized cast diff); every renamed row's width matches its e2m size.\n"
     "- [x] Round 15: stages A and B are EQUIVALENT")
edit(pr, "- **Open after round 15:**\n  - the cruise / road speed governor family and the engine retarder family, the droop word at 0x40aedc "
         "(task 046);\n",
     "- **Open after round 16:**\n  - the engine retarder family, the cruise PID's Q16 integrator type, the droop word at 0x40aedc "
     "(task 046);\n")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 16" not in t:
    t += """

## Round 16: the cruise control / road speed governor (`session_folder/round16/`)

- **The records:** `blocks.txt` / `blocks2.txt` (e2m_block_addresses.py on 117D-1192), `check*_out.txt` (code lines
  per candidate), `width_r16a.txt` (the width check).
- **Stage A:** `worklist_r16a.py` (through apply_hand_worklist.py), `fill_r16a.json` (type-only rows, via
  round15/apply_r15a_fill.py) and `apply_r16a_enums.py`; `refresh_enums_structs.py` refreshes the two CSVs that
  refresh_references.py skips.
- **Stage B:** `apply_r16b.py`. **Stage C:** `apply_r16c_switch_bits.py` and the proof helper
  `switch_normalize_r16c.py`. **Closing:** `apply_r16_closing.py`.
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 16" not in lines[i]:
    assert lines[i].endswith("open: the cruise / road speed governor and engine retarder families"), lines[i][-80:]
    lines[i] += ("; round 16: the cruise control / road speed governor family from e2m 117D-1191 (one "
                 "road_speed_governor_* vocabulary, the gain set and second order filter structs, CRUISE_CONTROL_STATE "
                 "from its value list), the switch bitfields and the round 11-15 methods in firmware/CLAUDE.md (the "
                 "user's decisions) - open: the engine retarder family")
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
