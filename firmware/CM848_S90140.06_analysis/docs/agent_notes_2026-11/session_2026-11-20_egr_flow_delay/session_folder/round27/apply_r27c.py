"""Round 27 stage C (label-only): j1939_input_signal_descriptor_t.fault_bit_index -> logical_switch (one row of
structure_definitions.csv; nothing else names the field). The comment comes from spec_r27c.py's FIELDS text.
usage: apply_r27c.py <repo> <spec_r27c.py> <map.csv>"""
import os
import runpy
import sys

repo, spec_path, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
new, comment = runpy.run_path(spec_path)["FIELDS"]["j1939_input_signal_descriptor_t"]["fault_bit_index"]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
old_prefix = "j1939_input_signal_descriptor_t,0x0053a278,fault_bit_index,dword,4,"
k = [i for i, l in enumerate(lines) if l.startswith(old_prefix)]
assert len(k) == 1, k
old_comment, rest = lines[k[0]][len(old_prefix):].split(",", 1)
assert "," not in comment and "," not in old_comment
lines[k[0]] = (f"j1939_input_signal_descriptor_t,0x0053a278,{new},dword,4,{comment} (was fault_bit_index, PR #53 round "
               f"27) | earlier note: {old_comment},{rest}")
open(p, "w").write("\n".join(lines))
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind\n0x0053a278,logical_switch,fault_bit_index,field\n")
print(lines[k[0]][:200])
