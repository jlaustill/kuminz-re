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
  `j1939_governor_source_index` and the cached control byte (16 + 1 underscore renders, 7 overlap warnings); deleting
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
    prefix; the retarder handler was only skimmed.
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
- **Round 6 leads:**
  - The J1939 monitor's session record: e2m 10FE J1939_Active_Engine (0x3feb4e), 10FF J1939_Active_Retarder and 1100
    J1939_*_Control_Status. Still unnamed or etc1-named: `etc1_governor_calib_session_start_time`,
    `etc1_governor_mode_history_write_index`, DAT_003feb56-5e (the mode history), DAT_003feb64 (the duration),
    `governor_transition_state_snapshot`. The "see j1939mon specification" text says it is one structure.
  - The other `cm848_*Governor*` functions of the TSC1 path: `cm848_resetGovernorState`, `governor_reset`,
    `governor_resetModeStateOnCondition`, `cm848_initGovernorStateVariables` and `initGovernorJ1939Bypass` reset the
    Jcomm state.
  - `retarder_tsc1_mode_transition_timer` / `retarder_tsc1_speed_mode_flag`: read the retarder handler in full.

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
