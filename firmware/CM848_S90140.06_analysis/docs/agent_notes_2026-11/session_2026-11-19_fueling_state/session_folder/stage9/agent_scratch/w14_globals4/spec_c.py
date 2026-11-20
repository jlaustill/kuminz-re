"""Comment overrides (shorter final texts); build.py applies them over spec_a / spec_b."""

COMMENTS = {
    "0x003fcff0": (
        "Cruise control top droop gain computed for the low rear axle ratio, the normal path (no e2m record here): "
        "governorCruiseStateMachine turns the cruise top droop width (e2m 1185 +4 Cruise_Top_Droop_Width, 0x3fd912) with "
        "rear_axle_ratio_low_cal into it; governor_cruise_speedReference_update loads it into the working gain at 0x40b6b0 "
        "(e2m 1187 +1A Cruise_Top_Droop_Gain). DAT_003fcff2 is the high-ratio twin (switch 31 with DRIVETRAIN_MANUAL_VSS and "
        "two_speed_axle_enable_cal 1). A droop slope, not a ramp rate."),
    "0x003fcff4": (
        "Road speed governor (RSG) top droop gain computed for the low rear axle ratio, the normal path (no e2m record "
        "here): governorCruiseStateMachine turns road_speed_governor_top_droop_width_cal (e2m 1185 +8 RSG_Top_Droop_Width) "
        "with rear_axle_ratio_low_cal into it; governor_cruise_speedReference_update loads it into "
        "road_speed_governor_top_droop_gain (e2m 1187 +26 RSG_Top_Droop_Gain, 0x40b6bc). DAT_003fcff6 is the high-ratio "
        "twin. A droop slope, not a ramp rate."),
    "0x0040a1a0": (
        "e2m 1921 +C Compressor_Inlet_Press_Source 'Source, DEFAULT or PRIMARY, indicator for Compressor Inlet Pressure' "
        "(UNITLESS): source quality of compressor_inlet_pressure, 0 PRIMARY / 1 BACKUP / 2 DEFAULT. "
        "hpcr_fuelFinal_exponentialAverage takes the barometric pressure selection state when the barometric sensor reads "
        "the compressor inlet (barometric_pressure_sensor_senses_ambient_air_flag_cal clear), else that state combined with "
        "the fresh air flow state; cm848_selectCompressorOutletTemperature reads it."),
    "0x0040a78a": (
        "e2m 10B1 +18 EPF_Shutdown_Override_Flag '[EPSOOVFG] True indicates EPS shutdown override request detected.' "
        "(UNITLESS, byte): the engine protection shutdown override request. governor_derateTrigger_latch_clear sets it from "
        "governor_derate_j1939_trigger_pending (a rising edge of switch 31 while a shutdown is approaching, "
        "j1939_feature_enable_flags_cal bit 0x200); governor_faultDerate_mainLoop_update then sets the running channel timer "
        "back to its start-warning time (raising the e2m +19 lamp flag) and clears this flag every pass. Not a fuel derate "
        "latch."),
    "0x0040a891": (
        "e2m 1053 +A Throttle_Decrease_Flag (mask 0x0001 '1-throttle value decreasing, 0-throttle value increasing') and "
        "Throttle_Transient_Flag (mask 0x0002 'Flag set-throttle in transient situation') (UNITLESS, 2 B): flag word of "
        "the commanded throttle filter, set by cm848_calculateFuelDemandChangeRate: 0x2 when the looked-up filter constant "
        "falls (0x1 too when the commanded throttle is below its filtered value, else 0x1 cleared), 0x2 cleared when the "
        "throttle settles. Not a fuel limit mode."),
    "0x0040bb8a": (
        "sensor_channel_filtered_output[77] (0x40baf0 + 2 x 77; no e2m record here): the second conversion of the boost "
        "(intake manifold) pressure input, 1/18.56 kPa per count: sensor channel 77 (cm848_sensorChannel4_init / _process, "
        "own table sensor_channel77_linearization_*, fault bits 648 / 649 with no DTC) uses the same QADC index as the MAP "
        "channel (value 3 for both in the RAM dump). cm848_checkSensorDeviationFlags compares it as the boost pressure "
        "sensor; cm848_diagnoseTurbochargerSpeedSensorFrequency divides it by the ambient pressure for the pressure ratio."),
    "0x003fddba": (
        "EEPROM 0x938 - e2m 0030 +4 Collector_Stop_Mode 'data collector stop flag' (UNITLESS, signed, 2 B; the e2m range is "
        "0-2 but the code tests 1, 2 and 3; 0 in the dump): data collector stop mode. After the trigger, 1 records half a "
        "buffer more and 2 records to the buffer end (cm848_phase_groupB_calculation); in mode 3 the circular fill stops "
        "when it catches its start and only then does j1939_dm1_diagnosticMessage_send send the buffer by transport "
        "protocol; other values stop at once. Never written by the application."),
    "0x0040b6f6": (
        "e2m 106C +2 User_Filtered_Gear_Ratio 'FILTERED GEAR RATIO USED BY THE SYSTEM -MAY BE FROZEN UPON GEAR SHIFT' "
        "(UNITLESS, 1/2048 per count; 32768 in the dump = 16.0, the stopped default): the filtered drivetrain ratio the "
        "other code reads. protectionTimeoutControl copies the filtered ratio into it only while the ratio is inside its "
        "tolerance window (frozen during a shift); below the minimum vehicle speed or with the engine stopped it is "
        "drivetrain_ratio_default. Not a fuel flow divisor."),
}
for n, (address, desc, off) in enumerate([
        ("0x0040adca", "Torque curve fueling reference idle speed breakpoint.", "40"),
        ("0x0040adcc", "Torque curve fueling reference HSG speed breakpoint.", "42"),
        ("0x0040adce", "1st Torque curve fueling reference between idle and hsg speed breakpoint.", "44"),
        ("0x0040add0", "2nd Torque curve fueling reference between idle and hsg speed breakpoint.", "46"),
        ("0x0040add2", "3rd Torque curve fueling reference between idle and hsg speed breakpoint.", "48")], start=1):
    COMMENTS[address] = (
        f"e2m 1102 +{off} Jcomm_Reference_Fueling_At_Point_{n} '{desc}' (MM3S, 0.0679 per count; 0 in the dump): the "
        f"reference (100 percent torque) fueling at torque curve point {n}: cm848_updateProtectionDiagnostics sets it to "
        f"j1939_reference_engine_fueling (or from the chi maximum fuel at the point speed when "
        f"algorithm_enable_flags_41_cal.reserved_bit_11 is set); cm848_updateProtectionStateMachine divides the point "
        f"fueling by it for the indicated percent torque. Not a speed reference.")

COMMENTS["0x0040a1aa"] = (
    "e2m 107C +0 ASG_Derivative_Term '[ASDV] ASG derivative term' (MM3S, 0.0679 per count, signed; 0 in the dump): the "
    "derivative term of the all-speed governor PID in cm848_runOperatingModeSpeedGovernor: (the derivative adjustment + "
    "error difference x fuel_demand_pid_coeffs[+8] / 4 - feedback difference x fuel_demand_pid_coeffs[+10] / 4) >> 11, "
    "clamped +-0x7fff, then cut by the dead window governor_demand_rate_limit_window and the limit "
    "governor_demand_rate_limit_max; scaled by droop gain 2 it feeds state X4.")
COMMENTS["0x0040a1c4"] = (
    "e2m 107C +1A ASG_QD_Adjustment '[ASQDAJ] ASG Quadratic Derivative Adjustment' (MM3S, 4 B, 0.0000332 per count, "
    "signed; 0 in the dump): the QD adjustment added to the derivative difference equation of "
    "cm848_runOperatingModeSpeedGovernor, (adjustment + error difference x fuel_demand_pid_coeffs[+8] / 4 - feedback "
    "difference x fuel_demand_pid_coeffs[+10] / 4) >> 11; the only store is the zero in cm848_initFuelDemandVariables, so "
    "it stays 0. Not a fuel timing blend or filter accumulator.")
