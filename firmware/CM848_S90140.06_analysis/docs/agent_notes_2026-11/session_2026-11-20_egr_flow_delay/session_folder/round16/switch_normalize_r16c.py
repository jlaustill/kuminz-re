"""Proof helper for round 16 stage C: rewrite the new .cpp to the narrow switch_input_state_t form - a byte 0 / 1 / 3
bitfield `switch_input_state_bits.<field>` -> `(switch_input_state_bits.<byte field> & <mask>)`, the mask written as
Ghidra writes constants (decimal below 10, else hex), and reserved_bit_18 -> reserved_bit_2. Prints the counts.
usage: switch_normalize_r16c.py <new.cpp> <out.cpp> <masks.json>"""
import json
import re
import sys

new_path, out_path, masks_path = sys.argv[1:4]
masks = json.load(open(masks_path))
text = open(new_path).read()
counts = {}
for field, (byte_field, mask) in masks.items():
    pattern = re.compile(r"(?<![A-Za-z0-9_])switch_input_state_bits\." + re.escape(field) + r"(?![A-Za-z0-9_])")
    m = str(mask) if mask < 10 else f"0x{mask:x}"
    text, n = pattern.subn(f"(switch_input_state_bits.{byte_field} & {m})", text)
    if n:
        counts[field] = n
text = text.replace("switch_input_state_bits.reserved_bit_18", "switch_input_state_bits.reserved_bit_2")
open(out_path, "w").write(text)
print("replaced:", counts, "total", sum(counts.values()))
