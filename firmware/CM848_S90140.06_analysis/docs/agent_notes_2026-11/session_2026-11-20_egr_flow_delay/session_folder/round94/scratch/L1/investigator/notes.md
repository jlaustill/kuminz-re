# L1 investigator notes (round 94)

## 0x16dd4 cm550_highRpmEngineProtectionStateMachine -> engine warmup protection state machine (CONFIRMED)
- called by cm550_runEvery10FramesTaskSetPhase0 (0x1b6b4) every 10 frames (50 ms).
- disasm 0x16dd4-0x1709c: a5=0x80ccb4 (WPSSFG completed), a3=0x80ccb2 (WPLMFG limiting), a4=0x80d0c8 engine_state.
  - enable bit 0x803cb8 & 2 (algorithm_enable_flags_18_cal.engine_warmup_protection_enable, WPEAFG) clear, or completed and
    engine_state != 1, or WPIHFG 0x80ccc8 != 0 -> completed=1 limiting=0, clr 0x80a8f4 (LSLOFG), clr 0x80ccca (WPACFT),
    limit 0x80ccc6 = fuel_demand_maximum (0x808004); rts.
  - engine_state 1 STOPPED: clr 0x80ccc4 WPO2TDTM, 0x80ccb6 WPDYTM, 0x80ccba WPTMMX, 0x80ccbc WPFUTM; 0x80ccbe WPRYTM (MIN)
    counts up to 0x807ddc WPRYTMCN (oil drain back time); at the limit: completed=0 limiting=1 0x80ccc0 WPSTFG=0
    0x80ccca WPACFT=1 and, when 0x807dde LSLOCN != 0, 0x80a8f4 LSLOFG = 1. if WPSTFG != 0 -> completed=1 limiting=0
    WPACFT=0. clr 0x80ccc2 WPDYFG. limit = fuel_demand_maximum.
  - engine_state 2/7/3/6: clr WPRYTM; WPTMMX ++ up to 0x807dd8 WPMXTMCN; on any active+latched fault (word 3 bits
    4/8/0x20/0x40, word 2 bits 2/1, word 6 bit 0x2000) WPFUTM ++ up to 0x807dda WPFUTMCN. either at its limit -> end.
    WPDYFG 0: oil pressure 0x80a30a >= 0x807dd4 WPO2TDCN -> WPO2TDTM ++ else clr; WPO2TDTM > 0x807dd6 WPO2TMCN -> WPDYFG=1,
    table 0x80058e input 0x800594 = coolant 0x80a336 -> WPO2DY 0x80ccb8.
    WPDYFG 1: WPDYTM 0x80ccb6 ++ up to WPO2DY; at it -> end (completed=1 limiting=0 LSLOFG=0 WPACFT=0).
    limiting 0 -> limit = fuel_demand_maximum; else 0x8005a2 = engine_rpm_primary (0x80ccf6), limit = table 0x80059c.
- CM848: no counterpart (cm550_applyEngineWarmupProtectionFuelLimit plate: CM848 has no such step) -> standalone cm550_.

## 0x1709e cm550_fuelTemperatureLimitingSecondary -> engine warmup protection initializer (CONFIRMED)
- called once from the start-up sequence (mc68k_applicationMain area, line 29388, after cm550_initializeLowSpeedGovernor).
- clr WPIHFG 0x80ccc8; enabled -> limiting=1 completed=0, LSLOCN -> LSLOFG=1; disabled -> limiting=0 completed=1.
  sets up the two table_interp_args_t: 0x80058e {index 2, x 0x60846 WPCQXA (11EF coolant axis), y 0x6085a WPDYTMYA (11EE)}
  and 0x80059c {index 2, x 0x607f2 WPESXA (11ED rpm axis), y 0x6081c WPFLDQYA (11EC fueling derate values)}.
- no fuel temperature anywhere.

## e2m 11EA records (resolved by e2m_block_addresses.py --firmware cm550 11EA)
+4 WPDYTM 0x80ccb6 SEC 0.05 'TIME COUNTING AGAINST RIFLE_TO_TURBO_DELAY_TIME' (no row)
+6 WPO2DY 0x80ccb8 SEC 0.05 'CALCULATED TIME BASED ON COOLANT_TEMPERATURE TO ALLOW OIL TO RE[ach turbo]' (no row)
+8 WPTMMX 0x80ccba SEC 'TIMER COUNTING AGAINST MAX_OVERALL_TIME_OUT' (no row)
+A WPFUTM 0x80ccbc SEC 'TIMER COUNTING AGAINST FAULT_TIME_OUT' (no row)
+C WPRYTM 0x80ccbe MIN 'TIMER COUNTING AGAINST OIL_BLEEDDOWN_TIME' (no row)
+E WPSTFG 0x80ccc0 T/F 'RUN_STATE HAS BEEN ACHIEVED DURING EXECUTION OF ENGINE WARMUP ALGO' (no row)
+10 WPDYFG 0x80ccc2 T/F 'FLAG INDICATING THAT RIFLE_TO_TURBO_DELAY_TIME DELAY STARTED' (no row)
+16 WPIHFG 0x80ccc8 T/F 'ENGINE WARMUP PROTECTION ALGORITHM INHIBITED WHEN 1' (no row)
+18 WPACFT 0x80ccca T/F 'WARMUP PROTECTION LIMITING TORQUE/RPM IF 1' (no row)
1045 +4 LSLOFG 0x80a8f4 'WHEN 1 TRANSITION FROM LSG TO NO ADJUST FUEL IS PROHIBITED' (no row)
11EB +A LSLOCN 0x807dde 'CALIBRATIBLE OPTION TO ALLOW LSG_LOCK_FLAG TO LOCK LOW IDLE GOV.' (no row)
1297 +0 WPMXRS 0x807dd2 'HIGHEST ROAD SPEED THAT WILL ALLOW ENGINE WARMUP PROTECTION' (no row)

## 0x1c0d4 cm550_FUN_0001c0d4 -> torque derate torque limit to fuel conversion (CONFIRMED role; COUNTERPART of CM848 0x1e4e8)
- disasm 0x1c0d4-0x1c150: a2=0x80db1a (MTMPRPFL max torque at current rpm), a3=0x80d33a torque_derate_torque_limit_state,
  a4=0x80dec8 torque_derate_fuel_quantity, a5=0x80db1c no_load_fuel_quantity.
  cmpi.w #1,(a2); bcc -> if 0 store 1. jsr 0x35076 (cm550_scaleByRatioSigned) (0x80d338 torque limit, 0x80d370 FSMTFLNP - no load, max torque)
  + no load; bge -> else 0; cmp.l with torque_derate_fuel_quantity (bge skip) -> store word + copy state (a3) to 0x80deca.
  THEN move.w #0xffff,(0x80d338); move.w #0x28,(0x80d33a) (reset to no limit / FUELING_STATE_NO_DERATE 40).
- caller: cm550_selectFinalFueling (0x1c152) after cm550_runFuelLimitChains (only when torque_derate_override_enable = 0).
- CM848 0x1e4e8 cm848_calculateProtectionRateLimited: same conversion steps (0 -> 1 guard on 0x40aee6, (0x40a89f - 0x40aeec) x 0x40a2d8 /
  0x40aee6 via 64-bit divide 0x570f0, + no load, clamp >= 0, min into 0x40afac + state 0x40a2da -> 0x40afae) but NO reset step;
  its caller cm848_arbitrateRequestedFueling 0x1e5a4 resets torque_derate_torque_limit 0xffff / NO_DERATE BEFORE
  cm848_processProtectionLimits. -> one extra step in CM550 + reset placement differs -> counterpart, cm550_ prefix.
- CM848 name cm848_calculateProtectionRateLimited is wrong (no rate limit; bare 'protection') - lead for L4.
- CM848 0x40aee6 fuel_demand_filter_dimension = maximum torque at current engine speed (written by 0x29c98 from maximum_torque_map_*,
  init 1 by 0x29de0) - same role as CM550 0x80db1a MTMPRPFL (e2m 1461 +0; CM848's 1461 not in the dumped table).

## 0x1c308 cm550_FUN_0001c308 -> start-up reset of the torque limit (CONFIRMED)
- disasm: move.w #0xffff,(0x80d338); move.w #0x28,(0x80d33a); rts. called once from start-up (line 29560, after cm550_FUN_00026a2e
  = the max torque map initializer). CM848 has no such function (its per-pass reset sits in cm848_arbitrateRequestedFueling) -> standalone.

## 0x1cc72 cm550_FUN_0001cc72 -> 100 percent throttle fuelings (CONFIRMED; COUNTERPART of CM848 0x1f17c cm848_calculateThrottle100Fuelings)
- called last by cm550_runEvery4FramesTaskSetPhase1 (20 ms).
- disasm 0x1cc72-0x1cdf6: programmable power bit 0x803cb8 & 0x200 clear -> cold offset d2 = 0 unless 0x803cd4 & 0x8000
  (full_fueling_coolant_temperature_adjustment_enable) and no active+latched fault word 2 bits 2/1/0x10, then d2 = tableLookup2D
  0x800700 (coolant 0x80a336 x rpm). 0x80d368 FSMXTHFL = 0x1cb76(rpm,400); 0x80d36c FSMXBFDP = 0x1cb76(0x80d654 HSRFBFDP,400)+d2,
  floor fuel_demand_minimum; 0x80d36a FST0MXFL = tableLookup2D 0x8006ea (rpm) then 0x1e02a; +d2 to both, floor.
  ESP bit 0x803cac & 0x10 set -> 0x80d370 FSMTFLNP = tableLookup2D 0x8006ea (the low HP / tau 0 table) + 0x1e02a + floor; else
  0x1cb76(rpm,400); floor.
- CM848 0x1f17c: cold_delta_fuel (flags 41 bit), maxFuelCurve, also +6 FSMXBK, chi max-fuel lookups, ESP forces interpolation factor 0
  -> different steps -> counterpart.
- 0x80d370 accesses: 0x1c102 move.w, 0x1cc7c (a3 word), 0x1cdc4 pea -> word. e2m 105A +8 FSMTFLNP = CM848 0x40a89f
  throttle_100_fueling_without_programmable_power. 0x80d36c = 105A +4 FSMXBFDP = CM848 0x40a89b engine_speed_limit_ramped_maximum_fuel_quantity.
- 0x80d36e (105A +6 FSMXBK) is written at 0x1d7b6 by another function (not 0x1cc72).

## 0x3452a cm550_FUN_0003452a -> TWIN of CM848 0x5067bc cm848_loadHourMetersFromEeprom (CONFIRMED) -> shared loadHourMetersFromEeprom
- CM550 disasm: move.l (0x803b3e),(0x80bda4) key_on_hour_meter; move.l (0x803b50),(0x80ccee) engine_hour_meter; rts (0x3453e).
- CM848 disasm: lwz 0x3fd4b2 key_on_hour_meter_cal -> stw 0x40a64c key_on_hour_meter; lwz 0x3fd4c4 engine_hour_meter_cal -> stw 0x40a794; blr.
- same 2 steps same order; both directly after the twin advanceHourMeters (CM550 0x34512 / CM848 0x506780); both called once from the
  application start-up right after the input channel initializers (CM550 line ~29259 after mc68k_initializeDiscreteOutputDrivers;
  CM848 cm848_applicationMain after cm848_initializeAmbientAirTemperatureChannel).
- EEPROM dump: offset 0x34 = 227512040 = RAM 0x803b3e; offset 0x46 = 226203089 = RAM 0x803b50 = engine_hour_meter (engine stopped);
  key_on_hour_meter live 227515497 (advanced since the last save). restartThroughBootRom 0x1192a saves both (0x1199a / 0x119e0 move.l),
  0x28164 / 0x281f6 the other saver. -> globals 0x803b3e key_on_hour_meter_cal dword, 0x803b50 engine_hour_meter_cal dword (CM848 names).

## HIGH_RPM_PROTECTION_STATE / HIGH_RPM_PROTECTION_FLAGS (both firmwares) -> leftovers, no users -> delete
- grep of global_variables / structure_definitions / function_definitions / local_variables(_actual) / arrays + both .cpp: NO row is
  typed with either enum and no .cpp line shows a member. ApplyEnums.java only creates the types -> they have no effect.
- CM848 copies came from commit 1100dce0 "Port 115 fuel/protection/sensor enums from CM550 to CM848" (no CM848 code evidence);
  CM848 has no idle shutdown machine (CM550 idle_shutdown_state comment).
- FLAGS masks 0x80/0x08/0x04/0x02/0x01 = the J1587 PID 71 (Idle Shutdown Timer Status) byte built in d2 at CM550 0xefa2
  (insiteCommandByteDispatcher, insite_parameter_id == 0x47): 0x80 idle_shutdown_timer 0x80d676 != 0 and < 0x803c02 period;
  0x08 0x803c9a & 2 idle_shutdown_enable; 0x04 0x80d672 overridden && 0x803c9a & 4 override enable; 0x02 0x80d28c
  engine_shutdown_command_flag && timer == 0; 0x01 0x80d67a idle_shutdown_warning_lamp_request. = J1939 SPN 590 / 591 / 592 / 593 / 594
  (PGN 65252 Shutdown) wording. The byte is a register local, so no row could carry the enum.
- STATE 0-4 = an old misreading of the idle shutdown machine; superseded by IDLE_SHUTDOWN_STATE (0-5, e2m 10CD ISST; round 94).
- related leftovers (no absolute reference in the dumped ROM, any alignment 0x80cbf0-0x80ccb2): CM550 globals 0x80cc6a / 0x80cc6c /
  0x80cc6e / 0x80cc72 high_rpm_protection_*; 0x8036fc high_rpm_protection_initial_timer; 0x80c994 high_rpm_protection_triggered_flag;
  struct high_rpm_protection_t (structure_definitions 272-276, no global uses it). INSITE_PARAM_CODE 0x47 HIGH_RPM_PROTECTION_STATUS
  is J1587 PID 71; INSITE_PARAM_CODE itself has no users either.

## callers (ROM search for the 4-byte address + bsr scan)
0x16dd4 jsr @0x1b6c0 only (task set, then rts); 0x1709e jsr @0x28810 only (applicationMain); 0x1c0d4 bsr.w @0x1c190 only
(selectFinalFueling); 0x1c308 jsr @0x28970 only (applicationMain, last call before move.w (a7)+,sr); 0x1cc72 jsr @0x1b5c8 only;
0x3452a jsr @0x2870e only (applicationMain). No pointer tables. d0 unused after 0x16dd4 / 0x1709e -> function_definitions return void.

## PROPOSED NAMES
- 0x16dd4 cm550_runEngineWarmupProtection (standalone; CM848 CHR e2m has no WP* record)
- 0x1709e cm550_initializeEngineWarmupProtection (standalone)
- 0x1c0d4 cm550_convertTorqueDerateTorqueLimitToFuelLimit (counterpart of CM848 0x1e4e8)
- 0x1c308 cm550_initializeTorqueDerateTorqueLimit (standalone: CM848 writes the pair only in 0x1e5a4 and applyPowerTakeOffTorqueLimit)
- 0x1cc72 cm550_calculateThrottle100Fuelings (counterpart of CM848 0x1f17c)
- 0x3452a loadHourMetersFromEeprom (twin; CM848 0x5067bc cm848_loadHourMetersFromEeprom -> loadHourMetersFromEeprom)

## GLOBALS (all word unless said; all accesses .w in abs_refs)
0x80ccb6 engine_warmup_protection_rifle_to_turbocharger_delay_timer (WPDYTM)
0x80ccb8 engine_warmup_protection_rifle_to_turbocharger_delay_time (WPO2DY)
0x80ccba engine_warmup_protection_overall_timer (WPTMMX)
0x80ccbc engine_warmup_protection_sensor_fault_timer (WPFUTM)
0x80ccbe engine_warmup_protection_oil_drain_back_timer (WPRYTM; dump 3600 = the limit)
0x80ccc0 engine_warmup_protection_run_state_achieved_flag (WPSTFG; no writer of 1 in dumped ROM)
0x80ccc2 engine_warmup_protection_rifle_to_turbocharger_delay_started_flag (WPDYFG)
0x80ccc4 engine_warmup_protection_oil_pressure_timer (WPO2TDTM; rename)
0x80ccc8 engine_warmup_protection_inhibit_flag (WPIHFG; no writer of 1 in dumped ROM)
0x80ccca engine_warmup_protection_torque_or_speed_limiting_flag (WPACFT; no reader in dumped ROM; not set at start-up)
0x80a8f4 low_speed_governor_lock_flag (1045 +4 LSLOFG; no reader in dumped ROM)
0x807dde engine_warmup_protection_low_speed_governor_lock_enable (11EB +A LSLOCN; dump 1)
0x807dd4/6/8/a/c renames: ..._oil_pressure_threshold / _oil_pressure_time / _maximum_time / _maximum_time_with_sensor_fault / _oil_drain_back_time
0x803b3e key_on_hour_meter_cal dword; 0x803b50 engine_hour_meter_cal dword
0x80d370 throttle_100_fueling_without_programmable_power word (105A +8; CM848 0x40a89f)
0x80d36c engine_speed_limit_ramped_maximum_fuel_quantity (105A +4 FSMXBFDP; CM848 0x40a89b)
0x80d654 engine_speed_limit_ramped (1063 +10 HSRFBFDP; selectEngineSpeedLimit 0x1d740-0x1d754 ramps it by 0x808138 HSRFRMRT toward 0x80d648 HSRFBEDP, drops at once; CM848 0x40a308)
0x80db1a maximum_torque_at_current_engine_speed (1461 +0 MTMPRPFL) + CM848 0x40aee6 (fuel_demand_filter_dimension) same name

## LEADS (not this batch)
- 0x80d36e (105A +6 FSMXBK) no row: written in selectEngineSpeedLimit @0x1d7b6 = 0x1cb76(0x80d64e HSBKRFAE, 400) floored -> CM848
  engine_speed_limit_reference_maximum_fuel_quantity; 0x80d64e = CM848 engine_speed_limit_reference.
- lookupTableInterpolation 0x34de0 reads (0xc,a2) = a no-interpolation word: table_interp_args_t (12 bytes) lacks +12; the warmup
  descriptors 0x80058e / 0x80059c are 14-byte records (coolant -> delay time; engine speed -> fuel limit) for L3.
- cm550_calculateBlendedTableValue 0x1cb76 = CM550's maximum fuel curve (counterpart of cm848_calculateMaximumFuelCurve 0x1f03c).
- CM848 0x1e4e8 cm848_calculateProtectionRateLimited misnamed (no rate limit) - L4; CM848 0x29c98 cm848_calculateFuelDemandFilter /
  0x29de0 cm848_initFuelDemandFilterDimensions = maximum torque map lookup / its initializer.
- INSITE_PARAM_CODE (both, unused) values are J1587 PIDs (0x47 = PID 71 idle shutdown timer status, 0x4a = PID 74, 0x53 = PID 83 ...).

## extra evidence (late)
- mc68k_runPowerDownSequence 0x27f9c saves key_on_hour_meter -> 0x803b3e (0x280e2-0x2816e, 4 bytes via 0x16c3c, waits until the mirror
  matches, up to 1000 tries) and engine_hour_meter -> 0x803b50 (0x28170-0x28200). restartThroughBootRom 0x1192a the same.
- 0x80d36c readers: cm550_calculateGovernorDroopSpeed 0xfaca, 0x184c6, selectEngineSpeedLimit 0x1d884, cm550_calculateEngineLoadPercentages
  0x26d96 / 0x26dc4 (CM848's engine_speed_limit_ramped_maximum_fuel_quantity readers include selectEngineSpeedLimit and
  cm848_calculateEngineLoadPercentages).
- 0x80d654 init: initializeEngineSpeedLimitDefaults 0x1d958 move.w (0x803ba0),(0x80d654); ramp in selectEngineSpeedLimit 0x1d740-0x1d754.
- CM848 0x1f17c stores 0x40a89d (+6) / 0x40a89b (+4) / 0x40a89f (+8) itself; CM550 writes +6 (0x80d36e) in selectEngineSpeedLimit 0x1d7b6.
- function_definitions: add 'return,,void' for 0x16dd4 and 0x1709e (callers 0x1b6c0 jsr+rts / 0x28810 jsr+jsr ignore d0).
- generated firmware_types.hpp (both) list the two enums; nothing else references them.
STATUS: all six functions decided; enums -> delete; globals listed above. Ready for StructuredOutput.
- 0x80ccc6 engine_warmup_protection_fuel_limit: stores only in 0x16dd4 (0x16e22 / 0x16eb2 / 0x16fd4 / 0x1706a / 0x17092), read only by 0x17120.
- enable bit 0x803cb8 & 2 read only at 0x16df0 / 0x16e32 (0x16dd4) and 0x170c0 (0x1709e).
- engine_state 4 / 5 / 8 (brake / overspeed / shutdown): 0x16ed4 bne.w 0x17098 -> the pass changes nothing.
FINAL: output written via StructuredOutput (round 94 L1 investigator).
