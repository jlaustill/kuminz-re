"""Stage 10b-4: J1939. The default priorities of e2m 1254 still missing _cal (bin 3; the PGN is the header each one
builds: 0xe8ff00 ACKM 59392, 0xfef100 / 0xfeed00 CCVS1 65265 / CCSS 65261, 0xfeca00 DM1 65226, 0xfecb00 DM2 65227,
0xfed200 = PGN 65234 = DM10 (the J1939 database; DM11 is 65235) - so the dm11 names were wrong and the e2m record,
Jcomm_DM10_Message_Default_Priority, is right); the transmit descriptors with the wrong PGN (bin 3); the anti-theft
words of e2m 117F (bin 5) and two more 117F rows; the retarder configuration's point 2 speed (bin 4)."""
GLOBALS = [
    ("0x003fd83a", "j1939_pgn59392_priority_cal",
     "the priority bits of the ACKM acknowledgement (header 0xe8ff00, PGN 59392) in cm848_initJ1939AcknowledgementBuffer"),
    ("0x003fd83e", "j1939_cruise_control_vehicle_speed_priority_cal",
     "the priority bits of both cruise control messages: CCVS1 (header 0xfef100, PGN 65265) and CCSS (0xfeed00, "
     "PGN 65261)"),
    ("0x003fd842", "j1939_pgn65226_priority_cal", "the priority bits of DM1 (header 0xfeca00, PGN 65226)"),
    ("0x003fd844", "j1939_pgn65227_priority_cal", "the priority bits of DM2 (header 0xfecb00, PGN 65227)"),
    ("0x003fd84c", "j1939_pgn65234_priority_cal",
     "the priority bits of DM10 (header 0xfed200, PGN 65234 - DM10 in the J1939 database; the old name said DM11, "
     "which is PGN 65235)"),
    ("0x003fab52", "j1939_dm10_tx_message",
     "the transmit descriptor of DM10 (header 0xfed200, PGN 65234); the old name said DM11 (PGN 65235)"),
    ("0x003faa8c", "j1939_pgn56320_tx_message",
     "the transmit descriptor of the anti-theft status (header 0xdc2800: PDU1, PF 0xdc = PGN 56320 Anti-theft Status "
     "to destination 0x28; the old name counted the destination into the PGN)"),
    ("0x003faeb8", "j1939_pgn65504_tx_message",
     "the transmit descriptor of PGN 65504 (header 0xffe000, proprietary B; the e2m priority record calls it the EPA "
     "info message); the old name said 57344"),
    ("0x003faa88", "j1939_pgn56320_encryption_seed",
     "cm848_sendPgn56320AntiTheftStatus copies j1939_anti_theft_encryption_seed_cal into it (accessed as a dword, "
     "typed later)"),
    ("0x0040a2c2", "j1939_anti_theft_status_transmit_state",
     "j1939_receivePgn56576Handler (the anti-theft request) sets 2; cm848_sendPgn56320AntiTheftStatus sends the status "
     "when it is 2 and j1939_anti_theft_send_status_report_cal is set"),
    ("0x003fdd80", "j1939_anti_theft_component_status_cal",
     "bits 5-4 of the PGN 56320 status byte (cm848_sendPgn56320AntiTheftStatus)"),
    ("0x003fdd86", "j1939_anti_theft_encryption_seed_cal",
     "the random number provided via the data link as an encryption seed; 4 bytes (accessed as a dword - the row is "
     "typed later)"),
    ("0x003fdd8e", "j1939_anti_theft_send_status_report_cal",
     "cm848_sendPgn56320AntiTheftStatus sends the anti-theft status only while it is set"),
    ("0x003fdd90", "j1939_anti_theft_status_of_request_cal",
     "bits 7-6 of the PGN 56320 status byte; j1939_receivePgn56576Handler sets 3"),
    ("0x003fdd7a", "current_horsepower_peak_fueling_cal",
     "the maximum fueling of the two active fueling curves; cm848_runPowerTakeOffGovernorPid scales by it (block 117F is "
     "aligned: +4 trip distance, +10 cruise maximum road speed and +12..+24 the anti-theft words match their code)"),
    ("0x003fdd7c", "cruise_maximum_road_speed_cal",
     "the maximum cruise reference speed: the cruise speed limit logic sets it to its default or the limit, and it is "
     "sent x 161 / 100 (km/h) in a J1939 cruise message"),
    ("0x0005c37e", "engine_retarder_configuration_maximum_speed",
     "PGN 65249 bytes 6-7, maximum retarder speed (point 2), in cm848_buildPgn65249RetarderConfigurationMessage"),
]
FUNCTIONS = [
    ("0x00023be0", "cm848_sendPgn56320AntiTheftStatus",
     "Sends the J1939 anti-theft status (PGN 56320) while j1939_anti_theft_send_status_report_cal is set and the "
     "transmit state is 2: the status byte from the status of request / component status / password valid / seed "
     "present bits and the encryption seed"),
    ("0x00023cd4", "cm848_initializePgn56320AntiTheftStatusBuffer",
     "Builds the transmit descriptor of the anti-theft status (header 0xdc2800, PGN 56320)"),
    ("0x00024b64", "cm848_initializePgn65234Dm10Handler",
     "Builds the transmit descriptor of DM10 (header 0xfed200, PGN 65234 - DM10 in the J1939 database)"),
    ("0x000233a0", "cm848_j1939HandlePgn56832Reset",
     "Receives J1939 PGN 56832 (Reset) via the Bank-2 receive table 0x3fd414: byte 1 = 0x20 sets the oil change "
     "monitor reset flag, 0x30 sets new_tires_installed_flag_cal"),
]
QUOTE_OVERRIDE = {
    "0x003faa88": "cm848_sendJ1939ProprietaryStatus: _j1939_pgn56360_prop_status_snapshot = _governor_prop_status_byte_b; (rendered with _: the row is typed word, the access is a dword)",
    "0x003fdd86": "cm848_sendJ1939ProprietaryStatus: _j1939_pgn56360_prop_status_snapshot = _governor_prop_status_byte_b; (rendered with _: typed word, accessed as a dword)",
}
