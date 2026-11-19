## Summary

`governor_fuel_demand_mode` (0x40a154) is an enum: the Cummins **FSGVFLST** governed fueling state ("indicator as to which algorithm is in control of fueling after it is governed"). Its codes come from one numbering that every fueling stage shares, so the enum is shared too. This PR does three stages:

1. **The enum.** `ENGINE_OPERATING_MODE` is now **`FUELING_STATE`**. Members 4 / 9 / 10 / 11 / 12 are new, the user and governed carriers are typed, 0x40b67c is renamed and the dword at 0x3fb526 is split.
2. **The later stages.** The derate, combustion and final stages get 17 more members proved from their setters, plus 16 `FUELING_STATE_UNIDENTIFIED_<n>` placeholders. Ten more carriers are typed, including `governor_mode_code`, now `final_fueling_state`.
3. **The arbitration.** 16 functions and 10 words of the fueling arbitration are renamed from legacy `*Protection*` / `governor_*` guesses.

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
- **Members.** 9 cruise control / 10 vehicle speed limit / 11 low speed governor / 12 high speed governor come from the code. 4 power take-off is **e2m-derived**: the code shows only another governor's command replacing the user fuel.

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

  e2m labels 29 ATDERAT, but CM848's 29 is the fault derate: its numbering differs from the e2m list above 12.
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

## Checks

- **Stage 1.** A fresh baseline build equals the committed `.cpp`. One function is **not label-only**: the reused local in `cm848_arbitrateGovernedFueling` (`wVar1`, first the state and later the fuel) is now two locals, `FVar1` / `wVar2`, with the same values and control flow.
- **Stage 2.** After `reverse_names.py`, the strict check (`check_enum_proof.py`: members and numbers to values, enum type to `word`, locals to placeholders) finds **0 differing functions** and no OR render.
- **Stage 3.** `reverse_names.py` says **EQUIVALENT**: a pure label rename, with all 26 names rendered.
- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.
- The build warnings are unchanged at each stage. `./analyze.sh verify` is deterministic. `lookup_tables.py` is clean. `test_rename_waves`, `test_lookup_tables` and `test_disasm_tools` pass. The headers are regenerated and compile with 0 errors; CM550's are unchanged.

## Not covered (task 045)

- The 16 `FUELING_STATE_UNIDENTIFIED_<n>` codes still need names. 24 / 25 / 27 first need the `COLD_START_PHASE` members 4 / 5 / 8, which disagree with their own comments.
- CM550's FSGVFLST typing.
- The rest of the power take-off cluster at 0x2a4b0-0x2bbe8.
- The `(int)(short)` temporary compare in `protectionRampRateControl` still renders as a number.

🤖 Generated with [Claude Code](https://claude.com/claude-code)
