"""Round 5, J1939 (main session): j1939_header_pgns.py lists every function that builds a J1939 header with the PGN
its constant encodes; four names named the wrong message. The EC1 (PGN 65251) "fault timer / fault counter" family is
the EC1 payload, its previous copy and the send-on-change test (J1939-71: EC1 goes out when a torque curve point
changes by 10 % or more). The payload is 28 bytes at 0x3fa7f8 (current) and 0x3fa814 (previous copy); J1939 byte n
is offset n - 1. Rows that match one J1939 field are named for it; rows the compiler's chunked copy made across two
fields are named by their byte range."""
P = "the EC1 (PGN 65251) payload"
Q = "the previous copy of the EC1 (PGN 65251) payload, kept for the send-on-change test"
GLOBALS = [
    ("0x003fa7f8", "j1939_pgn65251_payload",
     f"{P}: 28 bytes (J1939-71 EC1: the torque curve points 1-5, high idle point 6, the endspeed governor gain, the "
     "reference torque, override point 7 and the control range limits); buildPgn65251EngineConfiguration1Payload "
     "fills it and the transmit descriptor points at it; typed dword here (the copies move it in chunks)"),
    ("0x003fa7fe", "j1939_pgn65251_engine_speed_point_3", f"{P}, bytes 7-8: engine speed at point 3 (SPN 529)"),
    ("0x003fa800", "j1939_pgn65251_payload_bytes_9_10",
     f"{P}, bytes 9-10: the percent torque at point 3 and the first byte of the point 4 speed"),
    ("0x003fa804", "j1939_pgn65251_engine_speed_point_5", f"{P}, bytes 13-14: engine speed at point 5 (SPN 531)"),
    ("0x003fa808", "j1939_pgn65251_payload_bytes_17_18",
     f"{P}, bytes 17-18 (read as a dword through 20): the end of the high idle speed and the endspeed governor gain"),
    ("0x003fa80c", "j1939_pgn65251_payload_bytes_21_22",
     f"{P}, bytes 21-22 (read as a dword through 24): the end of the reference torque and the override speed"),
    ("0x003fa810", "j1939_pgn65251_control_range_limits",
     f"{P}, bytes 25-28: the requested speed control range lower / upper and torque control range lower / upper "
     "limits"),
    ("0x003fa814", "j1939_pgn65251_payload_previous",
     f"{Q}: cm848_sendPgn65251EngineConfiguration1OnChange copies the payload here before it rebuilds it"),
    ("0x003fa81a", "j1939_pgn65251_engine_speed_point_3_previous", f"{Q}, bytes 7-8"),
    ("0x003fa81c", "j1939_pgn65251_payload_bytes_9_10_previous", f"{Q}, bytes 9-10"),
    ("0x003fa820", "j1939_pgn65251_engine_speed_point_5_previous", f"{Q}, bytes 13-14"),
    ("0x003fa824", "j1939_pgn65251_payload_bytes_17_18_previous", f"{Q}, bytes 17-18"),
    ("0x003fa828", "j1939_pgn65251_payload_bytes_21_22_previous", f"{Q}, bytes 21-22"),
    ("0x003fa82c", "j1939_pgn65251_control_range_limits_previous", f"{Q}, bytes 25-28"),
    ("0x003faf1c", "j1939_pgn65279_water_in_fuel_indicator_byte",
     "the PGN 65279 payload: 0xfc no water / 0xfd water in fuel (fault bit 56 set) / 0xff not available (the "
     "water in fuel algorithm is disabled); cm848_sendPgn65279WaterInFuelIndicatorMessage writes it"),
]
FUNCTIONS = [
    ("0x0002560c", "cm848_initializePgn65232Dm8Buffer",
     "Builds the transmit descriptor of DM8 (header 0xfed000: PGN 65232 Test Results for Non-continuously Monitored "
     "Systems)"),
    ("0x00025824", "cm848_initializePgn61441ElectronicBrakeController1Buffer",
     "Builds the transmit descriptor of EBC1 (header 0xf00100: PGN 61441 Electronic Brake Controller 1; ETC1 is "
     "61442)"),
    ("0x00026efc", "cm848_initializePgn65279WaterInFuelIndicatorBuffer",
     "Builds the transmit descriptor of PGN 65279 (header 0xfeff00), the water in fuel indicator"),
    ("0x00026e90", "cm848_sendPgn65279WaterInFuelIndicatorMessage",
     "Sends PGN 65279, the water in fuel indicator: 0xff when the water in fuel algorithm is disabled, else 0xfd "
     "with fault bit 56 (water in fuel) set or 0xfc"),
    ("0x0001b730", "cm848_sendPgn65251EngineConfiguration1Message",
     "Builds the EC1 payload (buildPgn65251EngineConfiguration1Payload) and sends PGN 65251 when the transmit slot is "
     "free"),
    ("0x0001b778", "cm848_sendPgn65251EngineConfiguration1OnChange",
     "The EC1 send-on-change test (J1939-71): copies the payload to j1939_pgn65251_payload_previous, rebuilds it and "
     "compares each speed (cm848_hasWordChangedByTenPercent) and percent torque (cm848_hasByteChangedByTenPercent) "
     "with its previous value; a change of 10 % or more sends the message"),
    ("0x0001b624", "cm848_hasWordChangedByTenPercent",
     "Returns 1 when a 16-bit value changed by 10 % or more of its previous value (or from 0 to non-zero): "
     "|new - old| x 10 / old >= 1"),
    ("0x0001b69c", "cm848_hasByteChangedByTenPercent",
     "Returns 1 when an 8-bit value changed by 10 % or more of its previous value (or from 0 to non-zero)"),
    ("0x00023dbc", "cm848_sendJ1939NegativeAcknowledgement",
     "Sends the J1939 acknowledgement (PGN 59392, header 0xe8ff00) with the negative acknowledgement control byte"),
]
QUOTE_OVERRIDE = {
    "0x003fa80c": "cm848_processFaultMessageTiming: _fault_slot_data_shadow_b = _fault_slot_data_copy_b; (rendered with _: a word row read as a dword)",
    "0x003fa828": "cm848_processFaultMessageTiming: _fault_slot_data_shadow_b = _fault_slot_data_copy_b; (rendered with _)",
}
