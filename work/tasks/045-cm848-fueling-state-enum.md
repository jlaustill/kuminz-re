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

## Follow-ups (open)

- [ ] **The rest of the EMO family.** The other inputs of `fuel_demandMin_maxSelect_rateLimit` and its output
  `fuel_demand_min_threshold` look like AECD caps and the selected NOx emission level cap, not fuel demands. Also
  `DAT_0040a5ec` (the AECD flag pack; e2m `EMM_AECD_State` per the `combustion_status_flags` note) and the
  calibration words `DAT_00406568` / `DAT_0040656a`.

- [ ] **Codes 37 / 38 (T2SPD / T2TORQ) and 49 / 50 (OFCSTATE / AFRSTATE):** only compared in this build. The e2m T2
  family looks like a two-speed axle or transfer case shift controller; OFC is the combustion oxygen-fuel control; AFR
  is the air-fuel ratio.
- [ ] **Not applied yet:**
  - the i16 retypes of the signed crank words (0x40a79a / 9c / a2 / a6 / b6 / b8, 0x406858 / 5a / 64 / 66 / 68 - lha);
  - the low-confidence crank words 0x40a79c (Crank_4D_Timing), 0x40a7a2 (Crank_Wet_Stack_Timing), 0x40a7b8
    (SOI_Before_Startup) and 0x3fdfdc (Engine_Startup_Inhibit);
  - the unnamed crank defaults DAT_0005b1b6-0x5b1bc;
  - the power take-off fueling clamp maximum 0x407196 (no row; the code takes `cruise_speed_blend_working`);
  - the six power take-off helper functions. 0x2abc8 `cm848_initProtectionFilterState` initializes the whole
    governor: the filter, the smoothing pointer, the QD / QI / QP adjustments = 0x80 and the four
    `governor_pid_interp_state_*` = 2.
  - the power take-off speed-error filter record that `cm848_calculatePowerTakeOffGovernorSpeedError` passes to
    `cm848_signedFirstOrderFilter`: 0x3fafb2 `protection_filter_state_ptr` (it points at
    `power_take_off_speed_error_filter_coefficient`) + 0x3fafb6 `governor_integrator_working` (the filter state).
    These would become `power_take_off_speed_error_filter` / `_filter_state`, like `cooling_fan_speed_feedback_filter`.
  - a shared `{coefficient pointer, state}` struct for the 16 `cm848_signedFirstOrderFilter` records. Today each one
    is a flat pointer + dword.
  - the other power take-off words with "protection" names (`protection_monitored_rpm_snapshot`,
    `protection_rpm_axis_cal` / `_values_cal`, `governor_speed_gain_factor`);
  - `governor_rpm_reference_snapshot` (the 1500 rpm maximum set speed).
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
