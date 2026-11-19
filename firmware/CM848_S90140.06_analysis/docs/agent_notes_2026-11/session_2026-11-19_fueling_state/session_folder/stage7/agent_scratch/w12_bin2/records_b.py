"""Decisions for bin 2 records 34-66 (index = position in bins/bin2.json)."""

B = [
    # 34
    dict(address="0x00408e56", new="cruise_pid_differential_path_minimum", verdict="confirmed", type="i16", eng=(1, "rpm"),
         evidence=("e2m 1189 +0A Cruise_RSG_Diff_Path_Min (RPM, S, 0.006875 per count): protectionOutputActuatorControl "
                   "clamps the differential (speed rate) path value to at least it (the maximum being 0x408e54); lha; "
                   "dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Diff_Path_Min (RPM, S, 0.006875 per count): min limit on the output of the differential "
                  "path in the cc/rsg governor. protectionOutputActuatorControl raises the speed-rate path value to this when "
                  "it falls below (counterpart of 0x408e54). Dump {raw} = {eng}.")),
    # 35
    dict(address="0x00408e58", new="cruise_pid_driveline_filter_coefficient_1", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 1189 +0C Cruise_RSG_Driveline_Filter_C1 (UNITLESS, 1/65536): initCruiseConfirmFlags stores its "
                   "address in PTR_DAT_003fd012 (coefficient 1 of the second-order filter record at 0x3fd012) that "
                   "protectionOutputActuatorControl runs through cm848_secondOrderFilter on the torque-adjusted cruise speed "
                   "error before the Kp / Ki terms; census none, the helper loads it with lhz 0(r12); dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Driveline_Filter_C1 (UNITLESS, 1/65536): 2nd order driveline filter in the cc/rsg "
                  "governor, coefficient 1. initCruiseConfirmFlags stores its address as coefficient pointer 1 of the filter "
                  "record at 0x3fd012, which protectionOutputActuatorControl applies (cm848_secondOrderFilter) to "
                  "governor_cruise_speedError_torqueAdj before the proportional and integral terms; read as an unsigned "
                  "16-bit word. Dump {raw} = {eng}.")),
    # 36
    dict(address="0x00408e5a", new="cruise_pid_driveline_filter_coefficient_3", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 1189 +0E Cruise_RSG_Driveline_Filter_C3 (UNITLESS, 1/65536): initCruiseConfirmFlags stores its "
                   "address in PTR_DAT_003fd016 (coefficient 3 of the same filter record at 0x3fd012); the helper loads it "
                   "with lhz 0(r11); census none; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Driveline_Filter_C3 (UNITLESS, 1/65536): 2nd order driveline filter in the cc/rsg "
                  "governor, coefficient 3. initCruiseConfirmFlags stores its address as coefficient pointer 3 of the filter "
                  "record at 0x3fd012 (see cruise_pid_driveline_filter_coefficient_1); read as an unsigned 16-bit word. "
                  "Dump {raw} = {eng} (the third coefficient is 0 in this calibration).")),
    # 37
    dict(address="0x00408e5c", new="cruise_fuel_demand_ceiling", verdict="confirmed", type="word", eng=(1, "mm3"),
         evidence=("e2m 1189 +10 Cruise_RSG_Fueling_Clamp_Max (MM3S, 0.0679 mm3 per count): protectionRampRateControl points "
                   "cruise_speed_upper_limit_ptr (0x3fd038, a fuel limit despite its name) at it, or at "
                   "cruise_speed_blend_working (e2m 117F Current_HP_Peak_Fueling) when programmable power is enabled; "
                   "protectionOutputActuatorControl clamps the PID integrator and governor_fuel_demand_value to it; "
                   "lha 0(r31) at 0x52547c, census none; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Fueling_Clamp_Max (MM3S, 0.0679 mm3 per count): CC/RSG fueling clamp max. "
                  "protectionRampRateControl points cruise_speed_upper_limit_ptr (a fuel limit, not a speed) at it, or at "
                  "cruise_speed_blend_working when programmable power is enabled; protectionOutputActuatorControl clamps the "
                  "PID integrator and governor_fuel_demand_value to it (floor: cruise_fuel_demand_floor). 16-bit loads. "
                  "Dump {raw} = {eng}.")),
    # 38
    dict(address="0x00408e60", new="cruise_pid_rate_gain_scale_multiplier", verdict="confirmed", type="word", eng=(2, ""),
         evidence=("e2m 1189 +14 Cruise_RSG_Gain_Mult (UNITLESS, 1/1024): cm848_calculateCruisePidRateGainScale multiplies "
                   "its scale chain by it and shifts right by 10 to form cruise_pid_rate_gain_scale (capped at 0x408e6a); "
                   "lhz; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Gain_Mult [cruise control loop gain multiplier] (UNITLESS, 1/1024 per count): "
                  "cm848_calculateCruisePidRateGainScale: cruise_pid_rate_gain_scale = (((protection_timing_period_cal x "
                  "protection_temp_scale_factor / 60) x 100 >> 7) x this >> 10), capped at 0x408e6a; the scale multiplies the "
                  "cruise speed error and rate terms. Dump {raw} = {eng}.")),
    # 39
    dict(address="0x00408e62", new="cruise_pid_integral_adjustment_gain", verdict="confirmed", type="i16", eng=(3, ""),
         evidence=("e2m 1189 +16 Cruise_RSG_Integral_Adj_Gain (1/SEC, S, 1/32768 per count): protectionOutputActuatorControl "
                   "multiplies (fuel_demand_computed - cruise_fuel_demand_prev) by it x 2, limits the product to +-0x6e66666 "
                   "and adds it to the Q16 integrator _cruise_pid_integrator_q16; lha; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Integral_Adj_Gain [the integral adjustment gain of the cruise / RSG] (1/SEC, S, 1/32768 "
                  "per count): protectionOutputActuatorControl adds (fuel_demand_computed - cruise_fuel_demand_prev) x this x "
                  "2 (limited to +-0x6e66666) to the Q16 integrator _cruise_pid_integrator_q16, so the integrator follows the "
                  "fueling actually applied. Dump {raw} = {eng}.")),
    # 40
    dict(address="0x00408e6a", new="cruise_pid_rate_gain_scale_upper_limit", verdict="confirmed", type="word", eng=(2, ""),
         evidence=("e2m 1189 +1E Tool_UL_Cruise_RSG_Gain (UNITLESS, 0.01 per count): cm848_calculateCruisePidRateGainScale "
                   "caps cruise_pid_rate_gain_scale at it; lhz; dump {raw} ({eng})"),
         comment=("e2m Tool_UL_Cruise_RSG_Gain [tool maximum acceptable Cruise_RSG_Gain value] (UNITLESS, 0.01 per count, "
                  "1..294): upper limit of the service tool's cruise gain; cm848_calculateCruisePidRateGainScale applies it as "
                  "the cap of cruise_pid_rate_gain_scale. Dump {raw} = {eng}.")),
    # 41
    dict(address="0x00408e6c", new="vehicle_speed_limit_integrator_preset_fuel_offset", verdict="confirmed", type="word",
         eng=(1, "mm3"),
         evidence=("e2m 1189 +20 Cruise_RSG_RSG_Reset_Fuel_Offset (MM3S, S, 0.0679 mm3 per count): protectionRampRateControl, "
                   "in governor_fuel_demand_mode 10 (FUELING_STATE_VEHICLE_SPEED_LIMIT), presets the integrator from "
                   "fuel_demand_computed - it; lhz although the record is signed (a 16-bit subtract, so word); "
                   "dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_RSG_Reset_Fuel_Offset (MM3S, S, 0.0679 mm3 per count): adjustment to the RSG integrator "
                  "preset fuel calculation. protectionRampRateControl: in governor_fuel_demand_mode 10 (vehicle speed limit = "
                  "RSG) the PID integrator is preset from fuel_demand_computed - this offset. Loaded with lhz although the "
                  "record is signed. Dump {raw} = {eng}.")),
    # 42
    dict(address="0x00408e72", new="cruise_stable_speed_acceleration_threshold", verdict="confirmed", type="word",
         eng=(2, "mph"),
         evidence=("e2m 1189 +26 Cruise_RSG_Preset_Fueling_Thres_Accel (MPH, 0.0977 per count): protectionOutputActuatorControl "
                   "re-arms cruise_stable_speed_countdown (cruise_stable_speed_countdown_initial) when the clamped speed "
                   "change per pass is above it or below its negative; lha although the record is unsigned (max 5, so "
                   "word); dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Preset_Fueling_Thres_Accel [accel. threshold used in cruise preset fueling calculation] "
                  "(MPH, 0.0977 per count): protectionOutputActuatorControl re-arms cruise_stable_speed_countdown whenever the "
                  "speed change per pass is outside +-this, so the preset fueling reference is taken only at stable speed. "
                  "Loaded with lha although the record is unsigned. Dump {raw} = {eng}.")),
    # 43
    dict(address="0x00408e76", new="cruise_rate_correction_initial_fuel_gain", verdict="confirmed", type="i16", eng=None,
         evidence=("e2m 1189 +2A Cruise_RSG_Sump_Fuel_Init_Gain (MM3S, S, 0.696 per count): protectionOutputActuatorControl "
                   "sets cruise_speed_rate_term = it x speed change per pass (clamped +-0xb80) when "
                   "cruise_rate_correction_trigger_flag fires, takes it out of the integrator and makes it "
                   "governor_cruise_fuel_demand_delta; lha; dump {raw}"),
         comment=("e2m Cruise_RSG_Sump_Fuel_Init_Gain [this gain multiplied by differential_error determines sump_fuel] "
                  "(MM3S, S, 0.696 per count): protectionOutputActuatorControl: when cruise_rate_correction_trigger_flag "
                  "fires, cruise_speed_rate_term = this x (speed change per pass), clamped to +-0xb80, is taken out of the "
                  "integrator and becomes governor_cruise_fuel_demand_delta. Dump {raw} (correction off).")),
    # 44
    dict(address="0x00408e80", new="cruise_rate_correction_threshold_gain", verdict="confirmed", type="i16", eng=(2, ""),
         evidence=("e2m 1189 +34 Cruise_RSG_Sump_Thres_Gain (1/SEC, S, 1/32 per count): protectionOutputActuatorControl: rate "
                   "correction trigger metric DAT_003fd057 = (speed change << 5) - it x governor_cruise_speed_error_net / 25, "
                   "compared with Sump_Thres_Accel (0x408e7c); lha; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Sump_Thres_Gain [gain used in cruise sump activation equation] (1/SEC, S, 1/32 per count): "
                  "protectionOutputActuatorControl computes the rate correction trigger metric (DAT_003fd057) = (speed change "
                  "per pass << 5) - this x governor_cruise_speed_error_net / 25 and triggers when it exceeds 0x408e7c while "
                  "the error is below 0x408e7e. Dump {raw} = {eng}.")),
    # 45
    dict(address="0x00408e82", new="governor_cruise_fuel_demand_delta_decrement_rate", verdict="confirmed", type="word",
         eng=(1, "mm3/s"),
         evidence=("e2m 1189 +36 Cruise_RSG_Sump_Decrement_Rate (MM3S/SEC, 1.698 per count): protectionOutputActuatorControl "
                   "lowers a positive governor_cruise_fuel_demand_delta by it per pass (to 0 when it is smaller); lha "
                   "although the record is unsigned; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Sump_Decrement_Rate [Cruise RSG sump decrement ramp rate] (MM3S/SEC, 1.698 per count): "
                  "protectionOutputActuatorControl ramps a positive governor_cruise_fuel_demand_delta (the one-shot rate "
                  "correction fuel) toward 0 by this per pass and sets it to 0 when smaller. Loaded with lha although the "
                  "record is unsigned. Dump {raw} = {eng} (e2m scale).")),
    # 46
    dict(address="0x00408e84", new="governor_cruise_fuel_demand_delta_increment_rate", verdict="confirmed", type="word",
         eng=(1, "mm3/s"),
         evidence=("e2m 1189 +38 Cruise_RSG_Sump_Increment_Rate (MM3S/SEC, 1.698 per count): protectionOutputActuatorControl "
                   "raises a negative governor_cruise_fuel_demand_delta by it per pass (to 0 when within it); lha although "
                   "the record is unsigned; dump {raw} ({eng})"),
         comment=("e2m Cruise_RSG_Sump_Increment_Rate [Cruise RSG sump increment ramp rate] (MM3S/SEC, 1.698 per count): "
                  "protectionOutputActuatorControl ramps a negative governor_cruise_fuel_demand_delta toward 0 by this per "
                  "pass and sets it to 0 when within it. Loaded with lha although the record is unsigned. "
                  "Dump {raw} = {eng} (e2m scale).")),
    # 47
    dict(address="0x0005c2f6", new="fault_derate_curve_low_speed_governor_intercept_fueling", verdict="confirmed",
         type="word", eng=(1, "mm3"),
         evidence=("e2m 12BA +00 EPF_Curve_LSG_Intercept_Fueling (MM3S, 0.0679 mm3 per count): "
                   "governor_calculateIntegratorRpmOutput lowers the first fault derate curve speed "
                   "(governor_integrator_rpm_output) from the idle reference speed by governor_integrator_correction_term x it "
                   "/ 167 while the low speed governor droop is enabled; lhz; dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_LSG_Intercept_Fueling [EPLSINFL] (MM3S, 0.0679 mm3 per count): intercept fueling between the "
                  "LSG reference and the EPF (fault derate) curve. governor_calculateIntegratorRpmOutput: curve point 1 speed "
                  "= idle_reference_speed - governor_integrator_correction_term x this / 167 while the low speed governor "
                  "droop is enabled. Dump {raw} = {eng}.")),
    # 48
    dict(address="0x0005c2f8", new="fault_derate_curve_high_speed_governor_intercept_fueling", verdict="confirmed",
         type="word", eng=(1, "mm3"),
         evidence=("e2m 12BA +02 EPF_Curve_HSG_Intercept_Fueling (MM3S, 0.0679 mm3 per count): "
                   "governor_calculateIntegratorRpmOutput computes curve point 2 as "
                   "(engine_speed_limit_ramped_maximum_fuel_quantity - it) x engine_speed_limit_droop_slope / 4369 + "
                   "lowest_source_speed_limit when the limiting engine speed source is 1, 2, 4, 5 or 12; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_HSG_Intercept_Fueling [EPHSINFL] (MM3S, 0.0679 mm3 per count): intercept fueling between the "
                  "HSG breakpoint and the EPF (fault derate) curve. governor_calculateIntegratorRpmOutput: curve point 2 speed "
                  "= (engine_speed_limit_ramped_maximum_fuel_quantity - this) x engine_speed_limit_droop_slope / 4369 + "
                  "lowest_source_speed_limit when the limiting source number is 1, 2, 4, 5 or 12. Dump {raw} = {eng}.")),
    # 49
    dict(address="0x0005c2fa", new="fault_derate_curve_engine_speed_point_2", verdict="confirmed", type="word",
         eng=(0, "rpm"),
         evidence=("e2m 12BA +04 EPF_Curve_RPM_At_Point_2 (RPM, 0.125 rpm per count): governor_calculateIntegratorRpmOutput "
                   "stores it as the curve point 2 speed (protection_recovery_threshold_cal) when the limiting engine speed "
                   "source number is none of 1, 2, 4, 5, 12; engine_protection_derateParam_priorityApply looks that speed up in "
                   "fault_derate_fuel_limit_by_engine_speed_*; lhz; dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_RPM_At_Point_2 [EPRPP2] (RPM, 0.125 rpm per count): EPF (fault derate) curve speed at "
                  "breakpoint 2. governor_calculateIntegratorRpmOutput stores it in protection_recovery_threshold_cal (point 2 "
                  "speed, otherwise the computed HSG intercept speed); engine_protection_derateParam_priorityApply looks the "
                  "speed up in fault_derate_fuel_limit_by_engine_speed_*. Dump {raw} = {eng}.")),
    # 50
    dict(address="0x0005c2fc", new="fault_derate_curve_engine_speed_point_3", verdict="confirmed", type="word",
         eng=(0, "rpm"),
         evidence=("e2m 12BA +06 EPF_Curve_RPM_At_Point_3 (RPM, 0.125 rpm per count): governor_calculateIntegratorRpmOutput "
                   "stores it as the curve point 3 speed (protection_threshold_lookup_rpm); "
                   "engine_protection_derateParam_priorityApply looks it up in fault_derate_fuel_limit_by_engine_speed_*; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_RPM_At_Point_3 [EPRPP3] (RPM, 0.125 rpm per count): EPF (fault derate) curve speed at "
                  "breakpoint 3. governor_calculateIntegratorRpmOutput stores it in protection_threshold_lookup_rpm; "
                  "engine_protection_derateParam_priorityApply looks the speed up in fault_derate_fuel_limit_by_engine_speed_*. "
                  "Dump {raw} = {eng}.")),
    # 51
    dict(address="0x0005c2fe", new="fault_derate_curve_engine_speed_point_4", verdict="confirmed", type="word",
         eng=(0, "rpm"),
         evidence=("e2m 12BA +08 EPF_Curve_RPM_At_Point_4 (RPM, 0.125 rpm per count): governor_calculateIntegratorRpmOutput "
                   "stores it as the curve point 4 speed (protection_threshold_scale_working); "
                   "engine_protection_derateParam_priorityApply looks it up in fault_derate_fuel_limit_by_engine_speed_*; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_RPM_At_Point_4 [EPRPP4] (RPM, 0.125 rpm per count): EPF (fault derate) curve speed at "
                  "breakpoint 4. governor_calculateIntegratorRpmOutput stores it in protection_threshold_scale_working; "
                  "engine_protection_derateParam_priorityApply looks the speed up in fault_derate_fuel_limit_by_engine_speed_*. "
                  "Dump {raw} = {eng}.")),
    # 52
    dict(address="0x0005c300", new="fault_derate_curve_engine_speed_point_5", verdict="confirmed", type="word",
         eng=(0, "rpm"),
         evidence=("e2m 12BA +0A EPF_Curve_RPM_At_Point_5 (RPM, 0.125 rpm per count): governor_calculateIntegratorRpmOutput "
                   "stores it as the curve point 5 speed (protection_base_threshold_working); "
                   "engine_protection_derateParam_priorityApply looks it up in fault_derate_fuel_limit_by_engine_speed_*; lhz; "
                   "dump {raw} ({eng})"),
         comment=("e2m EPF_Curve_RPM_At_Point_5 [EPRPP5] (RPM, 0.125 rpm per count): EPF (fault derate) curve speed at "
                  "breakpoint 5. governor_calculateIntegratorRpmOutput stores it in protection_base_threshold_working; "
                  "engine_protection_derateParam_priorityApply looks the speed up in fault_derate_fuel_limit_by_engine_speed_*. "
                  "Dump {raw} = {eng}.")),
    # 53
    dict(address="0x0005c302", new="fault_derate_curve_priority_bit_position", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 12BA +0C EPF_Torque_Curve_Priority (UNITLESS, 0..15): fault_initBitwiseTimerMask sets "
                   "governor_faultDerate_channel_bit = 1 << (it & 0x3f), the priority bit this curve uses in "
                   "protection_mode_request_flags (governor_calculateIntegratorRpmOutput); lhz; dump {raw} (bit 0x8000)"),
         comment=("e2m EPF_Torque_Curve_Priority [EPTQPZ] (UNITLESS, 0..15): priority level of the EPF (fault derate) curve "
                  "configuration and bit position used. fault_initBitwiseTimerMask: governor_faultDerate_channel_bit = 1 << "
                  "this; governor_calculateIntegratorRpmOutput ORs that bit into protection_mode_request_flags and only a "
                  "request with no higher priority bit set rewrites the curve points. Dump {raw} = bit 0x8000.")),
    # 54
    dict(address="0x0005c304", new="fault_derate_curve_clamp_priority_mask", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 12BA +0E EPF_Torque_Curve_Min_Config (HEX, 0..65535): engine_protection_derateParam_priorityApply "
                   "tests it against cm848_getHighestPriorityBit(): a set bit min-merges the five curve fuelings (looked up from "
                   "the point speeds) into the working curve, a clear bit lets a request with no higher priority overwrite it; "
                   "lhz; dump {raw} (0x8000 = bit 15 only)"),
         comment=("e2m EPF_Torque_Curve_Min_Config [EPTQCG] (HEX): bitmap indicating when a feature should CLAMP a fueling "
                  "point. engine_protection_derateParam_priorityApply: if the highest priority bit "
                  "(cm848_getHighestPriorityBit) is set in this mask the five curve fuelings are min-merged into the working "
                  "curve (protection_cal_level1_working ...), otherwise the curve is overwritten. Dump 0x8000 = bit 15 "
                  "only.")),
    # 55
    dict(address="0x0040afb6", new="engine_friction_torque", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 175C +00 Friction_Torque (FT*LB, S, 0.5 per count): cm848_applyProtectionRpmCorrectionFilter stores "
                   "(grid torque of Coolant_Fuel_Adjustment at the engine speed, +08) - Zero_Fuel_Torque (+02) and adds the "
                   "pumping torque adjustment to it for No_Load_Torque (+04); write-only (sth, no read in the binary); the +08 "
                   "(torque of e2m 109C Coolant_Fuel_Adjustment) and +0A (net_combustion_torque_copy) anchors match the "
                   "block; dump {raw} (the torque grid is all zero, so the dump proves nothing)"),
         comment=("e2m Friction_Torque (FT*LB, S, 0.5 per count): friction torque. cm848_applyProtectionRpmCorrectionFilter: "
                  "(grid torque of the coolant friction fuel adjustment 0x40aef0) - engine_zero_fuel_base_friction_torque; adding "
                  "the pumping torque adjustment 0x40a41a gives engine_no_load_torque. Write-only (sth); the sign of the "
                  "composition is untestable, the torque grid is all zero. Dump {raw}.")),
    # 56
    dict(address="0x0040afb8", new="engine_zero_fuel_base_friction_torque", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 175C +02 Zero_Fuel_Torque (FT*LB, S, 0.5 per count): cm848_applyProtectionRpmCorrectionFilter stores "
                   "the combustion_torque_by_fuel_quantity grid torque at the engine speed for Friction_Fueling (0x40aef2, "
                   "e2m 109C, the friction fuel before the coolant adjustment); write-only (sth); the +08 / +0A anchors match; "
                   "dump {raw} (grid all zero)"),
         comment=("e2m Zero_Fuel_Torque (FT*LB, S, 0.5 per count): base friction torque at zero fueling at the current speed "
                  "(before the cold engine adjustment). cm848_applyProtectionRpmCorrectionFilter: the torque the combustion "
                  "torque grid gives for Friction_Fueling (0x40aef2) at the engine speed. Write-only (sth). Dump {raw} (grid "
                  "all zero).")),
    # 57
    dict(address="0x0040afba", new="engine_no_load_torque", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 175C +04 No_Load_Torque (FT*LB, S, 0.5 per count): cm848_applyProtectionRpmCorrectionFilter stores "
                   "Friction_Torque (+00) + fuel_demand_blend_adjusted (0x40a41a = e2m 1781 CHP_Pumping_Torque_Adj, the pumping "
                   "torque cm848_calculateNetCombustionTorque subtracts); write-only (sth); dump {raw} (grid all zero)"),
         comment=("e2m No_Load_Torque (FT*LB, S, 0.5 per count): engine no load torque. "
                  "cm848_applyProtectionRpmCorrectionFilter: engine_friction_torque + fuel_demand_blend_adjusted (e2m 1781 "
                  "CHP_Pumping_Torque_Adj, 0x40a41a), i.e. friction plus pumping torque. Write-only (sth). Dump {raw} (the "
                  "torque grid is all zero).")),
    # 58
    dict(address="0x0040afbc", new="net_machine_torque", verdict="confirmed", type="word", eng=None,
         evidence=("e2m 175C +06 Net_Machine_Torque (FT*LB, S, 0.5 per count): cm848_applyProtectionRpmCorrectionFilter stores "
                   "net_combustion_torque_copy (+0A) minus the grid torque of the accessory load fuels (A/C 0x40aef4 + fan "
                   "0x40aef6, e2m 109C, + alternator load 0x40aeb0, e2m 1065 Alternator_Load; floored at 0); write-only (sth); "
                   "dump {raw} (grid all zero)"),
         comment=("e2m Net_Machine_Torque (FT*LB, S, 0.5 per count): net machine torque, actual torque corresponding to "
                  "Ndot_Net_Torque_Cmd. cm848_applyProtectionRpmCorrectionFilter: net_combustion_torque_copy - the grid torque "
                  "of the accessory fuels (A/C, fan, alternator load). Write-only (sth). Dump {raw} (the torque grid is all "
                  "zero).")),
    # 59
    dict(address="0x00406000", new="injection_quantity_oxygen_limit_override_value", verdict="confirmed", type="word",
         eng=(1, "mm3"),
         evidence=("e2m 1791 +00 C_OFC_Fuel_Limit_Override_Value (MM3S, 0.0679 mm3 per count): cm848_calculateOxygenFuelLimit "
                   "replaces injection_quantity_oxygen_limit with it when combustion_override_and_estimation_enable_flags_cal "
                   "bit 0x1000 is set; lhz; dump {raw} ({eng}, the no-limit full scale)"),
         comment=("e2m C_OFC_Fuel_Limit_Override_Value (MM3S, 0.0679 mm3 per count): override value for the OFC fuel limit. "
                  "cm848_calculateOxygenFuelLimit replaces injection_quantity_oxygen_limit with it when "
                  "combustion_override_and_estimation_enable_flags_cal bit 0x1000 is set (then clamped by the maximum / "
                  "minimum rows). Dump {raw} = {eng} (the no-limit full scale).")),
    # 60
    dict(address="0x00406002", new="oxygen_limit_equivalence_ratio_override_value", verdict="confirmed", type="word",
         eng=(2, ""),
         evidence=("e2m 1791 +02 C_OFC_Equiv_Ratio_Value (UNITLESS, 1/128): cm848_calculateOxygenFuelLimit replaces "
                   "oxygen_limit_equivalence_ratio with it when combustion_override_and_estimation_enable_flags_cal bit 0x800 "
                   "is set; lhz; dump {raw} ({eng})"),
         comment=("e2m C_OFC_Equiv_Ratio_Value (UNITLESS, 1/128 per count, 0..15): OFC equivalence ratio user override value. "
                  "cm848_calculateOxygenFuelLimit replaces oxygen_limit_equivalence_ratio (normally the engine speed x "
                  "total_injection_quantity_for_air_handling table) with it when "
                  "combustion_override_and_estimation_enable_flags_cal bit 0x800 is set. Dump {raw} = {eng}.")),
    # 61
    dict(address="0x00406006", new="injection_quantity_oxygen_limit_gain_adjustment", verdict="confirmed", type="word",
         eng=(1, ""),
         evidence=("e2m 1791 +06 C_OFC_Gain_Adjustment (UNITLESS, 1/2048): cm848_calculateOxygenFuelLimit multiplies the "
                   "barometric pressure gain lookup (>> 11) by it before the equivalence ratio x cylinder_total_oxygen_mass / "
                   "(stoichiometric ratio 0x406004 << 11); lhz; dump {raw} ({eng})"),
         comment=("e2m C_OFC_Gain_Adjustment (UNITLESS, 1/2048 per count, 0..20): multiplier used to adjust the OFC fuel limit. "
                  "cm848_calculateOxygenFuelLimit: (this x barometric pressure gain >> 11) x equivalence ratio x "
                  "cylinder_total_oxygen_mass x 2 / (stoichiometric ratio << 11). Dump {raw} = {eng} (the maximum of the "
                  "range).")),
    # 62
    dict(address="0x00406752", new="egr_valve_position_autozero_filter_coefficient", verdict="confirmed", type="word",
         eng=(4, ""),
         evidence=("e2m 179C +04 C_EGR_Position_AZ_Fil_Cnst (UNITLESS, 1/65536): cm848_initializeEgrValvePosition stores its "
                   "address in PTR_DAT_003fbcbe, the coefficient pointer of the filter state that "
                   "cm848_updateEgrValvePositionAutozero hands to cm848_updateAutozeroOffset (PTR_PTR_003fbcde) for the "
                   "position samples; the filter helper loads it with lhz 0(r12); census none; dump {raw} ({eng})"),
         comment=("e2m C_EGR_Position_AZ_Fil_Cnst (UNITLESS, 1/65536 per count): filter constant for filtering EGR position "
                  "samples for the zero offset calculation. cm848_initializeEgrValvePosition stores its address as the "
                  "coefficient pointer of the autozero filter state (0x3fbcbe) that cm848_updateAutozeroOffset uses; read as "
                  "an unsigned 16-bit word. Dump {raw} = {eng}.")),
    # 63
    dict(address="0x003ff078", new="ambient_air_temperature_override_value", verdict="confirmed", type="i16",
         eng=(1, "F"),
         evidence=("e2m 1977 +04 C_AMB_Amb_Tmptr_Override_Value (DEG_F, S, 1/64 F per count): "
                   "hpcr_fuelFinal_exponentialAverage takes it as the ambient temperature result (boost_fuel_demand_blend_a) "
                   "while the user override trim word 0x3fd51a (e2m 197E T_AMB_Amb_Tmptr_User_Override) is non-zero; lha; "
                   "dump {raw} ({eng})"),
         comment=("e2m C_AMB_Amb_Tmptr_Override_Value (DEG_F, S, 1/64 F per count): ambient temperature user override value. "
                  "hpcr_fuelFinal_exponentialAverage uses it as the ambient temperature result (boost_fuel_demand_blend_a) "
                  "while the user override enable trim 0x3fd51a (e2m 197E T_AMB_Amb_Tmptr_User_Override) is non-zero. "
                  "Dump {raw} = {eng}.")),
    # 64
    dict(address="0x003ff07c", new="ambient_air_temperature_default_value", verdict="confirmed", type="i16",
         eng=(1, "F"),
         evidence=("e2m 1977 +08 C_AMB_Ambient_Air_Tmptr_Default (DEG_F, S, 1/64 F per count): "
                   "hpcr_fuelFinal_exponentialAverage takes it as the ambient temperature result when "
                   "fuel_demand_timing_mode_state is 2 (source DEFAULT) and no user override is set; lha; "
                   "dump {raw} ({eng})"),
         comment=("e2m C_AMB_Ambient_Air_Tmptr_Default (DEG_F, S, 1/64 F per count): ambient air temperature default value to "
                  "be used when the source is DEFAULT. hpcr_fuelFinal_exponentialAverage selects it when "
                  "fuel_demand_timing_mode_state is 2 (sensor source defaulted) instead of the filtered measurement. "
                  "Dump {raw} = {eng}.")),
    # 65
    dict(address="0x00409ebe", new="egr_orifice_temperature_rationality_startup_wait_time", verdict="confirmed",
         type="word", eng=(1, "s"),
         evidence=("e2m 1A53 +12 EGR_Orifice_Temp_Wait_Time (SEC, 0.1 s per count): "
                   "cm848_initializeEgrOrificeTemperatureSensorRationalityMonitor loads the byte counter "
                   "egr_orifice_temperature_rationality_startup_delay_count from it (lhz, stb); dump {raw} ({eng})"),
         comment=("e2m EGR_Orifice_Temp_Wait_Time (SEC, 0.1 s per count): time for the A/D to stabilize after key on before "
                  "running the monitor. cm848_initializeEgrOrificeTemperatureSensorRationalityMonitor loads "
                  "egr_orifice_temperature_rationality_startup_delay_count with it (byte store of the halfword). "
                  "Dump {raw} = {eng}.")),
    # 66
    dict(address="0x0005b336", new="intake_air_heater_crank_temperature_threshold", verdict="confirmed", type="i16",
         eng=(1, "F"),
         evidence=("e2m 8A41 +00 IAH_Crank_Temp (DEG_F, S, 1/64 F per count): cm848_updateIntakeAirHeaterRunupPhase runs its "
                   "relay logic only while the signed intake_air_heater_start_temperature (intake manifold temperature at "
                   "start, 1/64 F) is at or below it; lha; dump {raw} ({eng})"),
         comment=("e2m IAH_Crank_Temp (DEG_F, S, 1/64 F per count): if the intake manifold temperature is below this value, "
                  "enables the heaters during crank. cm848_updateIntakeAirHeaterRunupPhase runs the run-up relay logic only "
                  "while intake_air_heater_start_temperature <= this. Dump {raw} = {eng}.")),
]
