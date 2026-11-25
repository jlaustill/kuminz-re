"""Describer J2, second run (read-only on the repository): assembles the final answer (roles for the 14 functions,
3 helpers, the family's globals, enum roles, notes) into final_answer_v2.json and checks the proposed names
(unique among themselves, free in the frozen CM550 CSVs).  Every row was re-checked in this run; see notes.md."""
import csv
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"

roles = []


def row(address, role, discriminator, name, confidence, counterpart=""):
    roles.append({"address": address, "role": role, "discriminator": discriminator, "suggested_name": name,
                  "confidence": confidence, "cm848_counterpart": counterpart})


# ---------------------------------------------------------------- functions
row("0x0001fdc0",
    "J1922 monitor's occurrence recorder with one word argument, a datalink control mode. Only while bit 0x80 of "
    "algorithm_enable_flags_2_cal (e2m JC22MRSW, J1922 monitor enable) is set: mode 1 / 2 / 3 adds 1 to the total "
    "control count 0x804164 (e2m 1101 +0 JC22CU) and to that mode's count (0x804170 speed JC22RPCU / 0x804176 torque "
    "JC22TQCU / 0x80416a limit JC22LMCU), and stores key_on_hour_meter in that mode's time long (0x804172 / 0x804178 / "
    "0x80416c) and in the last-control time 0x804166 (JC22TM). Any other mode changes nothing.",
    "The only code that increments or stamps the e2m block 1101 cells and the only reader of bit 0x80. Its neighbour "
    "0x1fd6c (bit 0x100, called from the task set at 0x1b6d6) zeroes the same eight cells once 0x804166 + 0x808190 "
    "(JC22CCTM) is below key_on_hour_meter. It keeps a count and a last time per mode only; the records with source, "
    "mode list and duration belong to the J1939 monitor (0x22070). Two call sites: 0x231da passes the mode it ends, "
    "with no network test; 0x23244 passes the previous mode when the request changed and the previous network type "
    "0x801984 was 0 (J1922). It counts no J1939 message type.",
    "cm550_recordJ1922ControlOccurrence", "high",
    "none: CM848's algorithm_enable_flags_2_t marks bits 7 and 8 'no reader in this build', the frozen CM848 "
    "decompilation never reads j1922_monitor_enable, and CM848's labelled e2m has no block 1101 record (only the two "
    "enable bits and J1922_Clear_Occurrence_Time).")

row("0x0001ff38",
    "J1939 periodic transmit scheduler. With J1939 communication enabled (algorithm_enable_flags_11_cal mask 8): "
    "while bit 2 of the broadcast enable word 0x80aa12 (e2m 102E JCEGBCEA, engine broadcast) is set it walks the "
    "10-byte entries at 0x80096e (count byte 0x800a9a) and, for each entry whose next-due tick (+4) equals the tick "
    "word 0x800a9c, adds the entry's period (+2) to the next-due tick and calls the entry's function pointer (+6); "
    "then it adds 1 to the tick. Bit 3 (JCRDBCEA, retarder broadcast) does the same for the entries at 0x800a36 "
    "(count 0x800a9b, tick 0x800a9e).",
    "Transmit side only: it compares ticks and calls the due message builders; it reads no received frame, control "
    "mode or timer, and accumulates no run time histogram. The only other user of the two tables is the registration "
    "helper 0x1fe84 (no function row in the frozen copy; capacity 20 / 10; it stores milliseconds / 10 as period and "
    "first tick, so one call is one 10 ms tick). RAM dump: 17 engine entries (PGN 65265 every 10 ticks, 61444 every "
    "2, 61443 every 5, 65226 every 100 ...) and 2 retarder entries (PGN 61440, 65249). Second call of the odd-phase "
    "task set 0x1b504.",
    "cm550_runJ1939PeriodicTransmitQueues", "high",
    "cm848_runJ1939PeriodicTransmitQueues @ 0x538d3c - counterpart, not twin: the same two loops over the same "
    "10-byte entries (20 + 10 entries, then the two count bytes and the two tick words, in the same order), but "
    "CM848 also requires bit 2 / bit 3 of j1939_dm13_broadcast_enable_flags (CM550 has no DM13 test) and runs it in "
    "phase group A (even phases), CM550 in the odd-phase set.")

row("0x000212b2",
    "J1939 receive dispatcher. With J1939 communication enabled (algorithm_enable_flags_11_cal mask 8) it drains "
    "the CAN receive ring of 18-byte records (read pointer 0x80d9ba, write pointer 0x80d9b6, wrap from past "
    "0x80d884 to 0x80d72e) while fewer than 250 counts of the CTM4 time base 0xfff404 have passed since entry and "
    "the ring is not empty or its full flag 0x80d9bf is 1. Per record: the key word is record bytes 1-2 (PDU "
    "format, PDU specific), with the specific byte zeroed for format 0 when it is the engine node address 0x80da01, "
    "the retarder node address 0x80da0b or 0xFF, and for formats 1-0xEF when it is the engine node address or 0xFF; "
    "byte 3 goes to j1939_received_source_address; a source found in the 4 bytes at 0x80d9e0 (0xFE ends the list) "
    "is skipped; otherwise the first j1939_receive_handler_table entry with that key is called with the record. "
    "When the full flag was 1 it clears it and, with interrupts masked, writes 0xFB to the control byte at "
    "0xffd800 + 16 n of each 82527 message object n from the transmit object + 1 to the last receive object.",
    "Receive side: the only user of the ring's read pointer and the only caller of the handlers stored by "
    "registerJ1939ReceiveHandler (0x21272). It reads an MC68336 register (the CTM4 time base) and writes the "
    "chip-select 82527 (it re-enables what mc68k_queueCanCs4ReceiveMessage switched off with 0xF7 / 0xFD when the "
    "ring filled). First call of the even-phase task set 0x1b4d8; nothing calls it by pointer.",
    "mc68k_dispatchJ1939ReceivedMessages", "high",
    "cm848_dispatchJ1939ReceivedMessages @ 0x538ef4 - counterpart: the same ring walk (18-byte records), key rule, "
    "4-byte source list ended by 0xFE, table scan and first place in the 10 ms J1939 task set, but CM848 budgets 9 "
    "counts of TBLr >> 7, calls cm848_onJ1939Dm13SeenOnBus for PDU format 0xDF, and after a full ring sets TouCAN "
    "IMASK bits instead of 82527 control bytes.")

row("0x0002142c",
    "When bit 0x1000 of algorithm_enable_flags_2_cal (e2m JCRDTXEA, retarder shift assist enable) is set, the "
    "retarder control mode 0x80d9e4 is 2 with the retarder control device 0x80d9e6 = 1, the engine control mode "
    "0x80da50 is 1 with the engine control device 0x80da4e = 1, and fuel_demand_selected (0x80ded2, e2m FSDSFL user "
    "fueling) is at or above the limit 0x8089a8 (e2m 10FC +2 JCEBSILM), it ends the retarder request: mode 0, "
    "retarder_torque_percent 0x80d9ee = 125, and the words 0x80da8e and 0x80da90 cleared.",
    "The only function of this family that tests the shift assist bit and compares the user fueling with JCEBSILM. "
    "It makes four of the seven stores of the full retarder reset 0x23216 (it keeps the control device word and the "
    "two request timers 0x80da84 / 0x80da82) and is triggered by fueling, not by a timer. First call of the "
    "odd-phase task set 0x1b504.",
    "endRetarderShiftAssistAboveFuelDemandLimit", "high",
    "cm848_endRetarderShiftAssistAboveFuelDemandLimit @ 0x50aec0 - twin: the same six tests in the same order with "
    "the same constants (mask 0x1000, mode 2, device 1, mode 1, device 1, demand >= limit; both firmwares use the "
    "e2m records FSDSFL and JCEBSILM) and the same four stores in the same order (mode 0, 125, then two cleared "
    "words at the same places of the timer cluster: CM848 retarder_tsc1_zero_torque_request_timer / "
    "retarder_tsc1_speed_control_flag). In both it runs every 10 ms directly before the periodic transmit "
    "scheduler; CM848 places the pair in phase group A, CM550 in the odd-phase set.")

row("0x000216c6",
    "PGN 61184 service 0x45 handler: copies request data bytes 1-2 into a word (the parameter ID) and bytes 3-6 "
    "into a long (the length), then calls 0x21642 with (request, ID, offset 0, length), which writes the data that "
    "follows the header at the ID's address.",
    "Of the four write-by-parameter-ID handlers it is the one with a 4-byte length and no offset: 0x2167e (service "
    "0x44) takes a 1-byte length and no offset, 0x21714 (0x47) a 2-byte offset and a 1-byte length, 0x21778 (0x49) "
    "a 4-byte offset and a 4-byte length. Reached only through the registration at 0x21886 (pea 0x216c6 with "
    "service 0x45, in 0x21872).",
    "handleJ1939WriteByParameterIdLongLengthService", "high",
    "cm848_handleJ1939WriteByParameterIdLongLengthService @ 0x50b298 - twin: the same two copies (2 bytes from data "
    "+ 1, 4 bytes from data + 3), offset 0, the same helper call, registered for service 0x45 as the second entry "
    "of the registration list in both.")

row("0x00021778",
    "PGN 61184 service 0x49 handler: copies request data bytes 1-2 into a word (the parameter ID), bytes 3-6 into a "
    "long (the offset) and bytes 7-10 into a long (the length), then calls 0x21642 with (request, ID, offset, "
    "length), which writes the data that follows the header at the ID's address + offset.",
    "The widest of the four write-by-parameter-ID handlers: a 4-byte offset and a 4-byte length (0x21714, service "
    "0x47, takes a 2-byte offset and a 1-byte length; 0x2167e / 0x216c6 take no offset). Reached only through the "
    "registration at 0x218b6 (pea 0x21778 with service 0x49, in 0x21872).",
    "handleJ1939WriteByParameterIdLongOffsetService", "high",
    "cm848_handleJ1939WriteByParameterIdLongOffsetService @ 0x50b38c - twin: the same three copies (2 bytes from "
    "data + 1, 4 from + 3, 4 from + 7) and the same helper call, registered for service 0x49 as the last entry of "
    "the registration list in both.")

row("0x00021872",
    "Registers six PGN 61184 memory write services with registerJ1939DiagnosticService (0x2ee62) in this order: "
    "0x44 -> 0x2167e, 0x45 -> 0x216c6, 0x4b -> handleJ1939WriteMemoryService, 0x4d -> "
    "handleJ1939WriteMemoryLongLengthService, 0x47 -> 0x21714, 0x49 -> 0x21778. Called once, at 0x28e4a in "
    "mc68k_initializeJ1939Datalink.",
    "It only registers, and only the write services (four by parameter ID, two by address); the services 1 - 24 "
    "are registered by registerJ1939DiagnosticHandlers (0x11b36), which the start-up function calls directly after "
    "it.",
    "registerJ1939MemoryWriteServices", "high",
    "cm848_registerJ1939MemoryWriteServices @ 0x50b4d8 - twin: six calls of the twin registration helper with the "
    "same service numbers 68, 69, 75, 77, 71, 73 in the same order and the corresponding handlers (two of them "
    "already shared names); in both start-up functions it is the call directly before "
    "registerJ1939DiagnosticHandlers.")

row("0x00021920",
    "Builds one status byte from the lamp driver command byte 0x80bcf6 (e2m 000E +28, byte 0 of the output port): "
    "bit 4 (e2m MLLP / LCEGPNLP) gives 0x40 and also 0x01, bit 1 (LCSPLPEA, stop lamp) gives 0x10, bit 6 (LCWNLPEA, "
    "warning lamp) gives 0x04. Its two callers store the result as the first payload byte (the J1939-73 lamp status "
    "byte: malfunction indicator 0x40, red stop 0x10, amber warning 0x04, protect 0x01) of DM1 "
    "(j1939HandlePgn65226Dm1ActiveDtc, byte 0x801f64; it stores 0 instead when no DTC is active) and of DM2 "
    "(cm550_previousDtcListBuilder, byte 0x80266a).",
    "A pure mapping with no argument: no enable bit, no state, no message send. One command bit (bit 4) feeds both "
    "the malfunction indicator and the protect lamp.",
    "cm550_buildJ1939LampStatusByte", "high",
    "cm848_buildJ1939LampStatusByte @ 0x50b5b4 - counterpart: the same four output bits in the same order (0x40, "
    "0x10, 0x04, 0x01), the same place in the file (after the two byte swap helpers, before "
    "getJ1939MemoryServiceHeaderLength) and the same DM1 / DM2 use, but CM848 tests four separate flags "
    "(mil_on_request_flag, stop_fault_lamp_flag, warning_fault_lamp_flag, maintenance_fault_lamp_flag) where CM550 "
    "tests bits 4 / 1 / 6 / 4 of one output byte.")

row("0x00021f4e",
    "Copies one 24-byte control session record (12 words) into the J1939 history table: a byte argument of 0 "
    "selects the active engine record at 0x8041f8, any other value the active retarder record at 0x804212; the "
    "destination is the entry numbered by the index word 0x804232 (e2m 1100 +8 JCHSTBPO) in the table at 0x80417e "
    "(24 bytes per entry, e2m 10FD JCHSTB); the index is incremented and set back to 0 when it reaches 5.",
    "The only writer of the history table and of its next-entry index. It copies; it reads no control state. "
    "0x21fac fills the active record and 0x22070 decides when to file it (its five call sites are all in 0x22070).",
    "storeJ1939ControlSessionInHistoryTable", "high",
    "cm848_storeJ1939ControlSessionInHistoryTable @ 0x50be6c - twin: read the index, store index + 1, entry = table "
    "+ old index x 24, index >= 5 -> 0, argument 0 / non-zero picks the record, a 12-word copy - the same steps in "
    "the same order with the same constants, and the tracker is the only caller in both.")

row("0x00021fac",
    "Opens a control session record. Argument 0: the engine control status word 0x80422a (e2m 1100 +0 JCEGCOSS) = "
    "1, the engine control source 0x80422e (JCEGCOSA) = the engine control device word 0x80da4e, and the record at "
    "0x8041f8 gets kind byte 0, the source address byte 0x80da70, the device word, mode count 1, first mode = the "
    "engine control mode 0x80da50, four cleared mode words, start time = key_on_hour_meter and duration 0. Any "
    "other argument does the same for the retarder: status 0x80422c = 1, source 0x804230, record at 0x804212 with "
    "kind 1, the low byte 0x80d9e9 of the retarder source address, device 0x80d9e6 and mode 0x80d9e4.",
    "The only code that sets the two control status words to 1 and that writes the kind, source address, device "
    "and start time of the active records; it files nothing and compares nothing. Four call sites, all in 0x22070.",
    "startJ1939ControlSession", "high",
    "cm848_startJ1939ControlSession @ 0x50beec - twin: the same stores to the same record offsets (+0 kind, +1 "
    "source address, +2 device, +4 count = 1, +6 first mode, +8..+0xe cleared, +0x10 key_on_hour_meter, +0x14 = 0) "
    "after the same status = 1 and source stores; only the order of the four mode-word clears is reversed. Same "
    "single caller (the tracker).")

row("0x00022070",
    "J1939 monitor, enabled by bit 0x800 of algorithm_enable_flags_2_cal (e2m JC39MREA). Engine half - when the "
    "control mode 0x80da50, the network type 0x80da68 or the source address byte 0x80da70 differs from the copies "
    "0x800b12 / 0x800b16 / 0x800b18: mode 0 after a non-zero mode on network 1 clears the status 0x80422a, stores "
    "duration = key_on_hour_meter - start and files the record (0x21f4e(0)); a non-zero mode on network 1 opens a "
    "record (0x21fac(0)) when none is open, appends the mode to the open record's five-entry mode list (shifting "
    "it when full) when the source is unchanged, or stores the duration, files the record and opens a new one when "
    "the source changed; a non-zero mode on another network after network 1 clears the status and files the "
    "record. Retarder half: the same for mode 0x80d9e4 and source word 0x80d9e8 against the copies 0x800b14 / "
    "0x800b19, status 0x80422c and record 0x804212, with no network test. Each half ends by saving its copies.",
    "The decision maker of the J1939 history: the only function gated by bit 0x800 and the only user of the "
    "previous-value copies 0x800b12-0x800b19. It calls 0x21fac and 0x21f4e and changes no control state and no "
    "timer; it controls no memory register. Third call of the even-phase task set 0x1b4d8.",
    "trackJ1939ControlSessions", "high",
    "cm848_trackJ1939ControlSessions @ 0x50bff4 - twin (disassembly of both): the same decision tree branch for "
    "branch (the engine close clears the status, then stores the duration, then files; the 'other network' branch "
    "files without a duration; the retarder half has no network test), the same constants (network 1, 5 modes, "
    "arguments 0 / 1), the same order of the five previous-value copies, and the same third place in the 10 ms "
    "J1939 task set (after the receive dispatcher and the control timeouts).")

row("0x000231da",
    "Ends the engine's datalink control request: copies the control mode 0x80da50 to the previous-mode word "
    "0x801982, clears the mode, the engine control device word 0x80da4e and the speed control status 0x80da60 (e2m "
    "JCRPGVSS), calls the J1922 monitor recorder 0x1fdc0 with the saved mode, then clears the request timeout "
    "count 0x80da80 and the time limit timer 0x80da7e.",
    "The engine-side reset. Unlike the retarder reset 0x23216 it saves the old mode and reports the ended control "
    "to the J1922 monitor (with no network type test); it touches no retarder word and no fueling value, and "
    "arbitrates nothing. Five call sites, all in 0x23244: request timeout in modes 1 / 2 / 3 and time limit in "
    "modes 1 / 2.",
    "cm550_resetEngineTsc1Request", "medium",
    "cm848_runTsc1LostManagement @ 0x26f80 - counterpart: CM848 calls it at the same points of the timeout "
    "function and its reset path makes the same stores in the same order (previous mode kept, mode off, control "
    "device none, speed control flag, timeout count, time limit timer), but it first runs the TSC1 lost management "
    "(accelerator pedal window, torque / speed limit ramps, mode 3), which CM550 does not have, and it has no J1922 "
    "monitor call. The suggested name follows the retarder twin (resetEngineRetarderTsc1Request); in CM550 the "
    "request it ends may also be a J1922 one.")

row("0x00023216",
    "Ends the engine retarder control request with seven stores and no call: retarder control mode 0x80d9e4 = 0, "
    "retarder control device 0x80d9e6 = 0, retarder_torque_percent 0x80d9ee = 125, and the words 0x80da84 (request "
    "timeout count), 0x80da82 (time limit timer), 0x80da8e and 0x80da90 cleared.",
    "The retarder-side reset: no previous-mode store and no monitor call (0x231da does both for the engine). "
    "0x2142c makes four of these seven stores under the shift assist condition. Three call sites, all in 0x23244 "
    "(retarder timeout in mode 2, time limit in mode 2 after the ignored-list add, timeout in mode 3).",
    "resetEngineRetarderTsc1Request", "high",
    "cm848_resetEngineRetarderTsc1Request @ 0x27118 - twin: the same seven stores in the same order with the same "
    "constant 125 (the request timeout count before the time limit timer in both), and the same three call sites "
    "in the timeout function.")

row("0x00023244",
    "Runs the datalink (J1922 / J1939) powertrain control timers once per even phase. (1) It counts down the high "
    "idle override timers (a rise of high_idle_override_active_flag loads the time limit 0x80da88 with 0x808184 + "
    "1; the timeout 0x80da86 at 1 ends the override; the time limit at 1 ends it, sets the recovery flag 0x80da98 "
    "and loads 0x80da86 with the recovery time 0x808188 + 1), the timer 0x80da8c (at 1 clears 0x80da58, e2m "
    "JCPSDB), the out of gear timer 0x80da8a (at 1 clears 0x80da56), the retarder timer 0x80da8e and, for 0x803d4a "
    "(e2m VSRSSNTY) = 4 or 5, 0x80da92 (at 1 clears 0x80da6c) and 0x80aa10 (at 1 clears 0x80aa08), and for 4 the "
    "timer 0x80da94 (at 1 sets mask 0x0100 of system error status word 4). (2) Engine request: while mode / "
    "network type / source equal the copies 0x801982 / 0x801984 / 0x801986 it counts down the request timeout "
    "0x80da80 and the time limit 0x80da7e - a timeout (count 1, modes 1 / 2 / 3) calls the reset 0x231da; an "
    "expired time limit (mode 1; mode 2 only while 0x80da56 is 0) first puts the sender on the ignored list "
    "(0x238ac); on a change it reloads the time limit from the sender's configuration (+6 speed / +0xa torque, + "
    "1; 0 for modes 0 and 3) and, when the previous network type was 0, calls the J1922 recorder 0x1fdc0 with the "
    "previous mode. (3) The retarder request likewise (0x80da84 / 0x80da82, reset 0x23216, ignored list 0x238ec, "
    "time limit from +0x10). (4) A timeout in this pass adds 1 to the J1708 (0x804266) or J1939 (0x804268) link "
    "timeout count and, at the limit 0x8081fc, sets mask 0x0008 of system error status word 7 (J1708) or mask "
    "0x0400 of word 5 (J1939) and zeroes the count; a new or changed request instead sets that link's clear "
    "request byte (0x801993 / 0x801992), on which a pass without a timeout clears the error bit.",
    "The only function that counts these timers down, the only caller of the two resets and of the two "
    "ignored-list adders, and the owner of the two link timeout counts. It reads and writes no fuel demand and no "
    "fuel limit (the present name's 'fuel demand limit' matches nothing in the body). Second call of the "
    "even-phase task set 0x1b4d8. The error bits it sets are not the e2m's JC39TMER (word 7 mask 0x01).",
    "cm550_runJ1939PowertrainControlTimeouts", "high",
    "cm848_runJ1939PowertrainControlTimeouts @ 0x2715c - counterpart: the same skeleton in the same order (high "
    "idle override, progressive shift disable, out of gear, retarder timer, vehicle speed sensor type 4 / 5 "
    "timers, engine request, the previous-value saves, retarder request, J1708 then J1939 link fault count / "
    "clear) and the same second place in the task set, but CM848 adds the blocked-message bits, the ETC1 message / "
    "ETC2 gear / torque converter lockup timers, the output shaft speed fault hold-off, the timed-out flag and "
    "TSC1 lost management, while only CM550 loads the high idle time limit on the rising edge, requires 'not out "
    "of gear' for the mode 2 time limit and calls the J1922 recorder. CM848's name says J1939 although the "
    "function also serves J1922 control in both firmwares.")

row("0x00021642",
    "HELPER. Write by parameter ID: looks the word parameter ID up with cm550_lookupParameterIdAddress (0x10e16) "
    "and returns 8 when that fails; otherwise it calls writeJ1939DiagnosticMemory (0x2148a) with the request, the "
    "ID's address + the long offset argument and the long length argument, and returns its result.",
    "The shared tail of the four write-by-parameter-ID handlers 0x2167e / 0x216c6 / 0x21714 / 0x21778 (its only "
    "callers). It copies nothing itself and resolves an address only to write through it, so the present name "
    "(memory data copy resolver) is wrong. The frozen decompilation has no body for it; this is the disassembly "
    "0x21642-0x2167c.",
    "writeJ1939DiagnosticMemoryByParameterId", "high",
    "cm848_writeJ1939DiagnosticMemoryByParameterId @ 0x50b1b8 - twin: lookup, 8 on failure, write at address + "
    "offset, the same parameters (request, ID, offset, length) and the same four callers; the lookup callee is "
    "each firmware's own (counterparts).")

row("0x000238ac",
    "HELPER. Appends an entry to the engine control ignored-request list at 0x801994 (8-byte entries, count byte "
    "0x8019d0; nothing is stored once the count is 5): the word network type, the byte source address, the word "
    "control mode, and a countdown word loaded from 0x808188 (e2m 10E7 +A JCTMRCTM, the time a time-limited node "
    "must stay silent). 0x23244 calls it when a speed or torque control request reaches its time limit.",
    "The engine list (key = network type + source address + mode). Siblings on the same list: 0x23820 (find an "
    "entry and reload its countdown), 0x23920 (count down, drop expired entries), 0x239d2 (remove); the retarder "
    "list's adder is 0x238ec. Nothing in it is an I/O control.",
    "addEngineTsc1IgnoredRequestEntry", "medium",
    "cm848_addEngineTsc1IgnoredRequestEntry @ 0x53d3c - twin except the capacity constant: the same stores to the "
    "same entry offsets (+0 word, +2 byte, +4 word, +6 word = the recovery time) in the same order, called from "
    "the same time-limit branches of the timeout function; CM550's list holds 5 entries, CM848's 10 (the same 5 / "
    "10 difference as the shared-name twin findTsc1SourceConfiguration), and CM848 has one more caller "
    "(cm848_updateParkNeutralFlagAndTsc1Activity). If the capacity rules a twin out: "
    "cm550_addEngineTsc1IgnoredRequestEntry.")

row("0x000238ec",
    "HELPER. Appends an entry to the retarder control ignored-request list at 0x8019bc (4-byte entries, count byte "
    "0x8019d1; nothing is stored once the count is 5): the byte source address and a countdown word loaded from "
    "0x808188 (JCTMRCTM). 0x23244 calls it with the low byte of the retarder source address when a retarder torque "
    "control request (mode 2) reaches its time limit.",
    "The retarder list (key = source address only: no mode, no network type). Siblings: 0x23870 (find and reload), "
    "0x23920 (count down), 0x23a3c (remove). The present name's 'timeout entry' describes the list's countdown, "
    "not an I/O control.",
    "cm550_addRetarderTsc1IgnoredRequestEntry", "high",
    "cm848_addRetarderTsc1IgnoredRequestEntry @ 0x53d84 - counterpart: the same job at the same call site, but "
    "CM848's entry is 6 bytes with a control mode word and its function takes (source address, mode), while "
    "CM550's entry is 4 bytes and the function takes the source address only; capacity 5 against 10.")

# ---------------------------------------------------------------- globals: J1922 monitor (e2m 1101)
NONE1101 = "none (CM848's e2m has no block 1101 and nothing reads its J1922 monitor enable bit)"
row("0x00804164",
    "GLOBAL word (addq.w / clr.w). e2m 1101 +0 JC22CU 'CONTROL COUNT 0 = J1922 HASN'T CONTROLLED': 0x1fdc0 adds 1 "
    "for every call with mode 1, 2 or 3; 0x1fd6c clears it; no other reference. The present name "
    "j1939_message_total_timeout_count is wrong (no timeout, not J1939).",
    "The total of the three per-mode counts.", "j1922_control_count", "high", NONE1101)
row("0x00804166",
    "GLOBAL dword (move.l / clr.l). e2m 1101 +2 JC22TM 'ECM TIME OF LAST J1922 CONTROL': key_on_hour_meter at the "
    "last recorded control of any mode; 0x1fd6c compares it + 0x808190 with the hour meter. The present name is "
    "j1939_last_message_hour_meter.",
    "The stamp shared by all modes; the clear function's reference time.",
    "j1922_control_last_occurrence_time", "high", NONE1101)
row("0x0080416a", "GLOBAL word. e2m 1101 +6 JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT': +1 per call of 0x1fdc0 with "
    "mode 3; cleared by 0x1fd6c.", "Mode 3 count.", "j1922_limit_control_count", "high", NONE1101)
row("0x0080416c", "GLOBAL dword. e2m 1101 +8 JC22LMTM 'ECM TIME OF LAST J1922 LIMIT COM(MAND)': key_on_hour_meter "
    "at the last mode 3 record; cleared by 0x1fd6c.", "Mode 3 stamp.",
    "j1922_limit_control_last_occurrence_time", "high", NONE1101)
row("0x00804170", "GLOBAL word. e2m 1101 +C JC22RPCU 'J1922 SPEED CONTROL MODE COUNT': +1 per call of 0x1fdc0 with "
    "mode 1; cleared by 0x1fd6c.", "Mode 1 count.", "j1922_speed_control_count", "high", NONE1101)
row("0x00804172", "GLOBAL dword. e2m 1101 +E JC22RPTM 'J1922 SPEED CONTROL OCC. TIME': key_on_hour_meter at the "
    "last mode 1 record; cleared by 0x1fd6c.", "Mode 1 stamp.",
    "j1922_speed_control_last_occurrence_time", "high", NONE1101)
row("0x00804176", "GLOBAL word. e2m 1101 +12 JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT': +1 per call of 0x1fdc0 "
    "with mode 2; cleared by 0x1fd6c.", "Mode 2 count.", "j1922_torque_control_count", "high", NONE1101)
row("0x00804178", "GLOBAL dword. e2m 1101 +14 JC22TQTM: key_on_hour_meter at the last mode 2 record; cleared by "
    "0x1fd6c.", "Mode 2 stamp.", "j1922_torque_control_last_occurrence_time", "high", NONE1101)

# ---------------------------------------------------------------- globals: J1939 monitor (e2m 10FD / 10FE / 10FF / 1100)
row("0x0080417c",
    "GLOBAL word, no code reference. The base of e2m 10FD JCHSTB 'J1939 HISTORY TABLE' (type T): it holds 0x0078 = "
    "5 x 24 in the RAM dump and the EEPROM image; the entries start 2 bytes later.",
    "A length word in front of the table, like the two in front of the active records.",
    "j1939_control_session_history_length", "medium",
    "the word at 0x3fead4 (0x78), which has no row of its own in CM848 (it is j1939_input_signal_timeouts[24] "
    "there)")
row("0x0080417e",
    "GLOBAL array of 5 records of 24 bytes (to 0x8041f5). Its only code access is 0x21f4e, which copies 12 words "
    "to 0x80417e + index x 24 with index 0-4; five empty records (FE FE 00 ...) in the dump. Record layout as "
    "proven for the active records (0x8041f8).",
    "The finished sessions (a ring of five); the two active records feed it.",
    "j1939_control_session_history", "high",
    "j1939_control_session_history_cal @ 0x3fead6, j1939_control_session_t[5] - the same e2m record 10FD")
row("0x008041f6",
    "GLOBAL word, no code reference. The base of e2m 10FE JCAEEG 'J1939 ACTIVE ENGINE STRUCTURE' (type T): 0x0018 "
    "= 24 in the RAM dump and the EEPROM image.",
    "Length word of the active engine record.", "j1939_active_engine_control_session_length", "medium",
    "j1939_active_engine_control_session_length_cal @ 0x3feb4e (0x18 there too)")
row("0x008041f8",
    "GLOBAL 24-byte record; every access (0x21f4e, 0x21fac, 0x22070) goes through base + offset: +0 byte kind (0), "
    "+1 byte source address, +2 word control device, +4 word mode count (1 to 5), +6 five mode words, +0x10 dword "
    "start time (key_on_hour_meter), +0x14 dword duration. The row datalink_speed_snapshot_mode_count (0x8041fc) "
    "is its +4 field.",
    "The open engine control session.", "j1939_active_engine_control_session", "high",
    "j1939_active_engine_control_session_cal @ 0x3feb50, type j1939_control_session_t (session_kind, "
    "controlling_source_address, control_device, override_control_mode_count, override_control_modes[5], "
    "start_time, duration) - the same layout byte for byte")
row("0x00804210",
    "GLOBAL word, no code reference. The base of e2m 10FF JCAERD 'J1939 ACTIVE RETARDER' (type T): 0x0018 in the "
    "RAM dump and the EEPROM image.",
    "Length word of the active retarder record.", "j1939_active_retarder_control_session_length", "medium",
    "j1939_active_retarder_control_session_length_cal @ 0x3feb68")
row("0x00804212",
    "GLOBAL 24-byte record with the layout of 0x8041f8 and kind byte 1; written by 0x21fac(1) and the retarder "
    "half of 0x22070, copied by 0x21f4e(1). The row retarder_snapshot_mode_count (0x804216) is its +4 field.",
    "The open retarder control session.", "j1939_active_retarder_control_session", "high",
    "j1939_active_retarder_control_session_cal @ 0x3feb6a (j1939_control_session_t)")
row("0x0080422a",
    "GLOBAL word. e2m 1100 +0 JCEGCOSS 'J1939 ENGINE CONTROL STATUS 0 = INACTIVE': 0x21fac(0) sets 1; 0x22070 "
    "tests it for 1 and clears it when the engine session closes. No other reference.",
    "Engine session open flag.", "j1939_engine_control_active_flag", "high",
    "j1939_engine_control_active_flag_cal @ 0x3feb82")
row("0x0080422c",
    "GLOBAL word. e2m 1100 +2 JCRDCOSS 'J1939 RETARDER CONTROL STATUS 0 = INACTIVE': 0x21fac(1) sets 1; 0x22070 "
    "tests it for 1 and clears it when the retarder session closes.",
    "Retarder session open flag.", "j1939_retarder_control_active_flag", "high",
    "j1939_retarder_control_active_flag_cal @ 0x3feb84")
row("0x0080422e",
    "GLOBAL word. e2m 1100 +4 JCEGCOSA '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': its single reference is "
    "0x21fac(0), which copies the engine control device word 0x80da4e into it.",
    "Device of the open engine session.", "j1939_engine_control_source", "high",
    "j1939_engine_control_source_cal @ 0x3feb86")
row("0x00804230",
    "GLOBAL word. e2m 1100 +6 JCRDCOSA: its single reference is 0x21fac(1), which copies the retarder control "
    "device word 0x80d9e6 into it.",
    "Device of the open retarder session.", "j1939_retarder_control_source", "high",
    "j1939_retarder_control_source_cal @ 0x3feb88")
row("0x00804232",
    "GLOBAL word. e2m 1100 +8 JCHSTBPO 'POINTER INTO J1939_HISTORY_TABLE': the history entry 0x21f4e writes next; "
    "+1 per filed record, 5 becomes 0. Referenced by 0x21f4e only.",
    "Ring index.", "j1939_control_session_history_next_entry", "high",
    "j1939_control_session_history_next_entry_cal @ 0x3feb8a")

# ---------------------------------------------------------------- globals: the monitor's previous-value copies
row("0x00800b12",
    "GLOBAL word. 0x22070's copy of the engine control mode 0x80da50 from its last pass (cmp.w / tst.w, stored at "
    "the end of the engine half). Referenced by 0x22070 only.",
    "Monitor copy, engine mode.", "j1939_monitor_engine_override_control_mode_previous", "high",
    "j1939_monitor_engine_override_control_mode_previous @ 0x3fbd6c (the five copies lie in the same order in "
    "both)")
row("0x00800b14",
    "GLOBAL word. 0x22070's copy of the retarder control mode 0x80d9e4 from its last pass.",
    "Monitor copy, retarder mode.", "j1939_monitor_retarder_override_control_mode_previous", "high",
    "j1939_monitor_retarder_override_control_mode_previous @ 0x3fbd6e")
row("0x00800b16",
    "GLOBAL word. 0x22070's copy of engine_control_network_type 0x80da68; compared with 1 to tell whether a J1939 "
    "session has to be closed.",
    "Monitor copy, network type.", "j1939_monitor_engine_control_data_link_previous", "high",
    "j1939_monitor_engine_control_data_link_previous @ 0x3fbd70")
row("0x00800b18",
    "GLOBAL byte. 0x22070's copy of the engine control source address byte 0x80da70.",
    "Monitor copy, engine source.", "j1939_monitor_engine_controlling_source_address_previous", "high",
    "j1939_monitor_engine_controlling_source_address_previous @ 0x3fbd72")
row("0x00800b19",
    "GLOBAL byte. 0x22070's copy of the low byte 0x80d9e9 of the retarder source address; compared with the whole "
    "word 0x80d9e8.",
    "Monitor copy, retarder source.", "j1939_monitor_retarder_controlling_source_address_previous", "high",
    "j1939_monitor_retarder_controlling_source_address_previous @ 0x3fbd73")

# ---------------------------------------------------------------- globals: the timeout function's copies and flags
row("0x00801982",
    "GLOBAL word. 0x23244's copy of the engine control mode from its last pass; 0x231da also stores the mode it "
    "ends here, and it is the argument of both 0x1fdc0 calls.",
    "Timeout function copy, engine mode.", "tsc1_override_control_mode_previous", "high",
    "tsc1_override_control_mode_previous @ 0x3faf34")
row("0x00801984",
    "GLOBAL word. 0x23244's copy of engine_control_network_type; tested for 0 before the J1922 recorder call.",
    "Timeout function copy, network type.", "tsc1_controlling_data_link_previous", "high",
    "tsc1_controlling_data_link_previous @ 0x3faf36")
row("0x00801986",
    "GLOBAL byte. 0x23244's copy of the engine control source address byte 0x80da70.",
    "Timeout function copy, engine source.", "tsc1_controlling_source_address_previous", "high",
    "tsc1_controlling_source_address_previous @ 0x3faf38")
row("0x00801988",
    "GLOBAL word. 0x23244's copy of high_idle_override_active_flag (0x80da54); a change to 1 loads the override's "
    "time limit timer.",
    "Timeout function copy, high idle override.", "high_idle_override_active_flag_previous", "high",
    "high_idle_override_active_flag_previous @ 0x3faf39")
row("0x0080198a",
    "GLOBAL word. 0x23244's copy of the retarder control mode 0x80d9e4.",
    "Timeout function copy, retarder mode.", "engine_retarder_override_control_mode_previous", "high",
    "engine_retarder_override_control_mode_previous @ 0x3faf3b")
row("0x0080198c",
    "GLOBAL byte. 0x23244's copy of the low byte 0x80d9e9 of the retarder source address (read at 0x23606, "
    "written at 0x236b8). The third hit on this address (0x2393a in 0x23920) is the engine ignored list's base "
    "minus one entry, not an access.",
    "Timeout function copy, retarder source.", "engine_retarder_controlling_source_address_previous", "high",
    "engine_retarder_controlling_source_address_previous @ 0x3faf3d")
row("0x0080198e",
    "GLOBAL word. 0x23244's copy of 0x80da58 (e2m 10E8 +C JCPSDB, progressive shift disable).",
    "Timeout function copy, progressive shift disable. In CM550 the J1708-side handler 0x1f84e sets the flag too, "
    "so the etc1 prefix of CM848's name is narrower than the CM550 use.",
    "etc1_progressive_shift_disable_previous", "medium",
    "etc1_progressive_shift_disable_previous @ 0x3faf3e")
row("0x00801990",
    "GLOBAL word. 0x23244's copy of driveline_disengaged_flag 0x80da56 (e2m 10E8 +A JCOG, out of gear).",
    "Timeout function copy, out of gear. The J1922 command handler 0x1f4e8 sets the flag too, so the etc1 "
    "prefix of CM848's name is narrower than the CM550 use.", "etc1_out_of_gear_flag_previous", "medium",
    "etc1_out_of_gear_flag_previous @ 0x3faf40")
row("0x00801992",
    "GLOBAL byte. Set to 1 by 0x23244 when a control request is new or changed on network 1 (and by every "
    "retarder mode 2 / 3 change). While it is 1 and no J1939 timeout happened in the pass: the byte is cleared "
    "when the J1939 link error bit (system error status word 5 mask 0x0400) or the same mask of 0x806ac6 is "
    "clear; with both set and the mask of 0x80604a clear, the error bit and the byte are cleared. No timeout "
    "sets it: the present name datalink_j1939_timeout_flag says the opposite.",
    "Clear request for the J1939 link fault.", "j1939_link_fault_clear_request_flag", "high",
    "j1939_link_fault_clear_request_flag @ 0x3faf42")
row("0x00801993",
    "GLOBAL byte. The J1708 twin of 0x801992: set for a new or changed engine request on a network other than 1; "
    "the same clear logic on system error status word 7 mask 0x0008 (with 0x806aca and 0x80604e), which also "
    "zeroes the count 0x804266. Now datalink_j1708_timeout_flag.",
    "Clear request for the J1708 link fault.", "j1708_link_fault_clear_request_flag", "high",
    "j1708_link_fault_clear_request_flag @ 0x3faf43")

# ---------------------------------------------------------------- globals: the periodic transmit schedule
row("0x00800a9a",
    "GLOBAL byte. Number of entries in the schedule at 0x80096e: 0x1fe84 compares it with 20 and post-increments "
    "it, 0x1ff38 loops to it. 17 in the RAM dump.",
    "Queue 0 (engine broadcasts) count.", "j1939_periodic_queue0_count", "high",
    "j1939_periodic_queue0_count @ 0x3fd40e")
row("0x00800a9b",
    "GLOBAL byte. Number of entries in the schedule at 0x800a36 (limit 10 in 0x1fe84). 2 in the RAM dump.",
    "Queue 1 (retarder broadcasts) count.", "j1939_periodic_queue1_count", "high",
    "j1939_periodic_queue1_count @ 0x3fd40f")
row("0x00800a9c",
    "GLOBAL word. Tick of queue 0: 0x1ff38 compares each entry's next-due tick with it and adds 1 per call while "
    "broadcast bit 2 is set; 0x1fe84 adds it to a new entry's first tick.",
    "Queue 0 tick.", "j1939_periodic_queue0_current_tick", "high",
    "j1939_periodic_queue0_current_tick @ 0x3fd410")
row("0x00800a9e",
    "GLOBAL word. Tick of queue 1 (broadcast bit 3), used like 0x800a9c.",
    "Queue 1 tick.", "j1939_periodic_queue1_current_tick", "high",
    "j1939_periodic_queue1_current_tick @ 0x3fd412")
row("0x0080096e",
    "GLOBAL array of 20 entries of 10 bytes (to 0x800a35). Its two users agree on the layout: 0x1fe84 writes +0 "
    "word PGN, +2 word period (ms / 10), +4 word next-due tick, +6 pointer to the message builder; 0x1ff38 reads "
    "+4 and +2 and calls +6.",
    "The engine node's broadcast schedule (broadcast enable bit 2).", "j1939_periodic_queue0_entries", "medium",
    "the 20 entries at 0x3fd2e2 (no CM848 row; cm848_scheduleJ1939PeriodicMessage / "
    "cm848_runJ1939PeriodicTransmitQueues use the same 10-byte layout)")
row("0x00800a36",
    "GLOBAL array of 10 entries of 10 bytes (to 0x800a99) with the layout of 0x80096e.",
    "The retarder node's broadcast schedule (broadcast enable bit 3).", "j1939_periodic_queue1_entries", "medium",
    "the 10 entries at 0x3fd3aa (no CM848 row)")

# ---------------------------------------------------------------- globals: timers of the control state cluster
row("0x0080da7e",
    "GLOBAL word. Time limit timer of the engine control request: on a mode / network / source change 0x23244 "
    "loads it with the sender's speed (+6) or torque (+0xa) control time limit + 1 (0 for modes 0 and 3), counts "
    "it down while the request is unchanged, and at 1 puts the sender on the ignored list and resets the request; "
    "0x231da clears it. No other reference.",
    "The time limit, not the message timeout (that is 0x80da80).", "tsc1_request_time_limit_timer", "high",
    "j1939_powertrain_control_state.tsc1_request_time_limit_timer (0x40ae20); the timer words 0x80da7e-0x80da94 "
    "lie in the same order as CM848's +0x28..+0x3e")
row("0x0080da8c",
    "GLOBAL word. Loaded together with 0x80da58 = 1 by the ETC1 handler 0x2efd0 (0x80818c, e2m JCPSTM, + 1) and by "
    "a second loader, 0x1f84e (0x80818c without + 1; it reads the J1708 receive buffer through 0x80dcaa and is "
    "called at 0x16408 right after the two J1922 command handlers); both clear the pair otherwise. 0x23244 counts "
    "it down and at 1 clears 0x80da58 and the timer.",
    "Timeout of the progressive shift disable flag. Because the J1708-side handler 0x1f84e loads it too, the etc1 "
    "prefix of CM848's name is narrower than the CM550 use (progressive_shift_disable_timer would be the neutral "
    "form).",
    "etc1_progressive_shift_disable_timer", "medium",
    "j1939_powertrain_control_state.etc1_progressive_shift_disable_timer (0x40ae2e)")
row("0x0080da98",
    "GLOBAL word. 0x23244 sets it to 1 when the high idle override time limit expires (and loads the timeout "
    "timer with the recovery time) and clears it when that timer expires; the ETC1 handler 0x2efd0 tests it and, "
    "while it is set, only reloads the recovery time. No other reference.",
    "Recovery state of the high idle override.", "high_idle_override_recovery_flag", "high",
    "j1939_powertrain_control_state.high_idle_override_recovery_flag (0x40ae4a)")

# ---------------------------------------------------------------- globals: the ignored-request lists
row("0x00801994",
    "GLOBAL array of 5 entries of 8 bytes (to 0x8019bb); every access is in 0x23820 / 0x238ac / 0x23920 / 0x239d2: "
    "+0 word network type, +2 byte source address, +4 word control mode, +6 word countdown. The rows "
    "diagnostic_service_state_counter (0x801998), diagnostic_security_access_mode (0x80199a) and the "
    "torque_control_* rows 0x8019a2-0x8019b6 are fields of its entries (no reference of their own).",
    "The engine control ignored-request list.", "engine_tsc1_ignored_request_entries", "high",
    "engine_tsc1_ignored_request_entries @ 0x3fb916 (10 entries of the same 8 bytes)")
row("0x008019bc",
    "GLOBAL array of 5 entries of 4 bytes (to 0x8019cf); every access is in 0x23870 / 0x238ec / 0x23920 / "
    "0x23a3c: +0 byte source address, +2 word countdown. The hit on 0x8019b8 (row diag_service_pgn_dispatch_ptr) "
    "at 0x2398e is this list's base minus one entry, not an access.",
    "The retarder control ignored-request list.", "retarder_tsc1_ignored_request_entries", "high",
    "retarder_tsc1_ignored_request_entries @ 0x3fb966 (10 entries of 6 bytes: CM848 adds a mode word)")
row("0x008019d0",
    "GLOBAL byte. Entry count of the list at 0x801994 (limit 5); used by the four engine list functions only. Now "
    "io_control_entry_count.",
    "Engine list count.", "engine_tsc1_ignored_request_count", "high",
    "engine_tsc1_ignored_request_count @ 0x3fb9a2")
row("0x008019d1",
    "GLOBAL byte. Entry count of the list at 0x8019bc (limit 5); used by the four retarder list functions only. "
    "Now io_control_timeout_entry_count.",
    "Retarder list count.", "retarder_tsc1_ignored_request_count", "high",
    "retarder_tsc1_ignored_request_count @ 0x3fb9a3")

# ---------------------------------------------------------------- globals: description-named e2m records the family uses
row("0x0080da4e",
    "GLOBAL word. e2m 10E8 +2 JCEGCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN': the device in control of "
    "the engine; 0x2142c tests it for 1, 0x231da clears it, 0x21fac copies it into the session record. Now the "
    "description name source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_da4e.",
    "Engine side (the retarder twin is 0x80d9e6).", "engine_control_device_indicator", "high",
    "engine_control_device_indicator @ 0x40adf6 (the same e2m record)")
row("0x0080d9e6",
    "GLOBAL word. e2m 10E6 +2 JCRDCOID: the device in control of the retarder; 0x2142c tests it for 1, 0x23216 "
    "clears it, 0x21fac copies it. Now source_0_none_1_trans_2_abs_3_asr_4_unknown_0_4_d9e6.",
    "Retarder side.", "engine_retarder_control_device_indicator", "high",
    "engine_retarder_control_device_indicator @ 0x40ad5c")
row("0x0080da60",
    "GLOBAL word. e2m 10E8 +14 JCRPGVSS 'JCOMM SPEED CONTROL STATUS 1 = SPEED CONTROL MODE': 0x231da clears it; "
    "processEngineTsc1Request and the J1922 command handlers store 1 in the mode 1 branch and 0 in the other "
    "branches. Now jcomm_speed_control_status_1_speed_control_mode_0_n_true_false.",
    "Follows the engine control mode: 1 only in speed control.", "tsc1_speed_control_flag", "high",
    "j1939_powertrain_control_state.tsc1_speed_control_flag (0x40ae06; e2m Jcomm_Speed_Control_Status, the same "
    "record)")
row("0x0080aa12",
    "GLOBAL word. e2m 102E +0 JCBCFGLC 'BIT-MAPPED PARAMETER INDICATES PROTOCOLS/PORTS BROADCAST ENAB(LED)': "
    "0x1ff38 runs queue 0 on bit 2 (JCEGBCEA, J1939/71 engine broadcast) and queue 1 on bit 3 (JCRDBCEA, retarder "
    "broadcast); bits 0 / 1 are the J1587 / J1922 broadcasts. 0x000d in the dump. Now "
    "bit_2_0_15_enables_j1939_71_engine_broadcast_1_on_0_off.",
    "One word for all datalink broadcasts.", "datalink_broadcast_enable_flags", "high",
    "datalink_broadcast_enable_flags @ 0x40adee (the same e2m record)")
row("0x008089a8",
    "GLOBAL word. e2m 10FC +2 JCEBSILM 'LIMIT TO WHICH USER FUELING IS COMPARED TO DETERMINE IF ENGINE (BRAKES "
    "...)': 0x2142c ends the retarder request once fuel_demand_selected is at or above it; the retarder TSC1 "
    "handler (0x2f9c6) makes the same compare. 15 in the dump.",
    "Read by 0x2142c only in this family.", "engine_retarder_shift_assist_fuel_demand_limit", "high",
    "engine_retarder_shift_assist_fuel_demand_limit @ 0x5c36c (the same e2m record)")
row("0x00808188",
    "GLOBAL word. e2m 10E7 +A JCTMRCTM 'TIME THAT TIME LIMITED NODE MUST BE SILEN(T)': loaded (+ 1) into the high "
    "idle timeout timer when the time limit expires (0x23244) and while the recovery flag is set (0x2efd0), and "
    "the countdown of every ignored-list entry (0x23820 / 0x23870 / 0x238ac / 0x238ec).",
    "The recovery time of time-limited requests.", "j1939_time_limited_node_recovery_time", "high",
    "j1939_time_limited_node_recovery_time @ 0x5c38c (the same e2m record)")
row("0x00808184",
    "GLOBAL word. e2m 10E7 +6 JCEGOSTL 'TIME LIMIT FOR JCOMM_HIGH_IDLE_OVE(RRIDE)': 0x23244 loads it + 1 into the "
    "time limit timer 0x80da88 on a rise of high_idle_override_active_flag; "
    "buildPgn65251EngineConfiguration1Payload stores it / 10 as the byte at +0x17 of its buffer (0x33332). 600 in "
    "the dump. Now a description name.",
    "The time limit of the high idle override (the message timeout is 0x808182).",
    "j1939_pgn61442_engine_overspeed_enable_time_limit", "medium",
    "j1939_pgn61442_engine_overspeed_enable_time_limit @ 0x5c388 (the same e2m record; 600 there too)")
row("0x008081fc",
    "GLOBAL word. e2m 10E7 +7E JCTMERLM 'NUMBER OF TIMEOUTS ALLOWED BEFORE SETTING J1XXX_LINK_NOT_FAST(...)': "
    "0x23244 compares both link timeout counts with it (the J1708 count with limit - 1, signed; the J1939 count "
    "with the limit, unsigned). 100 in the dump.",
    "The limit of both link timeout counts.", "j1939_link_fault_timeout_count_limit", "high",
    "j1939_link_fault_timeout_count_limit @ 0x5c39c (JCTMERLM; CM848 10E7 +1A)")
row("0x00808190",
    "GLOBAL dword. e2m 10E7 +12 JC22CCTM 'J1922 CLEAR OCCURRENCE TIME: TIME FROM LAST J1922 CONTROL BEFO(RE ...)': "
    "its single reference is 0x1fd6c, which clears the J1922 counts when 0x804166 + this is below "
    "key_on_hour_meter.",
    "Used by the clear function only.", "j1922_clear_occurrence_time", "medium",
    "the unnamed ROM dword at 0x5c394 (e2m J1922_Clear_Occurrence_Time, 10E7 +12; no CM848 reader)")
row("0x00803d4a",
    "GLOBAL word in the EEPROM mirror (EEPROM 0x240). e2m 1180 +10 VSRSSNTY '0=NONE, 1=INDUCTIVE, 2=MINIGEN, "
    "3=TACH, 4=DLW/GR&OOG, 5=DLW/O GR(&OOG)': its only references are three compares in 0x23244 - 4 or 5 enables "
    "the 0x80da92 and 0x80aa10 countdowns, 4 the 0x80da94 countdown with the status word 4 error. 0 in the dump. "
    "No row yet.",
    "Selects which datalink timers 0x23244 runs.", "vehicle_speed_sensor_type_cal", "medium",
    "vehicle_speed_sensor_type_cal @ 0x3fdda6 (VSRSSNTY; tested for 4 / 5 at the same place of the CM848 "
    "counterpart)")
row("0x0080d9e0",
    "GLOBAL byte[4]. The receive dispatcher 0x212b2 compares the received source address with these bytes (0xFE "
    "ends the list) and skips the frame on a match; mc68k_initializeJ1939Datalink fills it with 0xFE (0x28bca); "
    "no other reference; FE FE FE FE in the RAM dump.",
    "A list of source addresses whose frames are dropped, not accepted.",
    "j1939_receive_ignored_source_addresses", "medium",
    "j1939_receive_source_address_whitelist @ 0x40ad56 is the same record (4 bytes after "
    "j1939_received_source_address in both), but 'whitelist' says the opposite of what both dispatchers do (a "
    "listed source is not dispatched); one corrected name for both is suggested")

# ---------------------------------------------------------------- globals the family's code does not let me name
row("0x0080bcf6",
    "GLOBAL byte. e2m 000E +28 'BYTE 0 OUTPUT_PORT' (lamp driver command bits; bit 7 the fuel shut-off command): "
    "0x21920 reads bits 4, 1 and 6 of it as the lamp commands. Now "
    "bit_6_which_enables_the_warning_lamp_driver_enable_disable, which names one bit of the byte.",
    "This family only reads three bits; its 20-odd other references (the writers) are outside the batch, so no "
    "name is proposed here.",
    "", "low", "none found: CM848's lamp status byte tests four separate flags")
row("0x0080da90",
    "GLOBAL word. Only cleared: 0x2142c, 0x23216 and two stores in the retarder TSC1 handler (0x2fa30 / 0x2fa8a); "
    "never read and never set to another value in the dumped ROM.",
    "Missing for a name: any reader or non-zero store. By position it is CM848's "
    "j1939_powertrain_control_state.retarder_tsc1_speed_control_flag (itself marked inferred).",
    "", "low", "retarder_tsc1_speed_control_flag (0x40ae32) by position and by the twin stores")
row("0x0080da92",
    "GLOBAL word. Used by 0x23244 only: for sensor type 4 / 5 it is counted down and at 1 cleared together with "
    "0x80da6c. No loader in the dumped ROM.",
    "Missing for a name: the code that loads it. By position CM848's etc1_out_of_gear_data_timer.",
    "", "low", "j1939_powertrain_control_state.etc1_out_of_gear_data_timer (0x40ae34) by position")
row("0x0080da6c",
    "GLOBAL word. Its single reference is the clr.w at 0x233da (0x23244, when 0x80da92 reaches 1).",
    "Missing for a name: any reader or setter. By position (e2m 10E8 +20) CM848's "
    "etc1_out_of_gear_data_valid_flag.",
    "", "low", "j1939_powertrain_control_state.etc1_out_of_gear_data_valid_flag (0x40ae12) by position")
row("0x0080aa10",
    "GLOBAL word. Used by 0x23244 only: for sensor type 4 / 5 it is counted down and on reaching 1 clears "
    "0x80aa08 (the timer then runs on to 0). No loader in the dumped ROM.",
    "Missing for a name: the code that loads it. CM848's counterpart step uses etc2_gear_ratio_timeout.",
    "", "low", "etc2_gear_ratio_timeout (CM848, the same step of the counterpart function)")
row("0x0080aa08",
    "GLOBAL word. Its single reference is the clr.w at 0x233f8 (0x23244, when 0x80aa10 reaches 1).",
    "Missing for a name: any reader or setter. CM848's counterpart step clears etc2_gear_ratio_valid_flag.",
    "", "low", "etc2_gear_ratio_valid_flag (CM848, the same step of the counterpart function)")

# ---------------------------------------------------------------- enum roles
enum_roles = []


def enum(name, value, meaning, evidence):
    enum_roles.append({"enum_name": name, "value": value, "meaning": meaning, "evidence": evidence})


enum("J1939_DIAGNOSTIC_SERVICE", 68,
     "write by parameter ID: 2-byte ID and 1-byte length, then the data (CM848 member "
     "J1939_DIAGNOSTIC_SERVICE_WRITE_BY_PARAMETER_ID; CM550's member is the placeholder SERVICE_44)",
     "0x21872 registers 0x2167e for 0x44; 0x2167e copies bytes 1-2, takes byte 3 as the length and calls 0x21642 "
     "with offset 0")
enum("J1939_DIAGNOSTIC_SERVICE", 69,
     "write by parameter ID with a 4-byte length (CM848 ..._WRITE_BY_PARAMETER_ID_LONG_LENGTH; CM550 SERVICE_45)",
     "0x21872 registers 0x216c6 for 0x45; bytes 1-2 the ID, bytes 3-6 the length, offset 0")
enum("J1939_DIAGNOSTIC_SERVICE", 71,
     "write by parameter ID at a 2-byte offset with a 1-byte length (CM848 "
     "..._WRITE_BY_PARAMETER_ID_SHORT_OFFSET; CM550 SERVICE_47)",
     "0x21872 registers 0x21714 for 0x47; bytes 1-2 the ID, bytes 3-4 the offset, byte 5 the length")
enum("J1939_DIAGNOSTIC_SERVICE", 73,
     "write by parameter ID at a 4-byte offset with a 4-byte length (CM848 ..._WRITE_BY_PARAMETER_ID_LONG_OFFSET; "
     "CM550 SERVICE_49)",
     "0x21872 registers 0x21778 for 0x49; bytes 1-2 the ID, bytes 3-6 the offset, bytes 7-10 the length")
enum("J1939_DIAGNOSTIC_SERVICE", 75,
     "write memory: 4-byte address and 1-byte length (CM848 ..._WRITE_MEMORY; CM550 SERVICE_4B)",
     "0x21872 registers the shared handleJ1939WriteMemoryService (0x217de) for 0x4b")
enum("J1939_DIAGNOSTIC_SERVICE", 77,
     "write memory with a 4-byte length (CM848 ..._WRITE_MEMORY_LONG_LENGTH; CM550 SERVICE_4D)",
     "0x21872 registers the shared handleJ1939WriteMemoryLongLengthService (0x21826) for 0x4d")
enum("TSC1_OVERRIDE_MODE", 0,
     "no override (CM848 TSC1_OVERRIDE_OFF; CM550 has no such enum yet)",
     "the resets 0x231da / 0x23216 and 0x2142c store 0; 0x22070 closes a session when the mode becomes 0; e2m "
     "JCEGMD '0 = DISABLE'")
enum("TSC1_OVERRIDE_MODE", 1,
     "speed control (CM848 TSC1_SPEED_CONTROL)",
     "0x1fdc0 counts mode 1 in 0x804170, e2m JC22RPCU 'J1922 SPEED CONTROL MODE COUNT'; 0x23244 loads the time "
     "limit from the configuration's speed_control_time_limit for mode 1; e2m JCEGMD '1 = SPEED'")
enum("TSC1_OVERRIDE_MODE", 2,
     "torque control (CM848 TSC1_TORQUE_CONTROL)",
     "0x1fdc0 counts mode 2 in 0x804176, e2m JC22TQCU 'J1922 TORQUE CONTROL MODE COUNT'; 0x23244 loads "
     "torque_control_time_limit for mode 2; the retarder mode 2 uses retarder_torque_control_time_limit")
enum("TSC1_OVERRIDE_MODE", 3,
     "speed / torque limit control (CM848 TSC1_SPEED_TORQUE_LIMIT)",
     "0x1fdc0 counts mode 3 in 0x80416a, e2m JC22LMCU 'J1922 LIMIT ENGINE MODE COUNT'; 0x23244 gives mode 3 a "
     "timeout but no time limit; e2m JCEGMD '3 = LIMIT'")
enum("CONTROL_NETWORK", 0,
     "J1922 (on the J1708 link) (CM848 CONTROL_NETWORK_J1922; CM550 has no such enum yet)",
     "0x23244: a timeout with engine_control_network_type not 1 counts in 0x804266 (e2m JC17TMCU, J1708 (J1922) "
     "time-outs), and the J1922 recorder is called when the previous network type is 0")
enum("CONTROL_NETWORK", 1,
     "J1939 (CM848 CONTROL_NETWORK_J1939)",
     "0x23244: a timeout with network type 1 counts in 0x804268 (e2m JC39TMCU); 0x22070 opens J1939 session "
     "records only for network type 1")
enum("J1939_CONTROL_DEVICE", 0,
     "none (CM848 J1939_CONTROL_DEVICE_NONE; CM550 has no such enum yet)",
     "the resets 0x231da / 0x23216 store 0 in 0x80da4e / 0x80d9e6; e2m JCEGCOID / JCRDCOID '0 = NONE'")
enum("J1939_CONTROL_DEVICE", 1,
     "transmission (CM848 J1939_CONTROL_DEVICE_TRANSMISSION)",
     "0x2142c requires 0x80d9e6 = 1 and 0x80da4e = 1 for the retarder shift assist end; e2m '1 = TRANS'")
enum("VEHICLE_SPEED_SENSOR_TYPE", 4,
     "data link with gear ratio and out of gear (CM848 VEHICLE_SPEED_SENSOR_J1939_WITH_GEAR_RATIO; CM550 has no "
     "such enum yet)",
     "0x23244 runs the 0x80da92 / 0x80aa10 countdowns for 0x803d4a = 4 or 5 and the 0x80da94 countdown (status "
     "word 4 mask 0x0100, e2m VSLOSTER) for 4 only; e2m VSRSSNTY '4=DLW/GR&OOG'")
enum("VEHICLE_SPEED_SENSOR_TYPE", 5,
     "data link without gear ratio and out of gear (CM848 VEHICLE_SPEED_SENSOR_J1939_WITHOUT_GEAR_RATIO)",
     "0x23244 runs the 0x80da92 / 0x80aa10 countdowns for 5 but not the 0x80da94 one; e2m VSRSSNTY '5=DLW/O GR'")

# ---------------------------------------------------------------- notes
notes = (
    "1. THE 'ROM TABLE' 0x1b4da-0x1b4e9 IS CODE, NOT A TABLE. 0x1b4d8 is a function made of jsr (abs).l "
    "instructions (opcode 4EB9 + 4-byte target): jsr 0x212b2 / 0x23244 / 0x22070 / 0x230ee / 0x21edc / 0x21070 / "
    "0x420bc / rts; the hits at 0x1b4da, 0x1b4e0 and 0x1b4e6 are the operands of the first three. Nobody walks "
    "it: executiveFrameInterruptHandler (0x1b876) calls 0x1b4d8 with bsr.w (PC-relative, so no absolute pointer "
    "exists) in each of the 20 even phases of the 40-phase executive, and 0x1b504 (jsr 0x2142c / 0x1ff38 / "
    "0x23920 / rts) in each of the 20 odd phases (20 bsr.w sites each, 0x1b960-0x1be6e). In the frozen copy two "
    "function rows share the name vp44_evenPhaseSchedulerTaskSet (0x1b4d8 and 0x1b62a), which hides the first "
    "from a name-keyed caller scan, and the rows 0x1b4ea and 0x1b4f6 are labels in the middle of 0x1b4d8's jsr "
    "chain. 0x1b4d8 is the counterpart of the first six calls of cm848_phase_group_a_processing (0xb7b4: dispatch "
    "/ control timeouts / track sessions / transport sessions / input supervision / switch and request inputs); "
    "CM848 then runs endRetarderShiftAssist and the periodic transmit queues in the same group, CM550 in the "
    "odd-phase set. "
    "2. _cal. The J1922 and J1939 monitor cells 0x804164-0x804233 are outside the stated mirror range "
    "0x803B0A-0x804155, so their names carry no _cal (as j1939_input_signal_timeouts at 0x804234 already does). "
    "But the ECU's parameter ID table tags them EEPROM (0x0100065A-0x01000728), CM848's same records end in _cal, "
    "and J90350.00.eeprom.bin equals the RAM dump at 0x803b0a + offset for all 4096 bytes; the judge decides "
    "whether the mirror is longer than 0x64C. "
    "3. e2m type T records start with a 2-byte length word: 10FD / 10FE / 10FF resolve to 0x80417c / 0x8041f6 / "
    "0x804210 and the code's data starts 2 bytes later, exactly as in CM848. "
    "4. TYPES. CM550 has no j1939_control_session_t, TSC1_OVERRIDE_MODE, J1939_CONTROL_DEVICE, CONTROL_NETWORK or "
    "VEHICLE_SPEED_SENSOR_TYPE yet; CM848's definitions fit CM550's accesses field for field. The byte 0x80d9e9 "
    "is the low byte of the existing word row retarder_command_source_address (0x80d9e8) and needs no row. "
    "5. FAULT BITS. In this ROM the J1708 link error is system error status word 7 (0x80600e) mask 0x0008 and the "
    "J1939 link error word 5 (0x80600a) mask 0x0400, each also set in the word at + 0x40; the clear path tests "
    "the same mask in 0x806aca / 0x806ac6 and in 0x80604e / 0x80604a. The e2m's JC39TMER (1036 +E mask 0x01) is "
    "not the bit this code sets. "
    "6. SIBLINGS OUTSIDE THE BATCH that the same evidence describes: 0x2167e cm550_j1939DataCopyWrapper2Byte is "
    "the service 0x44 handler (CM848 cm848_handleJ1939WriteByParameterIdService 0x50b228); 0x21714 "
    "cm550_j1939DataCopyWrapperExtended the service 0x47 handler (CM848 "
    "cm848_handleJ1939WriteByParameterIdShortOffsetService 0x50b300); 0x1fd6c cm550_j1939TimeoutDataClearHandler "
    "clears the J1922 monitor cells (bit 0x100) and the row 0x1fd8e is a label in its middle (no caller); 0x1fe84 "
    "(no row) does the steps of cm848_scheduleJ1939PeriodicMessage (0x538c8c) and is reached through movea.l "
    "#0x1fe84,a4 at 0x28b8a; 0x2efd0 cm550_diagnosticServiceDispatcherByPgn is the ETC1 receive handler (key "
    "0xf002, registered at 0x2f114) that loads the high idle / progressive shift / out of gear timers; 0x1f84e "
    "cm550_fuelDemandScaleFactorCalculator reads the J1708 receive buffer (pointer 0x80dcaa; called at 0x16408 "
    "right after the two J1922 command handlers) and sets progressive shift disable with its timer; the "
    "ignored-list functions 0x23820 / 0x23870 / 0x23920 / 0x239d2 / 0x23a3c stand in the same order as CM848's "
    "refreshEngine / refreshRetarder / (add, add) / processTimeouts / removeEngine / removeRetarder "
    "Tsc1IgnoredRequest functions. "
    "7. EXISTING CM550 NAMES THE CODE CONTRADICTS (not DAT_ or description names, so no row): 0x80da58 "
    "engine_brake_override_flag is e2m JCPSDB progressive shift disable; 0x80da82 "
    "retarder_command_inactivity_timer is the retarder time limit timer (retarder_torque_control_time_limit + 1); "
    "0x80da86 high_idle_override_duration_timer is the override's message timeout (0x808182 JCEGOSTM + 1) and "
    "0x80da88 high_idle_overspeed_timeout_timer its time limit (0x808184 JCEGOSTL + 1); 0x80da8e "
    "retarder_disengage_hold_timer is loaded with the request timeout + 1 only when the requested retarder torque "
    "is 0 (CM848 retarder_tsc1_zero_torque_request_timer); 0x804266 / 0x804268 are e2m 11C1 JC17TMCU / JC39TMCU "
    "(CM848 j1708_link_fault_timeout_count_cal / j1939_link_fault_timeout_count_cal). The system error status "
    "words 0x806000 + 2 n are description-named members of one e2m 1036 array and are left to the fault "
    "subsystem. "
    "8. PACKAGING. Globals are roles rows whose role starts with GLOBAL (the schema has no globals field); helper "
    "rows start with HELPER; a row with an empty suggested_name says what is missing. Every exclusivity statement "
    "('only reference', 'every access') was checked with abs_refs.py over the ROM in this run (absolute-long "
    "operands; an access through a computed pointer, as the parameter ID services make, is not visible to it). "
    "Every suggested "
    "name was checked against the frozen function_renames / global_variables / structure_definitions of both "
    "firmwares: the shared twin names are free in both (CM848 holds only the cm848_ forms), and the CM550 global "
    "names are free in CM550 (the CM848 hits are the same records). "
    "9. COPIES. This answer is also in "
    "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/J2/describer/final_answer_v2.json; the evidence trail "
    "is in /home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/J2/describer/notes.md."
)

answer = {"batch": "J2", "roles": roles, "enum_roles": enum_roles, "notes": notes}
out = os.path.join(HERE, "final_answer_v2.json")
json.dump(answer, open(out, "w"), indent=1)

# ---------------------------------------------------------------- checks
names = [r["suggested_name"] for r in roles if r["suggested_name"]]
dups = sorted({n for n in names if names.count(n) > 1})
print(f"{len(roles)} roles ({sum(1 for r in roles if not r['role'].startswith(('GLOBAL', 'HELPER')))} functions, "
      f"{sum(1 for r in roles if r['role'].startswith('HELPER'))} helpers, "
      f"{sum(1 for r in roles if r['role'].startswith('GLOBAL'))} globals); {len(enum_roles)} enum roles; "
      f"notes {len(notes)} chars; json {os.path.getsize(out)} bytes; longest role "
      f"{max(len(r['role']) for r in roles)}")
print("duplicate names:", dups or "none")
addresses = [r["address"] for r in roles]
print("duplicate addresses:", sorted({a for a in addresses if addresses.count(a) > 1}) or "none")
taken = {}
for fw in ("cm550", "cm848"):
    for fn, col in (("function_renames.csv", 1), ("global_variables.csv", 1)):
        for r in csv.reader(open(os.path.join(FROZEN, fw, fn), newline="", errors="replace")):
            if len(r) > col and r and not r[0].startswith("#"):
                taken.setdefault((fw, r[col]), []).append(r[0])
for n in names:
    if ("cm550", n) in taken:
        print("TAKEN in cm550:", n, taken[("cm550", n)])
for r in roles:
    n = r["suggested_name"]
    if n and not n.startswith(("cm550_", "mc68k_", "vp44_")) and r["role"].split(".")[0] not in ("GLOBAL",) \
            and not r["role"].startswith("GLOBAL") and ("cm848", n) in taken:
        print("shared function name TAKEN in cm848:", n, taken[("cm848", n)])
for r in roles:
    for k in ("role", "discriminator", "suggested_name", "confidence", "address"):
        assert k in r
    assert r["confidence"] in ("high", "medium", "low")
print("ok")
