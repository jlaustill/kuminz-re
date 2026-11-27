"""Round 39 stage B: statement_diff.py rules. The dword split first (the cast cache address, the two halves), then the
18 label renames of map_r39b.csv as whole tokens.  usage: make_rules_r39b.py <map.csv> <rules.json>"""
import csv
import json
import re
import sys

rules = [[r"\(word \*\)\(\(int\)&crank_sync_phase_counter \+ 2\)", "&cam_tooth_good_window_fraction_cached_axis_offset"],
         [r"\bcrank_sync_phase_counter\._0_2_", "crank_out_of_phase_count"],
         [r"\bcrank_sync_phase_counter\._2_2_", "cam_tooth_good_window_fraction_cached_axis_offset"]]
for r in csv.DictReader(open(sys.argv[1])):
    rules.append([r"\b" + re.escape(r["old_label"]) + r"\b", r["name"]])
json.dump({"*": rules}, open(sys.argv[2], "w"), indent=1)
print(len(rules), "rules")
