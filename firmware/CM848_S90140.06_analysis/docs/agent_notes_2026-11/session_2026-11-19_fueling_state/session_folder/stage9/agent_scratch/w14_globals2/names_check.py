"""names_check.py: reproduce the gate's name rules plus a wider collision grep for the candidate names in spec_names.txt
(one 'address new_name' per line).  Prints PROBLEM lines; silent apart from the summary when clean."""
import glob
import os
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


rows = []
for line in open(sys.argv[1] if len(sys.argv) > 1 else "/tmp/w14_globals2/spec_names.txt"):
    line = line.strip()
    if line and not line.startswith("#"):
        a, n = line.split()
        rows.append((int(a, 16), n))

texts = {}
for path in glob.glob(f"{OUT}/*.csv") + glob.glob(f"{OUT}/*.cpp") + glob.glob(f"{OUT}/*.hpp") + glob.glob(f"{OUT}/*.md"):
    texts[os.path.basename(path)] = open(path, errors="replace").read()
seen = {}
problems = 0
for a, n in rows:
    tag = f"0x{a:08x} {n}"
    if n in seen:
        print("PROBLEM", tag, "also proposed for", seen[n])
        problems += 1
    seen[n] = tag
    bad = sorted(set(words(n)) & BANNED)
    if bad:
        print("PROBLEM", tag, "banned", bad)
        problems += 1
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", n):
        print("PROBLEM", tag, "format")
        problems += 1
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", n):
        print("PROBLEM", tag, "hex-looking part")
        problems += 1
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if n.endswith("_cal") and not in_eeprom:
        print("PROBLEM", tag, "_cal outside the EEPROM mirror")
        problems += 1
    if (not n.endswith("_cal")) and in_eeprom:
        print("NOTE   ", tag, "EEPROM mirror without _cal")
    if n.split("_")[-1] == "protection":
        print("PROBLEM", tag, "bare protection")
        problems += 1
    pat = re.compile(rf"(?<![A-Za-z0-9_]){re.escape(n)}(?![A-Za-z0-9_])")
    for fname, text in texts.items():
        if pat.search(text):
            print("PROBLEM", tag, "already present in", fname)
            problems += 1
print(f"{len(rows)} names checked, {problems} problems")
