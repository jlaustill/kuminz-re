"""Rename table rows by base (old_base + role suffix -> new_base + same suffix), name column only, and append each
rename to a mapping CSV (address,name,...,old_label) for reverse_names.py. Usage: rename_bases.py <globals.csv> <mapping.csv>"""
import csv
import re
import sys

path, mapping = sys.argv[1:3]
BASES = {
    "injection_timing_main_start_run_up": "injection_timing_main_cold_start",
    "injection_timing_offset_start_run_up": "injection_timing_offset_cold_start",
    "fuel_pressure_setpoint_start_run_up": "fuel_pressure_setpoint_cold_start",
    "accelerator_pedal_sensor_channel97_linearization": "accelerator_pedal_channel97_linearization",
    "accelerator_pedal_sensor_channel98_linearization": "accelerator_pedal_channel98_linearization",
    "fuel_level_sensor_linearization": "fuel_level_linearization",
    "transmission_temperature_sensor_linearization": "transmission_temperature_linearization",
    "sensor_reference_voltage_2_linearization": "sensor_reference_voltage_b_linearization",
    "wastegate_duty_ceiling_by_rpm_and_fuel_quantity": "wastegate_duty_ceiling",
    "wastegate_duty_floor_by_rpm_and_fuel_quantity": "wastegate_duty_floor",
}
SUFFIX = re.compile(r"_(axis|values|x_axis|y_axis|grid)$")
old = open(path).read().split("\n")
names = {l.split(",")[1] for l in old if l.startswith("0x") and len(l.split(",")) > 1}
new, done = list(old), []
for i, line in enumerate(old):
    p = line.split(",")
    if not p[0].startswith("0x") or len(p) < 2:
        continue
    for ob, nb in BASES.items():
        if p[1].startswith(ob + "_") and SUFFIX.fullmatch(p[1][len(ob):]):
            n = nb + p[1][len(ob):]
            assert n not in names, f"{n} already used"
            done.append((p[0], p[1], n))
            p[1] = n
            new[i] = ",".join(p)
            break
used = {o.rsplit("_", 1)[0] for _, o, _ in done}
changed = [i for i in range(len(old)) if old[i] != new[i]]
assert len(changed) == len(done)
for i in changed:
    o, n = old[i].split(","), new[i].split(",")
    assert len(o) == len(n) and all(o[j] == n[j] for j in range(len(o)) if j != 1)
missing = [b for b in BASES if not any(o.startswith(b + "_") for _, o, _ in done)]
assert not missing, f"bases with no rows: {missing}"
assert len({n for _, _, n in done}) == len(done)
open(path, "w").write("\n".join(new))
with open(mapping, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label"])
    for a, o, n in done:
        w.writerow([a, n, o])
print(f"renamed {len(done)} rows")
