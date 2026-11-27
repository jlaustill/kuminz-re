# R2 investigator notes (round 97) - CM550 hsg / asg globals

Method: abs_refs.py on all 100 rows (refs.txt), func_of.py maps refs to functions (refs_by_function below),
e2m_block_addresses.py --firmware cm550 --address per row (e2m_cm550.txt), CM848 block listings for
1060/1061/1062/1063/1290/128F/13AB/13B4/109C/107A/107C/1170.
No row is in the EEPROM mirror (0x803b0a-0x804f93): no _cal anywhere in this batch.

## e2m layout facts
- CM550 block 107C base 0x80a96c, 107A base 0x80a98c (table entries). 107C records past +0x1F (ASQDAJ..ASQPDPER,
  +0x1A..+0x2E) overlap 107A: they do not fit this firmware. 0x80a992 / 0x80a996 / 0x80a99a are the 107A records
  (ASDPGN01 / ASTH01DP / ASSLDP) - the code agrees (droop gain 1 used as (0x400 - x) in the reference preset, CM848 twin).
- CM550 107A has ASRFST at +2 (0x80a98e, already all_speed_governor_reference_state FUELING_STATE), so 107A records
  from +4 on are 2 bytes later than CM848's (ASRF CM550 +4 / CM848 +2 ...). Same mnemonics.
- CM550 1060 has HSPZGVEN at +0x20 (0x808056), so 1060 records from +0x22 on sit 2 bytes after CM848's.
- CM550 1062 has SWHSG_00 / SWHSG_01 at +2 / +4, so HSMXDPFL / HSMNDPFL are +6 / +8 (CM848 +2 / +4).

## HSG PID (runHighSpeedGovernorPid 0x1ce7c / presetHighSpeedGovernorIntegrator 0x1d252 - twins of CM848)
Step-by-step map CM550 -> CM848 (same e2m mnemonic each):
- 0x808040 HSMXFTRF -> high_speed_governor_filtered_error_maximum i16 (cmp.w 0x1cef2 then ble: signed)
- 0x808042 HSMNFTRF -> high_speed_governor_filtered_error_minimum i16 (cmp.w 0x1cf18 bge)
- 0x808044 HSMXITFL -> high_speed_governor_integrator_maximum i16 (ext.l + cmp.l 0x1d1bc..; init copies it to the
  integral term like CM848 initializeHighSpeedGovernorGainSet)
- 0x808046 HSMNITFL -> high_speed_governor_integrator_minimum i16
- 0x808048 HSCNRSFL -> high_speed_governor_integrator_reset_value i16 (move.w to 0x800716 at 0x1cf76)
- 0x80804a HSITRSES -> high_speed_governor_integrator_reset_speed_offset i16 (ext.l + add to reference 0x1cf48)
- 0x80804c HSITRSFL -> high_speed_governor_integrator_reset_fuel_demand_threshold word (cmp.w + bcc 0x1cf64: unsigned)
- 0x80804e HSMNITPZ -> high_speed_governor_integrator_preset_minimum i16 (a1 base, ext.l 0x1d2be)
- 0x808050 HSMXITPZ -> high_speed_governor_integrator_preset_maximum i16 (a0 base, ext.l 0x1d2ae)
- 0x808052 HSMXFLLM -> high_speed_governor_fueling_maximum word (moveq #0 + move.w zero-extend 0x1d20e)
- 0x808054 HSMNFLLM -> high_speed_governor_fueling_minimum word
- 0x808058 HSDVAJEN -> high_speed_governor_derivative_gain_adjustment_enable word (tst.w 0x1cf98)
- 0x80805a HSPPAJEN -> high_speed_governor_proportional_gain_adjustment_enable word
- 0x80805c HSITAJEN -> high_speed_governor_integral_gain_adjustment_enable word
- 0x80805e HSDVFLMX -> high_speed_governor_derivative_term_maximum i16
- 0x808060 HSDVFLMN -> high_speed_governor_derivative_term_minimum i16
- 0x808062 HSPPFLMX -> high_speed_governor_proportional_term_maximum i16
- 0x808064 HSPPFLMN -> high_speed_governor_proportional_term_minimum i16
- 0x808066 HSITRSOF (CM550 1060 +30, CM848 +2E) -> high_speed_governor_integrator_preset_offset_limit i16
  (preset adds min(proportional term, this) 0x1d294-0x1d2ac, CM848 the same)
- 0x800716 (no e2m) -> high_speed_governor_integrator: a long (add.l/sub.l/cmp.l/move.l (a3) with a3 = #0x800716);
  integral term 0x80d62c = its low word move.w (2,a3) at 0x1d1ea / 0x1d2cc. Signed compares (bgt/ble) -> i32.
- 0x80d626 HSER -> high_speed_governor_filtered_error i16
- 0x80d628 HSPPFL -> high_speed_governor_proportional_term i16
- 0x80d62c HSITFL -> high_speed_governor_integral_term (CM848 i16; CM550 ext.l reads at 0x1d204 -> i16; see check)
- 0x80d62e HSAEPPGN -> high_speed_governor_proportional_gain (CM848 1061+A; _base is CM848's 1060 cal)
- 0x80d630 HSAEITGN -> high_speed_governor_integral_gain
- 0x80d632 HSAEDVGN -> high_speed_governor_derivative_gain
- 0x80d63e HSPPAJGN -> high_speed_governor_proportional_gain_adjusted
- 0x80d640 HSDVAJGN -> high_speed_governor_derivative_gain_adjusted
- 0x80d642 HSITAJGN -> high_speed_governor_integral_gain_adjusted

## HSG gain scheduling (selectHighSpeedGovernorGainSet 0x1d392 / initializeHighSpeedGovernorGainSet 0x1d2e4)
- 0x808118 HSACRFBP -> high_speed_governor_transient_acceleration_threshold
- 0x80811a HSACRFTM -> high_speed_governor_transient_gain_set_time_limit
- 0x80811c HSHIRFTD -> high_speed_governor_high_reference_speed_threshold
- 0x808126 HSLORFTD -> high_speed_governor_low_reference_speed_threshold
- 0x808120 / 0x80812a / 0x808132: the error filter coefficient (field +2) of the high / low reference speed and
  transient gain sets at 0x80811e / 0x808128 / 0x808130 (CM848 high_speed_governor_gain_set_t, 8 bytes:
  derivative, error filter, integral, proportional; CM550 reads _DAT_0080811e/0x808122/0x808124 etc. in that order)
- 0x80d612 HSAPFTTC -> high_speed_governor_error_filter_coefficient_working
- 0x80d614 HSAPSESL -> high_speed_governor_working_gain_set_code
- 0x80d61a HSGNSESL -> high_speed_governor_gain_set_code (0x10 / 0x11 / 0x12 / 0x13 stores)
- 0x80d622 HSSSFTTC -> high_speed_governor_error_filter_coefficient_alternate
- 0x80811a HSACRFTM is compared with the transient timer 0x80074a (= pass counter 0x800748 x 20, lsl/add/lsl
  at 0x1d3c2-0x1d3ca), CM848 the same (timer = pass_counter * 0x14)
- CM550 selectHighSpeedGovernorGainSet returns at once when algorithm_enable_flags_18 bit 0 is clear
  (beq.w 0x1d3b8 -> rts 0x1d59a): no base-set copy, unlike CM848 (lead, not this batch)

## Engine speed limit arbitration (selectEngineSpeedLimit 0x1d5a0 / initializeEngineSpeedLimitDefaults 0x1d94e)
a2 = #0x80d648 (lowest source limit), a3 = #0x80d644 (source number), a4 = #0x80d654 (ramped), a5 = #0x80d646 (applied)
- 0x80d644 HSRFST -> engine_speed_limit_limiting_source_number (CM848 field engine_speed_limit_arbitration.limiting_source_number;
  flat here: CM550 has no engine_speed_limit_arbitration_t struct; snapshot row 0x80d664 already
  engine_speed_limit_limiting_source_number_snapshot)
- 0x80d646 HSRF -> engine_speed_limit_applied (CM848 field .applied_speed_limit)
- 0x80d64e HSBKRFAE -> engine_speed_limit_reference (source 6, = *(0x80d666) = engine_speed_limit_reference_default_cal)
- 0x80d650 HSAENLRP -> engine_speed_limit_droop_no_load_speed (friction lookup x input 0x1d7ce; init from 0x803f46 HSNLRPDF)
- 0x80d652 HSDPSLAE -> engine_speed_limit_droop_slope, i16 (tst.w + ble 0x1d850/0x1d856, ext.l 0x1d898 / 0x26da2; CM848 i16)
- 0x80d656 HSDPFG -> engine_speed_limit_droop_active_flag
- 0x80d658 HSRFTOGS -> engine_speed_limit_arbitrated (move.w (a2) at 0x1d900; read 4x by the gain scheduler)
- 0x80d65a HSISRFAE -> engine_speed_limit_droop_cap (caps (a5) at 0x1d8f0; 0xffff at 0x1d920 each pass)
- 0x80db1e FLAENLRP (109C +2) -> engine_speed_limit_droop_no_load_fuel_quantity (store 0x1d804, sub.w 0x1d836)
- 0x808138 HSRFRMRT -> engine_speed_limit_ramp_up_step (add.w to (a4) 0x1d746)
- 0x80813e HSMXDPFL -> engine_speed_limit_droop_fuel_clamp_maximum (cmp.w + bls 0x1d860)
- 0x808140 HSMNDPFL -> engine_speed_limit_droop_fuel_clamp_minimum (cmp.w + bcc 0x1d870)
- 0x80813a / 0x80813c SWHSG_00 / _01 'BLANK SPOT IN HSG CALIBRATION': no reference in the ROM (range_refs 0x808100-0x808118
  and abs refs: none) -> high_speed_governor_spare_word_0 / _1 (CM848 precedent all_speed_governor_spare_word_1)
- 0x808506 HSGVSPOF (1281 +0) 'AMOUNT ADDED TO HSG_GOVERNED_SPEED TO EQUAL HSG_BREAKPOINT_SPEED': only the parameter table
  references it (0x367a4); no CM848 record -> name from the record, low confidence

## J1939 torque curve
- 0x800182 (no e2m): written only in vp44_fuelLimitExceedanceStatisticsAccumulator 0xfb26 (0xfc04: = 0x80d648 when the
  source number is 2/4/5/1, 0xfc10: = 0x80d64e otherwise); read 0xfcb0 / 0xfda0 cmp.w with 0x808174 (JCT0P5IN 'WHEN
  DERATE_SPEED < THIS POINT, LOW HP HSG REF. LINE LEFT') + bcc, and 0xfac2 in cm550_calculateGovernorDroopSpeed (point 2
  speed when the droop slope is 0). CM848 counterpart torque_limit_working_reference (0x3fa8a4) in
  cm848_updateJ1939EngineConfigurationTorqueCurve / cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling.
  -> j1939_torque_curve_derate_engine_speed (word)

## HSG compensator (13B4 / 13AB)
- No code in the dumped ROM touches 0x808110-0x808117, 0x80d60c, 0x80d60e (range_refs.py); 0x80d60a (HSDCES) is only
  read by runHighSpeedGovernorPid (0x1ceb6, subtracted from the HSG reference like CM848's
  high_speed_governor_compensated_engine_speed). The compensator itself is not in the dump (code above 0x40000).
  Same block + offset as CM848 13B4 +0..+6 / 13AB +4 -> CM848 names, medium confidence.

## ASG (cm550_runAllSpeedGovernor 0xc962 = counterpart of cm848_runOperatingModeSpeedGovernor 0xea00)
Same step order: preset of the filtered reference from (final_fueling - no-load) x (0x400 - droop gain 1) x 0x80 /
(droop gain 2 x (Ki1 + Ki2)); EMA of the selected reference; error; reset branch (external reset flag = 1 loads the
1170 reset states); feedback difference clamp +-8000; error difference clamp +-32000; PI sum >> 9 clamp 0xe6000;
derivative >> 0xd with deadband / limit; X4 / X2 / X5 / X6; fueling clamped by ASFLHILM / ASFLLOLM.
- 0x80a978 ASSTX1 -> all_speed_governor_state_speed_error; 0x80a97a ASSTX2 -> all_speed_governor_state_integral
  (move.w 0x8000fa -> 0x80a97a, the high word of the integral long); 0x80a97c ASSTX4 -> ..._state_pid_clamp_value;
  0x80a97e ASSTX5 -> ..._state_pid_integral_clamped; 0x80a980 ASSTX6 -> ..._state_fuel_demand_correction
- 0x80a96c ASDV -> all_speed_governor_derivative_term; 0x80a96e ASERDC -> all_speed_governor_error_difference;
  0x80a970 ASFBDC -> all_speed_governor_feedback_difference; 0x80a972 ASFTRF -> governor_reference_speed_filtered
- 0x80a932..0x80a93a ASRSSTX1..5 -> all_speed_governor_reset_state_speed_error_previous / _integral /
  _engine_speed_previous / _pid_clamp_value / _pid_integral_clamped (X6 0x80a93c already named)
- 0x80a990 ASRF (CM550 107A +4, CM848 +2) -> speed_request_unfiltered (EMA input 0xcad6; friction lookup x 0xd24c;
  droop lookup x 0xd410/0xd434; written by the reference selectors 0xd0fc / 0xd230 / 0xd58e)
- 0x80a992 ASDPGN01 -> all_speed_governor_droop_gain_1 (0x400 - x in the preset; TSC1 mode stores 0x400 at 0xd1e6;
  0xd498 = throttle droop gain 1) - NOT 107C +26 ASQIDPER
- 0x80a994 ASDPGN02 -> all_speed_governor_droop_gain_2
- 0x80a996 ASTH01DP -> all_speed_governor_throttle_droop_gain_1, word (a2 = #0x80a996; move.w (a2) 0xd488/0xd48c)
- 0x80a998 ASTH02DP -> all_speed_governor_throttle_droop_gain_2 (= (gain 1 + 0x400) >> 1 at 0xd48a-0xd496)
- 0x80a99a ASSLDP -> all_speed_governor_droop (droop table result; mulu.w 0xd454; snapshot all_speed_governor_droop_snapshot)
- 0x80a99c ASFLHILM -> governor_fuel_demand_tracking_limit; 0x80a99e ASFLLOLM -> governor_fuel_demand_tracking_floor
  (loaded from governor_fuel_demand_tracking_limit/floor_j1939 and _throttle_mode, already named in CM550)
- 0x80a9a0 ASETRS -> all_speed_governor_external_reset_flag
- 0x80a9a2 ASDPFG 'ASG DROOP SELECTION FLAG' -> all_speed_governor_tuning_set_select: 0 = reference speed set 1 +
  all_speed_governor_alternate_droop_lookup, 1 = set 2 + all_speed_governor_droop_lookup; default ASDPFGTN 0x803d5a;
  the switch byte 0x80bcd1 bit 1 flips it when STCG select is 0. CM848's ASDPFG (158D +0) is a 0..128 blend weight
  (all_speed_governor_tuning_set_blend_weight) - different block and semantics, so a CM550 name.
- 0x80a9a4 ASMNRP -> all_speed_governor_minimum_reference_speed; 0x80a9a6 ASMXRP -> all_speed_governor_maximum_reference_speed
  (CM848 158D +4 / +2 same mnemonics and role)
- 1170 application set (cm550_diagnosticDataCopyHandler 0xd0e2 = counterpart of cm848_selectAllSpeedGovernorApplicationMode,
  same copies in the same order): ASAPODMD/ASAPRF/ASAP01DP/ASAP02DP/ASAPHILM/ASAPLOLM/ASAPRS/ASAPSTX1..5 -> CM848 names
- 0x80bcdb (000E +D) = override value byte 3, merged into the switch status byte 0x80bcd1 where mask byte (*0x80054c)+2
  is set (0x15248-0x15258) and into 0x80bd01 (0x15cd6-0x15ce6); e2m bits: 0 sw25, 1 sw4 = DSUSSTCN STCG ASG droop,
  2 sw27, 3 sw28 / DSTHILUC / DSAKHIUC, 4 sw23, 5 sw29 / DSAKCYUC, 6 sw30 / DSAKONUC, 7 sw31
  -> switch_25_to_32_override_values (pattern of 0x80bcd8 / 0x80bcd9)

## Dump values (RAM / extended RAM) used in comments
0x800716 = 0x0000019b and 0x80d62c = 0x019b (term = low word of the integer integrator); 0x80d624 = 1776 = 1365 + 0 + 411;
0x80d626 = 8000 (clamped); 0x80071a = 212, 0x80071c = 8000; 0x80d646 = 0x80d64a = 21825; 0x80d64e = 0x80d654 = 0x80d658 = 20240;
0x80d644 = 6; 0x800182 = 20240 (= the reference, source 6); 0x80d652 = 6759; 0x80d65a = 24000 (not the 0xffff reset value:
a writer outside the dumped code); 0x80d61a = 16; 0x80a9a2 = 1 (default 0x803d5a = 1), 0x80a9a4 = 5200, 0x80a9a6 = 34304;
ASG states / 1170 block all 0.

## Bonus DAT_ rows (no CSV row today; all proved by the same twin comparison) - see proposals.tsv lines 101-124

## Stale mentions after the renames (comments of other rows) - stale_mentions.py output
0x800102 0x800118 0x800136 0x800144 0x80071e 0x80072c 0x80073a 0x803bca 0x807abe 0x807ac0 0x807ac2 0x807ac6 0x807b8e 0x807b90
0x807bdc 0x807bde 0x807be0 0x808084 0x8080bc 0x8080f4 0x8081fa 0x8091de 0x80a93c 0x80a976 0x80a984 0x80a9ac 0x80d664 0x80db2e
(global_variables) and function_renames 0xd3b2 / 0x1ce7c / 0x1d5a0 mention old names.

## Leads (not this batch)
- Struct: CM848 high_speed_governor_gain_set_t (derivative, error_filter_coefficient, integral, proportional; 8 bytes) fits
  CM550 0x80811e (high), 0x808128 (low), 0x808130 (transient): selectHighSpeedGovernorGainSet reads +6 / +4 / +0 / +2 in that
  layout (0x1d548-0x1d55e, 0x1d518-0x1d52e, 0x1d3f6-0x1d40c). Needs the struct added to CM550 structure_definitions.csv; the
  flat rows 0x808120 / 0x80812a / 0x808132 then fold into it.
- Struct: CM848 engine_speed_limit_arbitration_t (limiting_source_number, applied_speed_limit, lowest_source_speed_limit) fits
  CM550 0x80d644-0x80d649 (0x80d648 HSRFBEDP is another family's row).
- Functions: 0xd0e2 cm550_diagnosticDataCopyHandler = counterpart of cm848_selectAllSpeedGovernorApplicationMode;
  0xd3e6 cm550_diagnosticMode10FuelController = counterpart of cm848_calculateGovernorCompensatorCoefficients (same K
  0x2655879 = 40196217, no filter coefficient factor); 0xc8a0 cm550_dzgTimingAndPressureControlStateMachine = counterpart of
  cm848_calculateGovernorReferenceSpeedBlend; 0xd23c cm550_dualTableLookupSum = no-load fuel (friction at the reference +
  coolant), counterpart of cm848_calculateAllSpeedGovernorNoLoadFuel; 0xd1a4 cm550_diagnosticStatus2Initializer = TSC1 speed
  control mode set-up (j1939 gain set, droop gains 0x400, j1939 limits); 0xd218 / 0xd584 the TSC1 / throttle reference
  selectors; 0xd2be cm550_acceleratorThrottleFaultDetector = the ASG throttle reference speed; 0xfb26
  vp44_fuelLimitExceedanceStatisticsAccumulator = counterpart of cm848_updateJ1939EngineConfigurationTorqueCurve; 0xfaa6 =
  counterpart of cm848_setJ1939TorqueCurvePoints2And5AtDroopLineFueling.
- Misnamed ASG state rows: 0x8000fa fuel_blend_table_1_limit (= CM848 governor_pid_integral_state, long), 0x8000f4
  fuel_blend_table_2_base (fuel_trim_pid_ema_snapshot), 0x8000f6 fuel_blend_table_2_ptr (all_speed_governor_pid_accumulator,
  long), 0x800100 fuel_blend_table_3_base (governor_fuel_demand_tracking), 0x800110 fuel_blend_table_5_ptr
  (governor_reference_filter_weight), 0x800112 DAT (governor_fuel_demand_prev_ref), 0x800114 / 0x800116
  (speed_request_rate_limited_prev / speed_request_rate_limited).
- 0x803d5a default_throttle_source_selector is e2m 1387 +8 ASDPFGTN 'TRIM FOR ASG DROOP SELECTION FLAG' (the default of
  0x80a9a2); 0x80bcd1 state_of_the_throttle_interlock_switch_on_off bit 1 is the STCG / ASG droop switch.
- CM550 selectHighSpeedGovernorGainSet has no disabled-branch base-set copy (CM848 has one).
