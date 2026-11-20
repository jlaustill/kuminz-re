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
  - **Two source words:** `compressor_inlet_temperature_source` (1A0C +2) and `barometric_pressure_selected_source`
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

## Leads (not in this PR)

- **The engine speed module's functions** have mixed, partly wrong prefixes: `hpcr_processEngineSyncPulses` (the main
  speed interrupt), `mpc555_handleCamSignalInterrupt` (the backup speed interrupt), `mpc555_updateEngineRunState` (the
  crank sync state machine), `mpc555_resetEngineTimingAccumulators`, and `cm848_engineRunState3Handler` and its
  siblings. Rename them once each state's behaviour is read.
- **The signedness sweep's remainder:**
  - The 35 `has-lhz` rows need a per-row look: zero-extending loads usually mean the code treats the value as unsigned.
  - The 104 `no-load` rows are stored or pointer-passed only.
- **The rest of the e2m audit's low-overlap rows** (task 045 counted ~1300). A wave of agents would suit it.

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
