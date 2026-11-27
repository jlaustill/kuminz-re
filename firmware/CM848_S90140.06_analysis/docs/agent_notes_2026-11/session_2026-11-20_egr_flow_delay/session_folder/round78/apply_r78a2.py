"""Round 78 stage A2 (CM550): the globals that the removed oversize types used to cover, typed by their decoded m68k
accesses (m68k_abs_access.py), and the removed types' coordinate rows replaced. Idempotent. usage: apply_r78a2.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
R = "PR #53 round 78"
TYPE = {  # address: (type, evidence) - named rows that only get a type
    "0x0080000e": ("word", "a word between 0x80000c and the move.w-written 0x800010"),
    "0x00800010": ("word", "move.w #imm"),
    "0x0080034a": ("word", "addq.w / clr.w / move.w / tst.w"),
    "0x0080034c": ("word", "addq.w / clr.w / move.w"),
    "0x0080aaba": ("dword", "move.l - a pointer into the data collector buffer"),
}
COORDINATE = {  # address: (old coordinate name, new type or None to drop the row, evidence)
    "0x00800012": ("previous_engine_rpm.rpm_delta", "dword", "the code stores the ROM address 0x6086e there"),
    "0x00800348": ("engine_rpm_delta.previous_nonzero", "word", "clr.w / move.w #imm / tst.w"),
    "0x0080aabe": ("logical_address_canter_value_stored_to_the_data_collector_buffer_none.logical_start", "word",
                   "clr.w / move.w #imm"),
    "0x0080aac0": ("logical_address_canter_value_stored_to_the_data_collector_buffer_none.logical_start+2", "dword",
                   "move.l #imm"),
    "0x00808ddc": ("diagnostic_rx_buffer_base.rx_buffer_base[220]", None, ""),
}
out = []
for line in s.split("\n"):
    address = line.split(",")[0].lower() if line.startswith("0x") else ""
    parts = line.split(",", 3)
    if address in TYPE and R not in line:
        type_, why = TYPE[address]
        parts += [""] * (4 - len(parts))
        parts[2] = type_
        parts[3] = f"(typed {type_}: {why} - the removed oversize structs had covered it; {R})" + (
            " " + parts[3] if parts[3] else "")
        line = ",".join(parts)
    elif address in COORDINATE and len(parts) > 1 and parts[1] == COORDINATE[address][0]:
        old, type_, why = COORDINATE[address]
        if type_ is None:
            continue
        line = f"{address},,{type_},({why}; was the coordinate row {old}, a field of a removed oversize struct; {R})"
    out.append(line)
open(p, "w", newline="").write("\n".join(out))
print("round 78 stage A2 applied")
