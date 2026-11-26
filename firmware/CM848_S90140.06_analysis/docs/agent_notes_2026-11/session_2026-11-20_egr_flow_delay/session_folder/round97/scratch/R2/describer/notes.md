# R2 describer notes (round 97) - CM550 hsg / asg globals

Scratch files here: e2m_cm550.txt (record per address), e2m_cm550_blocks.txt (full CM550 blocks), e2m_cm848_blocks.txt
(CM848 blocks), cm848_rows.txt, users.txt (CM550 functions per global), absrefs.txt (abs-long refs).

Block layouts differ between firmwares (CM550 1060 has HSPZGVEN at +0x20, so HSDVAJEN is +0x22 in CM550 vs +0x20 in
CM848; CM550 107A has ASRFST at +2, so ASRF is +4 vs +2). Match records by MNEMONIC, not raw offset.
CM848 block 158D (ASDPFG / ASMXRP / ASMNRP) is "not in the dumped table": no CM848 address for those three.
CM550 107C records past +0x18 overlap 107A in RAM (ASQIDPER +0x26 = 0x80a992 = 107A ASDPGN01, ASQPAJ +0x2A = 0x80a996 =
ASTH01DP, ASQPDPER +0x2E = 0x80a99a = ASSLDP): the code decides which record is real.

All 100 addresses are RAM / extended RAM (0x800182 - 0x80db1e), outside the EEPROM mirror 0x803b0a-0x804f93: no _cal.

## Findings

### runHighSpeedGovernorPid 0x1ce7c (disassembly checked, dis_1ce7c.txt)
- 0x800716: a3 = #0x800716; add.l d0,(a3) / sub.l d0,(a3) / move.l d0,(a3), clamp cmp.l (a3) vs ext.l of 0x808044 / 0x808046
  (signed bgt/ble) -> a 32-bit signed integrator in integer fuel units; reset path writes the WORD 0x808048 into
  0x800716 (high word) and clr.w 0x800718. Its low word (0x2,a3) is copied to 0x80d62c (HSITFL). CM848 counterpart
  high_speed_governor_integrator (CM848 keeps it 16.16, integer in the high word). Type i32.
- 0x80d62c = move.w (0x2,a3) -> HSITFL integrator fueling contribution (CM848 high_speed_governor_integral_term i16);
  the current name hsg_pid_fuel_output_previous is wrong.
- RAM dump: 0x800716 long = 0x0000019b (411) and 0x80d62c = 411 -> the long holds the integer integrator, low word = HSITFL.
- initializeHighSpeedGovernorGainSet 0x1d328: move.w 0x808044 -> 0x80d62c (integral term = integrator maximum), same step
  as CM848 (high_speed_governor_integral_term = high_speed_governor_integrator_maximum). Confirms 0x80d62c = HSITFL.
- presetHighSpeedGovernorIntegrator 0x1d252: 0x808066 compared signed (bge) as the cap of the positive proportional part
  = CM848 high_speed_governor_integrator_preset_offset_limit (CM550 record HSITRSOF 1060 +0x30; CM848 1060 +0x2E).
  0x80804e / 0x808050 ext.l signed = preset minimum / maximum.
- 1060 rows -> CM848 names (same mnemonics): 0x808040 HSMXFTRF filtered_error_maximum, 0x808042 HSMNFTRF
  filtered_error_minimum, 0x808044 HSMXITFL integrator_maximum, 0x808046 HSMNITFL integrator_minimum, 0x808048 HSCNRSFL
  integrator_reset_value, 0x80804a HSITRSES integrator_reset_speed_offset, 0x80804c HSITRSFL
  integrator_reset_fuel_demand_threshold, 0x80804e HSMNITPZ / 0x808050 HSMXITPZ preset min / max, 0x808052 / 0x808054
  fueling_maximum / minimum, 0x808058 / 5a / 5c derivative / proportional / integral _gain_adjustment_enable (tst.w),
  0x80805e / 60 derivative_term max / min, 0x808062 / 64 proportional_term max / min (all high_speed_governor_ prefix).

### selectHighSpeedGovernorGainSet 0x1d392 (twin of CM848 0x1fa20)
- 1290: 0x808118 HSACRFBP transient_acceleration_threshold; 0x80811a HSACRFTM transient_gain_set_time_limit;
  0x80811c HSHIRFTD high_reference_speed_threshold; 0x808126 HSLORFTD low_reference_speed_threshold.
- Gain sets (CM848 high_speed_governor_gain_set_t = derivative / error_filter_coefficient / integral / proportional):
  high 0x80811e-0x808124, low 0x808128-0x80812e, transient 0x808130-0x808136 (code reads Kp at +6, Ki +4, Kd +0, filter
  +2 of each). So 0x808120 / 0x80812a / 0x808132 are the .error_filter_coefficient fields (offset 2) of the high / low /
  transient gain sets (CM848 0x5c31a / 0x5c324 / 0x5c32c).
- 128F: 0x80d612 HSAPFTTC error_filter_coefficient_working, 0x80d614 HSAPSESL working_gain_set_code (tst.w: non-zero
  -> load the working set 0x80d618 / 16 / 10 / 12 and copy the code into 0x80d61a), 0x80d61a HSGNSESL gain_set_code
  (0x10 base, 0x11 transient, 0x12 low, 0x13 high), 0x80d622 HSSSFTTC error_filter_coefficient_alternate.
  Nothing in the dumped ROM writes 0x80d610-0x80d618 (CM848 writer cm848_loadHighSpeedGovernorWorkingGainSet; CM550's
  slot after runHighSpeedGovernorPid is func_0x00042496, not dumped).
- 1061 active gains: 0x80d62e HSAEPPGN / 0x80d630 HSAEITGN / 0x80d632 HSAEDVGN = high_speed_governor_proportional_gain /
  integral_gain / derivative_gain (the ACTIVE set loaded by the gain set selection - current names *_gain_base are wrong;
  the base set is 0x808036 / 3a / 38 / 3c = 1060 +0 / +4 / +2 / +6).
  0x80d63e / 40 / 42 HSPPAJGN / HSDVAJGN / HSITAJGN = *_gain_adjusted. 0x80d626 HSER filtered_error (i16), 0x80d628
  HSPPFL proportional_term (i16).

### Compensator 13B4 / 13AB: no code reference in the dumped ROM (only the parameter ID table at 0x35224 lists them).
  0x80d60a HSDCES (compensated speed) is only read (by the PID); CM550 task 0x1b5xx calls func_0x0004da56 (not dumped)
  between selectEngineSpeedLimit and selectHighSpeedGovernorGainSet. Names from the records = CM848 names.

### selectEngineSpeedLimit 0x1d5a0 (twin of CM848 0x1fd94)
- 0x80d644 (a3) HSRFST limiting source number (5, 6, 9, 4, 3, 2, 7, 11, 10, 8); 0x80d646 (a5) HSRF applied limit (PID
  reference); 0x80d648 (a2) HSRFBEDP lowest source limit. Separate movea.l per address (no base + offset), CM848 types
  0x40a2f8 as engine_speed_limit_arbitration_t {limiting_source_number, applied_speed_limit, lowest_source_speed_limit}.
- 0x808138 HSRFRMRT ramp step (add.w to 0x80d654 ramped limit) = engine_speed_limit_ramp_up_step.
- 0x80813e / 0x808140 HSMXDPFL / HSMNDPFL clamp the integral term 0x80d62c (unsigned bls / bcc) = droop_fuel_clamp max/min.
- 0x80d64e HSBKRFAE = *0x80d666 (base reference pointer -> engine_speed_limit_reference_default_cal) = CM848
  engine_speed_limit_reference; 0x80d650 HSAENLRP (init 0x803f46) = engine_speed_limit_droop_no_load_speed; 0x80db1e
  FLAENLRP = friction fuel + coolant correction at 0x80d650 = engine_speed_limit_droop_no_load_fuel_quantity; 0x80d652
  HSDPSLAE = clamped division -> engine_speed_limit_droop_slope (tst.w + ble at 0x1d856 = signed test); 0x80d656 HSDPFG
  engine_speed_limit_droop_active_flag; 0x80d658 HSRFTOGS = copy of 0x80d648 at the end = engine_speed_limit_arbitrated
  (read by the gain set selection); 0x80d65a HSISRFAE droop cap (reset 0xffff each pass, lowered by source 2 in modes
  2 / 3, caps the applied limit) = engine_speed_limit_droop_cap.

### ASG (cm550_runAllSpeedGovernor 0xc962, disassembly dis_c962.txt)
- external reset (0x80a9a0 == 1): X1 0x80a932 -> d3 (previous speed error), X2 0x80a934 -> 0x8000fa (integrator high
  word, low word cleared), X3 0x80a936 -> 0x8000f4 (previous engine speed), X4 0x80a938 -> d4 (previous X4), X5
  0x80a93a -> d2 (previous X5), X6 0x80a93c -> d5. Same six memories as CM848 (reset_state_speed_error_previous /
  integral / engine_speed_previous / pid_clamp_value / pid_integral_clamped / fuel_demand_correction).
- 0x80a96c ASDV = derivative after dead band 0x807abe and limit 0x807ac2; 0x80a96e ASERDC = X1 - previous X1 (+-32000);
  0x80a970 ASFBDC = rpm 0x80ccf6 - previous rpm 0x8000f4 (+-8000); 0x80a972 ASFTRF filtered reference (EMA of 0x80a990
  through 0x80a984, preset on a state change); 0x80a978 ASSTX1 = filtered reference - rpm; 0x80a97a ASSTX2 = move.w
  0x8000fa (integrator high word); 0x80a97c ASSTX4 = derivative x droop gain 2 >> 10 + previous X4 x 0x807ac0 >> 10,
  +-0x1700; 0x80a97e ASSTX5 = X2 + X4 (+-0x1700); 0x80a980 ASSTX6 = (X5 c1 - X5prev c2 + X6prev c3) >> 8 (+-0x1700).
  0x80a99c / 0x80a99e clamp 0x80a976 ASFL (signed blt / bgt). 0x80a992 / 0x80a994 droop gains (mulu.w, Q10).
- cm550_diagnosticDataCopyHandler 0xd0e2 = the ASG application mode selection (counterpart of CM848
  cm848_selectAllSpeedGovernorApplicationMode 0xfb28): copies 1170 records 0x80a940 -> ASRF 0x80a990, 0x80a942 /
  0x80a944 -> droop gains 0x80a992 / 0x80a994, 0x80a94e..56 -> reset states 0x80a932..3a, 0x80a958 -> 0x80a93c,
  0x80a94c -> external reset 0x80a9a0, 0x80a948 / 0x80a94a -> fueling limits 0x80a99c / 0x80a99e; gate 0x80a93e != 0.
- cm550_diagnosticMode10FuelController 0xd3e6 = droop gain calculation (counterpart of CM848
  cm848_calculateGovernorCompensatorCoefficients): ASSLDP 0x80a99a = droop lookup (0x800144 when 0x80a9a2 == 1,
  0x800136 when 0) at ASRF; 0x80a996 throttle droop gain 1 = (0x2655879 - (Ki1+Ki2) x droop) / 2 / ((... + 0x2655879)
  >> 11) or 0; 0x80a998 = (gain1 + 0x400) >> 1; copied into 0x80a992 / 0x80a994. So 0x80a996 is ASTH01DP, not ASQPAJ;
  0x80a99a is ASSLDP, not ASQPDPER; 0x80a992 is ASDPGN01, not ASQIDPER.
- 0xd2be: 0x80a9a2 ASDPFG selects the reference speed set (0 -> set 1 pointers 0x80a9ac / b0, 1 -> set 2 0x80a9b4 / b8)
  into 0x80a9a4 ASMNRP / 0x80a9a6 ASMXRP; ASTHRFES 0x80a98c = min + throttle x (max - min) / 400. ASDPFG toggles from
  the default 0x803d5a when switch 0x80bcd1 bit 1 (STCG / ASG droop switch) is on and algorithm_enable_flags_27 bit 3
  clear (with default < 2, final fueling below no-load + 0x807ac8, throttle 0); else = default. CM848 counterpart of the
  same ASDPFG record: all_speed_governor_tuning_set_blend_weight 0x40af7c (0..128 blend); ASMXRP / ASMNRP: CM848
  all_speed_governor_maximum_reference_speed 0x40af7e / all_speed_governor_minimum_reference_speed 0x40af80.
  Dump: ASDPFG = 1, ASMNRP = 5200 (= set 2 ASMNRF02 650 rpm), ASMXRP = 34304 (set 2 4288 rpm).

### Other rows
- 0x800182 (no e2m record): written by the J1939 torque curve builder 0xfb26 (current name
  vp44_fuelLimitExceedanceStatisticsAccumulator; CM848 counterpart cm848_updateJ1939EngineConfigurationTorqueCurve
  0x20d10): = 0x80d648 HSRFBEDP when 0x80d644 is 2 / 4 / 5 / 1 (0xfbda-0xfc04), else = 0x80d64e HSBKRFAE (0xfc10).
  Read: cmp.w with 0x808174 (bcc, unsigned) at 0xfcb0 / 0xfda0 to pick the point 4 or point 5 fueling for the droop
  helper; cm550_calculateGovernorDroopSpeed 0xfac2 copies it into j1939_torque_curve_speed_at_point_2 (0x80da3a) when the
  droop slope 0x80d652 is 0. CM848 counterpart: torque_limit_working_reference 0x3fa8a4 (no comment; set to
  engine_speed_limit_reference or engine_speed_limit_arbitrated for sources 2 / 4 / 5 / 1 / 12). Dump 20240 (2530 rpm).
- 0x80bcdb e2m 000E +0xD: user override values of switch byte 3 (logical switches 24-31; Calterm DS25 bit 0, DS04 /
  DSUSSTCN / DSTHILUC bit 1, DS27 bit 2, DS28 bit 3, DS23 bit 4, DS29 bit 5, DS30 bit 6, DS31 bit 7).
  mc68k_sampleAndDebounceDiscreteInputs 0x15250: debounced byte 3 (a4 + 3 = 0x80bcd1) = (debounced & ~mask) | (this &
  mask) with mask = discrete_input_override_mask_ptr[2] = 0x803cb0 (high byte of algorithm_enable_flags_14_cal);
  mc68k_ioDriverStrobeHandler 0x15cde: the same for the raw image byte 0x80bd01. The J1939 input layer also writes
  0x80bcd8 + input / 8 bits (cm550_processJ1939SwitchInput / cm550_copyOutputBitToSwitchOverrideValue). Neighbours:
  switch_1_to_8_override_values 0x80bcd8, switch_9_to_16_override_values 0x80bcd9 -> suggested
  switch_25_to_32_override_values. Dump 0.
- Compensator ROM-copied calibration values in the RAM dump: 0x808110 = 0x8000, 0x808112 = 0, 0x808114 = 0, 0x808116 =
  1024 - identical to CM848's 0x5c948-0x5c94e (32768 / 0 / 0 / 1024).
- 0x808506 HSGVSPOF (1281 +0, 'amount added to HSG_governed_speed to equal HSG_breakpoint_speed', 0.125 rpm, 0-50 rpm;
  dump 240 = 30 rpm): no reference in the dumped ROM except the parameter ID table entry at 0x367a4. No CM848 record.
- 0x80813a / 0x80813c SWHSG_00 / SWHSG_01 'BLANK SPOT IN HSG CALIBRATION' (1062 +2 / +4; dump 0 / 0): no reference.
  CM848's 1062 block has no blank spots (its +2 is HSMXDPFL).

## Suggested names (final, describer)
0x800182 j1939_torque_curve_governor_breakpoint_speed (word) | 0x800716 high_speed_governor_integrator (i32)
1060: high_speed_governor_filtered_error_maximum / _minimum, _integrator_maximum / _minimum, _integrator_reset_value,
  _integrator_reset_speed_offset, _integrator_reset_fuel_demand_threshold, _integrator_preset_minimum / _maximum,
  _fueling_maximum / _minimum, _derivative / _proportional / _integral _gain_adjustment_enable, _derivative_term_maximum
  / _minimum, _proportional_term_maximum / _minimum, _integrator_preset_offset_limit (0x808066)
13B4: high_speed_governor_compensator_filter_coefficient_1 / _2, _compensator_transition_coefficient,
  _compensator_maximum_gear_ratio | 13AB +4 0x80d60e high_speed_governor_compensator_filter_coefficient_3
1290: high_speed_governor_transient_acceleration_threshold, _transient_gain_set_time_limit,
  _high_reference_speed_threshold, _low_reference_speed_threshold; 0x808120 / 0x80812a / 0x808132 =
  high_speed_governor_{high_reference_speed,low_reference_speed,transient}_gain_set.error_filter_coefficient (struct
  high_speed_governor_gain_set_t at 0x80811e / 0x808128 / 0x808130)
1062: 0x808138 engine_speed_limit_ramp_up_step, 0x80813a / 0x80813c high_speed_governor_spare_word_1 / _2,
  0x80813e / 0x808140 engine_speed_limit_droop_fuel_clamp_maximum / _minimum | 0x808506 high_speed_governor_breakpoint_speed_offset
1170 / 107C / 107A: CM848 names (reset_state_*, application_*, derivative_term, error_difference, feedback_difference,
  governor_reference_speed_filtered, state_*, speed_request_unfiltered, droop_gain_1 / _2, throttle_droop_gain_1 / _2,
  all_speed_governor_droop, governor_fuel_demand_tracking_limit / _floor, external_reset_flag);
  0x80a9a2 all_speed_governor_tuning_set_selection; 0x80a9a4 / a6 all_speed_governor_minimum / maximum_reference_speed
0x80bcdb switch_25_to_32_override_values (byte)
128F / 1061 / 1063 / 109C: CM848 names; 0x80d644 engine_speed_limit_arbitration (engine_speed_limit_arbitration_t),
  0x80d646 engine_speed_limit_arbitration.applied_speed_limit; 0x80d62c high_speed_governor_integral_term (i16);
  0x80d652 engine_speed_limit_droop_slope (i16)
