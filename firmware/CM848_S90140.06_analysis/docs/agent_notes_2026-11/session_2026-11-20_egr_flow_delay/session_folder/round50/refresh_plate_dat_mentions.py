"""Round 50: refresh_references.py never rewrites DAT_ labels (they are cited on purpose), so five plates still named
rows that rounds 49 / 50 created by their DAT_ label. Replace each with the row's name. Idempotent.
usage: refresh_plate_dat_mentions.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
t = open(p).read()
pairs = [("DAT_0005c30e", "commanded_throttle_difference_threshold"),
         ("DAT_0040a606", "compressor_inlet_density_source"),
         ("DAT_0040a64a", "duty_cycle_monitor_operating_region"),
         ("DAT_0005c2f4", "engine_protection_maximum_shutdowns"),
         ("DAT_0005c2ec", "engine_protection_fueling_index_ramp_rate")]
n = 0
for old, new in pairs:
    n += t.count(old)
    t = t.replace(old, new)
open(p, "w").write(t)
print(f"{n} plate mentions refreshed")
