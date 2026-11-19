# 045 - CM848 fueling state enum (governor_fuel_demand_mode)

## Problem Statement

Is there enough information in the CM848 firmware to type `governor_fuel_demand_mode` (0x40a154) as an enum, and if
so, which members and which carriers?

## Current Understanding (2026-11-19)

**Yes.** The word is the Cummins **FSGVFLST** "Adjusted_User_Fueling_State": the code of the algorithm in control of the
fuel after the limiting governors. It is one slice of a single numbering that every fueling stage shares, so the enum
is shared too: `ENGINE_OPERATING_MODE` was renamed `FUELING_STATE`.

### Firmware evidence (the code alone)

- **Access census:** 35 accesses in both banks, all 16-bit (30 `lha` / 2 `lhz` / 3 `sth`). Every load feeds `cmpwi rX,K`
  (K = 2, 4-12) or a plain copy; no arithmetic, mask, index or ordering compare. No 32-bit pointer to 0x0040a154 exists
  in either bank, and no base+offset access reaches it.
- **Writers:** only `cm848_processProtectionRampControl` (`sth` @ 0x40558: `li 10` / `li 12` / `lha` of 0x40b67c;
  `sth` @ 0x4061c: `li 11`) and its initial value in `cm848_initFuelFilterCoefficients` (`sth` @ 0x4083c: 11).
- **The chain:** `engine_operating_mode` → `operating_mode_governor_output.mode_code` (= the mode, or 4 in
  `cm848_updateGovernorFromProtection`) → 0x40b67c (= `mode_code`, or 9 in `cm848_calculateProtectionLevelLimit`) →
  0x40a154 (= 0x40b67c, or 10 / 11 / 12 from the arbitration).
- **One numbering:** `cm848_processProtectionSelection` (0x1e5a4) min-selects `governor_fuel_demand_value` against
  `torque_derate_fuel_quantity` and writes the winner's code into ONE word, `governor_fuel_mode_arbitrated`: either
  `governor_fuel_demand_mode` (1-12) or `torque_derate_fuel_source_code` (13, 20, ...).
- **RAM dump:** `engine_operating_mode` 7, `mode_code` 7, 0x40b67c 7, 0x40a154 11, `governor_request_active_flag` 1,
  `governor_mode_code` 26.

### Members

| Value | Member | Evidence |
|---|---|---|
| 1, 2, 5, 6, 7, 8, 30 | the existing user-stage members (TSC1 torque / TSC1 speed / calibrated fixed fuel demand / accelerator pedal fault / variable speed governor / dual-axis fuel table / all-speed governor restore) | copied through the chain; code |
| 4 | `FUELING_STATE_POWER_TAKE_OFF` | code: `governor_fuel_demand_command` replaces the user fueling. "Power take-off" is e2m-derived (block 1265, below) - medium |
| 9 | `FUELING_STATE_CRUISE_CONTROL` | code: cruise engaged and the cruise PID fuel wins; the cruise_control_state branches run in 9 |
| 10 | `FUELING_STATE_VEHICLE_SPEED_LIMIT` | code: the limit fuel from `cruise_speed_setpoint_adjusted` (= `vehicle_speed`, rate limited) against `cruise_speed_limit_working`; `protectionRampRateControl` runs the limit-minus-speed error in 10 |
| 11 | `FUELING_STATE_LOW_SPEED_GOVERNOR` | code: max select at or below the governor speed; only in 11 does `cm848_processSpeedGovernorControl` write `governor_fuel_demand_value`; the initial value; RAM dump 11 |
| 12 | `FUELING_STATE_HIGH_SPEED_GOVERNOR` | code: `governor_fuel_demand_value = high_speed_governor_fueling`; `runHighSpeedGovernorPid` resets its integrator in 12 |
| 37, 38 | no member | only compared, never stored (as before) |

### Cross-firmware and e2m corroboration

- **CM550 0x0080a8f2** = e2m FSGVFLST (block 1045 +2; the CM550 name `indicator_as_to_which_algorithm_is_in_control_of_fueling_after_it_1_12`).
  The shared `runHighSpeedGovernorPid` compares it with 12 in both firmwares (CM848 0x1f40c / CM550 0x1ce7c), and CM550
  compares it with 3-12 elsewhere.
- **e2m state ranges** (the description ends with the range): FSDSFLST user fueling state `~1-8,38`, PTSLFLST selected
  user / PTO state `~1-8`, FSGVFLST governed `~1-12`, FSLMFLST limited `~13-41`, FSFNFLST final `~1 - 41` (with the
  label `29=ATDERAT`).
- **Block 1045** FSGVFL (mm3/stroke x 0.0679348) / FSGVFLST / LSLOFG (T/F) = CM848 0x40a152 / 0x40a154 / 0x40a156:
  the 5888-count cap is 400 mm3 at 0.0679348, and `governor_request_active_flag` latches while the state is 11.
- **Block 1265** PTTHDQRP (rpm) / PTTHOV (T/F) / PTSLFL / PTSLFLST = CM848 0x40af56 / 0x40af58 / 0x40af5a / 0x40af5c:
  the rpm limit and the flag are set in the throttle-wins branch of `cm848_updateGovernorFromProtection`, and the
  fuel / state are `operating_mode_governor_output`.

## Changes (2026-11-19, PR #52, branch cm848/fueling-state-enum)

- `enums.csv`: `ENGINE_OPERATING_MODE` → `FUELING_STATE` (members renamed), + 4 / 9 / 10 / 11 / 12.
- Typed `FUELING_STATE`: 0x40b000 `engine_operating_mode`, 0x3fa0ec `engine_operating_mode_previous_pass`,
  `operating_mode_governor_output_t.mode_code`, 0x40b67c, 0x3fb526, 0x40a154 `governor_fuel_demand_mode`, 0x3fb524
  `governor_fuel_demand_mode_prev`, 0x3fd048 `cruise_fuel_demand_mode_prev`.
- Renamed 0x40b67c `governor_pid_integral_snapshot` → `governor_fuel_demand_working_mode` (it never holds a PID term).
- Split the 0x3fb526 dword `governor_pid_integral_working` into `governor_fuel_demand_working_mode_prev` (0x3fb526,
  written by `sth` @ 0x40474 only) and `fuel_demand_enable_sync_flag_shadow` (0x3fb528, word, `lhz` @ 0x4064c /
  `sth` @ 0x406b8; it had no type).

## Proof

- Fresh baseline build = the committed `.cpp` except the timestamp.
- `reverse_names.py` (label renames reversed) + a stricter check (`check_enum_proof.py` in the session folder): with
  member names / numbers normalized to values, the enum type to `word`, locals to placeholders and the dword pieces to
  the new words, **one** function still differs: `cm848_processProtectionRampControl`, whose reused local (`wVar1`: the
  state, later the fuel value) is now two locals (`FVar1` FUELING_STATE / `wVar2` word). Values and control flow are the
  same.
- Build warnings unchanged; `lookup_tables.py` clean; `test_rename_waves` / `test_lookup_tables` / `test_disasm_tools`
  pass; headers regenerated (CM848 types + globals; CM550 unchanged), both compile with 0 errors.

## Stage 2 - the derate, combustion and final stages (2026-11-19, PR #52)

The governed state flows on through `cm848_processProtectionSelection` (the min with the derate chain and the
tracked minimum), the combustion stage and `cm848_selectFuelDemandSource` (the engine-state overrides). Every carrier
holds the same numbering. The RAM dump (key on, engine stopped) reads governed 11 → derate 62 → snapshot / gross /
reference 62 → final 26. CM848 stores derate codes up to 62; the CM550-era e2m range ends at 41.

- **e2m blocks that line up:**
  - block 1051 FSFNFL / FSFNFLST = 0x40a2ce `fuel_demand_computed` / 0x40a2d0;
  - block 105D FSLMFL / FSLMFLST / FSAPLMFL (fuel system specific derate) = 0x40afac `torque_derate_fuel_quantity` /
    0x40afae / 0x40afb0 `fuel_pressure_fault_fuel_limit_working`.
- **Carriers typed `FUELING_STATE` (all 16-bit; no ordering compare):** `torque_derate_fuel_source_code` and
  `injection_quantity_combustion_reference_source_code`, plus these renamed ones:

  | Address | New name | Old name |
  |---|---|---|
  | 0x40a2d0 | `final_fueling_state` | `governor_mode_code` |
  | 0x40a2de | `final_fueling_state_prev` | `governor_mode_code_prev` |
  | 0x40a2d4 | `requested_fueling_state` | `governor_fuel_mode_arbitrated` |
  | 0x3fa874 | `fuel_demand_arbitrated_state` | `governor_fuel_mode_prev` |
  | 0x40a2e2 | `fuel_demand_arbitrated_state_snapshot` | `governor_fuel_mode_snapshot` |
  | 0x40afb4 | `fuel_demand_minimum_tracked_state` | `governor_fuel_mode_input` |
  | 0x40a2da | `governor_fuel_limit_cap_state` | `governor_fuel_mode_command_cached` |
  | 0x3fa6d0 | `injection_quantity_combustion_gross_source_code` | `governor_fuel_mode_working` |

  The freeze-frame byte `fault_entry_t.governor_mode_code` is now `final_fueling_state`.
- **Members proved from their setter:**
  - 13 calibrated fixed fuel limit;
  - 19 maximum fuel curve (the derate chain's starting value);
  - 20 TSC1 torque limit;
  - 22 engine starting, 23 fuel override, 26 engine stopped;
  - 28 fuel pressure fault limit, 29 fault derate (not the e2m ATDERAT);
  - 41 immobilizer fuel disable, 45 torque management;
  - 52 / 53 / 54 / 55 / 58 the combustion density maximum, chi maximum, temperature headroom, gross fuel override and
    oxygen limit;
  - 61 rail pressure shortfall, 62 the fuel pressure governor fault blend.
- **`FUELING_STATE_UNIDENTIFIED_<n>`:** codes stored (15 16 24 25 27 32 34 40 42 46 59) or only compared (37 38 47 49
  50) whose algorithm is not proved yet. Ghidra 12.1 prints a value with no exact member as an OR of members: 15
  rendered as `FUELING_STATE_HIGH_SPEED_GOVERNOR | FUELING_STATE_TSC1_SPEED_CONTROL | FUELING_STATE_TSC1_TORQUE_CONTROL`,
  27 as `26 | 1`, 59 as `58 | 1`. So every value a carrier holds needs a member.

## Stage 3 - the arbitration functions and words (2026-11-19, PR #52)

The earlier sections use the old names. Each rename's plate comment or comment gives the evidence and the old name.

| Address | New function | Was |
|---|---|---|
| 0x4043c | `cm848_arbitrateGovernedFueling` | `cm848_processProtectionRampControl` |
| 0x1e5a4 | `cm848_arbitrateRequestedFueling` | `cm848_processProtectionSelection` |
| 0x1e22c | `cm848_selectFinalFueling` | `cm848_selectFuelDemandSource` |
| 0x1f03c | `cm848_calculateMaximumFuelCurve` | `cm848_processActiveFaultList` |
| 0x3889c | `cm848_applyFuelPressureGovernorFaultBlend` | `cm848_processSafetyConditionProtection` |
| 0x40f80 | `cm848_calculateVehicleSpeedLimitFueling` | `cm848_processProtectionRampTimer` |
| 0x40e4c | `cm848_calculateCruiseControlFueling` | `cm848_processGovernorFuelRate` |
| 0x411b0 | `cm848_selectCruiseOrUserFueling` | `cm848_calculateProtectionLevelLimit` |
| 0x40dd4 | `cm848_snapshotHighSpeedGovernorFueling` | `cm848_copyProtectionRampValue` |
| 0x40de8 | `cm848_limitLowSpeedGovernorFueling` | `cm848_calculateGovernorFuelDemandUpperLimit` |
| 0x27ff8 | `cm848_runLowSpeedGovernor` | `cm848_processSpeedGovernorControl` |
| 0x427cc | `cm848_applyTsc1TorqueLimit` | `cm848_applySpeedControlProtectionLimit` |
| 0x509510 | `cm848_applyFaultDerateFuelLimit` | `cm848_enforceFuelLimitProtection` |
| 0x40844 | `cm848_calculateRiseLimitedVehicleSpeed` | `cm848_calculateFuelRateFromRpm` |
| 0x2bbe8 | `cm848_selectPowerTakeOffOrUserFueling` | `cm848_updateGovernorFromProtection` |
| 0x1f318 | `cm848_initializeFuelLimitChains` | `cm848_initProtectionStateWithFuelDemand` |

| Address | New word | Was |
|---|---|---|
| 0x40b674 | `vehicle_speed_limit_fueling` | `cruise_fuel_demand_setpoint` |
| 0x40b676 | `cruise_control_fueling` | `governor_pid_fuel_output` |
| 0x40b672 | `high_speed_governor_fueling_snapshot` | `governor_fuel_demand_low_threshold` |
| 0x40b67a | `low_speed_governor_fueling` | `governor_fuel_demand_upper` |
| 0x40ae94 | `low_speed_governor_fueling_working` | `governor_fuel_demand_upper_working` |
| 0x40a156 | `low_speed_governor_active_flag` (e2m LSLOFG) | `governor_request_active_flag` |
| 0x40b6e0 | `vehicle_speed_rise_limited` | `cruise_speed_setpoint_adjusted` |
| 0x3fb52c | `vehicle_speed_rise_limited_prev` | `cruise_speed_setpoint_prev` |
| 0x40af56 | `power_take_off_throttle_override_engine_speed_limit` (e2m PTTHDQRP) | `governor_fuel_idle_limit` |
| 0x40af58 | `power_take_off_throttle_override_flag` (e2m PTTHOV) | `governor_idle_transition_flag` |

Kept on purpose:
- `cruise_speed_limit_working`: both the cruise control and the vehicle speed limiter use it.
- The `fuel_flow_rpm_*` drivetrain ratio words.
- The limiter functions of the unidentified codes.

## Follow-ups (open)

- [ ] **Name the `FUELING_STATE_UNIDENTIFIED_<n>` codes:**
  - each limiter input: 15 `fuel_correction_upper_limit`, 16 `fuel_demand_load_based`, 32 `fuel_demand_arbitrated_a`,
    42 `protection_fuel_limit_working`, 46 `cold_start_fuel_demand_ramp_output`, 59 `fuel_demand_rate_output`;
  - 34 / 40 (the `governor_fuel_limit_cap` path);
  - 24 / 25 / 27: the `COLD_START_PHASE` members 4 / 5 / 8 disagree with their own comments, so name the phases first.
- [ ] **CM550:** type FSGVFLST (0x0080a8f2) and the 13-41 word (0x0080deca) with a shared enum. CM550's own
  `ENGINE_OPERATING_MODE` (ENGINE_IDLE ...) and `FUEL_SOURCE_ID` (0x09 governor low / 0x0A high / 0x0B diagnostic)
  contradict the CM848 code: guesses to replace, not to reuse.
- [x] **CM848 `FUEL_TIMING_MODE`:** applied to nothing, like `FUEL_DEMAND_SOURCE` / `FUEL_DEMAND_LIMIT` /
  `SHUTDOWN_SELECTOR_SOURCE` / `FUEL_CONTROL_MODE_SELECT` / `GOVERNOR_MODE`. No global, field, local or prototype uses
  them: they are unused CM550-era guesses. Their 0x18-0x1b values are final states 24-27 here. Removing them is a
  cleanup for later.
- [x] **Misnamed functions found in stage 2** (renamed in stage 3):
  - `cm848_processActiveFaultList` (0x1f03c) is the maximum fuel curve: two engine speed x 400 tables blended by
    `thermal_fuel_limit_factor`.
  - `cm848_processSafetyConditionProtection` (0x3889c) and its `safety_*` words are the code 62 fault blend for the
    fuel pressure governor faults.
- [x] **Misnamed words around the arbitration** (renamed in stage 3 except `cruise_speed_limit_working`; still open: the rest of the power take-off cluster below and the 0x3fb52a row):
  - `cruise_fuel_demand_setpoint` (0x40b674) = the vehicle speed limit fuel; `cruise_speed_setpoint_adjusted` (0x40b6e0)
    = the vehicle speed (rate limited); `cruise_speed_limit_working` = the vehicle speed limit.
  - `governor_fuel_demand_low_threshold` (0x40b672) = the copy of `high_speed_governor_fueling`;
    `governor_fuel_demand_upper` (0x40b67a) = the low speed governor fuel the max select compares;
    `governor_pid_fuel_output` (0x40b676) = the cruise PID fuel.
  - `governor_fuel_idle_limit` / `governor_idle_transition_flag` (0x40af56 / 0x40af58) = e2m PTTHDQRP / PTTHOV.
  - The "protection" cluster 0x2a4b0-0x2bbe8 (`cm848_calculateProtectionLoadCompensation`,
    `initProtectionParamCalculation`, `cm848_processProtectionControlStateMachine`, `cm848_initProtectionEvalState`,
    `cm848_updateGovernorFromProtection`) is likely the power take-off governor; `cm848_processProtectionRampControl`
    is the governed fueling arbitration.
  - The 0x3fb52a row is named `fuel_demand_enable_sync_flag_shadow+2` (a sub-label name; it renders `..._shadow_2`) and
    holds the previous `cruise_control_engaged_flag`.

## Investigation Log

- **2026-11-19:** investigate-firmware-symbol sweep (asm census, writers, value chain, RAM dump, CM550, e2m blocks),
  then the change above with the label-only proof. Scratch scripts, proof outputs and logs:
  `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-19_fueling_state/`.

## Key Files

- `firmware/CM848_S90140.06_analysis/output/enums.csv` (`FUELING_STATE`)
- `firmware/CM848_S90140.06_analysis/output/global_variables.csv`, `structure_definitions.csv`
- `e2m-analysis/exports/common_parameters.json` (the FS*ST / PT* records)
- `firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp` (`runHighSpeedGovernorPid` @ 0x1ce7c)
