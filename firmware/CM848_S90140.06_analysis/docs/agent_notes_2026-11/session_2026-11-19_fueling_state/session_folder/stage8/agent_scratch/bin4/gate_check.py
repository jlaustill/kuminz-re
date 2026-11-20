"""Read-only re-implementation of the repo gate's checks (firmware/scripts/rename_waves/apply_renames.py) on my result
file. Written by hand because running the repo script was blocked."""
import json
import re

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
RESULT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin4.jsonl"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for part in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", part)]
    return out


gv_lines = open(FW + "global_variables.csv").read().split("\n")
rows = {}
for i, line in enumerate(gv_lines):
    p = line.split(",", 3)
    if p[0].startswith("0x"):
        rows.setdefault(int(p[0], 16), []).append(i)
used = set()
for name in ("function_renames.csv", "global_variables.csv", "arrays.csv"):
    for line in open(FW + name):
        p = line.split(",")
        if p[0].startswith("0x") and len(p) > 1:
            used.add(p[1])
registers = set()
for line in open(FW + "mpc555_registers.csv"):
    p = line.split(",", 1)
    if p[0].startswith("0x"):
        registers.add(int(p[0], 16))

problems = []
seen = {}
for line in open(RESULT):
    r = json.loads(line)
    a = int(r["address"], 16)
    # every line: the old name must be the one in the row at that address
    rr = rows.get(a, [])
    if len(rr) != 1 or gv_lines[rr[0]].split(",", 3)[1] != r["old"]:
        problems.append(f"{r['address']} {r['old']}: row mismatch ({len(rr)} rows, "
                        f"{[gv_lines[i].split(',', 3)[1] for i in rr]})")
    if r["verdict"] != "confirmed":
        continue
    new = r["new"]
    if new in seen:
        problems.append(f"{new}: duplicate")
    seen[new] = a
    if new in used:
        problems.append(f"{new}: already in a CSV")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f"{new}: banned {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"{new}: hex-looking part")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problems.append(f"{new}: name format")
    if a in registers:
        problems.append(f"{new}: register address")
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if new.endswith("_cal") and not in_eeprom:
        problems.append(f"{new}: _cal outside the mirror")
    if r["old"].endswith("_cal") and in_eeprom and not new.endswith("_cal"):
        problems.append(f"{new}: lost its _cal")
    if "protection" in words(new) and new.split("_")[-1] == "protection":
        problems.append(f"{new}: bare protection")
print("gate re-check:", "no PROBLEM lines" if not problems else "")
for p in problems:
    print("PROBLEM", p)
