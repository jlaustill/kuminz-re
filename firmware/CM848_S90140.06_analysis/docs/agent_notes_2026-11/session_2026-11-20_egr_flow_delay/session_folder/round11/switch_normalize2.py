"""Proof helper for the narrowed switch_input_state_t: rewrite the new .cpp to the old byte[4] form - a byte field
`switch_input_state_bits.<field>` -> `switch_input_state_bits[k]`, a byte 2 bitfield -> `(switch_input_state_bits[2] &
0xMM)`, and the scanner's `(&switch_input_state_bits[0])[i]` -> `switch_input_state_bits[i]`.
usage: switch_normalize2.py <new.cpp> <out.cpp> <switch_fields.json>"""
import json
import re
import sys

new_path, out_path, fields_path = sys.argv[1:4]
fields = json.load(open(fields_path))
text = open(new_path).read()
counts = {}
for field, spec in fields.items():
    pattern = re.compile(r"(?<![A-Za-z0-9_])switch_input_state_bits\." + re.escape(field) + r"(?![A-Za-z0-9_])")
    repl = f"switch_input_state_bits[{spec[1]}]" if spec[0] == "byte" else f"(switch_input_state_bits[{spec[1]}] & 0x{spec[2]:x})"
    text, n = pattern.subn(repl, text)
    counts[field] = n
text, indexed = re.subn(r"\(&switch_input_state_bits\[0\]\)\[", "switch_input_state_bits[", text)
open(out_path, "w").write(text)
left = sorted(set(re.findall(r"switch_input_state_bits\.[A-Za-z_0-9]+", text)))
print("replaced:", counts, "| indexed:", indexed, "| left:", left)
