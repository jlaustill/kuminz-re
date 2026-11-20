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

# Stage 7 agents: rename wave 12 (2026-11-19, PR #52)

Six read-only `general-purpose` agents (model sonnet), started in parallel, one bin of 66-67 e2m records each.
Each wrote one JSONL result file in the scratch folder and nothing else.

The main session built the bins with `stage7/build_context.py`: every scalar e2m record that the parameter ID
table resolves, that has no name yet, that the .cpp uses, and whose dump value is in range. Then:
- `stage7/gate_W12.py` ran the gate. It applies apply_renames.py's rules and adds duplicates across bins,
  collisions, rows already present, and type against size. Only confirmed rows passed: 383 of 398;
- a random sample was spot-checked against the code and the width census;
- after the build, every differing function was classified (`classify_diffs.py`). The one bad render
  (a 4-byte version read bytewise, so `byte[4]`) was fixed.

## The shared brief (exact text)

````text
# Rename wave 12 (CM848): name the e2m records the ECU's parameter ID table resolves

Read-only research plus ONE output file. Do not edit any repository file, do not run `analyze.sh`, do not commit.
Write your results only to the result file named in your prompt.

## What is already proved
The CM848 carries its own e2m record -> address table. `cm848_lookupParameterIdAddress` searches 6-byte records
[e2m block id][address] in flash2. Each record in your bin sits at its `address`; that identity is not in question.
Two risks remain:
- **layout drift:** the labelled e2m is calibration 11.45 and the truck runs 11.46.06, so an offset inside a block may
  have moved;
- **naming quality.**

Each record in your bin has no name yet. The code uses it as `label_in_cpp` (a `DAT_<address>` label), and its dump
value is inside the record's min..max.

## Files
- Your bin: a JSON list (path in your prompt). Each item has:
  - the record: `record`, `unit`, `size_bytes`, `signed`, `scale`, `min`, `max`, `description`;
  - the code context: `code` (up to 4 lines that use the label, `function: line`) and `access_widths` (the load /
    store census; "none" means the census could not see the access);
  - `block_named_rows`: the same block's records that already have names, with a word-overlap score. Use them for
    naming consistency and as a drift check;
  - `region` (it decides `_cal`), `current_row` (`none` or `unnamed`) and `other_records_at_this_address`.
- Decompiled code: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
  and the CSVs next to it (global_variables.csv: address,name,type,comment).
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines`;
  - .../width_census.py `<all.dis> 0xADDR` (all.dis is in the same folder);
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/e2m_block_addresses.py
    `BLOCK` or `--address 0xADDR` (all records of a block with their addresses and current names).

## Per record
1. **Read the code lines.** Open the function when the line alone does not show the role. Check that the use fits
   the record: a flag compared with 0 / 1, a temperature compared with temperatures, a timer counted, a calibration
   only read, a table index used as one.
2. **Check the width.** The record's size (1 / 2 / 4 bytes) must match the access widths when the census shows them.
3. **Name it** in snake_case from the record name and description, following the rules below. Keep the block's
   conventions: a sibling named `air_handling_system_protection_*` means this one gets that prefix too.
4. **Give a verdict:**
   - `confirmed`: the use fits and the width matches;
   - `uncertain`: you cannot tell, or the use only weakly fits;
   - `rejected`: the use contradicts the record (drift), or the width disagrees. Say why.
   A wrong name is worse than no name.

## Naming rules
- Spell words out. No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox,
  id, adc, pwm, can, pid, tpu, qadc, vin.
- The `C_` (calibration) and `T_` (trim) prefixes only say "setting": drop them. `_cal` is decided by the region
  alone. In the EEPROM mirror (0x3fd482-0x3feec1) the name ends `_cal`; everywhere else it never does.
- Translate the Cummins abbreviations:
  - **Basic words:** Tmptr / Temp = temperature; Thd = threshold; Cmd = command; Amb = ambient; Ref = reference;
    Avg = average; Frac = fraction; Adj = adjustment; Cnt = count; Ctr = counter; Lmt / Lim = limit; Sw = switch;
    Stat = status; Val = value; Pos = position; Filt = filtered; Diag = diagnostic; Ovr = override; Vlv = valve;
    Pct = percent; Cyl = cylinder; Max / Min = maximum / minimum.
  - **Engine terms:** Inj = injection or injector (from context); SOI = start of injection (the repo writes
    `injection_timing`); Veh = vehicle; Baro = barometric; Alt = altitude; Trq = torque; Batt = battery;
    IMT = intake_manifold_temperature; CT = coolant_temperature; APS = accelerator_pedal; Accel = accelerator or
    acceleration (from context); Decel = deceleration.
  - **Systems:** COT = compressor_outlet_temperature; MCF / CMF = charge_mass_flow; VGT =
    variable_geometry_turbocharger; PTO = power_take_off; CC = cruise_control; EB = engine_brake; Jcomm = j1939;
    EL = emission_level.
  - **Governors:** LSG / HSG / ASG / VSG = low / high / all / variable speed governor.
  - **AECD** = auxiliary emission control device. Follow the repo's `<condition>_protection_*` family
    (`condensation_protection_active_flag`) rather than spelling the acronym.
- Module prefixes (EMO_, EMM_, CBR_, CBO_, FSS_, ...) are Cummins-internal. Use the words the rest of the block uses
  in its existing names, or drop the prefix when the remaining words are specific enough.
- Never a bare "protection": say protection of what.
- Use initialize, never init. Numbers in decimal.
- Flags end `_flag`; counters `_count` / `_counter`; timers `_timer`.
- The new name must not already exist (grep global_variables.csv and the .cpp). Two records in your bin must not get
  the same name.

## Types
- Use the record's size: 1 = `byte`, 2 = `word`, 4 = `dword`.
- Use `i16` only when the record is signed (S) and every access in the census is `lha`.
- If the census width disagrees with the record's size, reject the record and say so.

## Output: one JSON object per line, one line per record of your bin (rejected ones too)
- `current_row` `none`: `{"kind": "new_global", "verdict": ..., "address": "0x...", "new": "...", "type": "word",
  "evidence": "...", "comment": "..."}`
- `current_row` `unnamed`: `{"kind": "global", "verdict": ..., "address": "0x...", "old": "", "new": "...",
  "evidence": "...", "comment": "..."}`
- `evidence`: one line, for example `e2m 1997 +0E EMO_Air_Handling_COT_Limit (DEG_F, 1/64): compared with the
  compressor outlet temperature in cm848_checkAirHandlingSystemNearLimits; lhz; dump 13440`.
- `comment`: the CSV comment for the row. Lead with the e2m record and its description, then the role in the code.
  Include the dump value in engineering units when it helps (`(2048 = 2.0 here)`).

Finish with a short summary in your final message: counts per verdict, and the drift / width problems found.
````

## 6. Name e2m records bin 1 (680k tokens, 39 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin1.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W12 bin1 is done: 67 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl, one per bin record in bin order, all `kind` new_global with `type`. No repository file was edited. I checked the file for uniqueness against the CSVs and .cpp, banned words, `_cal`, type against size, and cited identifiers (see the last section).

**Verdicts:** 66 confirmed, 1 uncertain, 0 rejected.
- Uncertain is 0x40a672, named `exhaust_pressure_sensor_value_copy`. The e2m calls Exhaust_Pressure the calculated pressure, but the code stores the raw `sensor_channel109_value` (0 in the dump while `boost_pressure_current_raw` reads 1784). The two 191B rows keep `*_virtual_sensor_copy`.

**Drift (1):** 0x5c7ac is claimed by both 8A2B +24 IAH_Pulsewidth_Time_Duration and 8A37 +0 IAH_Default_IMT. The only code use is a signed temperature fallback, so I confirmed IAH_Default_IMT. 8A2B therefore ends at +22 in 11.46.06. Every other block aligned: siblings and neighbours resolve to the cells their own code uses.

**Width:** no disagreements.
- The census was empty at 0x5c1d0 and 0x5c7ac. I resolved both by disassembly: 0x5c1d0 is `lhz r9,0(r3)` at 0x5031a0, and 0x5c7ac is `lha` at 0x5183a4 (typed `i16`).
- `i16` is on six rows: 0x3fddb6, 0x409fd4, 0x409fd6, 0x409fd8, 0x409fda and 0x5c7ac.
- 0x40babe is signed but only stored (`sth`), so it is `word`.
- 0x409fce is `dword`; 0x408a94 and 0x408a95 are `byte`.
- Only 0x3fddb6 ends `_cal` (EEPROM 0x934).

**e2m wording that contradicts the code (the names follow the code):**
- 8C5A +2: the text says "Max speed", but the code needs vehicle speed above it.
- 8C5F +10: the description is another record's; the name, scale and pedal compare say minimum pedal position.
- 1772 +0: "Calculated" versus the raw sensor copy, which is the uncertain row.

**Naming choices:**
- `tsc1` is on four rows (0x5c3aa, 0x5c3ae, 0x5c3b0, 0x5c3b2). Swap it in one pass if you prefer it spelled out.
- Message acronyms are written as decimal PGNs (`j1939_pgn61442_*`, `j1939_pgn65247_*`, `j1939_pgn61443_*`).
- 10B6 mirrors the throttle-mode twins at 0x3ff6d0-d4: `..._reference_filter_coefficient`, `governor_fuel_demand_tracking_{limit,floor}_j1939`.

**Leads (legacy misnames, no extra JSON lines):**

Table-resolved:
- The `diag_dm1_*` words around 0x3fddb6 are the e2m data collector (0030-003B), not J1939 DM1.
- `sensor_channel109_value`, `_default_value` and `_fault_status` are the exhaust pressure sensor (1966 +A, 1966 +30, 1963 +18).
- `engine_to_vehicle_speed_ratio_*` is the e2m Tcase_NV transfer case low-range detection. In 8C60, `_high_flag` is Tcase_Low_Range_Flag and `_invalid_flag` is Tcase_Launch_Flag.
- `throttle_trim_predictor_output_min` is 1A2E +4 C_INM_EGRT_Min (EGR orifice temperature).
- `j1939_address_cached` (0x40a030) is 1042 +4 ASIC_Feedback_Delay_Time (100 us).
- `boost_pressure_synthetic_ema` and `boost_correction_mode_flags` are 1772 +A and +8, the exhaust pressure estimate and its state.
- ROM cells with a wrong `_cal`: `etc1_torque_mode_timeout_cal` (10E7 +A), `fuel_demand_norm_zero_cal` (10E7 +16), `cruise_speed_default_cal` (13B4 +4).
- 155A is past the end of the dumped table, so its link to the 0x5c1d6 gain sets is by offset only.

Inferred from use:
- `cruise_speed_factor_a`, `cruise_speed_factor_b` and `cruise_speed_offset*` are the high speed governor lead/lag compensator state.
- The `etc1_*` timer fields reload from the 10E7 cells:

  | Field | Reloaded from |
  |---|---|
  | `etc1_torque_mode_timer` | overspeed enable timeout |
  | `etc1_torque_active_timer` | overspeed time limit |
  | `etc1_torque_limit_timer` | progressive shift disable timeout |
  | `etc1_speed_override_timer` | driveline disengaged timeout |
  | `etc1_mode_timeout` | out of gear timeout |
  | `etc1_override_timeout` | torque converter lockup timeout |
  | `etc1_speed_cmd_timeout` | output shaft speed timeout |
  | `etc1_message_timeout` | message timeout |

- `j1939_fault_load_protection_*`, `j1939_fault_state*` and `j1939_load_protection_fault_reported_flag` are the P1762 governor pressure offset monitor state.
- `cm848_j1939FormatDm1Message` is the TSC1 lost management (e2m Jcomm_TSC_Lost_Fault).
- `faultTimerHandler` builds the 28-byte `j1939_pgn65251_tx_message` payload.
- `phase_group_a_validateEngineSync` is the exhaust pressure source selection.
- `sensor_channel108_filter` is the EGR orifice temperature lead predictor.

**Checks:** each of my names is unique and absent as a token from the CSVs, the .cpp and the three generated headers. The names also pass the gate's banned-word and hex-looking-part checks, and the `_cal` rule. An emulation of `comment_name_sweep.py` flags nothing in the new comments.

**Scratch (in /tmp, nothing in the repo):**
- /tmp/w12bin1_make.py is the generator; it holds all text and rewrites the JSONL.
- /tmp/w12bin1_check.py, /tmp/w12bin1_idcheck.py and /tmp/w12bin1_sweepcheck.py are the checks.
- /tmp/w12bin1_extract.py prints the full e2m descriptions.
- /tmp/w12bin1_xref.json holds the `xref_addr.py` output for all 67 addresses.
````

## 7. Name e2m records bin 2 (546k tokens, 36 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin2.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W12 bin2 is done: 67 lines written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl. Counts: 63 confirmed, 1 uncertain, 3 rejected.

I ran my own self-check, and it passed. That covers the line count, the address order against the bin, and the gate rules from `apply_renames.py` (banned words, hex-looking parts, `_cal` only inside the mirror). It also covers uniqueness against `global_variables.csv`, `function_renames.csv`, `arrays.csv` and the .cpp, and every comment staying within the 400-character clip. No repo file was touched.

**Drift (the 3 rejected rows)**
- 0x5a48e, 0x5a490 and 0x5a492 are 10E3 +22 / +24 / +26 in the labelled e2m. In the truck they are block 1228 +02 / +04 / +06.
- The code at those addresses is the DM4 freeze-frame vehicle-speed switch (`== 1`) and the DM5 OBD-compliance and continuous-monitors bytes. Block 1228 starts at 0x5a48c, so block 10E3 ends before +20 in the truck.
- These rows have an empty `new`, because bin 6 owns the three addresses.
- No other drift turned up. Anchors from existing named rows hold in 1189, 1048, 106D, 12BA, 1791, 179C, 1977, 1A53, 117F, 1143 and 175C.

**Shape (the 1 uncertain row, plus a collision)**
- 0x5a486 `j1939_command_security_flags` is typed `dword`, but the only access is bytewise (`lbzx` over 4 bytes). The role fits, so I marked it uncertain for the shape only. `byte[4]` against `dword` is your call.
- 0x5983a and 0x5983e are entry 0 of a 4-mode × 2-dword table. `cm848_faultTimeoutHandler` indexes it by `(aging_flags & 3) * 8`, and the mode-0 pair is never read.
- Bin 5 will also propose a row for 0x5983a (000F `Fault_Data`), so two `new_global` rows will hit that address.

**Width and sign**
- No census width contradicts a record.
- Several records are typed `word` despite their sign, because the rule needs every access to be `lha` for `i16`.
  - 0x408e6c is signed but loaded with `lhz`.
  - 0x408e72, 0x408e82 and 0x408e84 are unsigned but loaded with `lha`.
  - 0x40afb6, 0x40afb8, 0x40afba and 0x40afbc are signed but only ever stored. They are never read in the binary, and their torque grid is all zero, so the dump proves nothing there.
- Where the census said "none", I took the width from my own assembly reads. That covers the filter coefficients through the two second-order filter helpers, and 0x408e5c through `lha 0(r31)` at 0x52547c. It also covers 0x3fdfc0 (`sth 2(r27)`, r27 = 0x3fdfbe), 0x406752 and 0x5983a / 0x5983e.
- `i16` is used only on 0x408e54, 0x408e56, 0x408e62, 0x408e76, 0x408e80, 0x3ff078, 0x3ff07c and 0x5b336.
- `_cal` is on exactly 0x3fdfc0, 0x3fdd7e, 0x3fdd82 and 0x3fdd84.

**Neighbours noticed:** the named 10FC rows (`j1939_pgn65249_cal_*`, `j1939_protocol_mode_*`, `j1939_dtc_spn_cal_*`) are the PGN 65249 retarder-configuration points in e2m order. 0x5a494 `j1939_feature_config_word` is 1228 +08, the DM5 non-continuous monitors word.
````

## 8. Name e2m records bin 3 (594k tokens, 38 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin3.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin3.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W12 bin3 is finished: 66 result lines, in bin order, written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin3.jsonl. All 66 records are `new_global`. 64 names are unique and none collides with global_variables.csv or the .cpp. No name is a word-order permutation of an existing name.

**Verdicts: 64 confirmed, 0 uncertain, 2 rejected.**

**Rejected (neither is a bad address or a width problem):**
- **0x5a4aa, e2m 1253 +2 Fault_Data_J1939_111.**
  - The record is right at that address: slot 0 is fault 111, the value 0x00600275 carries SPN 629, and the DM1 builder reads it with `lwzx` (4 bytes).
  - What fails is the rest of block 1253. The e2m 11.45 slot order does not match this ROM (ROM: 111, 122, 123, 124, 131, 131, 132 ...; e2m: 111, 912, 184, 185, 115 ...). Only 1 of 90 e2m SPNs matches at the e2m offsets.
  - Also, 0x5a4aa is the base of a stride-4 table of 170 entries (header word 0x2a8 at 0x5a4a8), indexed by fault slot in three J1939 functions.
  - A scalar row would sit on that array base. I suggest one `dword[170]` row `j1939_dtc_definition_table` instead, and the scalar left unapplied.
- **0x40ba4c, e2m 1902 +2E IMTR_Ratio.**
  - The code uses the word as the thermostat monitor's current fuel total (`cm848_runThermostatMonitor`).
  - Its e2m neighbours AATR_Ratio and BTR_Ratio at 0x40ba48 / 0x40ba4a are already named thermostat fuel words.
  - So the +2A..+2E layout drifted from 11.45. A code-based candidate name is in the evidence: `thermostat_monitor_current_fuel_total`.

**Drift and widths:**
- **Drift:** block 1253 slot order and block 1902 +2A..+2E, as above.
- **Smaller e2m label problems, none affecting identity:**
  - Top_Gear_Ratio says "above which"; the code tests the ratio below it.
  - The 0x406768 boost coefficient is labelled per inHg, but the `/16384` divisor works in psi. The injection timing and engine speed divisors do reproduce the e2m scales.
  - The e2m descriptions of C_BT_Min_Vehicle_Speed and C_BT_VSS_Min_Timer are copy-pasted.
- **Widths:** no disagreements. Census-blind records were resolved by disassembly:
  - 0x597b2 (`lhz` through the record pointer);
  - 0x597bc, 0x597be and 0x597c0 (`lha` through the channel pointers; the 0x597c0 read is at 0x507fd8);
  - 0x40ba1e, 0x40ba22 and 0x40ba26 (4-byte `stw` through a pointer);
  - 0x5a4aa (4-byte `lwzx`, rejected).
- **Types:** by record size, except 0x597c0 `Fuel_Temperature_RPM_Lower_Limit`, typed `i16`. It is the only signed record, and its only reader is `lha`.
- **Block 1977/197A/197B check:** run with the tool; 1977 +4 = 0x3ff078 and +8 = 0x3ff07c. 197A / 197B resolve to 0x3ff0c4 / 0x3ff0e6, the pressure-drop lookup's axis and values used by the 197E code.

**Caveats for you:**
- **`_cal` on 0x3feb86 / 0x3feb88 (block 1100).** I applied `_cal` by the brief's region rule. These are logged J1939 control source slots, not tunables. The parameter ID table lists block 1100 as a plain RAM address, so the "EEPROM 0x1704 / 0x1706" offsets in the comments are my arithmetic, and the comments say so.
- **Prefix choices.**
  - Block 10CE uses the code's `pedal_fault_mode_` family, not the e2m's "limp home".
  - Block 8041 uses `injector_driver_`.
  - Block 112E uses `fuel_temperature_derate_` and spells the three temperatures as `_temperature`.
  - Block 17A2 uses `exhaust_temperature_estimate_`, not the neighbours' misleading `boost_target_*`.
  - I renamed 0x5c49e, 0x5c4a0, 0x5c4a2 and 0x5c4a4 so they are not a word permutation of the existing `engine_speed_limit_pedal_fault_mode`.

**Sibling rows outside my bin that look wrong (leads for you):**
- 0x40a899 `injection_timing_demand_output` is e2m 105A +2 Tau_0_Throttle_100_Fueling, the low-horsepower-curve full-throttle fueling. `cm848_validateFuelDemandRelativeToTiming` is really the engine load relative to that curve.
- 0x3fd912 / 0x3fd916 `cruise_ramp_zone_b/d_fuel_demand_threshold` are the cruise and road speed governor top droop widths in 1/256 mph. They are subtracted from `cruise_fuel_demand_ramp_ceiling` = 21760 = 85 mph.
- 0x40676c `boost_target_load_gain`, 0x40a67e `boost_target_fuel_normalized_ratio` and 0x40a682 `boost_target_load_rpm_output` belong to the exhaust temperature estimate, not a boost target.
- 0x3feb82 / 0x3feb84 / 0x3feb8a `*_calib_*` are J1939 engine and retarder control status and the history index.
- The `protection_coldStart_channelA/B_*` and `protection_load_*_threshold` rows in block 8C59 are the 48RE governor pressure zero and mid range monitors and their transmission temperature window.
- 0x40b9c6 `cam_sync_validation_state` is the fuel pressure key-on rationality state (`hpcr_checkRailPressureSensorBeforeStart`). The `cam_sync_validation_*` siblings in block 1B2C are its rationality parameters.
- 0x597b2..0x597d5 is a single 36-byte fault derate channel record, a candidate for a struct.
- 0x5c48e (the e2m limp home engine speed filter coefficient) already has an unnamed row; `pedal_fault_mode_target_speed_filter_coefficient` would fit.

**Files:** I modified only the result file. I also created two scratch scripts outside the repo, and they are still there:
- `/tmp/w12_bin3_build.py` is the generator that writes the result file.
- `/tmp/w12_bin3_check.py` is the validator.

Archive or delete them as you prefer.
````

## 9. Name e2m records bin 4 (556k tokens, 37 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin4.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin4.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
Wave 12 bin4 is done. The result file is /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin4.jsonl. It has 66 lines in bin order, all kind `new_global`. I validated it by script: every bin address is present once, no name is duplicated, and no name exists in global_variables.csv, the .cpp, or the other agents' result files. `_cal` appears if and only if the address is in the EEPROM mirror, and every type matches its record size.

**Counts:** 65 confirmed, 0 uncertain, 1 rejected (0x004086ca `AC_Driver_ON_Max_Time`, with `new` empty like bin2's rejected rows).

**Width:** no width rejects. The census was blind for three groups, so the widths come from the instructions cited in each evidence line.
- 0x5c4a6: `lha 0/2/4/6(r3)` at 0x28a80-0x28aa4. The address is taken as a pointer.
- 0x40a74e and 0x40a750: `sth r4,26(r5)` and `sth r4,28(r5)` at 0x508e34 and 0x508e38. These are fields +0x1a and +0x1c of a 62-byte per-input record at 0x40a734.
- The 12 rows of block 1930: `stb`/`lbz` and `sth`/`lhz` through the pointer arguments of `cm848_checkSensorStuckOverDistance`.
- 0x3fddae and 0x3fddb2 are `lwz`/`stw` (4 bytes).
- Types: `i16` only for 0x5c334, 0x4086a4 and 0x4086a6. The signed rows 0x40b6c6, 0x40b6ce, 0x40b6d0, 0x40b996 and 0x5c4a6 stay `word`, because their census is store-only or empty. 0x5c2b2 is unsigned but read with `lha`, so it is also `word`.

**Drift:**
- **Block 8A14:** it fits the code through +2A (0x4086c4) and not from +2C.
  - 0x4086ca is rejected. Its only reader loads it into the TSC1 activity counter, and its dump is 1 (0.1 s), which cannot be a maximum A/C run time.
  - The existing rows 0x4086c6 (`protection_iat_scale_factor_cal`, a percent factor of barometric pressure) and 0x4086c8 (`j1939_tsc1_active_duration_reload`) must not get e2m 8A14 comments.
- **Block 1930:** it fits through +10 and not from +12. The 12 in-bin rows (+00 to +0E) are proven by the callee, which uses each address in the matching argument slot.
  - From +12, the e2m's AATR_Numerator is a word, but the code puts the dword `water_in_fuel_distance` at 0x3feeb8, and BTR_Numerator/Denominator sit on unrelated names.
  - 0x3feec0 holds 0xa1a1, a marker rather than a counter.
- **No drift in the other blocks:**
  - Block 10DF's dump matches the truck's rating: 555 ft-lb, 1600 rpm, 2900 rpm rated.
  - Block 1152 matches its 62-byte layout.
  - Blocks 1034, 10EB, 118A, 12BD, 12FE, 164A, 1918, 1965, 1A9B, 806C and 81C9 also fit the code.

**Naming departures your consistency check will flag:**
- Block 8A14 uses `air_conditioning_*`, not the sibling `protection_event26_*`. That function is the A/C clutch request logic (logical output 38).
- Block 164A uses `end_of_line_test_*`, not the sibling `radiator_fan_speed_*`. The two intake air heater rows (IAH, 0x642ea and 0x642ec) are prefixed `end_of_line_test_` too, because their only readers are the end-of-line sequence.
- The 1930 rows end `_cal` as the brief requires. The existing rows at 0x3feeb6 and 0x3feeb8 sit in the same mirror without it.
- Rows 0x405d4a, 0x405d4c and 0x405d50 reuse the stem `injection_quantity_temperature_headroom_cap_`.
- Block 1152 follows the sibling prefix `fuel_temperature_derate_`.

**Leads:**
- `governor_speed_setpoint_raw`, `governor_d_gain_from_table`, `governor_p_gain_from_table` and `governor_j1939_gain_extra_working` actually hold the P, I, D and J gains of block 10EB. I checked the consumer code in `cm848_runLowSpeedGovernor`. The four words at 0x5c4a6 are a struct candidate.
- `faultTimerHandler` builds the 28-byte J1939 PGN 65251 payload, which is what the five speed points of block 12BD feed. The `throttle_position_*` words are e2m block 10E2 Jcomm percent peak torque.
- The note on `injection_quantity_temperature_headroom_cap` ("neither word has an e2m counterpart") is now outdated. 0x405d4e `C_TFC_Texhaust_Lim` is unnamed because its dump is out of range (6000 = 3000 F against a 0..1500 e2m range), and the cap is a constant 200 mm3 here (both limits are 2944).
- 0x642ee `EOL_EVR_Test_Time` (dump 150 = 15.0 s, over its e2m maximum of 10 s) is the alternator test end time, next to my 0x642f0 and 0x642f2 rows.
- In the compiled code, any battery voltage fall passes the 0x642f2 threshold, and no fall fails. The row comment says so.
````

## 10. Name e2m records bin 5 (473k tokens, 30 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin5.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin5.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
Wave 12 bin 5: 66 rows written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin5.jsonl (read-only research; no repo file touched, no build, no commit). The file passes my checks: it has 66 lines, its address set equals the bin, and every row is `new_global` with a `type`. All names are unique, none ends `_cal`, and none exists in the repo's CSVs, headers or .cpp. They also do not collide with bin3's finished result.

**Verdicts:** 61 confirmed, 5 uncertain, 0 rejected.
- **Types:** 56 word, 5 byte, 3 dword, 2 i16. The i16 rows are 0x5a9bc and 0x40675c (signed, `lha` only). 0x40add4 is signed but its only census access is `sth`, so it stays `word`.
- **Widths:** no census width disagrees with a record size. Five records are census-blind (array or address-taken access): 0x5983a, 0x408e02, 0x408e18, 0x408e26 and 0x6457a. Their width comes from the decompile (`uint *`, `word *`, `ushort`) and matches.
- **Offset drift:** none inside my 16 blocks.
  - The code proves the layouts: stride-8 fault table, zone gain sets in P/I/D/I-acc order, sum 10+2+1+1=14 for the J1939 receive groups, and 1052 bracketed by its clamp bounds.
  - The humidity block 1982 matches the dump to the digit: (71<<10)/1647 = 44.
  - The exhaust-pressure terms in 198C each match their e2m label.
  - The fuel-level block 8A22 ties to the 0.8 s task period.
  - The PCI slot 125 equals P0720's slot (ROM 0x5985a[320] = 125).

**Uncertain: tau polarity (0x5c35a, 0x5c35c, 0x5c35e, 0x5c360, 0x5c362).**
- The roles fit: these are the derated point-2 speed and fueling of the PGN 65251 engine configuration message, plus the point-5 intersection speed.
- The tau index is not proved.
  - Disassembly 0x20dac-0x20ea0 reads the Tau_0-labelled pair when `thermal_fuel_limit_factor` equals 0x4000.
  - That variable is e2m 1053 +2 Fuel_Interp_Factor (a startup/run alpha blend written by `hpcr_calculateFuelTrimOutput`).
  - With it forced to 0, the code computes the e2m "ESP Tau 0" fueling, so the labels read inverted.
  - The cal holds identical pairs (17600 / 736), so the dump cannot decide.
- 0x5c364 (the Tau_1 intersection) has no reader.
- I kept `tau_0` / `tau_1` in the names. If you apply them, the digits may need swapping.

**Overlap with bin2:** 0x5983a (`Fault_Data`, block 000F) is the same address as block 0023 `Fault_Countdown_Elapsed_Time_Mode_0`. Both rows must get one name; mine is `fault_countdown_elapsed_time_mode_0` (dword).
- In code the label is only the base of the fault aging table: 4 × {elapsed, rate} dwords at stride 8, indexed by `aging_flags & 3` with mode 0 excluded.
- The table is a struct-array candidate; all eight words are 0 in the ROM.

**Leads outside my scope:**
- **Collector:** the `diag_dm1_buffer_*` rows at 0x40c278 / 0x40c27c / 0x40c280 / 0x40c284 are e2m 0033-0036 Collector_Start / Center / End_Address / Status, so the data collector, not DM1.
  - My name `data_collector_table_address` follows the e2m, not those neighbours.
  - The whole 0x40c270-0x40c290 block reads 0 in the RAM dump, even pointers the init sets, so no dump value is quoted.
- **Engine configuration cluster:** `faultTimerHandler` (0x1b3a0, sent by `cm848_sendFaultTimerMessage`) builds the PGN 65251 engine configuration message. The `cm848_updateProtection*` functions and the `protection_*` variables in block 1104 (e.g. `protection_threshold_scale_cal` at 0x5c34e) are its point calculation. The existing `_cal` names there are wrong twice: they are legacy misnomers, and they sit in flash.
- **Cruise names:** `cruise_speed_offset_*` are fueling top-droop offsets in mm3, not speeds. My rows use `cruise_top_droop_offset_*`.
- **Other legacy names:** `boost_synthetic_ema_*` and `boost_pressure_synthetic_ema` are the exhaust-pressure estimate. `thermal_fuel_limit_factor` is the e2m Fuel_Interp_Factor.
- **Block 11F9:** +8 (OBD_Fuel_Type, 0x5a9c4) lands on a lookup-table length word (12), probably drift or a dropped record there. My +0 / +4 / +6 are code-proved.
- **Struct candidates:** the three 4-word cruise gain sets at 0x408e02 / 0x408e18 / 0x408e26, and the fault aging table.
- **Behaviour note, tachometer cutoff:** 0x645c2 floors a non-zero speed to 300 rpm rather than dropping it to zero as the e2m text says. I confirmed it because "cutoff" holds either way, and the comment says so.

**Name choices to be aware of:**
- **Spelled out, not abbreviated:** 0x40add4 is `environmental_protection_agency_indicated_friction_torque_percent_times_256` because EPA is not on the allowed abbreviation list.
- **Sibling convention:** the retarder stages follow the existing `engine_retarder_stage_1_weight` as `engine_retarder_stage_2` through `stage_6_weight`.
- **Fuel-level family:** the fuel-level rows use the existing `fuel_level_sensor_high_voltage_*` family rather than the e2m's "out of range" wording.
````

## 11. Name e2m records bin 6 (583k tokens, 35 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 12 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/brief_W12.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin6.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin6.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W12 bin6 is done. All 66 records are in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin6.jsonl. I made no repo edits and ran no builds. The untracked firmware/scripts/test_e2m_name_audit.py is not mine.

**Checks run on the file**
- 66 lines of valid JSON, in bin order, with the schema keys.
- Addresses match the bin.
- 64 names, all unique, none already in global_variables.csv or the .cpp.
- Types follow the size and signedness rules.

**Verdicts:** 64 confirmed, 0 uncertain, 2 rejected. The two rejected rows have `new` and `type` empty.

**Drift and width problems**
- **0x5c7ac, 8A2B +24 IAH_Pulsewidth_Time_Duration (rejected, drift):** the address belongs to block 8A37 +00 IAH_Default_IMT (signed DEG_F). The only code, cm848_captureIntakeAirHeaterStartTemperature, loads it with `lha` as the default start temperature. Block 8A2B ends at +22 in this ROM. That 8A37 record needs its own name, for example `intake_air_heater_default_intake_manifold_temperature` with type `i16`.
- **0x3ff06c, 10A0 +0E C_TSE_Charge_Press_Derate (rejected, width):** the record is a 4-byte bitmap (dump 0x010f000f), but the only access is one `lbz` of byte 0. Bytes +1 and +3 are separate byte rows (0x3ff06d, 0x3ff06f), so a dword row would swallow them.
- **0x5a48e / 0x5a490 / 0x5a492 (1228, kept):** the 10E3 tail records +22 / +24 / +26 resolve to the same addresses. Block 1228 starts at 0x5a48c, which is 10E3 + 0x20, so the 10E3 tail is not in this ROM. The DM4 and DM5 code fits 1228.
- **12F7 +14 J1939_Mux_Wet_Tank_Pressure (0x40aaba, not in my bin):** in this ROM it receives EEC2 accelerator pedal position 2, so that one e2m label does not match. The +11 to +13 and +15 records do match.

**Deliberate deviations (each is stated in the row's evidence)**
- **0x3fe9a8 fault_detected_bits_416_to_431 has no `_cal`.** The region rule says it should end `_cal`. I followed its 20+ siblings and the 0x3fe9c4 note "no _cal: runtime state". The e2m defines its bits 0x1 and 0x2 as the cylinder 7 and 8 misfire errors, and the misfire monitor tests exactly those masks.
- **0x408adc has a direction-neutral name (`converter_clutch_lockup_fourth_gear_ratio_limit`).** The e2m calls it "Min", but the code passes when the ratio is at or below it, so it is a ceiling in use. The neighbours +0C, +0E, +12 and +13 all fit, so this is a label issue, not drift. Verdict is confirmed.
- **The four PGN 65264 PTO rows use e2m-derived names** (`j1939_received_power_take_off_*`, `j1939_received_remote_power_take_off_switch`). They deviate from the sibling SPN-name convention because the local database has no usable PGN 65264 layout, so the SPN names cannot be verified. The A/C row uses SPN 985 (A/C High Pressure Fan Switch), from the SHUTDN positions the database files under number 65251.
- **0x3ff05e is `altitude_derate_engine_speed_threshold`.** I left out "air handling fault" because the early return also skips the normal cool and hot grids.
- **0xb74a is `application_overlay_core_software_version`.** It avoids a mix-up with the EEPROM calibration V11.46.06; the dump is 0x11201401.
- **The TCC rows use the repo's `converter_clutch_` prefix** rather than `torque_converter_clutch_`.

**Leads, outside my bin**
- The `cold_start_*` and `intake_temp_ema` names in the 0xe0f4-0xe518 functions are alpha names. `fuel_demand_ramp_factor` is alpha, and 0x5be66 `cold_start_intake_temperature_filter_coefficient` is e2m Alpha_Fuel_Rate_Filter_Constant.
- The `diag_dm1_*` names around cm848_phase_groupB_calculation are the e2m data collector. Collector_Schedule, Collector_Trigger and Collector_Stop_Mode sit at 0x3fddb6, 0x3fddb8 and 0x3fddba.
- `throttle_trim_predictor_output` (0x40a692) and `throttle_trim_predictor_gain` (0x40a696) are INM_EGRT_After_Lead and the lead time constant of EGR orifice temperature.
- `j1939_feature_config_word` (0x5a494) is Supported_Non_Continuous_Monitors, and `cm848_governorDroopCalculation` is a number-to-decimal-text helper.
- The `protection_*` rows at 0x408ad2-0x408ade are the P1740 converter clutch rationality values (e2m TCC_Rationality_* and TCC_Steady_Throttle_Count_Limit).
````

# Stage 8 agents: rename wave 13, the misname review (2026-11-19, PR #52)

Six read-only `general-purpose` agents (model sonnet), started in parallel, one bin of 63-64 e2m records each.
Each wrote one JSONL result file in the scratch folder and nothing else.

The main session built the bins with `stage8/build_context_W13.py`. A record went in when it is a named
scalar / enum / array row whose name shares no word with its table-resolved e2m record, with 3+ code
references and a dump value in range: 381 records, whole blocks per bin. Then:
- `stage8/apply_W13.py` held back 3 rows: two enum-typed rows whose enum members still follow the old reading,
  and a dword to split first. It checked the old names against CM550 and the cross-firmware maps (none
  shared) and ran the repo's apply_renames.py gate on the 218 renames (no PROBLEM line);
- a random sample of 9 renames was spot-checked against the code;
- the main session reconciled one cross-bin name: 0x40b798 became `backup_pulse_period_countdown`, to pair
  with bin 5's `backup_pulse_period_timeout`, because the code reloads it from that timeout;
- old comments stay as earlier notes, except 11 that an agent showed to be wrong. The proved facts of one of
  them (0x3fed94) were restored by hand. 54 rows got the rename note moved to the repo order;
- the 80B9 debounce counters and limits (8 rows) took their bits bytes' new meanings (code pairing checked);
- after the build, the label-only proof was EQUIVALENT, and the build warnings were identical to stage 4.

## The shared brief (exact text)

````text
# Rename wave 13 (CM848): review names that disagree with their e2m record

Read-only research plus ONE output file. Do not edit any repository file, do not run `analyze.sh`, do not commit.
Write your results only to the result file named in your prompt.

## Background
- The CM848 carries its own e2m record -> address table: `cm848_lookupParameterIdAddress` searches 6-byte records
  [e2m block id][address] in flash2.
- Every record in your bin sits at its `address`, but that address already has a name, and the name shares no word with
  the record. Usually one of three things is going on:
  1. **Synonym (keep):** the name is accurate, only worded differently. `key_on_hour_meter` for ECM_Run_Time,
     "Time key switch is on and ECM is running", stays.
  2. **Misname (rename):** the name describes something else. Examples: `boost_*` on an exhaust pressure estimate;
     `diag_dm1_*` on the data collector; `protection_*` on a monitor's parameters; a `_cal` on a ROM constant.
  3. **Drift (no change):** the labelled e2m is calibration 11.45 and the truck runs 11.46.06. A record can sit at a
     shifted offset, so the code use contradicts the record, and the current name, based on the code, may be right.
     Wave 12 found drift in blocks 10E3 / 1228, 8A2B / 8A37, 8A14 (+2C on), 1930 (+12 on), 1902 (+2A..+2E) and 1253.
- Many current names came from careful earlier work. Their comments often hold proved facts. Read the comment before
  you judge the name.

## Files
- Your bin: a JSON list (path in your prompt). Each item has:
  - the record: `record`, `unit`, `size_bytes`, `signed`, `scale`, `min`, `max`, `description`;
  - the current row: `label_in_cpp` (the current name), `current_row_type`, `current_comment`;
  - the code context: `code` (up to 4 lines that use the name) and `access_widths`;
  - `region` (it decides `_cal`), `block_named_rows` (the block's named rows with their word-overlap scores) and
    `other_records_at_this_address`.
- Decompiled code: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
  and the CSVs next to it (global_variables.csv: address,name,type,comment).
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines`;
  - .../width_census.py `<all.dis> 0xADDR` (all.dis is in the same folder);
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/e2m_block_addresses.py
    `BLOCK` or `--address 0xADDR`.

## Per record
1. Read the current comment and the code that uses the name. Open the function when the line alone does not show the
   role.
2. Decide which case it is:
   - **keep:** the current name is accurate. A synonym, or more specific than the record, is fine.
   - **rename:** the current name is wrong or misleading for what the code does, and the record matches the code. A
     name that breaks a rule also gets a rename, even when its meaning is right: an invented abbreviation (temp, cnt,
     ref, val, calc, init, cfg ...), or a wrong `_cal` (`_cal` only in the EEPROM mirror 0x3fd482-0x3feec1).
   - **drift:** the record does not match the code at this address. Leave the name; say what the code shows.
   - **uncertain:** you cannot tell.
3. For a rename, name it in snake_case from the record name and description (the rules below). Keep the accurate
   specifics of the current name and comment, such as units, direction and which monitor or message. Rename a misnamed
   family in your bin consistently: siblings with the same wrong prefix get the same new prefix.

## Naming rules
- Spell words out. No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox, id,
  adc, pwm, can, pid, tpu, qadc, vin, tsc1.
- Drop the e2m `C_` / `T_` prefixes. `_cal` is decided by the region alone: in the EEPROM mirror the name ends `_cal`,
  everywhere else it never does.
- Cummins abbreviations:
  - **Basic words:** Tmptr = temperature; Thd = threshold; Cmd = command; Amb = ambient; Ref = reference;
    Avg = average; Frac = fraction; Adj = adjustment; Cnt = count; Lmt / Lim = limit; Sw = switch; Val = value;
    Pos = position; Filt = filtered; Diag = diagnostic; Ovr = override; Vlv = valve; Pct = percent; Cyl = cylinder.
  - **Engine terms:** Inj = injection or injector; SOI = start of injection (the repo writes `injection_timing`);
    Veh = vehicle; Baro = barometric; Alt = altitude; Trq = torque; Batt = battery; IMT =
    intake_manifold_temperature; CT = coolant_temperature; APS = accelerator_pedal.
  - **Systems:** COT = compressor_outlet_temperature; MCF / CMF = charge_mass_flow; VGT =
    variable_geometry_turbocharger; PTO = power_take_off; CC = cruise_control; EB = engine_brake; Jcomm = j1939;
    EL = emission_level.
  - **Governors:** LSG / HSG / ASG / VSG = low / high / all / variable speed governor.
  - **AECD:** use the repo's `<condition>_protection_*` family.
- Module prefixes (EMO_, CBR_, FSS_ ...) are Cummins-internal: use the words the block's other names use.
- Never a bare "protection": say protection of what. Use initialize, never init. Numbers in decimal.
- The new name must not exist anywhere yet (grep global_variables.csv and the .cpp). No two rows may get one name.

## Output: one JSON object per line, one line per record of your bin
- **rename:** `{"kind": "global", "verdict": "confirmed", "address": "0x...", "old": "<current name>", "new": "...",
  "evidence": "...", "comment": "..."}`
  - The `comment` is the full new CSV comment. Lead with the e2m record and its description, then the role in the
    code. Keep the old comment's proved facts. Do not add "(was ...)": the apply adds it.
- **keep:** `{"kind": "global", "verdict": "keep", "address": "0x...", "old": "<current name>", "new": "<same>",
  "e2m_note": "e2m <block> +<offset> <record> '<short description>'"}`. The note is appended to the comment, as a
  cross-reference.
- **drift:** `{"kind": "global", "verdict": "drift", "address": "0x...", "old": "<current name>", "evidence": "<what the
  code shows vs the record>"}`
- **uncertain:** `{"kind": "global", "verdict": "uncertain", "address": "0x...", "old": "<current name>", "evidence":
  "..."}`
- `evidence`: one line with code function names and line facts, for example `e2m 1772 +A EXP_Exhaust_Pressure_Est
  (IN_HG): written by phase_group_a_validateEngineSync as the exhaust pressure estimate; the old name says boost`.
- Do not change types. If a type looks wrong, say so in the evidence.

Finish with a short summary in your final message:
- counts per verdict;
- the families you renamed;
- drift found;
- any function whose name your evidence shows is wrong (address, current name, proposed name, one-line reason). These
  are not applied automatically.
````

## 12. Review e2m names wave 13 bin 1 (557k tokens, 36 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin1.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin1.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W13 bin1 is written: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin1.jsonl. It has 64 lines in bin order. The `old` names match global_variables.csv, and the 28 new names pass the apply_renames / gate_W12 name rules and appear nowhere else in the firmware tree. `git status` is clean.

## Counts
- 28 rename (verdict `confirmed`), 31 keep, 5 drift, 0 uncertain.
- Comment clipping: the comments run up to ~980 characters. The apply clips at 360-400, so only the e2m record and the role sentence survive. Raise the limit if the lead wants more.

## Families renamed
- `engine_speed_limit_droop_type_select_cal` (0x3fdd38)
- `data_collector_center_address` (0x40c27c)
- `accelerator_pedal_autozero_cal` (0x3fddaa)
- `fault_detected_bits_592_to_607` (0x3fe9be, was `iat_sensor_deviation_flags`)
- `throttle_100_fueling`, `throttle_100_fueling_low_horsepower_curve`, `throttle_100_fueling_without_programmable_power` (0x40a897 / 899 / 89f)
- `j1939_derated_fueling_at_point_4` / `_5` (0x5c356 / 0x5c358)
- `fuel_temperature_derate_precrank_error_flag` (0x40a74c)
- The road speed governor (RSG) droop words in two prefixes:
  - Values passed to the fueling code: `vehicle_speed_limit_fueling_bottom_droop_gain`, `_top_droop_gain` and `_top_droop_offset` (0x40b6b2, 0x40b6b8, 0x40b6ba).
  - Values computed by the governor: `road_speed_governor_bottom_droop_gain` and `road_speed_governor_top_droop_gain` (0x40b6b6, 0x40b6bc).
  - Another bin may hold the Cruise twins or block 1102, so the lead may need to reconcile the prefixes.
- `j1939_pgn65251_speed_points_request_flags` (0x40a732)
- `wastegate_duty_feedforward_term`, `wastegate_duty_proportional_term`, `wastegate_duty_compressor_outlet_temperature_derate_error_term` (0x40a3be / 3c2 / 3e6)
- `egr_mass_flow_estimate_maximum` / `_minimum` (0x4002e4 / e6). The old `lower` / `upper` meaning was swapped: 0x4002e4 is the ceiling.
- `stoichiometric_oxygen_fuel_ratio` (0x406004)
- `injector_driver_pull_in_duration`, `injector_driver_delay_duration` (0x4090a0 / a4)
- `fuel_pressure_governor_derivative_gain_small_signal`, `_positive_large_signal`, `_negative_large_signal` (0x4094c4 / c8 / cc)
- `cruise_resume_downshift_delay_timer` (0x40b0ac)

## Type flags (types not changed)
- 0x4002e4 and 0x4002e6 are signed (`lha`, e2m S): i16.
- 0x4094c4 / c8 / cc are 4-byte records read with `lwz`, but the rows are `word`. Retype to dword and remove the `_lo_cal` rows at 0x4094c6 / ca / ce. The apply tool should not carry that to-do into the comments.

## Drift
- **1930 +16 (0x3feebc, BTR_Numerator) confirms the known drift from +12 on.** The word is a 0/1 latch for the engine retarder selector switch (switch 12), set in `cm848_mainLoopMonitor` and gating the logical output 11 check (faults 41/42 = P0478/P0477). The name also breaks the rules: EEPROM mirror without `_cal`, and a bare `protection_b`. A later pass should rename it to `engine_retarder_switch_learned_flag_cal`.
- **8D14 from +2 is new drift.** +0 holds (0x40b0ac, renamed): it reloads 150 = 1.5 s, counts down in 4th gear with the cruise flag, and gates the 4-3 downshift request. +2, +4, +C and +E (0x40b0ae / b0 / b8 / ba) are 16-bit shift-prediction words of the 48RE transmission governor pressure code, not timers or a lamp. Their `protection_*` prefix is wrong for that code.
- **8C4E +6 OSS_Ratio and 8C58 +12 Gov_Press_Control_Ratio alias one word with 8C5B +0 RE_PN_Rationality_Status.** That word is `park_neutral_switch_monitor_state` (0x40b570). I used `keep` with the 8C5B note, which also names the bin's records. The lead can flip it to drift if the gate wants the bin's record.
- Everything else matched: 0004, 0008, 0034, 101A, 1036, 105A, 1080, 1104, 1152, 1187, 11A4, 12BB, 162E, 16A2, 174F, 177E, 1791, 17AC, 801A, 8041, 80EF.

## Notes for the apply
- The old comment on 0x40b0ac ("overtemp ... derate level 4") is wrong. Do not carry it as "earlier note".
- The keep note for 0x6456c duplicates the wave 12 comment, which already leads with that record. Skip appending it.
- For 0x40b6bc (`road_speed_governor_top_droop_gain`), the old name `cruise_ramp_rate_d_working` is a different address from the existing `cruise_ramp_rate_d_computed` (0x3fcff4).
- 0x40a899 and 0x40a89f rest on e2m labels plus code corroboration. The "ESP Tau 0" wording on 0x40a89f is not reproduced by the code and is left open in the evidence and comment.

## Out-of-bin siblings, same wrong names (not applied)
- 0x3fea22 `j1939_tsc1_mode_shadow` → `fault_registered_bits_592_to_607` (registered twin of word 37)
- 0x5c34e / 0x5c350 `protection_threshold_scale_cal` / `_base_cal` → `j1939_engine_speed_at_point_4` / `_5`
- 0x40b6b4 `cruise_speed_setpoint_c` → `vehicle_speed_limit_fueling_bottom_droop_offset`
- Cruise twins, with proposed names:
  - 0x40b698 `cruise_speed_reference_a` → `cruise_control_fueling_bottom_droop_gain`
  - 0x40b6ac `cruise_speed_reference_b` → `cruise_control_fueling_top_droop_gain`
  - 0x40b6ae `cruise_speed_offset_b` → `cruise_control_fueling_top_droop_offset`
  - 0x40b69a `cruise_governor_fuel_demand_lower_ramp_start` → `cruise_control_fueling_bottom_droop_offset`
  - 0x40b69c / 0x40b6b0 `cruise_ramp_rate_a_working` / `_b_working` → `cruise_bottom_droop_gain` / `cruise_top_droop_gain`
- 0x3fa8ae / 0x3fa8b0 `protection_mode_request_bit` / `protection_mode_request_initialized_flag` (same wrong prefix as 0x40a732)
- 16A2:
  - 0x40a3e0 `governor_pid_adjustment_output` → `wastegate_duty_first_error_derivative_term`
  - 0x40a3e2 `governor_trim_lookup_result` → `wastegate_duty_second_error_gain`
  - 0x40a3e4 `governor_rpm_correction_term` → `wastegate_duty_second_error_derivative_term`
  - The feedforward calibration source 0x3ffca6 `throttle_rate_integrator_cal`, and its `throttle_rate_*` cal siblings, also belong to the wastegate controller.
- 177E +6 / +A / +C: 0x4002e8 `throttle_conversion_scale_cal`, 0x4002ec `rpm_fuel_trim_select_cal` (upstream/downstream EGR flow model select), 0x4002ee `throttle_load_scale_factor_cal`
- 80EF: 0x4094c2 `engine_sync_prot_gain_cal` → `fuel_pressure_governor_derivative_gain_constant`; 0x4094d0 `engine_sync_prot_limit_cal` and 0x4094d2 `engine_sync_prot_gain_b_cal` → `fuel_pressure_governor_derivative_positive_window_width` / `_negative_window_width`
- 8041: `mios_pwm16..19_*_ref` and `tpu_ch14_period_base` still carry `ref`

## Function names the evidence shows wrong (not applied)
| Address | Current name | Proposed name | Reason |
|---|---|---|---|
| 0x0001f17c | `cm848_calculateFuelDemandWithTrim` | `cm848_calculateThrottle100Fueling` | stores the five e2m 105A Throttle_100 fueling values |
| 0x000173a8 | `cm848_fuelDemandOverrideHandler` | `cm848_learnAcceleratorPedalAutozero` | tracks the lowest pedal reading with the idle switch on and writes the EEPROM autozero |
| 0x00020c64 | `cm848_processJ1939RxMessage` | `cm848_setTorqueCurvePoints2And5AtDroopLineFueling` | takes a fueling in param_1 and sets curve points 2 and 5; handles no message |
| 0x00020d10 | `cm848_updateProtectionStateMachine` | `cm848_updateJ1939EngineConfigurationTorqueCurve` | fills the e2m 1102 Jcomm speed / fueling / torque points of PGN 65251 |
| 0x00021ac0 | `cm848_initUdsServiceHandlers` | `cm848_lookupJ1939FuelTableAtEngineSpeed` | returns the chi/alpha-interpolated `j1939_fuel_table` value at the engine speed passed; no UDS |
| 0x000127bc | `cm848_selectFuelTrimMode` | `cm848_selectEgrMassFlowModel` | clamps the EGR mass flow estimate (`throttle_fuel_trim_t.final_trim`) |
| 0x000125f4 | `cm848_calculateRpmBasedFuelTrim` | `cm848_calculateEgrMassFlowUpstreamModel` | feeds that EGR estimate; selected by `rpm_fuel_trim_select_cal` = 0 |
| 0x0001242c | `cm848_calculateLoadBasedFuelTrim` | `cm848_calculateEgrMassFlowDownstreamModel` | feeds that EGR estimate; selected by `rpm_fuel_trim_select_cal` != 0 |

Cluster lead, no names proposed: `cm848_protectionScaledLimitCalculation` (0x320e0), `cm848_protectionRateOfChangeCalculation` (0x32250), `cm848_calculateProtectionFuelDemandThreshold` (0x3241c) and `cm848_processProtectionStateFlags` (0x3257c). They are 48RE shift / governor pressure code (`transmission_current_gear`, `transmission_output_speed_change`, `governor_pressure_target`), not protection.
````

## 13. Review e2m names wave 13 bin 2 (703k tokens, 43 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin2.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin2.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W13 bin2 is done: 64 lines written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin2.jsonl, in bin order. Nothing else was touched; `git status` is clean.

My own self-check passed. It covered address and `old` against the bin and the CSV row, name uniqueness against CSV fields and .cpp tokens, the BANNED set, `_cal` by region, comments of 360 characters or fewer, quoted dump values against `dump_raw`, and no comment citing a name this bin renames.

**Verdicts:** 48 rename (confirmed), 10 keep, 6 drift, 0 uncertain.

**Families renamed**
- **104C AFC (3):** `air_fuel_control_{normal_boost_timer, low_boost_timer, low_boost_blend_fraction}`. The old `fuel_ramp_*` names read backwards.
- **109C friction fuel (4) and 175C +8:** `friction_fueling` and `friction_fuel_adjustment_for_{coolant_temperature, air_conditioning_clutch, radiator_fan}`; `friction_torque_adjustment_for_coolant_temperature`. The old names said `governor_*` and `fuel_demand_rpm_correction_lookup`.
- **1102 Jcomm block (17):** the old `protection_*` / `j1939_dm1_*` / `fuel_demand_*` names, which are the PGN 65251 engine configuration and torque curve. New names:
  - `actual_engine_percent_torque_times_256`
  - `j1939_engine_percent_load_at_current_speed_times_256`
  - `j1939_indicated_percent_torque_at_{idle,point_2,point_5}_times_256`
  - `j1939_determined_engine_speed_at_point_{2,4,5}`
  - `j1939_reference_engine_fueling`
  - `reference_engine_torque_working` (old `_cal` was wrong)
  - `j1939_torque_curve_speed_at_point_{2,4,5}`
  - `j1939_torque_curve_fueling_at_point_{2..5}`
- **81AE/81AF cylinder balance (9):** `cylinder_balance_*`. The old "low / high threshold" names were reversed, and `cam_timing_*` was wrong.
- **18D9 intake manifold temperature lead (3):** `intake_manifold_temperature_{after_lead, lead_term, lead_time_constant}`. The old names said pressure.
- **Singles:**
  - `data_collector_end_address` (was `diag_dm1_*`)
  - `supervisor_chip_driver_feedback_delay_microseconds` (was `j1939_address_cached`)
  - `cruise_driver_fault_match_debounce_threshold` (was `protection_*`)
  - `ram_refresh_enable` and `development_mode` (see judgment calls)
  - `rear_axle_ratio_{low,high}_cal`
  - `road_speed_governor_top_droop_width_cal` (gains the mirror `_cal`)
  - `key_off_shutdown_mode`
  - `total_fueling`
  - `exhaust_temperature_estimate_injection_timing_coefficient`

**Drift**
- **1B2D, +4 on (4 rows, 0x40b9c8..ce):**
  - The code there is the OBD monitor enabling inputs, which an earlier pass tied to block 160A. Block 160A is outside the dumped ID table.
  - 1B2D +0 and +2 (0x40b9c4 / 0x40b9c6) hold: they are the key-on rationality abort code and state.
- **1966, +94 on (0x40be16):** the value/default pairs end at +92, and fault status words start at 0x40be14.
- **1649, +10 on (0x3fd948):**
  - The 193A +0 Test_Sensor1_Ratio_Supply_ID array starts here; the in-plant EOL struct ends at +F.
  - 193A +0 matches the current name and could be added as the cross-reference.

**Judgment calls to review**
- **0x40c04a `diagnostic_session_state` -> `ram_refresh_enable`, and 0x40aa9a `j1939_standby_flag` -> `development_mode`.** The evidence is strong:
  - `cm848_initProtectionModule` is the compare-and-rewrite loop, and it sets fault bit 0x1, which is e2m `RAM_Image_Word_Error`.
  - `cm848_runCylinderContributionTest` clears the flag while it edits calibration RAM.
  - Boot sets it ACTIVE.
  - The reset service sets `development_mode` and clears the refresh enable together.

  The enums `DIAG_SESSION_STATE` / `J1939_STANDBY_STATE` and their member descriptions still follow the old reading, and I did not change types.
- **0x40a33a `fuel_timing_arbitration_output` -> `total_fueling`.** There is no timing in it. `timing_limit_upper` (0x5c30c) is e2m 1052 +6 Minimum_Fueling.
- **0x3fd482 `eeprom_mirror`:** kept without `_cal`, as the base symbol of the whole mirror. It is the one mirror-region row I left deliberately.
- **`friction_fueling` and `total_fueling`:** these equal names in `e2m_variables.csv`. They are not in `global_variables.csv` or the .cpp, and 18 globals already coincide with that file.
- **Type remarks:**
  - Signed records typed `word` with `lha` reads are `i16` candidates: 0x40aef6, 0x40ad8a, 0x40afbe, 0x40676c, 0x40a458, 0x408eee and 0x408ef0.
  - 0x40a45a, 0x408f24, 0x408f26, 0x3fee94 and 0x3fee96 are signed and read through `(short)` casts.
  - 0x408ef2 is unsigned but read with `lha`.

**Functions whose names the evidence shows are wrong (not applied automatically)**

| Address | Current -> proposed | Reason |
|---|---|---|
| 0x0001b3a0 | `faultTimerHandler` -> `cm848_buildPgn65251EngineConfigurationMessage` | Fills the 28-byte PGN 65251 payload from the torque curve snapshots. |
| 0x00020d10 | `cm848_updateProtectionStateMachine` -> `cm848_updateJ1939TorqueCurve` | Builds the speeds, fuelings and percent torques at points 1-5; no protection state. |
| 0x00020c64 | `cm848_processJ1939RxMessage` -> `cm848_calculateJ1939TorqueCurveDroopBreakpoint` | Tail helper of the above, not a receive handler. |
| 0x00020500 | `cm848_calculateProtectionActivationDelay` -> `cm848_calculateReferenceEngineFueling` | Computes the Jcomm peak fueling. |
| 0x000209e8 | `cm848_calculateLoadRateOfChange` -> `cm848_calculateActualEnginePercentTorque` | Computes the EEC1 actual percent torque x 256. |
| 0x00020a58 | `cm848_calculateLoadToFuelRatio` -> `cm848_calculateEnginePercentLoadAtCurrentSpeed` | Computes the EEC2 percent load. |
| 0x0002588c | `j1939GetEngineStateCode` -> `cm848_buildPgn61444ElectronicEngineController1Message` | Builds and sends EEC1. |
| 0x000212dc | `cm848_initProtectionDelayDefaults` -> `cm848_initializeJ1939ReferenceEngineFuelingAndTorque` | Loads the ROM peak fueling and reference torque. |
| 0x00021cd4 | `cm848_updateProtectionDiagnostics` -> `cm848_updateJ1939TorqueCurveReferenceFuelings` | Skimmed only: it sets the five per-point reference fuelings. |
| 0x0050dba8 | `governor_computeSpeedTargetWithThermalCorrection` -> `cm848_calculateNoLoadFuel` | Sums friction fuel plus the coolant, A/C and fan adjustments. |
| 0x0050eaa8 | `cm848_applyProtectionRpmCorrectionFilter` -> `cm848_calculateEngineFrictionAndNetMachineTorque` | Computes the 175C friction, no-load and net machine torques. |
| 0x00013d14 / 0x00013dc8 | `cm848_calculatePressureSensorDerivative` / `...Filtered` -> `cm848_calculateIntakeManifoldTemperatureLeadTerm` / `cm848_filterIntakeManifoldTemperature` | Channel 9 is the intake manifold temperature. |
| 0x00538a84 / 0x005389c4 | `cm848_initProtectionModule` / `uds_session_state_init` -> `cm848_refreshRamCalibration` / `cm848_initializeRamRefresh` | The RAM refresh loop and its setup. |
| 0x00021624 / 0x00021668 / 0x00021694 | `cm848_activate` / `reset` / `forceActivateDiagnosticSession` | They set or clear `ram_refresh_enable` and `development_mode`; reset enters development mode. Review the names. |
| 0x00505c20 | `diag_dm1Buffer_circularFill` -> `cm848_fillDataCollectorBuffer` | It is the data collector. |
| 0x0004272c / 0x00042770 / 0x005268e8 | `cm848_applyProtectionControlLimit` / `cm848_setProtectionControlValue` / `cm848_computeProtectionTrimDivisors` -> `cm848_selectRearAxleRatioInUse` / `cm848_selectRearAxleRatioHigh` / `cm848_calculateRearAxleTrimDivisors` | Axle ratio selection and its trim divisors. |

**Siblings outside the bin that keep wrong names (for another pass)**
- **1102:**
  - 0x40ad90 `j1939_engine_torque_output_b` is the EEC3 nominal friction percent.
  - 0x40ad96 `protection_speed_ratio_c` and 0x40ad98 `protection_speed_ratio_d` are the point 3 and 4 percent torques.
  - 0x40ada0 and 0x40ada2 are the determined speeds at points 1 and 3.
  - 0x40adac and 0x40adb0 are the torque curve speeds at points 1 and 3.
  - 0x40adb6 is the point 1 fueling.
  - 0x40adc0..c8 `protection_*_cached` are the Calc_Fueling points 1-5.
  - 0x40adca..d2 `governor_speed_ref_channel_a..e` are the per-point reference fuelings.
  - ROM 1104: 0x5c34e, 0x5c350, 0x5c356 and 0x5c358 (`protection_*_cal`) are the Jcomm speeds and derated fuelings at points 4 and 5.
  - 0x40a298 `protection_temp_scale_factor` is the axle ratio in use, and 0x3fd062 / 0x3fd066 `protection_trim_divisor_*` are the axle ratio times the timing period.
- **18D9:**
  - 0x40a462 `fuel_demand_phase_state` and 0x40a464 `fuel_demand_phase_status_flags` are Charge_Tmptr_Source / State.
  - The `sensor_channel9_pressure_*` rows are the intake manifold temperature channel.
- **10C7 +2:** 0x40c04c `sensor_validation_result` is Powerdown_Refresh_Enable.
- **1B2D +0 / +2:** 0x40b9c4 and 0x40b9c6 `cam_sync_validation_abort_reason` / `_state` are the fuel pressure key-on rationality abort code and state.
- **1042:**
  - 0x40a036 `fault_active_recovery_threshold_ch19_20` carries a `ch` abbreviation; it is Cruise_Driver_Recover_Count.
  - The `j1939_can_frame_word_*` / `j1939_timer_*` rows are supervisor chip words.
- **11D5:** 0x3ff00a..10 `fuel_ramp_*_cal` carry a `_cal` outside the mirror. They are the AFC time delay and select slew records.
- **Data collector:** 0x40c270..84 `diag_dm1_buffer_*`, 0x3fddba and 0x3fddb8. Mechanical names would be `data_collector_buffer_start_address` and so on.
- **120C:** 0x5c30c `timing_limit_upper`, 0x3fa86c, 0x3fa870 and 0x3feaa2 carry the same misread "timing".
- **1185 +4:** 0x3fd912 `cruise_ramp_zone_b_fuel_demand_threshold` should be `cruise_top_droop_width_cal`.
- **81AE:**
  - 0x408f2c and 0x408f2e `cylinder_diag_*_threshold_cal` are the CBD service trim maximum / minimum, with a `_cal` outside the mirror.
  - 0x3fb5a4 and 0x3fb5a6 are the matching snapshots.
  - 0x408f30 is the cylinder contribution gain.
  - 0x408f13 and 0x408eec `cam_timing_*` also need a pass.
````

## 14. Review e2m names wave 13 bin 3 (689k tokens, 38 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin3.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin3.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W13 bin3 is finished: 64 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin3.jsonl, in bin order. I edited no repo file and made no scratch file. A script check found no problems: `old` is exactly label_in_cpp, no bad names or `_cal` errors, comments at most 396 characters with no "(was". None of the 40 new names exists in the CSVs, .cpp or .hpp, and none collides with the names in the bin1/2/4/5/6 result files present when I checked.

**Verdicts:** 40 confirmed renames, 20 keep, 4 drift, 0 uncertain.

**Renames, by family**
- **`_cal` fixes (meaning right, rule broken):**
  - Missing `_cal` in the EEPROM mirror: `fault_aging_drive_cycle_counter_cal` (0x3fed90) and `engine_start_count_since_fault_logged_cal` (0x3fedce, was a bare "protection").
  - `_cal` outside the mirror, dropped: the 1944 rows (0x4009d4 and 0x4009d8, which were also the wrong domain) and `shift_in_process_hold_off_time_limit` (0x40869c).
- **Misnames:**
  - **000D:** `not_safe_to_program_flag` (0x40af66, was `prior_boot_faulted`). It holds engine_state != STOPPED.
  - **0036:** `data_collector_status` (0x40c284). The `diag_dm1_*` words around it are the data collector, not J1939 DM1.
  - **1052:** `fuel_demand_minimum` (0x5c30c, was `timing_limit_upper`). Every use is a lower bound. It is not `fuel_demand_minimum_tracked`.
  - **1053:** `four_dimensional_fueling`, `four_dimensional_fueling_user_maximum`, `commanded_throttle_filter_coefficient` and `commanded_throttle_filtered`.
  - **106C:** `drivetrain_ratio_change_settle_counter` (0x40b6fc). `fuel_flow_divisor` is the wrong domain.
  - **10B1:**
    - `engine_protection_precrank_shutdown_command_flag` (0x40a782).
    - `engine_protection_shutdown_approaching_flag` (0x40a786). The old name duplicated `fault_derate_active_flag`; the code sets this when a channel's timer passes the start-warning time.
  - **10E2:** `j1939_friction_load_fueling_at_breakpoint_4` (0x40a644).
  - **118A:** `cruise_governor_reference_speed` (0x40b6d4).
  - **11D4:** `master_slave_final_override_fueling` (0x40a87b) and `master_slave_override_enable_flag` (0x40a87d).
  - **1211:** `monitor_readiness_code_cal` (0x3fed94). The old comment's "clear as faults resolve" is wrong. The bits are OBD monitors still to run.
  - **16A3:** `wastegate_duty_first_error_term_limit_enable_flag_cal` (0x3fd7de). It matches the existing `wastegate_duty_second_error_term_limit_enable_flag_cal`.
  - **1981:** `end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal` (0x3fee9b).
  - **80B9:** `injector_diagnostic_bits_{fast_decay, open_circuit, short_to_ground, short_to_battery}`, replacing the letters d, a, b and c.
  - **81B0:** `cylinder_balance_{filtered_fueling, fourier_real_component_1, fourier_imaginary_component_1, adjusted_real_component_2, adjusted_imaginary_component_2, adjusted_real_component_3, acceleration_buffer_6}`. I derived these from the harmonic sums in `hpcr_cbdCalculateCylinderTrims`, because two e2m descriptions are copy-pasted.
  - **8A14:** `shift_in_process_hold_off_time_limit` (0x40869c).
  - **8C33:** `converter_clutch_rationality_maximum_engagement_time` and `converter_clutch_steady_throttle_count_limit`.
  - **8C58:** `governor_pressure_zero_check_{state, debounce_count}` and `governor_pressure_mid_range_check_{fail_count, state, debounce_count}`. They match the existing 8C59 cal names; the monitors are P1757 and P1756, checked against the ROM tables.
- **Keep (accurate synonyms):** 0x40b6fa, 0x40a77e, 0x40a792, 0x3fed92, 0x3fd7f0, 0x40a706, 0x40ba36, 0x40b856, 0x4086be, 0x40b0a8, 0x40b44f, 0x40b450 and the eight 8A13 timers.

**Drift**
- **0x40ba48 and 0x40ba4a (1902 +2A / +2C):** the code uses them as the thermostat monitor's fuel words, not performance ratios.
- **0x4086c8 (8A14 +2E):** only the TSC1 reload fits; dump 20 is 0.3 deg F.
- **0x40b56e (8C58 +10), new:** the word is the P0720 output speed sensor state, which is e2m 8C4E +4 OSS_Rationality_Monitor_State at the same address. 8C4E +0 resolves to 0x40b56a, which is 8C58 +C, so the 8C58 tail (+C..+12) overlaps 8C4E. 8C59 +1A / +1C land on 8C4F +0 / +2.

**Vocabulary choices**
- `four_dimensional_*` follows the e2m ("4D"). The repo's `cm848_calculateDualAxisFuelLimit` and the enum say "dual axis".
- `malfunction_indicator_lamp` is spelled out; the repo's existing `mil_*` names are not on the brief's allow-list.
- `fourier` stands for FFT.
- `cylinder_balance_` follows the existing 81AF rows.
- 80B9 splits a family: eight out-of-bin rows keep the letters. Map: a = open_circuit, b = short_to_ground, c = short_to_battery, d = fast_decay.
  - The out-of-bin rows are `injector_diagnostic_bits_{a,c,b,d}_debounce_count` at 0x3fb6fc / 0x3fb6fe / 0x3fb700 / 0x3fb702 and `_debounce_limit` at 0x409a8c / 0x409a90 / 0x409a8e / 0x409a8a.
  - Short-to-ground versus short-to-battery rests on the e2m byte order only; both bytes feed P2146 / P2149. Open circuit is anchored by P0201-P0206.

**Type notes (not changed)**
- 0x40a87d is `dword` but should be `word`: the record is 2 bytes, every load is `lhz`, and it covers 11D4 +4 at 0x40a87f.
- 0x40b73c, 0x40b73e, 0x40b740, 0x40b742, 0x40b744 and 0x40b756 are signed records read only with `lha`, so `i16` would fit.
- 0x40b856 (a keep) is also signed with three `lha` loads.

**Old facts only in the evidence**
- Comments assume the apply keeps the old comment as an earlier note.
- 0x3fed94: the `lwz`/`stw` proof site (@ 0x52d634) and the note that it is distinct from `diagnostic_fault_flags_a/b` (0x40a813) are not repeated.
- Check the other renames if the apply drops old notes.

**Function names the evidence shows are wrong (not applied; proposed names not gate-checked)**
- 0x2bf44 `cm848_updateFaultOnKeyoff` -> `cm848_updateNotSafeToProgramFlag`. It runs every pass and only stores engine_state != STOPPED.
- 0x1e830 `cm848_updateEngineTimingCompensation` -> `cm848_updateFourDimensionalFueling`. It stores the 4-D fueling; nothing about timing.
- 0x1eae8 `cm848_calculateFuelDemandChangeRate` -> `cm848_filterCommandedThrottle`.
- 0x525e54 `protectionTimeoutControl` -> `cm848_updateDrivetrainRatio`. It computes and filters the drivetrain ratio and its out-of-gear and settle timers.
- 0x508130 `governor_coldStart_faultDerate_trigger` -> `cm848_examineEngineProtectionBeforeCranking`.
- 0x508898 `governor_faultDerate_mainLoop_update` -> `cm848_updateEngineProtectionShutdown`.
- 0x508e78 `cm848_updateJ1939ReceptionControlFlag` -> `cm848_detectEngineProtectionShutdownOverrideRequest`. It edge-detects the override switch, not J1939 reception.
- 0x508ee0 `governor_derateTrigger_latch_clear` -> `cm848_latchEngineProtectionShutdownOverride`.
- 0x1811c `cm848_faultSeverityEvaluation` -> `cm848_calculateFrictionFuelingAtBreakpoints`.
- 0x182e8 `cm848_calculateThrottleProtectionLimit` -> `cm848_calculateJ1939PercentPeakTorque`.
- 0x1820c `cm848_processThrottlePositionLookups` -> `cm848_calculateJ1939PercentPeakTorquePoints`.
- 0x18070 `cm848_throttlePositionProcessing` -> `cm848_calculatePercentPeakTorqueAtSpeed`.
- 0x50ddb4 `diag_suppress_stateMachine` -> `cm848_controlEndOfLineTestMilRequest`. It sets diagnostic_suppress_flag, which forces the MIL on.
- 0x533b18 / 0x533b5c / 0x533b94 `diag_protection_history_increment / _shiftIn / _shift` -> `cm848_incrementEngineStartCountsSinceFaultLogged` / `cm848_shiftInEngineStartCountsSinceFaultLogged` / `cm848_shiftEngineStartCountsSinceFaultLogged`.
- 0x42cfc `hpcr_processLoadThrottle` -> `hpcr_filterCylinderBalanceFueling`. It filters final_fueling for the cylinder balance code.

**Out-of-bin sibling leads (not in my bin)**
- **10E2:** 0x40a630-0x40a646.
  - Percent peak torque rows: `throttle_protection_load_ratio`, `throttle_position_b6` / `b8` / `ba` / `b4`, `throttle_position_from_integrator`.
  - Friction rows: `throttle_torque_integrator_lookup`, `throttle_cal_b4_lookup`, `throttle_cal_b6_lookup`, `throttle_cal_ba_lookup`.
  - They fit `j1939_percent_peak_torque_at_*` and `j1939_friction_load_fueling_at_*`.
  - I did not verify that the percent-torque words feed PGN 65251.
- **106C:** 0x40b6f6 `fuel_flow_rpm_divisor` (User_Filtered_Gear_Ratio), 0x40b6f8 `fuel_flow_divisor_invalid_flag`, 0x40b6fe `fuel_flow_rpm_divisor_saved`. They hold the drivetrain ratio, not fuel flow.
- **10B1:**
  - 0x40a78a `governor_fuel_derate_j1939_latch` is the shutdown override request.
  - 0x40a790 `governor_fuel_derate_state` is the engine protection timer state.
  - 0x40a772 and 0x40a774 (`governor_faultDerate_*`) are camelCase legacy names.
  - 0x40a74c `governor_faultDerate_ch0_threshold_exceeded` is 1152 +18 Fuel_Temperature_Precrank_Error.
- **1053:** 0x40a889 `thermal_fuel_limit_factor` is the 4-D interpolation factor. 0x40a891 `fuel_limit_mode_flags` holds the throttle transient/decrease flags. The `fuel_mode_ema_*` rows at 0x3fa880-0x3fa884, 0x406a46 and 0x406a52 are the same throttle filter.
- **8C33 / 8C34:** the P1740 `protection_*` rows at 0x408ad2, 0x408ad3, 0x408ade and 0x40b57a-0x40b58e. That includes `protection_pid_step_counter` (TCC_Rationality_Timer), `protection_output_stability_counter`, and `governor_pressure_error` (OD_Function_Timer).
- **8C58 / 8C59:**
  - 0x40b55e `protection_coldStart_channelA_trip_count` -> `governor_pressure_zero_check_fail_count`.
  - The window_active flags and 0x408a9c / 0x408aa4 / 0x408aa8 `protection_coldStart_*_threshold`. These are governor pressure target limits, not rpm.
  - 0x408aac / 0x408aae `protection_load_*_threshold`, a transmission temperature window.
- **81B0 and neighbours:**
  - 0x40b74c-0x40b754 `cylinder1..5_timing_offset` are Accel_Buffer_1..5, so `cylinder_balance_acceleration_buffer_1..5`.
  - 0x40b746 `cylinder_sync_valid_flag` and 0x40b747 `crank_pattern_sync_flag` are CBD_Stop_Compensation_Flag and CBD_Trim_Limits_Exceeded.
  - The 81AF rows `cam_timing_prev_capture_a/b` and `cylinder_sync_state`, and the 81B1-3 `cylinder_seq_*` rows.
- **0x3fed98 `fault_pending_flags_b`:** Pending_Readiness_Code, so `monitor_pending_readiness_code_cal`.
- **0x3fedbc `protection_event_spn_history`:** the fault code history; it is in the EEPROM mirror and lacks `_cal`.
- **0x40a19a `boost_fuel_demand_blend_a`:** holds `ambient_air_temperature_selected`.
````

## 15. Review e2m names wave 13 bin 4 (580k tokens, 32 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin4.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin4.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
Wave 13 bin 4 is done: 63 lines, one per record, in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin4.jsonl. The repo gate was not run (see "Gate not run"); my hand copy of its checks passes.

**Counts:** 21 rename (verdict confirmed), 42 keep, 0 drift, 0 uncertain.

**Families renamed** (each comment leads with the e2m record, then the code role):
- Data collector: 0x3fddb8 `diag_dm1_protection_warning_active` -> `data_collector_trigger_active_cal`. It is in the EEPROM mirror, so `_cal`.
- System switch status, e2m 1092: `diagnostic_fault_flags_a` / `_b` -> `system_switch_status` / `_2`. The dump reads 0x60 (accelerator at idle plus key on).
- J1939 source addresses, e2m 10E3 +4 / +6 / +8: `j1939_tsc1_*_sa` -> `j1939_transmission_source_address`, `j1939_anti_lock_brake_source_address`, `j1939_anti_slip_regulation_source_address`.
  - Independent proof: e2m 117D +14 orders the devices TRANS / ABS / ASR / UNKNOWN as 1 / 2 / 3 / 4, which is what `cm848_lookupJ1939SourceAddressIndex` returns.
- Non-continuous monitors: 0x5a494 `j1939_feature_config_word` -> `supported_non_continuous_monitors_bits` (see drift below).
- EGR orifice, e2m 19CA / 1A19:
  - `throttle_trim_predictor_output` -> `egr_orifice_temperature_after_lead`.
  - `throttle_trim_predictor_gain` -> `egr_orifice_temperature_lead_time_constant`.
  - `boost_fuel_correction_prev` -> `egr_orifice_delta_pressure`.
- Fuel pressure governor proportional gains, e2m 8014: `injection_timing_scale_cyl1_a_cal`, `cyl2_a_cal`, `cyl3_a_cal` -> `fuel_pressure_governor_proportional_gain_small_signal`, `_positive_large_signal`, `_negative_large_signal`.
  - Proof: they are the gain block of `cm848_applyPiecewiseLinearGain`. The window words at 0x4094ae read +-10 MPa. Each gain has its own e2m 8005-800A scaling curve.
- Injection scheduler, e2m 805C / 805E:
  - `injection_timing_tooth_base_offset_mode2` -> `injection_timing_tooth_base_offset_cylinder_0`. 'mode2' is wrong because both scheduling paths use it.
  - `injection_tpu_timing_mode` -> `injection_tpu_period_parameter_address`. The values 2 and 0x12 are the low bytes of 0x304102 / 0x304112, which are TPU-A channel 0 / channel 1 parameter 1.
  - `cam_sync_position_high_byte` -> `injection_timing_tooth_separation_per_cylinder`. It is tooth count / cylinders = 120 / 6 = 20.
- Singles:
  - `fuel_demand_cmd20_pending_flag` -> `duty_cycle_monitor_map_reset_pending_flag`.
  - `protection_temp_scale_factor` -> `rear_axle_ratio` (dump 453 = 3.54).
  - `governor_speed_engage_reset_flag` -> `ecm_power_down_delay_request_flag`.
  - `fuel_demand_enable_sync_flag` -> `cruise_resume_active_flag`.
  - `map_fuel_correction_multiplier_cal` -> `engine_displacement_cubic_inches` (359.2 cu in). The old `_cal` was wrong.

**Drift found**
- 0x5a494: the labelled record, e2m 10E3 +28 DDT_TSC_ASG_Filter_Slew_Rate, is the 11.45 e2m's shifted tail. The record that also resolves there, 1228 +8 Supported_Non_Continuous_Monitors, matches the DM5 / DM10 / DM7 code. This line is a rename taken from the 1228 record, so the caller can downgrade it to leave-as-is.
- No drift in 10E3 +4 / +6 / +8, 117D, 805C / 805E, or 8A12. For 8A12 I checked all seven timer / status pointers against the PCI descriptor tables.

**Function names the evidence shows are wrong** (not applied)

| Address | Current | Proposed | Reason |
|---|---|---|---|
| 0x00505c20 | `diag_dm1Buffer_circularFill` | `cm848_fillDataCollectorRingBuffer` | fills the data collector ring buffer, not DM1 |
| 0x00505f98 | `cm848_phase_groupB_calculation` | `cm848_runDataCollector` | the collector pass |
| 0x00505d94 | `hpcr_exception_process` | `cm848_resetDataCollector` | resets the collector, called at start-up by `cm848_applicationMain` |
| 0x00505df0 | `j1939_dm1_diagnosticMessage_send` | `cm848_sendDataCollectorBuffer` | sends the collector buffer by transport protocol in stop mode 3 |
| 0x0050638c | `cm848_outputs2_periodic` | `cm848_updateDutyCycleMonitor` | the duty cycle monitor load histogram |
| 0x0004272c | `cm848_applyProtectionControlLimit` | `cm848_selectTwoSpeedRearAxleRatio` | selects `rear_axle_ratio` |
| 0x00042770 | `cm848_setProtectionControlValue` | `cm848_selectSingleSpeedRearAxleRatio` | loads `rear_axle_ratio` from the EEPROM word |
| 0x0003e210 | `cm848_setFuelDemandActiveFlag` | `cm848_requestPowerDownDelayWhileMoving` | sets the power-down delay flag |
| 0x00529ea4 | `cm848_sensor_diagnostic_flag_update` | `cm848_initializeInjectionAngleScheduler` | sets state 1, TPU address 2, channel 6 and the tooth separation |
| 0x00506f88 | `sensor_channel108_filter` | `cm848_applyEgrOrificeTemperatureLeadCompensation` | channel 108 is the EGR orifice temperature sensor |
| 0x00507028 | `sensor_throttleTrim_ema_faultProcess` | `cm848_filterEgrOrificeTemperature` | same |
| 0x0050716c | `sensor_throttleTrim_inputSelect` | `cm848_selectEgrOrificeTemperature` | same |
| 0x00017f50 | `cm848_calculateFuelFlowWithMode` | `cm848_calculateEgrDeltaPressures` | writes the orifice / valve / engine delta pressures |
| 0x0001242c | `cm848_calculateLoadBasedFuelTrim` | `cm848_calculateEgrOrificeFlowTerms` | medium confidence; its inputs are the EGR orifice delta pressure ratio, valve position and orifice temperature |
| 0x00012cf4 | `cm848_loadBasedFuelAdjustment` | `cm848_calculateChargeMassFlow` | speed-density charge flow |
| 0x00525e54 | `protectionTimeoutControl` | `cm848_estimateDrivetrainRatio` | it is the drivetrain ratio estimator |

**Out-of-bin siblings** (summary only, no lines written)
- Cruise resume: `fuel_demand_enable_sync_flag_shadow` (0x3fb528) and `_shadow_2` embed the old name.
- Axle ratio, e2m 1180:
  - `protection_temp_scale_cal` (0x3fd534) is Rear_Axle_Ratio_High, so `rear_axle_ratio_high_cal`.
  - `protection_temp_scale_factor_working` (0x3fd52e) is Rear_Axle_Ratio_Low, so `rear_axle_ratio_low_cal`.
  - `protection_trim_divisor_cal` / `_working` are the timing period times those two.
- EGR 1A19: `boost_fuel_mode_state` (0x40a626, EGR_Orifice_Delta_Press_Source) and `fuel_demand_enable_state_cached` (0x40a62e, Engine_Delta_Press_Source).
- EGR orifice temperature: `throttle_trim_predictor_gain_lookup` (0x3fbcf8) and `throttle_trim_predictor_output_min` (0x406776).
- 177C charge flow: the rest of 0x400932-0x400948 (C_CHP_* words) carry `boost_*` / `fuel_*` names, several with a wrong `_cal`.
- 8014 and 8005-800A:
  - `engine_sync_prot_scale_a_cal` (0x4094ae) is a dword over the two window widths, with a junk `+2` label row.
  - `injection_timing_scale_cyl4_a` / `cyl5_a` / `cyl6_a_cal` are the integral gains.
  - `cam_sync_cyl1-3_timing_{axis,values}_a_cal` (0x40918a, 0x4091a0, 0x4091b6, 0x4091cc, 0x4091e2, 0x4091f8) are the HPCR_SF_Propcomp curves.
  - `cam_timing_alt_mode_enable_cal` (0x4090fa) is HPCR_Governor_Mode.
- Remaining `diag_dm1_*` collector rows: 0x40c270-0x40c284, 0x3fbca6-0x3fbcb8, 0x3fddba (Collector_Stop_Mode), 0x3fddc4 (Collector_Table).
- Struct `fault_entry_t`: fields `diagnostic_fault_flags_a` / `_b` have stale "Sensor scale factor" comments.
- `protection_enable_byte_35` (0x40c085) is byte 5 of `logical_output_request_bits`, requests 40-47.
- `governor_startup_threshold` (0x40a2c4) is e2m 117D +5C ESP_Tau.
- 81C9 cutout: the four kept `cylinder_cutout_*` rows act on one injector bank (masks 0x55 / 0xaa, three cylinders each), and the e2m says bank. I kept them because the rest of the `cylinder_cutout_*` family is outside my bin. Rename the whole family if you want the bank wording.
- 8A12: the e2m calls message $98 an Rx message, but the PCI tables list it as TX[12].

**Type notes**
- Renamed rows: 0x40a2b4 is a dword accessed as a halfword (should be word). 0x40a624 is a word read signed (i16). 0x3fddb8 is a word but e2m signed with lha reads (i16).
- Kept rows: 0x40b05c is a dword read as a word. 0x40b9e0 is a word used signed.

**Gate not run:** the repo's `apply_renames.py` was denied by the permission system, so I did not retry it. A hand copy of its rules (banned words, name format, `_cal` rule, no existing name, one CSV row per address with a matching old name) shows no PROBLEM lines. New names do not collide with the result files of bins 1, 3, 5 and 6; bin 2 had no result file when I checked.

**Scratch folder to archive:** /tmp/w13_bin4 (spec.py, build.py, gate_check.py, collide.py, peek.py, show.py).
````

## 16. Review e2m names wave 13 bin 5 (773k tokens, 42 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin5.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin5.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W13 bin5 is done: 63 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin5.jsonl, address set equal to the bin, and no repo file touched (git status is clean). Checks: every `old` equals the row's current name in global_variables.csv; every new name is free in all CSVs, the .cpp and the headers, is snake_case, avoids the gate's BANNED words (plus `mil`) and keeps the `_cal` rule; none of the five other result_W13 bins uses the same new name.

**Counts:** 42 renames (verdict `confirmed`), 20 keeps, 1 drift (0x40b9a2). 0x40b55e is counted as a rename, but the bin's own record there is drift; report it under both.

**Families renamed**
- **Converter clutch rationality monitor (8C34), 8 rows:** `protection_*` become `converter_clutch_*`.
  - Rows: 0x40b57a, 0x40b57c, 0x40b581, 0x40b583, 0x40b585, 0x40b586, 0x40b588, 0x40b58a.
  - The `protection_*` / 0x408ad5 / 0x408ad6 names in bin3 already use the same prefix.
- **48RE governor pressure monitors:** `governor_pressure_rationality_fail_count` (0x40b55a), `governor_pressure_rationality_timer` (0x40b55b) and `governor_pressure_zero_check_fail_count` (0x40b55e). Same prefix as the wave-12 cals and bin3's siblings.
- **Fuel metering coil resistance estimator (8019):** `fuel_metering_command_filtered` (0x40b893), `fuel_metering_coil_resistance_filtered` (0x40b895) and `fuel_metering_coil_temperature` (0x40b897). The old `cam_speed_rate` / `engine_sync_*` names were cam-sync guesses.
- **Fuel pressure governor integral gains (8015):** `fuel_pressure_governor_integral_gain_small_signal` / `_positive_large_signal` / `_negative_large_signal` (0x4094b2, 0x4094b6, 0x4094ba). The prefix matches bin1 and bin4.
- **Charge pressure in range (1A2C / 1A2D):** `charge_pressure_in_range_fault_count_increment` (0x4051e4), `_set_threshold` (0x4051e6) and `_fault_count` (0x40a438). I avoided "boost in range" because block 1632 (BIR) is a different monitor.
- **Pressure sensor agreement tolerances (165C):** `barometric_pressure_sensor_tolerance`, `boost_pressure_sensor_tolerance` and `oil_pressure_sensor_tolerance` (0x407186, 0x407188, 0x40718a). The check is off in this calibration (`algorithm_enable_flags_6_cal` bit 0x20 clear) and all three tolerances read 0. Channel 38 behind the "oil" one has no sensor wrapper and reads 0, so oil comes from the e2m order, not from the channel.
- **Crank/cam block 8194, 7 rows:**
  - 0x408f56 `backup_consecutive_error_threshold`
  - 0x408f68 `primary_period_rpm_conversion_factor`
  - 0x408f78 `tooth_period_buffer_initial_engine_speed`. The old `crank_teeth_per_rev` was an initial speed, 120 x 0.125 = 15 rpm, and the code's ×8 supports that.
  - 0x408f84 `backup_pulse_period_timeout`
  - 0x408f8a `cam_wheel_pulse_count`
  - 0x408f9c `crank_preliminary_sync_evaluation_count`
  - 0x408fa0 `engine_speed_interrupts_per_cylinder`
  - "Backup" is the TPU-A channel 1 (cam signal) path, so I did not call it crank.
- **End-of-line test lamp override:** `end_of_line_test_malfunction_indicator_lamp_override_state` (0x40af0a) and `_flash_request_flag` (0x40af0b). The prefix is aligned with bin3 and "mil" is spelled out.
- **EEPROM-mirror `_cal` fixes:** 0x3fde48 `load_histogram_total_sample_count_cal`, 0x3feb8e `j1939_link_fault_timeout_count_cal`, 0x3fedfa `transmission_learned_information_stored_flags_byte_1_cal` and 0x3fedfb `output_speed_to_vehicle_speed_ratio_learned_flag_cal`. For 0x3fedfa, the byte's only code users are the boot kernel's SCI routines; its application meaning comes from the table's address map.
- **Single renames:**
  - 0x3fd510 `calibration_download_security_key_cal`. The 0xFF value bypasses the six seed/key checks.
  - 0x40aeb0 `low_speed_governor_alternator_load_fuel`. This is LSG Alternator_Load; the e2m LSG_EVR_Gain / LSG_EVR_Offset cals sit at its inputs.
  - 0x40af07 `warm_up_cycle_condition_flags`
  - 0x40a404 `engine_volumetric_efficiency`
  - 0x40b778 `cylinder_cutout_test_mask`
  - 0x409082 `equivalent_throttle_vacuum_all_speed_governor_offset`. The e2m's own Vac_Throttle_* records define "vac" as the vacuum throttle actuator.

**Keeps (20), listed so you can override:** 0x3fd4b2, 0x40ae6c, 0x40ae6e, 0x40afaa, 0x40b99e, 0x40a532, 0x40ba62, 0x40b886, 0x40b88c, 0x40b766, 0x40b784 and the four PCI rows 0x40b38e, 0x40b3a5, 0x40b3bc, 0x40b3bd are plain synonyms. The generic ones I left alone:
- 0x40af06 `fault_aging_triggered_flag` is Drive_Cycle, next to a renamed Warm_Up sibling. An option is `drive_cycle_completed_flag`.
- 0x40b78c `injection_quantity_scale_factor` is the speed limp home derate. An option is `speed_limp_home_fuel_derate_scale`.
- 0x408fa2 `cylinder_event_count_max` is Engine_Cylinders. An option is `engine_cylinder_count`.
- 0x40b780 `cylinder_cutout_mask` is Bank_Cutoff.
- 0x40b891 `fuel_pressure_feedback_previous` is the governor's copy of the filtered feedback.

**Drift**
- **0x40b9a2:** e2m 1632 +4 BIR_Ratio resolves here, but the code holds the coolant-sensor monitor's pass counter, next to `cssc_coolant_temp_span` and `engine_cssc_coolant_state`. Block 1632 ends after +2 in this build. I left the name; `cssc` is an invented abbreviation, so the whole family wants one rename (see leads).
- **0x40b55e:** the bin's record 8C56 +4 Gov_Press_Rat_Ratio is drift, but the table also resolves 8C58 +0 RE_Governor_Pr_Zero_Rat_Fails_This_DC to this address and the code matches that one, so I renamed from it. Say so if you would rather treat it as plain drift and keep `protection_coldStart_channelA_trip_count`.
- **Pattern:** every in-use "ratio" record I hit is the last record of its block and has no storage of its own here. BIR_Ratio, Gov_Press_Rat_Ratio and PN_Ratio (8C5B +A, which resolves to 0x40b57a, a bin5 row; I documented the TCC record there) land on another variable's address. TCC_Ratio (8C34 +16, 0x40b590) lands inside the dword `governor_pressure_error`. Gov_Press_Control_Ratio (8C58 +12) lands on the next block's first word, `park_neutral_switch_monitor_state`.
- 8C34 +12 / +14 (0x40b58c `protection_throttle_velocity_term`, 0x40b58e `governor_pressure_error`) probably drift too: the governor pressure solenoid loop uses them, not TCC / OD timers.

**Function names the evidence shows are wrong (not applied)**

| Address | Current | Proposed | Reason |
|---|---|---|---|
| 0x5341a8 | `engine_coolantTemp_overheat_monitor` | `cm848_monitorWarmUpCycle` | Sets the OBD warm-up bits: rise over 40 F and above 140 F. At 3 it counts a cycle and auto-clears the fault ring. No overheat check. |
| 0x50ddb4 | `diag_suppress_stateMachine` | `cm848_setEndOfLineTestMalfunctionIndicatorLampOverride` | It is the in-plant end-of-line test's lamp override states 0-3. |
| 0x29f54 | `cm848_checkSensorDeviationFlags` | `cm848_checkPressureSensorAgreement` | Compares barometric pressure with two other pressure readings using the three tolerances. |
| 0x1359c | `cm848_processBoostControlState` | `cm848_updateChargePressureInRangeFaultCount` | It is the up/down fault counter that sets and clears fault 527. |
| 0x12ad4 | `cm848_boostBasedFuelModifier` | `cm848_calculateVolumetricEfficiency` | It computes the clamped volumetric efficiency and the pressure-ratio terms, not a fuel modifier. |
| 0x50638c | `cm848_outputs2_periodic` | `cm848_updateLoadHistogram` | It is the duty cycle monitor histogram, every 0.1 s. |
| 0x51ba6c | `cm848_pidError_calc` | `cm848_calculateConverterClutchRatioDelta` | Previous ratio minus ratio, not a PID error. |
| 0x51ba1c | `cm848_pidIntegrator_accumulate` | `cm848_accumulateConverterClutchRatioDeltaSum` | Sums those deltas. |
| 0x457d0 | `mpc555_updateEngineCrankState` | `mpc555_handleCamSignalInterrupt` | Weaker lead: it is the TPU-A channel 1 handler, and e2m PMA_Edge_Type (channel 1) says cam signal. |

`cm848_throttleBasedFuelCalculation` (0x128a0) also reads as the charge flow / EGR fraction model, but I have no proved name.

**Sibling leads outside the bin (not in my output)**
- **8015:** the window dword 0x4094be `engine_sync_prot_scale_b_cal` holds two signed words, +205 and -204. Split it into positive and negative window widths. 0x4094ae `engine_sync_prot_scale_a_cal` holds the same values for the proportional gains.
- **LSG_EVR cals:**
  - 0x4070e0 `governor_speed_filter_input_scale_cal`, e2m 1064 +2A LSG_EVR_Gain
  - 0x4070e2 `governor_speed_filter_fuel_offset_cal`, +2C LSG_EVR_Offset
  - 0x4070e4 `governor_speed_filter_coefficient`, +2E Alternator_Load_Filter_Coefficient
  - 0x3faf56 `governor_speed_filter`, the filter state

  The first two carry a wrong `_cal` in RAM; a family like `low_speed_governor_alternator_*` fits all four.
- **1A2C / 1A2D:**
  - 0x4051e0 `fuel_demand_step_min_threshold_cal` becomes `charge_pressure_in_range_fault_clear_threshold`
  - 0x4051e2 `fuel_demand_step_decrement_cal` becomes `charge_pressure_in_range_fault_count_decrement`
  - 0x40a42e / 0x40a430 / 0x40a432 / 0x40a434 / 0x40a436 are Charge_Press / Source / State / IR_Cond / IR_Enable and are named `map_*`, `fuel_*` and `boost_*`.
- **8C33 / 8C34 leftovers:** 0x408ad2, 0x408ad3, 0x408ade, 0x40b57d, 0x40b57f, 0x40b58b and the monitor's snapshot words still read `protection_*`. In the same order they are fail count limit, minimum ratio delta sum, overdrive rationality time, ratio delta, monitor state, third lockup flag.
- **`cssc_*` family:** 0x40b9a2, 0x40b9a4, 0x40b9a6, 0x3fd18a-0x3fd190 should become `coolant_temperature_sensor_performance_*`. The drifted row would be `coolant_temperature_sensor_performance_monitoring_cycle_count`.
- **165C / 177D:** 0x40718c `cold_start_sensor_deviation_delay_cal` has a wrong `_cal`, and `iat_sensor_deviation_flags` (0x3fe9be) says iat for pressure flags. `governor_integrator_bound_a` / `_b` (0x40bb8a / 0x40bb3c) are sensor channels 77 and 38. 0x400940 / 0x400942 `fuel_demand_rpm_factor_upper_cal` / `_base_cal` are the volumetric efficiency clamps (1.0 / 0.8) with a wrong `_cal` in RAM.
- **8194 backup/primary pairs:** 0x408f80 `crank_sync_period_confirm_count_cal` (Main_Consec_Error_Thres), 0x408f82 `crank_period_raw` (Maximum_Pulse_Period_Timeout) and 0x408f6c `crank_tooth_rpm_divisor_cal` (the backup speed constant) should pair with my primary/backup names.
- **Cross-bin mismatch:** bin6 renamed 0x40b798 to `crank_tooth_period_countdown`, the reload target of my `backup_pulse_period_timeout` and part of the same channel 1 backup path. `backup_pulse_period_countdown` would pair better; please reconcile.
- **11C1:** 0x3feb8c `etc1_state_timeout_counter` is e2m J1708_Link_Fault_Timeout_Count, and 0x3feb90 `etc1_fuel_demand_high_limit` is TSC_Lost_Max_Throttle_Disable. Both sit in the EEPROM mirror without `_cal`; 0x3feb8c would become `j1708_link_fault_timeout_count_cal`.

**Type remarks (types unchanged)**
- 0x40aeb0, 0x40b897 and 0x40b583 are signed with `lha` accesses, so `i16` would fit.
- The `word` row at 0x408f56 swallows the byte at 0x408f57, e2m +1 Bank_With_Added_Tooth, which already has a typeless label `crank_sync_reference_flag_cal`. It should be a byte row plus a byte row at 0x408f57. Until then the `(byte)` reads of the second byte render under my new name.
````

## 17. Review e2m names wave 13 bin 6 (739k tokens, 42 min)

### Prompt (exact text)

````text
You are one of six parallel agents in CM848 rename wave 13 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/brief_W13.md

Your bin: /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin6.json
Write your results (one JSON object per line, one line per record in your bin) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl

Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
Wave 13, bin 6 is done: 63 verdicts in `/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl`, one line per bin record, in bin order. Nothing else was edited, built or committed. The repo gate script was blocked by the permission classifier, so I ran a read-only re-implementation of its name rules on the file: BANNED words, `_cal` by region, hex-looking parts, format, old name equals the CSV row. It reports 0 problems. Checks against global_variables.csv, the .cpp and bins 1-5 found no collision. None of my old names is shared with CM550, so none would be held back.

## Counts
- 42 rename (`confirmed`), 20 keep, 1 drift, 0 uncertain.

## Families renamed
- **alpha** (e2m 104A): the `cold_start_*` words, `intake_temp_ema`, `governor_init_countdown` and `fuel_demand_ramp_factor` become `alpha_*`. `timingProtectionFlagsOrchestrator` is the alpha ramp. 6 rows.
- **all-speed governor** (107C): the `fuel_demand_*` / `governor_*` words become `all_speed_governor_*` (6 rows) and `rpm_deceleration_limit_integral_term`. The e2m reset-state block 1170 fixes the state meanings: X1 is the speed error, X6 the fuel correction.
- **data collector**: `diag_dm1_buffer_read_ptr` becomes `data_collector_start_address`, matching bins 1-3, which name the center, end and status words.
- **J1939 control session**: `etc1_*` / `governor_*calib*` become `j1939_*_cal` (3 rows). All three lacked `_cal` in the EEPROM mirror.
- **compressor map** (175F, 3 rows) and **ambient / compressor inlet** (1921, 4 rows): the `fuel_timing_*` and `boost_fuel_*` names become `compressor_*` / `ambient_*`. `ambient_air_temperature_reference` parallels `barometric_pressure_reference`. 1921 +14 is relative humidity, since the code multiplies saturation vapor pressure by it >> 10.
- **exhaust temperature model** (17A1, 2 rows): `boost_target_*` becomes `exhaust_temperature_model_*`.
- **HPCR fuel metering** (8000, 3 rows): `engine_sync_*_cal` becomes `fuel_metering_feedback_trim_{maximum,minimum}_scaling_factor` and `fuel_pressure_sensor_filter_coefficient`. The old `_cal` was wrong for this RAM region.
- **crank** (819B, 7 rows):
  - `engine_sync_startup_countdown` becomes `crank_tooth_period_countdown`. `mpc555_updateEngineCrankState` reloads it on every tooth capture.
  - `crank_sync_valid_flag` becomes `crank_low_speed_filtering_flag`.
  - `crank_mios_timing_output` becomes `crank_tooth_good_window_fraction`. It programs TPU-A channel 1, not MIOS.
  - `engine_event_countdown` becomes `crank_preliminary_sync_count`. I flipped this one from keep because bin 5 renames its `_cal` twin to `crank_preliminary_sync_evaluation_count`.
  - `timebase_previous_capture` becomes `first_speed_interrupt_time_ticks`, and `timebase_delta_ticks` becomes `crank_resync_time_ticks`.
  - `cam_sync_position_min` becomes `fuel_pressure_start_undershoot`. It is the lowest rail pressure reading during the start.
- **Singles**:
  - `pumping_torque_adjustment` (was `fuel_demand_blend_adjusted`)
  - `cylinder_residual_gas_mass_lower_limit`
  - `fuel_temperature_derate_fueling_severity_index_cal` (the first word of the single fault-derate channel record)
  - `water_in_fuel_distance_cal` (the name only gains `_cal`)
  - `cruise_coast_accelerate_hold_time` (was camelCase `cruiseOverride`)
  - `intake_air_heater_monitor_result` (see the judgment call below)

## Drift
- **0x40b9ee** (`misfire_monitor_cylinder_attempt_counts`), e2m 162B +A IAH_Function_Timer. It resolves to the same address as e2m 1651 +0 Misfire_Cyl_1_Attempt_Number, which the code matches. The IAH words end at +8, so 162B +A and +C (IAH_Ratio at 0x40b9f0) have no counterpart. I kept the name.
- **Block 1930 +12**: AATR_Numerator resolves to 0x3feeb8, but the code matches 191A WIF_Miles, not that record.
- **8C5B +A** (not in my bin): PN_Ratio resolves to 0x40b57a. That is `protection_output_hold_flag` in `cm848_monitorConverterClutchAndOverdrivePerformance`.
- **1B2E +A / +C** (not in my bin, unverified): they land on the `wastegate_monitor_fail_high_boost_pressure_axis` word[5] table and an unnamed word.

## Functions whose names the evidence shows are wrong (not auto-applied)

| Address | Current name | Proposed name | Reason |
|---|---|---|---|
| 0xe518 | `hpcr_calculateFuelTrimOutput` | `cm848_calculateAlpha` | selects the alpha source and outputs `combustion_alpha_input` |
| 0xe3a4 | `timingProtectionFlagsOrchestrator` | `cm848_calculateAlphaBase` | the alpha ramp |
| 0xe164 | `cm848_calculateSensorEma` | `cm848_calculateAlphaFuelRate` | fuel rate hysteresis on `fuel_mass_flow_raw` |
| 0xe218 | `cm848_checkFuelRateCondition` | `cm848_calculateAlphaGovernor` | on-governor condition |
| 0xe248 | `cm848_checkPressureFuelDelayA` | `cm848_calculateAlphaLowSpeedGovernor` | low speed governor alpha latch |
| 0xe2cc | `cm848_checkPressureFuelDelayB` | `cm848_calculateAlphaAirFuelControl` | air fuel control alpha latch |
| 0xe360 | `cm848_checkPressureHysteresis` | `cm848_calculateAlphaLowAmbientAirPressure` | barometric hysteresis of alpha |
| 0xe0f4 | `cm848_checkPressureFuelState` | `cm848_calculateAlphaAltitudeDerateLatch` | altitude derate alpha timer |
| 0xe748 | `cm848_initFuelPressureVariables` | `cm848_initializeAlpha` | clears the alpha latches, timers and filter |
| 0x505c20 | `diag_dm1Buffer_circularFill` | `cm848_fillDataCollectorBuffer` | data collector, not DM1 |
| 0x505d94 | `hpcr_exception_process` | `cm848_initializeDataCollector` | sets the collector pointers |
| 0x505df0 | `j1939_dm1_diagnosticMessage_send` | `cm848_sendDataCollectorBuffer` | sends the collector ring over the transport protocol |
| 0x505f98 | `cm848_phase_groupB_calculation` | `cm848_runDataCollector` | uses `data_collector_schedule_cal`, trigger line and count |
| 0x50beec | `governor_sourceData_init` | `cm848_startJ1939ControlSession` | opens an engine or retarder control session |
| 0x50bff4 | `phase_group_a_setupETC1Controller` | `cm848_trackJ1939ControlSessions` | opens, closes and files control sessions |
| 0x50be6c | `governor_calibSnapshot_rollingBuffer_update` | `cm848_storeJ1939ControlSessionInHistoryTable` | 5 x 24-byte history ring |
| 0x255c0 | `cm848_j1939SendDm1ResponseMessage` | `cm848_j1939SendDm8TestResultMessage` | sends PGN 65232 with test id and value |
| 0x130dc | `cm848_calculateBoostPressureOffset` | `cm848_calculatePumpingTorque` | e2m 1781 CHP pumping torque |
| 0x502b6c | `hpcr_fuelFinal_exponentialAverage` | `cm848_calculateAmbientConditions` | e2m 1921 ambient and compressor inlet conditions |
| 0x506e28 | `cm848_auxiliaryControl_exponentialAverage` | `cm848_calculateExhaustTemperatureEstimate` | exhaust virtual temperature and metal temperature |
| 0x50e7f4 | `cm848_blendBoostAndThrottleFuelDemand` | `cm848_calculateWaterVaporFractions` | humidity, vapor pressure and dew point model |
| 0x49004 | `cm848_resetEngineSyncState` | `cm848_resetFuelPressureGovernorState` | its own plate comment says it resets the fuel pressure governor |

## Out-of-bin twins left half-renamed
- **0x4062d2** `boost_pressure_ratio_upper_limit` should be `cylinder_residual_gas_mass_upper_limit` (e2m C_CBP_Residual_Mass_Max).
- **Alpha siblings:** all are alpha results or timers, none is a pressure or fuel-rate flag.
  - 0x40a16c `governor_startup_state` → `alpha_state`
  - 0x40a16e `pressure_fuel_delay_b_status` → `alpha_air_fuel_control_result`
  - 0x40a172 `fuel_rate_condition_status` → `alpha_governor_result` (it is the On Governor result and now reads confusingly next to `alpha_fuel_rate_result`)
  - 0x40a174 `pressure_fuel_delay_a_status` → `alpha_low_speed_governor_result`
  - 0x40a17a `pressure_hysteresis_state` → `alpha_low_ambient_air_pressure_result`
  - 0x40a17e / 0x40a180 `cold_start_timer_a` / `cold_start_timer_b`, 0x3fa0da / 0x3fa0dc `cold_start_timer_*_active_flag`
  - 0x3fa0d2 `cold_start_intake_temperature_filter_state`, 0x5be66 `cold_start_intake_temperature_filter_coefficient`
- **107C siblings** to take `all_speed_governor_*`: 0x40a1aa, 0x40a1b2, 0x40a1b8, 0x40a1ba, 0x40a1bc, 0x40a1c4, 0x40a1cc, 0x40a1d4, and 0x40a208 `fuel_demand_integrator_b_sum` (e2m Decel_Limit_Fuel).
- **Compressor map:**
  - 0x40a60e `boost_pressure_normalized` → `compressor_map_corrected_air_flow`
  - 0x40a612 `fuel_timing_boost_scale_lookup` → compressor map output ratio
  - 0x40a618 `fuel_timing_state_code` → `compressor_outlet_temperature_source`
- **Other siblings:**
  - 0x40a418 and 0x40a41c (CHP nominal delta-P and pumping torque without offset)
  - 0x40a682 `boost_target_load_rpm_output` → `exhaust_temperature_model_energy_fraction`
  - 1921 sources and pressure drop: 0x40a198 / 0x40a19c / 0x40a1a0 / 0x40a1a2 / `DAT_0040a1a6`
  - the remaining `diag_dm1_buffer_*` physical start and end pointers (0x40c270 / 0x40c274), fill and slot words, and `diag_dm1_fault_source_table`
  - `crank_tbl_event_counter` (Crank_Resync_Count)
  - 0x3fcd92 `governor_cruiseOverride_holdoff_countdown`
  - the rest of block 8000 (0x409110-0x409138): `engine_sync_*_cal`, `cam_sync_*_cal` and `engine_speed_override_*_cal` are HPCR governor settings and carry a wrong `_cal` in that RAM region

## Notes for the apply
- **Types (not changed).**
  - Signed in the e2m and loaded with `lha` or cast to short: 0x40a1ac, 0x40a1ae, 0x40a1b6, 0x40a1be, 0x40a41a, 0x40a19a, 0x40911a, 0x40911c. The rows are `word`, so `i16` would fit.
  - 0x40b808 is compared as short, and its e2m record is signed.
  - 0x40a204 (`fuel_demand_integrator_b`) is a dword over the I term and the P term. After the rename the P term would render as `rpm_deceleration_limit_integral_term._2_2_`, and the `fuel_demand_integrator_b+2` sub-row goes stale. Split the row: word at 0x40a204, word at 0x40a206 (e2m +5C).
- **Old comments that are wrong** (candidates for `WRONG_OLD_COMMENTS`): 0x3feb82, 0x3feb84, 0x3feb8a, 0x3fdfbe ("2x30B array"; there is one 30-byte channel record), 0x40a67e, 0x40a684, 0x40a1a4, 0x40a1a8, 0x408720.
- **[44] finding.** e2m 801D +0 says `fuel_metering_feedback_input` is the pressure regulator valve current (mA, 1.2218 per count). The repo notes still call that signal unidentified. I kept the name and put this in the note.
- **Judgment calls.**
  - 0x40ad82: the intake air heater attribution comes from the e2m name and the DM7 test order (test 0 = this word, test 1 = `misfire_monitor_result`). The word has no store anywhere in ROM or flash2.
  - `pumping_torque_adjustment` follows the brief's "Adj = adjustment" and fits net = gross minus it.
- **`e2m_variables.csv` coincidence.** `alpha_altitude_derate_timer` and `ambient_relative_humidity` also appear in `output/e2m_variables.csv`, a reference list of mechanical e2m names at e2m virtual addresses that no build step reads. They pass the brief's check against global_variables.csv and the .cpp, but a stricter grep over `output/*.csv` would flag them.

Scratch scripts are in `/tmp/w13b6`.
````

# Stage 9 agents: rename wave 14, the function misnames and the sibling rows (2026-11-19, PR #52)

Seven read-only `general-purpose` agents (model sonnet), started in parallel: three function bins (83 functions
by family) and four global bins (253 rows by e2m block). Each wrote one JSONL result file and nothing else.
4.78M tokens in all.

The main session built the worklists:
- the functions are the renames the wave-12 / wave-13 reports proposed (`stage9/extract_function_leads.py`,
  plus 9 by hand);
- the globals are the low-overlap rows of the blocks wave 13 renamed into, the wrong-`_cal` rows, and every row a
  report named. `expand_worklist.py` added the report ranges and family stems;
- `build_context_W14.py` precomputed the CM550 shared-name check, the owner's review notes, and each row's width
  against its records.

Before dispatch, an advisor review changed the plan: full plates, ranges, bins by family, the width check, and a
`code_quote` the gate checks.

`stage9/apply_W14.py` then:
- checked every line, the quotes and the name formats, and ran the repo gate;
- held 17 items: 5 CM550-shared functions, 3 functions with the owner's review notes, 7 width / struct items and
  2 enum rows;
- applied 75 function renames and 231 global renames.

The hand scripts applied the splits, the collector table array and the three enums.

## The shared brief (exact text)

````text
# Rename wave 14 (CM848): the function misnames and the sibling rows left by wave 13

This is read-only research with ONE output file. Do not edit any repository file, run `analyze.sh`, or commit.
Write your results only to the result file named in your prompt.

## Background
- **Waves 12 and 13** renamed about 600 globals from the CM848's own e2m record -> address table
  (`cm848_lookupParameterIdAddress`: 6-byte records [e2m block id][address] in flash2). For example:
  - the data collector (`data_collector_*`, was `diag_dm1_*`);
  - the PGN 65251 torque curve words;
  - alpha, the all-speed governor, the 48RE converter clutch / governor pressure monitors, cylinder balance;
  - the HPCR gain records (`fuel_pressure_governor_*_gains`, structs).
- **The leads.** The wave-13 agents also found functions whose names are wrong, and sibling rows they could not
  rename. Your bin holds those leads. A lead is a hint, not a fact: verify it in the code.
- **The labelled e2m is calibration 11.45; the truck runs 11.46.06.** A record can sit at a shifted offset (drift),
  and then the code use contradicts the record. Known drift: 10E3 tail / 1228, 8A2B / 8A37, 8A14 (+2C on), 1930 (+12
  on), 1902 (+2A..+2E), 1253, 8D14 (+2 on), 1B2D (+4 on), 1966 (+94 on), 1649 (+10 on). The 8C58 tail overlaps 8C4E.
- **Read the current comment or plate before you judge.** Many hold proved facts from earlier work.

## Files
- Decompiled code: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
- The CSVs next to it:
  - global_variables.csv: address,name,type,comment;
  - function_renames.csv: address,name,plate;
  - enums.csv;
  - structure_definitions.csv.
- CM550 (the other firmware): /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM550_J90350.00_analysis/output/function_renames.csv
  and /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/cross_firmware_matches.csv
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines` prints a function;
  - .../width_census.py `<all.dis> 0xADDR` gives the access widths; all.dis is in the same folder;
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/e2m_block_addresses.py
    `BLOCK` or `--address 0xADDR` gives the table-resolved e2m records;
  - the six wave-13 reports (the leads come from them):
    /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/reports/*.md
  - what waves 13 / 8c renamed (`address,name,old_label,kind`); families span blocks, so check these:
    /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/map_stage8.csv and .../stage8/map_stage8c.csv

## Naming rules (all items)
- **Spell words out.** No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox,
  id, adc, pwm, can, pid, tpu, qadc, vin, tsc1. In camelCase they are written Rpm, J1939, Pgn, Egr, Tpu, ...
- **Always** use initialize (never init) and calculate (never calc). Never use a bare "protection": say protection of
  what. Numbers are decimal (PGN 65251, not 0xFEE3).
- **`_cal` (globals)** is decided by the region alone. In the EEPROM mirror 0x3fd482-0x3feec1 the name ends `_cal`;
  everywhere else it never does.
- **Uniqueness.** A new name must not exist yet: grep the CSVs and the .cpp. No two items may get one name.
- **Families.** Rename a family consistently, and follow the names wave 13 gave its siblings (`block_named_rows` lists
  them).

## Function items (bins functions1-3)
Each item has:
- `current`, `current_plate`, `callers`, `callees`, `body_lines`;
- `proposals`: names the wave-13 agents suggested, each with its reason and source report. Some items have none.
- `shared_with_cm550` (precomputed): the current name also appears in CM550's CSVs or the cross-firmware map. Judge the
  function as usual; the main session holds shared renames.
- `user_review_note` (on three items): the owner's own signed review of the current name. Copy it verbatim at the end
  of your plate. The main session shows any rename of these to the owner and does not apply it on its own.
A proposal is a hint. Most items come with one, so the temptation is to confirm it. Decide from the code; a better
name or a keep is a fine answer.

Steps:
1. Read the function (`fnbody.py`), its callers where needed, and the globals it reads and writes.
2. Decide:
   - **rename:** the current name is wrong or misleading, and you can say what the function does from the code.
     - The proposal may be right, or you may improve it.
     - Keep the module prefix: `cm848_` for CM848 code; `hpcr_` / `mpc555_` only when the current name already has it
       and it still fits. A legacy unprefixed or mixed name (`faultTimerHandler`, `governor_sourceData_init`) becomes
       `cm848_<camelCase>`.
     - Use the form `<prefix>_<verbObject>` in camelCase (`cm848_calculateFuelMeteringCommand`).
   - **keep:** the current name is accurate.
   - **uncertain:** you cannot tell.
3. Quote the deciding code: `code_quote` is one exact line (or a fragment of 20+ characters) of the function's body
   that shows what it does. The gate checks that the quote is in that function.
4. For a rename, also write a new `plate_comment` (the function's plate comment):
   - say what the function does, its inputs and outputs, and the e2m records it uses;
   - **keep every proved fact of `current_plate`**, rewriting only what your evidence shows is wrong;
   - do not add "(was ...)": the apply adds it.

## Global items (bins globals1-4)
These rows sit next to families that waves 13 / 8c renamed. Each item has:
- the current name / type / comment and the region;
- the access widths, up to 6 code lines, and `e2m_records_here` (the table-resolved records at this address);
- `block_named_rows`, and `report_leads` (what a wave-13 agent wrote about the row).

Decide:
- **keep:** the current name is accurate, or more specific than the record.
- **rename:**
  - the name is wrong or misleading, and the record or the code shows the right meaning; or
  - it breaks a rule: an invented abbreviation, or a wrong or missing `_cal`. Many rows here are only `_cal` fixes.
- **drift:** the record does not match the code. Leave the name and say what the code shows.
- **uncertain:** you cannot tell.

Some rows have no e2m record here (`e2m_records_here` is empty). Name them from the code and the report lead, or say
uncertain.

**Width.** `covered_records` lists the e2m records inside the row. When `width_problem` is set, the row is a scalar
wider than its record, so one name covers several records. For example, a word over two 1-byte records renders the
second record as `(byte)name`. Then add `"split": [{"address": "0x...", "name": "...", "type": "byte|word|dword",
"comment": "..."}]`, one entry per covered record that the code uses. The main session applies splits by hand and
holds the plain rename.

## Checks (every rename)
- **Direction words** (minimum / maximum, upper / lower, positive / negative, enable / disable, high / low): confirm
  each against the deciding compare or use in the code, and quote it in the evidence.
- **Width:** if the row width differs from the e2m record size, or the code reads only part of the row, say so in
  `type_note`. Do not change types yourself; a `type_note` rename is held for the main session.
- **Quotes:** every global rename also carries a `code_quote`: one exact code line that uses the row and decides its
  meaning.
- **PGNs and P-codes:** a PGN, SPN or P-code in a new name must cite where you read it in the evidence. For example:
  the transmit header constant, or fault N -> ROM slot table 0x5985a -> obd_dtc_code_table.
- **Dump values:** quote dump values exactly as `dump_raw` gives them (raw, at the row's width). Write a scaled value
  as "N in the dump = X unit".
- **Old comments:** the apply keeps the old comment as an "earlier note". If your evidence shows that the old comment
  is wrong, set `"old_comment_wrong": true` and carry over its proved facts yourself.

## Output: one JSON object per line, one line per item of your bin (in bin order)
- **function rename:** `{"kind": "function", "verdict": "confirmed", "address": "0x...", "old": "<current>", "new":
  "...", "evidence": "...", "code_quote": "...", "plate_comment": "..."}`
- **function keep:** `{"kind": "function", "verdict": "keep", "address": "0x...", "old": "<current>", "new":
  "<same>", "evidence": "..."}`. A keep may carry a corrected `"plate_comment"`, which the apply writes.
- **function uncertain:** `{"kind": "function", "verdict": "uncertain", "address": "0x...", "old": "<current>",
  "evidence": "..."}`
- **global rename:** `{"kind": "global", "verdict": "confirmed", "address": "0x...", "old": "<current>", "new": "...",
  "evidence": "...", "code_quote": "...", "comment": "<full new CSV comment: the e2m record and its description, then
  the role in the code>"}`. Optional fields: `"type_note"`, `"split"` and `"old_comment_wrong": true`.
- **global keep:** `{"kind": "global", "verdict": "keep", "address": "0x...", "old": "<current>", "new": "<same>",
  "e2m_note": "e2m <block> +<offset> <record> '<short description>'"}`. Leave `e2m_note` empty when no record is here.
- **global drift / uncertain:** `{"kind": "global", "verdict": "drift" or "uncertain", "address": "0x...", "old":
  "<current>", "evidence": "..."}`
- The `evidence` field is one line of code facts: functions, compares, which records.

## The held enum rows (bin functions3 only: `held_enum_rows`)
Wave 13 found these two enum-typed rows misread:
- 0x40c04a `diagnostic_session_state` is the RAM refresh enable;
- 0x40aa9a `j1939_standby_flag` is the development mode.

Their enums (`DIAG_SESSION_STATE` / `J1939_STANDBY_STATE` in enums.csv) still follow the old reading. Re-read the code,
together with your bin's cm848_activateDiagnosticSession / cm848_resetDiagnosticSession /
cm848_forceActivateDiagnosticSession / cm848_initProtectionModule / uds_session_state_init. For each row, add one line:

`{"kind": "enum", "verdict": "confirmed" or "uncertain", "address": "0x...", "old": "<row name>", "new": "<row name>",
"enum_old": "...", "enum_new": "...", "members": [{"value": N, "old": "...", "new": "...", "comment": "..."}],
"comment": "<new row comment>", "evidence": "..."}`

Name the members after what each value does in the code. Keep the enum when it is still the right shape. A plain flag
may need no enum at all; then say so in the evidence.

## Finish with a short summary in your final message
- counts per verdict;
- the families you renamed;
- drift found;
- shared-name holds;
- any new leads outside your bin (address, current name, what the code shows).
````

## 18. Wave 14 functions bin 1 (603k tokens, 31 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (function items): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions1.json
It holds the alpha functions, the EGR / charge flow / intake manifold temperature models and the fueling, throttle and air models. Judge each family consistently.
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions1.jsonl

If you need scratch files, put them only under /tmp/w14_functions1/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 functions1: result file written, 31 lines in bin order.
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions1.jsonl

CHECKS
- The repo gate `apply_renames.py` dry run (no --apply) passes: 31 functions, 0 problems.
- Every `code_quote` is an exact substring of one physical line of that function's body in the current .cpp.
- All 31 new names are distinct and absent from all CSVs, the .cpp and the .hpp. They are also distinct from the result files present at the time (functions3, globals1, globals2); re-run the collision check once all bins are in.
- The repo worktree is clean (git status 0 lines).
- Plates cite other symbols by their CURRENT names, so the reference refresh keeps them right if a rename is held.

COUNTS
- 31 confirmed renames, 0 keep, 0 uncertain, 0 drift (drift applies to globals; none in this bin).
- None of the 31 current names was accurate. Several were swapped or wrong-domain:
  - 0xe164 `calculateSensorEma` is the alpha fuel rate result, and 0xe218 `checkFuelRateCondition` is the on-governor condition.
  - `cm848_calculateBoostPressureOffset` is the pumping torque.
  - `cm848_calculatePressureSensorFiltered` is the intake manifold temperature.

FAMILIES RENAMED
- **Alpha (e2m 104A / 104B), 9 functions.**
  - The five condition functions all take the shape `cm848_calculateAlpha<Condition>Result`, mirroring the `alpha_*_result` words:
    - 0xe164 `...AlphaFuelRateResult`
    - 0xe218 `...AlphaOnGovernorResult`
    - 0xe248 `...AlphaLowSpeedGovernorResult`
    - 0xe2cc `...AlphaAirFuelControlResult`
    - 0xe360 `...AlphaLowAmbientAirPressureResult`
  - 0xe0f4 `...AlphaAltitudeDerateLatch`, 0xe3a4 `...AlphaBase` (the ramp), 0xe518 `cm848_calculateAlpha` (the source selector; read from the disassembly because the decompile garbles it), 0xe748 `cm848_initializeAlpha`.
- **EGR mass flow models (e2m 177E / 177F), 3 functions.**
  - 0x1242c `cm848_calculateDownstreamEgrMassFlow` and 0x125f4 `cm848_calculateUpstreamEgrMassFlow`.
  - 0x127bc `cm848_calculateEgrMassFlowBeforeDelay` (e2m CHP_EGR_Flow_Before_Delay; it selects the model, clamps and zeroes on a closed valve).
  - Direction is proven by the `rpm_fuel_trim_select_cal == 0` branch plus e2m 177E +A (0 = upstream).
  - That selector is separate from 177E +8 (hot / cold side), which 0x17f50 and 0x507028 use.
- **Charge model (e2m 177C / 177D / 191B / 1781 / 1A2C / 1A2D), 4 functions.**
  - 0x12ad4 `cm848_calculateVolumetricEfficiency`, 0x12cf4 `cm848_calculateChargeMassFlow`.
  - 0x130dc `cm848_calculatePumpingTorqueAdjustment`.
  - 0x1359c `cm848_updateChargePressureInRangeFaultCount`. Fault 527 has no P-code (slot 170); none is claimed.
- **Intake manifold and EGR orifice temperature chains (twins, e2m 18D9 / 19CA), 5 functions.**
  - Lead compensation: 0x13d14 `cm848_calculateIntakeManifoldTemperatureLeadCompensation` and 0x506f88 `cm848_calculateEgrOrificeTemperatureLeadCompensation`.
  - 0x13dc8 `cm848_filterAndSelectIntakeManifoldTemperature`: it filters and also picks primary / backup / default. For the orifice this is split into 0x507028 `cm848_filterEgrOrificeTemperature` and 0x50716c `cm848_selectEgrOrificeTemperature`.
  - Channel 9 is the intake manifold temperature; channel 108 is the EGR orifice temperature.
- **0x17f50** `cm848_calculateEgrDeltaPressures` (e2m 1A19).
- **Pedal and fueling, 4 functions.**
  - 0x173a8 `cm848_learnAcceleratorPedalAutozero`.
  - 0x1e830 `cm848_updateFourDimensionalFueling`.
  - 0x1eae8 `cm848_filterCommandedThrottle`.
  - 0x1f17c `cm848_calculateThrottle100Fuelings` (it stores all five e2m 105A values, not one).
- **No load fuel and torques, 2 functions.** 0x50dba8 `cm848_calculateNoLoadFuel`; 0x50eaa8 `cm848_calculateFrictionNoLoadAndNetMachineTorque` (all six e2m 175C words).
- **Ambient, exhaust, water vapor, 3 functions.**
  - 0x502b6c `cm848_calculateAmbientAndCompressorInletConditions` (all of e2m 1921).
  - 0x506e28 `cm848_estimateExhaustTemperature` (verb follows `cm848_estimateCompressorOutletTemperature`).
  - 0x50e7f4 `cm848_calculateWaterVaporAndSaturationTemperatures` (it also computes the partial pressures and dew points).

SHARED-NAME HOLDS
- 0xe3a4: CM550 0xc582 has the same name and is the same alpha ramp. Hold for both firmwares.
- 0xe518: the cross_firmware_matches.csv row to CM550 0x1abb2 (review) is a FALSE match. `cm550_FUN_0001abb2` is an ESP / throttle fueling function. The real CM550 twin is `vp44RpmBasedFaultDetector` @ 0xc326, which writes `_APAPST` / `_APAPBA` and calls the alpha ramp. Hold.
- 0xe164: its map row to CM550 0xc404 (`calculateSensorEma`) is a TRUE twin that the precomputed `shared_with_cm550` flag missed. Hold.
- False bare-name map rows, so no hold needed:
  - 0x12cf4 -> CM550 0x1a8a4 (`vp44_FUN_0001a8a4`, a VP44 ISR routine)
  - 0x1359c -> CM550 0x1645e (`cm550_safeDivideWithClamp`)
  - 0x1f17c -> CM550 0x13cc8 (`cm550_FUN_00013cc8`, a buffer reset)
  - These three rows should leave the map.
- CM550 helper twins (rename leads for CM550): 0xc496 (on governor), 0xc4b2 (low speed governor), 0xc504 `cm550_fuelModeTransitionCountdownHandler` (air fuel control), 0xc556 (low ambient pressure), plus 0xc404 (fuel rate).

FOR THE MAIN SESSION
- Global-side reconcile: my 0xe218 name uses "OnGovernor", while the wave-13 lead for 0x40a172 was `alpha_governor_result`. Pick one. I suggest `alpha_on_governor_result`; the other four result words (0x40a16e, 0x40a170, 0x40a174, 0x40a17a) should mirror the same shape.
- Stale prototypes: function_definitions.csv declares two parameters each for 0x12ad4 (boost_denominator, base_fueling) and 0x130dc (manifold_pressure, rpm). The disassembly overwrites r3 and r4 before any read, so both functions take no arguments. The plates say so.
- Callers: the bin's `callers` list is name-grep, so it includes plate-comment mentions.
  - 0x50eaa8: the real caller is only `cm848_periodicTaskSet_sensorProcessing`.
  - 0x506e28: the real caller is only `cm848_periodicTaskSet_auxiliaryControl`.
  - 0x1f17c: the real caller is only `cm848_periodicTaskSet_controlLoop`.
- e2m text note: 18D9 +0 TPE_IMT_After_Lead says "before limits", but the code clamps to C_TPE_Min_IMT / Max_IMT inside 0x13d14.

NEW LEADS OUTSIDE MY BIN (proposed names are untested ideas, not gate-checked)
- 0x12724 `cm848_checkFuelSystemFaultFlags`: e2m 177F +18 EGR_Flow_Source for the downstream model. It is 0 only when the valve position, orifice delta pressure, charge pressure and orifice temperature sources are all 0. Idea: `cm848_calculateDownstreamEgrMassFlowSource`.
- 0x12778 `cm848_checkEngineFaultConditions`: the same for the upstream model (valve position, Exhaust_Press_Source = `fuel_demand_droop_state` 0x40a7d2, `exhaust_temperature_source`). Idea: `cm848_calculateUpstreamEgrMassFlowSource`.
- 0x128a0 `cm848_throttleBasedFuelCalculation`: delays and filters the EGR flow (final_trim, delay = load_adjusted) into `egr_mass_flow_delayed_filtered`, and divides by `charge_mass_flow_filtered` into `egr_fraction_actual`. It also does the O2 delay. Idea: `cm848_calculateEgrFractionAndFlowDelay`.
- 0x12dc4 `cm848_fuelDemandWithLoadCompensation`: stores `load_input` = intake manifold temperature + 0x7300 (degrees Rankine, e2m 177D +2), calls the efficiency and charge flow functions, and sets Charge_Flow_Source. Idea: `cm848_calculateChargeMassFlowModel`.
- 0x13564 `cm848_checkBoostControlCondition`: Charge_Press_IR_Enable (1A2D +8) = 1 when `map_sensor_fault_status` and `boost_fuel_weight_snapshot` are 0. Idea: `cm848_calculateChargePressureInRangeEnable`.
- 0x13774 `cm848_processBoostProtectionConditions`: the in-range monitor. Charge_Press_IR_Cond = |`boost_pressure_target` - `boost_pressure_sensor_value` - `boost_fuel_threshold_offset`| > `boost_fuel_threshold_limit`. Idea: `cm848_updateChargePressureInRangeMonitor`.
- 0x1ec70 `cm848_calculateDualAxisFuelLimit`: computes Four_D_Fueling (e2m 1053 +0), an alpha blend of two engine speed x throttle grids. The repo says "dual axis" (enum member and function name) while the e2m and wave 13 say "four dimensional". Reconcile the vocabulary.
- 0x5071b8 `cm848_phase_groupB_calculation_2`: the wrapper that filters then selects the EGR orifice temperature. Idea: `cm848_calculateEgrOrificeTemperature`.
- Globals, as likely already covered by the globals bins:
  - 0x405208 `pressure_sensor_lower_limit_cal` and 0x40520a `injection_timing_offset_floor_cal` are e2m 18D6 +2 / +4 C_TPE_Min_IMT / C_TPE_Max_IMT. The second is the maximum, so "floor" reads backwards, and `_cal` is wrong outside the EEPROM mirror.
  - `boost_pressure_state_t.load_input` (0x40a406) is the intake manifold temperature in degrees Rankine (e2m 177D +2).
  - 0x40aeec `fuel_demand_base_offset` is e2m 109C +0 No_Load_Fuel.
  - 0x40a456 `injection_enable_mode_byte` is e2m 1A1B +4 Charge_Tmptr_EStat; 0x40a452 `fuel_demand_boost_offset_filtered` is 1A1B +0 Charge_Tmptr_Est.
  - 0x40a60a `fuel_demand_state_b` is e2m 1A0C +2 Compressor_Inlet_Tmptr_Source.
  - The `throttle_fuel_trim_t` fields are the e2m 177F EGR flow words: `rpm_based_trim` = CHP_Upstream_EGR_Flow, `load_based_trim` = CHP_Downstream_EGR_Flow, `final_trim` = CHP_EGR_Flow_Before_Delay; `engine_fuel_fault_status` (0x40a402) = EGR_Flow_Source.

Scratch folder to archive: /tmp/w14_functions1 (`build.py` generates and validates the result file; plus lookup helpers).
````

## 19. Wave 14 functions bin 2 (642k tokens, 38 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (function items): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions2.json
It holds the J1939 torque curve / PGN 65251 / EEC1 / DM8 / TSC1-lost functions, the J1939 control session history, the data collector, the engine protection shutdown and a number-to-text helper. Judge each family consistently.
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions2.jsonl

If you need scratch files, put them only under /tmp/w14_functions2/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 functions2 is finished. All 28 items are in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions2.jsonl, in bin order. No repo file was touched and `git status` is clean. Scratch is in /tmp/w14_functions2/ (the generator `make_results.py`, `validate.py`, `check_refs.py`, `cross_check.py`).

Validation: every address and old name equals the bin. Every new name passes the gate regex and BANNED set, is unique, and is absent from every CSV, the .cpp, the .hpp files, CM550's CSVs and the other W14 result files (all seven were present at the final run). Every code_quote sits inside one physical line of its function.

**Counts:** 28 confirmed renames, 0 keep, 0 uncertain. No drift found.

**Families renamed**
- **Percent peak torque / friction, e2m 10E2:**
  - 0x18070 `cm848_calculateJ1939PercentPeakTorqueAtSpeed`
  - 0x1811c `cm848_calculateJ1939FrictionLoadFuelingAtBreakpoints`
  - 0x1820c `cm848_calculateJ1939PercentPeakTorquePoints`
  - 0x182e8 `cm848_calculateJ1939PercentPeakTorque`
- **PGN 65251 torque curve, e2m 1102:**
  - 0x1b3a0 `cm848_buildPgn65251EngineConfiguration1Payload`. It fills a buffer and sends nothing; the sender is 0x1b730.
  - 0x20500 `cm848_calculateJ1939ReferenceEngineFueling`
  - 0x209e8 `cm848_calculateActualEnginePercentTorque`
  - 0x20a58 `cm848_calculateEnginePercentLoadAtCurrentSpeed`
  - 0x20c64 `cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling`
  - 0x20d10 `cm848_updateJ1939EngineConfigurationTorqueCurve`
  - 0x212dc `cm848_initializeJ1939ReferenceEngineFuelingAndTorque`
  - 0x21ac0 `cm848_lookupMaximumTorqueAtEngineSpeed`
  - 0x21cd4 `cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings`
- **J1939 messages:**
  - 0x2588c `cm848_buildPgn61444ElectronicEngineController1Message`
  - 0x255c0 `cm848_sendPgn65232NonContinuousMonitorTestResultMessage`. I spelled out the PGN title because Dm8 is not on the allowed list.
  - 0x26f80 `cm848_runTsc1LostManagement`
- **J1939 control sessions, e2m 10FD-10FF and 1100:**
  - 0x50be6c `cm848_storeJ1939ControlSessionInHistoryTable`
  - 0x50beec `cm848_startJ1939ControlSession`
  - 0x50bff4 `cm848_trackJ1939ControlSessions`. It is the J1939 monitor, enabled by bit 0x800 of `governor_feature_config_word`.
- **Data collector:**
  - 0x505c20 `cm848_fillDataCollectorRingBuffer`
  - 0x505d94 `cm848_resetDataCollector`. The `hpcr_` prefix does not fit.
  - 0x505df0 `cm848_sendDataCollectorBuffer`
  - 0x505f98 `cm848_runDataCollector`
- **Number to text:** 0x27bc4 `cm848_formatNumberAsDecimalText`.
- **Engine protection shutdown:**
  - 0x508130 `cm848_examineEngineProtectionBeforeCranking`
  - 0x508898 `cm848_updateEngineProtectionShutdown`
  - 0x508e78 `cm848_detectEngineProtectionShutdownOverrideRequest`
  - 0x508ee0 `cm848_latchEngineProtectionShutdownOverride`

**Where I departed from the proposals**
- **0x21ac0:** the wave-13 "fuel table" reading is wrong.
  - The ROM grid at 0x5c58e peaks at 600 and is the e2m MT_Max_Torque_Map in lb-ft.
  - The RAM dump reproduces 1368 in 0x20500: (1030-397) x 10000 / ((290 x 13558) / 850).
- **0x21cd4:** the name covers both outputs, the torque curve fuelings and the reference fuelings.
- **0x1b3a0:** `Payload`, not `Message`.
- **0x20c64:** the literal form. The "breakpoint" proposal omits point 5.
- **0x18070 and 0x1811c:** J1939 added, to match `j1939_friction_load_fueling_at_breakpoint_4`.
- **0x26f80, 0x27bc4 and 0x255c0:** new names, since no usable proposal existed.

**Shared-name holds:** 0x1b3a0 (CM550 0x3320e) and 0x2588c (CM550 0x32c76). The plates cite siblings by their current names on purpose, so the refresh step rewrites them.

**Observations (nothing changed for them)**
- **0x21cd4 reference fuelings:** the code has no x 10000 here, unlike 0x20500. The divisor is 3939 to 9570 for 247 to 600 lb-ft, so the five reference fuelings read 0 in the dump (`algorithm_enable_flags_41_cal` = 0x7ca6, bit 11 set). I did not check what `cm848_clampedDivisionWithBounds` does with a zero denominator in 0x20d10.
- **0x1820c and 0x182e8:**
  - No caller was found: no `bl`, and no 32-bit pointer in ROM or flash2.
  - The 10E2 percent words read 0 in the dump.
  - The idle friction word reads 397, the first table value, so its lookup input was at or below 3600.
  - The other four friction words match the ROM table.
- **ROM 0x5c3ac (e2m 10E7 +2A TSC_Lost_Reset_Speed):** nothing reads it. 0x26f80 restarts from the current rpm instead.
- **This calibration:**
  - `governor_feature_config_word` = 15888 (0x3e10). J1939 monitor (0x800) is on; engine protection shutdown (0x1) and restart (0x20) are off.
  - `governor_fault_status_flags` = 39954 (0x9c12), so Collector_Enable (0x100) is off and the data collector is off.

**Out-of-bin leads**
- **PGN 65251 torque curve helpers:**
  - 0x20b84 `cm848_updateProtectionParameters` sets point 1: the idle reference speed minus a droop term, and the derated idle fueling.
  - 0x20bfc `cm848_updateProtectionInputs` picks point 3.
  - 0x21c3c `cm848_updateProtectionThresholdsIfLow` writes the point speeds from the 12BD broadcast overrides.
  - 0x21bf8 `cm848_getHighestPriorityBit` returns the highest set bit of `j1939_pgn65251_speed_points_request_flags`.
  - 0x507a20 `governor_calculateIntegratorRpmOutput` requests the fault derate curve speeds for those points.
  - 0x507c1c `fault_initBitwiseTimerMask` sets the request priority bit.
- **PGN 65251 transmit:** 0x1b730 `cm848_sendFaultTimerMessage` sends it. 0x1b778 `cm848_processFaultMessageTiming` resends when the payload changes. 0x1b900 `initFaultTimerMessage` sets up the descriptor (can_id 0xfee300, 28 bytes).
- **Torque map in lb-ft:**
  - 0x29c98 `cm848_calculateFuelDemandFilter` does the 0x21ac0 lookup at the current speed.
  - It stores the result in `fuel_demand_filter_dimension` (0x40aee6).
  - The ROM rows `j1939_fuel_table_xaxis_cal` / `_ystart_cal` / `_yend_cal` (0x5c556 / 0x5c582 / 0x5c58e) are the map's axes and grid. They carry a wrong `_cal` and a fuel domain.
  - No other W14 result covers these four.
- **Zero torque fueling:** `fuel_demand_norm_zero_cal` (0x5c398) is e2m 10E7 +16 FSS_Zero_Torque_Fueling, a ROM word (so `_cal` is wrong) that reads 0.
- **Torque normalization bit:** `algorithm_enable_flags_41_t.reserved_bit_11` now has two readers (0x20500 and 0x21cd4). Both scale the J1939 reference fueling with the torque map, so the bit can be promoted from a guess to the torque normalization enable.
- **Friction lookup init:** 0x1ea94 `cm848_initFaultSeverityTables` resets the lookup cache words for the maximum fuel grid, the friction table and the coolant table, then runs the five friction lookups.
- **Engine protection:**
  - 0x507ebc `protection_threshold_check` and 0x508834 `protection_event_timestamp` carry a bare "protection". They are the engine protection channel threshold check and its time-over-threshold counter.
  - `DAT_0005c2f4` is e2m 10B9 +0 Shutdown_Max_Limit (65535 in ROM) and has no name.
- **TSC1 rows:**
  - `etc1_fuel_demand_high_limit` (0x3feb90) is e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable. It sits in the EEPROM mirror, so it needs `_cal`.
  - `fuel_demand_timing_enable_flag` (0x40b1ee) is set with the TSC1 ignored-sender entries in 0x511b64, initial value 1, and read by 0x26f80 and 0x3ecdc. It looks like the TSC1 timing fault state; its semantics are unproved.
- **Cross-bin note:** globals3 and globals4 named the 10E2 and 1102 rows consistently with my functions (`j1939_percent_peak_torque_*_times_256`, `j1939_friction_load_fueling_at_*`, `j1939_torque_curve_*`). They name 0x40a632 `j1939_percent_peak_torque_at_current_speed_times_256`, so 0x182e8 could take an `...AtCurrentSpeed` suffix for symmetry. I left my name unchanged.
````

## 20. Wave 14 functions bin 3 (687k tokens, 38 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (function items plus the two held enum rows): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions3.json
It holds the rear axle / drivetrain ratio / power-down functions, the converter clutch helpers, crank / HPCR functions, diagnostics (pressure sensor agreement, not-safe-to-program, end-of-line lamp, warm-up cycle, engine start counts, load histogram) and the RAM refresh / diagnostic session functions together with the held enum rows (see the brief's last section). Three of the session functions carry the owner's own review notes: follow the brief's rule for them.
Write your results (one JSON object per line: one line per function item, plus one line per held enum row, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions3.jsonl

If you need scratch files, put them only under /tmp/w14_functions3/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 functions3 is done: 26 lines in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions3.jsonl (24 functions in bin order, then 0x40c04a, then 0x40aa9a). No repo file was touched (git status clean); scratch is in /tmp/w14_functions3 for the archive. A read-only re-implementation of the gate passes: each code_quote is an exact substring of its function body, name rules hold, and the new names appear in no CSV, .cpp, .hpp, CM550 file, cross_firmware_matches.csv or other W14 result file (checked at 21:41).

**Verdicts:** 24 function renames and 2 enum rows, all confirmed; 0 keep, 0 uncertain.

**Departures from the proposals**
- 0x42770 is `cm848_initializeRearAxleRatio`: it runs once at boot and does not depend on single-speed.
- 0x5268e8 is `cm848_calculateOutputShaftToVehicleSpeedDivisors`. 0x3c000 = 256 x 60 x 128 / 8 shows these are divisors (axle ratio x e2m 132C Tire_Size), not trims.
- 0x49004 is `cm848_initializeFuelPressureGovernorState`: it sits in the boot list next to the other `cm848_initialize*` calls and sets filter coefficient pointers. The old plate is kept in full, including the 0x3fb676 quirk.
- 0x533b5c is `cm848_removeEngineStartCountSinceFaultLogged`. It closes a gap with [i] = [i+1]; 0x533b94 does the opposite with [i] = [i-1]. The proposal's "shiftIn" would have been easy to confuse with 0x533b94.
- 0x50ddb4 is `cm848_controlEndOfLineTestMalfunctionIndicatorLampOverride`. Its argument is a step code 0-3, not the e2m EOL_Mil_State coding.
- 0x50638c is `cm848_updateDutyCycleMonitorLoadHistogram`. The name carries both families (e2m DC_Mon records and the load_histogram_* data).
- 0x457d0 is `mpc555_handleCamSignalInterrupt`, raised from "weaker lead" to confirmed. Channel 1's config byte is e2m 8194 +56 PMA_Edge_Type (cam). The handler writes 819C +2 Cam_Sync_State. It uses the 819B backup rows (Backup_Lost_Counter, Pulse_Period_Table_Backup) and Cam_2_Crank_Tooth_Number.

**Families renamed:** rear axle ratio and drivetrain ratio (0x4272c, 0x42770, 0x5268e8, 0x525e54); converter clutch ratio delta (0x51ba1c, 0x51ba6c); cam / fuel pressure governor / injection scheduler / cylinder balance filter (0x457d0, 0x49004, 0x529ea4, 0x42cfc); diagnostics (0x29f54, 0x2bf44, 0x50ddb4, 0x5341a8, 0x533b18 / 5c / 94, 0x50638c, 0x3e210); RAM refresh and development mode (0x21624, 0x21668, 0x21694, 0x5389c4, 0x538a84, plus the two enum rows).

**Session trio and the two enum rows (owner notes appended verbatim; the main session shows the owner any rename)**
- Normal state (boot, power-down, dump) is refresh 1 / development 0 / cal_write_mode 0xee. Service 10 (also called after a PCI security key is accepted) enters development mode with 0 / 1 / 0xea. Service 7 exits it, and only while it is on. Service 22 turns the refresh on when the engine is stopped and leaves development mode only if cal_write_mode is 0xea.
- Names: `cm848_exitDevelopmentMode` (0x21624), `cm848_enterDevelopmentMode` (0x21668), `cm848_forceExitDevelopmentMode` (0x21694). For 0x21694 the evidence names `cm848_forceEnableRamRefresh` as the alternative.
- Independent proof for 0x40aa9a: in the dumped flash2 table at 0x53a33a the register ranges are type 3 only in the STANDING_BY column (1) and type 10 otherwise.
- 0x40c04a becomes `ram_refresh_enable` with enum `RAM_REFRESH_STATE` {0 RAM_REFRESH_DISABLED, 1 RAM_REFRESH_ENABLED}. LOCKED_OUT (2) is dropped: nothing stores or tests it.
- 0x40aa9a becomes `development_mode` with enum `DEVELOPMENT_MODE_STATE` {0 DEVELOPMENT_MODE_OFF, 1 DEVELOPMENT_MODE_ON}. A plain flag would also do for both.
- Member comments are comma-free (enums.csv column order).
- e2m 10C7 +0 "compare RAM to EEPROM" is the periodic EEPROM mirror reload (cm848_periodicTaskSet_protection2 -> cm848_startEepromBlockRead -> cm848_onEepromBlockRead, copied only while refresh != INACTIVE). The ROM 0x64aea loop in 0x538a84 is the flash half (e2m 10C7 +2 Powerdown_Refresh_Enable, sensor_validation_result).

**Drift:** only e2m 1125 DC_Mon_Long_Term_Map, which resolves to 0x3fde4c while the 82 counters the code uses start at 0x3fde4e. The sum of those dwords equals the total in the dump (3203448). Two e2m notes, not drift: RUN_LOC 'AAh' versus 0xea / 0xee in this build, and Tire_Size 251 at 0x3fee7a (e2m range 300-725).

**Shared-name holds:** none; all 24 have shared_with_cm550 false.

**New leads outside the bin**
- 0x45478 `mpc555_updateEngineRunState` is the TPU-A channel 0 (PMM crank signal) handler. Its run_state is e2m 819C +6 Crank_Sync_State (0 NO / 1 LOST / 2 START / 3 PRELIM / 4 HAVE). Suggested name: `mpc555_handleCrankSignalInterrupt`.
- Struct `engine_crank_state_t` at 0x40b80a reads backwards. start_counter is Cam_Sync_Error_Count (819C +0), crank_state is Cam_Sync_State (+2), cranking_flag is Crank_Sync_Error_Count (+4), run_state is Crank_Sync_State (+6).
- 0x44fa8 `hpcr_processEngineSyncPulses` is the TPU-A channel 11 primary speed interrupt (crank_capture_period_packed = 819B +16 Crank_Accumulated_Period).
- 0x40a346 `cal_write_mode` is e2m 0010 +0 RUN_LOC: 0xee normal, 0xea development. cm848_lookupParameterIdAddress returns raw EEPROM addresses only for 0xee with the engine stopped. It is the owner's `== 0xea/0xee` enum candidate.
- enums.csv `DIAG_RESPONSE` comments are stale. NACK_NOT_READY means not in development mode. NACK_PROTECTED means not safe to program (also returned by cm848_commitEepromMirrorToEeprom). `PRIOR_BOOT_STATE` is unused and still describes the old reading of not_safe_to_program_flag.
- RAM refresh rows: 0x3fd2d4 `sensor_cal_rom_read_ptr`, 0x3fd2d8 `sensor_cal_ram_write_ptr`, 0x3fd2dc `sensor_cal_write_dirty_flag`, 0x3fd2de `sensor_cal_session_state_prev` (the previous refresh enable), 0x3fd2e0 `sensor_cal_ring_cycle_count`. 0x40c04c `sensor_validation_result` is e2m 10C7 +2 Powerdown_Refresh_Enable. The unnamed pointer rows 0x3fd2c4 / c8 / cc / d0 are the block descriptor (RAM start, RAM end, ROM source) and its cursor.
- Drivetrain ratio rows:
  - 0x5263a8 `initGovernorJ1939Bypass` is the drivetrain ratio initializer.
  - 0x40b6e8 `engine_temperature_protection_filter_state` is its EMA record.
  - 0x40b5c2 `governor_j1939_bypass_flag` is a 1 / 2 / 3 class against the top gear thresholds.
  - 0x3fd062 / 0x3fd066 `protection_trim_divisor_working` / `_cal` are low / high axle ratio x tire revolutions per mile; the `_cal` is outside the EEPROM mirror.
  - 0x3fee7a `protection_timing_period_cal` is e2m 132C +0 Tire_Size.
- End-of-line test steps (the callers of 0x50ddb4) have names that do not match the steps in the sequencer plate: 0x52ef90 `cm848_initialization_group21_state_cont` (step 0), 0x52fa34 `engine_coldStart_protection_stateMachine` (1), 0x52f250 `diag_camSync_deviation_check` (2), 0x52f5d4 `engine_coldStart_batteryVoltage_monitor` (3), 0x52f770 `engine_protection_timerBitCheck_dispatch` (6).
- Duty cycle monitor rows:
  - DAT_0040a64a is e2m 111F +2 DC_Mon_Operating_Region.
  - ROM 0x5c2bc is 111C +0 DC_Mon_High_Cutoff_RPM.
  - 0x3fdfac / 0x3fdfae hold the percentages of bins 81 / 82.
  - 0x3fbcba / 0x3fbcbc `fuel_demand_histogram_*` and 0x40aeec `fuel_demand_base_offset` belong to the monitor.
  - `algorithm_enable_flags_18_t.reserved_bit_3` is confirmed as e2m 106B +26 DC_Mon_Enable (the function gates on it).
- Pressure check rows: 0x2a214 `cm848_processSensorDeviationOnKeyoff` runs 0x29f54 after the shutdown delay. 0x40718c `cold_start_sensor_deviation_delay_cal` is a `_cal` outside the mirror (e2m 165C +6 Pressure_Check_Delay_Time). `governor_integrator_bound_a` / `_b` are pressures [77] / [38], paired with the boost / oil tolerances.
- mpc555_registers.csv TPUA_ descriptions list the channel groups in the wrong order. The firmware's own channel 0 / 1 / 11 setups fix CFSR0 = ch 12-15 through CFSR3 = ch 0-3, HSQR1 / HSRR1 / CPR1 = ch 0-7, and HSQR0 / HSRR0 / CPR0 = ch 8-15. The CSV has the opposite.
````

## 21. Wave 14 globals bin 1 (779k tokens, 41 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (global items, whole e2m blocks): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals1.json
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals1.jsonl

If you need scratch files, put them only under /tmp/w14_globals1/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 globals1 is done: 64 lines in bin order at /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals1.jsonl. I edited no repo file and ran no build. Scratch scripts are in /tmp/w14_globals1/.

What I checked: all 62 new names plus 3 split names pass the gate rules. None collides with the CSVs, the .cpp, the headers, or the other six agents' result files, and the format matches the brief. Every code_quote is a verbatim .cpp line or a fragment of one. Dump values were read at the row width from cm848_ram.bin.

**Counts**
- 62 confirmed renames, 1 keep (0x40a3ca `wastegate_duty_controller_state`, e2m 16A2 +C), 1 drift (0x40be14), 0 uncertain.
- 18 rows carry `old_comment_wrong`, mostly the `diag_dm1_*`, `cssc_*` and `protection_*` comments.
- 4 rows carry `type_note` and are held for you: 0x3fddc4 (a dword that is really the head of a 32-entry table) and 3 splits, 0x408f8c, 0x408fa3 and 0x408fa5.

**Families renamed**
- **Data collector**: `diag_dm1_*` is now `data_collector_*`.
  - 0x3fbca6 / aa / ae / b0 / b2 / b6 / b8: `_fill_stop_address`, `_fill_phase`, `_buffer_has_data_flag`, `_multiple_countdown`, `_table_entry_count`, `_sample_capacity`, `_trigger_input_previous_flag`.
  - 0x3fddc4 `data_collector_address_table_cal`.
  - 0x40c274 `data_collector_buffer_end_address`. This pairs with the other agent's `data_collector_buffer_start_address`.
- **Crank / cam block (e2m 8194, 29 rows, plus 0x40b7cc)**: the `mios` names were wrong, because these are TPU-A channel parameters.
  - Channel 0 is the crank signal (the TPU missing-transition function) and channel 1 is the cam signal (the additional-transition function). The functions3 agent reached the same reading for `mpc555_updateEngineCrankState`.
  - New names are `crank_signal_*` (0x408f93-99, 0x408fad) and `cam_signal_*` (0x408f90-92, 0x408fac).
  - Primary/backup pairs: `primary_consecutive_error_threshold`, `primary_pulse_period_timeout`, `backup_period_rpm_conversion_factor`.
  - Error limits are named for the counter they bound, with fault 5 = P0341, 117 = P0016, 92 = P0335, 93 = P0340, 124 = P0336 read through ROM 0x5985a: `cam_sync_error_count_limit`, `crank_sync_error_count_limit`, `cam_crank_mismatch_count_limit`.
  - The old "min" names were maxima.
  - Firing detection: `cylinder_firing_acceleration_threshold` and `cylinder_firing_detection_minimum_fueling`.
  - Pure `_cal` drops: 0x408f60, 0x408f8e, 0x408f9e.
  - Items 0x408f8c / 0x408f9a / 0x408fa3 / 0x408fa5 and 0x408f88 got descriptive names; the splits are listed below.
- **Cylinder balance**: the 0x3fb5a4 / a6 snapshots, and the 8C73 service limits and gain at 0x408f2c / 2e / 30 (`cylinder_balance_service_fueling_trim_maximum` / `_minimum`, `cylinder_contribution_test_gain`).
- **Coolant temperature sensor performance (P0116)**: `cssc_*` at 0x3fd18a-90 now `coolant_temperature_sensor_performance_*`.
  - 0x3fd18e is a one-shot precheck flag, not a "snapshot taken" flag.
  - 0x3fd18f is the soak-conditions flag.
- **Alpha (104A)**: `alpha_state`, `alpha_low_ambient_air_pressure_result`, `alpha_low_speed_governor_timer`, `alpha_air_fuel_control_timer`. The globals2 agent's `*_timer_active_flag` names match.
- **Others**:
  - `cruise_resume_active_flag_previous` (0x3fb528)
  - `egr_orifice_temperature_lead_time_constant_lookup` (0x3fbcf8)
  - `output_shaft_to_vehicle_speed_divisor_low_axle_ratio` and `_high_axle_ratio` (0x3fd062 / 66)
  - `logical_output_request_bits_40_to_47` (0x40c085, the intake air heater relay requests 43 / 44)
  - `cruise_top_droop_width_cal` (0x3fd912, the twin of the RSG top droop width)
  - `j1708_link_fault_timeout_count_cal` (0x3feb8c)
  - `pressure_sensor_check_delay_time` (0x40718c)
  - `wastegate_duty_compressor_outlet_temperature_derate_derivative_term` (0x40a3e4)

**Splits and type notes (apply by hand)**
- 0x408f8c / 0x408f8d: two bytes, `backup_period_capture_count` and `crank_periods_per_speed_interrupt`. Both are used.
- 0x408fa3 / 0x408fa4: `crank_lost_resync_cam_tooth_threshold` and `crank_preliminary_resync_cam_tooth_threshold`, bytes read in run state 1 and 3.
- 0x408fa5 / 0x408fa6: a byte upper limit and a word lower limit for the tooth shift. Their names are `crank_preliminary_sync_tooth_shift_upper_threshold` and `..._lower_threshold`.
- 0x3fddc4: type as `dword[32]`, with a length word at 0x3fddc2 (128 in the dump).

**Drift**
- 0x40be14 `barometric_pressure_sensor_fault_status`: e2m 1966 +94 TVA_Position_Sensor resolves here, but the code holds the barometric sensor channel's fault status. The name is kept.

**Shared-name holds**
- None. No current name in my bin appears in CM550's CSVs or `cross_firmware_matches.csv`.

**Things for you to decide**
- `j1708` in 0x3feb8c rests on the e2m record plus elimination: `etc1_active_state` is only ever stored as 1, so this path is state 0. Confidence is medium. "j1708" is not on the allowed list but is an SAE designation like j1939.
- I used `backup_` for 0x408f8c and 0x40b7cc (`backup_period_capture_index`) because the e2m names are Backup records and the data comes from channel 1. The ring `crank_period_capture_array` (0x40b7dc) keeps its `crank_` name until you rename it.
- 0x3fd062 / 66 and 0x3fbcf8 had no `dump_raw` in the bin. I quoted 113703 (= 453 x 251) and 500 from my own read of the RAM dump, so the dump-value check may flag them.
- I used `cylinder_contribution_test_gain` because `cylinder_contribution_gain` already exists in `e2m_variables.csv`.

**New leads outside my bin** (address, current name, what the code shows)
- 0x3fb52a `fuel_demand_enable_sync_flag_shadow+2` (label row): the previous-pass `cruise_control_engaged_flag`.
- Cylinder test saves in `cm848_runCylinderContributionTest`, all unnamed:
  - DAT_003fb596: previous `cylinder_diag_active_flag`.
  - DAT_003fb597: previous test status.
  - DAT_003fb598 (word[6]): copy of the learned trims.
- DAT_003fbcb4: the collector's bytes used (entries x capacity).
- 0x3fddc2: length word of the collector table, no row.
- 0x40a16e / 0x40a172 / 0x40a174 (`pressure_fuel_delay_b_status`, `fuel_rate_condition_status`, `pressure_fuel_delay_a_status`): e2m 104A +6 / +A / +C Alpha_AFC / Alpha_Governor / Alpha_LSG results, i.e. `alpha_air_fuel_control_result`, `alpha_governor_result`, `alpha_low_speed_governor_result`.
- 0x3fee7a `protection_timing_period_cal`: e2m 132C +0 Tire_Size, tire revolutions per mile. The dump reads 251, below the e2m range 300-725, so it may be drift.
- 0x3fee7c `protection_timing_counter`: VSS_Noise_Counter, in the EEPROM mirror without `_cal`.
- 0x408f28 / 2a `engine_sync_coolant_upper/lower_threshold_cal`: e2m 8C73 +0 / +2 CBD_Service_Max / Min_Coolant_Temp, with a `_cal` in RAM.
- 8194 rows with a `_cal` in RAM:
  - 0x408f58 `crank_pattern_tooth_count_cal`
  - 0x408f5e `crank_sync_phase_counter_threshold_cal`
  - 0x408f7e `crank_speed_setpoint_threshold_cal`
  - 0x408f66 `crank_timer_offset_cal`: a word row over two byte records, +10 at 0x408f66 (read as `._0_1_`) and +11 at 0x408f67 (read as the `(byte)` cast); the label row `crank_timer_offset_cal+1` sits at the second byte.
- 0x408fae / 0x408fba `crank_mios_timing_axis_cal` / `_values_cal`: the cam signal's good-window curve (e2m 819A), wrong `mios` and `_cal`.
- 819B words on the backup (cam) path still named `crank_*`:
  - 0x40b7dc `crank_period_capture_array` is Pulse_Period_Table_Backup, so `backup_period_capture_array`.
  - 0x40b794 `crank_tooth_period_raw` is Average_Pulse_Period_Backup.
  - 0x40b79a `crank_tooth_rpm` is Backup_RPM.
  - 0x40b7d0 `crank_tooth_good_window_fraction` is the cam signal's PMA_Good_Window, so `cam_signal_good_window_fraction`.
  - 0x40b79e `crank_sync_timeout_count` is Cam_Crank_Mismatch_Count, a mismatch count and not a timeout.
  - 0x40b7aa `crank_period_variation_metric` is Cylinder_Acceleration.
  - 0x40b7bc `crank_tooth_count_b` is Firing_Detection_Count.
- Struct `engine_crank_state_t` (e2m 819C): `start_counter` is Cam_Sync_Error_Count, `crank_state` is Cam_Sync_State (0 / 1 / 4 = no / lost / have), `cranking_flag` is Crank_Sync_Error_Count, `run_state` is Crank_Sync_State. The field names and comments are stale.
- Wastegate siblings, plus the stale `wastegate_duty_controller_state_t` field comments ("Governor output RPM", "Gap (0xa3cc)"):
  - 0x40a3e0 `governor_pid_adjustment_output`: TGC_Turbo_Deriv_Term.
  - 0x40a3e2 `governor_trim_lookup_result`: TGC_COT_Drt_SET_Gain.
  - 0x40a3e8 `battery_voltage_gain_lookup`: TGC_ULim_Battery_Voltage_Comp.
- 0x3feb90 `etc1_fuel_demand_high_limit`: e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable, in the EEPROM mirror without `_cal`.
- `protection_group29_startup_timer_count`, `protection_group29_coolant_temp_snapshot` and DAT_003fd184 / 003fd186 belong to the coolant temperature sensor performance family.
````

## 22. Wave 14 globals bin 2 (633k tokens, 33 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (global items, whole e2m blocks): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals2.json
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals2.jsonl

If you need scratch files, put them only under /tmp/w14_globals2/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 globals2 is done: 63 lines in bin order, written to /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals2.jsonl. Nothing else was edited; no builds, no commits. My scratch is in /tmp/w14_globals2/.

My own checks passed. `old` equals the CSV name on all 63 lines, and 63 lines match the bin order. Every code_quote is one physical .cpp line. Names pass the gate rules and clash with no CSV, .cpp or .hpp name, nor with any other `result_W14_*` file present at the end. Every comment is 400 characters or less and passes the sweep. I re-read all dump values from cm848_ram.bin and they match `dump_raw`.

## Counts
- 61 confirmed renames, 2 keep, 0 drift, 0 uncertain, 0 splits (no `width_problem` in the bin).
- 38 renames only drop a wrong `_cal`; 2 add a missing one (0x3feaa2, 0x3fedbc).
- Shared-name holds: none. No old name in the bin appears in CM550's CSVs or the cross-firmware maps.

## Families renamed
- **81AE cylinder balance (23 rows):** `cylinder_balance_*`, all with a wrong `_cal` dropped.
  - 12 reference rows become `cylinder_balance_reference_{1,2}_cylinder_{1,5,3}_{real,imaginary}`. The old 6cyl/4cyl split was wrong: Reference_2 is used by both 6- and 4-cylinder engines.
  - Filter rows use `_filter_coefficient`, following wave 13.
  - Plus `reference_3`, start tooth, reset enable, intake manifold temperature threshold, cutout disable time, component 3 adjustment, Fourier threshold and compensation reference speed.
- **81B0:** `cylinder1..5_timing_offset` become `cylinder_balance_acceleration_buffer_1..5`.
- **81A9 equivalent throttle governor (9 rows):** `equivalent_throttle_*` (tracking integral gain, minimum droop slope, cruise control / power take-off adjust gains and down speed errors, negative adjust enable and minimum fueling, positive adjust fueling margin). All `_cal` dropped.
- **Alpha (3):** `alpha_fuel_rate_filter_state` and the two `alpha_*_timer_active_flag` rows.
- **Fueling selection (3):** `total_fueling_selected` (it holds the clamped value too), `total_fueling_previous_pass`, and the EEPROM freeze frame `total_fueling_before_shutdown_or_excess_injection_fault_cal`. There is no timing in any of them.
- **Commanded throttle filter (3):** `commanded_throttle_filter_coefficient_lookup_result`, `..._cached_axis_offset`, `commanded_throttle_filter_state`.
- **Others:**
  - `throttle_100_speed_points_request_bit` and `..._initialized_flag`
  - `low_speed_governor_alternator_load_filter`, named `_filter` because it is a signed-filter record
  - `fault_registered_bits_592_to_607`
  - `recent_fault_dtc_codes_cal`
  - `four_dimensional_fueling_interpolation_factor` (it is alpha-driven, not thermal)
  - `power_down_refresh_enable`
  - `j1939_engine_speed_at_point_4` / `_5`
  - `charge_pressure`
  - `oxygen_flow_delay_volume_fraction`, `egr_flow_downstream_model_select`, `egr_flow_delay_fraction`
  - `ambient_air_pressure_initial_scaling_factor`
- **Keeps:** 0x40b56a and 0x40b56c, the P0720 timers. The code matches 8C4E +0 / +2; the 8C58 +C / +E records that also resolve there are the known 8C58 tail overlap.

## Drift and judgment calls
- **0x4086c6:** the bin's record (8A14 +2C) is the known drift. I renamed from 8A2A +0 APC_Initial_Scaling_Factor, which the code matches (barometric pressure x it / 100, 107 in the dump). The result is the y axis of the heater preheat table (ROM 0x5b3d8: 1257..1823 counts = 20..29 inHg). Treat as plain drift if you prefer.
- **0x4002e8:** 9552 in the dump is above the record's 0..1 range (8192 = 1.0), so the code's `< 0x2001` test takes its 0xffff branch. I judged it not drift: +8 and +A on the same block match the code.
- **0x3fedbc:** the bin showed no e2m record. `e2m_block_addresses.py --address` gives 128A +0 Recent_J2012_Codes_Table, so the audit misses array rows. The old comment ("SPN history") is wrong; the values are BCD DTC codes. I set `old_comment_wrong: true`.
- **0x40c04c:** xref shows 0 reads and 2 writes, so the "enable" polarity rests on the e2m text and the initial value 1.
- **0x40a42e:** I chose `charge_pressure` (e2m base name) over a `_selected` form like `barometric_pressure_selected`. The +2 word is Charge_Press_Source.
- **0x409080:** the e2m says "fueling below which ...", but the code needs `min <= final_fueling` (a minimum). The name follows the code and the evidence quotes the compare.

## Held or flagged rows
- **0x40a406:** `type_note` holds it (struct instance).
  - The type `boost_pressure_state_t`, its field names and the seven dotted label rows 0x40a408..0x40a414 must change with it.
  - The `type_note` gives field -> record: `load_input` is the intake manifold temperature in Rankine (177D +2), and the last two words are 177B +0 / +2.
  - New name `charge_flow_estimate_terms`.
- **0x3fea22:** it keeps the family name `fault_registered_bits_592_to_607` without `_cal`, against the brief's region rule. All 49 fault_detected / fault_registered / fault_previous_pass bit rows in the mirror, including its twin 0x3fe9be applied in wave 13, have no `_cal`. The strict rule would add `_cal` to all 49. The `evidence` and a `cal_note` field say so.

## Notes for the apply
- `comment` is at most 400 characters and sweep-clean.
- `evidence` is not: it quotes old names, so do not write it into the CSV.
- Comments cite current function names. Renamed in the other result files (comments not updated):
  - cm848_calculateSensorEma -> cm848_calculateAlphaFuelRateResult
  - cm848_checkPressureFuelDelayA -> cm848_calculateAlphaLowSpeedGovernorResult
  - cm848_checkPressureFuelDelayB -> cm848_calculateAlphaAirFuelControlResult
  - hpcr_calculateFuelTrimOutput -> cm848_calculateAlpha
  - cm848_initFuelPressureVariables -> cm848_initializeAlpha
  - cm848_calculateLoadBasedFuelTrim -> cm848_calculateDownstreamEgrMassFlow
  - cm848_calculateRpmBasedFuelTrim -> cm848_calculateUpstreamEgrMassFlow
  - cm848_selectFuelTrimMode -> cm848_calculateEgrMassFlowBeforeDelay
  - cm848_boostBasedFuelModifier -> cm848_calculateVolumetricEfficiency
  - cm848_calculateFuelDemandChangeRate -> cm848_filterCommandedThrottle
  - cm848_processJ1939RxMessage -> cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling
  - cm848_updateProtectionStateMachine -> cm848_updateJ1939EngineConfigurationTorqueCurve
  - cm848_updateProtectionDiagnostics -> cm848_calculateJ1939TorqueCurveFuelingsAndReferenceFuelings
  - hpcr_processLoadThrottle -> hpcr_filterCylinderBalanceFueling
  - cm848_checkSensorDeviationFlags -> cm848_checkPressureSensorAgreement
  - uds_session_state_init -> cm848_initializeRamRefresh
  - Evidence only: cm848_loadBasedFuelAdjustment -> cm848_calculateChargeMassFlow

## Cross-bin pairs
Checked against the other result files present at the end (no globals4 yet).
- Agree:
  - 0x5be66 -> `alpha_fuel_rate_filter_coefficient`
  - 0x40a17e / 0x40a180 -> `alpha_low_speed_governor_timer` / `alpha_air_fuel_control_timer`
  - 0x4070e4 -> `low_speed_governor_alternator_load_filter_coefficient`
- Differ: 0x406a46 / 0x406a52 are named `commanded_throttle_filter_coefficient_by_throttle_difference_axis` / `_values`. By the table grammar my cache word 0x3fa882 would then be `commanded_throttle_filter_coefficient_by_throttle_difference_cached_axis_offset`. I left my file alone; reconcile when applying.
- 0x40a430-0x40a436 (globals4) are not checked: my base for the +0 word is `charge_pressure`, and the siblings should start with it.

## Leads outside my bin
- **0x409072** `governor_speed_proportional_gain_cal`: it is 81A9 +2 Equiv_Throt_Proportional_Gain, used in the same tracking loop. Should be `equivalent_throttle_tracking_proportional_gain`, and RAM so no `_cal`.
- **81AE siblings with a wrong `_cal` or `cbd`, in no bin:**
  - 0x408ee4 `cylinder_sync_rpm_delta_threshold_cal` (CBD_Delta_Speed_Threshold)
  - 0x408ee6 `fuel_demand_zero_rpm_upper_cal` (CBD_Upper_Speed_Limit)
  - 0x408ee8 `fuel_demand_zero_rpm_lower_cal` (CBD_Lower_Speed_Limit)
  - 0x408ef4 `fuel_demand_setpoint_zero_threshold_cal` (CBD_Motoring_Fuel_Threshold)
  - 0x408ef6 `cbd_enable_flag` (CBD_Enable_N)
  - 0x408f14 `crank_sync_coolant_threshold_cal` (CBD_Coolant_Temp_Threshold, a minimum in the same disable chain as 0x408f16)
  - 0x408f20 (CBD_Cylinders = 6, no row)
- **0x3fb57e** `crank_state_debounce_timer`: the countdown reloaded from 0x408f18. It should be `cylinder_balance_cutout_disable_timer`.
- **0x3feaa0** `governor_mode_code_diag_snapshot`: the previous final_fueling_state latched with 0x3feaa2. It is in the mirror without `_cal` and has banned `diag`. xref: 1 write, 0 reads.
- **0x3fa86e** `governor_diag_entry_latch_flag`: banned `diag`; the latch that `cm848_clearFuelDemandFlag` (0x1e4d8) re-arms from the start-up init list.
- **0x3fd804** `fuel_timing_target_working`: in the EEPROM mirror without `_cal`. It is the FUELING_STATE_FUEL_OVERRIDE fueling that `cm848_selectFinalFueling` reads when `governor_feature_flags & 2`; the same "timing" misread.
- **0x40b1ec** `protection_iat_scaled` and **0x3fb224** `protection_iat_scale_pending_flag`: this is barometric pressure x 1.07, not an intake air temperature. Suggested names: `ambient_air_pressure_initial_scaled` and `..._pending_flag`.
- **Acceleration buffer shape:** 0x40b74c..0x40b75b is one `word[8]` array (e2m 81B0 +12..+20). Code indexes `(&cylinder1_timing_offset)[cylinder_event_seq_counter]` and the misfire monitor indexes it too. Buffers 7 and 8 (0x40b758 / 0x40b75a) have no row. I did not hold the five plain renames for this.
- **Signedness (kept out of `type_note` so renames are not held):**
  - e2m-signed rows read with `lha`: 0x409076, 0x40907a, 0x408ef8-0x408f10, 0x408f16, 0x408f1c, 0x40b74c-0x40b754. `i16` would fit.
  - 0x40907c is an unsigned record read as a signed short.
  - 0x40a42e is an unsigned record, but 4 of its 13 accesses are `lha`.
````

## 23. Wave 14 globals bin 3 (681k tokens, 41 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (global items, whole e2m blocks): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals3.json
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals3.jsonl

If you need scratch files, put them only under /tmp/w14_globals3/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
## W14 globals3: summary

The result file has 63 lines in bin order: `/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals3.jsonl`. It was written with `json.dumps` from `/tmp/w14_globals3/gen.py`.

Checks run against the final file:
- My self-check (`check.py`) reports no problems. It covers address and `old` against the bin and the CSV, name format, uniqueness within the file and against the CSVs, the .cpp and the headers, and all other `result_W14_*.jsonl` files. It also checks `_cal` by region, that each quote is in the .cpp and holds the old name, and the dump values I quote.
- The repo gate (`apply_renames.py`, dry run, nothing written) reports no PROBLEM for the 54 renames.
- `git status --short` is clean. I touched no repo file.

### Counts
- 54 rename (`confirmed`), 8 keep, 1 drift, 0 uncertain.
- 0x40912a is held by the apply: it carries a `type_note` and a one-entry `split` (a byte row over a 2-byte record; widen to word).
- 0x40b58c is a rename from the code and also drift in the record. List it under both.

### Families renamed
- **Throttle filter table (0x406a46, 0x406a52):** `commanded_throttle_filter_coefficient_by_throttle_difference_axis` / `_values`.
  - Blocks 1583 / 1584 are not in the dumped ID table, so there is no table-resolved record.
  - The basis is the X / Y pair, the units and scales, the description and the code role. It is stated in each comment.
- **Data collector (0x40c270):** `data_collector_buffer_start_address`. It pairs with globals1's `data_collector_buffer_end_address`.
- **Alpha fuel rate filter (0x5be66):** `alpha_fuel_rate_filter_coefficient`. It pairs with globals2's `alpha_fuel_rate_filter_state`.
- **Low speed governor alternator load (0x4070e0 / e2 / e4):** `low_speed_governor_alternator_load_{fuel_gain, duty_offset, filter_coefficient}`.
- **e2m 10E2 J1939 block (11 rows, 0x40a630-0x40a646):**
  - `j1939_no_load_fueling`
  - `j1939_percent_peak_torque_at_{current_speed, breakpoint_3, breakpoint_4, breakpoint_5, idle, rated_speed}_times_256`
  - `j1939_friction_load_fueling_at_{low_idle, rated_speed, breakpoint_3, breakpoint_5}`
  - The two functions that write the percent words have no caller (see the leads), so those words read 0.
- **Cruise droop, e2m 1187 (6 rows):**
  - `cruise_control_fueling_{bottom, top}_droop_{gain, offset}` are the values passed to the fueling procedure.
  - `cruise_{bottom, top}_droop_gain` are the computed slopes.
- **Air fuel control, e2m 11D5 (4 rows):** `air_fuel_control_low_boost_time_delay`, `_normal_boost_time_delay`, and `air_fuel_control_low_boost_blend_fraction_{increase, decrease}_step`.
- **OBD pending readiness code (0x3fed98):** `monitor_pending_readiness_code_cal`. It gains the missing `_cal`.
- **Wastegate (0x3ffca6):** `wastegate_duty_override_value`. The comment and evidence cite the `wastegate_duty_integrator_preset_flag_cal` branch.
- **Charge flow and volumetric efficiency, e2m 177C (11 rows):**
  - `charge_mass_flow_{filter_coefficient, estimate_maximum, estimate_minimum}`
  - `engine_{stroke, bore, valve_diameter}_inches`
  - `engine_volumetric_efficiency_{maximum, minimum, parameter_a, parameter_b, parameter_c}`
- **Exhaust temperature model (0x40a682):** `exhaust_temperature_model_energy_fraction`.
- **HPCR fuel pressure governor / fuel metering command, e2m 8000 (10 renames, 8 keeps):**
  - `fuel_pressure_governor_demand_minimum_when_{not_running, running}`
  - `fuel_metering_command_{override_enable, override_value, maximum, minimum}`
  - `fuel_pressure_governor_accelerator_feed_forward_{gain, minimum, maximum}`
  - `fuel_metering_battery_voltage_filter_coefficient` (0x40912a, held)
- **Converter clutch (0x40b57d):** `converter_clutch_rationality_ratio_delta`.
- **Governor pressure loop (0x40b58c):** `governor_pressure_controller_error_delta_term`.

The 8 keeps are 0x409114, 16, 18, 1e, 23, 26, 28 and 2e. Their names are accurate and each has an `e2m_note`.

### Drift
- New: e2m 8C34 drifts from +12 on. 0x40b58c, 0x40b58e and 0x40b590 are the governor pressure solenoid loop; the 8C34 monitor words end at +10.
- 0x40b58e (`governor_pressure_error`) is `drift` with no rename and no split. Both accesses are 4-byte `lwz` / `stw`, and neither e2m record is used.
- 0x40b58c is a rename from the code.
  - The old comment called the term "(D)". The new comment does not, because the loop adds three helper terms to `governor_pressure_controller_output` every pass in an incremental form.
  - A term on the per-pass error change acts like a proportional term there, so the name states what the term is computed from, the error delta.

### Shared-name holds
None. This bin has no function items.

### Names to reconcile
- `cruise_bottom_droop_gain` and `cruise_top_droop_gain` also appear in `e2m_variables.csv`. The gate does not read that file; wave 13 had the same coincidence for `friction_fueling`. They pair with `cruise_bottom_droop_width_cal` and with globals4's `cruise_top_droop_gain_for_rear_axle_ratio_low`.
- My comments cite five names from other bins' results. All were checked against the result files present at 21:43.
  - `data_collector_buffer_end_address`
  - `commanded_throttle_filter_coefficient_lookup_result`
  - `alpha_fuel_rate_filter_state`
  - `low_speed_governor_alternator_load_filter`
  - `charge_pressure` (the new name of `map_fuel_correction_factor`)
- They also cite current names of 11 functions that functions1-3 propose to rename (a comment name sweep can handle these):
  - `cm848_boostBasedFuelModifier`
  - `cm848_calculateFuelDemandChangeRate`
  - `cm848_calculateSensorEma`
  - `cm848_calculateThrottleProtectionLimit`
  - `cm848_faultSeverityEvaluation`
  - `cm848_initFuelPressureVariables`
  - `cm848_loadBasedFuelAdjustment`
  - `cm848_pidError_calc`
  - `cm848_pidIntegrator_accumulate`
  - `cm848_processThrottlePositionLookups`
  - `hpcr_exception_process`

### Type remarks (not in `type_note`)
- These rows have signed e2m records and are typed `word`. Their reads are `lha` or `sth`, so `i16` would fit.
  - 0x400944
  - 0x409110, 0x409112, 0x409114, 0x40911e, 0x409121, 0x409123, 0x409132, 0x409134, 0x409136, 0x409138
  - the six percent rows 0x40a632-0x40a63c
  - 0x40b57d
- 0x40b58c is read as signed (`(int)(short)`) although its e2m record is unsigned.
- 0x409121 and 0x40b57d are words at odd addresses; that matches their e2m offsets.

### Leads outside my bin
1. **The RAM dump has a gap (inferred).**
   - `cm848_ram.bin` is 0x45f80 bytes, which is 0x80 short of 0x440000.
   - The values 0x0040c28a / 0 / 0x003fddc4 sit at dump 0x40c200 / 0x40c204 / 0x40c206. That is 0x80 below the rows 0x40c280 / 0x40c284 / 0x40c286: the collector end pointer, status and table address.
   - Those three named rows read 0 at their own address and the expected value at address - 0x80.
   - The EEPROM mirror and the rows below 0x40c200 match.
   - So 0x40c200-0x40c27f is not in the dump, and rows from 0x40c280 up must be read at -0x80. The dump value 0 for 0x40c270 is not usable.
   - Affected rows: 0x40c200, 0x40c204, 0x40c234, 0x40c244 (`actuator_d_period_command`, `alternator_field_period_microseconds`, `egr_valve_motor_pwm_period_command`, `variable_geometry_turbocharger_motor_pwm_period_command`), 0x40c258 `output_read_back_fault_bits`, 0x40c25e / 0x40c260 `engine_rpm_override_value` / `_enable`, 0x40c262 `protection_timeout_sentinel`, and 0x40c270-0x40c27c.
   - globals1's comment for 0x40c274 says "0 in the dump, the collector is idle". The existing `data_collector_center_address` comment says "0 here". Neither is backed by the dump.
   - The collector end pointer is 0x40c28a (stored by `hpcr_exception_process`) and the table address is 0x3fddc4.
2. **`cm848_processThrottlePositionLookups` (0x1820c) and `cm848_calculateThrottleProtectionLimit` (0x182e8) have no caller.**
   - There is no `bl`, `b` or `bc` to them in all.dis, and no 32-bit pointer to them in the ROM or flash2 images.
   - Both are functions2 items. The Jcomm percent words stay 0.
3. **Siblings that are in no bin:**
   - 0x40094a / 0x40096c / 0x40098e / 0x4009b0 `boost_rpm_scale_axis_cal` / `boost_rpm_scale_output_cal` / `boost_load_axis_cal` / `boost_load_output_cal`. These are word[17] RAM rows with a wrong `_cal`, the tables of the volumetric efficiency model.
     - The axis is engine speed x stroke (800..3500 rpm x 4.7244 in).
     - The load axis is the absolute intake manifold temperature in 1/64 deg F (`intake_manifold_temperature_filtered + 0x7300`).
     - Its values are 157.5 x sqrt(axis).
   - 0x3fa5d6 `boost_modifier_filter_state` is the EMA record of `charge_mass_flow_filtered`.
   - 0x409472 / 0x40947e `cam_sync_speed_output_scale_axis_cal` / `_values_cal` (word[6], RAM, wrong `_cal`), 0x3fb697 `cam_sync_speed_filter_state`, and 0x40b884 (`engine_sync_state_t.reserved_05`) form the battery voltage compensation of `fuel_metering_command`: filtered battery voltage, then a scale table, then command x scale >> 12.
   - 0x3feff2 `fuel_demand_load_base_cal` (AFC_Fueling_Override_Value, `_cal` outside the mirror) and 0x3feff8 / 0x3feffa / 0x3feffc / 0x3feffe `fuel_demand_load_threshold_c / _b / _a / _d`.
   - 0x3ff002 / 0x3ff006 `fuel_demand_load_result_working` / `_select_working` and 0x3ff012 `boost_fuel_limit_maximum_decrease_step`. All of these are the air fuel control fueling thresholds and slew rates used in `cm848_calculateAirFuelControlFuelLimit`.
   - 0x40aeec `fuel_demand_base_offset` is e2m 109C +0 No_Load_Fuel, a table-resolved row with no comment. It is the friction fuel plus the coolant, A/C and fan adjustments, with about 25 readers.
   - 0x3fa712 `throttle_demand_offset_cal_working` is the friction fuel correction by coolant temperature, with a wrong `_cal` in the copy window.
   - 0x3fcefe `protection_pid_rpm_setpoint_prev` is the previous `converter_clutch_rationality_ratio`.
   - 0x40b596 `protection_throttle_error_delta` (dword) is `governor_pressure_error` minus the previous error. 0x408af0 `protection_throttle_velocity_gain` is its ROM gain. DAT_0040b59e and DAT_0040b594 are the other two terms. The `cm848_throttleGain_*` and `cm848_throttleSetpoint_limit` functions are governor pressure controller helpers misnamed "throttle".
   - 0x40b6b4 `cruise_speed_setpoint_c` (e2m RSG_BDO) and 0x40b6be `cruise_speed_offset_latched` (e2m Cruise_RSG_Top_Droop_Offset) are still unrenamed. Both were already named in the wave 13 report.

### Scratch folder (for the archive)
`/tmp/w14_globals3`: `gen.py`, `check.py`, `gate_dry.py`, `stale.py`, `names_check.py` and the lookup helpers (`item.py`, `uses.py`, `ptrsearch.py`, `dumpgap.py`, `others.py`, `inbins.py`).
````

## 24. Wave 14 globals bin 4 (751k tokens, 40 min)

### Prompt (exact text)

````text
You are one of seven parallel agents in CM848 rename wave 14 (Cummins ISB firmware reverse engineering). Read the brief first and follow it exactly:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/brief_W14.md

Your bin (global items, whole e2m blocks): /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals4.json
Write your results (one JSON object per line, one line per item in your bin, in bin order) ONLY to:
/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals4.jsonl

If you need scratch files, put them only under /tmp/w14_globals4/. Do not edit any other file. No builds, no commits. Finish with the short summary the brief asks for.
````

### Report (exact text, the agent's handback message)

````text
W14 globals4 is done. The result file is /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals4.jsonl: 63 lines in bin order. I edited no repo file. Scratch is in /tmp/w14_globals4/ (peek.py, fault.py, addr_records.py, spec_a/b/c.py, build.py, verify.py, cross_check.py, shared_names.py).

My checks on the final file: `old` equals the CSV name, and every new name passes the apply_renames.py rules (copied by hand, since the gate was not run). `_cal` appears only in the EEPROM mirror, and no new name collides with a CSV row, a .cpp token, or another W14 result file. Every code_quote sits on an executable .cpp line.

## Verdicts
- 61 renames (`confirmed`), 2 keeps, 0 drift, 0 uncertain.
- Keeps:
  - 0x40af54 `transmission_park_or_neutral_flag`: two records resolve here.
    - 109E +8 Chrysler_Park_Neutral_Flag matches the proved code use.
    - 1226 +56 CANC_Requested_MIL is a drift alias; it lands inside the power take-off words.
    - The e2m_note carries 109E +8.
  - 0x40b9cb `general_diagnostic_battery_voltage_in_range_flag`: no record resolves to that byte (1B2D +6 resolves to 0x40b9ca), the name is accurate, and the e2m_note is empty.
- 15 renames carry `old_comment_wrong`: 0x3fcff0, 0x3fcff4, 0x40a198, 0x40a19c, 0x40a78a, 0x40a790, 0x40b57f, 0x40b58b, 0x40b9a4, 0x40b9a6, 0x40b9c6, 0x3fddba, 0x40a1a2, 0x406776, 0x408a9c / aa4 / aa8. Each new comment carries the old comment's proved facts.
- One rename is held for the main session: 0x40b87f `engine_sync_state_t_0040b87f` -> `fuel_pressure_governor_state`. It has a `type_note`:
  - the struct is 6 bytes with a 1-byte `reserved_05`, but 0x40b884 is a word (lhz at 0x48d14, sth at 0x49250);
  - e2m 8019 +5 HPCR_Filtered_Battery_Voltage is a 2-byte record there, so the struct should be 7 bytes;
  - the type and its field labels want the matching `fuel_pressure_governor_state_t` rename in the same change.
- No `split` entries.

## Families renamed
- **The 1102 PGN 65251 torque curve (17 rows):**
  - `j1939_determined_engine_speed_at_point_1` / `_3`;
  - `j1939_torque_curve_speed_at_point_1` / `_3`;
  - `j1939_torque_curve_fueling_at_point_1`;
  - `j1939_torque_curve_calculated_fueling_at_point_1..5`;
  - `j1939_torque_curve_reference_fueling_at_point_1..5`;
  - `j1939_nominal_friction_percent_torque_times_256`.
  - I checked the point numbering against `cm848_updateProtectionStateMachine`: the calculated fuelings are snapshots taken before the working fueling resets to `fuel_demand_maximum`.
- **Air handling source words:** `barometric_pressure_reference_source`, `ambient_air_temperature_reference_source`, `compressor_inlet_pressure_source`, `intake_manifold_temperature_filtered_source`, `compressor_outlet_temperature_source`, `egr_orifice_delta_pressure_source`, `egr_delta_pressure_negated_source`, `charge_pressure_source`.
- **Charge pressure (1A2D / 1A2C):** `charge_pressure_state`, `charge_pressure_in_range_condition`, `charge_pressure_in_range_enable_flag`, `charge_pressure_in_range_fault_clear_threshold`, `charge_pressure_in_range_fault_count_decrement`.
  - 0x40a434 is 1 when the deviation exceeds the limit, so the old "below threshold" was backwards.
- **All-speed governor 107C:**
  - `all_speed_governor_derivative_term` (0x40a1aa);
  - `all_speed_governor_state_integral` (X2), `_pid_clamp_value` (X4), `_pid_integral_clamped` (X5), mirroring the 1170 reset-state names;
  - `all_speed_governor_derivative_adjustment` (the QD word).
- **Governor pressure monitors (8C59):**
  - `governor_pressure_zero_check_target_high_limit`;
  - `governor_pressure_mid_range_check_target_low_limit` / `_high_limit`;
  - `governor_pressure_check_maximum_transmission_temperature` / `_minimum_...`.
  - These are pressure targets and a transmission temperature window, not rpm or load.
- **Converter clutch monitor (8C34):** `converter_clutch_rationality_monitor_state`, `converter_clutch_first_lockup_in_third_gear_flag`.
- **Cylinder balance (81B0):** `cylinder_balance_stop_compensation_flag` (the old "valid" had the polarity reversed), `cylinder_balance_trim_limits_exceeded_flag`.
- **Rail pressure key-on check (1B2D):** `fuel_pressure_sensor_pre_start_check_state`, `fuel_pressure_sensor_pre_start_check_abort_code`.
- **Coolant temperature sensor performance (P0116):** `coolant_temperature_sensor_performance_temperature_span`, `_state`. They match the globals1 agent's `..._temperature_minimum` / `_maximum` suffix style.
- **Cruise droop gains:**
  - `cruise_top_droop_gain_for_rear_axle_ratio_low` (0x3fcff0);
  - `road_speed_governor_top_droop_gain_for_rear_axle_ratio_low` (0x3fcff4);
  - these pair with globals3's `cruise_top_droop_gain`.
- **Drivetrain ratio (106C):** `drivetrain_ratio_user_filtered`, `drivetrain_ratio_out_of_gear_cruise_disable_flag`.
- **Other renames:**
  - `data_collector_stop_mode_cal` (0x3fddba, EEPROM mirror);
  - `cruise_coast_accelerate_hold_countdown`;
  - `engine_protection_shutdown_override_request_flag` and `engine_protection_timer_state`;
  - `commanded_throttle_transient_flags`;
  - `compressor_inlet_pressure_drop`;
  - `egr_orifice_temperature_estimate_minimum_limit`;
  - `sensor_channel38_filtered_output` and `boost_pressure_channel77_sensor_filtered`.

## Drift and e2m contradictions
- The 1226 +56 alias at 0x40af54, described under Keeps.
- 0030 +4 Collector_Stop_Mode has range 0-2 in the e2m, but the code tests 1, 2 and 3. The record is correct by the parameter ID table.
- 1B2D +0 abort code 5 is "keyon too long" in the e2m. In the code it is set when the engine leaves STOPPED before the minimum number of samples. Both are recorded in the comment.
- The e2m description of 1921 +8 Ambient_Air_Tmptr_Source is copied from the pressure source. The code confirms it is the ambient temperature source.

## Holds and caveats
- **Shared-name holds:** none. None of the 61 old names appears in CM550's global_variables.csv or function_renames.csv, docs/cross_firmware_variable_map.csv, or cross_firmware_matches.csv.
- 0x40bb8a rests on this calibration: `qadc_channel_index_table[1]` and `[77]` hold the same index in the RAM dump. The code role holds regardless: the boost tolerance pairing and the compressor pressure ratio.
- 0x40bb3c is named by slot on purpose. Nothing writes channel 38, and "oil" comes only from the e2m tolerance order.
- 0x40a790 has no decompiled reader (three sth writes and no load). The name avoids SPN numbers and the J1939 coding, which is only the e2m's wording.
- `compressor_inlet_pressure_drop` also exists in `output/e2m_variables.csv`, the reference list that no build step reads. It collides with no CSV row or .cpp token.
- Comments cite current function names, several of which the function bins rename.
- Scaled dump values follow the brief's "N in the dump = X unit" form. The wave-13 `check_quoted_dump_values_W13.py` regex would misread the `= X` part as a quoted dump value.

## New leads outside my bin (current name; what the code shows)
- **Coolant sensor monitor:**
  - 0x40b9a2 `cssc_coolant_monitoring_cycle_count` -> `coolant_temperature_sensor_performance_monitoring_cycle_count`.
  - 0x3fd182 `protection_group29_coolant_temp_snapshot` and 0x3fd188 `protection_group29_startup_timer_count` belong to the same monitor.
  - So do DAT_003fd184 and DAT_003fd186, the intake manifold and battery temperature snapshots.
- **Thermostat monitor (P0128) `cssc` leftovers:** 0x40ba5e `cssc_initial_warmup_budget`, 0x40ba60 `cssc_conditioning_cycle_count`, 0x3fd262 `cssc_oiltemp_cooling_rate_fraction`, and the `engine_cssc_oilTemp_*` functions -> `thermostat_monitor_*`.
- **Sensor-select sources:**
  - 0x40a164 `fuel_boost_mode_state` (i16) is the barometric pressure selection state; the unsuffixed `barometric_pressure_source` is left for it.
  - 0x40a60a `fuel_demand_state_b` is the ambient air temperature input state.
  - 0x40a7d2 `fuel_demand_droop_state` is the source of `boost_pressure_current_raw`: 0 sensor, 1 synthetic EMA, 2 default (`phase_group_a_validateEngineSync`).
  - `boost_pressure_state_t_0040a406.reserved_0e` is the fresh air mass flow state, and `reserved_0a` is e2m 177D +C Charge_Flow_Source.
- **1102:** 0x40ad96 / 0x40ad98 `protection_speed_ratio_c` / `_d` are the percent torque x 256 at points 3 and 4 (`cm848_updateProtectionStateMachine`).
- **107C (the 1102 / 107C items are siblings of my renamed rows):**
  - 0x40a1cc / 0x40a1d4 `fuel_demand_pid_accum_hi` / `_lo` are the ASG QI / QP adjustments.
  - 0x40a1b2 and 0x40a208 are other 107C siblings.
  - 0x3fa0e8 `governor_pid_integral_state` is the dword whose high word is X2.
- **106C:** 0x40b6fe `fuel_flow_rpm_divisor_saved` is +A Gear_Ratio_When_Loaded.
- **10B1:** DAT_0040a78b is +19 EPF_Shutdown_Override_Lamp_Flag, with no row yet.
- **Cruise droop:** DAT_003fcff2 / DAT_003fcff6 are the rear_axle_ratio_high twins of my two cruise droop rows.
- **Pre-start check leftovers:** 0x3fd1de, 0x3fd1dc, 0x409ef4 and 0x409ef8 still say `cam_sync_validation_*` in `hpcr_checkRailPressureSensorBeforeStart`.
- **8019:** 0x40b890 `engine_sync_cold_start_flag` is HPCR_Dutycycle_Output_Tool_Override (1 B). 0x40b899 `engine_sync_signal_flag` is Temperature_Reset_Status.
- **Converter clutch monitor rows still named `protection_*`:** `protection_output_rate_counter`, `protection_output_phase_entry_flag`, `protection_action_mode_b2_snapshot`, `protection_pid_rpm_setpoint_prev`, `protection_fuel_demand_prev`, `protection_fuel_demand_tick_snapshot`, and 0x408ad2 / 0x408ad3 / 0x408ade.
- **Governor pressure tracking rows:** `protection_coldStart_channelA/B_window_active_flag`, `protection_coldStart_eval_cycle_count` and `_protection_coldStart_channelB_fault_reported_flag`.
````
