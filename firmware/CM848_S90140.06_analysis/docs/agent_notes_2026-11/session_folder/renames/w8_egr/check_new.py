"""Gate checks for the new_global rows (the real gate only looks at function / global rows), plus a summary of the file."""
import json
import re
import sys
from collections import Counter

RES = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_egr_charge.jsonl"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
used = set()
for fname, col in (("function_renames.csv", 1), ("global_variables.csv", 1), ("arrays.csv", 1)):
    for line in open(OUT + fname):
        p = line.split(",")
        if p[0].startswith("0x") and len(p) > col:
            used.add(p[col])


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


rows = [json.loads(l) for l in open(RES) if l.strip()]
news = [r for r in rows if r["kind"] == "new_global"]
seen = Counter()
bad = 0
for r in rows:
    if r["kind"] in ("function", "global", "new_global") and r.get("new"):
        seen[r["new"]] += 1
for r in news:
    n, a = r["new"], int(r["address"], 16)
    probs = []
    if n in used:
        probs.append("already in a CSV")
    if seen[n] > 1:
        probs.append("proposed twice")
    if set(words(n)) & BANNED:
        probs.append("banned %s" % sorted(set(words(n)) & BANNED))
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", n):
        probs.append("hex-looking")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
        probs.append("format")
    if n.endswith("_cal") and not (0x3fd482 <= a <= 0x3feec1):
        probs.append("_cal outside EEPROM")
    if r["type"] not in ("byte", "word", "dword", "i8", "i16", "i32"):
        probs.append("type")
    if probs:
        bad += 1
        print("PROBLEM new_global", r["address"], n, probs)
print("new_global rows checked:", len(news), "problems:", bad)
dups = [n for n, c in seen.items() if c > 1]
print("duplicate new names:", dups)
print("kinds:", Counter((r["kind"], r.get("verdict")) for r in rows))
sys.exit(0)
