"""Round 6 stage B1 (main session, label-only): e2m block 10E8 ("Jcomm", 0x40adf4-0x40ae1f) and 10E6 (0x40ad5a-
0x40ad5d) are Cummins' own layout of the J1939 powertrain control state. They confirm the stage A names and correct
three fields (apply_r6b1_fields.py) and the two control device indicators below."""
GLOBALS = [
    ("0x0040adf6", "engine_control_device_indicator",
     "the J1939 control device of the accepted engine TSC1 sender (cm848_lookupJ1939ControlDevice): 0 none, 1 the "
     "transmission, 2 ABS, 3 ASR, 4 another device; the high idle override needs 1. Typed undefined"),
    ("0x0040ad5c", "engine_retarder_control_device_indicator",
     "the J1939 control device of the accepted engine retarder TSC1 sender (cm848_lookupJ1939ControlDevice): 0 none, "
     "1 the transmission, 2 ABS, 3 ASR, 4 another device"),
]
FUNCTIONS = [
    ("0x00053a4c", "cm848_lookupJ1939ControlDevice",
     "Returns the J1939 control device of a source address, the e2m Jcomm_Engine_Control_Device_Indicator / "
     "Jcomm_Retarder_Control_Device_Indicator code: 1 when it is j1939_transmission_source_address, 2 for "
     "j1939_anti_lock_brake_source_address, 3 for j1939_anti_slip_regulation_source_address, else 4 (0 = none is the "
     "reset value)"),
]
