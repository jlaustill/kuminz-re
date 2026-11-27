# T1 proposal draft (scratch)

Functions
- CM550 0x21a5c (no function) -> receivePgn57344CabMessage1 TWIN CM848 0x50b734 (both rows)
- CM550 0x21a8c cm550_FUN_00021a8c -> receivePgn61441ElectronicBrakeController1Message TWIN 0x50b77c
- CM550 0x21b88 cm550_FUN_00021b88 -> receivePgn61443ElectronicEngineController2Message TWIN 0x50b8a4
- CM550 0x21c3c (no function) -> receivePgn65252ShutdownMessage TWIN 0x50b98c
- CM550 0x21c74 cm550_FUN_00021c74 -> receivePgn65264PowerTakeoffInformationMessage TWIN 0x50b9d8
- CM550 0x21d44 cm550_FUN_00021d44 -> receivePgn65265CruiseControlVehicleSpeedMessage TWIN 0x50bacc
- CM550 0x21272 cm550_canTransmissionController -> registerJ1939ReceiveHandler TWIN 0x538eb0 (16 vs 17 capacity only;
  layout bound like copyCalibrationFromRomToRam / clearWorkingRam twins; flip = cm550_registerJ1939ReceiveHandler)
- CM550 0x21ef6 cm550_FUN_00021ef6 -> cm550_registerJ1939InputMessageHandlers COUNTERPART 0x50bdcc (no 1000 store)
- CM550 0x21edc cm550_FUN_00021edc -> cm550_tickJ1939InputSupervision COUNTERPART 0x50bca0 (loop only)

Globals CM550
- 0x800ab0 j1939_receive_handler_table j1939_receive_handler_entry_t[16]; 0x800b10 j1939_receive_handler_count byte
- 0x804234 j1939_input_signal_timeouts word[25]
- 0x20108 j1939_input_signal_descriptor_table j1939_input_signal_descriptor_t[17]
- 0x803f9c j1939_engine_fan_requested_percent_speed_source_address_filter_cal byte
- 0x803fa6 j1939_air_conditioner_high_pressure_fan_switch_source_address_filter_cal byte
- 0x80d9dc j1939_received_source_address byte (was can_received_source_address)
- 0x80d70f-0x80d725: the 23 CM848 j1939_received_* names (0x80d720 = j1939_received_wet_tank_pressure)
Globals CM848
- 0x40aaba j1939_received_wet_tank_pressure (was j1939_received_accelerator_pedal_position_2)
Structs CM550: j1939_receive_handler_entry_t (6), j1939_input_signal_descriptor_t (10)
Remove CM550 0x800b00 diagnostic_request_buffer (inside entry 13; conditional on a clean build diff)
