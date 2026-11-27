"""Round 10 stage A: name the DAT_ lookup caches from new_r10a.json. A row with an empty name gets the name (its type,
usually word, stays); a missing row is inserted with an empty type (label-only). Map rows with the DAT_ labels.
String edits only (global_variables.csv takes commas unquoted). usage: apply_r10a_new.py <repo> <new.json> <map.csv>"""
import json
import os
import re
import sys

repo, new_path, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(p).read().split("\n")
NEW = json.load(open(new_path))
filled = inserted = 0
maps = []
for addr, name, comment in NEW:
    assert '"' not in comment
    idx = next((i for i, l in enumerate(lines) if l.startswith(addr + ",")), None)
    if idx is not None:
        a, n, t, c = (lines[idx].split(",", 3) + ["", ""])[:4]
        assert n == "", (addr, n)
        lines[idx] = ",".join([a, name, t, comment + (f" | earlier note: {c}" if c else "")])
        filled += 1
    else:
        k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > int(addr, 16))
        lines.insert(k, ",".join([addr, name, "", comment]))
        inserted += 1
    maps.append(f"{addr},{name},DAT_{addr[2:]},global")
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
print(f"filled {filled}, inserted {inserted}")
