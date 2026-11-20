"""Validates the W14 functions2 result file against the bin, the gate rules and the .cpp."""
import glob
import json
import os
import re
import sys

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
BIN = os.path.join(STAGE9, "bins", "functions2.json")
RESULT = os.path.join(STAGE9, "result_W14_functions2.jsonl")
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
REPO_FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
problems = []


def words(name):
    out = []
    for part in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", part)]
    return out


bin_items = json.load(open(BIN))["functions"]
records = [json.loads(line) for line in open(RESULT) if line.strip()]
if len(records) != len(bin_items):
    problems.append(f"{len(records)} lines for {len(bin_items)} bin items")

# function bodies: physical lines per function, from the .cpp markers
cpp_lines = open(os.path.join(OUT, "cm848_rom.ghidra.cpp"), errors="replace").read().split("\n")
starts = [(i, m.group(1)) for i, line in enumerate(cpp_lines) if (m := re.match(r"^// Function: (\S+) @", line))]
ranges = {name: (i, starts[k + 1][0] if k + 1 < len(starts) else len(cpp_lines)) for k, (i, name) in enumerate(starts)}

# every text a new name must be absent from
corpus = {}
for path in glob.glob(os.path.join(OUT, "*.csv")) + glob.glob(os.path.join(OUT, "*.hpp")):
    corpus[path] = open(path, errors="replace").read()
corpus["cpp"] = "\n".join(cpp_lines)
for path in glob.glob(os.path.join(STAGE9, "result_W14_*.jsonl")):
    if os.path.abspath(path) != os.path.abspath(RESULT):
        corpus[path] = open(path, errors="replace").read()
for path in glob.glob(os.path.join(REPO_FW, "CM550_J90350.00_analysis", "output", "*.csv")):
    corpus[path] = open(path, errors="replace").read()

seen = {}
KEYS = {"kind", "verdict", "address", "old", "new", "evidence", "code_quote", "plate_comment"}
for entry, record in zip(bin_items, records):
    tag = f"{entry['address']} {entry['current']}"
    if set(record) != KEYS:
        problems.append(f"{tag}: keys {sorted(set(record) ^ KEYS)}")
    if record.get("address") != entry["address"] or record.get("old") != entry["current"]:
        problems.append(f"{tag}: address / old differ from the bin")
    if record.get("kind") != "function" or record.get("verdict") != "confirmed":
        problems.append(f"{tag}: kind / verdict")
    new = record.get("new", "")
    if new in seen:
        problems.append(f"{tag}: new name {new} also used by {seen[new]}")
    seen[new] = tag
    if new == record.get("old"):
        problems.append(f"{tag}: new equals old")
    if not re.fullmatch(r"((cm848|cm550|mpc555|mc68k|hpcr|vp44)_)?[a-z][A-Za-z0-9]*", new):
        problems.append(f"{tag}: name format {new}")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f"{tag}: banned words {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"{tag}: hex-looking part")
    if re.search(r"\binit\b|Init[A-Z]|[a-z]Init\b|\bcalc\b|Calc[A-Z]", new):
        problems.append(f"{tag}: init / calc in the name")
    for path, text in corpus.items():
        if re.search(rf"(?<![A-Za-z0-9_]){re.escape(new)}(?![A-Za-z0-9_])", text):
            problems.append(f"{tag}: new name {new} already in {os.path.basename(path)}")
    # code quote inside one physical line of the function
    quote = record.get("code_quote", "")
    name = entry["current"]
    if name not in ranges:
        problems.append(f"{tag}: function not found in the .cpp")
    else:
        lo, hi = ranges[name]
        if not any(quote in line for line in cpp_lines[lo:hi]):
            problems.append(f"{tag}: code_quote is not inside one line of the function: {quote!r}")
        if len(quote.strip()) < 20:
            problems.append(f"{tag}: code_quote shorter than 20 characters")
    # text hygiene
    for field in ("evidence", "plate_comment"):
        text = record.get(field, "")
        if not text.strip():
            problems.append(f"{tag}: empty {field}")
        if '"' in text or "\n" in text or "*/" in text or "/*" in text:
            problems.append(f"{tag}: {field} has a double quote, newline or comment marker")
        if not text.isascii():
            problems.append(f"{tag}: {field} is not ASCII")
        if "(was" in text.lower() or "|" in text:
            problems.append(f"{tag}: {field} has '(was' or a pipe")
        if re.search(r"0x[fF][0-9a-fA-F]{3}\b", text) and field == "plate_comment":
            pass
print(f"{len(records)} records, {len(bin_items)} bin items")
for p in problems:
    print("PROBLEM", p)
print("OK" if not problems else f"{len(problems)} problems")
