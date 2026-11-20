"""Build result_W12_bin2.jsonl from the decisions below, then self-check it against the brief and the gate rules.

usage: build_results.py            (writes the result file and prints the checks)
"""
import csv
import json
import re
import sys

BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/bin2.json"
OUTFILE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin2.jsonl"
OUT = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/"
       "output/")

sys.path.insert(0, "/tmp/w12_bin2")
from records import RECORDS  # noqa: E402

BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
UNLISTED = {"rsg", "epf", "oog", "gr", "az", "tps", "ofc", "at", "iah", "ul", "cc", "lsg", "hsg", "asg", "vsg", "emo",
            "emm", "ct", "aps", "pto", "vgt", "cot", "mcf", "cmf", "jcomm", "cal", "dd", "ema", "avg", "min", "max"}
EEPROM = (0x3fd482, 0x3feec1)
I16 = {33, 34, 39, 43, 44, 63, 64, 66}
SIZE_TYPE = {"1": "byte", "2": "word", "4": "dword"}


def words(name):
    out = []
    for part in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", part)]
    return out


def eng_text(raw, scale, spec):
    if spec is None:
        return ""
    digits, unit = spec
    value = float(raw) * float(scale)
    return f"{value:.{digits}f}{(' ' + unit) if unit else ''}"


def main():
    items = json.load(open(BIN))
    assert len(items) == len(RECORDS) == 67, (len(items), len(RECORDS))
    problems = []
    lines = []
    for index, (item, rec) in enumerate(zip(items, RECORDS)):
        if item["address"] != rec["address"]:
            problems.append(f"#{index}: address {rec['address']} != bin {item['address']}")
            continue
        raw = item["dump_raw"]
        eng = eng_text(raw, item["scale"], rec.get("eng"))
        fields = {"raw": raw, "eng": eng}
        evidence = rec["evidence"].format(**fields)
        comment = rec["comment"].format(**fields)
        row = {"kind": "new_global", "verdict": rec["verdict"], "address": item["address"], "new": rec["new"],
               "type": rec["type"], "evidence": evidence, "comment": comment}
        lines.append(row)
        # checks
        if rec["verdict"] not in ("confirmed", "uncertain", "rejected"):
            problems.append(f"#{index}: verdict")
        if "\n" in evidence or "\n" in comment:
            problems.append(f"#{index}: newline")
        want = SIZE_TYPE[item["size_bytes"]]
        if index in I16:
            want = "i16"
        if rec["type"] != want:
            problems.append(f"#{index}: type {rec['type']} != {want}")
        if len(comment) > 420:
            problems.append(f"#{index}: comment {len(comment)} chars (clip is 400)")
        if rec["verdict"] == "rejected":
            if rec["new"] != "":
                problems.append(f"#{index}: rejected row must have an empty new")
            continue
        new = rec["new"]
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(f"#{index}: name format {new}")
        bad = sorted(set(words(new)) & BANNED)
        if bad:
            problems.append(f"#{index}: banned {bad}")
        stray = sorted((set(words(new)) & UNLISTED) - ({"cal"} if new.endswith("_cal") else set()))
        if stray:
            problems.append(f"#{index}: unlisted abbreviation {stray} in {new}")
        if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
            problems.append(f"#{index}: hex-looking part in {new}")
        if "protection" in words(new) and new.split("_")[-1] == "protection":
            problems.append(f"#{index}: bare protection")
        address = int(item["address"], 16)
        in_eeprom = EEPROM[0] <= address <= EEPROM[1]
        if new.endswith("_cal") != in_eeprom:
            problems.append(f"#{index}: _cal rule ({new}, eeprom={in_eeprom})")
    # uniqueness and collisions
    names = [r["new"] for r in lines if r["new"]]
    if len(names) != len(set(names)):
        problems.append("duplicate new names inside the bin: " + ", ".join(sorted({n for n in names if names.count(n) > 1})))
    used = set()
    for fname, col in (("global_variables.csv", 1), ("function_renames.csv", 1), ("arrays.csv", 1), ("constants.csv", 1),
                       ("local_variables.csv", 2)):
        try:
            for r in csv.reader(open(OUT + fname, errors="replace")):
                if len(r) > col:
                    used.add(r[col])
        except FileNotFoundError:
            problems.append(f"missing {fname}")
    cpp = open(OUT + "cm848_rom.ghidra.cpp", errors="replace").read()
    for n in names:
        if n in used:
            problems.append(f"name already in a CSV: {n}")
        if re.search(r"\b" + re.escape(n) + r"\b", cpp):
            problems.append(f"name already in the .cpp: {n}")
    addresses = {r["address"] for r in lines}
    if addresses != {i["address"] for i in items} or len(lines) != 67:
        problems.append("address set differs from the bin")
    if problems:
        print("PROBLEMS:")
        for p in problems:
            print("  ", p)
        return 1
    with open(OUTFILE, "w") as f:
        for row in lines:
            f.write(json.dumps(row) + "\n")
    counts = {}
    for row in lines:
        counts[row["verdict"]] = counts.get(row["verdict"], 0) + 1
    print("wrote", len(lines), "lines to", OUTFILE, counts)
    return 0


if __name__ == "__main__":
    sys.exit(main())
