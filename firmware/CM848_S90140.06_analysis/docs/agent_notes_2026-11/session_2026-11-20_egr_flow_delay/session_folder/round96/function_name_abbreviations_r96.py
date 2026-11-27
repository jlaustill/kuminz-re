"""Round 96: census of abbreviated words in function names (function_renames.csv), both firmwares. Read-only.
usage: function_name_abbreviations_r96.py <repo>"""
import collections
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
WATCH = {"init", "cbd", "calc", "msg", "cfg", "proc", "ctrl", "mgr", "params", "param", "tbl", "util", "rx", "tx",
         "ptr", "buf", "idx", "cnt", "addr", "diag", "req", "resp", "cmd", "err", "temp", "ack", "isr", "hw", "sw",
         "max", "min", "accum", "info", "sel", "seq", "eng", "spd"}
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    names = []
    for line in open(os.path.join(repo, "firmware", fw, "output", "function_renames.csv"), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x"):
            names.append(p[1])
    c = collections.Counter()
    ex = collections.defaultdict(list)
    for n in names:
        for w in set(x.lower() for x in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", n.replace("_", " "))):
            if w in WATCH:
                c[w] += 1
                ex[w].append(n)
    print("==", fw, len(names), "functions")
    for w, k in c.most_common():
        print(f"{k:5d} {w:7s} {', '.join(ex[w][:4])}")
