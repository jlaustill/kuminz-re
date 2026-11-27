"""Round 94 (CM550): copy CM848's J1939 control session types to CM550, as twins. CM550's Calterm labels for the
records these types describe are the same as CM848's:
- J1939_CONTROL_DEVICE: e2m 10E8 +2 JCEGCOID / 10E6 +2 JCRDCOID '0 = NONE 1 = TRANS 2 = ABS 3 = ASR 4 = UNKNOWN' in both;
- TSC1_OVERRIDE_MODE: e2m 10E8 +4 JCEGMD 'JCOMM CONTROL MODE 0 = DISABLE 1 = SPEED 2 = TORQUE 3 = LIMIT' in both;
- j1939_control_session_t (24 bytes): the record of e2m 10FD JCHSTB / 10FE JCAEEG / 10FF JCAERD in both, with these
  enums in its control_device / override_control_modes fields.
The rows are copied as they are, with a header line; comments that cite CM848-only names keep them (they describe
the twin). Idempotent; keeps each file's line endings. usage: copy_twin_types_r94.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
C8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
C5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
ENUMS = ("J1939_CONTROL_DEVICE", "TSC1_OVERRIDE_MODE")
STRUCTS = ("j1939_control_session_t",)


def rows_of(path, names):
    out = []
    for line in open(path, newline="").read().replace("\r\n", "\n").split("\n"):
        if line.split(",")[0] in names:
            out.append(line)
    return out


done = []
for fname, names, label in (("enums.csv", ENUMS, "enum"), ("structure_definitions.csv", STRUCTS, "struct")):
    src = rows_of(os.path.join(C8, fname), names)
    p = os.path.join(C5, fname)
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    have = {l.split(",")[0] for l in t.replace("\r\n", "\n").split("\n")}
    for n in names:
        if n in have:
            continue
        rows = [l for l in src if l.split(",")[0] == n]
        assert rows, (fname, n)
        head = (f"# {n}: CM848's {label} copied as a twin - CM550's Calterm labels for its records are the same ({R})")
        t = t.rstrip("\r\n") + E + E + head + E + E.join(rows) + E
        done.append(f"{label} {n} ({len(rows)} rows)")
    open(p, "w", newline="").write(t)
print("copied:", done or "nothing (already there)")
