"""Round 94: write overrides_r94.json - the hand decisions for applying the judged batches (each with its reason):
- 0x80da50: J2's tsc1_override_control_mode over F1's datalink_engine_control_mode (CM848's field name for the same
  record, e2m 10E8 +4 JCEGMD);
- D1's three task set names: dropped (round 93 named the task sets by their schedule slot);
- J2's structs (proven by J2's judge from every access; layouts from the investigator's note 4):
  j1939_periodic_transmit_entry_t (10), engine_tsc1_ignored_request_t (8), and the 4-byte retarder entry as
  cm550_retarder_tsc1_ignored_request_t (CM848's retarder entries are 6 bytes: the layout differs, so a cm550_
  type); j1939_control_session_t comes from CM848 with its two enums (copy_twin_types_r94.py);
- the rows inside J2's new instances, removed and mapped to their fields.
usage: make_overrides_r94.py <out.json>"""
import json
import sys

R = "PR #53 round 94"
o = {
    "global|CM550|0x0080da50": {"name": "tsc1_override_control_mode",
                                "reason": "F1 proposed datalink_engine_control_mode and J2 tsc1_override_control_mode for e2m 10E8 +4 JCEGMD; CM848 keeps the same record as j1939_powertrain_control_state.tsc1_override_control_mode, so the shared name wins"},
    "function|0x0001b754": {"drop": True, "reason": "an executive frame task set, named by its schedule slot in round 93 (cm550_runEvery20FramesTaskSetPhase1)"},
    "function|0x0001b788": {"drop": True, "reason": "an executive frame task set, named by its schedule slot in round 93 (cm550_runEvery20FramesTaskSetPhase3)"},
    "function|0x0001b7f2": {"drop": True, "reason": "an executive frame task set, named by its schedule slot in round 93 (cm550_runEvery20FramesTaskSetPhase11)"},
    "global|CM550|0x008019bc": {"type": "cm550_retarder_tsc1_ignored_request_t[5]",
                                "reason": "the 4-byte CM550 entry differs from CM848's 6-byte retarder entry: a cm550_ type"},
    "structs": {"CM550": {
        "j1939_periodic_transmit_entry_t": [
            ["pgn_key", "word", 2, "the PGN key of the periodic message (J2: the queue entry's +0)"],
            ["interval_ticks", "word", 2, "the transmit interval in 10 ms ticks"],
            ["next_tick", "word", 2, "the tick of the next transmission"],
            ["builder", "pointer", 4, "the address of the message's builder function"],
        ],
        "engine_tsc1_ignored_request_t": [
            ["data_link", "word", 2, "the network the request came on (the data link compared by findTsc1SourceConfiguration)"],
            ["source_address", "byte", 1, "the source address of the ignored TSC1 request"],
            ["reserved_3", "byte", 1, "no access"],
            ["control_mode", "word", 2, "the override control mode of the ignored request"],
            ["countdown", "word", 2, "counts down; the entry is removed at 0"],
        ],
        "cm550_retarder_tsc1_ignored_request_t": [
            ["source_address", "byte", 1, "the source address of the ignored retarder TSC1 request"],
            ["reserved_1", "byte", 1, "no access"],
            ["countdown", "word", 2, "counts down; the entry is removed at 0 (CM848's retarder entry is 6 bytes)"],
        ],
    }},
    "struct_sizes": {"CM550": {"j1939_periodic_transmit_entry_t": 10, "engine_tsc1_ignored_request_t": 8,
                               "cm550_retarder_tsc1_ignored_request_t": 4}},
    "remove_globals": {"CM550": {
        "0x008041fc": "j1939_active_engine_control_session.override_control_mode_count",
        "0x00804216": "j1939_active_retarder_control_session.override_control_mode_count",
        "0x00801998": "engine_tsc1_ignored_request_entries[0].control_mode",
        "0x0080199a": "engine_tsc1_ignored_request_entries[0].countdown",
        "0x008019a2": "engine_tsc1_ignored_request_entries[1].countdown",
        "0x008019a6": "engine_tsc1_ignored_request_entries[2].source_address",
        "0x008019aa": "engine_tsc1_ignored_request_entries[2].countdown",
        "0x008019ab": "",
        "0x008019ac": "engine_tsc1_ignored_request_entries[3].data_link",
        "0x008019ad": "",
        "0x008019b2": "engine_tsc1_ignored_request_entries[3].countdown",
        "0x008019b4": "engine_tsc1_ignored_request_entries[4].data_link",
        "0x008019b6": "engine_tsc1_ignored_request_entries[4].source_address",
        "0x008019b8": "engine_tsc1_ignored_request_entries[4].control_mode",
        # J1 (judge: 'the removals in the investigator's notes are required and exact'):
        # 0x808158 is one word (e2m 12FE +0 MXMOPZ, read as a word at 13 sites); 0x808159 is its low byte
        "0x00808159": "j1939_input_source_priority._1_1_",
        # 0x807d5e and 0x807d6a are dword[3] masks (XOR-ed with the three switch words); the rows inside are elements
        "0x00807d60": "",
        "0x00807d62": "switch_input_polarity_bits[1]",
        "0x00807d64": "",
        "0x00807d66": "switch_input_polarity_bits[2]",
        "0x00807d6e": "",
        # F1: 0x8000d7 has no reference (no absolute operand; 0x8000d6's users are word-wide: clr.w / move.w #4
        # through a1 at 0xc2d6 / 0xc2e8, or.w at 0xc31c), so 0x8000d6 can be the word it is
        "0x008000d7": "",
    }},
}
# J1: e2m 12A8 is 80 bytes at 0x80bd4a (the next block, 128E, is at 0x80bd9a): one client priority byte per switch;
# the 56 rows 0x80bd4b-0x80bd98 are its elements
for offset in range(1, 0x4f):
    o["remove_globals"]["CM550"][f"0x{0x80bd4a + offset:08x}"] = f"switch_input_source_priority[{offset}]"
o["global|CM550|0x008000d6"] = {"type": "word", "reason": "F1's judge: every access is word wide; the unreferenced row 0x8000d7 inside it is removed"}
# D1: the argument record of cm550_tableLookup2D (0x35088), layout read from its code ((a2) / 2(a2) / 6(a2) / 8(a2) /
# 0xa(a2) / 0xe(a2) / 0x10(a2) / 0x14(a2)); the axes and the grid are word tables (the first axis word is its byte count)
o["structs"]["CM550"]["table_lookup_2d_arguments_t"] = [
    ["x_axis_offset", "word", 2, "the byte offset of the last x axis point found; cached, written back by cm550_tableLookup2D"],
    ["x_axis_pointer", "word*", 4, "the x axis table (its first word is the byte count)"],
    ["x_input", "word", 2, "the x input value"],
    ["y_axis_offset", "word", 2, "the byte offset of the last y axis point found; cached, written back"],
    ["y_axis_pointer", "word*", 4, "the y axis table (its first word is the byte count)"],
    ["y_input", "word", 2, "the y input value"],
    ["z_values_pointer", "word*", 4, "the grid of z values, one row of x points per y point"],
    ["no_interpolation_flag", "word", 2, "nonzero: the lookup returns the grid value without interpolating"],
]
o["struct_sizes"]["CM550"]["table_lookup_2d_arguments_t"] = 22
# D1's two new enums: the idle shutdown state word ISST (0x80d674, word accesses) and the serial EEPROM driver's
# write state (0x801a8a, clr.l at 0x2693a)
o["new_enums"] = {"CM550": {"IDLE_SHUTDOWN_STATE": 2, "EEPROM_BYTE_WRITE_STATE": 4}}
o["global|CM550|0x00800010"] = {"type": "table_lookup_2d_arguments_t", "force_type": True,
                                "reason": "D1's judge: the 22-byte argument record (pea 0x800010 at 0xad1c / 0xad52, filled at 0xaf80-0xafac); round 93's typing pass had made its first word a 'word'"}
o["global|CM550|0x00801a8a"] = {"type": "EEPROM_BYTE_WRITE_STATE", "force_type": True,
                                "reason": "D1's judge: the serial EEPROM driver's write state (clr.l at 0x2693a; the driver step switches on it), not a can_buffer_setup_t"}
o["remove_globals"]["CM550"].update({
    # D1: 0x800000 is one i32 (move.l at 0xadd8 / 0xae18, tst.l at 0xae1e); 0x800002 is its low word (move.w at 0xae4a)
    "0x00800002": "duty_cycle_monitor_load_ratio._2_2_",
    # 0x800006 is one dword (long accesses only: move.l at 0xb002, cmp.l at 0xac8c ...); 0x800008 has no reference
    "0x00800008": "",
    # the rows inside the two 22-byte lookup records (no DMA is involved)
    "0x00800012": "duty_cycle_monitor_steady_state_fueling_lookup.x_axis_pointer",
    "0x00800014": "",
    "0x00800016": "duty_cycle_monitor_steady_state_fueling_lookup.x_input",
    "0x0080001a": "duty_cycle_monitor_steady_state_fueling_lookup.y_axis_pointer",
    "0x0080001c": "",
    "0x00800020": "duty_cycle_monitor_steady_state_fueling_lookup.z_values_pointer",
    "0x00800022": "",
    "0x0080002a": "",
    "0x0080002e": "duty_cycle_monitor_transient_fueling_lookup.y_axis_offset",
    "0x00800032": "",
    "0x00800036": "duty_cycle_monitor_transient_fueling_lookup.z_values_pointer",
    # the serial EEPROM driver's state replaces the can_buffer_setup_t instance at 0x801a8a
    "0x00801a8c": "",
    "0x00801a90": "",
    # the long term map counters (dword[51]): eight unreferenced rows inside
    "0x008054a6": "", "0x008054a8": "", "0x008054ac": "", "0x008054ae": "",
    "0x008054b2": "", "0x008054b4": "", "0x008054b8": "", "0x008054ba": "",
})
json.dump(o, open(sys.argv[1], "w"), indent=1)
print("overrides written:", len(o), "keys")
