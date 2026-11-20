import json
import re
import subprocess
import sys

sys.path.insert(0, "/tmp/w13_bin4")
import spec  # noqa: E402

BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin4.json"
OUT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin4.jsonl"
OUTPUT_DIR = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"

records = json.load(open(BIN))


def norm(address):
    return int(address, 16)


renames = {norm(a): v for a, v in spec.RENAMES.items()}
keeps = {norm(a): v for a, v in spec.KEEPS.items()}
problems = []

bin_addresses = [norm(r["address"]) for r in records]
if len(set(bin_addresses)) != len(bin_addresses):
    problems.append("duplicate addresses in bin")
spec_addresses = set(renames) | set(keeps)
if set(renames) & set(keeps):
    problems.append(f"in both: {[hex(a) for a in set(renames) & set(keeps)]}")
if spec_addresses != set(bin_addresses):
    problems.append(f"missing from spec: {[hex(a) for a in set(bin_addresses) - spec_addresses]}")
    problems.append(f"not in bin: {[hex(a) for a in spec_addresses - set(bin_addresses)]}")

lines = []
for record in records:
    a = norm(record["address"])
    old = record["label_in_cpp"]
    if a in renames:
        new, evidence, comment = renames[a]
        lines.append({"kind": "global", "verdict": "confirmed", "address": record["address"], "old": old, "new": new,
                      "evidence": evidence, "comment": comment})
    elif a in keeps:
        lines.append({"kind": "global", "verdict": "keep", "address": record["address"], "old": old, "new": old,
                      "e2m_note": keeps[a]})

# ---- checks -----------------------------------------------------------------------------------------------------
banned = {"temp", "cnt", "ref", "val", "calc", "init", "cfg", "tmptr", "thd", "cmd", "amb", "avg", "frac", "adj", "lmt",
          "lim", "sw", "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl", "inj", "veh", "baro", "alt", "trq", "batt",
          "imt", "ct", "aps", "cot", "mcf", "cmf", "vgt", "pto", "cc", "eb", "jcomm", "el", "lsg", "hsg", "asg", "vsg",
          "sa", "abs", "asr", "esp", "hpcr", "cbr", "emo", "dm", "chp", "veff"}
new_names = [l["new"] for l in lines if l["verdict"] == "confirmed"]
if len(new_names) != len(set(new_names)):
    problems.append("duplicate new names")
cpp = open(OUTPUT_DIR + "cm848_rom.ghidra.cpp", errors="replace").read()
csv_text = "\n".join(open(OUTPUT_DIR + n, errors="replace").read() for n in
                     ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv",
                      "arrays.csv", "constants.csv", "labels.csv", "local_variables.csv", "function_definitions.csv"))
for line in lines:
    if line["verdict"] == "confirmed":
        name = line["new"]
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", name):
            problems.append(f"{name}: not snake_case")
        if re.search(r"(^|_)_|__|_$", name):
            problems.append(f"{name}: bad underscores")
        bad = banned & set(name.split("_"))
        if bad:
            problems.append(f"{name}: banned tokens {bad}")
        if name in cpp or name in csv_text:
            # substring hits count too: names must not exist anywhere yet
            problems.append(f"{name}: already present in cpp/CSVs")
        in_mirror = 0x3fd482 <= norm(line["address"]) <= 0x3feec1
        if in_mirror != name.endswith("_cal"):
            problems.append(f"{name}: _cal rule (mirror={in_mirror})")
        if "(was" in line["comment"].lower() or "(was" in line["evidence"].lower():
            problems.append(f"{name}: contains (was")
        if "\n" in line["comment"] or "\n" in line["evidence"]:
            problems.append(f"{name}: newline")
        if not line["comment"].startswith("e2m "):
            problems.append(f"{name}: comment must lead with the e2m record")
    else:
        if line["new"] != line["old"]:
            problems.append(f"{line['old']}: keep with a new name")
        if not line["e2m_note"].startswith("e2m "):
            problems.append(f"{line['old']}: bad e2m_note")
        in_mirror = 0x3fd482 <= norm(line["address"]) <= 0x3feec1
        if line["old"].endswith("_cal") and not in_mirror:
            problems.append(f"{line['old']}: keep with _cal outside the mirror")
        if in_mirror and not line["old"].endswith("_cal"):
            problems.append(f"{line['old']}: keep in the mirror without _cal")

for line in lines:
    if line["verdict"] == "keep":
        tokens = set(line["old"].split("_"))
        if banned & tokens:
            problems.append(f"keep {line['old']}: banned tokens {banned & tokens}")

with open(OUT, "w") as handle:
    for line in lines:
        handle.write(json.dumps(line, ensure_ascii=False) + "\n")

from collections import Counter  # noqa: E402

print("lines:", len(lines), dict(Counter(l["verdict"] for l in lines)))
print("problems:", problems if problems else "none")
