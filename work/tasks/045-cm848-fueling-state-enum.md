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

## Stage 4 - the e2m labels, the engine state, the power take-off governor, the limiters (2026-11-19, PR #52)

Two read-only agents did the reading: the engine state, and the 0x2a2d0-0x2bed4 cluster. Their key claims were checked
here before anything was applied.

- **The labels.** `e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m` is a Chrysler calibration; the truck runs V11.46.06. It
  gives Cummins' value labels with HEX keys:
  - `Fueling_Control_State` / `User_Fueling_State` 00-3D;
  - `Engine_State` 1-8;
  - the `[PTST]` description.

  **Correction:** `29=ATDERAT` is 0x29 = 41, the anti-theft derate, which is `FUELING_STATE_IMMOBILIZER_FUEL_DISABLE`.
  0x1D = 29 is EPFDERAT, the fault derate. The stage 2 notes "CM848 numbers its limiters differently above 12 / e2m 29
  ATDERAT" were a decimal misread.
- **`FUELING_STATE`.**
  - Every member comment quotes its label.
  - Renamed to the labels: 13 `TORQUE_DERATE_OVERRIDE` (TRQDROVR), 19 `MAXIMUM_THROTTLE` (MAXTHROT), 22 `CRANKING`
    (CRANK), 28 `FUEL_SYSTEM_DERATE` (FSSDERAT).
  - Named: 15 `ALTITUDE_DERATE`, 16 `AIR_FUEL_CONTROL_DERATE`, 24 `ENGINE_BRAKE`, 25 `OVERSPEED`, 27 `SHUTDOWN`, 34
    `POWER_TAKE_OFF_DERATE`, 40 `NO_DERATE`, 42 `FUEL_LIMIT_BY_RPM_AND_DEMAND` (label PTTHLM; the code shows only a
    variable-speed-governor limit by engine speed and accelerator demand), 46 `COOLANT_OVERHEAT_DERATE` (CTDERAT), 47
    `FREE_ACCELERATION`, 59 `NET_TORQUE`.
  - Still `UNIDENTIFIED`, with their labels in the comments: 32 MSOVRIDE, 37 T2SPD, 38 T2TORQ, 49 OFCSTATE, 50 AFRSTATE.
  - Code 15 is the altitude derate: the engine speed x barometric pressure grids for cool / hot ambient air. The
    air handling faults only switch it to a fault grid. An earlier note read the fault path as the whole function.
- **`ENGINE_STATE`** (was `COLD_START_PHASE`).
  - `cold_start_phase` → `engine_state` (Cummins FSEGST). Its transitions were checked in `cm848_updateEngineState`
    (was `mpc555_processColdStartMainLoop`).
  - Block 1068 lines up 7/7 with sizes: `power_down_start_flag` (was `hardware_operation_complete_flag`; it ends the
    main loop), `ecm_power_down_timer` (was `governor_speed_engage_count`), `engine_state_crank_time` / `_run_time`,
    `engine_is_active_flag` / `engine_is_starting_flag`.
  - The five `engine_state_prev_*` words share the type.
- **The power take-off governor, now code-proven.**
  - J1939 CCVS1 sends `power_take_off_governor_j1939_state` as SPN 976, the PTO governor state. The enum
    `POWER_TAKE_OFF_GOVERNOR_J1939_STATE` uses the J1939-71 values.
  - OBD-II PID 0x1E sends `power_take_off_governor_active_flag` | switch 3.
  - `power_take_off_governor_state` uses `POWER_TAKE_OFF_GOVERNOR_STATE` (e2m PTST 0 remote count / 1 remote run / 2
    wait / 3 normal).
  - 10 functions renamed (`cm848_runPowerTakeOffGovernorStateMachine`, `cm848_runPowerTakeOffGovernorPid`,
    `cm848_applyPowerTakeOffTorqueLimit` ...).
  - The dword at 0x3fd89a is now two EEPROM words: `power_take_off_remote_switch_mode_cal` and
    `power_take_off_throttle_override_maximum_engine_speed_cal` (28000 = 3500 rpm).
  - `j1939_governor_feature_byte` (EEPROM 0x480) is 0 on this truck, so the governor never engages. The RAM dump reads
    WAIT.
- **The limiter families renamed:**
  - the altitude derate: `cm848_calculateAltitudeDerateFuelLimit` / `cm848_applyAltitudeDerateFuelLimit`;
  - the air fuel control limit: `cm848_calculateAirFuelControlFuelLimit`, `air_fuel_control_fuel_limit`;
  - the net torque limit: `cm848_calculateNetTorqueFuelLimit`;
  - the fuel limit by rpm and demand: `cm848_calculateFuelLimitByRpmAndDemand`, with its axes and blend words;
  - the coolant overheat derate: `cm848_runCoolantOverheatFuelDerate` and 6 more functions, 14 words and the two
    tables. These were the "unidentified `fuel_coldStart_*` helpers".

## Stage 5 - the power take-off words, the crank routine, two backwards flags (2026-11-19, PR #52)

- **The power take-off governor's words.** They are named from five e2m blocks that line up by offset, with matching
  units and RAM-dump values:
  - 10AB, the terms: `power_take_off_governor_filtered_speed_error`, `_proportional_term`, `_derivative_term`,
    `_integral_fueling`, `_droop_adjusted_fueling`, `_proportional_derivative_fueling`,
    `_smoothed_reference_engine_speed`, `_droop_compensated_speed_error`, the QD / QI / QP `_gain_adjustment` words
    (0x80 = 1.0; the old `_d_gain_factor_b` is QI) and `_no_load_fuel`.
  - 109E: `power_take_off_requested_engine_speed` (PTO_Requested_Speed).
  - 11B4, EEPROM 0x404-0x418: the engagement slew rate, max road speed 2 mph, minimum reference 1100 rpm, remote count
    limit 5, remote speeds 2-5 = 1400 / 1600 / 1800 / 2000 rpm, set / resume 1100 rpm, ramp rate and switch enable
    option (`power_take_off_*_cal`).
  - 109D: the engage window, 300-1200 rpm, and the remote switch timeout.
  - 10AA: the gains and clamps.
    - The +-1000 rpm speed-error clamps had their names swapped (the "lower bound" held +8000).
    - The "byte" filter constant is the word EMA coefficient 0.8.
    - The fueling clamp minimum and the integral constant were checked in the PID code.

  The PID reaches each word by its own address, not base + offset, so they stay flat words, not a struct.
- **The crank routine.** A read-only agent read it, and its e2m blocks, anchors and dump values were checked here.
  - e2m 105E: the 0x40a798-0x40a7be words, `crank_*`. They include `crank_exit_speed` (CRANKING ends at it),
    `crank_fuel` (the CRANKING fuel; it was named an rpm) and `crank_reentry_speed`.
  - e2m 105F: the ROM settings 0x406852-0x40687c, which lost a wrong `_cal`.
  - e2m 1032: `engine_stopped_speed` (10 rpm), `ecm_power_down_timer_threshold`, `ecm_power_down_delay`.
  - EEPROM: `crank_exit_speed_switch_cal`, `engine_brake_driveline_brake_type_cal` (1 = retarder, so ENGINE_BRAKE is
    never entered here) and `algorithm_enable_flags_20_cal`.
  - The crank tables (`crank_initial_fuel_*`, `crank_exit_fuel_*`, `crank_initial_speed_*`).
  - The AECD words: engine start / extended idle / extreme ambient (e2m `EMO_*_AECD_Active` / `_Cap_EL`). Stage 5b
    renamed them again (below).
- **Two flags that read backwards.**
  - `engine_starting` is now `engine_shutdown_command_flag` (e2m 10B1 +12 Shutdown, block anchored at +A
    `fault_derate_fuel_limit`). It forces SHUTDOWN and zeroes the injection and the rail pressure setpoint.
  - `engine_shutdown_active_flag` is now `key_off_shutdown_inhibit_flag`: 1 stops a key-off shutdown. Only J1939
    service 24 sets it (`cm848_inhibitKeyOffShutdown`, was `cm848_setColdStartMode2Flag`), and the next key-on edge
    clears it.
  - `cm848_setEngineStarting` is now `cm848_commandEngineShutdown`. The user's review note is kept.
- **Code 32** is `FUELING_STATE_MASTER_SLAVE_OVERRIDE` (e2m MSOVRIDE; [MSODEN] "Enable overriding slave Final_Fueling").
  Codes 37 / 38 / 49 / 50 keep placeholders, with the e2m T2 / OFC / AFR leads in their comments.
- **The stale `CSP_*` state names** in 32 comments now use `ENGINE_STATE_*`.
- **Proof:**
  - All 104 names render, with no `_` variants and no OR renders.
  - With the names reversed, one line still differs: an `(undefined *)` cast in `cm848_initProtectionFilterState`. It
    comes from the byte → word fix of `power_take_off_speed_error_filter_coefficient`; `cm848_signedFirstOrderFilter`
    reads it as `*(short *)`.
  - The build warnings match stage 4's, once `function_definitions.csv` had the two new function names
    (`refresh_references.py` does not touch that column).

## Stage 5b - the AECD words fixed, the old engine state prose (2026-11-19, PR #52)

A review after stage 5 found that 16 applied rows had not been checked: the crank tables and the AECD words.
- **The crank tables, checked.** Their e2m axes match the code:
  - `Crank_Initial_Fuel_Table` (8A47, coolant x ambient pressure) feeds `crank_initial_fuel` (105E +16);
  - `Crank_Exit_Fuel_Table` (8A4A) feeds `crank_coolant_exit_fuel` (+C);
  - `Crank_Initial_Speed_Table` (8A45, rpm over coolant) feeds the rpm word `crank_initial_fuel_break_speed` (+1C);
  - with `system_status_flags` fault bit 16 or 17 set, the code takes the 8A44 defaults (`DAT_0005b1b6` / `b8`,
    Crank_Initial_Default_Fuel / _RPM) instead.
- **The AECD words, renamed again.** Stage 5's `*_emission_control_active_flag` reads backwards: an auxiliary
  emission control device relaxes NOx control while it is active. The family already has wave 9's
  `condensation_protection_active_flag` / `_emission_level_cap`, so the words follow it, with the condition from the
  e2m AECD name:
  - **`engine_start_warmup_protection_*`** (19B2 / 19B3). Active while `algorithm_enable_flags_20_cal` bit 0x1000 and
    `engine_is_starting_flag` (CRANKING / JUMP_START) are set.
  - **`extended_idle_protection_*`** (19B0 / 19B1, "Extended Idle and PTO Protection"). `extended_idle_timer` counts
    +2 per pass (0.1 s units) while bit 0x800, `engine_is_active_flag` and the low speed governor or power take-off
    fueling are all set. The flag goes active at `extended_idle_time_threshold`, 3000 = 300 s.
  - **`extreme_ambient_overheat_protection_*`** (19A1-19A4). A coolant hysteresis
    (`extreme_ambient_coolant_temperature_high_flag`: on at 222 °F, off at 217 °F) with bit 0x200. The cap comes from
    the coolant table (`extreme_ambient_overheat_protection_cap_axis` / `_values`: -50 to 250 °F, all 1.0). The old
    names called this a cold start boost override.
  - **The rest of the family:** four new rows for the calibrations the code reads (the two `_when_active` caps of
    1.0, the 217 / 222 °F thresholds, `i16` for the `lha` pair). The three update functions are now
    `cm848_updateEngineStartWarmupProtection`, `cm848_updateExtendedIdleProtection` and
    `cm848_updateExtremeAmbientOverheatProtection`.
  - **EL is the emission level.** The same family's `C_EMO_Condensation_AECD_Cap` is the "NOx cap value to be used
    when condensation triggers EGR off" (1/1024), and `fuel_demandMin_maxSelect_rateLimit` takes the largest active
    cap.
  - **None of the three is active on this truck.** The enable bits 0x1000 / 0x800 / 0x200 are clear in
    `algorithm_enable_flags_20_cal` (0x0100).
- **ENGINE_BRAKE, checked.** It has one entry (`cm848_updateEngineState`), gated by `engine_retarder_active_flag` and
  `engine_brake_driveline_brake_type_cal == 0`, which is that word's only reader. e2m: "0=Exhaust/Engine Brake, 1=
  Retarder"; the dump has 1.
- **The prose left from the old engine state reading**, each checked against the compare in the code:
  - "at the governor setpoint" = RUNNING, "fuel mode switch" = ENGINE_BRAKE, "cold start phase 3" =
    `engine_is_active_flag`.
  - `fuel_cold_start_phase3_compensation_enable_flag` is now `condensation_count_enable_flag` (feature bit 0x200 and
    `engine_is_active_flag`; the two condensation counts follow their step only while it is 1).
  - `combustion_status_flags` bit 0x02 means "neither starting nor active", so the dump's 0x402 only shows that it
    was taken with the engine stopped (`engine_state` 1). The old note "why EGR is requested off on this truck" was a
    misreading.
- **The three plate shorthand tokens** are now full names.
- **Cross-firmware:** none of the stage 5 old names occur in CM550's CSVs or the cross-firmware maps.

## Stage 6a - the signed filter records typed (2026-11-19, PR #52)

- **The record type already existed.** `cm848_signedFirstOrderFilter` (0x5644c) reads its record exactly as
  `exponentialMovingAverage` reads an `ema_filter_state_t`:
  - [0] points at the 16-bit coefficient (read as `*(short *)`; 0 = no filtering);
  - [1] is the Q16.16 accumulator, written whole;
  - each pass moves the accumulator (65536 - coefficient) / 65536 of the way to the sample and returns the integer
    part, signed.

  Two of its records (`egr_valve_delta_pressure_filter_state` / `egr_valve_derivative_filter_state`) and the sensor
  channels' records were already `ema_filter_state_t`.
- **The count.** There are 39 call sites, not the 15 found earlier: a one-line grep missed every call whose arguments
  wrap onto the next line. 33 global records were not yet typed, and two more records are passed through a pointer.
- **The records.** All 33 are now `ema_filter_state_t` instances, named after what they filter: the call's output,
  or its input when the output is a local. Examples:
  - `power_take_off_speed_error_filter` (was `protection_filter_state_ptr` + `governor_integrator_working`);
  - `governor_speed_error_delta_filter` (was `governor_bank2_cal_ptr`);
  - `fuel_demand_delta_filter` (was `throttle_fuel_pgn_handler_pointer`);
  - the five fuel metering / fuel pressure governor records that were `cam_sync_*`;
  - `pressure_correction_first_filter` / `_second_filter` (two cascaded filters);
  - the three charge flow derate offset filters.

  Names that already fit stay (the cooling fan and engine acceleration records). 0x3fb9e2 is typed but left unnamed,
  because the names around it look suspect.
- **The accumulator rows.** The 23 +4 rows are gone. The narrow ones had rendered `_cam_sync_*_accum = 0` because the
  code stores a dword there. The accumulators now read `<record>.accumulator`, for example the presets
  `power_take_off_speed_error_filter.accumulator = (int)(short)x << 0x10`.
- **The coefficients.** 13 rows are retyped to `word`, since the filter reads 16 bits and 12 of them were typed `byte`.
  The misleading names (`*_filter_state_cal`, `_constants`) and the ROM-copy `_cal` are gone. Eleven unnamed
  coefficients get rows (one type only). The RAM-dump values run from 0 to 0.999.
- **The prototypes.** `cm848_signedFirstOrderFilter` / `cm848_conditionalFirstOrderFilter` now take
  `ema_filter_state_t *`. The return is `sword`, because the filter returns a sign-extended 16-bit value. Two wrong
  attempts first:
  - `int` maps to an unsigned dword in `ApplyFunctionDefinitions` (see `csv-type-reference.md`);
  - with `int32_t`, the locked 32-bit return put a temp and a cast at every call site.
- **Check.** All 46 names render, with no `_` variant. After mapping each field access back to the flat form it
  replaced, 15 functions still differ, all explained:
  - the init functions whose unnamed +4 bytes now read `.accumulator`;
  - the two filter prototypes;
  - type propagation in `cm848_updateAutozeroOffset` / `cm848_calculateFuelMeteringCommand` /
    `cm848_updateEgrValveOverTemperatureFault` (the skeleton of the 2992-token fuel metering function is identical);
  - one division in `cm848_throttleBasedFuelCalculation` that now renders through `ulonglong` (the same value: a
    16-bit sample << 13 stays below 2^32);
  - one declaration order change;
  - the unnamed instance's default label.

## Stage 6b - the ECU's parameter ID table, the emission manager, the power take-off helpers (2026-11-19, PR #52)

- **The ECU resolves e2m records itself.** `cm848_lookupParameterIdAddress` (0x539768) searches a table in flash2 at
  0x53be38-0x53ea6c: 6-byte records [e2m block id u16][address u32].
  - So an e2m record's address is table[column 3] + column 4. EEPROM addresses come back as 0x01000000 + offset, which
    the application reads at 0x3fd482 + offset.
  - The live flash2 dump holds 1441 of the 1886 records; the table runs past the end of the dump.
  - The table reproduces every block base proved earlier by matching offsets: 105E / 105F / 1032 / 10B1 / 1068 /
    10AA / 109D / 109E / 11B4 / 19A1-19B3 / 1180 / 1254.
  - `firmware/scripts/e2m_block_addresses.py` resolves blocks or one address, with the current CSV names
    (`test_e2m_block_addresses.py`). The emission manager agent found the table.
- **The emission manager (EMO / EMM, about 60 rows and 15 functions).** Every e2m identity was re-resolved with the
  tool.
  - **`emission_level_cap_command`** (was `fuel_demand_min_threshold`, e2m 198E EMM_Cap_EL_Cmd "Emission level cap after
    AECDs") is the rate-limited maximum of the AECD caps and `emission_level_cap_reference`. It is a lower bound on the
    combustion chi (`cm848_lookupProtectiveChi`), not a fuel demand floor.
  - Its calculation is `cm848_calculateEmissionLevelCapCommand`, with its rate limits, override value and EEPROM user
    override.
  - The reference is a cap table over altitude x ambient temperature times a speed x torque ratio table
    (`cm848_calculateEmissionLevelCapReference`). The not-to-exceed zone flag and its 150-sample averages are named.
  - **`emission_manager_engine_protection_state`** (was `combustion_status_flags`, e2m 19B5 +2 EMM_Protection_State)
    and `emission_manager_auxiliary_emission_control_state` (19B5 +0 EMM_AECD_State, the eight AECD bits).
  - **The air handling system protection AECD** (e2m 1990-1997: levels 1-3, the compressor outlet temperature /
    turbocharger speed / exhaust temperature limits and their tables, high load). Enabled by
    `algorithm_enable_flags_20_cal` bit 0x100, it is the only AECD active on this truck (level 2 / 3 caps 2.0).
  - **White smoke and misfire protection** (19A8 / 19A9): the old `injection_timing_temperature_component_check_flags`.
  - **General engine protection** (1A41 / 1A42): the old `fuel_demand_sensor_validation_*`.
- **The power take-off helpers (the second agent).**
  - **Six functions:** the governor initialization, the reference filter, the smoothed reference preset, the throttle
    override initialization, the PGN 65264 power take-off information message and its buffer.
  - **The working words:** the gain adjustment multiplier (Q14, calculated or from the e2m 13B2 / 13B3 tables), the
    PID integrator and the previous-pass copies, the switch state bits, the engagement ramp, the target / saved cab
    target, and the remote switch counts.
  - **`power_take_off_remote_speed_by_press_count`**, a `word[6]` read indexed (it was six words).
  - **The EEPROM block 0008 settings:** remote speed 1, maximum reference 1500 rpm, droop slope, gain adjustment
    offset / slope, resume / set speeds.
  - **The PGN 65264 / 65270 / 65249 priority words**, which were misnamed `_source_address_bits`.
- **Comments the power take-off agent found wrong, now fixed:**
  - the reference step limit is a minimum step;
  - the speed error starts from the smoothed reference, not the requested speed;
  - the ramp writes the requested speed;
  - `power_take_off_governor_droop_compensated_speed_error` has no writer.
- **Also renamed:** `emission_manager_engine_protection_fixed_chi_hundredths` (was
  `combustion_status_flag_chi_hundredths`) and `cm848_debounceCruiseSwitchRequest`.

## Stage 7 - the whole-CSV e2m audit and rename wave 12 (2026-11-19, PR #52)

- **The audit.** `firmware/scripts/e2m_name_audit.py` resolves every scalar e2m record through the parameter ID table
  and lists the row at its address (tests: `test_e2m_name_audit.py`). It also gives the dump value against the
  record's range and a word-overlap score against the current name.
  - **4691 records resolve.** After wave 12: 3388 named, 776 without a row, 477 inside a wider row (struct / array /
    dword) and 50 on unnamed rows.
  - **A correction.** The first run gave struct instances zero width and counted 244 "inside". Struct sizes from
    `structure_definitions.csv` are counted now, and none of the 383 new rows starts inside or covers another row.
  - **The 1610 low-overlap named rows** are mostly struct instances (compared by instance, not by field) and synonyms.
    Real misnames are among them. They are the next wave, not this one.
- **Wave 12: the unnamed records the code uses.** 398 records had no name, a code reference and an in-range dump
  value.
  - Six read-only Sonnet agents each took one bin of whole blocks, with precomputed context: code lines, width
    census, the block's named rows. They named each record from the e2m, checked the code use and the width, and
    rejected drift.
  - **Verdicts:** 384 confirmed, 6 uncertain, 8 rejected. The gate (apply_renames.py rules plus cross-bin duplicates,
    collisions, present rows and type against size) passed 383; one address is resolved by two blocks.
  - **Layout drift between the labelled 11.45 e2m and the truck's 11.46.06:**
    - the 10E3 tail is block 1228;
    - 8A2B +24 is 8A37 +0;
    - 8A14 drifts from +2C, 1930 from +12, and 1902 at +2A-+2E;
    - block 1253's fault slot order differs.
    In every case the code confirmed the table's block, not the e2m offset.
  - **After the build:**
    - all 393 names render, with no `_` variants; build warnings are unchanged;
    - 32 functions differ, all from typing the new rows: casts, local types and renumbered temporaries, local
      declaration order, `PTR_<target>_<address>` labels of unnamed pointers, one table base now indexed as dwords;
    - one bad render was fixed: a 4-byte software version read bytewise, now `byte[4]`.
- **The fueling chain's own e2m names (blocks 1045 / 1051, checked against their writers):**
  - `adjusted_user_fueling` / `adjusted_user_fueling_state` (were `governor_fuel_demand_value` /
    `governor_fuel_demand_mode`, [FSGVFL] / [FSGVFLST]: the symbol this PR started from);
  - `final_fueling` (was `fuel_demand_computed`, [FSFNFL], plus the freeze-frame field) and `requested_fueling`;
  - `master_slave_control_flag` and `torque_control_indication_flag`;
  - `torque_derate_torque_limit` / `_state`. Stage 4 named these after the power take-off, which is only one of their
    sources;
  - the two "before combustion reference" values.

## Stage 8 - rename wave 13, the misname review (2026-11-19, PR #52)

- **The worklist:** the named rows whose name shares no word with their table-resolved e2m record, with 3+ code
  references and an in-range dump value: 381 rows in six bins of whole blocks.
- **The agents' task:** keep (an accurate synonym, which also gains an `| e2m:` cross-reference), rename (wrong or
  misleading, a banned abbreviation, or a wrong / missing `_cal`), drift, or uncertain.
- **Verdicts:** 221 renames, 143 keeps, 17 drift.
- **Held back (3):**
  - `diagnostic_session_state` -> `ram_refresh_enable` and `j1939_standby_flag` -> `development_mode`. Both rows are
    enum-typed, and the enum members still follow the old reading.
  - 0x40a204. It is a dword over the integral and proportional terms; split it into two words first.
- **The gate:** the repo's `apply_renames.py` passed the 218 renames with no PROBLEM line. None of the old names occurs
  in CM550's CSVs or the cross-firmware maps.
- **The new drift:**
  - 8D14 from +2;
  - the 8C58 tail overlaps 8C4E;
  - 1B2D from +4;
  - 1966 from +94;
  - 1649 from +10.
  - The "ratio" records at the end of 8C34 / 8C56 / 8C5B / 1632 have no storage of their own in 11.46.
- **The families renamed:**
  - the data collector (`data_collector_*`, was `diag_dm1_*`);
  - the PGN 65251 engine configuration / torque curve words (e2m 1102);
  - alpha (104A), the all-speed governor (107C);
  - the converter clutch and governor pressure monitors (8C33 / 8C34 / 8C58);
  - cylinder balance (81AE / 81AF / 81B0), the fuel pressure governor gains (8014 / 8015 / 80EF);
  - the fuel metering coil (8019), the crank / backup cam signal words (8194 / 819B);
  - the EGR orifice and intake manifold temperature lead terms, the compressor map, the ambient / compressor inlet
    conditions (1921);
  - friction fueling (109C), the J1939 control session history, the rear axle ratio, the wastegate duty terms;
  - the `_cal` fixes.
- **Single renames worth noting:**
  - `engine_displacement_cubic_inches` (359.2) and `rear_axle_ratio` (3.54);
  - `total_fueling`;
  - `not_safe_to_program_flag` (was `prior_boot_faulted`);
  - `monitor_readiness_code_cal`.
- **Checks and fixes by the main session after the apply:**
  - A random sample of 9 renames was checked against the code.
  - 0x40b798 became `backup_pulse_period_countdown`. Bin 6 had named it `crank_tooth_period_countdown`. The code
    reloads it from bin 5's `backup_pulse_period_timeout` (e2m 8194 +2E).
  - An old comment stays as an `| earlier note:`, except for 11 that an agent showed to be wrong. 0x3fed94 had two
    proved facts in its old comment: the dword width at 0x52d634, and that it is distinct from 0x40a813. They were put
    back.
  - On 54 rows the rename note was moved to the repo order: `<comment> (was <old>) | earlier note: <old comment>`.
  - The 80B9 debounce counters and limits (8 rows) took their bits bytes' new meanings. The code pairs each with its
    old letter (a = open circuit, b = short to ground, c = short to battery, d = fast decay). This makes 226 renames.
  - The comment sweep found stale tokens: `safety_bits_1` / `_2` (now `fault_detected_bits_48_to_63` / `_64_to_79`),
    `governor_status_overspeed_flag_snapshot`, `cm848_protection_condition_eval_set1`, `throttle_fuel_demand_adjusted`
    and a shorthand. They were fixed.
- **Proof:** all 226 names render, with no `_` variant. The label-only proof is EQUIVALENT. The warnings and type stats
  are identical to stage 4.
- **The audit after wave 13:** 1489 named rows have a token overlap under 0.34 (1610 after stage 7). The keeps stay in
  that count; they now carry the record as a cross-reference.
- **The quoted dump values:** the renamed rows' comments quote 92 dump values (`check_quoted_dump_values_W13.py`).
  All 92 are right. 13 needed a manual read:
  - a raw value followed by its scaled form ("25600 in the dump = 3200 rpm");
  - a neighbour's value;
  - the 80EF dword gains read at their old word width;
  - a number with thousands separators.
  A read 2 bytes off fails 79 of the 92.

## Stage 8b - the fuel pressure governor / fuel metering gain records as structs (2026-11-19, PR #52)

- **The consumers prove the layout.**
  - `cm848_applyPiecewiseLinearGain` and `cm848_integrateWithZoneGain` read a 16-byte record: three dword gains at +0 /
    +4 / +8 (small signal / positive large / negative large), then the signed window widths at +12 / +14.
  - `cm848_calculateFilteredDerivative` reads an 18-byte one: a word filter coefficient, then the same five fields.
  - The proportional step applies a large-signal gain to the part of the input past the window. The integral and
    derivative steps use the zone's gain for the whole input.
- **Seven e2m blocks of exactly those sizes resolve to the records** through the parameter ID table. The new types are
  `piecewise_linear_gain_t` and `derivative_gain_t`.

  | Record | e2m | Type | Dump |
  |---|---|---|---|
  | `fuel_pressure_governor_proportional_gains` 0x4094a2 | 8014 | piecewise | 0.5 / 0.1 / 0.6 %/MPa, +-10 MPa |
  | `fuel_pressure_governor_integral_gains` 0x4094b2 | 8015 | piecewise | 1.0 / 0.6 / 1.0 %/MPa/s |
  | `fuel_pressure_governor_derivative_gains` 0x4094c2 | 80EF | derivative | coefficient 0.667, 0.005 / 0.02 / 0.02 |
  | `fuel_metering_current_compensation_proportional_gains` 0x4094d4 | 8016 | piecewise | all gains 0 (off) |
  | `fuel_metering_current_compensation_integral_gains` 0x4094e4 | 8017 | piecewise | 0.001 / 0.0001 / 0.0001, +-4000 mA |
  | `fuel_metering_uncompensated_duty_cycle_proportional_gains` 0x4094f4 | 8018 | piecewise | 0.029 / 0.016 / 0.0254 %/mA |
  | `fuel_metering_current_compensation_derivative_gains` 0x409504 | 80F2 | derivative | all 0 (off) |

  Every field reads in range, with the positive windows >= 0 and the negative ones <= 0 (`read_gain_blocks.py`).
- **Before:** 23 flat rows, several of them wrong:
  - the 80EF dword gains were word rows over their high halves, plus `_lo_cal` rows over the low halves;
  - 8016-8018 / 80F2 were byte rows named `cam_sync_*_prot_*_cal`;
  - the window pairs were dwords with `+2` label rows.
  They became 7 instances (16 interior rows deleted).
- **Prototypes:** the three consumers have full prototypes (`sword` return, `int32_t` input, `q16_fixed_point_t *` for
  the integrator / filter state, so the call sites stay cast-free).
- **The stack copies:** `cm848_calculateFuelMeteringCommand` copies the P / I / D records to the stack before the calls.
  Each gain and coefficient is scaled by its own lookup table while e2m 8000 +0 HPCR_Governor_Mode
  (`cam_timing_alt_mode_enable_cal`) is 0. The copies are typed in `local_variables.csv` (`working_*_gains`).
- **Proof:** exactly the four predicted functions changed (the three consumers and `cm848_calculateFuelMeteringCommand`).
  One more function changed only the order of its local declarations. The warnings and type stats are identical to
  stage 4. No retired name is left, and no instance renders with a `_` prefix.
- **Known artifacts:**
  - The derivative gains are not 4-aligned. The code copies them as halfwords, which render as `._0_2_` / `._2_2_`
    pieces.
  - The copy of the derivative record's negative window is one 4-byte store at +16 that runs past the 18-byte record.
    Ghidra prints a raw stack or register name for it (explained in the plate). The unscaled branch loads that word
    at 0x4094d2 across the D record's end and the 8016 record (`ram0x004094d2 & 0xffff0000`).
  - In the integral and derivative steps the zone gain is a computed-offset load.
  - `q16_fixed_point_t.integer_part` is an unsigned `word`, so the integral clamp shows `0xf001` for -4095.
- **Also:** the 80B9 short to ground / short to battery caveat (e2m byte order only) on its six rows.

## Stage 8c - the review fixes after stages 8 / 8b (2026-11-19, PR #52)

- **Widths:** the label-only proof cannot see a right name on a wrong-width row. Seven wave-13 rows are wider or
  narrower than their record (`width_mismatches_W13.py`). Four of them are right: an array, two struct instances, and
  0x3feeb8, which is also 191A WIF_Miles (4 bytes). Three were fixed:
  - 0x408f56 `backup_consecutive_error_threshold` word -> byte. Its three `lbz` reads of +1 rendered as
    `(byte)backup_consecutive_error_threshold`. They are 8194 +1 Bank_With_Added_Tooth, now the byte
    `crank_signal_window_with_added_tooth` (was the typeless `crank_sync_reference_flag_cal`).
  - 0x40a87d `master_slave_override_enable_flag` dword -> word: lhz only. It rendered `._0_2_` and covered 11D4 +4.
  - 0x40a2b4 `ecm_power_down_delay_request_flag` dword -> word: lhz / sth only. It rendered `._0_2_` and covered
    117D +4E.
- **80B9:** `cm848_evaluateInjectorDiagnosticFault` takes each injector's fault numbers from the ROM row table at
  0x57d76 (10 bytes per row, the class picks the offset 2 / 4 / 6 / 8; `injector_fault_codes.py`).
  - The open circuit codes put the bits in firing order: bits 0-5 = cylinders 1 / 5 / 3 / 6 / 2 / 4.
  - The two short classes set different internal faults (268 / 269 for the first injector), but both map to one OBD
    slot: P2146 for cylinders 1-3, P2149 for 4-6. So ground vs battery still rests on the e2m byte order alone. The
    comments said "the code treats the bytes alike", which is not right; they are reworded.
- **Spot check against the code:** 10 random direction-word renames (enable / limit / maximum / minimum / negative ...)
  were checked against their deciding compare or use. All 10 are right; the cylinder balance trim and dynamic
  compensation limits really were reversed before wave 13.
- **The facts stage 8b dropped** were put back: the scaling curves' e2m blocks, the window direction, and "never
  written, so no `_cal`".
- **The gain scheduling curves:** `cm848_calculateFuelMeteringCommand` multiplies each gain and filter coefficient by
  its own engine speed curve while `fuel_pressure_governor_gain_mode` (e2m 8000 +0 HPCR_Governor_Mode, was
  `cam_timing_alt_mode_enable_cal`) is 0. The code use maps each curve to its field (`gain_scaling_tables.py`), and
  the table resolves it to its e2m block.
  - The 22 tables were `cam_sync_cyl*_timing_*` / `cam_sync_prot_gain_*` / `cam_sync_scale_*` with a wrong `_cal`.
  - They are now `fuel_pressure_governor_<term>_<signal>_gain_scaling_axis` / `_values`, plus the derivative filter
    coefficient and the pressure sensor filter coefficient curves (e2m 8005-8010, 80E7-80EE, 80F0 / 80F1).
  - Each table is word[11] (a header word, then 10 points), on 400-4000 rpm.
- **Gate:** the repo's `apply_renames.py` passed all 24 renames against the pre-8c CSVs.

## Stage 9 - rename wave 14, the function misnames and the sibling rows (2026-11-19, PR #52)

- **Worklists:**
  - **83 functions:** the renames the wave-12 / wave-13 reports proposed (`extract_function_leads.py`), plus 9 by hand.
  - **253 globals:** the low-overlap and wrong-`_cal` rows of the e2m blocks wave 13 renamed into, and every row a
    report named. The report ranges and family stems were added (`expand_worklist.py`). 84 weaker rows and 125 rows
    with 0.2-0.34 overlap were deferred.
- **Precomputed before dispatch** (after an advisor review):
  - the CM550 shared-name check and the owner's signed review notes;
  - each row's width against the records it covers;
  - full plates, and a `code_quote` that the apply checks against the function body or the .cpp.
- **Seven agents:** three function bins by family and four global bins by block; 4.78M tokens, 31-41 min each.
  - Verdicts: 83 function renames; 238 global renames, 13 keeps, 2 drift; 2 enum rows.
- **Applied** (`apply_W14.py`, through the repo gate): 75 function renames (the plate keeps the old one as an earlier
  note), 231 global renames, 12 e2m cross-references on keeps. By hand:
  - **The rpm deceleration limit (e2m 107C +5A / +5C / +5E, 107D +2E):** the dword `fuel_demand_integrator_b` was
    the I term and the P term. They are now the `i16` rows `rpm_deceleration_limit_integral_term` /
    `_proportional_term`, plus `rpm_deceleration_limit_fuel` / `_fuel_maximum`.
  - **Byte splits of 8194 word rows:** `crank_sync_tooth` / `crank_teeth_per_cam_measurement`,
    `backup_period_capture_count` / `crank_periods_per_speed_interrupt`, the two resync cam tooth thresholds, and the
    tooth shift upper (byte) / lower (word) thresholds.
  - **Widths and arrays:** 0x40912a is a word. `data_collector_address_table_cal` is `dword[32]`, and its length
    word has a row.
  - **Enums:**
    - `ram_refresh_enable` is RAM_REFRESH_STATE (was `diagnostic_session_state` / DIAG_SESSION_STATE; LOCKED_OUT
      was never stored and is dropped).
    - `development_mode` is DEVELOPMENT_MODE_STATE (was `j1939_standby_flag` / J1939_STANDBY_STATE).
    - `run_location` is the new RUN_LOCATION {0xee normal, 0xea development} (was `cal_write_mode`, e2m 0010
      RUN_LOC). The owner's 2026-05-25 review note on 0x21694 asked for these compares as enums.
- **Families renamed:**
  - alpha (9 functions + words);
  - the EGR mass flow / charge flow / intake manifold temperature / EGR orifice temperature models;
  - the J1939 percent peak torque / friction / PGN 65251 torque curve functions;
  - J1939 control sessions, the data collector, engine protection shutdown, the rear axle and drivetrain ratio;
  - cylinder balance (81AE / 81B0), the equivalent throttle governor (81A9);
  - the TPU-A channel 0 crank / channel 1 cam signal settings (8194);
  - the HPCR settings (8000), the air handling source words, charge pressure in range;
  - the 1102 torque curve calculated / reference fuelings;
  - 88 wrong `_cal`s dropped.
- **Held for the owner:**
  - **Three functions with the owner's signed 2026-05-25 review notes.** The code shows the "activate" services
    exit development mode, so the proposals are:
    - 0x21624 `cm848_activateDiagnosticSession` -> `cm848_exitDevelopmentMode`;
    - 0x21668 `cm848_resetDiagnosticSession` -> `cm848_enterDevelopmentMode`;
    - 0x21694 `cm848_forceActivateDiagnosticSession` -> `cm848_forceExitDevelopmentMode`.
  - **Five functions whose names CM550 shares:** 0xe164 / 0xe3a4 / 0xe518 (alpha), 0x1b3a0 (PGN 65251 payload),
    0x2588c (EEC1). They need a cross-firmware rename. Per the agents, 0xe518's cross-firmware match row is false.
  - **Two struct items:**
    - `boost_pressure_state_t` (0x40a406) is the charge flow estimate terms; the agents give the field -> record
      mapping;
    - `engine_sync_state_t` (0x40b87f) is 7 bytes, not 6: 8019 +5 is a word.
- **Proof:**
  - The 324 renames and the enum maps reverse cleanly except in 10 functions. Each of those is explained by the
    retypes: pieces gone, `(short)` casts gone on the `i16` rows, one `(byte *)` / `(word *)` cast pair gone after
    the 0x40912a widening, and array indexing in the three collector functions (`real_code_diffs.py`).
  - The warnings are stage 4's, with 3 prototype warnings now naming renamed functions.
  - Headers compile, the tests pass, and the comment sweep is clean.
  - The width check is clean once the audit knows enum sizes (`load_enum_sizes`, new). 186 / 186 quoted dump values
    are right (one false positive read a scaled value); a 2-byte-shifted read fails 141.
  - Direction-word renames were checked against their compares.
- **The audit after wave 14:** 1344 named rows have a token overlap under 0.34 (1483 after wave 13).
- **Finding: the RAM dump misses 0x80 bytes at 0x40c200-0x40c27f** (wave 14 globals3, checked by the main session).
  - `cm848_ram.bin` is 0x45f80 bytes, exactly 0x80 short of 0x440000.
  - At 0x40c200 it holds what the code gives 0x40c280 / 84 / 86: the collector end pointer 0x40c28a, 0, and the
    collector table address 0x3fddc4. The rows' own addresses read 0.
  - So from 0x40c280 up, read the dump at address - 0x80. 0x40c200-0x40c27f has no data: 15 named rows, the PWM
    period commands and the collector words.
  - `e2m_name_audit.py` / `lookup_tables.py` still read it flat (follow-up).

## Follow-ups (open)

- [ ] **The wave-14 holds** (stage 9 above):
  - the owner's three development mode function names;
  - the five CM550-shared functions, which need a cross-firmware rename;
  - the two struct items (0x40a406 `charge_flow_estimate_terms_t`, 0x40b87f 7 bytes).
- [ ] **The RAM dump gap in the tools:** `e2m_name_audit.py` and `lookup_tables.py` read `cm848_ram.bin` flat. Add one
  helper that reads 0x40c280+ at -0x80 and refuses 0x40c200-0x40c27f, and check the comments that quote dump values
  of those 15 rows.
- [ ] **Leads from the wave-14 reports** (`agent_prompts_and_reports.md`, stage 9 section):
  - **Crank / cam:** `engine_crank_state_t`'s fields are 819C Cam_Sync_Error_Count / Cam_Sync_State /
    Crank_Sync_Error_Count / Crank_Sync_State. `mpc555_updateEngineRunState` is the TPU-A channel 0 crank handler. The
    819B backup words are still `crank_*`.
  - **Converter clutch:** the `protection_*` rows still left.
  - **Thermostat monitor:** the `cssc_*` rows and `engine_cssc_oilTemp_*` functions (P0128).
  - **Torque map:** `j1939_fuel_table_*` (0x5c556 / 82 / 8e) is the MT_Max_Torque_Map in lb-ft, with a wrong `_cal`.
  - **The 8194 / 81AE / 8000 rows** still with a wrong `_cal`, and the 84 + 125 deferred sibling rows.
  - **Stale prototypes:** 0x12ad4 / 0x130dc declare two parameters but take none (build warning).
  - **TPU-A registers:** `mpc555_registers.csv` lists the TPU-A CFSR / HSQR / HSRR / CPR channel groups in the wrong
    order (the firmware's own channel setups fix them).
  - **End-of-line test:** the step functions' names do not match the sequencer.
  - **RAM refresh:** the `sensor_cal_*` rows at 0x3fd2d4-0x3fd2e0.
  - **The fault bitmap rows:** 49 rows in the EEPROM mirror are named without `_cal`. Decide the rule for EEPROM-backed
    non-calibration data.

- [x] **Wave 14: the function names** (done in stage 9: 75 renamed, 8 held). The wave-12 / wave-13 agents proved about 70 misnamed functions in their reports
  (archived in `agent_prompts_and_reports.md`). Examples: the data collector (`diag_dm1Buffer_circularFill`), alpha
  (`hpcr_calculateFuelTrimOutput`), PGN 65251 (`faultTimerHandler`), EEC1 (`j1939GetEngineStateCode`), the drivetrain
  ratio estimator (`protectionTimeoutControl`), the EGR orifice / mass flow models, the warm-up cycle monitor
  (`engine_coolantTemp_overheat_monitor`), the RAM refresh, the 48RE governor pressure code.
- [ ] **The rest of the HPCR governor settings:** block 8000 (0x409110-0x409138: `engine_sync_*_cal` /
  `cam_sync_*_cal` / `engine_speed_override_*_cal`) has wrong `_cal`s. HPCR_Governor_Mode and the gain scheduling
  curves were done in stage 8c.
- [ ] **Shapes and types from wave 13:** the 0x40a204 and 0x408f66 splits were done in stage 9, the 0x4094xx gain
  records in stage 8b and 0x408f56 in stage 8c. Still open: the `i16` candidates listed in the wave-13 / wave-14
  reports.
- [x] **The held renames** (done in stage 9 with their enums): `diagnostic_session_state` -> `ram_refresh_enable` and `j1939_standby_flag` ->
  `development_mode` need their enums (`DIAG_SESSION_STATE` / `J1939_STANDBY_STATE`) re-read first.
- [x] **The out-of-bin siblings the wave-13 agents listed** (done in stage 9; the rest is in the stage-9 follow-ups) (in their reports, `agent_prompts_and_reports.md`): rows
  that keep a wrong name next to a renamed family. Examples:
  - the rest of the alpha (0x40a16c-0x40a180, 0x3fa0d2-0x3fa0dc) and all-speed governor (0x40a1aa-0x40a208) words;
  - the PGN 65251 points 1 / 3 and the per-point reference fuelings (0x40ad90-0x40add2, ROM 1104);
  - the converter clutch (8C33 / 8C34) and 8C58 leftovers still named `protection_*`;
  - the data collector pointers (0x40c270-0x40c284);
  - the `cssc_*` coolant sensor family, the `cylinder1..5_timing_offset` acceleration buffers, the LSG_EVR
    alternator-load rows;
  - the block 8000 governor settings with a wrong `_cal`.
- [ ] **The rest of the misname review:** wave 13 took the zero-overlap rows with 3+ references. Still to review: the
  other low-overlap named rows (1489 in the audit now, keeps included), the 244 rows inside wider rows and the 24
  out-of-range records.
- [x] **Wave 13: the misname review**, zero-overlap part: done in stage 8 (226 renames). Some wave-12 leads below were
  covered there: the data collector, the PGN 65251 builder's words, alpha, the 8C59 / P1740 monitors and part of
  `boost_target_*`. The wave-12 agents' leads, all table-resolved or proved in code:
  - the `diag_dm1_*` words around 0x3fddb6 / 0x40c278 are the e2m data collector (blocks 0030-003B), not DM1;
  - `sensor_channel109_*` is the exhaust pressure sensor. `boost_pressure_synthetic_ema` / `boost_synthetic_ema_*` /
    `boost_correction_mode_flags` are the exhaust pressure estimate (1772);
  - `boost_target_*` is the exhaust temperature estimate;
  - `engine_to_vehicle_speed_ratio_*` is the transfer case low-range detection (8C60);
  - `engine_temperature_protection_filter_state` is the exponentialMovingAverage record of `drivetrain_ratio` (it
    filters `drivetrain_ratio_raw`), not a temperature;
  - `cruise_speed_factor_*` / `cruise_speed_offset*` are the high speed governor lead / lag compensator and fueling
    top-droop offsets. `cruise_ramp_zone_*_fuel_demand_threshold` are the top droop widths;
  - the `etc1_*` timers reload from the 10E7 cells; `j1939_fault_load_protection_*` is the P1762 monitor; the
    `protection_*` rows at 0x408ad2-0x408ade are P1740 converter clutch rationality; the 8C59 rows are the 48RE
    governor pressure monitors;
  - `faultTimerHandler` / `cm848_updateProtection*` build PGN 65251 (engine configuration);
    `cm848_j1939FormatDm1Message` is the TSC1 lost management; `cm848_governorDroopCalculation` is a number-to-text
    helper;
  - the alpha names in 0xe0f4-0xe518 (`cold_start_*`, `intake_temp_ema`, `fuel_demand_ramp_factor`);
    `thermal_fuel_limit_factor` is Fuel_Interp_Factor; `injection_timing_demand_output` is the low-horsepower-curve
    full-throttle fueling;
  - `cam_sync_validation_*` is the fuel pressure key-on rationality; the 10EB gains sit on `governor_*_from_table`
    names; `j1939_feature_config_word` is DM5's non-continuous monitors;
  - wrong `_cal` on ROM cells: `etc1_torque_mode_timeout_cal`, `fuel_demand_norm_zero_cal`, `cruise_speed_default_cal`,
    `protection_threshold_scale_cal`.
- [ ] **Shapes found by wave 12:**
  - the J1939 DTC definition table (0x5a4aa, `dword[170]`);
  - the fault aging table (0x5983a, 4 x {elapsed, rate});
  - the cruise gain sets (0x408e02 / 18 / 26); the 36-byte fault derate channel record (0x597b2); the 10EB gain set
    (0x5c4a6).
- [ ] **Wave-12 rows left out:**
  - the tau-0 / tau-1 polarity of 0x5c35a-0x5c362 (the code reads the "Tau_0" pair at the other blend end);
  - the `j1939_command_security_flags` shape (`dword` or `byte[4]`);
  - `exhaust_pressure_sensor_value_copy`;
  - the 8 drift rejects (with code-based names in their evidence).

- [x] **An e2m audit of the whole CSV with the parameter ID table:** done in stage 7 (`e2m_name_audit.py`, wave 12). The misname half is wave 13 above.
- [ ] **Leads from the stage-6 reports, not yet applied:**
  - 0x40a19a `boost_fuel_demand_blend_a` is e2m 1921 +6 Ambient_Air_Tmptr, the real ambient air temperature.
    0x40a608 `ambient_air_temperature_selected` is e2m 1A0C +0 Compressor_Inlet_Tmptr. Both were checked with
    `e2m_block_addresses.py --address`. This is why the 0x3fb9e2 filter record stayed unnamed.
  - `cm848_dispatchModeHandlers` (0x42978) is a boot initializer; it calls the power take-off initialization.
  - `emission_manager_engine_protection_state` could become a bitfield: nine masked tests in
    `cm848_selectChiAndAlpha`. Run a piece census first.
  - The "6-byte table at 0x539508" in PTR_POINTERS_DOCUMENTATION.md is unbacked: those flash2 bytes are code.
  - The local j1939 Mongo entry for 65264 is wrong: it holds PGN 65266's fuel economy parameters.
- [ ] **The rest of the emission manager:** DAT_003fba26 / DAT_003fba36 (no writer found); the store-only 0x3fba22 /
  0x3fba24 (level 1 / 2 ambient temperature limits, medium); the `j1939_tsc1_override_state.proprietary_offset_value`
  misname (a torque); the compressor outlet temperature scale (the CSV says 1/64, the code and e2m suggest 1/32).

- [ ] **Codes 37 / 38 (T2SPD / T2TORQ) and 49 / 50 (OFCSTATE / AFRSTATE):** only compared in this build. The e2m T2
  family looks like a two-speed axle or transfer case shift controller; OFC is the combustion oxygen-fuel control; AFR
  is the air-fuel ratio.
- [ ] **Not applied yet:**
  - the i16 retypes of the signed crank words (0x40a79a / 9c / a2 / a6 / b6 / b8, 0x406858 / 5a / 64 / 66 / 68 - lha);
  - the low-confidence crank words 0x40a79c (Crank_4D_Timing), 0x40a7a2 (Crank_Wet_Stack_Timing), 0x40a7b8
    (SOI_Before_Startup) and 0x3fdfdc (Engine_Startup_Inhibit);
  - the unnamed crank defaults DAT_0005b1b6-0x5b1bc;
  - the power take-off fueling clamp maximum 0x407196 and the QD / QI / QP reference limits 0x4071a4-0x4071aa (no
    readers; the PID's fuel maximum is `cruise_speed_blend_working`);
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
