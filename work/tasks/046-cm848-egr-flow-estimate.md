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
    `governor_resetModeStateOnCondition`, `cm848_initGovernorStateVariables` (now `cm848_initializeLowSpeedGovernorReferenceSpeed`) and `initGovernorJ1939Bypass` reset the
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
  - `cm848_initGovernorStateVariables` (now `cm848_initializeLowSpeedGovernorReferenceSpeed`), a mixed governor initialization.

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
    walked size: 88 tables (86 blocks and 2 inline axes). After 8C18, 0B9E..0BA9 and 0BB5..0BC6 match the same
    way: 30 more blocks.
  - Two more groups sit by the walk's order and the code: the 2nd gear closed-throttle unlock pair, and the exhaust
    brake tables. The exhaust brake tables are 32 (blocks 8CA6..8CC6 with two boost axes).
  - A size match alone is not proof. 0B99 / 0B9A matched by size, but in 11.46 they are the manual 2nd pair, so
    the code users decide.
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
- **Stage F (fb2426c, label-only, after a review):** the review fixes.
  - **e2m 8BB6** aligns at 0x40b58c, the controller's RAM block (`RE_Deriv_Term` ... `RE_VFS_PWM_On_Time`). It
    confirms stage A's controller names. `governor_pressure_derivative_term` and `governor_pressure_error_slope` get
    their record names, and the proportional term at 0x40b59e is new. The old 8C34 `TCC_Function_Timer` note on
    0x40b58c was wrong.
  - **Old field names:** stage D's bare old field names in 48RE comments and plates (25 rows, 8 plates) now use the
    new names. The P0720 monitor's plate names `limp_home_flags_4`: its bit 5 is `RE_OSS_Limp`, which confirms the
    +8 alignment. `state_flags` bit 5 (service lockup) is an inference from its readers.
  - **Other renames:** `governor_pressure_normal_curve` (was `_base_curve`, matching `RE_Normal_Curve` and the
    enum's `NORMAL_CURVE`) and `overdrive_switch_power_on_delay_counter`.
  - **Checked by code use:** the cruise resume words and the O/D switch power-on delay of 8BBB.
- **Round 9 leads:**
  - The 43 new label-only rows (8BB5 / 8BBB) have no type yet. Typing them is a cast-normalized stage.
  - 8BB1-8BB4 (`RE_Axle_Ratio_Factor_*`, the axle ratio learning) and 8BB9 / 8BBA (`RE_Governor_Comp`, the
    governor pressure compensation table before 8BBB).
  - The limp-home bits: read each one from its fault setter, then the DTC, then the e2m record (as the P0720 bit
    did).
  - Signedness: the RE records carry the sign (column 10); deferred since round 8.
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

## Done, round 10 (2026-11-21, same PR; the user's next "keep going"): types, the monitors, the relay and the SCI tests

Scripts are in `session_folder/round10/`.
- **Stage A (3be5a5e, label-only): the 78 RE lookup caches** (54 `DAT_` words, 24 `protection_*` names) take their
  table's name (`gen_r10a.py`). A second cache of the same table gets `_2`. The 3rd / 4th gear exhaust brake unlock
  lookups share one cache.
- **Stage B (b9df152, types):**
  - 26 RE calibrations become `i16`: their e2m record is signed 2-byte and every load is `lha` (`re_audit.py` +
    `classify_signed_loads.py`).
  - The 98 label-only rows of rounds 9 / 10 get types, e.g. `RE_Max_Pressure_Delta` `i32` and the five 2-D grid
    caches `word[2]`.
  - The learned 1-2 shift lag table `transmission_1_2_shift_lag_cal` `word[6]` at 0x3fede2 (e2m `RE_One_Two_Lag`,
    EEPROM, trimmed by `cm848_updateTransmissionConditionFlags`). Its 2-3 twin at 0x3fedee lies under the boot
    kernel's diagnostic rows.
- **Stage C (c9e793d, label-only):**
  - **The cache suffix:** every lookup cache ends in `_cached_axis_offset` (127 `_interp_state` /
    `_interpolation_state` rows; "interp" is a short form). `word[2]` grids end in `_cached_axis_offsets`.
  - **Output 16 is the transmission relay** (`transmission_relay_request`). Its output check pairs faults 136 / 137
    = P0883 / P0882 'TCM power input', and fault 137 sets the e2m 8C19 bit `RE_Trans_Relay_Circuit_Open`. Outputs
    17 / 18 have the same kind of pairs (P0974 / P0973 shift solenoid A = overdrive, P2770 / P2769 converter
    clutch).
  - **The transmission controller's functions:**
    - `cm848_updateTransmissionRelayRequest`
    - `cm848_updateTransmissionLimpHomeFlags`
    - `cm848_updateTransmissionControlInputs`
    - the two phase-group-B phases `cm848_updateTransmissionControlState` / `cm848_runTransmissionControlWhenEnabled`
    - `cm848_initializeGovernorPressureTrackingMonitor`
    - `cm848_initializeAlternatorFieldControl`
  - **The monitor words:** the P1762 monitor words (e2m 8C56: `governor_pressure_rationality_monitor_state`, was
    `j1939_fault_state`), the P1756 / P1757 monitor's `protection_coldStart_*` words, and
    `transmission_normal_operation_flag`.
- **Stage E (4ff8174, label-only):**
  - **The P1740 monitor's working words** (`converter_clutch_rationality_*`, were `protection_*`).
  - **The SCI 0x13 actuator tests.** The DRB database (mydb, SCI 13-xx transactions) names every code:
    | Code | Test | Output |
    |---|---|---|
    | 13-09 | A/C clutch relay | 38 |
    | 13-28 / 13-29 | intake heaters | 43 / 44 |
    | 13-33 | fuel transfer pump | 53 |
    | 13-43 | transmission relay | 16 |
    | 13-49 | wait to start lamp | 4 |
    | 13-5D | exhaust brake | 11 |
    | 13-5E / 13-5F | fuel control / PWM radiator fan | the two flag tests |
  - **SCI names:** `cm848_updateSciOutputTests` / `cm848_stepSciOutputTest` / `cm848_stopSciOutputTest` /
    `cm848_stopAllSciOutputTests`, `sci_output_test_*`, `fuel_control_actuator_test_active_flag` and
    `cooling_fan_actuator_test_active_flag` (were the `cold_start_protection_*` / `diag_protection_*` family).
- **Stage D (ee328b7, types + renames):**
  - **`DIAGNOSTIC_MONITOR_STATE`** (the e2m NORUN / RUN / CMPPS / CMPFL / ABORT list) on six monitor states.
  - **The limp-home bit map:** each 8C19 bit with its setter. The bytes stay byte fields (the wave 11 rule).
  - **23 more caches** named after their tables.
- **Stage F (84033f0, types):**
  - `sci_output_test_timers_t` (0x3fcf40, one word per test; the calls read
    `cm848_stopSciOutputTest(&sci_output_test_timers.intake_heater_1,0x2b)`).
  - Full prototypes for the three test helpers (`word *timer`, `dword logical_output`, `word duration`). With Ghidra's
    `short *` guess, the first build printed the field addresses as raw constants: a pointer parameter must match
    the struct field's type.
  - The widths: 0x3fceee as a `dword` removes the overlap WARNING from the two P1756 / P1757 functions (27 -> 25 in
    the .cpp); the new rows get their types.
  - The proof: `relabel_struct.py` maps `instance.field` back to the old labels, then `cast_normalized_diff.py` runs.
- **Round 10 leads:**
  - **The `cam_sync_*_cal` tables** of `cm848_calculateFuelMeteringCommand` are fuel metering tables (by battery
    voltage, by engine speed). Give them an e2m pass, then name their caches (`engine_sync_init_state_a` / `b` /
    `j` / `k` / `l` / `n`). The same applies to `fuel_demand_interp_state_a`..`f` (`j1939_fuel_table_*_cal`),
    `governor_interp_table_state_b` and `cruise_switch_interp_index`. (Round 11 renamed the cruise switch cache;
    round 12 re-domained the cam_sync tables and their caches from the e2m HPCR_* records.)
  - **The end-of-line test sequencer** `engine_coldStart_protection_stateMachine` (0x52fa34) and its
    `cold_start_protection_*` words, `fault_event_queue_clear_active` and `protection_voltage_active_flag`.
    (Resolved in round 13: the end-of-line test steps and the SCI command 0x25 service tests.)
  - **The logical outputs** 4 / 11 / 38 / 43 / 44 / 53 have DRB names now. Bitfield structs for their bytes of
    `logical_output_request_bits` are possible: the code reads them, and the set / clear functions write them.
    (Resolved in round 11: the bytes are bitfield structs named from e2m 1577.)
  - **e2m 8C80** (the TVA auto zero monitor, `TVA_*`) and 8C2D (TTSR) have no row or block address yet.
  - **0x3fcf16-0x3fcf2e:** the SCI high-speed table words, and `DAT_003fcf5c` / `5d` (`cm848_countdown_timer_update`).
  - 8BB1 / 8BB3 / 8BB9 / 8BBA and 8BBB's tail are still not located.
  - **The lift pump control (output 53)** still has `protection_*` names: `protection_ambient_qualification`
    (0x519cc4) turns it on at key-on and while cranking / running, and off after a per-state timeout
    (`DAT_00408978` / `7a` / `7c`, with override cals `DAT_00408976` / `7e`); also `protection_exception_event_35_init`
    (0x519c84) and the `protection_event35_*` words. The firmware requesters of the five DRB-only test outputs
    (4 / 38 / 43 / 44 / 53) agree with their DRB names; firmware/CLAUDE.md's table lists them. (Resolved in round
    11: `cm848_controlLiftPump` and the e2m 8A6F words.)
  - The comment of `lookupTableInterpolation`'s cache parameter (`function_definitions.csv` row 14) still says
    `*_interp_state`: fix it with the `cam_sync_*` cache pass.
  - The stem check (`round10/stem_check_r10.py`): 90 of the 101 caches round 10 named after their tables appear in
    lookup calls, each with its table's stem. The one exception is the shared exhaust brake unlock cache; the other
    11 are `_y` words.

## Done, round 11 (2026-11-21, same PR; a "keep going" relayed from another session): the e2m output and switch maps

Scripts are in `session_folder/round11/`.
- **The e2m tables of the discrete I/O** (not in the dumped part of the parameter ID table except 12A7 / 12A8):
  | Block | Contents | Layout |
  |---|---|---|
  | 1577 | the 80 logical output requests (`<Name>_Driver`) | output N = byte N/8, mask 1 << N%8, at 0x40c080 |
  | 12A7 | the per-output override priorities | 0x40c094, `logical_output_request_priority` |
  | 1578 / 1579 / 157A | inversion, hardware map, previous command | per output |
  | 1612 | the 32 debounced discrete inputs (switches) | switch N = byte N/8 bit N%8, `switch_input_state_bits` at 0x40c050 |
  | 12A8 | the per-input override priorities | 0x40c058 |
  - They confirm the round 10 DRB names (16 = Transmission_VFS_Battery_Driver, the relay's battery feed of the
    solenoids) and the earlier switch findings (20 = park / neutral, 12 = Engine_Brake_Select_1, the exhaust brake
    switch, 13 = A/C).
- **Stage A (3c1f706, label-only):**
  - **The lift pump control:** `cm848_controlLiftPump` / `cm848_initializeLiftPumpControl`,
    `lift_pump_run_reason`, `lift_pump_engine_stopped_time`, and the 8A6F calibrations at 0x408976 (override state,
    the run times after cranking 20 s / key-on 35 s / running 0 s, override enable).
  - **Why 8A6F is shifted:** 11.45 computes the key-on time from a temperature table (8D2C / 8D2D into RAM 8D2E).
    This calibration has a fixed word at +4, so 11.45's +4 / +6 records sit at +6 / +8, and Temp_Source has no
    word. The code decides: the override gate is +8 and the reason 1 / 2 / 3 limits are +4 / +6 / +2.
  - **The SCI output status word:** `cm848_sciPackOutputStatusWord` (was `FUN_0051dfdc`) / `sci_output_status_word`.
  - **Two cache names**, and the request byte at 0x40c084 renamed `logical_output_request_bits_32_to_39`.
  - **The 1612 switch map** in the `switch_input_state_bits` comment.
- **Stage B (9e292a9, types):**
  - Bitfield structs for request bytes 1 / 4 / 5 / 6 / 8 / 9 from 1577: the tested bits named, the rest
    `reserved_bit_N` with the record. Every access is a masked read, so there are no pieces.
  - Byte 0 stays a byte: the set / clear functions index the array from it.
  - `LIFT_PUMP_RUN_REASON`.
  - The proof: `bitfield_normalize.py` (field to `(instance & mask)`, enum members to values) +
    `cast_normalized_diff.py`.
- **Stage C (2da9b14, types): `switch_input_state_t`** at 0x40c050, from 1612.
  - **The shape:** byte 2 (switches 16-23: park / neutral, the O/D OFF button, remote PTO, the relay and solenoid
    feedbacks) is a bitfield unit. Bytes 0 / 1 / 3 are byte fields (`switches_0_to_7` / `_8_to_15` / `_24_to_31`),
    each with its bit map. Five setter functions update their bits with | / & (switches 2 / 13 / 31).
  - **The pilot (all 32 as bitfields)** measured 216 named reads, but also 10 `._N_1_` piece lines in 3 of the 5
    setters (2 folded into `unwired_switch = 1 / 0`), and the scanner printed
    `(&switch_input_state_bits.field_0x0)[i]` (`round11/pilot_r11c_numbers.txt`).
  - **Left to the user:** the pilot failed the no-pieces gate and the firmware/CLAUDE.md rule. Taking the full
    struct means swapping in the pilot's rows (`apply_r11c_switch_struct.py`) and amending the rule.
  - **The proof:** `switch_normalize2.py` + `cast_normalized_diff.py`.
- **Stage D (a12ff3b, label-only):** output 54 was renamed `fuel_shutoff_request` (it had been stage B's
  `injector_driver_asic_shutoff_request`), from its requesters, the fuel pressure fault reactions
  (`output_requesters.py 0x36`).
- **Stage E (e3f493c, label-only, after the review): output 54 is `driver_asic_shutoff_request`.**
  - `fuel_shutoff_request` blurred it with output 30 (1577 +3 0x40 `FSO_Command`, which
    `cm848_processProtectionFaultsAndTiming` requests every pass).
  - Every reader of output 54 pairs it with `supervisor_register_36_bit_1_low_held_flag == 0`. The output read-back
    debounce, the injector and fuel metering feedback diagnostics and the fault scan stand down while either is set.
  - So it shuts off the output driver ASIC (e2m `ASIC_FS_Shutoff_Driver`). It is the software path next to the
    supervisor's shutdown line, requested by the fuel system fault reactions (reaction mask bit 3, fuel pressure
    too high, fault 388 excess fuel demand).
- **Round 11 leads:**
  - **The switch bytes 0 / 1 / 3 as bitfields:** the user's call (the numbers above). (Done in round 16 stage C: the user approved it.)
  - **`fuel_pressure_setpoint_map_cached_axis_offsets`** is a `word` row with a plural name: type it `word[16]`.
    (Resolved in round 12: the block is eight 2-word caches, so `word[2]` plus seven new rows.)
  - **`cruise_setpoint_interp_prev`** (0x3fd006) is a value looked up by vehicle speed (its change per pass is
    clamped to +-0x66), not a setpoint: name it with the cruise governor. (Round 16: `cruise_governor_filtered_road_speed`, the derivative filter output.)
  - **The input priority array** at 0x40c058 (e2m 12A8) has no code reference by name yet.
  - **Outputs 68 / 71** (`egr_valve_motor_opening_direction_request`,
    `variable_geometry_turbocharger_motor_closing_direction_request`) have no constant-index requester: their setter
    is unknown.
  - **`j1939_switch_input_default_state_bits`**, which `hpcr_initProtectionAndOutputCycle` copies into the switches:
    check whether it is e2m 1571 `Discrete_Inputs_Global_Default`.
  - **Comments and plates** still describe the switches and output bits in the old `[2] & 0x10` syntax.
  - **Output 30** `FSO_Command` (with 28 `CAN_Reset`) is requested on every pass by
    `cm848_processProtectionFaultsAndTiming`; byte 3 of the request array has no row.
  - 8C80 / 8C2D and the SCI high-speed words stay open from round 10 (round 12 resolved the cam_sync tables,
    round 13 the end-of-line test sequencer).

## Done, round 12 (2026-11-21, same PR; the relayed "keep going"): arrays and the CP3 fuel metering vocabulary

Scripts are in `session_folder/round12/`.
- **Stage A (9448e53, types): scalar rows typed as the arrays their comments describe.** `array_candidates.py` checks
  that no other row sits inside each range; the `DAT_` words inside are the elements.
  - The arrays: the switch debounce history `byte[16]`, the fuel demand timing ring `word[150]`, the cold start
    coolant thresholds, the J1939 source-address whitelist, the intake heater durations, the fuel pressure
    plausibility table, and the misfire per-slot counts and flags.
  - **The 16 words at 0x3fd0ca are eight 2-D lookup caches, one per fuel pressure setpoint table.** `word[16]` was
    tried first and rendered `x + 8`. The maps' cache is `word[2]`, and seven new `word[2]` rows are named after their
    tables. Stage 11A's comment was wrong.
  - **Not done:** `switch_input_hardware_line_cal`'s "32 words" overlap the boot kernel's time-shared words.
  - **The proof:** `array_normalize.py` + `cast_normalized_diff.py`.
- **Stage B (3588241, label-only): the CP3 M-PROP fuel metering names of `cm848_calculateFuelMeteringCommand`, from the e2m
  `HPCR_*` records.** The function's own plate called its `cam_sync_*` / `engine_sync_*` names older guesses.
  - **e2m 8B3C** aligns at 0x40913a: all 18 records land on rows, and the coil temperature estimate (gain x filtered
    resistance / 0x138 + offset, once the sample count reaches its minimum) matches three of them. It gives the
    cold / hot start temperatures, the temperature-source selectors, the tool override, and the coil resistance
    and temperature constants.
  - **The tables at 0x40915e-0x40948b**, each placed by its use: the duty-to-current curve
    (`HPCR_Current_Scaling`), the start / hot start duty curves blended by the coil temperature to preset the
    integrator, the duty pre-control map (the governor feed-forward), the maximum duty by engine speed, and the
    battery correction. The 11.45 column-5 order does not reach this layout, so it could not be walked.
  - **Also:** their lookup caches (the `engine_sync_init_state_*` words), the coil temperature ready / preset-done
    flags, and the two filters. ROM words lose the `_cal` suffix.
- **Stage C (5698e89, label-only, after a review):** stage B's scan printed only 420 of the function's 757
  lines.
  - **The current integrator preset table** (e2m 8B49 / 8B4A `HPCR_Current_Integrator_Preset_*`, by the coil
    temperature, presetting `fuel_metering_feedback_trim_integrator`) and its cache.
  - **The rest:** the three derivative gain scaling caches and `fuel_metering_coil_resistance_raw`.
  - **The plate:** its second early return is the service tool's fuel control test, not a cranking value. The
    full 8B3C +8 / +C text confirms the tool override names, and the selector code proves that 5 is the coil
    temperature.
  - **Stale text** in enums.csv, function_definitions.csv row 14, work/todo.md and these leads.
- **Closing:** the function's plate no longer calls its names older guesses (a full scan finds none).
- **Round 12 leads:**
  - **The fault status records** (`fault_status_array` / `fault_status_word_array`, 170 x 3 bytes from 0x3feb92)
    would be a packed record array, but the range overlaps the reflash kernel's data-transfer rows from 0x3fec7a
    (time-shared RAM).
  - **`HPCR_Current_Integrator_Preset_*`** (8B49 / 8B4A) and the other `HPCR_*` tables (the leak response, the
    monitor duty curves) have no row yet.

## Done, round 13 (2026-11-21, same PR; the relayed "keep going" again): the end-of-line tests and the SCI service tests

Scripts are in `session_folder/round13/`.
- **Stage A (99a8d67, label-only): the end-of-line test steps and the SCI command 0x25 service tests.**
  - **The sequencer:** `cm848_runEndOfLineTestSequence` runs seven step functions, each returning the next step.
    Their names were cold start / protection / cam sync / fault queue guesses.
    - 0 start, then 1 the output tests (engine stopped): lift pump, then the wait-to-start lamp and A/C clutch relay,
      then intake air heaters 1 and 2 one at a time.
    - 2 the intake air heater verdict: the battery voltage drop each heater causes.
    - 3 the alternator test, which cuts the field.
    - 4 the fan speed noise, 5 the misfire test, 6 the plant tester's final result.
  - **The settings:** e2m 164A `EOL_*` and 1649 `CHRY_In_Plant_*`. 0x642ee is 164A +C `EOL_EVR_Test_Time`.
  - **The SCI command 0x25 tests** (DRB 25-xx; the e2m calls them `Cmd25`). `cm848_expireSciCommand37Tests` (was
    `protectionVoltageTimeoutControl`) ends each one at its timeout.
    - 0x11 alternator field, 0x14-0x16 the 48RE solenoids, 0x24 lift pump.
    - 0x25 cylinder contribution (DRB 25-25 CylinderPerformanceTest, e2m 8C74).
    - 0x26 high pressure safety valve (DRB 25-26, e2m 8C76 / 8C77 / 8022 +1E).
    - 5-10 cut out firing-order slots 1-6 (cylinders 1 / 5 / 3 / 6 / 2 / 4): the fault cutout's bank masks 0x55 / 0xaa only fit firing order.
  - **`BYTE_003fd1ac`** is `end_of_line_test_seconds_since_engine_start`. It is time-shared with the boot kernel, and its
    boot calls keep their call override.
  - **The alternator verdict** takes the present voltage minus the snapshot in 16 bits (`subf` / `clrlwi`), so any fall
    in voltage passes.
- **Stage B (a44169f, types): three enums.**
  - `SERVICE_TOOL_TEST_STATE` (e2m '0=NOT_RUN,1=RUN,2=ABORT') on the cylinder contribution and HPSV test states.
  - `END_OF_LINE_TEST_STEP` and `END_OF_LINE_OUTPUT_TEST_STATE`.
  - The proof is `check_enum_proof3.py`, which handles byte-sized enum types: 0 functions differ beyond the
    substitutions.
- **Stage C (f951258, label-only): the record-anchored governor reference speeds.**
  - **DRB SCI 0x19 'SET RPM'** (19-7D 'SET ECM RPM 1000' = 125 x 8): `sci_set_engine_speed_request`, with its 0xe5c1
    key and a 72-pass timeout. The LSG target selection takes it as `low_speed_governor_service_speed_floor`
    (`low_speed_governor_tool_speed_request` since round 14: e2m 1496 +1C LSG_Tool_Speed).
  - **e2m block 0008** (checked in both dumps):
    - `LSG_Breakpoint_Speed` is `low_speed_governor_base_reference_speed_cal` (750 rpm).
    - `ASG_Minimum` / `_Maximum` for sets 1 and 2 (740 / 4650 rpm) and their blend
      (`cm848_blendAllSpeedGovernorReferenceSpeeds`). The old names called the minimum 'high' and the maximum
      'low'.
  - **Bit maps in the comments:** `end_of_line_test_enable_flags`, the in-plant flag bytes and
    `service_test_request_flags`.
- **Round 13 leads:**
  - **The low speed governor reference speed chain:** resolved in round 14 (below).
  - **The injector cutout markers** at 0x3fcf64 are a `word[8]` array candidate (the cancel loop reads them with
    `lhz`). The request bytes at 0x3fcf61-62 are the callback's receive buffer (stored at 0x3fcf61 + count).
  - **The ASG leftovers:** `governor_tuning_set_blend_weight` (its default is e2m 1387 +8 ASG_Droop_Flag_Trim, a
    droop-source select), `governor_speed_lower_limit*`, `governor_speed_error_input` / `_prescaled` and the
    unread set 3 (0008 +3C / +3E).
  - **`cm848_setLogicalOutputRequest()`** renders with no arguments in `cm848_setEndOfLineTestOutputRequest`,
    while its SCI callers show two: check its prototype row.
  - **The 47 '+N' offcut-label rows** in `global_variables.csv` are legacy export rows; some carry stale base names.
  - **e2m 1981 +0 `EOL_Alternator_Test_State`** (0x3fee9a) has no access in either bank.
  - **`cm848_validateWriteAuth`'s local declaration order** flips between builds of different CSVs. The DECL pattern
    of `reverse_names.py` probably does not match its array locals.

## Done, round 14 (2026-11-21, same PR; the relayed "keep going" again): the low speed governor reference speed chain

Scripts are in `session_folder/round14/`.
- **The records:** the Cummins e2m blocks lie past the end of the dumped parameter ID table, so they are aligned by
  relative offset. Every record is checked against its code use and the dump values:
  - 14EE (ROM settings) at 0x4070ee: all 32 records +0..+3E. 8C76 follows at 0x40712e, so 11.46 has no +40 / +42.
  - 1496 (RAM) at 0x40aeb2: all 16 records. +14 `LSG_Reference_Speed_State` is the source code, and +1A
    `SCI_Cmd19_Status` is round 13's 0xE5C1 key.
  - 14EF (ROM) at 0x5c4ae (it ends where 8A51 starts) and 14F0 (RAM) at 0x40aede: the LSG error terms.
  - The widths match the e2m sizes (14EE +28 and 1496 +16 are the 4-byte records).
- **Stage A (29de6d0, label-only):** 68 globals, 7 functions, the struct and 3 new rows.
  - The task `cm848_updateLowSpeedGovernorReferenceSpeed` runs the coolant temperature speed
    (`cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed`), the desired speed selection
    (`cm848_selectLowSpeedGovernorDesiredReferenceSpeed`, was `cm848_calculateProtectionSpeedLimits`) and the slew
    (`cm848_slewLowSpeedGovernorReferenceSpeed`; the `thermal_governor_*` words were its rates).
  - The struct at 0x40aec2 is `low_speed_governor_reference_t` (reference speed / no-load fuel / state / altitude
    speed).
  - The three `*_PN_Enable` flags read backwards (0 = park / neutral at rest only), so they are named
    `*_outside_park_neutral_enable`.
  - Switch 13 is e2m 1612 `AC_On_Off_Switch`.
- **Stage B (d65de3e, types):** `LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE`, from the record's own value labels (0
  COOLANT ... 12 MOVING), exactly the thirteen sources the code stores. `check_enum_proof3.py`: 0 functions differ.
- **Stage C (3307773, types):** the 0x3faf7a dword is two words: the extended idle conditions flag, and the base
  reference speed's boot copy (only the initializer writes it). EQUIVALENT with the old pieces mapped back.
- **Round 14 leads:**
  - **0x40aedc** is subtracted from the reference before droop, but its only store is 0 (`governor_speed_error_reference`;
    the droop or a throttle adjustment).
  - **The LSG PID internals** in `cm848_runLowSpeedGovernor` (`governor_speed_debounce_active_flag`,
    `governor_speed_error_prev_snapshot`, `governor_speed_low_clamp`; e2m 1064 / 1065). (Resolved in round 15.)
  - **The fuel by throttle table** of `cm848_calculateLowSpeedGovernorNoLoadFuel` (`governor_fuel_demand_axis_cal` /
    `_output_cal` at 0x40713a) has no record yet.

## Done, round 15 (2026-11-21, same PR; the relayed "keep going" again): the e2m pool above 0.2 overlap, part 1

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
    speed limit". (Done in round 16: `road_speed_governor_*` is the one vocabulary.)
  - **The engine retarder family** (e2m 1070 / 1071). Its records carry two value lists: `EB_Non_Override_Command_Source`
    1-6, and `EB_Brake_Type` 0-3 (a bitmask in this code). (Done in round 17.)
  - **Types:**
    - The AFC slew rates (e2m 11D5 +C / +10 / +14) are 4-byte records on word rows: `_fuel_demand_load_threshold_d`
      renders with an underscore. (Done in round 18: dwords.)
    - The 4D fueling caches are 4 bytes but typed `word`. (Done in round 18: word[2].)
    - The 0x40a35c dword holds `EB_Immediate_Brake` and the next record.
  - **User commanded timing** (125C +2) and the 4D timing word (103B +0): one use adds the timing like an offset, so read
    the 125C enable first. (Done in round 18: main_injection_timing_selection 2 / 3, and the enable is algorithm_enable_flags_4_cal bit 8.)
  - **`Main_Cold_Advance_Select`** (8085 +2: 0 add / 1 max wins / 2 min wins) is an enum candidate. (Done in round 18: INJECTION_TIMING_COMBINATION_MODE.)
  - **The rest of the pool:** the 0.34-0.5 band, and the 27 records with code references and no name.

## Done, round 16 (2026-11-21, same PR; the relayed "keep going" again): the cruise control / road speed governor

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
    stores; decide by a pilot. (Done in round 18: the pilot printed casts, not pieces, so it is a q16_fixed_point_t.)
  - **The engine retarder family** (e2m 1070 / 1071 / 1192), still open from round 15. 1192 +4 / +6 / +8 have no
    rows. (Done in round 17; 1192 +4 / +6 / +8 have no reader.)
  - **`DAT_0040b5c0`:** only the power-up initializer writes it (the maximum road speed trim).
  - **e2m 8A0F +C / +E / +10** (Prev_Debounced_CC_Switch_Mux / Prev_CC_Switch_Mux / Trans_Cruise_Cutoff_Request) land
    on `engine_warning_alert_flag` / `coolant_overheat_or_low_oil_pressure_flag` / `protection_fault_latch_flag`.
    It is open whether the block drifts or that family is misnamed. One reader of 0x40b214 is the PCI cruise control
    message builder, and 0x40b210 has a `_previous` twin. Read `cm848_updateEngineWarningFlags` before deciding.
  - **`governor_override_fuel_threshold_cal` (0x408e96)** is ROM, so it has a legacy `_cal`.

## Done, round 17 (2026-11-21, same PR; the relayed "keep going" again): the engine retarder request chain

Scripts are in `session_folder/round17/`.
- **The records:** the parameter ID table places e2m 1070 (RAM 0x40a352), 1071 (ROM 0x408e9a), 1192 (EEPROM) and the
  117D retarder words. Each was checked against the seven steps of `cm848_processEngineRetarderRequest`. The 20
  renamed rows with records match their e2m sizes, apart from the 0x40a35c dword, which stage C splits.
- **The vocabulary is the e2m's, and it fits the code:**
  - The **override command** is the TSC1 request: source 1 (J1939 override) or 6 (no override).
  - The **non-override command** is the lowest of the cruise permission (2), the operator switch selection (3) and
    the TSC1 limit (4). It restarts at 101 (none) each pass the allowed state is 2.
  - The **allowed state** picks between them: 0 none, 1 override only (the driver conditions hold the rest off), 2
    override or non-override. The **command level** and **command source** are the result, and the ERC1 builder maps
    the source to SPN 900 by compares.
  - The rule for the three words: `engine_retarder_*` names the brake request chain (e2m EB = engine brake) and the
    J1939 retarder words. `exhaust_brake_*` names the 48RE lockup aid and the exhaust brake switch (switch 12), and
    `variable_geometry_turbocharger_brake_*` names the VG brake. They describe one system at different layers, so they
    are not mass-renamed.
  - 'Driver' in these names is the human: the pedal / clutch / brake conditions. The e2m's hardware-driver words take
    'output' names (`EB_Driver_Level` is `engine_retarder_output_level_percent`).
  - e2m 1070 +10 / +20 and 117D +6 (a 0-255 switch sum, a 1/8192 fraction, a 0-3 switch status) do not explain
    the code's 0 / 100 values, so `engine_retarder_switch_percent` / `_2` and
    `engine_retarder_selection_percent_fault_masked` keep their code-derived names.
  - 'Request' stays only where the code means a request: the TSC1 requests and the request chain
    (`cm848_processEngineRetarderRequest`). Stage D moved the counters next to the command and the output level.
- **Stage A (9d4ddaf, label-only):** 28 globals, 2 functions and 1 field (EQUIVALENT, 30 names).
  - The seven other plates of the chain are rewritten in these words. They called the extended idle condition 'the
    road speed limit'.
  - **`algorithm_enable_flags_18_t` bit 14 is proven:** `engine_retarder_service_brake_activate_enable` (e2m
    EB_Service_Brake_Activate_Enable, was `reserved_bit_14`). While it is set, the driver conditions pass only after a
    service brake tap or with a cruise non-override command.
  - The 0x40a27c comment called the TSC1 devices primary / secondary / tertiary. They are e2m 10E6 +2's
    `J1939_CONTROL_DEVICE` codes.
- **Stage B (bd059da, types):** `ENGINE_RETARDER_COMMAND_SOURCE` (117D +8 value labels) on the three source words,
  `ENGINE_RETARDER_ALLOWED_STATE` (1070 +14), and `J1939_CONTROL_DEVICE` on `engine_retarder_j1939_control_device`.
  `check_enum_proof3.py`: 0 functions differ beyond the substitutions.
- **Stage C (833d573, types):** `engine_retarder_brake_type_t` (bit 0 exhaust brake, bit 1 VG brake; a ROM word read only with
  masks), and the 0x40a35c dword is now the word `engine_retarder_immediate_brake_flag` (one `sth` per store).
- **Stage D (label-only, after the review):**
  - `engine_retarder_command_age_counter`, `engine_retarder_output_on_delay_counter` / `_passes` (were
    `engine_retarder_request_*`).
  - `algorithm_enable_flags_41_t` bit 0 is `engine_retarder_extended_idle_enable` (was
    `engine_retarder_speed_limit_enable`). The old name came from the extended idle flag's old name,
    `governor_speed_limit_active_flag`; e2m 1496 +A is `LSG_Extended_Idle_Status`. With the flag and the bit set,
    the selection is 100 and the allowed state 2, while the active flag stays 0: the exhaust brake runs at
    extended idle (a warm-up use) without reporting braking.
- **Round 17 leads:**
  - **The service tool test points** (1070 +1A / +1C) are never written in this build, so their 1 / 2 / 3 codes are
    read from the code alone. They do not use the SPN 695 numbering: there 1 is speed control.
  - **`fuel_demand_offset_correction`** is added to the idle / PTO fueling limits, and its role is unread.
  - **The engage delay** by engine speed (1071 +C / +12 / +14) is written but has no effect: the shift block clears the
    inhibit flag first. It may be a 11.46 change.
  - **`algorithm_enable_flags_41_t.engine_retarder_extended_idle_enable`** has no e2m record yet (named from the
    code in stage D).

## Done, round 18 (2026-11-21, same PR; the relayed "keep going" again): types and the main injection timing selection

Scripts are in `session_folder/round18/`.
- **Stage A (cc6189f, types): three type leads.**
  - `cruise_pid_integrator_q16` as `q16_fixed_point_t`. A pilot build showed the dword integration lines as casts, not
    pieces, so the 12 integer-half lines read `.integer_part` and the preset's fraction clear `.fractional_part`.
  - The AFC slew rates (e2m 11D5 +C / +10 / +14) as the dwords `air_fuel_control_fueling_slew_rate_1` / `_2` / `_3`.
  - The 4D fueling caches as `word[2]`. Their second words had rows of their own, which failed inside the arrays and
    are removed.
  - Underscore warnings 24 -> 22.
- **Stage B (3d714fe, label-only): the round 15 'user commanded timing' lead.**
  - **`main_injection_timing_selection`** (was `injection_delivery_mode`; e2m 8085 +0): 0 no change, 1 calculated, 2
    the user commanded timing (e2m 125C +2, was `injection_timing_offset_cal`), 3 calculated plus the user timing.
  - **The 4D timing** (103B +0 `Four_D_Timing`, was `injection_timing_offset_map_output`) and its maps a / b. The user
    timing replaces it while `algorithm_enable_flags_4_cal` bit 8 is set. That word was `engine_mode_control_flags`;
    it is EEPROM 0x122, AENBLFLG word 4.
  - **The timing source members** follow the e2m value labels of 103B +8 `Final_Timing_State` (hex keys, shared with
    +4 `SOI_State`), checked at the stores: CRANK, USER_OVERRIDE, MISFIRE_LIMIT, COMBUSTION_MANAGER,
    EXTENDED_IDLE, COOLANT_OVERHEAT_DERATE, plus the intermediate FOUR_DIMENSIONAL_TIMING / USER_COMMANDED_TIMING.
    Two rest on more than a store: 8 is only the power-up value (stage D: `POWER_UP`, as the dump with the engine
    stopped reads 20), and 25 `COMBUSTION_REFERENCE` is the dump's value, but its storing function is a lead. They also name the limit words: the misfire timing limit (8A3D),
    the extended idle minimum (8085 +4) and the coolant overheat derate's minimum timing family.
- **Stage C (99dd717, types):** `MAIN_INJECTION_TIMING_SELECTION` and `INJECTION_TIMING_COMBINATION_MODE`, the
  `algorithm_enable_flags_4_t` bitfield (the user commanded fueling / timing enables), and five 2-D lookup caches as
  `word[2]`. Two of the caches were the `dual_axis_table_dims_t` instances, whose 'row / column counts' were the
  cached offsets, so that struct is gone.
- **Stage D (label-only, after the review):** one prefix rule for the main timing. `main_injection_timing*` names
  the final value and what describes it (its copies, selection and source; 9 rows), and `injection_timing_main_*`
  (60 rows) names its inputs, components and limits. So the misfire limit and the extended idle minimum are
  `injection_timing_main_*`, with the misfire limit's table and cache (were `injection_timing_demand_floor_*`).
  The plates of `cm848_calculateMainInjectionTiming` / `cm848_calculatePilotInjectionTimingOffset` lost the retired
  'floor / governor-limit minimum / working minimum / cold-start map' words.
- **Round 18 leads:**
  - **The cranking timing map** is e2m 105E +4 `Crank_4D_Timing`, but its tables keep
    `injection_timing_main_cold_start_*`. (Done in round 19: the map is e2m 8091-8093 `Main_SOI_Cranking_*`; 105E +4
    is the crank routine's own 4D timing output, which only its initializer writes.)
  - **Two more 'row count' caches:** `governor_adjustment_input_table_row_count` (0x3fb9da) and
    `boost_fuel_rpm_blend_table_row_count` (0x3fb9f2) look like lookup caches named as table dimensions. (Done in
    round 19.)
  - **`cm848_storeFuelDemandPreviousValues`** copies the off-nominal compensated reference (1711 +8 `CBO_SOI_Ref`)
    into `ANC_SOI` (10A4 +14) and two kernel-window words (0x3fa700 / 0x3fa702), with source 25 (e2m `CBR_SOI`). The
    ANC stage (e2m 10A4) has no names yet, and the function name is wrong. (Done in round 19.)
  - **`fuel_demand_offset_correction`** is added to the altitude derate limit (`protection_feature_flags` bit 0x80)
    and to the retarder's idle / PTO fueling limits; its source is unread.

## Done, round 19 (2026-11-21, same PR; the relayed "keep going" again): tables, sources and the ANC pass-through

Scripts are in `session_folder/round19/`.
- **Stage A (2327679, label-only):** tables named by the parameter ID table.
  - The main timing cranking map is e2m 8091-8093 `Main_SOI_Cranking_*` (was `injection_timing_main_cold_start_*`).
  - The ambient humidity table is e2m 1A98-1A9A `C_AMB_Humidity_*` (was `boost_fuel_rpm_blend_scale_*`), the table
    behind `ambient_relative_humidity`.
  - The altitude lookup's cache was named as a table dimension.
- **Stage B (e3bc815, types):**
  - `SENSOR_VALUE_SOURCE` (PRIMARY / BACKUP / DEFAULT) goes on eleven source words. Eleven e2m `*_Source` records
    share the value list '0=PRIMARY, 1=BACKUP, 2=DEFAULT', and the code stores and compares only those values.
    `barometric_altitude_source` (1921 +12) gets a row.
  - The humidity table's cache is `word[2]`.
- **Stage C (75d8c34, label-only): the ANC pass-through.**
  - The ANC timing stage (e2m 10A4, enables in 106B +8) is compiled out. A raw scan of both banks finds no access to
    0x40a04a-0x40a05d (its control, 0x40a05e, finds the three known ones), and no code tests the three ANC enable
    bits (0x1000 / 0x2000 / 0x4000 of 0x3fd5a2).
  - `cm848_passCompensatedTimingToCombustionLimits` (was `cm848_storeFuelDemandPreviousValues`) copies the
    off-nominal compensated reference into `injection_timing_combustion_limits_input`. That word was
    `injection_timing_compensated_reference_previous`; it is 10A4 +14 `ANC_SOI`, 'input to CBL'.
  - The function also sets source 25 (COMBUSTION_REFERENCE). The combustion limits step reads the word.
  - 'ANC' is not spelled out in the e2m, so the names use the role.
- **Stage D (label-only, after the review):** the siblings of stage A's map, each by its e2m record and the parameter
  ID table: the pilot timing offset cranking map (8078-807A `Pilot_SOI_Cranking_*`), the pilot quantity crank map,
  its correction and coolant factor (8D76-8D78, 806A +26, 8068 / 8069), the crank logic select (805F +22), and the
  cranking fuel pressure setpoint table and value (803F +2). They were all `*_cold_start_*`.
- **Round 19 leads:**
  - **AENBLFLG word 3:** 0x3fd5a2 `j1939_governor_feature_cal` is algorithm enable flags word 3 (e2m 106B +8):
    0x8 idle speed adjust, 0x10 PTO, 0x40 cruise control, 0x80 road speed governor, 0x400 cruise / RSG droop,
    0x1000-0x4000 ANC, 0x8000 the cruise set speed save. The code tests 0x10 / 0x40 / 0x80 / 0x100 / 0x8000 (21
    lines), so it is a bitfield struct and a rename (0x100 has no e2m name).
  - **`cm848_initialization_step_3`** is the ambient conditions module's initializer. Its filter
    (`ema_filter_state_t_003fb9f6`, coefficient `WORD_003ff07e`) is unnamed.
  - **The source enum's reach:** other `*_Source` words may use the same 0 / 1 / 2 coding without the e2m list (for
    example `egr_flow_source`). Check each one's stores before typing it.

## Done, round 20 (2026-11-22, same PR; the relayed "keep going" again): the algorithm enable flags block

Scripts are in `session_folder/round20/`.
- **The block:** e2m 106B (AENBLFLG) is the algorithm enable flags table. It is the 90-byte CRC-guarded EEPROM block
  0x118-0x171 (RAM 0x3fd59a + offset): a length word (+0) and 44 flag words, the e2m's word N at +2+2N.
  - The code reads it three ways. Most reads are masked tests of the named words.
  - The engine protection loops compute bit numbers from word 0: `(&algorithm_enable_flags_0_cal)[bit >> 4] &
    1 << (bit & 15)`, with bit = 128 + 4n + k and 420 + n. They run over one channel in this build (the fuel
    temperature derate channel at 0x597b2; the channel table ends after its 36 bytes). So they read word 8 bits 0-3
    (`Fuel_Temperature_{Fueling_Limiting, RPM_Limiting, Shutdown, Restart}_Enable`) and word 26 bit 4
    (`Fuel_Temperature_Data_Noderate_Enable`).
  - `calculateAlpha` reads words 0, 1, 12 and 19 through a pointer to word 0.
  - Nothing of these reaches word 3, so stage B's "no reader" comments and round 19's ANC claim hold.
  - Round 19's raw scanner finds only addresses built with `lis`. Word 3 has 5 such hits, but 10 functions read
    it; the others use a base register. So the ANC claim was also checked against the `.cpp`: no named, `DAT_`
    or region-loop reference reaches 0x40a04a-0x40a05d. (`sensor_channel_ram_start`, 0x40a046, is the exclusive
    end of the copied calibration region.)
- **Stage A (7117c24, label-only):** 17 words had guessed names. Word 3 was `j1939_governor_feature_cal`; the others
  were `governor_*`, `j1939_*` and `*_feature_*` guesses. Each is now `algorithm_enable_flags_<N>_cal`, with its e2m
  bits in the comment. The code agrees: word 29 0x100 is DM13, 0x20 / 0x40 the PGN 56832 resets, 0x800 the throttle
  error handler; word 28 0x400 is the J1939 input layer.
- **Stage B (516e3be, types):** `algorithm_enable_flags_3_t`, the PTO / cruise control / road speed governor / set
  speed save enables. Bit 8 has no record; its readers make the road speed governor a hard limit with no droop outside
  top gear.
- **Stage C (9c46007, label-only):**
  - `cold_delta_fuel` (0x40b22a, was `fuel_demand_offset_correction`) is e2m 8A9F `Cold_Delta_Fuel`. Its table
    (8AA0-8AA2, coolant temperature x engine speed) and `cm848_calculateColdDeltaFuel` are renamed with it. Each of
    its nine gated additions sits behind a `*_Cold_Increment_Enable` bit whose record says 'add Cold_Delta_Fuel to
    <that limit>'. This resolves round 18's note on the altitude derate limit.
  - `cm848_calculateInjectionTimingMainMisfireLimit` (was `cm848_processEngineConfigSpeedControl`).
  - The read 'guess (not proven, so reserved)' bits of the wave 11 structs 12 / 18 / 41 take their e2m names. Their
    e2m-named unread bits are named as word 3's are.
  - New rows: the length word `algorithm_enable_flags_table_length_cal` (the CRC scan starts there; it holds 70 in the
    dump, not 90) and words 7 / 8 / 11 / 26.
  - Word 11 bit 3 (`J1939_Communication_Enable`) was an unnamed `DAT_003fd5b2` that gates the J1939 transmit queues and
    the receive dispatch. The label-only proof found it. The word is 0x000b on this truck, so J1939 communication
    is enabled. Stage C's comment said 0x0000 without reading the dump; stage F corrected it.
- **Stage D (797ec46, types):** 17 more bitfield structs, on words 1, 2, 5, 6, 13, 19, 20, 21, 25, 27, 28, 29, 31, 32,
  40, 42 and 43. 117 bits are named from a matching reader, 50 from a single record, and 105 are reserved.
  Word 0 stays a word, because the loops index from it. The cold delta fuel cache is `word[2]`.
  - **Naming tiers (from the advisor):**
    - a read bit takes its record's name when the reader agrees, or its behaviour's name when there is no record;
    - an unread bit takes its record's name only when exactly one record sits on it, and each abbreviation in it is
      spelled out by that record's description, a sibling record or the repo's vocabulary: AC air conditioning
      (except word 18's `AC_Smart_Enable`, 'Smart Air Compressor'), IMT intake manifold temperature, EB engine
      retarder, WG wastegate, RSG road speed governor, AH air handling, CT coolant temperature;
    - the rest stay `reserved_bit_N`, with the record and the reader in the comment. 'SS', 'CSE', 'VGA', 'QPID',
      'OOG' and 'TVA' are never spelled out.
  - Where two records share a bit (word 19 0x200 / 0x2000), the reader picks.
  - A multi-bit e2m mask goes by its value list. Word 32's `Equivalent_Throttle_Enable` has mask 7 and 4 = ENABLE;
    the code tests 4.
  - Read bits with no record:
    - word 29 0x1000, the fuel delivery pressure byte of PGN 65263;
    - word 40 0x4000 / 0x8000, the retarder fault mask / PTO inhibit;
    - word 42 0x1000, the gear ratio torque management (the e2m's `Torque_Mgmt_GR_Enable` sits on 0x800, which
      nothing reads);
    - word 21 0x8000, kept reserved.
  - The dump fits the truck: word 40 sets `j1850_communication_enable` (the PCI bus), word 43
    `vacuum_throttle_cruise_enable` (the vacuum cruise servo) and `wastegate_solenoid_driver_enable`, and word 6
    `transmission_control_enable` (the 48RE).
- **Stage E (32df48c, label-only):** `cm848_initializeColdDeltaFuelLookupCache` (was
  `mpc555_initFuelDemandOffsetFilter`). Stage D's cache typing showed it only presets the lookup cache.
- **Stage F (16f967b, types + comments, after the advisor's review):** word 11 is
  `algorithm_enable_flags_11_t` (the proprietary / J1587 / J1922 / J1939 communication enables), the one directly
  read flags word left untyped. Its comment now gives the dump value 0x000b, and word 19 bit 7's comment no longer
  says the reader rules out its second record (the two are one enable under two names). That makes 19 bitfield
  structs this round (word 3, the 17 of stage D, word 11).
- **Methods:**
  - A "no reader" claim needs three searches:
    - the name's masked tests;
    - unnamed `DAT_` references in the range (the label-only proof found word 11's);
    - the computed and pointer reads (the engine protection loops, `calculateAlpha`).
  - A dump value goes into a comment only after it is read at the declared width. Word 11's 0x0000 was written from
    memory (it is 0x000b).
  - The scratch `refresh_enums_structs.py` replaced a field map row's old name (`reserved_bit_N`) in every struct. It
    now skips field rows, and a generic field name is renamed per struct.
- **Round 20 leads:**
  - `calculateAlpha` keeps the flags base in r4 across `cm848_calculateAlphaAltitudeDerateLatch`; the callee never
    touches r4. Ghidra joins r3:r4 into a `ulonglong` and renders the pointer as the call's result. A locked prototype
    would leave r4 undefined after the call; a fix needs a calling convention that keeps r4.
  - The PGN 65269 ambient air temperature bytes (`DAT_003faac5`) are unnamed.
  - The length word's 70 does not match the block's 90 bytes.

## Done, round 21 (2026-11-22, same PR; the relayed "keep going" again): the engine protection module

Scripts are in `session_folder/round21/`.
- **The module:** the engine protection feature (the e2m's 'EPF') runs as five round-robin tasks of
  `cm848_runFaultDerateScheduler`. Its per-channel data sits in three e2m blocks, and the channel loops step through
  each with the block's size as the stride: the configuration (112E, ROM), the state (1152, RAM) and the history (1143,
  EEPROM). This build has one channel, fuel temperature.
- **Stage A (75178dc, types):** `engine_protection_channel_configuration_t` / `_state_t` / `_history_t` (36 / 62 / 30
  bytes), the instances `fuel_temperature_engine_protection_configuration` / `_state` / `_history_cal`, and full
  prototypes for the five helpers that take them as parameters. The 62-byte state has 4-byte fields at 2-mod-4
  offsets. A pilot build of it alone showed the importer places fields at running offsets, and the loops step `+ 1`.
- **Stage B (756f2e0, types):**
  - the fault log: `engine_protection_fault_log_entry_t` (occurrence time = `key_on_hour_meter`, extreme value,
    duration) and the two EEPROM logs (e2m 10DA, 5 entries each);
  - the state's current-entry copies and log pointers;
  - the fault-log loop's three current-channel pointers;
  - the fix for stage A's five `i16` fields (see Methods).
- **Stage C (093c501, label-only):** 11 functions and 9 words:
  - the helpers, by what they do: the severity ramp, the threshold test, the restart indexes and limitation, the
    shutdown time count;
  - the loops: the over-limit durations, the restart severity, the fault logs;
  - the log helpers, which open and close an entry;
  - `hpcr_initializeEngineProtection` (was `hpcr_initFuelTemperatureSensorChannel`). Task 025 kept the old name
    because the channel it sets up is fuel temperature, and noted 'SensorChannel overclaims'. All its calls
    initialize engine protection: the derate limits, the start sequence, the protection mode, the precrank error and
    the task index;
  - the working words that were `governor_faultDerate_*` / `fault_channel_*`;
  - the override lamp flag (e2m 10B1 +19).
- **Stage D (cc49e74, tooling):** `ApplyStructures.java` maps `i16` / `sword` to short and warns when a field type is
  unknown; such a field used to become byte without a word. CM550 and CM848 build identical before and after. A
  scratch positive control (reverted) confirmed both paths: `i16` on a field rendered unchanged, and a made-up type
  printed the warning (twice: the importer looks types up in two passes).
- **Stage E (f6cecc2, types, after the review):** configuration +0x0A / +0x0C / +0x10 / +0x12 are short and the three
  threshold pointers short*. Every load is `lha`: directly in the shutdown function and the threshold test, and
  through the pointers. The e2m's NU loses to the loads. The input pointer stays `word*`, because it is read
  unsigned for the switch masks and signed for the compares. The (short) casts on those fields are gone.
- **Methods:**
  - `structure_definitions.csv` field types: the importer knows byte / word / dword / short / ushort / int / uint /
    pointer, `T*`, and the struct and enum names. Until stage D an unknown name became a byte array without a word:
    `i16`, which `global_variables.csv` uses, did. The decompiler then rendered array decays and odd computed-offset
    bases. `struct_type_fallbacks.py` lists such fields.
  - A struct stage's gate has three parts:
    - known access sites per struct, so a shifted layout fails them;
    - the changed functions stay inside the predicted set once the instance fields are rewritten back to the flat
      names;
    - the artifact counts (pieces, `extraout_`, `unaff_`, `in_r`) do not grow.
    Stage A's sites had no `i16` field, which is how its defect got through. Include one field of every type.
  - Pilot a struct with misaligned 4-byte fields alone before writing the rest.
- **Round 21 leads:**
  - The configuration flags word (+0) is tested at 0x1 / 0x2 / 0x4 / 0x8 / 0x10 / 0x20 / 0x40 / 0x100-0x800 / 0x1000.
    It has no e2m bit records, so a bitfield needs each bit named from the code.
  - `DAT_0040a78c` is cleared with the lamp flag. The module also has other unnamed working words (`DAT_003fbd20`-`26`,
    `3a`, `4e`-`58`). `governor_faultDerate_channel_bit` / `_lookup_interp_state` and their users
    (`engine_protection_derateParam_priorityApply`, `fault_initBitwiseTimerMask`,
    `governor_calculateIntegratorRpmOutput`) are still guesses.
  - e2m 10DA's engine overspeed error log (+0 / +78 / +7A).
  - The module's init chain still has guessed names. `cm848_completeEngineStartSequence` only clears the engine
    protection shutdown state; `cm848_initSensorChannelDataStructures` and `exception_resetProtectionModeState` are
    part of the module too.
  - `function_definitions.csv` `int` parameters render as `dword`. Check the prototype importer for the same kind
    of silent type mapping as the struct importer had.

## Done, round 22 (2026-11-22, same PR; the relayed "keep going" again): the engine protection leftovers

Scripts are in `session_folder/round22/`.
- **Stage A (14be183, label-only):** round 21's leads.
  - The boot / restart resets: `cm848_resetEngineProtectionShutdownState` (was `cm848_completeEngineStartSequence`;
    it is no part of an engine start), `cm848_resetEngineProtectionPrecrankState` (was
    `cm848_initSensorChannelDataStructures`), `cm848_resetEngineProtectionShutdownOverrideDetector`.
  - The override detector's words are logical switch 31's previous state and the pending request, not J1939 state.
    Task 025 had read them the same way.
  - The fault derate's J1939 torque curve (PGN 65251) adjustment: its initializer, its fuelings and speed points, its
    priority bit (1 << e2m EPF_Torque_Curve_Priority) and its lookup cache.
  - New rows: the shutdown channel recorded at power-up (`lha`), and the derate table's cache at the engine speed.
  - The configuration flags are documented bit by bit in their field comment. They are not a clean bitfield: most
    tests go through a whole word copy, with combined masks.
- **Stage B (eb3bc7e, label-only + comments, after the review):**
  - `cm848_isEngineProtectionInputMoreExtreme` (was `protection_condition_eval`) and
    `cm848_interpolateEngineProtectionSeverity` (was `threshold_value_interpolate`), now read rather than inferred.
  - The second derate cache is `fault_derate_fuel_limit_by_engine_speed_cached_axis_offset_2`, by the cache rule
    (the table base + `_2`, as with the retarder torque caches).
  - Two of stage A's comments went beyond the code read, and are corrected:
    - the torque curve plate: only the clamp-mask path keeps the minimum; the priority path sets the five fuelings;
    - the configuration flags' 0x4 / 0x8 / 0xc / 0x40: 0x4 also tracks the maximum, 0x8 the minimum, and 0x40
      also picks the fueling severity in the fault derate fuel limit.
  - `hpcr_initializeEngineProtection` is called only from `cm848_applicationMain`, so the "boot / restart" plates
    hold.
- **Closed leads:**
  - `function_definitions.csv`'s `int` maps to unsigned `dword` on purpose (`int32_t` is the signed one), and its
    `short` is an unsigned word, unlike the struct importer's. The importer says so in a comment and reports unknown
    types (`Error: Unknown type`). Write signed prototype types as `sword` / `int32_t`.
  - The 10DA engine overspeed log was already typed (`engine_overspeed_event_t[5]`). It has the fault log entry's
    shape but an unsigned value (the engine speed), so it stays a type of its own.
  - `DAT_0040a78c` only ever gets 0 (four `sth`, no load), so it stays unnamed.
- **Methods:** the scratch raw scanner (`raw_addr_scan.py`) accepted any `lis` of the base register in its 8-word
  window, not the nearest one, so it reported false hits (0x51f884 reads 0x40bd4e, not 0x3fbd4e). The round 22
  copy has two modes:
  - the default: the nearest `lis` decides, for counting real accesses;
  - `--permissive`: the old rule. It over-reports, but it cannot miss an access whose base comes from two paths
    with different `lis` values, so it is the one for "no access" claims.
  Both give the round 19 control's 3 and the ANC range's 0.
- **Round 22 leads:**
  - `DAT_0040a78c` only ever gets 0; a name needs a reader.
  - The words next to the module that belong to other code: `DAT_003fbd20`-`26` (the emission level cap, the timer
    registers, the not-to-exceed zone) and `DAT_003fbd50`-`58` (`cm848_updateGeneralEngineProtection`).

## Done, round 23 (2026-11-22, same PR; the relayed "keep going" again): the ambient module and the source enum

Scripts are in `session_folder/round23/`.
- **Stage A (0787531, label-only):**
  - The ambient conditions module (e2m 1921 / 1977, `cm848_calculateAmbientAndCompressorInletConditions`):
    - three `boost_*` words are the ambient air flow filter, its output, and the ambient air temperature estimate;
    - the unnamed filters, coefficients, tables and caches are named from the parameter ID table (1977 +2 / +A, 197A /
      197B the compressor inlet pressure drop, 197C / 1A0E / 197D the compressor inlet temperature rise);
    - the initializer is `cm848_initializeAmbientConditions`.
    This resolves round 19's lead on `cm848_initialization_step_3`'s filter.
  - The PGN 65269 payload: all five fields, from the local J1939 database (SPN 108 / 170 / 171 / 172 / 79). Only
    barometric pressure and ambient air temperature are built; the other three stay 'not available'. The ambient air
    temperature byte comes from the ambient temperature sensor, not the ambient module's estimate.
- **Stage B (e22155d, types):** `SENSOR_VALUE_SOURCE` on ten more `*_source` words. `source_scan.py` matches each
  word's e2m value list (via the parameter ID table) against every literal the code uses. `egr_flow_source`
  (PRIMARY / BACKUP only) is included; the fan and fuel metering "sources" use other value sets.
- **Stage C (bc99794, types, after the review):**
  - Stage B's scan only took `word` globals, and the ambient function still compared
    `charge_flow_estimate_terms.fresh_air_flow_source` with a bare 2 / 1. Now `exhaust_temperature_source` (`i16`)
    and the struct fields `charge_flow_estimate_terms_t.charge_flow_source` / `.fresh_air_flow_source` are
    `SENSOR_VALUE_SOURCE` too.
  - `source_scan.py` now covers every type and the struct fields, matches the value list in any order or its
    PRIMARY / BACKUP subset, and skips the dotted alias rows. Rerun, it finds 24 words typed, 8 with other value
    sets, and none left. This resolves round 19's reach lead.
  - Two comments named 0x40a1a6 by its Ghidra label (`DAT_0040a1a6`, `barometric_altitude_source` since round 19)
    and are refreshed.
- **Dead end:** the general engine protection's other reason bits. For `DAT_0040a43c` / `_43e`, no write was found
  in the `.cpp` or by the `lis` scan (two `lhz`, even in permissive mode; a base-register store would escape the
  scan), `DAT_003fbd50` / `_54` are only zeroed, and the e2m names only the state and
  its cap.
- **Round 23 leads:**
  - `algorithm_enable_flags_29_cal` bits 0 / 1 (the e2m's 'SS Ambient Advance / Derate') gate the ambient air
    temperature broadcast, a hint at what 'SS' is.
  - e2m 1977 +0 `C_AMB_Amb_Pressure_Fil_Cnst` (0x3ff074) has no row; check its users.
  - The CSV comments hold 276 Ghidra labels (`DAT_` / `WORD_` / `PTR_` / `<type>_` + address) whose address now
    has a name (`stale_ghidra_labels.py`). Some are deliberate history ('it rendered as ...'), so each hit needs a
    review; the stale-name sweeps skip these labels by design.

## Done, round 24 (2026-11-22, same PR; the relayed "keep going" again): the struct instances named after their Ghidra labels

Scripts are in `session_folder/round24/`. `apply_struct_renames.py` renames struct types, fields and the dotted alias
rows, with round 6's checks.
- **Stage A (1d84f6c, comments):** round 23's lead. 73 present-tense Ghidra labels in CSV comments became the names
  their addresses now have (`classify_labels.py`, `apply_r24a.py`). History mentions stay: 'was', 'rendered',
  'earlier note:', '#' lines and rename arrows. The proof: the `.cpp` without its comments is identical, and every
  changed CSV line differs in its comment column only.
- **Stage B (8de3cf6, label-only): the commanded throttle record.**
  - e2m 1047 lines up with the 14 words at 0x40a57a: `commanded_throttle_state_t` / `commanded_throttle_state` (was
    `fuel_demand_control_t`). Its fields are now:
    - `commanded_throttle` (was `calculated`);
    - `throttle_transition_state` (was `rate_limiter_state`; there is no rate limiter);
    - `throttle_minimum` and its confidence counter (were `throttle_based` / `rate_delta`);
    - `calculated_commanded_throttle` (was `rate_limited`);
    - the alternate throttle trio and the delta.
  - The `cm848_fuelDemand*` functions at 0x1702c-0x17af4 are the throttle validation and selection
    (`cm848_selectCommandedThrottle` ...).
  - e2m 1048 names four ROM words, and the autozero learning's three working words are renamed.
  - `governor_torque_output` (sensor channel 8) is the remote accelerator pedal (EEC2 SPN 974; task 042's lead), with
    its hand-over latch `cm848_verifyRemoteThrottleTransition`. `governor_speed_demand_limit(_prev)` are the dual
    channel pedal's demand.
  - `cm848_lookupFaultIndexByDtcCode`: the table holds P-codes, not SPNs.
  - 0x64428 is IAH_Grid_Off_Voltage_Check_Delay, and e2m 1966 names the fuel level and ECM internal temperature
    outputs.
- **Stage C (44578ee, label-only): the cam / crank sync record.**
  - e2m 819C at 0x40b80a: `cam_crank_sync_state_t` (was `engine_crank_state_t`) with `cam_sync_error_count` /
    `cam_sync_state` / `crank_sync_error_count` / `crank_sync_state`.
  - The TPU-A channel 0 handler is `mpc555_updateCrankSyncState`, and its eight state setters are named by the state
    they enter.
  - The e2m value labels (0-3) do not match the code's 0-4, so no enum. This is task 045's and round 3's lead.
- **Stage D (26dd083, label-only):**
  - `j1587_fault_count_data_cal` (e2m 1097 +C0: the active / previously active fault counts);
  - `active_dtc_cummins_fault_codes_cal` (was `fault_pending_counter_array`);
  - `boot_sci_session_state` and `reflash_transfer_state`;
  - `boot_j1939_transport_transmit_session`, with 12 fields named from the TP code (`_pad5` is the frame queue
    status);
  - `qsmcm_recram` and `system_initialization_flags`.

  The two boot structs get no `_cal`, though they sit in the mirror's range: only boot / kernel code uses them
  (`NOT_CAL` in `worklist_r24d.py`).
- **Stage E (a735961, types): the three 50-word fault bit arrays.**
  - In each array, fault n is bit n % 16 of word n / 16:
    - 0x3fe974: detected, e2m 1036 System_Error_Status_00..49;
    - 0x3fe9d8: registered;
    - 0x3fea3c: previous pass.
  - `cm848_clearDiagnosticState` clears 0x32 words of all three.
  - They are one `fault_bit_words_t` now (`faults_0_to_15` .. `faults_784_to_799`), with three `_cal` instances:
    `fault_detected_cal` / `fault_registered_cal` / `fault_previous_pass_cal`. They had been a 21-word struct named
    `system_status_flags_t` plus flat rows.
  - Each field comment names every bit from e2m 1036 (337 bits; the mask is column 11 of the labelled e2m), with its
    DTC.
  - The flat rows became dotted documentation rows. About 2100 renders now use one form.
  - The proof normalizes every fault word reference to an address token: 0 functions differ, pieces 500 -> 500.
- **Stage F (9ed041a, types):**
  - `sensor_readings_t` (slots 1-4 of `sensor_channel_filtered_output`) became four flat `<channel>_sensor_filtered`
    words like the other slots, and one cast went.
  - `throttle_fuel_enable_flag` (a dword) became `throttle_sensor_fault_flag` + `commanded_throttle_previous`, so
    pieces fell 500 -> 492.
- **A fix to stage B:** fault bits 306 / 307 (sensor channel 26) have no DTC slot. The stage B comment had read the
  ROM 0x5985a slot table as bytes; it holds u16 entries.
- **Round 24 leads:**
  - Named fault bits: e2m 1036 names 337 of the 800 bits, so `fault_bit_words_t` could hold bitfields. The monitors
    set and clear the words with `|=` / `&=` masks, which Ghidra 12.1 prints as pieces, so this is the user's call
    (as `switch_input_state_t` was).
  - `diag_clear_flags_t` (0x3fedfc, EEPROM mirror) is time-shared:
    - The application's word at +0 is the A/C pressure sensor learned flag. `cm848_controlAirConditioningClutchForDrTruck`
      sets it to 1 after `air_conditioning_pressure_learn_time` passes of channel 71 inside the learn window, and it
      gates channel 71's processing.
    - The kernel's byte at +0 is the SCI receive count, and +2 is the learned output speed / vehicle speed ratio.
    - A word typed for the application moves the pieces into the kernel's SCI code, so choose the representation
      first.
  - The executive timing records at 0x40be6a are an array of 12-byte `scheduler_task_stat_t`: `main_loop` clears them
    up to `ram_refresh_enable` and walks `scheduler_task_stat_ptr_b` by 12 a pass. To do: type the array and the two
    walking pointers, and spell out `min_time` / `max_time`.
  - The sensor channel blocks: most channel calls still pass Ghidra labels for their config / state / cache / filter
    / status. Channel 26 (ECM internal temperature) and 68 (fuel level) are identified.
  - The TouCAN A map is wrong. `mpc555_initCanController` shows that 0x307080-0x3070a7 are the module registers
    (TCNMCR 0x5000, CANCTRL0-2, PRESDIV 9, RXGMSK / RX14MSK dwords, IMASK, IFLAG), and the message buffers start at
    0x307100. The repo models 0x307080 / 90 / a0 as message buffers.
  - The kernel's response messages: `cm848_allocateDiagnosticResponseBuffer` returns 0x303056 / 0x303047, two 14-byte
    message records. Their last dword points at a status byte, not a data end, so check the type before using
    `j1939_tx_msg_t`.
  - `j1939_can_ring_buf._pad16` byte 0 is the CAN transmit ring's full flag: `mpc555_canTransmitQueuePush` sets it
    when its write pointer reaches the read pointer and returns 4 while it is set. Byte 1 is the receive ring's.
    Both bytes still render as pieces.
  - The `PROTECTION_OVERRIDE` enum (enums.csv, 0x7e / 0x7f named after their ASCII glyphs) is applied nowhere.
    `transmission_selected_gear` holds the J1939 SPN 524 coding (0x7E 1st / 0x7F 2nd ...). Since byte enums
    render, a `TRANSMISSION_SELECTED_GEAR` enum on it, `transmission_selected_gear_previous` and
    `j1939_powertrain_control_state.etc2_transmission_selected_gear` would replace the junk one.
  - Four e2m 1966 words have no row: 0x40bdc8-0x40bdce, the fuel and rail pressure sensor values and defaults.
    Nothing ties the 'Fuel_Press' value to the fuel delivery pressure channel yet.
  - Three dotted alias families keep a stale instance label: `adc_trigger_t_003024f4.*`,
    `j1939_cruise_state_t_003fee00.*` and `protection_b_state_t_003feebc.*`. Their base addresses carry flat
    names now. Check whether those struct types still exist.
  - Stage A read only its REVIEW set. Not read: the 209 hits it kept as history (classified by the words around
    them) and 29 left for review, which are dotted names, own-label openings, rename arrows and '#' lines.
    `classify_labels.py` reproduces the sets.
  - Still named with their Ghidra labels: `diag_buf_a_ctrl_t_0030305a` / `diag_buf_b_ctrl_t_0030304b` (the
    kernel response messages), `diag_clear_flags_t_003fedfc`, `scheduler_task_stat_t_0040be6a` and
    `toucan_a_mb1_t_00307090` (the TouCAN map). The two `BYTE_` holds stay on purpose.
  - Claims checked by the raw lis scan, in permissive mode:
    - the reflash transfer state (33 kernel + 9 boot accesses) and the boot SCI session (12 + 28) have no
      application access;
    - the fault arrays have 718 application accesses and none from boot or kernel code;
    - only one instruction forms 0x3fa6fc.
  - e2m 1036's two records at +0x64 (EGA / VGA valve over-temperature) fall on the registered array's word 0 here.
    This is 11.45-vs-11.46 drift, or registered bits.
  - `fault_definition_t.definition_flags` bit 0x2000 is clear in every slot, and the J1587 counts are its only test.
  - The editing-firmware-csvs skill says byte enums do not render. They do: `END_OF_LINE_OUTPUT_TEST_STATE` renders 19
    times. The skill text is left for the user.

## Done, round 25 (2026-11-22, same PR; the relayed "keep going" again): an enum and three shapes from the round 24 leads

Scripts are in `session_folder/round25/`.
- **Stage A (91a9b02, types):** `TRANSMISSION_SELECTED_GEAR`, the J1939 SPN 524 coding (one gear per bit, -125
  offset, 251 = park).
  - It types `transmission_selected_gear`, its `_previous` / `_last_valid` copies and
    `j1939_powertrain_control_state.etc2_transmission_selected_gear`.
  - Every literal they meet has a member: 54 renders, and no value renders as an OR of members.
  - The unapplied `PROTECTION_OVERRIDE` is gone; its members were named after the ASCII glyphs of 0x7e / 0x7f.
- **Stage B (930aac0, types): the TouCAN A register map.**
  - `mpc555_initCanController` proves the module registers sit at 0x307080-0x3070a7 and the message buffers at
    0x307100-0x3071ff.
  - The repo had put the module at 0x307000 (no code touches 0x307000-0x30707f) and modelled 0x307080 / 90 / a0 as
    message buffers 0-2.
  - New: `toucan_a` (`toucan_module_registers_t`, the register CSV's own mnemonics at the right base) and
    `toucan_a_message_buffers` (`toucan_message_buffer_t[16]`).
  - 31 global rows and 26 register rows went; pieces fell 492 -> 480.
- **Stage C (438b543, types): the executive frame timing (e2m 12A6).**
  - `executive_frame_timings` (`executive_frame_timing_t[40]`): one record per main loop phase.
  - Its two walking pointers are typed, so `main_loop` reads `->maximum_ticks` and so on.
  - The helpers are named, and 0x3feec0 has its row.
  - Stage C's commit message and first comment said 11 phases: a case count that missed the hex labels. `main_loop`
    has 40 phases (0-39), and record n holds phase n; stage D's commit fixed the comment.
- **Stage D (170236d, types): the boot kernel's two diagnostic response messages (0x303047 / 0x303056).**
  - They are `diagnostic_response_message_t`: the header, the data pointer and a status pointer. The last field
    points at the status byte after each record, so they are not `j1939_tx_msg_t`.
  - The status bytes are named, and the allocator returns the typed pointer.
- **Round 25 leads:**
  - The sensor channel blocks (round 24's lead, not started).
  - TouCAN B's base. The register CSV says 0x307400; no code uses TouCAN B, so nothing proves it.
  - `cm848_writeCan2ControllerTxMailbox` (boot ROM) and `cm848_writeCanControllerTxMailbox` both write TouCAN A, so
    the "Can2" looks wrong.
  - The kernel transport reads `msg_header[1].can_id` / `*(dword *)&msg_header[1].data_length`. Typed
    `diagnostic_response_message_t *`, its message parameter would make them `->data_pointer` / `->status_pointer`;
    check the callers first.
  - From round 24: `diag_clear_flags_t` (the named fault bits are done in round 27).

## Done, round 26 (2026-11-22, same PR): the peer session's cruise review of 69d6f68

The peer session passed on naming corrections from a read-only cruise review, at the user's request. Every item was
checked in the code before anything was renamed. Scripts are in `session_folder/round26/`.
- **Stage A (51ba84a, label-only): the cruise vacuum throttle actuator (`cm848_controlCruiseVacuumServo`).**
  - The Chrysler e2m blocks 8C2E (17 calibrations at 0x408daa-0x408dc9) and 8C2F (10 working words at
    0x40b64e-0x40b665) line up with its words by relative offset, and every code use matches its record.
  - So the `fuel_demand_*` / `governor_cycle_*` / `cruise_servo_*` words are `vacuum_throttle_*`: the PID gains,
    the integral clamps and reset, the duty cycle and its clamps / override, the target position (the equivalent
    throttle in cruise), the position error, the vacuum / vent PWM, the PWM period and counter, the deadband, and
    the disabled latch with its threshold, time and counter.
  - The wrong `_cal` on the ROM words went.
  - The latch (`vacuum_throttle_actuator_disabled_flag`, was `governor_cycle_active_flag`) is set on an
    accelerator pedal fault, or after `vacuum_throttle_maximum_error_time` of errors above the threshold with the
    brake off. Only the boot initializer clears it. With `vacuum_throttle_cruise_actuator_disable_mode` = 1 it gives
    cruise denied status 4.
  - Also `cruise_control_engaged_previous_flag` (0x3fb530, was `governor_override_active_prev_flag`): its only
    writer is the end of `cm848_calculateCruiseControlFueling`.
  - Also `cm848_checkCruiseSwitchLearnCondition` (0x512e70, was `governor_cruise_engage_check`): a fresh ON / OFF
    request with the switch ADC in its window, after which its caller sets `cruise_control_switches_learned_flag`.
    The rename gate bans 'press' (the e2m's abbreviation for pressure), so the name avoids it.
- **The vehicle speed path (the review's item 6, checked here):**
  - `cm848_calculateVehicleSpeed` runs unconditionally from `cm848_periodicTaskSet_canTx` and never tests
    `vehicle_speed_sensor_type_cal`. It rewrites `vehicle_speed_unfiltered` from the TPU-B sensor period (0 once the
    pulse timeout expires) and filters that into `vehicle_speed`.
  - `cm848_calculateVehicleSpeedFromOutputShaft` (in `cm848_periodicTaskSet_monitoring`) writes
    `vehicle_speed_unfiltered` from the J1939 output shaft speed only in mode 4
    (`VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO`).
  - So the filtered `vehicle_speed` never takes the mode-4 value. Only the direct readers of
    `vehicle_speed_unfiltered` can see it, depending on the task order: the drivetrain ratio, the speed sensor
    monitors, the engine / vehicle speed ratio monitor, PCI OBD, the power down delay and the transmission
    condition flags.
  - The context from the user: the truck runs an Allison LCT1000 on J1939. Transmission type 3 (48RE) is only what
    the ECM is calibrated for.
- **Not done:** the review's item 5. Its claim is that firmware/CLAUDE.md's J1939 input layer notes give the right
  outcome (no cruise code reads the CCVS switches) through the wrong mechanism: `j1939_input_signal_descriptor_table`'s
  third field is the logical switch that `cm848_evaluateJ1939InputSignalFault` sets (brake 11, clutch 15, PTO 3,
  remote PTO 19, interlock 26, the cruise / PTO set-resume fields 31). I did not verify it, and a CLAUDE.md edit
  needs the user's go-ahead rather than a peer request.

## Done, round 27 (2026-11-22, same PR): the sensor channel layer, the J1939 switch inputs, the fault bits

The user approved two open decisions ("approved", read as yes to both questions of the round 26 report): the named
fault bitfields and the firmware/CLAUDE.md J1939 note. Scripts are in `session_folder/round27/`.
- **Stage A (084a1cc, label-only): the sensor channel families.**
  - The four base functions run one 13-parameter algorithm. A machine code diff of the two periodic bodies shows Type A
    signed (lookup flags 2, `lha`, `cm848_signedFirstOrderFilter`) and Type B unsigned (flags 0, `lhz`,
    `exponentialMovingAverage`).
  - Type B also skips the threshold faults of three channels: 47 until `cruise_control_switches_learned_flag`, 71 until
    its learned flag, and 10 while `oil_pressure_switch_only_cal` is set.
  - Their names had the periodic / boot roles inverted. Now `cm848_processSignedSensorChannel` /
    `cm848_initializeSignedSensorChannel` / `cm848_processUnsignedSensorChannel` / `cm848_initializeUnsignedSensorChannel`.
  - The 63 wrappers are `cm848_process<Channel>Channel` (periodic) and `cm848_initialize<Channel>Channel` (boot).
  - 91 blocks are named by channel, among them the newly identified channels 29 (`engine_speed_sensor_supply_voltage`,
    e2m 8A1E-8A21; SV = supply voltage), 77 (`boost_pressure_absolute`, 17DB-17DE), 88 (`exhaust_throttle_position`,
    1813-1816) and 75 (`egr_valve_position`, 17CF-17D2). Channels 54 / 55's tables (e2m 81CC-81D1 Booster_Cap) were
    `injector_group_a / b_*`.
  - **Finding:** channel 88's wrapper passes the fuel temperature outputs 0x40bdd0 / 0x40bdd2 / 0x40be3a (the stack
    stores at 0x500128-0x500148). Channel 88 is disabled here (`sensor_channel_enable_bits_cal` word 5 = 0x047f), and its
    disabled path still writes its default 0x2400 and status 0x100 there each main-loop cycle (phase 25). So channels 7
    and 88 write the same three words. The dump holds channel 7's values (0x1200, status 2).
- **Stage C (04b419e, label-only + firmware/CLAUDE.md): the J1939 switch inputs.**
  - The peer session's item 5 checked out. `j1939_input_signal_descriptor_t`'s third field is `logical_switch` (was
    `fault_bit_index`). `cm848_evaluateJ1939InputSignalFault` sets / clears that switch's datalink state bit when its
    datalink-source bit is set and the J1939 priority wins.
  - The table maps the brake switch to 11, the clutch to 15, PTO on to 3, the remote PTO to 19 and the accelerator
    interlock to 26; cruise and the other inputs go to 31, the unwired switch.
  - firmware/CLAUDE.md's consumers bullet now says so: J1939 can drive the brake / clutch / PTO switches, not cruise.
- **Stage B (2eb75f6, types): one bitfield per fault in `fault_bit_words_t` words 1-49.**
  - 301 bits of words 1-49 have e2m 1036 names (the uncertain expansions checked against the bits' setters); the
    others are `fault_<n>`. Word 0's 15 named bits stay in its comment.
  - Word 0 stays the plain word `faults_0_to_15`, the base of the 200 indexed accesses.
  - The measured trade: 780 bit-name references (656 in tests, 108 in writes, 16 elsewhere) against 943 piece
    tokens. 856 of those are the set / clear writes, which Ghidra 12.1 does not fold; the other 87 are tests and
    whole-word uses.
  - The stage B commit message (2eb75f6) says 316 named bits and 674 tests / 109 writes. The right figures are 301
    (words 1-49) and 780 references: the proof's 674 counts both sides of a bit-to-bit compare.
  - A nested type per word was built and rejected (`ZPULL(...)` renders).
  - The mask-exact proof matches 1964 functions; the other 4 differ only structurally and were read by hand.
- **Round 27 leads:**
  - Word 0's 15 named bits (faults 0-4 and 6-15: the RAM image word, fuel shutoff, turbocharger wastegate driver 1,
    air fuel control low boost, fuel pressure idle, boost / sampled throttle / oil pressure high and low, HPCR OBD
    deviation) stay in its comment. The indexed accesses keep it a plain word.
  - The 72 dotted documentation rows `fault_*_cal.faults_A_to_B` in global_variables.csv name the word addresses;
    only word 0 is still a field. The importer skips them; rename or drop them with the next fault-word change.
  - The `fault_<n>` bits with unresolved e2m abbreviations: CORS (37 / 38), T2 (206-215), TAS (216 / 217), PP
    (709 / 710), Chry_Dat42 (308), the cruise SC source (146 / 147).
  - Channel 88's writes into the fuel temperature words: a calibration with channel 88 enabled would put the exhaust
    throttle position into `fuel_temperature_sensor_value`.
  - From the earlier rounds: TouCAN B's base, the "Can2" mailbox writer's name, the boot kernel transport's message
    parameter, `diag_clear_flags_t`.

## Done, round 28 (2026-11-22, same PR): the sensor-present flags, the boot CAN ring state

A peer relay started the round; the leads come from rounds 25-27. Scripts are in `session_folder/round28/`.
- **Stage A (0ec3474, label-only):**
  - Three e2m flag records whose row names had turned into readings of their effect:
    - `absolute_boost_pressure_sensor_present_flag` (11D5 +4, was `boost_is_gauge_pressure_flag`). Set,
      `cm848_calculateBoostPressure` subtracts the barometric reference; clear, the sensor's reading is the boost.
      The result is gauge boost either way; the old comment read the clear case as absolute.
    - `barometric_pressure_sensor_present_flag` (11D5 +2, was `boost_uses_barometric_pressure_flag`).
    - `two_speed_axle_switch_present_cal` (1180 +E Rear_Axle_Ratio_Switch_Present, was `two_speed_axle_enable_cal`).
    - `present_flags.py` scanned every table-resolved `*_Present` / `*_Installed` record; these were the only three
      whose row dropped the word.
  - `cm848_writeBootKernelCanTxMailbox` (was `cm848_writeCan2ControllerTxMailbox`): the boot kernel image's
    byte-for-byte copy of `cm848_writeCanControllerTxMailbox`. Both write TouCAN A (the round 25 lead).
  - `can_ring_state_t` / `boot_can_ring_state` (were `can_tx_ring_t` / `j1939_can_ring_buf`): the boot ROM and
    kernel CAN driver's transmit and receive rings. Only boot-side code uses it.
    - Its pointer fields are spelled out.
    - Five stale name-only rows inside it (`qadc_a_ccw_*`, `qadc_a_queue*_wrap_flag`) became dotted rows.
- **Stage B (c65bdd0, types):**
  - `_pad16` became `transmit_ring_full_flag` / `receive_ring_full_flag` / `reserved_18`.
  - Full prototypes for the two mailbox writers (`can_module`, `mailbox_number`, `frame_words`). Two call sites
    that rendered with two arguments now show the frame they send: the kernel's
    `mpc555_manageCan1TransmitBuffer` and the application's `mpc555_processJ1939TxBufferSend`.
  - The proof: 9 functions differ after the flag tokens. Each matches its old statements with the temps
    anonymized, apart from the frame argument (`diff_flag_users_r28b.py`).
- **Checked and closed:**
  - The 11D5 air fuel control slew rates are already dwords (the wave 15 lead).
  - TouCAN B has no code users, so nothing can prove its base.
- **Still open:** the boot kernel transport's message parameter. Typing it `diagnostic_response_message_t *` needs
  the six callers of `cm848_sendDiagServiceResponse` read for what they pass.

## Done, round 29 (2026-11-22, same PR): the transfer case low-range detector, fault bits from their setters

A peer relay started the round. Scripts are in `session_folder/round29/`.
- **Stage A (f13aca5, label-only):**
  - `opposite_words.py` scanned the e2m audit for records whose row name carries the opposite word (min / max, high /
    low, enable / disable ...). It found 29; their code uses settled each one.
  - **The transfer case low-range detector by N/V (e2m 8C5F / 8C60, "Tcase NV"):** the
    `engine_to_vehicle_speed_ratio_*` family is now `transfer_case_*`.
    - The flags: `transfer_case_low_range_flag` (was `..._high_flag`) and `transfer_case_launch_flag` (was
      `..._invalid_flag`).
    - The quantities: the N/V, its average and percent change, and the road speed.
    - The limits; the throttle limit compares `commanded_throttle` (e2m TPS).
    - The three filters and their coefficients.
    - The functions: `cm848_detectTransferCaseLowRange` / `cm848_initializeTransferCaseLowRangeFilters` (was
      `initGovernorTempTableParams`).
    - It runs only with `transmission_type_cal` 0, not in this calibration.
  - **Nine `fault_<n>` bits named from their setters or sensor channel:**
    - 57 / 58 / 59 / 60, the fuel pressure monitors (P1221 / P1222 / - / P1223);
    - 308 `engine_off_time_stuck_error` (e2m Chry_Dat42 = PCI frame 0x42's engine-off time unchanged for N key cycles);
    - 342 / 343, overspeed protection / warning;
    - 682 / 683, channel 101's VGT position sensor bits.
  - **The other hits read correctly:**
    - e2m 8C35 and 1631 name the thresholds by operating region, and the rows name them by check;
    - the misfire load is an upper bound;
    - the pedal count's "minimum" is the learned pedal minimum;
    - the cold-soak coolant limit is a maximum in the code.
- **Leads:**
  - Faults 22 / 23 (they gate an ET1 field), 179 / 180 (they gate EFL/P1 fuel delivery pressure, but which is high
    and which low is not known), 101, 410, 524 and 110 need more reading.
  - The kernel transport's message parameter.

## Done, round 30 (2026-11-22, same PR): the watchdog fueling monitor

A peer relay started the round. Scripts are in `session_folder/round30/`.
- **Stage A (82b5069, label-only):**
  - `setter_name_scan.py` flags functions whose name shares no word with the fault bits they set.
  - It found `fuel_quantity_demand_monitor`, which sets fault 388 (e2m Watchdog_Fueling_Error). It is now
    `cm848_monitorWatchdogFueling`, and its initializer `cm848_initializeWatchdogFueling`.
  - The Chrysler e2m blocks name its words, aligned by offset; each word matches its code use:
    - 8A70 at 0x40894c: the duration threshold, the error debounce, the speed threshold, the minimum duration offset;
    - 8B3B / 8B3D: the coolant allowance table.
  - Five of the words had no row.
- **Scans that found nothing to change:**
  - `unit_domain_scan.py`: rows whose name names another domain than their e2m unit. The 5 hits were e2m layout
    drift (8A2B +24, the 8C34 tail, 8A14 from +2C) and a unit oddity.
  - The setter-name scan's 9 other hits were generic or table-driven setters.
- **Leads:**
  - The EC1 (PGN 65251) payload as a struct: 28 bytes, J1939 little-endian, two instances. Its field widths need the
    base-register accesses that `xref_addr.py` does not see, so it needs a pilot build.
  - The fault bits 22 / 23 / 179 / 180 / 101 / 410 / 524 / 110.

## Done, round 31 (2026-11-22, same PR): the J1939 EC1 payload as a struct

A peer relay started the round; the lead is round 30's. Scripts are in `session_folder/round31/`.
- **Stage A (8146833, types):** `j1939_pgn65251_payload_t` is the 28-byte EC1 (PGN 65251) payload in the original
  J1939-71 layout and J1939 byte order.
  - Two instances: the payload and the send-on-change previous copy.
  - The SPN names come from the automotive `j1939_spns` table. The local Mongo `j1939` entry for 65251 holds the
    PGN 65252 Shutdown parameters.
  - Field widths follow the code's accesses: words where it reads a halfword (one unaligned, at +9), byte pairs
    where it joins two bytes, bytes for the torques and limits.
  - `cm848_sendPgn65251EngineConfiguration1OnChange` and `initializePgn65251EngineConfiguration1Buffer` read by
    field. They were `DAT_` / `ram0x` / `CONCAT11` renders. The compiler's four dword copies stay pieces.
  - Underscore renders 31 -> 23.
- **The proof:** only those two functions differ, and each access was checked against its old byte offset.

## Done, round 32 (2026-11-22, same PR): the discrete output read-back checks

A peer relay started the round. Scripts are in `session_folder/round32/`.
- **The finder:** `messy_functions.py` ranks the functions by their unnamed data renders. `cm848_mainLoopMonitor`
  was first, with 55 distinct `DAT_` labels.
- **Stage A (cad1457, labels and types):**
  - The read-back check of 11 discrete outputs: `cm848_checkDiscreteOutputReadBack` /
    `cm848_monitorDiscreteOutputReadBack` / `cm848_initializeDiscreteOutputReadBackChecks`. Before, they were
    `diag_faultMatch_outputCheck_update` / `cm848_mainLoopMonitor` / `cm848_initSensorCalibration`.
  - The check's nine parameters are named.
  - `discrete_output_read_back_counters_t` has 11 instances, and each output has a word retry count.
  - The pass count and the key-off snapshot are named.
  - Faults 146 / 147 are the cruise servo supply driver's (logical output 21, e2m 1577 Cruise_SC_Source_Driver).
  - The time-shared 0x3fd284 / 0x3fd298 are covered by named data, so their boot calls are call overrides and the
    `BYTE_` labels are gone (firmware/CLAUDE.md updated).
- **The proof:** tokens from the map, on copies with wrapped member names joined. Every function matches except the
  check (equal with its parameters renamed) and one local declaration reorder.
- **Leads, the rest of the ranking:**
  - the injection state initializers (`cm848_initializePilotInjectionQuantityState` 25 labels, `...TimingState`
    19, `...AuxiliaryInjectionQuantityState` 17, `cm848_initializeCombustionReferenceMapPointers` 21);
  - `cm848_buildPgn65249RetarderConfigurationMessage` (18; a payload like EC1);
  - `cm848_initPgn65242SoftwareIdHandler` (17), `cm848_processFaultScanLookup` (12), `cm848_sciCommand20Callback`
    (15).

## Done, round 33 (2026-11-22, same PR): the J1939 transmit status bytes and three text / configuration payloads

A peer relay started the round. Scripts are in `session_folder/round33/`.
- **Stage A (3c495a2, labels):**
  - The finding: `j1939_tx_msg_t`'s third field is the pointer to the message's status byte, not a data end pointer.
    `mpc555_sendJ1939SingleFrame` stores its result there (0 queued / 1 zero length / 4 queue full), and the
    application transport stores its session codes there. A broadcast (BAM) session, which every PF 0xFE message
    takes, writes 0x10 announced / 0x11 sending / 5 complete / 2 already active. A destination-specific (RTS / CTS)
    session writes 0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 send failed /
    8 busy. Both write 3 for a source address that is not ours.
  - The stage A commit message (and the first comments) listed only the RTS / CTS codes, although the five
    builders' messages are broadcasts; the comments were corrected in the round 33 closing fix.
  - The stage B commit message calls the cleared code units at 0x3fab40 / 0x3fab4c RAM-dump bytes that analysis
    disassembled. That is an inference: no code unit there was listed.
  - The five multi-frame builders (EC1, DM1, DM2, DM4, RC) rebuild only while its 0xf0 nibble is clear.
  - The field is `status_pointer`, the name its boot twin `diagnostic_response_message_t` already had.
  - 29 new `j1939_<message>_transmit_status` byte rows (all `lbz`; 31 status bytes with DM1's and stage B's 65259), and DM1's misnamed
    `j1939_dm1_fault_data_channel_byte` renamed.
  - `j1939_ackm_msg` is `j1939_pgn59392_tx_message`; five stale flat rows inside it are now dotted documentation
    rows.
  - The proof needed the field rename applied forward to the old `.cpp`, since the boot twin's `status_pointer`
    collides with a reverse map. One derived `PTR_` row was proof-only.
- **Stage B (20a26d2, types):**
  - The RC (PGN 65249) payload. Its byte 1 decodes against SPN 901 / 902: exhaust brake (0x14) for one retarder
    output driver, compression release brake (3) for two or more.
  - The CI (PGN 65259) payload, which covers the boot-called 0x3fab3c: the thunk became a call override.
  - The SOFT (PGN 65242) payload, plus the decimal text formatter's prototype. Its int text buffer had made a struct
    field print as a bare constant.
  - Proof: 1962 functions token-equal, 2 declaration reorders, 5 read as label-substituted diffs.
- **Leads:**
  - Round 34: the application J1939 transport's two transmit mechanisms as structs: the RTS / CTS session
    (`j1939_multiframe_tx_*`, the `ptr` / `addr` / `len` abbreviations) and the two 32-byte broadcast (BAM) session
    records at 0x3fbd74 / 0x3fbd94 (named `j1939_tp_rx_session_*`, though they transmit). 0x3fbd7c is record 0's
    advancing data pointer; its derived label `PTR_j1939_pgn65242_transmit_status_003fbd7c` only shows that the dump's
    last broadcast was the 47-byte SOFT payload (0x3fae80 + 47). Also as a struct, with `initiateJ1939TransportProtocol(j1939_tx_msg_t *msg)` and
    `mpc555_sendJ1939SingleFrame`'s parameters. They were deferred so the same functions change only once.
  - `j1939_diag_response_word_b` (0x3faddd) sits at EFL/P1 bytes 5-6 (SPN 101 crankcase pressure in J1939-71):
    check its writer.
  - The stale rows `j1939_rpm_tx_word+1` / `j1939_etc1_speed_offset_tx_word+1` (0x3faeb0-0x3faeb3).
  - The component / software identification sources in the EEPROM mirror (0x3fd653, 0x3fd69b-0x3fd6b9, 0x3fd71b)
    have no e2m records; name them once their writers are found.
  - Prototype `char` maps to `byte`, so ASCII digits print as 0x30.

## Done, round 34 (2026-11-22, same PR): the application J1939 transport's transmit sessions

A peer relay started the round. Scripts are in `session_folder/round34/`.
- **Stage A (67955cf, labels):**
  - The transport functions: `cm848_sendJ1939BroadcastDataPacket` / `cm848_sendJ1939ConnectionModeDataPackets` /
    `cm848_serviceJ1939TransportSessions` / `cm848_initializeJ1939Transport`. They were
    `j1939_transport_singleFrame_send` / `_dataFrame_bulkSend` / `phase_group_a_triggerControllerUpdates` /
    `j1939_pgn_handler_init_ec00eb00`.
  - `j1939_broadcast_no_packet_delay_flag` (was `j1939_tp_bam_session_active`). The disassembly sets it only for PF
    and PS both 0xff (PGN 65535), and it turns the 5-pass packet delay to 0.
- **Stage B (91993f0, types):**
  - `j1939_broadcast_transmit_sessions[2]` of `j1939_broadcast_transmit_session_t`: the two 32-byte broadcast
    records per source address. They were `j1939_tp_rx_session_*` and DAT_, although they only transmit.
  - Two frame buffers.
  - The packet sender reads `j1939_broadcast_transmit_sessions[param_1].packet_delay_timer`. Round 33's misleading
    `PTR_j1939_pgn65242_transmit_status_003fbd7c` is gone.
- **Stage C (44f4c9e, types):**
  - The RTS / CTS transmit session has the boot twin's 28-byte layout, and its code is the twin's. It is the
    application instance `j1939_transport_transmit_session` of `j1939_transport_transmit_session_t`.
  - The type's pointer fields are `byte*`. The prototypes are `initiateJ1939TransportProtocol(j1939_tx_msg_t *msg)`
    and `mpc555_sendJ1939SingleFrame(can_id, data_length (ushort), data, result)`.
  - Casts: `(undefined1 *)` 100 -> 80.
  - `cm848_sendDataCollectorBuffer`'s wait loop (0x10 / 0x11 / 5) confirms the broadcast codes.
  - `j1939_multiframe_tx_active` (shared with CM550) stays flat.
- **Leads (round 35):**
  - The boot session's flag / destination bytes 0x302903 / 0x302904 are misnamed `qadc_a_queue_status_1` /
    `qadc_a_active_channel_id`, and stale `qadc_a_*` rows sit inside `boot_j1939_transport_transmit_session`.
    Check CM550 for the shared names first.
  - `mpc555_sendJ1939TransportRequestToSend` takes a `j1939_msg_hdr_t *` that is really a whole message record
    (`diagnostic_response_message_t`), so it reads `msg_header[1].can_id` as the data pointer.
  - The receive session `j1939_multiframe_rx_*` (0x3fbdef-0x3fbe00) as a struct.
  - Round 33's EFL/P1 `j1939_diag_response_word_b` and the stale +1 rows at 0x3faeb0-0x3faeb3.

## Done, round 35 (2026-11-22, same PR): the boot kernel's J1939 transport and the receive session

A peer relay started the round. Scripts are in `session_folder/round35/`.
- **Stage A (fb9cccd, labels):** the boot kernel's transport state at 0x302903-0x302934 carried QADC names.
  0x302903 / 0x302904 are `boot_j1939_transport_transmit_active` / `_destination_address`, the twins of the
  application's flat bytes. Eight stale `qadc_a_*` rows inside `boot_j1939_transport_transmit_session` became dotted
  rows.
- **Stage B (ff9e247, types):**
  - Both kernels' receive session: `j1939_transport_receive_session_t` (18 bytes). The two kernels' handlers access
    it at the same offsets and widths.
  - The boot instance replaces `j1939_tp_pause_t` (whose `_pad2` word was the next packet number and the granted
    packet count) and flat `qadc_a_*` rows. The application instance replaces `j1939_multiframe_rx_*`.
  - `eeprom_block_tracking._pad2` is `failed_write_authorization_count` (`cm848_validateWriteAuth`).
  - No `_pad2` renders any more, and pieces went 1412 -> 1402.
- **Stage C (68c58e4, prototypes):**
  - The boot record senders take a `diagnostic_response_message_t *`. Their old rows made the callers pass a leftover
    r4 and an unset r5.
  - `mpc555_canTransmitQueuePush` has a prototype.
  - The diagnostic service chain takes a `j1939_rx_msg_t *`. The application transport hands it the receive record's
    tail from +8 as the received message.
  - Two widths stay dword: a 16-bit / 8-bit parameter there printed `CONCAT22` / `CONCAT31` with a phantom register
    half.
- **Leads (round 36):**
  - `cm848_sendDiagServiceResponse` (the boot twin of `cm848_sendJ1939ResponseFrame`) still takes its request as raw
    bytes.
  - Round 33's EFL/P1 `j1939_diag_response_word_b` and the stale +1 rows at 0x3faeb0-0x3faeb3.

## Done, round 36 (2026-11-22, same PR): two more payloads and the boot diagnostic request path

A peer relay started the round. Scripts are in `session_folder/round36/`.
- **Stage A (29f28c8, types):**
  - The EFL/P1 (PGN 65263) payload. The word at bytes 5-6 is SPN 101 crankcase pressure (was
    `j1939_diag_response_word_b`), and byte 3 (oil level) is never written.
  - The PGN 65504 payload: engine speed and net output torque, then the main injection timing XOR-scrambled with a
    key from the time base (`TBLr`) into bytes 5 / 6 / 8.
- **Stage B (c7d1515, prototypes):**
  - `cm848_sendDiagServiceResponse(j1939_rx_msg_t *request, dword result_code)`.
  - `cm848_dispatchDiagnosticService(j1939_rx_msg_t *request)`. Its old (service_code, data_ptr, data_length) rows
    made the boot data packet handler's call print a service code 0x2d, which was really the low byte of the receive
    session's message view 0x30292d (the disassembly: `addi r3,r31,8`).
  - `mpc555_sendJ1939TransportEndOfMessageAcknowledge(destination_address, transported_pgn)`.
- **Leads:**
  - Type `eeprom_diag_callback` / `diag_write_request_state.pending_request` as `j1939_rx_msg_t *`. They store
    requests, and four calls now cast them.
  - The next functions on `messy_functions.py`'s ranking (round 32).

## Done, round 37 (2026-11-22, same PR): 120 lookup cache words named from their own lookups

A peer relay started the round. Scripts are in `session_folder/round37/`.
- **Stage A (4775962, labels, types):** `cache_names.py` names every unnamed cache word from its interpolator calls:
  `<table>_cached_axis_offset` (word, 1-D) / `_cached_axis_offsets` (word[2], 2-D), where `<table>` is the lookup's
  data table.
  - 119 caches are named that way. By hand, 0x3fd134 is the pilot blend maps' shared 2-D cache (was
    `timing_limit_boost_blend_cached_axis_offset`, word).
  - These were the DAT_ words of the injection state initializers that led round 32's ranking.
  - `prove_caches.py` (a canonical form for the 2-D `&DAT_a` -> `name` change): every function matches apart from a
    declaration reorder and one type-only `WORD_` render.
- **Leads:**
  - Eleven caches skipped:
    - six of tables that another cache already names, which need a per-function word (one table is looked up from
      five functions). The cache that took the bare name gets renamed with its siblings;
    - three of unnamed tables (`WORD_ARRAY_00406778` / `WORD_ARRAY_0040770e` / a `PTR_` label);
    - two whose tables keep legacy names (`injection_timing_temp_corr_axis1_cal`, `safety_fuel_limit_rpm_axis_cal`):
      rename those tables first.
  - Named cache rows whose names do not match their lookups (0x3fd134 was one): an audit like `cache_names.py`
    over the named rows.

## Done, round 38 (2026-11-22, same PR): the named lookup cache rows audited

A peer relay started the round. Scripts are in `session_folder/round38/`.
- **Stage A (0333c10, labels, types):** `cache_audit.py` checks the 345 named cache rows against their own lookups.
  - 34 2-D caches typed as one word were widened to `word[2]`. Fifteen y halves that were separate rows became
    `name[1]` dotted rows; ten of them were `_y` rows, five had legacy names.
  - 24 misnamed caches now carry their own table's name: `fault_slot_state_5` / `_7`, `diag_state_group1_a` / `_c`,
    the `fuel_pressure_diagnostic_*` set, `governor_pid_init_state_*`, and the injection pulse width / pilot
    correction caches that had timing names.
  - Proof: all 1968 functions match `prove_caches.py`'s canonical form.
  - The re-audit leaves 6 width / 23 name findings, all of them skips.
- **Leads:**
  - Rename the legacy `_cal` tables, then their caches: `cylinder_event_values_*_cal`, `cylinder_seq_yend_cal`,
    `j1939_fuel_table_yend_cal`, `governor_fuel_demand_output_cal`, `engine_sync_speed_correction_values_cal`,
    `engine_event_countdown_values_cal`, `injection_timing_temp_corr_axis1_cal`, `safety_fuel_limit_rpm_axis_cal`.
  - `engine_retarder_torque_cached_axis_offset`: its lookup's data argument renders as the phantom `in_r6`, a
    prototype question.
  - The tables with several caches need per-function cache words (round 37's lead).

## Done, round 39 (2026-11-22, same PR): the `_cal` HARD list cleared

A peer relay started the round. The `auditing-cal-suffixes` skill drove it, and the scripts are in
`session_folder/round39/`. `audit_cal_suffixes.py` HARD went from 63 to 0 and SOFT from 4 to 0, so no `_cal` name is
left outside the EEPROM mirror.
- **Stage A (912c379, labels, types):** the 24 lookup tables that the auditor flagged (20 HARD at 0x40xxxx, 4 SOFT in
  Bank1 ROM), named from their own lookups in the table grammar, with 11 caches. Four caches were widened to `word[2]`
  with their y halves merged, and DAT_003fb01a gained a `word[2]` row.
  - Wrong-domain old names: the "injection timing temperature correction" map is the turbocharger corrected speed map,
    and the "J1939 fuel table" is e2m MT_Max_Torque_Map.
- **Stage B (e8faa64, labels, a type):** stage A's names checked against the ECU's parameter ID table
  (`e2m_block_addresses.py --address`). It resolves 19 of the 24.
  - Four renames:
    - `cylinder_balance_stop_compensation_*` (81B1-81B3);
    - `next_cylinder_by_crank_tooth_*` / `next_cylinder_by_cam_tooth_*` (8197 / 8198, 8195 / 8196; table b reads TPU-A
      channel 1);
    - `cam_tooth_good_window_fraction_*` (PMA = the cam wheel input);
    - `low_speed_governor_fuel_by_commanded_throttle_*` (one addend of the no-load fuel).
  - The dword `crank_sync_phase_counter` is two words: `crank_out_of_phase_count` (e2m 8194 +8) and the good window
    cache that stage A missed.
  - Stage A's comments were corrected: the expected firing revolutions lookup is a signed axis read at the literal 2,
    not a step lookup, and the fuel metering PWM unit is open (see the leads).
- **Stage C (2aa86ed, labels, types):** the last 42 HARD scalars. All 42 sit in RAM 0x3feed0-0x40a048, a copy of
  ROM 0x64aea-0x6fc62 (RAM = ROM + 0x39a3e6: all 22717 words of the running dump match; stage C's "never written"
  rested on a name regex and is now that measurement).
  - 39 are renamed from their code use, 11 of them also from their e2m record.
  - 3 only lose the `_cal` and are marked unverified.
  - The supervisor chip block was J1939-named: `supervisor_register_148` / `152` / `158` / `164` settings, the word[4]
    `supervisor_configuration_transmit_words`, `supervisor_watchdog_cycle_interval` / `_window_setting`, and the
    schedule counters (the word `j1939_tx_periodic_counter` is two byte counters).
  - `temperature_protection_*` is the park / neutral exit window, the `cruise_speed_*` rows are the
    fuel_rpm_compensated_offset clamps, and the `protection_fuel_demand_snapshot_*` rows are the pedal substitutes.
- **Proof:** every stage matches `prove_caches.py`'s canonical form for each function the type changes leave alone.
  `statement_diff.py` shows 0 differing statements in the 3 + 5 functions those changes touch.
- **Width and sign:** each of the 32 rows named from an e2m record matches the record's size (2 bytes). The one
  signed record, Expected_Firing_Revs_X_Axis, is the lookup's signed axis (flags 1); tables stay `word[N]` because
  they are passed as `word *`.
- **firmware/CLAUDE.md (factual refresh):** the "~1352 HARD" sentence now says the HARD list is empty, gives the
  ROM copy's measured range, and says 258 MISSING remain.
- **Leads:**
  - The fuel metering PWM frequency: e2m 80C2 says Hz at 1.0 per count, but TPU-B's 3.2 us tick makes it
    value / 16 Hz. Scope the output on the bench.
  - The 3 unverified rows: `governor_override_fuel_decay`, `governor_override_fuel_threshold`, `cruise_speed_target_min`.
  - `cm848_processFaultScanLookup` is the injector driver booster capacitor monitor; the function and its
    `per_cylinder_timing_*` arrays still carry guessed names.
  - The 258 MISSING (EEPROM-backed names without `_cal`); many are dotted documentation rows.
  - `safety_fuel_limit_*` and the commanded-throttle addend resolve no e2m record (the parameter ID table dump holds
    1441 of 1886 records).
  - `engine_retarder_torque_cached_axis_offset`'s phantom `in_r6` data argument.
  - `fuel_rpm_compensated_offset_upper_limit` / `_lower_limit` render under `(short)` casts: `i16` candidates.
  - `audit_cal_suffixes.py` calls RAM 0x3feed0-0x40a048 WORKING_RAM; it is the ROM copy.
  - The `auditing-cal-suffixes` skill still says "~1352 HARD"; the list is empty now.

## Done, round 40 (2026-11-22, same PR): the application's EEPROM mirror names

Two peer relays covered the round. The scripts are in `session_folder/round40/`.
- **Stage A (7f54db1, labels):** `audit_cal_suffixes.py` MISSING 258 -> 234.
  - **Which rows:** `missing_users.py` sorts the rows by who uses them; only names that application code alone uses and
    that describe the application's EEPROM value change. Every candidate went through the ECU's parameter ID table
    first, which resolves 7.
  - **Ten names change with the evidence (nine EEPROM rows and `engine_idling_flag`; 7f54db1's message said seven):**
    - the idle counters (e2m 117F +A Total_Idle_Fuel_Used: the "governed speed" flag is the low speed governor within
      50 rpm of its reference), now `lifetime_idle_*_cal` / `trip_idle_*_cal` / `engine_idling_flag`;
    - `low_speed_governor_no_load_fuel_trim_cal` (was governor_speed_target_trim: a fuel addend);
    - `feature_selection_bits_cal` (was j1939_governor_feature_byte: a scan-tool feature bitmap);
    - `eeprom_verify_retry_lifetime_total_cal`;
    - `final_fueling_state_before_shutdown_or_excess_injection_fault_cal`;
    - `exhaust_brake_switch_learned_flag_cal` (was protection_b_fault_active_flag).
  - The other 15 rows only gain `_cal` (7f54db1's message said 17), among them the VIN, `lifetime_distance_pulses_cal` and the
    0x19ce-0x19f2 counters.
  - `arrays.csv` also named the VIN; its arrays stage overrides the globals' name, so it changed too.
  - 1967 functions match the canonical form; the VIN reader differs only by whitespace.
- **Stage B (9c5414a, a type):** `feature_selection_bits_t`, five proven bits and three reserved.
  - The five tests are mask-exact (0 differing statements).
  - The SCI setting lookup's pointer temp is typed `byte *` (`local_variables.csv`), so the struct type does not spread
    there. With it, 15 raw setting addresses render as fields (each checked against its old address).
- **firmware/CLAUDE.md (name refreshes):**
  - The trip / lifetime, vehicle speed, switch, sensor channel and power take-off sections use the new names
    (`refresh_references.py`).
  - One factual fix: "+/-400 rpm ... probably idle" is +/-400 counts = 50 rpm, idle by e2m 117F +A.
- **The residual 234 MISSING:**
  - 123 documentation rows (`name[n]` / `name.field`, which can never end in `_cal`: an auditor false positive);
  - 77 boot-named rows at addresses the boot kernel uses before the application loads the mirror;
  - 10 dual-use rows;
  - 18 with no reference by name (not proof of unused);
  - 6 deferred: the region labels `eeprom_mirror` / `eeprom_checksummed_block_start`; `qadc_adc_enable_flag` and
    `fault_list_iteration_counter` without evidence; the `fault_status_array` / `_word_array` pair (needs a shape).
- **Leads:**
  - the 6 deferred rows;
  - the junk rows `sensor_validation_accum+2` (inside `lifetime_distance_pulses_cal`) and
    `sensor_validation_delta+1`;
  - the immobilizer secret key bytes under boot-time names;
  - `audit_cal_suffixes.py` could skip documentation rows.

## Done, round 41 (2026-11-22, same PR): the injector driver booster capacitor monitor

A peer relay started the round; the scripts are in `session_folder/round41/`.
- **Stage A (ea2bacd, types, labels):** `cm848_processFaultScanLookup` is `cm848_monitorInjectorDriverBoosterCapacitorVoltage`.
  - It runs for each cylinder event and checks the cylinder's capacitor (channel 54 / 55) three ways: the high
    threshold (fault 328 / 330), the low threshold (329 / 331), and the low voltage at injection count.
  - **`injector_driver_booster_capacitor_monitor_record_t[2]`** (0x5762c, 52 bytes each, decoded from the ROM) replaces
    12 loose rows; two of them were J1939-named fault numbers.
  - **`injector_driver_booster_capacitor_cylinder_record_t[8]`** (0x57694, was `calibration_constant_1`) holds the
    capacitor index and the four injector circuit faults that skip the cylinder.
  - **The RAM:** the lookup cache, the per-capacitor `word[2]` counts and the per-cylinder `word[8]` counts (were
    `per_cylinder_timing_array` / `_sync_counter` / `_timing_counter`). `injection_check_flags` is
    `injector_driver_booster_capacitor_low_voltage_mask`.
  - The initializer is `cm848_initializeInjectorDriverBoosterCapacitorMonitor` (was mpc555_initSensorCalibrationTables).
- **Proof:** `prove_records.py` maps the old raw addresses and the new struct accesses to field tokens by offset.
  - The monitor has 112 statements on each side, identical apart from its name. That proves field identity and
    statement structure: the canonical form drops the bracket indexes, the index set-up and the temp names, so it
    does not check which record or cylinder an access indexes (the index derivation reads the same in both).
  - The initializer was checked address by address.
  - The other functions match the canonical form or differ in the order of local declarations only.
- **Checks (fix commit):**
  - The parameter ID table resolves none of the new rows (absence of data). Its records for the channel config /
    state (81CB-81CF) confirm every pointer target: High_Limit / Low_Limit / Fault_Set, Raw / Unfiltered /
    User_Value.
  - Every access is word-width (`lhz` / `sth`, indexed included).
  - The low voltage check is on in this calibration and distinct from the low fault: count limit 3 at threshold 699
    raw counts, against the low fault's 705.
  - All 8 cylinder records follow the field order; records 6 / 7 are injectors 7 / 8.
  - This resolves round 39's booster capacitor monitor lead.
- **Leads:**
  - The monitor still carries decompiler temps and one goto (Readability Medium).
  - The record's spare count pointer has no reader.
  - `cylinder_event_count_max` (e2m 8194 Engine_Cylinders) keeps its name.

## Done, round 42 (2026-11-22, same PR): the fault status records, the retarder cylinder counts

A peer relay started the round; the scripts are in `session_folder/round42/`.
- **Stage A (34f1e78, a type):** `fault_status_array` (byte) and `fault_status_word_array` (word at +1) are one
  per-fault-slot status record (EEPROM 0x1710 + 3 x slot), now `fault_status_records_cal` (`fault_status_record_t`:
  `flags` byte + `status_word`).
  - **flags:** 0x10 the MIL request, 0x60 the heal cycle count, 0x0e a 3-bit count that
    `diag_faultState_severity_increment` steps, 0x80 a stored DTC. They are updated with read-modify-write masks, so
    the field stays a byte.
  - **status_word:** bit 0 is what `cm848_sciCommand51ReportActiveFaultDtcs` reports. It is clear in every slot of
    the truck's dump, the active P0483 too (slot 100: flags 0x82, status_word 0), so it is not simply "active".
    Bits 3-9 hold an age.
  - The dump agrees with the flags byte: P0483's 0x82 has the stored DTC bit.
  - **Typed at the base only:** 170 records would run across the boot kernel's time-shared structures at
    0x3fec7a-0x3fecf6.
  - **Render:** the 24 users (34f1e78's message said 22) read `(&fault_status_records_cal)[slot].flags` /
    `.status_word`.
  - **Proof:** `prove_status_records.py` gives 0 differing statements in 23 of the 24 users. In the 24th,
    `cm848_mainLoopServiceMonitor`, one pair is the same address (base + 1 + 3 x slot) written two ways.
    - It proves field identity and statement structure, not the index.
    - The first run covered only 12 users, because `prove_caches.py` prints at most 12 names; the fix commit
      re-ran it on every user.
  - This resolves round 40's deferred `fault_status_*` pair. The parameter ID table has no record at 0x3feb92
    (round 40's `app_e2m.txt`).
- **Stage B (e3b6532, labels and a local):** the retarder's six "stage weights" are e2m 13D8 Jcomm_EB_Driver_N_Num_Cyl
  (`engine_retarder_driver_N_cylinder_count`, 1 / 0 / 0 / 0 / 0 / 0). The engaged count is 13D9 Engine_Brake_On_Sum
  (`engine_retarder_cylinders_on_count`).
  - `cm848_calculateEngineRetarderTorque`'s live-in `in_r6` is the selected table (`selected_stage_torque_values`).
  - A count above 6 would read a stale r6; that is unreachable with these counts.
- **Leads:**
  - The other `fault_status_records_cal` bits: flags 0x01, status_word 0x02 / 0x04.
  - The "stage N" torque tables have no e2m record in the dump.

## Done, round 43 (2026-11-22, same PR): the main injection end timing, the junk rows

A peer relay started the round; the scripts are in `session_folder/round43/`.
- **Stage A (d8d2cdf, labels, types):** `cm848_computeFuelRpmCompensatedOffset` is `cm848_calculateMainInjectionEndTiming`.
  - It computes the main injection's end of injection timing: the start minus the pulse's crank angle.
  - Units: on-time at 0.4 us per count x engine speed at 1/8 rpm x 6 / 1e6 x 256 / 600 lands in main timing counts.
  - Its output is `main_injection_end_timing`, and its four calibrations follow (round 39's fuel_rpm_compensated_*
    names). The three signed ones (lha) are `i16`.
  - The old plate said the output had no reader; `cm848_updateOilChangeMonitor` reads it.
  - This resolves round 39's `i16` clamp lead.
- **Stage C (d0bd88c, labels):** the full e2m search names this block. The dumped parameter ID table does not reach it,
  but name, order, sign, scale and description all match the code.
  - 8B47: EOI_Default / EOI_Hydraulic_Delay / EOI_Max_Limit / EOI_Min_Limit. 8B48: EOI.
  - The pulse width addend is `main_injection_end_timing_hydraulic_delay` (uSEC, 0.4 per count).
  - The dump: default -171 = -20.04 deg, maximum 512 = 60.00 deg, minimum -171, hydraulic delay 1975 = 790 us; the
    output equals the default with the engine stopped.
  - `main_injection_timing_copy` is 103B +2 SOI.
  - So the `i16` types (default / maximum / minimum) meet both conditions of the signedness rule: a signed e2m record
    and `lha` loads. Stage A had only the loads.
- **Stage B (ef9781b, rows):** 30 junk `<name>+<N>` rows removed. They were an old export's labels for interior bytes,
  rendered nowhere. The `.cpp` differs only in local declaration order. MISSING 233 -> 221.
- **firmware/CLAUDE.md (factual refresh):** the MISSING sentence gives 221 (123 documentation, 77 boot-named, 10 dual-use,
  7 unreferenced, 4 deferred).
- **Checks (fix commit):** thunks 18 / 14 after the dotted junk rows; all four test scripts pass; CM550 uses none of
  the stage A names.
  - The round 39 / 41 fix scripts had duplicated text in this file: their edit guard let a second run re-apply an
    edit whose new text contains the old. `dedupe_task046.py` removed the copies.
- **Leads:**
  - The typed junk row `fuel_demand_enable_sync_flag_shadow+2` (`undefined2`).
  - The oil change monitor's "engine power" accumulator and increment table: keyed by the end of injection, so likely
    soot, but unproven.

## Done, round 44 (2026-11-22, same PR): round 39's unverified rows, the last typed junk row

A peer relay started the round; the scripts are in `session_folder/round44/`.
- **Stage A (a0c4d30, labels, a type):** the three rows round 39 left unverified, named from their code, and the typed
  junk row.
  - `governor_override_fuel_decay` is `all_speed_governor_vacuum_cruise_fueling_reduction`. While vacuum-throttle
    cruise is engaged, `cm848_runOperatingModeSpeedGovernor` subtracts it from `all_speed_governor_fueling`, with a
    floor of 0 (44 here).
  - `governor_override_fuel_threshold` is `cruise_accelerator_override_throttle_threshold`. On the accelerator path of
    `cm848_selectCruiseOrUserFueling`, the commanded throttle must be above it (0 here) before the operating mode
    governor takes the fueling from cruise. The function's plate named the wrong operands (`fuel_demand_control`);
    it now names the governor's fuel demand and the commanded throttle.
  - `cruise_speed_target_min` is `accelerator_pedal_single_channel_minimum_idle_threshold`. With the pedal fault
    latched, the demand stays valid only for P2127 (sensor 2, channel 98, low), and only while channel 97's learned
    idle threshold is at least this value (68; the dump holds 78).
  - The typed junk row at 0x3fb52a (`fuel_demand_enable_sync_flag_shadow+2`, `undefined2`) is
    `cruise_control_engaged_flag_previous_arbitration`, a word (lhz / sth). Its falling edge starts the cruise fuel
    ramp-down. Task 045 read it the same way.
  - 0x408e94 gets a documentation row from e2m 118F +0x0C: `cruise_out_of_gear_disable` (1 here). No instruction in
    the ROM or the live flash2 forms its address.
- **Evidence:**
  - The parameter ID table resolves none of the three rows.
  - No record sits at 107D +0x44..+0x49 or 118F +0x0D..+0x11 in any of the 68 e2m files. The search reads the offsets
    as numbers because some files zero-pad them to four digits.
  - The pedal block 0x408a72-0x408a7e lies past the dumped table. Stage A said no e2m record describes it. That was
    wrong: the search output was read through `head`, which cut it before the 8Bxx-8Cxx blocks (stage B).
  - `raw_address_scan.py` (lis + displacement over both images) finds exactly the accesses the `.cpp` shows.
    - Its first run read `cm848_flash2.bin`, which differs from the live image the build uses, and reported a false
      reader of 0x408a76.
  - The dump values agree with ROM through the copy rule.
- **Proof:** `prove_caches.py` matches all 1968 functions. The retype from `undefined2` to `word` changes no statement.
- This resolves round 39's unverified rows, round 43's typed junk row lead, and task 045's 0x3fb52a lead.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Stage B (379b0d0, labels, rows):** the uncapped search finds 14 blocks past the dumped parameter ID table that hold
  stage A's rows and their neighbours (`align_blocks.py`). Every record's description matches the code that reads
  the row. How each block is placed:
  - 11 blocks fill five gaps between dumped-table blocks exactly: 8C30; 8B12; 8B4E + 8BAC; 8B4F + 8BAD; and 8B51-8B55,
    between 8D3A's 30-byte table and 106D.
  - 8B50 / 8BAE match the EEPROM rows field by field. 8C36 ends at EEPROM 0x19a1, 16 bytes before 8B50.
  - 8B59 is placed by meaning only.
  The blocks:
  - 8C30 (6 bytes) fills 0x3ff6ca-0x3ff6cf, between 107D's last record and 107B.
    - +4 Vac_Throttle_ASG_Delta is 0x3ff6ce, now `vacuum_throttle_all_speed_governor_fueling_reduction`.
    - +0 / +2 (the driver override thresholds) get `i16` documentation rows; no instruction forms their addresses.
  - 8B12 (4 bytes) fills 0x408e96-0x408e99, between 118F and 1071.
    - +0 Cruise_Throttle_Transition_Threshold ('If throttle <= to this cal, will transition to cruise') is 0x408e96,
      now `cruise_throttle_transition_threshold`.
    - +2 Cruise_Bump_Up_Step_Adjust is `cruise_bump_up_step_margin_scale`.
  - 8B4E (12 bytes) and 8BAC (28 bytes) fill 0x408a66-0x408a8d, between 8C5F and 8C55.
    - 8BAC's 15 records line up with the 15 pedal calibration rows in order. 14 descriptions match the code-derived
      names; the 15th, +0x18 PPS_AZ_Time_Limit, shows the "total step" limit is a time limit (stage C).
    - +4 PPS_Test_Cell_Threshold_Auto_Zero ('PPS Auto_Zero threshold value if greater than is considered in test
      cell') is 0x408a76, now `accelerator_pedal_test_cell_idle_threshold`.
  - 8B4F (2 bytes) and 8BAD (14 bytes) fill 0x40b54a-0x40b559, between 8C60 and 8C56.
    - They hold the severity factor and the 9 pedal state rows, widths included (+4..+7 are bytes).
  - 8B50 (18 bytes) and 8BAE (4 bytes) fill the EEPROM rows 0x3fee34-0x3fee49.
    - They hold the oil change monitor accumulators and the learned idle thresholds (PPS1 / PPS2_Auto_Zero).
  - The oil change monitor's third accumulator is the oil soot percentage.
    - 8B4E +8 OCM_Soot_Percentage_Threshold is 2.10 % here, and 8B50 +0xA is OCM_Soot_Percentage_Since_Last_Reset.
    - The soot table 8B54 / 8B55 runs over the end of injection: 'Percentage of soot present in the engine oil
      based on 250 operating hours'.
    - The code adds table x 85048 / 900000 per pass. At the e2m's scales that is exactly 0.2 s per pass
      (900000 s = 250 h; 85048 = 0.01 / 2.351589501e-8 x 0.2).
    - The `engine_power_accumulator` names become `oil_change_monitor_soot_percentage_*`. The severity table
      (8B51-8B53) becomes `oil_change_monitor_severity_factor_by_coolant_and_rpm_*`, and its output
      `oil_change_monitor_severity_factor` (8B4F +0).
    - The tables decode with the e2m scales: coolant -50..250 F, 0..3000 rpm, factors 1.00..2.00, the end of
      injection -20.04..-5.04 deg, soot 47..0.37 %.
  - Sources:
    - The OCM blocks exist only in the older CHR_CC_11.20.13.16 / 11.25.05.07; the default 11.45.01.07 lacks them.
    - The PPS, vacuum throttle and cruise blocks are in the default.
    - 8B59 (OCM_Interval_Warning_Min_Miles, 2000 miles here) is cited by meaning only.
  - 33 rows gain citations. 0x408e94's note narrows "no code reads it" to "no direct access found". The firmware
    uses no small-data base register (r2 / r13 bases are under 0.1 % of D-form instructions), so the lis scan is
    representative.
- **Proof (stage B):** `prove_caches.py` matches 1967 of 1968 functions; `mpc555_tickTransferTimeoutAndRuntimeCounter` differs only in the order of its local declarations, and the 6 `oil_change_monitor_soot_percentage_cal._0_1_` pieces are the boot ROM's existing byte view of the time-shared 0x3fee3e.
- Stage B resolves task 042's [G4] soot table lead, round 43's "engine power" accumulator lead, and stage A's
  oil change monitor lead.
- **Leads:**
  - The time-shared oil change monitor rows keep their types. e2m 8B50 gives +0 2 bytes and +2 / +6 4 bytes; the
    rows at 0x3fee34 / 0x3fee36 / 0x3fee3a are dword / untyped / word. 0x3fee3a renders
    `_oil_change_monitor_distance_pulses_cal`. The boot ROM shares 0x3fee34-0x3fee3d.
  - `cruise_out_of_gear_disable` (e2m 118F +0x0C) is 1 in the calibration, but no direct access was found.
  - 8B13 ASG_Throttle_Reset_Allow was not searched for.
- **Stage C (6aefe56, labels):** the advisor's review of stage B.
  - `accelerator_pedal_idle_learning_total_step_limit` / `_counter` are `accelerator_pedal_idle_learning_time_limit`
    / `accelerator_pedal_idle_learning_timer`.
    - The counter increments on every 100 ms pass in which either channel's learning conditions hold, whether or
      not a step is taken.
    - Its limit is 8BAC +0x18 PPS_AZ_Time_Limit: 'Time allowed from key on for pps auto zero when auto zero
      conditions exist', 29.9 s here.
  - The PPS block is inactive in this calibration. 0x408a84 (8BAC +0x12 Accelerator_Position_Sensor_Type) is 0,
    which the e2m defines as TPS operation for the commanded throttle, so the five PPS block functions do nothing.
    The test cell comment on 0x408a76 now says so.
  - No history was lost: every `(was` note of stage B's renamed rows survives (`check_r44b_review.py`).
  - **Proof:** `prove_caches.py` matches all 1968 functions; verify byte-identical.

## Done, round 45 (2026-11-22, same PR): the table gap sweep

A peer relay started the round; the scripts are in `session_folder/round45/`.
- **Method:** round 44's tiling, made systematic.
  - `sweep_table_gaps.py` sizes every dumped parameter ID table block from its default e2m records. An axis or array
    adds its ROM byte-length word; a grid makes the extent unknown. It lists the gaps between consecutive blocks.
  - `match_gap_signatures.py` keeps the absent CHR_CC blocks, one or an ordered pair, whose record widths land on
    the CM848 rows' asm-verified widths and cover every row in the gap.
  - `rank_gap_semantics.py` ranks candidates by shared words; `show_placement.py` lays a candidate over its rows.
  - Layouts come from the default CHR_CC_11.45.01.07 first, then the nearest release. The e2m size column is
    decimal; the first run parsed it as hex.
- **Validation:** the sweep finds round 44's placement independently: one perfect match, 8B4E + 8BAC, for the
  40-byte gap. It agrees with the offset alignments of rounds 12, 14 and 26: 8B3C, 1496, 14EF and 8C2F.
- **Stage A (ee5d688, labels, rows):** six blocks, from the default e2m, each with one layout across the releases.
  - Tiled, each filling a gap between dumped-table blocks exactly:
    - 8A88 is the injector diagnostic debounce limits.
    - 8A89 + 1D41 (the only width match for its gap) is the fuel level rationality monitor (the
      `fuel_level_low_distance_*` rows) and the fuel pressure idle rationality test (the
      `fuel_pressure_sensor_plausibility_*` rows).
    - 15C7 (ROM) is the P0500 vehicle speed sensor monitor.
    - 8A7E is the oil pressure gauge and the low oil switch.
  - Anchored at the start and matched by field: 14EB, the J1939 DM13 state. Its rows already quoted its bracket codes.
  - Round 12's 8B3C: three rows gain citations.
  - Names:
    - `fuel_pressure_sensor_plausibility_maximum_governor_output` -> `fuel_pressure_sensor_plausibility_maximum_throttle`
      (FP_Idle_Throttle_Limit, %THROTTLE; the code compares `all_speed_governor_equivalent_throttle`).
    - New names in 8A7E: `engine_oil_pressure_filter_coefficient` (OPG_Pressure_Filter_Constant) and its EMA
      `engine_oil_pressure_filter_state`.
    - New rows in 8A7E: `low_oil_switch_chime_enable` and `engine_oil_pressure_default`, both read by
      `cm848_processEngineOilPressure`.
    - A documentation row: `vehicle_speed_sensor_stopped_engine_speed` (15C7 +4; no direct access found).
  - This truck runs the oil pressure switch-only path, so the sensor-path threshold (0) is unused.
  - Names kept, with the code checked:
    - `oil_pressure_switch_stuck_count_limit` (Low_Oil_Switch_Error_Time: the count runs with the engine stopped and
      no low pressure shown) and `oil_pressure_switch_fault_running_count_limit` (Low_Oil_Switch_Chime_Time).
    - `fuel_pressure_sensor_plausibility_step_limit` (FP_Idle_Time_Limit, 0.1 s; its counter is the average's sample
      count).
  - Rejected:
    - 8D04: its widths match 0x40a264, but its throttle valve actuator records land on rows the J1939 anti-theft
      handler writes.
    - 8B06: its EEPROM byte 0x34 is `eeprom_version_marker`; `feature_selection_bits_cal` is at EEPROM 0x480.
- **Coverage:** 106 gaps of 1-64 bytes between blocks of known extent. 25 have a perfect width match; this round read
  the unique ones and the word-ranked leads above 0.5. The rest, and the gaps next to grids, stay a lead.
- **Proof:** `prove_caches.py` matches 1967 of 1968 functions (the other differs only in the order of its local declarations); verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The other perfect-match gaps (many candidates each) and the 81 gaps with none.
  - The `fuel_level_low_distance_*` family (11 rows) could take the e2m's "rationality" vocabulary.
- **The user's decisions (2026-11-22):**
  - The round 27 fault bitfield exception section in `firmware/CLAUDE.md` stays as it is. The user left the call
    to me. One line cannot carry its two gotchas: word 0 stays a plain word (the base of 200 indexed accesses), and
    a nested type per word prints `ZPULL(...)`.
  - The `auditing-cal-suffixes` skill now says HARD 0 since round 39 (was "~1352"), checked by a fresh
    `audit_cal_suffixes.py` run (0 hard, 0 soft, 221 missing). Its region table now matches the auditor: the
    mirror is 0x3FD482-0x3FEEC1, and the copy window's overlapping top counts as mirror.

## Done, round 46 (2026-11-22, same PR): the gap sweep's remainder - the warning chime, rock cycle torque management

A peer relay started the round; the scripts are in `session_folder/round46/`.
- **Method:** `gap_leads.py` ranks the undecided perfect-width gaps by meaning, and lists unnamed data the `.cpp`
  reads inside gaps. Every record was read in full; a 70-character cut had hidden two descriptions.
- **Stage A (e83a3ce, labels):**
  - 8A7F (tiled) is the oil pressure gauge state.
    - OPG_Check_Gauges, OPG_Error_Count, OPG_Pressure ("Oil_Pressure - Ambient_Air_Pressure", the code) and
      OPG_Threshold_Value are cited.
    - `oil_pressure_model_unfiltered` keeps its name: the table (8A82 OPG_Threshold_Table) feeds only the
      switch-only pressure model here.
    - +2 OPG_Chime: `low_oil_pressure_derate_flag` (and `_previous`) -> `low_oil_pressure_chime_flag`. Its only
      consumer starts the warning chime; nothing derates on it.
  - 8B2D (field match, 5 / 5 records) holds the warning chime counts and the chime duration.
    - The countdown is a count x Cluster_Warning_Chime_Duration x 5 / 10 passes. The request goes out as PCI header
      0x53, byte 1, bit 5.
    - `engine_warning_alert_*` -> `warning_chime_count_*` / `warning_chime_duration` / `warning_chime_countdown` /
      `warning_chime_request_flag` (+ `_previous`).
  - 8A7C (tiled) is the transmission state; +2 / +4 / +6 are cited.
    - +0 Jcomm_Torque_Mgmt_Request: `fuel_demand_timing_enable_flag` -> `tsc1_lost_management_active_flag`.
    - It is set on a TSC1 timing fault, with fault 356 Jcomm_TSC_Lost_Fault. Its two consumers ramp the TSC1
      torque limit and require torque management.
    - **The dump has it at 1 with fault 356 detected:** the truck had flagged TSC1 as lost.
  - **Proof:** `prove_caches.py` matches all 1968 functions; verify byte-identical.
- **Stage B (3109998, labels, a row, functions):** the `park_neutral_exit_*` family is rock cycle torque management.
  - Its enable bit was already `rock_cycle_torque_management_enable`.
  - 8C49 (in the dumped table) RE_RCTM_* holds the window's enabling calibrations, 8C4A / 8C4B its transmission
    temperature dwell table, and 8A7C +8 / +A the flag and dwell timer.
  - 8C2A (a field match, 6 / 6) TC_Rock_Cycle_* holds the speed limit's calibrations: 850 rpm to the high speed
    governor, the throttle window, the maximum road speed, the ramp rate and the active-too-long time.
  - `park_neutral_exit_` -> `rock_cycle_` with every other word kept: 20 globals and 3 functions.
  - A new row: `rock_cycle_engine_speed_limit_maximum_output_shaft_speed` (8C49 +6).
  - The five state rows without a record are named by code membership, and say so. The plates keep the park / neutral
    exit trigger.
  - **Proof:** `prove_caches.py` against a copy of the old `.cpp` with the three function names changed matches all 1968 functions; verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - `engine_speed_limit_*` arbitration: source 15 is now `engine_speed_limit_rock_cycle`. The other sources may sit in
    e2m blocks too.
  - Unread gaps with unnamed reads: the thermostat monitor gap (0x409fb8, 8 addresses), ROM 0x642ce (9 addresses),
    and 0x4086c8 (`DAT_004086ca` / `DAT_004086ce`, read by the TSC1 function).
  - The remaining small perfect-width gaps (2-4 bytes, 1-2 rows) have no meaning match.

## Done, round 47 (2026-11-22, same PR): uncited table rows

A peer relay started the round; the scripts are in `session_folder/round47/`.
- **Method:**
  - `uncited_table_rows.py`: 5121 default-e2m scalar records resolve through the dumped parameter ID table, and 1295
    rows at those addresses do not cite their block.
  - `block_reliability.py`: the default e2m's layout drifts from this firmware for some blocks. A low word score only
    counts inside a block whose other rows match their records: 240 blocks are at least 70 % consistent, and they
    hold 49 outliers. Each was read against the code.
- **Stage A (54fef43, labels, a type):**
  - 0x40a336 `j1939_broadcast_enable_flag` (dword) -> `j1939_torque_and_load_not_available_flag` (word). It is 120C +6
    FSS_Torque_Load_Calculation_Flag: at 1 the EEC1 actual torque byte and the EEC2 percent load byte go out as 0xFE.
  - 0x3fad92 `j1939_dm1_spn_fmi_byte` -> `j1939_eec1_actual_engine_percent_torque_byte`; its only uses are in the
    EEC1 builder.
  - 0x40be5e `sensor_diag_default_a` -> `throttle_valve_actuator_position_sensor_fault_status` (1963 +4A).
  - **Proof:** `prove_caches.py` (the retyped word's two `._0_2_` pieces folded) matches all 1968 functions; verify byte-identical.
- **Stage B (ca0121e, labels, a split):**
  - 0x40a442 `fuel_blend_correction_inhibit_flag` (dword) is two words of 1A57: `egr_off_allowed_flag` (+0
    CHH_CBO_Off) and a new `egr_cooler_fouled_flag` (+2 CHH_EGR_Cooler_Fouled).
  - 0x3fd530 `j1939_ccvs1_switch_logic_option_cal` -> `cruise_set_accelerate_switch_select_cal` (1180 +8).
  - **Proof:** `prove_caches.py` (the split dword's six pieces folded) matches all 1968 functions; verify byte-identical.
- **Kept:**
  - `sendPgn61444ElectronicEngineController1Message` keeps its unprefixed name, shared with its CM550 twin (0x32c76).
    The first attempt renamed it, and the CM550 grep caught it.
  - Drift cases are not renamed: 8A14 / 8A2B reach into the next block's base, and 8A0F +C lands under the chime
    flag.
- refresh_references.py rewrote the old dword's name inside three texts that described its two words; the texts are
  restored (`fix_r47b_texts.py`).
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The other 44 outliers in consistent blocks; most are wording differences, and the code would settle the rest.
    Candidates: 1070 +20 EB_Active_Driver_Fraction (its scale disagrees with the 0 / 100 the code writes), 10E3 +24 /
    +26 under two OBD names, 1226 +E, 8C34 +14, 1982 +A.
  - The 1295 uncited rows could take citations in bulk wherever their record matches.
  - 138 function names lack a firmware prefix. Many are shared with CM550 by design, so a sweep must rename both
    firmwares or keep the name.

## Done, round 48 (2026-11-22, same PR): the OBD cooling monitors

A peer relay started the round; the scripts are in `session_folder/round48/`.
- **Stage A (8f0019c, labels, rows, types):** two leads from the unread gaps are the two cooling system monitors.
  - **The thermostat monitor (P0128).**
    - 8A8B (22 bytes, tiled between 1901 and 18F1) holds its calibrations. Three records match the rows named from
      code; the other eight are the eight unnamed addresses `cm848_runThermostatMonitor` reads, and they gain names.
    - 8A8C (anchored at its end by 18F0; 11 / 13 records land on named rows) holds its state: two new rows, and three
      `cssc_*` rows renamed into `thermostat_monitor_*`.
  - **The coolant temperature in-range (CTIR) monitor.**
    - 8A9D (20 bytes, tiled into the ROM gap between 1631 and 164A) holds its calibrations: nine new rows, one renamed
      into the family. The test timer's limit `DAT_000642d8` is +A CTIR_Max_Test_Time.
    - 8A9E (+0..+4, a field match) holds its state. `cssc_coolant_monitoring_cycle_count` ->
      `coolant_temperature_sensor_performance_test_timer`.
    - The dumped table's 1632 +4 BIR_Ratio at 0x40b9a2 is drift.
  - **Types:** every signed record is loaded with `lha` and every unsigned one with `lhz`, so the signed ones are
    `i16`. The thermostat calibrations +4 / +6 / +8 are retyped by the same rule.
  - `cssc_` was an invented abbreviation; no row carries it now.
- **Proof:** `prove_caches.py` on copies with the scalar casts stripped matches all 1968 functions (2 differ only in local declaration order; unstripped, the three thermostat functions differ only in casts); verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The 8A8C / 8A9E state rows still use `word` where the e2m record is signed. Their loads are `lha`, but some are
    pointer-passed (`addi`), so each needs the parameter type checked.
  - The 44 remaining round 47 outliers; the 138 unprefixed function names.

## Done, round 49 (2026-11-22, same PR): unnamed data the code reads, named from table-resolved records

A peer relay started the round; the scripts are in `session_folder/round49/`.
- **Method:** `unnamed_table_reads.py`.
  - The `.cpp` reads 411 unnamed addresses; 34 resolve through the dumped parameter ID table to a default-e2m scalar
    record.
  - Each is graded by its block's consistency, and each access width was checked with `raw_address_scan.py`.
- **Stage A (762fc7a, rows, a rename):** 33 rows in their blocks' naming style.
  - Groups: the J1939 torque curve's derated points, the duty cycle monitor, the compressor inlet and coolant states,
    the temperature headroom cap's exhaust limit, the injector continuous recharge interval, four intake air heater
    calibrations, the altitude derate's charge pressure bitmap, engine protection's ramp rate and maximum shutdowns,
    the J1939 NAMEs / security flags / DM4 / fault 111 data, the MIL bitmap, the fault code assignment table, the SCI
    data plate, and the per-cylinder injector maps.
  - Array-sized records reached only by `addi` get a row at their base, with the e2m size in the comment.
  - `fuel_demand_mode_active_flag` -> `charge_saturation_temperature_source` (1982 +A); the new
    `exhaust_saturation_temperature_source` (+C) copies it. This resolves round 47's 1982 +A outlier.
  - Skipped: 0x4086ca (8A14 +30 reaches past 8A2A's base: drift).
- **Proof:** `prove_caches.py` with the scalar casts and two char literals folded matches 1967 of 1968 functions (the other differs only in local declaration order); verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - Full array types for the base-only rows: the NAMEs, the MIL bitmap, the fault code table and the cylinder maps.
    The SCI data plate and the fault code table hold rows inside them.
  - The other 377 unnamed reads do not resolve through the dumped table.

## Done, round 50 (2026-11-22, same PR): gaps by access signature - the TSC1-lost counter, the throttle threshold

A peer relay started the round; the scripts are in `session_folder/round50/`.
- **Method:** `gap_access_signatures.py` matches each gap by access signature. Every load and store inside it (raw
  lis + displacement scan) must land on a record of its width, with `lha` / `lhz` agreeing with the record's sign.
  Only four gaps still hold unnamed reads.
- **Stage A (316e46c, labels, rows):**
  - 8A7B (tiled between 8A2A and 8C49) holds the TSC1-lost counter's calibrations ("PTP mode" = the backup powertrain
    protection).
    - The counter, its reload and threshold, and its intermittent count join the `tsc1_lost_*` family:
      `tsc1_lost_counter`, `tsc1_lost_time_limit`, `tsc1_lost_intermittent_time_limit`,
      `tsc1_lost_intermittent_count`.
    - New rows: `tsc1_lost_counter_initial_value`, `tsc1_lost_maximum_intermittent_count`, and the documentation row
      `park_neutral_status_from_pci_message_0e_enable`.
  - 1585 (tiled between 1052 and 1034) is Throttle_Diff_Threshold: a new `i16` row,
    `commanded_throttle_difference_threshold`, where the commanded throttle filter ends a transient.
- **Proof:** `prove_caches.py` with the casts folded matches 1965 of 1968 functions (the other three differ only in local declaration order); verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:** the two large gaps with unnamed reads (0x408d38 +62, 0x40b592 +52) have no one- or two-block fit; they may
  hold three or more blocks. (Round 51: 0x408d38 is four blocks; 0x40b592 starts with 8BB6.)

## Done, round 51 (2026-11-22, same PR): the 0x408d38 gap is four blocks, the trip information blocks

A peer relay started the round; the scripts are in `session_folder/round51/`.
- **Round 50's lead, answered:**
  - The 62-byte gap 0x408d38 is four absent blocks back to back: 8B9B 16 + 8C2C 24 + 8BB2 20 + 8B6B 2. No search
    of three blocks or fewer could find it. `split_gap_debug.py` (fix one block, test the rest) and `pair_fill.py`
    found it.
  - The 0x40b592 gap was misread. Its first 22 bytes are 8BB6 (the governor pressure PID, placed in an earlier round
    over 8C34's drifting tail). The rest, 0x40b5a8 +30, has 9816 width-consistent covers of up to three blocks
    (`scored_cover.py`, sign scored instead of rejected), none of them meaningful. A working-RAM span needs a
    semantic anchor, not width alone.
- **Stage A (c2a1175, labels and rows):**
  - 8B9B: the transmission temperature defaults and their limp-in delay, in the e2m's vocabulary
    (`transmission_temperature_limp_in_delay_*`, `transmission_temperature_default_during / after_limp_in_delay`,
    the RAM `transmission_temperature_limp_in_delay_timer`).
  - 8C2C (12 records on 12 rows): `transmission_temperature_rationality_maximum_test_time` (was a "minimum driving
    passes"), the start test's transmission limit, and the minimum engine-off time joining the `_rationality_`
    family.
  - 8C2D (RAM 0x40b626): `transmission_temperature_rationality_test_timer`.
  - 8BB2: `transmission_output_speed_minimum` (was `_floor`).
  - 8B6B: a new row, `trip_information_fault_minimum_time`, chosen by its use since 32 blocks fit the 2 bytes.
  - 8B6D (EEPROM mirror 0x3fee58, nine records on nine rows): `trip_information_distance_fault_status_cal` (+C) and
    `trip_information_fault_status_cal` (+E). The e2m's TI_Fault_Period says the delayed fault goes in +E; the code
    puts it in +C.
  - 8B6C (RAM 0x40b638): five rows cited, plus the documentation row `pci_transmit_message_11_fuel_used`.
  - `sensorDiagnosticsConfiguration` -> `cm848_flagTripInformationPowerDownDataLoss`.
  - The stale 8C34 +12 citation at 0x40b58c is dropped. 8C34's +12..+17 records start with CHR_CC 11.25.05.07.
- **Stage B (0604834, types):**
  - Three i16 rows. They change no rendered line.
  - `TRANSMISSION_TEMPERATURE_RATIONALITY_STATE`: members 0-4 from 8C2D's labels, plus the check's own verdict
    states 5 / 6. The shared `DIAGNOSTIC_MONITOR_STATE` rendered 5 and 6 as `ABORTED|RUNNING` / `ABORTED|PASSED`.
  - A void (void) prototype that removes the 0x30d4 argument the decompiler showed at the call.
- **Bitfield structs: built and rejected (not shipped).**
  - The build changed only the two writer functions and rendered 0 field names on the 14 masks. Every access is a
    whole-word `ori` / `andi` write; nothing tests a bit. Each mask line just gained a
    `(trip_information_*_t)(...)` cast.
  - Both words stay `word`, with every bit spelled out in their row comments.
  - The script is `apply_r51c_bitfield_structs_rejected.py` (log `verify_r51c_bitfield_structs.log`), so the user can
    overrule this in one line.
- **Closing:** the flag function has one call site, a bl at 0x54de0 in `cm848_restartApplicationWithoutReset`
  (`find_branch_callers.py`). `cm848_applicationMain` falls through into that code from 0x54d2c, so both
  decompilations show it. The 0x30d4 is 12500 from `li r3,12500 / mtdec r3`, the decrementer reload. Stage A's plate
  ("cm848_applicationMain twice") and stage B's "two calls" were wrong; the plate and the prototype comment are fixed.
- **Proof:** stage A: `prove_caches.py` (casts folded, the function rename applied to the old .cpp) matches 1967 of 1968 functions, the other differing only in local declaration order; stage B: 1962 match and the six others equal the old text once each enum member value is put back and the removed argument dropped (`prove_r51b_enum.py`); closing: no function body differs, only the flag function plate. Every verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - **User call, untested:** a flag enum (power-of-two members) on the two trip information words might render
    `| TRIP_INFORMATION_TRIP_FUEL_USED_OVERFLOW` where the bitfields render nothing. Ghidra already split stage B's
    whole-value constants into member combinations. firmware/CLAUDE.md allows an enum type only for whole-value
    compares, so it was not tried.
  - 0x40b5a8 +30 (vehicle speed state, the rock cycle phase, the road speed governor references, unnamed 0x40b5c0)
    needs a semantic anchor.
  - `initGovernorFlagsAux` only zeroes 0x3fcfba (in the trip counter RAM, never read directly): misnamed, but nothing
    says what the word is.
  - The rest of the transmission RAM 0x40b620-0x40b637 (the OSS period / speed words, 8BB4 / 8BB5?) is untiled.

## Done, round 52 (2026-11-23, same PR): nine more blocks record for record, five state enums

A peer relay started the round; the scripts are in `session_folder/round52/`.
- **Method:** `record_for_record_matches.py`.
  - For every absent block, it tries each base that puts the block's first or second record on an existing row, and
    counts records that land on a row start of the same width.
  - A base is rejected if any record lands inside a row, on a row of another width, or in a span already citing an
    e2m block.
  - The mixed-width hits were read by meaning.
  - Dense all-word areas match any all-word block at every even offset, so width alone is only a filter.
- **Stage A (61be5e0, labels, rows, comments):**
  - 8B23 (92 records) and 8A5F (46): the cooling fan and EVR / alternator field calibrations, on their code-named
    rows.
  - 8B22 (30) and 8A60 (21): their RAM.
  - 8B21 (11): the radiator fan speed sensor. It joins the transmission's 8BB2 vocabulary
    (`radiator_fan_speed_maximum / _minimum / _period_*`, `radiator_fan_pulses_per_revolution`, which was a
    "prescaler").
  - 15B4 (7): the reset capture. The exception stubs move SRR0 / a vector byte / LR into SPRG0-2, so the rows become
    `exception_srr0 / _vector / _link_register`. `hardware_timer_capture` becomes
    `power_on_reset_to_first_executive_frame_time`.
  - 8B9A / 8BB4: the rest of round 51's transmission RAM, now four blocks back to back at 0x40b620. Round 51's "no
    RAM record" for the limp-in timer was wrong.
  - The governor pressure solenoid's retest records (8BB5 +50 / +52, 8BB6 +1A) get documentation rows. Nothing reads
    them: unlike the fan and EVR drivers, this one only latches.
  - 8BB3 is cited on the learned output-speed-to-vehicle-speed ratio.
  - The e2m splits long value-label lists over duplicate records; the citations merge them.
- **Stage B (afe344d, enums):** five state enums from those labels, each member read against its storing branch:
  - `COOLING_FAN_COOLANT_REQUEST_STATE`, `COOLING_FAN_SPEED_TARGET_SOURCE` (16), `COOLING_FAN_DUTY_SOURCE` (12);
  - `ALTERNATOR_FIELD_REGULATOR_STATE` (on the state and its previous-state copy);
  - `ALTERNATOR_FIELD_LOAD_RESPONSE_STAGE`.
- **Proof:** stage A: `prove_caches.py` (casts folded) shows no function differing once the old labels map to the new; stage B: 1958 of 1968 functions match and the ten others equal the old text once each enum member value is put back (`prove_enum_substitution.py`). Every verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The matcher's all-word hits (343 of 433) are unreviewed and need a by-meaning pass.
  - The alternator field regulator's state handlers (the table at 0x57730) return the next state and could return the
    enum.

## Done, round 53 (2026-11-23, same PR): blocks ranked by meaning, the coolant temperature derate module

A peer relay started the round; the scripts are in `session_folder/round53/`.
- **Method:** `semantic_record_matches.py` is round 52's matcher ranked by a meaning score.
  - `semantic_score.py` expands the e2m abbreviations and scores the record name and description against the row name.
  - The score ranks, it does not decide: 8A71's best-scoring base was wrong. The true base, 0x40874e, fits all 16
    records, with every access's width and sign matching its record.
  - `e2m_cite.py` shares the citation helpers the stage scripts used to copy.
- **Stage A (dfd604c, labels, rows):** eleven blocks:
  - the fan speed sensor RAM (8B20);
  - the PTO / battery voltage flags and their calibrations (160A / 1609);
  - the sensor-fault substitutes and the in-use values (8B03 / 8B04). The eight substitutes are now named by the fault
    that selects them (`<sensor>_high_fault_substitute`), because the temperature pair went by value;
  - the learned ratio limits (8BB1);
  - the gear ratio margin and the rail-leak limit (8B8A, a new row);
  - the J1850 received data (8A7D, `pci_four_wheel_drive_status_flag`);
  - the brake switch pair (8A86);
  - the vehicle speed words (8ADA), which anchor round 51's 0x40b5a8 lead;
  - the VSS calibrations (8ADB) and the transfer case learning (8B0B).
- **Stage B (c1ba0fe, labels, rows):** the coolant temperature derate module (CT_Derate: 8A71 / 8A7A / 8A79 / 8A72).
  - The minimum derate (fault 390), the aggressive derate (fault 389) with its five level timers, the PI loop, and the
    check gauges / chime requests.
  - About 20 `cold_start_*` / `*bucket*` names became `coolant_overheat_*`, plus 7 new rows and 3 function renames
    (`cm848_monitorCoolantOverheatMinimumDerate` / `...AggressiveDerate`, `cm848_accumulateCoolantOverheatLevelTimers`).
  - `coolant_overheat_temp_threshold` used the banned abbreviation "temp".
- **Proof:** stage A: `prove_caches.py` (casts folded) shows no function differing once the old labels map to the new; stage B: 1966 of 1968 match, the other two only show the new axis table row in place of a raw pointer / DAT_ label (read by hand). Every verify byte-identical.
- **firmware/CLAUDE.md:** one factual correction, no new rule. The read-back bullet called the 0x5139b8 helpers
  "unidentified"; they are the coolant temperature derate. HARD stays 0 and MISSING 221.
- **Leads:**
  - The lifetime level-timer totals (8A73, EEPROM mirror 0x3fee04 + 4 x level) overlap the boot kernel's
    `eeprom_shadow_header`, so they stay untyped. This is the same time-sharing problem as the trip distance dword.
  - The matcher's other hits read by meaning but not applied: 1497 / 1498 (LSG droop on ASG-named rows), 158D, 8BA4.
  - 8B7C (AFR) exists only in older layouts.

## Done, round 54 (2026-11-23, same PR): the last unnamed tables, the stack monitor, legacy boot functions

A peer relay started the round; the scripts are in `session_folder/round54/`.
- **Round 53's disputed matcher hits stay rejected.** Read by meaning, every one contradicts its rows:
  - 8BA4 is a sensor-channel config, but the rows hold temperatures in deg F;
  - 158D would put a reset flag on a word that holds 27136;
  - 1497 / 1498 would put low speed governor droop slopes on code-proven words.
- **Stage A (b53080a, labels, rows, plates):**
  - The ten tables the 2026-11-16 campaign left `WORD_ARRAY_` are named: nine through the parameter ID table
    (turbocharger speed linearization, EGR orifice temperature lead time constant, turbocharger speed derate gain,
    torque management fuel grid) and one lookup cache. No `WORD_ARRAY_` table is left.
  - The application stack (RAM 0x3f9800-0x3f9ff8, r1 = 0x3f9ff8) has a high-water monitor, `cm848_updateStackHighWaterMark`
    (was `bufferManagementWithBounds`, read as a message buffer); its new `stack_headroom_factor_tenths` is 27 in the dump.
  - `cm848_initializeLifetimeDistanceRecordIndex` (was `initSensorTableIndexing`).
  - `test_disasm_tools.py` needed an unnamed table to test the xref tool and none is left; it falls back to a
    type-only word row.
- **Stage B (66af83f):**
  - Five boot-time functions named from their bodies: the rail pressure shortfall limit, the engine oil pressure
    processing, the oil change monitor lookups, the EEPROM calibration identifier update, and the OBD-II service state.
  - The calibration ID characters 4-9 (EEPROM 0x4a-0x4f) are the `byte[6]` row
    `calibration_identifier_characters_4_to_9_cal`.
- **Proof:** stage A: `prove_caches.py` (casts folded, function renames applied to the old .cpp) matches 1966 of 1968 functions, the other two differing only in local declaration order; stage B: 1964 match, two more order-only, and the last two only show the new calibration ID array row (read by hand). Every verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 98 unprefixed CM848-only functions remain, 46 with no plate (`list_unprefixed.py`). The fault manager core at
    0x533aec-0x535270 and the protection cluster at 0x514048-0x514394 are the largest groups; reviewing them all
    is an agent-sized job.
  - `initGovernorFlagsAux` only zeroes 0x3fcfba, which nothing reads directly.

## Done, round 55 (2026-11-23, same PR): the fault manager core named from its code

A peer relay started the round; the scripts are in `session_folder/round55/`.
- **Stage A (c4ebb04, function names and plates):** the fault manager at 0x533aec-0x535344, read function by function
  (`function_summary.py` lists a range's functions, plates and callers).
  - 14 unprefixed legacy names and `cm848_initFaultManagement` (now "initialize").
  - Two old names were swapped in meaning: `diag_resetSingleFault` cleared every record (now
    `cm848_clearAllFaultRecords`) and `diag_resetAllFaults` only the previously active faults (now
    `cm848_clearPreviouslyActiveFaults`, the DM3 meaning).
  - The others: the warm-up cycle auto clear, the similar-conditions test, the heal step, the occurrence count, the
    freeze frame queue, the detection record (pending, then confirmed), and the completed-monitor registration.
  - `diagnosticMainStateProcessor` is shared with CM550 and keeps its name.
- **Proof:** `prove_caches.py` (the function renames applied to the old .cpp, casts folded) shows no function differing; each old name is left once, in its own plate. verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 84 unprefixed CM848-only functions remain. The protection cluster at 0x514048-0x514394 is next.
  - The fault manager's prototypes still read `param_1` (the slot or fault code); naming them needs full
    `function_definitions.csv` rows.

## Done, round 56 (2026-11-23, same PR): the discrete output overrides replace the last protection_* function names

A peer relay started the round; the scripts are in `session_folder/round56/`.
- **Stage A (3115bca):** the 0x514048-0x514394 "protection" cluster and its globals are the discrete output overrides.
  - **The blocks:** e2m 8B5B (the override priority word and five enable / value byte pairs) and 8C29 (six more
    pairs). Neither is in the parameter ID table. They tile the gap from 8A79 (ends at 0x408787) to 8A5F (0x4087a0)
    exactly, and every pair is passed with the logical output its e2m record names. The output's own module and its
    round 32 read-back check use the same number.
  - **The types:** `discrete_output_override_t` (enable / value), with 11 instances named from the read-back stems.
    Also `discrete_output_override_priority` and the 11 `<stem>_output_override_enable_previous` words.
  - **The functions:** `cm848_applyDiscreteOutputOverride`, `cm848_applyDiscreteOutputOverrides`,
    `cm848_initializeDiscreteOutputOverrides`, `cm848_addCoolantOverheatLevelTimersToTotals` (8A72 timers into the
    8A73 totals at power-down) and `cm848_initializeOverdriveSwitchAndShift`.
  - **No prototype for the per-output helper.** Pilot builds that committed its four parameter names with `dword`,
    `int32_t` or `undefined4` each put a `(uint)` cast on all 33 call arguments (11 -> 44 casts), because a committed
    parameter locks the argument types. The plate names `param_1`-`param_4` instead.
  - **The trap:** the legacy suffixes are decimal output numbers, but `protection_event_11_reset` drove output 0x11
    (17). The script asserts its output table against the decompile's call arguments.
- **Proof:** `prove_caches.py` (the function renames applied to the old .cpp, casts folded, the struct fields as `instance.enable` / `.value`) shows no function differing; the 11 instances render with no pieces and the cast counts are unchanged. verify byte-identical.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 79 unprefixed CM848-only functions remain.
  - These 11 logical outputs now have proven names (the other outputs were not counted this round). A
    `LOGICAL_OUTPUT` enum on the first parameter of `cm848_setLogicalOutputRequest` /
    `cm848_clearLogicalOutputRequest` would name them at every call site. This round shows that committing a
    parameter casts every argument that differs from its type, so pilot it and count the casts.
  - Parameter names without the cast cost are untried. The `local_variables.csv` route (it already renames
    `cm848_validateWriteAuth`'s `param_1`) commits the parameter through `updateDBVariable` too, so it may cast the
    same way; a build would tell. Otherwise `ApplyFunctionDefinitions` would have to name parameters without locking
    the prototype, a shared-script change that needs both firmwares rebuilt.

## Done, round 57 (2026-11-23, same PR): the cruise cluster, the cruise N/V ratio, two warning chime sources

A peer relay started the round; the scripts are in `session_folder/round57/`.
- **Stage A (868e3f5): the cruise cluster at 0x511ea8-0x513980, read function by function.**
  - 10 unprefixed legacy names, plus `cm848_integrateCruiseRpmRatioChange` for the vocabulary.
  - Three were wrong-domain:
    - `governor_cruise_dualCalc_dispatch` runs the coolant overheat derate monitors
      (`cm848_runCoolantOverheatDerateMonitors`).
    - `engine_coolantTemp_delta_calc` is e2m 8A72 +0 CT_Derate_Temp_Error
      (`cm848_calculateCoolantOverheatTemperatureError`).
    - `fuel_demand_timing_initialize` initializes the TSC1 lost management and the rock cycle cache
      (`cm848_initializeRockCycleAndTsc1LostManagement`).
  - **The five state getters** return `CRUISE_CONTROL_STATE` (no parameters, r3 returns):
    `cm848_selectBaseCruiseState`, `cm848_selectDeniedCruiseState` and `cm848_selectCruiseStateFor{Set,Resume,Coast}Switch`.
    - They render the states by name and drop 6 casts.
    - The caller re-renders with renumbered locals and no cast added.
  - **The e2m 8A0E / 8A0F "N_V" ratio family** (table-resolved) is now `cruise_engine_to_vehicle_speed_ratio_*`
    (was `cruise_rpm_ratio_*`): 12 rows, including the filter state and its coefficient (two type-only rows).
- **Stage B (607a663): two of the five warning chime sources in `cm848_updateEngineWarningFlags`.**
  - `fuel_pressure_fault_active_flag` (was `protection_fault_latch_flag`): any of four rail pressure and fuel
    metering faults, 57-60 = P1221 / P1222 / no DTC (fault 59's slot holds P0000) / P1223; PCI 0x35 bit 6. The
    stage B commit message says "P1222 twice"; the follow-up corrected the row.
  - Its chime count `warning_chime_count_fuel_pressure_fault` is 8B2D +A. The CHR_B2 e2m releases (11.61-11.72)
    name that word Catalyst_Warning_Chime_Count, but the truck's code chimes it for these faults.
  - `air_conditioning_coolant_off_flag` (was `protection_coolant_classb_active_flag`): the A/C coolant-off condition
    of the DR truck A/C clutch control, chimed by e2m 8B2D +6 AC_Coolant_Off_Chime_Count.
  - Their copy / previous words and chime counts: 7 rows.
  - The 11.45 e2m's 8A0F +C / +E / +10 records (cruise switch history, a transmission cutout) do not match the code
    at those addresses, so 8A0F's 11.46 layout drifts from +C on.
- **Proof:** stage A: `prove_r57.sh` shows 1962 of 1968 functions label-only; `prove_return_types_r57.py` proves the five retyped getters (members back to values, casts and locals normalized), and the caller only re-renders (renumbered locals, no cast added). Stage B: no function differs. verify byte-identical.
- **Round 56's wording, corrected:** "the last `protection_*` names" was true of function names only; 17
  `protection_*` globals were left, and stage B renamed 5 of them.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - 69 unprefixed CM848-only functions remain.
  - 12 `protection_*` globals remain: `protection_diag_state_a` / `_b` / `_c`,
    `protection_event_output_polarity_bits_cal` / `_line_cal`, `protection_status_flags_b`, `protection_crank_event_counter`,
    the `protection_group29_*` pair, `protection_rpm_correction_cached_axis_offsets`, and two pad fields.
  - 8A0F +A Filtered_Cruise_N_V_Ratio (0x40b20e) has no code use under its address.
  - The 0x3fcd90 word that `cm848_initializeCruiseControl` zeroes has no reader found by name; it sits in the
    time-shared ROM-to-RAM window, so a pointer or boot-side reader is not ruled out.

## Done, round 58 (2026-11-23, same PR): the last 12 protection_* globals named from their code

A peer relay started the round; the scripts are in `session_folder/round58/`.
- **Stage A (d0ce823).** Each "no other access found" rests on the decompile's use list (every function, by name)
  plus the dump values. `scan_accesses_v2.py`, a base-tracking D-form scan of both banks (lis / addi / ori / mr
  bases), adds the raw-offset forms such as `lbz r11,19(r31)`. It tracks bases in address order and drops the
  volatile registers at every `bl`, so it cannot prove absence. Round 58's follow-up called it an under-report (2 of 6
  stores found); round 59 counted the machine code: those words have exactly 2 stores each, which the decompile
  prints as 6 lines by repeating the store in each branch's return path.
  - **The logical output line map** (EEPROM mirror; the boot kernel's time-shared rows inside it keep their names):
    `logical_output_line_cal` (the table), `logical_output_line_active_low_bits_cal` (the polarity bits),
    `logical_output_62_line_cal` (was `qadc_adc_enable_flag`) and `cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63`
    (outputs 62 / 63 follow the overdrive / converter clutch solenoid requests; active on this truck).
  - **The injector driver booster:** `injector_driver_booster_recharge_off_delay_counter` (e2m 8041 +26) and
    `fuel_system_hardware_shutdown_check_enable_flag` (was `tpu_protection_enable_flag`).
  - **The P0116 coolant rationality monitor:** its snapshot words (two of them new rows), the start delay countdown,
    and `cm848_initializeCoolantTemperatureSensorPerformanceMonitor`.
  - **Others:** `transmission_diagnostic_flags_6` (e2m 8C19 +13), `combustion_torque_by_fuel_quantity_friction_cached_axis_offsets`
    with `cm848_initializeFrictionTorqueLookupCache` (was `cm848_initThrottleRateFilterState`), and
    `all_speed_governor_spare_word_1` / `_2` / `_3` (set to 2 at boot; no other access found).
  - Two junk documentation rows were deleted (`protection_b_state_t_003feebc.protection_b_pad_01` / `_03`).
- **Proof:** `prove_r58.sh` shows no function differing; the 5 piece renders of the new names are the boot kernel's same 5 halves of the time-shared polarity word; all 12 renamed rows keep their notes. verify byte-identical.
- **firmware/CLAUDE.md (factual correction, numbers only):** the MISSING sentence now gives 218 since round 58 (121
  documentation rows, 3 deferred). This round's own rows changed it: `logical_output_62_line_cal` gained `_cal`, and two
  documentation rows were deleted.
- **Leads:**
  - No `global_variables.csv` row keeps a `protection_` prefix now; four struct fields still do
    (`engine_control_flags_t.protection_system`, `timing_mode_control_t.protection_blend_ramp` /
    `protection_counter_1` / `protection_counter_2`). 99 rows still have `protection` inside their names.
  - Entry 17 of the line table renders as the boot kernel's time-shared name `qadc_queue_timing_config._0_2_` in the
    mirror function.
  - `coolant_temperature_sensor_performance_snapshot_coolant_temperature` is read only with `lha`, so it is an `i16`
    candidate.
  - `scan_accesses_v2.py` could become a repo tool once it follows control flow; it now tracks bases in address
    order, so it cannot prove absence.
  - firmware/CLAUDE.md's time-shared bullet still says 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe are read "by protection + J1939
    builders"; they are the logical output line map.

## Done, round 59 (2026-11-23, same PR): 29 struct types nothing in CM848 uses are removed

A peer relay started the round; the scripts are in `session_folder/round59/`.
- **Stage A (18c75e9):** `orphan_struct_types.py` lists every struct type that nothing names: no address row, field,
  dependency, CSV, `.cpp` render, script, test, CLAUDE.md or skill. 32 of the 192 qualified. 24 of the 29 removed
  came with the 2026-01-30 port of 26 generic CM550 structures (fdc657a); the 5 protocol / DMA / patch types were
  there before.
  - **Covered by a live type (deleted):** `ad_sensor_config_t` (16 bytes) and `address_range_entry_t` (10) have
    the same size as `sensor_channel_config_t` / `memory_region_t`. `sensor_fault_config_t` (24) and
    `sensor_debounce_state_t` (22) only cover the role of `sensor_channel_config_t` / `sensor_channel_state_t`
    (16 / 12) and were marked "documentation only". The stage A commit message calls all four "superseded".
  - **No CM848 home (deleted, 25):** speculative protocol / DMA / patch types, CM550 templates unused there too, and
    three CM550 applies with no CM848 layout. The data plate is not at CM550's EEPROM 0x2C0 here.
    - The last `protection_` field names went with `engine_control_flags_t` and `timing_mode_control_t`.
  - **Kept as leads:** `param_id_entry_t`, `diag_dispatch_entry_t` and `ef00_dispatch_entry_t`. This round gave
    them homes at 0x53be38 / 0x539508 / 0x53a9a0; round 60 found their own comments name others (the boot table
    0x3F98AC, RAM 0x3FA8B2, RAM 0x3FDB30), and 0x539508 is code.
  - The removed text is archived verbatim with each type's pile (`removed_orphan_types.txt`). CM550 is untouched.
- **Stage B (0b13a71): round 58's scan claim corrected.** Round 58's follow-up said `scan_accesses_v2.py` found "2 of
  the 6 stores" to two words. The machine code has exactly 2 stores to each; the decompile prints 6 lines by repeating
  a shared store in each branch's return path. The scan still cannot prove absence (computed pointers; volatile bases
  forgotten at each call), and the seven rows, task 046 and the memory note now say that. Both words' 2 stores were
  checked in the disassembly (0x52deac / 0x52df64 and 0x5290dc / 0x529140).
- **Proof:** stage A: the `.cpp` is unchanged (only the timestamp differed); `firmware_types.hpp` loses exactly the 29 types; the other headers are unchanged; verify byte-identical. Stage B: comments only.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 218.
- **Leads:**
  - Type the parameter ID table (`param_id_entry_t`, 1441 records to the end of the flash2 dump) and the two dispatch
    tables. Done in round 60 for the parameter ID tables and the SCI table; the dispatch types' homes differ.
  - CM550 keeps unused copies of 18 of the removed types.
  - `j1939_ack_msg_t` is unused as well (only an `enums.csv` comment names it); `j1939_acknowledgement_payload_t`
    covers its role.
  - 69 unprefixed CM848-only functions remain.

## Done, round 60 (2026-11-23, same PR): the parameter ID tables and the SCI command dispatch table typed

A peer relay started the round; the scripts are in `session_folder/round60/`.
- **Stage A (afff095).**
  - **`parameter_id_entry_t`** (was `param_id_entry_t`: {word parameter_id, dword address}). Its own comments named its
    home, the boot kernel's 20-entry table. It now types both tables:
    - `boot_parameter_id_table` (`parameter_id_entry_t[20]` at 0x3f98ac, was `param_id_lookup_table`), with
      `cm848_lookupBootParameterIdAddress` (was `cm848_lookupTableEntryByKey`);
    - the application's `parameter_id_table` (`parameter_id_entry_t[1441]` at 0x53be38) and its hash index
      `parameter_id_table_bucket_start` (`word[1889]`).
  - **`sci_command_dispatch_entry_t`** (new) on `sci_command_dispatch_table` (flash2 0x53a9a0, 19 records).
  - Five type-only pointer rows inside the arrays are gone. `j1939_ack_msg_t` is deleted: its 8 fields equal
    `j1939_acknowledgement_payload_t`'s.
  - `ef00_dispatch_entry_t` / `diag_dispatch_entry_t` are untouched; their documented RAM homes are unverified.
- **Round 59's homes corrected:** its kept types' homes (0x53be38 / 0x539508 / 0x53a9a0) were wrong for two of the
  three, and 0x539508 is code. The round 59 lines above now say so.
- **Proof:** exactly the three expected functions differ, each diffed; casts 8 -> 5 over them, no pieces; `firmware_types.hpp` changes by one rename, one new type, one removal. verify byte-identical, thunks 18 / 14.
- **firmware/CLAUDE.md (factual corrections, verified this round):**
  - the Bank 2 "Command dispatch table" address 0x00539508 -> 0x0053a9a0 (0x539508 is a run of `bl` calls);
  - the stuck-warning row for `_param_id_lookup_table`: it already rendered without the `_` before this round; the
    row now says so, and that the typed array applies over the window (a follow-up fixed the row's first wording,
    "resolved in round 60").
- **Leads:**
  - The real homes of `ef00_dispatch_entry_t` / `diag_dispatch_entry_t`: read `j1939_diagServiceDispatch` and the
    registration code for each table's address and stride.
  - `cm848_lookupBootParameterIdAddress` keeps its `word` parameter and the `CONCAT22` it causes. A wider prototype
    would remove it but could add casts at its three callers (pilot it).
  - 69 unprefixed CM848-only functions remain.

## Done, round 61 (2026-11-23, same PR): both diagnostic service dispatch tables typed

A peer relay started the round; the scripts are in `session_folder/round61/`.
- **Stage A (acca2b6).** The two dispatch templates got the homes their own comments named:
  - **`j1939_diagnostic_service_entry_t`** (was `ef00_dispatch_entry_t`) on `j1939_diagnostic_service_table` (RAM
    0x3fa8b2, 32 slots). `cm848_j1939RegisterDiagnosticService` fills it and `cm848_j1939DiagnosticServiceHandler`
    scans it.
  - **`boot_diagnostic_service_entry_t`** (was `diag_dispatch_entry_t`; 5 bytes, handler at offset 1) on the boot
    kernel's `diagnostic_service_dispatch_table` (0x3fdb30). The `arrays.csv` `byte[10]` row became a
    `global_variables.csv` `[2]` row, the same 10 bytes.
  - `cm848_validateJ1939DiagnosticRequest` (was `j1939_diagServiceDispatch`): it checks length and security; it does not
    dispatch.
  - The 15 `j1939_diagService` plates now name the registrar's current name.
  - The three stale `function_definitions.csv` names are synced, so the build's three "Function name mismatch"
    warnings are gone. Later rounds should expect none.
- **Proof:** exactly the four table functions differ (two registrars, two scanners), each diffed; casts 3 -> 2 over them, no pieces; `firmware_types.hpp` renames the two dispatch types and nothing else. verify byte-identical, thunks 18 / 14, no name-mismatch warning left.
- **firmware/CLAUDE.md (factual corrections, numbers / locations only):**
  - MISSING 218 -> 219 (78 boot-named rows): the boot table's row moved into `global_variables.csv` at a time-shared
    EEPROM-mirror address.
  - The wave 9 note on `diagnostic_service_dispatch_table` now says where the row lives.
- **Follow-up (comments only):** stage A's new field comments had dropped two verified facts, and they are
  restored. The J1939 `service_id` points at the `EF00_SERVICE_ID` enum. The boot `service_id` lists the kernel's
  constant-ID registrations: 0x0b / 0x10 / 0x18 acknowledge, 0x19, 0x41, and 0x43 / 0x4a / 0x4c memory reads.
- **Leads:**
  - Type `j1939_diagnostic_service_entry_t.service_id` as `EF00_SERVICE_ID`; pilot it and count the casts.
  - `cm848_validateJ1939DiagnosticRequest`'s plate says the key check runs when
    `calibration_download_security_key_cal` "is set". The code tests `!= 0xff`, so fix the plate at the next
    rebuild.
  - `j1939_dm1_request_mode_byte` holds the DM7 request's mode byte, so the name looks wrong.
  - 69 unprefixed CM848-only functions remain.

## Done, round 62 (2026-11-23, same PR): the J1939 registration functions, the DM7 test identifier, a startup fault delay

A peer relay started the round; the scripts are in `session_folder/round62/`.
- **Stage A (25098ce):**
  - **The registration functions called by `cm848_j1939_system_init`:**
    `cm848_registerJ1939BroadcastAndNoOperationServices` (stage B) / `cm848_registerJ1939MemoryWriteServices` /
    `cm848_registerJ1939MemoryReadServices` / `cm848_registerJ1939GetAddressByParameterIdService` (were the
    `j1939_diag_request_batch_*` / `_41_handler` names), `cm848_registerJ1939InputMessageHandlers` (was
    `j1939_pgn_handler_init_batch`) and `cm848_registerJ1939Dm7Handler` (was `cm848_initJ1939Dm1RequestHandler`).
  - **`j1939_dm7_test_identifier`** (was `j1939_dm1_request_mode_byte`): DM7's first byte, the Test Identifier
    (SPN 1224, from the local J1939 database).
  - **`j1939_input_fault_start_delay`** (was `governor_table_check_startup_delay`): while it counts down, the J1939
    input processors clear their data error and timeout faults instead of setting them.
  - **The vague Bank 2 helpers:** `cm848_initializeTorqueLookupCaches`, `cm848_initializeOxygenLimitLookupCaches`,
    `cm848_calculateFrictionTorquePercentAndNetOutputTorque` and `cm848_presetPedalFaultModeFuelDemand`.
  - **New rows:** the pedal fault mode engine speed filter and its coefficient (two type-only rows named) and
    `combustion_torque_by_fuel_quantity_timing_adjusted_cached_axis_offsets` (`word[2]`).
  - `cm848_validateJ1939DiagnosticRequest`'s plate says "is not 0xff" for the key test (round 61's lead).
- **Stage B (fa13ad2d), from the closing checks:** stage A named the services 0x0f / 0x10 / 4 / 5 registrar
  `...ParameterAndBroadcastServices` after the `EF00_SERVICE_ID` member names. But `j1939_diagService15And16Handler`
  only returns 0: 0x0f / 0x10 are accepted no-ops in this build. The handler is now
  `cm848_j1939DiagnosticServiceAcknowledgeNoOperation` (the application's twin of the boot kernel's
  `cm848_diagServiceAcknowledgeNoOperation`), and the registrar is `cm848_registerJ1939BroadcastAndNoOperationServices`.
  Also checked:
  - e2m 10CE (Limp_Home_*) holds every `pedal_fault_mode_*` setting, and the filter coefficient row now cites
    10CE +0;
  - `j1939_input_fault_start_delay` reads 1000 in the dump, as it should with the J1939 input layer off, and both
    input processors clear the two faults while it is nonzero;
  - none of the round's old labels is in CM550;
  - "first byte" for the DM7 Test Identifier rests on the code reading byte 0, since the database gives no byte
    positions.
- **Not done:** typing the J1939 service ID as `EF00_SERVICE_ID`. The enum covers all 24 registered IDs, but its
  members are placeholders or abbreviations (`SYSTEM_SERVICE_04`, `MEM_READ_2B_PARAM_4B_OFFSET`), and the handler
  names already say more.
- **Proof:** `prove_r62.sh` shows no function differing; both renamed rows keep their notes. verify byte-identical, thunks 18 / 14, no name-mismatch warning.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 219.
- **Leads:**
  - Rename the `EF00_SERVICE_ID` members from their registered handlers, then type the registrar's `service_id`
    parameter (24 call sites would read the names).
  - `DAT_003fba10`, the word next to the new cache in `cm848_calculateNetCombustionTorque`.
  - 59 unprefixed CM848-only functions remain. Round 61's "69" did not count its own rename, so it was 68.

## Done, round 63 (2026-11-23, same PR): the PGN 61184 diagnostic services in both kernels

A peer relay started the round on round 62's lead; the scripts are in `session_folder/round63/`.
- **Stage A (eba8399d): the application's service vocabulary.**
  - `EF00_SERVICE_ID` -> `J1939_DIAGNOSTIC_SERVICE`: 24 members named from the handlers the application registers,
    plus 0x0c / 0x0d (the two responses). The old CLIP guesses were wrong for CM848:
    - 0x15 commits the EEPROM mirror;
    - 0x43's 4-byte field is the length;
    - 0x46 is registered, with an offset and a length.
  - The enum types the registrar's `service_id` (all 24 registrations render names), the dispatch table's entry
    field and the dispatcher's `service` local.
  - 23 functions renamed:
    - the 14 handlers on one scheme (`cm848_handleJ1939<member>Service`) and the 4 memory workers;
    - both header-length helpers: `cm848_getJ1939DiagnosticResponseEchoLength` (was `cm848_getLimitCategoryCode`)
      returns how many request bytes a response repeats;
    - `cm848_selectJ1939TransmitBuffer`;
    - service 1, `cm848_requestClearInactiveFaults`: it sets e2m 1080 +2's CLEAR_INACTIVE bit, as DM3 does. The DM3
      handler is renamed too.
  - `j1939_memory_read_reply_services` (0x53a330, 10 bytes). A first build with 11 bytes reached 0x53a33a, the start
    of `cm848_lookupApplicationMemoryRegionType`'s table.
  - `firmware/CLAUDE.md`: the `cm848_lookupParameterIdAddress` callers line listed 3 of the 5 callers.
  - `docs/parameter_by_id_system.md`: a corrections section. Its 20 parameters and handlers are the boot kernel's;
    0x43's bytes 3-6 are the length.
- **Stage B (f7d68431): the application's request is a `j1939_rx_msg_t *`** in 20 handlers and workers.
  - 45 casts and 113 placeholder names are gone; one informative cast is added.
  - `parameter_id` is `undefined4`: the lookup hashes all 32 bits, so a halfword type made a CONCAT22.
- **Stage C (d9933bac): the boot kernel's twin.**
  - `BOOT_DIAGNOSTIC_SERVICE`, 16 members. It is a separate enum because the boot kernel's 7 downloads a calibration.
  - Wrong prototypes fixed: the read handler's three rows (address / length / response_ptr are the request / the
    address / the length), and the read-by-ID worker's offset and length, which were named reserved and offset.
  - The 12 handlers and workers take the request.
  - 23 functions renamed (`cm848_handleBoot<member>Service` and so on).
  - `boot_kernel_rom_end` is also where the boot read reply table starts.
- **Follow-up (1d2f74d4), from the closing checks:**
  - CM550's `EF00_SERVICE_ID` type is `J1939_DIAGNOSTIC_SERVICE` too, since shared names change in both
    firmwares. Its members stay CM550's own, and the enum renders nowhere in CM550: its `.cpp` matches a base
    build.
  - The 0x0d member comment: 0xfe sends 0x0e.
  - The boot dispatcher's plate: a received 0x0c / 0x0d gets no answer. It said "answered directly".
  - `diag_scan_step_counter` -> `boot_diagnostic_service_count`. The boot registrar appends at it (at most 20)
    and the boot dispatcher scans that many entries.
  - A wider sweep for the round's 46 old names and its three overturned claims. It fixed three docs:
    - `parameter_by_id_system.md` names the boot handlers;
    - `rom_to_ram_thunking.md`'s snapshot row;
    - `ecu_identification.md` has a CM848 footnote under its test matrix.
    Snapshots, worklists, dated plans and task logs keep the old names.
- **Proof:** stage A 9 of 1968 functions differ: the registrar, its 5 callers and the dispatcher by member names (all 24 registrations keep their values and handlers in order), the read worker by the reply table, and one local declaration-order move. Stage B 21: the 20 typed functions (45 casts and 113 placeholder names removed, 1 cast added, no new artifacts) and the same declaration-order move. Stage C 22: the 19 predicted (41 casts and 57 placeholder names removed, none added; all 14 boot registrations keep their values and handlers) and three declaration-order moves. Every verify byte-identical, thunks 18 / 14, 0 failed prototype or local rows, headers 0 g++ errors, tests pass (Java 89), HARD 0 / MISSING 219.
- **firmware/CLAUDE.md:** two factual edits.
  - Stage A: the callers line.
  - Stage C: the reference refresh updated two renamed boot function names in the kernel flash driver note.
  HARD stays 0 and MISSING 219.
- **Leads:**
  - **Bench:** clip-core's `ECUReader::readParameterService43` sends bytes 3-6 as an offset, and
    `readParameterService46` sends zeros after the ID. On CM848 those bytes are a length (0x43) and an offset plus
    a length (0x46). Check both against the truck before trusting a by-ID read through kuminz-cli.
  - **The two `j1939_tx_msg_t` records** that `cm848_selectJ1939TransmitBuffer` picks are unnamed (0x3fcbc4 single
    frame with data at 0x3fcbd3; 0x3fc4ad transport with data at 0x3fc4bc).
  - **`DIAG_RESPONSE`** could gain the dispatcher's own result codes (2 wrong length / 3 key refused / 8 unknown ID /
    0x18 unknown service / 0x1a key missing) and a spelled-out name.
  - **The dispatcher's `result_code`** splits off a `uVar1` once committed. The importer names locals in one pass,
    so that temp cannot be named.
  - `DAT_003fba10` (round 62's lead) is still open.
  - **CM550's `J1939_DIAGNOSTIC_SERVICE` members are unreviewed.** They are its own CLIP-era names (0x43
    `MEM_READ_2B_PARAM_4B_OFFSET`), and no CM550 handler was read this round.
  - **Three unnamed length tables:**
    - 0x53a322, the application's header lengths. The code's base 0x53a2e1 falls inside input signal
      descriptor 10.
    - 0x5761e, the Bank 1 echo lengths (base 0x575dd).
    - The boot kernel's header lengths, in its image at RAM 0x3f97cd + service.
  - 38 unprefixed CM848-only functions remain.

## Done, round 64 (2026-11-23, same PR): both kernels' transmit records, one result-code enum

A peer relay started the round on round 63's leads; the scripts are in `session_folder/round64/`.
- **Stage A (3ce87e58): the records `cm848_selectJ1939TransmitBuffer` hands out.**
  - `j1939_single_frame_tx_message` (0x3fcbc4) and `j1939_transport_tx_message` (0x3fc4ad), with their status
    bytes and data. `j1939_single_frame_tx_data` is `byte[8]`. `j1939_transport_tx_data` is a named first byte,
    because boot kernel thunks sit inside its 1800-byte extent.
  - The selector returns `j1939_tx_msg_t *`, so its three callers lose their casts.
- **Stage B (57f9cb3d): the boot kernel's records.**
  - `diagnostic_response_message_t` was `j1939_tx_msg_t` field for field and is merged into it, along with two
    stale comment blocks.
  - The boot allocator gets the selector's prototype.
  - Its two data buffers are named (`diagnostic_transport_response_data` `byte[1800]`,
    `diagnostic_single_frame_response_data` `byte[8]`).
- **Stage C (36c29ebe): `J1939_DIAGNOSTIC_RESULT`.**
  - It merges `DIAG_RESPONSE` (0 / 4 / 7) and the unused `DIAG_RESPONSE_CODE`, which was ported from CM550.
  - 11 codes, named from what produces them in this firmware: the validator, the dispatcher, the memory workers,
    the region lookup and the handlers. 0xff (nothing to send) is deliberately not a member: the dispatcher masks
    each result with 0xff, and a member of that value would name the mask.
  - It types the validator's return and the dispatcher's `result_code`.
  - CM550's `DIAG_RESPONSE_CODE` type takes the same name; its members stay its own.
  - **A tool fix:** `refresh_other_csvs_r57.py` rewrote history notes ("(was DIAG_ACK ...)" became the new name).
    `refresh_other_csvs_r64.py` skips history markers as `refresh_references.py` does, and
    `history_corruption.py` finds a rewritten note. Round 63's renames show none, and neither do rounds 57-62's
    archived maps.
- **Corrections (this follow-up), from the closing review:**
  - The pushed closing said 12 codes and that the dispatcher lost 4 placeholder names. The enum has 11 codes, and
    the dispatcher lost none. `review_typed.py` matched only lowercase prefixes; `review_typed_r64.py` matches
    `JVar` too.
  - Commit 3ce87e58 says the thunk snapshot has 10 targets at 0x3fc580 - 0x3fcb24. That range holds 9; the
    snapshot's tenth, 0x3fc484, lies below the record.
  - The `j1939_transport_tx_data` comment said a 0x4c read reply needs up to 1775 bytes. That is the 0x49 reply
    to a 0x48 read (header 11 + 1764); a 0x4c reply needs 1773. The comment is fixed, and the `.cpp` is
    unchanged.
  - Commit 36c29ebe repeats the 4-placeholder claim.
- **Proof:** stage A 6 of 1968 functions differ: the selector, its 3 callers (each loses its cast) and two local declaration-order moves. Stage B 6: the boot allocator, its 2 callers (each loses its cast), the 2 boot transmit functions and one declaration-order move. Stage C 9: the 7 handlers, the validator and the dispatcher, with no cast or placeholder added or removed (the dispatcher's split temp is J1939_DIAGNOSTIC_RESULT JVar1 now - was uint uVar1); CM550's output equals a base build. Every verify byte-identical, thunks 18 / 14, 0 failed prototype or local rows, no artifact count changed, headers 0 g++ errors for both firmwares, tests pass, HARD 0 / MISSING 219.
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 219.
- **Leads:**
  - **The boot kernel's result codes differ:** 5 = unknown service, 10 = a ROM handler refused in EEPROM service
    mode. A boot twin of `J1939_DIAGNOSTIC_RESULT` would cover them.
  - 0x14 (CM550's CHECKSUM_MISMATCH) and 0xfe (answered with 0x0e by `cm848_sendJ1939ResponseFrame`) have no CM848
    producer found.
  - CM550's `J1939_DIAGNOSTIC_RESULT` / `J1939_DIAGNOSTIC_SERVICE` members are unreviewed.
  - Still open from round 63: the three unnamed length tables, `DAT_003fba10`, and 38 unprefixed CM848-only
    functions.

## Leads (not in this PR)

- **Round 5 leads:**
  - The TSC1 / ETC1 vocabulary: resolved in round 6 (below).
  - The `governor_cruise_*` working words of the cruise governor (and its `governor_cruise_zone_table_ptr`):
    rename them to the `cruise_governor_*` words with the functions. (Done in round 16.)
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
  - `sensor_channel9_ram` (0x40a0e6) is the state of the `cm848_sensorChannel9_*` wrappers (round 15: it is slot 7's state, `fuel_temperature_sensor_channel_state`). Check which
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
