"""Round 96: census of abbreviated words in parameter names (function_definitions.csv), local names
(local_variables.csv) and struct field names (structure_definitions.csv), both firmwares. Read-only.
A word is a '_'-separated or camelCase part of the name. usage: abbreviation_census_r96.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
ABBREVIATIONS = {"msg", "rx", "tx", "func", "fn", "idx", "ptr", "cnt", "val", "buf", "len", "addr", "cfg", "config",
                 "init", "param", "params", "calc", "tmp", "temp", "num", "src", "dst", "dest", "req", "resp", "ctrl",
                 "stat", "sts", "cmd", "err", "flg", "ref", "pos", "sel", "seq", "prev", "cur", "curr", "max", "min",
                 "avg", "hdr", "sub", "lim", "thr", "thresh", "spd", "pwr", "eng", "veh", "acc", "accel", "decel",
                 "diag", "info", "ack", "nack", "mult", "div", "deg", "pct", "ms", "us", "sec", "hi", "lo", "lsb",
                 "msb", "cal", "def", "ext", "int", "intr", "isr", "sw", "hw", "util", "mgr", "ctx", "obj", "arr",
                 "tbl", "lut", "dim", "dims", "coef", "coeff", "freq", "inj", "cyl", "trq", "tq", "fuel", "rpm"}
SKIP = {"fuel", "rpm", "max", "min", "cal", "temp", "info"}       # spelled words or allowed / existing conventions


def words(name):
    out = []
    for part in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", part)]
    return out


for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    out = os.path.join(repo, "firmware", fw, "output")
    counts = collections.Counter()
    examples = collections.defaultdict(set)
    for f, col in (("function_definitions.csv", 3), ("local_variables.csv", 3), ("structure_definitions.csv", 2)):
        for r in csv.reader(l for l in open(os.path.join(out, f), newline="") if not l.startswith("#")):
            if len(r) > col and r[col] and r[col] not in ("name", "new_name", "field_name"):
                for w in set(words(r[col])):
                    if w in ABBREVIATIONS and w not in SKIP:
                        counts[(f.split("_")[0], w)] += 1
                        examples[(f.split("_")[0], w)].add(r[col])
    print("==", fw)
    for (f, w), n in counts.most_common(40):
        print(f"{n:5d} {f:10s} {w:8s} {', '.join(sorted(examples[(f, w)])[:5])}")
