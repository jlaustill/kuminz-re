"""Block 8000 (bin records 28-35) and the first 801A rows (36-38): all keeps."""
ENTRIES = []


def keep(address, name, note):
    ENTRIES.append({"kind": "global", "verdict": "keep", "address": address, "old": name, "new": name, "e2m_note": note})


keep("0x004090fe", "fuel_pressure_governor_low_pressure_entry_count",
     "e2m 8000 +4 HPCR_Wait_Time_Deflate 'Waiting time to start deflation' (deflation = the low pressure fixed command mode, "
     "FUEL_PRESSURE_GOVERNOR_LOW_PRESSURE_FIXED; 10 ms per count in the e2m, 500 = 5 s in the dump)")
keep("0x00409100", "fuel_pressure_governor_low_pressure_fixed_limit",
     "e2m 8000 +6 HPCR_Min_Time_Deflate 'Minimum time duration of deflation process' (10 ms per count in the e2m, 1000 = 10 s in "
     "the dump; the code uses it as the pass cap of the low pressure fixed mode: the mode ends once its pass counter exceeds it, "
     "or earlier when the pressure or engine speed condition ends)")
keep("0x00409102", "fuel_pressure_governor_start_revolution_limit",
     "e2m 8000 +8 HPCR_Count_Rev 'Number of revolutions to wait for a change from precontrol to control mode' (1000 revolutions in "
     "the dump; precontrol = FUEL_PRESSURE_GOVERNOR_CLOSED_LOOP_AFTER_START with the feed forward, control = CLOSED_LOOP)")
keep("0x00409104", "fuel_pressure_governor_closed_loop_entry_pressure",
     "e2m 8000 +A HPCR_Min_Pressure_Switch_Closedloop 'Minimum pressure required to switch to closed loop control' (2254 counts = "
     "110 MPa at 0.0488 MPa per count)")
keep("0x00409106", "fuel_pressure_governor_closed_loop_entry_rpm",
     "e2m 8000 +C HPCR_Min_RPM_Switch_Closedloop 'Minimum engine speed required to switch to closed loop control' (400 counts of "
     "0.125 rpm = 50 rpm)")
keep("0x00409108", "fuel_pressure_governor_closed_loop_exit_pressure",
     "e2m 8000 +E HPCR_Min_Pressure_Stay_Closedloop 'Minimum pressure required to stay in closed loop control' (2049 counts = "
     "100 MPa; the mode machine leaves closed loop below it together with the speed condition at +10)")
keep("0x0040910a", "fuel_pressure_governor_closed_loop_exit_rpm",
     "e2m 8000 +10 HPCR_Min_RPM_Stay_Closedloop 'Minimum engine speed required to stay in closed loop control' (320 counts of "
     "0.125 rpm = 40 rpm)")
keep("0x0040910e", "fuel_pressure_governor_key_off_command",
     "e2m 8000 +14 HPCR_Dutycycle_Shutoff 'Duty cycle during shut off' (0 in the dump; the command of the "
     "FUEL_PRESSURE_GOVERNOR_KEY_OFF mode)")
keep("0x00409516", "fuel_pressure_sensor_too_high_threshold",
     "e2m 801A +0 HPCR_Fuelpr_Monitor_Max 'Fuel pressure upper limit (within sensor range)' (3688 counts = 180 MPa; the too high "
     "check of cm848_diagnoseFuelPressureGovernor, P0088 after fuel_pressure_too_high_count_limit passes)")
keep("0x00409518", "fuel_metering_feedback_circuit_high_threshold",
     "e2m 801A +2 HPCR_Current_Max 'Maximum current through pressure regulator valve' (4092 counts = 5.0 A at 1.2218 mA per count; "
     "fuel_metering_feedback_input above it is the high condition)")
keep("0x00409522", "fuel_pressure_governor_demand_limit_at_governed_speed",
     "e2m 801A +C HPCR_Lowidle_Dutycycle 'Dutycycle for monitoring defect during low idle' (283 = 6.9 percent; flag 0x40 of "
     "cm848_diagnoseFuelPressureGovernor needs final_fueling_state = FUELING_STATE_LOW_SPEED_GOVERNOR and the engine speed "
     "inside the +E window around governor_output_t.idle_reference_speed, so the governed speed here is the low idle)")
