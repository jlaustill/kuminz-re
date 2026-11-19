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

# Stage 5 agent (2026-11-19, PR #52)

One read-only `general-purpose` agent (model sonnet), run in the background while the main session checked the power
take-off words. The main session checked these before anything was applied:
- the e2m 105E / 105F / 1032 / 10B1 record names and offsets in `CHR_CC_11.45.01.07.e2m`;
- the 10B1 anchor (+A `fault_derate_fuel_limit` = Engine_Protection_Derate_Fueling) and the 1032 overspeed words;
- the EEPROM records 1254 +38 (Crank_Exit_Speed_Switch) and 1180 +16 (EB_Driveline_Brake_Type), and the code that
  reads them;
- the two setters (`cm848_setEngineStarting`, `cm848_setColdStartMode2Flag`) and the injection gate of
  `engine_injectionAngle_writeTpuEvent`;
- the RAM-dump values.

Applied: the high-confidence rows. Skipped: the low / medium rows (0x40a79c, 0x40a7a2, 0x40a7b8, 0x3fdfdc), the i16
retypes and the unnamed DAT_0005b1b6-0x5b1bc words.

## 3. Map CM848 crank routine words (137 tool uses, 28 min)

### Prompt (exact text)

````text
Read-only reverse-engineering research on CM848 (MPC555 PowerPC, big-endian) engine-control firmware. Do NOT edit any file, do NOT run `./analyze.sh build`, do NOT commit. Work in `/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum`.

**Context.** The global at RAM 0x40a7c0 is now `engine_state` (Cummins FSEGST Engine_State, enum `ENGINE_STATE`: 1 STOPPED / 2 CRANKING / 3 RUNNING / 4 ENGINE_BRAKE / 5 OVERSPEED / 6 JUMP_START / 7 REENTRY / 8 SHUTDOWN). It is set by `cm848_updateEngineState` (0x1c28c) in the decompile `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp`; each function starts with `// Function: <name> @ 0x<addr>`. Its e2m block 1068 lines up 7/7 with 0x40a7c0-0x40a7cf.

A previous reading suggested that the `cold_start_*` words around it are Cummins' crank routine, e2m blocks 105E / 105F: RAM 0x40a798-0x40a7bf and ROM / calibration 0x406852-0x40687c. Examples: `cold_start_rpm_threshold` (0x40a7be), `engine_rpm_trigger_cal`, `governor_cold_start_rpm_output`, `cold_start_fuel_mode_ready_flag`, `cold_start_phase26_fuel_mode_flag` (0x40a5f4), `cold_start_phase3_fuel_mode_count*`. Many names here are legacy guesses.

**e2m evidence.** The labelled Chrysler calibration `e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m` (the truck runs V11.46.06) has records `Name,Unit,Block,Offset,...` with descriptions after `;[MNEMONIC]`. Some records also carry hex-keyed value labels (`18=ENGBRAKE:...`). Grep the block, for example `grep -E '^[A-Za-z_0-9]+,[^,]*,105E,' e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m`.

A block's parameters keep their relative offsets in CM848 RAM. Use a block only when 2+ parameters line up with matching units, sizes and code behaviour, and say so. Block bases differ: find each block's CM848 base from 2+ anchors whose code behaviour you can confirm. CM848 CSV rows are in `firmware/CM848_S90140.06_analysis/output/global_variables.csv` (`address,name,type,comment`).

**What I need, for each word in those ranges plus every `cold_start_*` global that the crank / start logic uses:**
1. Its role from the code, citing `.cpp` line numbers and functions.
2. Its e2m match: block, offset, name, unit and description, or "no match".
3. A proposed name and a confidence (high / medium / low).
4. The width from the disassembly when it matters: `python3 firmware/scripts/disasm_func.py <function> 0x<address>`.

Also check two flags whose names may read backwards: `engine_starting` and `engine_shutdown_active_flag`. Say what each really does: who sets and clears it, and what it gates in `cm848_updateEngineState` and elsewhere.

**Rules:**
- `_cal` only for EEPROM-backed values: the CM848 EEPROM RAM mirror is 0x3fd482-0x3feec1. ROM / flash / working RAM never get `_cal`, so strip a wrong `_cal`.
- Spell words out, with no invented abbreviations. Only universal ones are allowed: RPM, J1939, ECM, PID, ADC, PWM, TPU, QADC, TSC1. Use "initialize", not "init".
- Never write a bare "protection": say protection of what.
- Say "unknown" rather than guess.

**Return** a compact report of at most 800 words:
- a table `address | old name | proposed name | evidence (cpp lines + e2m record) | confidence`;
- the two flags' verdict;
- anything that contradicts the context above.
````

### Report (exact text, the agent's handback message)

````text
Conventions: c#=cm848_rom.ghidra.cpp line (cm848_ functions): c17824 calculateColdStartFuelAdjust, c17893 calculateColdStartRpmAdjust, c17938 calculateColdStartTempTable, c17994 calculateIntakeAirAdjustment, c18032 checkColdStartConditions, c18053 processColdStartAdjustment, c18074 initColdStartTablePointers (jump-start ramp), c18106 processColdStartStateMachine (exit-fuel ramp), c18131 coldStartRpmTableLookup (timers), c18158 coldStartFuelFactorLookup, c18218 updateEngineState, c19316 selectFinalFueling. e2m = CHR_CC_11.45.01.07; +off = same offset in CM848; proposed names are e2m names spelled out. Blank conf = high. All words 16-bit (xref plus whole-ROM/flash2 scan); e2m-signed ones use lha: type i16 (0x40a79a/9c/a2/a6/b6/b8, 0x406858/5a/64/66/68).

Alignment (once; confirms the earlier 105E / 105F reading for all 42 words): 105E base 0x40a798 ends at 1068 (0x40a7c0). 105F base 0x406852: dump bytes equal ROM 0x6c46c (ROM copy, never written, outside the EEPROM mirror, so strip `_cal`); 1032 follows at 0x40687e. Units agree: helpers run every 4th phase = 20 ms = e2m SEC x0.02; two ramps run once per 40 phases = 200 ms = e2m "/SEC" x5; init and clamp +-1024 = e2m +-120 deg; dump: exit 800 rpm, exit time 3 s, re-entry 500 rpm (= RAM 4000).

|addr|old|new|evidence|conf|
|--|--|--|--|--|
|0x40a798|cold_start_advance_counter|crank_exit_timer|105E+00 c18135, c18035||
|0x40a79a|cold_start_rpm_adjust_b|crank_advance|+02 c17920||
|0x40a79c|cold_start_rpm_adjust_c|crank_4d_timing|+04 written -1024 c17880, never read; "4D" unknown|medium|
|0x40a79e|injection_timing_base_limit_working|crank_adjusted_initial_fuel|+06 c17851||
|0x40a7a0|fuel_timing_rpm_upper_limit|crank_adjusted_initial_rpm|+08 c17846||
|0x40a7a2|unnamed|crank_wet_stack_timing|+0A no access found|low|
|0x40a7a4|fuel_timing_correction_c|crank_coolant_exit_fuel|+0C c17836||
|0x40a7a6|fuel_timing_correction_a|crank_initial_advance|+0E c18009||
|0x40a7a8|fuel_timing_correction_b|crank_exit_fuel_adjustment|+10 c18111||
|0x40a7aa|governor_rpm_setpoint_output|crank_exit_speed|+12 c17981, ends CRANKING c18290||
|0x40a7ac|governor_cold_start_rpm_output|crank_fuel|+14 FUEL quantity c19345||
|0x40a7ae|fuel_timing_base_limit|crank_initial_fuel|+16 c17946||
|0x40a7b0|governor_fuel_timing_offset|crank_initial_fuel_adjustment|+18 c18087||
|0x40a7b2|fuel_timing_advance_cal|crank_initial_advance_break_speed|+1A c18014, RAM so no _cal||
|0x40a7b4|fuel_timing_table_output|crank_initial_fuel_break_speed|+1C c17952||
|0x40a7b6|cold_start_rpm_adjust_a|crank_exit_advance|+1E c17881||
|0x40a7b8|unnamed|injection_timing_before_startup|+20 only unreferenced code writes it|medium|
|0x40a7ba|torque_fuel_offset_trim|crank_initial_rpm_adjustment|+22 c18093||
|0x40a7bc|crank_event_sample_counter|crank_jump_start_timer|+24 c18142, c18299||
|0x40a7be|cold_start_rpm_threshold|crank_reentry_speed|+26 c18037, c18309||
|0x406852|fuel_timing_correction_c_cal|crank_exit_fuel_override|105F+00 c17843||
|0x406854|fuel_timing_correction_b_max_cal|crank_exit_fuel_ramp_maximum|+02 c18113||
|0x406856|cold_start_fuel_timing_correction_addend_cal|crank_exit_fuel_ramp_rate|+04 c18112||
|0x406858|fuel_timing_correction_load_max_cal|crank_high_manifold_temperature|+06 c18003||
|0x40685a|fuel_timing_correction_offset_cal|crank_low_manifold_temperature|+08 c18002||
|0x40685c|torque_fuel_timing_offset_cal|crank_jump_start_rpm_ramp_rate|+0A c18093||
|0x40685e|cold_start_fuel_timing_rpm_threshold_cal|crank_exit_fuel_ramp_rpm|+0C c18110||
|0x406860|cold_start_rpm_setpoint_cal|crank_exit_rpm|+0E c17983||
|0x406862|cold_start_advance_count_cal|crank_exit_time|+10 c18035||
|0x406864|cold_start_coolant_temp_threshold_cal|crank_jump_start_temperature_threshold|+12 c18082||
|0x406866|fuel_timing_correction_a_high_cal|crank_high_manifold_temperature_timing|+14 c18004||
|0x406868|fuel_timing_correction_a_low_cal|crank_low_manifold_temperature_timing|+16 c18009||
|0x40686a|fuel_timing_advance_high_cal|crank_high_manifold_temperature_rpm|+18 c18005||
|0x40686c|fuel_timing_advance_low_cal|crank_low_manifold_temperature_rpm|+1A c18014||
|0x40686e|cold_start_rpm_base_cal|crank_initial_reentry_speed|+1C c18041||
|0x406870|cold_start_rpm_threshold_addend_cal|crank_exited_reentry_speed_offset|+1E c18037||
|0x406872|cold_start_torque_fuel_offset_cal|crank_exited_initial_rpm_offset|+20 c18164||
|0x406874|governor_fuel_timing_offset_addend_cal|crank_jump_start_fueling_ramp_rate|+22 c18087||
|0x406876|fuel_timing_base_limit_cal|crank_initial_fuel_override|+24 c17956||
|0x406878|fuel_timing_table_override_cal|crank_initial_speed_override|+26 c17959||
|0x40687a|cold_start_governor_fuel_timing_offset_cal|crank_exited_initial_fueling_offset|+28 c18163||
|0x40687c|cold_start_crank_event_threshold_cal|crank_jump_start_time|+2A c18299||
|0x406884|engine_rpm_trigger_cal|engine_stopped_speed|1032+06 c18268; 1032 base 0x40687e, 6/6 with overspeed words||
|0x406886|governor_speed_engage_count_target_cal|ecm_power_down_timer_threshold|1032+08 c18356, 60 s||
|0x406888|governor_speed_engage_fault_count_threshold_cal|ecm_power_down_delay|1032+0A c18358, 2 s||
|0x3fd872|cold_start_rpm_active_flag|crank_exit_speed_switch_cal|1254+38, EEPROM+0x3f0; base 0x3fd83a, 15+ J1939 priority words by PGN; c17982; dump 0 = idle reference||
|0x3fd53e|cold_start_fuel_mode_ready_flag|engine_brake_driveline_brake_type_cal|1180+16, EEPROM+0xbc; base 0x3fd528: +02 85 mph, +04 106 mph, +0E two_speed_axle_enable_cal; 1 = retarder; c18305; dump 1||
|0x3fd5c4|cold_start_feature_enable_flags|algorithm_enable_flags_20_cal|106B+2A, EEPROM+0x142; 7 tested masks 0x100-0x8000 = its e2m enable bits; dump 0x0100||
|0x3fdfdc|engine_rpm_trigger_ready_flag|engine_startup_inhibit_cal|candidate: 1096+00 calibration record, single-record block; never written; c18268 needs 0|low|
|0x3fa840|cold_start_rpm_threshold_updated_flag|crank_reentry_speed_offset_applied_flag|c18035, c18139; no e2m|medium|
|0x5b1be-0x5b1e4|cold_start_fuel_demand_base_*|crank_initial_fuel_{x_axis,y_axis,grid}|8A49/48/47||
|0x5b25c-0x5b282|cold_start_fuel_demand_at_governor_setpoint_*|crank_exit_fuel_*|8A4C/4B/4A||
|0x5b2fa,0x5b30c|cold_start_fuel_ramp_start_rpm_*|crank_initial_speed_{axis,values}|8A46/45||
|0x5b1b6-0x5b1bc|DAT_0005b1b6/b8/ba/bc|crank_initial_default_fuel, _default_rpm, _fuel_maximum, _speed_maximum|8A44+0/2/4/6; 70 mm3, 450, 200 mm3, 950 rpm||
|0x40a5f4/f6|cold_start_phase26_fuel_mode_flag, fuel_coldStart_phase26_demand_floor|engine_start_warmup_protection_active_flag, _emission_level_cap|19B3+0/+2 c61560||
|0x40a5f8/fa|cold_start_phase3_fuel_mode_count_met_flag, _fuel_demand_floor|extended_idle_protection_active_flag, _emission_level_cap|19B1+0/+2||
|0x3fbc9c, 0x406570|cold_start_phase3_fuel_mode_count, _count_max|extended_idle_timer, extended_idle_time_threshold|19B0+02; +2 per 0.2 s c61610|medium|
|0x40a5fc/fe|cold_start_boost_override_*|extreme_ambient_overheat_protection_active_flag, _emission_level_cap|19A4; coolant 217/222 degF (19A1): hot, not cold||

Flags. engine_starting (0x40a784) is a shutdown request: e2m 10B1+12 Shutdown ("turn off all solenoids"); block base 0x40a772, 10 anchors (fault_derate_* words +0A/0C/0E/10/14/16/18, governor_fuel_derate_state +1E). Setters: fault-derate monitor c63996, c64025, c64041, held c64059 by governor_faultDerate_latch (cleared in STOPPED c63929); J1939 service 6. Cleared by cm848_completeEngineStartSequence and SHUTDOWN at rpm 0 (c18346). Gates: STOPPED/RUNNING to SHUTDOWN (c18278, c18315, c18368); injection quantity 0 (c84787); rail pressure setpoint 0 (c85696); final fueling (c19329). Name engine_shutdown_command_flag, high.
engine_shutdown_active_flag (0x40aa98) is inverted: 1 suppresses key-off shutdown. Only setter J1939 service 24; cleared at the key-on edge (c18374). Key off and flag 0: SHUTDOWN (c18278, c18314, c18368), power-down timer counts (c18350), injection 0 (c84787), rail pressure governor KEY_OFF (c46631). Name key_off_shutdown_inhibit_flag, medium (120C+04 FSS_Key_Off_Shutdown is a one-anchor candidate; 120C does not line up).
0x40a334 engine_start_inhibit_flag: keep; working RAM, only written 0 (c18403).

Contradictions: governor_cold_start_rpm_output is fuel; the fuel_timing/injection_timing/torque_fuel/governor names at 0x40a79e-0x40a7ba are crank names. `_cal` is wrong on 0x406852-0x40687c, 0x406884-0x406888 and 0x40a7b2, missing on 0x3fd53e/5c4/872 and 0x3fdfdc. crank_advance and injection_timing_before_startup are used only by code at 0x1bee8-0x1bf40 (states 2/6/7; overwrites timing 0x40a2f0): no caller found (b/bl/bc, lis+addi/ori, 16/32-bit literals, ROM+flash2). ENGINE_BRAKE is not entered with this calibration. Stale: enums.csv:897 (CSP_*) and two global comments use old state names; engine_injectionAngle_writeTpuEvent plate reads engine_starting backwards; cm848_setEngineStarting and cm848_setColdStartMode2Flag are misnames. Untraced cold_start_* (protection, battery, timer_a/b, active_flag_c, engine_sync, intake_temperature_filter): other domains, unknown.
````
