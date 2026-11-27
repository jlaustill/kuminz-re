"""Round 28 stage A (label-only): three sensor-present flags named from their e2m records and code use, the boot
kernel's copy of the CAN transmit mailbox writer, and the boot CAN ring state instance (its type and fields are
renamed by apply_struct_renames.py with spec_r28a.py)."""
B = "cm848_calculateBoostPressure"
GLOBALS = [
    ("0x003feff6", "absolute_boost_pressure_sensor_present_flag",
     "Nonzero = the boost pressure sensor reads absolute pressure, so " + B + " (lhz @ 0xdc68) subtracts the barometric "
     "reference (barometric_pressure_sensor_filtered, or barometric_pressure_sensor_config.default_value when "
     "barometric_pressure_sensor_present_flag is 0) and clamps at 0; 0 = a gauge sensor, its reading is the boost. "
     "Either way the result is gauge boost. Also read by the boost / altitude and transmission monitors"),
    ("0x003feff4", "barometric_pressure_sensor_present_flag",
     "Nonzero = a barometric (ambient air pressure) sensor is fitted: the boost and transmission paths subtract "
     "barometric_pressure_sensor_filtered; 0 = they use the barometric channel's default "
     "(barometric_pressure_sensor_config.default_value)"),
    ("0x003fd536", "two_speed_axle_switch_present_cal",
     "EEPROM: the rear axle ratio (two-speed axle) switch is fitted, so cm848_calculateVehicleSpeedFromOutputShaft lets "
     "switch 31 pick the second axle-ratio divisor"),
    ("0x003024c6", "boot_can_ring_state",
     "The boot ROM / kernel CAN driver's queue state (can_ring_state_t): the transmit ring (12-byte frames at 0x3022e6) "
     "and receive ring (18-byte records at 0x302016) pointers, their full flags and the transmit message buffer. Users: "
     "mpc555_canTransmitQueuePush, mpc555_manageCan1TransmitBuffer, mpc555_processCanReceiveBuffer, "
     "mpc555_dispatchCanMessageHandlers (kernel) and mpc555_initDiagnosticSubsystem, "
     "mpc555_diagService25_executeFunction (boot ROM); the application has its own CAN driver"),
]
FUNCTIONS = [
    ("0x00004f2c", "cm848_writeBootKernelCanTxMailbox",
     "The boot kernel's copy (ROM 0x3C30-0x7F60 image) of cm848_writeCanControllerTxMailbox, byte for byte: copies "
     "the ID and 8 data bytes (6 halfwords) into TouCAN A message buffer (number - 1) and writes 0xC8 (transmit once, "
     "length 8) to its control byte. Called by mpc555_canTransmitQueuePush and mpc555_manageCan1TransmitBuffer. The old "
     "'Can2' was not a second controller"),
]
