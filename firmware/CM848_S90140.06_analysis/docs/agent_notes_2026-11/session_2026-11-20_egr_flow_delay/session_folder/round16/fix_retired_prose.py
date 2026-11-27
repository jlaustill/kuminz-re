"""Round 16 closing, part 2: the retired 'vehicle speed limit' / 'zone' wording in current (non-history) comment text of
global_variables.csv and function_renames.csv, found by retired_prose.py. Idempotent.
usage: fix_retired_prose.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
FIXES = {
    "global_variables.csv": [
        ("for the first pass of cruise control or the vehicle speed limit (9 / 10 after another state)",
         "for the first pass of cruise control or the road speed governor (9 / 10 after another state)"),
        ("In a first pass of cruise control (9) or vehicle speed limit (10),",
         "In a first pass of cruise control (9) or the road speed governor (10),"),
        ("vehicle_speed_rise_limited is the speed the cruise control and vehicle speed limit fueling work on.",
         "vehicle_speed_rise_limited is the speed the cruise control and road speed governor fueling work on."),
        ("and the vehicle speed limit fuel (10),", "and the road speed governor fuel (10),"),
        ("a cruise / vehicle speed limit state runs", "a cruise / road speed governor state runs"),
        ("in the vehicle speed limit state;", "in the road speed governor state;"),
        ("The vehicle speed the cruise control and vehicle speed limit fueling work on",
         "The vehicle speed the cruise control and road speed governor fueling work on"),
        ("selects the cruise gain zones;", "selects the cruise governor gain sets;"),
        ("on a zone transition only when it is 0", "on a gain set change only when it is 0"),
    ],
    "function_renames.csv": [
        ("0xf4 vehicle speed limit,", "0xf4 road speed governor,"),
        ("the speed the cruise control and vehicle speed limit fueling work on",
         "the speed the cruise control and road speed governor fueling work on"),
    ],
}
for name, pairs in FIXES.items():
    p = os.path.join(out, name)
    t = open(p).read()
    for old, new in pairs:
        if old not in t and new in t:
            continue
        assert t.count(old) == 1, (name, old[:60], t.count(old))
        t = t.replace(old, new)
    open(p, "w").write(t)
print("retired wording fixed")
