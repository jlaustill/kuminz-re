"""Round 96, before the Q1 / Q2 / Q4 apply:
- CM550 function_renames.csv rows for the seven functions the batches name that have no row (the apply renames rows,
  it does not create them): Q1's four builders reached only through the scheduler's builder argument (0x3229a /
  0x32bbc / 0x339fe / 0x34496) and Q2's registrar 0x2f47e, DM10 builder 0x32222 and VI sender 0x34430. The placeholder
  name is the decompiler's default with the cm550_ prefix, inserted in address order.
- overrides: drop the 0x803631 element (its final name is a documentation path, which the apply's name check refuses;
  post_apply_r96_q124.py writes that row).
Idempotent; keeps line endings. usage: pre_apply_r96_q124.py <repo> <overrides_r96.json>"""
import json
import os
import sys

repo, ov_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
added = 0
for a in (0x2f47e, 0x3229a, 0x32222, 0x32bbc, 0x339fe, 0x34430, 0x34496):
    key = f"0x{a:08x},"
    if any(l.lower().startswith(key) for l in lines):
        continue
    k = next(k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > a)
    lines.insert(k, f"0x{a:08x},cm550_FUN_{a:08x}")
    added += 1
open(p, "w", newline="").write(E.join(lines))
o = json.load(open(ov_path))
o["global|CM550|0x00803631"] = {"drop": True, "reason": "its final name is the documentation path j1939_pgn65249_payload.retarder_control_method; post_apply_r96_q124.py writes it"}
json.dump(o, open(ov_path, "w"), indent=1)
print("placeholder rows added:", added)
