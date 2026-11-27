"""Stage 8 (shape): the signedness sweep - i16 for every named word row whose table-resolved e2m record is a signed
2-byte value and whose every load is an lha (classify_signed_loads.py: 444 rows; 35 with an lhz load stay word, 104
with no load are skipped) - plus two 819B words checked by hand (cylinder_acceleration: the only read is the register
in an (int)(short) compare; fuel_pressure_start_undershoot: lha through r31) and pulse_period_table_backup as dword[4].
Usage: apply_stage8.py <firmware output dir> <signed_loads.csv>"""
import csv
import os
import sys

out, loads_path = sys.argv[1:3]
NOTE = " | retyped word -> i16 2026-11-20 (e2m signed, every load lha)"
targets = {int(r["address"], 16): r["name"] for r in csv.DictReader(open(loads_path)) if r["verdict"] == "lha-only"}
targets[0x0040b7aa] = "cylinder_acceleration"
targets[0x0040b808] = "fuel_pressure_start_undershoot"
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
done, array = 0, 0
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    if a in targets:
        assert p[1] == targets[a] and p[2] == "word", (hex(a), p[:3])
        p[2] = "i16"
        p = p + [""] if len(p) < 4 else p
        note = NOTE if a not in (0x0040b7aa, 0x0040b808) else \
            " | retyped word -> i16 2026-11-20 (e2m 819B signed; " + \
            ("stored with sth, read as (int)(short))" if a == 0x0040b7aa else "lha through r31)")
        p[3] = p[3] + note
        lines[i] = ",".join(p)
        done += 1
    elif a == 0x0040b7dc:
        assert p[1] == "pulse_period_table_backup" and p[2] == "dword", p
        p[2] = "dword[4]"
        lines[i] = ",".join(p)
        array += 1
assert done == len(targets) and array == 1, (done, len(targets), array)
open(path, "w").write("\n".join(lines))
print(f"i16: {done}, dword[4]: {array}")
