"""Proof helper for round 17 stage C: rewrite the new .cpp to the old shapes - the brake type bits
`engine_retarder_brake_type.exhaust_brake` / `.variable_geometry_turbocharger_brake` -> `(engine_retarder_brake_type & 1)`
/ `(... & 2)` - and the old .cpp's `engine_retarder_immediate_brake_flag._0_2_` -> the plain name.
usage: normalize_r17c.py <old.cpp> <new.cpp> <old_out.cpp> <new_out.cpp>"""
import re
import sys

old_path, new_path, old_out, new_out = sys.argv[1:5]
new = open(new_path).read()
counts = {}
for field, mask in (("exhaust_brake", 1), ("variable_geometry_turbocharger_brake", 2)):
    new, counts[field] = re.subn(r"\bengine_retarder_brake_type\." + field + r"\b",
                                 f"(engine_retarder_brake_type & {mask})", new)
open(new_out, "w").write(new)
old = open(old_path).read()
old, counts["immediate_brake_piece"] = re.subn(r"\bengine_retarder_immediate_brake_flag\._0_2_",
                                               "engine_retarder_immediate_brake_flag", old)
open(old_out, "w").write(old)
print(counts)
