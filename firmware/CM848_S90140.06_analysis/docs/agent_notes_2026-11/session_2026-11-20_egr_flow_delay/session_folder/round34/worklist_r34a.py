"""Round 34 stage A: the application J1939 transport's function names and the broadcast delay flag (labels)."""
GLOBALS = [
    ("0x003fbdc4", "j1939_broadcast_no_packet_delay_flag",
     "1 while a broadcast (BAM) transport session for PGN 65535 runs (initiateJ1939TransportProtocol sets it when the "
     "descriptor's PDU format and PDU specific bytes are both 0xff): its packets then go out with no delay instead "
     "of the 5-pass packet delay. cm848_sendJ1939BroadcastDataPacket clears it when a session ends (was "
     "j1939_tp_bam_session_active: it is not set for other broadcasts; PR #53 round 34)"),
]
FUNCTIONS = [
    ("0x0050d2c0", "cm848_sendJ1939BroadcastDataPacket",
     "Sends the next data packet (TP.DT) of broadcast (BAM) session record param_1 (0 = j1939_source_address / 1 = "
     "j1939_engine_retarder_source_address) once its packet delay timer reaches 0: the packet number plus up to 7 "
     "data bytes from the record's advancing data pointer. The last packet ends the session. The message status "
     "becomes 0x11 while the session runs / 5 after the last packet / the send result if the frame fails. The delay "
     "is 5 service passes / 0 while j1939_broadcast_no_packet_delay_flag is set (was "
     "j1939_transport_singleFrame_send; PR #53 round 34)"),
    ("0x0050d444", "cm848_sendJ1939ConnectionModeDataPackets",
     "Sends the data packets (TP.DT) that the last clear to send granted the connection mode (RTS / CTS) transmit "
     "session: up to 10 per call / status 0x13 after each. Then it waits up to 0x70 passes for the next clear to "
     "send. With no window granted it counts the timeout down and ends the session with status 6 at 0 / a frame "
     "that fails to send ends it with status 7 (was j1939_transport_dataFrame_bulkSend; PR #53 round 34)"),
    ("0x0050d60c", "cm848_serviceJ1939TransportSessions",
     "The application J1939 transport's periodic service: sends the next packet of each active broadcast session "
     "record (cm848_sendJ1939BroadcastDataPacket 0 / 1) / runs the connection mode transmit session "
     "(cm848_sendJ1939ConnectionModeDataPackets) / ages the receive session's timeout "
     "(j1939_transport_timeout_decrement) (was phase_group_a_triggerControllerUpdates; PR #53 round 34)"),
    ("0x0050d700", "cm848_initializeJ1939Transport",
     "Points the transport's frame buffers (the two broadcast session records' at 0x3fbdb4 / 0x3fbdbc / the "
     "connection mode transmit session's at 0x3fbde7 / the receive data buffer at 0x3fbe09) and registers the PGN "
     "60416 (TP.CM) and 60160 (TP.DT) receive handlers j1939_transport_dispatchConnectionManagement / "
     "j1939_transport_handleDataPacket (was j1939_pgn_handler_init_ec00eb00; PR #53 round 34)"),
]
