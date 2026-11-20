"""Apply rename wave 13 (the misname review) after its gate.
- renames (verdict confirmed, new != old): run through the repo's apply_renames.py gate first (dry run); then the name,
  and the agent's comment + " (was <old>)", the old comment kept as "| earlier note:" (the repo convention) unless an
  agent showed it is wrong;
- keeps (verdict keep): the agent's e2m_note appended to the comment ("| e2m: ..."), unless the comment already cites
  that record;
- drift / uncertain: nothing.
An old name that also appears in CM550's CSVs or the cross-firmware maps (a shared name) is held back.
Writes map_stage8.csv (address,name,old_label,global).
usage: apply_W13.py <stage8 dir> <repo> [--dry-run]"""
import csv
import glob
import json
import os
import re
import subprocess
import sys

here, repo = sys.argv[1:3]
# old comments an agent showed to be wrong (from the wave-13 reports): not carried as an earlier note
WRONG_OLD_COMMENTS = {"0x0040b0ac", "0x003fed94", "0x003feb82", "0x003feb84", "0x003feb8a", "0x003fdfbe", "0x0040a67e",
                      "0x0040a684", "0x0040a1a4", "0x0040a1a8", "0x00408720"}
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
results = []
for path in sorted(glob.glob(os.path.join(here, "result_W13_bin*.jsonl"))):
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            r["_bin"] = os.path.basename(path)
            results.append(r)
# held for a later pass: enum-typed rows whose enum members still follow the old reading (bin 2), and a dword that
# should be split into its two terms first (bin 6)
HOLD = {0x40c04a, 0x40aa9a, 0x40a204}
renames = [r for r in results if r.get("verdict") == "confirmed" and r.get("new") and r.get("new") != r.get("old")
           and int(r["address"], 16) not in HOLD]
keeps = [r for r in results if r.get("verdict") == "keep" and r.get("e2m_note")]
shared_text = ""
for f in glob.glob(os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output", "*.csv")) + \
        [os.path.join(repo, "firmware", "cross_firmware_matches.csv"), os.path.join(repo, "docs", "cross_firmware_variable_map.csv")]:
    if os.path.exists(f):
        shared_text += open(f, errors="replace").read()
held = [r for r in renames if re.search(r"(?<![A-Za-z0-9_])" + re.escape(r["old"]) + r"(?![A-Za-z0-9_])", shared_text)]
renames = [r for r in renames if r not in held]
# the repo's gate, on a temporary file holding only the renames
gate_input = os.path.join(here, "gate_input_W13.jsonl")
with open(gate_input, "w") as f:
    for r in renames:
        f.write(json.dumps({k: r[k] for k in ("kind", "verdict", "address", "old", "new", "evidence")}) + "\n")
gate = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"),
                       out, gate_input], capture_output=True, text=True)
problems = [l for l in gate.stdout.splitlines() + gate.stderr.splitlines() if "PROBLEM" in l]
print(f"{len(results)} rows: {len(renames)} renames, {len(keeps)} keeps, {len(held)} held back (shared with CM550)")
for r in held:
    print(f"  held: {r['address']} {r['old']} -> {r['new']}")
print("\n".join(problems) if problems else "gate: no PROBLEM lines")
if dry or problems:
    sys.exit(1 if problems else 0)

path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
mapping = []
for r in renames:
    address = f"0x{int(r['address'], 16):08x}"
    i = index[address]
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == r["old"], (address, name, r["old"])
    new_comment = " ".join((r.get("comment") or r.get("evidence") or "").split())
    # the repo convention (apply_renames.py): the old comment stays as an earlier note - except where an agent showed
    # it is wrong (WRONG_OLD_COMMENTS)
    if comment and comment[:40] not in new_comment and address not in WRONG_OLD_COMMENTS:
        new_comment += f" | earlier note: {comment}"
    lines[i] = ",".join([a, r["new"], typ, f"{new_comment} (was {r['old']})"])
    mapping.append((address, r["new"], r["old"]))
for r in keeps:
    address = f"0x{int(r['address'], 16):08x}"
    i = index.get(address)
    if i is None:
        continue
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    record = r["e2m_note"].split()[3] if len(r["e2m_note"].split()) > 3 else ""
    if name != r["old"] or "| e2m:" in comment or (record and record in comment):
        continue
    note = " ".join(r["e2m_note"].split())
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
open(path, "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage8.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in mapping:
        f.write(f"{address},{new},{old},global\n")
print(f"applied {len(mapping)} renames and {len(keeps)} e2m notes")
