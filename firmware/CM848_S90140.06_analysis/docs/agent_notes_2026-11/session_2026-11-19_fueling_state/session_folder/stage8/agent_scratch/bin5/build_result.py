"""Builds the W13 bin5 result file from the decisions below and validates it against the bin.
usage: python3 build_result.py            (writes the jsonl, prints the validation report)"""
import json
import re
import csv
import sys

BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin5.json"
OUT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin5.jsonl"
OUTPUT_DIR = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/"
              "CM848_S90140.06_analysis/output/")

R = {}


def rename(address, old, new, evidence, comment):
    R[address] = {"kind": "global", "verdict": "confirmed", "address": address, "old": old, "new": new,
                  "evidence": evidence, "comment": comment}


def keep(address, old, e2m_note):
    R[address] = {"kind": "global", "verdict": "keep", "address": address, "old": old, "new": old,
                  "e2m_note": e2m_note}


def drift(address, old, evidence):
    R[address] = {"kind": "global", "verdict": "drift", "address": address, "old": old, "evidence": evidence}


exec(open("/tmp/w13b5/entries_a.py").read())
exec(open("/tmp/w13b5/entries_b.py").read())
exec(open("/tmp/w13b5/entries_c.py").read())
exec(open("/tmp/w13b5/entries_d.py").read())

bin_records = json.load(open(BIN))
order = [r["address"] for r in bin_records]
problems = []
if set(order) != set(R):
    problems.append(f"address mismatch: missing {sorted(set(order) - set(R))} extra {sorted(set(R) - set(order))}")
lines = []
for r in bin_records:
    entry = R.get(r["address"])
    if entry is None:
        continue
    if entry["old"] != r["label_in_cpp"]:
        problems.append(f"{r['address']}: old {entry['old']} != bin {r['label_in_cpp']}")
    lines.append(json.dumps(entry, ensure_ascii=True))
open(OUT, "w").write("\n".join(lines) + "\n")

# rule checks on the new names
names = {}
mirror = lambda a: 0x3fd482 <= int(a, 16) <= 0x3feec1
text_cache = {}
for f in ("global_variables.csv", "function_renames.csv", "enums.csv", "structure_definitions.csv", "constants.csv",
          "arrays.csv", "cm848_rom.ghidra.cpp", "firmware_globals.hpp", "firmware_functions.hpp", "firmware_types.hpp"):
    text_cache[f] = open(OUTPUT_DIR + f, errors="replace").read()
BAD_WORDS = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg", "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq", "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req", "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg",
             "tmptr", "thd", "amb", "avg", "frac", "filt", "ovr", "vlv", "cyl", "veh", "baro", "alt", "batt", "ct", "aps", "eol", "eps", "tcc", "od", "evr", "asg", "lsg", "hsg", "vsg", "cssc", "mil", "mprop", "dtc2", "cal2"}
counts = {}
for address, e in R.items():
    counts[e["verdict"]] = counts.get(e["verdict"], 0) + 1
    if e["verdict"] != "confirmed":
        if e["verdict"] == "keep" and e["new"] != e["old"]:
            problems.append(f"{address}: keep with a different name")
        continue
    new = e["new"]
    if new in names:
        problems.append(f"{address}: duplicate new name {new} (also {names[new]})")
    names[new] = address
    if new.endswith("_cal") != mirror(address):
        problems.append(f"{address}: _cal rule broken for {new}")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problems.append(f"{address}: name {new} not snake_case")
    for w in new.split("_"):
        if w in BAD_WORDS:
            problems.append(f"{address}: abbreviation-like word {w} in {new}")
    pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(new) + r"(?![A-Za-z0-9_])")
    for f, t in text_cache.items():
        if pat.search(t):
            problems.append(f"{address}: new name {new} already exists in {f}")
    if "\n" in e["comment"] or "\n" in e["evidence"]:
        problems.append(f"{address}: newline in text")
    if "(was " in e["comment"]:
        problems.append(f"{address}: comment contains (was")
    if "|" in e["comment"]:
        problems.append(f"{address}: comment contains a pipe")
print("counts", counts, "lines", len(lines))
print("PROBLEMS:" if problems else "no problems")
for p in problems:
    print("  ", p)

# stale references: old names of renamed rows must not appear in any comment
olds = {e["old"]: a for a, e in R.items() if e["verdict"] == "confirmed"}
for a, e in R.items():
    texts = []
    if e["verdict"] == "confirmed":
        texts.append(("comment", e["comment"]))
    if e["verdict"] == "keep":
        texts.append(("e2m_note", e["e2m_note"]))
    for kind, t in texts:
        for old, oa in olds.items():
            if re.search(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])", t):
                print(f"STALE REF in {a} {kind}: mentions old name {old} of {oa}")
# names a comment mentions that are new names of other rows are fine; list the new-name references for review
import glob
others = [f for f in glob.glob("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin*.jsonl") if "bin5" not in f]
other_new = {}
for f in others:
    for line in open(f):
        line = line.strip()
        if not line:
            continue
        j = json.loads(line)
        if j.get("new"):
            other_new.setdefault(j["new"], []).append((f.split("/")[-1], j["address"]))
for n, a in names.items():
    if n in other_new:
        print("CROSS-BIN COLLISION:", n, a, other_new[n])
print("other bins present:", [o.split("/")[-1] for o in others])
