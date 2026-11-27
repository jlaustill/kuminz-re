"""Round 72 stage A2: CM550 already modeled the region codes as MEMORY_ACCESS_FLAG (and J90280.05's table bounds as the
enum VALID_MEMORY_RANGE) - merge instead of duplicating: MEMORY_REGION_TYPE takes MEMORY_ACCESS_FLAG's place (the old
member names stay as history), the J90280.05 table bounds in the comments give way to J90350's (decoded from ROM
0x345dc), and the headers / README box / service 0x4B doc name the shared lookup. Idempotent; keeps line endings.
usage: apply_r72a2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 72"
E = "MEMORY_REGION_TYPE"
N = "lookupApplicationMemoryRegionType"
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


ENUMS = os.path.join(O5, "enums.csv")
# 1. stage A appended the enum at the end - it moves into MEMORY_ACCESS_FLAG's place
s = read(ENUMS)
tail_start = s.find(f"# {E} - the type byte of an application_memory_region_table entry (ROM 0x345dc)")
if tail_start != -1:
    s = s[:tail_start].rstrip("\n") + "\n"
    write(ENUMS, s)
HEADER_OLD = "# Memory Access Flags - from address_range_validation_table entries (byte 8=special_mode byte 9=normal_mode)\n"
HEADER_NEW = (f"# {E} (was MEMORY_ACCESS_FLAG; {R}) - the type bytes of application_memory_region_table @ ROM 0x345dc "
              f"(byte 8 while the development mode flag at 0x80de30 is 1 / byte 9 otherwise) read by {N} @ 0x3460e: the "
              "same function and codes as CM848's (CM848 adds 2 = Bank 2 flash). The memory write service at 0x2148a "
              "branches on it; 9 and 10 go back as its result.\n"
              "# (The READ / WRITE notes below are the J90280.05 analysis - its addresses:)\n")
edit(ENUMS, HEADER_OLD, HEADER_NEW)
FLAGS_OLD = (
    "MEMORY_ACCESS_FLAG,0x00,DIRECT_ACCESS,READ: Allowed | WRITE: Direct access no security check (Extended RAM),1\n"
    "MEMORY_ACCESS_FLAG,0x03,SECURITY_REQUIRED,READ: Allowed | WRITE: Requires security check or bypass (RAM),1\n"
    "MEMORY_ACCESS_FLAG,0x04,MEMORY_ACCESS_WRITE_DENIED,READ: Allowed | WRITE: Denied - returns error 0x0A (Flash/ROM),1\n"
    "MEMORY_ACCESS_FLAG,0x05,LOGGING_MODE,READ: Allowed | WRITE: Requires system_logging_state check (EEPROM),1\n"
    "MEMORY_ACCESS_FLAG,0x09,RANGE_INVALID,READ: Denied | WRITE: Error - address not in validation table,1\n"
    "MEMORY_ACCESS_FLAG,0x0A,ACCESS_DENIED,READ: Denied | WRITE: Error - explicitly blocked region,1\n")
FLAGS_NEW = (
    f"{E},0x00,{E}_RAM,Copied without a check: the extended RAM 0x8091dc-0x80ffff (was MEMORY_ACCESS_FLAG "
    f"DIRECT_ACCESS; {R}),1\n"
    f"{E},0x03,{E}_AUTHORIZATION_REQUIRED,Copied after the security code check: RAM 0x800000-0x8091dc and - while the "
    f"development mode flag is 1 - the registers 0xffc800-0xffffff (was MEMORY_ACCESS_FLAG SECURITY_REQUIRED; {R}),1\n"
    f"{E},0x04,{E}_MAIN_FLASH,Main flash 0x0-0x7ffff: the memory write service refuses it (10) (was MEMORY_ACCESS_FLAG "
    f"MEMORY_ACCESS_WRITE_DENIED; {R}),1\n"
    f"{E},0x05,{E}_EEPROM,EEPROM 0x1000000-0x1001fff: written after the security code check (was MEMORY_ACCESS_FLAG "
    f"LOGGING_MODE - the range is the EEPROM; {R}),1\n"
    f"{E},0x09,{E}_UNMAPPED,No entry holds the range or it wraps past 0xffffffff - passed back as the result (was "
    f"MEMORY_ACCESS_FLAG RANGE_INVALID; {R}),1\n"
    f"{E},0x0a,{E}_REFUSED,The registers while the development mode flag is not 1 - passed back as the result (was "
    f"MEMORY_ACCESS_FLAG ACCESS_DENIED; {R}),1\n")
edit(ENUMS, FLAGS_OLD, FLAGS_NEW)
# 2. J90280.05's table in the service 0x4A notes -> J90350's (ROM 0x345dc)
edit(ENUMS,
     "# - Accessible regions defined in address_range_validation_table @ 0x2b512:\n"
     "#   * Flash/ROM: 0x00000000-0x0003FFFF (256KB) - flags 0x04/0x04\n"
     "#   * RAM: 0x00800000-0x008091C2 (37KB) - flags 0x03/0x03\n"
     "#   * Extended RAM: 0x008091C2-0x0080FFFF (28KB) - flags 0x00/0x00\n"
     "#   * EEPROM: 0x01000000-0x01000FFF (4KB) - flags 0x05/0x05\n"
     "#   * High Memory: 0x00FFC800-0x00FFFFFF (14KB) - flags 0x03/0x0A (blocked in normal mode)\n",
     f"# - Accessible regions: application_memory_region_table @ ROM 0x345dc (J90280.05: 0x2b512; {R}):\n"
     "#   * Flash/ROM: 0x00000000-0x0007FFFF - types 0x04/0x04\n"
     "#   * RAM: 0x00800000-0x008091DC - types 0x03/0x03\n"
     "#   * Extended RAM: 0x008091DC-0x0080FFFF - types 0x00/0x00\n"
     "#   * EEPROM: 0x01000000-0x01001FFF - types 0x05/0x05\n"
     "#   * High Memory: 0x00FFC800-0x00FFFFFF - types 0x03/0x0A (REFUSED unless the development mode flag is 1)\n")
# 3. VALID_MEMORY_RANGE held J90280.05's bounds as an enum (renders nowhere; the table itself is typed now)
edit(ENUMS,
     "# Address Range Validation Table - addressRangeValidator @ 0x2b544 uses table @ 0x2b512\n"
     "# 5 entries x 10 bytes each (start_addr[4] + end_addr[4] + flag1[1] + flag2[1])\n"
     "# Error 0x09 returned if address outside these ranges\n"
     "VALID_MEMORY_RANGE,0x00000000,FIRMWARE_START,Valid firmware region start (256KB code space),4\n"
     "VALID_MEMORY_RANGE,0x0003FFFF,FIRMWARE_END,Valid firmware region end,4\n"
     "VALID_MEMORY_RANGE,0x00800000,RAM_START,Valid RAM region start (~37KB data),4\n"
     "VALID_MEMORY_RANGE,0x008091C2,RAM_END,Valid RAM region end,4\n",
     f"# (VALID_MEMORY_RANGE - J90280.05's table bounds held as an enum - removed in {R}: J90350's table is "
     "application_memory_region_table @ ROM 0x345dc, typed as memory_region_t[5])\n")
edit(ENUMS,
     "DIAG_ERROR_SOURCE,0x09,ADDR_RANGE_INVALID,addressRangeValidator @ 0x2b544 - address not in "
     "address_range_validation_table @ 0x2b512,1\n",
     f"DIAG_ERROR_SOURCE,0x09,ADDR_RANGE_INVALID,{N} @ 0x3460e ({E}_UNMAPPED) - the range is in no "
     f"application_memory_region_table entry (J90280.05: addressRangeValidator @ 0x2b544; {R}),1\n")
edit(ENUMS,
     "DIAG_ERROR_SOURCE,0x0A,ADDR_ACCESS_DENIED,addressRangeValidator @ 0x2b544 - normal_mode_flag=0x0A blocks access "
     "(high memory 0xFFC800-0xFFFFFF in normal mode),1\n",
     f"DIAG_ERROR_SOURCE,0x0A,ADDR_ACCESS_DENIED,{N} @ 0x3460e ({E}_REFUSED) - the registers 0xffc800-0xffffff while "
     f"the development mode flag is not 1 (J90280.05: addressRangeValidator @ 0x2b544; {R}),1\n")
# 4. headers
edit(os.path.join(O5, "function_definitions.csv"),
     "# addressRangeValidator @ 0x3460e - Validates memory address against 5-entry range table\n"
     "# Returns: MEMORY_ACCESS_FLAG (0=direct, 3=secured, 4=denied, 5=logging, 9=invalid)\n",
     f"# {N} @ 0x3460e (was addressRangeValidator) - the type of the application_memory_region_table entry holding a "
     "range\n"
     f"# Returns: {E} (was MEMORY_ACCESS_FLAG; {R})\n")
edit(os.path.join(O5, "local_variables.csv"),
     "# addressRangeValidator @ 0x3460e - Validates memory address against range table\n",
     f"# {N} @ 0x3460e (was addressRangeValidator; {R}) - the region type lookup\n")
# 5. the README's write-path diagram: the lookup box (same widths)
README = os.path.join(repo, "README.md")
edit(README, "addressRangeValidator               │", f"{N}   │")
edit(README, "  validation table @ 0x801be8       │", "  region table @ ROM 0x345dc        │")
edit(README, "Returns MEMORY_ACCESS_FLAG:         │", f"Returns {E}:         │")
# 6. the service 0x4B analysis: a name map (the J90280.05 comparison stays as written)
DOC = os.path.join(repo, "firmware/docs/service_0x4b_analysis.md")
edit(DOC, "\nCross-firmware comparison of the J1939 memory write implementation",
     f"\n> **Current names ({R}):** J90350.00's `addressRangeValidator` (0x3460e) is `{N}` - the same function as CM848 "
     "0x50d784, so the two firmwares share the name - and `MEMORY_ACCESS_FLAG` is `MEMORY_REGION_TYPE` (0 RAM / 3 "
     "AUTHORIZATION_REQUIRED / 4 MAIN_FLASH / 5 EEPROM / 9 UNMAPPED / 10 REFUSED: CM848's codes, which add 2 = Bank 2 "
     "flash); its table is `application_memory_region_table` at ROM 0x345dc (5 entries; CM848 has 7).\n"
     "\nCross-firmware comparison of the J1939 memory write implementation")
print("round 72 stage A2 applied")
