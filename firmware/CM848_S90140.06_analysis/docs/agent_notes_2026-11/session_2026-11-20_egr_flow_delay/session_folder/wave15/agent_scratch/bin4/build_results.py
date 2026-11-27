"""Merge the part_*.py entry lists of bin 4 into the result file, validating each entry.
usage: build_results.py [--final]      (--final also demands all 64 bin records)
Idempotent: the result file is rewritten from the parts every run, in bin order."""
import glob
import importlib.util
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
W15 = "/home/linux/.claude/jobs/374b0424/tmp/w15/"
BIN = W15 + "bins/bin4.json"
RESULT = W15 + "results/result_W15_bin4.jsonl"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/"
FINAL = "--final" in sys.argv

BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg",
          "val", "cal_", "rpm_"}
BANNED -= {"cal_", "rpm_"}
EEPROM = (0x3fd482, 0x3feec1)
RECENT_PREFIXES = ("exhaust_pressure", "charge_pressure_estimate", "engine_speed_state", "average_engine_speed",
                   "main_engine_speed", "backup_engine_speed", "egr_valve_delta_pressure", "engine_delta_pressure",
                   "pumping_torque_", "nominal_engine_delta_pressure")

bin_items = json.load(open(BIN))
by_addr = {int(i["address"], 16): i for i in bin_items}

files = ["global_variables.csv", "structure_definitions.csv", "function_renames.csv", "enums.csv", "local_variables.csv",
         "arrays.csv", "constants.csv", "labels.csv", "function_definitions.csv", "cm848_rom.ghidra.cpp",
         "firmware_globals.hpp", "firmware_functions.hpp", "firmware_types.hpp"]
texts = {f: open(OUT + f, errors="replace").read() for f in files}
cpp = texts["cm848_rom.ghidra.cpp"]
norm = lambda t: re.sub(r"\s+", "", t)
bodies = {}
for chunk in re.split(r"(?m)^(?=// Function: )", cpp):
    m = re.match(r"// Function: (\S+)", chunk)
    if m:
        bodies[m.group(1)] = norm(chunk)
cpp_norm = norm(cpp)


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


entries = []
for path in sorted(glob.glob(os.path.join(HERE, "part_*.py"))):
    spec = importlib.util.spec_from_file_location(os.path.basename(path)[:-3], path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    entries += mod.ENTRIES

problems = []
by_address = {}
for e in entries:
    a = int(e["address"], 16)
    if a not in by_addr:
        problems.append(f"{e['address']}: not in the bin")
        continue
    if a in by_address:
        problems.append(f"{e['address']}: given twice")
    by_address[a] = e
    item = by_addr[a]
    tag = f"{e['address']} {e['old']}"
    if e["old"] != item["label_in_cpp"]:
        problems.append(f"{tag}: old != label_in_cpp {item['label_in_cpp']}")
    verdict = e["verdict"]
    if verdict not in ("confirmed", "keep", "drift", "uncertain"):
        problems.append(f"{tag}: bad verdict {verdict}")
    if verdict == "confirmed":
        for key in ("new", "evidence", "code_quote", "comment"):
            if not e.get(key):
                problems.append(f"{tag}: missing {key}")
        new = e.get("new", "")
        if new == e["old"]:
            problems.append(f"{tag}: new == old")
        if not re.match(r"^[a-z][a-z0-9_]*[a-z0-9]$", new) or "__" in new:
            problems.append(f"{tag}: name format {new}")
        bad = sorted(set(words(new)) & BANNED)
        if bad:
            problems.append(f"{tag}: banned words {bad} in {new}")
        if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
            problems.append(f"{tag}: hex-looking part in {new}")
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith("_cal") != in_eeprom:
            problems.append(f"{tag}: _cal rule broken for {new} (eeprom mirror: {in_eeprom})")
        if "protection" in words(new) and new.split("_")[-1] == "protection":
            problems.append(f"{tag}: bare protection")
        if any(new.startswith(p) for p in RECENT_PREFIXES):
            problems.append(f"{tag}: reserved recent prefix {new}")
        pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(new) + r"(?![A-Za-z0-9_])")
        where = [f for f, t in texts.items() if pat.search(t)]
        if where:
            problems.append(f"{tag}: new name {new} already in {where}")
        quote = e.get("code_quote", "")
        fn, _, line = quote.partition(": ")
        if fn not in bodies:
            problems.append(f"{tag}: code_quote function {fn!r} not found")
        else:
            nl = norm(line)
            if len(nl) < 12 or nl not in bodies[fn]:
                problems.append(f"{tag}: code_quote line not in {fn}: {line[:70]}")
            if e["old"] not in line:
                problems.append(f"{tag}: code_quote does not contain the old name")
        if "\n" in e["comment"] or "\n" in e["evidence"]:
            problems.append(f"{tag}: newline in comment/evidence")
        if "(was " in e["comment"]:
            problems.append(f"{tag}: comment contains '(was '")
        if not e["comment"].startswith("e2m "):
            problems.append(f"{tag}: comment does not lead with the e2m record")
    elif verdict == "keep":
        if e.get("new") != e["old"]:
            problems.append(f"{tag}: keep with new != old")
        note = e.get("e2m_note", "")
        m = re.match(r"^e2m ([0-9A-F]{4}) \+([0-9A-F]+) (\S+) '", note)
        if not m:
            problems.append(f"{tag}: e2m_note format: {note[:60]}")
        else:
            if m.group(1) != item["block"] or int(m.group(2), 16) != int(item["offset"], 16) or m.group(3) != item["record"]:
                problems.append(f"{tag}: e2m_note does not match the bin record {item['block']} +{item['offset']} {item['record']}")
    else:
        if not e.get("evidence"):
            problems.append(f"{tag}: missing evidence")

# the other agents' results: no equal new name
others = set()
for path in glob.glob(W15 + "results/result_W15_bin*.jsonl"):
    if path == RESULT:
        continue
    for line in open(path):
        line = line.strip()
        if line.startswith("{"):
            try:
                r = json.loads(line)
            except json.JSONDecodeError:
                continue
            if r.get("verdict") == "confirmed" and r.get("new"):
                others.add((r["new"], os.path.basename(path), r.get("address")))
mine = {}
for e in entries:
    if e["verdict"] == "confirmed":
        if e["new"] in mine:
            problems.append(f"duplicate new name {e['new']}: {mine[e['new']]} and {e['address']}")
        mine[e["new"]] = e["address"]
        for new, src, addr in others:
            if new == e["new"]:
                problems.append(f"new name {e['new']} also proposed in {src} for {addr}")

if FINAL:
    missing = [i["address"] for a, i in sorted(by_addr.items()) if a not in by_address]
    if missing:
        problems.append(f"missing records: {missing}")

if problems:
    print("PROBLEMS")
    for p in problems:
        print("  ", p)
    sys.exit(1)

order = [int(i["address"], 16) for i in bin_items]
with open(RESULT, "w") as f:
    n = 0
    for a in order:
        if a in by_address:
            e = by_address[a]
            out = {k: v for k, v in e.items()}
            f.write(json.dumps(out) + "\n")
            n += 1
counts = {}
for e in entries:
    counts[e["verdict"]] = counts.get(e["verdict"], 0) + 1
print(f"wrote {n} lines to {RESULT}: {counts}")
