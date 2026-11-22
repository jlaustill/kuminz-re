"""Round 15 stage A: name the empty-name (type-only) rows of the sensor channel families. Each row keeps its type; the
role leads its comment. The map's old label is the default label the .cpp renders (sensor_channel_config_t_<addr>,
WORD_<addr>, ema_filter_state_t_<addr>, sensor_channel_state_t_<addr>). Checks: the row exists with an empty name, the
new name is not a .cpp identifier or another CSV name, and the default label renders in the .cpp.
usage: apply_r15a_fill.py <repo> <fill.json> <map.csv>"""
import glob
import json
import os
import re
import sys

repo, fill_path, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
ids = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
csvs = "".join(open(p).read() for p in glob.glob(os.path.join(out, "*.csv")))
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
index = {l[:10]: i for i, l in enumerate(lines) if l.startswith("0x")}
fill = json.load(open(fill_path))
problems, maps = [], []
for addr, old, new, role in fill:
    i = index.get(addr)
    if i is None:
        problems.append(f"{addr}: no row")
        continue
    a, n, t, c = (lines[i].split(",", 3) + ["", "", ""])[:4]
    if n:
        problems.append(f"{addr}: has a name {n}")
    if new in ids or re.search(rf"\b{re.escape(new)}\b", csvs):
        problems.append(f"{addr}: {new} is taken")
    if old not in ids:
        problems.append(f"{addr}: default label {old} does not render")
    lines[i] = ",".join([a, new, t, role + (f" (was the default label {old})") + (f" | earlier note: {c}" if c else "")])
    maps.append(f"{addr},{new},{old},global")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
open(gv, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
print(f"filled {len(maps)} rows")
