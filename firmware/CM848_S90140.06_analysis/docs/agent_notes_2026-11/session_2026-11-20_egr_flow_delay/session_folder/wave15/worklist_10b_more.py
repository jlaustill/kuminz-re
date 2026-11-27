"""Stage 10b-5: more agent leads, verified in the main session with evidence_W15.py (the e2m record and the code lines
of each row) and the function bodies named. Leads left open are in the task 046 list."""
GLOBALS = [
    # A/C clutch control (e2m 8A14, below the known +2C drift; bin 3)
    ("0x004086b4", "air_conditioning_low_rpm_off_threshold",
     "engine_protection_fuelMass_rpmCheck (the BR truck algorithm) keeps the A/C driver on only above it"),
    ("0x004086b8", "air_conditioning_low_rpm_on_time",
     "engine_protection_conditionCode_evaluate (the DR truck algorithm): the A/C driver may turn on after the engine "
     "speed has been above the low rpm on threshold this long"),
    # cruise / road speed governor (e2m 1186 / 1187; bins 3 and 6)
    ("0x0040b6a2", "cruise_droop_speed_error_delta",
     "the amount the cruise / RSG speed error is modified to form the droop curves; "
     "cm848_calculateAllSpeedGovernorEquivalentThrottle subtracts it from the reference speed; clamped to "
     "cruise_droop_speed_error_delta_minimum / maximum"),
    ("0x00408e20", "cruise_zone_2_speed_error_threshold",
     "governor_cruise_setpoint_calc switches to cruise gain set 2 above it (with cruise_zone_boundary_hysteresis); "
     "cruise_zone_3_speed_error_threshold is the next one"),
    ("0x0040b6be", "cruise_top_droop_offset",
     "the working top droop offset of the cruise / RSG droop (governor_cruise_setpoint_calc)"),
    ("0x003fb522", "cruise_fuel_ramp_down_working",
     "cm848_arbitrateGovernedFueling: starts at final_fueling and ramps down by cruise_minimum_fuel_ramp_rate "
     "(cruise_neutral_fuel_ramp_rate in neutral)"),
    ("0x003fd05c", "drivetrain_ratio_user_filtered_previous",
     "cm848_updateDrivetrainRatio: drivetrain_ratio_user_filtered of the previous pass (the settled test compares "
     "them)"),
    ("0x003fee7a", "tire_revolutions_per_mile_cal",
     "cm848_calculateRiseLimitedVehicleSpeed: tire revolutions per mile x rear_axle_ratio / 60 = engine_speed_to_vss_ratio"),
    # engine retarder (bin 4)
    ("0x003fb54a", "engine_retarder_fueling_below_threshold_pass_counter",
     "cm848_updateEngineRetarderActiveState: counts the passes with final_fueling at or below "
     "engine_retarder_fuel_demand_threshold"),
    # injection limit counters (e2m 804A / 804B; bin 3)
    ("0x004090ce", "injection_command_overlap_count_threshold",
     "the overlap persistence count that sets the fault (cm848_monitorInjectionLimitViolationCounters)"),
    ("0x0040b858", "injection_end_limit_exceeded_count",
     "persistence counter of the end of injection limit (TPU-A channel 2 / 7 flags)"),
    ("0x0040b85a", "injection_command_overlap_count",
     "persistence counter of injection commands that violate the minimum separation"),
    # cylinder balance (e2m 81AE; bin 3)
    ("0x00408f14", "cylinder_balance_coolant_temperature_threshold",
     "hpcr_cbdCalculateCylinderTrims: cylinder balance is off at or below this coolant temperature"),
    # the fault to erase (bin 6's uncertain row: the e2m record at +0 of 1080 is solid by the table)
    ("0x0040ae56", "diagnostic_fault_to_erase",
     "the fault to erase (a service tool request); the only access is cm848_clearDiagnosticState storing 0 after the "
     "clear"),
    # engine protection shutdown (e2m 10B3, EEPROM mirror)
    ("0x003fdfb8", "engine_protection_shutdown_active_channel_cal",
     "which protection channel shut the engine down (255 none, 0 coolant level, 1 coolant temperature, 2 intake "
     "manifold temperature, 3 oil pressure, ...); cm848_examineEngineProtectionBeforeCranking checks it before "
     "cranking"),
    ("0x003fdfba", "engine_protection_shutdown_count_cal",
     "the number of shutdowns while the error is active; cm848_examineEngineProtectionBeforeCranking compares it "
     "with the limit"),
    ("0x003fdfbc", "engine_protection_shutdown_total_cal",
     "the total number of shutdowns (cm848_updateEngineProtectionShutdown counts it up to 255)"),
    # injector driver PWM periods (e2m 8041 +A / +E / +12 / +18 / +1A; bin 2)
    ("0x004090aa", "injector_driver_booster_voltage_pwm_period_microseconds",
     "e2m 8041 +A HPCR_UCBOOS_Period 'Period duration for booster voltage' (USEC): the MIOS PWM 16 period "
     "(cm848_loadInjectorDriverCalibration); PWM 16 drives the booster voltage level"),
    ("0x004090ae", "injector_driver_recharge_voltage_pwm_period_microseconds",
     "e2m 8041 +E HPCR_URCHG_Period 'Period duration for recharge voltage' (USEC): the MIOS PWM 17 period"),
    ("0x004090b2", "injector_driver_recharge_current_period_microseconds",
     "e2m 8041 +12 HPCR_IRCHG_Period 'Period duration for recharge current control' (uSEC): TPU-A channel 14 "
     "parameter 0 (and the duty scale of cm848_loadInjectorDriverCalibration)"),
    ("0x004090b8", "injector_driver_hold_current_pwm_period_microseconds",
     "e2m 8041 +18 HPCR_ISOLLH_Period 'Period duration for hold current' (USEC): the MIOS PWM 18 period"),
    ("0x004090ba", "injector_driver_pull_in_current_pwm_period_microseconds",
     "e2m 8041 +1A HPCR_ISOLLA_Period 'Period duration for pullin current' (USEC): the MIOS PWM 19 period"),
    # the injector driver booster capacitor voltage channels (sensor channels 54 / 55; bin 4)
    ("0x0040be52", "injector_driver_booster_capacitor_1_voltage_sensor_fault_status",
     "fault status of sensor channel 54 (booster capacitor 1 voltage)"),
    ("0x0040be54", "injector_driver_booster_capacitor_2_voltage_sensor_fault_status",
     "fault status of sensor channel 55 (booster capacitor 2 voltage)"),
    ("0x0040b722", "injector_driver_booster_capacitor_1_voltage_channel_state",
     "the sensor channel state of channel 54 (booster capacitor 1 voltage)"),
    ("0x0040b72e", "injector_driver_booster_capacitor_2_voltage_channel_state",
     "the sensor channel state of channel 55 (booster capacitor 2 voltage)"),
    # supervisor chip (e2m 11AE; bin 2)
    ("0x0040a040", "supervisor_chip_overspeed_limit",
     "cm848_configureSupervisorChip: 30000000 / (it x the targets per revolution) is the overspeed period it "
     "programs (4200 rpm in the dump)"),
    # accelerator pedal faults (e2m 1048; bin 6)
    ("0x0005c2a4", "accelerator_pedal_fault_delay_at_idle",
     "the throttle fault delay at idle (ROM, no _cal), the twin of accelerator_pedal_fault_delay"),
    ("0x003fa6e2", "accelerator_pedal_fault_debounce_count_a",
     "cm848_monitorAcceleratorPedalIdleValidationFaults: one of the three fault debounce counters"),
    ("0x003fa6e4", "accelerator_pedal_fault_debounce_count_b", "the second fault debounce counter"),
    ("0x003fa6e6", "accelerator_pedal_fault_debounce_count_c", "the third fault debounce counter"),
    ("0x0005c29e", "accelerator_pedal_autozero_offset",
     "cm848_evaluateIdleValidationSwitches subtracts it from accelerator_pedal_autozero_cal for the idle validation "
     "switch thresholds"),
    ("0x0005c294", "accelerator_pedal_highest_valid_minimum",
     "the highest valid pedal minimum (ROM, no _cal): cm848_learnAcceleratorPedalAutozero learns the autozero only "
     "below it"),
]
FUNCTIONS = [
    ("0x005118f8", "cm848_controlAirConditioningClutch",
     "The A/C clutch control dispatcher (e2m 8A14 +4 AC_Control_Configuration: 0 = BR truck - 1 = DR truck): runs "
     "the BR or the DR truck algorithm; the dump holds 1 (DR)"),
    ("0x00510fa0", "cm848_controlAirConditioningClutchForBrTruck",
     "A/C clutch algorithm 0 (BR truck): a gate on engine speed - the A/C switch and the A/C pressure"),
    ("0x00511078", "cm848_controlAirConditioningClutchForDrTruck",
     "A/C clutch algorithm 1 (DR truck): condition codes 1-15 - cycle on / off times - the low rpm and high pressure "
     "thresholds; sets logical output 0x26 (the A/C clutch request)"),
    ("0x005127d8", "cm848_integrateCruiseRpmRatioChange",
     "Integrates the change of the engine speed / vehicle speed ratio (cruise_rpm_ratio_ema) into "
     "cruise_rpm_ratio_integral - not a speed error; the clutch cutout uses it"),
    ("0x0003a9a4", "cm848_initializePciMessageStatusBytes",
     "Stores the initial PCI (J1850) message status bytes: 37 of the 40 descriptor entries and the spare message "
     "$16; no J1939 buffer"),
    ("0x00046d90", "cm848_monitorInjectionLimitViolationCounters",
     "The persistence counters of the TPU-A channel 2 / 7 flags: end of injection limit exceeded and injection "
     "command overlap (e2m 804A / 804B; faults 325 / 326)"),
    ("0x000428d4", "cm848_selectUserCommandedFueling",
     "Selects FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND (USERCOMD) with user_commanded_fueling_cal"),
    ("0x00017560", "cm848_monitorAcceleratorPedalIdleValidationFaults",
     "Debounces and latches the accelerator pedal idle validation faults (P2121 fault 63 - P2127 fault 62 - P2128 "
     "fault 68) and saves the idle validation switch state at a throttle validation error; no fuel demand "
     "smoothing"),
    ("0x000429a0", "cm848_sensorChannel54_boosterCapacitor1VoltageInit",
     "Sensor channel 54 wrapper: the injector driver booster capacitor 1 voltage (faults 328 / 329; P2146)"),
    ("0x00042a2c", "cm848_sensorChannel54_boosterCapacitor1VoltageProcess",
     "Sensor channel 54 wrapper (the update / boot pass): the booster capacitor 1 voltage"),
    ("0x00042ab8", "cm848_sensorChannel55_boosterCapacitor2VoltageInit",
     "Sensor channel 55 wrapper: the injector driver booster capacitor 2 voltage (faults 330 / 331; P2149)"),
    ("0x00042b44", "cm848_sensorChannel55_boosterCapacitor2VoltageProcess",
     "Sensor channel 55 wrapper (the update / boot pass): the booster capacitor 2 voltage"),
    ("0x005289d4", "cm848_loadInjectorDriverCalibration",
     "Loads the injector driver calibration (every value is an e2m 8041 record): the MIOS PWM 16-19 periods and "
     "levels (booster / recharge voltage - hold / pull-in current) and the TPU-A channel 14 recharge current period"),
]
