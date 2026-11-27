"""Describer J2 (read-only on the repository): assembles the final answer as JSON in this scratch folder and checks
that no suggested name is used twice.  usage: build_answer.py <out.json>"""
import collections
import json
import sys

R = []


def row(address, role, discriminator, name, confidence, cm848=""):
    R.append({"address": address, "role": role, "discriminator": discriminator, "suggested_name": name,
              "confidence": confidence, "cm848_counterpart": cm848})


# ---------------------------------------------------------------------------------------------- functions
row("0x0001fdc0",
    "J1922 monitor counter with one word argument, a datalink control mode. Only while bit 0x80 of "
    "algorithm_enable_flags_2_cal (e2m JC22MRSW, J1922 monitor enable) is set: mode 1 / 2 / 3 adds 1 to the control "
    "count 0x804164 (e2m 1101 +0 JC22CU) and to that mode's count 0x804170 (speed, JC22RPCU) / 0x804176 (torque, "
    "JC22TQCU) / 0x80416a (limit, JC22LMCU), and stores key_on_hour_meter in that mode's time long 0x804172 / 0x804178 "
    "/ 0x80416c and in the last-control time 0x804166 (JC22TM); any other mode changes nothing.",
    "The only code that increments or stamps the e2m block 1101 cells and the only reader of bit 0x80. Its neighbour "
    "0x1fd6c (bit 0x100, monitor clear enable) zeroes the same eight cells once 0x804166 + 0x808190 (JC22CCTM) is "
    "below key_on_hour_meter. It keeps per-mode counts and last times only; records with source, mode list and "
    "duration are the J1939 monitor's (0x22070). Call sites: 0x231da passes the mode it ends with no network test; "
    "0x23244 passes the previous mode on a mode / network / source change only when the previous network type "
    "0x801984 is 0 (J1922) - so a J1939 control that ends by timeout or time limit is counted too.",
    "cm550_recordJ1922ControlOccurrence", "high",
    "none - CM848's algorithm_enable_flags_2_t keeps both bits ('no reader in this build'), its labelled e2m has no "
    "block 1101 record, and the frozen CM848 decompilation has no reader of j1922_monitor_enable.")

row("0x0001ff38",
    "J1939 periodic transmit scheduler. With J1939 communication enabled (algorithm_enable_flags_11_cal mask 8): when "
    "bit 2 (mask 4) of the broadcast enable word 0x80aa12 (e2m 102E JCEGBCEA, J1939/71 engine broadcast) is set it "
    "walks the 10-byte entries at 0x80096e (count byte 0x800a9a) and, for each entry whose next-due tick (+4) equals "
    "the tick word 0x800a9c, adds the entry's period (+2) to the next-due tick and calls the entry's function pointer "
    "(+6), then adds 1 to the tick; bit 3 (mask 8, JCRDBCEA retarder broadcast) does the same for the entries at "
    "0x800a36 (count 0x800a9b, tick 0x800a9e).",
    "The transmit side: it only compares ticks and calls the due message builders through the entry pointers; no "
    "received frame, control mode or timer is read. Besides the registration helper 0x1fe84 (queue 0 holds 20 entries, "
    "queue 1 holds 10; it stores milliseconds / 10 as period and first tick, so one call = 10 ms) it is the only user "
    "of the two tables. RAM dump: 17 engine entries (PGN 65265 every 10 ticks, 61444 every 2, 61443 every 5, 65226 "
    "every 100 ...) and 2 retarder entries (PGN 61440, 65249). Second call of the odd-phase task set 0x1b504.",
    "cm550_runJ1939PeriodicTransmitQueues", "high",
    "cm848_runJ1939PeriodicTransmitQueues @ 0x538d3c - counterpart, not twin: the same two loops over the same 10-byte "
    "entry layout (queue 0 = 20 entries, queue 1 = 10, the two count bytes and the two tick words right after the "
    "tables in the same order), but CM848 also requires j1939_dm13_broadcast_enable_flags bit 2 / bit 3 for each "
    "queue (CM550 has no DM13 test), and CM848 runs it in phase group A (even phases) while CM550 runs it in the "
    "odd-phase set.")

row("0x000212b2",
    "J1939 receive dispatcher. With J1939 communication enabled (algorithm_enable_flags_11_cal mask 8) it drains the "
    "CAN receive ring of 18-byte records (read pointer 0x80d9ba, write pointer 0x80d9b6; the read pointer wraps past "
    "0x80d884 to 0x80d72e) while fewer than 250 counts of the CTM4 time base word 0xfff404 have passed since entry and "
    "the ring is not empty or its overflow flag 0x80d9bf is 1. Per record: the key word is bytes 1-2 (PDU format, PDU "
    "specific) - the specific byte is zeroed for format 0 when it is the engine node address (0x80da01), the retarder "
    "node address (0x80da0b) or 0xFF, and for formats 1-0xEF when it is the engine node address or 0xFF; byte 3 goes "
    "to j1939_received_source_address; a source listed in the 4 bytes at 0x80d9e0 (0xFE ends the list) is skipped; "
    "otherwise the first j1939_receive_handler_table entry with that key is called with the record. If the overflow "
    "flag was 1 it clears it and, with interrupts masked, writes 0xFB to the byte at 0xffd810 + 16 x object for each "
    "82527 message object from the transmit object + 1 to the last receive object (the bytes "
    "mc68k_queueCanCs4ReceiveMessage wrote 0xF7 / 0xFD to when the ring filled).",
    "The receive side: the only user of the ring's read pointer and the only caller of the handlers in "
    "j1939_receive_handler_table (filled by registerJ1939ReceiveHandler 0x21272); it reads an MC68336 register (CTM4 "
    "time base) and writes the chip-select 82527. First call of the even-phase task set 0x1b4d8.",
    "mc68k_dispatchJ1939ReceivedMessages", "high",
    "cm848_dispatchJ1939ReceivedMessages @ 0x538ef4 - counterpart: the same ring walk (18-byte records), key rule, "
    "4-byte source skip list ended by 0xFE, table scan and first place in the 10 ms J1939 task set (phase group A), "
    "but CM848 budgets 9 counts of TBLr >> 7, also calls cm848_onJ1939Dm13SeenOnBus for PDU format 0xDF, and after an "
    "overflow sets TouCAN IMASK bits instead of 82527 message object bytes.")

row("0x0002142c",
    "When bit 0x1000 of algorithm_enable_flags_2_cal (e2m JCRDTXEA, J1939 retarder shift assist enable) is set, the "
    "retarder control mode 0x80d9e4 is 2 with the retarder control device 0x80d9e6 = 1 (transmission), the engine "
    "control mode 0x80da50 is 1 with the engine control device 0x80da4e = 1, and fuel_demand_selected (0x80ded2) is "
    "at or above the limit word 0x8089a8 (e2m 10FC +2 JCEBSILM), it ends the retarder request: mode 0, "
    "retarder_torque_percent (0x80d9ee) = 125, and the words 0x80da8e and 0x80da90 cleared.",
    "The only function of the family that reads the shift assist bit and compares the user fueling with JCEBSILM. It "
    "makes four of the seven stores of the full retarder reset 0x23216 (it leaves the control device word and the two "
    "request timers 0x80da84 / 0x80da82) and is driven by fueling, not by a timer. First call of the odd-phase task "
    "set 0x1b504.",
    "endRetarderShiftAssistAboveFuelDemandLimit", "high",
    "cm848_endRetarderShiftAssistAboveFuelDemandLimit @ 0x50aec0 - twin (disassembly of both): the same six tests in "
    "the same order with the same constants (mask 0x1000, mode 2, device 1, mode 1, device 1, skip while demand < "
    "limit) and the same four stores in the same order (mode 0, torque limit 125, then two cleared words that sit at "
    "the same offsets of the timer cluster: CM550 0x80da8e / 0x80da90 = CM848 retarder_tsc1_zero_torque_request_timer "
    "/ retarder_tsc1_speed_control_flag). Call graph: in both it is followed directly by the periodic transmit "
    "scheduler; CM848 runs the pair in phase group A, CM550 in the odd-phase set.")

row("0x000216c6",
    "PGN 61184 service 0x45 handler (registered by 0x21872): copies request data bytes 1-2 into a word (the parameter "
    "ID) and bytes 3-6 into a long (the length), then calls 0x21642 with (request, ID, offset 0, length), which writes "
    "the data that follows the header at the ID's address.",
    "Of the four write-by-parameter-ID handlers it is the one with a 4-byte length and no offset: 0x2167e (service "
    "0x44) takes a 1-byte length with offset 0, 0x21714 (0x47) a 2-byte offset and a 1-byte length, 0x21778 (0x49) a "
    "4-byte offset and a 4-byte length.",
    "handleJ1939WriteByParameterIdLongLengthService", "high",
    "cm848_handleJ1939WriteByParameterIdLongLengthService @ 0x50b298 - twin: the same two copies (2 bytes from data + "
    "1, 4 bytes from data + 3), offset 0, the same helper call, registered for service 0x45 at the same place of the "
    "registration list.")

row("0x00021778",
    "PGN 61184 service 0x49 handler (registered by 0x21872): copies request data bytes 1-2 into a word (the parameter "
    "ID), bytes 3-6 into a long (the offset) and bytes 7-10 into a long (the length), then calls 0x21642 with "
    "(request, ID, offset, length), which writes the data that follows the header at the ID's address + offset.",
    "The widest of the four write-by-parameter-ID handlers: a 4-byte offset and a 4-byte length (0x21714, service "
    "0x47, takes a 2-byte offset and a 1-byte length; 0x2167e / 0x216c6 take no offset).",
    "handleJ1939WriteByParameterIdLongOffsetService", "high",
    "cm848_handleJ1939WriteByParameterIdLongOffsetService @ 0x50b38c - twin: the same three copies (2 bytes from data "
    "+ 1, 4 from + 3, 4 from + 7) and the same helper call, registered for service 0x49 as the last entry of the "
    "registration list in both.")

row("0x00021872",
    "Registers six PGN 61184 memory write services with registerJ1939DiagnosticService (0x2ee62) in this order: 0x44 "
    "-> 0x2167e, 0x45 -> 0x216c6, 0x4b -> handleJ1939WriteMemoryService, 0x4d -> "
    "handleJ1939WriteMemoryLongLengthService, 0x47 -> 0x21714, 0x49 -> 0x21778. Called once, by "
    "mc68k_initializeJ1939Datalink.",
    "It only registers, and only the write services (four by parameter ID, two by address); the services 1-24 are "
    "registered by registerJ1939DiagnosticHandlers (0x11b36).",
    "registerJ1939MemoryWriteServices", "high",
    "cm848_registerJ1939MemoryWriteServices @ 0x50b4d8 - twin (disassembly of both): six calls of the twin "
    "registration helper with the same service numbers 68, 69, 75, 77, 71, 73 in the same order and the corresponding "
    "handlers (two of them already shared names); called from the J1939 start-up function in both.")

row("0x00021920",
    "Builds one status byte from the lamp driver command byte 0x80bcf6 (e2m 000E +28, byte 0 of the output port): bit "
    "4 (e2m MLLP / LCEGPNLP) gives 0x40 and also 0x01, bit 1 (LCSPLPEA, stop lamp) gives 0x10, bit 6 (LCWNLPEA, "
    "warning lamp) gives 0x04. Its two callers, the DM1 builder j1939HandlePgn65226Dm1ActiveDtc and the DM2 builder "
    "cm550_previousDtcListBuilder, store the result as the first payload byte (the J1939-73 lamp status byte: "
    "malfunction indicator 0x40, red stop 0x10, amber warning 0x04, protect 0x01).",
    "A pure mapping: no enable bit, no state, no message send. The same command bit (bit 4) feeds both the malfunction "
    "indicator and the protect lamp.",
    "cm550_buildJ1939LampStatusByte", "high",
    "cm848_buildJ1939LampStatusByte @ 0x50b5b4 - counterpart: the same four output bits in the same order (0x40, 0x10, "
    "0x04, 0x01), the same place in the file (after the two byte swap helpers, before "
    "getJ1939MemoryServiceHeaderLength) and the same DM1 / DM2 callers, but CM848 tests four separate flags "
    "(mil_on_request_flag, stop_fault_lamp_flag, warning_fault_lamp_flag, maintenance_fault_lamp_flag) where CM550 "
    "tests bits 4 / 1 / 6 / 4 of one output byte.")

row("0x00021f4e",
    "Copies one 24-byte control session record (12 words) into the J1939 history table: a byte argument of 0 selects "
    "the active engine record at 0x8041f8, any other value the active retarder record at 0x804212; the destination is "
    "entry (index word 0x804232, e2m 1100 +8 JCHSTBPO) of the table at 0x80417e (24 bytes per entry, e2m 10FD JCHSTB), "
    "and the index is incremented and set back to 0 when it reaches 5.",
    "The only writer of the history table and of its next-entry index. It copies; it reads no control state. 0x21fac "
    "fills the active record and 0x22070 decides when to file it.",
    "storeJ1939ControlSessionInHistoryTable", "high",
    "cm848_storeJ1939ControlSessionInHistoryTable @ 0x50be6c - twin (disassembly of both): read the index, store "
    "index + 1, entry = table + old index x 24, index >= 5 -> 0, argument 0 / non-zero picks the record, a 12-word "
    "copy - the same steps in the same order with the same constants, and the tracker is the only caller in both.")

row("0x00021fac",
    "Opens a control session record. Argument 0: the engine control status word 0x80422a (e2m 1100 +0 JCEGCOSS) = 1, "
    "the engine control source 0x80422e (JCEGCOSA) = the engine control device word 0x80da4e, and the record at "
    "0x8041f8 gets kind byte 0, the source address byte 0x80da70, the device word, mode count 1, first mode = the "
    "engine control mode 0x80da50, four cleared mode words, start time = key_on_hour_meter and duration 0. Any other "
    "argument does the same for the retarder: status 0x80422c = 1, source 0x804230, record at 0x804212 with kind 1, "
    "the low byte 0x80d9e9 of the retarder source address, device 0x80d9e6 and mode 0x80d9e4.",
    "The only code that sets the two control status words to 1 and that writes the kind, source address, device and "
    "start time of the active records; it files nothing and compares nothing.",
    "startJ1939ControlSession", "high",
    "cm848_startJ1939ControlSession @ 0x50beec - twin (disassembly of both): the same stores to the same record "
    "offsets (+0 kind, +1 source address, +2 device, +4 count = 1, +6 first mode, +8..+0xe cleared, +0x10 "
    "key_on_hour_meter, +0x14 = 0) after the same status = 1 and source stores; only the order of the four mode-word "
    "clears is reversed. Same single caller (the tracker).")

row("0x00022070",
    "J1939 monitor, enabled by bit 0x800 of algorithm_enable_flags_2_cal (e2m JC39MREA). Engine half - when the "
    "control mode 0x80da50, the network type 0x80da68 or the source address byte 0x80da70 differs from the copies at "
    "0x800b12 / 0x800b16 / 0x800b18: mode 0 after a non-zero mode on network 1 clears the status 0x80422a, stores "
    "duration = key_on_hour_meter - start and files the record (0x21f4e(0)); a non-zero mode on network 1 opens a "
    "record (0x21fac(0)) when none is open, appends the mode to the open record's five-entry mode list (shifting it "
    "when full) when the source is unchanged, or stores the duration, files the record and opens a new one when the "
    "source changed; a non-zero mode on another network after network 1 clears the status and files the record. "
    "Retarder half: the same for mode 0x80d9e4 and source word 0x80d9e8 against the copies 0x800b14 / 0x800b19, "
    "status 0x80422c and record 0x804212, with no network test. Both halves end by saving the copies.",
    "The decision maker of the J1939 history: the only function gated by bit 0x800 and the only user of the "
    "previous-value copies 0x800b12-0x800b19. It calls 0x21fac and 0x21f4e and changes no control state or timer. "
    "Third call of the even-phase task set 0x1b4d8.",
    "trackJ1939ControlSessions", "high",
    "cm848_trackJ1939ControlSessions @ 0x50bff4 - twin (disassembly of both): the same decision tree branch for "
    "branch (in both the engine close clears the status, then stores the duration, then files; the 'other network' "
    "branch files without a duration; the retarder half has no network test), the same constants (network 1, 5 "
    "modes, arguments 0 / 1), the same order of the five previous-value copies, and the same third place in the 10 "
    "ms J1939 task set (after the receive dispatcher and the control timeouts).")

row("0x000231da",
    "Ends the engine's datalink control request: copies the control mode 0x80da50 to the previous-mode word 0x801982, "
    "clears the mode, the engine control device word 0x80da4e and the speed control status 0x80da60 (e2m JCRPGVSS), "
    "calls the J1922 monitor counter 0x1fdc0 with the saved mode (no network type test here), then clears the request "
    "timeout count 0x80da80 and the time limit timer 0x80da7e.",
    "The engine-side reset. Unlike the retarder reset 0x23216 it stores the old mode for the caller's change test "
    "and reports the ended control to the J1922 monitor; it touches no retarder word. Five call sites, all in "
    "0x23244: request timeout in modes 1 / 2 / 3 and time limit in modes 1 / 2.",
    "cm550_resetEngineTsc1Request", "medium",
    "cm848_runTsc1LostManagement @ 0x26f80 - counterpart: CM848 calls it at the same points of the timeout function "
    "and its reset path makes the same stores in the same order (previous mode kept, mode off, control device none, "
    "speed control flag, timeout count, time limit timer), but CM848 first runs the TSC1 lost management (accelerator "
    "pedal window, torque / speed limit ramps, mode 3), which CM550 does not have, and has no J1922 monitor call. The "
    "suggested name follows the retarder twin's (resetEngineRetarderTsc1Request); the request it ends may also be a "
    "J1922 one.")

row("0x00023216",
    "Ends the engine retarder control request with seven stores and no call: the retarder control mode 0x80d9e4 = 0, "
    "the retarder control device 0x80d9e6 = 0, retarder_torque_percent 0x80d9ee = 125, and the words 0x80da84 "
    "(request timeout count), 0x80da82 (time limit timer), 0x80da8e and 0x80da90 cleared.",
    "The retarder-side reset: no previous-mode store and no monitor call (0x231da does both for the engine). 0x2142c "
    "makes four of these seven stores under the shift assist condition. Three call sites, all in 0x23244.",
    "resetEngineRetarderTsc1Request", "high",
    "cm848_resetEngineRetarderTsc1Request @ 0x27118 - twin (disassembly of both): the same seven stores in the same "
    "order with the same constant 125 (the request timeout count before the time limit timer in both), and the same "
    "three call sites in the timeout function (retarder request timeout in mode 2, time limit in mode 2 after the "
    "ignored-list add, timeout in mode 3).")

row("0x00023244",
    "Runs the datalink (J1922 / J1939) powertrain control timers once per even phase. It counts down the high idle "
    "override timers (a rising edge of high_idle_override_active_flag loads the time limit 0x80da88 with 0x808184 + "
    "1; the timeout 0x80da86 at 1 ends the override; the time limit at 1 ends it, sets the recovery flag 0x80da98 and "
    "loads 0x80da86 with the recovery time 0x808188 + 1), the timer 0x80da8c (at 1 clears 0x80da58, e2m JCPSDB "
    "progressive shift disable), the out of gear timer 0x80da8a (at 1 clears 0x80da56), the retarder timer 0x80da8e "
    "and, for vehicle speed sensor type 4 or 5 (0x803d4a, e2m VSRSSNTY), 0x80da92 (at 1 clears 0x80da6c) and 0x80aa10 "
    "(at 1 clears 0x80aa08) and for type 4 the timer 0x80da94 (at 1 sets bit 0x100 of system error status word 4). "
    "Engine request: while mode / network type / source equal the copies 0x801982 / 0x801984 / 0x801986 it counts "
    "down the request timeout 0x80da80 and the time limit 0x80da7e - a timeout (count 1, modes 1 / 2 / 3) calls the "
    "reset 0x231da, an expired time limit (mode 1; mode 2 only while 0x80da56 is 0) first puts the sender on the "
    "ignored list (0x238ac) - and on a change it reloads the time limit from the sender's configuration (+6 speed / "
    "+0xa torque, + 1; 0 for modes 0 and 3) and, when the previous network type was 0, calls the J1922 monitor counter "
    "with the previous mode. The retarder request is handled the same way (0x80da84 / 0x80da82, reset 0x23216, "
    "ignored list 0x238ec, time limit from +0x10). Last, a timeout in this pass adds 1 to the J1708 (0x804266) or "
    "J1939 (0x804268) link timeout count - at the limit 0x8081fc it sets bit 8 of error status word 7 / bit 0x400 of "
    "word 5 and zeroes the count - while a new or changed request sets that link's request byte (0x801993 / "
    "0x801992), on which a later pass clears the error bit.",
    "The only function that counts these timers down, the only caller of the two resets and of the two ignored-list "
    "adders, and the owner of the two link timeout counts. It reads and writes no fuel demand or fuel limit (the "
    "present name's 'fuel demand limit' matches nothing in the body). Second call of the even-phase task set 0x1b4d8.",
    "cm550_runJ1939PowertrainControlTimeouts", "high",
    "cm848_runJ1939PowertrainControlTimeouts @ 0x2715c - counterpart: the same skeleton in the same order (high idle "
    "override, progressive shift disable, out of gear, retarder timer, vehicle speed sensor type 4 / 5 timers, engine "
    "request, the previous-value saves, retarder request, J1708 then J1939 link fault count / clear) and the same "
    "second place in the task set, but CM848 adds the blocked-message bits, the ETC1 message / ETC2 gear / torque "
    "converter lockup timers, the output shaft speed fault with its hold-off, the timed-out flag and TSC1 lost "
    "management, while only CM550 loads the high idle time limit on the rising edge, requires 'not out of gear' for "
    "the mode 2 time limit and calls the J1922 monitor counter. CM848's name says J1939 although the function also "
    "serves J1922 control in both firmwares.")

# ---------------------------------------------------------------------------------------------- helpers
row("0x00021642",
    "HELPER. Write by parameter ID: looks the word parameter ID up with cm550_lookupParameterIdAddress (0x10e16) and "
    "returns 8 when that fails; otherwise it calls writeJ1939DiagnosticMemory (0x2148a) with the request, the ID's "
    "address + the long offset argument and the long length argument, and returns its result.",
    "The shared tail of the four write-by-parameter-ID handlers 0x2167e / 0x216c6 / 0x21714 / 0x21778. It copies "
    "nothing itself and resolves an address only to write through it, so the present name (memory data copy "
    "resolver) is wrong.",
    "writeJ1939DiagnosticMemoryByParameterId", "high",
    "cm848_writeJ1939DiagnosticMemoryByParameterId @ 0x50b1b8 - twin (disassembly of both): lookup, 8 on failure, "
    "write at address + offset, the same parameters (request, ID, offset, length) and the same four callers; the "
    "lookup callee is each firmware's own (counterparts).")

row("0x000238ac",
    "HELPER. Appends an entry to the engine control ignored-request list at 0x801994 (8-byte entries, count byte "
    "0x8019d0; nothing is stored when the count is 5): the word network type, the byte source address, the word "
    "control mode, and a countdown word loaded from 0x808188 (e2m 10E7 +A JCTMRCTM, the time a time-limited node "
    "must stay silent). 0x23244 calls it when a speed or torque control request reaches its time limit.",
    "The engine list (key = network type + source address + mode). Its siblings on the same list are 0x23820 (find "
    "an entry and reload its countdown), 0x23920 (count down, drop expired entries) and 0x239d2 (remove); the "
    "retarder list's adder is 0x238ec. Nothing in it is I/O control.",
    "addEngineTsc1IgnoredRequestEntry", "high",
    "cm848_addEngineTsc1IgnoredRequestEntry @ 0x53d3c - twin except the capacity constant (disassembly of both): the "
    "same stores to the same entry offsets (+0 word, +2 byte, +4 word, +6 word = the recovery time) in the same "
    "order, called from the same time-limit branches of the timeout function; CM550's list holds 5 entries, CM848's "
    "10 (the same 5 / 10 difference as the shared-name twin findTsc1SourceConfiguration).")

row("0x000238ec",
    "HELPER. Appends an entry to the retarder control ignored-request list at 0x8019bc (4-byte entries, count byte "
    "0x8019d1; nothing is stored when the count is 5): the byte source address and a countdown word loaded from "
    "0x808188 (JCTMRCTM). 0x23244 calls it with the low byte of the retarder source address when a retarder torque "
    "control request (mode 2) reaches its time limit.",
    "The retarder list (key = source address only, no mode, no network type). Its siblings are 0x23870 (find and "
    "reload), 0x23920 (count down) and 0x23a3c (remove). The present name's 'timeout entry' describes the list, not "
    "an I/O control.",
    "cm550_addRetarderTsc1IgnoredRequestEntry", "high",
    "cm848_addRetarderTsc1IgnoredRequestEntry @ 0x53d84 - counterpart: the same job at the same call site, but "
    "CM848's entry is 6 bytes with a control mode word and its function takes (source address, mode), while CM550's "
    "entry is 4 bytes and the function takes the source address only; capacity 5 against 10.")

# ---------------------------------------------------------------------------------------------- globals
G = "GLOBAL "
row("0x00804164", G + "(word; addq.w / clr.w). e2m 1101 +0 JC22CU 'CONTROL COUNT 0 = J1922 HASN'T CONTROLLED': +1 "
    "for every call of 0x1fdc0 with mode 1, 2 or 3; cleared by 0x1fd6c. Now j1939_message_total_timeout_count, which "
    "is wrong (no timeout, not J1939).",
    "The total of the three per-mode counts.", "j1922_control_count", "high",
    "none (CM848's e2m has no block 1101)")
row("0x00804166", G + "(dword; move.l / clr.l). e2m 1101 +2 JC22TM 'ECM TIME OF LAST J1922 CONTROL' (0.2 s counts): "
    "key_on_hour_meter at the last counted control of any mode; 0x1fd6c compares it + 0x808190 with the hour meter. "
    "Now j1939_last_message_hour_meter.",
    "The stamp shared by all modes.", "j1922_control_last_occurrence_time", "high", "none")
row("0x0080416a", G + "(word). e2m 1101 +6 JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT': +1 per call of 0x1fdc0 with "
    "mode 3.", "Mode 3 count.", "j1922_limit_control_count", "high", "none")
row("0x0080416c", G + "(dword). e2m 1101 +8 JC22LMTM 'ECM TIME OF LAST J1922 LIMIT COMMAND': key_on_hour_meter at "
    "the last mode 3 count.", "Mode 3 stamp.", "j1922_limit_control_last_occurrence_time", "high", "none")
row("0x00804170", G + "(word). e2m 1101 +C JC22RPCU 'J1922 SPEED CONTROL MODE COUNT': +1 per call of 0x1fdc0 with "
    "mode 1.", "Mode 1 count.", "j1922_speed_control_count", "high", "none")
row("0x00804172", G + "(dword). e2m 1101 +E JC22RPTM 'J1922 SPEED CONTROL OCC. TIME': key_on_hour_meter at the last "
    "mode 1 count.", "Mode 1 stamp.", "j1922_speed_control_last_occurrence_time", "high", "none")
row("0x00804176", G + "(word). e2m 1101 +12 JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT': +1 per call of 0x1fdc0 with "
    "mode 2.", "Mode 2 count.", "j1922_torque_control_count", "high", "none")
row("0x00804178", G + "(dword). e2m 1101 +14 JC22TQTM: key_on_hour_meter at the last mode 2 count.",
    "Mode 2 stamp.", "j1922_torque_control_last_occurrence_time", "high", "none")
row("0x0080417c", G + "(word, no code reference). The base of e2m 10FD JCHSTB 'J1939 HISTORY TABLE' (type T): it "
    "holds 0x0078 = 120 = 5 x 24 in the RAM dump and in the EEPROM image (offset 0x672); the entries start 2 bytes "
    "later.", "A length word in front of the table, like the two in front of the active records.",
    "j1939_control_session_history_length", "medium",
    "the word at 0x3fead4 (value 0x78), which CM848 has no own row for because it is j1939_input_signal_timeouts[24] "
    "there")
row("0x0080417e", G + "array of 5 records of 24 bytes (to 0x8041f5). The only code access is 0x21f4e, which copies 12 "
    "words to 0x80417e + index x 24 with index 0-4; the EEPROM image holds five records FE FE 00... (empty). Record "
    "layout as proven for the active records.",
    "The finished sessions (ring of five); the two active records feed it.", "j1939_control_session_history",
    "high", "j1939_control_session_history_cal @ 0x3fead6, j1939_control_session_t[5] - the same e2m record 10FD")
row("0x008041f6", G + "(word, no code reference). The base of e2m 10FE JCAEEG 'J1939 ACTIVE ENGINE STRUCTURE': "
    "0x0018 = 24 in the RAM dump and the EEPROM image (offset 0x6ec).",
    "Length word of the active engine record.", "j1939_active_engine_control_session_length", "medium",
    "j1939_active_engine_control_session_length_cal @ 0x3feb4e (0x18 there too)")
row("0x008041f8", G + "24-byte record, every access in 0x21fac / 0x22070 / 0x21f4e through base + offset: +0 byte "
    "kind (0), +1 byte source address, +2 word control device, +4 word mode count (1 to 5), +6 five mode words, +0x10 "
    "dword start time (key_on_hour_meter), +0x14 dword duration. The row datalink_speed_snapshot_mode_count "
    "(0x8041fc) is its +4 field.",
    "The open engine control session.", "j1939_active_engine_control_session", "high",
    "j1939_active_engine_control_session_cal @ 0x3feb50, type j1939_control_session_t (session_kind, "
    "controlling_source_address, control_device, override_control_mode_count, override_control_modes[5], start_time, "
    "duration) - the same layout byte for byte")
row("0x00804210", G + "(word, no code reference). The base of e2m 10FF JCAERD 'J1939 ACTIVE RETARDER': 0x0018 in the "
    "RAM dump and the EEPROM image (offset 0x706).",
    "Length word of the active retarder record.", "j1939_active_retarder_control_session_length", "medium",
    "j1939_active_retarder_control_session_length_cal @ 0x3feb68")
row("0x00804212", G + "24-byte record with the layout of 0x8041f8, kind byte 1; written by 0x21fac(1) and the "
    "retarder half of 0x22070. The row retarder_snapshot_mode_count (0x804216) is its +4 field.",
    "The open retarder control session.", "j1939_active_retarder_control_session", "high",
    "j1939_active_retarder_control_session_cal @ 0x3feb6a (j1939_control_session_t)")
row("0x0080422a", G + "(word). e2m 1100 +0 JCEGCOSS 'J1939 ENGINE CONTROL STATUS 0 = INACTIVE': 0x21fac(0) sets 1, "
    "0x22070 clears it when the engine session closes and tests it for 1.",
    "Engine session open flag.", "j1939_engine_control_active_flag", "high",
    "j1939_engine_control_active_flag_cal @ 0x3feb82")
row("0x0080422c", G + "(word). e2m 1100 +2 JCRDCOSS 'J1939 RETARDER CONTROL STATUS': the retarder twin of 0x80422a.",
    "Retarder session open flag.", "j1939_retarder_control_active_flag", "high",
    "j1939_retarder_control_active_flag_cal @ 0x3feb84")
row("0x0080422e", G + "(word). e2m 1100 +4 JCEGCOSA '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': 0x21fac(0) "
    "copies the engine control device word 0x80da4e into it; nothing else writes it.",
    "Device of the open engine session.", "j1939_engine_control_source", "high",
    "j1939_engine_control_source_cal @ 0x3feb86")
row("0x00804230", G + "(word). e2m 1100 +6 JCRDCOSA: 0x21fac(1) copies the retarder control device word 0x80d9e6 "
    "into it.", "Device of the open retarder session.", "j1939_retarder_control_source", "high",
    "j1939_retarder_control_source_cal @ 0x3feb88")
row("0x00804232", G + "(word). e2m 1100 +8 JCHSTBPO 'POINTER INTO J1939_HISTORY_TABLE': the history entry 0x21f4e "
    "writes next; +1 per filed record, 5 becomes 0.",
    "Ring index, used only by 0x21f4e.", "j1939_control_session_history_next_entry", "high",
    "j1939_control_session_history_next_entry_cal @ 0x3feb8a")
row("0x00800b12", G + "(word). 0x22070's copy of the engine control mode 0x80da50 from its last pass (cmp.w / tst.w, "
    "stored at the end of the engine half).", "Monitor copy, engine mode.",
    "j1939_monitor_engine_override_control_mode_previous", "high",
    "j1939_monitor_engine_override_control_mode_previous @ 0x3fbd6c (the five copies lie in the same order in both)")
row("0x00800b14", G + "(word). 0x22070's copy of the retarder control mode 0x80d9e4 from its last pass.",
    "Monitor copy, retarder mode.", "j1939_monitor_retarder_override_control_mode_previous", "high",
    "j1939_monitor_retarder_override_control_mode_previous @ 0x3fbd6e")
row("0x00800b16", G + "(word). 0x22070's copy of engine_control_network_type 0x80da68 (compared with 1 to tell a "
    "J1939 session to close).", "Monitor copy, network type.", "j1939_monitor_engine_control_data_link_previous",
    "high", "j1939_monitor_engine_control_data_link_previous @ 0x3fbd70")
row("0x00800b18", G + "(byte). 0x22070's copy of the engine control source address byte 0x80da70.",
    "Monitor copy, engine source.", "j1939_monitor_engine_controlling_source_address_previous", "high",
    "j1939_monitor_engine_controlling_source_address_previous @ 0x3fbd72")
row("0x00800b19", G + "(byte). 0x22070's copy of the low byte 0x80d9e9 of the retarder source address; compared "
    "with the whole word 0x80d9e8.", "Monitor copy, retarder source.",
    "j1939_monitor_retarder_controlling_source_address_previous", "high",
    "j1939_monitor_retarder_controlling_source_address_previous @ 0x3fbd73")
row("0x00801982", G + "(word). 0x23244's copy of the engine control mode from its last pass; 0x231da also stores the "
    "mode it ends here, and it is the argument of both 0x1fdc0 calls.", "Timeout function copy, engine mode.",
    "tsc1_override_control_mode_previous", "high", "tsc1_override_control_mode_previous @ 0x3faf34")
row("0x00801984", G + "(word). 0x23244's copy of engine_control_network_type; tested for 0 before the J1922 monitor "
    "call.", "Timeout function copy, network type.", "tsc1_controlling_data_link_previous", "high",
    "tsc1_controlling_data_link_previous @ 0x3faf36")
row("0x00801986", G + "(byte). 0x23244's copy of the engine control source address byte 0x80da70.",
    "Timeout function copy, engine source.", "tsc1_controlling_source_address_previous", "high",
    "tsc1_controlling_source_address_previous @ 0x3faf38")
row("0x00801988", G + "(word). 0x23244's copy of high_idle_override_active_flag (0x80da54); a change to 1 loads the "
    "time limit timer.", "Timeout function copy, high idle override.", "high_idle_override_active_flag_previous",
    "high", "high_idle_override_active_flag_previous (CM848, same place in the copy block)")
row("0x0080198a", G + "(word). 0x23244's copy of the retarder control mode 0x80d9e4.",
    "Timeout function copy, retarder mode.", "engine_retarder_override_control_mode_previous", "high",
    "engine_retarder_override_control_mode_previous (CM848)")
row("0x0080198c", G + "(byte). 0x23244's copy of the low byte 0x80d9e9 of the retarder source address.",
    "Timeout function copy, retarder source.", "engine_retarder_controlling_source_address_previous", "high",
    "engine_retarder_controlling_source_address_previous (CM848)")
row("0x0080198e", G + "(word). 0x23244's copy of 0x80da58 (e2m 10E8 +C JCPSDB, progressive shift disable).",
    "Timeout function copy, progressive shift disable.", "etc1_progressive_shift_disable_previous", "high",
    "etc1_progressive_shift_disable_previous @ 0x3faf3e")
row("0x00801990", G + "(word). 0x23244's copy of driveline_disengaged_flag 0x80da56 (e2m JCOG, out of gear).",
    "Timeout function copy, out of gear.", "etc1_out_of_gear_flag_previous", "high",
    "etc1_out_of_gear_flag_previous @ 0x3faf40")
row("0x00801992", G + "(byte). Set to 1 by 0x23244 when a control request is new or changed on network 1 (and by "
    "every retarder mode 2 / 3 change); while it is 1 and no J1939 timeout happened in the pass, the J1939 link "
    "error bit (status word 5 bit 0x400) is cleared once registered, then the byte. No timeout sets it: the present "
    "name datalink_j1939_timeout_flag says the opposite.",
    "Clear request for the J1939 link fault.", "j1939_link_fault_clear_request_flag", "high",
    "j1939_link_fault_clear_request_flag @ 0x3faf42")
row("0x00801993", G + "(byte). The J1708 twin of 0x801992 (network type not 1; error status word 7 bit 8, count "
    "0x804266). Now datalink_j1708_timeout_flag.",
    "Clear request for the J1708 link fault.", "j1708_link_fault_clear_request_flag", "high",
    "j1708_link_fault_clear_request_flag @ 0x3faf43")
row("0x00800a9a", G + "(byte). Number of entries in the schedule at 0x80096e: 0x1fe84 compares it with 20 and "
    "post-increments it, 0x1ff38 loops to it. 17 in the RAM dump.", "Queue 0 (engine broadcasts) count.",
    "j1939_periodic_queue0_count", "high", "j1939_periodic_queue0_count @ 0x3fd40e")
row("0x00800a9b", G + "(byte). Number of entries in the schedule at 0x800a36 (limit 10). 2 in the RAM dump.",
    "Queue 1 (retarder broadcasts) count.", "j1939_periodic_queue1_count", "high",
    "j1939_periodic_queue1_count @ 0x3fd40f")
row("0x00800a9c", G + "(word). Tick of queue 0: 0x1ff38 compares each entry's next-due tick with it and adds 1 per "
    "call while broadcast bit 2 is set; 0x1fe84 adds it to a new entry's first tick.", "Queue 0 tick.",
    "j1939_periodic_queue0_current_tick", "high", "j1939_periodic_queue0_current_tick @ 0x3fd410")
row("0x00800a9e", G + "(word). Tick of queue 1 (broadcast bit 3).", "Queue 1 tick.",
    "j1939_periodic_queue1_current_tick", "high", "j1939_periodic_queue1_current_tick @ 0x3fd412")
row("0x0080096e", G + "array of 20 entries of 10 bytes (to 0x800a35). Both users agree on the layout: 0x1fe84 writes "
    "+0 word PGN, +2 word period (ms / 10), +4 word next-due tick, +6 pointer to the message builder; 0x1ff38 reads "
    "+4, +2 and calls +6.", "The engine node's broadcast schedule (broadcast enable bit 2).",
    "j1939_periodic_queue0_entries", "medium",
    "the 20 entries at 0x3fd2e2 (no CM848 row; cm848_scheduleJ1939PeriodicMessage / "
    "cm848_runJ1939PeriodicTransmitQueues use the same 10-byte layout)")
row("0x00800a36", G + "array of 10 entries of 10 bytes (to 0x800a99), the layout of 0x80096e.",
    "The retarder node's broadcast schedule (broadcast enable bit 3).", "j1939_periodic_queue1_entries", "medium",
    "the 10 entries at 0x3fd3aa (no CM848 row)")
row("0x0080da7e", G + "(word). Time limit timer of the engine control request: on a mode / network / source change "
    "0x23244 loads it with the sender's speed (+6) or torque (+0xa) control time limit + 1 (0 for modes 0 and 3), "
    "counts it down while the request is unchanged, and at 1 puts the sender on the ignored list and resets the "
    "request; 0x231da clears it. No other reference.",
    "Time limit, not the message timeout (that is 0x80da80).", "tsc1_request_time_limit_timer", "high",
    "j1939_powertrain_control_state.tsc1_request_time_limit_timer (0x40ae20); the timer words 0x80da7e-0x80da94 lie "
    "in the same order as CM848's +0x28..+0x3e")
row("0x0080da8c", G + "(word). The ETC1 handler 0x2efd0 loads it with 0x80818c (e2m JCPSTM) + 1 together with "
    "0x80da58 = 1 and clears both; 0x23244 counts it down and at 1 clears 0x80da58 and the timer.",
    "Timeout of the progressive shift disable flag.", "etc1_progressive_shift_disable_timer", "high",
    "j1939_powertrain_control_state.etc1_progressive_shift_disable_timer (0x40ae2e)")
row("0x0080da98", G + "(word). 0x23244 sets it to 1 when the high idle override time limit expires (and loads the "
    "timeout timer with the recovery time) and clears it when that timer expires; the ETC1 handler 0x2efd0 tests it "
    "and, while it is set, only reloads the recovery time.",
    "Recovery state of the high idle override.", "high_idle_override_recovery_flag", "high",
    "j1939_powertrain_control_state.high_idle_override_recovery_flag (0x40ae4a)")
row("0x00801994", G + "array of 5 entries of 8 bytes (to 0x8019bb), every access in 0x23820 / 0x238ac / 0x23920 / "
    "0x239d2: +0 word network type, +2 byte source address, +4 word control mode, +6 word countdown. The rows "
    "diagnostic_service_state_counter (0x801998), diagnostic_security_access_mode (0x80199a) and the torque_control_* "
    "rows 0x8019a2-0x8019b8 are fields of its entries.",
    "The engine control ignored-request list.", "engine_tsc1_ignored_request_entries", "high",
    "engine_tsc1_ignored_request_entries @ 0x3fb916 (10 entries of the same 8 bytes)")
row("0x008019bc", G + "array of 5 entries of 4 bytes (to 0x8019cf), every access in 0x23870 / 0x238ec / 0x23920 / "
    "0x23a3c: +0 byte source address, +2 word countdown.",
    "The retarder control ignored-request list.", "retarder_tsc1_ignored_request_entries", "high",
    "retarder_tsc1_ignored_request_entries @ 0x3fb966 (10 entries of 6 bytes: CM848 adds a mode word)")
row("0x008019d0", G + "(byte). Entry count of the list at 0x801994 (limit 5). Now io_control_entry_count.",
    "Engine list count.", "engine_tsc1_ignored_request_count", "high",
    "engine_tsc1_ignored_request_count @ 0x3fb9a2")
row("0x008019d1", G + "(byte). Entry count of the list at 0x8019bc (limit 5). Now io_control_timeout_entry_count.",
    "Retarder list count.", "retarder_tsc1_ignored_request_count", "high",
    "retarder_tsc1_ignored_request_count @ 0x3fb9a3")
row("0x0080da4e", G + "(word). e2m 10E8 +2 JCEGCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the device in "
    "control of the engine; 0x2142c tests it for 1, 0x231da clears it, 0x21fac copies it into the session record. Now "
    "the description name source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_da4e.",
    "Engine side (the retarder twin is 0x80d9e6).", "engine_control_device_indicator", "high",
    "engine_control_device_indicator @ 0x40adf6 (the same e2m record)")
row("0x0080d9e6", G + "(word). e2m 10E6 +2 JCRDCOID: the device in control of the retarder; 0x2142c tests it for 1, "
    "0x23216 clears it, 0x21fac copies it. Now source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_d9e6.",
    "Retarder side.", "engine_retarder_control_device_indicator", "high",
    "engine_retarder_control_device_indicator @ 0x40ad5c")
row("0x0080aa12", G + "(word). e2m 102E +0 JCBCFGLC 'bit-mapped parameter indicates protocols/ports broadcast "
    "enabled': 0x1ff38 runs queue 0 on bit 2 (JCEGBCEA, J1939/71 engine broadcast) and queue 1 on bit 3 (JCRDBCEA, "
    "retarder broadcast); bits 0 / 1 are the J1587 / J1922 broadcasts. Now "
    "bit_2_0_15_enables_j1939_71_engine_broadcast_1_on_0_off.",
    "One word for all datalink broadcasts.", "datalink_broadcast_enable_flags", "high",
    "datalink_broadcast_enable_flags @ 0x40adee (the same e2m record)")
row("0x008089a8", G + "(word). e2m 10FC +2 JCEBSILM 'limit to which user fueling is compared to determine if engine "
    "(brakes should be ...)': 0x2142c ends the retarder request once fuel_demand_selected is at or above it.",
    "Read by 0x2142c only in this family.", "engine_retarder_shift_assist_fuel_demand_limit", "high",
    "engine_retarder_shift_assist_fuel_demand_limit @ 0x5c36c (the same e2m record)")
row("0x00808188", G + "(word). e2m 10E7 +A JCTMRCTM 'time that time limited node must be silent': loaded (+ 1) into "
    "the high idle timeout timer when the time limit expires, and the countdown of every ignored-list entry (0x238ac "
    "/ 0x238ec).", "The recovery time of time-limited requests.", "j1939_time_limited_node_recovery_time", "high",
    "j1939_time_limited_node_recovery_time @ 0x5c38c (the same e2m record)")
row("0x008081fc", G + "(word). e2m 10E7 +7E JCTMERLM 'number of timeouts allowed before setting "
    "J1XXX_LINK_NOT_FAST(_ENOUGH_ERROR)': 0x23244 compares both link timeout counts with it (the J1708 one with "
    "limit - 1).", "The limit of both link timeout counts.", "j1939_link_fault_timeout_count_limit", "high",
    "j1939_link_fault_timeout_count_limit @ 0x5c39c (JCTMERLM; CM848 10E7 +1A)")
row("0x00808190", G + "(dword). e2m 10E7 +12 JC22CCTM 'J1922 CLEAR OCCURRENCE TIME: time from last J1922 control "
    "before (clearing)': 0x1fd6c clears the J1922 counts when 0x804166 + this is below key_on_hour_meter.",
    "Used by the clear function only.", "j1922_clear_occurrence_time", "medium",
    "the unnamed ROM word at 0x5c394 (e2m J1922_Clear_Occurrence_Time; no CM848 reader)")
row("0x0080d9e0", G + "byte[4]. The receive dispatcher 0x212b2 compares the received source address with these bytes "
    "(0xFE ends the list) and skips the frame on a match; mc68k_initializeJ1939Datalink fills it with 0xFE; FE FE FE "
    "FE in the RAM dump.",
    "A list of source addresses whose frames are dropped - not accepted.", "j1939_receive_ignored_source_addresses",
    "medium",
    "j1939_receive_source_address_whitelist @ 0x40ad56 is the same record (4 bytes after "
    "j1939_received_source_address in both), but 'whitelist' says the opposite of what both dispatchers do (a "
    "listed source is not dispatched); one corrected name for both is suggested")

E = [
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x44,
     "meaning": "write by parameter ID: 2-byte ID and 1-byte length, then the data (CM848 member "
                "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID; CM550's member is the placeholder SERVICE_44)",
     "evidence": "0x21872 registers 0x2167e for 0x44; 0x2167e copies bytes 1-2, takes byte 3 as the length and calls "
                 "0x21642 with offset 0"},
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x45,
     "meaning": "write by parameter ID with a 4-byte length (CM848 ..._WRITE_BY_PARAMETER_ID_LONG_LENGTH; CM550 "
                "SERVICE_45)",
     "evidence": "0x21872 registers 0x216c6 for 0x45; bytes 1-2 the ID, bytes 3-6 the length, offset 0"},
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x47,
     "meaning": "write by parameter ID at a 2-byte offset with a 1-byte length (CM848 "
                "..._WRITE_BY_PARAMETER_ID_SHORT_OFFSET; CM550 SERVICE_47)",
     "evidence": "0x21872 registers 0x21714 for 0x47; bytes 1-2 the ID, bytes 3-4 the offset, byte 5 the length"},
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x49,
     "meaning": "write by parameter ID at a 4-byte offset with a 4-byte length (CM848 "
                "..._WRITE_BY_PARAMETER_ID_LONG_OFFSET; CM550 SERVICE_49)",
     "evidence": "0x21872 registers 0x21778 for 0x49; bytes 1-2 the ID, bytes 3-6 the offset, bytes 7-10 the length"},
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x4b,
     "meaning": "write memory: 4-byte address and 1-byte length (CM848 ..._WRITE_MEMORY; CM550 SERVICE_4B)",
     "evidence": "0x21872 registers the shared handleJ1939WriteMemoryService (0x217de) for 0x4b"},
    {"enum_name": "J1939_DIAGNOSTIC_SERVICE", "value": 0x4d,
     "meaning": "write memory with a 4-byte length (CM848 ..._WRITE_MEMORY_LONG_LENGTH; CM550 SERVICE_4D)",
     "evidence": "0x21872 registers the shared handleJ1939WriteMemoryLongLengthService (0x21826) for 0x4d"},
    {"enum_name": "TSC1_OVERRIDE_MODE", "value": 1,
     "meaning": "speed control (CM848 TSC1_SPEED_CONTROL; CM550 has no such enum yet)",
     "evidence": "0x1fdc0 counts mode 1 in 0x804170, e2m JC22RPCU 'J1922 SPEED CONTROL MODE COUNT'; 0x23244 loads "
                 "the time limit from the configuration's speed_control_time_limit for mode 1; e2m JCEGMD '1 = "
                 "SPEED'"},
    {"enum_name": "TSC1_OVERRIDE_MODE", "value": 2,
     "meaning": "torque control (CM848 TSC1_TORQUE_CONTROL)",
     "evidence": "0x1fdc0 counts mode 2 in 0x804176, e2m JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT'; 0x23244 loads "
                 "torque_control_time_limit for mode 2; the retarder mode 2 uses retarder_torque_control_time_limit"},
    {"enum_name": "TSC1_OVERRIDE_MODE", "value": 3,
     "meaning": "speed / torque limit control (CM848 TSC1_SPEED_TORQUE_LIMIT)",
     "evidence": "0x1fdc0 counts mode 3 in 0x80416a, e2m JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT'; 0x23244 gives "
                 "mode 3 a timeout but no time limit"},
    {"enum_name": "TSC1_OVERRIDE_MODE", "value": 0,
     "meaning": "no override (CM848 TSC1_OVERRIDE_OFF)",
     "evidence": "the resets 0x231da / 0x23216 and 0x2142c store 0; 0x22070 closes a session when the mode becomes 0; "
                 "e2m JCEGMD '0 = DISABLE'"},
    {"enum_name": "CONTROL_NETWORK", "value": 0,
     "meaning": "J1922 (on the J1708 link) (CM848 CONTROL_NETWORK_J1922)",
     "evidence": "0x23244: a timeout with engine_control_network_type not 1 counts in 0x804266 (e2m JC17TMCU, J1708 "
                 "(J1922) time-outs), and the J1922 monitor counter is called when the previous network type is 0"},
    {"enum_name": "CONTROL_NETWORK", "value": 1,
     "meaning": "J1939 (CM848 CONTROL_NETWORK_J1939)",
     "evidence": "0x23244: a timeout with network type 1 counts in 0x804268 (e2m JC39TMCU); 0x22070 opens J1939 "
                 "session records only for network type 1"},
    {"enum_name": "J1939_CONTROL_DEVICE", "value": 1,
     "meaning": "transmission (CM848 J1939_CONTROL_DEVICE_TRANSMISSION)",
     "evidence": "0x2142c requires 0x80d9e6 = 1 and 0x80da4e = 1 for the retarder shift assist end; e2m JCEGCOID / "
                 "JCRDCOID '1 = TRANS'"},
    {"enum_name": "J1939_CONTROL_DEVICE", "value": 0,
     "meaning": "none (CM848 J1939_CONTROL_DEVICE_NONE)",
     "evidence": "the resets 0x231da / 0x23216 store 0 in 0x80da4e / 0x80d9e6; e2m '0 = NONE'"},
]

NOTES = (
    "1. THE 'ROM TABLE' 0x1b4da-0x1b4e9 IS CODE, NOT A TABLE. 0x1b4d8 is a function made of jsr (abs).l instructions "
    "(opcode 4EB9 + 4-byte target): jsr 0x212b2 / 0x23244 / 0x22070 / 0x230ee / 0x21edc / 0x21070 / 0x420bc / rts. The "
    "hits at 0x1b4da, 0x1b4e0 and 0x1b4e6 are the operands of the first three. Nobody walks it: "
    "executiveFrameInterruptHandler (0x1b876) calls 0x1b4d8 with bsr.w (PC-relative, so no absolute pointer exists) in "
    "each of the 20 even phases of the 40-phase executive, and 0x1b504 (jsr 0x2142c / 0x1ff38 / 0x23920) in each of "
    "the 20 odd phases. The caller scan missed it because two function rows share the name "
    "vp44_evenPhaseSchedulerTaskSet (0x1b4d8 and 0x1b62a, the second a label in the middle of another jsr chain), so "
    "a name-keyed dictionary kept only the second body; the rows 0x1b4ea and 0x1b4f6 are likewise mid-chain labels of "
    "0x1b4d8. 0x1b4d8 is the counterpart of the first six calls of cm848_phase_group_a_processing (0xb7b4: "
    "dispatch / control timeouts / track sessions / transport sessions / input supervision / switch and request "
    "inputs); CM848 then runs endRetarderShiftAssist and the periodic transmit queues in the same group, CM550 in the "
    "odd-phase set. "
    "2. _cal CONFLICT. The J1922 and J1939 monitor cells 0x804164-0x804233 are outside the stated mirror range "
    "0x803B0A-0x804155, so the names above carry no _cal (as j1939_input_signal_timeouts at 0x804234 already does). "
    "But the ECU's parameter ID table tags them EEPROM (0x0100065A-0x01000728), CM848's same records end in _cal, and "
    "J90350.00.eeprom.bin equals the RAM dump at 0x803b0a + offset for all 4096 bytes (history length 0x0078 at "
    "offset 0x672, record lengths 0x0018 at 0x6ec / 0x706, empty records FE FE 00...). The mirror may be longer than "
    "0x64C; the judge decides whether these names get _cal. "
    "3. e2m type T records start with a 2-byte length word: 10FD / 10FE / 10FF resolve to 0x80417c / 0x8041f6 / "
    "0x804210 and the code's data starts 2 bytes later (0x80417e / 0x8041f8 / 0x804212), exactly as in CM848. "
    "4. Types: CM550 has no j1939_control_session_t, TSC1_OVERRIDE_MODE, J1939_CONTROL_DEVICE or CONTROL_NETWORK yet; "
    "CM848's definitions fit CM550's accesses field for field. The byte 0x80d9e9 is the low byte of the existing word "
    "row retarder_command_source_address (0x80d9e8) and needs no row. "
    "5. Siblings outside this batch that the same evidence names (not verified beyond what is quoted): 0x2167e "
    "cm550_j1939DataCopyWrapper2Byte = service 0x44 handler (CM848 cm848_handleJ1939WriteByParameterIdService "
    "0x50b228); 0x21714 cm550_j1939DataCopyWrapperExtended = service 0x47 handler (CM848 "
    "cm848_handleJ1939WriteByParameterIdShortOffsetService 0x50b300); 0x1fd6c cm550_j1939TimeoutDataClearHandler "
    "clears the J1922 monitor counts (bit 0x100) and its row 0x1fd8e is a mid-function label; 0x1fe84 is the "
    "counterpart of cm848_scheduleJ1939PeriodicMessage (0x538c8c); 0x2efd0 cm550_diagnosticServiceDispatcherByPgn is "
    "the ETC1 (PGN 61442, key 0xf002) receive handler that loads the high idle / progressive shift / out of gear "
    "timers; the ignored-list functions 0x23820 / 0x23870 / 0x23920 / 0x239d2 / 0x23a3c stand in the same order as "
    "CM848's refreshEngine / refreshRetarder / (add, add) / processTimeouts / removeEngine / removeRetarder "
    "Tsc1IgnoredRequest functions. "
    "6. Existing CM550 names in the timer cluster that the code contradicts (same order as CM848's "
    "j1939_powertrain_control_state +0x28..+0x3e): 0x80da58 engine_brake_override_flag is e2m JCPSDB progressive "
    "shift disable; 0x80da82 retarder_command_inactivity_timer is the retarder time limit timer (loaded from "
    "retarder_torque_control_time_limit + 1); 0x80da86 high_idle_override_duration_timer is the override's message "
    "timeout (the ETC1 handler loads 0x808182 JCEGOSTM + 1) and 0x80da88 high_idle_overspeed_timeout_timer its time "
    "limit (0x808184 JCEGOSTL + 1). Not named here because this family only counts them down or clears them and "
    "their loaders are not visible through absolute references: 0x80da90 (CM848 position: "
    "retarder_tsc1_speed_control_flag), 0x80da92 / 0x80da6c (etc1_out_of_gear_data_timer / "
    "etc1_out_of_gear_data_valid_flag), 0x80aa10 / 0x80aa08 (etc2_gear_ratio_timeout / etc2_gear_ratio_valid_flag), "
    "0x80da94 datalink_fault_detection_timer (etc1_output_shaft_speed_timer); 0x803d4a is e2m 1180 +10 VSRSSNTY, "
    "CM848 vehicle_speed_sensor_type_cal. "
    "7. Globals are returned as roles rows whose role starts with GLOBAL (the schema has no globals field); helper "
    "rows start with HELPER. Every suggested name was checked against the frozen function_renames / global_variables "
    "/ structure_definitions of both firmwares: the shared twin names are free in both (CM848 holds only the "
    "cm848_-prefixed forms), and the CM550 global names are free in CM550."
)

out = {"batch": "J2", "roles": R, "enum_roles": E, "notes": NOTES}
dup = [n for n, c in collections.Counter(r["suggested_name"] for r in R if r["suggested_name"]).items() if c > 1]
assert not dup, dup
json.dump(out, open(sys.argv[1], "w"), indent=1)
print(len(R), "roles;", len(E), "enum roles; notes", len(NOTES), "chars; longest role", max(len(r["role"]) for r in R))
print("\n".join(r["suggested_name"] for r in R))
