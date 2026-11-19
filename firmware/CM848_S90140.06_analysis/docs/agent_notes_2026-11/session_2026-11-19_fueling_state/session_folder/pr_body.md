## Summary

`governor_fuel_demand_mode` (0x40a154) is an enum: the Cummins **FSGVFLST** governed fueling state ("indicator as to which algorithm is in control of fueling after it is governed"). Its codes come from one numbering that every fueling stage shares, so the enum is shared too. This PR does five stages:

1. **The enum.** `ENGINE_OPERATING_MODE` is now **`FUELING_STATE`**. Members 4 / 9 / 10 / 11 / 12 are new, the user and governed carriers are typed, 0x40b67c is renamed and the dword at 0x3fb526 is split.
2. **The later stages.** The derate, combustion and final stages get 17 more members proved from their setters, plus 16 `FUELING_STATE_UNIDENTIFIED_<n>` placeholders. Ten more carriers are typed, including `governor_mode_code`, now `final_fueling_state`.
3. **The arbitration.** 16 functions and 10 words of the fueling arbitration are renamed from legacy `*Protection*` / `governor_*` guesses.
4. **Cummins' own value labels.** A labelled Chrysler calibration in the repo gives every code's label (with hex keys). It confirms the code-derived members and names 11 more. `cold_start_phase` turns out to be the **engine state** (`ENGINE_STATE`). The **power take-off governor** is proved in code (J1939 SPN 976). The limiter producers are renamed: altitude derate, air fuel control, net torque, coolant overheat derate.
5. **The words behind them.** The power take-off governor's words and the crank routine are named from e2m blocks that line up by offset. Two flags turn out to mean the opposite of their names: `engine_starting` is the shutdown command, and `engine_shutdown_active_flag` stops a key-off shutdown. Code 32 is the master / slave override. A follow-up (5b) renamed the emission control (AECD) words, which read backwards, and fixed the comments that still used the old engine state words.

`cm848_arbitrateGovernedFueling` (was `cm848_processProtectionRampControl`) now reads:

```c
FVar1 = FUELING_STATE_HIGH_SPEED_GOVERNOR;            // was 0xc
...
governor_fuel_demand_mode = FUELING_STATE_LOW_SPEED_GOVERNOR;   // was 0xb
if ((governor_fuel_demand_mode == FUELING_STATE_CRUISE_CONTROL) ||
    (governor_fuel_demand_mode == FUELING_STATE_VEHICLE_SPEED_LIMIT)) {   // were 9 / 10
```

## Stage 1: the enum

- **Access census.** 35 accesses in both banks, all 16-bit: 30 `lha`, 2 `lhz`, 3 `sth`. Every load feeds `cmpwi` or a copy. Neither bank holds a pointer to the word.
- **Writers.** Only the arbitration stores to it: 10 / 12 / a pass-through, and 11. The init stores 11.
- **Value chain.** `engine_operating_mode` → `operating_mode_governor_output.mode_code` (+4) → 0x40b67c (+9) → 0x40a154 (+10 / 11 / 12). The RAM dump reads 7 → 7 → 7 → 11.
- **CM550.** 0x0080a8f2 is e2m FSGVFLST and is compared with 12 in the shared `runHighSpeedGovernorPid`.
- **e2m blocks.** Block 1045 (FSGVFL / FSGVFLST / LSLOFG) and block 1265 (PTTHDQRP / PTTHOV / PTSLFL / PTSLFLST) line up by offset.
- **Members.** 9 cruise control / 10 vehicle speed limit / 11 low speed governor / 12 high speed governor come from the code. 4 power take-off was e2m-derived in stage 1 and is code-proven in stage 4.

## Stage 2: the derate, combustion and final stages

- **One numbering, proved in the code.** `cm848_arbitrateRequestedFueling` writes either the governed state (1-12) or `torque_derate_fuel_source_code` (13-62) into `requested_fueling_state`. The RAM dump (key on, engine stopped) reads governed 11 → derate 62 → final 26. CM848 stores derate codes up to 62, beyond the CM550-era e2m range of 1-41.
- **e2m blocks.** Block 1051 FSFNFL / FSFNFLST lines up with `fuel_demand_computed` / `final_fueling_state`, and block 105D FSLMFL / FSLMFLST / FSAPLMFL with 0x40afac / 0x40afae / 0x40afb0.
- **New members, each proved from its setter:**
  - 13 calibrated fixed fuel limit, 19 maximum fuel curve, 20 TSC1 torque limit;
  - 22 engine starting, 23 fuel override, 26 engine stopped;
  - 28 fuel pressure fault limit, 29 fault derate;
  - 41 immobilizer fuel disable, 45 torque management;
  - 52 / 53 / 54 / 55 / 58, the combustion limits;
  - 61 rail pressure shortfall, 62 fuel pressure governor fault blend.

  Stage 2 said CM848's numbering differs from the e2m list above 12, because e2m labels 29 ATDERAT. That was a decimal misread, corrected in stage 4: the label keys are hex, so 0x29 = 41 is the anti-theft derate, and the numbering matches.
- **`FUELING_STATE_UNIDENTIFIED_<n>`.** These cover the codes stored or only compared whose algorithm is not proved yet: 15 16 24 25 27 32 34 37 38 40 42 46 47 49 50 59. Without an exact member, **Ghidra 12.1 prints such a value as an OR of members**: 15 rendered as `FUELING_STATE_HIGH_SPEED_GOVERNOR | FUELING_STATE_TSC1_SPEED_CONTROL | FUELING_STATE_TSC1_TORQUE_CONTROL`. That is why 37 and 38 now have members too.
- **Carriers typed `FUELING_STATE`:**
  - `torque_derate_fuel_source_code`
  - `injection_quantity_combustion_reference_source_code`
  - `final_fueling_state` and `_prev` (were `governor_mode_code` / `_prev`; the `fault_entry_t` freeze-frame byte is renamed too)
  - `requested_fueling_state`
  - `fuel_demand_arbitrated_state` and `_snapshot`
  - `fuel_demand_minimum_tracked_state`
  - `governor_fuel_limit_cap_state`
  - `injection_quantity_combustion_gross_source_code`

  The last five were the `governor_fuel_mode_*` words.

## Stage 3: the arbitration functions and words

| New | Was |
|---|---|
| `cm848_arbitrateGovernedFueling` | `cm848_processProtectionRampControl` |
| `cm848_arbitrateRequestedFueling` | `cm848_processProtectionSelection` |
| `cm848_selectFinalFueling` | `cm848_selectFuelDemandSource` |
| `cm848_calculateMaximumFuelCurve` | `cm848_processActiveFaultList` |
| `cm848_applyFuelPressureGovernorFaultBlend` | `cm848_processSafetyConditionProtection` (faults P1221 / P1222 / P1223) |
| `cm848_calculateVehicleSpeedLimitFueling` | `cm848_processProtectionRampTimer` |
| `cm848_calculateCruiseControlFueling` | `cm848_processGovernorFuelRate` |
| `cm848_selectCruiseOrUserFueling` | `cm848_calculateProtectionLevelLimit` |
| `cm848_runLowSpeedGovernor` / `cm848_limitLowSpeedGovernorFueling` | `cm848_processSpeedGovernorControl` / `cm848_calculateGovernorFuelDemandUpperLimit` |
| `cm848_applyTsc1TorqueLimit` / `cm848_applyFaultDerateFuelLimit` | `cm848_applySpeedControlProtectionLimit` / `cm848_enforceFuelLimitProtection` |
| `cm848_selectPowerTakeOffOrUserFueling` | `cm848_updateGovernorFromProtection` |
| `cm848_calculateRiseLimitedVehicleSpeed` | `cm848_calculateFuelRateFromRpm` |
| `cm848_snapshotHighSpeedGovernorFueling` / `cm848_initializeFuelLimitChains` | `cm848_copyProtectionRampValue` / `cm848_initProtectionStateWithFuelDemand` |

The words are `vehicle_speed_limit_fueling`, `cruise_control_fueling`, `high_speed_governor_fueling_snapshot`, `low_speed_governor_fueling` (+ `_working`), `low_speed_governor_active_flag` (e2m LSLOFG), `vehicle_speed_rise_limited` (+ `_prev`) and `power_take_off_throttle_override_engine_speed_limit` / `_flag` (e2m PTTHDQRP / PTTHOV). Each plate comment and comment gives the evidence and the old name.

## Stage 4: Cummins' value labels, the engine state, the power take-off governor

- **The labels.** `e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m` is a Chrysler calibration close to the truck's V11.46.06. It lists `Fueling_Control_State` 00-3D, `Engine_State` 1-8 and the PTO `[PTST]` states, all with hex keys. Every `FUELING_STATE` member comment now quotes its label.
  - **Confirmed:** 4 PTO, 10 RSG, 16 AFCDERAT, 19 MAXTHROT, 20 JCTRQDER, 26 STOP, 28 FSSDERAT, 29 EPFDERAT, 41 ATDERAT, 45 TORQMGMT, 46 CTDERAT, 52 AIRDENLM, 53 CHIFULLM, 55 GROSSOVR, 58 OFCDERAT, 61 LOFPRDER.
  - **Renamed to the labels:** 13 `TORQUE_DERATE_OVERRIDE`, 19 `MAXIMUM_THROTTLE`, 22 `CRANKING`, 28 `FUEL_SYSTEM_DERATE`.
  - **Named:** 15 `ALTITUDE_DERATE`, 16 `AIR_FUEL_CONTROL_DERATE`, 24 `ENGINE_BRAKE`, 25 `OVERSPEED`, 27 `SHUTDOWN`, 34 `POWER_TAKE_OFF_DERATE`, 40 `NO_DERATE`, 42 `FUEL_LIMIT_BY_RPM_AND_DEMAND`, 46 `COOLANT_OVERHEAT_DERATE`, 47 `FREE_ACCELERATION`, 59 `NET_TORQUE`.
  - **Still `UNIDENTIFIED`** (their labels are in the comments): 32 / 37 / 38 / 49 / 50.
- **`COLD_START_PHASE` → `ENGINE_STATE`.** `cold_start_phase` is the Cummins engine state FSEGST, now `engine_state`: STOPPED / CRANKING / RUNNING / ENGINE_BRAKE / OVERSPEED / JUMP_START / REENTRY / SHUTDOWN. The old names and comments disagreed for 1 / 4 / 5 / 8.
  - `cm848_updateEngineState` (was `mpc555_processColdStartMainLoop`) sets it.
  - e2m block 1068 lines up 7/7: `power_down_start_flag`, `ecm_power_down_timer`, crank / run time, `engine_is_active_flag` / `engine_is_starting_flag`.
- **The power take-off governor (code-proven).**
  - The CCVS1 builder sends its state as J1939 SPN 976 (PTO governor state), and OBD-II PID 0x1E reports its active flag.
  - Two new enums: `POWER_TAKE_OFF_GOVERNOR_STATE` (e2m PTST remote count / remote run / wait / normal) and `POWER_TAKE_OFF_GOVERNOR_J1939_STATE` (the J1939-71 values).
  - 10 functions and 9 words are renamed, and the dword at 0x3fd89a is split into its two EEPROM words.
  - Entry needs EEPROM 0x480 bits 0 / 1, which are 0 on this truck, so the governor never engages.
- **The limiters.** Each producer is renamed:
  - the altitude derate: engine speed x barometric pressure, cool / hot ambient grids and an air-handling fault grid;
  - the air fuel control (boost smoke) limit;
  - the net torque limit;
  - the variable-speed-governor fuel limit by rpm and demand;
  - the coolant overheat derate. This family was the "unidentified `fuel_coldStart_*` helpers".
- **How it was done.** Two read-only agents read the engine state and the PTO cluster. Their key claims were re-checked here against the code, the dumps and the e2m file. Their prompts and reports are in the session notes.

## Stage 5: the power take-off words, the crank routine, two backwards flags

- **The power take-off governor's words.** Five e2m blocks line up by offset, with matching units and RAM-dump values:
  - **10AB, the PID terms:** filtered speed error, the proportional / derivative / integral terms, droop, the smoothed reference, the QD / QI / QP gain adjustments (0x80 = 1.0) and the no-load fuel.
  - **109E:** `power_take_off_requested_engine_speed`.
  - **11B4, EEPROM:** remote speeds 2-5 = 1400 / 1600 / 1800 / 2000 rpm, set / resume 1100 rpm, minimum reference 1100 rpm, a 2 mph road speed limit, the remote count limit, the ramp rate.
  - **109D:** the 300-1200 rpm engage window.
  - **10AA, the gains and clamps.** The +-1000 rpm speed-error clamps had their names swapped. The "byte" filter constant is the word coefficient 0.8.
- **The crank routine** (e2m 105E / 105F / 1032). The `cold_start_*`, `fuel_timing_*` and `governor_*` words at 0x40a798-0x40a7be are Cummins' crank words:
  - `crank_exit_speed`: CRANKING ends at it;
  - `crank_fuel`: the CRANKING fuel (it was named an rpm);
  - `crank_reentry_speed`: RUNNING drops to REENTRY at it;
  - the crank tables;
  - the ROM settings at 0x406852-0x40687c, which lose a wrong `_cal`;
  - `engine_stopped_speed` (10 rpm; was `engine_rpm_trigger_cal`), `ecm_power_down_timer_threshold` / `_delay`;
  - `engine_brake_driveline_brake_type_cal` = 1 (retarder), so ENGINE_BRAKE is never entered on this truck.
- **Two flags that read backwards:**
  - `engine_starting` is now `engine_shutdown_command_flag` (e2m 10B1 +12 Shutdown). It forces SHUTDOWN and zeroes the injection and the rail pressure setpoint.
  - `engine_shutdown_active_flag` is now `key_off_shutdown_inhibit_flag`: 1 stops a key-off shutdown. Only J1939 diagnostic service 24 sets it.
  - Their setters are `cm848_commandEngineShutdown` and `cm848_inhibitKeyOffShutdown`.
- **The rest:**
  - the engine start / extended idle / extreme ambient AECD words (e2m `EMO_*_AECD_Active` / `_Cap_EL`), renamed again in stage 5b;
  - code 32 = `FUELING_STATE_MASTER_SLAVE_OVERRIDE` (e2m MSOVRIDE, `[MSODEN]` "Enable overriding slave Final_Fueling");
  - the stale `CSP_*` state names in 32 comments, now `ENGINE_STATE_*`.
- **How it was done.** A read-only agent mapped the crank routine. Its e2m offsets, code anchors and dump values were re-checked here before anything was applied. The low-confidence words and the i16 retypes are left for later.

## Stage 5b: the AECD words fixed, the old engine state prose

A review of stage 5 found 16 applied rows that had not been checked. Checking them led to these fixes:

- **The AECD words.** Stage 5's `*_emission_control_active_flag` read backwards: an auxiliary emission control device relaxes NOx control while it is active. They now follow wave 9's `condensation_protection_*` family:
  - `engine_start_warmup_protection_*` (e2m 19B2 / 19B3);
  - `extended_idle_protection_*` (19B0 / 19B1). Its 300 s timer runs only while the low speed governor or the power take-off governor has the fueling;
  - `extreme_ambient_overheat_protection_*` (19A1-19A4): a 217 / 222 °F coolant hysteresis. The old names called it a cold start boost override.
  - Each `_emission_level_cap` goes into the max-select of `fuel_demandMin_maxSelect_rateLimit`. EL is the emission level: the condensation AECD's cap is the "NOx cap value to be used when condensation triggers EGR off".
  - Four calibration rows were added and the three update functions renamed. None of the three AECDs is enabled on this truck (`algorithm_enable_flags_20_cal` = 0x0100).
- **The old engine state words in comments.** "At the governor setpoint" is RUNNING, "fuel mode switch" is ENGINE_BRAKE and "cold start phase 3" is `engine_is_active_flag`. All ten comments were checked against the compare in the code. `fuel_cold_start_phase3_compensation_enable_flag` is now `condensation_count_enable_flag`.
- **A correction.** `combustion_status_flags` bit 0x02 means "engine stopped", so the dump's 0x402 only shows that it was taken with the engine off. The old note "why EGR is requested off on this truck" was a misreading.
- **Checked, no change:**
  - the crank tables: the e2m 8A44-8A4C axes and destinations match the code;
  - ENGINE_BRAKE: its only entry needs `engine_brake_driveline_brake_type_cal` = 0 (e2m: 1 = retarder), and the dump has 1.

## Checks

- **Stage 1.** A fresh baseline build equals the committed `.cpp`. One function is **not label-only**: the reused local in `cm848_arbitrateGovernedFueling` (`wVar1`, first the state and later the fuel) is now two locals, `FVar1` / `wVar2`, with the same values and control flow.
- **Stage 2.** After `reverse_names.py`, the strict check (`check_enum_proof.py`: members and numbers to values, enum type to `word`, locals to placeholders) finds **0 differing functions** and no OR render.
- **Stage 3.** `reverse_names.py` says **EQUIVALENT**: a pure label rename, with all 26 names rendered.
- **Stage 4.** All 103 names render with no `_` variant. After normalizing the members of the four enums, **0 functions differ**, and there is no OR render.
- **Stage 5.** All 104 names render with no `_` variant and no OR render. With the names reversed, one line still differs: an `(undefined *)` cast where the power take-off filter record takes the coefficient's address. It comes from the byte → word fix; `cm848_signedFirstOrderFilter` reads the coefficient as `*(short *)`.
- **Stage 5b.** `reverse_names.py` says **EQUIVALENT**: a pure label rename, all 17 names rendered (one function differs only in the order of its local declarations).
- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.
- The build warnings are unchanged at each stage. `./analyze.sh verify` is deterministic. `lookup_tables.py` is clean. `test_rename_waves`, `test_lookup_tables` and `test_disasm_tools` pass. The headers are regenerated and compile with 0 errors; CM550's are unchanged.

## Not covered (task 045)

- Codes 37 (T2SPD) / 38 (T2TORQ) / 49 (OFCSTATE) / 50 (AFRSTATE) are still unidentified.
- CM550's FSGVFLST typing.
- The six power take-off helper functions, including 0x2abc8, which initializes the whole governor.
- The power take-off filter record (0x3fafb2 pointer + 0x3fafb6 state).
- A shared struct for the 13 global `cm848_signedFirstOrderFilter` records (15 call sites; two pass a pointer through).
- The i16 retypes of the signed crank words, and the four low-confidence crank words.
- The rest of the EMO family: the other inputs of `fuel_demandMin_maxSelect_rateLimit` and its output `fuel_demand_min_threshold`, which look like AECD caps rather than fuel demands.
- The `(int)(short)` temporary compare in `protectionRampRateControl` still renders as a number.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
