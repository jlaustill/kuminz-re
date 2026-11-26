# R5 investigator notes (round 97) - CM550 engine protection
(started 2026-11-25; no earlier run found in this folder)

## First pass observations (decompiled bodies)
- 0xc66a cm550_rpmHistogramAndProtectionStatisticsAccumulator: actually ALTITUDE DERATE fuel limit (altitude_derate_enable bit, 2D lookup rpm x ambient pressure) - verify
- 0xd5e6 cm550_initBoostProtectionSystem: clears cruise_control_active_flag, road speed, gear ratio, sets engine_speed_limit_source_2 - verify
- 0x3458c cm550_engine_protection_coordinator: user_fueling_state arbitration chain - verify
- 0x30b04 cm550_protectionLimitValueInit: empty body in decompile - disassemble

## Tables (proven from 0x1873e init + every loop)
- settings (configuration) records: 0x807032 + 36n, n=0..8, end 0x807176 (loops: cmpa #0x807176 / lea 0x144). CM848 type engine_protection_channel_configuration_t (36 bytes) has the SAME field offsets.
- state records: 0x80d0dc + 46n, end 0x80d27a. CM848's engine_protection_channel_state_t is 62 bytes (+0x2e/+0x36 log entry copies); CM550's is 46 -> needs its own cm550_ type.
- history records: 0x8057c0 + 30n, end 0x8058ce (= engine_protection_active_fault_index). CM848 engine_protection_channel_history_t 30 bytes, same offsets.
- fault logs: 5 entries x 8 bytes (time dword, extreme word, duration word); CM848 engine_protection_fault_log_entry_t.
- channel order (init 0x1873e, sensor pointers): 0 coolant level 0x8091e6 (mask 1), 1 coolant temperature 0x80a336, 2 intake manifold temperature 0x80a26a, 3 oil pressure 0x80a30a (thresholds 0x80dabe / 0x80dac0, no max ptr), 4 water in fuel 0x80a46a, 5 boost 0x80a320, 6 engine sync fuel pressure 0x80a2f4, 7 fuel temperature 0x80a254, 8 ambient air pressure 0x80a3ba
- enable bit = 0x70 + 4n + k (k 0 fueling limit, 1 rpm limit, 2 shutdown, 3 restart) - established

## Functions (verified in asm)
- 0x18620: called only at 0x1bb9a (executiveFrameInterruptHandler frame 15 of 40); EPEN clear -> engine_speed_limit_fault_derate = max rated speed, fault_derate_fuel_limit = fuel_demand_maximum, active 0, approaching 0; else switch on 0x80060e (0..4): 0x18a26 / 0x18cb6 / 0x19702 / 0x18e0c+0x1952c / 0x18fcc; index++ wraps at 5. CM848 0x507c44 COUNTERPART (CM848 also sets engine_protection_timer_state 3, runs precrank exam each pass, latches override in task 1).
- 0x186ae: ramp of severity index; TWIN of CM848 0x507d50 cm848_rampEngineProtectionSeverityIndex (same params config/state/history/selector, same offsets 6/8, 2/4, 6/8, cap 0x100, floor 0) - verify CM848 asm
- 0x18708: (in-min)<<8 / (max-min) clamp 0..0x100 signed, inline divs.l; CM848 0x507dc0 has in==min test + cm848_clampedDivisionWithBounds -> COUNTERPART
- 0x1873e: called once from mc68k_applicationMain 0x28732; builds 9 channel state records + calls initializeFaultDerateEngineSpeedLimit, cm550_initShutdownLimitVariables, 0x192e0, task index 0. CM848 hpcr_initializeEngineProtection COUNTERPART (1 channel, 0x1000 flag picks rpm log, other resets)
- 0x18968: past-threshold test, UNSIGNED (bcs/bcc at 0x18a08/0x18a14), selects 0/2/3 only (no 1), switch formula ((in & mask)!=0) == (flags&0x10 != 0); CM848 0x507ebc signed, select 1 = max ptr, unwired switch case -> COUNTERPART
- 0x18a26: per channel errors_allowed(+0x16)==0 -> clear +6/+8; flags&0x101 -> past(c,s,0,0) ? saturating ++ +6 : 0; flags&0x402 -> past(c,s,1,0) ... +8. TWIN of CM848 0x50802c (verify asm)
- 0x18ac4: called once from mc68k_applicationMain 0x28738 (right after 0x1873e): EPEN+EPSOEN+EPRYEN, channel 0x8058ce != 0xff/3, count 0x8058d0 >= max 0x807f3c; bits 0x70+4n+2/+3; flags&1 / &2 past -> state+0x18 (precrank error)=1, 0x80d28a=1. CM848 0x508130 COUNTERPART (CRANKING test each pass, channel 4, bit 0x80)
- 0x18c1c: restart severity indexes, TWIN candidate of CM848 0x50832c (flags 1/0x40/2, 0x100)
- 0x18cb6: loop restart severity (bit base 0x70; CM848 0x80) -> COUNTERPART of 0x5084b4
- 0x18dae: channel 3 (CM848 4 + override path) -> COUNTERPART of 0x508408; round-96 name OK
- 0x192e0: 0x80061e = 0x8058ce; clr 0x80061c. CM848 cm848_resetEngineProtectionShutdownState does more -> COUNTERPART; round-96 name OK (check 0x18fcc use)
- 0x192f2: more-extreme test UNSIGNED (bls 0x1930c / bcc 0x19320); CM848 0x508f24 signed? -> check
- 0x19332: record fault log entry (current pointers 0x800622/626/62a); extreme start 0xffff (flag 8) / 0; sets fault bit in 0x806000[] AND 0x806040[] under sr 0x700. CM848 0x508f64 starts 0x7fff/0x8000, one array, copies entry -> COUNTERPART
- 0x19436: close fault log entry: needs 0x806000 bit set AND 0x806040 bit clear, clears 0x806000 bit (sr 0x700), closes the open entry (duration = key_on_hour_meter low - time low), index (idx+1)%5. CM848 0x5090fc needs fault_registered, clears detected+registered, copies entry -> COUNTERPART
- 0x1952c: TWIN of CM848 0x509278 cm848_logEngineProtectionChannelFaults (verified both asm: while-loop guard first, start monitor arming, precrank shortcut, 0x1000 shared log branch, 0xc extremity; only engine speed var and state stride differ)
- 0x186ae TWIN of 0x507d50 (CM848 lhz + cmpw = unsigned 16-bit, same as CM550 bls/bcc)
- 0x18a26 TWIN of 0x50802c (CM848 cmplw/ble loop guard first = while loop like CM550)
- 0x18c1c TWIN of 0x50832c (same flags 1/0x40/2, 0x100, interpolate(*in,*min,*max))
- 0x192f2 COUNTERPART of 0x508f24: CM848 cmpw on sign-extended args (signed), CM550 bls/bcc (unsigned)
- 0x30b04: empty interrupt handler (movem save/restore d0/d1/a0/a1 + rte); NO reference in dumped ROM (abs/pcrel/raw); 4 identical unreferenced stubs at 0x19ca0 0x1a1d6 0x1a73c 0x1a950
- 0x3458c: TWIN of CM848 0x42918 cm848_resetEngineOperatingMode (user fueling state FSDSFLST chain: save prev, clear, 7 selectors in the same order, prev to #3/#5/#6); both called from runEvery4FramesTaskSetPhase1. Shared name proposal selectUserFuelingState
- 0xc66a: altitude derate fuel limit (ATFLLM 0x80a922): enable bit algorithm_enable_flags_1 0x20 + RUNNING, 2D lookup rpm x ambient pressure 0x80a3ba, or default fueling 0x807abc above 0x807aba when ambient pressure fault bits (0x806002 bits 2/3 with enable) -> COUNTERPART of cm848_calculateAltitudeDerateFuelLimit 0x502464 (far larger); name cm550_calculateAltitudeDerateFuelLimit; caller cm550_runEvery10FramesTaskSetPhase7
- 0xd5e6: clears 117D CRSS/CRRF/VSFTAVVS/GRFTGRRA/GROGSS, ZVLMES = max rated speed; CM848 0x5031b4 cm848_initializeVehicleSpeedAndCruiseState does the same + j1939_anti_theft_status_transmit_state -> COUNTERPART; name cm550_initializeVehicleSpeedAndCruiseState
- 0x18f86 incrementDiagnosticCounters = shape of CM848 cm848_countEngineProtectionShutdownTime (lead, not in batch)
- e2m: config blocks 10B7/112B-1132 (subfile 8), state 10B0/114F-1156 (subfile 0), history 10B2/1140-1147 (subfile 7), logs 10DA (subfile 6); all channels same layout; all U
- table refs: only bases (+ 0x80581a word write at 0x1987c, 0x8057c2+idx at 0x190a2) from code; the rest from parameter_id_table entries -> struct arrays safe
- no-ref junk rows inside WIF rpm fault log: 0x805670 dtc_active_fault_count, 0x805676 dtc_timestamp_array

## Decisions (names all checked unique in both function_renames.csv / CM550 global_variables.csv / structure_definitions.csv)
Functions:
- 0x18620 -> cm550_runEngineProtectionScheduler (counterpart cm848_runFaultDerateScheduler 0x507c44)
- 0x186ae -> rampEngineProtectionSeverityIndex (TWIN 0x507d50; CM848 row changes too)
- 0x18708 -> cm550_interpolateEngineProtectionSeverity (counterpart 0x507dc0)
- 0x1873e -> cm550_initializeEngineProtection (counterpart hpcr_initializeEngineProtection 0x507e20)
- 0x18968 -> cm550_isEngineProtectionInputPastThreshold (counterpart 0x507ebc)
- 0x18a26 -> countEngineProtectionOverLimitDurations (TWIN 0x50802c)
- 0x18ac4 -> cm550_examineEngineProtectionBeforeCranking (counterpart 0x508130; CM550 runs once at start-up from mc68k_applicationMain 0x28738)
- 0x18c1c -> updateEngineProtectionRestartSeverityIndexes (TWIN 0x50832c)
- 0x18cb6 -> cm550_updateEngineProtectionRestartSeverity (counterpart 0x5084b4)
- 0x18dae keep cm550_updateEngineProtectionRestartLimitationCommands (counterpart 0x508408)
- 0x192e0 keep cm550_initializeEngineProtectionShutdownCounting (counterpart part of 0x508de8)
- 0x192f2 -> cm550_isEngineProtectionInputMoreExtreme (counterpart 0x508f24, signedness)
- 0x19332 -> cm550_recordEngineProtectionFaultLogEntry (counterpart 0x508f64)
- 0x19436 -> cm550_closeEngineProtectionFaultLogEntry (counterpart 0x5090fc)
- 0x1952c -> logEngineProtectionChannelFaults (TWIN 0x509278)
- 0x30b04 -> cm550_emptyInterruptHandler (standalone, unreferenced)
- 0x3458c -> selectUserFuelingState (TWIN 0x42918 cm848_resetEngineOperatingMode)
- 0xc66a -> cm550_calculateAltitudeDerateFuelLimit (counterpart 0x502464)
- 0xd5e6 -> cm550_initializeVehicleSpeedAndCruiseState (counterpart 0x5031b4)
Types: engine_protection_channel_configuration_t (shared name, CM550 word fields), cm550_engine_protection_channel_state_t (46 bytes), engine_protection_channel_history_t (shared name), engine_protection_fault_log_entry_t (shared name, extreme word)
Tables: 0x807032 engine_protection_channel_configuration_table [9]; 0x80d0dc engine_protection_channel_state_table [9]; 0x8057c0 engine_protection_channel_history_table [9]
Flat rows absorbed: 158 (config) + 153 (state) + 99 (history) -> list in absorbed_rows.txt
Fault logs: 15 logs x 40 bytes -> engine_protection_fault_log_entry_t[5]; 4 retype, 11 new; delete 0x805670 / 0x805676 (no refs); keep 0x805652/0x805654 overspeed flag/index
Other rows: 0x807410 EPIMEBTM, 0x80a26a EPIMTPFT, 0x80a26c EPIMEBTR, 0x80d27a/0x80d27c (CM848 10B1 names), new 0x80d28a EPPKSO, 0x80060e task index, 0x800622/626/62a current pointers, 0x80d290 EPRPDC span, 0x8058d2 EPSOTF
Leads: 0x8058ce/0x8058d0 CM848 names engine_protection_shutdown_active_channel(_cal)/engine_protection_shutdown_count(_cal) (same 10B3 records); 0x18f86 incrementDiagnosticCounters ~ cm848_countEngineProtectionShutdownTime; CM550 0x1c630 default selector == cm848_initEngineOperatingState (twin lead); 0x80a9c6 CRRF / 0x80a9d4 GROGSS no rows (CM848 cruise_speed_command / drivetrain_ratio_unsettled_flag)

## More verified facts
- channel inputs: sensor_state_t.filtered_value (+8) of the A/D records at 0x80a2aa + 22n: coolant temperature (6) 0x80a336, oil pressure (4) 0x80a30a, water in fuel (20) 0x80a46a, boost (5) 0x80a320, fuel pressure (3) 0x80a2f4, ambient air pressure (12) 0x80a3ba
- jump table 0x18646: 000a 0012 001a 0022 0030 -> 0x18650 (0x18a26) / 0x18658 (0x18cb6) / 0x18660 (0x19702) / 0x18668 (0x18e0c + 0x1952c) / 0x18676 (0x18fcc) -> enum PROTECTION_STATE (unused, stale) -> ENGINE_PROTECTION_TASK 0-4, type 0x80060e with it
- CM848 10B1: +0 EPRYO2SO engine_protection_restart_limitation_shutdown_command_flag, +2 EPRYO2SQ ..._approaching_flag, +0x10 EPPKSO engine_protection_precrank_shutdown_command_flag, +0x16 EPRPDC engine_speed_limit_fault_derate_span; 10B3 +4 EPSOTF engine_protection_shutdown_total_cal
- 0x80d28a written only by 0x18ac4 (via a4 at 0x18be8 / 0x18c12), read by processDiagnosticLimitStatus 0x1923a / 0x19250 (ORed into approaching flag and shutdown command)
- 0x807410 EPIMEBTM / 0x80a26c EPIMEBTR: no code reference in the dumped ROM (parameter_id_table only); 0x80a26a EPIMTPFT only as state[2].input_pointer (0x187b6) -> writer likely in the undumped 0x40000+ region
- the 117D words (CRSS/CRRF/VSFTAVVS/GRFTGRRA/GROGSS/ZVLMES) have no absolute writer in the dumped ROM besides 0xd5e6
- stale text references to old names (plates / comments to refresh): 0x18e0c, 0x19702, 0x1cad6, 0x192e0, 0xd1a4, 0xd4ae, 0x25806, 0x1b572, 0x1b722 plates; globals 0x80d288, 0x805562/0x80558a/0x8055da/0x805602, 0x807114/0x807116, 0x80ded4, 0x8000da, 0x80a9d6, 0x80a254; struct comments cm550_algorithm_enable_flags_2/7/8_t; function_definitions rows of 0x186ae/0x18708/0x18968/0x18c1c/0x192f2/0x19332/0x19436 (function_name column); CM848 function_definitions 0x507d50 / 0x50832c and local_variables 0x42918 (function_name column) for the twins
- proposed struct rows: proposed_structure_definitions.csv (this folder)
- 0x18cb6: REVISED to TWIN of CM848 0x5084b4 (asm compared: same checks bit0/0x20/255, same loop and calls, else clears +4/+6; only enable bit base 128 vs 112, strides 62 vs 46, table end differ = layout constants like the other twins) -> shared name updateEngineProtectionRestartSeverity

## Final (2026-11-25): 19 functions (6 twins: 0x186ae 0x18a26 0x18c1c 0x18cb6 0x1952c 0x3458c; 12 counterparts; 1 standalone 0x30b04), 77 globals (45 absorbed + 5 other listed + 3 tables + 15 fault logs + 2 deletions + 7 extras), 5 enum members (PROTECTION_STATE -> ENGINE_PROTECTION_TASK), 13 prototypes; nothing skipped
