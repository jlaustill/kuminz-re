"""Round 71 stage A: MEMORY_REGION_TYPE - the type codes of both kernels' memory region maps. Idempotent (each
change keys on its row and skips when the new text is there).
- Both maps (the boot one at 0x3f9830, the application's at Bank 2 0x53a33a) decode to the same codes, and their
  readers branch the same way: 0 plain copy / 3 and 5 after the write authorization / 2 Bank 2 / 4 main flash (the boot
  worker programs it, the application writer refuses it) / 9 and 10 passed back as the service result - which is why
  the result enums share those numbers (J1939_DIAGNOSTIC_RESULT_UNMAPPED_ADDRESS / _REGION_REFUSED; the boot read
  handler tests 9 and 10 too).
- memory_region_t's second type byte is the application's type when development mode is OFF (its first is the ON
  type and the boot kernel's); the boot table has both equal, so 'region_type_copy' described only that table.
- The first match wins, so the boot type 3 entry (0x2fc000-0x307fff) is effectively 0x2fc000-0x301fff; the RAM entry
  0x302000-0x3fffff takes the TPU / TouCAN registers. The application map leaves out the dual-port TPU RAM 0x302000-
  0x3037ff (9: emulation mode takes it from the CPU - round 70).
usage: apply_r71a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 71"
E = "MEMORY_REGION_TYPE"


def load(name):
    return open(os.path.join(O, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(O, name), "w").write("\n".join(lines))


def one(lines, pred, what):
    idx = [i for i, l in enumerate(lines) if pred(l)]
    assert len(idx) == 1, (what, len(idx))
    return idx[0]


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


# ---- enums.csv ---------------------------------------------------------------------------------------------------------
ENUM = [
    f"# {E} - the type byte of a memory region map entry: boot_memory_region_table (0x3f9830) and "
    f"application_memory_region_table (0x53a33a) - read by cm848_lookupBootMemoryRegionType / "
    f"cm848_lookupApplicationMemoryRegionType ({R}). 9 and 10 double as the service result.",
    f"{E},0x00,{E}_RAM,Written by a plain copy: boot 0x302000-0x3fffff (the first match - so the TPU / TouCAN registers "
    "from 0x304000 resolve here too) / application 0x40c26e-0x43ffff,1",
    f"{E},0x02,{E}_BANK_2_FLASH,Bank 2 flash from 0x500000: the boot worker writes it through "
    "eeprom_xfer_state.flash2_write_callback (the boot lookup answers UNMAPPED instead while flash2_writes_enabled is "
    "0); the application writer passes the code back,1",
    f"{E},0x03,{E}_AUTHORIZATION_REQUIRED,Written after the write authorization (cm848_validateWriteAuth / "
    "cm848_processSecurityCodeConversion): boot 0x2fc000-0x301fff (its entry reads 0x2fc000-0x307fff but the RAM entry "
    "matches the rest first) / application 0x3fa000-0x40c26e and - in development mode - its register ranges,1",
    f"{E},0x04,{E}_MAIN_FLASH,Main flash 0x0-0x6ffff: the boot worker programs it (cm848_dataTransferBufferWrite); the "
    "application writer refuses it (J1939_DIAGNOSTIC_RESULT_REGION_REFUSED),1",
    f"{E},0x05,{E}_EEPROM,EEPROM from 0x1000000: written after the write authorization (boot "
    "eeprom_xfer_state.eeprom_write_callback / application cm848_queueEepromByteWrites),1",
    f"{E},0x09,{E}_UNMAPPED,No entry holds the range - the application map leaves out the dual-port TPU RAM "
    "0x302000-0x3037ff that emulation mode takes from the CPU - or Bank 2 in the boot kernel while "
    "flash2_writes_enabled is 0; the readers and writers pass it back as the result "
    "(J1939_DIAGNOSTIC_RESULT_UNMAPPED_ADDRESS / BOOT_DIAGNOSTIC_RESULT_ADDRESS_NOT_ACCEPTED),1",
    f"{E},0x0a,{E}_REFUSED,The application's register ranges while development mode is off "
    "(development_mode_off_region_type); passed back as J1939_DIAGNOSTIC_RESULT_REGION_REFUSED - the boot read "
    "handler tests it too,1",
]
lines = load("enums.csv")
if ENUM[1] not in lines:
    i = one(lines, lambda l: l.startswith("BOOT_REQUEST_CHANNEL,0x03,"), "channel 3")
    lines[i + 1:i + 1] = ENUM
    save("enums.csv", lines)
edit("enums.csv", "(382fa677 named it REGION_REFUSED),4",
     "(382fa677 named it REGION_REFUSED) - though the boot read handler still tests 10: the code it shares with the "
     f"application, where 10 is {E}_REFUSED ({R}),4")

# ---- structure_definitions.csv -----------------------------------------------------------------------------------------
T = "structure_definitions.csv"
edit(T, "memory_region_t,0x003f9830,region_type,byte,1,0 RAM / 2 Bank-2 flash / 3 registers / 4 main flash / 5 EEPROM "
        "(9 = not found),,verified",
     f"memory_region_t,0x003f9830,region_type,{E},1,The type - the boot kernel's / the application's while "
     f"development_mode is ON ({R}: was byte '0 RAM / 2 Bank-2 flash / 3 registers / 4 main flash / 5 EEPROM (9 = not "
     "found)'),,verified")
edit(T, "memory_region_t,0x003f9830,region_type_copy,byte,1,Same value as region_type in every entry,,verified",
     f"memory_region_t,0x003f9830,development_mode_off_region_type,{E},1,The application's type while development_mode "
     "is OFF (cm848_lookupApplicationMemoryRegionType): its register ranges become REFUSED; equal to region_type in "
     f"boot_memory_region_table ({R}: was region_type_copy 'Same value as region_type in every entry' - true of the "
     "boot table only),,verified")
edit(T, "# --- memory_region_t: boot reflash kernel write-permission map (6 x 10 bytes @ RAM 0x3f9830 = ROM 0x3c60) ---",
     "# --- memory_region_t: a write-permission map entry - boot_memory_region_table (6 x 10 bytes @ RAM 0x3f9830 = ROM "
     f"0x3c60) and application_memory_region_table (7 @ 0x53a33a); the first matching entry wins ({R}) ---")
edit(T, "memory_region_t,0x003f9862,,,,region 5 0x2fc000-0x307fff internal registers - marker,,verified",
     "memory_region_t,0x003f9862,,,,region 5 0x2fc000-0x307fff type 3 - effectively 0x2fc000-0x301fff: region 3 matches "
     "the rest first - marker,,verified")

# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"
lines = load(G)
i = one(lines, lambda l: l.startswith("0x003f9830,"), "boot table")
if not lines[i].startswith("0x003f9830,boot_memory_region_table,"):
    assert lines[i].startswith("0x003f9830,memory_region_table,memory_region_t,"), lines[i]
    lines[i] = lines[i].replace("0x003f9830,memory_region_table,", "0x003f9830,boot_memory_region_table,", 1) + \
        f" (was memory_region_table; {R})"
APP = ("0x0053a33a,application_memory_region_table,memory_region_t[7],The application's write-permission map (7 x 10 "
       "bytes; it follows j1939_memory_read_reply_services): main flash 4 / Bank 2 0x500000-0x53ffff 2 / 0x3fa000-0x40c26e "
       "3 / 0x40c26e-0x43ffff 0 / EEPROM 0x1000000-0x1001fff 5 / registers 0x2fc000-0x301fff and 0x303800-0x307fff 3 in "
       "development mode else 10 - read by cm8"
       f"48_lookupApplicationMemoryRegionType ({R})")
if APP not in lines:
    for dead in ("0x0053a33e,,pointer,", "0x0053a344,,pointer,"):
        lines.remove(dead)
    j = one(lines, lambda l: l.startswith("0x0053a330,j1939_memory_read_reply_services,"), "reply services")
    lines.insert(j + 1, APP)
i = one(lines, lambda l: l.startswith("0x003fee05,"), "0x3fee05")
if lines[i] == "0x003fee05,sensor_fault_threshold_state,byte,":
    lines[i] = (f"0x003fee05,serial_download_region_type,{E},Boot kernel: the region type of the serial download "
                "block - mpc555_sciHandleDownloadDataBlock stores cm848_lookupBootMemoryRegionType's answer and branches "
                "on it (Bank 2 / main flash / EEPROM) | application side: the EEPROM mirror byte 0x1983 - no application "
                f"use found (was sensor_fault_threshold_state; {R})")
save(G, lines)

# ---- function_definitions.csv ------------------------------------------------------------------------------------------
D = "function_definitions.csv"
lines = load(D)
tail = [""] if lines and lines[-1] == "" else []
body = lines[:-1] if tail else lines
NEW = [
    ("0x000076c8", "cm848_lookupBootMemoryRegionType", [
        ("return", "", E, "The first boot_memory_region_table entry holding the range - UNMAPPED for none or for Bank 2 "
                          "while flash2_writes_enabled is 0"),
        ("0", "address", "uint", "The range's first address"),
        ("1", "length", "int", "Its length in bytes")]),
    ("0x0050d784", "cm848_lookupApplicationMemoryRegionType", [
        ("return", "", E, "The first application_memory_region_table entry holding the range (its development-mode-off "
                          "type unless development_mode is ON) - UNMAPPED for none"),
        ("0", "address", "uint", "The range's first address"),
        ("1", "length", "int", "Its length in bytes")]),
    ("0x00005400", "cm848_writeBootDiagnosticMemory", [
        ("return", "", "byte", "The result - including the region type when it is above EEPROM (the asm returns it at "
                               "0x5710); a byte so the region codes do not name the result")]),
    ("0x0050af58", "cm848_writeJ1939DiagnosticMemory", [
        ("return", "", "char", "The result - including the region type for Bank 2 / UNMAPPED / REFUSED; a char so the "
                               "region codes do not name the result")]),
]
for addr, func, rows in NEW:
    for index, name, typ, comment in rows:
        key = f"{addr},{func},{index},"
        if any(l.startswith(key) for l in body):
            continue
        body.append(f"{key}{name},{typ},{comment} ({R})")
save(D, body + tail)

# ---- function_renames.csv: plates ----------------------------------------------------------------------------------------
F = "function_renames.csv"
edit(F, "0x000076c8,cm848_lookupBootMemoryRegionType,Boot reflash kernel: the region type of an address range for the "
        "boot read / write / execute services",
     f"0x000076c8,cm848_lookupBootMemoryRegionType,Boot reflash kernel: the region type ({E}; its type 3 entry - "
     f"AUTHORIZATION_REQUIRED - is effectively 0x2fc000-0x301fff because the first match wins; {R}) of an address range "
     "for the boot read / write / execute services")
edit(F, "Application twin of the boot cm848_lookupBootMemoryRegionType: type of the 0x53a33a region",
     f"Application twin of the boot cm848_lookupBootMemoryRegionType ({E}): type of the application_memory_region_table "
     "(0x53a33a) entry")

with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x003f9830,boot_memory_region_table,memory_region_table,global,1\n"
             "0x003fee05,serial_download_region_type,sensor_fault_threshold_state,global,1\n")
print("round 71 stage A applied")
