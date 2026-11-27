"""Round 97 (read-only): global rows whose name has an abbreviated word, by word, both firmwares.
usage: global_abbreviation_census_r97.py <repo> [word ...]"""
import collections
import os
import sys

repo = os.path.abspath(sys.argv[1])
WATCH = set(sys.argv[2:]) or {"lsg", "asg", "anc", "hsg", "vsg", "rsg", "pto", "adj", "ref", "integ", "max", "min",
                              "ptr", "msg", "rx", "tx", "cfg", "config", "ctrl", "cnt", "idx", "buf", "init", "diag",
                              "calc", "temp", "tmp", "prot", "eps", "epf", "afc", "tsc", "cyl", "inj", "trq", "spd",
                              "accel", "decel", "prev", "cur", "curr", "val", "num", "param", "params", "addr", "req",
                              "resp", "cmd", "stat", "err", "sel", "seq", "hi", "lo", "avg", "pct", "deg", "sw", "hw"}
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    c = collections.Counter()
    ex = collections.defaultdict(list)
    for line in open(os.path.join(repo, "firmware", fw, "output", "global_variables.csv"), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x") and p[1] and "." not in p[1] and "[" not in p[1]:
            for w in set(p[1].lower().split("_")):
                if w in WATCH:
                    c[w] += 1
                    ex[w].append(p[1])
    print("==", fw, sum(c.values()), "word hits")
    for w, n in c.most_common():
        print(f"{n:5d} {w:6s} {', '.join(ex[w][:3])}")
