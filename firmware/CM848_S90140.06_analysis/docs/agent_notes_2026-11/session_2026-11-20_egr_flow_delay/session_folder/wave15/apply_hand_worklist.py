"""Apply a main-session worklist of hand-verified renames (stage 10b on), with the wave 15 checks.
Worklist: a Python file defining GLOBALS = [(address, new, role), ...] and FUNCTIONS = [(address, new, plate), ...].
- Globals: old = the current CSV name; the e2m record (the ECU's parameter ID table, e2m_block_addresses.py
  --address) leads the comment when the address has one; the role text follows. The quote is the first .cpp code
  line with the old name (printed for review); the checks: the new name is not an existing global / function /
  field / parameter / local / .cpp identifier, no duplicates, _cal = EEPROM mirror, no banned abbreviation, and the
  old name is not in CM550 or the cross-firmware maps (unless the address is in NOT_TWINS of the worklist).
  Comment = e2m part + role + " (was <old>)" + " | earlier note: <old comment>".
- Functions: through the repo's apply_renames.py (it also updates function_definitions / local_variables names);
  plate = the given plate + " (was <old>)" + " | earlier note: <old plate>".
Appends address,name,old_label,kind rows to the map.
usage: apply_hand_worklist.py <worklist.py> <repo> <map.csv> [--dry-run]"""
import csv
import glob
import json
import os
import re
import runpy
import subprocess
import sys

worklist_path, repo, map_path = sys.argv[1:4]
dry = "--dry-run" in sys.argv
work = runpy.run_path(worklist_path)
GLOBALS, FUNCTIONS = work.get("GLOBALS", []), work.get("FUNCTIONS", [])
NOT_TWINS = set(work.get("NOT_TWINS", set()))
QUOTE_OVERRIDE = work.get("QUOTE_OVERRIDE", {})
fw = os.path.join(repo, "firmware")
out = os.path.join(fw, "CM848_S90140.06_analysis", "output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
cpp_lines = cpp.split("\n")
cpp_identifiers = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
function_at, current, in_block = [], "", False
for line in cpp_lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    # lines inside a /* ... */ plate comment are not code: no function, so the quote picker skips them
    starts = "/*" in line and "*/" not in line.split("/*", 1)[1]
    function_at.append("" if in_block or line.strip().startswith("/*") else current)
    if starts:
        in_block = True
    elif in_block and "*/" in line:
        in_block = False
BANNED = {"temp", "tmp", "cnt", "ref", "val", "calc", "init", "cfg", "coef", "coeff", "ptr", "addr", "buf", "idx",
          "msg", "thd", "thresh", "hyst", "accel", "est", "press", "spd", "filt", "diag", "ovr", "vlv", "pct", "cyl",
          "trq", "batt", "veh", "baro", "amb", "cmd", "adj", "lmt", "lim", "sw", "inj", "avg", "frac", "pos", "sel",
          "req", "err", "freq", "ctrl", "stat", "seq", "src", "dst", "num", "cond", "info", "mgr", "proc", "sens",
          "volt", "curr", "accum", "thr", "tbl", "lut", "hdr", "eng", "prot", "mult", "comp", "deg", "sec", "aux",
          "arb", "qty", "corr", "lkp", "tmr", "util", "resp"}
gv_lines = open(os.path.join(out, "global_variables.csv"), newline="").read().split("\n")
gv_index = {l.split(",", 1)[0]: i for i, l in enumerate(gv_lines) if l.startswith("0x")}
gv_names = {l.split(",")[1] for l in gv_lines if l.startswith("0x") and "," in l}
fr = {l.split(",")[0]: l.rstrip("\r\n").split(",", 2) for l in open(os.path.join(out, "function_renames.csv"),
                                                                     errors="replace") if l.startswith("0x")}
fn_names = {v[1] for v in fr.values()}


def column(path, k):
    return {row[k] for row in csv.reader(open(path, errors="replace")) if len(row) > k}


taken = (gv_names | fn_names | cpp_identifiers | column(os.path.join(out, "structure_definitions.csv"), 2)
         | column(os.path.join(out, "structure_definitions.csv"), 0)
         | column(os.path.join(out, "function_definitions.csv"), 3) | column(os.path.join(out, "local_variables.csv"), 3)
         | column(os.path.join(out, "enums.csv"), 2))
shared_text = ""
for f in glob.glob(os.path.join(fw, "CM550_J90350.00_analysis", "output", "*.csv")) + \
        [os.path.join(fw, "cross_firmware_matches.csv"), os.path.join(repo, "docs", "cross_firmware_variable_map.csv")]:
    if os.path.exists(f):
        shared_text += open(f, errors="replace").read()


def e2m_of(address):
    run = subprocess.run([sys.executable, os.path.join(fw, "scripts", "e2m_block_addresses.py"), "--address", address],
                         capture_output=True, text=True, cwd=fw)
    m = re.match(r"(\S+) \+(\S+) (\S+) \[([^\]]*)\] -> \S+ \S+ \S+; ?(.*)", run.stdout.strip().split("\n")[0])
    if not m:
        return ""
    block, offset, record, unit, description = m.groups()
    description = re.sub(r"^\[[A-Z0-9]+\] ?", "", description).strip().rstrip(".")
    return f"e2m {block} +{offset.lstrip('0') or '0'} {record} '{description}' ({unit})"


problems, mapping, seen = [], [], {}
for address, new, role in GLOBALS:
    address = f"0x{int(address, 16):08x}"
    if address not in gv_index:
        problems.append(f"{address}: no global_variables.csv row")
        continue
    a, old, typ, comment = (gv_lines[gv_index[address]].split(",", 3) + [""])[:4]
    if new in seen:
        problems.append(f"{address} duplicate new name {new} (also {seen[new]})")
    seen[new] = address
    if not re.match(r"^[a-z][a-z0-9_]*[a-z0-9]$", new) or "__" in new:
        problems.append(f"{address} name format: {new}")
    if new in taken:
        problems.append(f"{address} {new} exists")
    a_int = int(address, 16)
    if (0x3fd482 <= a_int <= 0x3feec1) != new.endswith("_cal"):
        problems.append(f"{address} _cal rule: {new}")
    bad = [t for t in new.split("_") if t in BANNED]
    if bad:
        problems.append(f"{address} abbreviation {bad} in {new}")
    if address not in NOT_TWINS and re.search(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])",
                                              shared_text):
        problems.append(f"{address} old name {old} is in CM550 / the cross-firmware maps")
    quote = QUOTE_OVERRIDE.get(address)
    if not quote:
        pattern = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])")
        for i, line in enumerate(cpp_lines):
            s = line.strip()
            if not s.startswith(("//", "/*", "*")) and pattern.search(s) and function_at[i]:
                quote = f"{function_at[i]}: {s[:140]}"
                break
    if not quote:
        problems.append(f"{address} {old}: no code line uses it")
    print(f"{address} {old} -> {new}\n    Q: {quote}")
    e2m = e2m_of(address)
    text = (f"{e2m}: {role}" if e2m else role).strip() + f" (was {old})"
    if comment and comment[:40] not in text:
        text += f" | earlier note: {comment}"
    gv_lines[gv_index[address]] = ",".join([a, new, typ, text])
    mapping.append((address, new, old, "global"))
function_rows = []
for address, new, plate in FUNCTIONS:
    address = f"0x{int(address, 16):08x}"
    old = fr[address][1]
    old_plate = fr[address][2] if len(fr[address]) > 2 else ""
    if new in taken:
        problems.append(f"{address} {new} exists")
    if not re.match(r"^(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*$", new):
        problems.append(f"{address} function name format: {new}")
    if re.search(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])", shared_text) and address not in NOT_TWINS:
        problems.append(f"{address} old function name {old} is in CM550 / the cross-firmware maps")
    text = f"{plate} (was {old})"
    if old_plate and old_plate[:40] not in text:
        text += f" | earlier note: {old_plate}"
    function_rows.append({"kind": "function", "verdict": "confirmed", "address": address, "old": old, "new": new,
                          "plate_comment": text})
    print(f"{address} {old} -> {new}")
    mapping.append((address, new, old, "function"))
print(f"{len(GLOBALS)} globals, {len(FUNCTIONS)} functions")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
if dry or problems:
    sys.exit(1 if problems else 0)
open(os.path.join(out, "global_variables.csv"), "w", newline="").write("\n".join(gv_lines))
if function_rows:
    gate = map_path + ".functions.jsonl"
    open(gate, "w").write("".join(json.dumps(r) + "\n" for r in function_rows))
    done = subprocess.run([sys.executable, os.path.join(fw, "scripts", "rename_waves", "apply_renames.py"), out, gate,
                           "--apply"], capture_output=True, text=True)
    print(done.stdout.strip()[-300:])
    assert done.returncode == 0 and "PROBLEM" not in done.stdout, done.stdout[-800:] + done.stderr[-500:]
new_file = not os.path.exists(map_path)
with open(map_path, "a") as f:
    if new_file:
        f.write("address,name,old_label,kind\n")
    for address, new, old, kind in mapping:
        f.write(f"{address},{new},{old},{kind}\n")
print(f"applied {len(GLOBALS)} globals and {len(FUNCTIONS)} functions")
