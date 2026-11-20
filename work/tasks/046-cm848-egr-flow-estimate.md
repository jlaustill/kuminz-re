# 046 — CM848D: the EGR transport delay stage and the e2m 177F EGR flow estimate

## Problem Statement

On 2026-11-20 the user asked whether `cm848_throttleBasedFuelCalculation` (0x128a0) is named properly. It is not.
The function computes nothing about the throttle or fueling. It is the EGR transport delay stage of the Cummins
charge properties (CHP) model. Wave 14 (task 045) had already flagged it: "reads as the charge flow / EGR fraction
model, but I have no proved name". The ECU's own parameter ID table (found 2026-11-19) now proves the name: it
resolves every word the function writes to e2m block 177F.

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
  - `egr_flow_source` (was `engine_fuel_fault_status`) and `egr_oxygen_fraction_filter` (was `throttle_filter_state`;
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

## Leads (not in this PR)

- **The rest of the charge properties family, all misnamed (wave 14's ideas in brackets):**
  - 0x12e60 `cm848_fuelControlMainCalculation`: the charge properties task. It runs the charge flow model, then 0x128a0,
    then the fresh air flow. [`cm848_calculateChargeProperties`?]
  - 0x12dc4 `cm848_fuelDemandWithLoadCompensation`: stores the intake manifold temperature in Rankine (177D +2), runs
    the volumetric efficiency and the charge mass flow, and sets Charge_Flow_Source. [`cm848_calculateChargeMassFlowModel`]
  - 0x12eb4 `cm848_fuelDemandErrorCalculation`: the fresh air flow, e2m 177B +0 Fresh_Air_Flow = charge - delayed EGR
    (floor 0), filtered, plus 177B +2 Fresh_Air_Flow_Source. Its filter is `fuel_blend_rpm_base_filter_state`, and its
    initializer is 0x12f40 `cm848_initFuelDemandBlendPointers`.
  - 0x12724 `cm848_checkFuelSystemFaultFlags` / 0x12778 `cm848_checkEngineFaultConditions`: the EGR_Flow_Source checks of
    the downstream / upstream models. [`cm848_calculateDownstreamEgrMassFlowSource` / `...Upstream...`]
  - 0x12a58 `cm848_initFilterCoefficients` initializes the EGR model: the lookup caches and the three filters.
    0x12e40 `cm848_initFilterTablePointers` initializes the charge mass flow filter, and 0x12e88
    `cm848_initFuelControlFilterSystem` is the charge properties initializer.
- **The EGR model's lookup caches** `diag_state_group5_a_state` .. `_d_state` (0x3fa1ae-0x3fa1b4) and
  `diag_state_group6_a_state` / `_b_state` (0x3fa5d2 / 0x3fa5d4) are table caches, not diagnostic states. 5a+5b and
  5c+5d look like the word[2] caches of the two 3-D tables.
  - Together with the delay lines and the three filters, the EGR model's RAM runs 0x3fa1ae-0x3fa5d5. It could be one
    struct.
- **The EGR model's tables (ROM-copied RAM, so their `_cal` is wrong):**
  - upstream corrected flow: `boost_fuel_trim_pressure_axis_cal` / `_ystart_cal` / `_yend_cal` (0x4002f2 / 0x400318 /
    0x40033e, e2m 18E3 / 18E4 / 18E5);
  - square root of the exhaust temperature: `boost_fuel_input_axis_cal` / `_output_cal` (0x4005c6 / 0x4005ec,
    e2m 1974 / 1975);
  - downstream corrected flow: `throttle_rpm_axis_cal` / `_ystart_cal` / `_yend_cal` (0x400612 / 0x400638 / 0x40065e,
    e2m 193D / 193E / 193F);
  - square root of the orifice temperature: `throttle_trim_axis_cal` / `_output_cal` (0x4008e6 / 0x40090c,
    e2m 1946 / 1940).
- **`boost_pressure_current_raw` (0x40a7d0)** is e2m 1A5D +0 Exhaust_Press per the upstream model's plate comment. It
  is the exhaust pressure, not boost.
- **Open question:** the dump's write indices differ (191 / 215) although both advance once per pass in the same
  function. The kernel-image bytes the boot copy leaves under them (ROM 0x47e6 / 0x49e8) differ by 63, not 24, so the
  start values are unexplained.
- `firmware/classification.csv` and `docs/memory-mappings/bank1.txt` / `ram.txt` are stale generated snapshots: wave 14
  did not refresh them either, and 0x127bc still reads `selectFuelTrimMode` there. Regenerate them rather than patching
  rows. The same goes for the old `output/bank2_functions.cpp`, `output/internal_names_crossref.md` and the
  `output/worklist_*` batches.
- `output/fuel_injection_analysis.md` ("Related Functions") lists 0x128a0 / 0x12ad4 / 0x12cf4 / 0x12dc4 by their old
  names as a "Fuel Demand Calculation Chain". They are the charge properties model: the delayed EGR flow, the volumetric
  efficiency, the charge mass flow and its wrapper. Rewrite that section when the family is renamed.
