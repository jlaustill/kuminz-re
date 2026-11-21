"""Collect every verdicts_*.py in this folder (sorted), validate the entries and rewrite the result file
(atomically) with one JSON line per entry, in bin order.  Prints every problem; exit status 1 when there is one.
usage: emit.py [--final]      (--final also demands all 62 bin addresses)"""
import glob
import importlib.util
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
BIN = "/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin5.json"
RESULT = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin5.jsonl"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output"
CPP = os.path.join(OUT, "cm848_rom.ghidra.cpp")

final = "--final" in sys.argv
bin_rows = {r["address"]: r for r in json.load(open(BIN))}
entries = []
for path in sorted(glob.glob(os.path.join(HERE, "verdicts_*.py"))):
    spec = importlib.util.spec_from_file_location(os.path.basename(path)[:-3], path)
    module = importlib.util.module_from_spec(spec)
    sys.path.insert(0, HERE)
    spec.loader.exec_module(module)
    entries.extend(module.ENTRIES)

problems = []
seen = {}
for e in entries:
    a = e.get("address")
    if a in seen:
        problems.append(f"{a}: duplicate address")
    seen[a] = e
    if a not in bin_rows:
        problems.append(f"{a}: not in the bin")
        continue
    row = bin_rows[a]
    if e["old"] != row["label_in_cpp"]:
        problems.append(f"{a}: old '{e['old']}' != bin label '{row['label_in_cpp']}'")

# --- name checks --------------------------------------------------------------------------------------------
text_cpp = open(CPP, errors="replace").read()
csv_text = ""
for path in glob.glob(os.path.join(OUT, "*.csv")):
    csv_text += open(path, errors="replace").read() + "\n"
ABBREVIATIONS = {"init", "std", "ch", "freq", "prop", "temp", "tmptr", "cnt", "ref", "val", "calc", "cfg", "coef", "lim",
                 "lmt", "thd", "cmd", "amb", "avg", "frac", "adj", "sw", "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl",
                 "est", "press", "spd", "accel", "hyst", "inj", "veh", "baro", "alt", "trq", "batt", "imt", "ct", "aps",
                 "icp", "cot", "mcf", "cmf", "vgt", "pto", "cc", "eb", "jcomm", "el", "tpe", "chp", "lsg", "hsg", "asg",
                 "vsg", "pp", "esp", "tgc", "tw", "rsg", "bdo", "oc", "nv", "dat42", "mm3s", "src", "dest", "param",
                 "config", "max", "min"}
# "max"/"min" are flagged only as a warning: "maximum"/"minimum" are the spelled-out words.
new_names = {}
for e in entries:
    if e["verdict"] != "confirmed":
        continue
    a, new = e["address"], e["new"]
    row = bin_rows.get(a)
    if not row:
        continue
    if new in new_names:
        problems.append(f"{a}: new name '{new}' also used at {new_names[new]}")
    new_names[new] = a
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problems.append(f"{a}: '{new}' is not snake_case")
    if "__" in new or new.endswith("_") and not new.endswith("_cal"):
        problems.append(f"{a}: '{new}' has a double or trailing underscore")
    if new == e["old"]:
        problems.append(f"{a}: confirmed rename keeps the same name")
    in_mirror = 0x3fd482 <= int(a, 16) <= 0x3feec1
    if in_mirror != new.endswith("_cal"):
        problems.append(f"{a}: '{new}' _cal does not match the region ({'mirror' if in_mirror else 'not mirror'})")
    for token in new.split("_"):
        if token in ABBREVIATIONS:
            print(f"WARN {a}: '{new}' contains the token '{token}' (abbreviation?)")
    if token_bare := re.search(r"(^|_)protection(_|$)", new):
        if not re.search(r"_protection(_|$)", new) or new.startswith("protection_"):
            print(f"WARN {a}: '{new}' has a bare 'protection'")
    if re.search(rf"\b{re.escape(new)}\b", text_cpp):
        problems.append(f"{a}: '{new}' already appears in the .cpp")
    if re.search(rf"\b{re.escape(new)}\b", csv_text):
        problems.append(f"{a}: '{new}' already appears in an output CSV")
    # code quote
    cq = e.get("code_quote", "")
    m = re.match(r"([A-Za-z0-9_]+): (.+)$", cq)
    if not m:
        problems.append(f"{a}: code_quote is not '<function>: <line>'")
    else:
        fn, line = m.group(1), m.group(2).strip()
        mm = re.search(rf"^// Function: {re.escape(fn)} @.*?(?=^// Function: |\Z)", text_cpp, re.S | re.M)
        if not mm:
            problems.append(f"{a}: code_quote function '{fn}' not found in the .cpp")
        else:
            lines = [x.strip() for x in mm.group(0).split("\n")]
            if line not in lines:
                problems.append(f"{a}: code_quote line not found verbatim in {fn}: {line!r}")
            if not re.search(rf"\b{re.escape(e['old'])}\b", line):
                problems.append(f"{a}: code_quote does not contain the old name {e['old']}")
    if "(was" in e.get("comment", ""):
        problems.append(f"{a}: comment contains '(was'")
    for key in ("evidence", "comment"):
        if not e.get(key):
            problems.append(f"{a}: empty {key}")
# --- keys per verdict ---------------------------------------------------------------------------------------
KEYS = {"confirmed": {"kind", "verdict", "address", "old", "new", "evidence", "code_quote", "comment"},
        "keep": {"kind", "verdict", "address", "old", "new", "e2m_note"},
        "drift": {"kind", "verdict", "address", "old", "evidence"},
        "uncertain": {"kind", "verdict", "address", "old", "evidence"}}
for e in entries:
    want = KEYS.get(e["verdict"])
    if want is None:
        problems.append(f"{e['address']}: unknown verdict {e['verdict']}")
    elif set(e) != want:
        problems.append(f"{e['address']}: keys {sorted(set(e) ^ want)} differ for verdict {e['verdict']}")
    if e["verdict"] == "keep" and e["new"] != e["old"]:
        problems.append(f"{e['address']}: keep with a different new name")
    if e["verdict"] == "keep" and not re.match(r"e2m [0-9A-F]{4} \+[0-9A-F]+ \S+ '", e.get("e2m_note", "")):
        problems.append(f"{e['address']}: e2m_note format")
if final:
    for a in bin_rows:
        if a not in seen:
            problems.append(f"{a}: no verdict")
    if len(entries) != 62:
        problems.append(f"{len(entries)} entries, expected 62")

# --- a comment must not cite the old name of any confirmed rename (its own included): the apply adds "(was ...)" ----
olds = {e["old"]: e["address"] for e in entries if e["verdict"] == "confirmed"}
for e in entries:
    if e["verdict"] != "confirmed":
        continue
    for old, where in olds.items():
        if re.search(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", e["comment"]):
            problems.append(f"{e['address']}: comment cites {old}, which is renamed at {where}")
# --- ASCII only, one JSON object per line ------------------------------------------------------------------
for e in entries:
    for key, value in e.items():
        if isinstance(value, str) and any(ord(ch) > 127 for ch in value):
            problems.append(f"{e['address']}: non-ASCII character in {key}")
        if isinstance(value, str) and "\n" in value:
            problems.append(f"{e['address']}: newline in {key}")

order = {a: i for i, a in enumerate(bin_rows)}
entries.sort(key=lambda e: order.get(e["address"], 999))
tmp = RESULT + ".tmp"
with open(tmp, "w") as f:
    for e in entries:
        f.write(json.dumps(e, ensure_ascii=False) + "\n")
os.replace(tmp, RESULT)
counts = {}
for e in entries:
    counts[e["verdict"]] = counts.get(e["verdict"], 0) + 1
print(f"wrote {len(entries)} entries to {RESULT}: {counts}")
for p in problems:
    print("PROBLEM:", p)
sys.exit(1 if problems else 0)
