"""Round 27 stage C (label-only): the J1939 input descriptor's third field is a logical switch number, not a fault bit
index (cm848_evaluateJ1939InputSignalFault indexes the switch-input arrays with it). Verified in the code and the
flash2 table (0x53a278, 17 x 10 bytes) after a peer's read-only review pointed at it; the user approved the
CLAUDE.md correction."""
TYPES = {"j1939_input_signal_descriptor_t": "j1939_input_signal_descriptor_t"}   # identity: a field-only rename
INSTANCES = {}
FIELDS = {"j1939_input_signal_descriptor_t": {"fault_bit_index": (
    "logical_switch",
    "The logical switch (0-31) this input drives: cm848_evaluateJ1939InputSignalFault indexes "
    "switch_input_datalink_source_bits_cal / switch_input_source_priority / j1939_switch_input_default_state_bits "
    "with it and sets / clears its switch_input_datalink_state_bits bit through "
    "cm848_setDatalinkSwitchStateIfPriority / cm848_clearDatalinkSwitchStateIfPriority (received 1 sets / 0 clears; "
    "2 / 3 or a timeout apply the default bit). Table values: brake switch 11 / clutch switch 15 / PTO on 3 / remote "
    "PTO 19 / accelerator interlock 26 / the other 12 inputs 31 (the unwired switch)")}}
FIELD_NOTES = {}
