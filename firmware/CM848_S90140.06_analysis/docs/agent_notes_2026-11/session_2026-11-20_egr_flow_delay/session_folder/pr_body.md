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
  - **Proof:** after reversing the labels, six functions differ, each only by the intended rendering.

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
  - stage 10c's six changed functions were read diff by diff;
  - the apply gate checked bin coverage, old = current, name free as a global / function / field / parameter /
    local / enum / `.cpp` identifier, `_cal` = EEPROM mirror, banned abbreviations, CM550 sharing and the quoted line;
  - the quoted dump values match: 17 flags, all regex hits on scaled values, against 92 for the negative control;
  - the widths match the e2m records after 10c;
  - no stale references remain (`stale_refs_W15.py`, the comment-name sweep).
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
- **Wave 15 leads not applied:** the 9-word ASG gain set struct, the fault derate scheduler words, the cruise / RSG
  PID functions (`protectionOutputActuatorControl` ...), the TPU injection channel bytes, the 11D5 air fuel control
  rows, and 0x3fdda6 `drivetrain_type`, whose e2m record is RSC_Sensor_Type (the cruise fix rests on it). The full
  list is in task 046.
- **The e2m pool above 0.2 overlap** (123 rows at ≤ 0.25, 140 at ≤ 0.34, 220 at ≤ 0.5): a next wave if wanted.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
