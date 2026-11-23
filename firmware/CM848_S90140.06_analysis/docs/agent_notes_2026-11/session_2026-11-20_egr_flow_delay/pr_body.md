## Summary

**Is `cm848_throttleBasedFuelCalculation` (0x128a0) named properly? No.** It computes nothing about the throttle or
fueling. It is the EGR transport delay stage of the CHP charge flow model. CHP is the e2m prefix of the charge, EGR and
fresh air flow records; the e2m never spells it out, so no name guesses an expansion.
- **The proof:** the ECU's own parameter ID table (found 2026-11-19) maps every word the function writes to e2m block
  177F, and its struct `throttle_fuel_trim_t` is that block, one field per record.
- **Round 2:** at the user's request the rest of the family is renamed too, on this PR (stages 3 / 4). The scope rule:
  a symbol is in if its e2m record is `CHP_` / `C_CHP_`, or if it is an input that a family function would otherwise
  misname.

What 0x128a0 does, every 10 ms (phase group A, every even phase of the 5 ms main loop):
- **The oxygen delay:** CHP_O2_Flow_Delay = C_CHP_Volume_Fraction x 120 x 1000 / (volumetric efficiency x engine
  speed) ms. That is the time the engine takes to breathe that fraction of its displacement. The e2m scale is 0.001 s.
- **The oxygen fraction in the EGR:** the residual oxygen fraction goes through a 256-sample delay line (delay / 10 =
  10 ms samples) and a filter, which gives CHP_O2_Frac_EGR.
- **The EGR flow delay:** CHP_EGR_Flow_Delay is a fraction of the oxygen delay. The EGR mass flow goes through a second
  line and the signed filter, which gives `egr_mass_flow_delayed_filtered`.
- **The EGR fraction:** EGR_Fraction = delayed EGR flow x 8192 / charge flow, capped at 1.0.
- **The RAM dump agrees** (key on, engine stopped): the oxygen delay reads 40959 = 0xffff x 1000 / 1600.

The whole 10 ms task after both rounds:

```c
void cm848_calculateChargeFlows(void)          // was cm848_fuelControlMainCalculation
{
  cm848_calculateChargeFlowEstimate();         // was cm848_fuelDemandWithLoadCompensation (e2m 177C / 177D)
  cm848_calculateDelayedEgrFlowAndFraction();  // was cm848_throttleBasedFuelCalculation (177E / 177F)
  cm848_calculateFreshAirMassFlow();           // was cm848_fuelDemandErrorCalculation (177B)
  return;
}
```

## Changes

**Round 1: 0x128a0 and its struct.**
- **Stage 1, label-only (a513107).** `reverse_names.py` reports EQUIVALENT.
  - `cm848_calculateDelayedEgrFlowAndFraction`.
  - `cm848_delayUnsignedSample` / `cm848_delaySignedSample` (were `cm848_circularBufferWrite*`).
  - `egr_flow_estimate_terms_t` / `egr_flow_estimate_terms` (were `throttle_fuel_trim_t`), with all 12 fields from
    177F.
  - `egr_flow_source` (177F +18).
- **Stage 2, shape (d943bd0).**
  - `delay_line_t` on the two delay lines. They cover the boot-ROM call targets 0x3fa2f0 / 0x3fa5a0, which are now call
    overrides, and the boot calls still render by name.
  - Helper prototypes, `short` for the six e2m `S` words, `i16` for the EGR flow limits, and named locals.
- **Docs and review fixes (0805de0, 3a7d81a).**

**Round 2: the rest of the family.**
- **Stage 3, label-only (1d5752c).** `reverse_names.py` reports EQUIVALENT; all 49 names render.
  - **Functions:**
    - `cm848_calculateChargeFlows` / `cm848_initializeChargeFlows`;
    - `cm848_calculateChargeFlowEstimate` and `cm848_calculateFreshAirMassFlow`;
    - `cm848_calculateDownstreamEgrFlowSource` / `cm848_calculateUpstreamEgrFlowSource`;
    - four initializers.
  - **The exhaust pressure (e2m 1A5D / 1772):**
    - `cm848_calculateExhaustPressure` (was `phase_group_a_validateEngineSync`) and `cm848_initializeExhaustPressure`
      (was `cm848_initBoostPressureFaultHandling`);
    - `exhaust_pressure` (was `boost_pressure_current_raw`) with `_source` / `_state` / `_estimate` / `_estimate_state`;
    - the new row `exhaust_pressure_estimate_as_primary_cal` (EEPROM 0x468). It is 1 on this truck, so the estimate is
      the primary exhaust pressure.
  - **Tables:** the 10 EGR model tables and the 4 volumetric efficiency tables, named from their e2m records. They were
    `boost_fuel_*` / `throttle_*` / `boost_rpm_scale_*` / `boost_load_*` with a wrong `_cal`.
  - **Pumping torque (e2m 1780 / 1781 / 1954):** 8 words and the nominal engine delta pressure grid (were
    `fuel_demand_blend_*` / `fuel_demand_*_cal`).
  - **Filters and caches:** the charge mass flow and fresh air filters, and the four 1-D lookup caches.
- **Stage 4, shape (784b612).**
  - The three 2-D lookup caches are `word[2]`.
  - `void(void)` for 0x12ad4 / 0x12dc4 / 0x130dc. The asm writes r3 / r4 before any read, so their two stale prototype
    warnings are gone.
  - `word` returns for the source checks.
  - `i16` for the signed pumping torque words.

**Round 3: the user asked to "keep going, nothing is out of scope".**
- **Stage 5, label-only (ba425ad).** EQUIVALENT, 57 names.
  - **The TPE charge pressure estimate:** `cm848_estimateChargePressure` (was `cm848_calculateBoostTorqueOffset`; e2m
    1A22-1A29), with `charge_pressure_estimate` (was `boost_pressure_target`), its tables, caches and filter.
  - **The charge pressure in range monitor:** e2m 1A2D.
  - **The exhaust pressure:** the estimate `cm848_estimateExhaustPressure` (198C / 1772) and the sensor, channel 109
    (`exhaust_pressure_sensor_*`).
  - **The EGR delta pressures:** e2m 1A19, `egr_valve_delta_pressure` / `engine_delta_pressure`.
- **Stage 6, shape (9a2ba1f).** `i16` for eight of those words, and `void(void)` for 0x13294.
- **Stage 7, label-only (8022da1).** EQUIVALENT, 0 functions differ. The engine speed block e2m 819B:
  - `engine_rpm_state_t_0040b7ac.current_rpm` (356 lines) is `engine_speed_state.filtered_engine_speed`;
  - the main and backup speeds;
  - the cam / crank sync counters and the start times.
- **Stage 8, the signedness sweep (cd7ad20).**
  - **The rule:** 430 words become `i16`: each one's e2m record is signed 16-bit and every load of it is an `lha`.
  - **Kept `word`:** 14 words whose address goes to a `word *` parameter, and one read through an `lhz` pointer.
  - **Proof:** a cast-normalized diff. 133 functions changed, and the 6 that still differ are cosmetic.
  - **Effect:** 617 fewer `(short)` casts.

**Round 4: rename wave 15 (the agent wave you gave the go-ahead for).**
- **Stage 10, the wave (5f0f9d9).** Label-only, EQUIVALENT.
  - **Scope:** six read-only Sonnet agents (~3.3M tokens) reviewed 378 named rows. Each shares at most 20 % of its
    words with the e2m record the ECU's parameter table resolves to its address, is used in the code, has its dump
    value in range, and was never reviewed. Wave 13's 15 drift rows were left out.
  - **Verdicts:** 185 renames, 187 keeps (each gets an `| e2m:` note), 5 drift, 1 uncertain. Every rename carries a
    quoted `.cpp` line that the gate checks, and I read all 185 against their quotes.
  - **Hand decisions:**
    - 0x5c380 is PGN 65249 byte 19, the peak torque percent.
    - Cruise_RSG_* calibrations stay `cruise_*`.
    - The four LSG gain sets are named as sets.
    - CM550's `governor_integral_accumulator` is an unrelated pointer, so 0x40b53e is renamed on CM848 alone.
  - **Plus the whole e2m 1170 "ASG application specific" record:** 25 rows (were `engine_operating_mode_restore_*`),
    `cm848_selectAllSpeedGovernorApplicationMode` and `FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION`. Nothing restores
    anything, and nothing writes the record.
- **Follow-up 1 (8bdd341), label-only, EQUIVALENT: 107 globals, 17 functions.** The agents' siblings and function
  leads, verified by hand and run through the same gate.
  - **The low speed governor:** the working P / I / D / jerk gains had crossed names. Also the terms, clamps and
    adjustments, the 1064 constants (ten with a wrong `_cal`), the aggressive (10EE / 10EF) and gear (10EA) gain
    logic, and nine functions.
  - **The rest:** the HSG compensator (were `cruise_speed_*`), the ASG 107D leftovers, the net torque fuel limit.
  - **The compressor inlet vocabulary:**
    - The ECU's table names the channel 20 sensor Compressor_Inlet_Tmptr_Sensor, its selected value
      Compressor_Inlet_Tmptr and the density Compressor_Inlet_Density.
    - The ambient air temperature (1921 +6) is computed from them.
    - So `ambient_air_temperature_selected` → `compressor_inlet_temperature` (this reverses round 3's rename of its
      source word), `ambient_air_density` → `compressor_inlet_density`, `ambient_air_temperature_reference` →
      `ambient_air_temperature`.
- **Follow-up 2 (ea8a913), label-only, EQUIVALENT: 50 globals, 17 functions.**
  - **J1939:**
    - 0xfed200 is PGN 65234 = DM10 (the J1939 database; DM11 is 65235), so the `dm11` names were wrong.
    - The anti-theft status is PGN 56320, not 56360: a PDU1 PGN excludes the destination byte.
    - 56832 is Reset.
    - The 1254 priorities get `_cal`, and the 117F anti-theft words are named.
  - **The A/C clutch control:** 8A14 +4 says 0 = BR truck, 1 = DR truck, and this truck holds 1. The dispatcher and
    both algorithms were `engine_protection_*`.
  - **The injector driver:** PWM 16-19 are its reference levels and periods. The booster capacitor channels 54 / 55
    get wrappers named by when they run.
  - **Also:** the accelerator pedal faults, the engine protection shutdown counters, cruise rows, the tire size.
- **Stage 10c, shape (158c318):**
  - `low_speed_governor_gain_set_t` (four `short`) on the six gain sets, with the two pointers typed. The loader now
    reads `low_speed_governor_gain_set_pointer->proportional_gain` with no cast.
  - Two dwords split by their e2m records.
  - Byte rows for the supervisor chip pair: the old word render read the overspeed count as
    `(byte)targets_per_revolution`. 0x409530 is a byte too.
  - dword encryption seeds (no more `_` prefix) and i32 ASG adjustments.
  - **Proof:** after reversing the labels, twelve functions differ, eleven only by the intended rendering and one only
    by its local declaration order; the decompiler's piece accesses fall from 508 to 494 (none added).
- **Leftovers (stage 10e), label-only:** the half-renamed neighbours the final review found: the channel 20 / 9 fault
  statuses, the DM10 payload word (was `j1939_dm11_*`), the PGN 56320 header address bytes (were
  `j1939_prop_status_*`), three unused `j1939_pgn56360_alt_*` labels. Also five doubled e2m prefixes in comments.

**Round 5 (your second "keep going"): hand fixes on the wave 15 leads, each verified in the code.**
- **J1939 builders vs their PGNs (c1ebdc4).** A script lists the PGN that every header builder encodes.
  - **Four builders named the wrong message:** 65232 is DM8, 61441 is EBC1 (not ETC1), 65279 is the water in fuel
    indicator (was "SafetyStatus"), and 65251 is EC1.
  - **CM550:** `initFaultTimerMessage` is renamed there too. It builds the same header, so it is a true twin and the
    shared name stays shared.
  - **EC1 send-on-change:** the old "fault timer / fault counter" family is the EC1 payload, its previous copy and the
    J1939 rule "resend on a 10 % change" (`cm848_hasWordChangedByTenPercent` / `...Byte...`).
- **`all_speed_governor_gain_set_t` (0dea32e):** on the throttle-mode set, the application set and a ROM table of four
  (one per TSC1 requested speed control condition). The TSC1 selector now reads
  `j1939_tsc1_speed_control_condition_gain_sets[mode].integral_gain_1` (was `*(word *)(&DAT_0005c1da + iVar1)`).
- **`drivetrain_type` is the vehicle speed sensor type (705f055).**
  - **The record:** e2m RSC_Sensor_Type: 0 none, 1 inductive, 2 minigen, 3 tachograph, 4 / 5 J1939 with / without gear
    ratio. All 31 uses agree with it.
  - **The names:** `vehicle_speed_sensor_type_cal` (EEPROM mirror) and `VEHICLE_SPEED_SENSOR_TYPE`. The truck holds 1
    (inductive). The cruise fix is unchanged; its mode 4 is `VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO`.
- **e13e2a2:**
  - `INTAKE_AIR_HEATER_PHASE` (e2m 8A35 +2), with the "run-up" phase renamed crank;
  - `fuel_demand_control_t.override_priority` (was `override_active`) and the two throttle override claimers;
  - the cruise maximum / minimum engine speeds;
  - the compressor outlet temperature is 1/32 °F, so a "220 °F" limit is really 440 °F.
- **06a42fe / 1d5e537 / a6d3367:**
  - the cruise / vehicle speed limit governor's Bank 2 functions (were `protection*`);
  - the A/C clutch working words (were `protection_event26_*`), with its second condition code;
  - the injection hardware initialization, the fuel system hardware shutdown monitor and the LSG gain selection
    initialization;
  - the cruise governor's preset-this-pass flag.
- **Proof:** every round 5 stage is label-only (EQUIVALENT, and the comment-stripped diff finds 0 changed functions),
  except the two type stages. There the struct stage changed five functions, each only by the intended render, and
  the enum stage changed seven, each only by the enum render.

**Round 6 (the TSC1 / ETC1 lead): the J1939 powertrain control state, from e2m's own Jcomm blocks.**
- **Stage 0 (47d462a):** deletes two orphan struct definitions over the live TSC1 state. One still laid symbols over
  two globals, and removing it drops 15 underscore renders (14 + 1; two more were comment text) and 7 overlap
  warnings.
- **Stage A (247bebf, label-only, CM550 twin included):**
  - **The handler pair:** the TSC1 dispatcher routes PGN 0 by destination address. The engine's TSC1 goes to
    `processEngineTsc1Request` (was `torqueControlModeHandler`, also CM550's 0x2f128), the retarder's to its sibling.
  - **The three structs:** `j1939_powertrain_control_state` (was `j1939_tsc1_override_state`),
    `j1939_powertrain_messages_received` (ETC1 + ETC2 + TSC1 bytes; was `j1939_tsc1_received`) and
    `tsc1_source_configuration_table` (the SA whitelist: 10 entries of data link, source address and per-mode
    request timeouts / time limits).
  - **Fields that held something else:** `governor_mode` = the override control mode (SPN 695),
    `etc1_speed_setpoint` = the requested percent torque, `etc1_torque_limit_value` = the mode 3 speed limit, and
    `torque_limit_mode_select` = the ETC1 high idle override (SPN 606).
  - **The ETC1 timers** are named for the e2m 10E7 cals they load.
- **Stage B1 (2f5eec4): e2m 10E8 is Cummins' "Jcomm" layout of the struct.** It confirms the stage A names (e.g.
  Jcomm_Engine_Control_Network_Type 0 = J1922 / 1 = J1939) and corrects five: the out of gear network type, the
  J1939 blocked message bits, the net output torque and the two control device indicators. Every covered field now
  cites its record.
- **Stage B2 (4ae5f79): types.**
  - **Enums:** `TSC1_OVERRIDE_MODE` (SPN 695, now a word), `J1939_CONTROL_DEVICE` (none / transmission / ABS / ASR /
    unknown) and `CONTROL_NETWORK` (J1922 / J1939), e.g. `engine_control_device_indicator ==
    J1939_CONTROL_DEVICE_TRANSMISSION`.
  - **The e2m S fields** are now `short`.
  - **The source table** is a typed array, so `->retarder_torque_control_request_timeout` replaces
    `*(short *)(ptr + 0xe)`.
  - **The ETC2 receive words** are settled from the stores: a word at +0xa (the CSV had a byte, hence `_10_2_`) and
    the SPN 526 ratio at +0xd.
  - **Also:** 0x5c39a is the high idle override speed.
  - **The TSC1 source table, read from the ROM image:** the whitelist is 0x03 / 0x0B / 0x21 / 0x4A / 0x4F,
    with 50 ms request timeouts. Speed control is unlimited only from 0x03 (0xFFFF wraps to 0) and lasts 6 s
    from the other four, after which the sender is ignored until it sends override disabled. That matters for
    task 022's TSC1 work.
  - **Reverted:** a bitfield. Ghidra rendered its masked writes as a raw piece.

**Round 7 (another "keep going"): the J1939 monitor's session record, the retarder TSC1 words, the drivetrain
ratio module.**
- **Stage A (9d2ebdf, label-only):**
  - the J1939 monitor's e2m 1100 words and the tracker's retarder-half copies;
  - the engine retarder TSC1 handler read in full: the received bytes, a zero torque request timer, and a speed
    control flag that is always 0 because the handler rejects speed control;
  - `cm848_resetEngineRetarderTsc1Request` and `cm848_endRetarderShiftAssistAboveFuelDemandLimit`.
- **Stage C (9fd5621, label-only):** the drivetrain ratio module.
  - **Two misnamed words:** `drivetrain_ratio_filter_state` was `engine_temperature_protection_filter_state`, and
    `drivetrain_ratio_engine_period_valid_flag` was `protection_timeout_enable_flag`.
  - **Gear down:** `governor_j1939_bypass_flag` is the gear-down protection range (`drivetrain_gear_range`: top gear
    / one gear down / lower). With the feature on, only top gear keeps the road speed governor's droops.
- **Stage B (8b1c0f3, types):**
  - **`j1939_control_session_t`,** the j1939mon record (e2m 10FD / 10FE / 10FF), on the history `[5]` and the two
    active records. Its layout comes from the code and the EEPROM image's length words, and it replaces four member
    rows.
  - **The drivetrain cals** from e2m 106D, plus `gear_down_gear_ratio_cal`.
  - **`DRIVETRAIN_GEAR_RANGE`.**
- **Found:** the history table's length word is also `j1939_input_signal_timeouts[24]`. The supervision tick would
  count it down, but the tick is off in this calibration.

**Round 8 (another "keep going"): the 48RE transmission controller, named `protection_*` until now.**
- **The method:** the Chrysler e2m `RE_*` records, aligned by relative offset and proved word by word by code use.
  - 8C53 resolves through the parameter ID table to `transmission_pressure_state`.
  - 8C17 (RAM, 0x40b102) aligns +0..+4A. Its `RE_OSS_Accel` and seven names that were already right confirm it.
  - 8BBC (ROM cals, 0x40780c) aligns +0..+5C. Its `RE_Inertia_Default` is the word the shift logic initializer copies
    into the learned inertia (`lhz @ 0x331d4`).
  - 8C18 (ROM cals, 0x4082f4) aligns +00..+98, and 8C19 (the flag bytes) sits at 0x40b0e8 (stage F).
- **Stage A (e848623, label-only): the anti-hunt mode.**
  - `cm848_selectGovernorPressureAntiHunt` holds the governor pressure on a hold curve, which prevents the upshift,
    then forces it with a boost curve once the predicted post-shift acceleration clears the minimum for the throttle.
  - The prediction: the road load from a turbine torque estimate x the gear ratio, the next gear's torque, ÷ a
    vehicle inertia learned across each forced 1-2 shift.
- **Stage B (1766051, label-only):** the rest of both blocks.
  - the low range strategy (`cm848_selectGovernorPressureLowRange`, was `cm848_protectionOverloadHandler`);
  - the lockup / unlock, WOT and cruise decel cals;
  - the predicted shift delays (were `governor_pressure_learned_gain_gear1` / `2`);
  - `hot_mode_flag` = `transmission_overheat_protection_active_flag`;
  - `transmission_lockup_timers_t`;
  - the timer tick, the initialization and the governor pressure sensor offset calibration.
- **Stage C (d542b7d):** the gear ratio table is typed `word[6]`, and the inertia default and the shift logic
  initializer are named.
- **Closing (f349dd2):** the old-name sweep and the resolved-name notes. It also fixes a firmware/CLAUDE.md history
  sentence that the stage B reference refresh had rewritten (`round8/refresh_audit.py` now lists every comment-only
  refresh).
- **Stage E (94773eb, label-only):**
  - a "converter clutch engagement monitor" and a "high gear mode" (stage F corrects both, below);
  - the WOT anti-hang timer and upshift engine speeds, and the cruise decel delay timers.

- **Stage F (0b685f3, label-only, after a review): e2m 8C18 (0x4082f4, +00..+98) and the exhaust brake lockup aid.**
  - 71 ROM cals named from 8C18, each checked against its row's users. Among them: the engine acceleration limits,
    the WOT shift lag band, the lockup and overheat lockup delays, the throttle detent / WOT thresholds, the
    predicted shift delay limits and the overheat protection temperatures (were `hot_mode_*`).
  - The e2m corrects stage E. 8C17 +4A is `RE_E_Brake_Inhibit_Timer` ('Used to time ebrake TCC inhibit timeout
    limit'), the per-gear windows are `RE_EB_Lockup_Range_*` and the flag is 8C19 +16 `RE_E_Brake_Inhibit_LU`. The
    code agrees: `cm848_updateEngineRetarderEnableState` reads its bit 0 as lockup disengaged. So the function holds
    the exhaust brake off until the converter locks: now `cm848_updateExhaustBrakeInhibitForLockup`,
    `exhaust_brake_inhibit_*` and `transmission_exhaust_brake_flags` (stage G).
  - Pressure state 0x10 is `RE_Lockup_Boost`, so its mode is `cm848_selectGovernorPressureLockupBoost`. Switch 12 is
    the exhaust brake switch.
  - Review fixes: the output shaft acceleration plate (two methods), ordinals, and three `global_variables.csv`
    comments that an earlier script had quoted (that file takes commas unquoted).
- **Stage G (label-only, after a second review):**
  - The exhaust brake inhibit names follow their records' word order (`RE_E_Brake_Inhibit_LU`: the exhaust
    brake is inhibited): `cm848_updateExhaustBrakeInhibitForLockup`, `exhaust_brake_inhibit_*` and
    `transmission_exhaust_brake_flags` (`RE_Trans_EBrake`).
  - The flag byte's bit 2 is `RE_Ebrake_Inhibit_Timeout_Flag`.
  - Switch 12 is proved to be the exhaust brake switch (it drives `engine_retarder_switch_percent_2`).
  - 8C19 is checked at +0..+3, +9, +A, +C and +16.

**Round 9 (another "keep going"): the 48RE tables in memory order, the governor pressure controller, the pressure
state enum, the flag bytes.**
- **The method:** e2m column 5 numbers every ROM calibration block in memory order (RAM blocks have 0000).
  `walk_tables.py` walks the tables from round 8's anchor, sizing each from its length word in the dump. 118
  tables land on an existing `word[N]` row of exactly the walked size, and each one's users are the mode its record
  names. That is 88 + 30 walked, plus the exhaust brake set and a few placed by order and code, about 156 in all.
  A size match alone is not proof: the code users decide.
- **Stage A (0f4daf6, label-only):**
  - the walked tables and the scalar blocks 8BB5 (the governor pressure controller's calibration), 8BBB and 8BBD;
  - the `cm848_throttle*` family, which is the governor pressure solenoid PID (its offset limits had backwards
    names);
  - `cm848_selectGovernorPressureCruise` and the low range / normal lockup, unlock and shift functions.
- **Stage B (84be9af, label-only):**
  - the tables after 8C18;
  - the exhaust brake tables, which are e2m 8CA6..8CC6 in their own column-5 range;
  - the manual 2nd curve.
- **Stage C (3301eb9):**
  - `TRANSMISSION_PRESSURE_STATE`, with 24 members, every value proved by its store and checked by
    `check_enum_proof2.py`;
  - the 27-word output speed ring;
  - a `dword` fix.
- **Stage D (f63a28b):** the 8C19 flag bytes as `transmission_control_flags_t` / `transmission_shift_strategy_flags_t`.
- **Stage F (fb2426c, label-only, after a review):**
  - e2m 8BB6 confirms the controller's RAM names; the derivative term, error slope and proportional term get their
    record names.
  - Stage D's bare old field names in 48RE comments and plates are replaced.
  - The P0720 monitor's bit is `limp_home_flags_4` bit 5 = `RE_OSS_Limp`.
  - `governor_pressure_normal_curve`.

**Round 10 (another "keep going"): types, the 48RE monitors, the transmission relay, the SCI actuator tests.**
- **Stage A (3be5a5e, label-only):** the 78 RE lookup caches (54 `DAT_` words and 24 `protection_*` names) take
  their table's name.
- **Stage B (b9df152, types):**
  - 26 RE calibrations are `i16`: their e2m record is signed, and every load is `lha`.
  - The 98 label-only rows of rounds 9 / 10 get types.
  - The learned 1-2 shift lag table `transmission_1_2_shift_lag_cal` (EEPROM, e2m `RE_One_Two_Lag`).
- **Stage C (c9e793d, label-only):**
  - **The cache suffix:** every lookup cache ends in `_cached_axis_offset` (127 `_interp_state` /
    `_interpolation_state` rows; "interp" is a short form, and the lookup's own parameter already had the name).
  - **Output 16 is the transmission relay:** its output check pairs P0883 / P0882 'TCM power input', and fault 137
    sets the e2m bit `RE_Trans_Relay_Circuit_Open`.
  - **The transmission controller's functions:** the relay request, the limp-home flag update, the input step,
    and the two phase-group-B phases (they were `protection_*` / `processCalibrationTablesMain`).
  - **The monitor words:** the P1762 / P1756 / P1757 monitor words, which had `j1939_*` / `protection_coldStart_*`
    names.
- **Stage E (4ff8174, label-only):**
  - **The P1740 converter clutch monitor's working words.**
  - **The SCI 0x13 actuator tests.** The DRB database names every test code the callback handles: A/C clutch
    relay, the intake heaters, fuel transfer pump, transmission relay (13-43, on output 16), wait to start lamp,
    exhaust brake, the cruise solenoids, fuel control and PWM radiator fan. The old `cold_start_protection_*` /
    `diag_protection_*` names were a cold-start guess.
- **Stage D (ee328b7):**
  - **`DIAGNOSTIC_MONITOR_STATE`:** the e2m NORUN / RUN / CMPPS / CMPFL / ABORT list, on six 48RE monitor states,
    checked by `check_enum_proof2.py`.
  - **The limp-home bit map:** each byte's comment maps the e2m 8C19 bit records, with each bit's fault / DTC
    setter.
  - **23 more lookup caches** named after their tables.
- **Stage F (84033f0, types):**
  - `sci_output_test_timers_t`: one timer per actuator test. The calls read
    `cm848_stopSciOutputTest(&sci_output_test_timers.intake_heater_1,0x2b)`, thanks to `word *timer` prototypes
    (with Ghidra's `short *` guess the field addresses printed as raw constants).
  - The widths: 0x3fceee as a `dword` drops the overlap WARNING from the two P1756 / P1757 functions.

**Round 11 (a "keep going" relayed from another session): the e2m discrete I/O maps.**
- **The e2m tables of the discrete I/O:**
  - 1577 names the 80 logical output requests (output N = byte N/8, mask 1 << N%8) and 1612 the 32 switches; 12A7 /
    12A8 are their override priorities.
  - They confirm round 10's DRB names. Output 16 is Transmission_VFS_Battery_Driver, the relay's battery feed to
    the solenoids.
  - They also confirm the switch findings: 20 = park / neutral, 12 = the exhaust brake select.
- **Stage A (3c1f706, label-only):**
  - **The lift pump control:** `cm848_controlLiftPump` / `cm848_initializeLiftPumpControl`, its run reason and
    stopped timer, and the e2m 8A6F calibrations: override state, the run times after cranking 20 s / key-on 35 s /
    running 0 s, override enable. This calibration has a fixed key-on word, so 11.45's records after +2 sit one word
    later.
  - **The SCI output status word** (`cm848_sciPackOutputStatusWord`, was `FUN_0051dfdc`).
  - **Two cache names**, and the 1612 switch map.
- **Stage B (9e292a9, types):**
  - Bitfield structs for six request bytes, from 1577: the engine brake drivers 1-5, the A/C clutch, the intake air
    heaters, the lift pump, the EGR valve and VGT drives.
  - `LIFT_PUMP_RUN_REASON`.
  - No new `._N_1_` pieces.
- **Stage C (2da9b14, types): `switch_input_state_t`.** Byte 2 (park / neutral, the O/D OFF button, the relay and
  solenoid feedbacks) is a bitfield unit; bytes 0 / 1 / 3 are byte fields with their bit maps.
  - Their bits have read-modify-write setters, which the firmware/CLAUDE.md wave 11 rule keeps as bytes.
  - The all-bitfield pilot measured 216 named reads against 10 piece lines in 3 setters plus a `field_0x0` in the
    scanner. It is not shipped; it is left to the user.
- **Stages D (a12ff3b) / E (e3f493c, label-only): output 54 is `driver_asic_shutoff_request`** (e2m
  `ASIC_FS_Shutoff_Driver`). The fuel system fault reactions request it. Every reader pairs it with the
  supervisor's shutdown line, and the read-back and injector diagnostics stand down while it is set. It is not
  output 30 `FSO_Command`. Stage D's `fuel_shutoff_request` was replaced after the review.

**Round 12 (the relayed "keep going"): arrays and the CP3 fuel metering vocabulary.**
- **Stage A (9448e53, types): nine scalar rows typed as the arrays their comments describe.**
  - The arrays: the switch debounce history, the fuel demand timing ring, the J1939 source-address whitelist, the
    misfire per-slot counts and flags, and others.
  - The 16 words at 0x3fd0ca are eight 2-D lookup caches, one per fuel pressure setpoint table. They are split into
    eight named `word[2]` rows, where a `word[16]` attempt rendered `x + 8`.
- **Stage B (3588241, label-only): `cm848_calculateFuelMeteringCommand`'s `cam_sync_*` / `engine_sync_*` guesses**
  are re-domained from the e2m `HPCR_*` records (43 rows).
  - **e2m 8B3C** aligns at 0x40913a, and the code confirms its records (the coil temperature = gain x resistance /
    0x138 + offset).
  - **The pump tables:** duty to current, the start / hot start duty presets, the duty pre-control map (the
    feed-forward), the maximum duty, and the battery correction.
  - **Also:** their caches and the coil temperature flags. The ROM tables lose `_cal`.
- **Stage C (5698e89, label-only, after a review):** the current integrator preset table (e2m 8B49 / 8B4A) and the
  last caches. Stage B had scanned only part of the function. Also the plate (the tool override, not a cranking
  value) and stale text.

**Round 13 (the relayed "keep going" again): the end-of-line tests and the SCI command 0x25 service tests.**
- **Stage A (99a8d67, label-only): the steps of the Chrysler end-of-line (in-plant) test sequencer.**
  - The steps are the output tests (lift pump / wait-to-start lamp and A/C clutch relay / intake air heaters), the
    heater voltage-drop verdict, the alternator test, the fan speed noise, the misfire test and the final result.
  - They were cold start / protection / cam sync guesses. e2m 164A / 1649 name their settings.
  - **The SCI command 0x25 tests** (DRB 25-xx, e2m `Cmd25`) and their timeouts: the alternator field, the 48RE
    solenoids, the lift pump, the cylinder contribution test and the high pressure safety valve test.
- **Stage B (a44169f, types):** `SERVICE_TOOL_TEST_STATE` (e2m 0 not run / 1 running / 2 aborted),
  `END_OF_LINE_TEST_STEP` and `END_OF_LINE_OUTPUT_TEST_STATE`.
- **Stage C (f951258, label-only):**
  - the DRB SCI 0x19 'SET RPM' request;
  - the LSG base reference speed and the ASG minimum / maximum reference speeds from e2m block 0008. The old names
    called the minimum 'high'.
  - the bit maps in the comments.
- **Stage D (comments, after a review):** SCI 0x25 tests 5-10 cut out firing-order slots 1-6 (cylinders 1 / 5 / 3 /
  6 / 2 / 4), not injectors 1-6. The fault cutout's bank masks 0x55 / 0xaa only fit firing order.

**Round 14 (the relayed "keep going" again): the low speed governor reference speed chain.**
- **The records:** e2m 14EE / 1496 / 14EF / 14F0, aligned by relative offset (they lie past the dumped parameter ID
  table). Every record matches its code use and the dump values.
- **Stage A (29de6d0, label-only):**
  - the coolant temperature speed, the desired speed selection and the slew (were `cm848_updateSpeedLimitFromCoolant`
    / `cm848_calculateProtectionSpeedLimits` / `cm848_applySpeedLimitConstraints`);
  - 68 words, among them the A/C / drive / park / extended idle / tool / moving speeds and the rates;
  - the struct `low_speed_governor_reference_t`.
- **Stage B (d65de3e, types):** `LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE` from the record's own value labels.
- **Stage C (3307773, types):** a dword split into its two halves.

**Round 15 (the relayed "keep going" again): the e2m pool above 0.2 overlap, part 1.**
- **Stage A (123d6ae, label-only):** sixteen sensor channels named as families from e2m 1966 (124 rows). Each channel
  is proved at its calls and by its DTCs.
- **Stage B (359ecb7, label-only):**
  - the tachometer outputs: e2m 1565 names the output channel map, and entries 25 / 26 are todo 035's "actuators c / d";
  - the 4D fueling maps, the LSG leftovers and checked singles.

**Round 16 (the relayed "keep going" again): the cruise control / road speed governor.**
- **Stage A (9b3450f, label-only):** the family from e2m 117D-1191, with one vocabulary: `road_speed_governor_*`
  (state 10 is `FUELING_STATE_ROAD_SPEED_GOVERNOR`), the cruise / RSG PID's gain sets, the sump and the preset
  fueling. It also names the maximum road speeds and their trims, the cruise speed command ramps and steps (e2m 118F)
  and `CRUISE_CONTROL_STATE` from its e2m value list.
- **Stage B (9a1bd93, types):** `cruise_governor_gain_set_t` and `second_order_filter_state_t`, the typed pointers and
  11 new rows.
- **Stage C (5945df3, types) and D (098ecfe, docs), the user's two decisions:** the switch bytes 0 / 1 / 3 as
  bitfields (180 named bit accesses for 10 piece lines), and the round 11-15 methods in firmware/CLAUDE.md.

**Round 17 (the relayed "keep going" again): the engine retarder request chain.**
- **Stage A (9d4ddaf, label-only):** the chain in the e2m's words: the override command (TSC1), the non-override
  command (the lowest of cruise / switch / TSC1 limit), the allowed state, the command level and source. It also
  proves the `algorithm_enable_flags_18_t` bit 14 guess: `engine_retarder_service_brake_activate_enable`. The chain's
  plates are rewritten.
- **Stage B (bd059da, types):** `ENGINE_RETARDER_COMMAND_SOURCE` and `ENGINE_RETARDER_ALLOWED_STATE` from their e2m
  value lists, and `J1939_CONTROL_DEVICE` on the retarder's device word.
- **Stage C (833d573, types):** the `EB_Brake_Type` bitfield (exhaust / VG brake), and the 0x40a35c dword split.
- **Stage D (93b46ef, label-only, after the review):** the counters renamed beside the command / output level words,
  and `algorithm_enable_flags_41_t` bit 0 is `engine_retarder_extended_idle_enable` (its old "speed limit" name came
  from the extended idle flag's old name).

**Round 18 (the relayed "keep going" again): types and the main injection timing selection.**
- **Stage A (cc6189f, types):** the cruise Q16 integrator as `q16_fixed_point_t`, the AFC slew rates as dwords, and
  the 4D fueling caches as `word[2]` (underscore warnings 24 -> 22).
- **Stage B (3d714fe, label-only):** `main_injection_timing_selection`, the user commanded and 4D timing, the AENBLFLG
  word 4, and the timing source members from the 103B value labels with their limit words.
- **Stage C (99dd717, types):** the two timing enums, the `algorithm_enable_flags_4_t` bitfield, and five lookup
  caches (the misread `dual_axis_table_dims_t` struct is gone).
- **Stage D (label-only, after the review):** one prefix rule for the main timing (`injection_timing_main_*` for
  its inputs and limits), the misfire limit's table, the power-up timing source, and the plates' retired words.

**Round 19 (the relayed "keep going" again): tables, sources and the ANC pass-through.**
- **Stage A (2327679, label-only):** the main timing cranking map (e2m 8091-8093), the ambient humidity table (1A98-1A9A)
  and the altitude cache, from the parameter ID table.
- **Stage B (e3bc815, types):** `SENSOR_VALUE_SOURCE` on the eleven words whose e2m records share the PRIMARY / BACKUP /
  DEFAULT list, and the humidity cache as `word[2]`.
- **Stage C (75d8c34, label-only):** the compiled-out ANC stage's pass-through into the combustion limits input.
- **Stage D (label-only, after the review):** the pilot timing / pilot quantity / rail pressure cranking maps and words,
  from their e2m records (were `*_cold_start_*`).

**Round 20 (the relayed "keep going" again): the algorithm enable flags block.**
- **Stage A (7117c24, label-only):** the 17 guessed flag words named by their e2m 106B word numbers
  (`algorithm_enable_flags_<N>_cal`; word 3 was `j1939_governor_feature_cal`).
- **Stage B (516e3be, types):** `algorithm_enable_flags_3_t`, the cruise / road speed governor / PTO enables.
- **Stage C (9c46007, label-only):** `cold_delta_fuel` (e2m 8A9F, was `fuel_demand_offset_correction`) and its table,
  the misfire timing limit function, the wave 11 structs' proven guessed bits, and rows for the length word and words
  7 / 8 / 11 / 26.
- **Stage D (797ec46, types):** 17 more flag words as bitfields: 117 bits named from a matching reader, 50 from a
  single record (each abbreviation expanded by its description, a sibling record or the repo's vocabulary), 105
  reserved. Plus the cold delta fuel cache.
- **Stage E (32df48c, label-only):** the cold delta fuel cache initializer.
- **Stage F (16f967b, after the advisor's review):** word 11 as `algorithm_enable_flags_11_t` (the J1939 / J1587 /
  J1922 / proprietary communication enables), its dump value corrected to 0x000b (J1939 communication is enabled),
  and word 19 bit 7's comment.

**Round 21 (the relayed "keep going" again): the engine protection module.**
- **Stage A (75178dc, types):** the three per-channel records (e2m 112E / 1152 / 1143) as structs, and full prototypes
  for the helpers that take them.
- **Stage B (756f2e0, types):** the fault log entry and the two EEPROM logs, the fault-log loop's current-channel
  pointers, and stage A's five `i16` fields corrected to `short`.
- **Stage C (093c501, label-only):** the module's 11 functions and 9 working words, from the typed bodies.
- **Stage D (cc49e74, tooling):** `ApplyStructures.java` maps `i16` / `sword` and warns on an unknown field type
  (a scratch positive control confirmed both).
- **Stage E (f6cecc2, types, review):** the engine protection thresholds are `short` / `short*`: every load is `lha`.

**Round 22 (the relayed "keep going" again): the engine protection leftovers.**
- **Stage A (14be183, label-only):** the module's boot / restart resets, the shutdown override detector's words, the
  fault derate's J1939 torque curve adjustment (PGN 65251), two new rows, and the configuration flags documented.
- **Stage B (eb3bc7e, label-only, review):** the two helpers it had only seen as calls, the second derate cache by the cache rule, and two comments corrected.

**Round 23 (the relayed "keep going" again): the ambient module and the source enum.**
- **Stage A (0787531, label-only):** the ambient conditions module's filters, coefficients, tables, caches and
  initializer (e2m 1977 / 197A-197D / 1A0E), and the PGN 65269 payload's five fields.
- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more source words (each e2m value list against the code's
  literals).
- **Stage C (bc99794, types, review):** three more (an `i16` global and two struct fields), the scan widened to every
  type and struct field (none left), and a stale `DAT_` label refreshed.
**Round 24 (the relayed "keep going" again): struct instances still named after their Ghidra labels.**
- **Stage A (1d84f6c, comments):** 73 present-tense Ghidra labels in CSV comments refreshed (round 23's lead).
- **Stage B (8de3cf6, label-only):** the commanded throttle record (e2m 1047 / 1048), the remote and dual channel
  pedals, the DTC code lookup.
- **Stage C (44578ee, label-only):** the cam / crank sync record (e2m 819C) and its state setters.
- **Stage D (26dd083, label-only):** the J1587 fault counts, the boot SCI / reflash / J1939 transport sessions,
  two more instances.
- **Stage E (a735961, types):** the three 50-word fault bit arrays (e2m 1036) as one `fault_bit_words_t` with three
  `_cal` instances; every bit's e2m name and DTC in the field comments.
- **Stage F (9ed041a, types):** sensor channels 1-4 flat like their neighbours; the throttle dword split.
- Open after round 24: named fault bits (the user's call), `diag_clear_flags_t`, the executive timing records,
  the sensor channel blocks, the TouCAN A register map, the kernel's response messages (task 046).
**Round 25 (the relayed "keep going" again): an enum and three shapes from the round 24 leads.**
- **Stage A (91a9b02, types):** `TRANSMISSION_SELECTED_GEAR` (J1939 SPN 524) on the four gear words; the junk
  `PROTECTION_OVERRIDE` enum gone.
- **Stage B (930aac0, types):** the TouCAN A register map at its real base (`toucan_a`, `toucan_a_message_buffers`).
- **Stage C (438b543, types):** the executive frame timing records (e2m 12A6) and their typed walking pointers.
- **Stage D (170236d, types):** the boot kernel's two diagnostic response messages.
- Open after round 25: the sensor channel blocks, TouCAN B's base, the kernel transport's message parameter,
  named fault bits (the user's call), `diag_clear_flags_t` (task 046).
**Round 26 (the peer session's cruise review of 69d6f68).**
- **Stage A (51ba84a, label-only):** the cruise vacuum throttle actuator named from e2m 8C2E / 8C2F (30 words, the
  learn check, the previous-pass flag); the vehicle speed path's mode-4 behaviour recorded in task 046.
**Round 27 (the user approved the named fault bits and the CLAUDE.md J1939 note).**
- **Stage A (084a1cc, label-only):** the sensor channel layer. The inverted periodic / boot names are fixed (four base
  functions signed / unsigned, 63 wrappers process / initialize), and 91 blocks are named by channel from e2m. Finding:
  disabled channel 88 (exhaust throttle) writes the fuel temperature outputs.
- **Stage C (04b419e, label-only + firmware/CLAUDE.md):** the J1939 descriptor's third field is the logical switch
  (brake 11 / clutch 15 / PTO 3 / remote PTO 19 / interlock 26 / cruise and the rest 31); the CLAUDE.md mechanism text
  is corrected.
- **Stage B (2eb75f6, types):** one bitfield per fault in `fault_bit_words_t` words 1-49 (301 e2m names, the rest
  `fault_<n>`). 780 bit-name references (656 tests, 108 writes, 16 other); 943 piece tokens, 856 of them on
  set / clear writes.
**Round 28 (the round 25-27 leads).**
- **Stage A (0ec3474, label-only):** three sensor-present flags named from e2m: the absolute boost sensor flag read
  backwards, plus the barometric sensor and the two-speed axle switch. The boot kernel's copy of the CAN transmit
  mailbox writer (the old "Can2" was not a second controller). The boot CAN ring state struct and its fields.
- **Stage B (c65bdd0, types):** the ring's two full flags split out of `_pad16`; full prototypes for the mailbox
  writers, so two calls that hid their frame argument show it.
**Round 29.**
- **Stage A (f13aca5, label-only):** the transfer case low-range detector named from e2m 8C5F / 8C60 (was the
  `engine_to_vehicle_speed_ratio_*` monitor: the low-range flag read as a "high ratio" flag, the launch flag as
  "invalid"). Nine `fault_<n>` bits named from the code that sets them.
**Round 30.**
- **Stage A (82b5069, label-only):** the watchdog fueling monitor (fault 388) and its words named from e2m 8A70 /
  8B3B / 8B3D; it was `fuel_quantity_demand_monitor` with five `DAT_` words.
**Round 31.**
- **Stage A (8146833, types):** the J1939 EC1 (PGN 65251) payload and its previous copy as one 28-byte struct with
  the SPN fields; the send-on-change test now reads by field.
**Round 32.**
- **Stage A (cad1457, labels and types):** the discrete output read-back checks. The check, its monitor and
  initializer are named, the four counters are a struct with 11 instances, each output has a retry word, and faults
  146 / 147 are the cruise servo supply's. These were 55 `DAT_` labels.
**Round 33.**
- **Stage A (3c495a2, labels):** the J1939 transmit descriptor's third field is the status pointer (was
  `data_end_pointer`): the send result or the broadcast / RTS-CTS session code, 0x1x while a session runs.
  30 status bytes are named (31 with stage B's 65259), the ACK descriptor is `j1939_pgn59392_tx_message`, and five
  stale rows inside it are fixed.
- **Stage B (20a26d2, types):** the RC (PGN 65249), CI (PGN 65259) and SOFT (PGN 65242) payloads as structs, and
  the decimal text formatter's prototype. RC byte 1 decodes as exhaust brake (one driver) or compression release
  brake (two or more).
**Round 34.**
- **Stage A (67955cf, labels):** the transport's send / service / initialize functions and the PGN 65535 delay
  flag named from the code.
- **Stage B (91993f0, types):** the two broadcast transmit session records as a struct array (were
  `j1939_tp_rx_session_*` / DAT_).
- **Stage C (44f4c9e, types):** the RTS / CTS transmit session as the boot twin's type, that type's pointers as
  `byte*`, and the prototypes of `initiateJ1939TransportProtocol` / `mpc555_sendJ1939SingleFrame`.
**Round 35.**
- **Stage A (fb9cccd, labels):** the boot kernel's transmit session flag / destination (were QADC names).
- **Stage B (ff9e247, types):** the J1939 transport receive session as one type with boot and application
  instances (were `j1939_tp_pause_t` / `qadc_a_*` / `j1939_multiframe_rx_*`); both `_pad2` fields named.
- **Stage C (68c58e4, prototypes):** the boot record senders, the boot queue push and the diagnostic service chain.
**Round 36.**
- **Stage A (29f28c8, types):** the EFL/P1 (PGN 65263) and PGN 65504 payloads as structs (SPN 101 crankcase
  pressure was `j1939_diag_response_word_b`; PGN 65504 carries a time-base-scrambled injection timing).
- **Stage B (c7d1515, prototypes):** the boot diagnostic request path. The dispatcher's old rows printed a fake
  service code 0x2d (the low byte of the receive session's message view).
**Round 37.**
- **Stage A (4775962, labels, types):** 120 lookup cache words named from their own lookups
  (`<table>_cached_axis_offset(s)`); 0x3fd134 was named for the wrong table.
**Round 38.**
- **Stage A (0333c10, labels, types):** the named lookup cache rows audited against their own lookups: 34
  2-D caches widened to `word[2]` (15 y halves merged) and 24 misnamed caches renamed after their tables.
**Round 39.**
- **Stage A (912c379, labels, types):** the 24 lookup tables named `_cal` outside the EEPROM mirror, renamed after
  their lookups (the turbocharger corrected speed map, e2m MT_Max_Torque_Map, ...), and 11 caches.
- **Stage B (e8faa64, labels, a type):** stage A checked against the ECU's parameter ID table: four e2m renames (CBD
  stop compensation, crank / cam based next cylinder, the cam tooth window) and the cam window cache split from a
  dword.
- **Stage C (2aa86ed, labels, types):** the last 42 HARD `_cal` scalars renamed from their code (11 with e2m records);
  the J1939-named supervisor chip block re-domained. `audit_cal_suffixes.py` HARD 63 -> 0.
**Round 40.**
- **Stage A (7f54db1, labels):** 24 application-side names in the EEPROM mirror gain `_cal`; 9 of them (plus
  `engine_idling_flag`) renamed from their e2m records and code (the idle counters, the feature bitmap, the exhaust
  brake switch learned flag, ...).
- **Stage B (9c5414a, a type):** `feature_selection_bits_cal` as a bitfield struct; the SCI setting lookup's pointer
  typed `byte *`.
**Round 41.**
- **Stage A (ea2bacd, types, labels):** the injector driver booster capacitor monitor (was
  cm848_processFaultScanLookup): its two ROM record tables typed as struct arrays, its RAM counts as arrays, the
  low voltage mask and the initializer named.
**Round 42.**
- **Stage A (34f1e78, a type):** the per-fault-slot status records (`fault_status_records_cal`, a 3-byte struct; was
  two overlapping rows).
- **Stage B (e3b6532, labels):** the engine retarder driver cylinder counts and the cylinders-on count from e2m 13D8 /
  13D9; the retarder torque lookup's live-in table pointer named.
**Round 43.**
- **Stage A (d8d2cdf, labels, types):** the main injection end of injection timing (was
  cm848_computeFuelRpmCompensatedOffset): the function, its output and its calibrations.
- **Stage B (ef9781b, rows):** 30 junk `<name>+<N>` rows removed (the build changes only local declaration order).
- **Stage C (d0bd88c, labels):** the block named by e2m 8B47 / 8B48 (EOI_Default / _Hydraulic_Delay / _Max_Limit /
  _Min_Limit, EOI); the addend is the hydraulic delay.
**Round 44.**
- **Stage A (a0c4d30, labels, a type):** round 39's three unverified rows named from their code (the vacuum cruise
  fueling reduction, the cruise accelerator override threshold, the single-channel pedal idle threshold minimum),
  the last typed junk row (the previous-pass cruise engaged flag) and a documentation row for e2m
  Cruise_Out_Of_Gear_Disable.
- **Stage B (379b0d0, labels, rows):** 14 e2m blocks past the dumped parameter ID table (11 fill five gaps between dumped-table
  blocks exactly, 8B50 / 8BAE match field by field, 8B59 by meaning). Stage A's
  rows get their e2m names (Vac_Throttle_ASG_Delta, Cruise_Throttle_Transition_Threshold,
  PPS_Test_Cell_Threshold_Auto_Zero). The oil change monitor's third accumulator is the oil soot percentage (e2m
  OCM_Soot_Percentage_*). 33 rows gain citations.
- **Stage C (6aefe56, labels):** the pedal learning's "total step" limit and counter are a time limit and its timer (e2m
  PPS_AZ_Time_Limit); the PPS block is inactive in this calibration (Accelerator_Position_Sensor_Type = 0, TPS).
**Round 45.**
- **Stage A (ee5d688, labels, rows):** a sweep of the gaps between dumped parameter ID table blocks. It places six
  more e2m blocks: the injector debounce limits, the fuel level and fuel pressure rationality tests, the P0500
  vehicle speed sensor monitor, the oil pressure gauge and low oil switch (2 new rows, 2 named), and the DM13
  state. One rename.
- **Skill (the user's request):** `auditing-cal-suffixes` says HARD 0 since round 39 (was "~1352"), and its region
  table matches `audit_cal_suffixes.py`. The round 27 section in `firmware/CLAUDE.md` stays as it is.
**Round 46.**
- **Stage A (e83a3ce, labels):** the warning chime (e2m 8B2D: `warning_chime_*`, was `engine_warning_alert_*`), the oil
  pressure gauge state (8A7F; `low_oil_pressure_chime_flag`, was `…_derate_flag`) and the TSC1-lost backup
  powertrain protection flag (8A7C; `tsc1_lost_management_active_flag`, was `fuel_demand_timing_enable_flag`).
- **Stage B (3109998, labels, a row, functions):** the `park_neutral_exit_*` family is rock cycle torque management
  (e2m 8C2A TC_Rock_Cycle_* / 8C49-8C4B RE_RCTM_*). It becomes `rock_cycle_*`: 20 globals, 3 functions, 1 new row.

## Test plan

- [x] `./analyze.sh build` passes at every stage. The warnings are unchanged, except the three stale-prototype warnings
  that stages 4 and 6 remove.
- [x] Stages 1, 3, 5 and 7: the label-only proof is EQUIVALENT.
- [x] Stage 8: the cast-normalized proof leaves 6 differing functions, all cosmetic.
- [x] Stage 2 changed only the intended functions. Stage 4 changed only the functions predicted before its build (the
  two readers of `pumping_torque_adjustment` needed no cast, so they did not change). Apart from those, only
  declaration orders changed, and the piece count stays 508 → 508.
- [x] Rounds 2 and 3 (stages 3, 5 and 7):
  - no new name shadows a parameter or a local;
  - CM550 and the cross-firmware maps cite none of the old names;
  - every renamed row's width matches its e2m record (the only hits are struct instances).
- [x] Stage 8: every new `(ushort)` / `(uint)` cast on a retyped word was checked against its instruction. All 10 sit
  on `lha` loads whose value the code then shifts logically, so none needed a revert.
- [x] Round 4:
  - stages 10 / 10 follow-ups 1 / 2 are label-only (EQUIVALENT);
  - stage 10c's twelve changed functions were read diff by diff (the proof tool's own list missed the piece-only ones);
  - the apply gate checked bin coverage, old = current, name free as a global / function / field / parameter /
    local / enum / `.cpp` identifier, `_cal` = EEPROM mirror, banned abbreviations, CM550 sharing and the quoted line;
  - the quoted dump values match: 17 flags, all regex hits on scaled values, against 92 for the negative control; the
    hand stages' values (0x40a040 = 4200 rpm, the four injector driver levels 32.2 V / 80.2 V / 13.5 A / 18.5 A) were
    read from the dump at their declared widths;
  - the widths match the e2m records after 10c;
  - no stale references remain (`stale_refs_W15.py`, the comment-name sweep). A repo-wide grep of the old names
    leaves only history, CM550's unrelated `governor_integral_accumulator` and the stale generated snapshots; the
    lead lists of tasks 025 / 027 / 029 / 042 / 045 each got a "resolved by PR #53 round 4" section.
- [x] Round 5:
  - the label-only stages are EQUIVALENT, and the comment-stripped diff finds 0 changed functions;
  - the shared EC1 rename was built and proved on CM550 too;
  - the two type stages were read diff by diff: 5 functions with the intended render plus 3 changed only in local
    declaration order, and 7 functions with the enum render;
  - three facts were checked against their sources:
    - the TSC1 index is SPN 696 (the J1939 database and the receive handler), not 695 as a comment said;
    - the EC1 builder stores points 1-5 at payload +0 / +3 / +6 / +9 / +12, as J1939-71 lays them out;
    - the struct's `short` fields match the e2m S records and 8 of the 10 integral gain loads (`lha`). The compensator's
      two `lhz` loads (0xffec / 0xfff0) render as `(ushort)` casts, so 0dea32e's "lha" note is wrong for those two;
  - the closing checks on the 86-row round 5 map: the repo-wide old-name grep (live references fixed, resolved-name
    sections in tasks 022 / 025 / 027 / 042 / 045), the comment sweep and the e2m width check.
- [x] Round 6:
  - stage 0's diff is only the underscore renders (0 lines after normalizing the two names);
  - stages A and B1 are EQUIVALENT on both firmwares (stage A maps one auto-named local, `peVar1` -> `ptVar1`, that
    follows the type rename);
  - every B2 change was read diff by diff (31 functions: the enum renders, the dropped casts, the typed table and
    ETC2 words, and declaration order in three);
  - the facts were quoted from the instructions (`lha` / `lhz` / `sth` with addresses) and from e2m 10E6 / 10E7 /
    10E8.
- [x] Round 6 closing: the arbitration prose is fixed by branch, and "Bank 2" for 0x5c38c / 0x5c3b4 is
  corrected to ROM. The two unused enums that contradicted e2m are deleted, proved a no-op (comments only,
  0 functions).
- [x] Round 7:
  - stages A and C are EQUIVALENT;
  - stage B was read diff by diff: the struct field renders, the enum renders and declaration order;
  - the session functions' `int32_t` parameter was found because the first 7a build rendered `int` as
    `dword`.
- [x] Round 8:
  - stages A, B, E, F and G are EQUIVALENT: no function differs, except two in stage F, each of which declares one
    local in another place;
  - the width check: every aligned 8BBC / 8C17 / 8C18 / 8C53 record has a row of its size (two unused words have
    none);
  - stage C was read diff by diff;
  - each aligned e2m record's description was read against its row's users (`align_block.py`), and each block
    stops where it drifts.
- [x] Round 9:
  - stages A, B, D and F are label-only (EQUIVALENT; for D, the 3-byte array split normalized back to
    `flags[0..2]` gives 0 differences);
  - stage C passes `check_enum_proof2.py`, and its one other change is the ring array;
  - the table walk matches 118 existing rows by size and address (88 + 30), and each table's users agree with its
    record.
- [x] Round 10:
  - stages A, C and E are label-only (EQUIVALENT);
  - stage B passes `cast_normalized_diff.py` (each remaining difference is the lag table index, a grid cache's
    `[0] / [1]` or a byte literal);
  - stage D passes `check_enum_proof2.py`;
  - stage F passes `relabel_struct.py` + `cast_normalized_diff.py` (the `_` prefix, three signatures, one cast);
  - the SCI test names come from the DRB database, and output 16 is proved twice (its fault pair and DRB test
    13-43).
- [x] Round 11:
  - stages A and D are label-only (EQUIVALENT);
  - stage B passes `bitfield_normalize.py` + `cast_normalized_diff.py` (two differences, both the same values);
  - stage C passes `switch_normalize2.py` + `cast_normalized_diff.py` (one: the same address);
  - the `._N_1_` piece count is unchanged (183).
- [x] Round 12:
  - stage A passes `array_normalize.py` + `cast_normalized_diff.py` (two differences, the same addresses);
  - stage B is label-only (EQUIVALENT);
  - `lookup_tables.py` reports 0 sizing problems.
- [x] Round 13:
  - stages A and C are label-only (stage A: one function's local declarations reorder, sorted lines identical;
    stage C EQUIVALENT);
  - stage B passes `check_enum_proof3.py` (0 functions differ beyond the enum substitutions);
  - stage D (comments) is EQUIVALENT;
- [x] Round 46: stage A `prove_caches.py` matches all 1968 functions; verify byte-identical. Stage B `prove_caches.py` against a copy of the old `.cpp` with the three function names changed matches all 1968 functions; verify byte-identical.
- [x] Round 45: `prove_caches.py` matches 1967 of 1968 functions (the other differs only in the order of its local declarations); verify byte-identical.
- [x] Round 44 stage C: `prove_caches.py` matches all 1968 functions; verify byte-identical.
- [x] Round 44 stage B: `prove_caches.py` matches 1967 of 1968 functions; `mpc555_tickTransferTimeoutAndRuntimeCounter` differs only in the order of its local declarations, and the 6 `oil_change_monitor_soot_percentage_cal._0_1_` pieces are the boot ROM's existing byte view of the time-shared 0x3fee3e.
- [x] Round 44: label-only proof matches all 1968 functions (the `undefined2` -> `word` retype changes nothing); a raw lis + displacement scan of both images finds exactly the accesses the `.cpp` shows.
- [x] Round 43: the end timing function has 0 differing statements; removing the junk rows changes only the order of local declarations.
- [x] Round 42: all 24 status record users match field by field (index set-up dropped; one pair is the same address in two forms); the retarder function has 0 differing statements; the other functions match the canonical form.
- [x] Round 41: the monitor's 112 statements match field by field (prove_records.py: field identity and statement structure; the indexes are dropped); the other functions match the canonical form or differ in local declaration order only; widths asm-verified.
- [x] Round 40: every function matches the canonical form or has 0 differing statements (bitfield tests rewritten to their masks); 15 / 15 resolved addresses checked; MISSING 258 -> 234.
- [x] Round 39: every function matches the canonical form or has 0 differing statements; `audit_cal_suffixes.py` HARD 63 -> 0, SOFT 4 -> 0; e2m sizes agree; RAM 0x3feed0-0x40a048 = ROM + 0x39a3e6 (all 22717 words).
- [x] Round 38: all 1968 functions match the canonical form.
- [x] Round 37: every function matches the canonical form apart from one declaration reorder and one
  `WORD_` render of the same cache.
- [x] Round 36: stages A / B are token-equal apart from the 2 / 9 hand-read functions and one declaration
  reorder.
- [x] Round 35: stage A is EQUIVALENT; stages B / C are token-equal apart from declaration reorders and 8 / 16
  hand-read functions.
- [x] Round 34: stage A is EQUIVALENT; stages B / C are token-equal apart from declaration reorders and 4 / 18
  hand-read functions.
- [x] Round 33: stage A is EQUIVALENT (with the field rename applied forward and one derived `PTR_` row);
  stage B matches token for token apart from 2 declaration reorders and 5 hand-read functions.
- [x] Round 32: stage A matches token for token apart from the check's parameter names (verified) and one
  declaration reorder.
- [x] Round 31: stage A changes only the two EC1 functions, each access checked.
- [x] Round 30: stage A is EQUIVALENT.
- [x] Round 29: stage A is EQUIVALENT.
- [x] Round 28: stage A is EQUIVALENT; stage B's 9 differing functions match statement by statement apart from the
  frame argument.
- [x] Round 27: stages A and C are EQUIVALENT; stage B passes the mask-exact proof (1964 functions identical, 4
  structural differences read by hand).
- [x] Round 26: stage A is EQUIVALENT.
- [x] Round 25: stage A passes the enum proof (0 differences beyond the substitution); stages B, C and D pass the
  token gate with only the intended functions changed (B: one same-address temporary, C: `main_loop`'s typed
  pointers, D: the allocator's typed return); pieces 492 -> 480.
- [x] Round 24: stages B, C and D are EQUIVALENT; stage A (comments) leaves the code without comments identical;
  stages E and F pass an address-token normalization (0 functions differ; pieces 500 -> 500 -> 492).
- [x] Round 23: stage A is EQUIVALENT (20 names); stages B and C pass the enum proof (C differs only in a refreshed plate).
- [x] Round 22: stages A and B are EQUIVALENT (12 and 3 names).
- [x] Round 21: stages A and B pass a layout / containment / artifact gate (A was piloted first); stage C is EQUIVALENT; stage D builds CM550 and CM848 identical before and after, and its positive control shows both new paths; stage E's gate passes (the five readers, no casts left).
- [x] Round 20: stages A, C and E are EQUIVALENT; stages B, D and F pass the mask normalizer (the count gate: per word and mask, old masked reads = new field reads; pieces 464 -> 464).
- [x] Round 19: stages A, C and D are EQUIVALENT; stage B's enum proof shows only the substitutions (plus the cache's two users).
- [x] Round 18: stages B and D are EQUIVALENT; stage A's cast-normalized diff and stage C's diff show only the intended effects.
- [x] Round 17: stage A is EQUIVALENT (30 names); stage B's enum proof shows 0 functions differing beyond the substitutions; stage C's type diff is reviewed with a mask normalizer.
- [x] Round 16: stage A is EQUIVALENT (109 names); B and C are type diffs reviewed function by function (C with a mask-normalized cast diff); every renamed row's width matches its e2m size.
- [x] Round 15: stages A and B are EQUIVALENT; every renamed row's width matches its e2m size.
- [x] Round 14: stages A and C are EQUIVALENT (C with the split words mapped back to the old pieces); stage B
  passes `check_enum_proof3.py`.
  - the thunk stage still makes 19 thunks and 13 call overrides.
- [x] `./analyze.sh verify`: the two builds are byte-identical.
- [x] `lookup_tables.py` is clean (920 / 920 typed).
- [x] `test_lookup_tables.py`, `test_disasm_tools.py`, `test_e2m_block_addresses.py` and `test_rename_waves.py` pass.
- [x] The headers are regenerated (CM550's change only in round 5, for the shared EC1 function), and
  `g++ -fsyntax-only` is clean for both firmwares.

## Still open (task 046)

- **What 0x128a0 still shows:** it rates Readability Medium. One `uVar1` (the reused register's later values) remains.
- **The engine speed module's functions** have mixed prefixes: `hpcr_processEngineSyncPulses`,
  `mpc555_handleCamSignalInterrupt`, `mpc555_updateEngineRunState` and the run state handlers.
- **The signedness sweep's remainder:** 35 rows with an `lhz` load and 104 with no load.
- **Open after round 5:**
  - the rest of the 48RE controller: blocks 8C55 / 8C49, the 2-3 shift lag table under the boot kernel's rows, and
    8BBB's tail. Round 10 resolved the flag bits, the lookup caches, the 1-2 shift lag table and the 8C34 / 8C56
    monitor words;
  - the engine speed module's run-state machine (no e2m value list, so it needs a read);
  - the 48RE governor pressure functions 0x3257c / 0x3241c (their block 8D14 drifts);
  - the fault derate scheduler words and the 11D5 air fuel control rows;
  - the TPU injection bytes and the A/C class-B coolant flags.
  The full list is in task 046.
- **Open after round 23:**
  - the droop word at 0x40aedc and the task 046 leads;
  - the fault status records (a packed record array, but the range is time-shared RAM);
  - e2m 8C80 (TVA) / 8C2D;
  - the SCI high-speed table words;
  - `calculateAlpha`'s r4 alias (a calling convention question) and the PGN 65269 ambient temperature bytes;
  Round 11 resolved the output bitfields and the lift pump control; round 12 the cam_sync fuel metering tables and the setpoint caches; round 13 the end-of-line test sequencer; round 14 the low speed governor reference speed chain; round 16 the switch bytes 0 / 1 / 3 bitfields (the user approved them); round 20 the algorithm enable flags block; round 21 the engine protection records and fault logs.
- **The e2m pool above 0.2 overlap** (123 rows at ≤ 0.25, 140 at ≤ 0.34, 220 at ≤ 0.5): a next wave if wanted.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
