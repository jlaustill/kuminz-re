# 046 — CM848D: the EGR transport delay stage and the e2m 177F EGR flow estimate

## Problem Statement

On 2026-11-20 the user asked whether `cm848_throttleBasedFuelCalculation` (0x128a0) is named properly. It is not.
The function computes nothing about the throttle or fueling. It is the EGR transport delay stage of the CHP charge
flow model. CHP is the e2m prefix of the charge, EGR and fresh air flow records; the e2m never spells it out, so names
here avoid guessing an expansion. Wave 14 (task 045) had already flagged the function: "reads as the charge flow /
EGR fraction model, but I have no proved name". The ECU's own parameter ID table (found 2026-11-19) now proves the
name: it resolves every word the function writes to e2m block 177F. On the same day the user asked for the rest of
the family as well (stages 3 / 4 below).

## Evidence

- **e2m block 177F → `throttle_fuel_trim_t` @ 0x40a3ea, one to one** (`firmware/scripts/e2m_block_addresses.py 177F`):
  +0 CHP_O2_Frac_EGR, +2 EGR_Fraction, +4 CHP_EGR_Flow_Before_Delay, +6 CHP_EGR_Flow_Delay, +8 CHP_Downstream_EGR_Flow,
  +A CHP_Upstream_EGR_Flow, +C CHP_Downstream_Corrected_Flow, +E CHP_Downstream_Pratio, +10 CHP_Sqrt_Texhaust_R,
  +12 CHP_Upstream_Corrected_Flow, +14 CHP_O2_Flow_Delay, +16 CHP_Sqrt_Torifice_R, and +18 EGR_Flow_Source (the flat
  word 0x40a402, `engine_fuel_fault_status`). Every field was checked against the code that writes it: the
  upstream / downstream model bodies, `cm848_calculateEgrMassFlowBeforeDelay` and 0x128a0.
- **The code (0x128a0, every 10 ms):** phase group A runs in the 20 even phases of the 40-phase, 5 ms main loop.
  - CHP_O2_Flow_Delay = C_CHP_Volume_Fraction x 120 x 1000 / (volumetric efficiency x engine speed). That is the time
    the engine takes to breathe that fraction of its displacement, in ms. The e2m scale is 0.001 s, which matches the
    x 1000.
  - The delay / 10 is the delay in 10 ms samples. The residual oxygen fraction is delayed by it through a 256-sample
    ring, then filtered into CHP_O2_Frac_EGR.
  - CHP_EGR_Flow_Delay = the oxygen delay x C_CHP_EGR_Flow_Delay_Fraction / 32767. The EGR mass flow before delay is
    delayed by it, then filtered into `egr_mass_flow_delayed_filtered`.
  - EGR_Fraction = the delayed EGR flow x 8192 / the charge flow, capped at 1.0. It is 0 while the charge flow is
    0.5 lb/min or less.
- **The RAM dump (key on, engine stopped):**
  - The oxygen delay reads 40959. That is 0xffff x 1000 / 1600: the fraction (9552 > 8192) takes the 0xffff branch,
    and volumetric efficiency x speed sits at its 1600-count floor.
  - The oxygen fraction reads 8192 (1.0), and every delayed oxygen sample is 8192.
  - EGR_Flow_Source reads 1 (backup).
- **Widths (asm):** every 177F access is a halfword, for example `sth r5,0(r31)` @ 0x12944 (+14) and `lha r4,-23570(r4)`
  @ 0x129bc (+4). The function takes no arguments: r3-r10 are written before any read.
- **The signedness comes from the e2m `S` column:**
  - Signed: +4 / +8 / +A / +C / +E / +12, and C_CHP_EGR_Flow_Max / _Min (both `lha` in
    `cm848_calculateEgrMassFlowBeforeDelay`).
  - Unsigned: +0 / +2 / +6 / +10 / +14 / +16 / +18.
- **The delay lines:** `cm848_circularBufferWriteUnsigned` / `Signed` (0x123dc / 0x12404, called only from 0x128a0) store
  the sample at the byte index at +0x200 (`lbz` / `stb 512(r6)`) of a 256-word ring (`sthx`). Each advances its index
  and returns the word `delay` calls back (`(index - delay) * 2 & 0x1fe`; `lhzx` / `lhax`). The two lines sit at
  0x3fa1b6 and 0x3fa3b8 with a 0x202-byte stride, and the filter records follow at 0x3fa5ba.
- **Cross-firmware:** CM550 J90350.00 has no EGR model. Its `circularBufferWrite` (0x16cd8) is an EEPROM block writer
  and `circularBufferWriteWithStatus` (0x1355e) the data-collector ring, so the names share nothing with CM550.

## Done (branch `cm848/egr-flow-delay-model`)

- **Stage 1 (label-only; `reverse_names.py` EQUIVALENT, 0 functions differ):**
  - `cm848_calculateDelayedEgrFlowAndFraction` (was `cm848_throttleBasedFuelCalculation`);
  - `cm848_delayUnsignedSample` / `cm848_delaySignedSample` (were `cm848_circularBufferWriteUnsigned` / `Signed`);
  - `egr_flow_estimate_terms_t` / `egr_flow_estimate_terms` (were `throttle_fuel_trim_t` /
    `throttle_fuel_trim_t_0040a3ea`), with its 12 fields named from 177F;
  - `egr_flow_source` (was `engine_fuel_fault_status`) and `egr_oxygen_fraction_filter` (was `throttle_filter_state`; `egr_oxygen_fraction_filter_state` since stage 3;
    it shares C_CHP_EGR_Flow_Fil_Cnst with `egr_mass_flow_delayed_filter`).
- **Stage 2 (shape):**
  - `delay_line_t` (`samples` word[256], `write_index`, `spare`) with the instances `egr_oxygen_fraction_delay_line` /
    `egr_mass_flow_delay_line`, plus full prototypes for the two helpers.
  - The six signed 177F words became `short`, and the two EGR flow limits became `i16`.
  - The five locals of 0x128a0 are named.
  - Both delay lines cover boot-ROM call targets in the kernel's RAM image: 0x3fa2f0 (`cm848_runFlashProgramStateMachine`)
    and 0x3fa5a0 (`mpc555_cmfEraseBlocks`). The thunk stage now gives those calls call overrides ("(covering) kept";
    thunks 21 → 19, overrides 11 → 13), and the boot calls still render by name. The type-only byte row at 0x3fa5a0
    is removed.

## Done, the rest of the family (stages 3 / 4, 2026-11-20, same PR)

The scope rule: a symbol is in if its e2m record is `CHP_` / `C_CHP_`, or if it is an input that a family function
would otherwise misname.
- **Stage 3, label-only** (`reverse_names.py` EQUIVALENT; 49 names, all render):
  - **Functions:**
    - `cm848_calculateChargeFlows` (0x12e60, was `cm848_fuelControlMainCalculation`): the 10 ms task.
    - `cm848_initializeChargeFlows` (0x12e88, was `cm848_initFuelControlFilterSystem`): its boot initializer.
    - `cm848_calculateChargeFlowEstimate` (0x12dc4, was `cm848_fuelDemandWithLoadCompensation`): the Rankine
      temperature, volumetric efficiency, charge mass flow and Charge_Flow_Source.
    - `cm848_calculateFreshAirMassFlow` (0x12eb4, was `cm848_fuelDemandErrorCalculation`): e2m 177B, charge -
      delayed EGR, filtered.
    - `cm848_calculateDownstreamEgrFlowSource` / `cm848_calculateUpstreamEgrFlowSource` (0x12724 / 0x12778).
    - The four initializers: `cm848_initializeEgrFlowEstimate`, `cm848_initializeChargeMassFlowFilter`,
      `cm848_initializeFreshAirMassFlowFilter`, `cm848_initializePumpingTorqueLookupCache`.
  - **The exhaust pressure (e2m 1A5D / 1772):**
    - The functions are `cm848_calculateExhaustPressure` (0x509848, was `phase_group_a_validateEngineSync`; every
      10 ms) and `cm848_initializeExhaustPressure` (0x509a2c, was `cm848_initBoostPressureFaultHandling`; boot).
    - `exhaust_pressure` / `_source` / `_state` (were `boost_pressure_current_raw` / `fuel_demand_droop_state` /
      `boost_pressure_source_flags`).
    - `exhaust_pressure_estimate` / `_estimate_state` (were `boost_pressure_synthetic_ema` / `boost_correction_mode_flags`).
    - The new row `exhaust_pressure_estimate_as_primary_cal` (EEPROM 0x468). It is 1 on this truck, so the estimate is
      the primary exhaust pressure: the dump reads 1784 against an estimate of 1785.
  - **Tables:** the EGR model's 10 and the volumetric efficiency's 4, named from e2m 18E3-18E5 / 193D-193F / 1974-1975 /
    1946 + 1940 / 1782 / 1783 / 1961 / 1962. They had `boost_fuel_*` / `throttle_*` / `boost_rpm_scale_*` /
    `boost_load_*` names with a wrong `_cal`.
  - **Pumping torque (e2m 1780 / 1781 / 1954):** 8 words and the nominal engine delta pressure grid (were
    `fuel_demand_blend_*` / `fuel_demand_*_cal`).
  - **Filters and caches:**
    - `charge_mass_flow_filter_state`, plus `fresh_air_mass_flow_filter_state` with its 1A0F coefficient.
    - `egr_oxygen_fraction_filter_state`: an EMA record, so it takes `_filter_state`, the EMA-record convention.
    - Four 1-D lookup caches named `<table>_cached_axis_offset`.
- **Stage 4, shape:**
  - The three 2-D lookup caches are `word[2]` `<table>_cached_axis_offsets`. They were `diag_state_group5_a`..`_d` and
    `group7_a` / `_b`; each second word had no reader of its own.
  - `void(void)` prototypes for 0x12ad4, 0x12dc4 and 0x130dc. The asm writes r3 / r4 before any read, so their old
    two-parameter rows were stale.
  - `word` returns for the two source checks (`clrlwi r3,r4,16`).
  - `i16` for the pumping torque words that are e2m `S` and loaded with `lha`.

## Done, round 3 (stages 5-8, 2026-11-20, same PR; the user: "keep going, nothing is out of scope")

- **Stage 5, label-only** (EQUIVALENT; 57 names):
  - **TPE charge pressure estimate (e2m 1A22-1A29):** `cm848_estimateChargePressure` (was
    `cm848_calculateBoostTorqueOffset`). `charge_pressure_estimate` (was `boost_pressure_target`) = compressor inlet
    pressure x `compressor_pressure_ratio_estimate` (from the corrected turbocharger speed) x
    `compressor_pressure_ratio_scale` (from engine speed). Also renamed: its offset / tolerance / state words, the six
    tables, four new cache rows, the filter and the initializer.
  - **Charge pressure in range monitor (1A2D):** `cm848_calculateChargePressureInRangeEnable` /
    `cm848_monitorChargePressureInRange`.
  - **Exhaust pressure estimate (198C / 1772):** `cm848_estimateExhaustPressure` (was
    `cm848_phase_groupA_exponentialAverage`) with its constants and filter. The exhaust pressure sensor is channel 109
    (1966 +A): `exhaust_pressure_sensor_*`, plus a new row for slot 109 of `sensor_channel_filtered_output`.
  - **EGR delta pressures (1A19):** `egr_valve_delta_pressure` / `engine_delta_pressure` (were `egr_delta_pressure` /
    `egr_delta_pressure_negated`). `exhaust_pressure_offset` is 198C +0.
  - **Two source words:** `ambient_air_temperature_selected_source` (1A0C +2, beside +0 `ambient_air_temperature_selected`; round 4 renamed both `compressor_inlet_temperature_source` / `compressor_inlet_temperature`) and `barometric_pressure_selected_source`
    (1A11 +2).
  - **The rest:** the predicted IMT initializer, and the monitor bit `charge_pressure_estimate_enable`.
  - **A naming lesson:** a field named like a global (the first try was `charge_pressure_estimate`) breaks the
    label-only proof, whose global reversal also rewrites `.field`, and it confuses readers. Keep field names distinct.
- **Stage 6, shape:**
  - `i16` for eight e2m-signed `lha` words (the 198C offset and constants, the estimate offset, the three 1A19 delta
    pressures).
  - `void(void)` for 0x13294, which drops its stale-prototype warning.
- **Stage 7, label-only** (EQUIVALENT; 0 functions differ): the engine speed block e2m 819B.
  - `engine_rpm_state_t_0040b7ac.current_rpm` (356 lines) is `engine_speed_state.filtered_engine_speed`
    (Filtered_Engine_Speed).
  - `engine_rpm_measured` = `average_engine_speed`, `crank_derived_rpm` / `crank_tooth_rpm` = `main_engine_speed` /
    `backup_engine_speed`, and the EPS sums / counts between VSS pulses.
  - The cam / crank sync counters and the four start times.
  - Each record's code use fits its description, usually through a limit an earlier wave named.
- **Stage 8, the signedness sweep (shape):**
  - **The rule:** every named `word` row whose e2m record is signed 16-bit and whose every load is an `lha` becomes
    `i16`. `classify_signed_loads.py` found 444 such rows; 35 have an `lhz` load and 104 no load.
  - **Exceptions, kept `word`:**
    - 14 rows whose address is passed to a `word *` parameter: the sensor channel outputs and two duty limits. As
      `i16`, every call gained a `(word *)&` cast.
    - `variable_geometry_turbocharger_position`, which a shared pointer reads with `lhz`.
  - **Proof:** `cast_normalized_diff.py` compares the builds after removing casts, declarations and auto-names, and
    folding literals to 16 bits. Only cosmetic differences remain:
    - `(word *)` → `(sword *)` pointer casts;
    - one auto-name renumber;
    - `timer - 1` → `timer + -1` beside two removed casts.
  - **Also in stage 8:** `pulse_period_table_backup` is `dword[4]`, and `cylinder_acceleration` / `fuel_pressure_start_undershoot`
    are `i16`.

## Done, round 4: rename wave 15 (stages 10-10c, 2026-11-20, same PR; the user's go-ahead for the agent wave)

- **The wave (stage 10, 5f0f9d9):**
  - 378 rows: named rows that share at most 20 % of their words with the e2m record the ECU's own parameter table
    resolves to them, used in the code, dump in range, never reviewed. Six Sonnet agents, ~3.3M tokens.
  - Verdicts: 185 rename, 187 keep (each gets a `| e2m:` note), 5 drift, 1 uncertain.
  - The main session read every rename against its quoted line and changed a few by hand: the PGN 65249 point 5
    torque, Cruise_RSG_* stays `cruise_*`, the four LSG gain sets named as sets.
  - Plus the whole e2m 1170 "ASG application specific" record (25 rows), `cm848_selectAllSpeedGovernorApplicationMode`
    and `FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION`.
- **Follow-up 1 (8bdd341):**
  - The low speed governor family. The working P / I / D / jerk gains had crossed names. Also the 1064 / 1065 / 10EA /
    10EE / 10EF rows and nine functions.
  - The HSG compensator (were `cruise_speed_*`), the ASG 107D leftovers, the net torque fuel limit (8C68-8C6C).
  - **The compressor inlet vocabulary:**
    - The ECU's table names the channel 20 sensor Compressor_Inlet_Tmptr_Sensor, its selected value
      Compressor_Inlet_Tmptr and the density Compressor_Inlet_Density.
    - The ambient air temperature (1921 +6) is that temperature minus the inlet temperature rise.
    - So `ambient_air_temperature_selected` → `compressor_inlet_temperature`, `ambient_air_density` →
      `compressor_inlet_density`, `ambient_air_temperature_reference` → `ambient_air_temperature`.
- **Follow-up 2 (ea8a913):**
  - J1939: 0xfed200 is PGN 65234 = DM10 (DM11 is 65235), so the `dm11` names were wrong. The anti-theft status is PGN
    56320 (PDU1: 0xdc28 counted the destination). 56832 is Reset.
  - The A/C clutch control: 8A14 +4 says 0 = BR truck, 1 = DR truck, and this truck holds 1.
  - The injector driver: PWM 16-19 periods and levels, the booster capacitor channels 54 / 55.
  - The accelerator pedal faults, the engine protection shutdown counters.
  - The booster capacitor wrappers are named by when they run: the `_init` pair runs every pass, the `_process`
    pair once at boot (the known suffix inversion).
- **Stage 10c (types):**
  - `low_speed_governor_gain_set_t` (four i16) on the default / aggressive / middle gear / high gear / override /
    TSC1 sets, with the two gain set pointers typed.
  - The 0x3ffcaa and 0x3ff69c dwords split by their e2m records.
  - Byte rows for the supervisor chip pair and 0x409530, dword encryption seeds, i32 ASG QI / QP adjustments.
- **Thin evidence:**
  - 0x40a1cc / 0x40a1d4 (QI vs QP) rest on block alignment only.
  - 0x40a280 `programmable_power_active_selection` has only a zero store.
  - 0x40ae56 `diagnostic_fault_to_erase` (1080 +0) has only a zero store.
  - 0x3fdd7a `current_horsepower_peak_fueling_cal` rests on 117F's alignment and one multiply in the PTO governor
    PID.
  - `j1939_pgn56320_source_address` / `_destination_address` are named for the header bytes they fill. Which request
    bytes they come from (`param_1 + 2` / `+ 3`) is not traced.
  - **Function renames taken from the agents' reading, without a full read in the main session:**
    - `cm848_presetLowSpeedGovernorIntegrator` (0x27e4c; two bins agree);
    - `cm848_estimateChargeTemperature` / `cm848_initializeChargeTemperatureEstimate`;
    - `cm848_controlAirConditioningClutchForBrTruck` / `...ForDrTruck` (the dispatcher was read);
    - `cm848_initializePciMessageStatusBytes`, `cm848_monitorInjectionLimitViolationCounters`,
      `cm848_selectUserCommandedFueling`, `cm848_j1939HandlePgn56832Reset`;
    - `cm848_calculateAllSpeedGovernorEquivalentThrottle` (partly read).

    Read in full: the LSG functions, the ASG application selector, 0x17560, 0x5127d8, the A/C dispatcher, the wrapper
    callers.
- **Tooling found broken:** `apply_hand_worklist.py` looked the e2m records up from the wrong directory with a
  relative repo path. Follow-up 2 added the missing leading records to 90 comments.

## Done, round 5 (2026-11-21, same PR; the user: "keep going, nothing is out of scope")

Hand work on the wave 15 leads, each verified in the code (the scripts are in `session_folder/round5/`):
- **J1939 builders vs their PGNs (c1ebdc4):**
  - `j1939_header_pgns.py` lists the PGN every header builder encodes.
  - **Wrong names:** 65232 = DM8 (was "EngineControl"), 61441 = EBC1 (was "Etc1"), 65279 = the water in fuel indicator
    (was "SafetyStatus"), and 65251 = EC1. `initFaultTimerMessage` is renamed in CM550 too: it is a true twin, so the
    shared name stays shared.
  - **The EC1 "fault timer / fault counter" family** is the EC1 send-on-change test (J1939-71: resend on a 10 %
    change). The helpers are `cm848_hasWordChangedByTenPercent` / `cm848_hasByteChangedByTenPercent`, alongside the
    payload and its previous copy.
- **`all_speed_governor_gain_set_t` (0dea32e):** on the throttle-mode set (107B), the application set (1170) and the
  TSC1 table of four at 0x5c1d6 (one per requested speed control condition). The pointer is typed. Also
  `cm848_selectVariableSpeedGovernorMode` / `cm848_selectTsc1SpeedControlMode`.
- **`vehicle_speed_sensor_type_cal` (705f055):** 0x3fdda6 is e2m RSC_Sensor_Type, the vehicle speed sensor type
  (was `drivetrain_type`). `VEHICLE_SPEED_SENSOR_TYPE` runs NONE / INDUCTIVE / MINIGEN / TACHOGRAPH /
  J1939_WITH_GEAR_RATIO / J1939_WITHOUT_GEAR_RATIO, and the truck's EEPROM holds 1.
- **e13e2a2:**
  - `INTAKE_AIR_HEATER_PHASE` (e2m 8A35 +2), with the crank phase (was "run-up");
  - `fuel_demand_control_t.override_priority` and the two throttle override claimers;
  - the cruise maximum / minimum engine speeds;
  - the compressor outlet temperature is 1/32 °F.
- **06a42fe:** the cruise / vehicle speed limit governor's Bank 2 functions, the A/C clutch working words and the A/C
  initialization.
- **Stage f:** `cm848_initializeInjectionHardware`, `cm848_monitorFuelSystemHardwareShutdown` and
  `cm848_initializeLowSpeedGovernorGainSelection`.
- **Stage g:** `air_conditioning_condition_code_2` and `cruise_governor_preset_this_pass_flag`.
- **Round 5 thin evidence:**
  - Profiled with `writes_of.py` (what a function writes and calls), not read in full:
    `cm848_runCruiseAndVehicleSpeedLimitGovernor`, `cm848_monitorFuelSystemHardwareShutdown`,
    `cm848_initializeInjectionHardware` (its plate already described it).
  - `air_conditioning_condition_code_2` has no reader in the decompile.
  - The TSC1 gain set table has no e2m record (block 10B6 lists only +0..+4). Its size comes from the code:
    a 2-bit SPN 696 index, 18-byte sets, and the next row at 0x5c21e.
  - The struct's `short` fields follow the e2m S records and 8 of the 10 integral gain loads: `lha` at +4 / +6 in
    0xea00, 0xfb28, 0x10110 and 0x503074.
  - The compensator 0xff04 loads the two integral gains with `lhz` (0xffec / 0xfff0) and the three coefficients
    with `lha` (0xffdc / 0xffe0 / 0x1001c). Its two `(ushort)` casts are therefore faithful.
  - 0dea32e's message says the consumer loads every field with `lha`. That is wrong for those two loads.

## Done, round 6 (2026-11-21, same PR): the TSC1 / ETC1 vocabulary

The round 5 lead. Read in full: the TSC1 handler, the ETC1 handler, cm848_runTsc1LostManagement, the timer function, the
source lookup and the TSC1 dispatcher (scripts in `session_folder/round6/`).
- **Stage 0 (47d462a): two orphan struct definitions deleted.** `etc1_state_t` (0x40ae00) and `governor_control_t`
  (0x40adf4) both overlapped the live instance at 0x40adf8. `governor_control_t` still laid symbols over
  `j1939_governor_source_index` and the cached control byte (14 + 1 underscore renders in code, 7 overlap warnings); deleting
  it fixed them and nothing else changed.
- **Stage A: label-only, CM550 twin included.**
  - **The handler pair:** the dispatcher (now `cm848_dispatchTsc1ByDestinationAddress`) routes PGN 0 by destination
    address. `processEngineTsc1Request` (was `torqueControlModeHandler`, also CM550's 0x2f128) takes TSC1 for the
    engine, `cm848_processEngineRetarderTsc1Request` for the engine retarder.
  - **The structs:** `j1939_powertrain_control_state` (was `j1939_tsc1_override_state`, type
    `etc1_governor_state_t`), `j1939_powertrain_messages_received` (was `j1939_tsc1_received`: ETC1 + ETC2 + TSC1
    bytes) and `tsc1_source_configuration_table` (was `etc1_config_entry_t_0005c3b4`: 10 entries of data link,
    source address and the per-mode request timeouts / time limits, for the engine and the retarder).
  - **Fields that held something else:** `governor_mode` is the TSC1 override control mode (SPN 695);
    `etc1_speed_setpoint` the requested percent torque x 256; `etc1_torque_limit_value` the mode 3 speed limit;
    `etc1_active_state` the controlling data link (1 = J1939, else a timeout counts as a J1708 link fault);
    `torque_limit_mode_select` the high idle override (ETC1 SPN 606 with e2m Jcomm_High_Idle_Override_Speed);
    `etc1_spn1482_source_address` the TSC1 sender's address.
  - **The ETC1 timers** are named for the e2m 10E7 ("Jcomm") cals they load: out of gear, out of gear data,
    torque converter lockup, output shaft speed, progressive shift disable, and the high idle override time limit /
    timeout / recovery (`j1939_time_limited_node_recovery_time` = Jcomm_Recovery_Time, "time that time limited node
    must be silent before messages ...").
  - **Globals:** `cold_start_state_flag_a` / `_b` are the J1939 / J1708 link fault clear requests, and the
    `*_snapshot` / `*_prev` copies are the previous values of the fields they copy.
- **Thin evidence:**
  - `retarder_tsc1_mode_transition_timer` and `retarder_tsc1_speed_mode_flag` kept their old roles under a retarder
    prefix; the retarder handler was only skimmed. (Round 7 read it in full: they became
    `retarder_tsc1_zero_torque_request_timer` and `retarder_tsc1_speed_control_flag`.)
  - The source table has no e2m record; its field names come from the loads (+4 / +6 / +8 / +0xa / +0xc engine,
    +0xe / +0x10 / +0x12 retarder).
  - CM550's `cm550_diagnosticMessageValidator` / `cm550_diagnosticSessionValidator` sit where CM848's ignored
    request and source lookups sit (a name lead for CM550).
- **Stage B1 (2f5eec4): e2m 10E8 / 10E6 are the Jcomm control state.**
  - **The blocks:** Cummins' own layout of the struct (10E8 +4 = struct +0) and the retarder words.
  - **They confirm** the stage A names, e.g. Jcomm_Engine_Control_Network_Type 0 = J1922 / 1 = J1939 and
    TSC_Lost_Flag. Every covered field cites its record.
  - **They correct:**
    - `out_of_gear_network_type`, `j1939_blocked_message_bits` (J1939_Block_Message) and `engine_net_output_torque`;
    - the two device indicators (0 none / 1 transmission / 2 ABS / 3 ASR / 4 unknown);
    - `cm848_lookupJ1939ControlDevice`, which returns exactly those codes.
- **Stage B2: types.**
  - **Enums:** `TSC1_OVERRIDE_MODE` (resized to a word), `J1939_CONTROL_DEVICE` and `CONTROL_NETWORK`.
  - **short:** on the two e2m S fields.
  - **The source table:** its pointers are typed and the table is an array of 10.
  - **The ETC2 receive words,** settled from the stores:
    - the previous ratio is a word at +0xa (the old byte `auxiliary_state`; Ghidra's `_10_2_` counts in decimal);
    - the SPN 526 ratio is a word at +0xd.
  - **Also:** 0x5c39a `j1939_high_idle_override_speed`, the J1939 monitor's three copies of the engine control
    state, and two stale local rows.
  - **Reverted:** the bitfield. Masked writes render as a raw piece, so the field stays a word.
- **The TSC1 source table, read from the ROM image** (`originals/cm848_rom.bin` at 0x5c3b4, at word width):
  - **Senders:** entries 0-4 are J1939 (data link 1) with the source addresses 0x03 (the transmission), 0x0B, 0x21, 0x4A
    and 0x4F, which is task 022's whitelist. Entries 5-9 hold 0xFE (the J1939 null address) and are unused, so no
    wildcard is configured.
  - **Request timeouts:** 5 counts. The 10E7 MSEC cals count 10 ms, so that is 50 ms, J1939-71's TSC1 timeout. The
    transmission's mode 3 is 80 ms and the retarder's 250 ms.
  - **Time limits:** speed control is 0xFFFF for 0x03; the `+ 1` wraps it to 0, so the timer never fires and there is
    no limit. It is 600 = 6 s for the other four. Torque control is 6 s for all five, and the retarder has none.
  - **For task 022:** a TSC1 speed control request from 0x0B / 0x21 / 0x4A / 0x4F ends after 6 s, and the sender is
    then ignored until it sends override disabled. Only the transmission's address holds speed control indefinitely.
- **The arbitration, by branch (the plate is fixed):**
  - With no override active, any sender with an entry is accepted.
  - While a J1939 request is active, the controlling sender is always accepted. Another sender needs a higher
    priority, or at the same priority an active mode 3 request and a request that is not mode 3 or has a lower torque
    limit.
  - While a J1922 request is active, a J1939 sender needs an entry at the same or an earlier position.
- **The unused enums `GOVERNOR_MODE` / `RETARDER_MODE_STATE`** contradicted e2m 10E8 / 10E6 and are deleted. They were
  never applied, and the closing build proves a no-op.
- **Corrections:**
  - 0x5c38c and the table are in ROM (the main flash), not Bank 2. The `_cal` verdict (none) stands.
  - 4ae5f79 quotes `lha` only for `engine_net_output_torque` (0x40ae1c). The torque command's `short` rests on its e2m
    S record and on the render (the `(short)` casts it removed).
- **Round 6 leads** (the first three are resolved in round 7, below):
  - The J1939 monitor's session record: e2m 10FE J1939_Active_Engine (0x3feb4e), 10FF J1939_Active_Retarder and 1100
    J1939_*_Control_Status. Still unnamed or etc1-named: `etc1_governor_calib_session_start_time`,
    `etc1_governor_mode_history_write_index`, DAT_003feb56-5e (the mode history), DAT_003feb64 (the duration),
    `governor_transition_state_snapshot`. The "see j1939mon specification" text says it is one structure.
  - The other `cm848_*Governor*` functions of the TSC1 path: `cm848_resetGovernorState`, `governor_reset`,
    `governor_resetModeStateOnCondition`, `cm848_initGovernorStateVariables` and `initGovernorJ1939Bypass` reset the
    Jcomm state.
  - `retarder_tsc1_mode_transition_timer` / `retarder_tsc1_speed_mode_flag`: read the retarder handler in full.

## Done, round 7 (2026-11-21, same PR; the user's next "keep going")

Hand work on the round 6 leads (scripts in `session_folder/round7/`).
- **Stage A (9d2ebdf, label-only):**
  - **The J1939 monitor's working words** take their e2m 1100 names: `j1939_engine_control_source_cal` /
    `j1939_retarder_control_source_cal` and `j1939_control_session_history_next_entry_cal`.
  - **The tracker's retarder-half copies** are named like the engine half.
  - **The session functions' parameter** is `session_kind`, typed `int32_t` (the importer maps `int` to `dword`).
  - **The engine retarder TSC1 handler,** read in full:
    - `engine_retarder_received_tsc1_control_byte` / `_torque_byte`;
    - `retarder_tsc1_zero_torque_request_timer`: armed while the requested torque or limit is 0; why that is timed
      is open;
    - `retarder_tsc1_speed_control_flag`: always 0, because speed control is rejected. Its role as the retarder
      twin of `tsc1_speed_control_flag` is inferred, since no e2m record covers 0x40ae20-0x40ae4c;
    - `cm848_resetEngineRetarderTsc1Request` and `cm848_endRetarderShiftAssistAboveFuelDemandLimit`.
- **Stage C (9fd5621, label-only): the drivetrain ratio module.**
  - **Misnamed words:** `drivetrain_ratio_filter_state` (was `engine_temperature_protection_filter_state`) and
    `drivetrain_ratio_engine_period_valid_flag` (was `protection_timeout_enable_flag`, set by the VSS interrupt's
    period average).
  - **Gear down:** `drivetrain_gear_range` (was `governor_j1939_bypass_flag`) is the gear-down protection range,
    with `top_gear_ratio_threshold` / `gear_down_ratio_threshold`.
  - **Functions:** `cm848_initializeDrivetrainRatio`, `cm848_applyJ1939OutOfGearToDrivetrainRatio` and
    `cm848_saveOutputShaftSpeed`.
- **Stage B (types):**
  - **`j1939_control_session_t`,** the 24-byte j1939mon session record. Its layout comes from the three monitor
    functions and the EEPROM image's length words (0x78 / 0x18 / 0x18).
    - **Instances:** the history `[5]`, the active engine and the active retarder records.
    - **Replaced rows:** the four member rows. The control source words are `J1939_CONTROL_DEVICE`.
  - **The drivetrain cals** from e2m 106D, and `gear_down_gear_ratio_cal` (0x3fd900, e2m 8B8B).
  - **`DRIVETRAIN_GEAR_RANGE`.**
  - **The history store's locals** are named. The record local keeps the struct pointer type: its copy start reads
    `&session_record[-1].duration + 2` (the word before the record). A `word *` or `byte *` local made Ghidra spell
    it out longer.
- **Found:** the history table's length word (0x3fead4) is also `j1939_input_signal_timeouts[24]`.
  - The supervision tick's loop covers 25 words (`addi r3 = r4 + 48` / `bge` @ 0x50bd9c-0x50bdc4), so it would count
    the length word down.
  - The tick is off in this calibration (`j1939_input_processing_enable_cal` = 0). Documented on the array.
- **Thin evidence:**
  - `gear_down_gear_ratio_cal`'s address comes from the code. Block 8B8B is not in the parameter ID table.
  - Range codes 2 and 3 are never tested apart; the readers only test 1 against everything else.
  - e2m 1185 +A calls Top_Gear_Ratio the ratio above which the transmission is in top gear, but the code sets top
    gear below the threshold. The period formula makes the ratio engine speed / vehicle speed, lowest in top gear,
    so the code holds. The 0.8 / 1.0 ratios are not checked against the truck's gearing.
  - The session record length words have no direct load or store in the disassembly; e2m gives these type T
    records no size.
  - The tolerance percent at 0x408b78 has no writer and no e2m record, so it is unnamed.
- **Round 7 leads** (the first is resolved in round 8, below):
  - The transmission gear functions `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and
    `cm848_processProtectionStateFlags` (0x3257c): `transmission_current_gear` / output speed logic under inherited
    `protection_*` names (e2m 8D14 drifts). (Round 8: they are `cm848_learnVehicleInertia` and
    `cm848_selectGovernorPressureAntiHunt` of the 48RE controller; the e2m vocabulary is the `RE_*` blocks.)
  - The engine run-state machine (819B).
  - `cm848_initGovernorStateVariables`, a mixed governor initialization.

## Done, round 8 (2026-11-21, same PR; the user's next "keep going"): the 48RE transmission controller

The round 7 lead (0x3241c / 0x3257c) opened the whole 48RE controller, which was named `protection_*`. Scripts are in
`session_folder/round8/`.
- **Method:** the Chrysler e2m `RE_*` records, aligned by relative offset. None of the RE blocks are in the parameter
  ID table, but their bases are proved word by word:
  - **8C53 +0** `RE_Trans_Pressure_State` resolves to 0x40b100 in the table.
  - **8C17 (RAM) at 0x40b102**, aligned +0..+4A (it drifts from +4C, see stage F). The anti-hunt timers start it.
    `RE_OSS_Accel` (+28) lands on the existing output shaft acceleration, and seven names that were already right
    match (`RE_Governor_Set` = `governor_pressure_target`, `Transmission_OD_Lamp` = `overdrive_off_flag`, ...).
  - **8BBC (ROM cals) at 0x40780c**, aligned +0..+5C (it drifts from +5E). The anti-hunt timer limits and the
    inertia limits start it. +10 `RE_Inertia_Default` is the word `cm848_initializeTransmissionShiftLogic` copies
    into the learned inertia (`lhz @ 0x331d4`). Both read 53 in the engine-off RAM dump, which is the unlearned
    default, not independent evidence.
    `align_block.py` prints a block against the rows with each row's users.
- **Stage A (e848623, label-only): the anti-hunt mode and its post-shift acceleration model.**
  - `cm848_selectGovernorPressureAntiHunt` uses the hold curve (prevent the upshift) and the boost curve (force it),
    once the predicted post-shift acceleration clears `RE_PSA_Max_*`.
  - `cm848_predictPostShiftAcceleration`, `cm848_calculateTransmissionOutputTorqueInGear` (the turbine torque
    estimate x the gear ratio) and `cm848_learnVehicleInertia`.
  - `transmission_pressure_state_t` (the pressure state, then the anti-hunt timers), the gear ratio table and 25
    tables.
- **Stage B (1766051, label-only): the rest of both aligned ranges.**
  - The low range, lockup / unlock service, WOT boost / hold / anti-hang and cruise decel cals.
  - The 8C17 working words, including the predicted shift delays (were `governor_pressure_learned_gain_gear1` / `2`)
    and `transmission_overheat_protection_active_flag` (was `hot_mode_flag`).
  - `transmission_lockup_timers_t` (was `protection_lockout_t`).
  - `cm848_selectGovernorPressureLowRange` (was `cm848_protectionOverloadHandler`), the timer tick, the
    initialization, the output shaft acceleration and the governor pressure sensor offset calibration.
- **Stage C (types):** the gear ratio table as `word[6]`, `transmission_vehicle_inertia_default`, and
  `cm848_initializeTransmissionShiftLogic`.
- **Stage E (label-only, after the closing commit f349dd2):** what the timer tick still counted under
  `protection_*` names.
  - `cm848_monitorConverterClutchEngagement` (was `cm848_processProtectionRateLimitFlags`): read as a converter clutch
    engagement monitor (3 s for the speed ratio to enter the gear's window, else the lockup inhibit). Stage F
    corrects it: the e2m names it the exhaust brake lockup aid (now `cm848_updateExhaustBrakeInhibitForLockup`).
  - `cm848_selectGovernorPressureHighGear` (was `cm848_calculateProtectionThresholdLimit`): pressure state 0x10 in
    3rd / 4th below a throttle curve, plus the manual 1 / 2 lever's 4-3 request. Stage F renames it
    `cm848_selectGovernorPressureLockupBoost` (e2m `RE_Lockup_Boost`).
  - The WOT anti-hang timer and the WOT upshift target / command engine speeds (3075 rpm, the target minus engine
    acceleration x the predicted shift delay).
  - The cruise decel downshift / upshift delay timers.
  - Stage E read the 8C17 record at +4A (`RE_E_Brake_Inhibit_Timer`) as not fitting the code. It does fit (stage F),
    so 8C17 drifts from +4C.
- **Stage F (label-only, after the review): e2m 8C18 and the exhaust brake lockup aid.**
  - **8C18 (ROM cals) aligns at 0x4082f4, +00..+98.** From +9A the rows are a table axis. Rows named before from
    their code use confirm it:
    - +0E `RE_ERPM_WOT_Target` = stage E's WOT upshift target;
    - +16 `RE_Lockup_Boost` = the pressure state 0x10 target;
    - +1E `RE_Low_Range_Max`;
    - +20..+24 the gear identification ratios;
    - +26..+54 the overdrive and over temperature light temperatures;
    - +70 `RE_OSS_Accel_Method` = the method switch of `cm848_calculateOutputShaftAcceleration`.
  - **The renames:** 71 globals in all. Among them: the engine acceleration defaults / limits, the WOT shift lag band,
    the lockup and overheat lockup delays, the detent / WOT throttle thresholds, the predicted shift delay limits
    (were `governor_pressure_learned_gain_gear1 / 2_maximum / _minimum`), the overheat protection temperatures (were
    `hot_mode_*`) and the governor pressure override.
  - **The exhaust brake lockup aid** (stage E's "converter clutch engagement monitor"). The e2m names:
    - 8C17 +4A `RE_E_Brake_Inhibit_Timer`: 'Used to time ebrake TCC inhibit timeout limit';
    - 8C18 +88..+92 `RE_EB_Lockup_Range_*` and +96 `RE_E_Brake_Inhibit_Timeout`;
    - 8C19 +16 `RE_E_Brake_Inhibit_LU`: 'Flag set to inhibit Exhaust Brake to allow TCC lockup'.

    In the code, `cm848_updateEngineRetarderEnableState` reads bit 0 of 0x40b0fe as its torque converter lockup
    disengaged input. The exhaust brake sets that bit entering 2nd gear and after a 4-3 downshift. So the exhaust
    brake waits for converter lock: `cm848_updateExhaustBrakeLockupInhibit`, `exhaust_brake_lockup_flags`,
    `exhaust_brake_lockup_inhibit_timer` / `_timeout`, `exhaust_brake_lockup_speed_ratio_*` (stage G reorders the
    inhibit names). 8C17 drifts from +4C,
    not +4A.
  - **The lockup boost:** `cm848_selectGovernorPressureLockupBoost` (was stage E's `cm848_selectGovernorPressureHighGear`).
    Pressure state 0x10 is `RE_Lockup_Boost`, 'Gov pressure target during lockup, to prevent downshift'
    (`governor_pressure_lockup_boost`, was `governor_pressure_high_gear_target`).
  - **Switch 12 is the exhaust brake switch.** With `exhaust_brake_transmission_features_inhibit` (`RE_Ebrake_Inhibit`,
    0) clear and switch 12 on, `cm848_protectionStateTransitionCheck` uses the alternate `_c` 3-4 / 4-3 lines.
  - **Review fixes:**
    - the `cm848_calculateOutputShaftAcceleration` plate gives its two methods;
    - the ordinals are 1st / 2nd / 3rd everywhere;
    - three `global_variables.csv` comments that earlier scripts wrote with Python's `csv` module are unquoted (the
      importer splits that file with `split(",", 4)`, so commas need no quotes);
    - the stage C comment fix on the gear ratio table lands.
  - **Width check** (`width_check_r8.py`, the stage 8c rule): every 8BBC / 8C17 / 8C18 / 8C53 record in the aligned
    ranges has a row of its size. The exceptions are two words nothing reads: 0x407856 `RE_Lockup_Delay_2_3_Max_2nd`
    and 0x408372 `RE_Cruise_Unlock_Inhibit`.
- **Stage G (label-only, after a second review):**
  - **Word order:** the exhaust brake inhibit words take the word order of their records. `RE_E_Brake_Inhibit_LU`
    means the exhaust brake is inhibited (so the converter can lock). Stage F's `exhaust_brake_lockup_inhibit_*` read
    as a lockup inhibited by the exhaust brake, and the same function also sets a real lockup inhibit (`condition_eval`
    bit 6). The new names:
    - `cm848_updateExhaustBrakeInhibitForLockup`;
    - `exhaust_brake_inhibit_timer` / `_timeout` / `_previous`;
    - `transmission_exhaust_brake_flags`, the byte's record `RE_Trans_EBrake` ('Contains engine brake flags').
  - **Bit 2** of that byte is `RE_Ebrake_Inhibit_Timeout_Flag` ('E-Brake inhibit timeout flag'): the code sets it
    exactly when the inhibit timer runs out.
  - **8C19 at 0x40b0e8** is checked by code use at +0..+3, +9 (the low range boosts), +A (`status_flags`: the WOT
    anti-hang and boost flags), +C (`flags[0]`: the anti-hunt boosts, the detent) and +16.
  - **Switch 12** is the exhaust brake switch, proved by code: `cm848_driveEngineRetarderOutput` sets
    `engine_retarder_switch_percent_2` to 100 while it is on.
  - **The polarity of `converter_clutch_closed_throttle_lockup_enable`:** 1 here skips the block that unlocks the
    converter on the brake (switch 11) or switch 2, so its name has the right sense. The comment now says so.
  - **The csv-module audit:** `csv_tail_check2.py` and the scripts that wrote these files found no other damage than
    the three quoted rows, the 0x40b0fe tail and the lost stage C edit.
- **Thin evidence:**
  - `transmission_output_speed_fault_debounce_timer` (8C17 +8): only the timer tick and the initialization use it.
  - The turbine torque tables have other sizes than in the 11.45 e2m (17 / 9 / 17 x 9 here, 8 / 8 / 5 x 5 there).
  - The gear ratio table's indexes 0 / 1 (10 / 512) are unexplained.
- **Round 8 leads** (round 9 resolved all of them except signedness: the enum, the cruise function, the low range
  lockup, the 8C19 bytes, the tables, 8BB5 / 8BBB / 8BBD and the ring. 8BBB sits at 0x4077f6, not 0x4077cc;
  0x407800 is its +0A, the OD-off 4-3 lockup delay):
  - The pressure state codes 1-0x18: an enum needs every mode handler's curves. Named so far: 1 base, 0x12 / 0x13
    anti-hunt boost, 0x14 / 0x15 anti-hunt hold, 0xb-0xf low range, 0x10 lockup boost, 0x11 2nd gear lockup boost,
    0x16 manual low, 0x17 override, 7 / 9 WOT 1-2 / 2-3 hold, 8 / 10 WOT 1-2 / 2-3 boost.
  - The still `protection_*`-named 48RE functions and tables:
    - `cm848_protectionStateTransitionCheck` (0x31d98): the 3-4 / 4-3 shift lines, manual low and the cruise decel
      requests (e2m `RE_Normal_3_4` / `4_3`, `RE_Cruise_*`). Its gate (`condition_flags_1` bit 4) and pressure
      state 3 are not identified yet. Switch 12, the exhaust brake switch (stage F), picks the alternate `_c` shift
      lines;
    - `cm848_protectionCleanupHandler` (the 3rd gear lockup);
    - the `protection_condition_flags_t` / `protection_status_flags_t` bits. e2m 8C19 aligns at 0x40b0e8:
      - +0 `RE_Trans_Flag1` = `condition_eval`, with `RE_Request_3_4` / `RE_Request_4_3` at bits 2 / 1;
      - +1 `RE_Trans_Flag2`, with `RE_Low_Range` at bit 2 and `RE_Decel_Mode_Active` at bit 0;
      - +2 `RE_Trans_Flag3`, with `RE_Forced_2nd_Gear_ID` at bit 1 and `RE_High_Pressure` at bit 2;
      - +3 `RE_OD_Flags`, +5..+8 the limp flags, +16 the exhaust brake flags.

      The e2m gives no bit positions, so each bit still needs its code use;
    - the remaining tables (`RE_Cold_Curve`, `RE_Cruise_Curve`, `RE_Fuel_Economy_Curve`, `RE_WOT_*_Curve`,
      `RE_Lockup_*`, `RE_Unlock_*`).
  - Blocks 8BB5 / 8BBB / 8BBD (more RE cals), to align the same way. 8BBB may sit at 0x4077cc: its +34
    `RE_EB_Lockup_Delay_4_3_Max` would then be 0x407800, the 4-3 lockup delay `cm848_processOverdriveSwitchAndShift`
    loads with `overdrive_control_flags` bit 5.
  - Signedness: the anti-hunt compare casts `transmission_predicted_post_shift_acceleration` and
    `transmission_post_shift_acceleration_minimum` to `short`. Run the round 3 `i16` rule over round 8's rows; the RE
    records give the sign (column 10).
  - Method 1's 27-word output speed ring at 0x3fb192 (between `transmission_output_shaft_acceleration_sample_counter`
    and `transmission_output_speed_history_index`) as a `word[27]` `transmission_output_speed_history`.

## Done, round 9 (2026-11-21, same PR; the user's next "keep going"): the 48RE tables in memory order

Scripts are in `session_folder/round9/`.
- **Method: e2m column 5 is the ROM layout.** Every ROM calibration block carries a sequential number in column 5,
  and RAM blocks have 0000. The blocks sit in memory in that order.
  - `walk_tables.py` walks a run of table blocks from a known address. It sizes each table from its byte-length word in
    the RAM dump: an X axis or Y curve is a length word plus data, a Z grid is nx x ny words with no header. It prints
    the CSV row at each address.
  - From round 8's anchor 0x407876 (0B43) every table through 0B98 lands on an existing `word[N]` row of exactly the
    walked size: 58 tables. After 8C18, 0B9E..0BA9 and 0BB5..0BC6 match the same way: 30 more.
  - Each table's users in the code are the mode its record names.
  - Where 11.46 differs from the 11.45 e2m:
    - grid boost axes sit inline before the grid;
    - the T tables (`RE_Gear_Ratio`, the shift lags) are elsewhere;
    - 8BBB stops at +14 (its tow / brake / exhaust brake 4-3 tail is not before 8BBC);
    - the manual 2nd curve sits after `RE_WOT_Curve`.
- **Stage A (0f4daf6, label-only):**
  - about 70 tables named;
  - 8BB5 at 0x408ae0, the governor pressure control calibration (38 words);
  - 8BBB at 0x4077f6 (+00..+14) and 8BBD at 0x40b0ae (+00..+38, which confirms round 8's code names);
  - the governor pressure solenoid controller, which was the `cm848_throttle*` family. Its offset limits had
    backwards names;
  - `cm848_selectGovernorPressureCruise` and the low range / normal lockup, unlock and shift functions.
- **Stage B (84be9af, label-only):**
  - the 30 tables after 8C18;
  - the exhaust brake tables: e2m 8CA6..8CC6, column 5 1010..1030, in that order at 0x4080b0..0x4082bf and 0x408606.
    Stage A had called them 11.46 tables;
  - `RE_Manual_2nd_Curve`;
  - `governor_pressure_exhaust_brake_curve`, the one table here with no 11.45 record.
- **Stage C (3301eb9): `TRANSMISSION_PRESSURE_STATE`.**
  - 24 members, every value proved by its store; the code compares only with 0x11 and 0x18. `check_enum_proof2.py`
    shows only enum substitutions.
  - Also the 27-word output speed ring and the `dword` fix that removes `_throttle_setpoint_limit_arg`.
- **Stage D (f63a28b, label-only plus a field split): the 8C19 flag bytes.**
  - `transmission_control_flags_t` (0x40b0e8, +0..+9): `request_flags` (the 4-3 / 3-4 requests, the unlock request),
    `mode_flags` (cruise active, decel, low range), `state_flags`, `overdrive_flags`, `axle_ratio_learning_flags`,
    `limp_home_flags_1`..`4` and `low_range_boost_flags`.
  - `transmission_shift_strategy_flags_t` (0x40b0f2, +A..+11): `wide_open_throttle_flags`, `run_fuel_mode_flags`,
    `anti_hunt_flags` / `output_shaft_speed_flags` / `actuator_test_flags` (split from the 3-byte `flags`),
    `service_test_request_flags` and `limp_home_and_temperature_flags`.
- **Round 9 leads:**
  - Name the single bits of the limp-home and overdrive flag bytes. The e2m lists each byte's bit records, but not
    their positions.
  - The table lookup caches still named `protection_filter_stage_*_state` / `protection_rpm_limit_table_*_state` /
    `DAT_003fb1xx`: name each after its table.
  - The 11.45 T tables (`RE_One_Two_Lag` / `RE_Two_Three_Lag`) are the EEPROM adaptive shift lag tables (0x3fede2):
    name them.
  - 8BBB's tail (tow mode, brake 4-3, exhaust brake 4-3 command) is not in front of 8BBC in 11.46. Find it or show
    it is absent.
  - The other RE blocks: 8C33 / 8C34 (the converter clutch monitors), 8C55 (governor pressure rationality), 8C29 and
    8C49 (rock cycle torque management).

## Leads (not in this PR)

- **Round 5 leads:**
  - The TSC1 / ETC1 vocabulary: resolved in round 6 (below).
  - The `governor_cruise_*` working words of the cruise governor (and its `governor_cruise_zone_table_ptr`):
    rename them to the `cruise_governor_*` words with the functions.
  - The engine speed module's run-state machine (`mpc555_updateEngineRunState`, the `cm848_engineRunState*` handlers).
    Block 819B has no value list, so naming the states needs a read.
  - The 48RE governor pressure functions 0x3257c / 0x3241c and their words. Block 8D14 drifts from +2, so its
    shift-timer records do not describe them.
  - The TPU bytes 0x3fd0b8-0x3fd0bb, the A/C class-B coolant flag pair (read by the warning lamps), and the second
    A/C condition code 0x40b1e6.
- **Wave 15 leads still open** (each is in the agents' reports, `wave15/agent_prompts_and_reports_W15.md`):
  - The fault derate scheduler words (`governor_faultDerate_*` without e2m records) and the remaining
    `engine_protection_*` / `protection_*` functions.
  - The 11D5 air fuel control thresholds and slew rates; the agents report the slew rates as dwords typed `word`.
  - The TPU bytes 0x3fd0b8-0x3fd0bb, which belong to `cm848_initializeInjectionHardware` and
    `cm848_monitorFuelSystemHardwareShutdown`.
  - The converter clutch monitor's `protection_*` words and the wastegate controller's working words.
  - CM550's 0x80a9e0, the unnamed twin of 0x40a280.
  - `sensor_channel9_ram` (0x40a0e6) is the state of the `cm848_sensorChannel9_*` wrappers. Check which
    `channel_index` they pass before naming it: the wrapper number is not the channel.
  - Kept: `lifetime_distance_pulses` (117F Total_Distance, MI). The name gives the raw unit (8000 pulses per mile),
    which fits the code.
- **Resolved in round 5:**
  - the 9-word ASG gain set struct;
  - the cruise / RSG PID functions;
  - the PGN 65232 / 65251 / 61441 / 65279 functions (the CM550 twin renamed too);
  - the A/C working words;
  - the stale `target_rpm` rows;
  - the TPU injection / shutdown functions;
  - 0x3fdda6;
  - the compressor outlet temperature scale (1/32 °F).
- **The pool left:** the e2m audit's unreviewed rows above 0.2 overlap (123 at ≤ 0.25, 140 at ≤ 0.34, 220 at ≤ 0.5).
- **The engine speed module's functions** have mixed, partly wrong prefixes: `hpcr_processEngineSyncPulses` (the main
  speed interrupt), `mpc555_handleCamSignalInterrupt` (the backup speed interrupt), `mpc555_updateEngineRunState` (the
  crank sync state machine), `mpc555_resetEngineTimingAccumulators`, and `cm848_engineRunState3Handler` and its
  siblings. Rename them once each state's behaviour is read.
- **The signedness sweep's remainder:**
  - The 35 `has-lhz` rows need a per-row look: zero-extending loads usually mean the code treats the value as unsigned.
  - The 104 `no-load` rows are stored or pointer-passed only.

- **Unused unnamed e2m rows:** 1772 +2 Engine_Delta_Pressure, +4 EGR_Valve_Delta_Pressure and +6
  EGR_Orifice_Delta_Pressure (0x40a674-0x40a678), and 198C +A C_TPE_EMP_VT_Cmd_Cnst (0x406764). No code in the
  decompile references them, so they have no rows.
- Resolved in round 3: the TPE exhaust pressure estimator, sensor channel 109, 0x13294's stale prototype, and the
  functions just past the family (0x130ac, 0x13294-0x13774).
- **Open question:** the dump's write indices differ (191 / 215) although both advance once per pass in the same
  function. The kernel-image bytes the boot copy leaves under them (ROM 0x47e6 / 0x49e8) differ by 63, not 24, so the
  start values are unexplained.
- `firmware/classification.csv` and `docs/memory-mappings/bank1.txt` / `ram.txt` are stale generated snapshots: wave 14
  did not refresh them either, and 0x127bc still reads `selectFuelTrimMode` there. Regenerate them rather than patching
  rows. The same goes for the old `output/bank2_functions.cpp`, `output/internal_names_crossref.md` and the
  `output/worklist_*` batches.
- `output/fuel_injection_analysis.md` ("Related Functions") lists 0x128a0 / 0x12ad4 / 0x12cf4 / 0x12dc4 by their old
  names as a "Fuel Demand Calculation Chain". They are the CHP charge flow model: the delayed EGR flow, the volumetric
  efficiency, the charge mass flow and its wrapper. Rewrite that section (now `cm848_calculateDelayedEgrFlowAndFraction`
  / `cm848_calculateVolumetricEfficiency` / `cm848_calculateChargeMassFlow` / `cm848_calculateChargeFlowEstimate`).
