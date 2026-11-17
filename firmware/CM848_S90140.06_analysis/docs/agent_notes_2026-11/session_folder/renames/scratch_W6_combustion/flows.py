import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion")
from w6 import *

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
lines = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
cur = None
funcs = ["cm848_loadBasedFuelAdjustment", "cm848_throttleBasedFuelCalculation", "cm848_fuelDemandErrorCalculation"]
syms = ["fuel_quantity_ema_filtered", "fuel_quantity_ema", "reserved_0c", "fuel_demand_final", "efficiency_filtered",
        "residual_oxygen_fraction_before_delay", "fuel_rate_rpm_factor"]
pat = re.compile(r"\b(" + "|".join(syms) + r")\b")
for i, ln in enumerate(lines):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", ln)
    if m:
        cur = m.group(1)
    if cur in funcs and pat.search(ln) and not ln.lstrip().startswith(("*", "//")):
        print(i + 1, cur, "|", ln.strip()[:170])
print("ROM constants DAT_0005c310 / 0005c312:", w(0x5c310), w(0x5c312))
