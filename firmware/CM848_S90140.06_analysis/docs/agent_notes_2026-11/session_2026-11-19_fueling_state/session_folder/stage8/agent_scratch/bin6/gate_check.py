"""Re-implementation of the repo gate's name rules (apply_renames.py) for my result file, read-only."""
import ast
import json
import re
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
OUT = f"{REPO}/firmware/CM848_S90140.06_analysis/output"
RESULT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl"
BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin6.json"

source = open(f"{REPO}/firmware/scripts/rename_waves/apply_renames.py").read()
BANNED = ast.literal_eval(re.search(r"^BANNED = (\{.*?\})", source, re.S | re.M).group(1))
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


gv_lines = open(f"{OUT}/global_variables.csv", errors="replace").read().split("\n")
rows = {}
for i, l in enumerate(gv_lines):
    p = l.split(",", 3)
    if p[0].startswith("0x"):
        rows.setdefault(int(p[0], 16), []).append(p)
used = set()
for name_col in (f"{OUT}/function_renames.csv", f"{OUT}/global_variables.csv", f"{OUT}/arrays.csv"):
    for l in open(name_col, errors="replace"):
        p = l.split(",")
        if p[0].startswith("0x") and len(p) > 1:
            used.add(p[1])
cpp_tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", open(f"{OUT}/cm848_rom.ghidra.cpp", errors="replace").read()))
bin_ = json.load(open(BIN))
problems = []
counts = {}
seen_new = {}
lines = [json.loads(l) for l in open(RESULT) if l.strip()]
assert len(lines) == len(bin_), (len(lines), len(bin_))
for r, b in zip(lines, bin_):
    counts[r["verdict"]] = counts.get(r["verdict"], 0) + 1
    tag = f"{r['address']} {r['old']}"
    if r["address"] != b["address"] or r["old"] != b["label_in_cpp"]:
        problems.append(f"{tag}: address / old does not match the bin")
    a = int(r["address"], 16)
    cur = rows.get(a, [])
    if len(cur) != 1 or cur[0][1] != r["old"]:
        problems.append(f"{tag}: CSV rows at the address: {[c[1] for c in cur]}")
    if r["verdict"] == "confirmed":
        new = r["new"]
        if new in seen_new:
            problems.append(f"{tag}: new name also used at {seen_new[new]}")
        seen_new[new] = tag
        if new in used:
            problems.append(f"{tag}: new name {new} already in a CSV")
        if new in cpp_tokens:
            problems.append(f"{tag}: new name {new} already in the cpp")
        bad = sorted(set(words(new)) & BANNED)
        if bad:
            problems.append(f"{tag}: banned word(s) {bad} in {new}")
        if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
            problems.append(f"{tag}: hex-looking part in {new}")
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(f"{tag}: name format {new}")
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith("_cal") != in_eeprom:
            problems.append(f"{tag}: _cal rule broken for {new} (in EEPROM mirror: {in_eeprom})")
        if "protection" in words(new) and new.split("_")[-1] == "protection":
            problems.append(f"{tag}: bare protection")
        if new == r["old"]:
            problems.append(f"{tag}: new equals old")
        for key in ("evidence", "comment"):
            if not r.get(key) or "\n" in r[key] or "(was" in r[key]:
                problems.append(f"{tag}: bad {key}")
        if len(r["comment"]) > 900:
            problems.append(f"{tag}: long comment {len(r['comment'])}")
    elif r["verdict"] == "keep":
        if r["new"] != r["old"] or not r.get("e2m_note"):
            problems.append(f"{tag}: keep row malformed")
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if r["old"].endswith("_cal") != in_eeprom:
            problems.append(f"{tag}: KEEP name breaks the _cal rule (in EEPROM mirror: {in_eeprom})")
        bad = sorted(set(words(r["old"])) & BANNED)
        if bad:
            problems.append(f"{tag}: KEEP name has banned word(s) {bad}")
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", r["old"]):
            problems.append(f"{tag}: KEEP name format")
    else:
        if not r.get("evidence"):
            problems.append(f"{tag}: no evidence")
print("verdicts:", counts)
print("comment lengths: max", max(len(r.get("comment", "")) for r in lines),
      "evidence max", max(len(r.get("evidence", "")) for r in lines))
for p in problems:
    print("PROBLEM", p)
print("done,", len(problems), "problems")
