"""Round 69 stage A, second pass. Idempotent.
checksum_region_table.second_region.end_address (word *) references 0x53ea6c, so Ghidra labelled it and
cm848_lookupParameterIdAddress's '(parameter_id_entry_t *)0x53ea6c' became '&DAT_0053ea6c'. The word gets its name:
the Bank 2 image's last word (block_data_structure.block_length[2] = 0x3ea6e from 0x500000), right after
parameter_id_table's 1886 records - the lookup's last bucket ends at its address. Both flash2 dumps end before it.
usage: fix_r69a2.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
lines = open(p).read().split("\n")
row = ("0x0053ea6c,bank2_image_last_word,word,The Bank 2 image's last word: checksum_region_table.second_region.end_address "
       "(block_data_structure.block_length[2] = 0x3ea6e from 0x500000) - and one past parameter_id_table's 1886 records, "
       "so cm848_lookupParameterIdAddress ends its last bucket at its address. Both flash2 dumps end before it "
       "(at 0x53d4e9 and 0x53dfff) (PR #53 round 69)")
if row not in lines:
    i = [k for k, l in enumerate(lines) if l.startswith("0x0053be38,parameter_id_table,")]
    assert len(i) == 1
    j = i[0] + 1
    while j < len(lines) and lines[j].startswith("0x0053") and int(lines[j].split(",")[0], 16) < 0x53ea6c:
        j += 1
    lines.insert(j, row)
    open(p, "w").write("\n".join(lines))
print("second pass applied")
