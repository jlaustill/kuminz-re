"""Stage 10e: the half-renamed leftovers the final review found (old prefixes next to renamed siblings)."""
GLOBALS = [
    ("0x0040be16", "compressor_inlet_temperature_sensor_fault_status",
     "the fault status of sensor channel 20 (0 in range / 1 debouncing / 2 fault confirmed); "
     "cm848_selectCompressorInletTemperature picks the sensor or its default by it"),
    ("0x0040be1a", "intake_manifold_temperature_sensor_fault_status",
     "the fault status of sensor channel 9 (the intake manifold / charge temperature sensor); "
     "cm848_filterAndSelectIntakeManifoldTemperature selects by it"),
    ("0x003fab60", "j1939_dm10_payload",
     "the DM10 data word: cm848_j1939HandlePgn65234Dm10 stores the byte-reversed supported_non_continuous_monitors_bits "
     "in it and the DM10 transmit descriptor points at it (the old name said DM11, which is PGN 65235)"),
    ("0x0040a265", "j1939_pgn56320_destination_address",
     "j1939_receivePgn56576Handler stores byte 3 of the anti-theft request in it; cm848_sendPgn56320AntiTheftStatus "
     "puts it in the PS byte (the destination address) of the PGN 56320 header"),
    ("0x0040a264", "j1939_pgn56320_source_address",
     "j1939_receivePgn56576Handler stores byte 2 of the anti-theft request in it; cm848_sendPgn56320AntiTheftStatus "
     "puts it in the last header byte (the source address) of the PGN 56320 message"),
]
FUNCTIONS = []
