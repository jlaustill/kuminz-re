from records_a import A
from records_b import B

RECORDS = A + B

# comments tightened to the 400 character clip of the apply scripts
COMMENT_OVERRIDES = {
    0: ("e2m Fault_Countdown_Elapsed_Time_Mode_0 [DG00ELTM] (HR, 0.2 s per count): no countdown shall occur for a mode 0 "
        "fault. Entry 0 of the 4 mode x 2 dword table at 0x5983a: cm848_faultTimeoutHandler indexes it by "
        "(aging_flags & 3) * 8 and compares key_on_hour_meter - timestamp with the elapsed time; mode 0 is skipped before "
        "the read. Same address as e2m 000F Fault_Data. Dump {raw}."),
    2: ("e2m Maximum_Confidence_Count [CTMXCBCU] (MSEC, 100 ms per count): time to delay before setting a new Throttle_Min "
        "(the learned pedal minimum, fuel_demand_control_t.throttle_based). cm848_fuelDemandOverrideHandler starts the "
        "counter rate_delta with it when the pedal reads below the minimum, counts it down while the reading stays in "
        "the confidence band, accepts the new minimum at 0. Dump {raw} = 0.8 s."),
    25: ("e2m Fuel_Temperature_RPM_Index [EPFTRPIX] (UNITLESS, 1/256, 0..1): fuel temperature RPM severity index. Word 1 of "
         "the per-channel record at 0x3fdfbe (stride 30, word 0 = fueling index): "
         "cm848_calculateFaultDerateEngineSpeedLimit stores the channel's derate ramp (0..256) here; "
         "governor_faultDerate_mainLoop_update clears the active channel when both indexes are 0. EEPROM mirror (_cal). "
         "Dump {raw}."),
    31: ("e2m Cruise_RSG_Derivative_Filter_C1 (UNITLESS, 1/65536): 2nd order derivative filter in the cc/rsg governor, "
         "coefficient 1. initCruiseConfirmFlags stores its address as coefficient pointer 1 of the filter record at 0x3fd022 "
         "that protectionOutputActuatorControl runs on vehicle_speed_rise_limited (the speed change per pass feeds the "
         "differential path); 16-bit unsigned. Dump {raw} = {eng}."),
    35: ("e2m Cruise_RSG_Driveline_Filter_C1 (UNITLESS, 1/65536): 2nd order driveline filter in the cc/rsg governor, "
         "coefficient 1. initCruiseConfirmFlags stores its address as coefficient pointer 1 of the filter record at 0x3fd012; "
         "protectionOutputActuatorControl applies it (cm848_secondOrderFilter) to governor_cruise_speedError_torqueAdj before "
         "the P and I terms; 16-bit unsigned. Dump {raw} = {eng}."),
    37: ("e2m Cruise_RSG_Fueling_Clamp_Max (MM3S, 0.0679 mm3 per count): CC/RSG fueling clamp max. "
         "protectionRampRateControl points cruise_speed_upper_limit_ptr (a fuel limit, not a speed) at it, or at "
         "cruise_speed_blend_working with programmable power; protectionOutputActuatorControl clamps the PID integrator and "
         "governor_fuel_demand_value to it (floor: cruise_fuel_demand_floor). Dump {raw} = {eng}."),
    48: ("e2m EPF_Curve_HSG_Intercept_Fueling [EPHSINFL] (MM3S, 0.0679 mm3 per count): intercept fueling between the HSG "
         "breakpoint and the EPF (fault derate) curve. governor_calculateIntegratorRpmOutput: point 2 speed = "
         "(engine_speed_limit_ramped_maximum_fuel_quantity - this) x engine_speed_limit_droop_slope / 4369 + "
         "lowest_source_speed_limit for limiting sources 1, 2, 4, 5, 12. Dump {raw} = {eng}."),
    53: ("e2m EPF_Torque_Curve_Priority [EPTQPZ] (UNITLESS, 0..15): priority level of the EPF (fault derate) curve "
         "configuration and bit position used. fault_initBitwiseTimerMask: governor_faultDerate_channel_bit = 1 << this; "
         "governor_calculateIntegratorRpmOutput ORs it into protection_mode_request_flags and rewrites the curve points only "
         "when no higher priority bit is set. Dump {raw} = bit 0x8000."),
}
for _index, _text in COMMENT_OVERRIDES.items():
    RECORDS[_index]["comment"] = _text
