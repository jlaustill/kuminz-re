"""Proof helper for the switch_input_state_t pilot: rewrite each `switch_input_state_bits.<field>` in the new .cpp as
`(switch_input_state_bits[<byte>] & 0xMM)` (from switch_masks_r11c.json: field -> [byte, mask]), so
cast_normalized_diff.py can compare it with the old byte[4] rendering. Prints what is left (indexed forms, pieces).
usage: switch_normalize.py <new.cpp> <out.cpp> <switch_masks.json>"""
import json
import re
import sys

new_path, out_path, masks_path = sys.argv[1:4]
masks = json.load(open(masks_path))
text = open(new_path).read()
counts = {}
for field, (byte, mask) in masks.items():
    pattern = re.compile(r"(?<![A-Za-z0-9_])switch_input_state_bits\." + re.escape(field) + r"(?![A-Za-z0-9_])")
    text, n = pattern.subn(f"(switch_input_state_bits[{byte}] & 0x{mask:x})", text)
    counts[field] = n
open(out_path, "w").write(text)
left = sorted(set(re.findall(r"switch_input_state_bits(?:\.[A-Za-z_0-9]+|\._\d+_\d+_)", text)))
print("replaced:", sum(counts.values()), "| fields with no use:", [f for f, n in counts.items() if n == 0])
print("left:", left[:20])
