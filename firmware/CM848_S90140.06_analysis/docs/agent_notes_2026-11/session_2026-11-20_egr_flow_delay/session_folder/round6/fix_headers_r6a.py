"""Round 6 stage A: the '#' header lines and the two data rows the scripted refresh could not reach.
usage: fix_headers_r6a.py <CM848 output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "structure_definitions.csv": [
        ("# Passed as param_1 to all J1939 RX handlers (torqueControlModeHandler,",
         "# Passed as param_1 to all J1939 RX handlers (processEngineTsc1Request,"),
        ("# ETC1 Message Buffer - parsed J1939 ETC1 (Torque/Speed Control) message data\n"
         "# Populated by j1939ProcessTorqueSpeedControl when ETC1 messages arrive\n"
         "# Total size: 32 bytes (0x003fa982-0x003fa9a1)",
         "# J1939 powertrain messages received (j1939_powertrain_messages_received; round 6: was etc1_message_t /\n"
         "#   j1939_tsc1_received): the ETC1 bytes (cm848_j1939ProcessPgn61442Etc1), the ETC2 bytes at +0x10\n"
         "#   (cm848_j1939ProcessPgn61445Etc2) and the engine TSC1 bytes (processEngineTsc1Request)\n"
         "# Total size: 32 bytes (0x003fa982-0x003fa9a1)"),
        ("# ETC1 / Governor State Block - combined ETC1 handler and governor control state\n"
         "# Used by cm848_j1939ProcessTorqueSpeedControl, torqueControlModeHandler,\n"
         "#   cm848_processEngineRetarderTsc1Request (was cm848_j1939ProcessGovernorRequest), cm848_processGovernorModeTransition",
         "# J1939 powertrain control state (j1939_powertrain_control_state; round 6: was etc1_governor_state_t /\n"
         "#   j1939_tsc1_override_state): the engine TSC1 override, the engine retarder TSC1 timers, the ETC1 status\n"
         "#   flags with their timers, the ETC2 selected gear and the output shaft speed fault hold-off\n"
         "# Used by processEngineTsc1Request, cm848_j1939ProcessPgn61442Etc1, cm848_runTsc1LostManagement,\n"
         "#   cm848_processEngineRetarderTsc1Request, cm848_runJ1939PowertrainControlTimeouts"),
        ("# ETC1 Config Table Entry (DAT_0005c3b4 - 10 entries x 20 bytes, ROM/Bank1)\n"
         "# Search loop: match_key + source_address_filter select the active config entry\n"
         "# Pointer stride: etc1_config_entry_ptr advances by 10 shorts (20 bytes) per iteration\n"
         "# activation_confirm_timeout: loaded at offset+6 (mode1) or offset+10 (mode2); mode3 hardcodes 0",
         "# TSC1 source configuration entry (tsc1_source_configuration_table at 0x5c3b4: 10 entries x 20 bytes, Bank 2\n"
         "#   flash; round 6: was etc1_config_entry_t). cm848_findTsc1SourceConfiguration selects the sender's entry by\n"
         "#   data_link + source_address_filter, 20 bytes per entry\n"
         "# The time limits: speed_control_time_limit (+6, mode 1) and torque_control_time_limit (+0xa, mode 2);\n"
         "#   mode 3 has none"),
    ],
    "enums.csv": [
        ("# Used as local 'control_mode' in torqueControlModeHandler and stored in governor_mode field",
         "# Used as local 'control_mode' in processEngineTsc1Request and stored in\n"
         "#   j1939_powertrain_control_state.tsc1_override_control_mode"),
    ],
    "global_variables.csv": [
        ("\n0x00022f1c,accept_etc1_command,,\n", "\n0x00022f1c,accept_tsc1_command,,\n"),
        ("j1939_powertrain_messages_received_t.etc1_output_shaft_speed_previous",
         "j1939_powertrain_messages_received.etc1_output_shaft_speed_previous"),
    ],
}
only = sys.argv[2:] or list(EDITS)
for name, edits in EDITS.items():
    if name not in only:
        continue
    p = os.path.join(out, name)
    text = open(p).read()
    for old, new in edits:
        assert text.count(old) == 1, (name, old[:70], text.count(old))
        text = text.replace(old, new)
    open(p, "w").write(text)
    print(name, len(edits), "edits")
