"""Round 13 stage A (label-only): the Chrysler end-of-line (in-plant) test steps of cm848_runEndOfLineTestSequence and
the SCI command 0x25 (37) service tests. The sequencer's steps and their working words carried cold start /
protection / cam sync / fault queue guesses; e2m 164A (EOL_*) and 1649 (CHRY_In_Plant_*) name the settings, e2m 8C74
/ 8C76 / 8C77 / 8C19 the 'Cmd25' service tool tests (DRB 25-25 CylinderPerformanceTest, 25-26
HighPressSaftyValveTest). Outputs: 4 wait-to-start lamp, 17 overdrive solenoid, 18 converter clutch solenoid, 38 A/C
clutch relay, 43 / 44 intake air heaters 1 / 2, 53 lift pump (e2m 1577). Faults 386 / 387 = P0629 / P0628."""
STEP = "cm848_runEndOfLineTestSequence"
GLOBALS = [
    ("0x003fd1ac", "end_of_line_test_seconds_since_engine_start",
     f"Byte: seconds since the engine left ENGINE_STATE_STOPPED, kept by {STEP} (+1 each time "
     "end_of_line_test_second_divider_pass_count reaches 10; 0 while stopped); cm848_runEndOfLineMisfireTestStep "
     "compares it with the misfire test times. TIME-SHARED with the boot kernel image: the boot ROM calls "
     "cm848_sendDiagResponsePending at this address, and the build gives those calls a call override"),
    ("0x003fd1b0", "end_of_line_test_step_sub_state",
     "Byte: the sub-state of the end-of-line test step that is running - step 5 (cm848_runEndOfLineMisfireTestStep) "
     "and step 6 (cm848_runEndOfLineFinalResultStep: 0 waiting / 3 pass read once / 4 fail read once); 0 from "
     "cm848_initializeEndOfLineTestSequence"),
    ("0x003fd1b1", "end_of_line_output_test_start_delay_count",
     "Byte: cm848_runEndOfLineOutputTestStep returns at once on its first two passes after a reset (0 -> 2), then "
     "holds 2"),
    ("0x003fd1b2", "end_of_line_output_test_state",
     "Byte: state of cm848_runEndOfLineOutputTestStep - 1 start the actuator tests / 2 lift pump (output 53) / 3 "
     "wait-to-start lamp (output 4) and A/C clutch relay (output 38) / 4-5 intake air heater 1 (output 43) on then "
     "off / 6-7 intake air heater 2 (output 44) on then off and the verdict / 8 done (also when the step is left "
     "early); 1 from cm848_initializeEndOfLineTestSequence (1 in the RAM dump)"),
    ("0x003fd1b3", "end_of_line_output_test_output_on_flag",
     "Byte: 1 while the output under test is on (end_of_line_output_test_timer counts its on time), 0 while it is "
     "off (the timer counts end_of_line_test_relay_off_time before the next output)"),
    ("0x003fd1b4", "end_of_line_output_test_timer",
     "Word: countdown of the output tests' on / off times (end_of_line_test_lift_pump_on_time / _relay_on_time / "
     "_relay_off_time, one count per 0.1 s pass)"),
    ("0x003fd1b6", "end_of_line_test_output_previous_priority",
     "Word: the priority the output held (logical_output_request_priority) when cm848_setEndOfLineTestOutputRequest "
     "claimed it; cm848_clearEndOfLineTestOutputRequest passes it to cm848_clearLogicalOutputRequest"),
    ("0x003fd1b8", "end_of_line_test_output_priority",
     "Word: the priority of the end-of-line output test requests (5); cm848_clearEndOfLineTestOutputRequest zeroes an "
     "output's priority only while it still equals this"),
    ("0x003fd1bc", "end_of_line_test_intake_air_heater_1_voltage_drop",
     "Word: the battery voltage stored when intake air heater 1 (output 43) switches on (output test state 4). After "
     "end_of_line_test_intake_air_heater_voltage_reading_delay_time cm848_measureEndOfLineIntakeAirHeaterVoltageDrops "
     "makes it that voltage minus the present battery voltage - the drop the heater causes. "
     "cm848_runEndOfLineIntakeAirHeaterResultStep passes the test when both drops exceed "
     "end_of_line_test_intake_air_heater_minimum_delta_voltage_threshold"),
    ("0x003fd1be", "end_of_line_test_intake_air_heater_2_voltage_drop",
     "Word: as end_of_line_test_intake_air_heater_1_voltage_drop for intake air heater 2 (output 44, output test "
     "state 6)"),
    ("0x003fd1c0", "end_of_line_test_intake_air_heater_1_reading_delay_timer",
     "Word: countdown from end_of_line_test_intake_air_heater_voltage_reading_delay_time after heater 1 switches on; "
     "at 0 the voltage drop is taken. 0xffff = idle (set by cm848_initializeEndOfLineTestSequence)"),
    ("0x003fd1c2", "end_of_line_test_intake_air_heater_2_reading_delay_timer",
     "Word: as end_of_line_test_intake_air_heater_1_reading_delay_timer for heater 2"),
    ("0x003fd1c4", "end_of_line_test_step",
     f"Word: the step of {STEP}; each step function returns the next - 0 start (cm848_runEndOfLineTestStartStep) / "
     "1 output tests / 2 intake air heater result / 3 alternator test / 4 radiator fan speed noise / 5 misfire test "
     "/ 6 final result / 7 done"),
    ("0x003fd1c6", "end_of_line_alternator_test_started_flag",
     "Byte: set once the engine runs during cm848_runEndOfLineAlternatorTestStep, when it turns the MIL override on"),
    ("0x003fd1c9", "end_of_line_alternator_test_voltage_snapshot",
     "Word at an odd address (sth @ 0x52f670, lhz @ 0x52f694): the battery voltage when the alternator test cuts the "
     "field. The verdict takes the present voltage minus this in 16 bits (subf r4,r3,r31 / clrlwi), so any fall "
     "passes (it wraps to 65536 - drop, above end_of_line_test_alternator_voltage_threshold) and no fall fails"),
    ("0x0040b284", "alternator_field_actuator_test_active_flag",
     "Word: the alternator field actuator test. SCI command 0x25 test 0x11 (1 on / 2 off; "
     "alternator_field_actuator_test_timeout_count 15) and the end-of-line output tests (end_of_line_test_enable_flags "
     "bit 5) set it. cm848_applyAlternatorFieldDuty then drives alternator_field_actuator_test_duty while the engine "
     "is stopped (or always with alternator_field_actuator_test_while_running_enable), and "
     "cm848_testAlternatorOutputByCuttingField does not run"),
    ("0x0040b286", "end_of_line_alternator_test_field_cut_flag",
     "Byte: set by cm848_runEndOfLineAlternatorTestStep from its voltage snapshot to its verdict; while it is 1 "
     "cm848_applyAlternatorFieldDuty drives alternator_field_end_of_line_test_duty (0: the field off)"),
    ("0x004087f0", "alternator_field_actuator_test_duty",
     "Field duty while alternator_field_actuator_test_active_flag is set and the engine is stopped (or always with "
     "alternator_field_actuator_test_while_running_enable) - 25600 (100 %) in the RAM dump"),
    ("0x004087f6", "alternator_field_end_of_line_test_duty",
     "Field duty while end_of_line_alternator_test_field_cut_flag is 1 (the end-of-line alternator test) - 0 in the "
     "RAM dump"),
    ("0x004087f8", "alternator_field_actuator_test_while_running_enable",
     "1: alternator_field_actuator_test_duty applies while the engine runs too (else only in ENGINE_STATE_STOPPED) - "
     "1 in the RAM dump"),
    ("0x0040889a", "cooling_fan_actuator_test_duty",
     "Duty request (cooling_fan_duty_source_code 9) while cooling_fan_actuator_test_active_flag is set and the engine "
     "is stopped (or always with cooling_fan_actuator_test_while_running_enable) - 25344 (99 %) in the RAM dump"),
    ("0x0040889c", "cooling_fan_actuator_test_while_running_enable",
     "1: cooling_fan_actuator_test_duty applies while the engine runs too (else only in ENGINE_STATE_STOPPED) - 1 in "
     "the RAM dump"),
    ("0x003fcf74", "alternator_field_actuator_test_timeout_count",
     "SCI command 0x25 test 0x11 timeout: 15 at an on request, 0 at an off; cm848_expireSciCommand37Tests counts it "
     "down and clears alternator_field_actuator_test_active_flag at 0"),
    ("0x003fcf76", "lift_pump_actuator_test_timeout_count",
     "SCI command 0x25 test 0x24 timeout (the lift pump, output 53, with the engine stopped): 125 at a request; at 0, "
     "or as soon as the engine leaves ENGINE_STATE_STOPPED, cm848_expireSciCommand37Tests drops output 53's "
     "priority-5 request"),
    ("0x003fcf78", "cylinder_contribution_test_request_timeout_count",
     "SCI command 0x25 test 0x25 timeout (DRB 25-25 CylinderPerformanceTest): 1500 at a request; at 0, or when "
     "cylinder_contribution_test_status is 2 (aborted), cm848_expireSciCommand37Tests clears "
     "cylinder_contribution_test_request_flag"),
    ("0x003fcf7a", "high_pressure_safety_valve_test_timeout_count",
     "SCI command 0x25 test 0x26 timeout (DRB 25-26 HighPressSaftyValveTest): 150 at a request; at 0, or when "
     "high_pressure_safety_valve_test_state is 2 (aborted), cm848_expireSciCommand37Tests clears "
     "high_pressure_safety_valve_test_request_flag"),
    ("0x003fcf7c", "governor_pressure_solenoid_actuator_test_timeout_count",
     "SCI command 0x25 test 0x14 timeout (the 48RE governor pressure solenoid; e2m 8C19 RE_Cmd25_Gov_Press): 25 at a "
     "request; at 0 cm848_expireSciCommand37Tests clears transmission_shift_strategy_flags.service_test_request_flags "
     "bit 0"),
    ("0x003fcf7e", "converter_clutch_solenoid_actuator_test_timeout_count",
     "SCI command 0x25 test 0x15 timeout (the converter clutch solenoid, output 18; e2m 8C19 RE_Cmd25_TCC): 10 at a "
     "request; at 0 cm848_expireSciCommand37Tests clears service_test_request_flags bits 0-1 and output 18's "
     "priority-5 request"),
    ("0x003fcf80", "overdrive_solenoid_actuator_test_timeout_count",
     "SCI command 0x25 test 0x16 timeout (the overdrive solenoid, output 17; e2m 8C19 RE_Cmd25_3_4_Shift): 10 at a "
     "request; at 0 cm848_expireSciCommand37Tests clears service_test_request_flags bits 0 and 2 and output 17's "
     "priority-5 request"),
    ("0x0040b764", "cylinder_contribution_test_request_flag",
     "Byte: the service tool's cylinder contribution test request - SCI command 0x25 test 0x25 (DRB 25-25 "
     "CylinderPerformanceTest; 1 on / 2 off; timeout cylinder_contribution_test_request_timeout_count 1500). "
     "cm848_runCylinderContributionTest runs while it is set"),
    ("0x0040aed4", "high_pressure_safety_valve_test_request_flag",
     "Byte: the service tool's high pressure safety valve test request - SCI command 0x25 test 0x26 (DRB 25-26 "
     "HighPressSaftyValveTest; 1 on / 2 off; timeout high_pressure_safety_valve_test_timeout_count 150)"),
    ("0x0040aed5", "high_pressure_safety_valve_test_state",
     "Byte, set by cm848_calculateProtectionSpeedLimits: 0 without the request; 1 while protection_feature_flags bit "
     "0x10, the low speed governor in control, the engine running in park or neutral, the brake switch (11) and "
     "switch 2 off, the accelerator at idle, the vehicle stopped and engine speed at most "
     "high_pressure_safety_valve_test_maximum_engine_speed all hold - the idle speed floor then goes to "
     "high_pressure_safety_valve_test_engine_speed_setpoint and cm848_calculateFuelPressureSetpoint returns "
     "fuel_pressure_setpoint_high_pressure_safety_valve_test_value; 2 when one fails"),
    ("0x0040712e", "high_pressure_safety_valve_test_maximum_engine_speed",
     "ROM: the high pressure safety valve test aborts (state 2) above this engine speed (20000 = 2500 rpm in the RAM "
     "dump)"),
    ("0x00407130", "high_pressure_safety_valve_test_engine_speed_setpoint",
     "ROM: the idle speed floor (governor_speed_limit_floor, the low speed governor setpoint) while the high pressure "
     "safety valve test runs (9600 = 1200 rpm in the RAM dump)"),
    ("0x00409a88", "fuel_pressure_setpoint_high_pressure_safety_valve_test_value",
     "The rail pressure setpoint cm848_calculateFuelPressureSetpoint returns while "
     "high_pressure_safety_valve_test_state is 1 (2869 counts = 140 MPa)"),
]
FUNCTIONS = [
    ("0x0052ef90", "cm848_initializeEndOfLineTestSequence",
     f"Boot initializer of {STEP} (called from cm848_applicationMain): clears "
     "end_of_line_test_seconds_since_engine_start and its pass divider, shows a failed result again (MIL override 3) "
     "when end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal is 1, sets "
     "end_of_line_test_output_number to 80 (no output), end_of_line_test_step to 0 and end_of_line_output_test_state "
     "to 1, and idles the intake air heater reading delay timers (0xffff)"),
    ("0x0052f030", "cm848_runEndOfLineTestStartStep",
     f"Step 0 of {STEP}. Through EEPROM byte writes it clears the in-plant flag bytes "
     "(end_of_line_test_settings_cal.test_flags_1 to _5) except the pending / not-passed bits of the tests, and "
     "clears those bits for each test that end_of_line_test_enable_flags disables (bit 0 the intake air heater test "
     "- test_flags_5 bits 0-1, bit 5 the alternator test - test_flags_4 bit 0, bit 1 the misfire test - test_flags_5 "
     "bits 4-5); it also sets bytes 4-5 of eeprom_shadow_header.calibration_block1 to 0 / 0x19. It returns the first "
     "pending step: 1 the output tests (test_flags_2 bit 3 or test_flags_5 bit 0), 3 the alternator test "
     "(test_flags_3 bit 5), 5 the misfire test (test_flags_5 bit 4), 6 the final result (final_test_results_1 bit "
     "3), else 7 (done)"),
    ("0x0052f250", "cm848_runEndOfLineIntakeAirHeaterResultStep",
     f"Step 2 of {STEP}: the intake air heater test verdict. Both voltage drops "
     "(end_of_line_test_intake_air_heater_1_voltage_drop / _2_voltage_drop) above "
     "end_of_line_test_intake_air_heater_minimum_delta_voltage_threshold pass it (test_flags_5 bit 1 cleared, MIL "
     "override 2); otherwise the MIL override goes to 3 and "
     "end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal to 1. It clears test_flags_5 bit 0 (the "
     "test pending) and returns step 3"),
    ("0x0052f5d4", "cm848_runEndOfLineAlternatorTestStep",
     f"Step 3 of {STEP}: the alternator test (e2m 164A EOL_EVR_*) while test_flags_3 bit 5 is set (else step 4). With "
     "the engine running it turns the MIL override on once (end_of_line_alternator_test_started_flag). When "
     "end_of_line_test_time_since_engine_start passes end_of_line_test_alternator_test_delay it snapshots the battery "
     "voltage and sets end_of_line_alternator_test_field_cut_flag (cm848_applyAlternatorFieldDuty then drives "
     "alternator_field_end_of_line_test_duty, 0); after end_of_line_test_alternator_test_time it releases the field. "
     "The verdict takes the present voltage minus the snapshot in 16 bits, so any fall passes (test_flags_4 bit 0 "
     "cleared, MIL override 2) and no fall sets "
     "end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal; test_flags_3 bit 5 is cleared and it "
     "returns step 4"),
    ("0x0052f770", "cm848_runEndOfLineFinalResultStep",
     f"Step 6 of {STEP}: shows the plant tester's final verdict on the MIL. While "
     "end_of_line_test_settings_cal.test_results_1 bit 3 is set it waits; bit 2 must then read the same on two "
     "passes (end_of_line_test_step_sub_state 3 / 4). Clear (pass) sets the MIL override to 2, set (fail) to 3 with "
     "end_of_line_test_malfunction_indicator_lamp_power_down_state_flag_cal; both return step 7 (done). A failed "
     "result from an earlier step (the power-down flag) is shown again (override 3) on every pass"),
    ("0x0052f89c", "cm848_measureEndOfLineIntakeAirHeaterVoltageDrops",
     "Called each pass of cm848_runEndOfLineOutputTestStep while the intake air heater test runs (test_flags_5 bit 0 "
     "and end_of_line_test_enable_flags bit 0): counts down each heater's reading delay timer (0xffff = idle). When "
     "one reaches 0, its voltage word (the battery voltage stored when the heater switched on) becomes that value "
     "minus the present battery voltage - the drop the heater causes"),
    ("0x0052f938", "cm848_isDtcStoredOtherThanFault",
     "Returns 0 when recent_fault_dtc_codes_cal holds no DTC, or only the DTC of the given fault (ROM 0x5985a slot -> "
     "obd_dtc_code_table), else 1. cm848_runEndOfLineOutputTestStep calls it with fault 256, which has no DTC slot "
     "(slot 170, past the table), so there it means 'a DTC is stored'"),
    ("0x0052f994", "cm848_setEndOfLineTestOutputRequest",
     "Requests a logical output for the end-of-line output tests at the given priority (5): keeps the output's "
     "present priority in end_of_line_test_output_previous_priority, the output in end_of_line_test_output_number and "
     "the priority in end_of_line_test_output_priority, then calls cm848_setLogicalOutputRequest"),
    ("0x0052f9d8", "cm848_clearEndOfLineTestOutputRequest",
     "Releases a logical output of the end-of-line output tests: zeroes its priority while it still holds "
     "end_of_line_test_output_priority, then calls cm848_clearLogicalOutputRequest with the output and "
     "end_of_line_test_output_previous_priority"),
    ("0x0052fa34", "cm848_runEndOfLineOutputTestStep",
     f"Step 1 of {STEP}: the output tests (e2m 164A; engine stopped). When the engine is not stopped, or neither the "
     "intake air heater test (test_flags_5 bit 0 with end_of_line_test_enable_flags bit 0) nor the output tests "
     "(test_flags_2 bits 3 and 4) are pending, it releases the outputs and the actuator tests and returns step 3. "
     "After a two-pass start delay end_of_line_output_test_state runs: 1 starts the fuel control / alternator field "
     "/ cooling fan actuator tests (enable bits 6 / 5 / 7) and turns the MIL override on; 2 runs the lift pump "
     "(output 53, enable bit 3 - with the bit clear the state never moves on) for end_of_line_test_lift_pump_on_time "
     "and passes it without P0629 / P0628 (test_flags_2 bits 5 and 7 cleared); 3 runs the wait-to-start lamp "
     "(output 4, bit 2) and the A/C clutch relay (output 38, bit 4) for end_of_line_test_relay_on_time; 4-7 run "
     "intake air heaters 1 and 2 (outputs 43 / 44) one at a time, each storing the battery voltage for "
     "cm848_measureEndOfLineIntakeAirHeaterVoltageDrops; 7 passes the output tests when no DTC is stored "
     "(test_flags_2 bit 4 cleared), clears bit 3 and returns step 2 for the heater verdict (step 3 without the heater "
     "test). Each output is on for its on time and off for end_of_line_test_relay_off_time "
     "(end_of_line_output_test_timer / end_of_line_output_test_output_on_flag), requested at priority 5 through "
     "cm848_setEndOfLineTestOutputRequest / cm848_clearEndOfLineTestOutputRequest"),
    ("0x00530288", "cm848_initializeRadiatorFanSpeedRationalityCheck",
     "Boot initializer of cm848_checkRadiatorFanSpeedRationality (P0483): clears radiator_fan_speed_out_of_range_count"),
    ("0x00521474", "cm848_expireSciCommand37Tests",
     "Main loop: counts down the SCI command 0x25 (37) test timeouts that cm848_sciCommand37Callback sets and ends each "
     "test at 0 - the alternator field actuator test (alternator_field_actuator_test_active_flag), the lift pump test "
     "(output 53 at priority 5; also ended once the engine leaves ENGINE_STATE_STOPPED), the cylinder contribution "
     "test (DRB 25-25; also ended when cylinder_contribution_test_status is 2), the high pressure safety valve test "
     "(DRB 25-26; also ended when high_pressure_safety_valve_test_state is 2) and the 48RE governor pressure / "
     "converter clutch / overdrive solenoid tests (transmission_shift_strategy_flags.service_test_request_flags bits "
     "0 / 1 / 2, outputs 18 / 17)"),
    ("0x005216cc", "cm848_initializeSciCommand37TestTimeouts",
     "Boot initializer (cm848_applicationMain): clears the alternator field, lift pump, cylinder contribution and high "
     "pressure safety valve test timeouts of SCI command 0x25"),
]
