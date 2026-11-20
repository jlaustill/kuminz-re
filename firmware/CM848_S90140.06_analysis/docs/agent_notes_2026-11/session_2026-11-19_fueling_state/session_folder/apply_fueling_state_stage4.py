"""Stage 4 of the FUELING_STATE work (2026-11-19, PR #52).
The labelled Chrysler calibration e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m (the truck runs V11.46.06) lists Cummins'
value labels in HEX keys: Fueling_Control_State (FSFNFLST) 00-3D and Engine_State (FSEGST) 1-8. They confirm most
code-derived members, name the unidentified codes, and correct one misread (FSFNFLST "29=ATDERAT" is 0x29 = 41, the
anti-theft derate = FUELING_STATE_IMMOBILIZER_FUEL_DISABLE; 0x1D = 29 is EPFDERAT).
- FUELING_STATE: e2m label on every member, 4 members renamed to the labels, 11 placeholders named.
- COLD_START_PHASE -> ENGINE_STATE (e2m block 1068 lines up 7/7 with 0x40a7c0-0x40a7cf), cold_start_phase -> engine_state.
- The producers of codes 15 / 16 / 42 / 46 / 59 renamed (altitude derate, air fuel control, fuel limit by rpm and
  demand, coolant overheat derate, net torque).
Every old row is asserted before it is replaced. Usage: apply_fueling_state_stage4.py <CM848 output dir> [extra.py]"""
import os
import sys

OUT = sys.argv[1]
E2M = "CHR_CC_11.45.01.07"
LABEL = {0: "NOT_SET", 1: "JCOMTORQ", 2: "JCOMSPED", 4: "PTO", 5: "USERCOMD", 6: "LIMPHOME", 7: "ASGTHROT", 8: "FOUR_D",
         9: "CRUISE", 10: "RSG", 11: "LSG", 12: "HSG", 13: "TRQDROVR", 15: "ALTDERAT", 16: "AFCDERAT", 19: "MAXTHROT",
         20: "JCTRQDER", 22: "CRANK", 23: "OVERRIDE", 24: "ENGBRAKE", 25: "OVERSPED", 26: "STOP", 27: "SHUTDOWN",
         28: "FSSDERAT", 29: "EPFDERAT", 30: "ASG_APPL", 32: "MSOVRIDE", 34: "PTODERAT", 37: "T2SPD", 38: "T2TORQ",
         40: "NODERAT", 41: "ATDERAT", 42: "PTTHLM", 45: "TORQMGMT", 46: "CTDERAT", 47: "FREEACCL", 49: "OFCSTATE",
         50: "AFRSTATE", 52: "AIRDENLM", 53: "CHIFULLM", 54: "TFCDERAT", 55: "GROSSOVR", 58: "OFCDERAT", 59: "NETTORQ",
         61: "LOFPRDER"}
# value: (new member suffix or None to keep, new comment or None to keep the comment and only add the label)
MEMBERS = {
    13: ("TORQUE_DERATE_OVERRIDE", "torque_derate_fuel_source_code (cm848_arbitrateRequestedFueling): while "
         "governor_feature_flags bit 0x10 is set the EEPROM limit protection_fuel_limit_c_working (EEPROM 0x380) "
         "replaces the whole derate chain. Off in the dump: the flags are 0x1020 and the limit is 5888"),
    15: ("ALTITUDE_DERATE", "torque_derate_fuel_source_code (cm848_applyAltitudeDerateFuelLimit): "
         "altitude_derate_fuel_limit - the engine speed x barometric pressure grids for cool / hot ambient air blended "
         "by ambient air temperature (or the air handling fault grid while an enabled boost / intake manifold pressure / "
         "barometric / intake air or ambient air temperature / wastegate fault is set); cm848_calculateAltitudeDerateFuelLimit"),
    16: ("AIR_FUEL_CONTROL_DERATE", "fuel_demand_minimum_tracked_state (cm848_applyAirFuelControlFuelLimit): "
         "air_fuel_control_fuel_limit - the engine speed x boost pressure grid air_fuel_control_fuel_limit_grid blended "
         "toward air_fuel_control_low_boost_fuel_limit_grid (cm848_calculateAirFuelControlFuelLimit). RAM dump: 16 "
         "(no boost at key on)"),
    19: ("MAXIMUM_THROTTLE", "torque_derate_fuel_source_code starting value (cm848_initializeFuelLimitChains): "
         "protection_fuel_limit_cal_active - cm848_calculateMaximumFuelCurve(engine speed / 400) is the fuel at full "
         "accelerator (400 = 100 %) - before any derate source takes over"),
    22: ("CRANKING", "final_fueling_state (cm848_selectFinalFueling): engine_state CRANKING / JUMP_START (or REENTRY with "
         "the command below it) - the fuel is governor_cold_start_rpm_output"),
    24: ("ENGINE_BRAKE", "final_fueling_state (cm848_selectFinalFueling): engine_state ENGINE_BRAKE - the fuel is the ROM "
         "word 0x5c308 (0 here)"),
    25: ("OVERSPEED", "final_fueling_state (cm848_selectFinalFueling): engine_state OVERSPEED - the fuel is the ROM word "
         "0x5c30a (0 here)"),
    27: ("SHUTDOWN", "final_fueling_state (cm848_selectFinalFueling): engine_state SHUTDOWN - the fuel is "
         "timing_limit_upper (0 here)"),
    28: ("FUEL_SYSTEM_DERATE", "torque_derate_fuel_source_code (cm848_applyFuelPressureFaultFuelLimit): "
         "fuel_pressure_fault_fuel_limit_working from cm848_applyFuelLimitsForFuelPressureFaults (rail pressure faults) - "
         "e2m block 105D +4 FSAPLMFL fuel system specific fuel derate"),
    29: (None, "torque_derate_fuel_source_code (cm848_applyFaultDerateFuelLimit): fault_derate_fuel_limit from "
         "cm848_calculateFaultDerateFuelLimit"),
    34: ("POWER_TAKE_OFF_DERATE", "governor_fuel_limit_cap_state (cm848_checkProtectionParamLimit): "
         "governor_fuel_limit_override lowers governor_fuel_limit_cap while governor_fuel_active_flag (the power take-off "
         "governor of code 4) is 1"),
    40: ("NO_DERATE", "governor_fuel_limit_cap_state default (cm848_arbitrateRequestedFueling) and the starting value of "
         "fuel_demand_minimum_tracked_state (cm848_initializeFuelLimitChains)"),
    42: ("FUEL_LIMIT_BY_RPM_AND_DEMAND", "torque_derate_fuel_source_code (cm848_applyFuelLimitByRpmAndDemand): "
         "fuel_limit_by_rpm_and_demand - the alpha / chi blend of the engine speed x accelerator demand grids - computed "
         "only in the variable speed governor (engine_operating_mode 7) while injection_timing_enable_flags bit 0 is set"),
    46: ("COOLANT_OVERHEAT_DERATE", "torque_derate_fuel_source_code (cm848_applyCoolantOverheatFuelDerate): "
         "coolant_overheat_fuel_derate - the ramped smaller of the PI limit on the coolant temperature error and the "
         "engine speed limit of the coolant temperature buckets (cm848_runCoolantOverheatFuelDerate; enabled by "
         "engine_feature_enable_flags_cal bit 1)"),
    47: ("FREE_ACCELERATION", "only compared (final_fueling_state) - never stored in this build"),
    59: ("NET_TORQUE", "fuel_demand_minimum_tracked_state (cm848_applyNetTorqueFuelLimit): net_torque_fuel_limit - a "
         "rate-limited engine speed fuel curve from the alpha / chi map blend of fuel_demand_table_base_cal "
         "(cm848_calculateNetTorqueFuelLimit) while fault_feature_config_flags bit 2 is set"),
    32: (None, "stored - final_fueling_state / fuel_demand_arbitrated_state: fuel_limit_mode_active_flag set without "
         "fuel_limit_secondary_flag - the fuel is fuel_demand_arbitrated_a. Nothing stores either word (both only lhz; "
         "0 in the RAM dump) - probably an excluded feature"),
}
FUELING_HEADER = (
    "# Fueling State (renamed 2026-11-19 from ENGINE_OPERATING_MODE): the code of the algorithm in control of the fuel - "
    "one numbering for every fueling stage. The labelled Chrysler calibration e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m "
    "lists Cummins' labels with HEX keys (User_Fueling_State / Fueling_Control_State 00-3D; each member comment gives "
    "its label). Carriers: engine_operating_mode (the user stage) -> operating_mode_governor_output.mode_code (power "
    "take-off selection adds 4) -> governor_fuel_demand_working_mode (cruise adds 9) -> governor_fuel_demand_mode (the "
    "governed stage adds 10 / 11 / 12) -> requested_fueling_state / fuel_demand_arbitrated_state "
    "(cm848_arbitrateRequestedFueling: the governed fuel against torque_derate_fuel_source_code - the derate stage - and "
    "fuel_demand_minimum_tracked_state) -> injection_quantity_combustion_gross_source_code / _reference_source_code (the "
    "combustion stage 52-58) -> final_fueling_state (the engine-state overrides 22-41). 62 is newer than the label list. "
    "FUELING_STATE_UNIDENTIFIED_<n> (32 37 38 49 50) are codes stored or only compared whose algorithm is not proved "
    "yet: without an exact member Ghidra prints such a code as an OR of other members")
ENGINE_STATE_HEADER = [
    "# Engine State (Cummins FSEGST Engine_State; e2m block 1068 +0 - its labels in CHR_CC_11.45.01.07.e2m: 1 STOP 2 CRANK "
    "3 RUN 4 ENGBRAKE 5 OVERSPED 6 JUMPSTRT 7 REENTRY 8 SHUTDOWN): engine_state (0x40a7c0) set by "
    "cm848_updateEngineState. Block 1068 lines up 7/7 (+2 Start_Power_Down = power_down_start_flag / +4 "
    "ECM_Powerdown_Timer = ecm_power_down_timer / +6 / +A crank / run time / +E / +F Engine_Is_Active / _Starting). "
    "Renamed 2026-11-19 from COLD_START_PHASE / cold_start_phase: the old names and comments disagreed for 1 / 4 / 5 / 8",
]
ENGINE_STATE = {   # value: (old member, new member, comment)
    0: ("COLD_START_PHASE_INITIAL", "ENGINE_STATE_UNINITIALIZED",
        "Zeroed RAM: cm848_updateEngineState turns 0 (or anything above 8) into STOPPED"),
    1: ("COLD_START_PHASE_KEY_ON_ENGINE_STOPPED", "ENGINE_STATE_STOPPED",
        "e2m STOP: engine speed at or below engine_rpm_trigger_cal - the final fuel is 0 (FUELING_STATE_ENGINE_STOPPED). "
        "RAM dump (key on / engine stopped): 1"),
    2: ("COLD_START_PHASE_ABOVE_RPM_TRIGGER", "ENGINE_STATE_CRANKING",
        "e2m CRANK: above engine_rpm_trigger_cal until governor_rpm_setpoint_output - the fuel is "
        "governor_cold_start_rpm_output (FUELING_STATE_CRANKING)"),
    3: ("COLD_START_PHASE_AT_GOVERNOR_SETPOINT", "ENGINE_STATE_RUNNING",
        "e2m RUN: at or above governor_rpm_setpoint_output; no final-fuel override; engine_is_active_flag is 1"),
    4: ("COLD_START_PHASE_ENGINE_RETARDER_ACTIVE", "ENGINE_STATE_ENGINE_BRAKE",
        "e2m ENGBRAKE: from RUN while engine_retarder_active_flag is 1 (and cold_start_fuel_mode_ready_flag 0) until it "
        "clears - the fuel is the ROM word 0x5c308 (FUELING_STATE_ENGINE_BRAKE)"),
    5: ("COLD_START_PHASE_ENGINE_OVERSPEED", "ENGINE_STATE_OVERSPEED",
        "e2m OVERSPED: while engine_overspeed_active_flag is 1 (P0219) - the fuel is the ROM word 0x5c30a "
        "(FUELING_STATE_OVERSPEED)"),
    6: ("COLD_START_PHASE_ABOVE_RPM_VIA_CRANK_EVENTS", "ENGINE_STATE_JUMP_START",
        "e2m JUMPSTRT: from CRANK after the crank pass count passes its limit; the consumers treat it like CRANK"),
    7: ("COLD_START_PHASE_SETPOINT_UNDERRUN", "ENGINE_STATE_REENTRY",
        "e2m REENTRY: from RUN when engine speed drops to cold_start_rpm_threshold - the crank fuel is a floor "
        "(FUELING_STATE_CRANKING)"),
    8: ("COLD_START_PHASE_ENGINE_STANDBY", "ENGINE_STATE_SHUTDOWN",
        "e2m SHUTDOWN: the key line (mios_mdasm30.SCRD bit 15) is off without engine_shutdown_active_flag - or "
        "engine_starting is 1; ecm_power_down_timer runs - the fuel is timing_limit_upper (FUELING_STATE_SHUTDOWN)"),
}
FUNCTIONS = {   # address: (old name, new name, plate comment or None to keep it and add the history)
    "0x0001c28c": ("mpc555_processColdStartMainLoop", "cm848_updateEngineState", 'Called as the last task of hpcr_periodicTaskSet_fuelFinal (every 4th main loop phase, 20 ms if a phase is 5 ms). Two jobs. (1) The engine overspeed monitor: the speed engine_rpm_state_t.current_rpm (1/8 rpm) at or above engine_overspeed_set_rpm_threshold (33600 = 4200 rpm) for more than engine_overspeed_debounce_limit (3) passes in a row latches engine_overspeed_active_flag, sets fault 27 (fault_detected_bits_16_to_31 0x800 = P0219 engine overspeed through ROM 0x5985a) and opens a record in engine_overspeed_log_cal (5 records of 8 bytes in the EEPROM mirror: key_on_hour_meter at the start, speed when detected, duration); below engine_overspeed_clear_rpm_threshold (32000 = 4000 rpm) it clears the flag and the fault bit in the detected and registered words, writes the duration into the record and moves engine_overspeed_log_index_cal on (modulo 5). (2) The engine state machine on engine_state (Cummins FSEGST: STOPPED / CRANKING / RUNNING / ENGINE_BRAKE / OVERSPEED / JUMP_START / REENTRY / SHUTDOWN) from the engine speed, the governor setpoint, engine_retarder_active_flag and the ignition key line; while the overspeed flag is set it moves RUNNING to OVERSPEED until the flag clears, and in SHUTDOWN it counts ecm_power_down_timer toward power_down_start_flag (was mpc555_processColdStartMainLoop)'),
    "0x00502464": ("cm848_calibrationGroup5_periodic", "cm848_calculateAltitudeDerateFuelLimit",
                   "Sets altitude_derate_fuel_limit (e2m ALTDERAT): while governor_feature_flags bit 0x20 is set and the "
                   "engine runs - the engine speed x barometric pressure grids for cool / hot ambient air "
                   "(fuel_limit_barometric_cool_ambient_air_grid / _hot_ambient_air_grid) blended by ambient air "
                   "temperature inside the band altitude_derate_ambient_temperature_band_lower / _upper; while an air "
                   "handling fault enabled in altitude_derate_air_handling_fault_enable_a / _b is set (boost sensor / "
                   "underboost / intake manifold pressure / barometric / intake air and ambient air temperature / "
                   "wastegate solenoid) the air handling fault grid instead; else fuel_demand_maximum (was "
                   "cm848_calibrationGroup5_periodic)"),
    "0x00502af4": ("cm848_protection_limits", "cm848_applyAltitudeDerateFuelLimit",
                   "Takes altitude_derate_fuel_limit as the derate limit (FUELING_STATE_ALTITUDE_DERATE) when it is below "
                   "torque_derate_fuel_quantity (was cm848_protection_limits)"),
    "0x0000dcdc": ("cm848_fuelDemandBlendCalculator", "cm848_calculateAirFuelControlFuelLimit",
                   "Sets air_fuel_control_fuel_limit, the air fuel control (boost) fuel limit (e2m AFCDERAT): the engine "
                   "speed x boost pressure grid air_fuel_control_fuel_limit_grid, blended toward the low boost grid by a "
                   "ramp while governor_fault_status_flags bit 1 is set (was cm848_fuelDemandBlendCalculator)"),
    "0x0000e0c4": ("cm848_trackMinimumFuelDemand", "cm848_applyAirFuelControlFuelLimit",
                   "Takes air_fuel_control_fuel_limit into fuel_demand_minimum_tracked with "
                   "FUELING_STATE_AIR_FUEL_CONTROL_DERATE when it is lower (was cm848_trackMinimumFuelDemand)"),
    "0x0003ccb4": ("cm848_calculateFuelDemandLimit", "cm848_calculateNetTorqueFuelLimit",
                   "Sets net_torque_fuel_limit (e2m NETTORQ for its code 59): while fault_feature_config_flags bit 2 is "
                   "set the engine speed curves of fuel_demand_table_base_cal for the base / chi lower / chi upper map "
                   "blended by alpha / chi (cm848_interpolateAlphaChiValue) plus governor_integral_component_a / _b, "
                   "clamped to 0..5888 and rate limited by fuel_demand_rate_step_up / _down; else 5888 (was "
                   "cm848_calculateFuelDemandLimit)"),
    "0x0003cefc": ("cm848_trackFuelDemandMinimum", "cm848_applyNetTorqueFuelLimit",
                   "Takes net_torque_fuel_limit into fuel_demand_minimum_tracked with FUELING_STATE_NET_TORQUE when it is "
                   "lower and fault_feature_config_flags bit 2 is set (was cm848_trackFuelDemandMinimum)"),
    "0x0004b6cc": ("cm848_calculateFuel2DTableLookup", "cm848_calculateFuelLimitByRpmAndDemand",
                   "In the variable speed governor (engine_operating_mode 7) while injection_timing_enable_flags bit 0 "
                   "is set: looks up the engine speed x accelerator demand (fuel_demand_control.calculated) grids - the "
                   "reference map and the chi lower / upper blend maps - and blends them by alpha / chi "
                   "(cm848_interpolateAlphaChiValue) into fuel_limit_by_rpm_and_demand (e2m label of its code 42: "
                   "PTTHLM) (was cm848_calculateFuel2DTableLookup)"),
    "0x0004b9ac": ("cm848_applyProtectionLimit", "cm848_applyFuelLimitByRpmAndDemand",
                   "Takes fuel_limit_by_rpm_and_demand as the derate limit (FUELING_STATE_FUEL_LIMIT_BY_RPM_AND_DEMAND) "
                   "in the variable speed governor when it is below torque_derate_fuel_quantity (was "
                   "cm848_applyProtectionLimit)"),
    "0x00513f5c": ("governor_fuel_limit_update", "cm848_runCoolantOverheatFuelDerate",
                   "The engine coolant overheat fuel derate (e2m CTDERAT; engine_feature_enable_flags_cal bit 1 - else "
                   "coolant_overheat_fuel_derate 0x6400 = no limit): below the coolant threshold with no bucket cycle "
                   "it resets; else it runs the coolant temperature buckets, the PI limit, the fuel floor, the limit "
                   "selection and the ramp, and keeps the previous-pass words (was governor_fuel_limit_update)"),
    "0x00513e0c": ("governor_fuel_limit_initialize", "cm848_resetCoolantOverheatFuelDerate",
                   "Resets the coolant overheat fuel derate: clears faults 389 / 390, the bucket overheat flags and every "
                   "limit to 0x6400 (no limit) (was governor_fuel_limit_initialize)"),
    "0x005139b8": ("fuel_coldStart_integralCorrection_update", "cm848_calculateCoolantOverheatPiFuelLimit",
                   "Sets coolant_overheat_pi_fuel_limit, the PI fuel limit on coolant_overheat_temperature_error while "
                   "engine_overheat_derate_active_flag is set (was fuel_coldStart_integralCorrection_update)"),
    "0x00513c80": ("fuel_coldStart_demandMin_2dLookup", "cm848_applyCoolantOverheatFuelFloor",
                   "Looks up coolant_overheat_fuel_floor (engine speed x coolant temperature grid "
                   "coolant_overheat_fuel_demand_floor_grid) and raises coolant_overheat_pi_fuel_limit to it (reason "
                   "code 2) (was fuel_coldStart_demandMin_2dLookup)"),
    "0x00513af0": ("fuel_coldStart_rpmLimit_select", "cm848_selectCoolantOverheatFuelLimit",
                   "Sets coolant_overheat_engine_speed_fuel_limit (the engine speed table "
                   "coolant_overheat_engine_speed_fuel_limit_values while the first coolant temperature bucket counter "
                   "is past cold_start_coolant_bucket_thresholds and the coolant is above a threshold; else 0x6400) and "
                   "coolant_overheat_fuel_limit, the smaller of it and coolant_overheat_pi_fuel_limit (reason code 1 "
                   "when the engine speed limit is the smaller) (was fuel_coldStart_rpmLimit_select)"),
    "0x00513ba4": ("fuel_coldStart_demandRamp_rateLimiter", "cm848_rampCoolantOverheatFuelDerate",
                   "Moves coolant_overheat_fuel_derate toward coolant_overheat_fuel_limit by "
                   "coolant_overheat_fuel_derate_increase_step / _decrease_step per pass (reason codes 8 / 7) (was "
                   "fuel_coldStart_demandRamp_rateLimiter)"),
    "0x00513ddc": ("protection_fuel_limit_check", "cm848_applyCoolantOverheatFuelDerate",
                   "Takes coolant_overheat_fuel_derate as the derate limit (FUELING_STATE_COOLANT_OVERHEAT_DERATE) when it "
                   "is below torque_derate_fuel_quantity (was protection_fuel_limit_check)"),
}
GLOBALS = {   # address: (old name, new name, new type or None, comment or None = keep the old comment + the history)
    "0x0040a7c0": ("cold_start_phase", "engine_state", "ENGINE_STATE",
                   "The engine state (Cummins FSEGST - e2m block 1068 +0): ENGINE_STATE, set by cm848_updateEngineState. "
                   "RAM dump: 1 STOPPED (was cold_start_phase)"),
    "0x003fa856": ("cold_start_phase_prev_check", "engine_state_prev_check", "ENGINE_STATE", None),
    "0x003fa858": ("cold_start_phase_prev_adjust", "engine_state_prev_adjust", "ENGINE_STATE", None),
    "0x003fa85a": ("cold_start_phase_prev_sm", "engine_state_prev_state_machine", "ENGINE_STATE", None),
    "0x003fa85c": ("cold_start_phase_prev_rpm", "engine_state_prev_rpm", "ENGINE_STATE", None),
    "0x003fa85e": ("cold_start_phase_prev_fuel", "engine_state_prev_fuel", "ENGINE_STATE", None),
    "0x0040a7c2": ("hardware_operation_complete_flag", "power_down_start_flag", None,
                   "e2m block 1068 +2 Start_Power_Down: set when ecm_power_down_timer reaches its target in SHUTDOWN; "
                   "ends the application main loop (was hardware_operation_complete_flag)"),
    "0x0040a7c4": ("governor_speed_engage_count", "ecm_power_down_timer", None,
                   "e2m block 1068 +4 ECM_Powerdown_Timer: passes in SHUTDOWN with the engine stopped - at "
                   "governor_speed_engage_count_target_cal it sets power_down_start_flag (was governor_speed_engage_count)"),
    "0x0040a7c6": ("crank_event_timebase_e", "engine_state_crank_time", None,
                   "e2m block 1068 +6 Engine_State_Crank_Time: the time base elapsed when CRANKING starts (was "
                   "crank_event_timebase_e)"),
    "0x0040a7ca": ("crank_event_timebase_d", "engine_state_run_time", None,
                   "e2m block 1068 +A Engine_State_Run_Time: the time base elapsed when RUNNING starts (was "
                   "crank_event_timebase_d)"),
    "0x0040a7ce": ("cold_start_phase3_flag", "engine_is_active_flag", None,
                   "e2m block 1068 +E Engine_Is_Active: 1 while engine_state is RUNNING (was cold_start_phase3_flag)"),
    "0x0040a7cf": ("cold_start_phase_2_6_flag", "engine_is_starting_flag", None,
                   "e2m block 1068 +F Engine_Is_Starting: 1 while engine_state is CRANKING or JUMP_START (was "
                   "cold_start_phase_2_6_flag)"),
    "0x0040a18c": ("fuel_correction_upper_limit", "altitude_derate_fuel_limit", None,
                   "The altitude derate fuel limit of cm848_calculateAltitudeDerateFuelLimit (fuel_demand_maximum = no "
                   "limit) (was fuel_correction_upper_limit)"),
    "0x0040a192": ("fuel_correction_upper_limit_lookup", "altitude_derate_air_handling_fault_fuel_limit", None,
                   "The air handling fault grid lookup of cm848_calculateAltitudeDerateFuelLimit (was "
                   "fuel_correction_upper_limit_lookup)"),
    "0x003ff065": ("fuel_correction_limit_enable_a", "altitude_derate_air_handling_fault_enable_a", None,
                   "ROM enable bits: which air handling faults (group a) switch the altitude derate to the air handling "
                   "fault grid (was fuel_correction_limit_enable_a)"),
    "0x003ff069": ("fuel_correction_limit_enable_b", "altitude_derate_air_handling_fault_enable_b", None,
                   "ROM enable bits: which air handling faults (group b) switch the altitude derate to the air handling "
                   "fault grid (was fuel_correction_limit_enable_b)"),
    "0x0040a18e": ("fuel_correction_temp_band_lower", "altitude_derate_ambient_temperature_band_lower", None, None),
    "0x0040a190": ("fuel_correction_temp_band_upper", "altitude_derate_ambient_temperature_band_upper", None, None),
    "0x0040a158": ("fuel_demand_load_based", "air_fuel_control_fuel_limit", None,
                   "The air fuel control (boost) fuel limit of cm848_calculateAirFuelControlFuelLimit (was "
                   "fuel_demand_load_based)"),
    "0x0040b53c": ("fuel_demand_rate_output", "net_torque_fuel_limit", None,
                   "The rate-limited net torque fuel limit of cm848_calculateNetTorqueFuelLimit (5888 = none) (was "
                   "fuel_demand_rate_output)"),
    "0x0040b99c": ("protection_fuel_limit_working", "fuel_limit_by_rpm_and_demand", None,
                   "The variable speed governor's engine speed x accelerator demand fuel limit "
                   "(cm848_calculateFuelLimitByRpmAndDemand) (was protection_fuel_limit_working)"),
    "0x003fb740": ("injection_timing_trim_working", "fuel_limit_by_rpm_and_demand_reference", None,
                   "fuel_limit_by_rpm_and_demand_reference_map_grid lookup (was injection_timing_trim_working)"),
    "0x003fb742": ("injection_timing_trim_a", "fuel_limit_by_rpm_and_demand_chi_lower", None,
                   "The blend map lookup for combustion_chi_lower_map_number (was injection_timing_trim_a)"),
    "0x003fb744": ("injection_timing_trim_b", "fuel_limit_by_rpm_and_demand_chi_upper", None,
                   "The blend map lookup for combustion_chi_upper_map_number (was injection_timing_trim_b)"),
    "0x003fb73c": ("injection_timing_trim_boost_blend_interp_state", "fuel_limit_by_rpm_and_demand_blend_interp_state",
                   None, None),
    "0x000645c4": ("fault_table_entry_5", "fuel_limit_by_rpm_and_demand_x_axis", None,
                   "Engine speed axis of the fuel_limit_by_rpm_and_demand grids (was fault_table_entry_5)"),
    "0x000645f0": ("fault_table_entry_6", "fuel_limit_by_rpm_and_demand_y_axis", None,
                   "Accelerator demand axis of the fuel_limit_by_rpm_and_demand grids (was fault_table_entry_6)"),
    "0x0040b232": ("cold_start_fuel_demand_ramp_output", "coolant_overheat_fuel_derate", None,
                   "The engine coolant overheat fuel derate (cm848_rampCoolantOverheatFuelDerate; 0x6400 = no limit) - "
                   "FUELING_STATE_COOLANT_OVERHEAT_DERATE when it is the lowest derate (was "
                   "cold_start_fuel_demand_ramp_output)"),
    "0x003fcdbc": ("cold_start_fuel_demand_ramp_prev", "coolant_overheat_fuel_derate_prev", None, None),
    "0x0040b234": ("cold_start_rpm_fuel_limit", "coolant_overheat_engine_speed_fuel_limit", None, None),
    "0x003fcdbe": ("cold_start_rpm_fuel_limit_prev", "coolant_overheat_engine_speed_fuel_limit_prev", None, None),
    "0x0040b23a": ("cold_start_fuel_demand_pi_correction", "coolant_overheat_pi_fuel_limit", None, None),
    "0x003fcdc0": ("cold_start_fuel_demand_pi_correction_prev", "coolant_overheat_pi_fuel_limit_prev", None, None),
    "0x003fcdd8": ("cold_start_fuel_demand_limit_min", "coolant_overheat_fuel_limit", None, None),
    "0x003fcdda": ("cold_start_fuel_demand_min_floor", "coolant_overheat_fuel_floor", None, None),
    "0x0040b22c": ("cold_start_coolant_temp_error", "coolant_overheat_temperature_error", None, None),
    "0x003fcdc2": ("cold_start_overheat_active_prev", "engine_overheat_derate_active_prev_flag", None, None),
    "0x00408762": ("cold_start_fuel_demand_ramp_increase_step", "coolant_overheat_fuel_derate_increase_step", None, None),
    "0x00408760": ("cold_start_fuel_demand_ramp_decrease_step", "coolant_overheat_fuel_derate_decrease_step", None, None),
    "0x0005ae58": ("cold_start_rpm_fuel_limit_axis", "coolant_overheat_engine_speed_fuel_limit_axis", None, None),
    "0x0005ae84": ("cold_start_rpm_fuel_limit_values", "coolant_overheat_engine_speed_fuel_limit_values", None, None),
    "0x003fcdc6": ("cold_start_coolant_bucket_cycle_count", "coolant_temperature_bucket_cycle_count", None, None),
}
NEW_ENUMS = []                 # whole enums.csv lines appended at the end
NEW_ROWS = []                  # (after_address, global_variables.csv line) inserted after that row
if len(sys.argv) > 2:          # the power take-off agent's verified results, merged by a second file
    exec(open(sys.argv[2]).read())


def edit(path, fn):
    with open(path, newline="") as f:
        text = f.read()
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = fn(text.split(eol))
    with open(path, "w", newline="") as f:
        f.write(eol.join(lines))


def one(lines, predicate, what):
    hits = [i for i, line in enumerate(lines) if predicate(line)]
    assert len(hits) == 1, (what, len(hits))
    return hits[0]


renamed_members = []   # (old member, new member) for the proof mapping


def enums(lines):
    i = one(lines, lambda line: line.startswith("# Fueling State (renamed 2026-11-19"), "fueling header")
    lines[i] = FUELING_HEADER
    for j, line in enumerate(lines):
        if not line.startswith("FUELING_STATE,"):
            continue
        enum, value, name, rest = line.split(",", 3)
        comment, size = rest.rsplit(",", 1)
        v = int(value, 0)
        suffix, new_comment = MEMBERS.get(v, (None, None))
        new_name = f"FUELING_STATE_{suffix}" if suffix else name
        if new_name != name:
            renamed_members.append((name, new_name))
        comment = new_comment if new_comment is not None else comment
        comment = comment.split(" - e2m label ")[0]
        if v in LABEL:
            comment += f" - e2m label {LABEL[v]} ({E2M} 0x{v:02X})"
        assert "," not in comment and '"' not in comment, v
        lines[j] = f"{enum},{value},{new_name},{comment},{size}"
    first = one(lines, lambda line: line.startswith("COLD_START_PHASE,0,"), "COLD_START_PHASE 0")
    start = first
    while lines[start - 1].startswith("#") and ("old start" in lines[start - 1].lower() or "Cold start" in lines[start - 1]
                                                or lines[start - 1].startswith("#   ") or "Transitions" in lines[start - 1]
                                                or "Tracks engine" in lines[start - 1]):
        start -= 1
    assert lines[start].startswith("# Cold start state machine"), lines[start]
    rows = [k for k, line in enumerate(lines) if line.startswith("COLD_START_PHASE,")]
    assert rows == list(range(first, first + 9)), rows
    new_rows = []
    for k in rows:
        enum, value, name, rest = lines[k].split(",", 3)
        size = rest.rsplit(",", 1)[1]
        old, new, comment = ENGINE_STATE[int(value)]
        assert name == old, (name, old)
        assert "," not in comment
        renamed_members.append((old, new))
        new_rows.append(f"ENGINE_STATE,{value},{new},{comment},{size}")
    lines[start:rows[-1] + 1] = ENGINE_STATE_HEADER + new_rows
    tail = len(lines) - 1 if lines and lines[-1] == '' else len(lines)
    lines[tail:tail] = NEW_ENUMS
    return lines


def functions(lines):
    for address, (old, new, comment) in FUNCTIONS.items():
        i = one(lines, lambda line, a=address, o=old: line.split(",")[:2] == [a, o], f"function {address}")
        if comment is None:
            kept = lines[i].split(",", 2)[2] if lines[i].count(",") >= 2 else ""
            comment = (kept + " " if kept else "") + f"(was {old})"
        lines[i] = f"{address},{new},{comment}"
    return lines


def globals_(lines):
    for address, (old, new, new_type, comment) in GLOBALS.items():
        i = one(lines, lambda line, a=address, o=old: line.startswith(f"{a},{o},"), f"global {address}")
        parts = lines[i].split(",", 3)
        if comment is None:
            kept = parts[3] if len(parts) > 3 else ""
            comment = (kept + " " if kept else "") + f"(was {old})"
        lines[i] = f"{address},{new},{new_type or parts[2]},{comment}"
    for after, row in NEW_ROWS:
        i = one(lines, lambda line, a=after: line.startswith(a + ','), f'row {after}')
        lines.insert(i + 1, row)
    return lines


edit(os.path.join(OUT, "enums.csv"), enums)
edit(os.path.join(OUT, "function_renames.csv"), functions)
edit(os.path.join(OUT, "global_variables.csv"), globals_)
here = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(here, "map_stage4.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, (old, new, _) in FUNCTIONS.items():
        f.write(f"{address},{new},{old},function\n")
    for address, (old, new, *_rest) in GLOBALS.items():
        f.write(f"{address},{new},{old},global\n")
    for old, new in renamed_members:
        f.write(f",{new},{old},enum member\n")
    f.write(",ENGINE_STATE,COLD_START_PHASE,enum\n")
print(f"applied stage 4: {len(renamed_members)} members renamed, {len(FUNCTIONS)} functions, {len(GLOBALS)} globals")
