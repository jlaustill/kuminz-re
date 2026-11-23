"""Round 72 stage B1: the PGN 61184 memory write service and its security key check are the same functions in CM848 and
CM550 - one shared unprefixed name per pair - and their byte tables are named in both. Idempotent; keeps line endings.
The twin proofs (both bodies, both ROMs):
- writeJ1939DiagnosticMemory (CM848 0x50af58 / CM550 0x2148a): the length cap 1764 (0x6e4) -> 2; the request length 8 /
  header + data / + 10 for the key -> else 2; the region from lookupApplicationMemoryRegionType: 0 copied / 3 copied
  after the key check / 4 -> 10 / 5 EEPROM: 7 when writes are blocked, the key check (0x1a missing / 3 refused), the
  EEPROM byte write queue (0x0b when full), the mirror copy / the other codes passed back. Versioning: a type 3 write
  without the key returns 0x1a in CM848 but 3 in CM550; CM848 also refuses (10) type 3 writes into 0x3fd481-0x40a046
  while RAM refresh is on; CM550 has no Bank 2.
- handleJ1939WriteMemoryService (CM848 0x50b408 / CM550 0x217de): service 0x4b - address from request bytes 1-4, the
  1-byte length from byte 5. handleJ1939WriteMemoryLongLengthService (0x50b474 / 0x21826): service 0x4d - the 4-byte
  length from bytes 5-8. CM550's J1939_DIAGNOSTIC_SERVICE enum already put 0x4b / 0x4d at these two.
- getJ1939MemoryServiceHeaderLength (0x50b610 / 0x21964): 0 below service 0x41, else a byte from a 14-byte table that is
  byte-identical in both ROMs (03 07 07 04 07 06 06 0b 0b 06 06 09 09 03 at 0x53a322 / 0x21956).
- validateSecurityKey (0x5573c / 0x2fcdc): 0 when the key byte is 0xff; 1 once the failure count is 0x11; else the
  10-byte key is unscrambled, its hour meter stamp checked ((meter & ~0xff) - (stamp & ~0xff) < 0x1a) and its 6
  characters compared; a match clears the failure count and returns 0, a miss adds one and returns 1.
- unscrambleSecurityKey (0x555cc / 0x2fbd8): each key bit goes to the front of the work buffer when its mask bit is 0 and
  to the back otherwise; each work byte is XORed with the work byte its byte-order entry names; the output is written
  through the byte-order table backwards. Mask and byte order are byte-identical in both ROMs (46 58 9a 32 70 87 23 99 85
  64 / 06 08 01 02 00 07 03 09 05 04 at 0x5839a + 0x583a4 / 0x2fbc4 + 0x2fbce).
usage: apply_r72b1.py <repo> <map_cm848.csv> <map_cm550.csv>"""
import os
import re
import sys

repo, map8, map5 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 72"
EOL = {}


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


def edit(p, old, new):
    s = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    write(p, s.replace(old, new))


def insert_rows(p, rows):
    """Insert global rows in address order (skips rows already there)."""
    lines = read(p).split("\n")
    for row in rows:
        if row in lines:
            continue
        a = int(row.split(",")[0], 16)
        for i, l in enumerate(lines):
            if l.startswith("0x") and int(l.split(",")[0], 16) > a:
                break
        lines.insert(i, row)
    write(p, "\n".join(lines))


# (CM848 address, CM848 old, CM550 address, CM550 old, shared name, CM550 bare names in its other CSVs)
PAIRS = [
    ("0x0050af58", "cm848_writeJ1939DiagnosticMemory", "0x0002148a", "cm550_memoryOperationDispatcher",
     "writeJ1939DiagnosticMemory", ["memoryOperationDispatcher"]),
    ("0x0050b408", "cm848_handleJ1939WriteMemoryService", "0x000217de", "cm550_memoryOperationFromMessageExtended",
     "handleJ1939WriteMemoryService", ["memoryOperationFromMessageExtended"]),
    ("0x0050b474", "cm848_handleJ1939WriteMemoryLongLengthService", "0x00021826", "cm550_FUN_00021826",
     "handleJ1939WriteMemoryLongLengthService", ["memoryOperationFromMessage8Byte"]),
    ("0x0050b610", "cm848_getJ1939MemoryServiceHeaderLength", "0x00021964", "cm550_addressLookupFunction",
     "getJ1939MemoryServiceHeaderLength", ["addressLookupFunction"]),
    ("0x0005573c", "cm848_processSecurityCodeConversion", "0x0002fcdc", "sensorRangeValidation",
     "validateSecurityKey", ["hourMeterSecurityValidator"]),
    ("0x000555cc", "cm848_copyDataBuffer", "0x0002fbd8", "cm550_FUN_0002fbd8",
     "unscrambleSecurityKey", ["bitPackingAlgorithm"]),
]
TWIN = {  # the shared-name note each plate starts with: (CM848 side, CM550 side)
    "writeJ1939DiagnosticMemory": (
        "The same function as CM550 0x2148a (shared name - CM550 returns 3 rather than 0x1a for a type 3 write without "
        "the key / has no refresh-window refusal / has no Bank 2",
        "The same function as CM848 0x50af58 (shared name - CM848 returns 0x1a for a type 3 write without the key / "
        "refuses (10) type 3 writes into its calibration RAM while RAM refresh is on / has Bank 2"),
    "handleJ1939WriteMemoryService": ("The same function as CM550 0x217de (shared name",
                                      "The same function as CM848 0x50b408 (shared name"),
    "handleJ1939WriteMemoryLongLengthService": ("The same function as CM550 0x21826 (shared name",
                                                "The same function as CM848 0x50b474 (shared name"),
    "getJ1939MemoryServiceHeaderLength": (
        "The same function and table as CM550 0x21964 / 0x21956 (shared name",
        "The same function and table as CM848 0x50b610 / 0x53a322 (shared name"),
    "validateSecurityKey": ("The same function as CM550 0x2fcdc (shared name",
                            "The same function as CM848 0x5573c (shared name"),
    "unscrambleSecurityKey": ("The same function and tables as CM550 0x2fbd8 / 0x2fbc4 / 0x2fbce (shared name",
                              "The same function and tables as CM848 0x555cc / 0x5839a / 0x583a4 (shared name"),
}
PLATE5 = {  # CM550 rows had no plate
    "writeJ1939DiagnosticMemory":
        "Writes memory for a PGN 61184 write request (services 0x4b / 0x4d): a length cap of 1764 / an optional 10-byte "
        "key after the data / the region from lookupApplicationMemoryRegionType - 0 copied / 3 copied after "
        "validateSecurityKey (3 when the key is missing or refused) / 4 refused (10) / 5 EEPROM: 7 while EEPROM writes "
        "are blocked then the key (0x1a missing / 3 refused) then cm550_circularBufferWrite (0x0b when full) and the "
        "mirror copy / the other codes passed back",
    "handleJ1939WriteMemoryService":
        "PGN 61184 service 0x4b: request bytes 1-4 the address and 5 the length then the data - written through "
        "writeJ1939DiagnosticMemory",
    "handleJ1939WriteMemoryLongLengthService":
        "PGN 61184 service 0x4d: request bytes 1-4 the address and 5-8 the length then the data - written through "
        "writeJ1939DiagnosticMemory",
    "getJ1939MemoryServiceHeaderLength":
        "The request bytes before the data for a PGN 61184 memory service: 0 below 0x41 else "
        "j1939_memory_service_header_lengths[service - 0x41] (read from its base 0x21915)",
    "validateSecurityKey":
        "Checks the 10-byte security key of a secured request: 0 (pass) when the key byte 0x803b98 is 0xff; 1 once the "
        "failure count 0x801e76 reaches 0x11 (a lockout after 17 misses); else unscrambleSecurityKey gives 6 characters "
        "(compared with ecu_identity_test_pattern) and a 4-byte hour meter stamp ((meter & ~0xff) - (stamp & ~0xff) < "
        "0x1a): a match clears the count and passes / a miss adds one and fails. Called by writeJ1939DiagnosticMemory "
        "(types 3 / 5) and diagnosticCommandDispatcher (J1708 command 3)",
    "unscrambleSecurityKey":
        "Unscrambles the 10-byte security key: each bit goes to the front of the work buffer when its "
        "security_key_scramble_mask bit is 0 and to the back otherwise / each work byte is XORed with the work byte its "
        "security_key_byte_order entry names / the output is written through security_key_byte_order backwards",
}
PLATE8_NEW = {  # CM848 rows that had no plate
    "validateSecurityKey":
        "Checks the 10-byte security key of a secured request: 0 (pass) when calibration_download_security_key_cal is "
        "0xff; 1 once security_sequence_step - the failure count - reaches 0x11 (a lockout after 17 misses); else "
        "unscrambleSecurityKey gives 6 characters (compared with the EEPROM string at 0x3fd484) and a 4-byte hour meter "
        "stamp ((key_on_hour_meter & ~0xff) - (stamp & ~0xff) < 0x1a): a match clears the count and passes / a miss adds "
        "one and fails. Called by writeJ1939DiagnosticMemory (types 3 / 5) and cm848_validateJ1939DiagnosticRequest",
    "unscrambleSecurityKey":
        "Unscrambles the 10-byte security key: each bit goes to the front of the work buffer when its "
        "security_key_scramble_mask bit is 0 and to the back otherwise / each work byte is XORed with the work byte its "
        "security_key_byte_order entry names / the output is written through security_key_byte_order backwards (its "
        "pointers start one byte before / after the table)",
}

# ---- function_renames ---------------------------------------------------------------------------------------------------
F8, F5 = os.path.join(O8, "function_renames.csv"), os.path.join(O5, "function_renames.csv")
for a8, old8, a5, old5, new, _ in PAIRS:
    t8, t5 = TWIN[new]
    s = read(F8)
    if f"\n{a8},{new}," not in s:
        if f"\n{a8},{old8}," in s:  # it has a plate: the twin note goes first
            edit(F8, f"\n{a8},{old8},", f"\n{a8},{new},{t8}; was {old8}; {R}). ")
        else:
            edit(F8, f"\n{a8},{old8}\n", f"\n{a8},{new},{PLATE8_NEW[new]}. {t8}; was {old8}; {R}).\n")
    edit(F5, f"\n{a5},{old5}\n", f"\n{a5},{new},{PLATE5[new]}. {t5}; was {old5}; {R}).\n")

# ---- CM848 function_definitions: the name column ------------------------------------------------------------------------
D8 = os.path.join(O8, "function_definitions.csv")
lines = read(D8).split("\n")
for a8, old8, _, _, new, _ in PAIRS:
    for i, l in enumerate(lines):
        if l.startswith(f"{a8},{old8},"):
            lines[i] = l.replace(f",{old8},", f",{new},", 1)
write(D8, "\n".join(lines))

# ---- CM550 function_definitions / local_variables / enums: the old bare names -> the shared names (history kept) --------
OLD_TO_NEW = {"memoryOperationDispatcher": "writeJ1939DiagnosticMemory",
              "memoryOperationFromMessageExtended": "handleJ1939WriteMemoryService",
              "memoryOperationFromMessage8Byte": "handleJ1939WriteMemoryLongLengthService",
              "addressLookupFunction": "getJ1939MemoryServiceHeaderLength",
              "hourMeterSecurityValidator": "validateSecurityKey",
              "sensorRangeValidation": "validateSecurityKey",
              "bitPackingAlgorithm": "unscrambleSecurityKey"}
NAME = re.compile(r"(?<![A-Za-z0-9_])(?<!was )(?<!\(was )(" + "|".join(OLD_TO_NEW) + r")(?![A-Za-z0-9_])")
for name in ("function_definitions.csv", "local_variables.csv", "enums.csv"):
    p = os.path.join(O5, name)
    s = read(p)
    t = NAME.sub(lambda m: OLD_TO_NEW[m.group(1)], s)
    if t != s:
        write(p, t)
# the 0x21826 notes called it an '8-byte message variant / for shorter messages': it is the 4-byte-length service 0x4d
D5 = os.path.join(O5, "function_definitions.csv")
edit(D5, "# handleJ1939WriteMemoryLongLengthService @ 0x21826 - 8-byte message variant\n"
         "# Similar to Extended but for shorter messages\n",
     f"# handleJ1939WriteMemoryLongLengthService @ 0x21826 (was memoryOperationFromMessage8Byte; {R}) - service 0x4d: "
     "the 4-byte length variant\n"
     "# Like service 0x4b but the length is request bytes 5-8\n")
L5 = os.path.join(O5, "local_variables.csv")
edit(L5, "# handleJ1939WriteMemoryLongLengthService @ 0x21826 - 8-byte variant of message handler\n",
     f"# handleJ1939WriteMemoryLongLengthService @ 0x21826 (was memoryOperationFromMessage8Byte; {R}) - service 0x4d: "
     "the 4-byte length variant\n")
# the writer's prototype: the address was read as two words ('operation_size' short + a stack word) and the length as
# 'operation_flags'; its char return - as in CM848 - keeps the region codes it passes back from naming the result
edit(D5,
     "0x0002148a,writeJ1939DiagnosticMemory,0,request_ptr,int,Pointer to memory operation request (message data)\n"
     "0x0002148a,writeJ1939DiagnosticMemory,1,operation_size,short,Size of memory operation (data bytes to write)\n"
     "0x0002148a,writeJ1939DiagnosticMemory,2,operation_flags,uint,Operation control flags from message byte 5\n",
     "0x0002148a,writeJ1939DiagnosticMemory,return,,char,The result: 0 written / 2 wrong length / 3 key missing (type "
     "3) or refused / 7 EEPROM writes blocked / 0x0a main flash / 0x0b EEPROM queue full / 0x1a key missing (EEPROM) - "
     "or the region type passed back (UNMAPPED / REFUSED); a char as in CM848 so the region codes do not name the result "
     f"({R})\n"
     "0x0002148a,writeJ1939DiagnosticMemory,0,request,int,The PGN 61184 request (+4 its data length / +6 its data "
     f"pointer) (was request_ptr; {R})\n"
     "0x0002148a,writeJ1939DiagnosticMemory,1,address,dword,The first address to write - the request's bytes 1-4 (was "
     f"operation_size short: it read the address as two words; {R})\n"
     "0x0002148a,writeJ1939DiagnosticMemory,2,length,dword,The byte count - 1764 at most (was operation_flags uint; "
     f"{R})\n")
for a5, new in (("0x000217de", "handleJ1939WriteMemoryService"), ("0x00021826", "handleJ1939WriteMemoryLongLengthService")):
    s = read(D5)
    m = re.search(rf"^{a5},{new},0,msg_ptr,int,([^\n]*)$", s, flags=re.M)
    if m:
        edit(D5, m.group(0), f"{a5},{new},0,request,int,The PGN 61184 request (was msg_ptr - {m.group(1)}; {R})")

# ---- the byte tables ----------------------------------------------------------------------------------------------------
insert_rows(os.path.join(O8, "global_variables.csv"), [
    "0x0005839a,security_key_scramble_mask,byte[10],The mask unscrambleSecurityKey routes the security key's bits by "
    f"(46 58 9a 32 70 87 23 99 85 64) - byte-identical with CM550's 0x2fbc4 ({R})",
    "0x000583a4,security_key_byte_order,byte[10],The byte order unscrambleSecurityKey XORs and writes the key by (06 08 "
    f"01 02 00 07 03 09 05 04) - byte-identical with CM550's 0x2fbce ({R})",
    "0x0053a322,j1939_memory_service_header_lengths,byte[14],The request bytes before the data for PGN 61184 services "
    "0x41-0x4e (3 7 7 4 7 6 6 11 11 6 6 9 9 3) - getJ1939MemoryServiceHeaderLength reads it from its base 0x53a2e1 "
    f"(inside j1939 input descriptor 10); byte-identical with CM550's 0x21956 ({R})",
])
insert_rows(os.path.join(O5, "global_variables.csv"), [
    "0x00021956,j1939_memory_service_header_lengths,byte[14],The request bytes before the data for PGN 61184 services "
    "0x41-0x4e (3 7 7 4 7 6 6 11 11 6 6 9 9 3) - getJ1939MemoryServiceHeaderLength reads it from its base 0x21915; "
    f"byte-identical with CM848's 0x53a322 ({R})",
    "0x0002fbc4,security_key_scramble_mask,byte[10],The mask unscrambleSecurityKey routes the security key's bits by "
    f"(46 58 9a 32 70 87 23 99 85 64) - byte-identical with CM848's 0x5839a ({R})",
    "0x0002fbce,security_key_byte_order,byte[10],The byte order unscrambleSecurityKey XORs and writes the key by (06 08 "
    f"01 02 00 07 03 09 05 04) - byte-identical with CM848's 0x583a4 ({R})",
])

with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a8, old8, _, _, new, _ in PAIRS:
        fh.write(f"{a8},{new},{old8},function,1\n")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for _, _, a5, old5, new, _ in PAIRS:
        fh.write(f"{a5},{new},{old5},function,1\n")
print("round 72 stage B1 applied")

# ---- the two service handlers' locals: one address and one length (both firmwares) ------------------------------------
# CM550 named the length 'operation_flags' and split the 4-byte address into a 2-byte auStack_8 plus a word
# 'operation_size'; CM848 had no rows (byte *local_c[2] / uint local_10 and byte *local_10 / dword local_c[2]).
L5 = os.path.join(O5, "local_variables.csv")
s = read(L5)
for a5, new, length_type, length_source in (
        ("0x000217de", "handleJ1939WriteMemoryService", "uint", "request byte 5"),
        ("0x00021826", "handleJ1939WriteMemoryLongLengthService", "dword", "request bytes 5-8")):
    rows = [l for l in s.split("\n") if l.startswith(f"{a5},{new},")]
    want = [f"{a5},{new},local_c,length,{length_type},The byte count - {length_source} (was operation_flags; {R})",
            f"{a5},{new},auStack_8,address,dword,The address - request bytes 1-4 (was address_buffer byte[2] - with "
            f"wStack_6 'operation_size' it held the address as two halves; {R})"]
    if rows != want:
        assert len(rows) == 3, rows
        s = s.replace("\n".join(rows), "\n".join(want))
write(L5, s)
L8 = os.path.join(O8, "local_variables.csv")
lines = read(L8).split("\n")
for row in (
        f"0x0050b408,handleJ1939WriteMemoryService,local_c,address,byte *,The address - request bytes 1-4 ({R})",
        f"0x0050b408,handleJ1939WriteMemoryService,local_10,length,uint,The byte count - request byte 5 ({R})",
        f"0x0050b474,handleJ1939WriteMemoryLongLengthService,local_10,address,byte *,The address - request bytes 1-4 "
        f"({R})",
        f"0x0050b474,handleJ1939WriteMemoryLongLengthService,local_c,length,dword,The byte count - request bytes 5-8 "
        f"({R})"):
    if row not in lines:
        while lines and lines[-1] == "":
            lines.pop()
        lines += [row]
write(L8, "\n".join(lines).rstrip("\n") + "\n")
print("round 72 stage B1 locals applied")
