"""Round 15 stage B (label-only): the LSG leftovers, the 4D fueling maps, the tachometer outputs and checked singles from
the e2m pool above wave 15's 0.2 overlap.
- The tachometer: e2m 116A / 116B, and the output channel tables that e2m 1565 (the channel map, at 0x3fdc94), 151C (the
  duty caches, at 0x40c138) and 1527 (the period caches, at 0x40c198) name entry by entry. They agree with every entry
  round 10 proved by DTCs (1 Fan_Clutch_1, 10 Transmission_VFS, 11 Wastegate_Pressure_Control, 20 CP3_Pump_Regulator, 27
  EVR) and with waves 6 / 7 (39 EGA, 43 VGA). Entries 25 / 26 - todo 035's 'actuators c / d', identity open - are
  Tachometer_Highside_Driver / Tachometer_Lowside_Driver, and the code agrees: their only driver sets period
  tachometer_base_period x 1e6 / engine speed at 50 % duty.
- The 4D fueling maps: e2m 1054-1059 Steady_State / Transient RPM / Throttle axes and tables.
- Singles: each record checked against its code use."""
T = "the tachometer outputs (output channel entries 25 / 26)"
GLOBALS = [
    # the LSG leftovers and the 100 % throttle fueling at its reference
    ("0x003faf50", "low_speed_governor_ran_last_pass_flag",
     "1 after each pass of cm848_runLowSpeedGovernor, 0 while the LSG does not run; a 0 at the start of a pass presets "
     "the integrator"),
    ("0x003faf52", "low_speed_governor_engine_acceleration_previous",
     "engine_acceleration_unfiltered of the previous pass: cm848_runLowSpeedGovernor averages it with the present one"),
    ("0x003faf54", "low_speed_governor_minimum_average_engine_acceleration",
     "The lowest 2-pass average engine acceleration since the last integrator preset (reset to 0 there); "
     "cm848_presetLowSpeedGovernorIntegrator compares it with low_speed_governor_integrator_preset_acceleration_limit "
     "(e2m 1064 +26 'If Unfiltered_Engine_Acceleration < this, use learned integrator')"),
    ("0x003faf4c", "low_speed_governor_reference_maximum_fuel_quantity",
     "The 100 % throttle fueling at low_speed_governor_adjusted_reference_speed from the 4D fueling maps (both lookups "
     "pass 400 = 100 %); e2m 1064 adds its clamp and preset offsets to this '4D fueling at LSG_Adjusted_Reference_Speed'. "
     "Its 105A twins are engine_speed_limit_*_maximum_fuel_quantity"),
    # the 4D fueling maps (e2m 1054-1059)
    ("0x0040688a", "four_dimensional_fueling_steady_state_x_axis",
     "e2m 1055 Steady_State_RPM_Axis_4_D_Fuel: the engine speed axis of the steady-state 4D fueling map"),
    ("0x004068b6", "four_dimensional_fueling_steady_state_y_axis",
     "e2m 1054 Steady_State_Throttle_Axis_4_D_Fuel: the throttle axis"),
    ("0x004068c0", "four_dimensional_fueling_steady_state_grid",
     "e2m 1056 Steady_State_Table_4_D_Fuel: the steady-state fueling by engine speed and throttle"),
    ("0x00406968", "four_dimensional_fueling_transient_x_axis",
     "e2m 1058 Transient_RPM_Axis_4_D_Fuel: the engine speed axis of the transient 4D fueling map"),
    ("0x00406994", "four_dimensional_fueling_transient_y_axis",
     "e2m 1057 Transient_Throttle_Axis_4_D_Fuel: the throttle axis"),
    ("0x0040699e", "four_dimensional_fueling_transient_grid",
     "e2m 1059 Transient_Table_4_D_Fuel: the transient fueling; four_dimensional_fueling_interpolation_factor blends "
     "it with the steady-state map (0 = transient, 0x4000 = steady state)"),
    ("0x0040a8a1", "four_dimensional_fueling_steady_state_cached_axis_offset",
     "Lookup cache of the steady-state 4D fueling map (its x / y offsets: 4 bytes, typed word)"),
    ("0x0040a8a5", "four_dimensional_fueling_transient_cached_axis_offset",
     "Lookup cache of the transient 4D fueling map (4 bytes, typed word)"),
    # the tachometer
    ("0x0040c25e", "tachometer_override_engine_speed",
     "e2m 116B +0 Tachometer_Override_RPM 'RPM value for tach if normal input is overridden': what "
     "cm848_driveTachometerOutputs shows while tachometer_override_mode is 1. Inside the RAM dump gap"),
    ("0x0040c260", "tachometer_override_mode",
     "e2m 116B +2 Tachometer_Override_Mode (1 = override, 0 = no override)"),
    ("0x0040c262", "tachometer_signal_period",
     "e2m 116B +4 Tachometer_Signal_Period: tachometer_base_period x 1000000 / engine speed (microseconds), or "
     "0xffffffff (off); the period of " + T),
    ("0x003fdcc6", "tachometer_highside_driver_output_channel_cal",
     "e2m 1565 +32 Tachometer_Highside_Driver_Map 'mapping index to HW channel': entry 25 of the output channel "
     "assignment table (0 = unassigned in this calibration)"),
    ("0x003fdcc8", "tachometer_lowside_driver_output_channel_cal",
     "e2m 1565 +34 Tachometer_Lowside_Driver_Map: entry 26 (16 = TPU-B 15 in this calibration: the tachometer signal)"),
    ("0x0040c16a", "tachometer_highside_driver_duty_command",
     "e2m 151C +32 Tachometer_Highside_Driver_Duty_Cycle: the last duty sent to entry 25 (0x3200 = 50 % / 0)"),
    ("0x0040c16c", "tachometer_lowside_driver_duty_command",
     "e2m 151C +34 Tachometer_Lowside_Driver_Duty_Cycle: the last duty sent to entry 26"),
    ("0x0040c1fc", "tachometer_highside_driver_period_command",
     "e2m 1527 +64 Tachometer_Highside_Driver_Period: the last period sent to entry 25"),
    ("0x0040c200", "tachometer_lowside_driver_period_command",
     "e2m 1527 +68 Tachometer_Lowside_Driver_Period: the last period sent to entry 26. Inside the RAM dump gap"),
    ("0x003fb9aa", "tachometer_minimum_engine_speed",
     "tachometer_base_period x 0x1312 >> 10, at least tachometer_engine_speed_cutoff (cm848_initializeTachometerOutputs): "
     "a nonzero engine speed below it is shown as it"),
    # singles
    ("0x0040b1ec", "initial_ambient_air_pressure",
     "Taken once after key-on: barometric_pressure x ambient_air_pressure_initial_scaling_factor / 100; the input of "
     "the intake air heater preheat duration table"),
    ("0x003fb224", "initial_ambient_air_pressure_pending_flag",
     "1 until initial_ambient_air_pressure is taken (cm848_processSensorTemperatureData clears it)"),
    ("0x00408f70", "engine_position_sensor_error_detection_minimum_engine_speed",
     "Above this engine speed the crank / cam state machine counts its start events (the error detection runs)"),
    ("0x003feff8", "air_fuel_control_fueling_threshold_1",
     "Above it the AFC fueling slews by AFC_Fueling_Slew_Rate_1 (cm848_calculateAirFuelControlFuelLimit)"),
    ("0x003feffa", "air_fuel_control_fueling_threshold_2",
     "Above it the AFC fueling slews by AFC_Fueling_Slew_Rate_2"),
    ("0x003feffc", "air_fuel_control_fueling_threshold_3",
     "Above it the AFC fueling slews by AFC_Fueling_Slew_Rate_3"),
    ("0x0040ae60", "oil_change_monitor_reset_flag",
     "Set by the J1939 Reset request (PGN 56832, cm848_j1939HandlePgn56832Reset); cm848_updateOilChangeMonitor resets "
     "the oil change monitor and clears it"),
    ("0x0040aeec", "no_load_fuel_quantity",
     "The fuel that overcomes friction at the present speed: the LSG no-load fuel when that is off, and an input of "
     "the torque, load and duty cycle calculations"),
    ("0x0005c398", "zero_torque_fueling",
     "The largest fueling value that injects no fuel (the zero point of the J1939 torque, percent load and friction "
     "calculations)"),
    ("0x003fee7c", "vehicle_speed_sensor_noise_count_cal",
     "Counted by cm848_calculateVehicleSpeed each time a speed spike makes it use the previous sample"),
    ("0x0040b1fa", "output_speed_to_vehicle_speed_ratio_learn_delay_count",
     "Counts the passes of cm848_learnOutputSpeedToVehicleSpeedRatio; above "
     "output_speed_to_vehicle_speed_ratio_learn_delay_limit the learned ratio may update"),
    ("0x0040870a", "output_speed_to_vehicle_speed_ratio_learn_delay_limit",
     "ROM: the pass count output_speed_to_vehicle_speed_ratio_learn_delay_count must pass before the ratio is learned"),
    ("0x0040a3e8", "wastegate_duty_upper_limit_battery_voltage_factor",
     "The battery voltage factor (Q12) that cm848_calculateWastegateDutyRequest applies to the fixed duty ceiling"),
    ("0x00407266", "engine_speed_limit_droop_select_port_type",
     "0 discrete / 1 analog: the kind of input the high speed governor droop select switch uses "
     "(cm848_applySwitchSelectedEngineSpeedLimit); not engine_speed_limit_droop_type_select_cal (0008 +44)"),
    ("0x003fdc8e", "flash_write_failure_flag_cal",
     "Read at boot by cm848_applicationMain: 0 clears internal fault 84 (no DTC slot), else sets it"),
    ("0x003fdfdc", "engine_startup_inhibit_cal",
     "While nonzero cm848_updateEngineState stays in ENGINE_STATE_STOPPED (it never enters CRANKING)"),
]
FUNCTIONS = [
    ("0x00027d38", "cm848_calculateLowSpeedGovernorReferenceMaximumFuelQuantity",
     "low_speed_governor_reference_maximum_fuel_quantity: the steady-state and transient 4D fueling maps (e2m "
     "1054-1059) at low_speed_governor_adjusted_reference_speed and 100 % throttle (400), blended by "
     "four_dimensional_fueling_interpolation_factor (Q14: 0 = transient, 0x4000 = steady state)"),
    ("0x0005586c", "cm848_driveTachometerOutputs",
     "Drives the tachometer outputs (e2m 116A / 116B; output channel entries 25 / 26 = e2m 1565 Tachometer_Highside / "
     "Lowside_Driver_Map): the engine speed (or tachometer_override_engine_speed in override mode 1), raised to "
     "tachometer_minimum_engine_speed when lower and nonzero, gives tachometer_signal_period = tachometer_base_period x "
     "1000000 / speed microseconds at 50 % duty (0x3200); speed 0 (or a base period above 0x10c5) turns them off "
     "(period 0xffffffff, duty 0)"),
    ("0x00055a40", "cm848_initializeTachometerOutputs",
     "Boot initializer of the tachometer outputs: tachometer_minimum_engine_speed = tachometer_base_period x 0x1312 >> "
     "10 (at least tachometer_engine_speed_cutoff); then enables entries 25 / 26 with period 0xffffffff and duty 0"),
]
