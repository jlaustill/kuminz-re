import csv
import json
import re
import sys

ROOT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis"
RESULT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1b.jsonl"


def read_rows(path):
    rows = []
    with open(path, newline="") as handle:
        for line in handle:
            if line.startswith("#") or not line.strip():
                continue
            rows.append(next(csv.reader([line])))
    return rows


globals_rows = read_rows(ROOT + "/output/global_variables.csv")
globals_by_address = {}
all_names = set()
for row in globals_rows[1:]:
    if len(row) >= 2:
        globals_by_address[row[0].lower()] = row[1]
        all_names.add(row[1])

arrays_rows = read_rows(ROOT + "/output/arrays.csv")
for row in arrays_rows[1:]:
    for cell in row[:3]:
        all_names.add(cell)

function_rows = read_rows(ROOT + "/output/function_renames.csv")
functions_by_address = {}
for row in function_rows:
    if len(row) >= 2 and row[0].startswith("0x"):
        functions_by_address[row[0].lower()] = row[1]
        all_names.add(row[1])

with open(ROOT + "/docs/table_naming_campaign_2026-11-16.csv", newline="") as handle:
    lines = [line for line in handle if not line.startswith("#")]
for row in csv.DictReader(lines):
    all_names.add(row["name"])

errors = []
proposed = {}
counts = {"function": 0, "global": 0, "note": 0}
verdicts = {}
banned = re.compile(r"(^|_)(temp|pres|qty|corr|cal|ctrl|cfg|calc|val|num|cnt|idx|ptr|buf|msg|mgr|ctx)(_|$)")
for number, line in enumerate(open(RESULT), 1):
    try:
        item = json.loads(line)
    except Exception as error:
        errors.append("line %d invalid json: %s" % (number, error))
        continue
    kind = item["kind"]
    counts[kind] += 1
    if kind == "note":
        continue
    verdicts[item["verdict"]] = verdicts.get(item["verdict"], 0) + 1
    address = item["address"].lower()
    if kind == "global":
        current = globals_by_address.get(address)
        if current != item["old"]:
            errors.append("line %d global %s old %s but csv has %s" % (number, address, item["old"], current))
    else:
        current = functions_by_address.get(address)
        if current != item["old"]:
            errors.append("line %d function %s old %s but csv has %s" % (number, address, item["old"], current))
    new = item.get("new")
    if new:
        if new in proposed:
            errors.append("line %d duplicate new name %s (also line %d)" % (number, new, proposed[new]))
        proposed[new] = number
        if new in all_names:
            errors.append("line %d new name %s already exists in csvs" % (number, new))
        if kind == "global":
            if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
                errors.append("line %d bad snake_case %s" % (number, new))
            if banned.search(new):
                errors.append("line %d banned abbreviation in %s" % (number, new))
            if re.search(r"0x|[a-f0-9]{6,}", new):
                errors.append("line %d hex in %s" % (number, new))
            if new.endswith("_cal"):
                errors.append("line %d _cal in %s" % (number, new))
        else:
            if not re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new):
                errors.append("line %d bad function name %s" % (number, new))
        if len(new) > 70:
            errors.append("line %d long name %s (%d)" % (number, new, len(new)))
    if kind == "function" and not item.get("plate_comment", "").rstrip(".").endswith("was " + item["old"] + ")"):
        if "(was %s)" % item["old"] not in item.get("plate_comment", ""):
            errors.append("line %d plate lacks (was old)" % number)

print("counts", counts, "verdicts", verdicts)
print("errors", len(errors))
for error in errors:
    print(error)
