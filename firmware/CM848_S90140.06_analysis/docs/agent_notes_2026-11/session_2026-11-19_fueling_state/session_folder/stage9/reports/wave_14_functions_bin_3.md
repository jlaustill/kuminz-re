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