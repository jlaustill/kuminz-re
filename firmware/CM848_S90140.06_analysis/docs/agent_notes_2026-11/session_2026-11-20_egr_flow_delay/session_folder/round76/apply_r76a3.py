"""Round 76 stage A3 (CM550): remove param_circular_buffer_t. Its six rows give each field its own address, so
ApplyStructures builds one 1544-byte type (metadata 1024 + data 512 + four words) with an instance at every field address.
None rendered before round 76. Stage A changed the type set, and the instance at the 'count' address 0x80C3FE then
applied: the 1280-byte buffer at 0x80C7A8 (cm550_parameterCircularBufferWrite wraps its index at 0x500) rendered as
circular_buffer_count.metadata[index + 0x3aa]. Idempotent; keeps line endings. usage: apply_r76a3.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/structure_definitions.csv")
raw = open(p, "rb").read().decode()
eol = "\r\n" if "\r\n" in raw else "\n"
lines = raw.split(eol)
kept = [l for l in lines if not l.startswith("param_circular_buffer_t,")]
assert len(lines) - len(kept) in (0, 6), len(lines) - len(kept)
if len(kept) != len(lines):
    open(p, "wb").write(eol.join(kept).encode())
print(f"round 76 stage A3 applied: {len(lines) - len(kept)} rows removed")
