"""Build the result lines of bin1 and append them to the result file, per e2m block.
usage: emit.py <block> [<block> ...]    (a record whose address is already in the result file is skipped)"""
import json
import os
import sys

BIN = '/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'
RESULT = '/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin1.jsonl'

records = {r['address']: r for r in json.load(open(BIN))}
by_block = {}
for r in records.values():
    by_block.setdefault(r['block'], []).append(r)

ENTRIES = {}


def offset_text(r):
    return '+%s' % (r['offset'].lstrip('0').upper() or '0')


def keep(addr):
    r = records[addr]
    note = "e2m %s %s %s '%s'" % (r['block'], offset_text(r), r['record'], r['description'])
    ENTRIES[addr] = {"kind": "global", "verdict": "keep", "address": addr, "old": r['label_in_cpp'],
                     "new": r['label_in_cpp'], "e2m_note": note}


def rename(addr, new, evidence, code_quote, comment):
    r = records[addr]
    ENTRIES[addr] = {"kind": "global", "verdict": "confirmed", "address": addr, "old": r['label_in_cpp'], "new": new,
                     "evidence": evidence, "code_quote": code_quote, "comment": comment}


def drift(addr, evidence):
    r = records[addr]
    ENTRIES[addr] = {"kind": "global", "verdict": "drift", "address": addr, "old": r['label_in_cpp'],
                     "evidence": evidence}


def uncertain(addr, evidence):
    r = records[addr]
    ENTRIES[addr] = {"kind": "global", "verdict": "uncertain", "address": addr, "old": r['label_in_cpp'],
                     "evidence": evidence}


# ---------------------------------------------------------------- 105D
keep('0x0040afb4')

# ---------------------------------------------------------------- 1070
keep('0x0040a36a')
drift('0x0040a372',
      "record not implemented as described (the block layout is not shifted: +1E / +22 match): e2m 1070 +20 "
      "EB_Active_Driver_Fraction (UNITLESS, 1/8192 per count, 0-1, 'fraction of engine brake hardware "
      "currently active'): the only access is cm848_driveEngineRetarderOutput storing 0 or 100 from the wired retarder "
      "switch (switch_input_state_bits[1] mask 0x10), the same value cm848_calculateEngineRetarderSelectionPercent "
      "stores at 0x40a362; no reader; 100 is not a 1/8192 fraction and nothing computes the active hardware here (the "
      "engaged state is 0x40a374), so the code does not match the record; the current name describes what the code "
      "does")

# ---------------------------------------------------------------- 107C
rename('0x0040a1b2', 'all_speed_governor_reset_flag',
       "e2m 107C +8 ASG_Reset_State (UNITLESS): cm848_runOperatingModeSpeedGovernor sets it to 1 at the point that "
       "reloads the all-speed governor states (governor_pid_integral_state rebuilt and governor_fuel_demand_prev_ref "
       "reset, after the external reset restore or the re-seed from final_fueling) and to 0 on a normal pass; 3 stores, "
       "0 reads; the old name said fuel correction output active",
       "cm848_runOperatingModeSpeedGovernor: fuel_correction_output_active_flag = 1;",
       "e2m 107C +8 ASG_Reset_State '[ASRSST] ASG reset flag' (UNITLESS, 16-bit; 1 in the dump) (address from the ECU's "
       "parameter ID table): set to 1 by cm848_runOperatingModeSpeedGovernor at the point that reloads the all-speed "
       "governor states - governor_pid_integral_state is rebuilt and governor_fuel_demand_prev_ref is reset to the "
       "no-load fuel, either from the saved reset state (all_speed_governor_external_reset_flag = 1) or re-seeded from "
       "final_fueling when governor_fuel_demand_tracking no longer matches it - and cleared to 0 on a normal "
       "closed-loop pass; 3 stores (sth), no reader. It is not a fuel correction output flag.")
rename('0x0040a1cc', 'all_speed_governor_integral_adjustment',
       "e2m 107C +22 ASG_QI_Adjustment (MM3S, 4 B signed): cm848_runOperatingModeSpeedGovernor adds it into the PID "
       "accumulator sum fuel_demand_pid_accumulator = (this + the speed error terms x gain coefficients + the QP "
       "adjustment) >> 9; its only store is the zero in cm848_initFuelDemandVariables; the old name said accumulator "
       "hi (its twin at +2A said lo, the code adds both alike); type dword but the record is signed (i32 candidate)",
       "cm848_runOperatingModeSpeedGovernor: dVar4 = (int)(fuel_demand_pid_accum_hi +",
       "e2m 107C +22 ASG_QI_Adjustment '[ASQIAJ] ASG Quadratic Integral Adjustment' (MM3S, 4 B, 0.00013268512 per "
       "count, signed, -2000..2000; 0 in the dump) (address from the ECU's parameter ID table): the QI adjustment "
       "added into the PID accumulator of cm848_runOperatingModeSpeedGovernor, fuel_demand_pid_accumulator = (this + "
       "the speed error terms x gain coefficients + the QP adjustment at 0x40a1d4) >> 9, clamped to +-0xe6000; the only "
       "store is the zero in cm848_initFuelDemandVariables so it stays 0. Twin of "
       "all_speed_governor_derivative_adjustment (QD, e2m 107C +1A). Type dword; the record is signed 4 B (i32 "
       "candidate, both users load / store 32 bits).")
rename('0x0040a1d4', 'all_speed_governor_proportional_adjustment',
       "e2m 107C +2A ASG_QP_Adjustment (MM3S, 4 B signed): cm848_runOperatingModeSpeedGovernor adds it into the PID "
       "accumulator sum fuel_demand_pid_accumulator = (the QI adjustment + the speed error terms x gain coefficients + "
       "this) >> 9; its only store is the zero in cm848_initFuelDemandVariables; the old name said accumulator lo (its "
       "twin at +22 said hi, the code adds both alike); type dword but the record is signed (i32 candidate)",
       "cm848_runOperatingModeSpeedGovernor: (int)*(short *)(fuel_demand_pid_coeffs + 2)) + "
       "fuel_demand_pid_accum_lo) >> 9;",
       "e2m 107C +2A ASG_QP_Adjustment '[ASQPAJ] ASG Quadratic Proportional Adjustment' (MM3S, 4 B, 0.00013268512 per "
       "count, signed, -2000..2000; 0 in the dump) (address from the ECU's parameter ID table): the QP adjustment "
       "added into the PID accumulator of cm848_runOperatingModeSpeedGovernor, fuel_demand_pid_accumulator = (the QI "
       "adjustment at 0x40a1cc + the speed error terms x gain coefficients + this) >> 9, clamped to +-0xe6000; the "
       "only store is the zero in cm848_initFuelDemandVariables so it stays 0. Twin of "
       "all_speed_governor_derivative_adjustment (QD, e2m 107C +1A). Type dword; the record is signed 4 B (i32 "
       "candidate, both users load / store 32 bits).")

# ---------------------------------------------------------------- 10E7
keep('0x0005c39e')

# ---------------------------------------------------------------- 1180
rename('0x003fd532', 'cruise_discrete_switch_inputs_used_cal',
       "e2m 1180 +A Cruise_Use_Discrete_Switch_Inputs (UNITLESS): EEPROM mirror word (EEPROM 0xb0 = 0 in the dump and "
       "the EEPROM image; the block is aligned: Rear_Axle_Ratio_Low +6 / _High +C at EEPROM 0xac / 0xb2 both read 453 "
       "either side of it); its only reader cm848_checkSwitch31OnTimeFault gates the switch 31 pass-through on (this = 0 "
       "or switch_31_on_time_fault_enable), i.e. the Ford multiplexed path; the old name said protection init flag and "
       "lacked the _cal of the EEPROM mirror",
       "cm848_checkSwitch31OnTimeFault: if (((protection_system_init_flag == 0) || "
       "(switch_31_on_time_fault_enable != 0)) &&",
       "e2m 1180 +A Cruise_Use_Discrete_Switch_Inputs '[CRUSDSSW] Indicates discrete(T) or Ford multiplexed(F) cruise "
       "switches used.' (UNITLESS, 16-bit; EEPROM 0xb0 = 0 in the dump and the EEPROM image, i.e. Ford multiplexed "
       "cruise switches) (address from the ECU's parameter ID table): EEPROM-backed (the 0x3fd482 mirror) so _cal; the "
       "block is aligned (Rear_Axle_Ratio_Low +6 / _High +C at EEPROM 0xac / 0xb2 read 453 either side). Its only "
       "reader is cm848_checkSwitch31OnTimeFault (lhz @ 0x2c518), which runs the switch 31 pass-through block when this "
       "is 0 (multiplexed switches) or switch_31_on_time_fault_enable is set (the stores there are no-ops in this "
       "build). Not a protection init flag.")
keep('0x003fd536')

# ---------------------------------------------------------------- 118D
rename('0x0040b6e2', 'engine_speed_to_vss_ratio',
       "e2m 118D +2 Engine_VSS_Ratio (UNITLESS, 1/128, 10-500): cm848_calculateRiseLimitedVehicleSpeed stores "
       "protection_timing_period_cal (e2m 132C Tire_Size, tire revolutions per mile) x rear_axle_ratio / 60 here "
       "(1895 in the dump = 14.8) and divides the engine speed by (this x drivetrain_ratio_user_filtered) to predict "
       "the vehicle speed when fuel_flow_rpm_mode_flag is 0; the old name said fuel flow; the only access is the "
       "store, no reader",
       "cm848_calculateRiseLimitedVehicleSpeed: fuel_flow_rpm_numerator = (word)uVar1;",
       "e2m 118D +2 Engine_VSS_Ratio 'ratio of engine speed to transmission' (UNITLESS, 0.0078125 per count = 1/128, "
       "10-500; 1895 = 14.8 in the dump) (address from the ECU's parameter ID table): recomputed every pass by "
       "cm848_calculateRiseLimitedVehicleSpeed as protection_timing_period_cal (e2m 132C +0 Tire_Size, tire "
       "revolutions per mile) x rear_axle_ratio (1/128 per count) / 60, masked with 0x7fff - the output shaft rpm per "
       "mph x 128, i.e. the engine to vehicle speed factor before the transmission ratio. With fuel_flow_rpm_mode_flag "
       "= 0 (e2m 118B +2 Cruise_RSG_Feedback_Parameter: 0 = predicted vehicle speed) the predicted vehicle speed is "
       "engine speed x 65536 / (this x drivetrain_ratio_user_filtered >> 9) >> 2, rise limited into "
       "vehicle_speed_rise_limited. The only access is the store (the division uses the local copy), no reader. Not a "
       "fuel flow numerator.")

# ---------------------------------------------------------------- 11F9
drift('0x0005a9c4',
      "e2m 11F9 +8 OBD_Fuel_Type (HEX, 'Type of Fuel Currently being used by vehicle'): 0x5a9c4 is the length word "
      "(12) of the ROM table governor_tuning_set_blend_weight_by_drivetrain_ratio_axis that cm848_blendGovernorTuningSets "
      "reads (breakpoints 1843 / 2458 / 3482 / 6144 / 10240 / 40960 at 0x5a9c6-0x5a9d0), and e2m 8A4F +0 "
      "ASG_Gear_Ratio_Axis 'ASG Gear Ratio breakpoint table' shares this address and matches the code; 11F9 +0..+6 "
      "(words 0x2300 0x2300 0x01f4 0x0005) end at 0x5a9c3 and no OBD fuel type is stored after them in 11.46.06, "
      "so the last record of 11F9 has no storage of its own (as in 8C34 / 8C56 / 8C5B / 1632); the name stays")

# ---------------------------------------------------------------- 1298
rename('0x0005c950', 'high_speed_governor_working_gain_set_application_priority',
       "e2m 1298 +0 HSG_GR_Application_Priority (HEX): cm848_loadHighSpeedGovernorWorkingGainSet loads the gear ratio "
       "working gain set only while the present gain set source priority (e2m 1299 +0 HSG_Application_Gain_Set_Priority "
       "= the word at 0x40b70c, now system_speed_limit_working) is at or below this word, then stores this word there; "
       "both words are gain set priorities, not speed limits",
       "cm848_loadHighSpeedGovernorWorkingGainSet: system_speed_limit_working = system_speed_limit_working_minimum;",
       "e2m 1298 +0 HSG_GR_Application_Priority 'HSG gain schedule selection priority' (HEX; 0 here) (address from the "
       "ECU's parameter ID table): the application priority of the gear ratio based working gain set of the high speed "
       "governor. cm848_loadHighSpeedGovernorWorkingGainSet loads the working gain set (code 20 / 21, chosen by "
       "drivetrain_ratio_user_filtered against the gear ratio selection threshold) only while the priority of the "
       "present gain set source (e2m 1299 +0 HSG_Application_Gain_Set_Priority, the word at 0x40b70c) is at or below "
       "this, and then sets that word to this (lhz @ 0x424a8); no other code writes that word (whole-binary sweep: "
       "lhz @ 0x424ac / sth @ 0x424b8 only) so the test passes only while it is 0. algorithm_enable_flags_18_cal bit "
       "0x100 gates the whole load and is clear in this calibration. Not a system speed limit.")

# ---------------------------------------------------------------- 13AB
rename('0x0040b708', 'high_speed_governor_compensation_active_flag',
       "e2m 13AB +2 HSG_Compensation_Active (UNITLESS): cm848_calculateHighSpeedGovernorCompensatedEngineSpeed sets it "
       "to 1 while the lead / lag compensator runs (drivetrain ratio below the compensator maximum gear ratio, fault "
       "bit 29 / 30 or a standalone drivetrain) and to 0 when the factors pass the speed through; "
       "cm848_initializeHighSpeedGovernorCompensatedEngineSpeed clears it; 2 stores, no reader; the old name said "
       "cruise speed override",
       "cm848_calculateHighSpeedGovernorCompensatedEngineSpeed: cruise_speed_override_flag = 1;",
       "e2m 13AB +2 HSG_Compensation_Active 'Indicates when HSG rpm signal is being lead/lag compensated' (UNITLESS, "
       "16-bit; 0 in the dump) (address from the ECU's parameter ID table): 1 while the high speed governor lead / lag "
       "compensator is active, 0 while its factors pass the engine speed through. "
       "cm848_calculateHighSpeedGovernorCompensatedEngineSpeed sets it to 1 when drivetrain_ratio is below "
       "high_speed_governor_compensator_maximum_gear_ratio with the ratio settled, when fault bit 29 or 30 is detected "
       "or for a standalone drivetrain, else 0; cm848_initializeHighSpeedGovernorCompensatedEngineSpeed clears it. 2 "
       "stores, no reader. Not a cruise control speed override.")
rename('0x0040b70a', 'high_speed_governor_compensator_filter_coefficient_3',
       "e2m 13AB +4 HSG_Comp_Filter_Coefficient_3 (UNITLESS, 1/32768): cm848_calculateHighSpeedGovernorCompensatedEngineSpeed "
       "copies the compensator's third coefficient here every pass (the working word at 0x3fb560: coefficient 2 - "
       "coefficient 1 + 0x8000 while compensating, else the no-filtering coefficient), the weight of the previous output "
       "in its lead / lag equation; 1 store, no reader; the old name said cruise speed offset saved",
       "cm848_calculateHighSpeedGovernorCompensatedEngineSpeed: cruise_speed_offset_saved = cruise_speed_offset;",
       "e2m 13AB +4 HSG_Comp_Filter_Coefficient_3 'Filter coefficient #3 from HSG lead/lag dynamic compensator' "
       "(UNITLESS, 1/32768 per count, 0-1; 0 in the dump) (address from the ECU's parameter ID table): the output copy "
       "of coefficient 3 of the high speed governor lead / lag compensator y = (rpm x a + previous y x coefficient 3 - "
       "previous rpm x b) >> 15. cm848_calculateHighSpeedGovernorCompensatedEngineSpeed stores it every pass from the "
       "working word at 0x3fb560 (coefficient 2 - coefficient 1 + 0x8000 while compensating, else the no-filtering "
       "coefficient at 0x5c94c); 1 store, no reader. Coefficients 1 / 2 are the ROM words "
       "high_speed_governor_compensator_filter_coefficient_1 / _2 (e2m 13B4).")

# ---------------------------------------------------------------- 13D8
rename('0x0005c47c', 'engine_retarder_output_driver_count',
       "e2m 13D8 +0 EB_Number_Output_Drivers (UNITLESS): ROM word 1; the code compares it with 0 (the TSC1 handler and "
       "the ERC1 builder return) and with 1 and 2 (RC builder byte 1 = 0xFF / 0x14 / 3 for 0 / 1 / more than 1), so it "
       "is a count of output drivers, not a mode; the old name said configuration mode",
       "cm848_buildPgn65249RetarderConfigurationMessage: if (engine_retarder_configuration_mode < 2) {",
       "e2m 13D8 +0 EB_Number_Output_Drivers '[EBNUOUDR] Total number of Engine Brake Output Drivers at the ECM.' "
       "(UNITLESS, 16-bit; 1 here) (address from the ECU's parameter ID table): ROM word = 1 at the start of the "
       "retarder block (0x5c47c; the stage weights engine_retarder_stage_1_weight and the ramp words follow); its only "
       "readers are the retarder TSC1 handler (returns when 0), the ERC1 builder (byte 2 = 0xFF when 0) and the RC "
       "builder (byte 1 = 0xFF / 0x14 / 3 for 0 / 1 / above 1 drivers). 'dm' (diagnostic message) has nothing to do "
       "with it.")

# ---------------------------------------------------------------- 18D6
rename('0x00405206', 'intake_manifold_temperature_lag_filter_coefficient',
       "e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant (UNITLESS, 1/65536): cm848_initializeIntakeTemperatureFilterStates "
       "points the coefficient of both cascaded intake manifold temperature filters (0x3fa624 / 0x3fa62c, run by "
       "cm848_filterAndSelectIntakeManifoldTemperature) at it; it filters a temperature, the old name said pressure "
       "correction",
       "cm848_initializeIntakeTemperatureFilterStates: pressure_correction_first_filter.coefficient = "
       "&pressure_correction_filter_coefficient;",
       "e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant 'Filter constant used for filtering noise and quantization effects "
       "(used twice)' (UNITLESS, 1/65536 per count, 0-1) (address from the ECU's parameter ID table): the coefficient "
       "of the two cascaded intake manifold temperature filters (the cm848_signedFirstOrderFilter records at 0x3fa624 / "
       "0x3fa62c; cm848_initializeIntakeTemperatureFilterStates points both coefficient pointers at it and "
       "cm848_filterAndSelectIntakeManifoldTemperature runs them while the compensation is on). Read through the "
       "coefficient pointer as a 16-bit word: the weight of the previous value in 1/65536 - 62966 = 0.961 in the RAM "
       "dump; 0 = no filtering. It filters the intake manifold temperature, not a pressure.")
rename('0x00405208', 'intake_manifold_temperature_lower_limit',
       "e2m 18D6 +2 C_TPE_Min_IMT (DEG_F, 1/64, signed, -350..350): the lower clamp of the sensor value plus the lead "
       "term in cm848_calculateIntakeManifoldTemperatureLeadCompensation (-22400 = -350 deg F in the dump, lha); the old "
       "name said pressure sensor lower limit and had a _cal on a RAM-copied constant",
       "cm848_calculateIntakeManifoldTemperatureLeadCompensation: iVar2 = (int)pressure_sensor_lower_limit_cal;",
       "e2m 18D6 +2 C_TPE_Min_IMT 'Minimum limit for estimated IMT' (DEG_F, 0.015625 = 1/64 deg F per count, signed, "
       "-350..350; -22400 = -350 deg F in the dump) (address from the ECU's parameter ID table): the lower clamp that "
       "cm848_calculateIntakeManifoldTemperatureLeadCompensation applies to the intake manifold temperature sensor "
       "value plus the lead term (intake_manifold_temperature_after_lead). Signed 16-bit, every load lha. A "
       "temperature limit, not a pressure sensor limit.")
rename('0x0040520a', 'intake_manifold_temperature_upper_limit',
       "e2m 18D6 +4 C_TPE_Max_IMT (DEG_F, 1/64, signed, 0..350): the upper clamp of the sensor value plus the lead "
       "term in cm848_calculateIntakeManifoldTemperatureLeadCompensation (22400 = 350 deg F in the dump, 2 lha loads); "
       "the old name said injection timing offset floor and had a _cal on a RAM-copied constant",
       "cm848_calculateIntakeManifoldTemperatureLeadCompensation: iVar2 = (int)injection_timing_offset_floor_cal;",
       "e2m 18D6 +4 C_TPE_Max_IMT 'Maximum limit for estimated IMT' (DEG_F, 0.015625 = 1/64 deg F per count, signed, "
       "0..350; 22400 = 350 deg F in the dump) (address from the ECU's parameter ID table): the upper clamp that "
       "cm848_calculateIntakeManifoldTemperatureLeadCompensation applies to the intake manifold temperature sensor "
       "value plus the lead term (intake_manifold_temperature_after_lead). Signed 16-bit, every load lha. A "
       "temperature limit, not an injection timing floor.")

# ---------------------------------------------------------------- 18D9
rename('0x0040a464', 'intake_manifold_temperature_filtered_state',
       "e2m 18D9 +C Charge_Tmptr_State (HEX): written only by cm848_filterAndSelectIntakeManifoldTemperature as "
       "injection_enable_mode_byte (e2m 1A1B +4 Charge_Tmptr_EStat, 0x80 / 0x40) ORed with the sensor channel 9 fault "
       "status and 0x20 for the gated P0111 faults; the dump 0x80 is the estimate-default bit; 1 store, no reader; the "
       "old name said fuel demand phase",
       "cm848_filterAndSelectIntakeManifoldTemperature: fuel_demand_phase_status_flags = uVar4 | uVar3;",
       "e2m 18D9 +C Charge_Tmptr_State 'Charge temperature state' (HEX; 0x80 in the dump) (address from the ECU's "
       "parameter ID table): the state of the charge (intake manifold) temperature, built by "
       "cm848_filterAndSelectIntakeManifoldTemperature from injection_enable_mode_byte (e2m 1A1B +4 Charge_Tmptr_EStat, "
       "the quality of the charge temperature estimate: 0x80 when the compressor inlet temperature source is default or "
       "the estimate is disabled, 0x40 when it is backup), ORed with the sensor channel 9 fault status while fault bit "
       "19 / 20 (P0113 / P0112) is detected with its gate, and 0x20 for the gated P0111 faults (354 / 358); the same "
       "bits pick the source in intake_manifold_temperature_filtered_source. 1 store, no reader. Not a fuel demand "
       "phase.")

# ---------------------------------------------------------------- 1976
rename('0x004065be', 'ambient_air_density_negative_rate_limit',
       "e2m 1976 +0 C_TPE_Inlet_Density_Down_Rate (LBM/FT3, 0.000305, signed, -0.1..0): cm848_calculateAmbientAirDensity "
       "adds it to ambient_air_density when the new density is below it (-164 in the dump = -0.05); ambient_air_density "
       "is e2m 18E8 +0 Compressor_Inlet_Density; the old name said engine load ramp rate; the record is signed and the "
       "compare casts it to short, but it is also added through a word pointer (lhz), so the type stays word",
       "cm848_calculateAmbientAirDensity: (pwVar4 = &engine_load_ramp_rate_lower, iVar1 < "
       "(short)engine_load_ramp_rate_lower)) {",
       "e2m 1976 +0 C_TPE_Inlet_Density_Down_Rate 'Compressor_Inlet_Density negative rate decrement value' (LBM/FT3, "
       "0.00030517578 per count, signed, -0.1..0; -164 = -0.05 in the dump) (address from the ECU's parameter ID "
       "table): ROM-copied negative rate limit of ambient_air_density (e2m 18E8 +0 Compressor_Inlet_Density): "
       "cm848_calculateAmbientAirDensity moves ambient_air_density toward the new pressure over temperature value by at "
       "most this per pass (when the new value minus ambient_air_density is below it, ambient_air_density + this is "
       "stored). Signed in the record (the compare casts it to short) but also added through a word pointer, so the "
       "type stays word. Not an engine load ramp.")
rename('0x004065c0', 'ambient_air_density_positive_rate_limit',
       "e2m 1976 +2 C_TPE_Inlet_Density_Up_Rate (LBM/FT3, 0.000305, 0..0.1): cm848_calculateAmbientAirDensity adds it to "
       "ambient_air_density when the new density is above it (164 in the dump = 0.05); ambient_air_density is e2m 18E8 "
       "+0 Compressor_Inlet_Density; the old name said engine load ramp rate",
       "cm848_calculateAmbientAirDensity: pwVar4 = &engine_load_ramp_rate_upper;",
       "e2m 1976 +2 C_TPE_Inlet_Density_Up_Rate 'Compressor_Inlet_Density positive rate increment value' (LBM/FT3, "
       "0.00030517578 per count, 0..0.1; 164 = 0.05 in the dump) (address from the ECU's parameter ID table): "
       "ROM-copied positive rate limit of ambient_air_density (e2m 18E8 +0 Compressor_Inlet_Density): "
       "cm848_calculateAmbientAirDensity moves ambient_air_density toward the new pressure over temperature value by at "
       "most this per pass (when the new value minus ambient_air_density is above it, ambient_air_density + this is "
       "stored). Not an engine load ramp.")

# ---------------------------------------------------------------- 19BA
keep('0x0040a350')

# ---------------------------------------------------------------- 8194
rename('0x00408f72', 'engine_speed_filter_coefficient',
       "e2m 8194 +1C Filtered_Engine_Speed_Constant (UNITLESS, 1/65536): mpc555_resetEngineTimingAccumulators points "
       "crank_filter_state.coefficient at it and cm848_updateEngineSpeedFromCrankSignal runs exponentialMovingAverage on "
       "average_engine_speed (the main or the backup sensor speed) with that record into engine_speed_state.engine_speed, "
       "which becomes filtered_engine_speed; the old name said crank filter although the input is the main or backup "
       "speed",
       "mpc555_resetEngineTimingAccumulators: crank_filter_state.coefficient = &crank_filter_coefficient;",
       "e2m 8194 +1C Filtered_Engine_Speed_Constant '[ESESFTTC] Time constant for the filter used on the 2^n pulse "
       "average' (UNITLESS, 1.52588E-5 = 1/65536 per count, 0-1; 0 in the dump) (address from the ECU's parameter ID "
       "table): the coefficient of the engine speed filter. mpc555_resetEngineTimingAccumulators points "
       "crank_filter_state.coefficient (the ema_filter_state_t at 0x3fb5c6) at it, and cm848_updateEngineSpeedFromCrankSignal "
       "runs exponentialMovingAverage on average_engine_speed (the main or the backup sensor speed) with that record "
       "into engine_speed_state.engine_speed, which becomes engine_speed_state.filtered_engine_speed. EMA coefficient: "
       "the weight of the previous value in 1/65536 (0 = no filtering, as in the dump).")

# ---------------------------------------------------------------- 8A13
for _a, _r in sorted(records.items()):
    if _r['block'] == '8A13' and _a != '0x0040b4f8':
        keep(_a)
rename('0x0040b4f8', 'pci_spare_transmit_message_status',
       "e2m 8A13 +A9 Chry_Err16 (HEX, 1 B): the status byte of a PCI transmit message with header 0x16 that this ROM has "
       "no descriptor for (the 25-entry TX table at 0x578ef has no 0x16 header); the e2m layout of that message is data "
       "0x40b4f5-0x40b4f7, status here, age timer 0x40b4f9, in-frame response 0x40b4fb (= pci_spare_in_frame_response, "
       "0x18 0); only hpcr_initJ1939BufferValues writes it (0x80, the fourth store in the e2m source order Err10, "
       "Err16, Err35, ErrB0); the old name said J1939 message slot control",
       "hpcr_initJ1939BufferValues: j1939_msg_slot_hh_control = 0x80;",
       "e2m 8A13 +A9 Chry_Err16 'Chrysler DR Message $16 error for TRD Link Status, ECM Tx message' (HEX, 1 byte; 0x80 "
       "in the dump) (address from the ECU's parameter ID table): the status byte of a PCI transmit message with "
       "header 0x16 that this ROM has no descriptor for (the 25-entry TX table at 0x578ef holds no 0x16 header). The "
       "e2m layout of that message is data 0x40b4f5-0x40b4f7, status here, age timer 0x40b4f9 (Chry_Act16), in-frame "
       "response 0x40b4fb (Chry_Ifr16 = pci_spare_in_frame_response, 0x18 0 = the transmission controller node). Only "
       "hpcr_initJ1939BufferValues writes it: 0x80 (unconfirmed, like the live TX status bytes), the fourth store, in "
       "the e2m source order Err10, Err16, Err35, ErrB0; no reader. Not a J1939 message slot.")

# ---------------------------------------------------------------- 8A23
keep('0x0040b332')
keep('0x0040b334')

# ---------------------------------------------------------------- 8C4F
keep('0x00408ab6')

# ---------------------------------------------------------------- 8C68
rename('0x00408994', 'net_torque_fuel_limit_override_enable',
       "e2m 8C68 +0 Net_Torque_Fueling_Limit_Override (UNITLESS, 0/1): cm848_calculateNetTorqueFuelLimit takes the override "
       "value (0x408996, e2m 8C68 +2) instead of the engine speed x alpha / chi table result while it is nonzero (0 in "
       "the dump); single lhz reader; the old name said fuel demand calc bypass and has a _cal on a RAM-copied constant",
       "cm848_calculateNetTorqueFuelLimit: if (fuel_demand_calc_bypass_flag_cal == 0) {",
       "e2m 8C68 +0 Net_Torque_Fueling_Limit_Override 'Override enable for Net_Torque_Fueling_Limit' (UNITLESS, 0 / 1; 0 "
       "in the dump) (address from the ECU's parameter ID table): while it is nonzero cm848_calculateNetTorqueFuelLimit "
       "takes the override value (the word at 0x408996, e2m 8C68 +2 Net_Torque_Fueling_Limit_Override_Value) as the net "
       "torque fuel limit instead of the engine speed x alpha / chi table calculation (the rate limiter still runs on "
       "it); 0 here so the table calculation runs. Single reader (lhz @ 0x3ccf4). RAM-copied constant, so no _cal.")

# ---------------------------------------------------------------- 8D14
drift('0x0040b0b6',
      "e2m 8D14 +A RE_EB_4_3_Cmd_Timer (MSEC, 10 per count, 'Timer used to trigger 4_3_command feature'): the word is a "
      "snapshot of transmission_output_speed_change (stored in the gear 1 branch of cm848_processProtectionStateFlags, "
      "read as the old value by cm848_calculateProtectionFuelDemandThreshold in protection_rate_integrator_delta = "
      "snapshot - transmission_output_speed_change, lha), not a timer; 8D14 is known drift from +2, so the code use "
      "contradicts the record; the name stays (the protection_* names of this 48RE shift logic need their own review)")


def main():
    wanted = [b.upper() for b in sys.argv[1:]]
    done = set()
    if os.path.exists(RESULT):
        for line in open(RESULT):
            line = line.strip()
            if line:
                done.add(json.loads(line)['address'])
    out = []
    for block in wanted:
        for r in sorted(by_block[block], key=lambda x: x['address']):
            addr = r['address']
            if addr in done:
                print('skip (already written):', addr)
                continue
            if addr not in ENTRIES:
                print('MISSING ENTRY for', addr, block)
                sys.exit(1)
            out.append(ENTRIES[addr])
    with open(RESULT, 'a') as f:
        for e in out:
            f.write(json.dumps(e, ensure_ascii=True) + '\n')
    print('appended', len(out), 'lines for', ' '.join(wanted))


main()
