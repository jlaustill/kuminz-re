# R3 describer notes (round 97)

## ANC structure (from decompilation)
Three ANC limit functions share one pattern: (1) inhibit after a bare engine acceleration:
ESFT01AC (first stage filtered accel) > the limit's "accel below which" threshold -> the limit's *IH flag=1 and the inhibit timer = the *IHTM cal; else count it down, at 0 clear *IH.
(2) conditions: ASANENF!=0, IH==0, speed check, ESFT01AC<=accel threshold, ESFT02AC>=filtered threshold -> status=1, hold timer = *DYTM;
else override ASANODFG -> same; else count hold timer down, status 0 at 0.
- fuel limit  0xb2aa cm550_rpm_system_state_controller: inhibit 0x80003e <- 0x807a4c NZFLIHTM, hold 0x800042 <- 0x807a22 NZFLDYTM, IH flag 0x80a2a2 NZFLLMIH
- timing      0xb3d0: inhibit 0x800040 <- NZTAIHTM 0x807a4e, hold 0x800044 <- NZTADYTM 0x807a3a, IH flag 0x80a2a4
- speed limit 0xb4f2 cm550_engineStateFuelLimitInterpolator: inhibit 0x80003c <- NZESIHTM 0x807a4a, hold 0x800046 <- NZESDYTM 0x807a2e, IH 0x80a2a0

## ANC timers (RAM, no e2m record)
- 0x80003c: speed limit inhibit countdown (0xb4f2): loaded with NZESIHTM 0x807a4a (move.w abs,abs at 0xb52e) while ESFT01AC > NZESACTR; tst/subq; at 0 clears NZESLMIH 0x80a2a0. word. => acceleration_noise_control_engine_speed_limit_inhibit_timer
- 0x80003e: fuel limit inhibit countdown (0xb2aa): loaded with NZFLIHTM 0x807a4c (0xb2ea); at 0 clears NZFLLMIH 0x80a2a2. word. => acceleration_noise_control_fuel_limit_inhibit_timer
- 0x800042 (anc_fuel_limit_active_timer, undefined): fuel limit hold timer, loaded with NZFLDYTM 0x807a22 (two places) on conditions or override; else counted down, NZFLLMSS cleared at 0. word. => acceleration_noise_control_fuel_limit_hold_timer
- 0x800046 (anc_speed_limit_hold_timer): loaded with NZESDYTM 0x807a2e; NZESLMSS cleared at 0. => acceleration_noise_control_engine_speed_limit_hold_timer
(siblings already named round 96: 0x800040 timing_limit_inhibit_timer, 0x800044 timing_limit_hold_timer)

## AFC / alpha (twin calculateAlphaAirFuelControlResult 0xc504 = CM848 0xe2cc)
- 0x80a914 APAFTR 104A +1C (CM848 104A +18, same mnemonic) => alpha_air_fuel_control_timer (CM848 0x40a180) word
- 0x80a912 no record; set 1 in calculateAlpha (stopped/cranking/jump start), cleared in cm550_initializeAlpha 0x1dd18, tested ==1 in 0xc504 => alpha_air_fuel_control_timer_active_flag (CM848 0x3fa0dc) word
- 0x807aa6 APAFTRTM 104B +6 = CM848 104B +6 air_fuel_control_alpha_timeout (0x5be60) word; readers calculateAlpha 0xc36e, 0xc52c
- 0x80a906 FLAFSTFG 104A +E = CM848 alpha_air_fuel_control_state_detected_flag; set 1 by 0xc2be when final_fueling_state==16 (AFC derate), cleared by 0xc658 with the LSG flag, read 0xc518
- 0x807a5a AFFLMAN 11D5 +0 = CM848 air_fuel_control_fueling_override_value (0x3feff2); read 0xc1a8 in cm550_fuelTimingTransitionStateMachine when flags_12.air_fuel_control_override_enable, becomes air_fuel_control_fuel_limit
- 0x80de68 AFCNICTA 105B +0 S (signed); CM848 0x40a2e4 no row. 0xc2be: = AFICTA 0x808a6e when final_fueling_state==16 else 0; 0xc2ee adds it (ext.l = signed) to fuel_timing_advance_value with floor 0 => air_fuel_control_timing_increment i16

## Switch / PTO
- 0x80bcdf 000E +0x11 (DSPTRUUC 0x01, DSPTSEUC 0x04, DSPTONUC 0x10, DSAUSHUC 0x40): user override values of logical inputs 56-63 (the PTO switch byte 0x80bcd5). Read 0x153a0 / 0x153d4 / 0x15408 (bits 0x10 / 0x04 / 0x01) when flags_16 bits 12 / 10 / 8 set. byte. CM848: none (its switch block comes from 1612). => power_take_off_switch_override_values
- 0x803d42 CRSEACSW 1180 +8 EEPROM => cruise_set_accelerate_switch_select_cal (CM848 0x3fd530 same record). 13 tst.w in mc68k_sampleAndDebounceDiscreteInputs: 0 = set held->coast, resume held->accelerate; nonzero = set->accelerate, resume->coast (cruise byte 0x80bcd4 and PTO byte 0x80bcd5). RAM dump 1.
- 0x800544: PTO set switch (0x80bcd5 bit 2) held pass count: +1 per pass, saturates at 25, then set becomes coast or accelerate by CRSEACSW; clr when released.
- 0x800546: same for PTO resume (bit 0): at 25 becomes accelerate or coast.
  (siblings 0x800540 / 0x800542 = same for cruise set / resume on 0x80bcd4)
- 0x80053e: NOT a counter, a 0/1 flag. clr when PTO on bit 0x10 clear; =1 when 0x80aa02 == 3 (0x80aa02 no record, no writer in the dumped ROM). While 0: set+resume -> PTSERUSW 0x20 and clear 0x80bcd4 bit 6; set or resume alone -> clear 0x80bcd4 bit 6.
- 0x808984 PTMXEGES (S), 0x808986 PTMNEGES, 0x80898c PTROSWTM: no reader in the dumped ROM (parameter id table only). CM848 109D names power_take_off_maximum / minimum_engage_engine_speed, power_take_off_remote_switch_timeout.

## Auxiliary driver fault counters (updateEngineSyncStatus 0xd610; a3 = 0x807bfa DAAUCTMX error limit, a4 = 0x807c02 DRDRRVCU recovery limit, feedback 0x80bd03 (000E +35), command latch (0x1,a5) = 0x80bd09)
Per feedback bit: error A (feedback on, command off) -> fault F_on; error B (feedback off, command on) -> fault F_off; recovery (both on, F_off set and not latched in 0x80605x) -> clears F_off; recovery (both off, F_on set) -> clears F_on. All bytes; cm550_clearKickdownControlState 0xe780 zeroes the whole set.
- bit 0 (DSEBFB engine brake / DRR1FB): 0x800155 / 0x800156, rec on 0x800166, rec off 0x800165 (word 8 0x1000 / 0x800)
- bit 1 (DSCD01FB cold start aid relay 1 / DRR2FB): 0x800157 (-> w8 0x4000) / 0x800158 (-> w8 0x2000), rec on 0x800168 (clears w8 0x2000) LISTED, rec off 0x800167
- bit 2 (DSCD02FB cold start aid relay 2): 0x800159 / 0x80015a, rec on 0x80016a, rec off 0x800169
- bit 5 (DRR6FB relay 6): 0x80015b / 0x80015c, rec on 0x80016c, rec off 0x80016b
- bit 4 (DSPUFB prime pump / DRR5FB): 0x80015d / 0x80015e, rec on 0x80016e, rec off 0x80016d
- bit 6 (DRR4FB relay 4; command DREA04 bit 6): 0x80015f (-> w9 0x40) / 0x800160 (-> w9 0x20), rec on 0x800170 (clears w9 0x20) LISTED, rec off 0x80016f
- bit 3 (DSACFB A/C clutch / DRR7FB): 0x800161 (-> w9 0x100) / 0x800162 (-> w9 0x80), rec on 0x800172 (clears w9 0x80) LISTED, rec off 0x800171
- bit 7 (DSFMCHFB fan clutch / DRS1FB): 0x800173 / 0x800174, rec on 0x800176, rec off 0x800175
Old-pass sibling names use "high_recovery" for the command-on recovery (0x80016a aux_driver_cold_start2_high_recovery_count) and "low_recovery" for command-off.
=> 0x800168 auxiliary_driver_cold_start_aid_1_commanded_on_recovery_count; 0x800170 auxiliary_driver_relay_4_commanded_on_recovery_count; 0x800172 auxiliary_driver_air_conditioning_clutch_commanded_on_recovery_count (byte each, 5 byte accesses)

## Engine speed sensor sync pulse detector (cm550_detectEngineSpeedSensorSyncPulse 0x1025c; nothing to do with ANC)
- 0x8001a4 (anc_altitude_table_3_size): move.l read 0x102c4 (primary sensor, flag byte 0) as the threshold; written 0x1035e (= latest period 0x8001a8 x CSXT_1PC 0x807c1e >> 8) and by cm550_canBusTimingInit 0x103a8. dword. Detection: period < threshold => sync pulse (1) at running speed; below running speed the two validators. => primary_engine_speed_sensor_sync_pulse_period_threshold
- 0x8001a0 (anc_altitude_table_2_ptr): same for the backup sensor (read 0x10306, written 0x10370 / 0x103b2). dword. => backup_engine_speed_sensor_sync_pulse_period_threshold
- 0x8001a6 (anc_default_fueling_ptr): no access of its own; it is the low word of the dword 0x8001a4 => remove the row (skipped)
- 0x8001ac (anc_altitude_table_3_ptr): long pointer (movea.l / move.l): = selected sensor's next-write pointer - 4 (or the ring's last entry when next == ring start) = the newest stored period; cm550_bufferDecreasingPatternCheck 0x1011c walks back from it (wrapping at 0x8001b0 ring start to 0x8001b4 ring last entry); cm550_bufferThresholdValidator 0x101b8 reads the two entries before it. dword *. => engine_speed_sensor_sync_pulse_latest_period_pointer
- siblings (not listed): 0x8001a8 latest period (move.l), 0x8001b0 ring start pointer, 0x8001b4 ring last entry pointer. CM848: none (TPU cam / crank sync, hpcr_processEngineSyncPulses).

## ANC calibrations 10A5 (0x807a22-0x807a50; ROM copy, no _cal; CM848 has no 10A5 records and no ANC code)
Compares verified in disassembly (0xb2aa fuel / 0xb3d0 timing / 0xb4f2 speed). ESFT01AC = 0x80a294 first stage, ESFT02AC = 0x80a296 second stage, speed = 0x80ccf4.
- NZxxACTR (0x807a26 fuel, 0x807a50 timing, 0x807a36 speed): ESFT01AC > it => bare engine acceleration inhibit (IH=1, inhibit timer = NZxxIHTM); condition needs ESFT01AC <= it (bgt fails). i16 (cmp.w signed branches). => <limit>_engine_acceleration_maximum
- NZxxFTTR (0x807a28 fuel, 0x807a3e timing, 0x807a32 speed): condition needs ESFT02AC >= it (blt fails). i16. => <limit>_filtered_engine_acceleration_minimum
- NZFLTRES 0x807a2a: speed >= it (bcs fails) => acceleration_noise_control_fuel_limit_engine_speed_minimum
- NZESTRES 0x807a34: speed <= it (bhi fails) - opposite of its text 'above which' => acceleration_noise_control_engine_speed_limit_engine_speed_maximum
- NZTACLTR 0x807a38 (not listed): coolant > it (bls fails)
- NZxxDYTM (0x807a22 fuel, 0x807a3a timing, 0x807a2e speed): hold timer reload => <limit>_minimum_active_time
- NZFLRMRT 0x807a24 / NZTARMRT 0x807a3c / NZESRMRT 0x807a30: per-pass step added while inactive, up to fuel_demand_maximum / 0x400 / 0x803f40 maximum rated speed => <limit>_ramp_out_step
- NZxxIHTM (0x807a4c fuel / 0x807a4e timing / 0x807a4a speed): inhibit timer reload (signed per e2m S) => <limit>_bare_engine_acceleration_inhibit_time
- NZCNESLM 0x807a2c: NZESLM = it while the speed limit status is 1 => acceleration_noise_control_engine_speed_limit_active_value
- NZTAACLM 0x807a40: no reader in the dumped ROM (parameter table only)
- ESFT01MX 0x807a46 / ESFT01MN 0x807a48: twin calculateFilteredEngineAcceleration clamps => CM848 engine_acceleration_first_stage_clamp_maximum / _minimum (8A42 +4 / +6, same mnemonics) i16
## ANC RAM 10A4
- 0x80a290 NZESLM 10A4 +4: written 0xb5b0 / ramp, init 0xb66e = 0x803f40; read by selectEngineSpeedLimit (0x1d640 source 3) => acceleration_noise_control_engine_speed_limit
- 0x80a29e TSBENZTA 10A4 +12: = fuel_timing_advance_value before the ANC cap (0xb4da) => timing before ANC limit (CM848 10A4 +C SOI_Before_ANC_Timing, no row)
- 0x80a2a0 / 0x80a2a2 / 0x80a2a4 NZESLMIH / NZFLLMIH / NZTALMIH => <limit>_inhibit_flag
- 0x80a2a6 ASANODFG: 3 tst.w (one per limit) forces status 1 + hold reload; no writer in the dump => acceleration_noise_control_application_override_flag
- 0x80a2a8 ASANENF: 3 tst.w (0 = conditions fail) + set to 1 at 0xb66a (start-up init 0xb666) => acceleration_noise_control_application_enable_flag

## Other rows
- 0x807f6a SPDIRTTD 11DD +6: cm550_updateElectronicSmartPowerTau 0x1acb0: filtered deceleration rate 0x80d2b2 > it (unsigned word, moveq/move.w) => timer SPESDITR 0x80d2b0 counts to SPDIPE 0x807f68, else 0. Sibling engine_deceleration_rate_filter_coefficient 0x807f66 => engine_deceleration_rate_timer_threshold. CM848: no 11DD, no ESP tau writer.
- 0x8087f0 / f2 / fa / fc: cells of 12DF PPCVTB 'TABLE OF FUELING CURVES' (programmable power) 0x8086f2-0x808895 (210 words = 10 x 21; x axis PPHPCTI 0x8086b0, y axis PPSSFLXA 0x8086c6, next block PPSEAVTB 0x808896); no long constant in 0x8087a0-0x808830 anywhere in the ROM; RAM dump runs of 10 equal words => skip (delete the cell rows, type the table at 0x8086f2)
- 0x80053e: skipped (trigger 0x80aa02 = 117D +3E has no record in any CM550-family e2m and no writer in the dumped ROM)
- 0x807a00 / 02 / 1c / 1e / 20, 0x80a280 (A/C 818A / 818B, vehicle acceleration 818C): no code in the dumped ROM; names from the records only: air_conditioning_vehicle_acceleration_cutout_threshold (i16), air_conditioning_vehicle_acceleration_cutout_duration, vehicle_acceleration_filter_coefficient, vehicle_acceleration_clamp_maximum / _minimum (i16), air_conditioning_rapid_vehicle_acceleration_flag
- cruise / RSG / drivetrain ratio rows (1186, 1187, 106C, 106D, 1197): no CM550 reader in the dumped ROM (blocks only in the parameter id table); CM848 rows for the same records reused; 1197 +0 CRMXVSRF has no CM848 row => road_speed_governor_maximum_vehicle_speed_reference (record only)
- 0x80dc30 PTSLFL 1265 +4: written 5x by 0x2dcb0 (cm550_oil_pressure_shutdown_controller = the PTO / user fueling selector, counterpart of cm848_selectPowerTakeOffOrUserFueling), read 0xf84a (J1939 driver's demand fueling when the selected state is PTO or accelerator pedal fault) => power_take_off_or_user_fueling (pairs with 0x80dc32 power_take_off_or_user_fueling_state; CM848 operating_mode_governor_output.fuel_demand)
- 0x80a29e TSBENZTA => injection_timing_before_acceleration_noise_control_limit (pairs with 0x80a270 injection_timing_before_misfire_limit)
- all names checked unique (scratch proposals.txt)

## Read-back counters: CM848 vocabulary (cm848_checkDiscreteOutputReadBack 0x537c64, per-output structs <output>_output_read_back_check of discrete_output_read_back_counters_t)
CM848: commanded on / reads off -> on_mismatch_count -> HIGH fault; commanded off / reads on -> off_mismatch_count -> LOW fault; agree while on -> high_fault_recovery_count; agree while off -> low_fault_recovery_count. Same limits DAAUCTMX / DRDRRVCU (CM848 auxiliary_driver_fault_match_debounce_threshold / auxiliary_driver_fault_active_recovery_threshold).
CM550 0x800168 / 0x800170 / 0x800172 = agree while commanded on => high fault recovery counts. (CM550's old sibling names call the off-mismatch count 'high_side_error', the inverse of CM848's high / low.)
FINAL: 0x800168 cold_start_aid_1_output_read_back_high_fault_recovery_count (CM848 counterpart intake_air_heater_1_output_read_back_check.high_fault_recovery_count); 0x800170 relay_4_output_read_back_high_fault_recovery_count (no CM848 output identified); 0x800172 air_conditioning_output_read_back_high_fault_recovery_count (CM848 air_conditioning_output_read_back_check.high_fault_recovery_count). CM550 inlines eight copies in updateEngineSyncStatus; counterpart, not twin.
FINAL also: 0x807a00 air_conditioning_vehicle_acceleration_cutout_threshold, 0x807a02 air_conditioning_vehicle_acceleration_cutout_duration, 0x80dc30 power_take_off_or_user_fueling.

