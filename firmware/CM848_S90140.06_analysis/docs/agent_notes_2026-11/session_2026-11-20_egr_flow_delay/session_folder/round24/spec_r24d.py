"""Round 24 stage D: struct type and field renames for the instances of worklist_r24d.py."""
TYPES = {"fault_list_state_t": "j1587_fault_count_data_t",
         "diag_session_state_t": "boot_sci_session_state_t",
         "data_transfer_state_t": "reflash_transfer_state_t",
         "j1939_tp_queue_t": "j1939_transport_transmit_session_t",
         "sys_init_flags_t": "system_initialization_flags_t"}
INSTANCES = {
    "fault_list_state_t_003fe11a": ("0x003fe11a", "j1587_fault_count_data_cal", "fault_list_state_t"),
    "diag_session_state_t_003fecbe": ("0x003fecbe", "boot_sci_session_state", "diag_session_state_t"),
    "data_transfer_state_t_003fec82": ("0x003fec82", "reflash_transfer_state", "data_transfer_state_t"),
    "j1939_tp_queue_t_00302905": ("0x00302905", "boot_j1939_transport_transmit_session", "j1939_tp_queue_t"),
    "sys_init_flags_t_00302736": ("0x00302736", "system_initialization_flags", "sys_init_flags_t"),
}
TP = "mpc555_sendJ1939TransportRequestToSend"
FIELDS = {
    "fault_list_state_t": {
        "write_index": ("active_fault_count",
                        "e2m 1097 +C0 J1587_Fault_Count_Data 'Data used by J1587 and Fault Handler to keep track of "
                        "fault counts': the number of faults in active_dtc_list_cal - it moves with "
                        "active_dtc_list_cal.count and active_dtc_cummins_fault_codes_cal[0], and the list code indexes "
                        "the slots with it. No ring buffer write index"),
        "read_index": ("previously_active_fault_count",
                       "The number of faults in previously_active_dtc_list_cal (it moves with its count and "
                       "previously_active_dtc_cummins_fault_codes_cal[0]). No ring buffer read index"),
    },
    "j1939_tp_queue_t": {
        "session_pgn": ("transported_pgn",
                        f"The PGN of the transported message (its PDU format byte and data page; {TP} masks the low "
                        "byte), compared with each clear-to-send"),
        "queue_status2": ("total_packet_count",
                          f"(message_size - 1) / 7 + 1, set by {TP}; TP.CM byte 4 of the request-to-send"),
        "range_start": ("next_packet_number",
                        "The next packet number (TP.CM clear-to-send byte 3, recorded by "
                        "mpc555_handleJ1939TransportClearToSend); mpc555_sendJ1939TransportDataPackets adds 15 per "
                        "call"),
        "queue_ptr": ("granted_packet_count",
                      "The packets left in the granted window (TP.CM clear-to-send byte 2); 0 at the request-to-send, "
                      "15 less per data packet call"),
        "_pad5": ("frame_queue_status",
                  "The status mpc555_canTransmitQueuePush writes through its fourth argument (0x30290a) for the last "
                  "frame: 0 queued / 1 no data / 4 queue full; the senders test it. No padding"),
        "total_bytes": ("message_size",
                        f"The transported message's size in bytes (its header data_length; TP.CM bytes 2-3), set by "
                        f"{TP}"),
        "data_buf_ptr": ("message_data_pointer",
                         "The transported message's data (the message record's data pointer)"),
        "state_ptr": ("session_status_pointer",
                      "Points at the message's status byte (the message record's last dword): 0x12 while the data "
                      "transfer runs, 6 on a timeout"),
        "retry_timer": ("timeout_timer",
                        "Counted down by mpc555_sendJ1939TransportDataPackets while no window is granted; 0x37 after "
                        "the request-to-send and each clear-to-send, 0x70 after a window; at 0 the session status "
                        "becomes 6 (timeout)"),
        "can_header": ("frame_can_id",
                       "The CAN identifier of the next frame: the message's with PDU format 0xEC (TP.CM, PGN 60416) "
                       "for the request-to-send, then 0xEB (TP.DT, PGN 60160)"),
        "packet_size": ("frame_data_length",
                        "Data bytes of the next frame: 8, or what is left for the last data packet"),
        "tx_buf_ptr": ("transmit_frame_pointer",
                       "The frame assembly buffer the senders fill (0x30306D)"),
    },
    "sys_init_flags_t": {
        "init_sentinel": ("initialization_sentinel",
                          "0xBBBB, stored by mpc555_systemInitialization (the boot service loop); no reader in the "
                          ".cpp"),
        "init_counter": ("initialization_counter",
                         "0, stored by mpc555_systemInitialization; no reader in the .cpp"),
    },
}
FIELD_NOTES = {"fault_list_state_t": {
    "emission_count": "It counts the active faults whose fault_definition_t.definition_flags bit 0x2000 is clear - "
                      "every slot in this calibration, so it equals active_fault_count. Only these count updates test "
                      "the bit, so 'emission' is unproven",
    "total_emission_faults": "It counts the previously active faults whose definition_flags bit 0x2000 is clear - "
                             "every slot in this calibration, so it equals previously_active_fault_count; 'emission' "
                             "is unproven",
}}
