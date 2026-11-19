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

# Stage 6 agents (2026-11-19, PR #52)

Two read-only `general-purpose` agents (model sonnet), started in parallel while the main session typed the
signed filter records (stage 6a). Checked in the main session before anything was applied:
- the emission manager agent's base proof, the ECU's own parameter ID table in flash2 (0x53be38, 6-byte
  [id][address] records): an independent parser (`parameter_id_table.py`, then
  `firmware/scripts/e2m_block_addresses.py`) reproduces every block base proved earlier (105E, 105F, 1032, 10B1,
  1068, 10AA, 109D, 109E, 11B4, 19A1-19B3, 1180, 1254) and every e2m address both agents give;
- the 11B4 words of stage 5 against the table base (0x3fd884: +2..+16 as named);
- the access widths of every new row (width_census.py), `algorithm_enable_flags_20_cal` bit 0x100 in the air
  handling code, the two medium-confidence function names, the three PGN priority words and the cruise switch
  debounce;
- the stage-5 comment contradictions the power take-off agent found (all fixed in stage 6b).

Not applied: the store-only 0x3fba22 / 0x3fba24, the i16 retypes, the PGN 65264 byte 6 / 7 SPN identities, the
compressor outlet temperature scale question and DAT_003fba26 / DAT_003fba36 (no writer found).

## 4. Map CM848 PTO helper functions (567k tokens, 139 tool uses, 31 min)

### Prompt (exact text)

````text
Read-only research on the CM848 (Cummins ISB, MPC555) firmware analysis. Do NOT edit any file, do NOT run `analyze.sh`, do NOT commit. Return a table of naming proposals with evidence.

## Where things are
- Worktree root: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum
- Decompiled output: firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp. The CSVs that name things are in the same folder: global_variables.csv (address,name,type,comment), function_renames.csv (address,name,plate comment), structure_definitions.csv.
- RAM dump: firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin. Address A is at file offset A - 0x3FA000, big-endian. Read a value at its declared width only (a byte flag at an odd address is one byte).
- A labelled Chrysler calibration: e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m. Record fields: name,unit,block(hex),offset(hex),...; the description follows `;`. e2m blocks line up with CM848 RAM by relative offset. A block's base is proved only when 2+ records with matching units agree with the code.
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines` prints a function body;
  - .../width_census.py `<all.dis> 0xADDR...` prints the load/store widths of an address (all.dis is in the same folder);
  - .../writers.py lists the assignments of a global (read its header for usage).

## Known (PR #52, verified)
The function cluster around 0x2a2d0-0x2bbe8 is the power take-off (PTO) governor:
- `cm848_calculatePowerTakeOffGovernorSpeedError`;
- J1939 CCVS1 SPN 976 state;
- enums POWER_TAKE_OFF_GOVERNOR_STATE / POWER_TAKE_OFF_GOVERNOR_J1939_STATE;
- e2m 10AA (gains / clamps, ROM 0x40718e-0x4071a2), 10AB (the governor terms 0x40af2a-0x40af4a, `power_take_off_governor_*`), 109D (engage window 0x4071d8), 109E (0x40af4c requested speed), 11B4 (EEPROM calibrations 0x3fd886-0x3fd89a, `power_take_off_*_cal`).

Several older names in this cluster say "protection" or "governor" but belong to the PTO governor.

## Targets
1. The six helper functions:
   - 0x2abc8 `cm848_initProtectionFilterState` (it initializes the governor: the filter record, the smoothing pointer, the QD / QI / QP gain adjustments = 0x80, the four `governor_pid_interp_state_*` = 2);
   - 0x2ad28 `cm848_setProtectionParamFromRpm`;
   - 0x2ad48 `cm848_initProtectionSmoothingPointer`;
   - 0x2bd38 `cm848_resetProtectionBypass`;
   - 0x2bd58 `cm848_j1939HandlePgn65264Pto`;
   - 0x2bed4 `cm848_initJ1939PtoBuffer`.
   For each: what it does, its callers, the proposed name.
2. The working words 0x3fafac-0x3fafde:
   - `protection_monitored_rpm_snapshot`, `governor_speed_gain_factor`, `governor_pid_derivative_snapshot`, `governor_speed_product`, `governor_fuel_active_prev_flag`;
   - `governor_pid_interp_state_a`..`_d`;
   - `protection_smoothing_filter_state` (typed `ema_filter_state_t`);
   - `protection_control_state_flags`, `governor_rpm_transition_flag`, `governor_rpm_reference_ramped` / `_target`, `governor_rpm_integrator_high`.
   Also the tables `protection_rpm_axis_cal` / `protection_rpm_values_cal` (0x4071ac / 0x4071c2, word[11]). Say which are PTO and what each holds.
3. EXCLUDE from proposals 0x3fafb2 / 0x3fafb6. That is a `cm848_signedFirstOrderFilter` record being typed in the main session. Just say what it filters.

## Naming rules
- Spell words out. No invented abbreviations; allowed: RPM, J1939, PGN, ECM, PID, TPU, ADC, PWM. The repo spells out `power_take_off`.
- Never a bare "protection": say protection of what.
- `initialize`, not `init`.
- Decimal numbers in names.
- `_cal` only for the EEPROM mirror 0x3fd482-0x3feec1. ROM-copied 0x40xxxx calibrations get no `_cal`, so a 0x4071ac table drops it.
- Functions: `cm848_` + lowerCamelCase verb phrase.

## Evidence for every proposal
- the code lines (line numbers in the .cpp);
- the access width from width_census (quote it);
- the e2m record (block +offset name and description) when one exists, with how the block base was proved;
- the RAM dump value;
- confidence high / medium / low.

Skip a symbol rather than guess. Flag anything that contradicts a stage-5 name.

## Output
One markdown table (address | current | proposed | type | evidence | confidence), then a short list of contradictions and open questions. Keep it under ~120 lines.
````

### Report (exact text, the agent's handback message)

````text
Read-only: no repo file was touched; scratch is in /tmp/pto_research.

**Provenance**
- `L<n>` = line in the COMMITTED `cm848_rom.ghidra.cpp` at 5ed0272 (stage 6a). It is extracted at /tmp/pto_research/head.cpp. The live .cpp was being rebuilt while I worked (it had 25,647 lines at 13:4x, and 88,907 lines at an earlier check), so I did not cite it. `@0x...` instruction addresses and function@address never move.
- `WC` = width_census.py, quoted as printed. It prints "none" when the address is built with lis+addi and undercounts others, so `DF` (disasm_func.py verdict) and `AS` are the real width proof.
- `AS` = my whole-image scan of ROM + flash2: lis+displacement, lis+addi/ori address builds, step-1 pointer words, and raw displacement greps. Every hit for 0x3fafac-0x3fafec and the PGN 65264 buffer lies in the PTO functions 0x2a2d0-0x2bed4, none below 0x7F60, so the time-shared window is not a conflict.
- Dump = key on, engine stopped, PTO state WAIT (0x40af50 = 2). Most working words read 0 and prove nothing. Only the caches (2), the coefficient pointers (0x3fafb2 = 0x407190, 0x3fafcc = 0x4071a0) and the 0x3fafe8 array discriminate.
- WARNING: the local j1939 Mongo doc for number 65264 is wrong (name "SPN", it holds PGN 65266 fuel-economy parameters). SPNs 90 / 186 / 187 / 978-984 are absent. I used it for nothing.

| address | current | proposed | type | evidence | conf |
|---|---|---|---|---|---|
| 0x2abc8 | cm848_initProtectionFilterState | cm848_initializePowerTakeOffGovernorFiltersAndGains | void(void) | Boot init of the PTO governor (L27784-27800). Asm 0x2abd4-0x2ac30: `power_take_off_speed_error_filter` accumulator := 0 (stw@0x2abe0), coefficient ptr := 0x407190 (stw@0x2abec), `bl 0x2ad48` @0x2abf0, QD/QI/QP adjustments 0x40af44/46/48 := 0x80 (sth@0x2abfc/04/0c), caches 0x3fafc6/c8/ca/c4 := 2 (sth@0x2ac18/20/28/30). Only caller: cm848_dispatchModeHandlers @0x42978 (bl@0x4298c, L43613), itself called only by cm848_applicationMain's boot sequence (L55879). No pointer word to it (step-1 scan). Dump agrees. | high; name med-high (alt `...Pid`) |
| 0x2ad28 | cm848_setProtectionParamFromRpm | cm848_presetPowerTakeOffSmoothedReferenceEngineSpeed | void(void) | Smoothed reference 0x40af40 := engine speed (lhz 0x40b7ba @0x2ad30, sth@0x2ad34); reference filter accumulator 0x3fafd0 := 0 (stw@0x2ad40) (L27862-27870). Only caller: cm848_presetPowerTakeOffGovernorOnEngagement @0x2a960 (bl@0x2a97c, L27707), first active pass. That preset then zeroes the error filter, filtered error and PD fueling and presets the integrator. | high |
| 0x2ad48 | cm848_initProtectionSmoothingPointer | cm848_initializePowerTakeOffReferenceFilter | void(void) | Clears the accumulator (0x3fafd0, stw@0x2ad54) and points the coefficient at power_take_off_reference_filter_coefficient (0x4071a0, stw@0x2ad60) of the EMA record at 0x3fafcc, which cm848_smoothPowerTakeOffReferenceEngineSpeed uses (L27876-27884). Only caller: cm848_initProtectionFilterState (bl@0x2abf0, L27792). | high |
| 0x2bd38 | cm848_resetProtectionBypass | cm848_initializePowerTakeOffThrottleOverride | void(void) | power_take_off_throttle_override_flag (0x40af58) := 0 (sth@0x2bd40); power_take_off_throttle_override_engine_speed_limit (0x40af56) := engine_speed_limit_default_cal (lhz 0x3fd814 @0x2bd4c, sth@0x2bd50) (L28410-28418). These are the same two stores cm848_selectPowerTakeOffOrUserFueling makes whenever the throttle is not overriding. e2m 1265 +0 PTTHDQRP / +2 PTTHOV (base already proved by +4 / +6 = operating_mode_governor_output). Only caller: cm848_applicationMain (bl@0x5499c, L55888), right after cm848_initializePowerTakeOffGovernorState. | high; name med-high ("reset" also fits) |
| 0x2bd58 | cm848_j1939HandlePgn65264Pto | cm848_buildPgn65264PowerTakeOffInformationMessage | void(void) | Builds and sends the 8-byte PGN 65264 message via `sendJ1939Message(&j1939_working_tx_message)` (addi@0x2beb8, L28485; body L28424-28490). Payload at 0x3fb002: FF, FFFF, then bytes 4-5 = byte-swapped power_take_off_requested_engine_speed when j1939_governor_feature_cal bit 0x10 is set (dump 0xD0, L28442), else FFFF; byte 6 and byte 7 are 2-bit fields (0 off, 1 on, 3 datalink-sourced) from switches 19 + 3 and switch 31; byte 8 FF. Callers: `cm848_j1939RegisterPgnHandler(0xfef0,..)` in cm848_initJ1939ProtocolHandlers (lis/addi@0x23314-0x23324, L22834, request responder) and `diag_record_queue_add_entry(0,0xfef0,100,0x96,..)` in cm848_j1939_system_init (lis/addi@0x5393e4-0x5393f4, L94520, 100 ms broadcast). A step-1 scan of ROM + flash2 finds no 32-bit pointer to it, so the "6-byte table at 0x539508" in PTR_POINTERS_DOCUMENTATION.md is unbacked (those flash2 bytes are code). Identity: e2m 1254 +2C [JCPTPZ] "Power Takeoff Information message", and known_pgns.txt line 20 (live reply `18FEF000#FF FF FF 00 00 CC CC FF`) equals the dumped payload. Precedent: the 65263 sibling was renamed from ...HandlePgn65263... to cm848_buildPgn65263EngineFluidLevelPressure1Message for the same pattern. | high |
| 0x2bed4 | cm848_initJ1939PtoBuffer | cm848_initializePgn65264PowerTakeOffInformationBuffer | void(void) | Fills the PGN 65264 transmit descriptor j1939_working_tx_message (0x3faff4): can_id = ((j1939_pgn65264_source_address_bits & 7) << 2) top byte, 0xFEF000, j1939_source_address (lhz 0x3fd866 @0x2beec); length 8; data ptr 0x3fb002, end 0x3fb00a; payload bytes 1, 2-3, 8 := FF (L28492-28509). Dump can_id 0x18FEF000 (priority 6). Only caller: cm848_j1939_system_init (bl@0x53928c, flash2, L94498); sibling of cm848_initializePgn65249RetarderConfigurationBuffer. | high |
| 0x3fafac | protection_monitored_rpm_snapshot | power_take_off_governor_smoothed_reference_engine_speed_previous | word | Only in cm848_calculatePowerTakeOffGovernorSpeedError: `if (snapshot != smoothed reference)` recompute the gain multiplier (L27476, lhz@0x2a340), then `snapshot = smoothed reference` (L27502, sth@0x2a3f0). WC: none (addr-of@0x2a334); DF: word. e2m: none. Quirk: the engagement preset recomputes the multiplier without updating it. | high on meaning; name medium |
| 0x3fafae | governor_speed_gain_factor | power_take_off_gain_adjustment_multiplier | word | Q14 (0x4000 = 1.0) multiplier of the PTO speed error. Set by the speed error function: 0x20c / calculated / 0x7ccc (CALCULATED, L27481-27491) or the table lookup (TABLE, L27495-27499); also by the preset (L27736). Read as `error x factor >> 14` before the error filter (L27503, lha@0x2a3f8) and in the PID (L27553, x QP adjustment -> droop coefficient, lhz@0x2a4e0). WC `{'lhz': 1, 'sth': 1} -> 2 byte`; DF word. e2m: no record; indirect only: 10AB +2 PTO_Filtered_Error_Term "Gain adjusted and filtered". Clamps 0x20c / 0x7ccc x 1/16384 = 0.03198 / 1.94995 = the PTGNTB limits 0.032 / 1.95. This calibration (mode 0, offset 328 < 0x20c): 524 when running. | high |
| 0x3fafba | governor_pid_derivative_snapshot | power_take_off_governor_proportional_derivative_fueling_previous | dword | cm848_runPowerTakeOffGovernor copies PTO_PD_Fueling (0x40af3c) here before each pass (L27772, stw@0x2ab7c). The PID uses it only in the tracking branch while final_fueling_state != FUELING_STATE_POWER_TAKE_OFF: integrator = scaled fuel_demand_computed - snapshot (L27622-27634, lwz@0x2a7f8). WC `{'lwz': 1, 'stw': 1} -> 4 byte`. e2m: none. | high |
| 0x3fafbe | governor_speed_product | power_take_off_governor_integral_fueling_working | dword | The PID integrator: tracking init (L27633), `+= (P+D-droop) x (0x8000-K) / 0x8000 x QI / 0x80` (L27646), clamp (L27651-27653), then published to power_take_off_governor_integral_fueling (0x40af34, e2m 10AB +C) at L27655, and by the preset (L27747-27748). Those two copies are 0x40af34's only writers. WC: none (addr-of@0x2a75c / 0x2aac4); DF dword (PID stw@0x2a7c8/7f0/800/870/890, lwz@0x2a868/894; preset stw@0x2aad8/0x2ab04). | high |
| 0x3fafc2 | governor_fuel_active_prev_flag | power_take_off_governor_active_previous_flag | word | cm848_runPowerTakeOffGovernor: first active pass (prev == 0) runs the engagement preset (L27768, lhz@0x2ab5c); prev := power_take_off_governor_active_flag at the end (L27777, sth@0x2abac). WC: none (addr-of@0x2ab4c); DF word. | high |
| 0x3fafc4 | governor_pid_interp_state_d | power_take_off_gain_adjustment_cached_axis_offset | word | Argument 1 of both `lookupTableInterpolation(&..., smoothed reference, 0x4071ac, 0x4071c2, 0)` calls (L27497 speed error, L27731 preset; addr-of@0x2a3c4 / 0x2aa14); init sth@0x2ac30 (L27799). WC `{'sth': 1} -> 2 byte`; dump 2 (the lookup never ran). | high |
| 0x3fafc6 / c8 / ca | governor_pid_interp_state_a / _b / _c | power_take_off_unused_cached_axis_offset_1 / _2 / _3 | word | Only access anywhere is `li 2; sth` in cm848_initProtectionFilterState (@0x2ac18 / 0x2ac20 / 0x2ac28, L27796-27798). AS: no load, no address build, no data pointer. Precedent: unused_lookup_cached_axis_offset_1/2 (0x3fa114/16) and the HSG caches 0x3fa896-9a. The quadratic-adjustment inputs are also unread: 10AA +16/+18/+1A/+1C at 0x4071a4-aa (dump 640 640 640 23200) have AS 0 hits, and the QD/QI/QP adjustments are only ever written 0x80. Do not assign D/I/P: nothing distinguishes the three. WC `{'sth': 1} -> 2 byte` each; dump 2. | medium |
| 0x3fafcc | protection_smoothing_filter_state | power_take_off_reference_filter_state | ema_filter_state_t | exponentialMovingAverage record (+0 coefficient ptr, +4 accumulator 0x3fafd0). When abs(requested - smoothed) > power_take_off_reference_step_limit the accumulator is loaded with smoothed << 16 and one EMA step toward power_take_off_requested_engine_speed is taken (L27832-27835), giving the smoothed reference 0x40af40. Coefficient 0x4071a0 = 0xf333 = 0.95 (e2m 10AA +12 PTO_Reference_Ramp_Const). WC: none at 0x3fafcc (DF dword, stw@0x2ad60), `{'stw': 1} -> 4 byte` at 0x3fafd0; dump 0x3fafcc = 0x4071a0. Kept `_filter_state` (EMA record convention, pairs with `..._filter_coefficient`); the main session's `_filter` suffix is for its signed-filter records. Alt: `power_take_off_reference_filter`. | high |
| 0x3fafd4 | protection_control_state_flags | power_take_off_governor_switch_state_bits | dword (keep) | Ten switch channels, bit 2n = this pass, bit 2n+1 = last pass (`(flags & 0x55555) * 2`, L28031). ch0 0x1 cruise RESUME = accelerate; ch1 0x4 COAST; ch2 0x10 cruise on/off toggle (switch 3 hardwired) = cab PTO on; ch3 0x40 switch 31 (hardwired mode only); ch4 0x100 cruise SET; ch5 0x400 switch 31 (set+resume); ch6 0x1000 switch 19 remote PTO switch; ch7 0x4000 switch 15 clutch; ch8 0x10000 switch 11 brake; ch9 0x40000 cruise CANCEL. Init sets 0x2000 (L28342). Mode from engine_feature_enable_flags_cal & 0x200 (0x27EF here, cruise-ladder mode). WC `{'lwz': 1} -> 4 byte` (undercount); DF dword: 37 accesses in the state machine, 1 in the J1939 state, 2 in init. Keep dword: whole-word OR-assignments and `* 2` would print as `._N_` pieces if a bitfield (wave 11 rule). | high; name med-high |
| 0x3fafd8 | governor_rpm_transition_flag | power_take_off_engagement_ramp_complete_flag | word | cm848_rampPowerTakeOffReferenceEngineSpeed: `if (ramped + power_take_off_engagement_slew_rate_cal < target && flag == 0) ramped += slew; else { ramped = target; flag = 1; }` (L28296-28303). Cleared while inactive (L28309), in WAIT (L28233) and init. The slew ramp runs once per engagement, then the reference follows the target directly. WC `{'sth': 4, 'lhz': 1} -> 2 byte`. e2m: none (PTAERT describes only the slew rate). | high |
| 0x3fafda | governor_rpm_reference_ramped | power_take_off_engagement_ramp_engine_speed | word | Running value of that ramp: copied to power_take_off_requested_engine_speed (L28305) and reloaded from it / from the engine speed at the end (L28311), so it equals the requested speed after every pass. WC `{'sth': 2} -> 2 byte` (undercount); DF 5 + 1 accesses, lhz/sth only. e2m: none. | high |
| 0x3fafdc | governor_rpm_reference_target | power_take_off_target_engine_speed | word | Written only by the state machine: remote array entry / resume / set / set+resume speed / current rpm (+ droop) / +- power_take_off_ramp_rate_cal on accelerate / coast, clamped to [power_take_off_minimum_reference_engine_speed_cal, 0x3fdd00 = 1500 rpm maximum] (L28119, L28179, L28251-28276). Read by the ramp (L28297) and, by equality compares, cm848_updatePowerTakeOffGovernorJ1939State. WC `{'lhz': 7, 'sth': 2} -> 2 byte`; DF 10 + 5 + 1 accesses. e2m: none. | high |
| 0x3fafde | governor_rpm_integrator_high | power_take_off_saved_cab_target_engine_speed | word | Saved when the remote switch interrupts cab control (NORMAL -> REMOTE_COUNT: `= target`, L28221). In REMOTE_COUNT a timeout with 0 saved goes to WAIT (L28089); with a value it returns to NORMAL with `target = saved` (L28099). Cleared in WAIT (L28238) and init (L28336). WC `{'lhz': 2, 'sth': 3} -> 2 byte`. e2m: none. | med-high |
| 0x4071ac | protection_rpm_axis_cal | power_take_off_gain_adjustment_axis (drop `_cal`) | word[11] | PTO. Length word 20 + 10 breakpoints 0, 4000 ... 36000 (x 0.125 = 0-4500 rpm in 500 rpm steps) = e2m 13B2 PTO_Gain_Speed_Axis [PTSPAX] (max 4500). Input = power_take_off_governor_smoothed_reference_engine_speed. AS: only readers are the two PTO lookups (addr-of@0x2a3cc / 0x2aa24, L27499 / L27733); used only when power_take_off_gain_adjustment_mode (0x4071a2) is non-zero (dump 0 = CALCULATED, so both tables idle on this calibration). 13B2/13B3 are one-record blocks, so the proof is by content (36000 x 0.125 = the record's max) and layout: 10AA's last record +1C = 0x4071aa, axis 0x4071ac, values 0x4071c2, 109D at 0x4071d8, with no gaps. | high |
| 0x4071c2 | protection_rpm_values_cal | power_take_off_gain_adjustment_values (drop `_cal`) | word[11] | PTO. Length word 20 + 10 Q14 multipliers 1638 1638 2294 3277 4424 5571 6554 7700 8684 9830 = 0.10 0.10 0.14 0.20 0.27 0.34 0.40 0.47 0.53 0.60 = e2m 13B3 PTO_Gain_Adjust_Table [PTGNTB] "Gain adjustment in function of RPM" (scale 6.1035e-5 = 1/16384, limits 0.032 / 1.95 = the calculated-branch clamps 0x20c / 0x7ccc, L27481-27491). Only readers: the same two lookups (addr-of@0x2a3d4 / 0x2aa2c). | high |

Item 3 (not a proposal row): 0x3fafb2 / 0x3fafb6 (now `power_take_off_speed_error_filter`) filter the PTO speed error. That is the smoothed reference minus engine speed (L27469), clamped to +-8000 counts (+-1000 rpm), times the gain multiplier >> 14 (L27503), through cm848_signedFirstOrderFilter (L27505). The coefficient is power_take_off_speed_error_filter_coefficient (0x407190 = 52429/65536 = 0.8, e2m PTO_Error_Filter_Constant); the output is power_take_off_governor_filtered_speed_error (0x40af2a). When the output leaves the clamp the accumulator is reset to clamp << 16 (L27512). It is an error filter, not an integrator (old name `governor_integrator_working`).

**Adjacent, not requested**

| address | current | proposed | type | evidence | conf |
|---|---|---|---|---|---|
| 0x3fafb0 | governor_integrator_prev_snapshot | power_take_off_governor_filtered_speed_error_previous | i16 (was word) | lha@0x2a578: derivative = (error - previous) x Kd x QD (L27578). sth@0x2ab8c copies power_take_off_governor_filtered_speed_error before each pass (L27773). WC `{'lha': 1, 'sth': 1} -> 2 byte`. HSG twin: high_speed_governor_filtered_error_previous (0x3fa894). | high |
| 0x3fafe0 / e2 / e4 | protection_eval_step_index / _frame_counter / _sub_counter | power_take_off_remote_switch_press_count / _pressed_pass_count / _released_pass_count | word | REMOTE_COUNT logic (L28083-28107): remote switch (bit 0x1000) pressed -> frame_counter++, sub_counter := 0, and a rising edge (0x2000 clear) does step_index++ up to power_take_off_remote_count_limit_cal; released -> sub_counter++, frame_counter := 0; both are compared with power_take_off_remote_switch_timeout. WC `{'lhz': 2, 'sth': 6}`, `{'lhz': 1, 'sth': 4}`, `{'sth': 5}` -> 2 byte. | med-high |
| 0x3fafe8-0x3faff2 (6 rows) | protection_rpm_reference_snapshot, governor_rpm_reference_snapshot_a, governor_rpm_ref_target_0..3_snapshot | one `power_take_off_remote_speed_by_press_count` | word[6] | Indexed read: addi@0x2b280, `add` index x 2, lhzx@0x2b288 (L28117). Init copies remote speed 1, 1, 2, 3, 4, 5 (L28330-28335). Dump 11200 11200 11200 12800 14400 16000 = speeds at index 1..5 (e2m PTO_Remote_Speed_2..5 "toggled twice ... five times"); [0] is never indexed. Ends at 0x3faff4 (next descriptor). | high |
| 0x3fdcfe / 00 / 04 / 06 / 08 / 50 / 54 | governor_rpm_reference_working, governor_rpm_reference_snapshot, governor_speed_ratio_working, governor_speed_error_gain_factor, protection_rpm_gain_factor_cal, protection_rpm_reference_a, protection_rpm_reference_b | power_take_off_remote_speed_1_cal, power_take_off_maximum_reference_engine_speed_cal, power_take_off_droop_slope_cal, power_take_off_gain_adjustment_offset_cal, power_take_off_gain_adjustment_slope_cal, power_take_off_resume_speed_cal, power_take_off_set_speed_cal | word | e2m block 0008 (EEPROM adjustable parameters): all seven resolve to ONE base, RAM 0x3fdcf4 (EEPROM 0x872): +A PTO_Remote_Speed, +C PTO_Maximum_Reference_Speed, +10 PTO_Droop_Slope, +12 PTO_Gain_Adjust_Offset, +14 PTO_Gain_Adjust_Slope, +5C PTO_Resume_Speed, +60 PTO_Set_Speed (0x3fdd50 / 0x3fdd54 at +5C / +60). Dump (rpm x 8; e2m range 600-2500 rpm): 11200, 12000, 0, 328 (x 6.1035e-5 = 0.02, e2m max 0.2), 0, 8800, 8800. Code: max = target clamp (L28272); offset / slope = the CALCULATED gain (L27478-27480); SET channel (0x100) picks b, channel 0x40 picks a. AS: no store anywhere, so `_cal`. | high |
| 0x3fd866 | j1939_pgn65264_source_address_bits | j1939_pgn65264_priority_cal | word | e2m 1254 +2C Jcomm_PTO_Info_Message_Default_Priority [JCPTPZ]. Base RAM 0x3fd83a is proved by crank_exit_speed_switch_cal (+38) and the neighbouring priority words matching name by name (+2A 65270, +2E 65249, +30 65248, +32 65271). Read as `(value & 7) << 2` (CAN id top byte, lhz@0x2beec); dump 6 and can_id 0x18FEF000. EEPROM mirror, so `_cal`. | high |
| 0x3faff4; 0x3fb003-08 | j1939_working_tx_message; j1939_msg_payload_init_word, j1939_protection_rpm_tx_word, j1939_protection_data_byte_a / _b | j1939_pgn65264_tx_message; j1939_pgn65264_payload_bytes_2_to_3, j1939_pgn65264_requested_engine_speed_tx_word (bytes 4-5), j1939_pgn65264_payload_byte_6 / _7 | j1939_tx_msg_t; word; word; byte | AS: used only by the two PGN 65264 functions. Bytes 4-5 carry the byte-swapped requested speed (code, L28442). Positional names only: no SPN identity is claimed for bytes 6-7. | high / med |
| 0x5129b0 | protection_control_state_check_2 | cm848_debounceCruiseSwitchRequest | int(void) | Debounces cruise_switch_button_code into a CRUISE_SWITCH_REQUEST (returns 5 while the code settles). Callers: the PTO state machine (L28051) and cm848_cruiseControlPeriodicUpdate (L71312). Not a protection function. | med-high |

**Contradictions with stage-5 text or names**
1. The comment on 0x40719e `power_take_off_reference_step_limit` says "the largest step". The code (L27832-27849) snaps to the requested speed when abs(diff) <= limit; otherwise it takes one EMA step but at least `limit` (a minimum step) and does not cap larger steps. e2m [PTRFLM] says "Min. step change of Reference speed". The name is defensible (it is the e2m name); the comment is wrong. Alternative: `power_take_off_reference_minimum_step`.
2. The plate of cm848_calculatePowerTakeOffGovernorSpeedError (L27457) says "power_take_off_requested_engine_speed minus engine speed". The code subtracts from the smoothed reference (L27468-27469) and multiplies by the gain multiplier (L27503). The requested speed is used only for the no-load fuel lookup (L27515-27519).
3. The plate of cm848_smoothPowerTakeOffReferenceEngineSpeed says it smooths "requested toward its target". It first runs the engagement ramp (target to requested), then smooths requested into 0x40af40. The 0x40af4c comment "the target the state machine sets" fits 0x3fafdc: the state machine never writes 0x40af4c.
4. 0x40af42 `power_take_off_governor_droop_compensated_speed_error` (e2m 10AB +1A) has no store anywhere: lis+disp scan, a dword pair-store check at 0x40af40, and a raw `-20670(` grep. The three `stb -20670(r12)` hits at 0x27888 / 0x2793c / 0x27bac use `lis 64`, so they are 0x3faf42. Its only reader is cm848_calculateFuelDemandWithConditions (lha@0x46444) as the integral error while PTO is active. It is a constant 0 in this build, so the label rests on position alone.
5. 0x40af44-48 (QD/QI/QP adjustments) are only ever written 0x80 (by the init); the limits at 0x4071a4-aa and PTO_Fueling_Clamp_Max (0x407196, dump 1766 = 120 mm3) have no readers. The PID's fuel maximum is `cruise_speed_blend_working` (0x3fdd7a, EEPROM 0x8f8 = 5888 = 400 mm3, also read by cruise code). Task 045 already lists 0x407196.

**Open questions**
- cm848_dispatchModeHandlers (0x42978) is a boot initializer (calls cm848_initLookupTableParams, cm848_initDroopModeStateVariables and the PTO init), so its name is misleading. No proposal row.
- The decompiler prints decimal `& 800` at L28172. The real mask is 0x320 (`andi. r12,r30,0x320` @0x2b7e8). `(flags & 0xe0) == 0x40` (L28173, rlwinm@0x2b7f4) also includes channel 2's previous bit. This looks like a source quirk and is harmless here.
- The PTO governor never engages on this truck: j1939_governor_feature_byte (0x3fd902) = 0, and the state is WAIT. PGN 65264 still reports because bit 0x10 is set. While inactive, bytes 4-5 carry the live engine speed (L28308).
- SPN identities of PGN 65264 bytes 4-7 are unverified: the local DB has no usable entry. The three unused caches' D/I/P roles are unprovable from code.

Scratch (reproducible): /tmp/pto_research/{head.cpp, snap.cpp, lines.py, addrscan.py, ptrscan2.py, ram.py, refs.py, widths.py, disasm_func.py}. Repo evidence files: firmware/CM848_S90140.06_analysis/output/{global_variables.csv, function_renames.csv}, firmware/CM848_S90140.06_analysis/known_pgns.txt, e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m, all under /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum.
````

## 5. Map CM848 EMO emission family (525k tokens, 98 tool uses, 31 min)

### Prompt (exact text)

````text
Read-only research on the CM848 (Cummins ISB, MPC555) firmware analysis. Do NOT edit any file, do NOT run `analyze.sh`, do NOT commit. Return a table of naming proposals with evidence.

## Where things are
- Worktree root: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum
- Decompiled output: firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp. The CSVs that name things are in the same folder: global_variables.csv (address,name,type,comment), function_renames.csv (address,name,plate comment).
- RAM dump: firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin. Address A is at file offset A - 0x3FA000, big-endian. Read a value at its declared width only. The dump was taken with the engine stopped (engine_state 1).
- A labelled Chrysler calibration: e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m. Record fields: name,unit,block(hex),offset(hex),...,scale...; the description follows `;`. e2m blocks line up with CM848 RAM / ROM by relative offset. A block's base is proved only when 2+ records with matching units agree with the code.
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines` prints a function body;
  - .../width_census.py `<all.dis> 0xADDR...` prints the load/store widths of an address (all.dis is in the same folder);
  - .../writers.py lists the assignments of a global (read its header for usage).

## Known (PR #52 stage 5b, verified)
The e2m EMO auxiliary emission control devices (AECDs) are named: `condensation_protection_*`, `engine_start_warmup_protection_*`, `extended_idle_protection_*`, `extreme_ambient_overheat_protection_*`.
- RAM words are at 0x40a5b6-0x40a5fe; ROM calibrations at 0x40654e-0x406598.
- Each `<aecd>_emission_level_cap` (EL = NOx emission level, 1/1024, 1024 = 1.0) is 0 unless its AECD is active.
- `fuel_demandMin_maxSelect_rateLimit` (0x50477c) takes the maximum of these caps and other inputs, then rate-limits it into `fuel_demand_min_rate_limited` / `fuel_demand_min_threshold`.
- The names on that output and on the other inputs are old guesses ("fuel demand floor") and may be wrong.
- The `combustion_status_flags` (0x40a5ee) row says it follows the pack DAT_0040a5ec "like e2m EMM_AECD_State / EMM_Protection_State".

## Targets
1. The other inputs of `fuel_demandMin_maxSelect_rateLimit`, and their producer functions: `fuel_blend_weight_threshold_active`, `DAT_003fba26`, `fuel_demand_sensor_validation_floor`, `fuel_timing_cylinder_check_demand_floor`, `fuel_demand_blend_weight`.
2. Its outputs and settings: `DAT_003fba28`, `fuel_demand_min_rate_limited`, `fuel_demand_min_threshold`, `fuel_demand_min_rate_limiter_prev`, `fuel_demand_min_rate_limit_increase` / `_decrease`, `DAT_003fd7e8` (EEPROM mirror), `DAT_0040654c`. Follow `fuel_demand_min_threshold` to its consumers and say what the value really limits. Candidates: a NOx emission level cap for the air handling / EGR / `cm848_selectChiAndAlpha`.
3. `DAT_0040a5ec` (written by `fuel_modeStatusBits_pack`), `combustion_status_flags` (written by `fuel_modeStatusFlags_update`), `DAT_00406568` / `DAT_0040656a`, `DAT_003fd7ea` (EEPROM 0x368). Also the three functions `fuel_modeStatusBits_pack` / `fuel_modeStatusFlags_update` / `fuel_demandMin_maxSelect_rateLimit`.
4. Find the e2m EMM_* / EMO_* records (grep the e2m for `EMM_` and `EMO_`). Line up their blocks with these addresses where the evidence allows.

## Naming rules
- Spell words out. No invented abbreviations; allowed: RPM, J1939, ECM, EGR, NOx, VGT, ADC, PWM.
- AECD is not universal: spell out "auxiliary emission control" or follow the existing `<condition>_protection_*` family.
- Never a bare "protection": say protection of what.
- `initialize`, not `init`.
- Decimal numbers in names.
- `_cal` only for the EEPROM mirror 0x3fd482-0x3feec1 (RAM = 0x3fd482 + EEPROM offset). ROM-copied 0x40xxxx calibrations get no `_cal`.
- Functions: `cm848_` + lowerCamelCase verb phrase.

## Evidence for every proposal
- the code lines (line numbers in the .cpp);
- the access width from width_census (quote it);
- the e2m record (block +offset name, unit, description) when one exists, with how the base was proved;
- the RAM dump value;
- confidence high / medium / low.

Skip a symbol rather than guess. A name that claims a meaning the code does not show is worse than the old name.

## Output
One markdown table (address | current | proposed | type | evidence | confidence), then a short list of contradictions and open questions. Keep it under ~120 lines.
````

### Report (exact text, the agent's handback message)

````text
## Naming proposals: emission manager (CM848 S90140.06). Read-only; no repo file touched; scratch scripts are in /tmp/cm848_research_scratch

**Basis.** The base proof is the ECU's own flash2 `{ID, address}` table at 0x53be38 (`cm848_lookupParameterIdAddress` 0x539768, 6-byte records [id16][addr32 BE], 1442 of 1886 slots filled). Its ids are the e2m column-3 block ids, so record address = table[block] + column 4. This replaces your "2+ records agree" rule as the base proof. Check: it reproduces every base already proved by offsets (1045->0x40a152, 1051->0x40a2ce, 105D->0x40afac, 1265->0x40af56, 196E->0x40654e, 196F->0x40a5b6, 177A->0x40a54e, 1711->0x40a518, 1A9B->0x3fddae). The lookup subtracts 0xc02b7e from EEPROM addresses, so 0x1000366 -> 0x3fd7e8. Offsets come from the 11.45 e2m and the truck runs 11.46, so each row keeps its own code, unit and dump agreement. Blocks 198E and 1A41 have one record each (table + code role only). Table-proved bases: RAM 198D 0x40a72e, 198E 0x40a5b4, 1997 0x40a596, 19B5 0x40a5ec, 199B 0x40a5f0, 19A9 0x40a600, 1A42 0x40a8a9; ROM cal 1990 0x406460, 198B 0x406548, 19B4 0x406568, 19A8 0x4065ba, 1A41 0x406fb2, 1991-1996 0x406470/98, 0x4064c0/e2, 0x406504, 0x406526, 18AD-18B6 0x4062d8...0x406450; EEPROM 198F 0x1000366; 106B 0x1000118.
Units: EL (emission level) is 1/1024; the chi/level tables are 1/2048. Line numbers are "as of the 13:40 build"; the .cpp and global_variables.csv were rebuilt under me, so addresses are the stable cite. A last re-grep (13:42) found every target name unchanged.

**What `fuel_demand_min_threshold` really limits.** It is a LOWER bound on the combustion chi, not an upper limit on air handling or EGR. `cm848_lookupProtectiveChi` (lhz 0x15e84, L13798) raises each protective chi's level to cap x 2 (1/1024 -> 1/2048), converts back to chi and keeps the larger. `cm848_determineBaseChi` calls it twice (air density, coolant temperature) and `cm848_selectChiAndAlpha` consumes the result. Dump tables: chi 1.00 / 2.00 / 3.00 / 4.00 = level 2048 / 4096 / 6144 / 8192, so a cap of c/1024 floors the chi at c/1024 (dump: cap 1024 -> base chi 100, level 2048). The AECDs are sources of the cap, and the maps and EGR are downstream. `cm848_selectChiAndAlpha` ignores the base chi when it requests EGR off or a fixed chi. The only other reader is the 150-sample average.

| address | current | proposed | type | evidence | conf |
|---|---|---|---|---|---|
| 0x40a5b4 | fuel_demand_min_threshold | emission_level_cap_command | word | e2m 198E+0 EMM_Cap_EL_Cmd "Emission level cap after AECDs", UNITLESS 1/1024. Last `sth` 0x50492c = rate-limited value, or 0x40654c while 0x3fd7e8 is non-zero. Readers: 0x15e84, 0x505470, 0x5054a0. census {'lhz':3,'sth':1}->2 byte. Dump 1024 | high |
| 0x3fba28 | DAT_003fba28 (no row) | emission_level_cap_before_rate_limit | word | Nine `sth 0(r5)` (r5=lis/addi 0x3fba28) at 0x50478c, 0x5047ac, 0x5047d0, 0x5047f4, 0x504818, 0x50483c, 0x504860, 0x504884, 0x5048ac; no loads; the last is the maximum of all nine inputs. census prints "none" (addi form). Dump 1024 | high (write-only) |
| 0x3fba2a | fuel_demand_min_rate_limited | emission_level_cap_rate_limited | word | `sth` 0x504904 only (census {'sth':1}); slew-limiter output before the override select (L61029-61031). Dump 1024 | high |
| 0x3fba2c | fuel_demand_min_rate_limiter_prev | emission_level_cap_rate_limited_previous | word | lhz 0x5048c0 (addi form, census only {'sth':1}); `sth` 0x504930 stores the limited value, not the override; boot-cleared at 0x504940. Dump 1024 | high |
| 0x406548 / 0x40654a | fuel_demand_min_rate_limit_decrease / _increase | emission_level_cap_rate_limit_decrease / _increase | word | e2m 198B+0 C_EMO_Cap_EL_Down_Rate, +2 Up_Rate (1/1024, max 64, "variable rate limiter"). lhz 0x5048e0 / 0x5048bc: out = prev+inc if prev+inc < target; prev-dec if target < prev-dec; else target. census {'lhz':1} each. Dump 15/15 = 0.0146 EL per pass | high |
| 0x40654c | DAT_0040654c | emission_level_cap_override_value | word | e2m 198B+4 C_EMO_Cap_EL_Override_Value "Cap EL override value" (U 1/1024, 0-16). lhz 0x50491c, used while 0x3fd7e8 is non-zero. census {'lhz':1}. Dump 1024 | high |
| 0x3fd7e8 (EEPROM 0x366) | DAT_003fd7e8 | emission_level_cap_user_override_enable_cal | word | e2m 198F+0 T_EMO_Cap_EL_User_Override "Enable trim to use Cap EL override value". Table 198F->0x1000366, inside the mirror so `_cal`. lhz 0x50490c, census {'lhz':1}. EEPROM 0x366 = 0 and RAM 0 | high |
| 0x3fd7ea (EEPROM 0x368) | DAT_003fd7ea | emission_manager_engine_protection_state_user_override_enable_cal | word | e2m 198F+2 T_EMO_State_User_Override "EMM general engine protection state user override enable". lhz 0x505310 (L61483): non-zero -> state := 0x406568. census {'lhz':1}; EEPROM and RAM 0 | high |
| 0x406568 | DAT_00406568 | emission_manager_engine_protection_state_override_value | word | e2m 19B4+0 C_EMO_State_Override_Value "EMO protection state override"; table 19B4->0x406568 (directly after 196E, 0x40654e+0x1A). lhz 0x505320. Dump 1024 | high |
| 0x40656a | DAT_0040656a | emission_manager_engine_protection_state_forced_on_mask | word | e2m 19B4+2 C_EMO_Override_Enable_Mask. lhz 0x5053bc (L61498): ORed into the computed state on the no-override path only, so it is no enable; the name says what the code does. Dump 1024 (bit 0x400, never tested) -> state 0x402 | medium |
| 0x40a5ec | DAT_0040a5ec | emission_manager_auxiliary_emission_control_state | word | e2m 19B5+0 EMM_AECD_State "EMM AECD state" (0..256 = 8 bits); table 19B5->0x40a5ec. `sth` 0x505304 only (census {'sth':1}), no reader. Bit 0 air handling, 1 extreme ambient overheat, 2 condensation, 3 white smoke and misfire, 4 extended idle, 5 engine start and warmup, 6 general engine protection, 7 DAT_003fba36 (L61462-61467). Dump 0 | high |
| 0x40a5ee | combustion_status_flags | emission_manager_engine_protection_state | word | e2m 19B5+2 EMM_Protection_State (0..1024 = 10 bits: the nine masks of `cm848_selectChiAndAlpha` lhz 0x160c0 + 0x400). 0x50530c: general_engine_protection_state OR white smoke bits 0x20/0x40 OR 0x01 engine start OR 0x80 extended idle or condensation OR 0x02 engine neither starting nor running, OR forced-on mask; air handling and extreme ambient are not in it. census {'lhz':1,'sth':2}. Dump 0x402. Not the same word as 0x40a8a9 | high |
| 0x40a5f0 / 0x40a5f2 | DAT_0040a5f0 / DAT_0040a5f2 | emission_level_cap_average / nitrogen_oxide_target_off_nominal_adjusted_average | word | e2m 199B+0 EMM_Cap_EL_Avg (1/1024) and +2 EMM_bsNOx_Avg (G/HP*HR 1/4096); table 199B->0x40a5f0. `sth` x3 each (0x505500..0x505540), no readers. 150-sample mean of 0x40a5b4 and of 0x40a532 (e2m CBO_bsNOx 1711+0x1A, same 1/4096). Dump 1024 (window full) / 0 | high |
| 0x40a72e | fuel_demand_blend_weight | emission_level_cap_reference | word | e2m 198D+0 EMR_Cap_EL_Ref "Scheduled emission level cap before AECD's and overrides"; table 198D->0x40a72e. `fuel_demandBlend_weight_calc` (0x507694): lookup(altitude x ambient temperature) x lookup(engine speed x net torque) >> 10 = C_EMR_Cap_EL_Table (18AF) x C_EMR_Cap_EL_Ratio_Table (18B2); dualAxis flags 3 / 2 match the e2m signed/unsigned columns. lhz 0x50488c, census {'lhz':1,'sth':1}. Dump 1024 (all grid cells 1024) | high |
| 0x40a730 | fuel_demand_blend_rpm_in_range_flag | not_to_exceed_zone_flag | word | e2m 198D+2 EMR_NTE_Flag "Emission tracker NTE flag". `fuel_demandBlend_rpmRange_check` (0x507748): lower(rpm) <= torque <= upper(rpm) from 18B3-18B6. Only reader lhz 0x5053ec. Dump 1 (bands 0, torque 0) | high |
| 0x40afc0 | fuel_demand_aux_blend_deviation | net_combustion_torque_copy | i16 | `= net_combustion_torque` (0x40a54e, e2m CBP_Net_Combustion_Torque FT*LB 0.5) at 0x50eb74 in `cm848_applyProtectionRpmCorrectionFilter`. Read as the torque axis by the reference calc and the NTE check (0x507700 lhz, 0x5077b4 lha). census {'lhz':1,'lha':1} | medium |
| 0x40a5a2 | fuel_blend_weight_threshold_active | air_handling_system_protection_emission_level_cap | word | e2m 1997+0xC EMO_Air_Handling_Cap_EL; table 1997->0x40a596. `fuel_blendMode_conditionCheck_update` (0x504528): level 3 cap 0x406462 if level 3 allowed, else level 2 cap 0x406460 if level 2 allowed, else 0. lhz 0x504788, census {'sth':1,'lhz':1}. Dump 0 | high |
| 0x40a596-0x40a5b2 (rest of 1997) | fuel_blendMode_condition_a_flag, _condition_b_flag, _condition_b_combined_flag, _no_condition_active_flag, _no_condition_combined_flag, fuel_blendMode_active_flag, governor_adjustment_flow_rate_threshold, _any_compare_flag, _fuel_qty_threshold, _boost_threshold, etc1_speed_below_threshold_flag, DAT_0040a5ae / b0 / b2 | air_handling_system_protection_ + level_1_condition_flag, level_2_condition_flag, level_2_allowed_flag, level_3_condition_flag, level_3_allowed_flag, active_flag, compressor_outlet_temperature_limit (i16), near_limit_flag, turbocharger_speed_limit, exhaust_temperature_limit, high_load_flag, near_compressor_outlet_temperature_limit_flag / near_turbocharger_speed_limit_flag / near_exhaust_temperature_limit_flag | word | 15 e2m records +0..+0x1C match the code in order. `governor_adjustment_compare` (0x5043b4): limits stored at +0xE/+0x12/+0x14 from the 1994/1996/1995 tables (lookup flags 3/1/1 = e2m S/U), near flags `sth` 0x5044b0 / 0x504480 / 0x5044d8, ORed into +0x10. `governor_adjustment_blend_check` (0x50422c): level conditions. `etc1_threshold_lookup` (0x5041bc): high load. Level conditions: altitude <= threshold and ambient <= altitude x slope/16 + offset. Also 0x3fba22 / 0x3fba24 (store-only 0x50429c / 0x504330) = level 1/2 ambient temperature limits (medium). Dump 1,0,0,0,0,0, 25600, 0, 14625 (x8 rpm), 3000 (x0.5 F), 0, 0,0,0. "etc1" in the old names is the transmission message and unrelated | high |
| 0x406460-0x40646e (1990) | DAT_00406460, fuel_blend_weight_threshold_cal (0x406462), fuel_blendMode_condition_a_slope / _b_slope, DAT_00406468 / 6a / 6c / 6e | air_handling_system_protection_ + level_2_emission_level_cap_when_active, level_3_emission_level_cap_when_active (drop `_cal`: ROM-copied), level_1 / level_2_temperature_limit_per_foot, level_1 / level_2_altitude_limit, level_1 / level_2_ambient_temperature_offset | word (lha ones i16) | Table 1990->0x406460; e2m C_EMO_Air_AECD_Level_2/3_Cap_EL, Altitude_Multiplier_1/2, Altitude_Thd_1/2, Amb_Tmptr_Offset_1/2. Single readers 0x504630, 0x504248, 0x5042e0, 0x5042a4, 0x50433c, 0x50426c, 0x504304 (lha). 0x406462 is read twice: 0x50461c and `cm848_applyOffNominalTimingAdjustment` 0x16e0c (chi x 1024 < value x 100: EL and chi are the same number). Dump 2048, 2048, -2, -2, 15000 ft, 15000 ft, 6464 (101 F), 19264 (301 F) | high |
| tables | fuel_demand_floor_altitude_ambient_air_factor_*, unnamed 0x40637c/8e/a0, fuel_demand_auxiliary_blend_deviation_{maximum,minimum}_by_rpm_*, unnamed 0x406470/98, governor_adjustment_* tables | emission_level_cap_altitude_ambient_temperature_{x_axis,y_axis,grid} (0x4062d8/ea/fc); emission_level_cap_speed_torque_ratio_{x_axis,y_axis,grid}; not_to_exceed_zone_{upper,lower}_torque_{axis,values}; air_handling_system_protection_high_load_torque_{axis,values}, _limit_altitude_axis, _compressor_outlet_temperature_limit_values (0x4064e2), _exhaust_temperature_limit_values (0x406504), _turbocharger_speed_limit_values (0x406526) | word[] | Ids 18AD-18B6 and 1991-1996 map to these exact addresses in order. Dump: altitude -300..12000 ft, temperature -50..125 F, speed 0..3500 rpm, torque -200..500 ft-lb, grids all 1024, NTE torque bands all 0 | high |
| 0x40a600 / 0x40a602 / 0x4065ba / 0x4065bc | injection_timing_temperature_component_check_flags / fuel_timing_cylinder_check_demand_floor / DAT_004065ba / DAT_004065bc | white_smoke_and_misfire_protection_state / _emission_level_cap / _coolant_temperature_limit (i16) / _emission_level_cap_when_active | word | Table 19A9->0x40a600 (+0 EMO_White_Smoke_AECD_State, +2 Cap_EL), 19A8->0x4065ba (+0 C_EMO_UHC_Coolant_Tmptr_Limit, unburned hydrocarbon limit, +2 C_EMO_White_Smoke_Cap_EL). Gate bit 0x400 of algorithm_enable_flags_20_cal = T_EMO_White_Smoke_AECD_Enable. `cm848_updateInjectionTimingTemperatureComponentCheckFlags` (0x5057ec): bits 0x20 / 0x40 while base-chi timing is below the intake / coolant timing component (coolant <= 0x4065ba, lha 0x50585c, dump 10880 = 170 F). Cap lhz 0x505890 (dump 1024) while the state is non-zero (`sth` 0x5058a0); reader of 0x40a602 lhz 0x504868. census {'lhz':3}, {'lhz':1,'sth':1}. Dump 0/0 | high |
| 0x40a8a9 / 0x40a8ab / 0x406fb2 | fuel_demand_sensor_validation_flags / fuel_demand_sensor_validation_floor / DAT_00406fb2 | general_engine_protection_state / general_engine_protection_emission_level_cap / general_engine_protection_emission_level_cap_when_active | word | Table 1A42->0x40a8a9 (+0 EMO_Gen_Protect_AECD_State, +2 Cap_EL; packed odd-address block) and 1A41->0x406fb2. census {'lhz':3,'sth':1} / {'lhz':1,'sth':1}. `cm848_updateSensorValidationFlags` (0x509a7c): bits 0x100 egr_system_failure_flag, 8 DAT_0040a43c, 4 DAT_0040a43e (0x10/0x200 sources never written) only while governor_feature_config_flags bit 0x40 = T_EMO_Gen_Protect_AECD_Enable (106B+0x2C; EEPROM 0x144 = 8, clear); cap lhz 0x509b44. Dump 0 / 0 / 1000. It is one input of emission_manager_engine_protection_state, not that word | high identity, medium wording |
| 0x50477c | fuel_demandMin_maxSelect_rateLimit | cm848_calculateEmissionLevelCapCommand | function | Maximum of nine inputs (air handling cap, condensation cap, 0x3fba26, engine start cap, extended idle cap, extreme ambient cap, general protection cap, white smoke cap, reference), slew limit, user override, then 0x40a5b4 (L60980-61046) | high |
| 0x505260 / 0x50530c | fuel_modeStatusBits_pack / fuel_modeStatusFlags_update | cm848_packAuxiliaryEmissionControlState / cm848_calculateEmissionManagerEngineProtectionState | function | rows 0x40a5ec / 0x40a5ee | high |
| 0x504528, 0x5041bc, 0x50422c, 0x5043b4 | fuel_blendMode_conditionCheck_update, etc1_threshold_lookup, governor_adjustment_blend_check, governor_adjustment_compare | cm848_updateAirHandlingSystemProtection, cm848_checkAirHandlingSystemProtectionHighLoad, cm848_checkAirHandlingSystemProtectionLevelConditions, cm848_checkAirHandlingSystemNearLimits | function | 1997 row | high |
| 0x5057ec / 0x509a7c | cm848_updateInjectionTimingTemperatureComponentCheckFlags / cm848_updateSensorValidationFlags | cm848_updateWhiteSmokeAndMisfireProtection / cm848_updateGeneralEngineProtection | function | rows above | high / medium |
| 0x507694 / 0x507748 / 0x5077fc | fuel_demandBlend_weight_calc / _rpmRange_check / main_loop_callPhaseGroupProcessors | cm848_calculateEmissionLevelCapReference / cm848_checkNotToExceedZone / cm848_updateEmissionLevelCapReference | function | The wrapper runs in main-loop phase 0x17 and calls the other two | high / high / medium |
| 0x5053e0 / 0x504948 / 0x504938 | fuel_demandTiming_rollingAverage_update / cm848_mainLoop_step / cm848_initialization_step_6 | cm848_updateNotToExceedAverages / cm848_runEmissionManager / cm848_initializeEmissionLevelCapRateLimiter | function | Average: 150 samples, reset when the zone flag is 0 (0x5053ec). Step: phase 0x15, all 12 callees are emission-manager inputs or outputs. Init clears 0x3fba2c (0x504940) | high / medium / high |

**Skipped:** DAT_003fba26 and DAT_003fba36. No writer found by the displacement/addi scan, an address-forming scan of 0x3fba10-0x3fba40, or a pointer search of ROM/flash2/EEPROM; no table entry; no e2m record. Only reads: 0x5047b4 and 0x5052f8. They fill slot 8 of the max-select and bit 7 of the AECD state; that pairing is inference, so at most a type-only row with a comment.

**Contradictions and open questions**
1. `algorithm_enable_flags_20_cal` is 0x0100 (EEPROM 0x142), which is the air handling bit. Air handling is the only AECD enabled on this truck, with level 2 and 3 caps of 2048 (2.0). `feature_enable_flags_cal` 0x8488 has no 0x200 (condensation) and `governor_feature_config_flags` is 8 (no 0x40). Stage-5b notes saying "0x0100" refer to the other bits.
2. `injection_timing_temperature_component_check_flags` (stage 5b "verified") sits at 19A9+0, the white smoke and misfire state. Keep its bit meanings (0x20 intake, 0x40 coolant timing component) in the comment.
3. The 0x406fb2 cap has e2m scale 0.001 (dump 1000 = 1.0), but its siblings in the same max-select are 1/1024. Mixed, it is 0.977 EL. Harmless here because the AECD is disabled.
4. `governor_adjustment_compare` tests `limit <= compressor_outlet_temperature << 1`. The e2m scale of Compressor_Outlet_Tmptr (175F+8, table 175F->0x40a60e, so 0x40a616) is 1/32 F, and the doubling fits that. The CSV says 1/64 (dump 1662 = 26 F at 1/64, 52 F at 1/32, against 25 F ambient). Needs a check.
5. Lead only: 0x40a19a is e2m Ambient_Air_Tmptr (1921+6; 1921->0x40a194, Altitude +0 = barometric_altitude_feet, Compressor_Inlet_Tmptr_Rise +0x10 = 0x40a1a4 boost_fuel_timing_target). 0x40a608 `ambient_air_temperature_selected` is e2m Compressor_Inlet_Tmptr (1A0C+0). `hpcr_fuelFinal_exponentialAverage` (0x502b6c) is the ambient conditions module.
6. The old `off_nominal_compensation_off_flag` comment ("blend_weight << 10 < fuel_blend_weight_threshold_cal x 100") is a chi test (chi < 2.0), not a blend weight.
7. The high-load input `j1939_tsc1_override_state.proprietary_offset_value` is a torque (percent difference x fuel_demand_period_cal 850 / 17354 / 2 = about 6.27 ft-lb per percent, 100 percent = 627 ft-lb) that also feeds a J1939 TX byte. Its name and struct are wrong; out of scope.
8. The NTE torque bands are all 0 in this calibration, so the flag is 1 only at net torque exactly 0 and the averages are effectively idle. "150 samples = 30 s" holds only if a 40-phase cycle is 0.2 s.
9. The e2m labels EMR_Cap_EL_Ref "G/HP*HR" but the other caps UNITLESS; same 1/1024 scale. Names avoid a physical unit.
10. Optional: `emission_manager_engine_protection_state` could become a bitfield (nine masked tests in `cm848_selectChiAndAlpha`); run piece_census first, as the writer builds the value in a local.

**Scratch scripts to archive** (all in /tmp/cm848_research_scratch/): access_list.py `<all.dis> <addr>...` (instruction-level accesses incl. lis/addi forms), find_table_refs.py `<all.dis> <lo> <hi>` (address-forming scan), find_pointer.py `<originals> <addr>...` (BE pointer search), block_table2.py `<flash2> 0x53be38 0x53ea6c [id...]` (parse the ID table; block_table.py is an earlier walker), join_e2m.py `<originals> <e2m> <global_variables.csv> <block ids>` (e2m records + table + current names).
````
