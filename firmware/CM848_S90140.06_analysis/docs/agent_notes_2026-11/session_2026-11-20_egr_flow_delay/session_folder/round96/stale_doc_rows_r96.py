"""Round 96: documentation rows ('name.field' / 'name[n]' in global_variables.csv's name column) whose prefix is not
the name of a live row covering that address, in both firmwares. A rename of the covering row leaves them stale (the
refresh tools edit comment columns, not names). For each, the covering row and, for a struct-typed covering row, the
field that starts at the row's offset give the corrected name. With --fix the rows are renamed (the old name kept as
'(was ...)' in the comment); a row whose offset starts no field is reported and left alone.
usage: stale_doc_rows_r96.py <repo> [--fix]"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 96"
for fw in ("firmware/CM550_J90350.00_analysis/output", "firmware/CM848_S90140.06_analysis/output"):
    fields = {}
    for r in csv.reader(l for l in open(os.path.join(repo, fw, "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 4 and r[0] and r[2] and r[4].strip().isdigit():
            fields.setdefault(r[0], []).append((r[2], int(r[4])))
    path = os.path.join(repo, fw, "global_variables.csv")
    text = open(path, newline="").read()
    E = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(E)
    rows = []
    for i, line in enumerate(lines):
        p = line.split(",", 3)
        if len(p) > 2 and p[0].startswith("0x") and p[1]:
            rows.append((int(p[0], 16), p[1], p[2], i))
    names = {n for _, n, _, _ in rows}
    plain = sorted((a, n, t) for a, n, t, _ in rows if "." not in n and "[" not in n)
    stale = 0
    for a, n, t, i in rows:
        m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*)([.\[].*)$", n)
        if not m or m.group(1) in names:
            continue
        stale += 1
        ha, hn, ht = max((r for r in plain if r[0] <= a), default=(0, "?", ""))
        offset, field = a - ha, None
        o = 0
        for f, z in fields.get(ht, []):
            if o == offset:
                field = f
            o += z
        new = f"{hn}.{field}" if field else None
        print(f"   {fw.split('/')[1][:5]} 0x{a:x} {n} -> {new or '?'}  (covering 0x{ha:x} {hn} {ht} +{offset})")
        if new and "--fix" in sys.argv:
            p = lines[i].split(",", 3)
            comment = p[3] if len(p) > 3 else ""
            lines[i] = f"{p[0]},{new},{p[2]},{comment}{' ' if comment else ''}(was {n}: the covering row was renamed; {R})"
    if "--fix" in sys.argv:
        open(path, "w", newline="").write(E.join(lines))
    print(f"{fw.split('/')[1]}: {stale} stale documentation rows")
