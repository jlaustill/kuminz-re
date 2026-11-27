# L1 describer notes (round 94)

## 0x1c0d4 cm550_FUN_0001c0d4 (torque limit -> fuel limit)
- asm 0x1c0d4-0x1c150: guard max torque 0x80db1a (MTMPRPFL, e2m 1461 +0) <1 -> 1; d0 = 0x35076 scaleByRatioSigned(torque_derate_torque_limit 0x80d338, FSMTFLNP 0x80d370 - NLFL 0x80db1c, 0x80db1a); + NLFL; <0 -> 0; if < torque_derate_fuel_quantity 0x80dec8 -> store + state 0x80d33a -> 0x80deca; THEN 0x80d338 = 0xffff, 0x80d33a = 0x28 (40 FUELING_STATE_NO_DERATE).
- Only caller: cm550_selectFinalFueling 0x1c152 right after cm550_runFuelLimitChains (when torque_derate_override_enable = 0).
- CM848 0x1e4e8 cm848_calculateProtectionRateLimited: SAME formula (mulhw/mullw + 0x570f0 64/32 divide), same guard (==0 -> 1), same clamp, same compare/store; NO reset. CM848's caller cm848_arbitrateRequestedFueling resets limit=0xffff / NO_DERATE BEFORE cm848_processProtectionLimits + this. => counterpart (reset moved: CM550 consume-and-clear + start-up clear 0x1c308; CM848 clear-before-chain, no start-up clear).
- Only writer that lowers the torque limit in both: applyPowerTakeOffTorqueLimit (twin, chain step 2).
- 0x80d370 = e2m 105A +8 FSMTFLNP 'MAX FUELING WITHOUT PROGRAMMABLE POWER FOR ESP TAU 0' (type undefined, read as word at 0x1c102) = CM848 throttle_100_fueling_without_programmable_power 0x40a89f (105A +8 FSMTFLNP). Same record -> same name.
- 0x80db1a = e2m 1461 +0 MTMPRPFL = CM848 0x40aee6 (fuel_demand_filter_dimension: output of the max torque map interpolation in cm848_calculateFuelDemandFilter 0x29c98; CM848 block 1461 not in its dumped table).

## 0x1c308 cm550_FUN_0001c308
- asm: move.w #0xffff,0x80d338 ; move.w #0x28,0x80d33a ; rts. Called once from mc68k_applicationMain (0x8976 step, after cm550_FUN_00026a2e, before the restart point 0x28978). CM848: no counterpart (CM848 clears in cm848_arbitrateRequestedFueling every pass).

## 0x16dd4 cm550_highRpmEngineProtectionStateMachine -> engine warmup protection (e2m group 7A EWP, blocks 11EA work / 11EB cal / 11EC-11EF tables)
- asm 0x16dd4-0x1709c. Called from cm550_runEvery10FramesTaskSetPhase0 (50 ms; the e2m timers are 0.05 s per count). Return value is leftover d0 (void in effect).
- No numbered state word: flags + timers only. Off path (enable bit 0x2 of algorithm_enable_flags_18_cal clear, OR completed WPSSFG and engine_state != STOPPED, OR inhibit WPIHFG 0x80ccc8): completed=1, limiting=0, LSG lock 0x80a8f4=0, WPACFT 0x80ccca=0, limit 0x80ccc6 = fuel_demand_maximum.
- STOPPED: clear oil pressure timer 0x80ccc4, delay timer 0x80ccb6, overall timer 0x80ccba, fault timer 0x80ccbc; count bleed-down timer WPRYTM 0x80ccbe to WPRYTMCN 0x807ddc; at the end ARM: completed=0, limiting=1, WPSTFG 0x80ccc0=0, WPACFT=1, LSG lock=1 if LSLOCN 0x807dde. If WPSTFG set -> completed. Clear WPDYFG 0x80ccc2; limit = maximum.
- CRANKING(2)/REENTRY(7)/RUNNING(3)/JUMP_START(6): clear bleed-down timer; overall timer WPTMMX 0x80ccba +1 up to WPMXTMCN 0x807dd8; fault timer WPFUTM 0x80ccbc +1 up to WPFUTMCN 0x807dda while any of 7 fault status&latch pairs (word 3 bits 4/8/0x20/0x40, word 2 bits 2/1, word 6 bit 0x2000 - e2m: active coolant or oil pressure faults); either at max -> complete (off outputs), return. Before the delay (WPDYFG=0): oil pressure timer WPO2TDTM 0x80ccc4 +1 while oil_pressure filtered >= WPO2TDCN 0x807dd4 else 0; > WPO2TMCN 0x807dd6 -> WPDYFG=1, WPO2DY 0x80ccb8 = lookup(coolant temp; record 0x80058e: x 0x60846 WPCQXA / y 0x6085a WPDYTMYA). After: WPDYTM 0x80ccb6 +1 until >= WPO2DY -> complete. Then limit = lookup(engine_rpm_primary; record 0x80059c: x 0x607f2 WPESXA / y 0x6081c WPFLDQYA) while limiting, else maximum.
- Other engine states (4 brake, 5 overspeed, 8 shutdown): nothing changes.
- CM848: none. cm848_updateEngineStartWarmupProtection 0x5055a0 is the EMO AECD emission level cap (blocks 19B2/19B3) - no oil pressure timers, no fuel table; CM848 e2m has no 11EA..11EF records.
- WPSTFG 0x80ccc0 and WPIHFG 0x80ccc8: no writer of 1 in the dumped ROM (only this pair of functions touch them). LSLOFG 0x80a8f4: no reader in the dumped ROM.

## 0x1709e cm550_fuelTemperatureLimitingSecondary -> initializer of engine warmup protection
- asm 0x1709e-0x1711e: clr WPIHFG 0x80ccc8; enable bit 0x2 of 0x803cb8 set -> limiting 0x80ccb2=1, completed 0x80ccb4=0, LSG lock 0x80a8f4=1 if LSLOCN 0x807dde; else limiting=0, completed=1. Builds two lookupTableInterpolation records: 0x80058e {index 2, x 0x60846, y 0x6085a} and 0x80059c {index 2, x 0x607f2, y 0x6081c}. Called once from mc68k_applicationMain (0x8816 step). The 0x36xxx ROM pairs (0x80ccb2, 0x807dd4, 0x6081c, 0x607f2, 0x6085a, 0x60846) are the block bases of 11EA..11EF (parameter id table area).
- No fuel temperature anywhere; "secondary" unsupported.

## 0x3452a cm550_FUN_0003452a -> TWIN of CM848 0x5067bc cm848_loadHourMetersFromEeprom
- asm: move.l 0x803b3e -> 0x80bda4 (key_on_hour_meter, e2m 0004 +0 CMECTR); move.l 0x803b50 -> 0x80ccee (engine_hour_meter, 11BC +0 CMEGTR); rts.
- CM848 0x5067bc: lwz 0x3fd4b2 (EEPROM 0x30) -> stw key_on_hour_meter 0x40a64c; lwz 0x3fd4c4 (EEPROM 0x42) -> engine_hour_meter 0x40a794; blr. Same 2 dword copies, same order, same 0x12 gap between the two EEPROM words (CM550 EEPROM offsets 0x34 / 0x46).
- Callers: CM550 mc68k_applicationMain once (step 0x8714, after mc68k_initializeSerialEepromDriverAndLoadMirror); CM848 cm848_applicationMain once. advanceHourMeters (twin, already shared) counts both.
- The EEPROM words are written back by mc68k_runPowerDownSequence (0x280f4..0x281f8) and restartThroughBootRom (0x11978..0x119e2) in CM550 - as CM848's power-down / reflash restart save.
- => shared name loadHourMetersFromEeprom (both rows). Globals: 0x803b3e eeprom_hour_meter_buffer (undefined) -> key_on_hour_meter_cal dword; 0x803b50 eeprom_engine_run_time_buffer (undefined) -> engine_hour_meter_cal dword (inside 0x803b0a-0x804f93 so _cal; CM848 names). No CM550 e2m record (no 0027 block).

## 0x1cc72 cm550_FUN_0001cc72 -> counterpart of CM848 0x1f17c cm848_calculateThrottle100Fuelings
- asm 0x1cc72-0x1cdf6. Called last in cm550_runEvery4FramesTaskSetPhase1 (20 ms) after runHighSpeedGovernorPid/0x42496; CM848's is in cm848_periodicTaskSet_controlLoop after runHighSpeedGovernorPid / loadHighSpeedGovernorWorkingGainSet / arbitrateGovernedFueling.
- If programmable_power_enable (0x803cb8 bit 0x200) = 0: coolant term d2 = 0 if algorithm_enable_flags_32_cal bit 0x8000 (full_fueling_coolant_temperature_adjustment_enable) clear or a fault pair word 2 bits 2/1/0x10 (status 0x806004 & latch 0x806ac0) set, else cm550_tableLookup2D(record 0x800700: coolant temperature 0x80a336 at +6, engine_rpm_primary at +0xe). 105A +0 0x80d368 = calculateBlendedTableValue(rpm, 400) + d2 floored; 105A +4 0x80d36c = d2 + blended(HSRFBFDP 0x80d654, 400) floored; 105A +2 0x80d36a = tableLookup2D(record 0x8006ea at rpm) -> subtractAndClamp -> + d2 floored. floor = fuel_demand_minimum 0x80800a.
- Always: 105A +8 0x80d370 = blended(rpm, 400) when electronic_smart_power_enable (0x803cac bit 0x10) = 0, else tableLookup2D(0x8006ea) -> subtractAndClamp; floored.
- Does NOT write 105A +6 FSMXBK 0x80d36e (written at 0x1d7b6 by another function). CM848 writes +6 here, adds cold_delta_fuel (algorithm_enable_flags_41 gate) instead of the coolant x rpm table, uses lookupChiMaximumFuelAtSpeed for +4/+6, and forces the 4D interpolation factor to 0 for the ESP branch. => counterpart, not twin.
- Record set-up: 0x1cdf8 cm550_FUN_0001cdf8 builds 0x8006ea / 0x8006f2 / 0x800700 / 0x800708 (other function; not in this batch).

## Enums HIGH_RPM_PROTECTION_STATE / HIGH_RPM_PROTECTION_FLAGS (both firmwares)
- Users: NONE. grep of every frozen CSV (globals, structs, locals, function_definitions) of both firmwares: no row typed with either enum; no member name (TIMER_ACTIVE ... SHUTDOWN_PENDING, MONITORING) appears in either .cpp.
- FLAGS = the J1587 PID 71 (Idle Shutdown Timer Status) byte CM550 builds in insiteCommandByteDispatcher case 0x47 at 0xefa2 (asm 0xefa2-0xf008, into d2):
  0x80 idle_shutdown_timer 0x80d676 != 0 and < idle_shutdown_period_cal 0x803c02 (timer active, SPN 590 analogue)
  0x08 algorithm_enable_flags_3_cal (0x803c9a) bit 0x2 idle_shutdown_enable (function enabled, SPN 591)
  0x04 idle_shutdown_overridden_flag 0x80d672 and 0x803c9a bit 0x4 idle_shutdown_override_enable (override active, SPN 592)
  0x02 engine_shutdown_command_flag 0x80d28c and idle_shutdown_timer = 0 (engine shut down by the idle timer, SPN 593)
  0x01 idle_shutdown_warning_lamp_request 0x80d67a (driver alert mode, SPN 594)
  The byte is a local (local_6 high byte, shared by every PID of the dispatcher), so an enum cannot be applied to it without mislabelling the other PIDs.
- STATE: its header names global high_rpm_protection_state (CM550 0x80cc6c, untyped, in old struct high_rpm_protection_t 0x80cc6a-0x80cc72) and 0x16dd4. 0x16dd4 has no state word; 0x80cc6a..0x80cc72 (and 0x80c994/0x80c996/0x8036fc/0x8032c6/0x8002e8 high_rpm_*) have NO 4-byte address occurrence anywhere in the dumped ROM (raw byte search) and no decompile use. Values 0-4 do not match IDLE_SHUTDOWN_STATE (0-5: RESET COUNT WARNING DELAY OVERRIDE SHUTDOWN, already typed on idle_shutdown_state 0x80d674).
- CM848: SCI command 0x47 (cm848_sciCommand20Callback 0x51f0b8) is an empty case; no idle shutdown code is named; the CM848 rows are copies of CM550's with no user.
- Also misnamed (out of scope): INSITE_PARAM_CODE 0x47 HIGH_RPM_PROTECTION_STATUS in both enums.csv (enum not applied to insite_parameter_id, a byte).

## Extra evidence (second pass)
- 0x1c0d4 is reached by bsr.w at 0x1c190 right after jsr 0x30c3c (cm550_runFuelLimitChains) in cm550_selectFinalFueling; no absolute reference. CM550 chain = CM848 cm848_processProtectionLimits order (initializeFuelLimitChains, applyPowerTakeOffTorqueLimit, ...); only applyPowerTakeOffTorqueLimit lowers the torque limit in the dumped code (the chain's 0x45252 / 0x455c8 are not dumped).
- RAM dump: 0x80d338 = 0xffff, 0x80d33a = 40 (reset state); 0x80db1a = 330 lb-ft; NLFL 88; 105A +0/+2/+8 = 1619, +4/+6 = 1436.
- 0x80db1a writer = cm550_FUN_000269f2 (maximum_torque_map_lookup at engine rpm and alpha, floor 1) / init 1 in cm550_FUN_00026a2e (called just before 0x1c308 in the start-up list) = CM848 cm848_calculateFuelDemandFilter 0x29c98 / cm848_initFuelDemandFilterDimensions 0x29de0 writing 0x40aee6 fuel_demand_filter_dimension. Candidate shared name maximum_torque_at_current_rpm (e2m 1461 +0 MTMPRPFL / CM848 MT_Max_Torque_At_RPM_Ftlb).
- 105A in CM848: +4 engine_speed_limit_ramped_maximum_fuel_quantity (FSMXBFDP), +6 engine_speed_limit_reference_maximum_fuel_quantity (FSMXBK), +8 throttle_100_fueling_without_programmable_power (FSMTFLNP). CM550 0x80d654 = 1063 +10 HSRFBFDP = CM848 engine_speed_limit_ramped.
- 0x1cc72 lookups: 0x800700 = cold temperature fuel increment (x FLCDTPXA coolant 0x6124a, y FLCDESYA speed 0x6125e, z FLCDICZA 0x6126a; enable 5DCLAJEN 'addition of coolant temp fuel to 100% fueling') = CM550's in-line analogue of CM848 cold_delta_fuel; 0x8006ea = steady state 4D fueling table at throttle 400 (5DFL01XA/YA/ZA), records built by cm550_FUN_0001cdf8 (called from cm550_masterSubsystemInit).
- Warmup protection dump (engine stopped, key on): WPRYTM 0x80ccbe = 3600 = WPRYTMCN -> armed: WPLMFG 1, WPSSFG 0, WPACFT 1, LSLOFG 0x80a8f4 1 (LSLOCN 1), WPTQLM = 5888 (max, engine stopped). Cals: WPO2TDCN 1024 (8 psig), WPO2TMCN 10 (0.5 s), WPMXTMCN 1200 (60 s), WPFUTMCN 120 (6 s), WPRYTMCN 3600 (3 min), LSLOCN 1.
- WP* records exist only in the CM550-family e2m files (originals/), none in CHR/ (CM848).
- CM848 0x5067bc call site: cm848_applicationMain after the analog channel initializers (same start-up slot as CM550's after cm550_initializeAnalogSensorChannels / mc68k_initializeDiscreteOutputDrivers).
- Also old-pass leftovers (out of scope): DIAGNOSTIC_SYSTEM_FLAGS_1 0x02/0x04 'high RPM protection' = algorithm_enable_flags_3_cal idle_shutdown_enable / idle_shutdown_override_enable; INSITE_PARAM_CODE 0x47 HIGH_RPM_PROTECTION_STATUS (both firmwares); struct high_rpm_protection_t (no typed global).

## Proposed names (describer)
- 0x1c0d4 cm550_convertTorqueDerateTorqueLimitToFuelLimit (counterpart of CM848 0x1e4e8; CM848 could take cm848_convertTorqueDerateTorqueLimitToFuelLimit - bare 'Protection' today, L4 overlap)
- 0x1c308 cm550_initializeTorqueDerateTorqueLimit (no CM848 counterpart)
- 0x3452a loadHourMetersFromEeprom (twin; CM848 0x5067bc row changes too)
- 0x16dd4 cm550_runEngineWarmupProtection (none)
- 0x1709e cm550_initializeEngineWarmupProtection (none)
- 0x1cc72 cm550_calculateThrottle100Fuelings (counterpart of CM848 0x1f17c)
- STATE enum anchor: 0x80cc6a-0x80cc72 (high_rpm_protection_fault_flag / _state / _timer / _warning_flag rows, struct high_rpm_protection_t) lie INSIDE the serial EEPROM write queue data byte array 0x80c7a8 + i (i < 0x500, cm550_parameterCircularBufferWrite: '% 0x500', move.b (a3)+,(0,a0,d0.w) at 0x16c92 with a0 = 0x80c7a8). No 4-byte occurrence of any address 0x80c7a9..0x80cca7 in the ROM. So the anchor rows are stale names, not a state word.
