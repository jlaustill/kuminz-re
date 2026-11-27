"""Round 69 stage A: the calibration image header at ROM 0x8100, typed by e2m's own blocks. Idempotent (each change
keys on its row and skips when the new text is there).

mpc555_verifyDownloadedCalibration read it as PTR_DAT_00008104 / DAT_00008116 / PTR_DAT_0000811a / DAT_0000811e. e2m
names it as separate blocks, so separate objects:
- 1235 +0 Smart_Boot_Indicator (4 bytes) at 0x8100 -> smart_boot_indicator (0x98765432 here).
- 1236 (10 bytes) at 0x8104 -> checksum_table_descriptor_t: Checksum_Table_Ptr / Start_App_Code_Checksum_Range_Dummy (2)
  / End_App_Code_Checksum_Range_Dummy (4).
- 1198 +0 Flash_Start_Address at 0x810e stays flash_operational_code_entry_pointer.
- 002E +0 Block_Data_Structure (60 bytes) at 0x8112 -> block_data_structure_t. Its arrays each follow a word count (4
  here), which is why the verifier finds block_length at 0x811e + 8 x download_block_count; nothing reads the counts
  themselves, so they stay reserved_<offset>.
- The checksum table at 0xb752 (not in e2m) -> checksum_region_table_t: a word count (2) then 10-byte regions (sum /
  first word / last word). Region 1's sum matches the ROM dump; region 2 (Bank 2) runs past both flash2 dumps.
usage: apply_r69a.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 69"


def load(name):
    return open(os.path.join(O, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(O, name), "w").write("\n".join(lines))


def one(lines, pred, what):
    idx = [i for i, l in enumerate(lines) if pred(l)]
    assert len(idx) == 1, (what, len(idx))
    return idx[0]


# ---- structure_definitions.csv -----------------------------------------------------------------------------------------
T = "structure_definitions.csv"
TYPES = [
    f"# checksum_region_t - one region of checksum_region_table that mpc555_verifyDownloadedCalibration sums ({R})",
    "checksum_region_t,,expected_sum,word,2,The 16-bit sum of the region's words that the verifier requires,,verified",
    "checksum_region_t,,start_address,word*,4,The region's first word,,verified",
    "checksum_region_t,,end_address,word*,4,The region's last word (the sum includes it),,verified",
    f"# checksum_region_table_t - the calibration image's checksum table at ROM 0xb752 (checksum_table_descriptor "
    f"points at it; not in e2m): a word count then that many regions - this image has 2 ({R})",
    "checksum_region_table_t,0x0000b752,region_count,word,2,2 in this image,,verified",
    "checksum_region_table_t,0x0000b752,first_region,checksum_region_t,10,0xb76a-0x591f6 (the main flash code) - sum "
    "0xd501: the ROM dump sums to it,,verified",
    "checksum_region_table_t,0x0000b752,second_region,checksum_region_t,10,\"0x500000-0x53ea6c (Bank 2) - sum 0x17b2: "
    "both flash2 dumps end before 0x53ea6c (at 0x53d4e9 and 0x53dfff), so it is unchecked\",,verified",
    f"# checksum_table_descriptor_t - e2m 1236 (10 bytes) at ROM 0x8104 ({R})",
    "checksum_table_descriptor_t,0x00008104,checksum_table_pointer,checksum_region_table_t*,4,e2m 1236 +0 "
    "Checksum_Table_Ptr 'Pointer to checksum table.' - checksum_region_table (0xb752),,verified",
    "checksum_table_descriptor_t,0x00008104,application_code_checksum_range_start_dummy,word,2,e2m 1236 +4 "
    "Start_App_Code_Checksum_Range_Dummy 'Start of Flash Block to be checksummed.' - 0 here - no reader found,,verified",
    "checksum_table_descriptor_t,0x00008104,application_code_checksum_range_end_dummy,dword,4,e2m 1236 +6 "
    "End_App_Code_Checksum_Range_Dummy 'Dummy end of Flash Block to be checksummed.' - 0 here - no reader found,,verified",
    f"# block_data_structure_t - e2m 002E +0 Block_Data_Structure (60 bytes) at ROM 0x8112: the calibration image's "
    f"download blocks ({R}). Each array follows its own word count (4 here) - the verifier finds block_length at "
    "0x811e + 8 x download_block_count - so the fixed [4] arrays fit this image",
    "block_data_structure_t,0x00008112,reserved_0,word,2,0x003a = 58: the bytes after it (e2m sizes the block at 60) - "
    "no reader found,,verified",
    "block_data_structure_t,0x00008112,reserved_2,word,2,0x00f0 - no reader found,,verified",
    "block_data_structure_t,0x00008112,download_block_count,word,2,4: mpc555_verifyDownloadedCalibration requires "
    "eeprom_block_tracking.block_count to equal it,,verified",
    "block_data_structure_t,0x00008112,reserved_6,word,2,4: the count before block_start_address - no reader found,,"
    "verified",
    "block_data_structure_t,0x00008112,block_start_address,dword,16,0x8000 / 0x40000 / 0x500000 / 0x1000080 - the "
    "verifier requires each download_block_list[i].start_address to equal it,,verified",
    "block_data_structure_t,0x00008112,reserved_24,word,2,4: the count before block_capacity - no reader found,,verified",
    "block_data_structure_t,0x00008112,block_capacity,dword,16,\"0x38000 / 0x30000 / 0x40000 / 0x1f7e: main flash "
    "blocks 1-7, module B and Bank 2 match the flash geometry; 0x80 + 0x1f7e = 0x1ffe is unexplained - no reader "
    "found\",,verified",
    "block_data_structure_t,0x00008112,reserved_42,word,2,4: the count before block_length - no reader found,,verified",
    "block_data_structure_t,0x00008112,block_length,dword,16,\"0x38000 / 0x2fc64 / 0x3ea6e / 0x19c0: the image's length "
    "in each block - module B's ends at 0x6fc63 (0xff from 0x6fc64 on) and Bank 2's where checksum region 2 ends. The "
    "verifier requires each download_block_list[i].end_address to be at least it: an address against a length, so it "
    "always holds for the blocks that start above their length (all but the first)\",,verified",
]
lines = load(T)
if TYPES[1] not in lines:
    i = one(lines, lambda l: l.startswith("memory_region_t,0x003f9862,"), "region 5 marker")
    lines[i + 1:i + 1] = TYPES
    save(T, lines)

# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"
lines = load(G)
NEW_ROWS = {
    "0x00008100": "0x00008100,smart_boot_indicator,dword,e2m 1235 +0 Smart_Boot_Indicator '[SSSMRTSR] If SMT_BOOT_SUPPORTED, "
                  "OK to smart download' (HEX) - 0x98765432 here - no reader found: the calibration image starts its "
                  f"header with it ({R})",
    "0x00008112": "0x00008112,block_data_structure,block_data_structure_t,e2m 002E +0 Block_Data_Structure (60 bytes): the "
                  "calibration image's download blocks - mpc555_verifyDownloadedCalibration checks download_block_list "
                  f"against it ({R})",
    "0x0000b752": "0x0000b752,checksum_region_table,checksum_region_table_t,The calibration image's checksum table "
                  "(checksum_table_descriptor.checksum_table_pointer) - mpc555_verifyDownloadedCalibration sums each "
                  f"region ({R})",
}
if NEW_ROWS["0x00008100"] not in lines:
    i = one(lines, lambda l: l == "0x00008104,,pointer,", "0x8104")
    lines[i] = ("0x00008104,checksum_table_descriptor,checksum_table_descriptor_t,e2m 1236 (10 bytes): the checksum "
                f"table pointer and a dummy range (was a type-only pointer row; {R})")
    lines.insert(i, NEW_ROWS["0x00008100"])
    j = one(lines, lambda l: l == "0x0000811a,,pointer,", "0x811a")
    lines[j] = NEW_ROWS["0x00008112"]
    k = one(lines, lambda l: l.startswith("0x0000b74a,"), "0xb74a")
    for dead in ("0x0000b756,,pointer,", "0x0000b75a,,pointer,", "0x0000b760,,dword,"):
        lines.remove(dead)
    lines.insert(k + 1, NEW_ROWS["0x0000b752"])
    save(G, lines)

# ---- function_renames.csv: the verifier's plate names the new symbols ---------------------------------------------------
F = "function_renames.csv"
p = os.path.join(O, F)
s = open(p).read()
old = ("sums each region of the image header's checksum table (pointer at ROM 0x8104 - a count then 10-byte sum / start / "
       "end records) and checks download_block_list against the header's expected block count and addresses (0x8116 "
       "onward)")
new = ("sums each region of checksum_region_table (checksum_table_descriptor.checksum_table_pointer: a count then 10-byte "
       "sum / first word / last word regions) and checks download_block_list against block_data_structure (e2m 002E: "
       f"the block count / start addresses / lengths; {R})")
if new not in s:
    assert s.count(old) == 1
    open(p, "w").write(s.replace(old, new))
print("round 69 stage A applied")
