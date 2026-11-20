"""Which of the bin's old names also appear in CM550's CSVs, the cross-firmware function map or the variable map?"""
import json
import re

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware"
STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
text = ""
for p in (f"{FW}/CM550_J90350.00_analysis/output/global_variables.csv", f"{FW}/CM550_J90350.00_analysis/output/function_renames.csv",
          f"{FW}/cross_firmware_matches.csv", f"{FW}/../docs/cross_firmware_variable_map.csv",
          f"{FW}/CM550_J90350.00_analysis/output/structure_definitions.csv"):
    try:
        text += open(p, errors="replace").read() + "\n"
    except FileNotFoundError:
        print("missing", p)
bin_items = json.load(open(f"{STAGE9}/bins/globals2.json"))
hits = 0
for b in bin_items:
    n = b["current_name"]
    if re.search(rf"(?<![A-Za-z0-9_]){re.escape(n)}(?![A-Za-z0-9_])", text):
        print("SHARED", b["address"], n)
        hits += 1
print(hits, "shared old names")
