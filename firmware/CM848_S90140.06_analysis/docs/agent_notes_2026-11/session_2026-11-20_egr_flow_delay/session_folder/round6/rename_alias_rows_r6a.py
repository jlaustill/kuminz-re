"""Round 6 stage A: rename the dotted per-field alias rows of global_variables.csv (name-only rows such as
0x0040ae04,j1939_tsc1_override_state.etc1_capped_speed_target) to the new instance and field names.
usage: rename_alias_rows_r6a.py <global_variables.csv> <map_r6a.csv>"""
import csv
import re
import sys

gv_path, map_path = sys.argv[1:3]
m = list(csv.DictReader(open(map_path)))
fields = {r["old_label"]: r["name"] for r in m if r["kind"] == "field"}
inst = {"j1939_tsc1_override_state": "j1939_powertrain_control_state",
        "j1939_tsc1_received": "j1939_powertrain_messages_received"}
pat = re.compile(r"^(0x[0-9a-f]+),(j1939_tsc1_override_state|j1939_tsc1_received)\.([a-z0-9_]+)((?:\+\d+)?),(.*)$")
lines = open(gv_path).read().split("\n")
n = 0
for i, line in enumerate(lines):
    mm = pat.match(line)
    if mm:
        a, ins, f, suf, rest = mm.groups()
        lines[i] = f"{a},{inst[ins]}.{fields.get(f, f)}{suf},{rest}"
        n += 1
open(gv_path, "w").write("\n".join(lines))
print("renamed", n)
