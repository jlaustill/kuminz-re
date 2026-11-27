"""Round 63 stage A - the PGN 61184 diagnostic service vocabulary (application side).
- EF00_SERVICE_ID -> J1939_DIAGNOSTIC_SERVICE ("EF00" was the PGN in hex): 24 members named from the handlers the
  application registers with cm848_j1939RegisterDiagnosticService + the 2 responses cm848_sendJ1939ResponseFrame sends;
  each member's comment keeps its old name. Typed on the registrar's service_id parameter, on
  j1939_diagnostic_service_entry_t.service_id and on the dispatcher's service local (its other locals named).
- 23 functions renamed from their code: the 14 application memory / broadcast / address handlers (one
  cm848_handleJ1939<member>Service scheme), the 4 memory workers, both header-length helpers (the Bank 1 one returns how
  many request bytes a response repeats), the transmit buffer selector, the service 1 handler (clear inactive faults)
  and the DM3 handler that does the same.
- j1939_memory_read_reply_services (0x53a330 byte[11]): the read reply table, bytes checked in cm848_flash2_live.bin.
- firmware/CLAUDE.md: the cm848_lookupParameterIdAddress callers line (it listed 3 of the 5 callers).
Idempotent.  usage: apply_r63a.py <repo> <map.csv> <params.csv>"""
import csv
import io
import os
import re
import sys

repo, map_path, params_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 63"
ep = os.path.join(O, "enums.csv")
e = open(ep).read()
if "J1939_DIAGNOSTIC_SERVICE," in e:
    print("already applied")
    sys.exit(0)
P = "J1939_DIAGNOSTIC_SERVICE_"
MEMBERS = [
    (0x01, "CLEAR_INACTIVE_FAULTS", "cm848_requestClearInactiveFaults: sets the CLEAR_INACTIVE bit of "
     "diagnostic_clear_request_state as DM3 does"),
    (0x04, "DISABLE_BROADCAST", "cm848_handleJ1939DisableBroadcastService: cm848_updateJ1939BroadcastEnableMask with "
     "enable 0"),
    (0x05, "ENABLE_BROADCAST", "cm848_handleJ1939EnableBroadcastService: cm848_updateJ1939BroadcastEnableMask with "
     "enable 1"),
    (0x06, "COMMAND_ENGINE_SHUTDOWN", "cm848_commandEngineShutdown: sets engine_shutdown_command_flag"),
    (0x07, "EXIT_DEVELOPMENT_MODE", "cm848_exitDevelopmentMode"),
    (0x0a, "ENTER_DEVELOPMENT_MODE", "cm848_enterDevelopmentMode"),
    (0x0b, "RESTART_THROUGH_BOOT_ROM", "cm848_handleJ1939RestartService: cm848_restartThroughBootRom"),
    (0x0c, "POSITIVE_RESPONSE", "Sent by cm848_sendJ1939ResponseFrame for result 0 - then the request's first bytes "
     "(cm848_getJ1939DiagnosticResponseEchoLength); cm848_j1939DiagnosticServiceHandler ignores a received one"),
    (0x0d, "NEGATIVE_RESPONSE", "Sent by cm848_sendJ1939ResponseFrame for any other result - then the result code and "
     "the request's first bytes; cm848_j1939DiagnosticServiceHandler ignores a received one"),
    (0x0f, "NO_OPERATION_15", "cm848_j1939DiagnosticServiceAcknowledgeNoOperation: accepted and does nothing"),
    (0x10, "NO_OPERATION_16", "cm848_j1939DiagnosticServiceAcknowledgeNoOperation: accepted and does nothing"),
    (0x15, "COMMIT_EEPROM_MIRROR", "cm848_commitEepromMirrorToEeprom"),
    (0x16, "FORCE_EXIT_DEVELOPMENT_MODE", "cm848_forceExitDevelopmentMode"),
    (0x18, "INHIBIT_KEY_OFF_SHUTDOWN", "cm848_inhibitKeyOffShutdown"),
    (0x41, "GET_ADDRESS_BY_PARAMETER_ID", "cm848_handleJ1939GetAddressByParameterIdService: the ID (2 bytes); answered "
     "with 0x42 - the ID and its 4-byte address"),
    (0x43, "READ_BY_PARAMETER_ID_LONG_LENGTH", "cm848_handleJ1939ReadByParameterIdLongLengthService: the ID (2 bytes) "
     "and a length (4) read from the ID's address"),
    (0x44, "WRITE_BY_PARAMETER_ID", "cm848_handleJ1939WriteByParameterIdService: the ID (2 bytes) and a length (1) "
     "then the data"),
    (0x45, "WRITE_BY_PARAMETER_ID_LONG_LENGTH", "cm848_handleJ1939WriteByParameterIdLongLengthService: the ID (2 bytes) "
     "and a length (4) then the data"),
    (0x46, "READ_BY_PARAMETER_ID_SHORT_OFFSET", "cm848_handleJ1939ReadByParameterIdShortOffsetService: the ID (2 bytes) "
     "/ an offset (2) / a length (1)"),
    (0x47, "WRITE_BY_PARAMETER_ID_SHORT_OFFSET", "cm848_handleJ1939WriteByParameterIdShortOffsetService: the ID "
     "(2 bytes) / an offset (2) / a length (1) then the data"),
    (0x48, "READ_BY_PARAMETER_ID_LONG_OFFSET", "cm848_handleJ1939ReadByParameterIdLongOffsetService: the ID (2 bytes) "
     "/ an offset (4) / a length (4)"),
    (0x49, "WRITE_BY_PARAMETER_ID_LONG_OFFSET", "cm848_handleJ1939WriteByParameterIdLongOffsetService: the ID (2 bytes) "
     "/ an offset (4) / a length (4) then the data"),
    (0x4a, "READ_MEMORY", "cm848_handleJ1939ReadMemoryService: an address (4 bytes) and a length (1)"),
    (0x4b, "WRITE_MEMORY", "cm848_handleJ1939WriteMemoryService: an address (4 bytes) and a length (1) then the data"),
    (0x4c, "READ_MEMORY_LONG_LENGTH", "cm848_handleJ1939ReadMemoryLongLengthService: an address (4 bytes) and a "
     "length (4)"),
    (0x4d, "WRITE_MEMORY_LONG_LENGTH", "cm848_handleJ1939WriteMemoryLongLengthService: an address (4 bytes) and a "
     "length (4) then the data"),
]
HEADER = [
    "# J1939_DIAGNOSTIC_SERVICE - the PGN 61184 diagnostic service byte: the first data byte of a request or a response "
    f"(was EF00_SERVICE_ID - EF00 is the PGN in hex; {R}). Members: the services the application registers with "
    "cm848_j1939RegisterDiagnosticService (j1939_diagnostic_service_table) and the two responses "
    "cm848_sendJ1939ResponseFrame sends",
    "# Replies: 0x41 answers with 0x42 (the ID and its 4-byte address). A memory read answers with the matching write "
    "layout carrying the data (j1939_memory_read_reply_services): 0x43 -> 0x45 (0x44 under 256 bytes) / 0x46 -> 0x47 / "
    "0x48 -> 0x49 / 0x4a -> 0x4b / 0x4c -> 0x4d",
    "# The boot kernel keeps its own table (cm848_registerDiagnosticService: 2 / 7 / 0x0b / 0x10 / 0x18 / 0x19 / 0x41 / "
    "0x43-0x45 / 0x4a-0x4d) and its 7 downloads a calibration - so this enum is for the application only",
    "# Corrected here: 0x15 was GET_ADDRESS_BY_PARAM_ID but commits the EEPROM mirror (0x41 gets the address) - 0x43 was "
    "MEM_READ_2B_PARAM_4B_OFFSET but its 4-byte field is the length - 0x46 was MEM_READ_2B_PARAM_ONLY and noted NOT "
    "REGISTERED but the application registers it with an offset and a length - 0x49 was J1939_DATA_COPY but writes by "
    "parameter ID",
    "# Open: clip-core (ECUReader::readParameterService43 / 46) sends 0x43's 4 bytes as an offset and 0x46 with zeros "
    "after the ID - on CM848 those bytes are a length (0x43) and an offset and a length (0x46); a bench check is a task "
    "046 lead",
]
lines = e.split("\n")
first = next(i for i, l in enumerate(lines) if l.startswith("EF00_SERVICE_ID,"))
last = max(i for i, l in enumerate(lines) if l.startswith("EF00_SERVICE_ID,"))
top = first
while top > 0 and lines[top - 1].startswith("#"):
    top -= 1
old_names = {int(r[1], 0): r[2] for r in csv.reader(io.StringIO("\n".join(lines[first:last + 1])))}
registered = sorted(old_names)
assert registered == [v for v, _, _ in MEMBERS if v not in (0x0c, 0x0d)], registered
block = list(HEADER)
for v, name, comment in MEMBERS:
    text = comment + (f" (was {old_names[v]})" if v in old_names else "")
    assert "," not in text and '"' not in text, text
    block.append(f"J1939_DIAGNOSTIC_SERVICE,{v:#04x},{P}{name},{text},1")
for h in HEADER:
    assert "," not in h and '"' not in h, h[:60]
lines = lines[:top] + block + lines[last + 1:]
open(ep, "w").write("\n".join(lines))

dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
old = "0x000220e4,cm848_j1939RegisterDiagnosticService,0,service_id,byte,"
assert d.count(old) == 1
open(dp, "w").write(d.replace(old, "0x000220e4,cm848_j1939RegisterDiagnosticService,0,service_id,J1939_DIAGNOSTIC_SERVICE,"))

sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
old = ("j1939_diagnostic_service_entry_t,,service_id,byte,1,The PGN 61184 diagnostic service byte (the request's first "
       "data byte; its values are the EF00_SERVICE_ID enum),,verified")
assert s.count(old) == 1
open(sp, "w").write(s.replace(old, "j1939_diagnostic_service_entry_t,,service_id,J1939_DIAGNOSTIC_SERVICE,1,The PGN "
                                   "61184 diagnostic service byte (the request's first data byte; typed "
                                   f"J1939_DIAGNOSTIC_SERVICE - was EF00_SERVICE_ID in this comment; {R}),,verified"))

lp = os.path.join(O, "local_variables.csv")
lv = open(lp).read()
D = "0x00022128,cm848_j1939DiagnosticServiceHandler"
LOCALS = [("bVar1", "service", "J1939_DIAGNOSTIC_SERVICE", f"The request's service byte ({R})"),
          ("bVar2", "entry_index", "", f"Index into j1939_diagnostic_service_table ({R})"),
          ("pjVar3", "entry", "", f"The j1939_diagnostic_service_table entry being compared ({R})"),
          ("uVar4", "result_code", "", f"The validator's or the handler's result: 0xff = no response - else "
           f"cm848_sendJ1939ResponseFrame sends it ({R})")]
assert D not in lv
lv = lv.rstrip("\n") + "\n" + "\n".join(f"{D},{a},{b},{t},{c}" for a, b, t, c in LOCALS) + "\n"
open(lp, "w").write(lv)
with open(params_path, "w") as fh:
    fh.write("function,old,new\n" + "".join(f"cm848_j1939DiagnosticServiceHandler,{a},{b}\n" for a, b, _, _ in LOCALS))

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
anchor = "0x0053a33e,,pointer,"
assert g.count(anchor) == 1 and "0x0053a330," not in g
g = g.replace(anchor, "0x0053a330,j1939_memory_read_reply_services,byte[11],The reply service of each PGN 61184 memory "
                      "read - indexed by the read service - 0x43 (cm848_readJ1939DiagnosticMemoryAndRespond): 0x45 / "
                      "0x47 / 0x49 / 0x4b / 0x4d for 0x43 / 0x46 / 0x48 / 0x4a / 0x4c and 0 for the write services "
                      f"between. A 0x43 read under 256 bytes answers with 0x44 instead (set in code) ({R})\n" + anchor)
open(gp, "w").write(g)

ID_READ = "through cm848_readJ1939DiagnosticMemoryByParameterId. Registered by cm848_registerJ1939MemoryReadServices"
ID_WRITE = "through cm848_writeJ1939DiagnosticMemoryByParameterId. Registered by cm848_registerJ1939MemoryWriteServices"
FUNCS = [
    ("j1939_diagService4DisableBroadcast", "cm848_handleJ1939DisableBroadcastService",
     "PGN 61184 service 4 (J1939_DIAGNOSTIC_SERVICE_DISABLE_BROADCAST): cm848_updateJ1939BroadcastEnableMask with "
     "enable 0. Registered by cm848_registerJ1939BroadcastAndNoOperationServices"),
    ("j1939_diagService5EnableBroadcast", "cm848_handleJ1939EnableBroadcastService",
     "PGN 61184 service 5 (J1939_DIAGNOSTIC_SERVICE_ENABLE_BROADCAST): cm848_updateJ1939BroadcastEnableMask with "
     "enable 1. Registered by cm848_registerJ1939BroadcastAndNoOperationServices"),
    ("j1939_diagService65_getAddressByParameterId", "cm848_handleJ1939GetAddressByParameterIdService",
     "PGN 61184 service 0x41: resolves the request's parameter ID (bytes 1-2) with cm848_lookupParameterIdAddress and "
     "answers with service 0x42 - the ID and its 4-byte address in one 7-byte frame (mpc555_sendJ1939SingleFrame). "
     "Registered by cm848_registerJ1939GetAddressByParameterIdService"),
    ("j1939_diagService67_memoryReadByParameterId", "cm848_handleJ1939ReadByParameterIdLongLengthService",
     "PGN 61184 service 0x43: request bytes 1-2 the parameter ID and 3-6 the length - read from the ID's address "
     f"(offset 0) {ID_READ}. The reply is 0x45 (0x44 under 256 bytes)"),
    ("j1939_diagService68_memoryWriteByParameterId", "cm848_handleJ1939WriteByParameterIdService",
     "PGN 61184 service 0x44: request bytes 1-2 the parameter ID and 3 the length then the data - written at the ID's "
     f"address (offset 0) {ID_WRITE}"),
    ("j1939_diagService69_memoryWriteByParameterIdExt", "cm848_handleJ1939WriteByParameterIdLongLengthService",
     "PGN 61184 service 0x45: request bytes 1-2 the parameter ID and 3-6 the length then the data - written at the "
     f"ID's address (offset 0) {ID_WRITE}"),
    ("j1939_diagService70Handler", "cm848_handleJ1939ReadByParameterIdShortOffsetService",
     "PGN 61184 service 0x46: request bytes 1-2 the parameter ID / 3-4 the offset / 5 the length - read from the "
     f"ID's address + offset {ID_READ}. The reply is 0x47"),
    ("j1939_diagService71Handler", "cm848_handleJ1939WriteByParameterIdShortOffsetService",
     "PGN 61184 service 0x47: request bytes 1-2 the parameter ID / 3-4 the offset / 5 the length then the data - "
     f"written at the ID's address + offset {ID_WRITE}"),
    ("j1939_diagService72_memoryReadByParameterId", "cm848_handleJ1939ReadByParameterIdLongOffsetService",
     "PGN 61184 service 0x48: request bytes 1-2 the parameter ID / 3-6 the offset / 7-10 the length - read from the "
     f"ID's address + offset {ID_READ}. The reply is 0x49"),
    ("j1939_diagService73_memoryWriteByParameterId", "cm848_handleJ1939WriteByParameterIdLongOffsetService",
     "PGN 61184 service 0x49: request bytes 1-2 the parameter ID / 3-6 the offset / 7-10 the length then the data - "
     f"written at the ID's address + offset {ID_WRITE}"),
    ("j1939_diagService74_memoryRead", "cm848_handleJ1939ReadMemoryService",
     "PGN 61184 service 0x4a: request bytes 1-4 the address and 5 the length - read through "
     "cm848_readJ1939DiagnosticMemoryAndRespond. The reply is 0x4b. Registered by cm848_registerJ1939MemoryReadServices"),
    ("j1939_diagService75_memoryWrite", "cm848_handleJ1939WriteMemoryService",
     "PGN 61184 service 0x4b: request bytes 1-4 the address and 5 the length then the data - written through "
     "cm848_writeJ1939DiagnosticMemory. Registered by cm848_registerJ1939MemoryWriteServices"),
    ("j1939_diagService76_memoryReadExt", "cm848_handleJ1939ReadMemoryLongLengthService",
     "PGN 61184 service 0x4c: request bytes 1-4 the address and 5-8 the length - read through "
     "cm848_readJ1939DiagnosticMemoryAndRespond. The reply is 0x4d. Registered by cm848_registerJ1939MemoryReadServices"),
    ("j1939_diagService77_memoryWriteExt", "cm848_handleJ1939WriteMemoryLongLengthService",
     "PGN 61184 service 0x4d: request bytes 1-4 the address and 5-8 the length then the data - written through "
     "cm848_writeJ1939DiagnosticMemory. Registered by cm848_registerJ1939MemoryWriteServices"),
    ("j1939_readDiagMemoryByParameterId", "cm848_readJ1939DiagnosticMemoryByParameterId",
     "Reads by parameter ID for the PGN 61184 services 0x43 / 0x46 / 0x48: resolves the ID with "
     "cm848_lookupParameterIdAddress (8 = unknown ID) then cm848_readJ1939DiagnosticMemoryAndRespond(request / the ID's "
     "address + offset / length). Its parameters are the request / the ID / the offset / the length. Twin of the boot "
     "kernel's cm848_diagMemoryReadWithBaseOffset"),
    ("j1939_writeDiagMemoryByParameterId", "cm848_writeJ1939DiagnosticMemoryByParameterId",
     "Writes by parameter ID for the PGN 61184 services 0x44 / 0x45 / 0x47 / 0x49: resolves the ID with "
     "cm848_lookupParameterIdAddress (8 = unknown ID) then cm848_writeJ1939DiagnosticMemory(request / the ID's address "
     "+ offset / length). Its parameters are the request / the ID / the offset / the length. Twin of the boot kernel's "
     "cm848_memoryWriteByParameterId"),
    ("j1939_readDiagMemoryAndRespond", "cm848_readJ1939DiagnosticMemoryAndRespond",
     "Reads memory for a PGN 61184 read request and sends the reply: a length cap of 1764 (0x6e4) / a request length "
     "of 8 or the service's header length (cm848_getJ1939MemoryServiceHeaderLength) or that + 10 (the key) / the region "
     "from cm848_lookupApplicationMemoryRegionType. The reply service comes from j1939_memory_read_reply_services (a "
     "0x43 read under 256 bytes answers with 0x44). Twin of the boot kernel's cm848_diagMemoryReadHandler"),
    ("j1939_writeDiagMemory", "cm848_writeJ1939DiagnosticMemory",
     "Writes memory for a PGN 61184 write request: a length cap of 1764 / an optional 10-byte key after the data / the "
     "region from cm848_lookupApplicationMemoryRegionType - EEPROM (type 5) through cm848_queueEepromByteWrites or the "
     "RAM mirror / RAM (type 3) with the 0x3fd480 window protected. Twin of the boot kernel's cm848_writeDiagMemory"),
    ("j1939_getDiagServiceDataOffset", "cm848_getJ1939MemoryServiceHeaderLength",
     "The request bytes before the data for a PGN 61184 memory service: the byte at 0x53a2e1 + service and 0 below "
     "0x41. The bytes for 0x41-0x4e sit at 0x53a322: 3 / 7 / 7 / 4 / 7 / 6 / 6 / 11 / 11 / 6 / 6 / 9 / 9 / 3 (the "
     "base 0x53a2e1 falls inside input signal descriptor 10 at 0x53a2dc - so it renders as that descriptor's "
     "reserved_5). Twin of the boot kernel's cm848_getServiceDataOffset"),
    ("cm848_getLimitCategoryCode", "cm848_getJ1939DiagnosticResponseEchoLength",
     "How many request bytes a PGN 61184 response repeats after its response byte (cm848_sendJ1939ResponseFrame): the "
     "service byte and its target but never the length field. 3 for services 4 / 5 - 5 for 0x19 - the byte at 0x575dd "
     "+ service for 0x41-0x4e (at 0x5761e: 3 for the ID services without an offset / 5 with a 2-byte offset or a 4-byte "
     "address / 7 with a 4-byte offset) - else 1"),
    ("j1939_selectResponseBuffer", "cm848_selectJ1939TransmitBuffer",
     "Picks a transmit record (j1939_tx_msg_t) for a message of the given length: up to 8 bytes the single-frame record "
     "at 0x3fcbc4 (data at 0x3fcbd3 / status byte at 0x3fcbd2) - else the transport record at 0x3fc4ad (data at "
     "0x3fc4bc / status byte at 0x3fc4bb) when that status byte's high nibble is 0 - else 0. It sets the record's data "
     "length / data pointer / status pointer. Used by the PGN 61184 replies (cm848_sendJ1939ResponseFrame / "
     "cm848_readJ1939DiagnosticMemoryAndRespond) and cm848_sendDataCollectorBuffer"),
    ("cm848_advanceDiagnosticActionState", "cm848_requestClearInactiveFaults",
     "PGN 61184 service 1 (J1939_DIAGNOSTIC_SERVICE_CLEAR_INACTIVE_FAULTS): when not_safe_to_program_flag is 0 with the "
     "key on or it is 1 with algorithm_enable_flags_12_cal.obd_fault_handler_enable 0 it sets the CLEAR_INACTIVE bit "
     "of diagnostic_clear_request_state (e2m 1080 +2: 0 -> 1 / 2 -> 3) and returns DIAG_ACK - else "
     "DIAG_NACK_PROTECTED. The DM3 handler cm848_j1939HandlePgn65228Dm3ClearInactiveFaults does the same. Registered by "
     "cm848_registerJ1939DiagnosticHandlers"),
    ("cm848_j1939HandlePgn65228Dm3ClearDiag", "cm848_j1939HandlePgn65228Dm3ClearInactiveFaults",
     "DM3 (PGN 65228 - clear previously active codes) requested through PGN 59904 (j1939_pgn_dispatch_table / "
     "cm848_j1939DispatchPgnHandler): the gate and the CLEAR_INACTIVE bit of cm848_requestClearInactiveFaults (PGN "
     "61184 service 1) then an ACK or a NACK - through cm848_sendJ1939NegativeAcknowledgement when "
     "j1939_dm1_active_flag is set (which it then clears) - else cm848_sendJ1939AcknowledgeMessage"),
]
fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
original = f
mapping = ["address,name,old_label,kind,dims"]
for cur, new, plate in FUNCS:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{cur}(,[^\n]*)?$", f, re.M)
    assert m, cur
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate and '"' not in plate, cur
    old_plate = (m.group(2) or ",")[1:].strip()
    text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    f = f[:m.start()] + f"{m.group(1)},{new},{text}" + f[m.end():]
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
for old_text, new_text in [("(the j1939_diagService68-77 write handlers)", "(the cm848_handleJ1939Write*Service handlers)"),
                           ("(the j1939_diagService67-76 read handlers)", "(the cm848_handleJ1939Read*Service handlers)")]:
    assert f.count(old_text) == 1, old_text
    f = f.replace(old_text, new_text)
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")

cp = os.path.join(repo, "firmware/CLAUDE.md")
c = open(cp).read()
old = ("  - Callers: the PCI diagnostic request handler, `j1939_writeDiagMemoryByParameterId` and\n"
       "    `cm848_evaluateCalibratedMonitorDisableConditions`.\n")
new = ("  - Callers: the PCI diagnostic request handler, `cm848_evaluateCalibratedMonitorDisableConditions` and the PGN 61184\n"
       "    services that name a parameter ID: `cm848_readJ1939DiagnosticMemoryByParameterId`,\n"
       "    `cm848_writeJ1939DiagnosticMemoryByParameterId` and the 0x41 handler\n"
       "    `cm848_handleJ1939GetAddressByParameterIdService`.\n")
assert c.count(old) == 1
open(cp, "w").write(c.replace(old, new))
print(f"enum: {len(MEMBERS)} members / 2 fields typed / 4 locals / 1 global / {len(FUNCS)} functions / CLAUDE.md 1 line")
