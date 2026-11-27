"""Round 96 stage H (CM550): seven functions that never exported a body. The decompiler failed on each with 'Low-level
Error: Cannot properly adjust input varnodes': each takes stack arguments in the compiler's 2-byte-slot layout (a word
or byte at +4, a long at +6 / +8 ...), which Ghidra's 4-byte-slot default cannot fit, and none had a
function_definitions row (stack_parameter_layout.csv places parameters only from rows). Full prototypes from the
disassembly (each argument's load width and offset), plates for the four that had none, and three renames by what the
bodies do. Exact-line edits; refuses on a mismatch; keeps line endings. usage: stage_h_prototypes_r96.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
OUT = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "(PR #53 round 96)"


def load(p):
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    return t.split(E), E


RENAMES = {
    "0x000103ba": ("cm550_sendCanSingleFrame", "cm550_sendCanSingleFrame",
                   "Sends one CAN frame of up to 8 bytes. status = 1 when data_length is 0, and 4 while the transmit "
                   "ring is full (0x80d9be = 1). Otherwise it builds the 14-byte frame record on its stack: the "
                   "identifier << 3 at +0..+3 (the 82527's extended arbitration layout), the configuration byte 0x8c at "
                   "+4 (8 data bytes, transmit, extended identifier) and the data padded with 0xff at +5..+12. When bit "
                   "7 of the byte at *(0x80d9c2) is clear it hands the record to cm550_transmitCanFrameOnMessageObject "
                   "(controller 0xffd800, message object 0x80d9f5); otherwise it appends the record to the transmit "
                   "ring 0x80d896-0x80d9a0 (write pointer 0x80d9ae, read pointer 0x80d9b2). A ring that becomes full "
                   "sets 0x80d9be and, while 0x80da0c is 1, bit 9 of the words 0x80600a / 0x80604a. status = 0 then. "
                   "Callers: cm550_sendCanMessage, cm550_canDiagnosticResponseSender and sendJ1939MultiFrame. The "
                   f"prototype lets the decompiler export the body {R}"),
    "0x00016cd8": ("cm550_circularBufferWrite", "cm550_queueEepromByteWrites",
                   "Queues bytes for the serial EEPROM writer. It returns 1 and queues nothing when the pending count "
                   "circular_buffer_byte_count + byte_count would pass 1280 (0x500). Otherwise, for each byte, it "
                   "stores the data byte at 0x80c7a8[eeprom_circular_buffer_write_index] and the byte's EEPROM address "
                   "(eeprom_address + n) in the word ring 0x80bda8[index], advances the index modulo 1280 and counts "
                   "the entry; then it returns 0. Callers: cm550_commitEepromMirrorToEeprom (16-byte chunks of the "
                   "mirror 0x803b0a-0x804155 with their EEPROM offset), writeJ1939DiagnosticMemory and "
                   "cm550_memoryPatchingSystem (both while 0x80dc6c is 1). (was cm550_circularBufferWrite; the "
                   f"prototype lets the decompiler export the body) {R}"),
    "0x00018dae": ("cm550_protectionUpdateHandler", "cm550_updateEngineProtectionRestartLimitationCommands",
                   "The engine protection restart limitation, for protection channel 3 only. Once "
                   "engine_protection_consecutive_shutdown_count has reached "
                   "max_number_of_shutdowns_before_restart_is_not_allowed_0_255 and the channel state record's word "
                   "+0x16 is not 0, it sets epf_shutdown_approaching_command_from_restart_limitat_1_true_0_false "
                   "(0x80d27c) to (state word +6 != 0) and epf_shutdown_engine_command_from_restart_limitation_a_1_true_0_false "
                   "(0x80d27a) to (settings word +0x1e < state word +6, unsigned). Otherwise both keep their values. "
                   "cm550_protectionState1DiagnosticValidator calls it once per channel (0x18d7e) with the channel's "
                   "state record (from 0x80d0dc) and settings record (from 0x807032). (was "
                   f"cm550_protectionUpdateHandler; the prototype lets the decompiler export the body) {R}"),
    "0x0001e0bc": ("cm550_canFrameDataCopy", "cm550_transmitCanFrameOnMessageObject",
                   "Loads a 13-byte frame record (arbitration +0..+3, configuration +4, 8 data bytes) into message "
                   "object message_object_number of the CAN controller at controller_base (object = controller_base + "
                   "16 x number; both callers pass 0xffd800) and requests its transmission. In the 82527's set / reset "
                   "bit pairs it writes control 0 / 1 = 0x7f / 0xfb (MsgVal reset, CPUUpd set), copies the record to "
                   "the object's +2, then writes 0xbf / 0xe6 (MsgVal set; CPUUpd reset; NewDat and TxRqst set). "
                   "Callers: cm550_sendCanSingleFrame (a free transmit object) and mc68k_canCs4TransmitNextFrame (the "
                   f"next queued frame). (was cm550_canFrameDataCopy; the prototype lets the decompiler export the body) {R}"),
}
p = os.path.join(OUT, "function_renames.csv")
lines, E = load(p)
for a, (old, new, plate) in RENAMES.items():
    hits = [k for k, l in enumerate(lines) if l == f"{a},{old}" or l == f"{a},{new},{plate}"]
    assert len(hits) == 1, (a, old)
    lines[hits[0]] = f"{a},{new},{plate}"
open(p, "w", newline="").write(E.join(lines))

PROTOTYPES = {
    "0x000103ba": [("return", "", "void", "Returns nothing: the result goes to *status"),
                   ("0", "can_identifier", "dword", "The 29-bit identifier: the long at +4 (move.l (0x8;a6) after link a6); shifted << 3 into the arbitration bytes"),
                   ("1", "data_length", "ushort", "The data byte count: the word at +8 (move.w (0xc;a6)); 0 gives status 1"),
                   ("2", "data", "byte*", "The data bytes: the long at +10 (movea.l (0xe;a6))"),
                   ("3", "status", "byte*", "Receives 0 sent or queued / 1 no data / 4 the transmit ring is full: the long at +14 (movea.l (0x12;a6))")],
    "0x00016cd8": [("return", "", "byte", "1 = the queue cannot take byte_count more entries (nothing queued) / 0 = queued (moveq #1 / clr.b d0)"),
                   ("0", "eeprom_address", "ushort", "The EEPROM address of the first byte: the word at +4 (move.w (0x14;a7) after saving 4 registers); +1 per byte"),
                   ("1", "source", "byte*", "The data bytes: the long at +6 (movea.l (0x16;a7))"),
                   ("2", "byte_count", "ushort", "The number of bytes: the word at +10 (move.w (0x1a;a7))")],
    "0x00018dae": [("return", "", "void", "Returns nothing"),
                   ("0", "channel_index", "ushort", "The engine protection channel: the word at +4 (cmpi.w #3;(0xc;a7) after saving 2 registers); only channel 3 acts"),
                   ("1", "channel_state_record", "void*", "The channel's state record (from 0x80d0dc): the long at +6 (movea.l (0xe;a7)); words +6 and +0x16 are read"),
                   ("2", "channel_settings_record", "void*", "The channel's settings record (from 0x807032): the long at +10 (movea.l (0x12;a7)); word +0x1e is read")],
    "0x0001e0bc": [("return", "", "void", "Returns nothing"),
                   ("0", "controller_base", "dword", "The CAN controller's base address (0xffd800 from both callers): the long at +4 (add.l (0x8;a7) after the a2 push)"),
                   ("1", "message_object_number", "byte", "The message object: the byte at +5 (move.b (0xd;a7): the low byte of the word slot at +4); x 16 from controller_base"),
                   ("2", "frame", "byte*", "The 13-byte frame record (arbitration / configuration / data): the long at +6 (movea.l (0xe;a7))")],
    "0x00021272": [("return", "", "byte", "1 = the 16-entry table is full (moveq #1;d0) / 0 = appended (clr.b d0)"),
                   ("0", "pgn_key", "ushort", "The PGN key word stored at the entry's +0: the word at +4 (move.w (0x8;a7) after the a2 push); CM848's twin names it pgn_key"),
                   ("1", "handler", "void*", "The receive handler stored at the entry's +2: the long at +6 (move.l (0xa;a7))")],
    "0x00021642": [("return", "", "char", "8 = the parameter ID is unknown (cm550_lookupParameterIdAddress failed); otherwise writeJ1939DiagnosticMemory's result"),
                   ("0", "request", "int", "The PGN 61184 request that goes on to writeJ1939DiagnosticMemory: the long at +4 (move.l (0x8;a6) after link a6)"),
                   ("1", "parameter_id", "ushort", "The e2m block ID: the word at +8 (move.w (0xc;a6)), resolved by cm550_lookupParameterIdAddress"),
                   ("2", "offset", "dword", "Added to the ID's address: the long at +10 (adda.l (0xe;a6))"),
                   ("3", "length", "dword", "The bytes to write: the long at +14 (move.l (0x12;a6))")],
    "0x0002ee62": [("return", "", "byte", "1 = the 32-entry table is full / 0 = registered (clr.b d0)"),
                   ("0", "service_id", "J1939_DIAGNOSTIC_SERVICE", "The PGN 61184 service byte: the byte at +5 (move.b (0x9;a7) after the a2 push: the low byte of the word slot at +4; callers push it with move.w)"),
                   ("1", "handler", "void*", "The service handler stored at the entry's +2: the long at +6 (move.l (0xa;a7))")],
}
NAMES = {"0x000103ba": "cm550_sendCanSingleFrame", "0x00016cd8": "cm550_queueEepromByteWrites",
         "0x00018dae": "cm550_updateEngineProtectionRestartLimitationCommands",
         "0x0001e0bc": "cm550_transmitCanFrameOnMessageObject", "0x00021272": "registerJ1939ReceiveHandler",
         "0x00021642": "writeJ1939DiagnosticMemoryByParameterId", "0x0002ee62": "registerJ1939DiagnosticService"}
p = os.path.join(OUT, "function_definitions.csv")
lines, E = load(p)
assert not any(l.split(",", 1)[0] in PROTOTYPES for l in lines if l.startswith("0x")), "a row exists already"
block = []
for a, rows in PROTOTYPES.items():
    for idx, name, typ, comment in rows:
        comment = comment.replace(", ", " - ").replace(",", ";")      # function_definitions.csv: no commas
        block.append(f"{a},{NAMES[a]},{idx},{name},{typ},{comment} {R}")
k = max(i for i, l in enumerate(lines) if l.startswith("0x")) + 1
lines[k:k] = ["# PR #53 round 96: seven functions whose decompile failed ('Cannot properly adjust input varnodes') until they had rows"] + block
open(p, "w", newline="").write(E.join(lines))
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r96h_cm550.csv"), "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, (old, new, _) in RENAMES.items():
        if old != new:
            f.write(f"{a},{new},{old},symbol,1\n")
print("plates", len(RENAMES), "prototype rows", len(block))
