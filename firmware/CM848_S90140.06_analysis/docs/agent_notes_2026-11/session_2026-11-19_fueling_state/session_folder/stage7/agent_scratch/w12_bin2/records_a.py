"""Decisions for bin 2 records 0-33 (index = position in bins/bin2.json)."""

A = [
    # 0
    dict(address="0x0005983a", new="fault_countdown_elapsed_time_mode_0", verdict="confirmed", type="dword", eng=None,
         evidence=("e2m 0023 +00 Fault_Countdown_Elapsed_Time_Mode_0 (HR, 0.2 s per count): entry 0 of the 4-mode x 2-dword "
                   "table that cm848_faultTimeoutHandler reads (lwzx, base 0x5983a + (aging_flags & 3) * 8) against "
                   "key_on_hour_meter - timestamp (0.2 s counts); the mode-0 pair is never read (guard aging_flags & 3 != 0); "
                   "dword; dump {raw} (the whole table is 0)"),
         comment=("e2m Fault_Countdown_Elapsed_Time_Mode_0 [DG00ELTM] (HR, 0.2 s per count): no countdown shall occur for a "
                  "mode 0 fault. Entry 0 of the table 0x5983a-0x59859 (4 modes x elapsed time + countdown interval dwords): "
                  "cm848_faultTimeoutHandler indexes it by (aging_flags & 3) * 8 and compares key_on_hour_meter - timestamp "
                  "with the elapsed time; mode 0 is skipped before the read. Same address as e2m 000F Fault_Data. "
                  "Dump {raw}.")),
    # 1
    dict(address="0x0005983e", new="fault_countdown_decrement_interval_mode_0", verdict="confirmed", type="dword", eng=None,
         evidence=("e2m 0023 +04 Fault_Countdown_Count_Down_Rate_Mode_0 (HR, 0.2 s per count): second dword of table entry 0; "
                   "cm848_faultTimeoutHandler reads [0x5983a + (aging_flags & 3) * 8 + 4] (lwz 4(r9)) as the time per fault "
                   "count decrement ((key_on_hour_meter - timestamp - elapsed) - interval * (debounce_count - 1) > interval); "
                   "the mode-0 pair is never read; dword; dump {raw}"),
         comment=("e2m Fault_Countdown_Count_Down_Rate_Mode_0 [DG00CUDN] (HR, 0.2 s per count): time that must elapse before "
                  "the fault count is decremented once the countdown has started (mode 0: no countdown). Second dword of "
                  "table entry 0 (see fault_countdown_elapsed_time_mode_0): cm848_faultTimeoutHandler reads it at +4 of the "
                  "(aging_flags & 3) * 8 index; mode 0 is skipped before the read. Dump {raw}.")),
    # 2
    dict(address="0x0005c296", new="accelerator_pedal_minimum_learning_confidence_count_limit", verdict="confirmed",
         type="word", eng=(0, "ms"),
         evidence=("e2m 1048 +08 Maximum_Confidence_Count (MSEC, 100 ms per count): cm848_fuelDemandOverrideHandler loads the "
                   "confidence counter fuel_demand_control_t_0040a57a.rate_delta with it when the pedal reads below the "
                   "current minimum, counts it down while the reading stays in the band, accepts the new minimum at 0 and "
                   "abandons the attempt when the counter climbs back to it; lhz x2; dump {raw} ({eng})"),
         comment=("e2m Maximum_Confidence_Count [CTMXCBCU] (MSEC, 100 ms per count): time to delay before setting a new "
                  "Throttle_Min (the learned pedal minimum, fuel_demand_control_t.throttle_based). "
                  "cm848_fuelDemandOverrideHandler starts the confidence counter rate_delta at this value when the pedal "
                  "reads below the minimum, counts it down while the reading stays within the confidence band and accepts "
                  "the new minimum at 0. Dump {raw} = 0.8 s.")),
    # 3
    dict(address="0x0005c298", new="accelerator_pedal_minimum_learning_confidence_band", verdict="confirmed", type="word",
         eng=(1, "%"),
         evidence=("e2m 1048 +0A Confidence_Band (%THROTTLE, 0.25 % per count): cm848_fuelDemandOverrideHandler compares "
                   "throttle_fuel_demand_tracked + it with accelerator_pedal_sensor_counts (pedal in 0.25 % counts) to count "
                   "the confidence counter up or down; lhz; dump {raw} ({eng})"),
         comment=("e2m Confidence_Band [CTCB] (%THROTTLE, 0.25 % per count): confidence range to allow for noise in the "
                  "Throttle_Min logic. cm848_fuelDemandOverrideHandler: while accelerator_pedal_sensor_counts stays at or "
                  "below throttle_fuel_demand_tracked + this band the candidate minimum counts toward acceptance; above it "
                  "the confidence counter counts back up. Dump {raw} = {eng}.")),
    # 4
    dict(address="0x0005c29c", new="accelerator_pedal_test_cell_autozero", verdict="confirmed", type="word", eng=(1, "%"),
         evidence=("e2m 1048 +0E Test_Cell_Auto_Zero (%THROTTLE, 0.25 % per count): cm848_fuelDemandBaseCalculation uses it "
                   "instead of the learned autozero fuel_demand_cal_index as the pedal zero reference while "
                   "governor_feature_flags & 4 is set (the mode in which cm848_fuelDemandCoordinator skips the pedal learning "
                   "chain and clears the pedal faults), and sets accelerator_off_idle when the pedal is above it; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m Test_Cell_Auto_Zero [CTTEZR] (%THROTTLE, 0.25 % per count, 6..33): autozero value when in the test "
                  "cell. cm848_fuelDemandBaseCalculation takes it as the pedal zero reference instead of the learned autozero "
                  "(fuel_demand_cal_index) while governor_feature_flags & 4 is set, and sets accelerator_off_idle when the "
                  "pedal is above it. Dump {raw} = {eng}.")),
    # 5
    dict(address="0x0005c2a2", new="accelerator_pedal_above_idle_transition_range", verdict="confirmed", type="word",
         eng=(1, "%"),
         evidence=("e2m 1048 +14 Throttle_Transition_Range (%THROTTLE, 0.25 % per count): "
                   "cm848_fuelDemandRateLimiterStateMachine moves rate_limiter_state from 1 to 2 (above idle) when "
                   "throttle_based (the learned minimum) + it < accelerator_pedal_sensor_counts; lhz; dump {raw} ({eng})"),
         comment=("e2m Throttle_Transition_Range [CTTHTZRN] (%THROTTLE, 0.25 % per count): sum of this and Throttle_Min "
                  "defines the % where the pedal is considered ABOVE_IDLE. cm848_fuelDemandRateLimiterStateMachine: "
                  "rate_limiter_state 1 -> 2 when fuel_demand_control_t.throttle_based + this < "
                  "accelerator_pedal_sensor_counts. Dump {raw} = {eng}.")),
    # 6
    dict(address="0x0005c2a8", new="accelerator_pedal_autozero_update_count_limit", verdict="confirmed", type="word",
         eng=None,
         evidence=("e2m 1048 +1A TPS_AZ_Update_Limit (UNITLESS): cm848_fuelDemandOverrideHandler stops learning when it is "
                   "below governor_speed_output_snapshot, which only that function increments (once per accepted new "
                   "minimum); lhz; dump {raw}"),
         comment=("e2m TPS_AZ_Update_Limit (UNITLESS, 1..255): update occurrence limit to allow for setting a new "
                  "Throttle_Min and autozero. cm848_fuelDemandOverrideHandler ends the learning once this is below "
                  "governor_speed_output_snapshot, which that function increments for every accepted new minimum (its three "
                  "uses are all there). Dump {raw} updates.")),
    # 7
    dict(address="0x0005c930", new="drivetrain_ratio_minimum_limit", verdict="confirmed", type="word", eng=(3, ""),
         evidence=("e2m 106D +02 Gear_Ratio_Min_Limit (UNITLESS, 1/2048): protectionTimeoutControl (the drivetrain_ratio "
                   "estimator) takes the raw ratio as valid only above it (and below the maximum limit 0x5c932) and clamps "
                   "drivetrain_ratio_raw up to it otherwise; lhz; dump {raw} ({eng})"),
         comment=("e2m Gear_Ratio_Min_Limit (UNITLESS, 1/2048): minimum gear ratio limit below which out of gear is true. "
                  "protectionTimeoutControl: drivetrain_ratio_raw must lie between this and the maximum limit (0x5c932) for "
                  "the divisor to count as valid; a lower ratio is clamped to it and the settle counter restarts. "
                  "Dump {raw} = {eng}.")),
    # 8
    dict(address="0x0005c934", new="drivetrain_ratio_filter_coefficient", verdict="confirmed", type="word", eng=(4, ""),
         evidence=("e2m 106D +06 Gear_Ratio_Filter_Constant (UNITLESS, 1/65536): protectionTimeoutControl puts it in "
                   "local_30[0], the coefficient of the EMA of drivetrain_ratio_raw while the ratio is settled; "
                   "initGovernorJ1939Bypass points the filter state at it; lhz; dump {raw} ({eng})"),
         comment=("e2m Gear_Ratio_Filter_Constant [time constant of the filter used in the gear ratio calculations] "
                  "(UNITLESS, 1/65536): EMA coefficient (weight of the previous value) of drivetrain_ratio_raw -> "
                  "drivetrain_ratio while the ratio is settled (protectionTimeoutControl; initGovernorJ1939Bypass points the "
                  "filter state at it). Unsettled value: 0x5c942. Dump {raw} = {eng}.")),
    # 9
    dict(address="0x0005c936", new="drivetrain_ratio_default", verdict="confirmed", type="word", eng=(2, ""),
         evidence=("e2m 106D +08 Default_Gear_Ratio (UNITLESS, 1/2048): protectionTimeoutControl loads it into "
                   "drivetrain_ratio_raw, drivetrain_ratio, fuel_flow_rpm_divisor and fuel_flow_rpm_divisor_saved (and the "
                   "filter accumulator) while vehicle_speed < vehicle_speed_minimum or the engine is stopped; lhz x2; "
                   "dump {raw} ({eng})"),
         comment=("e2m Default_Gear_Ratio [gear ratio which is initialized upon power-up] (UNITLESS, 1/2048): "
                  "protectionTimeoutControl seeds drivetrain_ratio_raw, drivetrain_ratio, fuel_flow_rpm_divisor and "
                  "fuel_flow_rpm_divisor_saved (and the EMA accumulator) with it while vehicle_speed < vehicle_speed_minimum "
                  "or the engine is stopped (10 uses). Dump {raw} = {eng}.")),
    # 10
    dict(address="0x0005c938", new="drivetrain_ratio_out_of_gear_ratio_change_delay", verdict="confirmed", type="word",
         eng=(2, "s"),
         evidence=("e2m 106D +0A Out_Of_Gear_GR_Delay (SEC, 0.04 s per count): protectionTimeoutControl reloads "
                   "fuel_flow_divisor_settle_counter with it when the ratio leaves its window (fuel_flow_divisor_invalid_flag "
                   "= 1) and counts it down while valid; lhz; dump {raw} ({eng})"),
         comment=("e2m Out_Of_Gear_GR_Delay (SEC, 0.04 s per count): minimum time the vehicle is out of gear due to a gear "
                  "ratio change. protectionTimeoutControl reloads fuel_flow_divisor_settle_counter with it whenever the ratio "
                  "is outside its tolerance window or the min / max limits; the counter counts down while the ratio is "
                  "valid. Dump {raw} = {eng}.")),
    # 11
    dict(address="0x0005c93a", new="drivetrain_ratio_out_of_gear_speed_mismatch_delay", verdict="confirmed", type="word",
         eng=(1, "s"),
         evidence=("e2m 106D +0C Out_Of_Gear_Spd_Delay (SEC, 0.04 s per count): protectionTimeoutControl reloads "
                   "drivetrain_ratio_decoupled_hold_counter with it while engine speed is at most 1000 rpm (8000) and "
                   "vehicle_speed is above 0x5c93c, else counts it down; lhz; dump {raw} ({eng})"),
         comment=("e2m Out_Of_Gear_Spd_Delay [time delay forced for RSG override for mismatch of veh. and eng. speeds] "
                  "(SEC, 0.04 s per count): protectionTimeoutControl reloads drivetrain_ratio_decoupled_hold_counter with it "
                  "while engine speed is at most 1000 rpm and vehicle_speed is above Out_Of_Gear_Speed (0x5c93c), else "
                  "counts it down. Dump {raw} = {eng}.")),
    # 12
    dict(address="0x0005c93c", new="drivetrain_ratio_out_of_gear_vehicle_speed_threshold", verdict="confirmed",
         type="word", eng=(1, "mph"),
         evidence=("e2m 106D +0E Out_Of_Gear_Speed (MPH, 1/256 mph per count): protectionTimeoutControl reloads "
                   "drivetrain_ratio_decoupled_hold_counter while vehicle_speed (1/256 mph) is above it and engine speed is at "
                   "most 1000 rpm, and counts the counter down otherwise; lhz; dump {raw} ({eng})"),
         comment=("e2m Out_Of_Gear_Speed [vehicle speed above which an out of gear condition is considered] (MPH, 1/256 mph "
                  "per count): protectionTimeoutControl reloads drivetrain_ratio_decoupled_hold_counter with "
                  "Out_Of_Gear_Spd_Delay while vehicle_speed is above this and engine speed is at most 1000 rpm; otherwise "
                  "the counter counts down. Dump {raw} = {eng}.")),
    # 13
    dict(address="0x0005c940", new="drivetrain_ratio_out_of_gear_settling_delay", verdict="confirmed", type="word",
         eng=(1, "s"),
         evidence=("e2m 106D +12 Out_Of_Gear_Settling_Delay (SEC, 0.04 s per count): protectionTimeoutControl loads "
                   "drivetrain_ratio_unsettled_release_timer with it when fuel_flow_divisor_settle_counter reaches 1 and "
                   "counts it down; lhz; dump {raw} ({eng})"),
         comment=("e2m Out_Of_Gear_Settling_Delay [the additional time added when over RSG] (SEC, 0.04 s per count): "
                  "protectionTimeoutControl arms drivetrain_ratio_unsettled_release_timer with it when "
                  "fuel_flow_divisor_settle_counter reaches 1; the timer must reach 0 before drivetrain_ratio_unsettled_flag "
                  "clears. Dump {raw} = {eng} (no extra time).")),
    # 14
    dict(address="0x0005c942", new="drivetrain_ratio_out_of_gear_filter_coefficient", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 106D +14 Gear_Ratio_OOG_Filter_Constant (UNITLESS, 1/65536): protectionTimeoutControl uses it as the "
                   "filter coefficient (local_30[0]) instead of Gear_Ratio_Filter_Constant while "
                   "drivetrain_ratio_unsettled_flag = 1; lhz; dump {raw} ({eng})"),
         comment=("e2m Gear_Ratio_OOG_Filter_Constant [gear ratio filter constant while out of gear] (UNITLESS, 1/65536): "
                  "EMA coefficient of drivetrain_ratio_raw while drivetrain_ratio_unsettled_flag is 1 "
                  "(protectionTimeoutControl; the settled value is 0x5c934). Dump {raw} = {eng}.")),
    # 15
    dict(address="0x0005c946", new="drivetrain_ratio_fraction_tolerance", verdict="confirmed", type="word", eng=(4, ""),
         evidence=("e2m 106D +18 Gear_Ratio_Fraction_Tolerance (UNITLESS, 1/2048): protectionTimeoutControl accepts the ratio "
                   "only if (|raw - filtered| << 11) / filtered is at most it; lhz; dump {raw} ({eng})"),
         comment=("e2m Gear_Ratio_Fraction_Tolerance [tolerance for determining out of gear] (UNITLESS, 1/2048): "
                  "protectionTimeoutControl: the ratio is in gear only if (|drivetrain_ratio_raw - drivetrain_ratio| << 11) "
                  "/ drivetrain_ratio is at most this fraction (the absolute tolerances 0x5c92e / 0x5c944 also apply). "
                  "Dump {raw} = {eng}.")),
    # 16
    dict(address="0x0005c2f0", new="engine_speed_limit_fault_derate_full_severity", verdict="confirmed", type="word",
         eng=(0, "rpm"),
         evidence=("e2m 10B5 +00 Maximum_Derate_RPM (RPM, 0.125 rpm per count): cm848_initializeFaultDerateEngineSpeedLimit "
                   "sets engine_speed_limit_fault_derate_span = engine_speed_limit_default_cal - it; the sibling +02 "
                   "RPM_Limit_Filter_Time_Constant is the EMA coefficient WORD_0005c2f2 of the same function; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m Maximum_Derate_RPM [EPMXDQRP] (RPM, 0.125 rpm per count): maximum engine rpm when fully derated, i.e. "
                  "severity index = 1.0. cm848_initializeFaultDerateEngineSpeedLimit sets "
                  "engine_speed_limit_fault_derate_span = engine_speed_limit_default_cal - this, so "
                  "cm848_calculateFaultDerateEngineSpeedLimit lowers the limit by severity x span / 256 down to it. "
                  "Dump {raw} = {eng}.")),
    # 17
    dict(address="0x0005a46c", new="j1939_default_engine_source_address", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 10E3 +00 J1939_Default_Engine_Source_Address (UNITLESS): cm848_copyROMCalibrationToRAM copies it to "
                   "j1939_source_address (the ECM engine node address); lhz; dump {raw} (engine #1)"),
         comment=("e2m J1939_Default_Engine_Source_Address [JCDFEGSA] (UNITLESS): default J1939 network address for the ECM "
                  "as engine node. cm848_copyROMCalibrationToRAM copies it to j1939_source_address at boot (its only use). "
                  "Dump {raw} = source address 0 (engine #1).")),
    # 18
    dict(address="0x0005a46e", new="j1939_default_retarder_source_address", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 10E3 +02 J1939_Default_Retarder_Source_Address (UNITLESS): cm848_copyROMCalibrationToRAM copies it to "
                   "j1939_engine_retarder_source_address; lhz; dump {raw}"),
         comment=("e2m J1939_Default_Retarder_Source_Address [JCDFRDSA] (UNITLESS): default J1939 network address for the ECM "
                  "as retarder node upon power-up. cm848_copyROMCalibrationToRAM copies it to "
                  "j1939_engine_retarder_source_address (its only use). Dump {raw} = SA 41 (Retarder, Exhaust, Engine #1).")),
    # 19
    dict(address="0x0005a486", new="j1939_command_security_flags", verdict="uncertain", type="dword", eng=None,
         evidence=("e2m 10E3 +1A Command_Security_Flags (UNITLESS, 4 bytes): j1939_diagServiceDispatch tests bit (command & "
                   "7) of byte (command >> 3) of it (lbzx base 0x5a486, commands below 26) to require "
                   "cm848_processSecurityCodeConversion, so the role fits; uncertain only for the shape: the sole access is "
                   "byte-wise (census none), a 4-byte record read as 4 separate bytes, so byte[4] would render better than "
                   "dword (orchestrator's call); dump 0x440fff03 (bytes 44 0f ff 03)"),
         comment=("e2m Command_Security_Flags [JCCZSUFG] (UNITLESS, 4 bytes): bit-mapped parameter determining access "
                  "restriction of commands. j1939_diagServiceDispatch reads it as 4 bytes (lbzx at 0x5a486 + (command >> 3), "
                  "bit command & 7): a set bit makes the command need cm848_processSecurityCodeConversion. Dump bytes 44 0f "
                  "ff 03 = commands 2, 6, 8-11 and 16-25 restricted.")),
    # 20
    dict(address="0x0005a48e", new="", verdict="rejected", type="word", eng=None,
         evidence=("layout drift: 0x5a48e is e2m 1228 +02 Jcomm_Diag_MPH_in_Snapshot [JCVSSI], not 10E3 +22 "
                   "Jcomm_DD_CC_I_Gain; cm848_j1939BuildDm4FreezeFrame compares it with 1 to include the vehicle speed in the "
                   "DM4 freeze frame (else 0xffff); block 1228 starts at 0x5a48c, so block 10E3 ends before +20 in the truck; "
                   "lhz; dump {raw}"),
         comment=("Rejected (layout drift): 0x5a48e is not e2m 10E3 +22 Jcomm_DD_CC_I_Gain (driver demand cruise integrator "
                  "gain, MM3S/MPH/SEC); the code at the address is the DM4 freeze frame vehicle speed switch, e2m 1228 +02. "
                  "Not applied.")),
    # 21
    dict(address="0x0005a490", new="", verdict="rejected", type="word", eng=None,
         evidence=("layout drift: 0x5a490 is e2m 1228 +04 OBD_Compliance [JCOBDG], not 10E3 +24 Jcomm_DD_PTO_I_Gain; "
                   "cm848_j1939HandlePgn65230Dm5Readiness copies its low byte into DM5 byte 3 (DAT_003fad58, after the active / "
                   "previously active DTC counts); block 1228 starts at 0x5a48c; lhz; dump {raw}"),
         comment=("Rejected (layout drift): 0x5a490 is not e2m 10E3 +24 Jcomm_DD_PTO_I_Gain (driver demand PTO integrator "
                  "gain); the code at the address is the DM5 OBD compliance byte, e2m 1228 +04. Not applied.")),
    # 22
    dict(address="0x0005a492", new="", verdict="rejected", type="word", eng=None,
         evidence=("layout drift: 0x5a492 is e2m 1228 +06 Supported_Continuous_Monitors [JCCTMR], not 10E3 +26 "
                   "DDT_TSC_ASG_Filter_Constant; cm848_j1939HandlePgn65230Dm5Readiness copies its low byte into DM5 byte 4 "
                   "(DAT_003fad59); the next word 0x5a494 (1228 +08) is the DM5 non-continuous monitors word "
                   "(j1939_feature_config_word); lhz; dump {raw}"),
         comment=("Rejected (layout drift): 0x5a492 is not e2m 10E3 +26 DDT_TSC_ASG_Filter_Constant (driver demand ASG "
                  "throttle filter); the code at the address is the DM5 continuously monitored systems byte, e2m 1228 +06. "
                  "Not applied.")),
    # 23
    dict(address="0x0005c36c", new="engine_retarder_shift_assist_fuel_demand_limit", verdict="confirmed", type="word",
         eng=(1, "mm3"),
         evidence=("e2m 10FC +02 Jcomm_Retarder_Shift_Assist_Limit (MM3S, 0.0679 mm3 per count): "
                   "cm848_processEngineRetarderTsc1Request and governor_resetModeStateOnCondition compare it with "
                   "engine_operating_mode_fuel_demand (user fueling) and drop the transmission's retarder request when the "
                   "fueling is at or above it; lhz x2; dump {raw} ({eng})"),
         comment=("e2m Jcomm_Retarder_Shift_Assist_Limit [JCEBSILM] (MM3S, 0.0679 mm3 per count): limit to which user fueling "
                  "is compared to determine if engine brakes should be ... (e2m text cut off). "
                  "cm848_processEngineRetarderTsc1Request / governor_resetModeStateOnCondition clear the retarder override "
                  "(mode 0) when engine_operating_mode_fuel_demand >= this. Dump {raw} = {eng}.")),
    # 24
    dict(address="0x0005c376", new="engine_retarder_configuration_idle_torque_percent", verdict="confirmed",
         type="word", eng=(1, "%"),
         evidence=("e2m 10FC +0C Jcomm_Retarder_Torque_at_Idle (%, 1/256 % per count): "
                   "cm848_buildPgn65249RetarderConfigurationMessage sends 125 - (value >> 8) as the percent torque byte at idle "
                   "(DAT_003fae54) of the PGN 65249 RC message; the 10FC siblings fill the other speed / torque points of that "
                   "message in e2m order; lhz; dump {raw} ({eng})"),
         comment=("e2m Jcomm_Retarder_Torque_at_Idle [JCRDISTQ] (%, 1/256 % per count): available torque the retarder can "
                  "provide at idle (point 1 of the retarder configuration map). "
                  "cm848_buildPgn65249RetarderConfigurationMessage sends 125 - (value >> 8) as the percent torque byte of the "
                  "PGN 65249 Retarder Configuration broadcast. Dump {raw} = {eng}.")),
    # 25
    dict(address="0x003fdfc0", new="fuel_temperature_derate_engine_speed_severity_index_cal", verdict="confirmed",
         type="word", eng=None,
         evidence=("e2m 1143 +02 Fuel_Temperature_RPM_Index (UNITLESS, 1/256): word 1 of the 30-byte per-channel EEPROM record "
                   "at 0x3fdfbe (channel 0 = fuel temperature): cm848_calculateFaultDerateEngineSpeedLimit stores the "
                   "channel's engine speed derate ramp there (sth 2(r27), r27 = 0x3fdfbe, stride 30; census none) and "
                   "governor_faultDerate_mainLoop_update tests it with the fueling index for 0; word; dump {raw}"),
         comment=("e2m Fuel_Temperature_RPM_Index [EPFTRPIX] (UNITLESS, 1/256, 0..1): fuel temperature RPM severity index. "
                  "Word 1 of the per-channel record at 0x3fdfbe (stride 30; word 0 is the fueling index): "
                  "cm848_calculateFaultDerateEngineSpeedLimit stores the channel's derate ramp (0..256) here and "
                  "governor_faultDerate_mainLoop_update clears the active channel when both indexes are 0. EEPROM mirror, "
                  "so _cal. Dump {raw}.")),
    # 26
    dict(address="0x003fdd7e", new="j1939_anti_theft_command_state_cal", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 117F +12 Jcomm_AT_Command_State (UNITLESS, 0..6): j1939_receivePgn56576Handler (PGN 56576 Anti-theft "
                   "Request) stores byte 0 >> 5 (SPN 1201 Anti-theft Command States) there, or 6 when the command / exit mode / "
                   "encryption bits are reserved; sth x2; dump {raw} (the invalid-request value)"),
         comment=("e2m Jcomm_AT_Command_State [JCATCMST] (UNITLESS, 0..6): indicates the command being requested via the "
                  "datalink (for the vehicle anti-theft, VAT). j1939_receivePgn56576Handler (PGN 56576, Anti-theft Request) "
                  "stores byte 0 >> 5 (SPN 1201) here, or 6 when a field is reserved. EEPROM mirror, so _cal. Dump {raw}.")),
    # 27
    dict(address="0x003fdd82", new="j1939_anti_theft_desired_exit_mode_cal", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 117F +16 Jcomm_AT_Desired_Exit_Mode (UNITLESS, 0..2): j1939_receivePgn56576Handler stores "
                   "(byte 0 & 0x18) >> 3 (SPN 1200 Anti-theft Desired Exit Mode) there; sth; dump {raw}"),
         comment=("e2m Jcomm_AT_Desired_Exit_Mode [JCATEXMD] (UNITLESS, 0..2): indicates the desired mode of engine locking at "
                  "key-off (for VAT). j1939_receivePgn56576Handler stores (byte 0 & 0x18) >> 3 of the PGN 56576 Anti-theft "
                  "Request (SPN 1200). EEPROM mirror, so _cal. Dump {raw}.")),
    # 28
    dict(address="0x003fdd84", new="j1939_anti_theft_encryption_indicator_cal", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 117F +18 Jcomm_AT_Encryption_Indicator (UNITLESS, 0..2): j1939_receivePgn56576Handler stores "
                   "(byte 0 & 6) >> 1 (SPN 1199 Anti-theft Encryption Indicator) there; sth; dump {raw}"),
         comment=("e2m Jcomm_AT_Encryption_Indicator [JCATEYID] (UNITLESS, 0..2): indicates via the datalink if the VAT "
                  "encryption seed is required or a password is present. j1939_receivePgn56576Handler stores (byte 0 & 6) >> "
                  "1 of the PGN 56576 Anti-theft Request (SPN 1199). EEPROM mirror, so _cal. Dump {raw}.")),
    # 29
    dict(address="0x00408e4c", new="cruise_ramp_target_speed_rate_limit_increase", verdict="confirmed", type="word",
         eng=(2, "mph"),
         evidence=("e2m 1189 +00 CC_Reference_Rate_Pos (MPH, 0.0977 per count): protectionOutputActuatorControl limits the "
                   "rise of cruise_ramp_target_speed per pass to cruise_ramp_target_prev + it when cruise_speed_command is "
                   "above the previous target; lhz; dump {raw} ({eng})"),
         comment=("e2m CC_Reference_Rate_Pos (MPH, 0.0977 per count): positive slew rate limit on the cruise control "
                  "reference. protectionOutputActuatorControl (FUELING_STATE_CRUISE_CONTROL): when cruise_speed_command is "
                  "above cruise_ramp_target_prev, cruise_ramp_target_speed rises by at most this per pass. "
                  "Dump {raw} = {eng} (e2m scale).")),
    # 30
    dict(address="0x00408e4e", new="cruise_ramp_target_speed_rate_limit_decrease", verdict="confirmed", type="word",
         eng=(2, "mph"),
         evidence=("e2m 1189 +02 CC_Reference_Rate_Neg (MPH, 0.0977 per count): protectionOutputActuatorControl limits the "
                   "fall of cruise_ramp_target_speed per pass to cruise_ramp_target_prev - it when cruise_speed_command is "
                   "below the previous target; lhz; dump {raw} ({eng})"),
         comment=("e2m CC_Reference_Rate_Neg (MPH, 0.0977 per count): negative slew rate limit on the cruise control "
                  "reference. protectionOutputActuatorControl (FUELING_STATE_CRUISE_CONTROL): when cruise_speed_command is "
                  "below cruise_ramp_target_prev, cruise_ramp_target_speed falls by at most this per pass. "
                  "Dump {raw} = {eng} (e2m scale).")),
    # 31
    dict(address="0x00408e50", new="cruise_pid_derivative_filter_coefficient_1", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 1189 +04 Cruise_RSG_Derivative_Filter_C1 (UNITLESS, 1/65536): initCruiseConfirmFlags stores its "
                   "address in PTR_DAT_003fd022 (coefficient 1 of the 4-word second-order filter record at 0x3fd022) that "
                   "protectionOutputActuatorControl runs on vehicle_speed_rise_limited and differences (differential path); "
                   "census none, the helper loads the coefficient with lhz 0(r12); dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Derivative_Filter_C1 (UNITLESS, 1/65536): 2nd order derivative filter in the cc/rsg "
                  "governor, coefficient 1. initCruiseConfirmFlags stores its address as coefficient pointer 1 of the filter "
                  "record at 0x3fd022 that protectionOutputActuatorControl runs on vehicle_speed_rise_limited (the speed change "
                  "per pass feeds the differential path); read as an unsigned 16-bit word. Dump {raw} = {eng}.")),
    # 32
    dict(address="0x00408e52", new="cruise_pid_derivative_filter_coefficient_3", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 1189 +06 Cruise_RSG_Derivative_Filter_C3 (UNITLESS, 1/65536): initCruiseConfirmFlags stores its "
                   "address in PTR_DAT_003fd026 (coefficient 3 of the same filter record at 0x3fd022); the helper loads it "
                   "with lhz 0(r11); census none; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Derivative_Filter_C3 (UNITLESS, 1/65536): 2nd order derivative filter in the cc/rsg "
                  "governor, coefficient 3. initCruiseConfirmFlags stores its address as coefficient pointer 3 of the filter "
                  "record at 0x3fd022 (see cruise_pid_derivative_filter_coefficient_1); read as an unsigned 16-bit word. "
                  "Dump {raw} = {eng}.")),
    # 33
    dict(address="0x00408e54", new="cruise_pid_differential_path_maximum", verdict="confirmed", type="i16", eng=(1, "rpm"),
         evidence=("e2m 1189 +08 Cruise_RSG_Diff_Path_Max (RPM, S, 0.006875 per count): protectionOutputActuatorControl clamps "
                   "the differential (speed rate) path value (rate x gain x cruise_pid_rate_gain_scale / 22) to at most it, "
                   "the minimum being 0x408e56; lha; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Diff_Path_Max (RPM, S, 0.006875 per count): max limit on the output of the differential "
                  "path in the cc/rsg governor. protectionOutputActuatorControl limits the speed-rate path (speed change x "
                  "rate gain x cruise_pid_rate_gain_scale / 22) to at most this before the Kd term and the integrator "
                  "correction. Dump {raw} = {eng}.")),
]
