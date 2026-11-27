"""Round 93 (read-only): for each MID-BODY row of midfunction_rows_r93.txt, what else hangs on it: its plate comment,
function_definitions.csv / local_variables.csv rows, how the .cpp renders it and its container now (lines of each,
and whether the container's code already runs through the row's code), and where its name is mentioned.
usage: midbody2_survey_r93.py <repo> <midfunction_rows.txt>"""
import csv
import os
import re
import sys

repo, listing = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
bodies = {}
for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", cpp, re.M | re.S):
    code = re.sub(r"/\*.*?\*/", "", m.group(3), flags=re.S)
    bodies[int(m.group(2), 16)] = (m.group(1), [l for l in code.split("\n") if l.strip() and not l.strip().startswith("//")])
renames = {int(r[0], 16): r for r in csv.reader(open(os.path.join(O, "function_renames.csv"), newline="")) if r and r[0].startswith("0x")}
defs = open(os.path.join(O, "function_definitions.csv")).read()
locs = open(os.path.join(O, "local_variables.csv")).read()
glob = open(os.path.join(O, "global_variables.csv")).read()
for line in open(listing):
    if not line.startswith("MID-BODY"):
        continue
    parts = line.split()
    a, name, prev = int(parts[1], 16), parts[2], int(parts[4], 16)
    key = f"0x{a:08x}"
    row = renames.get(a, [])
    plate = row[2] if len(row) > 2 else ""
    own = bodies.get(a, ("", []))[1]
    container = bodies.get(prev, ("", []))[1]
    # does the container's code already contain the row's code (the tail)?
    tail = [l.strip() for l in own[2:-1] if l.strip() not in ("{", "}", "return;")]
    held = sum(1 for l in tail if any(l == c.strip() for c in container))
    mentions = len(re.findall(rf"\b{re.escape(name)}\b", cpp)) - (2 if own else 0)
    calls_from_container = any(re.search(rf"\b{re.escape(name)}\s*\(", c) for c in container)
    print(f"{a:05x} {name[:44]:44} own {len(own):3} lines | container {prev:05x} {len(container):3} lines, holds {held}/{len(tail)} tail lines"
          f"{' CALLS IT' if calls_from_container else ''} | other .cpp mentions {mentions} | defs {defs.count(chr(10) + key + ',')} locals {locs.count(chr(10) + key + ',')}"
          f" | csv mentions {len(re.findall(rf'{re.escape(name)}', glob))}{' | plate: ' + plate[:50] if plate else ''}")
