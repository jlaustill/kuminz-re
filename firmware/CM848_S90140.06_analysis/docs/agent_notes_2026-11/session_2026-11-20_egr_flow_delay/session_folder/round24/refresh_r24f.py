"""Round 24 stage F part 1: refresh the comments (CSV comment columns, '#' lines, firmware/CLAUDE.md) after
apply_r24f.py. The qualified sensor_readings_t references become the flat names; the phrases that described the old
dword's halves name the two words. A name right after 'was' / '(was' stays. Prints what is left.
usage: refresh_r24f.py <repo> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
FIELDS = {"intake_manifold_pressure": "intake_manifold_pressure_sensor_filtered",
          "coolant_temp": "coolant_temperature_sensor_filtered",
          "barometric_pressure": "barometric_pressure_sensor_filtered",
          "battery_voltage": "battery_voltage_sensor_filtered"}
tokens = {}
for f, n in FIELDS.items():
    tokens[f"sensor_readings_t_0040baf2.{f}"] = n
    tokens[f"sensor_readings_t.{f}"] = n
PHRASES = [("the previous commanded throttle (high word of throttle_fuel_enable_flag)",
            "the previous commanded throttle (commanded_throttle_previous)"),
           ("kept in the high word of throttle_fuel_enable_flag", "kept in commanded_throttle_previous"),
           ("registered fault bits 10 / 11 set the low word of throttle_fuel_enable_flag",
            "registered fault bits 10 / 11 set throttle_sensor_fault_flag")]
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?$")
pats = [(re.compile(r"(?<![A-Za-z0-9_.])" + re.escape(k) + r"(?![A-Za-z0-9_])"), v)
        for k, v in sorted(tokens.items(), key=lambda kv: -len(kv[0]))]


def refresh(text):
    for old, new in PHRASES:
        text = text.replace(old, new)
    for pat, rep in pats:
        def sub(m, rep=rep, text=text):
            return m.group(0) if HISTORY.search(text[max(0, m.start() - 12):m.start()]) else rep
        text = pat.sub(sub, text)
    return text


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


changed = {}
for name, col, n in [("global_variables.csv", 3, 4), ("function_renames.csv", 2, 3), ("arrays.csv", 4, 5),
                     ("labels.csv", 2, 3), ("constants.csv", 3, 4), ("deleted_functions.csv", 1, 2)]:
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    new = []
    for line in open(p).read().split("\n"):
        if not line or line.startswith("#"):
            new.append(refresh(line) if line.startswith("#") else line)
            continue
        parts = line.split(",", n - 1)
        if len(parts) > col:
            parts[col] = refresh(parts[col])
        new.append(",".join(parts))
    changed[p] = new
for name, col in [("structure_definitions.csv", 5), ("enums.csv", 3)]:
    p = os.path.join(out, name)
    new = []
    for line in open(p).read().split("\n"):
        if not line or line.startswith("#") or line.startswith(("struct_name,", "enum_name,")):
            new.append(refresh(line) if line.startswith("#") else line)
            continue
        row = next(csv.reader([line]))
        before = list(row)
        if len(row) > col:
            row[col] = refresh(row[col])
        new.append(write_csv_row(row) if row != before else line)
    changed[p] = new
cl = os.path.join(repo, "firmware/CLAUDE.md")
changed[cl] = [refresh(l) for l in open(cl).read().split("\n")]
for p, new in changed.items():
    old = open(p).read().split("\n")
    n = sum(1 for a, b in zip(old, new) if a != b)
    if n:
        print(f"{os.path.relpath(p, repo)}: {n} lines")
    if not dry and new != old:
        open(p, "w").write("\n".join(new))
    for i, l in enumerate(new):
        for m in re.finditer(r"sensor_readings_t\w*|throttle_fuel_enable_flag", l):
            if not HISTORY.search(l[max(0, m.start() - 12):m.start()]):
                print(f"  left: {os.path.relpath(p, repo)}:{i + 1}: ...{l[max(0, m.start() - 60):m.end() + 40]}")
