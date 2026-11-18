"""Stage-B render check on a .cpp: every wave-8 name renders in code (comments stripped), no `_name` variant, and the
underscore-overlap warning count. usage: w8_render_check.py <cpp> <mapping.csv>..."""
import csv
import re
import sys

cpp = open(sys.argv[1]).read()
code = re.sub(r"/\*.*?\*/", "", cpp, flags=re.S)
names = set()
for path in sys.argv[2:]:
    for r in csv.DictReader(open(path)):
        if r["name"] and r["kind"] in ("function", "global", "new row"):
            names.add(r["name"])
names |= {"engine_speed_limit_arbitration", "operating_mode_governor_output", "main_injection_timing_source_code",
          "engine_speed_limit_droop_slope", "engine_speed_limit_ramped", "egr_valve_driver_over_current_fault_counter"}
missing = sorted(n for n in names if not re.search(rf"\b{re.escape(n)}\b", code))
underscored = sorted(n for n in names if re.search(rf"\b_{re.escape(n)}\b", code))
print(f"{len(names)} names; not rendered in code: {len(missing)} {missing}")
print(f"underscore variants: {len(underscored)} {underscored}")
print("underscore-overlap warnings:", cpp.count("Globals starting with '_' overlap"))
