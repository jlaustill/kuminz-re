"""PR #50 body: the campaign review pass."""
import sys

p = sys.argv[1]
t = open(p).read()
anchor = "    - **45 tables stay unnamed** because their input units or output could not be traced.\n"
add = ("    - **Review pass (dfef374):**\n"
       "      - `docs/table_naming_campaign_2026-11-16.csv` records every table's evidence or skip reason; 39 % of the names are medium confidence.\n"
       "      - 24 names were aligned: `cold_start` to match `cold_start_phase`, the sensor tables to `<sensor>_linearization`, reference voltage `_b`, and `wastegate_duty_ceiling` / `_floor` without the unsupported fuel-quantity claim.\n"
       "      - The 4WD switch identity is now sourced from the DRB database (P0836 / P0837 \"4WD MUX SWITCH\").\n"
       "      - Bin 10's domain words came from the repo's e2m name lists; its traces stand on the code alone.\n"
       "      - That the auxiliary event comes after main is marked as inferred.\n")
assert t.count(anchor) == 1
open(p, "w").write(t.replace(anchor, anchor + add))
print("ok")
