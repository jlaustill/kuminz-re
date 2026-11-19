# Stage 4 agents (2026-11-19, PR #52)

Two read-only `general-purpose` agents (model sonnet), started in parallel. Their key claims were checked in the main
session before anything was applied:
- the e2m Engine_State / Fueling_Control_State / PTST labels in `CHR_CC_11.45.01.07.e2m`;
- the block 1068 offsets;
- the engine state transitions;
- the CCVS1 SPN 976 byte and OBD-II PID 0x1E lines;
- the access widths;
- the RAM-dump and EEPROM values.

## 1. Investigate CM848 cold_start_phase states (421k tokens, 97 tool uses, 20 min)

### Prompt

The target was the global `cold_start_phase` (0x40a7c0, enum `COLD_START_PHASE` 0-8), whose member names and comments
disagree (4 ENGINE_RETARDER_ACTIVE vs "fuel mode switch", 5 ENGINE_OVERSPEED vs "cold start suspended", 8
ENGINE_STANDBY vs "cranking", 1 KEY_ON_ENGINE_STOPPED vs "idle / crank speed"). The prompt suggested the e2m FSEGST
"current state of the engine 1-8" (block 1068 +0) as a lead.

It asked for:
- every store and its condition (from the `.cpp`, confirmed with `disasm_func.py`);
- each value's meaning, with cpp-line evidence;
- what the consumers do in each state (`cm848_selectFinalFueling` codes 26 / 22 / 24 / 25 / 27, and the ROM words
  0x5c308 / 0x5c30a);
- the e2m block check.

Naming rules: spelled out, `initialize`, a confidence per claim. Report limit: 700 words. Read-only: no edits, no build,
no commit.

### Report

Result: `cold_start_phase` (0x40a7c0) is Cummins' `Engine_State` (FSEGST): 1-8 = STOP / CRANK / RUN / ENGBRAKE / OVERSPED
/ JUMPSTRT / REENTRY / SHUTDOWN (labelled in `e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m:1196`).
- **Block 1068 lines up 7/7.** Crank block 105E ends at 0x40a7c0.
- **Five `sth` stores.** Four are in `mpc555_processColdStartMainLoop` (0x1c28c) and one in `cm848_initCrankingLimits`.
- **States:**
  - 0 zeroed RAM;
  - 1 STOP: at or below `engine_rpm_trigger_cal`, 10 rpm; fuel 0, code 26;
  - 2 CRANK: up to `governor_rpm_setpoint_output`; crank fuel, code 22;
  - 3 RUN;
  - 4 ENGBRAKE: `engine_retarder_active_flag`; ROM 0x5c308 = 0, code 24;
  - 5 OVERSPED: `engine_overspeed_active_flag`, 4200 / 4000 rpm, P0219; ROM 0x5c30a = 0, code 25;
  - 6 JUMPSTRT: over 50 CRANK passes;
  - 7 REENTRY: after RUN, at or below `cold_start_rpm_threshold`;
  - 8 SHUTDOWN: key off without `engine_shutdown_active_flag`, or `engine_starting` = 1. The power-down timer sets
    `hardware_operation_complete_flag`. Fuel is `timing_limit_upper` = 0, code 27.
- **Proposed names:** `engine_state` / `ENGINE_STATE`; codes 24 / 25 / 27 = ENGINE_BRAKE / OVERSPEED / SHUTDOWN.
- **Correction:** the e2m FSFNFLST keys are hex, so 29=ATDERAT is 0x29 = 41, the immobilizer.
- **Leads** (not applied):
  - `engine_starting` is a protection-shutdown latch and `engine_shutdown_active_flag` suppresses key-off; both names
    may read backwards.
  - `engine_start_inhibit_flag` is only ever stored 0.
  - `prior_boot_faulted` is a live `state != 1` flag.

## 2. Investigate CM848 power take-off cluster (450k tokens, 78 tool uses, 27 min)

### Prompt

The target was the function cluster 0x2a4b0-0x2bbe8 (`cm848_calculateProtectionLoadCompensation`,
`cm848_checkProtectionParamLimit`, `initProtectionParamCalculation`, `cm848_processProtectionControlStateMachine`,
`cm848_initProtectionEvalState`, `cm848_selectPowerTakeOffOrUserFueling`) and its globals.

The hypothesis to test, not assume: this is the power take-off governor. The evidence so far:
- fueling code 4 replaces the user fueling;
- e2m block 1265 PTTH* lines up.

It asked for code-level proof (PTO switches, set speed / resume / ramp, J1939 PTO messages, e2m blocks), per-function
and per-global names with a type shape (enum states), the calibration gating and the RAM-dump state.

Naming rules: `power_take_off` spelled out, never a bare "protection". Report limit: 800 words. Read-only.

### Report

Verdict: confirmed in code.
- **Evidence:**
  - the CCVS1 builder puts `protection_event_code` in byte 7 bits 1-5 (SPN 976 PTO Governor State);
  - OBD-II PID 0x1E bit 0 is switch 3 | `governor_fuel_active_flag`;
  - a PGN 65264 builder;
  - a state machine with switches 3 / 19, brake / clutch cancel, a 2 mph cutout, a 300-1200 rpm window, accelerate /
    coast ramps and a throttle override;
  - e2m blocks 10AB / 10AA / 11B4 / 109E / 109D / 1265 line up.
- **Gating:** `j1939_governor_feature_byte` (EEPROM 0x480) = 0, so the governor never engages. The RAM dump reads WAIT.
- **Proposed functions:** `cm848_runPowerTakeOffGovernorPid`, `cm848_calculatePowerTakeOffGovernorSpeedError`,
  `cm848_runPowerTakeOffGovernor`, `cm848_presetPowerTakeOffGovernorOnEngagement`, `cm848_applyPowerTakeOffTorqueLimit`,
  `cm848_runPowerTakeOffGovernorStateMachine`, `cm848_updatePowerTakeOffGovernorJ1939State`,
  `cm848_smoothPowerTakeOffReferenceEngineSpeed`, `cm848_rampPowerTakeOffReferenceEngineSpeed`,
  `cm848_initializePowerTakeOffGovernorState`.
- **Proposed globals:**
  - `power_take_off_governor_fuel_demand`, `_active_flag`, `_reference_engine_speed`;
  - `_state`, an enum PTST 0 REMOTE_COUNT / 1 REMOTE_RUN / 2 WAIT / 3 NORMAL;
  - `_j1939_state`, an enum of SPN 976 values;
  - `power_take_off_maximum_torque_cal` (EEPROM 0x41c);
  - `power_take_off_torque_limit` (+ state);
  - the 0x3fd89a dword split into `power_take_off_remote_switch_mode_cal` / `_throttle_override_maximum_engine_speed_cal`.
- **Not applied** (listed in task 045):
  - the struct `power_take_off_governor_t` over 0x40af28-0x40af41;
  - the speed calibrations of e2m block 11B4;
  - the `governor_integrator_*` / `protection_rpm_*` misnames;
  - six helper functions;
  - the switch 31 source refinement (engine_feature_enable_flags_cal bit 0x200).
