"""Round 97 stage C: apply function_spelling_plan_r97.csv.
- function_renames.csv: each planned row takes its new name; its plate gains '(was <old>; PR #53 round 97)' (a row with
  no plate gets that note as its plate).
- function_definitions.csv / local_variables.csv: the function_name column of rows at a renamed address.
Writes map_r97c_<fw>.csv (address,name,old_label,kind,dims) for the reference refresh and the proofs.
Refuses on a mismatch; keeps line endings. usage: apply_function_spelling_r97.py <repo> <plan.csv>"""
import collections
import csv
import os
import sys

repo, plan_path = os.path.abspath(sys.argv[1]), sys.argv[2]
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
NOTE = "PR #53 round 97"
plan = collections.defaultdict(dict)
for r in csv.DictReader(open(plan_path)):
    plan[r["firmware"]][int(r["address"], 16)] = (r["old"], r["new"])
for fw, rows in plan.items():
    d = os.path.join(repo, OUT[fw])
    p = os.path.join(d, "function_renames.csv")
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    done = set()
    for i, line in enumerate(lines):
        parts = line.split(",", 2)
        if len(parts) < 2 or not parts[0].startswith("0x"):
            continue
        a = int(parts[0], 16)
        if a not in rows:
            continue
        old, new = rows[a]
        assert parts[1] == old, (fw, hex(a), parts[1], old)
        plate = parts[2] if len(parts) > 2 else ""
        note = f"(was {old}; {NOTE})"
        plate = f"{plate} {note}" if plate else note
        lines[i] = f"{parts[0]},{new},{plate}"
        done.add(a)
    assert done == set(rows), (fw, set(rows) - done)
    open(p, "w", newline="").write(E.join(lines))
    for f in ("function_definitions.csv", "local_variables.csv"):
        q = os.path.join(d, f)
        t = open(q, newline="").read()
        E2 = "\r\n" if "\r\n" in t else "\n"
        ls = t.split(E2)
        n = 0
        for i, line in enumerate(ls):
            parts = line.split(",", 2)
            if len(parts) > 2 and parts[0].startswith("0x") and int(parts[0], 16) in rows:
                old, new = rows[int(parts[0], 16)]
                if parts[1] == old:
                    ls[i] = f"{parts[0]},{new},{parts[2]}"
                    n += 1
        open(q, "w", newline="").write(E2.join(ls))
        print(fw, f, n, "function_name cells")
    with open(os.path.join(HERE, f"map_r97c_{fw.lower()}.csv"), "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, (old, new) in sorted(rows.items()):
            fh.write(f"0x{a:08x},{new},{old},symbol,1\n")
    print(fw, len(rows), "functions renamed")
