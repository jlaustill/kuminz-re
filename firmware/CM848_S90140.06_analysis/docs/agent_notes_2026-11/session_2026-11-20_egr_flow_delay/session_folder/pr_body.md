## Summary

**Is `cm848_throttleBasedFuelCalculation` (0x128a0) named properly? No.** It computes nothing about the throttle or
fueling. It is the EGR transport delay stage of the Cummins charge properties (CHP) model. The ECU's own parameter ID
table (found 2026-11-19) maps every word it writes to e2m block 177F, and its struct `throttle_fuel_trim_t` is that
block, one field per record. Wave 14 had flagged the function as an unproved lead.

What it does, every 10 ms (phase group A, every even phase of the 5 ms main loop):
- **The oxygen delay:** CHP_O2_Flow_Delay = C_CHP_Volume_Fraction x 120 x 1000 / (volumetric efficiency x engine
  speed) ms. That is the time the engine takes to breathe that fraction of its displacement. The e2m scale is
  0.001 s, matching the x 1000.
- **The oxygen fraction in the EGR:** the residual oxygen fraction goes through a 256-sample delay line (delay / 10 =
  10 ms samples) and a filter, which gives CHP_O2_Frac_EGR.
- **The EGR flow delay:** CHP_EGR_Flow_Delay is a fraction of the oxygen delay. The EGR mass flow before delay goes
  through a second line and the signed filter, which gives `egr_mass_flow_delayed_filtered`.
- **The EGR fraction:** EGR_Fraction = the delayed EGR flow x 8192 / the charge flow, capped at 1.0.
- **The RAM dump agrees** (key on, engine stopped): the oxygen delay reads 40959 = 0xffff x 1000 / 1600, and the
  oxygen fraction reads 8192 = 1.0.

```c
// before
uVar4 = cm848_circularBufferWriteUnsigned
                  (&DAT_003fa1b6,residual_oxygen_fraction_before_delay,(uVar4 & 0xffff) / 10);
throttle_fuel_trim_t_0040a3ea.residual_oxygen_fraction_delayed_filtered = (word)dVar2;
// after
delayed_oxygen_fraction =
     cm848_delayUnsignedSample
               (&egr_oxygen_fraction_delay_line,residual_oxygen_fraction_before_delay,
                (uVar1 & 0xffff) / 10);
egr_flow_estimate_terms.egr_oxygen_fraction = (word)filtered_oxygen_fraction;
```

## Changes

**Stage 1, label-only (a513107).** `reverse_names.py` reports EQUIVALENT, and 0 functions differ.
- `cm848_throttleBasedFuelCalculation` → `cm848_calculateDelayedEgrFlowAndFraction`.
- `cm848_circularBufferWriteUnsigned` / `Signed` → `cm848_delayUnsignedSample` / `cm848_delaySignedSample`.
- `throttle_fuel_trim_t` / `throttle_fuel_trim_t_0040a3ea` → `egr_flow_estimate_terms_t` / `egr_flow_estimate_terms`.
  Its 12 fields are named from 177F +0 .. +16, for example:
  - `final_trim` = `egr_mass_flow_before_delay`;
  - `throttle_conversion` = `oxygen_flow_delay_milliseconds`;
  - `rpm_based_trim` / `load_based_trim` = `upstream_egr_mass_flow` / `downstream_egr_mass_flow`.
- `engine_fuel_fault_status` → `egr_flow_source` (177F +18 EGR_Flow_Source).
- `throttle_filter_state` → `egr_oxygen_fraction_filter`.

**Stage 2, shape (d943bd0).**
- **`delay_line_t`** (`samples` word[256], `write_index`, `spare`), on `egr_oxygen_fraction_delay_line` /
  `egr_mass_flow_delay_line`. The two helpers get full prototypes and now read
  `delay_line->samples[write_index] = sample`.
- **The boot kernel's call targets:** both lines sit in the kernel's RAM image and cover boot-ROM call targets, 0x3fa2f0
  (`cm848_runFlashProgramStateMachine`) and 0x3fa5a0 (`mpc555_cmfEraseBlocks`).
  - The thunk stage now gives those calls call overrides ("(covering) kept"; thunks 21 → 19, overrides 11 → 13).
  - The boot calls still render by name.
- **Signed types:**
  - The six e2m `S` words are `short`, and the two EGR flow limits are `i16` (both are `lha`).
  - `0x9c00` / `0x8148` now read `-0x6400` / `-0x7eb8`, and the `(short)` casts are gone.
- **Locals:** the locals of 0x128a0 are named.

**Docs (0805de0 and the review fixes).** Task 046 (the evidence and the open leads), todo 046, two `firmware/CLAUDE.md`
notes and the session archive.

## Test plan

- [x] `./analyze.sh build` passes. The warning lines are identical to the stage 1 build.
- [x] Stage 1: the label-only proof is EQUIVALENT, and every new name renders.
- [x] Stage 2: 9 functions differ from stage 1, the 6 intended ones plus 3 that only reorder their local declarations.
  The piece count stays 508 → 508, and no new name has an underscore variant.
- [x] `./analyze.sh verify`: the two builds are byte-identical.
- [x] `lookup_tables.py` is clean (920 / 920 typed).
- [x] `test_lookup_tables.py`, `test_disasm_tools.py`, `test_e2m_block_addresses.py` and `test_rename_waves.py` pass.
- [x] The headers are regenerated (CM550's are unchanged), and `g++ -fsyntax-only` is clean.

## Still open (task 046)

- **What 0x128a0 still shows:** the function rates Readability Medium. Its body still shows one `uVar1` (the reused
  register's later values) and the default-labelled `engine_rpm_state_t_0040b7ac`.
- **The rest of the charge properties family is still misnamed.** Each sibling's idea is in task 046.
  - 0x12e60 `cm848_fuelControlMainCalculation`
  - 0x12dc4 `cm848_fuelDemandWithLoadCompensation`
  - 0x12eb4 `cm848_fuelDemandErrorCalculation`, which is the fresh air flow
  - the two EGR flow source checks and the initializers
- **The EGR model's data:** its lookup caches (`diag_state_group5_*` / `_6_*`) and its tables at 0x4002f2-0x40090c
  (`boost_fuel_*` / `throttle_*_cal`) still carry legacy names.
- **The exhaust pressure:** `boost_pressure_current_raw` is the exhaust pressure (e2m 1A5D +0).

🤖 Generated with [Claude Code](https://claude.com/claude-code)
