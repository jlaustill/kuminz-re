"""Round 28 stage A (label-only): the boot CAN ring state struct (was can_tx_ring_t: it holds the receive ring too)."""
TYPES = {"can_tx_ring_t": "can_ring_state_t"}
INSTANCES = {"j1939_can_ring_buf": ("0x003024c6", "boot_can_ring_state", "can_tx_ring_t")}
FIELDS = {"can_tx_ring_t": {
    "j1939_tx_write_ptr": ("transmit_write_pointer",
                           "Transmit ring write pointer: 12-byte frames from 0x3022e6; mpc555_canTransmitQueuePush "
                           "stores a frame and advances it"),
    "j1939_tx_read_ptr": ("transmit_read_pointer",
                          "Transmit ring read pointer: mpc555_manageCan1TransmitBuffer sends the frame there and "
                          "advances it (wrapping after 0x3024ba)"),
    "can_rx_write_ptr": ("receive_write_pointer",
                         "Receive ring write pointer: 18-byte records from 0x302016 (mpc555_processCanReceiveBuffer)"),
    "can_rx_read_ptr": ("receive_read_pointer", "Receive ring read pointer (mpc555_dispatchCanMessageHandlers)"),
    "toucan_mb_ptr": ("transmit_message_buffer_pointer",
                      "The transmit message buffer: mpc555_initDiagnosticSubsystem sets it to TouCAN A buffer "
                      "0x3070f0 + 16 x n; the empty-ring path of mpc555_manageCan1TransmitBuffer clears its control byte"),
}}
FIELD_NOTES = {}
