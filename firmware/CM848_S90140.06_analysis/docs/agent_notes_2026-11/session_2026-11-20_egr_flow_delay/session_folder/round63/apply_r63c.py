"""Round 63 stage C - the boot kernel's PGN 61184 services, the twin of stages A / B.
- BOOT_DIAGNOSTIC_SERVICE (its own enum: the boot kernel's 7 downloads a calibration where the application's 7 exits
  development mode): the 14 services it registers + the 2 responses; typed on cm848_registerDiagnosticService's
  service_id, on boot_diagnostic_service_entry_t.service_id and on the boot dispatcher's service local.
- Prototypes: the read handler's three rows were wrong (address / length / response_ptr are the request / the address /
  the length); the read-by-ID worker's offset was "reserved" and its length "offset" (its add r31,r4,r31 adds the third
  parameter to the address and the fourth goes on as the length). Every handler and worker of the chain takes the
  j1939_rx_msg_t * request (cm848_dispatchDiagnosticService calls each handler with its j1939_rx_msg_t *request).
- 23 functions renamed on the application's scheme with "Boot" (cm848_handleBoot<member>Service ...): the 5
  registrars, the 12 handlers and 6 workers (CM550 has none of the old names).
- boot_kernel_rom_end: the read reply table starts at that address.
Idempotent.  usage: apply_r63c.py <repo> <map.csv>"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 63"
ep = os.path.join(O, "enums.csv")
e = open(ep).read()
if "BOOT_DIAGNOSTIC_SERVICE," in e:
    print("already applied")
    sys.exit(0)
P = "BOOT_DIAGNOSTIC_SERVICE_"
MEMBERS = [
    (0x02, "INITIALIZE_EEPROM_TRANSFER", "cm848_handleBootInitializeEepromTransferService: mpc555_initEepromTransfer(2) "
     "after a response-pending 0x96"),
    (0x07, "DOWNLOAD_CALIBRATION", "cm848_handleBootDownloadCalibrationService: mpc555_loadEepromCalibration(request / "
     "2)"),
    (0x0b, "NO_OPERATION_11", "cm848_bootDiagnosticServiceAcknowledgeNoOperation: accepted and does nothing"),
    (0x0c, "POSITIVE_RESPONSE", "Sent by cm848_sendDiagServiceResponse for result 0; cm848_dispatchDiagnosticService "
     "ignores a received one"),
    (0x0d, "NEGATIVE_RESPONSE", "Sent by cm848_sendDiagServiceResponse for a nonzero result other than 0xfe (that "
     "sends 0x0e); cm848_dispatchDiagnosticService ignores a received one"),
    (0x10, "NO_OPERATION_16", "cm848_bootDiagnosticServiceAcknowledgeNoOperation: accepted and does nothing"),
    (0x18, "NO_OPERATION_24", "cm848_bootDiagnosticServiceAcknowledgeNoOperation: accepted and does nothing"),
    (0x19, "EXECUTE_AT_ADDRESS", "cm848_handleBootExecuteAtAddressService: calls the request's 4-byte address once the "
     "positive response has left the CAN transmit ring"),
    (0x41, "GET_ADDRESS_BY_PARAMETER_ID", "cm848_handleBootGetAddressByParameterIdService: the ID (2 bytes); answered "
     "with 0x42"),
    (0x43, "READ_BY_PARAMETER_ID_LONG_LENGTH", "cm848_handleBootReadByParameterIdLongLengthService: the ID (2 bytes) "
     "and a length (4)"),
    (0x44, "WRITE_BY_PARAMETER_ID", "cm848_handleBootWriteByParameterIdService (RAM copy 0x3fb368): the ID (2 bytes) "
     "and a length (1) then the data"),
    (0x45, "WRITE_BY_PARAMETER_ID_LONG_LENGTH", "cm848_handleBootWriteByParameterIdLongLengthService (RAM copy "
     "0x3fb3d8): the ID (2 bytes) and a length (4) then the data"),
    (0x4a, "READ_MEMORY", "cm848_handleBootReadMemoryService: an address (4 bytes) and a length (1)"),
    (0x4b, "WRITE_MEMORY", "cm848_handleBootWriteMemoryService (RAM copy 0x3fb440): an address (4 bytes) and a length "
     "(1) then the data"),
    (0x4c, "READ_MEMORY_LONG_LENGTH", "cm848_handleBootReadMemoryLongLengthService: an address (4 bytes) and a length "
     "(4)"),
    (0x4d, "WRITE_MEMORY_LONG_LENGTH", "cm848_handleBootWriteMemoryLongLengthService (RAM copy 0x3fb4b8): an address "
     "(4 bytes) and a length (4) then the data"),
]
HEADER = [
    f"# BOOT_DIAGNOSTIC_SERVICE - the PGN 61184 service byte as the boot kernel reads it ({R}): the services it "
    "registers with cm848_registerDiagnosticService (diagnostic_service_dispatch_table) and the two responses "
    "cm848_sendDiagServiceResponse sends. Its 7 downloads a calibration where the application's 7 exits development "
    "mode - so it is its own enum (the application's is J1939_DIAGNOSTIC_SERVICE)",
    "# The memory services keep the application's layouts and reply pairs (0x43 -> 0x45 or 0x44 under 256 bytes / "
    "0x4a -> 0x4b / 0x4c -> 0x4d through the table at boot_kernel_rom_end); the writes run from the reflash kernel's "
    "RAM copy",
]
for h in HEADER:
    assert "," not in h and '"' not in h
block = list(HEADER)
for v, name, comment in MEMBERS:
    assert "," not in comment and '"' not in comment, comment
    block.append(f"BOOT_DIAGNOSTIC_SERVICE,{v:#04x},{P}{name},{comment},1")
lines = e.split("\n")
last = max(i for i, l in enumerate(lines) if l.startswith("J1939_DIAGNOSTIC_SERVICE,"))
lines = lines[:last + 1] + block + lines[last + 1:]
e = "\n".join(lines)
old = "and its 7 downloads a calibration - so this enum is for the application only"
assert e.count(old) == 1
e = e.replace(old, "and its 7 downloads a calibration - so this enum is for the application only (the boot kernel's "
                   "is BOOT_DIAGNOSTIC_SERVICE)")
open(ep, "w").write(e)

# the registrations match the members (values taken from the .cpp)
cpp = open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()
registered = sorted({int(v, 0) for v in re.findall(r"cm848_registerDiagnosticService\s*\(\s*(0x[0-9a-f]+|\d+)\s*,", cpp)})
assert registered == [v for v, _, _ in MEMBERS if v not in (0x0c, 0x0d)], registered

sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
rows = [r for r in s.split("\n") if r.startswith("boot_diagnostic_service_entry_t,,service_id,byte,")]
assert len(rows) == 1, rows
s = s.replace(rows[0], rows[0].replace("boot_diagnostic_service_entry_t,,service_id,byte,",
                                       "boot_diagnostic_service_entry_t,,service_id,BOOT_DIAGNOSTIC_SERVICE,", 1))
open(sp, "w").write(s)

REQUEST = ("request", "j1939_rx_msg_t*", f"The PGN 61184 request from cm848_dispatchDiagnosticService ({R})")
PROTOTYPES = {
    "0x00002c94": None,  # cm848_registerDiagnosticService: only param 0's type changes (below)
    "0x00001b48": [REQUEST, ("address", "uint", f"The first byte to read (was the length row; {R})"),
                   ("length", "uint", f"Bytes to read - at most 1764 (was the response_ptr row; {R})")],
    "0x00001cf8": [REQUEST, ("parameter_id", "ushort", f"The parameter ID that cm848_lookupBootParameterIdAddress "
                                                       f"resolves ({R})"),
                   ("offset", "uint", f"Added to the ID's address (was named reserved; {R})"),
                   ("length", "uint", f"Bytes to read (was named offset; {R})")],
    "0x00005400": [REQUEST, ("address", "uint", f"The first byte to write ({R})"),
                   ("length", "uint", f"Bytes to write ({R})")],
    "0x00005728": [REQUEST, ("parameter_id", "ushort", f"The parameter ID that cm848_lookupBootParameterIdAddress "
                                                       f"resolves ({R})"),
                   ("offset", "uint", f"Added to the ID's address ({R})"),
                   ("length", "uint", f"Bytes to write ({R})")],
}
for address in ("0x000019e8", "0x00001d5c", "0x00001dc4", "0x00001e30", "0x00005798", "0x00005808", "0x00005870",
                "0x000058e8"):
    PROTOTYPES[address] = [REQUEST]

FUNCS = [
    ("cm848_registerStandardDiagServices", "cm848_registerBootCalibrationAndNoOperationServices",
     "Boot kernel: registers its PGN 61184 services 2 (cm848_handleBootInitializeEepromTransferService) / 7 "
     "(cm848_handleBootDownloadCalibrationService) / 0x0b / 0x10 / 0x18 (cm848_bootDiagnosticServiceAcknowledgeNoOperation) "
     "in diagnostic_service_dispatch_table"),
    ("cm848_initService25Handler", "cm848_registerBootExecuteAtAddressService",
     "Boot kernel: registers service 0x19 (cm848_handleBootExecuteAtAddressService)"),
    ("cm848_initDataBasedDiagServices", "cm848_registerBootMemoryWriteServices",
     "Boot kernel (reset -> mpc555_initDiagnosticSubsystem): registers the memory write services 0x44 / 0x45 / 0x4b / "
     "0x4d with their handlers' RAM-copy addresses 0x3fb368 / 0x3fb3d8 / 0x3fb440 / 0x3fb4b8 (ROM 0x5798 / 0x5808 / "
     "0x5870 / 0x58e8 - the cm848_handleBootWrite*Service handlers). The arguments render as application variables "
     "because the running application reuses that RAM"),
    ("cm848_registerService65Handler", "cm848_registerBootGetAddressByParameterIdService",
     "Boot kernel: registers service 0x41 (cm848_handleBootGetAddressByParameterIdService)"),
    ("cm848_registerMemoryReadServices", "cm848_registerBootMemoryReadServices",
     "Boot kernel: registers the memory read services 0x43 / 0x4a / 0x4c (the cm848_handleBootRead*Service handlers)"),
    ("cm848_diagServiceAcknowledgeNoOperation", "cm848_bootDiagnosticServiceAcknowledgeNoOperation",
     "Boot kernel services 0x0b / 0x10 / 0x18: returns 0 (accepted) and does nothing. The application's twin is "
     "cm848_j1939DiagnosticServiceAcknowledgeNoOperation"),
    ("cm848_diagServiceDownloadCalibration", "cm848_handleBootDownloadCalibrationService",
     "Boot kernel service 7: mpc555_loadEepromCalibration(request / 2) then returns 0xff (the dispatcher sends no "
     "response)"),
    ("mpc555_diagServiceInitEepromTransfer", "cm848_handleBootInitializeEepromTransferService",
     "Boot kernel service 2: sends response-pending 0x96 (cm848_sendDiagResponsePending) / keeps the request in "
     "eeprom_diag_callback / starts mpc555_initEepromTransfer(2) - 0x17 when that returns 0 else 0xff"),
    ("mpc555_diagService25_executeFunction", "cm848_handleBootExecuteAtAddressService",
     "Boot kernel service 0x19: checks the request (cm848_validateDiagnosticRequestLengthAndAuthorization) / takes a "
     "4-byte address from bytes 1-4 / refuses region type 9 (cm848_lookupBootMemoryRegionType) / sends the positive "
     "response / waits at most 0x40c MIOS counter ticks for the boot CAN transmit ring to empty and calls the address"),
    ("cm848_diagService65_handler", "cm848_handleBootGetAddressByParameterIdService",
     "Boot kernel service 0x41: resolves the request's parameter ID (bytes 1-2) with cm848_lookupBootParameterIdAddress "
     "(8 when unknown) and answers with 0x42. Twin of the application's cm848_handleJ1939GetAddressByParameterIdService"),
    ("cm848_diagService67_memoryReadOffset", "cm848_handleBootReadByParameterIdLongLengthService",
     "Boot kernel service 0x43: request bytes 1-2 the parameter ID and 3-6 the length - read from the ID's address "
     "(offset 0) through cm848_readBootDiagnosticMemoryByParameterId. The 4 bytes are the length - not an offset"),
    ("cm848_diagService74_memoryRead", "cm848_handleBootReadMemoryService",
     "Boot kernel service 0x4a: request bytes 1-4 the address and 5 the length - read through "
     "cm848_readBootDiagnosticMemoryAndRespond"),
    ("cm848_diagService76_memoryReadExt", "cm848_handleBootReadMemoryLongLengthService",
     "Boot kernel service 0x4c: request bytes 1-4 the address and 5-8 the length - read through "
     "cm848_readBootDiagnosticMemoryAndRespond"),
    ("cm848_diagService68_memoryWriteByParameterId", "cm848_handleBootWriteByParameterIdService",
     "Boot reflash kernel service 0x44 (runs from its RAM copy at 0x3fb368): request bytes 1-2 the parameter ID and 3 "
     "the length then the data - through cm848_writeBootDiagnosticMemoryByParameterId"),
    ("cm848_diagService69_memoryWriteByParameterIdExt", "cm848_handleBootWriteByParameterIdLongLengthService",
     "Boot reflash kernel service 0x45 (runs from its RAM copy at 0x3fb3d8): request bytes 1-2 the parameter ID and "
     "3-6 the length then the data - through cm848_writeBootDiagnosticMemoryByParameterId"),
    ("cm848_diagService75_memoryWrite", "cm848_handleBootWriteMemoryService",
     "Boot reflash kernel service 0x4b (runs from its RAM copy at 0x3fb440): request bytes 1-4 the address and 5 the "
     "length then the data - sets diag_write_request_state.address_mode 1 and writes through "
     "cm848_writeBootDiagnosticMemory"),
    ("cm848_diagService77_memoryWriteExt", "cm848_handleBootWriteMemoryLongLengthService",
     "Boot reflash kernel service 0x4d (runs from its RAM copy at 0x3fb4b8): request bytes 1-4 the address and 5-8 the "
     "length then the data - sets diag_write_request_state.address_mode 1 and writes through "
     "cm848_writeBootDiagnosticMemory"),
    ("cm848_diagMemoryReadHandler", "cm848_readBootDiagnosticMemoryAndRespond",
     "Boot kernel: reads memory for a PGN 61184 read request and sends the reply (cm848_allocateDiagnosticResponseBuffer "
     "/ CAN ID 0xefff00): a length cap of 1764 / the request length against cm848_getBootMemoryServiceHeaderLength / "
     "the region from cm848_lookupBootMemoryRegionType. The reply service comes from the table at boot_kernel_rom_end "
     "(a 0x43 read under 256 bytes answers with 0x44). Its parameters are the request / the address / the length (the "
     "old rows said address / length / response_ptr). Twin of the application's "
     "cm848_readJ1939DiagnosticMemoryAndRespond"),
    ("cm848_diagMemoryReadWithBaseOffset", "cm848_readBootDiagnosticMemoryByParameterId",
     "Boot kernel: reads by parameter ID for service 0x43 - cm848_lookupBootParameterIdAddress (8 when unknown) then "
     "cm848_readBootDiagnosticMemoryAndRespond(request / the ID's address + offset / length). Its add r31 / r4 / r31 "
     "adds the third parameter to the address and the fourth goes on as the length (the old rows named them reserved "
     "and offset). Twin of the application's cm848_readJ1939DiagnosticMemoryByParameterId"),
    ("cm848_writeDiagMemory", "cm848_writeBootDiagnosticMemory",
     "Boot reflash kernel: writes memory for a PGN 61184 write request (the request / the address / the length). Twin "
     "of the application's cm848_writeJ1939DiagnosticMemory"),
    ("cm848_memoryWriteByParameterId", "cm848_writeBootDiagnosticMemoryByParameterId",
     "Boot reflash kernel: writes by parameter ID for services 0x44 / 0x45 - cm848_lookupBootParameterIdAddress (8 when "
     "unknown) then cm848_writeBootDiagnosticMemory(request / the ID's address + offset / length) with addressing mode "
     "0. Twin of the application's cm848_writeJ1939DiagnosticMemoryByParameterId"),
    ("cm848_getServiceDataOffset", "cm848_getBootMemoryServiceHeaderLength",
     "Boot reflash kernel: the request bytes before the data for a memory service - the byte at RAM 0x3f97cd + service "
     "(a table in the kernel image) and 0 below 0x41. Twin of the application's cm848_getJ1939MemoryServiceHeaderLength"),
    ("cm848_lookupMemoryRegionType", "cm848_lookupBootMemoryRegionType",
     "Boot reflash kernel: the region type of an address range for the boot read / write / execute services and the "
     "SCI download handlers (the application's is cm848_lookupApplicationMemoryRegionType)"),
]
fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
original = f
mapping = ["address,name,old_label,kind,dims"]
addresses = {}
for cur, new, plate in FUNCS:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{cur}(,[^\n]*)?$", f, re.M)
    assert m, cur
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate and '"' not in plate, cur
    old_plate = (m.group(2) or ",")[1:].strip()
    text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    f = f[:m.start()] + f"{m.group(1)},{new},{text}" + f[m.end():]
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
    addresses[m.group(1)] = new
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")

dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read().split("\n")
old = "0x00002c94,cm848_registerDiagnosticService,0,service_id,byte,"
hits = [i for i, l in enumerate(d) if l.startswith(old)]
assert len(hits) == 1
d[hits[0]] = d[hits[0]].replace(old, "0x00002c94,cm848_registerDiagnosticService,0,service_id,BOOT_DIAGNOSTIC_SERVICE,")
kept, removed = [], 0
for line in d:
    if line[:10] in PROTOTYPES and PROTOTYPES[line[:10]] is not None:
        removed += 1
        continue
    kept.append(line)
new_rows = []
for address, params in PROTOTYPES.items():
    if params is None:
        continue
    name = addresses.get(address)
    assert name, address
    for index, (pname, ptype, comment) in enumerate(params):
        assert "," not in comment
        new_rows.append(f"{address},{name},{index},{pname},{ptype},{comment}")
open(dp, "w").write("\n".join(kept).rstrip("\n") + "\n" + "\n".join(new_rows) + "\n")

lp = os.path.join(O, "local_variables.csv")
lv = open(lp).read()
row = (f"0x00006d24,cm848_dispatchDiagnosticService,BVar1,service,BOOT_DIAGNOSTIC_SERVICE,The request's service byte - "
       f"named as the enum type reaches it from the entry field ({R})")
assert "0x00006d24,cm848_dispatchDiagnosticService,BVar1," not in lv
open(lp, "w").write(lv.rstrip("\n") + "\n" + row + "\n")

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
old = "0x00007f60,boot_kernel_rom_end,byte,End of the boot reflash kernel image"
assert g.count(old) == 1
g = g.replace(old, "0x00007f60,boot_kernel_rom_end,byte,End of the boot reflash kernel image - and the start of the "
                   "boot read reply table that cm848_readBootDiagnosticMemoryAndRespond indexes by the read service - "
                   "0x43 (45 00 00 47 00 49 00 4b 00 4d: the same pairs as j1939_memory_read_reply_services). The name "
                   f"stays for the copy loop's bound ({R})")
open(gp, "w").write(g)
print(f"enum {len(MEMBERS)} members / {len(FUNCS)} functions / {removed} prototype rows replaced by {len(new_rows)} / "
      "1 local / boot_kernel_rom_end comment")
