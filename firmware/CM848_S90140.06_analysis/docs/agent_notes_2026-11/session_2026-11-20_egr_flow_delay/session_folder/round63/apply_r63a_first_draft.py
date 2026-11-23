"""Round 63 stage A: EF00_SERVICE_ID -> J1939_DIAGNOSTIC_SERVICE (the PGN 61184 service bytes; "EF00" was the PGN in hex),
its 24 members named from the handlers the application registers (cm848_j1939RegisterDiagnosticService), the
registrar's service_id parameter and j1939_diagnostic_service_entry_t.service_id typed with it (a pilot: the 24
constant registrations should render member names), and the two vague handlers 70 / 71 named from their request
layouts. CM550's enums.csv keeps its own unapplied EF00_SERVICE_ID copy (it renders nowhere there; its members already
differ at 0x06 / 0x49). Idempotent.  usage: apply_r63a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 63"
ep = os.path.join(O, "enums.csv")
e = open(ep).read()
if "J1939_DIAGNOSTIC_SERVICE," in e:
    print("already applied")
    sys.exit(0)
P = "J1939_DIAGNOSTIC_SERVICE_"
MEMBERS = [
    (0x01, "ADVANCE_ACTION_STATE", "cm848_advanceDiagnosticActionState (was SERVICE_QUERY_TERMINATE - a CLIP guess)"),
    (0x04, "DISABLE_BROADCAST", "j1939_diagService4DisableBroadcast"),
    (0x05, "ENABLE_BROADCAST", "j1939_diagService5EnableBroadcast"),
    (0x06, "COMMAND_ENGINE_SHUTDOWN", "cm848_commandEngineShutdown (sets engine_shutdown_command_flag)"),
    (0x07, "EXIT_DEVELOPMENT_MODE", "cm848_exitDevelopmentMode"),
    (0x0a, "ENTER_DEVELOPMENT_MODE", "cm848_enterDevelopmentMode"),
    (0x0b, "RESTART", "cm848_handleJ1939RestartService"),
    (0x0f, "NO_OPERATION_15", "cm848_j1939DiagnosticServiceAcknowledgeNoOperation (accepted - does nothing)"),
    (0x10, "NO_OPERATION_16", "cm848_j1939DiagnosticServiceAcknowledgeNoOperation (accepted - does nothing)"),
    (0x15, "COMMIT_EEPROM_MIRROR", "cm848_commitEepromMirrorToEeprom (was GET_ADDRESS_BY_PARAM_ID - wrong here)"),
    (0x16, "FORCE_EXIT_DEVELOPMENT_MODE", "cm848_forceExitDevelopmentMode"),
    (0x18, "INHIBIT_KEY_OFF_SHUTDOWN", "cm848_inhibitKeyOffShutdown"),
    (0x41, "GET_ADDRESS_BY_PARAMETER_ID", "j1939_diagService65_getAddressByParameterId"),
    (0x43, "READ_BY_PARAMETER_ID", "j1939_diagService67_memoryReadByParameterId: ID (2 bytes) + length (4) - offset 0"),
    (0x44, "WRITE_BY_PARAMETER_ID", "j1939_diagService68_memoryWriteByParameterId: ID (2 bytes) + length (1) - offset 0"),
    (0x45, "WRITE_BY_PARAMETER_ID_LONG_LENGTH",
     "j1939_diagService69_memoryWriteByParameterIdExt: ID (2 bytes) + length (4) - offset 0"),
    (0x46, "READ_BY_PARAMETER_ID_SHORT_OFFSET",
     "cm848_readJ1939DiagnosticMemoryByParameterIdShortOffset: ID (2 bytes) + offset (2) + length (1)"),
    (0x47, "WRITE_BY_PARAMETER_ID_SHORT_OFFSET",
     "cm848_writeJ1939DiagnosticMemoryByParameterIdShortOffset: ID (2 bytes) + offset (2) + length (1)"),
    (0x48, "READ_BY_PARAMETER_ID_LONG_OFFSET",
     "j1939_diagService72_memoryReadByParameterId: ID (2 bytes) + offset (4) + length (4)"),
    (0x49, "WRITE_BY_PARAMETER_ID_LONG_OFFSET",
     "j1939_diagService73_memoryWriteByParameterId: ID (2 bytes) + offset (4) + length (4) (was J1939_DATA_COPY)"),
    (0x4a, "READ_MEMORY", "j1939_diagService74_memoryRead: address (4 bytes) + length (1)"),
    (0x4b, "WRITE_MEMORY", "j1939_diagService75_memoryWrite: address (4 bytes) + length (1)"),
    (0x4c, "READ_MEMORY_LONG_LENGTH", "j1939_diagService76_memoryReadExt: address (4 bytes) + length (4)"),
    (0x4d, "WRITE_MEMORY_LONG_LENGTH", "j1939_diagService77_memoryWriteExt: address (4 bytes) + length (4)"),
]
lines = e.split("\n")
first = next(i for i, l in enumerate(lines) if l.startswith("EF00_SERVICE_ID,"))
last = max(i for i, l in enumerate(lines) if l.startswith("EF00_SERVICE_ID,"))
top = first
while top > 0 and lines[top - 1].startswith("#"):
    top -= 1
old_values = sorted(int(l.split(",")[1], 0) for l in lines[first:last + 1])
assert old_values == [v for v, _, _ in MEMBERS], old_values
block = [
    "# J1939_DIAGNOSTIC_SERVICE - the PGN 61184 diagnostic service bytes (was EF00_SERVICE_ID - EF00 is the PGN in hex; "
    "PR #53 round 63). Members are named from the handlers the application registers with "
    "cm848_j1939RegisterDiagnosticService (j1939_diagnostic_service_table)",
    "# The boot kernel registers some of the same IDs with its own handlers through cm848_registerDiagnosticService: "
    "0x0b / 0x10 / 0x18 acknowledge (no operation) - 0x19 - 0x41 - 0x43 / 0x4a / 0x4c memory reads",
    "# Corrected here: 0x15 was named GET_ADDRESS_BY_PARAM_ID but commits the EEPROM mirror (0x41 gets the address); "
    "0x46 was noted NOT REGISTERED but the application registers it; 0x49 was J1939_DATA_COPY but writes by parameter ID",
]
for v, name, handler in MEMBERS:
    assert "," not in handler
    block.append(f"J1939_DIAGNOSTIC_SERVICE,{v:#04x},{P}{name},{handler},1")
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
s = s.replace(old, "j1939_diagnostic_service_entry_t,,service_id,J1939_DIAGNOSTIC_SERVICE,1,The PGN 61184 diagnostic "
                   "service byte (the request's first data byte; typed J1939_DIAGNOSTIC_SERVICE - was EF00_SERVICE_ID in "
                   "this comment; PR #53 round 63),,verified")
open(sp, "w").write(s)

fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
mapping = ["address,name,old_label,kind,dims"]
for cur, new, plate in [
        ("j1939_diagService70Handler", "cm848_readJ1939DiagnosticMemoryByParameterIdShortOffset",
         "PGN 61184 service 0x46 (70): reads by parameter ID with a 2-byte offset and a 1-byte length (request bytes "
         "1-2 the ID / 3-4 the offset / 5 the length) through j1939_readDiagMemoryByParameterId. Registered by "
         "cm848_registerJ1939MemoryReadServices"),
        ("j1939_diagService71Handler", "cm848_writeJ1939DiagnosticMemoryByParameterIdShortOffset",
         "PGN 61184 service 0x47 (71): writes by parameter ID with a 2-byte offset and a 1-byte length (request bytes "
         "1-2 the ID / 3-4 the offset / 5 the length) through j1939_writeDiagMemoryByParameterId. Registered by "
         "cm848_registerJ1939MemoryWriteServices")]:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{cur}(,[^\n]*)?$", f, re.M)
    assert m, cur
    assert not re.search(rf"\b{new}\b", f), new
    old_plate = (m.group(2) or ",")[1:].strip()
    f = (f[:m.start()] + f"{m.group(1)},{new},{plate} (was {cur}; {R})"
         + (f" | earlier note: {old_plate}" if old_plate else "") + f[m.end():])
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"enum renamed with {len(MEMBERS)} members, 2 types set, 2 functions renamed")
