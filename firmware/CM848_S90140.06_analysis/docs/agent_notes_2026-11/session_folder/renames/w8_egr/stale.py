"""Find CSV comments that still cite the old names listed as stale by the wave-7 agent (outside '(was ...)' history)."""
import csv
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
OLD = ["fuel_demand_boost_input", "boost_fuel_scale_cal", "fuel_timing_error_scale", "boost_correction_inhibit_flag",
       "boost_fuel_mode_active", "cm848_processFuelDemandFaultConditions", "governor_speed_at_target_flag",
       "sensor_generic_fault_status", "cm848_calculateSensorChannel75DeviationDiagnosticConditions"]
hits = []
for fname, ncol in (("global_variables.csv", 3), ("function_renames.csv", 2), ("enums.csv", 3), ("structure_definitions.csv", 5),
                    ("arrays.csv", 3), ("constants.csv", 3), ("labels.csv", 3)):
    try:
        lines = open(OUT + fname, errors="replace").read().split("\n")
    except FileNotFoundError:
        continue
    for ln in lines:
        if not ln or ln.startswith("#"):
            continue
        parts = ln.split(",", ncol)
        text = parts[ncol] if len(parts) > ncol else ""
        # strip history markers
        stripped = re.sub(r"\(was [^)]*\)", "", text)
        stripped = re.sub(r"\| earlier note:.*$", "", stripped)
        for old in OLD:
            if re.search(r"(?<![\w])" + re.escape(old) + r"(?![\w])", stripped):
                hits.append((fname, parts[0], parts[1] if len(parts) > 1 else "", old))
print("remaining cites outside history markers:", len(hits))
for h in hits[:40]:
    print(h)
# and in the code CSV names themselves
for fname in ("global_variables.csv", "function_renames.csv"):
    for ln in open(OUT + fname, errors="replace"):
        p = ln.split(",", 2)
        if len(p) > 1 and p[1] in OLD:
            print("a row is STILL NAMED", fname, p[0], p[1])
sys.exit(0)
