"""Round 69 stage A, third pass: field-coordinate rows for the new structs' named fields, so the e2m resolver and
the address tools name them (round 68's convention; e2m_block_addresses.py showed 1236 +4 / +6 as 'no row').
Idempotent. usage: fix_r69a3.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
lines = open(p).read().split("\n")
R = "PR #53 round 69"
ROWS = [  # (address, name, after-address): inserted after the row with that address
    ("0x00008108", "checksum_table_descriptor.application_code_checksum_range_start_dummy", "0x00008104"),
    ("0x0000810a", "checksum_table_descriptor.application_code_checksum_range_end_dummy", "0x00008108"),
    ("0x00008116", "block_data_structure.download_block_count", "0x00008112"),
    ("0x0000811a", "block_data_structure.block_start_address[0]", "0x00008116"),
    ("0x0000812c", "block_data_structure.block_capacity[0]", "0x0000811a"),
    ("0x0000813e", "block_data_structure.block_length[0]", "0x0000812c"),
    ("0x0000b754", "checksum_region_table.first_region", "0x0000b752"),
    ("0x0000b75e", "checksum_region_table.second_region", "0x0000b754"),
]
for addr, name, after in ROWS:
    row = f"{addr},{name},,({R})"
    if row in lines:
        continue
    assert not any(l.startswith(addr + ",") for l in lines), addr
    i = [k for k, l in enumerate(lines) if l.startswith(after + ",")]
    assert len(i) == 1, after
    lines.insert(i[0] + 1, row)
open(p, "w").write("\n".join(lines))
print("third pass applied")
