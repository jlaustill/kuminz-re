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

## Test plan

- [x] `./analyze.sh build` passes at every stage. The warnings are unchanged, except the two stale-prototype warnings
  that stage 4 removes.
- [x] Stages 1, 3, 5 and 7: the label-only proof is EQUIVALENT.
- [x] Stage 8: the cast-normalized proof leaves 6 differing functions, all cosmetic.
- [x] Stage 2 changed only the intended functions. Stage 4 changed only the functions predicted before its build (the
  two readers of `pumping_torque_adjustment` needed no cast, so they did not change). Apart from those, only
  declaration orders changed, and the piece count stays 508 → 508.
- [x] No new name shadows a parameter or a local. CM550 and the cross-firmware maps cite none of the old names. Every
  stage 3 row's width matches its e2m record.
- [x] `./analyze.sh verify`: the two builds are byte-identical.
- [x] `lookup_tables.py` is clean (920 / 920 typed).
- [x] `test_lookup_tables.py`, `test_disasm_tools.py`, `test_e2m_block_addresses.py` and `test_rename_waves.py` pass.
- [x] The headers are regenerated (CM550's are unchanged), and `g++ -fsyntax-only` is clean.

## Still open (task 046)

- **What 0x128a0 still shows:** it rates Readability Medium. One `uVar1` (the reused register's later values) and the
  default-labelled `engine_rpm_state_t_0040b7ac` remain.
- **The engine speed module's functions** have mixed prefixes: `hpcr_processEngineSyncPulses`,
  `mpc555_handleCamSignalInterrupt`, `mpc555_updateEngineRunState` and the run state handlers.
- **The signedness sweep's remainder:** 35 rows with an `lhz` load and 104 with no load.
- **The rest of the e2m audit's low-overlap rows,** which would suit a wave of agents.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
