"""Validate the bin 3 result file against the bin, the CSVs and the .cpp. usage: validate.py"""
import json
import re
import sys
from collections import Counter

BIN = "/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin3.json"
RES = "/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin3.jsonl"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/"
CPP = OUT + "cm848_rom.ghidra.cpp"
FILES = ["global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv", "constants.csv", "arrays.csv",
         "local_variables.csv", "function_definitions.csv", "cm848_rom.ghidra.cpp"]
MIRROR = (0x3FD482, 0x3FEEC1)
BANNED = {"temp", "cnt", "ref", "val", "calc", "init", "cfg", "coef", "tmptr", "thd", "cmd", "amb", "avg", "frac", "adj", "lmt", "lim", "sw",
          "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl", "est", "press", "spd", "accel", "hyst", "inj", "veh", "baro", "alt", "trq", "batt",
          "neg", "abs", "alloc", "tx", "rx", "msg", "buf", "src", "dest", "cal_", "max", "min"}
ALLOWED_SHORT = {"j1939", "pgn", "rpm", "can"}

if len(sys.argv) > 1:
    RES = sys.argv[1]

problems = []


def problem(index, text):
    problems.append(f"[{index}] {text}")


records = json.load(open(BIN))
lines = [json.loads(line) for line in open(RES) if line.strip()]
if len(lines) != len(records):
    problem("-", f"{len(lines)} result lines for {len(records)} records")

texts = {name: open(OUT + name, errors="replace").read() for name in FILES}
cpp_lines = texts["cm848_rom.ghidra.cpp"].split("\n")
function_of = []
current = None
for line in cpp_lines:
    m = re.match(r"^// Function: (\S+) @", line)
    if m:
        current = m.group(1)
    function_of.append(current)
by_function = {}
for line, fn in zip(cpp_lines, function_of):
    by_function.setdefault(fn, []).append(line.strip())

old_names = {r["label_in_cpp"] for r in records}
new_names = Counter()
for index, (record, line) in enumerate(zip(records, lines)):
    address, old = record["address"], record["label_in_cpp"]
    if line.get("address") != address:
        problem(index, f"address {line.get('address')} != bin {address}")
    if line.get("old") != old:
        problem(index, f"old {line.get('old')} != bin {old}")
    if line.get("kind") != "global":
        problem(index, "kind is not global")
    verdict = line.get("verdict")
    if verdict not in ("confirmed", "keep", "drift", "uncertain"):
        problem(index, f"bad verdict {verdict}")
    in_mirror = MIRROR[0] <= int(address, 16) <= MIRROR[1]
    if verdict == "keep":
        if line.get("new") != old:
            problem(index, "keep with a different new")
        if not re.match(r"^e2m [0-9A-F]{4} \+[0-9A-F]+ \S+ '.+'$", line.get("e2m_note", "")):
            problem(index, f"e2m_note shape: {line.get('e2m_note')}")
        if in_mirror != old.endswith("_cal"):
            problem(index, f"keep: _cal does not match the region (mirror={in_mirror}) for {old}")
        if "_" in old and any(tok in BANNED and tok not in ALLOWED_SHORT for tok in old.split("_")):
            problem(index, f"keep: banned token in {old}: {[t for t in old.split('_') if t in BANNED]}")
        # the note must name the record's block and offset
        want = f"e2m {record['block']} +{record['offset'].lstrip('0') or '0'} {record['record']} "
        if not line.get("e2m_note", "").startswith(want):
            problem(index, f"e2m_note does not start with '{want}': {line.get('e2m_note')}")
    if verdict == "confirmed":
        new = line["new"]
        new_names[new] += 1
        if not re.match(r"^[a-z][a-z0-9_]*$", new) or "__" in new or new.endswith("_"):
            problem(index, f"bad name shape {new}")
        if in_mirror != new.endswith("_cal"):
            problem(index, f"_cal does not match the region (mirror={in_mirror}) for {new}")
        tokens = new.split("_")
        banned = [t for t in tokens if t in BANNED]
        if banned:
            problem(index, f"banned tokens {banned} in {new}")
        for name, text in texts.items():
            if re.search(r"(?<![A-Za-z0-9_])" + re.escape(new) + r"(?![A-Za-z0-9_])", text):
                problem(index, f"new name {new} already exists in {name}")
        if new in old_names:
            problem(index, f"new name {new} is an old name of another bin row")
        quote = line.get("code_quote", "")
        m = re.match(r"^(\S+): (.+)$", quote)
        if not m:
            problem(index, f"code_quote shape: {quote}")
        else:
            function, text = m.group(1), m.group(2)
            body = by_function.get(function)
            if body is None:
                problem(index, f"code_quote function {function} not found")
            elif text.strip() not in body:
                problem(index, f"code_quote line not found verbatim in {function}: {text}")
            if text.lstrip().startswith(("/*", "*", "//")):
                problem(index, f"code_quote is a comment line: {text}")
            if old not in text:
                problem(index, f"code_quote does not use the old name {old}: {text}")
        comment = line.get("comment", "")
        if not comment or "(was " in comment or "\n" in comment:
            problem(index, "comment empty, has '(was ' or a newline")
        if "e2m" not in comment[:40] and "EEPROM" not in comment[:20]:
            problem(index, f"comment does not lead with the e2m record: {comment[:50]}")
        for other in records:
            name = other["label_in_cpp"]
            if name != old and other["address"] != address and re.search(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])", comment):
                problem(index, f"comment mentions the current name of another bin row: {name}")
        if re.search(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])", comment):
            problem(index, f"comment mentions its own old name {old}")
        if not line.get("evidence") or "\n" in line["evidence"]:
            problem(index, "evidence empty or multi-line")
        # the comment must keep the retyped note when the old comment had one
        if "| retyped" in record.get("current_comment", "") and "| retyped" not in comment:
            problem(index, "old comment had a retyped note that the new comment dropped")

for name, count in new_names.items():
    if count > 1:
        problem("-", f"new name {name} used {count} times")

counts = Counter(line.get("verdict") for line in lines)
print("verdict counts:", dict(counts))
if problems:
    print(f"{len(problems)} problems:")
    for text in problems:
        print("  ", text)
    sys.exit(1)
print("validation passed")
