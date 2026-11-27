"""Round 90 stage A (CM550): the ECU's parameter ID table and its lookup.
- cm550_diagnosticMemoryAddressResolver (0x10e16) -> cm550_lookupParameterIdAddress: the counterpart of CM848's
  cm848_lookupParameterIdAddress (a hash over 6-byte [id][address] records in flash2; CM550 indexes by id range).
- parameter_id_table (0x35224, parameter_id_table_entry_t[1806], ROM): rendered DAT_00035224 / DAT_00035228.
  Index = id for 0x0000-0x002E, id - 0xFD1 for 0x1000-0x1478, id + 0x84A8 (mod 0x10000, = id - 0x7B58) for
  0x8000-0x8265: 47 + 1145 + 614 = 1806 entries, the whole run of address pairs at 0x35224-0x38a94; 723 are non-zero
  and they are exactly output/parameter_id_lookup_table.csv's 723 rows.
Idempotent; keeps line endings. usage: apply_r90a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 90"
OLD, NEW = "cm550_diagnosticMemoryAddressResolver", "cm550_lookupParameterIdAddress"


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


PLATE = ("The parameter ID -> address lookup: the counterpart of CM848's cm848_lookupParameterIdAddress (a hash over "
         "6-byte [id][address] records in flash2). CM550 indexes parameter_id_table (0x35224) by id range: index = id for "
         "0x0000-0x002E / id - 0xFD1 for 0x1000-0x1478 / id + 0x84A8 (mod 0x10000) for 0x8000-0x8265 (1806 entries); an "
         "id outside them or a 0 address returns 1. It reads address_ram_refresh_disabled while ram_refresh_enable is "
         "RAM_REFRESH_DISABLED (development mode) and address_ram_refresh_enabled otherwise - equal in all 1806 J90350.00 "
         "entries. The e2m block ids are entries too (block 1003 -> 0x806ae2) so an e2m record's address is "
         f"table[block] + its offset. (was {OLD}; {R})")
p = os.path.join(O, "function_renames.csv")
t = read(p)
m = re.search(r"^0x00010e16,([^,\r\n]*)(,[^\r\n]*)?$", t, re.M)
assert m
if m.group(1) != NEW:
    assert m.group(1) == OLD, m.group(1)
    t = t[:m.start()] + f"0x00010e16,{NEW},{PLATE}" + t[m.end():]
    write(p, t)
for name in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(O, name)
    d = read(p)
    d2 = re.sub(rf"^(0x00010e16,){OLD},", rf"\g<1>{NEW},", d, flags=re.M)
    if d2 != d:
        write(p, d2)

S = os.path.join(O, "structure_definitions.csv")
s = read(S)
E = "\r\n" if "\r\n" in s else "\n"
if "parameter_id_table_entry_t,," not in s:
    block = [f"# Parameter ID table entry (8 bytes; parameter_id_table at 0x35224, read by cm550_lookupParameterIdAddress) ({R})",
             "parameter_id_table_entry_t,,address_ram_refresh_disabled,dword,4,+0: the parameter's address while "
             "ram_refresh_enable is RAM_REFRESH_DISABLED (development mode); 0 = no parameter,,verified",
             "parameter_id_table_entry_t,,address_ram_refresh_enabled,dword,4,+4: the address otherwise; equal to +0 in "
             "all 1806 J90350.00 entries,,verified"]
    s = s.rstrip("\r\n") + E + E + E.join(block) + E
    write(S, s)

G = os.path.join(O, "global_variables.csv")
lines = read(G).split("\n")
ROW = ("0x00035224,parameter_id_table,parameter_id_table_entry_t[1806],The ECU's parameter ID table (ROM): id -> address for "
       "the diagnostic memory services by parameter ID; the e2m block ids are entries too (block 1003 -> 0x806ae2) so an "
       "e2m record's address is table[block] + offset. Index = id for 0x0000-0x002E / id - 0xFD1 for 0x1000-0x1478 / id + "
       "0x84A8 (mod 0x10000) for 0x8000-0x8265 (cm550_lookupParameterIdAddress); 723 entries are non-zero = "
       f"output/parameter_id_lookup_table.csv ({R})")
if not any(l.startswith("0x00035224,") for l in lines):
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < 0x35224]
    lines.insert(after[-1] + 1, ROW)
    write(G, "\n".join(lines))
with open(map_out, "w") as fh:
    fh.write(f"address,name,old_label,kind,dims\n0x00010e16,{NEW},{OLD},symbol,1\n")
print("stage A applied")
