"""Wave 14, functions3: items 0-11 (name, deciding quote, evidence, plate)."""

ITEMS_A = [
    # 0  0x0004272c
    dict(
        new="cm848_selectTwoSpeedRearAxleRatio",
        quote="(rear_axle_ratio = rear_axle_ratio_high_cal, (switch_input_state_bits[3] & 0x80) == 0)) {",
        evidence=(
            "Select on a two-speed axle: if (two_speed_axle_enable_cal != 0) it loads rear_axle_ratio_high_cal and then "
            "rear_axle_ratio_low_cal when (switch_input_state_bits[3] & 0x80) == 0 (switch 31 clear); with the enable 0 it "
            "stores nothing, so rear_axle_ratio keeps the start-up HIGH value of 0x42770. Called every pass from "
            "cm848_periodicTaskSet_auxiliaryControl. The output shaft consumers use the LOW record in that single-speed "
            "case instead (cm848_calculateVehicleSpeedFromOutputShaft: (two_speed_axle_enable_cal == 0) || "
            "((switch_input_state_bits[3] & 0x80) == 0) -> protection_trim_divisor_working). Dump (word): rear_axle_ratio, "
            "rear_axle_ratio_low_cal and rear_axle_ratio_high_cal are all 453, two_speed_axle_enable_cal is 0."
        ),
        plate=(
            "Selects the rear axle ratio in use for a two-speed axle: rear_axle_ratio (e2m 117D +30 Rear_Axle_Ratio, 1/128 "
            "per count) is set from rear_axle_ratio_high_cal (EEPROM 0xb2, e2m 1180 +C Rear_Axle_Ratio_High) and, while "
            "switch 31 (switch_input_state_bits[3] bit 0x80) is clear, from rear_axle_ratio_low_cal (EEPROM 0xac, e2m 1180 "
            "+6 Rear_Axle_Ratio_Low). The stores run only when two_speed_axle_enable_cal is nonzero; with it 0 the word "
            "keeps the start-up value that 0x42770 loads from the HIGH record, whereas "
            "cm848_calculateVehicleSpeedFromOutputShaft and cm848_calculateDrivetrainRatioFromVehicleSpeed use the LOW "
            "record in that single-speed case. Called every pass of cm848_periodicTaskSet_auxiliaryControl. Inputs: "
            "two_speed_axle_enable_cal, switch 31, the two ratio records. Output: rear_axle_ratio (read by "
            "cm848_processGovernorSpeedSetpoint, cm848_calculateRiseLimitedVehicleSpeed and "
            "cm848_calculateCruisePidRateGainScale). 453 = 3.54 in the dump for all three words; "
            "two_speed_axle_enable_cal is 0 there."
        ),
    ),
    # 1  0x00042770
    dict(
        new="cm848_initializeRearAxleRatio",
        quote="rear_axle_ratio = rear_axle_ratio_high_cal;",
        evidence=(
            "The whole body is one store, rear_axle_ratio = rear_axle_ratio_high_cal; (the HIGH record, EEPROM 0xb2, e2m "
            "1180 +C). Its only caller is the boot list of cm848_applicationMain, right before the divisor calculation "
            "0x5268e8, so it runs once at start-up. The periodic select 0x4272c stores nothing while "
            "two_speed_axle_enable_cal is 0, so this value stays in use on a single-speed axle. Dump (word): 453."
        ),
        plate=(
            "Start-up initializer of the rear axle ratio in use: rear_axle_ratio (e2m 117D +30 Rear_Axle_Ratio, 1/128 per "
            "count) = rear_axle_ratio_high_cal (EEPROM 0xb2, e2m 1180 +C Rear_Axle_Ratio_High). Called once from the boot "
            "list of cm848_applicationMain, just before the divisor calculation 0x5268e8. The value stays in use on a "
            "single-speed axle (two_speed_axle_enable_cal = 0: the periodic select 0x4272c then stores nothing) and is the "
            "start value on a two-speed axle, where the periodic select replaces it with rear_axle_ratio_low_cal while "
            "switch 31 is clear. 453 = 3.54 in the dump."
        ),
    ),
    # 2  0x005268e8
    dict(
        new="cm848_calculateOutputShaftToVehicleSpeedDivisors",
        quote="protection_trim_divisor_cal = (uint)rear_axle_ratio_high_cal * (uint)protection_timing_period_cal;",
        evidence=(
            "protection_trim_divisor_working = rear_axle_ratio_low_cal * protection_timing_period_cal and "
            "protection_trim_divisor_cal = rear_axle_ratio_high_cal * protection_timing_period_cal; "
            "protection_timing_period_cal (0x3fee7a) is e2m 132C +0 Tire_Size (tire revolutions per mile). The only reader "
            "of the two products is cm848_calculateVehicleSpeedFromOutputShaft: output_shaft_speed_current x 0x3c000 / "
            "divisor, and 0x3c000 = 256 x 60 x 128 / 8 (1/256 mph from 1/8 rpm with the ratio in 1/128), so they are "
            "divisors, not trims. Called once from the boot list of cm848_applicationMain after the rear axle ratio "
            "initializer. Dump: Tire_Size word 251 (the e2m range is 300-725; not interpreted), both divisors dword "
            "113703 = 453 x 251."
        ),
        plate=(
            "Start-up calculation of the output shaft speed to vehicle speed divisors: protection_trim_divisor_working "
            "(0x3fd062) = rear_axle_ratio_low_cal x protection_timing_period_cal and protection_trim_divisor_cal "
            "(0x3fd066) = rear_axle_ratio_high_cal x protection_timing_period_cal, one dword each. The ratio words are e2m "
            "1180 +6 / +C (1/128 per count); protection_timing_period_cal (EEPROM mirror 0x3fee7a) is e2m 132C +0 "
            "Tire_Size, the number of tire revolutions per mile (the e2m range is 300-725; 251 in the dump). "
            "cm848_calculateVehicleSpeedFromOutputShaft divides output_shaft_speed_current (1/8 rpm) x 0x3c000 (= 256 x 60 "
            "x 128 / 8) by the _cal divisor when two_speed_axle_enable_cal is on and switch 31 is set, else by the "
            "_working one, which gives vehicle speed in 1/256 mph. Called once from the boot list of "
            "cm848_applicationMain, after the rear axle ratio initializer 0x42770. 113703 = 453 x 251 for both in the dump."
        ),
    ),
    # 3  0x00525e54
    dict(
        new="cm848_updateDrivetrainRatio",
        quote="((uint)drivetrain_ratio_raw,&engine_temperature_protection_filter_state);",
        evidence=(
            "Estimate + filter + settle state of the drivetrain ratio (engine speed over vehicle or output shaft speed x "
            "2048): for the drivetrain types without a J1939 speed it computes drivetrain_ratio_raw = "
            "vehicle_speed_sensor_period x drivetrain_ratio_period_scale_cal x 16 / drivetrain_ratio_engine_period_average "
            "(0x7ffd when it cannot be computed), then exponentialMovingAverage((uint)drivetrain_ratio_raw, "
            "&engine_temperature_protection_filter_state) -> drivetrain_ratio, then the limit / tolerance check, the "
            "out-of-gear timers that clear drivetrain_ratio_unsettled_flag, governor_j1939_bypass_flag 1 / 2 / 3 against "
            "the top gear thresholds and the stable-divisor save. The J1939 types get their raw ratio elsewhere "
            "(cm848_calculateDrivetrainRatioFromVehicleSpeed) and only pass through the filter here, so update covers "
            "every path; estimate (the other proposal) covers one. Limit compare: (drivetrain_ratio_minimum_limit < uVar4) && "
            "(uVar4 < DAT_0005c932) with uVar4 = drivetrain_ratio_raw. Caller: cm848_periodicTaskSet_outputs."
        ),
        plate=(
            "Drivetrain ratio update, one pass of cm848_periodicTaskSet_outputs (skipped while drivetrain_type is "
            "DRIVETRAIN_STANDALONE). The ratio is engine speed over vehicle (or output shaft) speed x 2048. While "
            "vehicle_speed is below vehicle_speed_minimum or the engine is stopped it reseeds drivetrain_ratio_raw, "
            "drivetrain_ratio, fuel_flow_rpm_divisor, fuel_flow_rpm_divisor_saved and the filter accumulator with "
            "drivetrain_ratio_default and sets drivetrain_ratio_unsettled_flag. Otherwise, on the drivetrain types without "
            "a J1939 speed, it computes drivetrain_ratio_raw = vehicle_speed_sensor_period x drivetrain_ratio_period_scale_cal "
            "(e2m 1195 +2 GR_Constant) x 16 / drivetrain_ratio_engine_period_average (0x7ffd = not computable); the J1939 "
            "types get it elsewhere. It low-pass filters drivetrain_ratio_raw into drivetrain_ratio (the settled or the "
            "out-of-gear filter coefficient), checks it against the minimum / maximum limits and tolerances (in window: "
            "fuel_flow_rpm_divisor = drivetrain_ratio; outside: fuel_flow_divisor_invalid_flag = 1, the raw ratio is "
            "clamped and drivetrain_ratio_change_settle_counter is reloaded) and runs the out-of-gear timers "
            "(drivetrain_ratio_decoupled_hold_counter, drivetrain_ratio_unsettled_release_timer; e2m 106C +6 / +8) that "
            "clear drivetrain_ratio_unsettled_flag (e2m 117D +E Out_Of_Gear) only when all are 0. It also publishes "
            "governor_bypass_threshold_low / _high (from top_gear_ratio_cal, e2m 1185 +A), sets governor_j1939_bypass_flag "
            "to 1 / 2 / 3 as drivetrain_ratio is below the low / below the high / above the high threshold, and commits "
            "fuel_flow_rpm_divisor_saved once the divisor is stable and final_fueling is above its threshold."
        ),
    ),
    # 4  0x0003e210
    dict(
        new="cm848_requestPowerDownDelayWhileVehicleMoving",
        quote="ecm_power_down_delay_request_flag = 1;",
        evidence=(
            "The whole body is if (vehicle_speed_unfiltered != 0) { ecm_power_down_delay_request_flag = 1; } (e2m 117D +4C "
            "Powerdown_Delay_Request '[SDDYFG] The ECM will not powerdown until this is inactive'). cm848_updateEngineState "
            "starts the delayed power-down only while (ecm_power_down_timer != 0 && ecm_power_down_delay_request_flag == "
            "0) and clears the flag at the end of every SHUTDOWN pass. No fuel demand is involved. Caller: "
            "cm848_periodicTaskSet_sensorProcessing. Dump (word): the flag and vehicle_speed_unfiltered are both 0 (no "
            "speed sensor wired)."
        ),
        plate=(
            "Requests a delay of the ECM power-down while the vehicle is moving: sets "
            "ecm_power_down_delay_request_flag (e2m 117D +4C Powerdown_Delay_Request, '[SDDYFG] The ECM will not powerdown "
            "until this is inactive') to 1 when vehicle_speed_unfiltered (1/256 mph, from the speed sensor or the J1939 "
            "output shaft speed) is nonzero, and never clears it. cm848_updateEngineState starts the delayed power-down in "
            "SHUTDOWN only while the flag is 0 and clears it at the end of every SHUTDOWN pass. Runs every pass of "
            "cm848_periodicTaskSet_sensorProcessing. On this truck the speed reads 0 (no speed sensor wired), so the flag "
            "is never set (0 in the dump)."
        ),
    ),
    # 5  0x0051ba1c
    dict(
        new="cm848_accumulateConverterClutchRatioDeltaSum",
        quote="iVar1 = (int)(short)converter_clutch_rationality_ratio_delta_sum +",
        evidence=(
            "converter_clutch_rationality_ratio_delta_sum = saturate16((short)converter_clutch_rationality_ratio_delta_sum "
            "+ (short)protection_pid_error_term) (clamps 0x8000 / 0x7fff): a running sum of the ratio deltas of the P1740 "
            "converter clutch rationality test (fault 319 -> ROM slot table 0x5985a -> obd_dtc_code_table = P1740), "
            "e2m 8C34 +9 TCC_Rationality_Sum_Ratio_Delta; no setpoint, gain or integrator term. Called by "
            "cm848_monitorConverterClutchAndOverdrivePerformance right after the delta function 0x51ba6c, at the start of "
            "an engagement and on each timed step."
        ),
        plate=(
            "Accumulates the converter clutch rationality ratio delta: converter_clutch_rationality_ratio_delta_sum (e2m "
            "8C34 +9 TCC_Rationality_Sum_Ratio_Delta, signed word, 1/256) = signed 16-bit saturating sum of itself and "
            "protection_pid_error_term (the ratio delta that 0x51ba6c just calculated); it clamps at -32768 / 32767. Called "
            "by cm848_monitorConverterClutchAndOverdrivePerformance (the P1740 converter clutch / overdrive performance "
            "monitor) right after each ratio delta, at the start of an engagement and on each timed step. The monitor "
            "judges the sum against protection_pid_integrator_threshold (e2m 8C33 +7 TCC_Rationality_Min_Ratio_Delta) when "
            "the rationality timer reaches its limit. It is a plain running sum, not a PID integrator. 0 in the dump."
        ),
    ),
    # 6  0x0051ba6c
    dict(
        new="cm848_calculateConverterClutchRatioDelta",
        quote="iVar1 = (uint)protection_pid_rpm_setpoint_prev - (uint)converter_clutch_rationality_ratio;",
        evidence=(
            "protection_pid_error_term = saturate16(protection_pid_rpm_setpoint_prev - converter_clutch_rationality_ratio): "
            "the previous sample of the engine speed to output speed ratio (e2m 8C34 +7 TCC_Rationality_Ratio) minus the new "
            "one; the caller stores the new sample into protection_pid_rpm_setpoint_prev afterwards. No setpoint or gain "
            "is involved, so it is not a PID error. Caller: cm848_monitorConverterClutchAndOverdrivePerformance (P1740: "
            "fault 319 -> ROM slot table 0x5985a -> obd_dtc_code_table), two calls, each followed by 0x51ba1c."
        ),
        plate=(
            "Calculates the converter clutch rationality ratio delta: protection_pid_error_term = saturate16("
            "protection_pid_rpm_setpoint_prev - converter_clutch_rationality_ratio), i.e. the previous sample of the engine "
            "speed to transmission output speed ratio minus the new sample (converter_clutch_rationality_ratio, e2m 8C34 "
            "+7 TCC_Rationality_Ratio, 1/256), clamped to -32768..32767. Called by "
            "cm848_monitorConverterClutchAndOverdrivePerformance (the P1740 monitor) after each new ratio sample and "
            "followed by the sum update 0x51ba1c; the monitor then stores the new sample into "
            "protection_pid_rpm_setpoint_prev. Not a PID error: no setpoint or gain is involved. 0 in the dump."
        ),
    ),
    # 7  0x000457d0
    dict(
        new="mpc555_handleCamSignalInterrupt",
        quote="backup_pulse_period_countdown = crank_sync_timing_scale_working;",
        evidence=(
            "Channel 1 is the cam signal: e2m 8194 +56 PMA_Edge_Type 'Capture edge for cam signal' is the byte "
            "crank_mios_channel1_config_cal that mpc555_resetEngineTimingAccumulators ORs into tpu_a_ch1_param2.PARAM0 "
            "(PMM_Edge_Type 8194 +57 'crank signal' is channel 0's). This handler reloads backup_pulse_period_countdown "
            "(819B +A Backup_Lost_Counter) from crank_sync_timing_scale_working, stores the 24-bit period in the ring "
            "(&crank_period_capture_array)[crank_period_capture_index] (819B +4E Pulse_Period_Table_Backup, +3E "
            "Next_Table_Position_Backup) and sums it into crank_tooth_period_raw (+6 Average_Pulse_Period_Backup), reads "
            "crank_period_computed = TPUA_CH3_PARAM2 & 0xff (819B +E Cam_2_Crank_Tooth_Number) against "
            "crank_tooth_pattern_table (Cam_2_Crank_Position_Array) and writes engine_crank_state_t.crank_state, which is "
            "e2m 819C +2 Cam_Sync_State (only 0 / 1 / 4 = NO / LOST / HAVE here; the channel 0 handler walks run_state, "
            "819C +6 Crank_Sync_State, through 2 / 3 = START / PRELIM). crank_event_timebase_a (819B +72 Cam_Have_Sync_Time) "
            "is stored when crank_state is 4. HSRR1 = 1 is a host service request on channel 0 (bits 1:0): "
            "mpc555_resetEngineTimingAccumulators initializes channel 0 with HSRR1 = 3 and channel 1 with 0xc."
        ),
        plate=(
            "TPU-A channel 1 interrupt handler - reached via tpu_a_channel_interrupt_handler_table "
            "(mpc555_tpuAInterruptDispatcher 0x55de4) - no direct caller in the decompile. Channel 1 is the cam signal "
            "input (the TPU PMA function: e2m 8194 +56 PMA_Edge_Type 'Capture edge for cam signal' is "
            "crank_mios_channel1_config_cal, which goes into tpu_a_ch1_param2.PARAM0), so this is the backup engine speed "
            "path, not the crank. Per cam pulse it reloads backup_pulse_period_countdown (e2m 819B +A Backup_Lost_Counter) "
            "from crank_sync_timing_scale_working; with a nonzero tooth count it stores the 24-bit period of "
            "tpu_a_ch1_param2 into the ring crank_period_capture_array (819B +4E Pulse_Period_Table_Backup, index "
            "crank_period_capture_index = +3E Next_Table_Position_Backup) and sums it into crank_tooth_period_raw (+6 "
            "Average_Pulse_Period_Backup) and engine_rpm_state_t.crank_tooth_period_sum / _sample_count (the backup "
            "accumulator +24 and counter +2A). It runs the cam sync state engine_crank_state_t.crank_state (e2m 819C +2 "
            "Cam_Sync_State; here 0 NO / 1 LOST / 4 HAVE, driven by the channel status byte), the pattern machine from "
            "tpu_a_ch1_param2: start_counter (819C +0 Cam_Sync_Error_Count) rises while LOST above "
            "speed_setpoint_minimum and falls while HAVE, and crank_event_timebase_a (819B +72 Cam_Have_Sync_Time) is "
            "stored once at HAVE. It compares the crank tooth number of the cam pulse (crank_period_computed from "
            "TPUA_CH3_PARAM2, 819B +E Cam_2_Crank_Tooth_Number) with crank_tooth_pattern_table (Cam_2_Crank_Position_Array, "
            "2 x cam_wheel_pulse_count entries), counts matches in crank_tooth_count_a / crank_sync_period_counter and "
            "mismatches in crank_sync_timeout_count (819B +10 Cam_Crank_Mismatch_Count), and requests a TPU host service "
            "(tpu_a_mcr.HSRR1 = 1) with crank_resync_time_ticks / crank_tbl_event_counter when the crank bank is out of "
            "phase, then dispatches the run state handlers and the injection timing (engine_injectionTiming_crankSyncDispatch, "
            "cm848_enterSpeedLimpHome)."
        ),
    ),
    # 8  0x00049004
    dict(
        new="cm848_initializeFuelPressureGovernorState",
        quote="engine_sync_state_t_0040b87f.fuel_pressure_governor_mode = FUEL_PRESSURE_GOVERNOR_OPEN_LOOP_START;",
        evidence=(
            "Single caller: the boot list of cm848_applicationMain, between cm848_sensor_diagnostic_flag_update and "
            "cm848_initializeFuelPressureDiagnosticState / cm848_initializeFuelPressureSetpointState, so it is one of "
            "the start-up initializers, not an engine sync reset. It zeroes fuel_metering_command and "
            "fuel_pressure_governor_demand, stores FUEL_PRESSURE_GOVERNOR_OPEN_LOOP_START (the quote), clears the "
            "integrator / derivative states, sets the 17 lookup cache words engine_sync_init_state_a..q to 2, points seven "
            "EMA records at their coefficients (e.g. fuel_pressure_sensor_filter.coefficient = "
            "&fuel_pressure_sensor_filter_coefficient) and presets the coil resistance estimate "
            "(fuel_metering_coil_temperature = sensor_readings_t_0040baf2.coolant_temp). The old plate is kept in full, "
            "including the 0x3fb676 quirk (the fourth store pair repeats 0x3fb66e)."
        ),
        plate=(
            "Initializes (resets) the fuel pressure governor / fuel metering state (cm848_calculateFuelMeteringCommand): "
            "command, demand, governor mode 1, counters, the table interpolation states and filters. Of the four Q16.16 "
            "PID states it clears fuel_pressure_governor_integrator, fuel_metering_feedback_trim_integrator (twice) and "
            "fuel_pressure_governor_derivative_filter; fuel_metering_base_command_derivative_filter (0x3fb676) is never "
            "cleared because the fourth store pair repeats 0x3fb66e. In detail: fuel_metering_command and "
            "fuel_pressure_governor_demand = 0, fuel_pressure_governor_mode and its saved copy = "
            "FUEL_PRESSURE_GOVERNOR_OPEN_LOOP_START, the start revolution / low pressure counters and the feed forward = "
            "0, the 17 table lookup cache words engine_sync_init_state_a..q = 2, the EMA filter records of the fuel metering "
            "feedback / reference / command, the fuel pressure sensor, the accelerator feed forward and the two cam_sync_* "
            "speed filters = accumulator 0 with their coefficient pointers set, fuel_metering_command_filtered = 0, the coil "
            "resistance estimate (e2m 8019) preset from engine_sync_rpm_filter_initial_cal and the coolant temperature, and "
            "the engine_sync_* flags and governor_zero_speed_count = 0. Called once from the boot list of "
            "cm848_applicationMain, before the fuel pressure diagnostic and setpoint state initializers."
        ),
    ),
    # 9  0x00042cfc
    dict(
        new="hpcr_filterCylinderBalanceFueling",
        quote="cylinder_balance_filtered_fueling = final_fueling + (short)iVar1;",
        evidence=(
            "While cbd_enable_flag == 1 or misfire_monitor_speed_buffer_enable_flag == 1: uVar3 = "
            "(cylinder_balance_filtered_fueling - final_fueling) * cbd_fuel_demand_blend_scale_cal, iVar1 = uVar3 >> 13 "
            "(rounded toward 0), filtered = final_fueling + iVar1 clamped to 0..0x1700. That is a first-order low-pass of "
            "final_fueling (e2m 1051 +0) into cylinder_balance_filtered_fueling (e2m 81B0 +0 CBD_Filtered_Fueling) with "
            "the previous value weighted blend / 8192; there is no throttle or load input. Caller: "
            "cm848_periodicTaskSet_controlLoop. The hpcr_ prefix stays (the cylinder balance code is hpcr_cbd*)."
        ),
        plate=(
            "Cylinder balance fueling filter: while the cylinder balance code is enabled (cbd_enable_flag = 1) or the "
            "misfire monitor's speed buffer is enabled (misfire_monitor_speed_buffer_enable_flag = 1) it low-pass filters "
            "final_fueling (e2m 1051 +0 Final_Fueling) into cylinder_balance_filtered_fueling (e2m 81B0 +0 "
            "CBD_Filtered_Fueling): filtered = final_fueling + (previous filtered - final_fueling) x "
            "cbd_fuel_demand_blend_scale_cal / 8192, clamped to 0..5888 (0x1700). That word is the fueling axis of the "
            "cylinder balance tables and the zero-fuel test of hpcr_cbdCalculateCylinderTrims. Runs every pass of "
            "cm848_periodicTaskSet_controlLoop. There is no throttle or load input."
        ),
    ),
    # 10 0x00529ea4
    dict(
        new="cm848_initializeInjectionAngleScheduler",
        quote="TPUA_CH6_PARAM0 = 0x6002;",
        evidence=(
            "Sets injection_angle_sequence_state = 1 and injection_tpu_period_parameter_address = 2 (TPU-A channel 0 "
            "parameter 1 per its row comment), programs TPU-A channel 6 (CFSR2 field 0xf00 = 9, HSRR1 = 0x3000, CIER |= "
            "0x40, TPUA_CH6_PARAM0 = 0x6002 = 0x6000 | that address) and stores "
            "injection_timing_tooth_separation_per_cylinder = injection_timing_tooth_count / cylinder_event_count_max. "
            "Callers: the boot list of cm848_applicationMain and cm848_updateEngineSpeedFromCrankSignal (after "
            "engine_rpm_measured has dropped to 0, following mpc555_resetEngineTimingAccumulators). The row comment of "
            "injection_timing_tooth_separation_per_cylinder already calls this function the scheduler initializer; "
            "channel 6 is the injection scheduling channel (engine_injectionAngle_tpuChannel6EventHandler). Nothing in it "
            "touches a sensor or a diagnostic flag."
        ),
        plate=(
            "Initializes the injection angle scheduler, the TPU-A channel 6 per-cylinder injection event channel "
            "(handled by engine_injectionAngle_tpuChannel6EventHandler): sets injection_angle_sequence_state (e2m 805E +0 "
            "HPCR_Wakeup_Processing_Status_N) to 1 and injection_tpu_period_parameter_address (805E +B HPCR_Period_Address) "
            "to 2 (the primary speed input, TPU-A channel 0 parameter 1 at 0x304102), sets up channel 6 (CFSR2 function "
            "field 9, host service request 3 in HSRR1, channel interrupt enable bit 0x40 in CIER, priority field of CPR1; "
            "TPUA_CH6_PARAM0 = 0x6002 = 0x6000 | the period address) and stores "
            "injection_timing_tooth_separation_per_cylinder (805E +C HPCR_Wakeup_Seperation_In_Increments) = "
            "injection_timing_tooth_count / cylinder_event_count_max (120 / 6 = 20). Called once from the boot list of "
            "cm848_applicationMain and again by cm848_updateEngineSpeedFromCrankSignal after engine_rpm_measured has "
            "dropped to 0, right after mpc555_resetEngineTimingAccumulators."
        ),
    ),
    # 11 0x00029f54
    dict(
        new="cm848_checkPressureSensorAgreement",
        quote="fault_detected_bits_592_to_607 = fault_detected_bits_592_to_607 | 4;",
        evidence=(
            "Compares sensor_readings_t.barometric_pressure with governor_integrator_bound_a (sensor_channel_filtered_output"
            "[77]) and governor_integrator_bound_b ([38]) using barometric_pressure_sensor_tolerance, "
            "boost_pressure_sensor_tolerance and oil_pressure_sensor_tolerance (e2m 165C Ambient_Air / Boost / "
            "Oil_Sensor_Tolerence; the pairing in the code puts [77] with the boost tolerance and [38] with the oil one). "
            "A sensor sets its mask (4 / 8 / 0x10 of fault_detected_bits_592_to_607, faults 594 / 595 / 596 = e2m 1036 +4A "
            "System_Error_Status_37, no DTC slot: fault 594 -> ROM slot table 0x5985a -> slot 170) only when it is more "
            "than own tolerance + the other's away from BOTH others, e.g. (uint)barometric_pressure_sensor_tolerance + "
            "(uint)boost_pressure_sensor_tolerance < (uVar1 & 0xffff) && ... + (uint)oil_pressure_sensor_tolerance < "
            "(uVar2 & 0xffff), and clears it (and the twin bit in j1939_tsc1_mode_shadow) otherwise. It runs once from cm848_processSensorDeviationOnKeyoff after the engine has been stopped for "
            "cold_start_sensor_deviation_delay_cal (e2m 165C +6 Pressure_Check_Delay_Time), so the name says which "
            "sensors and what the verdict is."
        ),
        plate=(
            "Pressure sensor agreement check (e2m 165C: Ambient_Air_Sensor_Tolerence, Boost_Sensor_Tolerence, "
            "Oil_Sensor_Tolerence, Pressure_Check_Delay_Time), run once by cm848_processSensorDeviationOnKeyoff after the "
            "engine has been stopped for cold_start_sensor_deviation_delay_cal while algorithm_enable_flags_6_cal bit 0x20 "
            "is set. It compares three pressure readings, sensor_readings_t.barometric_pressure, "
            "governor_integrator_bound_a (sensor_channel_filtered_output[77], paired with the boost tolerance) and "
            "governor_integrator_bound_b ([38], paired with the oil tolerance), using barometric_pressure_sensor_tolerance, "
            "boost_pressure_sensor_tolerance and oil_pressure_sensor_tolerance. A sensor is flagged when it differs from "
            "both of the other two by more than the sum of its own tolerance and the other sensor's tolerance: mask 4 / 8 / 0x10 "
            "of fault_detected_bits_592_to_607 (faults 594 / 595 / 596, e2m 1036 +4A System_Error_Status_37, no DTC) for "
            "the barometric / first / second sensor. A bit and the same bit of its registered twin j1939_tsc1_mode_shadow "
            "(0x3fea22) are cleared when that sensor agrees with at least one other; all three bits are cleared when one "
            "of the sensor circuit faults the check depends on is set (fault_detected_bits_16_to_31 0x200 / 0x400, "
            "fault_detected_bits_0_to_15 0x100 / 0x200 / 0x1000 / 0x2000). Outputs: those three flag bits."
        ),
    ),
]
