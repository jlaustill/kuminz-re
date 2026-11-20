"""Apply rename wave 14 after its checks.
- Every result line: known kind / verdict, address in its bin, `old` = the current CSV name.
- Renames: new name format (functions `<prefix>_<camelCase>`, globals snake_case); no duplicate new names; the
  code_quote is in the function's body (functions) or in the .cpp next to the row's name (globals).
- Held, not applied (listed for the report): functions whose current name is shared with CM550 or that carry the
  owner's signed review note; globals with a type_note or a split (the main session handles widths by hand); enum items.
- The repo gate (apply_renames.py) runs on everything that is left (dry run); any PROBLEM line stops the apply.
- Functions are applied through apply_renames.py --apply (it also updates the name columns of function_definitions.csv
  and local_variables.csv). Plate = the agent's plate + " (was <old>)" + " | earlier note: <old plate>". A keep with a
  plate is a plate-only refresh, with the old plate kept the same way.
- Globals: comment = the agent's comment + " (was <old>)" + " | earlier note: <old comment>" (dropped when the agent set
  old_comment_wrong or already carried it). Keeps get "| e2m: <note>" unless the comment already cites the record.
Writes map_stage9.csv and held_W14.json.
usage: apply_W14.py <stage9 dir> <repo> [--dry-run]"""
import csv
import glob
import json
import os
import re
import subprocess
import sys

here, repo = sys.argv[1:3]
dry = "--dry-run" in sys.argv
# true CM550 twins the precomputed name check missed (found by the agents)
EXTRA_SHARED = {"0x0000e164"}
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
norm = lambda t: re.sub(r"\s+", "", t)
cpp_norm = norm(cpp)
bodies = {}
for chunk in re.split(r"(?m)^(?=// Function: )", cpp):
    m = re.match(r"// Function: (\S+)", chunk)
    if m:
        bodies[m.group(1)] = norm(chunk)
bins = {}
for path in glob.glob(os.path.join(here, "bins", "*.json")):
    data = json.load(open(path))
    items = data["functions"] + data.get("held_enum_rows", []) if isinstance(data, dict) else data
    for item in items:
        bins[(os.path.basename(path)[:-5], f"0x{int(item['address'], 16):08x}")] = item
fr = {l.split(",")[0]: l.rstrip("\r\n").split(",", 2) for l in open(os.path.join(out, "function_renames.csv"), errors="replace")
      if l.startswith("0x")}
gv = {l.split(",")[0]: (l.rstrip("\n").split(",", 3) + [""])[:4] for l in open(os.path.join(out, "global_variables.csv"),
      errors="replace") if l.startswith("0x")}
fn_names = {v[1] for v in fr.values()}
gv_names = {v[1] for v in gv.values()}
results, problems, held = [], [], []
for path in sorted(glob.glob(os.path.join(here, "result_W14_*.jsonl"))):
    bin_name = os.path.basename(path)[len("result_W14_"):-len(".jsonl")]
    for n, line in enumerate(open(path), 1):
        if not line.strip():
            continue
        r = json.loads(line)
        r["_bin"], r["_line"] = bin_name, n
        address = f"0x{int(r['address'], 16):08x}"
        r["address"] = address
        if (bin_name, address) not in bins:
            problems.append(f"{bin_name}:{n} {address} is not in the bin")
            continue
        kind, verdict = r.get("kind"), r.get("verdict")
        if kind not in ("function", "global", "enum") or verdict not in ("confirmed", "keep", "drift", "uncertain"):
            problems.append(f"{bin_name}:{n} bad kind / verdict {kind} / {verdict}")
            continue
        current = fr[address][1] if kind == "function" else gv.get(address, ["", ""])[1]
        if r.get("old") != current:
            problems.append(f"{bin_name}:{n} {address} old {r.get('old')} != current {current}")
            continue
        results.append(r)
renames = [r for r in results if r["verdict"] == "confirmed" and r.get("new") and r["new"] != r["old"]]
seen = {}
for r in renames:
    key = (r["kind"], r["new"])
    if key in seen:
        problems.append(f"duplicate new name {r['new']}: {seen[key]} and {r['address']}")
    seen[key] = r["address"]
apply_functions, apply_globals, plate_only = [], [], []
for r in results:
    item = bins[(r["_bin"], r["address"])]
    if r["kind"] == "enum":
        held.append({**r, "why": "enum item (applied by hand)"})
        continue
    if r["verdict"] != "confirmed" and not (r["kind"] == "function" and r["verdict"] == "keep" and r.get("plate_comment")):
        continue
    is_rename = r.get("new") and r["new"] != r["old"]
    quote = r.get("code_quote", "")
    if is_rename:
        if r["kind"] == "function":
            if not re.match(r"^(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*$", r["new"]):
                problems.append(f"{r['address']} function name format: {r['new']}")
            if r["new"] in fn_names:
                problems.append(f"{r['address']} function name exists: {r['new']}")
            if len(norm(quote)) < 12 or norm(quote) not in bodies.get(r["old"], ""):
                problems.append(f"{r['address']} {r['old']}: code_quote not in the function: {quote[:80]}")
        else:
            if not re.match(r"^[a-z][a-z0-9_]*[a-z0-9]$", r["new"]) or "__" in r["new"]:
                problems.append(f"{r['address']} global name format: {r['new']}")
            if r["new"] in gv_names:
                problems.append(f"{r['address']} global name exists: {r['new']}")
            if len(norm(quote)) < 12 or norm(quote) not in cpp_norm or r["old"] not in quote:
                problems.append(f"{r['address']} {r['old']}: code_quote not found with the name: {quote[:80]}")
    if r["kind"] == "function" and (item.get("shared_with_cm550") or item.get("user_review_note")
                                    or r["address"] in EXTRA_SHARED):
        held.append({**r, "why": "owner's review note" if item.get("user_review_note") else
                     ("shared with CM550" if item.get("shared_with_cm550") else "shared with CM550 (a true twin the agent found)")})
        continue
    if r["kind"] == "global" and (r.get("type_note") or r.get("split")):
        held.append({**r, "why": "type note / split (width, by hand)"})
        continue
    if r["kind"] == "function":
        old_plate = fr[r["address"]][2] if len(fr[r["address"]]) > 2 else ""
        plate = " ".join((r.get("plate_comment") or "").split())
        if is_rename:
            plate = f"{plate} (was {r['old']})"
        if old_plate and old_plate[:40] not in plate:
            plate += f" | earlier note: {old_plate}"
        (apply_functions if is_rename else plate_only).append({**r, "_plate": plate})
    else:
        apply_globals.append(r)
keeps = [r for r in results if r["kind"] == "global" and r["verdict"] == "keep" and r.get("e2m_note")]
counts = {}
for r in results:
    counts[(r["kind"], r["verdict"])] = counts.get((r["kind"], r["verdict"]), 0) + 1
print("verdicts:", {f"{k[0]} {k[1]}": v for k, v in sorted(counts.items())})
print(f"to apply: {len(apply_functions)} function renames, {len(plate_only)} plate refreshes, {len(apply_globals)} global"
      f" renames, {len(keeps)} keep notes; held: {len(held)}")
gate_input = os.path.join(here, "gate_input_W14.jsonl")
with open(gate_input, "w") as f:
    for r in apply_functions + plate_only:
        f.write(json.dumps({"kind": "function", "verdict": "confirmed", "address": r["address"], "old": r["old"],
                            "new": r.get("new") or r["old"], "plate_comment": r["_plate"]}) + "\n")
    for r in apply_globals:
        f.write(json.dumps({"kind": "global", "verdict": "confirmed", "address": r["address"], "old": r["old"],
                            "new": r["new"], "evidence": r.get("comment") or r.get("evidence", "")}) + "\n")
gate = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"), out,
                       gate_input], capture_output=True, text=True)
problems += [l for l in gate.stdout.splitlines() + gate.stderr.splitlines() if "PROBLEM" in l]
print(gate.stdout.strip().splitlines()[-1] if gate.stdout.strip() else gate.stderr[-300:])
json.dump(held, open(os.path.join(here, "held_W14.json"), "w"), indent=1)
print("\n".join(problems) if problems else "checks: no problems")
if dry or problems:
    sys.exit(1 if problems else 0)

# functions (and plate-only refreshes) through the repo's apply
function_input = os.path.join(here, "gate_input_W14_functions.jsonl")
with open(function_input, "w") as f:
    for r in apply_functions + plate_only:
        f.write(json.dumps({"kind": "function", "verdict": "confirmed", "address": r["address"], "old": r["old"],
                            "new": r.get("new") or r["old"], "plate_comment": r["_plate"]}) + "\n")
done = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"), out,
                       function_input, "--apply"], capture_output=True, text=True)
print(done.stdout.strip()[-400:])
assert done.returncode == 0, done.stderr[-500:]
# globals
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
for r in apply_globals:
    i = index[r["address"]]
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == r["old"], (r["address"], name)
    new_comment = " ".join((r.get("comment") or r.get("evidence") or "").split()) + f" (was {r['old']})"
    if comment and not r.get("old_comment_wrong") and comment[:40] not in new_comment:
        new_comment += f" | earlier note: {comment}"
    lines[i] = ",".join([a, r["new"], typ, new_comment])
for r in keeps:
    i = index.get(r["address"])
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    record = r["e2m_note"].split()[3] if len(r["e2m_note"].split()) > 3 else ""
    if name != r["old"] or "| e2m:" in comment or (record and record in comment):
        continue
    note = " ".join(r["e2m_note"].split())
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
open(path, "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage9.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for r in apply_functions:
        f.write(f"{r['address']},{r['new']},{r['old']},function\n")
    for r in apply_globals:
        f.write(f"{r['address']},{r['new']},{r['old']},global\n")
print(f"applied {len(apply_functions)} function renames, {len(plate_only)} plate refreshes, {len(apply_globals)} global"
      f" renames, keep notes on {len(keeps)} rows")
