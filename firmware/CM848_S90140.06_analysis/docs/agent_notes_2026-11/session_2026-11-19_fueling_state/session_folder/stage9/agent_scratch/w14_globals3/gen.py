"""Builds result_W14_globals3.jsonl in bin order from the decisions below (json.dumps, one object per line)."""
import json

BIN = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals3.json'
OUT = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals3.jsonl'

R = {}


def rename(address, new, evidence, quote, comment, **extra):
    R[address] = dict(verdict='confirmed', new=new, evidence=evidence, code_quote=quote, comment=comment, **extra)


def keep(address, e2m_note):
    R[address] = dict(verdict='keep', e2m_note=e2m_note)


def drift(address, evidence):
    R[address] = dict(verdict='drift', evidence=evidence)


NORAM = ' RAM outside the EEPROM mirror, so no _cal.'

# ---------------------------------------------------------------- throttle filter table (no table-resolved record)
rename('0x00406a46', 'commanded_throttle_filter_coefficient_by_throttle_difference_axis',
       "cm848_calculateFuelDemandChangeRate looks up |fuel_demand_control.calculated - commanded_throttle_filtered| in this word[6] "
       "(x axis: header 10 + 5 breakpoints) and the next table (y data); the result is copied into commanded_throttle_filter_coefficient, "
       "the coefficient of commanded_throttle_filtered's EMA filter. Basis for the e2m name: block 1583 is not in the dumped ID table, so the "
       "address is not table-resolved; the X / Y pair 1583 / 1584 (5 points each, %THROTTLE at 0.25 per count and UNITLESS at 1/65536, 'throttle "
       "difference breakpoints' / 'throttle filter constant') fits the code role and the dump (24 / 72 / 240 / 304 / 352 = 6 / 18 / 60 / 76 / 88 %); "
       "RAM address, so the _cal is wrong.",
       "(&fuel_mode_ema_state,input,fuel_mode_ema_axis_cal,fuel_mode_ema_output_cal,0);",
       "e2m 1583 Throttle_Filter_Constant_Table_X 'Throttle difference breakpoints in throttle filter constant table' (%THROTTLE, 0.25 per count, 5 points; "
       "not table-resolved because block 1583 is not in the dumped ID table - named by its code role, which fits the record): the x axis of the lookup in "
       "cm848_calculateFuelDemandChangeRate, input = the absolute difference between the commanded throttle and commanded_throttle_filtered, result "
       "commanded_throttle_filter_coefficient_lookup_result; word[6] = header 10 + 5 breakpoints (24 / 72 / 240 / 304 / 352 = 6 / 18 / 60 / 76 / 88 % in the "
       "dump). The y data is commanded_throttle_filter_coefficient_by_throttle_difference_values." + NORAM)
rename('0x00406a52', 'commanded_throttle_filter_coefficient_by_throttle_difference_values',
       "Same lookup in cm848_calculateFuelDemandChangeRate: this word[6] is the y data and its result goes to commanded_throttle_filter_coefficient. Basis for the "
       "e2m name: block 1584 is not in the dumped ID table, so the address is not table-resolved; it is the Y of the 1583 / 1584 pair (5 points, UNITLESS at 1/65536, "
       "'throttle filter constant breakpoints'); dump 62259 / 62259 / 58982 / 32768 / 13107 = 0.95 / 0.95 / 0.90 / 0.50 / 0.20 is a filter weight that falls as the "
       "throttle difference grows, and commanded_throttle_filter_coefficient reads 62259 = 0.95; RAM address, so the _cal is wrong.",
       "(&fuel_mode_ema_state,input,fuel_mode_ema_axis_cal,fuel_mode_ema_output_cal,0);",
       "e2m 1584 Throttle_Filter_Constant_Table_Y 'Throttle filter constant breakpoints in throttle filter constant table' (UNITLESS, 1/65536, 5 points; not "
       "table-resolved because block 1584 is not in the dumped ID table - named by its code role, as the Y of the 1583 X table): the y data of the lookup in "
       "cm848_calculateFuelDemandChangeRate (x axis commanded_throttle_filter_coefficient_by_throttle_difference_axis); word[6] = header 10 + 5 points: 62259 / 62259 / "
       "58982 / 32768 / 13107 = 0.95 / 0.95 / 0.90 / 0.50 / 0.20 in the dump. The result becomes the weight of the previous value in the commanded throttle EMA "
       "filter, so a larger throttle difference gives a smaller weight and the filter follows fast changes." + NORAM)

# ---------------------------------------------------------------- data collector
rename('0x0040c270', 'data_collector_buffer_start_address',
       "hpcr_exception_process (the collector reset) stores &DAT_0040c28a here and in the logical start / end pointers; "
       "cm848_phase_groupB_calculation sets the buffer end pointer to this + (0x7fff - remainder) of a 0x8000-byte buffer; "
       "diag_dm1Buffer_circularFill and j1939_dm1_diagnosticMessage_send wrap the logical pointers back to it after they pass the end pointer; "
       "dump_raw 0 is not usable (the dump does not cover 0x40c200-0x40c27f, see the lead in the summary).",
       "data_collector_end_address = diag_dm1_buffer_start_ptr;",
       "e2m 0031 +0 Buffer_Start 'Actual starting RAM address of the data collector buffer' (HEX, 4 B; no dump value: the RAM dump is missing 0x40c200-0x40c27f): the "
       "physical start of the data collector's ring buffer, the first byte after the collector variables (hpcr_exception_process stores 0x40c28a here and "
       "in the logical start and end pointers). The fill and the sender wrap the logical pointers back to it after they pass the buffer end pointer "
       "data_collector_buffer_end_address (0x40c274); the buffer is 0x8000 bytes cut into equal slots. A ring buffer start pointer of the Cummins data collector, not of J1939 DM1." + NORAM,
       old_comment_wrong=True)

# ---------------------------------------------------------------- alpha fuel rate filter
rename('0x0005be66', 'alpha_fuel_rate_filter_coefficient',
       "cm848_initFuelPressureVariables points the coefficient of the EMA filter record at 0x3fa0d2 here; cm848_calculateSensorEma filters "
       "fuel_mass_flow_raw with that record into alpha_filtered_fuel_delivery_rate (the alpha fuel rate); e2m 104B +C Alpha_Fuel_Rate_Filter_Constant; "
       "65514 in the dump = 0.9997.",
       "&cold_start_intake_temperature_filter_coefficient;",
       "e2m 104B +C Alpha_Fuel_Rate_Filter_Constant '[APFLFTTC] Time constant of LB/HR filter used in the alpha fuel rate calculations' (1/65536; 65514 in "
       "the dump = 0.9997): the weight of the previous value (0 = no filtering) of the EMA filter record alpha_fuel_rate_filter_state (0x3fa0d2), whose coefficient pointer "
       "cm848_initFuelPressureVariables points here; cm848_calculateSensorEma filters fuel_mass_flow_raw with it into alpha_filtered_fuel_delivery_rate. "
       "Not an intake temperature. Flash / ROM constant, so no _cal.")

# ---------------------------------------------------------------- low speed governor alternator load (e2m 1064 +2A / +2C / +2E)
rename('0x004070e0', 'low_speed_governor_alternator_load_fuel_gain',
       "cm848_runLowSpeedGovernor: low_speed_governor_alternator_load_fuel = cm848_signedFirstOrderFilter((gain x (alternator_field_duty_target - offset)) "
       ">> 14, &governor_speed_filter); e2m 1064 +2A LSG_EVR_Gain; 38 in the dump = 0.040 mm3 per stroke per percent; RAM address, so the _cal is wrong.",
       "((int)(short)((int)((uint)governor_speed_filter_input_scale_cal *",
       "e2m 1064 +2A LSG_EVR_Gain 'Slope for EVR duty cycle to fuel conversion (mm3s/%)' (0.0010615 per count; 38 in the dump = 0.040 mm3 per stroke per "
       "percent): the gain of the low speed governor's alternator load term. cm848_runLowSpeedGovernor computes (this x (alternator_field_duty_target - "
       "low_speed_governor_alternator_load_duty_offset)) >> 14 (duty in 1/256 percent), filters it with the record low_speed_governor_alternator_load_filter (0x3faf56, coefficient "
       "low_speed_governor_alternator_load_filter_coefficient) into low_speed_governor_alternator_load_fuel." + NORAM)
rename('0x004070e2', 'low_speed_governor_alternator_load_duty_offset',
       "Same expression in cm848_runLowSpeedGovernor: the word is subtracted from alternator_field_duty_target (duty 0-25600 = 0-100 %) before the gain; "
       "e2m 1064 +2C LSG_EVR_Offset, unit %, 1/256 per count; 7680 in the dump = 30 %; RAM address, so the _cal is wrong.",
       "(uint)governor_speed_filter_fuel_offset_cal)) >> 0xe),",
       "e2m 1064 +2C LSG_EVR_Offset 'Offset for EVR duty cycle to fuel conversion' (%, 1/256 per count; 7680 in the dump = 30 %): the alternator field duty "
       "(alternator_field_duty_target, 0-25600 = 0-100 %) is measured from this offset: cm848_runLowSpeedGovernor subtracts it from the duty before "
       "multiplying by low_speed_governor_alternator_load_fuel_gain. A duty offset, not a fuel offset." + NORAM)
rename('0x004070e4', 'low_speed_governor_alternator_load_filter_coefficient',
       "cm848_initSpeedProtectionParameters points governor_speed_filter.coefficient here; cm848_runLowSpeedGovernor filters the alternator duty-to-fuel "
       "term with that record into low_speed_governor_alternator_load_fuel; e2m 1064 +2E Alternator_Load_Filter_Coefficient; 32706 in the dump = 0.499.",
       "governor_speed_filter.coefficient = &governor_speed_filter_coefficient;",
       "e2m 1064 +2E Alternator_Load_Filter_Coefficient 'Filters calculated alternator load for LSG compensation' (1/65536; 32706 in the dump = 0.499): the "
       "weight of the previous value (0 = no filtering) of the EMA filter record low_speed_governor_alternator_load_filter (0x3faf56), whose coefficient pointer "
       "cm848_initSpeedProtectionParameters points here; cm848_runLowSpeedGovernor filters the alternator load fuel term with it. ROM copy, so no _cal.")

# ---------------------------------------------------------------- 10E2 Jcomm percent peak torque / friction load
NOCALLER = ("its writers cm848_processThrottlePositionLookups (0x1820c) and cm848_calculateThrottleProtectionLimit (0x182e8) have no caller "
            "(no bl / b / bc to them in all.dis, no 32-bit pointer in the ROM or flash2 images), so the word stays 0")
rename('0x0040a630', 'j1939_no_load_fueling',
       "cm848_calculateThrottleProtectionLimit copies fuel_demand_base_offset (e2m 109C +0 No_Load_Fuel: friction + coolant, A/C and fan adjustments) here and "
       "subtracts the copy from final_fueling; e2m 10E2 +0 Jcomm_No_Load_Torque is 'estimated frictional no load fueling value'; " + NOCALLER + " (0 in the dump).",
       "fuel_demand_base_offset_snapshot = fuel_demand_base_offset;",
       "e2m 10E2 +0 Jcomm_No_Load_Torque '[JCFCLDTQ] Jcomm No Load Torque estimated frictional no load fueling value' (MM3S, 0.0679 mm3 per count; 0 in the "
       "dump): the no load (friction) fueling at the current speed and temperature: cm848_calculateThrottleProtectionLimit copies fuel_demand_base_offset "
       "(e2m 109C No_Load_Fuel) here and subtracts it from final_fueling to form j1939_percent_peak_torque_at_current_speed_times_256. That function has no "
       "caller in either bank, so the word stays 0." + NORAM)
rename('0x0040a632', 'j1939_percent_peak_torque_at_current_speed_times_256',
       "cm848_calculateThrottleProtectionLimit: cm848_signedDivisionWithSaturation((final_fueling - snapshot) x 0x6400, j1939_peak_fueling_tau_0 - "
       "j1939_friction_load_fueling_at_breakpoint_4), i.e. percent x 256 (0x6400 = 25600 = 100 x 256; e2m 10E2 +2 Jcomm_Percent_Peak_Torque, % signed, 1/256 per "
       "count); " + NOCALLER + " (0 in the dump).",
       "throttle_protection_load_ratio = cm848_signedDivisionWithSaturation (((int)(short)final_fueling - (int)(short)fuel_demand_base_offset_snapshot) * 0x6400",
       "e2m 10E2 +2 Jcomm_Percent_Peak_Torque '[JCPCPKTQ] Jcomm Percent Peak Torque based on current engine speed and temperature' (%, signed, 1/256 per "
       "count; 0 in the dump): (final_fueling - j1939_no_load_fueling) x 25600 / (j1939_peak_fueling_tau_0 - j1939_friction_load_fueling_at_breakpoint_4), the "
       "present fueling above no load as percent x 256 of the peak fueling span. Written only by cm848_calculateThrottleProtectionLimit, which has no "
       "caller in either bank, so it stays 0. Not a throttle protection." + NORAM)


def percent_row(address, new, old_line_quote, record_line, speed_name, friction_name, dump_note):
    short_record = ' '.join(record_line.split(' ')[:4])          # "e2m 10E2 +4 Jcomm_Prc_Pk_Trq_at_Brkpt_3"
    rename(address, new,
           "cm848_processThrottlePositionLookups stores cm848_throttlePositionProcessing(" + speed_name + ", " + friction_name + "): ((fuel limit grid at that "
           "speed and throttle 400 = 100 %) - (friction + coolant adjustment)) x 0x6400 / (j1939_peak_fueling_tau_0 - j1939_friction_load_fueling_at_breakpoint_4) "
           "= percent x 256; " + short_record + "; " + NOCALLER + " (0 in the dump).",
           old_line_quote,
           record_line + " (%, signed, 1/256 per count; 0 in the dump): ((fuel limit grid fueling at " + dump_note + " and 100 percent throttle) - (" +
           friction_name + " + the coolant friction adjustment)) x 25600 / (j1939_peak_fueling_tau_0 - j1939_friction_load_fueling_at_breakpoint_4), percent x 256, "
           "stored by cm848_processThrottlePositionLookups, which has no caller in either bank, so it stays 0." + NORAM)


percent_row('0x0040a634', 'j1939_percent_peak_torque_at_breakpoint_3_times_256',
            "throttle_position_b6 = cm848_throttlePositionProcessing (j1939_speed_breakpoint_3_tau_0,(int)(short)throttle_cal_b6_lookup);",
            "e2m 10E2 +4 Jcomm_Prc_Pk_Trq_at_Brkpt_3 '[JCPCTQ03] Jcomm Percent Peak Torque at Breakpoint 3 percent peak torque avail at brkpt 3'",
            'j1939_speed_breakpoint_3_tau_0', 'j1939_friction_load_fueling_at_breakpoint_3', 'speed breakpoint 3 (1400 rpm)')
percent_row('0x0040a636', 'j1939_percent_peak_torque_at_breakpoint_4_times_256',
            "throttle_position_b8 = cm848_throttlePositionProcessing (j1939_speed_breakpoint_4_tau_0, (int)(short)j1939_friction_load_fueling_at_breakpoint_4);",
            "e2m 10E2 +6 Jcomm_Prc_Pk_Trq_at_Brkpt_4 '[JCPCTQ04] Jcomm Percent Peak Torque at Breakpoint 4 percent peak torque avail at brkpt 4'",
            'j1939_speed_breakpoint_4_tau_0', 'j1939_friction_load_fueling_at_breakpoint_4', 'speed breakpoint 4 (2600 rpm)')
percent_row('0x0040a638', 'j1939_percent_peak_torque_at_breakpoint_5_times_256',
            "throttle_position_ba = cm848_throttlePositionProcessing (j1939_speed_breakpoint_5_tau_0,(int)(short)throttle_cal_ba_lookup);",
            "e2m 10E2 +8 Jcomm_Prc_Pk_Trq_at_Brkpt_5 '[JCPCTQ05] Jcomm Percent Peak Torque at Breakpoint 5 percent peak torque avail at brkpt 5'",
            'j1939_speed_breakpoint_5_tau_0', 'j1939_friction_load_fueling_at_breakpoint_5', 'speed breakpoint 5 (2800 rpm)')
percent_row('0x0040a63a', 'j1939_percent_peak_torque_at_idle_times_256',
            "throttle_position_from_integrator = cm848_throttlePositionProcessing (governor_output_t_0040aec2.idle_reference_speed, (int)(short)throttle_torque_integrator_lookup);",
            "e2m 10E2 +A Jcomm_Prc_Pk_Trq_at_Idle '[JCLSPCTQ] Jcomm Percent Peak Torque at Idle speed percent peak torque avail at idle rpm'",
            'governor_output_t.idle_reference_speed', 'j1939_friction_load_fueling_at_low_idle', 'the low speed governor reference speed')
percent_row('0x0040a63c', 'j1939_percent_peak_torque_at_rated_speed_times_256',
            "throttle_position_b4 = cm848_throttlePositionProcessing(j1939_rated_speed_tau_0,(int)(short)throttle_cal_b4_lookup);",
            "e2m 10E2 +C Jcomm_Prc_Pk_Trq_at_Rated_RPM '[JCRTPCTQ] Jcomm Percent Peak Torque at rated speed percent peak torque avail at rated rpm'",
            'j1939_rated_speed_tau_0', 'j1939_friction_load_fueling_at_rated_speed', 'the rated speed (2900 rpm)')


def friction_row(address, new, quote, record_line, where, dump):
    short_record = ' '.join(record_line.split(' ')[:4])          # "e2m 10E2 +E Jcomm_Frict_Load_at_Low_Idle"
    rename(address, new,
           "cm848_faultSeverityEvaluation: " + quote.split('=')[0].strip() + " = lookupTableInterpolation(friction_fuel_by_engine_speed_axis / _values at " + where +
           "); it is also the friction input of the percent peak torque calculation in cm848_processThrottlePositionLookups; " + short_record + "; " + dump.split(' = ')[0] + " in the dump (" + dump.split(' = ')[1] +
           ", matches the table interpolation).",
           quote,
           record_line + " (MM3S, 0.0679 mm3 per count; " + dump.split(' = ')[0] + " in the dump = " + dump.split(' = ')[1] + "): friction_fuel_by_engine_speed_values (the no load curve) looked up at " + where +
           " by cm848_faultSeverityEvaluation, which also runs once at start-up from cm848_initFaultSeverityTables. The friction term of the matching "
           "j1939_percent_peak_torque_at_*_times_256 point." + NORAM)


friction_row('0x0040a63e', 'j1939_friction_load_fueling_at_low_idle',
             "throttle_torque_integrator_lookup = lookupTableInterpolation (&friction_fuel_by_engine_speed_interpolation_state, governor_output_t_0040aec2.idle_reference_speed",
             "e2m 10E2 +E Jcomm_Frict_Load_at_Low_Idle '[JCFCLDIS] Frictional Load interpolated from the no load curve at LSG ref spd'",
             'the low speed governor reference speed (governor_output_t.idle_reference_speed)', '397 = 27.0 mm3')
friction_row('0x0040a640', 'j1939_friction_load_fueling_at_rated_speed',
             "throttle_cal_b4_lookup = lookupTableInterpolation (&friction_fuel_by_engine_speed_interpolation_state,j1939_rated_speed_tau_0",
             "e2m 10E2 +10 Jcomm_Frict_Load_at_Rated_RPM '[JCFCBKRR] Frictional load torque (in fueling) at rated engine RPM'",
             'the rated speed j1939_rated_speed_tau_0 (2900 rpm)', '340 = 23.1 mm3')
friction_row('0x0040a642', 'j1939_friction_load_fueling_at_breakpoint_3',
             "throttle_cal_b6_lookup = lookupTableInterpolation (&friction_fuel_by_engine_speed_interpolation_state,j1939_speed_breakpoint_3_tau_0",
             "e2m 10E2 +12 Jcomm_Frict_Load_at_Brkpt_3 '[JCFCBK03] Frictional load torque (in fueling) at breakpoint 3 engine RPM'",
             'speed breakpoint 3 j1939_speed_breakpoint_3_tau_0 (1400 rpm)', '97 = 6.6 mm3')
friction_row('0x0040a646', 'j1939_friction_load_fueling_at_breakpoint_5',
             "throttle_cal_ba_lookup = lookupTableInterpolation (&friction_fuel_by_engine_speed_interpolation_state,j1939_speed_breakpoint_5_tau_0",
             "e2m 10E2 +16 Jcomm_Frict_Load_at_Brkpt_5 '[JCFCBK05] Frictional load torque (in fueling) at breakpoint 5 engine RPM'",
             'speed breakpoint 5 j1939_speed_breakpoint_5_tau_0 (2800 rpm)', '311 = 21.1 mm3')

# ---------------------------------------------------------------- 1187 cruise droop family
DROOP_DIR = ("bottom droop = cruise_speed_command < vehicle_speed_rise_limited (vehicle above the set speed), else top droop")
rename('0x0040b698', 'cruise_control_fueling_bottom_droop_gain',
       "cm848_calculateCruiseControlFueling: with cruise_speed_command < vehicle_speed_rise_limited it copies this word to cruise_speed_reference_active and divides "
       "(speed excess x 1024) by it, a zero word gives fueling 0; governor_cruise_speedReference_update copies the computed bottom droop gain here while "
       "cruise_deadband_active_flag = 1 and cruise_control_engaged_flag = 1, else 0; e2m 1187 +2 Cruise_BDG; 0 in the dump; " + DROOP_DIR + ".",
       "cruise_speed_reference_active = cruise_speed_reference_a;",
       "e2m 1187 +2 Cruise_BDG 'SLOPE OF THE BOTTOM DROOP LINE PASSED TO THE DESIRED_CC FUELING PROCEDURE.' (MPH/MM3S, 0.00005615 per count; 0 in the dump): the "
       "bottom droop slope of the cruise fueling. With the set speed below the vehicle speed, cm848_calculateCruiseControlFueling divides the speed excess x 1024 by "
       "it (0 = no droop, fueling 0). governor_cruise_speedReference_update copies cruise_bottom_droop_gain here while droops are allowed "
       "(cruise_deadband_active_flag) and cruise is engaged, else 0." + NORAM)
rename('0x0040b69a', 'cruise_control_fueling_bottom_droop_offset',
       "cm848_calculateCruiseControlFueling: cruise_speed_deviation = this - (speed excess x 1024 / bottom droop gain), clamped 0..0x1700; written once by "
       "governorCruiseStateMachine (store at 0x525070) from governor_cruise_fuel_demand_setpoint; e2m 1187 +4 Cruise_BDO; 353 in the dump = 24.0 mm3; " + DROOP_DIR + ".",
       "cruise_speed_deviation = cruise_governor_fuel_demand_lower_ramp_start - uVar1;",
       "e2m 1187 +4 Cruise_BDO 'CRUISE BOTTOM DROOP OFFSET PASSED TO THE DESIRED_CC FUELING PROCEDURE.' (MM3S, 0.0679 mm3 per count; 353 in the dump = 24.0 mm3): "
       "the fueling at the set speed on the bottom droop line. With the set speed below the vehicle speed, cm848_calculateCruiseControlFueling outputs this minus "
       "(speed excess x 1024 / cruise_control_fueling_bottom_droop_gain), clamped to 0..5888. governorCruiseStateMachine stores it once from "
       "governor_cruise_fuel_demand_setpoint (store at 0x525070), with the road speed governor's bottom droop offset (e2m RSG_BDO)." + NORAM)
rename('0x0040b69c', 'cruise_bottom_droop_gain',
       "governor_cruise_setpoint_calc: wVar6 = this word for the fueling below governor_cruise_fuel_demand_setpoint: speed error delta = (fuel - setpoint) x it >> 10; "
       "governorCruiseStateMachine writes it through the unnamed store *(undefined2 *)(iVar3 + -0x4964) = uVar2 (iVar3 = 0x410000, so 0x40b69c) with "
       "uVar2 = governor_cruise_rampScale_calc(cruise_bottom_droop_width_cal, ...), or 0 when governor_cruise_fuel_demand_setpoint is not above governor_cruise_fuel_demand_min; "
       "e2m 1187 +6 Cruise_Bottom_Droop_Gain; 0 in the dump.",
       "wVar6 = cruise_ramp_rate_a_working;",
       "e2m 1187 +6 Cruise_Bottom_Droop_Gain 'SLOPE OF THE BOTTOM DROOP LINE CALCULATED IN CC/RSG DROOP' (MPH/MM3S, 0.00005615 per count; 0 in the dump): the cruise "
       "bottom droop slope computed by governorCruiseStateMachine as the output of governor_cruise_rampScale_calc(cruise_bottom_droop_width_cal, ...), 0 when "
       "governor_cruise_fuel_demand_setpoint is not above governor_cruise_fuel_demand_min. governor_cruise_setpoint_calc turns the fueling below "
       "governor_cruise_fuel_demand_setpoint into the speed error delta with it ((fuel - setpoint) x it >> 10); governor_cruise_speedReference_update passes it on as "
       "cruise_control_fueling_bottom_droop_gain." + NORAM, old_comment_wrong=True)
rename('0x0040b6ac', 'cruise_control_fueling_top_droop_gain',
       "cm848_calculateCruiseControlFueling: with the set speed at or above the vehicle speed it copies this word to cruise_speed_reference_active and divides "
       "(speed shortfall x 1024) by it; a zero word gives the maximum 0x1700; governor_cruise_speedReference_update copies the computed top droop gain here while "
       "cruise_deadband_active_flag = 1 and cruise_control_engaged_flag = 1, else 0; e2m 1187 +16 Cruise_TDG; 0 in the dump; " + DROOP_DIR + ".",
       "cruise_speed_reference_active = cruise_speed_reference_b;",
       "e2m 1187 +16 Cruise_TDG 'SLOPE OF THE TOP DROOP LINE PASSED TO THE DESIRED_CC FUELING PROCEDURE.' (MPH/MM3S, 0.00005615 per count; 0 in the dump): the top droop "
       "slope of the cruise fueling. With the set speed at or above the vehicle speed, cm848_calculateCruiseControlFueling outputs cruise_control_fueling_top_droop_offset "
       "+ (speed shortfall x 1024 / this), clamped to 0..5888; a zero word gives 5888. governor_cruise_speedReference_update copies cruise_top_droop_gain here while droops are "
       "allowed and cruise is engaged, else 0." + NORAM)
rename('0x0040b6ae', 'cruise_control_fueling_top_droop_offset',
       "cm848_calculateCruiseControlFueling: cruise_speed_deviation = (speed shortfall x 1024 / top droop gain) + this, clamped 0..0x1700; governorCruiseStateMachine "
       "starts it at cruise_speed_offset_default and governor_cruise_speedReference_update sets it to cruise_speed_offset_latched; e2m 1187 +18 Cruise_TDO; "
       "2208 in the dump = 150.0 mm3; " + DROOP_DIR + ".",
       "cruise_speed_deviation = uVar1 + cruise_speed_offset_b;",
       "e2m 1187 +18 Cruise_TDO 'CRUISE TOP DROOP OFFSET PASSED TO THE DESIRED_CC FUELING PROCEDURE.' (MM3S, 0.0679 mm3 per count; 2208 in the dump = 150.0 mm3): "
       "the fueling at the set speed on the top droop line, added to the speed shortfall term in cm848_calculateCruiseControlFueling. governorCruiseStateMachine starts it "
       "at cruise_speed_offset_default; governor_cruise_speedReference_update then sets it to the latched cruise top droop offset (e2m Cruise_RSG_Top_Droop_Offset, "
       "picked by cruise_speed_offset_mode)." + NORAM)
rename('0x0040b6b0', 'cruise_top_droop_gain',
       "governor_cruise_setpoint_calc: uVar2 = this word for the fueling above cruise_speed_offset_latched: speed error delta = (fuel - offset) x it >> 10; "
       "governor_cruise_speedReference_update re-selects cruise_ramp_rate_b_computed or DAT_003fcff2 by switch_input_state_bits[3] & 0x80 (switch 31) when "
       "drivetrain_type is DRIVETRAIN_MANUAL_VSS and two_speed_axle_enable_cal = 1, and passes it on as cruise_speed_reference_b; e2m 1187 +1A Cruise_Top_Droop_Gain; "
       "0 in the dump.",
       "cruise_speed_reference_b = cruise_ramp_rate_b_working;",
       "e2m 1187 +1A Cruise_Top_Droop_Gain 'SLOPE OF THE TOP DROOP LINE COMPUTED IN CC/RSG DROOP ALGORITHM.' (MPH/MM3S, 0.00005615 per count; 0 in the dump): the cruise top "
       "droop slope in use. governorCruiseStateMachine loads the value computed for the low rear axle ratio; with a manual drivetrain and two_speed_axle_enable_cal = 1, "
       "governor_cruise_speedReference_update re-selects the low or high axle ratio value by switch 31 (switch_input_state_bits[3] & 0x80). governor_cruise_setpoint_calc "
       "turns the fueling above the top droop offset into the speed error delta with it (>> 10); the speed reference passes it on as cruise_control_fueling_top_droop_gain."
       + NORAM, old_comment_wrong=True)

# ---------------------------------------------------------------- 11D5 air fuel control
rename('0x003ff00a', 'air_fuel_control_low_boost_time_delay',
       "cm848_calculateAirFuelControlFuelLimit: while final_fueling_state is FUELING_STATE_AIR_FUEL_CONTROL_DERATE air_fuel_control_low_boost_timer counts up while it is "
       "below this word; once it is not, the low boost blend fraction ramps up; e2m 11D5 +18 AFC_Low_Boost_Time_Delay (0.02 s per count); 0 in the dump.",
       "if (air_fuel_control_low_boost_timer < fuel_ramp_decrease_limit_cal) {",
       "e2m 11D5 +18 AFC_Low_Boost_Time_Delay 'Time allowed before AFC Low Boost Error is set' (SEC, 0.02 per count; 0 in the dump): cm848_calculateAirFuelControlFuelLimit "
       "counts air_fuel_control_low_boost_timer up to it while the final fueling state is the air fuel control derate; after that "
       "air_fuel_control_low_boost_blend_fraction ramps up by air_fuel_control_low_boost_blend_fraction_increase_step. RAM outside the EEPROM mirror, so no _cal; "
       "not a fuel ramp limit.")
rename('0x003ff00c', 'air_fuel_control_low_boost_blend_fraction_increase_step',
       "cm848_calculateAirFuelControlFuelLimit adds it to air_fuel_control_low_boost_blend_fraction (capped at 64000) each pass in the air fuel control derate state after "
       "the low boost time delay; e2m 11D5 +1A AFC_Pos_Select_Slew_Rate 'increment AFC_Select by this value' (1/64000 per count); 0 in the dump.",
       "air_fuel_control_low_boost_blend_fraction + fuel_ramp_increase_step_cal;",
       "e2m 11D5 +1A AFC_Pos_Select_Slew_Rate 'increment AFC_Select by this value' (UNITLESS, 1/64000 per count; 0 in the dump): the step cm848_calculateAirFuelControlFuelLimit "
       "adds to air_fuel_control_low_boost_blend_fraction (AFC_Select, 64000 = 1.0) each pass, after air_fuel_control_low_boost_time_delay, while the final fueling state is "
       "the air fuel control derate; the fraction is capped at 64000. RAM outside the EEPROM mirror, so no _cal; not a fuel ramp step.")
rename('0x003ff00e', 'air_fuel_control_low_boost_blend_fraction_decrease_step',
       "cm848_calculateAirFuelControlFuelLimit subtracts it from air_fuel_control_low_boost_blend_fraction (floor 0) each pass when the final fueling state is not the air fuel "
       "control derate, after the normal boost time delay; e2m 11D5 +1C AFC_Neg_Select_Slew_Rate 'decrement AFC_Select by this value'; 0 in the dump.",
       "air_fuel_control_low_boost_blend_fraction - fuel_ramp_decrease_step_cal;",
       "e2m 11D5 +1C AFC_Neg_Select_Slew_Rate 'decrement AFC_Select by this value' (UNITLESS, 1/64000 per count; 0 in the dump): the step cm848_calculateAirFuelControlFuelLimit "
       "subtracts from air_fuel_control_low_boost_blend_fraction each pass once air_fuel_control_normal_boost_time_delay has passed outside the air fuel control derate state; "
       "the fraction stops at 0. RAM outside the EEPROM mirror, so no _cal; not a fuel ramp step.")
rename('0x003ff010', 'air_fuel_control_normal_boost_time_delay',
       "cm848_calculateAirFuelControlFuelLimit: outside the air fuel control derate state air_fuel_control_normal_boost_timer counts up while it is below this word; once it is "
       "not, the low boost blend fraction ramps down; e2m 11D5 +1E AFC_Normal_Boost_Time_Delay (0.02 s per count); 0 in the dump.",
       "if (air_fuel_control_normal_boost_timer < fuel_ramp_increase_limit_cal) {",
       "e2m 11D5 +1E AFC_Normal_Boost_Time_Delay 'Time allowed before AFC Low Boost Error is Cleared' (SEC, 0.02 per count; 0 in the dump): cm848_calculateAirFuelControlFuelLimit "
       "counts air_fuel_control_normal_boost_timer up to it while the final fueling state is not the air fuel control derate; after that "
       "air_fuel_control_low_boost_blend_fraction ramps down by air_fuel_control_low_boost_blend_fraction_decrease_step. RAM outside the EEPROM mirror, so no _cal; "
       "not a fuel ramp limit.")

# ---------------------------------------------------------------- 1211 pending readiness code
rename('0x003fed98', 'monitor_pending_readiness_code_cal',
       "a failed monitor result clears its pending bit first (cm848_runFuelPressureSensorPlausibilityMonitor bit 0x80000, hpcr_checkRailPressureSensorBeforeStart bit 0x40) "
       "and only then its bit in monitor_readiness_code_cal; diag_resetSingleFault / diag_resetAllFaults set 0xffffffff (lwz / stw, 4 bytes); e2m 1211 +8 "
       "Pending_Readiness_Code at EEPROM 0x1916, inside the mirror 0x3fd482-0x3feec1, so it needs _cal; 4294967295 in the dump.",
       "if (((bVar2) && (bVar1)) && ((fault_pending_flags_b & 0x80000) != 0)) {",
       "e2m 1211 +8 Pending_Readiness_Code '[DGPDRDCD] Indicates Pending status for Readiness_Code' (HEX, 4 B; EEPROM 0x1916; 4294967295 in the dump = 0xFFFFFFFF): the pending twin of "
       "monitor_readiness_code_cal, one bit per OBD monitor, all set by diag_resetSingleFault / diag_resetAllFaults. A failed monitor result first clears its pending bit and, "
       "once that is clear, its readiness bit (cm848_runFuelPressureSensorPlausibilityMonitor bit 0x80000, hpcr_checkRailPressureSensorBeforeStart bit 0x40). One of the 59 "
       "references (fault_updateActiveCounters) is really the clear of the last slot of fault_entry_pointer_queue_cal, the next dword.")

# ---------------------------------------------------------------- 16A1 wastegate override value
rename('0x003ffca6', 'wastegate_duty_override_value',
       "cm848_calculateWastegateDutyRequest copies it into wastegate_duty_feedforward_term every pass; with wastegate_duty_integrator_preset_flag_cal != 1 the request is "
       "feedforward + proportional + integrator, with the flag = 1 it is the feedforward term alone (iVar7 = (short)wastegate_duty_feedforward_term), then clamped between "
       "the floor and ceiling half-duty counts; e2m 16A1 +E C_TGC_Override_Value; 0 in the dump; outside the EEPROM mirror, so no _cal.",
       "wastegate_duty_feedforward_term = throttle_rate_integrator_cal;",
       "e2m 16A1 +E C_TGC_Override_Value 'Override value for turbocharger position demand' (%, 1/128 percent per count, 12800 = 100 %; 0 in the dump): "
       "cm848_calculateWastegateDutyRequest copies it into wastegate_duty_feedforward_term every pass, so it is the feedforward base of the wastegate duty request "
       "(request = it + proportional + integrator, clamped to the floor and ceiling). While wastegate_duty_integrator_preset_flag_cal is 1 the request is this value "
       "alone, the override. RAM outside the EEPROM mirror, so no _cal; not a throttle rate integrator.")

# ---------------------------------------------------------------- 177C charge flow / volumetric efficiency
rename('0x00400932', 'charge_mass_flow_filter_coefficient',
       "cm848_initFilterTablePointers points boost_modifier_filter_state.coefficient here; cm848_loadBasedFuelAdjustment filters the clamped speed-density charge flow "
       "(engine speed x engine_volumetric_efficiency x map_fuel_correction_factor x engine_displacement_cubic_inches / (load_input x 0xa200)) with that record into "
       "charge_mass_flow_filtered; e2m 177C +0 C_CHP_Charge_Flow_Fil_Cnst; 13107 in the dump = 0.2.",
       "boost_modifier_filter_state.coefficient = &boost_modifier_filter_coefficient;",
       "e2m 177C +0 C_CHP_Charge_Flow_Fil_Cnst 'Filter constant for estimating charge flow' (1/65536; 13107 in the dump = 0.2): the weight of the previous value (0 = no "
       "filtering) of the EMA filter record boost_modifier_filter_state (0x3fa5d6), whose coefficient pointer cm848_initFilterTablePointers points here; "
       "cm848_loadBasedFuelAdjustment filters the clamped speed-density charge mass flow estimate with it into charge_mass_flow_filtered. ROM copy, so no _cal.")
rename('0x00400934', 'charge_mass_flow_estimate_maximum',
       "cm848_loadBasedFuelAdjustment: uVar3 = the minimum word; if (uVar3 <= flow && maximum < flow) uVar3 = maximum, so this word is the upper clamp; e2m 177C +2 "
       "C_CHP_Charge_Flow_Max (LB/MIN, 1/128 per count); 7680 in the dump = 60.0 lb/min; RAM address, so the _cal is wrong.",
       "if ((uVar3 <= uVar1) && (uVar3 = uVar1, fuel_quantity_ema_upper_limit_cal < uVar1)) {",
       "e2m 177C +2 C_CHP_Charge_Flow_Max 'Max limit on charge flow estimation' (LB/MIN, 1/128 per count; 7680 in the dump = 60.0 lb/min): the upper clamp of the "
       "speed-density charge mass flow estimate (engine speed x engine_volumetric_efficiency x intake pressure x engine_displacement_cubic_inches / temperature term) in "
       "cm848_loadBasedFuelAdjustment, before the charge_mass_flow_filtered filter." + NORAM)
rename('0x00400936', 'charge_mass_flow_estimate_minimum',
       "cm848_loadBasedFuelAdjustment: uVar3 = this word first and it stays unless the estimate is at or above it, so it is the lower clamp; e2m 177C +4 C_CHP_Charge_Flow_Min "
       "(LB/MIN, 1/128 per count); 0 in the dump; RAM address, so the _cal is wrong.",
       "uVar3 = (uint)boost_load_lower_limit_cal;",
       "e2m 177C +4 C_CHP_Charge_Flow_Min 'Min limit on charge flow estimation' (LB/MIN, 1/128 per count; 0 in the dump): the lower clamp of the speed-density charge mass "
       "flow estimate in cm848_loadBasedFuelAdjustment (the estimate is replaced by it when below it)." + NORAM)
rename('0x00400938', 'engine_stroke_inches',
       "cm848_boostBasedFuelModifier looks up (engine speed in 1/8 rpm x this) >> 16 = rpm x stroke in the table at 0x40094a whose axis dump 3780..16535 = 800..3500 rpm x 4.7244; "
       "e2m 177C +6 C_CHP_Veff_Stroke 'Engine stroke' (IN, 1/8192 per count); 38702 in the dump = 4.7244 in = 120 mm; RAM address, "
       "so the _cal is wrong.",
       "(uint)boost_rpm_scale_factor_cal >> 0x10),boost_rpm_scale_axis_cal,",
       "e2m 177C +6 C_CHP_Veff_Stroke 'Engine stroke' (IN, 1/8192 per count; 38702 in the dump = 4.7244 in = 120 mm): the stroke of the volumetric efficiency model. "
       "cm848_boostBasedFuelModifier multiplies the engine speed (1/8 rpm) by it and shifts right by 16, so rpm x stroke (a piston speed term; the lookup axis at 0x40094a runs "
       "800..3500 rpm x 4.7244 in) selects the speed modifier. Not a boost scale factor." + NORAM)
rename('0x0040093c', 'engine_bore_inches',
       "cm848_boostBasedFuelModifier squares it and divides by the squared valve diameter (computed_value = bore^2 x 1024 / valve^2, capped 0x5000); e2m 177C +A C_CHP_Veff_Bore "
       "'Engine bore' (IN, 1/8192 per count); 32897 in the dump = 4.0157 in = 102 mm; RAM address, so the _cal is wrong.",
       "uVar2 = (uint)boost_pressure_factor_cal * (uint)boost_pressure_factor_cal;",
       "e2m 177C +A C_CHP_Veff_Bore 'Engine bore' (IN, 1/8192 per count; 32897 in the dump = 4.0157 in = 102 mm): the bore of the volumetric efficiency model. "
       "cm848_boostBasedFuelModifier squares it and divides by the squared engine_valve_diameter_inches (computed_value = bore^2 x 1024 / valve^2, capped at 0x5000), the "
       "piston to valve area ratio term. Not a boost pressure factor." + NORAM)
rename('0x0040093e', 'engine_valve_diameter_inches',
       "cm848_boostBasedFuelModifier: uVar1 = this word, floored at 0x333 (0.1 in), divides the squared bore; e2m 177C +C C_CHP_Veff_Valve_Diameter 'valve diameter' (IN, 1/8192 per "
       "count); 8869 in the dump = 1.0826 in; RAM address, so the _cal is wrong.",
       "uVar1 = (uint)boost_pressure_divisor_cal;",
       "e2m 177C +C C_CHP_Veff_Valve_Diameter 'valve diameter' (IN, 1/8192 per count; 8869 in the dump = 1.0826 in): the valve diameter of the volumetric efficiency model; "
       "cm848_boostBasedFuelModifier floors it at 0x333 (0.1 in) and divides engine_bore_inches squared by its square. The e2m says only 'valve diameter'." + NORAM)
rename('0x00400940', 'engine_volumetric_efficiency_maximum',
       "cm848_boostBasedFuelModifier: if (maximum < result) engine_volumetric_efficiency = maximum, the upper clamp; e2m 177C +E C_CHP_Veff_Max (1/8192 per count); 8192 in the dump = 1.0; "
       "RAM address, so the _cal is wrong.",
       "(uint)fuel_demand_rpm_factor_upper_cal < (uVar3 & 0xffff))) {",
       "e2m 177C +E C_CHP_Veff_Max 'Max limit to volumetric efficiency' (UNITLESS, 1/8192 per count; 8192 in the dump = 1.0): the upper clamp of engine_volumetric_efficiency in "
       "cm848_boostBasedFuelModifier (the result is replaced by it when above it)." + NORAM)
rename('0x00400942', 'engine_volumetric_efficiency_minimum',
       "cm848_boostBasedFuelModifier: engine_volumetric_efficiency = this word first and it stays unless the result is at or above it, the lower clamp; e2m 177C +10 C_CHP_Veff_Min "
       "(1/8192 per count); 6554 in the dump = 0.80; RAM address, so the _cal is wrong.",
       "engine_volumetric_efficiency = fuel_demand_rpm_factor_base_cal;",
       "e2m 177C +10 C_CHP_Veff_Min 'Min limit to volumetric efficiency' (UNITLESS, 1/8192 per count; 6554 in the dump = 0.80): the lower clamp of engine_volumetric_efficiency in "
       "cm848_boostBasedFuelModifier (the result is replaced by it when below it)." + NORAM)
rename('0x00400944', 'engine_volumetric_efficiency_parameter_a',
       "cm848_boostBasedFuelModifier: term = ... x ((pressure ratio + parameter B) x (-this word)); the efficiency is parameter C minus the smaller of term and C; e2m 177C +12 "
       "C_CHP_Veff_Parameter_A 'Charge flow estimate parameter A' (signed, 1/1024 per count); -2577 in the dump = -2.517 (lha, so i16); RAM address, so the _cal is wrong.",
       "(-(int)(short)boost_map_correction_factor_cal & 0xffffU);",
       "e2m 177C +12 C_CHP_Veff_Parameter_A 'Charge flow estimate parameter A' (signed, 1/1024 per count; -2577 in the dump = -2.517): parameter A of the volumetric efficiency "
       "model, used negated as the gain of (pressure ratio + engine_volumetric_efficiency_parameter_b): cm848_boostBasedFuelModifier subtracts the product, scaled by the speed "
       "modifier and the bore / valve area ratio over the temperature term, from engine_volumetric_efficiency_parameter_c (pressure ratio = boost_pressure_current_raw / "
       "charge_pressure, clamped at 5.0)." + NORAM)
rename('0x00400946', 'engine_volumetric_efficiency_parameter_b',
       "cm848_boostBasedFuelModifier: (pressure ratio + this word) x (-parameter A); e2m 177C +14 C_CHP_Veff_Parameter_B 'Charge flow estimate parameter B' (1/1024 per count); "
       "2502 in the dump = 2.443; RAM address, so the _cal is wrong.",
       "uVar1 = (uVar2 + boost_pressure_offset_cal & 0xffff) *",
       "e2m 177C +14 C_CHP_Veff_Parameter_B 'Charge flow estimate parameter B' (UNITLESS, 1/1024 per count; 2502 in the dump = 2.443): parameter B of the volumetric efficiency "
       "model, the offset added to the pressure ratio before it is multiplied by -engine_volumetric_efficiency_parameter_a (cm848_boostBasedFuelModifier)." + NORAM)
rename('0x00400948', 'engine_volumetric_efficiency_parameter_c',
       "cm848_boostBasedFuelModifier: uVar3 = this word; uVar2 = min(term, uVar3); efficiency = uVar3 - uVar2 then clamped to the minimum / maximum words; e2m 177C +16 "
       "C_CHP_Veff_Parameter_C 'Charge flow estimate parameter C' (1/8192 per count); 10917 in the dump = 1.333; RAM address, so the _cal is wrong.",
       "uVar3 = (uint)boost_pressure_upper_limit_cal;",
       "e2m 177C +16 C_CHP_Veff_Parameter_C 'Charge flow estimate parameter C' (UNITLESS, 1/8192 per count; 10917 in the dump = 1.333): parameter C of the volumetric efficiency "
       "model: cm848_boostBasedFuelModifier caps the correction term at it and takes it minus the smaller of the term and it, then clamps the result between "
       "engine_volumetric_efficiency_minimum and engine_volumetric_efficiency_maximum." + NORAM)

# ---------------------------------------------------------------- 17A1 exhaust temperature model
rename('0x0040a682', 'exhaust_temperature_model_energy_fraction',
       "cm848_calculateCombustionTemperatureRise sums the injection timing, engine speed and boost pressure terms (e2m 17A2 C_TPE_Exhaust_* constants) plus an offset, clamps "
       "to 15000..53000 (the e2m range of 17A1 +4 TPE_Energy_Fraction) and stores it; exhaust_temperature_model_delta = (it << 8) / charge_fuel_ratio; "
       "cm848_calculateTemperatureHeadroomFuelCap divides its fuel flow limit by it; 0 in the dump.",
       "boost_target_load_rpm_output = (word)uVar1;",
       "e2m 17A1 +4 TPE_Energy_Fraction 'TPE energy fraction' (DEG_F, 2 B, range 15000..53000; 0 in the dump): the heat term of the exhaust temperature model: "
       "cm848_calculateCombustionTemperatureRise sums the injection timing, engine speed and boost pressure terms (e2m C_TPE_Exhaust_* constants) plus an offset, clamps it to "
       "exactly 15000..53000 and stores it. exhaust_temperature_model_delta = it << 8 / charge_fuel_ratio, and cm848_calculateTemperatureHeadroomFuelCap divides its fuel flow "
       "limit by it. Not a boost target." + NORAM, old_comment_wrong=True)

# ---------------------------------------------------------------- 8000 HPCR fuel pressure governor / fuel metering command
HPCR_CLAMP = ("cm848_calculateFuelMeteringCommand: wVar5 = engine_sync_timing_upper_limit_cal, replaced by engine_sync_timing_coldstart_limit_cal when "
              "engine_state == ENGINE_STATE_RUNNING; fuel_pressure_governor_demand is clamped to [wVar5, rpm table limit] ('(short)demand < (short)wVar5' puts wVar5 in and "
              "restores the integrator)")
rename('0x00409110', 'fuel_pressure_governor_demand_minimum_when_not_running',
       HPCR_CLAMP + "; e2m 8000 +16 HPCR_Min_Dutycycle_Start says start, the code applies it in every state except RUNNING; -122 in the dump (i16, lha) = -3.0 %.",
       "wVar5 = engine_sync_timing_upper_limit_cal;",
       "e2m 8000 +16 HPCR_Min_Dutycycle_Start 'Minimum duty cycle during start' (%, signed, 0.0244 per count; -122 in the dump = -3.0 %): the lower limit of "
       "fuel_pressure_governor_demand (engine_sync_state_t) in cm848_calculateFuelMeteringCommand whenever engine_state is not RUNNING (the e2m says start); the demand is "
       "clamped between it and the rpm table limit, and the integrator is put back while the demand is outside. Not an engine sync timing limit." + NORAM)
rename('0x00409112', 'fuel_pressure_governor_demand_minimum_when_running',
       HPCR_CLAMP + "; e2m 8000 +18 HPCR_Min_Dutycycle_Normal; -122 in the dump (i16, lha) = -3.0 %.",
       "wVar5 = engine_sync_timing_coldstart_limit_cal;",
       "e2m 8000 +18 HPCR_Min_Dutycycle_Normal 'Minimum duty cycle during normal operation' (%, signed, 0.0244 per count; -122 in the dump = -3.0 %): the lower limit of "
       "fuel_pressure_governor_demand while engine_state is RUNNING (fuel_pressure_governor_demand_minimum_when_not_running applies in the other states), in "
       "cm848_calculateFuelMeteringCommand. Not a cold start limit." + NORAM)
keep('0x00409114', "e2m 8000 +1A HPCR_Min_Pressure_Deflate_Start 'Minimum pressure to start deflation'")
keep('0x00409116', "e2m 8000 +1C HPCR_Min_RPM_Deflate_Start 'Minimum engine speed to start deflation'")
keep('0x00409118', "e2m 8000 +1E HPCR_Max_RPM_Deflate_Start 'Maximum engine speed to start deflation'")
keep('0x0040911e', "e2m 8000 +24 HPCR_Dutycycle_Repl_Testbench 'Replacement value used in test bench mode'")
rename('0x00409120', 'fuel_metering_command_override_enable',
       "cm848_calculateFuelMeteringCommand returns early with fuel_metering_command = the override value while this byte is nonzero; "
       "cm848_monitorFuelPressureTrackingError and cm848_monitorFuelPressureSetpointNotReached run only while it is 0; e2m 8000 +26 HPCR_Fuelpr_Dutycycle_Override_Switch_N "
       "(1 B); 0 in the dump.",
       "if (engine_speed_override_enable_cal != 0) {",
       "e2m 8000 +26 HPCR_Fuelpr_Dutycycle_Override_Switch_N 'Override switch for duty cycle output to fuel pressure regulator' (UNITLESS, 1 B; 0 in the dump): "
       "cm848_calculateFuelMeteringCommand returns early with fuel_metering_command = fuel_metering_command_override_value while it is nonzero; the rail pressure tracking "
       "error and setpoint-not-reached monitors run only while it is 0. Not an engine speed override." + NORAM)
rename('0x00409121', 'fuel_metering_command_override_value',
       "cm848_calculateFuelMeteringCommand stores it into engine_sync_state_t.fuel_metering_command (0-4095) while the override byte is nonzero; e2m 8000 +27 "
       "HPCR_Fuelpr_Dutycycle_Override_Value (%, signed, 0.0244 per count; odd address, one lha); 0 in the dump.",
       "engine_sync_state_t_0040b87f.fuel_metering_command = engine_speed_override_value_cal;",
       "e2m 8000 +27 HPCR_Fuelpr_Dutycycle_Override_Value 'Override value for duty cycle output to fuel pressure regulator' (%, signed, 0.0244 per count, odd address; 0 in the "
       "dump): the fuel metering command (0-4095) that cm848_calculateFuelMeteringCommand outputs while fuel_metering_command_override_enable is nonzero." + NORAM)
keep('0x00409123', "e2m 8000 +29 HPCR_Dutycycle_Deflate 'Duty cycle during deflate'")
keep('0x00409126', "e2m 8000 +2C HPCR_Measured_Current_Filter_Constant 'Time constant for the filter used on the measured current'")
keep('0x00409128', "e2m 8000 +2E HPCR_Duty_To_Current_Filter_Constant 'Time constant for the filter used on the converted dutycycle to current'")
rename('0x0040912a', 'fuel_metering_battery_voltage_filter_coefficient',
       "cm848_calculateFuelMeteringCommand points cam_sync_speed_filter_state.coefficient at this address (at sensor_channel_config_t_00059336, the channel's own coefficient, while "
       "the governor mode is OPEN_LOOP_START); cm848_filterEngineSensorValue filters sensor_channel2_ram.value (the battery voltage channel: cm848_sensorChannel2_init passes "
       "battery_voltage_linearization_axis and slot 4) with that record into the word at 0x40b884 (engine_sync_state_t reserved_05), the input of the cam_sync_speed_output_scale lookup that scales fuel_metering_command; "
       "e2m 8000 +30 HPCR_Battery_Voltage_Filter_Constant is 2 B and this row is a byte; 0 in the dump (byte and word).",
       "pbVar13 = &cam_sync_speed_filter_state_cal;",
       "e2m 8000 +30 HPCR_Battery_Voltage_Filter_Constant 'Time constant for the battery voltage filter for fuel pressure control' (UNITLESS, 1/65536, 2 B; 0 in the dump = no "
       "filtering): the weight of the previous value of the battery voltage filter record cam_sync_speed_filter_state (0x3fb697); cm848_calculateFuelMeteringCommand points its "
       "coefficient here (at the sensor channel's own coefficient while the governor mode is OPEN_LOOP_START), and the filtered value, the word at 0x40b884 (engine_sync_state_t reserved_05), feeds the lookup that scales "
       "fuel_metering_command." + NORAM,
       type_note="row is a byte but the e2m record is 2 B and the filter reads the coefficient as a 16-bit word through its pointer: widen to word (0x40912b has no row, the next row "
                 "is 0x40912c)",
       split=[{"address": "0x0040912a", "name": "fuel_metering_battery_voltage_filter_coefficient", "type": "word",
               "comment": "e2m 8000 +30 HPCR_Battery_Voltage_Filter_Constant 'Time constant for the battery voltage filter for fuel pressure control' (UNITLESS, 1/65536, 2 B; "
                          "0 in the dump = no filtering): the weight of the previous value of the battery voltage filter record cam_sync_speed_filter_state, whose coefficient "
                          "pointer cm848_calculateFuelMeteringCommand points here (at the sensor channel's own coefficient while the governor mode is OPEN_LOOP_START). "
                          "RAM outside the EEPROM mirror, so no _cal."}])
keep('0x0040912e', "e2m 8000 +34 HPCR_Throttle_FF_Filter_Constant 'Time constant for Throttle Derivative Component'")
FF = ("cm848_calculateFuelMeteringCommand: iVar14 = (gain x (fuel_demand_control.calculated - fuel_demand_calculated_snapshot)) >> 10, clamped to [minimum word, "
      "maximum word] ('minimum <= iVar14' keeps it, 'maximum < iVar14' takes the maximum), then filtered into fuel_pressure_governor_accelerator_feed_forward")
rename('0x00409130', 'fuel_pressure_governor_accelerator_feed_forward_gain',
       FF + "; e2m 8000 +36 HPCR_Throttle_FF_Deriv_Gain; 65535 in the dump.",
       "iVar14 = (int)(short)((int)((uint)cam_sync_fuel_scale_gain_cal *",
       "e2m 8000 +36 HPCR_Throttle_FF_Deriv_Gain 'Gain for Throttle Derivative Component' (%; 65535 in the dump): the gain of the accelerator feed forward: "
       "cm848_calculateFuelMeteringCommand multiplies the change of fuel_demand_control.calculated since the last pass by it, shifts right by 10, clamps the product between "
       "fuel_pressure_governor_accelerator_feed_forward_minimum and _maximum and filters it (coefficient fuel_pressure_governor_accelerator_feed_forward_filter_coefficient) "
       "into fuel_pressure_governor_accelerator_feed_forward. Not a cam sync scale." + NORAM)
rename('0x00409132', 'fuel_pressure_governor_accelerator_feed_forward_minimum',
       FF + "; e2m 8000 +38 HPCR_Min_Throttle_Deriv; -820 in the dump (i16, lha) = -20.0 %.",
       "iVar12 = (int)(short)cam_sync_fuel_scale_lower_limit_cal;",
       "e2m 8000 +38 HPCR_Min_Throttle_Deriv 'Minimum value for Throttle Derivative Component' (%, signed, 0.0244 per count; -820 in the dump = -20.0 %): the lower clamp of the "
       "gain x accelerator demand change term before it is filtered into fuel_pressure_governor_accelerator_feed_forward (cm848_calculateFuelMeteringCommand)." + NORAM)
rename('0x00409134', 'fuel_pressure_governor_accelerator_feed_forward_maximum',
       FF + "; e2m 8000 +3A HPCR_Max_Throttle_Deriv; 0 in the dump (i16, lha).",
       "(iVar12 = iVar14, (short)cam_sync_fuel_scale_upper_limit_cal < iVar14)) {",
       "e2m 8000 +3A HPCR_Max_Throttle_Deriv 'Maximum value for Throttle Derivative Component' (%, signed, 0.0244 per count; 0 in the dump): the upper clamp of the gain x "
       "accelerator demand change term before it is filtered into fuel_pressure_governor_accelerator_feed_forward (cm848_calculateFuelMeteringCommand). With the dump's "
       "minimum -820 and maximum 0 only a falling accelerator demand gives a feed forward." + NORAM)
rename('0x00409136', 'fuel_metering_command_maximum',
       "cm848_calculateFuelMeteringCommand after the battery voltage scaling: wVar5 = this word; if (this < (short)fuel_metering_command) fuel_metering_command = wVar5, so it is the "
       "upper clamp; e2m 8000 +3C HPCR_Dutycycle_Output_Max; 4016 in the dump (i16, lha) = 98.0 %.",
       "wVar5 = engine_sync_speed_upper_limit_cal;",
       "e2m 8000 +3C HPCR_Dutycycle_Output_Max 'Maximum value for HPCR_Dutycycle_Output' (%, signed, 0.0244 per count; 4016 in the dump = 98.0 %): the upper clamp of "
       "fuel_metering_command (0-4095), applied after the battery voltage scaling and before the read-back retest in cm848_calculateFuelMeteringCommand. Not an engine sync "
       "speed limit." + NORAM)
rename('0x00409138', 'fuel_metering_command_minimum',
       "cm848_calculateFuelMeteringCommand after the battery voltage scaling: if ((short)fuel_metering_command < (short)this word) fuel_metering_command = wVar5 = this word, so it is "
       "the lower clamp; e2m 8000 +3E HPCR_Dutycycle_Output_Min; 0 in the dump (i16, lha).",
       "(wVar5 = engine_sync_speed_lower_limit_cal,",
       "e2m 8000 +3E HPCR_Dutycycle_Output_Min 'Minimum value for HPCR_Dutycycle_Output' (%, signed, 0.0244 per count; 0 in the dump): the lower clamp of fuel_metering_command "
       "(0-4095), applied after the battery voltage scaling and before the read-back retest in cm848_calculateFuelMeteringCommand. Not an engine sync speed limit." + NORAM)
# ---------------------------------------------------------------- 8C34 converter clutch rationality / governor pressure loop
rename('0x0040b57d', 'converter_clutch_rationality_ratio_delta',
       "cm848_pidError_calc stores protection_pid_rpm_setpoint_prev - converter_clutch_rationality_ratio (saturated to 16 bits) here and cm848_pidIntegrator_accumulate adds it "
       "into converter_clutch_rationality_ratio_delta_sum, both from cm848_monitorConverterClutchAndOverdrivePerformance; e2m 8C34 +3 TCC_Rationality_Ratio_Delta matches "
       "('Change in RPM/OSS delta since previous cycle'); odd address, one lha / sth; 0 in the dump.",
       "iVar1 = (int)(short)converter_clutch_rationality_ratio_delta_sum + (int)(short)protection_pid_error_term;",
       "e2m 8C34 +3 TCC_Rationality_Ratio_Delta 'Change in RPM/OSS delta since previous cycle' (UNITLESS, signed, 1/256 per count, odd address; 0 in the dump): the change of the "
       "engine to output speed ratio since the previous monitor pass: cm848_pidError_calc stores (previous ratio - converter_clutch_rationality_ratio) saturated to 16 bits "
       "and cm848_pidIntegrator_accumulate adds it into converter_clutch_rationality_ratio_delta_sum, in the converter clutch rationality monitor "
       "cm848_monitorConverterClutchAndOverdrivePerformance. The previous ratio is protection_pid_rpm_setpoint_prev (0x3fcefe). Not a protection PID." + NORAM,
       old_comment_wrong=True)
rename('0x0040b58c', 'governor_pressure_controller_error_delta_term',
       "DRIFT: e2m 8C34 +12 TCC_Function_Timer (SEC, 0.5 per count, 0..60) resolves here but the 8C34 monitor words end at +10; the code is the governor pressure solenoid loop: "
       "cm848_throttleGain_velocityBased_calc stores clamp(protection_throttle_error_delta x protection_throttle_velocity_gain x 0x100 / (DAT_00408aee << 7), +-0x6400) here, "
       "where protection_throttle_error_delta = governor_pressure_error - the previous error (cm848_controlGovernorPressureSolenoid), adds it to governor_pressure_controller_output "
       "and limits the sum with cm848_throttleSetpoint_limit; 1 in the dump.",
       "protection_throttle_velocity_term = (word)iVar1;",
       "e2m 8C34 +12 TCC_Function_Timer 'Count of how long the TCC driver has been on this drive cycle' resolves here but does not match (drift: the 8C34 monitor words end at "
       "+10; 1 in the dump): the code uses this word as the error delta term of the governor pressure controller. cm848_throttleGain_velocityBased_calc stores "
       "clamp(error delta x gain x 256 / (DAT_00408aee << 7), +-25600) from the change of governor_pressure_error between passes, adds it to governor_pressure_controller_output "
       "and limits the sum (cm848_throttleSetpoint_limit)." + NORAM, old_comment_wrong=True)
drift('0x0040b58e',
      "e2m 8C34 +14 OD_Function_Timer (2 B) and +16 TCC_Ratio (2 B) resolve into this dword, but the code uses the whole dword as one signed 32-bit error: "
      "cm848_controlGovernorPressureSolenoid stores governor_pressure_target - governor_pressure (stw) and cm848_throttleGain_loadBased_calc / _velocityBased_calc read it with lwz "
      "(29 references, 'if ((int)governor_pressure_error < 0)'); 65535 in the dump; the name fits the code, no split.")

# ---------------------------------------------------------------- assemble in bin order
bin_items = json.load(open(BIN))
missing = [it['address'] for it in bin_items if it['address'] not in R]
extra = [a for a in R if a not in {it['address'] for it in bin_items}]
assert not missing and not extra, (missing, extra)
with open(OUT, 'w') as f:
    for it in bin_items:
        r = R[it['address']]
        line = {'kind': 'global', 'verdict': r['verdict'], 'address': it['address'], 'old': it['current_name']}
        if r['verdict'] == 'confirmed':
            line['new'] = r['new']
        elif r['verdict'] == 'keep':
            line['new'] = it['current_name']
            line['e2m_note'] = r['e2m_note']
        for key in ('evidence', 'code_quote', 'comment', 'type_note', 'split', 'old_comment_wrong'):
            if key in r:
                line[key] = r[key]
        f.write(json.dumps(line) + '\n')
print('wrote', len(bin_items), 'lines to', OUT)
