"""Apply rename wave 12: the gated new rows (gated_W12.jsonl) go into global_variables.csv next to their address
neighbours, with the agent's comment (clipped like the rename_waves tools) + "(new row 2026-11-19, wave 12)".
Writes the proof map (address,new,DAT_<address>,global) to map_stage7.csv (created or appended).
usage: apply_W12.py <stage7 dir> <CM848 output dir>"""
import json
import os
import sys

here, out = sys.argv[1:3]
sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/rename_waves")
from common import clip  # noqa: E402

rows = [json.loads(l) for l in open(os.path.join(here, "gated_W12.jsonl")) if l.strip()]
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
present = {l.split(",", 1)[0] for l in lines if l.startswith("0x")}
added = []
for r in sorted(rows, key=lambda x: int(x["address"], 16)):
    address = f"0x{int(r['address'], 16):08x}"
    assert address not in present, address
    comment = " ".join((r.get("comment") or r.get("evidence") or "").split())
    comment = clip(comment, 360) + " (new row 2026-11-19, wave 12)"
    row = ",".join([address, r["new"], r["type"], comment])
    a = int(address, 16)
    candidates = [k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) < a]
    nearest = max(candidates, key=lambda k: int(lines[k].split(",", 1)[0], 16)) if candidates else len(lines) - 1
    lines.insert(nearest + 1, row)
    present.add(address)
    added.append((address, r["new"]))
open(path, "w", newline="").write("\n".join(lines))
map_path = os.path.join(here, "map_stage7.csv")
new_file = not os.path.exists(map_path)
with open(map_path, "a") as f:
    if new_file:
        f.write("address,name,old_label,kind\n")
    for address, name in added:
        f.write(f"{address},{name},DAT_{int(address, 16):08x},global\n")
print(f"{len(added)} new rows applied")
