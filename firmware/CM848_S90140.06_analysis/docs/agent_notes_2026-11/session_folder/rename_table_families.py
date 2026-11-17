"""Rename campaign table rows by family prefix (only addresses named by the campaign), add the new DAT_ rows,
and write a mapping (address,name,old_label,kind). Usage: rename_table_families.py <globals.csv> <provenance.csv> <mapping.csv>"""
import csv
import sys

path, provenance, mapping = sys.argv[1:4]
FAMILIES = [("injection_timing_offset_", "injection_timing_pilot_offset_"),
            ("pilot_quantity_", "injection_quantity_pilot_")]
NEW_ROWS = [
    (0x0040b8b8, "fuel_pressure_setpoint_cold_start_value", "word",
     "the cold-start (start-phase) table value of the rail pressure setpoint, written by "
     "cm848_calculateFuelPressureSetpoint and passed on in a register (one word store, no memory reader)"),
    (0x0040b8be, "fuel_pressure_setpoint_map_blended", "word",
     "the blended map value of the rail pressure setpoint (base map / map_1..map_4 through cm848_filterInputValue), "
     "written by cm848_calculateFuelPressureSetpoint (one word store, passed on in a register)"),
    (0x0040b8ea, "fuel_pressure_governor_demand_threshold", "word",
     "the demand threshold sum (gain + coolant + rpm terms + a constant) that the fuel-metering feedback monitor "
     "turns into fuel_metering_feedback_minimum_expected (one word store, passed on in a register)"),
]
campaign = {int(r["address"], 16) for r in csv.DictReader(l for l in open(provenance) if not l.startswith("#"))
            if r["status"] == "named"}
lines = open(path).read().split("\n")
names = {l.split(",")[1] for l in lines if l.startswith("0x") and len(l.split(",")) > 1}
addresses = {int(l.split(",")[0], 16) for l in lines if l.startswith("0x")}
done = []
for i, l in enumerate(lines):
    p = l.split(",", 3)
    if not p[0].startswith("0x") or int(p[0], 16) not in campaign:
        continue
    for o, n in FAMILIES:
        if p[1].startswith(o):
            new = n + p[1][len(o):]
            assert new not in names, new
            done.append((p[0], new, p[1], "table"))
            p[1] = new
            lines[i] = ",".join(p)
for a, name, typ, comment in NEW_ROWS:
    assert a not in addresses and name not in names, (hex(a), name)
    lines.append(f"0x{a:08x},{name},{typ},{comment}")
    done.append((f"0x{a:08x}", name, f"DAT_{a:08x}", "new row"))
if lines and lines[-len(NEW_ROWS) - 1] == "":
    lines.pop(-len(NEW_ROWS) - 1)
    lines.append("")
open(path, "w").write("\n".join(lines))
with open(mapping, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for row in done:
        w.writerow(row)
print(f"family renames {sum(1 for d in done if d[3] == 'table')}, new rows {len(NEW_ROWS)}")
