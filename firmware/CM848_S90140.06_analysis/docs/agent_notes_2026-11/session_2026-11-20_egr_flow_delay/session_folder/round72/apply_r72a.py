"""Round 72 stage A: the application memory region lookup is the same function in CM848 (0x50d784) and CM550
(0x3460e) - one shared unprefixed name, lookupApplicationMemoryRegionType - and CM550 gets MEMORY_REGION_TYPE,
memory_region_t and its 5-entry table. Idempotent.
The twin proof (both bodies): range end = start + length - 1 (CM550 returns 9 when it wraps); the table is scanned
entry by entry for start <= range start and range end <= end; the type is the entry's byte +8 when the mode flag is 1
(CM848 development_mode == DEVELOPMENT_MODE_ON / CM550 the byte at 0x80de30) else its byte +9; 9 when no entry holds
the range. CM550's table (ROM 0x345dc, 5 x 10 bytes; the lookup's code follows at 0x3460e): main flash 0x0-0x7ffff 4/4 /
RAM 0x800000-0x8091dc 3/3 / extended RAM 0x8091dc-0x80ffff 0/0 / EEPROM 0x1000000-0x1001fff 5/5 / registers
0xffc800-0xffffff 3/10 - CM848's codes; CM550 has no Bank 2.
usage: apply_r72a.py <repo> <map_cm848.csv> <map_cm550.csv>"""
import os
import sys

repo, map8, map5 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 72"
E = "MEMORY_REGION_TYPE"
N = "lookupApplicationMemoryRegionType"


EOL = {}  # each file keeps its own line ending (CM550's structure_definitions.csv is CRLF)


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


def load(o, name):
    return read(os.path.join(o, name)).split("\n")


def save(o, name, lines):
    write(os.path.join(o, name), "\n".join(lines))


def edit(o, name, old, new):
    p = os.path.join(o, name)
    s = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    write(p, s.replace(old, new))


# ---- CM848: the shared name ---------------------------------------------------------------------------------------------
OLD8 = "0x0050d784,cm848_lookupApplicationMemoryRegionType,Application twin of the boot cm848_lookupBootMemoryRegionType"
NEW8 = (f"0x0050d784,{N},The same function as CM550 0x3460e (shared name - there 5 entries and no Bank 2; was "
        f"cm848_lookupApplicationMemoryRegionType; {R}). Application twin of the boot cm848_lookupBootMemoryRegionType")
edit(O8, "function_renames.csv", OLD8, NEW8)
lines = load(O8, "function_definitions.csv")
for i, l in enumerate(lines):
    if l.startswith("0x0050d784,cm848_lookupApplicationMemoryRegionType,"):
        lines[i] = l.replace(",cm848_lookupApplicationMemoryRegionType,", f",{N},", 1)
assert sum(l.startswith(f"0x0050d784,{N},") for l in lines) == 3
save(O8, "function_definitions.csv", lines)

# ---- CM550: the enum ----------------------------------------------------------------------------------------------------
ENUM = [
    f"# {E} - the type byte of an application_memory_region_table entry (ROM 0x345dc) - read by {N} (the same function "
    f"as CM848 0x50d784; {R}). The memory write service at 0x2148a branches on it; 9 and 10 go back as its result.",
    f"{E},0x00,{E}_RAM,Copied without a check: the extended RAM 0x8091dc-0x80ffff,1",
    f"{E},0x03,{E}_AUTHORIZATION_REQUIRED,Copied after the security code check: RAM 0x800000-0x8091dc and - while the "
    "development mode flag is 1 - the registers 0xffc800-0xffffff,1",
    f"{E},0x04,{E}_MAIN_FLASH,Main flash 0x0-0x7ffff: the memory write service refuses it (10),1",
    f"{E},0x05,{E}_EEPROM,EEPROM 0x1000000-0x1001fff: written after the security code check,1",
    f"{E},0x09,{E}_UNMAPPED,No entry holds the range or it wraps past 0xffffffff - passed back as the result,1",
    f"{E},0x0a,{E}_REFUSED,The registers while the development mode flag is not 1 - passed back as the result,1",
]
lines = load(O5, "enums.csv")
if not any(l.startswith(f"{E},0x00,") for l in lines):  # stage A2 moves it into MEMORY_ACCESS_FLAG's place
    while lines and lines[-1] == "":
        lines.pop()
    lines += ENUM + [""]
    save(O5, "enums.csv", lines)

# ---- CM550: the struct template (type-only rows: an instance row would add a second copy of each field) ----------------
STRUCT = [
    "# --- memory_region_t: a write-permission map entry - application_memory_region_table (5 x 10 bytes @ ROM 0x345dc); "
    f"the first matching entry wins; the layout of CM848's memory_region_t ({R}) ---",
    "memory_region_t,,start_address,dword,4,First address of the region,,verified",
    "memory_region_t,,end_address,dword,4,Last address of the region (inclusive),,verified",
    f"memory_region_t,,region_type,{E},1,The type while the development mode flag (0x80de30) is 1,,verified",
    f"memory_region_t,,development_mode_off_region_type,{E},1,The type while the development mode flag is not 1 (the "
    "registers become REFUSED),,verified",
]
lines = load(O5, "structure_definitions.csv")
if STRUCT[1] not in lines:
    while lines and lines[-1] == "":
        lines.pop()
    lines += STRUCT + [""]
    save(O5, "structure_definitions.csv", lines)

# ---- CM550: the table ---------------------------------------------------------------------------------------------------
TABLE = (f"0x000345dc,application_memory_region_table,memory_region_t[5],The application's write-permission map (5 x 10 "
         "bytes; the lookup's code follows at 0x3460e): main flash 0x0-0x7ffff 4 / RAM 0x800000-0x8091dc 3 / extended RAM "
         "0x8091dc-0x80ffff 0 / EEPROM 0x1000000-0x1001fff 5 / registers 0xffc800-0xffffff 3 while the development mode "
         f"flag is 1 else 10 - read by {N} ({R})")
lines = load(O5, "global_variables.csv")
if TABLE not in lines:
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > 0x345dc:
            break
    lines.insert(i, TABLE)
    save(O5, "global_variables.csv", lines)

# ---- CM550: the function ------------------------------------------------------------------------------------------------
edit(O5, "function_renames.csv", "0x0003460e,cm550_addressRangeValidator\n",
     f"0x0003460e,{N},The type (MEMORY_REGION_TYPE) of the first application_memory_region_table entry holding "
     "range_start..range_start+range_length-1 - its first type byte while the development mode flag (0x80de30) is 1 "
     "else its second - or UNMAPPED (9) for none or a range that wraps: the same function as CM848 0x50d784 (shared "
     f"name; was cm550_addressRangeValidator; {R})\n")
edit(O5, "function_definitions.csv",
     "0x0003460e,addressRangeValidator,0,target_address,uint,Memory address to validate (start of operation)\n"
     "0x0003460e,addressRangeValidator,1,operation_length,uint,Length of memory operation in bytes\n",
     f"0x0003460e,{N},return,,{E},The first application_memory_region_table entry holding the range - UNMAPPED for "
     f"none ({R})\n"
     f"0x0003460e,{N},0,range_start,uint,The range's first address (was target_address; {R})\n"
     f"0x0003460e,{N},1,range_length,word,Its length in bytes - a word: the body read the upper half of a 4-byte "
     f"stack slot (was operation_length uint; {R})\n")
# the four local rows named the old placeholders (bVar2 / uVar3 / puVar4 no longer exist) - stage A2 sets real ones
lines = load(O5, "local_variables.csv")
stale = [l for l in lines if l.startswith("0x0003460e,addressRangeValidator,")]
assert len(stale) in (0, 4), stale
for l in stale:
    lines.remove(l)
save(O5, "local_variables.csv", lines)

with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             f"0x0050d784,{N},cm848_lookupApplicationMemoryRegionType,function,1\n")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             f"0x0003460e,{N},cm550_addressRangeValidator,function,1\n")
print("round 72 stage A applied")
