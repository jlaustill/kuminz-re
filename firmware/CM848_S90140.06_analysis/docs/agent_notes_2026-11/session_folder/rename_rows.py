"""Rename already-named global rows (name column only) and append them to a mapping CSV with old_label.
Usage: rename_rows.py <global_variables.csv> <mapping.csv>"""
import csv
import sys

path, mapping = sys.argv[1:3]
RENAMES = {
    0x59346: ("sensor_channel2_linearization_axis", "battery_voltage_linearization_axis"),
    0x59358: ("sensor_channel2_linearization_values", "battery_voltage_linearization_values"),
    0x59456: ("sensor_channel7_linearization_axis", "sensor_channel75_linearization_axis"),
    0x5946c: ("sensor_channel7_linearization_values", "sensor_channel75_linearization_values"),
    0x5fabe: ("post_injection_pulse_width_x_axis", "auxiliary_injection_pulse_width_x_axis"),
    0x5fad6: ("post_injection_pulse_width_y_axis", "auxiliary_injection_pulse_width_y_axis"),
    0x5faea: ("post_injection_pulse_width_grid", "auxiliary_injection_pulse_width_grid"),
}
old = open(path).read().split("\n")
names = {l.split(",")[1] for l in old if l.startswith("0x") and len(l.split(",")) > 1}
new, hits = list(old), {}
for i, line in enumerate(old):
    p = line.split(",")
    if p[0].startswith("0x") and int(p[0], 16) in RENAMES:
        a = int(p[0], 16)
        want_old, want_new = RENAMES[a]
        assert p[1] == want_old, f"0x{a:x} is {p[1]!r}, expected {want_old!r}"
        assert want_new not in names, f"{want_new} already used"
        p[1] = want_new
        new[i] = ",".join(p)
        hits[a] = hits.get(a, 0) + 1
assert sorted(hits) == sorted(RENAMES) and all(v == 1 for v in hits.values()), hits
changed = [i for i in range(len(old)) if old[i] != new[i]]
assert len(changed) == len(RENAMES)
for i in changed:
    o, n = old[i].split(","), new[i].split(",")
    assert len(o) == len(n) and all(o[j] == n[j] for j in range(len(o)) if j != 1)
open(path, "w").write("\n".join(new))
with open(mapping, "a", newline="") as f:
    w = csv.writer(f)
    for a, (o, n) in sorted(RENAMES.items()):
        w.writerow([f"0x{a:08x}", n, "", "", "", "", "", o])
print(f"renamed {len(changed)} rows")
