# J2 investigator run 2: the short role / discriminator / plate comment of each function for the compact result
# (the long forms stay in result_full.json). address -> (role, discriminator, plate_comment)
TEXTS = {
    "0x1fdc0": (
        "With the J1922 monitor enabled, records one ended engine control period of the given mode (1 speed / 2 torque / 3 limit): the counts + 1 and key_on_hour_meter stamps.",
        "The only writer of the e2m 1101 JC22* records 0x804164-0x80417b (0x1fd6c only clears them); it reads the J1922 monitor bit 0x80, not the J1939 monitor bit 0x800.",
        "Records one ended engine control period for the J1922 monitor (algorithm_enable_flags_2_cal.j1922_monitor_enable, e2m JC22MRSW): for control mode 1 (speed) / 2 (torque) / 3 (limit) it adds 1 to the total count 0x804164 (e2m 1101 JC22CU) and to the mode's count and stores key_on_hour_meter in the mode's time and the last control time 0x804166. Called when a J1922 request changes and, without a network type test, whenever cm550_resetEngineTsc1Request ends a request. CM848 has no counterpart."),
    "0x1ff38": (
        "Runs the two J1939 periodic transmit queues once per 10 ms: calls the builder of every entry whose next tick is due, adds its interval, then advances the queue's tick.",
        "The only code that walks the entry tables 0x80096e / 0x800a36 and calls their builders; the other reader of the J1939 enable bit (0x212b2) drains the receive ring.",
        "The 10 ms J1939 periodic transmit scheduler, second call of the odd frame task set 0x1b504. With algorithm_enable_flags_11_cal.j1939_communication_enable set it runs queue 0 (the engine node: up to 20 10-byte entries at 0x80096e) while bit 2 of the broadcast enable word 0x80aa12 is set (e2m JCEGBCEA) and queue 1 (the retarder node: up to 10 at 0x800a36) while bit 3 is set (JCRDBCEA). CM848's counterpart also tests the DM13 broadcast flags."),
    "0x212b2": (
        "Drains the J1939 CAN receive ring within a time budget: builds each record's PGN key, drops blocked source addresses, calls the registered receive handler, and re-enables the 82527 receive interrupts after the ring was full.",
        "The only reader of the ring pointers 0x80d9b6 / 0x80d9ba and the only code that scans j1939_receive_handler_table; it reads CTM4 0xfff404 and writes the 82527 at 0xffd810 + 16 n, hence mc68k_.",
        "J1939 receive dispatcher, first call of the even frame task set 0x1b4d8. With algorithm_enable_flags_11_cal.j1939_communication_enable set it drains the CAN receive ring (18-byte records at 0x80d72e) for at most 250 CTM4 time base counts: the PGN key is record bytes 1-2 (the PDU specific byte cleared for a PDU1 frame to the engine's address or 0xFF), byte 3 goes to j1939_received_source_address, a source in the blocking table 0x80d9e0 (e2m JCSABLTB) is dropped, otherwise the handler registered in j1939_receive_handler_table gets the record. CM848's counterpart adds the DM13 hook and uses the TouCAN."),
    "0x2142c": (
        "Ends the retarder torque control request when the shift assist is enabled, the transmission holds both the retarder torque control and the engine speed control, and the user fueling has reached the limit.",
        "Of the three readers of the shift assist bit 0x1000 it is the periodic one: it compares fuel_demand_selected with 0x8089a8, writes only the retarder request state and parses no message.",
        "With algorithm_enable_flags_2_cal.j1939_retarder_shift_assist_enable set (e2m JCRDTXEA), the retarder in torque control (mode 2) from the transmission (control device 1) and the engine in speed control (mode 1) from the transmission, it ends the retarder request once the user fueling fuel_demand_selected (e2m FSDSFL) reaches the limit 0x8089a8 (JCEBSILM): retarder mode 0, torque limit 125, 0x80da8e / 0x80da90 cleared. First call of the odd frame task set 0x1b504. Twin of CM848 0x50aec0."),
    "0x216c6": (
        "PGN 61184 service 0x45: parameter ID from request bytes 1-2, a 4-byte length from bytes 3-6, the data written at the ID's address (offset 0).",
        "Of the four write-by-parameter-ID handlers the one with a 4-byte length at data + 3 and offset 0; registered for service 0x45.",
        "PGN 61184 service 0x45 (registered by registerJ1939MemoryWriteServices): request bytes 1-2 the parameter ID and 3-6 the length, then the data - written at the ID's address (offset 0) through writeJ1939DiagnosticMemoryByParameterId. Twin of CM848 0x50b298."),
    "0x21778": (
        "PGN 61184 service 0x49: parameter ID from bytes 1-2, a 4-byte offset from 3-6 and a 4-byte length from 7-10, the data written at the ID's address + offset.",
        "Of the four write-by-parameter-ID handlers the one with three copies (2 bytes at data + 1, 4 at + 3, 4 at + 7); registered for service 0x49.",
        "PGN 61184 service 0x49 (registered by registerJ1939MemoryWriteServices): request bytes 1-2 the parameter ID / 3-6 the offset / 7-10 the length, then the data - written at the ID's address + offset through writeJ1939DiagnosticMemoryByParameterId. Twin of CM848 0x50b38c."),
    "0x21872": (
        "Registers the six PGN 61184 memory write service handlers (0x44, 0x45, 0x4b, 0x4d, 0x47, 0x49) with registerJ1939DiagnosticService.",
        "Its six registrations are exactly the memory write services; the other registrars called by mc68k_initializeJ1939Datalink register other service IDs.",
        "From mc68k_initializeJ1939Datalink: registers the PGN 61184 memory write services 0x44 / 0x45 / 0x4b / 0x4d / 0x47 / 0x49 (handlers 0x2167e / 0x216c6 / 0x217de / 0x21826 / 0x21714 / 0x21778) with registerJ1939DiagnosticService. Twin of CM848 0x50b4d8: the same six services in the same order."),
    "0x21920": (
        "Builds the J1939 DM1 / DM2 lamp status byte from the commanded lamp driver bits of the output byte 0x80bcf6.",
        "It only reads the byte 0x80bcf6 and returns the lamp status bits 0x40 / 0x10 / 0x04 / 0x01; no other input, no store.",
        "Builds the DM1 / DM2 lamp status byte from the lamp driver command byte 0x80bcf6 (e2m 000E +28): 0x40 malfunction indicator and 0x01 protect for bit 4 (MLLP / LCEGPNLP), 0x10 red stop for bit 1 (LCSPLPEA), 0x04 amber warning for bit 6 (LCWNLPEA). Called by j1939HandlePgn65226Dm1ActiveDtc and cm550_previousDtcListBuilder. CM848's counterpart reads four lamp flags."),
    "0x21f4e": (
        "Copies the 24-byte active engine or retarder session record into the next entry of the five-entry J1939 history table; the next-entry index wraps from 4 to 0.",
        "The only code that addresses the history table 0x80417e and the next-entry word 0x804232; its argument picks the record (0 engine, else retarder).",
        "Files a finished J1939 control session in the history table (e2m 10FD JCHSTB: 5 entries of 24 bytes at 0x80417e): copies the 12 words of the engine record 0x8041f8 (session_kind 0) or the retarder record 0x804212 into the entry numbered by 0x804232 (e2m 1100 +8 JCHSTBPO), which counts up and wraps from 4 to 0. Called by trackJ1939ControlSessions. Twin of CM848 0x50be6c."),
    "0x21fac": (
        "Opens an engine (argument 0) or retarder J1939 control session: status 1, control source = the control device, and the active record filled with kind, source address, device, one mode, start time and duration 0.",
        "The only writer of 1 to the status words 0x80422a / 0x80422c and the only code that initializes a whole active record; the tracker only appends modes and stores the duration.",
        "Opens a J1939 control session record. session_kind 0: the engine control status 0x80422a = 1 (e2m 1100 +0 JCEGCOSS), the control source 0x80422e = the control device 0x80da4e, and the record 0x8041f8 (e2m 10FE JCAEEG) gets kind 0, the source address, the device, one mode (the engine control mode 0x80da50), the start time key_on_hour_meter and duration 0. Any other kind: the same for the retarder (0x80422c / 0x804230 / record 0x804212, kind 1). Twin of CM848 0x50beec."),
    "0x22070": (
        "J1939 monitor: compares the engine and retarder control mode / network / source address with the last pass, opens a session record when a J1939 control starts, appends each new mode, and on its end stores the duration and files the record.",
        "The reader of the J1939 monitor bit 0x800; the only code that uses the previous-value words 0x800b12-0x800b19 and appends modes to the active records.",
        "J1939 monitor (algorithm_enable_flags_2_cal.j1939_monitor_enable, e2m JC39MREA), third call of the even frame task set 0x1b4d8: a control that starts on network 1 opens a session record (startJ1939ControlSession), each new mode from the same source is appended to the record's five mode words, and when the control ends or the source changes it stores the duration, clears the control status and files the record (storeJ1939ControlSessionInHistoryTable). Twin of CM848 0x50bff4."),
    "0x231da": (
        "Ends the engine's datalink control request: mode, control device and speed control status to 0, the ended mode recorded as a J1922 control occurrence, the request timeout and time limit timers cleared.",
        "The engine-side reset: it clears 0x80da50 / 0x80da4e / 0x80da60 / 0x80da80 / 0x80da7e and calls the recorder; its sibling 0x23216 clears the retarder's words and calls nothing.",
        "Ends the engine's datalink control request (a J1939 TSC1 request or a J1922 command): keeps the control mode in 0x801982, sets the mode 0x80da50, the control device 0x80da4e and the speed control status 0x80da60 to 0, records the ended mode with cm550_recordJ1922ControlOccurrence and clears the request timeout 0x80da80 and the time limit timer 0x80da7e. Called by cm550_runJ1939PowertrainControlTimeouts on a timeout or time limit. CM848 has cm848_runTsc1LostManagement at those call sites."),
    "0x23244": (
        "Counts down the datalink powertrain control timers each pass: ends the high idle override and the shift / out of gear flags, ends the engine and retarder requests on a timeout or time limit, and counts timeouts toward the link timeout faults.",
        "The only code that decrements the timers 0x80da7e-0x80da94 and uses the previous-value words 0x801982-0x801990; it alone sets the link timeout fault bits (word 7 mask 0x8, word 5 mask 0x400).",
        "Runs the datalink powertrain control timers, second call of the even frame task set 0x1b4d8: the high idle override (time limit, timeout, recovery), the progressive shift disable and out of gear flags, the retarder zero torque timer, the J1939 vehicle speed timers, and the request timeout and time limit of the engine and the retarder control request (J1939 and J1922 alike). A timeout counts toward the J1708 (0x804266) or J1939 (0x804268) link timeout fault; a new request asks for that fault to be cleared. Counterpart of cm848_runJ1939PowertrainControlTimeouts."),
    "0x23216": (
        "Ends the engine retarder control request: mode off, control device none, torque limit 125 and four timer / flag words cleared.",
        "The retarder-side reset: seven stores (mode, device, limit, 0x80da84, 0x80da82, 0x80da8e, 0x80da90) and no call.",
        "Ends the engine retarder control request: retarder_control_mode off, the control device 0x80d9e6 none, the torque limit 0x80d9ee 125 (no limit), and the request timeout 0x80da84, the time limit timer 0x80da82, the zero torque timer 0x80da8e and the word 0x80da90 cleared. Called three times by cm550_runJ1939PowertrainControlTimeouts. Twin of CM848 0x27118: the same seven stores in the same order."),
    "0x21642": (
        "Resolves a parameter ID to its address and writes the request's data at address + offset through writeJ1939DiagnosticMemory; an unknown ID returns 8.",
        "The shared worker of the four write-by-parameter-ID services: one ID lookup, the constant 8, one call of the memory writer.",
        "Writes by parameter ID for the PGN 61184 services 0x44 / 0x45 / 0x47 / 0x49: resolves the ID with cm550_lookupParameterIdAddress (8 = unknown ID), then writeJ1939DiagnosticMemory(request / the ID's address + offset / length). Parameters: the request / the ID / the offset / the length. Twin of CM848 0x50b1b8."),
    "0x238ac": (
        "Appends an 8-byte entry (network type, source address, control mode, countdown = the recovery time) to the engine ignored request list of at most 5 entries.",
        "It writes the list 0x801994 (count byte 0x8019d0) from three arguments; the retarder appender 0x238ec writes the 4-byte list from one.",
        "Appends an entry (network type word, source address, control mode, countdown = the recovery time 0x808188) to the engine ignored request list (8-byte entries at 0x801994, at most 5, count byte 0x8019d0). cm550_runJ1939PowertrainControlTimeouts calls it when a speed or torque control request reaches its time limit; the request handlers then ignore that sender and mode until the entry expires. CM848's counterpart holds 10 entries."),
    "0x238ec": (
        "Appends a 4-byte entry (source address, countdown = the recovery time) to the retarder ignored request list of at most 5 entries.",
        "It writes the 4-byte list 0x8019bc (count byte 0x8019d1) from one argument; the engine appender 0x238ac writes the 8-byte list from three.",
        "Appends an entry (source address, countdown = the recovery time 0x808188) to the retarder ignored request list (4-byte entries at 0x8019bc, at most 5, count byte 0x8019d1). cm550_runJ1939PowertrainControlTimeouts calls it when the retarder torque control request reaches its time limit; cm550_retarderControlModeHandler then ignores that sender until the entry expires. CM848's counterpart has 6-byte entries with the control mode."),
    "0x2167e": (
        "PGN 61184 service 0x44: parameter ID from request bytes 1-2, a 1-byte length from byte 3, the data written at the ID's address (offset 0).",
        "Of the four write-by-parameter-ID handlers the one with a single-byte length at data + 3 and offset 0; registered for service 0x44.",
        "PGN 61184 service 0x44 (registered by registerJ1939MemoryWriteServices): request bytes 1-2 the parameter ID and 3 the length, then the data - written at the ID's address (offset 0) through writeJ1939DiagnosticMemoryByParameterId. Twin of CM848 0x50b228."),
    "0x21714": (
        "PGN 61184 service 0x47: parameter ID from bytes 1-2, a 2-byte offset from 3-4 and a 1-byte length from 5, the data written at the ID's address + offset.",
        "Of the four write-by-parameter-ID handlers the one with a 2-byte offset from data bytes 3-4 and a single-byte length at 5; registered for service 0x47.",
        "PGN 61184 service 0x47 (registered by registerJ1939MemoryWriteServices): request bytes 1-2 the parameter ID / 3-4 the offset / 5 the length, then the data - written at the ID's address + offset through writeJ1939DiagnosticMemoryByParameterId. Twin of CM848 0x50b300."),
    "0x1fd6c": (
        "With the J1922 monitor clear enabled, zeroes the eight J1922 occurrence records once the last control time + the clear occurrence time is before key_on_hour_meter.",
        "The only code that clears the JC22* records and the only reader of 0x808190; it reads the clear enable bit 0x100, not the monitor bit 0x80 of 0x1fdc0.",
        "Clears the J1922 monitor's records when they are old: with algorithm_enable_flags_2_cal.j1922_monitor_clear_enable set (e2m JC22CCSW) and the last control time 0x804166 (JC22TM) + the clear occurrence time 0x808190 (JC22CCTM) before key_on_hour_meter, it zeroes the eight records that cm550_recordJ1922ControlOccurrence writes. Called by the task set 0x1b6d6. Nothing in it concerns J1939 or a timeout; CM848 has no counterpart."),
    "0x142a8": (
        "Returns the control device code of a source address: 1 for the transmission source address, 2 for the anti-lock brake address, 3 for the anti-slip regulation address, else 4.",
        "A pure lookup: one byte compared with the low bytes of three calibration words, four constant results, no store; it configures no CAN bus.",
        "Returns the J1939 control device of a source address (e2m JCEGCOID / JCRDCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN'): 1 for the low byte of the transmission source address 0x60f82 (e2m 10E3 +4 JCTRSA), 2 for the ABS address 0x60f84 (JCABSA), 3 for the ASR address 0x60f86 (JCARSA), else 4. processEngineTsc1Request stores it in 0x80da4e, cm550_retarderControlModeHandler in 0x80d9e6. Twin of CM848 0x53a4c."),
    "0x23820": (
        "Searches the engine ignored request list for the given network type, source address and control mode; when found it reloads the entry's countdown and returns 1, else 0.",
        "Of the list's functions the one that compares all three key fields and writes only the countdown; it validates no diagnostic message.",
        "Searches the engine ignored request list (8-byte entries at 0x801994, count byte 0x8019d0) for the entry with network type param 1, source address param 2 and control mode param 3: when found it reloads the countdown with the recovery time 0x808188 and returns 1, else 0. processEngineTsc1Request and the J1922 command handlers 0x1f4e8 / 0x1f8bc call it first and ignore the request on 1. Twin of CM848 0x53c68."),
    "0x23870": (
        "Searches the retarder ignored request list for the given source address; when found it reloads the entry's countdown and returns 1, else 0.",
        "It walks the 4-byte list 0x8019bc and compares one byte; the engine list's 0x23820 compares three fields of 8-byte entries.",
        "Searches the retarder ignored request list (4-byte entries at 0x8019bc, count byte 0x8019d1) for the entry with source address param 1: when found it reloads the countdown with the recovery time 0x808188 and returns 1, else 0. cm550_retarderControlModeHandler ignores the request on 1. CM848's counterpart also matches the control mode in 6-byte entries."),
    "0x23920": (
        "Counts every entry of the engine and retarder ignored request lists down by 1 and removes each entry that reaches 0 (the last entry moves into its place).",
        "The only code that decrements the entry countdowns; it walks both lists from the last entry down and takes no argument.",
        "Counts down the two ignored request lists once per pass, third call of the odd frame task set 0x1b504: each entry's countdown (word +6 of the 8-byte engine entries at 0x801994, word +2 of the 4-byte retarder entries at 0x8019bc) drops by 1; an entry at 0 is removed - the count byte drops and the last entry is copied into its place. CM848's counterpart also clears its blocked message bits."),
    "0x239d2": (
        "Removes every engine ignored request list entry whose network type and source address equal the two arguments (the last entry moves into the gap).",
        "Of the list's functions the one that matches two fields (word 0 and byte 2, not the mode) and removes; it initializes nothing.",
        "Removes the engine ignored request list entries (8-byte entries at 0x801994, count byte 0x8019d0) with network type param 1 and source address param 2, whatever their control mode: the count drops and the last entry is copied into the gap. processEngineTsc1Request calls it when that sender sends control mode 0, the J1922 command handlers when they accept a mode 1 / 2 / 3 command. Twin of CM848 0x53fa8."),
    "0x23a3c": (
        "Removes every retarder ignored request list entry whose source address equals the argument (the last entry moves into the gap).",
        "It walks the 4-byte list 0x8019bc and matches one byte; the engine list's remover 0x239d2 matches two fields of 8-byte entries.",
        "Removes the retarder ignored request list entries (4-byte entries at 0x8019bc, count byte 0x8019d1) with source address param 1: the count drops and the last entry is copied into the gap. cm550_retarderControlModeHandler calls it when that sender sends control mode 0. CM848's counterpart has 6-byte entries."),
}
