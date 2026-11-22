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
  - 316 bits have e2m 1036 names (the uncertain expansions checked against the bits' setters); the others are
    `fault_<n>`.
  - Word 0 stays the plain word `faults_0_to_15`, the base of the 200 indexed accesses.
  - The measured trade: 674 tests and 109 writes now name their fault, against 943 piece tokens. 856 of those are the
    set / clear writes, which Ghidra 12.1 does not fold.
  - A nested type per word was built and rejected (`ZPULL(...)` renders).
  - The mask-exact proof matches 1964 functions; the other 4 differ only structurally and were read by hand.
- **Round 27 leads:**
  - Word 0's seven named bits (RAM image word, fuel shutoff, turbocharger wastegate driver 1, fuel pressure idle,
    HPCR OBD deviation) stay in its comment. The indexed accesses keep it a plain word.
  - The `fault_<n>` bits with unresolved e2m abbreviations: CORS (37 / 38), T2 (206-215), TAS (216 / 217), PP
    (709 / 710), Chry_Dat42 (308), the cruise SC source (146 / 147).
  - Channel 88's writes into the fuel temperature words: a calibration with channel 88 enabled would put the exhaust
    throttle position into `fuel_temperature_sensor_value`.
  - From the earlier rounds: TouCAN B's base, the "Can2" mailbox writer's name, the boot kernel transport's message
    parameter, `diag_clear_flags_t`.

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
