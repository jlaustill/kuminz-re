"""Build and check result_W14_functions3.jsonl (read-only re-implementation of the rename gate)."""
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from items_a import ITEMS_A  # noqa: E402
from items_b import ITEMS_B  # noqa: E402
from items_enum import ENUM_ROWS  # noqa: E402

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
BIN = f"{STAGE9}/bins/functions3.json"
RESULT = f"{STAGE9}/result_W14_functions3.jsonl"
REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
OUT = f"{REPO}/firmware/CM848_S90140.06_analysis/output"
CPP = f"{OUT}/cm848_rom.ghidra.cpp"

BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


bin_data = json.load(open(BIN))
functions = bin_data["functions"]
held = bin_data["held_enum_rows"]
items = ITEMS_A + ITEMS_B
assert len(items) == len(functions) == 24, (len(items), len(functions))
assert len(ENUM_ROWS) == len(held) == 2

# raw function bodies
cpp_lines = open(CPP, errors="replace").read().split("\n")
starts = [(i, m.group(1)) for i, line in enumerate(cpp_lines) if (m := re.match(r"^// Function: (\S+) @", line))]
body = {}
for k, (i, name) in enumerate(starts):
    end = starts[k + 1][0] if k + 1 < len(starts) else len(cpp_lines)
    body[name] = "\n".join(cpp_lines[i:end])

# names already in use
used = set()
for fn in ("function_renames.csv", "global_variables.csv", "arrays.csv"):
    for line in open(f"{OUT}/{fn}", errors="replace"):
        p = line.split(",")
        if p[0].startswith("0x") and len(p) > 1:
            used.add(p[1])
token = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
anywhere = set()
for path in glob.glob(f"{OUT}/*.csv") + glob.glob(f"{OUT}/*.hpp") + [CPP]:
    anywhere |= set(token.findall(open(path, errors="replace").read()))
also_other_results = set()
for path in glob.glob(f"{STAGE9}/result_W14_*.jsonl"):
    if path == RESULT:
        continue
    for line in open(path):
        line = line.strip()
        if line:
            try:
                r = json.loads(line)
            except ValueError:
                continue
            if r.get("new"):
                also_other_results.add(r["new"])
enum_text = open(f"{OUT}/enums.csv").read()
enum_tokens = set(token.findall(enum_text))

lines, problems = [], []
seen_new = {}
for f, it in zip(functions, items):
    tag = f"{f['address']} {f['current']}"
    new = it["new"]
    plate = " ".join(it["plate"].split())
    note = f.get("user_review_note")
    if note:
        plate = f"{plate} | {note}"
        if not plate.endswith(note) or not plate.endswith(f" | {note}"):
            problems.append(f"{tag}: owner note not the final segment")
    rec = {"kind": "function", "verdict": "confirmed", "address": f["address"], "old": f["current"], "new": new,
           "evidence": " ".join(it["evidence"].split()), "code_quote": it["quote"], "plate_comment": plate}
    lines.append(rec)
    # gate re-implementation
    if f["current"] not in body:
        problems.append(f"{tag}: function body not found")
    elif it["quote"] not in body[f["current"]]:
        problems.append(f"{tag}: code_quote not in the function body: {it['quote']!r}")
    if len(it["quote"]) < 20:
        problems.append(f"{tag}: quote shorter than 20 characters")
    if new in seen_new:
        problems.append(f"{tag}: {new} also used for {seen_new[new]}")
    seen_new[new] = tag
    if new in used:
        problems.append(f"{tag}: {new} already in function_renames / global_variables / arrays")
    if new in anywhere:
        problems.append(f"{tag}: {new} already a token in the CSVs / .hpp / .cpp")
    if new in also_other_results:
        problems.append(f"{tag}: {new} also proposed in another W14 result file")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f"{tag}: banned word(s) {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"{tag}: hex-looking part")
    if not re.fullmatch(r"((cm848|cm550|mpc555|mc68k|hpcr|vp44)_)?[a-z][A-Za-z0-9]*", new):
        problems.append(f"{tag}: function name format")
    if "(was" in plate:
        problems.append(f"{tag}: plate contains (was")
    if re.search(r"\binit\b|\bcalc\b|\bInit[A-Z]|[a-z]Calc[A-Z]", new):
        problems.append(f"{tag}: init / calc in the name")
    if not plate.isascii() or not rec["evidence"].isascii():
        problems.append(f"{tag}: non-ASCII text")
    # the old plate's proved facts: print for a manual look when there is one
    if f["current_plate"] and not note:
        print(f"-- old plate of {tag}:\n   {f['current_plate']}")

for h, row in zip(held, ENUM_ROWS):
    tag = f"{h['address']} {h['current']}"
    if row["address"] != h["address"] or row["old"] != h["current"]:
        problems.append(f"{tag}: enum row does not match the bin")
    rec = {"kind": "enum", "verdict": "confirmed", "address": row["address"], "old": row["old"], "new": row["new"],
           "enum_old": row["enum_old"], "enum_new": row["enum_new"],
           "members": [dict(m) for m in row["members"]], "comment": " ".join(row["comment"].split()),
           "evidence": " ".join(row["evidence"].split())}
    lines.append(rec)
    for m in row["members"]:
        if "," in m["comment"]:
            problems.append(f"{tag}: member {m['old']} comment contains a comma (enums.csv column order)")
        if m["new"]:
            if not re.fullmatch(r"[A-Z][A-Z0-9]*(_[A-Z0-9]+)*", m["new"]):
                problems.append(f"{tag}: member {m['new']} not UPPER_SNAKE")
            if m["new"] in enum_tokens:
                problems.append(f"{tag}: member {m['new']} already in enums.csv")
            if m["new"] in anywhere:
                problems.append(f"{tag}: member {m['new']} already used somewhere")
    if row["enum_new"] in enum_tokens or row["enum_new"] in anywhere:
        problems.append(f"{tag}: enum type {row['enum_new']} already used")
    if row["new"] in used or row["new"] in anywhere:
        problems.append(f"{tag}: row name {row['new']} already used")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", row["new"]):
        problems.append(f"{tag}: global name format")
    bad = sorted(set(words(row["new"])) & BANNED)
    if bad:
        problems.append(f"{tag}: banned word(s) {bad}")

if problems:
    for p in problems:
        print("PROBLEM", p)
    print(f"{len(problems)} problem(s); nothing written")
    sys.exit(1)

with open(RESULT, "w") as fh:
    for rec in lines:
        fh.write(json.dumps(rec) + "\n")
print(f"wrote {len(lines)} lines to {RESULT}")
for rec in lines:
    print(rec["address"], rec["old"], "->", rec["new"], f"(plate {len(rec.get('plate_comment', ''))} chars, "
          f"evidence {len(rec['evidence'])} chars)")
