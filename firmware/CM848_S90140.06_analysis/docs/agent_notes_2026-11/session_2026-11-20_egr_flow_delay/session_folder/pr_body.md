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
  - the J1939 monitor's session record (e2m 10FE / 10FF / 1100: still etc1_governor-named words);
  - the engine speed module's run-state machine (no e2m value list, so it needs a read);
  - the 48RE governor pressure functions 0x3257c / 0x3241c (their block 8D14 drifts);
  - the fault derate scheduler words and the 11D5 air fuel control rows;
  - the TPU injection bytes and the A/C class-B coolant flags.
  The full list is in task 046.
- **The e2m pool above 0.2 overlap** (123 rows at ≤ 0.25, 140 at ≤ 0.34, 220 at ≤ 0.5): a next wave if wanted.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
