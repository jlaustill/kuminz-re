"""Round 11 stage A (label-only): the lift pump control (logical output 53, e2m 8A6F / 12A7 +0x35 / 1577 +6 0x20),
the SCI output status word, three cache names, the 32-39 request byte."""
GLOBALS = [
    ("0x003fcea4", "lift_pump_engine_stopped_time",
     "Word, 0.1 s: cm848_controlLiftPump adds 1 per pass while engine_state is STOPPED (held at 0xffff) and zeroes it "
     "when the engine cranks or runs; the pump stops when it passes the run time of lift_pump_run_reason "
     "(lift_pump_run_time_after_key_on / _after_cranking / _after_running)"),
    ("0x003fcea6", "lift_pump_run_reason",
     "Word: why the lift pump (logical output 53) runs - 1 key on (cm848_initializeLiftPumpControl), 2 the engine ran "
     "(RUNNING or ENGINE_BRAKE), 3 the engine cranked (CRANKING / REENTRY / JUMP_START); it picks the run time after "
     "the engine stops"),
    ("0x003fb1f2", "cruise_switch_ladder_cached_axis_offset",
     "Lookup cache (the last axis segment offset) of the cruise switch resistor-ladder lookup: "
     "cm848_processCruiseSwitchChannel / cm848_initCruiseSwitchChannel pass it with cruise_switch_sensor_config"),
    ("0x003fd0ca", "fuel_pressure_setpoint_map_cached_axis_offsets",
     "The lookup cache block of the fuel pressure setpoint maps (16 words 0x3fd0ca-0x3fd0e8, set to 2 by the "
     "initializer): cm848_calculateFuelPressureSetpoint passes its first word to each map lookup"),
    ("0x0040c084", "logical_output_request_bits_32_to_39",
     "Byte 4 of the logical output request array (outputs 32-39; e2m 1577 +4): 0x40 = output 38 AC_Discrete_Output, "
     "the A/C clutch relay (DRB test 13-09), which the A/C clutch control requests"),
]
FUNCTIONS = [
    ("0x00519cc4", "cm848_controlLiftPump",
     "The lift pump (logical output 53, e2m Lift_Pump_Driver; DRB test 13-33 'FUEL PUMP RELAY / TRANSFER PUMP'). With "
     "lift_pump_override_enable set it drives lift_pump_override_state. Otherwise it requests the pump while the "
     "engine runs (lift_pump_run_reason 2) or cranks (3), and with the engine stopped it counts "
     "lift_pump_engine_stopped_time (0.1 s) and drops the pump after the reason's run time: after key-on (35 s here), "
     "after cranking (20 s) or after running (0 s)"),
    ("0x00519c84", "cm848_initializeLiftPumpControl",
     "Key-on start of the lift pump control: lift_pump_run_reason = 1 (key on), lift_pump_engine_stopped_time = 0 and "
     "the lift pump requested (logical output 53), so the pump primes for lift_pump_run_time_after_key_on"),
]
